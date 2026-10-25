"""
A small Emotion Engine (R5900) interpreter for the function test bench (bench.py).

Runs game code out of a PCSX2 savestate's RAM: integer (MIPS III + R5900 3-operand mult/madd), the 128-bit GPRs
(lq/sq, the common MMI ops), the FPU (single precision, PS2 clamping) and VU0 macro mode (COP2). It is not an
emulator: no threads, interrupts, DMA or devices. Anything it does not know raises Unsupported, any access to the
hardware registers raises Hardware, so a test that reaches them is reported as such instead of guessed.
Writes can be journaled (begin/undo) so one call can be run twice from the same state.
"""
import math, struct

M64 = (1 << 64) - 1
M32 = 0xFFFFFFFF
FMAX = 3.4028234663852886e38
RET_MAGIC = 0x0FFFFFF0           # return address of a top-level call: pc reaching it ends the run

class Unsupported(Exception): pass
class Hardware(Exception): pass
class Fault(Exception): pass
class StepLimit(Exception): pass

def s32(v): v &= M32; return v - (1 << 32) if v & 0x80000000 else v
def s64(v): v &= M64; return v - (1 << 64) if v >> 63 else v
def sx32(v): return s32(v) & M64                     # sign-extend a 32-bit result into 64 bits
def f2u(f): return struct.unpack('<I', struct.pack('<f', f))[0]
def u2f(u):
    u &= M32
    if (u & 0x7F800000) == 0x7F800000: u = (u & 0x80000000) | 0x7F7FFFFF   # PS2: no Inf / NaN, max magnitude
    elif (u & 0x7F800000) == 0: u &= 0x80000000                           # denormals flush to zero
    return struct.unpack('<f', struct.pack('<I', u))[0]
def fclamp(x):
    if x != x: return FMAX
    if x > FMAX: return FMAX
    if x < -FMAX: return -FMAX
    r = struct.unpack('<f', struct.pack('<f', x))[0] if abs(x) <= FMAX else x
    if r != 0 and abs(r) < 1.1754943508222875e-38: r = 0.0 * r
    return r

class EE:
    def __init__(self, ram, scratch=None):
        self.ram = bytearray(ram)
        self.spr = bytearray(scratch if scratch else 16384)
        self.gpr = [0] * 32                 # 128-bit values
        self.hi = self.lo = self.hi1 = self.lo1 = 0
        self.sa = 0
        self.pc = 0
        self.fpr = [0] * 32                 # raw 32-bit words
        self.acc = 0.0                      # FPU accumulator
        self.fcr31 = 0
        self.vf = [[0, 0, 0, 0] for _ in range(32)]; self.vf[0][3] = 0x3F800000   # raw words
        self.vi = [0] * 16
        self.vacc = [0.0, 0.0, 0.0, 0.0]
        self.q = 0.0; self.vI = 0.0
        self.journal = None                 # list of (kind, addr, old bytes) while journaling
        self.hw_ok = True                   # outside a test: hardware reads give 0, writes are dropped
        self.on_call = None                 # hook(ee, target) -> None, called before every jal / jalr
        self.steps = 0

    # ---------------- memory ----------------
    def _where(self, a):
        a &= M32
        top = a >> 28
        if top == 7 and (a & 0x0FFFC000) == 0:
            return self.spr, a & 0x3FFF, 'S'
        if top in (0, 2, 3, 8, 9, 0xA, 0xB):
            p = a & 0x0FFFFFFF
            if p < 0x2000000: return self.ram, p, 'R'
            if 0x1FC00000 <= p < 0x20000000: return None, 0, 'B'
        if top in (1, 0xB) or (a & 0x1FFFFFFF) >= 0x10000000:
            return None, 0, 'H'
        raise Fault('bad address %08x' % a)

    def read(self, a, n):
        if a % n and n > 1: raise Fault('unaligned %d-byte read at %08x' % (n, a & M32))
        buf, o, k = self._where(a)
        if buf is None:
            if k == 'H' and not self.hw_ok: raise Hardware('read %08x' % (a & M32))
            return 0
        return int.from_bytes(buf[o:o + n], 'little')

    def write(self, a, n, v):
        if a % n and n > 1: raise Fault('unaligned %d-byte write at %08x' % (n, a & M32))
        buf, o, k = self._where(a)
        if buf is None:
            if k == 'H' and not self.hw_ok: raise Hardware('write %08x' % (a & M32))
            return
        if self.journal is not None: self.journal.append((k, o, bytes(buf[o:o + n])))
        buf[o:o + n] = (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little')

    def begin(self): self.journal = []
    def undo(self):
        j, self.journal = self.journal, None
        for k, o, old in reversed(j):
            (self.spr if k == 'S' else self.ram)[o:o + len(old)] = old
        return j

    # ---------------- registers ----------------
    def r(self, i): return self.gpr[i] & M64
    def w(self, i, v):
        if i: self.gpr[i] = (self.gpr[i] & ~M64) | (v & M64)
    def w128(self, i, v):
        if i: self.gpr[i] = v & ((1 << 128) - 1)
    def f(self, i): return u2f(self.fpr[i])
    def fw(self, i, x): self.fpr[i] = f2u(fclamp(x))

    def state(self):
        return dict(gpr=list(self.gpr), hi=self.hi, lo=self.lo, hi1=self.hi1, lo1=self.lo1, sa=self.sa, pc=self.pc,
                    fpr=list(self.fpr), acc=self.acc, fcr31=self.fcr31, vf=[list(v) for v in self.vf],
                    vi=list(self.vi), vacc=list(self.vacc), q=self.q, vI=self.vI)
    def restore(self, s):
        for k, v in s.items():
            setattr(self, k, [list(x) for x in v] if k == 'vf' else (list(v) if isinstance(v, list) else v))

    # ---------------- running ----------------
    def call(self, addr, args=(), sp=None, limit=2_000_000):
        """run the function at addr with integer args until it returns; returns v0 (64-bit)"""
        for i, a in enumerate(args[:8]): self.w(4 + i, a)
        if sp is not None: self.w(29, sp)
        self.w(31, RET_MAGIC)
        self.pc = addr
        self.run(limit)
        return self.r(2)

    def run(self, limit):
        end = self.steps + limit
        while self.pc != RET_MAGIC:
            if self.steps >= end: raise StepLimit('%d steps' % limit)
            self.step()

    def fetch(self, a):
        return self.read(a, 4)

    def step(self):
        pc = self.pc
        ins = self.fetch(pc)
        self.steps += 1
        nxt = self._exec(ins, pc)
        if nxt is None:
            self.pc = pc + 4
        else:                                   # a branch: (taken target or None, likely)
            tgt, likely, link = nxt
            if tgt is None and likely:          # branch-likely not taken: skip the delay slot
                self.pc = pc + 8; return
            if link: self.w(link, pc + 8)
            slot = self.fetch(pc + 4); self.steps += 1
            if self._exec(slot, pc + 4) is not None: raise Unsupported('branch in a delay slot at %08x' % pc)
            if tgt is None: self.pc = pc + 8
            else:
                if link and self.on_call: self.on_call(self, tgt)
                self.pc = tgt

    # returns None (no branch) or (target or None, likely, link register)
    def _exec(self, ins, pc):
        op = ins >> 26
        rs = (ins >> 21) & 31; rt = (ins >> 16) & 31; rd = (ins >> 11) & 31; sh = (ins >> 6) & 31
        imm = ins & 0xFFFF; simm = imm - 0x10000 if imm & 0x8000 else imm
        r, w = self.r, self.w
        if op == 0:
            fn = ins & 63
            if fn == 0: w(rd, sx32(r(rt) << sh))
            elif fn == 2: w(rd, sx32((r(rt) & M32) >> sh))
            elif fn == 3: w(rd, sx32(s32(r(rt)) >> sh))
            elif fn == 4: w(rd, sx32(r(rt) << (r(rs) & 31)))
            elif fn == 6: w(rd, sx32((r(rt) & M32) >> (r(rs) & 31)))
            elif fn == 7: w(rd, sx32(s32(r(rt)) >> (r(rs) & 31)))
            elif fn == 8: return (r(rs) & M32, False, 0)
            elif fn == 9: return (r(rs) & M32, False, rd or 31) if rd else (r(rs) & M32, False, 0)
            elif fn == 10:
                if r(rt) == 0: w(rd, r(rs))
            elif fn == 11:
                if r(rt) != 0: w(rd, r(rs))
            elif fn == 12:                                          # syscall
                if not self.hw_ok: raise Hardware('syscall %d at %08x' % (s32(r(3)), pc))
                w(2, 0)
            elif fn == 13: raise Fault('break at %08x' % pc)
            elif fn == 15: pass                                     # sync
            elif fn == 16: w(rd, self.hi)
            elif fn == 17: self.hi = r(rs)
            elif fn == 18: w(rd, self.lo)
            elif fn == 19: self.lo = r(rs)
            elif fn == 20: w(rd, r(rt) << (r(rs) & 63))
            elif fn == 22: w(rd, r(rt) >> (r(rs) & 63))
            elif fn == 23: w(rd, s64(r(rt)) >> (r(rs) & 63))
            elif fn == 24:                                          # mult (R5900: also rd = lo)
                p = s32(r(rs)) * s32(r(rt)); self.lo = sx32(p); self.hi = sx32(p >> 32); w(rd, self.lo)
            elif fn == 25:
                p = (r(rs) & M32) * (r(rt) & M32); self.lo = sx32(p); self.hi = sx32(p >> 32); w(rd, self.lo)
            elif fn in (26, 27):
                a, b = (s32(r(rs)), s32(r(rt))) if fn == 26 else (r(rs) & M32, r(rt) & M32)
                if b == 0: self.lo = sx32(-1 if a >= 0 else 1) if fn == 26 else M64; self.hi = sx32(a)
                else:
                    qv = abs(a) // abs(b) * (1 if (a < 0) == (b < 0) else -1); self.lo = sx32(qv); self.hi = sx32(a - qv * b)
            elif fn in (32, 33): w(rd, sx32(r(rs) + r(rt)))
            elif fn in (34, 35): w(rd, sx32(r(rs) - r(rt)))
            elif fn == 36: w(rd, r(rs) & r(rt))
            elif fn == 37: w(rd, r(rs) | r(rt))
            elif fn == 38: w(rd, r(rs) ^ r(rt))
            elif fn == 39: w(rd, ~(r(rs) | r(rt)))
            elif fn == 40: w(rd, self.sa)
            elif fn == 41: self.sa = r(rs)
            elif fn == 42: w(rd, int(s64(r(rs)) < s64(r(rt))))
            elif fn == 43: w(rd, int(r(rs) < r(rt)))
            elif fn in (44, 45): w(rd, r(rs) + r(rt))
            elif fn in (46, 47): w(rd, r(rs) - r(rt))
            elif fn == 56: w(rd, r(rt) << sh)
            elif fn == 58: w(rd, r(rt) >> sh)
            elif fn == 59: w(rd, s64(r(rt)) >> sh)
            elif fn == 60: w(rd, r(rt) << (sh + 32))
            elif fn == 62: w(rd, r(rt) >> (sh + 32))
            elif fn == 63: w(rd, s64(r(rt)) >> (sh + 32))
            elif 48 <= fn <= 54: pass                               # traps: never taken in game code
            else: raise Unsupported('special %d at %08x' % (fn, pc))
            return None
        if op == 1:
            v = s64(r(rs))
            c = {0: v < 0, 1: v >= 0, 2: v < 0, 3: v >= 0, 16: v < 0, 17: v >= 0, 18: v < 0, 19: v >= 0}.get(rt)
            if c is None:
                if rt == 24: self.sa = (r(rs) + imm) & 15; return None   # mtsab (byte amount)
                if rt == 25: self.sa = ((r(rs) ^ imm) & 7) * 2; return None
                raise Unsupported('regimm %d at %08x' % (rt, pc))
            return ((pc + 4 + (simm << 2)) & M32 if c else None, rt in (2, 3, 18, 19), 31 if rt >= 16 else 0)
        if op in (2, 3): return (((pc + 4) & 0xF0000000) | ((ins & 0x3FFFFFF) << 2), False, 31 if op == 3 else 0)
        if op in (4, 5, 6, 7, 20, 21, 22, 23):
            a, b = s64(r(rs)), s64(r(rt))
            k = op & 3
            c = (a == b, a != b, a <= 0, a > 0)[k]
            return ((pc + 4 + (simm << 2)) & M32 if c else None, op >= 20, 0)
        if op in (8, 9): w(rt, sx32(r(rs) + simm)); return None
        if op == 10: w(rt, int(s64(r(rs)) < simm)); return None
        if op == 11: w(rt, int(r(rs) < (simm & M64))); return None
        if op == 12: w(rt, r(rs) & imm); return None
        if op == 13: w(rt, r(rs) | imm); return None
        if op == 14: w(rt, r(rs) ^ imm); return None
        if op == 15: w(rt, sx32(imm << 16)); return None
        if op == 16:                                                 # COP0: EI / DI / mfc0 status etc.
            if rs == 8: raise Unsupported('bc0 at %08x' % pc)
            if rs == 0: w(rt, 0)
            return None
        if op == 17: return self._cop1(ins, pc, rs, rt, rd, sh)
        if op == 18: return self._cop2(ins, pc, rs, rt, rd)
        if op in (24, 25): w(rt, r(rs) + simm); return None
        if op == 28: return self._mmi(ins, pc, rs, rt, rd, sh)
        a = (r(rs) + simm) & M32
        if op == 30: self.w128(rt, self.read(a & ~15, 16)); return None              # lq
        if op == 31: self.write(a & ~15, 16, self.gpr[rt]); return None               # sq
        if op == 32: w(rt, s64(self.read(a, 1) << 56) >> 56); return None
        if op == 33: v = self.read(a, 2); w(rt, v - 0x10000 if v & 0x8000 else v); return None
        if op == 35: w(rt, sx32(self.read(a, 4))); return None
        if op == 36: w(rt, self.read(a, 1)); return None
        if op == 37: w(rt, self.read(a, 2)); return None
        if op == 39: w(rt, self.read(a, 4)); return None
        if op == 55: w(rt, self.read(a, 8)); return None
        if op == 40: self.write(a, 1, r(rt)); return None
        if op == 41: self.write(a, 2, r(rt)); return None
        if op == 43: self.write(a, 4, r(rt)); return None
        if op == 63: self.write(a, 8, r(rt)); return None
        if op == 49: self.fpr[rt] = self.read(a, 4); return None                     # lwc1
        if op == 57: self.write(a, 4, self.fpr[rt]); return None                     # swc1
        if op == 54:
            v = self.read(a & ~15, 16)
            if rt: self.vf[rt] = [(v >> (32 * i)) & M32 for i in range(4)]
            return None
        if op == 62: self.write(a & ~15, 16, sum(x << (32 * i) for i, x in enumerate(self.vf[rt]))); return None
        if op in (47, 51): return None                                               # cache, pref
        if op in (34, 38, 42, 46, 26, 27, 44, 45):                                   # lwl lwr swl swr ldl ldr sdl sdr
            return self._unaligned(op, a, rt)
        raise Unsupported('op %d at %08x' % (op, pc))

    def _unaligned(self, op, a, rt):
        n = 8 if op in (26, 27, 44, 45) else 4
        base = a & ~(n - 1); k = a & (n - 1)
        mem = self.read(base, n); reg = self.r(rt); bits = 8 * n; mask = (1 << bits) - 1
        if op in (34, 26):                       # lwl / ldl: high bytes from memory
            sft = (n - 1 - k) * 8
            v = ((mem << sft) & mask) | (reg & ((1 << sft) - 1))
            self.w(rt, sx32(v) if n == 4 else v)
        elif op in (38, 27):                     # lwr / ldr
            sft = k * 8
            keep = (mask ^ (mask >> sft)) & mask
            v = (mem >> sft) | (reg & keep)
            if n == 4: v = sx32(v) if k == 0 else (self.r(rt) & ~M32) | (v & M32)
            self.w(rt, v)
        elif op in (42, 44):                     # swl / sdl
            sft = (n - 1 - k) * 8
            v = (mem & ~(mask >> sft) & mask) | ((reg & mask) >> sft)
            self.write(base, n, v)
        else:                                    # swr / sdr
            sft = k * 8
            v = (mem & ((1 << sft) - 1)) | (((reg & mask) << sft) & mask)
            self.write(base, n, v)
        return None

    # ---------------- FPU ----------------
    def _cop1(self, ins, pc, rs, rt, rd, sh):
        ft, fs, fd = rt, rd, sh
        if rs == 0: self.w(rt, sx32(self.fpr[fs])); return None                       # mfc1
        if rs == 2: self.w(rt, sx32(self.fcr31 if fs == 31 else 0x2E00)); return None  # cfc1
        if rs == 4: self.fpr[fs] = self.r(rt) & M32; return None                      # mtc1
        if rs == 6:
            if fs == 31: self.fcr31 = self.r(rt) & M32
            return None
        if rs == 8:                                                                    # bc1f / bc1t (l)
            c = bool(self.fcr31 & 0x800000) == bool(rt & 1)
            simm = ins & 0xFFFF; simm = simm - 0x10000 if simm & 0x8000 else simm
            return ((pc + 4 + (simm << 2)) & M32 if c else None, bool(rt & 2), 0)
        if rs == 20:                                                                   # W format: cvt.s.w
            if ins & 63 == 32: self.fw(fd, float(s32(self.fpr[fs]))); return None
            raise Unsupported('cop1.w %d at %08x' % (ins & 63, pc))
        if rs != 16: raise Unsupported('cop1 rs %d at %08x' % (rs, pc))
        fn = ins & 63; a = self.f(fs); b = self.f(ft)
        if fn == 0: self.fw(fd, a + b)
        elif fn == 1: self.fw(fd, a - b)
        elif fn == 2: self.fw(fd, a * b)
        elif fn == 3:
            if b == 0: self.fpr[fd] = ((f2u(a) ^ f2u(b)) & 0x80000000) | 0x7F7FFFFF
            else: self.fw(fd, a / b)
        elif fn == 4: self.fw(fd, math.sqrt(abs(b)))
        elif fn == 5: self.fpr[fd] = self.fpr[fs] & 0x7FFFFFFF
        elif fn == 6: self.fpr[fd] = self.fpr[fs]
        elif fn == 7: self.fpr[fd] = self.fpr[fs] ^ 0x80000000
        elif fn == 22:
            s = math.sqrt(abs(b))
            self.fw(fd, a / s if s else FMAX)
        elif fn == 24: self.acc = fclamp(a + b)
        elif fn == 25: self.acc = fclamp(a - b)
        elif fn == 26: self.acc = fclamp(a * b)
        elif fn == 28: self.fw(fd, self.acc + a * b)
        elif fn == 29: self.fw(fd, self.acc - a * b)
        elif fn == 30: self.acc = fclamp(self.acc + a * b)
        elif fn == 31: self.acc = fclamp(self.acc - a * b)
        elif fn == 36:                                                                 # cvt.w.s (truncate, saturate)
            v = int(a) if abs(a) < 2147483648.0 else (0x7FFFFFFF if a > 0 else -0x80000000)
            self.fpr[fd] = v & M32
        elif fn == 40: self.fw(fd, max(a, b))
        elif fn == 41: self.fw(fd, min(a, b))
        elif fn in (48, 50, 52, 54):
            c = {48: False, 50: a == b, 52: a < b, 54: a <= b}[fn]
            self.fcr31 = (self.fcr31 | 0x800000) if c else (self.fcr31 & ~0x800000)
        else: raise Unsupported('cop1.s %d at %08x' % (fn, pc))
        return None

    # ---------------- MMI ----------------
    def _lanes(self, v, n): return [(v >> (n * i)) & ((1 << n) - 1) for i in range(128 // n)]
    def _pack(self, ls, n): return sum((x & ((1 << n) - 1)) << (n * i) for i, x in enumerate(ls))

    def _mmi(self, ins, pc, rs, rt, rd, sh):
        fn = ins & 63; A = self.gpr[rs]; B = self.gpr[rt]
        def sgn(x, n): return x - (1 << n) if x >> (n - 1) else x
        if fn in (0, 1, 32, 33):                                     # madd maddu madd1 maddu1
            hi, lo = (self.hi1, self.lo1) if fn >= 32 else (self.hi, self.lo)
            acc = ((hi & M32) << 32) | (lo & M32)
            if fn in (0, 32): acc = sgn(acc, 64) + s32(self.r(rs)) * s32(self.r(rt))
            else: acc = acc + (self.r(rs) & M32) * (self.r(rt) & M32)
            lo, hi = sx32(acc), sx32(acc >> 32)
            if fn >= 32: self.hi1, self.lo1 = hi, lo
            else: self.hi, self.lo = hi, lo
            self.w(rd, lo); return None
        if fn == 4:                                                  # plzcw
            res = []
            for x in self._lanes(self.r(rs), 32)[:2]:
                b = x >> 31; c = 0
                for k in range(30, -1, -1):
                    if (x >> k) & 1 == b: c += 1
                    else: break
                res.append(c)
            self.w(rd, res[0] | (res[1] << 32)); return None
        if fn == 16: self.w(rd, self.hi1); return None
        if fn == 17: self.hi1 = self.r(rs); return None
        if fn == 18: self.w(rd, self.lo1); return None
        if fn == 19: self.lo1 = self.r(rs); return None
        if fn in (24, 25):                                           # mult1 multu1
            p = s32(self.r(rs)) * s32(self.r(rt)) if fn == 24 else (self.r(rs) & M32) * (self.r(rt) & M32)
            self.lo1 = sx32(p); self.hi1 = sx32(p >> 32); self.w(rd, self.lo1); return None
        if fn in (26, 27):                                           # div1 divu1
            a, b = (s32(self.r(rs)), s32(self.r(rt))) if fn == 26 else (self.r(rs) & M32, self.r(rt) & M32)
            if b:
                qv = abs(a) // abs(b) * (1 if (a < 0) == (b < 0) else -1); self.lo1 = sx32(qv); self.hi1 = sx32(a - qv * b)
            return None
        if fn == 48 and sh in (0, 8):                                # pmfhl.lw / .uw are rare
            raise Unsupported('pmfhl at %08x' % pc)
        if fn in (8, 40, 9, 41):
            grp = {8: 'MMI0', 40: 'MMI1', 9: 'MMI2', 41: 'MMI3'}[fn]
            k = (grp, sh)
            L = lambda v, n: self._lanes(v, n)
            if k == ('MMI0', 0): r = self._pack([a + b for a, b in zip(L(A, 32), L(B, 32))], 32)          # paddw
            elif k == ('MMI0', 1): r = self._pack([a - b for a, b in zip(L(A, 32), L(B, 32))], 32)        # psubw
            elif k == ('MMI0', 2): r = self._pack([M32 if sgn(a, 32) > sgn(b, 32) else 0 for a, b in zip(L(A, 32), L(B, 32))], 32)  # pcgtw
            elif k == ('MMI0', 3): r = self._pack([a if sgn(a, 32) > sgn(b, 32) else b for a, b in zip(L(A, 32), L(B, 32))], 32)  # pmaxw
            elif k == ('MMI0', 4): r = self._pack([a + b for a, b in zip(L(A, 16), L(B, 16))], 16)        # paddh
            elif k == ('MMI0', 5): r = self._pack([a - b for a, b in zip(L(A, 16), L(B, 16))], 16)        # psubh
            elif k == ('MMI0', 8): r = self._pack([a + b for a, b in zip(L(A, 8), L(B, 8))], 8)           # paddb
            elif k == ('MMI0', 9): r = self._pack([a - b for a, b in zip(L(A, 8), L(B, 8))], 8)           # psubb
            elif k == ('MMI0', 18):                                                                         # pextlw
                a, b = L(A, 32), L(B, 32); r = self._pack([b[0], a[0], b[1], a[1]], 32)
            elif k == ('MMI0', 19):                                                                         # ppacw
                a, b = L(A, 32), L(B, 32); r = self._pack([b[0], b[2], a[0], a[2]], 32)
            elif k == ('MMI0', 22):                                                                         # pextlh
                a, b = L(A, 16), L(B, 16); r = self._pack([x for i in range(4) for x in (b[i], a[i])], 16)
            elif k == ('MMI0', 23):                                                                         # ppach
                a, b = L(A, 16), L(B, 16); r = self._pack([b[0], b[2], b[4], b[6], a[0], a[2], a[4], a[6]], 16)
            elif k == ('MMI0', 26):                                                                         # pextlb
                a, b = L(A, 8), L(B, 8); r = self._pack([x for i in range(8) for x in (b[i], a[i])], 8)
            elif k == ('MMI0', 30):                                                                         # pext5 (rare)
                raise Unsupported('pext5 at %08x' % pc)
            elif k == ('MMI1', 1): r = self._pack([(-sgn(b, 32)) & M32 if sgn(b, 32) < 0 else b for b in L(B, 32)], 32)  # pabsw
            elif k == ('MMI1', 2): r = self._pack([M32 if a == b else 0 for a, b in zip(L(A, 32), L(B, 32))], 32)  # pceqw
            elif k == ('MMI1', 3): r = self._pack([a if sgn(a, 32) < sgn(b, 32) else b for a, b in zip(L(A, 32), L(B, 32))], 32)  # pminw
            elif k == ('MMI1', 16): r = self._pack([a + b for a, b in zip(L(A, 32), L(B, 32))], 32)       # padduw (approx)
            elif k == ('MMI1', 18):                                                                         # pextuw
                a, b = L(A, 32), L(B, 32); r = self._pack([b[2], a[2], b[3], a[3]], 32)
            elif k == ('MMI1', 22):                                                                         # pextuh
                a, b = L(A, 16), L(B, 16); r = self._pack([x for i in range(4, 8) for x in (b[i], a[i])], 16)
            elif k == ('MMI1', 26):                                                                         # pextub
                a, b = L(A, 8), L(B, 8); r = self._pack([x for i in range(8, 16) for x in (b[i], a[i])], 8)
            elif k == ('MMI2', 14):                                                                         # pcpyld
                r = ((A & M64) << 64) | (B & M64)
            elif k == ('MMI2', 18): r = A & B                                                               # pand
            elif k == ('MMI2', 19): r = A ^ B                                                               # pxor
            elif k == ('MMI2', 26):                                                                         # pexeh
                b = L(B, 16); r = self._pack([b[2], b[1], b[0], b[3], b[6], b[5], b[4], b[7]], 16)
            elif k == ('MMI2', 27):                                                                         # prevh
                b = L(B, 16); r = self._pack([b[3], b[2], b[1], b[0], b[7], b[6], b[5], b[4]], 16)
            elif k == ('MMI2', 30):                                                                         # pexew
                b = L(B, 32); r = self._pack([b[2], b[1], b[0], b[3]], 32)
            elif k == ('MMI2', 31):                                                                         # prot3w
                b = L(B, 32); r = self._pack([b[1], b[2], b[0], b[3]], 32)
            elif k == ('MMI2', 8): r = (self.hi & M64) | ((self.hi1 & M64) << 64)                         # pmfhi
            elif k == ('MMI2', 9): r = (self.lo & M64) | ((self.lo1 & M64) << 64)                         # pmflo
            elif k == ('MMI1', 27): r = ((((A << 128) | B) >> (8 * (self.sa & 15))) & ((1 << 128) - 1))   # qfsrv
            elif k == ('MMI3', 8): self.hi = A & M64; self.hi1 = (A >> 64) & M64; return None               # pmthi
            elif k == ('MMI3', 9): self.lo = A & M64; self.lo1 = (A >> 64) & M64; return None               # pmtlo
            elif k == ('MMI3', 14):                                                                         # pcpyud
                r = (A >> 64) | ((B >> 64) << 64)
            elif k == ('MMI3', 18): r = A | B                                                               # por
            elif k == ('MMI3', 19): r = ~(A | B) & ((1 << 128) - 1)                                         # pnor
            elif k == ('MMI3', 27):                                                                         # pcpyh
                b = L(B, 16); r = self._pack([b[0]] * 4 + [b[4]] * 4, 16)
            elif k == ('MMI3', 30):                                                                         # pexcw
                b = L(B, 32); r = self._pack([b[0], b[2], b[1], b[3]], 32)
            else: raise Unsupported('%s %d at %08x' % (grp, sh, pc))
            self.w128(rd, r); return None
        raise Unsupported('mmi %d at %08x' % (fn, pc))

    # ---------------- VU0 macro mode (registers hold raw words; math through u2f / fclamp) ----------------
    def _cop2(self, ins, pc, rs, rt, rd):
        vf = self.vf
        if not (ins >> 25) & 1:
            if rs == 1: self.w128(rt, sum(x << (32 * i) for i, x in enumerate(vf[rd]))); return None          # qmfc2
            if rs == 5:                                                                                      # qmtc2
                if rd: v = self.gpr[rt]; vf[rd] = [(v >> (32 * i)) & M32 for i in range(4)]
                return None
            if rs == 2:                                                                                      # cfc2
                v = self.vi[rd] if rd < 16 else {21: f2u(self.vI), 22: f2u(self.q)}.get(rd, 0)
                self.w(rt, sx32(v)); return None
            if rs == 6:                                                                                      # ctc2
                v = self.r(rt) & M32
                if 0 < rd < 16: self.vi[rd] = v & 0xFFFF
                elif rd == 21: self.vI = u2f(v)
                elif rd == 22: self.q = u2f(v)
                return None
            raise Unsupported('cop2 rs %d at %08x' % (rs, pc))
        dest = [(ins >> (24 - i)) & 1 for i in range(4)]       # x y z w
        ft, fs, fd = (ins >> 16) & 31, (ins >> 11) & 31, (ins >> 6) & 31
        fn = ins & 63
        S = [u2f(x) for x in vf[fs]]; T = [u2f(x) for x in vf[ft]]; A = self.vacc
        def put(d, vals):
            if d == 0: return
            nv = list(vf[d])
            for i in range(4):
                if dest[i]: nv[i] = f2u(fclamp(vals[i]))
            vf[d] = nv
        def acc(vals):
            for i in range(4):
                if dest[i]: A[i] = fclamp(vals[i])
        Q = [self.q] * 4; I = [self.vI] * 4
        if fn < 0x3C:
            if fn < 0x1C: b = [T[fn & 3]] * 4; k = fn >> 2
            elif fn in (0x1C, 0x20, 0x21, 0x24, 0x25): b = Q; k = {0x1C: 6, 0x20: 0, 0x21: 2, 0x24: 1, 0x25: 3}[fn]
            elif fn in (0x1D, 0x1E, 0x1F, 0x22, 0x23, 0x26, 0x27): b = I; k = {0x1D: 4, 0x1E: 6, 0x1F: 5, 0x22: 0, 0x23: 2, 0x26: 1, 0x27: 3}[fn]
            elif 0x28 <= fn <= 0x2F and fn != 0x2E: b = T; k = {0x28: 0, 0x29: 2, 0x2A: 6, 0x2B: 4, 0x2C: 1, 0x2D: 3, 0x2F: 5}[fn]
            elif fn == 0x2E: put(fd, [A[0] - S[1] * T[2], A[1] - S[2] * T[0], A[2] - S[0] * T[1], 0.0]); return None   # vopmsub
            else:
                vi = self.vi
                imm5 = fd - 32 if fd & 16 else fd
                if fn == 0x30: d, v = fd & 15, vi[fs & 15] + vi[ft & 15]
                elif fn == 0x31: d, v = fd & 15, vi[fs & 15] - vi[ft & 15]
                elif fn == 0x32: d, v = ft & 15, vi[fs & 15] + imm5
                elif fn == 0x34: d, v = fd & 15, vi[fs & 15] & vi[ft & 15]
                elif fn == 0x35: d, v = fd & 15, vi[fs & 15] | vi[ft & 15]
                else: raise Unsupported('vu0 %02x at %08x (microprogram call?)' % (fn, pc))
                if d: vi[d] = v & 0xFFFF
                return None
            put(fd, [(S[i] + b[i], S[i] - b[i], A[i] + S[i] * b[i], A[i] - S[i] * b[i],
                      max(S[i], b[i]), min(S[i], b[i]), S[i] * b[i])[k] for i in range(4)])
            return None
        k = (fd << 2) | (fn & 3)
        if k < 0x10 or 0x18 <= k < 0x1C or k in (0x1C, 0x1E) or 0x20 <= k <= 0x2D:
            if k < 0x10: b, g = [T[k & 3]] * 4, k >> 2
            elif k < 0x1C: b, g = [T[k & 3]] * 4, 4
            elif k == 0x1C: b, g = Q, 4
            elif k == 0x1E: b, g = I, 4
            elif k < 0x28: b, g = (Q if k in (0x20, 0x21, 0x24, 0x25) else I), {0: 0, 1: 2, 4: 1, 5: 3}[k & 5]
            else:
                if k == 0x2B: raise Unsupported('vu0 special2 %02x at %08x' % (k, pc))
                b, g = T, {0x28: 0, 0x29: 2, 0x2A: 4, 0x2C: 1, 0x2D: 3}[k]
            acc([(S[i] + b[i], S[i] - b[i], A[i] + S[i] * b[i], A[i] - S[i] * b[i], S[i] * b[i])[g] for i in range(4)])
            return None
        if 0x10 <= k < 0x18:
            sc = (1.0, 16.0, 4096.0, 32768.0)[k & 3]
            if not ft: return None
            nv = list(vf[ft])
            for i in range(4):
                if not dest[i]: continue
                if k < 0x14: nv[i] = f2u(fclamp(s32(vf[fs][i]) / sc))                      # vitof
                else:                                                                      # vftoi
                    x = S[i] * sc
                    nv[i] = (int(x) if abs(x) < 2147483648.0 else (0x7FFFFFFF if x > 0 else -0x80000000)) & M32
            vf[ft] = nv
            return None
        if k == 0x1D: put(ft, [abs(x) for x in S])
        elif k == 0x1F: raise Unsupported('vclipw at %08x' % pc)
        elif k == 0x2E: acc([S[1] * T[2], S[2] * T[0], S[0] * T[1], 0.0])            # vopmula
        elif k == 0x2F: pass                                                         # vnop
        elif k == 0x30:                                                              # vmove (raw)
            if ft: vf[ft] = [vf[fs][i] if dest[i] else vf[ft][i] for i in range(4)]
        elif k == 0x31:                                                              # vmr32 (raw)
            if ft:
                src = [vf[fs][1], vf[fs][2], vf[fs][3], vf[fs][0]]
                vf[ft] = [src[i] if dest[i] else vf[ft][i] for i in range(4)]
        elif k in (0x38, 0x39, 0x3A):
            fsf, ftf = (ins >> 21) & 3, (ins >> 23) & 3
            a, b = S[fsf], T[ftf]
            if k == 0x38: self.q = fclamp(a / b) if b else (FMAX if a >= 0 else -FMAX)
            elif k == 0x39: self.q = fclamp(math.sqrt(abs(b)))
            else:
                s = math.sqrt(abs(b)); self.q = fclamp(a / s) if s else FMAX
        elif k == 0x3B: pass                                                         # vwaitq
        elif k == 0x3C:                                                              # vmtir
            if ft & 15: self.vi[ft & 15] = vf[fs][(ins >> 21) & 3] & 0xFFFF
        elif k == 0x3D:                                                              # vmfir
            v = self.vi[fs & 15]; v = v - 0x10000 if v & 0x8000 else v
            if ft: vf[ft] = [(v & M32) if dest[i] else vf[ft][i] for i in range(4)]
        else: raise Unsupported('vu0 special2 %02x at %08x' % (k, pc))
        return None
