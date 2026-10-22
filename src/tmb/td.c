#include "common.h"
#include "m2c_macros.h"

extern u8 tdEpNode_8_0[4] __asm__("tdEpNode");

void tdInit__Fv(void) {
    (*(s32*)tdEpNode_8_0) = 0;
}

extern u8 tdEpNode_8_3[4] __asm__("tdEpNode");

void tdSetEpNode__FP9_hierhead(void* arg0) {
    (*(void**)tdEpNode_8_3) = arg0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/td", tdTest__FP8_fvectorP9_tdResult);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/td", tdPop__FP8_tdstackPP9_hierhead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/td", tdPush__FPP9_hierheadP8_fvectorUiP17_animCharInstance);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/td", tdTraverse__FP8_fvectorP9_tdResult);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/td", tdSphereTest__FP8_fvectorffT0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/td", tdLodNode__FP8_hierlodPP9_hierhead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/td", tdColTriggerNode__FP21_hiercollisiontriggerP8_fvectorP9_tdResult);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/td", tdAnimTransNode__FP14_animtransformPP9_hierhead);
