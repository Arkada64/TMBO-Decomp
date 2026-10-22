#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fog", fogInit__Fv);

void fogInitStats__Fv(void) {
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fog", fogSetChanged__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fog", fogUpdate__Fi);

void fogCalcFogValues__FfffPfT3(f32* arg0, f32* arg1, f32 fparg0, f32 fparg1, f32 fparg2) {
    f32 temp_f14;

    temp_f14 = ((fparg2 - 1.0f) * (fparg1 * fparg0)) / (fparg0 - fparg1);
    *arg1 = temp_f14;
    *arg0 = 1.0f - (temp_f14 / fparg0);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fog", fogGetFogValues__FP6QwData);

extern u8 fogColorBlue_3C_13[4] __asm__("fogColorBlue");
extern u8 fogColorGreen_3C_13[4] __asm__("fogColorGreen");
extern u8 fogColorRed_3C_13[4] __asm__("fogColorRed");
extern u8 fogFarClip_3C_13[4] __asm__("fogFarClip");
extern u8 fogMaxRange_3C_13[4] __asm__("fogMaxRange");
extern u8 fogMaxVal_3C_13[4] __asm__("fogMaxVal");
extern u8 fogMinRange_3C_13[4] __asm__("fogMinRange");

void fogGetFogParms__FPfT0T0T0PiT4T4(f32* arg0, f32* arg1, f32* arg2, f32* arg3, s32* arg4, s32* arg5, s32* arg6) {
    *arg0 = (*(f32*)fogMinRange_3C_13);
    *arg4 = (*(s32*)fogColorRed_3C_13);
    *arg1 = (*(f32*)fogMaxRange_3C_13);
    *arg5 = (*(s32*)fogColorGreen_3C_13);
    *arg2 = (*(f32*)fogMaxVal_3C_13);
    *arg6 = (*(s32*)fogColorBlue_3C_13);
    *arg3 = (*(f32*)fogFarClip_3C_13);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fog", fogSetFogParms__Fffffiii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fog", fogSetVolumeParms__Fiffffiii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fog", fogGetFarClipRange__Fv);

extern u8 fogBackgroundColorIsSlaved_8_24[4] __asm__("fogBackgroundColorIsSlaved");

s32 fogGetIsSlavedToBg__Fv(void) {
    return (*(s32*)fogBackgroundColorIsSlaved_8_24);
}

extern u8 fogBackgroundColorIsSlaved_8_27[4] __asm__("fogBackgroundColorIsSlaved");

void fogClearSlavedToBg__Fv(void) {
    (*(s32*)fogBackgroundColorIsSlaved_8_27) = 0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fog", fogGetTODFogValues__FP6QwData);

extern u8 fogTODColorBlue_3C_34[4] __asm__("fogTODColorBlue");
extern u8 fogTODColorGreen_3C_34[4] __asm__("fogTODColorGreen");
extern u8 fogTODColorRed_3C_34[4] __asm__("fogTODColorRed");
extern u8 fogTODFarClip_3C_34[4] __asm__("fogTODFarClip");
extern u8 fogTODMaxRange_3C_34[4] __asm__("fogTODMaxRange");
extern u8 fogTODMaxVal_3C_34[4] __asm__("fogTODMaxVal");
extern u8 fogTODMinRange_3C_34[4] __asm__("fogTODMinRange");

void fogGetTODFogParms__FPfT0T0T0PiT4T4(f32* arg0, f32* arg1, f32* arg2, f32* arg3, s32* arg4, s32* arg5, s32* arg6) {
    *arg0 = (*(f32*)fogTODMinRange_3C_34);
    *arg4 = (*(s32*)fogTODColorRed_3C_34);
    *arg1 = (*(f32*)fogTODMaxRange_3C_34);
    *arg5 = (*(s32*)fogTODColorGreen_3C_34);
    *arg2 = (*(f32*)fogTODMaxVal_3C_34);
    *arg6 = (*(s32*)fogTODColorBlue_3C_34);
    *arg3 = (*(f32*)fogTODFarClip_3C_34);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fog", fogSetTODFogParms__Fffffiii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fog", fogAdjust__Ff);
