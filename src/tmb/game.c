#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", Init__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", InitBeforeDbLoad__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", InitTypeOfVehicles__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", InitAfterDbLoad__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", InitForReplay__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", CleanUpVehicles__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", Update__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", gameInitFirstFrame__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", GameAdjustLevelKlod__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", UpdateShadow__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", VehicleParse__7TheGameP9_hierhead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", AddVehicle__7TheGameP3_csii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", GetVehicleFromName__7TheGameii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", GetBestAIToBait__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", GetNumAIInBaitMode__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", FodderParse__7TheGameP9_hierhead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", AddFodder__7TheGameP3_csii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", SetPlayerCar__7TheGameiiii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", SetAICar__7TheGameiii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", InitializeFodderCars__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", SetFodderCar__7TheGameiib);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", gameInitCamera__7TheGameii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", ToggleAITheCameraFollows__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", GetCameraMaxHeight__7TheGameP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", gameCheckNumFodder__7TheGame);

void SetCameraOffsets__7TheGamei_2C_84(void*, int) __asm__("SetCameraOffsets__7TheGamei");
extern u8 cameraAddHeight_2C_84[4] __asm__("cameraAddHeight");
extern u8 cameraToTweak_2C_84[4] __asm__("cameraToTweak");
extern u8 game_2C_84[4] __asm__("game");
extern u8 oldCameraAddHeight_2C_84[4] __asm__("oldCameraAddHeight");

void gameCameraOffsetCallback__FPv(void) {
    SetCameraOffsets__7TheGamei_2C_84((*(s32*)game_2C_84), (*(s32*)cameraToTweak_2C_84));
    (*(s32*)oldCameraAddHeight_2C_84) = (*(s32*)cameraAddHeight_2C_84);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", SetCameraOffsets__7TheGamei);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", gameInitAIToCruiseZones__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", gamePickCruiseZone__7TheGameP7Vehiclei);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", gameInitCruiseZones__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", gameTakeCruiseZone__7TheGameP7Vehiclei);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", gameClearCruiseZone__7TheGameP7Vehiclei);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", gameCheckCruiseZones__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", gameUpdateAIFlags__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", gameGetAiToHuntPlayer__7TheGamei);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", gameCheckNewAIToHuntPlayer__7TheGamei);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", gameCheckNewAIToBaitPlayer__7TheGamei);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", gameCheckPlayerHealth__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", gameUpdateFodderFlags__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", gameResolveCollisions__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", gameCheckTriggerTree__7TheGame);

M2C_UNK memset_3C_150() __asm__("memset");

s32 InitTakeHitInfo__7TheGame(void* arg0) {
    void* temp_s0;

    temp_s0 = arg0 + 0x150560;
    memset_3C_150(temp_s0, 0, 0x1C);
    return (s32) temp_s0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", IsInteractiveAVehicle__7TheGameiPi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", SetGravity__7TheGamef);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", RegisterFodderLock__7TheGameP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", gameGetStartPoint__7TheGameP7Vehiclei);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", gameCheckStartPoint__7TheGamePib);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", gameCheckStartPointDistFromVehicles__7TheGameP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", gameAttractModeInit__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", gameAttractModeUpdate__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", gameOpenCityCorridor__7TheGamei);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", gameOpenAsylum__7TheGamei);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", gameSpawnBurningMan__7TheGameP7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", spawnBurningPed__7TheGameP7VehicleP8_fvector);

int Update__7BurnMan_54_195(void*) __asm__("Update__7BurnMan");
s32 gameUpdateBurningMan__7TheGame(void* arg0) {
    s32 var_s1;
    s32 var_v0;
    s32* var_s0;

    var_s1 = 2;
    var_s0 = arg0 + 0x1AACE0;
    do {
        var_v0 = *var_s0;
        if (var_v0 != 0) {
            var_v0 = Update__7BurnMan_54_195(var_s0);
        }
        var_s1 -= 1;
        var_s0 +=0x14;
    } while (var_s1 >= 0);
    return var_v0;
}

int Terminate__7BurnMan_54_201(void*) __asm__("Terminate__7BurnMan");
s32 gameTerminateAllBurningMen__7TheGame(void* arg0) {
    s32 var_s1;
    s32 var_v0;
    s32* var_s0;

    var_s1 = 2;
    var_s0 = arg0 + 0x1AACE0;
    do {
        var_v0 = *var_s0;
        if (var_v0 != 0) {
            var_v0 = Terminate__7BurnMan_54_201(var_s0);
        }
        var_s1 -= 1;
        var_s0 +=0x14;
    } while (var_s1 >= 0);
    return var_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", SavePlayerState__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", SavePlayerCodes__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", RestorePlayerState__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", RestorePlayerCodes__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", traversalCallback__7TheGameP3_csP11_hierobjectPA3_fP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", gameSniperPointsInit__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", gameGetNewSniperPoint__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", gameReestablishViews__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", CleanUpForEndurance__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", CleanUpForLastMan__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", GetNumAIsHunting__7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", _GLOBAL_$I$resetObj);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", CityUpdate__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", func_001359B8);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/game", func_001359D8);
