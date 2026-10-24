#!/usr/bin/env python3
"""EE registers from a PCSX2 savestate (uncompressed .p2s): finds the cpuRegs block (GPR[32] x 16 bytes, HI, LO,
CP0[32], sa, IsDelaySlot, pc) in the internal-structures entry and prints pc / ra / sp + a stack walk of
return-address-looking words, named from reference/match/online_files.csv.
  python3 tools/qb/stateregs.py state.p2s [ELF]"""
import sys, zipfile, struct, bisect, csv, os
z = zipfile.ZipFile(sys.argv[1])
names = z.namelist()
R = os.path.join(os.path.dirname(os.path.abspath(__file__)), '../../reference/match/online_files.csv')
syms = []
if len(sys.argv) > 2:      # names from the ELF that ran (the mod build is shifted against retail)
    import subprocess
    for l in subprocess.run(['nm', '-S', '--defined-only', sys.argv[2]], capture_output=True, text=True).stdout.splitlines():
        p = l.split()
        if len(p) == 4 and p[2] in 'tTwW': syms.append((int(p[0], 16), p[3], int(p[1], 16)))
else:
    for row in csv.reader(open(R)):
        try: syms.append((int(row[0], 16), row[2] or 'func_%08X' % int(row[0], 16), int(row[1], 16)))
        except Exception: pass
syms.sort(); addrs = [a for a, _, _ in syms]
def name(a):
    i = bisect.bisect_right(addrs, a) - 1
    if i < 0: return '?'
    s, n, l = syms[i]
    return f'{n}+0x{a - s:x}' if a - s < max(l, 4) + 0x400 else f'?{a:08x}'
GPR = '0 at v0 v1 a0 a1 a2 a3 t0 t1 t2 t3 t4 t5 t6 t7 s0 s1 s2 s3 s4 s5 s6 s7 t8 t9 k0 k1 gp sp fp ra'.split()
ent = [n for n in names if 'Internal' in n or 'cpu' in n.lower()]
d = z.read(ent[0]) if ent else max((z.read(n) for n in names), key=len)
best = None
for o in range(0, len(d) - 700, 4):
    g = lambda r: struct.unpack_from('<I', d, o + 16 * r)[0]
    if g(0) != 0: continue
    sp, ra, gp = g(29), g(31), g(28)
    pc = struct.unpack_from('<I', d, o + 680)[0]
    if 0x1000000 <= sp < 0x2000000 and 0x100000 <= ra < 0x400000 and 0x100000 <= pc < 0x400000 and 0x400000 < gp < 0x800000:
        best = o; break
if best is None: sys.exit('cpuRegs not found; entries: %s' % names)
g = lambda r: struct.unpack_from('<I', d, best + 16 * r)[0]
pc = struct.unpack_from('<I', d, best + 680)[0]
print('pc', hex(pc), name(pc)); print('ra', hex(g(31)), name(g(31)))
print(' '.join(f'{GPR[r]}={g(r):08x}' for r in range(32)))
mem = z.read([n for n in names if 'eeMemory' in n][0])
sp = g(29)
print('stack return-address candidates from sp', hex(sp))
seen = 0
for a in range(sp, min(sp + 0x2000, len(mem) - 4), 4):
    w = struct.unpack_from('<I', mem, a)[0]
    if 0x100000 <= w < 0x3A0000 and (w & 3) == 0:
        # a return address follows a jal: check the word before it
        j = struct.unpack_from('<I', mem, w - 8)[0]
        if j >> 26 in (3,) or (j & 0xFC00003F) == 9:
            print(f'  [{a:08x}] {w:08x} {name(w)}'); seen += 1
            if seen > 25: break
