#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigiddebris", init__11RigidDebris);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigiddebris", takeHit__11RigidDebrisP12DestructiblefP8_fvectorP10TakeHitDat);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigiddebris", takeHit__11RigidDebrisP3_csfP8_fvectorP10TakeHitDat);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigiddebris", initFromDestructible__11RigidDebrisP12Destructible);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigiddebris", initFromCS__11RigidDebrisP3_cs);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigiddebris", setFriction__11RigidDebrisff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigiddebris", debrisDestructible__11RigidDebrisP12DestructiblefP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigiddebris", createInstance__11RigidDebris);

s32 destroyInstance__11RigidDebrisP11RigidDebris(void* arg0, void* arg1) {
    void* temp_v0;

    temp_v0 = M2C_FIELD(arg0, void** , 0x110);
    M2C_FIELD(temp_v0, s8* , 0xC) = 0;
    M2C_FIELD(M2C_FIELD(arg0, void** , 0x110), s8* , 0xD) = 0;
    M2C_FIELD(arg0, s32* , 8) = 0;
    return (s32) temp_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigiddebris", getExistingInstance__11RigidDebrisUi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigiddebris", updateAll__11RigidDebris);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigiddebris", initCS__11RigidDebrisP9_hierheadP8_fvectorT2);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigiddebris", configBox__11RigidDebrisfffffff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigiddebris", configBox__11RigidDebrisffff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigiddebris", configTent__11RigidDebrisfffif);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigiddebris", configPyramid__11RigidDebrisfff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigiddebris", configPole__11RigidDebrisfff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigiddebris", configPole__11RigidDebrisffff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigiddebris", configCylinder__11RigidDebrisfffP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigiddebris", configPointCloud__11RigidDebrisiffff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigiddebris", takeHit__11RigidDebrisfP8_fvectorP10TakeHitDat);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigiddebris", pointCollis__11RigidDebris);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigiddebris", cylinderCollis__11RigidDebris);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigiddebris", sphereCollis__11RigidDebris);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigiddebris", update__11RigidDebris);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigiddebris", _GLOBAL_$I$_11RigidDebris$COLLIS_FUNK);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/rigiddebris", func_0015B440);
