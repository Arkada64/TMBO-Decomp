#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/CsColor", __Q27CsColor4Data);

#include "m2c_macros.h"
extern s32 D_00505D80_Colorv __asm__("D_00505D80");

s32 isEnabled__7CsColorv(void) {
    return D_00505D80_Colorv;
}

#include "m2c_macros.h"
extern f32 D_00505D84_Colorv __asm__("D_00505D84");

f32 contrast__7CsColorv(void) {
    return D_00505D84_Colorv;
}

#include "m2c_macros.h"
extern f32 D_00505D88_Colorv __asm__("D_00505D88");

f32 brightness__7CsColorv(void) {
    return D_00505D88_Colorv;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/CsColor", func_001FE2F8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/CsColor", func_001FE320);

#include "m2c_macros.h"
M2C_UNK __Q27CsColor4Data_1FE348() __asm__("__Q27CsColor4Data");
extern M2C_UNK D_00505D80_1FE348 __asm__("D_00505D80");

void func_001FE348(s32 arg0, s32 arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 != 0) {
            __Q27CsColor4Data_1FE348(&D_00505D80_1FE348);
        }
    }
}

#include "m2c_macros.h"
M2C_UNK func_001FE348_1FE378() __asm__("func_001FE348");

void func_001FE378(void) {
    func_001FE348_1FE378(1, 0xFFFF);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/CsColor", dbsPush__FPP9_hierheadP8_fvectorUiPA3_fP17_animCharInstance);
