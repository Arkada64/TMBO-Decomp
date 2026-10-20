//@@ func_00162670
#include "m2c_macros.h"
extern M2C_UNK D_00313D70;

void func_00162670(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    strcpy(&D_00313D70, arg3 + 0x15);
}
//@@ func_00163EB8
#include "m2c_macros.h"
void func_00163EB8(void* arg0, s32 arg1) {
    M2C_FIELD(arg0, s32* , 4) = arg1;
}
//@@ func_00164F68
#include "m2c_macros.h"
void func_00164F68(void* arg0, s32 arg1, s32 arg2) {
    strcpy(arg0 + 0x525C4, arg0 + 0xC);
    M2C_FIELD(arg0, s32* , 0x525D8) = arg1;
    strcpy(arg0 + 0x525DC, arg2);
}
//@@ func_001667E0
#include "m2c_macros.h"
void func_001667E0(s32 arg0) {
    func_0025B938(arg0 + 0x52444);
}
//@@ func_00166918
#include "m2c_macros.h"
void func_00166918(s32 arg0) {
    func_0025B8AC(arg0 + 0x525C4);
}
//@@ func_001669A0
#include "m2c_macros.h"
extern s32 D_002C1698;

void func_001669A0(s32 arg0, s32 arg1) {
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        D_002C1698 = -1;
    }
}
//@@ func_0016D638
#include "m2c_macros.h"
s32 func_0016D638(void* arg0) {
    printf("Taking down the RTime Interface...\n");
    func_0028B414();
    func_00259D38();
    func_0026E4E8();
    M2C_FIELD(arg0, s32* , 0x1BBC) = 0;
    M2C_FIELD(arg0, s32* , 0x1BB8) = 4;
    return 0;
}
//@@ func_0016D7C0
#include "m2c_macros.h"
void func_0016D7C0(s32 arg0) {
    func_0016D638();
    func_0016D338(arg0);
}
//@@ func_0016D7F0
#include "m2c_macros.h"
s32 func_0016D7F0(void* arg0) {
    return M2C_FIELD(arg0, s32* , 0x4258);
}
//@@ func_0016D7F8
#include "m2c_macros.h"
s32 func_0016D7F8(void* arg0) {
    return M2C_FIELD(arg0, s32* , 0x4278);
}
//@@ func_0016D828
#include "m2c_macros.h"
s32 func_0016D828(void) {
    return 1;
}
//@@ func_0016E8B8
#include "m2c_macros.h"
s32 func_0016E8B8(s32 arg0) {
    func_0016E8E0();
    return arg0;
}
//@@ func_0016EB70
#include "m2c_macros.h"
void func_0016EB70(void* arg0) {
    M2C_FIELD(arg0, s32* , 0x768) = 0;
}
//@@ func_0016EC18
#include "m2c_macros.h"
extern s32 D_00319924;
extern M2C_UNK func_00168F30;

void func_0016EC18(void) {
    if (D_00319924 == 0) {
        func_002693D8(&func_00168F30);
    }
}
//@@ func_0016EF88
#include "m2c_macros.h"
s32 func_0016EF88(s32 arg0) {
    return arg0 + 0x1218;
}
//@@ func_0016F478
#include "m2c_macros.h"
s32 func_0016F478(s32 arg0, s32 arg1) {
    return arg1;
}
//@@ func_0016F480
#include "m2c_macros.h"
s32 func_0016F480(s32 arg0, s32 arg1) {
    return arg1;
}
//@@ func_00172320
#include "m2c_macros.h"
s32 func_00172320(s32 arg0) {
    s32 temp_s1;

    temp_s1 = arg0 + 0x1CC8;
    memset(temp_s1, 0, 0x1000);
    sprintf(temp_s1, "[MEDIUS_ACCOUNT] %s\n[MEDIUS_PASSWORD] %s\n", arg0 + 0x14AC, arg0 + 0x14EC);
    return 1;
}
//@@ func_00172A80
#include "m2c_macros.h"
s32 func_00172A80(void) {
    return 1;
}
//@@ func_00172A88
#include "m2c_macros.h"
s32 func_00172A88(void) {
    return 0;
}
//@@ func_00173340
#include "m2c_macros.h"
void func_00173340(void* arg0, s32 arg1, M2C_UNK arg2) {
    if ((((u32) *M2C_FIELD(arg0, u32** , 0x3148) >> 1) & 0xF) == 4) {
        if (func_001734B8(arg0) != 0) {
            func_00172FE8(arg0, arg1, arg2, -1);
        }
    }
    if ((((u32) *M2C_FIELD(arg0, u32** , 0x3148) >> 1) & 0xF) == 8) {
        if (func_001734B8(arg0) != 0) {
            func_00172FE8(arg0, arg1, arg2, M2C_FIELD(((arg1 * 0x220) + arg0), s32* , 0x14));
        }
    }
}
//@@ func_00177078
#include "m2c_macros.h"
extern M2C_UNK D_003156C0;

void func_00177078(s32 arg0, s32 arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 != 0) {
            func_0016EC50(&D_003156C0);
        }
    }
}
//@@ func_001770A8
#include "m2c_macros.h"
void func_001770A8(void) {
    func_00177078(1, 0xFFFF);
}
