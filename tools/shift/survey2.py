# ruff: noqa
"""Exact (traversal-based) survey of every level: distinct ped ids, fodder ids, retail vs online."""
import collections, json
from ngpdb import get, disc
from ngptrav import visit
lvls = sorted({n[5:].rsplit(".", 1)[0] for n in disc("retail")[1] if n.startswith("/LVL/") and n.endswith(".NGP")})
res = {}
for l in lvls:
    row = {}
    for tag in ("retail", "online"):
        try: v = visit(get(tag, l, "NGP"))
        except KeyError: row[tag] = None; continue
        ped = sorted({i1 for o, op, i1, i2 in v if 3000 <= i1 < 4000})
        fod = sorted({i1 for o, op, i1, i2 in v if 0x401 <= i1 < 0xBB8})
        row[tag] = {"ped": ped, "fod": fod}
    res[l] = row
    r, o = row["retail"], row["online"]
    rp, op_ = set(r["ped"]), set(o["ped"]) if o else set()
    rf, of = set(r["fod"]), set(o["fod"]) if o else set()
    print(f"{l:9s} peds retail {len(rp):2d} online {len(op_):2d} missing {sorted(rp - op_)[:10]}"
          f" | fodder ids retail {len(rf):3d} online {len(of):3d} missing {len(rf - of)}", flush=True)
json.dump(res, open("/mnt/d/TMB Decomp/fx/survey2.json", "w"))
