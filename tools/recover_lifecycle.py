#!/usr/bin/env python3
"""Recover exact constant/no-op A2DE hooks; never invent placeholder bodies.

The manifest was derived from dsd 0.12.0 delinked A2DE code at upstream
9c7c0b341ae87f860df090e1e35d720f06c70bfa. Every listed original function is
exactly BX LR, or MOV R0,#0/#1 followed by BX LR. No ROM is distributed.
Object104/Object266 hooks also overlap with Ozero4's upstream PRs #15/#14.

--apply updates only the listed C++ files and their class declarations.
--verify checks the compiled function's complete bytes, size and relocations.
This is a per-function test, NOT a project-wide completion percentage.
"""
from __future__ import annotations
import argparse
import json
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[1]
RECOVERIES = """
FireSnake _36:v
Item pendingDestroy:v
Object18 pendingDestroy:v
StageEntity onStomped:v
stubs/Object101 pendingDestroy:v
stubs/Object103 pendingDestroy:v onDestroy:1 _21:v
stubs/Object104 pendingDestroy:v onDestroy:1
stubs/Object105 pendingDestroy:v onDestroy:1
stubs/Object110 pendingDestroy:v onDestroy:1
stubs/Object111 pendingDestroy:v
stubs/Object112 onStomped:v _21:v
stubs/Object113 _24:v _26:v _27:v _25:v _36:v pendingDestroy:v onDestroy:1
stubs/Object114 _23:v pendingDestroy:v onDestroy:1
stubs/Object120 _36:v
stubs/Object121 pendingDestroy:v _21:v
stubs/Object122 entityCollision:v onDestroy:1
stubs/Object127 pendingDestroy:v onDestroy:1
stubs/Object128 entityCollision:v _27:v _26:v _25:v _24:v _22:v onDestroy:1
stubs/Object129 entityCollision:v _27:v _26:v _25:v _24:v _22:v
stubs/Object131 pendingDestroy:v _01:0
stubs/Object146 pendingDestroy:v _21:v
stubs/Object147 pendingDestroy:v onDestroy:1
stubs/Object148 pendingDestroy:v onDestroy:1
stubs/Object149 pendingDestroy:v onDestroy:1
stubs/Object151 pendingDestroy:v onDestroy:1
stubs/Object153 onHeapCreated:1
stubs/Object155 pendingDestroy:v onDestroy:1
stubs/Object158 pendingDestroy:v
stubs/Object185 pendingDestroy:v onDestroy:1
stubs/Object196 pendingDestroy:v
stubs/Object214 onHeapCreated:1 pendingDestroy:v _01:0
stubs/Object224 pendingDestroy:v
stubs/Object227 pendingDestroy:v
stubs/Object228 pendingDestroy:v
stubs/Object23 pendingDestroy:v _21:v
stubs/Object230 onDestroy:1 pendingDestroy:v
stubs/Object231 onDestroy:1 pendingDestroy:v
stubs/Object232 pendingDestroy:v
stubs/Object233 pendingDestroy:v
stubs/Object237 _36:v _37:v _15:v
stubs/Object239 onStomped:v _27:v _22:v _25:v _30:v
stubs/Object241 _21:v onRender:1 pendingDestroy:v
stubs/Object259 _30:v _23:v
stubs/Object260 pendingDestroy:v
stubs/Object261 pendingDestroy:v _01:0
stubs/Object262 pendingDestroy:v
stubs/Object263 pendingDestroy:v onDestroy:1
stubs/Object266 onUpdate_0:1
stubs/Object269 _11:v pendingDestroy:v
stubs/Object27 pendingDestroy:v
stubs/Object276 onUpdate:1
stubs/Object28 pendingDestroy:v onDestroy:1
stubs/Object29 onDestroy:1
stubs/Object305 onDestroy:1
stubs/Object306 onDestroy:1 pendingDestroy:v
stubs/Object307 onDestroy:1 pendingDestroy:v
stubs/Object309 onDestroy:1 pendingDestroy:v
stubs/Object311 onDestroy:1 pendingDestroy:v
stubs/Object312 onDestroy:1 pendingDestroy:v
stubs/Object315 onDestroy:1
stubs/Object317 onDestroy:1 pendingDestroy:v
stubs/Object330 onDestroy:1
stubs/Object331 onDestroy:1
stubs/Object332 onDestroy:1
stubs/Object336 onDestroy:1 pendingDestroy:v
stubs/Object337 onDestroy:1
stubs/Object345 pendingDestroy:v onUpdate_6:0 onUpdate_defeated:1 onUpdate_1:1
stubs/Object35 pendingDestroy:v onDestroy:1
stubs/Object36 pendingDestroy:v
stubs/Object37 onDestroy:1
stubs/Object39 pendingDestroy:v
stubs/Object40 pendingDestroy:v
stubs/Object43 pendingDestroy:v
stubs/Object47 pendingDestroy:v onDestroy:1
stubs/Object49 onDestroy:1 pendingDestroy:v onRender:1
stubs/Object54 pendingDestroy:v
stubs/Object55 onStomped:v onDestroy:1
stubs/Object65 _31:v pendingDestroy:v
stubs/Object67 _21:v
stubs/Object69 entityCollision:v
stubs/Object71 _11:v
stubs/Object73 _36:v
stubs/Object74 pendingDestroy:v
stubs/Object75 _23:v _21:v pendingDestroy:v
stubs/Object77 pendingDestroy:v onDestroy:1
stubs/Object78 pendingDestroy:v onDestroy:1 _01:0
stubs/Object79 pendingDestroy:v
stubs/Object81 onDestroy:1 _21:v
stubs/Object87 onRender:1
stubs/Object91 _27:v _30:v _25:v
stubs/Object94 pendingDestroy:v
stubs/Object96 pendingDestroy:v onDestroy:1
stubs/Object97 onRender:1 pendingDestroy:v onDestroy:1
stubs/Object98 pendingDestroy:v
"""
PATTERNS = {
    "v": bytes.fromhex("1eff2fe1"),
    "0": bytes.fromhex("0000a0e31eff2fe1"),
    "1": bytes.fromhex("0100a0e31eff2fe1"),
}
INTEGER_METHODS = {"onCreate", "onDestroy", "onUpdate", "onRender"}


def entries():
    for line in RECOVERIES.strip().splitlines():
        name, *methods = line.split()
        source = Path("src/Bases") / (name + ".cpp")
        cls = source.stem
        for item in methods:
            method, kind = item.split(":")
            result = "void" if kind == "v" else "s32" if method in INTEGER_METHODS else "bool"
            symbol = f"_ZN{len(cls)}{cls}{len(method)}{method}Ev"
            yield source, cls, method, kind, result, symbol


def code_only(text: str) -> str:
    # Preserve offsets while hiding comments and string/character literals.
    pattern = r'//[^\n]*|/\*[\s\S]*?\*/|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\''
    return re.sub(pattern, lambda m: " " * len(m.group()), text)


def apply() -> dict:
    changes: dict[Path, str] = {}
    count = 0
    for source, cls, method, kind, result, symbol in entries():
        cpp = ROOT / source
        header = cpp.with_suffix(".hpp")
        src = changes.get(cpp, cpp.read_text())
        hdr = changes.get(header, header.read_text())
        if re.search(r"\b" + re.escape(cls) + r"\s*::\s*" + re.escape(method) + r"\s*\(", code_only(src)):
            continue
        clean = code_only(hdr)
        start = re.search(r"\bclass\s+" + re.escape(cls) + r"\s*:[^{]+\{", clean)
        if start is None:
            raise ValueError(f"Cannot locate class {cls} in {header}")
        depth, end = 1, start.end()
        while end < len(clean) and depth:
            depth += (clean[end] == "{") - (clean[end] == "}")
            end += 1
        if depth:
            raise ValueError(f"Unbalanced class {cls}")
        body = clean[start.end():end-1]
        declaration = re.search(r"\b" + re.escape(method) + r"\s*\(\s*\)", body)
        if declaration and re.match(r"\s*\{", body[declaration.end():]):
            raise ValueError(f"Refusing to redefine inline {cls}::{method}")
        if not declaration:
            public = re.search(r"\bpublic\s*:", body)
            if public is None:
                raise ValueError(f"Cannot find public section of {cls}")
            offset = start.end() + public.end()
            hdr = hdr[:offset] + f"\n\t{result} {method}();" + hdr[offset:]
            changes[header] = hdr
        statement = "" if kind == "v" else "\treturn " + (
            kind if result == "s32" else "true" if kind == "1" else "false"
        ) + ";\n"
        src = src.rstrip() + f"\n\n{result} {cls}::{method}()\n{{\n{statement}}}\n"
        changes[cpp] = src
        count += 1
    # Validate all targets before writing any file.
    for path, text in changes.items():
        if not path.resolve().is_relative_to((ROOT / "src/Bases").resolve()):
            raise ValueError(f"Unexpected output path: {path}")
        if not text.endswith("\n"):
            raise ValueError(f"Missing final newline in {path}")
    for path, text in changes.items():
        path.write_text(text)
    return {"reconstructed_functions": count, "changed_files": len(changes),
            "paths": sorted(str(p.relative_to(ROOT)) for p in changes)}


def verify(object_root: Path, report_path: Path) -> dict:
    from elftools.elf.elffile import ELFFile
    import io
    objects = {}
    checks = []
    for source, cls, method, kind, result, name in entries():
        path = object_root / source.with_suffix(".o")
        if path not in objects:
            objects[path] = ELFFile(io.BytesIO(path.read_bytes()))
        elf = objects[path]
        symtab = elf.get_section_by_name(".symtab")
        found = [s for s in (symtab.get_symbol_by_name(name) or [])
                 if s["st_info"]["type"] == "STT_FUNC" and isinstance(s["st_shndx"], int)]
        if len(found) != 1:
            raise ValueError(f"Expected exactly one definition of {name} in {path}")
        sym = found[0]
        section = elf.get_section(sym["st_shndx"])
        start, size = sym["st_value"], sym["st_size"]
        actual = section.data()[start:start + size]
        relocations = []
        for reloc_section in elf.iter_sections():
            if reloc_section["sh_type"] not in ("SHT_REL", "SHT_RELA"):
                continue
            if reloc_section["sh_info"] != sym["st_shndx"]:
                continue
            relocations.extend(r["r_offset"] for r in reloc_section.iter_relocations()
                               if start <= r["r_offset"] < start + size)
        expected = PATTERNS[kind]
        match = actual == expected and not relocations
        checks.append({"source": str(source), "symbol": name, "bytes": size,
                       "expected_hex": expected.hex(), "actual_hex": actual.hex(),
                       "relocations": relocations, "match": match})
    report = {"scope": "listed A2DE lifecycle functions only", "project_percentage": None,
              "checked_functions": len(checks), "matched_functions": sum(c["match"] for c in checks),
              "checked_bytes": sum(c["bytes"] for c in checks), "functions": checks}
    report_path.parent.mkdir(parents=True, exist_ok=True)
    report_path.write_text(json.dumps(report, indent=2) + "\n")
    failed = [c["symbol"] for c in checks if not c["match"]]
    if failed:
        raise ValueError("Byte mismatches: " + ", ".join(failed))
    return {k: v for k, v in report.items() if k != "functions"}


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--apply", action="store_true")
    parser.add_argument("--verify", action="store_true")
    parser.add_argument("--object-root", type=Path, default=ROOT / "build/ci-objects")
    parser.add_argument("--report", type=Path, default=ROOT / "build/ci-objects/lifecycle-report.json")
    args = parser.parse_args()
    if args.apply:
        print(json.dumps(apply(), indent=2))
    if args.verify:
        print(json.dumps(verify(args.object_root, args.report), indent=2))
    if not args.apply and not args.verify:
        print(f"{sum(1 for _ in entries())} exact A2DE recovery candidates; use --apply or --verify.")


if __name__ == "__main__":
    main()
