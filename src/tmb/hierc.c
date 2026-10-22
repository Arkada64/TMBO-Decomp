#include "common.h"
#include "m2c_macros.h"

extern u8 lastGsCtx_8_0[4] __asm__("lastGsCtx");

s32 hierGetLastGSCtx__Fv(void) {
    return (*(s32*)lastGsCtx_8_0);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hier2pFlushDma__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hier2p__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hier__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hierTraverse__FPP9_hierheadi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hierGroupNode__FP10_hiergroupP10_hierstackPP9_hierheadi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hierObjectNode__FP11_hierobjectP14_hierstackinfoP10_hierstackPP9_hierheadi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hierTranslateNode__FP14_hiertranslateP14_hierstackinfoP10_hierstackPP9_hierhead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hierRotateNode__FP11_hierrotateP10_hierstackPP9_hierhead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hierAnimTransNode);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hierCharInstNode__FP17_animCharInstanceP10_hierstackPP9_hierhead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hierTerrainNode__FP12_terrainnodePP9_hierheadP10_hierstack);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hierBurnManKludge);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hierLightNode);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hierKillLocator);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hierRegisterLocator__FUii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hierClearLocatorListForReplay__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hierParticleNode);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hierScaleNode);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hierCheckVifComplete__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hierWaitForVif1__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", vu0HierRotateAsm__FPA3_A3_fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", vu0FovTestResAsm__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", vu0MulEoForTerObj__FPA3_f);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hierPushAsm__FPP9_hierheadiUiUiPUifP17_animCharInstance);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hierPop__FP14_hierstackinfoPP9_hierhead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hierLodEC__FP6QwDataT0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hierLod__FP8_hierlodfPP9_hierheadP10_hierstackP14_hierstackinfo);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hierCtrlNode);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hierInit__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hierSetVu1Regs__Fv);

extern u8 gDisableFov_C_64[4] __asm__("gDisableFov");

void hierDisableFov__Fv(void) {
    (*(s32*)gDisableFov_C_64) = 1;
}

void hierInitCs__FP3_cs_5C_66(void*) __asm__("hierInitCs__FP3_cs");
extern u8 gNextCs_5C_66[4] __asm__("gNextCs");
extern u8 hierCsPool_5C_66[] __asm__("hierCsPool");

s32 csCreate__Fv(void) {
    void* temp_s0;

    if ((*(s32*)gNextCs_5C_66) < 0x320) {
        temp_s0 = ((*(s32*)gNextCs_5C_66) * 0xA0) + ((u8*)hierCsPool_5C_66);
        hierInitCs__FP3_cs_5C_66(temp_s0);
        (*(s32*)gNextCs_5C_66) += 1;
        return (s32) temp_s0;
    }
    return 0;
}

M2C_UNK printf_20_70() __asm__("printf");
extern u8 D_004F2A10_20_70[] __asm__("D_004F2A10");
extern u8 csListHead_20_70[4] __asm__("csListHead");

void hierCsAddToCsList__FP3_cs(void* arg0) {
    void* temp_v0;

    temp_v0 = (*(void**)csListHead_20_70);
    if (arg0 == NULL) {
        printf_20_70(((u8*)D_004F2A10_20_70));
        return;
    }
    (*(void**)csListHead_20_70) = arg0;
    M2C_FIELD(arg0, void** , 0x90) = temp_v0;
}

void hierSetCsEpNode__FP3_csP9_hierhead(s32* arg0, s32 arg1) {
    *arg0 = arg1;
}

void hierCsPtLightMe__FP3_csi(void* arg0) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, s8* , 0xF) = 1;
    }
}

int InitCsListArray__Fv_24_76(void) __asm__("InitCsListArray__Fv");
extern u8 csListHead_24_76[4] __asm__("csListHead");
extern u8 gNextCs_24_76[4] __asm__("gNextCs");
extern u8 g_largeCsList_24_76[4] __asm__("g_largeCsList");

s32 hierCsPoolInit__Fv(void) {
    s32 temp_v0;

    (*(s32*)gNextCs_24_76) = 0;
    (*(s32*)csListHead_24_76) = 0;
    temp_v0 = InitCsListArray__Fv_24_76();
    (*(s32*)g_largeCsList_24_76) = 0;
    return temp_v0;
}

extern u8 csListHead_8_79[4] __asm__("csListHead");

s32 hierCsGetList__Fv(void) {
    return (*(s32*)csListHead_8_79);
}

void hierSetCsDrawMe__FP3_csUc(void* arg0, u8 arg1) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, s8* , 0xC) = (s8) (arg1 & 0xFF);
    }
}

extern u8 gTraversalCallback_8_84[4] __asm__("gTraversalCallback");

void hierSetTraversalCallback__FPFP3_csP11_hierobjectPA3_fP8_fvector_v(void* arg0) {
    (*(void**)gTraversalCallback_8_84) = arg0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hierInitCs__FP3_cs);

void hierSetSwitch__FP11_hierswitchi(void* arg0, s32 arg1) {
    if ((arg0 != NULL) && ((M2C_FIELD(arg0, s32* , 0) & 0x3F) == 6) && (arg1 < (s32) M2C_FIELD(arg0, u8* , 0xB))) {
        M2C_FIELD(arg0, s8* , 8) = (s8) arg1;
    }
}

extern u8 cameraVehiclePos_2C_92[] __asm__("cameraVehiclePos");

s32 hierSetCameraVehiclePos__FP8_fvectori(void* arg0, s32 arg1) {
    void* temp_a1;

    temp_a1 = (arg1 * 0x10) + ((u8*)cameraVehiclePos_2C_92);
    M2C_FIELD(temp_a1, f32* , 0) = (f32) M2C_FIELD(arg0, f32* , 0);
    M2C_FIELD(temp_a1, f32* , 4) = (f32) M2C_FIELD(arg0, f32* , 4);
    M2C_FIELD(temp_a1, f32* , 8) = (f32) M2C_FIELD(arg0, f32* , 8);
    return (s32) ((u8*)cameraVehiclePos_2C_92);
}

extern u8 hierKlod_8_95[4] __asm__("hierKlod");

void hierSetKlod__Ff(f32 fparg0) {
    (*(f32*)hierKlod_8_95) = fparg0;
}

extern u8 hierKlod_8_99[4] __asm__("hierKlod");

f32 hierGetKlod__Fv(void) {
    return (*(f32*)hierKlod_8_99);
}

extern u8 hierObjPkt_C_101[] __asm__("hierObjPkt");

s32 hierGetBigBufAddr__Fv(void) {
    return (s32) ((u8*)hierObjPkt_C_101);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", vu0GetNearRangeAsm__FP6QwData);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", vu0WaitForIt__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", vu0GetEoAsm__FP6QwData);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", vu0AddTranslateAsm__FP6QwData);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", vu0LoadEoAsm__FP6QwData);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hierFlushObjQ__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hierSetDmaIntHandler__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/hierc", hierDmaHandler__Fi);
