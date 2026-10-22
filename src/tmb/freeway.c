#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/freeway", freewayInitBefore__7Freeway);

void initAfter__12FreewayTrain_64_3(void*) __asm__("initAfter__12FreewayTrain");
void animationSetToPercent__FR11_animHandlef_64_3(void*, float) __asm__("animationSetToPercent__FR11_animHandlef");
int animationGetHandle__FP11_animHandleUiUiUi_64_3(void*, unsigned int, unsigned int, unsigned int) __asm__("animationGetHandle__FP11_animHandleUiUiUi");
s32 freewayInitAfter__7Freeway(void* arg0) {
    u8 sp[0x10];
    initAfter__12FreewayTrain_64_3(arg0 + 0x60);
    initAfter__12FreewayTrain_64_3(arg0 + 0x1E0);
    animationGetHandle__FP11_animHandleUiUiUi_64_3(sp, 0x2849U, 0U, 1U);
    animationSetToPercent__FR11_animHandlef_64_3(sp, 0.0f);
    return animationGetHandle__FP11_animHandleUiUiUi_64_3(arg0 + 0x50, 0x17DFU, 0U, 0U);
}

M2C_UNK updateCraneAnim__7Freeway_38_8() __asm__("updateCraneAnim__7Freeway");
M2C_UNK updateTrainWreck__7Freeway_38_8() __asm__("updateTrainWreck__7Freeway");
M2C_UNK update__12FreewayTrain_38_8() __asm__("update__12FreewayTrain");

void freewayUpdate__7Freeway(s32 arg0) {
    updateCraneAnim__7Freeway_38_8();
    updateTrainWreck__7Freeway_38_8(arg0);
    update__12FreewayTrain_38_8(arg0 + 0x60);
    update__12FreewayTrain_38_8(arg0 + 0x1E0);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/freeway", updateCraneAnim__7Freeway);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/freeway", updateTrainWreck__7Freeway);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/freeway", bridgeDust__7Freewayb);

int timerGetFieldCount__Fv_C0_15(void) __asm__("timerGetFieldCount__Fv");
void AddMessage__7TheGameiiii_C0_15(void*, int, int, int, int) __asm__("AddMessage__7TheGameiiii");
extern u8 game_C0_15[4] __asm__("game");
extern u8 shell_C0_15[4] __asm__("shell");

s32 triggerCarUnlock__7Freeway(void* arg0) {
    s32 var_a0;
    s32 var_v0;
    void* var_v1;

    var_v0 = (timerGetFieldCount__Fv_C0_15() - 0x190) < M2C_FIELD(arg0, s32* , 4);
    if (var_v0 == 0) {
        var_v0 = M2C_FIELD(arg0, s32* , 8);
        if (var_v0 == 0) {
            AddMessage__7TheGameiiii_C0_15((*(void**)game_C0_15), 0xDE, 1, 0, 1);
            AddMessage__7TheGameiiii_C0_15((*(void**)game_C0_15), 0xCD, 1, 0, 1);
            var_a0 = 0xF;
            var_v1 = (*(s32*)shell_C0_15) + 0x1A220;
            do {
                if (M2C_FIELD(var_v1, s32* , 0xA8) == 0x160) {
                    M2C_FIELD(var_v1, s32* , -0x94) = 0;
                    if (M2C_FIELD(var_v1, s32* , 0) == 1) {
                        M2C_FIELD(var_v1, s32* , 0) = 0;
                    }
                }
                var_a0 -= 1;
                var_v1 += 4;
            } while (var_a0 >= 0);
            var_v0 = 1;
            M2C_FIELD(arg0, s32* , 8) = 1;
        }
    }
    return var_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/freeway", addNode__7FreewayiP9_hierhead);

void plightDestroy__FP11_pointlight_1C_21(void*) __asm__("plightDestroy__FP11_pointlight");
void cleanupOnShutdown__7Freeway(void* arg0) {
    void* temp_a0;

    temp_a0 = M2C_FIELD(arg0, void** , 0x360);
    if (temp_a0 != NULL) {
        plightDestroy__FP11_pointlight_1C_21(temp_a0);
    }
}

void mathfCopyVector__FP8_fvectorT0_6C_25(void*, void*) __asm__("mathfCopyVector__FP8_fvectorT0");

void startBridgeDestruct__7FreewayP11_hierswitchP8_fvectorT2(void* arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (M2C_FIELD(arg0, s32* , 0x24) == -1) {
        M2C_FIELD(arg0, s32* , 0x20) = arg1;
        M2C_FIELD(arg0, s32* , 0x24) = 0;
        mathfCopyVector__FP8_fvectorT0_6C_25(arg0 + 0x30, arg2);
        mathfCopyVector__FP8_fvectorT0_6C_25(arg0 + 0x40, arg3);
    }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/freeway", func_0012E1D0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/freeway", func_0012E1E0);
