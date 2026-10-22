#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/trafficdirector", init__15TrafficDirectorP7HighwayP7Vehiclei);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/trafficdirector", initAnim__15TrafficDirector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/trafficdirector", changeFodder__15TrafficDirectorP7Vehiclei);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/trafficdirector", disable__15TrafficDirectorP7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/trafficdirector", update__15TrafficDirector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/trafficdirector", isTollClear__15TrafficDirectorP7HighwayT1);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/trafficdirector", init__15HighwayDirectorP7HighwayP7Vehicleiif);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/trafficdirector", changeFodder__15HighwayDirectorP7Vehiclei);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/trafficdirector", init__15HighwayDirectorP7HighwayP7VehicleT2i);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/trafficdirector", init__15HighwayDirectorP7HighwayP7VehicleT2T2i);

s32 setNumSegments__15HighwayDirectori(void* arg0, s32 arg1) {
    s32 temp_lo;
    void* temp_a2;

    M2C_FIELD(arg0, s32* , 0x1E4) = arg1;
    temp_a2 = M2C_FIELD(arg0, void** , 0);
    temp_lo = (s32) ((s32) M2C_FIELD(temp_a2, s32* , 0x2444) / (s32) M2C_FIELD(temp_a2, s32* , 0x2440)) / arg1;
    M2C_FIELD(arg0, s32* , 0x1E8) = temp_lo;
    return temp_lo;
}

void setTrafficDensity__15HighwayDirectorf(void* arg0, f32 fparg0) {
    M2C_FIELD(arg0, f32* , 0x1EC) = fparg0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/trafficdirector", getVehicleSection__15HighwayDirectorP7Vehicle);

int getVehicleSection__15HighwayDirectorP7Vehicle_38_35(void*, void*) __asm__("getVehicleSection__15HighwayDirectorP7Vehicle");
s32 getVehicleSegment__15HighwayDirectorP7Vehicle(void* arg0, void* arg1) {
    return getVehicleSection__15HighwayDirectorP7Vehicle_38_35(arg0, arg1) / (s32) M2C_FIELD(arg0, s32* , 0x1E8);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/trafficdirector", getRangeFromStart__15HighwayDirectorP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/trafficdirector", update__15HighwayDirectorP7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/trafficdirector", update__15HighwayDirectorP7VehicleT1);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/trafficdirector", notifyOfOncoming__15HighwayDirectorP7Vehicle);

void disable__13HighwayDriver_54_51(void *) __asm__("disable__13HighwayDriver");
void vehicleDisable__7Vehicle_54_51(void *) __asm__("vehicleDisable__7Vehicle");

volatile unsigned int disable__15HighwayDirectorP7Vehicle(void *arg0, void *arg1)
{
  u8 *new_var;
  s32 temp_v0;
  vehicleDisable__7Vehicle_54_51(arg1);
  disable__13HighwayDriver_54_51(*((s32 *) (((u8 *) arg1) + 0x200C)));
  temp_v0 = *((s32 *) (((u8 *) arg0) + 0x1B8));
  *((s32 *) (((u8 *) arg0) + 0x1B8)) = (s32) (temp_v0 + 1);
  new_var = (u8 *) (arg0 + (temp_v0 * 4));
  *((void **) (new_var + 0x28)) = arg1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/trafficdirector", clearSegment__15HighwayDirectori);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/trafficdirector", getSegmentDensity__15HighwayDirectori);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/trafficdirector", getSegmentDensityMask__15HighwayDirectorif);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/trafficdirector", populateSegment__15HighwayDirectorii);

void vehicleResetStrength__7Vehicle_7C_68(void *) __asm__("vehicleResetStrength__7Vehicle");
void initVehicleSound__12VehicleSoundP7Vehicle_7C_68(void *, void *) __asm__("initVehicleSound__12VehicleSoundP7Vehicle");
void enable__13HighwayDriverPQ27Highway8Waypoint_7C_68(void *, void *) __asm__("enable__13HighwayDriverPQ27Highway8Waypoint");
M2C_UNK vehicleEnable__7Vehicle12VehicleTypes_7C_68() __asm__("vehicleEnable__7Vehicle12VehicleTypes");

s32 spawn__15HighwayDirectorPQ27Highway8Waypoint(void *arg0, void *arg1)
{
  u8 *new_var;
  s32 temp_v0;
  s32 temp_v0_2;
  void *temp_s0;
  temp_v0 = *((s32 *) (((u8 *) arg0) + 0x1B8));
  if (temp_v0 <= 0)
  {
    return 0;
  }
  temp_v0_2 = temp_v0 - 1;
  *((s32 *) (((u8 *) arg0) + 0x1B8)) = temp_v0_2;
  new_var = ((u8 *) (arg0 + (temp_v0_2 * 4))) + 0x28;
  temp_s0 = *((void **) new_var);
  vehicleEnable__7Vehicle12VehicleTypes_7C_68(temp_s0, 3);
  vehicleResetStrength__7Vehicle_7C_68(temp_s0);
  enable__13HighwayDriverPQ27Highway8Waypoint_7C_68(*((void **) (((u8 *) temp_s0) + 0x200C)), arg1);
  initVehicleSound__12VehicleSoundP7Vehicle_7C_68(temp_s0 + 0x2B20, temp_s0);
  return 1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/trafficdirector", pruneAllVehicles__15HighwayDirector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/trafficdirector", pruneSegment__15HighwayDirectori);
