#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/junkyard", JunkyardAddToSkyList__FP9_hierhead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/junkyard", JunkyardInitBefore__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/junkyard", JunkyardInit__FP9_hierheadP8_fvector);

int particlePrecipitationCreate__Fb_20_6(unsigned char) __asm__("particlePrecipitationCreate__Fb");
extern u8 rainfallTimer_20_6[4] __asm__("rainfallTimer");

s32 JunkyardInitAfter__Fv(void) {
    s32 temp_v0;

    temp_v0 = particlePrecipitationCreate__Fb_20_6(1U);
    (*(s32*)rainfallTimer_20_6) = 0;
    return temp_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/junkyard", JunkyardAnimateRainfall__Fi);

extern u8 tunnelDoor_24_16[] __asm__("tunnelDoor");

void JunkyardTunnelDoorTrigger__Fi(s32 arg0) {
    if (arg0 != 0) {
        M2C_FIELD(((u8*)tunnelDoor_24_16), s16* , 0x1C) = 1;
        return;
    }
    M2C_FIELD(((u8*)tunnelDoor_24_16), s16* , 0x1E) = 1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/junkyard", JunkyardTunnelDoorUpdate__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/junkyard", JunkyardPizzaBoyUpdate__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/junkyard", CheckCarsInPizzaHat__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/junkyard", junkyardAddPointsAfterJetCrash__Fv);

void update__9CarUnlock_C_31(void*) __asm__("update__9CarUnlock");
extern u8 s_junkCarUnlock_C_31[] __asm__("s_junkCarUnlock");

void JunkyardUpdate__Fv(void) {
    update__9CarUnlock_C_31(((u8*)s_junkCarUnlock_C_31));
}

void startUnlock__9CarUnlock_C_34(void*) __asm__("startUnlock__9CarUnlock");
extern u8 s_junkCarUnlock_C_34[] __asm__("s_junkCarUnlock");

void junkyardUnlockCar__Fv(void) {
    startUnlock__9CarUnlock_C_34(((u8*)s_junkCarUnlock_C_34));
}

void cleanup__9CarUnlock_C_37(void*) __asm__("cleanup__9CarUnlock");
extern u8 s_junkCarUnlock_C_37[] __asm__("s_junkCarUnlock");

void junkyardCleanupOnShutdown__Fv(void) {
    cleanup__9CarUnlock_C_37(((u8*)s_junkCarUnlock_C_37));
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/junkyard", func_00144FE0);
