"""Head-On textures (CT32-swizzled upload data, CLUT records inside the TEX) -> TMB TEX records (linear PSMT8/PSMT4
pixels) + RTX CLUT records, and the TMB TEX0 word for a mesh's gsTexCtx.

Record lists (TEX and RTX, both games): the LAST record has sizew 0 and runs to the end of the file; texmRelocate
processes it and then stops. So appending = give the old last record its real size, add ours, zero the size of the
new last one. RTX CLUT block addresses are packed (256 colours = 4 blocks, 16 = 1)."""
import struct, zlib, os
import numpy as np
from hotex import textures as ho_textures, clut_unswizzle

TEX1 = struct.pack('<IIII', 0x120, 0xfb5, 0x14, 0)


def records(d, payload_size):
    """[(off, bytes, gs)] including the final sizew-0 record (its size from payload_size(gs))"""
    ncls = struct.unpack_from('<I', d, 0)[0] if payload_size is tex_rec_size else 0
    o = struct.unpack_from('<I', d, 4)[0] * 16 if payload_size is tex_rec_size else 0
    out = []
    while o + 16 <= len(d):
        sz, key, gs = struct.unpack_from('<IIQ', d, o)
        if sz == 0:
            if gs:
                out.append((o, payload_size(gs), gs, key))
            break
        out.append((o, sz * 4, gs, key))
        o += sz * 4
    return out


def tex_rec_size(gs):
    psm, tw, th = (gs >> 32) & 0x3f, (gs >> 40) & 15, (gs >> 44) & 15
    n = (1 << tw) * (1 << th)
    return 0x80 + {0x13: n, 0x1b: n, 0x14: n // 2, 0x24: n // 2, 0x2c: n // 2, 0x02: 2 * n, 0x0a: 2 * n}.get(psm, 4 * n)


def rtx_rec_size(gs):
    """CLUT records (kind byte 0x08 at bits 48-55): 16-byte header + 4 bytes per colour. The other RTX records are
    VRAM-resident textures (retail levels: PSMT8H / PSMT4HL / PSMT4HH, kind 0x20 / 0x40) with a 0x80 header like a
    TEX record. (Getting this wrong for a level whose last RTX record is a resident texture broke the Lost merge.)"""
    tw, th = (gs >> 40) & 15, (gs >> 44) & 15
    n = (1 << tw) * (1 << th)
    if ((gs >> 48) & 0xff) == 0x08:
        return 16 + 4 * n
    psm = (gs >> 32) & 0x3f
    return 0x80 + {0x13: n, 0x1b: n, 0x14: n // 2, 0x24: n // 2, 0x2c: n // 2, 0x02: 2 * n, 0x0a: 2 * n}.get(psm, 4 * n)


def rtx_records(rtx):
    """compat: [(off, sizew, addr, tw, th)], end"""
    rs = records(rtx, rtx_rec_size)
    out = [(o, b // 4, (gs >> 16) & 0xffff, (gs >> 40) & 15, (gs >> 44) & 15) for o, b, gs, k in rs]
    return out, (rs[-1][0] + rs[-1][1]) if rs else 0


def clut_blocks(tw, th):
    return max(1, (1 << tw) * (1 << th) * 4 // 256)


def tex0(psm, w, h, cbp):
    tw, th = w.bit_length() - 1, h.bit_length() - 1
    tbw = max(1, w // 64)
    return (tbw << 14) | (psm << 20) | (tw << 26) | (th << 30) | (1 << 34) | (cbp << 37) | (1 << 61)


def join(recs_bytes):
    """concatenate full-size records; the last one gets sizew 0"""
    out = bytearray(b''.join(recs_bytes))
    last = len(out) - len(recs_bytes[-1])
    struct.pack_into('<I', out, last, 0)
    return out


class TexBuilder:
    def __init__(self, tmb_tex, tmb_rtx, ho_tex, first_id, reuse=None, half=(), own16=()):
        """reuse: {ho key: existing RTX CLUT address} - quantize to that palette instead of adding a CLUT"""
        self.tex, self.rtx = bytes(tmb_tex), bytes(tmb_rtx)
        ncls, recq = struct.unpack_from('<II', self.tex, 0)
        self.classes = [struct.unpack_from('<II', self.tex, 8 + 8 * i) for i in range(ncls)]
        self.recq = recq
        self.trecs = records(self.tex, tex_rec_size)
        self.rrecs = records(self.rtx, rtx_rec_size)
        self.pal = {}
        nxt = 0
        for o, b, gs, k in self.rrecs:
            a, tw, th = (gs >> 16) & 0xffff, (gs >> 40) & 15, (gs >> 44) & 15
            nxt = max(nxt, a + clut_blocks(tw, th))
            ne = (1 << tw) * (1 << th)
            p = [tuple(x) for x in np.frombuffer(self.rtx[o + 16:o + 16 + 4 * ne], np.uint8).reshape(ne, 4)]
            self.pal[a] = np.array(clut_unswizzle(p) if ne == 256 else p, float)
        self.next_cbp = nxt
        self.next_id = first_id
        self.ho = ho_textures(ho_tex)
        self.reuse = reuse or {}
        self.own16 = set(own16)
        self.half = set(half)               # keys stored at half size (reuse path only; UVs are normalized)
        self.map = {}
        self.new_tex, self.new_rtx = [], []

    def add(self, key):
        if key in self.map:
            return self.map[key]
        t = self.ho[key]
        h, w = t['img'].shape[:2]
        if key in self.reuse:                       # requantize onto an existing palette
            cbp = self.reuse[key]
            P = self.pal[cbp]
            im = t['img']
            if key in self.half:
                im = im.reshape(h // 2, 2, w // 2, 2, 4).mean((1, 3))
                h, w = h // 2, w // 2
            img = im.reshape(-1, 4).astype(float)
            img[:, 3] = np.minimum(255, img[:, 3])
            idx = ((img[:, None, :3] - P[None, :, :3]) ** 2).sum(2).argmin(1).astype(np.uint8)
            bpp = 8 if len(P) == 256 else 4
        elif key in self.own16:                     # own 16-colour palette: 1 CLUT block instead of 4
            from PIL import Image
            q = Image.fromarray(t['img'][:, :, :3]).quantize(16, method=Image.Quantize.MEDIANCUT, dither=Image.Dither.NONE)
            idx = np.asarray(q, np.uint8).reshape(-1)
            pal = np.array(q.getpalette()[:48], np.uint8).reshape(16, 3)
            if os.environ.get('GT_ENVLIFT', '1') == '1':   # used as a reflection map: no near-black entries
                pal = (pal.astype(float) * 0.6 + np.array([230, 190, 90]) * 0.4).clip(0, 255).astype(np.uint8)
            pal16 = np.concatenate([pal, np.full((16, 1), 0x80, np.uint8)], 1)   # Head-On alpha range (x2 below)
            t = dict(t, clutraw=pal16.tobytes(), clut=dict(tw=3, th=1))
            bpp, cbp = 4, None
        else:
            idx, bpp, cbp = t['idx'].astype(np.uint8), t['bpp'], None
            if key in self.half:                    # half size: every other texel (indices, same CLUT)
                idx = idx.reshape(h, w)[::2, ::2].reshape(-1)
                h, w = h // 2, w // 2
        if bpp == 8:
            payload, psm = idx.tobytes(), 0x13
        else:
            payload, psm = (idx[0::2] | (idx[1::2] << 4)).astype(np.uint8).tobytes(), 0x14
        nbytes = len(payload)
        cls = next(i for i, (cnt, bs) in enumerate(self.classes) if bs >= nbytes)
        tid = self.next_id
        self.next_id += 1
        tw, th = w.bit_length() - 1, h.bit_length() - 1
        gs = tid | (psm << 32) | (tw << 40) | (th << 44) | ((4 if psm == 0x13 else 8) << 51) | (cls << 59)
        q = nbytes // 16
        hdr = struct.pack('<IIQ', (0x80 + nbytes) // 4, zlib.crc32(payload + bytes([key & 255])) or 1, gs)
        hdr += struct.pack('<IIII', 0x60000000 | (q + 6), 0, 0, 0x50000000 | (q + 6)) + b'\0' * 0x60
        self.new_tex.append(hdr + payload)
        if cbp is None:                             # new CLUT (TMB alpha 0..0xFF, Head-On 0..0x80)
            c = bytearray(t['clutraw'])
            for i in range(3, len(c), 4):
                c[i] = min(255, c[i] * 2)
            ctw, cth = t['clut']['tw'], t['clut']['th']
            cbp = self.next_cbp
            self.next_cbp += clut_blocks(ctw, cth)
            rgs = (cbp << 16) | (ctw << 40) | (cth << 44) | (0x08 << 48) | (0x01 << 56)
            self.new_rtx.append(struct.pack('<IIQ', (16 + len(c)) // 4, 0, rgs) + bytes(c))
        self.map[key] = (tid, psm, w, h, cbp)
        return self.map[key]

    def gs_ctx(self, key):
        tid, psm, w, h, cbp = self.add(key)
        return tid, struct.pack('<Q', tex0(psm, w, h, cbp)) + struct.pack('<II', 6, 0) + TEX1 + b'\0' * 16

    def tex_bytes(self):
        old = []
        for o, b, gs, k in self.trecs:
            r = bytearray(self.tex[o:o + b])
            struct.pack_into('<I', r, 0, b // 4)
            old.append(bytes(r))
        drop = getattr(self, 'drop_tids', set())
        old = [r for r in old if (struct.unpack_from('<Q', r, 8)[0] & 0xffff) not in drop]
        allr = old + self.new_tex
        counts = {}
        for r in allr:
            c = struct.unpack_from('<Q', r, 8)[0] >> 59
            counts[c] = counts.get(c, 0) + 1
        head = bytearray(self.tex[:self.recq * 16])
        for i, (cnt, bs) in enumerate(self.classes):
            struct.pack_into('<II', head, 8 + 8 * i, max(cnt, counts.get(i, 0)), bs)
        out = head + join(allr)
        return bytes(out + b'\0' * (-len(out) % 2048))

    def rtx_bytes(self):
        old = []
        for o, b, gs, k in self.rrecs:
            r = bytearray(self.rtx[o:o + b])
            struct.pack_into('<I', r, 0, b // 4)
            old.append(bytes(r))
        dropc = getattr(self, 'drop_cbps', set())
        old = [r for r in old if ((struct.unpack_from('<Q', r, 8)[0] >> 16) & 0xffff) not in dropc]
        out = join(old + self.new_rtx)
        return bytes(out + b'\0' * (-len(out) % 2048))
