#!/usr/bin/env python3
"""
make_context.py: build an m2c context of function prototypes for every named function.
  - parameter types from the GCC 2.x mangled name (fooBar__7VehicleiPf -> (void* this, int, float*))
  - return type from the callee's own code: last write to $f0 -> float, to $v0 -> int, else void
Writes logs/ctx/m2c_ctx.c (pycparser-friendly) and logs/ctx/protos.json {name: [ret, [params]]}.
"""
import re, json
from pathlib import Path
R = Path.home() / "tmbo_decomp"; OUT = R / "logs/ctx"; OUT.mkdir(parents=True, exist_ok=True)
BASIC = {"i": "int", "f": "float", "d": "double", "c": "char", "s": "short", "l": "int", "x": "long long",
         "b": "int", "v": "void", "w": "short", "e": "...", "r": "double"}

def parse_type(s, k, args):
    """returns (ctype, new_k) or raises ValueError"""
    ptr, uns = 0, ""
    while k < len(s) and s[k] in "PRCVSU":
        if s[k] in "PR": ptr += 1
        elif s[k] == "U": uns = "unsigned "
        elif s[k] == "S": uns = "signed "
        k += 1
    if k >= len(s): raise ValueError
    ch = s[k]
    if ch in BASIC:
        t = BASIC[ch]; k += 1
        if t in ("float", "double", "void", "...", "long long") and uns: t = uns + t if t == "long long" else t
        elif uns: t = uns + t
        if t == "..." and ptr == 0: return "...", k
    elif ch.isdigit():
        j = k
        while s[j].isdigit(): j += 1
        n = int(s[k:j]); k = j + n; t = "void"          # class/struct/enum by name
        if ptr == 0: t = "int"                          # enums (and small structs by value: rare)
    elif ch == "Q":                                     # Q<n><len><name>...
        n = int(s[k + 1]); k += 2
        for _ in range(n):
            j = k
            while s[j].isdigit(): j += 1
            k = j + int(s[k:j])
        t = "void" if ptr else "int"
    elif ch == "A":                                     # array: A<n>_<type>
        j = s.index("_", k); t2, k = parse_type(s, j + 1, args); t = t2.rstrip("*").strip(); ptr += 1
    elif ch == "F":                                     # function pointer: F<params>_<ret>
        depth, j = 0, k + 1
        j = s.index("_", j)                             # crude: params end at first '_'
        _, k = parse_type(s, j + 1, args) if j + 1 < len(s) else ("void", j + 1)
        return "void*", k
    else:
        raise ValueError
    if t == "void" and ptr == 0: return "void", k
    return t + "*" * ptr, k

def parse_params(s):
    out, k = [], 0
    if s == "v": return []
    while k < len(s):
        if s[k] == "T":                                 # T<n>: same type as arg n (1-based, this counts)
            n = int(s[k + 1]); k += 2; out.append(out[n - 1] if n - 1 < len(out) else "int"); continue
        if s[k] == "N":                                 # N<count><n>: repeat arg n count times
            c, n = int(s[k + 1]), int(s[k + 2]); k += 3
            out += [out[n - 1] if n - 1 < len(out) else "int"] * c; continue
        t, k = parse_type(s, k, out); out.append(t)
    return out

def demangle(name):
    m = re.match(r"^(\w+?)__(F|\d+\w*?|Q\d\w*?)(\w*)$", name)
    if not m: return None
    base, kind = m.group(1), m.group(2)
    rest = name[len(base) + 2:]
    if rest.startswith("F"): return parse_params(rest[1:])
    # method: <len><Class><params>  (this pointer first)
    k = 0
    if rest[0] == "Q":
        n = int(rest[1]); k = 2
        for _ in range(n):
            j = k
            while rest[j].isdigit(): j += 1
            k = j + int(rest[k:j])
    else:
        j = 0
        while rest[j].isdigit(): j += 1
        k = j + int(rest[:j])
    if rest[k:k + 1] == "C": k += 1                     # const method
    return ["void*"] + parse_params(rest[k:])

def ret_type(asm):
    lines = [l for l in asm.splitlines() if re.search(r"\*/\s+\w", l)]
    if not lines: return "int"
    # look at the last 6 instructions before (and in the delay slot of) the final jr $31
    tail = "\n".join(l for l in lines[-14:] if not re.search(r"\s(lq|ld|lw)\s+\$(16|17|18|19|20|21|22|23|30|31)\b|\$29, \$29", l))
    # $f0 is also a common temp on the EE, so an int return ($v0) wins
    if re.search(r"\s(addiu|addu|move|or|lw|lh|lhu|lb|lbu|li|lui|sltu?i?|andi|ori|xori|daddu|mfc1|sll|srl|sra|subu|negu|and|nor)\s+\$(2|v0)\b", tail): return "int"
    if re.search(r"\b(mov\.s|add\.s|sub\.s|mul\.s|div\.s|lwc1|mtc1|cvt\.s\.w|neg\.s|abs\.s)\s+\$f0\b", tail): return "float"
    return "void"

asm_files = {p.stem: p for p in (R / "asm").rglob("*.s")}
protos, bad = {}, 0
for l in (R / "config/US/symbol_addrs.txt").read_text().splitlines():
    m = re.match(r"\s*(\w+)\s*=\s*0x[0-9A-Fa-f]+;.*type:func", l)
    if not m or "__" not in m.group(1): continue
    n = m.group(1)
    if n.startswith("__") or "__op" in n or "__tf" in n or "__ti" in n: continue
    try:
        ps = demangle(n)
    except (ValueError, IndexError):
        ps = None
    if ps is None or any(p == "..." for p in ps[:-1]): bad += 1; continue
    rt = ret_type(asm_files[n].read_text()) if n in asm_files else "int"
    protos[n] = [rt, ps]
lines = []
for n, (rt, ps) in sorted(protos.items()):
    args = ", ".join(f"{p} arg{i}" if p != "..." else "..." for i, p in enumerate(ps)) or "void"
    lines.append(f"{rt} {n}({args});")
(OUT / "m2c_ctx.c").write_text("\n".join(lines) + "\n")
(OUT / "protos.json").write_text(json.dumps(protos))
rts = {}
for rt, _ in protos.values(): rts[rt] = rts.get(rt, 0) + 1
print(f"{len(protos)} prototypes ({bad} names not parsed); returns: {rts}")
