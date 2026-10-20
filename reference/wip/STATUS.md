# Online decomp: where we left off (2026-10-20)

## Compiler (identified and in the build)
- Online's game code: **SN Systems ProDG ee-gcc 2.95.x, `-O2 -G0`** (128-bit `sq` register saves).
  Proof in `tools/compiler_matrix.py`: SN 2.95.2-273a / 2.95.3-107 / 2.95.3-114 reproduce drafts byte for byte;
  SN 2.95.3-136 and all Sony builds (2.9, 2.96, 3.2 x2) do not. The build uses 2.95.3-114.
- Pipeline (`tools/sn_cc.sh`): SN compiles C to assembly; `move` is rewritten to `daddu` (SN's encoding);
  GNU as assembles it so INCLUDE_ASM blocks assemble like the rest of the project; section alignment reset to 8.
- `use_gp_rel_macro_nonmatching: True` in the yaml, so INCLUDE_ASM files spell out `%gp_rel(...)($gp)` under -G0.
- Compilers live in `tools/compilers/` (not in git; github.com/decompme/compilers, release "compilers").

## Matched in C so far (build byte-identical)
- `netGetMyClientIndex`, `netGetDmeTime`, `func_00174268`, `netMsgChatHandler` (early-return form)

## Open toolchain issue (do this next)
- `netSendGameEvent` is right except one global load: the original has `lui a3,%hi(D)` / `lw a3,%lo(D)(a3)`
  back to back (an unsplit `lw $7,D` macro expanded by SN's assembler). Our SN `-S` output splits it
  (`lui $2,...` scheduled early). `-mno-split-addresses` fixes that load but turns every `la` into 64-bit
  `daddiu` under GNU as, breaking the other 4 (see logs from variants3, `reference/wip/variants3.c`).
- Conclusion: C functions need SN's own assembler; INCLUDE_ASM functions need GNU as.
  Plan: asm-processor-style splice. Build C-only object with the full SN toolchain (`-c`, INCLUDE_ASM
  defined empty), build the INCLUDE_ASM-only object with GNU as, then splice each C function's bytes
  and relocations into place by symbol, preserving order. Verify with cmp after each step.

## Next
- Write the splice tool (above), re-test all 5 with SN as.
- Workflow per function: write C -> `python3 tools/apply_c.py src/online/net.c <file>` -> `ninja` -> `cmp` / `tools/funcdiff.py`.
- After a config or toolchain change: `./configure.py distclean && ./configure.py generate && ninja`.
