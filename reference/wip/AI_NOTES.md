# Online AI (bots): how many spawn, who they target (reverse engineering notes)

All addresses SCUS-97196 (online). `game` = `*D_004FA030`, net = `D_003156C0` (8 player slots x 0x220).

## Bot count: hard-coded "3 vehicles total"
`func_001399A8` (game start), host only (`func_001734B8(net)`), lobby setting "USE BOTS" = bit 13 of
`net.unk3148->unk0`:
```
n = number of net slots with state (slot+0x214) >= 7 and slot+0xC8 == 0   // connected humans
if (n < 3) { addBot(net, -1);            // func_00175588
             if (n < 2) addBot(net, -1); }
```
So 1 player -> 2 bots, 2 players -> 1 bot, 3+ -> none. Nothing else limits it to that.

Structural limits behind it:
- AI vehicle pointer list `game+0x9E690` has **2 entries** (InitTypeOfVehicles clears exactly 2; `func_00175588`
  only adds a bot if 0x9E690 or 0x9E694 is empty). Right after it is the fodder list (`game+0x9E698`).
  Count of AIs = `game+0x9FEE4` (also copied to 0x9FCBC); loops over AIs use that count, so they are generic.
- Per-vehicle AI state is per *vehicle index* (0..7): brain `game+0x23000+i*0x630`, driver `game+0x26180+i*0x2C0`
  (`func_0013A7B8` / `func_0013A9E0`), so all 8 vehicles already have AI memory.
- A bot takes a free net player slot (`func_00175588`), so humans + bots <= 8 (8 vehicle structs, 8 car slots).
- Clients create the host's bots through `netObjCreateCB` -> `func_001690F0`, which indexes `game+0x9E690[k]`.

To make the count configurable: replace the two calls with a loop to the wanted count (capped at 8 - humans),
and move the AI pointer list to a larger free spot (patch every `game+0x9E690/0x9E694` reference: ~17 functions
in game.c, net.c, weap.c). Host-only logic; bots are already synced as normal net vehicles.

## Targeting: bots only ever hunt humans
- Driver modes (`driver+4`): 2 = attack (turned to fight what's in front), 3/4 = cruise between cruise zones,
  5 = hunt. `func_00130E88(driver, mode)` sets the mode; for **mode 5 it picks the target as the nearest active
  vehicle among the 8 net player slots** (`net+0xB0+i*0x220`) and stores it at `driver+0xB0` via `func_00130C00`.
- `func_0013BC98` (per frame, per human): when a human changes cruise zone it calls
  `gameCheckNewAIToHuntPlayer(game, human)`, but only if (1 human and >= 2 AIs) or (2 humans and >= 3 AIs).
  That function picks the best AI to hunt that human, records it in `game+0x9FD04[human]`, demotes the previous
  hunter to cruise (mode 4).
- `func_0013CB08` switches an AI whose target is that human to attack (mode 2) when it is facing it.
- The fairness gate `aiIsPlayerLookingAtAIEnoughForAIToShoot` is about the human's camera.

To get bot-vs-bot fights: hook the mode-5 target pick (and the hunter bookkeeping) so any vehicle, bot or
human, can be a target (score by distance, health, who hit me last, etc.), and bypass the "is the player
looking at me" gate when the target is a bot. All host-side, no new net traffic.

## Movement
Driving is the Driver class following attractor points / cruise zones (`driverGetNewPointInFrontOfVehicle`,
`gamePickCruiseZone`). A navmesh would replace the point picking inside Driver; doable with hooks later, much
easier once driver.c / attracti.c / ai.c are decompiled.
