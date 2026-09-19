# A2DE object-layout pass — 2026-09-19

Names below are the existing numeric object labels. Only matched functions are claimed, not complete object behavior. Member layouts come from original allocation sizes, constructor/destructor sequences, vector virtual-table writes and constructor-array strides. Unknown spans stay explicitly marked as unrecovered padding.

All listed allocation sizes are enforced by active compile-time assertions. ModelEntity/ModelAnmEntity are reconstructed names for shared runtime bases. Percentages in the last column concern the factory function only, not the entire class.

| Class | Base | Allocation | New matching functions | New matching bytes | Factory match |
| --- | --- | ---: | ---: | ---: | ---: |
| Object27 | StageEntity | `0x5E4` | 3 | 416 | 41.3600%, 100.0000% |
| Object28 | ModelAnmEntity | `0xD50` | 3 | 152 | 64.5882%, 100.0000% |
| Object29 | ModelAnmEntity | `0x4D4` | 3 | 120 | 100.0000% |
| Object36 | ModelAnmEntity | `0x75C` | 3 | 320 | 100.0000% |
| Object37 | ModelEntity | `0x4F4` | 3 | 372 | 39.7692%, 100.0000% |
| Object39 | StageEntity | `0x5E4` | 3 | 464 | 100.0000% |
| Object41 | ModelAnmEntity | `0x5B0` | 3 | 256 | 43.9200%, 100.0000% |
| Object57 | StageEntity | `0x4DC` | 3 | 340 | 100.0000% |
| Object65 | StageEntity | `0x1CC4` | 3 | 544 | 100.0000% |
| Object68 | ModelAnmEntity | `0x5AC` | 3 | 260 | 39.9615%, 39.9615%, 100.0000% |
| Object69 | ModelAnmEntity | `0x5C0` | 3 | 256 | 100.0000% |
| Object70 | ModelAnmEntity | `0x69C` | 3 | 344 | 100.0000% |
| Object73 | ModelAnmEntity | `0x51C` | 3 | 120 | 100.0000% |
| Object74 | ModelAnmEntity | `0x5C0` | 3 | 172 | 100.0000% |
| Object77 | ModelEntity | `0x4A8` | 3 | 348 | 100.0000% |
| Object80 | ModelEntity | `0x538` | 3 | 420 | 100.0000% |
| Object90 | StageEntity | `0x554` | 3 | 340 | 100.0000% |
| Object91 | ModelAnmEntity | `0x4FC` | 3 | 120 | 100.0000% |
| Object97 | StageEntity | `0x460` | 3 | 336 | 100.0000% |
| Object98 | StageEntity | `0x10B0` | 3 | 664 | 100.0000% |
| Object105 | StageEntity | `0x62C` | 0 | 0 | 75.9111% |
| Object108 | StageEntity | `0x85C` | 3 | 484 | 100.0000% |
| Object112 | ModelAnmEntity | `0x5E4` | 3 | 340 | 100.0000% |
| Object113 | ModelAnmEntity | `0x5C4` | 3 | 224 | 100.0000% |
| Object114 | ModelAnmEntity | `0x540` | 3 | 208 | 100.0000% |
| Object117 | ModelAnmEntity | `0x608` | 2 | 240 | 80.5526% |
| Object118 | ModelAnmEntity | `0x4DC` | 3 | 120 | 100.0000% |
| Object119 | StageEntity | `0x72C` | 3 | 676 | 100.0000% |
| Object120 | ModelAnmEntity | `0x52C` | 3 | 120 | 100.0000% |
| Object121 | StageEntity | `0xD74` | 3 | 788 | 100.0000% |
| Object124 | ModelEntity | `0x4D8` | 3 | 464 | 100.0000% |
| Object128 | ModelAnmEntity | `0x988` | 3 | 536 | 100.0000% |
| Object129 | ModelAnmEntity | `0x5B0` | 3 | 176 | 100.0000% |
| Object134 | ModelAnmEntity | `0x524` | 3 | 156 | 100.0000% |
| Object147 | StageEntity | `0x7C0` | 3 | 412 | 100.0000% |
| Object151 | StageEntity | `0x4EC` | 3 | 528 | 100.0000% |
| Object168 | StageEntity | `0x8BC` | 2 | 540 | 100.0000% |
| Object169 | StageEntity | `0x5A4` | 3 | 428 | 100.0000% |
| Object170 | StageEntity | `0x508` | 3 | 360 | 100.0000% |
| Object171 | StageEntity | `0x50C` | 3 | 360 | 100.0000% |
| Object188 | StageEntity | `0x540` | 3 | 360 | 100.0000% |
| Object198 | StageEntity | `0x4D8` | 3 | 360 | 100.0000% |
| Object200 | StageEntity | `0x1CE8` | 3 | 680 | 100.0000% |
| Object201 | StageEntity | `0x1E70` | 3 | 680 | 100.0000% |
| Object208 | StageEntity | `0x51C` | 3 | 360 | 100.0000% |
| Object209 | StageEntity | `0x68C` | 2 | 456 | 93.5769% |
| Object210 | StageEntity | `0x5DC` | 3 | 576 | 100.0000% |
| Object212 | StageEntity | `0x6C8` | 3 | 452 | 100.0000% |
| Object213 | StageEntity | `0x5A0` | 1 | 108 | 100.0000% |
| Object215 | StageEntity | `0x528` | 3 | 360 | 100.0000% |
| Object227 | StageEntity | `0x4FC` | 3 | 360 | 100.0000% |
| Object228 | StageEntity | `0x4FC` | 3 | 360 | 100.0000% |
| Object231 | StageEntity | `0xA30` | 3 | 584 | 100.0000% |
| Object237 | ModelEntity | `0x508` | 3 | 376 | 100.0000% |
| Object239 | ModelAnmEntity | `0x7E0` | 3 | 572 | 100.0000% |
| Object242 | ModelAnmEntity | `0x5E8` | 3 | 260 | 39.9615%, 39.9615%, 39.9615%, 39.9615%, 39.9615%, 100.0000% |
| Object250 | ModelEntity | `0x700` | 2 | 504 | 83.7544% |
| Object258 | ModelEntity | `0xAA0` | 2 | 432 | 93.3333% |
| Object259 | ModelAnmEntity | `0x708` | 3 | 452 | 100.0000% |
| Object262 | StageEntity | `0x71C` | 3 | 588 | 100.0000% |
| Object269 | StageEntity | `0x6F8` | 3 | 668 | 100.0000% |
| Object301 | ModelAnmEntity | `0x4BC` | 3 | 120 | 100.0000% |

Factories below 100% are explicitly not counted as matching. Their recovered layout can still allow the destructor variants to match exactly. Shared bases retain pending gameplay overrides; only the recorded function-level results are validated.
