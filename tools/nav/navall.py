import numpy as np, pickle, struct, os
from navbuild import build, pack, preview
LEVEL = dict(suburb=0, junkyard=1, freeway=2, prison=3, rooftop=4, city=5, loop=6, death1=7, death2=8, death3=9,
             death4=10, death5=11, death6=12, rooftop2=13, stadium=14, ship=15, asylum=16, minicity=17, miniburb=18,
             junk2=19, roofboss=20)
GAP, GAP_END = 0x1B93480, 0x1BE0000
A128 = lambda a: (a + 127) & ~127
TEX = dict(asylum=1542656, city=2089984, death1=2147328, death2=1674496, death3=1575424, death4=1088000,
           death5=1576064, death6=1491072, freeway=2595840, junk2=1754496, junkyard=1751168, loop=2474368,
           miniburb=2220160, minicity=2054016, prison=2399232, roofboss=1242496, rooftop=2143232, rooftop2=1726976,
           ship=1220608, stadium=1147904, suburb=2434432)
CAR_TEX1, CAR_NGP1 = 0x1E8E3F0, 0x15FEA80
PTSBUF, LEVEL_TEX = 0x1BE0000, 0x1C05670
def region(name):
    """free memory for the map: the level TEX tail (packs keep data there too), except where a pack or traffic
    uses it: FREEWAY (TEX tail 60 KB, ZFP0) -> NGP tail after the ZFP1 pack; PRISON -> TEX tail after ZRP2;
    SUBURB (TEX tail = its traffic) -> NGP tail after ZSF1. The RAM gap is traffic's on the other traffic maps."""
    if name == "freeway": a = A128(0x14CC680 + 514048); return a, (CAR_NGP1 - a) // 2048 * 2048
    if name in ("death1", "death2", "death3", "death4", "death5", "death6"):   # Lost maps can be swapped into these slots                    # NGP tail past the end of DEATH7's NGP + PTR (the DEATH7 test disc swaps it in)
        return 0x1524000, (CAR_NGP1 - 0x1524000) // 2048 * 2048
    if name in ("prison", "suburb"):        # the point-file read buffer, free once the level has loaded (late load)
        return PTSBUF, (LEVEL_TEX - PTSBUF) // 2048 * 2048
    a = A128(0x1C05670 + TEX[name])
    return a, (CAR_TEX1 - a) // 2048 * 2048
PTSDIR = os.environ.get("PTSDIR", "pts")
def parts_with_jumps(G, name, R):
    """keep the largest part plus every part the level's attractor graph (PTS links) joins to it both ways
    (in by some jump, back out by some jump: no traps); the links between kept parts become jump links"""
    import sys; sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "../peds"))
    import pts as ptsmod
    nb = G["nb"]; N = len(nb); comp = -np.ones(N, int); sizes = []
    for s in range(N):
        if comp[s] >= 0: continue
        c = len(sizes); st = [s]; comp[s] = c; n = 0
        while st:
            a = st.pop(); n += 1
            for b in nb[a]:
                if b >= 0 and comp[b] < 0: comp[b] = c; st.append(b)
        sizes.append(n)
    main = int(np.argmax(sizes)); keep = {main}; J = []
    f = os.path.join(PTSDIR, name.upper() + ".PTS")
    if os.path.exists(f):
        rec, z = G["rec"], G["z"]
        X = R["x0"] + rec[:, 4] * R["step"]; Y = R["y0"] + rec[:, 3] * R["step"]
        A = ptsmod.parse(open(f, "rb").read()); snap = []
        for a in A:
            x, y, zp = a["p"]; dd = (X - x) ** 2 + (Y - y) ** 2 + ((z - zp) * 2) ** 2
            m = int(dd.argmin())
            snap.append(m if (X[m] - x) ** 2 + (Y[m] - y) ** 2 < 48 ** 2 and abs(z[m] - zp) < 24 and sizes[comp[m]] >= 6 else -1)
        E = [(snap[i], snap[k]) for i, a in enumerate(A) for k in a["links"]
             if k < len(A) and snap[i] >= 0 and snap[k] >= 0 and comp[snap[i]] != comp[snap[k]]
             and (X[snap[i]] - X[snap[k]]) ** 2 + (Y[snap[i]] - Y[snap[k]]) ** 2 < 1600 ** 2]
        def reach(fwd):
            seen = {main}; st = [main]
            while st:
                c = st.pop()
                for a, b in E:
                    u, v = (comp[a], comp[b]) if fwd else (comp[b], comp[a])
                    if u == c and v not in seen: seen.add(v); st.append(v)
            return seen
        keep = reach(True) & reach(False)
        J = sorted(set((a, b) for a, b in E if comp[a] in keep and comp[b] in keep))
    k = np.isin(comp, list(keep))
    remap = -np.ones(N, int); remap[k] = np.arange(k.sum())
    nb2 = np.where(nb[k] >= 0, remap[np.maximum(nb[k], 0)], -1)
    G2 = dict(G, rec=G["rec"][k], z=G["z"][k], nb=nb2, jumps=[(int(remap[a]), int(remap[b])) for a, b in J])
    print(f"{name}: {len(keep)} parts kept ({int(k.sum())} of {N} nodes), {len(J)} jump links")
    return G2
def largest(G):
    nb = G["nb"]; N = len(nb); comp = -np.ones(N, int); best = (0, -1); c = 0
    for s in range(N):
        if comp[s] >= 0: continue
        st = [s]; comp[s] = c; n = 0
        while st:
            a = st.pop(); n += 1
            for b in nb[a]:
                if b >= 0 and comp[b] < 0: comp[b] = c; st.append(b)
        if n > best[0]: best = (n, c)
        c += 1
    keep = comp == best[1]
    remap = -np.ones(N, int); remap[keep] = np.arange(keep.sum())
    nb2 = np.where(nb[keep] >= 0, remap[np.maximum(nb[keep], 0)], -1)
    return dict(G, rec=G["rec"][keep], z=G["z"][keep], nb=nb2)
# areas the bots must not plan into: (x0, x1, y0, y1, below z) - surfaces lower than z in the box are dropped
# FREEWAY: the dead-end ramp by the hospital (drops from the road at y -2080, z 11 to z -63 at y -2880 and ends;
# Ark 2026-10-27: bots got stuck down there)
# FREEWAY 2: the jump by the stadium (x -620..-400, y 1600..1760): its deck (z 120-165) sits over the road the
# bots drive under; planned onto it from below, they got stuck there (Ark 2026-10-27)
# JUNKYARD: the narrow corner above the tilted trailer (x -430..-320, y -570..-450): a bot got stuck squeezing through
EXCLUDE = dict(freeway=[(-90, 150, -2910, -2070, -1e9, 10.5), (-640, -380, 1580, 1780, 100, 1e9)],
               junkyard=[(-430, -320, -570, -450, -1e9, 1e9)])
def exclude(name, H, R):
    for xa, xb, ya, yb, zl, zt in EXCLUDE.get(name, []):
        ia, ib = int((xa - R["x0"]) / R["step"]), int((xb - R["x0"]) / R["step"]) + 1
        ja, jb = int((ya - R["y0"]) / R["step"]), int((yb - R["y0"]) / R["step"]) + 1
        sub = H[:, ja:jb, ia:ib]
        cut = np.isfinite(sub) & (sub < zt) & (sub > zl)
        n = int(cut.sum()); sub[cut] = np.nan
        print(f"{name}: excluded {n} cells in x {xa}..{xb} y {ya}..{yb} z {zl}..{zt}")
    return H
table = []
ONLY = os.environ.get("NAV_ONLY")
for name, lvl in LEVEL.items():
    if ONLY and name not in ONLY.split(","): continue
    H = np.load(f"{name}_H.npy"); R = pickle.load(open(f"{name}_R.pkl", "rb"))
    H = exclude(name, H, R)
    addr, cap = region(name)
    for lat in (8, 9, 10, 12, 14, 16, 20):
        G = parts_with_jumps(build(H, R, lat), name, R)
        b = pack(G, R)
        if len(b) <= cap: break
    fn = f"ZN{lvl:02d}.BIN"
    open(fn, "wb").write(b)
    preview(H, G, R, f"{name}_nav.png")
    table.append((lvl, name, addr, cap, len(b), lat, len(G["rec"])))
    print(f"{name:9s} level {lvl:2d} lat {lat*4:3d} units, {len(G['rec']):6d} nodes, {len(b)//1024:4d} KB at 0x{addr:X} (room {cap//1024} KB)", flush=True)
pickle.dump(table, open("navtable.pkl", "wb"))

with open("navlevels.inc", "w") as f:
    for lvl, name, addr, cap, size, lat, n in table:
        late = 1 if addr == PTSBUF else 0
        f.write(f"    {{ {lvl}, 0x{addr:X}, {cap}, {late} }},  /* {name.upper()}: {size // 1024} KB, {n} nodes, {lat * 4}-unit cells */\n")
