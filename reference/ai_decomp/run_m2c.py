import os, re, subprocess, sys
import os
R = os.environ.get("TMBO", os.path.expanduser("~/tmbo_decomp")); M2C = os.environ.get("M2C", "m2c.py")
DIRS = {"ai": "Vehicle*", "driver": "Driver*", "game": "TheGame*"}
EXTRA = {  # functions outside these dirs that the AI calls, with known first argument
 "func_00130E88": "void func_00130E88(Driver*, s32);", "func_00130C00": "void func_00130C00(Driver*, Vehicle*);",
 "func_0010B950": "s32 func_0010B950(void*, FVECTOR*);", "func_001054E8": "void func_001054E8(Vehicle*);",
 "gamePickCruiseZone__7TheGameP7Vehiclei": "void gamePickCruiseZone__7TheGameP7Vehiclei(TheGame*, Vehicle*, s32);",
 "gameClearCruiseZone__7TheGameP7Vehiclei": "void gameClearCruiseZone__7TheGameP7Vehiclei(TheGame*, Vehicle*, s32);",
 "mathfManhatDist__FP8_fvectorT0": "f32 mathfManhatDist__FP8_fvectorT0(FVECTOR*, FVECTOR*);",
 "hdLosTest__FP8_fvectorT0P9_hdResulti": "s32 hdLosTest__FP8_fvectorT0P9_hdResulti(FVECTOR*, FVECTOR*, void*, s32);",
 "mathfRand__Fii": "s32 mathfRand__Fii(s32, s32);",
}
def first_arg(name, d):
    if "__7Vehicle" in name: return "Vehicle*"
    if "__6Driver" in name: return "Driver*"
    if "__7TheGame" in name: return "TheGame*"
    return DIRS[d]
files = []
protos = []
for d in DIRS:
    for f in sorted(os.listdir(f"{R}/asm/nonmatchings/tmb/{d}")):
        n = f[:-2]
        files.append((d, n))
        if n in EXTRA: continue
        protos.append(f"s32 {n}({first_arg(n, d)} arg0, ...);")
ctx = open("ctx_types.h").read() + "\nextern TheGame* D_004FA030;\n" + "\n".join(EXTRA.values()) + "\n" + "\n".join(protos) + "\n"
open("ctx_full.h", "w").write(ctx)
os.makedirs("out", exist_ok=True)
ok = bad = 0
for d, n in files:
    src = f"{R}/asm/nonmatchings/tmb/{d}/{n}.s"
    body = "".join(l for l in open(src) if not l.startswith(".include"))
    open("/tmp/f.s", "w").write('.set noat\n.set noreorder\n.section .text, "ax"\n' + body)
    r = subprocess.run([sys.executable, M2C, "-t", "mipsee-gcc-c", "--pointer-style", "left", "--context", "ctx_full.h",
                        "/tmp/f.s", "-f", n], capture_output=True, text=True)
    out = r.stdout if r.stdout.strip() else r.stderr
    if r.returncode or "Decompilation failure" in out: bad += 1
    else: ok += 1
    open(f"out/{d}__{n}.c", "w").write(out)
print("ok", ok, "failed", bad)
