#include "common.h"
#include "m2c_macros.h"

void mathfSetFVector__FP8_fvectorfff_58_0(void*, float, float, float) __asm__("mathfSetFVector__FP8_fvectorfff");
void mathfCopyVector__FP8_fvectorT0_58_0(void*, void*) __asm__("mathfCopyVector__FP8_fvectorT0");
s32 __9RigidBody(void* arg0) {
    f32 temp_f12;
    void* temp_s1;

    temp_s1 = arg0 + 0x10;
    M2C_FIELD(arg0, f32* , 0) = 0.0f;
    M2C_FIELD(arg0, s32* , 0x30) = 0;
    temp_f12 = M2C_FIELD(arg0, f32* , 0);
    mathfSetFVector__FP8_fvectorfff_58_0(temp_s1, temp_f12, temp_f12, temp_f12);
    mathfCopyVector__FP8_fvectorT0_58_0(arg0 + 0x40, temp_s1);
    return (s32) arg0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigidbody", setCenterOfMass__9RigidBodyR8_fvector);

M2C_UNK computeX__9RigidBody_2C_7() __asm__("computeX__9RigidBody");
M2C_UNK mathfSetFVector__FP8_fvectorfff_2C_7() __asm__("mathfSetFVector__FP8_fvectorfff");

void setCenterOfMass__9RigidBodyfff(s32 arg0) {
    mathfSetFVector__FP8_fvectorfff_2C_7(arg0 + 0x10);
    computeX__9RigidBody_2C_7(arg0);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigidbody", setTensor__9RigidBodyfff);

void mathfSubVector__FP8_fvectorT0T0_70_11(void*, void*, void*) __asm__("mathfSubVector__FP8_fvectorT0T0");
void mathfCopyVector__FP8_fvectorT0_70_11(void*, void*) __asm__("mathfCopyVector__FP8_fvectorT0");
int mathfAddVector__FP8_fvectorT0T0_70_11(void*, void*, void*) __asm__("mathfAddVector__FP8_fvectorT0T0");
s32 setTrans__9RigidBodyR8_fvector(void* arg0, void* arg1) {
    u8 sp[0x10];
    void* temp_s1;

    temp_s1 = arg0 + 0x40;
    mathfSubVector__FP8_fvectorT0T0_70_11(sp, temp_s1, M2C_FIELD(arg0, s32* , 0x30) + 0x10);
    mathfCopyVector__FP8_fvectorT0_70_11(M2C_FIELD(arg0, s32* , 0x30) + 0x10, arg1);
    return mathfAddVector__FP8_fvectorT0T0_70_11(temp_s1, M2C_FIELD(arg0, s32* , 0x30) + 0x10, sp);
}

void mathfAddVector__FP8_fvectorT0T0_50_15(void*, void*, void*) __asm__("mathfAddVector__FP8_fvectorT0T0");

void deltaTrans__9RigidBodyR8_fvector(void* arg0, s32 arg1) {
    void* temp_a0;
    void* temp_s0;

    temp_a0 = M2C_FIELD(arg0, s32* , 0x30) + 0x10;
    mathfAddVector__FP8_fvectorT0T0_50_15(temp_a0, temp_a0, arg1);
    temp_s0 = arg0 + 0x40;
    mathfAddVector__FP8_fvectorT0T0_50_15(temp_s0, temp_s0, arg1);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigidbody", initBlock__9RigidBodyffff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigidbody", initSphere__9RigidBodyff);

void setTensor__9RigidBodyfff_E4_24(void*, float, float, float) __asm__("setTensor__9RigidBodyfff");

void initCylindrical__9RigidBodyffif(f32* arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2) {
    f32 temp_f12;
    f32 temp_f14;

    temp_f14 = fparg2 * fparg0 * fparg0 * 0.5f;
    temp_f12 = (fparg2 * ((fparg0 * 3.0f * fparg0) + (fparg1 * fparg1))) / 12.0f;
    switch (arg1) {                                 /* irregular */
    case 0:
        setTensor__9RigidBodyfff_E4_24(arg0, temp_f14, temp_f12, temp_f12);
        break;
    case 1:
        setTensor__9RigidBodyfff_E4_24(arg0, temp_f12, temp_f14, temp_f12);
        break;
    case 2:
        setTensor__9RigidBodyfff_E4_24(arg0, temp_f12, temp_f12, temp_f14);
        break;
    }
    *arg0 = 1.0f / fparg2;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigidbody", initEllipsoid__9RigidBodyffff);

void computeAuxiliarys__9RigidBody_60_30(void*) __asm__("computeAuxiliarys__9RigidBody");
void computeX__9RigidBody_60_30(void*) __asm__("computeX__9RigidBody");
void mathfSetFVector__FP8_fvectorfff_60_30(void*, float, float, float) __asm__("mathfSetFVector__FP8_fvectorfff");

void reset__9RigidBody(s32 arg0) {
    mathfSetFVector__FP8_fvectorfff_60_30(arg0 + 0x50, 0, 0, 0);
    mathfSetFVector__FP8_fvectorfff_60_30(arg0 + 0x60, 0, 0, 0);
    computeAuxiliarys__9RigidBody_60_30(arg0);
    computeX__9RigidBody_60_30(arg0);
}

void mathfSetFVector__FP8_fvectorfff_50_33(void*, float, float, float) __asm__("mathfSetFVector__FP8_fvectorfff");

void clearForces__9RigidBody(s32 arg0) {
    mathfSetFVector__FP8_fvectorfff_50_33(arg0 + 0xD0, 0, 0, 0);
    mathfSetFVector__FP8_fvectorfff_50_33(arg0 + 0xE0, 0, 0, 0);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigidbody", applyWorldForce__9RigidBodyR8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigidbody", applyWorldForce__9RigidBodyR8_fvectorT1);

void mathfMulTransVec__FPA3_A3_fP8_fvectorT1_3C_41(void*, void*, void*) __asm__("mathfMulTransVec__FPA3_A3_fP8_fvectorT1");
int applyWorldForce__9RigidBodyR8_fvector_3C_41(void*, void*) __asm__("applyWorldForce__9RigidBodyR8_fvector");
s32 applyLocalForce__9RigidBodyR8_fvector(void* arg0, void* arg1) {
    u8 sp[0x10];
    mathfMulTransVec__FPA3_A3_fP8_fvectorT1_3C_41(M2C_FIELD(arg0, s32* , 0x30) + 0x20, arg1, sp);
    return applyWorldForce__9RigidBodyR8_fvector_3C_41(arg0, sp);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigidbody", applyLocalForce__9RigidBodyR8_fvectorT1);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigidbody", applyLocalTorque__9RigidBodyR8_fvectorT1);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigidbody", applyWorldTorque__9RigidBodyR8_fvectorT1);

void mathfAddVector__FP8_fvectorT0T0_48_54(void*, void*, void*) __asm__("mathfAddVector__FP8_fvectorT0T0");
void mathfScaleVector__FP8_fvectorT0f_48_54(void*, void*, float) __asm__("mathfScaleVector__FP8_fvectorT0f");

void applyWorldImpulse__9RigidBodyR8_fvector(f32* arg0, s32 arg1) {
    s32 temp_s1;

    temp_s1 = arg0 + 0x14;
    mathfAddVector__FP8_fvectorT0T0_48_54(temp_s1, temp_s1, arg1);
    mathfScaleVector__FP8_fvectorT0f_48_54(arg0 + 0x2c, temp_s1, *arg0);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigidbody", applyWorldImpulse__9RigidBodyR8_fvectorT1);

void mathfMulTransVec__FPA3_A3_fP8_fvectorT1_3C_61(void*, void*, void*) __asm__("mathfMulTransVec__FPA3_A3_fP8_fvectorT1");
int applyWorldImpulse__9RigidBodyR8_fvector_3C_61(void*, void*) __asm__("applyWorldImpulse__9RigidBodyR8_fvector");
s32 applyLocalImpulse__9RigidBodyR8_fvector(void* arg0, void* arg1) {
    u8 sp[0x10];
    mathfMulTransVec__FPA3_A3_fP8_fvectorT1_3C_61(M2C_FIELD(arg0, s32* , 0x30) + 0x20, arg1, sp);
    return applyWorldImpulse__9RigidBodyR8_fvector_3C_61(arg0, sp);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigidbody", applyLocalImpulse__9RigidBodyR8_fvectorT1);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigidbody", resolveCollision__9RigidBodyR9RigidBodyR8_fvectorT2fff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigidbody", resolveCollision__9RigidBodyR8_fvectorT1fff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigidbody", resolveCollision__9RigidBodyR8_fvectorT1T1fff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigidbody", resolveForces__9RigidBodyf);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigidbody", computeAuxiliarys__9RigidBody);

void mathfAddVector__FP8_fvectorT0T0_50_92(void*, void*, void*) __asm__("mathfAddVector__FP8_fvectorT0T0");
void mathfMulTransVec__FPA3_A3_fP8_fvectorT1_50_92(void*, void*, void*) __asm__("mathfMulTransVec__FPA3_A3_fP8_fvectorT1");

void computeX__9RigidBody(void* arg0) {
    s32 temp_s1;

    temp_s1 = arg0 + 0x40;
    mathfMulTransVec__FPA3_A3_fP8_fvectorT1_50_92(M2C_FIELD(arg0, s32* , 0x30) + 0x20, arg0 + 0x10, temp_s1);
    mathfAddVector__FP8_fvectorT0T0_50_92(temp_s1, temp_s1, M2C_FIELD(arg0, s32* , 0x30) + 0x10);
}

void mathfSubVector__FP8_fvectorT0T0_5C_94(void*, void*, void*) __asm__("mathfSubVector__FP8_fvectorT0T0");
void mathfCrossProduct__FP8_fvectorT0T0_5C_94(void*, void*, void*) __asm__("mathfCrossProduct__FP8_fvectorT0T0");
int mathfAddVector__FP8_fvectorT0T0_5C_94(void*, void*, void*) __asm__("mathfAddVector__FP8_fvectorT0T0");
s32 getPointVelocity__9RigidBodyR8_fvectorT1(void* arg0, void* arg1, void* arg2) {
    u8 sp[0x10];
    mathfSubVector__FP8_fvectorT0T0_5C_94(sp, arg2, arg0 + 0x40);
    mathfCrossProduct__FP8_fvectorT0T0_5C_94(arg1, arg0 + 0xC0, sp);
    return mathfAddVector__FP8_fvectorT0T0_5C_94(arg1, arg1, arg0 + 0xB0);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigidbody", setLinearVelocity__9RigidBodyR8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigidbody", createSkewSymmetric__9RigidBodyPA3_fR8_fvector);
