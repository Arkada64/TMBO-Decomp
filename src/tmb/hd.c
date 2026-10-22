#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hd", hdInit__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hd", hdCsTest__FP12_hdCsTestPtsP8_fvectorPA3_A3_fP9_hdResult);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hd", hdCsSphereTest__FP12_hdCsTestPtsP9_hdResult);

void hdHier_hd__Fv_4C_16(void) __asm__("hdHier_hd__Fv");
void mathfSubVector__FP8_fvectorT0T0_4C_16(void*, void*, void*) __asm__("mathfSubVector__FP8_fvectorT0T0");
extern u8 csSphereTest_4C_16[4] __asm__("csSphereTest");
extern u8 csTest_4C_16[4] __asm__("csTest");
extern u8 hdIgnoreInteractive_hd_4C_16[4] __asm__("hdIgnoreInteractive_hd");
extern u8 hdPrevPt_hd_4C_16[4] __asm__("hdPrevPt_hd");
extern u8 hdRayDir_hd_4C_16[] __asm__("hdRayDir_hd");
extern u8 hdResult_hd_4C_16[4] __asm__("hdResult_hd");
extern u8 hdTestPt_hd_4C_16[4] __asm__("hdTestPt_hd");
extern u8 sphereOnlyTest_4C_16[4] __asm__("sphereOnlyTest");

void hdPntTest__FP8_fvectorT0P9_hdResultUi(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    (*(s32*)hdResult_hd_4C_16) = arg2;
    (*(s32*)hdIgnoreInteractive_hd_4C_16) = arg3;
    (*(s32*)sphereOnlyTest_4C_16) = 0;
    (*(s32*)csSphereTest_4C_16) = 0;
    (*(s32*)csTest_4C_16) = 0;
    (*(s32*)hdTestPt_hd_4C_16) = arg0;
    (*(s32*)hdPrevPt_hd_4C_16) = arg1;
    mathfSubVector__FP8_fvectorT0T0_4C_16(((u8*)hdRayDir_hd_4C_16), arg0, arg1);
    hdHier_hd__Fv_4C_16();
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hd", hdPntSphereTest__FP8_fvectorT0P9_hdResultUi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hd", hdCsToCsTest__FP12_hdCsTestPtsP3_csP8_fvectorPA3_A3_fP9_hdResult);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hd", hdHier_hd__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hd", hdColGrid_hd__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hd", hdTraverse_hd__FPP9_hierhead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hd", hdSphereTest_hd__FP8_fvectorffT0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hd", hdPush_hd__FPP9_hierheadiP8_fvectorUiP17_animCharInstance);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hd", hdPop_hd__FP8_hdstackPP9_hierhead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hd", hdLodNode_hd__FP8_hierlodPP9_hierhead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hd", hdColNode_hd__FP20_hiercollisionvolume);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hd", hdTerrain_hd__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hd", hdAnimTransNode_hd__FP14_animtransformPP9_hierhead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hd", hdBspNode_hd__FP12_hierbspnode);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hd", hdPunt__FP8_fvectorT0PA3_A3_fP20_hiercollisionvolumei);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hd", hdRayTest__FP8_fvectorT0PA3_A3_fP20_hiercollisionvolumei);

extern u8 colGrid_20_65[4] __asm__("colGrid");

s32 hdSaveColGrid__FP18_HierCollisionGrid(void* arg0) {
    void* temp_v0;

    temp_v0 = (*(void**)colGrid_20_65);
    if (arg0 == NULL) {
        (*(void**)colGrid_20_65) = NULL;
        return (s32) temp_v0;
    }
    if (temp_v0 == NULL) {
        (*(void**)colGrid_20_65) = arg0;
    }
    return (s32) temp_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hd", hdGetSphereGridCells__FR8_fvectorfPiRi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hd", hdReparentCsGrid__FP3_cs);

extern u8 g_largeCsList_8_73[4] __asm__("g_largeCsList");

void _GLOBAL_$I$colGrid(void) {
    (*(s32*)g_largeCsList_8_73) = 0;
}
