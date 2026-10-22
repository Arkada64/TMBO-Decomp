#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/audiodec", audioDecCreate__FP8AudioDecPUcii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/audiodec", audioDecReset__FP8AudioDec);

M2C_UNK snd_CloseMovieSound_28_6() __asm__("snd_CloseMovieSound");
M2C_UNK snd_ResetMovieSound_28_6() __asm__("snd_ResetMovieSound");

s32 audioDecDelete__FP8AudioDec(void* arg0) {
    snd_ResetMovieSound_28_6();
    snd_CloseMovieSound_28_6();
    return 1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/audiodec", audioDecBeginPut__FP8AudioDecPPUcPiT1T2);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/audiodec", audioDecEndPut__FP8AudioDeci);

s32 audioDecIsPreset__FP8AudioDec(void* arg0) {
    return (M2C_FIELD(arg0, s32* , 0x54) < M2C_FIELD(arg0, s32* , 0x48)) ^ 1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/audiodec", audioDecStart__FP8AudioDec);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/audiodec", audioDecSendToIOP__FP8AudioDec);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/audiodec", iopGetArea__FPiT0T0T0P8AudioDeci);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/audiodec", sendToIOP2area__FiiiiPUciT4i);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/audiodec", sendToIOP__FiPUci);

s32 snd_PauseMovieSound_3C_28() __asm__("snd_PauseMovieSound");

s32 audioDecPause__FP8AudioDec(void* arg0) {
    M2C_FIELD(arg0, s32* , 0) = 3;
    M2C_FIELD(arg0, s32* , 0x50) = (s32) (snd_PauseMovieSound_3C_28() - M2C_FIELD(arg0, s32* , 0x44));
    return 1;
}

int audioDecStart__FP8AudioDec_1C_31(void*) __asm__("audioDecStart__FP8AudioDec");
s32 audioDecResume__FP8AudioDec(void* arg0) {
    return audioDecStart__FP8AudioDec_1C_31(arg0);
}
