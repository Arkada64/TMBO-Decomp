# ruff: noqa
"""Offline check of a placed pack: load the blobs at their absolute addresses in a fake RAM image, read the
manifest like mods/packs.c does, walk the entry points with the exact dbsTraverse port, check pointers/texture
pairs/TEX/RTX. Usage: python3 verifyblobs.py NAME"""
import sys, struct, collections, json
import ngptrav
from texfile import recs
OUT = "/mnt/c/Users/Ark/Desktop/TMB Decomp/packs/"
name = sys.argv[1]
lay = json.load(open(OUT + name + ".layout.json"))
blobs = [(fn, int(a, 16), sz) for fn, a, sz in lay["blobs"]]
lo = min(a for _, a, _ in blobs); hi = max(a + s for _, a, s in blobs)
ram = bytearray(hi - lo)
for fn, a, s in blobs:
    d = open(OUT + fn, "rb").read(); assert len(d) == s; ram[a - lo:a - lo + s] = d
R = lambda addr: struct.unpack_from("<I", ram, addr - lo)[0]
inblob = lambda addr: any(a <= addr < a + s for _, a, s in blobs)
m = blobs[0][1]
magic, ver, nb, hdr, pairs, npairs, tex, rtx, clut, ntex = struct.unpack_from("<10I", ram, m - lo)
assert magic == 0x50424D54 and nb == len(blobs), "manifest"
for k in range(nb):
    fn, a, s = struct.unpack_from("<16sII", ram, m - lo + 64 + 24 * k)
    assert (fn.rstrip(b"\0").decode(), a, s) == blobs[k], ("blob table", k)
neps = R(hdr)
ngptrav.BASE = lo                          # traverse() resolves pointers against this base
v = ngptrav.traverse(bytes(ram), [hdr - lo + 4 + 4 * i for i in range(neps)])
ids = collections.Counter(i1 for o, op, i1, i2 in v if i1)
print("entry points", neps, "callbacks", len(v), "ids", sorted(ids.items()))
bad = [hex(lo + o) for o, op, i1, i2 in v if not inblob(lo + o)]
print("nodes outside blobs:", len(bad))
pr = [struct.unpack_from("<II", ram, pairs - lo + 8 * k) for k in range(npairs)]
tids = sorted({struct.unpack_from("<H", ram, a - lo)[0] for a, g in pr if a})
cbps = sorted({(struct.unpack_from("<Q", ram, g - lo)[0] >> 37) & 0x3FFF for a, g in pr if g})
print("pairs", npairs, "tex ids", tids, "CLUT addrs (pack-relative)", cbps)
_, trs, _ = recs(bytes(ram[tex - lo:tex - lo + 0x80000]))
_, rrs, _ = recs(bytes(ram[rtx - lo:rtx - lo + 0x10000]))
print("TEX records", len(trs), "ids", sorted(r["id"] for r in trs), "| RTX records", len(rrs), "addrs", sorted(r["addr"] for r in rrs))
print("clut blocks", clut, "ntex", ntex, "| all node pointers inside blobs:", not bad)
