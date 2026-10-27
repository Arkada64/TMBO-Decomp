# Traffic + AI: where things stand (2026-10-22, account 1)

## Traffic (mods/traffic.s, tools/mods/apply_mods.py; build: `bash tools/build_shiftable.sh`)
- **Online maps have no traffic data**: online LVL/SUBURB.NGP has zero fodder groups. Retail has 9 car
  groups (node ids 2000+32n, op 1, flags@+0xA = 1/3) plus attachments 2001-2009 (op 4/6).
  Checked with tools/shift/ngpids.py. Online TEX is also ~155 KB smaller (the car textures are gone too).
- **Retail data does reach our code**: test disc `TMBO_suburb_retail.iso` (tools/shift/mkiso_swap.py
  swaps retail's SUBURB.NGP/TEX/RTX/PTR in). With it the log shows `TMBR fodder node 2000..2265`,
  about 35 cars per load. So FodderParse -> tmbr_FodderCs -> AddFodder (func_0013A640) runs.
- **Still to fix**:
  1. No cars appear. Check InitializeFodderCars (func_0013AB90; called from shell.s 0x1881A8).
     - It skips traffic if game+0x98000+0x7CAC (player count) >= 3.
     - It branches on +0x7CA0 (game type 2 -> TrafficDirector path func_001B0688).
     - It also reads +0x6698.
     - AddFodder's own printf "Got fodder car ..." is BUFFERED (game printf only flushes in bursts).
       To see it, swap that printf to scePrintf in the shiftable build.
  2. Once at load, hierTraverseAsm faults (0x214710 range, addr 0x10). Probably our pool cs
     (tmbr_FodderCs: func_00214088 + hierInitCs + sb 1 @0xC + hierSetCsEpNode + hierCsAddToCsList)
     is missing something that online's pooled cs (func_00213FF8 / func_00127B58) or AddVehicle sets.
     Compare with retail csCreate.
  3. Proper fix (option 2): graft retail's car groups + textures into the online map at load time,
     instead of swapping whole map files (the swap breaks map select: TEX code fault at 0x1464AC).
- **Debug**:
  - `TMBR_DEBUG_LOADER=1 bash tools/build_shiftable.sh` routes the db traversal callback through
    tmbr_LoaderDbg, which prints node ids 0x401-0xF9F.
  - Always use **scePrintf** for debug output.
- **Rule**: code growth inside the game's .text must be a multiple of 0x80. lq-read data lives in .text
  (libmpeg clamp mask), and a 0x28-byte growth gave full-screen green bars. apply_mods asserts this.
  build_shiftable aligns the mods' .text to 128.

## UPDATE 2026-10-22 00:40: why traffic can't spawn online
- **No free slot.** Online AddFodder (func_0013A640) puts the car into vehicle slot game[0x98000+0x7CA4].
  Online has only 8 vehicle slots (0x31B0 each), all taken by the 8 network player slots. The log shows
  every AddFodder going to slot 8, i.e. out of bounds.
  - Retail has many slots: stride 0x2D00, InitializeFodderCars thresholds at 15 and 33.
  - Retail AddFodder also increments the slot count; online's doesn't.
- mods/traffic.s now skips AddFodder when the slot is >= 8 and logs it. That copy is in the TMB Decomp
  folder only, not committed: the permuter was running in the repo at the time.
- The remaining hierTraverseAsm / 0x1464AC faults come from swapping retail's SUBURB files onto the
  online disc. They happen even with zero cars added, and the normal online disc has none.
- **Real traffic needs a bigger vehicle array.** Online's TheGame keeps 8 slots with fields after them,
  and every vehicle loop is `slti 8`. That's a structural change best done once game.c/vehicle code is
  in C. Same 8-slot design is probably behind the online AI limit too.
- Builds while the permuter runs: `mods_copy_build.sh` builds in ~/modshome/tmbo_decomp (private copy).

## AI count limit online (2 AI with 1 human, 1 with 2, 0 with 3+): NOT located yet
- The player/vehicle array is 8 slots × 0x31B0 at game + 0x98000-ish (see func_0013A9E0, which turns a
  vehicle slot into an AI car: "Setting vehicle %d to AI car %d (%s)"). It is only called from the
  prison story code (func_0017DB90), so it's not the online path.
- Net-side AI creation: func_00168C30 and func_0016C590 print "AI FAILED: name = ... vehicleIndex ...
  ClientIndex ... ObjectIndex"; they call func_001733F8, func_00176B10 and func_00174988. The host
  assigns AI to client/object slots there. Look upstream (lobby / game-start) for where the AI count is
  derived from the human count. A search for a `3 - n` pattern found nothing, so it's likely a table
  or slti chain.
- Targeting ("fight each other more"): GetBestAIToBait (0x13A420), GetNumAIInBaitMode, GetNumAIsHunting
  (0x13EE78), aiHuntUsingLOS, aiUpdateAttack, aiSetAggressiveness. Retail names map 1:1 (mapping.csv).
