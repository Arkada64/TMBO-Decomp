# Online decomp: where we left off (2026-10-20)

## Compiler (identified and in the build)
- Online's game code: **SN Systems ProDG ee-gcc 2.95.x, `-O2 -G0`** (128-bit `sq` register saves).
  Proof in `tools/compiler_matrix.py`: SN 2.95.2-273a / 2.95.3-107 / 2.95.3-114 reproduce drafts byte for byte;
  SN 2.95.3-136 and all Sony builds (2.9, 2.96, 3.2 x2) do not. The build uses 2.95.3-114.
- Pipeline (`tools/sn_cc.sh`): SN compiles C to assembly; `move` is rewritten to `daddu` (SN's encoding);
  GNU as assembles it so INCLUDE_ASM blocks assemble like the rest of the project; section alignment reset to 8.
- `use_gp_rel_macro_nonmatching: True` in the yaml, so INCLUDE_ASM files spell out `%gp_rel(...)($gp)` under -G0.
- Compilers live in `tools/compilers/` (not in git; github.com/decompme/compilers, release "compilers").

## Matched C in src/online/net.c (build is byte-identical)
- `netGetMyClientIndex`, `netGetDmeTime`, `func_00174268`

## Next
- Near misses in `reference/wip/net_funcs.c`: `netMsgChatHandler` (4 insns), `netSendGameEvent` (5 insns).
- Workflow per function: write C -> `python3 tools/apply_c.py src/online/net.c <file>` -> `ninja` -> `cmp` / `tools/funcdiff.py`.
- After a config or toolchain change: `./configure.py distclean && ./configure.py generate && ninja`.
