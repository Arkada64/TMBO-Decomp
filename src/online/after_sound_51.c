#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_sound_51", func_001A9D08);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_sound_51", func_001A9DD0);

#include "m2c_macros.h"
s32 func_001A9DE8(s32* arg0) {
    return *arg0 == 0xFFFFFFFE;
}

#include "m2c_macros.h"
s32 func_001A9E00(s32* arg0) {
    return ~*arg0 == 0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_sound_51", func_001A9E10);

#include "m2c_macros.h"
void func_001A9E28(void* arg0, s32 arg1, s32 arg2) {
    if (M2C_FIELD(arg0, s32* , 8) != arg1) {
        M2C_FIELD(arg0, s32* , 8) = arg1;
        M2C_FIELD(arg0, s32* , 4) = (s32) (M2C_FIELD(arg0, s32* , 4) | 1);
    }
    if (M2C_FIELD(arg0, s32* , 0xC) != arg2) {
        M2C_FIELD(arg0, s32* , 0xC) = arg2;
        M2C_FIELD(arg0, s32* , 4) = (s32) (M2C_FIELD(arg0, s32* , 4) | 4);
    }
}

#include "m2c_macros.h"
void func_001A9E68(void* arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s32* , 0x10) != arg1) {
        M2C_FIELD(arg0, s32* , 0x10) = arg1;
        M2C_FIELD(arg0, s32* , 4) = (s32) (M2C_FIELD(arg0, s32* , 4) | 8);
    }
}

#include "m2c_macros.h"
void func_001A9E90(void* arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s32* , 0x14) != arg1) {
        M2C_FIELD(arg0, s32* , 0x14) = arg1;
        M2C_FIELD(arg0, s32* , 4) = (s32) (M2C_FIELD(arg0, s32* , 4) | 0x10);
    }
}

#include "m2c_macros.h"
M2C_UNK func_001A9D08_1A9EB8() __asm__("func_001A9D08");

void func_001A9EB8(void) {
    func_001A9D08_1A9EB8(1, 0xFFFF);
}

#include "m2c_macros.h"
M2C_UNK func_001A9D08_1A9ED8() __asm__("func_001A9D08");

void func_001A9ED8(void) {
    func_001A9D08_1A9ED8(0, 0xFFFF);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_sound_51", func_001A9EF8);
