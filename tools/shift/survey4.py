# ruff: noqa
"""Pickup files (PKP) retail vs online: count by type per level (story health pads)."""
import sys, struct, collections
sys.path.insert(0, "/mnt/c/Users/Ark/Desktop/TMB Decomp"); sys.path.insert(0, "/mnt/c/Users/Ark/Desktop/TMB Decomp/tools/shift")
from ngpdb import disc, rawfile
for tag in ("retail", "online"):
    fs = disc(tag)[1]
    print(tag, "PKP files:", sorted(n for n in fs if n.upper().endswith(".PKP"))[:80])
def recs(d):
    # TMB PKP: 8-byte header, 20-byte records {xyz, 0, u32 type}
    n = struct.unpack_from("<I", d, 4)[0]          # header 00 20 15 08, count; records {u32 type, f32 xyz, u32 0}
    return [struct.unpack_from("<IfffI", d, 8 + 20 * i) for i in range(n)]
names = sorted(n for n in disc("retail")[1] if n.upper().endswith(".PKP"))
for n in names:
    out = []
    for tag in ("retail", "online"):
        try: d = rawfile(tag, n)
        except KeyError: out.append(None); continue
        c = collections.Counter(r[0] for r in recs(d))
        out.append((len(d), dict(sorted(c.items()))))
    print(n, out[0], "|", out[1], "" if out[0] == out[1] else "  DIFF")
