# ruff: noqa
import struct, collections

D = "/mnt/d/TMB Decomp/fx/"


def rng(i):
    return (
        "veh<0x401"
        if i < 0x401
        else "fod<0xBB8"
        if i < 0xBB8
        else "ped<0xFA0"
        if i < 0xFA0
        else "other"
    )


res = {}
for tag in ("retail", "online"):
    d = open(D + f"{tag}_suburb.ngp", "rb").read()
    c = collections.Counter()
    ids = collections.defaultdict(set)
    for off in range(0, len(d) - 3, 4):
        (w,) = struct.unpack_from("<I", d, off)
        op = w & 0x3F
        rel = (w >> 6) & 1
        id2 = (w >> 7) & 0x7FF
        id1 = w >> 18
        if id1 == 0 or id2 != 0:
            continue  # interactive node heads seem to have id2 == 0
        if op > 0x24:
            continue
        c[(op, rel, rng(id1))] += 1
        ids[(op, rng(id1))].add(id1)
    res[tag] = (c, ids)
keys = sorted(
    set(res["retail"][0]) | set(res["online"][0]), key=lambda k: -res["retail"][0][k]
)
print("op rel range        retail online")
for k in keys[:40]:
    print(
        f"{k[0]:3d} {k[1]} {k[2]:10s} {res['retail'][0][k]:7d} {res['online'][0][k]:7d}"
    )
for k in sorted(res["retail"][1]):
    if k[1] == "fod<0xBB8":
        r = res["retail"][1][k]
        o = res["online"][1].get(k, set())
        print(
            "op",
            k[0],
            "fodder ids retail",
            len(r),
            sorted(r)[:12],
            "online",
            len(o),
            sorted(o)[:12],
        )
