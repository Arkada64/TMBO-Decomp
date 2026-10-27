"""Weapon mounts of an extra car (hcbuild.py / pakbuild.py): the donor's mount nodes move to the new model's guns.

Donor side (TMB car NGP): every weapon model hangs under a mount transform (op3 or op4) whose translation places it:
  - machine guns: op1 id 4100 (the gun model, one shared group) under two op4 (left / right) under op6 switches of
    attach type 13 (id R+13, vehicle +0x2A54), in the high LOD (Roadkill: 0x5cdb0 / 0x5ce30, t(-2.77 / 2.82, 3.49, -1.48));
  - weapon models: op1 id 4001..4006 (+ 4011 / 4028 specials) under an op3 / op4 under an op6 of attach type 7
    (id R+7, vehicle +0x2A20 + sub * 4) with sub = weapon slot (1 special, 2 fire, 3 homing, 4 napalm, 5 pickup
    slot, 7 power / rico, 10 the 4006 extra), inside the weapon characters (op25 -> op17 bones), which the car tree
    instances, sometimes under an op3 offset (Junkyard Dog).
  The positions are read along the path from entry point 0 (op3 / op4 transforms accumulated; op17 bones are the
  identity at rest: their meshes are stored in model space), so they are car-space rest positions.
  Moving a mount = adding (target - rest position) to its own translation (in its parent's frame); the weapon model,
  and the fire origin the game takes from it, follow, including during the donor's weapon animations (the bone
  moves the moved mount along).
Head-On side (BDD ngp): an op5 near the root lists the car's mount points: kid 0 an op8, kid i = slot i // 2 (one
  entry for slots 0 and 7, two for 1..6); an op3 entry has its slot in its sub field and the point at +0x10 (car space,
  same as the meshes); op1 / op31 entries carry no point. Seen (Thumper, Outlaw 2,
  Twister, 12 Pak, Sweet Tooth / Gold Tooth): slot 0 = special (Thumper's fire breath at the nose, Outlaw's roof
  turret), slot 6 = the machine guns (Thumper: inside its two gun barrels), slot 4 = a forward point ahead of the
  guns, 1 / 2 / 5 = rear / side launchers, 3 = rear (or front) centre low, 7 = roof centre. Old Pickup and Pit Viper
  (fan-build, near-static) have no list.
HC_MOUNTS (default 1):
  0   off
  mg  machine guns only (Head-On slot 6 pair, else slot 4 mirrored, else the per-car table / box map)
  1   machine guns as above + every other mount box-mapped: the donor's position relative to its body box goes to the
      same relative spot of the new body box (keeps the donor's launcher layout, which its animations expect)
  ho  machine guns as above + the other mounts on Head-On slots (guessed: special 0, fire 1, homing 2, napalm 3,
      pickup 5, power / rico 7 -> 7, 4006 -> 7); box map where the slot has no point
HC_MG_SLOT=4|6 forces the machine-gun slot. HC_MOUNT_POS='4100:x,y,z;4001:x,y,z' sets Head-On-space points by id
(4100: the right gun; the left one is mirrored)."""
import os, struct
import numpy as np

BASE = 0x980000
SUB_SLOT = {1: 0, 2: 1, 3: 2, 4: 3, 5: 5, 7: 7, 10: 7}       # HC_MOUNTS=ho guess: donor switch sub -> Head-On slot
# cars without a Head-On list: machine-gun points picked from their meshes (Head-On space, right gun)
MG_TABLE = {'PVIPER': (1.31, 7.30, 0.00)}      # Pit Viper: the outer front bumper bars 0xe60 / 0x75e0 (y 6.67..7.33)


def u32(d, o): return struct.unpack_from('<I', d, o)[0]


def _xf(n, o):
    op = u32(n, o) & 0x3f
    if op == 3:
        return np.eye(3), np.array(struct.unpack_from('<3f', n, o + 0x10))
    if op == 4:
        M = np.array(struct.unpack_from('<16f', n, o + 0x10)).reshape(4, 4)
        return M[:3, :3], M[3, :3]
    return None


def donor_mounts(car):
    """mount transforms of the donor: {node: dict(op, ids, sub, kind, pos (car space), M (parent frame), path)}"""
    from hcbuild import kids
    n = car.n
    R = u32(n, u32(n, 4) - BASE) >> 18
    out = {}
    ne = u32(n, 0)
    for ep in range(ne):                       # entry 0 first: the drawn car; op7 (characters) as fallback
        st = [(u32(n, 4 + 4 * ep) - BASE, np.eye(3), np.zeros(3), (), None, np.eye(3))]
        while st:
            o, M, t, ch, sw, Mab = st.pop()   # Mab: frame the last transform above sits in
            if o in ch or len(ch) > 40:
                continue
            ch = ch + (o,)
            h = u32(n, o); op = h & 0x3f
            if op == 1 and (h >> 18) >= 4000 and len(ch) >= 2:
                p = ch[-2]
                if (u32(n, p) & 0x3f) in (3, 4):
                    d = out.setdefault(p, dict(op=u32(n, p) & 0x3f, ids=set(), sub=None, kind=None, pos=None, M=None, ep=ep))
                    d['ids'].add(h >> 18)
                    if d['pos'] is None:
                        d['pos'], d['M'] = t.copy(), Mab.copy()
                        if sw is not None:
                            sh = u32(n, sw)
                            d['kind'] = (sh >> 18) - R
                            d['sub'] = (sh >> 7) & 0x7ff
                continue
            if op == 6:
                sw = o
            x = _xf(n, o)
            if x is not None:
                Rm, tt = x
                Mab = M
                t = tt @ M + t
                M = Rm @ M
            for k in kids(car, o):
                st.append((k, M, t, ch, sw, Mab))
    return out


def ho_list(n):
    """Head-On mount list: {slot: [points]} (None for entries without a point)"""
    best = None
    for o in range(0, len(n) - 16, 16):
        if u32(n, o) & 0x3f != 5:
            continue
        k = n[o + 0xb]
        if not 8 <= k <= 20 or o + 0xc + 4 * k > len(n):
            continue
        ks = [u32(n, o + 0xc + 4 * i) for i in range(k)]
        if not all(0 < x < len(n) and x % 16 == 0 for x in ks) or u32(n, ks[0]) & 0x3f != 8:
            continue
        op3 = [x for x in ks if u32(n, x) & 0x3f == 3]
        if len(op3) < 3 or len({u32(n, x) >> 18 for x in op3}) != 1:
            continue
        L = {}
        for i, x in enumerate(ks):           # kid i: slot i // 2 (slot 0 and 7 have one entry); an op3 names its
            if i == 0:                       # slot in its sub field
                continue
            is3 = u32(n, x) & 0x3f == 3
            slot = (u32(n, x) >> 7) & 0x7ff if is3 else min(i // 2, 7)
            L.setdefault(slot, []).append(tuple(struct.unpack_from('<3f', n, x + 0x10)) if is3 else None)
        if best is None or len(op3) > best[0]:
            best = (len(op3), o, L)
    return (best[1], best[2]) if best else (None, {})


def mg_points(L, name=''):
    """right / left machine-gun points (Head-On space) and where they came from"""
    force = os.environ.get('HC_MG_SLOT')
    for slot in ([int(force)] if force else [6, 4]):
        pts = [p for p in L.get(slot, []) if p is not None]
        if not pts:
            continue
        r = max(pts, key=lambda p: p[0])
        l = min(pts, key=lambda p: p[0])
        if r[0] > 0.3 and l[0] < -0.3:
            return np.array(r), np.array(l), 'Head-On slot %d pair' % slot
        if slot == 4 or force:               # one side only (or the same point twice): mirrored
            p = np.array(pts[0]); q = p * np.array([-1, 1, 1])
            return (p, q, 'Head-On slot %d mirrored' % slot) if p[0] > 0 else (q, p, 'Head-On slot %d mirrored' % slot)
    for k, p in MG_TABLE.items():
        if k in name.upper():
            p = np.array(p)
            return p, p * np.array([-1, 1, 1]), 'table (%s)' % k
    return None, None, None


def move(car, rec, node, target):
    """add (target - rest pos) to the mount's translation, in its parent's frame"""
    d = rec[node]
    dw = np.asarray(target, float) - d['pos']
    dl = dw @ np.linalg.inv(d['M'])
    off = 0x10 if d['op'] == 3 else 0x40
    t = np.array(struct.unpack_from('<3f', car.n, node + off)) + dl
    struct.pack_into('<3f', car.n, node + off, *t)
    return dw


def apply(car, rec, L, to_donor, box_d, box_n, name='', log=print):
    """rec: donor_mounts() of the original donor; L: ho_list(); to_donor(p) maps Head-On space -> donor space;
    box_d / box_n: (lo, hi) of the donor's body and of the new body in donor space. Returns report rows."""
    mode = os.environ.get('HC_MOUNTS', '1')
    if mode == '0':
        return []
    over = {}
    for spec in filter(None, os.environ.get('HC_MOUNT_POS', '').split(';')):
        i, _, v = spec.partition(':')
        over[int(i)] = np.array([float(x) for x in v.split(',')])
    if 4100 in over:
        r, l, src = over[4100], over[4100] * np.array([-1, 1, 1]), 'HC_MOUNT_POS'
    else:
        r, l, src = mg_points(L, name)
    def ch(b):                           # centre / half size, x kept symmetric about the car's centre line
        lo, hi = np.asarray(b[0], float), np.asarray(b[1], float)
        c, h = (lo + hi) / 2, (hi - lo) / 2
        c[0], h[0] = 0.0, max(-lo[0], hi[0])
        return c, h
    (cd, hd_), (cn, hn) = ch(box_d), ch(box_n)
    boxmap = lambda p: cn + (p - cd) * hn / np.maximum(hd_, 1e-3)
    rows = []
    for node, d in sorted(rec.items()):
        ids = sorted(d['ids'])
        if 4100 in ids:
            if r is not None:
                tgt, how = to_donor(r if d['pos'][0] > 0 else l), src
            else:
                tgt, how = boxmap(d['pos']), 'box map (no Head-On points)'
        elif mode == 'mg':
            continue
        else:
            tgt, how = None, None
            hit = [i for i in ids if i in over]
            if hit:
                tgt, how = to_donor(over[hit[0]]), 'HC_MOUNT_POS'
            elif mode == 'ho' and d['sub'] in SUB_SLOT:
                pts = [p for p in L.get(SUB_SLOT[d['sub']], []) if p is not None]
                if pts:
                    p = min(pts, key=lambda q: abs(np.sign(q[0]) - np.sign(d['pos'][0])) * 10 + abs(q[1] - d['pos'][1]) * 0.01)
                    tgt, how = to_donor(np.array(p)), 'Head-On slot %d' % SUB_SLOT[d['sub']]
            if tgt is None:
                tgt, how = boxmap(d['pos']), 'box map'
        old = d['pos'].copy()
        move(car, rec, node, tgt)
        rows.append((ids, node, d['kind'], d['sub'], old, np.asarray(tgt, float), how))
        log('mount %-10s node %#x (switch type %s sub %s): (%.2f %.2f %.2f) -> (%.2f %.2f %.2f)  %s' % (
            '/'.join(map(str, ids)), node, d['kind'], d['sub'], *old, *tgt, how))
    return rows


def body_box_tmb(car, group):
    """box of the op0 meshes under a donor group (its body damage state 0)"""
    from hcbuild import meshes_under
    from tmbmesh import decode
    P = []
    for m in meshes_under(car, group):
        try:
            P += decode(bytes(car.n), m)['pos']
        except Exception:
            pass
    P = np.asarray(P, float)
    return np.percentile(P, 1, axis=0), np.percentile(P, 99, axis=0)


# ---------------------------------------------------------------- Old Pickup's flamethrower (HC_FLAME)
# The roof flamethrower (barrel x 1.1, y -1.9..4.85, z 5.6..6.2 and its fuel cylinder x 1.5..2.1, y -4.2..-1.9) is part
# of the Pickup's one body mesh 0x8c30. HC_FLAME=1 (default for PICKUP.BDD) cuts those triangles out of the body and
# puts them, turned about the vertical axis through its post (1.1, -1.9), into a 5-frame switch of attach type 7
# (id R+7) with sub FLAME_SUB, which the game registers at vehicle +0x2A20 + sub * 4 and nothing drives yet: frame 0 =
# straight ahead (the model as built), frames 1..4 = yaw FLAME_YAW degrees (+ = to the left).
FLAME_BOX = (np.array([0.6, -4.3, 5.3]), np.array([2.2, 5.0, 6.5]))
FLAME_PIVOT = (1.1, -1.9)
FLAME_SUB = 9
FLAME_YAW = [0.0, 20.0, 40.0, -20.0, -40.0]


def split_mesh(m, inside):
    """split a Head-On mesh dict into (triangles with all corners inside(), the rest), both as mesh dicts with
    strips cut into runs (winding kept: a run starting on the other parity gets a leading duplicate vertex)"""
    P =np.asarray(m['pos'], float)
    ins = np.array([bool(inside(p)) for p in P])
    outs = ([], [])
    cur = 1                               # texture select of texture 0 (a first strip without one draws with it)
    for s in m['strips']:
        if s['tag'][3]:
            cur = s['tag'][3]
        idx = s['idx']; par = 0; tris = []
        for i in range(2, len(idx)):
            if i in s['brk']:
                if i - 1 not in s['brk']:
                    par = i
                tris.append((i, None, None)); continue
            tris.append((i, bool(ins[idx[i - 2]] and ins[idx[i - 1]] and ins[idx[i]]), (i - par) % 2))
        for want, dst in ((True, outs[0]), (False, outs[1])):
            run = []
            for i, cls, sw in tris + [(None, None, None)]:
                if cls is want and (not run or i == run[-1][0] + 1):
                    run.append((i, sw)); continue
                if run:
                    a, b = run[0][0] - 2, run[-1][0]
                    sel = list(range(a, b + 1))
                    if run[0][1]:            # first triangle was a swapped one: keep its winding
                        sel = [a] + sel
                    t = list(s['tag']); t[3] = cur
                    dst.append(dict(s, idx=[idx[j] for j in sel], col=[s['col'][j] if j < len(s['col']) else 0xFFFF for j in sel],
                                    uv=[s['uv'][j] if j < len(s['uv']) else (0, 0) for j in sel], brk=set(), tag=tuple(t)))
                run = [(i, sw)] if cls is want else []
    return dict(m, strips=outs[0]), dict(m, strips=outs[1])


def turned(m, piv, deg):
    """mesh dict turned deg degrees about the vertical axis through piv (x, y)"""
    a = np.radians(deg); c, s = np.cos(a), np.sin(a)
    P = np.asarray(m['pos'], float).copy()
    x, y = P[:, 0] - piv[0], P[:, 1] - piv[1]
    P[:, 0], P[:, 1] = piv[0] + c * x - s * y, piv[1] + s * x + c * y
    N = np.asarray(m['nrm'], float).copy() if m['nrm'] else np.zeros((0, 3))
    if len(N):
        nx, ny = N[:, 0].copy(), N[:, 1].copy()
        N[:, 0], N[:, 1] = c * nx - s * ny, s * nx + c * ny
    return dict(m, pos=[tuple(p) for p in P], nrm=[tuple(q) for q in N])
