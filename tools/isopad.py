"""Pad an ISO with zero blocks at the end (and grow the PVD volume size): the game reads some small files (the
ped spawn files, last on the test disc) in whole chunks that run past the file, and past the image end PCSX2
returns errors forever (Prison Ship hung loading).  python3 isopad.py IMAGE.iso [blocks=64]"""
import struct, sys
S = 2048; N = int(sys.argv[2]) if len(sys.argv) > 2 else 64
f = open(sys.argv[1], 'r+b'); size = f.seek(0, 2)
assert size % S == 0
f.write(b'\0' * S * N)
f.seek(16 * S); pvd = bytearray(f.read(S))
vol = size // S + N
struct.pack_into('<I', pvd, 80, vol); struct.pack_into('>I', pvd, 84, vol)
f.seek(16 * S); f.write(pvd); f.close()
print(sys.argv[1], 'blocks', size // S, '->', vol)
