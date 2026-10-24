# Twisted Metal: Lost / Harbor City maps (Head-On ETE disc): prep survey (2026-10-23)

Tools: tools/lost/levels/ (hotx.py = Head-On level walk with transforms, hotop.py = top-down render of the
render meshes, horender.py, howalk.py). Bundles extracted from `/LVL/*.BDD` with TMB Decomp/cloud/in/hcext.py.

## The five maps (exe file table order = Lost menu order)
| file | name | bundle | ngp | tex | notes |
|---|---|---|---|---|---|
| HC_SC | Carnival of Darkness | 7.1 MB | 4.4 MB | 2.6 MB | big top tent in the middle; has HLI |
| HC_SU | Suburban Terror | 8.6 MB | 6.3 MB | 2.2 MB | cut-down Harbor City Suburbs |
| HC_GD | **City of the Dead** | 12.6 MB | 7.7 MB | **4.8 MB** | from Ghetto + Downtown; code-only in Head-On |
| HC_ND | Death Port | 3.3 MB | 1.8 MB | 1.4 MB | ships from Docks; 336 traffic/ped points (FPT) |
| HC_ST | Stadium Slaughter | 6.4 MB | 4.1 MB | 2.2 MB | stadium + a station/yard beside it |
TMB limits per level: NGP 13.1 MB (all fit), TEX ~2.6 MB as TMB stores it. Head-On stores textures as the
PSMCT32 upload (bigger than TMB's linear T8/T4 + CLUTs), so the converted sizes will be smaller; HC_GD may still
need downsizing.

## City of the Dead
- Largest texture set of any Head-On vehicle level by 1.2 MB (next: MONACO 3.6 MB; only the on-foot ASYLUM /
  IMPOUND are bigger). Most likely cause of the reported crash: texture/VRAM budget. Unconfirmed.
- Also the most "unusual" node use: 18 op8 nodes (others <= 7), 2 op24. Tree walks cleanly, no bad pointers.
- Has PTS (91), PKP (37 pickups, all 9 types), GPS (7), FPT (46); no HLI.

## Formats
- Level ngp: Head-On node tree (base 0, pointers = file offsets). Entry points: op1 root, op1 extra, op12
  collision grid, op6. Layouts confirmed so far: op1/2/3/4/5/6/13/19/20 (tools/lost notes), op7 = group with
  sphere (count u16 +0xC, kids +0x20), op17 = (count u16 +0x28, kids +0x2C), op18 = **translate + scale**
  (+0x10 xyz, +0x20 scale xyz, count u16 +8, kids +0x2C) - not TMB's BSP node, op31 = one child at +0x1C.
  Unknown: op8, op10, op14 (emitter?), op24, op27.
- Render meshes: Head-On op0 (decoded already, homesh.py). Walk with transforms reaches 20-50% of the mesh
  packets; the rest are other LODs / damage states / under op8. Top-down renders: hc_*_top.png.
- **Collision** (different from TMB's BSP + terrain):
  - op12 entry = uniform grid: +4 u16 cols, rows; +8 cell size (100.0), +0xC 1/cell; +0x10 bounds (4 floats);
    +0x20 ptr item list, +0x24 ptr object table; then cols*rows u32 cells = start << 10 | count.
    Object table starts with bounds then pointers to tree nodes.
  - op26 = quantized collision piece: +8 end ptr, +0xC header ptr {ptr, u16 a, u16 b, s32 origin xyz, f32 scale
    (1/512 or 1/1024)}, then s16 xyz vertices and index data. Not fully decoded (vertex/face split).
  - For TMB the game needs op18 BSP trees + op13 terrain: conversion = build BSP trees from these polygons
    (offline, Python). New code; the route-map tools already read TMB BSPs so they can check the result.
- **Point files**: same family as TMB (header `xx 20 vv vv` + counts).
  - PKP: 16-byte header, 64-byte records {xyz, ..., u32 type @+0x2C}; types 0-8. TMB PKP: 8-byte header,
    20-byte records {xyz, 0, u32 type}. Direct conversion once the weapon-type numbering is mapped.
  - PTS (v1607): 32-byte records = AI path graph (xyz + u16 links). Not needed: our route maps replace it.
  - GPS: boxes (xyz + size) = zones. FPT: fodder (traffic / ped) points. HLI: TMB has it too.
  - Spawn points: not located yet (TMB: check where the game reads them; likely PTS/HLI kinds).

## Plan per map
1. Finish the walk (op8 etc.) so every mesh is placed; convert meshes (tmbenc) + textures (textconv) into a TMB
   NGP/TEX/RTX/PTR (mkpack-style relocation for base 0x980000).
2. Collision: decode op26 fully, build TMB BSP trees (+ terrain if useful), verify with navgen.
3. Points: pickups (type map), spawns, then a route map (navall) from the converted collision.
4. Slot: swap into an existing level for testing (like the DEATH7 disc), later new level slots.

## Stage 1 (2026-10-23): render + textures + pickups -> TMB files (tools/lost/levels/)
- `lvbuild.py HC_xx.BDD OUTDIR NAME [scale]` -> NAME.NGP/.PTR/.TEX/.RTX (raw, base 0x980000) + NAME.PKP.
  Scale 1.15 (Head-On cars are ~1/1.15 of TMB's, so the maps are scaled up to match).
- Walk (hotx.py): + op7 (scene child +4, list at +0x20; +8 = op8, no meshes), op17 / op18 layouts, and the
  **world-object table**: records {1, 0, node (op3), 0, 4x4 matrix} near the end of the ngp = extra roots (filled
  the building holes on Suburban Terror). Guards: known ops only, child counts <= 512, sane matrices, depth 60.
  First LOD / first damage state only. Placed meshes: SU 1815, GD 1106, SC 1216, ST 861, ND 448.
- Textures (levtex.py): records = texture, its mip levels (same key), then its CLUT; pixels decoded page by page
  (any size). Only textures used by placed meshes are kept; all five fit without downsizing:
  GD 2.18 MB / 582 CLUT blocks, SC 1.79 MB / 498, SU 1.81 MB / 443, ST 1.48 MB / 303, ND 0.58 MB / 150
  (budgets 2.65 MB / 1041 blocks). City of the Dead's full set (452 textures, 4.3 MB) is what doesn't fit.
- Meshes: world transform baked into the vertices, then meshconv.hierobject (same encoder as Gold Tooth / 12 Pak);
  grouped by 1200-unit tiles (op1 groups with spheres) under one op1 root = the only entry point for now.
- Checks: lvcheck.py (TMB-decoder walk, PTR slots in range, every texture pair's id exists) and lvtexprev.py
  (textured top view from the TMB files alone). All five pass.
- Pickups (pkpconv.py): Head-On list 0 MG, 1 fire, 2 homing, 3 swarmer, 4 ricochet, 5 power, 6 health 30%,
  7 environment, 8 remote bomb, 9 full health -> TMB online PKP {type, xyz, w} with 1 fire, 2 homing, 3 skill
  weapon slot, 5 ricochet, 6 power, 7/8 health kinds, 9 slot 8; swarmer -> homing, remote bomb -> skill weapon.
  Unverified: TMB 0 (MG?), 7 vs 8 (partial / full health), 9 (environment?).

## Stage 2 (next): collision + the two other entry points
TMB levels have 3 entry points: op1 (render), **op15** (grid: cell 100, bounds - the counterpart of Head-On's
op12) and **op7** (object list). Need: Head-On op26 pieces decoded -> TMB op18 BSP trees (+ op13 terrain?),
op15 grid + op7 list built, spawn points found, then a test disc (swap into a level slot) and route maps.

## Stage 2 (2026-10-23): collision, donor assets, spawns, test disc (first in-game test pending)
- Head-On collision = op12 grid entry's object table: records {aabb, 0, 0xffff tt nn, nn node pointers root..leaf}
  (hocol.collision_objects); the leaf is an op26 piece {verts s16 before hdr; hdr {vptr, u16 ntri, u16 nnode,
  s32 origin xyz, f32 scale}; nnode x 14-byte BVH nodes; ntri x {u8 i0, i1, i2, flags}}, world = (v + origin) *
  scale, placed by composing the path's transforms (op3 / op4 / op18 / op13). Includes the ground.
- Winding is inconsistent: lvcol.orient makes it consistent per connected part; closed parts face out, open
  parts face up, mostly-vertical open parts are 4-unit double-sided slabs. Solid = behind a face, 30 deep.
- TMB collision = op18 nodes in the render tree under the callback-id-1 node: op18 {0x12, r^2, r, root, centre};
  BSP node 0x20 {front, back, 0, u16 matF, u16 matB, plane}, null child = leaf, 0x200 empty, 9 solid. One op18
  per piece, built from the piece's face planes + prism side / back planes, leaves labelled by sample points.
  ~1 node per triangle (SU 70K nodes = 2.2 MB).
- Level DB callback ids (online func_00127650): 1 = arena (render + collision, func_00242F30), 2 = 4 x
  func_00242FE0, 5 = tdSetEpNode, 13 = g+0x97B40, 14 = extra collision groups (op18 only), 0x20-0x400 static
  vehicles, 5000+ pickup models, 4000+ weapons, 7000-10620 effects / parts. op7 entry = op25 animated objects.
- **op15 entry = the collision grid** (hdColGrid_hdhat; the car height / collision lookup): header
  {0xf, s16 cols, f32 cell 100, minx, miny, maxx, maxy, ptr}, then cols x rows cell pointers INLINE from +0x20
  (rows from the bounds). A cell -> linked entries {next, path}; path {0, n, n node pointers from entry 0's root
  down to an op1 that holds exactly one op18}. The handler walks the path applying op3 / op4 / op6 / op31 / op17
  / op25 transforms and op1 sphere tests (skipped if group flags & 0xC). First test: without it every car fell
  through (and a bogus grid crashed in hdColGrid at 0x20E2CC).
- TMB BSP convention (all retail levels): front leaf always 0x200, back leaf always a material; the material
  fields are filled on internal children too. lvcol.normalize flips nodes to match.
- Donor: DEATH4. Its arena meshes are compacted out (1.08 MB), the id-1 node points at our tree, id-14 nodes'
  ids cleared, op15 resized, arena-only textures dropped (28), ours appended (ids / CLUT blocks after the donor's;
  identical palettes shared; textures halved / 16-colour if over budget).
- Spawns: start / respawn points are the PTS attractor points (gameCheckStartPoint -> random linked neighbour).
  ptsconv.py keeps the donor PTS links and moves every used point onto a Head-On AI path point; PUP likewise.
- Disc: tools/mklost.sh -> TMBR_LOST.iso: Elevators = City of the Dead, Snowy Roads = Suburban Terror,
  Power Plant = Carnival of Darkness, Dogpound = Death Port, Sewers = Stadium Slaughter. DEATH1-5 route maps moved
  to 0x1524000 (NGP tail; all five merged NGP + PTR end below 0x1460000).
