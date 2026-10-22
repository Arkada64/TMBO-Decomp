#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/watow", InitWaterTowerBefore__10WaterTower);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/watow", InitWaterTowerAfter__10WaterTower);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/watow", UpdateWaterTower__10WaterTower);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/watow", UpdateFalling__10WaterTower);

s32 AddEpNode__10WaterToweriP9_hierhead(void* arg0, s32 arg1, void* arg2) {
    if (arg1 == 0x28A0) {
        M2C_FIELD(arg0, void** , 0x64) = arg2;
    }
    return 0x28A0;
}
