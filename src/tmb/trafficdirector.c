#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/trafficdirector", func_001B0688);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/trafficdirector", initAnim__15TrafficDirector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/trafficdirector", changeFodder__15TrafficDirectorP7Vehiclei);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/trafficdirector", func_001B0930);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/trafficdirector", func_001B0978);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/trafficdirector", isTollClear__15TrafficDirectorP7HighwayT1);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/trafficdirector", init__15HighwayDirectorP7HighwayP7Vehicleiif);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/trafficdirector", changeFodder__15HighwayDirectorP7Vehiclei);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/trafficdirector", init__15HighwayDirectorP7HighwayP7VehicleT2i);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/trafficdirector", init__15HighwayDirectorP7HighwayP7VehicleT2T2i);

#include "m2c_macros.h"
void setNumSegments__15HighwayDirectori(void* arg0, s32 arg1) {
    void* temp_a2;

    M2C_FIELD_V1(arg0, s32* , 0x1E4) = arg1;
    temp_a2 = M2C_FIELD_V1(arg0, void** , 0);
    M2C_FIELD_V1(arg0, s32* , 0x1E8) = (s32) ((s32) ((s32) M2C_FIELD_V1(temp_a2, s32* , 0x2454) / (s32) M2C_FIELD_V1(temp_a2, s32* , 0x2450)) / arg1);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/trafficdirector", setTrafficDensity__15HighwayDirectorf);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/trafficdirector", getVehicleSection__15HighwayDirectorP7Vehicle);

#include "m2c_macros.h"
s32 getVehicleSection__15HighwayDirectorP7Vehicle_ehicle() __asm__("getVehicleSection__15HighwayDirectorP7Vehicle");

s32 getVehicleSegment__15HighwayDirectorP7Vehicle(void* arg0) {
    return getVehicleSection__15HighwayDirectorP7Vehicle_ehicle() / (s32) M2C_FIELD_V1(arg0, s32* , 0x1E8);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/trafficdirector", getRangeFromStart__15HighwayDirectorP8_fvector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/trafficdirector", update__15HighwayDirectorP7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/trafficdirector", func_001B1648);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/trafficdirector", func_001B1B68);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/trafficdirector", disable__15HighwayDirectorP7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/trafficdirector", func_001B1D20);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/trafficdirector", func_001B1DC0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/trafficdirector", func_001B1E60);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/trafficdirector", func_001B1FF8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/trafficdirector", func_001B2110);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/trafficdirector", func_001B2190);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/trafficdirector", pruneSegment__15HighwayDirectori);
