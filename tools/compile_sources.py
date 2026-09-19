#!/usr/bin/env python3
"""Compile A2DE sources with matching MWCC flags, without a ROM.

This checks compilation only. It does not measure decompilation completion.
Downloaded compiler files stay under ignored build/ci-tools and are not artifacts.
"""
from __future__ import annotations
import argparse
import concurrent.futures
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
import zipfile

ROOT = Path(__file__).resolve().parents[1]
TOOLS = ROOT / 'build/ci-tools'
OUTPUT = ROOT / 'build/ci-objects'
FLAGS = ['-O4,p', '-interworking', '-proc=arm946e', '-lang=C++',
         '-Cpp_exceptions=off', '-w=off', '-gccinc', '-nolink', '-c',
         '-sym=on', '-RTTI=off', '-once', '-i', 'lib/Nitro/', '-d', 'VER_A2DE']
WIBO_SHA256 = '13f86a2d618f0dbe67179d349625345eabf9b46450295cb4c904e49f6aff85af'


def prepare() -> None:
    TOOLS.mkdir(parents=True, exist_ok=True)
    downloads = {
        'wibo': 'https://github.com/decompals/wibo/releases/download/1.2.0/wibo-x86_64',
        'mwccarm.zip': 'https://github.com/decompme/compilers/releases/download/compilers/mwccarm.zip',
    }
    for filename, url in downloads.items():
        subprocess.run(['curl', '--fail', '--location', '--retry', '3', url,
                        '-o', str(TOOLS / filename)], check=True)
    wibo = TOOLS / 'wibo'
    if hashlib.sha256(wibo.read_bytes()).hexdigest() != WIBO_SHA256:
        raise ValueError('wibo checksum mismatch')
    wibo.chmod(0o755)
    with zipfile.ZipFile(TOOLS / 'mwccarm.zip') as archive:
        for member in archive.infolist():
            if not (TOOLS / member.filename).resolve().is_relative_to(TOOLS.resolve()):
                raise ValueError('Unsafe compiler archive path')
        archive.extractall(TOOLS)
    compiler_dir = TOOLS / 'mwccarm/1.2/sp3'
    shutil.copy2(TOOLS / 'mwccarm/license.dat', compiler_dir / 'license.dat')
    if (compiler_dir / 'lmgr8c.dll').exists():
        shutil.copy2(compiler_dir / 'lmgr8c.dll', compiler_dir / 'LMGR8C.dll')


def compile_one(source: Path) -> dict:
    dest = OUTPUT / source.with_suffix('.o')
    dest.parent.mkdir(parents=True, exist_ok=True)
    command = [str(TOOLS / 'wibo'), str(TOOLS / 'mwccarm/1.2/sp3/mwccarm.exe'),
               str(ROOT / source), '-o', str(dest), *FLAGS]
    try:
        process = subprocess.run(command, cwd=ROOT, stdout=subprocess.PIPE,
                                 stderr=subprocess.STDOUT, timeout=90)
        status, log = process.returncode, process.stdout.decode('utf-8', errors='replace')
    except subprocess.TimeoutExpired:
        status, log = 124, 'Compiler timed out after 90 seconds'
    if log or status:
        dest.with_suffix('.log').write_text(log)
    return {'source': str(source), 'object': str(dest.relative_to(ROOT)),
            'source_sha256': hashlib.sha256((ROOT / source).read_bytes()).hexdigest(),
            'exit_code': status}


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--prepare', action='store_true')
    args = parser.parse_args()
    if args.prepare:
        prepare()
    OUTPUT.mkdir(parents=True, exist_ok=True)
    sources = sorted(p.relative_to(ROOT) for base in ('src', 'lib')
                     for p in (ROOT / base).rglob('*.cpp'))
    if not sources:
        raise ValueError('No source files found')
    with concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:
        results = list(pool.map(compile_one, sources))
    failed = [r for r in results if r['exit_code']]
    compiler = TOOLS / 'mwccarm/1.2/sp3/mwccarm.exe'
    report = {
        'commit': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
        'release': 'A2DE', 'compiler': 'mwccarm 1.2/sp3',
        'compiler_sha256': hashlib.sha256(compiler.read_bytes()).hexdigest(), 'flags': FLAGS,
        'compiled': len(results) - len(failed), 'failed': len(failed),
        'matching_verified': False, 'units': results,
    }
    (OUTPUT / 'compile-report.json').write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps({k: v for k, v in report.items() if k != 'units'}, indent=2))
    for result in failed:
        print('FAILED:', result['source'])
        print((OUTPUT / Path(result['source']).with_suffix('.log')).read_text())
    if os.environ.get('GITHUB_STEP_SUMMARY'):
        with open(os.environ['GITHUB_STEP_SUMMARY'], 'a') as summary:
            summary.write(f"## A2DE compilation\n{report['compiled']} compiled; {report['failed']} failed.\n\n")
            summary.write('No ROM is used or published. Compilation is **not** a matching-progress measurement.\n')
    sys.exit(bool(failed))


if __name__ == '__main__':
    main()
