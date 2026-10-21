#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/font", func_002026D0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/font", fontDmaFontData__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/font", func_002029D8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/font", func_00202AD8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/font", func_00202B30);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/font", fontSetColor__Fiiii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/font", fontClearCutOut__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/font", fontSetCutOut__Fi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/font", func_00202C58);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/font", fontSetSize__Fii);

#include "m2c_macros.h"
extern M2C_UNK D_00505EF0_h__Fii __asm__("D_00505EF0");

void fontSetCharWidth__Fii(s32 arg0, s16 arg1)
{
  u8 *new_var;
  ;
  new_var = &D_00505EF0_h__Fii;
  *((s16 *) (((u8 *) ((arg0 << 5) + new_var)) + 4)) = arg1;
}

#include "m2c_macros.h"
M2C_UNK fontSetSize__Fii_ze__Fi() __asm__("fontSetSize__Fii");
M2C_UNK fontSetSpacing__Fii_ze__Fi() __asm__("fontSetSpacing__Fii");

void fontSetDefaultSize__Fi(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0:
        fontSetSize__Fii_ze__Fi(0, 0x10);
        fontSetSpacing__Fii_ze__Fi(0, 2);
        return;
    case 1:
        fontSetSize__Fii_ze__Fi(1, 0xC);
        fontSetSpacing__Fii_ze__Fi(1, 1);
        break;
    }
}

#include "m2c_macros.h"
#include "m2c_macros.h"
extern M2C_UNK D_00505EF0_g__Fii __asm__("D_00505EF0");

void fontSetSpacing__Fii(s32 arg0, s32 arg1)
{
  void *temp_a0;
  temp_a0 = &D_00505EF0_g__Fii;
  ;
  *((s16 *) (((u8 *) ((arg0 << 5) + temp_a0)) + 0xE)) = (s16) ((*((u16 *) (((arg0 << 5) + temp_a0) + 8))) + (arg1 * 0x10));
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/font", fontStringWidth__FiPc);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/font", func_00202DF8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/font", fontSpritePrintCenteredXY__FiiiPc);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/font", fontSpritePrintCentered__FiPc);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/font", func_00202F48);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/font", fontSetCharSizesInPixels__Fiiiii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/font", fontSetCharSizesInSubPixels__Fiiiii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/font", fontSetCursorAtColumnRow__Fiii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/font", fontSetCursorAtRowColumn__Fiii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/font", fontSetCursorAtPixel__Fiii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/font", fontSetCursorAtSubPixel__Fiii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/font", func_00203150);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/font", func_00203290);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/font", fontInitPacket__FP6QwData10_vramAddrs);
