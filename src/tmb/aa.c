#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/aa", func_001FAFF0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/aa", setAlpha__12MotionBlurAAfi);

#include "m2c_macros.h"
extern M2C_UNK D_00465E40_urAAbi __asm__("D_00465E40");

void setEnable__12MotionBlurAAbi(s32 arg0, s32 arg1) {
    *((arg1 * 0x1) + &D_00465E40_urAAbi) = arg0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/aa", setEnlarge__12MotionBlurAAfi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/aa", drawOverlay__12MotionBlurAAii);
