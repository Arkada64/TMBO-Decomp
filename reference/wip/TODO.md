# TMB-Reloaded TODO (2026-10-22)

## Peds on Freeway / Prison Passage
- 2026-10-22 night (account 2): analysis done, see reference/wip/PEDS_PLAN.md. Retail FREEWAY/PRISON
  have one ped type (3016-3018), 74 KB incl. a 66 KB anim/skeleton part online lacks entirely. Plan:
  a car-style extra db (NGP/PTR/RTX/TEX) with only the ped nodes, added after LoadCarsDB.
- Fact (SEL_PEDLOG run): the online level loader gets 17 ped spawn nodes (ids 3016-3066) on Suburbs,
  **none** on Freeway and none on Prison. The online versions of those maps had their ped data stripped
  (retail has it). Suburbs/Junkyard work with our ped patch.
- Plan: extract retail FREEWAY/PRISON ped nodes (ids 3000-3999) and, in the mod build, feed them to
  addPedEpNode (func_00178248) after the level loads.
- Check first: (1) are ped nodes self-contained (or do they point into other parts of the retail db)?
  (2) are the ped models/anims/textures still in online FREEWAY/PRISON? (a name scan of the NGPs found
  nothing useful; needs the hier format or a runtime check: addPedEpNode reads a ped type table
  D_0032CBF4 / D_0032CC80, indexed by D_004FB748). Not doable as a pnach (too much data).
- Tools: pedcount.py / pedcount2.py (NGP members), SEL_PEDLOG build (TMBR_DEBUG_LOADER=1, prints nodes
  0x401-0xF9F to emulog).

## Traffic
- Online FREEWAY.NGP still HAS traffic (fodder) nodes: 60 ids, 2000-2414. Use Freeway for traffic work
  (Suburbs online has none).
- Still blocked by vehicle slots: online has 8 (all players); traffic needs a second, host-owned, synced
  vehicle array (see reference/wip/NEXT_traffic_ai.md).
- The traffic loader hooks grow func_00127650 by 0x80 -> data moves -> map selector crash (see below).
  Rework them to jump out to the mods area instead of growing (like the peds pnach stub).

## Shiftable build: stale data reference
- Moving data (even just padding .text by 0x800 with no mods) crashes the map selector (exit to the PS2
  menu). Some data reference in the shiftable build is still raw. The mod build avoids it by keeping every
  game address fixed (mods after .bss). Find it eventually: bisect by padding at different .text points,
  or diff RAM dumps of the matching vs padded build at the selector.

## Free cam
- Works (FREECAM_TEST, Select+L3 test toggle). Possible tuning: speed, sensitivity, inverted axes.
- Rendering/culling may still use the followed car's position (some pop-in); hierSetCameraVehiclePos gets
  cs+0x10 = our position at render time, so probably fine.

## Releases / pnach
- Full pnach: release/SCUS-97196_C54E5CF2.pnach (tools/mods/make_pnach.sh). TMA variant without quick
  moves / tap switch: release/TMA/. Don't copy pnach files into the PCSX2 folder (user manages it).
- No merged release build until there is more to show (traffic/AI).
- Later: TMA rules as host lobby options; AI count rule (fill lobbies / min 2 AI); selectable AI count.

## Queue for the user
- perm_targeted.sh (permuter on the 99 vehicle functions), then send results.
