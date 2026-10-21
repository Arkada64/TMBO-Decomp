#include "common.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", todBoundAngle__FPf);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", todCalculateValue__Fiff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", todInit__Fv);

void todInitStats__Fv(void) {
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", todUpdate__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", todActive__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", todSetTimeActive__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", todGetTOD__FPiPfP10_todInfo14);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", todSetTOD__FifPvf);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", todGetCurrentTOD__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", todSetCurrentTOD__Ff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", todDisable__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", todGetAmbient__FPfT0T0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", todSetSkyEntry__FP9_hierhead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", todSetSkyObjects__Fiffffff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", todSetPlightsActive__Fii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", __12CTODLinkList);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", _$_12CTODLinkList);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", AddEntry__12CTODLinkList);

void DeleteEntry__12CTODLinkListi(void) {
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", GetNumEntries__12CTODLinkList);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", FindNodeByTime__12CTODLinkListf);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", FindFreeNode__12CTODLinkList);

void SortList__12CTODLinkList(void) {
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", ClearNode__12CTODLinkListP9_LinkNode);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", _GLOBAL_$D$todLink);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tod", _GLOBAL_$I$todLink);
