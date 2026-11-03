#!/usr/bin/env python3
"""Repair the m2c drafts that do not compile on their own (nm_apply's 'no_compile' bucket), in place in
logs/auto/*.drafts.c, so the next nm_build/n::go run picks them up as NON_MATCHING C.

Two kinds of repair:
 1. m2c's 16-byte type `s128` (quadword / VU0 register): the typedef lives in include/m2c_macros.h
    (`typedef int s128 __attribute__((mode(TI)))` - a true 128-bit scalar, so whole-quadword copies compile).
    That alone clears every draft whose only problem was s128.
 2. Error-driven, line-targeted repairs: compile the block alone with the real SN compiler, read its
    diagnostics, rewrite ONLY the lines the compiler names, compile again. Currently:
      - dereference of a value m2c left untyped (`*(v + x)` with v a void*/int): the asm loads a word, so
        `*(s32*)(v + x)`. Word is the dominant width in this code; the function bench flags any that differ.
      - `(s128) <value>` where the compiler cannot convert (float -> 128-bit): narrower cast `(s128)(s32)`,
        i.e. the integer value in the low word (the asm's quadword load of one float).
Blocks that still do not compile are left alone (they need hand C), and the report says which class remains.

Usage: python3 tools/nm/draftfix.py [--dry-run] [--limit N] [--files a.c,b.c] [--stats]
Report: prints a summary; details go to logs/nm/draftfix.txt
"""
import argparse, json, re, subprocess, sys
from pathlib import Path

R = Path(__file__).resolve().parent.parent.parent          # repo root (tools/nm/draftfix.py)
SN = "tools/compilers/ee-gcc2.95.3-114"
W = R / "logs/nm"
CFLAGS = ["-O2", "-G0", "-fno-exceptions", "-Iinclude", "-isystem", "include/gcc", "-isystem", "include/gcc/gcc-lib",
          "-isystem", "include/sdk", "-isystem", "include/sdk/common", "-isystem", "include/sdk/ee"]
PLACEHOLDER = re.compile(r"\bM2C_(BREAK|ERROR|TRAP|SYNC|UNK_)\w*\s*\(")

TYPESPEC = re.compile(r"^(?:[A-Za-z_]\w*\s*\*|M2C_UNK\w*\s*\*|void\s*\*|struct\s+\w+\s*\*)")


def cc(idx, code, hdr):
    """Compile one draft alone exactly like tools/nm_apply.py does."""
    W.mkdir(parents=True, exist_ok=True)
    (W / "df_tmp").mkdir(parents=True, exist_ok=True)
    one = W / "df_tmp" / f"c{idx}.c"
    obj = W / "df_tmp" / f"c{idx}.o"
    one.write_text(f'#include "{hdr}"\n{code}')
    obj.unlink(missing_ok=True)
    r = subprocess.run([str(R / SN / "bin/ee-gcc.exe"), f"-B{SN}/lib/gcc-lib/ee/2.95.3/", "-c", *CFLAGS,
                        str(one.relative_to(R)), "-o", str(obj.relative_to(R))],
                       cwd=R, capture_output=True, text=True, errors="replace")
    return (r.returncode == 0 and obj.exists()), r.stdout + r.stderr


def diags(out):
    """(line, message) for every error diagnostic (warnings and context lines dropped)."""
    res = []
    for l in out.splitlines():
        l = l.strip()
        if not l or "warning:" in l or "In function" in l or l.startswith("In file included"):
            continue
        m = re.match(r"^[^:\s]+\.c:(\d+): (.*)$", l)
        if m:
            res.append((int(m.group(1)), m.group(2)))
    return res


def fix_derefs(line):
    """`*(v + x)` / `*v` (m2c lost the pointee type) -> `*(s32*)(v + x)`."""
    spans, i = [], 0
    for m in re.finditer(r"(?<![\w)\]\.])\*(\s*)", line):
        j = m.end()
        if j >= len(line):
            continue
        if line[j] == "(":
            depth, k = 0, j
            while k < len(line):
                if line[k] == "(":
                    depth += 1
                elif line[k] == ")":
                    depth -= 1
                    if depth == 0:
                        k += 1
                        break
                k += 1
            operand = line[j:k]
            inner = operand[1:-1].strip()
            if not inner or TYPESPEC.match(inner):
                continue                                  # already typed: *(s32*)x
        elif re.match(r"[A-Za-z_]", line[j]):
            mm = re.match(r"[A-Za-z_]\w*", line[j:])
            if not mm:
                continue
            operand = mm.group(0)
            if line[j + len(operand):].lstrip().startswith("("):
                continue                                  # a call: m2c typed its return
            if TYPESPEC.match(operand):
                continue
        else:
            continue
        spans.append((m.start(), j + len(operand), "*(" "s32*" ")(" + operand + ")"))
    if not spans:
        return line, False
    out, i = [], 0
    for a, b, rep in spans:
        out.append(line[i:a])
        out.append(rep)
        i = b
    out.append(line[i:])
    return "".join(out), True


def repair(code, out, hdr, idx, log):
    """Rewrite the lines the compiler named, until it compiles or nothing more can be done."""
    for _ in range(6):
        errs = [d for d in diags(out) if d[1] and "Each undeclared identifier" not in d[1]]
        if not errs:
            return code, False
        lines = code.splitlines()
        did = False
        for ln, msg in errs:
            i = ln - 2                                        # file line 1 is the #include
            if not (0 <= i < len(lines)):
                continue
            src = lines[i]
            new = src
            if "void value not ignored" in msg or "invalid use of void expression" in msg \
                    or "invalid type argument of `unary *'" in msg or "invalid type argument of unary" in msg:
                new, c = fix_derefs(src)
                did |= c
            # 'unsupported wide integer operation' = a float/int into m2c's 128-bit type: this compiler cannot
            # do it at all, so those drafts are left for hand C (no text rewrite can make them valid here).
            if new != src:
                log.append(f"  L{ln}: {msg}")
                log.append(f"     - {src.strip()[:160]}")
                log.append(f"     + {new.strip()[:160]}")
                lines[i] = new
        if not did:
            return code, False
        code = "\n".join(lines) + "\n"
        ok, out = cc(idx, code, hdr)
        if ok:
            return code, True
    return code, False


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--files", default="")
    ap.add_argument("--stats", action="store_true")
    ap.add_argument("--fail-list", default="", help="only these functions ('rel::name' per line)")
    a = ap.parse_args()
    only = set(Path(a.fail_list).read_text().split()) if a.fail_list else None
    srcs = sorted(p for p in (R / "src").rglob("*.c")
                  if (R / f"logs/auto/{str(p.relative_to(R)).replace('/', '_')}.drafts.c").exists())
    if a.files:
        want = {f.strip() for f in a.files.split(",") if f.strip()}
        srcs = [p for p in srcs if str(p.relative_to(R)) in want]
    tot = dict(fixed=0, ok=0, placeholder=0, fail=0)
    log = []
    remain = {}
    n = 0
    for src in srcs:
        rel = str(src.relative_to(R))
        slug = rel.replace("/", "_")
        hdr = "online/net.h" if rel == "src/online/net.c" else "common.h"
        draft = R / f"logs/auto/{slug}.drafts.c"
        text = draft.read_text()
        parts = re.split(r"^(//@@ \S+[^\n]*\n)", text, flags=re.M)
        # parts: [pre, marker, body, marker, body, ...]
        changed_file = False
        for k in range(1, len(parts), 2):
            marker, body = parts[k], parts[k + 1]
            name = marker.split()[1]
            orig = body.rstrip() + "\n"
            if only is not None and f"{rel}::{name}" not in only:
                continue
            if PLACEHOLDER.search(orig):
                tot["placeholder"] += 1
                continue
            if a.limit and n >= a.limit:
                break
            n += 1
            idx = k
            ok, out = cc(idx, orig, hdr)
            if ok:
                tot["ok"] += 1
                continue
            new, fixed = repair(orig, out, hdr, idx, log)
            if fixed:
                ok2, out2 = cc(idx, new, hdr)
                if ok2:
                    tot["fixed"] += 1
                    log.append(f"FIXED {name} ({rel})")
                    parts[k + 1] = new
                    changed_file = True
                    continue
            tot["fail"] += 1
            for ln, msg in diags(out)[:4]:
                key = re.sub(r"`[^']*'|'[^']*'", "'X'", msg)
                key = re.sub(r"\b\d+\b", "N", key)
                remain.setdefault(key, []).append(f"{name} ({rel})")
        if changed_file and not a.dry_run:
            draft.write_text("".join(parts))
    print("drafts:", tot)
    print("\n== what still does not compile ==")
    for k, v in sorted(remain.items(), key=lambda kv: -len(kv[1]))[:25]:
        print(f"{len(v):5d}  {k}   e.g. {v[0]}")
    if log:
        (W / "draftfix.txt").write_text("\n".join(log) + "\n")
        print(f"\ndetails: {W / 'draftfix.txt'} ({len(log)} lines)")


if __name__ == "__main__":
    main()
