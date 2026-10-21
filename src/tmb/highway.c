#include "common.h"

#include "m2c_macros.h"
s32 isValid__7HighwayPQ27Highway8Waypoint(void* arg0, u32 arg1) {
    s32 var_v1;

    var_v1 = 0;
    if (arg1 >= (u32) (arg0 + 0x10)) {
        var_v1 = arg1 < (u32) (arg0 + ((M2C_FIELD(arg0, s32* , 0x2454) * 0x10) + 0x10));
    }
    return var_v1;
}

#include "m2c_macros.h"
void addOccupant__Q27Highway8WaypointP7Vehicle(void* arg0, void* arg1) {
    M2C_FIELD_V1(arg1, void** , 0x2024) = (void* ) M2C_FIELD_V1(arg0, void** , 0xC);
    M2C_FIELD_V1(arg0, void** , 0xC) = arg1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/highway", removeOccupant__Q27Highway8WaypointP7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/highway", func_00142190);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/highway", clearWaypoints__7Highway);

#include "m2c_macros.h"
s32 isRoadblockSet__7Highwayi_ghwayi() __asm__("isRoadblockSet__7Highwayi");

void clearRoadblock__7Highwayi(void* arg0, s32 arg1) {
    if (isRoadblockSet__7Highwayi_ghwayi() != 0) {
        if (M2C_FIELD(arg0, s32* , 0x245C) == arg1) {
            M2C_FIELD(arg0, s32* , 0x245C) = (s32) M2C_FIELD(arg0, s32* , 0x2460);
        }
        M2C_FIELD(arg0, s32* , 0x2458) = (s32) (M2C_FIELD(arg0, s32* , 0x2458) - 1);
    }
}

#include "m2c_macros.h"
#include "m2c_macros.h"
s32 isRoadblockSet__7Highwayi_142298() __asm__("isRoadblockSet__7Highwayi");

void func_00142298(void *arg0, s32 arg1)
{
  s32 *new_var;
  if (isRoadblockSet__7Highwayi_142298() == 0)
  {
    new_var = (s32 *) (((u8 *) (arg0 + ((*((s32 *) (((u8 *) arg0) + 0x2458))) * 4))) + 0x245C);
    *new_var = arg1;
    *((s32 *) (((u8 *) arg0) + 0x2458)) = (s32) ((*((s32 *) (((u8 *) arg0) + 0x2458))) + 1);
  }
}

#include "m2c_macros.h"
s32 isRoadblockSet__7Highwayi(void* arg0, s32 arg1) {
    s32 var_v1;

    var_v1 = 0;
    if ((M2C_FIELD_V1(arg0, s32* , 0x245C) == arg1) || (M2C_FIELD_V1(arg0, s32* , 0x2460) == arg1)) {
        var_v1 = 1;
    }
    return var_v1;
}
