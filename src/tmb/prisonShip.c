#include "common.h"
#include "m2c_macros.h"

void prisonShipInitBefore__Fv(void) {
}

extern u8 skyRocking_1C_2[4] __asm__("skyRocking");

void prisonShipParseNode__FP9_hierhead(s32* arg0) {
    if ((*arg0 & 0x3F) == 4) {
        (*(s32**)skyRocking_1C_2) = arg0;
    }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/prisonShip", prisonShipInitAfter__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/prisonShip", prisonShipUpdate__Fv);
