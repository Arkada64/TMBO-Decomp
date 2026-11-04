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

## Working C, 2026-11-03 (draft repair pass)
- `tools/nm/dsurv.py` (new): survey of the drafts that do not compile, grouped by the real compiler error
  (cached; `--fails-only` rechecks just the failures). `tools/nm/draftfix.py` (new): repairs them in place in
  `logs/auto/*.drafts.c`, error-driven and line-targeted (compile, rewrite only the lines the compiler names,
  compile again).
- Biggest single cause: m2c's 16-byte type `s128` was defined nowhere, so every draft touching a quadword /
  VU0 copy failed (302 undeclared + 123 parse errors). It is now in `include/m2c_macros.h` as
  `typedef int s128 __attribute__((mode(TI)))` - a true 128-bit scalar, so quadword copies compile.
- Second: a dereference of a value m2c left untyped (`*(v + x)`, v a void*/int) is a word access in the asm ->
  rewritten to `*(s32*)(v + x)`; 73 drafts.
- Drafts that compile on their own: **1034 -> 1146** of 1534 (497 -> 385 failing) before this status build.
- Status build with the repairs: in C now **905** of the 2009 INCLUDE_ASM functions
  (was 810), normal build byte-identical, `test/NM_TEST.ELF` rebuilt. Not boot-tested since 2026-10-25.
- Left for hand C (385 drafts): 212 use `subroutine_argN` (a register value m2c could not name - a guess would
  feed the game garbage, so they stay asm on purpose), 66 `(s128) <float>` casts (this compiler cannot convert
  into a 128-bit type), 36 "second half of f64" (m2c gave up), then ~70 one-offs (incompatible types, invalid
  operands on a void*/float argument, duplicate switch cases).
- Next: function bench (`tools/nm/bench`) on the new C, then the 233 drafts still dropped in context
  (their declarations clash with the file's), then the 417 functions with no draft at all.

## Boot tests are LAN-only (2026-11-03)
- A bench boot signed in to the live revival server with the owner's account. Cause: the baked community patch
  `Force Revival Server DNS` overwrites the netcnf hostname, and the network stack (`NETNETCNF` / `eznetcnf`)
  loads at boot - the menu path does not matter. Never boot a build that carries that patch.
- Test builds: `TMBR_NO_REVIVAL_DNS=1 bash tools/nm_build.sh ...` (build_shiftable.sh drops the section).
  Verify the ELF before booting: 0 matches for the server address (2 before). Tests run under the LAN function
  (SINGLE PLAYER is the LAN host path; ONLINE -> LAN is the online page, cursor 4).
- Function bench (tools/nm/bench) on src/tmb/ai.c, src/tmb/particle.c, src/online/after_clapper_09.c,
  src/online/after_ai_03.c with the LAN-only no-C build: normal build byte-identical, 105 drafts linked into
  DRAFTS.ELF (0 left out), mid-match savestate 42 MB, 5 frames. **2 drafts reached, 5 calls, 0 FAIL**, 1 `ret?`
  (func_0022CA48: only v0 differs - a void function's leftover). Coverage is capped by an EE-interpreter fault
  the drafts did not cause: `unaligned 4-byte read at 3c01806a` in `calculatePanAngle__FP7VehicleP8_fvector+0x2c`,
  which ends every root after ~1k-250k steps. Next: teach ee.py that read (or pick roots that avoid it) before
  the bench can say anything about the 105 drafts.
- Bench follow-up (same day): the fault is not the load transition. A savestate taken 45 s later in the race
  faults at the identical address (`calculatePanAngle+0x2c`, `3c01806a`), and `vehicle+0x2028` holds the same
  `0x3C018002` in it - so either the game really has that pointer at that moment (the bench then starts mid-frame
  and the state is not a safe entry point) or the state loading / interpreter is wrong. The check above says
  whether that value exists in the savestate RAM; the next step is the other side (compare the same field in
  PCSX2 while paused), then either a safer root (call the frame function only after the game's own update has
  run one frame in the interpreter) or a fixed state loader.

## Working-C build does NOT boot (2026-11-03, LAN-only build)
- First boot test of the working-C build (925 of 2009 functions): it stops at UI state 1, logs 50 TLB misses at
  5.57-5.67 s, and never reaches the main menu or renders a frame (TMBR perf 0). The first faulting pc is inside
  func_001FE4D0 (src/tmb/dbs.c), which is still INCLUDE_ASM - so the corruption comes from a C replacement that
  ran before it, not from that function.
- Control: the same mods build with no C boots to the main menu and into a match, so the mods and the toolchain are
  fine; the difference is the C. The 810-function build was never boot-tested either, so this may predate today.
- Safety: LAN-only (TMBR_NO_REVIVAL_DNS=1, 0 matches for the server address in the ELF), normal build stayed
  byte-identical, and test/NM_TEST.ELF is this working-C LAN ELF.
- Next: bisect. Cheapest axis is tools/nm_build.sh file arguments - only the named files get their C blocks, the
  rest stay asm - halving the list per step and booting, looking for TMBR ui: state 6 and TMBR perf lines in
  cloud/qb_out/<run>/emulog.txt. tools/nm/pc/nm_loop.sh and nm_skip.txt already keep a skip list for a faulting
  function; update their stale paths first.

## 2026-11-03 13:58 CST - boot failure bisected to one function
- File-level bisect over all 181 candidate files (cloud/in/nm2/bisect_boot.sh): building ONLY src/tmb/disp.c as C reproduces the failure, every other file boots to the main menu.
- Per-function bisect inside disp.c (cloud/in/nm2/bisect_disp.sh, subset kept as C, rest forced to asm via NM_SKIP): dispSetTags__FP8_DisplayPUiPviiiiiii alone reproduces it (50 TLB misses, never reaches state 6). dispCreate__FP8_Displayii alone boots fine (10 tlb, menu reached). Guards in the script prove NM_SKIP really takes effect.
- Likely cause: the m2c draft for dispSetTags keeps only 4 of the 8 real arguments, so the GIF packet chain gets garbage.
- dispSetTags is now on logs/nm_skip.txt (gitignored build input, also copied into nmhome), i.e. it stays asm.
- PENDING: the full working-C build with that skip, then a LAN-only boot to an actual match (cloud/out/nm_boot_lan.log). Started 13:52 CST, unverified at the time of this note.
## 2026-11-04 — the boot stall is not only disp.c: font.c found and fixed

- Full working-C build with all 11 disp.c drafts forced back to asm still stalls
  (`cloud/out/test_alloff.log`, VERDICT BAD, state 1 at 6.4 s, 50 TLB misses). The earlier
  per-function bisect had only ever built disp.c alone, so it could not see this.
- Tracing the crashing pc back to a function does not work yet: the running ELF is the shifted
  link, and 0x2039e8 is `addiu $a3,$zero,1` in the unshifted image, so map lookups name the wrong
  function. Resolving boot crashes needs the shifted map kept alongside `test/NM_TEST.ELF`.
- File-subset bisect in the full context (`cloud/in/nm2/bisect2.sh`, 90/91 split): half A
  (67 online + 23 tmb files) boots to the menu, half B (91 src/tmb files) stalls; halving converged
  on **src/tmb/font.c** (`cloud/out/bisect2.log` — MINIMAL CULPRIT).
- Function bisect inside font.c (`cloud/in/nm2/bisect_font.sh`): **fontDmaFontData__Fv** alone, as
  C, is enough to stall the boot. Two defects in its draft: `(0x8000 << 0x2D)` is a 32-bit shift by
  45 (undefined), so the GIF A+D tag was 0x10008001 instead of 0x1000000000008001; and the
  `D_004FB5C4 == 2` branch stored 4 bytes where the asm does `sh`, clobbering the next field.
- Also fixed: `func_00202AD8`, `func_00202B30` and `fontSetColor__Fiiii` all call
  `func_002029D8` with `$4` = the font index, but the drafts passed the colour bytes (`0xC0`,
  `0x80`) or nothing, i.e. a packet write at `(garbage << 5)` past `D_00505EF0`.
- The fixes live in `tools/nm/hand/src_tmb_font.c` (hand-written C, same `//@@ name` format).
  `tools/nm_build.sh` now copies `tools/nm/hand/*.c` into `logs/hand/` before nm_apply runs — the
  hand-written path has always existed in nm_apply, but nothing ever populated `logs/hand`, so every
  hand file was silently unused.
- Verified by boot: font.c with only fontDmaFontData__Fv as C (the hand version) reaches the menu
  (`cloud/out/test_font.log`, only_dma OK). font.c with all of its drafts is still BAD, so font.c
  has at least one more culprit; the bisect was restarted from there.
## 2026-11-04 (later) — font.c fixed by hand; the full build still stalls, so the search moves on

- `fontDmaFontData__Fv` and the three callers whose draft lost `func_002029D8`'s argument
  (`func_00202AD8`, `func_00202B30`, `fontSetColor__Fiiii`) are fixed as hand-written C in
  `tools/nm/hand/src_tmb_font.c`, and `tools/nm_build.sh` now copies `tools/nm/hand/*.c` into
  `logs/hand/` (nm_apply always supported hand files; nothing ever populated that directory).
- `func_002029D8` carries the same tag-width defect (`0x9000 << 0x2E` shifted as a 32-bit int), but a
  hand version that matches the asm instruction for instruction still hung the boot — reproducibly,
  UI state 1, no TLB misses, the log simply stops inside the DMA wait — so it stays asm via
  `logs/nm_skip.txt` until that is understood. Font packets are involved in both paths, so a second
  look there is the obvious follow-up.
- Verified by boot: font.c with those fixes and `func_002029D8` as asm reaches the menu
  (`cloud/out/test_font.log`, tag `skip29d8` -> OK).
- The full working-C build is still BAD (`cloud/out/full_boot.log`): 50 TLB misses, state 1, the same
  signature as before font.c was fixed. Half A of the file bisect (67 online + 23 tmb) booted, so at
  least one more of the 91 `src/tmb` files breaks the boot; the bisect restarts on that half with
  font.c removed.
