//@@ func_00244510 hand
#include "m2c_macros.h"
M2C_UNK videoDecBeginPut__FP8VideoDecPPUcPiT1T2_244510h() __asm__("videoDecBeginPut__FP8VideoDecPPUcPiT1T2");

s32 func_00244510(void* arg0) {
    s32 sp4;
    M2C_UNK sp8;
    s32 spC;

    videoDecBeginPut__FP8VideoDecPPUcPiT1T2_244510h(arg0, &sp4, &sp8, &spC);
    return sp4 + spC;
}

//@@ func_00244660 hand
#include "m2c_macros.h"
M2C_UNK decBs0__FP8VideoDec_244660h() __asm__("decBs0__FP8VideoDec");
M2C_UNK viBufReset__FP5ViBuf_244660h() __asm__("viBufReset__FP5ViBuf");
M2C_UNK videoDecSetState__FP8VideoDecUi_244660h() __asm__("videoDecSetState__FP8VideoDecUi");
M2C_UNK voBufReset__FP5VoBuf_244660h() __asm__("voBufReset__FP5VoBuf");
extern M2C_UNK D_004B4728_244660h __asm__("D_004B4728");

void func_00244660(s32 arg0) {
    volatile s32* wait;

    viBufReset__FP5ViBuf_244660h(arg0 + 0x48);
    voBufReset__FP5VoBuf_244660h(&D_004B4728_244660h);
    decBs0__FP8VideoDec_244660h(arg0);
    wait = (volatile s32*)((u8*)&D_004B4728_244660h + 0xC);
    while (*wait != 0) {
    }
    videoDecSetState__FP8VideoDecUi_244660h(arg0, 3);
}
