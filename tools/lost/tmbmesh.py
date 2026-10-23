"""TMB (Black/Online) op0 HierObject mesh packet decode. polyPkt -> DMA ret tag {0x6000qqqq,0, UNPACK S-32 1 @0xB4, nverts}
VIF: UNPACK V3-32 pool @0xB5 (float xyz), MSCAL 0, STCYCL 1/3, strips: V4-32 GIF tag @TOPS+0, V4-8 @+1 (nx,ny,nz,idx),
V4-8 @+2 (RGBA), V2-16 @+3 (UV), MSCNT."""
import struct
from vif import parse
BASE=0x980000
def u32(d,o): return struct.unpack_from('<I',d,o)[0]
def decode(n,node):
    pk=u32(n,node+4)-BASE
    qwc=u32(n,pk)&0xffff
    pos=[];strips=[];cur=None;base=0
    for r in parse(n,pk+8,pk+16+qwc*16):
        if r[1]=='BAD': raise ValueError(hex(r[0]))
        off,cmd,num,imm,p,pl=r
        if cmd==0x68: base=len(pos); pos+=[struct.unpack_from('<3f',n,p+12*i) for i in range(num)]
        elif cmd==0x6c: cur={'tag':struct.unpack_from('<4I',n,p),'nv':[],'col':[],'uv':[],'base':base}
        elif cmd==0x6e and (imm&0x3ff)==1: cur['nv']=[struct.unpack_from('<3bB',n,p+4*i) for i in range(num)]
        elif cmd==0x6e and (imm&0x3ff)==2: cur['col']=[struct.unpack_from('<4B',n,p+4*i) for i in range(num)]
        elif cmd==0x75: cur['uv']=[struct.unpack_from('<2h',n,p+4*i) for i in range(num)]
        elif cmd==0x17 and cur: strips.append(cur); cur=None
    return {'pos':pos,'strips':strips,'pk':pk}
def triangles(m):
    t=[]
    for s in m['strips']:
        idx=[v[3]+s['base'] for v in s['nv']]
        for i in range(2,len(idx)):
            a,b,c=i-2,i-1,i
            if i%2: a,b=b,a
            t.append((idx[a],idx[b],idx[c],s,(a,b,c)))
    return t
