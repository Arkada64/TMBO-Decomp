#!/usr/bin/env python3
"""
RETAIL: unattended decomp-permuter over near-miss drafts (EE-GCC 2.9), ported from the online one.
  1. near misses: logs/drafts/*.near.json (same-size drafts from retail_auto.sh) whose function is
     still INCLUDE_ASM in src/tmb/X.c; closest first, <= MAXD differing insns
  2. per function: permuter job dir in logs/perm/NAME, run with a time limit
  3. a score-0 result is re-aliased and put into the real build with integrate.py (sha1-verified),
     committed per function
Usage: perm_run.py [MAXD=8] [SECONDS_PER_FUNC=300] [MAX_FUNCS=60] [THREADS=4]
Resumable (logs/perm/done.txt). RETRY=1 re-applies existing score-0 outputs without permuting.
Needs pycparser 2.x in the venv (pip install 'pycparser<3'); m2c uses its own m2c_pycparser.
"""
import json, os, re, subprocess, sys, time
from pathlib import Path
import pycparser
assert pycparser.__version__.startswith("2."), f"permuter needs pycparser 2.x, have {pycparser.__version__}: pip install 'pycparser<3'"
R = Path.home() / "tmb_decomp"; P = R / "logs/perm"; P.mkdir(parents=True, exist_ok=True)
MAXD, SECS, MAXF, THR = (int(sys.argv[i]) if len(sys.argv) > i else d for i, d in ((1, 8), (2, 300), (3, 60), (4, 4)))
sh = lambda c, **k: subprocess.run(c, shell=True, cwd=R, capture_output=True, text=True, **k)
CC = f"{R}/tools/ee-gcc2.9/bin/ee-gcc -c -O2 -G8 -fno-exceptions"
TRAILER = ("\n\nCo-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>\n"
           "Claude-Session: https://claude.ai/code/session_01NDPuYvF2UhuQVqWzE5yi2a")

def remaining(seg):
    s = R / f"src/tmb/{seg}.c"
    return set(re.findall(r'^INCLUDE_ASM\("[^"]*", (\S+)\);', s.read_text(), re.M)) if s.exists() else set()

# ---- 1. near misses
near = {}
for f in (R / "logs/drafts").glob("*.near.json"):
    seg = f.name[:-len(".near.json")]
    left = remaining(seg)
    for n, v in json.loads(f.read_text()).items():
        if n in left and (n not in near or v["diff"] < near[n]["diff"]):
            near[n] = dict(v, seg=seg)
done = set((P / "done.txt").read_text().split()) if (P / "done.txt").exists() else set()
todo = [n for d, n in sorted((v["diff"], n) for n, v in near.items() if v["diff"] <= MAXD) if n not in done][:MAXF]
print(f"{len(near)} near misses still asm; {len(todo)} to permute (<= {MAXD} insns off)", flush=True)

# ---- 2. job setup
COMPILE = f"""#!/bin/bash
# permuter compile hook: retail EE-GCC 2.9, same flags as the build (input is preprocessed)
{CC} "$1" -o "$3" 2>/dev/null
"""
def sfx_of(code):
    m = re.search(r'_([0-9A-F]+_\d+)(?:\[[^\]]*\])?(?:\([^)]*\))? __asm__\("', code)
    return m.group(1) if m else None

def setup(name, v):
    d = P / name
    subprocess.run(["rm", "-rf", str(d)]); d.mkdir()
    code, sfx = v["code"], sfx_of(v["code"])
    code = re.sub(r' __asm__\("[^"]*"\)', "", code)
    if sfx: code = re.sub(rf"\b(\w+)_{sfx}\b", r"\1", code)            # drop private aliases
    (d / "draft.c").write_text(code)
    r = sh(f"gcc -E -P -std=gnu89 -DPERMUTER -Iinclude -isystem include/gcc -D'__attribute__(x)=' {d / 'draft.c'} -o {d / 'base.c'}")
    if r.returncode: return False
    s = R / f"asm/nonmatchings/tmb/{v['seg']}/{name}.s"
    if not s.exists(): return False
    (d / "target.s").write_text('.include "macro.inc"\n.set noat\n.set noreorder\n.section .text\n' + s.read_text())
    if sh(f"mips-linux-gnu-as -EL -march=5900 -G0 -no-pad-sections -mabi=eabi -Iinclude {d / 'target.s'} -o {d / 'target.o'}").returncode:
        return False
    (d / "compile.sh").write_text(COMPILE); (d / "compile.sh").chmod(0o755)
    (d / "settings.toml").write_text(f'func_name = "{name}"\ncompiler_type = "gcc"\n')
    return True

def realias(name, fn_text, v, out_text=""):
    """Put the solved function back into the draft's aliased form; carry over extern/prototype
    types the permuter changed."""
    sfx = sfx_of(v["code"])
    head = v["code"][:v["code"].find(f"{name}(")]
    head = head[:head.rfind("\n") + 1]
    if not sfx: return head + fn_text
    top = [l for l in out_text.split("\n") if l and not l[0].isspace() and l.rstrip().endswith(";")]
    lines = []
    for l in head.split("\n"):
        m = re.search(rf'\b(\w+)_{sfx}\b.*__asm__\("(\w+)"\)', l)
        if m and m.group(1) == m.group(2):
            real = m.group(1)
            new = [t for t in top if re.search(rf"\b{re.escape(real)}\b", t) and not t.startswith("typedef")]
            if new:
                l = f'{re.sub(rf"\b{re.escape(real)}\b", f"{real}_{sfx}", new[-1].rstrip()[:-1])} __asm__("{real}");'
        lines.append(l)
    head = "\n".join(lines)
    for real in re.findall(rf"\b(\w+)_{sfx}\b", head):
        fn_text = re.sub(rf"\b{re.escape(real)}\b", f"{real}_{sfx}", fn_text)
    return head + fn_text

def extract(src_text, name):
    m = re.search(rf"^[^\n;{{}}]*\b{re.escape(name)}\([^;{{]*\)\s*\{{", src_text, re.M)
    if not m: return None
    i, depth = m.end() - 1, 0
    for j in range(i, len(src_text)):
        depth += {"{": 1, "}": -1}.get(src_text[j], 0)
        if depth == 0: return src_text[m.start():j + 1] + "\n"

# ---- 3. run
RETRY = os.environ.get("RETRY") == "1"
if RETRY:
    todo = [n for n in sorted(done) if n in near and list((P / n).glob("output-0-*/source.c"))]
    print(f"RETRY: {len(todo)} score-0 outputs to re-apply", flush=True)
solved, t0 = 0, time.time()
for k, name in enumerate(todo, 1):
    v = near[name]
    if not RETRY:
        with open(P / "done.txt", "a") as f: f.write(name + "\n")
        if not setup(name, v):
            print(f"[{k}/{len(todo)}] {name}: setup failed", flush=True); continue
        try:
            sh(f"timeout {SECS} python3 tools/decomp-permuter/permuter.py {P / name} --stop-on-zero --best-only -j{THR}",
               timeout=SECS + 60)
        except subprocess.TimeoutExpired:
            pass
    outs = sorted((P / name).glob("output-0-*/source.c"))
    if not outs:
        best = sorted((P / name).glob("output-*"), key=lambda p: int(p.name.split("-")[1]))
        print(f"[{k}/{len(todo)}] {name}: {v['diff']} insns off -> best score "
              f"{best[0].name.split('-')[1] if best else '-'}  ({solved} solved, {time.time() - t0:.0f}s)", flush=True)
        continue
    otext = outs[0].read_text()
    fn = extract(otext, name)
    if not fn:
        print(f"[{k}/{len(todo)}] {name}: score 0 but function not found in output", flush=True); continue
    block = P / f"{name}.solved.c"
    block.write_text(f"//@@ {name} perm\n#include \"m2c_macros.h\"\n{realias(name, fn, v, otext)}")
    out = sh(f"python3 tools/integrate.py {v['seg']} {block}").stdout
    if re.search(r": 1/1 matches kept; byte-identical: True", out):
        solved += 1
        sh(f'git add -A src && git -c user.name=tmbo -c user.email=tmbo@localhost commit -q --no-verify '
           f'-m "Retail permuter match: {name}{TRAILER}"')
        print(f"[{k}/{len(todo)}] {name}: SOLVED and verified  ({solved} solved)", flush=True)
    else:
        print(f"[{k}/{len(todo)}] {name}: permuter hit 0 but the real build disagreed", flush=True)
print(f"\nDONE: {solved} solved of {len(todo)} tried")
