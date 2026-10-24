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
