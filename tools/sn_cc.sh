#!/bin/bash
# Compile a C file with the full SN ProDG toolchain (ee-gcc 2.95.3-114: compiler + SN assembler),
# which is what Online was built with. Verified: 240/241 functions of src/online/net.c match the disc.
# INCLUDE_ASM blocks are fed from temp copies prepared by tools/sn_prep_asm.py (short gp-relative
# form + small-data .extern declarations); the assembler runs with -G8, the C compiles with -G0.
# Called as: sn_cc.sh -c [flags...] IN.c -o OUT   (same shape as the gcc command it replaces)
set -e
SN=tools/compilers/ee-gcc2.95.3-114
args=(); out=""; in=""
while [ $# -gt 0 ]; do
  case "$1" in
    -o) out="$2"; shift 2 ;;
    -c) shift ;;
    *.c) in="$1"; shift ;;
    *)  args+=("$1"); shift ;;
  esac
done
tmp="$out.sn"; rm -rf "$tmp"; mkdir -p "$tmp/asm"
asmdir=$(grep -o 'INCLUDE_ASM("[^"]*"' "$in" | head -1 | sed 's/INCLUDE_ASM("//; s/"$//' || true)
if [ -n "$asmdir" ]; then
  cp "$asmdir"/*.s "$tmp/asm/"
  python3 tools/sn_prep_asm.py "$tmp/asm"
  sed "s|$asmdir|$PWD/$tmp/asm|g" "$in" > "$tmp/src.c"
else
  cp "$in" "$tmp/src.c"
fi
"$SN/bin/ee-gcc.exe" "-B$SN/lib/gcc-lib/ee/2.95.3/" -c "${args[@]}" -Wa,-G8 "$tmp/src.c" -o "$out"
# keep the original 8-byte section alignment
mips-linux-gnu-objcopy --set-section-alignment .text=8 --set-section-alignment .rodata=8 "$out"
