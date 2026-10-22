# ruff: noqa
"""
Test disc for the content packs: the online disc as a 2048-byte ISO plus new files in \PCAR\ (packs/*.BIN).
File data is appended at the end of the image; the new directory records go into the free tail of the \PCAR
directory's sectors (names starting with Z sort last); the PVD volume size is updated. Nothing else moves.
  python3 mkdisc.py OUT.iso FILE...          (FILEs from packs/, stored under \PCAR\ with their base name)
The plain ISO conversion is cached in packs/TMBO_base.iso.
"""
import sys, os, struct, shutil
sys.path.insert(0, "/mnt/c/Users/Ark/Desktop/TMB Decomp")
from isols import opener
W = "/mnt/c/Users/Ark/Desktop/TMB Decomp/"
ONLINE = W + "Twisted Metal - Black Online.bin"
BASEISO = W + "packs/TMBO_base.iso"
S = 2048

def base_iso():
    if os.path.exists(BASEISO): return
    on = opener(ONLINE)
    nsec = os.path.getsize(ONLINE) // 2352
    with open(BASEISO + ".tmp", "wb") as f:
        for s in range(0, nsec, 512): f.write(on(s, min(512, nsec - s)))
    os.rename(BASEISO + ".tmp", BASEISO)

def dirrecs(sec_data):
    """(offset, record bytes) for every record in one directory sector"""
    out, o = [], 0
    while o < len(sec_data) and sec_data[o]:
        n = sec_data[o]; out.append((o, sec_data[o:o + n])); o += n
    return out, o

def find(iso, lba, size, name):
    for s in range(size // S):
        iso.seek((lba + s) * S); d = iso.read(S)
        recs, _ = dirrecs(d)
        for o, r in recs:
            nm = r[33:33 + r[32]].decode("ascii", "replace")
            if nm == name: return struct.unpack_from("<I", r, 2)[0], struct.unpack_from("<I", r, 10)[0]
    return None

def record(name, lba, size, template):
    nm = name.encode() + b";1"
    n = 33 + len(nm); n += n & 1
    r = bytearray(n)
    r[0] = n; r[1] = 0
    struct.pack_into("<I", r, 2, lba); struct.pack_into(">I", r, 6, lba)
    struct.pack_into("<I", r, 10, size); struct.pack_into(">I", r, 14, size)
    r[18:25] = template[18:25]           # date
    r[25] = 0; r[26] = 0; r[27] = 0
    r[28:32] = template[28:32]           # volume sequence number
    r[32] = len(nm); r[33:33 + len(nm)] = nm
    return bytes(r)

def build(out, files):
    base_iso()
    shutil.copyfile(BASEISO, out)
    iso = open(out, "r+b")
    iso.seek(16 * S); pvd = bytearray(iso.read(S))
    vol = struct.unpack_from("<I", pvd, 80)[0]
    root = pvd[156:190]
    rl, rs = struct.unpack_from("<I", root, 2)[0], struct.unpack_from("<I", root, 10)[0]
    pl, ps = find(iso, rl, rs, "PCAR")
    # free room in the last used sector of \PCAR
    last, tail, tmpl = None, None, None
    for s in range(ps // S):
        iso.seek((pl + s) * S); d = iso.read(S)
        recs, end = dirrecs(d)
        if recs: last, tail, tmpl = s, end, recs[-1][1]
    iso.seek((pl + last) * S); sec = bytearray(iso.read(S))
    existing = {r[33:33 + r[32]].decode() for o, r in dirrecs(sec)[0]}
    lba = vol
    for f in files:
        name = os.path.basename(f).upper()
        data = open(f, "rb").read()
        r = record(name, lba, len(data), tmpl)
        if name + ";1" in existing: raise SystemExit(f"{name} already in \\PCAR (rebuild from the base)")
        if tail + len(r) > S: raise SystemExit("no room left in the \\PCAR directory sector")
        sec[tail:tail + len(r)] = r; tail += len(r)
        iso.seek(lba * S); iso.write(data + b"\0" * (-len(data) % S))
        print(f"  \\PCAR\\{name}: LBA {lba}, {len(data)} bytes")
        lba += (len(data) + S - 1) // S
    iso.seek((pl + last) * S); iso.write(sec)
    struct.pack_into("<I", pvd, 80, lba); struct.pack_into(">I", pvd, 84, lba)
    iso.seek(16 * S); iso.write(pvd)
    iso.seek(lba * S - 1); iso.write(b"\0") if os.path.getsize(out) < lba * S else None
    iso.close()
    print(f"{out}: volume {vol} -> {lba} sectors, \\PCAR sector free bytes left {S - tail}")

if __name__ == "__main__":
    build(sys.argv[1], sys.argv[2:])
