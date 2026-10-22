#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/zip", zipCrc32__FUlPCUcl);

s64 zipCrc32__FUlPCUcl_58_5() __asm__("zipCrc32__FUlPCUcl");
extern u8 G_crc32val_58_5[4] __asm__("G_crc32val");
extern u8 G_outSize_58_5[4] __asm__("G_outSize");
extern u8 outFileBuf_58_5[4] __asm__("outFileBuf");

s32 zipFlush__FUl(s64 arg0) {
    (*(s64*)G_crc32val_58_5) = zipCrc32__FUlPCUcl_58_5((*(s64*)G_crc32val_58_5), (*(s32*)outFileBuf_58_5), arg0);
    (*(s32*)outFileBuf_58_5) += (s64) (arg0 << 0x20) >> 0x20;
    (*(s64*)G_outSize_58_5) -= arg0;
    return 0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/zip", zipCheckHeader__FPUi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/zip", zipInflateCodes__FP4huftT0ii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/zip", zipFreeHuffmanTable__FP4huft);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/zip", zipBuildHuffmanTable__FPCUiUiUiPCUsT3PP4huftPi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/zip", zipInflateBlockStored__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/zip", zipInflateBlockFixed__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/zip", zipInflateBlockDynamic__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/zip", zipInflateBlock__FPi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/zip", zipInflateAll__FPcPv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/zip", zipGetChar__Fv);

extern u8 outFileBuf_C_39[4] __asm__("outFileBuf");
extern u8 outFileWindow_C_39[4] __asm__("outFileWindow");

void _GLOBAL_$I$whichHalfMeg(void) {
    (*(s32*)outFileWindow_C_39) = (*(s32*)outFileBuf_C_39);
}
