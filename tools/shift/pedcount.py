# ruff: noqa
# Count pedestrian (0xBB8..0xF9F) and fodder (0x401..0xBB7) node heads in every LVL/*.NGP, retail vs online.
import sys, struct, zlib, collections

sys.path.insert(0, "/mnt/d/TMB Decomp")
sys.path.insert(0, "/home/ark/tmbo_decomp/tools/shift")
from isols import opener, walk

W = "/mnt/d/TMB Decomp/"


def files(img):
    sector = opener(img)
    pvd = sector(16)
    root = pvd[156:190]
    (lba,) = struct.unpack_from("<I", root, 2)
    (size,) = struct.unpack_from("<I", root, 10)
    return sector, {n: (l, s) for n, l, s in walk(sector, lba, size, "/", [])}


def members(blob):
    i, out = 0, []
    while i + 30 <= len(blob) and blob[i + 2 : i + 4] == b"\x03\x04":
        (meth,) = struct.unpack_from("<H", blob, i + 8)
        cs, us = struct.unpack_from("<II", blob, i + 18)
        nl, el = struct.unpack_from("<HH", blob, i + 26)
        name = blob[i + 30 : i + 30 + nl].decode("ascii", "replace")
        d = blob[i + 30 + nl + el : i + 30 + nl + el + cs]
        out.append((name, zlib.decompressobj(-15).decompress(d) if meth == 8 else d))
        i += 30 + nl + el + cs
    return out


def count(d):
    c = collections.Counter()
    ids = collections.defaultdict(set)
    for off in range(0, len(d) - 3, 4):
        (w,) = struct.unpack_from("<I", d, off)
        op = w & 0x3F
        id2 = (w >> 7) & 0x7FF
        id1 = w >> 18
        if id1 == 0 or id2 != 0 or op > 0x24:
            continue
        k = "fod" if 0x401 <= id1 < 0xBB8 else "ped" if 0xBB8 <= id1 < 0xFA0 else None
        if k:
            c[k] += 1
            ids[k].add(id1)
    return c, ids


res = {}
for img, tag in (
    ()
    if __name__ != "__main__"
    else (
        ("Twisted Metal - Black.iso", "retail"),
        ("Twisted Metal - Black Online.bin", "online"),
    )
):
    sector, fs = files(W + img)
    for n, (l, s) in sorted(fs.items()):
        if not (n.startswith("/LVL/") and n.endswith(".NGP")):
            continue
        blob = sector(l, (s + 2047) // 2048)[:s]
        tot = collections.Counter()
        allids = collections.defaultdict(set)
        for mn, d in members(blob):
            c, ids = count(d)
            tot.update(c)
            for k in ids:
                allids[k] |= ids[k]
        res.setdefault(n, {})[tag] = (s, tot, {k: len(v) for k, v in allids.items()})
print(f"{'file':28} {'retail size/peds/fodder':32} {'online size/peds/fodder'}")
for n, r in sorted(res.items()):
    f = (
        lambda t: f"{r[t][0]:9d} ped {r[t][1]['ped']:4d}({r[t][2].get('ped', 0)}) fod {r[t][1]['fod']:4d}"
        if t in r
        else "-"
    )
    print(f"{n:28} {f('retail'):32} {f('online')}")
