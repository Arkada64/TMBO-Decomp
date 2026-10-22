# ruff: noqa
"""
Place a built pack (packs/NAME.{NGP,PTR,TEX,RTX}, from mkpack.py + texpack.py) into fixed free memory areas of
the ONLINE game for one level, with absolute pointers. Output: packs/NAME<i>.BIN (one per area, sector-padded)
and NAME.layout.json. The mod loader (mods/packs.c) reads blob 0 (manifest) and the rest, then registers the
textures (texture ids += level max id, CLUT addresses += end of the level's CLUTs) and walks the entry points.
  python3 mkblobs.py LEVEL NAME
Cuts inside the model data only where the set of owning instances changes (pointer targets = struct starts).
"""
import sys, struct, json, bisect, collections
import mkpack
from ngpdb import w, BASE
OUT = "/mnt/c/Users/Ark/Desktop/TMB Decomp/packs/"
SECTOR = 2048
A128 = lambda x: (x + 127) & ~127
# online fixed memory map
LEVEL_NGP, CAR_NGP1, CAR_END, PTSBUF = 0x980000, 0x15FEA80, 0x1B93480, 0x1BE0000
LEVEL_TEX, CAR_TEX1 = 0x1C05670, 0x1E8E3F0
SIZES = {  # online inflated level NGP / TEX sizes (slack.py)
    "FREEWAY": (11847216, 2595840), "PRISON": (13089136, 2399232), "SUBURB": (12691184, 2434432),
    "CITY": (13022912, 2089984), "MINICITY": (12152848, 2054016), "MINIBURB": (9117664, 2220160), "LOOP": (8236000, 2474368),
}
def areas(lvl):
    n, t = SIZES[lvl]
    out = [(A128(LEVEL_NGP + n), CAR_NGP1, "ngp tail"), (CAR_END, PTSBUF, "gap"), (A128(LEVEL_TEX + t), CAR_TEX1, "tex tail")]
    # usable bytes: the CD read writes whole sectors
    return [(a, (b - a) // SECTOR * SECTOR, nm) for a, b, nm in out if b - a >= SECTOR]

def build(lvl, name):
    ngp = open(OUT + name + ".NGP", "rb").read()
    ptr = open(OUT + name + ".PTR", "rb").read()
    tex = open(OUT + name + ".TEX", "rb").read()
    rtx = open(OUT + name + ".RTX", "rb").read()
    rep = json.load(open(OUT + name + ".json"))
    n = w(ptr, 0); slots = [w(ptr, 4 + 4 * i) for i in range(n)]
    m = w(ptr, 4 + 4 * n); pairs = [(w(ptr, 8 + 4 * n + 8 * i), w(ptr, 12 + 4 * n + 8 * i)) for i in range(m)]
    neps = w(ngp, 0)
    eps_off = [w(ngp, 4 + 4 * i) - BASE for i in range(neps)]
    lo, hi = mkpack.RANGES[rep["kind"]]
    # ownership of every chunk by top node (instance)
    _, tops, _ = mkpack.pick_eps(ngp, lo, hi)
    owners = collections.defaultdict(set)
    for t in tops:
        cs, _ = mkpack.closure(ngp, slots, [t])
        for c in cs: owners[c].add(t)
    allc, _ = mkpack.closure(ngp, slots, eps_off)
    data_start = A128(4 + 4 * neps)                       # model data starts after the pack's DbHeader
    chunks = [c for c in allc if c[1] > data_start]
    # segments: maximal runs of contiguous chunks with the same owner set (boundaries = safe cuts)
    segs = []
    for a, b in chunks:
        a = max(a, data_start); o = frozenset(owners.get((a, b), ()))
        if segs and segs[-1][1] == a and segs[-1][2] == o: segs[-1][1] = b
        else: segs.append([a, b, o])
    # contiguity check: model data must be one gap-free range from data_start
    holes = [(segs[i][1], segs[i + 1][0]) for i in range(len(segs) - 1) if segs[i][1] != segs[i + 1][0]]
    # --- place: blob0 = manifest + pairs + DbHeader + RTX in the smallest area that fits; then TEX; then data
    ar = areas(lvl)
    free = {i: [a, a, cap] for i, (a, cap, nm) in enumerate(ar)}   # i -> [start, cursor, capacity]
    def room(i): return free[i][0] + free[i][2] - free[i][1]
    def put(i, size, mod=0):
        cur = free[i][1]; cur += (mod - cur) % 128
        if cur + size > free[i][0] + free[i][2]: return None
        free[i][1] = cur + size; return cur
    MAN = 64 + 24 * len(ar)
    man_size = MAN + 8 * len(pairs)
    hdr_size = A128(4 + 4 * neps)
    # animation table merge area: online level's op7 entries + ours (loader builds it, sets table 0)
    from ngpdb import get, head as _head
    on = get("online", lvl, "NGP")
    lvl_anims = 0
    for k in range(w(on, 0)):
        e = w(on, 4 + 4 * k) - BASE
        if _head(w(on, e))[0] == 7: lvl_anims = w(on, e + 4)
    anims = rep.get("anims", [])
    anim_cap = lvl_anims + len(anims) + 8                 # a little slack
    anim_size = A128(4 * len(anims)) + A128(8 + 4 * anim_cap)
    # the online level TEX must already have bins of the pack's block sizes (the loader enlarges them)
    lt = get("online", lvl, "TEX")
    lsizes = {struct.unpack_from("<II", lt, 8 + 8 * k)[1] for k in range(w(lt, 0))}
    psizes = [struct.unpack_from("<II", tex, 8 + 8 * k)[1] for k in range(w(tex, 0))]
    assert all(s in lsizes for s in psizes), f"pack TEX classes {psizes} not all in level {sorted(lsizes)}"
    small = sorted(free, key=lambda i: free[i][2])
    b0 = next(i for i in small if room(i) >= A128(man_size) + hdr_size + len(rtx) + anim_size + 256)
    man_at = put(b0, A128(man_size)); hdr_at = put(b0, hdr_size); rtx_at = put(b0, len(rtx))
    alist_at = put(b0, A128(4 * len(anims))); atab_at = put(b0, A128(8 + 4 * anim_cap))
    order = [b0] + [i for i in free if i != b0]
    tex_at = None
    for i in sorted(order, key=lambda i: -room(i)):
        tex_at = put(i, len(tex))
        if tex_at: break
    assert tex_at, "no room for TEX"
    # data segments in order, filling areas (largest remaining first), cutting only at segment boundaries
    place = []        # (pack_a, pack_b, abs_addr)
    si = 0
    for i in sorted(free, key=lambda i: -room(i)):
        while si < len(segs):
            a, b, o = segs[si]
            at = put(i, b - a, a % 128)
            if at is None: break
            place.append((a, b, at)); si += 1
    assert si == len(segs), f"model data does not fit: {sum(b - a for a, b, o in segs[si:])} bytes left"
    pstarts = [p[0] for p in place]
    def absaddr(off):
        if off < data_start:
            assert off < hdr_size; return hdr_at + off
        j = bisect.bisect_right(pstarts, off) - 1
        a, b, at = place[j]; assert a <= off < b, hex(off); return at + off - a
    # --- write memory images per area
    img = {i: bytearray(free[i][1] - free[i][0]) for i in free if free[i][1] > free[i][0]}
    def wr(addr, data):
        for i in img:
            s = free[i][0]
            if s <= addr and addr + len(data) <= s + len(img[i]):
                img[i][addr - s:addr - s + len(data)] = data; return
        raise ValueError(hex(addr))
    for a, b, at in place: wr(at, ngp[a:b])
    hdr = bytearray(ngp[:hdr_size])
    for k in range(neps): struct.pack_into("<I", hdr, 4 + 4 * k, absaddr(eps_off[k]))
    wr(hdr_at, bytes(hdr)); wr(rtx_at, rtx); wr(tex_at, tex)
    nrel = 0
    for s in slots:
        if s < hdr_size: continue                               # eps: done above
        v = w(ngp, s); off = v - BASE
        wr(absaddr(s), struct.pack("<I", absaddr(off))); nrel += 1
    apairs = [(absaddr(a) if a else 0, absaddr(g) if g else 0) for a, g in pairs]
    # --- blob files + manifest
    blobs = []
    for k, i in enumerate([b0] + [i for i in img if i != b0]):
        size = (len(img[i]) + SECTOR - 1) // SECTOR * SECTOR
        assert size <= ar[i][1], "sector padding overruns the area"
        blobs.append((f"{name}{k}.BIN", free[i][0], size, i))
    man = bytearray(man_size)
    struct.pack_into("<14I", man, 0, 0x50424D54, 2, len(blobs), hdr_at, man_at + MAN, len(apairs), tex_at, rtx_at,
                     rep["clut_blocks"], rep["tex_ids"], alist_at, len(anims), atab_at, anim_cap)
    wr(alist_at, b"".join(struct.pack("<I", absaddr(a)) for a in anims))
    for k, (fn, addr, size, i) in enumerate(blobs):
        struct.pack_into("<16sII", man, 64 + 24 * k, fn.encode(), addr, size)
    for k, (a, g) in enumerate(apairs): struct.pack_into("<II", man, MAN + 8 * k, a, g)
    wr(man_at, bytes(man))
    for fn, addr, size, i in blobs:
        open(OUT + fn, "wb").write(bytes(img[i]) + b"\0" * (size - len(img[i])))
    lay = {"level": lvl, "areas": [(hex(a), cap, nm) for a, cap, nm in ar], "blobs": [(fn, hex(addr), size) for fn, addr, size, i in blobs],
           "manifest": hex(man_at), "hdr": hex(hdr_at), "tex": hex(tex_at), "rtx": hex(rtx_at), "segments": len(segs), "cuts": len(place),
           "holes": holes, "relocated": nrel, "pairs": len(apairs), "used": {ar[i][2]: free[i][1] - free[i][0] for i in free},
           "anims": len(anims), "level_anims": lvl_anims, "anim_table": hex(atab_at), "tex_classes": psizes}
    json.dump(lay, open(OUT + name + ".layout.json", "w"), indent=1)
    return lay

if __name__ == "__main__":
    print(json.dumps(build(sys.argv[1], sys.argv[2]), indent=1))
