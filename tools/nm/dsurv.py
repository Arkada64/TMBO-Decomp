#!/usr/bin/env python3
"""Survey the m2c drafts that do NOT compile on their own (nm_apply's 'no_compile' bucket = 480) and collect the
REAL compiler error text for each, grouped by signature, so the common m2c patterns can be fixed in a tool
(tools/nm/draftfix.py) the way bytefix.py fixed the byte-offset pointer arithmetic.

Incremental: results are cached in ~/nmtools/dsurv_cache.json keyed by function name + hash of the code that was
tried (after bytefix + draftfix), so a re-run after changing draftfix.py only recompiles what changed.

Usage: python3 dsurv.py [--jobs N] [--limit N] [--report FILE] [--files src/a.c,src/b.c]
Writes: the report (default /mnt/d/TMB Decomp/cloud/out/dsurv.txt) and the cache.
"""
import argparse, hashlib, json, os, re, subprocess, sys
from multiprocessing import Pool
from pathlib import Path

R = Path("/home/ark/nmhome/tmbo_decomp")          # the private build copy (nm_build.sh)
SN = "tools/compilers/ee-gcc2.95.3-114"
W = R / "logs/nm"
DW = W / "ds"
CFLAGS = ["-O2", "-G0", "-fno-exceptions", "-Iinclude", "-isystem", "include/gcc", "-isystem", "include/gcc/gcc-lib",
          "-isystem", "include/sdk", "-isystem", "include/sdk/common", "-isystem", "include/sdk/ee"]
CACHE = Path("/home/ark/nmtools/dsurv_cache.json")
FIXDIR = Path("/home/ark/nmtools/tools/nm")
sys.path[:0] = [str(R / "tools"), str(R / "tools" / "nm"), str(FIXDIR)]   # bytefix.py + draftfix.py
# a change to the headers the drafts include (m2c's s128 typedef lives there) must invalidate cached verdicts
HDRH = "".join(hashlib.sha1(p.read_bytes()).hexdigest()[:8] for p in (R / "include/m2c_macros.h", R / "include/common.h") if p.exists())


def load_fixer():
    """tools/nm/draftfix.py:draftfix(code) -> (code, changed) - same contract as bytefix."""
    sys.path.insert(0, str(FIXDIR))
    try:
        import draftfix
        return draftfix.draftfix
    except Exception as e:
        print(f"draftfix not loaded: {e}", file=sys.stderr)
        return None


def cc(idx, code, hdr):
    """Compile one draft alone, exactly like nm_apply.cc (ee-gcc.exe, same flags); return (ok, output)."""
    one = DW / f"{os.getpid()}_{idx}.c"
    obj = DW / f"{os.getpid()}_{idx}.o"
    one.write_text(f'#include "{hdr}"\n{code}')
    obj.unlink(missing_ok=True)
    args = [str(R / SN / "bin/ee-gcc.exe"), f"-B{SN}/lib/gcc-lib/ee/2.95.3/", "-c", *CFLAGS,
            str(one.relative_to(R)), "-o", str(obj.relative_to(R))]
    try:
        r = subprocess.run(args, cwd=R, capture_output=True, text=True, errors="replace", timeout=180)
        out = r.stdout + r.stderr
        return (r.returncode == 0 and obj.exists()), out
    except subprocess.TimeoutExpired:
        return False, "COMPILER TIMEOUT"
    finally:
        one.unlink(missing_ok=True)
        obj.unlink(missing_ok=True)


def errlines(out):
    """The diagnostics, without m2c noise: (line, message) pairs for errors only."""
    keep = []
    for l in out.splitlines():
        l = l.strip()
        if not l:
            continue
        if ": warning:" in l or l.endswith("warning:") or "warning:" in l:
            continue
        if "In function" in l or l.startswith("In file included") or "In method" in l:
            continue
        m = re.match(r"^[^:\s]+\.c:(\d+): (.*)$", l) or re.match(r"^[^:\s]+\.c:(\d+):(\d+): (.*)$", l)
        if m:
            keep.append((int(m.group(1)), m.group(m.lastindex)))
    return keep


IDENT = re.compile(r"`[^']*'|'[^']*'|\"[^\"]*\"")
NUM = re.compile(r"\b(?:0x[0-9a-fA-F]+|\d+)\b")
TYPEW = re.compile(r"\b(?:int|long|unsigned|char|short|float|double|void|struct \w+)\b")


def signature(msg):
    """Normalize a diagnostic so the same m2c mistake groups together."""
    s = IDENT.sub("'X'", msg)
    s = NUM.sub("N", s)
    s = TYPEW.sub("T", s)
    s = re.sub(r"\s+", " ", s).strip()
    return s


def classify(sig, raw):
    """Coarse bucket for the report."""
    r = raw.lower()
    for k, pat in [
        ("undeclared identifier", "undeclared"),
        ("has no member", "no member"),
        ("invalid operands", "invalid operands"),
        ("incompatible types", "incompatible type"),
        ("conflicting types", "conflicting type"),
        ("too few/many arguments", "arguments for"),
        ("dereferencing incomplete type", "incomplete type"),
        ("subscripted value / not array", "subscripted value"),
        ("lvalue required", "lvalue required"),
        ("syntax error / parse error", "parse error"),
        ("parse error before", "parse error"),
        ("initializer", "initializer"),
        ("implicit declaration", "implicit declaration"),
        ("duplicate / redeclared", "redecl"),
        ("storage size", "storage size"),
        ("assignment makes pointer from integer", "ptr from int"),
        ("assignment makes integer from pointer", "int from ptr"),
    ]:
        if pat in r:
            return k
    return sig.split(":")[0][:60] if ":" in sig else "other"


def tasks(files=None, limit=None):
    out = []
    srcs = sorted(p for p in (R / "src").rglob("*.c")
                  if (R / f"logs/auto/{str(p.relative_to(R)).replace('/', '_')}.drafts.c").exists())
    if files:
        want = {f.strip() for f in files.split(",") if f.strip()}
        srcs = [p for p in srcs if str(p.relative_to(R)) in want]
    for src in srcs:
        rel = str(src.relative_to(R))
        slug = rel.replace("/", "_")
        text = src.read_text()
        names = re.findall(r'^INCLUDE_ASM\("[^"]*", (\S+)\);', text, re.M)
        blocks = re.split(r"^//@@ (\S+)[^\n]*\n", (R / f"logs/auto/{slug}.drafts.c").read_text(), flags=re.M)[1:]
        variants = {}
        for n, c in zip(blocks[0::2], blocks[1::2]):
            variants.setdefault(n, []).append(c.rstrip() + "\n")
        hdr = "online/net.h" if rel == "src/online/net.c" else "common.h"
        for n in names:
            if n not in variants:
                continue                                  # no draft at all (different bucket)
            out.append((rel, n, hdr, variants[n]))
    if limit:
        out = out[:limit]
    return out


def prepare(t):
    """Apply bytefix + draftfix to a function's variants; returns (variants, changes)."""
    rel, name, hdr, vs = t
    from bytefix import bytefix
    fix = load_fixer()
    res, ch = [], []
    for c in vs:
        c2, b = bytefix(c)
        if b:
            ch.append("bytefix")
        if fix:
            c3, d = fix(c2)
            if d:
                ch.append("draftfix:%s" % ",".join(d) if isinstance(d, (list, tuple)) else "draftfix")
                c2 = c3
        res.append(c2)
    return res, sorted(set(ch))


def run_one(args):
    rel, name, hdr, variants = args
    vs, ch = prepare((rel, name, hdr, variants))
    h = hashlib.sha1("\n//--\n".join(vs).encode()).hexdigest()[:16]
    tried, errs = 0, []
    for i, c in enumerate(vs):
        if re.search(r"\bM2C_(BREAK|ERROR|TRAP|SYNC|UNK_)\w*\s*\(", c):
            continue                                      # m2c placeholder: skip like nm_apply
        tried += 1
        ok, out = cc(i, c, hdr)
        if ok:
            return dict(rel=rel, name=name, hash=h, changes=ch, status="ok", variant=i)
        errs.append(errlines(out))
    if not tried:
        return dict(rel=rel, name=name, hash=h, changes=ch, status="placeholder")
    # the last variant's errors are the interesting ones (usually the only one)
    e = errs[-1]
    sigs = sorted({signature(m) for _, m in e})
    return dict(rel=rel, name=name, hash=h, changes=ch, status="fail", nvar=len(vs),
                errs=[[ln, m] for ln, m in e][:12], sigs=sigs,
                classes=sorted({classify(s, s) for s in sigs}))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--jobs", type=int, default=4)
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--files", default="")
    ap.add_argument("--report", default="/mnt/d/TMB Decomp/cloud/out/dsurv.txt")
    ap.add_argument("--no-cache", action="store_true")
    ap.add_argument("--fails-only", action="store_true", help="recompile only the functions known to fail (fast iteration)")
    a = ap.parse_args()
    DW.mkdir(parents=True, exist_ok=True)
    cache = {}
    if CACHE.exists() and not a.no_cache:
        try:
            cache = json.loads(CACHE.read_text())
        except Exception:
            cache = {}
    ts = tasks(a.files or None, a.limit or None)
    todo, done = [], 0
    for t in ts:
        key = f"{t[0]}::{t[1]}"
        # cheap hash first: without re-running the fixers, decide if we can trust the cache
        raw = "\n//--\n".join(c.rstrip() + "\n" for c in t[3]) + HDRH
        rh = hashlib.sha1(raw.encode()).hexdigest()[:16]
        c = cache.get(key)
        if a.fails_only:
            if not (c and c.get("status") == "fail"):
                done += 1
                continue
            todo.append(t)
            continue
        if c and c.get("rawhash") == rh:
            done += 1                                     # unchanged since last run: keep the cached verdict
            continue
        todo.append(t)
    print(f"functions with drafts: {len(ts)}, cached: {done}, to compile: {len(todo)}", flush=True)
    rawh = {f"{t[0]}::{t[1]}": hashlib.sha1(("\n//--\n".join(c.rstrip() + "\n" for c in t[3]) + HDRH).encode()).hexdigest()[:16]
            for t in todo}
    with Pool(a.jobs) as p:
        for i, r in enumerate(p.imap_unordered(run_one, todo), 1):
            key = f"{r['rel']}::{r['name']}"
            r["rawhash"] = rawh[key]
            cache[key] = r
            if i % 50 == 0:
                print(f"  {i}/{len(todo)}", flush=True)
                CACHE.write_text(json.dumps(cache))
    CACHE.write_text(json.dumps(cache))
    # ---- report over everything we know
    rows = list(cache.values())
    st = {s: sum(1 for r in rows if r["status"] == s) for s in ("ok", "fail", "placeholder")}
    lines = [f"draft survey  {len(rows)} functions with drafts   ok={st['ok']} fail={st['fail']} placeholder={st['placeholder']}",
             ""]
    fails = [r for r in rows if r["status"] == "fail"]
    cls = {}
    for r in fails:
        for c in (r.get("classes") or ["other"]):
            cls.setdefault(c, []).append(r)
    lines.append("== failure classes (functions affected) ==")
    for c, rs in sorted(cls.items(), key=lambda kv: -len(kv[1])):
        lines.append(f"{len(rs):5d}  {c}")
    lines.append("")
    lines.append("== top diagnostic signatures ==")
    sigc = {}
    for r in fails:
        for s in (r.get("sigs") or []):
            sigc.setdefault(s, []).append(r)
    for s, rs in sorted(sigc.items(), key=lambda kv: -len(kv[1]))[:40]:
        ex = rs[0]
        lines.append(f"{len(rs):5d}  {s}")
        lines.append(f"        e.g. {ex['name']} ({ex['rel']})")
    lines.append("")
    lines.append("== per file (fail counts) ==")
    per = {}
    for r in fails:
        per[r["rel"]] = per.get(r["rel"], 0) + 1
    for f, n in sorted(per.items(), key=lambda kv: -kv[1]):
        lines.append(f"{n:5d}  {f}")
    Path(a.report).write_text("\n".join(lines) + "\n")
    # full failure detail next to the report
    det = Path(a.report).with_suffix(".json")
    det.write_text(json.dumps({k: v for k, v in cache.items() if v.get("status") != "ok"}, indent=1))
    print("\n".join(lines[:60]))
    print(f"\nreport: {a.report}\ndetail: {det}")


if __name__ == "__main__":
    main()
