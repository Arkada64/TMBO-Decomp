#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/pkt", pktInitVu1Dma__FP9Vu1DmaPktP6QwDataT1);

void pktClipUVScroll__FPfT0(f32* arg0, f32* arg1) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 var_f0;

    temp_f1 = *arg0;
    if (temp_f1 >= 0.5f) {
        var_f0 = temp_f1 - 1.0f;
        goto block_4;
    }
    if (temp_f1 <= -0.5f) {
        var_f0 = temp_f1 + 1.0f;
block_4:
        *arg0 = var_f0;
    }
    temp_f1_2 = *arg1;
    if (temp_f1_2 > 0.5f) {
        *arg1 = temp_f1_2 - 1.0f;
        return;
    }
    if (temp_f1_2 < -0.5f) {
        *arg1 = temp_f1_2 + 1.0f;
    }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/pkt", pktAddVu1Obj__FP9Vu1DmaPktP6QwDataP11_hierobjecti);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/pkt", pktGetMatrix__FPA3_f);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/pkt", pktGetLightDir__FPA3_f);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/pkt", pktAddVu1Tex__FP9Vu1DmaPktPUi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/pkt", pktAddPlaceHolderTex__FP9Vu1DmaPkt);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/pkt", pktFlushVu1Objs__FP9Vu1DmaPkt);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/pkt", pktLinkAlphaObj__FP9Vu1DmaPktP6QwDataf);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/pkt", pktInitReverseAlphaOT__FP9Vu1DmaPktP6QwDataPP6QwData);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/pkt", pktAttachAlphaOT__FP9Vu1DmaPktT0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/pkt", pktCacheForAsm__FP6QwData);
