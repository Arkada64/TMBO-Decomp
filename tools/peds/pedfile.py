import struct
def parse(d):
    assert struct.unpack_from('<I', d, 0)[0] == 0x10242000
    ng = d[4]; o = 5; gs = []
    for g in range(ng):
        npt, nent = d[o], d[o + 1]; o += 2
        bmin = struct.unpack_from('<4f', d, o); bmax = struct.unpack_from('<4f', d, o + 16); o += 32
        pts = []
        for i in range(npt):
            x, y, z, w = struct.unpack_from('<4f', d, o)
            rad = d[o + 16]; pad = d[o + 17:o + 24]; links = list(d[o + 24:o + 32])
            pts.append(dict(p=(x, y, z, w), rad=rad, pad=bytes(pad), links=links)); o += 32
        ents = [tuple(d[o + 3 * i:o + 3 * i + 3]) for i in range(nent)]; o += 3 * nent
        gs.append(dict(bmin=bmin, bmax=bmax, pts=pts, ents=ents))
    return gs, o
