"""Head-On / TMB TEX records -> RGBA images. Head-On: texture record (key != 0) followed by its CLUT record (key 0).
Record: u32 sizew, u32 key, u64 gs (Head-On: bits 40-43/44-47 = upload rect log2 in CT32 units), 0x70-byte GIF/DMA
header, then pixel data."""
import struct
import numpy as np
from texrec import recs
def clut_unswizzle(c):
    if len(c)!=256: return c
    out=list(c)
    for i in range(256):
        b=i&0x18
        j=(i&~0x18)|((b==8)<<4)|((b==0x10)<<3) if b in (8,0x10) else i
        out[i]=c[j]
    return out
def pal(d,off,nbytes):
    n=nbytes//4
    return [struct.unpack_from('<4B',d,off+4*i) for i in range(n)]
def textures(t):
    cl,rs,end=recs(t)
    if end+16<=len(t) and struct.unpack_from('<Q',t,end+8)[0]:
        gs=struct.unpack_from('<Q',t,end+8)[0]
        rs=rs+[{"off":end,"bytes":len(t)-end,"key":0,"gs":gs,"id":0,"addr":0,"tw":(gs>>40)&15,"th":(gs>>44)&15,"kind":gs>>58}]
    out={}
    for i,r in enumerate(rs):
        if r['key']==0: continue
        c=rs[i+1]
        tw,th=r['tw'],r['th']; nb=r['bytes']-0x80
        cn=c['bytes']-0x80
        p=pal(t,c['off']+0x80,4*(1<<c['tw'])*(1<<c['th']))
        npx=nb*2 if len(p)==16 else nb
        bpp=4 if len(p)==16 else 8
        if bpp==8: p=clut_unswizzle(p)
        # logical dims: area = npx; upload rect (CT32) w=1<<tw, h=1<<th: T8 = 2w x 2h, T4 = 2w x 4h? use square-ish
        W=(1<<tw)*2; H=npx//W
        if bpp==4: W=(1<<tw)*2; H=(1<<th)*4
        raw=t[r['off']+0x80:r['off']+0x80+nb]
        if bpp==8: idx=unswizzle8(raw,W,H)
        else:
            from gsmem import mem_from_ct32, read_t4
            idx=read_t4(mem_from_ct32(raw,1<<tw,1<<th),W,H)
        P=np.array(p,np.uint16); P[:,3]=np.minimum(255,P[:,3]*2)
        img=P[idx].reshape(H,W,4).astype(np.uint8)
        nent=(1<<c['tw'])*(1<<c['th'])
        out[r['key']]=dict(img=img,bpp=bpp,rec=r,clut=c,idx=np.asarray(idx),clutraw=bytes(t[c['off']+0x80:c['off']+0x80+4*nent]))
    return out
def unswizzle8(buf,w,h):
    a=np.frombuffer(bytes(buf),np.uint8); out=np.empty(w*h,np.uint8)
    for y in range(h):
        for x in range(w):
            bl=(y&~0xf)*w+(x&~0xf)*2
            ss=(((y+2)>>2)&1)*4
            py=(((y&~3)>>1)+(y&1))&7
            cl=py*w*2+((x+ss)&7)*4
            bn=((y>>1)&1)+((x>>2)&2)
            out[y*w+x]=a[bl+cl+bn]
    return out
