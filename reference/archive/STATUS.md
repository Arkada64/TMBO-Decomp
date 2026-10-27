# Online decomp: where we left off (2026-10-20)

## Decisions (from the owner)
- Goal: PC port with Steam multiplayer (P2P, lobby owner hosts, client-side hit detection) plus retail
  single player, in one moddable package. Full decomp path (not recompilation).
- **Don't byte-match code that will be replaced in the port** (decided 2026-10-20). Leave it as
  INCLUDE_ASM (build stays byte-identical) and spend no matching effort on it:
  - Sony SDK libraries (sdk/*, libgraph, libpad, libmc, libcdvd, libmpeg, eekernel wrappers)
  - Medius / SCE-RT DME network stack (the `dme*` layer and below) -> replaced by Steamworks
  - PS2 hardware paths: GS/VU1 rendering and `.vutext` microcode, IOP/989snd sound, pad, memory card, CD/DVD I/O
  - Network adapter setup (NETCNF/DEV9/INET)
  Still match: game logic and Incog's own network module (object callbacks, event handlers, send wrappers),
  since those are kept and modded. When unsure whether a file is "replaced", ask the owner.

## Toolchain (solved)
- Online's game code: **SN Systems ProDG ee-gcc 2.95.3-114, `-O2 -G0`**, compiled AND assembled by SN
  (its assembler expands macros differently from GNU as; using GNU as caused mismatches).
- `tools/sn_cc.sh` is the build's C compiler: copies the file's INCLUDE_ASM .s files to a temp dir,
  `tools/sn_prep_asm.py` converts `%gp_rel(SYM)($gp)` back to `(SYM)` and adds `.extern SYM, 4`,
  then SN compiles + assembles with `-Wa,-G8` (C itself stays -G0). Section alignment reset to 8.
- Evidence: full SN toolchain gives exactly the right size and 240/241 functions of src/online/net.c
  matching the disc. `-mno-split-addresses` is wrong (194/241). Sony compilers and SN 2.95.3-136 never match.
- `tools/compiler_matrix.py`, `tools/try_variants.py` (variant testing; note it still uses GNU as).
- Compilers live in `tools/compilers/` (not in git; github.com/decompme/compilers, release "compilers").
- The assistant's sandbox blocks running these compilers; the user runs builds (`cmd.sh`) and pastes output.

## Matched in C (build byte-identical)
- `netGetMyClientIndex`, `netGetDmeTime`, `func_00174268`, `netMsgChatHandler` (early-return form)

## Latest (2026-10-20 evening)
- First full auto_all.py pass: 234 of 2,466 INCLUDE_ASM functions matched (9.5%), every one verified
  in the real build; 99 of 181 files gained nothing. 2,232 functions remain in C files as INCLUDE_ASM.
- Automation alone clears ~10%. Biggest levers next: (1) fix the draft compile errors m2c makes in
  gameplay code (incompatible types, pointer*int, float/pointer mixups) so more drafts reach the check;
  (2) assisted matching in batches (assistant writes C variants, tools/batch_try.py verifies);
  (3) the 11 rejected + 14 shared-rodata files.
- Re-run auto_all.py any time; it resumes on what is left (log: logs/auto_all.txt).
- Fixed M2C_FIELD (m2c passes the pointer type; old macro added a pointer level, breaking all float
  fields). Earlier matches use M2C_FIELD_V1 (old form) so their verified bytes are untouched.
  Draft compile errors fell 785 -> 437 of 1,834, but the second pass matched only 44 more:
  raw m2c tops out ~12-14% here. Total matched game functions ~335.
- NEXT: decomp-permuter (tools/decomp-permuter) on near misses ranked by differing instructions,
  run unattended with the SN toolchain, results verified by the real build.

## Progress
- 52 of 241 functions in src/online/net.c are matched C, all verified in the real build (commit ffd402a).
- 180 SN-compiled game files converted from asm to C (INCLUDE_ASM), build byte-identical (commit 8782b60).
  2,466 functions are INCLUDE_ASM across 181 C files, ready for auto_all.py.
  tools/plan_c_files.py picks eligible files (sq-saving game code, clean own .rodata); tools/convert_c.py
  converts them in groups and isolates failures. 11 rejected (stay asm, need hand rodata work): tmb/collis,
  tmb/combo, tmb/destruct, tmb/gastank, tmb/hud, tmb/ped, tmb/shelloverlays, tmb/hd, tmb/resetcom,
  tmb/zip, online/after_zip_83. 14 more were skipped for shared .rodata.
- m2c gives up often on rendering files (vector ops, e.g. tmb/drawc 7/8) and drafts in gameplay files
  fail to compile more often (~70% in ai/vehicle) - expected; cheap to skip.

## Automatic matching (tools/auto_m2c.py + tools/fast_match.py + tools/batch_try.py)
- auto_m2c.py: m2c draft per INCLUDE_ASM function. Feeds m2c a fixed copy of the .s (named registers,
  noreorder header), fills skipped leading args, and gives every declared symbol a private alias
  (`D_x_<suffix> __asm__("D_x")`, unprototyped function aliases) so drafts never clash in one file.
- fast_match.py: compiles each draft alone with the full SN toolchain and compares to the disc (~1.5 s each).
- batch_try.py: puts candidates into the real build one at a time; keeps only byte-identical ones.
- ALWAYS verify with a real build that succeeded: `rm -f build/*.rom; ninja && cmp ...`. A failed ninja
  leaves the old ROM behind and `cmp` alone reports a false match (this happened once; commits
  028b26d..f6ffa26 were reverted by bedcc3f).
- Restoring an older net.c needs `./configure.py distclean && ./configure.py generate` so the
  nonmatching .s files for its INCLUDE_ASM functions exist again.
- Tried and ruled out: `-mno-split-addresses` (breaks matched C), stack-buffer size variants, .sdata
  attributes (no effect). Remaining misses (fast_match tally): ~78 size mismatch, ~30 differ, ~49 don't
  compile, 31 where m2c gives up. Known pattern: some originals store globals via SN-assembler macro
  expansion (`lui $at`/`sw ...($at)`), which C compiled here doesn't reproduce yet (see func_00163DC8,
  netSendGameEvent). Comparison direction mistakes from m2c in func_00165998/func_00165BA8.
- Batch workflow: `python3 tools/batch_try.py src/online/net.c <file>` tries variants per function in the
  real build, keeps byte-identical ones, prints `>>` diffs for misses. "subcommand failed" = ninja's sha1
  check, i.e. a mismatch, not a compile error.

## Open (with hints from diffs, reference/wip/batch3.c)
- `netSendGameEvent`: logic right; the message-id global load is split (`lui v0` early) where the original
  has `lui a3`/`lw a3` back to back. Not a flag; a source-shape difference still to find.
- `func_00164240` (log append): original falls through to success and branches away on failure; ours is
  inverted -> try a result variable (`ret = 0; if (...) {...; ret = 1;} return ret;`) or `if (n >= 0x100) return 0;`.
- `func_0016D638` (RTime shutdown): only the register for the constant 4 (orig v1) and where `return 0`
  is set differ -> try `void` + separate caller-visible result, or a temp variable for 4.
- `func_001653D8` (callbacks): lui/addiu order differs -> try other assignment orders of cb.fn[0..3].

## Workflow
- Per function: write C -> `python3 tools/apply_c.py src/online/net.c <file>` -> `ninja` -> `cmp`.
- After a config or toolchain change: `./configure.py distclean && ./configure.py generate && ninja`.

## Permuter pass (tools/perm_run.py)
- Run 1 (60 closest near misses, <=1 insn off, 300s each, 4 threads): 13 solved directly + 10 more
  recovered with `RETRY=1 python3 tools/perm_run.py` after fixing realias() = **23/60**.
  The 10 "permuter hit 0 but the real build disagreed" cases were the permuter changing an extern's
  type (e.g. `extern char D_x;` so `&D_x + i*4` stops scaling); realias() now carries changed
  top-level declarations back into the aliased draft head.
- "best score -" means the permuter found no improvement at all in 300s; those need hand work
  (list in logs/perm_run.txt).
- near.json: 430 same-size near misses; 263 are <=8 insns off. Run 2 (next 100) started overnight
  2026-10-20: log in logs/perm_run2.txt / logs/perm_run.txt.
- Needs pycparser 2.x in the venv (3.x dropped plyparser); m2c still works with it.
- Resumable: logs/perm/done.txt. Deleting logs/perm/near.json forces a re-rank (~45 min).

## Overnight 2026-10-20/21 results
- Permuter run 2 (next 100 near misses): **61/100** solved and verified.
- tools/fixup.py (new): rewrites every remaining draft for two systematic m2c mistakes and
  fast_matches the variants: (P) m2c writes pointer arithmetic in bytes, C scales it by the
  element size (`var += 0x10` on s32* -> 4; `(i*K) + &D` -> K/4); (A) m2c drops a pass-through
  leading argument (prepend arg0 / arg0, arg1). 55 matched standalone, **50 kept** in the real
  build by tools/apply_fix.sh (one commit per file).
- Still INCLUDE_ASM: 2054 total, 176 in net.c.
- Next: permuter run 3 on remaining <=8-insn near misses (resumable), re-rank after fixup
  (delete logs/perm/near.json), then hand work on net.c.
