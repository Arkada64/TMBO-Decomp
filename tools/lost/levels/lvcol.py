"""Head-On collision pieces -> TMB BSP collision (op18).
Solid = behind a collision face, up to DEPTH deep (the union of every triangle's back prism): Head-On's pieces
are surfaces with outward faces (ground patches, walls, closed boxes). Each piece becomes one op18 node whose
tree uses the piece's face planes; leaves are labelled by sample points (just in front of / behind every face,
labelled with the prism test); a region whose samples all agree stops splitting.
TMB layout: op18 {0x12, f32 r^2, f32 r, root ptr, f32 cx, cy, cz, 0}; tree node (0x20) {front ptr, back ptr, 0,
u16 front material, u16 back material, plane nx, ny, nz, w}; a null child = leaf (material 0x200 = empty);
front = n.p - w >= 0."""
import struct, math
import numpy as np
EMPTY, SOLID = 0x200, 9
DEPTH = 30.0
EPS = 0.05

def prism_solid(S, P0, N, E1, E2, inv, slab=None):
    """S (m,3) points; triangles: P0 (k,3), N unit normals, edges, inverse 2x2 for barycentrics"""
    D = S[:, None, :] - P0[None]                      # m,k,3
    d = (D * N[None]).sum(2)
    a = (D * E1[None]).sum(2); b = (D * E2[None]).sum(2)
    u = inv[None, :, 0, 0] * a + inv[None, :, 0, 1] * b
    v = inv[None, :, 1, 0] * a + inv[None, :, 1, 1] * b
    inside = (u >= -0.02) & (v >= -0.02) & (u + v <= 1.02)
    lo = np.where(slab, -SLAB, -DEPTH)[None] if slab is not None else -DEPTH
    hi = np.where(slab, SLAB, 0.5)[None] if slab is not None else 0.5
    return ((d <= hi) & (d >= lo) & inside).any(1)

SLAB = 4.0
INSET = 0.85          # vertex samples sit this far toward the triangle centre (edges need fewer splits)

def orient(W, T):
    """Head-On's winding is not consistent: make it consistent per connected part (shared edges run opposite),
    then closed parts face outward (positive volume), open parts face up; open parts that are mostly vertical
    (fences, walls) become double-sided slabs. Returns (T, slab mask)."""
    T = T.copy(); k = len(T)
    edges = {}
    for i, t in enumerate(T):
        for a, b in ((t[0], t[1]), (t[1], t[2]), (t[2], t[0])):
            edges.setdefault((min(a, b), max(a, b)), []).append(i)
    def dir_has(t, a, b):
        return (t[0] == a and t[1] == b) or (t[1] == a and t[2] == b) or (t[2] == a and t[0] == b)
    comp = -np.ones(k, int); slab = np.zeros(k, bool); c = 0
    for s0 in range(k):
        if comp[s0] >= 0: continue
        comp[s0] = c; st = [s0]; members = [s0]
        while st:
            i = st.pop(); t = T[i]
            for a, b in ((t[0], t[1]), (t[1], t[2]), (t[2], t[0])):
                for j in edges[(min(a, b), max(a, b))]:
                    if j == i or comp[j] >= 0: continue
                    if dir_has(T[j], a, b): T[j] = T[j][::-1].copy()     # same direction -> flip
                    comp[j] = c; st.append(j); members.append(j)
        m = np.array(members); P = W[T[m]]
        N = np.cross(P[:, 1] - P[:, 0], P[:, 2] - P[:, 0])
        closed = all(len(edges[(min(a, b), max(a, b))]) == 2 for t in T[m] for a, b in ((t[0], t[1]), (t[1], t[2]), (t[2], t[0])))
        if closed:
            vol = (P[:, 0] * np.cross(P[:, 1], P[:, 2])).sum()
            if vol < 0: T[m] = T[m][:, ::-1]
        else:
            nz = N[:, 2].sum(); tot = np.linalg.norm(N, axis=1).sum()
            if nz < 0: T[m] = T[m][:, ::-1]
            if abs(nz) < 0.3 * tot: slab[m] = True
        c += 1
    return T, slab

def build_piece(W, T):
    """W world vertices, T triangles -> (nodes, root) with nodes = list of [front, back, matF, matB, plane];
    children are node indices or None"""
    T, slab = orient(W, T)
    P = W[T]                                           # k,3,3
    N = np.cross(P[:, 1] - P[:, 0], P[:, 2] - P[:, 0]); A = np.linalg.norm(N, axis=1)
    keep = A > 1e-4
    P, N, A, slab = P[keep], N[keep] / A[keep, None], A[keep], slab[keep]
    if not len(P): return None
    E1, E2 = P[:, 1] - P[:, 0], P[:, 2] - P[:, 0]
    G = np.stack([np.stack([(E1 * E1).sum(1), (E1 * E2).sum(1)], 1), np.stack([(E1 * E2).sum(1), (E2 * E2).sum(1)], 1)], 1)
    inv = np.linalg.inv(G + np.eye(2)[None] * 1e-9)
    w = (N * P[:, 0]).sum(1)
    # coplanar groups -> plane list
    key = np.round(np.c_[N * 200, w * 2]).astype(np.int64)
    _, pid = np.unique(key, axis=0, return_inverse=True)
    pid = pid.reshape(-1)
    planes = [(N[pid == i][0], w[pid == i][0], np.where(pid == i)[0]) for i in range(pid.max() + 1)]
    nface = len(planes)
    # auxiliary planes: the prisms' back faces and side faces (no triangles; used once the face planes run out)
    aux = {}
    for i in range(len(P)):
        lo = SLAB if slab[i] else DEPTH
        cand = [(-N[i], -(w[i] - lo))]
        if slab[i]: cand.append((N[i], w[i] + SLAB))
        for a, b in ((0, 1), (1, 2), (2, 0)):
            e = P[i, b] - P[i, a]; sn = np.cross(e, N[i]); ln = np.linalg.norm(sn)
            if ln > 1e-6: sn /= ln; cand.append((sn, sn @ P[i, a]))
        for n_, w_ in cand:
            kk = tuple(np.round(np.r_[n_ * 200, w_ * 2]).astype(np.int64))
            if kk not in aux: aux[kk] = (n_, w_, np.zeros(0, int))
    planes += list(aux.values())
    # samples
    C = P.mean(1)
    Vin = P.reshape(-1, 3) * INSET + np.repeat(C, 3, 0) * (1 - INSET)      # vertices pulled toward the centre
    Nr = np.repeat(N, 3, 0)
    S = np.concatenate([C + N * 2, C - N * 2, C - N * 12, C + N * (DEPTH + 10), C - N * (DEPTH + 10),
                        Vin + Nr * 2, Vin - Nr * 2, Vin - Nr * 8])
    lab = np.zeros(len(S), bool)
    for i in range(0, len(S), 2000):
        lab[i:i + 2000] = prism_solid(S[i:i + 2000], P[:, 0], N, E1, E2, inv, slab)
    nodes = []
    Pv = P                                             # triangle vertices for splitting tests
    tri_of_plane = [pl[2] for pl in planes]
    def rec(pl_ids, s_ids, inherit, depth):
        if len(s_ids):
            m = lab[s_ids].mean()
            if m == 0 or m == 1 or not len(pl_ids) or depth > 60:
                return None, (SOLID if m >= 0.5 else EMPTY)
        elif not len(pl_ids) or depth > 60:
            return None, inherit
        else:
            return None, inherit
        # choose a splitter: few spanning triangles, balanced samples
        faces = [j for j in pl_ids if j < nface]
        pool = faces if faces else pl_ids
        rng = np.random.default_rng(len(nodes))
        cand = pool if len(pool) <= 48 else [pool[i] for i in rng.choice(len(pool), 48, replace=False)]
        best = None
        tris = np.concatenate([tri_of_plane[j] for j in pl_ids])
        L = lab[s_ids]
        for c in cand:
            n_, w_, _ = planes[c]
            dv = (Pv[tris] @ n_) - w_ if len(tris) else np.zeros((0, 3))
            span = ((dv.max(1) > EPS) & (dv.min(1) < -EPS)).sum() if len(tris) else 0
            ds = S[s_ids] @ n_ - w_
            fr_, bk_ = L[ds >= 0], L[ds < 0]
            imp = lambda x: min(x.sum(), len(x) - x.sum())                 # samples misclassified by a leaf
            sc = span * 4 + (imp(fr_) + imp(bk_)) * 1.0 + abs(len(fr_) - len(bk_)) * 0.05
            if c >= nface and (len(fr_) == 0 or len(bk_) == 0): sc += 1e9      # no progress
            if best is None or sc < best[0]: best = (sc, c)
        c = best[1]; n_, w_, _ = planes[c]
        fr, bk = [], []
        for j in pl_ids:
            if j == c: continue
            if j >= nface: fr.append(j); bk.append(j); continue
            dv = (Pv[tri_of_plane[j]] @ n_) - w_
            if (dv > EPS).any(): fr.append(j)
            if (dv < -EPS).any(): bk.append(j)
        ds = S[s_ids] @ n_ - w_
        me = len(nodes); nodes.append(None)
        f_node, f_mat = rec(fr, s_ids[ds >= 0], EMPTY, depth + 1)
        b_node, b_mat = rec(bk, s_ids[ds < 0], SOLID, depth + 1)
        if f_node is None and b_node is None and f_mat == b_mat:
            nodes[me] = 'dead'
            return None, f_mat
        nodes[me] = [f_node, b_node, f_mat, b_mat, (n_, w_)]
        return me, None
    root, mat = rec(list(range(len(planes))), np.arange(len(S)), SOLID, 0)
    if root is None:
        return None
    normalize(nodes, root)
    return nodes, root, (S, lab)

def normalize(nodes, root, solid_mat=SOLID):
    """TMB's trees always have the empty side in front and the solid side behind (real levels: front leaf 0x200,
    back leaf = a material, never the other way; the material is stored on both kinds of child). Flip every node
    whose front leaf is solid or whose back leaf is empty."""
    st = [root]; seen = set()
    while st:
        i = st.pop()
        if i is None or i in seen: continue
        seen.add(i)
        f, b, fm, bm, (n_, w_) = nodes[i]
        if (f is None and fm != EMPTY) or (b is None and bm == EMPTY):
            f, b, fm, bm, n_, w_ = b, f, bm, fm, -n_, -w_
        nodes[i] = [f, b, EMPTY, solid_mat, (n_, w_)]
        assert not (f is None and fm != EMPTY) and not (b is None and bm == EMPTY), 'unrepresentable leaf pair'
        st += [f, b]

def encode(nodes, root, base_off):
    """-> bytes of the live nodes (0x20 each, renumbered), slots (relative offsets holding node pointers), root rel"""
    live = {}
    order = []
    st = [root]
    while st:
        i = st.pop()
        if i is None or i in live: continue
        live[i] = len(order); order.append(i)
        f, b = nodes[i][0], nodes[i][1]
        st += [b, f]
    out = bytearray(0x20 * len(order)); slots = []
    for k, i in enumerate(order):
        f, b, fm, bm, (n_, w_) = nodes[i]
        o = 0x20 * k
        if f is not None: struct.pack_into('<I', out, o, base_off + 0x20 * live[f]); slots.append(o)
        if b is not None: struct.pack_into('<I', out, o + 4, base_off + 0x20 * live[b]); slots.append(o + 4)
        struct.pack_into('<IHH4f', out, o + 8, 0, fm, bm, float(n_[0]), float(n_[1]), float(n_[2]), float(w_))
    return bytes(out), slots, 0

def classify(nodes, root, pts):
    """reference solid test on the python tree (same rule as the game / navgen.bsp_solid)"""
    out = np.zeros(len(pts), bool)
    for k, p in enumerate(pts):
        i = root
        while True:
            f, b, fm, bm, (n_, w_) = nodes[i]
            if p @ n_ - w_ >= 0:
                if f is None: out[k] = False; break
                i = f
            else:
                if b is None: out[k] = True; break
                i = b
    return out
