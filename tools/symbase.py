# ruff: noqa
"""symbase.py: pick the symbol an absolute in-image address should be expressed relative to, so it moves
with the object it belongs to. Inside a sized object -> that object. Otherwise (gap, start of an unsized
object, section start) -> the NEXT real symbol, since an unlabeled address usually starts what follows."""

import re
import bisect
import subprocess


def load(elf):
    out = subprocess.run(
        ["mips-linux-gnu-nm", "-n", "-S", elf], capture_output=True, text=True
    ).stdout
    syms = []
    for l in out.splitlines():
        s = l.split()
        if len(s) == 4:
            a, z, t, n = s
            z = int(z, 16)
        elif len(s) == 3:
            a, t, n = s
            z = 0
        else:
            continue
        if (
            t.isupper()
            and t != "A"
            and re.fullmatch(r"[A-Za-z_]\w*", n)
            and not n.startswith("P_")
        ):
            syms.append((int(a, 16), z, n))
    syms.sort()
    return syms


class Base:
    def __init__(self, elf):
        self.s = load(elf)
        self.a = [x[0] for x in self.s]
        self.exact = {}
        for a, z, n in self.s:
            self.exact.setdefault(a, n)

    def expr(self, v, avoid=None):
        if v in self.exact and self.exact[v] != avoid:
            return self.exact[v]
        i = bisect.bisect_right(self.a, v) - 1
        # inside a sized object (look back a few: several symbols can share an address)
        for j in range(i, max(i - 8, -1), -1):
            a, z, n = self.s[j]
            if n != avoid and a <= v < a + z:
                return f"{n} + 0x{v - a:X}"
        k = bisect.bisect_right(self.a, v)
        while k < len(self.s) and self.s[k][2] == avoid:
            k += 1
        if k < len(self.s):
            a, z, n = self.s[k]
            return f"{n} - 0x{a - v:X}"
        a, z, n = self.s[i]
        return f"{n} + 0x{v - a:X}"
