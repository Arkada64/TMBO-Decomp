#!/usr/bin/env python3
"""
regen.py: regenerate m2c drafts for every still-asm function with the PS2 target (mipsee: EABI
argument registers t0-t3, f12+) and a prototype context from mangled names (make_context.py),
fast_match them, and put matches into the real build file by file (verified, one commit per file).
Drafts land in logs/auto_ee/ (fixup.py can then run over them with DRAFTDIR=logs/auto_ee).
Resumable: files listed in logs/auto_ee/done.txt are skipped.
"""
import os, re, subprocess, json
from pathlib import Path
R = Path.home() / "tmbo_decomp"; D = R / "logs/auto_ee"; D.mkdir(parents=True, exist_ok=True)
env = dict(os.environ, M2C_TARGET="mipsee-gcc-c", M2C_CONTEXT=str(R / "logs/ctx/m2c_ctx.c"),
           M2C_PROTOS=str(R / "logs/ctx/protos.json"))
T = "\n\nCo-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>\nClaude-Session: https://claude.ai/code/session_0163vgjiFyQy8GoFYgqXiav1"
def ok():
    (R / "build/SCUS_971.96.rom").unlink(missing_ok=True)
    return subprocess.run("ninja > logs/ninja.log 2>&1", shell=True, cwd=R).returncode == 0 and \
        (R / "disks/SCUS_971.96.rom").read_bytes() == (R / "build/SCUS_971.96.rom").read_bytes()
assert ok(), "build must be byte-identical first"
done = set((D / "done.txt").read_text().split()) if (D / "done.txt").exists() else set()
total = 0
for src in sorted((R / "src").rglob("*.c")):
    rel = str(src.relative_to(R)); slug = rel.replace("/", "_")
    if rel in done or not re.search(r"^INCLUDE_ASM", src.read_text(), re.M): continue
    hdr = "online/net.h" if rel == "src/online/net.c" else "common.h"
    dr, mf = D / f"{slug}.drafts.c", D / f"{slug}.matched.c"
    g = subprocess.run(["python3", "tools/auto_m2c.py", rel, hdr, str(dr)], cwd=R, env=env, capture_output=True, text=True)
    kept = 0
    if dr.exists():
        f = subprocess.run(["python3", "tools/fast_match.py", str(dr), str(mf), hdr], cwd=R, capture_output=True, text=True)
        if mf.exists() and re.search(r"^//@@ ", mf.read_text(), re.M):
            before = src.read_text()
            out = subprocess.run(["python3", "tools/batch_try.py", rel, str(mf)], cwd=R, capture_output=True, text=True).stdout
            k = re.search(r"kept (\d+)", out); kept = int(k.group(1)) if k else 0
            if kept and ok():
                subprocess.run(f'git add -A && git -c user.name=tmbo -c user.email=tmbo@localhost commit -q --no-verify -m "EE-target m2c match ({kept}): {rel}{T}"', shell=True, cwd=R)
            else:
                src.write_text(before); ok(); kept = 0
    total += kept
    with open(D / "done.txt", "a") as fh: fh.write(rel + "\n")
    print(f"{rel}: {g.stdout.strip()[:90]} | kept {kept} (total {total})", flush=True)
print(f"\nREGEN DONE: {total} functions matched; build byte-identical: {ok()}")
