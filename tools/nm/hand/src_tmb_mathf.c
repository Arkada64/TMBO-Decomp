//@@ mathfMulVec4x4__FPA3_fP8_fvectorT1 hand
/* VU0: out[i] = M[i].xyz . v.xyz + M[i].w   (rows 16 bytes apart; v.w unused) */
void mathfMulVec4x4__FPA3_fP8_fvectorT1(float* m, float* v, float* out)
{
    float r[4];
    int i;
    for (i = 0; i < 4; i++) {
        float* row = m + 4 * i;
        r[i] = row[0] * v[0] + (row[1] * v[1] + (row[2] * v[2] + row[3]));
    }
    for (i = 0; i < 4; i++) out[i] = r[i];
}
//@@ func_0021D300 hand
/* VU0: out.xyz = M0 * v.x + M1 * v.y + M2 * v.z (rows 0..2), out.w = v.w */
void func_0021D300(float* m, float* v, float* out)
{
    float x = v[0], y = v[1], z = v[2], w = v[3];
    int i;
    for (i = 0; i < 3; i++) out[i] = m[i] * x + m[4 + i] * y + m[8 + i] * z;
    out[3] = w;
}
//@@ mathfMulTransVec4x4__FPA3_fP8_fvectorT1 hand
/* VU0: out = M0 * v.x + M1 * v.y + M2 * v.z + M3 (all four components; v.w unused) */
void mathfMulTransVec4x4__FPA3_fP8_fvectorT1(float* m, float* v, float* out)
{
    float x = v[0], y = v[1], z = v[2];
    float r[4];
    int i;
    for (i = 0; i < 4; i++) r[i] = m[i] * x + m[4 + i] * y + m[8 + i] * z + m[12 + i];
    for (i = 0; i < 4; i++) out[i] = r[i];
}
//@@ mathfUnitMatrixAsm__FPA3_f hand
/* 4x4 identity (built from vf0 = 0,0,0,1 with qmfc2 / prot3w) */
void mathfUnitMatrixAsm__FPA3_f(float* m)
{
    int i;
    for (i = 0; i < 16; i++) m[i] = (i % 5 == 0) ? 1.0f : 0.0f;
}
//@@ func_0021EA80 hand
/* d.xyz = c - b, d.w = c.w; mathfRotationFromVector(a, &d) */
extern void mathfRotationFromVector__FP8_fvectorT0(void* a, float* d);
void func_0021EA80(void* a, float* b, float* c)
{
    float d[4] __attribute__((aligned(16)));
    d[0] = c[0] - b[0]; d[1] = c[1] - b[1]; d[2] = c[2] - b[2]; d[3] = c[3];
    mathfRotationFromVector__FP8_fvectorT0(a, d);
}
//@@ mathfDist2__FP8_fvectorT0 hand
/* 2D (x, y) distance from a to b; b == NULL: from the origin */
#ifdef __mips__
static float nm_sqrt(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
#else
#include <math.h>
#define nm_sqrt sqrtf
#endif
float mathfDist2__FP8_fvectorT0(float* a, float* b)
{
    float dx, dy;
    if (b == 0) { dy = a[1]; dx = a[0]; }
    else { dy = b[1] - a[1]; dx = b[0] - a[0]; }
    return nm_sqrt(dx * dx + dy * dy);
}
//@@ mathfMulMatrix__FPA3_fT0T0 hand
/* VU0: out = A * B (4x4, rows 16 bytes): out row i = sum_k A[i][k] * B row k. All inputs read first (out may alias). */
void mathfMulMatrix__FPA3_fT0T0(float* out, float* a, float* b)
{
    float r[16];
    int i, j;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            r[4 * i + j] = b[j] * a[4 * i] + b[4 + j] * a[4 * i + 1] + b[8 + j] * a[4 * i + 2] + b[12 + j] * a[4 * i + 3];
    for (i = 0; i < 16; i++) out[i] = r[i];
}
//@@ func_0021D258 hand
/* VU0: out.xyz = M(3x3 rows, 16 bytes apart) * v.xyz, out.w = v.w */
void func_0021D258(float* m, float* v, float* out)
{
    float x = v[0], y = v[1], z = v[2], w = v[3];
    float r0 = (m[0] * x + m[1] * y) + m[2] * z;
    float r1 = (m[6] * z + m[4] * x) + m[5] * y;
    float r2 = (m[8] * x + m[9] * y) + m[10] * z;
    out[0] = r0; out[1] = r1; out[2] = r2; out[3] = w;
}
//@@ mathfDist3__FP8_fvectorT0 hand
/* 3D distance from a to b; b == NULL: length of a */
#ifdef __mips__
static float nm_sqrt3(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
#else
#include <math.h>
#define nm_sqrt3 sqrtf
#endif
float mathfDist3__FP8_fvectorT0(float* a, float* b)
{
    float dx, dy, dz;
    if (b == 0) { dx = a[0]; dy = a[1]; dz = a[2]; }
    else { dx = b[0] - a[0]; dy = b[1] - a[1]; dz = b[2] - a[2]; }
    return nm_sqrt3(dx * dx + dy * dy + dz * dz);
}
//@@ mathfRotationFromVector__FP8_fvectorT0 hand
/* angles of a direction: out = (pitch atan2(z, |xy|), 0, heading atan2(x, y)) */
#ifdef __mips__
static float nm_sqrt4(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
#else
#include <math.h>
#define nm_sqrt4 sqrtf
#endif
extern float atan2f(float, float);
void mathfRotationFromVector__FP8_fvectorT0(float* out, float* v)
{
    float h = nm_sqrt4(v[0] * v[0] + v[1] * v[1]);
    out[0] = atan2f(v[2], h);
    *(int*)&out[1] = 0;
    out[2] = atan2f(v[0], v[1]);
}
//@@ func_0021EC18 hand
/* pitch of a direction: atan2(z, |xy|) */
#ifdef __mips__
static float nm_sqrt5(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
#else
#include <math.h>
#define nm_sqrt5 sqrtf
#endif
extern float atan2f(float, float);
float func_0021EC18(float* v)
{
    return atan2f(v[2], nm_sqrt5(v[0] * v[0] + v[1] * v[1]));
}
//@@ mathfPitchFromPointToPoint__FP8_fvectorT0 hand
/* pitch of b - a */
extern float func_0021EC18(float* v);
float mathfPitchFromPointToPoint__FP8_fvectorT0(float* a, float* b)
{
    float d[4] __attribute__((aligned(16)));
    d[0] = b[0] - a[0]; d[1] = b[1] - a[1]; d[2] = b[2] - a[2]; d[3] = b[3];
    return func_0021EC18(d);
}
//@@ func_0021EB98 hand
/* heading of b - a (func_0021EBC8 on the difference) */
extern float func_0021EBC8(float* v);
float func_0021EB98(float* a, float* b)
{
    float d[4] __attribute__((aligned(16)));
    d[0] = b[0] - a[0]; d[1] = b[1] - a[1]; d[2] = b[2] - a[2]; d[3] = b[3];
    return func_0021EBC8(d);
}
//@@ func_0021ED28 hand
/* remove the b component: k = a.b; tmp.xyz = b * k (tmp.w = b.w); out.xyz = a - tmp (out.w = a.w); returns k */
float func_0021ED28(float* a, float* b, float* out, float* tmp)
{
    float k = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
    float t0 = b[0] * k, t1 = b[1] * k, t2 = b[2] * k, tw = b[3];
    tmp[0] = t0; tmp[1] = t1; tmp[2] = t2; tmp[3] = tw;
    out[0] = a[0] - t0; out[1] = a[1] - t1; out[2] = a[2] - t2; out[3] = a[3];
    return k;
}
