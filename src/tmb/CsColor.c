#include "common.h"
#include "m2c_macros.h"

s32 __Q27CsColor4Data(void* arg0) {
    M2C_FIELD(arg0, s32* , 0) = 0;
    M2C_FIELD(arg0, f32* , 4) = 1.0f;
    M2C_FIELD(arg0, s32* , 8) = 0;
    return (s32) arg0;
}

extern u8 g_data_C_2[] __asm__("g_data");

s32 isEnabled__7CsColorv(void* arg0) {
    return (*(s32*)g_data_C_2);
}

extern u8 D_005043DC_C_6[] __asm__("D_005043DC");

f32 contrast__7CsColorv(void) {
    return (*(f32*)D_005043DC_C_6);
}

extern u8 D_005043E0_C_9[] __asm__("D_005043E0");

f32 brightness__7CsColorv(void) {
    return (*(f32*)D_005043E0_C_9);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/CsColor", load__7CsColorPCQ27CsColor4Data);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/CsColor", save__7CsColorPQ27CsColor4Data);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/CsColor", _GLOBAL_$I$__Q27CsColor4Data);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/CsColor", dbsPush__FPP9_hierheadP8_fvectorUiPA3_fP17_animCharInstance);
