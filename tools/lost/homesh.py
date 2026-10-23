"""Head-On (PS2 ETE) car mesh packets -> triangles.
A mesh packet: 0x70-byte header (+0x0C scale float, +0x10 tex ref, +0x20 bsphere), then a DMA 'ret' tag
{0x6000qqqq, 0, VIF UNPACK S-32 1 @0xB4, nverts} followed by qqqq qwords of VIF:
 STROW + STMOD 1 + UNPACK V3-16 (positions, (row+s16)*scale), UNPACK V3-8 (normals),
 then strips: UNPACK V4-32 GIF tag, S-8 indices, V4-5 colors, V2-16 UVs, masked S-8 restart flags, MSCNT."""
import struct
from vif import parse
def u32(d,o): return struct.unpack_from('<I',d,o)[0]
def f32(d,o): return struct.unpack_from('<f',d,o)[0]
def find_packets(n):
    return [o for o in range(0,len(n)-16,16) if (u32(n,o)>>16)==0x6000 and u32(n,o+4)==0 and (u32(n,o+8)>>16)==0x6001]
def header(n,o):
    """mesh header before the DMA tag at o: {0, flags, 0, scale(pow2 float)}, texrefs, bsphere..."""
    for back in range(0x70,0x200,16):
        h=o-back
        w0,w1,w2,w3=[u32(n,h+4*i) for i in range(4)]
        if w0==0 and w2==0 and (w3&0x7fffff)==0 and 0x30000000<=w3<=0x3f800000:
            return h
    return None
def decode(n,o):
    h=header(n,o)
    scale=f32(n,h+12) if h is not None else 1/8192
    gs=[u32(n,q) for q in range(h+0x40,o,16) if u32(n,q+4)==0x20000005] if h is not None else []
    texrefs=[u32(n,h+0x10+4*i) for i in range(len(gs))] if h is not None else []
    skin=h is not None and (o-h-0x60-0x10*len(gs))>0
    qwc=u32(n,o)&0xffff
    row=[0,0,0,0]; mode=0
    pos=[];nrm=[];strips=[]; cur=None; base=0
    for r in parse(n,o+8,o+16+qwc*16):
        if r[1]=='BAD': raise ValueError('bad vif @%x'%r[0])
        off,cmd,num,imm,p,pl=r
        if cmd==0x30: row=list(struct.unpack_from('<4I',n,p))
        elif cmd==0x05: mode=imm&3
        elif cmd==0x69:
            base=len(pos)
            for i in range(num):
                v=struct.unpack_from('<3h',n,p+6*i)
                if mode==1: v=[(v[k]+row[k])&0xffffffff for k in range(3)]; v=[x-(1<<32) if x>=1<<31 else x for x in v]
                pos.append(tuple(x*scale for x in v))
        elif cmd==0x6a:
            for i in range(num): nrm.append(tuple(x/127 for x in struct.unpack_from('<3b',n,p+3*i)))
        elif cmd==0x6c:
            cur={'gif':imm&0x3ff,'tag':struct.unpack_from('<4I',n,p),'idx':[],'col':[],'uv':[],'brk':set()}
        elif cmd==0x62 and (imm&0x3ff)==cur['gif']+1: cur['idx']=[base+x for x in n[p:p+num]]
        elif cmd==0x6e: cur['col']=[struct.unpack_from('<I',n,p+4*i)[0] for i in range(num)]
        elif cmd==0x6f: cur['col']=[struct.unpack_from('<H',n,p+2*i)[0] for i in range(num)]
        elif cmd==0x75: cur['uv']=[struct.unpack_from('<2h',n,p+4*i) for i in range(num)]
        elif cmd==0x72:
            k=((imm&0x3ff)-(cur['gif']+3))//3
            for j in range(num): cur['brk'].add(k+j)
        elif cmd==0x17:
            if cur: strips.append(cur); cur=None
    return {'hdr':h,'texrefs':texrefs,'gsreg':gs,'skin':skin,'scale':scale,'pos':pos,'nrm':nrm,'strips':strips,'tex':u32(n,o-0x60),'flags':u32(n,o-0x6c),'hflags':u32(n,h+4) if h is not None else 0}
def triangles(m):
    """-> list of ((i0,uv0),(i1,uv1),(i2,uv2)) with consistent winding"""
    tris=[]
    for s in m['strips']:
        idx,uv=s['idx'],s['uv']; par=0
        for i in range(2,len(idx)):
            if i in s['brk']:
                if i-1 not in s['brk']: par=i
                continue
            a,b,c=i-2,i-1,i
            if (i-par)%2: a,b=b,a
            tris.append(((idx[a],uv[a]),(idx[b],uv[b]),(idx[c],uv[c])))
    return tris
