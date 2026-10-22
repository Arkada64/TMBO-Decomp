# How the TMB:O bot AI works (from the decompiled code)

Readable C for every AI, driver and game-manager function is in `reference/ai_decomp/` (m2c drafts with named
structs, regenerate with `reference/ai_decomp/run_m2c.py`). Field names are ours; "sure" in `fields.py` means
confirmed by code or logs, the rest are educated guesses. Addresses are SCUS-97196 (online).

## Objects
| Thing | Where | Notes |
|---|---|---|
| `TheGame` | `*D_004FA030` | `vehicles[8]` (0x31B0 each) at +0, `brains[8]` +0x23000, `drivers[8]` +0x26180 (per vehicle index) |
| `Vehicle` | `game->vehicles[i]` | `kind` (+0x590): 1 human, 2 bot, 3 traffic. `brain` +0x2014, `driver` +0x2018, `aiOrPlayerIdx` +0x2100 |
| `AIBrain` | `v->brain` (0x630) | perception (`targetDist/Bearing/Facing`), attack state machine, timers, weapon choice |
| `Driver` | `v->driver` (0x2C0) | `mode`, `target` (+0xB4), waypoint graph `points` (AttractorPoints), current `group`, how it drives |
| AI list | `game->ais[]` +0x9E690 | 2 entries online (bots mod: 6), `numAIs` +0x9FEE4 |
| Humans | `game->humans[8]` +0x9E670, `humanGroup[8]` +0x9FD40 | attractor group each human is in (updated per frame) |

## One frame
1. **Manager** `func_0013BEA0` (host only, runs once per frame):
   - Hands the **think token** (`brain->thinkToken`) to ONE bot (round robin `game->thinkRR`). Only that bot gets
     its **perception refresh** this frame: `func_00104FA0` (distance/bearing/facing to `driver->target`,
     attractor group, LOS test `aiToPlayerLOSCheck`). With N bots each one sees the world every N frames.
   - Computes `distNearestHuman`; sets `nearHuman` when a human is within 1500 and visible (pickups only
     happen when `nearHuman` is set).
   - Sorts bots by threat (`brain->threat` = health x aggression), writes `brain->sortIndex`.
   - **Hunter assignment** (only when `game->singlePlayer` +0x9A3D0 is set, i.e. the retail single-player flag):
     `func_0013BC98` / `gameCheckNewAIToHuntPlayer` / `func_0013C568` pick ONE bot to hunt each human
     (`game->hunterOf[human]`), the others cruise. Whether online sets this flag is not verified yet (log it):
     if it is 0, the online bots keep whatever mode they were given.
2. **Per bot** `vehicleUpdate` -> `func_00101F88` (the AI frame; only for `netRole == 4`, the host's bots):
   - `func_001054E8`: **mode logic** by `driver->mode`:
     | mode | function | what it does |
     |---|---|---|
     | 0 | - | idle: the bot does not drive at all |
     | 2 | `aiUpdateBait(Old)Mode` | bait / attack whatever is in front, then pick a new cruise point |
     | 3 | `aiUpdateFleeMode` | flee to a flee spot when weak (`healthScore < fleeHealth`) |
     | 4 | `func_001082C8` | cruise between cruise zones; in single player can switch to hunt/bait/flee |
     | 5 | `func_00108618` | **hunt** `driver->target`: bead-on-target when reachable, snipe otherwise; flees when weak |
   - `aiUpdateAttack`: **attack state machine** (`brain->attackState`, timer `brain->stateTimer`
     +0x488, reset on every state change by `aiSetAttackState`):
     | state | function | |
     |---|---|---|
     | 1 | `func_00106370` | choose a weapon (random from the bot's weapon table, `aiGoodWeaponToPick`; forced weapon from the lobby setting if any); tops that weapon's ammo up to >= 1 |
     | 2 | `func_00106888` | switch to it (weapon next/prev pad bits) |
     | 3 | `func_00106A00` | wait until `stateTimer > brain+0x584` (quarter when <= 1 bot alive) |
     | 4 | `func_00106A60` | wait until in weapon range (`aiInWeaponRange`), give up after 301 ticks |
     | 5 | `func_00106AC8` | in range and LOS ok (`noLosTicks < 10`) or a non-LOS weapon -> 6 |
     | 6 | `aiLineUpShot` | needs `brain->aimed` (target within 35 deg, refreshed only with the think token), then the **fairness gate** `aiIsPlayerLookingAtAIEnoughForAIToShoot`, then bearing/pitch/range per weapon (`func_00106D50`, gate again) -> 7; gives up after 301 ticks |
     | 7 | `func_00107380` | fire (pad fire bit), specials via `specialActive` |
     | 8 | `func_001076E8` | special-weapon handling / cool-down (`specialInterval` x difficulty factor 4/2/1) |
     - `brain->okToAttack` is only ever set when `game->difficulty` (+0x9A3D4) > 0. **Online runs at 0** ->
       bots never get past the attack setup with normal weapons; specials take another path.
   - Driving: `aiOkToHuntUsingLOS` -> `aiHuntUsingLOS` (drive straight at the target with LOS steering) when
     the target's attractor group is visible from ours, else `func_0012E798` (driver update) follows the
     waypoint graph: `func_00102D78` (follow points), `aiPerform` (attack driving), `aiTurn`.
     Both read the target's group as `game->humanGroup[target->aiOrPlayerIdx]`: **only valid for humans**.
   - Stuck handling: `framesSinceX` (+0x444) >= 60 -> reverse/turn pad bits.
3. Damage (`func_001E1C40`): bot -> bot damage is **zeroed** (0.5x if `brain+0x598` set); human damage from
   bots shrinks when the human took a lot recently (`recentDamage` +0x43C).

## Why bot-vs-bot fails in the original code (what the mod has bypassed so far)
| Problem | Cause | Mod status |
|---|---|---|
| Bots only hunt humans | mode 5 target = nearest **net player** (`func_00130E88`) | replaced: `tmbr_BotsThink` picks nearest live car |
| Dogpile on the host | new bots are aimed at `vehicles[0]` | same |
| No damage to each other | `func_001E1C40` zeroes bot->bot damage | patched (full damage) |
| No normal shots at all | `difficulty` 0 online -> `okToAttack` never set | lobby difficulty (R3+L2/R2) |
| Shots stop once circling | fairness gate wants the TARGET to face the bot | skipped for bot targets |
| Wrong routes to bot targets | `humanGroup[aiOrPlayerIdx]` is a human's group | `tmbr_AiUpdate` swaps in the bot's group for its AI frame (was only around `func_0012E798`) |
| Bots sit still / slow to shoot | the mod's "special slowdown" ran `stateTimer` (+0x488) at 40%: that is the timer of EVERY attack state, not just specials | removed; specials now limited at weapon choice (`tmbr_AiGoodWeapon`, 35% chance) |

The last two rows are in commit "Bots: AI frame hook ..." (untested, needs a build on Ark's PC).

## What a real rework should look like
1. **Own targeting layer** (done in a basic form): any car can be a target; score by distance, health, who hit
   me last, line of sight; per-bot stickiness. Keep it host-side (bots are synced as normal net vehicles).
2. **Per-vehicle group table** instead of `humanGroup[]`: the bots' targets need their own attractor group.
   The clean fix is replacing the ~6 reads of `0x9FD40 + idx*4` with a lookup by vehicle index
   (`groupOf[vehicleIdx]`, updated for all 8 cars), rather than swapping values around the AI frame.
3. **Perception rate**: one bot per frame gets LOS/geometry. With 6 bots that is every 6th frame (~10 Hz);
   fine, but `aimed`/`seesTarget` are sticky between refreshes, which makes aiming jumpy. Option: refresh
   geometry (cheap) every frame, keep the LOS test round-robin.
4. **Weapon/special balance**: weapon table per character is `brain+0x320` (front) / `+0x3AC` (rear);
   special cadence = `specialInterval` x difficulty factor; tune per difficulty instead of global hacks.
5. **Movement**: everything routes through AttractorPoints groups (`driver->points`, `group`). A navmesh would
   replace `driverGetNextPoint` / `driverGetNewPointInFrontOfVehicle` / `attractGetGroupTestPointIsIn` users
   inside `driver.c`; `aiHuntUsingLOS` (direct steering) already works without the graph and could be the
   fallback on maps with poor attractor data.
6. Unknowns worth a logging pass: `game->singlePlayer` effects on online modes; `driver->mode` 0 entries
   (who sets idle); `brain+0x584` (state-3 delay) per character.
