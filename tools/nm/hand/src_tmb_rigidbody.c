//@@ applyWorldForce__9RigidBodyR8_fvector hand
/* RigidBody (offsets): +0 mass, +0x10 local centre of mass, +0x30 cs (cs+0x10 position, cs+0x20 rotation rows),
 * +0x40 world centre of mass, +0x50 / +0xB0 linear state pair (see func_00231A18 / func_00230D88),
 * +0xC0 angular velocity, +0xD0 force accumulator, +0xE0 torque accumulator. (VU0 quads: .w words kept.) */
/* force += f */
void applyWorldForce__9RigidBodyR8_fvector(char* rb, float* f)
{
    float* a = (float*)(rb + 0xD0);
    a[0] += f[0]; a[1] += f[1]; a[2] += f[2];
}
//@@ func_00230BF0 hand
/* force += R * f (a force in the body's frame) */
extern void applyWorldForce__9RigidBodyR8_fvector(char* rb, float* f);
void func_00230BF0(char* rb, float* f)
{
    float* m = (float*)(*(char**)(rb + 0x30) + 0x20);
    float t[4] __attribute__((aligned(16)));
    t[0] = m[0] * f[0] + m[4] * f[1] + m[8] * f[2];
    t[1] = m[1] * f[0] + m[5] * f[1] + m[9] * f[2];
    t[2] = m[2] * f[0] + m[6] * f[1] + m[10] * f[2];
    t[3] = f[3];
    applyWorldForce__9RigidBodyR8_fvector(rb, t);
}
//@@ func_00230D38 hand
/* torque += (p - world centre of mass) x f (a force f applied at world point p) */
void func_00230D38(char* rb, float* f, float* p)
{
    float* c = (float*)(rb + 0x40);
    float* t = (float*)(rb + 0xE0);
    float rx = p[0] - c[0], ry = p[1] - c[1], rz = p[2] - c[2];
    t[0] += ry * f[2] - f[1] * rz;
    t[1] += rz * f[0] - f[2] * rx;
    t[2] += rx * f[1] - f[0] * ry;
}
//@@ func_00230D88 hand
/* +0x50 += d; +0xB0 = +0x50 * mass (whole quad: .w = +0x50's) */
void func_00230D88(char* rb, float* d)
{
    float* a = (float*)(rb + 0x50);
    float* b = (float*)(rb + 0xB0);
    float m = *(float*)rb;
    a[0] += d[0]; a[1] += d[1]; a[2] += d[2];
    b[0] = a[0] * m; b[1] = a[1] * m; b[2] = a[2] * m; b[3] = a[3];
}
//@@ func_00230E48 hand
/* func_00230D88(rb, R * d): a change given in the body's frame */
extern void func_00230D88(char* rb, float* d);
void func_00230E48(char* rb, float* d)
{
    float* m = (float*)(*(char**)(rb + 0x30) + 0x20);
    float t[4] __attribute__((aligned(16)));
    t[0] = m[0] * d[0] + m[4] * d[1] + m[8] * d[2];
    t[1] = m[1] * d[0] + m[5] * d[1] + m[9] * d[2];
    t[2] = m[2] * d[0] + m[6] * d[1] + m[10] * d[2];
    t[3] = d[3];
    func_00230D88(rb, t);
}
//@@ func_00231A18 hand
/* +0xB0 = v (whole quad); +0x50 = v / mass (.w = v.w) */
void func_00231A18(char* rb, float* v)
{
    float* a = (float*)(rb + 0x50);
    float* b = (float*)(rb + 0xB0);
    float k = 1.0f / *(float*)rb;
    b[0] = v[0]; b[1] = v[1]; b[2] = v[2]; b[3] = v[3];
    a[0] = v[0] * k; a[1] = v[1] * k; a[2] = v[2] * k; a[3] = v[3];
}
//@@ func_00230858 hand
/* move by d: cs position += d, world centre of mass += d */
void func_00230858(char* rb, float* d)
{
    float* p = (float*)(*(char**)(rb + 0x30) + 0x10);
    float* c = (float*)(rb + 0x40);
    p[0] += d[0]; p[1] += d[1]; p[2] += d[2];
    c[0] += d[0]; c[1] += d[1]; c[2] += d[2];
}
//@@ func_00230810 hand
/* place at p: cs position = p (whole quad), world centre of mass keeps its offset from it (.w = p.w) */
void func_00230810(char* rb, float* p)
{
    float* cp = (float*)(*(char**)(rb + 0x30) + 0x10);
    float* c = (float*)(rb + 0x40);
    float ox = c[0] - cp[0], oy = c[1] - cp[1], oz = c[2] - cp[2];
    cp[0] = p[0]; cp[1] = p[1]; cp[2] = p[2]; cp[3] = p[3];
    c[0] = cp[0] + ox; c[1] = cp[1] + oy; c[2] = cp[2] + oz; c[3] = cp[3];
}
//@@ func_00231978 hand
/* world centre of mass = R * local centre of mass + cs position (.w = local's .w) */
void func_00231978(char* rb)
{
    char* cs = *(char**)(rb + 0x30);
    float* m = (float*)(cs + 0x20);
    float* p = (float*)(cs + 0x10);
    float* l = (float*)(rb + 0x10);
    float* c = (float*)(rb + 0x40);
    float x = m[0] * l[0] + m[4] * l[1] + m[8] * l[2];
    float y = m[1] * l[0] + m[5] * l[1] + m[9] * l[2];
    float z = m[2] * l[0] + m[6] * l[1] + m[10] * l[2];
    c[3] = l[3];
    c[0] = x + p[0]; c[1] = y + p[1]; c[2] = z + p[2];
}
//@@ func_002319C8 hand
/* velocity of world point p: out = w x (p - world centre of mass) + (+0xB0)  (w = +0xC0; out.w = w.w) */
void func_002319C8(char* rb, float* out, float* p)
{
    float* c = (float*)(rb + 0x40);
    float* w = (float*)(rb + 0xC0);
    float* v = (float*)(rb + 0xB0);
    float rx = p[0] - c[0], ry = p[1] - c[1], rz = p[2] - c[2];
    float x = w[1] * rz - ry * w[2], y = w[2] * rx - rz * w[0], z = w[0] * ry - rx * w[1];
    out[3] = w[3];
    out[0] = x + v[0]; out[1] = y + v[1]; out[2] = z + v[2];
}
