#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/highwaydriver", func_00142310);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/highwaydriver", setupCheapDriving__13HighwayDriver);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/highwaydriver", func_001423B8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/highwaydriver", func_00142488);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/highwaydriver", func_00142648);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/highwaydriver", func_00142670);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/highwaydriver", func_00142BF0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/highwaydriver", func_00142D30);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/highwaydriver", func_00142E70);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/highwaydriver", func_00143020);

#include "m2c_macros.h"
M2C_UNK removeOccupant__Q27Highway8WaypointP7Vehicle_Driver() __asm__("removeOccupant__Q27Highway8WaypointP7Vehicle");

void disable__13HighwayDriver(void* arg0) {
    s32 temp_a0;

    temp_a0 = M2C_FIELD_V1(arg0, s32* , 0x18);
    if (temp_a0 != 0) {
        removeOccupant__Q27Highway8WaypointP7Vehicle_Driver(temp_a0, M2C_FIELD_V1(arg0, s32* , 0x10));
    }
    M2C_FIELD_V1(arg0, s32* , 0x18) = 0;
    M2C_FIELD_V1(arg0, s32* , 4) = 1;
}

#include "m2c_macros.h"
M2C_UNK addOccupant__Q27Highway8WaypointP7Vehicle_ypoint() __asm__("addOccupant__Q27Highway8WaypointP7Vehicle");
M2C_UNK removeOccupant__Q27Highway8WaypointP7Vehicle_ypoint() __asm__("removeOccupant__Q27Highway8WaypointP7Vehicle");

void changeWaypoints__13HighwayDriverPQ27Highway8Waypoint(void* arg0, s32 arg1) {
    s32 temp_a0;

    temp_a0 = M2C_FIELD_V1(arg0, s32* , 0x18);
    if (temp_a0 != 0) {
        removeOccupant__Q27Highway8WaypointP7Vehicle_ypoint(temp_a0, M2C_FIELD_V1(arg0, s32* , 0x10));
    }
    M2C_FIELD_V1(arg0, s32* , 0x18) = arg1;
    addOccupant__Q27Highway8WaypointP7Vehicle_ypoint(arg1, M2C_FIELD_V1(arg0, s32* , 0x10));
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/highwaydriver", func_001430E0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/highwaydriver", getRangeToDriver2__13HighwayDriverP13HighwayDriver);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/highwaydriver", getClosestVehicleInLane__13HighwayDriverRf);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/highwaydriver", updateCurrentWaypointInLane__13HighwayDriver);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/highwaydriver", updateCurrentWaypointInArea__13HighwayDriver);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/highwaydriver", getRangeToWaypoint2__13HighwayDriverPQ27Highway8Waypoint);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/highwaydriver", handleEndOfHighway__13HighwayDriver);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/highwaydriver", getWaypointIndex__7HighwayPQ27Highway8Waypoint);
