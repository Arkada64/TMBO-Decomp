"""Level collision extractor (step 1): walk the level hierarchy with transforms and collect
BSP collision nodes (op 18), collision volumes (op 10) and terrain heightfields (op 13)."""
import sys, struct, collections
import numpy as np
BASE = 0x980000
def w(d, o): return struct.unpack_from("<I", d, o)[0]
def f4(d, o): return struct.unpack_from("<4f", d, o)
def u16(d, o): return struct.unpack_from("<H", d, o)[0]
def s32(d, o): return struct.unpack_from("<i", d, o)[0]

class Level:
    def __init__(self, path):
        self.d = open(path, "rb").read()
        self.n = len(self.d)
        self.bsp, self.vol, self.ter = [], [], []
        self.stats = collections.Counter()
    def P(self, slot):
        v = w(self.d, slot)
        return v - BASE if BASE <= v < BASE + self.n else None
    def mat(self, o):        # 4x4 row-major, row vectors (world = [x y z 1] @ M)
        return np.array(struct.unpack_from("<16f", self.d, o), np.float64).reshape(4, 4)
    def walk(self):
        d = self.d
        ne = w(d, 0)
        seen = set()
        stack = [(self.P(4 + 4 * i), np.eye(4), 0) for i in range(ne)]
        while stack:
            node, M, anim = stack.pop()
            if node is None or (node, anim) in seen: continue
            seen.add((node, anim))
            op = w(d, node) & 0x3F
            self.stats[op] += 1
            kids = []
            if op == 1:                                  # group
                kids = [self.P(node + 0x20 + 4 * i) for i in range(u16(d, node + 8))]
            elif op == 2:                                # LOD: first (closest) level only
                kids = [self.P(node + 0x28)] if s32(d, node + 4) else []
            elif op == 3:                                # translate
                T = np.eye(4); T[3, :3] = f4(d, node + 0x10)[:3]
                M = T @ M
                kids = [self.P(node + 0x1C + 4 * i) for i in range(s32(d, node + 8) & 0xFFFF)]
            elif op == 4:                                # rotate (full matrix)
                M = self.mat(node + 0x10) @ M
                kids = [self.P(node + 0x50 + 4 * i) for i in range(s32(d, node + 8) & 0xFFFF)]
            elif op == 30:                               # scale
                tr = f4(d, node + 0x10); sc = f4(d, node + 0x20)
                S = np.diag([sc[0], sc[1], sc[2], 1.0]); S[3, :3] = tr[:3]
                M = S @ M
                kids = [self.P(node + 0x2C + 4 * i) for i in range(s32(d, node + 8) & 0xFFFF)]
            elif op == 17:                               # animated transform: rest pose (preRot), counted
                M = self.mat(node + 0x40) @ M
                anim = 1
                kids = [self.P(node + 0xCC + 4 * i) for i in range(s32(d, node + 4))]
            elif op == 6:                                # switch: all children
                kids = [self.P(node + 0xC + 4 * i) for i in range(d[node + 0xB])]
            elif op == 31:                               # destructible: the current state only
                k = d[node + 8]
                kids = [self.P(node + 0xC + 0x14 * k)] if k < d[node + 9] else []
            elif op == 8:                                # control: two children
                kids = [self.P(node + 4), self.P(node + 8)]
            elif op == 13:                               # terrain
                self.ter.append((node, M.copy()))
                kids = [self.P(node + 0xBC + 4 * i) for i in range(s32(d, node + 4))]
            elif op == 18:                               # BSP collision node
                self.bsp.append((node, M.copy(), anim))
            elif op == 10:                               # convex collision volume
                self.vol.append((node, M.copy(), anim))
            elif op == 23:
                kids = [self.P(node + 4)]
            for k in kids:
                if k is not None: stack.append((k, M, anim))

if __name__ == "__main__":
    L = Level(sys.argv[1]); L.walk()
    print("nodes by op", sorted(L.stats.items()))
    print("bsp", len(L.bsp), "under anim", sum(a for _, _, a in L.bsp), "vol", len(L.vol), "terrain", len(L.ter))
    for node, M, a in L.bsp[:5]:
        c = np.array([*struct.unpack_from("<3f", L.d, node + 0x10), 1.0]) @ M
        print("bsp @%x r %.1f centre %s" % (node, struct.unpack_from("<f", L.d, node + 8)[0], np.round(c[:3], 1)))

# ---------------- geometry queries ----------------
def bsp_solid(L, root, pts):
    """pts: (N,3) local coords -> bool solid (leaf material != 0x200), material ids"""
    d = L.d
    out = np.zeros(len(pts), bool); mat = np.zeros(len(pts), np.int32)
    stack = [(root, np.arange(len(pts)))]
    while stack:
        b, idx = stack.pop()
        if len(idx) == 0: continue
        nx, ny, nz, wv = struct.unpack_from("<4f", d, b + 0x10)
        p = pts[idx]
        dist = p[:, 0] * nx + p[:, 1] * ny + p[:, 2] * nz - wv
        fr = dist >= 0
        for sel, kid_off, mat_off in ((fr, 0, 0xC), (~fr, 4, 0xE)):
            ii = idx[sel]
            if len(ii) == 0: continue
            k = L.P(b + kid_off)
            if k is None:
                m = u16(d, b + mat_off)
                out[ii] = m != 0x200; mat[ii] = m
            else:
                stack.append((k, ii))
    return out, mat

def terrain_grid(L, node, M):
    d = L.d
    cols, rows = struct.unpack_from("<HH", d, node + 0x9C)
    stride = w(d, node + 0xA0)
    va = L.P(node + 0x90)
    TM = np.array(struct.unpack_from("<16f", d, node + 0x10)).reshape(4, 4)   # column vectors
    raw = np.frombuffer(d, np.uint16, count=stride * rows * 4, offset=va).reshape(rows, stride, 4)
    h = raw[:, :, 0].astype(np.float64); fl = raw[:, :, 1]
    j, i = np.mgrid[0:rows, 0:stride]
    loc = np.stack([i, j, h, np.ones_like(h)], -1)
    wpos = loc @ TM.T
    wpos = np.concatenate([wpos[..., :3], np.ones(wpos.shape[:2] + (1,))], -1) @ M   # node's own transform
    return wpos[..., :3], fl, cols, rows

def bsp_clip(L, root, P0, P1):
    """Clip segments P0->P1 (N,3, in the tree's space) through a BSP tree.
    Returns arrays (ray, t0, t1) of the SOLID parts (leaf material != 0x200)."""
    d = L.d
    out_r, out_a, out_b = [], [], []
    N = len(P0)
    stack = [(root, np.arange(N), np.zeros(N), np.ones(N))]
    D = P1 - P0
    while stack:
        b, idx, ta, tb = stack.pop()
        if len(idx) == 0: continue
        nx, ny, nz, wv = struct.unpack_from("<4f", d, b + 0x10)
        n = np.array([nx, ny, nz])
        d0 = P0[idx] @ n - wv
        dd = D[idx] @ n
        da = d0 + ta * dd; db = d0 + tb * dd
        fa, fb = da >= 0, db >= 0
        parts = {True: [], False: []}
        same = fa == fb
        parts[True].append((idx[same & fa], ta[same & fa], tb[same & fa]))
        parts[False].append((idx[same & ~fa], ta[same & ~fa], tb[same & ~fa]))
        sp = ~same
        if sp.any():
            i2 = idx[sp]; a2 = ta[sp]; b2 = tb[sp]
            with np.errstate(divide="ignore", invalid="ignore"):
                tm = np.clip(-d0[sp] / dd[sp], a2, b2)
            fa2 = fa[sp]
            # the part on the start side keeps its side, the rest the other
            parts[True].append((i2[fa2], a2[fa2], tm[fa2])); parts[False].append((i2[fa2], tm[fa2], b2[fa2]))
            parts[False].append((i2[~fa2], a2[~fa2], tm[~fa2])); parts[True].append((i2[~fa2], tm[~fa2], b2[~fa2]))
        for side, kid_off, mat_off in ((True, 0, 0xC), (False, 4, 0xE)):
            ii = np.concatenate([p[0] for p in parts[side]]); aa = np.concatenate([p[1] for p in parts[side]])
            bb = np.concatenate([p[2] for p in parts[side]])
            if len(ii) == 0: continue
            k = L.P(b + kid_off)
            if k is None:
                if u16(d, b + mat_off) != 0x200:
                    out_r.append(ii); out_a.append(aa); out_b.append(bb)
            else:
                stack.append((k, ii, aa, bb))
    if not out_r: return np.zeros(0, int), np.zeros(0), np.zeros(0)
    return np.concatenate(out_r), np.concatenate(out_a), np.concatenate(out_b)

def sources(L):
    """every BSP tree with its local->world matrix: BSP nodes and terrain cells (world space)"""
    d = L.d
    src = []
    for node, M, _ in L.bsp:
        root = L.P(node + 0xC)
        c = np.array([*struct.unpack_from("<3f", d, node + 0x10), 1.0]) @ M
        r = struct.unpack_from("<f", d, node + 8)[0] * max(np.linalg.norm(M[:3, :3], axis=1).max(), 1e-6)
        if root is not None: src.append((root, M, c[:3], r))
    for node, M in L.ter:
        cols, rows = struct.unpack_from("<HH", d, node + 0x9C)
        stride = w(d, node + 0xA0)
        TM = np.array(struct.unpack_from("<16f", d, node + 0x10)).reshape(4, 4)
        ca = L.P(node + 0x90); bl = L.P(node + 0x98)
        cell = np.frombuffer(d, np.uint16, count=stride * rows * 4, offset=ca).reshape(rows, stride, 4)
        for j in range(rows):
            for i in range(cols):
                e = cell[j, i]
                if not (e[3] & 0x100): continue
                root = L.P(bl + 4 * int(e[1]))
                if root is None: continue
                c = TM @ np.array([i + 0.5, j + 0.5, 0, 1.0])
                src.append((root, M, c[:3], TM[0, 0] * 0.75 + 1e-3))   # xy radius of the cell; z handled by the ray
    return src

ZTOP, ZBOT = 4000.0, -4000.0
def rasterize(L, step=4.0, src=None, bounds=None):
    """Vertical rays every `step` units: solid intervals per column -> (gx0, gy0, nx, ny, cols list)"""
    src = src if src is not None else sources(L)
    if bounds is None:
        xs = [c[0] - r for _, _, c, r in src] + [c[0] + r for _, _, c, r in src]
        ys = [c[1] - r for _, _, c, r in src] + [c[1] + r for _, _, c, r in src]
        bounds = (min(xs), min(ys), max(xs), max(ys))
    x0, y0, x1, y1 = bounds
    nx = int((x1 - x0) / step) + 1; ny = int((y1 - y0) / step) + 1
    iv_c, iv_hi, iv_lo = [], [], []
    for root, M, c, r in src:
        i0 = max(0, int((c[0] - r - x0) / step)); i1 = min(nx - 1, int((c[0] + r - x0) / step) + 1)
        j0 = max(0, int((c[1] - r - y0) / step)); j1 = min(ny - 1, int((c[1] + r - y0) / step) + 1)
        if i1 < i0 or j1 < j0: continue
        jj, ii = np.mgrid[j0:j1 + 1, i0:i1 + 1]
        ii = ii.ravel(); jj = jj.ravel()
        X = x0 + ii * step; Y = y0 + jj * step
        W0 = np.stack([X, Y, np.full_like(X, ZTOP), np.ones_like(X)], 1)
        W1 = np.stack([X, Y, np.full_like(X, ZBOT), np.ones_like(X)], 1)
        if not np.allclose(M, np.eye(4)):
            Mi = np.linalg.inv(M); W0 = W0 @ Mi; W1 = W1 @ Mi
        rr, ta, tb = bsp_clip(L, root, W0[:, :3], W1[:, :3])
        if len(rr) == 0: continue
        keep = tb - ta > 1e-7
        rr, ta, tb = rr[keep], ta[keep], tb[keep]
        iv_c.append(jj[rr] * nx + ii[rr])
        iv_hi.append(ZTOP + ta * (ZBOT - ZTOP)); iv_lo.append(ZTOP + tb * (ZBOT - ZTOP))
    c = np.concatenate(iv_c); hi = np.concatenate(iv_hi); lo = np.concatenate(iv_lo)
    return dict(x0=x0, y0=y0, nx=nx, ny=ny, step=step, col=c, hi=hi, lo=lo)

def surfaces(R, clear=5.0, maxl=4):
    """walkable layers per column: tops of merged solid intervals with `clear` units of air above"""
    nx, ny = R["nx"], R["ny"]
    H = np.full((maxl, ny * nx), np.nan, np.float32)
    order = np.lexsort((-R["hi"], R["col"]))
    col, hi, lo = R["col"][order], R["hi"][order], R["lo"][order]
    starts = np.flatnonzero(np.r_[True, col[1:] != col[:-1]])
    ends = np.r_[starts[1:], len(col)]
    for s, e in zip(starts, ends):
        merged = []                       # (top, bottom) from the top down
        for h, l in zip(hi[s:e], lo[s:e]):
            if merged and h >= merged[-1][1] - 0.05: merged[-1][1] = min(merged[-1][1], l)
            else: merged.append([h, l])
        k = 0; ceiling = np.inf
        for top, bot in merged:
            if ceiling - top >= clear and top > ZBOT + 1:
                if k < maxl: H[k, col[s]] = top; k += 1
            ceiling = bot
    return H.reshape(maxl, ny, nx)

# ---------------- walkability and graph ----------------
def walkable(H, step, max_rise=2.0, radius=1):
    """layer 0..K walk mask: a cell is walkable if some 4-neighbour layer is within max_rise (not an isolated
    spike), and every cell within `radius` cells has a surface within max_rise*(dist+1) (keeps a wall margin)."""
    K, ny, nx = H.shape
    ok = np.isfinite(H)
    out = np.zeros_like(ok)
    def shifted(A, dy, dx, fill=np.nan):
        B = np.full_like(A, fill)
        ys = slice(max(dy, 0), ny + min(dy, 0)); yd = slice(max(-dy, 0), ny + min(-dy, 0))
        xs = slice(max(dx, 0), nx + min(dx, 0)); xd = slice(max(-dx, 0), nx + min(-dx, 0))
        B[..., yd, xd] = A[..., ys, xs]
        return B
    for k in range(K):
        z = H[k]
        good = np.isfinite(z)
        for r in range(1, radius + 1):
            for dy in range(-r, r + 1):
                for dx in range(-r, r + 1):
                    if max(abs(dy), abs(dx)) != r: continue
                    nb = shifted(H, dy, dx)                      # (K, ny, nx) neighbour layers
                    near = np.any(np.abs(nb - z[None]) <= max_rise * r, axis=0)
                    good &= near
        out[k] = good
    return out

def graph(H, Wk, step, lat=6, max_rise=2.0):
    """coarse nodes every `lat` cells: per lattice cell and layer, the node is the walkable fine cell nearest
    the lattice point; edges to the 8 neighbours when a straight fine-cell walk stays walkable and continuous."""
    K, ny, nx = H.shape
    nodes = {}                     # (gj, gi, k) -> (j, i, z)
    for gj in range(0, ny, lat):
        for gi in range(0, nx, lat):
            for k in range(K):
                best = None
                for dj in range(0, lat):
                    for di in range(0, lat):
                        j, i = gj + dj, gi + di
                        if j >= ny or i >= nx or not Wk[k, j, i]: continue
                        dd = abs(dj - lat // 2) + abs(di - lat // 2)
                        if best is None or dd < best[0]: best = (dd, j, i)
                if best: nodes[(gj // lat, gi // lat, k)] = (best[1], best[2], float(H[k, best[1], best[2]]))
    def walk(a, b):
        (j0, i0, z0), (j1, i1, z1) = a, b
        n = max(abs(j1 - j0), abs(i1 - i0))
        z = z0
        for s in range(1, n + 1):
            j = round(j0 + (j1 - j0) * s / n); i = round(i0 + (i1 - i0) * s / n)
            cand = [H[k, j, i] for k in range(K) if Wk[k, j, i] and abs(H[k, j, i] - z) <= max_rise]
            if not cand: return False
            z = min(cand, key=lambda c: abs(c - z))
        return abs(z - z1) <= max_rise
    edges = {}
    for key, a in nodes.items():
        gj, gi, k = key
        m = []
        for dj, di in ((0, 1), (1, 0), (1, 1), (1, -1)):
            for k2 in range(K):
                b = nodes.get((gj + dj, gi + di, k2))
                if b and abs(b[2] - a[2]) < max_rise * lat * 1.5 and walk(a, b): m.append((gj + dj, gi + di, k2))
        edges[key] = m
    return nodes, edges
