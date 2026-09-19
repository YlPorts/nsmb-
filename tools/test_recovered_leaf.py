"""Exercise newly recovered ARM leaf routines against independent scalar models.
Only synthetic state/table data is used. No game data is embedded in this test.
"""
import argparse
import io
import json
from pathlib import Path
import random
import struct
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--object-root', type=Path, default=Path('build/ci-objects'))
parser.add_argument('--report', type=Path, default=Path('build/ci-objects/leaf-semantics-report.json'))
args = parser.parse_args()

def info(unit, symbol, side='base'):
    path = args.object_root / (unit + '.o')
    elf = ELFFile(io.BytesIO(path.read_bytes()))
    symbols = elf.get_section_by_name('.symtab').get_symbol_by_name(symbol)
    if not symbols or len(symbols) != 1:
        raise RuntimeError('Missing or ambiguous symbol: ' + symbol)
    symbol = symbols[0]
    section = elf.get_section(symbol['st_shndx'])
    start = symbol['st_value'] - section['sh_addr']
    size = symbol['st_size']
    code = section.data()[start:start + size]
    relocs = []
    for relsec in elf.iter_sections():
        if not isinstance(relsec, RelocationSection) or relsec['sh_info'] != symbol['st_shndx']:
            continue
        symtab = elf.get_section(relsec['sh_link'])
        for rel in relsec.iter_relocations():
            offset = rel['r_offset'] - symbol['st_value']
            if 0 <= offset < size:
                kind = rel['r_info_type']
                target = symtab.get_symbol(rel['r_info_sym']).name
                addend = rel.entry.get('r_addend')
                if addend is None:
                    addend = struct.unpack_from('<i', code, offset)[0]
                relocs.append((offset, kind, target, addend))
    return {'data': code, 'relocs': relocs}
from unicorn import Uc,UC_ARCH_ARM,UC_MODE_ARM
from unicorn.arm_const import *
CODE=0x10000;STOP=0x12000;OBJECT=0x40000;TABLE=0x50000;STACK=0x80000
rng=random.Random(20260919)
def s16(v):return (v+0x8000)%0x10000-0x8000
def s32(v):return (v+0x80000000)%0x100000000-0x80000000
def put32(b,off,v):struct.pack_into('<I',b,off,v&0xffffffff)
def get32(b,off):return struct.unpack_from('<i',b,off)[0]
def run_model(unit,fn,kind,n=1000):
 a=info(unit,fn,'base');code=bytearray(a['data'])
 for off,typ,name,add in a['relocs']:
  if name=='_FixedSinCosTbl' and typ==2:struct.pack_into('<I',code,off,TABLE+add)
  else:raise AssertionError((fn,'unexpected relocation',typ,name))
 u=Uc(UC_ARCH_ARM,UC_MODE_ARM)
 for addr,size in [(CODE,0x3000),(OBJECT,0x2000),(TABLE,0x4000),(STACK,0x2000)]:u.mem_map(addr,size)
 u.mem_write(CODE,bytes(code))
 table=[rng.randrange(-4096,4097) for _ in range(8192)]
 u.mem_write(TABLE,struct.pack('<8192h',*table))
 for iteration in range(n):
  state=bytearray(rng.randbytes(0x800));expect=bytearray(state);args=[OBJECT,0,0,0]
  expected_return=None
  if kind=='rotate':
   direction=rng.randrange(2);angle=rng.randrange(-32768,32768)
   lo=rng.randrange(1,32768);hi=rng.randrange(-32768,0)
   steps=[rng.randrange(-2048,2049),rng.randrange(-2048,2049)]
   state[0x2bd]=direction;struct.pack_into('<h',state,0xa2,angle);expect=bytearray(state)
   u.mem_write(OBJECT+0x1000,struct.pack('<4h',lo,hi,*steps));args=[OBJECT,OBJECT+0x1000,OBJECT+0x1004,0]
   angle=s16(angle+steps[direction]);done=angle>=lo or angle<=hi
   if done:angle=[lo,hi][direction]
   struct.pack_into('<h',expect,0xa2,angle);expected_return=int(done)
  elif kind=='squish':
   flags=rng.randrange(256);raw=rng.randrange(1<<20)
   state[0x2bf]=flags;put32(state,0x24c,raw);expect=bytearray(state)
   expected_return=int(any(flags&flag and raw&mask for flag,mask in [(1,0x15),(2,0x2a),(8,0x1f40),(4,0xe000)]))
  elif kind=='bounce':
   vx=rng.randrange(-0x50000,0x50001);vy=rng.randrange(-0x50000,0x50001)
   a=rng.randrange(0,0x10000);b=rng.choice([0,0xff,0x100,0xfff,0x1000,0x1001,rng.randrange(0x1800)]);c=rng.randrange(0x2000)
   raw=rng.choice([0,0x1f40,0x40,0x1000,0x2000])
   put32(state,0xd0,vx);put32(state,0xd4,vy);put32(state,0x24c,raw);expect=bytearray(state);args=[OBJECT,a,b,c]
   if raw&0x1f40:
    if b<0x1000:
     vx=s32((vx*b+0x800)>>12)
     if abs(vx)<0x100:vx=0
    if vy<0:
     vy=s32((-vy*c+0x800)>>12)
     if vy<a:vy=0
   put32(expect,0xd0,vx);put32(expect,0xd4,vy)
  elif kind=='direction3d':
   angle=rng.randrange(65536);speed=rng.randrange(-0x50000,0x50001);vy=rng.randrange(-0x50000,0x50001);accel=rng.randrange(-0x2000,0x2001);minimum=rng.randrange(-0x50000,0x50001)
   struct.pack_into('<H',state,0xae,angle)
   for off,value in [(0xb4,speed),(0xbc,accel),(0xc0,minimum),(0xd4,vy)]:put32(state,off,value)
   expect=bytearray(state);index=(angle>>4)*2
   for off,value in [(0xd0,s32((speed*table[index]+0x800)>>12)),(0xd4,max(s32(vy+accel),minimum)),(0xd8,s32((speed*table[index+1]+0x800)>>12))]:put32(expect,off,value)
  else:raise AssertionError(kind)
  u.mem_write(OBJECT,bytes(state))
  for reg,val in zip([UC_ARM_REG_R0,UC_ARM_REG_R1,UC_ARM_REG_R2,UC_ARM_REG_R3],args):u.reg_write(reg,val&0xffffffff)
  for reg in [UC_ARM_REG_R4,UC_ARM_REG_R5,UC_ARM_REG_R6,UC_ARM_REG_R7,UC_ARM_REG_R8,UC_ARM_REG_R9,UC_ARM_REG_R10,UC_ARM_REG_R11,UC_ARM_REG_R12]:u.reg_write(reg,0xa5a5a5a5)
  u.reg_write(UC_ARM_REG_SP,STACK+0x1000);u.reg_write(UC_ARM_REG_LR,STOP)
  u.emu_start(CODE,STOP,count=500)
  assert u.reg_read(UC_ARM_REG_PC)==STOP,(kind,iteration,'did not return')
  actual=bytes(u.mem_read(OBJECT,len(expect)))
  assert actual==expect,(kind,iteration,'state differs',[(hex(k),a,b) for k,(a,b) in enumerate(zip(actual,expect)) if a!=b][:12])
  if expected_return is not None:assert u.reg_read(UC_ARM_REG_R0)==expected_return,(kind,iteration,'return differs')
 return {'unit':unit,'symbol':fn,'cases':n,'passed':n,'model':kind}
results=[]
for u,fn,kind in [('src/Bases/StageEntity','_ZN11StageEntity14rotateToTargetEPsS0_','rotate'),('src/Bases/StageEntity','_ZN11StageEntity13checkSquishedEv','squish'),('src/Bases/StageEntity','_ZN11StageEntity12updateBounceElll','bounce'),('src/Bases/Actor','_ZN5Actor24setDirectionalVelocity3DEv','direction3d')]:
 results.append(run_model(u,fn,kind));print(results[-1],flush=True)
args.report.parent.mkdir(parents=True, exist_ok=True)
args.report.write_text(json.dumps({'test_scope':'Compiled ARM functions versus independent scalar models with synthetic data, not a full-game test.','functions':results,'passed_cases':sum(r['passed'] for r in results)},indent=2)+'\n')
