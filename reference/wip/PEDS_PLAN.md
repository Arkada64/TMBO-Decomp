# Peds on Freeway / Prison, and traffic: findings + plan (account 2, 2026-10-22 night)

All offline analysis (no PCSX2 runs). Tools in tools/shift: ngpdb.py (disc/NGP/PTR access, cached in
TMB Decomp/fx/), pedgraph.py (ped/fodder subtrees from the exact pointer list), pedshared.py (shared
vs exclusive data, presence in online). Retail names come from the retail decomp (~/tmb_decomp).

## How peds work (retail names, same code online)
- A ped is a **model node** in the level database: hierhead id1 = 3000 + 8*type + k.
  k = 0: new ped (Pedestrian::init with the model, into the free pool of its type);
  k != 0: attachment of the previous ped (addAttachment). PedPimp pool: 96 peds, 25 types x 10.
- Called from dbProcInteractive (per-node callback of dbsTraverse in dbInitDb) -> addPedEpNode.
- .PED files (dbPedFilenames, PedPTool::readPointsFromDisk) are only spawn points; they pull peds from
  the pool by type (allocPedDbId: type = (id - 3000) >> 3). Online still has all .PED files.
- Ids 3072+ (3072 type 9 etc.) are something else: online keeps those and still shows no peds.

## What the maps contain (pedgraph.py)
| | retail peds | online peds |
|---|---|---|
| SUBURB | 41 nodes, types 2-8 | identical (so peds work there) |
| FREEWAY | 9 nodes: type 2 (3016-3018) + 3025 | none |
| PRISON | 6 nodes: type 2 (3016-3018) | none |
- Retail FREEWAY ped footprint: 74 KB (7.9 KB exclusive + 66 KB shared with a few 3016/3072 nodes:
  skeleton/animation data). **Online FREEWAY has none of it** (60 bytes of the 66 KB found, md5 with
  pointers masked). So the graft must bring the whole 74 KB. PRISON: same 66 KB shared + 6.5 KB.
- Traffic data is intact online: FREEWAY fodder 201 nodes online vs 198 retail, same footprint.
  Traffic is only blocked by vehicle slots (see NEXT_traffic_ai.md).

## Database format (from retail dbInitDb / dbsRelocateViaPtrListFile / dbsRelocateFileZero)
- NGP data is stored as if loaded at 0x980000. DbHeader = numEntryPts, epNode[] (3 groups per level).
- .PTR = [N, N pointer-slot offsets] [M, M texture-table u16 slots (+= getMaxTexId of previous dbs)]
  [M GS register words in geometry (VRAM relocation, file 0 only via dbsRelocateFileZero)].
- **Several databases load in sequence**: LoadLevelFiles = LevelResTexture, LevelDB, LevelTexture,
  CarsDB. Each car: fileReadf(name, getNextNgpLoadAddr()); fileAddNgpFile(addr, size);
  fileAddName(trimmed name). dbInitDb then relocates every db (its .PTR picked by name) and runs
  dbsTraverse/dbProcInteractive on each -> ped nodes in an extra db register themselves.
- Cars ship as /PCAR/AXP.{NGP,PTR,RTX,TEX} (and /ACAR): same 4-file set as a level.

## Plan for peds (no growth of game code; one test round)
1. Learn the TEX/RTX format and how a car's TEX/RTX reach VRAM (decompile LoadLevelTexture,
   LoadLevelResTexture, the texm code, and whatever loads /PCAR/*.TEX). Use a small car (AXP) as the
   reference.
2. tools/shift/mkpedpack.py: from retail FREEWAY/PRISON, copy the 74 KB closure into a new NGP
   (DbHeader with the ped nodes as entry points), rebased pointers, its own PTR (remapped slots, tex
   table, GS words) and a TEX/RTX subset with only the textures those nodes use. Verify offline: every
   pointer of the pack lands inside the pack.
3. Mod: on FREEWAY/PRISON, after LoadCarsDB, read the pack and fileAddNgpFile + fileAddName it.
   Hook = 1:1 jump to the mods area (like the peds pnach stub). Needs the pack on the disc image
   (mkiso_swap.py-style add) or loaded from a known place.
4. Ark: one test (Freeway, Prison), emulog with TMBR_DEBUG_LOADER=1 shows nodes 3016-3025.
Risks: the extra db's name decides which .PTR loader branch runs (the switch on the name's 4th char:
'P' vs 'A'/'B'); ped count/VRAM budget; the 3016/3072 nodes that share the anim data may be needed too.

## Traffic
- Data is present online; blocked by the 8 vehicle slots (online AddFodder writes slot 8 = out of
  bounds). Needs a second, host-owned vehicle array + sync. Plus: the traffic loader hooks grow
  func_00127650 by 0x80; rework them into 1:1 jumps out to the mods area (same technique as step 3).
  Not started tonight.
