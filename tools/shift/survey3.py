# ruff: noqa
"""Story phase 3 survey: every level's node ids (callback ids) and its other files, retail vs online.
Run from TMB Decomp: python3 cloud/in/g3/survey3.py > cloud/qb_out/survey3.txt"""
import sys, collections
sys.path.insert(0, "/mnt/d/TMB Decomp"); sys.path.insert(0, "/mnt/d/TMB Decomp/tools/shift")
from ngpdb import get, disc
from ngptrav import visit
def cls(i):
    if 1 <= i <= 1024: return "veh"
    if 1025 <= i < 3000: return "fod"
    if 3000 <= i < 4000: return "ped"
    if 4000 <= i < 5000: return "wpn"
    return "x%d" % (i // 1000)
lv = sorted({n[5:].rsplit(".", 1)[0] for n in disc("retail")[1] if n.startswith("/LVL/") and n.endswith(".NGP")})
rf, of = disc("retail")[1], disc("online")[1]
for l in lv:
    print("==", l)
    exts = sorted({n.rsplit(".", 1)[1] for n in list(rf) + list(of) if n.startswith("/LVL/" + l + ".")})
    for e in exts:
        a, b = rf.get("/LVL/%s.%s" % (l, e)), of.get("/LVL/%s.%s" % (l, e))
        print("  file %-4s retail %9s online %9s%s" % (e, a[1] if a else "-", b[1] if b else "-", "" if a and b and a[1] == b[1] else "   DIFF"))
    ids = {}
    for tag in ("retail", "online"):
        try: v = visit(get(tag, l, "NGP"))
        except Exception as ex: ids[tag] = None; print("  ", tag, "walk failed", ex); continue
        c = collections.Counter()
        for o, op, i1, i2 in v:
            if i1: c[(i1, op)] += 1
        ids[tag] = c
    r, o = ids.get("retail"), ids.get("online")
    if r is None or o is None: continue
    keys = sorted(set(r) | set(o))
    diff = [(k, r.get(k, 0), o.get(k, 0)) for k in keys if r.get(k, 0) != o.get(k, 0) and cls(k[0]) not in ("ped", "fod")]
    print("  ids retail %d online %d, differing (non ped/fodder) %d" % (len(r), len(o), len(diff)))
    for (i1, op), a, b in diff[:60]:
        print("    id %5d (%s) op %2d  retail %3d online %3d" % (i1, cls(i1), op, a, b))
