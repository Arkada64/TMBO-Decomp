#!/usr/bin/env python3
# ruff: noqa
"""
tools/mods/apply_mods.py apply|revert : patch the split asm for TMB-Reloaded mods (shiftable build only).
build_shiftable.sh runs `apply` before linking and `revert` after, so the normal build stays byte-identical.
Mods:
  traffic: level loader func_00127650 sends db nodes 0x401..0xBB7 to tmbr_FodderParse (mods/traffic.s)
  peds:    loader sends nodes 0xBB8..0xF9F to func_00178248 (addPedEpNode), and func_00138358 no longer
           clears the pedestrian 'enabled' flag (was the "Pedestrians online v2" pnach)
"""

import sys, shutil, os
from pathlib import Path

R = Path.home() / "tmbo_decomp"
LOADER = R / "asm/nonmatchings/online/after_prison_10/func_00127650.s"
GAME = R / "asm/nonmatchings/tmb/game/func_00138358.s"
TOUCH = [R / "src/online/after_prison_10.c", R / "src/tmb/game.c"]
HOOKS = (
    """\
.Ltmbr_fodder:
    lw         $4, %gp_rel(D_004FA030)($28)
    jal        tmbr_FodderParse
    daddu      $5, $17, $0
    b          .L00127AE8
    lq         $31, 0x20($29)
.Ltmbr_peds:
    jal        func_00178248
    daddu      $4, $17, $0
    b          .L00127AE8
    lq         $31, 0x20($29)
"""
    + "    nop\n" * 23
)
# ^ code growth inside the game's .text must be a multiple of 0x80: some code is followed by data that is
#   read with 128-bit lq (e.g. libmpeg's clamp mask D_002524C0), which ignores the low 4 address bits.
#   9 hook instructions + 23 nops = 0x80. A 0x28-byte growth gave full-screen green bars.
assert (
    sum(1 for l in HOOKS.splitlines() if l.strip() and not l.strip().endswith(":"))
    * 4
    % 0x80
    == 0
)


def sub_line(text, addr, old, new):
    out, hit = [], 0
    for l in text.split("\n"):
        if f" {addr} " in l and old in l:
            l = l.replace(old, new)
            hit += 1
        out.append(l)
    assert hit == 1, f"patch site {addr} '{old}' found {hit}x"
    return "\n".join(out)


DBG = os.environ.get("TMBR_DEBUG_LOADER") == "1"
CALLERS = [
    R / f"asm/nonmatchings/online/after_prison_10/{n}.s"
    for n in ("func_001274D0", "func_00127188", "func_00127330")
]


def apply():
    if DBG:  # route the db traversal callback through tmbr_LoaderDbg
        for f in CALLERS:
            bak = f.with_suffix(".s.orig")
            if not bak.exists():
                shutil.copy(f, bak)
            t = bak.read_text()
            assert (
                t.count("%hi(func_00127650)") == 1
                and t.count("%lo(func_00127650)") == 1
            ), f
            f.write_text(t.replace("(func_00127650)", "(tmbr_LoaderDbg)"))
        print("debug: loader callback wrapped")
    for f in (LOADER, GAME):
        bak = f.with_suffix(".s.orig")
        if not bak.exists():
            shutil.copy(f, bak)
        shutil.copy(bak, f)  # always patch from the original
    t = LOADER.read_text()
    t = sub_line(
        t, "0012777C", "bnez       $2, .L00127AE8", "bnez       $2, .Ltmbr_fodder"
    )
    t = sub_line(
        t, "00127788", "bnel       $2, $0, .L00127AEC", "bnel       $2, $0, .Ltmbr_peds"
    )
    t = sub_line(t, "0012778C", "lq        $17, 0x10($29)", "nop")
    assert t.count("endlabel func_00127650") == 1
    t = t.replace("endlabel func_00127650", HOOKS + "endlabel func_00127650")
    LOADER.write_text(t)
    g = GAME.read_text()
    g = sub_line(g, "00138828", "sw         $0, 0x3944($2)", "nop")
    GAME.write_text(g)
    for c in TOUCH:
        os.utime(c)
    print("mods applied: traffic, peds")


def revert():
    for f in (LOADER, GAME, *CALLERS):
        bak = f.with_suffix(".s.orig")
        if bak.exists():
            shutil.copy(bak, f)
            bak.unlink()
    for c in TOUCH:
        os.utime(c)
    print("mods reverted")


{"apply": apply, "revert": revert}[sys.argv[1]]()
