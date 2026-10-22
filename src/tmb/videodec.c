#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/videodec", videoDecCreate__FP8VideoDecPUciPUI80T3iP9TimeStampi);

M2C_UNK sceMpegSetDecodeMode_8_4() __asm__("sceMpegSetDecodeMode");

void videoDecSetDecodeMode__FP8VideoDeciii(void) {
    sceMpegSetDecodeMode_8_4();
}

M2C_UNK sceMpegAddStrCallback_20_6() __asm__("sceMpegAddStrCallback");

s32 videoDecSetStream__FP8VideoDeciiPFP7sceMpegP13sceMpegCbDataPv_iPv(void* arg0, s32 arg1, s32 arg2, void* arg3, void* arg4) {
    sceMpegAddStrCallback_20_6();
    return 1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/videodec", videoDecBeginPut__FP8VideoDecPPUcPiT1T2);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/videodec", videoDecEndPut__FP8VideoDeci);

s32 videoDecReset__FP8VideoDec(void* arg0) {
    M2C_FIELD(arg0, s32* , 0xA8) = 0;
    return 1;
}

void viBufDelete__FP5ViBuf_34_16(void*) __asm__("viBufDelete__FP5ViBuf");
M2C_UNK sceMpegDelete_34_16() __asm__("sceMpegDelete");

s32 videoDecDelete__FP8VideoDec(void* arg0) {
    viBufDelete__FP5ViBuf_34_16(arg0 + 0x48);
    sceMpegDelete_34_16(arg0);
    return 1;
}

s32 videoDecAbort__FP8VideoDec(void* arg0) {
    M2C_FIELD(arg0, s32* , 0xA8) = 1;
    return 1;
}

s32 videoDecGetState__FP8VideoDec(void* arg0) {
    return M2C_FIELD(arg0, s32* , 0xA8);
}

s32 videoDecSetState__FP8VideoDecUi(void* arg0, u32 arg1) {
    u32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u32* , 0xA8);
    M2C_FIELD(arg0, u32* , 0xA8) = arg1;
    return (s32) temp_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/videodec", videoDecPutTs__FP8VideoDecllPUci);

int viBufCount__FP5ViBuf_1C_26(void*) __asm__("viBufCount__FP5ViBuf");
s32 videoDecInputCount__FP8VideoDec(void* arg0) {
    return viBufCount__FP5ViBuf_1C_26(arg0 + 0x48);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/videodec", videoDecInputSpaceCount__FP8VideoDec);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/videodec", videoDecFlush__FP8VideoDec);

int videoDecInputCount__FP8VideoDec_48_35(void*) __asm__("videoDecInputCount__FP8VideoDec");
s32 sceMpegIsRefBuffEmpty_48_35() __asm__("sceMpegIsRefBuffEmpty");

s32 videoDecIsFlushed__FP8VideoDec(void* arg0) {
    s32 var_v0;

    var_v0 = 0;
    if (videoDecInputCount__FP8VideoDec_48_35(arg0) == 0) {
        var_v0 = sceMpegIsRefBuffEmpty_48_35(arg0) != 0;
    }
    return var_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/videodec", videoDecMain__FP8VideoDec);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/videodec", decBs0__FP8VideoDec);

M2C_UNK printf_28_43() __asm__("printf");
extern u8 D_004FBC60_28_43[] __asm__("D_004FBC60");

s32 mpegError__FP7sceMpegP18sceMpegCbDataErrorPv(void* arg0, void* arg1, void* arg2) {
    printf_28_43(((u8*)D_004FBC60_28_43), M2C_FIELD(arg1, s32* , 4));
    return 1;
}

void viBufAddDMA__FP5ViBuf_2C_46(void*) __asm__("viBufAddDMA__FP5ViBuf");
void switchThread__Fv_2C_46(void) __asm__("switchThread__Fv");
extern u8 videoDec_2C_46[] __asm__("videoDec");

s32 mpegNodata__FP7sceMpegP13sceMpegCbDataPv(void* arg0, void* arg1, void* arg2) {
    switchThread__Fv_2C_46();
    viBufAddDMA__FP5ViBuf_2C_46(((u8*)videoDec_2C_46) + 0x48);
    return 1;
}

void viBufStopDMA__FP5ViBuf_24_49(void*) __asm__("viBufStopDMA__FP5ViBuf");
extern u8 videoDec_24_49[] __asm__("videoDec");

s32 mpegStopDMA__FP7sceMpegP13sceMpegCbDataPv(void* arg0, void* arg1, void* arg2) {
    viBufStopDMA__FP5ViBuf_24_49(((u8*)videoDec_24_49) + 0x48);
    return 1;
}

void viBufRestartDMA__FP5ViBuf_24_52(void*) __asm__("viBufRestartDMA__FP5ViBuf");
extern u8 videoDec_24_52[] __asm__("videoDec");

s32 mpegRestartDMA__FP7sceMpegP13sceMpegCbDataPv(void* arg0, void* arg1, void* arg2) {
    viBufRestartDMA__FP5ViBuf_24_52(((u8*)videoDec_24_52) + 0x48);
    return 1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/videodec", mpegTS__FP7sceMpegP22sceMpegCbDataTimeStampPv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/videodec", cpy2area__FPUciT0iT0iT0i);
