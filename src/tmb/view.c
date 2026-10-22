#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewCreate__F10_viewportsi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewUpdate__Fi);

M2C_UNK todGetTOD__FPiPfP10_todInfo14_8_7() __asm__("todGetTOD__FPiPfP10_todInfo14");

void viewGetTOD__FPiPfP10_todInfo14(void) {
    todGetTOD__FPiPfP10_todInfo14_8_7();
}

M2C_UNK todSetTOD__FifPvf_8_10() __asm__("todSetTOD__FifPvf");

void viewSetTOD__FifPvf(void) {
    todSetTOD__FifPvf_8_10();
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetRot__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetMat__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetTrans__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewSetRot__FP8_fvectori);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewSetTrans__FP8_fvectori);

extern u8 viewCurView_8_26[4] __asm__("viewCurView");

s32 viewGetCurView__Fv(void) {
    return (*(s32*)viewCurView_8_26);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetViewCs__Fi);

extern u8 worldCtx_18_32[] __asm__("worldCtx");

s32 viewGetWorldCtx__Fi(s32 arg0) {
    return (s32) ((arg0 * 0xF0) + ((u8*)worldCtx_18_32));
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewSetWorldEpNode__FP9_hierhead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewSetAmbientVol__Fiffff);

extern u8 worldCtx_18_44[] __asm__("worldCtx");

s32 viewGetWeTrans__Fi(s32 arg0) {
    return (s32) ((arg0 * 0xF0) + (((u8*)worldCtx_18_44) + 0x20));
}

extern u8 worldCtx_18_47[] __asm__("worldCtx");

s32 viewGetWeMat__Fi(s32 arg0) {
    return (s32) ((arg0 * 0xF0) + (((u8*)worldCtx_18_47) + 0x30));
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewSetSkyEntry__FP9_hierheadi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetSky__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewSetSkyTrans__FP8_fvectori);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewSetSkyNode__FP9_hierheadi);

extern u8 dmaClipMat_2AC_65[] __asm__("dmaClipMat");
extern u8 dmaInnerClipMat_2AC_65[] __asm__("dmaInnerClipMat");
extern u8 dmaScreenMat_2AC_65[] __asm__("dmaScreenMat");
extern u8 dmaVu0ClipMat_2AC_65[] __asm__("dmaVu0ClipMat");
extern u8 dmaVu0ScreenMat_2AC_65[] __asm__("dmaVu0ScreenMat");

s32 viewSetVUPacketMat__FPA3_fT0T0(void* arg0, void* arg1, void* arg2) {
    s32 temp_v0;

    M2C_FIELD(((u8*)dmaScreenMat_2AC_65), s32* , 0) = (s32) M2C_FIELD(arg0, s32* , 0);
    M2C_FIELD(((u8*)dmaScreenMat_2AC_65), s32* , 4) = (s32) M2C_FIELD(arg0, s32* , 0x10);
    M2C_FIELD(((u8*)dmaScreenMat_2AC_65), s32* , 8) = (s32) M2C_FIELD(arg0, s32* , 0x20);
    M2C_FIELD(((u8*)dmaScreenMat_2AC_65), s32* , 0xC) = (s32) M2C_FIELD(arg0, s32* , 0x30);
    M2C_FIELD(((u8*)dmaScreenMat_2AC_65), s32* , 0x10) = (s32) M2C_FIELD(arg0, s32* , 4);
    M2C_FIELD(((u8*)dmaScreenMat_2AC_65), s32* , 0x14) = (s32) M2C_FIELD(arg0, s32* , 0x14);
    M2C_FIELD(((u8*)dmaScreenMat_2AC_65), s32* , 0x18) = (s32) M2C_FIELD(arg0, s32* , 0x24);
    M2C_FIELD(((u8*)dmaScreenMat_2AC_65), s32* , 0x1C) = (s32) M2C_FIELD(arg0, s32* , 0x34);
    M2C_FIELD(((u8*)dmaScreenMat_2AC_65), s32* , 0x20) = (s32) M2C_FIELD(arg0, s32* , 8);
    M2C_FIELD(((u8*)dmaScreenMat_2AC_65), s32* , 0x24) = (s32) M2C_FIELD(arg0, s32* , 0x18);
    M2C_FIELD(((u8*)dmaScreenMat_2AC_65), s32* , 0x28) = (s32) M2C_FIELD(arg0, s32* , 0x28);
    M2C_FIELD(((u8*)dmaScreenMat_2AC_65), s32* , 0x2C) = (s32) M2C_FIELD(arg0, s32* , 0x38);
    M2C_FIELD(((u8*)dmaScreenMat_2AC_65), s32* , 0x30) = (s32) M2C_FIELD(arg0, s32* , 0xC);
    M2C_FIELD(((u8*)dmaScreenMat_2AC_65), s32* , 0x34) = (s32) M2C_FIELD(arg0, s32* , 0x1C);
    M2C_FIELD(((u8*)dmaScreenMat_2AC_65), s32* , 0x38) = (s32) M2C_FIELD(arg0, s32* , 0x2C);
    M2C_FIELD(((u8*)dmaScreenMat_2AC_65), s32* , 0x3C) = (s32) M2C_FIELD(arg0, s32* , 0x3C);
    M2C_FIELD(((u8*)dmaClipMat_2AC_65), s32* , 0) = (s32) M2C_FIELD(arg1, s32* , 0);
    M2C_FIELD(((u8*)dmaClipMat_2AC_65), s32* , 4) = (s32) M2C_FIELD(arg1, s32* , 0x10);
    M2C_FIELD(((u8*)dmaClipMat_2AC_65), s32* , 8) = (s32) M2C_FIELD(arg1, s32* , 0x20);
    M2C_FIELD(((u8*)dmaClipMat_2AC_65), s32* , 0xC) = (s32) M2C_FIELD(arg1, s32* , 0x30);
    M2C_FIELD(((u8*)dmaClipMat_2AC_65), s32* , 0x10) = (s32) M2C_FIELD(arg1, s32* , 4);
    M2C_FIELD(((u8*)dmaClipMat_2AC_65), s32* , 0x14) = (s32) M2C_FIELD(arg1, s32* , 0x14);
    M2C_FIELD(((u8*)dmaClipMat_2AC_65), s32* , 0x18) = (s32) M2C_FIELD(arg1, s32* , 0x24);
    M2C_FIELD(((u8*)dmaClipMat_2AC_65), s32* , 0x1C) = (s32) M2C_FIELD(arg1, s32* , 0x34);
    M2C_FIELD(((u8*)dmaClipMat_2AC_65), s32* , 0x20) = (s32) M2C_FIELD(arg1, s32* , 8);
    M2C_FIELD(((u8*)dmaClipMat_2AC_65), s32* , 0x24) = (s32) M2C_FIELD(arg1, s32* , 0x18);
    M2C_FIELD(((u8*)dmaClipMat_2AC_65), s32* , 0x28) = (s32) M2C_FIELD(arg1, s32* , 0x28);
    M2C_FIELD(((u8*)dmaClipMat_2AC_65), s32* , 0x2C) = (s32) M2C_FIELD(arg1, s32* , 0x38);
    M2C_FIELD(((u8*)dmaClipMat_2AC_65), s32* , 0x30) = (s32) M2C_FIELD(arg1, s32* , 0xC);
    M2C_FIELD(((u8*)dmaClipMat_2AC_65), s32* , 0x34) = (s32) M2C_FIELD(arg1, s32* , 0x1C);
    M2C_FIELD(((u8*)dmaClipMat_2AC_65), s32* , 0x38) = (s32) M2C_FIELD(arg1, s32* , 0x2C);
    M2C_FIELD(((u8*)dmaClipMat_2AC_65), s32* , 0x3C) = (s32) M2C_FIELD(arg1, s32* , 0x3C);
    M2C_FIELD(((u8*)dmaInnerClipMat_2AC_65), s32* , 0) = (s32) M2C_FIELD(arg2, s32* , 0);
    M2C_FIELD(((u8*)dmaInnerClipMat_2AC_65), s32* , 4) = (s32) M2C_FIELD(arg2, s32* , 0x10);
    M2C_FIELD(((u8*)dmaInnerClipMat_2AC_65), s32* , 8) = (s32) M2C_FIELD(arg2, s32* , 0x20);
    M2C_FIELD(((u8*)dmaInnerClipMat_2AC_65), s32* , 0xC) = (s32) M2C_FIELD(arg2, s32* , 0x30);
    M2C_FIELD(((u8*)dmaInnerClipMat_2AC_65), s32* , 0x10) = (s32) M2C_FIELD(arg2, s32* , 4);
    M2C_FIELD(((u8*)dmaInnerClipMat_2AC_65), s32* , 0x14) = (s32) M2C_FIELD(arg2, s32* , 0x14);
    M2C_FIELD(((u8*)dmaInnerClipMat_2AC_65), s32* , 0x18) = (s32) M2C_FIELD(arg2, s32* , 0x24);
    M2C_FIELD(((u8*)dmaInnerClipMat_2AC_65), s32* , 0x1C) = (s32) M2C_FIELD(arg2, s32* , 0x34);
    M2C_FIELD(((u8*)dmaInnerClipMat_2AC_65), s32* , 0x20) = (s32) M2C_FIELD(arg2, s32* , 8);
    M2C_FIELD(((u8*)dmaInnerClipMat_2AC_65), s32* , 0x24) = (s32) M2C_FIELD(arg2, s32* , 0x18);
    M2C_FIELD(((u8*)dmaInnerClipMat_2AC_65), s32* , 0x28) = (s32) M2C_FIELD(arg2, s32* , 0x28);
    M2C_FIELD(((u8*)dmaInnerClipMat_2AC_65), s32* , 0x2C) = (s32) M2C_FIELD(arg2, s32* , 0x38);
    M2C_FIELD(((u8*)dmaInnerClipMat_2AC_65), s32* , 0x30) = (s32) M2C_FIELD(arg2, s32* , 0xC);
    M2C_FIELD(((u8*)dmaInnerClipMat_2AC_65), s32* , 0x34) = (s32) M2C_FIELD(arg2, s32* , 0x1C);
    M2C_FIELD(((u8*)dmaInnerClipMat_2AC_65), s32* , 0x38) = (s32) M2C_FIELD(arg2, s32* , 0x2C);
    M2C_FIELD(((u8*)dmaInnerClipMat_2AC_65), s32* , 0x3C) = (s32) M2C_FIELD(arg2, s32* , 0x3C);
    M2C_FIELD(((u8*)dmaVu0ScreenMat_2AC_65), s32* , 0) = (s32) M2C_FIELD(arg0, s32* , 0);
    M2C_FIELD(((u8*)dmaVu0ScreenMat_2AC_65), s32* , 4) = (s32) M2C_FIELD(arg0, s32* , 0x10);
    M2C_FIELD(((u8*)dmaVu0ScreenMat_2AC_65), s32* , 8) = (s32) M2C_FIELD(arg0, s32* , 0x20);
    M2C_FIELD(((u8*)dmaVu0ScreenMat_2AC_65), s32* , 0xC) = (s32) M2C_FIELD(arg0, s32* , 0x30);
    M2C_FIELD(((u8*)dmaVu0ScreenMat_2AC_65), s32* , 0x10) = (s32) M2C_FIELD(arg0, s32* , 4);
    M2C_FIELD(((u8*)dmaVu0ScreenMat_2AC_65), s32* , 0x14) = (s32) M2C_FIELD(arg0, s32* , 0x14);
    M2C_FIELD(((u8*)dmaVu0ScreenMat_2AC_65), s32* , 0x18) = (s32) M2C_FIELD(arg0, s32* , 0x24);
    M2C_FIELD(((u8*)dmaVu0ScreenMat_2AC_65), s32* , 0x1C) = (s32) M2C_FIELD(arg0, s32* , 0x34);
    M2C_FIELD(((u8*)dmaVu0ScreenMat_2AC_65), s32* , 0x20) = (s32) M2C_FIELD(arg0, s32* , 8);
    M2C_FIELD(((u8*)dmaVu0ScreenMat_2AC_65), s32* , 0x24) = (s32) M2C_FIELD(arg0, s32* , 0x18);
    M2C_FIELD(((u8*)dmaVu0ScreenMat_2AC_65), s32* , 0x28) = (s32) M2C_FIELD(arg0, s32* , 0x28);
    M2C_FIELD(((u8*)dmaVu0ScreenMat_2AC_65), s32* , 0x2C) = (s32) M2C_FIELD(arg0, s32* , 0x38);
    M2C_FIELD(((u8*)dmaVu0ScreenMat_2AC_65), s32* , 0x30) = (s32) M2C_FIELD(arg0, s32* , 0xC);
    M2C_FIELD(((u8*)dmaVu0ScreenMat_2AC_65), s32* , 0x34) = (s32) M2C_FIELD(arg0, s32* , 0x1C);
    M2C_FIELD(((u8*)dmaVu0ScreenMat_2AC_65), s32* , 0x38) = (s32) M2C_FIELD(arg0, s32* , 0x2C);
    M2C_FIELD(((u8*)dmaVu0ScreenMat_2AC_65), s32* , 0x3C) = (s32) M2C_FIELD(arg0, s32* , 0x3C);
    M2C_FIELD(((u8*)dmaVu0ClipMat_2AC_65), s32* , 0) = (s32) M2C_FIELD(arg1, s32* , 0);
    M2C_FIELD(((u8*)dmaVu0ClipMat_2AC_65), s32* , 4) = (s32) M2C_FIELD(arg1, s32* , 0x10);
    M2C_FIELD(((u8*)dmaVu0ClipMat_2AC_65), s32* , 8) = (s32) M2C_FIELD(arg1, s32* , 0x20);
    M2C_FIELD(((u8*)dmaVu0ClipMat_2AC_65), s32* , 0xC) = (s32) M2C_FIELD(arg1, s32* , 0x30);
    M2C_FIELD(((u8*)dmaVu0ClipMat_2AC_65), s32* , 0x10) = (s32) M2C_FIELD(arg1, s32* , 4);
    M2C_FIELD(((u8*)dmaVu0ClipMat_2AC_65), s32* , 0x14) = (s32) M2C_FIELD(arg1, s32* , 0x14);
    M2C_FIELD(((u8*)dmaVu0ClipMat_2AC_65), s32* , 0x18) = (s32) M2C_FIELD(arg1, s32* , 0x24);
    M2C_FIELD(((u8*)dmaVu0ClipMat_2AC_65), s32* , 0x1C) = (s32) M2C_FIELD(arg1, s32* , 0x34);
    M2C_FIELD(((u8*)dmaVu0ClipMat_2AC_65), s32* , 0x20) = (s32) M2C_FIELD(arg1, s32* , 8);
    M2C_FIELD(((u8*)dmaVu0ClipMat_2AC_65), s32* , 0x24) = (s32) M2C_FIELD(arg1, s32* , 0x18);
    M2C_FIELD(((u8*)dmaVu0ClipMat_2AC_65), s32* , 0x28) = (s32) M2C_FIELD(arg1, s32* , 0x28);
    M2C_FIELD(((u8*)dmaVu0ClipMat_2AC_65), s32* , 0x2C) = (s32) M2C_FIELD(arg1, s32* , 0x38);
    M2C_FIELD(((u8*)dmaVu0ClipMat_2AC_65), s32* , 0x30) = (s32) M2C_FIELD(arg1, s32* , 0xC);
    M2C_FIELD(((u8*)dmaVu0ClipMat_2AC_65), s32* , 0x34) = (s32) M2C_FIELD(arg1, s32* , 0x1C);
    temp_v0 = M2C_FIELD(arg1, s32* , 0x2C);
    M2C_FIELD(((u8*)dmaVu0ClipMat_2AC_65), s32* , 0x38) = temp_v0;
    M2C_FIELD(((u8*)dmaVu0ClipMat_2AC_65), s32* , 0x3C) = (s32) M2C_FIELD(arg1, s32* , 0x3C);
    return temp_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewApplySwap__FPA3_fT0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewSetBgColor__FUlUlUlUl);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewSetTODBgColor__FUlUlUlUl);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetBgColor__FRiT0T0T0);

extern u8 viewDb_18_79[] __asm__("viewDb");

s32 viewGetDb__Fi(s32 arg0) {
    return (s32) ((arg0 * 0x360) + ((u8*)viewDb_18_79));
}

extern u8 viewNumViews_8_82[4] __asm__("viewNumViews");

s32 viewGetNumViews__Fv(void) {
    return (*(s32*)viewNumViews_8_82);
}

extern u8 viewNumViews_8_85[4] __asm__("viewNumViews");

void viewSetNumViews__Fi(s32 arg0) {
    (*(s32*)viewNumViews_8_85) = arg0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewIsRearView__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGameIsInRearViewMode__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewIsRearViewSmall__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewIsRearViewLarge__Fi);

extern u8 viewRearLargeActive_8_100[4] __asm__("viewRearLargeActive");

s32 viewIsRearLargeActive__Fv(void) {
    return (*(s32*)viewRearLargeActive_8_100);
}

extern u8 viewRearSmallActive_8_103[4] __asm__("viewRearSmallActive");

s32 viewIsRearSmallActive__Fv(void) {
    return (*(s32*)viewRearSmallActive_8_103);
}

extern u8 viewRearViewConfig_8_106[4] __asm__("viewRearViewConfig");

s32 viewGetRearViewConfig__Fv(void) {
    return (*(s32*)viewRearViewConfig_8_106);
}

void viewToggleSplitScreen__Fbb_34_110(unsigned char, unsigned char) __asm__("viewToggleSplitScreen__Fbb");
extern u8 viewRearViewConfig_34_110[4] __asm__("viewRearViewConfig");

void viewToggleRearViewConfig__Fv(void) {
    (*(s32*)viewRearViewConfig_34_110) = (*(s32*)viewRearViewConfig_34_110) == 0;
    viewToggleSplitScreen__Fbb_34_110(1, 0);
    viewToggleSplitScreen__Fbb_34_110(1, 0);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewSetRearViewPos__FP3_csif);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetCenter__FiPiT1);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetWH__FiPiT1);

extern u8 viewScreenMats_24_122[] __asm__("viewScreenMats");

void viewGetZBuffParams__FiPfT1(s32 arg0, f32* arg1, f32* arg2) {
    void* temp_a0;

    temp_a0 = (arg0 << 6) + ((u8*)viewScreenMats_24_122);
    *arg1 = M2C_FIELD(temp_a0, f32* , 0x28);
    *arg2 = M2C_FIELD(temp_a0, f32* , 0x2C);
}

extern u8 worldToScreenMat_14_124[] __asm__("worldToScreenMat");

s32 viewGetWorldToScreenMat__Fi(s32 arg0) {
    return (s32) ((arg0 << 6) + ((u8*)worldToScreenMat_14_124));
}

int todInit__Fv_54_127(void) __asm__("todInit__Fv");
extern u8 viewInfo_54_127[] __asm__("viewInfo");
extern u8 viewRearLargeActive_54_127[4] __asm__("viewRearLargeActive");
extern u8 viewRearSmallActive_54_127[4] __asm__("viewRearSmallActive");

s32 viewInit__Fv(void) {
    M2C_UNK* var_v0;
    s32 temp_v0;
    s32 var_v1;

    var_v1 = 3;
    var_v0 = ((u8*)viewInfo_54_127);
    do {
        M2C_FIELD(var_v0, s32* , 0) = 0;
        var_v1 -= 1;
        M2C_FIELD(var_v0, s32* , 4) = 0;
        M2C_FIELD(var_v0, s32* , 8) = 0;
        M2C_FIELD(var_v0, s32* , 0xC) = 0;
        var_v0 +=0x4;
    } while (var_v1 >= 0);
    temp_v0 = todInit__Fv_54_127();
    (*(s32*)viewRearLargeActive_54_127) = 0;
    (*(s32*)viewRearSmallActive_54_127) = 0;
    return temp_v0;
}

void viewTweakInit__Fv(void) {
}

void viewSetFov__Fiff_54_134(int, float, float) __asm__("viewSetFov__Fiff");
int viewGetDef__Fi_54_134(int) __asm__("viewGetDef__Fi");
extern u8 viewFovH_54_134[4] __asm__("viewFovH");
extern u8 viewNumViews_54_134[4] __asm__("viewNumViews");

s32 viewTweakSetFov__Fv(void) {
    f32 temp_f13;
    s32 temp_a0;
    s32 var_s0;
    s32 var_v0;

    var_v0 = (*(s32*)viewNumViews_54_134);
    var_s0 = 0;
    if (var_v0 > 0) {
        do {
            temp_f13 = M2C_FIELD(viewGetDef__Fi_54_134(var_s0), f32* , 0x20);
            temp_a0 = var_s0;
            var_s0 += 1;
            viewSetFov__Fiff_54_134(temp_a0, (*(f32*)viewFovH_54_134), temp_f13);
            var_v0 = var_s0 < (*(s32*)viewNumViews_54_134);
        } while (var_v0 != 0);
    }
    return var_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewSetAmbient__Ffff);

extern u8 viewAmbientBlue_1C_141[4] __asm__("viewAmbientBlue");
extern u8 viewAmbientGreen_1C_141[4] __asm__("viewAmbientGreen");
extern u8 viewAmbientRed_1C_141[4] __asm__("viewAmbientRed");

void viewGetAmbient__FPfT0T0(f32* arg0, f32* arg1, f32* arg2) {
    *arg0 = (*(f32*)viewAmbientRed_1C_141);
    *arg1 = (*(f32*)viewAmbientGreen_1C_141);
    *arg2 = (*(f32*)viewAmbientBlue_1C_141);
}

extern u8 viewAmbientFactor_8_143[4] __asm__("viewAmbientFactor");

void viewSetAmbientFactor__Ff(f32 fparg0) {
    (*(f32*)viewAmbientFactor_8_143) = fparg0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetFov__FiPfT1);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewSetFov__Fiff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewComputeNormal__FP8_fvectorT0T0T0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewToggleSplitScreen__Fbb);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetScreenDisplay__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetDef__Fi);

extern u8 viewDef_18_159[] __asm__("viewDef");

void* viewGetDefByName__F10_viewports(s32 arg0) {
    return (arg0 * 0xB0) + ((u8*)viewDef_18_159);
}
