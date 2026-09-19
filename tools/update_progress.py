#!/usr/bin/env python3
"""Generate the fork's README progress block and SVG from measured integer totals.

Use --report with a locally generated objdiff report to update the totals. CI can
use --check without a ROM to check that the visible dashboard agrees with the
stored measurement; that is not an independent whole-game matching measurement.
"""
from __future__ import annotations
import argparse
from decimal import Decimal
import hashlib
import json
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[1]
BEGIN, END = '<!-- A2DE_PROGRESS_START -->', '<!-- A2DE_PROGRESS_END -->'
KEYS = ('matched_code','total_code','matched_functions','total_functions','matched_data','total_data')


def percent(matched: int, total: int) -> str:
    return format(Decimal(matched)*100/Decimal(total), '.6f')


def load_measures(path: Path) -> dict:
    report = json.loads(path.read_text())['measures']
    measures = {key:int(report[key]) for key in KEYS}
    validate(measures)
    return measures


def validate(measures: dict) -> None:
    for matched,total in [('matched_code','total_code'),('matched_functions','total_functions'),('matched_data','total_data')]:
        if not isinstance(measures[matched],int) or not isinstance(measures[total],int) or not 0 <= measures[matched] <= measures[total] or measures[total]<=0:
            raise ValueError('Invalid measurement: ' + matched)


def generate(summary: dict, readme: str) -> tuple[str,str]:
    m=summary['measures'];validate(m);p=percent(m['matched_code'],m['total_code'])
    text=f'''{BEGIN}
<p align="center">
  <a href="progress/A2DE.md"><img src="progress/A2DE.svg" width="720" alt="A2DE matching code: {p}%" /></a>
</p>

## **{p}% matching code — this fork**

| Verified A2DE metric | Current result |
| --- | ---: |
| Matching code bytes | **{m['matched_code']:,} / {m['total_code']:,}** |
| Matching functions | **{m['matched_functions']:,} / {m['total_functions']:,}** |

Measured **{summary['measured_on']}**. The percentage is based on code bytes, not function count, playable levels or a PC/Android port.

**Latest pass: +{summary['gain']['matching_functions']:,} matching functions / +{summary['gain']['matching_code_bytes']:,} code bytes.**
[Measurement details](progress/A2DE.md) · [Machine-readable totals](progress/summary.json) · [Latest batch](progress/batches/current.json)

This counter tracks **YlPorts/nsmb-**, not the separate upstream decomp.dev counter. Update it from a new local objdiff report with `python3 tools/update_progress.py --report build/report.json --date YYYY-MM-DD`; CI checks that the visible counter and stored totals agree.
{END}'''
    if BEGIN in readme or END in readme:
        if readme.count(BEGIN)!=1 or readme.count(END)!=1: raise ValueError('Ambiguous progress markers')
        readme=re.sub(re.escape(BEGIN)+r'.*?'+re.escape(END),lambda _:text,readme,flags=re.S)
    else:
        readme='# New Super Mario Bros. — YlPorts decompilation\n\n'+text+'\n\n'+readme
    lines=readme.splitlines()
    rows=0
    for i,line in enumerate(lines):
        if line.startswith('|') and re.search(r'\|\s*A2DE\s*\|',line):
            cells=line.split('|');cells[-2]=f' [**{p}% (this fork)**](progress/A2DE.md) ';lines[i]='|'.join(cells);rows+=1
    if rows!=1:raise ValueError('Expected one A2DE release-table row')
    readme='\n'.join(lines)+'\n'
    width=Decimal(m['matched_code'])*624/Decimal(m['total_code'])
    svg=f'''<svg xmlns="http://www.w3.org/2000/svg" width="720" height="230" viewBox="0 0 720 230" role="img" aria-labelledby="title description">
  <title id="title">A2DE matching code: {p}%</title>
  <desc id="description">{m['matched_code']:,} of {m['total_code']:,} code bytes; {m['matched_functions']:,} of {m['total_functions']:,} functions. Measured {summary['measured_on']}. This is not a playable-game completion percentage.</desc>
  <rect width="720" height="230" rx="18" fill="#111827"/>
  <g font-family="Arial, Helvetica, sans-serif">
    <text x="48" y="43" fill="#cbd5e1" font-size="15" font-weight="700" letter-spacing="1.5">YLPORTS / NSMB — A2DE MATCHING CODE</text>
    <text x="48" y="116" fill="#34d399" font-size="62" font-weight="700">{p}%</text>
    <text x="49" y="150" fill="#f8fafc" font-size="17">{m['matched_code']:,} / {m['total_code']:,} code bytes</text>
    <rect x="48" y="173" width="624" height="10" rx="5" fill="#334155"/>
    <rect x="48" y="173" width="{width:.4f}" height="10" rx="5" fill="#34d399"/>
    <text x="48" y="210" fill="#cbd5e1" font-size="13">{m['matched_functions']:,} matching functions · Measured {summary['measured_on']} · Source reconstruction, not a port</text>
  </g>
</svg>
'''
    return readme,svg


def main() -> None:
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--report',type=Path)
    parser.add_argument('--baseline-report',type=Path)
    parser.add_argument('--baseline-revision')
    parser.add_argument('--date')
    parser.add_argument('--check',action='store_true')
    args=parser.parse_args()
    path=ROOT/'progress/summary.json'
    summary=json.loads(path.read_text()) if path.exists() else {}
    if args.report:
        m=load_measures(args.report)
        if args.check:
            if m != summary['measures']:raise ValueError('Stored measurement differs from local report')
        else:
            if args.baseline_report:
                baseline=load_measures(args.baseline_report)
            elif summary:
                baseline=summary['measures']
            else:raise ValueError('First measurement requires --baseline-report')
            if any(m[k]!=baseline[k] for k in ('total_code','total_functions','total_data')):
                raise ValueError('Measurement denominators changed; review before publishing')
            if not args.date:raise ValueError('--date YYYY-MM-DD is required for a new measurement')
            import datetime
            datetime.date.fromisoformat(args.date)
            summary={'schema_version':1,'release':'A2DE','measured_on':args.date,
                'scope':'Configured A2DE ARM9 code: main executable, autoloads and overlays',
                'based_on_revision':args.baseline_revision or 'unspecified; inspect source history',
                'toolchain':{'dsd':'0.12.0','zig':'0.16.0','objdiff-cli':'3.8.1','mwccarm':'1.2/sp3 (2.0 build 84)','runner':'wibo 1.2.0'},
                'local_report_sha256':hashlib.sha256(args.report.read_bytes()).hexdigest(),
                'measures':m,'previous_measures':baseline,
                'gain':{'matching_code_bytes':m['matched_code']-baseline['matched_code'],
                        'matching_functions':m['matched_functions']-baseline['matched_functions']}}
    if not summary:raise ValueError('No measurement available')
    readme=ROOT/'readme.md'
    generated,svg=generate(summary,readme.read_text())
    outputs={readme:generated,ROOT/'progress/A2DE.svg':svg,path:json.dumps(summary,indent=2)+'\n'}
    for target,content in outputs.items():
        if args.check:
            if not target.exists() or target.read_text()!=content:
                raise ValueError('Outdated progress display: ' + str(target.relative_to(ROOT)))
        else:
            target.parent.mkdir(parents=True,exist_ok=True);target.write_text(content)
    print(('Checked' if args.check else 'Updated')+' A2DE matching code: '+percent(summary['measures']['matched_code'],summary['measures']['total_code'])+'%')


if __name__=='__main__':
    main()
