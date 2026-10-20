#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/highway", isValid__7HighwayPQ27Highway8Waypoint);

#include "m2c_macros.h"
void addOccupant__Q27Highway8WaypointP7Vehicle(void* arg0, void* arg1) {
    M2C_FIELD_V1(arg1, void** , 0x2024) = (void* ) M2C_FIELD_V1(arg0, void** , 0xC);
    M2C_FIELD_V1(arg0, void** , 0xC) = arg1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/highway", removeOccupant__Q27Highway8WaypointP7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/highway", func_00142190);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/highway", clearWaypoints__7Highway);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/highway", clearRoadblock__7Highwayi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/highway", func_00142298);

#include "m2c_macros.h"
s32 isRoadblockSet__7Highwayi(void* arg0, s32 arg1) {
    s32 var_v1;

    var_v1 = 0;
    if ((M2C_FIELD_V1(arg0, s32* , 0x245C) == arg1) || (M2C_FIELD_V1(arg0, s32* , 0x2460) == arg1)) {
        var_v1 = 1;
    }
    return var_v1;
}
