#!/bin/bash
# tools/post_split.sh: run after EVERY `configure.py split/generate` (splat rewrites asm/ and the .ld).
# Makes the build shiftable (code/data can grow or move) while the normal build stays byte-identical.
# Then `bash tools/build_shiftable.sh` links build/SCUS_971.96.shift.elf.
set -e
cd ~/tmbo_decomp && source .venv/bin/activate
LD=config/US/SCUS_971.96.ld
rm -f build/SCUS_971.96.rom; ninja > /dev/null
cmp -s build/SCUS_971.96.rom disks/SCUS_971.96.rom || { echo "base build not matching - fix that first"; exit 1; }
python3 tools/symbolize_data.py build/SCUS_971.96.elf   # raw data pointers -> symbols; non-pointers -> raw
python3 tools/fix_rawlo.py build/SCUS_971.96.elf        # unpaired %lo immediates (+ libmpeg mpc.s fix)
# standard MIPS gp anchor (original _gp is exactly .sdata + 0x7FF0); crt0 loads it via _gp
sed -i 's#_gp = 0x5015F0;#_gp = main_SDATA_START + 0x7FF0;#' $LD
sed -i 's#%hi(D_005015F0)#%hi(_gp)#; s#%lo(D_005015F0)#%lo(_gp)#' asm/gcc/_crt0.s
# original ELF section alignments (no-ops in the matching layout)
grep -q 'ALIGN(., 128);' $LD || sed -i 's#^\(\s*\)main_DATA_START = \.;#\1. = ALIGN(., 16);\n\1main_DATA_START = .;#;
        s#^\(\s*\)build/asm/data/1B8A00.data.s.o(.data);#\1. = ALIGN(., 128);\n&#;
        s#^\(\s*\)main_RODATA_START = \.;#\1. = ALIGN(., 16);\n\1main_RODATA_START = .;#;
        s#^\(\s*\)main_SDATA_START = \.;#\1. = ALIGN(., 8);\n\1main_SDATA_START = .;#;
        s#^\(\s*\)main_SBSS_START = \.;#\1. = ALIGN(., 8);\n\1main_SBSS_START = .;#;
        s#^\(\s*\)main_BSS_START = \.;#\1. = ALIGN(., 128);\n\1main_BSS_START = .;#' $LD
rm -f build/SCUS_971.96.rom; ninja > /dev/null
cmp -s build/SCUS_971.96.rom disks/SCUS_971.96.rom || { echo "POST-SPLIT BROKE THE MATCH"; exit 1; }
python3 tools/make_shiftable.py build/SCUS_971.96.elf | head -1   # -> config/US/undefined_syms_shiftable.txt
echo "post_split OK: normal build byte-identical, shiftable inputs ready"
