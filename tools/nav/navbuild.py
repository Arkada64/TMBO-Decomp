"""Nav graph from the layered heights (navgen.surfaces): nodes on a lattice, 8-way edges checked on the fine
grid, a compact binary for the game and a preview image."""
import sys, struct, pickle, numpy as np
from navgen import walkable
DIRS = [(0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1), (-1, 0), (-1, 1)]   # (dj, di): E NE N NW W SW S SE

def build(H, R, lat=8, max_rise=3.5, margin=1):   # 3.5 per 4 units ~ 41 deg (the game: normal z >= 0.707)
    K, ny, nx = H.shape
    Wk = walkable(H, R["step"], max_rise, margin)
    gh, gw = (ny + lat - 1) // lat, (nx + lat - 1) // lat
    offs = sorted(((dj, di) for dj in range(lat) for di in range(lat)),
                  key=lambda o: (o[0] - lat / 2 + .5) ** 2 + (o[1] - lat / 2 + .5) ** 2)
    G = np.mgrid[0:gh, 0:gw]
    nodes = []                         # per layer k: chosen fine (j, i) per lattice cell or -1
    for k in range(K):
        cj = np.full((gh, gw), -1); ci = np.full((gh, gw), -1)
        for dj, di in offs:
            j = G[0] * lat + dj; i = G[1] * lat + di
            inb = (j < ny) & (i < nx)
            jj = np.minimum(j, ny - 1); ii = np.minimum(i, nx - 1)
            ok = inb & Wk[k, jj, ii] & (cj < 0)
            cj[ok] = j[ok]; ci[ok] = i[ok]
        nodes.append((cj, ci))
    # flatten: node list (gj, gi, k, j, i, z)
    rec = []
    for k, (cj, ci) in enumerate(nodes):
        gj, gi = np.nonzero(cj >= 0)
        j, i = cj[gj, gi], ci[gj, gi]
        rec.append(np.stack([gj, gi, np.full_like(gj, k), j, i], 1))
    rec = np.concatenate(rec)
    z = H[rec[:, 2], rec[:, 3], rec[:, 4]]
    # drop duplicate layers in one lattice cell that are the same floor (within max_rise*2)
    order = np.lexsort((-z, rec[:, 1], rec[:, 0]))
    rec, z = rec[order], z[order]
    keep = np.ones(len(rec), bool)
    for a in range(1, len(rec)):
        if rec[a, 0] == rec[a - 1, 0] and rec[a, 1] == rec[a - 1, 1] and abs(z[a] - z[a - 1]) < 4 * max_rise: keep[a] = False
    rec, z = rec[keep], z[keep]
    N = len(rec)
    cellid = rec[:, 0] * gw + rec[:, 1]
    # lookup: lattice cell -> node indices
    from collections import defaultdict
    bycell = defaultdict(list)
    for n in range(N): bycell[int(cellid[n])].append(n)
    # fine-grid walk test between node a and candidate b
    Hn = np.where(Wk, H, np.nan)
    def walk_ok(a, b):
        ja, ia, za = rec[a, 3], rec[a, 4], z[a]
        jb, ib, zb = rec[b, 3], rec[b, 4], z[b]
        steps = np.maximum(np.abs(jb - ja), np.abs(ib - ia))
        zc = za.astype(np.float64).copy()
        ok = np.ones(len(a), bool)
        smax = int(steps.max()) if len(steps) else 0
        for s in range(1, smax + 1):
            act = ok & (s <= steps)
            if not act.any(): break
            t = s / np.maximum(steps, 1)
            j = np.clip(np.rint(ja + (jb - ja) * t).astype(int), 0, Hn.shape[1] - 1); i = np.clip(np.rint(ia + (ib - ia) * t).astype(int), 0, Hn.shape[2] - 1)
            col = Hn[:, j, i]                                   # (K, n)
            dz = np.abs(col - zc[None])
            dz = np.where(np.isnan(dz), np.inf, dz)
            best = dz.argmin(0); bd = dz[best, np.arange(len(a))]
            good = bd <= max_rise
            zn = col[best, np.arange(len(a))]
            ok = np.where(act, ok & good, ok)
            zc = np.where(act & good, zn, zc)
        return ok & (np.abs(zc - zb) <= max_rise)
    nb = np.full((N, 8), -1, np.int32)
    for d, (dj, di) in enumerate(DIRS[:4]):          # half the directions; mirror the rest
        A, B = [], []
        for n in range(N):
            c2 = (rec[n, 0] + dj, rec[n, 1] + di)
            if not (0 <= c2[0] < gh and 0 <= c2[1] < gw): continue
            cand = bycell.get(int(c2[0] * gw + c2[1]))
            if not cand: continue
            m = min(cand, key=lambda q: abs(z[q] - z[n]))
            A.append(n); B.append(m)
        if not A: continue
        A = np.array(A); B = np.array(B)
        ok = walk_ok(A, B) & walk_ok(B, A)
        nb[A[ok], d] = B[ok]; nb[B[ok], d + 4] = A[ok]
    return dict(rec=rec, z=z, nb=nb, gw=gw, gh=gh, lat=lat, Wk=Wk)

def pack(G, R):
    """binary for the game, little endian:
       header 32 bytes: 'NAV1', float x0, y0 (fine grid origin), float step (fine), float cell (lattice),
                        u16 gw, gh (lattice), u32 N
       N nodes of 8 bytes, sorted by cell: u32 cell (gj*gw+gi), s16 z*4, u8 offset (oi | oj<<4, fine steps
       inside the cell), u8 links (bit d = edge in DIRS[d]; the neighbour is the node of that cell nearest in z)"""
    rec, z, nb = G["rec"], G["z"], G["nb"]
    N = len(rec)
    step, lat = R["step"], G["lat"]
    sc = (lat + 15) // 16                        # offset unit in fine steps (header "step" = step * sc)
    cell = rec[:, 0] * G["gw"] + rec[:, 1]
    order = np.lexsort((z, cell))
    hdr = struct.pack("<4sffffHHI", b"NAV1", R["x0"], R["y0"], step * sc, step * lat, G["gw"], G["gh"], N)
    body = bytearray()
    for n in order:
        oj, oi = (rec[n, 3] - rec[n, 0] * lat) // sc, (rec[n, 4] - rec[n, 1] * lat) // sc
        links = sum(1 << d for d in range(8) if nb[n, d] >= 0)
        body += struct.pack("<IhBB", int(cell[n]), int(round(z[n] * 4)), int(oi) | int(oj) << 4, links)
    return hdr + bytes(body)

def preview(H, G, R, path, marks=()):
    from PIL import Image, ImageDraw
    K, ny, nx = H.shape
    img = np.zeros((ny, nx, 3), np.uint8)
    top = H[0]; g = np.isfinite(top)
    lo, hi = np.nanpercentile(top, 2), np.nanpercentile(top, 98)
    v = np.clip((top - lo) / max(hi - lo, 1), 0, 1)
    img[g] = (np.stack([40 + 120 * v, 40 + 120 * v, 40 + 80 * v], -1)[g]).astype(np.uint8)
    img[G["Wk"][0]] = (img[G["Wk"][0]] * 0.6 + np.array([0, 40, 0])).astype(np.uint8)
    im = Image.fromarray(img[::-1]); d = ImageDraw.Draw(im)
    rec, nb = G["rec"], G["nb"]
    for n in range(len(rec)):
        for k in range(4):
            m = nb[n, k]
            if m < 0: continue
            col = (90, 200, 255) if rec[n, 2] == 0 and rec[m, 2] == 0 else (255, 120, 255)
            d.line([rec[n, 4], ny - 1 - rec[n, 3], rec[m, 4], ny - 1 - rec[m, 3]], fill=col)
    for x, y in marks:
        i = (x - R["x0"]) / R["step"]; j = ny - 1 - (y - R["y0"]) / R["step"]
        d.ellipse([i - 6, j - 6, i + 6, j + 6], outline=(255, 0, 0), width=2)
    s = max(1, max(im.size) // 1400)
    if s > 1: im = im.resize((im.size[0] // s, im.size[1] // s), Image.LANCZOS)
    im.save(path)

if __name__ == "__main__":
    import time
    name = sys.argv[1]; lat = int(sys.argv[2]) if len(sys.argv) > 2 else 8
    H = np.load(f"{name}_H.npy"); R = pickle.load(open(f"{name}_R.pkl", "rb"))
    t = time.time(); G = build(H, R, lat)
    b = pack(G, R)
    open(f"{name}.nav", "wb").write(b)
    deg = (G["nb"] >= 0).sum(1)
    print(name, "nodes", len(G["rec"]), "avg links %.1f" % deg.mean(), "isolated", int((deg == 0).sum()), "bytes", len(b), "%.1fs" % (time.time() - t))
    preview(H, G, R, f"{name}_nav.png")
