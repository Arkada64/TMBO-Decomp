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

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/font", fontSetCharWidth__Fii);

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

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/font", fontSetSpacing__Fii);

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
