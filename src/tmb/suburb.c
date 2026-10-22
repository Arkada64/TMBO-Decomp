#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/suburb", SuburbInit__FP9_hierheadP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/suburb", SuburbInitAfter__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/suburb", SuburbUpdate__Fv);

void startUnlock__9CarUnlock_C_7(void*) __asm__("startUnlock__9CarUnlock");
extern u8 s_subCarUnlock_C_7[] __asm__("s_subCarUnlock");

void SuburbUnlockCar__Fv(void) {
    startUnlock__9CarUnlock_C_7(((u8*)s_subCarUnlock_C_7));
}

void cleanup__9CarUnlock_C_10(void*) __asm__("cleanup__9CarUnlock");
extern u8 s_subCarUnlock_C_10[] __asm__("s_subCarUnlock");

void suburbCleanupOnShutdown__Fv(void) {
    cleanup__9CarUnlock_C_10(((u8*)s_subCarUnlock_C_10));
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/suburb", func_00187520);
