#!/usr/bin/env python3
"""rpatch.py RETAIL.ELF HARNESS.ELF SCRIPT.json OUT.ELF : retail ELF + the harness (rbuild.sh) as an extra load
segment, its two hooks, and the script in tmbr_rq. Script JSON: {"keys": [k0..k3], "loop_from": n,
"steps": [[frames, "P1 BUTTONS", "P2 ...", "P3", "P4"], ...]} with buttons as names joined by + (as qbrun.py)."""
import json, struct, subprocess, sys
BTN = dict(SELECT=0x1, L3=0x2, R3=0x4, START=0x8, UP=0x10, RIGHT=0x20, DOWN=0x40, LEFT=0x80, L2=0x100, R2=0x200,
           L1=0x400, R1=0x800, TRIANGLE=0x1000, CIRCLE=0x2000, CROSS=0x4000, SQUARE=0x8000)
def mask(s):
    m = 0
    for k in filter(None, s.upper().split('+')): m |= BTN[k]
    return m
ret, har, scr, out = sys.argv[1:5]
syms = {}
for l in subprocess.run(['mips-linux-gnu-nm', har], capture_output=True, text=True).stdout.splitlines():
    p = l.split()
    if len(p) == 3: syms[p[2]] = int(p[0], 16)
d = bytearray(open(ret, 'rb').read())
h = open(har, 'rb').read()
hph, = struct.unpack_from('<I', h, 0x1C); hn, = struct.unpack_from('<H', h, 0x2C)
segs = [struct.unpack_from('<IIIIIIII', h, hph + 32 * i) for i in range(hn)]
seg = [s for s in segs if s[0] == 1 and s[2] >= 0x700000]
assert len(seg) == 1, segs
t, off, va, pa, fs, ms, fl, al = seg[0]
blob = bytearray(h[off:off + fs] + bytes(ms - fs))
# the script into tmbr_rq
sc = json.load(open(scr))
o = syms['tmbr_rq'] - va
steps = sc['steps']; assert len(steps) <= 150
struct.pack_into('<III', blob, o, 0x52514D54, len(steps), sc.get('loop_from', 0xFFFF))
blob[o + 12:o + 16] = bytes(sc.get('keys', [0, 1, 2, 3]))
for i, s in enumerate(steps):
    btn = [mask(x) for x in (list(s[1:]) + [''] * 4)[:4]]
    struct.pack_into('<HHHHHH', blob, o + 16 + 12 * i, s[0], 0, *btn)
# hooks: jal tmbr_rPadRead at 0x1D7810, jal tmbr_rFrameWait at 0x15B518 (retail is loaded at file offset 0x10000 + va - 0x100000)
phoff, = struct.unpack_from('<I', d, 0x1C); phnum, = struct.unpack_from('<H', d, 0x2C)
_, roff, rva, _, rfs, rms, _, _ = struct.unpack_from('<IIIIIIII', d, phoff)
def put(addr, word):
    struct.pack_into('<I', d, roff + addr - rva, word)
def jal(target): return (3 << 26) | ((target >> 2) & 0x3FFFFFF)
assert struct.unpack_from('<I', d, roff + 0x1DF220 - rva)[0] >> 26 == 3 and struct.unpack_from('<I', d, roff + 0x1D7810 - rva)[0] >> 26 == 3
put(0x1D7810, jal(syms['tmbr_rPadRead'])); put(0x1DF220, jal(syms['tmbr_rPadRead']))   # (0x1DF220: the movie skip)
for a_ in (0x15B4C0, 0x163560, 0x18EAD0, 0x1C1A20, 0x1F68C0, 0x1F68D4, 0x1F69AC, 0x1F69C0, 0x1FC5EC):   # every sceGsSyncV call
    assert struct.unpack_from('<I', d, roff + a_ - rva)[0] == jal(0x203B80), hex(a_)
    put(a_, jal(syms['tmbr_rSyncV']))
# the extra segment: data appended at a 0x10000-aligned file offset, a second program header after the first
fo = (len(d) + 0xFFFF) & ~0xFFFF
d += bytes(fo - len(d)) + blob
assert phoff + 64 <= 0x10000 and phnum == 1
struct.pack_into('<IIIIIIII', d, phoff + 32, 1, fo, va, va, len(blob), len(blob), 7, 0x10000)
struct.pack_into('<H', d, 0x2C, 2)
open(out, 'wb').write(d)
print('rpatch: %s (%d steps, harness %d bytes at %08x)' % (out, len(steps), len(blob), va))
