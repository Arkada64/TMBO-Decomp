"""Re-pack a raw file into the game's zip-like container ('IE\\x03\\x04' local header, PK central dir)."""
import sys, struct, zlib
orig, raw, out = sys.argv[1:4]
b = open(orig, 'rb').read(); data = open(raw, 'rb').read()
nl, xl = struct.unpack_from('<HH', b, 26)
c = zlib.compressobj(9, zlib.DEFLATED, -15); comp = c.compress(data) + c.flush()
crc = zlib.crc32(data) & 0xffffffff
loc = bytearray(b[:30 + nl + xl]); struct.pack_into('<III', loc, 14, crc, len(comp), len(data))
csize_old = struct.unpack_from('<I', b, 18)[0]
tail = bytearray(b[30 + nl + xl + csize_old:])
cd = tail.find(b'PK\x01\x02'); struct.pack_into('<III', tail, cd + 16, crc, len(comp), len(data))
eo = tail.find(b'PK\x05\x06'); struct.pack_into('<I', tail, eo + 16, len(loc) + len(comp))
open(out, 'wb').write(bytes(loc) + comp + bytes(tail))
print(out, len(b), '->', len(loc) + len(comp) + len(tail))
