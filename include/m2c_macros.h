#ifndef M2C_MACROS_H
#define M2C_MACROS_H
/* Minimal definitions so raw m2c drafts (--valid-syntax) compile. M2C_ERROR is left undefined on
 * purpose: drafts where m2c gave up fail to compile and are skipped. */
#include "common.h"
typedef s32 M2C_UNK;
#define M2C_FIELD(expr, type, offset) (*(type*)((u8*)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#ifndef NULL
#define NULL 0
#endif
typedef float f32;
typedef double f64;
#endif
