#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/boss", InitBossBefore__9FinalBoss);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/boss", InitBossAfter__9FinalBoss);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/boss", UpdateBoss__9FinalBoss);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/boss", UpdateRot__9FinalBossf);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/boss", UpdateTrans__9FinalBoss);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/boss", GetClosestPlayer__9FinalBoss);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/boss", GetNextAttractPt__9FinalBoss);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/boss", GetClosestAttractPt__9FinalBoss);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/boss", GetHeading__9FinalBossP8_fvectorT1);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/boss", TakeHit__9FinalBossP8_fvectorii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/boss", UpdateDeath__9FinalBoss);

void mathfSetFVector__FP8_fvectorfff_F8_30(void*, float, float, float) __asm__("mathfSetFVector__FP8_fvectorfff");
void mathfRotMatrixRPH__FPA3_fP8_fvector_F8_30(void*, void*) __asm__("mathfRotMatrixRPH__FPA3_fP8_fvector");
int mathfRand__Fii_F8_30(int, int) __asm__("mathfRand__Fii");
void mathfCopyVector__FP8_fvectorT0_F8_30(void*, void*) __asm__("mathfCopyVector__FP8_fvectorT0");
void GetNextAttractPt__9FinalBoss_F8_30(void*) __asm__("GetNextAttractPt__9FinalBoss");
s32 RegenBoss__9FinalBoss(void* arg0) {
    s32 temp_v0_2;
    void* temp_a0;
    void* temp_v0;

    M2C_FIELD(arg0, s32* , 4) = 1;
    M2C_FIELD(arg0, s32* , 0x20) = 0;
    M2C_FIELD(arg0, s32* , 0x24) = 0;
    M2C_FIELD(arg0, s32* , 0x28) = 0;
    M2C_FIELD(arg0, s32* , 0x2C) = 0;
    M2C_FIELD(arg0, s32* , 0x1C) = 3;
    M2C_FIELD(arg0, s32* , 0xF4) = -1;
    temp_v0_2 = mathfRand__Fii_F8_30(0, 7);
    M2C_FIELD(arg0, s32* , 0xF0) = temp_v0_2;
    mathfCopyVector__FP8_fvectorT0_F8_30(M2C_FIELD(arg0, void** , 0xE0) + 0x10, arg0 + ((temp_v0_2 * 0x30) + 0x100));
    GetNextAttractPt__9FinalBoss_F8_30(arg0);
    mathfSetFVector__FP8_fvectorfff_F8_30(arg0 + 0x50, 0.0f, 0.0f, 0.0f);
    mathfSetFVector__FP8_fvectorfff_F8_30(M2C_FIELD(arg0, void** , 0xE0) + 0x60, 0.0f, 0.0f, 0.0f);
    mathfSetFVector__FP8_fvectorfff_F8_30(arg0 + 0x40, 0.0f, 0.0f, 0.0f);
    temp_a0 = M2C_FIELD(arg0, void** , 0xE0);
    mathfRotMatrixRPH__FPA3_fP8_fvector_F8_30(temp_a0 + 0x20, temp_a0 + 0x60);
    mathfRotMatrixRPH__FPA3_fP8_fvector_F8_30(arg0 + 0xA0, M2C_FIELD(arg0, void** , 0xE0) + 0x60);
    temp_v0 = M2C_FIELD(arg0, void** , 0xE0);
    M2C_FIELD(temp_v0, s8* , 0xC) = 1;
    return (s32) temp_v0;
}

void AddEpNode__9FinalBossP9_hierhead(void* arg0, void* arg1) {
    M2C_FIELD(arg0, void** , 0x9C) = arg1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/boss", CheckCollision__9FinalBoss);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/boss", AddMessage__7TheGameiiii);
