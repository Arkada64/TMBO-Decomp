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


def rot_prh(a, b, c):
    """mathfRotMatrixPRH (0x0021E1D0-ish, rows for row vectors) of the angles it is given"""
    sa, ca, sb, cb, sc, cc = np.sin(a), np.cos(a), np.sin(b), np.cos(b), np.sin(c), np.cos(c)
    return np.array([[cb * cc, -cb * sc, sb],
                     [sa * sb * cc + ca * sc, -sa * sb * sc + ca * cc, -sa * cb],
                     [-ca * sb * cc + sa * sc, ca * sb * sc + sa * cc, ca * cb]])


def char_tracks(car, char):
    """animation tracks of an op25 character: {channel: [(time, c3, c2, c1, c0), ...]} (op25 +0x10 -> op33 node, its
    +4 -> header: +0xC channel count, +0x18 one pointer per channel -> nkeys, channel, keys of 5 floats; a key's value
    at time t >= its time T is c0 + c1 u + c2 u^2 + c3 u^3, u = t - T, as evaluateBetweenKeyframes)"""
    n = car.n
    c33 = car.P(char + 0x10)
    hdr = car.P(c33 + 4) if c33 is not None and (u32(n, c33) & 0x3f) == 33 else None
    out = {}
    if hdr is None:
        return out
    for i in range(min(u32(n, hdr + 0xc), 256)):
        tp = car.P(hdr + 0x18 + 4 * i)
        if tp is None:
            continue
        k, chn = u32(n, tp) & 0xffff, u32(n, tp + 4)
        if not 0 < k < 4096:
            continue
        out[chn] = [struct.unpack_from('<5f', n, tp + 8 + 20 * j) for j in range(k)]
    return out


def track_value(keys, t):
    """value at time t; before the first / after the last key the end value holds"""
    if t <= keys[0][0]:
        return keys[0][4]
    if t >= keys[-1][0]:
        return keys[-1][4]
    k = max((kk for kk in keys if kk[0] <= t), key=lambda kk: kk[0])
    u = t - k[0]
    return k[4] + u * (k[3] + u * (k[2] + u * k[1]))


def bone_local(n, o, vals=None):
    """an op17 bone's local transform as skeletonTraverse builds it from the stored channel values (the exported pose):
    R = RotPRH(-P, -R, -H) at +0x20; flags +0xC0: 0x10000 -> A40 * R, 0x20000 -> * A80 (A40 / A80 = -pivot / +pivot);
    then + the translation at +0x30. Returns (3x3, t) for row vectors (world = local @ parent)."""
    ang = np.array(struct.unpack_from('<3f', n, o + 0x20))
    tr = np.array(struct.unpack_from('<3f', n, o + 0x30))
    if vals is not None:                         # channel values replace the stored ones (+0x12.. index per field)
        ci = struct.unpack_from('<6h', n, o + 0x12)
        for j, c in enumerate(ci):
            if c >= 0 and c in vals:
                if j < 3: ang[j] = vals[c]
                else: tr[j - 3] = vals[c]
    R = rot_prh(*(-ang))
    M = np.eye(4); M[:3, :3] = R
    fl = u32(n, o + 0xc0)
    if fl & 0x10000:
        M = np.array(struct.unpack_from('<16f', n, o + 0x40)).reshape(4, 4) @ M
        if fl & 0x20000:
            M = M @ np.array(struct.unpack_from('<16f', n, o + 0x80)).reshape(4, 4)
    elif fl & 0x20000:
        M = M @ np.array(struct.unpack_from('<16f', n, o + 0x80)).reshape(4, 4)
    return M[:3, :3], M[3, :3] + tr


def _xf(n, o):
    op = u32(n, o) & 0x3f
    if op == 17:
        return bone_local(n, o)
    if op == 3:
        return np.eye(3), np.array(struct.unpack_from('<3f', n, o + 0x10))
    if op == 4:
        M = np.array(struct.unpack_from('<16f', n, o + 0x10)).reshape(4, 4)
        return M[:3, :3], M[3, :3]
    return None


def donor_mounts(car):
    """mount transforms of the donor: {node: dict(op, ids, sub, kind, pos, M, Mown, char, Mchar, ep)}
    pos = car-space position in the exported pose (op17 bones evaluated from their stored channel values, see
    bone_local: several donors' weapon bones carry a constant offset, e.g. Outlaw's 4001 bone t(0.27 -6.66 1.10),
    Junkyard Dog's 4005 x 12.97 at bind -> 2.89 posed); M = rotation of the frame the mount sits in, Mown = the
    mount's own rotation (its model's orientation), char = the nearest op25 character above it on the drawn path
    (None for the machine guns), Mchar = rotation of the frame that character sits in."""
    from hcbuild import kids
    n = car.n
    R = u32(n, u32(n, 4) - BASE) >> 18
    out = {}
    ne = u32(n, 0)
    for ep in range(ne):                       # entry 0 first: the drawn car; op7 (characters) as fallback
        st = [(u32(n, 4 + 4 * ep) - BASE, np.eye(3), np.zeros(3), (), None, np.eye(3), None)]
        while st:
            o, M, t, ch, sw, Mab, chr_ = st.pop()   # Mab: frame the last transform above sits in
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
                        d['pos'], d['M'], d['Mown'] = t.copy(), Mab.copy(), M.copy()
                        d['grp'] = o
                        d['char'], d['Mchar'] = chr_ if chr_ and ep == 0 else (None, None)
                        if sw is not None:
                            sh = u32(n, sw)
                            d['kind'] = (sh >> 18) - R
                            d['sub'] = (sh >> 7) & 0x7ff
                continue
            if op == 6:
                sw = o
            if op == 25:
                chr_ = (o, M.copy())
            x = _xf(n, o)
            if x is not None:
                Rm, tt = x
                Mab = M
                t = tt @ M + t
                M = Rm @ M
            for k in kids(car, o):
                st.append((k, M, t, ch, sw, Mab, chr_))
    return out


def char_anchors(car, char):
    """{channel: stored value} for the channels that drive the rotation / translation fields of the character's
    op17 bones (the exported pose: the anchor HC_ANIM damping scales towards)"""
    from hcbuild import kids
    n = car.n
    out, seen, st = {}, set(), [char]
    while st:
        o = st.pop()
        if o in seen:
            continue
        seen.add(o)
        if (u32(n, o) & 0x3f) == 17:
            ci = struct.unpack_from('<6h', n, o + 0x12)
            v = struct.unpack_from('<3f', n, o + 0x20) + struct.unpack_from('<3f', n, o + 0x30)
            for c, x in zip(ci, v):
                if c >= 0:
                    out.setdefault(c, x)
        st += [k for k in kids(car, o) if (u32(n, k) & 0x3f) != 0]
    return out


def damp_char(car, char, f):
    """scale the character's bone channels towards their stored values by f (key c0 -> a + f (c0 - a), c1..c3 * f):
    the same animation, smaller (f 0 = frozen in the exported pose)"""
    anc = char_anchors(car, char)
    n = car.n
    c33 = car.P(char + 0x10)
    hdr = car.P(c33 + 4)
    done = 0
    for i in range(min(u32(n, hdr + 0xc), 256)):
        tp = car.P(hdr + 0x18 + 4 * i)
        if tp is None:
            continue
        k, chn = u32(n, tp) & 0xffff, u32(n, tp + 4)
        if chn not in anc or not 0 < k < 4096:
            continue
        a = anc[chn]
        for j in range(k):
            t, c3, c2, c1, c0 = struct.unpack_from('<5f', n, tp + 8 + 20 * j)
            struct.pack_into('<5f', n, tp + 8 + 20 * j, t, c3 * f, c2 * f, c1 * f, a + f * (c0 - a))
        done += 1
    return done


def mount_envelope(car, rec, node, extra=np.zeros(3), f=1.0):
    """car-space positions of a mount over its character's animation (every key time and the midpoints, all
    channels evaluated), plus its exported-pose position; extra: a translate put above the character; f: the
    bone channels scaled towards their stored values (damp_char)"""
    from hcbuild import kids
    d = rec[node]
    n = car.n
    if d.get('char') is None:
        return np.array([d['pos']])
    trk = char_tracks(car, d['char'])
    ts = sorted({k[0] for v in trk.values() for k in v})
    ts = sorted(set(ts) | {(a + b) / 2 for a, b in zip(ts, ts[1:])})
    # path from the character down to the mount
    path = None
    st = [(d['char'], (d['char'],))]
    while st and path is None:
        o, ch = st.pop()
        for k in kids(car, o):
            if k == node:
                path = ch + (k,); break
            if k not in ch and len(ch) < 40 and (u32(n, k) & 0x3f) != 0:
                st.append((k, ch + (k,)))
    if path is None:
        return np.array([d['pos']])
    anc = char_anchors(car, d['char']) if f != 1.0 else {}
    out = []
    for t in ([None] + ts):
        vals = None if t is None else {c: track_value(v, t) for c, v in trk.items()}
        if vals is not None and anc:
            vals = {c: (anc[c] + f * (v - anc[c]) if c in anc else v) for c, v in vals.items()}
        M, tt, hidden = d['Mchar'], np.zeros(3), False
        for o in path:
            if (u32(n, o) & 0x3f) == 17:
                vc = struct.unpack_from('<h', n, o + 0x10)[0]
                if vals is not None and vc >= 0 and vc in vals and vals[vc] == 0:
                    hidden = True
                Rm, t3 = bone_local(n, o, vals)
            else:
                x = _xf(n, o)
                if x is None:
                    continue
                Rm, t3 = x
            tt = t3 @ M + tt
            M = Rm @ M
        if not hidden:
            out.append(tt)
    base = d['pos'] - out[0] if out else 0      # car-space offset of the character (transforms above it)
    return np.array(out) + base + extra


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


def move(car, rec, node, target, extra=None):
    """add (target - rest pos [- extra]) to the mount's translation, in its parent's frame (extra: the part of the
    move already done by a translate above its character)"""
    d = rec[node]
    dw = np.asarray(target, float) - d['pos'] - (0 if extra is None else extra)
    dl = dw @ np.linalg.inv(d['M'])
    off = 0x10 if d['op'] == 3 else 0x40
    t = np.array(struct.unpack_from('<3f', car.n, node + off)) + dl
    struct.pack_into('<3f', car.n, node + off, *t)
    return dw


def move_char(car, char, Mchar, delta, skip_slots=()):
    """put a translate (op3) by delta (car space) above every drawn reference to the op25 character (the op7 list's
    entries stay): the whole launcher skeleton moves, pivots included, so its animations keep their shape"""
    n = car.n
    op7s = [u32(n, 4 + 4 * i) - BASE for i in range(u32(n, 0)) if (u32(n, u32(n, 4 + 4 * i) - BASE) & 0x3f) == 7]
    lists = [(o + 8, o + 8 + 4 * u32(n, o + 4)) for o in op7s]
    refs = [sl for sl in sorted(set(car.slots)) if car.P(sl) == char and not any(a <= sl < b for a, b in lists)
            and sl not in skip_slots]
    dl = np.asarray(delta, float) @ np.linalg.inv(Mchar)
    for sl in refs:
        t = car.append(struct.pack('<IIIIfffI', 3, 0, 1, 0, *dl, 0))
        car.setp(t + 0x1c, char)
        car.setp(sl, t)
    return refs


def group_zmin(car, d):
    """lowest point of a mount's weapon model below its origin, in car-space orientation (0 if unknown)"""
    from hcbuild import meshes_under
    from tmbmesh import decode
    z = []
    for m in meshes_under(car, d['grp']):
        try:
            P = np.asarray(decode(bytes(car.n), m)['pos'], float)
        except Exception:
            continue
        if len(P):
            z.append((P @ d['Mown'])[:, 2].min())
    return min(z) if z else 0.0


def on_body(p, pts, box, zmin=0.0, inset=0.8):
    """a point moved onto / into the new body: x / y clamped inside the body box (x to inset * half width), then
    if it is above the body's top at that spot (vertices within 0.6 in x / y) it drops onto that top (its model's
    lowest point on the surface), below the bottom it rises to it. Without body points: the clamp only."""
    lo, hi = np.asarray(box[0], float), np.asarray(box[1], float)
    q = np.asarray(p, float).copy()
    hw = max(-lo[0], hi[0]) * inset
    q[0] = np.clip(q[0], -hw, hw)
    q[1] = np.clip(q[1], lo[1] + 0.3, hi[1] - 0.3)
    q[2] = np.clip(q[2], lo[2], hi[2])
    if pts is None or not len(pts):
        return q, 'clamped'
    for _ in range(12):                          # no body under it (narrow spot): step in towards the centre line
        near = pts[(np.abs(pts[:, 0] - q[0]) < 0.6) & (np.abs(pts[:, 1] - q[1]) < 0.6)]
        if len(near) >= 3:
            break
        q[0] *= 0.8
    else:
        return q, 'clamped (no body under it)'
    top, bot = near[:, 2].max(), near[:, 2].min()
    if q[2] > top:
        q[2] = top - min(zmin, 0.0) * 0.8 if zmin < 0 else top
        return q, 'on the body top (z %.2f)' % top
    if q[2] < bot:
        q[2] = bot
        return q, 'raised to the body bottom (z %.2f)' % bot
    return q, 'inside the body (top %.2f)' % top


def apply(car, rec, L, to_donor, box_d, box_n, name='', log=print, pts=None, skip_chars=()):
    """rec: donor_mounts() of the original donor; L: ho_list(); to_donor(p) maps Head-On space -> donor space;
    box_d / box_n: (lo, hi) of the donor's body and of the new body in donor space; pts: the new body's vertices
    (donor space, kept state-0 meshes) for on_body(); skip_chars: op25 characters the caller already placed (12 Pak's
    rack / antenna). Mounts inside a weapon character move with the whole character (move_char; Ark 2026-10-26:
    weapons floated beside the cars when only the mount under the animated bones moved). Returns report rows."""
    mode = os.environ.get('HC_MOUNTS', '1')
    if mode == '0':
        return []
    pts = None if pts is None else np.asarray(pts, float)
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
    tg = {}
    for node, d in sorted(rec.items()):
        ids = sorted(d['ids'])
        if 4100 in ids:
            if r is not None:
                tgt, how = to_donor(r if d['pos'][0] > 0 else l), src
            else:
                tgt, how = on_body(boxmap(d['pos']), pts, box_n)
                how = 'box map (no Head-On points), ' + how
        elif mode == 'mg':
            continue
        elif d.get('char') in skip_chars and d.get('char') is not None:
            continue
        else:
            tgt, how = None, None
            hit = [i for i in ids if i in over]
            if hit:
                tgt, how = to_donor(over[hit[0]]), 'HC_MOUNT_POS'
            elif mode == 'ho' and d['sub'] in SUB_SLOT:
                pts_ = [p for p in L.get(SUB_SLOT[d['sub']], []) if p is not None]
                if pts_:
                    p = min(pts_, key=lambda q: abs(np.sign(q[0]) - np.sign(d['pos'][0])) * 10 + abs(q[1] - d['pos'][1]) * 0.01)
                    tgt, how = to_donor(np.array(p)), 'Head-On slot %d' % SUB_SLOT[d['sub']]
            if tgt is None:
                tgt, how = on_body(boxmap(d['pos']), pts, box_n, group_zmin(car, d))
                how = 'box map, ' + how
        tg[node] = (np.asarray(tgt, float), how)
    # characters: one translate for all of a character's mounts (their mean move), the rest on the mounts themselves
    bychar = {}
    for node in tg:
        c = rec[node].get('char')
        if c is not None:
            bychar.setdefault(c, []).append(node)
    shift = {}
    for c, nodes in bychar.items():
        dl = np.mean([tg[k][0] - rec[k]['pos'] for k in nodes], axis=0)
        refs = move_char(car, c, rec[nodes[0]]['Mchar'], dl)
        for k in nodes:
            shift[k] = dl if refs else np.zeros(3)
        log('mount char %#x (%d drawn refs): moved by (%.2f %.2f %.2f) for %s' % (c, len(refs), *dl, [hex(k) for k in nodes]))
    # HC_ANIM (default 1): the donor's launcher animations swing / raise the weapon models by up to ~5 units
    # (Outlaw's 4005 arm turns 180 degrees about a hinge at x -4.2, Sweet Tooth's 4004 slides out to x -7.4); with
    # the launcher hardware hidden and a smaller body the deployed weapon hangs in the air beside the car. Each
    # weapon character's bone channels are scaled towards the exported pose (damp_char) by the largest factor
    # (1, 0.9 .. 0) that keeps every animated position of its mounts within the new body box + HC_ANIM_TOL (0.5).
    if os.environ.get('HC_ANIM', '1') == '1':
        tol = float(os.environ.get('HC_ANIM_TOL', '0.5'))
        lo_b, hi_b = np.asarray(box_n[0], float) - tol, np.asarray(box_n[1], float) + tol
        damped = set()
        for c, nodes in sorted(bychar.items()):
            def fits(f):
                for k in nodes:
                    E = mount_envelope(car, rec, k, f=f)
                    P_ = tg[k][0] + (E - E[0])
                    if (P_ < lo_b - 1e-6).any() or (P_ > hi_b + 1e-6).any():
                        return False
                return True
            f = next((x for x in np.round(np.arange(1.0, -0.01, -0.1), 2) if fits(x)), 0.0)
            if f < 1.0:
                nt = damp_char(car, c, f)
            E = np.concatenate([tg[k][0] + (lambda E: E - E[0])(mount_envelope(car, rec, k)) for k in nodes])
            log('mount char %#x: animation %s (animated range x %.2f..%.2f y %.2f..%.2f z %.2f..%.2f)' % (
                c, 'kept' if f >= 1.0 else 'scaled by %.1f (%d channels)' % (f, nt), E[:, 0].min(), E[:, 0].max(),
                E[:, 1].min(), E[:, 1].max(), E[:, 2].min(), E[:, 2].max()))
    rows = []
    for node, (tgt, how) in sorted(tg.items()):
        d = rec[node]
        old = d['pos'].copy()
        res = move(car, rec, node, tgt, shift.get(node))
        rows.append((sorted(d['ids']), node, d['kind'], d['sub'], old, tgt, how))
        log('mount %-10s node %#x (switch type %s sub %s): (%.2f %.2f %.2f) -> (%.2f %.2f %.2f)  %s%s' % (
            '/'.join(map(str, sorted(d['ids']))), node, d['kind'], d['sub'], *old, *tgt, how,
            '; on the mount %.2f' % np.linalg.norm(res) if node in shift else ''))
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


# ---------------------------------------------------------------- donor lights (HC_LIGHTS, default 1)
# TMB car lights are op5 nodes (+8 range, +0x30 colour; a flare / glow drawn at the node's place). Headlights: two op5
# under the op6 switch id R+9 (with glow quads and long beam cones, all under op4s below it), Outlaw's light bar
# beacons (4 op5 on bones of char 0x67a80, z 5.19) and Junkyard Dog's roof lamps (4 op5 on char 0x69360, z 5.56,
# with the lamp meshes) hang outside the high LOD, so hcbuild kept them: floating lights on the new cars (Ark
# 2026-10-26, Twister / Old Pickup). HC_LIGHTS=1: lights that are not headlights are unlinked and the meshes of the
# character carrying them hidden; the headlight assembly moves (one translate under the R+9 switch, plus x on each
# flare's own op4) to the front of the new body. HC_LIGHTS=0: as before.

def donor_lights(car):
    """[(op5 node, car-space pos, parent slots, headlight switch or None, nearest op25 above or None)] on entry 0"""
    from hcbuild import kids
    n = car.n
    R = u32(n, u32(n, 4) - BASE) >> 18
    out, seen = [], set()
    st = [(u32(n, 4) - BASE, np.eye(3), np.zeros(3), ())]
    while st:
        o, M, t, ch = st.pop()
        if o in ch or len(ch) > 60:
            continue
        ch = ch + (o,)
        if (u32(n, o) & 0x3f) == 5:
            if o not in seen:
                seen.add(o)
                sw = next((x for x in reversed(ch) if (u32(n, x) & 0x3f) == 6 and (u32(n, x) >> 18) == R + 9), None)
                c25 = next((x for x in reversed(ch) if (u32(n, x) & 0x3f) == 25), None)
                out.append((o, t.copy(), [sl for sl in car.slots if car.P(sl) == o], sw, c25, ch))
            continue
        x = _xf(n, o)
        if x is not None:
            Rm, tt = x
            t = tt @ M + t
            M = Rm @ M
        for k in kids(car, o):
            st.append((k, M, t, ch))
    return out


def fix_lights(car, pts, box_n, log=print, ho_heads=None):
    """HC_LIGHTS: returns the donor meshes to hide (light bars). pts: new body vertices (donor space); ho_heads: the
    new car's own headlight points {+1: right, -1: left} (donor space, from its flare quads) when it has them."""
    from hcbuild import meshes_under
    if os.environ.get('HC_LIGHTS', '1') == '0':
        return set()
    n = car.n
    L = donor_lights(car)
    hide = set()
    empty = None
    heads = {}
    for o, p, slots, sw, c25, ch in L:
        if sw is None:
            if empty is None:
                empty = car.append(struct.pack('<4I', 9, 0, 0, 0))
            for sl in slots:
                car.setp(sl, empty)
            hm = set(meshes_under(car, c25)) if c25 is not None else set()
            hide |= hm
            log('light %#x at (%.2f %.2f %.2f) colour (%.2f %.2f %.2f): unlinked (%d refs)%s' % (
                o, *p, *struct.unpack_from('<3f', n, o + 0x30), len(slots),
                ', meshes of its character %#x hidden (%d)' % (c25, len(hm)) if c25 is not None else ''))
        else:
            heads.setdefault(sw, []).append((o, p, ch))
    P = np.asarray(pts, float)
    lo, hi = np.asarray(box_n[0], float), np.asarray(box_n[1], float)
    hw = max(-lo[0], hi[0])
    for sw, lights in heads.items():
        tg = []
        F = P[P[:, 1] >= hi[1] - 1.5]                   # the front 1.5 of the body
        if len(F) < 3:
            F = P
        for o, p, ch in lights:
            if ho_heads and np.sign(p[0]) in ho_heads:
                tg.append(np.asarray(ho_heads[np.sign(p[0])], float)); continue
            x = np.sign(p[0]) * min(abs(p[0]), 0.8 * np.abs(F[:, 0]).max())
            for r in (0.4, 0.7, 1.0, 1.5, 3.0, 99.0):    # the front face around x: its foremost y, z kept inside it
                near = F[np.abs(F[:, 0] - x) < r]
                if len(near) >= 3:
                    break
            q = np.array([x, near[:, 1].max() + 0.05, np.clip(p[2], near[:, 2].min(), near[:, 2].max())])
            tg.append(q)
        d = np.mean([q - p for q, (o, p, ch) in zip(tg, lights)], axis=0)
        # one translate between the switch and its drawn kids (its op9 'off' kid stays)
        from hcbuild import kids
        ks = [(i, car.P(sw + 0xc + 4 * i)) for i in range(n[sw + 0xb])]
        for i, k in ks:
            if k is None or (u32(n, k) & 0x3f) == 9:
                continue
            t3 = car.append(struct.pack('<IIIIfffI', 3, 0, 1, 0, *d, 0))
            car.setp(t3 + 0x1c, k)
            car.setp(sw + 0xc + 4 * i, t3)
        # x of each flare on its own op4 / op3 parent (in that parent's frame: rotation only matters, the op4s here
        # are translations)
        for q, (o, p, ch) in zip(tg, lights):
            par = ch[-2]
            dx = q[0] - (p[0] + d[0])
            if (u32(n, par) & 0x3f) in (3, 4) and abs(dx) > 0.01:
                M = np.eye(3)                                # rotation of the frame par sits in
                for a in ch[:-2]:
                    x_ = _xf(n, a)
                    if x_ is not None:
                        M = x_[0] @ M
                off = 0x10 if (u32(n, par) & 0x3f) == 3 else 0x40
                tl = np.array(struct.unpack_from('<3f', n, par + off)) + np.array([dx, 0, 0]) @ np.linalg.inv(M)
                struct.pack_into('<3f', n, par + off, *tl)
            log('headlight %#x: (%.2f %.2f %.2f) -> (%.2f %.2f %.2f)' % (o, *p, *q))
        log('headlight switch %#x: assembly moved by (%.2f %.2f %.2f)' % (sw, *d))
    return hide
