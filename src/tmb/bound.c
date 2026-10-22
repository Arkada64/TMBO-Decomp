#include "common.h"
#include "m2c_macros.h"

M2C_UNK boundFAngle__FPf_30_2() __asm__("boundFAngle__FPf");

void boundFVector__FP8_fvector(s32 arg0) {
    boundFAngle__FPf_30_2();
    boundFAngle__FPf_30_2(arg0 + 4);
    boundFAngle__FPf_30_2(arg0 + 8);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/bound", boundFAngle__FPf);
