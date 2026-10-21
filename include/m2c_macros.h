#ifndef M2C_MACROS_H
#define M2C_MACROS_H
/* Minimal definitions so raw m2c drafts (--valid-syntax) compile. M2C_ERROR is left undefined on
 * purpose: drafts where m2c gave up fail to compile and are skipped. */
#include "common.h"
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef long long M2C_UNK64;
/* m2c passes the POINTER type: M2C_FIELD(p, f32*, 0x10) is the f32 at p+0x10 */
#define M2C_FIELD(expr, type, offset) (*(type)((u8*)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
/* Old (wrong) form, kept only for functions matched before 2026-10-20 evening; their bytes are verified. */
#define M2C_FIELD_V1(expr, type, offset) (*(type*)((u8*)(expr) + (offset)))
#ifndef NULL
#define NULL 0
#endif
typedef float f32;
typedef double f64;
#endif
