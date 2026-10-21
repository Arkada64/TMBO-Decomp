#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tod", todBoundAngle__FPf);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tod", func_0023A758);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tod", todInit__Fv);

void todInitStats__Fv(void) {
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tod", todUpdate__Fi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tod", todActive__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tod", todSetTimeActive__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tod", func_0023B890);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tod", func_0023BAC0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tod", func_0023C0E8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tod", todSetCurrentTOD__Ff);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tod", todDisable__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tod", func_0023C138);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tod", func_0023C160);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tod", func_0023C290);

#include "m2c_macros.h"
extern volatile char D_004C1270_e__Fii __asm__("D_004C1270");

void todSetPlightsActive__Fii(s32 arg0, s32 arg1)
{
  M2C_UNK *new_var;
  s32 *new_var2;
  new_var2 = &arg1;
  if (1)
  {
    new_var = (arg0 * 4) + (&D_004C1270_e__Fii);
    *new_var = *new_var2;
  }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tod", func_0023C368);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tod", func_0023C3F8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tod", func_0023C420);

void DeleteEntry__12CTODLinkListi(void) {
}

#include "m2c_macros.h"
s32 GetNumEntries__12CTODLinkList(s32* arg0) {
    return *arg0;
}

#include "m2c_macros.h"
s32 FindNodeByTime__12CTODLinkListf(void) {
    return 0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tod", FindFreeNode__12CTODLinkList);

void SortList__12CTODLinkList(void) {
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tod", ClearNode__12CTODLinkListP9_LinkNode);
