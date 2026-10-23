# Twisted Metal: Head-On - Extra Twisted Edition (PS2, SCUS-97621): what is on the disc

Ark's image: `TMB Decomp/Twisted Metal - Head-On - Extra Twisted Edition.iso`. Listing: `TMB Decomp/ls_headon.txt`
(`headon_ls.py`), section peek: `headon_peek.py`.

## Contents (405 files)
- `/CARS/*.BDD` (38) and `/AICARS/*.BDD` (38, smaller AI versions): Head-On cars (AXEL, COP, CRIM, DARK1/2,
  DARKPLA1/2, EDATV, EDBOSS, EDPLAYER, GRASS, HAMR, HEARSE, MRGRIM, MRSLAM, RKILL, SPECTRE, SWEET, THUMP, TWIST,
  WART) and **Harbor City** cars (`HC_`: AXEL, CHROM, DERBY, GRIM, HEARS, PREAC, RKILL, ROCK, SEMI, STOCK,
  SUV, SWEET, TANK, TAXI, TOW, VETTE).
- `/LVL/*.BDD` (26): Head-On levels + Harbor City levels `HC_GD, HC_ND, HC_SC, HC_ST, HC_SU`.
- `/TM1/*.PSS`: the Twisted Metal 1 documentary/videos. `/SHELL`, `/SND`, `/VAG`, `/MOV`, `/GLOBALS`.
- **Twisted Metal: Lost = the `HC_*` content.** The exe's Lost roster (display names, `headon_names2.py`) against
  its file table: Axel=HC_AXEL, Crazy 8=HC_DERBY, Mr. Grimm=HC_GRIM, Shadow=HC_HEARS, Brimstone=HC_PREAC,
  RoadKill=HC_RKILL, DarkSide=HC_SEMI, Outlaw=HC_SUV, Sweet Tooth=HC_SWEET, Yellow Jacket=HC_TAXI,
  JunkYard Dog=HC_TOW, Spectre=HC_VETTE, Manslaughter=HC_ROCK, **12-Pak=HC_STOCK**, Warthog=HC_TANK,
  **Gold Tooth=HC_CHROM** ("A solid gold ice cream truck provided to Sweet Tooth"; driver Needles Kane).
  Mapping by meaning (the two tables are in different orders) - confirm in game.

## .BDD = a bundle of the TMB file kinds
Directory at the start: records of 0x2C bytes {name[20], ext[8], u32 offset, u32 size, FILETIME[8]}, e.g.
`SWEET.BDD`: ngp @0xC0 (217008), tex @0x35400 (259824), ptr @0x74AF0 (824). No separate RTX (CLUTs inside tex?).
The ngp section uses the TMB node format (HierHead words, op1 roots, vehicle id 1-1024), stored for base 0
(TMB: 0x980000), so mkpack-style relocation applies.

## Format check (headon_cmp.py)
- HC_CHROM ngp: 2 entry points; root op1 node id 134 (vehicle), op1 children with the TMB child layout
  (count at +8, first child pointer at +0x20, rest at +0x24). Pointers are file offsets (base 0).
- tex header = TMB TEX header: nclass, recq, nclass x (count, block size), e.g. HC_CHROM (7,0x800) (3,0x2000)
  (5,0x1000) (3,0x4000).
- TMB car files (/PCAR/<code>.NGP, e.g. STP) are stored for their RAM slot (STP entry points 0xA25200...) with
  3 entry points; Lost cars have 2. The BDD ptr section should list the pointer slots to relocate.

## Next steps for imports
1. Diff the ngp node set of a Head-On car vs the same TMB car (e.g. SWEET vs TMB Sweet Tooth): ops, ids,
   attachment ids, weapon mounts.
2. Head-On tex vs TMB TEX+RTX: record layout, PSMs, CLUT placement.
3. A converter (mkpack-like) to a TMB car slot: NGP + PTR + TEX + RTX, then a car-select entry.
