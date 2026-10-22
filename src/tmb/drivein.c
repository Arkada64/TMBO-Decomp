#include "common.h"
#include "m2c_macros.h"

void InitDriveInBefore__7DriveIn(void *arg0)
{
  u8 *new_var;
  *((s32 *) (((u8 *) arg0) + 0x50)) = 0;
  *((s32 *) (((u8 *) arg0) - -0x54)) = 0;
 do { } while (0);
  *((s32 *) (new_var = ((u8 *) arg0) + 0x58)) = 0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/drivein", InitDriveInAfter__7DriveIn);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/drivein", UpdateDriveIn__7DriveIn);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/drivein", UpdateFalling__7DriveIn);

s32 AddEpNode__7DriveIniP9_hierhead(void* arg0, s32 arg1, void* arg2) {
    if (arg1 == 0x179F) {
        M2C_FIELD(arg0, void** , 0x58) = arg2;
    }
    return 0x179F;
}
