#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/healthstand", healthStandInit__FP8_fvectorPA3_f);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/healthstand", healthStandSetInert__Fi);

extern u8 healthStand_24_10[] __asm__("healthStand");

void healthStandSetPrimed__Fi(s32 arg0) {
    void* temp_a0;

    temp_a0 = (arg0 * 0x70) + ((u8*)healthStand_24_10);
    M2C_FIELD(temp_a0, s32* , 0x68) = 1;
    M2C_FIELD(temp_a0, s32* , 0x64) = 0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/healthstand", healthStandSetFiring__FiP8_fvectori);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/healthstand", healthStandsUpdate__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/healthstand", init__Q212HealthStands5Stand);

void init__Q212HealthStands5Stand_54_21(void*) __asm__("init__Q212HealthStands5Stand");
extern u8 numHealthStands_54_21[4] __asm__("numHealthStands");

void InitBeforeDbLoad__12HealthStands(s32* arg0) {
    s32 var_s0;
    s32 var_s1;

    var_s1 = 4;
    var_s0 = arg0 + 0x4;
    do {
        var_s1 -= 1;
        init__Q212HealthStands5Stand_54_21(var_s0);
        var_s0 += 0x80;
    } while (var_s1 != 0);
    *arg0 = 0;
    (*(s32*)numHealthStands_54_21) = 0;
}

M2C_UNK CheckTweakers__12HealthStands_8_27() __asm__("CheckTweakers__12HealthStands");

void tweakerCallback__12HealthStandsPv(void) {
    CheckTweakers__12HealthStands_8_27();
}

int healthStandSetPrimed__Fi_5C_28(int) __asm__("healthStandSetPrimed__Fi");
s32 CheckTweakers__12HealthStands(void* arg0) {
    s32 temp_a0;
    s32 var_s1;
    s32 var_v0;
    void* var_s0;

    var_v0 = M2C_FIELD(arg0, s32* , 0xC);
    var_s0 = arg0 + 0x10;
    if (var_v0 != 0) {
        var_s1 = 4;
        do {
            temp_a0 = M2C_FIELD(var_s0, s32* , 4);
            var_s1 -= 1;
            if (temp_a0 != -1) {
                var_v0 = healthStandSetPrimed__Fi_5C_28(temp_a0);
            }
            var_s0 += 0x80;
        } while (var_s1 != 0);
    }
    return var_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/healthstand", addStand__12HealthStandsP9_hierheadP8_fvectorPA3_f);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/healthstand", InitAfterDbLoad__12HealthStandsi);

extern u8 normalLevelOrPrisonShipDocked_C_35[4] __asm__("normalLevelOrPrisonShipDocked");

void prisonShipHasDocked__12HealthStands(void) {
    (*(s32*)normalLevelOrPrisonShipDocked_C_35) = 1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/healthstand", update__12HealthStands);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/healthstand", handleTrigger__12HealthStandsP9_tdResultP7Vehicleb);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/healthstand", cleanup__12HealthStands);
