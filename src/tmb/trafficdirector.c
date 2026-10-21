#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/trafficdirector", func_001B0688);

#include "m2c_macros.h"
long func_001FBCF8_rector() __asm__("func_001FBCF8");

void initAnim__15TrafficDirector(void *arg0)
{
  func_001FBCF8_rector(arg0 + 0x1F0, 0x283F, 0, 1);
  func_001FBCF8_rector(arg0 + 0x1FC, 0x283F, 0, 2);
  func_001FBCF8_rector(arg0 + 0x208, 0x2840, 0, 1);
  func_001FBCF8_rector(arg0 + 0x214, 0x2840, 0, 2);
  func_001FBCF8_rector(arg0 + 0x420, 0x283D, 0, 1);
  func_001FBCF8_rector(arg0 + 0x42C, 0x283D, 0, 2);
  func_001FBCF8_rector(arg0 + 0x438, 0x283E, 0, 1);
  func_001FBCF8_rector(arg0 + 0x444, 0x283E, 0, 2);
  *((s32 *) (((u8 *) arg0) + 0x220)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x450)) = 0;
}

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

#include "m2c_macros.h"
M2C_UNK disable__15HighwayDirectorP7Vehicle_1B2190() __asm__("disable__15HighwayDirectorP7Vehicle");

void func_001B2190(void *arg0)
{
  s32 temp_v0;
  s32 var_s1;
  void *var_s0;
  var_s1 = *((s32 *) (((u8 *) arg0) + 8));
  var_s0 = *((void **) (((u8 *) arg0) + 4));
  if (var_s1 != 0)
  {
    do
    {
      if (((*((s32 *) (((u8 *) var_s0) + 0x590))) != 0) && ((*((s32 *) (((u8 *) var_s0) + 0x17D8))) >= 0x385))
      {
        ;
        if ((*((s32 *) (((u8 *) var_s0) + 0x20AC))) == 0)
        {
          if ((*((s32 *) (((u8 *) var_s0) + 0x2134))) > 0)
          {
            disable__15HighwayDirectorP7Vehicle_1B2190(arg0, var_s0);
          }
        }
        else
          if ((*((s32 *) (((u8 *) var_s0) + 0x2134))) >= 0x385)
        {
          disable__15HighwayDirectorP7Vehicle_1B2190(arg0, var_s0);
        }
      }
      var_s1 -= 1;
      var_s0 += 0x31B0;
    }
    while (var_s1 != 0);
  }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/trafficdirector", pruneSegment__15HighwayDirectori);
