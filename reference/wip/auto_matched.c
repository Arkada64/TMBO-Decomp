//@@ func_00162670
#include "m2c_macros.h"
M2C_UNK strcpy_162670() __asm__("strcpy");
extern M2C_UNK D_00313D70_162670 __asm__("D_00313D70");

void func_00162670(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    strcpy_162670(&D_00313D70_162670, arg3 + 0x15);
}
//@@ func_00162FA0
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
//@@ func_00163EB8
#include "m2c_macros.h"
void func_00163EB8(void* arg0, s32 arg1) {
    M2C_FIELD(arg0, s32* , 4) = arg1;
}
//@@ func_00164F68
#include "m2c_macros.h"
M2C_UNK strcpy_164F68() __asm__("strcpy");

void func_00164F68(void* arg0, s32 arg1, s32 arg2) {
    strcpy_164F68(arg0 + 0x525C4, arg0 + 0xC);
    M2C_FIELD(arg0, s32* , 0x525D8) = arg1;
    strcpy_164F68(arg0 + 0x525DC, arg2);
}
//@@ func_001667E0
#include "m2c_macros.h"
M2C_UNK func_0025B938_1667E0() __asm__("func_0025B938");

void func_001667E0(s32 arg0) {
    func_0025B938_1667E0(arg0 + 0x52444);
}
//@@ func_00166918
#include "m2c_macros.h"
M2C_UNK func_0025B8AC_166918() __asm__("func_0025B8AC");

void func_00166918(s32 arg0) {
    func_0025B8AC_166918(arg0 + 0x525C4);
}
//@@ func_001669A0
#include "m2c_macros.h"
extern s32 D_002C1698_1669A0 __asm__("D_002C1698");

void func_001669A0(s32 arg0, s32 arg1) {
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        D_002C1698_1669A0 = -1;
    }
}
//@@ func_0016D638
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
    M2C_FIELD(arg0, s32* , 0x1BBC) = 0;
    M2C_FIELD(arg0, s32* , 0x1BB8) = 4;
    return 0;
}
//@@ func_0016D7C0
#include "m2c_macros.h"
M2C_UNK func_0016D338_16D7C0() __asm__("func_0016D338");
M2C_UNK func_0016D638_16D7C0() __asm__("func_0016D638");

void func_0016D7C0(s32 arg0) {
    func_0016D638_16D7C0();
    func_0016D338_16D7C0(arg0);
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
M2C_UNK func_0016E8E0_16E8B8() __asm__("func_0016E8E0");

s32 func_0016E8B8(s32 arg0) {
    func_0016E8E0_16E8B8();
    return arg0;
}
//@@ func_0016EB70
#include "m2c_macros.h"
void func_0016EB70(void* arg0) {
    M2C_FIELD(arg0, s32* , 0x768) = 0;
}
//@@ func_0016EC18
#include "m2c_macros.h"
M2C_UNK func_002693D8_16EC18() __asm__("func_002693D8");
extern s32 D_00319924_16EC18 __asm__("D_00319924");
extern M2C_UNK func_00168F30_16EC18 __asm__("func_00168F30");

void func_0016EC18(void) {
    if (D_00319924_16EC18 == 0) {
        func_002693D8_16EC18(&func_00168F30_16EC18);
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
M2C_UNK memset_172320() __asm__("memset");
M2C_UNK sprintf_172320() __asm__("sprintf");

s32 func_00172320(s32 arg0) {
    s32 temp_s1;

    temp_s1 = arg0 + 0x1CC8;
    memset_172320(temp_s1, 0, 0x1000);
    sprintf_172320(temp_s1, "[MEDIUS_ACCOUNT] %s\n[MEDIUS_PASSWORD] %s\n", arg0 + 0x14AC, arg0 + 0x14EC);
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
M2C_UNK func_00172FE8_173340() __asm__("func_00172FE8");
s32 func_001734B8_173340() __asm__("func_001734B8");

void func_00173340(void* arg0, s32 arg1, M2C_UNK arg2) {
    if ((((u32) *M2C_FIELD(arg0, u32** , 0x3148) >> 1) & 0xF) == 4) {
        if (func_001734B8_173340(arg0) != 0) {
            func_00172FE8_173340(arg0, arg1, arg2, -1);
        }
    }
    if ((((u32) *M2C_FIELD(arg0, u32** , 0x3148) >> 1) & 0xF) == 8) {
        if (func_001734B8_173340(arg0) != 0) {
            func_00172FE8_173340(arg0, arg1, arg2, M2C_FIELD(((arg1 * 0x220) + arg0), s32* , 0x14));
        }
    }
}
//@@ func_00173ED0
#include "m2c_macros.h"
void* netGetDmeTime_173ED0() __asm__("netGetDmeTime");

s32 func_00173ED0(s32 arg0, s32 arg1, s32 arg2) {
    void* temp_v0;

    temp_v0 = netGetDmeTime_173ED0();
    if (temp_v0 != NULL) {
        M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), s32* , 0x24) = arg2;
        return 1;
    }
    return 0;
}
//@@ func_00173F10
#include "m2c_macros.h"
void* netGetDmeTime_173F10() __asm__("netGetDmeTime");

s32 func_00173F10(void) {
    void* temp_v0;

    temp_v0 = netGetDmeTime_173F10();
    if (temp_v0 != NULL) {
        return M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), s32* , 0x24);
    }
    return 0;
}
//@@ func_00173F40
#include "m2c_macros.h"
void* netGetDmeTime_173F40() __asm__("netGetDmeTime");

s32 func_00173F40(s32 arg0, s32 arg1, s32 arg2) {
    void* temp_v0;

    temp_v0 = netGetDmeTime_173F40();
    if (temp_v0 != NULL) {
        M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), s32* , 0x1C) = arg2;
        return 1;
    }
    return 0;
}
//@@ func_00173F80
#include "m2c_macros.h"
void* netGetDmeTime_173F80() __asm__("netGetDmeTime");

s32 func_00173F80(s32 arg0, s32 arg1, s32 arg2) {
    void* temp_v0;

    temp_v0 = netGetDmeTime_173F80();
    if (temp_v0 != NULL) {
        M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), s32* , 0x20) = arg2;
        return 1;
    }
    return 0;
}
//@@ func_00173FC0
#include "m2c_macros.h"
void* netGetDmeTime_173FC0() __asm__("netGetDmeTime");

s32 func_00173FC0(void) {
    void* temp_v0;

    temp_v0 = netGetDmeTime_173FC0();
    if (temp_v0 != NULL) {
        return M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), s32* , 0x20);
    }
    return 0;
}
//@@ func_00177078
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
//@@ func_001770A8
#include "m2c_macros.h"
M2C_UNK func_00177078_1770A8() __asm__("func_00177078");

void func_001770A8(void) {
    func_00177078_1770A8(1, 0xFFFF);
}
