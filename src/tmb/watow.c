#include "common.h"
#include "m2c_macros.h"

void InitWaterTowerBefore__10WaterTower(void *arg0)
{
  u8 *new_var;
  new_var = ((u8 *) arg0) + 0x64;
  *((s32 *) new_var) = 0;
 do { } while (0);
  *((s32 *) (((u8 *) arg0) + 0x60)) = 0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/watow", InitWaterTowerAfter__10WaterTower);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/watow", UpdateWaterTower__10WaterTower);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/watow", UpdateFalling__10WaterTower);

s32 AddEpNode__10WaterToweriP9_hierhead(void* arg0, s32 arg1, void* arg2) {
    if (arg1 == 0x28A0) {
        M2C_FIELD(arg0, void** , 0x64) = arg2;
    }
    return 0x28A0;
}
