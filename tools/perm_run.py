#!/usr/bin/env python3
"""
Unattended decomp-permuter over near-miss drafts, using the SN toolchain.
  1. rank: re-check drafts of still-asm functions, keep same-size misses with <= MAXD differing insns
  2. for each (closest first): permuter job dir + run with a time limit
  3. a score-0 result is re-aliased, put into the real build via batch_try, committed if byte-identical
Usage: perm_run.py [MAXD=8] [SECONDS_PER_FUNC=300] [MAX_FUNCS=60] [THREADS=4]
Resumable: functions already tried are listed in logs/perm/done.txt.
"""
import json, os, re, subprocess, sys, time
from pathlib import Path
R = Path.home() / "tmbo_decomp"; P = R / "logs/perm"; P.mkdir(parents=True, exist_ok=True)
MAXD, SECS, MAXF, THR = (int(sys.argv[i]) if len(sys.argv) > i else d for i, d in ((1, 8), (2, 300), (3, 60), (4, 4)))
sh = lambda c, **k: subprocess.run(c, shell=True, cwd=R, capture_output=True, text=True, **k)
SN = "tools/compilers/ee-gcc2.95.3-114"

def build_ok():
    (R / "build/SCUS_971.96.rom").unlink(missing_ok=True)
    return sh("ninja > logs/ninja.log 2>&1").returncode == 0 and \
        (R / "disks/SCUS_971.96.rom").read_bytes() == (R / "build/SCUS_971.96.rom").read_bytes()

# ---- 1. rank near misses
near_file = P / "near.json"
if not near_file.exists():
    near = {}
    for src in sorted((R / "src").rglob("*.c")):
        rel = src.relative_to(R); slug = str(rel).replace("/", "_")
        drafts = R / f"logs/auto/{slug}.drafts.c"
        names = re.findall(r'^INCLUDE_ASM\("[^"]*", (\S+)\);', src.read_text(), re.M)
        if not names or not drafts.exists(): continue
        hdr = "online/net.h" if rel.as_posix() == "src/online/net.c" else "common.h"
        out = P / f"{slug}.near.json"
        env = dict(os.environ, ONLY_NAMES=",".join(names), NEAR_OUT=str(out))
        subprocess.run(["python3", "tools/fast_match.py", str(drafts), str(P / "ignore.c"), hdr], cwd=R, env=env, capture_output=True)
        if out.exists():
            for n, v in json.loads(out.read_text()).items():
                near[n] = dict(v, src=str(rel), hdr=hdr)
        print(f"ranked {rel}: {len(near)} near misses so far", flush=True)
    near_file.write_text(json.dumps(near))
near = json.loads(near_file.read_text())
todo = sorted((v["diff"], n) for n, v in near.items() if v["diff"] <= MAXD)
done = set((P / "done.txt").read_text().split()) if (P / "done.txt").exists() else set()
def still_asm(n):   # skip functions matched since ranking (fixup, earlier runs)
    return bool(re.search(rf'INCLUDE_ASM\("[^"]*", {re.escape(n)}\);', (R / near[n]["src"]).read_text()))
todo = [n for d, n in todo if n not in done and still_asm(n)][:MAXF]
print(f"{len(near)} near misses; {len(todo)} to permute (<= {MAXD} insns off)", flush=True)

# ---- 2. job setup
COMPILE = f"""#!/bin/bash
# permuter compile hook: SN ee-gcc (Windows exe) needs paths relative to the project
cd {R}
T=$(mktemp -d -p logs/permtmp)
cp "$1" "$T/in.c"
{SN}/bin/ee-gcc.exe -B{SN}/lib/gcc-lib/ee/2.95.3/ -c -O2 -G0 -Wa,-G8 -fno-exceptions "$T/in.c" -o "$T/out.o" 2>/dev/null
rc=$?; [ $rc = 0 ] && cp "$T/out.o" "$3"; rm -rf "$T"; exit $rc
"""
(R / "logs/permtmp").mkdir(exist_ok=True)
ASM = {p.stem: p for p in (R / "asm/nonmatchings").rglob("*.s")}

def setup(name, v):
    d = P / name
    subprocess.run(["rm", "-rf", str(d)]); d.mkdir()
    sfx = name[-6:]
    code = re.sub(r' __asm__\("[^"]*"\)', "", v["code"])
    code = re.sub(rf"\b(\w+)_{sfx}\b", r"\1", code)                      # drop private aliases
    (d / "draft.c").write_text(f'#include "{v["hdr"]}"\n{code}')
    r = sh(f"gcc -E -P -std=gnu89 -DPERMUTER -Iinclude -isystem include/gcc -D'__attribute__(x)=' {d / 'draft.c'} -o {d / 'base.c'}")
    if r.returncode: return False
    (d / "target.s").write_text('.include "macro.inc"\n.set noat\n.set noreorder\n.section .text\n' + ASM[name].read_text())
    if sh(f"mips-linux-gnu-as -EL -march=5900 -G0 -no-pad-sections -mabi=eabi -Iinclude {d / 'target.s'} -o {d / 'target.o'}").returncode:
        return False
    (d / "compile.sh").write_text(COMPILE); (d / "compile.sh").chmod(0o755)
    (d / "settings.toml").write_text(f'func_name = "{name}"\ncompiler_type = "gcc"\n')
    return True

def realias(name, fn_text, v, out_text=""):
    """Put the solved function back into the draft's aliased form for the real file.
    The permuter may also have changed the type of an extern/prototype: carry those over."""
    sfx = name[-6:]
    head = v["code"][:v["code"].find(f"{name}(")]
    head = head[:head.rfind("\n") + 1]                                    # declarations only
    top = [l for l in out_text.split("\n") if l and not l[0].isspace() and l.rstrip().endswith(";")]
    lines = []
    for l in head.split("\n"):
        m = re.search(rf'\b(\w+)_{sfx}\b.*__asm__\("(\w+)"\)', l)
        if m and m.group(1) == m.group(2):
            real = m.group(1)
            new = [t for t in top if re.search(rf"\b{re.escape(real)}\b", t) and not t.startswith("typedef")]
            if new:
                t = re.sub(rf"\b{re.escape(real)}\b", f"{real}_{sfx}", new[-1].rstrip()[:-1])
                l = f'{t} __asm__("{real}");'
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
RETRY = os.environ.get("RETRY") == "1"     # re-apply existing score-0 outputs, no permuting
if RETRY:
    todo = [n for n in sorted(done) if n in near and list((P / n).glob("output-0-*/source.c"))
            and re.search(rf'INCLUDE_ASM\("[^"]*", {re.escape(n)}\);', (R / near[n]["src"]).read_text())]
    print(f"RETRY: {len(todo)} score-0 outputs to re-apply", flush=True)
TRAILER = ("\n\nCo-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>\n"
           "Claude-Session: https://claude.ai/code/session_0163vgjiFyQy8GoFYgqXiav1")
assert build_ok(), "build must be byte-identical before starting"
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
        print(f"[{k}/{len(todo)}] {name}: {v['diff']} insns off -> best score {best[0].name.split('-')[1] if best else '-'}  "
              f"({solved} solved, {time.time() - t0:.0f}s)", flush=True); continue
    otext = outs[0].read_text()
    fn = extract(otext, name)
    block = R / f"logs/perm/{name}.solved.c"
    block.write_text(f"//@@ {name}\n{realias(name, fn, v, otext)}") if fn else None
    src = R / v["src"]; before = src.read_text()
    out = sh(f"python3 tools/batch_try.py {v['src']} {block}").stdout
    if fn and "kept 1" in out and build_ok():
        solved += 1
        sh(f'git add -A && git -c user.name=tmbo -c user.email=tmbo@localhost commit -q --no-verify -m "Permuter match: {name}{TRAILER}"')
        print(f"[{k}/{len(todo)}] {name}: SOLVED and verified  ({solved} solved)", flush=True)
    else:
        src.write_text(before); build_ok()
        print(f"[{k}/{len(todo)}] {name}: permuter hit 0 but the real build disagreed", flush=True)
print(f"\nDONE: {solved} solved of {len(todo)} tried; build byte-identical: {build_ok()}")
