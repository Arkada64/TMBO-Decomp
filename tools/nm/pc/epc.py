import zipfile, struct, sys, subprocess, bisect
z = zipfile.ZipFile(sys.argv[1]); d = z.read('PCSX2 Internal Structures.dat')
t = d.find(b'cpuRegs\x00'); b = t + 0x20
cp0 = struct.unpack_from('<32I', d, b + 512 + 32)
g = lambda r: struct.unpack_from('<I', d, b + 16 * r)[0]
out = subprocess.run(['nm', '-n', '/mnt/c/Users/Ark/Desktop/TMB Decomp/test/QUICK.ELF'], capture_output=True, text=True).stdout
s = [(int(p[0], 16), p[2]) for p in (l.split() for l in out.splitlines()) if len(p) == 3 and p[1] in 'tTwW']
a = [x for x, _ in s]
def nm(v):
    i = bisect.bisect_right(a, v) - 1
    return '%08x %s+0x%x' % (v, s[i][1], v - s[i][0])
print('EPC', nm(cp0[14]), ' Cause', hex(cp0[13]), ' Status', hex(cp0[12]), ' ErrorEPC', hex(cp0[30]))
print('pc', hex(struct.unpack_from('<I', d, b + 512 + 32 + 128 + 8)[0]))
