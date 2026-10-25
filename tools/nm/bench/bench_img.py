#!/usr/bin/env python3
"""
bench_img.py BASE.ELF OBJDIR OUT.ELF : link the bench's draft objects (nm_apply.py with NM_BENCH_OUT) into one image
at 0x02000000 - above the PS2's 32 MB, so it exists only in the bench's interpreter - with every reference to the
game resolved against BASE.ELF (the plain build the snapshot was taken with). Drafts that reference something the
game does not have are left out and listed.
"""
import os, subprocess, sys, tempfile
base, objdir, out = sys.argv[1:4]
def undefined(path):
    r = subprocess.run(['mips-linux-gnu-nm', '-u', path], capture_output=True, text=True).stdout
    return {l.split()[-1] for l in r.splitlines() if l.strip()}
have = {l.split()[-1] for l in subprocess.run(['mips-linux-gnu-nm', base], capture_output=True, text=True).stdout.splitlines() if l.strip()}
objs, left = [], []
for f in sorted(os.listdir(objdir)):
    if not f.endswith('.o'): continue
    p = os.path.join(objdir, f)
    miss = sorted(undefined(p) - have)
    if miss: left.append((f[:-2], miss[:3]))
    else: objs.append(p)
script = """SECTIONS {
  . = 0x02000000;
  .text : { *(.text) }
  .rodata : { *(.rodata*) *(.rdata*) }
  .data : { *(.data*) *(.sdata*) *(.lit4) *(.lit8) }
  .bss : { *(.bss*) *(.sbss*) *(.scommon) *(COMMON) }
  /DISCARD/ : { *(.reginfo) *(.mdebug*) *(.comment) *(.pdr) *(.gnu.attributes) *(.MIPS.*) }
}
"""
with tempfile.NamedTemporaryFile('w', suffix='.ld', delete=False) as t: t.write(script)
r = subprocess.run(['mips-linux-gnu-ld', '-EL', '-T', t.name, '--just-symbols=' + base, '-o', out, *objs],
                   capture_output=True, text=True)
print('bench image: %d drafts linked, %d left out (missing symbols)' % (len(objs), len(left)))
for n, m in left[:15]: print('  left out %s: needs %s' % (n, ', '.join(m)))
if r.returncode: print('LINK FAILED:', r.stderr[-2000:]); sys.exit(1)
print('BENCH_IMG_DONE', out)
