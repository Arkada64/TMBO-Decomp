"""Textured preview of meshes in a TMB car NGP using its TEX/RTX (validates the converted files)."""
import sys, struct, re, numpy as np
from texfile import recs
from tmbmesh import decode, triangles
from hotex import clut_unswizzle
from textconv import rtx_records
from trender import render
def load(d):
    n=open(d+'/STP.NGP','rb').read(); t=open(d+'/STP.TEX','rb').read(); r=open(d+'/STP.RTX','rb').read()
    from textconv import records, tex_rec_size
    byid={}
    for o,b,gs,k in records(t,tex_rec_size): byid[gs&0xffff]=dict(off=o,bytes=b,gs=gs,tw=(gs>>40)&15,th=(gs>>44)&15)
    rr,_=rtx_records(r); clut={a:(o,sz,tw,th) for o,sz,a,tw,th in rr}
    return n,t,r,byid,clut
def image(t,r,byid,clut,tid,cbp):
    x=byid.get(tid)
    if x is None or cbp not in clut: return None
    psm=(x['gs']>>32)&0x3f; w,h=1<<x['tw'],1<<x['th']
    raw=np.frombuffer(t[x['off']+0x80:x['off']+x['bytes']],np.uint8)
    if psm==0x14: idx=np.empty(len(raw)*2,np.uint8); idx[0::2]=raw&15; idx[1::2]=raw>>4
    else: idx=raw
    o,sz,tw,th=clut[cbp]; ne=(1<<tw)*(1<<th)
    pal=[tuple(np.frombuffer(r[o+16:o+16+4*ne],np.uint8).reshape(ne,4)[i]) for i in range(ne)]
    if ne==256: pal=clut_unswizzle(pal)
    return np.array(pal,np.uint8)[idx[:w*h]].reshape(h,w,4)
def meshes(d,nodes):
    n,t,r,byid,clut=load(d); out=[]
    for nd in nodes:
        m=decode(n,nd); nt=struct.unpack_from('<H',n,nd+0x5a)[0]
        tex=[]
        for i in range(nt):
            tid=struct.unpack_from('<H',n,nd+0x50+2*i)[0]; q=struct.unpack_from('<Q',n,nd+0x70+0x30*i)[0]
            tex.append(image(t,r,byid,clut,tid,(q>>37)&0x3fff))
        tr=triangles(m)
        # per-strip texture select: tag[3]=1+3k
        cur=0; T=[];U=[]
        sel={}
        for s in m['strips']:
            if s['tag'][3]: cur=(s['tag'][3]-1)//3
            sel[id(s)]=cur
        groups={}
        for a,b,c,s,(i0,i1,i2) in tr:
            k=sel[id(s)]; groups.setdefault(k,[]).append(((a,b,c),[(-s['uv'][j][0]/4096,-s['uv'][j][1]/4096) for j in (i0,i1,i2)]))
        for k,lst in groups.items():
            out.append(dict(pos=m['pos'],tris=[x[0] for x in lst],uvs=[x[1] for x in lst],tex=tex[k] if k<len(tex) else None))
    return out
if __name__=='__main__':
    d=sys.argv[1]; nodes=[int(x,16) for x in sys.argv[3:]]
    render(meshes(d,nodes),sys.argv[2])
