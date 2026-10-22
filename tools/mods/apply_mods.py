#!/usr/bin/env python3
# ruff: noqa
"""
tools/mods/apply_mods.py apply|revert : patch the split asm for TMB-Reloaded mods (shiftable build only).
build_shiftable.sh runs `apply` before linking and `revert` after, so the normal build stays byte-identical.
Mods:
  traffic: level loader func_00127650 sends db nodes 0x401..0xBB7 to tmbr_FodderParse (mods/traffic.s)
  peds:    loader sends nodes 0xBB8..0xF9F to func_00178248 (addPedEpNode), and func_00138358 no longer
           clears the pedestrian 'enabled' flag (was the "Pedestrians online v2" pnach)
  shield:  Respawn Shield hooks into mods/shield.s (was the community "TMA Ruleset/ Respawn Shield" pnach)
Rules: patches replace an instruction 1:1 (j/jal to a mod routine) or add labels. Inserted code inside
the game's .text must be a multiple of 0x80 bytes (see HOOKS).
TMBR_DEBUG_LOADER=1 also routes the db traversal callback through tmbr_LoaderDbg (prints node ids).
"""

import sys, shutil, os, re
from pathlib import Path

R = Path.home() / "tmbo_decomp"
A = lambda p: R / "asm" / p
LOADER = A("nonmatchings/online/after_prison_10/func_00127650.s")
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
# (file, address, expected opcode, replacement instruction)
PATCHES = [
    (LOADER, "0012777C", "bnez", "bnez       $2, .Ltmbr_fodder"),
    (LOADER, "00127788", "bnel", "bnel       $2, $0, .Ltmbr_peds"),
    (LOADER, "0012778C", "lq", "nop"),
    (A("nonmatchings/tmb/game/func_00138358.s"), "00138828", "sw", "nop"),
    # Respawn Shield
    (
        A("nonmatchings/tmb/vehicle/func_001D72D8.s"),
        "001DC07C",
        "addiu",
        "j          tmbr_shield_spawn",
    ),
    (
        A("nonmatchings/tmb/vehicle/func_001E1C40.s"),
        "001E1CBC",
        "bne",
        "beqz       $5, .L001E1CDC",
    ),
    (
        A("nonmatchings/tmb/vehicle/func_001E4690.s"),
        "001E472C",
        "addiu",
        "j          tmbr_shield_c",
    ),
    (
        A("nonmatchings/tmb/game/func_00138C90.s"),
        "001395E0",
        "jal",
        "jal        tmbr_CameraUpdate",
    ),  # free cam
    (
        A("nonmatchings/tmb/game/func_00138C90.s"),
        "00139218",
        "addiu",
        "j          tmbr_SpecMark",
    ),  # spectating -> free cam
    (
        A("nonmatchings/tmb/game/func_001399A8.s"),
        "00139D38",
        "jal",
        "jal        tmbr_InitPOV",
    ),  # default camera = 2nd view
    (
        A("sdk/libgraph/graphdev.s"),
        "00249F2C",
        "jal",
        "jal        tmbr_pnachTick",
    ),  # per-frame pnach writes
    (
        A("nonmatchings/tmb/player/func_0017BE80.s"),
        "0017BF78",
        "beqz",
        "j          tmbr_ShoulderTap",
    ),  # L1/R1 weapon switch on tap only
    (
        A("nonmatchings/tmb/player/func_0017BE80.s"),
        "0017BF00",
        "jal",
        "jal        tmbr_ComboUpdate",
    ),  # quick moves
    (
        A("nonmatchings/tmb/vehicle/func_001E4690.s"),
        "001E4E14",
        "jal",
        "jal        tmbr_shield_hearse",
    ),
    (
        A("nonmatchings/tmb/launch/func_001549A0.s"),
        "00155AB8",
        "jal",
        "j          tmbr_shield_d",
    ),
    (
        A("nonmatchings/tmb/launch/func_001549A0.s"),
        "00155340",
        "lw",
        "j          tmbr_shield_f",
    ),
    (
        A("nonmatchings/tmb/launch/func_00156E08.s"),
        "00156E08",
        "addiu",
        "j          tmbr_shield_e",
    ),
    (A("tmb/collis.s"), "00122D88", "lw", "j          tmbr_shield_h"),
    # retail content packs (mods/packs.c): after LoadLevelDB's level db init, load this level's pack
    (A("tmb/shell.s"), "0018890C", "jal", "jal        tmbr_LevelDbLoaded"),
    # ... and before the level's texture bins are built (level TEX init in func_00188930)
    (A("tmb/shell.s"), "001889E4", "jal", "jal        tmbr_LevelTexInitStub"),
]
# (file, address, label) - global label placed right before that instruction (return points)
LABELS = [
    (A("nonmatchings/tmb/vehicle/func_001D72D8.s"), "001DC084", "tmbr_ret_1DC084"),
    (A("nonmatchings/tmb/vehicle/func_001E4690.s"), "001E4734", "tmbr_ret_1E4734"),
    (A("nonmatchings/tmb/launch/func_001549A0.s"), "00155AC0", "tmbr_ret_155AC0"),
    (A("nonmatchings/tmb/launch/func_001549A0.s"), "00155348", "tmbr_ret_155348"),
    (A("nonmatchings/tmb/launch/func_00156E08.s"), "00156E10", "tmbr_ret_156E10"),
    (A("nonmatchings/tmb/player/func_0017BE80.s"), "0017BF80", "tmbr_ret_17BF80"),
    (A("nonmatchings/tmb/player/func_0017BE80.s"), "0017C060", "tmbr_ret_17C060"),
    (A("nonmatchings/tmb/game/func_00138C90.s"), "00139220", "tmbr_ret_139220"),
    (A("tmb/collis.s"), "00122D8C", "tmbr_ret_122D8C"),
]
# Patches to functions that are already decompiled (matched C): (file, exact old text, new text)
# NOTE: any change in code SIZE moves everything after it, and the shiftable build still has stale data
# references somewhere (the map selector crashes when data moves, even with no mods). Patches must keep every
# function's size; code that needs room goes into the mods area after .bss (see build_shiftable.sh).
# The shield length in matched-C func_001DD0C8 is therefore a post-link word patch (mods/postlink.txt).
C_PATCHES = []
# Plain text substitutions in asm files: (file, exact old text, new text, expected count)
CRT0 = A("gcc/_crt0.s")
ASM_TEXT = [
    # Main-thread stack size (SetupThread arg). The heap runs from the end of .bss to the stack's bottom, so
    # everything the mods add to the ELF comes out of the heap; the map selector ran out (operator new ->
    # abort -> exit to the PS2 menu). TMBR_STACK_SIZE (mods/memory.s) is smaller than the original 0x40000.
    (CRT0, "%hi(D_40000)", "%hi(TMBR_STACK_SIZE)", 1),
    (CRT0, "%lo(D_40000)", "%lo(TMBR_STACK_SIZE)", 1),
    # crt0 zeroes .bss from D_004FB400 up to D_725694 (= main_VRAM_END, the end of everything) - that would
    # wipe the mods, which now sit after .bss. Clear only up to the game's own .bss end; the heap still
    # starts at main_VRAM_END (the second D_725694 pair, $a0).
    (CRT0, "$v1, %hi(D_725694)", "$v1, %hi(main_BSS_END)", 1),
    (CRT0, "$v1, $v1, %lo(D_725694)", "$v1, $v1, %lo(main_BSS_END)", 1),
]
DBG = os.environ.get("TMBR_DEBUG_LOADER") == "1"
# Traffic/peds level-loader hooks: OFF by default. They add 0x80 bytes inside the loader (moves all code and
# data after it -> map selector crash, see above). TMBR_TRAFFIC=1 puts them back for traffic work.
# Peds in normal builds come from the baked "Pedestrians Online" pnach section (same size, stub in a dead func).
NO_TRAFFIC = os.environ.get("TMBR_TRAFFIC") != "1"
if NO_TRAFFIC:
    PATCHES = [p for p in PATCHES if p[0] != LOADER and p[1] != "00138828"]
# TMBR_SKIP=group,group: leave hooks out (for bisecting). Groups by hook address:
GROUPS = {
    "camera": {"00139D38"},
    "freecam": {"001395E0", "00139218"},
    "tick": {"00249F2C"},
    "qm": {"0017BF78", "0017BF00"},
    "packs": {"0018890C", "001889E4"},
    "shield": {
        "001DC07C",
        "001E1CBC",
        "001E472C",
        "001E4E14",
        "00155AB8",
        "00155340",
        "00156E08",
        "00122D88",
    },
}
SKIP = [g for g in os.environ.get("TMBR_SKIP", "").split(",") if g]
for g in SKIP:
    PATCHES = [p for p in PATCHES if p[1] not in GROUPS[g]]
if "shield" in SKIP:
    C_PATCHES = [c for c in C_PATCHES if "0x497" not in c[2]]
if SKIP:
    print("hooks left out:", ",".join(SKIP))
CALLERS = [
    A(f"nonmatchings/online/after_prison_10/{n}.s")
    for n in ("func_001274D0", "func_00127188", "func_00127330")
]
INS = re.compile(r"^(\s*/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/\s+)(\S+)(.*)$")


def files():
    fs = (
        {p[0] for p in PATCHES}
        | {l[0] for l in LABELS}
        | {LOADER}
        | {t[0] for t in ASM_TEXT}
    )
    return fs | (set(CALLERS) if DBG else set())


def touch_c(paths):
    # INCLUDE_ASM'd .s files aren't ninja dependencies of their .c: touch the .c files that include them
    dirs = {str(p.parent) for p in paths}
    for c in (R / "src").rglob("*.c"):
        t = c.read_text(errors="ignore")
        if any(f'"{d}"' in t for d in dirs):
            os.utime(c)


def apply():
    fs = files()
    text = {}
    for f in fs:
        bak = f.with_suffix(".s.orig")
        if not bak.exists():
            shutil.copy(f, bak)
        text[f] = bak.read_text()  # always patch from the original
    for f, addr, op, new in PATCHES:
        L = text[f].split("\n")
        hit = 0
        for i, l in enumerate(L):
            m = INS.match(l)
            if m and m.group(2) == addr:
                assert m.group(3) == op, (
                    f"{f.name} {addr}: expected {op}, found {m.group(3)}"
                )
                L[i] = m.group(1) + new
                hit += 1
        assert hit == 1, f"{f.name} {addr}: patch site found {hit}x"
        text[f] = "\n".join(L)
    for f, addr, lab in LABELS:
        L = text[f].split("\n")
        hit = 0
        for i, l in enumerate(L):
            m = INS.match(l)
            if m and m.group(2) == addr:
                L.insert(i, f".globl {lab}\n{lab}:")
                hit += 1
                break
        assert hit == 1, f"{f.name} {addr}: label site not found"
        text[f] = "\n".join(L)
    for f, old, new, n in ASM_TEXT:
        assert text[f].count(old) == n, (
            f"{f.name}: '{old}' found {text[f].count(old)}x, expected {n}"
        )
        text[f] = text[f].replace(old, new)
    assert text[LOADER].count("endlabel func_00127650") == 1
    if not NO_TRAFFIC:
        text[LOADER] = text[LOADER].replace(
            "endlabel func_00127650", HOOKS + "endlabel func_00127650"
        )
    else:
        print("traffic/peds loader hooks left out (TMBR_NO_TRAFFIC=1)")
    if DBG:
        for f in CALLERS:
            assert (
                text[f].count("%hi(func_00127650)") == 1
                and text[f].count("%lo(func_00127650)") == 1
            ), f
            text[f] = text[f].replace("(func_00127650)", "(tmbr_LoaderDbg)")
        print("debug: loader callback wrapped")
    for f, t in text.items():
        f.write_text(t)
    for f, old, new in C_PATCHES:
        bak = f.with_name(f.name + ".orig")
        if not bak.exists():
            shutil.copy(f, bak)
        t = bak.read_text()
        assert t.count(old) == 1, (
            f"{f.name}: C patch site found {t.count(old)}x (function changed?)"
        )
        f.write_text(t.replace(old, new))
    touch_c(fs)
    print("mods applied: traffic, peds, respawn shield, quick moves, camera, free cam")


def revert():
    fs = files() | set(CALLERS)
    for f in fs:
        bak = f.with_suffix(".s.orig")
        if bak.exists():
            shutil.copy(bak, f)
            bak.unlink()
    for f, _, _ in C_PATCHES:
        for bak in (f.with_name(f.name + ".orig"), f.with_suffix(".c.orig")):
            if bak.exists():
                shutil.copy(bak, f)
                bak.unlink()
    touch_c(fs)
    print("mods reverted")


{"apply": apply, "revert": revert}[sys.argv[1]]()
