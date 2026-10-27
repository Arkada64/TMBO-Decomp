"""Exact collision trees for converted Head-On pieces (replaces lvcol.build_piece's sample-labelled trees, which
were solid far outside the pieces: Ark 2026-10-26 "the collision is all wrong").
Solid = the union of convex prisms, one per convex polygon of a piece's surface (coplanar neighbouring triangles
merged while the polygon stays convex): the surface (outward), a back face DEPTH behind it (SLAB on both sides for
mostly vertical open parts: fences / walls) and a side plane per boundary edge (perpendicular to the surface).
Tree (a DAG - children may be shared, the game only follows pointers): axis-aligned splits (median of the prisms'
centres; a prism that straddles goes to both sides, so a split plane is never where a segment first meets solid)
down to <= LEAF prisms, then a chain: for each prism, its planes in turn - outside (front) goes on to the next
prism's chain, inside all of them (back of the last) = solid. Every empty->solid boundary is a real prism face, as
in the retail trees (front leaf 0x200, back leaf a material)."""
import math
import numpy as np
from lvcol import orient, normalize, EMPTY, SOLID, DEPTH, SLAB

LEAF = 4
VERT_NZ = 0.25
CHAIN_MAX = 5                 # cells with this few prisms end in a chain
EPS = 1e-4


def convex_polys(P, N, w, tri_ids):
    """greedy: merge edge-sharing coplanar triangles into convex polygons. P (k,3,3) oriented; returns lists of
    vertex loops (np arrays, CCW about the plane normal)"""
    if len(tri_ids) == 1:
        return [P[tri_ids[0]]]
    n_ = N[tri_ids[0]]
    # vertex ids by rounded position
    key = {}
    def vid(p):
        k = tuple(np.round(p * 64).astype(np.int64))
        if k not in key: key[k] = (len(key), p)
        return key[k][0]
    tris = [[vid(p) for p in P[t]] for t in tri_ids]
    pos = {v: p for v, p in key.values()}
    alive = [True] * len(tris)
    polys = [list(t) for t in tris]
    def convex(loop):
        m = len(loop)
        for i in range(m):
            a, b, c = pos[loop[i]], pos[loop[(i + 1) % m]], pos[loop[(i + 2) % m]]
            if np.cross(b - a, c - b) @ n_ < -1e-3: return False
        return True
    changed = True
    while changed:
        changed = False
        emap = {}
        for i, pl in enumerate(polys):
            if not alive[i]: continue
            for j in range(len(pl)):
                emap[(pl[j], pl[(j + 1) % len(pl)])] = i
        for (a, b), i in list(emap.items()):
            j = emap.get((b, a))
            if j is None or j == i or not alive[i] or not alive[j]: continue
            A, B = polys[i], polys[j]
            ia = A.index(a); jb = B.index(b)
            # A: ... a b ...  B: ... b a ...  -> A up to a, then B after a (around) back to b, then A after b
            if A[(ia + 1) % len(A)] != b or B[(jb + 1) % len(B)] != a: continue
            seqA = [A[(ia + 1 + k) % len(A)] for k in range(len(A))]          # b ... a
            seqB = [B[(jb + 1 + k) % len(B)] for k in range(len(B))]          # a ... b
            loop = seqA[:-1] + seqB[:-1]                                          # b..(before a), a..(before b)
            if len(set(loop)) != len(loop): continue
            # drop collinear vertices
            m = len(loop); keep = []
            for k in range(m):
                p0, p1, p2 = pos[loop[k - 1]], pos[loop[k]], pos[loop[(k + 1) % m]]
                if np.linalg.norm(np.cross(p1 - p0, p2 - p1)) > 1e-4: keep.append(loop[k])
            if len(keep) < 3 or not convex(keep): continue
            polys[i] = keep; alive[j] = False; changed = True
            break
    return [np.array([pos[v] for v in pl]) for i, pl in enumerate(polys) if alive[i]]


THIN = 12.0


def extrude_dir(n_):
    """the prism's depth direction: up / down for ground and ceilings, else the face's horizontal direction
    rounded to 16 headings (so a flat wall's triangles share it)"""
    if abs(n_[2]) > VERT_NZ: return np.array([0.0, 0.0, 1.0 if n_[2] > 0 else -1.0])
    a = math.atan2(n_[1], n_[0]); a = round(a / (math.pi / 8)) * (math.pi / 8)
    return np.array([math.cos(a), math.sin(a), 0.0])


def prisms_of(W, T):
    T, slab = orient(W, T)
    P = W[T]
    N = np.cross(P[:, 1] - P[:, 0], P[:, 2] - P[:, 0]); A = np.linalg.norm(N, axis=1)
    keep = A > 1e-4
    P, N, slab = P[keep], N[keep] / A[keep, None], slab[keep]
    if not len(P): return []
    w = (N * P[:, 0]).sum(1)
    key = np.c_[np.round(N * 500), np.round(w * 4), slab].astype(np.int64)
    _, gid = np.unique(key, axis=0, return_inverse=True); gid = gid.reshape(-1)
    out = []
    for g in range(gid.max() + 1):
        ids = np.where(gid == g)[0]
        n_ = N[ids[0]]; sl = bool(slab[ids[0]])
        for loop in convex_polys(P, N, w, ids):
            w0 = float(n_ @ loop.mean(0))
            d = extrude_dir(n_)                       # sides contain d: neighbours with the same d share them
            dl = loop @ d
            if sl:                                    # slab: both faces across d, offsets on a 4-unit grid
                planes = [(d, math.ceil((dl.max() + SLAB) / 4) * 4.0), (-d, -math.floor((dl.min() - SLAB) / 4) * 4.0)]
            else:                                     # the surface, and a back face across d on an 8-unit grid
                planes = [(n_, w0), (-d, -math.floor((dl.min() - DEPTH) / 8) * 8.0)]
            for k in range(len(loop)):
                e = loop[(k + 1) % len(loop)] - loop[k]
                sn = np.cross(e, d); ln = np.linalg.norm(sn)
                if ln > 1e-6: sn = sn / ln; planes.append((sn, float(sn @ loop[k])))
            pts = np.array(_prism_pts(planes))
            if len(planes) < 5 or len(pts) < 4: continue          # degenerate (face edge-on to its depth direction)
            out.append((planes, pts.min(0), pts.max(0)))
    return out


def build_piece(W, T):
    """-> (nodes, root, prisms) like lvcol.build_piece (nodes: [front, back, matF, matB, (n, w)])"""
    prs = prisms_of(W, T)
    if not prs: return None
    nodes = []
    memo = {}
    def chain(ids):
        key = ('c',) + tuple(ids)
        if key in memo: return memo[key]
        nxt = chain(ids[1:]) if len(ids) > 1 else None             # outside this prism -> the rest
        planes = prs[ids[0]][0]
        back = None                                                 # inside every plane -> solid leaf
        for n_, w_ in reversed(planes):
            nodes.append([nxt, back, EMPTY, SOLID, (np.asarray(n_, float), float(w_))])
            back = len(nodes) - 1
        memo[key] = back
        return back
    def kd(ids, depth):
        if len(ids) <= LEAF or depth > 40:
            return chain(sorted(ids))
        lo = np.array([prs[i][1] for i in ids]); hi = np.array([prs[i][2] for i in ids])
        c = (lo + hi) / 2
        ax = int(np.argmax(c.max(0) - c.min(0)))
        m = float(np.median(c[:, ax]))
        front = [ids[k] for k in range(len(ids)) if hi[k][ax] > m]       # reaches x > m
        back = [ids[k] for k in range(len(ids)) if lo[k][ax] < m]        # reaches x < m
        if max(len(front), len(back)) > 0.75 * len(ids):                 # straddlers: no real split
            return chain(sorted(ids))
        nv = np.zeros(3); nv[ax] = 1.0
        f = kd(front, depth + 1) if front else None
        b = kd(back, depth + 1) if back else None
        if b is None:                                                   # empty below: flip so the empty side is front
            nodes.append([b, f, EMPTY, SOLID, (-nv, -m)])
        else:
            nodes.append([f, b, EMPTY, SOLID, (nv, m)])
        return len(nodes) - 1
    root = kd(list(range(len(prs))), 0)
    normalize(nodes, root)
    return nodes, root, prs


def truth(prs, pts):
    out = np.zeros(len(pts), bool)
    for planes, lo, hi in prs:
        ins = np.ones(len(pts), bool)
        for n_, w_ in planes: ins &= pts @ n_ - w_ < 0
        out |= ins
    return out


def pkey(n_, w_):
    return tuple(np.round(np.r_[np.asarray(n_) * 2000, w_ * 20]).astype(np.int64))


def build_piece_bsp(W, T, ncand=24, seed=0):
    """a real BSP of the prism union: split by the prisms' own planes; a prism whose plane is the splitter (either
    orientation) has that plane satisfied on its side; a cell whose prism has every plane satisfied is solid.
    -> (nodes, root, prisms)"""
    prs = prisms_of(W, T)
    if not prs: return None
    PL = []                                    # all planes
    pid = {}
    def plane_id(n_, w_):
        k = pkey(n_, w_)
        if k not in pid: pid[k] = len(PL); PL.append((np.asarray(n_, float), float(w_)))
        return pid[k]
    items = []                                 # (prism index, frozenset of remaining plane ids)
    for i, (planes, lo, hi) in enumerate(prs):
        items.append((i, tuple(plane_id(n_, w_) for n_, w_ in planes)))
    rev = {}
    for k, j in pid.items():
        r = tuple(-x for x in k)
        if r in pid: rev[j] = pid[r]
    V = [np.asarray(_prism_pts(prs[i][0]), float) for i in range(len(prs))]
    mv = max(len(v) for v in V)
    VP = np.zeros((len(V), mv, 3))
    for i, v in enumerate(V): VP[i, :len(v)] = v; VP[i, len(v):] = v[0]   # padded with a real vertex
    PN = np.array([p[0] for p in PL]); PW = np.array([p[1] for p in PL])
    nodes = []
    rng = np.random.default_rng(seed)
    def side(i, j):                            # +1 front, -1 back, 0 straddles
        n_, w_ = PL[j]; d = V[i] @ n_ - w_
        if (d <= 1e-3).all(): return -1
        if (d >= -1e-3).all(): return 1
        return 0
    def chain_rem(its):
        """union of the cell's prisms by their remaining planes: outside one -> the next prism; inside all of a
        prism's planes -> solid; outside the last -> empty"""
        nxt = None
        for i, rem in reversed(its):
            back = None
            for j in reversed(rem):
                nodes.append([nxt, back, EMPTY, SOLID, PL[j]]); back = len(nodes) - 1
            nxt = back
        return nxt
    def rec(its, depth):
        if not its: return None, EMPTY
        for i, rem in its:
            if not rem: return None, SOLID
        if len(its) <= CHAIN_MAX or depth > 60:
            return chain_rem(its), None
        cand = sorted({j for _, rem in its for j in rem})
        if len(cand) > ncand: cand = list(rng.choice(cand, ncand, replace=False))
        best = None
        idx = np.array([i for i, _ in its])
        cand = np.array(cand)
        D = np.einsum('kvc,jc->jkv', VP[idx], PN[cand]) - PW[cand][:, None, None]    # cand, prism, vertex
        S = np.where((D <= 1e-3).all(2), -1, np.where((D >= -1e-3).all(2), 1, 0))
        for a, j in enumerate(cand):                 # a prism owning the plane (either way) is on its side
            for k, (i, rem) in enumerate(its):
                if j in rem: S[a, k] = -1
                elif rev.get(j, -1) in rem: S[a, k] = 1
        nf = (S > 0).sum(1); nb = (S < 0).sum(1); ns = (S == 0).sum(1)
        sc = ns * 3 + np.abs(nf - nb) * 0.5 + ((nf == 0) | (nb == 0)) * 1e6
        a_ = int(np.argmin(sc)); j = int(cand[a_])
        if ns[a_] * 2 > len(its) or sc[a_] >= 1e6:      # nothing separates them (crossing slabs): plain union chain
            return chain_rem(its), None
        F, B = [], []
        for i, rem in its:
            if j in rem: B.append((i, tuple(x for x in rem if x != j))); continue
            r = rev.get(j, -1)
            if r in rem: F.append((i, tuple(x for x in rem if x != r))); continue
            s = side(i, j)
            if s >= 0: F.append((i, rem))
            if s <= 0: B.append((i, rem))
        me = len(nodes); nodes.append(None)
        f, fm = rec(F, depth + 1); b, bm = rec(B, depth + 1)
        if f is None and b is None and fm == bm:
            nodes[me] = 'dead'; return None, fm
        nodes[me] = [f, b, fm if f is None else EMPTY, bm if b is None else SOLID, PL[j]]
        return me, None
    root, mat = rec(items, 0)
    if root is None: return None
    _fixleaves(nodes, root)
    return nodes, root, prs


def _prism_pts(planes):
    """vertices of a prism given its planes [top, bottom, sides...]: intersect top / bottom with consecutive sides"""
    (nt, wt), (nb, wb) = planes[0], planes[1]
    sides = planes[2:]; out = []
    for k in range(len(sides)):
        (n1, w1), (n2, w2) = sides[k - 1], sides[k]
        for n3, w3 in ((nt, wt), (nb, wb)):
            M = np.array([n1, n2, n3]);
            if abs(np.linalg.det(M)) < 1e-9: continue
            out.append(np.linalg.solve(M, [w1, w2, w3]))
    return out


def _fixleaves(nodes, root):
    """make every leaf pair representable (front leaf empty, back leaf solid): a node whose front leaf is solid
    and back leaf empty is flipped; front solid + back subtree / front subtree + back empty: flipped too; both
    leaves the same can't occur (merged); front solid + back solid / empty + empty pruned in rec."""
    st = [root]; seen = set()
    while st:
        i = st.pop()
        if i is None or i in seen: continue
        seen.add(i)
        f, b, fm, bm, (n_, w_) = nodes[i]
        bad = (f is None and fm != EMPTY) or (b is None and bm == EMPTY)
        if bad:
            f, b, fm, bm, n_, w_ = b, f, bm, fm, -np.asarray(n_), -w_
        if (f is None and fm != EMPTY) or (b is None and bm == EMPTY):
            # solid in front and a subtree behind (or a subtree in front and empty behind) after the flip: put an
            # always-true pass-through node between (a plane far outside, front leaf empty, back = the subtree)
            raise ValueError('leaf pair')
        nodes[i] = [f, b, EMPTY, SOLID, (np.asarray(n_, float), float(w_))]
        st += [f, b]


def hull_piece(W, T):
    """a small piece's convex hull as one convex solid (a chain of its face planes): for small open curved parts
    (signs, railings, statues) whose crossing slabs blow the exact union up"""
    from scipy.spatial import ConvexHull
    used = W[np.unique(T)]
    try:
        h = ConvexHull(used)
    except Exception:
        return None
    pl = {}
    for eq in h.equations:
        n_, w_ = eq[:3], -eq[3]
        pl.setdefault(pkey(n_, w_), (n_, float(w_)))
    nodes = []; back = None
    for n_, w_ in pl.values():
        nodes.append([None, back, EMPTY, SOLID, (np.asarray(n_, float), w_)]); back = len(nodes) - 1
    prs = [(list(pl.values()), used.min(0), used.max(0))]
    return nodes, back, prs


HULL_EXT = 160.0       # pieces up to this size may become their hull
HULL_RATIO = 8         # ... when the exact tree needs more than this many nodes per prism


def build_piece_auto(W, T):
    r = build_piece_bsp(W, T)
    if r is None: return None
    nodes, root, prs = r
    live = sum(1 for x in nodes if isinstance(x, list))
    ext = (W[np.unique(T)].max(0) - W[np.unique(T)].min(0)).max()
    if live > HULL_RATIO * len(prs) and ext <= HULL_EXT:
        h = hull_piece(W, T)
        if h is not None and len(h[0]) < live: return h
    return r
