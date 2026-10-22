#include "common.h"
#include "m2c_macros.h"

void Init__12Interactives(s32* arg0) {
    s32 var_a1;
    s32* var_v0;
    s32* var_v1;

    var_a1 = 0x7FF;
    var_v1 = arg0 + 0x800;
    var_v0 = arg0;
    do {
        *var_v0 = 0;
        var_a1 -= 1;
        *var_v1 = 0;
        var_v0 +=0x1;
        var_v1 +=0x1;
    } while (var_a1 >= 0);
    M2C_FIELD(arg0, s32* , 0x4000) = 1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/interact", Add__12Interactives16_interactiveTypeP13DbInteractiveP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/interact", SetInteractive__12InteractivesiP13DbInteractiveP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/interact", GetInteractive__12Interactivesi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/interact", DispatchHit__12InteractivesP8_fvectoriii);
