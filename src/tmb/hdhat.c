#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hdhat", hdHatTest__FP8_fvectorT0P14ColorUnionType);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hdhat", hdColGrid_hdhat__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hdhat", hdHatTraverse__FPP9_hierhead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hdhat", hdHatSphereTestAsm__FP8_fvectorfT0T0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hdhat", hdSphereTest_hdhat__FP8_fvectorfT0T0);

M2C_UNK mathfCopyVector__FP8_fvectorT0_70_8() __asm__("mathfCopyVector__FP8_fvectorT0");
extern u8 hdStackIdx_hdhat_70_8[4] __asm__("hdStackIdx_hdhat");
extern u8 hdStack_hdhat_70_8[] __asm__("hdStack_hdhat");

void hdPush_hdhat__FPP9_hierheadP8_fvectorT1UiP17_animCharInstance(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void* temp_s0;

    temp_s0 = ((*(s32*)hdStackIdx_hdhat_70_8) << 6) + ((u8*)hdStack_hdhat_70_8);
    M2C_FIELD(temp_s0, s32* , 0x20) = arg0;
    M2C_FIELD(temp_s0, s32* , 0x24) = arg3;
    M2C_FIELD(temp_s0, s32* , 0x30) = arg4;
    mathfCopyVector__FP8_fvectorT0_70_8(temp_s0);
    mathfCopyVector__FP8_fvectorT0_70_8(temp_s0 + 0x10, arg2);
    if ((*(s32*)hdStackIdx_hdhat_70_8) < 0x96) {
        (*(s32*)hdStackIdx_hdhat_70_8) += 1;
    }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hdhat", hdPop_hdhat__FP8_hdstackPP9_hierhead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hdhat", hdLodNode_hdhat__FP8_hierlodPP9_hierhead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hdhat", hdColNode_hdhat__FP20_hiercollisionvolume);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hdhat", hdAnimTransNode_hdhat__FP14_animtransformPP9_hierhead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hdhat", hdBspNode_hdhat__FP12_hierbspnode);

extern u8 hdDefaultHeight_8_28[4] __asm__("hdDefaultHeight");

void hdSetDefaultHeight__Ff(f32 fparg0) {
    (*(f32*)hdDefaultHeight_8_28) = fparg0;
}
