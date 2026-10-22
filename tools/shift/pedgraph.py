# ruff: noqa
"""
Ped (3000-3999) and fodder (2000-2999) subtrees in a level database, via the exact pointer list (.PTR):
  .PTR = N, N pointer-slot offsets, M, M u16 texture-id slot offsets, ...
Chunks = [pointer target, next target). A subtree = chunks reachable from its node through pointer slots.
Usage: python3 pedgraph.py LEVEL [retail|online]
"""
import sys, bisect, collections, struct
from ngpdb import get, w, head, BASE

def load(tag, lvl):
    ngp, ptr = get(tag, lvl, "NGP"), get(tag, lvl, "PTR")
    n = w(ptr, 0); slots = [w(ptr, 4 + 4 * i) for i in range(n)]
    m = w(ptr, 4 + 4 * n); tex = [w(ptr, 8 + 4 * n + 4 * i) for i in range(m)]
    rest = len(ptr) - (8 + 4 * n + 4 * m)
    return ngp, slots, tex, rest

def analyze(tag, lvl):
    ngp, slots, tex, rest = load(tag, lvl)
    size = len(ngp)
    tgt = {}
    bad = 0
    for s in slots:
        v = w(ngp, s)
        if BASE <= v < BASE + size: tgt[s] = v - BASE
        elif v: bad += 1
    bounds = sorted(set(tgt.values()) | {0, size} | {w(ngp, 4 + 4 * i) - BASE for i in range(w(ngp, 0))})
    sslots = sorted(tgt)
    def chunk(t):
        i = bisect.bisect_right(bounds, t) - 1
        return bounds[i], bounds[i + 1]
    def kids(c):
        a, b = c
        i, j = bisect.bisect_left(sslots, a), bisect.bisect_left(sslots, b)
        return {chunk(tgt[s]) for s in sslots[i:j]}
    def closure(starts, stop=frozenset()):
        seen, todo = set(), [chunk(s) for s in starts]
        while todo:
            c = todo.pop()
            if c in seen or c[0] in stop: continue
            seen.add(c); todo += kids(c)
        return seen
    nodes = collections.defaultdict(list)
    for t in set(tgt.values()):
        op, id2, id1 = head(w(ngp, t))
        if id2 == 0 and op <= 0x24 and 2000 <= id1 < 4000:
            nodes[("ped" if id1 < 3072 else "p3k") if id1 >= 3000 else "fod"].append((id1, t))
    eps = [w(ngp, 4 + 4 * i) - BASE for i in range(w(ngp, 0))]
    print(f"== {tag} {lvl}: {len(slots)} ptr slots ({bad} out of range), {len(tex)} tex slots, {rest} bytes after")
    stexs = sorted(tex)
    def texids(cs):
        ids = set()
        for a, b in cs:
            i, j = bisect.bisect_left(stexs, a), bisect.bisect_left(stexs, b)
            ids |= {struct.unpack_from("<H", ngp, s)[0] for s in stexs[i:j]}
        return ids
    for kind in ("ped", "p3k"):
        ns = sorted(nodes[kind])
        if not ns: print(f"   {kind}: none"); continue
        heads = {t for _, t in ns}
        mine = closure(heads)
        other = closure(eps, stop=frozenset(heads))           # everything not reached through these nodes
        shared = mine & other
        nb = sum(b - a for a, b in mine); sb = sum(b - a for a, b in shared)
        tm, to = texids(mine), texids(other)
        print(f"   {kind}: {len(ns)} nodes, ids {sorted(collections.Counter(i for i, _ in ns).items())}")
        print(f"      footprint {nb} bytes in {len(mine)} chunks; shared with rest of level: {sb} bytes / {len(shared)} chunks")
        print(f"      texture ids: {len(tm)} used, {len(tm - to)} used only by {kind}  (sample {sorted(tm)[:12]})")
        if kind == "ped":
            types = collections.Counter((i - 3000) >> 3 for i, _ in ns if i % 8 == 0)
            print(f"      ped models by type: {dict(sorted(types.items()))}")
    return nodes

if __name__ == "__main__":
    for tag in (sys.argv[2:] or ["retail", "online"]):
        analyze(tag, sys.argv[1])
