#!/usr/bin/env python3
"""splitpatch.py IN.ELF OUT.ELF VIEWS : set the split-screen stress test's view count (mods/freecam.c tmbr_split)"""
import sys, struct
d = bytearray(open(sys.argv[1], 'rb').read())
tag = struct.pack('<I', 0x54494C53)
o = d.find(tag)
assert o >= 0 and d.find(tag, o + 1) < 0, 'tmbr_split tag not found (or twice)'
struct.pack_into('<i', d, o + 4, int(sys.argv[3]))
open(sys.argv[2], 'wb').write(d)
print('split: %s views %s' % (sys.argv[2], sys.argv[3]))
