#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", main);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", SelectAICars__5Shell);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", RandomlySelectAI__5Shelliii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", InitPlayers__5Shell);

void Init__6Camera_98_16(void*) __asm__("Init__6Camera");
M2C_UNK SetCameraPOV__6Camerai10_cameraPOV_98_16() __asm__("SetCameraPOV__6Camerai10_cameraPOV");
void hierInit__Fv_98_16(void) __asm__("hierInit__Fv");
void hierSetVu1Regs__Fv_98_16(void) __asm__("hierSetVu1Regs__Fv");
void initShellSound__10ShellSound_98_16(void*) __asm__("initShellSound__10ShellSound");
M2C_UNK viewCreate__F10_viewportsi_98_16() __asm__("viewCreate__F10_viewportsi");
void viewInit__Fv_98_16(void) __asm__("viewInit__Fv");
void viewSetNumViews__Fi_98_16(int) __asm__("viewSetNumViews__Fi");
extern u8 game_98_16[4] __asm__("game");

void InitBeforeUiDbLoad__5Shell(void* arg0) {
    void* temp_a0;

    M2C_FIELD(arg0, s32* , 0x1A3A0) = 0;
    hierInit__Fv_98_16();
    hierSetVu1Regs__Fv_98_16();
    viewInit__Fv_98_16();
    initShellSound__10ShellSound_98_16(arg0 + 0x1A144);
    viewSetNumViews__Fi_98_16(1);
    viewCreate__F10_viewportsi_98_16(9, 0);
    temp_a0 = (*(s32*)game_98_16) + 0x14C0D0;
    M2C_FIELD(temp_a0, s32* , 0x43E0) = 1;
    Init__6Camera_98_16(temp_a0);
    SetCameraPOV__6Camerai10_cameraPOV_98_16((*(s32*)game_98_16) + 0x14C0D0, 0, 2);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", __5Shell);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", _$_5Shell);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", InitRTState__5Shell);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", EvaluateGameStatus__5Shelli);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", EvaluateEnduranceStatus__5Shelli);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", EvaluateMultiPlayerLastManStatus__5Shelli);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", EvaluateOnePlayerStoryStatus__5Shelli);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", EvaluateOnePlayerChallengeStatus__5Shelli);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", EvaluateTwoPlayerCoopStatus__5Shelli);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", EvaluateMultiPlayerBattleStatus__5Shelli);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", Evaluate34PlayerBattleStatus__5Shelli);

s32 HasTimeElapsed__5Shell(void* arg0) {
    return 0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", InitPlayerLives__5Shell);

s32 ResetMultiPlayerGameStats__5Shell(void* arg0) {
    s32 var_v1;
    void* var_v0;

    var_v1 = 3;
    var_v0 = arg0 + 0x1A340;
    do {
        M2C_FIELD(var_v0, s32* , -0x10) = 0;
        var_v1 -= 1;
        M2C_FIELD(var_v0, s32* , 0) = 0;
        var_v0 += 4;
    } while (var_v1 >= 0);
    M2C_FIELD(arg0, s32* , 0x1A350) = -1;
    return (s32) (arg0 + 0x18000);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", ResetShellStats__5Shell);

void viewSetAmbientFactor__Ff_10_49(float) __asm__("viewSetAmbientFactor__Ff");

void ResetShellOptions__5Shell(void)
{
  unsigned int new_var;
  int new_var2;
  new_var2 = 0x3F800000;
  new_var2 = 1;
  if (new_var2)
  {
    new_var = new_var2;
    viewSetAmbientFactor__Ff_10_49(new_var);
  }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", BootInitUi__5Shell);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", BootInitGame__5Shell);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", ResolveCommandLineLevel__5Shell);

M2C_UNK sceGsResetGraph_2C_61() __asm__("sceGsResetGraph");
M2C_UNK sceGsResetPath_2C_61() __asm__("sceGsResetPath");

void InitGS__5Shells(s32 arg0, s16 arg1) {
    sceGsResetGraph_2C_61(0, 1, 2, arg1);
    sceGsResetPath_2C_61();
}

void fileOnlyResFile__FPci_78_64(void*, int) __asm__("fileOnlyResFile__FPci");
void fileOnlyTexFile__FPci_78_64(void*, int) __asm__("fileOnlyTexFile__FPci");
s32 fileReadf__FPcPv_78_64(void*, void*) __asm__("fileReadf__FPcPv");
s32 getVramAddr__5Shell_78_64(void*) __asm__("getVramAddr__5Shell");
M2C_UNK texmInit__F10_vramAddrs_78_64() __asm__("texmInit__F10_vramAddrs");
M2C_UNK texmResInit__F10_vramAddrsP6QwData_78_64() __asm__("texmResInit__F10_vramAddrsP6QwData");
s32 zipInflateAll__FPcPv_78_64(void*, void*) __asm__("zipInflateAll__FPcPv");
extern u8 D_004E7C98_78_64[] __asm__("D_004E7C98");
extern u8 D_004E7CB0_78_64[] __asm__("D_004E7CB0");

void LoadUiTexture__5Shell(s32 arg0) {
    fileOnlyResFile__FPci_78_64(0xB00000, fileReadf__FPcPv_78_64(((u8*)D_004E7C98_78_64), 0xB00000));
    texmResInit__F10_vramAddrsP6QwData_78_64(getVramAddr__5Shell_78_64(arg0), 0xB00000);
    fileOnlyTexFile__FPci_78_64(0xB00000, zipInflateAll__FPcPv_78_64(((u8*)D_004E7CB0_78_64), 0xB00000));
    texmInit__F10_vramAddrs_78_64(getVramAddr__5Shell_78_64(arg0));
}

M2C_UNK dbInitDb__FP9_dbheader10_vramAddrs_6C_67() __asm__("dbInitDb__FP9_dbheader10_vramAddrs");
M2C_UNK dbsRelocateFileZero__F10_vramAddrsb_6C_67() __asm__("dbsRelocateFileZero__F10_vramAddrsb");
void fileAddName__FPc_6C_67(void*) __asm__("fileAddName__FPc");
void fileOnlyNgpFile__FPci_6C_67(void*, int) __asm__("fileOnlyNgpFile__FPci");
s32 getVramAddr__5Shell_6C_67(void*) __asm__("getVramAddr__5Shell");
s32 zipInflateAll__FPcPv_6C_67(void*, void*) __asm__("zipInflateAll__FPcPv");
extern u8 D_004E7CC8_6C_67[] __asm__("D_004E7CC8");
extern u8 D_004FACF0_6C_67[] __asm__("D_004FACF0");
extern u8 commandLineLevelSelected_6C_67[4] __asm__("commandLineLevelSelected");

void LoadUiDB__5Shell(s32 arg0) {
    fileOnlyNgpFile__FPci_6C_67(0x980000, zipInflateAll__FPcPv_6C_67(((u8*)D_004E7CC8_6C_67), 0x980000));
    fileAddName__FPc_6C_67(((u8*)D_004FACF0_6C_67));
    dbsRelocateFileZero__F10_vramAddrsb_6C_67(getVramAddr__5Shell_6C_67(arg0), (*(s32*)commandLineLevelSelected_6C_67));
    dbInitDb__FP9_dbheader10_vramAddrs_6C_67(0x980000, getVramAddr__5Shell_6C_67(arg0));
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", LoadLevelResTexture__5Shell);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", LoadLevelTexture__5Shell);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", LoadLevelDB__5Shell);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", LoadCarsDB__5Shell);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", InitMenuItemsBefore__5Shell);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", InitMenuItemsAfter__5Shell);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", CreateMenuItem__5ShelliiP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", AddEpNode__5ShelliP9_hierhead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", formatFilename__5ShellPcPCcT2Q25Shell11_shFileType);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", formatFilename__5ShellPcPCcT2T2);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", formatMovieFilename__5ShellPcPCcT2T2);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", getVramAddr__5Shell);

s32 Use30HzMode__5Shell(void* arg0) {
    return 0;
}

extern u8 levelName_24_101[] __asm__("levelName");

s32 GetLevelName__5Shell(void* arg0) {
    return (s32) ((M2C_FIELD(arg0, s32* , 0x1A354) * 0x10) + ((u8*)levelName_24_101));
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", LoadLevelFiles__5Shellb);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", _$_17SFXStreamingSound);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", _$_19AmbientSoundManager);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", _$_7TheGame);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", _GLOBAL_$D$commandLinePageCars);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", __7TheGame);

extern u8 shellGame_28_122[] __asm__("shellGame");
extern u8 shellInfo_28_122[] __asm__("shellInfo");

void _GLOBAL_$I$commandLinePageCars(void) {
    __7TheGame(((u8*)shellGame_28_122));
    __5Shell(((u8*)shellInfo_28_122));
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", func_001634C0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shell", func_001634E0);
