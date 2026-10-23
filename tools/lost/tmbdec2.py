"""TMB op0 packet -> batches (inverse of tmbenc.vif_packet)."""
import struct
from vif import parse
BASE=0x980000
def batches(n,node):
    pk=struct.unpack_from('<I',n,node+4)[0]-BASE
    qwc=struct.unpack_from('<I',n,pk)[0]&0xffff
    out=[];cur=None;b=None
    for r in parse(n,pk+8,pk+16+qwc*16):
        off,cmd,num,imm,p,pl=r
        if cmd==0x68: b={'pool':[struct.unpack_from('<3f',n,p+12*i) for i in range(num)],'strips':[]}; out.append(b)
        elif cmd==0x6c: cur={'tag':struct.unpack_from('<4I',n,p),'a':[],'c':[],'t':[]}
        elif cmd==0x6e and (imm&0x3ff)==1: cur['a']=[struct.unpack_from('<3bB',n,p+4*i) for i in range(num)]
        elif cmd==0x6e and (imm&0x3ff)==2: cur['c']=[struct.unpack_from('<4B',n,p+4*i) for i in range(num)]
        elif cmd==0x75: cur['t']=[struct.unpack_from('<2h',n,p+4*i) for i in range(num)]
        elif cmd==0x17 and cur and b is not None:
            b['strips'].append({'tag':cur['tag'],'v':list(zip(cur['a'],cur['c'],cur['t']))}); cur=None
    return out,pk,qwc
