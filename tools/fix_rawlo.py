#!/usr/bin/env python3
# ruff: noqa
"""
fix_rawlo.py MATCHING_ELF : spimdisasm sometimes can't pair a %lo with its lui (the lui is in another
basic block, or the base register is reused several times), so it prints the low half as a raw number:
    lui   $20, %hi(D_00612BC0)   ...   addiu $4, $20, 0x2BC0
Bytes match, but in a shifted build the lui moves and the 0x2BC0 doesn't -> the code writes to the old
address (this broke the controller state machine). Rewrite the raw immediate as %lo(SYM) when lui-hi +
immediate is exactly SYM's address. Same bytes in a normal build. Idempotent.
"""

import re, sys, subprocess
from pathlib import Path

R = Path.home() / "tmbo_decomp"
S = {}
for l in subprocess.run(
    ["mips-linux-gnu-nm", sys.argv[1]], capture_output=True, text=True
).stdout.splitlines():
    p = l.split()
    if len(p) == 3:
        S.setdefault(p[2], int(p[0], 16))
INS = re.compile(r"^(\s*/\* [0-9A-F]+ [0-9A-F]{8} [0-9A-F]{8} \*/\s+)(\S+)(\s*)(.*)$")
NODEST = {
    "sb",
    "sh",
    "sw",
    "sd",
    "sq",
    "swc1",
    "sdc1",
    "sqc2",
    "swl",
    "swr",
    "sdl",
    "sdr",
    "sc",
    "scd",
    "b",
    "beq",
    "bne",
    "beqz",
    "bnez",
    "blez",
    "bgtz",
    "bltz",
    "bgez",
    "beql",
    "bnel",
    "beqzl",
    "bnezl",
    "blezl",
    "bgtzl",
    "bltzl",
    "bgezl",
    "j",
    "jr",
    "jal",
    "jalr",
    "nop",
    "sync",
    "sync.p",
    "sync.l",
    "syscall",
    "break",
    "mtc1",
    "mtc0",
    "mthi",
    "mtlo",
    "mult",
    "multu",
    "div",
    "divu",
    "mult1",
    "div1",
    "divu1",
    "mtsab",
    "cache",
    "pref",
    "teq",
    "tne",
    "ei",
    "di",
    "eret",
    "bc1t",
    "bc1f",
    "bc1tl",
    "bc1fl",
    "c.eq.s",
    "c.lt.s",
    "c.le.s",
    "ctc1",
    "qmtc2",
    "ctc2",
    "vcallms",
    "lwc1",
    "ldc1",
    "lqc2",
    "mthi1",
    "mtlo1",
}
MEMOPS = {
    "lb",
    "lbu",
    "lh",
    "lhu",
    "lw",
    "lwu",
    "ld",
    "lq",
    "sb",
    "sh",
    "sw",
    "sd",
    "sq",
    "lwc1",
    "swc1",
    "ldc1",
    "sdc1",
    "lqc2",
    "sqc2",
    "lwl",
    "lwr",
    "ldl",
    "ldr",
    "swl",
    "swr",
    "sdl",
    "sdr",
}
NUM = r"-?0x[0-9A-Fa-f]+|-?\d+"


def target(sym, imm):
    s = S[sym]
    hi = (s + 0x8000) >> 16
    iv = int(imm, 0) & 0xFFFF
    return ((hi << 16) + (iv - 0x10000 if iv & 0x8000 else iv)) & 0xFFFFFFFF


n = 0
dirs = set()
for f in (R / "asm").rglob("*.s"):
    if "asm/data" in str(f):
        continue
    L = f.read_text(errors="ignore").split("\n")
    reg = {}
    changed = False
    for i, l in enumerate(L):
        if re.match(r"\s*(glabel|endlabel)\s", l):
            reg = {}
        m = INS.match(l)
        if not m:
            continue
        op, args = m.group(2), m.group(4)
        ops = [a.strip() for a in re.split(r",(?![^()]*\))", args)] if args else []
        if op == "lui" and ops and "%hi(" in args:
            reg[ops[0]] = re.search(r"%hi\(([^)]+)\)", args).group(1)
            continue
        new = None
        if op in MEMOPS and len(ops) == 2:
            mm = re.match(rf"({NUM})\((\$\w+)\)$", ops[1])
            if (
                mm
                and mm.group(2) in reg
                and reg[mm.group(2)] in S
                and target(reg[mm.group(2)], mm.group(1)) == S[reg[mm.group(2)]]
            ):
                new = f"{ops[0]}, %lo({reg[mm.group(2)]})({mm.group(2)})"
        elif (
            op in ("addiu", "daddiu")
            and len(ops) == 3
            and re.fullmatch(NUM, ops[2])
            and ops[1] in reg
            and reg[ops[1]] in S
            and target(reg[ops[1]], ops[2]) == S[reg[ops[1]]]
        ):
            new = f"{ops[0]}, {ops[1]}, %lo({reg[ops[1]]})"
        if new:
            L[i] = f"{m.group(1)}{op}{m.group(3)}{new}"
            changed = True
            n += 1
        # register copies of a lui'd value (`daddu $s4, $v0, $zero`) carry the %hi along
        if (
            op in ("daddu", "addu", "or")
            and len(ops) == 3
            and ops[2] in ("$zero", "$0")
            and ops[1] in reg
        ):
            reg[ops[0]] = reg[ops[1]]
            continue
        if op not in NODEST and ops:
            d = ops[0]
            if (
                op in ("addiu", "daddiu")
                and "%lo(" in L[i]
                and len(ops) > 1
                and d == ops[1]
            ):
                reg.pop(d, None)
            elif d in reg:
                del reg[d]
    if changed:
        f.write_text("\n".join(L))
        dirs.add(str(f.parent))
# libmpeg mpc.s: func_00252478 (MMI copy/saturate loop) was disassembled as .word data, so its
# `lui/addiu $t2, D_002524C0` (address of the 0x00FF00FF clamp mask) is raw. In a shifted build it loads
# the old address -> wrong clamp -> green vertical stripes in decoded MPEG/IPU images (menu background).
MPC = R / "asm/sdk/libmpeg/mpc.s"
if MPC.exists():
    t = MPC.read_text()
    t2 = t.replace(".word 0x3C0A0025", "lui        $10, %hi(D_002524C0)").replace(
        ".word 0x254A24C0", "addiu      $10, $10, %lo(D_002524C0)"
    )
    if t2 != t:
        MPC.write_text(t2)
        n += 2
# INCLUDE_ASM'd .s files aren't ninja dependencies of their .c: touch the .c files that include them
import os

for c in (R / "src").rglob("*.c"):
    t = c.read_text(errors="ignore")
    if any(f'"{d}"' in t for d in dirs):
        os.utime(c)
print(f"fix_rawlo: {n} raw %lo immediates symbolized")
