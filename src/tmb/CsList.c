#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/CsList", InitCsListArray__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/CsList", allocateCsListNode__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/CsList", deallocCsListNode__FP10CsListNode);

void* allocateCsListNode__Fv_40_13(void) __asm__("allocateCsListNode__Fv");

void pushCsFront__6CsListP3_cs(void** arg0, s32 arg1) {
    void* temp_v0;

    temp_v0 = allocateCsListNode__Fv_40_13();
    M2C_FIELD(temp_v0, s32* , 4) = arg1;
    M2C_FIELD(temp_v0, void** , 0) = (void* ) *arg0;
    *arg0 = temp_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/CsList", removeCs__6CsListP3_cs);
