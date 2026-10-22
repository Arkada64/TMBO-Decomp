# ruff: noqa
# List the LVL files of FREEWAY / PRISON / SUBURB / JUNKYARD on both discs, and the members inside each NGP.
import sys, struct

sys.path.insert(0, "/mnt/c/Users/Ark/Desktop/TMB Decomp")
from pedcount import files, members, W

for img, tag in (
    ("Twisted Metal - Black.iso", "retail"),
    ("Twisted Metal - Black Online.bin", "online"),
):
    sector, fs = files(W + img)
    print("==", tag)
    for n, (l, s) in sorted(fs.items()):
        if not n.startswith("/LVL/"):
            continue
        if not any(k in n for k in ("FREEWAY", "PRISON", "SUBURB", "JUNKYARD")):
            continue
        line = f"  {n:24} {s:9d}"
        if n.endswith(".NGP"):
            blob = sector(l, (s + 2047) // 2048)[:s]
            line += "  " + " ".join(f"{mn}:{len(d)}" for mn, d in members(blob))
        print(line)
