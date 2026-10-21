#!/bin/bash
# Shift test 2: same 72-byte insertion, linked with relative auto symbols.
cd ~/tmbo_decomp && source .venv/bin/activate
W="/mnt/c/Users/Ark/Desktop/TMB Decomp"; OUT="$W/test"
cp "$W/make_shiftable.py" tools/
python3 tools/make_shiftable.py logs/shift_nm_base.txt
grep -c ' + 0x' config/US/undefined_syms_shiftable.txt
git status --short | grep -v '^??' && { echo "tree not clean, stopping"; exit 1; }
git checkout -q -b shift-test
python3 - src/tmb/ai.c <<'EOF'
import sys, re
p = sys.argv[1]; t = open(p).read()
pad = '\nvoid tmbr_shift_pad(void) { __asm__ volatile(".set noreorder\\n" ' + '"nop\\n" ' * 16 + '); }\n'
i = [m.end() for m in re.finditer(r'^#include[^\n]*\n', t, re.M)][-1]
open(p, 'w').write(t[:i] + pad + t[i:])
EOF
ninja build/SCUS_971.96.elf > logs/shift_build2.log 2>&1 || true
CMD=$(ninja -t commands build/SCUS_971.96.elf | tail -1)
CMD=${CMD/-T \/home\/ark\/tmbo_decomp\/config\/US\/undefined_syms_auto.txt -T \/home\/ark\/tmbo_decomp\/config\/US\/undefined_funcs.txt/-T config\/US\/undefined_syms_shiftable.txt}
echo "$CMD" | grep -q shiftable && echo "relinking with relative symbols" || echo "WARNING: substitution failed"
eval "$CMD" 2>&1 | head -5
mips-linux-gnu-nm -n build/SCUS_971.96.elf > logs/shift_nm_shift2.txt
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
git checkout -q -- . ; git checkout -q online; git branch -q -D shift-test
rm -f build/SCUS_971.96.rom; ninja > logs/shift_restore.log 2>&1 && cmp -s build/SCUS_971.96.rom disks/SCUS_971.96.rom && echo "restored: byte-identical again"
