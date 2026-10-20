#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/CsList", func_00247B28);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/CsList", allocateCsListNode__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/CsList", deallocCsListNode__FP10CsListNode);

#include "m2c_macros.h"
void* allocateCsListNode__Fv_tP3_cs() __asm__("allocateCsListNode__Fv");

void pushCsFront__6CsListP3_cs(void** arg0, s32 arg1) {
    void* temp_v0;

    temp_v0 = allocateCsListNode__Fv_tP3_cs();
    M2C_FIELD_V1(temp_v0, s32* , 4) = arg1;
    M2C_FIELD_V1(temp_v0, void** , 0) = (void* ) *arg0;
    *arg0 = temp_v0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/CsList", removeCs__6CsListP3_cs);
