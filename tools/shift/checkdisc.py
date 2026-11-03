# ruff: noqa
import sys, struct
sys.path.insert(0, "/mnt/d/TMB Decomp")
from isols import opener, walk
iso = sys.argv[1]
sector = opener(iso)
pvd = sector(16); root = pvd[156:190]
lba, = struct.unpack_from("<I", root, 2); size, = struct.unpack_from("<I", root, 10)
files = {n: (l, s) for n, l, s in walk(sector, lba, size, "/", [])}
ok = True
for f in sys.argv[2:]:
    n = "/PCAR/" + f
    if n not in files: print("MISSING", n); ok = False; continue
    l, s = files[n]
    d = sector(l, (s + 2047) // 2048)[:s]
    same = d == open("/mnt/d/TMB Decomp/packs/" + f, "rb").read()
    print(n, l, s, "identical" if same else "DIFFERENT"); ok &= same
print("cars still listed:", sum(1 for n in files if n.startswith("/PCAR/")), "| all ok:", ok, "| total files", len(files))
