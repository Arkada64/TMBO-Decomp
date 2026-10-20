#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hoserInfo", hoserInfoInit__FP9HoserInfo);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hoserInfo", hoserFindFreeBookmark__FP9HoserInfo);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hoserInfo", func_00215110);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hoserInfo", func_00215200);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hoserInfo", func_00215320);

#include "m2c_macros.h"
s32 hoserGotoBookmark__FP9HoserInfo(void) {
    return 0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hoserInfo", hoserNextBookmark__FP9HoserInfo);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hoserInfo", hoserPrevBookmark__FP9HoserInfo);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hoserInfo", func_00215468);

#include "m2c_macros.h"
extern M2C_UNK D_00610F00_fo__Fv __asm__("D_00610F00");

M2C_UNK* hoserGetHoserInfo__Fv(void) {
    return &D_00610F00_fo__Fv;
}
