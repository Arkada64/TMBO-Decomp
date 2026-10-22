# ruff: noqa
import sys, struct


def opener(path):
    f = open(path, "rb")
    f.seek(0, 2)
    size = f.tell()
    raw = size % 2352 == 0 and not path.lower().endswith(".iso")

    def sector(n, count=1):
        out = b""
        for i in range(count):
            if raw:
                f.seek((n + i) * 2352)
                s = f.read(2352)
                mode = s[15]
                out += s[24 : 24 + 2048] if mode == 2 else s[16 : 16 + 2048]
            else:
                f.seek((n + i) * 2048)
                out += f.read(2048)
        return out

    return sector


def walk(sector, lba, size, prefix, out):
    data = sector(lba, (size + 2047) // 2048)
    i = 0
    while i < len(data):
        l = data[i]
        if l == 0:
            i = (i // 2048 + 1) * 2048
            continue
        rec = data[i : i + l]
        (elba,) = struct.unpack_from("<I", rec, 2)
        (esz,) = struct.unpack_from("<I", rec, 10)
        flags = rec[25]
        nl = rec[32]
        name = rec[33 : 33 + nl]
        if name not in (b"\0", b"\1"):
            n = name.decode("ascii", "replace").split(";")[0]
            if flags & 2:
                walk(sector, elba, esz, prefix + n + "/", out)
            else:
                out.append((prefix + n, elba, esz))
        i += l
    return out


if __name__ == "__main__":
    path = sys.argv[1]
    sector = opener(path)
    pvd = sector(16)
    root = pvd[156 : 156 + 34]
    (lba,) = struct.unpack_from("<I", root, 2)
    (size,) = struct.unpack_from("<I", root, 10)
    for n, l, s in walk(sector, lba, size, "/", []):
        print(f"{l:8d} {s:10d} {n}")
