#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/plight", plightFindLight__FP11_pointlight);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/plight", plightInit__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/plight", plightCreate__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/plight", plightDestroy__FP11_pointlight);

extern u8 doParaLights_C_20[4] __asm__("doParaLights");

void plightParaActivate__Fv(void) {
    (*(s32*)doParaLights_C_20) = 1;
}

extern u8 doParaLights_8_22[4] __asm__("doParaLights");

s32 plightParaActive__Fv(void) {
    return (*(s32*)doParaLights_8_22);
}

extern u8 doParaLights_8_25[4] __asm__("doParaLights");

void plightParaDeactivate__Fv(void) {
    (*(s32*)doParaLights_8_25) = 0;
}

extern u8 ptLightsActive_C_29[4] __asm__("ptLightsActive");

void plightActivate__Fv(void) {
    (*(s32*)ptLightsActive_C_29) = 1;
}

extern u8 ptLightsActive_8_31[4] __asm__("ptLightsActive");

s32 plightIsActive__Fv(void) {
    return (*(s32*)ptLightsActive_8_31);
}

extern u8 ptLightsActive_8_34[4] __asm__("ptLightsActive");

void plightDeActivate__Fv(void) {
    (*(s32*)ptLightsActive_8_34) = 0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/plight", plightSetPosition__FP11_pointlightfff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/plight", plightSetDirection__FP11_pointlightfff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/plight", plightSetBeamAngle__FP11_pointlightf);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/plight", plightSetIntensity__FP11_pointlightf);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/plight", plightSetRange__FP11_pointlightf);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/plight", plightSetColor__FP11_pointlightfff);

extern u8 paraL_C_48[] __asm__("paraL");

s32 plightGetParaLight__Fv(void) {
    return (s32) ((u8*)paraL_C_48);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/plight", plightInObject__FPA3_fP9_fvector4T1fT1P3_cs);

void plightSetRange__FP11_pointlightf_38_57(void*, float) __asm__("plightSetRange__FP11_pointlightf");
int plightCreate__Fv_38_57(void) __asm__("plightCreate__Fv");
extern u8 ptLightRange_38_57[4] __asm__("ptLightRange");

s32 plightTest__Fv(void) {
    void* temp_v0;

    temp_v0 = plightCreate__Fv_38_57();
    plightSetRange__FP11_pointlightf_38_57(temp_v0, (*(f32*)ptLightRange_38_57));
    return (s32) temp_v0;
}

void plightSetRange__FP11_pointlightf_84_60(void*, float) __asm__("plightSetRange__FP11_pointlightf");
void plightSetColor__FP11_pointlightfff_84_60(void*, float, float, float) __asm__("plightSetColor__FP11_pointlightfff");
void plightSetBeamAngle__FP11_pointlightf_84_60(void*, float) __asm__("plightSetBeamAngle__FP11_pointlightf");
int plightCreate__Fv_84_60(void) __asm__("plightCreate__Fv");
s32 plightCreatePlayerLight__FP3_cs(void* arg0) {
    s32 temp_v0;

    temp_v0 = plightCreate__Fv_84_60();
    if (temp_v0 != 0) {
        plightSetRange__FP11_pointlightf_84_60((void* ) temp_v0, 800.0f);
        plightSetColor__FP11_pointlightfff_84_60((void* ) temp_v0, 255.0f, 255.0f, 230.0f);
        M2C_FIELD(temp_v0, s32* , 0x38) = 0;
        plightSetBeamAngle__FP11_pointlightf_84_60((void* ) temp_v0, 96.0f);
        M2C_FIELD(temp_v0, void** , 0x3C) = arg0;
        M2C_FIELD(temp_v0, s32* , 0x34) = 0;
    }
    return temp_v0;
}

void plightSetRange__FP11_pointlightf_84_63(void*, float) __asm__("plightSetRange__FP11_pointlightf");
void plightSetColor__FP11_pointlightfff_84_63(void*, float, float, float) __asm__("plightSetColor__FP11_pointlightfff");
void plightSetBeamAngle__FP11_pointlightf_84_63(void*, float) __asm__("plightSetBeamAngle__FP11_pointlightf");
int plightCreate__Fv_84_63(void) __asm__("plightCreate__Fv");
s32 plightCreateCarLight__FP3_cs(void* arg0) {
    s32 temp_v0;

    temp_v0 = plightCreate__Fv_84_63();
    if (temp_v0 != 0) {
        plightSetRange__FP11_pointlightf_84_63((void* ) temp_v0, 800.0f);
        plightSetColor__FP11_pointlightfff_84_63((void* ) temp_v0, 255.0f, 255.0f, 230.0f);
        M2C_FIELD(temp_v0, s32* , 0x38) = 0;
        plightSetBeamAngle__FP11_pointlightf_84_63((void* ) temp_v0, 96.0f);
        M2C_FIELD(temp_v0, void** , 0x3C) = arg0;
        M2C_FIELD(temp_v0, s32* , 0x34) = 0;
    }
    return temp_v0;
}

void plightSetRange__FP11_pointlightf_8C_66(void*, float) __asm__("plightSetRange__FP11_pointlightf");
void plightSetColor__FP11_pointlightfff_8C_66(void*, float, float, float) __asm__("plightSetColor__FP11_pointlightfff");
void plightSetBeamAngle__FP11_pointlightf_8C_66(void*, float) __asm__("plightSetBeamAngle__FP11_pointlightf");
int plightCreate__Fv_8C_66(void) __asm__("plightCreate__Fv");
s32 plightCreateBossLight__FP3_cs(void* arg0) {
    s32 temp_v0;

    temp_v0 = plightCreate__Fv_8C_66();
    if (temp_v0 != 0) {
        plightSetRange__FP11_pointlightf_8C_66((void* ) temp_v0, 1000.0f);
        plightSetColor__FP11_pointlightfff_8C_66((void* ) temp_v0, 188.0f, 141.0f, 255.0f);
        M2C_FIELD(temp_v0, s32* , 0x38) = 1;
        plightSetBeamAngle__FP11_pointlightf_8C_66((void* ) temp_v0, 126.0f);
        M2C_FIELD(temp_v0, void** , 0x3C) = arg0;
        M2C_FIELD(temp_v0, s32* , 0x34) = 0;
    }
    return temp_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/plight", plightCreateWeapLight__FfffP3_cs);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/plight", plightCreateExplodeLight__FfffP3_cs);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/plight", plightUpdateParaLights__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/plight", plightGetParaLight__FiPfT1T1T1T1);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/plight", plightSetParaLight__Fifffff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/plight", plightSetTODParaLight__Fifffff);

void plightUpdateLights__Fv(void) {
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/plight", plightClosestPts__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/plight", plightRenderObj__Fv);

extern u8 plightOut_C_100[] __asm__("plightOut");

s32 plightGetPktPtr__Fv(void) {
    return (s32) ((u8*)plightOut_C_100);
}
