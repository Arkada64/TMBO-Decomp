# ruff: noqa
import sys, struct, zlib, collections

sys.path.insert(0, "/mnt/d/TMB Decomp")
from isols import opener, walk


def getfile(img, name):
    sector = opener(img)
    pvd = sector(16)
    root = pvd[156:190]
    (lba,) = struct.unpack_from("<I", root, 2)
    (size,) = struct.unpack_from("<I", root, 10)
    for n, l, s in walk(sector, lba, size, "/", []):
        if n == name:
            return sector(l, (s + 2047) // 2048)[:s]


def members(blob):
    i, out = 0, []
    while i + 30 <= len(blob) and blob[i + 2 : i + 4] == b"\x03\x04":
        (meth,) = struct.unpack_from("<H", blob, i + 8)
        cs, us = struct.unpack_from("<II", blob, i + 18)
        nl, el = struct.unpack_from("<HH", blob, i + 26)
        name = blob[i + 30 : i + 30 + nl].decode("ascii", "replace")
        d = blob[i + 30 + nl + el : i + 30 + nl + el + cs]
        data = zlib.decompressobj(-15).decompress(d) if meth == 8 else d
        out.append((name, data))
        i += 30 + nl + el + cs
    return out, blob[:2]


for img, tag in (
    ("Twisted Metal - Black.iso", "retail"),
    ("Twisted Metal - Black Online.bin", "online"),
):
    blob = getfile("/mnt/d/TMB Decomp/" + img, "/LVL/SUBURB.NGP")
    ms, sig = members(blob)
    print(tag, "sig", sig, [(n, len(d)) for n, d in ms])
    for n, d in ms:
        open(f"/mnt/d/TMB Decomp/fx/{tag}_{n}", "wb").write(d)
        c = collections.Counter()
        for (w,) in struct.iter_unpack("<I", d[: len(d) // 4 * 4]):
            nid = w >> 18
            if 0x401 <= nid < 0xBB8:
                c["fodder 0x401-0xBB7"] += 1
            if 0xBB8 <= nid < 0xFA0:
                c["peds 0xBB8-0xF9F"] += 1
            if 0 < nid < 0x401:
                c["vehicles <0x401"] += 1
        print("  ", n, dict(c))
