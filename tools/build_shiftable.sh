#!/bin/bash
# tools/build_shiftable.sh: link the shiftable ELF -> build/SCUS_971.96.shift.elf (PCSX2-ready: entry/paddr fixed).
# With MODS=1 (default) the TMB-Reloaded mods in mods/*.s are assembled, linked in (.text after the last
# game object, .bss after the game's bss) and tools/mods/apply_mods.py hooks them into the game's asm.
# Needs tools/post_split.sh to have been run since the last split. Restores the normal build afterwards.
set -e
cd ~/tmbo_decomp && source .venv/bin/activate
MODS=${MODS:-1}
LD=config/US/SCUS_971.96.ld
touch config/US/empty_syms.txt
cp build.ninja /tmp/build.ninja.shift.bak; cp $LD /tmp/ld.shift.bak
restore() {
  cp /tmp/build.ninja.shift.bak build.ninja; cp /tmp/ld.shift.bak $LD
  [ "$MODS" = 1 ] && python3 tools/mods/apply_mods.py revert || true
}
trap restore EXIT
grep -q data_ptrs_shiftable build.ninja || sed -i 's#-T \(\S*\)/undefined_funcs.txt -Map#-T \1/undefined_funcs.txt -T \1/data_ptrs_shiftable.txt -Map#' build.ninja
sed -i 's#undefined_syms_auto.txt#undefined_syms_shiftable.txt#; s#undefined_funcs.txt#empty_syms.txt#' build.ninja
if [ "$MODS" = 1 ]; then
  python3 tools/mods/apply_mods.py apply
  mkdir -p build/mods; TXT=""; BSS=""
  for s in mods/*.s; do
    o=build/mods/$(basename $s).o
    mips-linux-gnu-as -Iinclude -EL -march=5900 -G0 -no-pad-sections -mabi=eabi $s -o $o
    TXT="$TXT        $o(.text);\n"; BSS="$BSS        $o(.bss);\n"
  done
  # keep everything after the mods on its original 128-byte phase (lq-read data, DMA buffers)
  sed -i "s#^\(\s*\)build/asm/newlib/libc/machine/r5900/memcmp.s.o(.text);#&\n$TXT        . = ALIGN(., 128);\n#" $LD
  sed -i "s#^\(\s*\)build/asm/data/bss1.bss.s.o(.bss);#&\n$BSS#" $LD
  # ninja doesn't know about the mod objects: make the link step re-run
  touch $LD
fi
ninja build/SCUS_971.96.elf
python3 - <<'EOF'
import struct
d = bytearray(open('build/SCUS_971.96.elf', 'rb').read())
struct.pack_into('<I', d, 0x18, 0x100008)
ph = struct.unpack_from('<I', d, 0x1C)[0]; struct.pack_into('<I', d, ph + 12, struct.unpack_from('<I', d, ph + 8)[0])
open('build/SCUS_971.96.shift.elf', 'wb').write(d)
print("wrote build/SCUS_971.96.shift.elf")
EOF
mips-linux-gnu-nm build/SCUS_971.96.elf | grep -E " tmbr_" || true
restore; trap - EXIT
rm -f build/SCUS_971.96.rom; ninja > /dev/null
cmp -s build/SCUS_971.96.rom disks/SCUS_971.96.rom && echo "normal build restored: byte-identical"
