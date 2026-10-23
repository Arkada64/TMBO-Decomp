import sys, numpy as np
from bdd import bdd
from homesh import find_packets, decode, triangles
from hocollect import collect
from hotex import textures
from trender import render
def meshes(path,root,state=0,lod=0):
    s=bdd(path); n=s['ngp']; tx=textures(s['tex'])
    hdr2pk={decode(n,o)['hdr']:o for o in find_packets(n)}
    ms=[]
    for h in collect(n,root,state,lod=lod):
        if h not in hdr2pk: continue
        m=decode(n,hdr2pk[h]); tr=triangles(m)
        t=tx.get(m['texrefs'][0]) if m['texrefs'] else None
        ms.append(dict(hdr=h,m=m,pos=m['pos'],tris=[(a[0],b[0],c[0]) for a,b,c in tr],uvs=[[(-q[1][0]/4096,-q[1][1]/4096) for q in tri] for tri in tr],tex=t['img'] if t else None))
    return ms
if __name__=='__main__':
    ms=meshes(sys.argv[1],int(sys.argv[2],16),int(sys.argv[3]) if len(sys.argv)>3 else 0)
    if len(sys.argv)>5: ms=[m for m in ms if hex(m['hdr']) not in sys.argv[5].split(',')]
    render(ms,sys.argv[4])
