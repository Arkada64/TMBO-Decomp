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
R = Path.home() / "tmbo_decomp"
SN = "tools/compilers/ee-gcc2.95.3-114"
W = R / "logs/nm"; W.mkdir(parents=True, exist_ok=True)
CFLAGS = ["-O2", "-G0", "-fno-exceptions", "-Iinclude", "-isystem", "include/gcc", "-isystem", "include/gcc/gcc-lib",
          "-isystem", "include/sdk", "-isystem", "include/sdk/common", "-isystem", "include/sdk/ee"]

def cc(path, extra=()):
    obj = W / "t.o"; obj.unlink(missing_ok=True)
    r = subprocess.run([f"{R / SN}/bin/ee-gcc.exe", f"-B{SN}/lib/gcc-lib/ee/2.95.3/", "-c", *CFLAGS, *extra,
                        str(Path(path).relative_to(R)), "-o", str(obj.relative_to(R))], cwd=R, capture_output=True, text=True)
    return r.returncode == 0 and obj.exists(), r.stdout + r.stderr

# functions the mods patch in their .s files: keep them asm in every build
hooked = set(re.findall(r'A\("[^"]*/([A-Za-z_0-9]+)\.s"\)', (R / "tools/mods/apply_mods.py").read_text()))
hooked |= {"func_00127650"}          # the level loader (LOADER in apply_mods.py)

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
    variants = {}
    for n, c in zip(blocks[0::2], blocks[1::2]): variants.setdefault(n, []).append(c.rstrip() + "\n")
    hdr = header_for(rel); chosen = {}
    for n in names:
        if n in hooked or n.endswith("Asm") or "Asm__" in n: st["kept_asm"] += 1; continue
        if n not in variants: st["no_draft"] += 1; continue
        for c in variants[n]:
            (W / "one.c").write_text(f'#include "{hdr}"\n{c}')
            if cc(W / "one.c")[0]: chosen[n] = c; break
        else: st["no_compile"] += 1
    # in context: compile the whole file with NON_MATCHING, drop blocks the compiler names, repeat
    for _ in range(40):
        new = text
        for n, c in chosen.items():
            new = re.sub(rf'^(INCLUDE_ASM\("[^"]*", {re.escape(n)}\);)\n',
                         lambda m: f"#ifdef NON_MATCHING\n/* NM:{n} */\n{c}#else\n{m.group(1)}\n#endif\n", new, count=1, flags=re.M)
        src.write_text(new)
        ok, err = cc(src, ["-DNON_MATCHING"])
        if ok: break
        lines = new.splitlines(); bad = set()
        for m in re.finditer(rf"{re.escape(rel)}:(\d+):", err):
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
    ok, err = cc(src)
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
