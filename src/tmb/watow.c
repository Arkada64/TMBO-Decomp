#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/watow", InitWaterTowerBefore__10WaterTower);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/watow", InitWaterTowerAfter__10WaterTower);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/watow", func_001E5C28);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/watow", func_001E5D98);

#include "m2c_macros.h"
void AddEpNode__10WaterToweriP9_hierhead(void* arg0, s32 arg1, s32 arg2) {
    if (arg1 == 0x28A0) {
        M2C_FIELD_V1(arg0, s32* , 0x64) = arg2;
    }
}
