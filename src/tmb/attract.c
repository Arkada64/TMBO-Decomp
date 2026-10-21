#include "common.h"

#include "m2c_macros.h"
void addOccupant__12AttractPointP7Vehicle(void* arg0, void* arg1) {
    M2C_FIELD_V1(arg1, void** , 0x2024) = (void* ) M2C_FIELD_V1(arg0, void** , 0xC);
    M2C_FIELD_V1(arg0, void** , 0xC) = arg1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", removeOccupant__12AttractPointP7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", func_0010B660);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", attractInitBeforeDbLoad__15AttractorPointsP12AttractPointP10StartPoint);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", attractInitAfterDbLoad__15AttractorPoints);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", func_0010B950);

#include "m2c_macros.h"
f32 attractGetMaxRangeForBeadBetweenGroups__15AttractorPointsii(s32 arg0, s32 arg1, s32 arg2)
{
  f32 var_f0;
  void *temp_v1;
  u8 *new_var;
  var_f0 = 0.0f;
  new_var = (u8 *) (arg0 + (arg1 * 4));
  temp_v1 = *((void **) (new_var + 8));
  if ((*((u8 *) (((u8 *) (temp_v1 + arg2)) + 0x140))) & 1)
  {
    var_f0 = *((f32 *) (((u8 *) temp_v1) + 0x18));
  }
  return var_f0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", attractGetClosestPoint__15AttractorPointsP8_fvector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", func_0010BA78);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", func_0010BB10);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", func_0010BC10);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", attractInitPoints__15AttractorPointsii);

#include "m2c_macros.h"
void func_0010BD88(void* arg0) {
    s32 temp_v1;
    s32 var_a1;

    var_a1 = 0;
    if (M2C_FIELD(arg0, s32* , 0x24C) > 0) {
        do {
            temp_v1 = var_a1 * 4;
            var_a1 += 1;
            M2C_FIELD((temp_v1 + M2C_FIELD(arg0, s32* , 4)), s16* , 2) = 0;
        } while (var_a1 < M2C_FIELD(arg0, s32* , 0x24C));
    }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", func_0010BDC0);

#include "m2c_macros.h"
s32 func_0010BE08(void* arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD_V1(arg0, s32* , 0x24C);
    return (arg1 >= temp_v0) ? 0 : temp_v0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", func_0010BE18);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", func_0010BEF8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", func_0010BFD8);

#include "m2c_macros.h"
M2C_UNK attractiInitGroupIndirection__FPii_Groups() __asm__("attractiInitGroupIndirection__FPii");
s32 attractiInitLevelsGroups__FP8GroupDat_Groups() __asm__("attractiInitLevelsGroups__FP8GroupDat");

void attractInitAfterDbLoad__18AttractPointGroups(void *arg0)
{
  s32 temp_v0;
  void *new_var;
  new_var = arg0 + 0x7080;
  temp_v0 = attractiInitLevelsGroups__FP8GroupDat_Groups();
  *((s32 *) (((u8 *) arg0) + 0x71A0)) = temp_v0;
  attractiInitGroupIndirection__FPii_Groups(new_var, temp_v0);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", attractGetCenterOfGroup__15AttractorPointsP8_fvectori);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", func_0010C250);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", attractGetRandomTransPoint__15AttractorPointsi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", attractGetSnipePoint__15AttractorPointsi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", func_0010C458);
