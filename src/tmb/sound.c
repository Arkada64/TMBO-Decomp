#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0018F560);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", initAnimationSound__14AnimationSoundP7Vehicle);

#include "m2c_macros.h"
M2C_UNK func_001A9600_18F5D0() __asm__("func_001A9600");

void func_0018F5D0(void) {
    func_001A9600_18F5D0();
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0018F5F0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0018F628);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", startAnimationSound__14AnimationSoundP7VehicleG11_animHandlei);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0018F8E0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", playTowTruckAnimationSound__14AnimationSound);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", playAnimationSound__14AnimationSoundii);

#include "m2c_macros.h"
M2C_UNK func_001FBCF8_18FD00() __asm__("func_001FBCF8");
M2C_UNK initCrossFadeLevels__12VehicleSound_18FD00() __asm__("initCrossFadeLevels__12VehicleSound");
s32 mathfRand__Fii_18FD00() __asm__("mathfRand__Fii");
s32 timerGetFieldCount__Fv_18FD00() __asm__("timerGetFieldCount__Fv");

void func_0018FD00(void* arg0, void* arg1) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;

    M2C_FIELD(arg0, void** , 0x184) = arg1;
    M2C_FIELD(arg0, f32* , 0x158) = (f32) M2C_FIELD(arg1, f32* , 0x320);
    initCrossFadeLevels__12VehicleSound_18FD00();
    M2C_FIELD(arg0, s32* , 0x15C) = 0;
    M2C_FIELD(arg0, s32* , 0x164) = 0;
    M2C_FIELD(arg0, s32* , 0x160) = 0;
    M2C_FIELD(arg0, s32* , 0x14) = 0;
    M2C_FIELD(arg0, s32* , 0xF4) = 0;
    M2C_FIELD(arg0, s32* , 0xF8) = 0;
    if (M2C_FIELD(arg1, s32* , 0x20F4) == 0xE0) {
        func_001FBCF8_18FD00(arg0 + 0x178, 0x12BE, M2C_FIELD(arg1, s32* , 0x20F0), 0);
    }
    M2C_FIELD(arg0, s32* , 0x14C) = 0;
    M2C_FIELD(arg0, s32* , 0x28) = 0;
    M2C_FIELD(arg0, s32* , 0x24) = 0;
    M2C_FIELD(arg0, s32* , 0x94) = 0;
    M2C_FIELD(arg0, s32* , 0x98) = 0;
    M2C_FIELD(arg0, s32* , 0x9C) = 0;
    M2C_FIELD(arg0, s32* , 0x20) = 0x3C;
    M2C_FIELD(arg0, s32* , 0xE0) = timerGetFieldCount__Fv_18FD00();
    temp_v0 = timerGetFieldCount__Fv_18FD00();
    M2C_FIELD(arg0, s32* , 0x34) = 0;
    M2C_FIELD(arg0, s32* , 0x4C) = 0;
    M2C_FIELD(arg0, s32* , 0x64) = 0;
    M2C_FIELD(arg0, s32* , 0x7C) = 0;
    M2C_FIELD(arg0, s32* , 0xE4) = temp_v0;
    temp_v0_2 = timerGetFieldCount__Fv_18FD00();
    M2C_FIELD(arg0, s32* , 0xA0) = 0;
    M2C_FIELD(arg0, s32* , 0xA8) = 0;
    M2C_FIELD(arg0, s32* , 0xD4) = 0;
    M2C_FIELD(arg0, s32* , 0xBC) = 0;
    M2C_FIELD(arg0, s32* , 0xB8) = 0;
    M2C_FIELD(arg0, s32* , 0x30) = 0;
    M2C_FIELD(arg0, s32* , 0x18) = temp_v0_2;
    M2C_FIELD(arg0, s32* , 0x144) = timerGetFieldCount__Fv_18FD00();
    temp_v0_3 = timerGetFieldCount__Fv_18FD00();
    M2C_FIELD(arg0, s32* , 0x174) = 0;
    M2C_FIELD(arg0, s32* , 0xF0) = temp_v0_3;
    M2C_FIELD(arg0, s32* , 8) = timerGetFieldCount__Fv_18FD00();
    temp_v0_4 = mathfRand__Fii_18FD00(0x78, 0xF0);
    M2C_FIELD(arg0, s32* , 0x10) = 0;
    M2C_FIELD(arg0, s32* , 0x11C) = 0;
    M2C_FIELD(arg0, s32* , 0xDC) = 1;
    M2C_FIELD(arg0, s32* , 0xC) = temp_v0_4;
    temp_v0_5 = timerGetFieldCount__Fv_18FD00();
    M2C_FIELD(arg0, s32* , 0x154) = 0;
    M2C_FIELD(arg0, s32* , 0xEC) = 0x12;
    M2C_FIELD(arg0, s32* , 0x120) = temp_v0_5;
    M2C_FIELD(arg0, s32* , 0x13C) = timerGetFieldCount__Fv_18FD00();
    M2C_FIELD(arg0, s32* , 0x140) = timerGetFieldCount__Fv_18FD00();
    M2C_FIELD(arg0, s32* , 4) = timerGetFieldCount__Fv_18FD00();
    M2C_FIELD(arg0, s32* , 0x124) = timerGetFieldCount__Fv_18FD00();
    temp_v0_6 = mathfRand__Fii_18FD00(8, 0x19);
    M2C_FIELD(arg0, s32* , 0x130) = 0;
    M2C_FIELD(arg0, s32* , 0x134) = 0;
    M2C_FIELD(arg0, s32* , 0x128) = temp_v0_6;
    M2C_FIELD(arg0, s32* , 0x12C) = timerGetFieldCount__Fv_18FD00();
    M2C_FIELD(arg0, s32* , 0x1C) = timerGetFieldCount__Fv_18FD00();
    M2C_FIELD(arg0, s32* , 0xD8) = 0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0018FE78);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0018FF80);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", playVehicleExplosion__12VehicleSoundP8_fvector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", initCrossFadeLevels__12VehicleSound);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_001902B0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00190A58);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00190B70);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00190C88);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00190DA0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00190EB8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00191048);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_001923B0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_001924C0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", playIceChopSound__12VehicleSound);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", playMinionShieldDamagedSound__12VehicleSound);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", playDeathSplashSound__12VehicleSound);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00192718);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00192770);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_001927C8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", playBlowHornSound__12VehicleSound);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00192970);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00192A10);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", updateVehicleEngine__12VehicleSoundfif);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_001933E8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_001935E0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", calculateSpeedAdjustment__12VehicleSound);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00193AC8);

#include "m2c_macros.h"
M2C_UNK func_001A6620_eSound() __asm__("func_001A6620");

void stopFodderEngine__12VehicleSound(s32 arg0) {
    func_001A6620_eSound(arg0 + 0x4C);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00193CF8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00193D40);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00193D88);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00193DD0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00193F38);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_001940E0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_001942E0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", updateVehicleSkid__12VehicleSoundPUiii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00194510);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00194570);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", playCollisionSound__12VehicleSoundii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00194B60);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00194D78);

#include "m2c_macros.h"
s32 timerGetFieldCount__Fv_194E48() __asm__("timerGetFieldCount__Fv");

void func_00194E48(void* arg0) {
    M2C_FIELD_V1(arg0, s32* , 0) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x1C) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x24) = timerGetFieldCount__Fv_194E48();
}

void updateHudSound__8HudSoundP7Vehicle(void) {
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00194E80);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00194EF8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", playOutOfReticleCountdownBeep__8HudSoundP7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", playLowHealthBeepSound__8HudSoundP7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00195010);

#include "m2c_macros.h"
M2C_UNK func_001A6620_dSound() __asm__("func_001A6620");
M2C_UNK func_001A9600_dSound() __asm__("func_001A9600");

void terminateHudSounds__8HudSound(s32 arg0) {
    func_001A6620_dSound();
    func_001A9600_dSound(arg0 + 0x1C);
}

#include "m2c_macros.h"
M2C_UNK func_001A6620_1950B8() __asm__("func_001A6620");

void func_001950B8(void) {
    func_001A6620_1950B8();
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", initFinalBossSound__14FinalBossSound);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_001950F8);

void playTankerHornSound__14FinalBossSoundP8_fvector(void) {
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", playCreakySound__14FinalBossSoundP8_fvector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_001951D0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00195230);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00195290);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_001952F0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00195390);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00195420);

#include "m2c_macros.h"
void initShieldSound__11ShieldSound(s32* arg0) {
    *arg0 = 0;
}

#include "m2c_macros.h"
M2C_UNK func_001A9600_1957E0() __asm__("func_001A9600");

void func_001957E0(void) {
    func_001A9600_1957E0();
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", updateShieldSound__11ShieldSoundP8_fvector);

#include "m2c_macros.h"
M2C_UNK func_001A6620_eSound() __asm__("func_001A6620");

void terminateAxleSmashing__12VehicleSound(s32 arg0) {
    func_001A6620_eSound(arg0 + 0xBC);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", updateAxleSmashing__12VehicleSoundiii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", updatePrisonFence__12VehicleSoundiii);

#include "m2c_macros.h"
M2C_UNK func_001A6620_195B48() __asm__("func_001A6620");

void func_00195B48(s32 arg0) {
    func_001A6620_195B48(arg0 + 0xE0);
}

#include "m2c_macros.h"
void initFerrisWheelSound__16FerrisWheelSound(s32* arg0) {
    *arg0 = 0;
}

#include "m2c_macros.h"
M2C_UNK func_001A9600_195B70() __asm__("func_001A9600");

void func_00195B70(void) {
    func_001A9600_195B70();
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00195B90);

#include "m2c_macros.h"
void initOceanSound__10OceanSound(s32* arg0) {
    *arg0 = 0;
}

#include "m2c_macros.h"
M2C_UNK func_001A9600_195C70() __asm__("func_001A9600");

void func_00195C70(void) {
    func_001A9600_195C70();
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00195C90);

#include "m2c_macros.h"
void initHouseSound__10HouseSound(void* arg0) {
    M2C_FIELD_V1(arg0, s32* , 4) = 0;
    M2C_FIELD_V1(arg0, s32* , 0) = 1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00195DA8);

#include "m2c_macros.h"
void initTrainSound__10TrainSound(void* arg0) {
    M2C_FIELD_V1(arg0, s32* , 4) = 0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00195F48);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", initBuildingFallingSound__20BuildingFallingSound);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_001961A8);

#include "m2c_macros.h"
void startBuildingFallingSound__20BuildingFallingSoundi(void* arg0, s32 arg1) {
    if (arg1 == 0) {
        M2C_FIELD_V1(arg0, s32* , 0x10) = 1;
        return;
    }
    M2C_FIELD_V1(arg0, s32* , 0x14) = 1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00196328);

#include "m2c_macros.h"
void initWreckingBallSound__17WreckingBallSound(s32* arg0) {
    *arg0 = 0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00196648);

#include "m2c_macros.h"
void initDeath4Sound__11Death4Sound(s32* arg0) {
    *arg0 = 0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_001967C0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00196948);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00196990);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", updateCloudSound__10CloudSound);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", triggerCloudEnvironmentWeaponSound__10CloudSound);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", initCraneSound__10CraneSound);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00196F10);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", initRainSound__9RainSound);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", updateRainSound__9RainSoundi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", initShipLevelSound__14ShipLevelSound);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00197DB0);

#include "m2c_macros.h"
void initAsylumLevelSound__16AsylumLevelSound(s32* arg0) {
    *arg0 = 0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00198058);

#include "m2c_macros.h"
void initLoopLevelSound__14LoopLevelSound(s32* arg0) {
    *arg0 = 0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00198188);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00198218);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", initPrisonLevelSound__16PrisonLevelSound);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00198360);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00198750);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00198880);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00198D20);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", updateBlimpWeaponState__16PrisonLevelSoundii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00198FD8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", startSecretDoorSound__16PrisonLevelSound);

void setACUnitDestroyed__16PrisonLevelSoundi(void) {
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00199798);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_001997D0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", setPhoneDestroyed__10PhoneSoundi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_001998D8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", setACUnitDestroyed__19RooftopACUnitsSoundi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00199BD8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_00199C08);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", initWindSound__9WindSound);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", updateWindSound__9WindSound);

#include "m2c_macros.h"
s32 mathfRand__Fii_nSound() __asm__("mathfRand__Fii");
s32 timerGetFieldCount__Fv_nSound() __asm__("timerGetFieldCount__Fv");

void initPizzaManSound__13PizzaManSound(void* arg0) {
    s32 temp_v0;

    M2C_FIELD_V1(arg0, s32* , 0) = 0;
    M2C_FIELD_V1(arg0, s32* , 4) = 0;
    M2C_FIELD_V1(arg0, s32* , 8) = 0;
    M2C_FIELD_V1(arg0, s32* , 0xC) = timerGetFieldCount__Fv_nSound();
    temp_v0 = mathfRand__Fii_nSound(5, 0xA);
    M2C_FIELD_V1(arg0, s32* , 0x14) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x10) = temp_v0;
    M2C_FIELD_V1(arg0, s32* , 0x18) = timerGetFieldCount__Fv_nSound();
    M2C_FIELD_V1(arg0, s32* , 0x1C) = 0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", setPizzaManDead__13PizzaManSound);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", updatePizzaManSound__13PizzaManSound);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", initSmasherSound__12SmasherSound);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019B048);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019B1A0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019B460);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", initJetSound__8JetSound);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", terminateJetSound__8JetSoundP8_fvector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019B5F8);

#include "m2c_macros.h"
void initHelicopterSound__15HelicopterSound(s32* arg0) {
    *arg0 = 0;
}

#include "m2c_macros.h"
M2C_UNK func_001A9600_rSound() __asm__("func_001A9600");

void terminateHelicopterSound__15HelicopterSound(void) {
    func_001A9600_rSound();
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019BB80);

#include "m2c_macros.h"
void initBlimpSound__10BlimpSound(s32* arg0) {
    *arg0 = 0;
}

#include "m2c_macros.h"
M2C_UNK func_001A9600_19C2B8() __asm__("func_001A9600");

void func_0019C2B8(void) {
    func_001A9600_19C2B8();
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019C2D8);

#include "m2c_macros.h"
void initTransformerSound__16TransformerSound(s32* arg0) {
    *arg0 = 0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019C500);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", initFireSound__9FireSoundfffii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", updateFireSound__9FireSound);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019C758);

#include "m2c_macros.h"
s32 timerGetFieldCount__Fv_19C7A0() __asm__("timerGetFieldCount__Fv");

void func_0019C7A0(void* arg0) {
    M2C_FIELD_V1(arg0, s32* , 0xC) = 1;
    M2C_FIELD_V1(arg0, s32* , 0x10) = timerGetFieldCount__Fv_19C7A0();
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", updateTimedFireSound__14TimedFireSound);

#include "m2c_macros.h"
s32 __10ShellSound(s32 arg0) {
    return arg0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019C8F8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019C920);

#include "m2c_macros.h"
M2C_UNK func_0019CA78_19C978() __asm__("func_0019CA78");

void func_0019C978(void) {
    func_0019CA78_19C978();
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019C998);

#include "m2c_macros.h"
M2C_UNK func_0019CA78_19CA18() __asm__("func_0019CA78");
M2C_UNK snd_SetReverbDepth_19CA18() __asm__("snd_SetReverbDepth");
M2C_UNK soundStopSound__FPUi_19CA18() __asm__("soundStopSound__FPUi");

void func_0019CA18(void* arg0) {
    s32 temp_v1;

    M2C_FIELD_V1(arg0, s32* , 0x1C) = 0;
    temp_v1 = M2C_FIELD_V1(arg0, s32* , 0x10);
    M2C_FIELD_V1(arg0, s32* , 0x20) = 0;
    if ((temp_v1 != 0) && (temp_v1 != 0xFFFFFFFF)) {
        snd_SetReverbDepth_19CA18(3, 0, 0);
        soundStopSound__FPUi_19CA18(arg0 + 0x10);
    }
    func_0019CA78_19CA18(arg0);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019CA78);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", playShellSFXSound__10ShellSoundi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", playRTShellSound__Fi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019CB60);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019CBC0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019CC20);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", playShellCarsEngineSound__10ShellSoundi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019D110);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019D140);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019D380);

#include "m2c_macros.h"
void initFlameSound__10FlameSound(s32* arg0) {
    *arg0 = 0;
}

#include "m2c_macros.h"
M2C_UNK func_001A9600_19D450() __asm__("func_001A9600");

void func_0019D450(void) {
    func_001A9600_19D450();
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", updateFlameSound__10FlameSoundP8_fvector);

#include "m2c_macros.h"
void initAmbientTrafficSound__19AmbientTrafficSound(s32* arg0) {
    *arg0 = 0;
}

#include "m2c_macros.h"
M2C_UNK func_001A9600_19D548() __asm__("func_001A9600");

void func_0019D548(void) {
    func_001A9600_19D548();
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019D568);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019D638);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019D668);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019D6B0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019D8E8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019D918);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019D960);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", initCarRevealSound__14CarRevealSoundfff);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019DAC0);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", D_004EAF70);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", D_004EAFF0);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", D_004EB050);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019DEC8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019E7C0);

#include "m2c_macros.h"
s32 timerGetFieldCount__Fv_uncher() __asm__("timerGetFieldCount__Fv");

void initLauncherSound__13LauncherSoundP8Launcher(void* arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_v0_2;

    M2C_FIELD_V1(arg0, s32* , 0x14) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x170) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x18) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x1C) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x20) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x188) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x158) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x68) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x80) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x98) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x38) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x214) = arg1;
    M2C_FIELD_V1(arg0, s32* , 0) = timerGetFieldCount__Fv_uncher();
    temp_v0 = timerGetFieldCount__Fv_uncher();
    M2C_FIELD_V1(arg0, s32* , 0x1A0) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x1B8) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x1D0) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x1E8) = 0;
    M2C_FIELD_V1(arg0, s32* , 0xB0) = 0;
    M2C_FIELD_V1(arg0, s32* , 0xC8) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x50) = 0;
    M2C_FIELD_V1(arg0, s32* , 0xE0) = 0;
    M2C_FIELD_V1(arg0, s32* , 0xC) = 0;
    M2C_FIELD_V1(arg0, s32* , 4) = temp_v0;
    temp_v0_2 = timerGetFieldCount__Fv_uncher();
    M2C_FIELD_V1(arg0, s32* , 0x10) = 0;
    M2C_FIELD_V1(arg0, s32* , 0xF8) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x110) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x128) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x140) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x210) = temp_v0_2;
    M2C_FIELD_V1(arg0, s32* , 0x204) = timerGetFieldCount__Fv_uncher();
    M2C_FIELD_V1(arg0, s32* , 0x208) = timerGetFieldCount__Fv_uncher();
    M2C_FIELD_V1(arg0, s32* , 0x20C) = timerGetFieldCount__Fv_uncher();
}

#include "m2c_macros.h"
M2C_UNK func_001A6620_19EB90() __asm__("func_001A6620");
M2C_UNK func_001A9600_19EB90() __asm__("func_001A9600");

void func_0019EB90(s32 arg0) {
    func_001A9600_19EB90(arg0 + 0x14);
    func_001A9600_19EB90(arg0 + 0x18);
    func_001A9600_19EB90(arg0 + 0x1C);
    func_001A6620_19EB90(arg0 + 0xB0);
    func_001A6620_19EB90(arg0 + 0xC8);
    func_001A6620_19EB90(arg0 + 0x50);
    func_001A6620_19EB90(arg0 + 0x20);
    func_001A6620_19EB90(arg0 + 0x38);
    func_001A6620_19EB90(arg0 + 0x1A0);
    func_001A6620_19EB90(arg0 + 0x1B8);
    func_001A6620_19EB90(arg0 + 0x1D0);
    func_001A6620_19EB90(arg0 + 0x1E8);
    func_001A6620_19EB90(arg0 + 0x170);
    func_001A6620_19EB90(arg0 + 0x188);
    func_001A6620_19EB90(arg0 + 0x68);
    func_001A6620_19EB90(arg0 + 0x80);
    func_001A6620_19EB90(arg0 + 0x98);
    func_001A6620_19EB90(arg0 + 0xE0);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019EC40);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019ED00);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", func_0019EEB8);

#include "m2c_macros.h"
M2C_UNK func_001A6620_rSound() __asm__("func_001A6620");

void stopLaserSound__13LauncherSound(s32 arg0) {
    func_001A6620_rSound(arg0 + 0x170);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound", updateAxleSpecial__13LauncherSoundP7Vehicle);
