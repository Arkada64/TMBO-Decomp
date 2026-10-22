#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/disp", dispCreate__FP8_Displayii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/disp", dispSetTags__FP8_DisplayPUiPviiiiiii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/disp", setDMAscTag__FPUiUiPvUiUiUiUi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/disp", setGIFtag__FPUiUlUiUiUiUiUiUi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/disp", setGIFad__FPUiUiUl);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/disp", setBITBLTBUF__FPUiUiUiUi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/disp", setTRXPOS__FPUiUiUiUi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/disp", setTRXREG__FPUiUiUi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/disp", setTRXDIR__FPUiUi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/disp", setPMODE__F12PMODESetting);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/disp", vblankHandler__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/disp", handler_endimage__Fi);

s32 sceGsSyncV_34_29() __asm__("sceGsSyncV");
extern u8 isCountVblank_34_29[4] __asm__("isCountVblank");

void startDisplay__Fi(s32 arg0) {
    do {

    } while (sceGsSyncV_34_29(0) == arg0);
    (*(s32*)isCountVblank_34_29) = 1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/disp", endDisplay__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/disp", blitLastMovieFrame__Fv);
