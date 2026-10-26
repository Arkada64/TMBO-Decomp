#!/usr/bin/env python3
"""splitpatch.py IN.ELF OUT.ELF VIEWS [GUESTS [CAR2 CAR3 CAR4]] : split-screen test settings in a copy of the ELF.
VIEWS: extra views following bots (mods/freecam.c tmbr_split). GUESTS: local guest players on controllers 2-4
(mods/guests.c tmbr_guests); CARn = character number (0 = random)."""
import sys, struct
d = bytearray(open(sys.argv[1], 'rb').read())
def put(tag, vals):
    t = struct.pack('<I', tag); o = d.find(t)
    assert o >= 0 and d.find(t, o + 1) < 0, 'tag %08x not found (or twice)' % tag
    for i, v in enumerate(vals): struct.pack_into('<i', d, o + 4 + 4 * i, v)
put(0x54494C53, [int(sys.argv[3])])
if len(sys.argv) > 4:
    cars = [int(x) << 5 for x in sys.argv[5:8]] + [0] * 3
    put(0x53545347, [int(sys.argv[4])] + cars[:3])
open(sys.argv[2], 'wb').write(d)
print('split: %s views %s guests %s' % (sys.argv[2], sys.argv[3], ' '.join(sys.argv[4:]) or '0'))
