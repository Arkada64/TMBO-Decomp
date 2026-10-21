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

#include "m2c_macros.h"
M2C_UNK func_001957E0_1DD0C8() __asm__("func_001957E0");
M2C_UNK hierSetSwitch__FP11_hierswitchi_1DD0C8() __asm__("hierSetSwitch__FP11_hierswitchi");
M2C_UNK updateShieldSound__11ShieldSoundP8_fvector_1DD0C8() __asm__("updateShieldSound__11ShieldSoundP8_fvector");

void func_001DD0C8(void *arg0)
{
  u8 *new_var;
  s32 temp_a0;
  s32 temp_v1;
  void *temp_a0_2;
  if ((*((s8 *) (((u8 *) arg0) + 0x497))) != 0)
  {
    temp_a0 = *((s32 *) (((u8 *) arg0) + 0x2068));
    if ((*((s32 *) (((u8 *) arg0) + 0x24B4))) != 0)
    {
      hierSetSwitch__FP11_hierswitchi_1DD0C8(temp_a0, 2);
      hierSetSwitch__FP11_hierswitchi_1DD0C8(*((s32 *) (((u8 *) arg0) + 0x206C)), 2);
    }
    else
    {
      hierSetSwitch__FP11_hierswitchi_1DD0C8(temp_a0, 1);
      hierSetSwitch__FP11_hierswitchi_1DD0C8(*((s32 *) (((u8 *) arg0) + 0x206C)), 1);
    }
    ;
    *((s32 *) (((u8 *) arg0) + 0x464)) = (s32) ((*((s32 *) (((u8 *) arg0) + 0x464))) + (*((s32 *) (((u8 *) arg0) + 0x2114))));
    updateShieldSound__11ShieldSoundP8_fvector_1DD0C8(arg0 + 0x2F50, arg0 + 0x1D0);
    temp_v1 = *((s32 *) (((u8 *) arg0) + 0x20B4));
    new_var = (u8 *) arg0;
    if (((temp_v1 == 1) && ((*((s32 *) (((u8 *) arg0) + 0x464))) >= 0xB5)) || ((temp_v1 == 2) && ((*((s8 *) (0x498 + ((u8 *) arg0)))) == 0)))
    {
      *((s32 *) (((u8 *) arg0) + 0x464)) = 0;
      *((s8 *) (new_var + 0x497)) = 0;
      hierSetSwitch__FP11_hierswitchi_1DD0C8(*((s32 *) (((u8 *) arg0) + 0x2068)), 0);
      hierSetSwitch__FP11_hierswitchi_1DD0C8(*((s32 *) (((u8 *) arg0) + ((unsigned int) 0x206C))), 0);
      func_001957E0_1DD0C8(arg0 + 0x2F50);
    }
  }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001DD1B8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vehicle", func_001DD5A8);

#include "m2c_macros.h"
float animationStartReverse__FR11_animHandleb_1DD708(void*, int) __asm__("animationStartReverse__FR11_animHandleb");
int animationPause__FR11_animHandle_1DD708(void*) __asm__("animationPause__FR11_animHandle");
int animationIsRunning__FR11_animHandle_1DD708(void*) __asm__("animationIsRunning__FR11_animHandle");
M2C_UNK func_00110DC8_1DD708() __asm__("func_00110DC8");
M2C_UNK func_0013FF38_1DD708() __asm__("func_0013FF38");
M2C_UNK func_001E5420_1DD708() __asm__("func_001E5420");
M2C_UNK func_001FBCF8_1DD708() __asm__("func_001FBCF8");
M2C_UNK memset_1DD708() __asm__("memset");

void func_001DD708(void* arg0) {
    u8 sp[0x10];
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    u8 temp_s0;
    u8 temp_s1;

    if ((M2C_FIELD(arg0, s8* , 0x496) != 0) && ((temp_v1 = M2C_FIELD(arg0, s32* , 0x20B4), (temp_v1 == 1)) || (temp_v1 == 4))) {
        temp_s1 = M2C_FIELD(arg0, u8* , 0x5A1);
        temp_s0 = M2C_FIELD(arg0, u8* , 0x5A2);
        M2C_FIELD(arg0, s32* , 0x45C) = (s32) (M2C_FIELD(arg0, s32* , 0x45C) + 1);
        memset_1DD708(arg0 + 0x594, 0, 0x12);
        M2C_FIELD(arg0, u8* , 0x5A1) = temp_s1;
        M2C_FIELD(arg0, u8* , 0x5A2) = temp_s0;
        if ((M2C_FIELD(arg0, s32* , 0x20F4) == 0xC0) && (M2C_FIELD(arg0, s32* , 0x24B4) != 0)) {
            animationPause__FR11_animHandle_1DD708(arg0 + 0x2E98);
        }
        if (M2C_FIELD(arg0, s32* , 0x45C) >= 0xAB) {
            func_001FBCF8_1DD708(sp, M2C_FIELD(arg0, s32* , 0x20F4) + 0xE, M2C_FIELD(arg0, s32* , 0x20F0), 0);
            if (animationIsRunning__FR11_animHandle_1DD708(sp) == 0) {
                animationStartReverse__FR11_animHandleb_1DD708(sp, 0);
                if (M2C_FIELD(arg0, s32* , 0x2064) != 0) {
                    func_001FBCF8_1DD708(sp, M2C_FIELD(arg0, s32* , 0x20F4) + 0xE, M2C_FIELD(arg0, s32* , 0x20F0), 1);
                    animationStartReverse__FR11_animHandleb_1DD708(sp, 0);
                }
            }
        }
        if ((M2C_FIELD(arg0, s32* , 0x45C) >= 0xF1) && ((temp_v1_2 = M2C_FIELD(arg0, s32* , 0x20B4), (temp_v1_2 == 1)) || (temp_v1_2 == 4))) {
            func_001E5420_1DD708(arg0);
        }
    }
    temp_v1_3 = M2C_FIELD(arg0, s32* , 0x20F4);
    if (temp_v1_3 == 0x140) {
        func_0013FF38_1DD708(arg0);
    } else if (temp_v1_3 == 0x160) {
        func_00110DC8_1DD708(arg0);
    }
}

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
