#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/utilities", loadShellTextureFile__10BlitMasterPCc);

void preloadShellTextureFile__10BlitMasterPCc(void) {
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/utilities", blitToZBuffer__10BlitMasteriiibi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/utilities", blitToFrameBuffer__10BlitMasteriii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/utilities", DMAToScratchPad__FP6QwDatai);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/utilities", DMARestoreFromScratchPad__FP6QwDataT0i);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/utilities", WaitDMA__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/utilities", buildProgressBar__FUi);

extern u8 loadbarBuf_C_21[] __asm__("loadbarBuf");

s32 getLoadbarPacket__Fv(void) {
    return (s32) ((u8*)loadbarBuf_C_21);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/utilities", initProgressBar__Fiiib);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/utilities", informProgressBar__Ff);
