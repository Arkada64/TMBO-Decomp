#include "common.h"

#include "m2c_macros.h"
volatile char pktInitVu1Dma__FP9Vu1DmaPktP6QwDataT1(void *arg0, s32 arg1, s32 arg2, s16 arg3)
{
  *((s16 *) (((u8 *) arg0) + 0x18)) = arg3;
  *((s32 *) (0 + ((u8 *) arg0))) = arg1;
  *((s32 *) (((u8 *) arg0) + 4)) = arg2;
  *((s32 *) (((u8 *) arg0) + 8)) = arg1;
  *((s32 *) (((u8 *) arg0) + 0xC)) = 0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/pkt", pktClipUVScroll__FPfT0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/pkt", pktAddVu1Obj__FP9Vu1DmaPktP6QwDataP11_hierobjecti);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/pkt", pktGetLightDir__FPA3_f);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/pkt", func_0022DD50);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/pkt", pktAddVu1Tex__FP9Vu1DmaPktPUi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/pkt", pktAddPlaceHolderTex__FP9Vu1DmaPkt);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/pkt", func_0022DDC8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/pkt", pktLinkAlphaObj__FP9Vu1DmaPktP6QwDataf);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/pkt", pktInitReverseAlphaOT__FP9Vu1DmaPktP6QwDataPP6QwData);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/pkt", func_0022DF48);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/pkt", pktCacheForAsm__FP6QwData);
