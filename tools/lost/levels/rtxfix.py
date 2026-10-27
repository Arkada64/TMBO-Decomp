"""Repair a merged level RTX (Lost maps on the DEATH4 donor, built before 2026-10-26):
  python3 rtxfix.py IN.RTX OUT.RTX
A TEX / RTX record list ends with a record whose sizew is 0 (it runs to the end of the file; texmResRelocate /
texmRelocate stop after it). lvbuild's merge copied the donor's records unchanged and appended ours, so DEATH4's
old last RTX record (a VRAM-resident PSMT4HH texture) kept sizew 0 in the middle of the list: the game stopped
there and never uploaded any of the converted map's CLUTs. Every record but the real last one gets its size back."""
import sys, os, struct
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from textconv import rtx_rec_size


def fix(d):
    d = bytearray(d); o = 0; fixed = []; n = 0
    while o + 16 <= len(d):
        sz, key, gs = struct.unpack_from('<IIQ', d, o)
        if sz == 0 and gs == 0: break
        b = sz * 4 if sz else rtx_rec_size(gs)
        if sz == 0:
            nxt = o + b
            if nxt + 16 <= len(d) and struct.unpack_from('<Q', d, nxt + 8)[0]:   # more records follow
                struct.pack_into('<I', d, o, b // 4); fixed.append((n, o, b))
            else:
                break                                                            # the real last record
        o += b; n += 1
    return bytes(d), fixed, n + 1


if __name__ == '__main__':
    d, fixed, n = fix(open(sys.argv[1], 'rb').read())
    open(sys.argv[2], 'wb').write(d)
    print(sys.argv[1], 'records', n, 'fixed (index, offset, bytes)', fixed)
