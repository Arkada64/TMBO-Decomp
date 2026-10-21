#include "common.h"

#include "m2c_macros.h"
s32 mathfRand__Fii_17F8D0() __asm__("mathfRand__Fii");
s32 timerGetFieldCount__Fv_17F8D0() __asm__("timerGetFieldCount__Fv");

void func_0017F8D0(void *arg0)
{
  s32 temp_v0;
  s32 temp_v0_2;
  *((s32 *) (((u8 *) arg0) + 0x10)) = 0;
  *((s32 *) (((u8 *) arg0) + 0xC)) = 0;
  *((s32 *) (((u8 *) arg0) + 8)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x24)) = 0;
  *((s32 *) (((u8 *) arg0) + 4)) = 1;
  *((s32 *) (((u8 *) arg0) + 0x20)) = -1;
  *((s32 *) (((u8 *) arg0) + 0x18)) = 1;
  temp_v0 = mathfRand__Fii_17F8D0(0x3C, 0xB4) * 0x3C;
  *((s32 *) (((u8 *) arg0) + 0x64)) = 0x258;
  *((s32 *) (((u8 *) arg0) + 0x60)) = temp_v0;
  temp_v0_2 = mathfRand__Fii_17F8D0(0x258, 0x708);
  *((s32 *) (((u8 *) arg0) + 0x70)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x6C)) = 0x78;
  *((f32 *) (((u8 *) arg0) + 0x34)) = 1.0f;
  *((s32 *) (((u8 *) arg0) + 0x68)) = temp_v0_2;
  *((s32 *) (((u8 *) arg0) + 0x3C)) = timerGetFieldCount__Fv_17F8D0();
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_healthstand_38", func_0017F960);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_healthstand_38", func_0017FF60);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_healthstand_38", func_0017FFD0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_healthstand_38", func_00180070);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_healthstand_38", func_00180180);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_healthstand_38", func_001803B8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_healthstand_38", func_001804D0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_healthstand_38", func_001805B0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_healthstand_38", func_00180658);

#include "m2c_macros.h"
#include "m2c_macros.h"
void func_001808B0(void *arg0, s32 arg1, s32 arg2)
{
  u32 temp_v1;
  unsigned int new_var;
  temp_v1 = arg1 - 0x1E1E;
  if (temp_v1 < 0xCU)
  {
    new_var = temp_v1 * 4;
    *((s32 *) (((u8 *) arg0) + 0)) = (s32) ((*((s32 *) (((u8 *) arg0) + ((*((s32 *) (((u8 *) arg0) + 0))) * 0)))) + 1);
    *((s32 *) (((u8 *) (arg0 + new_var)) + 0x604)) = arg2;
    return;
  }
  if (arg1 == 0x1E17)
  {
    *((s32 *) (((u8 *) arg0) + 0x634)) = arg2;
  }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_healthstand_38", func_001808F0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_healthstand_38", func_00180C30);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_healthstand_38", func_00180D00);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_healthstand_38", func_00180D78);
