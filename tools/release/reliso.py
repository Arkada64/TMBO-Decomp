"""release ISO: TMBR_TEST.iso with the mod ELF as the disc's boot executable (SYSTEM.CNF's ELF replaced)."""
import sys, struct, shutil, os, re
S = 2048
src, elf, out = sys.argv[1:4]
shutil.copyfile(src, out)
f = open(out, 'r+b')
f.seek(16 * S); pvd = bytearray(f.read(S))
vol = struct.unpack_from('<I', pvd, 80)[0]
root = pvd[156:190]; rl, rs = struct.unpack_from('<I', root, 2)[0], struct.unpack_from('<I', root, 10)[0]
f.seek(rl * S); d = bytearray(f.read(rs))
def find(name):
    o = 0
    while o < len(d):
        n = d[o]
        if n == 0: o = (o // S + 1) * S; continue
        nm = d[o + 33:o + 33 + d[o + 32]].decode(errors='replace')
        if nm.split(';')[0].upper() == name.upper(): return o
        o += n
    return None
o = find('SYSTEM.CNF'); l, sz = struct.unpack_from('<I', d, o + 2)[0], struct.unpack_from('<I', d, o + 10)[0]
f.seek(l * S); cnf = f.read(sz).decode(errors='replace'); print('SYSTEM.CNF:', cnf.strip().replace('\r', ' ').replace('\n', ' | '))
boot = re.search(r'cdrom0:\\\\?([A-Z0-9_.]+)', cnf).group(1); print('boot', boot)
o = find(boot); ol, osz = struct.unpack_from('<I', d, o + 2)[0], struct.unpack_from('<I', d, o + 10)[0]
data = open(elf, 'rb').read()
need = (len(data) + S - 1) // S
if need <= (osz + S - 1) // S: at = ol
else: at = vol
f.seek(at * S); f.write(data + b'\0' * (-len(data) % S))
end = max(vol, at + need)
pad = 512
f.seek(end * S); f.write(bytes(pad * S)); end += pad
struct.pack_into('<I', d, o + 2, at); struct.pack_into('>I', d, o + 6, at)
struct.pack_into('<I', d, o + 10, len(data)); struct.pack_into('>I', d, o + 14, len(data))
f.seek(rl * S); f.write(d)
struct.pack_into('<I', pvd, 80, end); struct.pack_into('>I', pvd, 84, end)
f.seek(16 * S); f.write(pvd); f.truncate(end * S); f.close()
print('boot ELF %s: %d bytes at LBA %d (was %d, %d bytes); volume %d -> %d sectors' % (boot, len(data), at, ol, osz, vol, end))
