#!/bin/bash
# Shiftable-build test: insert 64 bytes of code near the start of .text, relink, check every symbol moved
# consistently, and write bootable ELFs (baseline + shifted) for PCSX2's ELF Override.
cd ~/tmbo_decomp && source .venv/bin/activate
OUT="/mnt/c/Users/Ark/Desktop/TMB Decomp/test"; mkdir -p "$OUT"
fix_entry() { python3 - "$1" "$2" <<'EOF'
import struct, sys
d = bytearray(open(sys.argv[1], 'rb').read())
ent = 0x100008
struct.pack_into('<I', d, 0x18, ent)                       # e_entry
phoff = struct.unpack_from('<I', d, 0x1C)[0]
struct.pack_into('<I', d, phoff + 12, struct.unpack_from('<I', d, phoff + 8)[0])   # p_paddr = p_vaddr
open(sys.argv[2], 'wb').write(d)
EOF
}
git status --short | grep -v '^??' && { echo "tree not clean, stopping"; exit 1; }
rm -f build/SCUS_971.96.rom; ninja > logs/shift_base.log 2>&1 && cmp -s build/SCUS_971.96.rom disks/SCUS_971.96.rom && echo "baseline byte-identical"
fix_entry build/SCUS_971.96.elf "$OUT/BASE_TEST.ELF"
mips-linux-gnu-nm -n build/SCUS_971.96.elf > logs/shift_nm_base.txt
FIRST=$(grep -l '^#include' $(grep -lE '^[a-z].*\) \{' src/tmb/*.c) | head -1)
FIRST=src/tmb/ai.c
git checkout -q -b shift-test
python3 - "$FIRST" <<'EOF'
import sys, re
p = sys.argv[1]; t = open(p).read()
pad = '\nvoid tmbr_shift_pad(void) { __asm__ volatile(".set noreorder\\n" ' + '"nop\\n" ' * 16 + '); }\n'
i = [m.end() for m in re.finditer(r'^#include[^\n]*\n', t, re.M)][-1]
open(p, 'w').write(t[:i] + pad + t[i:])
EOF
rm -f build/SCUS_971.96.rom; ninja > logs/shift_build.log 2>&1; echo "shifted build exit $? (a ROM mismatch is expected)"
mips-linux-gnu-nm -n build/SCUS_971.96.elf > logs/shift_nm_shift.txt
fix_entry build/SCUS_971.96.elf "$OUT/SHIFT_TEST.ELF"
python3 - <<'EOF'
import collections
def load(p):
    d = {}
    for l in open(p):
        s = l.split()
        if len(s) == 3: d[s[2]] = int(s[0], 16)
    return d
a, b = load('logs/shift_nm_base.txt'), load('logs/shift_nm_shift.txt')
pad = b.get('tmbr_shift_pad'); print("pad function at", hex(pad) if pad else None)
deltas = collections.Counter()
for n, v in a.items():
    if n in b: deltas[(b[n] - v) if v >= (pad or 0) else ('before', b[n] - v)] += 1
print("symbol moves (delta: count):", dict(deltas))
print("_gp base/shift:", hex(a.get('_gp', 0)), hex(b.get('_gp', 0)))
EOF
grep -iE 'error|overflow|relocation truncated' logs/shift_build.log | head -5
git checkout -q -- . ; git checkout -q online; git branch -q -D shift-test
rm -f build/SCUS_971.96.rom; ninja > logs/shift_restore.log 2>&1 && cmp -s build/SCUS_971.96.rom disks/SCUS_971.96.rom && echo "restored: byte-identical again"
ls -la "$OUT"
