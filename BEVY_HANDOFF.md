# TMB in Bevy: handoff (2026-10-29)

New goal from Ark: **reimplement the Twisted Metal: Black engine in Bevy for PC**, loading the game's data from his
own disc, rebuilt a piece at a time, with room later for content from other Twisted Metal games. The base is
the **Bevy codebase of Ark's own game Concrete Eden** (formerly Full Metal Carnage), which already has car
combat, AI with a navmesh, and Steam networking. TMB's data gets loaded into that engine; Concrete Eden's
systems are reused where they fit.

This file covers what the TMB side has already worked out (formats, game logic, tools, lessons) so the new chat
does not redo it. Everything below points at files in this repo (github.com/Arkada64/TMB-Reloaded, private,
branch `main`) or on Ark's PC.

---

## 1. Ground rules (from Ark, keep them)
- **Ark owns legal discs.** Never commit or distribute game data (ISOs, extracted files, converted assets). The
  engine reads the data from Ark's disc or his extracted copy at runtime or through a local import step.
- **Upstream decomp (abelbriggs1/tmb_decomp) has no license and asks people not to port to other platforms.**
  That is why this repo is private. For the Bevy engine: use the decomp and our notes to *understand* formats
  and behaviour, and write new Rust code. Don't paste decompiled C or asm into the engine.
- **Budget:** Ark is on a limited weekly plan. Keep work cheap: few or no subagents, no long verification runs.
- **Ark tests, not you.** No automated play-test runs on his PC; build, hand him the build, read his logs after.
- **No SSD bloat:** don't leave large intermediate files lying around; put superseded files in a `_to_delete`
  folder (Ark's rule: never delete permanently, move to `_to_delete`).
- **No black voids:** Ark has kenophobia (fear of empty spaces). Debug views, map previews and the default
  clear colour must not be black or empty-looking; use a mid-tone (e.g. a soft slate) for "nothing here".
- **Commit and push** when a step is done.
- Concrete Eden's own direction (dark, oppressive art, high frame rate, 180 Hz monitor, Steam-invite-only
  joining, 12 players) is Ark's. For TMB in Bevy, ask before adopting it; TMB's own look and rules come first.

## 2. Where things are
| What | Where |
|---|---|
| This repo (decomp + mod + notes) | github.com/Arkada64/TMB-Reloaded (`main`). Read `HANDOFF.md` (decomp side) and `reference/wip/*.md` |
| Concrete Eden (Bevy) | On Ark's PC; its HTML predecessor is github.com/Arkada64/FMC-Prototype. **Ask Ark for the Bevy repo / folder.** The Bevy to-do list lives on his PC |
| Decomp build folder | `D:\TMB Decomp` (WSL: `/mnt/d/TMB Decomp`). Disc tools (`isols.py`, `mkdisc.py`, `ngp.py`, `ngpdb.py`, `mkpack.py`...) live at its top level; copies of some are in `tools/shift/` here |
| Base online disc image | `D:\TMB Decomp\packs\TMBO_base.iso` (Twisted Metal: Black Online, SCUS-97196) |
| Retail disc | Ark's retail Twisted Metal: Black (SCUS-97101); the decomp's retail side is in `~/tmb_decomp` on his WSL |
| Release mod build | `D:\TMBR` (game ISO `game\TMBR.iso`, emulator, `emulator\logs\emulog.txt`) |
| Head-On ETE disc notes | `reference/wip/HEADON_ETE.md` (TM: Lost / Harbor City content is the `HC_*` files there) |

PC access from a cloud session: Ark's PC is reached through the Claude desktop app (device bridge + Desktop
Commander). Long jobs: start them as their own process (calls time out after 60 s) and poll a log file.

## 3. The data (what's known)
Disc layout (online): level files at the root (`<LEVEL>.NGP/.PTR/.TEX/.RTX`), point files in `\PTS\`
(`<LEVEL>.PTS/.PUP/.PKP/.HPT/.PED`), cars in `\PCAR\` (player) and `\ACAR\` (AI versions), `\SHELL\` (menus),
`\MOV\*.PSS` (videos). Some files are inside a zip-like container: local header `IE\x03\x04`, PK central
directory (`tools/lost/iezip.py`). ISO reading: `isols.py` (on the PC, `D:\TMB Decomp`).

Level indexes (online, used everywhere in the mod): 0 SUBURB, 1 JUNKYARD, 2 FREEWAY, 3 PRISON, 4 ROOFTOP,
5 CITY, 6 LOOP, 7-12 DEATH1-DEATH6, 13 ROOFTOP2, 14 STADIUM, 15 SHIP, 16 ASYLUM, 17 MINICITY, 18 MINIBURB,
19 JUNK2, 20 ROOFBOSS. (Ark's names: ROOFTOP = Skyscrapers, ROOFTOP2 = Mini Skyscrapers, ROOFBOSS = Warhawk's
roof, PRISON = Prison Passage, SHIP = Prison Ship, ASYLUM = Asylum Hall. Ask him for the rest.)

### NGP (the scene database: levels and cars)
- Stored as if loaded at **0x980000**: every pointer in the file is `0x980000 + file offset` (Head-On's BDD
  bundles use base 0). Header: `u32 numEntryPts`, then `numEntryPts` node pointers.
- Node word 0 (HierHead): `op = w & 0x3F`, `id2 = (w >> 7) & 0x7FF`, `id1 = w >> 18`.
- Child layouts per op: `tools/lost/tmbtree_walk.py` and `tools/shift/ngptrav.py` (an exact port of the game's
  `dbsTraverse`). Known ops: 0 mesh (HierObject), 1 group (count u16 at +8, children from +0x20),
  2 LOD (first child = closest), 3 translate, 4 transform matrix, 5 light, 6 switch, 7 animation,
  8 two-child node, 10 collision volume, 13 terrain heightfield, 17 bones, 18 BSP collision, 25 animation
  character, 30, 31 damage-state / LOD set.
- Level db ids (what the loader does with an entry point by id): 1-1024 vehicles, 1025-2999 traffic ("fodder"),
  3000-3999 peds, 4000+ weapons (`reference/wip/PACKS.md`).
- **Meshes (op 0)** are PS2 VIF/GIF packets: vertex pool unpacked as V3-32 floats, then strips with a GIF tag,
  V4-8 normal + vertex index, V4-8 RGBA, V2-16 UV. Decoder: `tools/lost/tmbmesh.py` / `tmbdec2.py`; encoder
  `tmbenc.py`. Textured previews: `tmbprev.py`; a car drawn at rest with weapons, lights and damage state 0:
  `carview.py`.
- **Collision** for a level: walk the hierarchy with transforms and collect op 18 (BSP), op 10 (volumes) and
  op 13 (terrain heightfields): `tools/nav/navgen.py`. Walkable-surface extraction and a route map built from it:
  `tools/nav/navbuild.py`, `navall.py`.

### PTR, TEX, RTX (textures)
- `.PTR`: `[N, N pointer slots] [M, M pairs (texture-id u16 slot, GS TEX0 word slot)]`: which mesh uses which
  texture.
- `.TEX` / `.RTX`: header `u32 nclass, u32 recq (first record, in qwords), nclass x (count, blocksize)`, then
  records `u32 sizew, u32 key, u64 gs` (id bits 0-15, PSM 32-37, tw 40-43, th 44-47, class 59-63) + payload.
  The last record has `sizew 0` and runs to the end of the file. TEX holds linear PSMT8 / PSMT4 pixels; RTX holds
  the CLUTs (palettes). `tools/lost/texrec.py`, `textconv.py`, `gsmem.py` (GS swizzle). There is also an HD texture
  pack mapping in `tools/hdpack/` (PCSX2 texture dump hashes to files).

### Point files (`\PTS\`)
- `.PTS` = **attractor points**, the waypoint graph the game's AI drives on, also used for spawn points: records of
  32 bytes `float x, y, z, w; u16 links[6] (0xFFFF = none), u16 kind, u16 nlinks`, ending at an all-zero
  record. Parser: `tools/peds/pts.py`. Links are mostly two-way; one-way links are drops.
- `.PED` = pedestrian spawn groups (`tools/peds/pedfile.py`, `mkped.py`). `.PUP` / `.PKP` / `.HPT` = pickups and
  related point lists (format partly known, see the mod's `packs.c` / `lostslots.c`).
- Overlay of a level's attractor graph over its drivable surfaces: `tools/nav/attr_overlay.py`.

### Cars
- Each car: `<CODE>.NGP/.PTR/.TEX/.RTX` in `\PCAR\` and `\ACAR\`. Driving stats are **hard-coded per car type**
  in the game (`vehicleInitDynamics`), not in the files: table and offsets in
  `reference/wip/CAR_STATS_SPECIALS.md` (also specials, 2-wheel vs 4-wheel physics).
- Weapon mounts, lights and the damage-state switches inside a car NGP: `reference/wip/HC_MOUNTS.md`.
- Head-On / TM: Lost / Harbor City cars and levels (`.BDD` bundles = the same TMB file kinds, base 0):
  `reference/wip/HEADON_ETE.md`, converters in `tools/lost/` (`hcbuild.py`, `meshconv.py`, `textconv.py`).

### Traffic ("fodder" cars): kept, for the engine
The mod removed traffic on 2026-10-28 (g176), but nothing was deleted: the code and tools are all still here.
- `mods/_to_delete/traffic.c`, `traffic.s`, `traffic_nodes.c`: the working port of retail's traffic (spawn, drive
  along lanes, draw, take weapon hits, respawn after destruction, host-to-client sync). The header comment
  explains the whole system; `traffic_nodes.c` lists each level's traffic model nodes.
- `reference/wip/TRAFFIC_PLAN.md`: where retail had traffic (CITY, FREEWAY, LOOP, MINIBURB, MINICITY, SUBURB; 72
  model ids per level, Freeway 60), the game functions involved (FodderDriver, TrafficDirector,
  HighwayDirector, InitializeFodderCars, SetFodderCar, AddFodder), and how the cars are run each frame.
- **Models**: the traffic car models are in the level NGP itself (db ids 1025-2999). Online removed SUBURB's,
  so take SUBURB from the retail disc (the mod rebuilt them as a pack: `tools/shift/fodpack.py`, `fodnodes.py`).
- **Routes**: street cars drive on a second attractor-point set, the "street points" (lanes), which the game
  keeps at `game + 0x34890` after level load. `FodderDriver::init` reads its lanes from there. Freeway's highway
  cars are run by the TrafficDirector / HighwayDirector instead. Which disc file the street points come from still
  needs confirming (candidates in `\PTS\`, e.g. `.HPT`). Copies of the point files for the traffic maps are on
  Ark's PC in `D:\TMB Decomp\cloud\out\trafpts`.
- **Route traces**: a debug build (`TRAFFIC_TRACE 1` in traffic.c) logged every car's position every 0.5 s and every
  street point with its links. `tools/traffic/trafmap.py` draws them over the level's top view: the exact routes
  as the game drives them, checked for all 6 traffic maps on 2026-10-25.

## 4. Game logic already reverse-engineered
- **Bot AI**: `reference/wip/AI_ARCHITECTURE.md` (TheGame / Vehicle / AIBrain / Driver, one AI frame, think token,
  attack state machine, why bots only hunted humans) and `reference/wip/AI_NOTES.md`. Readable m2c C for every AI,
  driver and game-manager function with named struct fields: `reference/ai_decomp/` (`fields.py`: "sure" = confirmed).
  Driver modes: 2 hunt, 3 flee, 4 cruise, 5 hunt the nearest human.
- **Vehicle struct** offsets used by the mod (0x31B0 bytes per car in `TheGame`): position via `cs` (+0x2028)
  + 0x10, health +0x404, max health +0x3F0, kind +0x590 (1 human, 2 bot), brain +0x2014, driver +0x2018,
  owner type +0x20B4 (1 local, 2 remote player, 4 host bot), shield state byte +0x497. Many more in
  `reference/wip/vehicle_scope.md`, `vehicle_funcs.txt`.
- **Network** (online): message names and schema `reference/net_names.txt`, `reference/net_schema.json`; lobby
  options travel in the game-info object (bytes 0xC6 / 0xC7). Peer-to-peer, the lobby host owns the session,
  client-side hit detection.
- Team modes (cut in online, revived in the mod): `reference/wip/TEAM_MODES.md`. Car select limits:
  `CARSELECT_MORE.md`. Boss cars: `BOSS_CARIDS.md`.
- The mod's code (`mods/*.c`) is the best record of what each game system expects at runtime: `bots.c` (targeting,
  weapons, specials, turbo), `nav.c` / `navbake.c` (route maps, jump links), `skins.c` (extra cars, specials,
  kill feed), `teams.c`, `dmgreport.c`, `story.c` (Minion), `packs.c` (loading extra content at level load).

## 5. Lessons from the TMB Reloaded AI work (Oct 2026), for the Bevy AI
- The game's own AI drives only on its attractor graph. When a bot's spot has no link to its target's group, the
  hunt just waits in place: "sits until someone comes near". Cruise mode drives to a zone and parks there.
- A **route map built from the level collision** (walkable surfaces, wall margin, slopes over ~41 degrees cut,
  the largest connected part plus every part the attractor graph joins to it both ways) works well on ground maps.
  **Jump links** (attractor links that join separate route-map parts, followed straight at full speed with turbo)
  got bots onto the Freeway stadium, the Junkyard mound and other roofs.
- Free fight steering (orbiting, lining up, dodging, weaving) that ignores the ground drove bots into walls and off
  roofs. Any steering layer needs a ground check (a wall or drop ahead on the route map) and must never press
  reverse at a drop (in TMB the brake button is also reverse).
- Rooftop maps (Skyscrapers, Mini Skyscrapers, Warhawk's roof) never got stable bot driving; the last state was
  the game's own driving plus a rescue (a bot that falls is put back on a start point with -5 % health).
- What Ark wants from bots: player-like, aggressive, fighting each other and not only humans, constant weapon
  use (short missile bursts, no waiting for perfect line-ups), moving around the map (patrol when nothing is in
  range), unpredictable per car rather than scripted.
- Final mod state: build g189, commit `6c3c0f8` (simple driving + targeting + aggressive fire control + patrol
  on the route map). Notes in `TODO.md`.

## 6. Suggested first steps (confirm with Ark before starting)
1. Get the Concrete Eden Bevy repo from Ark and read its structure (crates, its AI / navmesh, physics, netcode).
2. **Import step** (a Rust tool or crate in that workspace): read the ISO (or Ark's extracted folder), unpack the IE
   containers, parse NGP + PTR + TEX + RTX into Bevy meshes and textures. Start with one level (JUNKYARD is small)
   and one car. Check against the Python tools above, which already decode all of it.
3. A level viewer in Bevy: static meshes, textures, a fly camera, a non-black background.
4. Collision from op 18 / op 10 / op 13 into the engine's physics; drive one car on it with TMB's stats.
5. Attractor points and the route map into Concrete Eden's navmesh / AI; then weapons, specials, HUD, networking.

## 7. Questions to ask Ark first
- Where is the Concrete Eden Bevy repo, and which parts of it should be reused as-is?
- Retail (SCUS-97101) or online (SCUS-97196) data as the base, or both?
- Import at build time (convert once to an engine format, kept local) or read the disc at runtime?
- What does the first playable milestone look like to him (one map, one car, bots)?
