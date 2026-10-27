# Prison Passage story sequence (retail vs TMBO), 2026-10-26

Read-only research: retail asm (`~/retail/asm/tmb/prison.s`, `ai.s`, `attract.s`, `game.s`, `shell.s`,
`destruct.s`) and TMBO asm (`~/tmbo/asm/nonmatchings/tmb/prison_part2/*`, `game/*`, `attract/*`).
Nothing below has been checked in-game. Timings are worked out from the constants.

## TL;DR
- The sequence is NOT a separate story script and is NOT node 6050. It is the `Prison` level object's state
  machine (`prisonUpdate__6Prison`), and it runs in every mode. In retail story it starts at "on the ship, doors
  closed, island 6000 units away", waits about 60 s, then the island slides in and docks. AI cars are released
  in 3 waves at fixed start-point ranges.
- **TMBO still has almost all of it** (state machine, island movement, drawbridge / gates, transition points,
  start-point ranges per state, guard-tower / crane hooks). Online skips it in 3 places:
  1. `func_0017D4D0` (prisonInitAfter) jumps straight to the final state (5 = docked, bridge down, all switches on)
     whenever `net(D_003156C0)+0x1BB4` != 0, which is the net session state, non-zero in any online / LAN game.
  2. `func_0017DB90` (state 0) forces the timer to 0xE11 when `D_00317274` != 0 (the net-game flag), so the ship
     would leave on frame 1 anyway.
  3. TMBO's SetAICar (`func_0013A9E0`) lost retail's "Prison: disable AI >= 2 until the ship leaves / AI >= 4
     until it docks" block. `func_0017DFE8` (state 2) lost the "AI count == 4 -> SetAICar(4..9)" branch.
- Node id 6050 (0x17A2) has nothing to do with this. Retail `DoEffect__12Destructible` sends 0x17A0-0x17A2 to the
  generic "AC-unit" destructible (BlowDebris; on PRISON it calls `setACUnitDestroyed__16PrisonLevelSound`). It is
  cosmetic. Its 2 missing nodes are 2 breakable props.

## Retail: the object and its data
- `Prison` instance = game + 0x162EE0 (TMBO game + 0x3E5C0). Level index PRISON = 3 (retail game+0x1B3DB0,
  TMBO game+0x9FCA0).
- Called per level from game.s jump tables: `prisonInitBefore` (0x157A60), `prisonInitAfter` (0x157C58),
  `InitForReplay__6Prison` (0x157B00, restart), `prisonUpdate` (0x1580B8, per frame).
  `prisonAddNode__6PrisoniP9_hierhead` (0x157E80) runs from db.s (`prisonAddNode__7TheGame`).
- Level nodes that drive it (`prisonAddNode`). Check these against the online PRISON.NGP. The survey reported only
  6050 as missing, so they should all be present.
  | id | hex | stored | use |
  |---|---|---|---|
  | 10200 | 0x27D8 | +0x00 | **island translate node**: float +0x14 = offset, set to 6000 on load |
  | 10201-10202 | 0x27D9/DA | Blimp EP nodes | `AddEpNode__5Blimp` |
  | 10014, 10016 | 0x271E/0x2720 | heli EP | `AddHeliEpNode__11Helicopters` |
  | 10208 | 0x27E0 | +0x04 switch | on at dock |
  | 10213 | 0x27E5 | +0x08 switch | on at dock |
  | 10214 | 0x27E6 | +0x110 table (by node bits) | switches, start off |
  | 10215 | 0x27E7 | +0x0C switch | first-room door A (on when its anim stops) |
  | 10216 | 0x27E8 | +0x10 switch | first-room door B |
- Animations from model 0x1450 (`animationGetHandle(h, 0x1450, 0, n)`): +0x14 = n1 (departure / doors),
  +0x20 = 3, +0x2C = 4, +0x38 = 5, +0x44 = 6, +0x50 = 7, +0x5C = 8 (drawbridge / side gates), +0x68 = 9,
  +0x74 = 10, +0x80..+0xBC = 11..16 (6 inner-door anims), +0xC8 = 20.
- Fields: +0xF8 state, +0xFC island speed (starts at 1.333), +0x100 timer in fields, +0xD4 ElectrocutionPeds,
  +0x11C PrisonLevelSound (TMBO +0x120).
- Start points: the level's AttractorPoints start-point list (game+0x155290; TMBO game+0x30970), in index order.
  On PRISON, `attractGetStartPoint__15AttractorPoints` (retail 0x109430, TMBO func_0010BE18) picks from a range
  that depends on the state:
  - mode 0 (attract/demo): points 0-3
  - state 0: points **0-1 (on the ship)**
  - state 1-2: points 2-3
  - state >= 3: points 4 .. last
  Humans use the same ranges: `gameGetStartPoint` (0x133ED8, TMBO func_0013D7B8 with idx -1) bypasses
  "closest point" on level 3. AI uses `aiSetToStartPoint` (0x100268, TMBO func_001002C0).
- Game mode game+0x1AE650 (= shell+0x18000+0x235C; TMBO game+0x9A3D0). From uiGameModes_1P / _MP:
  1 story, 2 challenge, 3 endurance (likely), 4/6/7 multiplayer types, 9 boot, 0 attract/demo.

## Retail: the sequence (prisonUpdate jump table on +0xF8)
0. **InnerDoorsClosed** (`prisonUpdateInnerDoorsClosed`, 0x158228). Player (+ AI 0,1) on the ship, inner doors shut,
   bow-wave particles running (`prisonUpdateBowWaves`, so the moored ship looks under way). Timer += fields.
   - Story (mode 1-4) holds until timer > 0xE10 = 3600 fields (about 60 s). Mode 0 or >4 leaves at once; mode 2
     can leave early when game+0x1B3DC4 == 0.
   - Debug skip: inputGetInput 0x4000+0x1000+0x2000+0x8000+0x100 held, none of 0x400/0x800/0x200 -> timer = 0xE10.
   - Leaving: start anim +0x14 and the 6 inner-door anims, state = 1. In a non-attract mode,
     `SetAICar(game, 2, ..)` and `SetAICar(game, 3, ..)`: this re-inits AI 2/3 (aiInit -> type 2, placed at start
     points 2-3). Then **AI count game+0x1B3DC0 = 4** (3 if AI 3 is missing), which hides AI 4+ from the AI loop.
     Then `prisonUpdateTransitionPoints`, which rewires the attractor-point links so AI can path off the ship.
1. **DrawBridgeClosed** (0x158438). `prisonUpdateIslandTrans` moves the island: offset -= speed every frame.
   The speed eases from 1.333 toward 0.667 below 2000 (bow waves killed), then toward 0.05 below 100
   (`smoothEasyIn`). Below 3000: start anims +0x20/+0x50/+0x5C (drawbridge), game+0x1AAB14 = 1 (Blimp+4: blimp
   active), state = 2. The first-room door switches (+0xC/+0x10) turn on when their node's destroyed byte is clear
   and anim +0x14 has stopped.
   Rough timing: about 4000 units at about 80 u/s, then about 2000 at about 40 u/s, so about 100 s to dock.
2. **DrawBridgeOpen** (0x158688). When the offset reaches <= 0: offset = 0, state = 3,
   `prisonShipHasDocked__12HealthStands` (health stands go live), side-gate anims +0x2C/+0x38/+0x44, switch +0x4 on,
   TransitionPoints. Then **AI wave 3**: if the AI count == 4, `SetAICar(4..9)` (stops at the first empty slot)
   and count = n. Otherwise `vehicleEnable(v, 2)` for 4..count-1. Switch +0x8 on. Pauses anims +0x50/+0x5C when
   +0x20 ends.
3. **GatesOpenBridgeUp** (0x1588C8). Side-gate sound. Once: if game+0x19E0C0 is set, clear it and
   `hidePickupsOutsideOfBoat__7Pickups(pickups, 1)` (pickups off the boat appear; prisonInitAfter hid them with 0).
4. Set by `prisonGuardTowerDestroyed` (0x158F90, from destruct.s): reverse +0x20, start +0x50/+0x5C, state 4.
   **GatesOpenBridgeMovingDown** (0x158908): when +0x20 stops, start +0x68/+0x74/+0xC8, state = 5,
   TransitionPoints.
5. **GatesOpenBridgeDown**: folding-ramp sound only.
- Every frame: `prisonUpdateCraneDestruct`, `update__17ElectrocutionPeds`, `update__9CarUnlock`
  (`s_prisonCarUnlock`; `unlockCar__6Prison` is fired from destruct.s for the level-3 secret).

### Who disables the AI at the start: retail `SetAICar__7TheGameiii` (0x131360)
After aiInit, if mode != 0: `driverSetPlayerToHunt`. Then if level == 3 and aiIdx >= 2: if prison state == 0,
`vehicleDisable`. If aiIdx >= 4 and state < 3, `vehicleDisable`. `InitPlayers__5Shell` calls SetAICar for every
story AI (Prison Passage: 8), so in story AI 2-7 start disabled and hidden (vehicle +0x580 = 0). AI 0-1 ride the
ship. Waves: AI 2-3 when the ship leaves, AI 4-7 at the dock.

## TMBO: what survives (mapping.csv + asm)
| retail | TMBO | status |
|---|---|---|
| prisonUpdate | func_0017DA58 | same table; no ElectrocutionPeds update, no PedElectrocution sound |
| InnerDoorsClosed | func_0017DB90 | `D_00317274` forces timer 0xE11; wait only if mode != 0; SetAICar(2,3) kept; **AI count not set to 4** |
| DrawBridgeClosed | func_0017DD58 | kept (writes game+0x96814 = 1) |
| IslandTrans | prisonUpdateIslandTrans__6Prison | kept |
| DrawBridgeOpen | func_0017DFE8 | kept except **SetAICar(4..9) branch** and HealthStands; vehicleEnable loop runs if count > 4 |
| GatesOpenBridgeUp | func_0017E1A8 | no pickup reveal; adds an online-only call func_00129A70 while the gate anim runs and the net session is on |
| MovingDown / Down / TransitionPoints / GuardTower / Crane | func_0017E218 / prisonUpdate... / func_0017E898 / func_0017E928 | kept, still called from destruct.s |
| InitForReplay | InitForReplay__6Prison | resets state 0 / timer 0 / offset 6000; bow-wave particles only if `D_00317274` == 0 |
| prisonInitAfter | func_0017D4D0 | **net+0x1BB4 != 0: jump to state 5** (offset 0, +0x96814 = 1, anims, all 4 switches on); also anim 0x27E2 + net cfg bit |
| attractGetStartPoint | func_0010BE18 | prison ranges kept (level game+0x9FCA0, mode game+0x9A3D0) |
| aiSetToStartPoint / gameGetStartPoint | func_001002C0 / func_0013D7B8 | kept |
| SetAICar | func_0013A9E0 | **prison disable block and hunt-player removed**; stride 0x31B0, car ids at +0x20F4/+0x20F0 |
| hidePickupsOutsideOfBoat, HealthStands::*, ElectrocutionPeds update/initAfter | - | removed / orphaned (func_0017EC18 and func_0017F0F8 exist but nothing calls them) |
- TMBO globals: game `D_004FA030`; AI list game+0x9E690 + 4*i; AI count game+0x9FEE4 (bots.c `NAI`); vehicle
  type +0x590 (retail +0x580); net `D_003156C0`.
- Side notes:
  - NEXT_traffic_ai.md calls game+0x9FCA0 the "game type". It is the **level index** (compared with 3 = PRISON and
    0x15 here; 2 = Freeway, which has the TrafficDirector).
  - mapping.csv rows that look wrong (low score, far-away addresses): prisonInitBefore -> 0x127118,
    unlockCar -> 0x24FC88, cleanupOnShutdown -> 0x299350, ElectrocutionPeds::cleanup -> 0x1A6C18.

## Restore plan (story mode, solo / local guests; host runs it)
All hooks are 1:1 `jal` swaps in tools/mods/apply_mods.py, like the existing ones. Gate everything on
`tmbr_StoryOn() && F(game,0x9FCA0) == 3`. Otherwise call the original.

1. **Init**: swap `jal func_0017D4D0` at **0x001386C8** (func_00138358) for `tmbr_PrisonInitAfter(p)`. In story,
   save `net+0x1BB4` and `D_00317274`, set both to 0, call `func_0017D4D0(p)`, then restore both. Result: retail
   init (state 0, offset 6000, doors shut, bow waves created). Also set `p->stage = 0` (our own state).
2. **Ship phase**: swap `jal func_0017DB90` at **0x0017DAFC** for `tmbr_PrisonShip(p)`. In story:
   - Every frame: for AI i in 2..NAI-1, if `veh+0x590 != 0`, call `vehicleDisable(veh)` (catches bots that spawn late).
     Optionally re-place humans: `func_0013D7B8(game, veh, -1)` once, so they land on points 0-1.
   - `F(p,0x100) += timerGetFieldsLastFrame()`; while <= 3600, return. The bow waves still run (0x0017DB04).
   - Then do the departure in C, not through func_0017DB90, so TMBO's SetAICar never touches net bots:
     `animationStart(p+0x14,1)`, `animationStart(p+0x80+0xC*k,1)` for k = 0..5, `F(p,0xF8) = 1`, then for AI 2-3
     `place(veh, 2..3)` + `vehicleEnable(veh,2)`, then `prisonUpdateTransitionPoints__6Prison(p)`.
     `place` = `idx = func_0010BFD8(points, lo, hi)` (attractGetStartPointInRange) + `func_0013D7B8(game, veh, idx)`.
     Passing an explicit index skips the mode-dependent range. Then aiInit / driver re-init as needed: compare
     with what func_001002C0 does after placing.
3. **Dock**: swap `jal func_0017DFE8` at **0x0017DB24** for `tmbr_PrisonBridge(p)`. In story, save NAI, set it to 4
   (skips TMBO's bare vehicleEnable loop), call the original, restore NAI. If the state is now 3: for AI 4..NAI-1,
   `place(veh, 4, nStart-1)` + `vehicleEnable(veh, 2)`.
4. Restart (InitForReplay via func_00138888 0x00138AF4) already resets to state 0. Hook it too, to re-run the
   disables and clear `D_00317274` around the call.
5. Later / optional: pickups hidden until the dock (re-implement hidePickupsOutsideOfBoat with TMBO's
   `attractGetGroupTestPointIsIn` 0x10B758 + Pickups layout), ElectrocutionPeds (call func_0017F0F8 from init and
   func_0017EC18 from update once the ped packs are in), health stands (absent in TMBO), the debug skip combo.

## Risks / checks
- **Check first** (one test log): in story on PRISON, print state, offset, NAI, `game+0x9A3D0` (mode), each
  vehicle's +0x214C start index and +0x590 type at frame 1. If the mode is 0, `attractGetStartPoint` uses 0-3 in
  every state, which is why the plan places vehicles with explicit indices.
- Net bots (bots.c gameMakeAI / net objects): disabling them on the host may confuse clients or the "cars left"
  HUD / LMS win check (a disabled bot must not count as dead and must not end the round early). Test with teams.c
  winner logic, and check `tmbr_HudCarsLeft`.
- More than 2 humans: the ship has only points 0-1. `gameCheckStartPoint` may push a 3rd car elsewhere, maybe onto
  the island. Fine for solo + 1 guest. With more, check the PTS start list.
- Clearing `D_00317274` during InitForReplay: if it stays non-zero, the bow-wave handle `D_004FB4FC` stays 0 (sbss),
  not -1, and BowWaves writes through `D_004FB504/508` + 0x2D88. Clearing the flag (or setting the handle to -1) is
  required.
- Clearing net+0x1BB4 inside func_0017D4D0: it only reads the field. Make sure nothing in it calls net code. From
  the asm: animationGetHandle / Start, hierSetSwitch, InitForReplay, sound init only.
- Island geometry moves under hd collision. Retail does the same; players are on the ship, which does not move.
- Online co-op later: the state machine runs on every console (timer from load). Remote clients would need the
  state synced (TMBO's func_00129A70 at the dock may be a hint).
- The pacing is long: about 60 s hold + about 100 s approach. Retail is the same. A shorter hold is an easy option.
