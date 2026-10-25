#!/usr/bin/env python3
"""Shiftable NON_MATCHING link: keep every position-sensitive thing where the game expects it modulo 0x80.
The game reads some data out of .text with 128-bit loads and DMA-copies aligned buffers (a 0x28-byte text growth
gave full-screen green bars; a misaligned bss gave "NO CONTROLLER IN CONTROLLER PORT 1"). So:
  - each C object's .text / .rodata / .data keeps its original size when the C is smaller (padded), and grows
    only in whole 0x80 steps when it is bigger (the drafts' jump tables and strings grew .rodata by 0x18 and the
    bss with it -> no controller);
  - the C float literals (.lit4/.lit8, gp-relative under the SN assembler's -G8) go after the game's .sdata,
    padded to a multiple of 0x80, so .sbss/.bss move by 0x80 steps only.
Original sizes come from the matching build's map. Only the objects of the given C files are guarded (the mods
change other objects on purpose, e.g. the level loader's hook block).  Usage: nm_ld.py MAP LDSCRIPT SRC.c ..."""
import re, sys
mp, ld = sys.argv[1], sys.argv[2]
import json, os
# only the files that really got C in this build (logs/nm/summary.json): a file whose drafts were all skipped is
# the matching file, and moving its sections broke a boot (after_audiodec_81.c, 2026-10-25)
sm = json.load(open(os.path.join(os.path.dirname(os.path.abspath(ld)), "../../logs/nm/summary.json")))
used = {'build/' + f + '.o' for f, st in sm["files"].items() if st.get("used")}
asked = {'build/' + re.sub(r'^.*?/(src/)', r'\1', f) + '.o' for f in sys.argv[3:]}
only = (asked & used) if asked else used
if os.environ.get("NM_GUARD_ALL") and asked: only = asked      # test: guard the asked files even without C
orig = {}        # (object, section) -> size in the matching build
for m in re.finditer(r"^ (\.text|\.rodata|\.data)\s+0x([0-9a-f]+)\s+0x([0-9a-f]+)\s+(build/src/\S+\.c\.o)", open(mp).read(), re.M):
    orig[(m.group(4), m.group(1))] = int(m.group(3), 16)
src_lines = open(ld).read().splitlines()
# C objects whose original had no .rodata / .data in the link script (their C has some now): those sections
# go into the padded block after .sdata with the literals
listed = {(m.group(1), m.group(2)) for m in (re.match(r"^\s*(build/src/\S+\.c\.o)\((\.rodata|\.data)\);$", l) for l in src_lines) if m}
extra = [f"{o}({sec});" for o in sorted(only) for sec in (".rodata", ".data") if (o, sec) not in listed]
out = []; n = 0
for l in src_lines:
    m = re.match(r"^(\s*)(build/src/\S+\.c\.o)\((\.text|\.rodata|\.data)\);$", l)
    if m and m.group(2) in only:
        ind, o = m.group(1), m.group(2); sz = orig.get((o, m.group(3)), 0)
        sym = "__nm_" + re.sub(r"\W", "_", o + m.group(3))
        out += [f"{ind}{sym} = .;", l,
                f"{ind}. = {sym} + ((. - {sym}) <= 0x{sz:X} ? 0x{sz:X} : 0x{sz:X} + ALIGN(. - {sym} - 0x{sz:X}, 0x80));"]
        n += 1; continue
    if re.match(r"^\s*build/asm/data/3F9600\.sdata\.s\.o\(\.sdata\);$", l):
        ind = re.match(r"^(\s*)", l).group(1)
        # each moved section starts 0x80-aligned, like the game's own data (DMA / 128-bit loads)
        out += [l, f"{ind}__nm_lit = .;", f"{ind}*(.lit4);", f"{ind}*(.lit8);"] + [f"{ind}. = ALIGN(0x80); {e}" for e in extra] + [
                f"{ind}. = __nm_lit + ALIGN(. - __nm_lit, 0x80);"]
        continue
    out.append(l)
open(ld, "w").write("\n".join(out) + "\n")
print(f"nm_ld: {n} sections size-guarded, literals + {len(extra)} new sections after .sdata")
