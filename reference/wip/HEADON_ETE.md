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
- **No Gold Tooth, 12 Pak or Pit Viper files** (no GOLD*/12PAK*/PIT* names; Lost is not on this disc as
  separate content). Those need the Twisted Metal: Lost image.

## .BDD = a bundle of the TMB file kinds
Directory at the start: records of 0x2C bytes {name[20], ext[8], u32 offset, u32 size, FILETIME[8]}, e.g.
`SWEET.BDD`: ngp @0xC0 (217008), tex @0x35400 (259824), ptr @0x74AF0 (824). No separate RTX (CLUTs inside tex?).
The ngp section uses the TMB node format (HierHead words, op1 roots, vehicle id 1-1024), stored for base 0
(TMB: 0x980000), so mkpack-style relocation applies.

## Next steps for imports
1. Diff the ngp node set of a Head-On car vs the same TMB car (e.g. SWEET vs TMB Sweet Tooth): ops, ids,
   attachment ids, weapon mounts.
2. Head-On tex vs TMB TEX+RTX: record layout, PSMs, CLUT placement.
3. A converter (mkpack-like) to a TMB car slot: NGP + PTR + TEX + RTX, then a car-select entry.
