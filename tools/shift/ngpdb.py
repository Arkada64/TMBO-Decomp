# ruff: noqa
"""
Level database analyzer (retail vs online). NGP member data is stored as if loaded at 0x980000.
  DbHeader: numEntryPts, epNode[numEntryPts] (pointers). HierHead word: op&0x3F, id2 (>>7)&0x7FF, id1 >>18.
Usage: python3 ngpdb.py dump LEVEL   |   extract LEVEL  (caches to fx/)
"""
import sys, struct, zlib, os, collections
sys.path.insert(0, "/mnt/d/TMB Decomp")
from isols import opener, walk
B = "/mnt/d/TMB Decomp/"
FX = B + "fx/"; os.makedirs(FX, exist_ok=True)
IMGS = {"retail": B + "Twisted Metal - Black.iso", "online": B + "Twisted Metal - Black Online.bin"}
BASE = 0x980000
_L = {}
def disc(tag):
    if tag not in _L:
        sector = opener(IMGS[tag]); pvd = sector(16); root = pvd[156:190]
        lba, = struct.unpack_from("<I", root, 2); size, = struct.unpack_from("<I", root, 10)
        _L[tag] = (sector, {n: (l, s) for n, l, s in walk(sector, lba, size, "/", [])})
    return _L[tag]
def rawfile(tag, path):
    sector, files = disc(tag); l, s = files[path]
    return sector(l, (s + 2047) // 2048)[:s]
def members(blob):
    i, out = 0, []
    while i + 30 <= len(blob) and blob[i + 2:i + 4] == b"\x03\x04":
        meth, = struct.unpack_from("<H", blob, i + 8)
        cs, us = struct.unpack_from("<II", blob, i + 18)
        nl, el = struct.unpack_from("<HH", blob, i + 26)
        name = blob[i + 30:i + 30 + nl].decode("ascii", "replace")
        d = blob[i + 30 + nl + el:i + 30 + nl + el + cs]
        out.append((name, zlib.decompressobj(-15).decompress(d) if meth == 8 else d))
        i += 30 + nl + el + cs
    return out
def get(tag, lvl, ext):
    """cached decompressed member (NGP/PTR may be zip containers or raw)"""
    p = FX + f"{tag}_{lvl.lower()}.{ext.lower()}"
    if not os.path.exists(p):
        raw = rawfile(tag, f"/LVL/{lvl}.{ext}")
        ms = members(raw)
        open(p, "wb").write(ms[0][1] if ms else raw)
    return open(p, "rb").read()
def w(d, o): return struct.unpack_from("<I", d, o)[0]
def head(word): return word & 0x3F, (word >> 7) & 0x7FF, word >> 18

if __name__ == "__main__":
    cmd, lvl = sys.argv[1], sys.argv[2]
    for tag in ("retail", "online"):
        ngp, ptr = get(tag, lvl, "NGP"), get(tag, lvl, "PTR")
        n = w(ngp, 0)
        eps = [w(ngp, 4 + 4 * i) for i in range(n)]
        print(f"== {tag} {lvl}: ngp {len(ngp)} bytes, {n} entry points, ptr {len(ptr)} bytes")
        print("   ptr words:", [hex(w(ptr, 4 * i)) for i in range(8)])
        ok = sum(BASE <= e < BASE + len(ngp) for e in eps)
        print(f"   eps in range: {ok}/{n}")
        c = collections.Counter()
        ped = []
        for e in eps:
            if not BASE <= e < BASE + len(ngp): continue
            op, id2, id1 = head(w(ngp, e - BASE))
            rng = "veh" if id1 < 0x401 else "fod" if id1 < 3000 else "ped" if id1 < 4000 else "oth"
            c[rng] += 1
            if rng == "ped": ped.append((id1, op, e - BASE))
        print("   ep id ranges:", dict(c))
        print("   ped eps:", [(i, o, hex(off)) for i, o, off in ped[:40]], "... total", len(ped))
