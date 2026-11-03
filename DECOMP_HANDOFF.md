# TMB decomp: handoff for the next agent (2026-11-03)

You are picking up the **Twisted Metal: Black Online decomp** (PS2, SCUS-97196) for Ark, the owner. This file is
self-contained; the older `HANDOFF.md` has background (toolchains, matching pipeline, account split) and is still
correct on those points.

## Goal (decided by Ark, 2026-10-31)
**Working C for a native PC port of TMB itself.** Every function of the game as compilable C. It does **not**
have to byte-match the original. Byte-matching (permuter runs) is no longer the goal. Order:
1. As many functions as possible run as C inside the PS2 build (`-DNON_MATCHING`) without breaking the game.
2. Then strip the PS2 hardware layers (GS/VU1 rendering, IOP sound, pad, memory card, CD, Medius network) behind
   interfaces, and build for PC.
(A separate project, "Twisted Engine", reimplements the engine in Bevy. That is not this job; see BEVY_HANDOFF.md.)

## Rules from Ark
- He owns legal discs. **Never commit or share game data**: disc images, extracted asm, build output, compilers
  are all already in `.gitignore`. The repo (github.com/Arkada64/TMB-Reloaded) is **private**.
- **Keep it cheap**: he is on a limited plan. No big multi-agent runs; long jobs run on his PC unattended and you
  read the log afterwards.
- **Ask before launching PCSX2** (boot tests). It opens a window on his desktop. Runs must be muted and out of
  the way. Compile-only work needs no permission.
- **Don't bloat his SSD**: no piles of build copies or savestates. Superseded files go to `D:\TMB Decomp\_to_delete`
  (never delete permanently).
- Commit and push when a step is done. Commit with
  `git -c user.name=tmbo -c user.email=tmbo@localhost commit --no-verify`.
- Short plain reports. He prefers working through a block of work, not check-ins every few minutes.

## Where things are (Ark's PC: Windows + WSL Ubuntu, user `ark`)
| What | Where |
|---|---|
| Online decomp repo | WSL `~/tmbo_decomp` (remote `reloaded` = GitHub, push branch `online` as `main`). Its local branch is behind GitHub `main` (mod commits were pushed from elsewhere): `git fetch reloaded` before relying on `tools/` |
| Retail decomp repo | WSL `~/tmb_decomp` (branch `retail`), 1,768 functions still asm. Not the focus now |
| Staging folder | `D:\TMB Decomp` = WSL `/mnt/d/TMB Decomp`. `cloud\in` = scripts to run, `cloud\out` = their logs |
| Mod sources the build includes | `D:\TMB Decomp\mods` (+ `apply_mods.py`, `build_shiftable.sh`) |
| Test outputs | `D:\TMB Decomp\test` (`NM_TEST.ELF` = the working-C build) |
| Release mod build / emulator | `D:\TMBR` (`game\TMBR.iso`, `emulator\`, log `emulator\logs\emulog.txt`) |
| Compilers | `~/tmbo_decomp/tools/compilers/ee-gcc2.95.3-114` (SN ProDG, `-O2 -G0`, see HANDOFF.md) |

Folders moved from `C:\Users\Ark\Desktop` to `D:` on 2026-10-29. Some scripts in `tools/` still say
`/mnt/c/Users/Ark/Desktop/...`: replace it with `/mnt/d/...` when you use them (the scripts at the top level of
`D:\TMB Decomp` were already fixed).

## Current state (status run 2026-10-31, `D:\TMB Decomp\cloud\out\nm_go.txt`)
Online: 2,009 functions still `INCLUDE_ASM` in `src/`.

| | functions |
|---|---|
| **in C** in the working-C build (m2c draft or hand-written, compiles in its file) | **810** |
| no draft (m2c failed or emitted `M2C_ERROR`) | 417 |
| draft does not compile on its own | 480 |
| compiles alone but breaks the whole file (dropped) | 233 |
| kept asm on purpose (mod hooks, hand `*Asm` routines, `logs/nm_skip.txt`) | 69 |

The normal build stayed byte-identical and `NM_TEST.ELF` built. **Not yet boot-tested** in this state (last boot
tests were 2026-10-24/25, with fewer functions).

## The working-C pipeline (all in `tools/`, read `tools/nm/README.md` first)
- `nm_apply.py`: puts each compiling m2c draft (from `logs/auto/*.drafts.c`) into the source as
  `#ifdef NON_MATCHING <C> #else INCLUDE_ASM(...) #endif`. Hand-written C in `tools/nm/hand/<src_dir_file>.c`
  (`//@@ NAME` blocks) is tried first. `tools/nm/bytefix.py` fixes m2c's byte-offset pointer arithmetic.
  `NM_SKIP=a,b` / `logs/nm_skip.txt` keep known-bad drafts as asm. Writes `logs/nm/summary.json`.
- `nm_build.sh`: private copy in `~/nmhome/tmbo_decomp`, normal build must stay byte-identical, then the
  shiftable build with the mods and `-DNON_MATCHING` -> `test/NM_TEST.ELF`.
- `nm_ld.py`: alignment-safe link. C objects keep their size or grow in 0x80 steps; C float literals go after
  .sdata. Without this the game breaks (green bars, "no controller", exits to the BIOS).
- **One command for all of the above:** `tools/nm/pc/nm_go.sh` (copy in `D:\TMB Decomp\cloud\in\nm2\nm_go.sh`):
  fetches the newest tools from GitHub `main`, fixes paths, runs `nm_build.sh`, prints the TOTAL line. ~25 min,
  no PCSX2. Run it in WSL as its own process and read `cloud/out/nm_go.txt`.
- **Boot test** (needs Ark's OK): `tools/nm/pc/nm_test.sh` (build + quick-boot a match via `tools/qb/qbrun.py`),
  `nm_loop.sh` (repeat; a fault inside a C function puts it on the skip list), `night.sh` (unattended bisect of
  boot failures), `stopall.sh`. A fault's pc is the start of the recompiled block: the function is right, the
  instruction is not. `tools/nm/pc/exittrap.py` / `exitwho.py` name the function behind an exit to the BIOS.
  These scripts still carry `/mnt/c/Users/Ark/Desktop` paths and `cloud/in/...` locations: update them to D:
  and to `tools/...` before use. The emulator is now `D:\TMBR\emulator` (qbrun.py points at
  `C:\Users\Ark\Desktop\TMBO Ready2Play Edition`: check which one exists).
- **Function bench** (best tool for correctness; no long boots): `tools/nm/bench/README.md`. One boot keeps a
  mid-match savestate (`bench2_go.sh`), every draft is compiled apart into an image above 32 MB, then
  `run_frames.py` runs game frames in a small EE interpreter and compares each C function against the original
  asm from the same state. FAIL = crashes or writes different memory (reliable). First run caught 9 bad drafts.

## Next steps, in order
1. **Raise the count, compile-only (no permission needed):**
   - the 480 non-compiling drafts: group the compiler errors (`nm_apply` logs them per file in `logs/nm/`), fix
     the common m2c patterns in a tool (as `bytefix.py` did), hand-fix the rest into `tools/nm/hand/`.
   - the 233 dropped in context: usually a draft's declarations clash with the file's (types, prototypes,
     aliases); same treatment.
   - the 417 without drafts: re-run m2c with better context (`M2C_CONTEXT`, `M2C_PROTOS`; see
     `tools/auto_m2c.py`). Where m2c gives up (vector / VU0 code in rendering files), write C by hand.
   Re-run `nm_go.sh` after each batch and report the new TOTAL.
2. **Correctness (with Ark's OK for the one boot):** bench snapshot, `run_frames.py`, fix every FAIL (hand C),
   then a boot test of `NM_TEST.ELF` (a match on Suburbs or Snowy Roads, look for faults / BIOS exits).
3. When most game code is C: plan the PC layer (which files are PS2 hardware, see STATUS.md "Don't byte-match
   code that will be replaced" list) with Ark before writing it.

## Useful background
- `reference/wip/STATUS.md` on the PC repo: progress log and lessons (always verify with
  `rm -f build/*.rom; ninja && cmp`: a failed ninja once left a stale ROM and gave false matches).
- `reference/ai_decomp/`: readable m2c C with named structs for the AI / driver / game manager.
  `reference/wip/*.md`: notes on vehicles, cars, specials, traffic, peds, nav, team modes.
- `mods/*.c`: the mod (TMB Reloaded) shows how most game systems behave at runtime.
