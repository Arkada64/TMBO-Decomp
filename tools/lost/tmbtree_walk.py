"""Child-pointer slots of TMB nodes (layouts from ngptrav / hier.h), for subtree edits."""
import struct
def kid_slots(n, o):
    u=lambda a: struct.unpack_from('<I',n,a)[0]; i32=lambda a: struct.unpack_from('<i',n,a)[0]
    op=u(o)&0x3f
    if op==1: k=struct.unpack_from('<H',n,o+8)[0]; return [o+0x20+4*i for i in range(k)]
    if op==2: return [o+0x28+0x10*i for i in range(i32(o+4))]
    if op==3: return [o+0x1c+4*i for i in range(i32(o+8))]
    if op==4: return [o+0x50+4*i for i in range(i32(o+8))]
    if op==6: return [o+0xc+4*i for i in range(n[o+0xb])]
    if op==17: return [o+0xcc+4*i for i in range(i32(o+4))]
    if op==31: return [o+0xc+0x14*i for i in range(n[o+9])]
    if op==30: return [o+0x2c+4*i for i in range(i32(o+8))]
    if op==8: return [o+4,o+8]
    return []
def subtree_slots(car, root):
    out=[]; seen=set(); st=[root]
    while st:
        o=st.pop()
        if o in seen: continue
        seen.add(o)
        for s in kid_slots(car.n,o):
            t=car.P(s)
            if t is None: continue
            out.append((s,t)); st.append(t)
    return out
