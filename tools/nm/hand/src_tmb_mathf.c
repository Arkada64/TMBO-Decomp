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
//@@ func_0021D810 hand
/* normalize the three columns of the 3x3 part (rows 16 bytes apart); a column shorter than 1e-7 becomes (0,0,1) */
#ifdef __mips__
static float nm_sqrt6(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
#else
#include <math.h>
#define nm_sqrt6 sqrtf
#endif
void func_0021D810(float* m)
{
    int i;
    for (i = 0; i < 3; i++) {
        float x = m[i], y = m[4 + i], z = m[8 + i];
        float len = nm_sqrt6(x * x + y * y + z * z);
        if (len < 1.0e-7f) { m[i] = 0.0f; m[4 + i] = 0.0f; m[8 + i] = 1.0f; }
        else { float k = 1.0f / len; m[8 + i] = z * k; m[i] = x * k; m[4 + i] = y * k; }
    }
}
//@@ mathfMatrixFromNormal__FPA3_fP8_fvector hand
/* orientation with row 1 = n: row 0 = (ny, -nx, 0) / |n.xy|, row 2 = (-nx nz / h, -ny nz / h, h); rest identity.
 * |n.xy| below 1e-6 (n straight up / down): row 0 = (1,0,0), row 2 = (0, -nz, h) */
#ifdef __mips__
static float nm_sqrt7(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
#else
#include <math.h>
#define nm_sqrt7 sqrtf
#endif
void mathfMatrixFromNormal__FPA3_fP8_fvector(float* m, float* n)
{
    float nz = n[2], h;
    m[4] = n[0]; m[5] = n[1]; m[6] = nz;
    h = nm_sqrt7(n[0] * n[0] + n[1] * n[1]);
    if (h > 1.0e-6f) {
        float a = n[1] / h, b = -n[0] / h;
        m[0] = a; m[1] = b;
        m[8] = b * n[2]; m[9] = -a * n[2];
    } else {
        m[0] = 1.0f; m[1] = 0.0f; m[8] = 0.0f; m[9] = -nz;
    }
    m[10] = h; m[15] = 1.0f;
    m[2] = 0.0f; m[11] = 0.0f; m[7] = 0.0f; m[3] = 0.0f; m[14] = 0.0f; m[13] = 0.0f; m[12] = 0.0f;
}
//@@ func_0021EAB0 hand
/* orientation looking from a to b: mathfMatrixFromNormal(m, normalize(b - a)); nothing when a == b */
extern void mathfMatrixFromNormal__FPA3_fP8_fvector(float* m, float* n);
#ifdef __mips__
static float nm_sqrt8(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
#else
#include <math.h>
#define nm_sqrt8 sqrtf
#endif
void func_0021EAB0(float* m, float* a, float* b)
{
    float d[4] __attribute__((aligned(16)));
    float l2, k;
    d[0] = b[0] - a[0]; d[1] = b[1] - a[1]; d[2] = b[2] - a[2]; d[3] = b[3];
    l2 = d[0] * d[0] + d[1] * d[1] + d[2] * d[2];
    if (!(0.0f < l2)) return;
    k = 1.0f / nm_sqrt8(l2);
    d[0] *= k; d[1] *= k; d[2] *= k;
    mathfMatrixFromNormal__FPA3_fP8_fvector(m, d);
}
//@@ func_0021F7F8 hand
/* quaternion turning unit vector a onto unit vector b: s = sqrt(2 (1 + a.b)); q.xyz = (a x b) / s, q.w = s / 2 */
#ifdef __mips__
static float nm_sqrt9(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
#else
#include <math.h>
#define nm_sqrt9 sqrtf
#endif
void func_0021F7F8(float* q, float* a, float* b)
{
    float cx = a[1] * b[2] - b[1] * a[2];
    float cy = a[2] * b[0] - b[2] * a[0];
    float cz = a[0] * b[1] - b[0] * a[1];
    float d = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
    float s = nm_sqrt9((d + 1.0f) + (d + 1.0f));
    float k = 1.0f / s;
    q[0] = cx * k; q[1] = cy * k; q[2] = cz * k;
    q[3] = s * 0.5f;
}
//@@ func_0021F878 hand
/* normalize quaternion q into out, unless its squared length is already within ~1e-6 of 1 (out untouched then) */
#ifdef __mips__
static float nm_sqrtA(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
#else
#include <math.h>
#define nm_sqrtA sqrtf
#endif
void func_0021F878(float* out, float* q)
{
    float l2 = q[0] * q[0] + q[1] * q[1] + q[2] * q[2] + q[3] * q[3];
    float k;
    if (!(1.00000095367431640625f <= l2) && !(l2 <= 0.99999904632568359375f)) return;
    k = 1.0f / nm_sqrtA(l2);
    out[0] = q[0] * k; out[1] = q[1] * k; out[2] = q[2] * k; out[3] = q[3] * k;
}
//@@ func_0021F928 hand
/* rescale the vector part so q is a unit quaternion for its w: xyz *= sqrt((1 - w^2) / |xyz|^2);
 * |xyz|^2 below 1e-7: xyz = (0, 0, sqrt(1 - w^2)). out.w = q.w */
#ifdef __mips__
static float nm_sqrtB(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
#else
#include <math.h>
#define nm_sqrtB sqrtf
#endif
void func_0021F928(float* out, float* q)
{
    float l2 = q[0] * q[0] + q[1] * q[1] + q[2] * q[2];
    if (l2 < 1.0e-7f) {
        out[0] = 0.0f; out[1] = 0.0f;
        out[2] = nm_sqrtB(1.0f - q[3] * q[3]);
    } else {
        float k = nm_sqrtB((1.0f - q[3] * q[3]) / l2);
        out[0] = q[0] * k; out[1] = q[1] * k; out[2] = q[2] * k;
    }
    out[3] = q[3];
}
//@@ mathfTransform3dTo2d__FiP8_fvectorT1 hand
/* world point p -> screen for view i: t = p + the view's world-eye offset (w = 1), r = WorldToScreen * t;
 * out = (r.x / r.w, r.y / r.w, r.w, r.z / r.w). Nothing when p or out is NULL. */
extern float* viewGetWeTrans__Fi(int i);
extern float* viewGetWorldToScreenMat__Fi(int i);
extern void mathfMulVec4x4__FPA3_fP8_fvectorT1(float* m, float* v, float* out);
void mathfTransform3dTo2d__FiP8_fvectorT1(int i, float* p, float* out)
{
    float t[4] __attribute__((aligned(16))), r[4] __attribute__((aligned(16)));
    float* we = viewGetWeTrans__Fi(i);
    float* m = viewGetWorldToScreenMat__Fi(i);
    float k;
    if (!p || !out) return;
    t[0] = p[0] + we[0]; t[1] = p[1] + we[1]; t[2] = p[2] + we[2]; t[3] = 1.0f;
    mathfMulVec4x4__FPA3_fP8_fvectorT1(m, t, r);
    k = 1.0f / r[3];
    out[2] = r[3];
    out[3] = r[2] * k;
    out[0] = r[0] * k;
    out[1] = r[1] * k;
}
//@@ func_0021ED78 hand
/* re-orthonormalize a rotation's rows: r0 = norm(r1 x r2), r1 = norm(r2 x r0), r2 = norm(r0 x r1).
 * The VU0 code stores whole quads, so the w words move too: m[3] = old m[7], m[7] = old m[11], m[11] = new m[3]. */
#ifdef __mips__
static float nm_sqrtC(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
#else
#include <math.h>
#define nm_sqrtC sqrtf
#endif
static void nm_crossNorm(float* out, float* a, float* b, float w)
{
    float x = a[1] * b[2] - b[1] * a[2], y = a[2] * b[0] - b[2] * a[0], z = a[0] * b[1] - b[0] * a[1];
    float k = 1.0f / nm_sqrtC(x * x + y * y + z * z);
    out[0] = x * k; out[1] = y * k; out[2] = z * k; out[3] = w;
}
void func_0021ED78(float* m)
{
    nm_crossNorm(m, m + 4, m + 8, m[7]);
    nm_crossNorm(m + 4, m + 8, m, m[11]);
    nm_crossNorm(m + 8, m, m + 4, m[3]);
}
