#!/usr/bin/env python3
"""
fixup.py: rewrite m2c drafts for two systematic m2c-vs-C mistakes, then fast_match the variants.
  P  m2c writes pointer arithmetic in BYTES; on a typed pointer (s16*, s32*, void**...) C scales it.
     -> divide the constant by the element size  (var += 0x10 on s32* -> var += 4)
     -> (i * K) + &D  with D a 4-byte extern     -> (i * K/4) + &D
  A  m2c drops a leading argument that is just passed through in a0 (a1) -> prepend arg0 (arg0, arg1)
Variants per function: P, A1..An, P+A1..; the first one that matches wins (fast_match).
Usage: fixup.py            (all still-INCLUDE_ASM functions that have drafts)
Output: logs/fix/<slug>.matched.c (batch_try format), summary on stdout.
"""
import re, subprocess, sys, os, json
from pathlib import Path
R = Path.home() / "tmbo_decomp"; OUT = R / "logs/fix"; OUT.mkdir(parents=True, exist_ok=True)
SZ = {"s8": 1, "u8": 1, "char": 1, "s16": 2, "u16": 2, "M2C_UNK16": 2, "s32": 4, "u32": 4, "f32": 4,
      "M2C_UNK": 4, "M2C_UNK32": 4, "s64": 8, "u64": 8, "f64": 8, "M2C_UNK64": 8}
NUM = r"(0x[0-9A-Fa-f]+|\d+)"

def scale_ptrs(code):
    ptrs = {}
    for m in re.finditer(r"\b(\w+)\s*(\*+)\s*(\w+)\s*[;,)=]", code):
        t, stars, v = m.groups()
        size = 4 if len(stars) > 1 else SZ.get(t)
        if size and size > 1: ptrs[v] = size
    for m in re.finditer(r"^extern (\w+) (\w+)", code, re.M):
        if SZ.get(m.group(1), 0) > 1: ptrs["&" + m.group(2)] = SZ[m.group(1)]
    new = code
    def div(v, s, n):
        k = int(n, 0)
        return hex(k // s) if k % s == 0 else None
    for v, s in ptrs.items():
        if v.startswith("&"):
            d = re.escape(v)
            def f(m):
                r = div(None, s, m.group(2)); return m.group(0) if r is None else f"{m.group(1)}{r})"
            new = re.sub(rf"(\(\w+ \* ){NUM}\)(?= \+ {d}\b)", f, new)
            new = re.sub(rf"(?<={d} \+ )(\(\w+ \* ){NUM}\)", f, new)
            continue
        def g(m):
            r = div(None, s, m.group(3)); return m.group(0) if r is None else f"{m.group(1)}{m.group(2)}{r}"
        new = re.sub(rf"(\b{v}\s*)(\+=|-=|\+ |- )\s*{NUM}\b(?!\s*\*)", g, new)
    return new

def arg_variants(code):
    body = code[code.find("{"):] if "{" in code else ""
    sig = code[:len(code) - len(body)]
    calls = [m for m in re.finditer(r"\b(\w+)\(", body) if m.group(1) not in ("if", "while", "for", "switch", "return", "sizeof", "M2C_FIELD")]
    out = []
    params = re.search(r"\(([^()]*)\)\s*$", sig.rstrip())
    has0 = params and "arg0" in params.group(1)
    has1 = params and "arg1" in params.group(1)
    for m in calls[:3]:
        for pre in ("arg0", "arg0, arg1"):
            if pre == "arg0, arg1" and not has1: continue
            i = m.end()
            b = body[:i] + pre + (", " if body[i] != ")" else "") + body[i:]
            s = sig
            if not has0:
                s = re.sub(r"\((void)?\)(\s*)$", r"(void* arg0)\2", sig.rstrip()) + "\n"
            out.append(s + b)
    return out

NEAR = json.loads((R / "logs/perm/near.json").read_text()) if (R / "logs/perm/near.json").exists() else {}
def main():
    tot = {}
    for src in sorted((R / "src").rglob("*.c")):
        rel = src.relative_to(R); slug = str(rel).replace("/", "_")
        drafts = R / f"logs/auto/{slug}.drafts.c"
        names = set(re.findall(r'^INCLUDE_ASM\("[^"]*", (\S+)\);', src.read_text(), re.M))
        if not names or not drafts.exists(): continue
        blocks = re.split(r"^//@@ (\S+)[^\n]*\n", drafts.read_text(), flags=re.M)[1:]
        var, seen = [], set()
        for name, code in zip(blocks[0::2], blocks[1::2]):
            if name not in names or name in seen: continue
            seen.add(name)
            if name in NEAR: code = NEAR[name]["code"]           # closest variant we know of
            fpos = code.find(f"{name}(")
            if fpos < 0: continue
            ls = code.rfind("\n", 0, fpos) + 1
            head, fn = code[:ls], code[ls:]
            p = scale_ptrs(fn)
            cands = ([p] if p != fn else []) + arg_variants(fn) + ([q for q in arg_variants(p)] if p != fn else [])
            for c in cands: var.append(f"//@@ {name}\n{head}{c}")
        if not var: continue
        vf = OUT / f"{slug}.variants.c"; vf.write_text("".join(var))
        hdr = "online/net.h" if rel.as_posix() == "src/online/net.c" else "common.h"
        mf = OUT / f"{slug}.matched.c"
        r = subprocess.run(["python3", "tools/fast_match.py", str(vf), str(mf), hdr], cwd=R, capture_output=True, text=True)
        got = re.findall(r"^//@@ (\S+)", mf.read_text(), re.M) if mf.exists() else []
        tot[str(rel)] = got
        print(f"{rel}: {len(var)} variants -> {len(got)} matched {got[:6]}", flush=True)
    n = sum(len(v) for v in tot.values())
    (OUT / "summary.json").write_text(json.dumps(tot))
    print(f"\nFIXUP DONE: {n} functions matched standalone")
main()
