#!/bin/bash
# Usage: m2c_func.sh FUNCNAME [more...]  -> writes reference/m2c/FUNCNAME.c
# Extracts one function (plus any rodata jump tables) from asm/ and runs m2c on it.
cd ~/tmbo_decomp && source .venv/bin/activate
mkdir -p reference/m2c /tmp/m2c
for fn in "$@"; do
  src=$(grep -rl "nonmatching $fn," asm | head -1)
  [ -z "$src" ] && { echo "$fn: not found"; continue; }
  out=/tmp/m2c/$fn.s
  {
    echo '.include "macro.inc"'; echo '.set noat'; echo '.set noreorder'; echo '.section .text'
    awk -v f="$fn" '$0 ~ "nonmatching "f"," {p=1} p {print} p && $0 ~ "endlabel "f"$" {exit}' "$src"
    # jump tables referenced by the function
    for jt in $(awk -v f="$fn" '$0 ~ "nonmatching "f"," {p=1} p {print} p && $0 ~ "endlabel "f"$" {exit}' "$src" | grep -o 'jtbl_[0-9A-F]*' | sort -u); do
      echo '.section .rodata'
      awk -v j="$jt" '$0 ~ "dlabel "j"$" {p=1} p {print} p && $0 ~ "enddlabel "j"$" {exit}' $(grep -rl "dlabel $jt\$" asm | head -1)
    done
  } > "$out"
  python3 -m m2c.main -t mips-gcc-c --pointer-style left --valid-syntax "$out" -f "$fn" \
    > "reference/m2c/$fn.c" 2> "/tmp/m2c/$fn.err" \
    && echo "$fn: $(wc -l < reference/m2c/$fn.c) lines" \
    || { echo "$fn: m2c failed"; tail -3 "/tmp/m2c/$fn.err"; }
done
