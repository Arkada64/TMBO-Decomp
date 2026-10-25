#!/bin/bash
# build the retail harness and a patched ELF: rbuild.sh SCRIPT.json OUT.ELF   (in WSL)
set -e
S=$(realpath "$1"); O=$(realpath -m "$2")
W="/mnt/c/Users/Ark/Desktop/TMB Decomp"; R=/home/ark/tmbo_decomp; SN=tools/compilers/ee-gcc2.95.3-114
H="$W/cloud/in/retail"; T=/home/ark/retailqb; mkdir -p $T
cp "$H/retail_qb.c" $T/
cd $R && "$R/$SN/bin/ee-gcc.exe" "-B$SN/lib/gcc-lib/ee/2.95.3/" -c -O2 -G0 $T/retail_qb.c -o $T/retail_qb.o 2>&1 | grep -v "^$" || true
mips-linux-gnu-objcopy $T/retail_qb.o
printf 'SECTIONS { . = 0x760000; .text : { *(.text) } .rodata : { *(.rodata*) *(.rdata*) } .data : { *(.data*) *(.sdata*) } .bss : { *(.bss*) *(.sbss*) *(COMMON) } /DISCARD/ : { *(.reginfo) *(.mdebug*) *(.comment) *(.pdr) *(.MIPS.*) } }\n' > $T/r.ld
mips-linux-gnu-ld -EL -T $T/r.ld --just-symbols=/home/ark/tmb_decomp/build/SCUS_971.01.elf -o $T/harness.elf $T/retail_qb.o
python3 "$H/rpatch.py" /home/ark/tmb_decomp/disks/SCUS_971.01 $T/harness.elf "$S" "$O"
