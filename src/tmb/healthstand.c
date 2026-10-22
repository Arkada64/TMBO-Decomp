#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/healthstand", healthStandInit__FP8_fvectorPA3_f);

extern u8 healthStand_1C_7[] __asm__("healthStand");

void healthStandSetInert__Fi(s32 arg0)
{
  int new_var;
  new_var = 0x68;
  *((s32 *) (((u8 *) ((arg0 * 0x70) + ((u8 *) healthStand_1C_7))) + new_var)) = 0;
}

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

s32 healthStandInit__FP8_fvectorPA3_f_A8_32(void *, void *) __asm__("healthStandInit__FP8_fvectorPA3_f");
void healthStandSetPrimed__Fi_A8_32(int) __asm__("healthStandSetPrimed__Fi");
void mathfCopyMatrix__FPA3_fT0_A8_32(void *, void *) __asm__("mathfCopyMatrix__FPA3_fT0");
void mathfCopyVector__FP8_fvectorT0_A8_32(void *, void *) __asm__("mathfCopyVector__FP8_fvectorT0");

void addStand__12HealthStandsP9_hierheadP8_fvectorPA3_f(s32 arg0, u32 *arg1, s32 arg2, s32 arg3)
{
  s32 temp_s1;
  s32 temp_s2;
  int new_var;
  s32 temp_v0_2;
  u32 temp_v0;
  void *temp_s0;
  temp_v0 = (((u32) (*arg1)) >> 7) & 0x7FF;
  if (temp_v0 < 4U)
  {
    new_var = (temp_v0 << 7) + 0x10;
    temp_s0 = arg0 + new_var;
    temp_s1 = temp_s0 + 0x50;
    temp_s2 = temp_s0 + 0x10;
    mathfCopyVector__FP8_fvectorT0_A8_32(temp_s1, arg2);
    mathfCopyMatrix__FPA3_fT0_A8_32(temp_s2, arg3);
    temp_v0_2 = healthStandInit__FP8_fvectorPA3_f_A8_32(temp_s1, temp_s2);
    *((s32 *) (((u8 *) temp_s0) + 4)) = temp_v0_2;
    healthStandSetPrimed__Fi_A8_32(temp_v0_2);
    *arg1 &= 0x7F;
  }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/healthstand", InitAfterDbLoad__12HealthStandsi);

extern u8 normalLevelOrPrisonShipDocked_C_35[4] __asm__("normalLevelOrPrisonShipDocked");

void prisonShipHasDocked__12HealthStands(void) {
    (*(s32*)normalLevelOrPrisonShipDocked_C_35) = 1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/healthstand", update__12HealthStands);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/healthstand", handleTrigger__12HealthStandsP9_tdResultP7Vehicleb);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/healthstand", cleanup__12HealthStands);
