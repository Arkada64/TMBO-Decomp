# Run queue (things you can run without Claude). Run them one at a time, in order.

1. **decomp_run.sh**: running now. General permuter, up to 150 near-miss functions.
   - Progress: `tail -f ~/tmbo_decomp/logs/perm_run4.txt`
2. **perm_targeted.sh**: after 1 finishes. Permuter aimed only at the 99 functions that use the 8-slot
   vehicle array (vehicle_funcs.txt), with a wider window (30 insns, 10 min each).
   - These are exactly what the "bigger vehicle list" mod (traffic + more AI) must change.
   - Run: `bash "/mnt/c/Users/Ark/Desktop/TMB Decomp/perm_targeted.sh"`
   - Progress: `tail -f ~/tmbo_decomp/logs/perm_targeted.txt`
   - The last line says how many of the 99 are still in asm.

3. **commit_pending.sh**: any time no permuter is running. Commits tonight's work, which was done
   outside the repo while the permuter had it: tester builds, the slot guard, these notes.
   - Run: `bash "/mnt/c/Users/Ark/Desktop/TMB Decomp/commit_pending.sh"`

Making a tester build later (no PCSX2 involved):
- Permuter running: `RELEASE=1 bash "/mnt/c/Users/Ark/Desktop/TMB Decomp/mods_copy_build.sh"`
- Otherwise: `bash tools/build_shiftable.sh && bash tools/make_tester_patch.sh`
- Output goes to `TMB Decomp/release/`: a TMBR_<version>.bps plus a README for testers.

1 and 2 keep a result only if the build stays byte-identical, and they commit + push on their own.
Neither launches PCSX2.

## Community patches still to port (must-have)
Already baked in: DNS, Bugfixes, Skip Intros, No-Interlacing, 16:9, the 3 Balance patches.
1. **TMA Ruleset: Remove ENV pickups / Remove health pickups.**
   - Today these are button-toggled cheat codes (D-codes reading the pad every frame).
   - Port as a real rule: a mod flag checked at the patched spots (ENV: 0x3303E4 / 0x155140; health:
     the early-return at 0x1E32D8).
   - Default ON like the pnach. Later it becomes a host-owned lobby option, next to the retail/online
     balance toggle.
2. **TMA Ruleset: Respawn Shield.**
   - Rewrite its code-cave asm (currently it overwrites TrafficDirector::init 0x1B0688..0x1B07E4) as
     mods/*.s, hooked through apply_mods.py.
   - Drop its two NOPs (0x1881A8 = the InitializeFodderCars call, and 0x138D10), or traffic can't work.
   - Its absolute addresses (lui 0x33/0x31 ...) need translating to symbols by hand.
3. **Spectator views.**
   - Bake "Alternate View 5 (Helicopter)", the community default, as a one-line write now.
   - Later it becomes an option, and the commented-out "Select View Toggle" becomes a proper mod.
4. **Verify in-game** the continuous data writes that are now only initial values: Enable Chat
   (0x4FA590) and some 16:9 values. If the game resets them, add a small per-frame or code-level mod.

## Scope of the vehicle-list job (for account 2 / next session)
- **99 functions** index the vehicle array (stride 0x31B0). **27** of them loop over exactly 8 slots.
  **229** touch game fields past the array (game+0x98000 region).
  - The per-function table is in vehicle_scope.md, generated from the asm.
- **Online: 8 slots.** All of them belong to the network player slots, so AddFodder gets slot 8 (out of
  bounds). Retail has many more slots (stride 0x2D00, traffic thresholds 15 and 33).
- **Probable design:** a separate, larger array for non-network vehicles (traffic, extra AI). The 8 net
  slots stay as they are, so net code and fields past the array don't move. That still needs the 27
  8-slot loops (collision, targeting, HUD, update) to also walk the new array.

## Account 2 queue (set by Ark, 2026-10-22)
1. Push the untested bot changes (433b442) into `TMB Decomp/mods` on the PC (bots.c + the two apply_mods.py
   lines), build, test.
2. Traffic: same approach as the AI: decompile fodder/fodderdriver/highwaydriver/trafficdirector + the game's
   fodder setup into readable C (reference/ai_decomp style), then rebuild traffic for online's 8 vehicle
   slots. Includes the Suburb traffic pack.
3. Bots deeper rework: per-frame perception refresh (not one bot per frame), per-vehicle attractor group
   table, and net messages that can name more than 2 bots (owner -2/-3 encoding in weapon / kill events).
4. Peds on ASYLUM (hall) and SHIP (prison ship): both are parts of Prison Passage as separate maps; check if
   PRISON's retail ped data (inmates) can be placed there.
5. Lost / Harbor City content (Ark's ideas, after 1-4):
   - First: Extra Twisted Edition disc image -> is Lost its own (TMB-engine) program? same NGP/TEX/RTX/PTR formats?
   - Gold Tooth = skin of Sweet Tooth (asset conversion + skin pick in menu/lobby).
   - 12 Pak = new character: donor car for handling/stats, imported model, new select entry; special = the
     reticle skill weapon with a longer max charge (find the charge cap in the special code, make it per-car).
   - Lost maps: pickups (placement data may be missing/different) and skill weapons; AI route graph; spawns.
   - Harbor City (PS2 prototype): e.g. Pit Viper with Spectre's special.
   - Memory: test PCSX2 "128MB RAM (dev console)" from mod code (write/read above 32 MB) before laying out.
6. Navmesh for bots (needed: bots hit pathfinding bugs engaging targets on some maps). Plan:
   - Offline tool: walkable surfaces from each level's collision/terrain data (the hd* / terrain nodes the
     game's collision uses) -> navmesh (Recast-style voxelize + regions + polygons) -> per-level pack file.
   - Runtime (mod C, host only): load the pack, A* over polygons (+ string pulling) from bot to target.
   - Plug in where the driver picks its next route point (driverGetNextPoint / ...InFrontOfVehicle,
     func_00102D78 follow) and where groups are tested (attractGetGroupTestPointIsIn); keep the
     attractor graph as fallback and aiHuntUsingLOS (direct steering) for open line of sight.
   - Needs from Ark: list of maps/spots where bots get stuck or route wrong.

## Status 2026-10-22 afternoon (account 2)
- Bots: combat steering (gas on, handbrake swings, extend + jink, reverse as last resort), trigger-happy
  firing (34 deg, in sight, < 500), no fleeing, roles (brawler / sniper / roamer / cruiser) rerolled every
  15-40 s, breakaway from long fights / pile-ups, nav fallback (mods/nav.c, lazy grid A* on hdLosTest rays).
  Net: bots 0-5 named -2..-7 in weapon / kill messages (mods/botnet.s). Not done: host migration with bots
  (func_00168C30 / func_00168DE0 only re-own ais[0..1]).
- Traffic: TRAFFIC_DIAG.ELF (TMBR_TRAFFIC_ON in freecam.c, no loader growth) logs per-car state every 2 s;
  needs Ark's runs on FREEWAY, MINIBURB, CITY before the real fixes. Known: traffic_nodes.c holds absolute
  node addresses + free-memory ranges per level, computed offline before the packs existed.
- Peds: ASYLUM and SHIP already have retail's type-2 peds (3016-3018, same as retail). Retail PRISON's inmates
  (types 9-11) are packed for them: ZAP (ASYLUM, level 16) / ZSP (SHIP, level 15) in TMBO_PEDS_TEST.iso.

## Status 2026-10-22 night (account 2)
- Traffic: works on FREEWAY / MINIBURB / CITY (street lanes fixed: FodderDriver::init is static). SUBURB: ZSF pack
  (18 cars) + fod_suburb, untested. Cars in the RAM gap except SUBURB. Open: collisions with players
  (func_0013CEE0 pairs only 8 slots), damage / destruction, net sync (each machine runs its own traffic).
- Rear fire L1+Down: flag is set like the d-pad combo; the launcher drops it on a 21-frame tick. Held 1 s now,
  debug log TMBR rf on (freecam.c TMBR_RFDBG) - still failing in Ark's test before the hold.
- Peds SHIP / ASYLUM: ZSP / ZAP inmates load into the pool (3 -> 18); packs.c tmbr_PedsRetype retypes 3/4 of the
  type-2 group entries (PedWorldManager game+0x89FA0) to 9-11. Untested.
- Packs: blob 0 scratch moved to the RAM gap (FREEWAY loading screen). FREEWAY player-car / headlight texture
  corruption still unexplained (LOOP bridge corruption seen with traffic in its NGP tail).
- Bots: respawn shield for bots (cruise while 0x497 >= 4), turbo (pad[7]). Perf: bots < 1 ms/frame total.
- Audio cut-outs with many bots: probably SPU voice limits (989snd); not looked at yet.
- Head-On ETE disc: reference/wip/HEADON_ETE.md (Harbor City cars/levels; no Gold Tooth / 12 Pak).
- 2026-10-23 morning: bot respawn shield 10 s; traffic collisions (collisCsToCsCollision owner lookup also finds
  traffic, tmbr_IsVehicleOrTraffic; weapons still use the 8-slot lookup - traffic not destructible yet);
  bots prefer damaged targets and retreat when < 35 % with 2+ bots on them. Lost: Gold Tooth = HC_CHROM,
  12-Pak = HC_STOCK (HEADON_ETE.md). Still open: traffic damage/destruction, traffic net sync, audio.
