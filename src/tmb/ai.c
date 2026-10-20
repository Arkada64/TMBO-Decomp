#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiInit__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_001002C0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_001003C0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_00100E88);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiSetAggressiveness__7Vehiclei);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_00101DF0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiGoodWeaponToPick__7Vehiclei);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiGoodRearWeaponToPick__7Vehiclei);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_00101F88);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_00102360);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiTurn__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiTurnCorner__7Vehicle);

#include "m2c_macros.h"
void aiInitTurnAndShoot__7Vehicleii(void* arg0, s32 arg1, s32 arg2) {
    if (M2C_FIELD(M2C_FIELD(arg0, void** , 0x2018), f32* , 0x1A0) == 0.0f) {
        M2C_FIELD(M2C_FIELD(arg0, void** , 0x2014), s32* , 0x5CC) = 1;
        M2C_FIELD(M2C_FIELD(arg0, void** , 0x2014), s32* , 0x5D0) = 0;
        M2C_FIELD(M2C_FIELD(arg0, void** , 0x2014), s32* , 0x444) = arg1;
        M2C_FIELD(M2C_FIELD(arg0, void** , 0x2014), s32* , 0x448) = arg2;
        M2C_FIELD(M2C_FIELD(arg0, void** , 0x2014), s32* , 0x458) = 0;
        M2C_FIELD(M2C_FIELD(arg0, void** , 0x2018), s32* , 0x250) = 0;
        M2C_FIELD(M2C_FIELD(arg0, void** , 0x2018), s32* , 0x254) = 0;
        M2C_FIELD(M2C_FIELD(arg0, void** , 0x2018), s32* , 0x258) = 1;
    }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_00102948);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_00102D78);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_00103888);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiDriveToAttackRange__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiNeedToSlowDown__7VehiclefPf);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiCheckSpeed__7Vehiclef);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiPerform__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_00103F20);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiPerformBeadOnHuntCs__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiOkToHuntUsingLOS__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiHuntUsingLOS__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_00104760);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_00104848);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_001048D0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiCheckForPickup__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_00104DF8);

#include "m2c_macros.h"
s32 aiGoingTooFast__7Vehicle(void) {
    return 0;
}

#include "m2c_macros.h"
s32 aiLockingOnHuntCs__7Vehicle(void) {
    return 0;
}

#include "m2c_macros.h"
void aiLoseBeads__7Vehicle(void* arg0) {
    M2C_FIELD_V1(M2C_FIELD_V1(arg0, void** , 0x2014), s32* , 0x5A8) = 0;
    if (M2C_FIELD_V1(M2C_FIELD_V1(arg0, void** , 0x2014), s32* , 0x5B0) != 0) {
        M2C_FIELD_V1(M2C_FIELD_V1(arg0, void** , 0x2018), s32* , 0x258) = 0;
        M2C_FIELD_V1(M2C_FIELD_V1(arg0, void** , 0x2014), s32* , 0x5B0) = 0;
    }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_00104FA0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiToPlayerLOSCheck__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_001054E8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiUpdateAttack__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiPickBestWeaponToFireNow__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiIsGoodWeaponChoice__7Vehiclei);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiGetWeapRangeInfo__7VehicleiPfT2T2T2);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_00106370);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_00106440);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_001065A0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_00106778);

#include "m2c_macros.h"
s32 aiOkToUseWeaponForRearFiring__7Vehiclei(void* arg0, s32 arg1) {
    s32 var_a1;

    var_a1 = 0;
    switch (arg1) {
    case 2:
    case 3:
    case 4:
    case 6:
    case 7:
        var_a1 = 1;
        break;
    case 1:
        var_a1 = M2C_FIELD_V1(M2C_FIELD_V1(arg0, void** , 0x2014), s32* , 0x610);
        break;
    }
    return var_a1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_00106888);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiUsingNonLOSWeapon__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_00106A00);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_00106A60);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_00106AC8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiLineUpShot__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_00106D50);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_00107048);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiIsPlayerLookingAtAIEnoughForAIToShoot__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_00107380);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_00107580);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_001076E8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_00107920);

#include "m2c_macros.h"
void aiSetAttackState__7Vehicle12_attackState(void* arg0, s32 arg1) {
    void* temp_v1;

    temp_v1 = M2C_FIELD_V1(arg0, void** , 0x2014);
    if (M2C_FIELD_V1(temp_v1, s32* , 0x414) != arg1) {
        M2C_FIELD_V1(temp_v1, s32* , 0x414) = arg1;
        M2C_FIELD_V1(M2C_FIELD_V1(arg0, void** , 0x2014), s32* , 0x488) = 0;
    }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiUpdateBaitMode__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiUpdateBaitModeOld__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiUpdateFleeMode__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiUpdateSnipeMode__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_001082C8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiStartTurnToNewCruisePoint__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_00108618);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiCheckForBeadOnHuntCs__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiUpdatePickupGameMode__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiSeekPointAndStop__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiGetFleeSpot__7Vehiclei);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiInWeaponRange__7Vehiclei);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_00108DD0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", func_00108FD8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiCheckShadowDetonation__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiCheckSkillAttack__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/ai", aiCheckSpecialWeaponFiring__7Vehicle);

void aiGetBestPointToBeDrivingNow__7Vehicle(void) {
}
