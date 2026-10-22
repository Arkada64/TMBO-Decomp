# Retail (SCUS-97101) status: account 2

## 2026-10-21
- Step 1 done: `retail` branch, `ninja` gives a byte-identical ROM (sha1 be9859150d...).
  Needs `source .venv/bin/activate` first, or ninja dies on `splat` and leaves the old ROM.
- Step 2 (pipeline port), tools in `tools/`:
  | Tool | Does |
  |---|---|
  | `fast_match.py DRAFTS OUT [hdr]` | compile each `//@@ NAME` block alone with EE-GCC 2.9 `-O2 -G8`, compare to disc, relocs masked. NAME is the mangled symbol. `LANG_SRC=c++` for C++ blocks. Parallel-safe. |
  | `retail_selftest.sh` | fast_match on upstream's combo/font/mathf: **106/106 MATCH** (1 name missing from symbol_addrs) |
  | `auto_m2c.py ASM.s OUT` | splits a whole-file asm (retail has no per-function nonmatchings) and writes m2c drafts, several variants per function |
  | `gcc2_mangle.py` | parameter types from GCC 2 mangled names |
  | `make_context.py` | m2c context of 2475 prototypes decoded from symbol_addrs names |
  | `showdiff.py DRAFTS NAME` | disc vs ours instruction diff (`V=n` picks the nth variant) |
  | `retail_auto.sh [jobs]` | whole-project draft + match pass, resumable, summary in `logs/retail_auto.txt` |
- Lessons (retail differs from online):
  - m2c target must be **`mipsee-gcc-c`** (EE arg registers: floats f12-f19, 8 int args).
  - `-G8`: unknown-size externs become gp-relative. Drafts declare data as `u8 x[]` (lui/addiu)
    or `u8 x[4]` (when the asm uses `%gp_rel`), which also makes m2c's byte offsets right.
  - Callees whose result is unused must be `void`, or v0/v1 allocation differs.
  - Mangled names give real prototypes (floats, char/short truncation) for every callee.
- First sample (9 small files, 44 functions): 5 match standalone, most others within a few insns.

- Whole-project run (`retail_auto.sh`, 7 min, 4 jobs): **468 functions match standalone**.
- Integration: `integrate.py X` (all matches at once, bisects on sha1 failure) and
  `retail_integrate.sh` (converts every segment with matches from `asm` to a `c` segment, splat
  writes INCLUDE_ASM per function, then integrates + commits per segment, ~1 h).
  Segments are **C, not C++**: drafts are C with mangled names as identifiers. Convert to real
  C++ (classes, methods) later, when a file is cleaned up by hand.
  Needs `migrate_rodata_to_functions: False` in the yaml: splat refuses c segments whose
  rodata stays asm otherwise. Rodata/lit4 of converted segments are still asm.
- **428 functions in the real build** (timer 10 + 418), ROM byte-identical. Plus upstream's 107.
  Note: `report.json` progress still shows 2.54% (it doesn't count functions inside
  partly-INCLUDE_ASM files); count matches with `git log`/`grep -c INCLUDE_ASM` instead.

- auto_m2c.py also takes a converted segment's dir (`asm/nonmatchings/tmb/X`, only functions
  still INCLUDE_ASM). `WITH_RODATA=1` adds 'R' variants with the segment's rodata given to m2c:
  on ui+sound it fixed every m2c failure but gave 1 new match and doubled the time, and R matches
  can't enter the build anyway while rodata is asm (integrate.py skips them unless ALLOW_R=1).
  Real fix = rodata migration (C owns each function's rodata), a bigger change for later.
- `perm_run.py [MAXD SECS MAXF THREADS]`: permuter over `logs/drafts/*.near.json` (469 near
  misses), solved ones go in via integrate.py + commit. Needs pycparser 2.x (installed 2.23 in
  the venv; m2c still fine). Smoke test: IsAscii__FPc solved in 30 s.

- Permuter run 1 (`perm_run.py 8 180 120 4`, ~2.5 h): **53 solved of 120** (closest first).
  Retail now has **482 functions in the build** (429 + 53), plus upstream's 107.

## Next
1. More permuter runs: `perm_run.py 8 180 120 4` continues with the next 120 (done.txt).
2. Rodata migration, so switch/literal functions can be matched.
3. Then step 3 of the handoff (port account 1's online matches to retail) and step 4 (UI).
