#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/freewaytrain_part2", func_00137760);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/freewaytrain_part2", finishExplosion__15FreewayTrainCarP8_fvectorb);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/freewaytrain_part2", func_00137BE8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/freewaytrain_part2", getPos__15FreewayTrainCarP8_fvector);

#include "m2c_macros.h"
void initBefore__15FreewayTrainCar(void *arg0)
{
  *((s32 *) (((u8 *) arg0) + 0x58)) = 0;
 do { } while (0);
  *((s32 *) (((u8 *) arg0) + 0)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x54)) = 0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/freewaytrain_part2", initAfter__15FreewayTrainCar);

#include "m2c_macros.h"
M2C_UNK getPos__15FreewayTrainCarP8_fvector_137D20() __asm__("getPos__15FreewayTrainCarP8_fvector");

void func_00137D20(s32 arg0, s32 arg1, M2C_UNK arg2) {
    getPos__15FreewayTrainCarP8_fvector_137D20((arg1 * 0x60) + arg0, arg2);
}

#include "m2c_macros.h"
M2C_UNK finishExplosion__15FreewayTrainCarP8_fvectorb_Traini() __asm__("finishExplosion__15FreewayTrainCarP8_fvectorb");
M2C_UNK getPos__15FreewayTrainCarP8_fvector_Traini() __asm__("getPos__15FreewayTrainCarP8_fvector");

void popCar__12FreewayTraini(s32 arg0, s32 arg1) {
    u8 sp[0x10];
    s32 temp_s0;

    temp_s0 = (arg1 * 0x60) + arg0;
    getPos__15FreewayTrainCarP8_fvector_Traini(temp_s0, sp);
    finishExplosion__15FreewayTrainCarP8_fvectorb_Traini(temp_s0, sp, 1);
}
