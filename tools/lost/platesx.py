"""Car select name plates for the extra cars (Gold Tooth, Old Pickup, Pit Viper, Outlaw 2, Thumper, Twister), like
12 Pak's (plate12pak.py): the game's own typewriter glyphs cut from the other plates, quantized onto the plates'
palette, painted into two new SHELL1 textures (ids 76, 77; four plate rows each, the plate box of 'Black Razer' /
12 Pak). Each plate is a copy of the 12 Pak plate mesh (switch child 15) with its texture id and V coordinates
moved to its row; the six go under a new op6 switch (id 0) that replaces the unused plate child 16 (the 'hter'
leftover). mods/skins.c shows child 16 for an extra and sets that switch to the extra's plate.

  python3 platesx.py SHELL_DIR OUT_DIR [preview.png]
SHELL_DIR: SHELL1.NGP / SHELL1.TEX (zip-entry containers) + SHELL1.PTR / SHELL1.RTX (raw), TEX already holding the
12 Pak / menu label edits. Writes OUT_DIR/SHELL1.NGP, SHELL1.PTR, SHELL1.TEX (containers like the input)."""
import sys, os, struct, zlib
import numpy as np
from PIL import Image, ImageFilter
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from tmbcar import Car, u32, BASE, mesh_extent
from textconv import records, tex_rec_size, rtx_records, join
from hotex import clut_unswizzle
from vif import parse

NAMES = ['Gold Tooth', 'Old Pickup', 'Pit Viper', 'Outlaw 2', 'Thumper', 'Twister']   # skins.c plate order
SWITCH, PAK_PLATE, SPARE = 0x71DC0, 0x71830, 16
NEW_IDS = (76, 77)
NODE = {55: 0x71ad0, 56: 0x71590, 57: 0x70300, 58: 0x70840, 59: 0x70d80}


def unzip_entry(b):
    if b[:4] != b'IE\x03\x04':
        return bytes(b), None
    nl, xl = struct.unpack_from('<HH', b, 26); cs = struct.unpack_from('<I', b, 18)[0]
    m = struct.unpack_from('<H', b, 8)[0]
    d = b[30 + nl + xl:30 + nl + xl + cs]
    return (zlib.decompress(d, -15) if m == 8 else d), b[:30 + nl + xl]


def zip_entry(raw, head):
    if head is None:
        return raw
    c = zlib.compressobj(9, zlib.DEFLATED, -15); comp = c.compress(raw) + c.flush()
    loc = bytearray(head); struct.pack_into('<III', loc, 14, zlib.crc32(raw) & 0xffffffff, len(comp), len(raw))
    struct.pack_into('<H', loc, 8, 8)
    return bytes(loc) + comp


def main():
    src, out = sys.argv[1], sys.argv[2]
    prev = sys.argv[3] if len(sys.argv) > 3 else None
    rd = lambda e: open(os.path.join(src, 'SHELL1.' + e), 'rb').read()
    ngp, nhead = unzip_entry(rd('NGP'))
    tex, thead = unzip_entry(rd('TEX'))
    rtx = rd('RTX'); ptr = rd('PTR')
    car = Car(ngp, ptr, b'', b'')
    n = car.n
    assert u32(n, SWITCH) & 0x3f == 6 and n[SWITCH + 0xb] == 19, 'plate switch not as expected (already patched?)'

    # ---- textures / palette
    trecs = records(tex, tex_rec_size)
    byid = {gs & 0xffff: (o, b, gs) for o, b, gs, k in trecs}
    assert not any(i in byid for i in NEW_IDS)
    rr, _ = rtx_records(rtx)
    clut = {a: (o, sz, tw, th) for o, sz, a, tw, th in rr}
    cbp = (struct.unpack_from('<Q', n, PAK_PLATE + 0x70)[0] >> 37) & 0x3fff
    o = clut[cbp][0]
    pal = np.array(clut_unswizzle([tuple(p) for p in np.frombuffer(rtx[o + 16:o + 16 + 1024], np.uint8).reshape(256, 4)]), np.int32)

    def timg(tid):                                   # upright RGBA float
        o_, b_, gs = byid[tid]
        c_ = (struct.unpack_from('<Q', n, NODE[tid] + 0x70)[0] >> 37) & 0x3fff
        oo = clut[c_][0]
        p_ = np.array(clut_unswizzle([tuple(p) for p in np.frombuffer(rtx[oo + 16:oo + 16 + 1024], np.uint8).reshape(256, 4)]), np.uint8)
        idx = np.frombuffer(tex[o_ + 0x80:o_ + 0x80 + 65536], np.uint8)
        return p_[idx].reshape(256, 256, 4)[::-1].astype(np.float32)
    T = {k: timg(k) for k in NODE}

    def glyph(tid, r0, r1, c0, c1, base, scale=1.0, thick=0, th=420):
        g = T[tid][r0:r1, c0:c1].copy()
        core = Image.fromarray(((g[..., :3].sum(2) > th) * 255).astype(np.uint8))
        m = np.asarray(core.filter(ImageFilter.MaxFilter(5)).filter(ImageFilter.GaussianBlur(1.5)), np.float32) / 255
        g *= np.clip(m * 1.5, 0, 1)[..., None]
        if scale != 1.0 or thick:
            im = [Image.fromarray(g[..., k].astype(np.uint8)) for k in range(4)]
            if scale != 1.0:
                im = [x.resize((round(g.shape[1] * scale), round(g.shape[0] * scale)), Image.BICUBIC) for x in im]
            g = np.stack([np.asarray(x, np.float32) for x in im], -1)
            if thick:
                h = g.copy(); h[:, 1:] = np.maximum(h[:, 1:], g[:, :-1]); g = h
        return g, (base - r0) * scale

    # glyph boxes (upright texture rows / cols of the retail plates; baseline row last)
    RK = lambda c0, c1: glyph(58, 2, 44, c0, c1, 36)            # Roadkill
    SP = lambda c0, c1: glyph(58, 108, 152, c0, c1, 143)        # Spectre
    ST = lambda c0, c1: glyph(56, 80, 120, c0, c1, 113)         # SweetTooth
    OL = lambda c0, c1: glyph(57, 140, 180, c0, c1, 173)        # Outlaw
    MG = lambda c0, c1: glyph(57, 203, 243, c0, c1, 236)        # Mr.Grimm
    S = 25 / 22
    G = {
        'G': MG(76, 97), 'm': MG(139, 165), 'o': RK(37, 57), 'a': RK(56, 79), 'd': RK(79, 102), 'k': RK(102, 123),
        'i': RK(124, 141), 'l': RK(140, 160), 'T': ST(121, 142), 't': ST(99, 122), 'h': ST(202, 225), 'w': ST(39, 61),
        'O': OL(46, 66), 'u': OL(68, 91), 'p': SP(36, 59), 'e': SP(60, 80), 'c': SP(81, 100), 'r': SP(122, 145),
        's': glyph(56, 140, 176, 113, 131, 169),
        'P': glyph(55, 63, 97, 24, 48, 91, S, 1), '2': glyph(55, 213, 248, 229, 250, 242, S, 1, 280),
    }
    # 'V' (no plate has one): Axel's 'A' upside down, crossbar removed
    a, b = glyph(59, 14, 50, 14, 38, 45)
    v = a[::-1].copy()
    hgt = v.shape[0]
    v[12:15, 9:15] = 0                               # the crossbar between the legs (rows 12..14 of the flipped crop)
    G['V'] = (v, hgt - (b - 29))                    # new baseline = the old cap top (29 rows above the baseline)

    def compose(text):
        H, W = 48, 251
        can = np.zeros((H, W, 4), np.float32)
        parts, wsum = [], 0
        for ch in text:
            if ch == ' ':
                parts.append(None); wsum += 10; continue
            parts.append(G[ch]); wsum += G[ch][0].shape[1] - 3
        x, base = max(2, (W - wsum) // 2), 34
        for g in parts:
            if g is None:
                x += 10; continue
            p, bb = g; t_ = int(round(base - bb)); h, w = p.shape[:2]
            y0, y1 = max(0, t_), min(H, t_ + h)
            x1 = min(W, x + w)
            can[y0:y1, x:x1] = np.maximum(can[y0:y1, x:x1], p[y0 - t_:y1 - t_, :x1 - x])
            x += w - 3
        flat = can.reshape(-1, 4).astype(np.int32)
        return ((flat[:, None, :] - pal[None]) ** 2 * np.array([1, 1, 1, 2])).sum(-1).argmin(1).astype(np.uint8).reshape(H, W)

    # ---- two new textures, four plate rows each: plate j at rows 64*(j%4) + 8 .. + 56 (box 10..53 = UV)
    o58, b58, gs58 = byid[58]
    bgi = int(np.frombuffer(tex[o58 + 0x80:o58 + 0x80 + 65536], np.uint8)[0])
    imgs = [np.full((256, 256), bgi, np.uint8) for _ in NEW_IDS]
    for j, name in enumerate(NAMES):
        k, row = divmod(j, 4)
        imgs[k][64 * row + 8:64 * row + 56, 4:255] = compose(name)
    new_recs = []
    for tid, up in zip(NEW_IDS, imgs):
        payload = up[::-1].tobytes()
        r = bytearray(tex[o58:o58 + 0x80]) + payload
        struct.pack_into('<I', r, 0, len(r) // 4)
        struct.pack_into('<I', r, 4, zlib.crc32(payload) or 1)
        struct.pack_into('<Q', r, 8, (gs58 & ~0xffff) | tid)
        new_recs.append(bytes(r))
    ncls, recq = struct.unpack_from('<II', tex, 0)
    old = []
    for o_, b_, gs, k in trecs:
        r = bytearray(tex[o_:o_ + b_]); struct.pack_into('<I', r, 0, b_ // 4); old.append(bytes(r))
    allr = old + new_recs
    head = bytearray(tex[:recq * 16])
    cnt = {}
    for r in allr:
        c = struct.unpack_from('<Q', r, 8)[0] >> 59; cnt[c] = cnt.get(c, 0) + 1
    for i in range(ncls):
        c_, bs = struct.unpack_from('<II', head, 8 + 8 * i)
        struct.pack_into('<II', head, 8 + 8 * i, max(c_, cnt.get(i, 0)), bs)
    tex2 = bytes(head + join(allr))

    # ---- plate meshes + switch
    a0, a1 = mesh_extent(n, PAK_PLATE)
    blob0 = bytes(n[a0:a1])
    pk_rel = u32(n, PAK_PLATE + 4) - BASE - a0
    uvs = []                                          # offsets (relative) of the raw V values
    pk = u32(n, PAK_PLATE + 4) - BASE
    qwc = u32(n, pk) & 0xffff
    for rec in parse(bytes(n), pk + 8, pk + 16 + qwc * 16):
        off, cmd, num, imm, p, pl = rec
        if cmd == 0x75:
            uvs += [p + 4 * i + 2 - a0 for i in range(num)]
    assert len(uvs) >= 4
    kids = []
    for j in range(len(NAMES)):
        k, row = divmod(j, 4)
        b = bytearray(blob0)
        struct.pack_into('<I', b, 4, pk_rel)          # node-relative, relocated by append
        struct.pack_into('<H', b, 0x50, NEW_IDS[k])
        shift = (64 * row + 10 - 205) / 256.0          # decoded v = -raw / 4096; rows = v * 256
        for q in uvs:
            raw = struct.unpack_from('<h', b, q)[0]
            struct.pack_into('<h', b, q, int(round(raw - shift * 4096)))
        kids.append(car.append(bytes(b), rel_slots=(4,), rel_pairs=((0x50, 0x70),)))
    sw = bytearray(0x10 + 4 * len(kids))
    struct.pack_into('<IIBBBB', sw, 0, 6, 0, 0, 0, 0, len(kids))
    swo = car.append(bytes(sw))
    for i, k in enumerate(kids):
        car.setp(swo + 0xc + 4 * i, k)
    car.setp(SWITCH + 0xc + 4 * SPARE, swo)

    os.makedirs(out, exist_ok=True)
    open(os.path.join(out, 'SHELL1.NGP'), 'wb').write(zip_entry(car.ngp_bytes(), nhead))
    open(os.path.join(out, 'SHELL1.PTR'), 'wb').write(car.ptr_bytes())
    open(os.path.join(out, 'SHELL1.TEX'), 'wb').write(zip_entry(tex2, thead))
    print('plates: switch %#x kids %s, textures %s' % (swo, [hex(k) for k in kids], NEW_IDS))
    if prev:
        rows = []
        for up in imgs:
            a_ = pal[up].astype(np.uint8); im = Image.fromarray(a_)
            bg = Image.new('RGBA', im.size, (0, 0, 0, 255))
            im.putalpha(im.split()[3].point(lambda v_: min(255, v_ * 2))); bg.alpha_composite(im)
            rows.append(np.asarray(bg))
        Image.fromarray(np.concatenate(rows, 1)).resize((1024, 512), Image.NEAREST).save(prev)


if __name__ == '__main__':
    main()
