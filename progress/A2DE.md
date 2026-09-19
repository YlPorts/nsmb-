# A2DE matching progress

Measured on 2026-09-19 using the supplied A2DE ROM, dsd 0.12.0, Zig 0.16.0, objdiff-cli 3.8.1, and mwccarm 1.2/sp3 (2.0 build 84), executed through wibo 1.2.0.

| Checkpoint | Matching code bytes | Total code bytes | Matching code | Matching functions |
| --- | ---: | ---: | ---: | ---: |
| Baseline at 6e60cc29 | 80,456 | 2,876,454 | 2.797055% | 950 / 15,667 |
| Object104 and Object266 (6666f37) | 80,668 | 2,876,454 | 2.804425% | 956 / 15,667 |
| Verified lifecycle methods (e764d7d) | 81,580 | 2,876,454 | 2.836131% | 1,128 / 15,667 |
| Goomba states and collision helpers (fcff83e) | 83,204 | 2,876,454 | 2.892589% | 1,145 / 15,667 |
| Object layouts, vectors and sound-test update | 87,612 | 2,876,454 | 3.045834% | 1,184 / 15,667 |

**Cumulative gain: 7,156 matching code bytes and 234 matching functions.** The code-size and function-count denominators have not changed. No previously matching function was lost, comparing each function's unit and original address rather than its possibly improved name.

## Latest verified changes

The latest checkpoint adds **39 matching functions / 4,408 matching code bytes** over fcff83e:

- Twelve object layouts recovered from original allocation sizes, member-constructor calls and vector virtual-table stores: Object47, Object60, Object61, Object63, Object71, Object72, Object81, Object148, Object149, Object155, Object211 and Object265. All 36 affected factory/destructor functions now match, and each layout has a compile-time size guard. Other methods of those classes remain incomplete.
- StageEntity::tryNormalizeVec3: restores the original zero-vector check and helper invocation.
- StageEntity::isPlayerInZone: restores the original position masking and rectangular-boundary checks.
- SoundTestScene::onUpdate: restores address arguments, mode selection and input handling.

All 39 functions match the original in objdiff. No previous matching function was lost, and the measurement denominators remain unchanged.

## Preceding checkpoints

- Goomba: mega-dropped and stomped states, defeated update, stomp response, player collision, and music-event handling. The player-collision reconstruction now passes the player pointer to both StageEntity helpers, matching the original ARM calling convention.
- MiniGoomba and ParaGoomba: factories and destructors, with corrected virtual-table symbol boundaries and relocations.
- StageEntity: two reconstructed player-collision helpers, plus an exact reconstruction of the related blue-shell helper.
- FireSnake and Object18: destruction/cleanup routines.

The Goomba checkpoint added **17 matching functions / 1,624 matching code bytes** over e764d7d. Goomba's unit now has 1,280 / 7,456 matching code bytes (13 / 28 matching functions); the class is still incomplete.

The preceding lifecycle checkpoint reconstructed 172 known parameterless leaf methods across 92 translation units. Every one was compared directly with the original function bytes. Empty methods in that checkpoint are genuinely empty in the original, not substitutes for missing game logic. The exact e764d7d source snapshot was rebuilt locally and reproduced the same totals.

Object104 remains at 420 / 420 code bytes (7 / 7 functions), and Object266 at 264 / 264 code bytes (5 / 5 functions). Their data sections are not fully matching; 100% code does not mean every section is complete.

## Validation and reproducibility

Full source compilation and the local progress report both pass:

```sh
zig build delink -DRelease=A2DE
zig build all -DRelease=A2DE -j4
zig build report -DRelease=A2DE
```

The batch manifest records SHA-256 fingerprints of the 39 locally compiled functions that objdiff matched to the original. The publication workflow checks exact source preimages/postimages, recompiles all game/library units without a ROM, and checks those fingerprints before committing the patch. This verifies reproduction of the locally tested code; it does not calculate whole-game matching progress without the private ROM.

These checks are **object-code validation, not a linked-ROM or gameplay test**. The project is not 100% decompiled and this checkpoint is not a native PC/Android port.

## Attribution

The reconstruction incorporates Ozero4's upstream contributions in NSMB-Decomp/nsmb#13, #14 and #15, and cappuch's cleanup routines from #11. Additional work corrects Object104's external helper linkage and Goomba's helper parameter types, reconstructs the StageEntity helper bodies, recovers the twelve layouts and three additional routines above, and verifies all reported gains locally.

No ROM, extracted original game binaries, or official NitroSDK library sources are published with these changes.
