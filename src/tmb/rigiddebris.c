#include "common.h"

#include "m2c_macros.h"
M2C_UNK func_001A8A28_181D38() __asm__("func_001A8A28");
extern M2C_UNK D_00330D30_181D38 __asm__("D_00330D30");

void func_00181D38(void) {
    M2C_UNK* var_a0;
    s32 var_v1;

    var_v1 = 0x14;
    var_a0 = &D_00330D30_181D38;
    do {
        M2C_FIELD(var_a0, s32* , 8) = 0;
        var_v1 -= 1;
        M2C_FIELD(var_a0, s32* , 0x110) = 0;
        M2C_FIELD(var_a0, s32* , 0x70C) = 0;
        var_a0 +=0x1c4;
    } while (var_v1 != 0);
    func_001A8A28_181D38(var_a0);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/rigiddebris", takeHit__11RigidDebrisP12DestructiblefP8_fvectorP10TakeHitDat);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/rigiddebris", func_00181E98);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/rigiddebris", func_00182178);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/rigiddebris", setFriction__11RigidDebrisff);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/rigiddebris", func_001822A0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/rigiddebris", createInstance__11RigidDebris);

#include "m2c_macros.h"
void destroyInstance__11RigidDebrisP11RigidDebris(void* arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void** , 0x110), s8* , 0xC) = 0;
    M2C_FIELD(M2C_FIELD(arg0, void** , 0x110), s8* , 0xD) = 0;
    M2C_FIELD(arg0, s32* , 8) = 0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/rigiddebris", getExistingInstance__11RigidDebrisUi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/rigiddebris", func_00182528);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/rigiddebris", initCS__11RigidDebrisP9_hierheadP8_fvectorT2);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/rigiddebris", configBox__11RigidDebrisfffffff);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/rigiddebris", func_001827F0);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/rigiddebris", D_004E9A30);
