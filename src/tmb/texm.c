#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", texmInit__F10_vramAddrs);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", texmResInit__F10_vramAddrsP6QwData);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", texmLoadResTexture__FP6QwData);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", texmLoadTexture__FP6QwData);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", texmSetupTexture__FiiiiiP6QwDataii);

extern u8 texInfo_20_19[] __asm__("texInfo");

void texmGetTextureDMATagAddress__FiPPUi(s32 arg0, s32 *arg1)
{
  u8 *new_var;
  s32 *new_var2;
  new_var = texInfo_20_19;
  new_var2 = (arg0 * 0x10) + new_var;
  *arg1 = *new_var2;
  *(new_var2 = arg1) = (*arg1) + 0x10;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", texmGetTextureAddrs__FiP6QwDataP9Vu1DmaPkt);

extern u8 displayBuffer_14_25[4] __asm__("displayBuffer");

void texmPrepTexInfoZero__FP11tGS_DISPFB2(s32* arg0) {
    (*(s32*)displayBuffer_14_25) = (*arg0 & 0x1FF) << 5;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", texmParticleTexture__FiP6QwDataT1);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", texmActivateTexture__FiP6QwDataP9Vu1DmaPkt);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", texmActivateBitBlitTexture__FiP6QwData);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", texmSetMipMapTbl__FiP6QwDataP9Vu1DmaPkt);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", texmUpdateLastUsed__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", texmFindVramSpace__Fi);

extern u8 texInfo_20_44[] __asm__("texInfo");

s32 texmGetMipLevels__Fi(s32 arg0)
{
  u8 *new_var2;
  int new_var;
  new_var = 7;
  new_var2 = (u8 *) ((arg0 * 0x10) + ((u8 *) texInfo_20_44));
  return (((u32) (*((u32 *) (new_var2 + 4)))) >> 0x19) & new_var;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", texmAllocateBinSpace__FP8_texbins);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", texmAlreadyGotBin__FP8_texbinsUiPUs);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", texmFindNextLargestTexSize__FP8_texbinsUiPUs);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", texmMatchingBlkSizeInFirstFile__FUiP8_texfile);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", __tcf_0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", texmRelocate__FPc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", texmResCheckForData__FPc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", texmResRelocate__FPc10_vramAddrs);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", texmCacheForAsm__FP6QwData);

extern u8 texLastUsedCnt_C_81[4] __asm__("texLastUsedCnt");

void texmRestoreCache__FP6QwData(void* arg0) {
    (*(s32*)texLastUsedCnt_C_81) = M2C_FIELD(arg0, s32* , 0x44);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", func_001FA830);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", func_001FA898);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", _S_oom_malloc__t23__malloc_alloc_template1i0Ui);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", _S_chunk_alloc__t24__default_alloc_template2b0i0UiRi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", _S_refill__t24__default_alloc_template2b0i0Ui);

M2C_UNK _M_put_node__t19_Rb_tree_alloc_base3Zt4pair2ZCUiZUsZt9allocator1ZUsb1Pt13_Rb_tree_node1Zt4pair2ZCUiZUs_8_94() __asm__("_M_put_node__t19_Rb_tree_alloc_base3Zt4pair2ZCUiZUsZt9allocator1ZUsb1Pt13_Rb_tree_node1Zt4pair2ZCUiZUs");

void destroy_node__t8_Rb_tree5ZUiZt4pair2ZCUiZUsZt10_Select1st1Zt4pair2ZCUiZUsZt4less1ZUiZt9allocator1ZUsPt13_Rb_tree_node1Zt4pair2ZCUiZUs(void) {
    _M_put_node__t19_Rb_tree_alloc_base3Zt4pair2ZCUiZUsZt9allocator1ZUsb1Pt13_Rb_tree_node1Zt4pair2ZCUiZUs_8_94();
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", _M_erase__t8_Rb_tree5ZUiZt4pair2ZCUiZUsZt10_Select1st1Zt4pair2ZCUiZUsZt4less1ZUiZt9allocator1ZUsPt13_Rb_tree_node1Zt4pair2ZCUiZUs);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", deallocate__t12simple_alloc2Zt13_Rb_tree_node1Zt4pair2ZCUsZUsZt24__default_alloc_template2b0i0Pt13_Rb_tree_node1Zt4pair2ZCUsZUsUi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", _M_put_node__t19_Rb_tree_alloc_base3Zt4pair2ZCUsZUsZt9allocator1ZUsb1Pt13_Rb_tree_node1Zt4pair2ZCUsZUs);

M2C_UNK _M_put_node__t19_Rb_tree_alloc_base3Zt4pair2ZCUsZUsZt9allocator1ZUsb1Pt13_Rb_tree_node1Zt4pair2ZCUsZUs_8_106() __asm__("_M_put_node__t19_Rb_tree_alloc_base3Zt4pair2ZCUsZUsZt9allocator1ZUsb1Pt13_Rb_tree_node1Zt4pair2ZCUsZUs");

void destroy_node__t8_Rb_tree5ZUsZt4pair2ZCUsZUsZt10_Select1st1Zt4pair2ZCUsZUsZt4less1ZUsZt9allocator1ZUsPt13_Rb_tree_node1Zt4pair2ZCUsZUs(void) {
    _M_put_node__t19_Rb_tree_alloc_base3Zt4pair2ZCUsZUsZt9allocator1ZUsb1Pt13_Rb_tree_node1Zt4pair2ZCUsZUs_8_106();
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", _M_erase__t8_Rb_tree5ZUsZt4pair2ZCUsZUsZt10_Select1st1Zt4pair2ZCUsZUsZt4less1ZUsZt9allocator1ZUsPt13_Rb_tree_node1Zt4pair2ZCUsZUs);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", _M_insert__t8_Rb_tree5ZUiZt4pair2ZCUiZUsZt10_Select1st1Zt4pair2ZCUiZUsZt4less1ZUiZt9allocator1ZUsP18_Rb_tree_node_baseT1RCt4pair2ZCUiZUs);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", insert_unique__t8_Rb_tree5ZUiZt4pair2ZCUiZUsZt10_Select1st1Zt4pair2ZCUiZUsZt4less1ZUiZt9allocator1ZUsRCt4pair2ZCUiZUs);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", _M_insert__t8_Rb_tree5ZUsZt4pair2ZCUsZUsZt10_Select1st1Zt4pair2ZCUsZUsZt4less1ZUsZt9allocator1ZUsP18_Rb_tree_node_baseT1RCt4pair2ZCUsZUs);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", insert_unique__t8_Rb_tree5ZUsZt4pair2ZCUsZUsZt10_Select1st1Zt4pair2ZCUsZUsZt4less1ZUsZt9allocator1ZUsRCt4pair2ZCUsZUs);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", _$_t13_Rb_tree_base2Zt4pair2ZCUsZUsZt9allocator1ZUs);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", _$_t8_Rb_tree5ZUsZt4pair2ZCUsZUsZt10_Select1st1Zt4pair2ZCUsZUsZt4less1ZUsZt9allocator1ZUs);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", _$_t3map4ZUsZUsZt4less1ZUsZt9allocator1ZUs);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", _GLOBAL_$D$texmDupMap);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", _$_t9allocator1Zt4pair2ZCUsZUs);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", _GLOBAL_$I$texmDupMap);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", _$_t9allocator1Zt4pair2ZCUiZUs);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", _M_put_node__t19_Rb_tree_alloc_base3Zt4pair2ZCUiZUsZt9allocator1ZUsb1Pt13_Rb_tree_node1Zt4pair2ZCUiZUs);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", deallocate__t12simple_alloc2Zt13_Rb_tree_node1Zt4pair2ZCUiZUsZt24__default_alloc_template2b0i0Pt13_Rb_tree_node1Zt4pair2ZCUiZUsUi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", deallocate__t24__default_alloc_template2b0i0PvUi);

M2C_UNK free_8_154() __asm__("free");

void deallocate__t23__malloc_alloc_template1i0PvUi(void) {
    free_8_154();
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", _$_t3map4ZUiZUsZt4less1ZUiZt9allocator1ZUs);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", _$_t8_Rb_tree5ZUiZt4pair2ZCUiZUsZt10_Select1st1Zt4pair2ZCUiZUsZt4less1ZUiZt9allocator1ZUs);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/texm", _$_t13_Rb_tree_base2Zt4pair2ZCUiZUsZt9allocator1ZUs);
