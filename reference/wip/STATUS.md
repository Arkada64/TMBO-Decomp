# Online decomp: where we left off (2026-10-20)

## Compiler (identified)
- Online's game code was built with **SN Systems ProDG ee-gcc 2.95.x, `-O2 -G0`** (128-bit `sq` register saves).
- `tools/compiler_matrix.py` proof: SN 2.95.2-273a, 2.95.3-107 and 2.95.3-114 each match 3 of 5 drafts byte for byte.
  SN 2.95.3-136 and every Sony build (2.9, 2.96, 3.2 x2) match none.
- Compilers live in `tools/compilers/` (not in git; from github.com/decompme/compilers, release "compilers").

## Matched in C (verified by compiler_matrix, not yet in the build)
- `netGetMyClientIndex`, `netGetDmeTime`, `func_00174268` (drafts in `reference/wip/net_funcs.c`)
- Near misses: `netMsgChatHandler` (4 insns), `netSendGameEvent` (5 insns)

## Next step: hook SN into the build
1. Calling `ee-gcc.exe` directly assembles INCLUDE_ASM blocks with SN's own assembler: net.c.o comes out 792 bytes too big.
2. `tools/sn_cc.sh` (C -> asm with SN, then GNU as) fixes the size path, but GNU as then errors
   "macro used $at after .set noat" inside INCLUDE_ASM files (first: func_00162B20.s:118).
   Likely fix: compare SN's `-S` preamble (`.set` directives) with what the asm files expect, or
   emit `.set at` around INCLUDE_ASM in include/include_asm.h for this pipeline.
3. To try it: in `tools/build_system/env.py` set `compiler = "tools/sn_cc.sh"` and `c_flags` `-G0`,
   then `./configure.py distclean && ./configure.py generate && ninja`, then
   `python3 tools/apply_c.py src/online/net.c <drafts>` and `python3 tools/funcdiff.py <names>`.
