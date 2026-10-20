#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/movie", func_00222048);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/movie", func_002220B8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/movie", updateMpegMovieDecoding__Fb);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/movie", func_002224C0);

#include "m2c_macros.h"
M2C_UNK RotateThreadReadyQueue_ad__Fv() __asm__("RotateThreadReadyQueue");

void switchThread__Fv(void) {
    RotateThreadReadyQueue_ad__Fv(2);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/movie", isAudioOK__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/movie", func_00222820);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/movie", termAll__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/movie", func_00222B10);

void ErrMessage__FPc(void) {
}

#include "m2c_macros.h"
M2C_UNK audioDecSendToIOP__FP8AudioDec_io__Fv() __asm__("audioDecSendToIOP__FP8AudioDec");
extern M2C_UNK D_004B4860_io__Fv __asm__("D_004B4860");

s32 proceedAudio__Fv(void) {
    audioDecSendToIOP__FP8AudioDec_io__Fv(&D_004B4860_io__Fv);
    return 1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/movie", loadImage__FPUi);
