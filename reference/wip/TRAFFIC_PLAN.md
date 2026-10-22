# Traffic in online maps: findings + plan (account 2, 2026-10-22)

## Where retail had traffic, and what online kept (tools/shift/survey2.py)
Retail fodder (traffic) nodes on CITY, FREEWAY, LOOP, MINIBURB, MINICITY, SUBURB (72 ids each; Freeway 60).
Online kept all of it except SUBURB (0). SUBURB needs a data pack (same pipeline as peds: mkpack KIND=fod).
Online kept all traffic CODE: fodderInit/fodderUpdateInputs (0x1343D8/0x1345B0), FodderDriver, TrafficDirector
(update called from the online per-frame update func_00138C90 when level type == 2), HighwayDirector,
InitializeFodderCars (0x13AB90), SetFodderCar (0x13ADC0), AddFodder (0x13A640), gameCheckNumFodder (0x13AFD0).

## How retail runs traffic
- Retail vehicles (stride 0x2D00) are one array at game+0: players, AI, then fodder. InitializeFodderCars
  makes up to 33 (0x21) fodder cars (15 in some modes) with SetFodderCar(game, idx, carModel, highway?).
- Retail Update__7TheGame per frame: vehicleUpdate for every active vehicle (+0x580), gameResolveCollisions,
  then per vehicle suspUpdateSuspension + vehicleSetCsMat + vehicleUpdateAfterNewPos + updateVehicleSound.
  TrafficDirector::update for highway levels; gameUpdateFodderFlags.

## Why online has none
- Online vehicles: 8 x 0x31B0 at game+0 (game = *D_004FA030), slot counter game+0x9FCA4, per-vehicle
  interactive index game+0x9FCD8[i]; other TheGame fields start right after (0x18D80) -> can't grow in place.
- Online level callback (func_00127650) ignores fodder ids; mods/traffic.s (account 1) ports FodderParse,
  but AddFodder then writes past slot 7. Its loader hook grows func_00127650 (off by default).

## Every loop over vehicles (fx/vehloops.txt, 99 functions)
Needed for traffic, by system:
- Per-frame update: func_00138C90 (online Update): loop calling vehicleUpdate (func_001DC760) etc.
- Vehicle collisions: func_0013CEE0 (collisTestForCollisions / collisResolveCsToCsCollisions / drift).
- Fodder management: gameCheckNumFodder (0x13AFD0), TrafficDirector/HighwayDirector (init/update/
  changeFodder/pruneAllVehicles), InitializeFodderCars.
- Weapon hits: all *HD__6Weapon handlers + collis func_00123288 + explosions: hdPntSphereTest ->
  DispatchHit__12Interactives (func_0014F108) -> IsInteractiveAVehicle(interactive, &vehIdx) ->
  game + vehIdx*0x31B0 (-> fodderTakeHit for fodder).
- Lock-on / targeting: Launcher GetLockOn, UpdateSpecial, UpdateEnvWeapon, FireCurrentWeapon (use 0x7CA4 count).
- Peds react to vehicles: takeHit__10AttractPed. Sound: updateAmbientSound. Shadows: UpdateShadow.
- Not needed (players only): HUD, net roster/session/game events, shell overlays.

## Plan (phases, each one test round)
1. Spawn + drive (Freeway first: data + memory available). Separate array of N traffic vehicles (0x31B0 each,
   ~418 KB for 33) in free memory (NGP tail after the ped pack). Placement trick: put the array at an address
   that is a whole number of vehicles away from game (addr - game = k*0x31B0), so "vehicle index" k..k+N
   still means game + idx*0x31B0 for every function that takes an index (IsInteractiveAVehicle callers).
   Fodder ids from the level callback via a 1:1 jump (no growth), port of FodderParse into our array,
   InitializeFodderCars equivalent, per-frame hook after the online vehicle loop: vehicleUpdate + suspension
   + cs matrix + after-new-pos for each traffic car. Check: cars drive, render, lights/blinkers.
2. Collisions with players: hook func_0013CEE0 to also test player x traffic and traffic x traffic.
3. Weapons/explosions: hook IsInteractiveAVehicle to map traffic interactives to their (large) index; check
   which hit handlers also index side arrays by vehicle index (those need care).
4. Network: host simulates, clients follow (positions/state per car at low rate); until then traffic is
   local per client like peds ("not synced").
5. SUBURB traffic data pack (mkpack KIND=fod) + same as 1-4. CITY/LOOP/MINIBURB/MINICITY as 1-4.
Open questions for Ark: can players join a match in progress (cars streamed mid-match by func_0018A5A0)?
How many traffic cars per level is acceptable for performance (retail: 33 with 1 player)?
