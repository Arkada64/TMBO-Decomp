#include "common.h"
#include "m2c_macros.h"

s32 isIn__15PedAttractGroupP8_fvector(void* arg0, void* arg1) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    s32 var_v0;

    temp_f1 = M2C_FIELD(arg1, f32* , 0);
    var_v0 = 0;
    if ((M2C_FIELD(arg0, f32* , 0x10) < temp_f1) && (temp_f1 < M2C_FIELD(arg0, f32* , 0x20))) {
        temp_f1_2 = M2C_FIELD(arg1, f32* , 4);
        if ((M2C_FIELD(arg0, f32* , 0x14) < temp_f1_2) && (temp_f1_2 < M2C_FIELD(arg0, f32* , 0x24))) {
            temp_f1_3 = M2C_FIELD(arg1, f32* , 8);
            if ((M2C_FIELD(arg0, f32* , 0x18) < temp_f1_3) && (temp_f1_3 < M2C_FIELD(arg0, f32* , 0x28))) {
                var_v0 = 1;
            }
        }
    }
    return var_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", init__10AttractPedP10PedestrianP15PedAttractGroupiQ210AttractPed8Behavior);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", update__10AttractPed);

M2C_UNK killPed__10AttractPed_8_8() __asm__("killPed__10AttractPed");

void shutdown__10AttractPed(void) {
    killPed__10AttractPed_8_8();
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", testBehaviorInit__10AttractPed);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", testBehaviorUpdate__10AttractPed);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", standerInit__10AttractPed);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", standerUpdate__10AttractPed);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", runnerInit__10AttractPed);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", runnerUpdate__10AttractPed);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", runnerUpdateState__10AttractPed);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", guardInit__10AttractPed);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", guardUpdate__10AttractPed);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", guardUpdateState__10AttractPed);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", skaterInit__10AttractPed);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", skaterUpdate__10AttractPed);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", skaterUpdateState__10AttractPed);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", getRandNeighbor__10AttractPed);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", changePts__10AttractPedP15PedAttractPointT1);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", setState__10AttractPedi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", isTargetInFOV__10AttractPedP3_csP8_fvectorf);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", getHeadingToTarget__10AttractPedP8_fvectorT1);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", getRelativeHeading__10AttractPedff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", updateTrans__10AttractPed);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", getClosestVehicle__10AttractPedPf);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", takeHit__10AttractPedP8_fvectorii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", updateDeath__10AttractPed);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", killPed__10AttractPed);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", regenPed__10AttractPedb);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", init__15PedWorldManager);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", update__15PedWorldManager);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", managePedGroups__15PedWorldManager);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", activateGroup__15PedWorldManagerUc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", stealPedFromOldGroup__15PedWorldManageri);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", deactivateGroup__15PedWorldManagerUc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", deactivateAllGroups__15PedWorldManager);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", isGroupActive__15PedWorldManagerUc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", handleDestruct__15PedWorldManagerUii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", BlowDebris__7TheGameP9_hierheadP8_fvectorT2fT2ffif);

s32 getNeighbor__10AttractPedi(void *arg0, int arg1)
{
  int new_var2;
  void *new_var;
  new_var = arg0;
  new_var2 = ((*((u8 *) (((u8 *) ((*((s32 *) (((u8 *) new_var) + 0x74))) + arg1)) + 0x18))) << 5) + 0x30;
  return (*((s32 *) (((u8 *) new_var) + 0x6C))) + new_var2;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", getPt__10AttractPedi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", behaviorUpdate__10AttractPed);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", behaviorInit__10AttractPedQ210AttractPed8Behavior);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", getAnimConfigForState__10AttractPedi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", getAnimForState__10AttractPedi);

void setAnimForState__10AttractPedii(void* arg0, s32 arg1, s32 arg2) {
    M2C_FIELD((arg0 + arg2), s8* , 0x80) = (s8) arg1;
}

s32 getState__10AttractPed(void* arg0) {
    return M2C_FIELD(arg0, s32* , 0x28);
}

s32 isDying__10AttractPed(void* arg0) {
    s32 var_v1;

    var_v1 = 0;
    if (M2C_FIELD(arg0, s32* , 0x20) != 0) {
        var_v1 = M2C_FIELD(arg0, s32* , 0x24) > 0;
    }
    return var_v1;
}

s32 isDead__10AttractPed(void* arg0) {
    s32 var_v1;

    var_v1 = 0;
    if (M2C_FIELD(arg0, s32* , 0x20) != 0) {
        var_v1 = M2C_FIELD(arg0, s32* , 0x24) < 1;
    }
    return var_v1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attractped", __10AttractPed);

M2C_UNK __rtti_si_50_106() __asm__("__rtti_si");
M2C_UNK __tf14CorpseStrategy_50_106() __asm__("__tf14CorpseStrategy");
extern u8 D_004E4BD0_50_106[] __asm__("D_004E4BD0");
extern u8 __ti10AttractPed_50_106[] __asm__("__ti10AttractPed");
extern u8 __ti14CorpseStrategy_50_106[] __asm__("__ti14CorpseStrategy");

s32* __tf10AttractPed(void) {
    if ((*(s32*)__ti10AttractPed_50_106) == 0) {
        __tf14CorpseStrategy_50_106();
        __rtti_si_50_106(((u8*)__ti10AttractPed_50_106), ((u8*)D_004E4BD0_50_106), ((u8*)__ti14CorpseStrategy_50_106));
    }
    return ((u8*)__ti10AttractPed_50_106);
}

s32 getDbId__10Pedestrian(void* arg0) {
    return (s32) ((u32) **M2C_FIELD(arg0, u32*** , 4) >> 0x12);
}
