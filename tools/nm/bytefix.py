#!/usr/bin/env python3
"""m2c drafts do pointer +/- in BYTES (asm offsets), but C scales them by the pointee size: `s32* p; p -= 0x20`
moves 0x80. (2026-10-25: 4 boot-breaking drafts, e.g. func_00116038 `arg0 + 0x4260` on an s32* arg0.)
bytefix(code): every pointer with sized pointee (s16/s32/f32/..., pointers) that takes part in + / - becomes a
char* (byte arithmetic, as the asm), and its uses as that type are cast back: *p, p[i], p->x."""
import re
SIZED = r"(?:s16|u16|s32|u32|s64|u64|f32|f64|M2C_UNK16|M2C_UNK32|M2C_UNK64|M2C_UNK|[A-Za-z_]\w*\s*\*)"
DECL = re.compile(rf"\b({SIZED})\s*\*\s*([A-Za-z_]\w*)\b(?=\s*[;,=)\[])")

def bytefix(code):
    decls = {}
    for m in DECL.finditer(code):
        t, v = re.sub(r"\s+", "", m.group(1)), m.group(2)
        if t.rstrip("*") in ("char", "s8", "u8", "void", "M2C_UNK8") and not t.endswith("*"): continue
        decls.setdefault(v, t)
    out, changed = code, []
    for v, t in decls.items():
        # arithmetic on the pointer itself (not p->, not p == / p != compares, not p * x)
        if not re.search(rf"(?<![\w.>])\b{re.escape(v)}\s*(\+|-)(?![>=\-+])|\b{re.escape(v)}\s*(\+=|-=)", out):
            continue
        T = f"{t}*"
        # declaration / parameter: T* v -> char* v
        out = re.sub(rf"\b{re.escape(t)}\s*\*\s*{re.escape(v)}\b(?=\s*[;,=)\[])", f"char* {v}", out)
        # typed uses: p[i], p->x
        out = re.sub(rf"(?<![\w.>])\b{re.escape(v)}\s*\[", f"(({T}){v})[", out)
        out = re.sub(rf"(?<![\w.>])\b{re.escape(v)}\s*->", f"(({T}){v})->", out)
        # unary deref *p (a '*' not preceded by an operand: identifier, ')' or ']')
        res, i = [], 0
        for m in re.finditer(rf"\*\s*{re.escape(v)}\b(?!\s*\[)", out):
            j = m.start() - 1
            while j >= 0 and out[j] in " \t": j -= 1
            if j >= 0 and (out[j].isalnum() or out[j] in "_)]"): continue      # multiplication
            if j >= 0 and out[j] == "*" : continue                              # ** (pointer-to-pointer decl/deref)
            res.append(out[i:m.start()]); res.append(f"(*({T}){v})"); i = m.end()
        res.append(out[i:]); out = "".join(res)
        changed.append(v)
    # the same for addresses of variables: `(i << 5) + &D_002BD8C8` (an s32 / M2C_UNK global) is a byte offset in
    # the asm (func_001435D0 / func_0010C520: the level name table, wrong name -> exit to the BIOS)
    o2 = re.sub(r"(?<![\w)\]])&\s*([A-Za-z_]\w*)\b(?!\s*[\[.(]|\s*->)(?=\s*[+-](?![>=+-]))", r"(u8*)&\1", out)
    o2 = re.sub(r"([+-]\s*)&\s*([A-Za-z_]\w*)\b(?!\s*[\[.(]|\s*->)", r"\1(u8*)&\2", o2)
    if o2 != out: changed.append("&global"); out = o2
    # ... and a load / store through such an address keeps the global's own type: `*(i + (u8*)&G)` would read one
    # byte (before: a whole word at 4x the offset). Bench 10-25 (particleGetLensFlareInfo: a pointer table indexed
    # by bytes) - and the level name table loads of func_001435D0 / func_0010C520.
    if "(u8*)&" in out:
        res, i = [], 0
        while True:
            m = re.compile(r"\*\s*\(").search(out, i)
            if not m: break
            j = m.start() - 1
            while j >= 0 and out[j] in " \t": j -= 1
            unary = j < 0 or not (out[j].isalnum() or out[j] in "_)]")
            k, depth = m.end(), 1                      # the matching ')'
            while k < len(out) and depth:
                depth += {"(": 1, ")": -1}.get(out[k], 0); k += 1
            inner = out[m.end():k - 1]
            g = re.findall(r"\(u8\*\)&\s*([A-Za-z_]\w*)", inner)
            if unary and depth == 0 and len(g) == 1 and not inner.lstrip().startswith(("u8", "s8", "s16", "u16", "s32", "u32", "f32", "M2C", "void", "__typeof__")):
                arr = re.search(r"\bextern\b[^;\n]*\b" + re.escape(g[0]) + r"\s*\[", out)   # declared as an array: its element type
                ty = f"__typeof__({g[0]}[0])" if arr else f"__typeof__({g[0]})"
                res.append(out[i:m.start()]); res.append(f"*({ty}*)({inner})"); i = k
                changed.append("deref " + g[0])
            else:
                res.append(out[i:m.end()]); i = m.end()
        res.append(out[i:]); out = "".join(res)
    return out, changed

if __name__ == "__main__":
    import sys
    s = open(sys.argv[1]).read()
    o, c = bytefix(s)
    print(o); print("// bytefix:", c, file=sys.stderr)
