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
