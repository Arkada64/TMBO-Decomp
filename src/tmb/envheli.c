#include "common.h"
#include "m2c_macros.h"

void mathfSetFVector__FP8_fvectorfff_6C_1(void*, float, float, float) __asm__("mathfSetFVector__FP8_fvectorfff");

void InitBefore__7EnvHeli(void* arg0) {
    M2C_FIELD(arg0, s32* , 0x294) = 0;
    M2C_FIELD(arg0, s32* , 0x10) = 0;
    M2C_FIELD(arg0, s32* , 0x14) = 0;
    M2C_FIELD(arg0, s32* , 0x18) = 0;
    M2C_FIELD(arg0, s32* , 0x90) = 0;
    M2C_FIELD(arg0, s32* , 0xC) = 3;
    mathfSetFVector__FP8_fvectorfff_6C_1(arg0 + 0x30, 0, 0, 0);
    M2C_FIELD(arg0, f32* , 0x8C) = 100.0f;
    M2C_FIELD(arg0, f32* , 0x88) = 200.0f;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/envheli", InitAfter__7EnvHeli);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/envheli", Update__7EnvHeli);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/envheli", UpdateEnvHeli__7EnvHeli);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/envheli", UpdateRot__7EnvHelif);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/envheli", UpdateTrans__7EnvHeli);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/envheli", GetNextAttractPt__7EnvHeli);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/envheli", GetClosestAttractPt__7EnvHeli);

int playDestructibleSound__FP8_fvectoriiii_D0_21(void*, int, int, int, int) __asm__("playDestructibleSound__FP8_fvectoriiii");
void particleCreateFx__FP8_fvectorPA3_fifT0T1bf_D0_21(void*, void*, int, float, void*, void*, unsigned char, float) __asm__("particleCreateFx__FP8_fvectorPA3_fifT0T1bf");
int mathfRand__Fii_D0_21(int, int) __asm__("mathfRand__Fii");
s32 TakeHit__7EnvHeliP8_fvectorii(void* arg0, void* arg1, s32 arg2, s32 arg3) {
    s32 temp_a0;
    s32 temp_v1;
    s32 var_v0;
    void* temp_s0;

    var_v0 = M2C_FIELD(arg0, s32* , 0xC) - arg2;
    M2C_FIELD(arg0, s32* , 0xC) = var_v0;
    if ((var_v0 <= 0) && (var_v0 = M2C_FIELD(arg0, s32* , 0x10), (var_v0 != 1))) {
        temp_a0 = M2C_FIELD(arg0, s32* , 0x90);
        M2C_FIELD(arg0, s32* , 0x10) = 1;
        M2C_FIELD(arg0, s32* , 0x14) = 0;
        particleCreateFx__FP8_fvectorPA3_fifT0T1bf_D0_21(temp_a0 + 0x10, temp_a0 + 0x20, 0x14, 1.0f, NULL, NULL, 0U, 0.0f);
        temp_s0 = M2C_FIELD(arg0, s32* , 0x90) + 0x10;
        var_v0 = playDestructibleSound__FP8_fvectoriiii_D0_21(temp_s0, 0, mathfRand__Fii_D0_21(0, 0x14) + 3, 0xFA, 0x578);
        temp_v1 = M2C_FIELD(arg0, s32* , 8);
        if (temp_v1 == 1) {
            var_v0 = M2C_FIELD(arg0, s32* , 0x28C);
            if (var_v0 != 0) {
                M2C_FIELD(var_v0, s32* , 0x23A4) = temp_v1;
                var_v0 = 0x258;
                M2C_FIELD(arg0, s32* , 0x18) = 0x258;
            }
        }
    }
    return var_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/envheli", UpdateDeath__7EnvHeli);

void mathfSetFVector__FP8_fvectorfff_E8_27(void*, float, float, float) __asm__("mathfSetFVector__FP8_fvectorfff");
void mathfRotMatrixRPH__FPA3_fP8_fvector_E8_27(void*, void*) __asm__("mathfRotMatrixRPH__FPA3_fP8_fvector");
void mathfCopyVector__FP8_fvectorT0_E8_27(void*, void*) __asm__("mathfCopyVector__FP8_fvectorT0");
s32 Regen__7EnvHeli(void* arg0) {
    void* temp_a0;
    void* temp_v0;

    M2C_FIELD(arg0, s32* , 4) = 1;
    M2C_FIELD(arg0, s32* , 0x10) = 0;
    M2C_FIELD(arg0, s32* , 0x14) = 0;
    M2C_FIELD(arg0, s32* , 0x18) = 0;
    M2C_FIELD(arg0, s32* , 8) = 0;
    M2C_FIELD(arg0, s32* , 0x94) = 0;
    M2C_FIELD(arg0, s32* , 0xC) = 3;
    M2C_FIELD(arg0, s32* , 0x98) = -1;
    mathfCopyVector__FP8_fvectorT0_E8_27(M2C_FIELD(arg0, void** , 0x90) + 0x10, arg0 + 0x160);
    M2C_FIELD(M2C_FIELD(arg0, void** , 0x90), f32* , 0x18) = 300.0f;
    mathfSetFVector__FP8_fvectorfff_E8_27(arg0 + 0x30, 0.0f, 0.0f, 0.0f);
    mathfSetFVector__FP8_fvectorfff_E8_27(M2C_FIELD(arg0, void** , 0x90) + 0x60, 0.0f, 0.0f, 0.0f);
    mathfSetFVector__FP8_fvectorfff_E8_27(arg0 + 0x20, 0.0f, 0.0f, 0.0f);
    temp_a0 = M2C_FIELD(arg0, void** , 0x90);
    mathfRotMatrixRPH__FPA3_fP8_fvector_E8_27(temp_a0 + 0x20, temp_a0 + 0x60);
    mathfRotMatrixRPH__FPA3_fP8_fvector_E8_27(arg0 + 0x40, M2C_FIELD(arg0, void** , 0x90) + 0x60);
    temp_v0 = M2C_FIELD(arg0, void** , 0x90);
    M2C_FIELD(temp_v0, s8* , 0xC) = 1;
    return (s32) temp_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/envheli", GetHeading__7EnvHeliP8_fvectorT1);

void AddEpNode__7EnvHeliP9_hierhead(void* arg0, void* arg1) {
    s32 temp_a2;

    temp_a2 = M2C_FIELD(arg1, s32* , 0);
    if ((temp_a2 & 0xFFFC0000) == 0x9C800000) {
        if ((temp_a2 & 0x3F) == 3) {
            M2C_FIELD(arg0, void** , 0x298) = (void* ) M2C_FIELD(arg1, void** , 0x1C);
            return;
        }
        M2C_FIELD(arg0, void** , 0x298) = arg1;
        return;
    }
    M2C_FIELD(arg0, void** , 0x294) = arg1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/envheli", func_0012A3A8);
