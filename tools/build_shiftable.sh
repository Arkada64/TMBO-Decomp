#!/bin/bash
# tools/build_shiftable.sh: link the shiftable ELF -> build/SCUS_971.96.shift.elf (PCSX2-ready: entry/paddr fixed).
# Needs tools/post_split.sh to have been run since the last split. Restores the normal build afterwards.
set -e
cd ~/tmbo_decomp && source .venv/bin/activate
touch config/US/empty_syms.txt
cp build.ninja /tmp/build.ninja.shift.bak
trap 'cp /tmp/build.ninja.shift.bak build.ninja' EXIT
grep -q data_ptrs_shiftable build.ninja || sed -i 's#-T \(\S*\)/undefined_funcs.txt -Map#-T \1/undefined_funcs.txt -T \1/data_ptrs_shiftable.txt -Map#' build.ninja
sed -i 's#undefined_syms_auto.txt#undefined_syms_shiftable.txt#; s#undefined_funcs.txt#empty_syms.txt#' build.ninja
ninja build/SCUS_971.96.elf
python3 - <<'EOF'
import struct
d = bytearray(open('build/SCUS_971.96.elf', 'rb').read())
struct.pack_into('<I', d, 0x18, 0x100008)
ph = struct.unpack_from('<I', d, 0x1C)[0]; struct.pack_into('<I', d, ph + 12, struct.unpack_from('<I', d, ph + 8)[0])
open('build/SCUS_971.96.shift.elf', 'wb').write(d)
print("wrote build/SCUS_971.96.shift.elf")
EOF
cp /tmp/build.ninja.shift.bak build.ninja
rm -f build/SCUS_971.96.rom; ninja > /dev/null
cmp -s build/SCUS_971.96.rom disks/SCUS_971.96.rom && echo "normal build restored: byte-identical"
