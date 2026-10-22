# ruff: noqa
"""
Build a car-style extra database ("pack") from part of a retail level: NGP + PTR (+ TEX/RTX, see texpack).
  python3 mkpack.py LEVEL NAME KIND      KIND = ped (ids 3000-3999) | fod (ids 1025-2999)
Output: TMB Decomp/packs/NAME.{NGP,PTR,TEX,RTX} + NAME.json (report)
Entry points: the nearest common group of all wanted nodes if its subtree has only wanted ids, else each
top-most wanted node (in traversal order). Data = every chunk reachable through pointer slots.
"""
import sys, os, bisect, struct, json, collections
from ngpdb import get, w, head, BASE
from ngptrav import traverse
OUT = "/mnt/c/Users/Ark/Desktop/TMB Decomp/packs/"; os.makedirs(OUT, exist_ok=True)
RANGES = {"ped": (3000, 4000), "fod": (0x401, 0xBB8)}

def load(lvl, tag="retail"):
    ngp, ptr = get(tag, lvl, "NGP"), get(tag, lvl, "PTR")
    n = w(ptr, 0); slots = [w(ptr, 4 + 4 * i) for i in range(n)]
    m = w(ptr, 4 + 4 * n); pairs = [(w(ptr, 8 + 4 * n + 8 * i), w(ptr, 12 + 4 * n + 8 * i)) for i in range(m)]
    return ngp, slots, pairs

def pick_eps(ngp, lo, hi):
    par = {}
    v = traverse(ngp, [4 + 4 * i for i in range(w(ngp, 0))], parents=par)
    wanted = [o for o, op, i1, i2 in v if lo <= i1 < hi]
    wset = set(wanted)
    def anc(o):
        out = []
        x = par.get(o)
        while x is not None: out.append(x); x = par.get(x)
        return out
    tops = [o for o in wanted if not any(a in wset for a in anc(o))]
    tops = list(dict.fromkeys(tops))
    # nearest common ancestor of all tops
    chains = [anc(t) for t in tops]
    common = [a for a in chains[0] if all(a in c for c in chains[1:])] if chains else []
    for cand in common:
        # the subtree of cand must only contain wanted callback ids (or id 0 internal nodes)
        sub = traverse(ngp, [], parents=None) if False else None
        # traverse from a fake slot: write nothing, use helper that takes node directly
        ids = subtree_ids(ngp, cand)
        if all(lo <= i < hi for i in ids if i):
            return [cand], tops, wanted
        break
    return tops, tops, wanted

def subtree_ids(ngp, node):
    # traverse() takes slots holding pointers; find a slot pointing at node by scanning is costly, so
    # build a 4-byte fake db: append the pointer at the end of a copy
    fake = bytearray(ngp) + struct.pack("<I", BASE + node)
    v = traverse(bytes(fake), [len(ngp)])
    return [i1 for o, op, i1, i2 in v]

def closure(ngp, slots, eps):
    size = len(ngp)
    tgt = {}
    for s in slots:
        v = w(ngp, s)
        if BASE <= v < BASE + size: tgt[s] = v - BASE
    bounds = sorted(set(tgt.values()) | {0, size} | set(eps))
    sslots = sorted(tgt)
    def chunk(t):
        i = bisect.bisect_right(bounds, t) - 1; return bounds[i], bounds[i + 1]
    seen, todo = set(), [chunk(e) for e in eps]
    while todo:
        c = todo.pop()
        if c in seen: continue
        seen.add(c)
        i, j = bisect.bisect_left(sslots, c[0]), bisect.bisect_left(sslots, c[1])
        todo += [chunk(tgt[s]) for s in sslots[i:j]]
    return sorted(seen), tgt

def limit_tops(ngp, tops, per_type):
    """keep at most per_type top nodes per ped id (in traversal order)"""
    from collections import Counter
    seen, keep = Counter(), []
    for t in tops:
        i = head(w(ngp, t))[2]
        if seen[i] < per_type: keep.append(t); seen[i] += 1
    return keep

def build(lvl, name, kind, per_type=None):
    lo, hi = RANGES[kind]
    ngp, slots, pairs = load(lvl)
    eps, tops, wanted = pick_eps(ngp, lo, hi)
    if per_type:
        eps = limit_tops(ngp, tops, per_type)
    chunks, tgt = closure(ngp, slots, eps)
    # merge adjacent chunks into runs, lay them out keeping offset mod 128
    runs = []
    for a, b in chunks:
        if runs and runs[-1][1] == a: runs[-1][1] = b
        else: runs.append([a, b])
    hdr = 4 + 4 * len(eps)
    pos = (hdr + 127) & ~127
    remap = []                                 # (old_a, old_b, new_a)
    for a, b in runs:
        pos += (a - pos) % 128
        remap.append((a, b, pos)); pos += b - a
    starts = [r[0] for r in remap]
    def new(off):
        i = bisect.bisect_right(starts, off) - 1
        if i < 0: return None
        a, b, na = remap[i]
        return na + (off - a) if a <= off < b else None
    out = bytearray(pos)
    for a, b, na in remap: out[na:na + b - a] = ngp[a:b]
    struct.pack_into("<I", out, 0, len(eps))
    for i, e in enumerate(eps): struct.pack_into("<I", out, 4 + 4 * i, BASE + new(e))
    nslots, dangling = [4 + 4 * i for i in range(len(eps))], 0
    for s in sorted(slots):
        ns = new(s)
        if ns is None: continue
        t = tgt.get(s)
        if t is None:
            if w(ngp, s): dangling += 1
            continue
        nt = new(t)
        if nt is None: dangling += 1; continue
        struct.pack_into("<I", out, ns, BASE + nt); nslots.append(ns)
    npairs = []
    for ts, gs in pairs:
        nts = new(ts) if ts else 0
        ngs = new(gs) if gs else 0
        if (ts and nts is None) or (gs and ngs is None): continue
        if ts == 0 and gs == 0: continue
        npairs.append((nts or 0, ngs or 0))
    ptr = struct.pack("<I", len(nslots)) + b"".join(struct.pack("<I", s) for s in nslots)
    ptr += struct.pack("<I", len(npairs)) + b"".join(struct.pack("<II", a, b) for a, b in npairs)
    ptr += b"\0" * (-len(ptr) % 16)
    out += b"\0" * (-len(out) % 128)
    # self-check: every pointer in the pack lands inside the pack; traversal sees the wanted ids
    bad = [s for s in nslots if not BASE <= w(out, s) < BASE + len(out)]
    v = traverse(bytes(out), [4 + 4 * i for i in range(len(eps))])
    ids = collections.Counter(i1 for o, op, i1, i2 in v if i1)
    # animation characters of the wanted ids: retail's op7 (global animation table) entries; animationGetHandle
    # finds a ped's clips by (id1, id2) in these tables, so the loader must add them to table 0
    anims = []
    for e in [w(ngp, 4 + 4 * i) - BASE for i in range(w(ngp, 0))]:
        if head(w(ngp, e))[0] != 7: continue
        for i in range(w(ngp, e + 4)):
            a = w(ngp, e + 8 + 4 * i) - BASE
            if lo <= head(w(ngp, a))[2] < hi:
                na = new(a)
                assert na is not None, f"anim entry {hex(a)} not in the pack"
                anims.append(na)
    rep = {"anims": anims, "level": lvl, "kind": kind, "eps": [hex(e) for e in eps], "tops": len(tops), "wanted_nodes": len(wanted),
           "ngp_bytes": len(out), "chunks": len(chunks), "runs": len(runs), "ptr_slots": len(nslots),
           "tex_pairs": len(npairs), "dangling": dangling, "bad_ptrs": len(bad),
           "ids_seen": sorted(ids.items()), "texids": sorted({struct.unpack_from("<H", out, a)[0] for a, b in npairs if a})}
    open(OUT + name + ".NGP", "wb").write(out)
    open(OUT + name + ".PTR", "wb").write(ptr)
    json.dump(rep, open(OUT + name + ".json", "w"), indent=1)
    return rep, out, npairs

if __name__ == "__main__":
    pt = int(sys.argv[4]) if len(sys.argv) > 4 else None
    rep, _, _ = build(sys.argv[1], sys.argv[2], sys.argv[3], pt)
    print(json.dumps({k: v for k, v in rep.items() if k != "texids"}, indent=None)[:1500])
    print("texids:", len(rep["texids"]), rep["texids"][:30])
