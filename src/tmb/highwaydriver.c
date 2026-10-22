#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/highwaydriver", init__13HighwayDriverP7HighwayP7Vehicle);

f32 mathfNormalize__FP8_fvectorT0_68_3(void*, void*) __asm__("mathfNormalize__FP8_fvectorT0");
void mathfSubVector__FP8_fvectorT0T0_68_3(void*, void*, void*) __asm__("mathfSubVector__FP8_fvectorT0T0");

void setupCheapDriving__13HighwayDriver(void* arg0) {
    s32 temp_s1;

    temp_s1 = arg0 + 0x20;
    mathfSubVector__FP8_fvectorT0T0_68_3(temp_s1, M2C_FIELD(arg0, s32* , 0x1C), M2C_FIELD(M2C_FIELD(arg0, void** , 0x10), s32* , 0x2018) + 0x10);
    M2C_FIELD(arg0, f32* , 0x28) = (f32) (M2C_FIELD(arg0, f32* , 0x28) - M2C_FIELD(M2C_FIELD(arg0, void** , 0x10), f32* , 0x394));
    M2C_FIELD(arg0, f32* , 0x2C) = mathfNormalize__FP8_fvectorT0_68_3(temp_s1, temp_s1);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/highwaydriver", updateCheapDriving__13HighwayDriver);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/highwaydriver", updatePosition__13HighwayDriverb);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/highwaydriver", restoreNormalDriving__13HighwayDriver);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/highwaydriver", updateSteering__13HighwayDriver);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/highwaydriver", isLaneClear__13HighwayDriverPQ27Highway8Waypointiii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/highwaydriver", isAnyoneEntering__13HighwayDriverPQ27Highway8Waypoint);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/highwaydriver", dodgeVehicle__13HighwayDriverP7Vehicle);

void teleport__13HighwayDriverPQ27Highway8Waypoint_2C_22() __asm__("teleport__13HighwayDriverPQ27Highway8Waypoint");

void enable__13HighwayDriverPQ27Highway8Waypoint(void *arg0)
{
  teleport__13HighwayDriverPQ27Highway8Waypoint_2C_22();
  *((s32 *) (((u8 *) arg0) + 4)) = 2;
}

void removeOccupant__Q27Highway8WaypointP7Vehicle_40_23(void*, void*) __asm__("removeOccupant__Q27Highway8WaypointP7Vehicle");
s32 disable__13HighwayDriver(void* arg0) {
    void* temp_a0;

    temp_a0 = M2C_FIELD(arg0, void** , 0x18);
    if (temp_a0 != NULL) {
        removeOccupant__Q27Highway8WaypointP7Vehicle_40_23(temp_a0, M2C_FIELD(arg0, void** , 0x10));
    }
    M2C_FIELD(arg0, void** , 0x18) = NULL;
    M2C_FIELD(arg0, s32* , 4) = 1;
    return 1;
}

void addOccupant__Q27Highway8WaypointP7Vehicle_48_27(void*, void*) __asm__("addOccupant__Q27Highway8WaypointP7Vehicle");
void removeOccupant__Q27Highway8WaypointP7Vehicle_48_27(void*, void*) __asm__("removeOccupant__Q27Highway8WaypointP7Vehicle");

void changeWaypoints__13HighwayDriverPQ27Highway8Waypoint(void* arg0, s32 arg1) {
    s32 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s32* , 0x18);
    if (temp_a0 != 0) {
        removeOccupant__Q27Highway8WaypointP7Vehicle_48_27(temp_a0, M2C_FIELD(arg0, s32* , 0x10));
    }
    M2C_FIELD(arg0, s32* , 0x18) = arg1;
    addOccupant__Q27Highway8WaypointP7Vehicle_48_27(arg1, M2C_FIELD(arg0, s32* , 0x10));
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/highwaydriver", teleport__13HighwayDriverPQ27Highway8Waypoint);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/highwaydriver", getRangeToDriver2__13HighwayDriverP13HighwayDriver);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/highwaydriver", getClosestVehicleInLane__13HighwayDriverRf);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/highwaydriver", updateCurrentWaypointInLane__13HighwayDriver);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/highwaydriver", updateCurrentWaypointInArea__13HighwayDriver);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/highwaydriver", getRangeToWaypoint2__13HighwayDriverPQ27Highway8Waypoint);

s32 getWaypointIndex__7HighwayPQ27Highway8Waypoint_5C_46(void*, void*) __asm__("getWaypointIndex__7HighwayPQ27Highway8Waypoint");
void teleport__13HighwayDriverPQ27Highway8Waypoint_5C_46(void*, void*) __asm__("teleport__13HighwayDriverPQ27Highway8Waypoint");

void handleEndOfHighway__13HighwayDriver(void* arg0) {
    void* temp_s1;

    temp_s1 = M2C_FIELD(arg0, void** , 0x14);
    teleport__13HighwayDriverPQ27Highway8Waypoint_5C_46(arg0, M2C_FIELD(arg0, void** , 0x14) + ((getWaypointIndex__7HighwayPQ27Highway8Waypoint_5C_46(temp_s1, M2C_FIELD(arg0, s32* , 0x18)) % (s32) M2C_FIELD(temp_s1, s32* , 0x2440)) * 0x10));
}

s32 getWaypointIndex__7HighwayPQ27Highway8Waypoint(void* arg0, void* arg1) {
    return (s32) (arg1 - arg0) >> 4;
}
