#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/destruct", Init__13Destructibles);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/destruct", AddDestruct__13DestructiblesiP9_hierheadP8_fvectorPA3_f);

M2C_UNK updateAll__11RigidDebris_8_8() __asm__("updateAll__11RigidDebris");

void Update__13Destructibles(void) {
    updateAll__11RigidDebris_8_8();
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/destruct", TakeHit__12DestructibleP8_fvectorii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/destruct", DoEffect__12DestructibleP8_fvectoriiP9_hierheadii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/destruct", GenericTakeHit__12DestructibleP8_fvectoriiii);

s32 AddVehicleDestruct__13DestructiblesP9_hierhead(void* arg0, void* arg1) {
    s32 temp_v1;
    s32 temp_v1_2;
    void* temp_v0;

    temp_v1_2 = M2C_FIELD(arg0, s32* , 0x1BD54);
    if (temp_v1_2 < 0x5DC) {
        temp_v0 = arg0 + (temp_v1_2 << 6);
        M2C_FIELD(temp_v0, s32* , 0x18) = 0;
        M2C_FIELD(temp_v0, void** , 0x10) = arg1;
        temp_v1 = M2C_FIELD(arg0, s32* , 0x1BD54) + 1;
        M2C_FIELD(arg0, s32* , 0x1BD54) = temp_v1;
        return (s32) (arg0 + ((temp_v1 << 6) - 0x40));
    }
    return 0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/destruct", VehicleTakeHit__12DestructibleP8_fvectoriiiT1T1);

s32 ResetDestructs__13Destructibles(void* arg0) {
    s32 temp_v1;
    s32 var_a2;
    void* temp_a1;
    void* temp_a3;
    void* var_a0;
    void* var_v0;

    var_a0 = arg0;
    var_v0 = var_a0 + 0x18000;
    var_a2 = 0;
    if (M2C_FIELD(var_a0, s32* , 0x1BD54) > 0) {
        temp_a3 = var_v0;
        do {
            temp_a1 = M2C_FIELD(var_a0, void** , 0x10);
            if ((temp_a1 != NULL) && ((M2C_FIELD(var_a0, s32* , 4) = (s32) M2C_FIELD(var_a0, s32* , 8), temp_v1 = M2C_FIELD(temp_a1, s32* , 0) & 0x3F, (temp_v1 == 0x1F)) || (temp_v1 == 6))) {
                M2C_FIELD(temp_a1, s8* , 8) = 0;
            }
            var_a2 += 1;
            var_v0 = (void* ) (var_a2 < M2C_FIELD(temp_a3, s32* , 0x3D54));
            var_a0 += 0x40;
        } while (var_v0 != NULL);
    }
    return (s32) var_v0;
}

int mathfSetFVector__FP8_fvectorfff_48_26(void*, float, float, float) __asm__("mathfSetFVector__FP8_fvectorfff");
s32 init__9CarUnlockfffii(void* arg0, f32 fparg0, f32 fparg1, f32 fparg2, s32 arg1, s32 arg2) {
    s32 temp_v0;

    M2C_FIELD(arg0, s32* , 4) = arg1;
    M2C_FIELD(arg0, s32* , 0xC) = 0;
    temp_v0 = mathfSetFVector__FP8_fvectorfff_48_26(arg0 + 0x10, fparg0, fparg1, fparg2);
    M2C_FIELD(arg0, s32* , 0) = 0;
    M2C_FIELD(arg0, s32* , 0x20) = (s32) (arg1 == 0);
    return temp_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/destruct", update__9CarUnlock);

void startUnlock__9CarUnlock(void* arg0) {
    M2C_FIELD(arg0, s32* , 0xC) = 1;
}

void plightDestroy__FP11_pointlight_1C_35(void*) __asm__("plightDestroy__FP11_pointlight");

void cleanup__9CarUnlock(s32* arg0) {
    s32 temp_a0;

    temp_a0 = *arg0;
    if (temp_a0 != 0) {
        plightDestroy__FP11_pointlight_1C_35(temp_a0);
    }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/destruct", func_00125700);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/destruct", func_00125710);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/destruct", prisonGuardTowerDestroyed__7TheGame);
