# A2DE matching progress

Measured on 2026-09-19 with the supplied A2DE ROM, dsd 0.12.0, Zig 0.16.0, objdiff-cli 3.8.1, and mwccarm 1.2/sp3 (2.0 build 84), executed through wibo 1.2.0.

| Checkpoint | Matching code bytes | Total code bytes | Matching code | Matching functions |
| --- | ---: | ---: | ---: | ---: |
| Baseline at 6e60cc29 | 80,456 | 2,876,454 | 2.797055% | 950 / 15,667 |
| Object104 and Object266 | 80,668 | 2,876,454 | 2.804425% | 956 / 15,667 |

This checkpoint adds 212 matching code bytes and six matching functions. No unit lost previously matching code bytes. The denominator and measurement configuration are unchanged.

- Object104: 420 / 420 code bytes, 7 / 7 functions.
- Object266: 264 / 264 code bytes, 5 / 5 functions.
- Their data sections are not yet fully matching. A 100% code result is not a claim that every section of the object is complete.

Validated locally with `zig build all -DRelease=A2DE -j4` followed by `zig build report -DRelease=A2DE`. Both completed successfully. This is object-code matching validation, not a full linked-ROM or gameplay test. The inherited self-hosted CI does not establish validation for this fork without a configured runner.

The reconstruction incorporates Ozero4's upstream contributions in NSMB-Decomp/nsmb#14 and #15. Object104 additionally uses the target's unmangled tile-query helper linkage, bringing its code to an exact match.

No ROM, extracted game binaries, or official NitroSDK library sources are included. The project is not 100% decompiled.
