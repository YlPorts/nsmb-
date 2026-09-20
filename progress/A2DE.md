# A2DE matching progress

Measured on 2026-09-19 using the supplied A2DE ROM, dsd 0.12.0, Zig 0.16.0, objdiff-cli 3.8.1, and mwccarm 1.2/sp3 (2.0 build 84), executed through wibo 1.2.0.

| Checkpoint | Matching code bytes | Total code bytes | Matching code | Matching functions |
| --- | ---: | ---: | ---: | ---: |
| Baseline at 6e60cc29 | 80,456 | 2,876,454 | 2.797055% | 950 / 15,667 |
| Object104 and Object266 (6666f37) | 80,668 | 2,876,454 | 2.804425% | 956 / 15,667 |
| Verified lifecycle methods (e764d7d) | 81,580 | 2,876,454 | 2.836131% | 1,128 / 15,667 |
| Goomba states and collision helpers (fcff83e) | 83,204 | 2,876,454 | 2.892589% | 1,145 / 15,667 |
| Object layouts, vectors and sound-test update (262f343) | 87,612 | 2,876,454 | 3.045834% | 1,184 / 15,667 |
| Collision, movement and minigame lifecycle reconstruction (4d786f3) | 91,704 | 2,876,454 | 3.188092% | 1,223 / 15,667 |
| Shared model bases, platform lists and 62 object layouts | 115,988 | 2,876,454 | 4.032326% | 1,418 / 15,667 |
| Worldmap character/player-model completion | 121,032 | 2,876,454 | 4.207681% | 1,441 / 15,667 |
| Worldmap camera code completion | 123,816 | 2,876,454 | 4.304467% | 1,453 / 15,667 |
| Object258 grouped layout and 11 recovered allocation sizes | 124,536 | 2,876,454 | 4.329497% | 1,465 / 15,667 |
| WorldmapScene helper, input and menu recovery | 126,616 | 2,876,454 | 4.401809% | 1,506 / 15,667 |

**Cumulative gain: 46,160 matching code bytes and 556 matching functions.** The code-size and function-count denominators have not changed. No previously matching function was lost, checking each function's unit and original address.

## Latest verified changes — WorldmapScene helper pass

**4.401809% matching code**, up from 4.329497% at `f42a292`. This pass adds **41 matching functions / 2,080 matching code bytes**. The new total is **126,616 / 2,876,454 code bytes** and **1,506 / 15,667 functions**. Matching data remains **4,276 / 851,344 bytes**.

| Area | New matching functions | New matching code bytes |
| --- | ---: | ---: |
| `src/worldmap/scene` query/completion/input/menu helpers | 41 | 2,080 |

- Recover world/path/node query helpers, completion counters, star-coin/path accounting support, world transition helpers, input checks, and five `WorldmapScene` menu dispatch methods.
- Recover the original member-function symbol names for the five menu methods so their ARM bodies and relocation targets compare under the correct C++ names.
- `src/worldmap/scene` now reports **2,080 / 15,256 matching code bytes and 41 / 69 matching functions**. Functions that remained only fuzzy were excluded from this batch.

### Validation of this pass

The complete local objdiff report reproduces **126,616 / 2,876,454 matching code bytes**, **1,506 / 15,667 matching functions**, and **4,276 / 851,344 matching data bytes**. The project-wide delta from `f42a292` is exactly **+2,080 bytes / +41 functions**, with no previously matching function or code byte lost.

Every function listed in the batch manifest is compared against the supplied A2DE reference using complete ARM instruction bytes after relocation normalization plus explicit RELA offset/type/symbol/addend checks. Public CI recompiles the same sources and reproduces the aggregate fingerprint without publishing ROM or extracted original binaries.

```sh
zig build delink -DRelease=A2DE
zig build objdiff -DRelease=A2DE
zig build all -DRelease=A2DE
objdiff-cli report generate -o build/report.json
python3 tools/verify_matching_batch.py --object-root build/A2DE --compare-original
```

These are ARM9 object-code comparisons against the supplied A2DE reference, **not a linked-ROM/gameplay-completion or native-port test**.

## Previous verified changes — allocation/layout pass

**4.329497% matching code**, up from 4.304467% at `296e67f`. This pass adds **12 matching functions / 720 matching code bytes**. The new total is **124,536 / 2,876,454 code bytes** and **1,465 / 15,667 functions**. Matching data remains **4,276 / 851,344 bytes**.

| Area | New matching functions | New matching code bytes |
| --- | ---: | ---: |
| `Object258::create` after grouped `0x4A0` member recovery | 1 | 192 |
| 11 factory allocation-size recoveries | 11 | 528 |

- Recover `Object258`'s `0x4A0` region as one grouped subobject containing a `Vec3_32` and 62 `Vec2_32` entries. This restores the original field offsets and makes the 192-byte factory instruction stream and relocation references match exactly.
- Recover original allocation sizes for `Object76`, `Object249`, `Object341`, `Object342`, `Object343`, `Object344`, `Object348`, `Object350`, `Object354`, `Object367` and `Object368`, with active compile-time size assertions.
- For those 11 factories, the generated ARM code and function sizes match the reference. Remaining objdiff fuzziness is limited to equivalent unresolved relocation labels for the shared `StageEntity` constructor/vtable targets; the whole-project code-byte report counts the code as matching. No relocation is discarded when claiming `Object258`'s exact match.

### Validation of this pass

The complete local objdiff report reproduces **124,536 / 2,876,454 matching code bytes**, **1,465 / 15,667 matching functions**, and **4,276 / 851,344 matching data bytes**. The project-wide delta from the camera checkpoint is exactly **+720 bytes / +12 functions**, with no previously matching code or function lost. All translation units compile with the recovered sizes.

```sh
zig build delink -DRelease=A2DE
zig build objdiff -DRelease=A2DE
zig build all -DRelease=A2DE -j4
build/bin/objdiff-cli report generate -o build/report.json
python3 tools/update_progress.py --report build/report.json --check
```

These are ARM9 object-code comparisons against the supplied A2DE reference, **not a linked-ROM/gameplay-completion or native-port test**. No ROM or extracted original game binaries are published.

## Previous verified changes — worldmap camera code pass

**4.304467% matching code**, up from 4.207681% at `76daeb8`. This pass adds **12 matching functions / 2,784 matching code bytes**. The new total is **123,816 / 2,876,454 code bytes** and **1,453 / 15,667 functions**. Matching data remains **4,276 / 851,344 bytes**.

| Area | New matching functions | New matching code bytes |
| --- | ---: | ---: |
| WorldMapCamera lifecycle, task state, update/render/create and factory | 12 | 2,784 |

- Reconstruct the full configured `WorldMapCamera` code range: destructors, task dispatch/state transitions, FOV interpolation, camera update, view rendering, creation and allocation helper.
- Recover the `View` matrix initialization used by the original constructor path and the `Vec3_32` base-pointer conversion needed for the original ARM code generation.
- Recover the `WorldMapCamera`, `PerspView` and `View` symbol boundaries and equivalent relocation addends without changing effective target addresses.
- Keep the camera unit marked incomplete because its configured data range is not yet 100% matching; this checkpoint claims **100% camera code**, not 100% camera data.

### Validation of this pass

The complete local objdiff report reproduces **123,816 / 2,876,454 matching code bytes**, **1,453 / 15,667 matching functions**, and **4,276 / 851,344 matching data bytes**. `src/worldmap/camera` reports **2,784 / 2,784 matching code bytes and 12 / 12 matching functions**.

The project-wide gain is exactly the camera gain (+12 functions / +2,784 bytes), so no previously matching function or code byte was lost. Every recovered camera function also reproduces the original instruction stream after relocation normalization, including matching relocation count/offset/type/addend structure.

```sh
zig build delink -DRelease=A2DE
zig build objdiff -DRelease=A2DE
zig build all -DRelease=A2DE -j4
build/bin/objdiff-cli report generate -o build/report.json
python3 tools/update_progress.py --report build/report.json --check
```

These are ARM9 object-code comparisons against the supplied A2DE reference, **not a linked-ROM/gameplay-completion, rendering/audio or native-port test**. No ROM or extracted original game binaries are published.

## Previous verified changes — worldmap character/player-model pass

**4.207681% matching code**, up from 4.032326% at `a2945ad`. This pass added **23 matching functions / 5,044 matching code bytes**. All 1,418 functions matching at the preceding checkpoint remained matching. Matching data increased by **248 bytes**, from 4,028 to 4,276.

| Area | New matching functions | New matching code bytes |
| --- | ---: | ---: |
| WmCharacter, including static initializer/constructor sections | 21 | 2,916 |
| WmPlayerModel render/resource loading | 2 | 2,128 |

- Reconstructed `WmCharacter` task dispatch, update/render hooks, resource creation, creation/destruction, and static task/profile/resource data.
- Completed `WmPlayerModel::render` and `WmPlayerModel::loadResources`, corrected the update parameter width, and corrected `ModelAnm::create` from C++ `bool` to Nitro `BOOL`.

## Previous verified changes — large layout/platform pass

**4.032326% matching code**, up from 3.188092% at `4d786f3`. This pass adds **195 matching functions / 24,284 matching code bytes**. All 1,223 previously matching functions remain matching. Code, data and function-count denominators are unchanged.

| Area | New matching functions | New matching code bytes |
| --- | ---: | ---: |
| 62 recovered object layouts and shared-base inheritance | 176 | 23,192 |
| ModelAnmEntity construction/destruction | 4 | 412 |
| Platform list management, construction and geometry setters | 15 | 680 |

- Reconstruct two shared model-owning bases, named `ModelEntity` and `ModelAnmEntity` here. These are **reconstructed names**, not claims of recovered original class names. Distinguish their members and destructor chains from flat byte padding.
- Recover 62 object allocations, typed model/animation/vector/platform members, and constructor-array counts/strides. All recovered class sizes have active `static_assert` checks. [Per-class evidence and results](layouts-A2DE-20260919.md) show which factories/destructors match; this is not a claim that 62 complete enemies are implemented.
- Implement Platform's reset, link and unlink operations, all three base destructor variants, base/rotating/segment constructors, the original no-op hooks, and four rotating-platform geometry setters. Rendering, collision-resolution and platform-specific update overrides still require reconstruction.
- Recover virtual-table prefix boundaries and preserve every relocation's effective target address when moving a label back to its 8-byte header. New source units are split out of previously generated gaps, without dropping original instructions from the measurement.

### Validation of this pass

All **358 game/library translation units compile**. The complete local objdiff report reproduces 115,988 / 2,876,454 matching code bytes and 1,418 / 15,667 matching functions.

Every one of the **195 new functions additionally passes a stricter local comparison**: equal function size, equal complete ARM instructions after normalizing only relocation-encoded address/displacement bits, and equal relocation offsets, types, symbol names and explicit addends. No relocation references are ignored. The public aggregate hash covers the ordered size, instruction hash and relocation-reference hash of each compiled reconstruction; no original instruction data is embedded.

```sh
python3 tools/verify_matching_batch.py --object-root build/A2DE --compare-original \
    --report build/strict-original-verification.json
```

The public CI reproduces the compiled-function hashes/references; it cannot recalculate whole-game matching without the private ROM. Existing 4,000 synthetic scalar tests still pass. New Platform tests pass **4,000 list operations plus 12 reset cases**, checking all 12 nodes after each operation, including repeated insertion/removal and head/tail/interior removal.

```sh
python3 tools/test_recovered_leaf.py --object-root build/ci-objects
python3 tools/test_platform_lists.py --object-root build/ci-objects
python3 tools/update_progress.py --check
```

**Data-accounting correction:** matching data decreases from 4,036 to 4,028 bytes. The previous Object325 data range included the first 8 bytes of the neighboring shared-base virtual-table header. Those bytes now belong to their actual table/gap instead. Total data remains 851,344 bytes; no matching code function was lost. This correction is recorded rather than hidden by changing a denominator.

The README's large percentage card and A2DE table row now display **this fork's measured code percentage**, generated from integer totals in `progress/summary.json`. The inherited upstream decomp.dev badge no longer masquerades as this fork's progress. Regenerate from a new local report using `tools/update_progress.py --report build/report.json --date YYYY-MM-DD`; `--check` rejects a stale README/card.

These are ARM9 object-code comparisons and focused synthetic tests, **not a linked-ROM, gameplay-completion, rendering/audio or native-port test**. Many gameplay methods and data sections remain incomplete.

## Previous collision, movement and minigame checkpoint

This checkpoint adds **39 matching functions / 4,092 matching code bytes** over 262f343. The original denominators are unchanged and all 1,184 previously matching functions are retained, using the unit, original address and explicit symbol-rename mapping, including aliased functions and distinct sections.

| Area | New matching functions | New matching code bytes |
| --- | ---: | ---: |
| Six object layouts and shared-profile factories | 19 | 2,092 |
| StageEntity collision and movement helpers | 7 | 876 |
| Actor directional movement and nearest-player search | 4 | 772 |
| MGScene and MGDebugScene lifecycle routines | 9 | 352 |

- **Object23, Object78, Object94, Object101, Object115 and Object135:** reconstruct member offsets and allocation sizes. Profiles 24/25/26 create Object23, profile 95 creates Object94, and profile 102 creates Object101. These are shared runtime classes, not additional distinct enemy implementations. Only the listed functions are claimed matching; the classes are still incomplete.
- **StageEntity:** reconstruct squish detection, side/bottom/cumulative sensor updates, lava collision handling, rotation-to-target and bounce response. CollisionMgr's previously opaque fields at 0x54 and 0x68 are recovered without changing the enclosing layout.
- **Actor:** reconstruct directional velocity in 2D/3D and nearest-player searches with and without horizontal wrapping. Correct the search API to return an Actor pointer and accept optional displacement-output pointers. The angle parameter uses the original low-16-bit wrapping behavior.
- **Minigames:** reconstruct creation/destruction/render/update hooks and the creation helper in MGScene, plus MGDebugScene::preUpdate. Recover MGScene fields at 0x5C and 0x60 while preserving affected derived layouts. This incorporates cappuch's PR #10, with original-binary-verified corrections to global/helper names and additional recovered methods.

**Size-check correction:** NTR_SIZE_GUARD is currently an empty macro in nsmb_nitro.hpp. The preceding checkpoint's statement that its guards enforced the sizes was incorrect. This checkpoint replaces the guards on the twelve previously recovered object layouts and the six new layouts with active static_assert checks. The earlier matching-code measurements remain valid.

### Previous layout checkpoint

At 262f343, twelve object layouts (Object47, Object60, Object61, Object63, Object71, Object72, Object81, Object148, Object149, Object155, Object211 and Object265) and three routines (StageEntity::tryNormalizeVec3, StageEntity::isPlayerInZone and SoundTestScene::onUpdate) added 39 functions / 4,408 bytes over fcff83e. The full class implementations remain incomplete.

## Preceding checkpoints

- Goomba: mega-dropped and stomped states, defeated update, stomp response, player collision, and music-event handling. The player-collision reconstruction now passes the player pointer to both StageEntity helpers, matching the original ARM calling convention.
- MiniGoomba and ParaGoomba: factories and destructors, with corrected virtual-table symbol boundaries and relocations.
- StageEntity: two reconstructed player-collision helpers, plus an exact reconstruction of the related blue-shell helper.
- FireSnake and Object18: destruction/cleanup routines.

The Goomba checkpoint added **17 matching functions / 1,624 matching code bytes** over e764d7d. Goomba's unit now has 1,280 / 7,456 matching code bytes (13 / 28 matching functions); the class is still incomplete.

The preceding lifecycle checkpoint reconstructed 172 known parameterless leaf methods across 92 translation units. Every one was compared directly with the original function bytes. Empty methods in that checkpoint are genuinely empty in the original, not substitutes for missing game logic. The exact e764d7d source snapshot was rebuilt locally and reproduced the same totals.

Object104 remains at 420 / 420 code bytes (7 / 7 functions), and Object266 at 264 / 264 code bytes (5 / 5 functions). Their data sections are not fully matching; 100% code does not mean every section is complete.

## Earlier checkpoint validation and reproducibility

Full source compilation and the local progress report both pass:

```sh
zig build delink -DRelease=A2DE
zig build all -DRelease=A2DE -j4
zig build report -DRelease=A2DE
```

The batch manifest records SHA-256 fingerprints of the 39 locally compiled functions that objdiff matched to the original, including relocation fingerprints. The publication workflow checks exact source preimages/postimages, recompiles all 356 game/library units without a ROM, and verifies these fingerprints before committing the patch. This reproduces the locally tested code; it does not calculate whole-game matching progress without the private ROM.

Four recovered ARM routines (rotation, squish detection, bounce response and 3D directional velocity) also pass **4,000 deterministic synthetic-state tests** against independent scalar models, executed through Unicorn 2.1.4. The test uses generated state and trigonometry-table values, not original game data:

```sh
python3 -m pip install pyelftools==0.32 unicorn==2.1.4
python3 tools/test_recovered_leaf.py --object-root build/ci-objects
```

These are focused function tests; they do not test stage completion, rendering, audio or a playable ROM.

These checks are **object-code validation, not a linked-ROM or gameplay test**. The project is not 100% decompiled and this checkpoint is not a native PC/Android port.

## Attribution

The reconstruction incorporates Ozero4's upstream contributions in NSMB-Decomp/nsmb#13, #14 and #15, and cappuch's cleanup/lifecycle work from #11 and #10. Additional work corrects Object104's external helper linkage and Goomba's helper parameter types, reconstructs the StageEntity helper bodies, recovers the twelve layouts and three additional routines above, and verifies all reported gains locally.

No ROM, extracted original game binaries, or official NitroSDK library sources are published with these changes.
