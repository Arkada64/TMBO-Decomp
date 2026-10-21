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

## Next
1. Ark runs `retail_auto.sh` (whole project), then look at the summary.
2. Integration (batch_try equivalent): turning an asm segment into a `.cpp` with INCLUDE_ASM
   per function (splat `cpp` segment) so matches go into the real build, verified by sha1.
3. Port perm_run for the near misses (Ark runs it).
