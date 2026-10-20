#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/videodec", func_002442C0);

#include "m2c_macros.h"
M2C_UNK sceMpegSetDecodeMode_2443C0() __asm__("sceMpegSetDecodeMode");

void func_002443C0(void) {
    sceMpegSetDecodeMode_2443C0();
}

#include "m2c_macros.h"
M2C_UNK sceMpegAddStrCallback_Pv_iPv() __asm__("sceMpegAddStrCallback");

s32 videoDecSetStream__FP8VideoDeciiPFP7sceMpegP13sceMpegCbDataPv_iPv(void) {
    sceMpegAddStrCallback_Pv_iPv();
    return 1;
}

#include "m2c_macros.h"
M2C_UNK func_002489E8_PiT1T2() __asm__("func_002489E8");

void videoDecBeginPut__FP8VideoDecPPUcPiT1T2(s32 arg0) {
    func_002489E8_PiT1T2(arg0 + 0x48);
}

#include "m2c_macros.h"
M2C_UNK func_00248AE0_eoDeci() __asm__("func_00248AE0");

void videoDecEndPut__FP8VideoDeci(s32 arg0) {
    func_00248AE0_eoDeci(arg0 + 0x48);
}

#include "m2c_macros.h"
s32 videoDecReset__FP8VideoDec(void* arg0) {
    M2C_FIELD(arg0, s32* , 0xA8) = 0;
    return 1;
}

#include "m2c_macros.h"
M2C_UNK func_00249180_deoDec() __asm__("func_00249180");
M2C_UNK sceMpegDelete_deoDec() __asm__("sceMpegDelete");

s32 videoDecDelete__FP8VideoDec(s32 arg0) {
    func_00249180_deoDec(arg0 + 0x48);
    sceMpegDelete_deoDec(arg0);
    return 1;
}

#include "m2c_macros.h"
s32 videoDecAbort__FP8VideoDec(void* arg0) {
    M2C_FIELD(arg0, s32* , 0xA8) = 1;
    return 1;
}

#include "m2c_macros.h"
s32 videoDecGetState__FP8VideoDec(void* arg0) {
    return M2C_FIELD(arg0, s32* , 0xA8);
}

#include "m2c_macros.h"
s32 videoDecSetState__FP8VideoDecUi(void* arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32* , 0xA8);
    M2C_FIELD(arg0, s32* , 0xA8) = arg1;
    return temp_v0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/videodec", videoDecPutTs__FP8VideoDecllPUci);

#include "m2c_macros.h"
M2C_UNK viBufCount__FP5ViBuf_deoDec() __asm__("viBufCount__FP5ViBuf");

void videoDecInputCount__FP8VideoDec(s32 arg0) {
    viBufCount__FP5ViBuf_deoDec(arg0 + 0x48);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/videodec", func_00244510);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/videodec", videoDecFlush__FP8VideoDec);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/videodec", videoDecIsFlushed__FP8VideoDec);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/videodec", func_00244660);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/videodec", decBs0__FP8VideoDec);

#include "m2c_macros.h"
s32 func_00244900(void) {
    return 1;
}

#include "m2c_macros.h"
M2C_UNK switchThread__Fv_244908() __asm__("switchThread__Fv");
M2C_UNK viBufAddDMA__FP5ViBuf_244908() __asm__("viBufAddDMA__FP5ViBuf");
extern M2C_UNK D_004B4788_244908 __asm__("D_004B4788");

s32 func_00244908(void) {
    switchThread__Fv_244908();
    viBufAddDMA__FP5ViBuf_244908(&D_004B4788_244908);
    return 1;
}

#include "m2c_macros.h"
M2C_UNK viBufStopDMA__FP5ViBuf_244938() __asm__("viBufStopDMA__FP5ViBuf");
extern M2C_UNK D_004B4788_244938 __asm__("D_004B4788");

s32 func_00244938(void) {
    viBufStopDMA__FP5ViBuf_244938(&D_004B4788_244938);
    return 1;
}

#include "m2c_macros.h"
M2C_UNK viBufRestartDMA__FP5ViBuf_244960() __asm__("viBufRestartDMA__FP5ViBuf");
extern M2C_UNK D_004B4788_244960 __asm__("D_004B4788");

s32 func_00244960(void) {
    viBufRestartDMA__FP5ViBuf_244960(&D_004B4788_244960);
    return 1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/videodec", func_00244988);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/videodec", cpy2area__FPUciT0iT0iT0i);
