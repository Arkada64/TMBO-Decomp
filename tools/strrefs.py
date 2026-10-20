"""Resolve lui/addiu(ori) address pairs in a function and return the C strings it references."""

import struct
import difflib


class Img:
    def __init__(self, path):
        d = path.read_bytes()
        self.d = d
        (shoff,) = struct.unpack_from("<I", d, 0x20)
        (shnum,) = struct.unpack_from("<H", d, 0x30)
        self.secs = []
        for i in range(shnum):
            s = struct.unpack_from("<IIIIIIIIII", d, shoff + i * 40)
            if s[1] == 1 and s[2] & 2 and s[3]:  # PROGBITS + ALLOC
                self.secs.append((s[3], s[3] + s[5], s[4]))

    def word(self, a):
        for lo, hi, off in self.secs:
            if lo <= a < hi:
                return struct.unpack_from("<I", self.d, off + a - lo)[0]

    def cstr(self, a):
        for lo, hi, off in self.secs:
            if lo <= a < hi:
                o = off + a - lo
                e = self.d.find(b"\0", o, o + 200)
                if e - o < 4:
                    return None
                s = self.d[o:e]
                if all(32 <= c < 127 or c in (9, 10) for c in s):
                    return s.decode()
        return None

    def strings(self, addr, size):
        regs, out = {}, set()
        for i in range(size // 4):
            w = self.word(addr + 4 * i)
            if w is None:
                break
            op = w >> 26
            rs, rt, imm = (w >> 21) & 31, (w >> 16) & 31, w & 0xFFFF
            if op == 0x0F:
                regs[rt] = imm << 16
                continue
            if op in (0x09, 0x19, 0x0D) and rs in regs:
                v = regs[rs] + (
                    imm if op == 0x0D else (imm - 0x10000 if imm & 0x8000 else imm)
                )
                s = self.cstr(v & 0xFFFFFFFF)
                if s:
                    out.add(s)
        return out


def strings_agree(a, b, thresh=0.7):
    """True if any string in a closely resembles any string in b (tolerates version bumps)."""
    if a & b:
        return True
    return any(
        difflib.SequenceMatcher(None, x, y).ratio() >= thresh for x in a for y in b
    )
