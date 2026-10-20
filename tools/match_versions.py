#!/usr/bin/env python3
"""
Match functions between Twisted Metal: Black retail (SCUS_971.01) and Online (SCUS_971.96).

Inputs:
  retail ELF + retail symbol_addrs.txt (names/sizes) + retail splat yaml (file boundaries)
  online ELF + online split asm (function starts/sizes found by spimdisasm)
Outputs (in OUTDIR):
  mapping.csv          every online function, its retail match (if any), method, score
  retail_files.csv     per retail source file: functions total / found in Online
  online_only.txt      online functions with no retail counterpart (network code etc.)
  symbol_addrs_ported.txt   names to drop into the Online config
"""

import re
import struct
import sys
import csv
import difflib
import collections
from pathlib import Path

HOME = Path.home()
RETAIL_ELF = HOME / "tmb_decomp/disks/SCUS_971.01"
RETAIL_SYMS = HOME / "tmb_decomp/config/US/symbol_addrs.txt"
RETAIL_YAML = HOME / "tmb_decomp/config/US/SCUS_971.01.yaml"
ONLINE_ELF = HOME / "tmbo_decomp/disks/SCUS_971.96"
ONLINE_ASM = HOME / "tmbo_decomp/asm"
OUTDIR = HOME / "tmbo_decomp/reference/match"


# ---------------------------------------------------------------- ELF helpers
def load_text(path):
    d = path.read_bytes()
    (shoff,) = struct.unpack_from("<I", d, 0x20)
    shnum, shstrndx = struct.unpack_from("<HH", d, 0x30)
    secs = [struct.unpack_from("<IIIIIIIIII", d, shoff + i * 40) for i in range(shnum)]
    strtab = secs[shstrndx]
    name = lambda off: d[strtab[4] + off : d.index(b"\0", strtab[4] + off)].decode()
    for s in secs:
        if name(s[0]) == ".text":
            return s[3], d[s[4] : s[4] + s[5]]  # vaddr, bytes
    raise SystemExit(f"no .text in {path}")


class Code:
    def __init__(self, path):
        self.base, self.data = load_text(path)
        self.end = self.base + len(self.data)

    def words(self, addr, size):
        o = addr - self.base
        return list(struct.unpack_from(f"<{size // 4}I", self.data, o))


# ---------------------------------------------------------------- function lists
def retail_functions(code):
    """name/addr/size from retail symbol_addrs.txt; missing sizes run to the next func."""
    funcs = {}
    pat = re.compile(r"^\s*(\S+)\s*=\s*0x([0-9A-Fa-f]+);\s*//(.*)$")
    for line in RETAIL_SYMS.read_text().splitlines():
        m = pat.match(line)
        if not m or "type:func" not in m.group(3):
            continue
        addr = int(m.group(2), 16)
        if not (code.base <= addr < code.end):
            continue
        sz = re.search(r"size:0x([0-9A-Fa-f]+)", m.group(3))
        funcs[addr] = [m.group(1), int(sz.group(1), 16) if sz else None]
    addrs = sorted(funcs)
    for i, a in enumerate(addrs):
        if funcs[a][1] is None:
            funcs[a][1] = (addrs[i + 1] if i + 1 < len(addrs) else code.end) - a
    return {a: (n, s) for a, (n, s) in funcs.items() if s and s % 4 == 0}


def retail_files():
    """[(vram_start, filename)] for .text subsegments of the retail yaml."""
    out = []
    for line in RETAIL_YAML.read_text().splitlines():
        m = re.match(
            r"\s*- \[0x([0-9A-Fa-f]+),\s*(asm|c|cpp|hasm),\s*([^\]\s]+)\]", line
        )
        if m:
            out.append((int(m.group(1), 16) + 0x100000, m.group(3)))
    return sorted(out)


def online_functions():
    """Function starts/sizes from spimdisasm output (nonmatching NAME, 0xSIZE + first insn comment)."""
    funcs = {}
    for f in sorted(ONLINE_ASM.rglob("*.s")):
        lines = f.read_text().splitlines()
        for i, line in enumerate(lines):
            m = re.match(r"\s*nonmatching\s+(\S+),\s*0x([0-9A-Fa-f]+)", line)
            if not m:
                continue
            for nxt in lines[i + 1 : i + 6]:
                a = re.match(r"\s*/\*\s*[0-9A-F]+\s+([0-9A-F]{8})\s", nxt)
                if a:
                    funcs[int(a.group(1), 16)] = (m.group(1), int(m.group(2), 16))
                    break
    return funcs


# ---------------------------------------------------------------- fingerprints
IMM_OPS = {
    0x08,
    0x09,
    0x0A,
    0x0B,
    0x0C,
    0x0D,
    0x0E,
    0x18,
    0x19,
    0x1A,
    0x1B,
    0x1E,
    0x1F,
    *range(0x20, 0x28),
    *range(0x28, 0x30),
    0x31,
    0x35,
    0x36,
    0x37,
    0x39,
    0x3D,
    0x3E,
    0x3F,
}
GP, SP = 28, 29


def mask(w, strict):
    """Blank out fields that change when code/data moves between builds."""
    op = w >> 26
    if op in (2, 3):  # j / jal: target address
        return op << 26
    if op == 0x0F:  # lui: upper address half
        return w & 0xFFFF0000
    if op in IMM_OPS:
        rs = (w >> 21) & 31
        if rs == GP or not strict or op in (0x09, 0x19, 0x0D) and rs != SP:
            return w & 0xFFFF0000  # gp-relative / address low half / loose mode
        if rs != SP and op >= 0x1E:  # struct offsets: keep in strict, they rarely move
            return w
    return w


def mnemonic(w):
    op = w >> 26
    return (op, w & 0x3F) if op == 0 else (op, (w >> 16) & 31 if op == 1 else 0)


class Fn:
    __slots__ = ("addr", "name", "size", "words", "strict", "loose", "mn", "calls")

    def __init__(self, code, addr, name, size):
        self.addr, self.name, self.size = addr, name, size
        self.words = code.words(addr, size)
        self.strict = hash(tuple(mask(w, True) for w in self.words))
        self.loose = hash(tuple(mask(w, False) for w in self.words))
        self.mn = [mnemonic(w) for w in self.words]
        base_hi = addr & 0xF0000000
        self.calls = [
            (i, base_hi | ((w & 0x03FFFFFF) << 2))
            for i, w in enumerate(self.words)
            if w >> 26 == 3
        ]


# ---------------------------------------------------------------- matching
def unique_hash_pass(on, rt, key, match, method):
    on_idx, rt_idx = collections.defaultdict(list), collections.defaultdict(list)
    for f in on.values():
        if f.addr not in match:
            on_idx[getattr(f, key)].append(f)
    used = {r for r, _, _ in match.values()}
    for f in rt.values():
        if f.addr not in used:
            rt_idx[getattr(f, key)].append(f)
    n = 0
    for h, ofs in on_idx.items():
        rfs = rt_idx.get(h, [])
        if len(ofs) == 1 and len(rfs) == 1 and ofs[0].size >= 16:
            match[ofs[0].addr] = (rfs[0].addr, method, 1.0)
            n += 1
    return n


def callgraph_pass(on, rt, match):
    """Same-shaped matched functions call their callees in the same order -> pair the callees."""
    n, changed = 0, True
    while changed:
        changed = False
        used = {r for r, _, _ in match.values()}
        for oa, (ra, method, _) in list(match.items()):
            o, r = on[oa], rt[ra]
            if len(o.calls) != len(r.calls):
                continue
            for (_, oc), (_, rc) in zip(o.calls, r.calls):
                if oc in on and rc in rt and oc not in match and rc not in used:
                    if abs(on[oc].size - rt[rc].size) <= max(16, rt[rc].size // 4):
                        match[oc] = (rc, "callgraph", 1.0)
                        used.add(rc)
                        n += 1
                        changed = True
    return n


def fuzzy_pass(on, rt, match, threshold=0.80):
    """Between consecutive matched anchors, pair leftovers by instruction-sequence similarity."""
    anchors = sorted((oa, ra) for oa, (ra, _, _) in match.items())
    on_sorted, rt_sorted = sorted(on), sorted(rt)
    used = {r for r, _, _ in match.values()}
    import bisect

    n = 0
    for (o0, r0), (o1, r1) in zip([(0, 0)] + anchors, anchors + [(1 << 32, 1 << 32)]):
        if r1 < r0:  # order inversion: skip window
            continue
        olist = [
            a
            for a in on_sorted[
                bisect.bisect_right(on_sorted, o0) : bisect.bisect_left(on_sorted, o1)
            ]
            if a not in match
        ]
        rlist = [
            a
            for a in rt_sorted[
                bisect.bisect_right(rt_sorted, r0) : bisect.bisect_left(rt_sorted, r1)
            ]
            if a not in used
        ]
        if not olist or not rlist or len(olist) * len(rlist) > 40000:
            continue
        for oa in olist:
            o, best = on[oa], (0, None)
            for ra in rlist:
                if ra in used:
                    continue
                r = rt[ra]
                if not (0.6 < o.size / r.size < 1.67):
                    continue
                sm = difflib.SequenceMatcher(None, o.mn, r.mn, autojunk=False)
                if sm.quick_ratio() < threshold:
                    continue
                s = sm.ratio()
                if s > best[0]:
                    best = (s, ra)
            if best[0] >= threshold:
                match[oa] = (best[1], "fuzzy", round(best[0], 3))
                used.add(best[1])
                n += 1
    return n


def global_fuzzy_pass(on, rt, match, min_size=64, accept=0.85, lo=0.60, margin=0.08):
    """Anywhere-in-binary search for edited functions: histogram prefilter, then sequence ratio."""
    import numpy as np

    used = {r for r, _, _ in match.values()}
    ol = sorted(
        (f for a, f in on.items() if a not in match and f.size >= min_size),
        key=lambda f: -f.size,
    )
    rl = [f for a, f in rt.items() if a not in used and f.size >= min_size // 2]
    if not ol or not rl:
        return 0
    vocab = {m: i for i, m in enumerate({m for f in ol + rl for m in f.mn})}

    def vec(fs):
        M = np.zeros((len(fs), len(vocab)), dtype=np.float32)
        for i, f in enumerate(fs):
            for m in f.mn:
                M[i, vocab[m]] += 1
        return M / np.maximum(np.linalg.norm(M, axis=1, keepdims=True), 1e-9)

    O, R = vec(ol), vec(rl)
    rsize = np.array([f.size for f in rl], dtype=np.float32)
    taken, n = set(), 0
    for i, o in enumerate(ol):
        sim = R @ O[i]
        ratio = rsize / o.size
        sim[(ratio < 0.5) | (ratio > 2.0)] = -1
        cands = [
            j for j in np.argsort(-sim)[:6] if sim[j] > 0.9 and rl[j].addr not in taken
        ]
        scored = sorted(
            (
                (
                    difflib.SequenceMatcher(
                        None, o.mn, rl[j].mn, autojunk=False
                    ).ratio(),
                    j,
                )
                for j in cands
            ),
            reverse=True,
        )
        if not scored:
            continue
        best = scored[0][0]
        second = scored[1][0] if len(scored) > 1 else 0
        if best >= accept or (best >= lo and best - second >= margin):
            r = rl[scored[0][1]]
            match[o.addr] = (r.addr, "global_fuzzy", round(best, 3))
            taken.add(r.addr)
            n += 1
    return n


def callgraph_align_pass(on, rt, match):
    """Like callgraph_pass, but aligns call lists so inserted/removed calls don't break pairing."""
    n, changed = 0, True
    while changed:
        changed = False
        used = {r for r, _, _ in match.values()}
        for oa, (ra, _, _) in list(match.items()):
            o, r = on[oa], rt[ra]
            if not o.calls or not r.calls:
                continue
            key_o = [
                ("M", match[c][0])
                if c in match
                else ("S", on[c].size // 32 if c in on else -1)
                for _, c in o.calls
            ]
            key_r = [
                ("M", c) if c in used else ("S", rt[c].size // 32 if c in rt else -1)
                for _, c in r.calls
            ]
            sm = difflib.SequenceMatcher(None, key_o, key_r, autojunk=False)
            for tag, i1, i2, j1, j2 in sm.get_opcodes():
                # 'equal' runs pair directly; same-length 'replace' runs pair if callee sizes are close
                if tag == "equal" or (tag == "replace" and i2 - i1 == j2 - j1):
                    for k in range(i2 - i1):
                        oc, rc = o.calls[i1 + k][1], r.calls[j1 + k][1]
                        if key_o[i1 + k][0] != "S" or key_r[j1 + k][0] != "S":
                            continue
                        if oc not in on or rc not in rt or oc in match or rc in used:
                            continue
                        if tag == "replace" and not (
                            0.75 <= on[oc].size / rt[rc].size <= 1.33
                        ):
                            continue
                        match[oc] = (rc, "callgraph_align", 1.0)
                        used.add(rc)
                        n += 1
                        changed = True
    return n


WEIGHT = {
    "exact": 5.0,
    "masked": 4.0,
    "strings": 4.5,
    "callgraph": 2.5,
    "callgraph_align": 2.0,
    "fuzzy": 1.0,
    "global_fuzzy": 1.0,
    "order": 1.5,
}


def string_pass(on, rt, match, ostr, rstr):
    """Functions referencing an identical, unique set of strings are the same function."""

    def idx(fs, strs, skip):
        d = collections.defaultdict(list)
        for a in fs:
            s = strs.get(a)
            if a not in skip and s and sum(map(len, s)) >= 8:
                d[frozenset(s)].append(a)
        return d

    used = {r for r, _, _ in match.values()}
    oi, ri = idx(on, ostr, match), idx(rt, rstr, used)
    n = 0
    for k, oas in oi.items():
        ras = ri.get(k, [])
        if len(oas) == 1 and len(ras) == 1:
            match[oas[0]] = (ras[0], "strings", 1.0)
            n += 1
    return n


def string_veto_pass(match, ostr, rstr):
    """Drop weaker matches whose referenced strings clearly disagree."""
    from strrefs import strings_agree

    n = 0
    for oa, (ra, m, s) in list(match.items()):
        if m in ("exact", "masked", "strings"):
            continue
        so, sr = ostr.get(oa), rstr.get(ra)
        if so and sr and not strings_agree(so, sr):
            del match[oa]
            n += 1
    return n


def order_fix_pass(on, rt, match, files):
    """
    Per retail source file, functions keep their relative order in Online.
    Keep the max-weight increasing chain of matches, drop the rest, then re-pair
    leftovers positionally between surviving anchors.
    Returns (dropped, repaired).
    """
    import bisect

    byfile = collections.defaultdict(list)
    for oa, (ra, m, s) in match.items():
        byfile[file_of(ra, files)].append((ra, oa, m, s))
    dropped = 0
    for f, lst in byfile.items():
        lst.sort()
        w = [
            WEIGHT[m] * (s if m in ("fuzzy", "global_fuzzy") else 1.0)
            for _, _, m, s in lst
        ]
        best, prev = w[:], [-1] * len(lst)  # weighted LIS on online address
        for i in range(len(lst)):
            for j in range(i):
                if lst[j][1] < lst[i][1] and best[j] + w[i] > best[i]:
                    best[i], prev[i] = best[j] + w[i], j
        keep, i = set(), max(range(len(lst)), key=lambda k: best[k]) if lst else -1
        while i != -1:
            keep.add(i)
            i = prev[i]
        for k, (ra, oa, m, s) in enumerate(lst):
            if k not in keep:
                del match[oa]
                dropped += 1

    # positional repair inside each file's anchor gaps
    used = {r for r, _, _ in match.values()}
    on_sorted = sorted(on)
    rt_by_file = collections.defaultdict(list)
    for ra in sorted(rt):
        rt_by_file[file_of(ra, files)].append(ra)
    repaired = 0
    for f, ras in rt_by_file.items():
        inv = {r: o for o, (r, _, _) in match.items()}
        pts = [(ra, inv[ra]) for ra in ras if ra in inv]
        if not pts:
            continue
        bounds = [(None, None)] + pts + [(None, None)]
        for (r0, o0), (r1, o1) in zip(bounds, bounds[1:]):
            rgap = [
                ra
                for ra in ras
                if ra not in used
                and (r0 is None or ra > r0)
                and (r1 is None or ra < r1)
            ]
            if not rgap:
                continue
            lo = o0 if o0 is not None else (o1 - 0x4000 if o1 is not None else None)
            hi = o1 if o1 is not None else (o0 + 0x4000 if o0 is not None else None)
            if lo is None or hi is None:
                continue
            ogap = [
                a
                for a in on_sorted[
                    bisect.bisect_right(on_sorted, lo) : bisect.bisect_left(
                        on_sorted, hi
                    )
                ]
                if a not in match
            ]
            # monotone greedy: each retail func takes the first similar online func after the previous pick
            start = 0
            for ra in rgap:
                r = rt[ra]
                for k in range(start, len(ogap)):
                    o = on[ogap[k]]
                    if not (0.5 < o.size / r.size < 2.0):
                        continue
                    s = difflib.SequenceMatcher(
                        None, o.mn, r.mn, autojunk=False
                    ).ratio()
                    if s >= 0.6:
                        match[o.addr] = (ra, "order", round(s, 3))
                        used.add(ra)
                        repaired += 1
                        start = k + 1
                        break
    return dropped, repaired


# ---------------------------------------------------------------- reports
def file_of(addr, files):
    name = "?"
    for start, fn in files:
        if start > addr:
            break
        name = fn
    return name


def main():
    rc, oc = Code(RETAIL_ELF), Code(ONLINE_ELF)
    rt = {a: Fn(rc, a, n, s) for a, (n, s) in retail_functions(rc).items()}
    on = {
        a: Fn(oc, a, n, s)
        for a, (n, s) in online_functions().items()
        if a + s <= oc.end
    }
    files = retail_files()
    print(f"retail functions: {len(rt)}   online functions: {len(on)}")

    sys.path.insert(0, str(Path(__file__).parent))
    from strrefs import Img

    ri, oi = Img(RETAIL_ELF), Img(ONLINE_ELF)
    rstr = {a: s for a, f in rt.items() if (s := ri.strings(a, f.size))}
    ostr = {a: s for a, f in on.items() if (s := oi.strings(a, f.size))}

    match = {}
    steps = [
        ("strings", lambda: string_pass(on, rt, match, ostr, rstr)),
        ("strict hash", lambda: unique_hash_pass(on, rt, "strict", match, "exact")),
        ("loose hash", lambda: unique_hash_pass(on, rt, "loose", match, "masked")),
        ("call graph", lambda: callgraph_pass(on, rt, match)),
        ("fuzzy", lambda: fuzzy_pass(on, rt, match)),
        ("call graph", lambda: callgraph_pass(on, rt, match)),
        ("fuzzy", lambda: fuzzy_pass(on, rt, match)),
        ("call graph", lambda: callgraph_pass(on, rt, match)),
        ("global fuzzy", lambda: global_fuzzy_pass(on, rt, match)),
        ("cg align", lambda: callgraph_align_pass(on, rt, match)),
        ("fuzzy", lambda: fuzzy_pass(on, rt, match, threshold=0.70)),
        ("global fuzzy", lambda: global_fuzzy_pass(on, rt, match, min_size=32)),
        ("cg align", lambda: callgraph_align_pass(on, rt, match)),
        ("string veto", lambda: -string_veto_pass(match, ostr, rstr)),
        ("order fix", lambda: order_fix_pass(on, rt, match, files)),
        ("cg align", lambda: callgraph_align_pass(on, rt, match)),
        ("order fix", lambda: order_fix_pass(on, rt, match, files)),
        ("string veto", lambda: -string_veto_pass(match, ostr, rstr)),
    ]
    for label, step in steps:
        print(f"  {label:12s} +{step()}  (total {len(match)})")

    OUTDIR.mkdir(parents=True, exist_ok=True)
    with open(OUTDIR / "mapping.csv", "w", newline="") as fh:
        w = csv.writer(fh)
        w.writerow(
            [
                "online_addr",
                "online_size",
                "retail_name",
                "retail_addr",
                "retail_size",
                "retail_file",
                "method",
                "score",
            ]
        )
        for oa in sorted(on):
            if oa in match:
                ra, m, s = match[oa]
                w.writerow(
                    [
                        f"0x{oa:08X}",
                        f"0x{on[oa].size:X}",
                        rt[ra].name,
                        f"0x{ra:08X}",
                        f"0x{rt[ra].size:X}",
                        file_of(ra, files),
                        m,
                        s,
                    ]
                )
            else:
                w.writerow(
                    [
                        f"0x{oa:08X}",
                        f"0x{on[oa].size:X}",
                        "",
                        "",
                        "",
                        "",
                        "online_only",
                        "",
                    ]
                )

    used = {r for r, _, _ in match.values()}
    per = collections.defaultdict(
        lambda: [0, 0, 0, 0]
    )  # funcs, found, bytes, found bytes
    for ra, f in rt.items():
        p = per[file_of(ra, files)]
        p[0] += 1
        p[2] += f.size
        if ra in used:
            p[1] += 1
            p[3] += f.size
    with open(OUTDIR / "retail_files.csv", "w", newline="") as fh:
        w = csv.writer(fh)
        w.writerow(
            [
                "retail_file",
                "functions",
                "found_in_online",
                "bytes",
                "found_bytes",
                "pct_bytes",
            ]
        )
        for fn, (a, b, c, d) in sorted(per.items(), key=lambda kv: kv[0]):
            w.writerow([fn, a, b, c, d, round(100 * d / c, 1) if c else 0])

    only = [on[a] for a in sorted(on) if a not in match]
    (OUTDIR / "online_only.txt").write_text(
        "".join(f"0x{f.addr:08X} 0x{f.size:X}\n" for f in only)
    )
    with open(OUTDIR / "symbol_addrs_ported.txt", "w") as fh:
        for oa in sorted(match):
            ra, m, s = match[oa]
            if m in ("fuzzy", "global_fuzzy", "order") and s < 0.85:
                continue  # low confidence: report only
            fh.write(
                f"{rt[ra].name:60s} = 0x{oa:08X}; // type:func size:0x{on[oa].size:X} // {m}\n"
            )

    tot_on = sum(f.size for f in on.values())
    m_on = sum(on[a].size for a in match)
    tot_rt = sum(f.size for f in rt.values())
    m_rt = sum(rt[r].size for r in used)
    print(
        f"\nOnline code matched to retail: {len(match)}/{len(on)} funcs, {100 * m_on / tot_on:.1f}% of bytes"
    )
    print(
        f"Retail code present in Online: {len(used)}/{len(rt)} funcs, {100 * m_rt / tot_rt:.1f}% of bytes"
    )
    print(f"Online-only: {len(only)} funcs, {sum(f.size for f in only) / 1024:.0f} KB")


if __name__ == "__main__":
    main()
