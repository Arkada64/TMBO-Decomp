#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/drivein", InitDriveInBefore__7DriveIn);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/drivein", InitDriveInAfter__7DriveIn);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/drivein", func_0012DF00);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/drivein", func_0012E040);

#include "m2c_macros.h"
void AddEpNode__7DriveIniP9_hierhead(void* arg0, s32 arg1, s32 arg2) {
    if (arg1 == 0x179F) {
        M2C_FIELD_V1(arg0, s32* , 0x58) = arg2;
    }
}
