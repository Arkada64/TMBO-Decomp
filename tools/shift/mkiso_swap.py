# ruff: noqa
# Build a test disc: the online disc as a 2048-byte ISO with retail's LVL/SUBURB.* files swapped in.
# New file data is appended at the end of the image; only the directory records (LBA + size) and the
# volume size in the PVD are changed. Output: TMBO_suburb_retail.iso (next to this script).
import sys, struct, os

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from isols import opener, walk

W = os.path.dirname(os.path.abspath(__file__))
ONLINE = os.path.join(W, "Twisted Metal - Black Online.bin")
RETAIL = os.path.join(W, "Twisted Metal - Black.iso")
OUT = os.path.join(W, "TMBO_suburb_retail.iso")
SWAP = ["/LVL/SUBURB.NGP", "/LVL/SUBURB.TEX", "/LVL/SUBURB.RTX", "/LVL/SUBURB.PTR"]

on = opener(ONLINE)
re_ = opener(RETAIL)
nsec = os.path.getsize(ONLINE) // 2352
with open(OUT, "wb") as f:  # 1. raw .bin -> 2048-byte ISO
    for s in range(0, nsec, 512):
        f.write(on(s, min(512, nsec - s)))


def files(sector):
    pvd = sector(16)
    root = pvd[156:190]
    (lba,) = struct.unpack_from("<I", root, 2)
    (size,) = struct.unpack_from("<I", root, 10)
    return {n: (l, s) for n, l, s in walk(sector, lba, size, "/", [])}


rf = files(re_)
iso = open(OUT, "r+b")


def isec(n, c=1):
    iso.seek(n * 2048)
    return iso.read(c * 2048)


of = files(isec)
end = nsec
for name in SWAP:  # 2. append retail file data
    l, s = rf[name]
    data = re_(l, (s + 2047) // 2048)[:s]
    iso.seek(end * 2048)
    iso.write(data + b"\0" * (-len(data) % 2048))
    newlba, newsize = end, s
    end += (s + 2047) // 2048
    # 3. patch the directory record of this file in the online image
    d = name.rsplit("/", 1)
    dirname, fname = d[0], d[1]
    pvd = isec(16)
    root = pvd[156:190]
    (rl,) = struct.unpack_from("<I", root, 2)
    (rs,) = struct.unpack_from("<I", root, 10)
    dl, ds = rl, rs
    for part in dirname.strip("/").split("/"):
        data = isec(dl, (ds + 2047) // 2048)
        i = 0
        found = None
        while i < len(data):
            L = data[i]
            if L == 0:
                i = (i // 2048 + 1) * 2048
                continue
            if (
                data[i + 33 : i + 33 + data[i + 32]]
                .decode("ascii", "replace")
                .split(";")[0]
                == part
            ):
                found = (
                    struct.unpack_from("<II", data, i + 2)[0],
                    struct.unpack_from("<I", data, i + 10)[0],
                )
            i += L
        dl, ds = found
    data = bytearray(isec(dl, (ds + 2047) // 2048))
    i = 0
    ok = False
    while i < len(data):
        L = data[i]
        if L == 0:
            i = (i // 2048 + 1) * 2048
            continue
        if (
            data[i + 33 : i + 33 + data[i + 32]]
            .decode("ascii", "replace")
            .split(";")[0]
            == fname
        ):
            struct.pack_into("<I", data, i + 2, newlba)
            struct.pack_into(">I", data, i + 6, newlba)
            struct.pack_into("<I", data, i + 10, newsize)
            struct.pack_into(">I", data, i + 14, newsize)
            ok = True
        i += L
    assert ok, name
    iso.seek(dl * 2048)
    iso.write(data)
    print(f"{name}: online {of[name][1]} bytes -> retail {s} bytes at LBA {newlba}")
pvd = bytearray(isec(16))  # 4. volume space size
struct.pack_into("<I", pvd, 80, end)
struct.pack_into(">I", pvd, 84, end)
iso.seek(16 * 2048)
iso.write(pvd)
iso.close()
chk = files(opener(OUT))
for name in SWAP:
    print("check", name, chk[name])
print("wrote", OUT, end * 2048 // (1 << 20), "MB")
