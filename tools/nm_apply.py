#!/usr/bin/env python3
"""
Working-C pass: put the m2c drafts of still-asm functions into the source as NON_MATCHING alternatives:

    #ifdef NON_MATCHING
    <draft C>
    #else
    INCLUDE_ASM("...", name);
    #endif

The normal build is untouched (byte-identical); a build with -DNON_MATCHING uses the C. A draft is used only if
it compiles on its own (first variant that does), and the whole file must still compile with NON_MATCHING:
blocks the compiler complains about are dropped again until it does.
Functions the mods hook (tools/mods/apply_mods.py patches their .s) and hand-written *Asm routines stay asm.
Usage: nm_apply.py [SRC.c ...]   (default: every src file that has a drafts file in logs/auto)
Writes logs/nm/summary.json (per file: used / no draft / no compiling draft / dropped in context).
"""
import json, os, re, subprocess, sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parent)); sys.path.insert(0, str(Path(__file__).resolve().parent / "nm"))
try:
    from bytefix import bytefix            # m2c's byte-offset pointer arithmetic on typed pointers (tools/nm/bytefix.py)
except ImportError:
    bytefix = None
from pathlib import Path
R = Path.home() / "tmbo_decomp"
SN = "tools/compilers/ee-gcc2.95.3-114"
W = R / "logs/nm"; W.mkdir(parents=True, exist_ok=True)
CFLAGS = ["-O2", "-G0", "-fno-exceptions", "-Iinclude", "-isystem", "include/gcc", "-isystem", "include/gcc/gcc-lib",
          "-isystem", "include/sdk", "-isystem", "include/sdk/common", "-isystem", "include/sdk/ee"]

def cc(path, extra=(), whole=False):
    """whole=True: the real build's compiler wrapper (tools/sn_cc.sh handles INCLUDE_ASM), as build.ninja's cc rule"""
    obj = W / "t.o"; obj.unlink(missing_ok=True)
    pre = ["tools/sn_cc.sh"] if whole else [f"{R / SN}/bin/ee-gcc.exe", f"-B{SN}/lib/gcc-lib/ee/2.95.3/"]
    r = subprocess.run([*pre, "-c", *extra, *CFLAGS, str(Path(path).relative_to(R)), "-o", str(obj.relative_to(R))],
                       cwd=R, capture_output=True, text=True)
    return r.returncode == 0 and obj.exists(), r.stdout + r.stderr

# functions the mods patch in their .s files: keep them asm in every build
hooked = set(re.findall(r'A\("[^"]*/([A-Za-z_0-9]+)\.s"\)', (R / "tools/mods/apply_mods.py").read_text()))
hooked |= {"func_00127650"}          # the level loader (LOADER in apply_mods.py)
# functions mods/postlink.txt patches by address (respawn shield) stay asm too
try:
    _sa = []
    for l in (R / "config/US/symbol_addrs.txt").read_text().splitlines():
        m = re.match(r"\s*(\S+)\s*=\s*(0x[0-9A-Fa-f]+);.*size:(0x[0-9A-Fa-f]+)", l)
        if m: _sa.append((int(m.group(2), 16), int(m.group(3), 16), m.group(1)))
    for l in (R / "mods/postlink.txt").read_text().splitlines():
        f = l.split("#")[0].split()
        if f:
            a = int(f[0], 16)
            hooked |= {n for s0, sz, n in _sa if s0 <= a < s0 + sz}
except FileNotFoundError:
    pass
# drafts known to break the game (found by boot tests): keep them asm. NM_SKIP=a,b adds more for a test.
SKIP = set(filter(None, os.environ.get("NM_SKIP", "").split(","))) | set(
    l.split()[0] for l in (R / "logs/nm_skip.txt").read_text().splitlines() if l.strip() and not l.startswith("#")
) if (R / "logs/nm_skip.txt").exists() else set(filter(None, os.environ.get("NM_SKIP", "").split(",")))

def header_for(rel):
    return "online/net.h" if rel == "src/online/net.c" else "common.h"

def apply(src):
    rel = str(src.relative_to(R)); slug = rel.replace("/", "_")
    drafts = R / f"logs/auto/{slug}.drafts.c"
    text = src.read_text()
    names = re.findall(r'^INCLUDE_ASM\("[^"]*", (\S+)\);', text, re.M)
    st = dict(asm=len(names), used=0, no_draft=0, no_compile=0, dropped=0, kept_asm=0)
    if not names: return st
    blocks = re.split(r"^//@@ (\S+)[^\n]*\n", drafts.read_text(), flags=re.M)[1:] if drafts.exists() else []
    # hand-written C (tools/nm/hand/<slug>.c, same //@@ format) goes first: tried before the m2c drafts
    hand = R / f"logs/hand/{slug}"                # src/tmb/mathf.c -> logs/hand/src_tmb_mathf.c (as tools/nm/hand)
    if not hand.exists(): hand = R / f"logs/hand/{slug}.c"
    handb = re.split(r"^//@@ (\S+)[^\n]*\n", hand.read_text(), flags=re.M)[1:] if hand.exists() else []
    handn = set(handb[0::2]); blocks = handb + blocks
    variants = {}
    for n, c in zip(blocks[0::2], blocks[1::2]):
        c = c.rstrip() + "\n"
        if bytefix and n not in handn:                 # (hand-written C is already right)
            c2, ch = bytefix(c)
            if ch: st["bytefix"] = st.get("bytefix", 0) + 1; c = c2
        variants.setdefault(n, []).append(c)
    hdr = header_for(rel); chosen = {}
    for n in names:
        if n in hooked or n in SKIP or ((n.endswith("Asm") or "Asm__" in n) and n not in handn): st["kept_asm"] += 1; continue
        if n not in variants: st["no_draft"] += 1; continue
        for c in variants[n]:
            if re.search(r"\bM2C_(BREAK|ERROR|TRAP|SYNC|UNK_)\w*\s*\(", c): continue   # m2c placeholders: compile, never link
            (W / "one.c").write_text(f'#include "{hdr}"\n{c}')
            if cc(W / "one.c")[0]: chosen[n] = c; break
        else: st["no_compile"] += 1
    # a function's .s can carry its own rodata (strings, constants, jump tables) ahead of the code; other code
    # and the data pointer tables use those symbols, so the C version keeps that rodata: <name>_nmro.s (jump
    # tables dropped - they point at labels inside the asm being replaced)
    ro = {}
    for n in chosen:
        m = re.search(rf'^INCLUDE_ASM\("([^"]*)", {re.escape(n)}\);', text, re.M)
        sf = Path(m.group(1)) / f"{n}.s" if m else None
        if not sf or not sf.exists(): continue
        t = sf.read_text()
        if ".section .rodata" not in t: continue
        part = t[t.index(".section .rodata"):t.index(".section .text")] if ".section .text" in t else ""
        blocks_ = re.split(r"(?=^(?:\.align \d+\n)?nonmatching )", part, flags=re.M)
        keep = [b for b in blocks_ if not re.search(r"\.word\s+\.L", b)]
        body = "".join(keep).strip()
        if not body.startswith(".section"): body = ".section .rodata\n" + body
        if "dlabel" not in body: continue
        (sf.parent / f"{n}_nmro.s").write_text(body + "\n.section .text\n")
        ro[n] = f'INCLUDE_ASM("{m.group(1)}", {n}_nmro);\n'
    # NM_BENCH=1 (function test bench, tools/nm/bench): the asm keeps the name, so every caller still runs the
    # original; the draft is linked beside it as <name>__c. That build boots like the asm one, and its snapshot
    # holds both versions for the bench to run side by side.
    bench = os.environ.get("NM_BENCH") == "1"
    def block(n, c, inc):
        if bench:
            return f"#ifdef NON_MATCHING\n{inc}\n#define {n} {n}__c\n/* NM:{n} */\n{c}#undef {n}\n#else\n{inc}\n#endif\n"
        return f"#ifdef NON_MATCHING\n/* NM:{n} */\n{ro.get(n, '')}{c}#else\n{inc}\n#endif\n"
    # in context: compile the whole file with NON_MATCHING, drop blocks the compiler names, repeat
    for _ in range(40):
        new = text
        for n, c in chosen.items():
            new = re.sub(rf'^(INCLUDE_ASM\("[^"]*", {re.escape(n)}\);)\n',
                         lambda m: block(n, c, m.group(1)), new, count=1, flags=re.M)
        src.write_text(new)
        ok, err = cc(src, ["-DNON_MATCHING"], whole=True)
        if ok: break
        if os.environ.get('NM_DEBUG'): print('\n'.join(l for l in err.splitlines() if 'warning' not in l)[:3000])
        lines = new.splitlines(); bad = set()
        for m in re.finditer(rf"{re.escape(rel)}:(\d+): (?!warning)", err):
            ln = int(m.group(1)) - 1
            for k in range(min(ln, len(lines) - 1), -1, -1):      # the NM block this line belongs to
                mm = re.match(r"/\* NM:(\S+) \*/", lines[k])
                if mm: bad.add(mm.group(1)); break
                if lines[k].startswith("#endif") and k != ln: break
        if not bad:                                                  # an error outside our blocks: give up on the file
            src.write_text(text); st["dropped"] += len(chosen); chosen = {}; break
        for n in bad: chosen.pop(n, None); st["dropped"] += 1
    else:
        src.write_text(text); st["dropped"] += len(chosen); chosen = {}
    # (the drafts carry their own #include "m2c_macros.h")
    # the normal build must not see any of it
    ok, err = cc(src, whole=True)
    if not ok: src.write_text(text); st["dropped"] += len(chosen); chosen = {}
    st["used"] = len(chosen)
    return st

if __name__ == "__main__":
    files = [Path(a).resolve() for a in sys.argv[1:]] or \
        sorted(p for p in (R / "src").rglob("*.c") if (R / f"logs/auto/{str(p.relative_to(R)).replace('/', '_')}.drafts.c").exists())
    summary = {}
    for f in files:
        summary[str(f.relative_to(R))] = s = apply(f)
        print(f"{f.relative_to(R)}: {s}", flush=True)
    tot = {k: sum(s[k] for s in summary.values()) for k in ("asm", "used", "no_draft", "no_compile", "dropped", "kept_asm")}
    print("TOTAL", tot)
    (W / "summary.json").write_text(json.dumps(dict(files=summary, total=tot), indent=1))
