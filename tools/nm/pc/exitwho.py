# exitwho.py RUNDIR ELF : if the run's savestate stopped in an exit trap (exittrap.py), name the call chain.
# Prints "exit chain: ..." and, for night.sh, a line "TMBR exit trap: TLB Miss (not a real one) pc=0x<addr>"
# naming the deepest C function in the chain (or the caller of the exit when none is C).
import bisect, struct, subprocess, sys, zipfile
run, elf = sys.argv[1], sys.argv[2]
try: z = zipfile.ZipFile(run + '/state.p2s')
except Exception: sys.exit(0)
st = z.read('PCSX2 Internal Structures.dat'); ram = z.read('eeMemory.bin')
i = st.find(b'cpuRegs\0'); b = i + 32
gpr = [struct.unpack_from('<I', st, b + 16 * k)[0] for k in range(32)]
pc = struct.unpack_from('<I', st, b + 512 + 32 + 128 + 8)[0]
s = []
for l in subprocess.run(['nm', '-n', elf], capture_output=True, text=True).stdout.splitlines():
    p = l.split()
    if len(p) == 3 and p[1] in 'tTwW': s.append((int(p[0], 16), p[2]))
a = [x for x, _ in s]
def sym(v):
    k = bisect.bisect_right(a, v) - 1
    return s[k][1] if k >= 0 else '?'
traps = {s[k][0] for k in range(len(s)) if s[k][1] in ('Exit', 'LoadExecPS2', 'ExecPS2')}
if not any(t <= pc < t + 12 for t in traps): sys.exit(0)        # not stopped in a trap
w = lambda v: struct.unpack_from('<I', ram, v & 0x1FFFFFF)[0]
def is_ret(v):                                                    # v follows a jal / jalr + delay slot
    if v & 3 or not (a[0] < v < a[-1]): return False
    ins = w(v - 8)
    return ins >> 26 == 3 or (ins >> 26 == 0 and ins & 0x3F == 9)
chain = [gpr[31]]
sp = gpr[29] & 0x1FFFFFF
for q in range(sp, min(sp + 0x800, len(ram) - 4), 4):
    v = w(q)
    if is_ret(v) and v not in chain: chain.append(v)
names = ['%x %s' % (v, sym(v)) for v in chain[:12]]
print('TMBR exit chain (%s): %s' % (sym(pc), ' <- '.join(names)))
# only C drafts (their /* NM:name */ markers in the build's sources) can be blamed; matched C and labels cannot
import glob, re, os
drafts = set()
for f in glob.glob(os.path.expanduser('/home/ark/nmhome/tmbo_decomp/src/**/*.c'), recursive=True):
    drafts |= set(re.findall(r'/\* NM:(\S+) \*/', open(f, errors='replace').read()))
c = [v for v in chain if sym(v) in drafts]
pick = c[0] if c else gpr[31]
print('TMBR exit trap: TLB Miss (not a real one) pc=0x%x' % pick)
