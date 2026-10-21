#!/usr/bin/env python3
"""
RETAIL: m2c drafts for every function in a whole-file asm (asm/tmb/ui.s), as '//@@ NAME m2c' blocks
for fast_match.py. Retail asm is one .s per translation unit (no per-function nonmatchings), so this
splits it itself. Drafts are C: mangled C++ names (uiMain__Fv) are valid C identifiers, and
EE-GCC 2.9 emits the same code for a C function as for the C++ one (methods: `this` is arg0).
Every symbol a draft declares gets a private alias bound to the real one with an asm label, so
drafts never clash with each other or with the header.
Two variants per function (fast_match keeps the first MATCH):
  proto  callees get prototypes decoded from their mangled names (gcc2_mangle.py) and are `void`
         when the draft never uses their result (v0/v1 allocation depends on it)
  plain  m2c's unprototyped declarations
Data externs become byte arrays (BYTE_DATA=0 to disable), see below.
Usage: auto_m2c.py ASM.s OUT.c [max_size_bytes]
Env: M2C_CONTEXT (context file for m2c), M2C_TARGET (default mipsee-gcc-c), SHOW_ERR=1
"""
import re, subprocess, sys, os
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
from gcc2_mangle import params as mangled_params
asm, out = Path(sys.argv[1]), Path(sys.argv[2])
max_size = int(sys.argv[3]) if len(sys.argv) > 3 else 1 << 30
TMP = Path.home() / "tmb_decomp/logs/m2c_tmp"; TMP.mkdir(parents=True, exist_ok=True)
text = asm.read_text(errors="replace").split(".section .rodata")[0]
parts = re.split(r"^(?:\.align \d+\n)?nonmatching (\S+), (0x[0-9A-Fa-f]+)\n", text, flags=re.M)
funcs = [(parts[i], int(parts[i + 1], 16), parts[i + 2]) for i in range(1, len(parts), 3)]
_c = os.environ.get("M2C_CONTEXT", str(Path.home() / "tmb_decomp/logs/ctx/retail_protos.h"))
ctx = ["--context", _c] if _c and Path(_c).exists() else []   # M2C_CONTEXT= (empty) to skip

SZ = {"s8": 1, "u8": 1, "char": 1, "s16": 2, "u16": 2, "M2C_UNK16": 2, "s32": 4, "u32": 4, "f32": 4,
      "M2C_UNK": 4, "M2C_UNK32": 4, "s64": 8, "u64": 8, "f64": 8, "M2C_UNK64": 8}
def scale_ptrs(code):
    """(from online fixup.py, 'P') m2c writes pointer arithmetic in BYTES; on a typed pointer C scales
    it: divide the constant by the element size (var += 0x10 on s32* -> var += 4)."""
    ptrs = {}
    for m in re.finditer(r"\b(\w+)\s*(\*+)\s*(\w+)\s*[;,)=]", code):
        t, stars, v = m.groups()
        size = 4 if len(stars) > 1 else SZ.get(t)
        if size and size > 1: ptrs[v] = size
    for v, s in ptrs.items():
        def g(m):
            k = int(m.group(3), 0)
            return m.group(0) if k % s else f"{m.group(1)}{m.group(2)}{hex(k // s)}"
        code = re.sub(rf"(\b{v}\s*)(\+=|-=|\+ |- )\s*(0x[0-9A-Fa-f]+|\d+)\b(?!\s*\*)", g, code)
    return code

def build(name, code, body_s, sfx, proto):
    lines, aliases, datas = [], {}, []
    fn_text = code[code.find(f"{name}("):] if f"{name}(" in code else code
    for l in code.splitlines():
        m = re.match(r"^(.*?)\b([A-Za-z_]\w*)(\(.*\));\s*/\* extern \*/$", l)        # function decl
        d = re.match(r"^extern (.*?)\b([A-Za-z_]\w*)((?:\[[^\]]*\])*);", l)           # data decl
        if m:
            real, alias = m.group(2), f"{m.group(2)}_{sfx}"
            aliases[real] = alias
            ps = mangled_params(real) if proto else None
            if ps is not None:
                # result used anywhere other than as a bare statement?
                used = any(not re.match(r"\s*$", fn_text[max(0, x.start() - 200):x.start()].split("\n")[-1])
                           for x in re.finditer(rf"\b{re.escape(real)}\(", fn_text))
                ret = m.group(1).strip() if used else "void"
                l = f'{ret} {alias}({", ".join(ps) or "void"}) __asm__("{real}");'
            else:
                l = f'{m.group(1)}{alias}() __asm__("{real}");'
        elif d and not d.group(3) and os.environ.get("BYTE_DATA", "1") == "1":
            # Data as a byte array: (1) the size decides addressing under -G8 (<=8 bytes -> $gp,
            # else lui/addiu), so match the original: [4] if the asm uses %gp_rel, [] otherwise;
            # (2) &x is then a u8*, so m2c's byte offsets (i * 0xC + &x) are right as written.
            real, alias = d.group(2), f"{d.group(2)}_{sfx}"
            aliases[real] = alias
            datas.append((alias, d.group(1).strip()))
            l = f'extern u8 {alias}[{4 if f"%gp_rel({real})" in body_s else ""}] __asm__("{real}");'
        elif d:
            aliases[d.group(2)] = f"{d.group(2)}_{sfx}"
            l = f'extern {d.group(1)}{d.group(2)}_{sfx}{d.group(3)} __asm__("{d.group(2)}");'
        lines.append(l)
    if proto:
        # with a context m2c knows the callees and doesn't declare them: add aliased prototypes
        for real in sorted(set(re.findall(r"\b(\w+__\w+)\(", fn_text))):
            if real == name or real in aliases: continue
            ps = mangled_params(real)
            if ps is None: continue
            alias = aliases[real] = f"{real}_{sfx}"
            used = any(not re.match(r"\s*$", fn_text[max(0, x.start() - 200):x.start()].split("\n")[-1])
                       for x in re.finditer(rf"\b{re.escape(real)}\(", fn_text))
            lines.insert(0, f'{"int" if used else "void"} {alias}({", ".join(ps) or "void"}) __asm__("{real}");')
    body = "\n".join(lines).strip()
    decl_end = max(body.find(f"{name}("), 0)
    head, rest = body[:decl_end], body[decl_end:]
    for real, alias in aliases.items():
        rest = re.sub(rf"\b{re.escape(real)}\b", alias, rest)
    for alias, typ in datas:
        # &x -> x (the array decays to u8*); a bare x is a value of m2c's type -> *(type*)x
        rest = re.sub(rf"&{alias}\b", "\0", rest)
        rest = re.sub(rf"(?<![\w.]){alias}\b", f"(*({typ}*){alias})", rest)
        rest = rest.replace("\0", f"((u8*){alias})")
    body = head + rest
    # m2c lists only the args it sees used; fill gaps (arg3 alone -> arg0..arg3) so registers line up
    def fill(m):
        ps = [p.strip() for p in m.group(2).split(",") if p.strip() and p.strip() != "void"]
        nums = {int(x.group(1)): p for p in ps if (x := re.search(r"\barg(\d+)$", p))}
        if not nums or len(nums) != len(ps): return m.group(0)
        return f"{m.group(1)}({', '.join(nums.get(i, f's32 arg{i}') for i in range(max(nums) + 1))}) {{"
    body = re.sub(rf"^(.*\b{re.escape(name)})\((.*)\) \{{", fill, body, count=1, flags=re.M)
    # bare `sp` = a local buffer at the bottom of the frame: declare it, sized from the frame minus saves
    if re.search(r"\bsp\b", body) and not re.search(r"\bsp\[", body):
        frame = re.search(r"addiu\s+\$(?:sp|29), \$(?:sp|29), -(0x[0-9A-F]+)", body_s)
        saves = len(re.findall(r"\b(?:sq|sd)\s+\$\w+, 0x[0-9A-F]+\(\$(?:sp|29)\)", body_s))
        room = int(frame.group(1), 16) - 16 * saves if frame else 0
        if room > 0:
            body = re.sub(rf"^(.*\b{re.escape(name)}\(.*\) \{{)$", lambda m: m.group(1) + f"\n    u8 sp[0x{room:X}];",
                          body, count=1, flags=re.M)
    return body

blocks, stats = [], {"ok": 0, "error": 0, "too_big": 0, "failed": 0}
for name, size, body_s in funcs:
    if size > max_size: stats["too_big"] += 1; continue
    tmp = TMP / f"{name[:120]}.s"
    tmp.write_text('.set noat\n.set noreorder\n.section .text, "ax"\n' + body_s)
    seen, err = [], ""
    def m2c(c):
        return subprocess.run([sys.executable, "-m", "m2c.main", "-t", os.environ.get("M2C_TARGET", "mipsee-gcc-c"),
                               "--valid-syntax", "--pointer-style", "left", *c, str(tmp), "-f", name],
                              capture_output=True, text=True)
    rn = m2c([])
    # ctx: m2c reads the decoded prototypes (args it can't see set, float args) + our proto decls;
    # proto: no context, but prototypes added to the draft; plain: m2c's own declarations
    for v, r in (("ctx", m2c(ctx) if ctx else None), ("proto", rn), ("plain", rn)):
        if r is None: continue
        if r.returncode or not r.stdout.strip() or "M2C_ERROR" in r.stdout:
            err = "error" if "M2C_ERROR" in r.stdout else "failed"
            if os.environ.get("SHOW_ERR"): print(name, v, r.stderr[-800:])
            continue
        b = build(name, r.stdout, body_s, f"{size:X}_{len(blocks)}", v != "plain")
        for vv, bb in ((v, b), (v + "P", scale_ptrs(b))):
            if bb in seen: continue
            seen.append(bb)
            blocks.append(f"//@@ {name} {vv}\n#include \"m2c_macros.h\"\n{bb}\n")
    if seen: stats["ok"] += 1
    else: stats[err or "failed"] += 1
out.write_text("".join(blocks))
print(f"{len(funcs)} functions in {asm} -> drafts written: {stats['ok']} ({len(blocks)} variants)  "
      f"(m2c gave up: {stats['error']}, m2c failed: {stats['failed']}, over size limit: {stats['too_big']})")
