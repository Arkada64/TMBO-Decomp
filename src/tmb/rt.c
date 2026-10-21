#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/rt", func_00183580);

#include "m2c_macros.h"
extern M2C_UNK D_00339A90_easoni __asm__("D_00339A90");

void rtReturnToShell__F14RtReturnReasoni(s32 arg0, s32 arg1)
{
  u8 *new_var;
  if ((*((s32 *) (((u8 *) (&D_00339A90_easoni)) + 0))) == 0)
  {
    new_var = ((u8 *) (&D_00339A90_easoni)) - -8;
    *((s32 *) new_var) = arg0;
    *((s32 *) (((u8 *) (&D_00339A90_easoni)) + 4)) = arg1;
    *((s32 *) (((u8 *) (&D_00339A90_easoni)) + 0)) = 1;
  }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/rt", func_00183BA0);
