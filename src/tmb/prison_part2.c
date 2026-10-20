#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/prison_part2", InitForReplay__6Prison);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/prison_part2", func_0017D4D0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/prison_part2", func_0017D7B8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/prison_part2", func_0017D938);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/prison_part2", D_004E9480);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/prison_part2", func_0017DA58);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/prison_part2", func_0017DB90);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/prison_part2", func_0017DD58);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/prison_part2", prisonUpdateIslandTrans__6Prison);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/prison_part2", func_0017DFE8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/prison_part2", func_0017E1A8);

#include "m2c_macros.h"
s32 animationIsRunning__FR11_animHandle_17E218() __asm__("animationIsRunning__FR11_animHandle");
M2C_UNK animationPause__FR11_animHandle_17E218() __asm__("animationPause__FR11_animHandle");
M2C_UNK animationStart__FR11_animHandleb_17E218() __asm__("animationStart__FR11_animHandleb");
M2C_UNK prisonUpdateTransitionPoints__6Prison_17E218() __asm__("prisonUpdateTransitionPoints__6Prison");

void func_0017E218(void* arg0) {
    void* temp_s1;
    void* temp_s1_2;

    if ((M2C_FIELD(arg0, s32* , 0x20) != 0) && (animationIsRunning__FR11_animHandle_17E218(arg0 + 0x20) == 0)) {
        if (M2C_FIELD(arg0, s32* , 0x50) != 0) {
            temp_s1 = arg0 + 0x50;
            if (animationIsRunning__FR11_animHandle_17E218(temp_s1) != 0) {
                animationPause__FR11_animHandle_17E218(temp_s1);
            }
        }
        if (M2C_FIELD(arg0, s32* , 0x5C) != 0) {
            temp_s1_2 = arg0 + 0x5C;
            if (animationIsRunning__FR11_animHandle_17E218(temp_s1_2) != 0) {
                animationPause__FR11_animHandle_17E218(temp_s1_2);
            }
        }
        if (M2C_FIELD(arg0, s32* , 0x68) != 0) {
            animationStart__FR11_animHandleb_17E218(arg0 + 0x68, 1);
        }
        if (M2C_FIELD(arg0, s32* , 0x74) != 0) {
            animationStart__FR11_animHandleb_17E218(arg0 + 0x74, 1);
        }
        if (M2C_FIELD(arg0, s32* , 0xC8) != 0) {
            animationStart__FR11_animHandleb_17E218(arg0 + 0xC8, 1);
        }
        M2C_FIELD(arg0, s32* , 0xF8) = 5;
        prisonUpdateTransitionPoints__6Prison_17E218(arg0);
    }
}

#include "m2c_macros.h"
M2C_UNK func_00198D20_Prison() __asm__("func_00198D20");

void prisonUpdateGatesOpenBridgeDown__6Prison(s32 arg0) {
    func_00198D20_Prison(arg0 + 0x120);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/prison_part2", prisonUpdateTransitionPoints__6Prison);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/prison_part2", func_0017E898);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/prison_part2", func_0017E928);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/prison_part2", prisonUpdateCraneDestruct__6Prison);

#include "m2c_macros.h"
void startShocking__17ElectrocutionPeds(void* arg0) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32* , 0xC);
    if ((temp_v1 == 0) || (temp_v1 == 3)) {
        M2C_FIELD(arg0, s32* , 0x14) = 0x262;
    }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/prison_part2", func_0017EC18);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/prison_part2", func_0017F0F8);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/prison_part2", D_004E94D8);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/prison_part2", D_004E94E8);
