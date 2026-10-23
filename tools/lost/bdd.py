import struct
def u32(d,o): return struct.unpack_from('<I',d,o)[0]
def bdd(path):
    d=open(path,'rb').read(); out={}; o=0
    while o+0x2c<=len(d):
        name=d[o:o+20].split(b'\0')[0].decode('latin1'); ext=d[o+20:o+28].split(b'\0')[0].decode('latin1')
        off,size=struct.unpack_from('<II',d,o+28)
        if not name or off==0 or off+size>len(d): break
        out[ext.lower()]=d[off:off+size]; o+=0x2c
    return out
