#!/bin/bash
# tools/build_shiftable.sh: link the shiftable ELF -> build/SCUS_971.96.shift.elf (PCSX2-ready: entry/paddr fixed).
# With MODS=1 (default):
#   - mods/*.s are assembled and linked in (.text after the last game object, .bss after the game's bss)
#   - tools/mods/apply_mods.py hooks them into the game's asm (reverted afterwards)
#   - the community pnach sections in mods/pnach_sections.txt are baked in (tools/mods/apply_pnach.py)
#   - a version string "TMB-Reloaded <git> <date>" is linked in (symbol tmbr_version)
# Needs tools/post_split.sh to have been run since the last split. Restores the normal build afterwards.
set -e
cd ~/tmbo_decomp && source .venv/bin/activate
MODS=${MODS:-1}
LD=config/US/SCUS_971.96.ld
touch config/US/empty_syms.txt
mips-linux-gnu-nm -n -S build/SCUS_971.96.elf > build/base_syms.txt   # the matching ELF (for pnach translation)
cp build/SCUS_971.96.elf build/base.elf                                  # apply_pnach reads its code (lui of lo-half patches)
cp build.ninja /tmp/build.ninja.shift.bak; cp $LD /tmp/ld.shift.bak
restore() {
  cp /tmp/build.ninja.shift.bak build.ninja; cp /tmp/ld.shift.bak $LD
  [ "$MODS" = 1 ] && python3 tools/mods/apply_mods.py revert || true
}
trap restore EXIT
grep -q data_ptrs_shiftable build.ninja || sed -i 's#-T \(\S*\)/undefined_funcs.txt -Map#-T \1/undefined_funcs.txt -T \1/data_ptrs_shiftable.txt -Map#' build.ninja
sed -i 's#undefined_syms_auto.txt#undefined_syms_shiftable.txt#; s#undefined_funcs.txt#empty_syms.txt#' build.ninja
VERSION="TMB-Reloaded $(git rev-parse --short HEAD)$(git diff --quiet HEAD -- src mods tools || echo -dirty) $(date +%Y-%m-%d)"
if [ -n "$TMBR_TEXT_PAD" ]; then   # test: grow .text by N bytes at its end (moves all data/bss by N)
  sed -i "s#^\(\s*\)build/asm/newlib/libc/machine/r5900/memcmp.s.o(.text);#&\n        . = . + $TMBR_TEXT_PAD;#" $LD
  touch $LD; echo "text pad $TMBR_TEXT_PAD"
fi
if [ "$MODS" = 1 ]; then
  # bisect knobs (the private build copy is re-synced every time, so editing its mods/ is fine)
  [ -n "$TMBR_STACK" ] && sed -i "s/^.set TMBR_STACK_SIZE, .*/.set TMBR_STACK_SIZE, $TMBR_STACK/" mods/memory.s && echo "stack $TMBR_STACK"
  [ "$TMBR_NO_PEDS" = 1 ] && sed -i '/^Pedestrians Online/d' mods/tmbr_sections.txt && echo "no peds"
  [ "$TMBR_NO_POSTLINK" = 1 ] && : > mods/postlink.txt && echo "no postlink"
  python3 tools/mods/apply_mods.py apply
  mkdir -p build/mods; TXT=""; BSS=""
  printf '.section .text, "ax"\n.align 3\n.globl tmbr_version\ntmbr_version:\n    .asciz "%s"\n.align 3\n' "$VERSION" > build/mods/version.s
  for s in mods/*.s build/mods/version.s; do
    o=build/mods/$(basename $s).o
    mips-linux-gnu-as -Iinclude -EL -march=5900 -G0 -no-pad-sections -mabi=eabi $s -o $o
    TXT="$TXT        $o(.text);\n"; BSS="$BSS        $o(.bss);\n"
  done
  for c in mods/*.c; do          # C mods: the game's own compiler (SN ee-gcc 2.95), same flags as the build
    [ -e "$c" ] || continue
    o=build/mods/$(basename $c).o
    tools/sn_cc.sh -c -Iinclude -isystem include/gcc -isystem include/gcc/gcc-lib -isystem include/sdk \
      -isystem include/sdk/common -isystem include/sdk/ee -O2 -G0 -fno-common $( [ "${TMBR_TEST:-0}" = 1 ] && echo -DTMBR_FREECAM_ANYTIME ) \
      $c -o $o
    TXT="$TXT        $o(.text);\n        $o(.rodata);\n        $o(.lit4);\n        $o(.lit8);\n        $o(.data);\n        $o(.sdata);\n"
    BSS="$BSS        $o(.bss);\n        $o(.sbss);\n"
  done
  # Mods go in their own section AFTER the game's .bss: the game's code and data keep their original
  # addresses. (Putting them after .text moved all data, and something in the shiftable build still points
  # at old data addresses: the map selector crashed even with no mods, just from data moving.)
  # main_VRAM_END (= start of the heap, crt0) comes after them.
  # Gap of >= 0x40 bytes first: crt0's .bss clear writes 16-byte blocks and overshoots the .bss end by up to
  # 16 bytes (it zeroed the first instructions of tmbr_InitPOV -> crash when a match started).
  sed -i "s#^    __romPos += SIZEOF(.main);#    .tmbr_mods ALIGN(. + 0x40, 0x80) : AT(ADDR(.tmbr_mods))\n    {\n        tmbr_MODS_START = .;\n$TXT$BSS        . = ALIGN(0x80);\n        tmbr_MODS_END = .;\n    }\n&#" $LD
  grep -q tmbr_MODS_START $LD || { echo "mods section not inserted"; exit 1; }
  # After every game .text object, pad so the next object keeps its original address mod 128. Any growth
  # from mod patches (asm or C) is then rounded up to 128 bytes: some code is followed by data read with
  # 128-bit lq (e.g. libmpeg's clamp mask), and a non-multiple-of-128 shift breaks it (green bars).
  python3 - "$LD" <<'EOF'
import re, sys
ld = sys.argv[1]; ends = {}
for l in open("build/SCUS_971.96.map"):                     # map of the matching build
    m = re.match(r"\s*\.text\s+0x([0-9a-f]+)\s+0x([0-9a-f]+)\s+(build/\S+\.o)\s*$", l)
    if m: ends[m.group(3)] = int(m.group(1), 16) + int(m.group(2), 16)
out, n = [], 0
for l in open(ld).read().split("\n"):
    out.append(l)
    m = re.match(r"\s*(build/\S+\.o)\(\.text\);\s*$", l)
    if m and m.group(1) in ends:
        out.append(f"        . = . + ((0x{ends[m.group(1)]:X} - .) & 0x7F);"); n += 1
open(ld, "w").write("\n".join(out))
print(f"128-byte phase kept after {n} .text objects")
EOF
  touch $LD                     # ninja doesn't know about the mod objects: make the link step re-run
fi
ninja build/SCUS_971.96.elf
mips-linux-gnu-nm -n -S build/SCUS_971.96.elf > build/shift_syms.txt
python3 - "$MODS" <<'EOF'
import struct, sys, re
d = bytearray(open('build/SCUS_971.96.elf', 'rb').read())
struct.pack_into('<I', d, 0x18, 0x100008)
ph, = struct.unpack_from('<I', d, 0x1C); phsz, phn = struct.unpack_from('<HH', d, 0x2A)
segs = []
for i in range(phn):                                   # every PT_LOAD: paddr = vaddr (PCSX2)
    o = ph + i * phsz
    t, off, va, pa, fsz = struct.unpack_from('<IIIII', d, o)
    if t == 1: struct.pack_into('<I', d, o + 12, va); segs.append((va, off, fsz))
def fo(va):
    for sva, off, fsz in segs:
        if sva <= va < sva + fsz: return off + va - sva
    raise SystemExit(f"{va:08X} not in a loaded segment")
if sys.argv[1] == "1":                                 # post-link word patches (mods/postlink.txt)
    S = {}
    for l in open("build/shift_syms.txt"):
        f = l.split()
        if len(f) >= 3: S[f[-1]] = int(f[0], 16)
    for l in open("mods/postlink.txt"):
        l = l.split("#")[0].split()
        if not l: continue
        a, exp = int(l[0], 16), int(l[1], 16)
        cur, = struct.unpack_from('<I', d, fo(a))
        assert cur == exp, f"postlink {a:08X}: expected {exp:08X}, found {cur:08X}"
        if l[2] in ("j", "jal"): new = ((2 if l[2] == "j" else 3) << 26) | ((S[l[3]] >> 2) & 0x3FFFFFF)
        else: new = int(l[2], 16)
        struct.pack_into('<I', d, fo(a), new)
        print(f"postlink {a:08X}: {cur:08X} -> {new:08X}")
open('build/SCUS_971.96.shift.elf', 'wb').write(d)
print(f"wrote build/SCUS_971.96.shift.elf ({len(segs)} load segments)")
EOF
if [ "$MODS" = 1 ]; then
  cp build/SCUS_971.96.shift.elf build/stage_A_nopnach.elf           # for bisecting: mods only
  python3 tools/mods/apply_pnach.py build/SCUS_971.96.shift.elf build/base_syms.txt build/shift_syms.txt \
      mods/community.pnach mods/pnach_sections.txt
  cp build/SCUS_971.96.shift.elf build/stage_B_community.elf         # mods + community pnach
  python3 tools/mods/apply_pnach.py build/SCUS_971.96.shift.elf build/base_syms.txt build/shift_syms.txt \
      mods/tmbr.pnach mods/tmbr_sections.txt
  mips-linux-gnu-strip -o build/TMBR.elf build/SCUS_971.96.shift.elf      # release ELF: no symbol table
  echo "$VERSION" > build/TMBR.version
  echo "release: build/TMBR.elf  ($VERSION)"
fi
restore; trap - EXIT
rm -f build/SCUS_971.96.rom; ninja > /dev/null
cmp -s build/SCUS_971.96.rom disks/SCUS_971.96.rom && echo "normal build restored: byte-identical"
