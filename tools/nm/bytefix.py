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
    return out, changed

if __name__ == "__main__":
    import sys
    s = open(sys.argv[1]).read()
    o, c = bytefix(s)
    print(o); print("// bytefix:", c, file=sys.stderr)
