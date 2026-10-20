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

## Open
- `netSendGameEvent`: logic right; the message-id global load is split (`lui v0` early) where the original
  has `lui a3`/`lw a3` back to back. Not a flag (see above); a source-shape difference still to find.

## Workflow
- Per function: write C -> `python3 tools/apply_c.py src/online/net.c <file>` -> `ninja` -> `cmp`.
- After a config or toolchain change: `./configure.py distclean && ./configure.py generate && ninja`.
