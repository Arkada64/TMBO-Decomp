#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_clapper_09", func_00118FA0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_clapper_09", func_00119118);

#include "m2c_macros.h"
M2C_UNK func_00119318_1192E8() __asm__("func_00119318");
M2C_UNK func_001A22F8_1192E8() __asm__("func_001A22F8");

s32 func_001192E8(s32 arg0) {
    func_00119318_1192E8();
    func_001A22F8_1192E8(arg0 + 0x70);
    return arg0;
}

#include "m2c_macros.h"
void func_00119318(void *arg0)
{
  u8 *new_var;
  *((s32 *) (((u8 *) arg0) + 0x6C)) = 0;
  *((f32 *) (((u8 *) arg0) + 0x2C)) = 1.0f;
  *((s32 *) (((u8 *) arg0) + 0x78)) = -1;
  *((s32 *) (((u8 *) arg0) + 0)) = 0;
  *((s32 *) (((u8 *) arg0) + 4)) = 0;
  *((s32 *) (((u8 *) arg0) + 8)) = 0;
  *((s32 *) (((u8 *) arg0) + 0xC)) = -1;
  *((s32 *) (((u8 *) arg0) + 0x10)) = -1;
  *((s32 *) (((u8 *) arg0) + 0x14)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x18)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x1C)) = 0;
 do { *((s32 *) ((new_var = (u8 *) arg0) + 0x20)) = -1; *((s32 *) (new_var + 0x24)) = 0; *((s32 *) (new_var + 0x30)) = 0; *((s32 *) (new_var + 0x5C)) = 0; *((s32 *) (new_var + 0x60)) = 0; *((s32 *) (new_var + 0x68)) = 0; } while (0);
  *((s32 *) (new_var + 0x64)) = 0;
}

#include "m2c_macros.h"
s32 mathfRand__Fii_119370() __asm__("mathfRand__Fii");
s32 timerGetFieldCount__Fv_119370() __asm__("timerGetFieldCount__Fv");

void func_00119370(void *arg0)
{
  s32 temp_v0;
  s32 temp_v0_2;
  *((s32 *) (((u8 *) arg0) + 8)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x1C)) = 0;
  *((s32 *) (((u8 *) arg0) + 0)) = 1;
  *((s32 *) (((u8 *) arg0) + 0x14)) = 1;
  *((s32 *) (((u8 *) arg0) + 0x10)) = -1;
  temp_v0 = mathfRand__Fii_119370(0x2D, 0xB4) * 0x3C;
  *((s32 *) (((u8 *) arg0) + 0x60)) = 0x1A4;
  *((s32 *) (((u8 *) arg0) + 0x5C)) = temp_v0;
  temp_v0_2 = mathfRand__Fii_119370(8, 0xC) * 0x3C;
  *((s32 *) (((u8 *) arg0) + 0x6C)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x30)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x68)) = 0x78;
  *((f32 *) (((u8 *) arg0) + 0x2C)) = 1.0f;
  *((s32 *) (((u8 *) arg0) + 0x64)) = temp_v0_2;
  *((s32 *) (((u8 *) arg0) + 0x38)) = timerGetFieldCount__Fv_119370();
  *((s32 *) (((u8 *) arg0) + 0x34)) = mathfRand__Fii_119370(0x78, 0x168);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_clapper_09", func_00119420);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_clapper_09", func_00119F08);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_clapper_09", func_00119F80);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_clapper_09", func_00119FE8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_clapper_09", func_0011A108);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_clapper_09", func_0011A358);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_clapper_09", func_0011A470);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_clapper_09", func_0011A550);

#include "m2c_macros.h"
M2C_UNK printf_11A860() __asm__("printf");

void func_0011A860(void* arg0, s32 arg1, s32 arg2) {
    if (arg1 == 0x1E15) {
        printf_11A860("Found the collector Visual\n");
        M2C_FIELD_V1(arg0, s32* , 0x9E4) = arg2;
    }
    if (arg1 == 0x1E16) {
        printf_11A860("Found the collector Teleport Visual\n");
        M2C_FIELD_V1(arg0, s32* , 0x9E8) = arg2;
    }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_clapper_09", func_0011A8D0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_clapper_09", func_0011ACA0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_clapper_09", func_0011AD70);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_clapper_09", func_0011ADE8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_clapper_09", func_0011AEF8);

#include "m2c_macros.h"
s32 func_0011B0B0(void) {
    return 0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_clapper_09", func_0011B0B8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_clapper_09", func_0011B1D8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_clapper_09", func_0011B308);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_clapper_09", func_0011B488);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_clapper_09", func_0011B730);

#include "m2c_macros.h"
M2C_UNK func_0011AD70_11B8F8() __asm__("func_0011AD70");

void func_0011B8F8(s32 arg0, s32 arg1, void* arg2, void* arg3) {
    M2C_FIELD(((M2C_FIELD(arg3, s32* , 0x10) * 0x7C) + arg0), s32* , 0x10) = 0;
    M2C_FIELD(M2C_FIELD(((M2C_FIELD(arg3, s32* , 0x10) * 0x7C) + arg0), void** , 0x34), s8* , 0xC) = 0;
    M2C_FIELD(arg2, s32* , 0x20BC) = -1;
    func_0011AD70_11B8F8(arg0, M2C_FIELD(arg3, s32* , 0x10));
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_clapper_09", func_0011B948);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_clapper_09", func_0011BBE8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_clapper_09", func_0011BD50);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_clapper_09", func_0011BFB8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_clapper_09", func_0011C098);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_clapper_09", func_0011C110);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_clapper_09", func_0011C150);
