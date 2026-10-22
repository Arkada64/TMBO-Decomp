#include "common.h"
#include "m2c_macros.h"

void Death2Init__Fv(void) {
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/death2", Death2InitAfter__Fv);

void thunderstormUpdate__Fv_8_5(void) __asm__("thunderstormUpdate__Fv");

void Death2Update__Fv(void) {
    thunderstormUpdate__Fv_8_5();
}
