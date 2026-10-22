#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hoserInfo", hoserInfoInit__FP9HoserInfo);

s32 hoserFindFreeBookmark__FP9HoserInfo(void *arg0)
{
  int new_var2;
  s32 var_a1;
  s32 var_a2;
  s32 *var_v1;
  void *new_var;
  var_a2 = -1;
  var_a1 = 0;
  new_var = arg0 + 0x80;
  new_var2 = -1;
  var_v1 = new_var;
  do
  {
    if ((*var_v1) == new_var2)
    {
      var_a2 = var_a1;
      var_v1 = arg0 + 0x1340;
      var_a1 = 0x32;
    }
    var_a1 += 1;
    var_v1 += 0x18;
  }
  while (var_a1 < 0x32);
  return var_a2;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hoserInfo", hoserAddBookmark__FP9HoserInfoPA3_fP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hoserInfo", hoserDeleteBookmark__FP9HoserInfo);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hoserInfo", hoserDeleteAllBookmarks__FP9HoserInfo);

s32 hoserGotoBookmark__FP9HoserInfo(void* arg0) {
    return 0;
}

extern u8 nextBookmark_30_18[4] __asm__("nextBookmark");

s32 hoserNextBookmark__FP9HoserInfo(void* arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(((M2C_FIELD(arg0, s32* , 0x4C) * 0x60) + arg0), s32* , 0x84);
    (*(s32*)nextBookmark_30_18) = temp_v0;
    if (temp_v0 != -1) {
        M2C_FIELD(arg0, s32* , 0x4C) = temp_v0;
    }
    return (*(s32*)nextBookmark_30_18);
}

extern u8 prevBookmark_30_21[4] __asm__("prevBookmark");

s32 hoserPrevBookmark__FP9HoserInfo(void* arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(((M2C_FIELD(arg0, s32* , 0x4C) * 0x60) + arg0), s32* , 0x88);
    (*(s32*)prevBookmark_30_21) = temp_v0;
    if (temp_v0 != -1) {
        M2C_FIELD(arg0, s32* , 0x4C) = temp_v0;
    }
    return (*(s32*)prevBookmark_30_21);
}

f32 mathfDist3__FP8_fvectorT0_C4_26(void*, void*) __asm__("mathfDist3__FP8_fvectorT0");
extern u8 D_004FA644_C4_26[4] __asm__("D_004FA644");

s32 hoserClosestBookmark__FP9HoserInfoP8_fvector(void* arg0, s32 arg1) {
    f32 temp_f0;
    f32 var_f20;
    s32 var_s1;
    s32 var_s2;
    s32 var_s4;
    s32* var_s0;

    var_s4 = -1;
    var_s2 = 0;
    var_s1 = arg0 + 0xD0;
    var_s0 = arg0 + 0x80;
    var_f20 = (*(f32*)D_004FA644_C4_26);
    do {
        if (*var_s0 != -1) {
            temp_f0 = mathfDist3__FP8_fvectorT0_C4_26(arg1, var_s1);
            if (temp_f0 < var_f20) {
                var_f20 = temp_f0;
                var_s4 = var_s2;
            }
        }
        var_s2 += 1;
        var_s1 += 0x60;
        var_s0 +=0x18;
    } while (var_s2 < 0x32);
    if (var_s4 != -1) {
        M2C_FIELD(arg0, s32* , 0x4C) = var_s4;
    }
    return var_s4;
}

extern u8 hoserInfo_C_30[] __asm__("hoserInfo");

s32 hoserGetHoserInfo__Fv(void) {
    return (s32) ((u8*)hoserInfo_C_30);
}
