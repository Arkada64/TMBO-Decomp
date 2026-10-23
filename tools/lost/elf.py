import struct,sys
import sys
d=open(sys.argv[1] if len(sys.argv)>1 and sys.argv[1].upper().startswith('SCUS') else 'SCUS_976.21','rb').read()
e_phoff=struct.unpack_from('<I',d,0x1c)[0]; n=struct.unpack_from('<H',d,0x2c)[0]
segs=[]
for i in range(n):
    t,off,va,pa,fs,ms=struct.unpack_from('<6I',d,e_phoff+32*i)
    if t==1: segs.append((va,off,fs))
def rd(a,cnt=1):
    for va,off,fs in segs:
        if va<=a<va+fs: return struct.unpack_from('<%dI'%cnt,d,off+a-va)
    raise KeyError(hex(a))
