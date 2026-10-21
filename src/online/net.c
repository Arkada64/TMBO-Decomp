#include "online/net.h"

void func_001625D8(void) {
}

void func_001625E0(void) {
}

void func_001625E8(void) {
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_001625F0);

#include "m2c_macros.h"
M2C_UNK strcpy_162670() __asm__("strcpy");
extern M2C_UNK D_00313D70_162670 __asm__("D_00313D70");

void func_00162670(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    strcpy_162670(&D_00313D70_162670, arg3 + 0x15);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00162698);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_001626F8);

#include "m2c_macros.h"
void func_00163EB8_162778() __asm__("func_00163EB8");
extern s32 D_002C1690_162778 __asm__("D_002C1690");

void func_00162778(s32 arg0, s32 arg1, s32 arg2, void *arg3)
{
  func_00163EB8_162778(&D_002C1690_162778, *((s32 *) (((u8 *) arg3) + 0x18)));
  D_002C1690_162778 = 1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_001627B0);

#include "m2c_macros.h"
void func_00163EB8_1628E0() __asm__("func_00163EB8");
extern s32 D_002C1690_1628E0 __asm__("D_002C1690");

void func_001628E0(s32 arg0, s32 arg1, s32 arg2, void *arg3)
{
  func_00163EB8_1628E0(&D_002C1690_1628E0, *((s32 *) (((u8 *) arg3) + 0x18)));
  D_002C1690_1628E0 = 1;
}

#include "m2c_macros.h"
void func_00163EB8_162918() __asm__("func_00163EB8");
extern s32 D_002C1690_162918 __asm__("D_002C1690");

void func_00162918(s32 arg0, s32 arg1, s32 arg2, void *arg3)
{
  func_00163EB8_162918(&D_002C1690_162918, *((s32 *) (((u8 *) arg3) + 0x18)));
  D_002C1690_162918 = 1;
}

#include "m2c_macros.h"
void func_00163EB8_162950() __asm__("func_00163EB8");
extern s32 D_002C1690_162950 __asm__("D_002C1690");

void func_00162950(s32 arg0, s32 arg1, s32 arg2, void *arg3)
{
  func_00163EB8_162950(&D_002C1690_162950, *((s32 *) (((u8 *) arg3) + 0x18)));
  D_002C1690_162950 = 1;
}

#include "m2c_macros.h"
void func_00163EB8_162988() __asm__("func_00163EB8");
extern s32 D_002C1690_162988 __asm__("D_002C1690");

void func_00162988(s32 arg0, s32 arg1, s32 arg2, void *arg3)
{
  u8 *new_var;
  new_var = ((u8 *) arg3) + 0x18;
  func_00163EB8_162988(&D_002C1690_162988, *((s32 *) new_var));
  D_002C1690_162988 = 1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_001629C0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00162A00);

#include "m2c_macros.h"
void func_00163EB8_162A38() __asm__("func_00163EB8");
M2C_UNK func_001641B8_162A38() __asm__("func_001641B8");
extern s32 D_002C1690_162A38 __asm__("D_002C1690");

void func_00162A38(s32 arg0, s32 arg1, s32 arg2, void *arg3)
{
  void *temp_a1;
  func_00163EB8_162A38(&D_002C1690_162A38, *((s32 *) (((u8 *) arg3) + 0x18)));
  if ((*((s32 *) (((u8 *) arg3) + 0x18))) == 0)
  {
    temp_a1 = arg3 + 0x1C;
    if (temp_a1 != 0)
    {
      func_001641B8_162A38(&D_002C1690_162A38, temp_a1);
    }
  }
  if ((*((s8 *) (((u8 *) arg3) + 0x11C))) != 0)
  {
    D_002C1690_162A38 = 1;
  }
}

#include "m2c_macros.h"
void func_00163EB8_162AB0() __asm__("func_00163EB8");
M2C_UNK func_00164240_162AB0() __asm__("func_00164240");
extern s32 D_002C1690_162AB0 __asm__("D_002C1690");

void func_00162AB0(s32 arg0, s32 arg1, s32 arg2, void *arg3)
{
  func_00163EB8_162AB0(&D_002C1690_162AB0, *((s32 *) (((u8 *) arg3) + 0x18)));
  if ((*((s32 *) (((u8 *) arg3) + 0x18))) == 0)
  {
    func_00164240_162AB0(&D_002C1690_162AB0, arg3 + 0x20);
  }
  if ((*((s8 *) (((u8 *) arg3) + 0x408))) != 0)
  {
    D_002C1690_162AB0 = 1;
  }
}

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E58D0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00162B20);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00162F00);

#include "m2c_macros.h"
s32 func_00298010_162FA0() __asm__("func_00298010");
s32 func_00299350_162FA0() __asm__("func_00299350");
M2C_UNK strcpy_162FA0() __asm__("strcpy");
extern M2C_UNK D_004F9C28_162FA0 __asm__("D_004F9C28");
extern M2C_UNK D_004F9C30_162FA0 __asm__("D_004F9C30");

void func_00162FA0(s32 arg0) {
    u8 sp[0x100];
    s32 var_a0;
    s32 var_s0;

    strcpy_162FA0(sp);
    var_s0 = func_00299350_162FA0(sp, &D_004F9C28_162FA0);
    if (var_s0 != 0) {
        var_a0 = var_s0;
loop_2:
        if (func_00298010_162FA0(var_a0, &D_004F9C30_162FA0, 3) == 0) {
            strcpy_162FA0(var_s0 + 4, arg0);
            return;
        }
        var_s0 = func_00299350_162FA0(NULL, &D_004F9C28_162FA0);
        var_a0 = var_s0;
        if (var_s0 == 0) {

        } else {
            goto loop_2;
        }
    }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00163040);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00163200);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00163278);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00163560);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00163658);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00163708);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00163778);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_001638C0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_001639F8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00163A58);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00163B00);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00163CE0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00163D48);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00163DC8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00163E00);

#include "m2c_macros.h"
void func_00163EB8(void* arg0, s32 arg1) {
    M2C_FIELD_V1(arg0, s32* , 4) = arg1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00163EC0);

void func_001641A8(char* p) {
    p[0x64] = 0;
    *(char**)(p + 0x1E64) = p + 0x64;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_001641B8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00164240);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00164290);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00164318);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_001644D0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00164610);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00164750);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_001648B0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00164938);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_001649D8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00164B60);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00164C20);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00164CA8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00164E60);

#include "m2c_macros.h"
M2C_UNK strcpy_164F68() __asm__("strcpy");

void func_00164F68(void* arg0, s32 arg1, s32 arg2) {
    strcpy_164F68(arg0 + 0x525C4, arg0 + 0xC);
    M2C_FIELD_V1(arg0, s32* , 0x525D8) = arg1;
    strcpy_164F68(arg0 + 0x525DC, arg2);
}

#include "m2c_macros.h"
M2C_UNK* func_00164FD8(void* arg0) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32* , 4);
    switch (temp_v1) {                              /* irregular */
    case -1000:
        return "TM:B ONLINE Begin Session Failed";
    case -999:
        return "TM:B ONLINE Account Already Exists";
    case -998:
        return "TM:B ONLINE Account Not Found";
    case -997:
        return "TM:B ONLINE Account Logged In";
    case -996:
        return "TM:B ONLINE End Session Failed";
    case -995:
        return "TM:B ONLINE Login Failed";
    case -994:
        return "TM:B ONLINE Registration Failed";
    case -993:
        return "TM:B ONLINE Incorrect Login Step";
    case -992:
        return "TM:B ONLINE Already Leader Of Clan";
    case -991:
        return "TM:B ONLINE WM Error";
    case -990:
        return "TM:B ONLINE Not Clan Leader";
    case -989:
        return "TM:B ONLINE Player Not Privileged";
    case -988:
        return "TM:B ONLINE DB Error";
    case -987:
        return "TM:B ONLINE DME Error";
    case -986:
        return "TM:B ONLINE Exceeds Max Worlds";
    case -985:
        return "TM:B ONLINE Request Denied";
    case -984:
        return "TM:B ONLINE Set Game List Filter Failed";
    case -983:
        return "TM:B ONLINE Clear Game List Filter Failed";
    case -982:
        return "TM:B ONLINE Get Game List Filter Failed";
    case -981:
        return "TM:B ONLINE Num Filters At Max";
    case -980:
        return "TM:B ONLINE Filter Not Found";
    case -979:
        return "TM:B ONLINE Invalid Request Msg";
    case -978:
        return "TM:B ONLINE Invalid Password";
    case -977:
        return "TM:B ONLINE Game Not Found";
    case -976:
        return "TM:B ONLINE Channel Not Found";
    case -975:
        return "TM:B ONLINE Game Name Exists";
    case -974:
        return "TM:B ONLINE Channel Name Exists";
    case -973:
        return "TM:B ONLINE Game Name Not Found";
    case -972:
        return "TM:B ONLINE Player Banned";
    case -971:
        return "TM:B ONLINE Clan Not Found";
    case -970:
        return "TM:B ONLINE Clan Name In Use";
    case -969:
        return "TM:B ONLINE Session Key Invalid";
    case -968:
        return "TM:B ONLINE Text String Invalid";
    case -967:
        return "TM:B ONLINE Filter Failed";
    case -966:
        return "TM:B ONLINE Fail";
    case 0:
        return "TM:B ONLINE Success";
    case 1:
        return "TM:B ONLINE No Result";
    case 2:
        return "TM:B ONLINE Request Accepted";
    case 3:
        return "TM:B ONLINE World Created Size Reduced";
    case 4:
        return "TM:B ONLINE Pass";
    case 16777215:
        return "Extra TM:B ONLINE Callback Status";
    default:
        if (M2C_FIELD(arg0, s32* , 4) == -0x32) {
            return "Bad Connection or Server Down";
        }
        return "Unknown Error";
    }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_001653D8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00165430);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E62C0);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E62D8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00165498);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E6340);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E6380);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00165620);

void func_00259FBC(void);
void func_001658C8(void) {
    func_00259FBC();
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_001658E8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00165998);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00165A38);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00165B08);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00165BA8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00165C80);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00165D50);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00165E08);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00165ED0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00165F08);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00165FB0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00166060);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00166110);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00166190);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00166280);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_001662F8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00166368);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00166478);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00166528);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00166600);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00166678);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00166730);

#include "m2c_macros.h"
M2C_UNK func_0025B938_1667E0() __asm__("func_0025B938");

void func_001667E0(s32 arg0) {
    func_0025B938_1667E0(arg0 + 0x52444);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00166808);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00166868);

#include "m2c_macros.h"
M2C_UNK func_0025B8AC_166918() __asm__("func_0025B8AC");

void func_00166918(s32 arg0) {
    func_0025B8AC_166918(arg0 + 0x525C4);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00166940);

#include "m2c_macros.h"
extern s32 D_002C1698_1669A0 __asm__("D_002C1698");

void func_001669A0(s32 arg0, s32 arg1) {
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        D_002C1698_1669A0 = -1;
    }
}

void func_001669A0(int a, int b);
void func_001669C8(void) {
    func_001669A0(1, 0xFFFF);
}

int netMsgChatHandler(int unused0, int unused1, int client, void* text) {
    NetChatLine line;

    func_001188C0(&line);
    if (client == 0x100) {
        return 0x44;
    }
    strcpy(line.name, D_003156D8 + client * 0x220);
    line.client = client;
    func_00118380(&line, text);
    func_001186C8(D_002B90A0, &line);
    return 0x44;
}

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E6500);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", netMsgSessionHandler);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", netMsgGameEventHandler);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", netMsgWorldEventHandler);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", netMsgPlayerInfoHandler);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", netMsgRosterHandler);

void func_00168B58(void) {
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00168B60);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00168C30);

extern char D_003156C0[];
char func_00176B10(char* state, int arg);
void func_00168D90(int connection, int client) {
    char* state;

    if (client != 0x100) {
        state = D_003156C0;
        if (connection == *(int*)(state + 0x2CF0)) {
            *(char*)(*(char**)(state + 0x3148) + 0x24) = func_00176B10(state, 0);
        }
    }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00168DE0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00168F30);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00168FB8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00169050);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_001690F0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00169230);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E6A00);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", netObjCreateCB);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", netObjUpdateVehicleCB);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", netObjDestroyCB);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", netWeaponCreateCB);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", netWeaponUpdateCB);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", netWeaponDestroyCB);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", netFodderUpdateCB);

void netStatsUpdateCB(void) {
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", netGameDataUpdateCB);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", netPadFlagsUpdateCB);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016C480);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016C488);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016C590);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016C738);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016C748);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E6D30);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016C7D0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016CA88);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016CB90);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016CD88);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016D238);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016D338);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016D3B0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016D4F8);

#include "m2c_macros.h"
M2C_UNK func_00259D38_16D638() __asm__("func_00259D38");
M2C_UNK func_0026E4E8_16D638() __asm__("func_0026E4E8");
M2C_UNK func_0028B414_16D638() __asm__("func_0028B414");
M2C_UNK printf_16D638() __asm__("printf");

s32 func_0016D638(void* arg0) {
    printf_16D638("Taking down the RTime Interface...\n");
    func_0028B414_16D638();
    func_00259D38_16D638();
    func_0026E4E8_16D638();
    M2C_FIELD_V1(arg0, s32* , 0x1BBC) = 0;
    M2C_FIELD_V1(arg0, s32* , 0x1BB8) = 4;
    return 0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016D690);

#include "m2c_macros.h"
M2C_UNK func_0016D338_16D7C0() __asm__("func_0016D338");
M2C_UNK func_0016D638_16D7C0() __asm__("func_0016D638");

void func_0016D7C0(s32 arg0) {
    func_0016D638_16D7C0();
    func_0016D338_16D7C0(arg0);
}

#include "m2c_macros.h"
s32 func_0016D7F0(void* arg0) {
    return M2C_FIELD_V1(arg0, s32* , 0x4258);
}

#include "m2c_macros.h"
s32 func_0016D7F8(void* arg0) {
    return M2C_FIELD_V1(arg0, s32* , 0x4278);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016D800);

#include "m2c_macros.h"
s32 func_0016D828(void) {
    return 1;
}

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E72A0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", netInitDme);

int iSignalSema(int sema);
void func_0016E6D8(int sema) {
    iSignalSema(sema);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016E6F8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016E7D0);

#include "m2c_macros.h"
M2C_UNK func_0016E8E0_16E8B8() __asm__("func_0016E8E0");

s32 func_0016E8B8(s32 arg0) {
    func_0016E8E0_16E8B8();
    return arg0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016E8E0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016E9A0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016E9E8);

#include "m2c_macros.h"
void func_0016EB70(void* arg0) {
    M2C_FIELD_V1(arg0, s32* , 0x768) = 0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016EB78);

#include "m2c_macros.h"
M2C_UNK func_002693D8_16EC18() __asm__("func_002693D8");
extern s32 D_00319924_16EC18 __asm__("D_00319924");
extern M2C_UNK func_00168F30_16EC18 __asm__("func_00168F30");

void func_0016EC18(void) {
    if (D_00319924_16EC18 == 0) {
        func_002693D8_16EC18(&func_00168F30_16EC18);
    }
}

void func_0016EC48(void) {
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016EC50);

#include "m2c_macros.h"
void* func_00213F80_16EE60() __asm__("func_00213F80");
M2C_UNK hierCsAddToCsList__FP3_cs_16EE60() __asm__("hierCsAddToCsList__FP3_cs");
M2C_UNK hierSetCsEpNode__FP3_csP9_hierhead_16EE60() __asm__("hierSetCsEpNode__FP3_csP9_hierhead");

void func_0016EE60(void* arg0, s32 arg1, s32 arg2, M2C_UNK arg3) {
    void* temp_v0;
    void* temp_v0_2;
    void* temp_v0_3;

    switch (arg1) {                                 /* irregular */
    case 0x1E47:
        temp_v0 = func_00213F80_16EE60();
        M2C_FIELD(arg0, void** , 0xB790) = temp_v0;
        M2C_FIELD(temp_v0, s8* , 0xC) = 0;
        hierSetCsEpNode__FP3_csP9_hierhead_16EE60(M2C_FIELD(arg0, void** , 0xB790), arg3);
        hierCsAddToCsList__FP3_cs_16EE60(M2C_FIELD(arg0, void** , 0xB790));
        return;
    case 0x1E48:
        temp_v0_2 = func_00213F80_16EE60();
        M2C_FIELD(arg0, void** , 0xB794) = temp_v0_2;
        M2C_FIELD(temp_v0_2, s8* , 0xC) = 0;
        hierSetCsEpNode__FP3_csP9_hierhead_16EE60(M2C_FIELD(arg0, void** , 0xB794), arg3);
        hierCsAddToCsList__FP3_cs_16EE60(M2C_FIELD(arg0, void** , 0xB794));
        break;
    case 0x1E49:
        temp_v0_3 = func_00213F80_16EE60();
        M2C_FIELD(arg0, void** , 0xB798) = temp_v0_3;
        M2C_FIELD(temp_v0_3, s8* , 0xC) = 0;
        hierSetCsEpNode__FP3_csP9_hierhead_16EE60(M2C_FIELD(arg0, void** , 0xB798), arg3);
        hierCsAddToCsList__FP3_cs_16EE60(M2C_FIELD(arg0, void** , 0xB798));
        break;
    }
}

char* func_0016EF58(char* base, int slot) {
    return base + (slot * 0x220 + 0x10);
}

char* func_0016EF70(char* base, int index) {
    return base + (index * 0x84 + 0x1110);
}

#include "m2c_macros.h"
s32 func_0016EF88(s32 arg0) {
    return arg0 + 0x1218;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016EF90);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E7760);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E7770);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E7788);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E77A8);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E77C8);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E77E8);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E7810);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E7838);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E7858);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E7880);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E7890);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E78A8);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E78B8);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E78C8);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E78D8);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E78F0);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E7900);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E7910);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E7920);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E7938);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E7958);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E7978);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E7988);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E79A0);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E79B8);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E79C0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016F058);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016F1C8);

#include "m2c_macros.h"
s32 func_0016F478(s32 arg0, s32 arg1) {
    return arg1;
}

#include "m2c_macros.h"
s32 func_0016F480(s32 arg0, s32 arg1) {
    return arg1;
}

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E7BC8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016F488);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E7D38);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E7D78);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016F718);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016F910);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E7DE0);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E7E08);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E7E30);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E7E58);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E7E70);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E7EA0);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E7ED0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016FA30);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016FD68);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_0016FE70);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E80E0);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E8108);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E8130);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E8158);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E8180);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E81A8);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E81C8);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E81F8);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E8230);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E8250);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E8280);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E82C0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00170308);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_001703E8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00170760);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00170B68);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00170D38);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00170DF0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_001714D0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00171818);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00171AA8);

void func_00268260(int handle);
void func_00171B58(void* unused, char* obj) {
    func_00268260(*(int*)(obj + 0x50));
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00171B78);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00171C08);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E8528);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", netSendSessionMsg);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", netSendGameEvent);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", netBroadcastGameEvent);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00171F88);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00172190);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00172218);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_001722C0);

#include "m2c_macros.h"
M2C_UNK memset_172320() __asm__("memset");
M2C_UNK sprintf_172320() __asm__("sprintf");

s32 func_00172320(s32 arg0) {
    s32 temp_s1;

    temp_s1 = arg0 + 0x1CC8;
    memset_172320(temp_s1, 0, 0x1000);
    sprintf_172320(temp_s1, "[MEDIUS_ACCOUNT] %s\n[MEDIUS_PASSWORD] %s\n", arg0 + 0x14AC, arg0 + 0x14EC);
    return 1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00172378);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00172A10);

#include "m2c_macros.h"
s32 func_00172A80(void) {
    return 1;
}

#include "m2c_macros.h"
s32 func_00172A88(void) {
    return 0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00172A90);

int func_00172F48(char* state, int which) {
    char* game = *(char**)(state + 0x3148);
    int mode = (*(unsigned int*)game >> 1) & 0xF;

    if (mode == 4 || mode == 8) {
        if (which == 0) {
            return *(signed char*)(game + 0x1A);
        }
        if (which == 1) {
            return *(signed char*)(game + 0x1B);
        }
        return -1;
    }
    return -1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00172FA0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00172FE8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_001731A8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00173248);

#include "m2c_macros.h"
M2C_UNK func_00172FE8_173340() __asm__("func_00172FE8");
s32 func_001734B8_173340() __asm__("func_001734B8");

void func_00173340(void* arg0, s32 arg1, M2C_UNK arg2) {
    if ((((u32) *M2C_FIELD_V1(arg0, u32** , 0x3148) >> 1) & 0xF) == 4) {
        if (func_001734B8_173340(arg0) != 0) {
            func_00172FE8_173340(arg0, arg1, arg2, -1);
        }
    }
    if ((((u32) *M2C_FIELD_V1(arg0, u32** , 0x3148) >> 1) & 0xF) == 8) {
        if (func_001734B8_173340(arg0) != 0) {
            func_00172FE8_173340(arg0, arg1, arg2, M2C_FIELD_V1(((arg1 * 0x220) + arg0), s32* , 0x14));
        }
    }
}

int func_00264AE0(int* out, int connection, int index);
int func_001733F8(NetState* state) {
    int index;
    int value;

    if (dmeGetMyClientIndex(&index, state->mConnectionIndex) != 0) {
        return 0;
    }
    if (func_00264AE0(&value, state->mConnectionIndex, index) != 0) {
        return 0;
    }
    return value;
}

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E888C);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E8890);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E88A0);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E88B0);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E88C0);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E88D0);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E88E0);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E88F8);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E8910);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E8928);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E8938);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E8948);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E8960);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", D_004E8978);

int netGetMyClientIndex(NetState* state) {
    int index;
    int err;

    err = dmeGetMyClientIndex(&index, state->mConnectionIndex);
    if (err == 0) {
        if ((unsigned int)index >= 8) {
            printf("NETWORK:  ERROR:  GetMyClientIndex() RETURNING %d\n", index);
        }
        return index;
    } else {
        printf("NETWORK: NetGetMyClientIndex returned an error of %d index = %d mConnectionIndex = %d\n", err, index, state->mConnectionIndex);
        return 0;
    }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_001734B8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00173500);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00173570);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_001735A8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_001735E8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00173810);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00173880);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00173BE8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00173C50);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00173D08);

#include "m2c_macros.h"
void* netGetDmeTime_173ED0() __asm__("netGetDmeTime");

s32 func_00173ED0(s32 arg0, s32 arg1, s32 arg2) {
    void* temp_v0;

    temp_v0 = netGetDmeTime_173ED0();
    if (temp_v0 != NULL) {
        M2C_FIELD_V1(M2C_FIELD_V1(temp_v0, void** , 0x1C), s32* , 0x24) = arg2;
        return 1;
    }
    return 0;
}

#include "m2c_macros.h"
void* netGetDmeTime_173F10() __asm__("netGetDmeTime");

s32 func_00173F10(void) {
    void* temp_v0;

    temp_v0 = netGetDmeTime_173F10();
    if (temp_v0 != NULL) {
        return M2C_FIELD_V1(M2C_FIELD_V1(temp_v0, void** , 0x1C), s32* , 0x24);
    }
    return 0;
}

#include "m2c_macros.h"
void* netGetDmeTime_173F40() __asm__("netGetDmeTime");

s32 func_00173F40(s32 arg0, s32 arg1, s32 arg2) {
    void* temp_v0;

    temp_v0 = netGetDmeTime_173F40();
    if (temp_v0 != NULL) {
        M2C_FIELD_V1(M2C_FIELD_V1(temp_v0, void** , 0x1C), s32* , 0x1C) = arg2;
        return 1;
    }
    return 0;
}

#include "m2c_macros.h"
void* netGetDmeTime_173F80() __asm__("netGetDmeTime");

s32 func_00173F80(s32 arg0, s32 arg1, s32 arg2) {
    void* temp_v0;

    temp_v0 = netGetDmeTime_173F80();
    if (temp_v0 != NULL) {
        M2C_FIELD_V1(M2C_FIELD_V1(temp_v0, void** , 0x1C), s32* , 0x20) = arg2;
        return 1;
    }
    return 0;
}

#include "m2c_macros.h"
void* netGetDmeTime_173FC0() __asm__("netGetDmeTime");

s32 func_00173FC0(void) {
    void* temp_v0;

    temp_v0 = netGetDmeTime_173FC0();
    if (temp_v0 != NULL) {
        return M2C_FIELD_V1(M2C_FIELD_V1(temp_v0, void** , 0x1C), s32* , 0x20);
    }
    return 0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00173FF0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_001740B0);

int func_00174218(char* base, int slot) {
    return *(int*)(base + slot * 0x220 + 0xB4);
}

int func_00174230(char* base, int value, int slot) {
    *(int*)(base + slot * 0x220 + 0xB4) = value;
    return 1;
}

int netGetDmeTime(NetState* state) {
    int time;

    dmeGetTime(&time);
    return time;
}

int func_00174268(NetState* state, int index) {
    return D_00321018[netGetMyClientIndex(state)][index];
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_001742B0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00174598);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00174608);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00174638);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_001746E8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00174860);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_001748D8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00174910);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00174988);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00174BF0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00174D58);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00174D78);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00175588);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_001756A0);

#include "m2c_macros.h"
s32 func_001734B8_1759D8() __asm__("func_001734B8");
M2C_UNK func_00268260_1759D8() __asm__("func_00268260");

void func_001759D8(s32 arg0, void* arg1) {
    s32* temp_v0;
    void* temp_v0_2;

    if (arg1 != NULL) {
        temp_v0 = M2C_FIELD(arg1, s32** , 0x20D0);
        if (temp_v0 != NULL) {
            *temp_v0 = 0;
            if (func_001734B8_1759D8() != 0) {
                func_00268260_1759D8(M2C_FIELD(arg1, s32* , 0x20C4));
            }
            M2C_FIELD(arg1, s32** , 0x20D0) = NULL;
            M2C_FIELD(arg1, s32* , 0x20C4) = -1;
        }
        temp_v0_2 = M2C_FIELD(arg1, void** , 0x20D4);
        if (temp_v0_2 != NULL) {
            M2C_FIELD(temp_v0_2, s32* , 0xC) = 0;
            if (func_001734B8_1759D8(arg0) != 0) {
                func_00268260_1759D8(M2C_FIELD(arg1, s32* , 0x20C8));
            }
            M2C_FIELD(arg1, void** , 0x20D4) = NULL;
            M2C_FIELD(arg1, s32* , 0x20C8) = -1;
        }
        if (M2C_FIELD(arg1, s32* , 0x20D8) != 0) {
            if (func_001734B8_1759D8(arg0) != 0) {
                func_00268260_1759D8(M2C_FIELD(arg1, s32* , 0x20CC));
            }
            M2C_FIELD(arg1, s32* , 0x20D8) = 0;
            M2C_FIELD(arg1, s32* , 0x20CC) = -1;
        }
    }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00175AA0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_001761E8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00176580);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00176B10);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00176C20);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00176CC8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/net", func_00176EA0);

extern int* D_003156C4;
int func_00177028(int value) {
    int i;
    int* table = D_00321018[*D_003156C4];

    for (i = 0; i < 8; i++) {
        if (table[i] == value) {
            return i;
        }
    }
    return -1;
}

#include "m2c_macros.h"
M2C_UNK func_0016EC50_177078() __asm__("func_0016EC50");
extern M2C_UNK D_003156C0_177078 __asm__("D_003156C0");

void func_00177078(s32 arg0, s32 arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 != 0) {
            func_0016EC50_177078(&D_003156C0_177078);
        }
    }
}

#include "m2c_macros.h"
M2C_UNK func_00177078_1770A8() __asm__("func_00177078");

void func_001770A8(void) {
    func_00177078_1770A8(1, 0xFFFF);
}
