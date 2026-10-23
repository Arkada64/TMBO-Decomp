"""Collect Head-On op0 meshes under a node, following known child layouts; op19 (damage states) -> chosen state."""
import struct
def collect(n,root,state=0,lod=None,log=None):
    N=len(n); u=lambda o: struct.unpack_from('<I',n,o)[0]
    u16=lambda o: struct.unpack_from('<H',n,o)[0]
    out=[]; seen=set()
    def ok(p): return 0<p<N and p%16==0
    def w(o,d):
        if o in seen or not ok(o): return
        seen.add(o); op=u(o)&0x3f; kids=[]
        if op==0: out.append(o); return
        if op==1: kids=[u(o+0x20+4*i) for i in range(u16(o+8))]
        elif op==2:
            k=u16(o+4); ks=[u(o+0x28+0x10*i) for i in range(k)]
            kids=ks if lod is None else [ks[min(lod,k-1)]]
        elif op==3: kids=[u(o+0x1c+4*i) for i in range(u16(o+8))]
        elif op==4: kids=[u(o+0x50+4*i) for i in range(u16(o+8))]
        elif op==5: kids=[u(o+0xc+4*i) for i in range(n[o+0xb])]
        elif op==6: kids=[u(o+0xc+4*i) for i in range(n[o+0xb])]
        elif op==13:
            k=o+0x20
            if u(o+0x20)==0x3f800000: k=o+0xa0
            while ok(u(k)): kids.append(u(k)); k+=4
            if k==o+0x20+4*len(kids) and u(o+0x30)==0 and (u(o+0x34)&0xff) in (0x10,0x12,0): kids.append(o+0x30)
        elif op==19:
            cnt=u(o+8)&0xff; hp=[1.0,0.4,0.15,0.02][state] if isinstance(state,int) else state
            pick=cnt-1
            for i in range(cnt-1):
                if hp*0xffff>(u(o+0x18+0xc*i)&0xffff): pick=i; break
            kids=[u(o+0x10+0xc*pick)]
        elif op==20: kids=[u(o+8)]
        if log is not None: log.append((d,o,op,len(kids)))
        for k in kids: w(k,d+1)
    w(root,0)
    return out
