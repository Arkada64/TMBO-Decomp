#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/prison", prisonInitBefore__6Prison);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/prison", InitForReplay__6Prison);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/prison", prisonInitAfter__6Prison);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/prison", prisonAddNode__6PrisoniP9_hierhead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/prison", prisonUpdateBowWaves__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/prison", prisonUpdate__6Prison);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/prison", prisonUpdateInnerDoorsClosed__6Prison);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/prison", prisonUpdateDrawBridgeClosed__6Prison);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/prison", prisonUpdateIslandTrans__6Prison);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/prison", prisonUpdateDrawBridgeOpen__6Prison);

s32 animationIsRunning__FR11_animHandle_3C_34(void*) __asm__("animationIsRunning__FR11_animHandle");
void updateSideGates__16PrisonLevelSound_3C_34(void*) __asm__("updateSideGates__16PrisonLevelSound");

void prisonUpdateGatesOpenBridgeUp__6Prison(s32 arg0) {
    if (animationIsRunning__FR11_animHandle_3C_34(arg0 + 0x2C) != 0) {
        updateSideGates__16PrisonLevelSound_3C_34(arg0 + 0x11C);
    }
}

s32 animationIsRunning__FR11_animHandle_EC_37(void*) __asm__("animationIsRunning__FR11_animHandle");
void animationPause__FR11_animHandle_EC_37(void*) __asm__("animationPause__FR11_animHandle");
void animationStart__FR11_animHandleb_EC_37(void*, unsigned char) __asm__("animationStart__FR11_animHandleb");
void prisonUpdateTransitionPoints__6Prison_EC_37(void*) __asm__("prisonUpdateTransitionPoints__6Prison");

void prisonUpdateGatesOpenBridgeMovingDown__6Prison(void* arg0) {
    void* temp_s1;
    void* temp_s1_2;

    if ((M2C_FIELD(arg0, s32* , 0x20) != 0) && (animationIsRunning__FR11_animHandle_EC_37(arg0 + 0x20) == 0)) {
        if (M2C_FIELD(arg0, s32* , 0x50) != 0) {
            temp_s1 = arg0 + 0x50;
            if (animationIsRunning__FR11_animHandle_EC_37(temp_s1) != 0) {
                animationPause__FR11_animHandle_EC_37(temp_s1);
            }
        }
        if (M2C_FIELD(arg0, s32* , 0x5C) != 0) {
            temp_s1_2 = arg0 + 0x5C;
            if (animationIsRunning__FR11_animHandle_EC_37(temp_s1_2) != 0) {
                animationPause__FR11_animHandle_EC_37(temp_s1_2);
            }
        }
        if (M2C_FIELD(arg0, s32* , 0x68) != 0) {
            animationStart__FR11_animHandleb_EC_37(arg0 + 0x68, 1);
        }
        if (M2C_FIELD(arg0, s32* , 0x74) != 0) {
            animationStart__FR11_animHandleb_EC_37(arg0 + 0x74, 1);
        }
        if (M2C_FIELD(arg0, s32* , 0xC8) != 0) {
            animationStart__FR11_animHandleb_EC_37(arg0 + 0xC8, 1);
        }
        M2C_FIELD(arg0, s32* , 0xF8) = 5;
        prisonUpdateTransitionPoints__6Prison_EC_37(arg0);
    }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/prison", prisonUpdateGatesOpenBridgeDown__6Prison);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/prison", prisonUpdateTransitionPoints__6Prison);

void animationStart__FR11_animHandleb_80_48(void*, unsigned char) __asm__("animationStart__FR11_animHandleb");
void animationStartReverse__FR11_animHandleb_80_48(void*, unsigned char) __asm__("animationStartReverse__FR11_animHandleb");
s32 prisonGuardTowerDestroyed__6Prison(void* arg0) {
    s32 var_v0;

    var_v0 = M2C_FIELD(arg0, s32* , 0x68);
    if (var_v0 != 0) {
        var_v0 = M2C_FIELD(arg0, s32* , 0xF8) < 4;
        if (var_v0 != 0) {
            if (M2C_FIELD(arg0, s32* , 0x20) != 0) {
                animationStartReverse__FR11_animHandleb_80_48(arg0 + 0x20, 1U);
            }
            if (M2C_FIELD(arg0, s32* , 0x50) != 0) {
                animationStart__FR11_animHandleb_80_48(arg0 + 0x50, 1U);
            }
            if (M2C_FIELD(arg0, s32* , 0x5C) != 0) {
                animationStart__FR11_animHandleb_80_48(arg0 + 0x5C, 1U);
            }
            var_v0 = 4;
            M2C_FIELD(arg0, s32* , 0xF8) = 4;
        }
    }
    return var_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/prison", prisonTriggerCraneDestruct__6Prisonb);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/prison", prisonUpdateCraneDestruct__6Prison);

s32 startShocking__17ElectrocutionPeds(void* arg0) {
    s32 temp_v1;
    s32 var_v0;

    temp_v1 = M2C_FIELD(arg0, s32* , 0xC);
    var_v0 = 3;
    if ((temp_v1 == 0) || (temp_v1 == 3)) {
        var_v0 = 0x262;
        M2C_FIELD(arg0, s32* , 0x14) = 0x262;
    }
    return var_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/prison", update__17ElectrocutionPeds);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/prison", initAfter__17ElectrocutionPeds);

void plightDestroy__FP11_pointlight_1C_72(void*) __asm__("plightDestroy__FP11_pointlight");
void cleanup__17ElectrocutionPeds(void* arg0) {
    void* temp_a0;

    temp_a0 = M2C_FIELD(arg0, void** , 0x10);
    if (temp_a0 != NULL) {
        plightDestroy__FP11_pointlight_1C_72(temp_a0);
    }
}

void startUnlock__9CarUnlock_C_76(void*) __asm__("startUnlock__9CarUnlock");
extern u8 s_prisonCarUnlock_C_76[] __asm__("s_prisonCarUnlock");

void unlockCar__6Prison(void) {
    startUnlock__9CarUnlock_C_76(((u8*)s_prisonCarUnlock_C_76));
}

void cleanup__17ElectrocutionPeds_24_79(void*) __asm__("cleanup__17ElectrocutionPeds");
void cleanup__9CarUnlock_24_79(void*) __asm__("cleanup__9CarUnlock");
extern u8 s_prisonCarUnlock_24_79[] __asm__("s_prisonCarUnlock");

void cleanupOnShutdown__6Prison(s32 arg0) {
    cleanup__17ElectrocutionPeds_24_79(arg0 + 0xD4);
    cleanup__9CarUnlock_24_79(((u8*)s_prisonCarUnlock_24_79));
}
