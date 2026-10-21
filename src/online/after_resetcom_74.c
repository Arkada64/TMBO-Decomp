#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_resetcom_74", func_00230770);

#include "m2c_macros.h"
int setCenterOfMass__9RigidBodyfff_230798(void*, float, float, float) __asm__("setCenterOfMass__9RigidBodyfff");
void func_00230798(void* arg0, void* arg1) {
    setCenterOfMass__9RigidBodyfff_230798(arg0, M2C_FIELD(arg1, f32* , 0), M2C_FIELD(arg1, f32* , 4), M2C_FIELD(arg1, f32* , 8));
}
