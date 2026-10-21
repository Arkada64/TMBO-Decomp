#include "common.h"

#include "m2c_macros.h"
extern volatile unsigned char D_0045BF78_1B22F0 __asm__("D_0045BF78");

s32 func_001B22F0(s32 arg0)
{
  s32 *new_var2;
  s32 **new_var3;
  s32 *new_var;
  int new_var4;
  new_var4 = 0x80;
  new_var = (new_var2 = (s32 *) (((u8 *) ((&D_0045BF78_1B22F0) + (arg0 * 0x84))) + new_var4));
  new_var3 = &new_var;
  return *(*new_var3);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_trafficdirector_56", func_001B2310);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_trafficdirector_56", func_001B2350);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_trafficdirector_56", func_001B2370);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_trafficdirector_56", func_001B23A8);

#include "m2c_macros.h"
s32 func_001B23C8(s32 arg0) {
    return arg0 != 0xB;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_trafficdirector_56", func_001B23D8);

#include "m2c_macros.h"
M2C_UNK func_001B23D8_1B2558() __asm__("func_001B23D8");

void func_001B2558(s32 arg0, M2C_UNK arg1) {
    switch (arg0) {                                 /* irregular */
    case 6:
        func_001B23D8_1B2558(6, 1, arg1, 0);
        func_001B23D8_1B2558(6, 3, arg1, 0);
        func_001B23D8_1B2558(6, 4, arg1, 0);
        func_001B23D8_1B2558(6, 5, arg1, 0);
        func_001B23D8_1B2558(6, 6, arg1, 0);
        func_001B23D8_1B2558(6, 8, arg1, 1);
        return;
    case 33:
        func_001B23D8_1B2558(0x21, 0, arg1, 0);
        func_001B23D8_1B2558(0x21, 1, arg1, 0);
        func_001B23D8_1B2558(0x21, 2, arg1, 0);
        func_001B23D8_1B2558(0x21, 3, arg1, 0);
        func_001B23D8_1B2558(0x21, 4, arg1, 0);
        func_001B23D8_1B2558(0x21, 5, arg1, 1);
        break;
    }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_trafficdirector_56", func_001B2690);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_trafficdirector_56", func_001B2B68);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_trafficdirector_56", func_001B4380);
