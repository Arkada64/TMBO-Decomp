# quick checks of the interpreter on hand-assembled R5900 code (run: python3 test_ee.py)
import struct
from ee import EE, u2f, f2u
def R(op, rs, rt, rd, sh, fn): return (op << 26) | (rs << 21) | (rt << 16) | (rd << 11) | (sh << 6) | fn
def I(op, rs, rt, imm): return (op << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)
def J(op, t): return (op << 26) | ((t >> 2) & 0x3FFFFFF)
JR_RA = R(0, 31, 0, 0, 0, 8); NOP = 0
def run(code, args=(), setup=None):
    ram = bytearray(0x2000000)
    for i, w in enumerate(code): struct.pack_into('<I', ram, 0x100000 + 4 * i, w)
    ee = EE(ram)
    if setup: setup(ee)
    v = ee.call(0x100000, args, sp=0x1F00000)
    return ee, v
# factorial(n): v0 = 1; loop: v0 *= a0; a0 -= 1; bne a0, 0, loop
ee, v = run([I(9, 0, 2, 1),                      # addiu v0, zero, 1
             R(0, 2, 4, 2, 0, 24),               # mult v0, v0, a0   (R5900 3-operand)
             I(9, 4, 4, -1),                     # addiu a0, a0, -1
             I(5, 4, 0, -3),                     # bne a0, zero, -3 (to mult)
             NOP, JR_RA, NOP], (6,))
assert v == 720, v
# branch-likely not taken skips its slot: beql zero, a0 (not equal) ; slot addiu v0 = 99 must be skipped
ee, v = run([I(9, 0, 2, 5), I(20, 0, 4, 4), I(9, 0, 2, 99), JR_RA, NOP], (3,))
assert v == 5, v
# lq / sq 128-bit copy and lw sign extension
def st(ee): ee.ram[0x200000:0x200010] = bytes(range(0xF0, 0x100))
ee, v = run([I(0x1E, 4, 8, 0), I(0x1F, 5, 8, 0), I(35, 5, 2, 12), JR_RA, NOP], (0x200000, 0x200100), st)
assert ee.ram[0x200100:0x200110] == bytes(range(0xF0, 0x100)) and v == 0xFFFFFFFFFFFFFFFF & (0xFFFEFDFC - (1 << 32)), hex(v)
# FPU: f0 = a * b + c via mtc1 / mul.s / add.s
def fp(ee):
    ee.fpr[2], ee.fpr[4], ee.fpr[6] = f2u(1.5), f2u(4.0), f2u(0.25)
ee, v = run([R(17, 16, 4, 2, 0, 2), R(17, 16, 6, 0, 0, 0), JR_RA, NOP], (), fp)   # mul.s f0,f2,f4 ; add.s f0,f0,f6
assert u2f(ee.fpr[0]) == 6.25, u2f(ee.fpr[0])
# VU0: lqc2 vf1 ; vadd.xyzw vf2, vf1, vf1 ; sqc2 vf2
def vu(ee):
    ee.ram[0x300000:0x300010] = struct.pack('<4f', 1, 2, 3, 4)
vadd = (18 << 26) | (1 << 25) | (0xF << 21) | (1 << 16) | (1 << 11) | (2 << 6) | 0x28
ee, v = run([I(0x36, 4, 1, 0), vadd, I(0x3E, 4, 2, 16), JR_RA, NOP], (0x300000,), vu)
assert struct.unpack('<4f', ee.ram[0x300010:0x300020]) == (2, 4, 6, 8)
# journal undo
ee.begin(); ee.write(0x300000, 4, 0xDEADBEEF); ee.undo()
assert struct.unpack_from('<f', ee.ram, 0x300000)[0] == 1.0
# jal hook sees the target
seen = []
def hk(ee):
    ee.on_call = lambda e, t: seen.append(t)
ee, v = run([R(0, 31, 0, 16, 0, 33), J(3, 0x100014), NOP, R(0, 16, 0, 0, 0, 8), NOP, JR_RA, NOP], (), hk)   # s0 = ra; jal; jr s0
print('ok, hook saw', [hex(x) for x in seen])
