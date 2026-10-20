#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/audiodec", func_002468C8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/audiodec", audioDecReset__FP8AudioDec);

#include "m2c_macros.h"
M2C_UNK func_001FADF0_246980() __asm__("func_001FADF0");
M2C_UNK func_001FAE40_246980() __asm__("func_001FAE40");

s32 func_00246980(void) {
    func_001FADF0_246980();
    func_001FAE40_246980();
    return 1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/audiodec", func_002469A8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/audiodec", audioDecEndPut__FP8AudioDeci);

#include "m2c_macros.h"
s32 audioDecIsPreset__FP8AudioDec(void* arg0) {
    return (M2C_FIELD(arg0, s32* , 0x54) < M2C_FIELD(arg0, s32* , 0x48)) ^ 1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/audiodec", audioDecStart__FP8AudioDec);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/audiodec", audioDecSendToIOP__FP8AudioDec);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/audiodec", iopGetArea__FPiT0T0T0P8AudioDeci);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/audiodec", sendToIOP2area__FiiiiPUciT4i);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/audiodec", sendToIOP__FiPUci);

#include "m2c_macros.h"
s32 snd_PauseMovieSound_dioDec() __asm__("snd_PauseMovieSound");

s32 audioDecPause__FP8AudioDec(void* arg0) {
    M2C_FIELD(arg0, s32* , 0) = 3;
    M2C_FIELD(arg0, s32* , 0x50) = (s32) (snd_PauseMovieSound_dioDec() - M2C_FIELD(arg0, s32* , 0x44));
    return 1;
}

#include "m2c_macros.h"
M2C_UNK audioDecStart__FP8AudioDec_dioDec() __asm__("audioDecStart__FP8AudioDec");

void audioDecResume__FP8AudioDec(void) {
    audioDecStart__FP8AudioDec_dioDec();
}
