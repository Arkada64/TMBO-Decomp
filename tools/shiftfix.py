#!/usr/bin/env python3
"""m2c writes 64-bit asm shifts (dsll32 / dsrl32 / dsra32 = "shift 32 then N") as `(x << 0x2N)` on a
32-bit int, which is undefined behaviour in C. Two boot breaks were traced to exactly this
(fontDmaFontData__Fv, func_002029D8), and the draft corpus has ~68 such shifts.

Only shifts ABOVE 32 are rewritten. A shift by exactly 32 happens to survive gcc 2.95: the count wraps
mod 32, so `(s64)(x << 0x20) >> 0x20` evaluates to `(s64)x` - which is precisely the sign extension the
asm's dsll32/dsra32 pair performs. Rewriting those 51 sites only cost drafts that then failed to
compile (903 used instead of 921 for the same corpus), so they are left alone; the corrupting ones are
the tags and masks built with 0x25/0x28/0x30/0x38, where the wrapped shift changes the value.

Conservative otherwise: only parenthesised shifts whose left side has no parentheses (literals,
globals, simple arithmetic - what m2c emits for tags) and that carry no explicit 64-bit cast.
"""
import re

SHIFT = re.compile(r"\(([^()]*?)\s*(<<\s*0x((?:[0-9a-fA-F]+)))\s*\)")
CAST64 = re.compile(r"\b(?:s64|u64|M2C_UNK64)\b")


def shiftfix(code):
    """Return (fixed_code, sites_changed)."""
    changed = 0

    def repl(m):
        nonlocal changed
        lhs, shift, count = m.group(1), m.group(2), int(m.group(3), 16)
        if count <= 0x20 or CAST64.search(lhs):
            return m.group(0)
        changed += 1
        return f"(((s64)({lhs})) {shift})"

    return SHIFT.sub(repl, code), changed


if __name__ == "__main__":
    import sys
    from pathlib import Path

    total = 0
    verbose = "-v" in sys.argv
    for p in [a for a in sys.argv[1:] if a != "-v"]:
        for path in sorted(Path().glob(p)) if any(c in p for c in "*?") else [Path(p)]:
            code = path.read_text()
            out, n = shiftfix(code)
            if n:
                total += n
                print(f"{path}: {n} site(s)")
                if verbose:
                    for a, b in zip(code.splitlines(), out.splitlines()):
                        if a != b:
                            print(f"  - {a.strip()[:110]}\n  + {b.strip()[:110]}")
    print(f"total sites: {total}")
