# Functions using the online 8-slot vehicle array (stride 0x31B0)
Generated from the online asm. Columns:
- **0x31B0 uses**: how many times the function indexes a vehicle slot.
- **8-loops**: `slti x, 8` compares (loops over all slots).
- **game+0x98000 uses**: accesses to TheGame fields that sit past the array.

The 27 functions with 8-loops are the ones a bigger/second vehicle list must change.
Also listed in vehicle_funcs.txt.

| function | file | 0x31B0 uses | 8-loops | game+0x98000 uses |
|---|---|---|---|---|
| GetVehicleFromName__7TheGameii | tmb/game | 1 | 2 | 0 |
| IsInteractiveAVehicle__7TheGameiPi | tmb/game | 1 | 1 | 0 |
| func_00138C90 | tmb/game | 6 | 2 | 13 |
| func_0013A7B8 | tmb/game | 1 | 1 | 2 |
| func_0013A9E0 (set vehicle to AI car) | tmb/game | 1 | 1 | 2 |
| func_0013AB90 (InitializeFodderCars) | tmb/game | 1 | 1 | 9 |
| func_0013CD18 | tmb/game | 2 | 2 | 4 |
| func_0013D0C0 | tmb/game | 1 | 1 | 0 |
| func_0013EED0 | online/after_game_19 | 1 | 1 | 6 |
| func_001475F8 | tmb/hud.s | 5 | 3 | 4 |
| func_00149D08 | tmb/hud.s | 4 | 1 | 4 |
| func_0014E708 | tmb/hud.s | 3 | 1 | 0 |
| func_00156E08 | tmb/launch | 3 | 1 | 10 |
| func_001690F0 | online/net | 3 | 1 | 0 |
| func_00171F88 | online/net | 1 | 2 | 0 |
| func_00174988 | online/net | 1 | 2 | 0 |
| func_00174D78 | online/net | 1 | 3 | 4 |
| func_001756A0 | online/net | 1 | 2 | 2 |
| func_00175AA0 | online/net | 3 | 4 | 0 |
| func_001761E8 | online/net | 2 | 2 | 2 |
| func_00183580 | tmb/rt | 1 | 1 | 6 |
| func_0018C7D0 | online/after_shelloverlays_45 | 3 | 2 | 0 |
| func_001C7C28 | tmb/ui.s | 1 | 2 | 0 |
| func_001E1C40 | tmb/vehicle | 3 | 2 | 10 |
| func_001ED420 | tmb/weap | 1 | 1 | 0 |
| netMsgGameEventHandler | online/net | 4 | 6 | 6 |
| netObjDestroyCB | online/net | 4 | 2 | 0 |

Plus 72 functions that index a slot without looping over all 8: AddVehicle, AddFodder (func_0013A640),
weapons (weap/*), HUD, launch, trafficdirector, shell, destruct, collis and others. See vehicle_funcs.txt.
