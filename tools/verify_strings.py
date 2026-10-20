#!/usr/bin/env python3
"""
Independent accuracy check for match_versions.py: a correct retail<->online pair should
reference the same text strings. Resolves lui/addiu(ori) address pairs, reads C strings.
Also writes online_only_strings.txt: strings used by online-only functions (naming hints).
"""

import csv
import struct
import collections
from pathlib import Path

HOME = Path.home()
D = HOME / "tmbo_decomp/reference/match"


class Img:
    def __init__(self, path):
        d = path.read_bytes()
        self.d = d
        (shoff,) = struct.unpack_from("<I", d, 0x20)
        (shnum,) = struct.unpack_from("<H", d, 0x30)
        self.secs = []
        for i in range(shnum):
            s = struct.unpack_from("<IIIIIIIIII", d, shoff + i * 40)
            if s[1] == 1 and s[2] & 2 and s[3]:  # PROGBITS + ALLOC
                self.secs.append((s[3], s[3] + s[5], s[4]))

    def word(self, a):
        for lo, hi, off in self.secs:
            if lo <= a < hi:
                return struct.unpack_from("<I", self.d, off + a - lo)[0]

    def cstr(self, a):
        for lo, hi, off in self.secs:
            if lo <= a < hi:
                o = off + a - lo
                e = self.d.find(b"\0", o, o + 200)
                if e - o < 4:
                    return None
                s = self.d[o:e]
                if all(32 <= c < 127 or c in (9, 10) for c in s):
                    return s.decode()
        return None

    def strings(self, addr, size):
        regs, out = {}, set()
        for i in range(size // 4):
            w = self.word(addr + 4 * i)
            op = w >> 26
            rs, rt, imm = (w >> 21) & 31, (w >> 16) & 31, w & 0xFFFF
            if op == 0x0F:
                regs[rt] = imm << 16
                continue
            if op in (0x09, 0x19, 0x0D) and rs in regs:
                v = regs[rs] + (
                    imm if op == 0x0D else (imm - 0x10000 if imm & 0x8000 else imm)
                )
                s = self.cstr(v & 0xFFFFFFFF)
                if s:
                    out.add(s)
        return out


rt_img = Img(HOME / "tmb_decomp/disks/SCUS_971.01")
on_img = Img(HOME / "tmbo_decomp/disks/SCUS_971.96")
stats = collections.defaultdict(lambda: [0, 0, 0])  # with_strings, agree, disagree
bad = []
only_strings = []
for r in csv.DictReader(open(D / "mapping.csv")):
    oa, osz = int(r["online_addr"], 16), int(r["online_size"], 16)
    so = on_img.strings(oa, osz)
    if not r["retail_name"]:
        if so:
            only_strings.append((oa, sorted(so)))
        continue
    sr = rt_img.strings(int(r["retail_addr"], 16), int(r["retail_size"], 16))
    if not so or not sr:
        continue
    st = stats[r["method"]]
    st[0] += 1
    if so & sr:
        st[1] += 1
    else:
        st[2] += 1
        bad.append(
            (r["method"], r["score"], r["retail_name"], sorted(sr)[:2], sorted(so)[:2])
        )
print("method           pairs-with-strings  share-a-string  share-none")
for m, (n, a, b) in sorted(stats.items(), key=lambda kv: -kv[1][0]):
    print(f"{m:16s} {n:10d} {a:14d} ({100 * a / n:.0f}%) {b:8d}")
print("\nexamples sharing no strings:")
for b in bad[:10]:
    print(" ", b)
with open(D / "online_only_strings.txt", "w") as fh:
    for oa, ss in only_strings:
        fh.write(
            f"0x{oa:08X}: "
            + " | ".join(s.replace("\n", "\\n")[:60] for s in ss[:6])
            + "\n"
        )
print(f"\nonline-only functions with strings: {len(only_strings)}")
