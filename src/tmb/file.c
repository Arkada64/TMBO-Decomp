#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", fileReadf__FPcPv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", fileReads__FPcPvUi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", fileWritef__FPcPvi);

void fileMakeDirTree__Fv_A4_9(void) __asm__("fileMakeDirTree__Fv");
s32 sceCdDiskReady_A4_9() __asm__("sceCdDiskReady");
M2C_UNK sceCdInit_A4_9() __asm__("sceCdInit");
M2C_UNK sceCdMmode_A4_9() __asm__("sceCdMmode");
M2C_UNK sceFsReset_A4_9() __asm__("sceFsReset");
M2C_UNK sceSifInitRpc_A4_9() __asm__("sceSifInitRpc");
s32 sceSifRebootIop_A4_9() __asm__("sceSifRebootIop");
s32 sceSifSyncIop_A4_9() __asm__("sceSifSyncIop");
extern u8 D_004F2150_A4_9[] __asm__("D_004F2150");
extern u8 cdHasBeenInitialized_A4_9[4] __asm__("cdHasBeenInitialized");

s32 fileInitializeCd__Fv(void) {
    s32 temp_v0;

    sceSifInitRpc_A4_9(0);
    sceCdInit_A4_9(0);
    do {

    } while (sceSifRebootIop_A4_9(((u8*)D_004F2150_A4_9)) == 0);
    do {

    } while (sceSifSyncIop_A4_9() == 0);
    sceSifInitRpc_A4_9(0);
    sceCdInit_A4_9(0);
    sceCdMmode_A4_9(2);
    sceFsReset_A4_9();
    do {

    } while (sceCdDiskReady_A4_9(0) != 2);
    fileMakeDirTree__Fv_A4_9();
    (*(s32*)cdHasBeenInitialized_A4_9) = 1;
    do {
        temp_v0 = sceCdDiskReady_A4_9(0);
    } while (temp_v0 != 2);
    return temp_v0;
}

extern u8 fileStatus_C_12[] __asm__("fileStatus");

s32 getTexFilesLoaded__Fv(void) {
    return (s32) M2C_FIELD(((u8*)fileStatus_C_12), s8* , 0x38);
}

extern u8 fileStatus_C_15[] __asm__("fileStatus");

s32 getNgpFilesLoaded__Fv(void) {
    return (s32) M2C_FIELD(((u8*)fileStatus_C_15), s8* , 0x74);
}

extern u8 fileStatus_C_18[] __asm__("fileStatus");

s32 getResFilesLoaded__Fv(void) {
    return (s32) M2C_FIELD(((u8*)fileStatus_C_18), s8* , 0xB0);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", getNextNgpLoadAddr__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", getNextTexLoadAddr__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", getNextResLoadAddr__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", getNgpAddr__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", getTexAddr__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", getResAddr__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", getGenericName__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", getMaxTexId__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", getMaxTexAddr__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", getMaxResAddr__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", setMaxTexId__FiUs);

extern u8 fileStatus_18_55[] __asm__("fileStatus");

void setMaxTexAddr__FiUs(s32 arg0, s16 arg1)
{
  u8 *new_var;
  new_var = (u8 *) (((u8 *) fileStatus_18_55) - (-(arg0 * 2)));
  *((s16 *) (new_var + 0x14C)) = arg1;
}

extern u8 fileStatus_18_58[] __asm__("fileStatus");

void setMaxResAddr__FiUs(s32 arg0, s16 arg1)
{
  s16 *new_var;
  u8 *new_var2;
  new_var2 = (u8 *) (((u8 *) fileStatus_18_58) - (-(arg0 * 2)));
  new_var = (s16 *) (new_var2 + 0x168);
  *new_var = arg1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", getIdxOfAddr__FPc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", getIdxOfResAddr__FPc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", getIdxOfName__FPc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", fileAddNgpFile__FPci);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", fileAddTexFile__FPci);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", fileAddResFile__FPci);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", fileAddName__FPc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", fileOnlyNgpFile__FPci);

extern u8 fileStatus_48_100[] __asm__("fileStatus");

void fileOnlyTexFile__FPci(s32 arg0, s32 arg1)
{
  s32 temp_a1;
  s32 temp_a2;
  int new_var2;
  u8 *new_var;
  int new_var3;
  new_var2 = arg0 + arg1;
  temp_a1 = new_var2;
  *((s32 *) (((u8 *) ((u8 *) fileStatus_48_100)) + 0)) = arg0;
  new_var = ((u8 *) ((u8 *) fileStatus_48_100)) + 4;
  temp_a2 = temp_a1 & 0x7F;
  *((s8 *) (((u8 *) ((u8 *) fileStatus_48_100)) + 0x38)) = 1;
  *((s32 *) (((u8 *) ((u8 *) fileStatus_48_100)) + 4)) = temp_a1;
  if (temp_a2 != 0)
  {
    new_var3 = 0x80 - temp_a2;
    *((s32 *) new_var) = (s32) ((temp_a1 + ((s8) new_var3)) + 0x70);
  }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", fileOnlyResFile__FPci);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", fileInitBeforeDbLoad__Fv);

void filePrintFileStatus__Fv(void) {
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", fileMakeDirTree__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", fourCharsToInt__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", twoCharsToShort__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", fileCdRead__FllPc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", fileCdSearchFile__FP10sceCdlFILEPCc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", fileHierAddrOfSect__FUi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", filePrintCdFiles__FP13_cdFileSystemi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", fileStringCompare__FPcT0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", fileTrimPath__FPc);

void fileOutputTime__Fv(void) {
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/file", fileGetTimeString__Fv);
