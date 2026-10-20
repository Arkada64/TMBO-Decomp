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
mips-linux-gnu-as -EL -march=5900 -G0 -no-pad-sections -mabi=eabi -Iinclude "$out.s" -o "$out"
