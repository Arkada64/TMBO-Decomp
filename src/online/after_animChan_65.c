#include "common.h"

#include "m2c_macros.h"
extern M2C_UNK D_00465E68_1FE0B8 __asm__("D_00465E68");

void func_001FE0B8(s32 arg0) {
    *((arg0 * 0x1) + &D_00465E68_1FE0B8) = 0;
}

#include "m2c_macros.h"
M2C_UNK __11MemoryStackPvUi_1FE0D0() __asm__("__11MemoryStackPvUi");
extern M2C_UNK D_00465E50_1FE0D0 __asm__("D_00465E50");
extern M2C_UNK D_00500D80_1FE0D0 __asm__("D_00500D80");

void func_001FE0D0(s32 arg0, s32 arg1) {
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        __11MemoryStackPvUi_1FE0D0(&D_00465E50_1FE0D0, &D_00500D80_1FE0D0, 0x5000);
    }
}

#include "m2c_macros.h"
M2C_UNK func_001FE0D0_1FE108() __asm__("func_001FE0D0");

void func_001FE108(void) {
    func_001FE0D0_1FE108(1, 0xFFFF);
}

#include "m2c_macros.h"
M2C_UNK boundFAngle__FPf_1FE128() __asm__("boundFAngle__FPf");

void func_001FE128(s32 arg0) {
    boundFAngle__FPf_1FE128();
    boundFAngle__FPf_1FE128(arg0 + 4);
    boundFAngle__FPf_1FE128(arg0 + 8);
}
