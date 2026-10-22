# ruff: noqa
# verify_pnach.py BASE_ELF SHIFT_ELF(before pnach) BASE_SYMS SHIFT_SYMS PNACH SECTIONS
# For each patched address: the original word at that address in the base ELF must equal the word at the
# translated address in the shifted ELF (before patching). Mismatch = the patch would land on other code/data.
import sys, re, struct, bisect, importlib.util

base_elf, shift_elf, bs, ss, pnach, sections = sys.argv[1:7]


def img(p):
    d = open(p, "rb").read()
    (ph,) = struct.unpack_from("<I", d, 0x1C)
    off, va, _, fsz = struct.unpack_from("<IIII", d, ph + 4)
    return (
        lambda a: struct.unpack_from("<I", d, off + a - va)[0]
        if 0 <= a - va < fsz - 3
        else None
    )


B_, S_ = img(base_elf), img(shift_elf)


def load(p):
    s = []
    for l in open(p):
        f = l.split()
        if len(f) == 4:
            a, z, t, n = f
            z = int(z, 16)
        elif len(f) == 3:
            a, t, n = f
            z = 0
        else:
            continue
        if t in "Aa" or n.startswith("."):
            continue
        s.append((int(a, 16), z, n))
    s.sort()
    return s


B = load(bs)
S = {n: a for a, z, n in load(ss)}
BA = [a for a, z, n in B]


def tr(addr):
    i = bisect.bisect_right(BA, addr) - 1
    for j in range(i, max(i - 8, -1), -1):
        a, z, n = B[j]
        if a <= addr < a + max(z, 1) and n in S:
            return S[n] + (addr - a), n
    for j in range(i, max(i - 64, -1), -1):
        a, z, n = B[j]
        if n in S:
            return S[n] + (addr - a), n + "?"


want = [l.strip() for l in open(sections) if l.strip() and not l.startswith("#")]
cur = None
bad = 0
for l in open(pnach, encoding="utf-8", errors="replace"):
    l = l.split("//")[0].strip()
    m = re.match(r"\[(.*)\]", l)
    if m:
        cur = m.group(1).strip()
        continue
    m = re.match(r"patch=(\d),EE,([0-9A-Fa-f]{8}),(extended|word),([0-9A-Fa-f]+)", l)
    if not (m and cur in want):
        continue
    a = (
        int(m.group(2), 16) & 0x0FFFFFFF
        if m.group(3) == "word"
        else int(m.group(2)[1:], 16)
    )
    a &= ~3
    t, n = tr(a)
    bw, sw = B_(a), S_(t)
    ok = bw == sw
    if not ok:
        bad += 1
    print(
        f"{'OK ' if ok else 'BAD'} {cur[:28]:28} {a:08X} -> {t:08X} [{n}] base {bw:08X} shift {sw:08X}"
    )
print("mismatches:", bad)
