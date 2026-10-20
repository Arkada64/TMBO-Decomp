#!/bin/bash
# SN ProDG ee-gcc as a C-to-assembly step only; GNU as assembles the result, so INCLUDE_ASM
# blocks are assembled exactly like the rest of the project.
# Called as: sn_cc.sh -c [flags...] IN -o OUT   (same shape as the gcc command it replaces)
set -e
SN=tools/compilers/ee-gcc2.95.3-114
args=(); out=""
while [ $# -gt 0 ]; do
  case "$1" in
    -o) out="$2"; shift 2 ;;
    -c) shift ;;
    *)  args+=("$1"); shift ;;
  esac
done
"$SN/bin/ee-gcc.exe" "-B$SN/lib/gcc-lib/ee/2.95.3/" -S "${args[@]}" -o "$out.s"
# SN's assembler encodes the `move` pseudo-op as daddu; GNU as would pick `or`. Spell it out.
sed -i -E 's/^(\s+)move\s+(\$[0-9a-z]+),\s*(\$[0-9a-z]+)\s*$/\1daddu\t\2,\3,$0/' "$out.s"
mips-linux-gnu-as -EL -march=5900 -G0 -no-pad-sections -mabi=eabi -Iinclude "$out.s" -o "$out"
# GNU as gives these sections 16-byte alignment; the original objects were 8-byte aligned.
mips-linux-gnu-objcopy --set-section-alignment .text=8 --set-section-alignment .rodata=8 "$out"
