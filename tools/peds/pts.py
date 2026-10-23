import struct
def parse(d):
    pts = []
    for o in range(0, len(d) - 31, 32):
        x, y, z, w = struct.unpack_from('<4f', d, o)
        l = struct.unpack_from('<8H', d, o + 16)
        if x == 0 and y == 0 and z == 0 and l[7] == 0:
            break
        links = [k for k in l[:6] if k != 0xFFFF][:l[7]]
        pts.append(dict(p=(x, y, z), links=links, kind=l[6]))
    return pts
