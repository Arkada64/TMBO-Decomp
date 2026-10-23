"""Head-On textures (CT32-swizzled upload data, CLUT records inside the TEX) -> TMB TEX records (linear PSMT8/PSMT4
pixels) + RTX CLUT records, and the TMB TEX0 word for a mesh's gsTexCtx."""
import struct, zlib
import numpy as np
from texrec import recs
from hotex import textures as ho_textures

TEX1 = struct.pack('<IIII', 0x120, 0xfb5, 0x14, 0)


def rtx_records(rtx):
    """[(off, sizew, addr, tw, th)] and the end offset (terminator)"""
    o, out = 0, []
    while o + 16 <= len(rtx):
        sz = struct.unpack_from('<I', rtx, o)[0]
        if sz == 0:
            break
        gs = struct.unpack_from('<Q', rtx, o + 8)[0]
        out.append((o, sz, (gs >> 16) & 0xffff, (gs >> 40) & 15, (gs >> 44) & 15))
        o += sz * 4
    return out, o


def clut_blocks(tw, th):
    n = (1 << tw) * (1 << th)          # entries (CT32)
    return max(1, n * 4 // 256)        # GS blocks of 256 bytes


def tex0(tid_psm, w, h, cbp):
    psm = tid_psm
    tw, th = w.bit_length() - 1, h.bit_length() - 1
    tbw = max(1, w // 64)
    q = (tbw << 14) | (psm << 20) | (tw << 26) | (th << 30) | (1 << 34) | (cbp << 37) | (1 << 61)
    return q


class TexBuilder:
    def __init__(self, tmb_tex, tmb_rtx, ho_tex, first_id):
        self.tex = bytearray(tmb_tex)
        self.rtx = bytearray(tmb_rtx)
        self.classes = [struct.unpack_from('<II', tmb_tex, 8 + 8 * i) for i in range(struct.unpack_from('<I', tmb_tex, 0)[0])]
        _, self.trecs, self.tend = recs(bytes(self.tex))
        self.rrecs, self.rend = rtx_records(bytes(self.rtx))
        last = max(self.rrecs, key=lambda r: r[2])
        self.next_cbp = last[2] + clut_blocks(last[3], last[4])
        self.next_id = first_id
        self.ho = ho_textures(ho_tex)
        self.map = {}      # ho key -> (id, psm, w, h, cbp)
        self.new_tex, self.new_rtx = [], []

    def add(self, key):
        if key in self.map:
            return self.map[key]
        t = self.ho[key]
        img_idx = t['idx']
        h, w = t['img'].shape[:2]
        bpp = t['bpp']
        if bpp == 8:
            payload = img_idx.astype(np.uint8).tobytes()
            psm = 0x13
        else:
            a = img_idx.astype(np.uint8)
            payload = (a[0::2] | (a[1::2] << 4)).astype(np.uint8).tobytes()
            psm = 0x14
        nbytes = len(payload)
        cls = next(i for i, (cnt, bs) in enumerate(self.classes) if bs >= nbytes)
        tid = self.next_id
        self.next_id += 1
        tw, th = w.bit_length() - 1, h.bit_length() - 1
        k = 4 if psm == 0x13 else 8
        gs = tid | (psm << 32) | (tw << 40) | (th << 44) | (k << 51) | (cls << 59)
        q = nbytes // 16
        hdr = struct.pack('<IIQ', (0x80 + nbytes) // 4, zlib.crc32(payload + t['clutraw']) or 1, gs)
        hdr += struct.pack('<IIII', 0x60000000 | (q + 6), 0, 0, 0x50000000 | (q + 6)) + b'\0' * 0x60
        self.new_tex.append(hdr + payload)
        # CLUT -> RTX (TMB alpha range is 0..0xFF, Head-On 0..0x80)
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
        body = bytes(self.tex[:self.tend]) + b''.join(self.new_tex)
        counts = {}
        for i in range(len(self.classes)):
            counts[i] = 0
        _, rs, _ = recs(body + b'\0' * 16)
        for r in rs:
            counts[r['gs'] >> 59] = counts.get(r['gs'] >> 59, 0) + 1
        out = bytearray(body)
        for i, (cnt, bs) in enumerate(self.classes):
            struct.pack_into('<II', out, 8 + 8 * i, max(cnt, counts.get(i, 0)), bs)
        out += b'\0' * 16
        out += b'\0' * (-len(out) % 2048)
        return bytes(out)

    def rtx_bytes(self):
        out = bytes(self.rtx[:self.rend]) + b''.join(self.new_rtx) + b'\0' * 16
        return out + b'\0' * (-len(out) % 2048)
