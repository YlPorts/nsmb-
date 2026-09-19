#!/usr/bin/env python3
"""Reproduce a locally verified batch; optionally compare to private ROM delinks.

The public manifest contains hashes, not original game instructions. CI without a
ROM checks reproducibility only. --compare-original requires objdiff.json and its
original delinked objects, and checks complete instructions and RELA references.
"""
from __future__ import annotations
import argparse
import gzip
import hashlib
import io
import json
from pathlib import Path, PurePosixPath
import struct
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection


def digest(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def safe_unit(value: str) -> str:
    path = PurePosixPath(value)
    if path.is_absolute() or '..' in path.parts or path.parts[0] not in ('src', 'lib'):
        raise ValueError('Unsafe unit path: ' + value)
    return str(path)


def function(path: Path, name: str) -> tuple[bytes, list, bytes]:
    elf = ELFFile(io.BytesIO(path.read_bytes()))
    if elf.elfclass != 32 or not elf.little_endian or elf['e_machine'] != 'EM_ARM':
        raise ValueError('Expected a 32-bit little-endian ARM object: ' + str(path))
    symtab = elf.get_section_by_name('.symtab')
    symbols = symtab.get_symbol_by_name(name) or []
    symbols = [s for s in symbols if isinstance(s['st_shndx'], int) and s['st_info']['type'] == 'STT_FUNC']
    if len(symbols) != 1:
        raise ValueError('Missing or ambiguous defined function: ' + name)
    symbol = symbols[0]
    section = elf.get_section(symbol['st_shndx'])
    start, size = symbol['st_value'] & ~1, symbol['st_size']
    if not size:
        raise ValueError('Empty symbol size: ' + name)
    mappings = [s for s in symtab.iter_symbols() if s['st_shndx'] == symbol['st_shndx']
                and s.name in ('$a', '$t') and s['st_value'] <= start]
    if symbol['st_value'] & 1 or (mappings and max(mappings, key=lambda s:s['st_value']).name == '$t'):
        raise ValueError('This strict batch verifier currently supports ARM, not Thumb: ' + name)
    offset = start - section['sh_addr']
    code = section.data()[offset:offset + size]
    if len(code) != size:
        raise ValueError('Function extends outside its section: ' + name)
    normalized = bytearray(code)
    references = []
    for relsec in elf.iter_sections():
        if not isinstance(relsec, RelocationSection) or relsec['sh_info'] != symbol['st_shndx']:
            continue
        targets = elf.get_section(relsec['sh_link'])
        for rel in relsec.iter_relocations():
            off = rel['r_offset'] - start
            if not 0 <= off < size:
                continue
            if off + 4 > size or not relsec.is_RELA():
                raise ValueError('Unsupported partial or implicit-addend relocation: ' + name)
            kind, addend = rel['r_info_type'], rel['r_addend']
            references.append([off, kind, targets.get_symbol(rel['r_info_sym']).name, addend])
            # Explicit RELA addends are compared separately, never discarded.
            # PC24: preserve opcode/condition bits and clear only the displacement.
            if kind == 1:  # R_ARM_PC24, used by this MWCC toolchain
                word = struct.unpack_from('<I', normalized, off)[0]
                struct.pack_into('<I', normalized, off, word & 0xff000000)
            elif kind == 2:  # R_ARM_ABS32
                normalized[off:off + 4] = b'\0' * 4
            else:
                raise ValueError('Unsupported relocation type %s in %s' % (kind, name))
    references.sort()
    return code, references, bytes(normalized)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--manifest', type=Path, default=Path('progress/batches/current.json'))
    parser.add_argument('--object-root', type=Path, default=Path('build/ci-objects'))
    parser.add_argument('--compare-original', action='store_true')
    parser.add_argument('--report', type=Path, default=Path('build/ci-objects/batch-verification.json'))
    args = parser.parse_args()
    meta = json.loads(args.manifest.read_text())
    packed = args.manifest.parent / meta['function_manifest']
    data = gzip.decompress(packed.read_bytes())
    if digest(data) != meta['function_manifest_sha256']:
        raise ValueError('Function-manifest fingerprint mismatch')
    expected = json.loads(data)
    if len(expected) != meta['verified_function_count'] or not expected:
        raise ValueError('Invalid function count')
    units = {}
    if args.compare_original:
        units = {u['name']: u for u in json.loads(Path('objdiff.json').read_text())['units']}
    seen, verified = set(), []
    for item in expected:
        unit, name = safe_unit(item['unit']), item['symbol']
        if (unit, name) in seen:
            raise ValueError('Duplicate manifest entry')
        seen.add((unit, name))
        code, refs, normalized = function(args.object_root / (unit + '.o'), name)
        refhash = digest(json.dumps(refs, separators=(',', ':')).encode())
        if len(code) != item['size']:
            raise ValueError('Compiled function size changed: ' + unit + ':' + name)
        if args.compare_original:
            original, original_refs, original_normalized = function(Path(units[unit]['target_path']), name)
            if len(code) != len(original) or normalized != original_normalized or refs != original_refs:
                raise ValueError('Original ARM instructions/references differ: ' + unit + ':' + name)
        verified.append({'unit':unit,'symbol':name,'size':len(code),'sha256':digest(code),'relocations_sha256':refhash})
    aggregate = digest(json.dumps(verified, sort_keys=True, separators=(',', ':')).encode())
    if aggregate != meta['compiled_functions_sha256']:
        raise ValueError('Compiled function/reference aggregate differs from the locally verified batch')
    report = {
        'compiled_functions_sha256': aggregate,
        'verified_function_count': len(verified),
        'verified_code_bytes': sum(item['size'] for item in verified),
        'compared_to_original': args.compare_original,
        'scope': ('Full ARM function size, relocation-normalized instructions, and explicit RELA references'
                  if args.compare_original else 'Reproduction of locally verified compiled functions; not ROM-free whole-game matching'),
        'functions': verified,
    }
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps({k:v for k,v in report.items() if k != 'functions'}, indent=2))


if __name__ == '__main__':
    main()
