# Story bosses: retail vs TMBO (research, 2026-10-26)

Read-only research for STORY_PLAN phase 4. Retail addresses are from /home/claude/retail/asm (symbols). TMBO addresses are from
/home/claude/tmbo/asm. Retail `game+0x1A8000+0x6650` is the game type (shell +0x235C: 1 = story, 4 = the second story type
(it plays movie 0x88 instead), 2 = another mode). Retail `D_001B3DB0` is the level index.

## 1. How retail runs Warhawk's Roof (level 20)

### Creation (no boss-specific spawn: two ordinary AI cars plus a FinalBoss object)
- **Car files.** `LoadCarsDB__5Shell` (0x162040): AI cars come from shell +0x19DB4. In game types 1 and 4 on level 0x14 the
  AI count is forced to 2. Each AI car loads `carName[car>>5]` with type 2 (ACAR), allowed for index < 0x12, so `b2`/`b3`
  (B2A.*, B3A.*) load. Player cars only allow index < 0x10.
- **Vehicles.** The hier parse `VehicleParse__7TheGame` (0x130BC0) handles a node with id (word>>18) == 0x200 in two ways:
  `FinalBoss::AddEpNode` stores that hierhead at FinalBoss +0x9C, and `AddVehicle` still creates a vehicle named 0x200. The
  vehicle's name (retail +0x20A8, TMBO +0x20F4) is the id of the node in the car file, not the shell car value.
- **AI.** `InitPlayers__5Shell` calls `SetAICar__7TheGameiii(game, aiIdx, carValue, dupId)` (0x131360) for each AI car value.
  SetAICar finds the vehicle whose **name == carValue and dup == dupId** and makes it an AI.
- **The FinalBoss object** is at game+0x1AB420. Retail wires it only for level 20 in game types 1 and 4:
  - `InitBeforeDbLoad` (level jump table jtbl_004E5310, entry 20 -> 0x12F140) calls `InitBossBefore__9FinalBoss` (0x10F1C0)
    and then `forceFieldInitBefore`. InitBossBefore sets +0x4 = 1, state +0x10 = 2, health +0x18/+0x1C =
    BLACK_RAZOR_INITIAL_HEALTH and `firstField = 1`, and zeroes +0x9C/+0xE0.
  - `InitAfterDbLoad` calls `InitBossAfter__9FinalBoss` (0x10F288). It does these steps in order:
    - Calls `GetVehicleFromName(game, 0x200, 0)` and dereferences the result **without a null check**.
    - Sets 8 hard-coded attract points at +0x100..+0x280.
    - Calls `csCreate` and sets the cs model to the hier at +0x9C (the 0x200 node).
    - Calls `Interactives::Add` with type 0xC (this is how hits reach the boss).
    - Creates the boss point light.
    - Calls `forceFieldCreate` around the boss, then sets force-field state 2 (the shield).
    - Sets more points at +0x710..+0x790.
    - Calls `RegisterFodderLock`.
    - Sets vehicle 0x200 health (+0x3F0/+0x3F4) to BLACK_RAZOR_INITIAL_HEALTH, doubled in game type 4.
    - Initialises the FinalBossSound and HelicopterSound objects.
    - Sets `difficulty` from game +0x6654.
    - Gets animation handles (bank 0x206).
  - `Update__7TheGame` (when enableAI is set) sets a game flag (`UpdatePlasmaBallTrans+0x30` slot = 1), then calls
    `UpdateBoss__9FinalBoss` (0x10F7C0) and then `forceFieldUpdate`.
- **ROOFBOSS EP nodes.** No level-specific EP nodes. `attractiInitRoofbossGroups` is an empty stub. The boss path uses the
  points hard-coded in InitBossAfter. The only "EP node" is the 0x200 hier node from the boss car file.

### The two boss cars
- **0x200 (b2, "Black Razor" health):** a vehicle whose health mirrors the boss health. TakeHit writes it and calls
  `Destructible::VehicleTakeHit` on it. The visible boss is the FinalBoss cs (a helicopter: HelicopterSound, machine guns,
  "rico" launcher, rammer, creaky sounds, radar blip 0x200). Whether the 0x200 car body is ever drawn or driven is unverified.
- **0x220 (b3, the tanker):** on the first UpdateBoss pass (`firstField`), UpdateBoss gets vehicle 0x220 and calls
  `aiInit`, `aiSetAggressiveness(100)`, `vehicleEnable(2)`, `driverSetDrivingMode(5)` and plays the tanker horn.
  - Vehicle code special-cases 0x220:
    - `vehicleTakeHit` -> `tankerTakeHit__7Vehiclei` (0x1ADF68). This is the explosion: it calls
      `DispatchHit(interactives, pos, **0x29A**, ...)`.
    - `vehicleUpdateDeathSequence` -> `tankerUpdateDeathSequence` (0x1AEB..). The tanker respawns and is re-made an AI with
      the same four calls plus the horn.
    - `UpdateLauncher` -> `UpdateTanker` (a torch turret aimed at the closest car).

### Fight flow and win condition (`TakeHit__9FinalBoss`, 0x111A70)
- **Phase 1, shield.** While the shield hit count (+0x3C) is below 3, only damage values 0x29A (a tanker explosion) or 0x3E8
  count:
  - 1st hit: force field state 4.
  - 2nd hit: state 7, HUD message 0xDB, damaged-shield sound.
  - 3rd hit: state 3, message 0xDC, kill-shield sound, +0x10 = 3, a new strafingSpeed.
  - Any other hit only calls `forceFieldTakeHit` (bounce plus sound).

  So the player must shoot or blow up the tanker while it is next to the boss, three times.
- **Phase 2.** Every hit lowers health +0x1C and is mirrored into vehicle 0x200. At 0: +0x20 = 1 (UpdateDeath runs for 0x78
  frames), the helicopter sound stops, and `rtReturnToShell(0, 0xF0)` is called, i.e. a win after a 240-frame delay. The shell
  then sets +0x2308 (roof won), which leads to the ending movies (STORY_MOVIES.md).
- UpdateBoss is a state machine on +0x10 (patrol, strafe, ram, hover; attract points via GetNextAttractPt or
  GetClosestPlayer). It calls `RegenBoss` and `CheckCollision`, and fires with `CreateStaticWeapon` when FIRE_WEAPONS is set.

### Other story "bosses"
- **Minion's Stadium (14):** retail does more than make Minion an AI car.
  - `vehicleInitDynamics`: an AI-driven Minion (+0x580 != 1) on level 0xE gets special dynamics and a **force field**
    (`forceFieldCreate`, state 2).
  - `vehicleTakeHit` -> `minionTakeHit__7Vehiclei` (0x1AD9A0) for an AI Minion on level 0xE (the shield phases).
  - Level 14 InitBefore (game types 1, 2, 4) calls `forceFieldInitBefore`, and Update calls `forceFieldUpdate`.
- **Prison Ship (15):** `prisonShipInitBefore/InitAfter/Update` hold level props only, no boss.
- **Prison Passage (3):** in non-zero game types, the inner-doors and drawbridge updates call `SetAICar` on the caged cars at
  game +UpdateTranslation+0x310/0x314. These are prisoners released mid-level, not a boss.

## 2. Why TMBO's gameMakeAI gives Roadkill, and what else rejects the boss

- **`gameMakeAI` = func_0013A7B8 is TMBO's rewrite of `SetAICar`.** It sits between AddFodder and InitializeFodderCars in
  both binaries. Its first instruction is `daddu $a2,$a1,$zero`, which **throws away the car value**. The loop then matches
  only vehicle **+0x20F0 == a3**. +0x20F0 is set by `AddVehicle` (0x13A240) to the load index (func_00127AF8()-1), not to a
  name. So the car value passed by bots.c does nothing: the bot is whatever model was loaded into that slot's vehicle, and
  +0x20F4 is that model's hier node id.
- **What loads into a slot.** The level load func_00188248 copies D_00313F00[slot] to D_003F6E08 and loads each slot's car
  through func_00189268. The host's reload is func_0016FE70 -> func_0018A930 when vehicle +0x20F4 != slot +0xB4. The host
  packs slot +0xB4 >> 5 into bytes; netMsgSessionHandler unpacks byte << 5 into D_00313F00. The ACAR table D_003F6A00
  allows index < 0x12. **No clamp turns 16/17 into 1 anywhere on this path.**
  - The only `& 0x1E0` clamp (car field >> 17 & 0x1E0) is the one-car-for-everyone option (func_00187CA8, ui.s 0x1C8450,
    func_001B2B68). That clamp would give 0x200 -> 0, not 0x20.
- **So the Roadkill in test g116 is not explained by code read here.** Candidates, cheapest check first:
  - (a) TMBO's B2A/B3A hier node id is not 0x200/0x220.
  - (b) The B2/B3 load never happened for that slot.
  - (c) gameMakeAI picked another vehicle with the same +0x20F0.

  The game's own log settles it:
  - `SHELL: Loading Vehicle %s into slot %d` (D_004EA510, printed by func_00189268) must show `b2`/`b3`.
  - `GAME: Added vehicle #%d %s ...` (AddVehicle) shows the id.
  - In-game, check `GetVehicleFromName(g, 0x200, 0)` != 0 and `F(g+0x97120, 0x9C)` != 0.
- **Other things in TMBO that drop the boss (dead or unwired code):**
  - TMBO never calls InitBossBefore (func_00111E48), InitBossAfter (func_00111ED8), UpdateBoss (func_001123C0),
    forceFieldInitBefore (0x1360D8) or forceFieldUpdate (0x136508). The level switch cases are gone.
  - Only VehicleParse -> AddEpNode survives. TMBO's FinalBoss is at **game+0x97120**.
  - `tankerTakeHit` (func_001E3188) has no caller. TMBO's vehicle hit code (likely func_001E1C40) lost the 0x220 branch.
  - `tankerUpdateDeathSequence` is gone, so the tanker would not respawn as a boss AI.
  - `minionTakeHit` (func_001E2A00) has no caller, and the Minion force-field setup is gone.
  - Still present: TakeHit (func_00114B78, still reached through interactive dispatch func_0014F108 for type 0xC),
    UpdateTanker (called from UpdateLauncher), CheckCollision, RegenBoss (func_00114FE0), the 0x220 checks in ai func_001002C0,
    game func_0013D0C0 and launch, and the FinalBossSound and HelicopterSound functions.
- **TMBO InitBossAfter differences:**
  - Health goes to vehicle +0x400/+0x404, and the destructible at +0x2084.
  - There is no game-type-4 doubling.
  - Difficulty comes from game+0x98000+0x23D4.
  - HUD messages use `AddMessage__3Hudiii` 0xC7/0xC8.
  - TakeHit still ends with `rtReturnToShell(0, 0xF0)` at **0x114D5C**.

## 3. Mod plan (story run, level 20, host)

1. **Cars.** Keep story.c giving two free slots 0x200 and 0x220, and make the level load put those values in D_00313F00
   (as guests.c does). First confirm with the logs above that vehicles named 0x200 and 0x220 exist. If the model ids are
   wrong, nothing below works; stop and inspect B2A/B3A.
2. **Init after the level loads** (level 20, story on, both vehicles found, FinalBoss +0x9C != 0, once per level serial):
   1. Save +0x9C.
   2. Call `func_00111E48(g+0x97120)` (InitBossBefore).
   3. Restore +0x9C (InitBossBefore zeroes it; retail runs it before the db load).
   4. Call `func_001360D8()` (forceFieldInitBefore).
   5. Call `func_00111ED8(g+0x97120)` (InitBossAfter).

   Never call step 5 with vehicle 0x200 missing (null dereference).
3. **Every frame** (level 20, not paused): call `func_001123C0(g+0x97120)` (UpdateBoss), then `func_00136508()`
   (forceFieldUpdate). Find TMBO's equivalent of the game flag retail sets first (`UpdatePlasmaBallTrans+0x30`).
4. **Tanker:**
   - Hook the vehicle hit path (func_001E1C40, or its caller): when +0x20F4 == 0x220, call `func_001E3188(v, dmg)`.
   - Re-do the tanker AI on respawn: aiInit, aiSetAggressiveness 100, vehicleEnable 2, driverSetDrivingMode 5, which is
     retail's tankerUpdateDeathSequence.
5. **Win:** patch the jal at 0x114D5C (rtReturnToShell) to a mod stub that marks the stage won through
   story.c/teams.c. UpdateDeath still plays.
6. **bots.c/teams.c:**
   - Keep 0x200 and 0x220 out of bot personality, nav, specials and the "bots' team is out" check (the win comes from step 5).
   - Do not let the bot spawner hand these slots normal cars.
7. **Optional Minion (14):** for an AI Minion, call forceFieldInitBefore + forceFieldCreate/SetState(2) as in retail
   vehicleInitDynamics, call forceFieldUpdate per frame, and route its hits to `func_001E2A00`.

## Risks
- **Online sync.** The boss is mostly local simulation: the FinalBoss cs, force field and mathfRand states are not networked.
  Clients either see nothing or desync. Start with host-only, single-console runs (host plus split-screen guests).
- **The unexplained Roadkill model id (section 2).** This blocks everything else until the logs settle it.
- **Missing assets.** Sounds (FinalBoss sound banks, retail STGAME.BNK) and animation bank 0x206 may be missing on the TMBO
  disc. That could mean silence, or a crash if a handle stays null.
- **Function mappings are fuzzy.** InitBossBefore/After and RegenBoss were identified from their call patterns, not symbols.
  vehicleTakeHit = func_001E1C40 is a guess.
- **Address-space overlap.** The FinalBoss interactive (type 0xC) and RegisterFodderLock (TMBO func_0013D788) may clash with
  the mod's traffic/fodder code.
