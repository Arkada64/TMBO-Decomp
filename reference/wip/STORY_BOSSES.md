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
  - Details and the mod's port: section "Minion's Stadium (level 14)" at the end.
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
  - `minionTakeHit` (func_001E2A00) has no caller, and the Minion force-field setup is gone (ported 2026-10-26, see the
    Minion section).
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

## Status 2026-10-26 (tests g120-g129, parked for the Lost maps)
- Boss cars load: story.c writes the slot cars into D_00313F00 before the level load (guests.c tmbr_LevelLoadCars);
  vehicles 0x200 / 0x220 exist (bots slots 1 / 2). B2A/B3A come from \ACAR (type 2), no PCAR copies needed.
- GetVehicleFromName(g, name, dup) matches +0x20F0 == dup (TMBO's load index), so retail's (0x200, 0) lookups fail:
  the five boss-code calls are hooked to tmbr_BossVehName (by name only).
- Init hook: InitAfterDbLoad's common tail 0x1387FC (plightActivate) -> tmbr_LevelInitAfter.
- Crash: calling InitBossAfter (func_00111ED8) -> EE runs data at 0x33e498 (vehicle 0 + 0x2038), "Unknown R5900
  SPECIAL", TLB store 0x1003b, same frame. BOSSSTEP 0-2 (no InitBossAfter) never crash (only the HUD's null boss cs
  TLBs at 0x14AC64 / 0x14B778). A trampoline on InitBossAfter's first call (0x11206C, tmbr_BT0) never printed, and
  nothing between its entry and that call jumps - unexplained. Next: check that 0x111ED8 in the built ELF really is
  this code (shift build?), single-step with PCSX2's debugger, or call the pieces (csCreate func_00213F80 etc.) from C.

## Minion's Stadium (level 14): retail's shielded Minion (2026-10-26, not tested yet)

### What retail does (AI Minion = vehicle id 0x1E0 with type +0x580 != 1, level index 0xE)
- **`vehicleInitDynamics`** (0x1A4238, case 0x1E0 at 0x1A6DA8). It runs from `vehicleInit`, so on every spawn and respawn.
  - Health +0x3F0: 250 for an AI Minion, 150 for a human one.
  - Shield generator hit points +0x3F8..+0x404: 35 / 5 / 25 / 25, or 100 / 75 / 75 / 75 in game type 4.
    Generator models at +0x2058..+0x2064 are switched to 0 (intact).
  - AI branch only, big-car geometry (retail offset = TMBO offset):

    | Retail | TMBO | Value (AI) | Value (human) |
    |---|---|---|---|
    | 0x394 | 0x3A4 | -8.681 | -4.401 |
    | 0x398 / 0x39C / 0x3A0 | 0x3A8 / 0x3AC / 0x3B0 | 18.564 | 9.282 |
    | 0x3A4 | 0x3B4 | 9.66 | 4.7 |
    | 0x3A8 | 0x3B8 | 14.34 | 6.8 |
    | 0x3AC | 0x3BC | -44.818 | -22 |
    | 0x3B0 | 0x3C0 | 28.606 | 14 |
    | 0x3B4 | 0x3C4 | -54.3 | -27 |
    | 0x3B8 | 0x3C8 | 34.468 | 15.79 |
    | 0x3C0 | 0x3D0 | 5.447 | 3.6 |
    | 0x3C4 | 0x3D4 | 7.2 | 2.7 |

    These are ride height, half track and axle positions (skins.c ownWheels), roughly 2x. That is the giant Minion.
  - Then `forceFieldCreate(cs+0x20, cs+0x10, v+0x20A4 (dup), -14.5, 4, 30, 49, 35)` and `forceFieldSetState(2)`.
    - The int argument is the dup that forceFieldCreate passes to `GetVehicleFromName(game, 0x1E0, dup)`.
    - f12/f13 go to the shield model's scale node +0x14/+0x18. f14..f16 are the ellipsoid size.
- **`vehicleTakeHit`** (0x1AD208): after the respawn-shield cut (damage 0) and the AI-vs-AI cut (0 or half), an AI
  Minion on 0xE calls `minionTakeHit(v, damage)`. If it returns non-zero, vehicleTakeHit returns: the hit is skipped.
- **`minionTakeHit`** (0x1AD9A0, TMBO func_001E2A00, same logic):
  - Damage 1000 kills all four generators (state 0).
  - It always calls `forceFieldTakeHit(*(hitinfo+0))` (TMBO func_00136300). The hit info is game+0x150560 in retail and
    game+0x2BC10 in TMBO: +0 is a pointer to the hit position, +8 = 1 for a local hit.
  - A generator (local offsets on the stack table, through the cs matrix) takes the damage when the hit lands within 50
    (manhattan) of it and it still has hit points.
    - At 0: its model switch, `figureOutForceField` (TMBO func_001E4F40: state 4/6/7/3 by the number of dead
      generators), particles, a HUD message and a sound.
    - Otherwise: a "generator hit" message.
  - While any generator is up it returns 1, with the shield-impact sound if +8 == 1.
  - When none is up: `aiSetAggressiveness(100)`, the "shield down" message if one died now, and it returns 0.
  - TMBO's version sends messages through `AddMessage__3Hudiii(game+0x97B50 + v[+0x210C]*0xA20, 0xBD..0xC5, 1, 1)`, the
    car's own screen index.
- **Level 14 InitBefore** (game types 1, 2, 4) = `forceFieldInitBefore`. **Update** (types 1, 2, 4) =
  `forceFieldUpdate`. It also sets the `UpdatePlasmaBallTrans+0x30` game flag, which vehicleUpdatePosition uses to switch
  the car hier switches +0x202C/+0x2030 (lights?). That flag is not ported.

### What TMBO lost
- InitDynamics' 0x1E0 case (func_001D72D8 .L001DAB40) has no AI/level test. Every Minion gets the human values plus 160
  health. The generator hit points are 35 / 5 / 25 / 25 at +0x408..+0x414 (TMBO = retail + 0x10).
- `minionTakeHit` (func_001E2A00) has no caller.
- No level case calls the force field. forceFieldCreate (func_00136100) is intact and tests the **shell** level
  +0x18000+0x23AC == 0xE.

### Mod (story.c, host only, story on, game level 14 (game+0x9FCA0))
- **`tmbr_MinionVehInit`**: aiInit's `jal vehicleInit` at **0x10011C** (new hook). Every AI spawn and respawn passes
  here: gameMakeAI, and the death sequence func_001E3800 -> aiInit. skins.c already owns 0x1D7020 (InitDynamics).
  After vehicleInit, an AI Minion (0x1E0, +0x590 == 2) gets these:
  - Health +0x400 = 250. aiInit then copies it to +0x404 and applies the difficulty scaling.
  - The force field: `func_00136100(cs+0x20, cs+0x10, +0x20F0, ...)` + `forceFieldSetState(2)`. GetVehicleFromName
    inside it is already routed to tmbr_BossVehName, and the right dup makes the normal lookup succeed.
  - The ally bot (teams.c tmbr_IsAlly) gets no field. A second AI Minion does not take it over.
  - `MINION_BIG` (default 0) also writes retail's big-car geometry and calls vehicleRecomputeDeltas. It is off because
    TMBO's Minion model is probably the normal size.
- **`tmbr_VehTakeHit`** now hooks the weapon dispatch **0x14F184** and the network hit events **0x167D38 / 0x167DA0 /
  0x167EC4**, then calls dmgreport.c's `tmbr_TakeHit`.
  - Bug fixed: 0x14F184 had two entries in apply_mods.py (story's and dmgreport's). The later one won, so the Warhawk
    tanker hook never ran.
  - For the shielded Minion, `minionHit` does these steps:
    - Finds the attacker by +0x20FC.
    - Drops teammates' hits to tmbr_TakeHit.
    - Applies the mod's damage cuts: respawn shield byte 0x497 -> 0; the ally bot -> half. The mod already removed
      TMBO's AI-vs-AI cut.
    - Points hit info +0 at the hit position, unless it is a local hit (+8 == 1) with +0 set. Network events leave +0
      stale.
    - Sets the Minion's +0x210C to the attacker's screen (a local player, 0..3) or 0, so the HUD messages land on a
      real HUD.
    - Calls `func_001E2A00`, then restores both.
    - Returns 1 = absorbed: no tmbr_TakeHit, no damage, no damage report.
- **`minionFrame`** (from tmbr_BossFrame, bots.c tmbr_BotsThink, every frame):
  - Calls `forceFieldUpdate` while the field is on.
  - Moves the field to another AI Minion if its car is no longer one. This covers the ally bot's first spawn, before
    teams.c knows it is the ally.
  - Turns the field off (forceFieldInitBefore) when no AI Minion is left.
- **`minionLevelInit`** (from tmbr_LevelInitAfter, 0x1387FC): `forceFieldInitBefore` on level 14.
- Log lines start with `TMBR minion:`. Among them: shield up (spawn / respawn / moved / late) with theBoss
  (D_004FB45C, must be 1), the shield model pointer (D_004FB46C, must be non-zero), state and generators; each
  generator hit; state every 600 frames.

### Risks
- **Shared force-field globals** with Warhawk's roof: theBoss, mat/pos pointers, model switch, state, CLUT, fx
  handles. One level never runs both. Both paths reset on level init (minionLevelInit, and the roof's own
  forceFieldInitBefore).
- **Model.** If TMBO's Minion car file has no shield model at +0x2068, forceFieldCreate clears theBoss. Then there is no
  bubble and no forceFieldUpdate, but the generators still absorb (minionTakeHit only needs the generator switches
  +0x2074..+0x2080, which TMBO's InitDynamics already sets).
- **Clients** run none of it. Hits on the host's bot are applied on the host (dispatch or network event), so health
  stays synced: a client sees a Minion that shrugs off hits until the generators are down. But a client sees no
  bubble, its generator models stay intact, and the HUD messages show on the host's screen 0 only. A client's own
  local hits on the remote Minion still play the normal hit effects.
- **Messages and sounds.** HUD message ids 0xBD..0xC5 and the Minion shield sounds must exist in TMBO's data.
- **Respawn shield.** A hit during the respawn shield does 0 damage to the generators but still shows "generator hit"
  (retail does the same).

### Check in game (story run at Minion's Stadium, host)
1. The log shows `TMBR minion: stadium init`, then `shield up (spawn) ... boss 1 model <non-zero> state 2,
   generators 35 5 25 25, health 250`.
2. A bubble with electric arcs is drawn around Minion and follows him.
3. Shots near a generator log `hit ... generators ...` with the numbers going down. HUD messages appear and his health
   does not drop.
4. After the four generators are down: the "shield down" message, `through` in the log, and normal damage.
5. Kill him: on respawn the log shows `shield up (respawn)` with full generators.
6. With ALLY BOT on: the ally Minion has no bubble (`ally bot, no shield` or `moved`).
7. On other levels: no `TMBR minion` lines.
8. Warhawk tanker hook: `tmbr_VehTakeHit` now really runs, which matters for ROOF_BOSS builds.
