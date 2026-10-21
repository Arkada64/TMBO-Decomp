#include "common.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewCreate__F10_viewportsi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewUpdate__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetTOD__FPiPfP10_todInfo14);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewSetTOD__FifPvf);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetRot__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetMat__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetTrans__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewSetRot__FP8_fvectori);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewSetTrans__FP8_fvectori);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetCurView__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetViewCs__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetWorldCtx__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewSetWorldEpNode__FP9_hierhead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewSetAmbientVol__Fiffff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetWeTrans__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetWeMat__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewSetSkyEntry__FP9_hierheadi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetSky__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewSetSkyTrans__FP8_fvectori);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewSetSkyNode__FP9_hierheadi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewSetVUPacketMat__FPA3_fT0T0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewApplySwap__FPA3_fT0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewSetBgColor__FUlUlUlUl);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewSetTODBgColor__FUlUlUlUl);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetBgColor__FRiT0T0T0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetDb__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetNumViews__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewSetNumViews__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewIsRearView__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGameIsInRearViewMode__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewIsRearViewSmall__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewIsRearViewLarge__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewIsRearLargeActive__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewIsRearSmallActive__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetRearViewConfig__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewToggleRearViewConfig__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewSetRearViewPos__FP3_csif);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetCenter__FiPiT1);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetWH__FiPiT1);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetZBuffParams__FiPfT1);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetWorldToScreenMat__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewInit__Fv);

void viewTweakInit__Fv(void) {
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewTweakSetFov__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewSetAmbient__Ffff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetAmbient__FPfT0T0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewSetAmbientFactor__Ff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetFov__FiPfT1);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewSetFov__Fiff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewComputeNormal__FP8_fvectorT0T0T0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewToggleSplitScreen__Fbb);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetScreenDisplay__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetDef__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/view", viewGetDefByName__F10_viewports);
