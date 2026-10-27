#!/bin/bash
# Shift test 3: symbolize raw data pointers, confirm the normal build is still byte-identical,
# then link SHIFTABLE with a 72-byte insertion and write SHIFT_TEST.ELF + its patch file.
# NOTE: never run `configure.py generate` here: it re-runs splat and wipes asm/ edits.
cd ~/tmbo_decomp && source .venv/bin/activate
W="/mnt/c/Users/Ark/Desktop/TMB Decomp"; OUT="$W/test"
cp "$W/symbolize_data.py" "$W/make_shiftable.py" "$W/test_pnach.py" tools/
t0=$(date +%s)
git checkout -q -- config/US/undefined_syms_auto.txt config/US/undefined_funcs.txt
grep -q data_ptrs_shiftable build.ninja || sed -i 's#-T /home/ark/tmbo_decomp/config/US/undefined_funcs.txt -Map#-T /home/ark/tmbo_decomp/config/US/undefined_funcs.txt -T /home/ark/tmbo_decomp/config/US/data_ptrs_shiftable.txt -Map#' build.ninja
python3 tools/symbolize_data.py logs/shift_nm_base.txt
rm -f build/SCUS_971.96.rom; ninja > logs/shift3_base.log 2>&1
cmp -s build/SCUS_971.96.rom disks/SCUS_971.96.rom && echo "normal build still byte-identical" || { echo "BASE BROKEN - stopping"; grep -E 'error|undefined' logs/shift3_base.log | head -5; exit 1; }
mips-linux-gnu-nm -n build/SCUS_971.96.elf > logs/shift_nm_base3.txt
python3 tools/make_shiftable.py logs/shift_nm_base3.txt
cp src/tmb/ai.c /tmp/ai.c.bak; cp build.ninja /tmp/build.ninja.bak
python3 - src/tmb/ai.c <<'EOF'
import sys, re
p = sys.argv[1]; t = open(p).read()
pad = '\nvoid tmbr_shift_pad(void) { __asm__ volatile(".set noreorder\\n" ' + '"nop\\n" ' * 16 + '); }\n'
i = [m.end() for m in re.finditer(r'^#include[^\n]*\n', t, re.M)][-1]
open(p, 'w').write(t[:i] + pad + t[i:])
EOF
touch config/US/empty_syms.txt
sed -i 's#undefined_syms_auto.txt#undefined_syms_shiftable.txt#; s#undefined_funcs.txt#empty_syms.txt#' build.ninja
grep -A4 '^rule ld' build.ninja
ninja build/SCUS_971.96.elf > logs/shift3_build.log 2>&1; echo "shifted link exit $?"; grep -E 'undefined|error' logs/shift3_build.log | head -3
mips-linux-gnu-nm -n build/SCUS_971.96.elf > logs/shift_nm_shift2.txt
cp logs/shift_nm_base3.txt logs/shift_nm_base.txt
python3 - <<'EOF'
import struct
d = bytearray(open('build/SCUS_971.96.elf', 'rb').read())
struct.pack_into('<I', d, 0x18, 0x100008)
ph = struct.unpack_from('<I', d, 0x1C)[0]; struct.pack_into('<I', d, ph + 12, struct.unpack_from('<I', d, ph + 8)[0])
open('/mnt/c/Users/Ark/Desktop/TMB Decomp/test/SHIFT_TEST.ELF', 'wb').write(d)
def load(p):
    r = {}
    for l in open(p):
        s = l.split()
        if len(s) == 3: r[s[2]] = int(s[0], 16)
    return r
a, b = load('logs/shift_nm_base.txt'), load('logs/shift_nm_shift2.txt')
pad = b['tmbr_shift_pad']; import collections
c = collections.Counter(b[n] - v for n, v in a.items() if n in b and pad <= v < 0x625694)
print("in-image symbol moves after the pad (delta: count):", dict(c))
EOF
cp /tmp/ai.c.bak src/tmb/ai.c; cp /tmp/build.ninja.bak build.ninja
rm -f build/SCUS_971.96.rom; ninja > logs/shift3_restore.log 2>&1 && cmp -s build/SCUS_971.96.rom disks/SCUS_971.96.rom && echo "restored: byte-identical again"
python3 tools/test_pnach.py
cp "$OUT"/*.pnach "/mnt/c/Users/Ark/Desktop/TMBO Ready2Play Edition/PCSX2/patches/"
echo "done in $(( $(date +%s) - t0 ))s"
