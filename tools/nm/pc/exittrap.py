# exittrap.py ELF : turn the game's exit syscalls (Exit, LoadExecPS2, ExecPS2) into a stop: di; b .; nop
# A test build that exits to the BIOS then freezes inside the stub instead, so the kept savestate still has the
# exiting thread's registers and stack (exitwho.py names the callers). Test builds only.
import struct, subprocess, sys
elf = sys.argv[1]
d = bytearray(open(elf, 'rb').read())
phoff, = struct.unpack_from('<I', d, 0x1C); phnum, = struct.unpack_from('<H', d, 0x2C)
segs = [struct.unpack_from('<IIIII', d, phoff + 32 * i) for i in range(phnum)]   # type off vaddr paddr filesz
def off(v):
    for t, o, va, pa, fs in segs:
        if t == 1 and va <= v < va + fs: return o + v - va
    raise SystemExit('exittrap: %x not in a load segment' % v)
syms = {}
for l in subprocess.run(['nm', elf], capture_output=True, text=True).stdout.splitlines():
    p = l.split()
    if len(p) == 3: syms[p[2]] = int(p[0], 16)
for name in ('Exit', 'LoadExecPS2', 'ExecPS2'):
    if name not in syms: print('exittrap: no', name); continue
    o = off(syms[name])
    struct.pack_into('<III', d, o, 0x42000039, 0x1000FFFF, 0)    # di ; b . ; nop
    print('exittrap: %s at %x' % (name, syms[name]))
open(elf, 'wb').write(d)
