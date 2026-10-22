#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiInit__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiSetToStartPoint__7Vehicleb);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiInitDynamics__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiInitWeaponPreferences__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiSetAggressiveness__7Vehiclei);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiInitWeapons__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiGoodWeaponToPick__7Vehiclei);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiGoodRearWeaponToPick__7Vehiclei);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiUpdateInputs__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiUpdateFrozenInput__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiTurn__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiTurnCorner__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiInitTurnAndShoot__7Vehicleii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiTurnAndShoot__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiMoveBetweenPoints__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiUpdateControlPadForTwoStageAttack__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiDriveToAttackRange__7Vehicle);

extern u8 D_004F70F0_68_35[4] __asm__("D_004F70F0");

s32 aiNeedToSlowDown__7VehiclefPf(void* arg0, f32* arg1, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f4;
    s32 var_v1;

    var_v1 = 0;
    temp_f1 = M2C_FIELD(arg0, f32* , 0x2C4);
    temp_f4 = M2C_FIELD(M2C_FIELD(arg0, void** , 0x2008), f32* , 0x1A8);
    temp_f0 = ((temp_f1 - temp_f4) / (M2C_FIELD(arg0, f32* , 0x328) * M2C_FIELD(arg0, f32* , 0x564) * (*(f32*)D_004F70F0_68_35))) * ((temp_f1 + temp_f4) * 0.5f);
    *arg1 = temp_f0;
    if ((fparg0 - 3.0f) < temp_f0) {
        var_v1 = 1;
    }
    return var_v1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiCheckSpeed__7Vehiclef);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiPerform__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiPerformTStop__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiPerformBeadOnHuntCs__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiOkToHuntUsingLOS__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiHuntUsingLOS__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiPerformAmbush__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiPerformSnipe__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiLineDrive__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiCheckForPickup__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiNeedThisPickup__7VehicleP3_cs);

s32 aiGoingTooFast__7Vehicle(void* arg0) {
    return 0;
}

s32 aiLockingOnHuntCs__7Vehicle(void* arg0) {
    return 0;
}

void aiLoseBeads__7Vehicle(void* arg0) {
    void* temp_v1;

    temp_v1 = M2C_FIELD(arg0, void** , 0x2004);
    M2C_FIELD(temp_v1, s32* , 0x5A8) = 0;
    if (M2C_FIELD(temp_v1, s32* , 0x5B0) != 0) {
        M2C_FIELD(M2C_FIELD(arg0, void** , 0x2008), s32* , 0x258) = 0;
        M2C_FIELD(temp_v1, s32* , 0x5B0) = 0;
    }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiUpdateCarToPlayerInfo__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiToPlayerLOSCheck__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiUpdateDrivingMode__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiUpdateAttack__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiPickBestWeaponToFireNow__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiIsGoodWeaponChoice__7Vehiclei);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiGetWeapRangeInfo__7VehicleiPfT2T2T2);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiPickWeapon__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiPickForwardWeapon__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiPickRearWeapon__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiPickBestHomingWeapon__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiOkToUseWeaponForRearFiring__7Vehiclei);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiToggleToWeapon__7Vehicle);

extern u8 game_68_106[4] __asm__("game");

s32 aiUsingNonLOSWeapon__7Vehicle(void* arg0) {
    s32 temp_v1;
    s32 var_a2;
    void* temp_a1;

    temp_a1 = M2C_FIELD(arg0, void** , 0x2004);
    var_a2 = 0;
    if ((M2C_FIELD(temp_a1, s32* , 0x47C) == 5) && (M2C_FIELD(arg0, s32* , 0x224C) == 0xC) && ((temp_v1 = M2C_FIELD((*(void**)game_68_106), s32* , 0x1B3DB0), var_a2 = 1, (temp_v1 == 4)) || (temp_v1 == 8)) && (M2C_FIELD(temp_a1, f32* , 0x18) < M2C_FIELD(temp_a1, f32* , 0x20))) {
        var_a2 = 0;
    }
    return var_a2;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiDelayAfterTogglingToWeapon__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiGetInWeaponRange__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiGetLineOfSight__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiLineUpShot__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiCheckForGoodShot__7Vehicleff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiCheckForGoodRearShot__7Vehicleff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiIsPlayerLookingAtAIEnoughForAIToShoot__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiFireWeapon__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiFireRearWeapon__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiDelayAfterFireWeapon__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiCheckMachineGuns__7Vehicle);

void aiSetAttackState__7Vehicle12_attackState(void* arg0, s32 arg1) {
    void* temp_v1;

    temp_v1 = M2C_FIELD(arg0, void** , 0x2004);
    if (M2C_FIELD(temp_v1, s32* , 0x414) != arg1) {
        M2C_FIELD(temp_v1, s32* , 0x414) = arg1;
        M2C_FIELD(temp_v1, s32* , 0x488) = 0;
    }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiUpdateBaitMode__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiUpdateBaitModeOld__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiUpdateFleeMode__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiUpdateSnipeMode__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiUpdateCruiseMode__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiStartTurnToNewCruisePoint__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiUpdateHuntMode__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiCheckForBeadOnHuntCs__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiUpdatePickupGameMode__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiSeekPointAndStop__7Vehicle);

void gamePickCruiseZone__7TheGameP7Vehiclei_50_167(void*, void*, int) __asm__("gamePickCruiseZone__7TheGameP7Vehiclei");
extern u8 game_50_167[4] __asm__("game");

s32 aiGetFleeSpot__7Vehiclei(void* arg0, s32 arg1) {
    s32 temp_v0;
    void* temp_a1;

    gamePickCruiseZone__7TheGameP7Vehiclei_50_167((*(void**)game_50_167), arg0, arg1);
    temp_a1 = M2C_FIELD(arg0, void** , 0x2008);
    temp_v0 = M2C_FIELD(temp_a1, s32* , 0x20C) << 5;
    M2C_FIELD(temp_a1, s32* , 0x210) = (s32) M2C_FIELD((*M2C_FIELD(temp_a1, s32** , 0xB8) + temp_v0), s8* , 0x1D);
    return temp_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiInWeaponRange__7Vehiclei);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiCheckGasCanDetonation__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiCheckTowTruckDetonation__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiCheckShadowDetonation__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiCheckSkillAttack__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", aiCheckSpecialWeaponFiring__7Vehicle);

void aiGetBestPointToBeDrivingNow__7Vehicle(void) {
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ai", TogglePOV__7TheGamei);
