#include "common.h"
#include "m2c_macros.h"

s32 isValid__7HighwayPQ27Highway8Waypoint(void* arg0, void* arg1) {
    s32 var_v1;

    var_v1 = 0;
    if ((u32) arg1 >= (u32) arg0) {
        var_v1 = (u32) arg1 < (u32) (arg0 + (M2C_FIELD(arg0, s32* , 0x2444) * 0x10));
    }
    return var_v1;
}

s32 addOccupant__Q27Highway8WaypointP7Vehicle(void* arg0, void* arg1) {
    void* temp_v0;

    temp_v0 = M2C_FIELD(arg0, void** , 0xC);
    M2C_FIELD(arg1, void** , 0x2014) = temp_v0;
    M2C_FIELD(arg0, void** , 0xC) = arg1;
    return (s32) temp_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/highway", removeOccupant__Q27Highway8WaypointP7Vehicle);

s32 getNumOccupants__Q27Highway8Waypoint(void* arg0) {
    s32 var_v0;
    void* var_v1;

    var_v1 = M2C_FIELD(arg0, void** , 0xC);
    var_v0 = 0;
    if (var_v1 != NULL) {
        do {
            var_v1 = M2C_FIELD(var_v1, void** , 0x2014);
            var_v0 += 1;
        } while (var_v1 != NULL);
    }
    return var_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/highway", clearWaypoints__7Highway);

int isRoadblockSet__7Highwayi_58_11(void*, int) __asm__("isRoadblockSet__7Highwayi");
s32 clearRoadblock__7Highwayi(void* arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = isRoadblockSet__7Highwayi_58_11(arg0, arg1);
    if (var_v0 != 0) {
        if (M2C_FIELD(arg0, s32* , 0x244C) == arg1) {
            M2C_FIELD(arg0, s32* , 0x244C) = (s32) M2C_FIELD(arg0, s32* , 0x2450);
        }
        var_v0 = M2C_FIELD(arg0, s32* , 0x2448) - 1;
        M2C_FIELD(arg0, s32* , 0x2448) = var_v0;
    }
    return var_v0;
}

s32 isRoadblockSet__7Highwayi_50_16() __asm__("isRoadblockSet__7Highwayi");

void setRoadblock__7Highwayi(void *arg0, s32 arg1)
{
  void *new_var;
  u8 *new_var2;
  if (isRoadblockSet__7Highwayi_50_16() == 0)
  {
    *((s32 *) ((new_var2 = (u8 *) (arg0 + ((*((s32 *) (((u8 *) arg0) + 0x2448))) * 4))) + 0x244C)) = arg1;
    new_var = arg0;
    *((s32 *) (((u8 *) arg0) + 0x2448)) = (s32) ((*((s32 *) (((u8 *) new_var) + 0x2448))) + 1);
  }
}

s32 isRoadblockSet__7Highwayi(void* arg0, s32 arg1) {
    s32 var_v1;

    var_v1 = 0;
    if ((M2C_FIELD(arg0, s32* , 0x244C) == arg1) || (M2C_FIELD(arg0, s32* , 0x2450) == arg1)) {
        var_v1 = 1;
    }
    return var_v1;
}
