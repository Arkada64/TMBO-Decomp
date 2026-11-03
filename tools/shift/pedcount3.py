# ruff: noqa
# Which ped-related names (models/anims/textures) are in each map's NGP, retail vs online?
import sys, re

sys.path.insert(0, "/mnt/d/TMB Decomp")
from pedcount import files, members, W

want = ("/LVL/FREEWAY.NGP", "/LVL/PRISON.NGP", "/LVL/SUBURB.NGP")
names = {}
for img, tag in (
    ("Twisted Metal - Black.iso", "retail"),
    ("Twisted Metal - Black Online.bin", "online"),
):
    sector, fs = files(W + img)
    for n in want:
        l, s = fs[n]
        d = b"".join(m for _, m in members(sector(l, (s + 2047) // 2048)[:s]))
        names[(n, tag)] = {
            x.decode()
            for x in re.findall(
                rb"[A-Za-z0-9_]{0,24}(?:ped|PED|Ped|pedestrian|PEDESTRIAN)[A-Za-z0-9_]{0,24}",
                d,
            )
        }
for n in want:
    r, o = names[(n, "retail")], names[(n, "online")]
    print(
        n,
        f"retail {len(r)} names, online {len(o)}; only in retail: {sorted(r - o)[:25]}",
    )
