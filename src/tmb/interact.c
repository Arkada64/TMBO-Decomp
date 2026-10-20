#include "common.h"

#include "m2c_macros.h"
void func_0014F040(void* arg0) {
    s32 var_v1;
    void* var_v0;

    var_v1 = 0x7FF;
    var_v0 = arg0;
    do {
        M2C_FIELD(var_v0, s32* , 0) = 0;
        var_v1 -= 1;
        M2C_FIELD(var_v0, s32* , 0x2000) = 0;
        var_v0 += 4;
    } while (var_v1 >= 0);
    M2C_FIELD(arg0, s32* , 0x4000) = 0x1E;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/interact", func_0014F070);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/interact", func_0014F0B8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/interact", func_0014F0E0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/interact", GetInteractive__12Interactivesi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/interact", func_0014F108);
