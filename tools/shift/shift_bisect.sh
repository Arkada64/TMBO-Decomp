#!/bin/bash
# Bisect the shifted-build crash: insert 64 bytes of padding at different points of the linker script.
#   S1 = start of .text (everything moves)   S2 = end of .text (data/rodata/sdata/bss move)
#   S3 = before .sdata (sdata/bss move)        S4 = start of .bss (only bss moves)
cd ~/tmbo_decomp && source .venv/bin/activate
OUT="/mnt/d/TMB Decomp/test"; P="/mnt/d/TMBR/emulator/PCSX2/patches"
LD=config/US/SCUS_971.96.ld
cp $LD /tmp/ld.bak; cp build.ninja /tmp/ninja.bak; cp asm/gcc/_crt0.s /tmp/crt0.bak; rm -f /tmp/bss.bak
rm -f build/SCUS_971.96.rom; ninja > /dev/null 2>&1; cmp -s build/SCUS_971.96.rom disks/SCUS_971.96.rom || { echo "base not matching"; exit 1; }
mips-linux-gnu-nm -n build/SCUS_971.96.elf > logs/bis_nm_base.txt
W="/mnt/d/TMB Decomp"; cp "$W/symbase.py" "$W/symbolize_data.py" "$W/make_shiftable.py" tools/
python3 tools/symbolize_data.py build/SCUS_971.96.elf
cp "$W/fix_rawlo.py" tools/; python3 tools/fix_rawlo.py build/SCUS_971.96.elf
rm -f build/SCUS_971.96.rom; ninja > /dev/null 2>&1; cmp -s build/SCUS_971.96.rom disks/SCUS_971.96.rom || { echo "base broken after symbolize"; exit 1; }
cp build/SCUS_971.96.elf /tmp/base.elf
python3 tools/make_shiftable.py /tmp/base.elf | head -40
touch config/US/empty_syms.txt
sed -i 's#undefined_syms_auto.txt#undefined_syms_shiftable.txt#; s#undefined_funcs.txt#empty_syms.txt#' build.ninja
for V in ${VARIANTS:-S1 S2 S3 S4}; do
  cp /tmp/ld.bak $LD
  case $V in
    S0) ;;
    S5) sed -i 's#main_SBSS_START = .;#. += 0x1000;\n        main_SBSS_START = .;#' $LD ;;
    S6) sed -i '0,/build\/asm\/gcc\/_crt0.s.o(.text);/s//&\n        . += 0x1000;/' $LD ;;
    S1) sed -i '0,/build\/asm\/gcc\/_crt0.s.o(.text);/s//&\n        . += 0x40;/' $LD ;;
    S2) sed -i 's#build/asm/newlib/libc/machine/r5900/memcmp.s.o(.text);#&\n        . += 0x40;#' $LD ;;
    S3) sed -i 's#main_SDATA_START = .;#. += 0x40;\n        main_SDATA_START = .;#' $LD ;;
    S4) sed -i 's#main_SBSS_START = .;#. += 0x40;\n        main_SBSS_START = .;#' $LD ;;
  esac
  cp /tmp/bss.bak asm/data/bss1.bss.s 2>/dev/null || cp asm/data/bss1.bss.s /tmp/bss.bak
  case $V in
    C*) # C<ADDR>: 0x80 bytes of padding in .bss before the first object at/after ADDR
      python3 - "${V#C}" <<'EOF'
import re, sys
cut = int(sys.argv[1], 16); p = 'asm/data/bss1.bss.s'; L = open(p).read().split('\n')
for i, l in enumerate(L):
    m = re.match(r'\s*dlabel D_([0-9A-F]{8})\b', l)
    if m and int(m.group(1), 16) >= cut and int(m.group(1), 16) % 0x80 == 0:
        j = i - 1
        while j > 0 and L[j].strip().startswith(('nonmatching', '.align', '')) and not L[j].strip().startswith(('enddlabel', '.space')): j -= 1
        L.insert(i, '.space 0x80'); print('padding before', m.group(0).strip()); break
open(p, 'w').write('\n'.join(L))
EOF
      ;;
  esac
  case $V in
    B2) sed -i 's#build/asm/newlib/libc/machine/r5900/memcmp.s.o(.text);#&\n        . += 0x80;#' $LD ;;
    B3) sed -i 's#main_SDATA_START = .;#. += 0x80;\n        main_SDATA_START = .;#' $LD ;;
    B6) sed -i 's#main_SDATA_START = .;#. += 0x1000;\n        main_SDATA_START = .;#' $LD ;;
    B7) sed -i 's#main_SDATA_START = .;#. += 0x10000;\n        main_SDATA_START = .;#' $LD ;;
    B4) sed -i 's#main_SBSS_START = .;#. += 0x80;\n        main_SBSS_START = .;#' $LD ;;
    B5) sed -i 's#main_BSS_START = .;#. += 0x80;\n        main_BSS_START = .;#' $LD ;;
    T*) awk -v N="${V#T}" '{print} /\(\.text\);/ {k++; if (k==N) print "        . += 0x80;"}' $LD > /tmp/ld.t && cp /tmp/ld.t $LD
        grep -B1 -m1 '^        \. += 0x80;' $LD | head -1 ;;
    B8) sed -i 's#main_BSS_START = .;#. += 0x100;\n        main_BSS_START = .;#' $LD ;;
    B9) sed -i 's#main_BSS_START = .;#. += 0x400;\n        main_BSS_START = .;#' $LD ;;
  esac
  # standard MIPS gp anchor (the original is exactly .sdata + 0x7FF0); crt0 loads it via _gp
  sed -i 's#_gp = 0x5015F0;#_gp = main_SDATA_START + 0x7FF0;#' $LD
  sed -i 's#%hi(D_005015F0)#%hi(_gp)#; s#%lo(D_005015F0)#%lo(_gp)#' asm/gcc/_crt0.s
  sed -i 's#^\(\s*\)main_DATA_START = \.;#\1. = ALIGN(., 16);\n\1main_DATA_START = .;#;
          s#^\(\s*\)build/asm/data/1B8A00.data.s.o(.data);#\1. = ALIGN(., 128);\n&#;
          s#^\(\s*\)main_RODATA_START = \.;#\1. = ALIGN(., 16);\n\1main_RODATA_START = .;#;
          s#^\(\s*\)main_SDATA_START = \.;#\1. = ALIGN(., 8);\n\1main_SDATA_START = .;#;
          s#^\(\s*\)main_SBSS_START = \.;#\1. = ALIGN(., 8);\n\1main_SBSS_START = .;#;
          s#^\(\s*\)main_BSS_START = \.;#\1. = ALIGN(., 128);\n\1main_BSS_START = .;#' $LD
  ninja build/SCUS_971.96.elf > logs/bis_$V.log 2>&1 || { echo "$V link failed"; grep -E 'error|undefined' logs/bis_$V.log | head -3; continue; }
  mips-linux-gnu-nm -n build/SCUS_971.96.elf > logs/bis_nm_$V.txt
  python3 - "$V" "$OUT" "$P" <<'EOF'
import struct, sys, re, bisect, collections
V, OUT, P = sys.argv[1:]
d = bytearray(open('build/SCUS_971.96.elf', 'rb').read())
struct.pack_into('<I', d, 0x18, 0x100008)
ph = struct.unpack_from('<I', d, 0x1C)[0]; struct.pack_into('<I', d, ph + 12, struct.unpack_from('<I', d, ph + 8)[0])
open(f'{OUT}/{V}.ELF', 'wb').write(d)
dd = bytes(d) + b"\0" * (-len(d) % 4); c = 0
for (w,) in struct.iter_unpack('<I', dd): c ^= w
def load(p):
    r = {}
    for l in open(p):
        s = l.split()
        if len(s) == 3 and s[1] not in 'Aa': r[s[2]] = int(s[0], 16)
    return r
a, b = load('logs/bis_nm_base.txt'), load(f'logs/bis_nm_{V}.txt')
moves = collections.Counter(b[n] - v for n, v in a.items() if n in b and 0x100000 <= v < 0x625694)
order = sorted((v, n) for n, v in a.items() if n in b); addrs = [x for x, _ in order]
def tr(x):
    i = bisect.bisect_right(addrs, x) - 1; return b[order[i][1]] + (x - order[i][0])
import os
src = open(f'{P}/SCUS-97196_C54E5CF2.pnach').read() if os.path.exists(f'{P}/SCUS-97196_C54E5CF2.pnach') else ''
want = ("Force Revival Server DNS", "Bugfixes & Improvements", "Skip Intros")
out, keep = [f"gametitle=TMB Online bisect build {V} [{c:08X}]", ""], False
for l in src.splitlines():
    m = re.match(r"\[(.*)\]", l.strip())
    if m: keep = m.group(1).strip() in want; out += ["", l] if keep else []; continue
    if keep:
        mm = re.match(r"(patch=\d,EE,)([0-9A-Fa-f])([0-9A-Fa-f]{7})(,.*)", l)
        if mm: l = f"{mm.group(1)}{mm.group(2)}{tr(int(mm.group(3), 16)):07X}{mm.group(4)}"
        out.append(l)
if src and os.path.isdir(P): open(f'{P}/{c:08X}.pnach', 'w').write("\n".join(out) + "\n")
open(f'{OUT}/Run {V}.bat', 'w').write('@echo off\r\nset P=D:\\TMBR\\emulator\\PCSX2\r\n'
    f'"%P%\\pcsx2-qt.exe" -elf "%~dp0{V}.ELF" -- "%P%\\_games\\Twisted Metal - Black Online (USA).chd"\r\n')
print(f"{V}: CRC {c:08X}, symbol moves {dict(moves.most_common(3))}")
EOF
done
cp /tmp/ld.bak $LD; cp /tmp/ninja.bak build.ninja; cp /tmp/bss.bak asm/data/bss1.bss.s 2>/dev/null; rm -f /tmp/bss.bak; cp /tmp/crt0.bak asm/gcc/_crt0.s 2>/dev/null
rm -f build/SCUS_971.96.rom; ninja > /dev/null 2>&1 && cmp -s build/SCUS_971.96.rom disks/SCUS_971.96.rom && echo "restored: byte-identical"
