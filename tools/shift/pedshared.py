# ruff: noqa
"""
For retail ped subtrees (ids 3000-3071): which chunks are exclusive vs shared with the level, and do the
shared ones exist in the online level (byte match with pointer words masked)?
Usage: python3 pedshared.py LEVEL
"""
import sys, bisect, struct, hashlib, collections
from ngpdb import get, w, head, BASE

def graph(tag, lvl):
    ngp, ptr = get(tag, lvl, "NGP"), get(tag, lvl, "PTR")
    n = w(ptr, 0); slots = sorted(w(ptr, 4 + 4 * i) for i in range(n))
    tgt = {s: w(ngp, s) - BASE for s in slots if BASE <= w(ngp, s) < BASE + len(ngp)}
    eps = [w(ngp, 4 + 4 * i) - BASE for i in range(w(ngp, 0))]
    bounds = sorted(set(tgt.values()) | {0, len(ngp)} | set(eps))
    return ngp, slots, tgt, eps, bounds

def masked(ngp, slots, a, b):
    d = bytearray(ngp[a:b])
    for s in slots[bisect.bisect_left(slots, a):bisect.bisect_left(slots, b)]:
        d[s - a:s - a + 4] = b"PPPP"
    return bytes(d)

lvl = sys.argv[1]
ngp, slots, tgt, eps, bounds = graph("retail", lvl)
sslots = sorted(tgt)
def chunk(t):
    i = bisect.bisect_right(bounds, t) - 1; return bounds[i], bounds[i + 1]
def kids(c):
    i, j = bisect.bisect_left(sslots, c[0]), bisect.bisect_left(sslots, c[1])
    return {chunk(tgt[s]) for s in sslots[i:j]}
def closure(starts, stop=frozenset()):
    seen, todo = set(), [chunk(s) for s in starts]
    while todo:
        c = todo.pop()
        if c in seen or c[0] in stop: continue
        seen.add(c); todo += kids(c)
    return seen
peds = sorted((head(w(ngp, t))[2], t) for t in set(tgt.values())
              if head(w(ngp, t))[1] == 0 and 3000 <= head(w(ngp, t))[2] < 3072 and head(w(ngp, t))[0] <= 0x24)
heads = frozenset(t for _, t in peds)
mine, other = closure(heads), closure(eps, stop=heads)
shared, excl = mine & other, mine - other
print(f"retail {lvl}: ped nodes {[(i, hex(t)) for i, t in peds]}")
print(f"  exclusive {sum(b-a for a,b in excl)} bytes / {len(excl)} chunks; shared {sum(b-a for a,b in shared)} bytes / {len(shared)} chunks")
# who in the rest of the level points at the shared chunks? (parents outside the ped subtree)
par = collections.Counter()
inv = collections.defaultdict(set)
for s, t in tgt.items(): inv[chunk(t)].add(chunk(s))
for c in shared:
    for p in inv[c]:
        if p in other and p not in mine:
            op, id2, id1 = head(w(ngp, p[0]))
            par[(op, id1)] += 1
print("  shared chunks' outside parents (op, id1 of parent chunk head):", par.most_common(8))
sizes = collections.Counter(b - a for a, b in shared)
print("  shared chunk sizes (top):", sizes.most_common(6))
# online presence
on, oslots, otgt, oeps, ob = graph("online", lvl)
idx = collections.defaultdict(list)
for i in range(len(ob) - 1):
    a, b = ob[i], ob[i + 1]
    if b - a >= 16: idx[(b - a, hashlib.md5(masked(on, oslots, a, b)).digest())].append(a)
def present(cs):
    hit = [c for c in cs if c[1] - c[0] < 16 or (c[1] - c[0], hashlib.md5(masked(ngp, slots, *c)).digest()) in idx]
    return sum(b - a for a, b in hit), len(hit)
print("  shared chunks found in online %s: %d bytes / %d chunks" % ((lvl,) + present(shared)))
print("  exclusive chunks found in online %s: %d bytes / %d chunks" % ((lvl,) + present(excl)))
