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

## Full walk (headon_cmp.py, TMB dbsTraverse port)
- TMB STP (Sweet Tooth): 3 entry points (op1 car root id 192, op15, op7), 589 nodes, ops 0,1,2,3,4,5,6,7,9,10,
  15,17,25,31; callbacks: car parts 192-223, weapon mounts 4001-4006, 4100; PTR = 1643 pointer slots + 335
  texture pairs.
- Lost HC_CHROM: 2 entry points (op1 root id 134, op6); the walk stops after 7 nodes at **ops 20, 26, 27**,
  which the TMB traverse doesn't know: the Head-On engine has new node types (PSP-era geometry). Its ptr
  section is another format (starts 0xFFFFFFFF, then pairs of u16).
- So Lost cars are not drop-in: an import means decoding the Head-On geometry/texture nodes and re-authoring a
  TMB car (op17 meshes, op4/op6 parts, 4001+ weapon mounts, TEX/RTX), i.e. a model converter.

## Head-On formats, decoded (2026-10-23, tools/lost/)
- **Nodes**: same HierHead word as TMB (op = word & 0x3F) and the same layouts for op0 object, op1 group, op2 LOD,
  op3 translate, op4 rotate, op6 switch. New / changed in Head-On: op5 = child list (count byte +0xB, kids +0xC),
  op13 = joint (bind matrix + inverse, kids at +0xA0; a short 0x30 form has kids at +0x20 and an inline op0),
  op19 = health switch (count byte +8, entries of 0xC from +0x10: child, extra, u16 threshold of 0xFFFF),
  op20 = reference (child +8), op8 = empty placeholder, op17/26/27 = car-level data (skeleton, mounts).
  Gold Tooth: high LOD = 0x28EF0 (LOD node 0x28F20), far LOD = 0x5980; op5 at 0x350 lists 14 mount points (id 62).
- **op0 (Head-On)**: {0, flags, 0, pow2 scale}, texture keys (u32, up to 4), bounding sphere, 3 qwords, one GS
  qword per texture, optional 2 skin qwords (bone indices), then a DMA `ret` packet. VIF: STROW + STMOD 1 +
  UNPACK V3-16 positions ((row + s16) * scale), V3-8 normals, then per strip: GIF tag (4th word = texture select
  1+3k, same as TMB), S-8 pool indices, V4-5 (or V4-8) colors, V2-16 UVs (same 4096 scale as TMB), masked S-8
  writes = strip restart pairs, MSCNT. Positions are in car space, same axes as TMB (x right, y forward, z up);
  the Lost truck is the TMB Sweet Tooth model at ~1/1.15 scale.
- **op0 (TMB)**: hier.h HierObject (0x70 + 0x30 per texture: TEX0 + TEX1 as A+D) then the packet: UNPACK S-32
  @0xB4 count, V3-32 float pool, MSCAL 0, STCYCL 1/3, strips of {GIF tag, V4-8 (normal xyz, pool index),
  V4-8 RGBA, V2-16 UV}, MSCNT; new batch = STCYCL 4/4, FLUSH, count, pool. numVerts (flags >> 16) = strip
  vertices. tools/lost/tmbenc.py re-encodes 33 of STP's 36 meshes byte-identically (the other 3 are sprites).
- **Textures**: Head-On TEX records = TMB TEX records, but pixels are stored as the PSMCT32 upload (GS-swizzled;
  gsmem.py unswizzles T8/T4), gs holds the upload rect, the key is the texture reference, and each CLUT is the
  next record (alpha 0..0x80). TMB stores linear PSMT8/PSMT4 pixels, gs = id | psm<<32 | tw<<40 | th<<44 |
  (4 for T8, 8 for T4)<<51 | class<<59, CLUTs live in the RTX (alpha 0..0xFF, CBP = RTX block address).
  For a non-first texture file (cars) texmRelocate only matches class block sizes to the level's bins.

## Gold Tooth as a Sweet Tooth skin (tools/lost/gtbuild.py)
`python3 gtbuild.py DIR_WITH_STP.* HC_CHROM.BDD OUTDIR [scale=1.15]` replaces the meshes of Sweet Tooth's three
body damage states (op31 id 209 groups) and its far LOD body with Gold Tooth's (high LOD, Head-On flare / flame
effect meshes skipped), adds 7 textures + CLUTs, drops the old meshes and rebuilds the PTR. NGP 756,640 bytes
(original 757,888). Wheels, weapon mounts, special, shadow and collision stay Sweet Tooth's.
`GT_STATES=0,1,2` uses Gold Tooth's own damage states (+25 KB). Previews: hoprev.py (Head-On), tmbprev.py (the
built TMB files, round-trip check). Test disc: `TMBO_GOLDTOOTH_TEST.iso` = peds test disc + the four STP files
(cloud/goldtooth/mkdisc_gt.sh, mkswap.py appends files and repoints their directory records).

- First in-game run (2026-10-23): black-screen softlock, loading screen corrupted, VIF DMA error. Cause: TEX/RTX
  record lists end with a record whose sizew is 0 (it runs to the end of the file and stops texmRelocate); the
  first build cut that record off (STP texture 21 + its CLUT at block 72) and put a new CLUT on block 72. Fixed
  (textconv.records/join). Car CLUT space: retail cars use 57-74 blocks (STP 76 incl. that last CLUT), car TEX
  up to 299,520 bytes, so the build reuses Sweet Tooth's palettes for the truck-art textures (GT_HALF, GT_GOLD_PAL
  shrink further: TMBO_GOLDTOOTH_SAFE.iso = no new CLUTs, TEX 282,624).

## Next
1. In-game check of the skin (pick Sweet Tooth). Then: Gold Tooth's own wheels (Head-On wheel meshes / tire
   texture 0x87F40), damage states, Lost's mount points.
2. 12-Pak (HC_STOCK.BDD) as a new character: needs a free car slot / car-select entry, its own collision and
   weapon mounts (Head-On op5 mount list), and a full NGP instead of a skin.

## Harbor City fan build cars set aside (2026-10-26, Ark: 5 possible new characters)
Source: `Desktop/Twisted Metal Harbor City/game` (the Head-On / Lost engine, run from host files by its own
PCSX2, `TM.ELF`). Its roster strings: Axel, Stock Car, Pit Viper, Mr Grimm, Preacher, Roadkill, Old Pickup,
Semi, Sweet Tooth, Thumper, Spectre, Mr Slam, Outlaw (files AXEL STCAR PVIPER MRGRIM PREACH RKILL PICKUP SEMI
SWEET THUMP VETTE MRSLAM COPFOD). Copied to `TMB Decomp/hc_cars/CARS` + `/AICARS` (3.8 MB):
| Car | File | ngp | tex | ptr | note |
|---|---|---|---|---|---|
| Old Pickup | PICKUP.BDD | 116,624 | 156,528 | 94 | tiny pointer list: a near-static model (Ark: needs animating) |
| Pit Viper | PVIPER.BDD | 118,720 | 153,584 | 136 | also near-static |
| Thumper | THUMP.BDD | 310,048 | 124,912 | 852 | full car |
| Twister | TWIST.BDD | 253,824 | 92,400 | 822 | full car (not in this build's roster; AICARS has TWISTAI + OLDTWISTAI) |
| Outlaw 2 | COP.BDD | 314,640 | 97,264 | 818 | the full cop car; COPFOD.BDD (50 KB ngp) is the traffic cop the roster names |
Same BDD bundle format as the ETE disc above (ngp with Head-On node ops 20/26/27, tex, ptr), so the Gold Tooth /
12 Pak converters (tools/lost) are the starting point. Retail TMB donors for animation: Black's own cars.
