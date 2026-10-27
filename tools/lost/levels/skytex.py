import struct,numpy as np,sys
sys.path[:0]=['/home/claude/tmb-reloaded/tools/lost','/home/claude/lost','/home/claude/tmb-reloaded/tools/shift']
from hotex import clut_unswizzle
from textconv import records, tex_rec_size, rtx_records
def rtx_all(r):
    o=0; out={}; cl={}
    while o+16<=len(r):
        sz,k,gs=struct.unpack_from('<IIQ',r,o)
        kd=(gs>>48)&0xff
        if kd==8:
            ne=(1<<((gs>>40)&15))*(1<<((gs>>44)&15)); cl[(gs>>16)&0xffff]=(o,ne)
        else: out[gs&0xffff]=(o,gs)
        if sz==0: break
        o+=sz*4
    return out,cl
def tex_image(n,t,r,tid,cbp):
    res,cl=rtx_all(r)
    byid={gs&0xffff:(o,b,gs) for o,b,gs,k in records(t,tex_rec_size)}
    if tid in byid: o,b,gs=byid[tid]; data=t
    elif tid in res: o,gs=res[tid]; data=r
    else: return None
    psm=(gs>>32)&0x3f; w,h=1<<((gs>>40)&15),1<<((gs>>44)&15)
    raw=np.frombuffer(data[o+0x80:o+0x80+(w*h if psm in (0x13,0x1b) else w*h//2)],np.uint8)
    if psm in (0x13,0x1b): idx=raw
    else: idx=np.empty(len(raw)*2,np.uint8); idx[0::2]=raw&15; idx[1::2]=raw>>4
    if cbp not in cl: return None
    co,ne=cl[cbp]
    pal=[tuple(x) for x in np.frombuffer(r[co+16:co+16+4*ne],np.uint8).reshape(ne,4)]
    if ne==256: pal=clut_unswizzle(pal)
    pal=np.array(pal,np.uint8)
    return pal[idx[:w*h]].reshape(h,w,4)
