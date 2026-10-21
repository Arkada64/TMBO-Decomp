# TMB-Reloaded: agent handoff

Read this first, then `reference/wip/STATUS.md` (detailed progress log, lessons, open functions).
Both files live in the `main` branch of github.com/Arkada64/TMB-Reloaded (private).

## The project
Preservation + modding of Twisted Metal: Black (retail, SCUS-97101) and Twisted Metal: Black
Online (SCUS-97196), PS2. Personal project, not distributed. The owner (Ark) has legal discs.

End goal: **one package with single-player and online**, multiplayer moved to **Steam** (lobbies,
invites, P2P), plus online co-op, an AI overhaul, and single-player maps/features in online.

### Decisions already made (don't relitigate)
- Decomp path (not binary patching), so the game can be modded.
- Lobby host is the session owner, like the original. P2P, client-side hit detection.
- **Don't byte-match code that will be replaced**: Sony SDK, Medius/DME, PS2 hardware
  (GS/VU1, IOP sound, pad, memcard, CD) and the network adapter setup. Leave it as asm.
- Leaning **retail as the base**: online's menus are a different system (retail `tmb/ui` is
  1% shared with online; `shell`/`shelloverlays` ~18%), and online's Medius lobby screens get
  replaced by Steam screens anyway. Retail keeps the full single-player menu system.
- Near-term Steam route: run in PCSX2 with the emulated network adapter; our own lobby code
  in the game talks to a small PC-side helper that uses Steam. Native PC port is long-term.
- Never commit disc images, extracted asm, assets, build output, or the SN compiler
  (all already in `.gitignore`). Credits are in `CREDITS.md`.
- Upstream (abelbriggs1/tmb_decomp) has no license and asks people not to port to other
  platforms yet. Repo is private for that reason; Ark will decide later about contacting them.

## Work split between accounts
| | Account 1 (online side) | Account 2 (retail side): **you, if you're the second account** |
|---|---|---|
| Repo dir | `~/tmbo_decomp` | `~/tmb_decomp` |
| Branch | `online` -> pushed as `main` | `retail` -> pushed as `retail` |
| Focus | net.c, Medius replacement, permuter/fixup runs on online | Retail pipeline, then `tmb/ui`, `shell`, `shelloverlays`, `hud`, then data tools |

Don't edit the other account's repo dir. Both run on Ark's PC, so heavy jobs (permuter,
fixup) compete for CPU: check `pgrep -af "perm_run|fixup|apply_fix"` before starting one, and
keep thread counts modest (`-j4`) if the other side is busy.

## Environment (Ark's PC)
- Windows + WSL Ubuntu 26.04; user `ark`. Claude reaches it through Desktop Commander
  (`start_process` with `shell: cmd`, command `wsl bash -lc "..."`).
- **Device calls time out at 60 s.** For anything longer, start it as its own process and
  poll its log with `sleep 50; tail ...`. A process started via start_process keeps running.
  `nohup ... &` inside `wsl bash -lc` gets killed when the call returns; don't use it.
- Staging folder: `C:\Users\Ark\Desktop\TMB Decomp\` (= `/mnt/c/Users/Ark/Desktop/TMB Decomp/`).
  Write scripts there, copy into the repo. `cmd.sh` = what Ark runs; `diag.sh` = what Claude runs.
- **Never rewrite a script while bash is still running it**: bash reads scripts
  incrementally and will run whatever lands past its read position.
- Python venv: `source .venv/bin/activate` in each repo. pycparser must stay 2.x (permuter).
- Git push: remote `reloaded` uses Windows Git Credential Manager (already signed in).
  Commit with `git -c user.name=tmbo -c user.email=tmbo@localhost commit --no-verify`.
- The auto-mode classifier has sometimes blocked running downloaded compilers/builds. If it
  does, write the command into `cmd.sh` and ask Ark to run it.

## Toolchains
- **Online** (SCUS-97196): SN Systems ProDG ee-gcc 2.95.3-114 (Windows .exe, from the
  decomp.me compilers release), `-O2 -G0`, assembled by SN too (`-Wa,-G8`) via `tools/sn_cc.sh`
  + `tools/sn_prep_asm.py`. Lives in `tools/compilers/` (gitignored: re-download if missing).
- **Retail** (SCUS-97101): Sony EE-GCC 2.9 (native Linux, tracked in `tools/ee-gcc2.9`),
  `-O2 -G8 -fno-exceptions` (see `tools/build_system/env.py`). Register saves use `sd`.
- Both: splat config needs `mips_abi_gpr: n32` (fixed locally in both repos).

## Online pipeline (in ~/tmbo_decomp/tools), all verified against the real ROM
| Tool | Does |
|---|---|
| `auto_m2c.py` | m2c drafts per file, with asm-label aliasing (`T X_sfx __asm__("X")`) so drafts never clash |
| `fast_match.py DRAFTS OUT [hdr]` | compiles each `//@@ NAME` block alone, compares to disc with relocs masked; `NEAR_OUT` dumps near misses |
| `batch_try.py SRC BLOCKS` | puts blocks into the real build one at a time, keeps byte-identical ones |
| `auto_all.py` | resumable whole-project auto pass, commits per file |
| `perm_run.py [MAXD SECS MAXF THR]` | decomp-permuter on near misses; `RETRY=1` re-applies saved score-0 outputs |
| `fixup.py` + `apply_fix.sh` | rewrites drafts for m2c's byte-vs-element pointer arithmetic and dropped leading args |
| `showdiff.py NAME` | target vs ours instruction diff for a permuter job dir |
| `match_versions.py`, `reference/match/*.csv` | retail<->online function mapping (73% of retail bytes found in online) |

Hard rules: always verify with `rm -f build/*.rom; ninja && cmp` (a failed ninja once left a
stale ROM and produced false "matches"). `M2C_FIELD(expr, type, off)` takes a POINTER type.

## Account 2: retail plan, in order
1. **Branch + baseline.** In `~/tmb_decomp`: `git checkout -b retail` (keep the local n32 yaml
   fix; discard `config/US/report.json` noise), confirm `ninja` gives a byte-identical ROM,
   push `git push reloaded retail`. Retail is barely decompiled upstream: only `combo.cpp`,
   `font.cpp`, `mathf.cpp` are C; ~241 files are asm.
2. **Port the pipeline.** Copy the online tools over and swap the compile step to
   `tools/ee-gcc2.9/bin/ee-gcc -c -O2 -G8 -fno-exceptions` (no SN prep, no `-G0`/gp tricks;
   check how upstream's ninja rule assembles). Retail is C++ ("C with classes"): many names are
   mangled, and `.cpp` vs `.c` matters for mangling. Get `fast_match` reproducing one of
   upstream's existing matches before trusting it.
3. **Function porter.** For functions shared with online that account 1 has already matched,
   adapt the online C to retail (same logic, different compiler) and verify. Free matches.
4. **UI first:** `tmb/ui` (64 KB), `tmb/shell`, `tmb/shelloverlays`, `tmb/hud`, `tmb/texm`.
   Goal: the multiplayer menu (split-screen setup) in readable C, so new entries
   (Online / Steam lobby) can be added. Name things as you learn them (`symbol_addrs.txt`).
5. **Data tools** (menu text, layouts and fonts are game data, not code): learn the archive
   formats from the now-decompiled loader code, then write extract/repack, a PS2 texture <-> PNG
   converter, and a string-table editor. Finally a disc builder that rebuilds a playable image
   from Ark's own disc + our modified ELF/data (nothing copyrighted stored or shared).

## Account 1: online plan, in order
1. Finish permuter run 3 (`logs/perm_run3.txt`), re-rank after fixup (`rm logs/perm/near.json`).
2. net.c by hand (176 left): `netSendGameEvent` (unsplit global load), `func_00163DC8`
   (`$at` macro stores), `func_00164240` (branch layout), `func_00165998`/`func_00165BA8`
   (reversed compare). Protocol notes: https://claude.ai/code/artifact/296d6d5f-8975-4c20-8b4d-f76f27e07f65
3. Version diff for the merge: which online-only systems retail needs (net layer + hooks).
4. Medius/DME replacement design: lobby protocol to the PC-side Steam helper.

## Feature notes (from analysis so far)
- **Traffic + pedestrians online (wanted).** "Fodder" = civilian traffic cars (FodderDriver,
  TrafficDirector, HighwayDirector). Network sync for them was built: `NetFodder` (44 bytes),
  `netFodderUpdateCB` registered in `netInitDme`. Pedestrians (PedWorldManager, Pedestrian,
  AttractPed: stander/runner/guard/skater) are in the online build, `PedWorldManager::init`
  runs unconditionally at level load (in func_00137E08), and the online disc has `.PED`
  placement files for every level incl. DEATH1-7, MINICITY, MINIBURB, JUNK2, ROOFTOP2.
  Neither shows up in online play, so both are switched off downstream of init. Tasks:
  find the switches; peds have no network object, so add one modelled on NetFodder
  (host-driven) or keep them local-only; decode `.PED` to add peds to more places.
- **Balance toggle (wanted).** Retail vs online car setups selectable; lobby setting owned by
  the host (input-replicated physics must agree on every peer). Differences concentrated in
  `tmb/vehicle` (42% shared), `rigidbody` (29%), `pickup` (35%). First task: a diff tool
  comparing matched C of both builds.
- **AI overhaul.** Vehicle methods in `ai.c`: `aiPerform` state machine (hunt/bait/flee/snipe/
  pickup), weapon choice, fairness gate `aiIsPlayerLookingAtAIEnoughForAIToShoot`,
  `aiSetAggressiveness`; movement via per-level attractor-point waypoint graphs
  (`attracti.c`, `driver.c`). In co-op the host runs AI and sends it as NetVehicle.
- **Ported names have confidence levels** (`reference/match/mapping.csv` `method`): exact/
  masked/strings/callgraph are solid; fuzzy is good; order/global_fuzzy (~490) are hints only.

## Reporting
Update `reference/wip/STATUS.md` at the end of each session (what was done, counts, what's
next), commit, push. Ark mostly watches and pastes outputs; keep him informed briefly.
