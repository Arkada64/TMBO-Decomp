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

#include "m2c_macros.h"
M2C_UNK __builtin_delete_23C3F8() __asm__("__builtin_delete");

void func_0023C3F8(s32 arg0, s32 arg1)
{
  s32 temp_a1;
  s32 new_var;
  ;
  if ((arg1 & 1) != 0)
  {
    new_var = temp_a1;
    __builtin_delete_23C3F8(new_var);
  }
}

#include "m2c_macros.h"
s32 FindFreeNode__12CTODLinkList_23C420() __asm__("FindFreeNode__12CTODLinkList");

s32 func_0023C420(void *arg0)
{
  s32 temp_v0;
  if (((*((s32 *) (((u8 *) arg0) + 0))) < 0xC) && ((temp_v0 = FindFreeNode__12CTODLinkList_23C420(), temp_v0 != (-1))))
  {
    if ((*((s32 *) (((u8 *) arg0) + 4))) == (-1))
    {
      *((s32 *) (((u8 *) arg0) + 8)) = (*((s32 *) (((u8 *) arg0) + 4)) = temp_v0);
      *((s32 *) (((u8 *) arg0) + 0)) = (s32) ((*((s32 *) (((u8 *) arg0) + 0))) + 1);
    }
  }
  return 0;
}

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

#include "m2c_macros.h"
void ClearNode__12CTODLinkListP9_LinkNode(s32 arg0, void *arg1)
{
  *((s32 *) (((u8 *) arg1) + 0x10)) = 0;
  *((s32 *) (((u8 *) arg1) + 0xC)) = -1;
 do { *((s32 *) (((u8 *) arg1) + 0)) = -1; *((s32 *) (((u8 *) arg1) + 4)) = -1; } while (0);
  *((s32 *) (((u8 *) arg1) + 8)) = -1;
}
