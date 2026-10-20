#include "common.h"

#include "m2c_macros.h"
M2C_UNK hierSetCsDrawMe__FP3_csUc_eTypes() __asm__("hierSetCsDrawMe__FP3_csUc");
M2C_UNK shadow2ndOnOff__7Vehiclei_eTypes() __asm__("shadow2ndOnOff__7Vehiclei");

void vehicleEnable__7Vehicle12VehicleTypes(void* arg0, s32 arg1) {
    s32 temp_a0;

    M2C_FIELD_V1(arg0, s32* , 0x590) = arg1;
    M2C_FIELD_V1(arg0, s32* , 0x2134) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x2158) = 0;
    hierSetCsDrawMe__FP3_csUc_eTypes(M2C_FIELD_V1(arg0, s32* , 0x2028), 1);
    temp_a0 = M2C_FIELD_V1(arg0, s32* , 0x202C);
    if (temp_a0 != 0) {
        hierSetCsDrawMe__FP3_csUc_eTypes(temp_a0, 1);
        shadow2ndOnOff__7Vehiclei_eTypes(arg0, 1);
    }
}

#include "m2c_macros.h"
M2C_UNK hierSetCsDrawMe__FP3_csUc_ehicle() __asm__("hierSetCsDrawMe__FP3_csUc");
M2C_UNK shadow2ndOnOff__7Vehiclei_ehicle() __asm__("shadow2ndOnOff__7Vehiclei");

void vehicleDisable__7Vehicle(void* arg0) {
    s32 temp_a0;
    s32 temp_a0_2;

    M2C_FIELD_V1(arg0, s32* , 0x590) = 0;
    hierSetCsDrawMe__FP3_csUc_ehicle(M2C_FIELD_V1(arg0, s32* , 0x2028), 0);
    temp_a0 = M2C_FIELD_V1(arg0, s32* , 0x202C);
    if (temp_a0 != 0) {
        hierSetCsDrawMe__FP3_csUc_ehicle(temp_a0, 0);
        shadow2ndOnOff__7Vehiclei_ehicle(arg0, 0);
    }
    temp_a0_2 = M2C_FIELD_V1(arg0, s32* , 0x2038);
    if (temp_a0_2 != 0) {
        hierSetCsDrawMe__FP3_csUc_ehicle(temp_a0_2, 0);
    }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", vehicleSetToPosition__7VehicleP8_fvectorf);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001D6F78);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001D72D8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001DC130);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", vehicleRecomputeDeltas__7Vehicleb);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001DC760);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001DCD48);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001DCFC8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001DD0C8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001DD1B8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001DD5A8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001DD708);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", vehicleCheckSMC__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", vehicleUpdateFrozenPlayer__7Vehicle);

#include "m2c_macros.h"
M2C_UNK func_001DDCF0_1DDC78() __asm__("func_001DDCF0");
M2C_UNK func_001DDF58_1DDC78() __asm__("func_001DDF58");
M2C_UNK func_001DEFB0_1DDC78() __asm__("func_001DEFB0");
M2C_UNK func_001DF320_1DDC78() __asm__("func_001DF320");
M2C_UNK vehicleCheckStun__7Vehicle_1DDC78() __asm__("vehicleCheckStun__7Vehicle");
M2C_UNK vehicleCheckTraction__7Vehicle_1DDC78() __asm__("vehicleCheckTraction__7Vehicle");
M2C_UNK vehicleUpdateTurn__7Vehicle_1DDC78() __asm__("vehicleUpdateTurn__7Vehicle");

void func_001DDC78(void* arg0) {
    if (M2C_FIELD_V1(arg0, s32* , 0x20B4) != 5) {
        vehicleCheckStun__7Vehicle_1DDC78();
        vehicleCheckTraction__7Vehicle_1DDC78(arg0);
        func_001DDF58_1DDC78(arg0);
        vehicleUpdateTurn__7Vehicle_1DDC78(arg0);
        func_001DEFB0_1DDC78(arg0);
        func_001DF320_1DDC78(arg0);
        func_001DDCF0_1DDC78(arg0);
        return;
    }
    vehicleUpdateTurn__7Vehicle_1DDC78(arg0);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001DDCF0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", vehicleCheckStun__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", vehicleCheckTraction__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001DDF58);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", vehicleUpdateTurn__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001DEFB0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001DF320);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001DF5A0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001DF5D8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", vehicleFullDrift__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001DF840);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001E0230);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001E02B0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001E03C0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", vehicleUpdatePeelingOut__7Vehicleb);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", vehicleInitJump__7Vehicle9_jumpType);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", vehicleInitRollOver__7VehicleP8_fvector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001E1398);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", vehicleBringBackRotChange__7VehiclePff);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001E1C40);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001E2A00);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001E3188);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001E32D8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", vehicleSlowDown__7Vehiclef);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001E3478);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001E3800);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001E3FE0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", vehicleSaveAndClearPadFlags__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", vehicleReactToWeaponDamage__7VehicleP8_fvectorib);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001E4500);

#include "m2c_macros.h"
void vehicleStunCar__7Vehiclei(void* arg0, s32 arg1) {
    M2C_FIELD_V1(arg0, s32* , 0x474) = arg1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001E4690);

void func_001E4F38(void) {
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001E4F40);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", SetCarOnFire__7Vehicle);
