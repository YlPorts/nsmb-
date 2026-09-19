#!/usr/bin/env python3
"""Test reconstructed Platform list routines using compiled ARM and synthetic state.

These tests do not emulate or include the game. Both pointer topology and bytes
outside the fields touched by each operation are checked after every call.
"""
from __future__ import annotations
import argparse
import json
from pathlib import Path
import random
import struct
from unicorn import Uc, UC_ARCH_ARM, UC_MODE_ARM
from unicorn.arm_const import UC_ARM_REG_R0, UC_ARM_REG_SP, UC_ARM_REG_LR, UC_ARM_REG_PC
from verify_matching_batch import function

CODE, STOP, OBJECTS, GLOBALS, STACK = 0x10000, 0x16000, 0x40000, 0x50000, 0x80000
NODE_COUNT, NODE_STRIDE, NODE_SIZE = 12, 0x100, 0x58


def set32(buf: bytearray, offset: int, value: int) -> None:
    struct.pack_into('<I', buf, offset, value & 0xffffffff)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--object-root', type=Path, default=Path('build/ci-objects'))
    parser.add_argument('--report', type=Path, default=Path('build/ci-objects/platform-semantics-report.json'))
    args = parser.parse_args()
    names = {'reset':'_ZN8Platform5resetEv', 'link':'_ZN8Platform4linkEv', 'unlink':'_ZN8Platform6unlinkEv'}
    addresses = {names[k]: CODE + i*0x1000 for i,k in enumerate(names)}
    addresses.update({'_ZN8Platform8listHeadE':GLOBALS, '_ZN8Platform8listTailE':GLOBALS+4})
    cpu = Uc(UC_ARCH_ARM, UC_MODE_ARM)
    for address, size in [(CODE,0x8000),(OBJECTS,0x2000),(GLOBALS,0x1000),(STACK,0x2000)]:
        cpu.mem_map(address,size)
    for name in names.values():
        raw, refs, _ = function(args.object_root / 'src/Collision/platform.o', name)
        code = bytearray(raw)
        for off, kind, symbol, addend in refs:
            if symbol not in addresses:
                raise AssertionError('Unexpected dependency: ' + symbol)
            target, location = addresses[symbol], addresses[name] + off
            if kind == 2:
                set32(code,off,target+addend)
            elif kind == 1:
                original = struct.unpack_from('<I',code,off)[0]
                delta = target + addend - location
                assert delta % 4 == 0
                set32(code,off,(original & 0xff000000) | ((delta >> 2) & 0xffffff))
            else:
                raise AssertionError('Unexpected relocation type')
        cpu.mem_write(addresses[name],bytes(code))
    rng = random.Random(20260919)
    states = [bytearray(rng.randbytes(NODE_SIZE)) for _ in range(NODE_COUNT)]
    order: list[int] = []
    def address(index: int) -> int:
        return OBJECTS + index*NODE_STRIDE
    def reset_expected(index: int) -> None:
        for off in (8,12,16): set32(states[index],off,0)
        states[index][0x51] = states[index][0x52] = 0
    def call(operation: str, index: int) -> None:
        cpu.reg_write(UC_ARM_REG_R0,address(index));cpu.reg_write(UC_ARM_REG_SP,STACK+0x1000)
        cpu.reg_write(UC_ARM_REG_LR,STOP)
        cpu.emu_start(addresses[names[operation]],STOP,count=500)
        assert cpu.reg_read(UC_ARM_REG_PC)==STOP, (operation,'did not return')
    def check() -> None:
        expected_globals = struct.pack('<2I',address(order[0]) if order else 0,address(order[-1]) if order else 0)
        assert bytes(cpu.mem_read(GLOBALS,8))==expected_globals,'head/tail differ'
        for i,expected in enumerate(states):
            assert bytes(cpu.mem_read(address(i),NODE_SIZE))==expected, ('state differs',i)
    for i,state in enumerate(states):
        cpu.mem_write(address(i),bytes(state));reset_expected(i);call('reset',i)
    check()
    # Repeated link/unlink, empty list, and deletion of head/tail/interior nodes.
    cases = 0
    for _ in range(4000):
        i = rng.randrange(NODE_COUNT); operation = rng.choice(('link','unlink'))
        if operation=='link' and i not in order:
            old_tail = order[-1] if order else None
            set32(states[i],8,address(old_tail) if old_tail is not None else 0)
            set32(states[i],12,0)
            if old_tail is not None:set32(states[old_tail],12,address(i))
            states[i][0x52]=1;order.append(i)
        elif operation=='unlink' and i in order:
            pos=order.index(i);prev=order[pos-1] if pos else None;nxt=order[pos+1] if pos+1<len(order) else None
            if prev is not None:set32(states[prev],12,address(nxt) if nxt is not None else 0)
            if nxt is not None:set32(states[nxt],8,address(prev) if prev is not None else 0)
            order.remove(i);reset_expected(i)
        call(operation,i);check();cases+=1
    report={'passed_operations':cases,'reset_cases':NODE_COUNT,'nodes_checked_after_each_operation':NODE_COUNT,
            'scope':'Synthetic linked-list invariants and complete node-memory comparison against compiled ARM; not a gameplay test.'}
    args.report.parent.mkdir(parents=True,exist_ok=True)
    args.report.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))


if __name__=='__main__':
    main()
