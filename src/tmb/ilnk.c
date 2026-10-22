#include "common.h"
#include "m2c_macros.h"

void ilnkListInit__FP9_ilnklistiPi(void* arg0, s32 arg1, s32* arg2) {
    s32 var_a1;
    void* var_a0;

    var_a0 = arg0;
    var_a1 = arg1;
    if (var_a1 > 0) {
        do {
            M2C_FIELD(var_a0, s32* , 0) = 0;
            var_a1 -= 1;
            M2C_FIELD(var_a0, s32* , 8) = -1;
            M2C_FIELD(var_a0, s32* , 4) = -1;
            var_a0 += 0xC;
        } while (var_a1 != 0);
    }
    *arg2 = -1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ilnk", ilnkListFill__FP9_ilnklistiPib);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ilnk", ilnkListAdd__FP9_ilnklistiPi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ilnk", ilnkListRem__FP9_ilnklistiPi);
