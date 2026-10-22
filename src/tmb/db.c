#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/db", dbInitDb__FP9_dbheader10_vramAddrs);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/db", dbProcInteractive__FP9_hierheadP8_fvectorPA3_f);

void hierSetCsEpNode__FP3_csP9_hierhead_54_11(void*, void*) __asm__("hierSetCsEpNode__FP3_csP9_hierhead");
void hierCsAddToCsList__FP3_cs_54_11(void*) __asm__("hierCsAddToCsList__FP3_cs");
int csCreate__Fv_54_11(void) __asm__("csCreate__Fv");
s32 dbGetCSForModel__FP9_hierhead(void* arg0) {
    s32 temp_v0;

    temp_v0 = csCreate__Fv_54_11();
    if (temp_v0 != 0) {
        M2C_FIELD(temp_v0, s8* , 0xC) = 1;
        hierSetCsEpNode__FP3_csP9_hierhead_54_11((void* ) temp_v0, arg0);
        hierCsAddToCsList__FP3_cs_54_11((void* ) temp_v0);
    }
    return temp_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/db", prisonAddNode__7TheGameiP9_hierhead);
