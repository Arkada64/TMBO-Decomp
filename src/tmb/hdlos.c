#include "common.h"
#include "m2c_macros.h"

int hdLosTest__FP8_fvectorT0P9_hdResulti_2C_0(void*, void*, void*, int) __asm__("hdLosTest__FP8_fvectorT0P9_hdResulti");
extern u8 doCSTest_2C_0[4] __asm__("doCSTest");
extern u8 hdIgnoreInteractive_hdlos_2C_0[4] __asm__("hdIgnoreInteractive_hdlos");

s32 hdLosCsTest__FP8_fvectorT0P9_hdResultii(void* arg0, void* arg1, void* arg2, s32 arg3, s32 arg4) {
    s32 temp_v0;

    (*(s32*)hdIgnoreInteractive_hdlos_2C_0) = arg3;
    (*(s32*)doCSTest_2C_0) = 1;
    temp_v0 = hdLosTest__FP8_fvectorT0P9_hdResulti_2C_0(arg0, arg1, arg2, arg4);
    (*(s32*)doCSTest_2C_0) = 0;
    return temp_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hdlos", hdLosTest__FP8_fvectorT0P9_hdResulti);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hdlos", hdWalkColGrid__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hdlos", hdColGrid_hdlos__FP8_fvectorT0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hdlos", hdTraverse_hdlos__FPP9_hierhead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hdlos", hdPush_hdlos__FPP9_hierheadiP8_fvectorT2UiP17_animCharInstance);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hdlos", hdPop_hdlos__FP8_hdstackPP9_hierhead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hdlos", hdSphereTest_hdlos__FP8_fvectorfT0T0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hdlos", hdColNode_hdlos__FP20_hiercollisionvolume);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hdlos", hdAnimTransNode_hdlos__FP14_animtransformPP9_hierhead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hdlos", hdBspNode_hdlos__FP12_hierbspnode);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hdlos", hdLosResult__FP20_hiercollisionvolumei);

extern u8 hdModelMode_10_29[4] __asm__("hdModelMode");
extern u8 worldEpNode_10_29[4] __asm__("worldEpNode");

s32 hdSetModelMode__FP9_hierhead(void* arg0) {
    (*(void**)worldEpNode_10_29) = arg0;
    (*(s32*)hdModelMode_10_29) = 1;
    return 1;
}
