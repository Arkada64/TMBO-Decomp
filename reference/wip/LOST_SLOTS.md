# Lost / Harbor City maps in their own level slots (2026-10-26)

Follows LOST_MAPS.md (conversion; the last test disc swapped the maps into DEATH1-5). Now each map gets its own
entry in the host's level select and its own files; no existing level changes. Code: mods/lostslots.c, hooks in
tools/mods/apply_mods.py (group `lost` for TMBR_SKIP), disc: tools/lost/mklostslots.sh.

## How TMBO picks and loads a level
- Level index = shell +0x18000 +0x23AC (game +0x9FCA0 at runtime), 0..20. Index 21 is a dev special case in the
  three level loaders (files named by the buffer D_003F6E68), not usable: every other per-level table overflows.
- Tables by index: D_003F6760 file base names (16 bytes x 21: SUBURB .. DEATH1 = 7 .. DEATH4 = **10** .. ROOFBOSS
  = 20), D_003F68B0 display names (DOGPOUND = 10; func_00189FC8 / func_00189FF0), full-path tables of 32-byte
  strings for \PTS\<base>.PTS (D_002B8E28), .HPT, .PED (0x330xxx), .PKP, .PUP. InitAfterDbLoad (func_00138358)
  switches on the index (sltiu 0x15), many sound functions read +0x23AC (rain, wind, clouds, ambient, prison fence),
  func_00186730 loads a per-level bank by base name (func_002306D8). Mods: navbake.c NAV_LEVELS (\PCAR\ZNxx by
  index), packs.c PACKS, traffic_nodes.c, story.c NEXT / AICOUNT / NAME [21], packs.c ped name table.
- Level files: func_00188688 (RTX), LoadLevelDB (NGP), func_00188930 (TEX) build "\LVL\%s.%s;1" with
  formatFilename (base = D_003F6760[level]). NGP and TEX go through the zip reader func_002466D8 ->
  func_00200788 (they must be in the zip container: there is no raw path), RTX and the point files through the
  raw reader func_002006D0. Both look the name up with func_00201910 (sceCdlFILE*, name). The loading screen
  sizes NGP / TEX with two direct func_00201910 calls (0x1883C4 / 0x1883FC). No PTR is ever loaded by the game.
- Host's pick: level select screen func_001CA6D8 (UI state 0x24, reached from the waiting room GAME SETUP):
  D_004FA448 = highlighted level, steps +-1 with wrap 20 <-> 0, skipping 19 (JUNK2); picture = hier switch shell
  +0xB48 child = level; preview clip LS<level>.PSS (nextMovie 0x46 + level). Confirm (0x1CAB1C) stores it in
  +0x23AC and sends the game info (func_00174988, level in 5 bits of the header word). Clients store it in
  netMsgSessionHandler. Waiting room line "LEVEL : %s" = func_00189FC8 (0x1C5FD0).

## Design: extra entries that run AS Dogpound
Real new indices would need every table above extended (and the shell NGP's level pictures / LS clips). Instead
each Lost map is a virtual entry that runs as level 10 (Dogpound, base DEATH4 = the donor the conversion was
built on: its weapons, pickup models, effects are inside the converted NGP). Everything keyed by the index
(music, weather / fog, sounds, AI counts, nav slot address 0x1524000, story, packs, traffic) behaves as on
Dogpound; only the file names differ:
| game asks for | gets (while a Lost map is picked and the level is 10) |
|---|---|
| \LVL\DEATH4.NGP / TEX / RTX / PTR | \LVL\HC<xx>.<ext> |
| \PTS\DEATH4.PTS / PKP / PUP | \PTS\HC<xx>.<ext> (HPT, PED stay Dogpound's) |
| \PCAR\ZN10.BIN (navbake.c) | \PCAR\ZNHC<xx>.BIN (missing -> no route map, not Dogpound's) |
xx in Lost's menu order: 1 SC Carnival of Darkness, 2 SU Suburban Terror, 3 GD City of the Dead, 4 ND Death Port,
5 ST Stadium Slaughter. A missing HC file other than the ZN falls back to Dogpound's (logged "NOT ON DISC").
Off while STORY is on (story levels use the index directly).

Level select: virtual positions like skins.c's extra cars: right from WARHAWK (20) -> Lost 1 .. Lost n -> wraps
to SUBURBS (0); left from SUBURBS -> Lost n .. Lost 1 -> WARHAWK. Only maps whose \LVL\HC<xx>.NGP is on the disc
are listed (none on a normal disc = the screen is unchanged). On a Lost entry the game's own position is 10, so
Dogpound's picture and clip show, with the Lost name printed at (0x1400, 0x700). Waiting room LEVEL line shows
the Lost name. Sync: host chat "\x01LM<n>" on confirm and every 5 s in the room (skins.c's chat handler routes
it); a client drops a value not refreshed for ~10 s of room time (unmodded / other host).

## Hooks (tools/mods/apply_mods.py, all 1:1 jal swaps)
| address | was | now |
|---|---|---|
| 0x1CA9E0 (ui.s, level select) | jal func_0019CBC0 (step sound) | tmbr_LevelSelStep |
| 0x1CA7CC (ui.s, level select) | jal func_001CE258 (pad read) | tmbr_LevelSelFrame |
| 0x1CAB20 (ui.s, level select) | jal func_00174988 (send game info) | tmbr_LevelSelConfirm |
| 0x1C5FD0 (ui.s, waiting room) | jal func_00189FC8 (level name) | tmbr_LevelShowName |
| 0x2006F8 (func_002006D0, raw reader) | jal func_00201910 | tmbr_FileSearch |
| 0x2007C0 (func_00200788, zip reader) | jal func_00201910 | tmbr_FileSearch |
| 0x1883C4 / 0x1883FC (loading bar sizes) | jal func_00201910 | tmbr_FileSearch |
Also: skins.c tmbr_ChatHandler routes "\x01LM" to tmbr_LostRecv; bots.c tmbr_LobbyFrame calls tmbr_LostLobby.

## Tests
- Disc: `bash tools/lost/mklostslots.sh` (after mktest.sh) -> test/LOSTSLOTS.iso + "Run LOSTSLOTS.bat".
  Staged files in packs/lost3/{LVL,PTS,PCAR}/ (rewritten only when changed).
- Headless pick, either:
  - build with `TMBR_LOSTMAP=n` in the environment (build_shiftable.sh passes -DTMBR_LOSTMAP=n): the host's
    waiting room forces Dogpound + Lost map n every frame (log "TMBR lost: test build, level forced to ..."), so
    any quick-boot script that reaches the room as host and starts the match plays it (e.g. the stress scripts:
    their level-select CROSS picks Suburbs, the room then forces the map);
  - or buttons in the level select from SUBURBS (the default highlight): LEFT x k = Lost map 6 - k (with all five
    on the disc: 1 LEFT = Stadium Slaughter, 3 LEFTs = City of the Dead, 5 = Carnival), then CROSS.
- Log lines: "TMBR lost: <name> available", "TMBR lost: level 10, Lost map n ...", one
  "TMBR lost: LVL\DEATH4.NGP;1 -> LVL\HCGD.NGP;1" per redirected file, "TMBR nav: level 10 map, N nodes".
- 128 MB EE (TODO 6g): nothing in the mod depends on it; the test is PCSX2's setting only.

## Risks / to check in game
- The level select is the host's only path: if TMBO's GAME SETUP has another level list, it is not hooked.
- Name position on the level select screen (0x1400, 0x700) is a guess (skins' car-select spot); the LS clip and
  picture are Dogpound's.
- Late joiners get the map within 5 s of the room; a client whose disc lacks the HC files falls back to
  Dogpound's files (desync of the arena, not a crash) - all players need the same disc.
- HPT (helicopter path?) and PED stay Dogpound's.
- mkdisc.py: the wrapper maps "LVL/HC*.*", "PTS/HC*.*", "PCAR/ZNHC*.BIN" (paths relative to packs/) to the files in
  packs/lost3/; relies on mkdisc using the path's directory as the disc directory (LVL, PTS, PCAR).
