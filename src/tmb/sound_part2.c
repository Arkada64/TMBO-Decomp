#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", triggerSweettoothFoldingOutSound__13LauncherSoundP7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_0019F138);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", triggerSweettoothFoldingInOuttaAmmoSound__13LauncherSoundP7Vehicle);

#include "m2c_macros.h"
M2C_UNK func_001A6620_19F208() __asm__("func_001A6620");

void func_0019F208(s32 arg0) {
    func_001A6620_19F208(arg0 + 0x68);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_0019F228);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_0019F2D8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", updateDerbySpecialSound__13LauncherSoundP7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_0019F558);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_0019F5D8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_0019FAD0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_0019FB28);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_0019FB70);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_0019FBB8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_0019FBE8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_0019FC18);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_0019FC48);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_0019FCA8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_0019FD98);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", updateMinionTorchSound__13LauncherSoundP7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", updateTankerTorchSound__13LauncherSoundP7Vehicle);

#include "m2c_macros.h"
M2C_UNK func_001A6620_rSound() __asm__("func_001A6620");

void terminateMinionTorchSound__13LauncherSound(s32 arg0) {
    func_001A6620_rSound(arg0 + 0xB0);
}

#include "m2c_macros.h"
M2C_UNK func_001A6620_rSound() __asm__("func_001A6620");

void terminateTankerTorchSound__13LauncherSound(s32 arg0) {
    func_001A6620_rSound(arg0 + 0xC8);
}

#include "m2c_macros.h"
M2C_UNK func_001A6620_19FFF8() __asm__("func_001A6620");

void func_0019FFF8(s32 arg0) {
    func_001A6620_19FFF8(arg0 + 0x50);
}

#include "m2c_macros.h"
M2C_UNK func_001A6620_rSound() __asm__("func_001A6620");

void terminateChargerSpecialChargeUpSound__13LauncherSound(s32 arg0) {
    func_001A6620_rSound(arg0 + 0x20);
    func_001A6620_rSound(arg0 + 0x38);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A0048);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", updateChargerSpecialOverchargeSound__13LauncherSoundP7Vehiclei);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A01F8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A0288);

#include "m2c_macros.h"
M2C_UNK func_001FBCF8_1A02D8() __asm__("func_001FBCF8");
s32 timerGetFieldCount__Fv_1A02D8() __asm__("timerGetFieldCount__Fv");
extern M2C_UNK D_004FFF00_1A02D8 __asm__("D_004FFF00");

void func_001A02D8(void* arg0) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;

    M2C_FIELD_V1(arg0, s32* , 0x54) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x24) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x3C) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x20) = 0;
    temp_v0 = timerGetFieldCount__Fv_1A02D8();
    M2C_FIELD_V1(arg0, s32* , 0x70) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x6C) = temp_v0;
    temp_v0_2 = timerGetFieldCount__Fv_1A02D8();
    M2C_FIELD_V1(arg0, s32* , 0x64) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x80) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x84) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x68) = temp_v0_2;
    temp_v0_3 = timerGetFieldCount__Fv_1A02D8();
    M2C_FIELD_V1(arg0, s32* , 4) = 0;
    M2C_FIELD_V1(arg0, s32* , 0) = 0;
    M2C_FIELD_V1(arg0, s32* , 8) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x78) = 0x3FFF;
    M2C_FIELD_V1(arg0, s32* , 0x7C) = temp_v0_3;
    M2C_FIELD_V1(arg0, s32* , 0x74) = timerGetFieldCount__Fv_1A02D8();
    func_001FBCF8_1A02D8(&D_004FFF00_1A02D8, 0xFDB, 0, 0);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A0368);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A0798);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A0F90);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A1020);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A10D8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A1170);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A1210);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", activateHearseMachineGunPopupSound__FP7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", playHelicopterMachineGunSound__FP8_fvector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", playGasCanDropDetonationSound__FP8_fvector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", playRooftopSparkySound__FP8_fvector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A1408);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", playWreckingBallDropDetonationSound__FP8_fvector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", playCityGasBallBounceSound__FP8_fvector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A14F8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", playTunnelDoorOpenSound__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A1730);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", playRooftopSatSound__Fi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", playTunnelDoorCloseSound__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A1940);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", initElevatorSound__13ElevatorSound);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", startElevatorSound__13ElevatorSoundii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A1B40);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", updateElevatorLoweringSound__13ElevatorSound);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A2158);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A21E8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A2278);

#include "m2c_macros.h"
void func_001A22F8(void* arg0) {
    M2C_FIELD_V1(arg0, s32* , 0) = 0;
    M2C_FIELD_V1(arg0, s32* , 4) = 0x10;
}

#include "m2c_macros.h"
void func_001A2308(void* arg0) {
    M2C_FIELD_V1(arg0, s32* , 0) = 0;
    M2C_FIELD_V1(arg0, s32* , 4) = 0x11;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A2318);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A23A0);

#include "m2c_macros.h"
M2C_UNK func_001A9600_1A2418() __asm__("func_001A9600");

void func_001A2418(void) {
    func_001A9600_1A2418();
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A2438);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A24E0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", playMachineGunExplosion__14ExplosionSoundP8_fvectoriii);

#include "m2c_macros.h"
s32 func_001A30D8_1A2960() __asm__("func_001A30D8");

void func_001A2960(void* arg0) {
    M2C_FIELD_V1(arg0, s32* , 0) = func_001A30D8_1A2960(M2C_FIELD_V1(arg0, s32* , 4));
}

#include "m2c_macros.h"
s32 func_001A30D8_1A2990() __asm__("func_001A30D8");

void func_001A2990(void* arg0) {
    M2C_FIELD_V1(arg0, s32* , 0) = func_001A30D8_1A2990(M2C_FIELD_V1(arg0, s32* , 8));
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A29C0);

#include "m2c_macros.h"
M2C_UNK snd_PlaySoundVolPanPMPB_A_1A2A38() __asm__("snd_PlaySoundVolPanPMPB_A");

void func_001A2A38(s32* arg0) {
    snd_PlaySoundVolPanPMPB_A_1A2A38(*arg0);
}

#include "m2c_macros.h"
s32 func_001A9DE8_1A2A58() __asm__("func_001A9DE8");
s32 func_001A9E00_1A2A58() __asm__("func_001A9E00");
M2C_UNK func_001F9150_1A2A58() __asm__("func_001F9150");

void func_001A2A58(s32* arg0) {
    s32 var_s1;

    var_s1 = 0;
    if ((*arg0 != 0) && (func_001A9DE8_1A2A58() == 0)) {
        var_s1 = func_001A9E00_1A2A58(arg0) == 0;
    }
    if (var_s1 != 0) {
        func_001F9150_1A2A58(*arg0);
    }
    *arg0 = 0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A2AC0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A2C00);

#include "m2c_macros.h"
M2C_UNK func_001A2A58_1A2C48() __asm__("func_001A2A58");

void func_001A2C48(s32* arg0, s32 arg1) {
    if (*arg0 == 0) {
        *arg0 = arg1;
        func_001A2A58_1A2C48();
        return;
    }
    *arg0 = arg1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A2C78);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", __12SoundManager);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A2CE0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A2FC8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A30D8);

#include "m2c_macros.h"
M2C_UNK func_001FA370_1A3168() __asm__("func_001FA370");
M2C_UNK func_001FA490_1A3168() __asm__("func_001FA490");
M2C_UNK sceCdInit_1A3168() __asm__("sceCdInit");

void func_001A3168(void* arg0) {
    if (M2C_FIELD_V1(arg0, s32* , 0x90) != 0) {
        func_001FA490_1A3168();
    }
    sceCdInit_1A3168(0);
    if (M2C_FIELD_V1(arg0, s32* , 0x90) != 0) {
        func_001FA370_1A3168(5, 0xA000, 0, 1);
    }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A31C0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A3350);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A33F8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A34F0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A3698);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A36B8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A3860);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A3CE0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A3D48);

#include "m2c_macros.h"
M2C_UNK func_001A9590_1A3E78() __asm__("func_001A9590");
M2C_UNK func_001F9720_1A3E78() __asm__("func_001F9720");

void func_001A3E78(void) {
    func_001F9720_1A3E78();
    func_001A9590_1A3E78();
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A3EA0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A3ED8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A4070);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A4168);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A41F0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A42A0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A4358);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A44A8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", setReverbDepth__19AmbientSoundManagerffii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", evaluateStreamState__19AmbientSoundManagerP14StreamingSound);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", evaluateSFXState__19AmbientSoundManagerP17SFXStreamingSound);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A47B8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", updateAmbientSound__19AmbientSoundManager);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A5550);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", func_001A5740);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", updateRhythmFadeoutState__19AmbientSoundManageri);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", D_004EB760);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", D_004EB768);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part2", jtbl_004EB780);
