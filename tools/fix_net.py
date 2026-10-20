#!/usr/bin/env python3
"""One-off repair of src/online/net.c: two auto-matched drafts conflict with earlier code."""
import re
from pathlib import Path
p = Path("src/online/net.c")
t = p.read_text()
# 1) call through an unprototyped pointer: same code, no prototype check
t, n1 = re.subn(r"^(\s*)func_0016D638\(\);", r"\1((void (*)())func_0016D638)();", t, flags=re.M)
# 2) the second D_003156C0 declaration: private alias for the rest of that draft
i = t.index("extern M2C_UNK D_003156C0;")
end = min(x for x in (t.find('#include "m2c_macros.h"', i + 1), t.find("INCLUDE_ASM(", i + 1)) if x != -1)
blk = t[i:end].replace("extern M2C_UNK D_003156C0;", 'extern M2C_UNK D_003156C0_a __asm__("D_003156C0");', 1)
blk = re.sub(r"\bD_003156C0\b(?!_a)(?![^\n]*__asm__)", "D_003156C0_a", blk)
t = t[:i] + blk + t[end:]
p.write_text(t)
print(f"call fixed: {n1}, alias block of {blk.count(chr(10))} lines")
