#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ped", set__Q210Pedestrian10AnimConfigfff);

M2C_UNK loadAnimConfig__10Pedestrian_8_3() __asm__("loadAnimConfig__10Pedestrian");

void init__10Pedestrian(void) {
    loadAnimConfig__10Pedestrian_8_3();
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ped", loadAnimConfig__10Pedestrian);

void saveAnimConfig__10Pedestrian(void) {
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ped", init__10PedestrianP9_hierhead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ped", addAttachment__10PedestrianP9_hierhead);

void moveForward__10Pedestrianf(void) {
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ped", snapToGround__10Pedestrian);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ped", init__Q214CorpseStrategy6CorpseP3_csff);

int resolveCollision__9RigidBodyR8_fvectorT1T1fff_70_20(void*, void*, void*, void*, float, float, float) __asm__("resolveCollision__9RigidBodyR8_fvectorT1T1fff");
void mathfScaleVector__FP8_fvectorT0f_70_20(void*, void*, float) __asm__("mathfScaleVector__FP8_fvectorT0f");
extern u8 D_004F8CF0_70_20[4] __asm__("D_004F8CF0");
extern u8 D_004F8CF4_70_20[4] __asm__("D_004F8CF4");

s32 takeHit__Q214CorpseStrategy6CorpseR8_fvectorT1f(void* arg0, void* arg1, void* arg2, f32 fparg0) {
    u8 sp[0x10];
    mathfScaleVector__FP8_fvectorT0f_70_20(sp, arg2, fparg0 * 60.0f);
    return resolveCollision__9RigidBodyR8_fvectorT1T1fff_70_20(arg0, sp, arg1, arg2, 0.0f, (*(f32*)D_004F8CF0_70_20), (*(f32*)D_004F8CF4_70_20));
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ped", update__Q214CorpseStrategy6Corpse);

s32 isResting__Q214CorpseStrategy6Corpse(void* arg0) {
    return (M2C_FIELD(arg0, s32* , 0x4D0) < 0x15) ^ 1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ped", init__Q214CorpseStrategy9AccessoryP9_hierheadR8_fvectorPA3_f);

int resolveCollision__9RigidBodyR8_fvectorT1T1fff_70_35(void*, void*, void*, void*, float, float, float) __asm__("resolveCollision__9RigidBodyR8_fvectorT1T1fff");
void mathfScaleVector__FP8_fvectorT0f_70_35(void*, void*, float) __asm__("mathfScaleVector__FP8_fvectorT0f");
extern u8 D_004F8D0C_70_35[4] __asm__("D_004F8D0C");
extern u8 D_004F8D10_70_35[4] __asm__("D_004F8D10");

s32 takeHit__Q214CorpseStrategy9AccessoryR8_fvectorT1f(void* arg0, void* arg1, void* arg2, f32 fparg0) {
    u8 sp[0x10];
    mathfScaleVector__FP8_fvectorT0f_70_35(sp, arg2, fparg0 * 60.0f);
    return resolveCollision__9RigidBodyR8_fvectorT1T1fff_70_35(arg0 + 0x10, sp, arg1, arg2, 0.0f, (*(f32*)D_004F8D0C_70_35), (*(f32*)D_004F8D10_70_35));
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ped", update__Q214CorpseStrategy9Accessory);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ped", init__14CorpseStrategy);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ped", init__14CorpseStrategyP10Pedestrian);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ped", takeHit__14CorpseStrategyP8_fvectorii);

s32 isResting__Q214CorpseStrategy6Corpse_5C_50(void*) __asm__("isResting__Q214CorpseStrategy6Corpse");
void update__Q214CorpseStrategy6Corpse_5C_50(void*) __asm__("update__Q214CorpseStrategy6Corpse");
void update__Q214CorpseStrategy9Accessory_5C_50(void*) __asm__("update__Q214CorpseStrategy9Accessory");

void update__14CorpseStrategy(void* arg0) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 var_v0;

    temp_a0 = M2C_FIELD(arg0, s32* , 8);
    var_v0 = 0;
    if (temp_a0 != 0) {
        var_v0 = isResting__Q214CorpseStrategy6Corpse_5C_50(temp_a0) == 0;
    }
    if (var_v0 != 0) {
        update__Q214CorpseStrategy6Corpse_5C_50(M2C_FIELD(arg0, s32* , 8));
        temp_a0_2 = M2C_FIELD(arg0, s32* , 0xC);
        if (temp_a0_2 != 0) {
            update__Q214CorpseStrategy9Accessory_5C_50(temp_a0_2);
        }
    }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ped", deactivate__14CorpseStrategy);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ped", init__7PedPimp);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ped", addPedEpNode__7PedPimpP9_hierhead);

int allocPedType__7PedPimpi_20_61(void*, int) __asm__("allocPedType__7PedPimpi");
s32 allocPedDbId__7PedPimpi(void* arg0, s32 arg1) {
    return allocPedType__7PedPimpi_20_61((void* ) ((s32) (arg0 - 0xBB8) >> 3), arg1);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ped", allocPedType__7PedPimpi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ped", freePed__7PedPimpP10Pedestrian);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ped", getPedIndex__7PedPimpP10Pedestrian);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ped", getPedPointer__7PedPimpUc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ped", _GLOBAL_$I$_10Pedestrian$s_animConfig);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ped", freeAccessory__14CorpseStrategyPQ214CorpseStrategy9Accessory);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ped", grabAccessory__14CorpseStrategy);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ped", freeCorpse__14CorpseStrategyPQ214CorpseStrategy6Corpse);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ped", grabCorpse__14CorpseStrategy);

int isResting__Q214CorpseStrategy6Corpse_2C_93(void*) __asm__("isResting__Q214CorpseStrategy6Corpse");
s32 isDead__14CorpseStrategy(void* arg0) {
    s32 var_v0;
    void* temp_a0;

    temp_a0 = M2C_FIELD(arg0, void** , 8);
    var_v0 = 0;
    if (temp_a0 != NULL) {
        var_v0 = isResting__Q214CorpseStrategy6Corpse_2C_93(temp_a0) != 0;
    }
    return var_v0;
}

int isResting__Q214CorpseStrategy6Corpse_2C_96(void*) __asm__("isResting__Q214CorpseStrategy6Corpse");
s32 isDying__14CorpseStrategy(void* arg0) {
    s32 var_v0;
    void* temp_a0;

    temp_a0 = M2C_FIELD(arg0, void** , 8);
    var_v0 = 0;
    if (temp_a0 != NULL) {
        var_v0 = isResting__Q214CorpseStrategy6Corpse_2C_96(temp_a0) == 0;
    }
    return var_v0;
}

s32 isActive__14CorpseStrategy(void* arg0) {
    return M2C_FIELD(arg0, s32* , 8) != 0;
}

M2C_UNK __rtti_si_4C_100() __asm__("__rtti_si");
M2C_UNK __tfQ210Pedestrian8Strategy_4C_100() __asm__("__tfQ210Pedestrian8Strategy");
extern u8 D_004E7428_4C_100[] __asm__("D_004E7428");
extern u8 __ti14CorpseStrategy_4C_100[] __asm__("__ti14CorpseStrategy");
extern u8 __tiQ210Pedestrian8Strategy_4C_100[4] __asm__("__tiQ210Pedestrian8Strategy");

s32* __tf14CorpseStrategy(void) {
    if ((*(s32*)__ti14CorpseStrategy_4C_100) == 0) {
        __tfQ210Pedestrian8Strategy_4C_100();
        __rtti_si_4C_100(((u8*)__ti14CorpseStrategy_4C_100), ((u8*)D_004E7428_4C_100), ((u8*)__tiQ210Pedestrian8Strategy_4C_100));
    }
    return ((u8*)__ti14CorpseStrategy_4C_100);
}

u32 func_001539C8(void* arg0) {
    return (u32) **M2C_FIELD(arg0, u32*** , 4) >> 0x12;
}

M2C_UNK __rtti_user_3C_104() __asm__("__rtti_user");
extern u8 D_004E7440_3C_104[] __asm__("D_004E7440");
extern u8 __tiQ210Pedestrian8Strategy_3C_104[4] __asm__("__tiQ210Pedestrian8Strategy");

s32* __tfQ210Pedestrian8Strategy(void) {
    if ((*(s32*)__tiQ210Pedestrian8Strategy_3C_104) == 0) {
        __rtti_user_3C_104(((u8*)__tiQ210Pedestrian8Strategy_3C_104), ((u8*)D_004E7440_3C_104));
    }
    return ((u8*)__tiQ210Pedestrian8Strategy_3C_104);
}
