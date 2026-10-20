#include "common.h"

#include "m2c_macros.h"
M2C_UNK func_0021DE90_21FCC0() __asm__("func_0021DE90");
M2C_UNK func_0021F758_21FCC0() __asm__("func_0021F758");

void func_0021FCC0(s32 arg0) {
    u8 sp[0x10];
    func_0021DE90_21FCC0(sp);
    func_0021F758_21FCC0(arg0, sp);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_mathf_71", func_0021FCF8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_mathf_71", func_0021FD30);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_mathf_71", func_0021FD90);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_mathf_71", func_0021FE00);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_mathf_71", func_0021FF30);

#include "m2c_macros.h"
M2C_UNK func_00247C58_21FF40() __asm__("func_00247C58");
extern M2C_UNK D_004B3C60_21FF40 __asm__("D_004B3C60");

void func_0021FF40(s32 arg0, s32 arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 != 0) {
            func_00247C58_21FF40(&D_004B3C60_21FF40);
        }
    }
}

#include "m2c_macros.h"
M2C_UNK func_0021FF40_21FF70() __asm__("func_0021FF40");

void func_0021FF70(void) {
    func_0021FF40_21FF70(1, 0xFFFF);
}
