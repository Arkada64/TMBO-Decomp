#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_sound_49", func_001A5A38);

#include "m2c_macros.h"
M2C_UNK func_001A6498_1A63B8() __asm__("func_001A6498");
extern M2C_UNK D_0045BBF0_1A63B8 __asm__("D_0045BBF0");

void func_001A63B8(s32 arg0, s32 arg1) {
    func_001A6498_1A63B8(arg0, *((arg1 * 0x1) + &D_0045BBF0_1A63B8));
}

#include "m2c_macros.h"
M2C_UNK func_001A6498_1A63E8() __asm__("func_001A6498");
extern M2C_UNK D_0045AA70_1A63E8 __asm__("D_0045AA70");

void func_001A63E8(s32 arg0, s32 arg1) {
    func_001A6498_1A63E8(arg0, *((arg1 * 0x3) + &D_0045AA70_1A63E8));
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_sound_49", func_001A6418);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_sound_49", func_001A6448);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_sound_49", func_001A6498);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_sound_49", func_001A64E8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_sound_49", func_001A6538);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_sound_49", func_001A6590);

#include "m2c_macros.h"
M2C_UNK func_001A8570_1A6620() __asm__("func_001A8570");
M2C_UNK func_001F9608_1A6620() __asm__("func_001F9608");
extern M2C_UNK D_0045AB30_1A6620 __asm__("D_0045AB30");

void func_001A6620(s32* arg0) {
    s32 temp_a0;
    s32 var_v0;

    temp_a0 = *arg0;
    var_v0 = 0;
    if (temp_a0 != 0) {
        var_v0 = ~temp_a0 != 0;
    }
    if (var_v0 != 0) {
        func_001F9608_1A6620(temp_a0);
        *arg0 = 0;
    } else if (~temp_a0 == 0) {
        func_001A8570_1A6620(&D_0045AB30_1A6620, arg0);
    }
}

#include "m2c_macros.h"
void func_001A6688(void* arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (M2C_FIELD(arg0, s32* , 8) != arg1) {
        M2C_FIELD(arg0, s32* , 8) = arg1;
        M2C_FIELD(arg0, s32* , 4) = (s32) (M2C_FIELD(arg0, s32* , 4) | 1);
    }
    if (M2C_FIELD(arg0, s32* , 0xC) != arg2) {
        M2C_FIELD(arg0, s32* , 0xC) = arg2;
        M2C_FIELD(arg0, s32* , 4) = (s32) (M2C_FIELD(arg0, s32* , 4) | 4);
    }
    if (M2C_FIELD(arg0, s32* , 0x14) != arg3) {
        M2C_FIELD(arg0, s32* , 0x14) = arg3;
        M2C_FIELD(arg0, s32* , 4) = (s32) (M2C_FIELD(arg0, s32* , 4) | 0x10);
    }
}

#include "m2c_macros.h"
void func_001A66E8(void* arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (M2C_FIELD(arg0, s32* , 8) != arg1) {
        M2C_FIELD(arg0, s32* , 8) = arg1;
        M2C_FIELD(arg0, s32* , 4) = (s32) (M2C_FIELD(arg0, s32* , 4) | 1);
    }
    if (M2C_FIELD(arg0, s32* , 0xC) != arg2) {
        M2C_FIELD(arg0, s32* , 0xC) = arg2;
        M2C_FIELD(arg0, s32* , 4) = (s32) (M2C_FIELD(arg0, s32* , 4) | 4);
    }
    if (M2C_FIELD(arg0, s32* , 0x10) != arg3) {
        M2C_FIELD(arg0, s32* , 0x10) = arg3;
        M2C_FIELD(arg0, s32* , 4) = (s32) (M2C_FIELD(arg0, s32* , 4) | 8);
    }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_sound_49", func_001A6748);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_sound_49", func_001A67C0);

#include "m2c_macros.h"
void func_001A67E8(s32* arg0, s32 arg1) {
    *arg0 = arg1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_sound_49", func_001A67F0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_sound_49", func_001A6910);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_sound_49", func_001A69A8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_sound_49", func_001A6A20);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_sound_49", func_001A6A90);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_sound_49", func_001A6B00);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_sound_49", func_001A6B78);
