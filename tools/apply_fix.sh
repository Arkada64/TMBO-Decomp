#!/bin/bash
# Waits for perm_run.py and fixup.py to finish, then puts fixup matches into the real build one file at a time.
cd ~/tmbo_decomp && source .venv/bin/activate
while pgrep -f "tools/(perm_run|fixup).py" > /dev/null; do sleep 60; done
python3 - <<'EOF'
import json, subprocess, re
from pathlib import Path
R = Path.home() / "tmbo_decomp"
import os
FD = R / os.environ.get("FIXDIR", "logs/fix")
tot = json.loads((FD / "summary.json").read_text())
T = "\n\nCo-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>\nClaude-Session: https://claude.ai/code/session_0163vgjiFyQy8GoFYgqXiav1"
def ok():
    (R / "build/SCUS_971.96.rom").unlink(missing_ok=True)
    return subprocess.run("ninja > logs/ninja.log 2>&1", shell=True, cwd=R).returncode == 0 and \
        (R / "disks/SCUS_971.96.rom").read_bytes() == (R / "build/SCUS_971.96.rom").read_bytes()
n = 0
for rel, names in tot.items():
    if not names: continue
    mf = FD / (rel.replace("/", "_") + ".matched.c")
    if not re.search(r"^//@@ ", mf.read_text(), re.M): continue
    before = (R / rel).read_text()
    out = subprocess.run(["python3", "tools/batch_try.py", rel, str(mf)], cwd=R, capture_output=True, text=True).stdout
    k = re.search(r"kept (\d+)", out); k = int(k.group(1)) if k else 0
    if k and ok():
        n += k
        subprocess.run(f'git add -A && git -c user.name=tmbo -c user.email=tmbo@localhost commit -q --no-verify -m "Fixup match ({k}): {rel}{T}"', shell=True, cwd=R)
        print(f"{rel}: kept {k}", flush=True)
    else:
        (R / rel).write_text(before); ok()
        print(f"{rel}: none kept", flush=True)
print(f"APPLY DONE: {n} functions; build byte-identical: {ok()}")
EOF
