# Working-C pipeline (toward the PC build)
- `../nm_apply.py`: puts compiling m2c drafts in as `#ifdef NON_MATCHING` alternatives to `INCLUDE_ASM`.
- `../nm_build.sh`: private copy (~/nmhome), normal build must stay byte-identical, then the shiftable build with
  mods and `-DNON_MATCHING` -> `test/NM_TEST.ELF`. C float literals go after the game's .sdata (gp-relative).
- On the test PC: `cloud/in/nm_test.sh FILES` (build + quick-boot into retail Snowy Roads),
  `cloud/in/nm_loop.sh N FILES` (repeat; a TLB fault inside one of our C functions puts it on
  `cloud/in/nm_skip.txt` and goes again; stops when clean or when a fault needs a look).
- Note: PCSX2 reports the start of the recompiled block as the fault pc, so the function is right, the
  instruction is not.
- `draftfix.py`: repairs the drafts that do not compile on their own, in place in `logs/auto/*.drafts.c`
  (compile-only). Error-driven and line-targeted: compile the block alone, rewrite only the lines the compiler
  names, repeat. Covered patterns: `*(v + x)` where m2c lost the pointee type -> `*(s32*)(v + x)` (word access,
  the dominant width here); `s128` (m2c's 16-byte quadword type) comes from `include/m2c_macros.h`.
  `--fail-list FILE` limits it to `rel::name` lines. Left for hand C: m2c's `(s128) <float>` casts (this
  compiler cannot convert into a 128-bit type), `subroutine_argN` (a register value m2c could not name) and
  `second half of f64` (m2c gave up); those drafts stay asm.
- `dsurv.py`: survey of the drafts that do not compile - groups the real compiler errors by signature and
  class, cached so a re-run only recompiles what changed (`--fails-only` rechecks just the failures).
  Point it at the private build copy: `python3 tools/nm/dsurv.py --jobs 4 --report logs/nm/dsurv.txt`.
