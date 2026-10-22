# Retail content packs: peds on Freeway/Prison (traffic next)

Account 2, 2026-10-22. Status: built and verified offline; **needs Ark's test round** (TEST_PEDS.txt).

## What is missing online (exact, tools/shift/survey2.py -> reference/wip/level_survey.txt)
Exact port of retail dbsTraverse (ngptrav.py) over every level on both discs:
- Peds: identical to retail everywhere except **FREEWAY** (retail: types 2, 14, 15, 16 + 3025 attachment)
  and **PRISON** (types 2, 9, 10, 11 = the inmates). Online stripped them.
- Traffic data (fodder nodes 1025-2999): retail CITY, FREEWAY, LOOP, MINIBURB, MINICITY, SUBURB. Online
  kept all of it except **SUBURB** (72 ids -> 0). Traffic is blocked by vehicle slots, not data.

## How the game loads content (retail names; online equivalents)
- Level db callback dispatch (dbProcInteractive / online func_00127650): 1-1024 vehicles, 1025-2999 fodder,
  3000-3999 peds (addPedEpNode: k = id&7, 0 = new ped of type (id-3000)>>3, else attachment), 4000+ weapons...
  Online's func_00127650 no longer sends peds; the baked "Pedestrians Online" patch reroutes them.
- A ped type = op1 node (id 3000+8t) -> op2 -> op1 -> op25 (anim character) -> bones (op17) -> parts.
  Retail stores all ped types of a level contiguously, each type one interval, no data shared between types.
- NGP data is stored for base 0x980000. .PTR = [N, N pointer slots] [M, M pairs (texture-id u16 slot,
  GS TEX0 word slot)]. TEX = header (classes) + records (id, block class); RTX = records (CLUTs, and
  PSM 8H/4HL/4HH "res" textures), loaded to VRAM by address.
- Online fixed layout (D_004FAE38 set): file slots 0 = level, 1..8 = cars (slot from D_00321018[me][client]),
  14 table entries per file kind (D_0048AC10). RAM: level NGP 0x980000 (0xC7EA80 reserved), car NGPs
  0x15FEA80..0x1B93480, free gap ..0x1BE0000 (point-file read buffer after), level TEX/RTX 0x1C05670
  (0x288D80 reserved), car TEX slots ..0x1FFFFF0. Texture ids: level < 600, car slot k = 600+50(k-1),
  ids >= 1000 rejected. CLUT VRAM: level area 0x411 blocks, cars 78 blocks each, slot 9's base = start of
  texture paging (not usable). Cars can also be streamed in mid-match (func_0018A5A0, per frame).

## The packs
- mkpack.py LEVEL NAME ped: ped subtree of the retail level (entry point = the peds group), every chunk it
  points to, own NGP + PTR. texpack.py: TEX/RTX subsets, ids renumbered 1..n, CLUTs re-laid from 0, GS words
  and texture slots patched. mkblobs.py: places it in the online level's free areas (tail of the level NGP
  slot, the gap, tail of the level TEX slot) with absolute pointers, cutting only where the owning instance
  set changes; blob 0 starts with a manifest. verifyblobs.py: loads the blobs into a fake RAM and walks
  them with the dbsTraverse port (exact retail ids, every node inside the blobs, textures consistent).
  | pack | blobs | where |
  |---|---|---|
  | ZFP (Freeway) | ZFP0 6 KB @0x1E7F280, ZFP1 514 KB @0x14CC680 | TEX tail, NGP tail |
  | ZRP (Prison) | ZRP0 8 KB @0x15FB980, ZRP1 313 KB @0x1B93480, ZRP2 217 KB @0x1E4F280 | NGP tail, gap, TEX tail |
- mods/packs.c (hook: LoadLevelDB's jal func_00127330 at 0x18890C -> tmbr_LevelDbLoaded): reads the
  blobs from \PCAR\, uploads the CLUTs after the level's own CLUTs (D_006F268C), registers the textures
  as file slot 9 with ids after the level's (getMaxTexId(0)), patches texture slots + CBPs, walks the
  entry points with func_00127650 -> peds join the pool. Logs "TMBR pack ..." lines (scePrintf).
- Disc: mkdisc.py adds the blobs to \PCAR\ of a 2048-byte ISO of the online disc (data appended, records
  in the free tail of the \PCAR directory sector, PVD size updated). checkdisc.py reads them back.
  Release would be a BPS patch of the ISO (packs are ~1 MB).

## Open
- Test results (Ark). Things that could go wrong: peds pool reset after our load (unlikely: same timing as
  the level's own peds), VRAM CLUT area, inmates needing prison-specific code, memory areas not free.
- Traffic: needs vehicles beyond the 8 slots (89 asm files loop over the 0x31B0-stride array). SUBURB
  also needs a traffic pack (same pipeline, KIND=fod).
