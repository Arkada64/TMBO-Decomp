#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_game_19", func_0013EED0);

#include "m2c_macros.h"
M2C_UNK func_00183D88_13F0E8() __asm__("func_00183D88");
extern M2C_UNK D_002B9830_13F0E8 __asm__("D_002B9830");

void func_0013F0E8(s32 arg0, s32 arg1) {
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        func_00183D88_13F0E8(&D_002B9830_13F0E8, 3);
    }
}

#include "m2c_macros.h"
M2C_UNK func_0013F0E8_13F118() __asm__("func_0013F0E8");

void func_0013F118(void) {
    func_0013F0E8_13F118(1, 0xFFFF);
}
