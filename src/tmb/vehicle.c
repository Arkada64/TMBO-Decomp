#include "common.h"
#include "m2c_macros.h"

void shadow2ndOnOff__7Vehiclei_60_0(void*, int) __asm__("shadow2ndOnOff__7Vehiclei");
void hierSetCsDrawMe__FP3_csUc_60_0(void*, unsigned char) __asm__("hierSetCsDrawMe__FP3_csUc");
void vehicleEnable__7Vehicle12VehicleTypes(void* arg0, s32 arg1) {
    void* temp_a0;

    M2C_FIELD(arg0, s32* , 0x580) = arg1;
    M2C_FIELD(arg0, s32* , 0x20E8) = 0;
    M2C_FIELD(arg0, s32* , 0x210C) = 0;
    hierSetCsDrawMe__FP3_csUc_60_0(M2C_FIELD(arg0, void** , 0x2018), 1U);
    temp_a0 = M2C_FIELD(arg0, void** , 0x201C);
    if (temp_a0 != NULL) {
        hierSetCsDrawMe__FP3_csUc_60_0(temp_a0, 1U);
        shadow2ndOnOff__7Vehiclei_60_0(arg0, 1);
    }
}

void hierSetCsDrawMe__FP3_csUc_6C_4(void*, unsigned char) __asm__("hierSetCsDrawMe__FP3_csUc");
void shadow2ndOnOff__7Vehiclei_6C_4(void*, int) __asm__("shadow2ndOnOff__7Vehiclei");
void stopVehicleSounds__12VehicleSound_6C_4(void*) __asm__("stopVehicleSounds__12VehicleSound");

void vehicleDisable__7Vehicle(void* arg0) {
    s32 temp_a0;

    M2C_FIELD(arg0, s32* , 0x580) = 0;
    hierSetCsDrawMe__FP3_csUc_6C_4(M2C_FIELD(arg0, s32* , 0x2018), 0);
    temp_a0 = M2C_FIELD(arg0, s32* , 0x201C);
    if (temp_a0 != 0) {
        hierSetCsDrawMe__FP3_csUc_6C_4(temp_a0, 0);
        shadow2ndOnOff__7Vehiclei_6C_4(arg0, 0);
    }
    if (M2C_FIELD(arg0, s32* , 0x580) == 3) {
        stopVehicleSounds__12VehicleSound_6C_4(arg0 + 0x2B20);
    }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleSetToPosition__7VehicleP8_fvectorf);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleInit__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleInitDynamics__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleCleanUp__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleRecomputeDeltas__7Vehicleb);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleUpdate__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleUpdateAfterNewPos__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleCheckSpawnedCar__7Vehicle);

void hierSetSwitch__FP11_hierswitchi_E4_34(void*, int) __asm__("hierSetSwitch__FP11_hierswitchi");
void terminateShieldSound__11ShieldSound_E4_34(void*) __asm__("terminateShieldSound__11ShieldSound");
void updateShieldSound__11ShieldSoundP8_fvector_E4_34(void*, void*) __asm__("updateShieldSound__11ShieldSoundP8_fvector");

void vehicleUpdateShields__7Vehicle(void* arg0) {
    s32 temp_a0;
    void* temp_s1;

    if (M2C_FIELD(arg0, s8* , 0x484) != 0) {
        temp_a0 = M2C_FIELD(arg0, s32* , 0x204C);
        if (M2C_FIELD(arg0, s32* , 0x243C) != 0) {
            hierSetSwitch__FP11_hierswitchi_E4_34(temp_a0, 2);
            hierSetSwitch__FP11_hierswitchi_E4_34(M2C_FIELD(arg0, s32* , 0x2050), 2);
        } else {
            hierSetSwitch__FP11_hierswitchi_E4_34(temp_a0, 1);
            hierSetSwitch__FP11_hierswitchi_E4_34(M2C_FIELD(arg0, s32* , 0x2050), 1);
        }
        temp_s1 = arg0 + 0x2B1C;
        M2C_FIELD(arg0, s32* , 0x454) = (s32) (M2C_FIELD(arg0, s32* , 0x454) + M2C_FIELD(arg0, s32* , 0x20C8));
        updateShieldSound__11ShieldSoundP8_fvector_E4_34(temp_s1, arg0 + 0x1D0);
        if (M2C_FIELD(arg0, s32* , 0x454) >= 0xB5) {
            M2C_FIELD(arg0, s32* , 0x454) = 0;
            M2C_FIELD(arg0, s8* , 0x484) = 0;
            if (M2C_FIELD(arg0, s8* , 0x48A) == 0) {
                M2C_FIELD(arg0, s8* , 0x48B) = 1;
            }
            hierSetSwitch__FP11_hierswitchi_E4_34(M2C_FIELD(arg0, s32* , 0x204C), 0);
            hierSetSwitch__FP11_hierswitchi_E4_34(M2C_FIELD(arg0, s32* , 0x2050), 0);
            terminateShieldSound__11ShieldSound_E4_34(temp_s1);
        }
    }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleUpdateCloaking__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleUpdateFires__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleUpdateAnimations__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleCheckSMC__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleUpdateFrozenPlayer__7Vehicle);

M2C_UNK vehicleCheckStun__7Vehicle_50_53() __asm__("vehicleCheckStun__7Vehicle");
M2C_UNK vehicleCheckTraction__7Vehicle_50_53() __asm__("vehicleCheckTraction__7Vehicle");
M2C_UNK vehicleUpdateBrakeLight__7Vehicle_50_53() __asm__("vehicleUpdateBrakeLight__7Vehicle");
M2C_UNK vehicleUpdatePitch__7Vehicle_50_53() __asm__("vehicleUpdatePitch__7Vehicle");
M2C_UNK vehicleUpdateRoll__7Vehicle_50_53() __asm__("vehicleUpdateRoll__7Vehicle");
M2C_UNK vehicleUpdateSpeed__7Vehicle_50_53() __asm__("vehicleUpdateSpeed__7Vehicle");
M2C_UNK vehicleUpdateTurn__7Vehicle_50_53() __asm__("vehicleUpdateTurn__7Vehicle");

void vehicleUpdateControlPadDynamics__7Vehicle(s32 arg0) {
    vehicleCheckStun__7Vehicle_50_53();
    vehicleCheckTraction__7Vehicle_50_53(arg0);
    vehicleUpdateSpeed__7Vehicle_50_53(arg0);
    vehicleUpdateTurn__7Vehicle_50_53(arg0);
    vehicleUpdatePitch__7Vehicle_50_53(arg0);
    vehicleUpdateRoll__7Vehicle_50_53(arg0);
    vehicleUpdateBrakeLight__7Vehicle_50_53(arg0);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleUpdateBrakeLight__7Vehicle);

void mathfSetFVector__FP8_fvectorfff_84_57(void*, float, float, float) __asm__("mathfSetFVector__FP8_fvectorfff");
M2C_UNK memset_84_57() __asm__("memset");

void vehicleCheckStun__7Vehicle(void* arg0) {
    f32 temp_f12;
    s32 temp_v0;
    s32 temp_v1;
    s8 temp_s0;

    temp_v1 = M2C_FIELD(arg0, s32* , 0x464);
    if (temp_v1 != 0) {
        temp_v0 = temp_v1 - M2C_FIELD(arg0, s32* , 0x20C8);
        M2C_FIELD(arg0, s32* , 0x464) = temp_v0;
        if (temp_v0 < 0) {
            M2C_FIELD(arg0, s32* , 0x464) = 0;
        }
        temp_s0 = M2C_FIELD(arg0, s8* , 0x584);
        memset_84_57(arg0 + 0x584, 0, 0x12);
        M2C_FIELD(arg0, f32* , 0x2C4) = 0.0f;
        M2C_FIELD(arg0, s8* , 0x584) = temp_s0;
        temp_f12 = M2C_FIELD(arg0, f32* , 0x2C4);
        mathfSetFVector__FP8_fvectorfff_84_57(arg0 + 0x1F0, temp_f12, temp_f12, temp_f12);
    }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleCheckTraction__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleUpdateSpeed__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleUpdateTurn__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleUpdatePitch__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleUpdateRoll__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleDecrementTurbo__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleShouldBeDrifting__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleFullDrift__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleUpdatePosition__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleSetCsMat__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleSetCsKlod__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleUpdateDrift__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleUpdatePeelingOut__7Vehicleb);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleInitJump__7Vehicle9_jumpType);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleCheckFreeHealth__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleInitRollOver__7VehicleP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleUpdateRollingCar__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleBringBackRotChange__7VehiclePff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleTakeHit__7VehicleP8_fvectorii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", minionTakeHit__7Vehiclei);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", tankerTakeHit__7Vehiclei);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleRestoreHealth__7Vehiclef);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleSlowDown__7Vehiclef);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleBlowUpCar__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleUpdateDeathSequence__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", tankerUpdateDeathSequence__7Vehicle);

void fodderLeftTurnSignal__7Vehicleb_1D0_129(void*, unsigned char) __asm__("fodderLeftTurnSignal__7Vehicleb");
void fodderRightTurnSignal__7Vehicleb_1D0_129(void*, unsigned char) __asm__("fodderRightTurnSignal__7Vehicleb");
void hierSetSwitch__FP11_hierswitchi_1D0_129(void*, int) __asm__("hierSetSwitch__FP11_hierswitchi");
void particleKillFx__Fi_1D0_129(int) __asm__("particleKillFx__Fi");
void terminateFlameSound__10FlameSound_1D0_129(void*) __asm__("terminateFlameSound__10FlameSound");
extern u8 game_1D0_129[4] __asm__("game");

void vehicleResetStrength__7Vehicle(void* arg0) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;

    M2C_FIELD(arg0, s8* , 0x475) = 0;
    M2C_FIELD(arg0, f32* , 0x3F4) = (f32) M2C_FIELD(arg0, f32* , 0x3F0);
    M2C_FIELD(arg0, s8* , 0x478) = 0;
    if (M2C_FIELD(arg0, s32* , 0x580) == 3) {
        temp_a0 = M2C_FIELD(arg0, s32* , 0x2028);
        M2C_FIELD(arg0, s32* , 0x2090) = 0;
        if (temp_a0 != 0) {
            hierSetSwitch__FP11_hierswitchi_1D0_129(temp_a0, 0);
        }
        temp_a0_2 = M2C_FIELD(arg0, s32* , 0x202C);
        if (temp_a0_2 != 0) {
            hierSetSwitch__FP11_hierswitchi_1D0_129(temp_a0_2, 0);
        }
        temp_a0_3 = M2C_FIELD(arg0, s32* , 0x2030);
        if (temp_a0_3 != 0) {
            hierSetSwitch__FP11_hierswitchi_1D0_129(temp_a0_3, 0);
        }
        if (M2C_FIELD(arg0, s32* , 0x2034) != 0) {
            fodderLeftTurnSignal__7Vehicleb_1D0_129(arg0, 0);
            hierSetSwitch__FP11_hierswitchi_1D0_129(M2C_FIELD(arg0, s32* , 0x2034), 0);
        }
        if (M2C_FIELD(arg0, s32* , 0x2038) != 0) {
            fodderRightTurnSignal__7Vehicleb_1D0_129(arg0, 0);
            hierSetSwitch__FP11_hierswitchi_1D0_129(M2C_FIELD(arg0, s32* , 0x2038), 0);
        }
    }
    if ((M2C_FIELD(arg0, s32* , 0x20A8) == 0x1E0) && (M2C_FIELD(arg0, s32* , 0x580) == 2)) {
        if (M2C_FIELD((*(void**)game_1D0_129), s32* , 0x1AE650) == 4) {
            M2C_FIELD(arg0, s32* , 0x3F8) = 0x64;
            hierSetSwitch__FP11_hierswitchi_1D0_129(M2C_FIELD(arg0, s32* , 0x2058), 0);
            M2C_FIELD(arg0, s32* , 0x3FC) = 0x4B;
            hierSetSwitch__FP11_hierswitchi_1D0_129(M2C_FIELD(arg0, s32* , 0x205C), 0);
            M2C_FIELD(arg0, s32* , 0x400) = 0x4B;
            hierSetSwitch__FP11_hierswitchi_1D0_129(M2C_FIELD(arg0, s32* , 0x2060), 0);
            M2C_FIELD(arg0, s32* , 0x404) = 0x4B;
            hierSetSwitch__FP11_hierswitchi_1D0_129(M2C_FIELD(arg0, s32* , 0x2064), 0);
        } else {
            M2C_FIELD(arg0, s32* , 0x3F8) = 0x23;
            hierSetSwitch__FP11_hierswitchi_1D0_129(M2C_FIELD(arg0, s32* , 0x2058), 0);
            M2C_FIELD(arg0, s32* , 0x3FC) = 5;
            hierSetSwitch__FP11_hierswitchi_1D0_129(M2C_FIELD(arg0, s32* , 0x205C), 0);
            M2C_FIELD(arg0, s32* , 0x400) = 0x19;
            hierSetSwitch__FP11_hierswitchi_1D0_129(M2C_FIELD(arg0, s32* , 0x2060), 0);
            M2C_FIELD(arg0, s32* , 0x404) = 0x19;
            hierSetSwitch__FP11_hierswitchi_1D0_129(M2C_FIELD(arg0, s32* , 0x2064), 0);
        }
    }
    if (M2C_FIELD(arg0, s8* , 0x485) != 0) {
        M2C_FIELD(arg0, s32* , 0x460) = 0;
        M2C_FIELD(arg0, s8* , 0x485) = 0;
        particleKillFx__Fi_1D0_129(M2C_FIELD(arg0, s32* , 0x2B14));
        M2C_FIELD(arg0, s32* , 0x2B14) = -1;
        terminateFlameSound__10FlameSound_1D0_129(arg0 + 0x2B18);
    }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleSaveAndClearPadFlags__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleReactToWeaponDamage__7VehicleP8_fvectorib);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleUpdateTurbos__7Vehicle);

void vehicleStunCar__7Vehiclei(void* arg0, s32 arg1) {
    M2C_FIELD(arg0, s32* , 0x464) = arg1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", vehicleCheckForCombos__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", figureOutForceField__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", SetCarOnFire__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", func_001B0890);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", func_001B08A0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", func_001B08C0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vehicle", func_001B08D0);
