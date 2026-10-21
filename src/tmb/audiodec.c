#include "common.h"

#include "m2c_macros.h"
s32 func_001FADB8_2468C8() __asm__("func_001FADB8");

s32 func_002468C8(void *arg0, s32 arg1, s32 arg2, s32 arg3)
{
  s32 temp_v0;
  int new_var;
  *((s32 *) (((u8 *) arg0) + 0x30)) = arg1;
  *((s32 *) (((u8 *) arg0) + 0x3C)) = arg2;
  new_var = 0;
  *((s32 *) (((u8 *) arg0) + new_var)) = new_var;
  *((s32 *) (((u8 *) arg0) + 0x2C)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x34)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x38)) = new_var;
  *((s32 *) (((u8 *) arg0) + 0x40)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x54)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x4C)) = new_var;
  *((s32 *) (((u8 *) arg0) + 0x50)) = new_var;
  *((s32 *) (((u8 *) arg0) + 0x48)) = arg3;
  temp_v0 = func_001FADB8_2468C8(arg3, 0x400, 0, 6);
  *((s32 *) (((u8 *) arg0) + 0x44)) = temp_v0;
  return (temp_v0 < new_var) ^ 1;
}

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
