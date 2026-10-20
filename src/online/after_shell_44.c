#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_shell_44", func_0018B070);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_shell_44", func_0018B1A0);

#include "m2c_macros.h"
void func_0018B200(s32* arg0) {
    *arg0 = 0;
}

#include "m2c_macros.h"
M2C_UNK __builtin_delete_18B208() __asm__("__builtin_delete");
M2C_UNK func_001A6620_18B208() __asm__("func_001A6620");

void func_0018B208(s32 arg0, s32 arg1) {
    func_001A6620_18B208(arg0 + 0x1E8);
    func_001A6620_18B208(arg0 + 0x1D0);
    func_001A6620_18B208(arg0 + 0x1B8);
    func_001A6620_18B208(arg0 + 0x1A0);
    func_001A6620_18B208(arg0 + 0x188);
    func_001A6620_18B208(arg0 + 0x170);
    func_001A6620_18B208(arg0 + 0x158);
    func_001A6620_18B208(arg0 + 0x140);
    func_001A6620_18B208(arg0 + 0x128);
    func_001A6620_18B208(arg0 + 0x110);
    func_001A6620_18B208(arg0 + 0xF8);
    func_001A6620_18B208(arg0 + 0xE0);
    func_001A6620_18B208(arg0 + 0xC8);
    func_001A6620_18B208(arg0 + 0xB0);
    func_001A6620_18B208(arg0 + 0x98);
    func_001A6620_18B208(arg0 + 0x80);
    func_001A6620_18B208(arg0 + 0x68);
    func_001A6620_18B208(arg0 + 0x50);
    func_001A6620_18B208(arg0 + 0x38);
    func_001A6620_18B208(arg0 + 0x20);
    if (arg1 & 1) {
        __builtin_delete_18B208(arg0);
    }
}

#include "m2c_macros.h"
M2C_UNK func_0014EF80_18B2E8() __asm__("func_0014EF80");

s32 func_0018B2E8(s32 arg0) {
    func_0014EF80_18B2E8(arg0 + 0x20);
    func_0014EF80_18B2E8(arg0 + 0x38);
    func_0014EF80_18B2E8(arg0 + 0x50);
    func_0014EF80_18B2E8(arg0 + 0x68);
    func_0014EF80_18B2E8(arg0 + 0x80);
    func_0014EF80_18B2E8(arg0 + 0x98);
    func_0014EF80_18B2E8(arg0 + 0xB0);
    func_0014EF80_18B2E8(arg0 + 0xC8);
    func_0014EF80_18B2E8(arg0 + 0xE0);
    func_0014EF80_18B2E8(arg0 + 0xF8);
    func_0014EF80_18B2E8(arg0 + 0x110);
    func_0014EF80_18B2E8(arg0 + 0x128);
    func_0014EF80_18B2E8(arg0 + 0x140);
    func_0014EF80_18B2E8(arg0 + 0x158);
    func_0014EF80_18B2E8(arg0 + 0x170);
    func_0014EF80_18B2E8(arg0 + 0x188);
    func_0014EF80_18B2E8(arg0 + 0x1A0);
    func_0014EF80_18B2E8(arg0 + 0x1B8);
    func_0014EF80_18B2E8(arg0 + 0x1D0);
    func_0014EF80_18B2E8(arg0 + 0x1E8);
    return arg0;
}

#include "m2c_macros.h"
M2C_UNK func_0018B1A0_18B3B0() __asm__("func_0018B1A0");

void func_0018B3B0(void) {
    func_0018B1A0_18B3B0(1, 0xFFFF);
}

#include "m2c_macros.h"
M2C_UNK func_0018B1A0_18B3D0() __asm__("func_0018B1A0");

void func_0018B3D0(void) {
    func_0018B1A0_18B3D0(0, 0xFFFF);
}

#include "m2c_macros.h"
s32 func_0018B778_18B3F0() __asm__("func_0018B778");

s32 func_0018B3F0(s32 arg0) {
    s32 var_v1;

    var_v1 = 0;
    if ((arg0 == 0) || (arg0 == 0x10)) {
        var_v1 = func_0018B778_18B3F0();
    }
    return var_v1 ^ 1;
}
