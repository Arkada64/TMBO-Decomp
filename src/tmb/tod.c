#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", todBoundAngle__FPf);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", todCalculateValue__Fiff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", todInit__Fv);

void todInitStats__Fv(void) {
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", todUpdate__Fi);

extern u8 todTimeOfDayOn_8_17[4] __asm__("todTimeOfDayOn");

s32 todActive__Fv(void) {
    return (*(s32*)todTimeOfDayOn_8_17);
}

extern u8 todSetTimeOfDay_8_20[4] __asm__("todSetTimeOfDay");

s32 todSetTimeActive__Fv(void) {
    return (*(s32*)todSetTimeOfDay_8_20);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", todGetTOD__FPiPfP10_todInfo14);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", todSetTOD__FifPvf);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", todGetCurrentTOD__Fv);

extern u8 hour_C_38[4] __asm__("hour");

s32 todSetCurrentTOD__Ff(f32 fparg0) {
    (*(f32*)hour_C_38) = fparg0;
    return 1;
}

extern u8 todSetTimeOfDay_C_41[4] __asm__("todSetTimeOfDay");
extern u8 todTimeOfDayOn_C_41[4] __asm__("todTimeOfDayOn");

void todDisable__Fv(void) {
    (*(s32*)todTimeOfDayOn_C_41) = 0;
    (*(s32*)todSetTimeOfDay_C_41) = 0;
}

extern u8 todAmbientBlue_1C_45[4] __asm__("todAmbientBlue");
extern u8 todAmbientGreen_1C_45[4] __asm__("todAmbientGreen");
extern u8 todAmbientRed_1C_45[4] __asm__("todAmbientRed");

void todGetAmbient__FPfT0T0(f32* arg0, f32* arg1, f32* arg2) {
    *arg0 = (*(f32*)todAmbientRed_1C_45);
    *arg1 = (*(f32*)todAmbientGreen_1C_45);
    *arg2 = (*(f32*)todAmbientBlue_1C_45);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", todSetSkyEntry__FP9_hierhead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", todSetSkyObjects__Fiffffff);

extern u8 s_todPlightsEnabled_18_53[] __asm__("s_todPlightsEnabled");

s32 todSetPlightsActive__Fii(s32 arg0, s32 arg1)
{
  s32 *new_var;
  ;
  new_var = ((*(&arg0)) * 4) + ((u8 *) s_todPlightsEnabled_18_53);
  *new_var = arg1;
  return (s32) ((u8 *) s_todPlightsEnabled_18_53);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", __12CTODLinkList);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", _$_12CTODLinkList);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", AddEntry__12CTODLinkList);

void DeleteEntry__12CTODLinkListi(void) {
}

s32 GetNumEntries__12CTODLinkList(s32* arg0) {
    return *arg0;
}

s32 FindNodeByTime__12CTODLinkListf(void* arg0, f32 fparg0) {
    return 0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", FindFreeNode__12CTODLinkList);

void SortList__12CTODLinkList(void) {
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", ClearNode__12CTODLinkListP9_LinkNode);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", _GLOBAL_$D$todLink);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", _GLOBAL_$I$todLink);
