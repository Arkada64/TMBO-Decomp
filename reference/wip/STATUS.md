# Online decomp: where we left off (2026-10-20)

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

## Progress
- 17 of 241 functions in src/online/net.c are matched C (batches in reference/wip/batch1-3.c).
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
