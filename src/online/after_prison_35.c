#include "common.h"

#include "m2c_macros.h"
M2C_UNK plightDestroy__FP11_pointlight_17F230() __asm__("plightDestroy__FP11_pointlight");

void func_0017F230(void* arg0) {
    s32 temp_a0;

    temp_a0 = M2C_FIELD_V1(arg0, s32* , 0x10);
    if (temp_a0 != 0) {
        plightDestroy__FP11_pointlight_17F230(temp_a0);
    }
}

#include "m2c_macros.h"
M2C_UNK startUnlock__9CarUnlock_17F258() __asm__("startUnlock__9CarUnlock");
extern M2C_UNK D_004FFDF0_17F258 __asm__("D_004FFDF0");

void func_0017F258(void) {
    startUnlock__9CarUnlock_17F258(&D_004FFDF0_17F258);
}

#include "m2c_macros.h"
M2C_UNK func_0012DDB8_17F278() __asm__("func_0012DDB8");
extern M2C_UNK D_004FFDF0_17F278 __asm__("D_004FFDF0");

void func_0017F278(void) {
    func_0012DDB8_17F278(&D_004FFDF0_17F278);
}
