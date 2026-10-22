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
