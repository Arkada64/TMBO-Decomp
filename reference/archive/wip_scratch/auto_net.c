//@@ func_001625F0 m2c0
#include "m2c_macros.h"
M2C_UNK func_0010A7D8_1625F0() __asm__("func_0010A7D8");
M2C_UNK func_00166808_1625F0() __asm__("func_00166808");
s32 func_001734B8_1625F0() __asm__("func_001734B8");
extern M2C_UNK D_002B8A00_1625F0 __asm__("D_002B8A00");
extern M2C_UNK D_002C1690_1625F0 __asm__("D_002C1690");
extern M2C_UNK D_003156C0_1625F0 __asm__("D_003156C0");

void func_001625F0(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    M2C_FIELD(&D_002C1690_1625F0, s32* , 0x52438) = (s32) M2C_FIELD(arg3, s32* , 4);
    func_0010A7D8_1625F0(&D_002B8A00_1625F0, M2C_FIELD(arg3, s32* , 4));
    if ((M2C_FIELD(&D_003156C0_1625F0, s32* , 0x1BB4) > 0) && (func_001734B8_1625F0(&D_003156C0_1625F0) != 0)) {
        func_00166808_1625F0(&D_002C1690_1625F0, M2C_FIELD(&D_002C1690_1625F0, s32* , 0x52438));
    }
}
//@@ func_00162670 m2c0
#include "m2c_macros.h"
M2C_UNK strcpy_162670() __asm__("strcpy");
extern M2C_UNK D_00313D70_162670 __asm__("D_00313D70");

void func_00162670(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    strcpy_162670(&D_00313D70_162670, arg3 + 0x15);
}
//@@ func_00162698 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163EB8_162698() __asm__("func_00163EB8");
extern M2C_UNK D_002C1690_162698 __asm__("D_002C1690");

void func_00162698(s32 arg0) {
    M2C_FIELD(&D_002C1690_162698, s32* , 8) = arg0;
    if (arg0 == -1) {
        func_00163EB8_162698(&D_002C1690_162698, 0xFFFFFF);
    } else {
        func_00163EB8_162698(&D_002C1690_162698, 0);
    }
    M2C_FIELD(&D_002C1690_162698, s32* , 0) = 1;
}
//@@ func_001626F8 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163EB8_1626F8() __asm__("func_00163EB8");
M2C_UNK strcpy_1626F8() __asm__("strcpy");
extern s32 D_002C1690_1626F8 __asm__("D_002C1690");
extern M2C_UNK D_004F9C20_1626F8 __asm__("D_004F9C20");

void func_001626F8(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    func_00163EB8_1626F8(&D_002C1690_1626F8, M2C_FIELD(arg3, s32* , 0x18));
    if (M2C_FIELD(arg3, s32* , 0x18) == 0) {
        strcpy_1626F8(&D_002C1690_1626F8 + 0xC, arg3 + 0x1C);
    } else {
        strcpy_1626F8(&D_002C1690_1626F8 + 0xC, &D_004F9C20_1626F8);
    }
    D_002C1690_1626F8 = 1;
}
//@@ func_00162778 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163EB8_162778() __asm__("func_00163EB8");
extern s32 D_002C1690_162778 __asm__("D_002C1690");

void func_00162778(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    func_00163EB8_162778(&D_002C1690_162778, M2C_FIELD(arg3, s32* , 0x18));
    D_002C1690_162778 = 1;
}
//@@ func_001628E0 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163EB8_1628E0() __asm__("func_00163EB8");
extern s32 D_002C1690_1628E0 __asm__("D_002C1690");

void func_001628E0(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    func_00163EB8_1628E0(&D_002C1690_1628E0, M2C_FIELD(arg3, s32* , 0x18));
    D_002C1690_1628E0 = 1;
}
//@@ func_00162918 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163EB8_162918() __asm__("func_00163EB8");
extern s32 D_002C1690_162918 __asm__("D_002C1690");

void func_00162918(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    func_00163EB8_162918(&D_002C1690_162918, M2C_FIELD(arg3, s32* , 0x18));
    D_002C1690_162918 = 1;
}
//@@ func_00162950 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163EB8_162950() __asm__("func_00163EB8");
extern s32 D_002C1690_162950 __asm__("D_002C1690");

void func_00162950(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    func_00163EB8_162950(&D_002C1690_162950, M2C_FIELD(arg3, s32* , 0x18));
    D_002C1690_162950 = 1;
}
//@@ func_00162988 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163EB8_162988() __asm__("func_00163EB8");
extern s32 D_002C1690_162988 __asm__("D_002C1690");

void func_00162988(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    func_00163EB8_162988(&D_002C1690_162988, M2C_FIELD(arg3, s32* , 0x18));
    D_002C1690_162988 = 1;
}
//@@ func_001629C0 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163EB8_1629C0() __asm__("func_00163EB8");
extern M2C_UNK D_002C1690_1629C0 __asm__("D_002C1690");

void func_001629C0(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    M2C_FIELD(&D_002C1690_1629C0, s32* , 0x60) = (s32) M2C_FIELD(arg3, s32* , 0x18);
    func_00163EB8_1629C0(&D_002C1690_1629C0, M2C_FIELD(arg3, s32* , 0x1C));
    M2C_FIELD(&D_002C1690_1629C0, s32* , 0) = 1;
}
//@@ func_00162A00 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163EB8_162A00() __asm__("func_00163EB8");
extern s32 D_002C1690_162A00 __asm__("D_002C1690");

void func_00162A00(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    func_00163EB8_162A00(&D_002C1690_162A00, M2C_FIELD(arg3, s32* , 0x58));
    D_002C1690_162A00 = 1;
}
//@@ func_00162A38 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163EB8_162A38() __asm__("func_00163EB8");
M2C_UNK func_001641B8_162A38() __asm__("func_001641B8");
extern s32 D_002C1690_162A38 __asm__("D_002C1690");

void func_00162A38(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    void* temp_a1;

    func_00163EB8_162A38(&D_002C1690_162A38, M2C_FIELD(arg3, s32* , 0x18));
    if (M2C_FIELD(arg3, s32* , 0x18) == 0) {
        temp_a1 = arg3 + 0x1C;
        if (temp_a1 != NULL) {
            func_001641B8_162A38(&D_002C1690_162A38, temp_a1);
        }
    }
    if (M2C_FIELD(arg3, s8* , 0x11C) != 0) {
        D_002C1690_162A38 = 1;
    }
}
//@@ func_00162AB0 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163EB8_162AB0() __asm__("func_00163EB8");
M2C_UNK func_00164240_162AB0() __asm__("func_00164240");
extern s32 D_002C1690_162AB0 __asm__("D_002C1690");

void func_00162AB0(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    func_00163EB8_162AB0(&D_002C1690_162AB0, M2C_FIELD(arg3, s32* , 0x18));
    if (M2C_FIELD(arg3, s32* , 0x18) == 0) {
        func_00164240_162AB0(&D_002C1690_162AB0, arg3 + 0x20);
    }
    if (M2C_FIELD(arg3, s8* , 0x408) != 0) {
        D_002C1690_162AB0 = 1;
    }
}
//@@ func_00162B20 m2c0
#include "m2c_macros.h"
M2C_UNK func_001649D8_162B20() __asm__("func_001649D8");
M2C_UNK printf_162B20() __asm__("printf");
s32 strcmp_162B20() __asm__("strcmp");
extern M2C_UNK D_002C1690_162B20 __asm__("D_002C1690");
extern M2C_UNK D_00301690_162B20 __asm__("D_00301690");
extern M2C_UNK D_003156C0_162B20 __asm__("D_003156C0");
extern M2C_UNK D_004E58D0_162B20 __asm__("D_004E58D0");
extern s32 D_004F9C58_162B20 __asm__("D_004F9C58");
extern s32 D_004F9C5C_162B20 __asm__("D_004F9C5C");
extern s32 D_004F9C60_162B20 __asm__("D_004F9C60");
extern s32 D_004F9C64_162B20 __asm__("D_004F9C64");
extern s32 D_004F9C68_162B20 __asm__("D_004F9C68");
extern s32 D_004F9C6C_162B20 __asm__("D_004F9C6C");
extern s32 D_004F9C70_162B20 __asm__("D_004F9C70");
extern s32 D_004F9C74_162B20 __asm__("D_004F9C74");
extern s32 D_004F9C78_162B20 __asm__("D_004F9C78");
extern s32 D_004F9C7C_162B20 __asm__("D_004F9C7C");
extern s32 D_004F9C80_162B20 __asm__("D_004F9C80");
extern M2C_UNK func_001648B0_162B20 __asm__("func_001648B0");
extern M2C_UNK func_00164938_162B20 __asm__("func_00164938");

void func_00162B20(s32 arg0, s32 arg1, M2C_UNK* arg2) {
    s32 sp20;
    s32 temp_v0;
    s32 var_s5;
    s32 var_v1;
    s32* var_a0;
    void* temp_s0;
    void* var_a2;

    sp20 = arg1;
    if (arg0 != 0xFFFFFF) {
        D_004F9C58_162B20 -= 1;
    }
    if (D_004F9C58_162B20 < 0) {
        printf_162B20(&D_004E58D0_162B20);
        printf_162B20("!!!!     Ping Counter < 0  (%d)  !!!!\n", D_004F9C58_162B20);
        printf_162B20(&D_004E58D0_162B20);
    }
    if (M2C_FIELD(&D_002C1690_162B20, s32* , 0x41AB0) == 0) {
        if (M2C_FIELD(&D_002C1690_162B20, s32* , 0x406A4) == 0) {
            if (M2C_FIELD(&D_002C1690_162B20, s32* , 0x406A8) != 0) {
                var_s5 = 0;
                if (M2C_FIELD(&D_002C1690_162B20, s32* , 0x406A8) > 0) {
                    do {
                        temp_s0 = (var_s5 << 7) + 0x406AC + &D_002C1690_162B20;
                        if (strcmp_162B20(temp_s0 + 0x54, sp20) == 0) {
                            if (M2C_FIELD(temp_s0, M2C_UNK** , 0x7C) == (M2C_UNK* )0x270F) {
                                switch (arg0) {     /* irregular */
                                case 0x0:
                                case 0xFFFFFF:
                                    M2C_FIELD(temp_s0, M2C_UNK** , 0x7C) = arg2;
                                    D_004F9C60_162B20 += 1;
                                    if (M2C_FIELD(&D_003156C0_162B20, s32* , 0x4264) != 0) {
                                        var_a2 = temp_s0 + 4;
block_19:
                                        func_001649D8_162B20(&D_002C1690_162B20, M2C_FIELD(temp_s0, s32* , 0), var_a2, M2C_FIELD(temp_s0, s32* , 0x44), &func_00164938_162B20);
                                    } else {
                                        func_001649D8_162B20(&D_002C1690_162B20, M2C_FIELD(temp_s0, s32* , 0), temp_s0 + 4, M2C_FIELD(temp_s0, s32* , 0x44), arg2, &func_001648B0_162B20);
                                    }
                                    break;
                                case 0xE:
                                    M2C_FIELD(temp_s0, M2C_UNK** , 0x7C) = arg2;
                                    D_004F9C64_162B20 += 1;
                                    if (M2C_FIELD(&D_003156C0_162B20, s32* , 0x4264) != 0) {
                                        var_a2 = temp_s0 + 4;
                                        goto block_19;
                                    }
                                    func_001649D8_162B20(&D_002C1690_162B20, M2C_FIELD(temp_s0, s32* , 0), temp_s0 + 4, M2C_FIELD(temp_s0, s32* , 0x44), (M2C_UNK* )0x270E, &func_001648B0_162B20);
                                    break;
                                }
                            }
                        }
                        var_s5 += 1;
                    } while (var_s5 < M2C_FIELD(&D_00301690_162B20, s32* , 0x6A8));
                }
                var_v1 = 0;
                if (M2C_FIELD(&D_002C1690_162B20, s32* , 0x406A8) > 0) {
                    var_a0 = &D_002C1690_162B20 + 0x40728;
loop_25:
                    temp_v0 = *var_a0;
                    if (temp_v0 != 0x270F) {
                        var_v1 += 1;
                        if (temp_v0 != 0x2710) {
                            var_a0 += 0x80;
                            if (var_v1 >= M2C_FIELD(&D_002C1690_162B20, s32* , 0x406A8)) {
                                goto block_28;
                            }
                            goto loop_25;
                        }
                    }
                } else {
block_28:
                    if (D_004F9C58_162B20 == 0) {
                        M2C_FIELD(&D_002C1690_162B20, s32* , 0x406A4) = 1;
                        D_004F9C70_162B20 += D_004F9C5C_162B20;
                        D_004F9C74_162B20 += D_004F9C60_162B20;
                        D_004F9C78_162B20 += D_004F9C64_162B20;
                        D_004F9C7C_162B20 += D_004F9C68_162B20;
                        D_004F9C80_162B20 += D_004F9C6C_162B20;
                        D_004F9C5C_162B20 = 0;
                    }
                }
            }
        }
    }
}
//@@ func_00162F00 m2c0
#include "m2c_macros.h"
s32 func_00298010_162F00() __asm__("func_00298010");
s32 func_00299350_162F00() __asm__("func_00299350");
M2C_UNK strcpy_162F00() __asm__("strcpy");
extern M2C_UNK D_004F9C28_162F00 __asm__("D_004F9C28");
extern M2C_UNK D_004F9C30_162F00 __asm__("D_004F9C30");

void func_00162F00(void* arg0) {
    u8 sp[0x100];
    s32 var_a0;
    s32 var_s0;

    strcpy_162F00(sp);
    var_s0 = func_00299350_162F00(sp, &D_004F9C28_162F00);
    if (var_s0 != 0) {
        var_a0 = var_s0;
loop_2:
        if (func_00298010_162F00(var_a0, &D_004F9C30_162F00, 3) == 0) {
            strcpy_162F00(arg0, var_s0 + 4);
            return;
        }
        var_s0 = func_00299350_162F00(NULL, &D_004F9C28_162F00);
        var_a0 = var_s0;
        if (var_s0 == 0) {

        } else {
            goto loop_2;
        }
    }
}
//@@ func_00162F00 m2c1
#include "m2c_macros.h"
s32 func_00298010_162F00() __asm__("func_00298010");
s32 func_00299350_162F00() __asm__("func_00299350");
M2C_UNK strcpy_162F00() __asm__("strcpy");
extern M2C_UNK D_004F9C28_162F00 __asm__("D_004F9C28");
extern M2C_UNK D_004F9C30_162F00 __asm__("D_004F9C30");

void func_00162F00(void* arg0) {
    u8 sp[0xF0];
    s32 var_a0;
    s32 var_s0;

    strcpy_162F00(sp);
    var_s0 = func_00299350_162F00(sp, &D_004F9C28_162F00);
    if (var_s0 != 0) {
        var_a0 = var_s0;
loop_2:
        if (func_00298010_162F00(var_a0, &D_004F9C30_162F00, 3) == 0) {
            strcpy_162F00(arg0, var_s0 + 4);
            return;
        }
        var_s0 = func_00299350_162F00(NULL, &D_004F9C28_162F00);
        var_a0 = var_s0;
        if (var_s0 == 0) {

        } else {
            goto loop_2;
        }
    }
}
//@@ func_00162F00 m2c2
#include "m2c_macros.h"
s32 func_00298010_162F00() __asm__("func_00298010");
s32 func_00299350_162F00() __asm__("func_00299350");
M2C_UNK strcpy_162F00() __asm__("strcpy");
extern M2C_UNK D_004F9C28_162F00 __asm__("D_004F9C28");
extern M2C_UNK D_004F9C30_162F00 __asm__("D_004F9C30");

void func_00162F00(void* arg0) {
    u8 sp[0xE0];
    s32 var_a0;
    s32 var_s0;

    strcpy_162F00(sp);
    var_s0 = func_00299350_162F00(sp, &D_004F9C28_162F00);
    if (var_s0 != 0) {
        var_a0 = var_s0;
loop_2:
        if (func_00298010_162F00(var_a0, &D_004F9C30_162F00, 3) == 0) {
            strcpy_162F00(arg0, var_s0 + 4);
            return;
        }
        var_s0 = func_00299350_162F00(NULL, &D_004F9C28_162F00);
        var_a0 = var_s0;
        if (var_s0 == 0) {

        } else {
            goto loop_2;
        }
    }
}
//@@ func_00162F00 m2c3
#include "m2c_macros.h"
s32 func_00298010_162F00() __asm__("func_00298010");
s32 func_00299350_162F00() __asm__("func_00299350");
M2C_UNK strcpy_162F00() __asm__("strcpy");
extern M2C_UNK D_004F9C28_162F00 __asm__("D_004F9C28");
extern M2C_UNK D_004F9C30_162F00 __asm__("D_004F9C30");

void func_00162F00(void* arg0) {
    u8 sp[0xD0];
    s32 var_a0;
    s32 var_s0;

    strcpy_162F00(sp);
    var_s0 = func_00299350_162F00(sp, &D_004F9C28_162F00);
    if (var_s0 != 0) {
        var_a0 = var_s0;
loop_2:
        if (func_00298010_162F00(var_a0, &D_004F9C30_162F00, 3) == 0) {
            strcpy_162F00(arg0, var_s0 + 4);
            return;
        }
        var_s0 = func_00299350_162F00(NULL, &D_004F9C28_162F00);
        var_a0 = var_s0;
        if (var_s0 == 0) {

        } else {
            goto loop_2;
        }
    }
}
//@@ func_00162F00 m2c4
#include "m2c_macros.h"
s32 func_00298010_162F00() __asm__("func_00298010");
s32 func_00299350_162F00() __asm__("func_00299350");
M2C_UNK strcpy_162F00() __asm__("strcpy");
extern M2C_UNK D_004F9C28_162F00 __asm__("D_004F9C28");
extern M2C_UNK D_004F9C30_162F00 __asm__("D_004F9C30");

void func_00162F00(void* arg0) {
    u8 sp[0xC0];
    s32 var_a0;
    s32 var_s0;

    strcpy_162F00(sp);
    var_s0 = func_00299350_162F00(sp, &D_004F9C28_162F00);
    if (var_s0 != 0) {
        var_a0 = var_s0;
loop_2:
        if (func_00298010_162F00(var_a0, &D_004F9C30_162F00, 3) == 0) {
            strcpy_162F00(arg0, var_s0 + 4);
            return;
        }
        var_s0 = func_00299350_162F00(NULL, &D_004F9C28_162F00);
        var_a0 = var_s0;
        if (var_s0 == 0) {

        } else {
            goto loop_2;
        }
    }
}
//@@ func_00162F00 m2c5
#include "m2c_macros.h"
s32 func_00298010_162F00() __asm__("func_00298010");
s32 func_00299350_162F00() __asm__("func_00299350");
M2C_UNK strcpy_162F00() __asm__("strcpy");
extern M2C_UNK D_004F9C28_162F00 __asm__("D_004F9C28");
extern M2C_UNK D_004F9C30_162F00 __asm__("D_004F9C30");

void func_00162F00(void* arg0) {
    u8 sp[0xB0];
    s32 var_a0;
    s32 var_s0;

    strcpy_162F00(sp);
    var_s0 = func_00299350_162F00(sp, &D_004F9C28_162F00);
    if (var_s0 != 0) {
        var_a0 = var_s0;
loop_2:
        if (func_00298010_162F00(var_a0, &D_004F9C30_162F00, 3) == 0) {
            strcpy_162F00(arg0, var_s0 + 4);
            return;
        }
        var_s0 = func_00299350_162F00(NULL, &D_004F9C28_162F00);
        var_a0 = var_s0;
        if (var_s0 == 0) {

        } else {
            goto loop_2;
        }
    }
}
//@@ func_00162FA0 m2c0
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
//@@ func_00162FA0 m2c1
#include "m2c_macros.h"
s32 func_00298010_162FA0() __asm__("func_00298010");
s32 func_00299350_162FA0() __asm__("func_00299350");
M2C_UNK strcpy_162FA0() __asm__("strcpy");
extern M2C_UNK D_004F9C28_162FA0 __asm__("D_004F9C28");
extern M2C_UNK D_004F9C30_162FA0 __asm__("D_004F9C30");

void func_00162FA0(s32 arg0) {
    u8 sp[0xF0];
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
//@@ func_00162FA0 m2c2
#include "m2c_macros.h"
s32 func_00298010_162FA0() __asm__("func_00298010");
s32 func_00299350_162FA0() __asm__("func_00299350");
M2C_UNK strcpy_162FA0() __asm__("strcpy");
extern M2C_UNK D_004F9C28_162FA0 __asm__("D_004F9C28");
extern M2C_UNK D_004F9C30_162FA0 __asm__("D_004F9C30");

void func_00162FA0(s32 arg0) {
    u8 sp[0xE0];
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
//@@ func_00162FA0 m2c3
#include "m2c_macros.h"
s32 func_00298010_162FA0() __asm__("func_00298010");
s32 func_00299350_162FA0() __asm__("func_00299350");
M2C_UNK strcpy_162FA0() __asm__("strcpy");
extern M2C_UNK D_004F9C28_162FA0 __asm__("D_004F9C28");
extern M2C_UNK D_004F9C30_162FA0 __asm__("D_004F9C30");

void func_00162FA0(s32 arg0) {
    u8 sp[0xD0];
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
//@@ func_00162FA0 m2c4
#include "m2c_macros.h"
s32 func_00298010_162FA0() __asm__("func_00298010");
s32 func_00299350_162FA0() __asm__("func_00299350");
M2C_UNK strcpy_162FA0() __asm__("strcpy");
extern M2C_UNK D_004F9C28_162FA0 __asm__("D_004F9C28");
extern M2C_UNK D_004F9C30_162FA0 __asm__("D_004F9C30");

void func_00162FA0(s32 arg0) {
    u8 sp[0xC0];
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
//@@ func_00162FA0 m2c5
#include "m2c_macros.h"
s32 func_00298010_162FA0() __asm__("func_00298010");
s32 func_00299350_162FA0() __asm__("func_00299350");
M2C_UNK strcpy_162FA0() __asm__("strcpy");
extern M2C_UNK D_004F9C28_162FA0 __asm__("D_004F9C28");
extern M2C_UNK D_004F9C30_162FA0 __asm__("D_004F9C30");

void func_00162FA0(s32 arg0) {
    u8 sp[0xB0];
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
//@@ func_00163040 m2c0
#include "m2c_macros.h"
M2C_UNK func_00162B20_163040() __asm__("func_00162B20");
M2C_UNK func_00162F00_163040() __asm__("func_00162F00");
s32 func_00164610_163040() __asm__("func_00164610");
s32 func_0026B998_163040() __asm__("func_0026B998");
M2C_UNK printf_163040() __asm__("printf");
s32 strcmp_163040() __asm__("strcmp");
extern M2C_UNK D_002C1690_163040 __asm__("D_002C1690");
extern M2C_UNK D_004E58D0_163040 __asm__("D_004E58D0");
extern M2C_UNK D_004F9C38_163040 __asm__("D_004F9C38");
extern s32 D_004F9C58_163040 __asm__("D_004F9C58");

void func_00163040(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    M2C_UNK sp10;
    M2C_UNK* var_s0;
    M2C_UNK* var_s3;
    s32 temp_a2;
    s32 temp_s0;
    s32 var_s2;

    temp_s0 = arg3 + 0x134;
    func_00162F00_163040(&sp10, arg3 + 0x34);
    if (func_00164610_163040(&D_002C1690_163040, temp_s0, M2C_FIELD(arg3, s32* , 0x174), M2C_FIELD(arg3, s32* , 0x28)) == 0) {
        printf_163040("Game %s not found in the current temp list\n", temp_s0);
    } else if (strcmp_163040(&sp10, &D_004F9C38_163040) == 0) {
        printf_163040("No IP address found for game %s\n", temp_s0);
    } else {
        var_s2 = 0;
        if (M2C_FIELD(&D_002C1690_163040, s32* , 0x406A8) > 0) {
            var_s0 = &D_002C1690_163040 + 0x40700;
            var_s3 = &D_002C1690_163040 + 0x406B0;
loop_6:
            if (strcmp_163040(var_s0, &sp10) != 0) {
                goto block_14;
            }
            if (strcmp_163040(var_s3, arg3 + 0x134) == 0) {
block_14:
                var_s2 += 1;
                var_s3 += 0x80;
                var_s0 += 0x80;
                if (var_s2 >= M2C_FIELD(&D_002C1690_163040, s32* , 0x406A8)) {
                    goto block_15;
                }
                goto loop_6;
            }
            temp_a2 = M2C_FIELD(var_s0, s32* , 0x28);
            if (temp_a2 < 0x270F) {
                func_00162B20_163040(0xFFFFFF, var_s0, temp_a2);
            }
        } else {
block_15:
            if (func_0026B998_163040(&sp10, func_00162B20_163040) == 0) {
                D_004F9C58_163040 += 1;
            }
            if (D_004F9C58_163040 >= 0x29) {
                printf_163040(&D_004E58D0_163040);
                printf_163040("!!!!     Ping Counter < %d (%d)  !!!!\n", 0x28, D_004F9C58_163040);
                printf_163040(&D_004E58D0_163040);
            }
        }
    }
}
//@@ func_00163200 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163EB8_163200() __asm__("func_00163EB8");
M2C_UNK printf_163200() __asm__("printf");
extern M2C_UNK D_002C1690_163200 __asm__("D_002C1690");

void func_00163200(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    printf_163200("%d TOTAL GAMES\n", M2C_FIELD(arg3, s32* , 0x18));
    M2C_FIELD(&D_002C1690_163200, s32* , 0x41AAC) = (s32) M2C_FIELD(arg3, s32* , 0x18);
    M2C_FIELD((&D_002C1690_163200 + 0x41AB8), s32* , 0x50) = (s32) M2C_FIELD(arg3, s32* , 0x18);
    func_00163EB8_163200(&D_002C1690_163200, M2C_FIELD(arg3, s32* , 0x1C));
    M2C_FIELD(&D_002C1690_163200, s32* , 0) = 1;
}
//@@ func_00163278 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163EB8_163278() __asm__("func_00163EB8");
M2C_UNK func_001644D0_163278() __asm__("func_001644D0");
M2C_UNK func_0025B1D0_163278() __asm__("func_0025B1D0");
M2C_UNK func_0025BD88_163278() __asm__("func_0025BD88");
M2C_UNK printf_163278() __asm__("printf");
s32 strcmp_163278() __asm__("strcmp");
M2C_UNK strcpy_163278() __asm__("strcpy");
extern M2C_UNK D_002C1690_163278 __asm__("D_002C1690");
extern M2C_UNK D_00313EE0_163278 __asm__("D_00313EE0");
extern s32 D_004F9C5C_163278 __asm__("D_004F9C5C");
extern s32 D_004F9C60_163278 __asm__("D_004F9C60");
extern s32 D_004F9C64_163278 __asm__("D_004F9C64");
extern s32 D_004F9C68_163278 __asm__("D_004F9C68");
extern s32 D_004F9C6C_163278 __asm__("D_004F9C6C");
extern s32 D_004F9C70_163278 __asm__("D_004F9C70");
extern s32 D_004F9C74_163278 __asm__("D_004F9C74");
extern s32 D_004F9C78_163278 __asm__("D_004F9C78");
extern s32 D_004F9C7C_163278 __asm__("D_004F9C7C");
extern s32 D_004F9C80_163278 __asm__("D_004F9C80");
extern s32 D_004F9C84_163278 __asm__("D_004F9C84");
extern M2C_UNK func_00163040_163278 __asm__("func_00163040");

void func_00163278(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_a3_2;
    s32 temp_t6;

    func_00163EB8_163278(&D_002C1690_163278, M2C_FIELD(arg3, s32* , 0x18));
    if (strcmp_163278(arg3, &D_00313EE0_163278) != 0) {
        printf_163278("Received a GameListResponse for a game not in this page.\n");
    } else {
        if (M2C_FIELD(arg3, s32* , 0x18) == 0) {
            temp_a3 = M2C_FIELD(arg3, s32* , 0x60);
            if (temp_a3 != 0) {
                D_004F9C5C_163278 += 1;
                func_001644D0_163278(&D_002C1690_163278, M2C_FIELD(arg3, s32* , 0x1C), arg3 + 0x20, temp_a3);
                func_0025BD88_163278(&D_002C1690_163278 + 0x11, 0x1C, sp);
                strcpy_163278(&sp15, &D_002C1690_163278 + 0xC);
                sp28 = M2C_FIELD(arg3, s32* , 0x1C);
                func_0025B1D0_163278(sp, &func_00163040_163278);
            }
        }
        if (M2C_FIELD(arg3, s8* , 0x6C) != 0) {
            printf_163278("Reached the end of this page. Games read %d\n", D_004F9C5C_163278);
            D_004F9C84_163278 = 1;
        }
        if (M2C_FIELD(arg3, s32* , 0x18) < 0) {
            M2C_FIELD(&D_002C1690_163278, s32* , 0x41AB0) = 1;
            temp_a3_2 = D_004F9C7C_163278 + D_004F9C68_163278;
            temp_a2 = D_004F9C80_163278 + D_004F9C6C_163278;
            D_004F9C74_163278 += D_004F9C60_163278;
            D_004F9C78_163278 += D_004F9C64_163278;
            D_004F9C7C_163278 = temp_a3_2;
            D_004F9C80_163278 = temp_a2;
            D_004F9C70_163278 += D_004F9C5C_163278;
            M2C_FIELD(&D_002C1690_163278, s32* , 0x406A4) = 1;
            D_004F9C5C_163278 = 0;
            printf_163278("End of List = %d (Server Error - Aborted List)\n", 1, temp_a2, temp_a3_2);
            printf_163278("List Stats: Count:%d, Ready:%d, TimedOut:%d, NoPing:%d, Tossed:%d\n", D_004F9C70_163278, D_004F9C74_163278, D_004F9C78_163278);
        }
        temp_t6 = M2C_FIELD(arg3, s32* , 0x18);
        if (temp_t6 == 1) {
            M2C_FIELD(&D_002C1690_163278, s32* , 0x41AB0) = temp_t6;
            D_004F9C7C_163278 += D_004F9C68_163278;
            D_004F9C70_163278 += D_004F9C5C_163278;
            D_004F9C74_163278 += D_004F9C60_163278;
            D_004F9C78_163278 += D_004F9C64_163278;
            D_004F9C80_163278 += D_004F9C6C_163278;
            M2C_FIELD(&D_002C1690_163278, s32* , 0x406A4) = temp_t6;
            D_004F9C5C_163278 = 0;
            printf_163278("End of List = %d\n", 1, D_004F9C64_163278, D_004F9C68_163278);
            printf_163278("List Stats: Count:%d, Ready:%d, TimedOut:%d, NoPing:%d, Tossed:%d\n", D_004F9C70_163278, D_004F9C74_163278, D_004F9C78_163278);
        }
    }
}
//@@ func_00163278 m2c1
#include "m2c_macros.h"
M2C_UNK func_00163EB8_163278() __asm__("func_00163EB8");
M2C_UNK func_001644D0_163278() __asm__("func_001644D0");
M2C_UNK func_0025B1D0_163278() __asm__("func_0025B1D0");
M2C_UNK func_0025BD88_163278() __asm__("func_0025BD88");
M2C_UNK printf_163278() __asm__("printf");
s32 strcmp_163278() __asm__("strcmp");
M2C_UNK strcpy_163278() __asm__("strcpy");
extern M2C_UNK D_002C1690_163278 __asm__("D_002C1690");
extern M2C_UNK D_00313EE0_163278 __asm__("D_00313EE0");
extern s32 D_004F9C5C_163278 __asm__("D_004F9C5C");
extern s32 D_004F9C60_163278 __asm__("D_004F9C60");
extern s32 D_004F9C64_163278 __asm__("D_004F9C64");
extern s32 D_004F9C68_163278 __asm__("D_004F9C68");
extern s32 D_004F9C6C_163278 __asm__("D_004F9C6C");
extern s32 D_004F9C70_163278 __asm__("D_004F9C70");
extern s32 D_004F9C74_163278 __asm__("D_004F9C74");
extern s32 D_004F9C78_163278 __asm__("D_004F9C78");
extern s32 D_004F9C7C_163278 __asm__("D_004F9C7C");
extern s32 D_004F9C80_163278 __asm__("D_004F9C80");
extern s32 D_004F9C84_163278 __asm__("D_004F9C84");
extern M2C_UNK func_00163040_163278 __asm__("func_00163040");

void func_00163278(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    u8 sp[0x20];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_a3_2;
    s32 temp_t6;

    func_00163EB8_163278(&D_002C1690_163278, M2C_FIELD(arg3, s32* , 0x18));
    if (strcmp_163278(arg3, &D_00313EE0_163278) != 0) {
        printf_163278("Received a GameListResponse for a game not in this page.\n");
    } else {
        if (M2C_FIELD(arg3, s32* , 0x18) == 0) {
            temp_a3 = M2C_FIELD(arg3, s32* , 0x60);
            if (temp_a3 != 0) {
                D_004F9C5C_163278 += 1;
                func_001644D0_163278(&D_002C1690_163278, M2C_FIELD(arg3, s32* , 0x1C), arg3 + 0x20, temp_a3);
                func_0025BD88_163278(&D_002C1690_163278 + 0x11, 0x1C, sp);
                strcpy_163278(&sp15, &D_002C1690_163278 + 0xC);
                sp28 = M2C_FIELD(arg3, s32* , 0x1C);
                func_0025B1D0_163278(sp, &func_00163040_163278);
            }
        }
        if (M2C_FIELD(arg3, s8* , 0x6C) != 0) {
            printf_163278("Reached the end of this page. Games read %d\n", D_004F9C5C_163278);
            D_004F9C84_163278 = 1;
        }
        if (M2C_FIELD(arg3, s32* , 0x18) < 0) {
            M2C_FIELD(&D_002C1690_163278, s32* , 0x41AB0) = 1;
            temp_a3_2 = D_004F9C7C_163278 + D_004F9C68_163278;
            temp_a2 = D_004F9C80_163278 + D_004F9C6C_163278;
            D_004F9C74_163278 += D_004F9C60_163278;
            D_004F9C78_163278 += D_004F9C64_163278;
            D_004F9C7C_163278 = temp_a3_2;
            D_004F9C80_163278 = temp_a2;
            D_004F9C70_163278 += D_004F9C5C_163278;
            M2C_FIELD(&D_002C1690_163278, s32* , 0x406A4) = 1;
            D_004F9C5C_163278 = 0;
            printf_163278("End of List = %d (Server Error - Aborted List)\n", 1, temp_a2, temp_a3_2);
            printf_163278("List Stats: Count:%d, Ready:%d, TimedOut:%d, NoPing:%d, Tossed:%d\n", D_004F9C70_163278, D_004F9C74_163278, D_004F9C78_163278);
        }
        temp_t6 = M2C_FIELD(arg3, s32* , 0x18);
        if (temp_t6 == 1) {
            M2C_FIELD(&D_002C1690_163278, s32* , 0x41AB0) = temp_t6;
            D_004F9C7C_163278 += D_004F9C68_163278;
            D_004F9C70_163278 += D_004F9C5C_163278;
            D_004F9C74_163278 += D_004F9C60_163278;
            D_004F9C78_163278 += D_004F9C64_163278;
            D_004F9C80_163278 += D_004F9C6C_163278;
            M2C_FIELD(&D_002C1690_163278, s32* , 0x406A4) = temp_t6;
            D_004F9C5C_163278 = 0;
            printf_163278("End of List = %d\n", 1, D_004F9C64_163278, D_004F9C68_163278);
            printf_163278("List Stats: Count:%d, Ready:%d, TimedOut:%d, NoPing:%d, Tossed:%d\n", D_004F9C70_163278, D_004F9C74_163278, D_004F9C78_163278);
        }
    }
}
//@@ func_00163278 m2c2
#include "m2c_macros.h"
M2C_UNK func_00163EB8_163278() __asm__("func_00163EB8");
M2C_UNK func_001644D0_163278() __asm__("func_001644D0");
M2C_UNK func_0025B1D0_163278() __asm__("func_0025B1D0");
M2C_UNK func_0025BD88_163278() __asm__("func_0025BD88");
M2C_UNK printf_163278() __asm__("printf");
s32 strcmp_163278() __asm__("strcmp");
M2C_UNK strcpy_163278() __asm__("strcpy");
extern M2C_UNK D_002C1690_163278 __asm__("D_002C1690");
extern M2C_UNK D_00313EE0_163278 __asm__("D_00313EE0");
extern s32 D_004F9C5C_163278 __asm__("D_004F9C5C");
extern s32 D_004F9C60_163278 __asm__("D_004F9C60");
extern s32 D_004F9C64_163278 __asm__("D_004F9C64");
extern s32 D_004F9C68_163278 __asm__("D_004F9C68");
extern s32 D_004F9C6C_163278 __asm__("D_004F9C6C");
extern s32 D_004F9C70_163278 __asm__("D_004F9C70");
extern s32 D_004F9C74_163278 __asm__("D_004F9C74");
extern s32 D_004F9C78_163278 __asm__("D_004F9C78");
extern s32 D_004F9C7C_163278 __asm__("D_004F9C7C");
extern s32 D_004F9C80_163278 __asm__("D_004F9C80");
extern s32 D_004F9C84_163278 __asm__("D_004F9C84");
extern M2C_UNK func_00163040_163278 __asm__("func_00163040");

void func_00163278(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    u8 sp[0x10];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_a3_2;
    s32 temp_t6;

    func_00163EB8_163278(&D_002C1690_163278, M2C_FIELD(arg3, s32* , 0x18));
    if (strcmp_163278(arg3, &D_00313EE0_163278) != 0) {
        printf_163278("Received a GameListResponse for a game not in this page.\n");
    } else {
        if (M2C_FIELD(arg3, s32* , 0x18) == 0) {
            temp_a3 = M2C_FIELD(arg3, s32* , 0x60);
            if (temp_a3 != 0) {
                D_004F9C5C_163278 += 1;
                func_001644D0_163278(&D_002C1690_163278, M2C_FIELD(arg3, s32* , 0x1C), arg3 + 0x20, temp_a3);
                func_0025BD88_163278(&D_002C1690_163278 + 0x11, 0x1C, sp);
                strcpy_163278(&sp15, &D_002C1690_163278 + 0xC);
                sp28 = M2C_FIELD(arg3, s32* , 0x1C);
                func_0025B1D0_163278(sp, &func_00163040_163278);
            }
        }
        if (M2C_FIELD(arg3, s8* , 0x6C) != 0) {
            printf_163278("Reached the end of this page. Games read %d\n", D_004F9C5C_163278);
            D_004F9C84_163278 = 1;
        }
        if (M2C_FIELD(arg3, s32* , 0x18) < 0) {
            M2C_FIELD(&D_002C1690_163278, s32* , 0x41AB0) = 1;
            temp_a3_2 = D_004F9C7C_163278 + D_004F9C68_163278;
            temp_a2 = D_004F9C80_163278 + D_004F9C6C_163278;
            D_004F9C74_163278 += D_004F9C60_163278;
            D_004F9C78_163278 += D_004F9C64_163278;
            D_004F9C7C_163278 = temp_a3_2;
            D_004F9C80_163278 = temp_a2;
            D_004F9C70_163278 += D_004F9C5C_163278;
            M2C_FIELD(&D_002C1690_163278, s32* , 0x406A4) = 1;
            D_004F9C5C_163278 = 0;
            printf_163278("End of List = %d (Server Error - Aborted List)\n", 1, temp_a2, temp_a3_2);
            printf_163278("List Stats: Count:%d, Ready:%d, TimedOut:%d, NoPing:%d, Tossed:%d\n", D_004F9C70_163278, D_004F9C74_163278, D_004F9C78_163278);
        }
        temp_t6 = M2C_FIELD(arg3, s32* , 0x18);
        if (temp_t6 == 1) {
            M2C_FIELD(&D_002C1690_163278, s32* , 0x41AB0) = temp_t6;
            D_004F9C7C_163278 += D_004F9C68_163278;
            D_004F9C70_163278 += D_004F9C5C_163278;
            D_004F9C74_163278 += D_004F9C60_163278;
            D_004F9C78_163278 += D_004F9C64_163278;
            D_004F9C80_163278 += D_004F9C6C_163278;
            M2C_FIELD(&D_002C1690_163278, s32* , 0x406A4) = temp_t6;
            D_004F9C5C_163278 = 0;
            printf_163278("End of List = %d\n", 1, D_004F9C64_163278, D_004F9C68_163278);
            printf_163278("List Stats: Count:%d, Ready:%d, TimedOut:%d, NoPing:%d, Tossed:%d\n", D_004F9C70_163278, D_004F9C74_163278, D_004F9C78_163278);
        }
    }
}
//@@ func_00163278 m2c3
#include "m2c_macros.h"
M2C_UNK func_00163EB8_163278() __asm__("func_00163EB8");
M2C_UNK func_001644D0_163278() __asm__("func_001644D0");
M2C_UNK func_0025B1D0_163278() __asm__("func_0025B1D0");
M2C_UNK func_0025BD88_163278() __asm__("func_0025BD88");
M2C_UNK printf_163278() __asm__("printf");
s32 strcmp_163278() __asm__("strcmp");
M2C_UNK strcpy_163278() __asm__("strcpy");
extern M2C_UNK D_002C1690_163278 __asm__("D_002C1690");
extern M2C_UNK D_00313EE0_163278 __asm__("D_00313EE0");
extern s32 D_004F9C5C_163278 __asm__("D_004F9C5C");
extern s32 D_004F9C60_163278 __asm__("D_004F9C60");
extern s32 D_004F9C64_163278 __asm__("D_004F9C64");
extern s32 D_004F9C68_163278 __asm__("D_004F9C68");
extern s32 D_004F9C6C_163278 __asm__("D_004F9C6C");
extern s32 D_004F9C70_163278 __asm__("D_004F9C70");
extern s32 D_004F9C74_163278 __asm__("D_004F9C74");
extern s32 D_004F9C78_163278 __asm__("D_004F9C78");
extern s32 D_004F9C7C_163278 __asm__("D_004F9C7C");
extern s32 D_004F9C80_163278 __asm__("D_004F9C80");
extern s32 D_004F9C84_163278 __asm__("D_004F9C84");
extern M2C_UNK func_00163040_163278 __asm__("func_00163040");

void func_00163278(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    u8 sp[0x8];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_a3_2;
    s32 temp_t6;

    func_00163EB8_163278(&D_002C1690_163278, M2C_FIELD(arg3, s32* , 0x18));
    if (strcmp_163278(arg3, &D_00313EE0_163278) != 0) {
        printf_163278("Received a GameListResponse for a game not in this page.\n");
    } else {
        if (M2C_FIELD(arg3, s32* , 0x18) == 0) {
            temp_a3 = M2C_FIELD(arg3, s32* , 0x60);
            if (temp_a3 != 0) {
                D_004F9C5C_163278 += 1;
                func_001644D0_163278(&D_002C1690_163278, M2C_FIELD(arg3, s32* , 0x1C), arg3 + 0x20, temp_a3);
                func_0025BD88_163278(&D_002C1690_163278 + 0x11, 0x1C, sp);
                strcpy_163278(&sp15, &D_002C1690_163278 + 0xC);
                sp28 = M2C_FIELD(arg3, s32* , 0x1C);
                func_0025B1D0_163278(sp, &func_00163040_163278);
            }
        }
        if (M2C_FIELD(arg3, s8* , 0x6C) != 0) {
            printf_163278("Reached the end of this page. Games read %d\n", D_004F9C5C_163278);
            D_004F9C84_163278 = 1;
        }
        if (M2C_FIELD(arg3, s32* , 0x18) < 0) {
            M2C_FIELD(&D_002C1690_163278, s32* , 0x41AB0) = 1;
            temp_a3_2 = D_004F9C7C_163278 + D_004F9C68_163278;
            temp_a2 = D_004F9C80_163278 + D_004F9C6C_163278;
            D_004F9C74_163278 += D_004F9C60_163278;
            D_004F9C78_163278 += D_004F9C64_163278;
            D_004F9C7C_163278 = temp_a3_2;
            D_004F9C80_163278 = temp_a2;
            D_004F9C70_163278 += D_004F9C5C_163278;
            M2C_FIELD(&D_002C1690_163278, s32* , 0x406A4) = 1;
            D_004F9C5C_163278 = 0;
            printf_163278("End of List = %d (Server Error - Aborted List)\n", 1, temp_a2, temp_a3_2);
            printf_163278("List Stats: Count:%d, Ready:%d, TimedOut:%d, NoPing:%d, Tossed:%d\n", D_004F9C70_163278, D_004F9C74_163278, D_004F9C78_163278);
        }
        temp_t6 = M2C_FIELD(arg3, s32* , 0x18);
        if (temp_t6 == 1) {
            M2C_FIELD(&D_002C1690_163278, s32* , 0x41AB0) = temp_t6;
            D_004F9C7C_163278 += D_004F9C68_163278;
            D_004F9C70_163278 += D_004F9C5C_163278;
            D_004F9C74_163278 += D_004F9C60_163278;
            D_004F9C78_163278 += D_004F9C64_163278;
            D_004F9C80_163278 += D_004F9C6C_163278;
            M2C_FIELD(&D_002C1690_163278, s32* , 0x406A4) = temp_t6;
            D_004F9C5C_163278 = 0;
            printf_163278("End of List = %d\n", 1, D_004F9C64_163278, D_004F9C68_163278);
            printf_163278("List Stats: Count:%d, Ready:%d, TimedOut:%d, NoPing:%d, Tossed:%d\n", D_004F9C70_163278, D_004F9C74_163278, D_004F9C78_163278);
        }
    }
}
//@@ func_00163278 m2c4
#include "m2c_macros.h"
M2C_UNK func_00163EB8_163278() __asm__("func_00163EB8");
M2C_UNK func_001644D0_163278() __asm__("func_001644D0");
M2C_UNK func_0025B1D0_163278() __asm__("func_0025B1D0");
M2C_UNK func_0025BD88_163278() __asm__("func_0025BD88");
M2C_UNK printf_163278() __asm__("printf");
s32 strcmp_163278() __asm__("strcmp");
M2C_UNK strcpy_163278() __asm__("strcpy");
extern M2C_UNK D_002C1690_163278 __asm__("D_002C1690");
extern M2C_UNK D_00313EE0_163278 __asm__("D_00313EE0");
extern s32 D_004F9C5C_163278 __asm__("D_004F9C5C");
extern s32 D_004F9C60_163278 __asm__("D_004F9C60");
extern s32 D_004F9C64_163278 __asm__("D_004F9C64");
extern s32 D_004F9C68_163278 __asm__("D_004F9C68");
extern s32 D_004F9C6C_163278 __asm__("D_004F9C6C");
extern s32 D_004F9C70_163278 __asm__("D_004F9C70");
extern s32 D_004F9C74_163278 __asm__("D_004F9C74");
extern s32 D_004F9C78_163278 __asm__("D_004F9C78");
extern s32 D_004F9C7C_163278 __asm__("D_004F9C7C");
extern s32 D_004F9C80_163278 __asm__("D_004F9C80");
extern s32 D_004F9C84_163278 __asm__("D_004F9C84");
extern M2C_UNK func_00163040_163278 __asm__("func_00163040");

void func_00163278(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    u8 sp[0x4];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_a3_2;
    s32 temp_t6;

    func_00163EB8_163278(&D_002C1690_163278, M2C_FIELD(arg3, s32* , 0x18));
    if (strcmp_163278(arg3, &D_00313EE0_163278) != 0) {
        printf_163278("Received a GameListResponse for a game not in this page.\n");
    } else {
        if (M2C_FIELD(arg3, s32* , 0x18) == 0) {
            temp_a3 = M2C_FIELD(arg3, s32* , 0x60);
            if (temp_a3 != 0) {
                D_004F9C5C_163278 += 1;
                func_001644D0_163278(&D_002C1690_163278, M2C_FIELD(arg3, s32* , 0x1C), arg3 + 0x20, temp_a3);
                func_0025BD88_163278(&D_002C1690_163278 + 0x11, 0x1C, sp);
                strcpy_163278(&sp15, &D_002C1690_163278 + 0xC);
                sp28 = M2C_FIELD(arg3, s32* , 0x1C);
                func_0025B1D0_163278(sp, &func_00163040_163278);
            }
        }
        if (M2C_FIELD(arg3, s8* , 0x6C) != 0) {
            printf_163278("Reached the end of this page. Games read %d\n", D_004F9C5C_163278);
            D_004F9C84_163278 = 1;
        }
        if (M2C_FIELD(arg3, s32* , 0x18) < 0) {
            M2C_FIELD(&D_002C1690_163278, s32* , 0x41AB0) = 1;
            temp_a3_2 = D_004F9C7C_163278 + D_004F9C68_163278;
            temp_a2 = D_004F9C80_163278 + D_004F9C6C_163278;
            D_004F9C74_163278 += D_004F9C60_163278;
            D_004F9C78_163278 += D_004F9C64_163278;
            D_004F9C7C_163278 = temp_a3_2;
            D_004F9C80_163278 = temp_a2;
            D_004F9C70_163278 += D_004F9C5C_163278;
            M2C_FIELD(&D_002C1690_163278, s32* , 0x406A4) = 1;
            D_004F9C5C_163278 = 0;
            printf_163278("End of List = %d (Server Error - Aborted List)\n", 1, temp_a2, temp_a3_2);
            printf_163278("List Stats: Count:%d, Ready:%d, TimedOut:%d, NoPing:%d, Tossed:%d\n", D_004F9C70_163278, D_004F9C74_163278, D_004F9C78_163278);
        }
        temp_t6 = M2C_FIELD(arg3, s32* , 0x18);
        if (temp_t6 == 1) {
            M2C_FIELD(&D_002C1690_163278, s32* , 0x41AB0) = temp_t6;
            D_004F9C7C_163278 += D_004F9C68_163278;
            D_004F9C70_163278 += D_004F9C5C_163278;
            D_004F9C74_163278 += D_004F9C60_163278;
            D_004F9C78_163278 += D_004F9C64_163278;
            D_004F9C80_163278 += D_004F9C6C_163278;
            M2C_FIELD(&D_002C1690_163278, s32* , 0x406A4) = temp_t6;
            D_004F9C5C_163278 = 0;
            printf_163278("End of List = %d\n", 1, D_004F9C64_163278, D_004F9C68_163278);
            printf_163278("List Stats: Count:%d, Ready:%d, TimedOut:%d, NoPing:%d, Tossed:%d\n", D_004F9C70_163278, D_004F9C74_163278, D_004F9C78_163278);
        }
    }
}
//@@ func_00163560 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163EB8_163560() __asm__("func_00163EB8");
M2C_UNK func_00164E60_163560() __asm__("func_00164E60");
M2C_UNK func_0025B090_163560() __asm__("func_0025B090");
M2C_UNK func_0025BD88_163560() __asm__("func_0025BD88");
M2C_UNK strcpy_163560() __asm__("strcpy");
extern M2C_UNK D_002C1690_163560 __asm__("D_002C1690");
extern M2C_UNK func_00163658_163560 __asm__("func_00163658");

void func_00163560(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    M2C_UNK sp30;
    M2C_UNK sp45;
    s32 sp58;

    func_00163EB8_163560(&D_002C1690_163560, M2C_FIELD(arg3, s32* , 0x18));
    if (M2C_FIELD(arg3, s32* , 0x18) == 0) {
        func_00164E60_163560(&D_002C1690_163560, M2C_FIELD(&D_002C1690_163560, s32* , 0x52438), M2C_FIELD(arg3, s32* , 0x30), arg3 + 0x134, M2C_FIELD(arg3, s32* , 0x178), M2C_FIELD(arg3, s32* , 0x17C), M2C_FIELD(arg3, s32* , 0x180), M2C_FIELD(arg3, s32* , 0x184));
        func_0025BD88_163560(&D_002C1690_163560 + 0x11, 0x1F, &sp30);
        strcpy_163560(&D_002C1690_163560 + 0x51AF0, &sp30);
        strcpy_163560(&sp45, &D_002C1690_163560 + 0xC);
        sp58 = M2C_FIELD(&D_002C1690_163560, s32* , 0x51B0C);
        func_0025B090_163560(&sp30, &func_00163658_163560);
    }
}
//@@ func_00163658 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163EB8_163658() __asm__("func_00163EB8");
M2C_UNK func_00164B60_163658() __asm__("func_00164B60");
M2C_UNK printf_163658() __asm__("printf");
s32 strcmp_163658() __asm__("strcmp");
extern M2C_UNK D_002C1690_163658 __asm__("D_002C1690");

void func_00163658(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    void* temp_s0;

    temp_s0 = &D_002C1690_163658 + 0x51AF0;
    printf_163658("PlayerListHandler() called <<<%s>>>   <<<%s>>>)\n", temp_s0, arg3);
    if (strcmp_163658(temp_s0, arg3) == 0) {
        func_00163EB8_163658(&D_002C1690_163658, M2C_FIELD(arg3, s32* , 0x18));
        if (M2C_FIELD(arg3, s32* , 0x18) == 0) {
            func_00164B60_163658(&D_002C1690_163658, M2C_FIELD(arg3, s32* , 0x1C), arg3 + 0x20, arg3 + 0x40);
        }
        if (M2C_FIELD(arg3, s8* , 0x144) != 0) {
            M2C_FIELD(&D_002C1690_163658, s32* , 0x51B14) = 1;
        }
    }
}
//@@ func_00163708 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163EB8_163708() __asm__("func_00163EB8");
M2C_UNK func_00266D78_163708() __asm__("func_00266D78");
extern M2C_UNK D_002C1690_163708 __asm__("D_002C1690");
extern M2C_UNK D_00313D6C_163708 __asm__("D_00313D6C");

void func_00163708(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    func_00163EB8_163708(&D_002C1690_163708, M2C_FIELD(arg3, s32* , 0x18));
    if (M2C_FIELD(arg3, s32* , 0x18) == 0) {
        M2C_FIELD(&D_002C1690_163708, s32* , 0x52438) = (s32) M2C_FIELD(arg3, s32* , 0x1C);
    }
    func_00266D78_163708(&D_00313D6C_163708);
    M2C_FIELD(&D_002C1690_163708, s32* , 0) = 1;
}
//@@ func_00163778 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163EB8_163778() __asm__("func_00163EB8");
M2C_UNK printf_163778() __asm__("printf");
s32 strcmp_163778() __asm__("strcmp");
extern M2C_UNK D_002C1690_163778 __asm__("D_002C1690");

void func_00163778(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    void* temp_s2;

    printf_163778("FindWorldByName response\n");
    printf_163778("MessageID %s\n", arg3);
    printf_163778("StatusCode %d\n", M2C_FIELD(arg3, void** , 0x18));
    if (M2C_FIELD(arg3, void** , 0x18) != (void* )1) {
        temp_s2 = arg3 + 0x48;
        if ((M2C_FIELD(arg3, s32* , 0x40) == 0) && (strcmp_163778(&D_002C1690_163778 + 0x1D, temp_s2) == 0)) {
            printf_163778("Game World found with id %d\n", M2C_FIELD(arg3, void** , 0x44));
            M2C_FIELD(&D_002C1690_163778, void** , 0x52438) = (void* ) M2C_FIELD(arg3, void** , 0x44);
            func_00163EB8_163778(&D_002C1690_163778, M2C_FIELD(arg3, void** , 0x18));
        }
        printf_163778("ApplicationID %d\n", M2C_FIELD(arg3, void** , 0x1C));
        printf_163778("ApplicationName %s\n", arg3 + 0x20);
        printf_163778("MediusWorldID %d\n", M2C_FIELD(arg3, void** , 0x44));
        printf_163778("World Name %s\n", temp_s2);
        printf_163778("WorldStatus %d\n", M2C_FIELD(arg3, void** , 0x88));
        printf_163778("EndOfList %c\n", (void* ) M2C_FIELD(arg3, s8* , 0x8C));
    } else {
        printf_163778("World not found\n");
    }
    if (M2C_FIELD(arg3, s8* , 0x8C) != 0) {
        M2C_FIELD(&D_002C1690_163778, s32* , 0) = 1;
    }
}
//@@ func_001639F8 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163EB8_1639F8() __asm__("func_00163EB8");
extern M2C_UNK D_002C1690_1639F8 __asm__("D_002C1690");

void func_001639F8(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    func_00163EB8_1639F8(&D_002C1690_1639F8, M2C_FIELD(arg3, s32* , 0x18));
    M2C_FIELD(&D_002C1690_1639F8, s32* , 0x51AEC) = (s32) M2C_FIELD(arg3, s32* , 0x24);
    M2C_FIELD(&D_002C1690_1639F8, s32* , 0) = 1;
}
//@@ func_00163A58 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163EB8_163A58() __asm__("func_00163EB8");
M2C_UNK func_00164E60_163A58() __asm__("func_00164E60");
extern M2C_UNK D_002C1690_163A58 __asm__("D_002C1690");

void func_00163A58(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    func_00163EB8_163A58(&D_002C1690_163A58, M2C_FIELD(arg3, s32* , 0x18));
    func_00164E60_163A58(&D_002C1690_163A58, M2C_FIELD(&D_002C1690_163A58, s32* , 0x52438), M2C_FIELD(arg3, s32* , 0x30), arg3 + 0x134, M2C_FIELD(arg3, s32* , 0x178), M2C_FIELD(arg3, s32* , 0x17C), M2C_FIELD(arg3, s32* , 0x180), M2C_FIELD(arg3, s32* , 0x184));
    M2C_FIELD(&D_002C1690_163A58, s32* , 0) = 1;
}
//@@ func_00163B00 m2c0
#include "m2c_macros.h"
M2C_UNK func_00162FA0_163B00() __asm__("func_00162FA0");
M2C_UNK func_00163EB8_163B00() __asm__("func_00163EB8");
M2C_UNK func_00164E60_163B00() __asm__("func_00164E60");
M2C_UNK func_0025B938_163B00() __asm__("func_0025B938");
M2C_UNK func_002666A8_163B00() __asm__("func_002666A8");
M2C_UNK printf_163B00() __asm__("printf");
M2C_UNK strcpy_163B00() __asm__("strcpy");
extern M2C_UNK D_002C1690_163B00 __asm__("D_002C1690");
static M2C_UNK D_004E5BD8;                          /* unable to generate initializer: unknown type; const */

void func_00163B00(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    M2C_UNK sp30;
    M2C_UNK sp130;
    s32 sp144;
    s32 sp148;
    M2C_UNK sp14C;
    M2C_UNK sp18C;
    s32 sp28C;
    s32 sp290;
    M2C_UNK* sp294;
    s32 sp298;
    s32 sp29C;
    s32 sp2A0;
    s32 sp2A4;
    s32 sp2A8;
    s32 sp2AC;
    M2C_UNK* temp_a1_2;
    M2C_UNK* temp_s3;
    M2C_UNK* temp_s4;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_t6;

    temp_a1 = M2C_FIELD(arg3, s32* , 0x18);
    if (temp_a1 != 0) {
        func_00163EB8_163B00(&D_002C1690_163B00, temp_a1);
        M2C_FIELD(&D_002C1690_163B00, s32* , 0) = 1;
        printf_163B00(&D_004E5BD8);
        printf_163B00("In GetAndSendWorldReportHandler()\n gameLevel %d\n skillLevel %d\n playerCount %d\n gameName %s\n mode %d\n worldStatus %d\n gameStats %s\n", M2C_FIELD(arg3, M2C_UNK** , 0x28), M2C_FIELD(arg3, s32* , 0x2C), M2C_FIELD(arg3, s32* , 0x30));
        return;
    }
    temp_s3 = arg3 + 0x34;
    temp_s4 = arg3 + 0x134;
    func_00163EB8_163B00(&D_002C1690_163B00, 0);
    func_002666A8_163B00(&sp30);
    printf_163B00("replacing IP addy %s\n", &sp30);
    func_00162FA0_163B00(&sp30, temp_s3);
    printf_163B00("new stats %s\n", temp_s3);
    temp_t6 = M2C_FIELD(arg3, s32* , 0x17C);
    func_00164E60_163B00(&D_002C1690_163B00, M2C_FIELD(&D_002C1690_163B00, s32* , 0x52438), M2C_FIELD(arg3, s32* , 0x30), temp_s4, M2C_FIELD(arg3, s32* , 0x178), temp_t6, temp_t6, M2C_FIELD(arg3, s32* , 0x184));
    strcpy_163B00(&sp130, &D_002C1690_163B00 + 0xC);
    sp144 = M2C_FIELD(&D_002C1690_163B00, s32* , 0x52438);
    sp148 = M2C_FIELD(arg3, s32* , 0x30);
    strcpy_163B00(&sp14C, temp_s4);
    strcpy_163B00(&sp18C, temp_s3);
    temp_a1_2 = M2C_FIELD(arg3, M2C_UNK** , 0x28);
    temp_a2 = M2C_FIELD(arg3, s32* , 0x2C);
    temp_a3 = M2C_FIELD(arg3, s32* , 0x174);
    sp290 = M2C_FIELD(arg3, s32* , 0x24);
    sp28C = M2C_FIELD(arg3, s32* , 0x20);
    sp294 = temp_a1_2;
    sp298 = temp_a2;
    sp29C = temp_a3;
    sp2A0 = M2C_FIELD(arg3, s32* , 0x178);
    sp2A4 = M2C_FIELD(arg3, s32* , 0x17C);
    sp2A8 = M2C_FIELD(arg3, s32* , 0x180);
    sp2AC = M2C_FIELD(arg3, s32* , 0x184);
    func_0025B938_163B00(&sp130, temp_a1_2, temp_a2, temp_a3);
    M2C_FIELD(&D_002C1690_163B00, s32* , 0) = 1;
}
//@@ func_00163CE0 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163EB8_163CE0() __asm__("func_00163EB8");
M2C_UNK func_00164F68_163CE0() __asm__("func_00164F68");
extern M2C_UNK D_002C1690_163CE0 __asm__("D_002C1690");

void func_00163CE0(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    func_00163EB8_163CE0(&D_002C1690_163CE0, M2C_FIELD(arg3, s32* , 0x18));
    func_00164F68_163CE0(&D_002C1690_163CE0, M2C_FIELD(&D_002C1690_163CE0, s32* , 0x52438), arg3 + 0x48);
    M2C_FIELD(&D_002C1690_163CE0, s32* , 0) = 1;
}
//@@ func_00163D48 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163EB8_163D48() __asm__("func_00163EB8");
M2C_UNK func_0025B8AC_163D48() __asm__("func_0025B8AC");
M2C_UNK strcpy_163D48() __asm__("strcpy");
extern M2C_UNK D_002C1690_163D48 __asm__("D_002C1690");

void func_00163D48(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    u8 sp[0x120];
    M2C_UNK sp18;

    func_00163EB8_163D48(&D_002C1690_163D48, M2C_FIELD(arg3, s32* , 0x18));
    strcpy_163D48(sp, &D_002C1690_163D48 + 0xC);
    strcpy_163D48(&sp18, arg3 + 0x48, M2C_FIELD(&D_002C1690_163D48, s32* , 0x52438));
    func_0025B8AC_163D48(sp);
    M2C_FIELD(&D_002C1690_163D48, s32* , 0) = 1;
}
//@@ func_00163D48 m2c1
#include "m2c_macros.h"
M2C_UNK func_00163EB8_163D48() __asm__("func_00163EB8");
M2C_UNK func_0025B8AC_163D48() __asm__("func_0025B8AC");
M2C_UNK strcpy_163D48() __asm__("strcpy");
extern M2C_UNK D_002C1690_163D48 __asm__("D_002C1690");

void func_00163D48(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    u8 sp[0x110];
    M2C_UNK sp18;

    func_00163EB8_163D48(&D_002C1690_163D48, M2C_FIELD(arg3, s32* , 0x18));
    strcpy_163D48(sp, &D_002C1690_163D48 + 0xC);
    strcpy_163D48(&sp18, arg3 + 0x48, M2C_FIELD(&D_002C1690_163D48, s32* , 0x52438));
    func_0025B8AC_163D48(sp);
    M2C_FIELD(&D_002C1690_163D48, s32* , 0) = 1;
}
//@@ func_00163D48 m2c2
#include "m2c_macros.h"
M2C_UNK func_00163EB8_163D48() __asm__("func_00163EB8");
M2C_UNK func_0025B8AC_163D48() __asm__("func_0025B8AC");
M2C_UNK strcpy_163D48() __asm__("strcpy");
extern M2C_UNK D_002C1690_163D48 __asm__("D_002C1690");

void func_00163D48(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    u8 sp[0x100];
    M2C_UNK sp18;

    func_00163EB8_163D48(&D_002C1690_163D48, M2C_FIELD(arg3, s32* , 0x18));
    strcpy_163D48(sp, &D_002C1690_163D48 + 0xC);
    strcpy_163D48(&sp18, arg3 + 0x48, M2C_FIELD(&D_002C1690_163D48, s32* , 0x52438));
    func_0025B8AC_163D48(sp);
    M2C_FIELD(&D_002C1690_163D48, s32* , 0) = 1;
}
//@@ func_00163D48 m2c3
#include "m2c_macros.h"
M2C_UNK func_00163EB8_163D48() __asm__("func_00163EB8");
M2C_UNK func_0025B8AC_163D48() __asm__("func_0025B8AC");
M2C_UNK strcpy_163D48() __asm__("strcpy");
extern M2C_UNK D_002C1690_163D48 __asm__("D_002C1690");

void func_00163D48(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    u8 sp[0xF0];
    M2C_UNK sp18;

    func_00163EB8_163D48(&D_002C1690_163D48, M2C_FIELD(arg3, s32* , 0x18));
    strcpy_163D48(sp, &D_002C1690_163D48 + 0xC);
    strcpy_163D48(&sp18, arg3 + 0x48, M2C_FIELD(&D_002C1690_163D48, s32* , 0x52438));
    func_0025B8AC_163D48(sp);
    M2C_FIELD(&D_002C1690_163D48, s32* , 0) = 1;
}
//@@ func_00163D48 m2c4
#include "m2c_macros.h"
M2C_UNK func_00163EB8_163D48() __asm__("func_00163EB8");
M2C_UNK func_0025B8AC_163D48() __asm__("func_0025B8AC");
M2C_UNK strcpy_163D48() __asm__("strcpy");
extern M2C_UNK D_002C1690_163D48 __asm__("D_002C1690");

void func_00163D48(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    u8 sp[0xE0];
    M2C_UNK sp18;

    func_00163EB8_163D48(&D_002C1690_163D48, M2C_FIELD(arg3, s32* , 0x18));
    strcpy_163D48(sp, &D_002C1690_163D48 + 0xC);
    strcpy_163D48(&sp18, arg3 + 0x48, M2C_FIELD(&D_002C1690_163D48, s32* , 0x52438));
    func_0025B8AC_163D48(sp);
    M2C_FIELD(&D_002C1690_163D48, s32* , 0) = 1;
}
//@@ func_00163D48 m2c5
#include "m2c_macros.h"
M2C_UNK func_00163EB8_163D48() __asm__("func_00163EB8");
M2C_UNK func_0025B8AC_163D48() __asm__("func_0025B8AC");
M2C_UNK strcpy_163D48() __asm__("strcpy");
extern M2C_UNK D_002C1690_163D48 __asm__("D_002C1690");

void func_00163D48(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    u8 sp[0xD0];
    M2C_UNK sp18;

    func_00163EB8_163D48(&D_002C1690_163D48, M2C_FIELD(arg3, s32* , 0x18));
    strcpy_163D48(sp, &D_002C1690_163D48 + 0xC);
    strcpy_163D48(&sp18, arg3 + 0x48, M2C_FIELD(&D_002C1690_163D48, s32* , 0x52438));
    func_0025B8AC_163D48(sp);
    M2C_FIELD(&D_002C1690_163D48, s32* , 0) = 1;
}
//@@ func_00163DC8 m2c0
#include "m2c_macros.h"
extern s32 D_004F9C70_163DC8 __asm__("D_004F9C70");
extern s32 D_004F9C74_163DC8 __asm__("D_004F9C74");
extern s32 D_004F9C78_163DC8 __asm__("D_004F9C78");
extern s32 D_004F9C7C_163DC8 __asm__("D_004F9C7C");
extern s32 D_004F9C80_163DC8 __asm__("D_004F9C80");

void func_00163DC8(void* arg0) {
    M2C_FIELD(arg0, s32* , 0x41AB4) = 0;
    M2C_FIELD(arg0, s32* , 0x41AB0) = 0;
    D_004F9C70_163DC8 = 0;
    D_004F9C74_163DC8 = 0;
    D_004F9C78_163DC8 = 0;
    D_004F9C7C_163DC8 = 0;
    D_004F9C80_163DC8 = 0;
}
//@@ func_00163E00 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163EB8_163E00() __asm__("func_00163EB8");
M2C_UNK func_0025A020_163E00() __asm__("func_0025A020");
M2C_UNK func_00266D78_163E00() __asm__("func_00266D78");

void func_00163E00(s32* arg0, s32 arg1) {
    u8 sp[0x10];
    s32 sp4;
    s32 sp8;

    func_00266D78_163E00(sp);
    sp8 = subroutine_arg0;
    if (*arg0 == 0) {
        do {
            func_00266D78_163E00(&sp4);
            if ((sp4 - sp8) >= 0x33) {
                func_0025A020_163E00();
                func_00266D78_163E00(&sp8);
            }
            if (arg1 < (sp4 - subroutine_arg0)) {
                *arg0 = 1;
                func_00163EB8_163E00(arg0, -0x32);
            }
        } while (*arg0 == 0);
    }
    *arg0 = 0;
}
//@@ func_00163E00 m2c1
#include "m2c_macros.h"
M2C_UNK func_00163EB8_163E00() __asm__("func_00163EB8");
M2C_UNK func_0025A020_163E00() __asm__("func_0025A020");
M2C_UNK func_00266D78_163E00() __asm__("func_00266D78");

void func_00163E00(s32* arg0, s32 arg1) {
    u8 sp[0x8];
    s32 sp4;
    s32 sp8;

    func_00266D78_163E00(sp);
    sp8 = subroutine_arg0;
    if (*arg0 == 0) {
        do {
            func_00266D78_163E00(&sp4);
            if ((sp4 - sp8) >= 0x33) {
                func_0025A020_163E00();
                func_00266D78_163E00(&sp8);
            }
            if (arg1 < (sp4 - subroutine_arg0)) {
                *arg0 = 1;
                func_00163EB8_163E00(arg0, -0x32);
            }
        } while (*arg0 == 0);
    }
    *arg0 = 0;
}
//@@ func_00163E00 m2c2
#include "m2c_macros.h"
M2C_UNK func_00163EB8_163E00() __asm__("func_00163EB8");
M2C_UNK func_0025A020_163E00() __asm__("func_0025A020");
M2C_UNK func_00266D78_163E00() __asm__("func_00266D78");

void func_00163E00(s32* arg0, s32 arg1) {
    u8 sp[0x4];
    s32 sp4;
    s32 sp8;

    func_00266D78_163E00(sp);
    sp8 = subroutine_arg0;
    if (*arg0 == 0) {
        do {
            func_00266D78_163E00(&sp4);
            if ((sp4 - sp8) >= 0x33) {
                func_0025A020_163E00();
                func_00266D78_163E00(&sp8);
            }
            if (arg1 < (sp4 - subroutine_arg0)) {
                *arg0 = 1;
                func_00163EB8_163E00(arg0, -0x32);
            }
        } while (*arg0 == 0);
    }
    *arg0 = 0;
}
//@@ func_00163EB8 m2c0
#include "m2c_macros.h"
void func_00163EB8(void* arg0, s32 arg1) {
    M2C_FIELD(arg0, s32* , 4) = arg1;
}
//@@ func_00163EC0 m2c0
#include "m2c_macros.h"
M2C_UNK func_001649D8_163EC0() __asm__("func_001649D8");
M2C_UNK func_00266D78_163EC0() __asm__("func_00266D78");
M2C_UNK printf_163EC0() __asm__("printf");
extern M2C_UNK D_002C1690_163EC0 __asm__("D_002C1690");
extern M2C_UNK D_00301690_163EC0 __asm__("D_00301690");
extern M2C_UNK D_003156C0_163EC0 __asm__("D_003156C0");
extern s32 D_004F9C58_163EC0 __asm__("D_004F9C58");
extern s32 D_004F9C5C_163EC0 __asm__("D_004F9C5C");
extern s32 D_004F9C60_163EC0 __asm__("D_004F9C60");
extern s32 D_004F9C64_163EC0 __asm__("D_004F9C64");
extern s32 D_004F9C68_163EC0 __asm__("D_004F9C68");
extern s32 D_004F9C6C_163EC0 __asm__("D_004F9C6C");
extern s32 D_004F9C70_163EC0 __asm__("D_004F9C70");
extern s32 D_004F9C74_163EC0 __asm__("D_004F9C74");
extern s32 D_004F9C78_163EC0 __asm__("D_004F9C78");
extern s32 D_004F9C7C_163EC0 __asm__("D_004F9C7C");
extern s32 D_004F9C80_163EC0 __asm__("D_004F9C80");
extern M2C_UNK func_001648B0_163EC0 __asm__("func_001648B0");
extern M2C_UNK func_00164938_163EC0 __asm__("func_00164938");

s32 func_00163EC0(void* arg0, s32 arg1, s32 arg2) {
    s32 sp20;
    s32 temp_fp;
    s32 temp_v0;
    s32 var_s2;
    s32 var_v0;
    void* temp_s0;
    void* temp_s1;

    func_00266D78_163EC0(&sp20);
    temp_fp = sp20 - M2C_FIELD(arg0, s32* , 0x406A0);
    var_v0 = 0;
    if (arg1 < temp_fp) {
        if (arg2 != 0) {
            var_s2 = 0;
            if (M2C_FIELD(&D_002C1690_163EC0, s32* , 0x406A8) > 0) {
                do {
                    temp_s0 = (var_s2 << 7) + 0x406AC + &D_002C1690_163EC0;
                    temp_v0 = M2C_FIELD(temp_s0, s32* , 0x7C);
                    temp_s1 = temp_s0 + 4;
                    if (temp_v0 == 0x2710) {
                        printf_163EC0("Throwing away No-Info Game %s\n", temp_s1);
                        M2C_FIELD(temp_s0, s32* , 0x7C) = 0x270E;
                        D_004F9C6C_163EC0 += 1;
                        func_001649D8_163EC0(&D_002C1690_163EC0, M2C_FIELD(temp_s0, s32* , 0), temp_s1, M2C_FIELD(temp_s0, s32* , 0x44), 0x270F, &func_001648B0_163EC0);
                    } else if (temp_v0 == 0x270F) {
                        M2C_FIELD(temp_s0, s32* , 0x7C) = 0x270E;
                        D_004F9C68_163EC0 += 1;
                        if (M2C_FIELD(&D_003156C0_163EC0, s32* , 0x4264) != 0) {
                            func_001649D8_163EC0(&D_002C1690_163EC0, M2C_FIELD(temp_s0, s32* , 0), temp_s0 + 4, M2C_FIELD(temp_s0, s32* , 0x44), 0x270E, &func_00164938_163EC0);
                        } else {
                            func_001649D8_163EC0(&D_002C1690_163EC0, M2C_FIELD(temp_s0, s32* , 0), temp_s0 + 4, M2C_FIELD(temp_s0, s32* , 0x44), 0x270E, &func_001648B0_163EC0);
                        }
                    }
                    var_s2 += 1;
                } while (var_s2 < M2C_FIELD(&D_00301690_163EC0, s32* , 0x6A8));
            }
        }
        if ((D_004F9C58_163EC0 == 0) || (var_v0 = 0, ((temp_fp < 0x7531) == 0))) {
            var_v0 = 1;
            D_004F9C70_163EC0 += D_004F9C5C_163EC0;
            D_004F9C74_163EC0 += D_004F9C60_163EC0;
            D_004F9C78_163EC0 += D_004F9C64_163EC0;
            D_004F9C7C_163EC0 += D_004F9C68_163EC0;
            D_004F9C80_163EC0 += D_004F9C6C_163EC0;
            M2C_FIELD(arg0, s32* , 0x406A4) = 1;
            M2C_FIELD(arg0, s32* , 0x406A8) = 0;
        }
    }
    return var_v0;
}
//@@ func_001641B8 m2c0
#include "m2c_macros.h"
M2C_UNK printf_1641B8() __asm__("printf");
M2C_UNK strcpy_1641B8() __asm__("strcpy");
s32 strlen_1641B8() __asm__("strlen");

void func_001641B8(void* arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = strlen_1641B8(arg0 + 0x64);
    if ((u32) (temp_s0 + strlen_1641B8(arg1)) >= 0x1E00U) {
        printf_1641B8("Policy array full. Further policy information not stored\n");
        return;
    }
    strcpy_1641B8(M2C_FIELD(arg0, s32* , 0x1E64), arg1);
    M2C_FIELD(arg0, s32* , 0x1E64) = (s32) (M2C_FIELD(arg0, s32* , 0x1E64) + strlen_1641B8(arg1));
}
//@@ func_00164240 m2c0
#include "m2c_macros.h"
M2C_UNK strcpy_164240() __asm__("strcpy");

s32 func_00164240(void* arg0) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32* , 0x1E68);
    if (temp_v1 < 0x100) {
        M2C_FIELD(arg0, s32* , 0x1E68) = (s32) (temp_v1 + 1);
        strcpy_164240(arg0 + ((temp_v1 * 0x3E8) + 0x1E6C), arg0);
        return 1;
    }
    return 0;
}
//@@ func_00164750 m2c0
#include "m2c_macros.h"
M2C_UNK strcpy_164750() __asm__("strcpy");

s32 func_00164750(void* arg0, s32 arg1) {
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_v0;
    s32 var_s0;
    void* temp_a0;
    void* temp_a1;
    void* temp_a1_2;
    void* var_s1;
    void* var_s2;
    void* var_s3;
    void* var_s4;
    void* var_s5;

    var_s0 = arg1;
    if (var_s0 < (M2C_FIELD(arg0, s32* , 0x406A8) + 1)) {
        temp_v0 = var_s0 << 7;
        var_s1 = temp_v0 + 0x40724 + arg0;
        var_s5 = temp_v0 + 0x40780 + arg0;
        var_s4 = temp_v0 + 0x40700 + arg0;
        var_s3 = temp_v0 + 0x40730 + arg0;
        var_s2 = temp_v0 + 0x406B0 + arg0;
        do {
            temp_a1 = var_s3;
            var_s0 += 1;
            M2C_FIELD(var_s1, s32* , -0x78) = (s32) M2C_FIELD(var_s1, s32* , 8);
            var_s3 += 0x80;
            strcpy_164750(var_s2, temp_a1);
            var_s2 += 0x80;
            temp_a0 = var_s4;
            temp_a3 = M2C_FIELD(var_s1, s32* , 0x4C);
            temp_a1_2 = var_s5;
            temp_a2 = M2C_FIELD(var_s1, s32* , 0x50);
            var_s5 += 0x80;
            var_s4 += 0x80;
            M2C_FIELD(var_s1, s32* , -0x2C) = (s32) M2C_FIELD(var_s1, s32* , 0x54);
            M2C_FIELD(var_s1, s32* , -0x34) = temp_a3;
            M2C_FIELD(var_s1, s32* , -0x30) = temp_a2;
            M2C_FIELD(var_s1, s32* , -0x28) = (s32) M2C_FIELD(var_s1, s32* , 0x58);
            strcpy_164750(temp_a0, temp_a1_2, temp_a2, temp_a3);
            M2C_FIELD(var_s1, s32* , 0) = (s32) M2C_FIELD(var_s1, s32* , 0x80);
            M2C_FIELD(var_s1, s32* , -4) = (s32) M2C_FIELD(var_s1, s32* , 0x7C);
            var_s1 += 0x80;
        } while (var_s0 < (M2C_FIELD(arg0, s32* , 0x406A8) + 1));
    }
    M2C_FIELD(arg0, s32* , 0x406A8) = (s32) (M2C_FIELD(arg0, s32* , 0x406A8) - 1);
    return 1;
}
//@@ func_00164B60 m2c0
#include "m2c_macros.h"
M2C_UNK strcpy_164B60() __asm__("strcpy");

s32 func_00164B60(void* arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3) {
    s32 temp_a2;
    s32 temp_v1;
    s32 temp_v1_2;

    temp_v1 = M2C_FIELD(arg0, s32* , 0x51B10);
    if (temp_v1 < 8) {
        temp_a2 = temp_v1 * 0x124;
        M2C_FIELD((temp_a2 + (arg0 + 0x50000)), s32* , 0x1B18) = arg1;
        strcpy_164B60(arg0 + ((M2C_FIELD(arg0, s32* , 0x51B10) * 0x124) + 0x51B18) + 4, arg2, temp_a2);
        temp_v1_2 = M2C_FIELD(arg0, s32* , 0x51B10);
        M2C_FIELD(arg0, s32* , 0x51B10) = (s32) (temp_v1_2 + 1);
        strcpy_164B60(arg0 + ((temp_v1_2 * 0x124) + 0x51B18) + 0x24, arg3);
        return 1;
    }
    return 0;
}
//@@ func_00164F68 m2c0
#include "m2c_macros.h"
M2C_UNK strcpy_164F68() __asm__("strcpy");

void func_00164F68(void* arg0, s32 arg1, s32 arg2) {
    strcpy_164F68(arg0 + 0x525C4, arg0 + 0xC);
    M2C_FIELD(arg0, s32* , 0x525D8) = arg1;
    strcpy_164F68(arg0 + 0x525DC, arg2);
}
//@@ func_00164FD8 m2c0
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
//@@ func_001653D8 m2c0
#include "m2c_macros.h"
M2C_UNK func_00259A58_1653D8() __asm__("func_00259A58");
extern M2C_UNK func_001625D8_1653D8 __asm__("func_001625D8");
extern M2C_UNK func_001625E0_1653D8 __asm__("func_001625E0");
extern M2C_UNK func_001625E8_1653D8 __asm__("func_001625E8");
extern M2C_UNK func_001625F0_1653D8 __asm__("func_001625F0");

void func_001653D8(void) {
    u8 sp[0x30];
    M2C_UNK sp20;

    func_00259A58_1653D8(sp, &sp20, &func_001625F0_1653D8, 0x7530, 0x7530);
}
//@@ func_001653D8 m2c1
#include "m2c_macros.h"
M2C_UNK func_00259A58_1653D8() __asm__("func_00259A58");
extern M2C_UNK func_001625D8_1653D8 __asm__("func_001625D8");
extern M2C_UNK func_001625E0_1653D8 __asm__("func_001625E0");
extern M2C_UNK func_001625E8_1653D8 __asm__("func_001625E8");
extern M2C_UNK func_001625F0_1653D8 __asm__("func_001625F0");

void func_001653D8(void) {
    u8 sp[0x20];
    M2C_UNK sp20;

    func_00259A58_1653D8(sp, &sp20, &func_001625F0_1653D8, 0x7530, 0x7530);
}
//@@ func_001653D8 m2c2
#include "m2c_macros.h"
M2C_UNK func_00259A58_1653D8() __asm__("func_00259A58");
extern M2C_UNK func_001625D8_1653D8 __asm__("func_001625D8");
extern M2C_UNK func_001625E0_1653D8 __asm__("func_001625E0");
extern M2C_UNK func_001625E8_1653D8 __asm__("func_001625E8");
extern M2C_UNK func_001625F0_1653D8 __asm__("func_001625F0");

void func_001653D8(void) {
    u8 sp[0x10];
    M2C_UNK sp20;

    func_00259A58_1653D8(sp, &sp20, &func_001625F0_1653D8, 0x7530, 0x7530);
}
//@@ func_001653D8 m2c3
#include "m2c_macros.h"
M2C_UNK func_00259A58_1653D8() __asm__("func_00259A58");
extern M2C_UNK func_001625D8_1653D8 __asm__("func_001625D8");
extern M2C_UNK func_001625E0_1653D8 __asm__("func_001625E0");
extern M2C_UNK func_001625E8_1653D8 __asm__("func_001625E8");
extern M2C_UNK func_001625F0_1653D8 __asm__("func_001625F0");

void func_001653D8(void) {
    u8 sp[0x8];
    M2C_UNK sp20;

    func_00259A58_1653D8(sp, &sp20, &func_001625F0_1653D8, 0x7530, 0x7530);
}
//@@ func_001653D8 m2c4
#include "m2c_macros.h"
M2C_UNK func_00259A58_1653D8() __asm__("func_00259A58");
extern M2C_UNK func_001625D8_1653D8 __asm__("func_001625D8");
extern M2C_UNK func_001625E0_1653D8 __asm__("func_001625E0");
extern M2C_UNK func_001625E8_1653D8 __asm__("func_001625E8");
extern M2C_UNK func_001625F0_1653D8 __asm__("func_001625F0");

void func_001653D8(void) {
    u8 sp[0x4];
    M2C_UNK sp20;

    func_00259A58_1653D8(sp, &sp20, &func_001625F0_1653D8, 0x7530, 0x7530);
}
//@@ func_00165430 m2c0
#include "m2c_macros.h"
M2C_UNK func_00259C6C_165430() __asm__("func_00259C6C");
M2C_UNK printf_165430() __asm__("printf");
M2C_UNK strcpy_165430() __asm__("strcpy");
extern u16 D_004F9C40_165430 __asm__("D_004F9C40");
extern M2C_UNK func_00162670_165430 __asm__("func_00162670");

void func_00165430(s32 arg0) {
    u8 sp[0x30];
    M2C_UNK sp15;

    strcpy_165430(&sp15, arg0 + 0xC);
    printf_165430("Trying to request the server version\n");
    printf_165430("Session Key = %s\n", &sp15);
    func_00259C6C_165430(sp, &func_00162670_165430);
}
//@@ func_00165430 m2c1
#include "m2c_macros.h"
M2C_UNK func_00259C6C_165430() __asm__("func_00259C6C");
M2C_UNK printf_165430() __asm__("printf");
M2C_UNK strcpy_165430() __asm__("strcpy");
extern u16 D_004F9C40_165430 __asm__("D_004F9C40");
extern M2C_UNK func_00162670_165430 __asm__("func_00162670");

void func_00165430(s32 arg0) {
    u8 sp[0x20];
    M2C_UNK sp15;

    strcpy_165430(&sp15, arg0 + 0xC);
    printf_165430("Trying to request the server version\n");
    printf_165430("Session Key = %s\n", &sp15);
    func_00259C6C_165430(sp, &func_00162670_165430);
}
//@@ func_00165430 m2c2
#include "m2c_macros.h"
M2C_UNK func_00259C6C_165430() __asm__("func_00259C6C");
M2C_UNK printf_165430() __asm__("printf");
M2C_UNK strcpy_165430() __asm__("strcpy");
extern u16 D_004F9C40_165430 __asm__("D_004F9C40");
extern M2C_UNK func_00162670_165430 __asm__("func_00162670");

void func_00165430(s32 arg0) {
    u8 sp[0x10];
    M2C_UNK sp15;

    strcpy_165430(&sp15, arg0 + 0xC);
    printf_165430("Trying to request the server version\n");
    printf_165430("Session Key = %s\n", &sp15);
    func_00259C6C_165430(sp, &func_00162670_165430);
}
//@@ func_00165430 m2c3
#include "m2c_macros.h"
M2C_UNK func_00259C6C_165430() __asm__("func_00259C6C");
M2C_UNK printf_165430() __asm__("printf");
M2C_UNK strcpy_165430() __asm__("strcpy");
extern u16 D_004F9C40_165430 __asm__("D_004F9C40");
extern M2C_UNK func_00162670_165430 __asm__("func_00162670");

void func_00165430(s32 arg0) {
    u8 sp[0x8];
    M2C_UNK sp15;

    strcpy_165430(&sp15, arg0 + 0xC);
    printf_165430("Trying to request the server version\n");
    printf_165430("Session Key = %s\n", &sp15);
    func_00259C6C_165430(sp, &func_00162670_165430);
}
//@@ func_00165430 m2c4
#include "m2c_macros.h"
M2C_UNK func_00259C6C_165430() __asm__("func_00259C6C");
M2C_UNK printf_165430() __asm__("printf");
M2C_UNK strcpy_165430() __asm__("strcpy");
extern u16 D_004F9C40_165430 __asm__("D_004F9C40");
extern M2C_UNK func_00162670_165430 __asm__("func_00162670");

void func_00165430(s32 arg0) {
    u8 sp[0x4];
    M2C_UNK sp15;

    strcpy_165430(&sp15, arg0 + 0xC);
    printf_165430("Trying to request the server version\n");
    printf_165430("Session Key = %s\n", &sp15);
    func_00259C6C_165430(sp, &func_00162670_165430);
}
//@@ func_001658E8 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163E00_1658E8() __asm__("func_00163E00");
M2C_UNK func_00163EB8_1658E8() __asm__("func_00163EB8");
s32 func_0025A208_1658E8() __asm__("func_0025A208");
M2C_UNK func_0025BD88_1658E8() __asm__("func_0025BD88");
extern s32 D_002C1694_1658E8 __asm__("D_002C1694");
extern s32 D_00319924_1658E8 __asm__("D_00319924");
extern M2C_UNK func_001626F8_1658E8 __asm__("func_001626F8");

s32 func_001658E8(s32* arg0) {
    u8 sp[0x20];
    s32 temp_v0;

    func_0025BD88_1658E8(arg0 + 0xC, 0x35, sp);
    if (D_00319924_1658E8 != 0) {

    }
    *arg0 = 0;
    temp_v0 = func_0025A208_1658E8(sp, &func_001626F8_1658E8);
    if (temp_v0 != 0) {
        func_00163EB8_1658E8(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_1658E8(arg0, 0xC350);
    return (D_002C1694_1658E8 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_001658E8 m2c1
#include "m2c_macros.h"
M2C_UNK func_00163E00_1658E8() __asm__("func_00163E00");
M2C_UNK func_00163EB8_1658E8() __asm__("func_00163EB8");
s32 func_0025A208_1658E8() __asm__("func_0025A208");
M2C_UNK func_0025BD88_1658E8() __asm__("func_0025BD88");
extern s32 D_002C1694_1658E8 __asm__("D_002C1694");
extern s32 D_00319924_1658E8 __asm__("D_00319924");
extern M2C_UNK func_001626F8_1658E8 __asm__("func_001626F8");

s32 func_001658E8(s32* arg0) {
    u8 sp[0x10];
    s32 temp_v0;

    func_0025BD88_1658E8(arg0 + 0xC, 0x35, sp);
    if (D_00319924_1658E8 != 0) {

    }
    *arg0 = 0;
    temp_v0 = func_0025A208_1658E8(sp, &func_001626F8_1658E8);
    if (temp_v0 != 0) {
        func_00163EB8_1658E8(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_1658E8(arg0, 0xC350);
    return (D_002C1694_1658E8 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_001658E8 m2c2
#include "m2c_macros.h"
M2C_UNK func_00163E00_1658E8() __asm__("func_00163E00");
M2C_UNK func_00163EB8_1658E8() __asm__("func_00163EB8");
s32 func_0025A208_1658E8() __asm__("func_0025A208");
M2C_UNK func_0025BD88_1658E8() __asm__("func_0025BD88");
extern s32 D_002C1694_1658E8 __asm__("D_002C1694");
extern s32 D_00319924_1658E8 __asm__("D_00319924");
extern M2C_UNK func_001626F8_1658E8 __asm__("func_001626F8");

s32 func_001658E8(s32* arg0) {
    u8 sp[0x8];
    s32 temp_v0;

    func_0025BD88_1658E8(arg0 + 0xC, 0x35, sp);
    if (D_00319924_1658E8 != 0) {

    }
    *arg0 = 0;
    temp_v0 = func_0025A208_1658E8(sp, &func_001626F8_1658E8);
    if (temp_v0 != 0) {
        func_00163EB8_1658E8(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_1658E8(arg0, 0xC350);
    return (D_002C1694_1658E8 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_001658E8 m2c3
#include "m2c_macros.h"
M2C_UNK func_00163E00_1658E8() __asm__("func_00163E00");
M2C_UNK func_00163EB8_1658E8() __asm__("func_00163EB8");
s32 func_0025A208_1658E8() __asm__("func_0025A208");
M2C_UNK func_0025BD88_1658E8() __asm__("func_0025BD88");
extern s32 D_002C1694_1658E8 __asm__("D_002C1694");
extern s32 D_00319924_1658E8 __asm__("D_00319924");
extern M2C_UNK func_001626F8_1658E8 __asm__("func_001626F8");

s32 func_001658E8(s32* arg0) {
    u8 sp[0x4];
    s32 temp_v0;

    func_0025BD88_1658E8(arg0 + 0xC, 0x35, sp);
    if (D_00319924_1658E8 != 0) {

    }
    *arg0 = 0;
    temp_v0 = func_0025A208_1658E8(sp, &func_001626F8_1658E8);
    if (temp_v0 != 0) {
        func_00163EB8_1658E8(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_1658E8(arg0, 0xC350);
    return (D_002C1694_1658E8 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165998 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163E00_165998() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165998() __asm__("func_00163EB8");
s32 func_0025A2A0_165998() __asm__("func_0025A2A0");
M2C_UNK func_0025BD88_165998() __asm__("func_0025BD88");
M2C_UNK strcpy_165998() __asm__("strcpy");
extern s32 D_002C1694_165998 __asm__("D_002C1694");
extern M2C_UNK func_00162778_165998 __asm__("func_00162778");

s32 func_00165998(s32* arg0) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165998(temp_s0, 0x36, sp);
    strcpy_165998(&sp15, temp_s0);
    *arg0 = 0;
    temp_v0 = func_0025A2A0_165998(sp, &func_00162778_165998);
    if (temp_v0 != 0) {
        func_00163EB8_165998(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165998(arg0, 0xC350);
    return (D_002C1694_165998 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165998 m2c1
#include "m2c_macros.h"
M2C_UNK func_00163E00_165998() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165998() __asm__("func_00163EB8");
s32 func_0025A2A0_165998() __asm__("func_0025A2A0");
M2C_UNK func_0025BD88_165998() __asm__("func_0025BD88");
M2C_UNK strcpy_165998() __asm__("strcpy");
extern s32 D_002C1694_165998 __asm__("D_002C1694");
extern M2C_UNK func_00162778_165998 __asm__("func_00162778");

s32 func_00165998(s32* arg0) {
    u8 sp[0x20];
    M2C_UNK sp15;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165998(temp_s0, 0x36, sp);
    strcpy_165998(&sp15, temp_s0);
    *arg0 = 0;
    temp_v0 = func_0025A2A0_165998(sp, &func_00162778_165998);
    if (temp_v0 != 0) {
        func_00163EB8_165998(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165998(arg0, 0xC350);
    return (D_002C1694_165998 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165998 m2c2
#include "m2c_macros.h"
M2C_UNK func_00163E00_165998() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165998() __asm__("func_00163EB8");
s32 func_0025A2A0_165998() __asm__("func_0025A2A0");
M2C_UNK func_0025BD88_165998() __asm__("func_0025BD88");
M2C_UNK strcpy_165998() __asm__("strcpy");
extern s32 D_002C1694_165998 __asm__("D_002C1694");
extern M2C_UNK func_00162778_165998 __asm__("func_00162778");

s32 func_00165998(s32* arg0) {
    u8 sp[0x10];
    M2C_UNK sp15;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165998(temp_s0, 0x36, sp);
    strcpy_165998(&sp15, temp_s0);
    *arg0 = 0;
    temp_v0 = func_0025A2A0_165998(sp, &func_00162778_165998);
    if (temp_v0 != 0) {
        func_00163EB8_165998(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165998(arg0, 0xC350);
    return (D_002C1694_165998 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165998 m2c3
#include "m2c_macros.h"
M2C_UNK func_00163E00_165998() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165998() __asm__("func_00163EB8");
s32 func_0025A2A0_165998() __asm__("func_0025A2A0");
M2C_UNK func_0025BD88_165998() __asm__("func_0025BD88");
M2C_UNK strcpy_165998() __asm__("strcpy");
extern s32 D_002C1694_165998 __asm__("D_002C1694");
extern M2C_UNK func_00162778_165998 __asm__("func_00162778");

s32 func_00165998(s32* arg0) {
    u8 sp[0x8];
    M2C_UNK sp15;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165998(temp_s0, 0x36, sp);
    strcpy_165998(&sp15, temp_s0);
    *arg0 = 0;
    temp_v0 = func_0025A2A0_165998(sp, &func_00162778_165998);
    if (temp_v0 != 0) {
        func_00163EB8_165998(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165998(arg0, 0xC350);
    return (D_002C1694_165998 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165998 m2c4
#include "m2c_macros.h"
M2C_UNK func_00163E00_165998() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165998() __asm__("func_00163EB8");
s32 func_0025A2A0_165998() __asm__("func_0025A2A0");
M2C_UNK func_0025BD88_165998() __asm__("func_0025BD88");
M2C_UNK strcpy_165998() __asm__("strcpy");
extern s32 D_002C1694_165998 __asm__("D_002C1694");
extern M2C_UNK func_00162778_165998 __asm__("func_00162778");

s32 func_00165998(s32* arg0) {
    u8 sp[0x4];
    M2C_UNK sp15;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165998(temp_s0, 0x36, sp);
    strcpy_165998(&sp15, temp_s0);
    *arg0 = 0;
    temp_v0 = func_0025A2A0_165998(sp, &func_00162778_165998);
    if (temp_v0 != 0) {
        func_00163EB8_165998(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165998(arg0, 0xC350);
    return (D_002C1694_165998 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165A38 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163E00_165A38() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165A38() __asm__("func_00163EB8");
s32 func_0025A344_165A38() __asm__("func_0025A344");
M2C_UNK func_0025BD88_165A38() __asm__("func_0025BD88");
M2C_UNK strcpy_165A38() __asm__("strcpy");
extern s32 D_002C1694_165A38 __asm__("D_002C1694");
extern M2C_UNK func_001627B0_165A38 __asm__("func_001627B0");

s32 func_00165A38(s32* arg0, s32 arg1, s32 arg2) {
    u8 sp[0x70];
    M2C_UNK sp15;
    M2C_UNK sp26;
    M2C_UNK sp46;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165A38(temp_s0, 3, sp);
    strcpy_165A38(&sp15, temp_s0);
    strcpy_165A38(&sp26, arg1);
    strcpy_165A38(&sp46, arg2);
    *arg0 = 0;
    temp_v0 = func_0025A344_165A38(sp, &func_001627B0_165A38);
    if (temp_v0 != 0) {
        func_00163EB8_165A38(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165A38(arg0, 0xC350);
    return (D_002C1694_165A38 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165A38 m2c1
#include "m2c_macros.h"
M2C_UNK func_00163E00_165A38() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165A38() __asm__("func_00163EB8");
s32 func_0025A344_165A38() __asm__("func_0025A344");
M2C_UNK func_0025BD88_165A38() __asm__("func_0025BD88");
M2C_UNK strcpy_165A38() __asm__("strcpy");
extern s32 D_002C1694_165A38 __asm__("D_002C1694");
extern M2C_UNK func_001627B0_165A38 __asm__("func_001627B0");

s32 func_00165A38(s32* arg0, s32 arg1, s32 arg2) {
    u8 sp[0x60];
    M2C_UNK sp15;
    M2C_UNK sp26;
    M2C_UNK sp46;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165A38(temp_s0, 3, sp);
    strcpy_165A38(&sp15, temp_s0);
    strcpy_165A38(&sp26, arg1);
    strcpy_165A38(&sp46, arg2);
    *arg0 = 0;
    temp_v0 = func_0025A344_165A38(sp, &func_001627B0_165A38);
    if (temp_v0 != 0) {
        func_00163EB8_165A38(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165A38(arg0, 0xC350);
    return (D_002C1694_165A38 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165A38 m2c2
#include "m2c_macros.h"
M2C_UNK func_00163E00_165A38() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165A38() __asm__("func_00163EB8");
s32 func_0025A344_165A38() __asm__("func_0025A344");
M2C_UNK func_0025BD88_165A38() __asm__("func_0025BD88");
M2C_UNK strcpy_165A38() __asm__("strcpy");
extern s32 D_002C1694_165A38 __asm__("D_002C1694");
extern M2C_UNK func_001627B0_165A38 __asm__("func_001627B0");

s32 func_00165A38(s32* arg0, s32 arg1, s32 arg2) {
    u8 sp[0x50];
    M2C_UNK sp15;
    M2C_UNK sp26;
    M2C_UNK sp46;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165A38(temp_s0, 3, sp);
    strcpy_165A38(&sp15, temp_s0);
    strcpy_165A38(&sp26, arg1);
    strcpy_165A38(&sp46, arg2);
    *arg0 = 0;
    temp_v0 = func_0025A344_165A38(sp, &func_001627B0_165A38);
    if (temp_v0 != 0) {
        func_00163EB8_165A38(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165A38(arg0, 0xC350);
    return (D_002C1694_165A38 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165A38 m2c3
#include "m2c_macros.h"
M2C_UNK func_00163E00_165A38() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165A38() __asm__("func_00163EB8");
s32 func_0025A344_165A38() __asm__("func_0025A344");
M2C_UNK func_0025BD88_165A38() __asm__("func_0025BD88");
M2C_UNK strcpy_165A38() __asm__("strcpy");
extern s32 D_002C1694_165A38 __asm__("D_002C1694");
extern M2C_UNK func_001627B0_165A38 __asm__("func_001627B0");

s32 func_00165A38(s32* arg0, s32 arg1, s32 arg2) {
    u8 sp[0x40];
    M2C_UNK sp15;
    M2C_UNK sp26;
    M2C_UNK sp46;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165A38(temp_s0, 3, sp);
    strcpy_165A38(&sp15, temp_s0);
    strcpy_165A38(&sp26, arg1);
    strcpy_165A38(&sp46, arg2);
    *arg0 = 0;
    temp_v0 = func_0025A344_165A38(sp, &func_001627B0_165A38);
    if (temp_v0 != 0) {
        func_00163EB8_165A38(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165A38(arg0, 0xC350);
    return (D_002C1694_165A38 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165A38 m2c4
#include "m2c_macros.h"
M2C_UNK func_00163E00_165A38() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165A38() __asm__("func_00163EB8");
s32 func_0025A344_165A38() __asm__("func_0025A344");
M2C_UNK func_0025BD88_165A38() __asm__("func_0025BD88");
M2C_UNK strcpy_165A38() __asm__("strcpy");
extern s32 D_002C1694_165A38 __asm__("D_002C1694");
extern M2C_UNK func_001627B0_165A38 __asm__("func_001627B0");

s32 func_00165A38(s32* arg0, s32 arg1, s32 arg2) {
    u8 sp[0x30];
    M2C_UNK sp15;
    M2C_UNK sp26;
    M2C_UNK sp46;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165A38(temp_s0, 3, sp);
    strcpy_165A38(&sp15, temp_s0);
    strcpy_165A38(&sp26, arg1);
    strcpy_165A38(&sp46, arg2);
    *arg0 = 0;
    temp_v0 = func_0025A344_165A38(sp, &func_001627B0_165A38);
    if (temp_v0 != 0) {
        func_00163EB8_165A38(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165A38(arg0, 0xC350);
    return (D_002C1694_165A38 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165A38 m2c5
#include "m2c_macros.h"
M2C_UNK func_00163E00_165A38() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165A38() __asm__("func_00163EB8");
s32 func_0025A344_165A38() __asm__("func_0025A344");
M2C_UNK func_0025BD88_165A38() __asm__("func_0025BD88");
M2C_UNK strcpy_165A38() __asm__("strcpy");
extern s32 D_002C1694_165A38 __asm__("D_002C1694");
extern M2C_UNK func_001627B0_165A38 __asm__("func_001627B0");

s32 func_00165A38(s32* arg0, s32 arg1, s32 arg2) {
    u8 sp[0x20];
    M2C_UNK sp15;
    M2C_UNK sp26;
    M2C_UNK sp46;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165A38(temp_s0, 3, sp);
    strcpy_165A38(&sp15, temp_s0);
    strcpy_165A38(&sp26, arg1);
    strcpy_165A38(&sp46, arg2);
    *arg0 = 0;
    temp_v0 = func_0025A344_165A38(sp, &func_001627B0_165A38);
    if (temp_v0 != 0) {
        func_00163EB8_165A38(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165A38(arg0, 0xC350);
    return (D_002C1694_165A38 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165B08 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163E00_165B08() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165B08() __asm__("func_00163EB8");
s32 func_0025A3FC_165B08() __asm__("func_0025A3FC");
M2C_UNK func_0025BD88_165B08() __asm__("func_0025BD88");
M2C_UNK strcpy_165B08() __asm__("strcpy");
extern s32 D_002C1694_165B08 __asm__("D_002C1694");
extern M2C_UNK func_001628E0_165B08 __asm__("func_001628E0");

s32 func_00165B08(s32* arg0) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165B08(temp_s0, 4, sp);
    strcpy_165B08(&sp15, temp_s0);
    *arg0 = 0;
    temp_v0 = func_0025A3FC_165B08(sp, &func_001628E0_165B08);
    if (temp_v0 != 0) {
        func_00163EB8_165B08(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165B08(arg0, 0xC350);
    return (D_002C1694_165B08 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165B08 m2c1
#include "m2c_macros.h"
M2C_UNK func_00163E00_165B08() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165B08() __asm__("func_00163EB8");
s32 func_0025A3FC_165B08() __asm__("func_0025A3FC");
M2C_UNK func_0025BD88_165B08() __asm__("func_0025BD88");
M2C_UNK strcpy_165B08() __asm__("strcpy");
extern s32 D_002C1694_165B08 __asm__("D_002C1694");
extern M2C_UNK func_001628E0_165B08 __asm__("func_001628E0");

s32 func_00165B08(s32* arg0) {
    u8 sp[0x20];
    M2C_UNK sp15;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165B08(temp_s0, 4, sp);
    strcpy_165B08(&sp15, temp_s0);
    *arg0 = 0;
    temp_v0 = func_0025A3FC_165B08(sp, &func_001628E0_165B08);
    if (temp_v0 != 0) {
        func_00163EB8_165B08(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165B08(arg0, 0xC350);
    return (D_002C1694_165B08 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165B08 m2c2
#include "m2c_macros.h"
M2C_UNK func_00163E00_165B08() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165B08() __asm__("func_00163EB8");
s32 func_0025A3FC_165B08() __asm__("func_0025A3FC");
M2C_UNK func_0025BD88_165B08() __asm__("func_0025BD88");
M2C_UNK strcpy_165B08() __asm__("strcpy");
extern s32 D_002C1694_165B08 __asm__("D_002C1694");
extern M2C_UNK func_001628E0_165B08 __asm__("func_001628E0");

s32 func_00165B08(s32* arg0) {
    u8 sp[0x10];
    M2C_UNK sp15;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165B08(temp_s0, 4, sp);
    strcpy_165B08(&sp15, temp_s0);
    *arg0 = 0;
    temp_v0 = func_0025A3FC_165B08(sp, &func_001628E0_165B08);
    if (temp_v0 != 0) {
        func_00163EB8_165B08(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165B08(arg0, 0xC350);
    return (D_002C1694_165B08 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165B08 m2c3
#include "m2c_macros.h"
M2C_UNK func_00163E00_165B08() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165B08() __asm__("func_00163EB8");
s32 func_0025A3FC_165B08() __asm__("func_0025A3FC");
M2C_UNK func_0025BD88_165B08() __asm__("func_0025BD88");
M2C_UNK strcpy_165B08() __asm__("strcpy");
extern s32 D_002C1694_165B08 __asm__("D_002C1694");
extern M2C_UNK func_001628E0_165B08 __asm__("func_001628E0");

s32 func_00165B08(s32* arg0) {
    u8 sp[0x8];
    M2C_UNK sp15;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165B08(temp_s0, 4, sp);
    strcpy_165B08(&sp15, temp_s0);
    *arg0 = 0;
    temp_v0 = func_0025A3FC_165B08(sp, &func_001628E0_165B08);
    if (temp_v0 != 0) {
        func_00163EB8_165B08(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165B08(arg0, 0xC350);
    return (D_002C1694_165B08 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165B08 m2c4
#include "m2c_macros.h"
M2C_UNK func_00163E00_165B08() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165B08() __asm__("func_00163EB8");
s32 func_0025A3FC_165B08() __asm__("func_0025A3FC");
M2C_UNK func_0025BD88_165B08() __asm__("func_0025BD88");
M2C_UNK strcpy_165B08() __asm__("strcpy");
extern s32 D_002C1694_165B08 __asm__("D_002C1694");
extern M2C_UNK func_001628E0_165B08 __asm__("func_001628E0");

s32 func_00165B08(s32* arg0) {
    u8 sp[0x4];
    M2C_UNK sp15;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165B08(temp_s0, 4, sp);
    strcpy_165B08(&sp15, temp_s0);
    *arg0 = 0;
    temp_v0 = func_0025A3FC_165B08(sp, &func_001628E0_165B08);
    if (temp_v0 != 0) {
        func_00163EB8_165B08(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165B08(arg0, 0xC350);
    return (D_002C1694_165B08 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165BA8 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163E00_165BA8() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165BA8() __asm__("func_00163EB8");
s32 func_0025A53C_165BA8() __asm__("func_0025A53C");
M2C_UNK func_0025BD88_165BA8() __asm__("func_0025BD88");
M2C_UNK strcpy_165BA8() __asm__("strcpy");
extern s32 D_002C1694_165BA8 __asm__("D_002C1694");
extern M2C_UNK func_00162918_165BA8 __asm__("func_00162918");

s32 func_00165BA8(s32* arg0, s32 arg1, s32 arg2) {
    u8 sp[0x70];
    M2C_UNK sp15;
    s32 sp28;
    M2C_UNK sp2C;
    M2C_UNK sp4C;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165BA8(temp_s0, 5, sp);
    strcpy_165BA8(&sp15, temp_s0);
    sp28 = 1;
    strcpy_165BA8(&sp2C, arg1);
    strcpy_165BA8(&sp4C, arg2);
    *arg0 = 0;
    temp_v0 = func_0025A53C_165BA8(sp, &func_00162918_165BA8);
    if (temp_v0 != 0) {
        func_00163EB8_165BA8(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165BA8(arg0, 0xC350);
    return (D_002C1694_165BA8 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165BA8 m2c1
#include "m2c_macros.h"
M2C_UNK func_00163E00_165BA8() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165BA8() __asm__("func_00163EB8");
s32 func_0025A53C_165BA8() __asm__("func_0025A53C");
M2C_UNK func_0025BD88_165BA8() __asm__("func_0025BD88");
M2C_UNK strcpy_165BA8() __asm__("strcpy");
extern s32 D_002C1694_165BA8 __asm__("D_002C1694");
extern M2C_UNK func_00162918_165BA8 __asm__("func_00162918");

s32 func_00165BA8(s32* arg0, s32 arg1, s32 arg2) {
    u8 sp[0x60];
    M2C_UNK sp15;
    s32 sp28;
    M2C_UNK sp2C;
    M2C_UNK sp4C;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165BA8(temp_s0, 5, sp);
    strcpy_165BA8(&sp15, temp_s0);
    sp28 = 1;
    strcpy_165BA8(&sp2C, arg1);
    strcpy_165BA8(&sp4C, arg2);
    *arg0 = 0;
    temp_v0 = func_0025A53C_165BA8(sp, &func_00162918_165BA8);
    if (temp_v0 != 0) {
        func_00163EB8_165BA8(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165BA8(arg0, 0xC350);
    return (D_002C1694_165BA8 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165BA8 m2c2
#include "m2c_macros.h"
M2C_UNK func_00163E00_165BA8() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165BA8() __asm__("func_00163EB8");
s32 func_0025A53C_165BA8() __asm__("func_0025A53C");
M2C_UNK func_0025BD88_165BA8() __asm__("func_0025BD88");
M2C_UNK strcpy_165BA8() __asm__("strcpy");
extern s32 D_002C1694_165BA8 __asm__("D_002C1694");
extern M2C_UNK func_00162918_165BA8 __asm__("func_00162918");

s32 func_00165BA8(s32* arg0, s32 arg1, s32 arg2) {
    u8 sp[0x50];
    M2C_UNK sp15;
    s32 sp28;
    M2C_UNK sp2C;
    M2C_UNK sp4C;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165BA8(temp_s0, 5, sp);
    strcpy_165BA8(&sp15, temp_s0);
    sp28 = 1;
    strcpy_165BA8(&sp2C, arg1);
    strcpy_165BA8(&sp4C, arg2);
    *arg0 = 0;
    temp_v0 = func_0025A53C_165BA8(sp, &func_00162918_165BA8);
    if (temp_v0 != 0) {
        func_00163EB8_165BA8(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165BA8(arg0, 0xC350);
    return (D_002C1694_165BA8 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165BA8 m2c3
#include "m2c_macros.h"
M2C_UNK func_00163E00_165BA8() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165BA8() __asm__("func_00163EB8");
s32 func_0025A53C_165BA8() __asm__("func_0025A53C");
M2C_UNK func_0025BD88_165BA8() __asm__("func_0025BD88");
M2C_UNK strcpy_165BA8() __asm__("strcpy");
extern s32 D_002C1694_165BA8 __asm__("D_002C1694");
extern M2C_UNK func_00162918_165BA8 __asm__("func_00162918");

s32 func_00165BA8(s32* arg0, s32 arg1, s32 arg2) {
    u8 sp[0x40];
    M2C_UNK sp15;
    s32 sp28;
    M2C_UNK sp2C;
    M2C_UNK sp4C;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165BA8(temp_s0, 5, sp);
    strcpy_165BA8(&sp15, temp_s0);
    sp28 = 1;
    strcpy_165BA8(&sp2C, arg1);
    strcpy_165BA8(&sp4C, arg2);
    *arg0 = 0;
    temp_v0 = func_0025A53C_165BA8(sp, &func_00162918_165BA8);
    if (temp_v0 != 0) {
        func_00163EB8_165BA8(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165BA8(arg0, 0xC350);
    return (D_002C1694_165BA8 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165BA8 m2c4
#include "m2c_macros.h"
M2C_UNK func_00163E00_165BA8() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165BA8() __asm__("func_00163EB8");
s32 func_0025A53C_165BA8() __asm__("func_0025A53C");
M2C_UNK func_0025BD88_165BA8() __asm__("func_0025BD88");
M2C_UNK strcpy_165BA8() __asm__("strcpy");
extern s32 D_002C1694_165BA8 __asm__("D_002C1694");
extern M2C_UNK func_00162918_165BA8 __asm__("func_00162918");

s32 func_00165BA8(s32* arg0, s32 arg1, s32 arg2) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 sp28;
    M2C_UNK sp2C;
    M2C_UNK sp4C;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165BA8(temp_s0, 5, sp);
    strcpy_165BA8(&sp15, temp_s0);
    sp28 = 1;
    strcpy_165BA8(&sp2C, arg1);
    strcpy_165BA8(&sp4C, arg2);
    *arg0 = 0;
    temp_v0 = func_0025A53C_165BA8(sp, &func_00162918_165BA8);
    if (temp_v0 != 0) {
        func_00163EB8_165BA8(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165BA8(arg0, 0xC350);
    return (D_002C1694_165BA8 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165BA8 m2c5
#include "m2c_macros.h"
M2C_UNK func_00163E00_165BA8() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165BA8() __asm__("func_00163EB8");
s32 func_0025A53C_165BA8() __asm__("func_0025A53C");
M2C_UNK func_0025BD88_165BA8() __asm__("func_0025BD88");
M2C_UNK strcpy_165BA8() __asm__("strcpy");
extern s32 D_002C1694_165BA8 __asm__("D_002C1694");
extern M2C_UNK func_00162918_165BA8 __asm__("func_00162918");

s32 func_00165BA8(s32* arg0, s32 arg1, s32 arg2) {
    u8 sp[0x20];
    M2C_UNK sp15;
    s32 sp28;
    M2C_UNK sp2C;
    M2C_UNK sp4C;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165BA8(temp_s0, 5, sp);
    strcpy_165BA8(&sp15, temp_s0);
    sp28 = 1;
    strcpy_165BA8(&sp2C, arg1);
    strcpy_165BA8(&sp4C, arg2);
    *arg0 = 0;
    temp_v0 = func_0025A53C_165BA8(sp, &func_00162918_165BA8);
    if (temp_v0 != 0) {
        func_00163EB8_165BA8(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165BA8(arg0, 0xC350);
    return (D_002C1694_165BA8 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165C80 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163E00_165C80() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165C80() __asm__("func_00163EB8");
s32 func_0025A5F4_165C80() __asm__("func_0025A5F4");
M2C_UNK func_0025BD88_165C80() __asm__("func_0025BD88");
M2C_UNK strcpy_165C80() __asm__("strcpy");
extern s32 D_002C1694_165C80 __asm__("D_002C1694");
extern M2C_UNK func_00162950_165C80 __asm__("func_00162950");

s32 func_00165C80(s32* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp[0x70];
    M2C_UNK sp15;
    M2C_UNK sp26;
    M2C_UNK sp46;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165C80(temp_s0, 7, sp);
    strcpy_165C80(&sp15, temp_s0);
    strcpy_165C80(&sp26, arg2);
    strcpy_165C80(&sp46, arg3);
    *arg0 = 0;
    temp_v0 = func_0025A5F4_165C80(sp, &func_00162950_165C80);
    if (temp_v0 != 0) {
        func_00163EB8_165C80(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165C80(arg0, 0xC350);
    return (D_002C1694_165C80 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165C80 m2c1
#include "m2c_macros.h"
M2C_UNK func_00163E00_165C80() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165C80() __asm__("func_00163EB8");
s32 func_0025A5F4_165C80() __asm__("func_0025A5F4");
M2C_UNK func_0025BD88_165C80() __asm__("func_0025BD88");
M2C_UNK strcpy_165C80() __asm__("strcpy");
extern s32 D_002C1694_165C80 __asm__("D_002C1694");
extern M2C_UNK func_00162950_165C80 __asm__("func_00162950");

s32 func_00165C80(s32* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp[0x60];
    M2C_UNK sp15;
    M2C_UNK sp26;
    M2C_UNK sp46;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165C80(temp_s0, 7, sp);
    strcpy_165C80(&sp15, temp_s0);
    strcpy_165C80(&sp26, arg2);
    strcpy_165C80(&sp46, arg3);
    *arg0 = 0;
    temp_v0 = func_0025A5F4_165C80(sp, &func_00162950_165C80);
    if (temp_v0 != 0) {
        func_00163EB8_165C80(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165C80(arg0, 0xC350);
    return (D_002C1694_165C80 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165C80 m2c2
#include "m2c_macros.h"
M2C_UNK func_00163E00_165C80() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165C80() __asm__("func_00163EB8");
s32 func_0025A5F4_165C80() __asm__("func_0025A5F4");
M2C_UNK func_0025BD88_165C80() __asm__("func_0025BD88");
M2C_UNK strcpy_165C80() __asm__("strcpy");
extern s32 D_002C1694_165C80 __asm__("D_002C1694");
extern M2C_UNK func_00162950_165C80 __asm__("func_00162950");

s32 func_00165C80(s32* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp[0x50];
    M2C_UNK sp15;
    M2C_UNK sp26;
    M2C_UNK sp46;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165C80(temp_s0, 7, sp);
    strcpy_165C80(&sp15, temp_s0);
    strcpy_165C80(&sp26, arg2);
    strcpy_165C80(&sp46, arg3);
    *arg0 = 0;
    temp_v0 = func_0025A5F4_165C80(sp, &func_00162950_165C80);
    if (temp_v0 != 0) {
        func_00163EB8_165C80(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165C80(arg0, 0xC350);
    return (D_002C1694_165C80 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165C80 m2c3
#include "m2c_macros.h"
M2C_UNK func_00163E00_165C80() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165C80() __asm__("func_00163EB8");
s32 func_0025A5F4_165C80() __asm__("func_0025A5F4");
M2C_UNK func_0025BD88_165C80() __asm__("func_0025BD88");
M2C_UNK strcpy_165C80() __asm__("strcpy");
extern s32 D_002C1694_165C80 __asm__("D_002C1694");
extern M2C_UNK func_00162950_165C80 __asm__("func_00162950");

s32 func_00165C80(s32* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp[0x40];
    M2C_UNK sp15;
    M2C_UNK sp26;
    M2C_UNK sp46;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165C80(temp_s0, 7, sp);
    strcpy_165C80(&sp15, temp_s0);
    strcpy_165C80(&sp26, arg2);
    strcpy_165C80(&sp46, arg3);
    *arg0 = 0;
    temp_v0 = func_0025A5F4_165C80(sp, &func_00162950_165C80);
    if (temp_v0 != 0) {
        func_00163EB8_165C80(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165C80(arg0, 0xC350);
    return (D_002C1694_165C80 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165C80 m2c4
#include "m2c_macros.h"
M2C_UNK func_00163E00_165C80() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165C80() __asm__("func_00163EB8");
s32 func_0025A5F4_165C80() __asm__("func_0025A5F4");
M2C_UNK func_0025BD88_165C80() __asm__("func_0025BD88");
M2C_UNK strcpy_165C80() __asm__("strcpy");
extern s32 D_002C1694_165C80 __asm__("D_002C1694");
extern M2C_UNK func_00162950_165C80 __asm__("func_00162950");

s32 func_00165C80(s32* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp[0x30];
    M2C_UNK sp15;
    M2C_UNK sp26;
    M2C_UNK sp46;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165C80(temp_s0, 7, sp);
    strcpy_165C80(&sp15, temp_s0);
    strcpy_165C80(&sp26, arg2);
    strcpy_165C80(&sp46, arg3);
    *arg0 = 0;
    temp_v0 = func_0025A5F4_165C80(sp, &func_00162950_165C80);
    if (temp_v0 != 0) {
        func_00163EB8_165C80(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165C80(arg0, 0xC350);
    return (D_002C1694_165C80 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165C80 m2c5
#include "m2c_macros.h"
M2C_UNK func_00163E00_165C80() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165C80() __asm__("func_00163EB8");
s32 func_0025A5F4_165C80() __asm__("func_0025A5F4");
M2C_UNK func_0025BD88_165C80() __asm__("func_0025BD88");
M2C_UNK strcpy_165C80() __asm__("strcpy");
extern s32 D_002C1694_165C80 __asm__("D_002C1694");
extern M2C_UNK func_00162950_165C80 __asm__("func_00162950");

s32 func_00165C80(s32* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp[0x20];
    M2C_UNK sp15;
    M2C_UNK sp26;
    M2C_UNK sp46;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165C80(temp_s0, 7, sp);
    strcpy_165C80(&sp15, temp_s0);
    strcpy_165C80(&sp26, arg2);
    strcpy_165C80(&sp46, arg3);
    *arg0 = 0;
    temp_v0 = func_0025A5F4_165C80(sp, &func_00162950_165C80);
    if (temp_v0 != 0) {
        func_00163EB8_165C80(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165C80(arg0, 0xC350);
    return (D_002C1694_165C80 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165D50 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163E00_165D50() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165D50() __asm__("func_00163EB8");
s32 func_0025A888_165D50() __asm__("func_0025A888");
M2C_UNK func_0025BD88_165D50() __asm__("func_0025BD88");
M2C_UNK strcpy_165D50() __asm__("strcpy");
extern s32 D_002C1694_165D50 __asm__("D_002C1694");
extern M2C_UNK func_00162988_165D50 __asm__("func_00162988");

s32 func_00165D50(s32* arg0, s32 arg1) {
    u8 sp[0x50];
    M2C_UNK sp15;
    M2C_UNK sp26;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165D50(temp_s0, 0, sp);
    strcpy_165D50(&sp15, temp_s0);
    strcpy_165D50(&sp26, arg1);
    *arg0 = 0;
    temp_v0 = func_0025A888_165D50(sp, &func_00162988_165D50);
    if (temp_v0 != 0) {
        func_00163EB8_165D50(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165D50(arg0, 0xC350);
    return (D_002C1694_165D50 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165D50 m2c1
#include "m2c_macros.h"
M2C_UNK func_00163E00_165D50() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165D50() __asm__("func_00163EB8");
s32 func_0025A888_165D50() __asm__("func_0025A888");
M2C_UNK func_0025BD88_165D50() __asm__("func_0025BD88");
M2C_UNK strcpy_165D50() __asm__("strcpy");
extern s32 D_002C1694_165D50 __asm__("D_002C1694");
extern M2C_UNK func_00162988_165D50 __asm__("func_00162988");

s32 func_00165D50(s32* arg0, s32 arg1) {
    u8 sp[0x40];
    M2C_UNK sp15;
    M2C_UNK sp26;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165D50(temp_s0, 0, sp);
    strcpy_165D50(&sp15, temp_s0);
    strcpy_165D50(&sp26, arg1);
    *arg0 = 0;
    temp_v0 = func_0025A888_165D50(sp, &func_00162988_165D50);
    if (temp_v0 != 0) {
        func_00163EB8_165D50(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165D50(arg0, 0xC350);
    return (D_002C1694_165D50 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165D50 m2c2
#include "m2c_macros.h"
M2C_UNK func_00163E00_165D50() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165D50() __asm__("func_00163EB8");
s32 func_0025A888_165D50() __asm__("func_0025A888");
M2C_UNK func_0025BD88_165D50() __asm__("func_0025BD88");
M2C_UNK strcpy_165D50() __asm__("strcpy");
extern s32 D_002C1694_165D50 __asm__("D_002C1694");
extern M2C_UNK func_00162988_165D50 __asm__("func_00162988");

s32 func_00165D50(s32* arg0, s32 arg1) {
    u8 sp[0x30];
    M2C_UNK sp15;
    M2C_UNK sp26;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165D50(temp_s0, 0, sp);
    strcpy_165D50(&sp15, temp_s0);
    strcpy_165D50(&sp26, arg1);
    *arg0 = 0;
    temp_v0 = func_0025A888_165D50(sp, &func_00162988_165D50);
    if (temp_v0 != 0) {
        func_00163EB8_165D50(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165D50(arg0, 0xC350);
    return (D_002C1694_165D50 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165D50 m2c3
#include "m2c_macros.h"
M2C_UNK func_00163E00_165D50() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165D50() __asm__("func_00163EB8");
s32 func_0025A888_165D50() __asm__("func_0025A888");
M2C_UNK func_0025BD88_165D50() __asm__("func_0025BD88");
M2C_UNK strcpy_165D50() __asm__("strcpy");
extern s32 D_002C1694_165D50 __asm__("D_002C1694");
extern M2C_UNK func_00162988_165D50 __asm__("func_00162988");

s32 func_00165D50(s32* arg0, s32 arg1) {
    u8 sp[0x20];
    M2C_UNK sp15;
    M2C_UNK sp26;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165D50(temp_s0, 0, sp);
    strcpy_165D50(&sp15, temp_s0);
    strcpy_165D50(&sp26, arg1);
    *arg0 = 0;
    temp_v0 = func_0025A888_165D50(sp, &func_00162988_165D50);
    if (temp_v0 != 0) {
        func_00163EB8_165D50(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165D50(arg0, 0xC350);
    return (D_002C1694_165D50 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165D50 m2c4
#include "m2c_macros.h"
M2C_UNK func_00163E00_165D50() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165D50() __asm__("func_00163EB8");
s32 func_0025A888_165D50() __asm__("func_0025A888");
M2C_UNK func_0025BD88_165D50() __asm__("func_0025BD88");
M2C_UNK strcpy_165D50() __asm__("strcpy");
extern s32 D_002C1694_165D50 __asm__("D_002C1694");
extern M2C_UNK func_00162988_165D50 __asm__("func_00162988");

s32 func_00165D50(s32* arg0, s32 arg1) {
    u8 sp[0x10];
    M2C_UNK sp15;
    M2C_UNK sp26;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165D50(temp_s0, 0, sp);
    strcpy_165D50(&sp15, temp_s0);
    strcpy_165D50(&sp26, arg1);
    *arg0 = 0;
    temp_v0 = func_0025A888_165D50(sp, &func_00162988_165D50);
    if (temp_v0 != 0) {
        func_00163EB8_165D50(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165D50(arg0, 0xC350);
    return (D_002C1694_165D50 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165D50 m2c5
#include "m2c_macros.h"
M2C_UNK func_00163E00_165D50() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165D50() __asm__("func_00163EB8");
s32 func_0025A888_165D50() __asm__("func_0025A888");
M2C_UNK func_0025BD88_165D50() __asm__("func_0025BD88");
M2C_UNK strcpy_165D50() __asm__("strcpy");
extern s32 D_002C1694_165D50 __asm__("D_002C1694");
extern M2C_UNK func_00162988_165D50 __asm__("func_00162988");

s32 func_00165D50(s32* arg0, s32 arg1) {
    u8 sp[0x8];
    M2C_UNK sp15;
    M2C_UNK sp26;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165D50(temp_s0, 0, sp);
    strcpy_165D50(&sp15, temp_s0);
    strcpy_165D50(&sp26, arg1);
    *arg0 = 0;
    temp_v0 = func_0025A888_165D50(sp, &func_00162988_165D50);
    if (temp_v0 != 0) {
        func_00163EB8_165D50(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165D50(arg0, 0xC350);
    return (D_002C1694_165D50 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165E08 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163E00_165E08() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165E08() __asm__("func_00163EB8");
M2C_UNK func_0025BD88_165E08() __asm__("func_0025BD88");
s32 func_0025C088_165E08() __asm__("func_0025C088");
M2C_UNK strcpy_165E08() __asm__("strcpy");
extern s32 D_002C1694_165E08 __asm__("D_002C1694");
extern M2C_UNK func_001629C0_165E08 __asm__("func_001629C0");

s32 func_00165E08(void* arg0, s32 arg1) {
    u8 sp[0x50];
    M2C_UNK sp15;
    M2C_UNK sp26;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165E08(temp_s0, 1, sp);
    strcpy_165E08(&sp15, temp_s0);
    strcpy_165E08(&sp26, arg1);
    M2C_FIELD(arg0, s32* , 0) = 0;
    temp_v0 = func_0025C088_165E08(sp, &func_001629C0_165E08);
    if (temp_v0 == 0) {
        func_00163E00_165E08(arg0, 0xC350);
        if (D_002C1694_165E08 >= 0) {
            return 0;
        }
        M2C_FIELD(arg0, s32* , 0x60) = -1;
        return 0xFFFFFF;
    }
    M2C_FIELD(arg0, s32* , 0x60) = -1;
    func_00163EB8_165E08(arg0, 0xFFFFFF);
    return temp_v0;
}
//@@ func_00165E08 m2c1
#include "m2c_macros.h"
M2C_UNK func_00163E00_165E08() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165E08() __asm__("func_00163EB8");
M2C_UNK func_0025BD88_165E08() __asm__("func_0025BD88");
s32 func_0025C088_165E08() __asm__("func_0025C088");
M2C_UNK strcpy_165E08() __asm__("strcpy");
extern s32 D_002C1694_165E08 __asm__("D_002C1694");
extern M2C_UNK func_001629C0_165E08 __asm__("func_001629C0");

s32 func_00165E08(void* arg0, s32 arg1) {
    u8 sp[0x40];
    M2C_UNK sp15;
    M2C_UNK sp26;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165E08(temp_s0, 1, sp);
    strcpy_165E08(&sp15, temp_s0);
    strcpy_165E08(&sp26, arg1);
    M2C_FIELD(arg0, s32* , 0) = 0;
    temp_v0 = func_0025C088_165E08(sp, &func_001629C0_165E08);
    if (temp_v0 == 0) {
        func_00163E00_165E08(arg0, 0xC350);
        if (D_002C1694_165E08 >= 0) {
            return 0;
        }
        M2C_FIELD(arg0, s32* , 0x60) = -1;
        return 0xFFFFFF;
    }
    M2C_FIELD(arg0, s32* , 0x60) = -1;
    func_00163EB8_165E08(arg0, 0xFFFFFF);
    return temp_v0;
}
//@@ func_00165E08 m2c2
#include "m2c_macros.h"
M2C_UNK func_00163E00_165E08() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165E08() __asm__("func_00163EB8");
M2C_UNK func_0025BD88_165E08() __asm__("func_0025BD88");
s32 func_0025C088_165E08() __asm__("func_0025C088");
M2C_UNK strcpy_165E08() __asm__("strcpy");
extern s32 D_002C1694_165E08 __asm__("D_002C1694");
extern M2C_UNK func_001629C0_165E08 __asm__("func_001629C0");

s32 func_00165E08(void* arg0, s32 arg1) {
    u8 sp[0x30];
    M2C_UNK sp15;
    M2C_UNK sp26;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165E08(temp_s0, 1, sp);
    strcpy_165E08(&sp15, temp_s0);
    strcpy_165E08(&sp26, arg1);
    M2C_FIELD(arg0, s32* , 0) = 0;
    temp_v0 = func_0025C088_165E08(sp, &func_001629C0_165E08);
    if (temp_v0 == 0) {
        func_00163E00_165E08(arg0, 0xC350);
        if (D_002C1694_165E08 >= 0) {
            return 0;
        }
        M2C_FIELD(arg0, s32* , 0x60) = -1;
        return 0xFFFFFF;
    }
    M2C_FIELD(arg0, s32* , 0x60) = -1;
    func_00163EB8_165E08(arg0, 0xFFFFFF);
    return temp_v0;
}
//@@ func_00165E08 m2c3
#include "m2c_macros.h"
M2C_UNK func_00163E00_165E08() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165E08() __asm__("func_00163EB8");
M2C_UNK func_0025BD88_165E08() __asm__("func_0025BD88");
s32 func_0025C088_165E08() __asm__("func_0025C088");
M2C_UNK strcpy_165E08() __asm__("strcpy");
extern s32 D_002C1694_165E08 __asm__("D_002C1694");
extern M2C_UNK func_001629C0_165E08 __asm__("func_001629C0");

s32 func_00165E08(void* arg0, s32 arg1) {
    u8 sp[0x20];
    M2C_UNK sp15;
    M2C_UNK sp26;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165E08(temp_s0, 1, sp);
    strcpy_165E08(&sp15, temp_s0);
    strcpy_165E08(&sp26, arg1);
    M2C_FIELD(arg0, s32* , 0) = 0;
    temp_v0 = func_0025C088_165E08(sp, &func_001629C0_165E08);
    if (temp_v0 == 0) {
        func_00163E00_165E08(arg0, 0xC350);
        if (D_002C1694_165E08 >= 0) {
            return 0;
        }
        M2C_FIELD(arg0, s32* , 0x60) = -1;
        return 0xFFFFFF;
    }
    M2C_FIELD(arg0, s32* , 0x60) = -1;
    func_00163EB8_165E08(arg0, 0xFFFFFF);
    return temp_v0;
}
//@@ func_00165E08 m2c4
#include "m2c_macros.h"
M2C_UNK func_00163E00_165E08() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165E08() __asm__("func_00163EB8");
M2C_UNK func_0025BD88_165E08() __asm__("func_0025BD88");
s32 func_0025C088_165E08() __asm__("func_0025C088");
M2C_UNK strcpy_165E08() __asm__("strcpy");
extern s32 D_002C1694_165E08 __asm__("D_002C1694");
extern M2C_UNK func_001629C0_165E08 __asm__("func_001629C0");

s32 func_00165E08(void* arg0, s32 arg1) {
    u8 sp[0x10];
    M2C_UNK sp15;
    M2C_UNK sp26;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165E08(temp_s0, 1, sp);
    strcpy_165E08(&sp15, temp_s0);
    strcpy_165E08(&sp26, arg1);
    M2C_FIELD(arg0, s32* , 0) = 0;
    temp_v0 = func_0025C088_165E08(sp, &func_001629C0_165E08);
    if (temp_v0 == 0) {
        func_00163E00_165E08(arg0, 0xC350);
        if (D_002C1694_165E08 >= 0) {
            return 0;
        }
        M2C_FIELD(arg0, s32* , 0x60) = -1;
        return 0xFFFFFF;
    }
    M2C_FIELD(arg0, s32* , 0x60) = -1;
    func_00163EB8_165E08(arg0, 0xFFFFFF);
    return temp_v0;
}
//@@ func_00165E08 m2c5
#include "m2c_macros.h"
M2C_UNK func_00163E00_165E08() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165E08() __asm__("func_00163EB8");
M2C_UNK func_0025BD88_165E08() __asm__("func_0025BD88");
s32 func_0025C088_165E08() __asm__("func_0025C088");
M2C_UNK strcpy_165E08() __asm__("strcpy");
extern s32 D_002C1694_165E08 __asm__("D_002C1694");
extern M2C_UNK func_001629C0_165E08 __asm__("func_001629C0");

s32 func_00165E08(void* arg0, s32 arg1) {
    u8 sp[0x8];
    M2C_UNK sp15;
    M2C_UNK sp26;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165E08(temp_s0, 1, sp);
    strcpy_165E08(&sp15, temp_s0);
    strcpy_165E08(&sp26, arg1);
    M2C_FIELD(arg0, s32* , 0) = 0;
    temp_v0 = func_0025C088_165E08(sp, &func_001629C0_165E08);
    if (temp_v0 == 0) {
        func_00163E00_165E08(arg0, 0xC350);
        if (D_002C1694_165E08 >= 0) {
            return 0;
        }
        M2C_FIELD(arg0, s32* , 0x60) = -1;
        return 0xFFFFFF;
    }
    M2C_FIELD(arg0, s32* , 0x60) = -1;
    func_00163EB8_165E08(arg0, 0xFFFFFF);
    return temp_v0;
}
//@@ func_00165ED0 m2c0
#include "m2c_macros.h"
M2C_UNK func_0025A184_165ED0() __asm__("func_0025A184");
M2C_UNK strcpy_165ED0() __asm__("strcpy");

void func_00165ED0(s32 arg0, s32 arg1) {
    u8 sp[0x20];
    strcpy_165ED0(sp, arg0 + 0xC);
    func_0025A184_165ED0(sp, arg1);
}
//@@ func_00165ED0 m2c1
#include "m2c_macros.h"
M2C_UNK func_0025A184_165ED0() __asm__("func_0025A184");
M2C_UNK strcpy_165ED0() __asm__("strcpy");

void func_00165ED0(s32 arg0, s32 arg1) {
    u8 sp[0x10];
    strcpy_165ED0(sp, arg0 + 0xC);
    func_0025A184_165ED0(sp, arg1);
}
//@@ func_00165ED0 m2c2
#include "m2c_macros.h"
M2C_UNK func_0025A184_165ED0() __asm__("func_0025A184");
M2C_UNK strcpy_165ED0() __asm__("strcpy");

void func_00165ED0(s32 arg0, s32 arg1) {
    u8 sp[0x8];
    strcpy_165ED0(sp, arg0 + 0xC);
    func_0025A184_165ED0(sp, arg1);
}
//@@ func_00165ED0 m2c3
#include "m2c_macros.h"
M2C_UNK func_0025A184_165ED0() __asm__("func_0025A184");
M2C_UNK strcpy_165ED0() __asm__("strcpy");

void func_00165ED0(s32 arg0, s32 arg1) {
    u8 sp[0x4];
    strcpy_165ED0(sp, arg0 + 0xC);
    func_0025A184_165ED0(sp, arg1);
}
//@@ func_00165F08 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163E00_165F08() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165F08() __asm__("func_00163EB8");
s32 func_0025AA6C_165F08() __asm__("func_0025AA6C");
M2C_UNK func_0025BD88_165F08() __asm__("func_0025BD88");
M2C_UNK strcpy_165F08() __asm__("strcpy");
extern M2C_UNK func_00162A00_165F08 __asm__("func_00162A00");

s32 func_00165F08(s32* arg0, s32 arg1) {
    u8 sp[0x70];
    M2C_UNK sp15;
    s32 sp28;
    M2C_UNK sp2C;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165F08(temp_s0, 0x5A, sp);
    strcpy_165F08(&sp15, temp_s0);
    sp28 = 0;
    strcpy_165F08(&sp2C, arg1);
    *arg0 = 0;
    temp_v0 = func_0025AA6C_165F08(sp, &func_00162A00_165F08);
    if (temp_v0 != 0) {
        func_00163EB8_165F08(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165F08(arg0, 0xC350);
    return 0;
}
//@@ func_00165F08 m2c1
#include "m2c_macros.h"
M2C_UNK func_00163E00_165F08() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165F08() __asm__("func_00163EB8");
s32 func_0025AA6C_165F08() __asm__("func_0025AA6C");
M2C_UNK func_0025BD88_165F08() __asm__("func_0025BD88");
M2C_UNK strcpy_165F08() __asm__("strcpy");
extern M2C_UNK func_00162A00_165F08 __asm__("func_00162A00");

s32 func_00165F08(s32* arg0, s32 arg1) {
    u8 sp[0x60];
    M2C_UNK sp15;
    s32 sp28;
    M2C_UNK sp2C;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165F08(temp_s0, 0x5A, sp);
    strcpy_165F08(&sp15, temp_s0);
    sp28 = 0;
    strcpy_165F08(&sp2C, arg1);
    *arg0 = 0;
    temp_v0 = func_0025AA6C_165F08(sp, &func_00162A00_165F08);
    if (temp_v0 != 0) {
        func_00163EB8_165F08(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165F08(arg0, 0xC350);
    return 0;
}
//@@ func_00165F08 m2c2
#include "m2c_macros.h"
M2C_UNK func_00163E00_165F08() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165F08() __asm__("func_00163EB8");
s32 func_0025AA6C_165F08() __asm__("func_0025AA6C");
M2C_UNK func_0025BD88_165F08() __asm__("func_0025BD88");
M2C_UNK strcpy_165F08() __asm__("strcpy");
extern M2C_UNK func_00162A00_165F08 __asm__("func_00162A00");

s32 func_00165F08(s32* arg0, s32 arg1) {
    u8 sp[0x50];
    M2C_UNK sp15;
    s32 sp28;
    M2C_UNK sp2C;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165F08(temp_s0, 0x5A, sp);
    strcpy_165F08(&sp15, temp_s0);
    sp28 = 0;
    strcpy_165F08(&sp2C, arg1);
    *arg0 = 0;
    temp_v0 = func_0025AA6C_165F08(sp, &func_00162A00_165F08);
    if (temp_v0 != 0) {
        func_00163EB8_165F08(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165F08(arg0, 0xC350);
    return 0;
}
//@@ func_00165F08 m2c3
#include "m2c_macros.h"
M2C_UNK func_00163E00_165F08() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165F08() __asm__("func_00163EB8");
s32 func_0025AA6C_165F08() __asm__("func_0025AA6C");
M2C_UNK func_0025BD88_165F08() __asm__("func_0025BD88");
M2C_UNK strcpy_165F08() __asm__("strcpy");
extern M2C_UNK func_00162A00_165F08 __asm__("func_00162A00");

s32 func_00165F08(s32* arg0, s32 arg1) {
    u8 sp[0x40];
    M2C_UNK sp15;
    s32 sp28;
    M2C_UNK sp2C;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165F08(temp_s0, 0x5A, sp);
    strcpy_165F08(&sp15, temp_s0);
    sp28 = 0;
    strcpy_165F08(&sp2C, arg1);
    *arg0 = 0;
    temp_v0 = func_0025AA6C_165F08(sp, &func_00162A00_165F08);
    if (temp_v0 != 0) {
        func_00163EB8_165F08(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165F08(arg0, 0xC350);
    return 0;
}
//@@ func_00165F08 m2c4
#include "m2c_macros.h"
M2C_UNK func_00163E00_165F08() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165F08() __asm__("func_00163EB8");
s32 func_0025AA6C_165F08() __asm__("func_0025AA6C");
M2C_UNK func_0025BD88_165F08() __asm__("func_0025BD88");
M2C_UNK strcpy_165F08() __asm__("strcpy");
extern M2C_UNK func_00162A00_165F08 __asm__("func_00162A00");

s32 func_00165F08(s32* arg0, s32 arg1) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 sp28;
    M2C_UNK sp2C;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165F08(temp_s0, 0x5A, sp);
    strcpy_165F08(&sp15, temp_s0);
    sp28 = 0;
    strcpy_165F08(&sp2C, arg1);
    *arg0 = 0;
    temp_v0 = func_0025AA6C_165F08(sp, &func_00162A00_165F08);
    if (temp_v0 != 0) {
        func_00163EB8_165F08(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165F08(arg0, 0xC350);
    return 0;
}
//@@ func_00165F08 m2c5
#include "m2c_macros.h"
M2C_UNK func_00163E00_165F08() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165F08() __asm__("func_00163EB8");
s32 func_0025AA6C_165F08() __asm__("func_0025AA6C");
M2C_UNK func_0025BD88_165F08() __asm__("func_0025BD88");
M2C_UNK strcpy_165F08() __asm__("strcpy");
extern M2C_UNK func_00162A00_165F08 __asm__("func_00162A00");

s32 func_00165F08(s32* arg0, s32 arg1) {
    u8 sp[0x20];
    M2C_UNK sp15;
    s32 sp28;
    M2C_UNK sp2C;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_165F08(temp_s0, 0x5A, sp);
    strcpy_165F08(&sp15, temp_s0);
    sp28 = 0;
    strcpy_165F08(&sp2C, arg1);
    *arg0 = 0;
    temp_v0 = func_0025AA6C_165F08(sp, &func_00162A00_165F08);
    if (temp_v0 != 0) {
        func_00163EB8_165F08(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165F08(arg0, 0xC350);
    return 0;
}
//@@ func_00165FB0 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163E00_165FB0() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165FB0() __asm__("func_00163EB8");
s32 func_0025B80C_165FB0() __asm__("func_0025B80C");
M2C_UNK func_0025BD88_165FB0() __asm__("func_0025BD88");
M2C_UNK strcpy_165FB0() __asm__("strcpy");
extern s32 D_002C1694_165FB0 __asm__("D_002C1694");
extern M2C_UNK func_00162A38_165FB0 __asm__("func_00162A38");

s32 func_00165FB0(void* arg0) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x1E64) = (s32) (arg0 + 0x64);
    func_0025BD88_165FB0(temp_s0, 0x24, sp);
    strcpy_165FB0(&sp15, temp_s0);
    M2C_FIELD(arg0, s32* , 0) = 0;
    sp28 = 0;
    temp_v0 = func_0025B80C_165FB0(sp, &func_00162A38_165FB0);
    if (temp_v0 != 0) {
        func_00163EB8_165FB0(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165FB0(arg0, 0xC350);
    return (D_002C1694_165FB0 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165FB0 m2c1
#include "m2c_macros.h"
M2C_UNK func_00163E00_165FB0() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165FB0() __asm__("func_00163EB8");
s32 func_0025B80C_165FB0() __asm__("func_0025B80C");
M2C_UNK func_0025BD88_165FB0() __asm__("func_0025BD88");
M2C_UNK strcpy_165FB0() __asm__("strcpy");
extern s32 D_002C1694_165FB0 __asm__("D_002C1694");
extern M2C_UNK func_00162A38_165FB0 __asm__("func_00162A38");

s32 func_00165FB0(void* arg0) {
    u8 sp[0x20];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x1E64) = (s32) (arg0 + 0x64);
    func_0025BD88_165FB0(temp_s0, 0x24, sp);
    strcpy_165FB0(&sp15, temp_s0);
    M2C_FIELD(arg0, s32* , 0) = 0;
    sp28 = 0;
    temp_v0 = func_0025B80C_165FB0(sp, &func_00162A38_165FB0);
    if (temp_v0 != 0) {
        func_00163EB8_165FB0(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165FB0(arg0, 0xC350);
    return (D_002C1694_165FB0 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165FB0 m2c2
#include "m2c_macros.h"
M2C_UNK func_00163E00_165FB0() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165FB0() __asm__("func_00163EB8");
s32 func_0025B80C_165FB0() __asm__("func_0025B80C");
M2C_UNK func_0025BD88_165FB0() __asm__("func_0025BD88");
M2C_UNK strcpy_165FB0() __asm__("strcpy");
extern s32 D_002C1694_165FB0 __asm__("D_002C1694");
extern M2C_UNK func_00162A38_165FB0 __asm__("func_00162A38");

s32 func_00165FB0(void* arg0) {
    u8 sp[0x10];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x1E64) = (s32) (arg0 + 0x64);
    func_0025BD88_165FB0(temp_s0, 0x24, sp);
    strcpy_165FB0(&sp15, temp_s0);
    M2C_FIELD(arg0, s32* , 0) = 0;
    sp28 = 0;
    temp_v0 = func_0025B80C_165FB0(sp, &func_00162A38_165FB0);
    if (temp_v0 != 0) {
        func_00163EB8_165FB0(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165FB0(arg0, 0xC350);
    return (D_002C1694_165FB0 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165FB0 m2c3
#include "m2c_macros.h"
M2C_UNK func_00163E00_165FB0() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165FB0() __asm__("func_00163EB8");
s32 func_0025B80C_165FB0() __asm__("func_0025B80C");
M2C_UNK func_0025BD88_165FB0() __asm__("func_0025BD88");
M2C_UNK strcpy_165FB0() __asm__("strcpy");
extern s32 D_002C1694_165FB0 __asm__("D_002C1694");
extern M2C_UNK func_00162A38_165FB0 __asm__("func_00162A38");

s32 func_00165FB0(void* arg0) {
    u8 sp[0x8];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x1E64) = (s32) (arg0 + 0x64);
    func_0025BD88_165FB0(temp_s0, 0x24, sp);
    strcpy_165FB0(&sp15, temp_s0);
    M2C_FIELD(arg0, s32* , 0) = 0;
    sp28 = 0;
    temp_v0 = func_0025B80C_165FB0(sp, &func_00162A38_165FB0);
    if (temp_v0 != 0) {
        func_00163EB8_165FB0(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165FB0(arg0, 0xC350);
    return (D_002C1694_165FB0 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165FB0 m2c4
#include "m2c_macros.h"
M2C_UNK func_00163E00_165FB0() __asm__("func_00163E00");
M2C_UNK func_00163EB8_165FB0() __asm__("func_00163EB8");
s32 func_0025B80C_165FB0() __asm__("func_0025B80C");
M2C_UNK func_0025BD88_165FB0() __asm__("func_0025BD88");
M2C_UNK strcpy_165FB0() __asm__("strcpy");
extern s32 D_002C1694_165FB0 __asm__("D_002C1694");
extern M2C_UNK func_00162A38_165FB0 __asm__("func_00162A38");

s32 func_00165FB0(void* arg0) {
    u8 sp[0x4];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x1E64) = (s32) (arg0 + 0x64);
    func_0025BD88_165FB0(temp_s0, 0x24, sp);
    strcpy_165FB0(&sp15, temp_s0);
    M2C_FIELD(arg0, s32* , 0) = 0;
    sp28 = 0;
    temp_v0 = func_0025B80C_165FB0(sp, &func_00162A38_165FB0);
    if (temp_v0 != 0) {
        func_00163EB8_165FB0(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_165FB0(arg0, 0xC350);
    return (D_002C1694_165FB0 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166060 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163E00_166060() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166060() __asm__("func_00163EB8");
s32 func_0025BA68_166060() __asm__("func_0025BA68");
M2C_UNK func_0025BD88_166060() __asm__("func_0025BD88");
M2C_UNK strcpy_166060() __asm__("strcpy");
extern s32 D_002C1694_166060 __asm__("D_002C1694");
extern M2C_UNK func_00162AB0_166060 __asm__("func_00162AB0");

s32 func_00166060(void* arg0) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x1E68) = 0;
    func_0025BD88_166060(temp_s0, 0x18, sp);
    strcpy_166060(&sp15, temp_s0);
    M2C_FIELD(arg0, s32* , 0) = 0;
    sp28 = 0x272F;
    temp_v0 = func_0025BA68_166060(sp, &func_00162AB0_166060);
    if (temp_v0 != 0) {
        func_00163EB8_166060(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_166060(arg0, 0xC350);
    return (D_002C1694_166060 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166060 m2c1
#include "m2c_macros.h"
M2C_UNK func_00163E00_166060() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166060() __asm__("func_00163EB8");
s32 func_0025BA68_166060() __asm__("func_0025BA68");
M2C_UNK func_0025BD88_166060() __asm__("func_0025BD88");
M2C_UNK strcpy_166060() __asm__("strcpy");
extern s32 D_002C1694_166060 __asm__("D_002C1694");
extern M2C_UNK func_00162AB0_166060 __asm__("func_00162AB0");

s32 func_00166060(void* arg0) {
    u8 sp[0x20];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x1E68) = 0;
    func_0025BD88_166060(temp_s0, 0x18, sp);
    strcpy_166060(&sp15, temp_s0);
    M2C_FIELD(arg0, s32* , 0) = 0;
    sp28 = 0x272F;
    temp_v0 = func_0025BA68_166060(sp, &func_00162AB0_166060);
    if (temp_v0 != 0) {
        func_00163EB8_166060(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_166060(arg0, 0xC350);
    return (D_002C1694_166060 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166060 m2c2
#include "m2c_macros.h"
M2C_UNK func_00163E00_166060() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166060() __asm__("func_00163EB8");
s32 func_0025BA68_166060() __asm__("func_0025BA68");
M2C_UNK func_0025BD88_166060() __asm__("func_0025BD88");
M2C_UNK strcpy_166060() __asm__("strcpy");
extern s32 D_002C1694_166060 __asm__("D_002C1694");
extern M2C_UNK func_00162AB0_166060 __asm__("func_00162AB0");

s32 func_00166060(void* arg0) {
    u8 sp[0x10];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x1E68) = 0;
    func_0025BD88_166060(temp_s0, 0x18, sp);
    strcpy_166060(&sp15, temp_s0);
    M2C_FIELD(arg0, s32* , 0) = 0;
    sp28 = 0x272F;
    temp_v0 = func_0025BA68_166060(sp, &func_00162AB0_166060);
    if (temp_v0 != 0) {
        func_00163EB8_166060(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_166060(arg0, 0xC350);
    return (D_002C1694_166060 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166060 m2c3
#include "m2c_macros.h"
M2C_UNK func_00163E00_166060() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166060() __asm__("func_00163EB8");
s32 func_0025BA68_166060() __asm__("func_0025BA68");
M2C_UNK func_0025BD88_166060() __asm__("func_0025BD88");
M2C_UNK strcpy_166060() __asm__("strcpy");
extern s32 D_002C1694_166060 __asm__("D_002C1694");
extern M2C_UNK func_00162AB0_166060 __asm__("func_00162AB0");

s32 func_00166060(void* arg0) {
    u8 sp[0x8];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x1E68) = 0;
    func_0025BD88_166060(temp_s0, 0x18, sp);
    strcpy_166060(&sp15, temp_s0);
    M2C_FIELD(arg0, s32* , 0) = 0;
    sp28 = 0x272F;
    temp_v0 = func_0025BA68_166060(sp, &func_00162AB0_166060);
    if (temp_v0 != 0) {
        func_00163EB8_166060(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_166060(arg0, 0xC350);
    return (D_002C1694_166060 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166060 m2c4
#include "m2c_macros.h"
M2C_UNK func_00163E00_166060() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166060() __asm__("func_00163EB8");
s32 func_0025BA68_166060() __asm__("func_0025BA68");
M2C_UNK func_0025BD88_166060() __asm__("func_0025BD88");
M2C_UNK strcpy_166060() __asm__("strcpy");
extern s32 D_002C1694_166060 __asm__("D_002C1694");
extern M2C_UNK func_00162AB0_166060 __asm__("func_00162AB0");

s32 func_00166060(void* arg0) {
    u8 sp[0x4];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x1E68) = 0;
    func_0025BD88_166060(temp_s0, 0x18, sp);
    strcpy_166060(&sp15, temp_s0);
    M2C_FIELD(arg0, s32* , 0) = 0;
    sp28 = 0x272F;
    temp_v0 = func_0025BA68_166060(sp, &func_00162AB0_166060);
    if (temp_v0 != 0) {
        func_00163EB8_166060(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_166060(arg0, 0xC350);
    return (D_002C1694_166060 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166110 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163E00_166110() __asm__("func_00163E00");
M2C_UNK func_0025BD88_166110() __asm__("func_0025BD88");
s32 func_0025C93C_166110() __asm__("func_0025C93C");
M2C_UNK strcpy_166110() __asm__("strcpy");
extern M2C_UNK func_00163200_166110 __asm__("func_00163200");

s32 func_00166110(s32* arg0) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166110(temp_s0, 0x61, sp);
    strcpy_166110(&sp15, temp_s0);
    *arg0 = 0;
    sp28 = 0x272F;
    temp_v0 = func_0025C93C_166110(sp, &func_00163200_166110);
    if (temp_v0 == 0) {
        func_00163E00_166110(arg0, 0xC350);
    }
    return temp_v0;
}
//@@ func_00166110 m2c1
#include "m2c_macros.h"
M2C_UNK func_00163E00_166110() __asm__("func_00163E00");
M2C_UNK func_0025BD88_166110() __asm__("func_0025BD88");
s32 func_0025C93C_166110() __asm__("func_0025C93C");
M2C_UNK strcpy_166110() __asm__("strcpy");
extern M2C_UNK func_00163200_166110 __asm__("func_00163200");

s32 func_00166110(s32* arg0) {
    u8 sp[0x20];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166110(temp_s0, 0x61, sp);
    strcpy_166110(&sp15, temp_s0);
    *arg0 = 0;
    sp28 = 0x272F;
    temp_v0 = func_0025C93C_166110(sp, &func_00163200_166110);
    if (temp_v0 == 0) {
        func_00163E00_166110(arg0, 0xC350);
    }
    return temp_v0;
}
//@@ func_00166110 m2c2
#include "m2c_macros.h"
M2C_UNK func_00163E00_166110() __asm__("func_00163E00");
M2C_UNK func_0025BD88_166110() __asm__("func_0025BD88");
s32 func_0025C93C_166110() __asm__("func_0025C93C");
M2C_UNK strcpy_166110() __asm__("strcpy");
extern M2C_UNK func_00163200_166110 __asm__("func_00163200");

s32 func_00166110(s32* arg0) {
    u8 sp[0x10];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166110(temp_s0, 0x61, sp);
    strcpy_166110(&sp15, temp_s0);
    *arg0 = 0;
    sp28 = 0x272F;
    temp_v0 = func_0025C93C_166110(sp, &func_00163200_166110);
    if (temp_v0 == 0) {
        func_00163E00_166110(arg0, 0xC350);
    }
    return temp_v0;
}
//@@ func_00166110 m2c3
#include "m2c_macros.h"
M2C_UNK func_00163E00_166110() __asm__("func_00163E00");
M2C_UNK func_0025BD88_166110() __asm__("func_0025BD88");
s32 func_0025C93C_166110() __asm__("func_0025C93C");
M2C_UNK strcpy_166110() __asm__("strcpy");
extern M2C_UNK func_00163200_166110 __asm__("func_00163200");

s32 func_00166110(s32* arg0) {
    u8 sp[0x8];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166110(temp_s0, 0x61, sp);
    strcpy_166110(&sp15, temp_s0);
    *arg0 = 0;
    sp28 = 0x272F;
    temp_v0 = func_0025C93C_166110(sp, &func_00163200_166110);
    if (temp_v0 == 0) {
        func_00163E00_166110(arg0, 0xC350);
    }
    return temp_v0;
}
//@@ func_00166110 m2c4
#include "m2c_macros.h"
M2C_UNK func_00163E00_166110() __asm__("func_00163E00");
M2C_UNK func_0025BD88_166110() __asm__("func_0025BD88");
s32 func_0025C93C_166110() __asm__("func_0025C93C");
M2C_UNK strcpy_166110() __asm__("strcpy");
extern M2C_UNK func_00163200_166110 __asm__("func_00163200");

s32 func_00166110(s32* arg0) {
    u8 sp[0x4];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166110(temp_s0, 0x61, sp);
    strcpy_166110(&sp15, temp_s0);
    *arg0 = 0;
    sp28 = 0x272F;
    temp_v0 = func_0025C93C_166110(sp, &func_00163200_166110);
    if (temp_v0 == 0) {
        func_00163E00_166110(arg0, 0xC350);
    }
    return temp_v0;
}
//@@ func_00166190 m2c0
#include "m2c_macros.h"
M2C_UNK func_0025AEB0_166190() __asm__("func_0025AEB0");
M2C_UNK func_0025BD88_166190() __asm__("func_0025BD88");
M2C_UNK func_00266D78_166190() __asm__("func_00266D78");
M2C_UNK printf_166190() __asm__("printf");
M2C_UNK strcpy_166190() __asm__("strcpy");
extern M2C_UNK D_00313EE0_166190 __asm__("D_00313EE0");
extern s32 D_004F9C58_166190 __asm__("D_004F9C58");
extern s32 D_004F9C5C_166190 __asm__("D_004F9C5C");
extern s32 D_004F9C60_166190 __asm__("D_004F9C60");
extern s32 D_004F9C64_166190 __asm__("D_004F9C64");
extern s32 D_004F9C68_166190 __asm__("D_004F9C68");
extern s32 D_004F9C6C_166190 __asm__("D_004F9C6C");
extern s32 D_004F9C84_166190 __asm__("D_004F9C84");
extern M2C_UNK func_00163278_166190 __asm__("func_00163278");

void func_00166190(void* arg0, s16 arg1) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 sp28;
    s16 sp2C;
    s16 sp2E;
    void* temp_s1;

    printf_166190("Get Available Games - Page:%d PageSize:%d ListSize:%d\n\0BASCUS-97196\0\0\0 !\"#$%&'()*+,-.0123456789:;<=>?ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_abcdefghijklmnopqrstuvwxyz{}\0\00123456789\0\0 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\0 .0123456789", 0x28, 0x200);
    temp_s1 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x406A4) = 0;
    M2C_FIELD(arg0, s32* , 0x406A8) = 0;
    D_004F9C58_166190 = 0;
    D_004F9C6C_166190 = 0;
    D_004F9C68_166190 = 0;
    D_004F9C64_166190 = 0;
    D_004F9C60_166190 = 0;
    D_004F9C5C_166190 = 0;
    D_004F9C84_166190 = 0;
    func_0025BD88_166190(temp_s1, 0x20, sp);
    strcpy_166190(&D_00313EE0_166190, sp);
    strcpy_166190(&sp15, temp_s1);
    sp2C = arg1;
    sp28 = 0x272F;
    sp2E = 0x28;
    func_00266D78_166190(arg0 + 0x406A0);
    func_0025AEB0_166190(sp, &func_00163278_166190);
}
//@@ func_00166190 m2c1
#include "m2c_macros.h"
M2C_UNK func_0025AEB0_166190() __asm__("func_0025AEB0");
M2C_UNK func_0025BD88_166190() __asm__("func_0025BD88");
M2C_UNK func_00266D78_166190() __asm__("func_00266D78");
M2C_UNK printf_166190() __asm__("printf");
M2C_UNK strcpy_166190() __asm__("strcpy");
extern M2C_UNK D_00313EE0_166190 __asm__("D_00313EE0");
extern s32 D_004F9C58_166190 __asm__("D_004F9C58");
extern s32 D_004F9C5C_166190 __asm__("D_004F9C5C");
extern s32 D_004F9C60_166190 __asm__("D_004F9C60");
extern s32 D_004F9C64_166190 __asm__("D_004F9C64");
extern s32 D_004F9C68_166190 __asm__("D_004F9C68");
extern s32 D_004F9C6C_166190 __asm__("D_004F9C6C");
extern s32 D_004F9C84_166190 __asm__("D_004F9C84");
extern M2C_UNK func_00163278_166190 __asm__("func_00163278");

void func_00166190(void* arg0, s16 arg1) {
    u8 sp[0x20];
    M2C_UNK sp15;
    s32 sp28;
    s16 sp2C;
    s16 sp2E;
    void* temp_s1;

    printf_166190("Get Available Games - Page:%d PageSize:%d ListSize:%d\n\0BASCUS-97196\0\0\0 !\"#$%&'()*+,-.0123456789:;<=>?ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_abcdefghijklmnopqrstuvwxyz{}\0\00123456789\0\0 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\0 .0123456789", 0x28, 0x200);
    temp_s1 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x406A4) = 0;
    M2C_FIELD(arg0, s32* , 0x406A8) = 0;
    D_004F9C58_166190 = 0;
    D_004F9C6C_166190 = 0;
    D_004F9C68_166190 = 0;
    D_004F9C64_166190 = 0;
    D_004F9C60_166190 = 0;
    D_004F9C5C_166190 = 0;
    D_004F9C84_166190 = 0;
    func_0025BD88_166190(temp_s1, 0x20, sp);
    strcpy_166190(&D_00313EE0_166190, sp);
    strcpy_166190(&sp15, temp_s1);
    sp2C = arg1;
    sp28 = 0x272F;
    sp2E = 0x28;
    func_00266D78_166190(arg0 + 0x406A0);
    func_0025AEB0_166190(sp, &func_00163278_166190);
}
//@@ func_00166190 m2c2
#include "m2c_macros.h"
M2C_UNK func_0025AEB0_166190() __asm__("func_0025AEB0");
M2C_UNK func_0025BD88_166190() __asm__("func_0025BD88");
M2C_UNK func_00266D78_166190() __asm__("func_00266D78");
M2C_UNK printf_166190() __asm__("printf");
M2C_UNK strcpy_166190() __asm__("strcpy");
extern M2C_UNK D_00313EE0_166190 __asm__("D_00313EE0");
extern s32 D_004F9C58_166190 __asm__("D_004F9C58");
extern s32 D_004F9C5C_166190 __asm__("D_004F9C5C");
extern s32 D_004F9C60_166190 __asm__("D_004F9C60");
extern s32 D_004F9C64_166190 __asm__("D_004F9C64");
extern s32 D_004F9C68_166190 __asm__("D_004F9C68");
extern s32 D_004F9C6C_166190 __asm__("D_004F9C6C");
extern s32 D_004F9C84_166190 __asm__("D_004F9C84");
extern M2C_UNK func_00163278_166190 __asm__("func_00163278");

void func_00166190(void* arg0, s16 arg1) {
    u8 sp[0x10];
    M2C_UNK sp15;
    s32 sp28;
    s16 sp2C;
    s16 sp2E;
    void* temp_s1;

    printf_166190("Get Available Games - Page:%d PageSize:%d ListSize:%d\n\0BASCUS-97196\0\0\0 !\"#$%&'()*+,-.0123456789:;<=>?ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_abcdefghijklmnopqrstuvwxyz{}\0\00123456789\0\0 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\0 .0123456789", 0x28, 0x200);
    temp_s1 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x406A4) = 0;
    M2C_FIELD(arg0, s32* , 0x406A8) = 0;
    D_004F9C58_166190 = 0;
    D_004F9C6C_166190 = 0;
    D_004F9C68_166190 = 0;
    D_004F9C64_166190 = 0;
    D_004F9C60_166190 = 0;
    D_004F9C5C_166190 = 0;
    D_004F9C84_166190 = 0;
    func_0025BD88_166190(temp_s1, 0x20, sp);
    strcpy_166190(&D_00313EE0_166190, sp);
    strcpy_166190(&sp15, temp_s1);
    sp2C = arg1;
    sp28 = 0x272F;
    sp2E = 0x28;
    func_00266D78_166190(arg0 + 0x406A0);
    func_0025AEB0_166190(sp, &func_00163278_166190);
}
//@@ func_00166190 m2c3
#include "m2c_macros.h"
M2C_UNK func_0025AEB0_166190() __asm__("func_0025AEB0");
M2C_UNK func_0025BD88_166190() __asm__("func_0025BD88");
M2C_UNK func_00266D78_166190() __asm__("func_00266D78");
M2C_UNK printf_166190() __asm__("printf");
M2C_UNK strcpy_166190() __asm__("strcpy");
extern M2C_UNK D_00313EE0_166190 __asm__("D_00313EE0");
extern s32 D_004F9C58_166190 __asm__("D_004F9C58");
extern s32 D_004F9C5C_166190 __asm__("D_004F9C5C");
extern s32 D_004F9C60_166190 __asm__("D_004F9C60");
extern s32 D_004F9C64_166190 __asm__("D_004F9C64");
extern s32 D_004F9C68_166190 __asm__("D_004F9C68");
extern s32 D_004F9C6C_166190 __asm__("D_004F9C6C");
extern s32 D_004F9C84_166190 __asm__("D_004F9C84");
extern M2C_UNK func_00163278_166190 __asm__("func_00163278");

void func_00166190(void* arg0, s16 arg1) {
    u8 sp[0x8];
    M2C_UNK sp15;
    s32 sp28;
    s16 sp2C;
    s16 sp2E;
    void* temp_s1;

    printf_166190("Get Available Games - Page:%d PageSize:%d ListSize:%d\n\0BASCUS-97196\0\0\0 !\"#$%&'()*+,-.0123456789:;<=>?ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_abcdefghijklmnopqrstuvwxyz{}\0\00123456789\0\0 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\0 .0123456789", 0x28, 0x200);
    temp_s1 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x406A4) = 0;
    M2C_FIELD(arg0, s32* , 0x406A8) = 0;
    D_004F9C58_166190 = 0;
    D_004F9C6C_166190 = 0;
    D_004F9C68_166190 = 0;
    D_004F9C64_166190 = 0;
    D_004F9C60_166190 = 0;
    D_004F9C5C_166190 = 0;
    D_004F9C84_166190 = 0;
    func_0025BD88_166190(temp_s1, 0x20, sp);
    strcpy_166190(&D_00313EE0_166190, sp);
    strcpy_166190(&sp15, temp_s1);
    sp2C = arg1;
    sp28 = 0x272F;
    sp2E = 0x28;
    func_00266D78_166190(arg0 + 0x406A0);
    func_0025AEB0_166190(sp, &func_00163278_166190);
}
//@@ func_00166190 m2c4
#include "m2c_macros.h"
M2C_UNK func_0025AEB0_166190() __asm__("func_0025AEB0");
M2C_UNK func_0025BD88_166190() __asm__("func_0025BD88");
M2C_UNK func_00266D78_166190() __asm__("func_00266D78");
M2C_UNK printf_166190() __asm__("printf");
M2C_UNK strcpy_166190() __asm__("strcpy");
extern M2C_UNK D_00313EE0_166190 __asm__("D_00313EE0");
extern s32 D_004F9C58_166190 __asm__("D_004F9C58");
extern s32 D_004F9C5C_166190 __asm__("D_004F9C5C");
extern s32 D_004F9C60_166190 __asm__("D_004F9C60");
extern s32 D_004F9C64_166190 __asm__("D_004F9C64");
extern s32 D_004F9C68_166190 __asm__("D_004F9C68");
extern s32 D_004F9C6C_166190 __asm__("D_004F9C6C");
extern s32 D_004F9C84_166190 __asm__("D_004F9C84");
extern M2C_UNK func_00163278_166190 __asm__("func_00163278");

void func_00166190(void* arg0, s16 arg1) {
    u8 sp[0x4];
    M2C_UNK sp15;
    s32 sp28;
    s16 sp2C;
    s16 sp2E;
    void* temp_s1;

    printf_166190("Get Available Games - Page:%d PageSize:%d ListSize:%d\n\0BASCUS-97196\0\0\0 !\"#$%&'()*+,-.0123456789:;<=>?ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_abcdefghijklmnopqrstuvwxyz{}\0\00123456789\0\0 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\0 .0123456789", 0x28, 0x200);
    temp_s1 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x406A4) = 0;
    M2C_FIELD(arg0, s32* , 0x406A8) = 0;
    D_004F9C58_166190 = 0;
    D_004F9C6C_166190 = 0;
    D_004F9C68_166190 = 0;
    D_004F9C64_166190 = 0;
    D_004F9C60_166190 = 0;
    D_004F9C5C_166190 = 0;
    D_004F9C84_166190 = 0;
    func_0025BD88_166190(temp_s1, 0x20, sp);
    strcpy_166190(&D_00313EE0_166190, sp);
    strcpy_166190(&sp15, temp_s1);
    sp2C = arg1;
    sp28 = 0x272F;
    sp2E = 0x28;
    func_00266D78_166190(arg0 + 0x406A0);
    func_0025AEB0_166190(sp, &func_00163278_166190);
}
//@@ func_00166280 m2c0
#include "m2c_macros.h"
M2C_UNK func_0025B1D0_166280() __asm__("func_0025B1D0");
M2C_UNK func_0025BD88_166280() __asm__("func_0025BD88");
M2C_UNK strcpy_166280() __asm__("strcpy");
extern M2C_UNK func_00163560_166280 __asm__("func_00163560");

void func_00166280(void* arg0, s32 arg1) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;

    temp_s0 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x51B0C) = arg1;
    M2C_FIELD(arg0, s32* , 0x51B10) = 0;
    M2C_FIELD(arg0, s32* , 0x51B14) = 0;
    func_0025BD88_166280(temp_s0, 0x1C, sp);
    strcpy_166280(&sp15, temp_s0);
    sp28 = M2C_FIELD(arg0, s32* , 0x51B0C);
    func_0025B1D0_166280(sp, &func_00163560_166280);
}
//@@ func_00166280 m2c1
#include "m2c_macros.h"
M2C_UNK func_0025B1D0_166280() __asm__("func_0025B1D0");
M2C_UNK func_0025BD88_166280() __asm__("func_0025BD88");
M2C_UNK strcpy_166280() __asm__("strcpy");
extern M2C_UNK func_00163560_166280 __asm__("func_00163560");

void func_00166280(void* arg0, s32 arg1) {
    u8 sp[0x20];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;

    temp_s0 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x51B0C) = arg1;
    M2C_FIELD(arg0, s32* , 0x51B10) = 0;
    M2C_FIELD(arg0, s32* , 0x51B14) = 0;
    func_0025BD88_166280(temp_s0, 0x1C, sp);
    strcpy_166280(&sp15, temp_s0);
    sp28 = M2C_FIELD(arg0, s32* , 0x51B0C);
    func_0025B1D0_166280(sp, &func_00163560_166280);
}
//@@ func_00166280 m2c2
#include "m2c_macros.h"
M2C_UNK func_0025B1D0_166280() __asm__("func_0025B1D0");
M2C_UNK func_0025BD88_166280() __asm__("func_0025BD88");
M2C_UNK strcpy_166280() __asm__("strcpy");
extern M2C_UNK func_00163560_166280 __asm__("func_00163560");

void func_00166280(void* arg0, s32 arg1) {
    u8 sp[0x10];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;

    temp_s0 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x51B0C) = arg1;
    M2C_FIELD(arg0, s32* , 0x51B10) = 0;
    M2C_FIELD(arg0, s32* , 0x51B14) = 0;
    func_0025BD88_166280(temp_s0, 0x1C, sp);
    strcpy_166280(&sp15, temp_s0);
    sp28 = M2C_FIELD(arg0, s32* , 0x51B0C);
    func_0025B1D0_166280(sp, &func_00163560_166280);
}
//@@ func_00166280 m2c3
#include "m2c_macros.h"
M2C_UNK func_0025B1D0_166280() __asm__("func_0025B1D0");
M2C_UNK func_0025BD88_166280() __asm__("func_0025BD88");
M2C_UNK strcpy_166280() __asm__("strcpy");
extern M2C_UNK func_00163560_166280 __asm__("func_00163560");

void func_00166280(void* arg0, s32 arg1) {
    u8 sp[0x8];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;

    temp_s0 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x51B0C) = arg1;
    M2C_FIELD(arg0, s32* , 0x51B10) = 0;
    M2C_FIELD(arg0, s32* , 0x51B14) = 0;
    func_0025BD88_166280(temp_s0, 0x1C, sp);
    strcpy_166280(&sp15, temp_s0);
    sp28 = M2C_FIELD(arg0, s32* , 0x51B0C);
    func_0025B1D0_166280(sp, &func_00163560_166280);
}
//@@ func_00166280 m2c4
#include "m2c_macros.h"
M2C_UNK func_0025B1D0_166280() __asm__("func_0025B1D0");
M2C_UNK func_0025BD88_166280() __asm__("func_0025BD88");
M2C_UNK strcpy_166280() __asm__("strcpy");
extern M2C_UNK func_00163560_166280 __asm__("func_00163560");

void func_00166280(void* arg0, s32 arg1) {
    u8 sp[0x4];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;

    temp_s0 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x51B0C) = arg1;
    M2C_FIELD(arg0, s32* , 0x51B10) = 0;
    M2C_FIELD(arg0, s32* , 0x51B14) = 0;
    func_0025BD88_166280(temp_s0, 0x1C, sp);
    strcpy_166280(&sp15, temp_s0);
    sp28 = M2C_FIELD(arg0, s32* , 0x51B0C);
    func_0025B1D0_166280(sp, &func_00163560_166280);
}
//@@ func_001662F8 m2c0
#include "m2c_macros.h"
M2C_UNK func_0025B090_1662F8() __asm__("func_0025B090");
M2C_UNK func_0025BD88_1662F8() __asm__("func_0025BD88");
M2C_UNK strcpy_1662F8() __asm__("strcpy");
extern M2C_UNK func_00163658_1662F8 __asm__("func_00163658");

void func_001662F8(void* arg0, s32 arg1) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;

    temp_s0 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x51B14) = 0;
    M2C_FIELD(arg0, s32* , 0x51B10) = 0;
    func_0025BD88_1662F8(temp_s0, 0x1F, sp);
    strcpy_1662F8(&sp15, temp_s0);
    sp28 = arg1;
    func_0025B090_1662F8(sp, &func_00163658_1662F8);
}
//@@ func_001662F8 m2c1
#include "m2c_macros.h"
M2C_UNK func_0025B090_1662F8() __asm__("func_0025B090");
M2C_UNK func_0025BD88_1662F8() __asm__("func_0025BD88");
M2C_UNK strcpy_1662F8() __asm__("strcpy");
extern M2C_UNK func_00163658_1662F8 __asm__("func_00163658");

void func_001662F8(void* arg0, s32 arg1) {
    u8 sp[0x20];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;

    temp_s0 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x51B14) = 0;
    M2C_FIELD(arg0, s32* , 0x51B10) = 0;
    func_0025BD88_1662F8(temp_s0, 0x1F, sp);
    strcpy_1662F8(&sp15, temp_s0);
    sp28 = arg1;
    func_0025B090_1662F8(sp, &func_00163658_1662F8);
}
//@@ func_001662F8 m2c2
#include "m2c_macros.h"
M2C_UNK func_0025B090_1662F8() __asm__("func_0025B090");
M2C_UNK func_0025BD88_1662F8() __asm__("func_0025BD88");
M2C_UNK strcpy_1662F8() __asm__("strcpy");
extern M2C_UNK func_00163658_1662F8 __asm__("func_00163658");

void func_001662F8(void* arg0, s32 arg1) {
    u8 sp[0x10];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;

    temp_s0 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x51B14) = 0;
    M2C_FIELD(arg0, s32* , 0x51B10) = 0;
    func_0025BD88_1662F8(temp_s0, 0x1F, sp);
    strcpy_1662F8(&sp15, temp_s0);
    sp28 = arg1;
    func_0025B090_1662F8(sp, &func_00163658_1662F8);
}
//@@ func_001662F8 m2c3
#include "m2c_macros.h"
M2C_UNK func_0025B090_1662F8() __asm__("func_0025B090");
M2C_UNK func_0025BD88_1662F8() __asm__("func_0025BD88");
M2C_UNK strcpy_1662F8() __asm__("strcpy");
extern M2C_UNK func_00163658_1662F8 __asm__("func_00163658");

void func_001662F8(void* arg0, s32 arg1) {
    u8 sp[0x8];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;

    temp_s0 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x51B14) = 0;
    M2C_FIELD(arg0, s32* , 0x51B10) = 0;
    func_0025BD88_1662F8(temp_s0, 0x1F, sp);
    strcpy_1662F8(&sp15, temp_s0);
    sp28 = arg1;
    func_0025B090_1662F8(sp, &func_00163658_1662F8);
}
//@@ func_001662F8 m2c4
#include "m2c_macros.h"
M2C_UNK func_0025B090_1662F8() __asm__("func_0025B090");
M2C_UNK func_0025BD88_1662F8() __asm__("func_0025BD88");
M2C_UNK strcpy_1662F8() __asm__("strcpy");
extern M2C_UNK func_00163658_1662F8 __asm__("func_00163658");

void func_001662F8(void* arg0, s32 arg1) {
    u8 sp[0x4];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;

    temp_s0 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x51B14) = 0;
    M2C_FIELD(arg0, s32* , 0x51B10) = 0;
    func_0025BD88_1662F8(temp_s0, 0x1F, sp);
    strcpy_1662F8(&sp15, temp_s0);
    sp28 = arg1;
    func_0025B090_1662F8(sp, &func_00163658_1662F8);
}
//@@ func_00166368 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163E00_166368() __asm__("func_00163E00");
s32 func_0025A9B4_166368() __asm__("func_0025A9B4");
M2C_UNK func_0025BD88_166368() __asm__("func_0025BD88");
M2C_UNK strcpy_166368() __asm__("strcpy");
extern s32 D_002C1694_166368 __asm__("D_002C1694");
extern M2C_UNK func_00163708_166368 __asm__("func_00163708");

s32 func_00166368(void* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp[0xB0];
    M2C_UNK sp15;
    s32 sp28;
    s32 sp2C;
    s32 sp30;
    s32 sp34;
    M2C_UNK sp38;
    M2C_UNK sp78;
    s32 sp98;
    s32 sp9C;
    s32 spA0;
    s32 spA4;
    s32 spA8;
    s32 spAC;
    s32 temp_s0;
    s32 var_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166368(temp_s0, 0x10, sp);
    strcpy_166368(&sp15, temp_s0);
    sp28 = 0x272F;
    sp30 = 8;
    sp34 = arg3;
    sp2C = 1;
    strcpy_166368(&sp38, arg1);
    strcpy_166368(&sp78, arg2);
    M2C_FIELD(arg0, s32* , 0x52440) = 0;
    M2C_FIELD(arg0, s32* , 0) = 0;
    sp98 = 1;
    sp9C = -1;
    spAC = 0;
    spA0 = 0;
    spA4 = 0;
    spA8 = 0;
    var_v0 = func_0025A9B4_166368(sp, &func_00163708_166368);
    if (var_v0 == 0) {
        func_00163E00_166368(arg0, 0xC350);
        var_v0 = (D_002C1694_166368 >= 0) ? 0 : 0xFFFFFF;
    }
    return var_v0;
}
//@@ func_00166368 m2c1
#include "m2c_macros.h"
M2C_UNK func_00163E00_166368() __asm__("func_00163E00");
s32 func_0025A9B4_166368() __asm__("func_0025A9B4");
M2C_UNK func_0025BD88_166368() __asm__("func_0025BD88");
M2C_UNK strcpy_166368() __asm__("strcpy");
extern s32 D_002C1694_166368 __asm__("D_002C1694");
extern M2C_UNK func_00163708_166368 __asm__("func_00163708");

s32 func_00166368(void* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp[0xA0];
    M2C_UNK sp15;
    s32 sp28;
    s32 sp2C;
    s32 sp30;
    s32 sp34;
    M2C_UNK sp38;
    M2C_UNK sp78;
    s32 sp98;
    s32 sp9C;
    s32 spA0;
    s32 spA4;
    s32 spA8;
    s32 spAC;
    s32 temp_s0;
    s32 var_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166368(temp_s0, 0x10, sp);
    strcpy_166368(&sp15, temp_s0);
    sp28 = 0x272F;
    sp30 = 8;
    sp34 = arg3;
    sp2C = 1;
    strcpy_166368(&sp38, arg1);
    strcpy_166368(&sp78, arg2);
    M2C_FIELD(arg0, s32* , 0x52440) = 0;
    M2C_FIELD(arg0, s32* , 0) = 0;
    sp98 = 1;
    sp9C = -1;
    spAC = 0;
    spA0 = 0;
    spA4 = 0;
    spA8 = 0;
    var_v0 = func_0025A9B4_166368(sp, &func_00163708_166368);
    if (var_v0 == 0) {
        func_00163E00_166368(arg0, 0xC350);
        var_v0 = (D_002C1694_166368 >= 0) ? 0 : 0xFFFFFF;
    }
    return var_v0;
}
//@@ func_00166368 m2c2
#include "m2c_macros.h"
M2C_UNK func_00163E00_166368() __asm__("func_00163E00");
s32 func_0025A9B4_166368() __asm__("func_0025A9B4");
M2C_UNK func_0025BD88_166368() __asm__("func_0025BD88");
M2C_UNK strcpy_166368() __asm__("strcpy");
extern s32 D_002C1694_166368 __asm__("D_002C1694");
extern M2C_UNK func_00163708_166368 __asm__("func_00163708");

s32 func_00166368(void* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp[0x90];
    M2C_UNK sp15;
    s32 sp28;
    s32 sp2C;
    s32 sp30;
    s32 sp34;
    M2C_UNK sp38;
    M2C_UNK sp78;
    s32 sp98;
    s32 sp9C;
    s32 spA0;
    s32 spA4;
    s32 spA8;
    s32 spAC;
    s32 temp_s0;
    s32 var_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166368(temp_s0, 0x10, sp);
    strcpy_166368(&sp15, temp_s0);
    sp28 = 0x272F;
    sp30 = 8;
    sp34 = arg3;
    sp2C = 1;
    strcpy_166368(&sp38, arg1);
    strcpy_166368(&sp78, arg2);
    M2C_FIELD(arg0, s32* , 0x52440) = 0;
    M2C_FIELD(arg0, s32* , 0) = 0;
    sp98 = 1;
    sp9C = -1;
    spAC = 0;
    spA0 = 0;
    spA4 = 0;
    spA8 = 0;
    var_v0 = func_0025A9B4_166368(sp, &func_00163708_166368);
    if (var_v0 == 0) {
        func_00163E00_166368(arg0, 0xC350);
        var_v0 = (D_002C1694_166368 >= 0) ? 0 : 0xFFFFFF;
    }
    return var_v0;
}
//@@ func_00166368 m2c3
#include "m2c_macros.h"
M2C_UNK func_00163E00_166368() __asm__("func_00163E00");
s32 func_0025A9B4_166368() __asm__("func_0025A9B4");
M2C_UNK func_0025BD88_166368() __asm__("func_0025BD88");
M2C_UNK strcpy_166368() __asm__("strcpy");
extern s32 D_002C1694_166368 __asm__("D_002C1694");
extern M2C_UNK func_00163708_166368 __asm__("func_00163708");

s32 func_00166368(void* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp[0x80];
    M2C_UNK sp15;
    s32 sp28;
    s32 sp2C;
    s32 sp30;
    s32 sp34;
    M2C_UNK sp38;
    M2C_UNK sp78;
    s32 sp98;
    s32 sp9C;
    s32 spA0;
    s32 spA4;
    s32 spA8;
    s32 spAC;
    s32 temp_s0;
    s32 var_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166368(temp_s0, 0x10, sp);
    strcpy_166368(&sp15, temp_s0);
    sp28 = 0x272F;
    sp30 = 8;
    sp34 = arg3;
    sp2C = 1;
    strcpy_166368(&sp38, arg1);
    strcpy_166368(&sp78, arg2);
    M2C_FIELD(arg0, s32* , 0x52440) = 0;
    M2C_FIELD(arg0, s32* , 0) = 0;
    sp98 = 1;
    sp9C = -1;
    spAC = 0;
    spA0 = 0;
    spA4 = 0;
    spA8 = 0;
    var_v0 = func_0025A9B4_166368(sp, &func_00163708_166368);
    if (var_v0 == 0) {
        func_00163E00_166368(arg0, 0xC350);
        var_v0 = (D_002C1694_166368 >= 0) ? 0 : 0xFFFFFF;
    }
    return var_v0;
}
//@@ func_00166368 m2c4
#include "m2c_macros.h"
M2C_UNK func_00163E00_166368() __asm__("func_00163E00");
s32 func_0025A9B4_166368() __asm__("func_0025A9B4");
M2C_UNK func_0025BD88_166368() __asm__("func_0025BD88");
M2C_UNK strcpy_166368() __asm__("strcpy");
extern s32 D_002C1694_166368 __asm__("D_002C1694");
extern M2C_UNK func_00163708_166368 __asm__("func_00163708");

s32 func_00166368(void* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp[0x70];
    M2C_UNK sp15;
    s32 sp28;
    s32 sp2C;
    s32 sp30;
    s32 sp34;
    M2C_UNK sp38;
    M2C_UNK sp78;
    s32 sp98;
    s32 sp9C;
    s32 spA0;
    s32 spA4;
    s32 spA8;
    s32 spAC;
    s32 temp_s0;
    s32 var_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166368(temp_s0, 0x10, sp);
    strcpy_166368(&sp15, temp_s0);
    sp28 = 0x272F;
    sp30 = 8;
    sp34 = arg3;
    sp2C = 1;
    strcpy_166368(&sp38, arg1);
    strcpy_166368(&sp78, arg2);
    M2C_FIELD(arg0, s32* , 0x52440) = 0;
    M2C_FIELD(arg0, s32* , 0) = 0;
    sp98 = 1;
    sp9C = -1;
    spAC = 0;
    spA0 = 0;
    spA4 = 0;
    spA8 = 0;
    var_v0 = func_0025A9B4_166368(sp, &func_00163708_166368);
    if (var_v0 == 0) {
        func_00163E00_166368(arg0, 0xC350);
        var_v0 = (D_002C1694_166368 >= 0) ? 0 : 0xFFFFFF;
    }
    return var_v0;
}
//@@ func_00166368 m2c5
#include "m2c_macros.h"
M2C_UNK func_00163E00_166368() __asm__("func_00163E00");
s32 func_0025A9B4_166368() __asm__("func_0025A9B4");
M2C_UNK func_0025BD88_166368() __asm__("func_0025BD88");
M2C_UNK strcpy_166368() __asm__("strcpy");
extern s32 D_002C1694_166368 __asm__("D_002C1694");
extern M2C_UNK func_00163708_166368 __asm__("func_00163708");

s32 func_00166368(void* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp[0x60];
    M2C_UNK sp15;
    s32 sp28;
    s32 sp2C;
    s32 sp30;
    s32 sp34;
    M2C_UNK sp38;
    M2C_UNK sp78;
    s32 sp98;
    s32 sp9C;
    s32 spA0;
    s32 spA4;
    s32 spA8;
    s32 spAC;
    s32 temp_s0;
    s32 var_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166368(temp_s0, 0x10, sp);
    strcpy_166368(&sp15, temp_s0);
    sp28 = 0x272F;
    sp30 = 8;
    sp34 = arg3;
    sp2C = 1;
    strcpy_166368(&sp38, arg1);
    strcpy_166368(&sp78, arg2);
    M2C_FIELD(arg0, s32* , 0x52440) = 0;
    M2C_FIELD(arg0, s32* , 0) = 0;
    sp98 = 1;
    sp9C = -1;
    spAC = 0;
    spA0 = 0;
    spA4 = 0;
    spA8 = 0;
    var_v0 = func_0025A9B4_166368(sp, &func_00163708_166368);
    if (var_v0 == 0) {
        func_00163E00_166368(arg0, 0xC350);
        var_v0 = (D_002C1694_166368 >= 0) ? 0 : 0xFFFFFF;
    }
    return var_v0;
}
//@@ func_00166478 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163E00_166478() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166478() __asm__("func_00163EB8");
s32 func_0025B3BC_166478() __asm__("func_0025B3BC");
M2C_UNK func_0025BD88_166478() __asm__("func_0025BD88");
M2C_UNK strcpy_166478() __asm__("strcpy");
extern M2C_UNK D_002C1690_166478 __asm__("D_002C1690");
extern M2C_UNK func_00163778_166478 __asm__("func_00163778");

s32 func_00166478(s32* arg0, s32 arg1) {
    u8 sp[0x70];
    M2C_UNK sp15;
    M2C_UNK sp26;
    s32 sp68;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    strcpy_166478(arg0 + 0x1D);
    func_0025BD88_166478(temp_s0, 0x15, sp);
    strcpy_166478(&sp15, temp_s0);
    strcpy_166478(&sp26, arg1);
    sp68 = 2;
    func_00163EB8_166478(&D_002C1690_166478, 1);
    *arg0 = 0;
    temp_v0 = func_0025B3BC_166478(sp, &func_00163778_166478);
    if (temp_v0 == 0) {
        func_00163E00_166478(arg0, 0xC350);
    }
    return temp_v0;
}
//@@ func_00166478 m2c1
#include "m2c_macros.h"
M2C_UNK func_00163E00_166478() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166478() __asm__("func_00163EB8");
s32 func_0025B3BC_166478() __asm__("func_0025B3BC");
M2C_UNK func_0025BD88_166478() __asm__("func_0025BD88");
M2C_UNK strcpy_166478() __asm__("strcpy");
extern M2C_UNK D_002C1690_166478 __asm__("D_002C1690");
extern M2C_UNK func_00163778_166478 __asm__("func_00163778");

s32 func_00166478(s32* arg0, s32 arg1) {
    u8 sp[0x60];
    M2C_UNK sp15;
    M2C_UNK sp26;
    s32 sp68;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    strcpy_166478(arg0 + 0x1D);
    func_0025BD88_166478(temp_s0, 0x15, sp);
    strcpy_166478(&sp15, temp_s0);
    strcpy_166478(&sp26, arg1);
    sp68 = 2;
    func_00163EB8_166478(&D_002C1690_166478, 1);
    *arg0 = 0;
    temp_v0 = func_0025B3BC_166478(sp, &func_00163778_166478);
    if (temp_v0 == 0) {
        func_00163E00_166478(arg0, 0xC350);
    }
    return temp_v0;
}
//@@ func_00166478 m2c2
#include "m2c_macros.h"
M2C_UNK func_00163E00_166478() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166478() __asm__("func_00163EB8");
s32 func_0025B3BC_166478() __asm__("func_0025B3BC");
M2C_UNK func_0025BD88_166478() __asm__("func_0025BD88");
M2C_UNK strcpy_166478() __asm__("strcpy");
extern M2C_UNK D_002C1690_166478 __asm__("D_002C1690");
extern M2C_UNK func_00163778_166478 __asm__("func_00163778");

s32 func_00166478(s32* arg0, s32 arg1) {
    u8 sp[0x50];
    M2C_UNK sp15;
    M2C_UNK sp26;
    s32 sp68;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    strcpy_166478(arg0 + 0x1D);
    func_0025BD88_166478(temp_s0, 0x15, sp);
    strcpy_166478(&sp15, temp_s0);
    strcpy_166478(&sp26, arg1);
    sp68 = 2;
    func_00163EB8_166478(&D_002C1690_166478, 1);
    *arg0 = 0;
    temp_v0 = func_0025B3BC_166478(sp, &func_00163778_166478);
    if (temp_v0 == 0) {
        func_00163E00_166478(arg0, 0xC350);
    }
    return temp_v0;
}
//@@ func_00166478 m2c3
#include "m2c_macros.h"
M2C_UNK func_00163E00_166478() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166478() __asm__("func_00163EB8");
s32 func_0025B3BC_166478() __asm__("func_0025B3BC");
M2C_UNK func_0025BD88_166478() __asm__("func_0025BD88");
M2C_UNK strcpy_166478() __asm__("strcpy");
extern M2C_UNK D_002C1690_166478 __asm__("D_002C1690");
extern M2C_UNK func_00163778_166478 __asm__("func_00163778");

s32 func_00166478(s32* arg0, s32 arg1) {
    u8 sp[0x40];
    M2C_UNK sp15;
    M2C_UNK sp26;
    s32 sp68;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    strcpy_166478(arg0 + 0x1D);
    func_0025BD88_166478(temp_s0, 0x15, sp);
    strcpy_166478(&sp15, temp_s0);
    strcpy_166478(&sp26, arg1);
    sp68 = 2;
    func_00163EB8_166478(&D_002C1690_166478, 1);
    *arg0 = 0;
    temp_v0 = func_0025B3BC_166478(sp, &func_00163778_166478);
    if (temp_v0 == 0) {
        func_00163E00_166478(arg0, 0xC350);
    }
    return temp_v0;
}
//@@ func_00166478 m2c4
#include "m2c_macros.h"
M2C_UNK func_00163E00_166478() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166478() __asm__("func_00163EB8");
s32 func_0025B3BC_166478() __asm__("func_0025B3BC");
M2C_UNK func_0025BD88_166478() __asm__("func_0025BD88");
M2C_UNK strcpy_166478() __asm__("strcpy");
extern M2C_UNK D_002C1690_166478 __asm__("D_002C1690");
extern M2C_UNK func_00163778_166478 __asm__("func_00163778");

s32 func_00166478(s32* arg0, s32 arg1) {
    u8 sp[0x30];
    M2C_UNK sp15;
    M2C_UNK sp26;
    s32 sp68;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    strcpy_166478(arg0 + 0x1D);
    func_0025BD88_166478(temp_s0, 0x15, sp);
    strcpy_166478(&sp15, temp_s0);
    strcpy_166478(&sp26, arg1);
    sp68 = 2;
    func_00163EB8_166478(&D_002C1690_166478, 1);
    *arg0 = 0;
    temp_v0 = func_0025B3BC_166478(sp, &func_00163778_166478);
    if (temp_v0 == 0) {
        func_00163E00_166478(arg0, 0xC350);
    }
    return temp_v0;
}
//@@ func_00166478 m2c5
#include "m2c_macros.h"
M2C_UNK func_00163E00_166478() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166478() __asm__("func_00163EB8");
s32 func_0025B3BC_166478() __asm__("func_0025B3BC");
M2C_UNK func_0025BD88_166478() __asm__("func_0025BD88");
M2C_UNK strcpy_166478() __asm__("strcpy");
extern M2C_UNK D_002C1690_166478 __asm__("D_002C1690");
extern M2C_UNK func_00163778_166478 __asm__("func_00163778");

s32 func_00166478(s32* arg0, s32 arg1) {
    u8 sp[0x20];
    M2C_UNK sp15;
    M2C_UNK sp26;
    s32 sp68;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    strcpy_166478(arg0 + 0x1D);
    func_0025BD88_166478(temp_s0, 0x15, sp);
    strcpy_166478(&sp15, temp_s0);
    strcpy_166478(&sp26, arg1);
    sp68 = 2;
    func_00163EB8_166478(&D_002C1690_166478, 1);
    *arg0 = 0;
    temp_v0 = func_0025B3BC_166478(sp, &func_00163778_166478);
    if (temp_v0 == 0) {
        func_00163E00_166478(arg0, 0xC350);
    }
    return temp_v0;
}
//@@ func_00166528 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163E00_166528() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166528() __asm__("func_00163EB8");
s32 func_0025ACF0_166528() __asm__("func_0025ACF0");
M2C_UNK func_0025BD88_166528() __asm__("func_0025BD88");
M2C_UNK strcpy_166528() __asm__("strcpy");
extern s32 D_002C1694_166528 __asm__("D_002C1694");
extern M2C_UNK func_001638C0_166528 __asm__("func_001638C0");

s32 func_00166528(s32* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp[0x80];
    M2C_UNK sp15;
    s32 sp28;
    M2C_UNK sp2C;
    s32 sp4C;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166528(temp_s0, 0x2A, sp);
    strcpy_166528(&sp15, temp_s0);
    sp28 = arg1;
    strcpy_166528(&sp2C, arg2);
    *arg0 = 0;
    sp4C = arg3;
    temp_v0 = func_0025ACF0_166528(sp, &func_001638C0_166528);
    if (temp_v0 != 0) {
        func_00163EB8_166528(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_166528(arg0, 0xC350);
    return (D_002C1694_166528 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166528 m2c1
#include "m2c_macros.h"
M2C_UNK func_00163E00_166528() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166528() __asm__("func_00163EB8");
s32 func_0025ACF0_166528() __asm__("func_0025ACF0");
M2C_UNK func_0025BD88_166528() __asm__("func_0025BD88");
M2C_UNK strcpy_166528() __asm__("strcpy");
extern s32 D_002C1694_166528 __asm__("D_002C1694");
extern M2C_UNK func_001638C0_166528 __asm__("func_001638C0");

s32 func_00166528(s32* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp[0x70];
    M2C_UNK sp15;
    s32 sp28;
    M2C_UNK sp2C;
    s32 sp4C;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166528(temp_s0, 0x2A, sp);
    strcpy_166528(&sp15, temp_s0);
    sp28 = arg1;
    strcpy_166528(&sp2C, arg2);
    *arg0 = 0;
    sp4C = arg3;
    temp_v0 = func_0025ACF0_166528(sp, &func_001638C0_166528);
    if (temp_v0 != 0) {
        func_00163EB8_166528(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_166528(arg0, 0xC350);
    return (D_002C1694_166528 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166528 m2c2
#include "m2c_macros.h"
M2C_UNK func_00163E00_166528() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166528() __asm__("func_00163EB8");
s32 func_0025ACF0_166528() __asm__("func_0025ACF0");
M2C_UNK func_0025BD88_166528() __asm__("func_0025BD88");
M2C_UNK strcpy_166528() __asm__("strcpy");
extern s32 D_002C1694_166528 __asm__("D_002C1694");
extern M2C_UNK func_001638C0_166528 __asm__("func_001638C0");

s32 func_00166528(s32* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp[0x60];
    M2C_UNK sp15;
    s32 sp28;
    M2C_UNK sp2C;
    s32 sp4C;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166528(temp_s0, 0x2A, sp);
    strcpy_166528(&sp15, temp_s0);
    sp28 = arg1;
    strcpy_166528(&sp2C, arg2);
    *arg0 = 0;
    sp4C = arg3;
    temp_v0 = func_0025ACF0_166528(sp, &func_001638C0_166528);
    if (temp_v0 != 0) {
        func_00163EB8_166528(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_166528(arg0, 0xC350);
    return (D_002C1694_166528 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166528 m2c3
#include "m2c_macros.h"
M2C_UNK func_00163E00_166528() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166528() __asm__("func_00163EB8");
s32 func_0025ACF0_166528() __asm__("func_0025ACF0");
M2C_UNK func_0025BD88_166528() __asm__("func_0025BD88");
M2C_UNK strcpy_166528() __asm__("strcpy");
extern s32 D_002C1694_166528 __asm__("D_002C1694");
extern M2C_UNK func_001638C0_166528 __asm__("func_001638C0");

s32 func_00166528(s32* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp[0x50];
    M2C_UNK sp15;
    s32 sp28;
    M2C_UNK sp2C;
    s32 sp4C;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166528(temp_s0, 0x2A, sp);
    strcpy_166528(&sp15, temp_s0);
    sp28 = arg1;
    strcpy_166528(&sp2C, arg2);
    *arg0 = 0;
    sp4C = arg3;
    temp_v0 = func_0025ACF0_166528(sp, &func_001638C0_166528);
    if (temp_v0 != 0) {
        func_00163EB8_166528(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_166528(arg0, 0xC350);
    return (D_002C1694_166528 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166528 m2c4
#include "m2c_macros.h"
M2C_UNK func_00163E00_166528() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166528() __asm__("func_00163EB8");
s32 func_0025ACF0_166528() __asm__("func_0025ACF0");
M2C_UNK func_0025BD88_166528() __asm__("func_0025BD88");
M2C_UNK strcpy_166528() __asm__("strcpy");
extern s32 D_002C1694_166528 __asm__("D_002C1694");
extern M2C_UNK func_001638C0_166528 __asm__("func_001638C0");

s32 func_00166528(s32* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp[0x40];
    M2C_UNK sp15;
    s32 sp28;
    M2C_UNK sp2C;
    s32 sp4C;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166528(temp_s0, 0x2A, sp);
    strcpy_166528(&sp15, temp_s0);
    sp28 = arg1;
    strcpy_166528(&sp2C, arg2);
    *arg0 = 0;
    sp4C = arg3;
    temp_v0 = func_0025ACF0_166528(sp, &func_001638C0_166528);
    if (temp_v0 != 0) {
        func_00163EB8_166528(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_166528(arg0, 0xC350);
    return (D_002C1694_166528 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166528 m2c5
#include "m2c_macros.h"
M2C_UNK func_00163E00_166528() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166528() __asm__("func_00163EB8");
s32 func_0025ACF0_166528() __asm__("func_0025ACF0");
M2C_UNK func_0025BD88_166528() __asm__("func_0025BD88");
M2C_UNK strcpy_166528() __asm__("strcpy");
extern s32 D_002C1694_166528 __asm__("D_002C1694");
extern M2C_UNK func_001638C0_166528 __asm__("func_001638C0");

s32 func_00166528(s32* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 sp28;
    M2C_UNK sp2C;
    s32 sp4C;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166528(temp_s0, 0x2A, sp);
    strcpy_166528(&sp15, temp_s0);
    sp28 = arg1;
    strcpy_166528(&sp2C, arg2);
    *arg0 = 0;
    sp4C = arg3;
    temp_v0 = func_0025ACF0_166528(sp, &func_001638C0_166528);
    if (temp_v0 != 0) {
        func_00163EB8_166528(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_166528(arg0, 0xC350);
    return (D_002C1694_166528 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166600 m2c0
#include "m2c_macros.h"
M2C_UNK func_0025B9D0_166600() __asm__("func_0025B9D0");
M2C_UNK strcpy_166600() __asm__("strcpy");
extern M2C_UNK D_004F9C48_166600 __asm__("D_004F9C48");
extern M2C_UNK D_004F9C50_166600 __asm__("D_004F9C50");

void func_00166600(s32 arg0, s32 arg1) {
    u8 sp[0x80];
    strcpy_166600(sp, arg0 + 0xC);
    func_0025B9D0_166600(sp, &D_004F9C50_166600, &D_004F9C50_166600, M2C_FIELD(&D_004F9C48_166600, u8* , 4), arg1, M2C_FIELD(&D_004F9C48_166600, s32* , 0), M2C_FIELD(&D_004F9C48_166600, u8* , 4), M2C_FIELD(&D_004F9C50_166600, s32* , 0), M2C_FIELD(&D_004F9C50_166600, u16* , 4), M2C_FIELD(&D_004F9C50_166600, u8* , 6), 0x3E8);
}
//@@ func_00166600 m2c1
#include "m2c_macros.h"
M2C_UNK func_0025B9D0_166600() __asm__("func_0025B9D0");
M2C_UNK strcpy_166600() __asm__("strcpy");
extern M2C_UNK D_004F9C48_166600 __asm__("D_004F9C48");
extern M2C_UNK D_004F9C50_166600 __asm__("D_004F9C50");

void func_00166600(s32 arg0, s32 arg1) {
    u8 sp[0x70];
    strcpy_166600(sp, arg0 + 0xC);
    func_0025B9D0_166600(sp, &D_004F9C50_166600, &D_004F9C50_166600, M2C_FIELD(&D_004F9C48_166600, u8* , 4), arg1, M2C_FIELD(&D_004F9C48_166600, s32* , 0), M2C_FIELD(&D_004F9C48_166600, u8* , 4), M2C_FIELD(&D_004F9C50_166600, s32* , 0), M2C_FIELD(&D_004F9C50_166600, u16* , 4), M2C_FIELD(&D_004F9C50_166600, u8* , 6), 0x3E8);
}
//@@ func_00166600 m2c2
#include "m2c_macros.h"
M2C_UNK func_0025B9D0_166600() __asm__("func_0025B9D0");
M2C_UNK strcpy_166600() __asm__("strcpy");
extern M2C_UNK D_004F9C48_166600 __asm__("D_004F9C48");
extern M2C_UNK D_004F9C50_166600 __asm__("D_004F9C50");

void func_00166600(s32 arg0, s32 arg1) {
    u8 sp[0x60];
    strcpy_166600(sp, arg0 + 0xC);
    func_0025B9D0_166600(sp, &D_004F9C50_166600, &D_004F9C50_166600, M2C_FIELD(&D_004F9C48_166600, u8* , 4), arg1, M2C_FIELD(&D_004F9C48_166600, s32* , 0), M2C_FIELD(&D_004F9C48_166600, u8* , 4), M2C_FIELD(&D_004F9C50_166600, s32* , 0), M2C_FIELD(&D_004F9C50_166600, u16* , 4), M2C_FIELD(&D_004F9C50_166600, u8* , 6), 0x3E8);
}
//@@ func_00166600 m2c3
#include "m2c_macros.h"
M2C_UNK func_0025B9D0_166600() __asm__("func_0025B9D0");
M2C_UNK strcpy_166600() __asm__("strcpy");
extern M2C_UNK D_004F9C48_166600 __asm__("D_004F9C48");
extern M2C_UNK D_004F9C50_166600 __asm__("D_004F9C50");

void func_00166600(s32 arg0, s32 arg1) {
    u8 sp[0x50];
    strcpy_166600(sp, arg0 + 0xC);
    func_0025B9D0_166600(sp, &D_004F9C50_166600, &D_004F9C50_166600, M2C_FIELD(&D_004F9C48_166600, u8* , 4), arg1, M2C_FIELD(&D_004F9C48_166600, s32* , 0), M2C_FIELD(&D_004F9C48_166600, u8* , 4), M2C_FIELD(&D_004F9C50_166600, s32* , 0), M2C_FIELD(&D_004F9C50_166600, u16* , 4), M2C_FIELD(&D_004F9C50_166600, u8* , 6), 0x3E8);
}
//@@ func_00166600 m2c4
#include "m2c_macros.h"
M2C_UNK func_0025B9D0_166600() __asm__("func_0025B9D0");
M2C_UNK strcpy_166600() __asm__("strcpy");
extern M2C_UNK D_004F9C48_166600 __asm__("D_004F9C48");
extern M2C_UNK D_004F9C50_166600 __asm__("D_004F9C50");

void func_00166600(s32 arg0, s32 arg1) {
    u8 sp[0x40];
    strcpy_166600(sp, arg0 + 0xC);
    func_0025B9D0_166600(sp, &D_004F9C50_166600, &D_004F9C50_166600, M2C_FIELD(&D_004F9C48_166600, u8* , 4), arg1, M2C_FIELD(&D_004F9C48_166600, s32* , 0), M2C_FIELD(&D_004F9C48_166600, u8* , 4), M2C_FIELD(&D_004F9C50_166600, s32* , 0), M2C_FIELD(&D_004F9C50_166600, u16* , 4), M2C_FIELD(&D_004F9C50_166600, u8* , 6), 0x3E8);
}
//@@ func_00166600 m2c5
#include "m2c_macros.h"
M2C_UNK func_0025B9D0_166600() __asm__("func_0025B9D0");
M2C_UNK strcpy_166600() __asm__("strcpy");
extern M2C_UNK D_004F9C48_166600 __asm__("D_004F9C48");
extern M2C_UNK D_004F9C50_166600 __asm__("D_004F9C50");

void func_00166600(s32 arg0, s32 arg1) {
    u8 sp[0x30];
    strcpy_166600(sp, arg0 + 0xC);
    func_0025B9D0_166600(sp, &D_004F9C50_166600, &D_004F9C50_166600, M2C_FIELD(&D_004F9C48_166600, u8* , 4), arg1, M2C_FIELD(&D_004F9C48_166600, s32* , 0), M2C_FIELD(&D_004F9C48_166600, u8* , 4), M2C_FIELD(&D_004F9C50_166600, s32* , 0), M2C_FIELD(&D_004F9C50_166600, u16* , 4), M2C_FIELD(&D_004F9C50_166600, u8* , 6), 0x3E8);
}
//@@ func_00166678 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163E00_166678() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166678() __asm__("func_00163EB8");
M2C_UNK func_0025BD88_166678() __asm__("func_0025BD88");
s32 func_0025BF48_166678() __asm__("func_0025BF48");
M2C_UNK strcpy_166678() __asm__("strcpy");
extern s32 D_002C1694_166678 __asm__("D_002C1694");
extern M2C_UNK func_001639F8_166678 __asm__("func_001639F8");

s32 func_00166678(s32* arg0, s32 arg1) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 sp28;
    s32 sp2C;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166678(temp_s0, 0xFFFFFF, sp);
    strcpy_166678(&sp15, temp_s0);
    *arg0 = 0;
    sp28 = arg1;
    sp2C = 0;
    temp_v0 = func_0025BF48_166678(sp, &func_001639F8_166678);
    if (temp_v0 != 0) {
        func_00163EB8_166678(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_166678(arg0, 0xC350);
    return (D_002C1694_166678 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166678 m2c1
#include "m2c_macros.h"
M2C_UNK func_00163E00_166678() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166678() __asm__("func_00163EB8");
M2C_UNK func_0025BD88_166678() __asm__("func_0025BD88");
s32 func_0025BF48_166678() __asm__("func_0025BF48");
M2C_UNK strcpy_166678() __asm__("strcpy");
extern s32 D_002C1694_166678 __asm__("D_002C1694");
extern M2C_UNK func_001639F8_166678 __asm__("func_001639F8");

s32 func_00166678(s32* arg0, s32 arg1) {
    u8 sp[0x20];
    M2C_UNK sp15;
    s32 sp28;
    s32 sp2C;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166678(temp_s0, 0xFFFFFF, sp);
    strcpy_166678(&sp15, temp_s0);
    *arg0 = 0;
    sp28 = arg1;
    sp2C = 0;
    temp_v0 = func_0025BF48_166678(sp, &func_001639F8_166678);
    if (temp_v0 != 0) {
        func_00163EB8_166678(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_166678(arg0, 0xC350);
    return (D_002C1694_166678 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166678 m2c2
#include "m2c_macros.h"
M2C_UNK func_00163E00_166678() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166678() __asm__("func_00163EB8");
M2C_UNK func_0025BD88_166678() __asm__("func_0025BD88");
s32 func_0025BF48_166678() __asm__("func_0025BF48");
M2C_UNK strcpy_166678() __asm__("strcpy");
extern s32 D_002C1694_166678 __asm__("D_002C1694");
extern M2C_UNK func_001639F8_166678 __asm__("func_001639F8");

s32 func_00166678(s32* arg0, s32 arg1) {
    u8 sp[0x10];
    M2C_UNK sp15;
    s32 sp28;
    s32 sp2C;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166678(temp_s0, 0xFFFFFF, sp);
    strcpy_166678(&sp15, temp_s0);
    *arg0 = 0;
    sp28 = arg1;
    sp2C = 0;
    temp_v0 = func_0025BF48_166678(sp, &func_001639F8_166678);
    if (temp_v0 != 0) {
        func_00163EB8_166678(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_166678(arg0, 0xC350);
    return (D_002C1694_166678 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166678 m2c3
#include "m2c_macros.h"
M2C_UNK func_00163E00_166678() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166678() __asm__("func_00163EB8");
M2C_UNK func_0025BD88_166678() __asm__("func_0025BD88");
s32 func_0025BF48_166678() __asm__("func_0025BF48");
M2C_UNK strcpy_166678() __asm__("strcpy");
extern s32 D_002C1694_166678 __asm__("D_002C1694");
extern M2C_UNK func_001639F8_166678 __asm__("func_001639F8");

s32 func_00166678(s32* arg0, s32 arg1) {
    u8 sp[0x8];
    M2C_UNK sp15;
    s32 sp28;
    s32 sp2C;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166678(temp_s0, 0xFFFFFF, sp);
    strcpy_166678(&sp15, temp_s0);
    *arg0 = 0;
    sp28 = arg1;
    sp2C = 0;
    temp_v0 = func_0025BF48_166678(sp, &func_001639F8_166678);
    if (temp_v0 != 0) {
        func_00163EB8_166678(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_166678(arg0, 0xC350);
    return (D_002C1694_166678 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166678 m2c4
#include "m2c_macros.h"
M2C_UNK func_00163E00_166678() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166678() __asm__("func_00163EB8");
M2C_UNK func_0025BD88_166678() __asm__("func_0025BD88");
s32 func_0025BF48_166678() __asm__("func_0025BF48");
M2C_UNK strcpy_166678() __asm__("strcpy");
extern s32 D_002C1694_166678 __asm__("D_002C1694");
extern M2C_UNK func_001639F8_166678 __asm__("func_001639F8");

s32 func_00166678(s32* arg0, s32 arg1) {
    u8 sp[0x4];
    M2C_UNK sp15;
    s32 sp28;
    s32 sp2C;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166678(temp_s0, 0xFFFFFF, sp);
    strcpy_166678(&sp15, temp_s0);
    *arg0 = 0;
    sp28 = arg1;
    sp2C = 0;
    temp_v0 = func_0025BF48_166678(sp, &func_001639F8_166678);
    if (temp_v0 != 0) {
        func_00163EB8_166678(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_166678(arg0, 0xC350);
    return (D_002C1694_166678 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166730 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163E00_166730() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166730() __asm__("func_00163EB8");
s32 func_0025B1D0_166730() __asm__("func_0025B1D0");
M2C_UNK func_0025BD88_166730() __asm__("func_0025BD88");
M2C_UNK strcpy_166730() __asm__("strcpy");
extern s32 D_002C1694_166730 __asm__("D_002C1694");
extern M2C_UNK func_00163A58_166730 __asm__("func_00163A58");

s32 func_00166730(s32* arg0, s32 arg1) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166730(temp_s0, 0x1C, sp);
    strcpy_166730(&sp15, temp_s0);
    *arg0 = 0;
    sp28 = arg1;
    temp_v0 = func_0025B1D0_166730(sp, &func_00163A58_166730);
    if (temp_v0 != 0) {
        func_00163EB8_166730(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_166730(arg0, 0xC350);
    return (D_002C1694_166730 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166730 m2c1
#include "m2c_macros.h"
M2C_UNK func_00163E00_166730() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166730() __asm__("func_00163EB8");
s32 func_0025B1D0_166730() __asm__("func_0025B1D0");
M2C_UNK func_0025BD88_166730() __asm__("func_0025BD88");
M2C_UNK strcpy_166730() __asm__("strcpy");
extern s32 D_002C1694_166730 __asm__("D_002C1694");
extern M2C_UNK func_00163A58_166730 __asm__("func_00163A58");

s32 func_00166730(s32* arg0, s32 arg1) {
    u8 sp[0x20];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166730(temp_s0, 0x1C, sp);
    strcpy_166730(&sp15, temp_s0);
    *arg0 = 0;
    sp28 = arg1;
    temp_v0 = func_0025B1D0_166730(sp, &func_00163A58_166730);
    if (temp_v0 != 0) {
        func_00163EB8_166730(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_166730(arg0, 0xC350);
    return (D_002C1694_166730 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166730 m2c2
#include "m2c_macros.h"
M2C_UNK func_00163E00_166730() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166730() __asm__("func_00163EB8");
s32 func_0025B1D0_166730() __asm__("func_0025B1D0");
M2C_UNK func_0025BD88_166730() __asm__("func_0025BD88");
M2C_UNK strcpy_166730() __asm__("strcpy");
extern s32 D_002C1694_166730 __asm__("D_002C1694");
extern M2C_UNK func_00163A58_166730 __asm__("func_00163A58");

s32 func_00166730(s32* arg0, s32 arg1) {
    u8 sp[0x10];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166730(temp_s0, 0x1C, sp);
    strcpy_166730(&sp15, temp_s0);
    *arg0 = 0;
    sp28 = arg1;
    temp_v0 = func_0025B1D0_166730(sp, &func_00163A58_166730);
    if (temp_v0 != 0) {
        func_00163EB8_166730(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_166730(arg0, 0xC350);
    return (D_002C1694_166730 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166730 m2c3
#include "m2c_macros.h"
M2C_UNK func_00163E00_166730() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166730() __asm__("func_00163EB8");
s32 func_0025B1D0_166730() __asm__("func_0025B1D0");
M2C_UNK func_0025BD88_166730() __asm__("func_0025BD88");
M2C_UNK strcpy_166730() __asm__("strcpy");
extern s32 D_002C1694_166730 __asm__("D_002C1694");
extern M2C_UNK func_00163A58_166730 __asm__("func_00163A58");

s32 func_00166730(s32* arg0, s32 arg1) {
    u8 sp[0x8];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166730(temp_s0, 0x1C, sp);
    strcpy_166730(&sp15, temp_s0);
    *arg0 = 0;
    sp28 = arg1;
    temp_v0 = func_0025B1D0_166730(sp, &func_00163A58_166730);
    if (temp_v0 != 0) {
        func_00163EB8_166730(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_166730(arg0, 0xC350);
    return (D_002C1694_166730 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166730 m2c4
#include "m2c_macros.h"
M2C_UNK func_00163E00_166730() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166730() __asm__("func_00163EB8");
s32 func_0025B1D0_166730() __asm__("func_0025B1D0");
M2C_UNK func_0025BD88_166730() __asm__("func_0025BD88");
M2C_UNK strcpy_166730() __asm__("strcpy");
extern s32 D_002C1694_166730 __asm__("D_002C1694");
extern M2C_UNK func_00163A58_166730 __asm__("func_00163A58");

s32 func_00166730(s32* arg0, s32 arg1) {
    u8 sp[0x4];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166730(temp_s0, 0x1C, sp);
    strcpy_166730(&sp15, temp_s0);
    *arg0 = 0;
    sp28 = arg1;
    temp_v0 = func_0025B1D0_166730(sp, &func_00163A58_166730);
    if (temp_v0 != 0) {
        func_00163EB8_166730(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_166730(arg0, 0xC350);
    return (D_002C1694_166730 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_001667E0 m2c0
#include "m2c_macros.h"
M2C_UNK func_0025B938_1667E0() __asm__("func_0025B938");

void func_001667E0(s32 arg0) {
    func_0025B938_1667E0(arg0 + 0x52444);
}
//@@ func_00166808 m2c0
#include "m2c_macros.h"
M2C_UNK func_0025B1D0_166808() __asm__("func_0025B1D0");
M2C_UNK func_0025BD88_166808() __asm__("func_0025BD88");
M2C_UNK strcpy_166808() __asm__("strcpy");
extern M2C_UNK func_00163B00_166808 __asm__("func_00163B00");

void func_00166808(s32 arg0, s32 arg1) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166808(temp_s0, 0x1C, sp);
    strcpy_166808(&sp15, temp_s0);
    sp28 = arg1;
    func_0025B1D0_166808(sp, &func_00163B00_166808);
}
//@@ func_00166808 m2c1
#include "m2c_macros.h"
M2C_UNK func_0025B1D0_166808() __asm__("func_0025B1D0");
M2C_UNK func_0025BD88_166808() __asm__("func_0025BD88");
M2C_UNK strcpy_166808() __asm__("strcpy");
extern M2C_UNK func_00163B00_166808 __asm__("func_00163B00");

void func_00166808(s32 arg0, s32 arg1) {
    u8 sp[0x20];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166808(temp_s0, 0x1C, sp);
    strcpy_166808(&sp15, temp_s0);
    sp28 = arg1;
    func_0025B1D0_166808(sp, &func_00163B00_166808);
}
//@@ func_00166808 m2c2
#include "m2c_macros.h"
M2C_UNK func_0025B1D0_166808() __asm__("func_0025B1D0");
M2C_UNK func_0025BD88_166808() __asm__("func_0025BD88");
M2C_UNK strcpy_166808() __asm__("strcpy");
extern M2C_UNK func_00163B00_166808 __asm__("func_00163B00");

void func_00166808(s32 arg0, s32 arg1) {
    u8 sp[0x10];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166808(temp_s0, 0x1C, sp);
    strcpy_166808(&sp15, temp_s0);
    sp28 = arg1;
    func_0025B1D0_166808(sp, &func_00163B00_166808);
}
//@@ func_00166808 m2c3
#include "m2c_macros.h"
M2C_UNK func_0025B1D0_166808() __asm__("func_0025B1D0");
M2C_UNK func_0025BD88_166808() __asm__("func_0025BD88");
M2C_UNK strcpy_166808() __asm__("strcpy");
extern M2C_UNK func_00163B00_166808 __asm__("func_00163B00");

void func_00166808(s32 arg0, s32 arg1) {
    u8 sp[0x8];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166808(temp_s0, 0x1C, sp);
    strcpy_166808(&sp15, temp_s0);
    sp28 = arg1;
    func_0025B1D0_166808(sp, &func_00163B00_166808);
}
//@@ func_00166808 m2c4
#include "m2c_macros.h"
M2C_UNK func_0025B1D0_166808() __asm__("func_0025B1D0");
M2C_UNK func_0025BD88_166808() __asm__("func_0025BD88");
M2C_UNK strcpy_166808() __asm__("strcpy");
extern M2C_UNK func_00163B00_166808 __asm__("func_00163B00");

void func_00166808(s32 arg0, s32 arg1) {
    u8 sp[0x4];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166808(temp_s0, 0x1C, sp);
    strcpy_166808(&sp15, temp_s0);
    sp28 = arg1;
    func_0025B1D0_166808(sp, &func_00163B00_166808);
}
//@@ func_00166868 m2c0
#include "m2c_macros.h"
M2C_UNK func_00163E00_166868() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166868() __asm__("func_00163EB8");
s32 func_0025B130_166868() __asm__("func_0025B130");
M2C_UNK func_0025BD88_166868() __asm__("func_0025BD88");
M2C_UNK strcpy_166868() __asm__("strcpy");
extern s32 D_002C1694_166868 __asm__("D_002C1694");
extern M2C_UNK func_00163CE0_166868 __asm__("func_00163CE0");

s32 func_00166868(s32 arg0, s32 arg1, s32 arg2) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166868(temp_s0, 0x23, sp);
    strcpy_166868(&sp15, temp_s0);
    sp28 = arg2;
    temp_v0 = func_0025B130_166868(sp, &func_00163CE0_166868);
    if (temp_v0 != 0) {
        func_00163EB8_166868(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_166868(arg0, 0xC350);
    return (D_002C1694_166868 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166868 m2c1
#include "m2c_macros.h"
M2C_UNK func_00163E00_166868() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166868() __asm__("func_00163EB8");
s32 func_0025B130_166868() __asm__("func_0025B130");
M2C_UNK func_0025BD88_166868() __asm__("func_0025BD88");
M2C_UNK strcpy_166868() __asm__("strcpy");
extern s32 D_002C1694_166868 __asm__("D_002C1694");
extern M2C_UNK func_00163CE0_166868 __asm__("func_00163CE0");

s32 func_00166868(s32 arg0, s32 arg1, s32 arg2) {
    u8 sp[0x20];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166868(temp_s0, 0x23, sp);
    strcpy_166868(&sp15, temp_s0);
    sp28 = arg2;
    temp_v0 = func_0025B130_166868(sp, &func_00163CE0_166868);
    if (temp_v0 != 0) {
        func_00163EB8_166868(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_166868(arg0, 0xC350);
    return (D_002C1694_166868 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166868 m2c2
#include "m2c_macros.h"
M2C_UNK func_00163E00_166868() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166868() __asm__("func_00163EB8");
s32 func_0025B130_166868() __asm__("func_0025B130");
M2C_UNK func_0025BD88_166868() __asm__("func_0025BD88");
M2C_UNK strcpy_166868() __asm__("strcpy");
extern s32 D_002C1694_166868 __asm__("D_002C1694");
extern M2C_UNK func_00163CE0_166868 __asm__("func_00163CE0");

s32 func_00166868(s32 arg0, s32 arg1, s32 arg2) {
    u8 sp[0x10];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166868(temp_s0, 0x23, sp);
    strcpy_166868(&sp15, temp_s0);
    sp28 = arg2;
    temp_v0 = func_0025B130_166868(sp, &func_00163CE0_166868);
    if (temp_v0 != 0) {
        func_00163EB8_166868(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_166868(arg0, 0xC350);
    return (D_002C1694_166868 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166868 m2c3
#include "m2c_macros.h"
M2C_UNK func_00163E00_166868() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166868() __asm__("func_00163EB8");
s32 func_0025B130_166868() __asm__("func_0025B130");
M2C_UNK func_0025BD88_166868() __asm__("func_0025BD88");
M2C_UNK strcpy_166868() __asm__("strcpy");
extern s32 D_002C1694_166868 __asm__("D_002C1694");
extern M2C_UNK func_00163CE0_166868 __asm__("func_00163CE0");

s32 func_00166868(s32 arg0, s32 arg1, s32 arg2) {
    u8 sp[0x8];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166868(temp_s0, 0x23, sp);
    strcpy_166868(&sp15, temp_s0);
    sp28 = arg2;
    temp_v0 = func_0025B130_166868(sp, &func_00163CE0_166868);
    if (temp_v0 != 0) {
        func_00163EB8_166868(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_166868(arg0, 0xC350);
    return (D_002C1694_166868 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166868 m2c4
#include "m2c_macros.h"
M2C_UNK func_00163E00_166868() __asm__("func_00163E00");
M2C_UNK func_00163EB8_166868() __asm__("func_00163EB8");
s32 func_0025B130_166868() __asm__("func_0025B130");
M2C_UNK func_0025BD88_166868() __asm__("func_0025BD88");
M2C_UNK strcpy_166868() __asm__("strcpy");
extern s32 D_002C1694_166868 __asm__("D_002C1694");
extern M2C_UNK func_00163CE0_166868 __asm__("func_00163CE0");

s32 func_00166868(s32 arg0, s32 arg1, s32 arg2) {
    u8 sp[0x4];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166868(temp_s0, 0x23, sp);
    strcpy_166868(&sp15, temp_s0);
    sp28 = arg2;
    temp_v0 = func_0025B130_166868(sp, &func_00163CE0_166868);
    if (temp_v0 != 0) {
        func_00163EB8_166868(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00_166868(arg0, 0xC350);
    return (D_002C1694_166868 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166918 m2c0
#include "m2c_macros.h"
M2C_UNK func_0025B8AC_166918() __asm__("func_0025B8AC");

void func_00166918(s32 arg0) {
    func_0025B8AC_166918(arg0 + 0x525C4);
}
//@@ func_00166940 m2c0
#include "m2c_macros.h"
M2C_UNK func_0025B130_166940() __asm__("func_0025B130");
M2C_UNK func_0025BD88_166940() __asm__("func_0025BD88");
M2C_UNK strcpy_166940() __asm__("strcpy");
extern M2C_UNK func_00163D48_166940 __asm__("func_00163D48");

void func_00166940(s32 arg0, s32 arg1, s32 arg2) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166940(temp_s0, 0x23, sp);
    strcpy_166940(&sp15, temp_s0);
    sp28 = arg2;
    func_0025B130_166940(sp, &func_00163D48_166940);
}
//@@ func_00166940 m2c1
#include "m2c_macros.h"
M2C_UNK func_0025B130_166940() __asm__("func_0025B130");
M2C_UNK func_0025BD88_166940() __asm__("func_0025BD88");
M2C_UNK strcpy_166940() __asm__("strcpy");
extern M2C_UNK func_00163D48_166940 __asm__("func_00163D48");

void func_00166940(s32 arg0, s32 arg1, s32 arg2) {
    u8 sp[0x20];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166940(temp_s0, 0x23, sp);
    strcpy_166940(&sp15, temp_s0);
    sp28 = arg2;
    func_0025B130_166940(sp, &func_00163D48_166940);
}
//@@ func_00166940 m2c2
#include "m2c_macros.h"
M2C_UNK func_0025B130_166940() __asm__("func_0025B130");
M2C_UNK func_0025BD88_166940() __asm__("func_0025BD88");
M2C_UNK strcpy_166940() __asm__("strcpy");
extern M2C_UNK func_00163D48_166940 __asm__("func_00163D48");

void func_00166940(s32 arg0, s32 arg1, s32 arg2) {
    u8 sp[0x10];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166940(temp_s0, 0x23, sp);
    strcpy_166940(&sp15, temp_s0);
    sp28 = arg2;
    func_0025B130_166940(sp, &func_00163D48_166940);
}
//@@ func_00166940 m2c3
#include "m2c_macros.h"
M2C_UNK func_0025B130_166940() __asm__("func_0025B130");
M2C_UNK func_0025BD88_166940() __asm__("func_0025BD88");
M2C_UNK strcpy_166940() __asm__("strcpy");
extern M2C_UNK func_00163D48_166940 __asm__("func_00163D48");

void func_00166940(s32 arg0, s32 arg1, s32 arg2) {
    u8 sp[0x8];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166940(temp_s0, 0x23, sp);
    strcpy_166940(&sp15, temp_s0);
    sp28 = arg2;
    func_0025B130_166940(sp, &func_00163D48_166940);
}
//@@ func_00166940 m2c4
#include "m2c_macros.h"
M2C_UNK func_0025B130_166940() __asm__("func_0025B130");
M2C_UNK func_0025BD88_166940() __asm__("func_0025BD88");
M2C_UNK strcpy_166940() __asm__("strcpy");
extern M2C_UNK func_00163D48_166940 __asm__("func_00163D48");

void func_00166940(s32 arg0, s32 arg1, s32 arg2) {
    u8 sp[0x4];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88_166940(temp_s0, 0x23, sp);
    strcpy_166940(&sp15, temp_s0);
    sp28 = arg2;
    func_0025B130_166940(sp, &func_00163D48_166940);
}
//@@ func_001669A0 m2c0
#include "m2c_macros.h"
extern s32 D_002C1698_1669A0 __asm__("D_002C1698");

void func_001669A0(s32 arg0, s32 arg1) {
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        D_002C1698_1669A0 = -1;
    }
}
//@@ netMsgWorldEventHandler m2c0
#include "m2c_macros.h"
M2C_UNK animationStart__FR11_animHandleb_andler() __asm__("animationStart__FR11_animHandleb");
M2C_UNK func_001FBCF8_andler() __asm__("func_001FBCF8");
M2C_UNK hierSetSwitch__FP11_hierswitchi_andler() __asm__("hierSetSwitch__FP11_hierswitchi");
extern void* D_004FA030_andler __asm__("D_004FA030");
extern s32 D_004FA038_andler __asm__("D_004FA038");

s32 netMsgWorldEventHandler(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    u8 sp[0x20];
    u32* sp10;
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s1;
    s32 var_s3;
    s32 var_s3_2;
    s32 var_v1;
    s32 var_v1_2;
    u32 temp_v1_3;
    u32 temp_v1_4;
    u32* temp_a1_3;
    u32* var_fp;
    u32* var_s6;
    u32* var_s7;
    void* temp_a0;
    void* temp_a1_2;
    void* temp_a2;

    var_fp = NULL;
    var_s7 = NULL;
    var_s6 = NULL;
    var_s1 = 0;
    sp10 = NULL;
    if (arg2 != 0x100) {
        temp_v1 = M2C_FIELD(arg3, s32* , 0);
        if (temp_v1 != 0x28) {
            if (temp_v1 < 0x29) {
                if (temp_v1 != 0x22) {
                    return 0xC0;
                }
                var_s3 = 0;
                var_v1 = 1;
loop_8:
                var_s0 = 7;
                if (var_v1 != 0) {
                    var_a2 = var_s1 * 0x18;
loop_10:
                    temp_a1 = 1 << var_s0;
                    var_s1 += 1;
                    var_s0 -= 1;
                    temp_a0 = M2C_FIELD((D_004FA030_andler + 0x80000 + var_a2), void** , 0x63A0);
                    var_a2 += 0x18;
                    M2C_FIELD(temp_a0, s8* , 0xC) = (s8) ((*(arg3 + 4 + var_s3) & temp_a1) != 0);
                    if (var_s0 >= 0) {
                        if (var_s1 < 0x69) {
                            goto loop_10;
                        }
                    }
                }
                var_s3 += 1;
                temp_v0 = var_s1 < 0x69;
                if (var_s3 < 0xE) {
                    var_v1 = temp_v0;
                    if (temp_v0 == 0) {

                    } else {
                        goto loop_8;
                    }
                }
                goto block_59;
            }
            if (temp_v1 != 0x2A) {
                return 0xC0;
            }
            if (M2C_FIELD(arg3, s32* , 4) != 0) {
                M2C_FIELD(D_004FA030_andler, s32* , 0x9651C) = 1;
                M2C_FIELD(M2C_FIELD(D_004FA030_andler, void** , 0x96580), s8* , 0xC) = 0;
                hierSetSwitch__FP11_hierswitchi_andler(M2C_FIELD(D_004FA030_andler, s32* , 0x96604), 1, (void* )0x90000);
            }
            goto block_59;
        }
        var_s3_2 = 0;
        var_v1_2 = 1;
loop_16:
        var_s0_2 = 7;
        if (var_v1_2 != 0) {
            temp_v1_2 = D_004FA038_andler;
loop_18:
            temp_v0_2 = var_s1 << 6;
            temp_a1_2 = temp_v1_2 + temp_v0_2;
            temp_a2 = M2C_FIELD(temp_a1_2, void** , 0x10);
            if (temp_a2 != NULL) {
                if ((M2C_FIELD((arg3 + var_s3_2), u8* , 4) & (1 << var_s0_2)) > 0) {
                    M2C_FIELD(temp_a1_2, s32* , 4) = -1;
                    M2C_FIELD(temp_a2, s8* , 8) = 1;
                    temp_v1_3 = (u32) *M2C_FIELD((D_004FA038_andler + temp_v0_2), u32** , 0x10) >> 0x12;
                    switch (temp_v1_3) {
                    case 0x179F:
                        M2C_FIELD(D_004FA030_andler, s32* , 0x967B8) = 1;
                        M2C_FIELD(D_004FA030_andler, s32* , 0x967B4) = 1;
                        hierSetSwitch__FP11_hierswitchi_andler(M2C_FIELD(D_004FA030_andler, s32* , 0x96800), 1, temp_a2, 1);
                        break;
                    case 0x177F:
                        func_001FBCF8_andler(sp, 0x271D, 0, 1);
                        animationStart__FR11_animHandleb_andler(sp, 1);
                        break;
                    case 0x1793:
                        M2C_FIELD(D_004FA030_andler, s32* , 0x96658) = 1;
                        break;
                    case 0x178F:
                        M2C_FIELD(D_004FA030_andler, s32* , 0x96664) = 1;
                        break;
                    case 0x1790:
                        M2C_FIELD(D_004FA030_andler, s32* , 0x96668) = 1;
                        break;
                    case 0x1791:
                        M2C_FIELD(D_004FA030_andler, s32* , 0x9666C) = 1;
                        break;
                    case 0x1792:
                        M2C_FIELD(D_004FA030_andler, s32* , 0x96670) = 1;
                        break;
                    case 0x17B3:
                        func_001FBCF8_andler(sp, 0x2909, 0, 1);
                        animationStart__FR11_animHandleb_andler(sp, 1);
                        break;
                    }
                } else {
                default:
                }
                temp_a1_3 = M2C_FIELD((D_004FA038_andler + temp_v0_2), u32** , 0x10);
                temp_v1_4 = (u32) *temp_a1_3 >> 0x12;
                switch (temp_v1_4) {                /* switch 1; irregular */
                case 0x178F:                        /* switch 1 */
                    var_s6 = temp_a1_3;
                    break;
                case 0x1792:                        /* switch 1 */
                    sp10 = temp_a1_3;
                    break;
                case 0x1790:                        /* switch 1 */
                    var_s7 = temp_a1_3;
                    break;
                case 0x1791:                        /* switch 1 */
                    var_fp = temp_a1_3;
                    break;
                }
            }
            var_s1 += 1;
            var_s0_2 -= 1;
            if ((var_s0_2 >= 0) && (var_s1 < 0x5DC)) {
                goto loop_18;
            }
        }
        var_s3_2 += 1;
        temp_v0_3 = var_s1 < 0x5DC;
        if (var_s3_2 < 0xBC) {
            var_v1_2 = temp_v0_3;
            if (temp_v0_3 != 0) {
                goto loop_16;
            }
        }
        if (M2C_FIELD(D_004FA030_andler, s32* , 0x96658) != 0) {
            if (var_s6 != NULL) {
                M2C_FIELD(var_s6, s8* , 8) = 1;
            }
            if (var_s7 != NULL) {
                M2C_FIELD(var_s7, s8* , 8) = 1;
            }
            if (var_fp != NULL) {
                M2C_FIELD(var_fp, s8* , 8) = 1;
            }
            if (sp10 != NULL) {
                M2C_FIELD(sp10, s8* , 8) = 1;
            }
        }
        /* Duplicate return node #60. Try simplifying control flow for better match */
        return 0xC0;
    }
block_59:
    return 0xC0;
}
//@@ netMsgWorldEventHandler m2c1
#include "m2c_macros.h"
M2C_UNK animationStart__FR11_animHandleb_andler() __asm__("animationStart__FR11_animHandleb");
M2C_UNK func_001FBCF8_andler() __asm__("func_001FBCF8");
M2C_UNK hierSetSwitch__FP11_hierswitchi_andler() __asm__("hierSetSwitch__FP11_hierswitchi");
extern void* D_004FA030_andler __asm__("D_004FA030");
extern s32 D_004FA038_andler __asm__("D_004FA038");

s32 netMsgWorldEventHandler(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    u8 sp[0x10];
    u32* sp10;
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s1;
    s32 var_s3;
    s32 var_s3_2;
    s32 var_v1;
    s32 var_v1_2;
    u32 temp_v1_3;
    u32 temp_v1_4;
    u32* temp_a1_3;
    u32* var_fp;
    u32* var_s6;
    u32* var_s7;
    void* temp_a0;
    void* temp_a1_2;
    void* temp_a2;

    var_fp = NULL;
    var_s7 = NULL;
    var_s6 = NULL;
    var_s1 = 0;
    sp10 = NULL;
    if (arg2 != 0x100) {
        temp_v1 = M2C_FIELD(arg3, s32* , 0);
        if (temp_v1 != 0x28) {
            if (temp_v1 < 0x29) {
                if (temp_v1 != 0x22) {
                    return 0xC0;
                }
                var_s3 = 0;
                var_v1 = 1;
loop_8:
                var_s0 = 7;
                if (var_v1 != 0) {
                    var_a2 = var_s1 * 0x18;
loop_10:
                    temp_a1 = 1 << var_s0;
                    var_s1 += 1;
                    var_s0 -= 1;
                    temp_a0 = M2C_FIELD((D_004FA030_andler + 0x80000 + var_a2), void** , 0x63A0);
                    var_a2 += 0x18;
                    M2C_FIELD(temp_a0, s8* , 0xC) = (s8) ((*(arg3 + 4 + var_s3) & temp_a1) != 0);
                    if (var_s0 >= 0) {
                        if (var_s1 < 0x69) {
                            goto loop_10;
                        }
                    }
                }
                var_s3 += 1;
                temp_v0 = var_s1 < 0x69;
                if (var_s3 < 0xE) {
                    var_v1 = temp_v0;
                    if (temp_v0 == 0) {

                    } else {
                        goto loop_8;
                    }
                }
                goto block_59;
            }
            if (temp_v1 != 0x2A) {
                return 0xC0;
            }
            if (M2C_FIELD(arg3, s32* , 4) != 0) {
                M2C_FIELD(D_004FA030_andler, s32* , 0x9651C) = 1;
                M2C_FIELD(M2C_FIELD(D_004FA030_andler, void** , 0x96580), s8* , 0xC) = 0;
                hierSetSwitch__FP11_hierswitchi_andler(M2C_FIELD(D_004FA030_andler, s32* , 0x96604), 1, (void* )0x90000);
            }
            goto block_59;
        }
        var_s3_2 = 0;
        var_v1_2 = 1;
loop_16:
        var_s0_2 = 7;
        if (var_v1_2 != 0) {
            temp_v1_2 = D_004FA038_andler;
loop_18:
            temp_v0_2 = var_s1 << 6;
            temp_a1_2 = temp_v1_2 + temp_v0_2;
            temp_a2 = M2C_FIELD(temp_a1_2, void** , 0x10);
            if (temp_a2 != NULL) {
                if ((M2C_FIELD((arg3 + var_s3_2), u8* , 4) & (1 << var_s0_2)) > 0) {
                    M2C_FIELD(temp_a1_2, s32* , 4) = -1;
                    M2C_FIELD(temp_a2, s8* , 8) = 1;
                    temp_v1_3 = (u32) *M2C_FIELD((D_004FA038_andler + temp_v0_2), u32** , 0x10) >> 0x12;
                    switch (temp_v1_3) {
                    case 0x179F:
                        M2C_FIELD(D_004FA030_andler, s32* , 0x967B8) = 1;
                        M2C_FIELD(D_004FA030_andler, s32* , 0x967B4) = 1;
                        hierSetSwitch__FP11_hierswitchi_andler(M2C_FIELD(D_004FA030_andler, s32* , 0x96800), 1, temp_a2, 1);
                        break;
                    case 0x177F:
                        func_001FBCF8_andler(sp, 0x271D, 0, 1);
                        animationStart__FR11_animHandleb_andler(sp, 1);
                        break;
                    case 0x1793:
                        M2C_FIELD(D_004FA030_andler, s32* , 0x96658) = 1;
                        break;
                    case 0x178F:
                        M2C_FIELD(D_004FA030_andler, s32* , 0x96664) = 1;
                        break;
                    case 0x1790:
                        M2C_FIELD(D_004FA030_andler, s32* , 0x96668) = 1;
                        break;
                    case 0x1791:
                        M2C_FIELD(D_004FA030_andler, s32* , 0x9666C) = 1;
                        break;
                    case 0x1792:
                        M2C_FIELD(D_004FA030_andler, s32* , 0x96670) = 1;
                        break;
                    case 0x17B3:
                        func_001FBCF8_andler(sp, 0x2909, 0, 1);
                        animationStart__FR11_animHandleb_andler(sp, 1);
                        break;
                    }
                } else {
                default:
                }
                temp_a1_3 = M2C_FIELD((D_004FA038_andler + temp_v0_2), u32** , 0x10);
                temp_v1_4 = (u32) *temp_a1_3 >> 0x12;
                switch (temp_v1_4) {                /* switch 1; irregular */
                case 0x178F:                        /* switch 1 */
                    var_s6 = temp_a1_3;
                    break;
                case 0x1792:                        /* switch 1 */
                    sp10 = temp_a1_3;
                    break;
                case 0x1790:                        /* switch 1 */
                    var_s7 = temp_a1_3;
                    break;
                case 0x1791:                        /* switch 1 */
                    var_fp = temp_a1_3;
                    break;
                }
            }
            var_s1 += 1;
            var_s0_2 -= 1;
            if ((var_s0_2 >= 0) && (var_s1 < 0x5DC)) {
                goto loop_18;
            }
        }
        var_s3_2 += 1;
        temp_v0_3 = var_s1 < 0x5DC;
        if (var_s3_2 < 0xBC) {
            var_v1_2 = temp_v0_3;
            if (temp_v0_3 != 0) {
                goto loop_16;
            }
        }
        if (M2C_FIELD(D_004FA030_andler, s32* , 0x96658) != 0) {
            if (var_s6 != NULL) {
                M2C_FIELD(var_s6, s8* , 8) = 1;
            }
            if (var_s7 != NULL) {
                M2C_FIELD(var_s7, s8* , 8) = 1;
            }
            if (var_fp != NULL) {
                M2C_FIELD(var_fp, s8* , 8) = 1;
            }
            if (sp10 != NULL) {
                M2C_FIELD(sp10, s8* , 8) = 1;
            }
        }
        /* Duplicate return node #60. Try simplifying control flow for better match */
        return 0xC0;
    }
block_59:
    return 0xC0;
}
//@@ netMsgWorldEventHandler m2c2
#include "m2c_macros.h"
M2C_UNK animationStart__FR11_animHandleb_andler() __asm__("animationStart__FR11_animHandleb");
M2C_UNK func_001FBCF8_andler() __asm__("func_001FBCF8");
M2C_UNK hierSetSwitch__FP11_hierswitchi_andler() __asm__("hierSetSwitch__FP11_hierswitchi");
extern void* D_004FA030_andler __asm__("D_004FA030");
extern s32 D_004FA038_andler __asm__("D_004FA038");

s32 netMsgWorldEventHandler(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    u8 sp[0x8];
    u32* sp10;
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s1;
    s32 var_s3;
    s32 var_s3_2;
    s32 var_v1;
    s32 var_v1_2;
    u32 temp_v1_3;
    u32 temp_v1_4;
    u32* temp_a1_3;
    u32* var_fp;
    u32* var_s6;
    u32* var_s7;
    void* temp_a0;
    void* temp_a1_2;
    void* temp_a2;

    var_fp = NULL;
    var_s7 = NULL;
    var_s6 = NULL;
    var_s1 = 0;
    sp10 = NULL;
    if (arg2 != 0x100) {
        temp_v1 = M2C_FIELD(arg3, s32* , 0);
        if (temp_v1 != 0x28) {
            if (temp_v1 < 0x29) {
                if (temp_v1 != 0x22) {
                    return 0xC0;
                }
                var_s3 = 0;
                var_v1 = 1;
loop_8:
                var_s0 = 7;
                if (var_v1 != 0) {
                    var_a2 = var_s1 * 0x18;
loop_10:
                    temp_a1 = 1 << var_s0;
                    var_s1 += 1;
                    var_s0 -= 1;
                    temp_a0 = M2C_FIELD((D_004FA030_andler + 0x80000 + var_a2), void** , 0x63A0);
                    var_a2 += 0x18;
                    M2C_FIELD(temp_a0, s8* , 0xC) = (s8) ((*(arg3 + 4 + var_s3) & temp_a1) != 0);
                    if (var_s0 >= 0) {
                        if (var_s1 < 0x69) {
                            goto loop_10;
                        }
                    }
                }
                var_s3 += 1;
                temp_v0 = var_s1 < 0x69;
                if (var_s3 < 0xE) {
                    var_v1 = temp_v0;
                    if (temp_v0 == 0) {

                    } else {
                        goto loop_8;
                    }
                }
                goto block_59;
            }
            if (temp_v1 != 0x2A) {
                return 0xC0;
            }
            if (M2C_FIELD(arg3, s32* , 4) != 0) {
                M2C_FIELD(D_004FA030_andler, s32* , 0x9651C) = 1;
                M2C_FIELD(M2C_FIELD(D_004FA030_andler, void** , 0x96580), s8* , 0xC) = 0;
                hierSetSwitch__FP11_hierswitchi_andler(M2C_FIELD(D_004FA030_andler, s32* , 0x96604), 1, (void* )0x90000);
            }
            goto block_59;
        }
        var_s3_2 = 0;
        var_v1_2 = 1;
loop_16:
        var_s0_2 = 7;
        if (var_v1_2 != 0) {
            temp_v1_2 = D_004FA038_andler;
loop_18:
            temp_v0_2 = var_s1 << 6;
            temp_a1_2 = temp_v1_2 + temp_v0_2;
            temp_a2 = M2C_FIELD(temp_a1_2, void** , 0x10);
            if (temp_a2 != NULL) {
                if ((M2C_FIELD((arg3 + var_s3_2), u8* , 4) & (1 << var_s0_2)) > 0) {
                    M2C_FIELD(temp_a1_2, s32* , 4) = -1;
                    M2C_FIELD(temp_a2, s8* , 8) = 1;
                    temp_v1_3 = (u32) *M2C_FIELD((D_004FA038_andler + temp_v0_2), u32** , 0x10) >> 0x12;
                    switch (temp_v1_3) {
                    case 0x179F:
                        M2C_FIELD(D_004FA030_andler, s32* , 0x967B8) = 1;
                        M2C_FIELD(D_004FA030_andler, s32* , 0x967B4) = 1;
                        hierSetSwitch__FP11_hierswitchi_andler(M2C_FIELD(D_004FA030_andler, s32* , 0x96800), 1, temp_a2, 1);
                        break;
                    case 0x177F:
                        func_001FBCF8_andler(sp, 0x271D, 0, 1);
                        animationStart__FR11_animHandleb_andler(sp, 1);
                        break;
                    case 0x1793:
                        M2C_FIELD(D_004FA030_andler, s32* , 0x96658) = 1;
                        break;
                    case 0x178F:
                        M2C_FIELD(D_004FA030_andler, s32* , 0x96664) = 1;
                        break;
                    case 0x1790:
                        M2C_FIELD(D_004FA030_andler, s32* , 0x96668) = 1;
                        break;
                    case 0x1791:
                        M2C_FIELD(D_004FA030_andler, s32* , 0x9666C) = 1;
                        break;
                    case 0x1792:
                        M2C_FIELD(D_004FA030_andler, s32* , 0x96670) = 1;
                        break;
                    case 0x17B3:
                        func_001FBCF8_andler(sp, 0x2909, 0, 1);
                        animationStart__FR11_animHandleb_andler(sp, 1);
                        break;
                    }
                } else {
                default:
                }
                temp_a1_3 = M2C_FIELD((D_004FA038_andler + temp_v0_2), u32** , 0x10);
                temp_v1_4 = (u32) *temp_a1_3 >> 0x12;
                switch (temp_v1_4) {                /* switch 1; irregular */
                case 0x178F:                        /* switch 1 */
                    var_s6 = temp_a1_3;
                    break;
                case 0x1792:                        /* switch 1 */
                    sp10 = temp_a1_3;
                    break;
                case 0x1790:                        /* switch 1 */
                    var_s7 = temp_a1_3;
                    break;
                case 0x1791:                        /* switch 1 */
                    var_fp = temp_a1_3;
                    break;
                }
            }
            var_s1 += 1;
            var_s0_2 -= 1;
            if ((var_s0_2 >= 0) && (var_s1 < 0x5DC)) {
                goto loop_18;
            }
        }
        var_s3_2 += 1;
        temp_v0_3 = var_s1 < 0x5DC;
        if (var_s3_2 < 0xBC) {
            var_v1_2 = temp_v0_3;
            if (temp_v0_3 != 0) {
                goto loop_16;
            }
        }
        if (M2C_FIELD(D_004FA030_andler, s32* , 0x96658) != 0) {
            if (var_s6 != NULL) {
                M2C_FIELD(var_s6, s8* , 8) = 1;
            }
            if (var_s7 != NULL) {
                M2C_FIELD(var_s7, s8* , 8) = 1;
            }
            if (var_fp != NULL) {
                M2C_FIELD(var_fp, s8* , 8) = 1;
            }
            if (sp10 != NULL) {
                M2C_FIELD(sp10, s8* , 8) = 1;
            }
        }
        /* Duplicate return node #60. Try simplifying control flow for better match */
        return 0xC0;
    }
block_59:
    return 0xC0;
}
//@@ netMsgWorldEventHandler m2c3
#include "m2c_macros.h"
M2C_UNK animationStart__FR11_animHandleb_andler() __asm__("animationStart__FR11_animHandleb");
M2C_UNK func_001FBCF8_andler() __asm__("func_001FBCF8");
M2C_UNK hierSetSwitch__FP11_hierswitchi_andler() __asm__("hierSetSwitch__FP11_hierswitchi");
extern void* D_004FA030_andler __asm__("D_004FA030");
extern s32 D_004FA038_andler __asm__("D_004FA038");

s32 netMsgWorldEventHandler(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    u8 sp[0x4];
    u32* sp10;
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s1;
    s32 var_s3;
    s32 var_s3_2;
    s32 var_v1;
    s32 var_v1_2;
    u32 temp_v1_3;
    u32 temp_v1_4;
    u32* temp_a1_3;
    u32* var_fp;
    u32* var_s6;
    u32* var_s7;
    void* temp_a0;
    void* temp_a1_2;
    void* temp_a2;

    var_fp = NULL;
    var_s7 = NULL;
    var_s6 = NULL;
    var_s1 = 0;
    sp10 = NULL;
    if (arg2 != 0x100) {
        temp_v1 = M2C_FIELD(arg3, s32* , 0);
        if (temp_v1 != 0x28) {
            if (temp_v1 < 0x29) {
                if (temp_v1 != 0x22) {
                    return 0xC0;
                }
                var_s3 = 0;
                var_v1 = 1;
loop_8:
                var_s0 = 7;
                if (var_v1 != 0) {
                    var_a2 = var_s1 * 0x18;
loop_10:
                    temp_a1 = 1 << var_s0;
                    var_s1 += 1;
                    var_s0 -= 1;
                    temp_a0 = M2C_FIELD((D_004FA030_andler + 0x80000 + var_a2), void** , 0x63A0);
                    var_a2 += 0x18;
                    M2C_FIELD(temp_a0, s8* , 0xC) = (s8) ((*(arg3 + 4 + var_s3) & temp_a1) != 0);
                    if (var_s0 >= 0) {
                        if (var_s1 < 0x69) {
                            goto loop_10;
                        }
                    }
                }
                var_s3 += 1;
                temp_v0 = var_s1 < 0x69;
                if (var_s3 < 0xE) {
                    var_v1 = temp_v0;
                    if (temp_v0 == 0) {

                    } else {
                        goto loop_8;
                    }
                }
                goto block_59;
            }
            if (temp_v1 != 0x2A) {
                return 0xC0;
            }
            if (M2C_FIELD(arg3, s32* , 4) != 0) {
                M2C_FIELD(D_004FA030_andler, s32* , 0x9651C) = 1;
                M2C_FIELD(M2C_FIELD(D_004FA030_andler, void** , 0x96580), s8* , 0xC) = 0;
                hierSetSwitch__FP11_hierswitchi_andler(M2C_FIELD(D_004FA030_andler, s32* , 0x96604), 1, (void* )0x90000);
            }
            goto block_59;
        }
        var_s3_2 = 0;
        var_v1_2 = 1;
loop_16:
        var_s0_2 = 7;
        if (var_v1_2 != 0) {
            temp_v1_2 = D_004FA038_andler;
loop_18:
            temp_v0_2 = var_s1 << 6;
            temp_a1_2 = temp_v1_2 + temp_v0_2;
            temp_a2 = M2C_FIELD(temp_a1_2, void** , 0x10);
            if (temp_a2 != NULL) {
                if ((M2C_FIELD((arg3 + var_s3_2), u8* , 4) & (1 << var_s0_2)) > 0) {
                    M2C_FIELD(temp_a1_2, s32* , 4) = -1;
                    M2C_FIELD(temp_a2, s8* , 8) = 1;
                    temp_v1_3 = (u32) *M2C_FIELD((D_004FA038_andler + temp_v0_2), u32** , 0x10) >> 0x12;
                    switch (temp_v1_3) {
                    case 0x179F:
                        M2C_FIELD(D_004FA030_andler, s32* , 0x967B8) = 1;
                        M2C_FIELD(D_004FA030_andler, s32* , 0x967B4) = 1;
                        hierSetSwitch__FP11_hierswitchi_andler(M2C_FIELD(D_004FA030_andler, s32* , 0x96800), 1, temp_a2, 1);
                        break;
                    case 0x177F:
                        func_001FBCF8_andler(sp, 0x271D, 0, 1);
                        animationStart__FR11_animHandleb_andler(sp, 1);
                        break;
                    case 0x1793:
                        M2C_FIELD(D_004FA030_andler, s32* , 0x96658) = 1;
                        break;
                    case 0x178F:
                        M2C_FIELD(D_004FA030_andler, s32* , 0x96664) = 1;
                        break;
                    case 0x1790:
                        M2C_FIELD(D_004FA030_andler, s32* , 0x96668) = 1;
                        break;
                    case 0x1791:
                        M2C_FIELD(D_004FA030_andler, s32* , 0x9666C) = 1;
                        break;
                    case 0x1792:
                        M2C_FIELD(D_004FA030_andler, s32* , 0x96670) = 1;
                        break;
                    case 0x17B3:
                        func_001FBCF8_andler(sp, 0x2909, 0, 1);
                        animationStart__FR11_animHandleb_andler(sp, 1);
                        break;
                    }
                } else {
                default:
                }
                temp_a1_3 = M2C_FIELD((D_004FA038_andler + temp_v0_2), u32** , 0x10);
                temp_v1_4 = (u32) *temp_a1_3 >> 0x12;
                switch (temp_v1_4) {                /* switch 1; irregular */
                case 0x178F:                        /* switch 1 */
                    var_s6 = temp_a1_3;
                    break;
                case 0x1792:                        /* switch 1 */
                    sp10 = temp_a1_3;
                    break;
                case 0x1790:                        /* switch 1 */
                    var_s7 = temp_a1_3;
                    break;
                case 0x1791:                        /* switch 1 */
                    var_fp = temp_a1_3;
                    break;
                }
            }
            var_s1 += 1;
            var_s0_2 -= 1;
            if ((var_s0_2 >= 0) && (var_s1 < 0x5DC)) {
                goto loop_18;
            }
        }
        var_s3_2 += 1;
        temp_v0_3 = var_s1 < 0x5DC;
        if (var_s3_2 < 0xBC) {
            var_v1_2 = temp_v0_3;
            if (temp_v0_3 != 0) {
                goto loop_16;
            }
        }
        if (M2C_FIELD(D_004FA030_andler, s32* , 0x96658) != 0) {
            if (var_s6 != NULL) {
                M2C_FIELD(var_s6, s8* , 8) = 1;
            }
            if (var_s7 != NULL) {
                M2C_FIELD(var_s7, s8* , 8) = 1;
            }
            if (var_fp != NULL) {
                M2C_FIELD(var_fp, s8* , 8) = 1;
            }
            if (sp10 != NULL) {
                M2C_FIELD(sp10, s8* , 8) = 1;
            }
        }
        /* Duplicate return node #60. Try simplifying control flow for better match */
        return 0xC0;
    }
block_59:
    return 0xC0;
}
//@@ netMsgRosterHandler m2c0
#include "m2c_macros.h"
M2C_UNK strcpy_andler() __asm__("strcpy");
extern M2C_UNK D_003156C0_andler __asm__("D_003156C0");
extern M2C_UNK D_00318416_andler __asm__("D_00318416");

s32 netMsgRosterHandler(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_UNK* var_a2;
    s128 var_t1;
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_fp;
    s32* var_s1;
    s32* var_s2;
    s32* var_s3;
    s32* var_s4;
    s32* var_s5;
    s32* var_s6;
    s32* var_s7;
    void* var_s0;
    void* var_t0;

    if (arg2 != 0x100) {
        var_fp = arg3;
        var_t1 = 0;
        var_a2 = &D_00318416_andler;
        var_t0 = &D_00318416_andler + 0x272;
        var_s7 = arg3 + 0x2C;
        var_s6 = arg3 + 0x28;
        var_s5 = arg3 + 0x1C;
        var_s4 = arg3 + 0x18;
        var_s3 = arg3 + 0x20;
        var_s2 = arg3 + 0x24;
        var_s1 = arg3 + 0x14;
        var_s0 = &D_00318416_andler + 0x252;
        do {
            temp_a1 = var_fp;
            var_fp += 0x30;
            strcpy_andler((s128) var_a2, temp_a1, (s128) var_a2, (s128) var_t0, var_t1);
            temp_v0 = *var_s1;
            var_s1 += 0x30;
            M2C_FIELD(var_s0, s32* , -0xA0) = temp_v0;
            var_t1 = subroutine_arg8 + 1;
            var_a2 = subroutine_arg0 + 0x14;
            temp_v0_2 = *var_s2;
            var_s2 += 0x30;
            M2C_FIELD(var_s0, s32* , -0x20) = temp_v0_2;
            temp_v1 = *var_s3;
            var_s3 += 0x30;
            M2C_FIELD(var_s0, s32* , -0x60) = temp_v1;
            temp_v0_3 = *var_s4;
            var_s4 += 0x30;
            M2C_FIELD(var_s0, s32* , -0x80) = temp_v0_3;
            temp_v1_2 = *var_s5;
            var_s5 += 0x30;
            M2C_FIELD(var_s0, s32* , -0x40) = temp_v1_2;
            temp_v0_4 = *var_s6;
            var_s6 += 0x30;
            M2C_FIELD(var_s0, s32* , 0) = temp_v0_4;
            var_s0 += 4;
            temp_v0_5 = *var_s7;
            var_s7 += 0x30;
            *subroutine_arg4 = temp_v0_5;
            var_t0 = subroutine_arg4 + 4;
        } while (var_t1 < 8);
        M2C_FIELD(&D_003156C0_andler, s32* , 0x3230) = 1;
    }
    return 0x180;
}
//@@ func_00168B60 m2c0
#include "m2c_macros.h"
M2C_UNK func_00171B78_168B60() __asm__("func_00171B78");
s32 func_001734B8_168B60() __asm__("func_001734B8");
M2C_UNK func_00174988_168B60() __asm__("func_00174988");
M2C_UNK printf_168B60() __asm__("printf");
M2C_UNK strcpy_168B60() __asm__("strcpy");
extern M2C_UNK D_003156C0_168B60 __asm__("D_003156C0");
extern M2C_UNK D_003156D0_168B60 __asm__("D_003156D0");

void func_00168B60(s32 arg0, s32 arg1, M2C_UNK arg2) {
    if (arg1 != 0x100) {
        if (arg0 == M2C_FIELD(&D_003156C0_168B60, s32* , 0x2CF0)) {
            if (M2C_FIELD(&D_003156C0_168B60, s32* , 0x1BB4) > 0) {
                if (func_001734B8_168B60(&D_003156C0_168B60) != 0) {
                    func_00174988_168B60(&D_003156C0_168B60, arg1);
                }
            }
            *((arg1 * 0x220) + &D_003156D0_168B60) = arg1;
            strcpy_168B60((arg1 * 0x220) + &D_003156D0_168B60 + 0xC4, arg2);
            printf_168B60("Client %d Connecting on Connection %d from IP %s\n", arg1, arg0, arg2);
            func_00171B78_168B60(&D_003156D0_168B60 - 0x10, arg1);
        }
    }
}
//@@ func_00168C30 m2c0
#include "m2c_macros.h"
M2C_UNK func_0016EF90_168C30() __asm__("func_0016EF90");
M2C_UNK func_0016F1C8_168C30() __asm__("func_0016F1C8");
s32 func_001733F8_168C30() __asm__("func_001733F8");
s32 func_001734B8_168C30() __asm__("func_001734B8");
M2C_UNK func_00173500_168C30() __asm__("func_00173500");
M2C_UNK func_00174988_168C30() __asm__("func_00174988");
s32 func_00176B10_168C30() __asm__("func_00176B10");
M2C_UNK func_00176CC8_168C30() __asm__("func_00176CC8");
M2C_UNK printf_168C30() __asm__("printf");
extern M2C_UNK D_003156C0_168C30 __asm__("D_003156C0");
extern M2C_UNK D_004E6A00_168C30 __asm__("D_004E6A00");
extern void* D_004FA030_168C30 __asm__("D_004FA030");

void func_00168C30(s32 arg0, s32 arg1) {
    void* temp_v1;
    void* temp_v1_2;

    if ((arg1 != 0x100) && (arg0 == M2C_FIELD(&D_003156C0_168C30, s32* , 0x2CF0))) {
        func_0016EF90_168C30(&D_003156C0_168C30);
        if ((func_001733F8_168C30(&D_003156C0_168C30) == 1) && (func_00176B10_168C30(&D_003156C0_168C30, 1) <= 0)) {
            printf_168C30(&D_004E6A00_168C30);
            func_00176CC8_168C30(&D_003156C0_168C30);
        } else if (func_001734B8_168C30(&D_003156C0_168C30) != 0) {
            func_00174988_168C30(&D_003156C0_168C30, -1);
            M2C_FIELD(&D_003156C0_168C30, s32* , 0x2EE4) = 0;
            if (func_001733F8_168C30(&D_003156C0_168C30) == 2) {
                temp_v1 = M2C_FIELD(D_004FA030_168C30, void** , 0x9E690);
                if (temp_v1 != NULL) {
                    M2C_FIELD(temp_v1, s32* , 0x20C0) = -1;
                    M2C_FIELD(M2C_FIELD(D_004FA030_168C30, void** , 0x9E690), s32* , 0x20B4) = 4;
                }
                temp_v1_2 = M2C_FIELD(D_004FA030_168C30, void** , 0x9E694);
                if (temp_v1_2 != NULL) {
                    M2C_FIELD(temp_v1_2, s32* , 0x20C0) = -1;
                    M2C_FIELD(M2C_FIELD(D_004FA030_168C30, void** , 0x9E694), s32* , 0x20B4) = 4;
                }
            }
        } else if (func_001733F8_168C30(&D_003156C0_168C30) == 1) {
            func_00173500_168C30(&D_003156C0_168C30);
        }
        func_0016F1C8_168C30(&D_003156C0_168C30, arg1);
        func_0016EF90_168C30(&D_003156C0_168C30, arg1);
    }
}
//@@ func_00168DE0 m2c0
#include "m2c_macros.h"
M2C_UNK func_00170DF0_168DE0() __asm__("func_00170DF0");
s32 func_001734B8_168DE0() __asm__("func_001734B8");
M2C_UNK func_00174BF0_168DE0() __asm__("func_00174BF0");
s8 func_00176B10_168DE0() __asm__("func_00176B10");
s32 netGetMyClientIndex_168DE0() __asm__("netGetMyClientIndex");
extern M2C_UNK D_003156C0_168DE0 __asm__("D_003156C0");
extern M2C_UNK D_003186FC_168DE0 __asm__("D_003186FC");
extern void* D_004FA030_168DE0 __asm__("D_004FA030");
extern void* D_004FA03C_168DE0 __asm__("D_004FA03C");

void func_00168DE0(s32 arg0, s32 arg1) {
    s32 temp_v0_2;
    s32 var_a1;
    s32 var_a1_2;
    s32* var_v0;
    void* temp_v0;
    void* temp_v1;
    void* temp_v1_2;
    void** var_v1;

    if (arg1 != 0x100) {
        if (arg0 == M2C_FIELD(&D_003156C0_168DE0, s32* , 0x2CF0)) {
            M2C_FIELD(M2C_FIELD(&D_003156C0_168DE0, void** , 0x3148), s8* , 0x24) = func_00176B10_168DE0(&D_003156C0_168DE0, 0);
            if (func_001734B8_168DE0(&D_003156C0_168DE0) != 0) {
                M2C_FIELD(&D_003156C0_168DE0, s32* , 0x307C) = netGetMyClientIndex_168DE0(&D_003156C0_168DE0);
                temp_v1 = M2C_FIELD(D_004FA030_168DE0, void** , 0x9E690);
                if (temp_v1 != NULL) {
                    M2C_FIELD(temp_v1, s32* , 0x20C0) = -1;
                }
                temp_v1_2 = M2C_FIELD(D_004FA030_168DE0, void** , 0x9E694);
                if (temp_v1_2 != NULL) {
                    M2C_FIELD(temp_v1_2, s32* , 0x20C0) = -1;
                }
                func_00174BF0_168DE0(&D_003156C0_168DE0);
                func_00170DF0_168DE0(&D_003156C0_168DE0, M2C_FIELD(D_004FA03C_168DE0, s32* , 0x1A3AC));
                var_v0 = &D_003156C0_168DE0 + 0x3058;
                var_a1 = 7;
                do {
                    *var_v0 = 0;
                    var_a1 -= 1;
                    var_v0 -= 4;
                } while (var_a1 >= 0);
                var_v1 = D_004FA030_168DE0 + 0x20D8;
                var_a1_2 = 7;
                do {
                    temp_v0 = *var_v1;
                    if (temp_v0 != NULL) {
                        temp_v0_2 = M2C_FIELD(temp_v0, s32* , 4);
                        if (temp_v0_2 != -1) {
                            *((temp_v0_2 * 4) + &D_003186FC_168DE0) = 1;
                        }
                    }
                    var_a1_2 -= 1;
                    var_v1 += 0x31B0;
                } while (var_a1_2 >= 0);
            }
        }
    }
}
//@@ func_00168F30 m2c0
#include "m2c_macros.h"
M2C_UNK dmeSendMsg_168F30() __asm__("dmeSendMsg");
M2C_UNK func_002665A0_168F30() __asm__("func_002665A0");
s32 strcmp_168F30() __asm__("strcmp");
M2C_UNK strcpy_168F30() __asm__("strcpy");
extern M2C_UNK D_004F9D10_168F30 __asm__("D_004F9D10");
extern s32 D_004F9D94_168F30 __asm__("D_004F9D94");

void func_00168F30(s32 arg0, s32 arg1) {
    u8 sp[0x70];
    s32 sp10;
    M2C_UNK sp44;
    s32 sp54;

    if (strcmp_168F30(&D_004F9D10_168F30, arg0) != 0) {
        func_002665A0_168F30(sp, arg0);
        sp10 = 1;
        strcpy_168F30(&sp44, arg0);
        sp54 = arg1;
        dmeSendMsg_168F30(0, sp, 2, D_004F9D94_168F30);
    }
}
//@@ func_00168F30 m2c1
#include "m2c_macros.h"
M2C_UNK dmeSendMsg_168F30() __asm__("dmeSendMsg");
M2C_UNK func_002665A0_168F30() __asm__("func_002665A0");
s32 strcmp_168F30() __asm__("strcmp");
M2C_UNK strcpy_168F30() __asm__("strcpy");
extern M2C_UNK D_004F9D10_168F30 __asm__("D_004F9D10");
extern s32 D_004F9D94_168F30 __asm__("D_004F9D94");

void func_00168F30(s32 arg0, s32 arg1) {
    u8 sp[0x60];
    s32 sp10;
    M2C_UNK sp44;
    s32 sp54;

    if (strcmp_168F30(&D_004F9D10_168F30, arg0) != 0) {
        func_002665A0_168F30(sp, arg0);
        sp10 = 1;
        strcpy_168F30(&sp44, arg0);
        sp54 = arg1;
        dmeSendMsg_168F30(0, sp, 2, D_004F9D94_168F30);
    }
}
//@@ func_00168F30 m2c2
#include "m2c_macros.h"
M2C_UNK dmeSendMsg_168F30() __asm__("dmeSendMsg");
M2C_UNK func_002665A0_168F30() __asm__("func_002665A0");
s32 strcmp_168F30() __asm__("strcmp");
M2C_UNK strcpy_168F30() __asm__("strcpy");
extern M2C_UNK D_004F9D10_168F30 __asm__("D_004F9D10");
extern s32 D_004F9D94_168F30 __asm__("D_004F9D94");

void func_00168F30(s32 arg0, s32 arg1) {
    u8 sp[0x50];
    s32 sp10;
    M2C_UNK sp44;
    s32 sp54;

    if (strcmp_168F30(&D_004F9D10_168F30, arg0) != 0) {
        func_002665A0_168F30(sp, arg0);
        sp10 = 1;
        strcpy_168F30(&sp44, arg0);
        sp54 = arg1;
        dmeSendMsg_168F30(0, sp, 2, D_004F9D94_168F30);
    }
}
//@@ func_00168F30 m2c3
#include "m2c_macros.h"
M2C_UNK dmeSendMsg_168F30() __asm__("dmeSendMsg");
M2C_UNK func_002665A0_168F30() __asm__("func_002665A0");
s32 strcmp_168F30() __asm__("strcmp");
M2C_UNK strcpy_168F30() __asm__("strcpy");
extern M2C_UNK D_004F9D10_168F30 __asm__("D_004F9D10");
extern s32 D_004F9D94_168F30 __asm__("D_004F9D94");

void func_00168F30(s32 arg0, s32 arg1) {
    u8 sp[0x40];
    s32 sp10;
    M2C_UNK sp44;
    s32 sp54;

    if (strcmp_168F30(&D_004F9D10_168F30, arg0) != 0) {
        func_002665A0_168F30(sp, arg0);
        sp10 = 1;
        strcpy_168F30(&sp44, arg0);
        sp54 = arg1;
        dmeSendMsg_168F30(0, sp, 2, D_004F9D94_168F30);
    }
}
//@@ func_00168F30 m2c4
#include "m2c_macros.h"
M2C_UNK dmeSendMsg_168F30() __asm__("dmeSendMsg");
M2C_UNK func_002665A0_168F30() __asm__("func_002665A0");
s32 strcmp_168F30() __asm__("strcmp");
M2C_UNK strcpy_168F30() __asm__("strcpy");
extern M2C_UNK D_004F9D10_168F30 __asm__("D_004F9D10");
extern s32 D_004F9D94_168F30 __asm__("D_004F9D94");

void func_00168F30(s32 arg0, s32 arg1) {
    u8 sp[0x30];
    s32 sp10;
    M2C_UNK sp44;
    s32 sp54;

    if (strcmp_168F30(&D_004F9D10_168F30, arg0) != 0) {
        func_002665A0_168F30(sp, arg0);
        sp10 = 1;
        strcpy_168F30(&sp44, arg0);
        sp54 = arg1;
        dmeSendMsg_168F30(0, sp, 2, D_004F9D94_168F30);
    }
}
//@@ func_00168F30 m2c5
#include "m2c_macros.h"
M2C_UNK dmeSendMsg_168F30() __asm__("dmeSendMsg");
M2C_UNK func_002665A0_168F30() __asm__("func_002665A0");
s32 strcmp_168F30() __asm__("strcmp");
M2C_UNK strcpy_168F30() __asm__("strcpy");
extern M2C_UNK D_004F9D10_168F30 __asm__("D_004F9D10");
extern s32 D_004F9D94_168F30 __asm__("D_004F9D94");

void func_00168F30(s32 arg0, s32 arg1) {
    u8 sp[0x20];
    s32 sp10;
    M2C_UNK sp44;
    s32 sp54;

    if (strcmp_168F30(&D_004F9D10_168F30, arg0) != 0) {
        func_002665A0_168F30(sp, arg0);
        sp10 = 1;
        strcpy_168F30(&sp44, arg0);
        sp54 = arg1;
        dmeSendMsg_168F30(0, sp, 2, D_004F9D94_168F30);
    }
}
//@@ func_00168FB8 m2c0
#include "m2c_macros.h"
s32 strcmp_168FB8() __asm__("strcmp");
extern M2C_UNK D_003156C0_168FB8 __asm__("D_003156C0");

void func_00168FB8(s32 arg0, M2C_UNK arg1, s32 arg2) {
    M2C_UNK* var_s0;
    void* var_s1;

    if (arg0 == 0) {
        var_s0 = &D_003156C0_168FB8;
        var_s1 = &D_003156C0_168FB8 + 0xD4;
        do {
            if ((M2C_FIELD(var_s0, s32* , 0x10) != -1) && (strcmp_168FB8(var_s1, arg1) == 0)) {
                M2C_FIELD(var_s0, s32* , 0xCC) = arg2;
            }
            var_s0 += 0x220;
            var_s1 += 0x220;
        } while ((s32) var_s0 < (s32) (&D_003156C0_168FB8 + 0x1100));
    }
}
//@@ func_00169050 m2c0
#include "m2c_macros.h"
s32 strcmp_169050() __asm__("strcmp");
extern M2C_UNK D_003156C0_169050 __asm__("D_003156C0");

void func_00169050(s32 arg0, M2C_UNK arg1, s32 arg2) {
    s32 var_s1;
    s32* var_s0;
    void* var_s2;

    if (arg0 == 0) {
        var_s1 = 0;
        if (M2C_FIELD(&D_003156C0_169050, s32* , 0x1980) > 0) {
            var_s0 = &D_003156C0_169050 + 0x1588;
            var_s2 = &D_003156C0_169050 + 0x1560;
            do {
                if (strcmp_169050(var_s2, arg1) == 0) {
                    *var_s0 = arg2;
                }
                var_s1 += 1;
                var_s0 += 0x5C;
                var_s2 += 0x5C;
            } while (var_s1 < M2C_FIELD(&D_003156C0_169050, s32* , 0x1980));
        }
    }
}
//@@ func_001690F0 m2c0
#include "m2c_macros.h"
M2C_UNK func_0013A7B8_1690F0() __asm__("func_0013A7B8");
s32 func_00174268_1690F0() __asm__("func_00174268");
M2C_UNK func_001FDE10_1690F0() __asm__("func_001FDE10");
extern M2C_UNK D_003156C0_1690F0 __asm__("D_003156C0");
extern s32 D_004FA030_1690F0 __asm__("D_004FA030");

s32 func_001690F0(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s0;
    s32 temp_s1;
    s32 var_s1;
    s32 var_v0;
    u32 var_v0_2;
    void* temp_v0;
    void* temp_v0_2;
    void* temp_v1;

    var_v0 = *(D_004FA030_1690F0 + 0x9E690 + (arg1 * 4));
    if (var_v0 == 0) {
        if (arg2 != -1) {
            var_s1 = func_00174268_1690F0(&D_003156C0_1690F0, arg2, D_004FA030_1690F0) - 1;
            goto block_12;
        }
        temp_v1 = D_004FA030_1690F0 + 0x31B0;
        var_s1 = 1;
        if (M2C_FIELD(temp_v1, s32* , 0x20F4) == arg0) {
            var_v0_2 = 0;
            if (M2C_FIELD(temp_v1, s32* , 0x20C4) != arg2) {
                goto loop_7;
            }
        } else {
loop_7:
            var_s1 += 1;
            if (var_s1 < 8) {
                temp_v0 = (var_s1 * 0x31B0) + D_004FA030_1690F0;
                if ((M2C_FIELD(temp_v0, s32* , 0x20F4) == arg0) && (M2C_FIELD(temp_v0, s32* , 0x20C4) == -1)) {

                } else {
                    goto loop_7;
                }
            }
block_12:
            var_v0_2 = var_s1 - 1;
        }
        temp_s1 = (var_v0_2 >= 7U) ? 7 : var_s1;
        func_0013A7B8_1690F0(D_004FA030_1690F0, -1, arg0, temp_s1);
        temp_s0 = temp_s1 * 0x31B0;
        temp_v0_2 = D_004FA030_1690F0 + temp_s0;
        M2C_FIELD(temp_v0_2, s32* , 0x20B4) = 5;
        M2C_FIELD(temp_v0_2, s32* , 0x20C0) = arg2;
        func_001FDE10_1690F0(1, temp_s1 + 1);
        var_v0 = D_004FA030_1690F0 + temp_s0;
    }
    return var_v0;
}
//@@ func_00169230 m2c0
#include "m2c_macros.h"
M2C_UNK func_0013A7B8_169230() __asm__("func_0013A7B8");
M2C_UNK func_0016F058_169230() __asm__("func_0016F058");
s32 func_00174268_169230() __asm__("func_00174268");
extern M2C_UNK D_003156C0_169230 __asm__("D_003156C0");
extern s32 D_004FA030_169230 __asm__("D_004FA030");

void* func_00169230(s32 arg0) {
    u32 temp_a1;
    void* temp_s0;
    void* temp_s2;
    void* var_v0;

    temp_s2 = (arg0 * 0x220) + &D_003156C0_169230;
    var_v0 = M2C_FIELD(temp_s2, void** , 0xB0);
    if (var_v0 == NULL) {
        temp_a1 = func_00174268_169230(&D_003156C0_169230, arg0) - 1;
        if (temp_a1 < 8U) {
            temp_s0 = *(D_004FA030_169230 + 0x9E670 + (temp_a1 * 4));
            func_0013A7B8_169230(D_004FA030_169230, temp_a1, M2C_FIELD(temp_s0, s32* , 0x20F4), M2C_FIELD(temp_s0, s32* , 0x20F0));
            M2C_FIELD(temp_s0, s32* , 0x590) = 0;
            M2C_FIELD(temp_s2, void** , 0xB0) = temp_s0;
            M2C_FIELD(temp_s0, s32* , 0x20C0) = arg0;
            M2C_FIELD(M2C_FIELD(temp_s2, void** , 0xB0), s32* , 0x20B4) = 2;
            func_0016F058_169230(&D_003156C0_169230, arg0, M2C_FIELD(&D_003156C0_169230, s32* , 0x2CF0));
            var_v0 = temp_s0;
        } else {
            var_v0 = NULL;
        }
    }
    return var_v0;
}
//@@ netObjDestroyCB m2c0
#include "m2c_macros.h"
M2C_UNK AddMessage__3Hudiii_troyCB() __asm__("AddMessage__3Hudiii");
M2C_UNK func_0011B308_troyCB() __asm__("func_0011B308");
M2C_UNK func_0013EED0_troyCB() __asm__("func_0013EED0");
M2C_UNK func_0014EDA0_troyCB() __asm__("func_0014EDA0");
M2C_UNK func_0016F1C8_troyCB() __asm__("func_0016F1C8");
s32 func_001734B8_troyCB() __asm__("func_001734B8");
M2C_UNK func_00174D78_troyCB() __asm__("func_00174D78");
M2C_UNK func_001759D8_troyCB() __asm__("func_001759D8");
M2C_UNK func_00181AA8_troyCB() __asm__("func_00181AA8");
M2C_UNK func_001A9240_troyCB() __asm__("func_001A9240");
M2C_UNK func_00264A60_troyCB() __asm__("func_00264A60");
void* netGetDmeTime_troyCB() __asm__("netGetDmeTime");
M2C_UNK sprintf_troyCB() __asm__("sprintf");
extern M2C_UNK D_003156C0_troyCB __asm__("D_003156C0");
extern s32 D_004F9CA4_troyCB __asm__("D_004F9CA4");
extern s32 D_004F9CAC_troyCB __asm__("D_004F9CAC");
extern s32 D_004F9D18_troyCB __asm__("D_004F9D18");
extern void* D_004FA030_troyCB __asm__("D_004FA030");

void netObjDestroyCB(s32 arg0, s32 arg1) {
    u8 sp[0x90];
    M2C_UNK sp80;
    f32* temp_a0_2;
    f32* temp_a0_3;
    f32* var_t0;
    s32 temp_a1;
    s32 temp_a1_5;
    s32 temp_a1_7;
    s32 temp_v1_3;
    s32 var_a0_2;
    s32 var_t1;
    s32* temp_a0_4;
    s32* temp_v1_2;
    s32* var_a3;
    u8 temp_a0;
    void* temp_a1_2;
    void* temp_a1_3;
    void* temp_a1_4;
    void* temp_a1_6;
    void* temp_s0;
    void* temp_s0_2;
    void* temp_s0_3;
    void* temp_s0_4;
    void* temp_v0;
    void* temp_v1;
    void* var_a0;
    void* var_a2;

    temp_v1 = netGetDmeTime_troyCB(&D_003156C0_troyCB);
    if (arg0 != 0x100) {
        if (arg1 == M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F00)) {
            M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) = 0;
            M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F00) = -1;
        } else if (temp_v1 != NULL) {
            temp_a0 = M2C_FIELD(temp_v1, u8* , 0);
            if (temp_a0 == D_004F9CA4_troyCB) {
                temp_s0 = M2C_FIELD(temp_v1, void** , 0x1C);
                if (M2C_FIELD(temp_s0, s32* , 4) != -1) {
                    var_a0 = D_004FA030_troyCB;
                    if (M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) != 0) {
                        var_a0 = D_004FA030_troyCB;
                        if (func_001734B8_troyCB(&D_003156C0_troyCB) != 0) {
                            var_a2 = D_004FA030_troyCB;
                            var_t1 = 0;
                            var_t0 = temp_s0 + 0x30;
                            var_a3 = temp_s0 + 0x10;
                            do {
                                temp_a1 = var_t1 * 4;
                                temp_v1_2 = M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + 0x40 + temp_a1;
                                *temp_v1_2 += *var_a3;
                                temp_a0_2 = M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + temp_a1;
                                *temp_a0_2 += *var_t0;
                                temp_a1_2 = M2C_FIELD(var_a2, void** , 0x20D8);
                                var_t1 += 1;
                                if (temp_a1_2 != NULL) {
                                    temp_a0_3 = M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + 0x20 + (M2C_FIELD(temp_a1_2, s32* , 4) * 4);
                                    *temp_a0_3 += M2C_FIELD((temp_a1_2 + (M2C_FIELD(temp_s0, s32* , 4) * 4)), f32* , 0x30);
                                    temp_a1_3 = M2C_FIELD(var_a2, void** , 0x20D8);
                                    temp_a0_4 = M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + 0x60 + (M2C_FIELD(temp_a1_3, s32* , 4) * 4);
                                    *temp_a0_4 += M2C_FIELD((temp_a1_3 + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x10);
                                }
                                var_a2 += 0x31B0;
                                var_t0 += 4;
                                var_a3 += 4;
                            } while (var_t1 < 8);
                            M2C_FIELD((M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x40) = 0;
                            *(M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + (M2C_FIELD(temp_s0, s32* , 4) * 4)) = 0;
                            M2C_FIELD((M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x60) = 0;
                            M2C_FIELD((M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x20) = 0;
                            M2C_FIELD((&D_003156C0_troyCB + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x303C) = 0;
                            var_a0 = D_004FA030_troyCB;
                        }
                    }
                    temp_a1_4 = var_a0 + 0x18D80;
                    do {
                        temp_v1_3 = M2C_FIELD(var_a0, s32* , 0x20D8);
                        if (temp_v1_3 != 0) {
                            M2C_FIELD((temp_v1_3 + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x30) = 0;
                            M2C_FIELD((M2C_FIELD(var_a0, s32* , 0x20D8) + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x10) = 0;
                        }
                        var_a0 += 0x31B0;
                    } while ((s32) var_a0 < (s32) temp_a1_4);
                }
                if (M2C_FIELD(temp_s0, s32* , 0) <= 0xFFFE) {
                    M2C_FIELD(((arg0 * 0x220) + &D_003156C0_troyCB), s32* , 0x220) = 0;
                }
                if (M2C_FIELD(D_004FA030_troyCB, s32* , 0x20D8) == temp_s0) {
                    M2C_FIELD(D_004FA030_troyCB, s32* , 0x20D8) = 0;
                } else {
                    var_a0_2 = 1;
loop_23:
                    if (var_a0_2 < 8) {
                        temp_v0 = (var_a0_2 * 0x31B0) + D_004FA030_troyCB;
                        var_a0_2 += 1;
                        if (M2C_FIELD(temp_v0, s32* , 0x20D8) == temp_s0) {
                            M2C_FIELD(temp_v0, s32* , 0x20D8) = 0;
                        } else {
                            goto loop_23;
                        }
                    }
                }
            } else if (temp_a0 == D_004F9CAC_troyCB) {
                M2C_FIELD(&D_003156C0_troyCB, void** , 0x3148) = (void* ) (&D_003156C0_troyCB + 0x3080);
            } else if ((temp_a0 == D_004F9D18_troyCB) && (temp_s0_2 = M2C_FIELD(temp_v1, void** , 0x1C), (temp_s0_2 != NULL)) && (temp_a1_5 = M2C_FIELD(temp_s0_2, s32* , 0), (temp_a1_5 != 0))) {
                if ((u32) (M2C_FIELD(temp_a1_5, s32* , 0x20B4) - 4) < 2U) {
                    if (arg0 != *M2C_FIELD(&D_003156C0_troyCB, s32** , 4)) {
                        func_0013EED0_troyCB(D_004FA030_troyCB, temp_a1_5);
                        func_001759D8_troyCB(&D_003156C0_troyCB, M2C_FIELD(temp_s0_2, s32* , 0));
                    }
                } else {
                    if (func_001734B8_troyCB(&D_003156C0_troyCB, temp_a1_5) != 0) {
                        temp_s0_3 = (arg0 * 0x220) + &D_003156C0_troyCB;
                        temp_a1_6 = M2C_FIELD(temp_s0_3, void** , 0xB0);
                        if (temp_a1_6 != NULL) {
                            temp_a1_7 = M2C_FIELD(temp_a1_6, s32* , 0x20E0);
                            if (temp_a1_7 != -1) {
                                func_00181AA8_troyCB(&D_003156C0_troyCB + 0x3234, temp_a1_7, 0);
                            }
                            if (M2C_FIELD(&D_003156C0_troyCB, s32* , 0x3870) != 0) {
                                func_0011B308_troyCB(&D_003156C0_troyCB + 0x386C, M2C_FIELD(temp_s0_3, void** , 0xB0));
                            }
                        }
                    }
                    temp_s0_4 = &D_003156C0_troyCB + 0x56C0;
                    func_00264A60_troyCB(&sp80, M2C_FIELD(temp_s0_4, s32* , 0x2CF0), arg0);
                    if (M2C_FIELD(temp_s0_4, s32* , 0x1BB4) == 0xB) {
                        func_001A9240_troyCB();
                    }
                    sprintf_troyCB(sp, "%s has left the game.", (arg0 * 0x220) + (temp_s0_4 + 0x18));
                    func_0014EDA0_troyCB(sp);
                    AddMessage__3Hudiii_troyCB(D_004FA030_troyCB + 0x97B50, 0xF9, 2, 0);
                    func_0016F1C8_troyCB(temp_s0_4, arg0);
                    if (M2C_FIELD(temp_s0_4, s32* , 0x3220) != 0) {
                        if (M2C_FIELD(M2C_FIELD(temp_s0_4, void** , 0x3148), u8* , 0x24) == 0) {
                            func_00174D78_troyCB(temp_s0_4, 0, 0);
                        }
                    }
                }
            }
        }
    }
}
//@@ netObjDestroyCB m2c1
#include "m2c_macros.h"
M2C_UNK AddMessage__3Hudiii_troyCB() __asm__("AddMessage__3Hudiii");
M2C_UNK func_0011B308_troyCB() __asm__("func_0011B308");
M2C_UNK func_0013EED0_troyCB() __asm__("func_0013EED0");
M2C_UNK func_0014EDA0_troyCB() __asm__("func_0014EDA0");
M2C_UNK func_0016F1C8_troyCB() __asm__("func_0016F1C8");
s32 func_001734B8_troyCB() __asm__("func_001734B8");
M2C_UNK func_00174D78_troyCB() __asm__("func_00174D78");
M2C_UNK func_001759D8_troyCB() __asm__("func_001759D8");
M2C_UNK func_00181AA8_troyCB() __asm__("func_00181AA8");
M2C_UNK func_001A9240_troyCB() __asm__("func_001A9240");
M2C_UNK func_00264A60_troyCB() __asm__("func_00264A60");
void* netGetDmeTime_troyCB() __asm__("netGetDmeTime");
M2C_UNK sprintf_troyCB() __asm__("sprintf");
extern M2C_UNK D_003156C0_troyCB __asm__("D_003156C0");
extern s32 D_004F9CA4_troyCB __asm__("D_004F9CA4");
extern s32 D_004F9CAC_troyCB __asm__("D_004F9CAC");
extern s32 D_004F9D18_troyCB __asm__("D_004F9D18");
extern void* D_004FA030_troyCB __asm__("D_004FA030");

void netObjDestroyCB(s32 arg0, s32 arg1) {
    u8 sp[0x80];
    M2C_UNK sp80;
    f32* temp_a0_2;
    f32* temp_a0_3;
    f32* var_t0;
    s32 temp_a1;
    s32 temp_a1_5;
    s32 temp_a1_7;
    s32 temp_v1_3;
    s32 var_a0_2;
    s32 var_t1;
    s32* temp_a0_4;
    s32* temp_v1_2;
    s32* var_a3;
    u8 temp_a0;
    void* temp_a1_2;
    void* temp_a1_3;
    void* temp_a1_4;
    void* temp_a1_6;
    void* temp_s0;
    void* temp_s0_2;
    void* temp_s0_3;
    void* temp_s0_4;
    void* temp_v0;
    void* temp_v1;
    void* var_a0;
    void* var_a2;

    temp_v1 = netGetDmeTime_troyCB(&D_003156C0_troyCB);
    if (arg0 != 0x100) {
        if (arg1 == M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F00)) {
            M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) = 0;
            M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F00) = -1;
        } else if (temp_v1 != NULL) {
            temp_a0 = M2C_FIELD(temp_v1, u8* , 0);
            if (temp_a0 == D_004F9CA4_troyCB) {
                temp_s0 = M2C_FIELD(temp_v1, void** , 0x1C);
                if (M2C_FIELD(temp_s0, s32* , 4) != -1) {
                    var_a0 = D_004FA030_troyCB;
                    if (M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) != 0) {
                        var_a0 = D_004FA030_troyCB;
                        if (func_001734B8_troyCB(&D_003156C0_troyCB) != 0) {
                            var_a2 = D_004FA030_troyCB;
                            var_t1 = 0;
                            var_t0 = temp_s0 + 0x30;
                            var_a3 = temp_s0 + 0x10;
                            do {
                                temp_a1 = var_t1 * 4;
                                temp_v1_2 = M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + 0x40 + temp_a1;
                                *temp_v1_2 += *var_a3;
                                temp_a0_2 = M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + temp_a1;
                                *temp_a0_2 += *var_t0;
                                temp_a1_2 = M2C_FIELD(var_a2, void** , 0x20D8);
                                var_t1 += 1;
                                if (temp_a1_2 != NULL) {
                                    temp_a0_3 = M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + 0x20 + (M2C_FIELD(temp_a1_2, s32* , 4) * 4);
                                    *temp_a0_3 += M2C_FIELD((temp_a1_2 + (M2C_FIELD(temp_s0, s32* , 4) * 4)), f32* , 0x30);
                                    temp_a1_3 = M2C_FIELD(var_a2, void** , 0x20D8);
                                    temp_a0_4 = M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + 0x60 + (M2C_FIELD(temp_a1_3, s32* , 4) * 4);
                                    *temp_a0_4 += M2C_FIELD((temp_a1_3 + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x10);
                                }
                                var_a2 += 0x31B0;
                                var_t0 += 4;
                                var_a3 += 4;
                            } while (var_t1 < 8);
                            M2C_FIELD((M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x40) = 0;
                            *(M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + (M2C_FIELD(temp_s0, s32* , 4) * 4)) = 0;
                            M2C_FIELD((M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x60) = 0;
                            M2C_FIELD((M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x20) = 0;
                            M2C_FIELD((&D_003156C0_troyCB + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x303C) = 0;
                            var_a0 = D_004FA030_troyCB;
                        }
                    }
                    temp_a1_4 = var_a0 + 0x18D80;
                    do {
                        temp_v1_3 = M2C_FIELD(var_a0, s32* , 0x20D8);
                        if (temp_v1_3 != 0) {
                            M2C_FIELD((temp_v1_3 + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x30) = 0;
                            M2C_FIELD((M2C_FIELD(var_a0, s32* , 0x20D8) + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x10) = 0;
                        }
                        var_a0 += 0x31B0;
                    } while ((s32) var_a0 < (s32) temp_a1_4);
                }
                if (M2C_FIELD(temp_s0, s32* , 0) <= 0xFFFE) {
                    M2C_FIELD(((arg0 * 0x220) + &D_003156C0_troyCB), s32* , 0x220) = 0;
                }
                if (M2C_FIELD(D_004FA030_troyCB, s32* , 0x20D8) == temp_s0) {
                    M2C_FIELD(D_004FA030_troyCB, s32* , 0x20D8) = 0;
                } else {
                    var_a0_2 = 1;
loop_23:
                    if (var_a0_2 < 8) {
                        temp_v0 = (var_a0_2 * 0x31B0) + D_004FA030_troyCB;
                        var_a0_2 += 1;
                        if (M2C_FIELD(temp_v0, s32* , 0x20D8) == temp_s0) {
                            M2C_FIELD(temp_v0, s32* , 0x20D8) = 0;
                        } else {
                            goto loop_23;
                        }
                    }
                }
            } else if (temp_a0 == D_004F9CAC_troyCB) {
                M2C_FIELD(&D_003156C0_troyCB, void** , 0x3148) = (void* ) (&D_003156C0_troyCB + 0x3080);
            } else if ((temp_a0 == D_004F9D18_troyCB) && (temp_s0_2 = M2C_FIELD(temp_v1, void** , 0x1C), (temp_s0_2 != NULL)) && (temp_a1_5 = M2C_FIELD(temp_s0_2, s32* , 0), (temp_a1_5 != 0))) {
                if ((u32) (M2C_FIELD(temp_a1_5, s32* , 0x20B4) - 4) < 2U) {
                    if (arg0 != *M2C_FIELD(&D_003156C0_troyCB, s32** , 4)) {
                        func_0013EED0_troyCB(D_004FA030_troyCB, temp_a1_5);
                        func_001759D8_troyCB(&D_003156C0_troyCB, M2C_FIELD(temp_s0_2, s32* , 0));
                    }
                } else {
                    if (func_001734B8_troyCB(&D_003156C0_troyCB, temp_a1_5) != 0) {
                        temp_s0_3 = (arg0 * 0x220) + &D_003156C0_troyCB;
                        temp_a1_6 = M2C_FIELD(temp_s0_3, void** , 0xB0);
                        if (temp_a1_6 != NULL) {
                            temp_a1_7 = M2C_FIELD(temp_a1_6, s32* , 0x20E0);
                            if (temp_a1_7 != -1) {
                                func_00181AA8_troyCB(&D_003156C0_troyCB + 0x3234, temp_a1_7, 0);
                            }
                            if (M2C_FIELD(&D_003156C0_troyCB, s32* , 0x3870) != 0) {
                                func_0011B308_troyCB(&D_003156C0_troyCB + 0x386C, M2C_FIELD(temp_s0_3, void** , 0xB0));
                            }
                        }
                    }
                    temp_s0_4 = &D_003156C0_troyCB + 0x56C0;
                    func_00264A60_troyCB(&sp80, M2C_FIELD(temp_s0_4, s32* , 0x2CF0), arg0);
                    if (M2C_FIELD(temp_s0_4, s32* , 0x1BB4) == 0xB) {
                        func_001A9240_troyCB();
                    }
                    sprintf_troyCB(sp, "%s has left the game.", (arg0 * 0x220) + (temp_s0_4 + 0x18));
                    func_0014EDA0_troyCB(sp);
                    AddMessage__3Hudiii_troyCB(D_004FA030_troyCB + 0x97B50, 0xF9, 2, 0);
                    func_0016F1C8_troyCB(temp_s0_4, arg0);
                    if (M2C_FIELD(temp_s0_4, s32* , 0x3220) != 0) {
                        if (M2C_FIELD(M2C_FIELD(temp_s0_4, void** , 0x3148), u8* , 0x24) == 0) {
                            func_00174D78_troyCB(temp_s0_4, 0, 0);
                        }
                    }
                }
            }
        }
    }
}
//@@ netObjDestroyCB m2c2
#include "m2c_macros.h"
M2C_UNK AddMessage__3Hudiii_troyCB() __asm__("AddMessage__3Hudiii");
M2C_UNK func_0011B308_troyCB() __asm__("func_0011B308");
M2C_UNK func_0013EED0_troyCB() __asm__("func_0013EED0");
M2C_UNK func_0014EDA0_troyCB() __asm__("func_0014EDA0");
M2C_UNK func_0016F1C8_troyCB() __asm__("func_0016F1C8");
s32 func_001734B8_troyCB() __asm__("func_001734B8");
M2C_UNK func_00174D78_troyCB() __asm__("func_00174D78");
M2C_UNK func_001759D8_troyCB() __asm__("func_001759D8");
M2C_UNK func_00181AA8_troyCB() __asm__("func_00181AA8");
M2C_UNK func_001A9240_troyCB() __asm__("func_001A9240");
M2C_UNK func_00264A60_troyCB() __asm__("func_00264A60");
void* netGetDmeTime_troyCB() __asm__("netGetDmeTime");
M2C_UNK sprintf_troyCB() __asm__("sprintf");
extern M2C_UNK D_003156C0_troyCB __asm__("D_003156C0");
extern s32 D_004F9CA4_troyCB __asm__("D_004F9CA4");
extern s32 D_004F9CAC_troyCB __asm__("D_004F9CAC");
extern s32 D_004F9D18_troyCB __asm__("D_004F9D18");
extern void* D_004FA030_troyCB __asm__("D_004FA030");

void netObjDestroyCB(s32 arg0, s32 arg1) {
    u8 sp[0x70];
    M2C_UNK sp80;
    f32* temp_a0_2;
    f32* temp_a0_3;
    f32* var_t0;
    s32 temp_a1;
    s32 temp_a1_5;
    s32 temp_a1_7;
    s32 temp_v1_3;
    s32 var_a0_2;
    s32 var_t1;
    s32* temp_a0_4;
    s32* temp_v1_2;
    s32* var_a3;
    u8 temp_a0;
    void* temp_a1_2;
    void* temp_a1_3;
    void* temp_a1_4;
    void* temp_a1_6;
    void* temp_s0;
    void* temp_s0_2;
    void* temp_s0_3;
    void* temp_s0_4;
    void* temp_v0;
    void* temp_v1;
    void* var_a0;
    void* var_a2;

    temp_v1 = netGetDmeTime_troyCB(&D_003156C0_troyCB);
    if (arg0 != 0x100) {
        if (arg1 == M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F00)) {
            M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) = 0;
            M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F00) = -1;
        } else if (temp_v1 != NULL) {
            temp_a0 = M2C_FIELD(temp_v1, u8* , 0);
            if (temp_a0 == D_004F9CA4_troyCB) {
                temp_s0 = M2C_FIELD(temp_v1, void** , 0x1C);
                if (M2C_FIELD(temp_s0, s32* , 4) != -1) {
                    var_a0 = D_004FA030_troyCB;
                    if (M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) != 0) {
                        var_a0 = D_004FA030_troyCB;
                        if (func_001734B8_troyCB(&D_003156C0_troyCB) != 0) {
                            var_a2 = D_004FA030_troyCB;
                            var_t1 = 0;
                            var_t0 = temp_s0 + 0x30;
                            var_a3 = temp_s0 + 0x10;
                            do {
                                temp_a1 = var_t1 * 4;
                                temp_v1_2 = M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + 0x40 + temp_a1;
                                *temp_v1_2 += *var_a3;
                                temp_a0_2 = M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + temp_a1;
                                *temp_a0_2 += *var_t0;
                                temp_a1_2 = M2C_FIELD(var_a2, void** , 0x20D8);
                                var_t1 += 1;
                                if (temp_a1_2 != NULL) {
                                    temp_a0_3 = M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + 0x20 + (M2C_FIELD(temp_a1_2, s32* , 4) * 4);
                                    *temp_a0_3 += M2C_FIELD((temp_a1_2 + (M2C_FIELD(temp_s0, s32* , 4) * 4)), f32* , 0x30);
                                    temp_a1_3 = M2C_FIELD(var_a2, void** , 0x20D8);
                                    temp_a0_4 = M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + 0x60 + (M2C_FIELD(temp_a1_3, s32* , 4) * 4);
                                    *temp_a0_4 += M2C_FIELD((temp_a1_3 + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x10);
                                }
                                var_a2 += 0x31B0;
                                var_t0 += 4;
                                var_a3 += 4;
                            } while (var_t1 < 8);
                            M2C_FIELD((M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x40) = 0;
                            *(M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + (M2C_FIELD(temp_s0, s32* , 4) * 4)) = 0;
                            M2C_FIELD((M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x60) = 0;
                            M2C_FIELD((M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x20) = 0;
                            M2C_FIELD((&D_003156C0_troyCB + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x303C) = 0;
                            var_a0 = D_004FA030_troyCB;
                        }
                    }
                    temp_a1_4 = var_a0 + 0x18D80;
                    do {
                        temp_v1_3 = M2C_FIELD(var_a0, s32* , 0x20D8);
                        if (temp_v1_3 != 0) {
                            M2C_FIELD((temp_v1_3 + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x30) = 0;
                            M2C_FIELD((M2C_FIELD(var_a0, s32* , 0x20D8) + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x10) = 0;
                        }
                        var_a0 += 0x31B0;
                    } while ((s32) var_a0 < (s32) temp_a1_4);
                }
                if (M2C_FIELD(temp_s0, s32* , 0) <= 0xFFFE) {
                    M2C_FIELD(((arg0 * 0x220) + &D_003156C0_troyCB), s32* , 0x220) = 0;
                }
                if (M2C_FIELD(D_004FA030_troyCB, s32* , 0x20D8) == temp_s0) {
                    M2C_FIELD(D_004FA030_troyCB, s32* , 0x20D8) = 0;
                } else {
                    var_a0_2 = 1;
loop_23:
                    if (var_a0_2 < 8) {
                        temp_v0 = (var_a0_2 * 0x31B0) + D_004FA030_troyCB;
                        var_a0_2 += 1;
                        if (M2C_FIELD(temp_v0, s32* , 0x20D8) == temp_s0) {
                            M2C_FIELD(temp_v0, s32* , 0x20D8) = 0;
                        } else {
                            goto loop_23;
                        }
                    }
                }
            } else if (temp_a0 == D_004F9CAC_troyCB) {
                M2C_FIELD(&D_003156C0_troyCB, void** , 0x3148) = (void* ) (&D_003156C0_troyCB + 0x3080);
            } else if ((temp_a0 == D_004F9D18_troyCB) && (temp_s0_2 = M2C_FIELD(temp_v1, void** , 0x1C), (temp_s0_2 != NULL)) && (temp_a1_5 = M2C_FIELD(temp_s0_2, s32* , 0), (temp_a1_5 != 0))) {
                if ((u32) (M2C_FIELD(temp_a1_5, s32* , 0x20B4) - 4) < 2U) {
                    if (arg0 != *M2C_FIELD(&D_003156C0_troyCB, s32** , 4)) {
                        func_0013EED0_troyCB(D_004FA030_troyCB, temp_a1_5);
                        func_001759D8_troyCB(&D_003156C0_troyCB, M2C_FIELD(temp_s0_2, s32* , 0));
                    }
                } else {
                    if (func_001734B8_troyCB(&D_003156C0_troyCB, temp_a1_5) != 0) {
                        temp_s0_3 = (arg0 * 0x220) + &D_003156C0_troyCB;
                        temp_a1_6 = M2C_FIELD(temp_s0_3, void** , 0xB0);
                        if (temp_a1_6 != NULL) {
                            temp_a1_7 = M2C_FIELD(temp_a1_6, s32* , 0x20E0);
                            if (temp_a1_7 != -1) {
                                func_00181AA8_troyCB(&D_003156C0_troyCB + 0x3234, temp_a1_7, 0);
                            }
                            if (M2C_FIELD(&D_003156C0_troyCB, s32* , 0x3870) != 0) {
                                func_0011B308_troyCB(&D_003156C0_troyCB + 0x386C, M2C_FIELD(temp_s0_3, void** , 0xB0));
                            }
                        }
                    }
                    temp_s0_4 = &D_003156C0_troyCB + 0x56C0;
                    func_00264A60_troyCB(&sp80, M2C_FIELD(temp_s0_4, s32* , 0x2CF0), arg0);
                    if (M2C_FIELD(temp_s0_4, s32* , 0x1BB4) == 0xB) {
                        func_001A9240_troyCB();
                    }
                    sprintf_troyCB(sp, "%s has left the game.", (arg0 * 0x220) + (temp_s0_4 + 0x18));
                    func_0014EDA0_troyCB(sp);
                    AddMessage__3Hudiii_troyCB(D_004FA030_troyCB + 0x97B50, 0xF9, 2, 0);
                    func_0016F1C8_troyCB(temp_s0_4, arg0);
                    if (M2C_FIELD(temp_s0_4, s32* , 0x3220) != 0) {
                        if (M2C_FIELD(M2C_FIELD(temp_s0_4, void** , 0x3148), u8* , 0x24) == 0) {
                            func_00174D78_troyCB(temp_s0_4, 0, 0);
                        }
                    }
                }
            }
        }
    }
}
//@@ netObjDestroyCB m2c3
#include "m2c_macros.h"
M2C_UNK AddMessage__3Hudiii_troyCB() __asm__("AddMessage__3Hudiii");
M2C_UNK func_0011B308_troyCB() __asm__("func_0011B308");
M2C_UNK func_0013EED0_troyCB() __asm__("func_0013EED0");
M2C_UNK func_0014EDA0_troyCB() __asm__("func_0014EDA0");
M2C_UNK func_0016F1C8_troyCB() __asm__("func_0016F1C8");
s32 func_001734B8_troyCB() __asm__("func_001734B8");
M2C_UNK func_00174D78_troyCB() __asm__("func_00174D78");
M2C_UNK func_001759D8_troyCB() __asm__("func_001759D8");
M2C_UNK func_00181AA8_troyCB() __asm__("func_00181AA8");
M2C_UNK func_001A9240_troyCB() __asm__("func_001A9240");
M2C_UNK func_00264A60_troyCB() __asm__("func_00264A60");
void* netGetDmeTime_troyCB() __asm__("netGetDmeTime");
M2C_UNK sprintf_troyCB() __asm__("sprintf");
extern M2C_UNK D_003156C0_troyCB __asm__("D_003156C0");
extern s32 D_004F9CA4_troyCB __asm__("D_004F9CA4");
extern s32 D_004F9CAC_troyCB __asm__("D_004F9CAC");
extern s32 D_004F9D18_troyCB __asm__("D_004F9D18");
extern void* D_004FA030_troyCB __asm__("D_004FA030");

void netObjDestroyCB(s32 arg0, s32 arg1) {
    u8 sp[0x60];
    M2C_UNK sp80;
    f32* temp_a0_2;
    f32* temp_a0_3;
    f32* var_t0;
    s32 temp_a1;
    s32 temp_a1_5;
    s32 temp_a1_7;
    s32 temp_v1_3;
    s32 var_a0_2;
    s32 var_t1;
    s32* temp_a0_4;
    s32* temp_v1_2;
    s32* var_a3;
    u8 temp_a0;
    void* temp_a1_2;
    void* temp_a1_3;
    void* temp_a1_4;
    void* temp_a1_6;
    void* temp_s0;
    void* temp_s0_2;
    void* temp_s0_3;
    void* temp_s0_4;
    void* temp_v0;
    void* temp_v1;
    void* var_a0;
    void* var_a2;

    temp_v1 = netGetDmeTime_troyCB(&D_003156C0_troyCB);
    if (arg0 != 0x100) {
        if (arg1 == M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F00)) {
            M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) = 0;
            M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F00) = -1;
        } else if (temp_v1 != NULL) {
            temp_a0 = M2C_FIELD(temp_v1, u8* , 0);
            if (temp_a0 == D_004F9CA4_troyCB) {
                temp_s0 = M2C_FIELD(temp_v1, void** , 0x1C);
                if (M2C_FIELD(temp_s0, s32* , 4) != -1) {
                    var_a0 = D_004FA030_troyCB;
                    if (M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) != 0) {
                        var_a0 = D_004FA030_troyCB;
                        if (func_001734B8_troyCB(&D_003156C0_troyCB) != 0) {
                            var_a2 = D_004FA030_troyCB;
                            var_t1 = 0;
                            var_t0 = temp_s0 + 0x30;
                            var_a3 = temp_s0 + 0x10;
                            do {
                                temp_a1 = var_t1 * 4;
                                temp_v1_2 = M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + 0x40 + temp_a1;
                                *temp_v1_2 += *var_a3;
                                temp_a0_2 = M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + temp_a1;
                                *temp_a0_2 += *var_t0;
                                temp_a1_2 = M2C_FIELD(var_a2, void** , 0x20D8);
                                var_t1 += 1;
                                if (temp_a1_2 != NULL) {
                                    temp_a0_3 = M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + 0x20 + (M2C_FIELD(temp_a1_2, s32* , 4) * 4);
                                    *temp_a0_3 += M2C_FIELD((temp_a1_2 + (M2C_FIELD(temp_s0, s32* , 4) * 4)), f32* , 0x30);
                                    temp_a1_3 = M2C_FIELD(var_a2, void** , 0x20D8);
                                    temp_a0_4 = M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + 0x60 + (M2C_FIELD(temp_a1_3, s32* , 4) * 4);
                                    *temp_a0_4 += M2C_FIELD((temp_a1_3 + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x10);
                                }
                                var_a2 += 0x31B0;
                                var_t0 += 4;
                                var_a3 += 4;
                            } while (var_t1 < 8);
                            M2C_FIELD((M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x40) = 0;
                            *(M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + (M2C_FIELD(temp_s0, s32* , 4) * 4)) = 0;
                            M2C_FIELD((M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x60) = 0;
                            M2C_FIELD((M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x20) = 0;
                            M2C_FIELD((&D_003156C0_troyCB + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x303C) = 0;
                            var_a0 = D_004FA030_troyCB;
                        }
                    }
                    temp_a1_4 = var_a0 + 0x18D80;
                    do {
                        temp_v1_3 = M2C_FIELD(var_a0, s32* , 0x20D8);
                        if (temp_v1_3 != 0) {
                            M2C_FIELD((temp_v1_3 + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x30) = 0;
                            M2C_FIELD((M2C_FIELD(var_a0, s32* , 0x20D8) + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x10) = 0;
                        }
                        var_a0 += 0x31B0;
                    } while ((s32) var_a0 < (s32) temp_a1_4);
                }
                if (M2C_FIELD(temp_s0, s32* , 0) <= 0xFFFE) {
                    M2C_FIELD(((arg0 * 0x220) + &D_003156C0_troyCB), s32* , 0x220) = 0;
                }
                if (M2C_FIELD(D_004FA030_troyCB, s32* , 0x20D8) == temp_s0) {
                    M2C_FIELD(D_004FA030_troyCB, s32* , 0x20D8) = 0;
                } else {
                    var_a0_2 = 1;
loop_23:
                    if (var_a0_2 < 8) {
                        temp_v0 = (var_a0_2 * 0x31B0) + D_004FA030_troyCB;
                        var_a0_2 += 1;
                        if (M2C_FIELD(temp_v0, s32* , 0x20D8) == temp_s0) {
                            M2C_FIELD(temp_v0, s32* , 0x20D8) = 0;
                        } else {
                            goto loop_23;
                        }
                    }
                }
            } else if (temp_a0 == D_004F9CAC_troyCB) {
                M2C_FIELD(&D_003156C0_troyCB, void** , 0x3148) = (void* ) (&D_003156C0_troyCB + 0x3080);
            } else if ((temp_a0 == D_004F9D18_troyCB) && (temp_s0_2 = M2C_FIELD(temp_v1, void** , 0x1C), (temp_s0_2 != NULL)) && (temp_a1_5 = M2C_FIELD(temp_s0_2, s32* , 0), (temp_a1_5 != 0))) {
                if ((u32) (M2C_FIELD(temp_a1_5, s32* , 0x20B4) - 4) < 2U) {
                    if (arg0 != *M2C_FIELD(&D_003156C0_troyCB, s32** , 4)) {
                        func_0013EED0_troyCB(D_004FA030_troyCB, temp_a1_5);
                        func_001759D8_troyCB(&D_003156C0_troyCB, M2C_FIELD(temp_s0_2, s32* , 0));
                    }
                } else {
                    if (func_001734B8_troyCB(&D_003156C0_troyCB, temp_a1_5) != 0) {
                        temp_s0_3 = (arg0 * 0x220) + &D_003156C0_troyCB;
                        temp_a1_6 = M2C_FIELD(temp_s0_3, void** , 0xB0);
                        if (temp_a1_6 != NULL) {
                            temp_a1_7 = M2C_FIELD(temp_a1_6, s32* , 0x20E0);
                            if (temp_a1_7 != -1) {
                                func_00181AA8_troyCB(&D_003156C0_troyCB + 0x3234, temp_a1_7, 0);
                            }
                            if (M2C_FIELD(&D_003156C0_troyCB, s32* , 0x3870) != 0) {
                                func_0011B308_troyCB(&D_003156C0_troyCB + 0x386C, M2C_FIELD(temp_s0_3, void** , 0xB0));
                            }
                        }
                    }
                    temp_s0_4 = &D_003156C0_troyCB + 0x56C0;
                    func_00264A60_troyCB(&sp80, M2C_FIELD(temp_s0_4, s32* , 0x2CF0), arg0);
                    if (M2C_FIELD(temp_s0_4, s32* , 0x1BB4) == 0xB) {
                        func_001A9240_troyCB();
                    }
                    sprintf_troyCB(sp, "%s has left the game.", (arg0 * 0x220) + (temp_s0_4 + 0x18));
                    func_0014EDA0_troyCB(sp);
                    AddMessage__3Hudiii_troyCB(D_004FA030_troyCB + 0x97B50, 0xF9, 2, 0);
                    func_0016F1C8_troyCB(temp_s0_4, arg0);
                    if (M2C_FIELD(temp_s0_4, s32* , 0x3220) != 0) {
                        if (M2C_FIELD(M2C_FIELD(temp_s0_4, void** , 0x3148), u8* , 0x24) == 0) {
                            func_00174D78_troyCB(temp_s0_4, 0, 0);
                        }
                    }
                }
            }
        }
    }
}
//@@ netObjDestroyCB m2c4
#include "m2c_macros.h"
M2C_UNK AddMessage__3Hudiii_troyCB() __asm__("AddMessage__3Hudiii");
M2C_UNK func_0011B308_troyCB() __asm__("func_0011B308");
M2C_UNK func_0013EED0_troyCB() __asm__("func_0013EED0");
M2C_UNK func_0014EDA0_troyCB() __asm__("func_0014EDA0");
M2C_UNK func_0016F1C8_troyCB() __asm__("func_0016F1C8");
s32 func_001734B8_troyCB() __asm__("func_001734B8");
M2C_UNK func_00174D78_troyCB() __asm__("func_00174D78");
M2C_UNK func_001759D8_troyCB() __asm__("func_001759D8");
M2C_UNK func_00181AA8_troyCB() __asm__("func_00181AA8");
M2C_UNK func_001A9240_troyCB() __asm__("func_001A9240");
M2C_UNK func_00264A60_troyCB() __asm__("func_00264A60");
void* netGetDmeTime_troyCB() __asm__("netGetDmeTime");
M2C_UNK sprintf_troyCB() __asm__("sprintf");
extern M2C_UNK D_003156C0_troyCB __asm__("D_003156C0");
extern s32 D_004F9CA4_troyCB __asm__("D_004F9CA4");
extern s32 D_004F9CAC_troyCB __asm__("D_004F9CAC");
extern s32 D_004F9D18_troyCB __asm__("D_004F9D18");
extern void* D_004FA030_troyCB __asm__("D_004FA030");

void netObjDestroyCB(s32 arg0, s32 arg1) {
    u8 sp[0x50];
    M2C_UNK sp80;
    f32* temp_a0_2;
    f32* temp_a0_3;
    f32* var_t0;
    s32 temp_a1;
    s32 temp_a1_5;
    s32 temp_a1_7;
    s32 temp_v1_3;
    s32 var_a0_2;
    s32 var_t1;
    s32* temp_a0_4;
    s32* temp_v1_2;
    s32* var_a3;
    u8 temp_a0;
    void* temp_a1_2;
    void* temp_a1_3;
    void* temp_a1_4;
    void* temp_a1_6;
    void* temp_s0;
    void* temp_s0_2;
    void* temp_s0_3;
    void* temp_s0_4;
    void* temp_v0;
    void* temp_v1;
    void* var_a0;
    void* var_a2;

    temp_v1 = netGetDmeTime_troyCB(&D_003156C0_troyCB);
    if (arg0 != 0x100) {
        if (arg1 == M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F00)) {
            M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) = 0;
            M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F00) = -1;
        } else if (temp_v1 != NULL) {
            temp_a0 = M2C_FIELD(temp_v1, u8* , 0);
            if (temp_a0 == D_004F9CA4_troyCB) {
                temp_s0 = M2C_FIELD(temp_v1, void** , 0x1C);
                if (M2C_FIELD(temp_s0, s32* , 4) != -1) {
                    var_a0 = D_004FA030_troyCB;
                    if (M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) != 0) {
                        var_a0 = D_004FA030_troyCB;
                        if (func_001734B8_troyCB(&D_003156C0_troyCB) != 0) {
                            var_a2 = D_004FA030_troyCB;
                            var_t1 = 0;
                            var_t0 = temp_s0 + 0x30;
                            var_a3 = temp_s0 + 0x10;
                            do {
                                temp_a1 = var_t1 * 4;
                                temp_v1_2 = M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + 0x40 + temp_a1;
                                *temp_v1_2 += *var_a3;
                                temp_a0_2 = M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + temp_a1;
                                *temp_a0_2 += *var_t0;
                                temp_a1_2 = M2C_FIELD(var_a2, void** , 0x20D8);
                                var_t1 += 1;
                                if (temp_a1_2 != NULL) {
                                    temp_a0_3 = M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + 0x20 + (M2C_FIELD(temp_a1_2, s32* , 4) * 4);
                                    *temp_a0_3 += M2C_FIELD((temp_a1_2 + (M2C_FIELD(temp_s0, s32* , 4) * 4)), f32* , 0x30);
                                    temp_a1_3 = M2C_FIELD(var_a2, void** , 0x20D8);
                                    temp_a0_4 = M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + 0x60 + (M2C_FIELD(temp_a1_3, s32* , 4) * 4);
                                    *temp_a0_4 += M2C_FIELD((temp_a1_3 + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x10);
                                }
                                var_a2 += 0x31B0;
                                var_t0 += 4;
                                var_a3 += 4;
                            } while (var_t1 < 8);
                            M2C_FIELD((M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x40) = 0;
                            *(M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + (M2C_FIELD(temp_s0, s32* , 4) * 4)) = 0;
                            M2C_FIELD((M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x60) = 0;
                            M2C_FIELD((M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x20) = 0;
                            M2C_FIELD((&D_003156C0_troyCB + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x303C) = 0;
                            var_a0 = D_004FA030_troyCB;
                        }
                    }
                    temp_a1_4 = var_a0 + 0x18D80;
                    do {
                        temp_v1_3 = M2C_FIELD(var_a0, s32* , 0x20D8);
                        if (temp_v1_3 != 0) {
                            M2C_FIELD((temp_v1_3 + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x30) = 0;
                            M2C_FIELD((M2C_FIELD(var_a0, s32* , 0x20D8) + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x10) = 0;
                        }
                        var_a0 += 0x31B0;
                    } while ((s32) var_a0 < (s32) temp_a1_4);
                }
                if (M2C_FIELD(temp_s0, s32* , 0) <= 0xFFFE) {
                    M2C_FIELD(((arg0 * 0x220) + &D_003156C0_troyCB), s32* , 0x220) = 0;
                }
                if (M2C_FIELD(D_004FA030_troyCB, s32* , 0x20D8) == temp_s0) {
                    M2C_FIELD(D_004FA030_troyCB, s32* , 0x20D8) = 0;
                } else {
                    var_a0_2 = 1;
loop_23:
                    if (var_a0_2 < 8) {
                        temp_v0 = (var_a0_2 * 0x31B0) + D_004FA030_troyCB;
                        var_a0_2 += 1;
                        if (M2C_FIELD(temp_v0, s32* , 0x20D8) == temp_s0) {
                            M2C_FIELD(temp_v0, s32* , 0x20D8) = 0;
                        } else {
                            goto loop_23;
                        }
                    }
                }
            } else if (temp_a0 == D_004F9CAC_troyCB) {
                M2C_FIELD(&D_003156C0_troyCB, void** , 0x3148) = (void* ) (&D_003156C0_troyCB + 0x3080);
            } else if ((temp_a0 == D_004F9D18_troyCB) && (temp_s0_2 = M2C_FIELD(temp_v1, void** , 0x1C), (temp_s0_2 != NULL)) && (temp_a1_5 = M2C_FIELD(temp_s0_2, s32* , 0), (temp_a1_5 != 0))) {
                if ((u32) (M2C_FIELD(temp_a1_5, s32* , 0x20B4) - 4) < 2U) {
                    if (arg0 != *M2C_FIELD(&D_003156C0_troyCB, s32** , 4)) {
                        func_0013EED0_troyCB(D_004FA030_troyCB, temp_a1_5);
                        func_001759D8_troyCB(&D_003156C0_troyCB, M2C_FIELD(temp_s0_2, s32* , 0));
                    }
                } else {
                    if (func_001734B8_troyCB(&D_003156C0_troyCB, temp_a1_5) != 0) {
                        temp_s0_3 = (arg0 * 0x220) + &D_003156C0_troyCB;
                        temp_a1_6 = M2C_FIELD(temp_s0_3, void** , 0xB0);
                        if (temp_a1_6 != NULL) {
                            temp_a1_7 = M2C_FIELD(temp_a1_6, s32* , 0x20E0);
                            if (temp_a1_7 != -1) {
                                func_00181AA8_troyCB(&D_003156C0_troyCB + 0x3234, temp_a1_7, 0);
                            }
                            if (M2C_FIELD(&D_003156C0_troyCB, s32* , 0x3870) != 0) {
                                func_0011B308_troyCB(&D_003156C0_troyCB + 0x386C, M2C_FIELD(temp_s0_3, void** , 0xB0));
                            }
                        }
                    }
                    temp_s0_4 = &D_003156C0_troyCB + 0x56C0;
                    func_00264A60_troyCB(&sp80, M2C_FIELD(temp_s0_4, s32* , 0x2CF0), arg0);
                    if (M2C_FIELD(temp_s0_4, s32* , 0x1BB4) == 0xB) {
                        func_001A9240_troyCB();
                    }
                    sprintf_troyCB(sp, "%s has left the game.", (arg0 * 0x220) + (temp_s0_4 + 0x18));
                    func_0014EDA0_troyCB(sp);
                    AddMessage__3Hudiii_troyCB(D_004FA030_troyCB + 0x97B50, 0xF9, 2, 0);
                    func_0016F1C8_troyCB(temp_s0_4, arg0);
                    if (M2C_FIELD(temp_s0_4, s32* , 0x3220) != 0) {
                        if (M2C_FIELD(M2C_FIELD(temp_s0_4, void** , 0x3148), u8* , 0x24) == 0) {
                            func_00174D78_troyCB(temp_s0_4, 0, 0);
                        }
                    }
                }
            }
        }
    }
}
//@@ netObjDestroyCB m2c5
#include "m2c_macros.h"
M2C_UNK AddMessage__3Hudiii_troyCB() __asm__("AddMessage__3Hudiii");
M2C_UNK func_0011B308_troyCB() __asm__("func_0011B308");
M2C_UNK func_0013EED0_troyCB() __asm__("func_0013EED0");
M2C_UNK func_0014EDA0_troyCB() __asm__("func_0014EDA0");
M2C_UNK func_0016F1C8_troyCB() __asm__("func_0016F1C8");
s32 func_001734B8_troyCB() __asm__("func_001734B8");
M2C_UNK func_00174D78_troyCB() __asm__("func_00174D78");
M2C_UNK func_001759D8_troyCB() __asm__("func_001759D8");
M2C_UNK func_00181AA8_troyCB() __asm__("func_00181AA8");
M2C_UNK func_001A9240_troyCB() __asm__("func_001A9240");
M2C_UNK func_00264A60_troyCB() __asm__("func_00264A60");
void* netGetDmeTime_troyCB() __asm__("netGetDmeTime");
M2C_UNK sprintf_troyCB() __asm__("sprintf");
extern M2C_UNK D_003156C0_troyCB __asm__("D_003156C0");
extern s32 D_004F9CA4_troyCB __asm__("D_004F9CA4");
extern s32 D_004F9CAC_troyCB __asm__("D_004F9CAC");
extern s32 D_004F9D18_troyCB __asm__("D_004F9D18");
extern void* D_004FA030_troyCB __asm__("D_004FA030");

void netObjDestroyCB(s32 arg0, s32 arg1) {
    u8 sp[0x40];
    M2C_UNK sp80;
    f32* temp_a0_2;
    f32* temp_a0_3;
    f32* var_t0;
    s32 temp_a1;
    s32 temp_a1_5;
    s32 temp_a1_7;
    s32 temp_v1_3;
    s32 var_a0_2;
    s32 var_t1;
    s32* temp_a0_4;
    s32* temp_v1_2;
    s32* var_a3;
    u8 temp_a0;
    void* temp_a1_2;
    void* temp_a1_3;
    void* temp_a1_4;
    void* temp_a1_6;
    void* temp_s0;
    void* temp_s0_2;
    void* temp_s0_3;
    void* temp_s0_4;
    void* temp_v0;
    void* temp_v1;
    void* var_a0;
    void* var_a2;

    temp_v1 = netGetDmeTime_troyCB(&D_003156C0_troyCB);
    if (arg0 != 0x100) {
        if (arg1 == M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F00)) {
            M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) = 0;
            M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F00) = -1;
        } else if (temp_v1 != NULL) {
            temp_a0 = M2C_FIELD(temp_v1, u8* , 0);
            if (temp_a0 == D_004F9CA4_troyCB) {
                temp_s0 = M2C_FIELD(temp_v1, void** , 0x1C);
                if (M2C_FIELD(temp_s0, s32* , 4) != -1) {
                    var_a0 = D_004FA030_troyCB;
                    if (M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) != 0) {
                        var_a0 = D_004FA030_troyCB;
                        if (func_001734B8_troyCB(&D_003156C0_troyCB) != 0) {
                            var_a2 = D_004FA030_troyCB;
                            var_t1 = 0;
                            var_t0 = temp_s0 + 0x30;
                            var_a3 = temp_s0 + 0x10;
                            do {
                                temp_a1 = var_t1 * 4;
                                temp_v1_2 = M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + 0x40 + temp_a1;
                                *temp_v1_2 += *var_a3;
                                temp_a0_2 = M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + temp_a1;
                                *temp_a0_2 += *var_t0;
                                temp_a1_2 = M2C_FIELD(var_a2, void** , 0x20D8);
                                var_t1 += 1;
                                if (temp_a1_2 != NULL) {
                                    temp_a0_3 = M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + 0x20 + (M2C_FIELD(temp_a1_2, s32* , 4) * 4);
                                    *temp_a0_3 += M2C_FIELD((temp_a1_2 + (M2C_FIELD(temp_s0, s32* , 4) * 4)), f32* , 0x30);
                                    temp_a1_3 = M2C_FIELD(var_a2, void** , 0x20D8);
                                    temp_a0_4 = M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + 0x60 + (M2C_FIELD(temp_a1_3, s32* , 4) * 4);
                                    *temp_a0_4 += M2C_FIELD((temp_a1_3 + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x10);
                                }
                                var_a2 += 0x31B0;
                                var_t0 += 4;
                                var_a3 += 4;
                            } while (var_t1 < 8);
                            M2C_FIELD((M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x40) = 0;
                            *(M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + (M2C_FIELD(temp_s0, s32* , 4) * 4)) = 0;
                            M2C_FIELD((M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x60) = 0;
                            M2C_FIELD((M2C_FIELD(&D_003156C0_troyCB, s32* , 0x2F04) + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x20) = 0;
                            M2C_FIELD((&D_003156C0_troyCB + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x303C) = 0;
                            var_a0 = D_004FA030_troyCB;
                        }
                    }
                    temp_a1_4 = var_a0 + 0x18D80;
                    do {
                        temp_v1_3 = M2C_FIELD(var_a0, s32* , 0x20D8);
                        if (temp_v1_3 != 0) {
                            M2C_FIELD((temp_v1_3 + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x30) = 0;
                            M2C_FIELD((M2C_FIELD(var_a0, s32* , 0x20D8) + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x10) = 0;
                        }
                        var_a0 += 0x31B0;
                    } while ((s32) var_a0 < (s32) temp_a1_4);
                }
                if (M2C_FIELD(temp_s0, s32* , 0) <= 0xFFFE) {
                    M2C_FIELD(((arg0 * 0x220) + &D_003156C0_troyCB), s32* , 0x220) = 0;
                }
                if (M2C_FIELD(D_004FA030_troyCB, s32* , 0x20D8) == temp_s0) {
                    M2C_FIELD(D_004FA030_troyCB, s32* , 0x20D8) = 0;
                } else {
                    var_a0_2 = 1;
loop_23:
                    if (var_a0_2 < 8) {
                        temp_v0 = (var_a0_2 * 0x31B0) + D_004FA030_troyCB;
                        var_a0_2 += 1;
                        if (M2C_FIELD(temp_v0, s32* , 0x20D8) == temp_s0) {
                            M2C_FIELD(temp_v0, s32* , 0x20D8) = 0;
                        } else {
                            goto loop_23;
                        }
                    }
                }
            } else if (temp_a0 == D_004F9CAC_troyCB) {
                M2C_FIELD(&D_003156C0_troyCB, void** , 0x3148) = (void* ) (&D_003156C0_troyCB + 0x3080);
            } else if ((temp_a0 == D_004F9D18_troyCB) && (temp_s0_2 = M2C_FIELD(temp_v1, void** , 0x1C), (temp_s0_2 != NULL)) && (temp_a1_5 = M2C_FIELD(temp_s0_2, s32* , 0), (temp_a1_5 != 0))) {
                if ((u32) (M2C_FIELD(temp_a1_5, s32* , 0x20B4) - 4) < 2U) {
                    if (arg0 != *M2C_FIELD(&D_003156C0_troyCB, s32** , 4)) {
                        func_0013EED0_troyCB(D_004FA030_troyCB, temp_a1_5);
                        func_001759D8_troyCB(&D_003156C0_troyCB, M2C_FIELD(temp_s0_2, s32* , 0));
                    }
                } else {
                    if (func_001734B8_troyCB(&D_003156C0_troyCB, temp_a1_5) != 0) {
                        temp_s0_3 = (arg0 * 0x220) + &D_003156C0_troyCB;
                        temp_a1_6 = M2C_FIELD(temp_s0_3, void** , 0xB0);
                        if (temp_a1_6 != NULL) {
                            temp_a1_7 = M2C_FIELD(temp_a1_6, s32* , 0x20E0);
                            if (temp_a1_7 != -1) {
                                func_00181AA8_troyCB(&D_003156C0_troyCB + 0x3234, temp_a1_7, 0);
                            }
                            if (M2C_FIELD(&D_003156C0_troyCB, s32* , 0x3870) != 0) {
                                func_0011B308_troyCB(&D_003156C0_troyCB + 0x386C, M2C_FIELD(temp_s0_3, void** , 0xB0));
                            }
                        }
                    }
                    temp_s0_4 = &D_003156C0_troyCB + 0x56C0;
                    func_00264A60_troyCB(&sp80, M2C_FIELD(temp_s0_4, s32* , 0x2CF0), arg0);
                    if (M2C_FIELD(temp_s0_4, s32* , 0x1BB4) == 0xB) {
                        func_001A9240_troyCB();
                    }
                    sprintf_troyCB(sp, "%s has left the game.", (arg0 * 0x220) + (temp_s0_4 + 0x18));
                    func_0014EDA0_troyCB(sp);
                    AddMessage__3Hudiii_troyCB(D_004FA030_troyCB + 0x97B50, 0xF9, 2, 0);
                    func_0016F1C8_troyCB(temp_s0_4, arg0);
                    if (M2C_FIELD(temp_s0_4, s32* , 0x3220) != 0) {
                        if (M2C_FIELD(M2C_FIELD(temp_s0_4, void** , 0x3148), u8* , 0x24) == 0) {
                            func_00174D78_troyCB(temp_s0_4, 0, 0);
                        }
                    }
                }
            }
        }
    }
}
//@@ netWeaponCreateCB m2c0
#include "m2c_macros.h"
M2C_UNK FireSpecial__8LauncherP7Vehicle_eateCB() __asm__("FireSpecial__8LauncherP7Vehicle");
s32 GetWeaponMapping__8Launcheri_eateCB() __asm__("GetWeaponMapping__8Launcheri");
M2C_UNK ReverseAnimation__8LauncherP7Vehicleifi_eateCB() __asm__("ReverseAnimation__8LauncherP7Vehicleifi");
M2C_UNK StartAnimation__8LauncherP7Vehicleif_eateCB() __asm__("StartAnimation__8LauncherP7Vehicleif");
M2C_UNK animationPause__FR11_animHandle_eateCB() __asm__("animationPause__FR11_animHandle");
M2C_UNK animationSetToFrame__FR11_animHandlef_eateCB() __asm__("animationSetToFrame__FR11_animHandlef");
M2C_UNK animationStart__FR11_animHandleb_eateCB() __asm__("animationStart__FR11_animHandleb");
M2C_UNK func_00133198_eateCB() __asm__("func_00133198");
M2C_UNK func_00159C98_eateCB() __asm__("func_00159C98");
M2C_UNK func_001735E8_eateCB() __asm__("func_001735E8");
M2C_UNK func_0019FB28_eateCB() __asm__("func_0019FB28");
M2C_UNK func_0019FB70_eateCB() __asm__("func_0019FB70");
M2C_UNK func_001A01F8_eateCB() __asm__("func_001A01F8");
M2C_UNK func_001EDDF0_eateCB() __asm__("func_001EDDF0");
M2C_UNK func_001FBCF8_eateCB() __asm__("func_001FBCF8");
void* netGetDmeTime_eateCB() __asm__("netGetDmeTime");
M2C_UNK terminateChargerSpecialChargeUpSound__13LauncherSound_eateCB() __asm__("terminateChargerSpecialChargeUpSound__13LauncherSound");
s32 timerGetCurTics__Fv_eateCB() __asm__("timerGetCurTics__Fv");
extern M2C_UNK D_003156C0_eateCB __asm__("D_003156C0");
extern void* D_004FA030_eateCB __asm__("D_004FA030");

void netWeaponCreateCB(s32 arg0, s32 arg1) {
    f32 sp10;
    f32 sp14;
    f32 sp18;
    s32 sp1C;
    M2C_UNK sp20;
    s16 temp_v1_2;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s8 temp_v1;
    s8 temp_v1_3;
    s8 temp_v1_4;
    u16 temp_a0_2;
    u32** temp_v1_6;
    u8 temp_a0;
    void* temp_a1;
    void* temp_a1_2;
    void* temp_s0;
    void* temp_s1;
    void* temp_s2;
    void* temp_v1_5;
    void* var_s0;
    void* var_s3;
    void* var_s4;

    var_s3 = NULL;
    if (arg0 != 0x100) {
        temp_s2 = M2C_FIELD(netGetDmeTime_eateCB(&D_003156C0_eateCB), void** , 0x1C);
        M2C_FIELD(temp_s2, void** , 0) = NULL;
        if (M2C_FIELD(temp_s2, s16* , 0xA) != -1) {
            temp_v1 = M2C_FIELD(temp_s2, s8* , 0xC);
            temp_a0 = (u8) M2C_FIELD(temp_s2, s8* , 0xC);
            if (temp_v1 == 1) {
                var_s3 = M2C_FIELD(((arg0 * 0x220) + &D_003156C0_eateCB), void** , 0xB0);
                goto block_9;
            }
            var_v0 = temp_a0 << 0x18;
            if (temp_v1 == -2) {
                temp_a1 = M2C_FIELD(D_004FA030_eateCB, void** , 0x9E690);
                var_s3 = temp_a1;
                if (temp_a1 == NULL) {
                    var_v0 = temp_a0 << 0x18;
                    goto block_7;
                }
                goto block_9;
            }
block_7:
            if ((var_v0 >> 0x18) == -3) {
                temp_a1_2 = M2C_FIELD(D_004FA030_eateCB, void** , 0x9E694);
                var_s3 = temp_a1_2;
                if (temp_a1_2 != NULL) {
block_9:
                    if (var_s3 != NULL) {
                        goto block_10;
                    }
                }
            }
        } else {
block_10:
            temp_v1_2 = M2C_FIELD(temp_s2, s16* , 0xE);
            if (temp_v1_2 >= 0) {
                var_s4 = M2C_FIELD(((M2C_FIELD(temp_s2, s16* , 0x10) * 0x220) + &D_003156C0_eateCB), void** , 0xB0);
            } else if (temp_v1_2 == -2) {
                var_s4 = M2C_FIELD(D_004FA030_eateCB, void** , 0x9E690);
            } else {
                var_s4 = NULL;
                if (temp_v1_2 == -3) {
                    var_s4 = M2C_FIELD(D_004FA030_eateCB, void** , 0x9E694);
                }
            }
            if (M2C_FIELD(temp_s2, s16* , 0x12) != -1) {

            }
            temp_a0_2 = (u16) M2C_FIELD(temp_s2, s16* , 0xA);
            if (M2C_FIELD(temp_s2, s16* , 0xA) == 0xA0) {
                temp_v1_3 = M2C_FIELD(temp_s2, s8* , 6);
                var_v0_2 = temp_a0_2 << 0x10;
                if (temp_v1_3 == 1) {
                    M2C_FIELD(var_s3, s32* , 0x242C) = (s32) temp_v1_3;
                    M2C_FIELD(var_s3, s32* , 0x2430) = 0x96;
                    M2C_FIELD((var_s3 + (M2C_FIELD(temp_s2, s8* , 6) * 4)), s32* , 0x22AC) = -1;
                    func_001735E8_eateCB(&D_003156C0_eateCB, temp_s2, var_s3);
                } else {
                    goto block_23;
                }
            } else {
                var_v0_2 = temp_a0_2 << 0x10;
block_23:
                var_v0_3 = temp_a0_2 << 0x10;
                if (((var_v0_2 >> 0x10) == 0x180) && (var_v0_3 = temp_a0_2 << 0x10, (M2C_FIELD(temp_s2, s8* , 6) == 1))) {
                    func_00159C98_eateCB(var_s3 + 0x21B0, var_s3);
                } else {
                    var_v0_4 = temp_a0_2 << 0x10;
                    if (((var_v0_3 >> 0x10) == 0x1E0) && (var_v0_4 = temp_a0_2 << 0x10, (M2C_FIELD(temp_s2, s8* , 6) == 1))) {
                        FireSpecial__8LauncherP7Vehicle_eateCB(var_s3 + 0x21B0, var_s3);
                    } else {
                        if (((var_v0_4 >> 0x10) == 0x20) && (M2C_FIELD(temp_s2, s8* , 6) == 0x11)) {
                            terminateChargerSpecialChargeUpSound__13LauncherSound_eateCB(var_s3 + 0x2AD0);
                            M2C_FIELD(var_s3, s32* , 0x2508) = (s32) M2C_FIELD(temp_s2, u8* , 4);
                        }
                        sp10 = M2C_FIELD(temp_s2, f32* , 0x2C);
                        sp14 = M2C_FIELD(temp_s2, f32* , 0x30);
                        sp1C = 0;
                        sp18 = M2C_FIELD(temp_s2, f32* , 0x34);
                        M2C_FIELD(&D_003156C0_eateCB, void** , 0x2E94) = NULL;
                        if (var_s3 != NULL) {
                            M2C_FIELD((var_s3 + (M2C_FIELD(temp_s2, s8* , 6) * 4)), s32* , 0x22AC) = (s32) M2C_FIELD(temp_s2, s8* , 7);
                            temp_v1_4 = M2C_FIELD(temp_s2, s8* , 6);
                            switch (temp_v1_4) {    /* irregular */
                            case 4:
                                if (M2C_FIELD(temp_s2, u8* , 4) != 0x20) {
                                    var_s0 = var_s3 + 0x21B0;
                                    if (M2C_FIELD(&D_003156C0_eateCB, s32* , 0x1BB4) == 0xB) {
                                        func_0019FB70_eateCB(var_s3 + 0x2AD0, var_s3);
                                    }
                                } else {
                                    temp_v1_5 = var_s3 + 0x21B0;
                                    M2C_FIELD(var_s3, s32* , 0x2420) = 1;
                                    var_s0 = temp_v1_5;
                                    StartAnimation__8LauncherP7Vehicleif_eateCB(0x3F800000, temp_v1_5, var_s3, 4);
                                    if (M2C_FIELD(&D_003156C0_eateCB, s32* , 0x1BB4) == 0xB) {
                                        func_0019FB28_eateCB(var_s3 + 0x2AD0, var_s3);
                                    }
                                }
                                ReverseAnimation__8LauncherP7Vehicleifi_eateCB(0x40000000, var_s0, var_s3, 4, 0);
                                break;
                            case 28:
                                if (M2C_FIELD(temp_s2, u8* , 4) == 0x20) {
                                    M2C_FIELD(var_s3, s32* , 0x21B4) = 1;
                                }
                                M2C_FIELD(var_s3, s32* , 0x27B4) = timerGetCurTics__Fv_eateCB(4);
                                M2C_FIELD(var_s3, s32* , 0x27B8) = 0;
                                break;
                            case 18:
                                M2C_FIELD(var_s3, s32* , 0x21B4) = 0;
                                M2C_FIELD(var_s3, s32* , 0x27B8) = 0;
                                M2C_FIELD(var_s3, s32* , 0x27B4) = timerGetCurTics__Fv_eateCB(4);
                                break;
                            }
                            if (M2C_FIELD(temp_s2, s8* , 6) == 0xC) {
                                if (M2C_FIELD(var_s3, s32* , 0x23F0) == 0) {
                                    temp_v1_6 = M2C_FIELD(var_s3, u32*** , 0x2404);
                                    M2C_FIELD(var_s3, s32* , 0x23F4) = -1;
                                    if (temp_v1_6 != NULL) {
                                        func_001FBCF8_eateCB(&sp20, (u32) **temp_v1_6 >> 0x12, 0, 0);
                                        animationStart__FR11_animHandleb_eateCB(&sp20, 1);
                                    }
                                }
                                if (M2C_FIELD(&D_003156C0_eateCB, s32* , 0x1BB4) == 0xB) {
                                    func_001A01F8_eateCB(var_s3 + 0x2AD0, var_s3 + 0x23E0);
                                }
                                M2C_FIELD(var_s3, s32* , 0x23F0) = 1;
                                M2C_FIELD(var_s3, s32* , 0x23F4) = (s32) (M2C_FIELD(var_s3, s32* , 0x23F4) + 1);
                            }
                            if (M2C_FIELD(temp_s2, s8* , 7) == 0x7F) {
                                if (var_s4 != NULL) {
                                    func_00133198_eateCB(D_004FA030_eateCB + 0x96260, var_s3, var_s4, 1);
                                }
                            } else {
                                func_001EDDF0_eateCB(D_004FA030_eateCB + 0x6C310, M2C_FIELD(temp_s2, s8* , 6), var_s3, var_s4);
                            }
                            if (M2C_FIELD(temp_s2, s8* , 6) == 0x1C) {
                                temp_s0 = var_s3 + 0x2E8C;
                                M2C_FIELD(var_s3, s32* , 0x21B4) = 0;
                                M2C_FIELD(var_s3, s32* , 0x2244) = 0;
                                temp_s1 = var_s3 + 0x21B0;
                                animationPause__FR11_animHandle_eateCB(temp_s0);
                                animationSetToFrame__FR11_animHandlef_eateCB(0, temp_s0);
                                animationSetToFrame__FR11_animHandlef_eateCB(0, var_s3 + ((GetWeaponMapping__8Launcheri_eateCB(temp_s1, 1) * 0xC) + 0x2D9C));
                                StartAnimation__8LauncherP7Vehicleif_eateCB(0x3F800000, temp_s1, var_s3, 1);
                            }
                            if (M2C_FIELD(&D_003156C0_eateCB, void** , 0x2E94) != NULL) {
                                M2C_FIELD(temp_s2, void** , 0) = (void* ) M2C_FIELD(&D_003156C0_eateCB, void** , 0x2E94);
                                M2C_FIELD(M2C_FIELD(&D_003156C0_eateCB, void** , 0x2E94), s32* , 0x50) = arg1;
                                M2C_FIELD(M2C_FIELD(temp_s2, void** , 0), f32* , 0xB4) = (f32) M2C_FIELD(temp_s2, f32* , 0x38);
                            }
                            M2C_FIELD((var_s3 + (M2C_FIELD(temp_s2, s8* , 6) * 4)), s32* , 0x2338) = (s32) M2C_FIELD(temp_s2, s8* , 8);
                        }
                    }
                }
            }
        }
    }
}
//@@ netWeaponUpdateCB m2c0
#include "m2c_macros.h"
M2C_UNK func_001735E8_dateCB() __asm__("func_001735E8");
M2C_UNK func_001F02A8_dateCB() __asm__("func_001F02A8");
void* netGetDmeTime_dateCB() __asm__("netGetDmeTime");
extern M2C_UNK D_003156C0_dateCB __asm__("D_003156C0");
extern void* D_004FA030_dateCB __asm__("D_004FA030");

void netWeaponUpdateCB(s32 arg0) {
    s32 var_a2;
    s32 var_v0;
    s8 temp_a2;
    s8 temp_v1;
    u8 temp_a3;
    void* temp_a0;
    void* temp_a1;

    if (arg0 != 0x100) {
        temp_a1 = M2C_FIELD(netGetDmeTime_dateCB(&D_003156C0_dateCB), void** , 0x1C);
        if (M2C_FIELD(temp_a1, s16* , 0xA) != 0xA0) {
            goto block_14;
        }
        temp_a2 = M2C_FIELD(temp_a1, s8* , 6);
        if (temp_a2 != 1) {
block_14:
            if (((M2C_FIELD(temp_a1, s16* , 0xA) != 0x180) || (M2C_FIELD(temp_a1, s8* , 6) != 1)) && (M2C_FIELD(temp_a1, u8* , 4) == 1)) {
                temp_a0 = M2C_FIELD(temp_a1, void** , 0);
                if (temp_a0 != NULL) {
                    if (M2C_FIELD(temp_a0, s32* , 0x54) == 0) {
                        func_001F02A8_dateCB(temp_a0, temp_a1);
                    }
                }
            }
        } else {
            temp_v1 = M2C_FIELD(temp_a1, s8* , 0xC);
            temp_a3 = (u8) M2C_FIELD(temp_a1, s8* , 0xC);
            if (temp_v1 == temp_a2) {
                var_a2 = M2C_FIELD(((arg0 * 0x220) + &D_003156C0_dateCB), s32* , 0xB0);
                goto block_13;
            }
            var_v0 = temp_a3 << 0x18;
            if ((temp_v1 != -2) || (var_a2 = M2C_FIELD(D_004FA030_dateCB, s32* , 0x9E690), var_v0 = temp_a3 << 0x18, (var_a2 == 0))) {
                if ((var_v0 >> 0x18) == -3) {
                    var_a2 = M2C_FIELD(D_004FA030_dateCB, s32* , 0x9E694);
                    if (var_a2 != 0) {
                        goto block_13;
                    }
                }
            } else {
block_13:
                func_001735E8_dateCB(&D_003156C0_dateCB, temp_a1, var_a2, temp_a3);
            }
        }
    }
}
//@@ netWeaponDestroyCB m2c0
#include "m2c_macros.h"
M2C_UNK func_001735E8_troyCB() __asm__("func_001735E8");
M2C_UNK func_001F02A8_troyCB() __asm__("func_001F02A8");
void* netGetDmeTime_troyCB() __asm__("netGetDmeTime");
extern M2C_UNK D_003156C0_troyCB __asm__("D_003156C0");
extern void* D_004FA030_troyCB __asm__("D_004FA030");

void netWeaponDestroyCB(s32 arg0) {
    s32 var_a2;
    s32 var_v0;
    s8 temp_a1;
    s8 temp_v1;
    u8 temp_a3;
    void* temp_a0;
    void* temp_a1_2;
    void* temp_s1;

    if (arg0 != 0x100) {
        temp_s1 = M2C_FIELD(netGetDmeTime_troyCB(&D_003156C0_troyCB), void** , 0x1C);
        if (M2C_FIELD(temp_s1, s16* , 0xA) != 0xA0) {
            goto block_16;
        }
        temp_a1 = M2C_FIELD(temp_s1, s8* , 6);
        if (temp_a1 != 1) {
block_16:
            if ((M2C_FIELD(temp_s1, s16* , 0xA) != 0x180) || (M2C_FIELD(temp_s1, s8* , 6) != 1)) {
                if (M2C_FIELD(temp_s1, u8* , 4) != 0) {
                    temp_a0 = M2C_FIELD(temp_s1, void** , 0);
                    if (temp_a0 != NULL) {
                        if (M2C_FIELD(temp_a0, s32* , 0x54) == 0) {
                            func_001F02A8_troyCB(temp_a0, temp_s1);
                        }
                        goto block_22;
                    }
                } else {
block_22:
                    temp_a1_2 = M2C_FIELD(temp_s1, void** , 0);
                    if (temp_a1_2 != NULL) {
                        M2C_FIELD(temp_a1_2, s32* , 0x50) = -1;
                    }
                }
            }
        } else {
            temp_v1 = M2C_FIELD(temp_s1, s8* , 0xC);
            temp_a3 = (u8) M2C_FIELD(temp_s1, s8* , 0xC);
            if (temp_v1 == temp_a1) {
                var_a2 = M2C_FIELD(((arg0 * 0x220) + &D_003156C0_troyCB), s32* , 0xB0);
                goto block_14;
            }
            var_v0 = temp_a3 << 0x18;
            if (temp_v1 == -2) {
                var_a2 = M2C_FIELD(D_004FA030_troyCB, s32* , 0x9E690);
                if (var_a2 == 0) {
                    var_v0 = temp_a3 << 0x18;
                    goto block_12;
                }
                goto block_15;
            }
block_12:
            if ((var_v0 >> 0x18) == -3) {
                var_a2 = M2C_FIELD(D_004FA030_troyCB, s32* , 0x9E694);
                if (var_a2 != 0) {
block_14:
block_15:
                    func_001735E8_troyCB(&D_003156C0_troyCB, temp_s1, var_a2, temp_a3);
                }
            }
        }
    }
}
//@@ netGameDataUpdateCB m2c0
#include "m2c_macros.h"
M2C_UNK func_0011BD50_dateCB() __asm__("func_0011BD50");
M2C_UNK func_00173570_dateCB() __asm__("func_00173570");
M2C_UNK func_00176580_dateCB() __asm__("func_00176580");
M2C_UNK func_001814D0_dateCB() __asm__("func_001814D0");
M2C_UNK func_001A9278_dateCB() __asm__("func_001A9278");
extern M2C_UNK D_003156C0_dateCB __asm__("D_003156C0");
extern M2C_UNK D_003188F4_dateCB __asm__("D_003188F4");
extern M2C_UNK D_00318F2C_dateCB __asm__("D_00318F2C");
extern s32 D_004F9CBC_dateCB __asm__("D_004F9CBC");
extern s32 D_004F9CC0_dateCB __asm__("D_004F9CC0");
extern s32 D_004F9CC8_dateCB __asm__("D_004F9CC8");

void netGameDataUpdateCB(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;

    if (arg0 != 0x100) {
        temp_v0 = D_004F9CBC_dateCB;
        if ((M2C_FIELD(M2C_FIELD(&D_003156C0_dateCB, void** , 0x3148), s32* , 0) & 1) && ((u32) (M2C_FIELD(M2C_FIELD(&D_003156C0_dateCB, void** , 4), s32* , 0x204) - 9) < 2U)) {
            func_00173570_dateCB(&D_003156C0_dateCB, 0xB);
        }
        temp_v0_2 = D_004F9CC0_dateCB;
        if (arg2 == temp_v0) {
            func_0011BD50_dateCB(&D_00318F2C_dateCB);
        }
        temp_v0_3 = D_004F9CC8_dateCB;
        if (arg2 == temp_v0_2) {
            func_001814D0_dateCB(&D_003188F4_dateCB);
        }
        if (arg2 == temp_v0_3) {
            temp_a1 = M2C_FIELD(M2C_FIELD(&D_003156C0_dateCB, void** , 4), s32* , 0);
            if (M2C_FIELD(M2C_FIELD(&D_003156C0_dateCB, void** , 0x3148), s8* , 0x1A) == temp_a1) {
                func_001A9278_dateCB(M2C_FIELD(&D_003156C0_dateCB, void** , 0x3148), temp_a1);
            }
        }
        func_00176580_dateCB(&D_003156C0_dateCB);
    }
}
//@@ netPadFlagsUpdateCB m2c0
#include "m2c_macros.h"
void* netGetDmeTime_dateCB() __asm__("netGetDmeTime");
extern M2C_UNK D_003156C0_dateCB __asm__("D_003156C0");

void netPadFlagsUpdateCB(s32 arg0) {
    void* temp_a1;
    void* temp_v0;
    void* temp_v1;
    void* temp_v1_10;
    void* temp_v1_11;
    void* temp_v1_12;
    void* temp_v1_13;
    void* temp_v1_14;
    void* temp_v1_15;
    void* temp_v1_16;
    void* temp_v1_17;
    void* temp_v1_18;
    void* temp_v1_19;
    void* temp_v1_20;
    void* temp_v1_21;
    void* temp_v1_22;
    void* temp_v1_23;
    void* temp_v1_24;
    void* temp_v1_25;
    void* temp_v1_26;
    void* temp_v1_27;
    void* temp_v1_28;
    void* temp_v1_29;
    void* temp_v1_2;
    void* temp_v1_30;
    void* temp_v1_31;
    void* temp_v1_32;
    void* temp_v1_33;
    void* temp_v1_34;
    void* temp_v1_35;
    void* temp_v1_36;
    void* temp_v1_37;
    void* temp_v1_38;
    void* temp_v1_39;
    void* temp_v1_3;
    void* temp_v1_40;
    void* temp_v1_41;
    void* temp_v1_42;
    void* temp_v1_43;
    void* temp_v1_44;
    void* temp_v1_45;
    void* temp_v1_46;
    void* temp_v1_47;
    void* temp_v1_48;
    void* temp_v1_4;
    void* temp_v1_5;
    void* temp_v1_6;
    void* temp_v1_7;
    void* temp_v1_8;
    void* temp_v1_9;

    temp_a1 = netGetDmeTime_dateCB(&D_003156C0_dateCB);
    if (arg0 != 0x100) {
        if (temp_a1 != NULL) {
            temp_v0 = M2C_FIELD(temp_a1, void** , 0x1C);
            if (temp_v0 != NULL) {
                temp_v1 = M2C_FIELD(temp_v0, void** , 0xC);
                if (temp_v1 != NULL) {
                    M2C_FIELD(temp_v1, s8* , 0x594) = (s8) (M2C_FIELD(temp_v0, u32* , 0) & 1);
                    temp_v1_2 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_2, void** , 0xC), s8* , 0x595) = (s8) (((u32) M2C_FIELD(temp_v1_2, u32* , 0) >> 1) & 1);
                    temp_v1_3 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_3, void** , 0xC), s8* , 0x596) = (s8) (((u32) M2C_FIELD(temp_v1_3, u32* , 0) >> 2) & 1);
                    temp_v1_4 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_4, void** , 0xC), s8* , 0x597) = (s8) (((u32) M2C_FIELD(temp_v1_4, u32* , 0) >> 3) & 1);
                    temp_v1_5 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_5, void** , 0xC), s8* , 0x598) = (s8) (((u32) M2C_FIELD(temp_v1_5, u32* , 0) >> 4) & 1);
                    temp_v1_6 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_6, void** , 0xC), s8* , 0x599) = (s8) (((u32) M2C_FIELD(temp_v1_6, u32* , 0) >> 5) & 1);
                    temp_v1_7 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_7, void** , 0xC), s8* , 0x59A) = (s8) (((u32) M2C_FIELD(temp_v1_7, u32* , 0) >> 6) & 1);
                    temp_v1_8 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_8, void** , 0xC), s8* , 0x59B) = (s8) ((u64) (u8) M2C_FIELD(temp_v1_8, u32* , 0) >> 7);
                    temp_v1_9 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_9, void** , 0xC), s8* , 0x59C) = (s8) (((u32) M2C_FIELD(temp_v1_9, u32* , 0) >> 8) & 1);
                    temp_v1_10 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_10, void** , 0xC), s8* , 0x5A1) = (s8) (((u32) M2C_FIELD(temp_v1_10, u32* , 0) >> 9) & 1);
                    temp_v1_11 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_11, void** , 0xC), s8* , 0x5A2) = (s8) (((u32) M2C_FIELD(temp_v1_11, u32* , 0) >> 0xA) & 1);
                    temp_v1_12 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_12, void** , 0xC), s8* , 0x5A3) = (s8) (((u32) M2C_FIELD(temp_v1_12, u32* , 0) >> 0xB) & 1);
                    temp_v1_13 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_13, void** , 0xC), s8* , 0x5A4) = (s8) (((u32) M2C_FIELD(temp_v1_13, u32* , 0) >> 0xC) & 1);
                    temp_v1_14 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_14, void** , 0xC), s8* , 0x5A5) = (s8) (((u32) M2C_FIELD(temp_v1_14, u32* , 0) >> 0xD) & 1);
                    temp_v1_15 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_15, void** , 0xC), s8* , 0x59D) = (s8) ((u32) M2C_FIELD(temp_v1_15, u32* , 0) >> 0xE);
                    temp_v1_16 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_16, void** , 0xC), s8* , 0x59E) = (s8) ((u32) M2C_FIELD(temp_v1_16, u32* , 0) >> 0x16);
                    temp_v1_17 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_17, void** , 0xC), s8* , 0x484) = (s8) (((u32) M2C_FIELD(temp_v1_17, u32* , 0) >> 0x1E) & 1);
                    temp_v1_18 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_18, void** , 0xC), s8* , 0x485) = (s8) ((u32) M2C_FIELD(temp_v1_18, u32* , 0) >> 0x1F);
                    temp_v1_19 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_19, void** , 0xC), s8* , 0x486) = (s8) (M2C_FIELD(temp_v1_19, u32* , 4) & 1);
                    temp_v1_20 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_20, void** , 0xC), s8* , 0x487) = (s8) (((u32) M2C_FIELD(temp_v1_20, u32* , 4) >> 1) & 1);
                    temp_v1_21 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_21, void** , 0xC), s8* , 0x488) = (s8) (((u32) M2C_FIELD(temp_v1_21, u32* , 4) >> 2) & 1);
                    temp_v1_22 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_22, void** , 0xC), s8* , 0x489) = (s8) (((u32) M2C_FIELD(temp_v1_22, u32* , 4) >> 3) & 1);
                    temp_v1_23 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_23, void** , 0xC), s8* , 0x48B) = (s8) (((u32) M2C_FIELD(temp_v1_23, u32* , 4) >> 4) & 1);
                    temp_v1_24 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_24, void** , 0xC), s8* , 0x48C) = (s8) (((u32) M2C_FIELD(temp_v1_24, u32* , 4) >> 5) & 1);
                    temp_v1_25 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_25, void** , 0xC), s8* , 0x48D) = (s8) (((u32) M2C_FIELD(temp_v1_25, u32* , 4) >> 6) & 1);
                    temp_v1_26 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_26, void** , 0xC), s8* , 0x48E) = (s8) ((u64) (u8) M2C_FIELD(temp_v1_26, u32* , 4) >> 7);
                    temp_v1_27 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_27, void** , 0xC), s8* , 0x48F) = (s8) (((u32) M2C_FIELD(temp_v1_27, u32* , 4) >> 8) & 1);
                    temp_v1_28 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_28, void** , 0xC), s8* , 0x490) = (s8) (((u32) M2C_FIELD(temp_v1_28, u32* , 4) >> 9) & 1);
                    temp_v1_29 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_29, void** , 0xC), s8* , 0x492) = (s8) (((u32) M2C_FIELD(temp_v1_29, u32* , 4) >> 0xA) & 1);
                    temp_v1_30 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_30, void** , 0xC), s8* , 0x493) = (s8) (((u32) M2C_FIELD(temp_v1_30, u32* , 4) >> 0xB) & 1);
                    temp_v1_31 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_31, void** , 0xC), s8* , 0x494) = (s8) (((u32) M2C_FIELD(temp_v1_31, u32* , 4) >> 0xC) & 1);
                    temp_v1_32 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_32, void** , 0xC), s8* , 0x495) = (s8) (((u32) M2C_FIELD(temp_v1_32, u32* , 4) >> 0xD) & 1);
                    temp_v1_33 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_33, void** , 0xC), s8* , 0x497) = (s8) (((u32) M2C_FIELD(temp_v1_33, u32* , 4) >> 0xF) & 1);
                    temp_v1_34 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_34, void** , 0xC), s8* , 0x498) = (s8) (M2C_FIELD(temp_v1_34, u16* , 6) & 1);
                    temp_v1_35 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_35, void** , 0xC), s8* , 0x499) = (s8) (((u32) M2C_FIELD(temp_v1_35, u32* , 4) >> 0x11) & 1);
                    temp_v1_36 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_36, void** , 0xC), s8* , 0x49A) = (s8) (((u32) M2C_FIELD(temp_v1_36, u32* , 4) >> 0x12) & 1);
                    temp_v1_37 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_37, void** , 0xC), s8* , 0x49B) = (s8) (((u32) M2C_FIELD(temp_v1_37, u32* , 4) >> 0x13) & 1);
                    temp_v1_38 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_38, void** , 0xC), s8* , 0x49D) = (s8) (((u32) M2C_FIELD(temp_v1_38, u32* , 4) >> 0x14) & 1);
                    temp_v1_39 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_39, void** , 0xC), s8* , 0x49E) = (s8) (((u32) M2C_FIELD(temp_v1_39, u32* , 4) >> 0x15) & 1);
                    temp_v1_40 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_40, void** , 0xC), s8* , 0x49F) = (s8) (((u32) M2C_FIELD(temp_v1_40, u32* , 4) >> 0x16) & 1);
                    temp_v1_41 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_41, void** , 0xC), s8* , 0x4A0) = (s8) (((u32) M2C_FIELD(temp_v1_41, u32* , 4) >> 0x1D) & 1);
                    temp_v1_42 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_42, void** , 0xC), s8* , 0x4A1) = (s8) (((u32) M2C_FIELD(temp_v1_42, u32* , 4) >> 0x1E) & 1);
                    temp_v1_43 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_43, void** , 0xC), s8* , 0x4A2) = (s8) ((u32) M2C_FIELD(temp_v1_43, u32* , 4) >> 0x1F);
                    temp_v1_44 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_44, void** , 0xC), s8* , 0x4A3) = (s8) (M2C_FIELD(temp_v1_44, u32* , 8) & 1);
                    temp_v1_45 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_45, void** , 0xC), s8* , 0x4A4) = (s8) (((u32) M2C_FIELD(temp_v1_45, u32* , 8) >> 1) & 1);
                    temp_v1_46 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_46, void** , 0xC), s8* , 0x4A5) = (s8) (((u32) M2C_FIELD(temp_v1_46, u32* , 8) >> 2) & 1);
                    temp_v1_47 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_47, void** , 0xC), s8* , 0x4A6) = (s8) (((u32) M2C_FIELD(temp_v1_47, u32* , 8) >> 3) & 1);
                    temp_v1_48 = M2C_FIELD(temp_a1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_v1_48, void** , 0xC), s8* , 0x4A7) = (s8) (((u32) M2C_FIELD(temp_v1_48, u32* , 8) >> 4) & 1);
                }
            }
        }
    }
}
//@@ func_0016C480 m2c0
#include "m2c_macros.h"
extern s32 D_004F9EB0_16C480 __asm__("D_004F9EB0");

void func_0016C480(s32 arg0, s32 arg1, s32 arg2) {
    D_004F9EB0_16C480 = arg2;
}
//@@ func_0016C488 m2c0
#include "m2c_macros.h"
M2C_UNK SetCameraPOV__6Camerai10_cameraPOV_16C488() __asm__("SetCameraPOV__6Camerai10_cameraPOV");
M2C_UNK func_001D6F78_16C488() __asm__("func_001D6F78");
extern M2C_UNK D_003156C0_16C488 __asm__("D_003156C0");
extern s32 D_004FA030_16C488 __asm__("D_004FA030");

void func_0016C488(void) {
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_t0;
    s32 var_a2;
    void* var_v0;

    temp_a1 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&D_003156C0_16C488, void** , 4), void** , 0xA0), s32* , 0x210C);
    temp_t0 = temp_a1 * 4;
    temp_a2 = *(D_004FA030_16C488 + 0x27790 + temp_t0);
    if ((u32) (temp_a2 - 1) < 4U) {
        SetCameraPOV__6Camerai10_cameraPOV_16C488(D_004FA030_16C488 + 0x27780, temp_a1, temp_a2, D_004FA030_16C488);
    } else {
        temp_a0 = D_004FA030_16C488 + 0x27780;
        SetCameraPOV__6Camerai10_cameraPOV_16C488(temp_a0, temp_a1, *(temp_a0 + temp_t0), D_004FA030_16C488);
    }
    var_a2 = M2C_FIELD((D_004FA030_16C488 + 0x27780), s32* , 0x43E0);
    if (var_a2 > 0) {
        var_v0 = D_004FA030_16C488 + 0x2B9E0;
        do {
            M2C_FIELD(var_v0, s32* , 0) = 0;
            var_a2 -= 1;
            M2C_FIELD(var_v0, s32* , 4) = 0;
            M2C_FIELD(var_v0, s32* , 8) = 0;
            var_v0 += 0x10;
        } while (var_a2 != 0);
    }
    M2C_FIELD(M2C_FIELD(&D_003156C0_16C488, void** , 4), s32* , 0x208) = 0;
    M2C_FIELD(M2C_FIELD(&D_003156C0_16C488, void** , 4), s32* , 0x20C) = 0;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&D_003156C0_16C488, void** , 4), void** , 0xA0), s32* , 0x590) = 1;
    func_001D6F78_16C488(M2C_FIELD(M2C_FIELD(&D_003156C0_16C488, void** , 4), void** , 0xA0), 1, var_a2);
}
//@@ func_0016C590 m2c0
#include "m2c_macros.h"
M2C_UNK func_00171F88_16C590() __asm__("func_00171F88");
s32 func_001733F8_16C590() __asm__("func_001733F8");
M2C_UNK func_00174988_16C590() __asm__("func_00174988");
s8 func_00176B10_16C590() __asm__("func_00176B10");
s32 func_00176CC8_16C590() __asm__("func_00176CC8");
M2C_UNK func_00266DE0_16C590() __asm__("func_00266DE0");
M2C_UNK func_00266EB0_16C590() __asm__("func_00266EB0");
s32 netGetMyClientIndex_16C590() __asm__("netGetMyClientIndex");
M2C_UNK printf_16C590() __asm__("printf");
extern M2C_UNK D_002B8A00_16C590 __asm__("D_002B8A00");
extern M2C_UNK D_003156C0_16C590 __asm__("D_003156C0");
extern M2C_UNK D_004E6500_16C590 __asm__("D_004E6500");
extern M2C_UNK D_004E6A00_16C590 __asm__("D_004E6A00");
extern void* D_004FA030_16C590 __asm__("D_004FA030");
static M2C_UNK D_004E6BB0;                          /* unable to generate initializer: unknown type; const */

void func_0016C590(s32 arg0, s32 arg1) {
    u8 sp[0x10];
    s32 temp_s0;

    temp_s0 = func_001733F8_16C590(&D_003156C0_16C590);
    printf_16C590("In HostChangeCallback...\n");
    switch (temp_s0) {                              /* irregular */
    case 1:
        if (func_00176B10_16C590(&D_003156C0_16C590, 1) <= 0) {
            printf_16C590(&D_004E6A00_16C590, &D_003156C0_16C590);
            if (func_00176CC8_16C590(&D_003156C0_16C590) != 0) {
                printf_16C590(&D_004E6BB0);
                M2C_FIELD(&D_003156C0_16C590, s32* , 0x1BB0) = temp_s0;
                func_00174988_16C590(&D_003156C0_16C590, -1);
            }
        }
        if ((arg1 == *M2C_FIELD(&D_003156C0_16C590, s32** , 4)) && (M2C_FIELD(D_004FA030_16C590, s32* , 0x9FD9C) != 0) && (M2C_FIELD(&D_003156C0_16C590, s32* , 0x3230) == 0)) {
            func_00171F88_16C590(&D_003156C0_16C590, &D_003156C0_16C590);
        }
        break;
    case 2:
        func_00266DE0_16C590(&D_003156C0_16C590 + 0x307C, M2C_FIELD(&D_003156C0_16C590, s32* , 0x2CF0));
        printf_16C590(&D_004E6500_16C590);
        printf_16C590(">>>>> 6 Setting ConnectionSessionMaster = %d\n\0BASCUS-97196\0\0\0 !\"#$%&'()*+,-.0123456789:;<=>?ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_abcdefghijklmnopqrstuvwxyz{}\0\00123456789\0\0 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\0 .0123456789", M2C_FIELD(&D_003156C0_16C590, M2C_UNK** , 0x307C));
        printf_16C590(&D_004E6500_16C590);
        break;
    }
    if (M2C_FIELD(&D_003156C0_16C590, s32* , 0x2E90) == 0) {
        if (M2C_FIELD(&D_003156C0_16C590, s32* , 0x1BB4) > 0) {
            if (arg1 == netGetMyClientIndex_16C590(&D_003156C0_16C590, 0)) {
                M2C_FIELD(&D_002B8A00_16C590, s32* , 0xE0) = 1;
                func_00266EB0_16C590(sp, M2C_FIELD(&D_003156C0_16C590, s32* , 0x2CF0));
                M2C_FIELD(&D_002B8A00_16C590, s32* , 0xEC) = (s32) subroutine_arg0;
            }
        }
    }
    M2C_FIELD(M2C_FIELD(&D_003156C0_16C590, void** , 0x3148), s8* , 0x24) = func_00176B10_16C590(&D_003156C0_16C590, 0);
}
//@@ func_0016C590 m2c1
#include "m2c_macros.h"
M2C_UNK func_00171F88_16C590() __asm__("func_00171F88");
s32 func_001733F8_16C590() __asm__("func_001733F8");
M2C_UNK func_00174988_16C590() __asm__("func_00174988");
s8 func_00176B10_16C590() __asm__("func_00176B10");
s32 func_00176CC8_16C590() __asm__("func_00176CC8");
M2C_UNK func_00266DE0_16C590() __asm__("func_00266DE0");
M2C_UNK func_00266EB0_16C590() __asm__("func_00266EB0");
s32 netGetMyClientIndex_16C590() __asm__("netGetMyClientIndex");
M2C_UNK printf_16C590() __asm__("printf");
extern M2C_UNK D_002B8A00_16C590 __asm__("D_002B8A00");
extern M2C_UNK D_003156C0_16C590 __asm__("D_003156C0");
extern M2C_UNK D_004E6500_16C590 __asm__("D_004E6500");
extern M2C_UNK D_004E6A00_16C590 __asm__("D_004E6A00");
extern void* D_004FA030_16C590 __asm__("D_004FA030");
static M2C_UNK D_004E6BB0;                          /* unable to generate initializer: unknown type; const */

void func_0016C590(s32 arg0, s32 arg1) {
    u8 sp[0x8];
    s32 temp_s0;

    temp_s0 = func_001733F8_16C590(&D_003156C0_16C590);
    printf_16C590("In HostChangeCallback...\n");
    switch (temp_s0) {                              /* irregular */
    case 1:
        if (func_00176B10_16C590(&D_003156C0_16C590, 1) <= 0) {
            printf_16C590(&D_004E6A00_16C590, &D_003156C0_16C590);
            if (func_00176CC8_16C590(&D_003156C0_16C590) != 0) {
                printf_16C590(&D_004E6BB0);
                M2C_FIELD(&D_003156C0_16C590, s32* , 0x1BB0) = temp_s0;
                func_00174988_16C590(&D_003156C0_16C590, -1);
            }
        }
        if ((arg1 == *M2C_FIELD(&D_003156C0_16C590, s32** , 4)) && (M2C_FIELD(D_004FA030_16C590, s32* , 0x9FD9C) != 0) && (M2C_FIELD(&D_003156C0_16C590, s32* , 0x3230) == 0)) {
            func_00171F88_16C590(&D_003156C0_16C590, &D_003156C0_16C590);
        }
        break;
    case 2:
        func_00266DE0_16C590(&D_003156C0_16C590 + 0x307C, M2C_FIELD(&D_003156C0_16C590, s32* , 0x2CF0));
        printf_16C590(&D_004E6500_16C590);
        printf_16C590(">>>>> 6 Setting ConnectionSessionMaster = %d\n\0BASCUS-97196\0\0\0 !\"#$%&'()*+,-.0123456789:;<=>?ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_abcdefghijklmnopqrstuvwxyz{}\0\00123456789\0\0 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\0 .0123456789", M2C_FIELD(&D_003156C0_16C590, M2C_UNK** , 0x307C));
        printf_16C590(&D_004E6500_16C590);
        break;
    }
    if (M2C_FIELD(&D_003156C0_16C590, s32* , 0x2E90) == 0) {
        if (M2C_FIELD(&D_003156C0_16C590, s32* , 0x1BB4) > 0) {
            if (arg1 == netGetMyClientIndex_16C590(&D_003156C0_16C590, 0)) {
                M2C_FIELD(&D_002B8A00_16C590, s32* , 0xE0) = 1;
                func_00266EB0_16C590(sp, M2C_FIELD(&D_003156C0_16C590, s32* , 0x2CF0));
                M2C_FIELD(&D_002B8A00_16C590, s32* , 0xEC) = (s32) subroutine_arg0;
            }
        }
    }
    M2C_FIELD(M2C_FIELD(&D_003156C0_16C590, void** , 0x3148), s8* , 0x24) = func_00176B10_16C590(&D_003156C0_16C590, 0);
}
//@@ func_0016C590 m2c2
#include "m2c_macros.h"
M2C_UNK func_00171F88_16C590() __asm__("func_00171F88");
s32 func_001733F8_16C590() __asm__("func_001733F8");
M2C_UNK func_00174988_16C590() __asm__("func_00174988");
s8 func_00176B10_16C590() __asm__("func_00176B10");
s32 func_00176CC8_16C590() __asm__("func_00176CC8");
M2C_UNK func_00266DE0_16C590() __asm__("func_00266DE0");
M2C_UNK func_00266EB0_16C590() __asm__("func_00266EB0");
s32 netGetMyClientIndex_16C590() __asm__("netGetMyClientIndex");
M2C_UNK printf_16C590() __asm__("printf");
extern M2C_UNK D_002B8A00_16C590 __asm__("D_002B8A00");
extern M2C_UNK D_003156C0_16C590 __asm__("D_003156C0");
extern M2C_UNK D_004E6500_16C590 __asm__("D_004E6500");
extern M2C_UNK D_004E6A00_16C590 __asm__("D_004E6A00");
extern void* D_004FA030_16C590 __asm__("D_004FA030");
static M2C_UNK D_004E6BB0;                          /* unable to generate initializer: unknown type; const */

void func_0016C590(s32 arg0, s32 arg1) {
    u8 sp[0x4];
    s32 temp_s0;

    temp_s0 = func_001733F8_16C590(&D_003156C0_16C590);
    printf_16C590("In HostChangeCallback...\n");
    switch (temp_s0) {                              /* irregular */
    case 1:
        if (func_00176B10_16C590(&D_003156C0_16C590, 1) <= 0) {
            printf_16C590(&D_004E6A00_16C590, &D_003156C0_16C590);
            if (func_00176CC8_16C590(&D_003156C0_16C590) != 0) {
                printf_16C590(&D_004E6BB0);
                M2C_FIELD(&D_003156C0_16C590, s32* , 0x1BB0) = temp_s0;
                func_00174988_16C590(&D_003156C0_16C590, -1);
            }
        }
        if ((arg1 == *M2C_FIELD(&D_003156C0_16C590, s32** , 4)) && (M2C_FIELD(D_004FA030_16C590, s32* , 0x9FD9C) != 0) && (M2C_FIELD(&D_003156C0_16C590, s32* , 0x3230) == 0)) {
            func_00171F88_16C590(&D_003156C0_16C590, &D_003156C0_16C590);
        }
        break;
    case 2:
        func_00266DE0_16C590(&D_003156C0_16C590 + 0x307C, M2C_FIELD(&D_003156C0_16C590, s32* , 0x2CF0));
        printf_16C590(&D_004E6500_16C590);
        printf_16C590(">>>>> 6 Setting ConnectionSessionMaster = %d\n\0BASCUS-97196\0\0\0 !\"#$%&'()*+,-.0123456789:;<=>?ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_abcdefghijklmnopqrstuvwxyz{}\0\00123456789\0\0 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\0 .0123456789", M2C_FIELD(&D_003156C0_16C590, M2C_UNK** , 0x307C));
        printf_16C590(&D_004E6500_16C590);
        break;
    }
    if (M2C_FIELD(&D_003156C0_16C590, s32* , 0x2E90) == 0) {
        if (M2C_FIELD(&D_003156C0_16C590, s32* , 0x1BB4) > 0) {
            if (arg1 == netGetMyClientIndex_16C590(&D_003156C0_16C590, 0)) {
                M2C_FIELD(&D_002B8A00_16C590, s32* , 0xE0) = 1;
                func_00266EB0_16C590(sp, M2C_FIELD(&D_003156C0_16C590, s32* , 0x2CF0));
                M2C_FIELD(&D_002B8A00_16C590, s32* , 0xEC) = (s32) subroutine_arg0;
            }
        }
    }
    M2C_FIELD(M2C_FIELD(&D_003156C0_16C590, void** , 0x3148), s8* , 0x24) = func_00176B10_16C590(&D_003156C0_16C590, 0);
}
//@@ func_0016C738 m2c0
#include "m2c_macros.h"
void func_0016C738(void* arg0) {
    M2C_FIELD(arg0, s8* , 0x14) = 0;
    M2C_FIELD(arg0, s8* , 4) = 0;
}
//@@ func_0016C748 m2c0
#include "m2c_macros.h"
M2C_UNK func_00161598_16C748() __asm__("func_00161598");
M2C_UNK func_0016E7D0_16C748() __asm__("func_0016E7D0");
s32 timerGetCurTics__Fv_16C748() __asm__("timerGetCurTics__Fv");
extern M2C_UNK D_004E6D30_16C748 __asm__("D_004E6D30");
extern M2C_UNK D_004F9D38_16C748 __asm__("D_004F9D38");
extern s32 D_004F9D9C_16C748 __asm__("D_004F9D9C");

void func_0016C748(void* arg0) {
    M2C_FIELD(arg0, s32* , 0x4294) = 0xEA60;
    M2C_FIELD(arg0, s32* , 0x4268) = 0;
    M2C_FIELD(arg0, s32* , 0x4258) = 0;
    M2C_FIELD(arg0, s32* , 0x425C) = 0;
    M2C_FIELD(arg0, s32* , 0x4260) = 0;
    M2C_FIELD(arg0, s32* , 0x4264) = 0;
    M2C_FIELD(arg0, s32* , 0x1BBC) = 0;
    M2C_FIELD(arg0, s32* , 0x4270) = 0;
    M2C_FIELD(arg0, s32* , 0x4274) = 0;
    M2C_FIELD(arg0, s32* , 0x4278) = 0;
    M2C_FIELD(arg0, s32* , 0x427C) = 0;
    M2C_FIELD(arg0, s32* , 0x4280) = 0;
    M2C_FIELD(arg0, s32* , 0x1BB8) = 0;
    M2C_FIELD(arg0, s32* , 0x426C) = 0;
    D_004F9D9C_16C748 = timerGetCurTics__Fv_16C748();
    func_0016E7D0_16C748(0);
    func_00161598_16C748(&D_004F9D38_16C748, "cdrom0:\\NET\\NETCNF.IRX;1", 0x3A, &D_004E6D30_16C748);
}
//@@ func_0016C7D0 m2c0
#include "m2c_macros.h"
M2C_UNK func_00161508_16C7D0() __asm__("func_00161508");
M2C_UNK func_00161588_16C7D0() __asm__("func_00161588");
M2C_UNK func_002587F0_16C7D0() __asm__("func_002587F0");
s32 func_00258850_16C7D0() __asm__("func_00258850");
s32 func_00258910_16C7D0() __asm__("func_00258910");
s32* func_002589D0_16C7D0() __asm__("func_002589D0");
s32 func_00258A50_16C7D0() __asm__("func_00258A50");
s32 func_00258B98_16C7D0() __asm__("func_00258B98");
M2C_UNK memset_16C7D0() __asm__("memset");
M2C_UNK printf_16C7D0() __asm__("printf");
extern s32 D_00313F40_16C7D0 __asm__("D_00313F40");
extern M2C_UNK D_00313F70_16C7D0 __asm__("D_00313F70");
extern M2C_UNK D_00314380_16C7D0 __asm__("D_00314380");
extern M2C_UNK D_004F9D40_16C7D0 __asm__("D_004F9D40");

void func_0016C7D0(void* arg0) {
    M2C_UNK* var_a2;
    M2C_UNK* var_s1_2;
    s32 temp_v0;
    s32 var_a1;
    s32 var_s0;
    s32 var_s1;
    s32 var_v1;
    s32* temp_v0_2;
    void* var_v0;

    printf_16C7D0("\nNETINIT: Reading the Network Configuration Files\n");
    M2C_FIELD(arg0, s32* , 0x1BC4) = 0;
    func_00161508_16C7D0();
    temp_v0 = func_00258910_16C7D0(&D_004F9D40_16C7D0, &D_00313F40_16C7D0);
    if (temp_v0 > 0) {
        M2C_FIELD(arg0, s32** , 0x43D0) = &D_00313F40_16C7D0;
    }
    var_s1 = 0;
    M2C_FIELD(arg0, s32* , 0x4278) = func_00258850_16C7D0(&D_004F9D40_16C7D0, 0);
    M2C_FIELD(arg0, s32* , 0x427C) = func_00258850_16C7D0(&D_004F9D40_16C7D0, 1);
    M2C_FIELD(arg0, s32* , 0x4280) = func_00258850_16C7D0(&D_004F9D40_16C7D0, 2);
    M2C_FIELD(arg0, s32* , 0xB788) = 0;
    M2C_FIELD(arg0, s32* , 0xB788) = func_00258A50_16C7D0(&D_00313F40_16C7D0);
    var_a1 = 0;
    if (D_00313F40_16C7D0 > 0) {
        do {
            temp_v0_2 = func_002589D0_16C7D0(&D_00313F40_16C7D0, var_a1);
            if ((temp_v0_2 != NULL) && (*temp_v0_2 != 0) && (var_s1 < 6)) {
                var_v1 = var_s1 + 1;
                if (func_00258B98_16C7D0(&D_004F9D40_16C7D0, temp_v0_2 + 8, &D_00314380_16C7D0) == 0) {
                    var_a2 = &D_00314380_16C7D0;
                    var_v0 = (var_s1 * 0x1340) + arg0 + 0x4400;
                    do {
                        M2C_FIELD(var_v0, s128* , 0) = (s128) M2C_FIELD(var_a2, s128* , 0);
                        M2C_FIELD(var_v0, s128* , 0x10) = (s128) M2C_FIELD(var_a2, s128* , 0x10);
                        var_a2 += 0x20;
                        var_v0 += 0x20;
                    } while (var_a2 != (&D_00314380_16C7D0 + 0x1340));
                }
            } else {
                memset_16C7D0(arg0 + ((var_s1 * 0x1340) + 0x4400), 0, 0x1340);
                var_v1 = var_s1 + 1;
            }
            var_s1 = var_v1;
            var_a1 = var_s1;
        } while (var_s1 < D_00313F40_16C7D0);
    }
    func_002587F0_16C7D0();
    if (M2C_FIELD(arg0, s32* , 0x4278) > 0) {
        if (temp_v0 > 0) {
            M2C_FIELD(arg0, s32* , 0x1BB8) = 1;
            M2C_FIELD(arg0, s32* , 0x4258) = 1;
        } else {
            goto block_17;
        }
    } else {
block_17:
        M2C_FIELD(arg0, s32* , 0x4258) = 0;
        M2C_FIELD(arg0, s32* , 0xB788) = 0;
        M2C_FIELD(arg0, s32* , 0x1BC4) = temp_v0;
        M2C_FIELD(arg0, s32* , 0x425C) = 0;
        M2C_FIELD(arg0, s32* , 0x4260) = 0;
        M2C_FIELD(arg0, s32* , 0x1BB8) = 0;
    }
    if (M2C_FIELD(arg0, s32* , 0x4258) != 0) {
        var_s0 = 0;
        printf_16C7D0("NETINIT: Configuration Count = %d\n", M2C_FIELD(arg0, s32* , 0x4278));
        printf_16C7D0("NETINIT: Interface Count = %d\n", M2C_FIELD(arg0, s32* , 0x427C));
        printf_16C7D0("NETINIT: Device Count = %d\n", M2C_FIELD(arg0, s32* , 0x4280));
        printf_16C7D0("NETINIT: Memory Card can hold %d Configurations\n", M2C_FIELD(M2C_FIELD(arg0, s32** , 0x43D0), s32* , 0));
        printf_16C7D0("NETINIT: Default Configuration = %d\n", M2C_FIELD(M2C_FIELD(arg0, s32** , 0x43D0), s32* , 4));
        printf_16C7D0("NETINIT: Listing all configurations...\n");
        if (M2C_FIELD(M2C_FIELD(arg0, s32** , 0x43D0), s32* , 0) > 0) {
            var_s1_2 = &D_00313F70_16C7D0;
            do {
                printf_16C7D0("NETINIT: Configuration #%d\n", var_s0);
                var_s0 += 1;
                func_00161588_16C7D0(var_s1_2);
                var_s1_2 += 0x68;
            } while (var_s0 < M2C_FIELD(M2C_FIELD(arg0, s32** , 0x43D0), s32* , 0));
        }
        printf_16C7D0("...Done Listing Configurations.\n\n");
    }
}
//@@ func_0016CA88 m2c0
#include "m2c_macros.h"
s32* func_002589D0_16CA88() __asm__("func_002589D0");
s32 func_00298010_16CA88() __asm__("func_00298010");
M2C_UNK printf_16CA88() __asm__("printf");
extern M2C_UNK D_003156C0_16CA88 __asm__("D_003156C0");
extern M2C_UNK D_004F9D48_16CA88 __asm__("D_004F9D48");

s32 func_0016CA88(void* arg0, s32 arg1) {
    s32* temp_v0;

    M2C_FIELD(&D_003156C0_16CA88, s32* , 0x2DFC) = 8;
    M2C_FIELD(&D_003156C0_16CA88, s32* , 0x2DF8) = 8;
    M2C_FIELD(arg0, s32** , 0xB780) = NULL;
    temp_v0 = func_002589D0_16CA88(M2C_FIELD(arg0, s32* , 0x43D0));
    M2C_FIELD(arg0, s32** , 0xB780) = temp_v0;
    if (*temp_v0 != 0) {
        M2C_FIELD(arg0, void** , 0xB784) = (void* ) (arg0 + ((arg1 * 0x1340) + 0x4400));
        printf_16CA88("NETINIT: Evaluating the Network Configuration %d...\n", arg1);
        if (M2C_FIELD(arg0, s32* , 0x4278) > 0) {
            if (func_00298010_16CA88(M2C_FIELD(arg0, void** , 0xB784) + 0xE00, &D_004F9D48_16CA88, 3) == 0) {
                M2C_FIELD(arg0, s32* , 0x4260) = 0;
                M2C_FIELD(arg0, s32* , 0x425C) = 1;
                printf_16CA88("    Using the Sony Duel Network Adapter\n");
            } else {
                M2C_FIELD(arg0, s32* , 0x425C) = 0;
                M2C_FIELD(arg0, s32* , 0x4260) = 1;
                printf_16CA88("    Using a USB Network Adapter\n");
            }
            M2C_FIELD(arg0, s32* , 0x1BB8) = 2;
        } else {
            M2C_FIELD(arg0, s32** , 0xB780) = NULL;
            M2C_FIELD(arg0, s32* , 0x4260) = 0;
            M2C_FIELD(arg0, s32* , 0x425C) = 0;
        }
        return arg1;
    }
    return -1;
}
//@@ func_0016CB90 m2c0
#include "m2c_macros.h"
s32 func_0016CA88_16CB90() __asm__("func_0016CA88");
s32 func_0016CD88_16CB90() __asm__("func_0016CD88");
s32 func_0016D238_16CB90() __asm__("func_0016D238");
s32 func_0016D3B0_16CB90() __asm__("func_0016D3B0");
s32 func_0016D4F8_16CB90() __asm__("func_0016D4F8");
s32 func_001A9590_16CB90() __asm__("func_001A9590");
M2C_UNK printf_16CB90() __asm__("printf");

s32 func_0016CB90(void* arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a1;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;

    temp_v1 = M2C_FIELD(arg0, s32* , 0x1BB8);
    var_a1 = 0;
    if (temp_v1 == 1) {
        if (arg1 == 0) {
            M2C_FIELD(arg0, s32* , 0x4264) = 0;
            M2C_FIELD(arg0, s32* , 0x4268) = 0;
            M2C_FIELD(arg0, s32* , 0x426C) = 0;
            do {

            } while (func_001A9590_16CB90() != 0);
            var_v0 = 0;
            if (M2C_FIELD(arg0, s32* , 0x1BB8) <= 0) {
                printf_16CB90("ERROR: No Config File on the Mem Card - cannot play a network game!!!\n");
                return -1;
            }
            /* Duplicate return node #34. Try simplifying control flow for better match */
            return var_v0;
        }
        if (arg1 == temp_v1) {
            var_a1 = (M2C_FIELD(arg0, s32* , 0x4274) == 0) ? 0 : 0x3E7;
        }
        var_v0_2 = arg1 < 0x14;
        if (arg1 == 2) {
            return func_0016CA88_16CB90(arg0, M2C_FIELD(arg0, s32* , 0x4284) + 1);
        }
        goto block_11;
    }
    var_v0_2 = arg1 < 0x14;
block_11:
    var_v0 = var_a1;
    if (var_v0_2 == 0) {
        temp_v1_2 = M2C_FIELD(arg0, s32* , 0x1BB8);
        if (temp_v1_2 == 2) {
            return func_0016CD88_16CB90(arg0, arg1);
        }
        if ((arg1 < 0x15) || (var_v0 = -1, ((temp_v1_2 < 2) == 0))) {
            var_v0_3 = arg1 < 0x83;
            if (M2C_FIELD(arg0, s32* , 0x1BB8) == 3) {
                if ((u32) (arg1 - 0x82) < 0xAU) {
                    var_a1 = func_0016D238_16CB90(arg0, arg1);
                }
                var_a1 = ((arg1 ^ 0x8C) == 0) ? 0x3E7 : var_a1;
                if (arg1 == 0x8D) {
                    var_a1 = func_0016D3B0_16CB90(arg0, var_a1);
                }
                var_v0_3 = arg1 < 0x83;
            }
            if ((var_v0_3 != 0) || (var_v0 = -1, ((M2C_FIELD(arg0, s32* , 0x1BB8) < 3) == 0))) {
                var_v0_4 = arg1 < 0x97;
                if (M2C_FIELD(arg0, s32* , 0x1BB8) == 4) {
                    var_v0_4 = arg1 < 0x97;
                    if ((u32) (arg1 - 0x96) < 0x1EU) {
                        var_a1 = func_0016D4F8_16CB90(arg0, arg1);
                        var_v0_4 = arg1 < 0x97;
                    }
                }
                temp_a0 = M2C_FIELD(arg0, s32* , 0x1BB8);
                if ((var_v0_4 != 0) || (var_v0 = -1, ((temp_a0 < 4) == 0))) {
                    if (arg1 >= 0xB4) {
                        var_v0 = -1;
                        if (temp_a0 >= 5) {
                            goto block_32;
                        }
                    } else {
block_32:
                        var_v0 = var_a1;
                        if (temp_a0 == 5) {
                            var_v0 = ((arg1 ^ 0xB4) == 0) ? 0x3E7 : var_a1;
                        }
                    }
                }
            }
        }
        /* Duplicate return node #34. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
//@@ func_0016CD88 m2c0
#include "m2c_macros.h"
s32 func_00161548_16CD88() __asm__("func_00161548");
s32 func_00161598_16CD88() __asm__("func_00161598");
M2C_UNK func_00290058_16CD88() __asm__("func_00290058");
extern M2C_UNK D_003156C0_16CD88 __asm__("D_003156C0");
extern M2C_UNK D_004F9D38_16CD88 __asm__("D_004F9D38");
extern M2C_UNK D_004F9D50_16CD88 __asm__("D_004F9D50");

s32 func_0016CD88(void* arg0, s32 arg1) {
    M2C_UNK var_a2;
    M2C_UNK* var_a1;
    M2C_UNK* var_a3;
    s32 temp_a0;
    s32 var_s0;

    var_s0 = ((arg1 ^ 0x14) != 0) ? 0 : 0x3E7;
    if (arg1 == 0x19) {
        var_s0 = (M2C_FIELD(arg0, s32* , 0x4274) != 0) ? 0x3E7 : var_s0;
    }
    if (arg1 == 0x1D) {
        var_s0 = func_00161598_16CD88(&D_004F9D38_16CD88, "cdrom0:\\NET\\INET.IRX;1", 0, NULL);
    }
    if (arg1 == 0x1E) {
        var_s0 = (M2C_FIELD(arg0, s32* , 0x4274) != 0) ? 0x3E7 : var_s0;
    }
    if (arg1 == 0x27) {
        var_s0 = func_00161598_16CD88(&D_004F9D38_16CD88, "cdrom0:\\NET\\INETCTL.IRX;1", 9, "-no_auto");
    }
    temp_a0 = M2C_FIELD(M2C_FIELD(arg0, void** , 0xB780), s32* , 4);
    if (temp_a0 != 2) {
        if (temp_a0 < 3) {
            if (temp_a0 != 1) {
                M2C_FIELD(arg0, s32* , 0x1BBC) = 0;
                goto block_55;
            }
            M2C_FIELD(&D_003156C0_16CD88, s32* , 0x2DFC) = 2;
            M2C_FIELD(&D_003156C0_16CD88, s32* , 0x4264) = temp_a0;
            M2C_FIELD(&D_003156C0_16CD88, s32* , 0x2DF8) = 2;
            if (arg1 == 0x28) {
                var_s0 = (M2C_FIELD(arg0, s32* , 0x4274) != 0) ? 0x3E7 : var_s0;
            }
            if (arg1 == 0x31) {
                var_s0 = func_00161598_16CD88(&D_004F9D38_16CD88, "cdrom0:\\NET\\PPP.IRX;1", 0, NULL);
            }
            if (M2C_FIELD(arg0, s32* , 0x425C) != 0) {
                if (arg1 == 0x3C) {
                    var_s0 = (M2C_FIELD(arg0, s32* , 0x4274) != 0) ? 0x3E7 : var_s0;
                }
                if (arg1 == 0x45) {
                    var_s0 = func_00161598_16CD88(&D_004F9D38_16CD88, "cdrom0:\\NET\\DEV9.IRX;1", 0, NULL);
                }
                if (arg1 == 0x5A) {
                    var_s0 = (M2C_FIELD(arg0, s32* , 0x4274) != 0) ? 0x3E7 : var_s0;
                }
                if (arg1 == 0x63) {
                    var_s0 = func_00161598_16CD88(&D_004F9D38_16CD88, "cdrom0:\\NET\\SPDUART.IRX;1", 0x20, "dial=cdrom0:\\NET\\DIAL_SPD.CNF;1");
                }
            }
            if (M2C_FIELD(arg0, s32* , 0x4260) != 0) {
                if (arg1 == 0x64) {
                    var_s0 = (M2C_FIELD(arg0, s32* , 0x4274) != 0) ? 0x3E7 : var_s0;
                }
                if (arg1 == 0x6D) {
                    var_a1 = "cdrom0:\\NET\\CXTMDM.IRX;1";
                    var_a3 = "dial=cdrom0:\\NET\\DIAL_CXT.CNF;1";
                    var_a2 = 0x20;
                    goto block_54;
                }
            }
            goto block_57;
        }
        if (temp_a0 != 3) {
            M2C_FIELD(arg0, s32* , 0x1BBC) = 0;
block_55:
            return -1;
        }
        goto block_22;
    }
    if (arg1 == 0x28) {
        var_s0 = (M2C_FIELD(arg0, s32* , 0x4274) != 0) ? 0x3E7 : var_s0;
    }
    if (arg1 == 0x31) {
        var_s0 = func_00161598_16CD88(&D_004F9D38_16CD88, "cdrom0:\\NET\\PPP.IRX;1", 0, NULL);
    }
    if (arg1 == 0x32) {
        var_s0 = (M2C_FIELD(arg0, s32* , 0x4274) != 0) ? 0x3E7 : var_s0;
    }
    if (arg1 == 0x3B) {
        var_s0 = func_00161598_16CD88(&D_004F9D38_16CD88, "cdrom0:\\NET\\PPPOE.IRX;1", 0, NULL);
    }
block_22:
    if (M2C_FIELD(arg0, s32* , 0x425C) != 0) {
        if (arg1 == 0x3C) {
            var_s0 = (M2C_FIELD(arg0, s32* , 0x4274) != 0) ? 0x3E7 : var_s0;
        }
        if (arg1 == 0x45) {
            var_s0 = func_00161598_16CD88(&D_004F9D38_16CD88, "cdrom0:\\NET\\DEV9.IRX;1", 0, NULL);
        }
        if (arg1 == 0x46) {
            var_s0 = (M2C_FIELD(arg0, s32* , 0x4274) != 0) ? 0x3E7 : var_s0;
        }
        if (arg1 == 0x4F) {
            var_s0 = func_00161598_16CD88(&D_004F9D38_16CD88, "cdrom0:\\NET\\SMAP.IRX;1", 0, NULL);
        }
    }
    if (M2C_FIELD(arg0, s32* , 0x4260) != 0) {
        if (arg1 == 0x50) {
            var_s0 = (M2C_FIELD(arg0, s32* , 0x4274) != 0) ? 0x3E7 : var_s0;
        }
        if (arg1 == 0x59) {
            var_a1 = "cdrom0:\\NET\\AN986.IRX;1";
            var_a2 = 0;
            var_a3 = NULL;
block_54:
            var_s0 = func_00161598_16CD88(&D_004F9D38_16CD88, var_a1, var_a2, var_a3);
        }
    }
block_57:
    if (arg1 == 0x6E) {
        var_s0 = (M2C_FIELD(arg0, s32* , 0x4274) != 0) ? 0x3E7 : var_s0;
    }
    if (arg1 == 0x72) {
        var_s0 = func_00161598_16CD88(&D_004F9D38_16CD88, "cdrom0:\\NET\\MSIFRPC.IRX;1", 0, NULL);
    }
    if (arg1 == 0x73) {
        var_s0 = (M2C_FIELD(arg0, s32* , 0x4274) != 0) ? 0x3E7 : var_s0;
    }
    if (arg1 == 0x77) {
        var_s0 = func_00161598_16CD88(&D_004F9D38_16CD88, "cdrom0:\\NET\\LIBNETB.IRX;1", 8, &D_004F9D50_16CD88);
        func_00290058_16CD88(0);
    }
    if (arg1 == 0x78) {
        var_s0 = (M2C_FIELD(arg0, s32* , 0x4274) != 0) ? 0x3E7 : var_s0;
    }
    if (arg1 == 0x7C) {
        var_s0 = func_00161548_16CD88();
    }
    if (arg1 == 0x7D) {
        M2C_FIELD(arg0, s32* , 0x1BB8) = 3;
    }
    return var_s0;
}
//@@ func_0016D238 m2c0
#include "m2c_macros.h"
s32 func_0016D338_16D238() __asm__("func_0016D338");
s32 func_00258D98_16D238() __asm__("func_00258D98");
M2C_UNK func_00258F80_16D238() __asm__("func_00258F80");
s32 func_00259098_16D238() __asm__("func_00259098");
M2C_UNK printf_16D238() __asm__("printf");
s32 timerGetCurTics__Fv_16D238() __asm__("timerGetCurTics__Fv");
extern M2C_UNK D_00319980_16D238 __asm__("D_00319980");
extern s32 D_00319984_16D238 __asm__("D_00319984");
extern s32 D_004F9D60_16D238 __asm__("D_004F9D60");

s32 func_0016D238(void* arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_s1;
    s32 var_v0;
    void* temp_v1;

    var_s1 = ((arg1 ^ 0x82) != 0) ? 0 : 0x3E7;
    if (arg1 == 0x85) {
        var_s1 = func_0016D338_16D238();
    }
    if (arg1 == 0x87) {
        var_s1 = func_00258D98_16D238(M2C_FIELD(arg0, s32* , 0xB784));
        D_00319984_16D238 = var_s1;
        printf_16D238("NETINIT: ezNetCtlSetProperties returned %d\n", var_s1);
    }
    var_v0 = var_s1;
    if (arg1 == 0x89) {
        temp_v0 = func_00259098_16D238(0);
        printf_16D238("NETINIT: ezNetCtlUpInterface returned %d\n", temp_v0);
        if (temp_v0 >= 0) {
            func_00258F80_16D238(&D_00319980_16D238);
            temp_v1 = &D_00319980_16D238 - 0x42C0;
            printf_16D238("(ID=%d:%d) state %d, link %d, Message:[%s]\n", M2C_FIELD(temp_v1, s32* , 0x42C4), M2C_FIELD(temp_v1, s32* , 0x42C0), M2C_FIELD(temp_v1, s32* , 0x42CC));
        }
        M2C_FIELD(arg0, s32* , 0x4290) = 0;
        M2C_FIELD(arg0, s32* , 0x428C) = 0;
        D_004F9D60_16D238 = timerGetCurTics__Fv_16D238();
        var_v0 = temp_v0;
    }
    return var_v0;
}
//@@ func_0016D338 m2c0
#include "m2c_macros.h"
s32 func_00259110_16D338() __asm__("func_00259110");
M2C_UNK printf_16D338() __asm__("printf");
extern s32 D_00319984_16D338 __asm__("D_00319984");

s32 func_0016D338(void* arg0) {
    s32 temp_s1;

    temp_s1 = func_00259110_16D338(0);
    printf_16D338("NETINIT: Taking down the Network Interface...\n");
    printf_16D338("NETINIT: ezNetCtlDownInterface returned %d\n", temp_s1);
    M2C_FIELD(arg0, s32* , 0x1BB8) = 3;
    D_00319984_16D338 = -1;
    M2C_FIELD(arg0, s32* , 0x4290) = 0;
    M2C_FIELD(arg0, s32* , 0x4268) = 0;
    M2C_FIELD(arg0, s32* , 0x426C) = 0;
    M2C_FIELD(arg0, s32* , 0x428C) = 0;
    return temp_s1;
}
//@@ func_0016D3B0 m2c0
#include "m2c_macros.h"
s32 func_00258F80_16D3B0() __asm__("func_00258F80");
M2C_UNK strncpy_16D3B0() __asm__("strncpy");
s32 timerGetCurTics__Fv_16D3B0() __asm__("timerGetCurTics__Fv");
extern M2C_UNK D_00319980_16D3B0 __asm__("D_00319980");
extern s32 D_004F9D58_16D3B0 __asm__("D_004F9D58");
extern s32 D_004F9D5C_16D3B0 __asm__("D_004F9D5C");
extern s32 D_004F9D60_16D3B0 __asm__("D_004F9D60");

s32 func_0016D3B0(void* arg0) {
    s32 temp_a0;
    s32 temp_a3;
    s32 temp_s3;
    s32 temp_v0;
    s32 var_v0;
    void* temp_s1;

    temp_s1 = &D_00319980_16D3B0 - 0x42C0;
    temp_s3 = func_00258F80_16D3B0(&D_00319980_16D3B0);
    temp_a0 = timerGetCurTics__Fv_16D3B0();
    if ((M2C_FIELD(temp_s1, s32* , 0x42CC) != D_004F9D58_16D3B0) || (M2C_FIELD(temp_s1, s32* , 0x42C8) != D_004F9D5C_16D3B0)) {
        temp_v0 = timerGetCurTics__Fv_16D3B0(temp_a0);
        temp_a3 = M2C_FIELD(temp_s1, s32* , 0x42CC);
        D_004F9D5C_16D3B0 = M2C_FIELD(temp_s1, s32* , 0x42C8);
        D_004F9D60_16D3B0 = temp_v0;
        D_004F9D58_16D3B0 = temp_a3;
        strncpy_16D3B0(arg0 + 0x1BC8, &D_00319980_16D3B0 + 0x10, 0x100, temp_a3);
        M2C_FIELD(arg0, s32* , 0x1BC4) = (s32) M2C_FIELD(temp_s1, s32* , 0x42CC);
        if (M2C_FIELD(temp_s1, s32* , 0x42CC) == 3) {
            M2C_FIELD(arg0, s32* , 0x4268) = 1;
            M2C_FIELD(arg0, s32* , 0x1BB8) = 4;
            M2C_FIELD(arg0, s32* , 0x426C) = 0;
        }
        var_v0 = M2C_FIELD(temp_s1, s32* , 0x42CC);
        if (M2C_FIELD(temp_s1, s32* , 0x42CC) == 5) {
            M2C_FIELD(arg0, s32* , 0x1BB8) = 3;
            M2C_FIELD(arg0, s32* , 0x4268) = 0;
            M2C_FIELD(arg0, s32* , 0x426C) = 0;
            return -1;
        }
        /* Duplicate return node #9. Try simplifying control flow for better match */
        return var_v0;
    }
    if (M2C_FIELD(arg0, s32* , 0x4294) >= 0x44100000) {
        return temp_s3;
    }
    strncpy_16D3B0(arg0 + 0x1BC8, &D_00319980_16D3B0 + 0x10, 0x100);
    var_v0 = -1;
    M2C_FIELD(arg0, s32* , 0x1BC4) = 6;
    return var_v0;
}
//@@ func_0016D4F8 m2c0
#include "m2c_macros.h"
s32 func_0010A210_16D4F8() __asm__("func_0010A210");
s32 func_001653D8_16D4F8() __asm__("func_001653D8");
M2C_UNK func_00265A50_16D4F8() __asm__("func_00265A50");
M2C_UNK func_002666A8_16D4F8() __asm__("func_002666A8");
s32 netInitDme_16D4F8() __asm__("netInitDme");
M2C_UNK printf_16D4F8() __asm__("printf");
extern M2C_UNK D_002B8A00_16D4F8 __asm__("D_002B8A00");
extern M2C_UNK D_002C1690_16D4F8 __asm__("D_002C1690");

s32 func_0016D4F8(void* arg0, s32 arg1) {
    s32 var_s2;
    s32 var_s2_2;
    s32 var_v0;
    void* temp_s0;

    var_s2 = 0;
    if (arg1 == 0x96) {
        var_s2 = (M2C_FIELD(arg0, s32* , 0x4274) == 0) ? 0 : 0x3E7;
    }
    switch (arg1) {                                 /* irregular */
    case 0x9F:
        var_s2 = netInitDme_16D4F8(arg0);
        if (var_s2 <= 0) {
            M2C_FIELD(arg0, s32* , 0x1BBC) = 0;
            return -1;
        }
        func_00265A50_16D4F8(0x4000, 0x4000);
        temp_s0 = arg0 + 0x1A94;
        func_002666A8_16D4F8(temp_s0);
        printf_16D4F8("Local IP Address: [%s]\n", temp_s0);
        if (arg1 == 0xA0) {
        case 0xA0:
            var_s2 = (M2C_FIELD(arg0, s32* , 0x4274) != 0) ? 0x3E7 : var_s2;
        }
        if (arg1 == 0xA9) {
        case 0xA9:
            var_s2 = -1;
            if (func_001653D8_16D4F8(&D_002C1690_16D4F8) != 0) {
                M2C_FIELD(arg0, s32* , 0x1BBC) = 0;
            } else {
                var_s2 = 1;
            }
        }
        if (arg1 == 0xAA) {
        case 0xAA:
            var_s2 = (M2C_FIELD(arg0, s32* , 0x4274) != 0) ? 0x3E7 : var_s2;
        }
    default:
        var_v0 = var_s2;
        if (arg1 == 0xB3) {
            if (func_0010A210_16D4F8(&D_002B8A00_16D4F8) == 0) {
                M2C_FIELD(arg0, s32* , 0x1BBC) = 0;
                var_s2_2 = -1;
            } else {
                M2C_FIELD(arg0, s32* , 0x1BB8) = 5;
                var_s2_2 = 1;
                M2C_FIELD(arg0, s32* , 0x1BBC) = 1;
            }
            var_v0 = var_s2_2;
        }
        return var_v0;
    }
}
//@@ func_0016D638 m2c0
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
//@@ func_0016D690 m2c0
#include "m2c_macros.h"
M2C_UNK func_00258F80_16D690() __asm__("func_00258F80");
M2C_UNK printf_16D690() __asm__("printf");
M2C_UNK strncpy_16D690() __asm__("strncpy");
s32 timerGetCurTics__Fv_16D690() __asm__("timerGetCurTics__Fv");
extern M2C_UNK D_003156C0_16D690 __asm__("D_003156C0");
extern M2C_UNK D_00319980_16D690 __asm__("D_00319980");
extern s32 D_004F9D58_16D690 __asm__("D_004F9D58");
extern s32 D_004F9D5C_16D690 __asm__("D_004F9D5C");
extern s32 D_004F9D9C_16D690 __asm__("D_004F9D9C");

s32 func_0016D690(void* arg0) {
    s32 temp_v1;
    s32 var_v0;

    timerGetCurTics__Fv_16D690();
    if (0x44100000 >= 0x3E9) {
        func_00258F80_16D690(&D_00319980_16D690);
        D_004F9D9C_16D690 = timerGetCurTics__Fv_16D690();
    }
    if ((M2C_FIELD(&D_003156C0_16D690, s32* , 0x42CC) != D_004F9D58_16D690) || (M2C_FIELD(&D_003156C0_16D690, s32* , 0x42C8) != D_004F9D5C_16D690)) {
        printf_16D690("(ID=%d:%d) state %d -> %d, link %d, Message:[%s]\n", M2C_FIELD(&D_003156C0_16D690, s32* , 0x42C4), M2C_FIELD(&D_003156C0_16D690, s32* , 0x42C0), D_004F9D58_16D690);
        D_004F9D5C_16D690 = M2C_FIELD(&D_003156C0_16D690, s32* , 0x42C8);
        D_004F9D58_16D690 = M2C_FIELD(&D_003156C0_16D690, s32* , 0x42CC);
    }
    temp_v1 = M2C_FIELD(arg0, s32* , 0x4264);
    if (temp_v1 != 0) {
        var_v0 = 0;
        if (M2C_FIELD(&D_003156C0_16D690, s32* , 0x42CC) == 5) {
            strncpy_16D690(arg0 + 0x1BC8, &D_003156C0_16D690 + 0x42D0, 0x100);
            M2C_FIELD(arg0, s32* , 0x1BC4) = (s32) M2C_FIELD(&D_003156C0_16D690, s32* , 0x42CC);
            return -1;
        }
        /* Duplicate return node #9. Try simplifying control flow for better match */
        return var_v0;
    }
    var_v0 = (temp_v1 >= M2C_FIELD(&D_003156C0_16D690, s32* , 0x42C8)) ? -1 : M2C_FIELD(&D_003156C0_16D690, s32* , 0x42C8);
    return var_v0;
}
//@@ func_0016D7C0 m2c0
#include "m2c_macros.h"
M2C_UNK func_0016D338_16D7C0() __asm__("func_0016D338");
M2C_UNK func_0016D638_16D7C0() __asm__("func_0016D638");

void func_0016D7C0(s32 arg0) {
    func_0016D638_16D7C0();
    func_0016D338_16D7C0(arg0);
}
//@@ func_0016D7F0 m2c0
#include "m2c_macros.h"
s32 func_0016D7F0(void* arg0) {
    return M2C_FIELD(arg0, s32* , 0x4258);
}
//@@ func_0016D7F8 m2c0
#include "m2c_macros.h"
s32 func_0016D7F8(void* arg0) {
    return M2C_FIELD(arg0, s32* , 0x4278);
}
//@@ func_0016D800 m2c0
#include "m2c_macros.h"
s32 func_0016D800(void* arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32* , 0x43D0);
    if (temp_v1 == 0) {
        return 0;
    }
    return (arg1 * 0x68) + temp_v1 + 0x38;
}
//@@ func_0016D828 m2c0
#include "m2c_macros.h"
s32 func_0016D828(void) {
    return 1;
}
//@@ netInitDme m2c0
#include "m2c_macros.h"
M2C_UNK dmeMsgLayoutAddField_nitDme() __asm__("dmeMsgLayoutAddField");
M2C_UNK dmeMsgLayoutBegin_nitDme() __asm__("dmeMsgLayoutBegin");
M2C_UNK dmeMsgRegister_nitDme() __asm__("dmeMsgRegister");
M2C_UNK dmeObjLayoutAddField_nitDme() __asm__("dmeObjLayoutAddField");
M2C_UNK dmeObjLayoutBegin_nitDme() __asm__("dmeObjLayoutBegin");
M2C_UNK dmeObjRegisterType_nitDme() __asm__("dmeObjRegisterType");
M2C_UNK dmeObjSetCallbacks_nitDme() __asm__("dmeObjSetCallbacks");
M2C_UNK func_001192E8_nitDme() __asm__("func_001192E8");
M2C_UNK func_00266478_nitDme() __asm__("func_00266478");
s32 func_00266F50_nitDme() __asm__("func_00266F50");
s32 func_00267080_nitDme() __asm__("func_00267080");
M2C_UNK func_00268ED0_nitDme() __asm__("func_00268ED0");
M2C_UNK func_00268F20_nitDme() __asm__("func_00268F20");
M2C_UNK func_00269318_nitDme() __asm__("func_00269318");
M2C_UNK memset_nitDme() __asm__("memset");
M2C_UNK printf_nitDme() __asm__("printf");
extern s32 D_00319924_nitDme __asm__("D_00319924");
extern u8 D_004E72A0_nitDme __asm__("D_004E72A0");
extern s32 D_004F9CA0_nitDme __asm__("D_004F9CA0");
extern s32 D_004F9CA4_nitDme __asm__("D_004F9CA4");
extern s32 D_004F9CA8_nitDme __asm__("D_004F9CA8");
extern s32 D_004F9CAC_nitDme __asm__("D_004F9CAC");
extern s32 D_004F9CB0_nitDme __asm__("D_004F9CB0");
extern s32 D_004F9CB4_nitDme __asm__("D_004F9CB4");
extern M2C_UNK D_004F9CB8_nitDme __asm__("D_004F9CB8");
extern M2C_UNK D_004F9CBC_nitDme __asm__("D_004F9CBC");
extern M2C_UNK D_004F9CC0_nitDme __asm__("D_004F9CC0");
extern M2C_UNK D_004F9CC4_nitDme __asm__("D_004F9CC4");
extern M2C_UNK D_004F9CC8_nitDme __asm__("D_004F9CC8");
extern M2C_UNK D_004F9CCC_nitDme __asm__("D_004F9CCC");
extern M2C_UNK D_004F9CD0_nitDme __asm__("D_004F9CD0");
extern M2C_UNK D_004F9CD4_nitDme __asm__("D_004F9CD4");
extern s32 D_004F9D18_nitDme __asm__("D_004F9D18");
extern s32 D_004F9D24_nitDme __asm__("D_004F9D24");
extern s32 D_004F9D80_nitDme __asm__("D_004F9D80");
extern s32 D_004F9D84_nitDme __asm__("D_004F9D84");
extern s32 D_004F9D88_nitDme __asm__("D_004F9D88");
extern s32 D_004F9D90_nitDme __asm__("D_004F9D90");
extern s32 D_004F9D94_nitDme __asm__("D_004F9D94");
extern s32 D_004F9D98_nitDme __asm__("D_004F9D98");
extern M2C_UNK func_0016C590_nitDme __asm__("func_0016C590");
extern M2C_UNK netFodderUpdateCB_nitDme __asm__("netFodderUpdateCB");
extern M2C_UNK netGameDataUpdateCB_nitDme __asm__("netGameDataUpdateCB");
extern M2C_UNK netMsgChatHandler_nitDme __asm__("netMsgChatHandler");
extern M2C_UNK netMsgGameEventHandler_nitDme __asm__("netMsgGameEventHandler");
extern M2C_UNK netMsgPlayerInfoHandler_nitDme __asm__("netMsgPlayerInfoHandler");
extern M2C_UNK netMsgRosterHandler_nitDme __asm__("netMsgRosterHandler");
extern M2C_UNK netMsgSessionHandler_nitDme __asm__("netMsgSessionHandler");
extern M2C_UNK netMsgWorldEventHandler_nitDme __asm__("netMsgWorldEventHandler");
extern M2C_UNK netObjCreateCB_nitDme __asm__("netObjCreateCB");
extern M2C_UNK netObjDestroyCB_nitDme __asm__("netObjDestroyCB");
extern M2C_UNK netObjUpdateVehicleCB_nitDme __asm__("netObjUpdateVehicleCB");
extern M2C_UNK netPadFlagsUpdateCB_nitDme __asm__("netPadFlagsUpdateCB");
extern M2C_UNK netStatsUpdateCB_nitDme __asm__("netStatsUpdateCB");
extern M2C_UNK netWeaponCreateCB_nitDme __asm__("netWeaponCreateCB");
extern M2C_UNK netWeaponDestroyCB_nitDme __asm__("netWeaponDestroyCB");
extern M2C_UNK netWeaponUpdateCB_nitDme __asm__("netWeaponUpdateCB");

s32 netInitDme(void) {
    u8 sp[0xA50];
    M2C_UNK sp1;
    u8 sp100;
    M2C_UNK sp101;
    M2C_UNK sp200;
    s32 sp204;
    s32 sp208;
    M2C_UNK sp220;
    s32 sp240;
    s32 sp244;
    s64 sp248;
    s8 sp250;
    s32 sp260;
    s32 sp264;
    s64 sp268;
    s8 sp270;
    s32 sp280;
    s32 sp284;
    s64 sp288;
    s8 sp290;
    s32 sp2A0;
    s32 sp2A4;
    s64 sp2A8;
    s8 sp2B0;
    s32 sp2C0;
    s32 sp2C4;
    s64 sp2C8;
    s8 sp2D0;
    M2C_UNK sp2DC;
    M2C_UNK sp2E4;
    M2C_UNK sp2E8;
    M2C_UNK sp2F4;
    M2C_UNK sp300;
    M2C_UNK sp30C;
    M2C_UNK sp30E;
    M2C_UNK sp310;
    M2C_UNK sp312;
    M2C_UNK sp314;
    M2C_UNK sp316;
    M2C_UNK sp318;
    M2C_UNK sp319;
    M2C_UNK sp31A;
    M2C_UNK sp31B;
    M2C_UNK sp320;
    M2C_UNK sp348;
    M2C_UNK sp34C;
    M2C_UNK sp350;
    M2C_UNK sp354;
    M2C_UNK sp360;
    M2C_UNK sp368;
    M2C_UNK sp36C;
    M2C_UNK sp370;
    M2C_UNK sp378;
    M2C_UNK sp380;
    M2C_UNK sp390;
    M2C_UNK sp394;
    M2C_UNK sp398;
    M2C_UNK sp39C;
    M2C_UNK sp3A0;
    M2C_UNK sp3C0;
    M2C_UNK sp3DC;
    M2C_UNK sp3E0;
    M2C_UNK sp3E4;
    M2C_UNK sp400;
    M2C_UNK sp414;
    M2C_UNK sp464;
    M2C_UNK sp46E;
    M2C_UNK sp470;
    M2C_UNK sp474;
    M2C_UNK sp478;
    M2C_UNK sp47B;
    M2C_UNK sp47C;
    M2C_UNK sp480;
    M2C_UNK sp485;
    M2C_UNK sp486;
    M2C_UNK sp488;
    M2C_UNK sp48C;
    M2C_UNK sp490;
    M2C_UNK sp494;
    M2C_UNK sp498;
    M2C_UNK sp49A;
    M2C_UNK sp49B;
    M2C_UNK sp49C;
    M2C_UNK sp4A0;
    M2C_UNK sp55C;
    M2C_UNK sp55E;
    M2C_UNK sp55F;
    M2C_UNK sp560;
    M2C_UNK sp570;
    M2C_UNK sp57C;
    M2C_UNK sp580;
    M2C_UNK sp584;
    M2C_UNK sp590;
    M2C_UNK sp610;
    M2C_UNK sp614;
    M2C_UNK sp620;
    M2C_UNK sp660;
    M2C_UNK sp670;
    M2C_UNK sp750;
    M2C_UNK sp754;
    M2C_UNK sp810;
    M2C_UNK sp814;
    M2C_UNK sp870;
    M2C_UNK sp9F0;
    M2C_UNK sp9F4;
    M2C_UNK spA40;
    s32 spA44;
    s32* spA48;
    M2C_UNK* temp_s0_2;
    s32 var_v0;
    s32 var_v0_2;
    u8 temp_s0;

    temp_s0 = D_004E72A0_nitDme;
    memset_nitDme(&sp1, 0, 0xFF);
    sp100 = temp_s0;
    memset_nitDme(&sp101, 0, 0xFF);
    func_00268ED0_nitDme(&sp200);
    sp208 = 0x272F;
    sp204 = 0x40;
    func_00268F20_nitDme(&sp200, &sp220);
    func_00269318_nitDme(0x2000, 0x2000);
    var_v0 = -1;
    if (func_00266F50_nitDme(sp) == 0) {
        var_v0 = -1;
        if (func_00267080_nitDme(&sp100) == 0) {
            temp_s0_2 = "-----------------------------------------------------------------\n";
            printf_nitDme(temp_s0_2);
            printf_nitDme("NETWORK: Initialized Distributed Memory Engine\n");
            printf_nitDme("         Build Version  %s\n", sp);
            printf_nitDme("         Client Version %s\n", &sp100);
            printf_nitDme(temp_s0_2);
            var_v0_2 = 0x12C;
            if (D_00319924_nitDme == 0) {
                var_v0_2 = 0xC8;
            }
            sp2C0 = var_v0_2;
            sp2C8 = (((((0xFEE6 << 0x11) | 0xCCCC) << 0x10) | 0xCCCC) << 0xD) | 0x199A;
            sp248 = 0;
            sp240 = 0x85;
            sp268 = 0;
            sp250 = 0x10;
            sp288 = 0;
            sp260 = 0x43;
            sp2A8 = 0;
            sp280 = 0x7D0;
            sp2A0 = 0x1388;
            sp2B0 = 0x40;
            sp2D0 = 0x10;
            sp270 = 0x40;
            sp290 = 0x40;
            sp2A4 = 1;
            sp2C4 = 1;
            sp244 = 1;
            sp264 = 1;
            sp284 = 1;
            dmeObjLayoutBegin_nitDme(0x85, 0, 0x43, 0x7D0);
            spA48 = &sp2C0;
            dmeObjLayoutAddField_nitDme(&spA40, 4, 1, 1);
            dmeObjRegisterType_nitDme(&D_004F9D18_nitDme, "NetVehicle", 0x38);
            dmeObjSetCallbacks_nitDme(D_004F9D18_nitDme, &netObjCreateCB_nitDme, &netObjUpdateVehicleCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 4, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp31B, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp31A, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp319, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp318, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp316, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp314, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp312, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp310, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp30E, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp30C, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp300, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp2F4, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp2E8, 4, 6);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp2E4, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp2DC, 1, 1);
            dmeObjRegisterType_nitDme(&D_004F9D24_nitDme, "NetWeapon", 0x4C);
            dmeObjSetCallbacks_nitDme(D_004F9D24_nitDme, &netWeaponCreateCB_nitDme, &netWeaponUpdateCB_nitDme, &netWeaponDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 4);
            dmeObjLayoutAddField_nitDme(&D_004F9CD0_nitDme, &sp370 - &sp36C, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&D_004F9CD4_nitDme, &sp370 - &sp360, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&spA40, &sp370 - &sp354, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp370 - &sp350, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp370 - &sp34C, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp370 - &sp348, 4, 4);
            dmeObjRegisterType_nitDme(&D_004F9CA0_nitDme, "NetFodder", 0x2C);
            dmeObjSetCallbacks_nitDme(D_004F9CA0_nitDme, &netObjCreateCB_nitDme, &netFodderUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp39C, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp398, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp394, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp390, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp370, 4, 6);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp350, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp34C, 4, 4);
            dmeObjRegisterType_nitDme(&D_004F9CA4_nitDme, "NetStats", 0x58);
            dmeObjSetCallbacks_nitDme(D_004F9CA4_nitDme, &netObjCreateCB_nitDme, &netStatsUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 6);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp3E0, 4, 6);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp3C0, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp3A0, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp380, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp378, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp370, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp368, 4, 4);
            dmeObjRegisterType_nitDme(&D_004F9CA8_nitDme, "NetPersistantStats", 0xA0);
            dmeObjSetCallbacks_nitDme(D_004F9CA8_nitDme, &netObjCreateCB_nitDme, &netStatsUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp49C, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp49B, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp49A, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp498, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp494, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp490, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp48C, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp488, 2, 3);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp485, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp480, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp47C, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp47B, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp478, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp474, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp470, 2, 3);
            dmeObjLayoutAddField_nitDme(&D_004F9CB8_nitDme, &sp4A0 - &sp46E, 1, 0);
            dmeObjLayoutAddField_nitDme(&D_004F9CBC_nitDme, &sp4A0 - &sp464, 1, 1);
            dmeObjLayoutAddField_nitDme(&D_004F9CC0_nitDme, &sp4A0 - &sp414, 1, 1);
            dmeObjLayoutAddField_nitDme(&D_004F9CCC_nitDme, &sp4A0 - &sp3E4, 1, 1);
            dmeObjLayoutAddField_nitDme(&D_004F9CC8_nitDme, &sp4A0 - &sp486, 1, 0);
            dmeObjLayoutAddField_nitDme(&D_004F9CC4_nitDme, &sp4A0 - &sp3DC, 1, 0);
            dmeObjRegisterType_nitDme(&D_004F9CAC_nitDme, "NetGameData", 0xC8);
            dmeObjSetCallbacks_nitDme(D_004F9CAC_nitDme, &netObjCreateCB_nitDme, &netGameDataUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp570 - &sp560, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp570 - &sp55F, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp570 - &sp55E, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp570 - &sp55C, 2, 2);
            dmeObjRegisterType_nitDme(&D_004F9CB0_nitDme, "NetVehiclePadFlagsObj", 0x18);
            dmeObjSetCallbacks_nitDme(D_004F9CB0_nitDme, &netObjCreateCB_nitDme, &netPadFlagsUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            func_001192E8_nitDme(&sp590);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp590 - &sp584, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp590 - &sp580, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp590 - &sp57C, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp590 - &sp570, 4, 4);
            dmeObjRegisterType_nitDme(&D_004F9CB4_nitDme, "NetArtifactObj\0BASCUS-97196\0 !\"#$%&'()*+,-.0123456789:;<=>?ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_abcdefghijklmnopqrstuvwxyz{}\0\00123456789\0\0 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\0 .0123456789", 0x7C);
            dmeObjSetCallbacks_nitDme(D_004F9CB4_nitDme, &netObjCreateCB_nitDme, &netObjUpdateVehicleCB_nitDme, &netObjDestroyCB_nitDme);
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp610, &sp610, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp610, &sp614, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp610, &sp620, 0x40, 1);
            dmeMsgRegister_nitDme(&spA44, &netMsgGameEventHandler_nitDme);
            D_004F9D84_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp660, &sp660, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp660, &sp670, 0xE0, 1);
            dmeMsgRegister_nitDme(&spA44, &netMsgSessionHandler_nitDme);
            D_004F9D88_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp750, &sp750, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp750, &sp754, 0xBC, 1);
            dmeMsgRegister_nitDme(&spA44, &netMsgWorldEventHandler_nitDme);
            D_004F9D90_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp810, &sp810, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp810, &sp814, 0x5C, 1);
            dmeMsgRegister_nitDme(&spA44, &netMsgPlayerInfoHandler_nitDme);
            D_004F9D94_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp870, &sp870, 0x30, 8);
            dmeMsgRegister_nitDme(&spA44, &netMsgRosterHandler_nitDme);
            D_004F9D98_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp9F0, &sp9F0, 4, 4);
            dmeMsgLayoutAddField_nitDme(&sp9F0, &sp9F4, 0x44, 0x44);
            dmeMsgRegister_nitDme(&spA44, &netMsgChatHandler_nitDme);
            D_004F9D80_nitDme = spA44;
            func_00266478_nitDme(&func_0016C590_nitDme);
            var_v0 = 1;
        }
    }
    return var_v0;
}
//@@ netInitDme m2c1
#include "m2c_macros.h"
M2C_UNK dmeMsgLayoutAddField_nitDme() __asm__("dmeMsgLayoutAddField");
M2C_UNK dmeMsgLayoutBegin_nitDme() __asm__("dmeMsgLayoutBegin");
M2C_UNK dmeMsgRegister_nitDme() __asm__("dmeMsgRegister");
M2C_UNK dmeObjLayoutAddField_nitDme() __asm__("dmeObjLayoutAddField");
M2C_UNK dmeObjLayoutBegin_nitDme() __asm__("dmeObjLayoutBegin");
M2C_UNK dmeObjRegisterType_nitDme() __asm__("dmeObjRegisterType");
M2C_UNK dmeObjSetCallbacks_nitDme() __asm__("dmeObjSetCallbacks");
M2C_UNK func_001192E8_nitDme() __asm__("func_001192E8");
M2C_UNK func_00266478_nitDme() __asm__("func_00266478");
s32 func_00266F50_nitDme() __asm__("func_00266F50");
s32 func_00267080_nitDme() __asm__("func_00267080");
M2C_UNK func_00268ED0_nitDme() __asm__("func_00268ED0");
M2C_UNK func_00268F20_nitDme() __asm__("func_00268F20");
M2C_UNK func_00269318_nitDme() __asm__("func_00269318");
M2C_UNK memset_nitDme() __asm__("memset");
M2C_UNK printf_nitDme() __asm__("printf");
extern s32 D_00319924_nitDme __asm__("D_00319924");
extern u8 D_004E72A0_nitDme __asm__("D_004E72A0");
extern s32 D_004F9CA0_nitDme __asm__("D_004F9CA0");
extern s32 D_004F9CA4_nitDme __asm__("D_004F9CA4");
extern s32 D_004F9CA8_nitDme __asm__("D_004F9CA8");
extern s32 D_004F9CAC_nitDme __asm__("D_004F9CAC");
extern s32 D_004F9CB0_nitDme __asm__("D_004F9CB0");
extern s32 D_004F9CB4_nitDme __asm__("D_004F9CB4");
extern M2C_UNK D_004F9CB8_nitDme __asm__("D_004F9CB8");
extern M2C_UNK D_004F9CBC_nitDme __asm__("D_004F9CBC");
extern M2C_UNK D_004F9CC0_nitDme __asm__("D_004F9CC0");
extern M2C_UNK D_004F9CC4_nitDme __asm__("D_004F9CC4");
extern M2C_UNK D_004F9CC8_nitDme __asm__("D_004F9CC8");
extern M2C_UNK D_004F9CCC_nitDme __asm__("D_004F9CCC");
extern M2C_UNK D_004F9CD0_nitDme __asm__("D_004F9CD0");
extern M2C_UNK D_004F9CD4_nitDme __asm__("D_004F9CD4");
extern s32 D_004F9D18_nitDme __asm__("D_004F9D18");
extern s32 D_004F9D24_nitDme __asm__("D_004F9D24");
extern s32 D_004F9D80_nitDme __asm__("D_004F9D80");
extern s32 D_004F9D84_nitDme __asm__("D_004F9D84");
extern s32 D_004F9D88_nitDme __asm__("D_004F9D88");
extern s32 D_004F9D90_nitDme __asm__("D_004F9D90");
extern s32 D_004F9D94_nitDme __asm__("D_004F9D94");
extern s32 D_004F9D98_nitDme __asm__("D_004F9D98");
extern M2C_UNK func_0016C590_nitDme __asm__("func_0016C590");
extern M2C_UNK netFodderUpdateCB_nitDme __asm__("netFodderUpdateCB");
extern M2C_UNK netGameDataUpdateCB_nitDme __asm__("netGameDataUpdateCB");
extern M2C_UNK netMsgChatHandler_nitDme __asm__("netMsgChatHandler");
extern M2C_UNK netMsgGameEventHandler_nitDme __asm__("netMsgGameEventHandler");
extern M2C_UNK netMsgPlayerInfoHandler_nitDme __asm__("netMsgPlayerInfoHandler");
extern M2C_UNK netMsgRosterHandler_nitDme __asm__("netMsgRosterHandler");
extern M2C_UNK netMsgSessionHandler_nitDme __asm__("netMsgSessionHandler");
extern M2C_UNK netMsgWorldEventHandler_nitDme __asm__("netMsgWorldEventHandler");
extern M2C_UNK netObjCreateCB_nitDme __asm__("netObjCreateCB");
extern M2C_UNK netObjDestroyCB_nitDme __asm__("netObjDestroyCB");
extern M2C_UNK netObjUpdateVehicleCB_nitDme __asm__("netObjUpdateVehicleCB");
extern M2C_UNK netPadFlagsUpdateCB_nitDme __asm__("netPadFlagsUpdateCB");
extern M2C_UNK netStatsUpdateCB_nitDme __asm__("netStatsUpdateCB");
extern M2C_UNK netWeaponCreateCB_nitDme __asm__("netWeaponCreateCB");
extern M2C_UNK netWeaponDestroyCB_nitDme __asm__("netWeaponDestroyCB");
extern M2C_UNK netWeaponUpdateCB_nitDme __asm__("netWeaponUpdateCB");

s32 netInitDme(void) {
    u8 sp[0xA40];
    M2C_UNK sp1;
    u8 sp100;
    M2C_UNK sp101;
    M2C_UNK sp200;
    s32 sp204;
    s32 sp208;
    M2C_UNK sp220;
    s32 sp240;
    s32 sp244;
    s64 sp248;
    s8 sp250;
    s32 sp260;
    s32 sp264;
    s64 sp268;
    s8 sp270;
    s32 sp280;
    s32 sp284;
    s64 sp288;
    s8 sp290;
    s32 sp2A0;
    s32 sp2A4;
    s64 sp2A8;
    s8 sp2B0;
    s32 sp2C0;
    s32 sp2C4;
    s64 sp2C8;
    s8 sp2D0;
    M2C_UNK sp2DC;
    M2C_UNK sp2E4;
    M2C_UNK sp2E8;
    M2C_UNK sp2F4;
    M2C_UNK sp300;
    M2C_UNK sp30C;
    M2C_UNK sp30E;
    M2C_UNK sp310;
    M2C_UNK sp312;
    M2C_UNK sp314;
    M2C_UNK sp316;
    M2C_UNK sp318;
    M2C_UNK sp319;
    M2C_UNK sp31A;
    M2C_UNK sp31B;
    M2C_UNK sp320;
    M2C_UNK sp348;
    M2C_UNK sp34C;
    M2C_UNK sp350;
    M2C_UNK sp354;
    M2C_UNK sp360;
    M2C_UNK sp368;
    M2C_UNK sp36C;
    M2C_UNK sp370;
    M2C_UNK sp378;
    M2C_UNK sp380;
    M2C_UNK sp390;
    M2C_UNK sp394;
    M2C_UNK sp398;
    M2C_UNK sp39C;
    M2C_UNK sp3A0;
    M2C_UNK sp3C0;
    M2C_UNK sp3DC;
    M2C_UNK sp3E0;
    M2C_UNK sp3E4;
    M2C_UNK sp400;
    M2C_UNK sp414;
    M2C_UNK sp464;
    M2C_UNK sp46E;
    M2C_UNK sp470;
    M2C_UNK sp474;
    M2C_UNK sp478;
    M2C_UNK sp47B;
    M2C_UNK sp47C;
    M2C_UNK sp480;
    M2C_UNK sp485;
    M2C_UNK sp486;
    M2C_UNK sp488;
    M2C_UNK sp48C;
    M2C_UNK sp490;
    M2C_UNK sp494;
    M2C_UNK sp498;
    M2C_UNK sp49A;
    M2C_UNK sp49B;
    M2C_UNK sp49C;
    M2C_UNK sp4A0;
    M2C_UNK sp55C;
    M2C_UNK sp55E;
    M2C_UNK sp55F;
    M2C_UNK sp560;
    M2C_UNK sp570;
    M2C_UNK sp57C;
    M2C_UNK sp580;
    M2C_UNK sp584;
    M2C_UNK sp590;
    M2C_UNK sp610;
    M2C_UNK sp614;
    M2C_UNK sp620;
    M2C_UNK sp660;
    M2C_UNK sp670;
    M2C_UNK sp750;
    M2C_UNK sp754;
    M2C_UNK sp810;
    M2C_UNK sp814;
    M2C_UNK sp870;
    M2C_UNK sp9F0;
    M2C_UNK sp9F4;
    M2C_UNK spA40;
    s32 spA44;
    s32* spA48;
    M2C_UNK* temp_s0_2;
    s32 var_v0;
    s32 var_v0_2;
    u8 temp_s0;

    temp_s0 = D_004E72A0_nitDme;
    memset_nitDme(&sp1, 0, 0xFF);
    sp100 = temp_s0;
    memset_nitDme(&sp101, 0, 0xFF);
    func_00268ED0_nitDme(&sp200);
    sp208 = 0x272F;
    sp204 = 0x40;
    func_00268F20_nitDme(&sp200, &sp220);
    func_00269318_nitDme(0x2000, 0x2000);
    var_v0 = -1;
    if (func_00266F50_nitDme(sp) == 0) {
        var_v0 = -1;
        if (func_00267080_nitDme(&sp100) == 0) {
            temp_s0_2 = "-----------------------------------------------------------------\n";
            printf_nitDme(temp_s0_2);
            printf_nitDme("NETWORK: Initialized Distributed Memory Engine\n");
            printf_nitDme("         Build Version  %s\n", sp);
            printf_nitDme("         Client Version %s\n", &sp100);
            printf_nitDme(temp_s0_2);
            var_v0_2 = 0x12C;
            if (D_00319924_nitDme == 0) {
                var_v0_2 = 0xC8;
            }
            sp2C0 = var_v0_2;
            sp2C8 = (((((0xFEE6 << 0x11) | 0xCCCC) << 0x10) | 0xCCCC) << 0xD) | 0x199A;
            sp248 = 0;
            sp240 = 0x85;
            sp268 = 0;
            sp250 = 0x10;
            sp288 = 0;
            sp260 = 0x43;
            sp2A8 = 0;
            sp280 = 0x7D0;
            sp2A0 = 0x1388;
            sp2B0 = 0x40;
            sp2D0 = 0x10;
            sp270 = 0x40;
            sp290 = 0x40;
            sp2A4 = 1;
            sp2C4 = 1;
            sp244 = 1;
            sp264 = 1;
            sp284 = 1;
            dmeObjLayoutBegin_nitDme(0x85, 0, 0x43, 0x7D0);
            spA48 = &sp2C0;
            dmeObjLayoutAddField_nitDme(&spA40, 4, 1, 1);
            dmeObjRegisterType_nitDme(&D_004F9D18_nitDme, "NetVehicle", 0x38);
            dmeObjSetCallbacks_nitDme(D_004F9D18_nitDme, &netObjCreateCB_nitDme, &netObjUpdateVehicleCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 4, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp31B, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp31A, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp319, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp318, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp316, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp314, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp312, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp310, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp30E, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp30C, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp300, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp2F4, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp2E8, 4, 6);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp2E4, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp2DC, 1, 1);
            dmeObjRegisterType_nitDme(&D_004F9D24_nitDme, "NetWeapon", 0x4C);
            dmeObjSetCallbacks_nitDme(D_004F9D24_nitDme, &netWeaponCreateCB_nitDme, &netWeaponUpdateCB_nitDme, &netWeaponDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 4);
            dmeObjLayoutAddField_nitDme(&D_004F9CD0_nitDme, &sp370 - &sp36C, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&D_004F9CD4_nitDme, &sp370 - &sp360, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&spA40, &sp370 - &sp354, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp370 - &sp350, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp370 - &sp34C, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp370 - &sp348, 4, 4);
            dmeObjRegisterType_nitDme(&D_004F9CA0_nitDme, "NetFodder", 0x2C);
            dmeObjSetCallbacks_nitDme(D_004F9CA0_nitDme, &netObjCreateCB_nitDme, &netFodderUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp39C, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp398, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp394, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp390, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp370, 4, 6);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp350, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp34C, 4, 4);
            dmeObjRegisterType_nitDme(&D_004F9CA4_nitDme, "NetStats", 0x58);
            dmeObjSetCallbacks_nitDme(D_004F9CA4_nitDme, &netObjCreateCB_nitDme, &netStatsUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 6);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp3E0, 4, 6);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp3C0, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp3A0, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp380, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp378, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp370, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp368, 4, 4);
            dmeObjRegisterType_nitDme(&D_004F9CA8_nitDme, "NetPersistantStats", 0xA0);
            dmeObjSetCallbacks_nitDme(D_004F9CA8_nitDme, &netObjCreateCB_nitDme, &netStatsUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp49C, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp49B, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp49A, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp498, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp494, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp490, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp48C, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp488, 2, 3);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp485, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp480, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp47C, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp47B, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp478, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp474, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp470, 2, 3);
            dmeObjLayoutAddField_nitDme(&D_004F9CB8_nitDme, &sp4A0 - &sp46E, 1, 0);
            dmeObjLayoutAddField_nitDme(&D_004F9CBC_nitDme, &sp4A0 - &sp464, 1, 1);
            dmeObjLayoutAddField_nitDme(&D_004F9CC0_nitDme, &sp4A0 - &sp414, 1, 1);
            dmeObjLayoutAddField_nitDme(&D_004F9CCC_nitDme, &sp4A0 - &sp3E4, 1, 1);
            dmeObjLayoutAddField_nitDme(&D_004F9CC8_nitDme, &sp4A0 - &sp486, 1, 0);
            dmeObjLayoutAddField_nitDme(&D_004F9CC4_nitDme, &sp4A0 - &sp3DC, 1, 0);
            dmeObjRegisterType_nitDme(&D_004F9CAC_nitDme, "NetGameData", 0xC8);
            dmeObjSetCallbacks_nitDme(D_004F9CAC_nitDme, &netObjCreateCB_nitDme, &netGameDataUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp570 - &sp560, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp570 - &sp55F, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp570 - &sp55E, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp570 - &sp55C, 2, 2);
            dmeObjRegisterType_nitDme(&D_004F9CB0_nitDme, "NetVehiclePadFlagsObj", 0x18);
            dmeObjSetCallbacks_nitDme(D_004F9CB0_nitDme, &netObjCreateCB_nitDme, &netPadFlagsUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            func_001192E8_nitDme(&sp590);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp590 - &sp584, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp590 - &sp580, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp590 - &sp57C, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp590 - &sp570, 4, 4);
            dmeObjRegisterType_nitDme(&D_004F9CB4_nitDme, "NetArtifactObj\0BASCUS-97196\0 !\"#$%&'()*+,-.0123456789:;<=>?ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_abcdefghijklmnopqrstuvwxyz{}\0\00123456789\0\0 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\0 .0123456789", 0x7C);
            dmeObjSetCallbacks_nitDme(D_004F9CB4_nitDme, &netObjCreateCB_nitDme, &netObjUpdateVehicleCB_nitDme, &netObjDestroyCB_nitDme);
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp610, &sp610, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp610, &sp614, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp610, &sp620, 0x40, 1);
            dmeMsgRegister_nitDme(&spA44, &netMsgGameEventHandler_nitDme);
            D_004F9D84_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp660, &sp660, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp660, &sp670, 0xE0, 1);
            dmeMsgRegister_nitDme(&spA44, &netMsgSessionHandler_nitDme);
            D_004F9D88_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp750, &sp750, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp750, &sp754, 0xBC, 1);
            dmeMsgRegister_nitDme(&spA44, &netMsgWorldEventHandler_nitDme);
            D_004F9D90_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp810, &sp810, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp810, &sp814, 0x5C, 1);
            dmeMsgRegister_nitDme(&spA44, &netMsgPlayerInfoHandler_nitDme);
            D_004F9D94_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp870, &sp870, 0x30, 8);
            dmeMsgRegister_nitDme(&spA44, &netMsgRosterHandler_nitDme);
            D_004F9D98_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp9F0, &sp9F0, 4, 4);
            dmeMsgLayoutAddField_nitDme(&sp9F0, &sp9F4, 0x44, 0x44);
            dmeMsgRegister_nitDme(&spA44, &netMsgChatHandler_nitDme);
            D_004F9D80_nitDme = spA44;
            func_00266478_nitDme(&func_0016C590_nitDme);
            var_v0 = 1;
        }
    }
    return var_v0;
}
//@@ netInitDme m2c2
#include "m2c_macros.h"
M2C_UNK dmeMsgLayoutAddField_nitDme() __asm__("dmeMsgLayoutAddField");
M2C_UNK dmeMsgLayoutBegin_nitDme() __asm__("dmeMsgLayoutBegin");
M2C_UNK dmeMsgRegister_nitDme() __asm__("dmeMsgRegister");
M2C_UNK dmeObjLayoutAddField_nitDme() __asm__("dmeObjLayoutAddField");
M2C_UNK dmeObjLayoutBegin_nitDme() __asm__("dmeObjLayoutBegin");
M2C_UNK dmeObjRegisterType_nitDme() __asm__("dmeObjRegisterType");
M2C_UNK dmeObjSetCallbacks_nitDme() __asm__("dmeObjSetCallbacks");
M2C_UNK func_001192E8_nitDme() __asm__("func_001192E8");
M2C_UNK func_00266478_nitDme() __asm__("func_00266478");
s32 func_00266F50_nitDme() __asm__("func_00266F50");
s32 func_00267080_nitDme() __asm__("func_00267080");
M2C_UNK func_00268ED0_nitDme() __asm__("func_00268ED0");
M2C_UNK func_00268F20_nitDme() __asm__("func_00268F20");
M2C_UNK func_00269318_nitDme() __asm__("func_00269318");
M2C_UNK memset_nitDme() __asm__("memset");
M2C_UNK printf_nitDme() __asm__("printf");
extern s32 D_00319924_nitDme __asm__("D_00319924");
extern u8 D_004E72A0_nitDme __asm__("D_004E72A0");
extern s32 D_004F9CA0_nitDme __asm__("D_004F9CA0");
extern s32 D_004F9CA4_nitDme __asm__("D_004F9CA4");
extern s32 D_004F9CA8_nitDme __asm__("D_004F9CA8");
extern s32 D_004F9CAC_nitDme __asm__("D_004F9CAC");
extern s32 D_004F9CB0_nitDme __asm__("D_004F9CB0");
extern s32 D_004F9CB4_nitDme __asm__("D_004F9CB4");
extern M2C_UNK D_004F9CB8_nitDme __asm__("D_004F9CB8");
extern M2C_UNK D_004F9CBC_nitDme __asm__("D_004F9CBC");
extern M2C_UNK D_004F9CC0_nitDme __asm__("D_004F9CC0");
extern M2C_UNK D_004F9CC4_nitDme __asm__("D_004F9CC4");
extern M2C_UNK D_004F9CC8_nitDme __asm__("D_004F9CC8");
extern M2C_UNK D_004F9CCC_nitDme __asm__("D_004F9CCC");
extern M2C_UNK D_004F9CD0_nitDme __asm__("D_004F9CD0");
extern M2C_UNK D_004F9CD4_nitDme __asm__("D_004F9CD4");
extern s32 D_004F9D18_nitDme __asm__("D_004F9D18");
extern s32 D_004F9D24_nitDme __asm__("D_004F9D24");
extern s32 D_004F9D80_nitDme __asm__("D_004F9D80");
extern s32 D_004F9D84_nitDme __asm__("D_004F9D84");
extern s32 D_004F9D88_nitDme __asm__("D_004F9D88");
extern s32 D_004F9D90_nitDme __asm__("D_004F9D90");
extern s32 D_004F9D94_nitDme __asm__("D_004F9D94");
extern s32 D_004F9D98_nitDme __asm__("D_004F9D98");
extern M2C_UNK func_0016C590_nitDme __asm__("func_0016C590");
extern M2C_UNK netFodderUpdateCB_nitDme __asm__("netFodderUpdateCB");
extern M2C_UNK netGameDataUpdateCB_nitDme __asm__("netGameDataUpdateCB");
extern M2C_UNK netMsgChatHandler_nitDme __asm__("netMsgChatHandler");
extern M2C_UNK netMsgGameEventHandler_nitDme __asm__("netMsgGameEventHandler");
extern M2C_UNK netMsgPlayerInfoHandler_nitDme __asm__("netMsgPlayerInfoHandler");
extern M2C_UNK netMsgRosterHandler_nitDme __asm__("netMsgRosterHandler");
extern M2C_UNK netMsgSessionHandler_nitDme __asm__("netMsgSessionHandler");
extern M2C_UNK netMsgWorldEventHandler_nitDme __asm__("netMsgWorldEventHandler");
extern M2C_UNK netObjCreateCB_nitDme __asm__("netObjCreateCB");
extern M2C_UNK netObjDestroyCB_nitDme __asm__("netObjDestroyCB");
extern M2C_UNK netObjUpdateVehicleCB_nitDme __asm__("netObjUpdateVehicleCB");
extern M2C_UNK netPadFlagsUpdateCB_nitDme __asm__("netPadFlagsUpdateCB");
extern M2C_UNK netStatsUpdateCB_nitDme __asm__("netStatsUpdateCB");
extern M2C_UNK netWeaponCreateCB_nitDme __asm__("netWeaponCreateCB");
extern M2C_UNK netWeaponDestroyCB_nitDme __asm__("netWeaponDestroyCB");
extern M2C_UNK netWeaponUpdateCB_nitDme __asm__("netWeaponUpdateCB");

s32 netInitDme(void) {
    u8 sp[0xA30];
    M2C_UNK sp1;
    u8 sp100;
    M2C_UNK sp101;
    M2C_UNK sp200;
    s32 sp204;
    s32 sp208;
    M2C_UNK sp220;
    s32 sp240;
    s32 sp244;
    s64 sp248;
    s8 sp250;
    s32 sp260;
    s32 sp264;
    s64 sp268;
    s8 sp270;
    s32 sp280;
    s32 sp284;
    s64 sp288;
    s8 sp290;
    s32 sp2A0;
    s32 sp2A4;
    s64 sp2A8;
    s8 sp2B0;
    s32 sp2C0;
    s32 sp2C4;
    s64 sp2C8;
    s8 sp2D0;
    M2C_UNK sp2DC;
    M2C_UNK sp2E4;
    M2C_UNK sp2E8;
    M2C_UNK sp2F4;
    M2C_UNK sp300;
    M2C_UNK sp30C;
    M2C_UNK sp30E;
    M2C_UNK sp310;
    M2C_UNK sp312;
    M2C_UNK sp314;
    M2C_UNK sp316;
    M2C_UNK sp318;
    M2C_UNK sp319;
    M2C_UNK sp31A;
    M2C_UNK sp31B;
    M2C_UNK sp320;
    M2C_UNK sp348;
    M2C_UNK sp34C;
    M2C_UNK sp350;
    M2C_UNK sp354;
    M2C_UNK sp360;
    M2C_UNK sp368;
    M2C_UNK sp36C;
    M2C_UNK sp370;
    M2C_UNK sp378;
    M2C_UNK sp380;
    M2C_UNK sp390;
    M2C_UNK sp394;
    M2C_UNK sp398;
    M2C_UNK sp39C;
    M2C_UNK sp3A0;
    M2C_UNK sp3C0;
    M2C_UNK sp3DC;
    M2C_UNK sp3E0;
    M2C_UNK sp3E4;
    M2C_UNK sp400;
    M2C_UNK sp414;
    M2C_UNK sp464;
    M2C_UNK sp46E;
    M2C_UNK sp470;
    M2C_UNK sp474;
    M2C_UNK sp478;
    M2C_UNK sp47B;
    M2C_UNK sp47C;
    M2C_UNK sp480;
    M2C_UNK sp485;
    M2C_UNK sp486;
    M2C_UNK sp488;
    M2C_UNK sp48C;
    M2C_UNK sp490;
    M2C_UNK sp494;
    M2C_UNK sp498;
    M2C_UNK sp49A;
    M2C_UNK sp49B;
    M2C_UNK sp49C;
    M2C_UNK sp4A0;
    M2C_UNK sp55C;
    M2C_UNK sp55E;
    M2C_UNK sp55F;
    M2C_UNK sp560;
    M2C_UNK sp570;
    M2C_UNK sp57C;
    M2C_UNK sp580;
    M2C_UNK sp584;
    M2C_UNK sp590;
    M2C_UNK sp610;
    M2C_UNK sp614;
    M2C_UNK sp620;
    M2C_UNK sp660;
    M2C_UNK sp670;
    M2C_UNK sp750;
    M2C_UNK sp754;
    M2C_UNK sp810;
    M2C_UNK sp814;
    M2C_UNK sp870;
    M2C_UNK sp9F0;
    M2C_UNK sp9F4;
    M2C_UNK spA40;
    s32 spA44;
    s32* spA48;
    M2C_UNK* temp_s0_2;
    s32 var_v0;
    s32 var_v0_2;
    u8 temp_s0;

    temp_s0 = D_004E72A0_nitDme;
    memset_nitDme(&sp1, 0, 0xFF);
    sp100 = temp_s0;
    memset_nitDme(&sp101, 0, 0xFF);
    func_00268ED0_nitDme(&sp200);
    sp208 = 0x272F;
    sp204 = 0x40;
    func_00268F20_nitDme(&sp200, &sp220);
    func_00269318_nitDme(0x2000, 0x2000);
    var_v0 = -1;
    if (func_00266F50_nitDme(sp) == 0) {
        var_v0 = -1;
        if (func_00267080_nitDme(&sp100) == 0) {
            temp_s0_2 = "-----------------------------------------------------------------\n";
            printf_nitDme(temp_s0_2);
            printf_nitDme("NETWORK: Initialized Distributed Memory Engine\n");
            printf_nitDme("         Build Version  %s\n", sp);
            printf_nitDme("         Client Version %s\n", &sp100);
            printf_nitDme(temp_s0_2);
            var_v0_2 = 0x12C;
            if (D_00319924_nitDme == 0) {
                var_v0_2 = 0xC8;
            }
            sp2C0 = var_v0_2;
            sp2C8 = (((((0xFEE6 << 0x11) | 0xCCCC) << 0x10) | 0xCCCC) << 0xD) | 0x199A;
            sp248 = 0;
            sp240 = 0x85;
            sp268 = 0;
            sp250 = 0x10;
            sp288 = 0;
            sp260 = 0x43;
            sp2A8 = 0;
            sp280 = 0x7D0;
            sp2A0 = 0x1388;
            sp2B0 = 0x40;
            sp2D0 = 0x10;
            sp270 = 0x40;
            sp290 = 0x40;
            sp2A4 = 1;
            sp2C4 = 1;
            sp244 = 1;
            sp264 = 1;
            sp284 = 1;
            dmeObjLayoutBegin_nitDme(0x85, 0, 0x43, 0x7D0);
            spA48 = &sp2C0;
            dmeObjLayoutAddField_nitDme(&spA40, 4, 1, 1);
            dmeObjRegisterType_nitDme(&D_004F9D18_nitDme, "NetVehicle", 0x38);
            dmeObjSetCallbacks_nitDme(D_004F9D18_nitDme, &netObjCreateCB_nitDme, &netObjUpdateVehicleCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 4, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp31B, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp31A, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp319, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp318, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp316, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp314, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp312, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp310, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp30E, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp30C, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp300, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp2F4, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp2E8, 4, 6);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp2E4, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp2DC, 1, 1);
            dmeObjRegisterType_nitDme(&D_004F9D24_nitDme, "NetWeapon", 0x4C);
            dmeObjSetCallbacks_nitDme(D_004F9D24_nitDme, &netWeaponCreateCB_nitDme, &netWeaponUpdateCB_nitDme, &netWeaponDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 4);
            dmeObjLayoutAddField_nitDme(&D_004F9CD0_nitDme, &sp370 - &sp36C, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&D_004F9CD4_nitDme, &sp370 - &sp360, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&spA40, &sp370 - &sp354, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp370 - &sp350, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp370 - &sp34C, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp370 - &sp348, 4, 4);
            dmeObjRegisterType_nitDme(&D_004F9CA0_nitDme, "NetFodder", 0x2C);
            dmeObjSetCallbacks_nitDme(D_004F9CA0_nitDme, &netObjCreateCB_nitDme, &netFodderUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp39C, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp398, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp394, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp390, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp370, 4, 6);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp350, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp34C, 4, 4);
            dmeObjRegisterType_nitDme(&D_004F9CA4_nitDme, "NetStats", 0x58);
            dmeObjSetCallbacks_nitDme(D_004F9CA4_nitDme, &netObjCreateCB_nitDme, &netStatsUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 6);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp3E0, 4, 6);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp3C0, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp3A0, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp380, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp378, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp370, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp368, 4, 4);
            dmeObjRegisterType_nitDme(&D_004F9CA8_nitDme, "NetPersistantStats", 0xA0);
            dmeObjSetCallbacks_nitDme(D_004F9CA8_nitDme, &netObjCreateCB_nitDme, &netStatsUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp49C, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp49B, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp49A, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp498, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp494, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp490, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp48C, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp488, 2, 3);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp485, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp480, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp47C, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp47B, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp478, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp474, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp470, 2, 3);
            dmeObjLayoutAddField_nitDme(&D_004F9CB8_nitDme, &sp4A0 - &sp46E, 1, 0);
            dmeObjLayoutAddField_nitDme(&D_004F9CBC_nitDme, &sp4A0 - &sp464, 1, 1);
            dmeObjLayoutAddField_nitDme(&D_004F9CC0_nitDme, &sp4A0 - &sp414, 1, 1);
            dmeObjLayoutAddField_nitDme(&D_004F9CCC_nitDme, &sp4A0 - &sp3E4, 1, 1);
            dmeObjLayoutAddField_nitDme(&D_004F9CC8_nitDme, &sp4A0 - &sp486, 1, 0);
            dmeObjLayoutAddField_nitDme(&D_004F9CC4_nitDme, &sp4A0 - &sp3DC, 1, 0);
            dmeObjRegisterType_nitDme(&D_004F9CAC_nitDme, "NetGameData", 0xC8);
            dmeObjSetCallbacks_nitDme(D_004F9CAC_nitDme, &netObjCreateCB_nitDme, &netGameDataUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp570 - &sp560, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp570 - &sp55F, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp570 - &sp55E, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp570 - &sp55C, 2, 2);
            dmeObjRegisterType_nitDme(&D_004F9CB0_nitDme, "NetVehiclePadFlagsObj", 0x18);
            dmeObjSetCallbacks_nitDme(D_004F9CB0_nitDme, &netObjCreateCB_nitDme, &netPadFlagsUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            func_001192E8_nitDme(&sp590);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp590 - &sp584, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp590 - &sp580, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp590 - &sp57C, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp590 - &sp570, 4, 4);
            dmeObjRegisterType_nitDme(&D_004F9CB4_nitDme, "NetArtifactObj\0BASCUS-97196\0 !\"#$%&'()*+,-.0123456789:;<=>?ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_abcdefghijklmnopqrstuvwxyz{}\0\00123456789\0\0 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\0 .0123456789", 0x7C);
            dmeObjSetCallbacks_nitDme(D_004F9CB4_nitDme, &netObjCreateCB_nitDme, &netObjUpdateVehicleCB_nitDme, &netObjDestroyCB_nitDme);
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp610, &sp610, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp610, &sp614, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp610, &sp620, 0x40, 1);
            dmeMsgRegister_nitDme(&spA44, &netMsgGameEventHandler_nitDme);
            D_004F9D84_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp660, &sp660, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp660, &sp670, 0xE0, 1);
            dmeMsgRegister_nitDme(&spA44, &netMsgSessionHandler_nitDme);
            D_004F9D88_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp750, &sp750, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp750, &sp754, 0xBC, 1);
            dmeMsgRegister_nitDme(&spA44, &netMsgWorldEventHandler_nitDme);
            D_004F9D90_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp810, &sp810, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp810, &sp814, 0x5C, 1);
            dmeMsgRegister_nitDme(&spA44, &netMsgPlayerInfoHandler_nitDme);
            D_004F9D94_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp870, &sp870, 0x30, 8);
            dmeMsgRegister_nitDme(&spA44, &netMsgRosterHandler_nitDme);
            D_004F9D98_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp9F0, &sp9F0, 4, 4);
            dmeMsgLayoutAddField_nitDme(&sp9F0, &sp9F4, 0x44, 0x44);
            dmeMsgRegister_nitDme(&spA44, &netMsgChatHandler_nitDme);
            D_004F9D80_nitDme = spA44;
            func_00266478_nitDme(&func_0016C590_nitDme);
            var_v0 = 1;
        }
    }
    return var_v0;
}
//@@ netInitDme m2c3
#include "m2c_macros.h"
M2C_UNK dmeMsgLayoutAddField_nitDme() __asm__("dmeMsgLayoutAddField");
M2C_UNK dmeMsgLayoutBegin_nitDme() __asm__("dmeMsgLayoutBegin");
M2C_UNK dmeMsgRegister_nitDme() __asm__("dmeMsgRegister");
M2C_UNK dmeObjLayoutAddField_nitDme() __asm__("dmeObjLayoutAddField");
M2C_UNK dmeObjLayoutBegin_nitDme() __asm__("dmeObjLayoutBegin");
M2C_UNK dmeObjRegisterType_nitDme() __asm__("dmeObjRegisterType");
M2C_UNK dmeObjSetCallbacks_nitDme() __asm__("dmeObjSetCallbacks");
M2C_UNK func_001192E8_nitDme() __asm__("func_001192E8");
M2C_UNK func_00266478_nitDme() __asm__("func_00266478");
s32 func_00266F50_nitDme() __asm__("func_00266F50");
s32 func_00267080_nitDme() __asm__("func_00267080");
M2C_UNK func_00268ED0_nitDme() __asm__("func_00268ED0");
M2C_UNK func_00268F20_nitDme() __asm__("func_00268F20");
M2C_UNK func_00269318_nitDme() __asm__("func_00269318");
M2C_UNK memset_nitDme() __asm__("memset");
M2C_UNK printf_nitDme() __asm__("printf");
extern s32 D_00319924_nitDme __asm__("D_00319924");
extern u8 D_004E72A0_nitDme __asm__("D_004E72A0");
extern s32 D_004F9CA0_nitDme __asm__("D_004F9CA0");
extern s32 D_004F9CA4_nitDme __asm__("D_004F9CA4");
extern s32 D_004F9CA8_nitDme __asm__("D_004F9CA8");
extern s32 D_004F9CAC_nitDme __asm__("D_004F9CAC");
extern s32 D_004F9CB0_nitDme __asm__("D_004F9CB0");
extern s32 D_004F9CB4_nitDme __asm__("D_004F9CB4");
extern M2C_UNK D_004F9CB8_nitDme __asm__("D_004F9CB8");
extern M2C_UNK D_004F9CBC_nitDme __asm__("D_004F9CBC");
extern M2C_UNK D_004F9CC0_nitDme __asm__("D_004F9CC0");
extern M2C_UNK D_004F9CC4_nitDme __asm__("D_004F9CC4");
extern M2C_UNK D_004F9CC8_nitDme __asm__("D_004F9CC8");
extern M2C_UNK D_004F9CCC_nitDme __asm__("D_004F9CCC");
extern M2C_UNK D_004F9CD0_nitDme __asm__("D_004F9CD0");
extern M2C_UNK D_004F9CD4_nitDme __asm__("D_004F9CD4");
extern s32 D_004F9D18_nitDme __asm__("D_004F9D18");
extern s32 D_004F9D24_nitDme __asm__("D_004F9D24");
extern s32 D_004F9D80_nitDme __asm__("D_004F9D80");
extern s32 D_004F9D84_nitDme __asm__("D_004F9D84");
extern s32 D_004F9D88_nitDme __asm__("D_004F9D88");
extern s32 D_004F9D90_nitDme __asm__("D_004F9D90");
extern s32 D_004F9D94_nitDme __asm__("D_004F9D94");
extern s32 D_004F9D98_nitDme __asm__("D_004F9D98");
extern M2C_UNK func_0016C590_nitDme __asm__("func_0016C590");
extern M2C_UNK netFodderUpdateCB_nitDme __asm__("netFodderUpdateCB");
extern M2C_UNK netGameDataUpdateCB_nitDme __asm__("netGameDataUpdateCB");
extern M2C_UNK netMsgChatHandler_nitDme __asm__("netMsgChatHandler");
extern M2C_UNK netMsgGameEventHandler_nitDme __asm__("netMsgGameEventHandler");
extern M2C_UNK netMsgPlayerInfoHandler_nitDme __asm__("netMsgPlayerInfoHandler");
extern M2C_UNK netMsgRosterHandler_nitDme __asm__("netMsgRosterHandler");
extern M2C_UNK netMsgSessionHandler_nitDme __asm__("netMsgSessionHandler");
extern M2C_UNK netMsgWorldEventHandler_nitDme __asm__("netMsgWorldEventHandler");
extern M2C_UNK netObjCreateCB_nitDme __asm__("netObjCreateCB");
extern M2C_UNK netObjDestroyCB_nitDme __asm__("netObjDestroyCB");
extern M2C_UNK netObjUpdateVehicleCB_nitDme __asm__("netObjUpdateVehicleCB");
extern M2C_UNK netPadFlagsUpdateCB_nitDme __asm__("netPadFlagsUpdateCB");
extern M2C_UNK netStatsUpdateCB_nitDme __asm__("netStatsUpdateCB");
extern M2C_UNK netWeaponCreateCB_nitDme __asm__("netWeaponCreateCB");
extern M2C_UNK netWeaponDestroyCB_nitDme __asm__("netWeaponDestroyCB");
extern M2C_UNK netWeaponUpdateCB_nitDme __asm__("netWeaponUpdateCB");

s32 netInitDme(void) {
    u8 sp[0xA20];
    M2C_UNK sp1;
    u8 sp100;
    M2C_UNK sp101;
    M2C_UNK sp200;
    s32 sp204;
    s32 sp208;
    M2C_UNK sp220;
    s32 sp240;
    s32 sp244;
    s64 sp248;
    s8 sp250;
    s32 sp260;
    s32 sp264;
    s64 sp268;
    s8 sp270;
    s32 sp280;
    s32 sp284;
    s64 sp288;
    s8 sp290;
    s32 sp2A0;
    s32 sp2A4;
    s64 sp2A8;
    s8 sp2B0;
    s32 sp2C0;
    s32 sp2C4;
    s64 sp2C8;
    s8 sp2D0;
    M2C_UNK sp2DC;
    M2C_UNK sp2E4;
    M2C_UNK sp2E8;
    M2C_UNK sp2F4;
    M2C_UNK sp300;
    M2C_UNK sp30C;
    M2C_UNK sp30E;
    M2C_UNK sp310;
    M2C_UNK sp312;
    M2C_UNK sp314;
    M2C_UNK sp316;
    M2C_UNK sp318;
    M2C_UNK sp319;
    M2C_UNK sp31A;
    M2C_UNK sp31B;
    M2C_UNK sp320;
    M2C_UNK sp348;
    M2C_UNK sp34C;
    M2C_UNK sp350;
    M2C_UNK sp354;
    M2C_UNK sp360;
    M2C_UNK sp368;
    M2C_UNK sp36C;
    M2C_UNK sp370;
    M2C_UNK sp378;
    M2C_UNK sp380;
    M2C_UNK sp390;
    M2C_UNK sp394;
    M2C_UNK sp398;
    M2C_UNK sp39C;
    M2C_UNK sp3A0;
    M2C_UNK sp3C0;
    M2C_UNK sp3DC;
    M2C_UNK sp3E0;
    M2C_UNK sp3E4;
    M2C_UNK sp400;
    M2C_UNK sp414;
    M2C_UNK sp464;
    M2C_UNK sp46E;
    M2C_UNK sp470;
    M2C_UNK sp474;
    M2C_UNK sp478;
    M2C_UNK sp47B;
    M2C_UNK sp47C;
    M2C_UNK sp480;
    M2C_UNK sp485;
    M2C_UNK sp486;
    M2C_UNK sp488;
    M2C_UNK sp48C;
    M2C_UNK sp490;
    M2C_UNK sp494;
    M2C_UNK sp498;
    M2C_UNK sp49A;
    M2C_UNK sp49B;
    M2C_UNK sp49C;
    M2C_UNK sp4A0;
    M2C_UNK sp55C;
    M2C_UNK sp55E;
    M2C_UNK sp55F;
    M2C_UNK sp560;
    M2C_UNK sp570;
    M2C_UNK sp57C;
    M2C_UNK sp580;
    M2C_UNK sp584;
    M2C_UNK sp590;
    M2C_UNK sp610;
    M2C_UNK sp614;
    M2C_UNK sp620;
    M2C_UNK sp660;
    M2C_UNK sp670;
    M2C_UNK sp750;
    M2C_UNK sp754;
    M2C_UNK sp810;
    M2C_UNK sp814;
    M2C_UNK sp870;
    M2C_UNK sp9F0;
    M2C_UNK sp9F4;
    M2C_UNK spA40;
    s32 spA44;
    s32* spA48;
    M2C_UNK* temp_s0_2;
    s32 var_v0;
    s32 var_v0_2;
    u8 temp_s0;

    temp_s0 = D_004E72A0_nitDme;
    memset_nitDme(&sp1, 0, 0xFF);
    sp100 = temp_s0;
    memset_nitDme(&sp101, 0, 0xFF);
    func_00268ED0_nitDme(&sp200);
    sp208 = 0x272F;
    sp204 = 0x40;
    func_00268F20_nitDme(&sp200, &sp220);
    func_00269318_nitDme(0x2000, 0x2000);
    var_v0 = -1;
    if (func_00266F50_nitDme(sp) == 0) {
        var_v0 = -1;
        if (func_00267080_nitDme(&sp100) == 0) {
            temp_s0_2 = "-----------------------------------------------------------------\n";
            printf_nitDme(temp_s0_2);
            printf_nitDme("NETWORK: Initialized Distributed Memory Engine\n");
            printf_nitDme("         Build Version  %s\n", sp);
            printf_nitDme("         Client Version %s\n", &sp100);
            printf_nitDme(temp_s0_2);
            var_v0_2 = 0x12C;
            if (D_00319924_nitDme == 0) {
                var_v0_2 = 0xC8;
            }
            sp2C0 = var_v0_2;
            sp2C8 = (((((0xFEE6 << 0x11) | 0xCCCC) << 0x10) | 0xCCCC) << 0xD) | 0x199A;
            sp248 = 0;
            sp240 = 0x85;
            sp268 = 0;
            sp250 = 0x10;
            sp288 = 0;
            sp260 = 0x43;
            sp2A8 = 0;
            sp280 = 0x7D0;
            sp2A0 = 0x1388;
            sp2B0 = 0x40;
            sp2D0 = 0x10;
            sp270 = 0x40;
            sp290 = 0x40;
            sp2A4 = 1;
            sp2C4 = 1;
            sp244 = 1;
            sp264 = 1;
            sp284 = 1;
            dmeObjLayoutBegin_nitDme(0x85, 0, 0x43, 0x7D0);
            spA48 = &sp2C0;
            dmeObjLayoutAddField_nitDme(&spA40, 4, 1, 1);
            dmeObjRegisterType_nitDme(&D_004F9D18_nitDme, "NetVehicle", 0x38);
            dmeObjSetCallbacks_nitDme(D_004F9D18_nitDme, &netObjCreateCB_nitDme, &netObjUpdateVehicleCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 4, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp31B, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp31A, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp319, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp318, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp316, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp314, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp312, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp310, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp30E, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp30C, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp300, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp2F4, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp2E8, 4, 6);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp2E4, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp2DC, 1, 1);
            dmeObjRegisterType_nitDme(&D_004F9D24_nitDme, "NetWeapon", 0x4C);
            dmeObjSetCallbacks_nitDme(D_004F9D24_nitDme, &netWeaponCreateCB_nitDme, &netWeaponUpdateCB_nitDme, &netWeaponDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 4);
            dmeObjLayoutAddField_nitDme(&D_004F9CD0_nitDme, &sp370 - &sp36C, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&D_004F9CD4_nitDme, &sp370 - &sp360, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&spA40, &sp370 - &sp354, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp370 - &sp350, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp370 - &sp34C, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp370 - &sp348, 4, 4);
            dmeObjRegisterType_nitDme(&D_004F9CA0_nitDme, "NetFodder", 0x2C);
            dmeObjSetCallbacks_nitDme(D_004F9CA0_nitDme, &netObjCreateCB_nitDme, &netFodderUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp39C, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp398, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp394, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp390, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp370, 4, 6);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp350, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp34C, 4, 4);
            dmeObjRegisterType_nitDme(&D_004F9CA4_nitDme, "NetStats", 0x58);
            dmeObjSetCallbacks_nitDme(D_004F9CA4_nitDme, &netObjCreateCB_nitDme, &netStatsUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 6);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp3E0, 4, 6);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp3C0, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp3A0, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp380, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp378, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp370, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp368, 4, 4);
            dmeObjRegisterType_nitDme(&D_004F9CA8_nitDme, "NetPersistantStats", 0xA0);
            dmeObjSetCallbacks_nitDme(D_004F9CA8_nitDme, &netObjCreateCB_nitDme, &netStatsUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp49C, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp49B, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp49A, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp498, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp494, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp490, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp48C, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp488, 2, 3);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp485, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp480, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp47C, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp47B, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp478, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp474, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp470, 2, 3);
            dmeObjLayoutAddField_nitDme(&D_004F9CB8_nitDme, &sp4A0 - &sp46E, 1, 0);
            dmeObjLayoutAddField_nitDme(&D_004F9CBC_nitDme, &sp4A0 - &sp464, 1, 1);
            dmeObjLayoutAddField_nitDme(&D_004F9CC0_nitDme, &sp4A0 - &sp414, 1, 1);
            dmeObjLayoutAddField_nitDme(&D_004F9CCC_nitDme, &sp4A0 - &sp3E4, 1, 1);
            dmeObjLayoutAddField_nitDme(&D_004F9CC8_nitDme, &sp4A0 - &sp486, 1, 0);
            dmeObjLayoutAddField_nitDme(&D_004F9CC4_nitDme, &sp4A0 - &sp3DC, 1, 0);
            dmeObjRegisterType_nitDme(&D_004F9CAC_nitDme, "NetGameData", 0xC8);
            dmeObjSetCallbacks_nitDme(D_004F9CAC_nitDme, &netObjCreateCB_nitDme, &netGameDataUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp570 - &sp560, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp570 - &sp55F, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp570 - &sp55E, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp570 - &sp55C, 2, 2);
            dmeObjRegisterType_nitDme(&D_004F9CB0_nitDme, "NetVehiclePadFlagsObj", 0x18);
            dmeObjSetCallbacks_nitDme(D_004F9CB0_nitDme, &netObjCreateCB_nitDme, &netPadFlagsUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            func_001192E8_nitDme(&sp590);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp590 - &sp584, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp590 - &sp580, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp590 - &sp57C, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp590 - &sp570, 4, 4);
            dmeObjRegisterType_nitDme(&D_004F9CB4_nitDme, "NetArtifactObj\0BASCUS-97196\0 !\"#$%&'()*+,-.0123456789:;<=>?ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_abcdefghijklmnopqrstuvwxyz{}\0\00123456789\0\0 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\0 .0123456789", 0x7C);
            dmeObjSetCallbacks_nitDme(D_004F9CB4_nitDme, &netObjCreateCB_nitDme, &netObjUpdateVehicleCB_nitDme, &netObjDestroyCB_nitDme);
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp610, &sp610, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp610, &sp614, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp610, &sp620, 0x40, 1);
            dmeMsgRegister_nitDme(&spA44, &netMsgGameEventHandler_nitDme);
            D_004F9D84_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp660, &sp660, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp660, &sp670, 0xE0, 1);
            dmeMsgRegister_nitDme(&spA44, &netMsgSessionHandler_nitDme);
            D_004F9D88_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp750, &sp750, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp750, &sp754, 0xBC, 1);
            dmeMsgRegister_nitDme(&spA44, &netMsgWorldEventHandler_nitDme);
            D_004F9D90_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp810, &sp810, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp810, &sp814, 0x5C, 1);
            dmeMsgRegister_nitDme(&spA44, &netMsgPlayerInfoHandler_nitDme);
            D_004F9D94_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp870, &sp870, 0x30, 8);
            dmeMsgRegister_nitDme(&spA44, &netMsgRosterHandler_nitDme);
            D_004F9D98_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp9F0, &sp9F0, 4, 4);
            dmeMsgLayoutAddField_nitDme(&sp9F0, &sp9F4, 0x44, 0x44);
            dmeMsgRegister_nitDme(&spA44, &netMsgChatHandler_nitDme);
            D_004F9D80_nitDme = spA44;
            func_00266478_nitDme(&func_0016C590_nitDme);
            var_v0 = 1;
        }
    }
    return var_v0;
}
//@@ netInitDme m2c4
#include "m2c_macros.h"
M2C_UNK dmeMsgLayoutAddField_nitDme() __asm__("dmeMsgLayoutAddField");
M2C_UNK dmeMsgLayoutBegin_nitDme() __asm__("dmeMsgLayoutBegin");
M2C_UNK dmeMsgRegister_nitDme() __asm__("dmeMsgRegister");
M2C_UNK dmeObjLayoutAddField_nitDme() __asm__("dmeObjLayoutAddField");
M2C_UNK dmeObjLayoutBegin_nitDme() __asm__("dmeObjLayoutBegin");
M2C_UNK dmeObjRegisterType_nitDme() __asm__("dmeObjRegisterType");
M2C_UNK dmeObjSetCallbacks_nitDme() __asm__("dmeObjSetCallbacks");
M2C_UNK func_001192E8_nitDme() __asm__("func_001192E8");
M2C_UNK func_00266478_nitDme() __asm__("func_00266478");
s32 func_00266F50_nitDme() __asm__("func_00266F50");
s32 func_00267080_nitDme() __asm__("func_00267080");
M2C_UNK func_00268ED0_nitDme() __asm__("func_00268ED0");
M2C_UNK func_00268F20_nitDme() __asm__("func_00268F20");
M2C_UNK func_00269318_nitDme() __asm__("func_00269318");
M2C_UNK memset_nitDme() __asm__("memset");
M2C_UNK printf_nitDme() __asm__("printf");
extern s32 D_00319924_nitDme __asm__("D_00319924");
extern u8 D_004E72A0_nitDme __asm__("D_004E72A0");
extern s32 D_004F9CA0_nitDme __asm__("D_004F9CA0");
extern s32 D_004F9CA4_nitDme __asm__("D_004F9CA4");
extern s32 D_004F9CA8_nitDme __asm__("D_004F9CA8");
extern s32 D_004F9CAC_nitDme __asm__("D_004F9CAC");
extern s32 D_004F9CB0_nitDme __asm__("D_004F9CB0");
extern s32 D_004F9CB4_nitDme __asm__("D_004F9CB4");
extern M2C_UNK D_004F9CB8_nitDme __asm__("D_004F9CB8");
extern M2C_UNK D_004F9CBC_nitDme __asm__("D_004F9CBC");
extern M2C_UNK D_004F9CC0_nitDme __asm__("D_004F9CC0");
extern M2C_UNK D_004F9CC4_nitDme __asm__("D_004F9CC4");
extern M2C_UNK D_004F9CC8_nitDme __asm__("D_004F9CC8");
extern M2C_UNK D_004F9CCC_nitDme __asm__("D_004F9CCC");
extern M2C_UNK D_004F9CD0_nitDme __asm__("D_004F9CD0");
extern M2C_UNK D_004F9CD4_nitDme __asm__("D_004F9CD4");
extern s32 D_004F9D18_nitDme __asm__("D_004F9D18");
extern s32 D_004F9D24_nitDme __asm__("D_004F9D24");
extern s32 D_004F9D80_nitDme __asm__("D_004F9D80");
extern s32 D_004F9D84_nitDme __asm__("D_004F9D84");
extern s32 D_004F9D88_nitDme __asm__("D_004F9D88");
extern s32 D_004F9D90_nitDme __asm__("D_004F9D90");
extern s32 D_004F9D94_nitDme __asm__("D_004F9D94");
extern s32 D_004F9D98_nitDme __asm__("D_004F9D98");
extern M2C_UNK func_0016C590_nitDme __asm__("func_0016C590");
extern M2C_UNK netFodderUpdateCB_nitDme __asm__("netFodderUpdateCB");
extern M2C_UNK netGameDataUpdateCB_nitDme __asm__("netGameDataUpdateCB");
extern M2C_UNK netMsgChatHandler_nitDme __asm__("netMsgChatHandler");
extern M2C_UNK netMsgGameEventHandler_nitDme __asm__("netMsgGameEventHandler");
extern M2C_UNK netMsgPlayerInfoHandler_nitDme __asm__("netMsgPlayerInfoHandler");
extern M2C_UNK netMsgRosterHandler_nitDme __asm__("netMsgRosterHandler");
extern M2C_UNK netMsgSessionHandler_nitDme __asm__("netMsgSessionHandler");
extern M2C_UNK netMsgWorldEventHandler_nitDme __asm__("netMsgWorldEventHandler");
extern M2C_UNK netObjCreateCB_nitDme __asm__("netObjCreateCB");
extern M2C_UNK netObjDestroyCB_nitDme __asm__("netObjDestroyCB");
extern M2C_UNK netObjUpdateVehicleCB_nitDme __asm__("netObjUpdateVehicleCB");
extern M2C_UNK netPadFlagsUpdateCB_nitDme __asm__("netPadFlagsUpdateCB");
extern M2C_UNK netStatsUpdateCB_nitDme __asm__("netStatsUpdateCB");
extern M2C_UNK netWeaponCreateCB_nitDme __asm__("netWeaponCreateCB");
extern M2C_UNK netWeaponDestroyCB_nitDme __asm__("netWeaponDestroyCB");
extern M2C_UNK netWeaponUpdateCB_nitDme __asm__("netWeaponUpdateCB");

s32 netInitDme(void) {
    u8 sp[0xA10];
    M2C_UNK sp1;
    u8 sp100;
    M2C_UNK sp101;
    M2C_UNK sp200;
    s32 sp204;
    s32 sp208;
    M2C_UNK sp220;
    s32 sp240;
    s32 sp244;
    s64 sp248;
    s8 sp250;
    s32 sp260;
    s32 sp264;
    s64 sp268;
    s8 sp270;
    s32 sp280;
    s32 sp284;
    s64 sp288;
    s8 sp290;
    s32 sp2A0;
    s32 sp2A4;
    s64 sp2A8;
    s8 sp2B0;
    s32 sp2C0;
    s32 sp2C4;
    s64 sp2C8;
    s8 sp2D0;
    M2C_UNK sp2DC;
    M2C_UNK sp2E4;
    M2C_UNK sp2E8;
    M2C_UNK sp2F4;
    M2C_UNK sp300;
    M2C_UNK sp30C;
    M2C_UNK sp30E;
    M2C_UNK sp310;
    M2C_UNK sp312;
    M2C_UNK sp314;
    M2C_UNK sp316;
    M2C_UNK sp318;
    M2C_UNK sp319;
    M2C_UNK sp31A;
    M2C_UNK sp31B;
    M2C_UNK sp320;
    M2C_UNK sp348;
    M2C_UNK sp34C;
    M2C_UNK sp350;
    M2C_UNK sp354;
    M2C_UNK sp360;
    M2C_UNK sp368;
    M2C_UNK sp36C;
    M2C_UNK sp370;
    M2C_UNK sp378;
    M2C_UNK sp380;
    M2C_UNK sp390;
    M2C_UNK sp394;
    M2C_UNK sp398;
    M2C_UNK sp39C;
    M2C_UNK sp3A0;
    M2C_UNK sp3C0;
    M2C_UNK sp3DC;
    M2C_UNK sp3E0;
    M2C_UNK sp3E4;
    M2C_UNK sp400;
    M2C_UNK sp414;
    M2C_UNK sp464;
    M2C_UNK sp46E;
    M2C_UNK sp470;
    M2C_UNK sp474;
    M2C_UNK sp478;
    M2C_UNK sp47B;
    M2C_UNK sp47C;
    M2C_UNK sp480;
    M2C_UNK sp485;
    M2C_UNK sp486;
    M2C_UNK sp488;
    M2C_UNK sp48C;
    M2C_UNK sp490;
    M2C_UNK sp494;
    M2C_UNK sp498;
    M2C_UNK sp49A;
    M2C_UNK sp49B;
    M2C_UNK sp49C;
    M2C_UNK sp4A0;
    M2C_UNK sp55C;
    M2C_UNK sp55E;
    M2C_UNK sp55F;
    M2C_UNK sp560;
    M2C_UNK sp570;
    M2C_UNK sp57C;
    M2C_UNK sp580;
    M2C_UNK sp584;
    M2C_UNK sp590;
    M2C_UNK sp610;
    M2C_UNK sp614;
    M2C_UNK sp620;
    M2C_UNK sp660;
    M2C_UNK sp670;
    M2C_UNK sp750;
    M2C_UNK sp754;
    M2C_UNK sp810;
    M2C_UNK sp814;
    M2C_UNK sp870;
    M2C_UNK sp9F0;
    M2C_UNK sp9F4;
    M2C_UNK spA40;
    s32 spA44;
    s32* spA48;
    M2C_UNK* temp_s0_2;
    s32 var_v0;
    s32 var_v0_2;
    u8 temp_s0;

    temp_s0 = D_004E72A0_nitDme;
    memset_nitDme(&sp1, 0, 0xFF);
    sp100 = temp_s0;
    memset_nitDme(&sp101, 0, 0xFF);
    func_00268ED0_nitDme(&sp200);
    sp208 = 0x272F;
    sp204 = 0x40;
    func_00268F20_nitDme(&sp200, &sp220);
    func_00269318_nitDme(0x2000, 0x2000);
    var_v0 = -1;
    if (func_00266F50_nitDme(sp) == 0) {
        var_v0 = -1;
        if (func_00267080_nitDme(&sp100) == 0) {
            temp_s0_2 = "-----------------------------------------------------------------\n";
            printf_nitDme(temp_s0_2);
            printf_nitDme("NETWORK: Initialized Distributed Memory Engine\n");
            printf_nitDme("         Build Version  %s\n", sp);
            printf_nitDme("         Client Version %s\n", &sp100);
            printf_nitDme(temp_s0_2);
            var_v0_2 = 0x12C;
            if (D_00319924_nitDme == 0) {
                var_v0_2 = 0xC8;
            }
            sp2C0 = var_v0_2;
            sp2C8 = (((((0xFEE6 << 0x11) | 0xCCCC) << 0x10) | 0xCCCC) << 0xD) | 0x199A;
            sp248 = 0;
            sp240 = 0x85;
            sp268 = 0;
            sp250 = 0x10;
            sp288 = 0;
            sp260 = 0x43;
            sp2A8 = 0;
            sp280 = 0x7D0;
            sp2A0 = 0x1388;
            sp2B0 = 0x40;
            sp2D0 = 0x10;
            sp270 = 0x40;
            sp290 = 0x40;
            sp2A4 = 1;
            sp2C4 = 1;
            sp244 = 1;
            sp264 = 1;
            sp284 = 1;
            dmeObjLayoutBegin_nitDme(0x85, 0, 0x43, 0x7D0);
            spA48 = &sp2C0;
            dmeObjLayoutAddField_nitDme(&spA40, 4, 1, 1);
            dmeObjRegisterType_nitDme(&D_004F9D18_nitDme, "NetVehicle", 0x38);
            dmeObjSetCallbacks_nitDme(D_004F9D18_nitDme, &netObjCreateCB_nitDme, &netObjUpdateVehicleCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 4, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp31B, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp31A, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp319, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp318, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp316, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp314, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp312, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp310, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp30E, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp30C, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp300, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp2F4, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp2E8, 4, 6);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp2E4, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp2DC, 1, 1);
            dmeObjRegisterType_nitDme(&D_004F9D24_nitDme, "NetWeapon", 0x4C);
            dmeObjSetCallbacks_nitDme(D_004F9D24_nitDme, &netWeaponCreateCB_nitDme, &netWeaponUpdateCB_nitDme, &netWeaponDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 4);
            dmeObjLayoutAddField_nitDme(&D_004F9CD0_nitDme, &sp370 - &sp36C, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&D_004F9CD4_nitDme, &sp370 - &sp360, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&spA40, &sp370 - &sp354, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp370 - &sp350, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp370 - &sp34C, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp370 - &sp348, 4, 4);
            dmeObjRegisterType_nitDme(&D_004F9CA0_nitDme, "NetFodder", 0x2C);
            dmeObjSetCallbacks_nitDme(D_004F9CA0_nitDme, &netObjCreateCB_nitDme, &netFodderUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp39C, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp398, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp394, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp390, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp370, 4, 6);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp350, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp34C, 4, 4);
            dmeObjRegisterType_nitDme(&D_004F9CA4_nitDme, "NetStats", 0x58);
            dmeObjSetCallbacks_nitDme(D_004F9CA4_nitDme, &netObjCreateCB_nitDme, &netStatsUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 6);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp3E0, 4, 6);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp3C0, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp3A0, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp380, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp378, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp370, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp368, 4, 4);
            dmeObjRegisterType_nitDme(&D_004F9CA8_nitDme, "NetPersistantStats", 0xA0);
            dmeObjSetCallbacks_nitDme(D_004F9CA8_nitDme, &netObjCreateCB_nitDme, &netStatsUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp49C, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp49B, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp49A, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp498, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp494, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp490, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp48C, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp488, 2, 3);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp485, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp480, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp47C, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp47B, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp478, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp474, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp470, 2, 3);
            dmeObjLayoutAddField_nitDme(&D_004F9CB8_nitDme, &sp4A0 - &sp46E, 1, 0);
            dmeObjLayoutAddField_nitDme(&D_004F9CBC_nitDme, &sp4A0 - &sp464, 1, 1);
            dmeObjLayoutAddField_nitDme(&D_004F9CC0_nitDme, &sp4A0 - &sp414, 1, 1);
            dmeObjLayoutAddField_nitDme(&D_004F9CCC_nitDme, &sp4A0 - &sp3E4, 1, 1);
            dmeObjLayoutAddField_nitDme(&D_004F9CC8_nitDme, &sp4A0 - &sp486, 1, 0);
            dmeObjLayoutAddField_nitDme(&D_004F9CC4_nitDme, &sp4A0 - &sp3DC, 1, 0);
            dmeObjRegisterType_nitDme(&D_004F9CAC_nitDme, "NetGameData", 0xC8);
            dmeObjSetCallbacks_nitDme(D_004F9CAC_nitDme, &netObjCreateCB_nitDme, &netGameDataUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp570 - &sp560, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp570 - &sp55F, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp570 - &sp55E, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp570 - &sp55C, 2, 2);
            dmeObjRegisterType_nitDme(&D_004F9CB0_nitDme, "NetVehiclePadFlagsObj", 0x18);
            dmeObjSetCallbacks_nitDme(D_004F9CB0_nitDme, &netObjCreateCB_nitDme, &netPadFlagsUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            func_001192E8_nitDme(&sp590);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp590 - &sp584, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp590 - &sp580, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp590 - &sp57C, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp590 - &sp570, 4, 4);
            dmeObjRegisterType_nitDme(&D_004F9CB4_nitDme, "NetArtifactObj\0BASCUS-97196\0 !\"#$%&'()*+,-.0123456789:;<=>?ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_abcdefghijklmnopqrstuvwxyz{}\0\00123456789\0\0 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\0 .0123456789", 0x7C);
            dmeObjSetCallbacks_nitDme(D_004F9CB4_nitDme, &netObjCreateCB_nitDme, &netObjUpdateVehicleCB_nitDme, &netObjDestroyCB_nitDme);
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp610, &sp610, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp610, &sp614, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp610, &sp620, 0x40, 1);
            dmeMsgRegister_nitDme(&spA44, &netMsgGameEventHandler_nitDme);
            D_004F9D84_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp660, &sp660, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp660, &sp670, 0xE0, 1);
            dmeMsgRegister_nitDme(&spA44, &netMsgSessionHandler_nitDme);
            D_004F9D88_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp750, &sp750, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp750, &sp754, 0xBC, 1);
            dmeMsgRegister_nitDme(&spA44, &netMsgWorldEventHandler_nitDme);
            D_004F9D90_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp810, &sp810, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp810, &sp814, 0x5C, 1);
            dmeMsgRegister_nitDme(&spA44, &netMsgPlayerInfoHandler_nitDme);
            D_004F9D94_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp870, &sp870, 0x30, 8);
            dmeMsgRegister_nitDme(&spA44, &netMsgRosterHandler_nitDme);
            D_004F9D98_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp9F0, &sp9F0, 4, 4);
            dmeMsgLayoutAddField_nitDme(&sp9F0, &sp9F4, 0x44, 0x44);
            dmeMsgRegister_nitDme(&spA44, &netMsgChatHandler_nitDme);
            D_004F9D80_nitDme = spA44;
            func_00266478_nitDme(&func_0016C590_nitDme);
            var_v0 = 1;
        }
    }
    return var_v0;
}
//@@ netInitDme m2c5
#include "m2c_macros.h"
M2C_UNK dmeMsgLayoutAddField_nitDme() __asm__("dmeMsgLayoutAddField");
M2C_UNK dmeMsgLayoutBegin_nitDme() __asm__("dmeMsgLayoutBegin");
M2C_UNK dmeMsgRegister_nitDme() __asm__("dmeMsgRegister");
M2C_UNK dmeObjLayoutAddField_nitDme() __asm__("dmeObjLayoutAddField");
M2C_UNK dmeObjLayoutBegin_nitDme() __asm__("dmeObjLayoutBegin");
M2C_UNK dmeObjRegisterType_nitDme() __asm__("dmeObjRegisterType");
M2C_UNK dmeObjSetCallbacks_nitDme() __asm__("dmeObjSetCallbacks");
M2C_UNK func_001192E8_nitDme() __asm__("func_001192E8");
M2C_UNK func_00266478_nitDme() __asm__("func_00266478");
s32 func_00266F50_nitDme() __asm__("func_00266F50");
s32 func_00267080_nitDme() __asm__("func_00267080");
M2C_UNK func_00268ED0_nitDme() __asm__("func_00268ED0");
M2C_UNK func_00268F20_nitDme() __asm__("func_00268F20");
M2C_UNK func_00269318_nitDme() __asm__("func_00269318");
M2C_UNK memset_nitDme() __asm__("memset");
M2C_UNK printf_nitDme() __asm__("printf");
extern s32 D_00319924_nitDme __asm__("D_00319924");
extern u8 D_004E72A0_nitDme __asm__("D_004E72A0");
extern s32 D_004F9CA0_nitDme __asm__("D_004F9CA0");
extern s32 D_004F9CA4_nitDme __asm__("D_004F9CA4");
extern s32 D_004F9CA8_nitDme __asm__("D_004F9CA8");
extern s32 D_004F9CAC_nitDme __asm__("D_004F9CAC");
extern s32 D_004F9CB0_nitDme __asm__("D_004F9CB0");
extern s32 D_004F9CB4_nitDme __asm__("D_004F9CB4");
extern M2C_UNK D_004F9CB8_nitDme __asm__("D_004F9CB8");
extern M2C_UNK D_004F9CBC_nitDme __asm__("D_004F9CBC");
extern M2C_UNK D_004F9CC0_nitDme __asm__("D_004F9CC0");
extern M2C_UNK D_004F9CC4_nitDme __asm__("D_004F9CC4");
extern M2C_UNK D_004F9CC8_nitDme __asm__("D_004F9CC8");
extern M2C_UNK D_004F9CCC_nitDme __asm__("D_004F9CCC");
extern M2C_UNK D_004F9CD0_nitDme __asm__("D_004F9CD0");
extern M2C_UNK D_004F9CD4_nitDme __asm__("D_004F9CD4");
extern s32 D_004F9D18_nitDme __asm__("D_004F9D18");
extern s32 D_004F9D24_nitDme __asm__("D_004F9D24");
extern s32 D_004F9D80_nitDme __asm__("D_004F9D80");
extern s32 D_004F9D84_nitDme __asm__("D_004F9D84");
extern s32 D_004F9D88_nitDme __asm__("D_004F9D88");
extern s32 D_004F9D90_nitDme __asm__("D_004F9D90");
extern s32 D_004F9D94_nitDme __asm__("D_004F9D94");
extern s32 D_004F9D98_nitDme __asm__("D_004F9D98");
extern M2C_UNK func_0016C590_nitDme __asm__("func_0016C590");
extern M2C_UNK netFodderUpdateCB_nitDme __asm__("netFodderUpdateCB");
extern M2C_UNK netGameDataUpdateCB_nitDme __asm__("netGameDataUpdateCB");
extern M2C_UNK netMsgChatHandler_nitDme __asm__("netMsgChatHandler");
extern M2C_UNK netMsgGameEventHandler_nitDme __asm__("netMsgGameEventHandler");
extern M2C_UNK netMsgPlayerInfoHandler_nitDme __asm__("netMsgPlayerInfoHandler");
extern M2C_UNK netMsgRosterHandler_nitDme __asm__("netMsgRosterHandler");
extern M2C_UNK netMsgSessionHandler_nitDme __asm__("netMsgSessionHandler");
extern M2C_UNK netMsgWorldEventHandler_nitDme __asm__("netMsgWorldEventHandler");
extern M2C_UNK netObjCreateCB_nitDme __asm__("netObjCreateCB");
extern M2C_UNK netObjDestroyCB_nitDme __asm__("netObjDestroyCB");
extern M2C_UNK netObjUpdateVehicleCB_nitDme __asm__("netObjUpdateVehicleCB");
extern M2C_UNK netPadFlagsUpdateCB_nitDme __asm__("netPadFlagsUpdateCB");
extern M2C_UNK netStatsUpdateCB_nitDme __asm__("netStatsUpdateCB");
extern M2C_UNK netWeaponCreateCB_nitDme __asm__("netWeaponCreateCB");
extern M2C_UNK netWeaponDestroyCB_nitDme __asm__("netWeaponDestroyCB");
extern M2C_UNK netWeaponUpdateCB_nitDme __asm__("netWeaponUpdateCB");

s32 netInitDme(void) {
    u8 sp[0xA00];
    M2C_UNK sp1;
    u8 sp100;
    M2C_UNK sp101;
    M2C_UNK sp200;
    s32 sp204;
    s32 sp208;
    M2C_UNK sp220;
    s32 sp240;
    s32 sp244;
    s64 sp248;
    s8 sp250;
    s32 sp260;
    s32 sp264;
    s64 sp268;
    s8 sp270;
    s32 sp280;
    s32 sp284;
    s64 sp288;
    s8 sp290;
    s32 sp2A0;
    s32 sp2A4;
    s64 sp2A8;
    s8 sp2B0;
    s32 sp2C0;
    s32 sp2C4;
    s64 sp2C8;
    s8 sp2D0;
    M2C_UNK sp2DC;
    M2C_UNK sp2E4;
    M2C_UNK sp2E8;
    M2C_UNK sp2F4;
    M2C_UNK sp300;
    M2C_UNK sp30C;
    M2C_UNK sp30E;
    M2C_UNK sp310;
    M2C_UNK sp312;
    M2C_UNK sp314;
    M2C_UNK sp316;
    M2C_UNK sp318;
    M2C_UNK sp319;
    M2C_UNK sp31A;
    M2C_UNK sp31B;
    M2C_UNK sp320;
    M2C_UNK sp348;
    M2C_UNK sp34C;
    M2C_UNK sp350;
    M2C_UNK sp354;
    M2C_UNK sp360;
    M2C_UNK sp368;
    M2C_UNK sp36C;
    M2C_UNK sp370;
    M2C_UNK sp378;
    M2C_UNK sp380;
    M2C_UNK sp390;
    M2C_UNK sp394;
    M2C_UNK sp398;
    M2C_UNK sp39C;
    M2C_UNK sp3A0;
    M2C_UNK sp3C0;
    M2C_UNK sp3DC;
    M2C_UNK sp3E0;
    M2C_UNK sp3E4;
    M2C_UNK sp400;
    M2C_UNK sp414;
    M2C_UNK sp464;
    M2C_UNK sp46E;
    M2C_UNK sp470;
    M2C_UNK sp474;
    M2C_UNK sp478;
    M2C_UNK sp47B;
    M2C_UNK sp47C;
    M2C_UNK sp480;
    M2C_UNK sp485;
    M2C_UNK sp486;
    M2C_UNK sp488;
    M2C_UNK sp48C;
    M2C_UNK sp490;
    M2C_UNK sp494;
    M2C_UNK sp498;
    M2C_UNK sp49A;
    M2C_UNK sp49B;
    M2C_UNK sp49C;
    M2C_UNK sp4A0;
    M2C_UNK sp55C;
    M2C_UNK sp55E;
    M2C_UNK sp55F;
    M2C_UNK sp560;
    M2C_UNK sp570;
    M2C_UNK sp57C;
    M2C_UNK sp580;
    M2C_UNK sp584;
    M2C_UNK sp590;
    M2C_UNK sp610;
    M2C_UNK sp614;
    M2C_UNK sp620;
    M2C_UNK sp660;
    M2C_UNK sp670;
    M2C_UNK sp750;
    M2C_UNK sp754;
    M2C_UNK sp810;
    M2C_UNK sp814;
    M2C_UNK sp870;
    M2C_UNK sp9F0;
    M2C_UNK sp9F4;
    M2C_UNK spA40;
    s32 spA44;
    s32* spA48;
    M2C_UNK* temp_s0_2;
    s32 var_v0;
    s32 var_v0_2;
    u8 temp_s0;

    temp_s0 = D_004E72A0_nitDme;
    memset_nitDme(&sp1, 0, 0xFF);
    sp100 = temp_s0;
    memset_nitDme(&sp101, 0, 0xFF);
    func_00268ED0_nitDme(&sp200);
    sp208 = 0x272F;
    sp204 = 0x40;
    func_00268F20_nitDme(&sp200, &sp220);
    func_00269318_nitDme(0x2000, 0x2000);
    var_v0 = -1;
    if (func_00266F50_nitDme(sp) == 0) {
        var_v0 = -1;
        if (func_00267080_nitDme(&sp100) == 0) {
            temp_s0_2 = "-----------------------------------------------------------------\n";
            printf_nitDme(temp_s0_2);
            printf_nitDme("NETWORK: Initialized Distributed Memory Engine\n");
            printf_nitDme("         Build Version  %s\n", sp);
            printf_nitDme("         Client Version %s\n", &sp100);
            printf_nitDme(temp_s0_2);
            var_v0_2 = 0x12C;
            if (D_00319924_nitDme == 0) {
                var_v0_2 = 0xC8;
            }
            sp2C0 = var_v0_2;
            sp2C8 = (((((0xFEE6 << 0x11) | 0xCCCC) << 0x10) | 0xCCCC) << 0xD) | 0x199A;
            sp248 = 0;
            sp240 = 0x85;
            sp268 = 0;
            sp250 = 0x10;
            sp288 = 0;
            sp260 = 0x43;
            sp2A8 = 0;
            sp280 = 0x7D0;
            sp2A0 = 0x1388;
            sp2B0 = 0x40;
            sp2D0 = 0x10;
            sp270 = 0x40;
            sp290 = 0x40;
            sp2A4 = 1;
            sp2C4 = 1;
            sp244 = 1;
            sp264 = 1;
            sp284 = 1;
            dmeObjLayoutBegin_nitDme(0x85, 0, 0x43, 0x7D0);
            spA48 = &sp2C0;
            dmeObjLayoutAddField_nitDme(&spA40, 4, 1, 1);
            dmeObjRegisterType_nitDme(&D_004F9D18_nitDme, "NetVehicle", 0x38);
            dmeObjSetCallbacks_nitDme(D_004F9D18_nitDme, &netObjCreateCB_nitDme, &netObjUpdateVehicleCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 4, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp31B, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp31A, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp319, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp318, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp316, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp314, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp312, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp310, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp30E, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp30C, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp300, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp2F4, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp2E8, 4, 6);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp2E4, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp320 - &sp2DC, 1, 1);
            dmeObjRegisterType_nitDme(&D_004F9D24_nitDme, "NetWeapon", 0x4C);
            dmeObjSetCallbacks_nitDme(D_004F9D24_nitDme, &netWeaponCreateCB_nitDme, &netWeaponUpdateCB_nitDme, &netWeaponDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 4);
            dmeObjLayoutAddField_nitDme(&D_004F9CD0_nitDme, &sp370 - &sp36C, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&D_004F9CD4_nitDme, &sp370 - &sp360, 0xC, 0xD);
            dmeObjLayoutAddField_nitDme(&spA40, &sp370 - &sp354, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp370 - &sp350, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp370 - &sp34C, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp370 - &sp348, 4, 4);
            dmeObjRegisterType_nitDme(&D_004F9CA0_nitDme, "NetFodder", 0x2C);
            dmeObjSetCallbacks_nitDme(D_004F9CA0_nitDme, &netObjCreateCB_nitDme, &netFodderUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp39C, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp398, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp394, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp390, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp370, 4, 6);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp350, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp3A0 - &sp34C, 4, 4);
            dmeObjRegisterType_nitDme(&D_004F9CA4_nitDme, "NetStats", 0x58);
            dmeObjSetCallbacks_nitDme(D_004F9CA4_nitDme, &netObjCreateCB_nitDme, &netStatsUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 6);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp3E0, 4, 6);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp3C0, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp3A0, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp380, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp378, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp370, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp400 - &sp368, 4, 4);
            dmeObjRegisterType_nitDme(&D_004F9CA8_nitDme, "NetPersistantStats", 0xA0);
            dmeObjSetCallbacks_nitDme(D_004F9CA8_nitDme, &netObjCreateCB_nitDme, &netStatsUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp49C, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp49B, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp49A, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp498, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp494, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp490, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp48C, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp488, 2, 3);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp485, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp480, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp47C, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp47B, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp478, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp474, 4, 5);
            dmeObjLayoutAddField_nitDme(&spA40, &sp4A0 - &sp470, 2, 3);
            dmeObjLayoutAddField_nitDme(&D_004F9CB8_nitDme, &sp4A0 - &sp46E, 1, 0);
            dmeObjLayoutAddField_nitDme(&D_004F9CBC_nitDme, &sp4A0 - &sp464, 1, 1);
            dmeObjLayoutAddField_nitDme(&D_004F9CC0_nitDme, &sp4A0 - &sp414, 1, 1);
            dmeObjLayoutAddField_nitDme(&D_004F9CCC_nitDme, &sp4A0 - &sp3E4, 1, 1);
            dmeObjLayoutAddField_nitDme(&D_004F9CC8_nitDme, &sp4A0 - &sp486, 1, 0);
            dmeObjLayoutAddField_nitDme(&D_004F9CC4_nitDme, &sp4A0 - &sp3DC, 1, 0);
            dmeObjRegisterType_nitDme(&D_004F9CAC_nitDme, "NetGameData", 0xC8);
            dmeObjSetCallbacks_nitDme(D_004F9CAC_nitDme, &netObjCreateCB_nitDme, &netGameDataUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 1, 1);
            dmeObjLayoutAddField_nitDme(&spA40, &sp570 - &sp560, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp570 - &sp55F, 1, 0);
            dmeObjLayoutAddField_nitDme(&spA40, &sp570 - &sp55E, 2, 2);
            dmeObjLayoutAddField_nitDme(&spA40, &sp570 - &sp55C, 2, 2);
            dmeObjRegisterType_nitDme(&D_004F9CB0_nitDme, "NetVehiclePadFlagsObj", 0x18);
            dmeObjSetCallbacks_nitDme(D_004F9CB0_nitDme, &netObjCreateCB_nitDme, &netPadFlagsUpdateCB_nitDme, &netObjDestroyCB_nitDme);
            func_001192E8_nitDme(&sp590);
            dmeObjLayoutBegin_nitDme();
            dmeObjLayoutAddField_nitDme(&spA40, 0, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp590 - &sp584, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp590 - &sp580, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp590 - &sp57C, 4, 4);
            dmeObjLayoutAddField_nitDme(&spA40, &sp590 - &sp570, 4, 4);
            dmeObjRegisterType_nitDme(&D_004F9CB4_nitDme, "NetArtifactObj\0BASCUS-97196\0 !\"#$%&'()*+,-.0123456789:;<=>?ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_abcdefghijklmnopqrstuvwxyz{}\0\00123456789\0\0 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\0 .0123456789", 0x7C);
            dmeObjSetCallbacks_nitDme(D_004F9CB4_nitDme, &netObjCreateCB_nitDme, &netObjUpdateVehicleCB_nitDme, &netObjDestroyCB_nitDme);
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp610, &sp610, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp610, &sp614, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp610, &sp620, 0x40, 1);
            dmeMsgRegister_nitDme(&spA44, &netMsgGameEventHandler_nitDme);
            D_004F9D84_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp660, &sp660, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp660, &sp670, 0xE0, 1);
            dmeMsgRegister_nitDme(&spA44, &netMsgSessionHandler_nitDme);
            D_004F9D88_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp750, &sp750, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp750, &sp754, 0xBC, 1);
            dmeMsgRegister_nitDme(&spA44, &netMsgWorldEventHandler_nitDme);
            D_004F9D90_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp810, &sp810, 4, 1);
            dmeMsgLayoutAddField_nitDme(&sp810, &sp814, 0x5C, 1);
            dmeMsgRegister_nitDme(&spA44, &netMsgPlayerInfoHandler_nitDme);
            D_004F9D94_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp870, &sp870, 0x30, 8);
            dmeMsgRegister_nitDme(&spA44, &netMsgRosterHandler_nitDme);
            D_004F9D98_nitDme = spA44;
            dmeMsgLayoutBegin_nitDme();
            dmeMsgLayoutAddField_nitDme(&sp9F0, &sp9F0, 4, 4);
            dmeMsgLayoutAddField_nitDme(&sp9F0, &sp9F4, 0x44, 0x44);
            dmeMsgRegister_nitDme(&spA44, &netMsgChatHandler_nitDme);
            D_004F9D80_nitDme = spA44;
            func_00266478_nitDme(&func_0016C590_nitDme);
            var_v0 = 1;
        }
    }
    return var_v0;
}
//@@ func_0016E6F8 m2c0
#include "m2c_macros.h"
M2C_UNK WaitSema_16E6F8() __asm__("WaitSema");
s32 func_00291E90_16E6F8() __asm__("func_00291E90");
s32 func_002A7AF8_16E6F8() __asm__("func_002A7AF8");
extern s32 D_004F9D64_16E6F8 __asm__("D_004F9D64");
extern M2C_UNK D_004F9D68_16E6F8 __asm__("D_004F9D68");
extern M2C_UNK D_004F9D70_16E6F8 __asm__("D_004F9D70");
extern M2C_UNK D_004F9D78_16E6F8 __asm__("D_004F9D78");

void func_0016E6F8(s32 arg0) {
    u8 sp[0x10];
loop_1:
    WaitSema_16E6F8(arg0);
    if (D_004F9D64_16E6F8 & 1) {
        func_002A7AF8_16E6F8(&D_004F9D68_16E6F8, 0x5003, 0, 0);
        do {

        } while (func_002A7AF8_16E6F8(&D_004F9D70_16E6F8, 0x4806, 0, 0) < 0);
    } else {
        do {

        } while (func_002A7AF8_16E6F8(&D_004F9D78_16E6F8, 0x4402, 0, 0) < 0);
    }
    do {
loop_7:
        if (func_00291E90_16E6F8(sp) == 0) {
            goto loop_7;
        }
    } while (subroutine_arg0 != 0);
    goto loop_1;
}
//@@ func_0016E6F8 m2c1
#include "m2c_macros.h"
M2C_UNK WaitSema_16E6F8() __asm__("WaitSema");
s32 func_00291E90_16E6F8() __asm__("func_00291E90");
s32 func_002A7AF8_16E6F8() __asm__("func_002A7AF8");
extern s32 D_004F9D64_16E6F8 __asm__("D_004F9D64");
extern M2C_UNK D_004F9D68_16E6F8 __asm__("D_004F9D68");
extern M2C_UNK D_004F9D70_16E6F8 __asm__("D_004F9D70");
extern M2C_UNK D_004F9D78_16E6F8 __asm__("D_004F9D78");

void func_0016E6F8(s32 arg0) {
    u8 sp[0x8];
loop_1:
    WaitSema_16E6F8(arg0);
    if (D_004F9D64_16E6F8 & 1) {
        func_002A7AF8_16E6F8(&D_004F9D68_16E6F8, 0x5003, 0, 0);
        do {

        } while (func_002A7AF8_16E6F8(&D_004F9D70_16E6F8, 0x4806, 0, 0) < 0);
    } else {
        do {

        } while (func_002A7AF8_16E6F8(&D_004F9D78_16E6F8, 0x4402, 0, 0) < 0);
    }
    do {
loop_7:
        if (func_00291E90_16E6F8(sp) == 0) {
            goto loop_7;
        }
    } while (subroutine_arg0 != 0);
    goto loop_1;
}
//@@ func_0016E6F8 m2c2
#include "m2c_macros.h"
M2C_UNK WaitSema_16E6F8() __asm__("WaitSema");
s32 func_00291E90_16E6F8() __asm__("func_00291E90");
s32 func_002A7AF8_16E6F8() __asm__("func_002A7AF8");
extern s32 D_004F9D64_16E6F8 __asm__("D_004F9D64");
extern M2C_UNK D_004F9D68_16E6F8 __asm__("D_004F9D68");
extern M2C_UNK D_004F9D70_16E6F8 __asm__("D_004F9D70");
extern M2C_UNK D_004F9D78_16E6F8 __asm__("D_004F9D78");

void func_0016E6F8(s32 arg0) {
    u8 sp[0x4];
loop_1:
    WaitSema_16E6F8(arg0);
    if (D_004F9D64_16E6F8 & 1) {
        func_002A7AF8_16E6F8(&D_004F9D68_16E6F8, 0x5003, 0, 0);
        do {

        } while (func_002A7AF8_16E6F8(&D_004F9D70_16E6F8, 0x4806, 0, 0) < 0);
    } else {
        do {

        } while (func_002A7AF8_16E6F8(&D_004F9D78_16E6F8, 0x4402, 0, 0) < 0);
    }
    do {
loop_7:
        if (func_00291E90_16E6F8(sp) == 0) {
            goto loop_7;
        }
    } while (subroutine_arg0 != 0);
    goto loop_1;
}
//@@ func_0016E7D0 m2c0
#include "m2c_macros.h"
M2C_UNK ChangeThreadPriority_16E7D0() __asm__("ChangeThreadPriority");
s32 CreateSema_16E7D0() __asm__("CreateSema");
s32 CreateThread_16E7D0() __asm__("CreateThread");
M2C_UNK DeleteSema_16E7D0() __asm__("DeleteSema");
s32 GetThreadId_16E7D0() __asm__("GetThreadId");
M2C_UNK StartThread_16E7D0() __asm__("StartThread");
M2C_UNK func_00290D20_16E7D0() __asm__("func_00290D20");
extern s32 D_004F9D64_16E7D0 __asm__("D_004F9D64");
extern M2C_UNK D_004FDD60_16E7D0 __asm__("D_004FDD60");
extern M2C_UNK D_005015F0_16E7D0 __asm__("D_005015F0");
extern M2C_UNK func_0016E6D8_16E7D0 __asm__("func_0016E6D8");
extern M2C_UNK func_0016E6F8_16E7D0 __asm__("func_0016E6F8");

s32 func_0016E7D0(s32 arg0) {
    u8 sp[0x50];
    M2C_UNK sp30;
    s32 sp34;
    s32 sp38;
    s32 sp44;
    s32 temp_v0;
    s32 temp_v0_2;

    sp38 = 0;
    sp34 = 1;
    sp44 = 0;
    temp_v0 = CreateSema_16E7D0(&sp30);
    if (temp_v0 != -1) {
        ChangeThreadPriority_16E7D0(GetThreadId_16E7D0(), 2);
        temp_v0_2 = CreateThread_16E7D0(sp, &D_004FDD60_16E7D0, &D_005015F0_16E7D0, &D_005015F0_16E7D0, 1);
        if (temp_v0_2 != -1) {
            StartThread_16E7D0(temp_v0_2, temp_v0);
            func_00290D20_16E7D0(&func_0016E6D8_16E7D0, temp_v0);
            D_004F9D64_16E7D0 = arg0;
            return temp_v0;
        }
        DeleteSema_16E7D0(temp_v0);
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return -1;
    }
    return -1;
}
//@@ func_0016E7D0 m2c1
#include "m2c_macros.h"
M2C_UNK ChangeThreadPriority_16E7D0() __asm__("ChangeThreadPriority");
s32 CreateSema_16E7D0() __asm__("CreateSema");
s32 CreateThread_16E7D0() __asm__("CreateThread");
M2C_UNK DeleteSema_16E7D0() __asm__("DeleteSema");
s32 GetThreadId_16E7D0() __asm__("GetThreadId");
M2C_UNK StartThread_16E7D0() __asm__("StartThread");
M2C_UNK func_00290D20_16E7D0() __asm__("func_00290D20");
extern s32 D_004F9D64_16E7D0 __asm__("D_004F9D64");
extern M2C_UNK D_004FDD60_16E7D0 __asm__("D_004FDD60");
extern M2C_UNK D_005015F0_16E7D0 __asm__("D_005015F0");
extern M2C_UNK func_0016E6D8_16E7D0 __asm__("func_0016E6D8");
extern M2C_UNK func_0016E6F8_16E7D0 __asm__("func_0016E6F8");

s32 func_0016E7D0(s32 arg0) {
    u8 sp[0x40];
    M2C_UNK sp30;
    s32 sp34;
    s32 sp38;
    s32 sp44;
    s32 temp_v0;
    s32 temp_v0_2;

    sp38 = 0;
    sp34 = 1;
    sp44 = 0;
    temp_v0 = CreateSema_16E7D0(&sp30);
    if (temp_v0 != -1) {
        ChangeThreadPriority_16E7D0(GetThreadId_16E7D0(), 2);
        temp_v0_2 = CreateThread_16E7D0(sp, &D_004FDD60_16E7D0, &D_005015F0_16E7D0, &D_005015F0_16E7D0, 1);
        if (temp_v0_2 != -1) {
            StartThread_16E7D0(temp_v0_2, temp_v0);
            func_00290D20_16E7D0(&func_0016E6D8_16E7D0, temp_v0);
            D_004F9D64_16E7D0 = arg0;
            return temp_v0;
        }
        DeleteSema_16E7D0(temp_v0);
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return -1;
    }
    return -1;
}
//@@ func_0016E7D0 m2c2
#include "m2c_macros.h"
M2C_UNK ChangeThreadPriority_16E7D0() __asm__("ChangeThreadPriority");
s32 CreateSema_16E7D0() __asm__("CreateSema");
s32 CreateThread_16E7D0() __asm__("CreateThread");
M2C_UNK DeleteSema_16E7D0() __asm__("DeleteSema");
s32 GetThreadId_16E7D0() __asm__("GetThreadId");
M2C_UNK StartThread_16E7D0() __asm__("StartThread");
M2C_UNK func_00290D20_16E7D0() __asm__("func_00290D20");
extern s32 D_004F9D64_16E7D0 __asm__("D_004F9D64");
extern M2C_UNK D_004FDD60_16E7D0 __asm__("D_004FDD60");
extern M2C_UNK D_005015F0_16E7D0 __asm__("D_005015F0");
extern M2C_UNK func_0016E6D8_16E7D0 __asm__("func_0016E6D8");
extern M2C_UNK func_0016E6F8_16E7D0 __asm__("func_0016E6F8");

s32 func_0016E7D0(s32 arg0) {
    u8 sp[0x30];
    M2C_UNK sp30;
    s32 sp34;
    s32 sp38;
    s32 sp44;
    s32 temp_v0;
    s32 temp_v0_2;

    sp38 = 0;
    sp34 = 1;
    sp44 = 0;
    temp_v0 = CreateSema_16E7D0(&sp30);
    if (temp_v0 != -1) {
        ChangeThreadPriority_16E7D0(GetThreadId_16E7D0(), 2);
        temp_v0_2 = CreateThread_16E7D0(sp, &D_004FDD60_16E7D0, &D_005015F0_16E7D0, &D_005015F0_16E7D0, 1);
        if (temp_v0_2 != -1) {
            StartThread_16E7D0(temp_v0_2, temp_v0);
            func_00290D20_16E7D0(&func_0016E6D8_16E7D0, temp_v0);
            D_004F9D64_16E7D0 = arg0;
            return temp_v0;
        }
        DeleteSema_16E7D0(temp_v0);
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return -1;
    }
    return -1;
}
//@@ func_0016E7D0 m2c3
#include "m2c_macros.h"
M2C_UNK ChangeThreadPriority_16E7D0() __asm__("ChangeThreadPriority");
s32 CreateSema_16E7D0() __asm__("CreateSema");
s32 CreateThread_16E7D0() __asm__("CreateThread");
M2C_UNK DeleteSema_16E7D0() __asm__("DeleteSema");
s32 GetThreadId_16E7D0() __asm__("GetThreadId");
M2C_UNK StartThread_16E7D0() __asm__("StartThread");
M2C_UNK func_00290D20_16E7D0() __asm__("func_00290D20");
extern s32 D_004F9D64_16E7D0 __asm__("D_004F9D64");
extern M2C_UNK D_004FDD60_16E7D0 __asm__("D_004FDD60");
extern M2C_UNK D_005015F0_16E7D0 __asm__("D_005015F0");
extern M2C_UNK func_0016E6D8_16E7D0 __asm__("func_0016E6D8");
extern M2C_UNK func_0016E6F8_16E7D0 __asm__("func_0016E6F8");

s32 func_0016E7D0(s32 arg0) {
    u8 sp[0x20];
    M2C_UNK sp30;
    s32 sp34;
    s32 sp38;
    s32 sp44;
    s32 temp_v0;
    s32 temp_v0_2;

    sp38 = 0;
    sp34 = 1;
    sp44 = 0;
    temp_v0 = CreateSema_16E7D0(&sp30);
    if (temp_v0 != -1) {
        ChangeThreadPriority_16E7D0(GetThreadId_16E7D0(), 2);
        temp_v0_2 = CreateThread_16E7D0(sp, &D_004FDD60_16E7D0, &D_005015F0_16E7D0, &D_005015F0_16E7D0, 1);
        if (temp_v0_2 != -1) {
            StartThread_16E7D0(temp_v0_2, temp_v0);
            func_00290D20_16E7D0(&func_0016E6D8_16E7D0, temp_v0);
            D_004F9D64_16E7D0 = arg0;
            return temp_v0;
        }
        DeleteSema_16E7D0(temp_v0);
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return -1;
    }
    return -1;
}
//@@ func_0016E7D0 m2c4
#include "m2c_macros.h"
M2C_UNK ChangeThreadPriority_16E7D0() __asm__("ChangeThreadPriority");
s32 CreateSema_16E7D0() __asm__("CreateSema");
s32 CreateThread_16E7D0() __asm__("CreateThread");
M2C_UNK DeleteSema_16E7D0() __asm__("DeleteSema");
s32 GetThreadId_16E7D0() __asm__("GetThreadId");
M2C_UNK StartThread_16E7D0() __asm__("StartThread");
M2C_UNK func_00290D20_16E7D0() __asm__("func_00290D20");
extern s32 D_004F9D64_16E7D0 __asm__("D_004F9D64");
extern M2C_UNK D_004FDD60_16E7D0 __asm__("D_004FDD60");
extern M2C_UNK D_005015F0_16E7D0 __asm__("D_005015F0");
extern M2C_UNK func_0016E6D8_16E7D0 __asm__("func_0016E6D8");
extern M2C_UNK func_0016E6F8_16E7D0 __asm__("func_0016E6F8");

s32 func_0016E7D0(s32 arg0) {
    u8 sp[0x10];
    M2C_UNK sp30;
    s32 sp34;
    s32 sp38;
    s32 sp44;
    s32 temp_v0;
    s32 temp_v0_2;

    sp38 = 0;
    sp34 = 1;
    sp44 = 0;
    temp_v0 = CreateSema_16E7D0(&sp30);
    if (temp_v0 != -1) {
        ChangeThreadPriority_16E7D0(GetThreadId_16E7D0(), 2);
        temp_v0_2 = CreateThread_16E7D0(sp, &D_004FDD60_16E7D0, &D_005015F0_16E7D0, &D_005015F0_16E7D0, 1);
        if (temp_v0_2 != -1) {
            StartThread_16E7D0(temp_v0_2, temp_v0);
            func_00290D20_16E7D0(&func_0016E6D8_16E7D0, temp_v0);
            D_004F9D64_16E7D0 = arg0;
            return temp_v0;
        }
        DeleteSema_16E7D0(temp_v0);
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return -1;
    }
    return -1;
}
//@@ func_0016E7D0 m2c5
#include "m2c_macros.h"
M2C_UNK ChangeThreadPriority_16E7D0() __asm__("ChangeThreadPriority");
s32 CreateSema_16E7D0() __asm__("CreateSema");
s32 CreateThread_16E7D0() __asm__("CreateThread");
M2C_UNK DeleteSema_16E7D0() __asm__("DeleteSema");
s32 GetThreadId_16E7D0() __asm__("GetThreadId");
M2C_UNK StartThread_16E7D0() __asm__("StartThread");
M2C_UNK func_00290D20_16E7D0() __asm__("func_00290D20");
extern s32 D_004F9D64_16E7D0 __asm__("D_004F9D64");
extern M2C_UNK D_004FDD60_16E7D0 __asm__("D_004FDD60");
extern M2C_UNK D_005015F0_16E7D0 __asm__("D_005015F0");
extern M2C_UNK func_0016E6D8_16E7D0 __asm__("func_0016E6D8");
extern M2C_UNK func_0016E6F8_16E7D0 __asm__("func_0016E6F8");

s32 func_0016E7D0(s32 arg0) {
    u8 sp[0x8];
    M2C_UNK sp30;
    s32 sp34;
    s32 sp38;
    s32 sp44;
    s32 temp_v0;
    s32 temp_v0_2;

    sp38 = 0;
    sp34 = 1;
    sp44 = 0;
    temp_v0 = CreateSema_16E7D0(&sp30);
    if (temp_v0 != -1) {
        ChangeThreadPriority_16E7D0(GetThreadId_16E7D0(), 2);
        temp_v0_2 = CreateThread_16E7D0(sp, &D_004FDD60_16E7D0, &D_005015F0_16E7D0, &D_005015F0_16E7D0, 1);
        if (temp_v0_2 != -1) {
            StartThread_16E7D0(temp_v0_2, temp_v0);
            func_00290D20_16E7D0(&func_0016E6D8_16E7D0, temp_v0);
            D_004F9D64_16E7D0 = arg0;
            return temp_v0;
        }
        DeleteSema_16E7D0(temp_v0);
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return -1;
    }
    return -1;
}
//@@ func_0016E8B8 m2c0
#include "m2c_macros.h"
M2C_UNK func_0016E8E0_16E8B8() __asm__("func_0016E8E0");

s32 func_0016E8B8(s32 arg0) {
    func_0016E8E0_16E8B8();
    return arg0;
}
//@@ func_0016E8E0 m2c0
#include "m2c_macros.h"
M2C_UNK strcpy_16E8E0() __asm__("strcpy");
extern M2C_UNK D_004F9DA8_16E8E0 __asm__("D_004F9DA8");
extern M2C_UNK D_004F9DB0_16E8E0 __asm__("D_004F9DB0");

void func_0016E8E0(void* arg0) {
    M2C_FIELD(arg0, s32* , 0) = -1;
    M2C_FIELD(arg0, s32* , 4) = -1;
    strcpy_16E8E0(arg0 + 8, &D_004F9DA8_16E8E0);
    strcpy_16E8E0(arg0 + 0x48, &D_004F9DB0_16E8E0);
    M2C_FIELD(arg0, f32* , 0xC0) = 10000.0f;
    M2C_FIELD(arg0, s32* , 0xBC) = 0x2710;
    strcpy_16E8E0(arg0 + 0xC4, "10.0.0.82");
    M2C_FIELD(arg0, s32* , 0xA4) = -1;
    M2C_FIELD(arg0, s32* , 0xAC) = 1;
    M2C_FIELD(arg0, f32* , 0x98) = 1.0f;
    M2C_FIELD(arg0, s32* , 0xB8) = 0;
    M2C_FIELD(arg0, s32* , 0xA8) = 0;
    M2C_FIELD(arg0, s32* , 0xA0) = 0;
    M2C_FIELD(arg0, s32* , 0xB0) = 0;
    M2C_FIELD(arg0, s32* , 0xB4) = 0;
    M2C_FIELD(arg0, f32* , 0x90) = 1.0f;
    M2C_FIELD(arg0, f32* , 0x94) = 1.0f;
    M2C_FIELD(arg0, s32* , 0x204) = 0;
    M2C_FIELD(arg0, s32* , 0x208) = 0;
    M2C_FIELD(arg0, s32* , 0x20C) = 0;
    M2C_FIELD(arg0, s32* , 0x210) = 0;
}
//@@ func_0016E9A0 m2c0
#include "m2c_macros.h"
M2C_UNK strcpy_16E9A0() __asm__("strcpy");
extern M2C_UNK D_004F9DB0_16E9A0 __asm__("D_004F9DB0");

void* func_0016E9A0(void* arg0) {
    strcpy_16E9A0("Default Team\0BASCUS-97196\0 !\"#$%&'()*+,-.0123456789:;<=>?ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_abcdefghijklmnopqrstuvwxyz{}\0\00123456789\0\0 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\0 .0123456789");
    strcpy_16E9A0(arg0 + 0x40, &D_004F9DB0_16E9A0);
    M2C_FIELD(arg0, s32* , 0x80) = -1;
    return arg0;
}
//@@ func_0016EB70 m2c0
#include "m2c_macros.h"
void func_0016EB70(void* arg0) {
    M2C_FIELD(arg0, s32* , 0x768) = 0;
}
//@@ func_0016EB78 m2c0
#include "m2c_macros.h"
M2C_UNK func_0026B998_16EB78() __asm__("func_0026B998");
M2C_UNK func_0026DFF8_16EB78() __asm__("func_0026DFF8");
s32 timerGetFieldCount__Fv_16EB78() __asm__("timerGetFieldCount__Fv");
extern M2C_UNK D_003156C0_16EB78 __asm__("D_003156C0");
extern s32 D_004F9DD8_16EB78 __asm__("D_004F9DD8");
extern M2C_UNK func_00169050_16EB78 __asm__("func_00169050");

void func_0016EB78(void) {
    s32 temp_v0;
    s32 var_s0;
    void* var_s1;

    temp_v0 = timerGetFieldCount__Fv_16EB78();
    if ((temp_v0 - D_004F9DD8_16EB78) >= 0x259) {
        var_s0 = 0;
        if (M2C_FIELD(&D_003156C0_16EB78, s32* , 0x1980) > 0) {
            var_s1 = &D_003156C0_16EB78 + 0x1560;
            do {
                func_0026B998_16EB78(var_s1, &func_00169050_16EB78);
                var_s0 += 1;
                func_0026DFF8_16EB78();
                var_s1 += 0x5C;
            } while (var_s0 < M2C_FIELD(&D_003156C0_16EB78, s32* , 0x1980));
        }
        D_004F9DD8_16EB78 = temp_v0;
    }
}
//@@ func_0016EC18 m2c0
#include "m2c_macros.h"
M2C_UNK func_002693D8_16EC18() __asm__("func_002693D8");
extern s32 D_00319924_16EC18 __asm__("D_00319924");
extern M2C_UNK func_00168F30_16EC18 __asm__("func_00168F30");

void func_0016EC18(void) {
    if (D_00319924_16EC18 == 0) {
        func_002693D8_16EC18(&func_00168F30_16EC18);
    }
}
//@@ func_0016EC50 m2c0
#include "m2c_macros.h"
M2C_UNK func_001192E8_16EC50() __asm__("func_001192E8");
M2C_UNK func_0016E8B8_16EC50() __asm__("func_0016E8B8");
M2C_UNK func_0016E9A0_16EC50() __asm__("func_0016E9A0");
M2C_UNK func_0016E9E8_16EC50() __asm__("func_0016E9E8");
M2C_UNK func_001746E8_16EC50() __asm__("func_001746E8");
M2C_UNK func_00174860_16EC50() __asm__("func_00174860");
M2C_UNK func_0017F848_16EC50() __asm__("func_0017F848");
M2C_UNK memset_16EC50() __asm__("memset");

void* func_0016EC50(void* arg0) {
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s0_4;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s2_3;
    s32 var_s2_4;

    var_s2 = 7;
    var_s0 = arg0 + 0x10;
    do {
        var_s2 -= 1;
        func_0016E8B8_16EC50(var_s0);
        var_s0 += 0x220;
    } while (var_s2 != -1);
    var_s0_2 = arg0 + 0x1110;
    var_s2_2 = 1;
    do {
        var_s2_2 -= 1;
        func_0016E9A0_16EC50(var_s0_2);
        var_s0_2 += 0x84;
    } while (var_s2_2 != -1);
    var_s0_3 = arg0 + 0x3244;
    func_0016E9E8_16EC50(arg0 + 0x1218);
    var_s2_3 = 0xB;
    func_0016E8B8_16EC50(arg0 + 0x1990);
    do {
        var_s2_3 -= 1;
        func_0017F848_16EC50(var_s0_3);
        var_s0_3 += 0x7C;
    } while (var_s2_3 != -1);
    var_s0_4 = arg0 + 0x387C;
    var_s2_4 = 0x13;
    do {
        var_s2_4 -= 1;
        func_001192E8_16EC50(var_s0_4);
        var_s0_4 += 0x7C;
    } while (var_s2_4 != -1);
    M2C_FIELD(arg0, s32* , 0) = 3;
    memset_16EC50(arg0 + 0x3080, 0, 0xC8);
    M2C_FIELD(arg0, s64* , 0x3080) = (s64) ((((((M2C_FIELD(arg0, s64* , 0x3080) & ~0x1E) | 4) & ~0x20 & ~0x3C0) | 0x40) & ~0xC00) | 0x800);
    M2C_FIELD(arg0, s8* , 0x3084) = 8;
    M2C_FIELD(arg0, s32* , 0x2E90) = 0;
    M2C_FIELD(arg0, s32* , 0x4258) = 0;
    M2C_FIELD(arg0, s32* , 0x425C) = 0;
    M2C_FIELD(arg0, s32* , 0x4260) = 0;
    M2C_FIELD(arg0, s32* , 0x4278) = 0;
    M2C_FIELD(arg0, s32* , 0x427C) = 0;
    M2C_FIELD(arg0, s32* , 0x4280) = 0;
    M2C_FIELD(arg0, s32* , 0x4284) = 0;
    M2C_FIELD(arg0, s32* , 0x4288) = 0;
    M2C_FIELD(arg0, s32* , 0x4270) = 0;
    M2C_FIELD(arg0, s32* , 0x4274) = 0;
    M2C_FIELD(arg0, s8* , 0x309B) = -1;
    M2C_FIELD(arg0, s64* , 0x3080) = (s64) ((M2C_FIELD(arg0, s64* , 0x3080) & 0xFFC0FFFF) | 0x230000);
    M2C_FIELD(arg0, s32* , 0x1BB4) = -1;
    M2C_FIELD(arg0, s32* , 0x2DFC) = 8;
    M2C_FIELD(arg0, s32* , 0x1A34) = 0x20;
    M2C_FIELD(arg0, s8* , 0x309A) = -1;
    M2C_FIELD(arg0, s32* , 0x2DF8) = 8;
    func_001746E8_16EC50(arg0, -1, 0x20, 0xFFC0FFFF);
    func_00174860_16EC50(arg0);
    return arg0;
}
//@@ func_0016EE60 m2c0
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
//@@ func_0016EF88 m2c0
#include "m2c_macros.h"
s32 func_0016EF88(s32 arg0) {
    return arg0 + 0x1218;
}
//@@ func_0016EF90 m2c0
#include "m2c_macros.h"
M2C_UNK strcpy_16EF90() __asm__("strcpy");
extern M2C_UNK D_004F9E38_16EF90 __asm__("D_004F9E38");

void func_0016EF90(s32 arg0, s32 arg1) {
    void* temp_v1;
    void* temp_v1_2;

    temp_v1 = (arg1 * 0x220) + arg0;
    M2C_FIELD(temp_v1, s32* , 0x10) = -1;
    M2C_FIELD(temp_v1, s32* , 0x14) = -1;
    strcpy_16EF90((arg1 * 0x220) + arg0 + 0x18, &D_004F9E38_16EF90, temp_v1);
    strcpy_16EF90((arg1 * 0x220) + arg0 + 0x58, &D_004F9E38_16EF90);
    temp_v1_2 = (arg1 * 0x220) + arg0;
    M2C_FIELD(temp_v1_2, s32* , 0xCC) = 0x2710;
    M2C_FIELD(temp_v1_2, f32* , 0xD0) = 10000.0f;
    strcpy_16EF90(temp_v1_2 + 0xD4, &D_004F9E38_16EF90, temp_v1_2);
    M2C_FIELD(((arg1 * 0x220) + arg0), s32* , 0x214) = 0;
}
//@@ func_0016F058 m2c0
#include "m2c_macros.h"
M2C_UNK AddMessage__3Hudiii_16F058() __asm__("AddMessage__3Hudiii");
M2C_UNK func_0014ECE8_16F058() __asm__("func_0014ECE8");
M2C_UNK func_0014ED08_16F058() __asm__("func_0014ED08");
M2C_UNK func_0014EDA0_16F058() __asm__("func_0014EDA0");
M2C_UNK func_001A9208_16F058() __asm__("func_001A9208");
M2C_UNK func_00264448_16F058() __asm__("func_00264448");
M2C_UNK func_00267080_16F058() __asm__("func_00267080");
M2C_UNK memset_16F058() __asm__("memset");
M2C_UNK printf_16F058() __asm__("printf");
M2C_UNK sprintf_16F058() __asm__("sprintf");
extern void* D_003156C4_16F058 __asm__("D_003156C4");
extern u8 D_004E79B8_16F058 __asm__("D_004E79B8");
extern M2C_UNK D_004E79C0_16F058 __asm__("D_004E79C0");
extern s32 D_004FA030_16F058 __asm__("D_004FA030");

s32 func_0016F058(void* arg0, s32 arg1, M2C_UNK arg2) {
    u8 sp[0x180];
    M2C_UNK sp1;
    M2C_UNK sp100;
    s32* temp_s2;
    void* temp_s1;

    memset_16F058(&sp1, 0, 0xFF);
    func_00267080_16F058(sp);
    printf_16F058(&D_004E79C0_16F058);
    temp_s2 = M2C_FIELD(arg0, s32** , 4);
    func_00264448_16F058();
    printf_16F058("Network: Remote Client (%d) has Joined Game %d (my client ID = %d) DME >>%s<< DME TIME >>%s<<\n", arg1, arg2, *temp_s2);
    printf_16F058(&D_004E79C0_16F058);
    M2C_FIELD(((arg1 * 0x220) + arg0), s32* , 0x10) = arg1;
    temp_s1 = arg0 + ((arg1 * 0x220) + 0x10) + 8;
    func_0014ECE8_16F058(arg1, temp_s1);
    func_0014ED08_16F058(arg1, temp_s1);
    if (M2C_FIELD(arg0, s32* , 0x1BB4) == 0xB) {
        func_001A9208_16F058();
        sprintf_16F058(&sp100, "%s is joining the game.", temp_s1);
        func_0014EDA0_16F058(&sp100);
        AddMessage__3Hudiii_16F058(D_004FA030_16F058 + ((M2C_FIELD(M2C_FIELD(D_003156C4_16F058, void** , 0xA0), s32* , 0x210C) * 0xA20) + 0x97B50), 0xF9, 2, 0);
    }
    return arg1;
}
//@@ func_0016F058 m2c1
#include "m2c_macros.h"
M2C_UNK AddMessage__3Hudiii_16F058() __asm__("AddMessage__3Hudiii");
M2C_UNK func_0014ECE8_16F058() __asm__("func_0014ECE8");
M2C_UNK func_0014ED08_16F058() __asm__("func_0014ED08");
M2C_UNK func_0014EDA0_16F058() __asm__("func_0014EDA0");
M2C_UNK func_001A9208_16F058() __asm__("func_001A9208");
M2C_UNK func_00264448_16F058() __asm__("func_00264448");
M2C_UNK func_00267080_16F058() __asm__("func_00267080");
M2C_UNK memset_16F058() __asm__("memset");
M2C_UNK printf_16F058() __asm__("printf");
M2C_UNK sprintf_16F058() __asm__("sprintf");
extern void* D_003156C4_16F058 __asm__("D_003156C4");
extern u8 D_004E79B8_16F058 __asm__("D_004E79B8");
extern M2C_UNK D_004E79C0_16F058 __asm__("D_004E79C0");
extern s32 D_004FA030_16F058 __asm__("D_004FA030");

s32 func_0016F058(void* arg0, s32 arg1, M2C_UNK arg2) {
    u8 sp[0x170];
    M2C_UNK sp1;
    M2C_UNK sp100;
    s32* temp_s2;
    void* temp_s1;

    memset_16F058(&sp1, 0, 0xFF);
    func_00267080_16F058(sp);
    printf_16F058(&D_004E79C0_16F058);
    temp_s2 = M2C_FIELD(arg0, s32** , 4);
    func_00264448_16F058();
    printf_16F058("Network: Remote Client (%d) has Joined Game %d (my client ID = %d) DME >>%s<< DME TIME >>%s<<\n", arg1, arg2, *temp_s2);
    printf_16F058(&D_004E79C0_16F058);
    M2C_FIELD(((arg1 * 0x220) + arg0), s32* , 0x10) = arg1;
    temp_s1 = arg0 + ((arg1 * 0x220) + 0x10) + 8;
    func_0014ECE8_16F058(arg1, temp_s1);
    func_0014ED08_16F058(arg1, temp_s1);
    if (M2C_FIELD(arg0, s32* , 0x1BB4) == 0xB) {
        func_001A9208_16F058();
        sprintf_16F058(&sp100, "%s is joining the game.", temp_s1);
        func_0014EDA0_16F058(&sp100);
        AddMessage__3Hudiii_16F058(D_004FA030_16F058 + ((M2C_FIELD(M2C_FIELD(D_003156C4_16F058, void** , 0xA0), s32* , 0x210C) * 0xA20) + 0x97B50), 0xF9, 2, 0);
    }
    return arg1;
}
//@@ func_0016F058 m2c2
#include "m2c_macros.h"
M2C_UNK AddMessage__3Hudiii_16F058() __asm__("AddMessage__3Hudiii");
M2C_UNK func_0014ECE8_16F058() __asm__("func_0014ECE8");
M2C_UNK func_0014ED08_16F058() __asm__("func_0014ED08");
M2C_UNK func_0014EDA0_16F058() __asm__("func_0014EDA0");
M2C_UNK func_001A9208_16F058() __asm__("func_001A9208");
M2C_UNK func_00264448_16F058() __asm__("func_00264448");
M2C_UNK func_00267080_16F058() __asm__("func_00267080");
M2C_UNK memset_16F058() __asm__("memset");
M2C_UNK printf_16F058() __asm__("printf");
M2C_UNK sprintf_16F058() __asm__("sprintf");
extern void* D_003156C4_16F058 __asm__("D_003156C4");
extern u8 D_004E79B8_16F058 __asm__("D_004E79B8");
extern M2C_UNK D_004E79C0_16F058 __asm__("D_004E79C0");
extern s32 D_004FA030_16F058 __asm__("D_004FA030");

s32 func_0016F058(void* arg0, s32 arg1, M2C_UNK arg2) {
    u8 sp[0x160];
    M2C_UNK sp1;
    M2C_UNK sp100;
    s32* temp_s2;
    void* temp_s1;

    memset_16F058(&sp1, 0, 0xFF);
    func_00267080_16F058(sp);
    printf_16F058(&D_004E79C0_16F058);
    temp_s2 = M2C_FIELD(arg0, s32** , 4);
    func_00264448_16F058();
    printf_16F058("Network: Remote Client (%d) has Joined Game %d (my client ID = %d) DME >>%s<< DME TIME >>%s<<\n", arg1, arg2, *temp_s2);
    printf_16F058(&D_004E79C0_16F058);
    M2C_FIELD(((arg1 * 0x220) + arg0), s32* , 0x10) = arg1;
    temp_s1 = arg0 + ((arg1 * 0x220) + 0x10) + 8;
    func_0014ECE8_16F058(arg1, temp_s1);
    func_0014ED08_16F058(arg1, temp_s1);
    if (M2C_FIELD(arg0, s32* , 0x1BB4) == 0xB) {
        func_001A9208_16F058();
        sprintf_16F058(&sp100, "%s is joining the game.", temp_s1);
        func_0014EDA0_16F058(&sp100);
        AddMessage__3Hudiii_16F058(D_004FA030_16F058 + ((M2C_FIELD(M2C_FIELD(D_003156C4_16F058, void** , 0xA0), s32* , 0x210C) * 0xA20) + 0x97B50), 0xF9, 2, 0);
    }
    return arg1;
}
//@@ func_0016F058 m2c3
#include "m2c_macros.h"
M2C_UNK AddMessage__3Hudiii_16F058() __asm__("AddMessage__3Hudiii");
M2C_UNK func_0014ECE8_16F058() __asm__("func_0014ECE8");
M2C_UNK func_0014ED08_16F058() __asm__("func_0014ED08");
M2C_UNK func_0014EDA0_16F058() __asm__("func_0014EDA0");
M2C_UNK func_001A9208_16F058() __asm__("func_001A9208");
M2C_UNK func_00264448_16F058() __asm__("func_00264448");
M2C_UNK func_00267080_16F058() __asm__("func_00267080");
M2C_UNK memset_16F058() __asm__("memset");
M2C_UNK printf_16F058() __asm__("printf");
M2C_UNK sprintf_16F058() __asm__("sprintf");
extern void* D_003156C4_16F058 __asm__("D_003156C4");
extern u8 D_004E79B8_16F058 __asm__("D_004E79B8");
extern M2C_UNK D_004E79C0_16F058 __asm__("D_004E79C0");
extern s32 D_004FA030_16F058 __asm__("D_004FA030");

s32 func_0016F058(void* arg0, s32 arg1, M2C_UNK arg2) {
    u8 sp[0x150];
    M2C_UNK sp1;
    M2C_UNK sp100;
    s32* temp_s2;
    void* temp_s1;

    memset_16F058(&sp1, 0, 0xFF);
    func_00267080_16F058(sp);
    printf_16F058(&D_004E79C0_16F058);
    temp_s2 = M2C_FIELD(arg0, s32** , 4);
    func_00264448_16F058();
    printf_16F058("Network: Remote Client (%d) has Joined Game %d (my client ID = %d) DME >>%s<< DME TIME >>%s<<\n", arg1, arg2, *temp_s2);
    printf_16F058(&D_004E79C0_16F058);
    M2C_FIELD(((arg1 * 0x220) + arg0), s32* , 0x10) = arg1;
    temp_s1 = arg0 + ((arg1 * 0x220) + 0x10) + 8;
    func_0014ECE8_16F058(arg1, temp_s1);
    func_0014ED08_16F058(arg1, temp_s1);
    if (M2C_FIELD(arg0, s32* , 0x1BB4) == 0xB) {
        func_001A9208_16F058();
        sprintf_16F058(&sp100, "%s is joining the game.", temp_s1);
        func_0014EDA0_16F058(&sp100);
        AddMessage__3Hudiii_16F058(D_004FA030_16F058 + ((M2C_FIELD(M2C_FIELD(D_003156C4_16F058, void** , 0xA0), s32* , 0x210C) * 0xA20) + 0x97B50), 0xF9, 2, 0);
    }
    return arg1;
}
//@@ func_0016F058 m2c4
#include "m2c_macros.h"
M2C_UNK AddMessage__3Hudiii_16F058() __asm__("AddMessage__3Hudiii");
M2C_UNK func_0014ECE8_16F058() __asm__("func_0014ECE8");
M2C_UNK func_0014ED08_16F058() __asm__("func_0014ED08");
M2C_UNK func_0014EDA0_16F058() __asm__("func_0014EDA0");
M2C_UNK func_001A9208_16F058() __asm__("func_001A9208");
M2C_UNK func_00264448_16F058() __asm__("func_00264448");
M2C_UNK func_00267080_16F058() __asm__("func_00267080");
M2C_UNK memset_16F058() __asm__("memset");
M2C_UNK printf_16F058() __asm__("printf");
M2C_UNK sprintf_16F058() __asm__("sprintf");
extern void* D_003156C4_16F058 __asm__("D_003156C4");
extern u8 D_004E79B8_16F058 __asm__("D_004E79B8");
extern M2C_UNK D_004E79C0_16F058 __asm__("D_004E79C0");
extern s32 D_004FA030_16F058 __asm__("D_004FA030");

s32 func_0016F058(void* arg0, s32 arg1, M2C_UNK arg2) {
    u8 sp[0x140];
    M2C_UNK sp1;
    M2C_UNK sp100;
    s32* temp_s2;
    void* temp_s1;

    memset_16F058(&sp1, 0, 0xFF);
    func_00267080_16F058(sp);
    printf_16F058(&D_004E79C0_16F058);
    temp_s2 = M2C_FIELD(arg0, s32** , 4);
    func_00264448_16F058();
    printf_16F058("Network: Remote Client (%d) has Joined Game %d (my client ID = %d) DME >>%s<< DME TIME >>%s<<\n", arg1, arg2, *temp_s2);
    printf_16F058(&D_004E79C0_16F058);
    M2C_FIELD(((arg1 * 0x220) + arg0), s32* , 0x10) = arg1;
    temp_s1 = arg0 + ((arg1 * 0x220) + 0x10) + 8;
    func_0014ECE8_16F058(arg1, temp_s1);
    func_0014ED08_16F058(arg1, temp_s1);
    if (M2C_FIELD(arg0, s32* , 0x1BB4) == 0xB) {
        func_001A9208_16F058();
        sprintf_16F058(&sp100, "%s is joining the game.", temp_s1);
        func_0014EDA0_16F058(&sp100);
        AddMessage__3Hudiii_16F058(D_004FA030_16F058 + ((M2C_FIELD(M2C_FIELD(D_003156C4_16F058, void** , 0xA0), s32* , 0x210C) * 0xA20) + 0x97B50), 0xF9, 2, 0);
    }
    return arg1;
}
//@@ func_0016F058 m2c5
#include "m2c_macros.h"
M2C_UNK AddMessage__3Hudiii_16F058() __asm__("AddMessage__3Hudiii");
M2C_UNK func_0014ECE8_16F058() __asm__("func_0014ECE8");
M2C_UNK func_0014ED08_16F058() __asm__("func_0014ED08");
M2C_UNK func_0014EDA0_16F058() __asm__("func_0014EDA0");
M2C_UNK func_001A9208_16F058() __asm__("func_001A9208");
M2C_UNK func_00264448_16F058() __asm__("func_00264448");
M2C_UNK func_00267080_16F058() __asm__("func_00267080");
M2C_UNK memset_16F058() __asm__("memset");
M2C_UNK printf_16F058() __asm__("printf");
M2C_UNK sprintf_16F058() __asm__("sprintf");
extern void* D_003156C4_16F058 __asm__("D_003156C4");
extern u8 D_004E79B8_16F058 __asm__("D_004E79B8");
extern M2C_UNK D_004E79C0_16F058 __asm__("D_004E79C0");
extern s32 D_004FA030_16F058 __asm__("D_004FA030");

s32 func_0016F058(void* arg0, s32 arg1, M2C_UNK arg2) {
    u8 sp[0x130];
    M2C_UNK sp1;
    M2C_UNK sp100;
    s32* temp_s2;
    void* temp_s1;

    memset_16F058(&sp1, 0, 0xFF);
    func_00267080_16F058(sp);
    printf_16F058(&D_004E79C0_16F058);
    temp_s2 = M2C_FIELD(arg0, s32** , 4);
    func_00264448_16F058();
    printf_16F058("Network: Remote Client (%d) has Joined Game %d (my client ID = %d) DME >>%s<< DME TIME >>%s<<\n", arg1, arg2, *temp_s2);
    printf_16F058(&D_004E79C0_16F058);
    M2C_FIELD(((arg1 * 0x220) + arg0), s32* , 0x10) = arg1;
    temp_s1 = arg0 + ((arg1 * 0x220) + 0x10) + 8;
    func_0014ECE8_16F058(arg1, temp_s1);
    func_0014ED08_16F058(arg1, temp_s1);
    if (M2C_FIELD(arg0, s32* , 0x1BB4) == 0xB) {
        func_001A9208_16F058();
        sprintf_16F058(&sp100, "%s is joining the game.", temp_s1);
        func_0014EDA0_16F058(&sp100);
        AddMessage__3Hudiii_16F058(D_004FA030_16F058 + ((M2C_FIELD(M2C_FIELD(D_003156C4_16F058, void** , 0xA0), s32* , 0x210C) * 0xA20) + 0x97B50), 0xF9, 2, 0);
    }
    return arg1;
}
//@@ func_0016F1C8 m2c0
#include "m2c_macros.h"
M2C_UNK func_0010BDC0_16F1C8() __asm__("func_0010BDC0");
M2C_UNK func_00128F48_16F1C8() __asm__("func_00128F48");
s32 func_00174268_16F1C8() __asm__("func_00174268");
s8 func_00176B10_16F1C8() __asm__("func_00176B10");
M2C_UNK func_00176EA0_16F1C8() __asm__("func_00176EA0");
M2C_UNK func_001940E0_16F1C8() __asm__("func_001940E0");
M2C_UNK func_001DC130_16F1C8() __asm__("func_001DC130");
M2C_UNK func_001EFF98_16F1C8() __asm__("func_001EFF98");
M2C_UNK func_001FDE10_16F1C8() __asm__("func_001FDE10");
M2C_UNK printf_16F1C8() __asm__("printf");
M2C_UNK vehicleDisable__7Vehicle_16F1C8() __asm__("vehicleDisable__7Vehicle");
extern M2C_UNK D_003156C0_16F1C8 __asm__("D_003156C0");
extern M2C_UNK D_004E79C0_16F1C8 __asm__("D_004E79C0");
extern s32 D_004FA030_16F1C8 __asm__("D_004FA030");

s32 func_0016F1C8(s32 arg0, s32 arg1) {
    s32 temp_a2;
    s32 temp_s1;
    s32 var_s1;
    s32 var_s2;
    s32 var_s5;
    s32* temp_v0_2;
    u32 temp_v1;
    void* temp_s0;
    void* temp_v0;
    void* temp_v0_3;

    temp_s1 = arg1 * 0x220;
    temp_s0 = M2C_FIELD((temp_s1 + &D_003156C0_16F1C8), void** , 0xB0);
    printf_16F1C8(&D_004E79C0_16F1C8);
    temp_a2 = temp_s1 + 0x10;
    if (arg1 >= 0) {
        printf_16F1C8("Network: Remote Client (%d) %s, Leaves Game\n", arg1, arg0 + temp_a2 + 8);
    } else {
        printf_16F1C8("Network: Remote Client (%d) Leaves Game\n", arg1, temp_a2);
    }
    printf_16F1C8("Network: Cleaning up Client Car and Client Object.\n");
    printf_16F1C8(&D_004E79C0_16F1C8);
    if (temp_s0 != NULL) {
        printf_16F1C8("  car name           = %d\n", M2C_FIELD(temp_s0, s32* , 0x20F4));
        printf_16F1C8("  car netPlayerType  = %d\n", M2C_FIELD(temp_s0, s32* , 0x20B4));
        var_s1 = 0x6C3C0;
        var_s2 = 0;
        printf_16F1C8("  car typeOfVehicle  = %d\n", M2C_FIELD(temp_s0, s32* , 0x590));
        var_s5 = 0xC7;
        printf_16F1C8("Remove Player Turning OFF the visual for car %d\n", M2C_FIELD(temp_s0, s32* , 0x20F4));
        func_0010BDC0_16F1C8(D_004FA030_16F1C8 + 0x30970, M2C_FIELD(temp_s0, s32* , 0x214C));
        func_001940E0_16F1C8(temp_s0 + 0x2F54);
        M2C_FIELD(temp_s0, s8* , 0x2155) = 0;
        M2C_FIELD(temp_s0, s8* , 0x2154) = 0;
        M2C_FIELD(temp_s0, s16* , 0x2156) = 0;
        func_001FDE10_16F1C8(0, func_00174268_16F1C8(&D_003156C0_16F1C8, arg1));
        func_001DC130_16F1C8(temp_s0);
        M2C_FIELD(temp_s0, s32* , 0x215C) = 0;
        M2C_FIELD(M2C_FIELD(temp_s0, void** , 0x2028), s8* , 0xD) = 0;
        M2C_FIELD(M2C_FIELD(temp_s0, void** , 0x2034), s8* , 0xC) = 0;
        do {
            temp_v0 = D_004FA030_16F1C8 + var_s2;
            if ((M2C_FIELD(temp_v0, s32* , 0x6C3C0) != 0) && (M2C_FIELD(temp_v0, s32* , 0x6C4F0) == temp_s0)) {
                func_001EFF98_16F1C8(D_004FA030_16F1C8 + var_s1);
                M2C_FIELD((D_004FA030_16F1C8 + var_s2), s32* , 0x6C3C0) = 0;
            }
            var_s1 += 0x210;
            var_s5 -= 1;
            var_s2 += 0x210;
        } while (var_s5 >= 0);
        temp_v1 = M2C_FIELD(temp_s0, u32* , 0x31A4);
        if (temp_v1 < 5U) {
            func_00128F48_16F1C8(D_004FA030_16F1C8 + ((temp_v1 * 0xB30) + 0x9A3E0));
            M2C_FIELD(temp_s0, u32* , 0x31A4) = -1U;
        }
        temp_v0_2 = M2C_FIELD(temp_s0, s32** , 0x20D0);
        if (temp_v0_2 != NULL) {
            *temp_v0_2 = 0;
            M2C_FIELD(temp_s0, s32** , 0x20D0) = NULL;
        }
        temp_v0_3 = M2C_FIELD(temp_s0, void** , 0x20D4);
        M2C_FIELD(temp_s0, s32* , 0x20C4) = -1;
        if (temp_v0_3 != NULL) {
            M2C_FIELD(temp_v0_3, s32* , 0xC) = 0;
            M2C_FIELD(temp_s0, void** , 0x20D4) = NULL;
        }
        M2C_FIELD(temp_s0, s32* , 0x20D8) = 0;
        M2C_FIELD(temp_s0, s32* , 0x20C0) = -1;
        M2C_FIELD(temp_s0, s32* , 0x20C8) = -1;
        M2C_FIELD(temp_s0, s32* , 0x20CC) = -1;
        vehicleDisable__7Vehicle_16F1C8(temp_s0);
    }
    M2C_FIELD(((arg1 * 0x220) + arg0), s32* , 0xB0) = 0;
    printf_16F1C8("JUST Cleaned Up mPlayers[%d]\n", arg1);
    M2C_FIELD(M2C_FIELD(&D_003156C0_16F1C8, void** , 0x3148), s8* , 0x24) = func_00176B10_16F1C8(&D_003156C0_16F1C8, 0);
    func_00176EA0_16F1C8(arg0);
    return arg1;
}
//@@ func_0016F478 m2c0
#include "m2c_macros.h"
s32 func_0016F478(s32 arg0, s32 arg1) {
    return arg1;
}
//@@ func_0016F480 m2c0
#include "m2c_macros.h"
s32 func_0016F480(s32 arg0, s32 arg1) {
    return arg1;
}
//@@ func_0016F718 m2c0
#include "m2c_macros.h"
s32 func_0016F910_16F718() __asm__("func_0016F910");
M2C_UNK func_001703E8_16F718() __asm__("func_001703E8");
M2C_UNK func_00266478_16F718() __asm__("func_00266478");
M2C_UNK func_00266D78_16F718() __asm__("func_00266D78");
s32 func_002697C0_16F718() __asm__("func_002697C0");
M2C_UNK func_0026A4F8_16F718() __asm__("func_0026A4F8");
s32 func_0026A550_16F718() __asm__("func_0026A550");
M2C_UNK func_0026E2D8_16F718() __asm__("func_0026E2D8");
s32 netGetMyClientIndex_16F718() __asm__("netGetMyClientIndex");
M2C_UNK printf_16F718() __asm__("printf");
extern M2C_UNK D_004E7BC8_16F718 __asm__("D_004E7BC8");
extern M2C_UNK D_004E7D38_16F718 __asm__("D_004E7D38");
extern M2C_UNK D_004E7DE0_16F718 __asm__("D_004E7DE0");
extern M2C_UNK D_004E7E08_16F718 __asm__("D_004E7E08");
extern M2C_UNK D_004E7E30_16F718 __asm__("D_004E7E30");
extern M2C_UNK D_004E7E58_16F718 __asm__("D_004E7E58");
extern M2C_UNK D_004E7E70_16F718 __asm__("D_004E7E70");
extern M2C_UNK D_004E7EA0_16F718 __asm__("D_004E7EA0");
extern M2C_UNK D_004E7ED0_16F718 __asm__("D_004E7ED0");
extern s32 D_004F9EB0_16F718 __asm__("D_004F9EB0");
extern s32 D_004F9EB4_16F718 __asm__("D_004F9EB4");
extern M2C_UNK D_004F9EB8_16F718 __asm__("D_004F9EB8");
extern M2C_UNK func_00168B60_16F718 __asm__("func_00168B60");
extern M2C_UNK func_00168C30_16F718 __asm__("func_00168C30");
extern M2C_UNK func_0016C480_16F718 __asm__("func_0016C480");
extern M2C_UNK func_0016C590_16F718 __asm__("func_0016C590");

s32 func_0016F718(void* arg0, s32 arg1) {
    u8 sp[0x40];
    M2C_UNK sp20;
    M2C_UNK sp30;
    s32 temp_s2;
    s32 var_s2;

    temp_s2 = arg0 + 0x1258;
    func_00266478_16F718(&func_0016C590_16F718);
    D_004F9EB4_16F718 = 2;
    D_004F9EB0_16F718 = 0;
    func_00266D78_16F718(&D_004F9EB8_16F718);
    printf_16F718(&D_004E7BC8_16F718);
    printf_16F718("NETWORK: Attempting to connect to Peer 2 Peer Server:\n");
    printf_16F718(&D_004E7DE0_16F718, temp_s2);
    printf_16F718(&D_004E7E08_16F718, M2C_FIELD(arg0, s32* , 0x1298));
    printf_16F718(&D_004E7E30_16F718, M2C_FIELD(arg0, s32* , 0x129C));
    if (arg1 != 0) {
        func_0026A4F8_16F718(sp);
        var_s2 = func_0026A550_16F718(sp, &sp20, &func_00168C30_16F718, M2C_FIELD(arg0, s32* , 0x2DFC));
        printf_16F718(&D_004E7E58_16F718, var_s2);
        M2C_FIELD(arg0, s32* , 0x2CF0) = sp28;
loop_4:
        if (func_0016F910_16F718(arg0, &sp30) == 2) {
            func_001703E8_16F718(arg0);
            goto loop_4;
        }
        M2C_FIELD(arg0, s32* , 0x307C) = netGetMyClientIndex_16F718(arg0);
        printf_16F718(&D_004E7E70_16F718);
        printf_16F718(&D_004E7EA0_16F718, M2C_FIELD(arg0, s32* , 0x307C));
        printf_16F718(&D_004E7E70_16F718);
    } else {
        var_s2 = func_002697C0_16F718(arg0 + 0x2CF0, 0, temp_s2, &func_0016C480_16F718);
    }
    if (var_s2 != 0) {
        D_004F9EB0_16F718 = 1;
        func_0026E2D8_16F718(M2C_FIELD(arg0, s32* , 0x2CF0));
    }
    printf_16F718(&D_004E7D38_16F718, M2C_FIELD(arg0, s32* , 0x2CF0));
    printf_16F718(&D_004E7ED0_16F718);
    return D_004F9EB0_16F718;
}
//@@ func_0016F718 m2c1
#include "m2c_macros.h"
s32 func_0016F910_16F718() __asm__("func_0016F910");
M2C_UNK func_001703E8_16F718() __asm__("func_001703E8");
M2C_UNK func_00266478_16F718() __asm__("func_00266478");
M2C_UNK func_00266D78_16F718() __asm__("func_00266D78");
s32 func_002697C0_16F718() __asm__("func_002697C0");
M2C_UNK func_0026A4F8_16F718() __asm__("func_0026A4F8");
s32 func_0026A550_16F718() __asm__("func_0026A550");
M2C_UNK func_0026E2D8_16F718() __asm__("func_0026E2D8");
s32 netGetMyClientIndex_16F718() __asm__("netGetMyClientIndex");
M2C_UNK printf_16F718() __asm__("printf");
extern M2C_UNK D_004E7BC8_16F718 __asm__("D_004E7BC8");
extern M2C_UNK D_004E7D38_16F718 __asm__("D_004E7D38");
extern M2C_UNK D_004E7DE0_16F718 __asm__("D_004E7DE0");
extern M2C_UNK D_004E7E08_16F718 __asm__("D_004E7E08");
extern M2C_UNK D_004E7E30_16F718 __asm__("D_004E7E30");
extern M2C_UNK D_004E7E58_16F718 __asm__("D_004E7E58");
extern M2C_UNK D_004E7E70_16F718 __asm__("D_004E7E70");
extern M2C_UNK D_004E7EA0_16F718 __asm__("D_004E7EA0");
extern M2C_UNK D_004E7ED0_16F718 __asm__("D_004E7ED0");
extern s32 D_004F9EB0_16F718 __asm__("D_004F9EB0");
extern s32 D_004F9EB4_16F718 __asm__("D_004F9EB4");
extern M2C_UNK D_004F9EB8_16F718 __asm__("D_004F9EB8");
extern M2C_UNK func_00168B60_16F718 __asm__("func_00168B60");
extern M2C_UNK func_00168C30_16F718 __asm__("func_00168C30");
extern M2C_UNK func_0016C480_16F718 __asm__("func_0016C480");
extern M2C_UNK func_0016C590_16F718 __asm__("func_0016C590");

s32 func_0016F718(void* arg0, s32 arg1) {
    u8 sp[0x30];
    M2C_UNK sp20;
    M2C_UNK sp30;
    s32 temp_s2;
    s32 var_s2;

    temp_s2 = arg0 + 0x1258;
    func_00266478_16F718(&func_0016C590_16F718);
    D_004F9EB4_16F718 = 2;
    D_004F9EB0_16F718 = 0;
    func_00266D78_16F718(&D_004F9EB8_16F718);
    printf_16F718(&D_004E7BC8_16F718);
    printf_16F718("NETWORK: Attempting to connect to Peer 2 Peer Server:\n");
    printf_16F718(&D_004E7DE0_16F718, temp_s2);
    printf_16F718(&D_004E7E08_16F718, M2C_FIELD(arg0, s32* , 0x1298));
    printf_16F718(&D_004E7E30_16F718, M2C_FIELD(arg0, s32* , 0x129C));
    if (arg1 != 0) {
        func_0026A4F8_16F718(sp);
        var_s2 = func_0026A550_16F718(sp, &sp20, &func_00168C30_16F718, M2C_FIELD(arg0, s32* , 0x2DFC));
        printf_16F718(&D_004E7E58_16F718, var_s2);
        M2C_FIELD(arg0, s32* , 0x2CF0) = sp28;
loop_4:
        if (func_0016F910_16F718(arg0, &sp30) == 2) {
            func_001703E8_16F718(arg0);
            goto loop_4;
        }
        M2C_FIELD(arg0, s32* , 0x307C) = netGetMyClientIndex_16F718(arg0);
        printf_16F718(&D_004E7E70_16F718);
        printf_16F718(&D_004E7EA0_16F718, M2C_FIELD(arg0, s32* , 0x307C));
        printf_16F718(&D_004E7E70_16F718);
    } else {
        var_s2 = func_002697C0_16F718(arg0 + 0x2CF0, 0, temp_s2, &func_0016C480_16F718);
    }
    if (var_s2 != 0) {
        D_004F9EB0_16F718 = 1;
        func_0026E2D8_16F718(M2C_FIELD(arg0, s32* , 0x2CF0));
    }
    printf_16F718(&D_004E7D38_16F718, M2C_FIELD(arg0, s32* , 0x2CF0));
    printf_16F718(&D_004E7ED0_16F718);
    return D_004F9EB0_16F718;
}
//@@ func_0016F718 m2c2
#include "m2c_macros.h"
s32 func_0016F910_16F718() __asm__("func_0016F910");
M2C_UNK func_001703E8_16F718() __asm__("func_001703E8");
M2C_UNK func_00266478_16F718() __asm__("func_00266478");
M2C_UNK func_00266D78_16F718() __asm__("func_00266D78");
s32 func_002697C0_16F718() __asm__("func_002697C0");
M2C_UNK func_0026A4F8_16F718() __asm__("func_0026A4F8");
s32 func_0026A550_16F718() __asm__("func_0026A550");
M2C_UNK func_0026E2D8_16F718() __asm__("func_0026E2D8");
s32 netGetMyClientIndex_16F718() __asm__("netGetMyClientIndex");
M2C_UNK printf_16F718() __asm__("printf");
extern M2C_UNK D_004E7BC8_16F718 __asm__("D_004E7BC8");
extern M2C_UNK D_004E7D38_16F718 __asm__("D_004E7D38");
extern M2C_UNK D_004E7DE0_16F718 __asm__("D_004E7DE0");
extern M2C_UNK D_004E7E08_16F718 __asm__("D_004E7E08");
extern M2C_UNK D_004E7E30_16F718 __asm__("D_004E7E30");
extern M2C_UNK D_004E7E58_16F718 __asm__("D_004E7E58");
extern M2C_UNK D_004E7E70_16F718 __asm__("D_004E7E70");
extern M2C_UNK D_004E7EA0_16F718 __asm__("D_004E7EA0");
extern M2C_UNK D_004E7ED0_16F718 __asm__("D_004E7ED0");
extern s32 D_004F9EB0_16F718 __asm__("D_004F9EB0");
extern s32 D_004F9EB4_16F718 __asm__("D_004F9EB4");
extern M2C_UNK D_004F9EB8_16F718 __asm__("D_004F9EB8");
extern M2C_UNK func_00168B60_16F718 __asm__("func_00168B60");
extern M2C_UNK func_00168C30_16F718 __asm__("func_00168C30");
extern M2C_UNK func_0016C480_16F718 __asm__("func_0016C480");
extern M2C_UNK func_0016C590_16F718 __asm__("func_0016C590");

s32 func_0016F718(void* arg0, s32 arg1) {
    u8 sp[0x20];
    M2C_UNK sp20;
    M2C_UNK sp30;
    s32 temp_s2;
    s32 var_s2;

    temp_s2 = arg0 + 0x1258;
    func_00266478_16F718(&func_0016C590_16F718);
    D_004F9EB4_16F718 = 2;
    D_004F9EB0_16F718 = 0;
    func_00266D78_16F718(&D_004F9EB8_16F718);
    printf_16F718(&D_004E7BC8_16F718);
    printf_16F718("NETWORK: Attempting to connect to Peer 2 Peer Server:\n");
    printf_16F718(&D_004E7DE0_16F718, temp_s2);
    printf_16F718(&D_004E7E08_16F718, M2C_FIELD(arg0, s32* , 0x1298));
    printf_16F718(&D_004E7E30_16F718, M2C_FIELD(arg0, s32* , 0x129C));
    if (arg1 != 0) {
        func_0026A4F8_16F718(sp);
        var_s2 = func_0026A550_16F718(sp, &sp20, &func_00168C30_16F718, M2C_FIELD(arg0, s32* , 0x2DFC));
        printf_16F718(&D_004E7E58_16F718, var_s2);
        M2C_FIELD(arg0, s32* , 0x2CF0) = sp28;
loop_4:
        if (func_0016F910_16F718(arg0, &sp30) == 2) {
            func_001703E8_16F718(arg0);
            goto loop_4;
        }
        M2C_FIELD(arg0, s32* , 0x307C) = netGetMyClientIndex_16F718(arg0);
        printf_16F718(&D_004E7E70_16F718);
        printf_16F718(&D_004E7EA0_16F718, M2C_FIELD(arg0, s32* , 0x307C));
        printf_16F718(&D_004E7E70_16F718);
    } else {
        var_s2 = func_002697C0_16F718(arg0 + 0x2CF0, 0, temp_s2, &func_0016C480_16F718);
    }
    if (var_s2 != 0) {
        D_004F9EB0_16F718 = 1;
        func_0026E2D8_16F718(M2C_FIELD(arg0, s32* , 0x2CF0));
    }
    printf_16F718(&D_004E7D38_16F718, M2C_FIELD(arg0, s32* , 0x2CF0));
    printf_16F718(&D_004E7ED0_16F718);
    return D_004F9EB0_16F718;
}
//@@ func_0016F718 m2c3
#include "m2c_macros.h"
s32 func_0016F910_16F718() __asm__("func_0016F910");
M2C_UNK func_001703E8_16F718() __asm__("func_001703E8");
M2C_UNK func_00266478_16F718() __asm__("func_00266478");
M2C_UNK func_00266D78_16F718() __asm__("func_00266D78");
s32 func_002697C0_16F718() __asm__("func_002697C0");
M2C_UNK func_0026A4F8_16F718() __asm__("func_0026A4F8");
s32 func_0026A550_16F718() __asm__("func_0026A550");
M2C_UNK func_0026E2D8_16F718() __asm__("func_0026E2D8");
s32 netGetMyClientIndex_16F718() __asm__("netGetMyClientIndex");
M2C_UNK printf_16F718() __asm__("printf");
extern M2C_UNK D_004E7BC8_16F718 __asm__("D_004E7BC8");
extern M2C_UNK D_004E7D38_16F718 __asm__("D_004E7D38");
extern M2C_UNK D_004E7DE0_16F718 __asm__("D_004E7DE0");
extern M2C_UNK D_004E7E08_16F718 __asm__("D_004E7E08");
extern M2C_UNK D_004E7E30_16F718 __asm__("D_004E7E30");
extern M2C_UNK D_004E7E58_16F718 __asm__("D_004E7E58");
extern M2C_UNK D_004E7E70_16F718 __asm__("D_004E7E70");
extern M2C_UNK D_004E7EA0_16F718 __asm__("D_004E7EA0");
extern M2C_UNK D_004E7ED0_16F718 __asm__("D_004E7ED0");
extern s32 D_004F9EB0_16F718 __asm__("D_004F9EB0");
extern s32 D_004F9EB4_16F718 __asm__("D_004F9EB4");
extern M2C_UNK D_004F9EB8_16F718 __asm__("D_004F9EB8");
extern M2C_UNK func_00168B60_16F718 __asm__("func_00168B60");
extern M2C_UNK func_00168C30_16F718 __asm__("func_00168C30");
extern M2C_UNK func_0016C480_16F718 __asm__("func_0016C480");
extern M2C_UNK func_0016C590_16F718 __asm__("func_0016C590");

s32 func_0016F718(void* arg0, s32 arg1) {
    u8 sp[0x10];
    M2C_UNK sp20;
    M2C_UNK sp30;
    s32 temp_s2;
    s32 var_s2;

    temp_s2 = arg0 + 0x1258;
    func_00266478_16F718(&func_0016C590_16F718);
    D_004F9EB4_16F718 = 2;
    D_004F9EB0_16F718 = 0;
    func_00266D78_16F718(&D_004F9EB8_16F718);
    printf_16F718(&D_004E7BC8_16F718);
    printf_16F718("NETWORK: Attempting to connect to Peer 2 Peer Server:\n");
    printf_16F718(&D_004E7DE0_16F718, temp_s2);
    printf_16F718(&D_004E7E08_16F718, M2C_FIELD(arg0, s32* , 0x1298));
    printf_16F718(&D_004E7E30_16F718, M2C_FIELD(arg0, s32* , 0x129C));
    if (arg1 != 0) {
        func_0026A4F8_16F718(sp);
        var_s2 = func_0026A550_16F718(sp, &sp20, &func_00168C30_16F718, M2C_FIELD(arg0, s32* , 0x2DFC));
        printf_16F718(&D_004E7E58_16F718, var_s2);
        M2C_FIELD(arg0, s32* , 0x2CF0) = sp28;
loop_4:
        if (func_0016F910_16F718(arg0, &sp30) == 2) {
            func_001703E8_16F718(arg0);
            goto loop_4;
        }
        M2C_FIELD(arg0, s32* , 0x307C) = netGetMyClientIndex_16F718(arg0);
        printf_16F718(&D_004E7E70_16F718);
        printf_16F718(&D_004E7EA0_16F718, M2C_FIELD(arg0, s32* , 0x307C));
        printf_16F718(&D_004E7E70_16F718);
    } else {
        var_s2 = func_002697C0_16F718(arg0 + 0x2CF0, 0, temp_s2, &func_0016C480_16F718);
    }
    if (var_s2 != 0) {
        D_004F9EB0_16F718 = 1;
        func_0026E2D8_16F718(M2C_FIELD(arg0, s32* , 0x2CF0));
    }
    printf_16F718(&D_004E7D38_16F718, M2C_FIELD(arg0, s32* , 0x2CF0));
    printf_16F718(&D_004E7ED0_16F718);
    return D_004F9EB0_16F718;
}
//@@ func_0016F718 m2c4
#include "m2c_macros.h"
s32 func_0016F910_16F718() __asm__("func_0016F910");
M2C_UNK func_001703E8_16F718() __asm__("func_001703E8");
M2C_UNK func_00266478_16F718() __asm__("func_00266478");
M2C_UNK func_00266D78_16F718() __asm__("func_00266D78");
s32 func_002697C0_16F718() __asm__("func_002697C0");
M2C_UNK func_0026A4F8_16F718() __asm__("func_0026A4F8");
s32 func_0026A550_16F718() __asm__("func_0026A550");
M2C_UNK func_0026E2D8_16F718() __asm__("func_0026E2D8");
s32 netGetMyClientIndex_16F718() __asm__("netGetMyClientIndex");
M2C_UNK printf_16F718() __asm__("printf");
extern M2C_UNK D_004E7BC8_16F718 __asm__("D_004E7BC8");
extern M2C_UNK D_004E7D38_16F718 __asm__("D_004E7D38");
extern M2C_UNK D_004E7DE0_16F718 __asm__("D_004E7DE0");
extern M2C_UNK D_004E7E08_16F718 __asm__("D_004E7E08");
extern M2C_UNK D_004E7E30_16F718 __asm__("D_004E7E30");
extern M2C_UNK D_004E7E58_16F718 __asm__("D_004E7E58");
extern M2C_UNK D_004E7E70_16F718 __asm__("D_004E7E70");
extern M2C_UNK D_004E7EA0_16F718 __asm__("D_004E7EA0");
extern M2C_UNK D_004E7ED0_16F718 __asm__("D_004E7ED0");
extern s32 D_004F9EB0_16F718 __asm__("D_004F9EB0");
extern s32 D_004F9EB4_16F718 __asm__("D_004F9EB4");
extern M2C_UNK D_004F9EB8_16F718 __asm__("D_004F9EB8");
extern M2C_UNK func_00168B60_16F718 __asm__("func_00168B60");
extern M2C_UNK func_00168C30_16F718 __asm__("func_00168C30");
extern M2C_UNK func_0016C480_16F718 __asm__("func_0016C480");
extern M2C_UNK func_0016C590_16F718 __asm__("func_0016C590");

s32 func_0016F718(void* arg0, s32 arg1) {
    u8 sp[0x8];
    M2C_UNK sp20;
    M2C_UNK sp30;
    s32 temp_s2;
    s32 var_s2;

    temp_s2 = arg0 + 0x1258;
    func_00266478_16F718(&func_0016C590_16F718);
    D_004F9EB4_16F718 = 2;
    D_004F9EB0_16F718 = 0;
    func_00266D78_16F718(&D_004F9EB8_16F718);
    printf_16F718(&D_004E7BC8_16F718);
    printf_16F718("NETWORK: Attempting to connect to Peer 2 Peer Server:\n");
    printf_16F718(&D_004E7DE0_16F718, temp_s2);
    printf_16F718(&D_004E7E08_16F718, M2C_FIELD(arg0, s32* , 0x1298));
    printf_16F718(&D_004E7E30_16F718, M2C_FIELD(arg0, s32* , 0x129C));
    if (arg1 != 0) {
        func_0026A4F8_16F718(sp);
        var_s2 = func_0026A550_16F718(sp, &sp20, &func_00168C30_16F718, M2C_FIELD(arg0, s32* , 0x2DFC));
        printf_16F718(&D_004E7E58_16F718, var_s2);
        M2C_FIELD(arg0, s32* , 0x2CF0) = sp28;
loop_4:
        if (func_0016F910_16F718(arg0, &sp30) == 2) {
            func_001703E8_16F718(arg0);
            goto loop_4;
        }
        M2C_FIELD(arg0, s32* , 0x307C) = netGetMyClientIndex_16F718(arg0);
        printf_16F718(&D_004E7E70_16F718);
        printf_16F718(&D_004E7EA0_16F718, M2C_FIELD(arg0, s32* , 0x307C));
        printf_16F718(&D_004E7E70_16F718);
    } else {
        var_s2 = func_002697C0_16F718(arg0 + 0x2CF0, 0, temp_s2, &func_0016C480_16F718);
    }
    if (var_s2 != 0) {
        D_004F9EB0_16F718 = 1;
        func_0026E2D8_16F718(M2C_FIELD(arg0, s32* , 0x2CF0));
    }
    printf_16F718(&D_004E7D38_16F718, M2C_FIELD(arg0, s32* , 0x2CF0));
    printf_16F718(&D_004E7ED0_16F718);
    return D_004F9EB0_16F718;
}
//@@ func_0016F718 m2c5
#include "m2c_macros.h"
s32 func_0016F910_16F718() __asm__("func_0016F910");
M2C_UNK func_001703E8_16F718() __asm__("func_001703E8");
M2C_UNK func_00266478_16F718() __asm__("func_00266478");
M2C_UNK func_00266D78_16F718() __asm__("func_00266D78");
s32 func_002697C0_16F718() __asm__("func_002697C0");
M2C_UNK func_0026A4F8_16F718() __asm__("func_0026A4F8");
s32 func_0026A550_16F718() __asm__("func_0026A550");
M2C_UNK func_0026E2D8_16F718() __asm__("func_0026E2D8");
s32 netGetMyClientIndex_16F718() __asm__("netGetMyClientIndex");
M2C_UNK printf_16F718() __asm__("printf");
extern M2C_UNK D_004E7BC8_16F718 __asm__("D_004E7BC8");
extern M2C_UNK D_004E7D38_16F718 __asm__("D_004E7D38");
extern M2C_UNK D_004E7DE0_16F718 __asm__("D_004E7DE0");
extern M2C_UNK D_004E7E08_16F718 __asm__("D_004E7E08");
extern M2C_UNK D_004E7E30_16F718 __asm__("D_004E7E30");
extern M2C_UNK D_004E7E58_16F718 __asm__("D_004E7E58");
extern M2C_UNK D_004E7E70_16F718 __asm__("D_004E7E70");
extern M2C_UNK D_004E7EA0_16F718 __asm__("D_004E7EA0");
extern M2C_UNK D_004E7ED0_16F718 __asm__("D_004E7ED0");
extern s32 D_004F9EB0_16F718 __asm__("D_004F9EB0");
extern s32 D_004F9EB4_16F718 __asm__("D_004F9EB4");
extern M2C_UNK D_004F9EB8_16F718 __asm__("D_004F9EB8");
extern M2C_UNK func_00168B60_16F718 __asm__("func_00168B60");
extern M2C_UNK func_00168C30_16F718 __asm__("func_00168C30");
extern M2C_UNK func_0016C480_16F718 __asm__("func_0016C480");
extern M2C_UNK func_0016C590_16F718 __asm__("func_0016C590");

s32 func_0016F718(void* arg0, s32 arg1) {
    u8 sp[0x4];
    M2C_UNK sp20;
    M2C_UNK sp30;
    s32 temp_s2;
    s32 var_s2;

    temp_s2 = arg0 + 0x1258;
    func_00266478_16F718(&func_0016C590_16F718);
    D_004F9EB4_16F718 = 2;
    D_004F9EB0_16F718 = 0;
    func_00266D78_16F718(&D_004F9EB8_16F718);
    printf_16F718(&D_004E7BC8_16F718);
    printf_16F718("NETWORK: Attempting to connect to Peer 2 Peer Server:\n");
    printf_16F718(&D_004E7DE0_16F718, temp_s2);
    printf_16F718(&D_004E7E08_16F718, M2C_FIELD(arg0, s32* , 0x1298));
    printf_16F718(&D_004E7E30_16F718, M2C_FIELD(arg0, s32* , 0x129C));
    if (arg1 != 0) {
        func_0026A4F8_16F718(sp);
        var_s2 = func_0026A550_16F718(sp, &sp20, &func_00168C30_16F718, M2C_FIELD(arg0, s32* , 0x2DFC));
        printf_16F718(&D_004E7E58_16F718, var_s2);
        M2C_FIELD(arg0, s32* , 0x2CF0) = sp28;
loop_4:
        if (func_0016F910_16F718(arg0, &sp30) == 2) {
            func_001703E8_16F718(arg0);
            goto loop_4;
        }
        M2C_FIELD(arg0, s32* , 0x307C) = netGetMyClientIndex_16F718(arg0);
        printf_16F718(&D_004E7E70_16F718);
        printf_16F718(&D_004E7EA0_16F718, M2C_FIELD(arg0, s32* , 0x307C));
        printf_16F718(&D_004E7E70_16F718);
    } else {
        var_s2 = func_002697C0_16F718(arg0 + 0x2CF0, 0, temp_s2, &func_0016C480_16F718);
    }
    if (var_s2 != 0) {
        D_004F9EB0_16F718 = 1;
        func_0026E2D8_16F718(M2C_FIELD(arg0, s32* , 0x2CF0));
    }
    printf_16F718(&D_004E7D38_16F718, M2C_FIELD(arg0, s32* , 0x2CF0));
    printf_16F718(&D_004E7ED0_16F718);
    return D_004F9EB0_16F718;
}
//@@ func_0016F910 m2c0
#include "m2c_macros.h"
s32 dpcmp_16F910() __asm__("dpcmp");
s32 func_0016FA30_16F910() __asm__("func_0016FA30");
M2C_UNK func_0016FD68_16F910() __asm__("func_0016FD68");
M2C_UNK func_00266D78_16F910() __asm__("func_00266D78");
M2C_UNK func_00266E48_16F910() __asm__("func_00266E48");
s32 litodp_16F910() __asm__("litodp");
extern s32 D_004F9EB0_16F910 __asm__("D_004F9EB0");
extern s32 D_004F9EB4_16F910 __asm__("D_004F9EB4");
extern s32 D_004F9EB8_16F910 __asm__("D_004F9EB8");

s32 func_0016F910(void* arg0, s32* arg1) {
    u8 sp[0x10];
    s32 temp_s0;
    s32 temp_s1;

    func_00266D78_16F910(sp);
    temp_s1 = (dpcmp_16F910(litodp_16F910(subroutine_arg0 - D_004F9EB8_16F910), ((0x81BA << 0x10) | 0x9800) << 0x1F) < 1) ? 0 : 1;
    func_00266E48_16F910(&D_004F9EB4_16F910, M2C_FIELD(arg0, s32* , 0x2CF0));
    temp_s0 = D_004F9EB4_16F910;
    switch (temp_s0) {                              /* irregular */
    case 2:
        if (temp_s1 == 0) {
            switch (temp_s0) {                      /* switch 1; irregular */
            case 1:
            case 1:                                 /* switch 1 */
                if (func_0016FA30_16F910(arg0) != temp_s0) {
                    D_004F9EB0_16F910 = temp_s0;
                } else {
                    D_004F9EB0_16F910 = 0;
                }
                break;
            }
        } else {
        case 0:
        case 3:
        case 0:                                     /* switch 1 */
        case 3:                                     /* switch 1 */
            func_0016FD68_16F910(arg0);
            D_004F9EB4_16F910 = 3;
            if (D_004F9EB0_16F910 == 0) {
                D_004F9EB0_16F910 = 1;
            }
        }
        break;
    }
    *arg1 = D_004F9EB0_16F910;
    return D_004F9EB4_16F910;
}
//@@ func_0016F910 m2c1
#include "m2c_macros.h"
s32 dpcmp_16F910() __asm__("dpcmp");
s32 func_0016FA30_16F910() __asm__("func_0016FA30");
M2C_UNK func_0016FD68_16F910() __asm__("func_0016FD68");
M2C_UNK func_00266D78_16F910() __asm__("func_00266D78");
M2C_UNK func_00266E48_16F910() __asm__("func_00266E48");
s32 litodp_16F910() __asm__("litodp");
extern s32 D_004F9EB0_16F910 __asm__("D_004F9EB0");
extern s32 D_004F9EB4_16F910 __asm__("D_004F9EB4");
extern s32 D_004F9EB8_16F910 __asm__("D_004F9EB8");

s32 func_0016F910(void* arg0, s32* arg1) {
    u8 sp[0x8];
    s32 temp_s0;
    s32 temp_s1;

    func_00266D78_16F910(sp);
    temp_s1 = (dpcmp_16F910(litodp_16F910(subroutine_arg0 - D_004F9EB8_16F910), ((0x81BA << 0x10) | 0x9800) << 0x1F) < 1) ? 0 : 1;
    func_00266E48_16F910(&D_004F9EB4_16F910, M2C_FIELD(arg0, s32* , 0x2CF0));
    temp_s0 = D_004F9EB4_16F910;
    switch (temp_s0) {                              /* irregular */
    case 2:
        if (temp_s1 == 0) {
            switch (temp_s0) {                      /* switch 1; irregular */
            case 1:
            case 1:                                 /* switch 1 */
                if (func_0016FA30_16F910(arg0) != temp_s0) {
                    D_004F9EB0_16F910 = temp_s0;
                } else {
                    D_004F9EB0_16F910 = 0;
                }
                break;
            }
        } else {
        case 0:
        case 3:
        case 0:                                     /* switch 1 */
        case 3:                                     /* switch 1 */
            func_0016FD68_16F910(arg0);
            D_004F9EB4_16F910 = 3;
            if (D_004F9EB0_16F910 == 0) {
                D_004F9EB0_16F910 = 1;
            }
        }
        break;
    }
    *arg1 = D_004F9EB0_16F910;
    return D_004F9EB4_16F910;
}
//@@ func_0016F910 m2c2
#include "m2c_macros.h"
s32 dpcmp_16F910() __asm__("dpcmp");
s32 func_0016FA30_16F910() __asm__("func_0016FA30");
M2C_UNK func_0016FD68_16F910() __asm__("func_0016FD68");
M2C_UNK func_00266D78_16F910() __asm__("func_00266D78");
M2C_UNK func_00266E48_16F910() __asm__("func_00266E48");
s32 litodp_16F910() __asm__("litodp");
extern s32 D_004F9EB0_16F910 __asm__("D_004F9EB0");
extern s32 D_004F9EB4_16F910 __asm__("D_004F9EB4");
extern s32 D_004F9EB8_16F910 __asm__("D_004F9EB8");

s32 func_0016F910(void* arg0, s32* arg1) {
    u8 sp[0x4];
    s32 temp_s0;
    s32 temp_s1;

    func_00266D78_16F910(sp);
    temp_s1 = (dpcmp_16F910(litodp_16F910(subroutine_arg0 - D_004F9EB8_16F910), ((0x81BA << 0x10) | 0x9800) << 0x1F) < 1) ? 0 : 1;
    func_00266E48_16F910(&D_004F9EB4_16F910, M2C_FIELD(arg0, s32* , 0x2CF0));
    temp_s0 = D_004F9EB4_16F910;
    switch (temp_s0) {                              /* irregular */
    case 2:
        if (temp_s1 == 0) {
            switch (temp_s0) {                      /* switch 1; irregular */
            case 1:
            case 1:                                 /* switch 1 */
                if (func_0016FA30_16F910(arg0) != temp_s0) {
                    D_004F9EB0_16F910 = temp_s0;
                } else {
                    D_004F9EB0_16F910 = 0;
                }
                break;
            }
        } else {
        case 0:
        case 3:
        case 0:                                     /* switch 1 */
        case 3:                                     /* switch 1 */
            func_0016FD68_16F910(arg0);
            D_004F9EB4_16F910 = 3;
            if (D_004F9EB0_16F910 == 0) {
                D_004F9EB0_16F910 = 1;
            }
        }
        break;
    }
    *arg1 = D_004F9EB0_16F910;
    return D_004F9EB4_16F910;
}
//@@ func_0016FA30 m2c0
#include "m2c_macros.h"
M2C_UNK dmeGetMyClientIndex_16FA30() __asm__("dmeGetMyClientIndex");
M2C_UNK func_0016FD68_16FA30() __asm__("func_0016FD68");
M2C_UNK func_001703E8_16FA30() __asm__("func_001703E8");
s32 func_00173500_16FA30() __asm__("func_00173500");
M2C_UNK func_00173570_16FA30() __asm__("func_00173570");
M2C_UNK func_00174598_16FA30() __asm__("func_00174598");
M2C_UNK func_001748D8_16FA30() __asm__("func_001748D8");
M2C_UNK func_00266D78_16FA30() __asm__("func_00266D78");
M2C_UNK func_00266E48_16FA30() __asm__("func_00266E48");
M2C_UNK func_00266EB0_16FA30() __asm__("func_00266EB0");
M2C_UNK func_0026E2D8_16FA30() __asm__("func_0026E2D8");
M2C_UNK memset_16FA30() __asm__("memset");
M2C_UNK netSendSessionMsg_16FA30() __asm__("netSendSessionMsg");
M2C_UNK printf_16FA30() __asm__("printf");
M2C_UNK strcpy_16FA30() __asm__("strcpy");
extern s32 D_00317270_16FA30 __asm__("D_00317270");
extern M2C_UNK D_004E7BC8_16FA30 __asm__("D_004E7BC8");
extern s32 D_004F9EB4_16FA30 __asm__("D_004F9EB4");

s32 func_0016FA30(void* arg0) {
    u8 sp[0x100];
    s32 spF0;
    s32 spF4;
    s32 spF8;
    s32 spFC;
    s32 var_s1;
    s32* temp_a2;
    s32* temp_v0;

    printf_16FA30("NETWORK: Successfully connected to Server %s, Connection Index = %d\n", arg0 + 0x1258, M2C_FIELD(arg0, s32* , 0x2CF0));
    dmeGetMyClientIndex_16FA30(&spF0, M2C_FIELD(arg0, s32* , 0x2CF0));
    printf_16FA30("NETWORK: NetGetMyClientIndex(mConnectionIndex) = %d\n", spF0);
    temp_v0 = arg0 + ((spF0 * 0x220) + 0x10);
    M2C_FIELD(arg0, s32** , 4) = temp_v0;
    *temp_v0 = spF0;
    M2C_FIELD(M2C_FIELD(arg0, s32** , 4), s32* , 4) = -1;
    strcpy_16FA30(M2C_FIELD(arg0, s32** , 4) + 8, arg0 + 0x1998, -1);
    strcpy_16FA30(M2C_FIELD(arg0, s32** , 4) + 0x48, arg0 + 0x19D8);
    M2C_FIELD(M2C_FIELD(arg0, s32** , 4), s32* , 0xA4) = (s32) M2C_FIELD(arg0, s32* , 0x1A34);
    strcpy_16FA30(M2C_FIELD(arg0, s32** , 4) + 0xC4, arg0 + 0x1A94);
    temp_a2 = M2C_FIELD(arg0, s32** , 4);
    M2C_FIELD(temp_a2, s32* , 0x204) = (s32) M2C_FIELD(arg0, s32* , 0x1B94);
    M2C_FIELD(M2C_FIELD(arg0, s32** , 4), s32* , 0xBC) = 0;
    func_00173570_16FA30(arg0, 1, temp_a2);
    func_00266EB0_16FA30(&spF4, M2C_FIELD(arg0, s32* , 0x2CF0));
    if (spF4 != 1) {
        printf_16FA30("NETWORK: Connection count = %d, I am NOT the Session Master\n", spF4);
    } else {
        printf_16FA30("NETWORK: Connection count = %d, I should be the Session Master\n", 1);
    }
    if (spF4 == 1) {
        D_00317270_16FA30 = 1;
        func_00174598_16FA30(arg0);
        M2C_FIELD(M2C_FIELD(arg0, s32** , 4), s32* , 0xA4) = (s32) M2C_FIELD(arg0, s32* , 0x1A34);
        memset_16FA30(arg0 + 0x3080, 0, 0xC8);
        M2C_FIELD(arg0, s64* , 0x3080) = (s64) ((((((M2C_FIELD(arg0, s64* , 0x3080) & ~0x1E) | 4) & ~0x20 & ~0x3C0) | 0x40) & ~0xC00) | 0x800);
        M2C_FIELD(arg0, u8* , 0x3084) = (u8) M2C_FIELD(arg0, u8* , 0x2DFC);
        M2C_FIELD(arg0, s8* , 0x309B) = -1;
        M2C_FIELD(arg0, s8* , 0x309A) = -1;
        M2C_FIELD(arg0, s64* , 0x3080) = (s64) ((M2C_FIELD(arg0, s64* , 0x3080) & 0xFFC0FFFF) | 0x230000);
    }
    if (spF4 < 2) {
        M2C_FIELD(arg0, s32* , 0x2EE4) = 0;
    } else {
        func_00266D78_16FA30(&spF8);
        printf_16FA30("NETWORK: Waiting for state info...\n");
        M2C_FIELD(arg0, s32* , 0x2EE4) = 1;
    }
    var_s1 = 0;
    if (M2C_FIELD(arg0, s32* , 0x2EE4) != 0) {
loop_13:
        func_00266D78_16FA30(&spFC);
        if (((spFC - spF8) < 0x1389) || (netSendSessionMsg_16FA30(arg0, func_00173500_16FA30(arg0), sp), func_00266D78_16FA30(&spF8), printf_16FA30("NETWORK: Still waiting for state info...\n"), func_00266E48_16FA30(&D_004F9EB4_16FA30, M2C_FIELD(arg0, s32* , 0x2CF0)), var_s1 = ((D_004F9EB4_16FA30 ^ 1) != 0) ? 0xB : (var_s1 + 1), ((var_s1 < 0xB) != 0))) {
            func_001703E8_16FA30(arg0);
            if (M2C_FIELD(arg0, s32* , 0x2EE4) == 0) {
                goto block_16;
            }
            goto loop_13;
        }
        func_00173570_16FA30(arg0, 0);
        func_0016FD68_16FA30(arg0);
        func_001748D8_16FA30(arg0);
        D_004F9EB4_16FA30 = 3;
        return 3;
    }
block_16:
    if (M2C_FIELD(arg0, s32* , 0x1BB4) != 0xE) {
        printf_16FA30("NETWORK: Got State Info...\n");
        printf_16FA30(&D_004E7BC8_16FA30);
        D_004F9EB4_16FA30 = 1;
        return 1;
    }
    func_0026E2D8_16FA30(M2C_FIELD(arg0, s32* , 0x2CF0));
    func_001748D8_16FA30(arg0);
    func_00173570_16FA30(arg0, 0);
    D_004F9EB4_16FA30 = 0;
    return 0;
}
//@@ func_0016FA30 m2c1
#include "m2c_macros.h"
M2C_UNK dmeGetMyClientIndex_16FA30() __asm__("dmeGetMyClientIndex");
M2C_UNK func_0016FD68_16FA30() __asm__("func_0016FD68");
M2C_UNK func_001703E8_16FA30() __asm__("func_001703E8");
s32 func_00173500_16FA30() __asm__("func_00173500");
M2C_UNK func_00173570_16FA30() __asm__("func_00173570");
M2C_UNK func_00174598_16FA30() __asm__("func_00174598");
M2C_UNK func_001748D8_16FA30() __asm__("func_001748D8");
M2C_UNK func_00266D78_16FA30() __asm__("func_00266D78");
M2C_UNK func_00266E48_16FA30() __asm__("func_00266E48");
M2C_UNK func_00266EB0_16FA30() __asm__("func_00266EB0");
M2C_UNK func_0026E2D8_16FA30() __asm__("func_0026E2D8");
M2C_UNK memset_16FA30() __asm__("memset");
M2C_UNK netSendSessionMsg_16FA30() __asm__("netSendSessionMsg");
M2C_UNK printf_16FA30() __asm__("printf");
M2C_UNK strcpy_16FA30() __asm__("strcpy");
extern s32 D_00317270_16FA30 __asm__("D_00317270");
extern M2C_UNK D_004E7BC8_16FA30 __asm__("D_004E7BC8");
extern s32 D_004F9EB4_16FA30 __asm__("D_004F9EB4");

s32 func_0016FA30(void* arg0) {
    u8 sp[0xF0];
    s32 spF0;
    s32 spF4;
    s32 spF8;
    s32 spFC;
    s32 var_s1;
    s32* temp_a2;
    s32* temp_v0;

    printf_16FA30("NETWORK: Successfully connected to Server %s, Connection Index = %d\n", arg0 + 0x1258, M2C_FIELD(arg0, s32* , 0x2CF0));
    dmeGetMyClientIndex_16FA30(&spF0, M2C_FIELD(arg0, s32* , 0x2CF0));
    printf_16FA30("NETWORK: NetGetMyClientIndex(mConnectionIndex) = %d\n", spF0);
    temp_v0 = arg0 + ((spF0 * 0x220) + 0x10);
    M2C_FIELD(arg0, s32** , 4) = temp_v0;
    *temp_v0 = spF0;
    M2C_FIELD(M2C_FIELD(arg0, s32** , 4), s32* , 4) = -1;
    strcpy_16FA30(M2C_FIELD(arg0, s32** , 4) + 8, arg0 + 0x1998, -1);
    strcpy_16FA30(M2C_FIELD(arg0, s32** , 4) + 0x48, arg0 + 0x19D8);
    M2C_FIELD(M2C_FIELD(arg0, s32** , 4), s32* , 0xA4) = (s32) M2C_FIELD(arg0, s32* , 0x1A34);
    strcpy_16FA30(M2C_FIELD(arg0, s32** , 4) + 0xC4, arg0 + 0x1A94);
    temp_a2 = M2C_FIELD(arg0, s32** , 4);
    M2C_FIELD(temp_a2, s32* , 0x204) = (s32) M2C_FIELD(arg0, s32* , 0x1B94);
    M2C_FIELD(M2C_FIELD(arg0, s32** , 4), s32* , 0xBC) = 0;
    func_00173570_16FA30(arg0, 1, temp_a2);
    func_00266EB0_16FA30(&spF4, M2C_FIELD(arg0, s32* , 0x2CF0));
    if (spF4 != 1) {
        printf_16FA30("NETWORK: Connection count = %d, I am NOT the Session Master\n", spF4);
    } else {
        printf_16FA30("NETWORK: Connection count = %d, I should be the Session Master\n", 1);
    }
    if (spF4 == 1) {
        D_00317270_16FA30 = 1;
        func_00174598_16FA30(arg0);
        M2C_FIELD(M2C_FIELD(arg0, s32** , 4), s32* , 0xA4) = (s32) M2C_FIELD(arg0, s32* , 0x1A34);
        memset_16FA30(arg0 + 0x3080, 0, 0xC8);
        M2C_FIELD(arg0, s64* , 0x3080) = (s64) ((((((M2C_FIELD(arg0, s64* , 0x3080) & ~0x1E) | 4) & ~0x20 & ~0x3C0) | 0x40) & ~0xC00) | 0x800);
        M2C_FIELD(arg0, u8* , 0x3084) = (u8) M2C_FIELD(arg0, u8* , 0x2DFC);
        M2C_FIELD(arg0, s8* , 0x309B) = -1;
        M2C_FIELD(arg0, s8* , 0x309A) = -1;
        M2C_FIELD(arg0, s64* , 0x3080) = (s64) ((M2C_FIELD(arg0, s64* , 0x3080) & 0xFFC0FFFF) | 0x230000);
    }
    if (spF4 < 2) {
        M2C_FIELD(arg0, s32* , 0x2EE4) = 0;
    } else {
        func_00266D78_16FA30(&spF8);
        printf_16FA30("NETWORK: Waiting for state info...\n");
        M2C_FIELD(arg0, s32* , 0x2EE4) = 1;
    }
    var_s1 = 0;
    if (M2C_FIELD(arg0, s32* , 0x2EE4) != 0) {
loop_13:
        func_00266D78_16FA30(&spFC);
        if (((spFC - spF8) < 0x1389) || (netSendSessionMsg_16FA30(arg0, func_00173500_16FA30(arg0), sp), func_00266D78_16FA30(&spF8), printf_16FA30("NETWORK: Still waiting for state info...\n"), func_00266E48_16FA30(&D_004F9EB4_16FA30, M2C_FIELD(arg0, s32* , 0x2CF0)), var_s1 = ((D_004F9EB4_16FA30 ^ 1) != 0) ? 0xB : (var_s1 + 1), ((var_s1 < 0xB) != 0))) {
            func_001703E8_16FA30(arg0);
            if (M2C_FIELD(arg0, s32* , 0x2EE4) == 0) {
                goto block_16;
            }
            goto loop_13;
        }
        func_00173570_16FA30(arg0, 0);
        func_0016FD68_16FA30(arg0);
        func_001748D8_16FA30(arg0);
        D_004F9EB4_16FA30 = 3;
        return 3;
    }
block_16:
    if (M2C_FIELD(arg0, s32* , 0x1BB4) != 0xE) {
        printf_16FA30("NETWORK: Got State Info...\n");
        printf_16FA30(&D_004E7BC8_16FA30);
        D_004F9EB4_16FA30 = 1;
        return 1;
    }
    func_0026E2D8_16FA30(M2C_FIELD(arg0, s32* , 0x2CF0));
    func_001748D8_16FA30(arg0);
    func_00173570_16FA30(arg0, 0);
    D_004F9EB4_16FA30 = 0;
    return 0;
}
//@@ func_0016FA30 m2c2
#include "m2c_macros.h"
M2C_UNK dmeGetMyClientIndex_16FA30() __asm__("dmeGetMyClientIndex");
M2C_UNK func_0016FD68_16FA30() __asm__("func_0016FD68");
M2C_UNK func_001703E8_16FA30() __asm__("func_001703E8");
s32 func_00173500_16FA30() __asm__("func_00173500");
M2C_UNK func_00173570_16FA30() __asm__("func_00173570");
M2C_UNK func_00174598_16FA30() __asm__("func_00174598");
M2C_UNK func_001748D8_16FA30() __asm__("func_001748D8");
M2C_UNK func_00266D78_16FA30() __asm__("func_00266D78");
M2C_UNK func_00266E48_16FA30() __asm__("func_00266E48");
M2C_UNK func_00266EB0_16FA30() __asm__("func_00266EB0");
M2C_UNK func_0026E2D8_16FA30() __asm__("func_0026E2D8");
M2C_UNK memset_16FA30() __asm__("memset");
M2C_UNK netSendSessionMsg_16FA30() __asm__("netSendSessionMsg");
M2C_UNK printf_16FA30() __asm__("printf");
M2C_UNK strcpy_16FA30() __asm__("strcpy");
extern s32 D_00317270_16FA30 __asm__("D_00317270");
extern M2C_UNK D_004E7BC8_16FA30 __asm__("D_004E7BC8");
extern s32 D_004F9EB4_16FA30 __asm__("D_004F9EB4");

s32 func_0016FA30(void* arg0) {
    u8 sp[0xE0];
    s32 spF0;
    s32 spF4;
    s32 spF8;
    s32 spFC;
    s32 var_s1;
    s32* temp_a2;
    s32* temp_v0;

    printf_16FA30("NETWORK: Successfully connected to Server %s, Connection Index = %d\n", arg0 + 0x1258, M2C_FIELD(arg0, s32* , 0x2CF0));
    dmeGetMyClientIndex_16FA30(&spF0, M2C_FIELD(arg0, s32* , 0x2CF0));
    printf_16FA30("NETWORK: NetGetMyClientIndex(mConnectionIndex) = %d\n", spF0);
    temp_v0 = arg0 + ((spF0 * 0x220) + 0x10);
    M2C_FIELD(arg0, s32** , 4) = temp_v0;
    *temp_v0 = spF0;
    M2C_FIELD(M2C_FIELD(arg0, s32** , 4), s32* , 4) = -1;
    strcpy_16FA30(M2C_FIELD(arg0, s32** , 4) + 8, arg0 + 0x1998, -1);
    strcpy_16FA30(M2C_FIELD(arg0, s32** , 4) + 0x48, arg0 + 0x19D8);
    M2C_FIELD(M2C_FIELD(arg0, s32** , 4), s32* , 0xA4) = (s32) M2C_FIELD(arg0, s32* , 0x1A34);
    strcpy_16FA30(M2C_FIELD(arg0, s32** , 4) + 0xC4, arg0 + 0x1A94);
    temp_a2 = M2C_FIELD(arg0, s32** , 4);
    M2C_FIELD(temp_a2, s32* , 0x204) = (s32) M2C_FIELD(arg0, s32* , 0x1B94);
    M2C_FIELD(M2C_FIELD(arg0, s32** , 4), s32* , 0xBC) = 0;
    func_00173570_16FA30(arg0, 1, temp_a2);
    func_00266EB0_16FA30(&spF4, M2C_FIELD(arg0, s32* , 0x2CF0));
    if (spF4 != 1) {
        printf_16FA30("NETWORK: Connection count = %d, I am NOT the Session Master\n", spF4);
    } else {
        printf_16FA30("NETWORK: Connection count = %d, I should be the Session Master\n", 1);
    }
    if (spF4 == 1) {
        D_00317270_16FA30 = 1;
        func_00174598_16FA30(arg0);
        M2C_FIELD(M2C_FIELD(arg0, s32** , 4), s32* , 0xA4) = (s32) M2C_FIELD(arg0, s32* , 0x1A34);
        memset_16FA30(arg0 + 0x3080, 0, 0xC8);
        M2C_FIELD(arg0, s64* , 0x3080) = (s64) ((((((M2C_FIELD(arg0, s64* , 0x3080) & ~0x1E) | 4) & ~0x20 & ~0x3C0) | 0x40) & ~0xC00) | 0x800);
        M2C_FIELD(arg0, u8* , 0x3084) = (u8) M2C_FIELD(arg0, u8* , 0x2DFC);
        M2C_FIELD(arg0, s8* , 0x309B) = -1;
        M2C_FIELD(arg0, s8* , 0x309A) = -1;
        M2C_FIELD(arg0, s64* , 0x3080) = (s64) ((M2C_FIELD(arg0, s64* , 0x3080) & 0xFFC0FFFF) | 0x230000);
    }
    if (spF4 < 2) {
        M2C_FIELD(arg0, s32* , 0x2EE4) = 0;
    } else {
        func_00266D78_16FA30(&spF8);
        printf_16FA30("NETWORK: Waiting for state info...\n");
        M2C_FIELD(arg0, s32* , 0x2EE4) = 1;
    }
    var_s1 = 0;
    if (M2C_FIELD(arg0, s32* , 0x2EE4) != 0) {
loop_13:
        func_00266D78_16FA30(&spFC);
        if (((spFC - spF8) < 0x1389) || (netSendSessionMsg_16FA30(arg0, func_00173500_16FA30(arg0), sp), func_00266D78_16FA30(&spF8), printf_16FA30("NETWORK: Still waiting for state info...\n"), func_00266E48_16FA30(&D_004F9EB4_16FA30, M2C_FIELD(arg0, s32* , 0x2CF0)), var_s1 = ((D_004F9EB4_16FA30 ^ 1) != 0) ? 0xB : (var_s1 + 1), ((var_s1 < 0xB) != 0))) {
            func_001703E8_16FA30(arg0);
            if (M2C_FIELD(arg0, s32* , 0x2EE4) == 0) {
                goto block_16;
            }
            goto loop_13;
        }
        func_00173570_16FA30(arg0, 0);
        func_0016FD68_16FA30(arg0);
        func_001748D8_16FA30(arg0);
        D_004F9EB4_16FA30 = 3;
        return 3;
    }
block_16:
    if (M2C_FIELD(arg0, s32* , 0x1BB4) != 0xE) {
        printf_16FA30("NETWORK: Got State Info...\n");
        printf_16FA30(&D_004E7BC8_16FA30);
        D_004F9EB4_16FA30 = 1;
        return 1;
    }
    func_0026E2D8_16FA30(M2C_FIELD(arg0, s32* , 0x2CF0));
    func_001748D8_16FA30(arg0);
    func_00173570_16FA30(arg0, 0);
    D_004F9EB4_16FA30 = 0;
    return 0;
}
//@@ func_0016FA30 m2c3
#include "m2c_macros.h"
M2C_UNK dmeGetMyClientIndex_16FA30() __asm__("dmeGetMyClientIndex");
M2C_UNK func_0016FD68_16FA30() __asm__("func_0016FD68");
M2C_UNK func_001703E8_16FA30() __asm__("func_001703E8");
s32 func_00173500_16FA30() __asm__("func_00173500");
M2C_UNK func_00173570_16FA30() __asm__("func_00173570");
M2C_UNK func_00174598_16FA30() __asm__("func_00174598");
M2C_UNK func_001748D8_16FA30() __asm__("func_001748D8");
M2C_UNK func_00266D78_16FA30() __asm__("func_00266D78");
M2C_UNK func_00266E48_16FA30() __asm__("func_00266E48");
M2C_UNK func_00266EB0_16FA30() __asm__("func_00266EB0");
M2C_UNK func_0026E2D8_16FA30() __asm__("func_0026E2D8");
M2C_UNK memset_16FA30() __asm__("memset");
M2C_UNK netSendSessionMsg_16FA30() __asm__("netSendSessionMsg");
M2C_UNK printf_16FA30() __asm__("printf");
M2C_UNK strcpy_16FA30() __asm__("strcpy");
extern s32 D_00317270_16FA30 __asm__("D_00317270");
extern M2C_UNK D_004E7BC8_16FA30 __asm__("D_004E7BC8");
extern s32 D_004F9EB4_16FA30 __asm__("D_004F9EB4");

s32 func_0016FA30(void* arg0) {
    u8 sp[0xD0];
    s32 spF0;
    s32 spF4;
    s32 spF8;
    s32 spFC;
    s32 var_s1;
    s32* temp_a2;
    s32* temp_v0;

    printf_16FA30("NETWORK: Successfully connected to Server %s, Connection Index = %d\n", arg0 + 0x1258, M2C_FIELD(arg0, s32* , 0x2CF0));
    dmeGetMyClientIndex_16FA30(&spF0, M2C_FIELD(arg0, s32* , 0x2CF0));
    printf_16FA30("NETWORK: NetGetMyClientIndex(mConnectionIndex) = %d\n", spF0);
    temp_v0 = arg0 + ((spF0 * 0x220) + 0x10);
    M2C_FIELD(arg0, s32** , 4) = temp_v0;
    *temp_v0 = spF0;
    M2C_FIELD(M2C_FIELD(arg0, s32** , 4), s32* , 4) = -1;
    strcpy_16FA30(M2C_FIELD(arg0, s32** , 4) + 8, arg0 + 0x1998, -1);
    strcpy_16FA30(M2C_FIELD(arg0, s32** , 4) + 0x48, arg0 + 0x19D8);
    M2C_FIELD(M2C_FIELD(arg0, s32** , 4), s32* , 0xA4) = (s32) M2C_FIELD(arg0, s32* , 0x1A34);
    strcpy_16FA30(M2C_FIELD(arg0, s32** , 4) + 0xC4, arg0 + 0x1A94);
    temp_a2 = M2C_FIELD(arg0, s32** , 4);
    M2C_FIELD(temp_a2, s32* , 0x204) = (s32) M2C_FIELD(arg0, s32* , 0x1B94);
    M2C_FIELD(M2C_FIELD(arg0, s32** , 4), s32* , 0xBC) = 0;
    func_00173570_16FA30(arg0, 1, temp_a2);
    func_00266EB0_16FA30(&spF4, M2C_FIELD(arg0, s32* , 0x2CF0));
    if (spF4 != 1) {
        printf_16FA30("NETWORK: Connection count = %d, I am NOT the Session Master\n", spF4);
    } else {
        printf_16FA30("NETWORK: Connection count = %d, I should be the Session Master\n", 1);
    }
    if (spF4 == 1) {
        D_00317270_16FA30 = 1;
        func_00174598_16FA30(arg0);
        M2C_FIELD(M2C_FIELD(arg0, s32** , 4), s32* , 0xA4) = (s32) M2C_FIELD(arg0, s32* , 0x1A34);
        memset_16FA30(arg0 + 0x3080, 0, 0xC8);
        M2C_FIELD(arg0, s64* , 0x3080) = (s64) ((((((M2C_FIELD(arg0, s64* , 0x3080) & ~0x1E) | 4) & ~0x20 & ~0x3C0) | 0x40) & ~0xC00) | 0x800);
        M2C_FIELD(arg0, u8* , 0x3084) = (u8) M2C_FIELD(arg0, u8* , 0x2DFC);
        M2C_FIELD(arg0, s8* , 0x309B) = -1;
        M2C_FIELD(arg0, s8* , 0x309A) = -1;
        M2C_FIELD(arg0, s64* , 0x3080) = (s64) ((M2C_FIELD(arg0, s64* , 0x3080) & 0xFFC0FFFF) | 0x230000);
    }
    if (spF4 < 2) {
        M2C_FIELD(arg0, s32* , 0x2EE4) = 0;
    } else {
        func_00266D78_16FA30(&spF8);
        printf_16FA30("NETWORK: Waiting for state info...\n");
        M2C_FIELD(arg0, s32* , 0x2EE4) = 1;
    }
    var_s1 = 0;
    if (M2C_FIELD(arg0, s32* , 0x2EE4) != 0) {
loop_13:
        func_00266D78_16FA30(&spFC);
        if (((spFC - spF8) < 0x1389) || (netSendSessionMsg_16FA30(arg0, func_00173500_16FA30(arg0), sp), func_00266D78_16FA30(&spF8), printf_16FA30("NETWORK: Still waiting for state info...\n"), func_00266E48_16FA30(&D_004F9EB4_16FA30, M2C_FIELD(arg0, s32* , 0x2CF0)), var_s1 = ((D_004F9EB4_16FA30 ^ 1) != 0) ? 0xB : (var_s1 + 1), ((var_s1 < 0xB) != 0))) {
            func_001703E8_16FA30(arg0);
            if (M2C_FIELD(arg0, s32* , 0x2EE4) == 0) {
                goto block_16;
            }
            goto loop_13;
        }
        func_00173570_16FA30(arg0, 0);
        func_0016FD68_16FA30(arg0);
        func_001748D8_16FA30(arg0);
        D_004F9EB4_16FA30 = 3;
        return 3;
    }
block_16:
    if (M2C_FIELD(arg0, s32* , 0x1BB4) != 0xE) {
        printf_16FA30("NETWORK: Got State Info...\n");
        printf_16FA30(&D_004E7BC8_16FA30);
        D_004F9EB4_16FA30 = 1;
        return 1;
    }
    func_0026E2D8_16FA30(M2C_FIELD(arg0, s32* , 0x2CF0));
    func_001748D8_16FA30(arg0);
    func_00173570_16FA30(arg0, 0);
    D_004F9EB4_16FA30 = 0;
    return 0;
}
//@@ func_0016FA30 m2c4
#include "m2c_macros.h"
M2C_UNK dmeGetMyClientIndex_16FA30() __asm__("dmeGetMyClientIndex");
M2C_UNK func_0016FD68_16FA30() __asm__("func_0016FD68");
M2C_UNK func_001703E8_16FA30() __asm__("func_001703E8");
s32 func_00173500_16FA30() __asm__("func_00173500");
M2C_UNK func_00173570_16FA30() __asm__("func_00173570");
M2C_UNK func_00174598_16FA30() __asm__("func_00174598");
M2C_UNK func_001748D8_16FA30() __asm__("func_001748D8");
M2C_UNK func_00266D78_16FA30() __asm__("func_00266D78");
M2C_UNK func_00266E48_16FA30() __asm__("func_00266E48");
M2C_UNK func_00266EB0_16FA30() __asm__("func_00266EB0");
M2C_UNK func_0026E2D8_16FA30() __asm__("func_0026E2D8");
M2C_UNK memset_16FA30() __asm__("memset");
M2C_UNK netSendSessionMsg_16FA30() __asm__("netSendSessionMsg");
M2C_UNK printf_16FA30() __asm__("printf");
M2C_UNK strcpy_16FA30() __asm__("strcpy");
extern s32 D_00317270_16FA30 __asm__("D_00317270");
extern M2C_UNK D_004E7BC8_16FA30 __asm__("D_004E7BC8");
extern s32 D_004F9EB4_16FA30 __asm__("D_004F9EB4");

s32 func_0016FA30(void* arg0) {
    u8 sp[0xC0];
    s32 spF0;
    s32 spF4;
    s32 spF8;
    s32 spFC;
    s32 var_s1;
    s32* temp_a2;
    s32* temp_v0;

    printf_16FA30("NETWORK: Successfully connected to Server %s, Connection Index = %d\n", arg0 + 0x1258, M2C_FIELD(arg0, s32* , 0x2CF0));
    dmeGetMyClientIndex_16FA30(&spF0, M2C_FIELD(arg0, s32* , 0x2CF0));
    printf_16FA30("NETWORK: NetGetMyClientIndex(mConnectionIndex) = %d\n", spF0);
    temp_v0 = arg0 + ((spF0 * 0x220) + 0x10);
    M2C_FIELD(arg0, s32** , 4) = temp_v0;
    *temp_v0 = spF0;
    M2C_FIELD(M2C_FIELD(arg0, s32** , 4), s32* , 4) = -1;
    strcpy_16FA30(M2C_FIELD(arg0, s32** , 4) + 8, arg0 + 0x1998, -1);
    strcpy_16FA30(M2C_FIELD(arg0, s32** , 4) + 0x48, arg0 + 0x19D8);
    M2C_FIELD(M2C_FIELD(arg0, s32** , 4), s32* , 0xA4) = (s32) M2C_FIELD(arg0, s32* , 0x1A34);
    strcpy_16FA30(M2C_FIELD(arg0, s32** , 4) + 0xC4, arg0 + 0x1A94);
    temp_a2 = M2C_FIELD(arg0, s32** , 4);
    M2C_FIELD(temp_a2, s32* , 0x204) = (s32) M2C_FIELD(arg0, s32* , 0x1B94);
    M2C_FIELD(M2C_FIELD(arg0, s32** , 4), s32* , 0xBC) = 0;
    func_00173570_16FA30(arg0, 1, temp_a2);
    func_00266EB0_16FA30(&spF4, M2C_FIELD(arg0, s32* , 0x2CF0));
    if (spF4 != 1) {
        printf_16FA30("NETWORK: Connection count = %d, I am NOT the Session Master\n", spF4);
    } else {
        printf_16FA30("NETWORK: Connection count = %d, I should be the Session Master\n", 1);
    }
    if (spF4 == 1) {
        D_00317270_16FA30 = 1;
        func_00174598_16FA30(arg0);
        M2C_FIELD(M2C_FIELD(arg0, s32** , 4), s32* , 0xA4) = (s32) M2C_FIELD(arg0, s32* , 0x1A34);
        memset_16FA30(arg0 + 0x3080, 0, 0xC8);
        M2C_FIELD(arg0, s64* , 0x3080) = (s64) ((((((M2C_FIELD(arg0, s64* , 0x3080) & ~0x1E) | 4) & ~0x20 & ~0x3C0) | 0x40) & ~0xC00) | 0x800);
        M2C_FIELD(arg0, u8* , 0x3084) = (u8) M2C_FIELD(arg0, u8* , 0x2DFC);
        M2C_FIELD(arg0, s8* , 0x309B) = -1;
        M2C_FIELD(arg0, s8* , 0x309A) = -1;
        M2C_FIELD(arg0, s64* , 0x3080) = (s64) ((M2C_FIELD(arg0, s64* , 0x3080) & 0xFFC0FFFF) | 0x230000);
    }
    if (spF4 < 2) {
        M2C_FIELD(arg0, s32* , 0x2EE4) = 0;
    } else {
        func_00266D78_16FA30(&spF8);
        printf_16FA30("NETWORK: Waiting for state info...\n");
        M2C_FIELD(arg0, s32* , 0x2EE4) = 1;
    }
    var_s1 = 0;
    if (M2C_FIELD(arg0, s32* , 0x2EE4) != 0) {
loop_13:
        func_00266D78_16FA30(&spFC);
        if (((spFC - spF8) < 0x1389) || (netSendSessionMsg_16FA30(arg0, func_00173500_16FA30(arg0), sp), func_00266D78_16FA30(&spF8), printf_16FA30("NETWORK: Still waiting for state info...\n"), func_00266E48_16FA30(&D_004F9EB4_16FA30, M2C_FIELD(arg0, s32* , 0x2CF0)), var_s1 = ((D_004F9EB4_16FA30 ^ 1) != 0) ? 0xB : (var_s1 + 1), ((var_s1 < 0xB) != 0))) {
            func_001703E8_16FA30(arg0);
            if (M2C_FIELD(arg0, s32* , 0x2EE4) == 0) {
                goto block_16;
            }
            goto loop_13;
        }
        func_00173570_16FA30(arg0, 0);
        func_0016FD68_16FA30(arg0);
        func_001748D8_16FA30(arg0);
        D_004F9EB4_16FA30 = 3;
        return 3;
    }
block_16:
    if (M2C_FIELD(arg0, s32* , 0x1BB4) != 0xE) {
        printf_16FA30("NETWORK: Got State Info...\n");
        printf_16FA30(&D_004E7BC8_16FA30);
        D_004F9EB4_16FA30 = 1;
        return 1;
    }
    func_0026E2D8_16FA30(M2C_FIELD(arg0, s32* , 0x2CF0));
    func_001748D8_16FA30(arg0);
    func_00173570_16FA30(arg0, 0);
    D_004F9EB4_16FA30 = 0;
    return 0;
}
//@@ func_0016FA30 m2c5
#include "m2c_macros.h"
M2C_UNK dmeGetMyClientIndex_16FA30() __asm__("dmeGetMyClientIndex");
M2C_UNK func_0016FD68_16FA30() __asm__("func_0016FD68");
M2C_UNK func_001703E8_16FA30() __asm__("func_001703E8");
s32 func_00173500_16FA30() __asm__("func_00173500");
M2C_UNK func_00173570_16FA30() __asm__("func_00173570");
M2C_UNK func_00174598_16FA30() __asm__("func_00174598");
M2C_UNK func_001748D8_16FA30() __asm__("func_001748D8");
M2C_UNK func_00266D78_16FA30() __asm__("func_00266D78");
M2C_UNK func_00266E48_16FA30() __asm__("func_00266E48");
M2C_UNK func_00266EB0_16FA30() __asm__("func_00266EB0");
M2C_UNK func_0026E2D8_16FA30() __asm__("func_0026E2D8");
M2C_UNK memset_16FA30() __asm__("memset");
M2C_UNK netSendSessionMsg_16FA30() __asm__("netSendSessionMsg");
M2C_UNK printf_16FA30() __asm__("printf");
M2C_UNK strcpy_16FA30() __asm__("strcpy");
extern s32 D_00317270_16FA30 __asm__("D_00317270");
extern M2C_UNK D_004E7BC8_16FA30 __asm__("D_004E7BC8");
extern s32 D_004F9EB4_16FA30 __asm__("D_004F9EB4");

s32 func_0016FA30(void* arg0) {
    u8 sp[0xB0];
    s32 spF0;
    s32 spF4;
    s32 spF8;
    s32 spFC;
    s32 var_s1;
    s32* temp_a2;
    s32* temp_v0;

    printf_16FA30("NETWORK: Successfully connected to Server %s, Connection Index = %d\n", arg0 + 0x1258, M2C_FIELD(arg0, s32* , 0x2CF0));
    dmeGetMyClientIndex_16FA30(&spF0, M2C_FIELD(arg0, s32* , 0x2CF0));
    printf_16FA30("NETWORK: NetGetMyClientIndex(mConnectionIndex) = %d\n", spF0);
    temp_v0 = arg0 + ((spF0 * 0x220) + 0x10);
    M2C_FIELD(arg0, s32** , 4) = temp_v0;
    *temp_v0 = spF0;
    M2C_FIELD(M2C_FIELD(arg0, s32** , 4), s32* , 4) = -1;
    strcpy_16FA30(M2C_FIELD(arg0, s32** , 4) + 8, arg0 + 0x1998, -1);
    strcpy_16FA30(M2C_FIELD(arg0, s32** , 4) + 0x48, arg0 + 0x19D8);
    M2C_FIELD(M2C_FIELD(arg0, s32** , 4), s32* , 0xA4) = (s32) M2C_FIELD(arg0, s32* , 0x1A34);
    strcpy_16FA30(M2C_FIELD(arg0, s32** , 4) + 0xC4, arg0 + 0x1A94);
    temp_a2 = M2C_FIELD(arg0, s32** , 4);
    M2C_FIELD(temp_a2, s32* , 0x204) = (s32) M2C_FIELD(arg0, s32* , 0x1B94);
    M2C_FIELD(M2C_FIELD(arg0, s32** , 4), s32* , 0xBC) = 0;
    func_00173570_16FA30(arg0, 1, temp_a2);
    func_00266EB0_16FA30(&spF4, M2C_FIELD(arg0, s32* , 0x2CF0));
    if (spF4 != 1) {
        printf_16FA30("NETWORK: Connection count = %d, I am NOT the Session Master\n", spF4);
    } else {
        printf_16FA30("NETWORK: Connection count = %d, I should be the Session Master\n", 1);
    }
    if (spF4 == 1) {
        D_00317270_16FA30 = 1;
        func_00174598_16FA30(arg0);
        M2C_FIELD(M2C_FIELD(arg0, s32** , 4), s32* , 0xA4) = (s32) M2C_FIELD(arg0, s32* , 0x1A34);
        memset_16FA30(arg0 + 0x3080, 0, 0xC8);
        M2C_FIELD(arg0, s64* , 0x3080) = (s64) ((((((M2C_FIELD(arg0, s64* , 0x3080) & ~0x1E) | 4) & ~0x20 & ~0x3C0) | 0x40) & ~0xC00) | 0x800);
        M2C_FIELD(arg0, u8* , 0x3084) = (u8) M2C_FIELD(arg0, u8* , 0x2DFC);
        M2C_FIELD(arg0, s8* , 0x309B) = -1;
        M2C_FIELD(arg0, s8* , 0x309A) = -1;
        M2C_FIELD(arg0, s64* , 0x3080) = (s64) ((M2C_FIELD(arg0, s64* , 0x3080) & 0xFFC0FFFF) | 0x230000);
    }
    if (spF4 < 2) {
        M2C_FIELD(arg0, s32* , 0x2EE4) = 0;
    } else {
        func_00266D78_16FA30(&spF8);
        printf_16FA30("NETWORK: Waiting for state info...\n");
        M2C_FIELD(arg0, s32* , 0x2EE4) = 1;
    }
    var_s1 = 0;
    if (M2C_FIELD(arg0, s32* , 0x2EE4) != 0) {
loop_13:
        func_00266D78_16FA30(&spFC);
        if (((spFC - spF8) < 0x1389) || (netSendSessionMsg_16FA30(arg0, func_00173500_16FA30(arg0), sp), func_00266D78_16FA30(&spF8), printf_16FA30("NETWORK: Still waiting for state info...\n"), func_00266E48_16FA30(&D_004F9EB4_16FA30, M2C_FIELD(arg0, s32* , 0x2CF0)), var_s1 = ((D_004F9EB4_16FA30 ^ 1) != 0) ? 0xB : (var_s1 + 1), ((var_s1 < 0xB) != 0))) {
            func_001703E8_16FA30(arg0);
            if (M2C_FIELD(arg0, s32* , 0x2EE4) == 0) {
                goto block_16;
            }
            goto loop_13;
        }
        func_00173570_16FA30(arg0, 0);
        func_0016FD68_16FA30(arg0);
        func_001748D8_16FA30(arg0);
        D_004F9EB4_16FA30 = 3;
        return 3;
    }
block_16:
    if (M2C_FIELD(arg0, s32* , 0x1BB4) != 0xE) {
        printf_16FA30("NETWORK: Got State Info...\n");
        printf_16FA30(&D_004E7BC8_16FA30);
        D_004F9EB4_16FA30 = 1;
        return 1;
    }
    func_0026E2D8_16FA30(M2C_FIELD(arg0, s32* , 0x2CF0));
    func_001748D8_16FA30(arg0);
    func_00173570_16FA30(arg0, 0);
    D_004F9EB4_16FA30 = 0;
    return 0;
}
//@@ func_0016FD68 m2c0
#include "m2c_macros.h"
M2C_UNK func_00165ED0_16FD68() __asm__("func_00165ED0");
M2C_UNK func_00166600_16FD68() __asm__("func_00166600");
s32 func_001734B8_16FD68() __asm__("func_001734B8");
M2C_UNK func_00266EB0_16FD68() __asm__("func_00266EB0");
M2C_UNK func_0026E2D8_16FD68() __asm__("func_0026E2D8");
M2C_UNK printf_16FD68() __asm__("printf");
extern M2C_UNK D_002C1690_16FD68 __asm__("D_002C1690");
extern s32 D_003183B0_16FD68 __asm__("D_003183B0");
extern M2C_UNK D_004E7BC8_16FD68 __asm__("D_004E7BC8");
extern M2C_UNK D_004E7DE0_16FD68 __asm__("D_004E7DE0");
extern M2C_UNK D_004E7E08_16FD68 __asm__("D_004E7E08");
extern M2C_UNK D_004E7E30_16FD68 __asm__("D_004E7E30");

void func_0016FD68(void* arg0) {
    u8 sp[0x10];
    if (M2C_FIELD(arg0, s32* , 0x2CF0) >= 0) {
        if (M2C_FIELD(arg0, s32* , 0x2E90) == 0) {
            func_00165ED0_16FD68(&D_002C1690_16FD68, 2);
            func_00266EB0_16FD68(sp, D_003183B0_16FD68);
            if ((subroutine_arg0 < 2) && (func_001734B8_16FD68(arg0) != 0)) {
                func_00166600_16FD68(&D_002C1690_16FD68, M2C_FIELD(&D_002C1690_16FD68, s32* , 0x52438));
            }
        }
        printf_16FD68(&D_004E7BC8_16FD68);
        printf_16FD68("NETWORK: Disconnecting from connection %d:\n", M2C_FIELD(arg0, s32* , 0x2CF0));
        printf_16FD68(&D_004E7DE0_16FD68, (s32) (arg0 + 0x1258));
        printf_16FD68(&D_004E7E08_16FD68, M2C_FIELD(arg0, s32* , 0x1298));
        printf_16FD68(&D_004E7E30_16FD68, M2C_FIELD(arg0, s32* , 0x129C));
        printf_16FD68(&D_004E7BC8_16FD68);
        M2C_FIELD(arg0, s32* , 0x1BB0) = 0;
        M2C_FIELD(arg0, s32* , 0x1BB4) = 0;
        func_0026E2D8_16FD68(M2C_FIELD(arg0, s32* , 0x2CF0));
        M2C_FIELD(arg0, s32* , 0x2CF0) = -1;
    }
}
//@@ func_0016FD68 m2c1
#include "m2c_macros.h"
M2C_UNK func_00165ED0_16FD68() __asm__("func_00165ED0");
M2C_UNK func_00166600_16FD68() __asm__("func_00166600");
s32 func_001734B8_16FD68() __asm__("func_001734B8");
M2C_UNK func_00266EB0_16FD68() __asm__("func_00266EB0");
M2C_UNK func_0026E2D8_16FD68() __asm__("func_0026E2D8");
M2C_UNK printf_16FD68() __asm__("printf");
extern M2C_UNK D_002C1690_16FD68 __asm__("D_002C1690");
extern s32 D_003183B0_16FD68 __asm__("D_003183B0");
extern M2C_UNK D_004E7BC8_16FD68 __asm__("D_004E7BC8");
extern M2C_UNK D_004E7DE0_16FD68 __asm__("D_004E7DE0");
extern M2C_UNK D_004E7E08_16FD68 __asm__("D_004E7E08");
extern M2C_UNK D_004E7E30_16FD68 __asm__("D_004E7E30");

void func_0016FD68(void* arg0) {
    u8 sp[0x8];
    if (M2C_FIELD(arg0, s32* , 0x2CF0) >= 0) {
        if (M2C_FIELD(arg0, s32* , 0x2E90) == 0) {
            func_00165ED0_16FD68(&D_002C1690_16FD68, 2);
            func_00266EB0_16FD68(sp, D_003183B0_16FD68);
            if ((subroutine_arg0 < 2) && (func_001734B8_16FD68(arg0) != 0)) {
                func_00166600_16FD68(&D_002C1690_16FD68, M2C_FIELD(&D_002C1690_16FD68, s32* , 0x52438));
            }
        }
        printf_16FD68(&D_004E7BC8_16FD68);
        printf_16FD68("NETWORK: Disconnecting from connection %d:\n", M2C_FIELD(arg0, s32* , 0x2CF0));
        printf_16FD68(&D_004E7DE0_16FD68, (s32) (arg0 + 0x1258));
        printf_16FD68(&D_004E7E08_16FD68, M2C_FIELD(arg0, s32* , 0x1298));
        printf_16FD68(&D_004E7E30_16FD68, M2C_FIELD(arg0, s32* , 0x129C));
        printf_16FD68(&D_004E7BC8_16FD68);
        M2C_FIELD(arg0, s32* , 0x1BB0) = 0;
        M2C_FIELD(arg0, s32* , 0x1BB4) = 0;
        func_0026E2D8_16FD68(M2C_FIELD(arg0, s32* , 0x2CF0));
        M2C_FIELD(arg0, s32* , 0x2CF0) = -1;
    }
}
//@@ func_0016FD68 m2c2
#include "m2c_macros.h"
M2C_UNK func_00165ED0_16FD68() __asm__("func_00165ED0");
M2C_UNK func_00166600_16FD68() __asm__("func_00166600");
s32 func_001734B8_16FD68() __asm__("func_001734B8");
M2C_UNK func_00266EB0_16FD68() __asm__("func_00266EB0");
M2C_UNK func_0026E2D8_16FD68() __asm__("func_0026E2D8");
M2C_UNK printf_16FD68() __asm__("printf");
extern M2C_UNK D_002C1690_16FD68 __asm__("D_002C1690");
extern s32 D_003183B0_16FD68 __asm__("D_003183B0");
extern M2C_UNK D_004E7BC8_16FD68 __asm__("D_004E7BC8");
extern M2C_UNK D_004E7DE0_16FD68 __asm__("D_004E7DE0");
extern M2C_UNK D_004E7E08_16FD68 __asm__("D_004E7E08");
extern M2C_UNK D_004E7E30_16FD68 __asm__("D_004E7E30");

void func_0016FD68(void* arg0) {
    u8 sp[0x4];
    if (M2C_FIELD(arg0, s32* , 0x2CF0) >= 0) {
        if (M2C_FIELD(arg0, s32* , 0x2E90) == 0) {
            func_00165ED0_16FD68(&D_002C1690_16FD68, 2);
            func_00266EB0_16FD68(sp, D_003183B0_16FD68);
            if ((subroutine_arg0 < 2) && (func_001734B8_16FD68(arg0) != 0)) {
                func_00166600_16FD68(&D_002C1690_16FD68, M2C_FIELD(&D_002C1690_16FD68, s32* , 0x52438));
            }
        }
        printf_16FD68(&D_004E7BC8_16FD68);
        printf_16FD68("NETWORK: Disconnecting from connection %d:\n", M2C_FIELD(arg0, s32* , 0x2CF0));
        printf_16FD68(&D_004E7DE0_16FD68, (s32) (arg0 + 0x1258));
        printf_16FD68(&D_004E7E08_16FD68, M2C_FIELD(arg0, s32* , 0x1298));
        printf_16FD68(&D_004E7E30_16FD68, M2C_FIELD(arg0, s32* , 0x129C));
        printf_16FD68(&D_004E7BC8_16FD68);
        M2C_FIELD(arg0, s32* , 0x1BB0) = 0;
        M2C_FIELD(arg0, s32* , 0x1BB4) = 0;
        func_0026E2D8_16FD68(M2C_FIELD(arg0, s32* , 0x2CF0));
        M2C_FIELD(arg0, s32* , 0x2CF0) = -1;
    }
}
//@@ func_00170308 m2c0
#include "m2c_macros.h"
M2C_UNK func_00173570_170308() __asm__("func_00173570");
M2C_UNK func_0026AE18_170308() __asm__("func_0026AE18");
M2C_UNK func_0026B340_170308() __asm__("func_0026B340");
M2C_UNK printf_170308() __asm__("printf");
extern M2C_UNK D_004E7BC8_170308 __asm__("D_004E7BC8");
extern M2C_UNK D_004E80E0_170308 __asm__("D_004E80E0");
extern M2C_UNK D_004E8108_170308 __asm__("D_004E8108");
extern M2C_UNK D_004E8130_170308 __asm__("D_004E8130");
extern M2C_UNK D_004E8158_170308 __asm__("D_004E8158");
extern void* D_004FA03C_170308 __asm__("D_004FA03C");

void func_00170308(void* arg0) {
    if (M2C_FIELD(arg0, s32* , 0x2CF0) >= 0) {
        func_00173570_170308(0xC);
        printf_170308(&D_004E7BC8_170308);
        printf_170308("NETWORK: Leaving the Game\n");
        printf_170308(&D_004E80E0_170308, M2C_FIELD(arg0, s32* , 0x2CF0));
        printf_170308(&D_004E8108_170308, M2C_FIELD(arg0, s32* , 4) + 8);
        printf_170308(&D_004E8130_170308, M2C_FIELD(arg0, s32* , 0x2E04));
        printf_170308(&D_004E8158_170308, M2C_FIELD(arg0, s32* , 0x2E08));
        printf_170308(&D_004E7BC8_170308);
        func_0026AE18_170308(M2C_FIELD(arg0, s32* , 0x2CF0), 0);
        func_0026B340_170308(M2C_FIELD(arg0, s32* , 0x2CF0));
        M2C_FIELD(arg0, s32* , 0x1BB0) = 1;
        M2C_FIELD(arg0, s32* , 0x3214) = (s32) M2C_FIELD(D_004FA03C_170308, s32* , 0x1A3AC);
    }
}
//@@ func_001703E8 m2c0
#include "m2c_macros.h"
s32 func_0010A588_1703E8() __asm__("func_0010A588");
M2C_UNK func_00166808_1703E8() __asm__("func_00166808");
M2C_UNK func_00166940_1703E8() __asm__("func_00166940");
s32 func_0016D690_1703E8() __asm__("func_0016D690");
s32 func_001734B8_1703E8() __asm__("func_001734B8");
M2C_UNK func_00174D78_1703E8() __asm__("func_00174D78");
s8 func_00176B10_1703E8() __asm__("func_00176B10");
s32 func_0025A020_1703E8() __asm__("func_0025A020");
s32 func_0025C268_1703E8() __asm__("func_0025C268");
M2C_UNK func_00266228_1703E8() __asm__("func_00266228");
M2C_UNK func_00266D78_1703E8() __asm__("func_00266D78");
M2C_UNK func_00266DB8_1703E8() __asm__("func_00266DB8");
M2C_UNK func_0026B7A0_1703E8() __asm__("func_0026B7A0");
M2C_UNK func_0026DFF8_1703E8() __asm__("func_0026DFF8");
s32 func_0026E028_1703E8() __asm__("func_0026E028");
M2C_UNK func_0026E278_1703E8() __asm__("func_0026E278");
M2C_UNK printf_1703E8() __asm__("printf");
extern s32 D_002B8A00_1703E8 __asm__("D_002B8A00");
extern M2C_UNK D_002C1690_1703E8 __asm__("D_002C1690");
extern s32 D_00313D6C_1703E8 __asm__("D_00313D6C");
extern M2C_UNK D_003156C0_1703E8 __asm__("D_003156C0");
extern s32 D_004F9E3C_1703E8 __asm__("D_004F9E3C");
extern u32 D_004F9E40_1703E8 __asm__("D_004F9E40");
extern f32 D_004F9E44_1703E8 __asm__("D_004F9E44");
extern f32 D_004F9E48_1703E8 __asm__("D_004F9E48");
extern s32 D_004F9E4C_1703E8 __asm__("D_004F9E4C");
extern s32 D_004F9E50_1703E8 __asm__("D_004F9E50");
extern M2C_UNK func_00168FB8_1703E8 __asm__("func_00168FB8");

void func_001703E8(M2C_UNK* arg0) {
    u8 sp[0x50];
    M2C_UNK sp20;
    M2C_UNK sp40;
    s32 sp44;
    M2C_UNK* var_a0;
    s32 temp_a0;
    s32 temp_s0_2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 var_s1;
    s32 var_s2;
    s32* temp_s0;
    u32 temp_v0_5;

    var_s2 = 0;
    if (M2C_FIELD(arg0, s32* , 0x1BB8) == 5) {
        if (M2C_FIELD(arg0, s32* , 0x2E90) != 0) {
            var_s2 = func_0026E028_1703E8();
        } else {
            temp_v0 = func_0025A020_1703E8();
            if (temp_v0 != 0) {
                var_s2 = func_0025C268_1703E8(&D_002B8A00_1703E8);
                printf_1703E8("Medius Update returned an Error %d, NetError %d\n", temp_v0, var_s2);
            } else {
                temp_v0_2 = func_0010A588_1703E8(&D_002B8A00_1703E8);
                if (temp_v0_2 != 0) {
                    var_s1 = 0;
                    func_0026E278_1703E8(sp);
loop_7:
                    if (var_s1 < 4) {
                        temp_s0 = &(&sp4[0])[var_s1];
                        printf_1703E8("Connection %d Error = %d\n", var_s1, *temp_s0);
                        temp_s0_2 = *temp_s0;
                        if (temp_s0_2 == 0) {
                            var_s1 += 1;
                            goto loop_7;
                        }
                        var_s2 = temp_s0_2;
                    }
                    printf_1703E8("MGCL Update returned an Error %d - Connection Index %d, NetError %d\n", temp_v0_2, D_002B8A00_1703E8, var_s2);
                }
            }
        }
        if (func_0016D690_1703E8(arg0) == -1) {
            var_a0 = "InitCheckConnectionStatus returned an Error...\n";
            goto block_18;
        }
        if (var_s2 != 0) {
            printf_1703E8("NETWORK: Update Error = %d\n", var_s2);
            switch (var_s2) {                       /* irregular */
            case 2:
                var_a0 = "Update Error - Connection Lost\n";
block_18:
                printf_1703E8(var_a0);
                func_00174D78_1703E8(arg0, 6, 2);
                break;
            case 12:
                printf_1703E8("Update Error - Bad Packet received from the server\n");
                break;
            default:
                printf_1703E8("Update Error - Network Error\n");
                func_00174D78_1703E8(arg0, 6, 2);
                break;
            }
        }
        temp_a0 = M2C_FIELD(arg0, s32* , 0x1BB4);
        if ((u32) (temp_a0 - 1) < 6U) {
            temp_v0_3 = D_004F9E4C_1703E8 + 1;
            D_004F9E4C_1703E8 = temp_v0_3;
            if (temp_v0_3 == 0x259) {
                if (temp_a0 > 0) {
                    if (M2C_FIELD(((D_004F9E50_1703E8 * 0x220) + arg0), s32* , 0x10) != -1) {
                        func_0026B7A0_1703E8(M2C_FIELD(arg0, s32* , 0x2CF0), D_004F9E50_1703E8, &func_00168FB8_1703E8);
                        func_0026DFF8_1703E8();
                    }
                    temp_v0_4 = D_004F9E50_1703E8 + 1;
                    D_004F9E50_1703E8 = temp_v0_4;
                    if (temp_v0_4 >= 8) {
                        D_004F9E50_1703E8 = 0;
                    }
                }
                D_004F9E4C_1703E8 = 0;
            }
        }
        if (M2C_FIELD(arg0, s32* , 0x1BB4) > 0) {
            func_00266DB8_1703E8(&sp40);
            func_00266228_1703E8(&sp20);
            D_004F9E3C_1703E8 += 1;
            D_004F9E44_1703E8 += sp28;
            D_004F9E48_1703E8 += sp38;
            func_00266D78_1703E8(&sp44);
            if (((sp44 - M2C_FIELD(&D_002C1690_1703E8, s32* , 0x526DC)) >= 0x4E21) && (M2C_FIELD(&D_002C1690_1703E8, s32* , 8) >= 0) && (M2C_FIELD(arg0, s32* , 0x1BBC) != 0) && (M2C_FIELD(arg0, s32* , 0x2E90) == 0)) {
                if (func_001734B8_1703E8(&D_003156C0_1703E8) != 0) {
                    func_00166808_1703E8(&D_002C1690_1703E8, M2C_FIELD(&D_002C1690_1703E8, s32* , 0x52438));
                }
                func_00166940_1703E8(&D_002C1690_1703E8, M2C_FIELD(&D_002C1690_1703E8, s32* , 0x52438), M2C_FIELD(&D_002C1690_1703E8, s32* , 0x60));
                func_0025A020_1703E8();
                func_00266D78_1703E8(&D_00313D6C_1703E8);
            }
            if (M2C_FIELD(arg0, s32* , 0x1BB4) == 0xB) {
                if (func_001734B8_1703E8(arg0) != 0) {
                    temp_v0_5 = D_004F9E40_1703E8 + 1;
                    D_004F9E40_1703E8 = temp_v0_5;
                    if (temp_v0_5 >= 0x12DU) {
                        M2C_FIELD(M2C_FIELD(&D_003156C0_1703E8, void** , 0x3148), s8* , 0x24) = func_00176B10_1703E8(&D_003156C0_1703E8, 0);
                        D_004F9E40_1703E8 = 0;
                    }
                }
            }
        }
    }
}
//@@ func_001703E8 m2c1
#include "m2c_macros.h"
s32 func_0010A588_1703E8() __asm__("func_0010A588");
M2C_UNK func_00166808_1703E8() __asm__("func_00166808");
M2C_UNK func_00166940_1703E8() __asm__("func_00166940");
s32 func_0016D690_1703E8() __asm__("func_0016D690");
s32 func_001734B8_1703E8() __asm__("func_001734B8");
M2C_UNK func_00174D78_1703E8() __asm__("func_00174D78");
s8 func_00176B10_1703E8() __asm__("func_00176B10");
s32 func_0025A020_1703E8() __asm__("func_0025A020");
s32 func_0025C268_1703E8() __asm__("func_0025C268");
M2C_UNK func_00266228_1703E8() __asm__("func_00266228");
M2C_UNK func_00266D78_1703E8() __asm__("func_00266D78");
M2C_UNK func_00266DB8_1703E8() __asm__("func_00266DB8");
M2C_UNK func_0026B7A0_1703E8() __asm__("func_0026B7A0");
M2C_UNK func_0026DFF8_1703E8() __asm__("func_0026DFF8");
s32 func_0026E028_1703E8() __asm__("func_0026E028");
M2C_UNK func_0026E278_1703E8() __asm__("func_0026E278");
M2C_UNK printf_1703E8() __asm__("printf");
extern s32 D_002B8A00_1703E8 __asm__("D_002B8A00");
extern M2C_UNK D_002C1690_1703E8 __asm__("D_002C1690");
extern s32 D_00313D6C_1703E8 __asm__("D_00313D6C");
extern M2C_UNK D_003156C0_1703E8 __asm__("D_003156C0");
extern s32 D_004F9E3C_1703E8 __asm__("D_004F9E3C");
extern u32 D_004F9E40_1703E8 __asm__("D_004F9E40");
extern f32 D_004F9E44_1703E8 __asm__("D_004F9E44");
extern f32 D_004F9E48_1703E8 __asm__("D_004F9E48");
extern s32 D_004F9E4C_1703E8 __asm__("D_004F9E4C");
extern s32 D_004F9E50_1703E8 __asm__("D_004F9E50");
extern M2C_UNK func_00168FB8_1703E8 __asm__("func_00168FB8");

void func_001703E8(M2C_UNK* arg0) {
    u8 sp[0x40];
    M2C_UNK sp20;
    M2C_UNK sp40;
    s32 sp44;
    M2C_UNK* var_a0;
    s32 temp_a0;
    s32 temp_s0_2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 var_s1;
    s32 var_s2;
    s32* temp_s0;
    u32 temp_v0_5;

    var_s2 = 0;
    if (M2C_FIELD(arg0, s32* , 0x1BB8) == 5) {
        if (M2C_FIELD(arg0, s32* , 0x2E90) != 0) {
            var_s2 = func_0026E028_1703E8();
        } else {
            temp_v0 = func_0025A020_1703E8();
            if (temp_v0 != 0) {
                var_s2 = func_0025C268_1703E8(&D_002B8A00_1703E8);
                printf_1703E8("Medius Update returned an Error %d, NetError %d\n", temp_v0, var_s2);
            } else {
                temp_v0_2 = func_0010A588_1703E8(&D_002B8A00_1703E8);
                if (temp_v0_2 != 0) {
                    var_s1 = 0;
                    func_0026E278_1703E8(sp);
loop_7:
                    if (var_s1 < 4) {
                        temp_s0 = &(&sp4[0])[var_s1];
                        printf_1703E8("Connection %d Error = %d\n", var_s1, *temp_s0);
                        temp_s0_2 = *temp_s0;
                        if (temp_s0_2 == 0) {
                            var_s1 += 1;
                            goto loop_7;
                        }
                        var_s2 = temp_s0_2;
                    }
                    printf_1703E8("MGCL Update returned an Error %d - Connection Index %d, NetError %d\n", temp_v0_2, D_002B8A00_1703E8, var_s2);
                }
            }
        }
        if (func_0016D690_1703E8(arg0) == -1) {
            var_a0 = "InitCheckConnectionStatus returned an Error...\n";
            goto block_18;
        }
        if (var_s2 != 0) {
            printf_1703E8("NETWORK: Update Error = %d\n", var_s2);
            switch (var_s2) {                       /* irregular */
            case 2:
                var_a0 = "Update Error - Connection Lost\n";
block_18:
                printf_1703E8(var_a0);
                func_00174D78_1703E8(arg0, 6, 2);
                break;
            case 12:
                printf_1703E8("Update Error - Bad Packet received from the server\n");
                break;
            default:
                printf_1703E8("Update Error - Network Error\n");
                func_00174D78_1703E8(arg0, 6, 2);
                break;
            }
        }
        temp_a0 = M2C_FIELD(arg0, s32* , 0x1BB4);
        if ((u32) (temp_a0 - 1) < 6U) {
            temp_v0_3 = D_004F9E4C_1703E8 + 1;
            D_004F9E4C_1703E8 = temp_v0_3;
            if (temp_v0_3 == 0x259) {
                if (temp_a0 > 0) {
                    if (M2C_FIELD(((D_004F9E50_1703E8 * 0x220) + arg0), s32* , 0x10) != -1) {
                        func_0026B7A0_1703E8(M2C_FIELD(arg0, s32* , 0x2CF0), D_004F9E50_1703E8, &func_00168FB8_1703E8);
                        func_0026DFF8_1703E8();
                    }
                    temp_v0_4 = D_004F9E50_1703E8 + 1;
                    D_004F9E50_1703E8 = temp_v0_4;
                    if (temp_v0_4 >= 8) {
                        D_004F9E50_1703E8 = 0;
                    }
                }
                D_004F9E4C_1703E8 = 0;
            }
        }
        if (M2C_FIELD(arg0, s32* , 0x1BB4) > 0) {
            func_00266DB8_1703E8(&sp40);
            func_00266228_1703E8(&sp20);
            D_004F9E3C_1703E8 += 1;
            D_004F9E44_1703E8 += sp28;
            D_004F9E48_1703E8 += sp38;
            func_00266D78_1703E8(&sp44);
            if (((sp44 - M2C_FIELD(&D_002C1690_1703E8, s32* , 0x526DC)) >= 0x4E21) && (M2C_FIELD(&D_002C1690_1703E8, s32* , 8) >= 0) && (M2C_FIELD(arg0, s32* , 0x1BBC) != 0) && (M2C_FIELD(arg0, s32* , 0x2E90) == 0)) {
                if (func_001734B8_1703E8(&D_003156C0_1703E8) != 0) {
                    func_00166808_1703E8(&D_002C1690_1703E8, M2C_FIELD(&D_002C1690_1703E8, s32* , 0x52438));
                }
                func_00166940_1703E8(&D_002C1690_1703E8, M2C_FIELD(&D_002C1690_1703E8, s32* , 0x52438), M2C_FIELD(&D_002C1690_1703E8, s32* , 0x60));
                func_0025A020_1703E8();
                func_00266D78_1703E8(&D_00313D6C_1703E8);
            }
            if (M2C_FIELD(arg0, s32* , 0x1BB4) == 0xB) {
                if (func_001734B8_1703E8(arg0) != 0) {
                    temp_v0_5 = D_004F9E40_1703E8 + 1;
                    D_004F9E40_1703E8 = temp_v0_5;
                    if (temp_v0_5 >= 0x12DU) {
                        M2C_FIELD(M2C_FIELD(&D_003156C0_1703E8, void** , 0x3148), s8* , 0x24) = func_00176B10_1703E8(&D_003156C0_1703E8, 0);
                        D_004F9E40_1703E8 = 0;
                    }
                }
            }
        }
    }
}
//@@ func_001703E8 m2c2
#include "m2c_macros.h"
s32 func_0010A588_1703E8() __asm__("func_0010A588");
M2C_UNK func_00166808_1703E8() __asm__("func_00166808");
M2C_UNK func_00166940_1703E8() __asm__("func_00166940");
s32 func_0016D690_1703E8() __asm__("func_0016D690");
s32 func_001734B8_1703E8() __asm__("func_001734B8");
M2C_UNK func_00174D78_1703E8() __asm__("func_00174D78");
s8 func_00176B10_1703E8() __asm__("func_00176B10");
s32 func_0025A020_1703E8() __asm__("func_0025A020");
s32 func_0025C268_1703E8() __asm__("func_0025C268");
M2C_UNK func_00266228_1703E8() __asm__("func_00266228");
M2C_UNK func_00266D78_1703E8() __asm__("func_00266D78");
M2C_UNK func_00266DB8_1703E8() __asm__("func_00266DB8");
M2C_UNK func_0026B7A0_1703E8() __asm__("func_0026B7A0");
M2C_UNK func_0026DFF8_1703E8() __asm__("func_0026DFF8");
s32 func_0026E028_1703E8() __asm__("func_0026E028");
M2C_UNK func_0026E278_1703E8() __asm__("func_0026E278");
M2C_UNK printf_1703E8() __asm__("printf");
extern s32 D_002B8A00_1703E8 __asm__("D_002B8A00");
extern M2C_UNK D_002C1690_1703E8 __asm__("D_002C1690");
extern s32 D_00313D6C_1703E8 __asm__("D_00313D6C");
extern M2C_UNK D_003156C0_1703E8 __asm__("D_003156C0");
extern s32 D_004F9E3C_1703E8 __asm__("D_004F9E3C");
extern u32 D_004F9E40_1703E8 __asm__("D_004F9E40");
extern f32 D_004F9E44_1703E8 __asm__("D_004F9E44");
extern f32 D_004F9E48_1703E8 __asm__("D_004F9E48");
extern s32 D_004F9E4C_1703E8 __asm__("D_004F9E4C");
extern s32 D_004F9E50_1703E8 __asm__("D_004F9E50");
extern M2C_UNK func_00168FB8_1703E8 __asm__("func_00168FB8");

void func_001703E8(M2C_UNK* arg0) {
    u8 sp[0x30];
    M2C_UNK sp20;
    M2C_UNK sp40;
    s32 sp44;
    M2C_UNK* var_a0;
    s32 temp_a0;
    s32 temp_s0_2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 var_s1;
    s32 var_s2;
    s32* temp_s0;
    u32 temp_v0_5;

    var_s2 = 0;
    if (M2C_FIELD(arg0, s32* , 0x1BB8) == 5) {
        if (M2C_FIELD(arg0, s32* , 0x2E90) != 0) {
            var_s2 = func_0026E028_1703E8();
        } else {
            temp_v0 = func_0025A020_1703E8();
            if (temp_v0 != 0) {
                var_s2 = func_0025C268_1703E8(&D_002B8A00_1703E8);
                printf_1703E8("Medius Update returned an Error %d, NetError %d\n", temp_v0, var_s2);
            } else {
                temp_v0_2 = func_0010A588_1703E8(&D_002B8A00_1703E8);
                if (temp_v0_2 != 0) {
                    var_s1 = 0;
                    func_0026E278_1703E8(sp);
loop_7:
                    if (var_s1 < 4) {
                        temp_s0 = &(&sp4[0])[var_s1];
                        printf_1703E8("Connection %d Error = %d\n", var_s1, *temp_s0);
                        temp_s0_2 = *temp_s0;
                        if (temp_s0_2 == 0) {
                            var_s1 += 1;
                            goto loop_7;
                        }
                        var_s2 = temp_s0_2;
                    }
                    printf_1703E8("MGCL Update returned an Error %d - Connection Index %d, NetError %d\n", temp_v0_2, D_002B8A00_1703E8, var_s2);
                }
            }
        }
        if (func_0016D690_1703E8(arg0) == -1) {
            var_a0 = "InitCheckConnectionStatus returned an Error...\n";
            goto block_18;
        }
        if (var_s2 != 0) {
            printf_1703E8("NETWORK: Update Error = %d\n", var_s2);
            switch (var_s2) {                       /* irregular */
            case 2:
                var_a0 = "Update Error - Connection Lost\n";
block_18:
                printf_1703E8(var_a0);
                func_00174D78_1703E8(arg0, 6, 2);
                break;
            case 12:
                printf_1703E8("Update Error - Bad Packet received from the server\n");
                break;
            default:
                printf_1703E8("Update Error - Network Error\n");
                func_00174D78_1703E8(arg0, 6, 2);
                break;
            }
        }
        temp_a0 = M2C_FIELD(arg0, s32* , 0x1BB4);
        if ((u32) (temp_a0 - 1) < 6U) {
            temp_v0_3 = D_004F9E4C_1703E8 + 1;
            D_004F9E4C_1703E8 = temp_v0_3;
            if (temp_v0_3 == 0x259) {
                if (temp_a0 > 0) {
                    if (M2C_FIELD(((D_004F9E50_1703E8 * 0x220) + arg0), s32* , 0x10) != -1) {
                        func_0026B7A0_1703E8(M2C_FIELD(arg0, s32* , 0x2CF0), D_004F9E50_1703E8, &func_00168FB8_1703E8);
                        func_0026DFF8_1703E8();
                    }
                    temp_v0_4 = D_004F9E50_1703E8 + 1;
                    D_004F9E50_1703E8 = temp_v0_4;
                    if (temp_v0_4 >= 8) {
                        D_004F9E50_1703E8 = 0;
                    }
                }
                D_004F9E4C_1703E8 = 0;
            }
        }
        if (M2C_FIELD(arg0, s32* , 0x1BB4) > 0) {
            func_00266DB8_1703E8(&sp40);
            func_00266228_1703E8(&sp20);
            D_004F9E3C_1703E8 += 1;
            D_004F9E44_1703E8 += sp28;
            D_004F9E48_1703E8 += sp38;
            func_00266D78_1703E8(&sp44);
            if (((sp44 - M2C_FIELD(&D_002C1690_1703E8, s32* , 0x526DC)) >= 0x4E21) && (M2C_FIELD(&D_002C1690_1703E8, s32* , 8) >= 0) && (M2C_FIELD(arg0, s32* , 0x1BBC) != 0) && (M2C_FIELD(arg0, s32* , 0x2E90) == 0)) {
                if (func_001734B8_1703E8(&D_003156C0_1703E8) != 0) {
                    func_00166808_1703E8(&D_002C1690_1703E8, M2C_FIELD(&D_002C1690_1703E8, s32* , 0x52438));
                }
                func_00166940_1703E8(&D_002C1690_1703E8, M2C_FIELD(&D_002C1690_1703E8, s32* , 0x52438), M2C_FIELD(&D_002C1690_1703E8, s32* , 0x60));
                func_0025A020_1703E8();
                func_00266D78_1703E8(&D_00313D6C_1703E8);
            }
            if (M2C_FIELD(arg0, s32* , 0x1BB4) == 0xB) {
                if (func_001734B8_1703E8(arg0) != 0) {
                    temp_v0_5 = D_004F9E40_1703E8 + 1;
                    D_004F9E40_1703E8 = temp_v0_5;
                    if (temp_v0_5 >= 0x12DU) {
                        M2C_FIELD(M2C_FIELD(&D_003156C0_1703E8, void** , 0x3148), s8* , 0x24) = func_00176B10_1703E8(&D_003156C0_1703E8, 0);
                        D_004F9E40_1703E8 = 0;
                    }
                }
            }
        }
    }
}
//@@ func_001703E8 m2c3
#include "m2c_macros.h"
s32 func_0010A588_1703E8() __asm__("func_0010A588");
M2C_UNK func_00166808_1703E8() __asm__("func_00166808");
M2C_UNK func_00166940_1703E8() __asm__("func_00166940");
s32 func_0016D690_1703E8() __asm__("func_0016D690");
s32 func_001734B8_1703E8() __asm__("func_001734B8");
M2C_UNK func_00174D78_1703E8() __asm__("func_00174D78");
s8 func_00176B10_1703E8() __asm__("func_00176B10");
s32 func_0025A020_1703E8() __asm__("func_0025A020");
s32 func_0025C268_1703E8() __asm__("func_0025C268");
M2C_UNK func_00266228_1703E8() __asm__("func_00266228");
M2C_UNK func_00266D78_1703E8() __asm__("func_00266D78");
M2C_UNK func_00266DB8_1703E8() __asm__("func_00266DB8");
M2C_UNK func_0026B7A0_1703E8() __asm__("func_0026B7A0");
M2C_UNK func_0026DFF8_1703E8() __asm__("func_0026DFF8");
s32 func_0026E028_1703E8() __asm__("func_0026E028");
M2C_UNK func_0026E278_1703E8() __asm__("func_0026E278");
M2C_UNK printf_1703E8() __asm__("printf");
extern s32 D_002B8A00_1703E8 __asm__("D_002B8A00");
extern M2C_UNK D_002C1690_1703E8 __asm__("D_002C1690");
extern s32 D_00313D6C_1703E8 __asm__("D_00313D6C");
extern M2C_UNK D_003156C0_1703E8 __asm__("D_003156C0");
extern s32 D_004F9E3C_1703E8 __asm__("D_004F9E3C");
extern u32 D_004F9E40_1703E8 __asm__("D_004F9E40");
extern f32 D_004F9E44_1703E8 __asm__("D_004F9E44");
extern f32 D_004F9E48_1703E8 __asm__("D_004F9E48");
extern s32 D_004F9E4C_1703E8 __asm__("D_004F9E4C");
extern s32 D_004F9E50_1703E8 __asm__("D_004F9E50");
extern M2C_UNK func_00168FB8_1703E8 __asm__("func_00168FB8");

void func_001703E8(M2C_UNK* arg0) {
    u8 sp[0x20];
    M2C_UNK sp20;
    M2C_UNK sp40;
    s32 sp44;
    M2C_UNK* var_a0;
    s32 temp_a0;
    s32 temp_s0_2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 var_s1;
    s32 var_s2;
    s32* temp_s0;
    u32 temp_v0_5;

    var_s2 = 0;
    if (M2C_FIELD(arg0, s32* , 0x1BB8) == 5) {
        if (M2C_FIELD(arg0, s32* , 0x2E90) != 0) {
            var_s2 = func_0026E028_1703E8();
        } else {
            temp_v0 = func_0025A020_1703E8();
            if (temp_v0 != 0) {
                var_s2 = func_0025C268_1703E8(&D_002B8A00_1703E8);
                printf_1703E8("Medius Update returned an Error %d, NetError %d\n", temp_v0, var_s2);
            } else {
                temp_v0_2 = func_0010A588_1703E8(&D_002B8A00_1703E8);
                if (temp_v0_2 != 0) {
                    var_s1 = 0;
                    func_0026E278_1703E8(sp);
loop_7:
                    if (var_s1 < 4) {
                        temp_s0 = &(&sp4[0])[var_s1];
                        printf_1703E8("Connection %d Error = %d\n", var_s1, *temp_s0);
                        temp_s0_2 = *temp_s0;
                        if (temp_s0_2 == 0) {
                            var_s1 += 1;
                            goto loop_7;
                        }
                        var_s2 = temp_s0_2;
                    }
                    printf_1703E8("MGCL Update returned an Error %d - Connection Index %d, NetError %d\n", temp_v0_2, D_002B8A00_1703E8, var_s2);
                }
            }
        }
        if (func_0016D690_1703E8(arg0) == -1) {
            var_a0 = "InitCheckConnectionStatus returned an Error...\n";
            goto block_18;
        }
        if (var_s2 != 0) {
            printf_1703E8("NETWORK: Update Error = %d\n", var_s2);
            switch (var_s2) {                       /* irregular */
            case 2:
                var_a0 = "Update Error - Connection Lost\n";
block_18:
                printf_1703E8(var_a0);
                func_00174D78_1703E8(arg0, 6, 2);
                break;
            case 12:
                printf_1703E8("Update Error - Bad Packet received from the server\n");
                break;
            default:
                printf_1703E8("Update Error - Network Error\n");
                func_00174D78_1703E8(arg0, 6, 2);
                break;
            }
        }
        temp_a0 = M2C_FIELD(arg0, s32* , 0x1BB4);
        if ((u32) (temp_a0 - 1) < 6U) {
            temp_v0_3 = D_004F9E4C_1703E8 + 1;
            D_004F9E4C_1703E8 = temp_v0_3;
            if (temp_v0_3 == 0x259) {
                if (temp_a0 > 0) {
                    if (M2C_FIELD(((D_004F9E50_1703E8 * 0x220) + arg0), s32* , 0x10) != -1) {
                        func_0026B7A0_1703E8(M2C_FIELD(arg0, s32* , 0x2CF0), D_004F9E50_1703E8, &func_00168FB8_1703E8);
                        func_0026DFF8_1703E8();
                    }
                    temp_v0_4 = D_004F9E50_1703E8 + 1;
                    D_004F9E50_1703E8 = temp_v0_4;
                    if (temp_v0_4 >= 8) {
                        D_004F9E50_1703E8 = 0;
                    }
                }
                D_004F9E4C_1703E8 = 0;
            }
        }
        if (M2C_FIELD(arg0, s32* , 0x1BB4) > 0) {
            func_00266DB8_1703E8(&sp40);
            func_00266228_1703E8(&sp20);
            D_004F9E3C_1703E8 += 1;
            D_004F9E44_1703E8 += sp28;
            D_004F9E48_1703E8 += sp38;
            func_00266D78_1703E8(&sp44);
            if (((sp44 - M2C_FIELD(&D_002C1690_1703E8, s32* , 0x526DC)) >= 0x4E21) && (M2C_FIELD(&D_002C1690_1703E8, s32* , 8) >= 0) && (M2C_FIELD(arg0, s32* , 0x1BBC) != 0) && (M2C_FIELD(arg0, s32* , 0x2E90) == 0)) {
                if (func_001734B8_1703E8(&D_003156C0_1703E8) != 0) {
                    func_00166808_1703E8(&D_002C1690_1703E8, M2C_FIELD(&D_002C1690_1703E8, s32* , 0x52438));
                }
                func_00166940_1703E8(&D_002C1690_1703E8, M2C_FIELD(&D_002C1690_1703E8, s32* , 0x52438), M2C_FIELD(&D_002C1690_1703E8, s32* , 0x60));
                func_0025A020_1703E8();
                func_00266D78_1703E8(&D_00313D6C_1703E8);
            }
            if (M2C_FIELD(arg0, s32* , 0x1BB4) == 0xB) {
                if (func_001734B8_1703E8(arg0) != 0) {
                    temp_v0_5 = D_004F9E40_1703E8 + 1;
                    D_004F9E40_1703E8 = temp_v0_5;
                    if (temp_v0_5 >= 0x12DU) {
                        M2C_FIELD(M2C_FIELD(&D_003156C0_1703E8, void** , 0x3148), s8* , 0x24) = func_00176B10_1703E8(&D_003156C0_1703E8, 0);
                        D_004F9E40_1703E8 = 0;
                    }
                }
            }
        }
    }
}
//@@ func_001703E8 m2c4
#include "m2c_macros.h"
s32 func_0010A588_1703E8() __asm__("func_0010A588");
M2C_UNK func_00166808_1703E8() __asm__("func_00166808");
M2C_UNK func_00166940_1703E8() __asm__("func_00166940");
s32 func_0016D690_1703E8() __asm__("func_0016D690");
s32 func_001734B8_1703E8() __asm__("func_001734B8");
M2C_UNK func_00174D78_1703E8() __asm__("func_00174D78");
s8 func_00176B10_1703E8() __asm__("func_00176B10");
s32 func_0025A020_1703E8() __asm__("func_0025A020");
s32 func_0025C268_1703E8() __asm__("func_0025C268");
M2C_UNK func_00266228_1703E8() __asm__("func_00266228");
M2C_UNK func_00266D78_1703E8() __asm__("func_00266D78");
M2C_UNK func_00266DB8_1703E8() __asm__("func_00266DB8");
M2C_UNK func_0026B7A0_1703E8() __asm__("func_0026B7A0");
M2C_UNK func_0026DFF8_1703E8() __asm__("func_0026DFF8");
s32 func_0026E028_1703E8() __asm__("func_0026E028");
M2C_UNK func_0026E278_1703E8() __asm__("func_0026E278");
M2C_UNK printf_1703E8() __asm__("printf");
extern s32 D_002B8A00_1703E8 __asm__("D_002B8A00");
extern M2C_UNK D_002C1690_1703E8 __asm__("D_002C1690");
extern s32 D_00313D6C_1703E8 __asm__("D_00313D6C");
extern M2C_UNK D_003156C0_1703E8 __asm__("D_003156C0");
extern s32 D_004F9E3C_1703E8 __asm__("D_004F9E3C");
extern u32 D_004F9E40_1703E8 __asm__("D_004F9E40");
extern f32 D_004F9E44_1703E8 __asm__("D_004F9E44");
extern f32 D_004F9E48_1703E8 __asm__("D_004F9E48");
extern s32 D_004F9E4C_1703E8 __asm__("D_004F9E4C");
extern s32 D_004F9E50_1703E8 __asm__("D_004F9E50");
extern M2C_UNK func_00168FB8_1703E8 __asm__("func_00168FB8");

void func_001703E8(M2C_UNK* arg0) {
    u8 sp[0x10];
    M2C_UNK sp20;
    M2C_UNK sp40;
    s32 sp44;
    M2C_UNK* var_a0;
    s32 temp_a0;
    s32 temp_s0_2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 var_s1;
    s32 var_s2;
    s32* temp_s0;
    u32 temp_v0_5;

    var_s2 = 0;
    if (M2C_FIELD(arg0, s32* , 0x1BB8) == 5) {
        if (M2C_FIELD(arg0, s32* , 0x2E90) != 0) {
            var_s2 = func_0026E028_1703E8();
        } else {
            temp_v0 = func_0025A020_1703E8();
            if (temp_v0 != 0) {
                var_s2 = func_0025C268_1703E8(&D_002B8A00_1703E8);
                printf_1703E8("Medius Update returned an Error %d, NetError %d\n", temp_v0, var_s2);
            } else {
                temp_v0_2 = func_0010A588_1703E8(&D_002B8A00_1703E8);
                if (temp_v0_2 != 0) {
                    var_s1 = 0;
                    func_0026E278_1703E8(sp);
loop_7:
                    if (var_s1 < 4) {
                        temp_s0 = &(&sp4[0])[var_s1];
                        printf_1703E8("Connection %d Error = %d\n", var_s1, *temp_s0);
                        temp_s0_2 = *temp_s0;
                        if (temp_s0_2 == 0) {
                            var_s1 += 1;
                            goto loop_7;
                        }
                        var_s2 = temp_s0_2;
                    }
                    printf_1703E8("MGCL Update returned an Error %d - Connection Index %d, NetError %d\n", temp_v0_2, D_002B8A00_1703E8, var_s2);
                }
            }
        }
        if (func_0016D690_1703E8(arg0) == -1) {
            var_a0 = "InitCheckConnectionStatus returned an Error...\n";
            goto block_18;
        }
        if (var_s2 != 0) {
            printf_1703E8("NETWORK: Update Error = %d\n", var_s2);
            switch (var_s2) {                       /* irregular */
            case 2:
                var_a0 = "Update Error - Connection Lost\n";
block_18:
                printf_1703E8(var_a0);
                func_00174D78_1703E8(arg0, 6, 2);
                break;
            case 12:
                printf_1703E8("Update Error - Bad Packet received from the server\n");
                break;
            default:
                printf_1703E8("Update Error - Network Error\n");
                func_00174D78_1703E8(arg0, 6, 2);
                break;
            }
        }
        temp_a0 = M2C_FIELD(arg0, s32* , 0x1BB4);
        if ((u32) (temp_a0 - 1) < 6U) {
            temp_v0_3 = D_004F9E4C_1703E8 + 1;
            D_004F9E4C_1703E8 = temp_v0_3;
            if (temp_v0_3 == 0x259) {
                if (temp_a0 > 0) {
                    if (M2C_FIELD(((D_004F9E50_1703E8 * 0x220) + arg0), s32* , 0x10) != -1) {
                        func_0026B7A0_1703E8(M2C_FIELD(arg0, s32* , 0x2CF0), D_004F9E50_1703E8, &func_00168FB8_1703E8);
                        func_0026DFF8_1703E8();
                    }
                    temp_v0_4 = D_004F9E50_1703E8 + 1;
                    D_004F9E50_1703E8 = temp_v0_4;
                    if (temp_v0_4 >= 8) {
                        D_004F9E50_1703E8 = 0;
                    }
                }
                D_004F9E4C_1703E8 = 0;
            }
        }
        if (M2C_FIELD(arg0, s32* , 0x1BB4) > 0) {
            func_00266DB8_1703E8(&sp40);
            func_00266228_1703E8(&sp20);
            D_004F9E3C_1703E8 += 1;
            D_004F9E44_1703E8 += sp28;
            D_004F9E48_1703E8 += sp38;
            func_00266D78_1703E8(&sp44);
            if (((sp44 - M2C_FIELD(&D_002C1690_1703E8, s32* , 0x526DC)) >= 0x4E21) && (M2C_FIELD(&D_002C1690_1703E8, s32* , 8) >= 0) && (M2C_FIELD(arg0, s32* , 0x1BBC) != 0) && (M2C_FIELD(arg0, s32* , 0x2E90) == 0)) {
                if (func_001734B8_1703E8(&D_003156C0_1703E8) != 0) {
                    func_00166808_1703E8(&D_002C1690_1703E8, M2C_FIELD(&D_002C1690_1703E8, s32* , 0x52438));
                }
                func_00166940_1703E8(&D_002C1690_1703E8, M2C_FIELD(&D_002C1690_1703E8, s32* , 0x52438), M2C_FIELD(&D_002C1690_1703E8, s32* , 0x60));
                func_0025A020_1703E8();
                func_00266D78_1703E8(&D_00313D6C_1703E8);
            }
            if (M2C_FIELD(arg0, s32* , 0x1BB4) == 0xB) {
                if (func_001734B8_1703E8(arg0) != 0) {
                    temp_v0_5 = D_004F9E40_1703E8 + 1;
                    D_004F9E40_1703E8 = temp_v0_5;
                    if (temp_v0_5 >= 0x12DU) {
                        M2C_FIELD(M2C_FIELD(&D_003156C0_1703E8, void** , 0x3148), s8* , 0x24) = func_00176B10_1703E8(&D_003156C0_1703E8, 0);
                        D_004F9E40_1703E8 = 0;
                    }
                }
            }
        }
    }
}
//@@ func_001703E8 m2c5
#include "m2c_macros.h"
s32 func_0010A588_1703E8() __asm__("func_0010A588");
M2C_UNK func_00166808_1703E8() __asm__("func_00166808");
M2C_UNK func_00166940_1703E8() __asm__("func_00166940");
s32 func_0016D690_1703E8() __asm__("func_0016D690");
s32 func_001734B8_1703E8() __asm__("func_001734B8");
M2C_UNK func_00174D78_1703E8() __asm__("func_00174D78");
s8 func_00176B10_1703E8() __asm__("func_00176B10");
s32 func_0025A020_1703E8() __asm__("func_0025A020");
s32 func_0025C268_1703E8() __asm__("func_0025C268");
M2C_UNK func_00266228_1703E8() __asm__("func_00266228");
M2C_UNK func_00266D78_1703E8() __asm__("func_00266D78");
M2C_UNK func_00266DB8_1703E8() __asm__("func_00266DB8");
M2C_UNK func_0026B7A0_1703E8() __asm__("func_0026B7A0");
M2C_UNK func_0026DFF8_1703E8() __asm__("func_0026DFF8");
s32 func_0026E028_1703E8() __asm__("func_0026E028");
M2C_UNK func_0026E278_1703E8() __asm__("func_0026E278");
M2C_UNK printf_1703E8() __asm__("printf");
extern s32 D_002B8A00_1703E8 __asm__("D_002B8A00");
extern M2C_UNK D_002C1690_1703E8 __asm__("D_002C1690");
extern s32 D_00313D6C_1703E8 __asm__("D_00313D6C");
extern M2C_UNK D_003156C0_1703E8 __asm__("D_003156C0");
extern s32 D_004F9E3C_1703E8 __asm__("D_004F9E3C");
extern u32 D_004F9E40_1703E8 __asm__("D_004F9E40");
extern f32 D_004F9E44_1703E8 __asm__("D_004F9E44");
extern f32 D_004F9E48_1703E8 __asm__("D_004F9E48");
extern s32 D_004F9E4C_1703E8 __asm__("D_004F9E4C");
extern s32 D_004F9E50_1703E8 __asm__("D_004F9E50");
extern M2C_UNK func_00168FB8_1703E8 __asm__("func_00168FB8");

void func_001703E8(M2C_UNK* arg0) {
    u8 sp[0x8];
    M2C_UNK sp20;
    M2C_UNK sp40;
    s32 sp44;
    M2C_UNK* var_a0;
    s32 temp_a0;
    s32 temp_s0_2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 var_s1;
    s32 var_s2;
    s32* temp_s0;
    u32 temp_v0_5;

    var_s2 = 0;
    if (M2C_FIELD(arg0, s32* , 0x1BB8) == 5) {
        if (M2C_FIELD(arg0, s32* , 0x2E90) != 0) {
            var_s2 = func_0026E028_1703E8();
        } else {
            temp_v0 = func_0025A020_1703E8();
            if (temp_v0 != 0) {
                var_s2 = func_0025C268_1703E8(&D_002B8A00_1703E8);
                printf_1703E8("Medius Update returned an Error %d, NetError %d\n", temp_v0, var_s2);
            } else {
                temp_v0_2 = func_0010A588_1703E8(&D_002B8A00_1703E8);
                if (temp_v0_2 != 0) {
                    var_s1 = 0;
                    func_0026E278_1703E8(sp);
loop_7:
                    if (var_s1 < 4) {
                        temp_s0 = &(&sp4[0])[var_s1];
                        printf_1703E8("Connection %d Error = %d\n", var_s1, *temp_s0);
                        temp_s0_2 = *temp_s0;
                        if (temp_s0_2 == 0) {
                            var_s1 += 1;
                            goto loop_7;
                        }
                        var_s2 = temp_s0_2;
                    }
                    printf_1703E8("MGCL Update returned an Error %d - Connection Index %d, NetError %d\n", temp_v0_2, D_002B8A00_1703E8, var_s2);
                }
            }
        }
        if (func_0016D690_1703E8(arg0) == -1) {
            var_a0 = "InitCheckConnectionStatus returned an Error...\n";
            goto block_18;
        }
        if (var_s2 != 0) {
            printf_1703E8("NETWORK: Update Error = %d\n", var_s2);
            switch (var_s2) {                       /* irregular */
            case 2:
                var_a0 = "Update Error - Connection Lost\n";
block_18:
                printf_1703E8(var_a0);
                func_00174D78_1703E8(arg0, 6, 2);
                break;
            case 12:
                printf_1703E8("Update Error - Bad Packet received from the server\n");
                break;
            default:
                printf_1703E8("Update Error - Network Error\n");
                func_00174D78_1703E8(arg0, 6, 2);
                break;
            }
        }
        temp_a0 = M2C_FIELD(arg0, s32* , 0x1BB4);
        if ((u32) (temp_a0 - 1) < 6U) {
            temp_v0_3 = D_004F9E4C_1703E8 + 1;
            D_004F9E4C_1703E8 = temp_v0_3;
            if (temp_v0_3 == 0x259) {
                if (temp_a0 > 0) {
                    if (M2C_FIELD(((D_004F9E50_1703E8 * 0x220) + arg0), s32* , 0x10) != -1) {
                        func_0026B7A0_1703E8(M2C_FIELD(arg0, s32* , 0x2CF0), D_004F9E50_1703E8, &func_00168FB8_1703E8);
                        func_0026DFF8_1703E8();
                    }
                    temp_v0_4 = D_004F9E50_1703E8 + 1;
                    D_004F9E50_1703E8 = temp_v0_4;
                    if (temp_v0_4 >= 8) {
                        D_004F9E50_1703E8 = 0;
                    }
                }
                D_004F9E4C_1703E8 = 0;
            }
        }
        if (M2C_FIELD(arg0, s32* , 0x1BB4) > 0) {
            func_00266DB8_1703E8(&sp40);
            func_00266228_1703E8(&sp20);
            D_004F9E3C_1703E8 += 1;
            D_004F9E44_1703E8 += sp28;
            D_004F9E48_1703E8 += sp38;
            func_00266D78_1703E8(&sp44);
            if (((sp44 - M2C_FIELD(&D_002C1690_1703E8, s32* , 0x526DC)) >= 0x4E21) && (M2C_FIELD(&D_002C1690_1703E8, s32* , 8) >= 0) && (M2C_FIELD(arg0, s32* , 0x1BBC) != 0) && (M2C_FIELD(arg0, s32* , 0x2E90) == 0)) {
                if (func_001734B8_1703E8(&D_003156C0_1703E8) != 0) {
                    func_00166808_1703E8(&D_002C1690_1703E8, M2C_FIELD(&D_002C1690_1703E8, s32* , 0x52438));
                }
                func_00166940_1703E8(&D_002C1690_1703E8, M2C_FIELD(&D_002C1690_1703E8, s32* , 0x52438), M2C_FIELD(&D_002C1690_1703E8, s32* , 0x60));
                func_0025A020_1703E8();
                func_00266D78_1703E8(&D_00313D6C_1703E8);
            }
            if (M2C_FIELD(arg0, s32* , 0x1BB4) == 0xB) {
                if (func_001734B8_1703E8(arg0) != 0) {
                    temp_v0_5 = D_004F9E40_1703E8 + 1;
                    D_004F9E40_1703E8 = temp_v0_5;
                    if (temp_v0_5 >= 0x12DU) {
                        M2C_FIELD(M2C_FIELD(&D_003156C0_1703E8, void** , 0x3148), s8* , 0x24) = func_00176B10_1703E8(&D_003156C0_1703E8, 0);
                        D_004F9E40_1703E8 = 0;
                    }
                }
            }
        }
    }
}
//@@ func_00170760 m2c0
#include "m2c_macros.h"
M2C_UNK func_00109810_170760() __asm__("func_00109810");
M2C_UNK func_001E5790_170760() __asm__("func_001E5790");
M2C_UNK func_00266DB8_170760() __asm__("func_00266DB8");
M2C_UNK func_0026C948_170760() __asm__("func_0026C948");
s32 timerGetFieldCount__Fv_170760() __asm__("timerGetFieldCount__Fv");
extern s8 D_003184B6_170760 __asm__("D_003184B6");
extern s32 D_004F9D18_170760 __asm__("D_004F9D18");
extern s32 D_004F9DE4_170760 __asm__("D_004F9DE4");

void func_00170760(s32 arg0, void* arg1) {
    u8 sp[0x10];
    s32 sp4;
    s16 var_a1;
    s32 temp_a0_2;
    s32 var_a2;
    s32* temp_a0;
    s32* var_a0;
    u8 temp_v0_2;
    void* temp_a0_3;
    void* temp_a0_4;
    void* temp_v0;
    void* temp_v1;
    void* temp_v1_10;
    void* temp_v1_11;
    void* temp_v1_2;
    void* temp_v1_3;
    void* temp_v1_4;
    void* temp_v1_5;
    void* temp_v1_6;
    void* temp_v1_7;
    void* temp_v1_8;
    void* temp_v1_9;

    if ((arg1 != NULL) && (temp_v0 = M2C_FIELD(arg1, void** , 0x20D0), (temp_v0 != NULL))) {
        M2C_FIELD(temp_v0, u8* , 0x32) = 0U;
        if (((M2C_FIELD(arg1, s32* , 0x20F4) == 0xC0) && (M2C_FIELD(arg1, s32* , 0x24B4) != 0)) || ((M2C_FIELD(arg1, s32* , 0x20F4) == 0x160) && (M2C_FIELD(arg1, s32* , 0x24F0) == 2))) {
            temp_v1 = M2C_FIELD(arg1, void** , 0x20D0);
            M2C_FIELD(temp_v1, u8* , 0x32) = (u8) (M2C_FIELD(temp_v1, u8* , 0x32) | 1);
        }
        if (M2C_FIELD(M2C_FIELD(arg1, void** , 0x2028), u8* , 0xC) != 0) {
            temp_v1_2 = M2C_FIELD(arg1, void** , 0x20D0);
            M2C_FIELD(temp_v1_2, u8* , 0x32) = (u8) (M2C_FIELD(temp_v1_2, u8* , 0x32) | 2);
        }
        func_001E5790_170760(arg1, sp);
        if (subroutine_arg0 != 0) {
            temp_v1_3 = M2C_FIELD(arg1, void** , 0x20D0);
            M2C_FIELD(temp_v1_3, u8* , 0x32) = (u8) (M2C_FIELD(temp_v1_3, u8* , 0x32) | 4);
        }
        if (M2C_FIELD(arg1, s8* , 0x486) != 0) {
            temp_v1_4 = M2C_FIELD(arg1, void** , 0x20D0);
            M2C_FIELD(temp_v1_4, u8* , 0x32) = (u8) (M2C_FIELD(temp_v1_4, u8* , 0x32) | 8);
        }
        if (M2C_FIELD(arg1, s8* , 0x485) != 0) {
            temp_v1_5 = M2C_FIELD(arg1, void** , 0x20D0);
            M2C_FIELD(temp_v1_5, u8* , 0x32) = (u8) (M2C_FIELD(temp_v1_5, u8* , 0x32) | 0x20);
        }
        if (D_003184B6_170760 != 0) {
            temp_v1_6 = M2C_FIELD(arg1, void** , 0x20D0);
            M2C_FIELD(temp_v1_6, u8* , 0x32) = (u8) (M2C_FIELD(temp_v1_6, u8* , 0x32) | 0x40);
        }
        if (M2C_FIELD(arg1, s32* , 0x218C) != 0) {
            temp_v1_7 = M2C_FIELD(arg1, void** , 0x20D0);
            M2C_FIELD(temp_v1_7, u8* , 0x32) = (u8) (M2C_FIELD(temp_v1_7, u8* , 0x32) | 0x80);
        }
        temp_a0 = arg1 + 0x2338;
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), u8* , 0x2E) = (u8) M2C_FIELD(arg1, u8* , 0x590);
        if (*(temp_a0 + (M2C_FIELD(arg1, s32* , 0x21B0) * 4)) <= 0) {
            M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), u8* , 0x30) = 0U;
        } else {
            M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), u8* , 0x30) = (u8) M2C_FIELD(arg1, s32* , 0x21B0);
        }
        var_a0 = temp_a0;
        var_a2 = 0;
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), f32* , 0x1C) = (f32) M2C_FIELD(arg1, f32* , 0x404);
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), u16* , 0x2C) = 0U;
        do {
            if (*var_a0 != 0) {
                temp_v1_8 = M2C_FIELD(arg1, void** , 0x20D0);
                M2C_FIELD(temp_v1_8, u16* , 0x2C) = (u16) (((1 << var_a2) & 0xFFFF) | M2C_FIELD(temp_v1_8, u16* , 0x2C));
            }
            var_a2 += 1;
            var_a0 += 4;
        } while (var_a2 < 9);
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), u8* , 0x31) = (u8) M2C_FIELD(arg1, u8* , 0x22C0);
        var_a1 = (M2C_FIELD(arg1, s8* , 0x49B) == 0) ? 0 : 0x40;
        if (M2C_FIELD(arg1, s8* , 0x49E) != 0) {
            var_a1 = (var_a1 | 0x80) & 0xFF;
        }
        if (M2C_FIELD(arg1, s8* , 0x496) != 0) {
            var_a1 |= 0x20;
        }
        if (M2C_FIELD(arg1, s8* , 0x490) != 0) {
            var_a1 |= 8;
            temp_v0_2 = M2C_FIELD(arg1, u8* , 0x491) - 1;
            M2C_FIELD(arg1, u8* , 0x491) = temp_v0_2;
            if ((temp_v0_2 << 0x18) <= 0) {
                M2C_FIELD(arg1, s8* , 0x490) = 0;
            }
        }
        if (M2C_FIELD(arg1, s8* , 0x497) != 0) {
            var_a1 |= 0x10;
        }
        temp_a0_2 = M2C_FIELD(arg1, s32* , 0x20F4);
        if (temp_a0_2 == 0xA0) {
            var_a1 |= M2C_FIELD(arg1, u8* , 0x2508) & 7;
        }
        if (temp_a0_2 == 0x160) {
            if (M2C_FIELD(arg1, s32* , 0x242C) == 0) {
                goto block_42;
            }
        } else {
block_42:
            if ((temp_a0_2 == 0x120) && (M2C_FIELD(arg1, s32* , 0x242C) != 0)) {
                temp_v1_9 = M2C_FIELD(arg1, void** , 0x20D0);
                M2C_FIELD(temp_v1_9, u8* , 0x32) = (u8) (M2C_FIELD(temp_v1_9, u8* , 0x32) | 1);
            }
        }
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), s16* , 0x2A) = var_a1;
        temp_v1_10 = M2C_FIELD(arg1, void** , 0x20D0);
        M2C_FIELD(temp_v1_10, s16* , 0x24) = M2C_BITWISE(s16, M2C_FIELD(temp_v1_10, f32* , 4));
        temp_a0_3 = M2C_FIELD(arg1, void** , 0x20D0);
        M2C_FIELD(temp_a0_3, s16* , 0x26) = M2C_BITWISE(s16, M2C_FIELD(temp_a0_3, f32* , 8));
        temp_a0_4 = M2C_FIELD(arg1, void** , 0x20D0);
        if ((M2C_FIELD(temp_a0_4, s16* , 0x24) + M2C_FIELD(temp_a0_4, s16* , 0x26)) >= 0x321) {
            M2C_FIELD(temp_a0_4, s16* , 0x24) = 0;
            M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), s16* , 0x26) = 0;
        }
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), f32* , 4) = (f32) M2C_FIELD(M2C_FIELD(arg1, void** , 0x2028), f32* , 0x10);
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), f32* , 8) = (f32) M2C_FIELD(M2C_FIELD(arg1, void** , 0x2028), f32* , 0x14);
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), f32* , 0xC) = (f32) M2C_FIELD(M2C_FIELD(arg1, void** , 0x2028), f32* , 0x18);
        func_00266DB8_170760(&sp4, var_a1, var_a2, 1);
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), f32* , 0x20) = 16.6667f;
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), f32* , 0x10) = (f32) M2C_FIELD(arg1, f32* , 0x2D4);
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), f32* , 0x14) = (f32) M2C_FIELD(M2C_FIELD(arg1, void** , 0x2028), f32* , 0x68);
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), f32* , 0x18) = (f32) M2C_FIELD(arg1, f32* , 0x208);
        if (M2C_FIELD(arg1, s32* , 0x20B4) == 4) {
            func_00109810_170760(arg1, M2C_FIELD(arg1, s32* , 0x20D4));
        }
        if (timerGetFieldCount__Fv_170760() >= 0x5B) {
            if (D_004F9DE4_170760 == 0) {
                D_004F9DE4_170760 = 1;
                func_0026C948_170760(-1, D_004F9D18_170760);
            }
            temp_v1_11 = M2C_FIELD(arg1, void** , 0x20D0);
            M2C_FIELD(temp_v1_11, u8* , 0x32) = (u8) (M2C_FIELD(temp_v1_11, u8* , 0x32) | 0x10);
        }
    }
}
//@@ func_00170760 m2c1
#include "m2c_macros.h"
M2C_UNK func_00109810_170760() __asm__("func_00109810");
M2C_UNK func_001E5790_170760() __asm__("func_001E5790");
M2C_UNK func_00266DB8_170760() __asm__("func_00266DB8");
M2C_UNK func_0026C948_170760() __asm__("func_0026C948");
s32 timerGetFieldCount__Fv_170760() __asm__("timerGetFieldCount__Fv");
extern s8 D_003184B6_170760 __asm__("D_003184B6");
extern s32 D_004F9D18_170760 __asm__("D_004F9D18");
extern s32 D_004F9DE4_170760 __asm__("D_004F9DE4");

void func_00170760(s32 arg0, void* arg1) {
    u8 sp[0x8];
    s32 sp4;
    s16 var_a1;
    s32 temp_a0_2;
    s32 var_a2;
    s32* temp_a0;
    s32* var_a0;
    u8 temp_v0_2;
    void* temp_a0_3;
    void* temp_a0_4;
    void* temp_v0;
    void* temp_v1;
    void* temp_v1_10;
    void* temp_v1_11;
    void* temp_v1_2;
    void* temp_v1_3;
    void* temp_v1_4;
    void* temp_v1_5;
    void* temp_v1_6;
    void* temp_v1_7;
    void* temp_v1_8;
    void* temp_v1_9;

    if ((arg1 != NULL) && (temp_v0 = M2C_FIELD(arg1, void** , 0x20D0), (temp_v0 != NULL))) {
        M2C_FIELD(temp_v0, u8* , 0x32) = 0U;
        if (((M2C_FIELD(arg1, s32* , 0x20F4) == 0xC0) && (M2C_FIELD(arg1, s32* , 0x24B4) != 0)) || ((M2C_FIELD(arg1, s32* , 0x20F4) == 0x160) && (M2C_FIELD(arg1, s32* , 0x24F0) == 2))) {
            temp_v1 = M2C_FIELD(arg1, void** , 0x20D0);
            M2C_FIELD(temp_v1, u8* , 0x32) = (u8) (M2C_FIELD(temp_v1, u8* , 0x32) | 1);
        }
        if (M2C_FIELD(M2C_FIELD(arg1, void** , 0x2028), u8* , 0xC) != 0) {
            temp_v1_2 = M2C_FIELD(arg1, void** , 0x20D0);
            M2C_FIELD(temp_v1_2, u8* , 0x32) = (u8) (M2C_FIELD(temp_v1_2, u8* , 0x32) | 2);
        }
        func_001E5790_170760(arg1, sp);
        if (subroutine_arg0 != 0) {
            temp_v1_3 = M2C_FIELD(arg1, void** , 0x20D0);
            M2C_FIELD(temp_v1_3, u8* , 0x32) = (u8) (M2C_FIELD(temp_v1_3, u8* , 0x32) | 4);
        }
        if (M2C_FIELD(arg1, s8* , 0x486) != 0) {
            temp_v1_4 = M2C_FIELD(arg1, void** , 0x20D0);
            M2C_FIELD(temp_v1_4, u8* , 0x32) = (u8) (M2C_FIELD(temp_v1_4, u8* , 0x32) | 8);
        }
        if (M2C_FIELD(arg1, s8* , 0x485) != 0) {
            temp_v1_5 = M2C_FIELD(arg1, void** , 0x20D0);
            M2C_FIELD(temp_v1_5, u8* , 0x32) = (u8) (M2C_FIELD(temp_v1_5, u8* , 0x32) | 0x20);
        }
        if (D_003184B6_170760 != 0) {
            temp_v1_6 = M2C_FIELD(arg1, void** , 0x20D0);
            M2C_FIELD(temp_v1_6, u8* , 0x32) = (u8) (M2C_FIELD(temp_v1_6, u8* , 0x32) | 0x40);
        }
        if (M2C_FIELD(arg1, s32* , 0x218C) != 0) {
            temp_v1_7 = M2C_FIELD(arg1, void** , 0x20D0);
            M2C_FIELD(temp_v1_7, u8* , 0x32) = (u8) (M2C_FIELD(temp_v1_7, u8* , 0x32) | 0x80);
        }
        temp_a0 = arg1 + 0x2338;
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), u8* , 0x2E) = (u8) M2C_FIELD(arg1, u8* , 0x590);
        if (*(temp_a0 + (M2C_FIELD(arg1, s32* , 0x21B0) * 4)) <= 0) {
            M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), u8* , 0x30) = 0U;
        } else {
            M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), u8* , 0x30) = (u8) M2C_FIELD(arg1, s32* , 0x21B0);
        }
        var_a0 = temp_a0;
        var_a2 = 0;
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), f32* , 0x1C) = (f32) M2C_FIELD(arg1, f32* , 0x404);
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), u16* , 0x2C) = 0U;
        do {
            if (*var_a0 != 0) {
                temp_v1_8 = M2C_FIELD(arg1, void** , 0x20D0);
                M2C_FIELD(temp_v1_8, u16* , 0x2C) = (u16) (((1 << var_a2) & 0xFFFF) | M2C_FIELD(temp_v1_8, u16* , 0x2C));
            }
            var_a2 += 1;
            var_a0 += 4;
        } while (var_a2 < 9);
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), u8* , 0x31) = (u8) M2C_FIELD(arg1, u8* , 0x22C0);
        var_a1 = (M2C_FIELD(arg1, s8* , 0x49B) == 0) ? 0 : 0x40;
        if (M2C_FIELD(arg1, s8* , 0x49E) != 0) {
            var_a1 = (var_a1 | 0x80) & 0xFF;
        }
        if (M2C_FIELD(arg1, s8* , 0x496) != 0) {
            var_a1 |= 0x20;
        }
        if (M2C_FIELD(arg1, s8* , 0x490) != 0) {
            var_a1 |= 8;
            temp_v0_2 = M2C_FIELD(arg1, u8* , 0x491) - 1;
            M2C_FIELD(arg1, u8* , 0x491) = temp_v0_2;
            if ((temp_v0_2 << 0x18) <= 0) {
                M2C_FIELD(arg1, s8* , 0x490) = 0;
            }
        }
        if (M2C_FIELD(arg1, s8* , 0x497) != 0) {
            var_a1 |= 0x10;
        }
        temp_a0_2 = M2C_FIELD(arg1, s32* , 0x20F4);
        if (temp_a0_2 == 0xA0) {
            var_a1 |= M2C_FIELD(arg1, u8* , 0x2508) & 7;
        }
        if (temp_a0_2 == 0x160) {
            if (M2C_FIELD(arg1, s32* , 0x242C) == 0) {
                goto block_42;
            }
        } else {
block_42:
            if ((temp_a0_2 == 0x120) && (M2C_FIELD(arg1, s32* , 0x242C) != 0)) {
                temp_v1_9 = M2C_FIELD(arg1, void** , 0x20D0);
                M2C_FIELD(temp_v1_9, u8* , 0x32) = (u8) (M2C_FIELD(temp_v1_9, u8* , 0x32) | 1);
            }
        }
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), s16* , 0x2A) = var_a1;
        temp_v1_10 = M2C_FIELD(arg1, void** , 0x20D0);
        M2C_FIELD(temp_v1_10, s16* , 0x24) = M2C_BITWISE(s16, M2C_FIELD(temp_v1_10, f32* , 4));
        temp_a0_3 = M2C_FIELD(arg1, void** , 0x20D0);
        M2C_FIELD(temp_a0_3, s16* , 0x26) = M2C_BITWISE(s16, M2C_FIELD(temp_a0_3, f32* , 8));
        temp_a0_4 = M2C_FIELD(arg1, void** , 0x20D0);
        if ((M2C_FIELD(temp_a0_4, s16* , 0x24) + M2C_FIELD(temp_a0_4, s16* , 0x26)) >= 0x321) {
            M2C_FIELD(temp_a0_4, s16* , 0x24) = 0;
            M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), s16* , 0x26) = 0;
        }
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), f32* , 4) = (f32) M2C_FIELD(M2C_FIELD(arg1, void** , 0x2028), f32* , 0x10);
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), f32* , 8) = (f32) M2C_FIELD(M2C_FIELD(arg1, void** , 0x2028), f32* , 0x14);
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), f32* , 0xC) = (f32) M2C_FIELD(M2C_FIELD(arg1, void** , 0x2028), f32* , 0x18);
        func_00266DB8_170760(&sp4, var_a1, var_a2, 1);
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), f32* , 0x20) = 16.6667f;
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), f32* , 0x10) = (f32) M2C_FIELD(arg1, f32* , 0x2D4);
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), f32* , 0x14) = (f32) M2C_FIELD(M2C_FIELD(arg1, void** , 0x2028), f32* , 0x68);
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), f32* , 0x18) = (f32) M2C_FIELD(arg1, f32* , 0x208);
        if (M2C_FIELD(arg1, s32* , 0x20B4) == 4) {
            func_00109810_170760(arg1, M2C_FIELD(arg1, s32* , 0x20D4));
        }
        if (timerGetFieldCount__Fv_170760() >= 0x5B) {
            if (D_004F9DE4_170760 == 0) {
                D_004F9DE4_170760 = 1;
                func_0026C948_170760(-1, D_004F9D18_170760);
            }
            temp_v1_11 = M2C_FIELD(arg1, void** , 0x20D0);
            M2C_FIELD(temp_v1_11, u8* , 0x32) = (u8) (M2C_FIELD(temp_v1_11, u8* , 0x32) | 0x10);
        }
    }
}
//@@ func_00170760 m2c2
#include "m2c_macros.h"
M2C_UNK func_00109810_170760() __asm__("func_00109810");
M2C_UNK func_001E5790_170760() __asm__("func_001E5790");
M2C_UNK func_00266DB8_170760() __asm__("func_00266DB8");
M2C_UNK func_0026C948_170760() __asm__("func_0026C948");
s32 timerGetFieldCount__Fv_170760() __asm__("timerGetFieldCount__Fv");
extern s8 D_003184B6_170760 __asm__("D_003184B6");
extern s32 D_004F9D18_170760 __asm__("D_004F9D18");
extern s32 D_004F9DE4_170760 __asm__("D_004F9DE4");

void func_00170760(s32 arg0, void* arg1) {
    u8 sp[0x4];
    s32 sp4;
    s16 var_a1;
    s32 temp_a0_2;
    s32 var_a2;
    s32* temp_a0;
    s32* var_a0;
    u8 temp_v0_2;
    void* temp_a0_3;
    void* temp_a0_4;
    void* temp_v0;
    void* temp_v1;
    void* temp_v1_10;
    void* temp_v1_11;
    void* temp_v1_2;
    void* temp_v1_3;
    void* temp_v1_4;
    void* temp_v1_5;
    void* temp_v1_6;
    void* temp_v1_7;
    void* temp_v1_8;
    void* temp_v1_9;

    if ((arg1 != NULL) && (temp_v0 = M2C_FIELD(arg1, void** , 0x20D0), (temp_v0 != NULL))) {
        M2C_FIELD(temp_v0, u8* , 0x32) = 0U;
        if (((M2C_FIELD(arg1, s32* , 0x20F4) == 0xC0) && (M2C_FIELD(arg1, s32* , 0x24B4) != 0)) || ((M2C_FIELD(arg1, s32* , 0x20F4) == 0x160) && (M2C_FIELD(arg1, s32* , 0x24F0) == 2))) {
            temp_v1 = M2C_FIELD(arg1, void** , 0x20D0);
            M2C_FIELD(temp_v1, u8* , 0x32) = (u8) (M2C_FIELD(temp_v1, u8* , 0x32) | 1);
        }
        if (M2C_FIELD(M2C_FIELD(arg1, void** , 0x2028), u8* , 0xC) != 0) {
            temp_v1_2 = M2C_FIELD(arg1, void** , 0x20D0);
            M2C_FIELD(temp_v1_2, u8* , 0x32) = (u8) (M2C_FIELD(temp_v1_2, u8* , 0x32) | 2);
        }
        func_001E5790_170760(arg1, sp);
        if (subroutine_arg0 != 0) {
            temp_v1_3 = M2C_FIELD(arg1, void** , 0x20D0);
            M2C_FIELD(temp_v1_3, u8* , 0x32) = (u8) (M2C_FIELD(temp_v1_3, u8* , 0x32) | 4);
        }
        if (M2C_FIELD(arg1, s8* , 0x486) != 0) {
            temp_v1_4 = M2C_FIELD(arg1, void** , 0x20D0);
            M2C_FIELD(temp_v1_4, u8* , 0x32) = (u8) (M2C_FIELD(temp_v1_4, u8* , 0x32) | 8);
        }
        if (M2C_FIELD(arg1, s8* , 0x485) != 0) {
            temp_v1_5 = M2C_FIELD(arg1, void** , 0x20D0);
            M2C_FIELD(temp_v1_5, u8* , 0x32) = (u8) (M2C_FIELD(temp_v1_5, u8* , 0x32) | 0x20);
        }
        if (D_003184B6_170760 != 0) {
            temp_v1_6 = M2C_FIELD(arg1, void** , 0x20D0);
            M2C_FIELD(temp_v1_6, u8* , 0x32) = (u8) (M2C_FIELD(temp_v1_6, u8* , 0x32) | 0x40);
        }
        if (M2C_FIELD(arg1, s32* , 0x218C) != 0) {
            temp_v1_7 = M2C_FIELD(arg1, void** , 0x20D0);
            M2C_FIELD(temp_v1_7, u8* , 0x32) = (u8) (M2C_FIELD(temp_v1_7, u8* , 0x32) | 0x80);
        }
        temp_a0 = arg1 + 0x2338;
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), u8* , 0x2E) = (u8) M2C_FIELD(arg1, u8* , 0x590);
        if (*(temp_a0 + (M2C_FIELD(arg1, s32* , 0x21B0) * 4)) <= 0) {
            M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), u8* , 0x30) = 0U;
        } else {
            M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), u8* , 0x30) = (u8) M2C_FIELD(arg1, s32* , 0x21B0);
        }
        var_a0 = temp_a0;
        var_a2 = 0;
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), f32* , 0x1C) = (f32) M2C_FIELD(arg1, f32* , 0x404);
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), u16* , 0x2C) = 0U;
        do {
            if (*var_a0 != 0) {
                temp_v1_8 = M2C_FIELD(arg1, void** , 0x20D0);
                M2C_FIELD(temp_v1_8, u16* , 0x2C) = (u16) (((1 << var_a2) & 0xFFFF) | M2C_FIELD(temp_v1_8, u16* , 0x2C));
            }
            var_a2 += 1;
            var_a0 += 4;
        } while (var_a2 < 9);
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), u8* , 0x31) = (u8) M2C_FIELD(arg1, u8* , 0x22C0);
        var_a1 = (M2C_FIELD(arg1, s8* , 0x49B) == 0) ? 0 : 0x40;
        if (M2C_FIELD(arg1, s8* , 0x49E) != 0) {
            var_a1 = (var_a1 | 0x80) & 0xFF;
        }
        if (M2C_FIELD(arg1, s8* , 0x496) != 0) {
            var_a1 |= 0x20;
        }
        if (M2C_FIELD(arg1, s8* , 0x490) != 0) {
            var_a1 |= 8;
            temp_v0_2 = M2C_FIELD(arg1, u8* , 0x491) - 1;
            M2C_FIELD(arg1, u8* , 0x491) = temp_v0_2;
            if ((temp_v0_2 << 0x18) <= 0) {
                M2C_FIELD(arg1, s8* , 0x490) = 0;
            }
        }
        if (M2C_FIELD(arg1, s8* , 0x497) != 0) {
            var_a1 |= 0x10;
        }
        temp_a0_2 = M2C_FIELD(arg1, s32* , 0x20F4);
        if (temp_a0_2 == 0xA0) {
            var_a1 |= M2C_FIELD(arg1, u8* , 0x2508) & 7;
        }
        if (temp_a0_2 == 0x160) {
            if (M2C_FIELD(arg1, s32* , 0x242C) == 0) {
                goto block_42;
            }
        } else {
block_42:
            if ((temp_a0_2 == 0x120) && (M2C_FIELD(arg1, s32* , 0x242C) != 0)) {
                temp_v1_9 = M2C_FIELD(arg1, void** , 0x20D0);
                M2C_FIELD(temp_v1_9, u8* , 0x32) = (u8) (M2C_FIELD(temp_v1_9, u8* , 0x32) | 1);
            }
        }
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), s16* , 0x2A) = var_a1;
        temp_v1_10 = M2C_FIELD(arg1, void** , 0x20D0);
        M2C_FIELD(temp_v1_10, s16* , 0x24) = M2C_BITWISE(s16, M2C_FIELD(temp_v1_10, f32* , 4));
        temp_a0_3 = M2C_FIELD(arg1, void** , 0x20D0);
        M2C_FIELD(temp_a0_3, s16* , 0x26) = M2C_BITWISE(s16, M2C_FIELD(temp_a0_3, f32* , 8));
        temp_a0_4 = M2C_FIELD(arg1, void** , 0x20D0);
        if ((M2C_FIELD(temp_a0_4, s16* , 0x24) + M2C_FIELD(temp_a0_4, s16* , 0x26)) >= 0x321) {
            M2C_FIELD(temp_a0_4, s16* , 0x24) = 0;
            M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), s16* , 0x26) = 0;
        }
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), f32* , 4) = (f32) M2C_FIELD(M2C_FIELD(arg1, void** , 0x2028), f32* , 0x10);
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), f32* , 8) = (f32) M2C_FIELD(M2C_FIELD(arg1, void** , 0x2028), f32* , 0x14);
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), f32* , 0xC) = (f32) M2C_FIELD(M2C_FIELD(arg1, void** , 0x2028), f32* , 0x18);
        func_00266DB8_170760(&sp4, var_a1, var_a2, 1);
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), f32* , 0x20) = 16.6667f;
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), f32* , 0x10) = (f32) M2C_FIELD(arg1, f32* , 0x2D4);
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), f32* , 0x14) = (f32) M2C_FIELD(M2C_FIELD(arg1, void** , 0x2028), f32* , 0x68);
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), f32* , 0x18) = (f32) M2C_FIELD(arg1, f32* , 0x208);
        if (M2C_FIELD(arg1, s32* , 0x20B4) == 4) {
            func_00109810_170760(arg1, M2C_FIELD(arg1, s32* , 0x20D4));
        }
        if (timerGetFieldCount__Fv_170760() >= 0x5B) {
            if (D_004F9DE4_170760 == 0) {
                D_004F9DE4_170760 = 1;
                func_0026C948_170760(-1, D_004F9D18_170760);
            }
            temp_v1_11 = M2C_FIELD(arg1, void** , 0x20D0);
            M2C_FIELD(temp_v1_11, u8* , 0x32) = (u8) (M2C_FIELD(temp_v1_11, u8* , 0x32) | 0x10);
        }
    }
}
//@@ func_00170B68 m2c0
#include "m2c_macros.h"
s32 func_0026BD50_170B68() __asm__("func_0026BD50");
M2C_UNK memset_170B68() __asm__("memset");
void* netGetDmeTime_170B68() __asm__("netGetDmeTime");
extern s32 D_004F9CA0_170B68 __asm__("D_004F9CA0");
extern void* D_004FA030_170B68 __asm__("D_004FA030");

void func_00170B68(s32 arg0) {
    s32 temp_s0;
    s32 temp_s1;
    s32 var_s2;
    void* temp_a1;
    void* temp_a1_2;
    void* temp_v0;

    temp_a1 = D_004FA030_170B68;
    var_s2 = 0;
    if (M2C_FIELD(temp_a1, s32* , 0x96250) > 0) {
        do {
            temp_s1 = var_s2 * 0x110;
            temp_s0 = M2C_FIELD((temp_a1 + temp_s1), s32* , 0x9601C);
            if (temp_s0 != -1) {

            } else if (func_0026BD50_170B68(temp_a1 + (temp_s1 + 0x95F20) + 0xFC, 1, 3, 0) != 0) {
                M2C_FIELD((D_004FA030_170B68 + temp_s1), s32* , 0x9601C) = temp_s0;
            } else {
                temp_v0 = netGetDmeTime_170B68(arg0, M2C_FIELD((D_004FA030_170B68 + temp_s1), s32* , 0x9601C));
                memset_170B68(M2C_FIELD(temp_v0, void** , 0x1C), 0, 0x2C);
                M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), s32* , 0) = 0xB;
                temp_a1_2 = D_004FA030_170B68 + temp_s1;
                M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), s32* , 0x24) = 1;
                M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), s32* , 0x20) = (s32) M2C_FIELD(temp_a1_2, s32* , 0x95FCC);
                M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), f32* , 4) = (f32) M2C_FIELD(M2C_FIELD(temp_a1_2, void** , 0x95FC8), f32* , 0x10);
                M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), f32* , 8) = (f32) M2C_FIELD(M2C_FIELD(temp_a1_2, void** , 0x95FC8), f32* , 0x14);
                M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), f32* , 0xC) = (f32) M2C_FIELD(M2C_FIELD(temp_a1_2, void** , 0x95FC8), f32* , 0x18);
                M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), f32* , 0x10) = (f32) M2C_FIELD(M2C_FIELD(temp_a1_2, void** , 0x95FC8), f32* , 0x60);
                M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), f32* , 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_a1_2, void** , 0x95FC8), f32* , 0x64);
                M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), f32* , 0x18) = (f32) M2C_FIELD(M2C_FIELD(temp_a1_2, void** , 0x95FC8), f32* , 0x68);
                M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), s32* , 0x28) = var_s2;
            }
            var_s2 += 1;
        } while (var_s2 < M2C_FIELD(D_004FA030_170B68, s32* , 0x96250));
    }
}
//@@ func_00170D38 m2c0
#include "m2c_macros.h"
s32 func_0026BD50_170D38() __asm__("func_0026BD50");
M2C_UNK memset_170D38() __asm__("memset");
void* netGetDmeTime_170D38() __asm__("netGetDmeTime");
extern s32 D_004F9CA0_170D38 __asm__("D_004F9CA0");
extern M2C_UNK D_004F9E58_170D38 __asm__("D_004F9E58");

void func_00170D38(void* arg0) {
    s32 temp_s1;
    void* temp_v0;

    temp_s1 = M2C_FIELD(arg0, s32* , 0x2E9C);
    if (temp_s1 == -1) {
        if (func_0026BD50_170D38(arg0 + 0x2E9C, 1, 3, 0) != 0) {
            M2C_FIELD(arg0, s32* , 0x2E9C) = temp_s1;
        } else {
            temp_v0 = netGetDmeTime_170D38(arg0, M2C_FIELD(arg0, s32* , 0x2E9C));
            memset_170D38(M2C_FIELD(temp_v0, void** , 0x1C), 0, 0x2C);
            M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), s32* , 0) = 1;
            M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), s32* , 0x24) = 0;
        }
    }
}
//@@ func_00170DF0 m2c0
#include "m2c_macros.h"
M2C_UNK func_00170B68_170DF0() __asm__("func_00170B68");
M2C_UNK func_00170D38_170DF0() __asm__("func_00170D38");
s32 func_001734B8_170DF0() __asm__("func_001734B8");
s32 func_0026BD50_170DF0() __asm__("func_0026BD50");
M2C_UNK memset_170DF0() __asm__("memset");
void* netGetDmeTime_170DF0() __asm__("netGetDmeTime");
extern s32 D_004F9CA0_170DF0 __asm__("D_004F9CA0");
extern M2C_UNK D_004F9E60_170DF0 __asm__("D_004F9E60");
extern M2C_UNK D_004F9E68_170DF0 __asm__("D_004F9E68");
extern M2C_UNK D_004F9E70_170DF0 __asm__("D_004F9E70");
extern void* D_004FA030_170DF0 __asm__("D_004FA030");

void func_00170DF0(void* arg0, u32 arg1) {
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s0_5;
    s32 temp_s2;
    s32 temp_s2_2;
    s32 temp_s2_3;
    s32 var_v0;
    s32* var_v1;
    void* temp_a0;
    void* temp_a1;
    void* temp_v0;
    void* temp_v0_2;
    void* temp_v0_3;
    void* temp_v0_4;
    void* temp_v0_5;
    void* temp_v0_6;
    void* var_s0;

    if (func_001734B8_170DF0() != 0) {
        func_00170B68_170DF0(arg0);
        switch (arg1) {
        case 0:
        case 18:
            temp_s0 = M2C_FIELD(arg0, s32* , 0x2EAC);
            if (temp_s0 == -1) {
                if (func_0026BD50_170DF0(arg0 + 0x2EAC, 1, 3, 0) != 0) {
                    M2C_FIELD(arg0, s32* , 0x2EAC) = temp_s0;
                } else {
                    var_s0 = netGetDmeTime_170DF0(arg0, M2C_FIELD(arg0, s32* , 0x2EAC));
                    if (var_s0 != NULL) {
                        memset_170DF0(M2C_FIELD(var_s0, s32** , 0x1C), 0, 0x2C);
                        var_v1 = M2C_FIELD(var_s0, s32** , 0x1C);
                        var_v0 = 5;
block_52:
                        *var_v1 = var_v0;
                        M2C_FIELD(M2C_FIELD(var_s0, void** , 0x1C), s32* , 0x24) = 0;
                    }
                }
            default:
            }
            break;
        case 1:
        case 19:
            func_00170D38_170DF0(arg0);
            temp_s0_2 = M2C_FIELD(arg0, s32* , 0x2EA8);
            if (temp_s0_2 != -1) {

            } else if (func_0026BD50_170DF0(arg0 + 0x2EA8, 1, 3, 0) == 0) {
                temp_v0 = netGetDmeTime_170DF0(arg0, M2C_FIELD(arg0, s32* , 0x2EA8));
                memset_170DF0(M2C_FIELD(temp_v0, s32** , 0x1C), 0, 0x2C);
                M2C_FIELD(M2C_FIELD(temp_v0, s32** , 0x1C), s32* , 0) = 2;
                M2C_FIELD(M2C_FIELD(temp_v0, s32** , 0x1C), s32* , 0x24) = 0;
            } else {
                M2C_FIELD(arg0, s32* , 0x2EA8) = temp_s0_2;
            }
            if (M2C_FIELD(arg0, s32* , 0x2EA0) == -1) {
                if (func_0026BD50_170DF0(arg0 + 0x2EA0, 1, 3, 0) != 0) {
                    M2C_FIELD(arg0, s32* , 0x2EA0) = M2C_FIELD(arg0, s32* , 0x2EA0);
                } else {
                    var_s0 = netGetDmeTime_170DF0(arg0, M2C_FIELD(arg0, s32* , 0x2EA0));
                    memset_170DF0(M2C_FIELD(var_s0, s32** , 0x1C), 0, 0x2C);
                    var_v1 = M2C_FIELD(var_s0, s32** , 0x1C);
                    var_v0 = 4;
                    goto block_52;
                }
            }
            break;
        case 3:
            temp_s0_3 = M2C_FIELD(arg0, s32* , 0x2EB4);
            if (temp_s0_3 == -1) {
                if (func_0026BD50_170DF0(arg0 + 0x2EB4, 1, 3, 0) != 0) {
                    M2C_FIELD(arg0, s32* , 0x2EB4) = temp_s0_3;
                } else {
                    temp_v0_2 = netGetDmeTime_170DF0(arg0, M2C_FIELD(arg0, s32* , 0x2EB4));
                    memset_170DF0(M2C_FIELD(temp_v0_2, s32** , 0x1C), 0, 0x2C);
                    M2C_FIELD(M2C_FIELD(temp_v0_2, s32** , 0x1C), s32* , 0) = 6;
                    M2C_FIELD(M2C_FIELD(temp_v0_2, s32** , 0x1C), s32* , 0x24) = 1;
                    M2C_FIELD(M2C_FIELD(temp_v0_2, s32** , 0x1C), s32* , 0x20) = (s32) M2C_FIELD(D_004FA030_170DF0, s32* , 0x96844);
                    M2C_FIELD(M2C_FIELD(temp_v0_2, s32** , 0x1C), f32* , 4) = (f32) M2C_FIELD(M2C_FIELD(D_004FA030_170DF0, void** , 0x96840), f32* , 0x10);
                    M2C_FIELD(M2C_FIELD(temp_v0_2, s32** , 0x1C), f32* , 8) = (f32) M2C_FIELD(M2C_FIELD(D_004FA030_170DF0, void** , 0x96840), f32* , 0x14);
                    M2C_FIELD(M2C_FIELD(temp_v0_2, s32** , 0x1C), f32* , 0xC) = (f32) M2C_FIELD(M2C_FIELD(D_004FA030_170DF0, void** , 0x96840), f32* , 0x18);
                    M2C_FIELD(M2C_FIELD(temp_v0_2, s32** , 0x1C), f32* , 0x10) = (f32) M2C_FIELD(M2C_FIELD(D_004FA030_170DF0, void** , 0x96840), f32* , 0x60);
                    M2C_FIELD(M2C_FIELD(temp_v0_2, s32** , 0x1C), f32* , 0x14) = (f32) M2C_FIELD(M2C_FIELD(D_004FA030_170DF0, void** , 0x96840), f32* , 0x64);
                    M2C_FIELD(M2C_FIELD(temp_v0_2, s32** , 0x1C), f32* , 0x18) = (f32) M2C_FIELD(M2C_FIELD(D_004FA030_170DF0, void** , 0x96840), f32* , 0x68);
                }
            }
            break;
        case 5:
        case 17:
            temp_s0_4 = M2C_FIELD(arg0, s32* , 0x2EC0);
            temp_a1 = D_004FA030_170DF0;
            if (temp_s0_4 == -1) {
                if (func_0026BD50_170DF0(arg0 + 0x2EC0, 1, 3, 0) == 0) {
                    temp_v0_3 = netGetDmeTime_170DF0(arg0, M2C_FIELD(arg0, s32* , 0x2EC0));
                    memset_170DF0(M2C_FIELD(temp_v0_3, s32** , 0x1C), 0, 0x2C);
                    M2C_FIELD(M2C_FIELD(temp_v0_3, s32** , 0x1C), s32* , 0) = 7;
                    M2C_FIELD(M2C_FIELD(temp_v0_3, s32** , 0x1C), s32* , 0x24) = 1;
                    M2C_FIELD(M2C_FIELD(temp_v0_3, s32** , 0x1C), s32* , 0x20) = (s32) M2C_FIELD(D_004FA030_170DF0, s32* , 0x962F4);
                    M2C_FIELD(M2C_FIELD(temp_v0_3, s32** , 0x1C), f32* , 4) = (f32) M2C_FIELD(M2C_FIELD(D_004FA030_170DF0, void** , 0x962F0), f32* , 0x10);
                    M2C_FIELD(M2C_FIELD(temp_v0_3, s32** , 0x1C), f32* , 8) = (f32) M2C_FIELD(M2C_FIELD(D_004FA030_170DF0, void** , 0x962F0), f32* , 0x14);
                    M2C_FIELD(M2C_FIELD(temp_v0_3, s32** , 0x1C), f32* , 0xC) = (f32) M2C_FIELD(M2C_FIELD(D_004FA030_170DF0, void** , 0x962F0), f32* , 0x18);
                    M2C_FIELD(M2C_FIELD(temp_v0_3, s32** , 0x1C), f32* , 0x10) = (f32) M2C_FIELD(M2C_FIELD(D_004FA030_170DF0, void** , 0x962F0), f32* , 0x60);
                    M2C_FIELD(M2C_FIELD(temp_v0_3, s32** , 0x1C), f32* , 0x14) = (f32) M2C_FIELD(M2C_FIELD(D_004FA030_170DF0, void** , 0x962F0), f32* , 0x64);
                    M2C_FIELD(M2C_FIELD(temp_v0_3, s32** , 0x1C), f32* , 0x18) = (f32) M2C_FIELD(M2C_FIELD(D_004FA030_170DF0, void** , 0x962F0), f32* , 0x68);
                } else {
                    M2C_FIELD(arg0, s32* , 0x2EC0) = temp_s0_4;
                }
            }
            temp_s2 = M2C_FIELD(temp_a1, s32* , 0x968D8);
            if (temp_s2 != -1) {

            } else if (func_0026BD50_170DF0(temp_a1 + 0x968D8, 1, 3, 0) != 0) {
                M2C_FIELD(D_004FA030_170DF0, s32* , 0x968D8) = temp_s2;
            } else {
                temp_v0_4 = netGetDmeTime_170DF0(arg0, M2C_FIELD(D_004FA030_170DF0, s32* , 0x968D8));
                memset_170DF0(M2C_FIELD(temp_v0_4, s32** , 0x1C), 0, 0x2C);
                M2C_FIELD(M2C_FIELD(temp_v0_4, s32** , 0x1C), s32* , 0) = 8;
                M2C_FIELD(M2C_FIELD(temp_v0_4, s32** , 0x1C), s32* , 0x24) = 0;
            }
            temp_s2_2 = M2C_FIELD(D_004FA030_170DF0, s32* , 0x96968);
            if (temp_s2_2 == -1) {
                if (func_0026BD50_170DF0(D_004FA030_170DF0 + 0x96968, 1, 3, 0) != 0) {
                    M2C_FIELD(D_004FA030_170DF0, s32* , 0x96968) = temp_s2_2;
                } else {
                    temp_v0_5 = netGetDmeTime_170DF0(arg0, M2C_FIELD(D_004FA030_170DF0, s32* , 0x96968));
                    memset_170DF0(M2C_FIELD(temp_v0_5, s32** , 0x1C), 0, 0x2C);
                    M2C_FIELD(M2C_FIELD(temp_v0_5, s32** , 0x1C), s32* , 0) = 9;
                    M2C_FIELD(M2C_FIELD(temp_v0_5, s32** , 0x1C), s32* , 0x24) = 0;
                }
            }
            break;
        case 6:
            temp_a0 = D_004FA030_170DF0 + 0x3EAC0;
            temp_s2_3 = M2C_FIELD(temp_a0, s32* , 0x188);
            if (temp_s2_3 == -1) {
                if (func_0026BD50_170DF0(temp_a0 + 0x188, 1, 3, 0) != 0) {
                    M2C_FIELD((D_004FA030_170DF0 + 0x3EAC0), s32* , 0x188) = temp_s2_3;
                } else {
                    temp_v0_6 = netGetDmeTime_170DF0(arg0, M2C_FIELD((D_004FA030_170DF0 + 0x3EAC0), s32* , 0x188));
                    memset_170DF0(M2C_FIELD(temp_v0_6, s32** , 0x1C), 0, 0x2C);
                    M2C_FIELD(M2C_FIELD(temp_v0_6, s32** , 0x1C), s32* , 0) = 0xA;
                    M2C_FIELD(M2C_FIELD(temp_v0_6, s32** , 0x1C), s32* , 0x24) = 0;
                    M2C_FIELD(M2C_FIELD(temp_v0_6, s32** , 0x1C), s32* , 0x1C) = 0;
                }
            }
            break;
        case 7:
            func_00170D38_170DF0(arg0);
            break;
        case 10:
            temp_s0_5 = M2C_FIELD(arg0, s32* , 0x2EA8);
            if (temp_s0_5 == -1) {
                if (func_0026BD50_170DF0(arg0 + 0x2EA8, 1, 3, 0) != 0) {
                    M2C_FIELD(arg0, s32* , 0x2EA8) = temp_s0_5;
                } else {
                    var_s0 = netGetDmeTime_170DF0(arg0, M2C_FIELD(arg0, s32* , 0x2EA8));
                    memset_170DF0(M2C_FIELD(var_s0, s32** , 0x1C), 0, 0x2C);
                    var_v1 = M2C_FIELD(var_s0, s32** , 0x1C);
                    var_v0 = 2;
                    goto block_52;
                }
            }
            break;
        }
    }
}
//@@ func_001714D0 m2c0
#include "m2c_macros.h"
M2C_UNK func_00170760_1714D0() __asm__("func_00170760");
s32 func_001734B8_1714D0() __asm__("func_001734B8");
s32 func_00174268_1714D0() __asm__("func_00174268");
M2C_UNK func_00265180_1714D0() __asm__("func_00265180");
s32 func_0026BD50_1714D0() __asm__("func_0026BD50");
M2C_UNK hierSetCsDrawMe__FP3_csUc_1714D0() __asm__("hierSetCsDrawMe__FP3_csUc");
M2C_UNK memset_1714D0() __asm__("memset");
void* netGetDmeTime_1714D0() __asm__("netGetDmeTime");
M2C_UNK vehicleDisable__7Vehicle_1714D0() __asm__("vehicleDisable__7Vehicle");
M2C_UNK vehicleEnable__7Vehicle12VehicleTypes_1714D0() __asm__("vehicleEnable__7Vehicle12VehicleTypes");
extern M2C_UNK D_003156C0_1714D0 __asm__("D_003156C0");
extern M2C_UNK D_0041BF00_1714D0 __asm__("D_0041BF00");
extern M2C_UNK D_004E8528_1714D0 __asm__("D_004E8528");
extern s32 D_004F9CA4_1714D0 __asm__("D_004F9CA4");
extern s32 D_004F9D18_1714D0 __asm__("D_004F9D18");
extern s32 D_004FA030_1714D0 __asm__("D_004FA030");

void func_001714D0(void* arg0) {
    void* sp10;
    u16 sp38;
    u8 sp3E;
    void* sp50;
    s32 sp54;
    s32 temp_a0_2;
    s32 temp_a1;
    s32 var_a0;
    s32 var_a1;
    s32* temp_v1_4;
    void* temp_a0;
    void* temp_a2;
    void* temp_t4;
    void* temp_v1;
    void* temp_v1_2;
    void* temp_v1_3;
    void* temp_v1_5;

    temp_a2 = M2C_FIELD(arg0, void** , 4);
    temp_a0 = *(D_004FA030_1714D0 + 0x9E670 + ((func_00174268_1714D0(&D_003156C0_1714D0, M2C_FIELD(M2C_FIELD(arg0, void** , 4), s32* , 0)) - 1) * 4));
    temp_a1 = M2C_FIELD(temp_a2, s32* , 0xA4);
    if ((M2C_FIELD(temp_a0, s32* , 0x20F4) == temp_a1) && (M2C_FIELD(temp_a0, s32* , 0x20C4) == -1)) {
        M2C_FIELD(temp_a2, void** , 0xA0) = temp_a0;
        if (M2C_FIELD(&D_003156C0_1714D0, s32* , 0x3220) != 0) {
            var_a0 = 6;
        } else {
            var_a0 = 1;
        }
        M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), s32* , 0x20B4) = var_a0;
    }
    temp_v1 = M2C_FIELD(arg0, void** , 4);
    M2C_FIELD(M2C_FIELD(temp_v1, void** , 0xA0), s32* , 0x20C0) = (s32) M2C_FIELD(temp_v1, s32* , 0);
    vehicleDisable__7Vehicle_1714D0(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), temp_a1, temp_a2);
    temp_v1_2 = M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0);
    if (M2C_FIELD(temp_v1_2, s32* , 0x20F4) == 0x100) {
        temp_a0_2 = M2C_FIELD(temp_v1_2, s32* , 0x2038);
        if (temp_a0_2 != 0) {
            hierSetCsDrawMe__FP3_csUc_1714D0(temp_a0_2, 1);
        }
    }
    if (M2C_FIELD(arg0, s32* , 0x3220) != 0) {
        M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), s8* , 0x485) = 1;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), s8* , 0x488) = 1;
    } else {
        memset_1714D0(&sp10, 0, 0x38);
        temp_t4 = M2C_FIELD(arg0, void** , 4);
        sp38 = (u16) M2C_FIELD(temp_t4, s32* , 0xA4);
        sp10 = M2C_FIELD(temp_t4, void** , 0xA0);
        sp3E = M2C_FIELD(M2C_FIELD(temp_t4, void** , 0xA0), u8* , 0x590);
        temp_v1_3 = M2C_FIELD(arg0, void** , 4);
        if (func_0026BD50_1714D0(M2C_FIELD(temp_t4, void** , 0xA0) + 0x20C4, 1, 2, 0) != 0) {
            M2C_FIELD(M2C_FIELD(temp_v1_3, void** , 0xA0), s32* , 0x20C4) = -1;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), s32* , 0x20B8) = -1;
        } else {
            M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), s32* , 0x20D0) = (s32) M2C_FIELD(netGetDmeTime_1714D0(arg0, M2C_FIELD(M2C_FIELD(temp_v1_3, void** , 0xA0), s32* , 0x20C4)), s32* , 0x1C);
            func_00265180_1714D0(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), s32* , 0x20C4));
            if (func_001734B8_1714D0(arg0) != 0) {
                vehicleEnable__7Vehicle12VehicleTypes_1714D0(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), 1);
            }
        }
        if (D_004F9CA4_1714D0 >= 0) {
            memset_1714D0(&sp50, 0, 0x58);
            sp50 = (void* ) M2C_FIELD(M2C_FIELD(arg0, void** , 4), s32* , 0xA4);
            if (func_001734B8_1714D0(arg0) != 0) {
                var_a1 = 0;
                if (M2C_FIELD(arg0, s32* , 0x303C) == 0) {
                    M2C_FIELD(arg0, s32* , 0x303C) = 1;
                } else {
loop_20:
                    var_a1 += 1;
                    if (var_a1 < 8) {
                        temp_v1_4 = arg0 + 0x303C + (var_a1 * 4);
                        if (*temp_v1_4 == 0) {
                            *temp_v1_4 = 1;
                        } else {
                            goto loop_20;
                        }
                    }
                }
                sp54 = var_a1;
            } else {
                sp54 = -1;
            }
            if (func_0026BD50_1714D0(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0) + 0x20CC, 1, 2, 0) != 0) {
                M2C_FIELD(M2C_FIELD(arg0, void** , 4), s32* , 0x210) = 0;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), s32* , 0x20CC) = -1;
            } else {
                M2C_FIELD(M2C_FIELD(arg0, void** , 4), s32* , 0x210) = (s32) M2C_FIELD(netGetDmeTime_1714D0(arg0, M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), s32* , 0x20CC)), s32* , 0x1C);
                temp_v1_5 = M2C_FIELD(arg0, void** , 4);
                M2C_FIELD(M2C_FIELD(temp_v1_5, void** , 0xA0), s32* , 0x20D8) = (s32) M2C_FIELD(temp_v1_5, s32* , 0x210);
            }
        }
    }
    func_00170760_1714D0(arg0, M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0));
}
//@@ func_00171818 m2c0
#include "m2c_macros.h"
M2C_UNK func_0026BD50_171818() __asm__("func_0026BD50");
M2C_UNK memset_171818() __asm__("memset");
extern s32 D_004F9D24_171818 __asm__("D_004F9D24");
extern M2C_UNK D_004F9E78_171818 __asm__("D_004F9E78");
extern void* D_004FA030_171818 __asm__("D_004FA030");

s32 func_00171818(s32 arg0, void* arg1, s32 arg2) {
    void* sp10;
    u8 sp14;
    s8 sp15;
    u8 sp16;
    u8 sp17;
    u8 sp18;
    u16 sp1A;
    u8 sp1C;
    u16 sp1E;
    u16 sp20;
    u16 sp22;
    f32 sp24;
    f32 sp28;
    f32 sp2C;
    f32 sp3C;
    f32 sp40;
    f32 sp44;
    f32 sp48;
    M2C_UNK sp4C;
    M2C_UNK sp54;
    s32 temp_t0;
    s32 temp_v1_2;
    s32 var_a1;
    s8* temp_v1;
    u16 var_v0_2;
    u16 var_v1;
    u8 var_v0;
    void* temp_a1;
    void* temp_a1_2;
    void* temp_a1_3;
    void* temp_v0;

    memset_171818(&sp10, 0, 0x4C);
    temp_a1 = M2C_FIELD(arg1, void** , 0x130);
    sp15 = 1;
    sp16 = M2C_FIELD(arg1, u8* , 0x14);
    sp10 = arg1;
    sp14 = 0;
    sp1A = M2C_FIELD(temp_a1, u16* , 0x20F4);
    if (M2C_FIELD(temp_a1, s32* , 0x590) == 1) {
        var_v0 = (u8) M2C_FIELD(temp_a1, s32* , 0x590);
    } else {
        var_v0 = -3U;
        if (temp_a1 == M2C_FIELD(D_004FA030_171818, s32* , 0x9E690)) {
            var_v0 = -2U;
        }
    }
    sp1C = var_v0;
    temp_t0 = (s32) M2C_FIELD(arg1, u8* , 0x14);
    if (temp_t0 != 1) {
        temp_a1_2 = M2C_FIELD(arg1, void** , 0x150);
        temp_v0 = M2C_FIELD(arg1, void** , 0x130) + (temp_t0 * 4);
        sp17 = M2C_FIELD(temp_v0, u8* , 0x22AC);
        sp18 = M2C_FIELD(temp_v0, u8* , 0x2338);
        sp24 = M2C_FIELD(temp_a1_2, f32* , 0x10);
        sp28 = M2C_FIELD(temp_a1_2, f32* , 0x14);
        sp2C = M2C_FIELD(temp_a1_2, f32* , 0x18);
        sp3C = M2C_FIELD(temp_a1_2, f32* , 0x60);
        sp40 = M2C_FIELD(temp_a1_2, f32* , 0x64);
        sp48 = M2C_FIELD(arg1, f32* , 0xB4);
        sp44 = M2C_FIELD(temp_a1_2, f32* , 0x68);
        if ((temp_t0 == 0x11) && ((s16) sp1A == 0x20)) {
            sp14 = M2C_FIELD(M2C_FIELD(arg1, void** , 0x130), u8* , 0x2508);
        }
    } else {
        switch ((s16) sp1A) {                       /* irregular */
        case 0xA0:
            sp14 = M2C_FIELD(arg1, u8* , 0x24);
            sp17 = M2C_FIELD(arg1, u8* , 0x18);
            sp18 = M2C_FIELD(arg1, u8* , 4);
            break;
        case 0x1E0:
            /* fallthrough */
        case 0x180:
            sp17 = M2C_FIELD(arg1, u8* , 0x18);
            sp18 = M2C_FIELD(arg1, u8* , 4);
            break;
        }
    }
    temp_a1_3 = M2C_FIELD(arg1, void** , 0x134);
    if (temp_a1_3 != NULL) {
        if (M2C_FIELD(temp_a1_3, s32* , 0x590) != 2) {
            sp1E = M2C_FIELD(temp_a1_3, u16* , 0x20F4);
            sp20 = M2C_FIELD(temp_a1_3, u16* , 0x20C0);
        } else {
            var_v0_2 = -3U;
            if (temp_a1_3 == M2C_FIELD(D_004FA030_171818, s32* , 0x9E690)) {
                var_v0_2 = -2U;
            }
            sp1E = var_v0_2;
            sp20 = 0;
        }
        sp22 = -1U;
    } else {
        var_v1 = -1U;
        sp1E = -1U;
        sp20 = -1U;
        if (M2C_FIELD(arg1, s32* , 0x13C) != 0) {
            var_v1 = M2C_FIELD(M2C_FIELD(arg1, void** , 0x130), u16* , 0x20B0);
        }
        sp22 = var_v1;
    }
    var_a1 = 0;
    do {
        temp_v1 = &sp54 + var_a1;
        *(&sp4C + var_a1) = -1;
        var_a1 += 1;
        *temp_v1 = 0;
    } while (var_a1 < 8);
    temp_v1_2 = (s32) M2C_FIELD(arg1, u8* , 0x14);
    if (((temp_v1_2 == 4) || (temp_v1_2 == 0x1C)) && (M2C_FIELD(arg1, s32* , 0x20) != 0)) {
        sp14 = 0x20;
    }
    if (arg2 != 0) {
        sp17 = 0x7F;
    }
    func_0026BD50_171818(arg1 + 0x50, 1, 2, 0);
    return M2C_FIELD(arg1, s32* , 0x50);
}
//@@ func_00171AA8 m2c0
#include "m2c_macros.h"
M2C_UNK func_0026C948_171AA8() __asm__("func_0026C948");
void* netGetDmeTime_171AA8() __asm__("netGetDmeTime");
extern M2C_UNK D_003156C0_171AA8 __asm__("D_003156C0");

void func_00171AA8(s32 arg0, void* arg1, void* arg2, s8 arg3) {
    s32 temp_a0;
    u8 var_v0;
    void* temp_v1;

    temp_v1 = M2C_FIELD(netGetDmeTime_171AA8(&D_003156C0_171AA8, M2C_FIELD(arg1, s32* , 0x50)), void** , 0x1C);
    M2C_FIELD(temp_v1, s8* , 4) = arg3;
    M2C_FIELD(temp_v1, f32* , 0x14) = (f32) M2C_FIELD(M2C_FIELD(arg1, void** , 0x150), f32* , 0x10);
    M2C_FIELD(temp_v1, f32* , 0x18) = (f32) M2C_FIELD(M2C_FIELD(arg1, void** , 0x150), f32* , 0x14);
    M2C_FIELD(temp_v1, f32* , 0x1C) = (f32) M2C_FIELD(M2C_FIELD(arg1, void** , 0x150), f32* , 0x18);
    if (arg2 != NULL) {
        M2C_FIELD(temp_v1, u8* , 0x3C) = (u8) M2C_FIELD(arg2, u8* , 0x20C4);
    }
    temp_a0 = M2C_FIELD(arg1, s32* , 0x14);
    if (temp_a0 != 4) {
        var_v0 = M2C_FIELD(arg1, u8* , 8);
        goto block_7;
    }
    if (arg3 == temp_a0) {
        var_v0 = 0xA;
block_7:
        M2C_FIELD(temp_v1, u8* , 0x44) = var_v0;
    }
    func_0026C948_171AA8(-1, M2C_FIELD(arg1, s32* , 0x50));
}
//@@ func_00171B78 m2c0
#include "m2c_macros.h"
M2C_UNK netSendSessionMsg_171B78() __asm__("netSendSessionMsg");
M2C_UNK strncpy_171B78() __asm__("strncpy");

void func_00171B78(void* arg0, M2C_UNK arg1) {
    u8 sp[0xF0];
    M2C_UNK sp18;
    s8 sp27;
    f32 sp30;
    f32 sp34;
    f32 sp38;
    f32 sp3C;
    s32 sp40;
    void* temp_a1;
    void* temp_v0;

    temp_a1 = M2C_FIELD(arg0, void** , 4);
    strncpy_171B78(&sp18, temp_a1 + 8, 0xF, M2C_FIELD(temp_a1, s32* , 0xA4));
    sp27 = 0;
    temp_v0 = M2C_FIELD(arg0, void** , 4);
    sp30 = M2C_FIELD(temp_v0, f32* , 0x90);
    sp34 = M2C_FIELD(temp_v0, f32* , 0x94);
    sp38 = M2C_FIELD(temp_v0, f32* , 0x98);
    sp40 = M2C_FIELD(arg0, s32* , 0x1BB4);
    sp3C = M2C_FIELD(temp_v0, f32* , 0x9C);
    netSendSessionMsg_171B78(arg0, arg1, sp);
}
//@@ func_00171B78 m2c1
#include "m2c_macros.h"
M2C_UNK netSendSessionMsg_171B78() __asm__("netSendSessionMsg");
M2C_UNK strncpy_171B78() __asm__("strncpy");

void func_00171B78(void* arg0, M2C_UNK arg1) {
    u8 sp[0xE0];
    M2C_UNK sp18;
    s8 sp27;
    f32 sp30;
    f32 sp34;
    f32 sp38;
    f32 sp3C;
    s32 sp40;
    void* temp_a1;
    void* temp_v0;

    temp_a1 = M2C_FIELD(arg0, void** , 4);
    strncpy_171B78(&sp18, temp_a1 + 8, 0xF, M2C_FIELD(temp_a1, s32* , 0xA4));
    sp27 = 0;
    temp_v0 = M2C_FIELD(arg0, void** , 4);
    sp30 = M2C_FIELD(temp_v0, f32* , 0x90);
    sp34 = M2C_FIELD(temp_v0, f32* , 0x94);
    sp38 = M2C_FIELD(temp_v0, f32* , 0x98);
    sp40 = M2C_FIELD(arg0, s32* , 0x1BB4);
    sp3C = M2C_FIELD(temp_v0, f32* , 0x9C);
    netSendSessionMsg_171B78(arg0, arg1, sp);
}
//@@ func_00171B78 m2c2
#include "m2c_macros.h"
M2C_UNK netSendSessionMsg_171B78() __asm__("netSendSessionMsg");
M2C_UNK strncpy_171B78() __asm__("strncpy");

void func_00171B78(void* arg0, M2C_UNK arg1) {
    u8 sp[0xD0];
    M2C_UNK sp18;
    s8 sp27;
    f32 sp30;
    f32 sp34;
    f32 sp38;
    f32 sp3C;
    s32 sp40;
    void* temp_a1;
    void* temp_v0;

    temp_a1 = M2C_FIELD(arg0, void** , 4);
    strncpy_171B78(&sp18, temp_a1 + 8, 0xF, M2C_FIELD(temp_a1, s32* , 0xA4));
    sp27 = 0;
    temp_v0 = M2C_FIELD(arg0, void** , 4);
    sp30 = M2C_FIELD(temp_v0, f32* , 0x90);
    sp34 = M2C_FIELD(temp_v0, f32* , 0x94);
    sp38 = M2C_FIELD(temp_v0, f32* , 0x98);
    sp40 = M2C_FIELD(arg0, s32* , 0x1BB4);
    sp3C = M2C_FIELD(temp_v0, f32* , 0x9C);
    netSendSessionMsg_171B78(arg0, arg1, sp);
}
//@@ func_00171B78 m2c3
#include "m2c_macros.h"
M2C_UNK netSendSessionMsg_171B78() __asm__("netSendSessionMsg");
M2C_UNK strncpy_171B78() __asm__("strncpy");

void func_00171B78(void* arg0, M2C_UNK arg1) {
    u8 sp[0xC0];
    M2C_UNK sp18;
    s8 sp27;
    f32 sp30;
    f32 sp34;
    f32 sp38;
    f32 sp3C;
    s32 sp40;
    void* temp_a1;
    void* temp_v0;

    temp_a1 = M2C_FIELD(arg0, void** , 4);
    strncpy_171B78(&sp18, temp_a1 + 8, 0xF, M2C_FIELD(temp_a1, s32* , 0xA4));
    sp27 = 0;
    temp_v0 = M2C_FIELD(arg0, void** , 4);
    sp30 = M2C_FIELD(temp_v0, f32* , 0x90);
    sp34 = M2C_FIELD(temp_v0, f32* , 0x94);
    sp38 = M2C_FIELD(temp_v0, f32* , 0x98);
    sp40 = M2C_FIELD(arg0, s32* , 0x1BB4);
    sp3C = M2C_FIELD(temp_v0, f32* , 0x9C);
    netSendSessionMsg_171B78(arg0, arg1, sp);
}
//@@ func_00171B78 m2c4
#include "m2c_macros.h"
M2C_UNK netSendSessionMsg_171B78() __asm__("netSendSessionMsg");
M2C_UNK strncpy_171B78() __asm__("strncpy");

void func_00171B78(void* arg0, M2C_UNK arg1) {
    u8 sp[0xB0];
    M2C_UNK sp18;
    s8 sp27;
    f32 sp30;
    f32 sp34;
    f32 sp38;
    f32 sp3C;
    s32 sp40;
    void* temp_a1;
    void* temp_v0;

    temp_a1 = M2C_FIELD(arg0, void** , 4);
    strncpy_171B78(&sp18, temp_a1 + 8, 0xF, M2C_FIELD(temp_a1, s32* , 0xA4));
    sp27 = 0;
    temp_v0 = M2C_FIELD(arg0, void** , 4);
    sp30 = M2C_FIELD(temp_v0, f32* , 0x90);
    sp34 = M2C_FIELD(temp_v0, f32* , 0x94);
    sp38 = M2C_FIELD(temp_v0, f32* , 0x98);
    sp40 = M2C_FIELD(arg0, s32* , 0x1BB4);
    sp3C = M2C_FIELD(temp_v0, f32* , 0x9C);
    netSendSessionMsg_171B78(arg0, arg1, sp);
}
//@@ func_00171B78 m2c5
#include "m2c_macros.h"
M2C_UNK netSendSessionMsg_171B78() __asm__("netSendSessionMsg");
M2C_UNK strncpy_171B78() __asm__("strncpy");

void func_00171B78(void* arg0, M2C_UNK arg1) {
    u8 sp[0xA0];
    M2C_UNK sp18;
    s8 sp27;
    f32 sp30;
    f32 sp34;
    f32 sp38;
    f32 sp3C;
    s32 sp40;
    void* temp_a1;
    void* temp_v0;

    temp_a1 = M2C_FIELD(arg0, void** , 4);
    strncpy_171B78(&sp18, temp_a1 + 8, 0xF, M2C_FIELD(temp_a1, s32* , 0xA4));
    sp27 = 0;
    temp_v0 = M2C_FIELD(arg0, void** , 4);
    sp30 = M2C_FIELD(temp_v0, f32* , 0x90);
    sp34 = M2C_FIELD(temp_v0, f32* , 0x94);
    sp38 = M2C_FIELD(temp_v0, f32* , 0x98);
    sp40 = M2C_FIELD(arg0, s32* , 0x1BB4);
    sp3C = M2C_FIELD(temp_v0, f32* , 0x9C);
    netSendSessionMsg_171B78(arg0, arg1, sp);
}
//@@ func_00171C08 m2c0
#include "m2c_macros.h"
M2C_UNK dmeSendMsgToClient_171C08() __asm__("dmeSendMsgToClient");
M2C_UNK func_00266708_171C08() __asm__("func_00266708");
M2C_UNK strcpy_171C08() __asm__("strcpy");
extern s32 D_004F9D80_171C08 __asm__("D_004F9D80");

void func_00171C08(void* arg0) {
    u8 sp[0x60];
    s8 sp50;
    s32 temp_a2;
    s32 var_s0;

    var_s0 = 0;
    strcpy_171C08(sp);
loop_1:
    func_00266708_171C08(&sp50, M2C_FIELD(arg0, s32* , 0x2CF0), var_s0);
    temp_a2 = var_s0;
    var_s0 += 1;
    if (sp50 != 0) {
        dmeSendMsgToClient_171C08(0x40, M2C_FIELD(arg0, s32* , 0x2CF0), temp_a2, D_004F9D80_171C08);
    }
    if (var_s0 < 8) {
        goto loop_1;
    }
}
//@@ func_00171C08 m2c1
#include "m2c_macros.h"
M2C_UNK dmeSendMsgToClient_171C08() __asm__("dmeSendMsgToClient");
M2C_UNK func_00266708_171C08() __asm__("func_00266708");
M2C_UNK strcpy_171C08() __asm__("strcpy");
extern s32 D_004F9D80_171C08 __asm__("D_004F9D80");

void func_00171C08(void* arg0) {
    u8 sp[0x50];
    s8 sp50;
    s32 temp_a2;
    s32 var_s0;

    var_s0 = 0;
    strcpy_171C08(sp);
loop_1:
    func_00266708_171C08(&sp50, M2C_FIELD(arg0, s32* , 0x2CF0), var_s0);
    temp_a2 = var_s0;
    var_s0 += 1;
    if (sp50 != 0) {
        dmeSendMsgToClient_171C08(0x40, M2C_FIELD(arg0, s32* , 0x2CF0), temp_a2, D_004F9D80_171C08);
    }
    if (var_s0 < 8) {
        goto loop_1;
    }
}
//@@ func_00171C08 m2c2
#include "m2c_macros.h"
M2C_UNK dmeSendMsgToClient_171C08() __asm__("dmeSendMsgToClient");
M2C_UNK func_00266708_171C08() __asm__("func_00266708");
M2C_UNK strcpy_171C08() __asm__("strcpy");
extern s32 D_004F9D80_171C08 __asm__("D_004F9D80");

void func_00171C08(void* arg0) {
    u8 sp[0x40];
    s8 sp50;
    s32 temp_a2;
    s32 var_s0;

    var_s0 = 0;
    strcpy_171C08(sp);
loop_1:
    func_00266708_171C08(&sp50, M2C_FIELD(arg0, s32* , 0x2CF0), var_s0);
    temp_a2 = var_s0;
    var_s0 += 1;
    if (sp50 != 0) {
        dmeSendMsgToClient_171C08(0x40, M2C_FIELD(arg0, s32* , 0x2CF0), temp_a2, D_004F9D80_171C08);
    }
    if (var_s0 < 8) {
        goto loop_1;
    }
}
//@@ func_00171C08 m2c3
#include "m2c_macros.h"
M2C_UNK dmeSendMsgToClient_171C08() __asm__("dmeSendMsgToClient");
M2C_UNK func_00266708_171C08() __asm__("func_00266708");
M2C_UNK strcpy_171C08() __asm__("strcpy");
extern s32 D_004F9D80_171C08 __asm__("D_004F9D80");

void func_00171C08(void* arg0) {
    u8 sp[0x30];
    s8 sp50;
    s32 temp_a2;
    s32 var_s0;

    var_s0 = 0;
    strcpy_171C08(sp);
loop_1:
    func_00266708_171C08(&sp50, M2C_FIELD(arg0, s32* , 0x2CF0), var_s0);
    temp_a2 = var_s0;
    var_s0 += 1;
    if (sp50 != 0) {
        dmeSendMsgToClient_171C08(0x40, M2C_FIELD(arg0, s32* , 0x2CF0), temp_a2, D_004F9D80_171C08);
    }
    if (var_s0 < 8) {
        goto loop_1;
    }
}
//@@ func_00171C08 m2c4
#include "m2c_macros.h"
M2C_UNK dmeSendMsgToClient_171C08() __asm__("dmeSendMsgToClient");
M2C_UNK func_00266708_171C08() __asm__("func_00266708");
M2C_UNK strcpy_171C08() __asm__("strcpy");
extern s32 D_004F9D80_171C08 __asm__("D_004F9D80");

void func_00171C08(void* arg0) {
    u8 sp[0x20];
    s8 sp50;
    s32 temp_a2;
    s32 var_s0;

    var_s0 = 0;
    strcpy_171C08(sp);
loop_1:
    func_00266708_171C08(&sp50, M2C_FIELD(arg0, s32* , 0x2CF0), var_s0);
    temp_a2 = var_s0;
    var_s0 += 1;
    if (sp50 != 0) {
        dmeSendMsgToClient_171C08(0x40, M2C_FIELD(arg0, s32* , 0x2CF0), temp_a2, D_004F9D80_171C08);
    }
    if (var_s0 < 8) {
        goto loop_1;
    }
}
//@@ func_00171C08 m2c5
#include "m2c_macros.h"
M2C_UNK dmeSendMsgToClient_171C08() __asm__("dmeSendMsgToClient");
M2C_UNK func_00266708_171C08() __asm__("func_00266708");
M2C_UNK strcpy_171C08() __asm__("strcpy");
extern s32 D_004F9D80_171C08 __asm__("D_004F9D80");

void func_00171C08(void* arg0) {
    u8 sp[0x10];
    s8 sp50;
    s32 temp_a2;
    s32 var_s0;

    var_s0 = 0;
    strcpy_171C08(sp);
loop_1:
    func_00266708_171C08(&sp50, M2C_FIELD(arg0, s32* , 0x2CF0), var_s0);
    temp_a2 = var_s0;
    var_s0 += 1;
    if (sp50 != 0) {
        dmeSendMsgToClient_171C08(0x40, M2C_FIELD(arg0, s32* , 0x2CF0), temp_a2, D_004F9D80_171C08);
    }
    if (var_s0 < 8) {
        goto loop_1;
    }
}
//@@ netSendSessionMsg m2c0
#include "m2c_macros.h"
s32 dmeSendMsgToClient_ionMsg() __asm__("dmeSendMsgToClient");
s32 func_00266708_ionMsg() __asm__("func_00266708");
M2C_UNK netMsgSessionHandler_ionMsg() __asm__("netMsgSessionHandler");
M2C_UNK printf_ionMsg() __asm__("printf");
extern s32 D_004F9D88_ionMsg __asm__("D_004F9D88");

s32 netSendSessionMsg(void* arg0, s32 arg1, s32* arg2) {
    u8 sp[0x10];
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_s0;

    temp_v1 = *M2C_FIELD(arg0, s32** , 4);
    if ((temp_v1 != -1) && (temp_v1 == arg1)) {
        netMsgSessionHandler_ionMsg(M2C_FIELD(arg0, s32* , 0x2CF0), M2C_FIELD(arg0, s32* , 0x129C), arg1, arg2);
        goto block_17;
    }
    switch (arg1) {                                 /* irregular */
    case -1:
        var_s0 = 0;
        do {
            if ((func_00266708_ionMsg(sp, M2C_FIELD(arg0, s32* , 0x2CF0), var_s0) == 0) && (subroutine_arg0 != 0)) {
                temp_v0 = dmeSendMsgToClient_ionMsg(0x40, M2C_FIELD(arg0, s32* , 0x2CF0), var_s0, D_004F9D88_ionMsg);
                if (temp_v0 != 0) {
                    printf_ionMsg("NETWORK WARNING: Failed to send PREGAME (1) command %d to client %d NetError = %d\n", *arg2, var_s0, temp_v0);
                }
            }
            var_s0 += 1;
        } while (var_s0 < 8);
block_17:
        return 1;
    case -99:
        return 0;
    default:
        temp_v0_2 = dmeSendMsgToClient_ionMsg(0x40, M2C_FIELD(arg0, s32* , 0x2CF0), arg1, D_004F9D88_ionMsg);
        if (temp_v0_2 != 0) {
            printf_ionMsg("NETWORK WARNING: Failed to send PREGAME (1) command %d to client %d NetError = %d\n", *arg2, arg1, temp_v0_2);
        }
        goto block_17;
    }
}
//@@ netSendSessionMsg m2c1
#include "m2c_macros.h"
s32 dmeSendMsgToClient_ionMsg() __asm__("dmeSendMsgToClient");
s32 func_00266708_ionMsg() __asm__("func_00266708");
M2C_UNK netMsgSessionHandler_ionMsg() __asm__("netMsgSessionHandler");
M2C_UNK printf_ionMsg() __asm__("printf");
extern s32 D_004F9D88_ionMsg __asm__("D_004F9D88");

s32 netSendSessionMsg(void* arg0, s32 arg1, s32* arg2) {
    u8 sp[0x8];
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_s0;

    temp_v1 = *M2C_FIELD(arg0, s32** , 4);
    if ((temp_v1 != -1) && (temp_v1 == arg1)) {
        netMsgSessionHandler_ionMsg(M2C_FIELD(arg0, s32* , 0x2CF0), M2C_FIELD(arg0, s32* , 0x129C), arg1, arg2);
        goto block_17;
    }
    switch (arg1) {                                 /* irregular */
    case -1:
        var_s0 = 0;
        do {
            if ((func_00266708_ionMsg(sp, M2C_FIELD(arg0, s32* , 0x2CF0), var_s0) == 0) && (subroutine_arg0 != 0)) {
                temp_v0 = dmeSendMsgToClient_ionMsg(0x40, M2C_FIELD(arg0, s32* , 0x2CF0), var_s0, D_004F9D88_ionMsg);
                if (temp_v0 != 0) {
                    printf_ionMsg("NETWORK WARNING: Failed to send PREGAME (1) command %d to client %d NetError = %d\n", *arg2, var_s0, temp_v0);
                }
            }
            var_s0 += 1;
        } while (var_s0 < 8);
block_17:
        return 1;
    case -99:
        return 0;
    default:
        temp_v0_2 = dmeSendMsgToClient_ionMsg(0x40, M2C_FIELD(arg0, s32* , 0x2CF0), arg1, D_004F9D88_ionMsg);
        if (temp_v0_2 != 0) {
            printf_ionMsg("NETWORK WARNING: Failed to send PREGAME (1) command %d to client %d NetError = %d\n", *arg2, arg1, temp_v0_2);
        }
        goto block_17;
    }
}
//@@ netSendSessionMsg m2c2
#include "m2c_macros.h"
s32 dmeSendMsgToClient_ionMsg() __asm__("dmeSendMsgToClient");
s32 func_00266708_ionMsg() __asm__("func_00266708");
M2C_UNK netMsgSessionHandler_ionMsg() __asm__("netMsgSessionHandler");
M2C_UNK printf_ionMsg() __asm__("printf");
extern s32 D_004F9D88_ionMsg __asm__("D_004F9D88");

s32 netSendSessionMsg(void* arg0, s32 arg1, s32* arg2) {
    u8 sp[0x4];
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_s0;

    temp_v1 = *M2C_FIELD(arg0, s32** , 4);
    if ((temp_v1 != -1) && (temp_v1 == arg1)) {
        netMsgSessionHandler_ionMsg(M2C_FIELD(arg0, s32* , 0x2CF0), M2C_FIELD(arg0, s32* , 0x129C), arg1, arg2);
        goto block_17;
    }
    switch (arg1) {                                 /* irregular */
    case -1:
        var_s0 = 0;
        do {
            if ((func_00266708_ionMsg(sp, M2C_FIELD(arg0, s32* , 0x2CF0), var_s0) == 0) && (subroutine_arg0 != 0)) {
                temp_v0 = dmeSendMsgToClient_ionMsg(0x40, M2C_FIELD(arg0, s32* , 0x2CF0), var_s0, D_004F9D88_ionMsg);
                if (temp_v0 != 0) {
                    printf_ionMsg("NETWORK WARNING: Failed to send PREGAME (1) command %d to client %d NetError = %d\n", *arg2, var_s0, temp_v0);
                }
            }
            var_s0 += 1;
        } while (var_s0 < 8);
block_17:
        return 1;
    case -99:
        return 0;
    default:
        temp_v0_2 = dmeSendMsgToClient_ionMsg(0x40, M2C_FIELD(arg0, s32* , 0x2CF0), arg1, D_004F9D88_ionMsg);
        if (temp_v0_2 != 0) {
            printf_ionMsg("NETWORK WARNING: Failed to send PREGAME (1) command %d to client %d NetError = %d\n", *arg2, arg1, temp_v0_2);
        }
        goto block_17;
    }
}
//@@ netSendGameEvent m2c0
#include "m2c_macros.h"
s32 dmeSendMsgToClient_eEvent() __asm__("dmeSendMsgToClient");
M2C_UNK netMsgGameEventHandler_eEvent() __asm__("netMsgGameEventHandler");
M2C_UNK printf_eEvent() __asm__("printf");
extern s32 D_004F9D84_eEvent __asm__("D_004F9D84");

s32 netSendGameEvent(void* arg0, s32 arg1, void* arg2) {
    s32 temp_v0;

    if (*M2C_FIELD(arg0, s32** , 4) == arg1) {
        netMsgGameEventHandler_eEvent(M2C_FIELD(arg0, s32* , 0x2CF0), M2C_FIELD(arg0, s32* , 0x129C), arg1, arg2);
    } else {
        temp_v0 = dmeSendMsgToClient_eEvent(0x40, M2C_FIELD(arg0, s32* , 0x2CF0), arg1, D_004F9D84_eEvent);
        if (temp_v0 != 0) {
            printf_eEvent("NETWORK WARNING: Failed to send command %d to client %d NetError = %d\n", M2C_FIELD(arg2, s32* , 4), arg1, temp_v0);
        }
    }
    return 1;
}
//@@ func_00171F88 m2c0
#include "m2c_macros.h"
s8* dmeSendMsgToClient_171F88() __asm__("dmeSendMsgToClient");
s32 func_00266708_171F88() __asm__("func_00266708");
M2C_UNK netMsgRosterHandler_171F88() __asm__("netMsgRosterHandler");
M2C_UNK printf_171F88() __asm__("printf");
M2C_UNK strcpy_171F88() __asm__("strcpy");
extern M2C_UNK D_00318416_171F88 __asm__("D_00318416");
extern s32 D_004F9D98_171F88 __asm__("D_004F9D98");
extern s32 D_004FA030_171F88 __asm__("D_004FA030");

s32 func_00171F88(void* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp[0x190];
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    s32 sp20;
    s32 sp24;
    s32 sp28;
    s32 sp2C;
    s8 sp180;
    s8 sp18F;
    s128 sp190;
    s128 sp1A0;
    s128 sp1B0;
    s128 sp1C0;
    s128 sp1D0;
    M2C_UNK* var_t2;
    s128 var_t3;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a2;
    s32 var_a3;
    s32 var_s1;
    s32 var_s1_2;
    s32* var_fp;
    s32* var_s3;
    s32* var_s4;
    s32* var_s6;
    s32* var_s7;
    s32* var_t0;
    s32* var_t1;
    s32* var_t4;
    s8* temp_v0_3;
    void* temp_a0;
    void* var_s0;
    void* var_s2;

    var_a2 = arg2;
    var_a3 = arg3;
    var_t2 = &D_00318416_171F88;
    var_t1 = &sp2C;
    var_t4 = &D_00318416_171F88 + 0x272;
    var_t0 = &sp28;
    var_fp = &sp1C;
    var_s7 = &sp18;
    var_s1 = 0;
    var_s6 = &sp20;
    var_s4 = &sp24;
    var_s3 = &sp14;
    var_s2 = sp;
    var_s0 = &D_00318416_171F88 + 0x252;
    var_t3 = 0;
    do {
        temp_a0 = var_s2;
        sp190 = (s128) var_t0;
        var_s1 += 1;
        sp1A0 = (s128) var_t1;
        var_s2 += 0x30;
        sp1B0 = (s128) var_t2;
        sp1C0 = var_t3;
        sp1D0 = (s128) var_t4;
        strcpy_171F88(temp_a0, (s128) var_t2, var_a2, var_a3);
        var_a3 = var_s1 < 8;
        temp_v1 = M2C_FIELD((D_004FA030_171F88 + var_t3), s32* , 0x20F4);
        var_t2 += 0x14;
        var_t3 += 0x31B0;
        var_a2 = M2C_FIELD(var_s0, s32* , -0x80);
        *var_s3 = temp_v1;
        *var_s4 = M2C_FIELD(var_s0, s32* , -0x20);
        var_s3 += 0x30;
        *var_s6 = M2C_FIELD(var_s0, s32* , -0x60);
        var_s4 += 0x30;
        var_s6 += 0x30;
        *var_s7 = var_a2;
        var_s7 += 0x30;
        temp_v1_2 = M2C_FIELD(var_s0, s32* , 0);
        *var_fp = M2C_FIELD(var_s0, s32* , -0x40);
        var_s0 += 4;
        var_fp += 0x30;
        temp_v0 = *var_t4;
        *var_t0 = temp_v1_2;
        var_t4 += 4;
        var_t0 += 0x30;
        *var_t1 = temp_v0;
        var_t1 += 0x30;
    } while (var_a3 != 0);
    var_s1_2 = 0;
loop_3:
    if (*M2C_FIELD(arg0, s32** , 4) == var_s1_2) {
        netMsgRosterHandler_171F88(M2C_FIELD(arg0, s32* , 0x2CF0), M2C_FIELD(arg0, s32* , 0x129C), var_s1_2, sp);
    } else {
        temp_v0_2 = func_00266708_171F88(&sp180, M2C_FIELD(arg0, s32* , 0x2CF0), var_s1_2);
        if (temp_v0_2 != 0) {
            sp18F = 0;
            printf_171F88("NETWORK WARNING:  NetGetClientIpAddress Failed %d (%s)\n", temp_v0_2, &sp180);
        }
        if (sp180 != 0) {
            temp_v0_3 = dmeSendMsgToClient_171F88(0x40, M2C_FIELD(arg0, s32* , 0x2CF0), var_s1_2, D_004F9D98_171F88);
            if (temp_v0_3 != NULL) {
                printf_171F88("NETWORK WARNING: Failed to FINAL SCORE to client %d NetError = %d\n", var_s1_2, temp_v0_3);
            }
        }
    }
    var_s1_2 += 1;
    if (var_s1_2 < 8) {
        goto loop_3;
    }
    return 1;
}
//@@ func_00171F88 m2c1
#include "m2c_macros.h"
s8* dmeSendMsgToClient_171F88() __asm__("dmeSendMsgToClient");
s32 func_00266708_171F88() __asm__("func_00266708");
M2C_UNK netMsgRosterHandler_171F88() __asm__("netMsgRosterHandler");
M2C_UNK printf_171F88() __asm__("printf");
M2C_UNK strcpy_171F88() __asm__("strcpy");
extern M2C_UNK D_00318416_171F88 __asm__("D_00318416");
extern s32 D_004F9D98_171F88 __asm__("D_004F9D98");
extern s32 D_004FA030_171F88 __asm__("D_004FA030");

s32 func_00171F88(void* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp[0x180];
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    s32 sp20;
    s32 sp24;
    s32 sp28;
    s32 sp2C;
    s8 sp180;
    s8 sp18F;
    s128 sp190;
    s128 sp1A0;
    s128 sp1B0;
    s128 sp1C0;
    s128 sp1D0;
    M2C_UNK* var_t2;
    s128 var_t3;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a2;
    s32 var_a3;
    s32 var_s1;
    s32 var_s1_2;
    s32* var_fp;
    s32* var_s3;
    s32* var_s4;
    s32* var_s6;
    s32* var_s7;
    s32* var_t0;
    s32* var_t1;
    s32* var_t4;
    s8* temp_v0_3;
    void* temp_a0;
    void* var_s0;
    void* var_s2;

    var_a2 = arg2;
    var_a3 = arg3;
    var_t2 = &D_00318416_171F88;
    var_t1 = &sp2C;
    var_t4 = &D_00318416_171F88 + 0x272;
    var_t0 = &sp28;
    var_fp = &sp1C;
    var_s7 = &sp18;
    var_s1 = 0;
    var_s6 = &sp20;
    var_s4 = &sp24;
    var_s3 = &sp14;
    var_s2 = sp;
    var_s0 = &D_00318416_171F88 + 0x252;
    var_t3 = 0;
    do {
        temp_a0 = var_s2;
        sp190 = (s128) var_t0;
        var_s1 += 1;
        sp1A0 = (s128) var_t1;
        var_s2 += 0x30;
        sp1B0 = (s128) var_t2;
        sp1C0 = var_t3;
        sp1D0 = (s128) var_t4;
        strcpy_171F88(temp_a0, (s128) var_t2, var_a2, var_a3);
        var_a3 = var_s1 < 8;
        temp_v1 = M2C_FIELD((D_004FA030_171F88 + var_t3), s32* , 0x20F4);
        var_t2 += 0x14;
        var_t3 += 0x31B0;
        var_a2 = M2C_FIELD(var_s0, s32* , -0x80);
        *var_s3 = temp_v1;
        *var_s4 = M2C_FIELD(var_s0, s32* , -0x20);
        var_s3 += 0x30;
        *var_s6 = M2C_FIELD(var_s0, s32* , -0x60);
        var_s4 += 0x30;
        var_s6 += 0x30;
        *var_s7 = var_a2;
        var_s7 += 0x30;
        temp_v1_2 = M2C_FIELD(var_s0, s32* , 0);
        *var_fp = M2C_FIELD(var_s0, s32* , -0x40);
        var_s0 += 4;
        var_fp += 0x30;
        temp_v0 = *var_t4;
        *var_t0 = temp_v1_2;
        var_t4 += 4;
        var_t0 += 0x30;
        *var_t1 = temp_v0;
        var_t1 += 0x30;
    } while (var_a3 != 0);
    var_s1_2 = 0;
loop_3:
    if (*M2C_FIELD(arg0, s32** , 4) == var_s1_2) {
        netMsgRosterHandler_171F88(M2C_FIELD(arg0, s32* , 0x2CF0), M2C_FIELD(arg0, s32* , 0x129C), var_s1_2, sp);
    } else {
        temp_v0_2 = func_00266708_171F88(&sp180, M2C_FIELD(arg0, s32* , 0x2CF0), var_s1_2);
        if (temp_v0_2 != 0) {
            sp18F = 0;
            printf_171F88("NETWORK WARNING:  NetGetClientIpAddress Failed %d (%s)\n", temp_v0_2, &sp180);
        }
        if (sp180 != 0) {
            temp_v0_3 = dmeSendMsgToClient_171F88(0x40, M2C_FIELD(arg0, s32* , 0x2CF0), var_s1_2, D_004F9D98_171F88);
            if (temp_v0_3 != NULL) {
                printf_171F88("NETWORK WARNING: Failed to FINAL SCORE to client %d NetError = %d\n", var_s1_2, temp_v0_3);
            }
        }
    }
    var_s1_2 += 1;
    if (var_s1_2 < 8) {
        goto loop_3;
    }
    return 1;
}
//@@ func_00171F88 m2c2
#include "m2c_macros.h"
s8* dmeSendMsgToClient_171F88() __asm__("dmeSendMsgToClient");
s32 func_00266708_171F88() __asm__("func_00266708");
M2C_UNK netMsgRosterHandler_171F88() __asm__("netMsgRosterHandler");
M2C_UNK printf_171F88() __asm__("printf");
M2C_UNK strcpy_171F88() __asm__("strcpy");
extern M2C_UNK D_00318416_171F88 __asm__("D_00318416");
extern s32 D_004F9D98_171F88 __asm__("D_004F9D98");
extern s32 D_004FA030_171F88 __asm__("D_004FA030");

s32 func_00171F88(void* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp[0x170];
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    s32 sp20;
    s32 sp24;
    s32 sp28;
    s32 sp2C;
    s8 sp180;
    s8 sp18F;
    s128 sp190;
    s128 sp1A0;
    s128 sp1B0;
    s128 sp1C0;
    s128 sp1D0;
    M2C_UNK* var_t2;
    s128 var_t3;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a2;
    s32 var_a3;
    s32 var_s1;
    s32 var_s1_2;
    s32* var_fp;
    s32* var_s3;
    s32* var_s4;
    s32* var_s6;
    s32* var_s7;
    s32* var_t0;
    s32* var_t1;
    s32* var_t4;
    s8* temp_v0_3;
    void* temp_a0;
    void* var_s0;
    void* var_s2;

    var_a2 = arg2;
    var_a3 = arg3;
    var_t2 = &D_00318416_171F88;
    var_t1 = &sp2C;
    var_t4 = &D_00318416_171F88 + 0x272;
    var_t0 = &sp28;
    var_fp = &sp1C;
    var_s7 = &sp18;
    var_s1 = 0;
    var_s6 = &sp20;
    var_s4 = &sp24;
    var_s3 = &sp14;
    var_s2 = sp;
    var_s0 = &D_00318416_171F88 + 0x252;
    var_t3 = 0;
    do {
        temp_a0 = var_s2;
        sp190 = (s128) var_t0;
        var_s1 += 1;
        sp1A0 = (s128) var_t1;
        var_s2 += 0x30;
        sp1B0 = (s128) var_t2;
        sp1C0 = var_t3;
        sp1D0 = (s128) var_t4;
        strcpy_171F88(temp_a0, (s128) var_t2, var_a2, var_a3);
        var_a3 = var_s1 < 8;
        temp_v1 = M2C_FIELD((D_004FA030_171F88 + var_t3), s32* , 0x20F4);
        var_t2 += 0x14;
        var_t3 += 0x31B0;
        var_a2 = M2C_FIELD(var_s0, s32* , -0x80);
        *var_s3 = temp_v1;
        *var_s4 = M2C_FIELD(var_s0, s32* , -0x20);
        var_s3 += 0x30;
        *var_s6 = M2C_FIELD(var_s0, s32* , -0x60);
        var_s4 += 0x30;
        var_s6 += 0x30;
        *var_s7 = var_a2;
        var_s7 += 0x30;
        temp_v1_2 = M2C_FIELD(var_s0, s32* , 0);
        *var_fp = M2C_FIELD(var_s0, s32* , -0x40);
        var_s0 += 4;
        var_fp += 0x30;
        temp_v0 = *var_t4;
        *var_t0 = temp_v1_2;
        var_t4 += 4;
        var_t0 += 0x30;
        *var_t1 = temp_v0;
        var_t1 += 0x30;
    } while (var_a3 != 0);
    var_s1_2 = 0;
loop_3:
    if (*M2C_FIELD(arg0, s32** , 4) == var_s1_2) {
        netMsgRosterHandler_171F88(M2C_FIELD(arg0, s32* , 0x2CF0), M2C_FIELD(arg0, s32* , 0x129C), var_s1_2, sp);
    } else {
        temp_v0_2 = func_00266708_171F88(&sp180, M2C_FIELD(arg0, s32* , 0x2CF0), var_s1_2);
        if (temp_v0_2 != 0) {
            sp18F = 0;
            printf_171F88("NETWORK WARNING:  NetGetClientIpAddress Failed %d (%s)\n", temp_v0_2, &sp180);
        }
        if (sp180 != 0) {
            temp_v0_3 = dmeSendMsgToClient_171F88(0x40, M2C_FIELD(arg0, s32* , 0x2CF0), var_s1_2, D_004F9D98_171F88);
            if (temp_v0_3 != NULL) {
                printf_171F88("NETWORK WARNING: Failed to FINAL SCORE to client %d NetError = %d\n", var_s1_2, temp_v0_3);
            }
        }
    }
    var_s1_2 += 1;
    if (var_s1_2 < 8) {
        goto loop_3;
    }
    return 1;
}
//@@ func_00171F88 m2c3
#include "m2c_macros.h"
s8* dmeSendMsgToClient_171F88() __asm__("dmeSendMsgToClient");
s32 func_00266708_171F88() __asm__("func_00266708");
M2C_UNK netMsgRosterHandler_171F88() __asm__("netMsgRosterHandler");
M2C_UNK printf_171F88() __asm__("printf");
M2C_UNK strcpy_171F88() __asm__("strcpy");
extern M2C_UNK D_00318416_171F88 __asm__("D_00318416");
extern s32 D_004F9D98_171F88 __asm__("D_004F9D98");
extern s32 D_004FA030_171F88 __asm__("D_004FA030");

s32 func_00171F88(void* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp[0x160];
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    s32 sp20;
    s32 sp24;
    s32 sp28;
    s32 sp2C;
    s8 sp180;
    s8 sp18F;
    s128 sp190;
    s128 sp1A0;
    s128 sp1B0;
    s128 sp1C0;
    s128 sp1D0;
    M2C_UNK* var_t2;
    s128 var_t3;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a2;
    s32 var_a3;
    s32 var_s1;
    s32 var_s1_2;
    s32* var_fp;
    s32* var_s3;
    s32* var_s4;
    s32* var_s6;
    s32* var_s7;
    s32* var_t0;
    s32* var_t1;
    s32* var_t4;
    s8* temp_v0_3;
    void* temp_a0;
    void* var_s0;
    void* var_s2;

    var_a2 = arg2;
    var_a3 = arg3;
    var_t2 = &D_00318416_171F88;
    var_t1 = &sp2C;
    var_t4 = &D_00318416_171F88 + 0x272;
    var_t0 = &sp28;
    var_fp = &sp1C;
    var_s7 = &sp18;
    var_s1 = 0;
    var_s6 = &sp20;
    var_s4 = &sp24;
    var_s3 = &sp14;
    var_s2 = sp;
    var_s0 = &D_00318416_171F88 + 0x252;
    var_t3 = 0;
    do {
        temp_a0 = var_s2;
        sp190 = (s128) var_t0;
        var_s1 += 1;
        sp1A0 = (s128) var_t1;
        var_s2 += 0x30;
        sp1B0 = (s128) var_t2;
        sp1C0 = var_t3;
        sp1D0 = (s128) var_t4;
        strcpy_171F88(temp_a0, (s128) var_t2, var_a2, var_a3);
        var_a3 = var_s1 < 8;
        temp_v1 = M2C_FIELD((D_004FA030_171F88 + var_t3), s32* , 0x20F4);
        var_t2 += 0x14;
        var_t3 += 0x31B0;
        var_a2 = M2C_FIELD(var_s0, s32* , -0x80);
        *var_s3 = temp_v1;
        *var_s4 = M2C_FIELD(var_s0, s32* , -0x20);
        var_s3 += 0x30;
        *var_s6 = M2C_FIELD(var_s0, s32* , -0x60);
        var_s4 += 0x30;
        var_s6 += 0x30;
        *var_s7 = var_a2;
        var_s7 += 0x30;
        temp_v1_2 = M2C_FIELD(var_s0, s32* , 0);
        *var_fp = M2C_FIELD(var_s0, s32* , -0x40);
        var_s0 += 4;
        var_fp += 0x30;
        temp_v0 = *var_t4;
        *var_t0 = temp_v1_2;
        var_t4 += 4;
        var_t0 += 0x30;
        *var_t1 = temp_v0;
        var_t1 += 0x30;
    } while (var_a3 != 0);
    var_s1_2 = 0;
loop_3:
    if (*M2C_FIELD(arg0, s32** , 4) == var_s1_2) {
        netMsgRosterHandler_171F88(M2C_FIELD(arg0, s32* , 0x2CF0), M2C_FIELD(arg0, s32* , 0x129C), var_s1_2, sp);
    } else {
        temp_v0_2 = func_00266708_171F88(&sp180, M2C_FIELD(arg0, s32* , 0x2CF0), var_s1_2);
        if (temp_v0_2 != 0) {
            sp18F = 0;
            printf_171F88("NETWORK WARNING:  NetGetClientIpAddress Failed %d (%s)\n", temp_v0_2, &sp180);
        }
        if (sp180 != 0) {
            temp_v0_3 = dmeSendMsgToClient_171F88(0x40, M2C_FIELD(arg0, s32* , 0x2CF0), var_s1_2, D_004F9D98_171F88);
            if (temp_v0_3 != NULL) {
                printf_171F88("NETWORK WARNING: Failed to FINAL SCORE to client %d NetError = %d\n", var_s1_2, temp_v0_3);
            }
        }
    }
    var_s1_2 += 1;
    if (var_s1_2 < 8) {
        goto loop_3;
    }
    return 1;
}
//@@ func_00171F88 m2c4
#include "m2c_macros.h"
s8* dmeSendMsgToClient_171F88() __asm__("dmeSendMsgToClient");
s32 func_00266708_171F88() __asm__("func_00266708");
M2C_UNK netMsgRosterHandler_171F88() __asm__("netMsgRosterHandler");
M2C_UNK printf_171F88() __asm__("printf");
M2C_UNK strcpy_171F88() __asm__("strcpy");
extern M2C_UNK D_00318416_171F88 __asm__("D_00318416");
extern s32 D_004F9D98_171F88 __asm__("D_004F9D98");
extern s32 D_004FA030_171F88 __asm__("D_004FA030");

s32 func_00171F88(void* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp[0x150];
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    s32 sp20;
    s32 sp24;
    s32 sp28;
    s32 sp2C;
    s8 sp180;
    s8 sp18F;
    s128 sp190;
    s128 sp1A0;
    s128 sp1B0;
    s128 sp1C0;
    s128 sp1D0;
    M2C_UNK* var_t2;
    s128 var_t3;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a2;
    s32 var_a3;
    s32 var_s1;
    s32 var_s1_2;
    s32* var_fp;
    s32* var_s3;
    s32* var_s4;
    s32* var_s6;
    s32* var_s7;
    s32* var_t0;
    s32* var_t1;
    s32* var_t4;
    s8* temp_v0_3;
    void* temp_a0;
    void* var_s0;
    void* var_s2;

    var_a2 = arg2;
    var_a3 = arg3;
    var_t2 = &D_00318416_171F88;
    var_t1 = &sp2C;
    var_t4 = &D_00318416_171F88 + 0x272;
    var_t0 = &sp28;
    var_fp = &sp1C;
    var_s7 = &sp18;
    var_s1 = 0;
    var_s6 = &sp20;
    var_s4 = &sp24;
    var_s3 = &sp14;
    var_s2 = sp;
    var_s0 = &D_00318416_171F88 + 0x252;
    var_t3 = 0;
    do {
        temp_a0 = var_s2;
        sp190 = (s128) var_t0;
        var_s1 += 1;
        sp1A0 = (s128) var_t1;
        var_s2 += 0x30;
        sp1B0 = (s128) var_t2;
        sp1C0 = var_t3;
        sp1D0 = (s128) var_t4;
        strcpy_171F88(temp_a0, (s128) var_t2, var_a2, var_a3);
        var_a3 = var_s1 < 8;
        temp_v1 = M2C_FIELD((D_004FA030_171F88 + var_t3), s32* , 0x20F4);
        var_t2 += 0x14;
        var_t3 += 0x31B0;
        var_a2 = M2C_FIELD(var_s0, s32* , -0x80);
        *var_s3 = temp_v1;
        *var_s4 = M2C_FIELD(var_s0, s32* , -0x20);
        var_s3 += 0x30;
        *var_s6 = M2C_FIELD(var_s0, s32* , -0x60);
        var_s4 += 0x30;
        var_s6 += 0x30;
        *var_s7 = var_a2;
        var_s7 += 0x30;
        temp_v1_2 = M2C_FIELD(var_s0, s32* , 0);
        *var_fp = M2C_FIELD(var_s0, s32* , -0x40);
        var_s0 += 4;
        var_fp += 0x30;
        temp_v0 = *var_t4;
        *var_t0 = temp_v1_2;
        var_t4 += 4;
        var_t0 += 0x30;
        *var_t1 = temp_v0;
        var_t1 += 0x30;
    } while (var_a3 != 0);
    var_s1_2 = 0;
loop_3:
    if (*M2C_FIELD(arg0, s32** , 4) == var_s1_2) {
        netMsgRosterHandler_171F88(M2C_FIELD(arg0, s32* , 0x2CF0), M2C_FIELD(arg0, s32* , 0x129C), var_s1_2, sp);
    } else {
        temp_v0_2 = func_00266708_171F88(&sp180, M2C_FIELD(arg0, s32* , 0x2CF0), var_s1_2);
        if (temp_v0_2 != 0) {
            sp18F = 0;
            printf_171F88("NETWORK WARNING:  NetGetClientIpAddress Failed %d (%s)\n", temp_v0_2, &sp180);
        }
        if (sp180 != 0) {
            temp_v0_3 = dmeSendMsgToClient_171F88(0x40, M2C_FIELD(arg0, s32* , 0x2CF0), var_s1_2, D_004F9D98_171F88);
            if (temp_v0_3 != NULL) {
                printf_171F88("NETWORK WARNING: Failed to FINAL SCORE to client %d NetError = %d\n", var_s1_2, temp_v0_3);
            }
        }
    }
    var_s1_2 += 1;
    if (var_s1_2 < 8) {
        goto loop_3;
    }
    return 1;
}
//@@ func_00171F88 m2c5
#include "m2c_macros.h"
s8* dmeSendMsgToClient_171F88() __asm__("dmeSendMsgToClient");
s32 func_00266708_171F88() __asm__("func_00266708");
M2C_UNK netMsgRosterHandler_171F88() __asm__("netMsgRosterHandler");
M2C_UNK printf_171F88() __asm__("printf");
M2C_UNK strcpy_171F88() __asm__("strcpy");
extern M2C_UNK D_00318416_171F88 __asm__("D_00318416");
extern s32 D_004F9D98_171F88 __asm__("D_004F9D98");
extern s32 D_004FA030_171F88 __asm__("D_004FA030");

s32 func_00171F88(void* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp[0x140];
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    s32 sp20;
    s32 sp24;
    s32 sp28;
    s32 sp2C;
    s8 sp180;
    s8 sp18F;
    s128 sp190;
    s128 sp1A0;
    s128 sp1B0;
    s128 sp1C0;
    s128 sp1D0;
    M2C_UNK* var_t2;
    s128 var_t3;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a2;
    s32 var_a3;
    s32 var_s1;
    s32 var_s1_2;
    s32* var_fp;
    s32* var_s3;
    s32* var_s4;
    s32* var_s6;
    s32* var_s7;
    s32* var_t0;
    s32* var_t1;
    s32* var_t4;
    s8* temp_v0_3;
    void* temp_a0;
    void* var_s0;
    void* var_s2;

    var_a2 = arg2;
    var_a3 = arg3;
    var_t2 = &D_00318416_171F88;
    var_t1 = &sp2C;
    var_t4 = &D_00318416_171F88 + 0x272;
    var_t0 = &sp28;
    var_fp = &sp1C;
    var_s7 = &sp18;
    var_s1 = 0;
    var_s6 = &sp20;
    var_s4 = &sp24;
    var_s3 = &sp14;
    var_s2 = sp;
    var_s0 = &D_00318416_171F88 + 0x252;
    var_t3 = 0;
    do {
        temp_a0 = var_s2;
        sp190 = (s128) var_t0;
        var_s1 += 1;
        sp1A0 = (s128) var_t1;
        var_s2 += 0x30;
        sp1B0 = (s128) var_t2;
        sp1C0 = var_t3;
        sp1D0 = (s128) var_t4;
        strcpy_171F88(temp_a0, (s128) var_t2, var_a2, var_a3);
        var_a3 = var_s1 < 8;
        temp_v1 = M2C_FIELD((D_004FA030_171F88 + var_t3), s32* , 0x20F4);
        var_t2 += 0x14;
        var_t3 += 0x31B0;
        var_a2 = M2C_FIELD(var_s0, s32* , -0x80);
        *var_s3 = temp_v1;
        *var_s4 = M2C_FIELD(var_s0, s32* , -0x20);
        var_s3 += 0x30;
        *var_s6 = M2C_FIELD(var_s0, s32* , -0x60);
        var_s4 += 0x30;
        var_s6 += 0x30;
        *var_s7 = var_a2;
        var_s7 += 0x30;
        temp_v1_2 = M2C_FIELD(var_s0, s32* , 0);
        *var_fp = M2C_FIELD(var_s0, s32* , -0x40);
        var_s0 += 4;
        var_fp += 0x30;
        temp_v0 = *var_t4;
        *var_t0 = temp_v1_2;
        var_t4 += 4;
        var_t0 += 0x30;
        *var_t1 = temp_v0;
        var_t1 += 0x30;
    } while (var_a3 != 0);
    var_s1_2 = 0;
loop_3:
    if (*M2C_FIELD(arg0, s32** , 4) == var_s1_2) {
        netMsgRosterHandler_171F88(M2C_FIELD(arg0, s32* , 0x2CF0), M2C_FIELD(arg0, s32* , 0x129C), var_s1_2, sp);
    } else {
        temp_v0_2 = func_00266708_171F88(&sp180, M2C_FIELD(arg0, s32* , 0x2CF0), var_s1_2);
        if (temp_v0_2 != 0) {
            sp18F = 0;
            printf_171F88("NETWORK WARNING:  NetGetClientIpAddress Failed %d (%s)\n", temp_v0_2, &sp180);
        }
        if (sp180 != 0) {
            temp_v0_3 = dmeSendMsgToClient_171F88(0x40, M2C_FIELD(arg0, s32* , 0x2CF0), var_s1_2, D_004F9D98_171F88);
            if (temp_v0_3 != NULL) {
                printf_171F88("NETWORK WARNING: Failed to FINAL SCORE to client %d NetError = %d\n", var_s1_2, temp_v0_3);
            }
        }
    }
    var_s1_2 += 1;
    if (var_s1_2 < 8) {
        goto loop_3;
    }
    return 1;
}
//@@ func_00172190 m2c0
#include "m2c_macros.h"
M2C_UNK func_00172378_172190() __asm__("func_00172378");
s32 func_001B0428_172190() __asm__("func_001B0428");
M2C_UNK memset_172190() __asm__("memset");
extern s32 D_004FA03C_172190 __asm__("D_004FA03C");

void func_00172190(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 temp_s2;

    temp_s2 = arg0 + 0x1CC8;
    memset_172190(temp_s2, 0, 0x1000);
    if (func_001B0428_172190(D_004FA03C_172190 + 0x19E60, arg1, temp_s2, arg2) != 0) {
        func_00172378_172190(arg0, temp_s2);
    }
}
//@@ func_00172218 m2c0
#include "m2c_macros.h"
M2C_UNK memset_172218() __asm__("memset");
M2C_UNK sprintf_172218() __asm__("sprintf");

s32 func_00172218(void* arg0) {
    s32 temp_s1;

    temp_s1 = arg0 + 0x1CC8;
    memset_172218(temp_s1, 0, 0x1000);
    sprintf_172218(temp_s1, "[CONNECT_IP] %s\n[CLIENT_IP] %s\n[CLIENT_SUBNET] %s\n[CLIENT_GATEWAY] %s\n[WORLD_ID] %d\n[SERVER_IP] %s\n[DNS_SERVERS] %s %s\n[SERVER_PORT] %d\n[CURRENT_CONFIG] %d\n[AUTO_RECONNECT] %d\n[SHOW_DIAGNOSTICS] %d\n[MEDIUS_SERVER] %s\n[MEDIUS_PORT] %s\n", arg0 + 0x13AC, arg0 + 0x1A54, M2C_FIELD(arg0, s32* , 0x1298), M2C_FIELD(arg0, s32* , 0x4288), M2C_FIELD(arg0, s32* , 0x4270), M2C_FIELD(arg0, s32* , 0x4274), arg0 + 0x142C, arg0 + 0x146C);
    return 1;
}
//@@ func_001722C0 m2c0
#include "m2c_macros.h"
M2C_UNK memset_1722C0() __asm__("memset");
M2C_UNK sprintf_1722C0() __asm__("sprintf");

s32 func_001722C0(void* arg0) {
    s32 temp_s1;

    temp_s1 = arg0 + 0x1CC8;
    memset_1722C0(temp_s1, 0, 0x1000);
    sprintf_1722C0(temp_s1, "[USER_NAME] %s\n[USER_CAR] %d\n[GAME_NAME] %s\n", arg0 + 0x1998, M2C_FIELD(arg0, s32* , 0x1A34));
    return 1;
}
//@@ func_00172320 m2c0
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
//@@ func_00172A10 m2c0
#include "m2c_macros.h"
extern s8* D_004FB4F0_172A10 __asm__("D_004FB4F0");

s8* func_00172A10(s32 arg0, s8* arg1) {
    s32 var_a1;
    s8 var_v0;
    s8* var_v1;

    if (arg1 != NULL) {
        D_004FB4F0_172A10 = arg1;
    }
    var_a1 = 0;
    var_v1 = D_004FB4F0_172A10;
    if (*D_004FB4F0_172A10 == 0) {
        return NULL;
    }
loop_5:
    var_v1 += 1;
    if (*var_v1 == 0xD) {
        var_v0 = M2C_FIELD(var_v1, s8* , 0);
        if (var_v0 == 0xA) {
            M2C_FIELD(var_v1, s8* , -1) = 0;
            var_a1 = 1;
            var_v1 += 1;
            D_004FB4F0_172A10 = var_v1;
            goto block_8;
        }
    } else {
block_8:
        var_v0 = *var_v1;
    }
    if ((var_v0 != 0) && (var_a1 == 0)) {
        goto loop_5;
    }
    return D_004FB4F0_172A10;
}
//@@ func_00172A80 m2c0
#include "m2c_macros.h"
s32 func_00172A80(void) {
    return 1;
}
//@@ func_00172A88 m2c0
#include "m2c_macros.h"
s32 func_00172A88(void) {
    return 0;
}
//@@ func_00172A90 m2c0
#include "m2c_macros.h"
M2C_UNK func_0011A8D0_172A90() __asm__("func_0011A8D0");
M2C_UNK func_00173248_172A90() __asm__("func_00173248");
s32 func_001734B8_172A90() __asm__("func_001734B8");
M2C_UNK func_00174988_172A90() __asm__("func_00174988");
M2C_UNK func_00176EA0_172A90() __asm__("func_00176EA0");
M2C_UNK func_001808F0_172A90() __asm__("func_001808F0");
M2C_UNK func_001A9278_172A90() __asm__("func_001A9278");
s8 netGetMyClientIndex_172A90() __asm__("netGetMyClientIndex");
s32 timerGetFieldsLastFrame__Fv_172A90() __asm__("timerGetFieldsLastFrame__Fv");
extern M2C_UNK D_003156C0_172A90 __asm__("D_003156C0");
extern s32 D_004F9E8C_172A90 __asm__("D_004F9E8C");

void func_00172A90(void* arg0, void* arg1, void* arg2) {
    s32 temp_v0_6;
    s32 temp_v1;
    s32 temp_v1_8;
    s32 var_a2_2;
    s8 temp_a1;
    s8 temp_v1_7;
    u32 temp_a0_3;
    u32 temp_v1_4;
    void* temp_a0;
    void* temp_a0_2;
    void* temp_a1_2;
    void* temp_a1_3;
    void* temp_v0;
    void* temp_v0_2;
    void* temp_v0_3;
    void* temp_v0_4;
    void* temp_v0_5;
    void* temp_v1_2;
    void* temp_v1_3;
    void* temp_v1_5;
    void* temp_v1_6;
    void* temp_v1_9;
    void* var_a1;
    void* var_a1_3;
    void* var_a2;
    void* var_s1;
    void* var_s2;
    void** var_a1_2;

    var_a1 = arg1;
    var_a2 = arg2;
    temp_v1 = ((u32) M2C_FIELD(M2C_FIELD(arg0, void** , 0x3148), u32* , 0) >> 1) & 0xF;
    if (temp_v1 != 4) {
        var_s2 = arg0 + 0x3234;
        if (temp_v1 >= 5) {
            if (temp_v1 == 5) {
                if (M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0x210) != NULL) {
                    temp_v1_2 = M2C_FIELD(arg0, void** , 4);
                    var_a2 = M2C_FIELD(temp_v1_2, void** , 0x210);
                    var_a1 = M2C_FIELD(arg0, void** , 0x3148) + M2C_FIELD(temp_v1_2, s32* , 0);
                    M2C_FIELD(var_a2, s32* , 8) = (s32) (M2C_FIELD(var_a2, s32* , 8) + (M2C_FIELD(var_a1, s8* , 0x32) * timerGetFieldsLastFrame__Fv_172A90(4U)));
                }
                func_0011A8D0_172A90(arg0 + 0x386C, var_a1, var_a2);
                var_s2 = arg0 + 0x3234;
            }
        }
    } else {
        var_s2 = arg0 + 0x3234;
        if (func_001734B8_172A90(arg0) != 0) {
            var_a2_2 = 0;
            if (M2C_FIELD(M2C_FIELD(arg0, void** , 0x3148), s8* , 0x1A) < 0) {
                M2C_FIELD(M2C_FIELD(arg0, void** , 0x3148), s8* , 0x1A) = netGetMyClientIndex_172A90(arg0);
                func_001A9278_172A90();
                func_00174988_172A90(arg0, -1);
                var_a2_2 = 0;
            }
            M2C_FIELD(M2C_FIELD(arg0, void** , 0x3148), s32* , 0x1C) = 0;
            var_a1_2 = arg0 + 0xB0;
loop_11:
            temp_v1_3 = *var_a1_2;
            if (temp_v1_3 == NULL) {
                var_a2_2 += 1;
                goto block_20;
            }
            if (M2C_FIELD(temp_v1_3, s32* , 0x590) == 0) {
                var_a2_2 += 1;
                goto block_20;
            }
            var_a2_2 += 1;
            if ((M2C_FIELD(temp_v1_3, s8* , 0x485) != 0) || (temp_a0 = M2C_FIELD(arg0, void** , 0x3148), temp_v0 = (M2C_FIELD(temp_a0, s8* , 0x1A) * 0x220) + arg0, (M2C_FIELD(temp_v0, s32* , 0x10) == -1)) || (M2C_FIELD(temp_v0, s32* , 0x220) == 0)) {
block_20:
                var_a1_2 += 0x220;
                if (var_a2_2 < 8) {
                    goto loop_11;
                }
            } else {
                M2C_FIELD(temp_a0, s32* , 0x1C) = 1;
            }
            temp_v0_2 = M2C_FIELD(arg0, void** , 0x3148);
            temp_a1 = M2C_FIELD(temp_v0_2, s8* , 0x1A);
            if ((temp_a1 != -1) && ((temp_v1_4 = M2C_FIELD(M2C_FIELD(&D_003156C0_172A90, void** , 0x3148), u32* , 0), (((temp_v1_4 >> 5) & 1) != 1)) || (temp_v1_4 & 1))) {
                temp_a0_2 = (temp_a1 * 0x220) + arg0;
                if ((M2C_FIELD(temp_a0_2, s32* , 0x10) != -1) && (M2C_FIELD(temp_a0_2, s32* , 0x220) != 0)) {
                    temp_v0_3 = M2C_FIELD(temp_a0_2, void** , 0xB0);
                    if (temp_v0_3 != NULL) {
                        if ((M2C_FIELD(temp_v0_3, s8* , 0x485) != 0) && (M2C_FIELD(temp_v0_2, s32* , 0x1C) != 0)) {
                            goto block_29;
                        }
                    }
                } else {
block_29:
                    func_00173248_172A90(arg0, M2C_FIELD(temp_v0_2, s8* , 0x1A), -1, -1);
                    func_00174988_172A90(arg0, -1);
                }
            }
        }
        temp_v1_5 = M2C_FIELD(arg0, void** , 0xB790);
        if (temp_v1_5 != NULL) {
            M2C_FIELD(temp_v1_5, s8* , 0xC) = 0;
        }
        temp_v1_6 = M2C_FIELD(arg0, void** , 0xB794);
        if (temp_v1_6 != NULL) {
            M2C_FIELD(temp_v1_6, s8* , 0xC) = 0;
        }
        temp_v0_4 = M2C_FIELD(arg0, void** , 0xB798);
        if (temp_v0_4 != NULL) {
            M2C_FIELD(temp_v0_4, s8* , 0xC) = 0;
        }
        temp_v1_7 = M2C_FIELD(M2C_FIELD(&D_003156C0_172A90, void** , 0x3148), s8* , 0x1A);
        var_s1 = NULL;
        if (temp_v1_7 >= 0) {
            var_s1 = M2C_FIELD(((temp_v1_7 * 0x220) + &D_003156C0_172A90), void** , 0xB0);
        }
        if (var_s1 != NULL) {
            temp_a1_2 = M2C_FIELD(arg0, void** , 4);
            if ((M2C_FIELD(M2C_FIELD(arg0, void** , 0x3148), s8* , 0x1A) == M2C_FIELD(temp_a1_2, s32* , 0)) && ((temp_a0_3 = M2C_FIELD(M2C_FIELD(&D_003156C0_172A90, void** , 0x3148), u32* , 0), (((temp_a0_3 >> 5) & 1) != 1)) || (temp_a0_3 & 1)) && (M2C_FIELD(temp_a1_2, void** , 0x210) != NULL) && (M2C_FIELD(M2C_FIELD(temp_a1_2, void** , 0xA0), s8* , 0x485) == 0)) {
                temp_a1_3 = M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0x210);
                M2C_FIELD(temp_a1_3, s32* , 8) = (s32) (M2C_FIELD(temp_a1_3, s32* , 8) + timerGetFieldsLastFrame__Fv_172A90(temp_a0_3, temp_a1_2, M2C_FIELD(&D_003156C0_172A90, void** , 0x3148)));
            }
            temp_v1_8 = M2C_FIELD(var_s1, s32* , 0x20F4);
            var_a1_3 = NULL;
            switch (temp_v1_8) {                    /* irregular */
            case 0x140:
            case 0x80:
            case 0x40:
                /* fallthrough */
            case 0x160:
            case 0xE0:
            case 0xA0:
            case 0x20:
                var_a1_3 = M2C_FIELD(arg0, void** , 0xB790);
                break;
            case 0x100:
            case 0x180:
            case 0xC0:
                /* fallthrough */
            case 0x120:
            case 0x60:
                var_a1_3 = M2C_FIELD(arg0, void** , 0xB794);
                break;
            case 0x1C0:
                /* fallthrough */
            case 0x1E0:
            case 0x1A0:
                var_a1_3 = M2C_FIELD(arg0, void** , 0xB798);
                break;
            }
            if (var_a1_3 != NULL) {
                temp_v1_9 = M2C_FIELD(var_s1, void** , 0x2028);
                if (M2C_FIELD(temp_v1_9, u8* , 0xC) == 0) {
                    M2C_FIELD(var_a1_3, s8* , 0xC) = 0;
                } else if (M2C_FIELD(var_s1, s8* , 0x485) != 0) {
                    M2C_FIELD(var_a1_3, s8* , 0xC) = 0;
                } else {
                    temp_v0_5 = temp_v1_9 + 0x20;
                    if (M2C_FIELD(var_s1, s8* , 0x49B) != 0) {
                        M2C_FIELD(var_a1_3, s8* , 0xC) = 0;
                    } else {
                        M2C_FIELD(var_a1_3, s128* , 0x20) = (s128) M2C_FIELD(temp_v1_9, s128* , 0x20);
                        M2C_FIELD(var_a1_3, s128* , 0x30) = (s128) M2C_FIELD(temp_v0_5, s128* , 0x10);
                        M2C_FIELD(var_a1_3, s128* , 0x40) = (s128) M2C_FIELD(temp_v0_5, s128* , 0x20);
                        M2C_FIELD(var_a1_3, s128* , 0x50) = (s128) M2C_FIELD(temp_v0_5, s128* , 0x30);
                        M2C_FIELD(var_a1_3, s128* , 0x10) = (s128) M2C_FIELD(var_s1, s128* , 0x1D0);
                        M2C_FIELD(var_a1_3, s8* , 0xC) = 1;
                    }
                }
            }
        }
    }
    func_001808F0_172A90(var_s2);
    temp_v0_6 = D_004F9E8C_172A90 + 1;
    D_004F9E8C_172A90 = temp_v0_6;
    if (temp_v0_6 >= 0x709) {
        D_004F9E8C_172A90 = 0;
        func_00176EA0_172A90(arg0);
    }
}
//@@ func_00172FA0 m2c0
#include "m2c_macros.h"
void func_00172FA0(void* arg0, s8 arg1, s32 arg2) {
    s32 temp_a0;
    void* temp_a3;

    temp_a3 = M2C_FIELD(arg0, void** , 0x3148);
    temp_a0 = ((u32) M2C_FIELD(temp_a3, u32* , 0) >> 1) & 0xF;
    if ((temp_a0 == 4) || (temp_a0 == 8)) {
        switch (arg2) {                             /* irregular */
        case 0:
            M2C_FIELD(temp_a3, s8* , 0x1A) = arg1;
            return;
        case 1:
            M2C_FIELD(temp_a3, s8* , 0x1B) = arg1;
            break;
        }
    }
}
//@@ func_00172FE8 m2c0
#include "m2c_macros.h"
M2C_UNK func_001731A8_172FE8() __asm__("func_001731A8");
M2C_UNK func_00173248_172FE8() __asm__("func_00173248");
s32 func_001734B8_172FE8() __asm__("func_001734B8");
M2C_UNK func_001A9278_172FE8() __asm__("func_001A9278");

void func_00172FE8(void* arg0, s32 arg1, s8 arg2, M2C_UNK arg3) {
    s32 temp_a0;
    s32 temp_a0_4;
    s32 temp_a0_5;
    s32 temp_a1_3;
    u32 temp_a0_3;
    u32 temp_v0;
    void* temp_a0_2;
    void* temp_a0_6;
    void* temp_a1;
    void* temp_a1_2;

    temp_a1 = M2C_FIELD(arg0, void** , 0x3148);
    temp_a0 = ((u32) M2C_FIELD(temp_a1, u32* , 0) >> 1) & 0xF;
    if (temp_a0 != 4) {
        if (temp_a0 == 8) {
            goto block_4;
        }
    } else if (arg1 == M2C_FIELD(temp_a1, s8* , 0x1A)) {
block_4:
        temp_a0_2 = M2C_FIELD(arg0, void** , 0x3148);
        if (((((u32) M2C_FIELD(temp_a0_2, u32* , 0) >> 1) & 0xF) != 8) || (arg1 == M2C_FIELD(temp_a0_2, s8* , 0x1A)) || (arg1 == M2C_FIELD(temp_a0_2, s8* , 0x1B))) {
            if (func_001734B8_172FE8(arg0, temp_a1) != 0) {
                temp_a1_2 = M2C_FIELD(arg0, void** , 0x3148);
                temp_a0_3 = M2C_FIELD(temp_a1_2, u32* , 0);
                if (((temp_a0_3 >> 1) & 0xF) == 4) {
                    temp_a0_4 = (temp_a0_3 >> 0xA) & 3;
                    switch (temp_a0_4) {            /* irregular */
                    case 0:
                        break;
                    case 2:
                        if (arg2 != M2C_FIELD(temp_a1_2, s8* , 0x1A)) {
                            M2C_FIELD(temp_a1_2, s8* , 0x1A) = arg2;
                        } else {
                        case 1:
                            func_001731A8_172FE8(arg0, arg1, arg3);
                        }
                        break;
                    default:
                        func_00173248_172FE8(arg0, arg1, arg3);
                        break;
                    }
                }
                temp_v0 = M2C_FIELD(M2C_FIELD(arg0, void** , 0x3148), u32* , 0);
                if (((temp_v0 >> 1) & 0xF) == 8) {
                    temp_a0_5 = (temp_v0 >> 0xA) & 3;
                    switch (temp_a0_5) {            /* switch 1; irregular */
                    case 0:                         /* switch 1 */
                        break;
                    case 1:                         /* switch 1 */
                        func_001731A8_172FE8(arg0, arg1, arg3);
                        break;
                    default:                        /* switch 1 */
                        func_00173248_172FE8(arg0, arg1, arg3);
                        break;
                    }
                }
                temp_a0_6 = M2C_FIELD(arg0, void** , 0x3148);
                temp_a1_3 = *M2C_FIELD(arg0, s32** , 4);
                if (M2C_FIELD(temp_a0_6, s8* , 0x1A) == temp_a1_3) {
                    func_001A9278_172FE8(temp_a0_6, temp_a1_3);
                }
            }
        }
    }
}
//@@ func_001731A8 m2c0
#include "m2c_macros.h"
void func_001731A8(void* arg0, s32 arg1, s32 arg2) {
    s32 var_a3;
    s32 var_v0;
    s32 var_v0_2;
    s8 temp_a1;
    s8 temp_a1_2;
    s8 var_a1;
    void* temp_a0;

    temp_a1 = arg1 + 1;
    var_a1 = (temp_a1 >= 8) ? 0 : temp_a1;
    var_a3 = 0;
    var_v0 = var_a1 * 0x220;
loop_4:
    temp_a0 = var_v0 + arg0;
    if (M2C_FIELD(temp_a0, s32* , 0x10) == -1) {
        var_a3 += 1;
        goto block_2;
    }
    if (M2C_FIELD(temp_a0, s32* , 0x220) == 0) {
        var_a3 += 1;
        goto block_2;
    }
    var_v0_2 = var_a3 ^ 8;
    if (M2C_FIELD(temp_a0, s32* , 0x14) != arg2) {
        if (arg2 != -1) {
            var_a3 += 1;
block_2:
            if (var_a3 < 8) {
                var_a1 = (var_a1 >= 8) ? 0 : var_a1;
                var_v0 = var_a1 * 0x220;
                goto loop_4;
            }
            goto block_14;
        }
block_14:
        var_v0_2 = var_a3 ^ 8;
    }
    temp_a1_2 = (var_v0_2 == 0) ? -1 : var_a1;
    if ((u32) (arg2 + 1) < 2U) {
        M2C_FIELD(M2C_FIELD(arg0, void** , 0x3148), s8* , 0x1A) = temp_a1_2;
        return;
    }
    M2C_FIELD(M2C_FIELD(arg0, void** , 0x3148), s8* , 0x1B) = temp_a1_2;
}
//@@ func_00173248 m2c0
#include "m2c_macros.h"
M2C_UNK func_001731A8_173248() __asm__("func_001731A8");
s8 mathfRand__Fii_173248() __asm__("mathfRand__Fii");

void func_00173248(void* arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;
    s32 var_s0;
    s8 temp_v0;
    void* temp_v0_2;
    void* temp_v1;

    var_s0 = 0;
loop_1:
    temp_v0 = mathfRand__Fii_173248(0, 7);
    temp_v1 = (temp_v0 * 0x220) + arg0;
    temp_a0 = M2C_FIELD(temp_v1, s32* , 0x10);
    if ((temp_a0 == -1) || (M2C_FIELD(temp_v1, s32* , 0x220) == 0) || (temp_a0 == arg1) || ((M2C_FIELD(temp_v1, s32* , 0x14) != arg2) && (arg2 != -1))) {
        var_s0 += 1;
        if (var_s0 >= 0x64) {

        } else {
            goto loop_1;
        }
    }
    if (var_s0 == 0x64) {
        func_001731A8_173248(arg0, arg1, arg2);
        return;
    }
    temp_v0_2 = M2C_FIELD(arg0, void** , 0x3148);
    if ((u32) (arg2 + 1) < 2U) {
        M2C_FIELD(temp_v0_2, s8* , 0x1A) = temp_v0;
        return;
    }
    M2C_FIELD(temp_v0_2, s8* , 0x1B) = temp_v0;
}
//@@ func_00173340 m2c0
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
//@@ func_001734B8 m2c0
#include "m2c_macros.h"
s32 dmeGetMyClientIndex_1734B8() __asm__("dmeGetMyClientIndex");
s32 func_00173500_1734B8() __asm__("func_00173500");

s32 func_001734B8(void* arg0) {
    u8 sp[0x10];
    s32 var_v0;

    var_v0 = 0;
    if (dmeGetMyClientIndex_1734B8(sp, M2C_FIELD(arg0, s32* , 0x2CF0)) == 0) {
        var_v0 = subroutine_arg0 == func_00173500_1734B8(arg0);
    }
    return var_v0;
}
//@@ func_001734B8 m2c1
#include "m2c_macros.h"
s32 dmeGetMyClientIndex_1734B8() __asm__("dmeGetMyClientIndex");
s32 func_00173500_1734B8() __asm__("func_00173500");

s32 func_001734B8(void* arg0) {
    u8 sp[0x8];
    s32 var_v0;

    var_v0 = 0;
    if (dmeGetMyClientIndex_1734B8(sp, M2C_FIELD(arg0, s32* , 0x2CF0)) == 0) {
        var_v0 = subroutine_arg0 == func_00173500_1734B8(arg0);
    }
    return var_v0;
}
//@@ func_001734B8 m2c2
#include "m2c_macros.h"
s32 dmeGetMyClientIndex_1734B8() __asm__("dmeGetMyClientIndex");
s32 func_00173500_1734B8() __asm__("func_00173500");

s32 func_001734B8(void* arg0) {
    u8 sp[0x4];
    s32 var_v0;

    var_v0 = 0;
    if (dmeGetMyClientIndex_1734B8(sp, M2C_FIELD(arg0, s32* , 0x2CF0)) == 0) {
        var_v0 = subroutine_arg0 == func_00173500_1734B8(arg0);
    }
    return var_v0;
}
//@@ func_00173500 m2c0
#include "m2c_macros.h"
s32 func_001733F8_173500() __asm__("func_001733F8");
s32 func_00266DE0_173500() __asm__("func_00266DE0");

s32 func_00173500(void* arg0) {
    u8 sp[0x10];
    s32 temp_v0;

    temp_v0 = func_001733F8_173500();
    if (temp_v0 == 1) {

    } else if (temp_v0 == 2) {
        if (func_00266DE0_173500(sp, M2C_FIELD(arg0, s32* , 0x2CF0)) != 0) {

        }
    }
    return subroutine_arg0;
}
//@@ func_00173500 m2c1
#include "m2c_macros.h"
s32 func_001733F8_173500() __asm__("func_001733F8");
s32 func_00266DE0_173500() __asm__("func_00266DE0");

s32 func_00173500(void* arg0) {
    u8 sp[0x8];
    s32 temp_v0;

    temp_v0 = func_001733F8_173500();
    if (temp_v0 == 1) {

    } else if (temp_v0 == 2) {
        if (func_00266DE0_173500(sp, M2C_FIELD(arg0, s32* , 0x2CF0)) != 0) {

        }
    }
    return subroutine_arg0;
}
//@@ func_00173500 m2c2
#include "m2c_macros.h"
s32 func_001733F8_173500() __asm__("func_001733F8");
s32 func_00266DE0_173500() __asm__("func_00266DE0");

s32 func_00173500(void* arg0) {
    u8 sp[0x4];
    s32 temp_v0;

    temp_v0 = func_001733F8_173500();
    if (temp_v0 == 1) {

    } else if (temp_v0 == 2) {
        if (func_00266DE0_173500(sp, M2C_FIELD(arg0, s32* , 0x2CF0)) != 0) {

        }
    }
    return subroutine_arg0;
}
//@@ func_00173570 m2c0
#include "m2c_macros.h"
M2C_UNK func_00171B78_173570() __asm__("func_00171B78");

void func_00173570(void* arg0, s32 arg1) {
    M2C_FIELD(arg0, s32* , 0x1BB4) = arg1;
    M2C_FIELD(M2C_FIELD(arg0, void** , 4), s32* , 0x204) = arg1;
    if (M2C_FIELD(arg0, s32* , 0x1BB4) > 0) {
        func_00171B78_173570(-1);
    }
}
//@@ func_001735A8 m2c0
#include "m2c_macros.h"
void* netGetDmeTime_1735A8() __asm__("netGetDmeTime");

u8 func_001735A8(s32 arg0, s32 arg1, void* arg2) {
    s32 var_s0;
    void* temp_v0;

    var_s0 = M2C_FIELD(arg2, s32* , 0x21B0);
    if (arg1 >= 0) {
        temp_v0 = netGetDmeTime_1735A8();
        if (temp_v0 != NULL) {
            var_s0 = (s32) M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), u8* , 0x30);
        }
    }
    return (u8) var_s0;
}
//@@ func_00173810 m2c0
#include "m2c_macros.h"
M2C_UNK func_001703E8_173810() __asm__("func_001703E8");
s32 netGetDmeTime_173810() __asm__("netGetDmeTime");

void func_00173810(s32 arg0, s32 arg1) {
    s32 var_a1;
    s32 var_s0;
    s32 var_s1;

    var_a1 = arg1;
loop_1:
    var_s1 = 1;
    func_001703E8_173810(arg0, var_a1);
    var_s0 = 0;
    var_a1 = 0;
    do {
        var_s0 += 1;
        var_s1 = (netGetDmeTime_173810(arg0, var_a1) == 0) ? 0 : var_s1;
        var_a1 = var_s0;
    } while (var_s0 < 4);
    if (var_s1 == 0) {
        goto loop_1;
    }
}
//@@ func_00173880 m2c0
#include "m2c_macros.h"
extern s32 D_004B1340_173880 __asm__("D_004B1340");
extern s32 D_004B1360_173880 __asm__("D_004B1360");
extern M2C_UNK D_004B1380_173880 __asm__("D_004B1380");
extern s32 D_004FA858_173880 __asm__("D_004FA858");

s32 func_00173880(void* arg0, void* arg1) {
    s32 temp_a3;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 temp_v1_6;
    s32 temp_v1_7;
    s32 temp_v1_8;
    u32 var_a1;
    void* temp_a0;
    void* temp_a0_2;
    void* temp_v0;
    void* temp_v1;

    if (M2C_FIELD(arg0, s32* , 0x1BB4) == 0xB) {
        temp_v0 = M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0);
        temp_v1 = M2C_FIELD(temp_v0, void** , 0x20D0);
        if ((temp_v1 != NULL) && (M2C_FIELD(temp_v0, f32* , 0x404) > 0.0f)) {
            M2C_FIELD(temp_v1, u8* , 0x33) = (u8) M2C_FIELD(arg1, u8* , 1);
            M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), void** , 0x20D0), u8* , 0x34) = (u8) M2C_FIELD(arg1, u8* , 2);
            M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), void** , 0x20D0), u8* , 0x35) = (u8) M2C_FIELD(arg1, u8* , 3);
            if (D_004FA858_173880 != 3) {
                M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), void** , 0x20D0), u8* , 0x36) = (u8) M2C_FIELD(arg1, u8* , 5);
                M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), void** , 0x20D0), u8* , 0x37) = (u8) M2C_FIELD(arg1, u8* , 6);
                if (D_004B1360_173880 != 0) {
                    temp_a0 = M2C_FIELD(arg0, void** , 4);
                    temp_a3 = M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_a0, void** , 0xA0), void** , 0x20D0), u8* , 0x35) << 8;
                    var_a1 = 0;
                    if (temp_a3 & 0x100) {
                        if (D_004B1360_173880 == 1) {
                            var_a1 = 0x4000;
                        } else {
                            var_a1 = ((D_004B1360_173880 ^ 2) != 0) ? 0U : 0x4000U;
                        }
                    }
                    if (temp_a3 & 0x200) {
                        temp_v1_2 = (&D_004B1360_173880)[0];
                        if (temp_v1_2 == 1) {
                            var_a1 |= 0x8000;
                        } else if (temp_v1_2 == 2) {
                            var_a1 |= 0x2000;
                        }
                    }
                    if (temp_a3 & 0x400) {
                        temp_v1_3 = (&D_004B1360_173880)[0];
                        if (temp_v1_3 == 1) {
                            var_a1 |= 0x1000;
                        } else if (temp_v1_3 == 2) {
                            var_a1 |= 0x400;
                        }
                    }
                    if (temp_a3 & 0x800) {
                        temp_v1_4 = (&D_004B1360_173880)[0];
                        if (temp_v1_4 == 1) {
                            var_a1 |= 0x2000;
                        } else if (temp_v1_4 == 2) {
                            var_a1 |= 0x800;
                        }
                    }
                    if (temp_a3 & 0x1000) {
                        temp_v1_5 = (&D_004B1360_173880)[0];
                        if (temp_v1_5 == 1) {
                            var_a1 |= 0x400;
                        } else if (temp_v1_5 == 2) {
                            var_a1 |= 0x1000;
                        }
                    }
                    if (temp_a3 & 0x2000) {
                        temp_v1_6 = (&D_004B1360_173880)[0];
                        if (temp_v1_6 == 1) {
                            var_a1 |= 0x800;
                        } else if (temp_v1_6 == 2) {
                            var_a1 |= 0x100;
                        }
                    }
                    if (temp_a3 & 0x4000) {
                        temp_v1_7 = (&D_004B1360_173880)[0];
                        if (temp_v1_7 == 1) {
                            var_a1 |= 0x100;
                        } else if (temp_v1_7 == 2) {
                            var_a1 |= 0x8000;
                        }
                    }
                    if ((temp_a3 & 0x8000) && ((temp_v1_8 = (&D_004B1360_173880)[0], (temp_v1_8 == 1)) || (temp_v1_8 == 2))) {
                        var_a1 |= 0x200;
                    }
                    M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_a0, void** , 0xA0), void** , 0x20D0), s8* , 0x35) = (s8) (var_a1 >> 8);
                }
            } else {
                if (M2C_FIELD(&D_004B1380_173880, s8* , 2) >= 0) {
                    M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), void** , 0x20D0), u8* , 0x36) = (u8) M2C_FIELD(&D_004B1380_173880, s8* , 2);
                } else {
                    if ((u32) ((u8) M2C_FIELD(&D_004B1380_173880, s8* , 2) & 0xFF) >= 0xA0U) {
                        temp_a0_2 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), void** , 0x20D0);
                        M2C_FIELD(temp_a0_2, u8* , 0x35) = (u8) (M2C_FIELD(temp_a0_2, u8* , 0x35) & 0xDF);
                    }
                    M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), void** , 0x20D0), s8* , 0x36) = 0x7F;
                }
                M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), void** , 0x20D0), u8* , 0x37) = (u8) M2C_FIELD(&D_004B1380_173880, u8* , 1);
            }
            if (D_004B1340_173880 == 4) {
                M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), void** , 0x20D0), s8* , 0x36) = 0x88;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), void** , 0x20D0), s8* , 0x37) = 0x88;
                if (D_004B1340_173880 == D_004B1340_173880) {
                    M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), void** , 0x20D0), s8* , 0x36) = 0x88;
                    M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), void** , 0x20D0), s8* , 0x37) = 0x88;
                }
            }
        }
    }
    return 1;
}
//@@ func_00173BE8 m2c0
#include "m2c_macros.h"
M2C_UNK netSendGameEvent_173BE8() __asm__("netSendGameEvent");
s64 timerGetCurTics__Fv_173BE8() __asm__("timerGetCurTics__Fv");
extern s32 D_004F9C9C_173BE8 __asm__("D_004F9C9C");

void func_00173BE8(s32 arg0, M2C_UNK arg1) {
    u8 sp[0x50];
    if (D_004F9C9C_173BE8 == 0) {
        netSendGameEvent_173BE8(arg0, arg1, sp, timerGetCurTics__Fv_173BE8());
        D_004F9C9C_173BE8 = 1;
    }
}
//@@ func_00173BE8 m2c1
#include "m2c_macros.h"
M2C_UNK netSendGameEvent_173BE8() __asm__("netSendGameEvent");
s64 timerGetCurTics__Fv_173BE8() __asm__("timerGetCurTics__Fv");
extern s32 D_004F9C9C_173BE8 __asm__("D_004F9C9C");

void func_00173BE8(s32 arg0, M2C_UNK arg1) {
    u8 sp[0x40];
    if (D_004F9C9C_173BE8 == 0) {
        netSendGameEvent_173BE8(arg0, arg1, sp, timerGetCurTics__Fv_173BE8());
        D_004F9C9C_173BE8 = 1;
    }
}
//@@ func_00173BE8 m2c2
#include "m2c_macros.h"
M2C_UNK netSendGameEvent_173BE8() __asm__("netSendGameEvent");
s64 timerGetCurTics__Fv_173BE8() __asm__("timerGetCurTics__Fv");
extern s32 D_004F9C9C_173BE8 __asm__("D_004F9C9C");

void func_00173BE8(s32 arg0, M2C_UNK arg1) {
    u8 sp[0x30];
    if (D_004F9C9C_173BE8 == 0) {
        netSendGameEvent_173BE8(arg0, arg1, sp, timerGetCurTics__Fv_173BE8());
        D_004F9C9C_173BE8 = 1;
    }
}
//@@ func_00173BE8 m2c3
#include "m2c_macros.h"
M2C_UNK netSendGameEvent_173BE8() __asm__("netSendGameEvent");
s64 timerGetCurTics__Fv_173BE8() __asm__("timerGetCurTics__Fv");
extern s32 D_004F9C9C_173BE8 __asm__("D_004F9C9C");

void func_00173BE8(s32 arg0, M2C_UNK arg1) {
    u8 sp[0x20];
    if (D_004F9C9C_173BE8 == 0) {
        netSendGameEvent_173BE8(arg0, arg1, sp, timerGetCurTics__Fv_173BE8());
        D_004F9C9C_173BE8 = 1;
    }
}
//@@ func_00173BE8 m2c4
#include "m2c_macros.h"
M2C_UNK netSendGameEvent_173BE8() __asm__("netSendGameEvent");
s64 timerGetCurTics__Fv_173BE8() __asm__("timerGetCurTics__Fv");
extern s32 D_004F9C9C_173BE8 __asm__("D_004F9C9C");

void func_00173BE8(s32 arg0, M2C_UNK arg1) {
    u8 sp[0x10];
    if (D_004F9C9C_173BE8 == 0) {
        netSendGameEvent_173BE8(arg0, arg1, sp, timerGetCurTics__Fv_173BE8());
        D_004F9C9C_173BE8 = 1;
    }
}
//@@ func_00173BE8 m2c5
#include "m2c_macros.h"
M2C_UNK netSendGameEvent_173BE8() __asm__("netSendGameEvent");
s64 timerGetCurTics__Fv_173BE8() __asm__("timerGetCurTics__Fv");
extern s32 D_004F9C9C_173BE8 __asm__("D_004F9C9C");

void func_00173BE8(s32 arg0, M2C_UNK arg1) {
    u8 sp[0x8];
    if (D_004F9C9C_173BE8 == 0) {
        netSendGameEvent_173BE8(arg0, arg1, sp, timerGetCurTics__Fv_173BE8());
        D_004F9C9C_173BE8 = 1;
    }
}
//@@ func_00173C50 m2c0
#include "m2c_macros.h"
s32 func_001734B8_173C50() __asm__("func_001734B8");
s32 func_00173500_173C50() __asm__("func_00173500");
s32 netGetMyClientIndex_173C50() __asm__("netGetMyClientIndex");
M2C_UNK netMsgGameEventHandler_173C50() __asm__("netMsgGameEventHandler");
M2C_UNK netSendGameEvent_173C50() __asm__("netSendGameEvent");
M2C_UNK printf_173C50() __asm__("printf");
extern M2C_UNK D_004E7E70_173C50 __asm__("D_004E7E70");

void func_00173C50(void* arg0) {
    u8 sp[0x50];
    netGetMyClientIndex_173C50();
    if (func_001734B8_173C50(arg0) != 0) {
        M2C_FIELD(arg0, s32* , 0x307C) = (s32) subroutine_arg0;
        printf_173C50(&D_004E7E70_173C50);
        printf_173C50(">>>>> 2 Setting ConnectionSessionMaster = %d\n", M2C_FIELD(arg0, s32* , 0x307C));
        printf_173C50(&D_004E7E70_173C50);
        M2C_FIELD(arg0, s32* , 0x2E8C) = 1;
        netMsgGameEventHandler_173C50(M2C_FIELD(arg0, s32* , 0x2CF0), M2C_FIELD(arg0, s32* , 0x129C), netGetMyClientIndex_173C50(arg0), sp);
        return;
    }
    netSendGameEvent_173C50(arg0, func_00173500_173C50(arg0), sp);
}
//@@ func_00173C50 m2c1
#include "m2c_macros.h"
s32 func_001734B8_173C50() __asm__("func_001734B8");
s32 func_00173500_173C50() __asm__("func_00173500");
s32 netGetMyClientIndex_173C50() __asm__("netGetMyClientIndex");
M2C_UNK netMsgGameEventHandler_173C50() __asm__("netMsgGameEventHandler");
M2C_UNK netSendGameEvent_173C50() __asm__("netSendGameEvent");
M2C_UNK printf_173C50() __asm__("printf");
extern M2C_UNK D_004E7E70_173C50 __asm__("D_004E7E70");

void func_00173C50(void* arg0) {
    u8 sp[0x40];
    netGetMyClientIndex_173C50();
    if (func_001734B8_173C50(arg0) != 0) {
        M2C_FIELD(arg0, s32* , 0x307C) = (s32) subroutine_arg0;
        printf_173C50(&D_004E7E70_173C50);
        printf_173C50(">>>>> 2 Setting ConnectionSessionMaster = %d\n", M2C_FIELD(arg0, s32* , 0x307C));
        printf_173C50(&D_004E7E70_173C50);
        M2C_FIELD(arg0, s32* , 0x2E8C) = 1;
        netMsgGameEventHandler_173C50(M2C_FIELD(arg0, s32* , 0x2CF0), M2C_FIELD(arg0, s32* , 0x129C), netGetMyClientIndex_173C50(arg0), sp);
        return;
    }
    netSendGameEvent_173C50(arg0, func_00173500_173C50(arg0), sp);
}
//@@ func_00173C50 m2c2
#include "m2c_macros.h"
s32 func_001734B8_173C50() __asm__("func_001734B8");
s32 func_00173500_173C50() __asm__("func_00173500");
s32 netGetMyClientIndex_173C50() __asm__("netGetMyClientIndex");
M2C_UNK netMsgGameEventHandler_173C50() __asm__("netMsgGameEventHandler");
M2C_UNK netSendGameEvent_173C50() __asm__("netSendGameEvent");
M2C_UNK printf_173C50() __asm__("printf");
extern M2C_UNK D_004E7E70_173C50 __asm__("D_004E7E70");

void func_00173C50(void* arg0) {
    u8 sp[0x30];
    netGetMyClientIndex_173C50();
    if (func_001734B8_173C50(arg0) != 0) {
        M2C_FIELD(arg0, s32* , 0x307C) = (s32) subroutine_arg0;
        printf_173C50(&D_004E7E70_173C50);
        printf_173C50(">>>>> 2 Setting ConnectionSessionMaster = %d\n", M2C_FIELD(arg0, s32* , 0x307C));
        printf_173C50(&D_004E7E70_173C50);
        M2C_FIELD(arg0, s32* , 0x2E8C) = 1;
        netMsgGameEventHandler_173C50(M2C_FIELD(arg0, s32* , 0x2CF0), M2C_FIELD(arg0, s32* , 0x129C), netGetMyClientIndex_173C50(arg0), sp);
        return;
    }
    netSendGameEvent_173C50(arg0, func_00173500_173C50(arg0), sp);
}
//@@ func_00173C50 m2c3
#include "m2c_macros.h"
s32 func_001734B8_173C50() __asm__("func_001734B8");
s32 func_00173500_173C50() __asm__("func_00173500");
s32 netGetMyClientIndex_173C50() __asm__("netGetMyClientIndex");
M2C_UNK netMsgGameEventHandler_173C50() __asm__("netMsgGameEventHandler");
M2C_UNK netSendGameEvent_173C50() __asm__("netSendGameEvent");
M2C_UNK printf_173C50() __asm__("printf");
extern M2C_UNK D_004E7E70_173C50 __asm__("D_004E7E70");

void func_00173C50(void* arg0) {
    u8 sp[0x20];
    netGetMyClientIndex_173C50();
    if (func_001734B8_173C50(arg0) != 0) {
        M2C_FIELD(arg0, s32* , 0x307C) = (s32) subroutine_arg0;
        printf_173C50(&D_004E7E70_173C50);
        printf_173C50(">>>>> 2 Setting ConnectionSessionMaster = %d\n", M2C_FIELD(arg0, s32* , 0x307C));
        printf_173C50(&D_004E7E70_173C50);
        M2C_FIELD(arg0, s32* , 0x2E8C) = 1;
        netMsgGameEventHandler_173C50(M2C_FIELD(arg0, s32* , 0x2CF0), M2C_FIELD(arg0, s32* , 0x129C), netGetMyClientIndex_173C50(arg0), sp);
        return;
    }
    netSendGameEvent_173C50(arg0, func_00173500_173C50(arg0), sp);
}
//@@ func_00173C50 m2c4
#include "m2c_macros.h"
s32 func_001734B8_173C50() __asm__("func_001734B8");
s32 func_00173500_173C50() __asm__("func_00173500");
s32 netGetMyClientIndex_173C50() __asm__("netGetMyClientIndex");
M2C_UNK netMsgGameEventHandler_173C50() __asm__("netMsgGameEventHandler");
M2C_UNK netSendGameEvent_173C50() __asm__("netSendGameEvent");
M2C_UNK printf_173C50() __asm__("printf");
extern M2C_UNK D_004E7E70_173C50 __asm__("D_004E7E70");

void func_00173C50(void* arg0) {
    u8 sp[0x10];
    netGetMyClientIndex_173C50();
    if (func_001734B8_173C50(arg0) != 0) {
        M2C_FIELD(arg0, s32* , 0x307C) = (s32) subroutine_arg0;
        printf_173C50(&D_004E7E70_173C50);
        printf_173C50(">>>>> 2 Setting ConnectionSessionMaster = %d\n", M2C_FIELD(arg0, s32* , 0x307C));
        printf_173C50(&D_004E7E70_173C50);
        M2C_FIELD(arg0, s32* , 0x2E8C) = 1;
        netMsgGameEventHandler_173C50(M2C_FIELD(arg0, s32* , 0x2CF0), M2C_FIELD(arg0, s32* , 0x129C), netGetMyClientIndex_173C50(arg0), sp);
        return;
    }
    netSendGameEvent_173C50(arg0, func_00173500_173C50(arg0), sp);
}
//@@ func_00173C50 m2c5
#include "m2c_macros.h"
s32 func_001734B8_173C50() __asm__("func_001734B8");
s32 func_00173500_173C50() __asm__("func_00173500");
s32 netGetMyClientIndex_173C50() __asm__("netGetMyClientIndex");
M2C_UNK netMsgGameEventHandler_173C50() __asm__("netMsgGameEventHandler");
M2C_UNK netSendGameEvent_173C50() __asm__("netSendGameEvent");
M2C_UNK printf_173C50() __asm__("printf");
extern M2C_UNK D_004E7E70_173C50 __asm__("D_004E7E70");

void func_00173C50(void* arg0) {
    u8 sp[0x8];
    netGetMyClientIndex_173C50();
    if (func_001734B8_173C50(arg0) != 0) {
        M2C_FIELD(arg0, s32* , 0x307C) = (s32) subroutine_arg0;
        printf_173C50(&D_004E7E70_173C50);
        printf_173C50(">>>>> 2 Setting ConnectionSessionMaster = %d\n", M2C_FIELD(arg0, s32* , 0x307C));
        printf_173C50(&D_004E7E70_173C50);
        M2C_FIELD(arg0, s32* , 0x2E8C) = 1;
        netMsgGameEventHandler_173C50(M2C_FIELD(arg0, s32* , 0x2CF0), M2C_FIELD(arg0, s32* , 0x129C), netGetMyClientIndex_173C50(arg0), sp);
        return;
    }
    netSendGameEvent_173C50(arg0, func_00173500_173C50(arg0), sp);
}
//@@ func_00173D08 m2c0
#include "m2c_macros.h"
M2C_UNK func_001703E8_173D08() __asm__("func_001703E8");
s32 func_00173500_173D08() __asm__("func_00173500");
M2C_UNK func_00173C50_173D08() __asm__("func_00173C50");
f32 func_001F2CC8_173D08() __asm__("func_001F2CC8");
M2C_UNK netSendGameEvent_173D08() __asm__("netSendGameEvent");
s64 timerGetCurTics__Fv_173D08() __asm__("timerGetCurTics__Fv");
extern s32 D_003188E0_173D08 __asm__("D_003188E0");

s32 func_00173D08(void* arg0, s32 arg1) {
    u8 sp[0x60];
    f32 var_f0;
    s32 temp_a0;
    s32 var_s4;
    s32 var_v0;
    s32 var_v0_2;
    s64 temp_v0;
    s64 var_s0;
    s64 var_s1;
    s64 var_s3;

    var_s4 = 0x1B7740;
    var_s3 = timerGetCurTics__Fv_173D08();
    var_s1 = var_s3;
    if (arg1 > 0) {
        var_s4 = arg1 * 0x3E8;
    }
    var_s0 = (s64) (var_s3 << 0x20) >> 0x20;
    netSendGameEvent_173D08(arg0, func_00173500_173D08(arg0), sp);
    netSendGameEvent_173D08(arg0, func_00173500_173D08(arg0), sp);
    netSendGameEvent_173D08(arg0, func_00173500_173D08(arg0), sp);
    var_v0 = 1;
    if (D_003188E0_173D08 == 0) {
        func_00173C50_173D08(arg0);
        M2C_FIELD(arg0, s32* , 0x2E8C) = 0;
loop_4:
        temp_v0 = timerGetCurTics__Fv_173D08();
        if (temp_v0 < var_s0) {
            var_v0_2 = (temp_v0 + 0x10000) - var_s0;
        } else {
            var_v0_2 = temp_v0 - var_s0;
        }
        var_s1 += var_v0_2;
        temp_a0 = var_s1 - var_s3;
        var_s0 = temp_v0;
        if (temp_a0 >= 0) {
            var_f0 = func_001F2CC8_173D08(temp_a0);
        } else {
            var_f0 = 2.0f * func_001F2CC8_173D08((temp_a0 & 1) | ((u64) temp_a0 >> 1));
        }
        if ((var_f0 / 576.0f) > 5000.0f) {
            var_s4 -= 0x1388;
            var_v0 = 0;
            if (var_s4 >= 0) {
                func_00173C50_173D08(arg0);
                var_s3 = timerGetCurTics__Fv_173D08();
                var_s1 = var_s3;
                var_s0 = (s64) (var_s3 << 0x20) >> 0x20;
                goto block_13;
            }
        } else {
block_13:
            func_001703E8_173D08(arg0);
            var_v0 = 1;
            if (M2C_FIELD(arg0, s32* , 0x2E8C) == 0) {
                goto loop_4;
            }
        }
    }
    return var_v0;
}
//@@ func_00173D08 m2c1
#include "m2c_macros.h"
M2C_UNK func_001703E8_173D08() __asm__("func_001703E8");
s32 func_00173500_173D08() __asm__("func_00173500");
M2C_UNK func_00173C50_173D08() __asm__("func_00173C50");
f32 func_001F2CC8_173D08() __asm__("func_001F2CC8");
M2C_UNK netSendGameEvent_173D08() __asm__("netSendGameEvent");
s64 timerGetCurTics__Fv_173D08() __asm__("timerGetCurTics__Fv");
extern s32 D_003188E0_173D08 __asm__("D_003188E0");

s32 func_00173D08(void* arg0, s32 arg1) {
    u8 sp[0x50];
    f32 var_f0;
    s32 temp_a0;
    s32 var_s4;
    s32 var_v0;
    s32 var_v0_2;
    s64 temp_v0;
    s64 var_s0;
    s64 var_s1;
    s64 var_s3;

    var_s4 = 0x1B7740;
    var_s3 = timerGetCurTics__Fv_173D08();
    var_s1 = var_s3;
    if (arg1 > 0) {
        var_s4 = arg1 * 0x3E8;
    }
    var_s0 = (s64) (var_s3 << 0x20) >> 0x20;
    netSendGameEvent_173D08(arg0, func_00173500_173D08(arg0), sp);
    netSendGameEvent_173D08(arg0, func_00173500_173D08(arg0), sp);
    netSendGameEvent_173D08(arg0, func_00173500_173D08(arg0), sp);
    var_v0 = 1;
    if (D_003188E0_173D08 == 0) {
        func_00173C50_173D08(arg0);
        M2C_FIELD(arg0, s32* , 0x2E8C) = 0;
loop_4:
        temp_v0 = timerGetCurTics__Fv_173D08();
        if (temp_v0 < var_s0) {
            var_v0_2 = (temp_v0 + 0x10000) - var_s0;
        } else {
            var_v0_2 = temp_v0 - var_s0;
        }
        var_s1 += var_v0_2;
        temp_a0 = var_s1 - var_s3;
        var_s0 = temp_v0;
        if (temp_a0 >= 0) {
            var_f0 = func_001F2CC8_173D08(temp_a0);
        } else {
            var_f0 = 2.0f * func_001F2CC8_173D08((temp_a0 & 1) | ((u64) temp_a0 >> 1));
        }
        if ((var_f0 / 576.0f) > 5000.0f) {
            var_s4 -= 0x1388;
            var_v0 = 0;
            if (var_s4 >= 0) {
                func_00173C50_173D08(arg0);
                var_s3 = timerGetCurTics__Fv_173D08();
                var_s1 = var_s3;
                var_s0 = (s64) (var_s3 << 0x20) >> 0x20;
                goto block_13;
            }
        } else {
block_13:
            func_001703E8_173D08(arg0);
            var_v0 = 1;
            if (M2C_FIELD(arg0, s32* , 0x2E8C) == 0) {
                goto loop_4;
            }
        }
    }
    return var_v0;
}
//@@ func_00173D08 m2c2
#include "m2c_macros.h"
M2C_UNK func_001703E8_173D08() __asm__("func_001703E8");
s32 func_00173500_173D08() __asm__("func_00173500");
M2C_UNK func_00173C50_173D08() __asm__("func_00173C50");
f32 func_001F2CC8_173D08() __asm__("func_001F2CC8");
M2C_UNK netSendGameEvent_173D08() __asm__("netSendGameEvent");
s64 timerGetCurTics__Fv_173D08() __asm__("timerGetCurTics__Fv");
extern s32 D_003188E0_173D08 __asm__("D_003188E0");

s32 func_00173D08(void* arg0, s32 arg1) {
    u8 sp[0x40];
    f32 var_f0;
    s32 temp_a0;
    s32 var_s4;
    s32 var_v0;
    s32 var_v0_2;
    s64 temp_v0;
    s64 var_s0;
    s64 var_s1;
    s64 var_s3;

    var_s4 = 0x1B7740;
    var_s3 = timerGetCurTics__Fv_173D08();
    var_s1 = var_s3;
    if (arg1 > 0) {
        var_s4 = arg1 * 0x3E8;
    }
    var_s0 = (s64) (var_s3 << 0x20) >> 0x20;
    netSendGameEvent_173D08(arg0, func_00173500_173D08(arg0), sp);
    netSendGameEvent_173D08(arg0, func_00173500_173D08(arg0), sp);
    netSendGameEvent_173D08(arg0, func_00173500_173D08(arg0), sp);
    var_v0 = 1;
    if (D_003188E0_173D08 == 0) {
        func_00173C50_173D08(arg0);
        M2C_FIELD(arg0, s32* , 0x2E8C) = 0;
loop_4:
        temp_v0 = timerGetCurTics__Fv_173D08();
        if (temp_v0 < var_s0) {
            var_v0_2 = (temp_v0 + 0x10000) - var_s0;
        } else {
            var_v0_2 = temp_v0 - var_s0;
        }
        var_s1 += var_v0_2;
        temp_a0 = var_s1 - var_s3;
        var_s0 = temp_v0;
        if (temp_a0 >= 0) {
            var_f0 = func_001F2CC8_173D08(temp_a0);
        } else {
            var_f0 = 2.0f * func_001F2CC8_173D08((temp_a0 & 1) | ((u64) temp_a0 >> 1));
        }
        if ((var_f0 / 576.0f) > 5000.0f) {
            var_s4 -= 0x1388;
            var_v0 = 0;
            if (var_s4 >= 0) {
                func_00173C50_173D08(arg0);
                var_s3 = timerGetCurTics__Fv_173D08();
                var_s1 = var_s3;
                var_s0 = (s64) (var_s3 << 0x20) >> 0x20;
                goto block_13;
            }
        } else {
block_13:
            func_001703E8_173D08(arg0);
            var_v0 = 1;
            if (M2C_FIELD(arg0, s32* , 0x2E8C) == 0) {
                goto loop_4;
            }
        }
    }
    return var_v0;
}
//@@ func_00173D08 m2c3
#include "m2c_macros.h"
M2C_UNK func_001703E8_173D08() __asm__("func_001703E8");
s32 func_00173500_173D08() __asm__("func_00173500");
M2C_UNK func_00173C50_173D08() __asm__("func_00173C50");
f32 func_001F2CC8_173D08() __asm__("func_001F2CC8");
M2C_UNK netSendGameEvent_173D08() __asm__("netSendGameEvent");
s64 timerGetCurTics__Fv_173D08() __asm__("timerGetCurTics__Fv");
extern s32 D_003188E0_173D08 __asm__("D_003188E0");

s32 func_00173D08(void* arg0, s32 arg1) {
    u8 sp[0x30];
    f32 var_f0;
    s32 temp_a0;
    s32 var_s4;
    s32 var_v0;
    s32 var_v0_2;
    s64 temp_v0;
    s64 var_s0;
    s64 var_s1;
    s64 var_s3;

    var_s4 = 0x1B7740;
    var_s3 = timerGetCurTics__Fv_173D08();
    var_s1 = var_s3;
    if (arg1 > 0) {
        var_s4 = arg1 * 0x3E8;
    }
    var_s0 = (s64) (var_s3 << 0x20) >> 0x20;
    netSendGameEvent_173D08(arg0, func_00173500_173D08(arg0), sp);
    netSendGameEvent_173D08(arg0, func_00173500_173D08(arg0), sp);
    netSendGameEvent_173D08(arg0, func_00173500_173D08(arg0), sp);
    var_v0 = 1;
    if (D_003188E0_173D08 == 0) {
        func_00173C50_173D08(arg0);
        M2C_FIELD(arg0, s32* , 0x2E8C) = 0;
loop_4:
        temp_v0 = timerGetCurTics__Fv_173D08();
        if (temp_v0 < var_s0) {
            var_v0_2 = (temp_v0 + 0x10000) - var_s0;
        } else {
            var_v0_2 = temp_v0 - var_s0;
        }
        var_s1 += var_v0_2;
        temp_a0 = var_s1 - var_s3;
        var_s0 = temp_v0;
        if (temp_a0 >= 0) {
            var_f0 = func_001F2CC8_173D08(temp_a0);
        } else {
            var_f0 = 2.0f * func_001F2CC8_173D08((temp_a0 & 1) | ((u64) temp_a0 >> 1));
        }
        if ((var_f0 / 576.0f) > 5000.0f) {
            var_s4 -= 0x1388;
            var_v0 = 0;
            if (var_s4 >= 0) {
                func_00173C50_173D08(arg0);
                var_s3 = timerGetCurTics__Fv_173D08();
                var_s1 = var_s3;
                var_s0 = (s64) (var_s3 << 0x20) >> 0x20;
                goto block_13;
            }
        } else {
block_13:
            func_001703E8_173D08(arg0);
            var_v0 = 1;
            if (M2C_FIELD(arg0, s32* , 0x2E8C) == 0) {
                goto loop_4;
            }
        }
    }
    return var_v0;
}
//@@ func_00173D08 m2c4
#include "m2c_macros.h"
M2C_UNK func_001703E8_173D08() __asm__("func_001703E8");
s32 func_00173500_173D08() __asm__("func_00173500");
M2C_UNK func_00173C50_173D08() __asm__("func_00173C50");
f32 func_001F2CC8_173D08() __asm__("func_001F2CC8");
M2C_UNK netSendGameEvent_173D08() __asm__("netSendGameEvent");
s64 timerGetCurTics__Fv_173D08() __asm__("timerGetCurTics__Fv");
extern s32 D_003188E0_173D08 __asm__("D_003188E0");

s32 func_00173D08(void* arg0, s32 arg1) {
    u8 sp[0x20];
    f32 var_f0;
    s32 temp_a0;
    s32 var_s4;
    s32 var_v0;
    s32 var_v0_2;
    s64 temp_v0;
    s64 var_s0;
    s64 var_s1;
    s64 var_s3;

    var_s4 = 0x1B7740;
    var_s3 = timerGetCurTics__Fv_173D08();
    var_s1 = var_s3;
    if (arg1 > 0) {
        var_s4 = arg1 * 0x3E8;
    }
    var_s0 = (s64) (var_s3 << 0x20) >> 0x20;
    netSendGameEvent_173D08(arg0, func_00173500_173D08(arg0), sp);
    netSendGameEvent_173D08(arg0, func_00173500_173D08(arg0), sp);
    netSendGameEvent_173D08(arg0, func_00173500_173D08(arg0), sp);
    var_v0 = 1;
    if (D_003188E0_173D08 == 0) {
        func_00173C50_173D08(arg0);
        M2C_FIELD(arg0, s32* , 0x2E8C) = 0;
loop_4:
        temp_v0 = timerGetCurTics__Fv_173D08();
        if (temp_v0 < var_s0) {
            var_v0_2 = (temp_v0 + 0x10000) - var_s0;
        } else {
            var_v0_2 = temp_v0 - var_s0;
        }
        var_s1 += var_v0_2;
        temp_a0 = var_s1 - var_s3;
        var_s0 = temp_v0;
        if (temp_a0 >= 0) {
            var_f0 = func_001F2CC8_173D08(temp_a0);
        } else {
            var_f0 = 2.0f * func_001F2CC8_173D08((temp_a0 & 1) | ((u64) temp_a0 >> 1));
        }
        if ((var_f0 / 576.0f) > 5000.0f) {
            var_s4 -= 0x1388;
            var_v0 = 0;
            if (var_s4 >= 0) {
                func_00173C50_173D08(arg0);
                var_s3 = timerGetCurTics__Fv_173D08();
                var_s1 = var_s3;
                var_s0 = (s64) (var_s3 << 0x20) >> 0x20;
                goto block_13;
            }
        } else {
block_13:
            func_001703E8_173D08(arg0);
            var_v0 = 1;
            if (M2C_FIELD(arg0, s32* , 0x2E8C) == 0) {
                goto loop_4;
            }
        }
    }
    return var_v0;
}
//@@ func_00173D08 m2c5
#include "m2c_macros.h"
M2C_UNK func_001703E8_173D08() __asm__("func_001703E8");
s32 func_00173500_173D08() __asm__("func_00173500");
M2C_UNK func_00173C50_173D08() __asm__("func_00173C50");
f32 func_001F2CC8_173D08() __asm__("func_001F2CC8");
M2C_UNK netSendGameEvent_173D08() __asm__("netSendGameEvent");
s64 timerGetCurTics__Fv_173D08() __asm__("timerGetCurTics__Fv");
extern s32 D_003188E0_173D08 __asm__("D_003188E0");

s32 func_00173D08(void* arg0, s32 arg1) {
    u8 sp[0x10];
    f32 var_f0;
    s32 temp_a0;
    s32 var_s4;
    s32 var_v0;
    s32 var_v0_2;
    s64 temp_v0;
    s64 var_s0;
    s64 var_s1;
    s64 var_s3;

    var_s4 = 0x1B7740;
    var_s3 = timerGetCurTics__Fv_173D08();
    var_s1 = var_s3;
    if (arg1 > 0) {
        var_s4 = arg1 * 0x3E8;
    }
    var_s0 = (s64) (var_s3 << 0x20) >> 0x20;
    netSendGameEvent_173D08(arg0, func_00173500_173D08(arg0), sp);
    netSendGameEvent_173D08(arg0, func_00173500_173D08(arg0), sp);
    netSendGameEvent_173D08(arg0, func_00173500_173D08(arg0), sp);
    var_v0 = 1;
    if (D_003188E0_173D08 == 0) {
        func_00173C50_173D08(arg0);
        M2C_FIELD(arg0, s32* , 0x2E8C) = 0;
loop_4:
        temp_v0 = timerGetCurTics__Fv_173D08();
        if (temp_v0 < var_s0) {
            var_v0_2 = (temp_v0 + 0x10000) - var_s0;
        } else {
            var_v0_2 = temp_v0 - var_s0;
        }
        var_s1 += var_v0_2;
        temp_a0 = var_s1 - var_s3;
        var_s0 = temp_v0;
        if (temp_a0 >= 0) {
            var_f0 = func_001F2CC8_173D08(temp_a0);
        } else {
            var_f0 = 2.0f * func_001F2CC8_173D08((temp_a0 & 1) | ((u64) temp_a0 >> 1));
        }
        if ((var_f0 / 576.0f) > 5000.0f) {
            var_s4 -= 0x1388;
            var_v0 = 0;
            if (var_s4 >= 0) {
                func_00173C50_173D08(arg0);
                var_s3 = timerGetCurTics__Fv_173D08();
                var_s1 = var_s3;
                var_s0 = (s64) (var_s3 << 0x20) >> 0x20;
                goto block_13;
            }
        } else {
block_13:
            func_001703E8_173D08(arg0);
            var_v0 = 1;
            if (M2C_FIELD(arg0, s32* , 0x2E8C) == 0) {
                goto loop_4;
            }
        }
    }
    return var_v0;
}
//@@ func_00173ED0 m2c0
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
//@@ func_00173F10 m2c0
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
//@@ func_00173F40 m2c0
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
//@@ func_00173F80 m2c0
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
//@@ func_00173FC0 m2c0
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
//@@ func_00173FF0 m2c0
#include "m2c_macros.h"
s32 func_00173FF0(void* arg0, void* arg1, void* arg2) {
    s32 temp_v1;
    s32* temp_a1;
    s8 temp_a3_2;
    void* temp_a3;
    void* temp_t0;
    void* temp_v0;

    temp_v0 = M2C_FIELD(arg1, void** , 0x20D8);
    if ((temp_v0 != NULL) && (arg2 != NULL)) {
        temp_t0 = M2C_FIELD(arg2, void** , 0x20D8);
        if ((temp_t0 != NULL) && (M2C_FIELD(temp_v0, s32* , 4) != -1)) {
            if (M2C_FIELD(temp_t0, s32* , 4) != -1) {
                temp_a3 = M2C_FIELD(arg0, void** , 0x3148);
                if (((((u32) M2C_FIELD(temp_a3, u32* , 0) >> 1) & 0xF) != 4) || (arg1 == arg2) || (temp_a3_2 = M2C_FIELD(temp_a3, s8* , 0x1A), (M2C_FIELD(((M2C_FIELD(arg1, s32* , 0x20C0) * 0x220) + arg0), s32* , 0x10) == temp_a3_2)) || (M2C_FIELD(arg2, s32* , 0x20C0) == temp_a3_2)) {
                    temp_a1 = M2C_FIELD(arg1, void** , 0x20D8) + 0x10 + (M2C_FIELD(temp_t0, s32* , 4) * 4);
                    temp_v1 = *temp_a1 + 1;
                    *temp_a1 = (temp_v1 < 0x3E8) ? temp_v1 : 0x3E7;
                    return 1;
                }
                /* Duplicate return node #7. Try simplifying control flow for better match */
                return 0;
            }
            /* Duplicate return node #7. Try simplifying control flow for better match */
            return 0;
        }
    }
    return 0;
}
//@@ func_001740B0 m2c0
#include "m2c_macros.h"
s32 func_001740B0(void* arg0, void* arg1, void* arg2) {
    f32 temp_f0;
    f32 var_f2;
    f32* temp_v1_2;
    s32 temp_a1_2;
    s32 temp_v1;
    s8 temp_a0;
    s8 temp_a1;
    s8 temp_v0_3;
    void* temp_t1;
    void* temp_v0;
    void* temp_v0_2;

    temp_v0 = M2C_FIELD(arg1, void** , 0x20D8);
    if ((temp_v0 != NULL) && (arg2 != NULL)) {
        temp_t1 = M2C_FIELD(arg2, void** , 0x20D8);
        if ((temp_t1 != NULL) && (M2C_FIELD(temp_v0, s32* , 4) != -1) && (M2C_FIELD(temp_t1, s32* , 4) != -1) && ((temp_v0_2 = M2C_FIELD(arg0, void** , 0x3148), ((((u32) M2C_FIELD(temp_v0_2, u32* , 0) >> 1) & 0xF) != 4)) || (temp_a1 = M2C_FIELD(temp_v0_2, s8* , 0x1A), (M2C_FIELD(((M2C_FIELD(arg1, s32* , 0x20C0) * 0x220) + arg0), s32* , 0x10) == temp_a1)) || (M2C_FIELD(arg2, s32* , 0x20C0) == temp_a1))) {
            if ((((u32) M2C_FIELD(temp_v0_2, u32* , 0) >> 1) & 0xF) != 8) {
                goto block_24;
            }
            temp_a0 = M2C_FIELD(temp_v0_2, s8* , 0x1A);
            temp_a1_2 = M2C_FIELD(((M2C_FIELD(arg1, s32* , 0x20C0) * 0x220) + arg0), s32* , 0x10);
            if (temp_a1_2 == temp_a0) {
                goto block_24;
            }
            temp_v1 = M2C_FIELD(arg2, s32* , 0x20C0);
            if (temp_v1 == temp_a0) {
                goto block_24;
            }
            temp_v0_3 = M2C_FIELD(temp_v0_2, s8* , 0x1B);
            if (temp_a1_2 == temp_v0_3) {
                goto block_24;
            }
            if (temp_v1 == temp_v0_3) {
block_24:
                if (!((M2C_FIELD(temp_v0_2, u32* , 0) >> 0xC) & 1) || (arg1 == arg2) || (M2C_FIELD(((M2C_FIELD(arg1, s32* , 0x20C0) * 0x220) + arg0), s32* , 0x14) != M2C_FIELD(((M2C_FIELD(arg2, s32* , 0x20C0) * 0x220) + arg0), s32* , 0x14))) {
                    temp_v1_2 = M2C_FIELD(arg1, void** , 0x20D8) + 0x30 + (M2C_FIELD(temp_t1, s32* , 4) * 4);
                    temp_f0 = *temp_v1_2 + arg0;
                    var_f2 = 999990.0f;
                    if (temp_f0 < 999990.0f) {
                        var_f2 = temp_f0;
                    }
                    *temp_v1_2 = var_f2;
                    return 1;
                }
                /* Duplicate return node #23. Try simplifying control flow for better match */
                return 0;
            }
            /* Duplicate return node #23. Try simplifying control flow for better match */
            return 0;
        }
    }
    return 0;
}
//@@ func_001742B0 m2c0
#include "m2c_macros.h"
M2C_UNK func_001703E8_1742B0() __asm__("func_001703E8");
s32 func_00174268_1742B0() __asm__("func_00174268");
M2C_UNK func_001890F0_1742B0() __asm__("func_001890F0");
s32 func_0018A480_1742B0() __asm__("func_0018A480");
M2C_UNK func_001FE0B8_1742B0() __asm__("func_001FE0B8");
M2C_UNK memset_1742B0() __asm__("memset");
M2C_UNK vehicleDisable__7Vehicle_1742B0() __asm__("vehicleDisable__7Vehicle");
extern s32 D_004FA030_1742B0 __asm__("D_004FA030");
extern s32 D_004FA03C_1742B0 __asm__("D_004FA03C");

void func_001742B0(s32 arg0) {
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_s0;
    s32 temp_s6;
    s32 temp_v1;
    s32 var_s3;
    s32 var_v0;
    s32 var_v0_3;
    s32 var_v1;
    s32* var_v0_2;
    void* temp_a0_2;
    void* temp_a0_3;
    void* temp_a0_4;
    void* temp_a0_5;
    void* temp_a0_6;
    void* temp_s0_2;
    void* temp_s1;

    var_s3 = 0;
    var_v0 = 0 * 0x220;
loop_1:
    temp_s6 = var_s3 + 1;
    temp_s1 = var_v0 + arg0;
    temp_a0 = func_00174268_1742B0(arg0, var_s3);
    temp_s0 = temp_a0 - 1;
    if ((M2C_FIELD(temp_s1, s32* , 0x10) != -1) && (temp_a1 = M2C_FIELD(temp_s1, s32* , 0xB4), (temp_a1 != -1)) && (temp_v1 = M2C_FIELD(temp_s1, s32* , 0xB8), (temp_v1 != 0))) {
        if (temp_v1 == 1) {
            temp_s0_2 = M2C_FIELD((D_004FA030_1742B0 + 0x98000 + (temp_s0 * 4)), void** , 0x6670);
            if (temp_s0_2 != NULL) {
                if (M2C_FIELD(temp_s0_2, s32* , 0x20F4) != temp_a1) {
                    memset_1742B0(temp_s0_2 + 0x10, 0, 0x300);
                    memset_1742B0(temp_s0_2 + 0x310, 0, 0x174);
                    memset_1742B0(temp_s0_2 + 0x484, 0, 0x25);
                    memset_1742B0(temp_s0_2 + 0x4B0, 0, 0xE0);
                    memset_1742B0(temp_s0_2 + 0x5C0, 0, 0x14E0);
                    memset_1742B0(temp_s0_2 + 0x1AA0, 0, 0x490);
                    memset_1742B0(temp_s0_2 + 0x21B0, 0, 0xD90);
                    temp_a0_2 = M2C_FIELD(temp_s0_2, void** , 0x2010);
                    if (temp_a0_2 != NULL) {
                        memset_1742B0(temp_a0_2, 0, 0x7E4);
                    }
                    temp_a0_3 = M2C_FIELD(temp_s0_2, void** , 0x2014);
                    if (temp_a0_3 != NULL) {
                        memset_1742B0(temp_a0_3, 0, 0x630);
                    }
                    temp_a0_4 = M2C_FIELD(temp_s0_2, void** , 0x2018);
                    if (temp_a0_4 != NULL) {
                        memset_1742B0(temp_a0_4, 0, 0x2C0);
                    }
                    temp_a0_5 = M2C_FIELD(temp_s0_2, void** , 0x201C);
                    if (temp_a0_5 != NULL) {
                        memset_1742B0(temp_a0_5, 0, 0x30);
                    }
                    temp_a0_6 = M2C_FIELD(temp_s0_2, void** , 0x2020);
                    if (temp_a0_6 != NULL) {
                        memset_1742B0(temp_a0_6, 0, 0x70);
                    }
                    M2C_FIELD(temp_s0_2, s32* , 0x2024) = 0;
                    var_v0_2 = temp_s0_2 + 0x3184;
                    M2C_FIELD(temp_s0_2, s32* , 0x203C) = 0;
                    M2C_FIELD(temp_s0_2, s32* , 0x2040) = 0;
                    var_v1 = 1;
                    M2C_FIELD(temp_s0_2, s32* , 0x2044) = 0;
                    M2C_FIELD(temp_s0_2, s32* , 0x2048) = 0;
                    M2C_FIELD(temp_s0_2, s32* , 0x204C) = 0;
                    M2C_FIELD(temp_s0_2, s32* , 0x2050) = 0;
                    M2C_FIELD(temp_s0_2, s32* , 0x2054) = 0;
                    M2C_FIELD(temp_s0_2, s32* , 0x2058) = 0;
                    M2C_FIELD(temp_s0_2, s32* , 0x205C) = 0;
                    M2C_FIELD(temp_s0_2, s32* , 0x2060) = 0;
                    M2C_FIELD(temp_s0_2, s32* , 0x2064) = 0;
                    M2C_FIELD(temp_s0_2, s32* , 0x2068) = 0;
                    M2C_FIELD(temp_s0_2, s32* , 0x206C) = 0;
                    M2C_FIELD(temp_s0_2, s32* , 0x2070) = 0;
                    M2C_FIELD(temp_s0_2, s32* , 0x2074) = 0;
                    M2C_FIELD(temp_s0_2, s32* , 0x2078) = 0;
                    M2C_FIELD(temp_s0_2, s32* , 0x207C) = 0;
                    M2C_FIELD(temp_s0_2, s32* , 0x2080) = 0;
                    M2C_FIELD(temp_s0_2, s32* , 0x2084) = 0;
                    M2C_FIELD(temp_s0_2, s32* , 0x2088) = 0;
                    M2C_FIELD(temp_s0_2, s32* , 0x20E0) = -1;
                    M2C_FIELD(temp_s0_2, s32* , 0x2F44) = -1;
                    M2C_FIELD(temp_s0_2, s32* , 0x2F48) = -1;
                    M2C_FIELD(temp_s0_2, s32* , 0x2030) = 0;
                    M2C_FIELD(temp_s0_2, s32* , 0x20DC) = 0;
                    M2C_FIELD(temp_s0_2, s32* , 0x20B8) = -1;
                    M2C_FIELD(temp_s0_2, s32* , 0x20BC) = -1;
                    M2C_FIELD(temp_s0_2, s32* , 0x590) = 0;
                    do {
                        *var_v0_2 = -1;
                        var_v1 -= 1;
                        var_v0_2 -= 4;
                    } while (var_v1 >= 0);
                    goto block_19;
                }
                goto block_23;
            }
block_19:
            func_001FE0B8_1742B0(func_00174268_1742B0(arg0, var_s3));
            func_001703E8_1742B0(arg0);
            func_001890F0_1742B0(D_004FA03C_1742B0, var_s3);
            M2C_FIELD(((var_s3 * 0x220) + arg0), s32* , 0xB8) = 2;
            goto block_24;
        }
        var_s3 = temp_s6;
        if (func_0018A480_1742B0(temp_a0, temp_a1) != 0) {
            var_v0_3 = var_s3 < 8;
            if (M2C_FIELD(temp_s1, s32* , 0xB8) == 2) {
                func_001703E8_1742B0(arg0);
                vehicleDisable__7Vehicle_1742B0(M2C_FIELD((D_004FA030_1742B0 + 0x98000 + (temp_s0 * 4)), s32* , 0x6670));
block_23:
                M2C_FIELD(temp_s1, s32* , 0xB8) = 0;
                goto block_24;
            }
        } else {
            goto block_25;
        }
    } else {
block_24:
        var_s3 = temp_s6;
block_25:
        var_v0_3 = var_s3 < 8;
    }
    if (var_v0_3 != 0) {
        var_v0 = var_s3 * 0x220;
        goto loop_1;
    }
}
//@@ func_00174598 m2c0
#include "m2c_macros.h"
s32 mathfRand__Fii_174598() __asm__("mathfRand__Fii");

void func_00174598(void* arg0) {
    s32 temp_s1;
    s32 var_v0;
    void* var_s0;

    var_s0 = arg0;
    temp_s1 = var_s0 + 0x1100;
    var_v0 = M2C_FIELD(var_s0, s32* , 0x10);
loop_1:
    if (var_v0 == -1) {
        M2C_FIELD(var_s0, s32* , 0xB4) = (s32) (mathfRand__Fii_174598(1, 0xE) << 5);
    }
    var_s0 += 0x220;
    if ((s32) var_s0 < temp_s1) {
        var_v0 = M2C_FIELD(var_s0, s32* , 0x10);
        goto loop_1;
    }
}
//@@ func_00174608 m2c0
#include "m2c_macros.h"
void func_00174608(s32 arg0, s32 arg1) {
    s32 var_v0;
    s32* var_a0;

    var_a0 = arg0 + 0xF94;
    var_v0 = 7;
    do {
        *var_a0 = arg1;
        var_v0 -= 1;
        var_a0 -= 0x220;
    } while (var_v0 >= 0);
}
//@@ func_001746E8 m2c0
#include "m2c_macros.h"
M2C_UNK func_0016F1C8_1746E8() __asm__("func_0016F1C8");
extern s32 D_004F9F70_1746E8 __asm__("D_004F9F70");
extern s32 D_004F9F74_1746E8 __asm__("D_004F9F74");
extern void* D_004FA030_1746E8 __asm__("D_004FA030");

void func_001746E8(void* arg0) {
    s32 temp_a1;
    s32 temp_v0;
    s32 var_s2;
    s32 var_s2_2;
    s32* var_s1;
    void* temp_a3;
    void* temp_v1;

    temp_a3 = arg0 + 0x3080;
    M2C_FIELD(arg0, s32* , 0x2F00) = -1;
    var_s2 = 0;
    M2C_FIELD(arg0, s32* , 0x2E04) = 0x32;
    M2C_FIELD(arg0, s32* , 0x3224) = 1;
    M2C_FIELD(arg0, s32* , 0x3080) = (s32) (M2C_FIELD(arg0, s32* , 0x3080) & ~1);
    M2C_FIELD(arg0, s32* , 0x1BC0) = 0;
    M2C_FIELD(arg0, s32* , 0x1BC4) = 0;
    M2C_FIELD(arg0, s32* , 0x2E00) = 0;
    M2C_FIELD(arg0, s32* , 0x2E08) = 0;
    M2C_FIELD(arg0, s32* , 0x2E8C) = 0;
    M2C_FIELD(arg0, s32* , 0x2E98) = -1;
    M2C_FIELD(arg0, s32* , 0x2E9C) = -1;
    M2C_FIELD(arg0, s32* , 0x2EA0) = -1;
    M2C_FIELD(arg0, s32* , 0x2EA8) = -1;
    M2C_FIELD(arg0, s32* , 0x2EAC) = -1;
    M2C_FIELD(arg0, s32* , 0x2EC0) = -1;
    M2C_FIELD(arg0, s32* , 0x2EB4) = -1;
    M2C_FIELD(arg0, s32* , 0x3218) = -1;
    M2C_FIELD(arg0, s32* , 0x2EA4) = 0;
    M2C_FIELD(arg0, s32* , 0x2EB0) = 0;
    M2C_FIELD(arg0, s32* , 0x2EBC) = 0;
    M2C_FIELD(arg0, s32* , 0x2ED0) = 0;
    M2C_FIELD(arg0, s32* , 0x2ED4) = 0;
    M2C_FIELD(arg0, s32* , 0x2ECC) = 0;
    M2C_FIELD(arg0, s32* , 0x2ED8) = 0;
    M2C_FIELD(arg0, s32* , 0x2EF0) = 1;
    M2C_FIELD(arg0, s32* , 0x2EF4) = 1;
    M2C_FIELD(arg0, void** , 0x3148) = temp_a3;
    M2C_FIELD(arg0, s32* , 0x3220) = 0;
    M2C_FIELD(arg0, s32* , 0x3228) = 0;
    M2C_FIELD(arg0, s32* , 0x322C) = 0;
    M2C_FIELD(arg0, s8* , 0x2DF6) = 0;
    M2C_FIELD(arg0, s32* , 0x321C) = 0;
    M2C_FIELD(temp_a3, s8* , 0x24) = 0;
    M2C_FIELD(M2C_FIELD(arg0, void** , 0x3148), s8* , 0xC4) = 0;
    do {
        temp_v0 = var_s2 * 4;
        var_s2 += 1;
        temp_v1 = M2C_FIELD(arg0, void** , 0x3148) + temp_v0;
        M2C_FIELD(temp_v1, s32* , 0x8C) = (s32) (M2C_FIELD(temp_v1, s32* , 0x8C) | 0xF0);
    } while (var_s2 < 0xC);
    M2C_FIELD(arg0, s32* , 0xB798) = 0;
    M2C_FIELD(arg0, s32* , 0xB790) = 0;
    var_s2_2 = 0;
    M2C_FIELD(arg0, s32* , 0xB794) = 0;
    var_s1 = arg0 + 0x303C;
    M2C_FIELD(D_004FA030_1746E8, s32* , 0x9FD9C) = 1;
    do {
        *var_s1 = 0;
        temp_a1 = var_s2_2;
        var_s2_2 += 1;
        func_0016F1C8_1746E8(arg0, temp_a1);
        var_s1 += 4;
    } while (var_s2_2 < 8);
    M2C_FIELD(arg0, s32* , 0x3010) = 0;
    D_004F9F70_1746E8 = 0;
    D_004F9F74_1746E8 = 0;
}
//@@ func_00174860 m2c0
#include "m2c_macros.h"
M2C_UNK func_0016E8E0_174860() __asm__("func_0016E8E0");
M2C_UNK func_00174910_174860() __asm__("func_00174910");

void func_00174860(void* arg0) {
    s32 var_s2;
    void* var_s0;

    var_s2 = 7;
    M2C_FIELD(arg0, s32* , 4) = (s32) (arg0 + 0x1990);
    var_s0 = arg0 + 0x10;
    do {
        var_s2 -= 1;
        func_0016E8E0_174860(var_s0);
        var_s0 += 0x220;
    } while (var_s2 >= 0);
    M2C_FIELD(arg0, s32* , 0x1BB4) = 0;
    M2C_FIELD(arg0, s32* , 0x2CF0) = -1;
    M2C_FIELD(arg0, s32* , 0x307C) = -0x63;
    func_00174910_174860(arg0);
}
//@@ func_001748D8 m2c0
#include "m2c_macros.h"
M2C_UNK InitTypeOfVehicles__7TheGame_1748D8() __asm__("InitTypeOfVehicles__7TheGame");
M2C_UNK func_001746E8_1748D8() __asm__("func_001746E8");
M2C_UNK func_00174860_1748D8() __asm__("func_00174860");
extern s32 D_004FA030_1748D8 __asm__("D_004FA030");

void func_001748D8(s32 arg0) {
    func_001746E8_1748D8();
    func_00174860_1748D8(arg0);
    InitTypeOfVehicles__7TheGame_1748D8(D_004FA030_1748D8);
}
//@@ func_00174BF0 m2c0
#include "m2c_macros.h"
s32 func_001734B8_174BF0() __asm__("func_001734B8");
s32 func_0026BD50_174BF0() __asm__("func_0026BD50");
M2C_UNK memset_174BF0() __asm__("memset");
void* netGetDmeTime_174BF0() __asm__("netGetDmeTime");
extern s32 D_004F9CA8_174BF0 __asm__("D_004F9CA8");
extern s32 D_004F9CAC_174BF0 __asm__("D_004F9CAC");
extern s32 D_004FA03C_174BF0 __asm__("D_004FA03C");

void func_00174BF0(void* arg0) {
    M2C_UNK sp10;
    s32 temp_s1;
    s32 temp_s1_2;

    if (func_001734B8_174BF0() != 0) {
        if (D_004F9CAC_174BF0 == -1) {

        } else {
            temp_s1 = M2C_FIELD(arg0, s32* , 0x3218);
            if (temp_s1 == -1) {
                *(D_004FA03C_174BF0 + 0x1A3C8 + (*M2C_FIELD(arg0, s32** , 4) * 4)) = (s32) M2C_FIELD(arg0, u8* , 0x3085);
                if (func_0026BD50_174BF0(arg0 + 0x3218, 1, 3, 0) == 0) {
                    M2C_FIELD(arg0, void** , 0x3148) = (void* ) M2C_FIELD(netGetDmeTime_174BF0(arg0, M2C_FIELD(arg0, s32* , 0x3218)), void** , 0x1C);
                } else {
                    M2C_FIELD(arg0, s32* , 0x3218) = temp_s1;
                }
            }
        }
        if (D_004F9CA8_174BF0 != -1) {
            temp_s1_2 = M2C_FIELD(arg0, s32* , 0x2F00);
            if (temp_s1_2 == -1) {
                memset_174BF0(&sp10, 0, 0xA0);
                M2C_FIELD(M2C_FIELD(arg0, void** , 0x3148), s8* , 0x24) = 1;
                if (func_0026BD50_174BF0(arg0 + 0x2F00, 1, 3, 0) == 0) {
                    M2C_FIELD(arg0, s32* , 0x2F04) = (s32) M2C_FIELD(netGetDmeTime_174BF0(arg0, M2C_FIELD(arg0, s32* , 0x2F00)), s32* , 0x1C);
                } else {
                    M2C_FIELD(arg0, s32* , 0x2F00) = temp_s1_2;
                    M2C_FIELD(arg0, s32* , 0x2F04) = 0;
                }
            }
        }
    }
}
//@@ func_00174D58 m2c0
#include "m2c_macros.h"
extern M2C_UNK D_00320E80_174D58 __asm__("D_00320E80");

s32 func_00174D58(void* arg0) {
    return *((M2C_FIELD(M2C_FIELD(arg0, void** , 0x3148), s32* , 0x20) * 4) + &D_00320E80_174D58);
}
//@@ func_00175588 m2c0
#include "m2c_macros.h"
s32 func_0013A7B8_175588() __asm__("func_0013A7B8");
s32 func_00174268_175588() __asm__("func_00174268");
M2C_UNK func_001756A0_175588() __asm__("func_001756A0");
extern void* D_004FA030_175588 __asm__("D_004FA030");

s32 func_00175588(s32 arg0, s32 arg1) {
    s32 var_a1;
    s32 var_s0;
    s32* var_s1;

    var_s0 = arg1;
    var_a1 = 2;
    if ((M2C_FIELD(D_004FA030_175588, s32* , 0x9E690) == 0) || (M2C_FIELD(D_004FA030_175588, s32* , 0x9E694) == 0)) {
        if (var_s0 == -1) {
            var_s0 = 0;
            var_s1 = arg0 + 0x214;
loop_6:
            if (var_s0 < 8) {
                if (*var_s1 != 0) {
                    var_s1 += 0x220;
                    goto block_5;
                }
                var_a1 = func_00174268_175588(arg0, var_s0) - 1;
                var_s1 += 0x220;
                if (M2C_FIELD(M2C_FIELD((D_004FA030_175588 + 0x98000 + (var_a1 * 4)), void** , 0x6670), s32* , 0x20D0) == 0) {

                } else {
block_5:
                    var_s0 += 1;
                    goto loop_6;
                }
            }
        }
        func_001756A0_175588(arg0, func_0013A7B8_175588(D_004FA030_175588, var_a1, M2C_FIELD(((var_s0 * 0x220) + arg0), s32* , 0xB4), var_a1));
    }
    return 1;
}
//@@ func_001756A0 m2c0
#include "m2c_macros.h"
M2C_UNK func_00109810_1756A0() __asm__("func_00109810");
s8 func_00177028_1756A0() __asm__("func_00177028");
s32 func_0026BD50_1756A0() __asm__("func_0026BD50");
M2C_UNK memset_1756A0() __asm__("memset");
void* netGetDmeTime_1756A0() __asm__("netGetDmeTime");
extern M2C_UNK D_0041BF00_1756A0 __asm__("D_0041BF00");
extern M2C_UNK D_004E8528_1756A0 __asm__("D_004E8528");
extern s32 D_004F9CA4_1756A0 __asm__("D_004F9CA4");
extern s32 D_004F9CB0_1756A0 __asm__("D_004F9CB0");
extern s32 D_004F9D18_1756A0 __asm__("D_004F9D18");
extern void* D_004FA030_1756A0 __asm__("D_004FA030");

s32 func_001756A0(void* arg0, void* arg1) {
    s32 sp10;
    u16 sp38;
    s8 sp3E;
    s8 sp3F;
    s8 sp43;
    s32 sp50;
    s8 sp60;
    s8 sp61;
    u16 sp62;
    s16 sp64;
    s32 sp70;
    s32 sp74;
    s32 spC4;
    s32 var_a1;
    s32 var_v1;
    s32* temp_v1_3;
    s8 var_s2;
    s8 var_s4;
    void* temp_v1_2;
    void** temp_v1;

    var_s4 = -1;
    var_s2 = 0;
    if (arg1 != NULL) {
        var_v1 = 0;
        M2C_FIELD(arg1, s32* , 0x20B4) = 4;
loop_3:
        if (var_s2 < 8) {
            var_v1 += 0x31B0;
            if (arg1 == (D_004FA030_1756A0 + var_v1)) {
                var_s4 = func_00177028_1756A0(var_s2 + 1);
            } else {
                var_s2 += 1;
                goto loop_3;
            }
        }
        if (M2C_FIELD(arg1, void*** , 0x20D0) == NULL) {
            var_s2 = 0;
            memset_1756A0(&sp10, 0, 0x38);
            sp3E = 2;
            sp38 = M2C_FIELD(arg1, u16* , 0x20F4);
            if (arg1 == M2C_FIELD(D_004FA030_1756A0, s32* , 0x9E690)) {
                sp3F = 0;
            } else {
loop_10:
                var_s2 += 1;
                if (var_s2 < 2) {
                    if (arg1 == *(D_004FA030_1756A0 + 0x9E690 + (var_s2 * 4))) {
                        sp3F = var_s2;
                    } else {
                        goto loop_10;
                    }
                }
            }
            sp43 = var_s4;
            if (func_0026BD50_1756A0(arg1 + 0x20C4, 1, 3, 0) != 0) {
                M2C_FIELD(arg1, s32* , 0x20B8) = -1;
                M2C_FIELD(arg1, s32* , 0x20C4) = -1;
            } else {
                temp_v1 = M2C_FIELD(netGetDmeTime_1756A0(arg0, M2C_FIELD(arg1, s32* , 0x20C4)), void*** , 0x1C);
                M2C_FIELD(arg1, void*** , 0x20D0) = temp_v1;
                *temp_v1 = arg1;
            }
        }
        if (M2C_FIELD(arg1, void** , 0x20D4) == NULL) {
            memset_1756A0(&sp50, 0, 0x18);
            func_00109810_1756A0(arg1, &sp50);
            sp62 = M2C_FIELD(arg1, u16* , 0x20F4);
            sp60 = 2;
            sp61 = var_s2;
            sp64 = (s16) var_s4;
            if (func_0026BD50_1756A0(arg1 + 0x20C8, 1, 3, 0) != 0) {
                M2C_FIELD(arg1, void** , 0x20D4) = NULL;
                M2C_FIELD(arg1, s32* , 0x20C8) = -1;
            } else {
                temp_v1_2 = M2C_FIELD(netGetDmeTime_1756A0(arg0, M2C_FIELD(arg1, s32* , 0x20C8)), void** , 0x1C);
                M2C_FIELD(arg1, void** , 0x20D4) = temp_v1_2;
                M2C_FIELD(temp_v1_2, void** , 0xC) = arg1;
            }
        }
        if (M2C_FIELD(arg1, s32* , 0x20D8) == 0) {
            memset_1756A0(&sp70, 0, 0x58);
            var_a1 = 0;
            sp70 = (s32) M2C_FIELD(arg1, u16* , 0x20F4) | ((var_s2 + 1) << 0x10);
            if (M2C_FIELD(arg0, s32* , 0x303C) == 0) {
                M2C_FIELD(arg0, s32* , 0x303C) = 1;
            } else {
loop_24:
                var_a1 += 1;
                if (var_a1 < 8) {
                    temp_v1_3 = arg0 + 0x303C + (var_a1 * 4);
                    if (*temp_v1_3 == 0) {
                        *temp_v1_3 = 1;
                    } else {
                        goto loop_24;
                    }
                }
            }
            sp74 = var_a1;
            spC4 = (s32) var_s4;
            if (func_0026BD50_1756A0(arg1 + 0x20CC, 1, 3, 0) != 0) {
                M2C_FIELD(arg1, s32* , 0x20D8) = 0;
                M2C_FIELD(arg1, s32* , 0x20CC) = -1;
            } else {
                M2C_FIELD(arg1, s32* , 0x20D8) = (s32) M2C_FIELD(netGetDmeTime_1756A0(arg0, M2C_FIELD(arg1, s32* , 0x20CC)), s32* , 0x1C);
            }
        }
    }
    return 1;
}
//@@ func_001759D8 m2c0
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
//@@ func_001761E8 m2c0
#include "m2c_macros.h"
M2C_UNK func_00174D78_1761E8() __asm__("func_00174D78");
M2C_UNK func_001A94C0_1761E8() __asm__("func_001A94C0");
s32 timerGetFieldsLastFrame__Fv_1761E8() __asm__("timerGetFieldsLastFrame__Fv");
extern M2C_UNK D_003156C0_1761E8 __asm__("D_003156C0");
extern void* D_004FA030_1761E8 __asm__("D_004FA030");

void func_001761E8(void* arg0) {
    M2C_UNK var_a1;
    s32 temp_v0_2;
    s32 temp_v1_2;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_s5;
    s32 var_v0;
    u32 temp_lo;
    u32 temp_s4;
    u32 temp_v1;
    void* temp_a0;
    void* temp_a1;
    void* temp_a1_2;
    void* temp_v0;
    void* var_a3;

    /* Flowgraph is not reducible, falling back to gotos-only mode. */
    var_s5 = 0;
    if (M2C_FIELD(M2C_FIELD(&D_003156C0_1761E8, void** , 0x3148), u32* , 8) == 0) {
        goto block_13;
    }
    temp_s4 = (u32) M2C_FIELD(M2C_FIELD(&D_003156C0_1761E8, void** , 0x3148), u32* , 0x2C) / 60U;
    M2C_FIELD(M2C_FIELD(&D_003156C0_1761E8, void** , 0x3148), u32* , 0x2C) = (u32) (M2C_FIELD(M2C_FIELD(&D_003156C0_1761E8, void** , 0x3148), u32* , 0x2C) - timerGetFieldsLastFrame__Fv_1761E8());
    temp_lo = (u32) M2C_FIELD(M2C_FIELD(&D_003156C0_1761E8, void** , 0x3148), u32* , 0x2C) / 60U;
    if (M2C_FIELD(D_004FA030_1761E8, s32* , 0x9FD9C) != 0) {
        goto block_4;
    }
    if (temp_lo == temp_s4) {
        goto block_4;
    }
    func_001A94C0_1761E8(temp_lo, 0x98000, 0x3C);
block_4:
    temp_v1 = M2C_FIELD(M2C_FIELD(&D_003156C0_1761E8, void** , 0x3148), u32* , 0x2C);
    if (temp_v1 == 0) {
        goto block_6;
    }
    if ((u32) M2C_FIELD(M2C_FIELD(&D_003156C0_1761E8, void** , 0x3148), u32* , 8) >= temp_v1) {
        goto block_14;
    }
block_6:
    temp_a1 = M2C_FIELD(arg0, void** , 0x3148);
    temp_a0 = M2C_FIELD(arg0, void** , 4);
    if (M2C_FIELD(temp_a1, s8* , 0x1A) != M2C_FIELD(temp_a0, s32* , 0)) {
        goto block_11;
    }
    if ((((u32) M2C_FIELD(temp_a1, u32* , 0) >> 1) & 0xF) == 1) {
        goto block_11;
    }
    if (M2C_FIELD(temp_a0, void** , 0x210) == NULL) {
        goto block_11;
    }
    if (M2C_FIELD(M2C_FIELD(temp_a0, void** , 0xA0), s8* , 0x485) != 0) {
        goto block_12;
    }
    temp_a1_2 = M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0x210);
    M2C_FIELD(temp_a1_2, s32* , 8) = (s32) (M2C_FIELD(temp_a1_2, s32* , 8) + timerGetFieldsLastFrame__Fv_1761E8(&D_003156C0_1761E8, temp_a1));
block_11:
block_12:
    func_00174D78_1761E8(&D_003156C0_1761E8, 1, 0);
block_13:
block_14:
    if (M2C_FIELD(&D_003156C0_1761E8, s32* , 0x3220) == 0) {
        goto block_25;
    }
    if (M2C_FIELD(&D_003156C0_1761E8, s32* , 0x322C) != 0xB4) {
        goto block_25;
    }
    var_a2 = 0;
    if (M2C_FIELD(D_004FA030_1761E8, s32* , 0x20D8) == 0) {
        goto loop_19;
    }
    var_v0 = M2C_FIELD(D_004FA030_1761E8, s32* , 0x20B4);
    goto block_22;
loop_19:
    var_a2 += 1;
    if (var_a2 >= 8) {
        goto block_23;
    }
    temp_v0 = (var_a2 * 0x31B0) + D_004FA030_1761E8;
    if (M2C_FIELD(temp_v0, s32* , 0x20D8) == 0) {
        goto loop_19;
    }
    var_v0 = M2C_FIELD(temp_v0, s32* , 0x20B4);
block_22:
    if ((u32) (var_v0 - 1) >= 2U) {
        goto loop_19;
    }
block_23:
    if (var_a2 != 8) {
        goto block_25;
    }
    func_00174D78_1761E8(&D_003156C0_1761E8, 0, 0);
block_25:
    temp_v1_2 = M2C_FIELD(arg0, s32* , 0x322C);
    if (temp_v1_2 >= 0xB4) {
        goto block_27;
    }
    M2C_FIELD(arg0, s32* , 0x322C) = (s32) (temp_v1_2 + 1);
block_27:
    if (M2C_FIELD(&D_003156C0_1761E8, s32* , 0x3220) == 0) {
        goto block_29;
    }
    if (M2C_FIELD(arg0, s32* , 0x322C) != 0xB4) {
        goto block_53;
    }
block_29:
    var_a2_2 = 0;
    var_a3 = D_004FA030_1761E8 + 0x2104;
loop_30:
    if (M2C_FIELD(var_a3, s32* , -0x2C) == 0) {
        goto block_47;
    }
    if (M2C_FIELD(&D_003156C0_1761E8, u16* , 0x3098) == 0) {
        goto block_34;
    }
    if (M2C_FIELD((&D_003156C0_1761E8 + (var_a2_2 * 4)), s32* , 0x2F28) < (s32) M2C_FIELD(&D_003156C0_1761E8, u16* , 0x3098)) {
        goto block_35;
    }
    func_00174D78_1761E8(&D_003156C0_1761E8, 2, 0, var_a3);
    goto block_52;
block_34:
block_35:
    if (M2C_FIELD(&D_003156C0_1761E8, s32* , 0x308C) == 0) {
        goto block_38;
    }
    if (M2C_FIELD((&D_003156C0_1761E8 + (var_a2_2 * 4)), s32* , 0x2F88) < M2C_FIELD(&D_003156C0_1761E8, s32* , 0x308C)) {
        goto block_38;
    }
    var_a1 = 4;
    goto block_42;
block_38:
    if (M2C_FIELD(&D_003156C0_1761E8, s32* , 0x3090) == 0) {
        goto block_43;
    }
    temp_v0_2 = M2C_FIELD((&D_003156C0_1761E8 + (var_a2_2 * 4)), s32* , 0x2FC8);
    if (temp_v0_2 == 0xF4240) {
        goto block_43;
    }
    if (temp_v0_2 < M2C_FIELD(&D_003156C0_1761E8, s32* , 0x3090)) {
        goto block_44;
    }
    var_a1 = 7;
block_42:
    func_00174D78_1761E8(&D_003156C0_1761E8, var_a1, 0, var_a3);
    goto block_52;
block_43:
block_44:
    if (M2C_FIELD(M2C_FIELD(&D_003156C0_1761E8, void** , 0x3148), u8* , 5) == 0) {
        goto block_46;
    }
    if (M2C_FIELD((&D_003156C0_1761E8 + (M2C_FIELD(var_a3, s32* , 0) * 4)), s32* , 0x2F48) >= (s32) M2C_FIELD(M2C_FIELD(&D_003156C0_1761E8, void** , 0x3148), u8* , 5)) {
        goto block_47;
    }
block_46:
    var_s5 += 1;
block_47:
    var_a2_2 += 1;
    var_a3 += 0x31B0;
    if (var_a2_2 < 8) {
        goto loop_30;
    }
    if (!(M2C_FIELD(M2C_FIELD(&D_003156C0_1761E8, void** , 0x3148), s32* , 0) & 1)) {
        goto block_52;
    }
    if ((((s64) (M2C_FIELD(&D_003156C0_1761E8, s64* , 0x3080) << 0x1F) >> 0x20) & 0xF) != 3) {
        goto block_53;
    }
    if (var_s5 >= 2) {
        goto block_53;
    }
    func_00174D78_1761E8(&D_003156C0_1761E8, 3, 0, var_a3);
block_52:
block_53:
    return;
}
//@@ func_00176B10 m2c0
#include "m2c_macros.h"
s32 func_001733F8_176B10() __asm__("func_001733F8");
M2C_UNK func_00264AE0_176B10() __asm__("func_00264AE0");
extern M2C_UNK D_003156C0_176B10 __asm__("D_003156C0");

s32 func_00176B10(void* arg0, s32 arg1) {
    u8 sp[0x10];
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s2;
    s32* var_a0;
    s32* var_s1;
    s32* var_v1;

    var_s2 = 0;
    if (func_001733F8_176B10(&D_003156C0_176B10) != 1) {
        var_s0 = 0;
        var_s1 = arg0 + 0xC8;
        do {
            func_00264AE0_176B10(sp, M2C_FIELD(arg0, s32* , 0x2CF0), var_s0);
            if ((subroutine_arg0 == 2) && ((*var_s1 == 0) || (arg1 != 0))) {
                var_s2 += 1;
            }
            var_s0 += 1;
            var_s1 += 0x220;
        } while (var_s0 < 8);
    } else {
        var_v1 = &D_003156C0_176B10 + 0x214;
        var_a0 = arg0 + 0xC8;
        var_s0_2 = 7;
        do {
            if ((*var_v1 >= 9) && ((*var_a0 == 0) || (arg1 != 0))) {
                var_s2 += 1;
            }
            var_a0 += 0x220;
            var_s0_2 -= 1;
            var_v1 += 0x220;
        } while (var_s0_2 >= 0);
    }
    return var_s2;
}
//@@ func_00176B10 m2c1
#include "m2c_macros.h"
s32 func_001733F8_176B10() __asm__("func_001733F8");
M2C_UNK func_00264AE0_176B10() __asm__("func_00264AE0");
extern M2C_UNK D_003156C0_176B10 __asm__("D_003156C0");

s32 func_00176B10(void* arg0, s32 arg1) {
    u8 sp[0x8];
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s2;
    s32* var_a0;
    s32* var_s1;
    s32* var_v1;

    var_s2 = 0;
    if (func_001733F8_176B10(&D_003156C0_176B10) != 1) {
        var_s0 = 0;
        var_s1 = arg0 + 0xC8;
        do {
            func_00264AE0_176B10(sp, M2C_FIELD(arg0, s32* , 0x2CF0), var_s0);
            if ((subroutine_arg0 == 2) && ((*var_s1 == 0) || (arg1 != 0))) {
                var_s2 += 1;
            }
            var_s0 += 1;
            var_s1 += 0x220;
        } while (var_s0 < 8);
    } else {
        var_v1 = &D_003156C0_176B10 + 0x214;
        var_a0 = arg0 + 0xC8;
        var_s0_2 = 7;
        do {
            if ((*var_v1 >= 9) && ((*var_a0 == 0) || (arg1 != 0))) {
                var_s2 += 1;
            }
            var_a0 += 0x220;
            var_s0_2 -= 1;
            var_v1 += 0x220;
        } while (var_s0_2 >= 0);
    }
    return var_s2;
}
//@@ func_00176B10 m2c2
#include "m2c_macros.h"
s32 func_001733F8_176B10() __asm__("func_001733F8");
M2C_UNK func_00264AE0_176B10() __asm__("func_00264AE0");
extern M2C_UNK D_003156C0_176B10 __asm__("D_003156C0");

s32 func_00176B10(void* arg0, s32 arg1) {
    u8 sp[0x4];
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s2;
    s32* var_a0;
    s32* var_s1;
    s32* var_v1;

    var_s2 = 0;
    if (func_001733F8_176B10(&D_003156C0_176B10) != 1) {
        var_s0 = 0;
        var_s1 = arg0 + 0xC8;
        do {
            func_00264AE0_176B10(sp, M2C_FIELD(arg0, s32* , 0x2CF0), var_s0);
            if ((subroutine_arg0 == 2) && ((*var_s1 == 0) || (arg1 != 0))) {
                var_s2 += 1;
            }
            var_s0 += 1;
            var_s1 += 0x220;
        } while (var_s0 < 8);
    } else {
        var_v1 = &D_003156C0_176B10 + 0x214;
        var_a0 = arg0 + 0xC8;
        var_s0_2 = 7;
        do {
            if ((*var_v1 >= 9) && ((*var_a0 == 0) || (arg1 != 0))) {
                var_s2 += 1;
            }
            var_a0 += 0x220;
            var_s0_2 -= 1;
            var_v1 += 0x220;
        } while (var_s0_2 >= 0);
    }
    return var_s2;
}
//@@ func_00176C20 m2c0
#include "m2c_macros.h"
M2C_UNK func_00264AE0_176C20() __asm__("func_00264AE0");
M2C_UNK printf_176C20() __asm__("printf");

s8 func_00176C20(void* arg0) {
    u8 sp[0x10];
    s32 var_s0;
    s8 var_s1;

    var_s1 = 0;
    var_s0 = 0;
loop_1:
    func_00264AE0_176C20(sp, M2C_FIELD(arg0, s32* , 0x2CF0), var_s0);
    if (subroutine_arg0 == 2) {
        var_s1 |= 1 << var_s0;
    }
    var_s0 += 1;
    if (var_s0 < 8) {
        goto loop_1;
    }
    printf_176C20("GetPlayersJoinedList = 0x%x\n", var_s1);
    return var_s1;
}
//@@ func_00176C20 m2c1
#include "m2c_macros.h"
M2C_UNK func_00264AE0_176C20() __asm__("func_00264AE0");
M2C_UNK printf_176C20() __asm__("printf");

s8 func_00176C20(void* arg0) {
    u8 sp[0x8];
    s32 var_s0;
    s8 var_s1;

    var_s1 = 0;
    var_s0 = 0;
loop_1:
    func_00264AE0_176C20(sp, M2C_FIELD(arg0, s32* , 0x2CF0), var_s0);
    if (subroutine_arg0 == 2) {
        var_s1 |= 1 << var_s0;
    }
    var_s0 += 1;
    if (var_s0 < 8) {
        goto loop_1;
    }
    printf_176C20("GetPlayersJoinedList = 0x%x\n", var_s1);
    return var_s1;
}
//@@ func_00176C20 m2c2
#include "m2c_macros.h"
M2C_UNK func_00264AE0_176C20() __asm__("func_00264AE0");
M2C_UNK printf_176C20() __asm__("printf");

s8 func_00176C20(void* arg0) {
    u8 sp[0x4];
    s32 var_s0;
    s8 var_s1;

    var_s1 = 0;
    var_s0 = 0;
loop_1:
    func_00264AE0_176C20(sp, M2C_FIELD(arg0, s32* , 0x2CF0), var_s0);
    if (subroutine_arg0 == 2) {
        var_s1 |= 1 << var_s0;
    }
    var_s0 += 1;
    if (var_s0 < 8) {
        goto loop_1;
    }
    printf_176C20("GetPlayersJoinedList = 0x%x\n", var_s1);
    return var_s1;
}
//@@ func_00176CC8 m2c0
#include "m2c_macros.h"
M2C_UNK func_00174988_176CC8() __asm__("func_00174988");
s32 func_00176B10_176CC8() __asm__("func_00176B10");
s32 func_002663F0_176CC8() __asm__("func_002663F0");
M2C_UNK memset_176CC8() __asm__("memset");
s32 netGetMyClientIndex_176CC8() __asm__("netGetMyClientIndex");
M2C_UNK printf_176CC8() __asm__("printf");
extern M2C_UNK D_003156C0_176CC8 __asm__("D_003156C0");
extern M2C_UNK D_004E7E70_176CC8 __asm__("D_004E7E70");

s32 func_00176CC8(void* arg0) {
    u8 sp[0x10];
    s32 temp_s2;
    s32 temp_v0;
    void* temp_a0;
    void* temp_a0_2;
    void* temp_a1;
    void* temp_v1;

    temp_s2 = netGetMyClientIndex_176CC8(&D_003156C0_176CC8);
    if (func_002663F0_176CC8(M2C_FIELD(arg0, s32* , 0x2CF0), sp) == 0) {
        M2C_FIELD(arg0, s32* , 0x307C) = (s32) subroutine_arg0;
        if (subroutine_arg0 == temp_s2) {
            if (func_00176B10_176CC8(&D_003156C0_176CC8, 1) <= 0) {
                M2C_FIELD(&D_003156C0_176CC8, s32* , 0x1BB0) = (s32) M2C_FIELD(&D_003156C0_176CC8, s32* , 0x1BB4);
                if (M2C_FIELD(&D_003156C0_176CC8, s32* , 0x1BB4) >= 9) {
                    M2C_FIELD(&D_003156C0_176CC8, s32* , 0x1BB0) = 8;
                }
            }
            if (M2C_FIELD(&D_003156C0_176CC8, s32* , 0x1BB4) < 0xA) {
                *M2C_FIELD(&D_003156C0_176CC8, u32** , 0x3148) &= ~1;
            }
            M2C_FIELD(arg0, s32* , 0x307C) = temp_s2;
            printf_176CC8(&D_004E7E70_176CC8);
            printf_176CC8(">>>>> 3 Setting ConnectionSessionMaster = %d\n\0BASCUS-97196\0\0\0 !\"#$%&'()*+,-.0123456789:;<=>?ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_abcdefghijklmnopqrstuvwxyz{}\0\00123456789\0\0 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\0 .0123456789\0\\PTS\\PEDANIM.CFG;1", M2C_FIELD(arg0, s32* , 0x307C));
            printf_176CC8(&D_004E7E70_176CC8);
            temp_v0 = ((u32) *M2C_FIELD(&D_003156C0_176CC8, u32** , 0x3148) >> 1) & 0xF;
            if (temp_v0 == 1) {
                M2C_FIELD(&D_003156C0_176CC8, s32* , 0x1BB0) = temp_v0;
                memset_176CC8(M2C_FIELD(arg0, void** , 0x3148), 0, 0xC8);
                temp_a0 = M2C_FIELD(arg0, void** , 0x3148);
                M2C_FIELD(temp_a0, s32* , 0) = (s32) ((M2C_FIELD(temp_a0, s32* , 0) & ~0x1E) | 4);
                temp_v1 = M2C_FIELD(arg0, void** , 0x3148);
                M2C_FIELD(temp_v1, s32* , 0) = (s32) (M2C_FIELD(temp_v1, s32* , 0) & ~0x20);
                temp_a0_2 = M2C_FIELD(arg0, void** , 0x3148);
                M2C_FIELD(temp_a0_2, s32* , 0) = (s32) ((M2C_FIELD(temp_a0_2, s32* , 0) & ~0x3C0) | 0x40);
                temp_a1 = M2C_FIELD(arg0, void** , 0x3148);
                M2C_FIELD(temp_a1, s32* , 0) = (s32) ((M2C_FIELD(temp_a1, s32* , 0) & ~0xC00) | 0x800);
                M2C_FIELD(M2C_FIELD(arg0, void** , 0x3148), s8* , 4) = 8;
                M2C_FIELD(M2C_FIELD(arg0, void** , 0x3148), s8* , 0x1A) = -1;
                M2C_FIELD(M2C_FIELD(arg0, void** , 0x3148), s8* , 0x1B) = -1;
                M2C_FIELD(arg0, s64* , 0x3080) = (s64) ((M2C_FIELD(arg0, s64* , 0x3080) & 0xFFC0FFFF) | 0x230000);
            }
            func_00174988_176CC8(&D_003156C0_176CC8, -1);
            return 1;
        }
        return 0;
    }
    M2C_FIELD(arg0, s32* , 0x307C) = -1;
    return 0;
}
//@@ func_00176CC8 m2c1
#include "m2c_macros.h"
M2C_UNK func_00174988_176CC8() __asm__("func_00174988");
s32 func_00176B10_176CC8() __asm__("func_00176B10");
s32 func_002663F0_176CC8() __asm__("func_002663F0");
M2C_UNK memset_176CC8() __asm__("memset");
s32 netGetMyClientIndex_176CC8() __asm__("netGetMyClientIndex");
M2C_UNK printf_176CC8() __asm__("printf");
extern M2C_UNK D_003156C0_176CC8 __asm__("D_003156C0");
extern M2C_UNK D_004E7E70_176CC8 __asm__("D_004E7E70");

s32 func_00176CC8(void* arg0) {
    u8 sp[0x8];
    s32 temp_s2;
    s32 temp_v0;
    void* temp_a0;
    void* temp_a0_2;
    void* temp_a1;
    void* temp_v1;

    temp_s2 = netGetMyClientIndex_176CC8(&D_003156C0_176CC8);
    if (func_002663F0_176CC8(M2C_FIELD(arg0, s32* , 0x2CF0), sp) == 0) {
        M2C_FIELD(arg0, s32* , 0x307C) = (s32) subroutine_arg0;
        if (subroutine_arg0 == temp_s2) {
            if (func_00176B10_176CC8(&D_003156C0_176CC8, 1) <= 0) {
                M2C_FIELD(&D_003156C0_176CC8, s32* , 0x1BB0) = (s32) M2C_FIELD(&D_003156C0_176CC8, s32* , 0x1BB4);
                if (M2C_FIELD(&D_003156C0_176CC8, s32* , 0x1BB4) >= 9) {
                    M2C_FIELD(&D_003156C0_176CC8, s32* , 0x1BB0) = 8;
                }
            }
            if (M2C_FIELD(&D_003156C0_176CC8, s32* , 0x1BB4) < 0xA) {
                *M2C_FIELD(&D_003156C0_176CC8, u32** , 0x3148) &= ~1;
            }
            M2C_FIELD(arg0, s32* , 0x307C) = temp_s2;
            printf_176CC8(&D_004E7E70_176CC8);
            printf_176CC8(">>>>> 3 Setting ConnectionSessionMaster = %d\n\0BASCUS-97196\0\0\0 !\"#$%&'()*+,-.0123456789:;<=>?ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_abcdefghijklmnopqrstuvwxyz{}\0\00123456789\0\0 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\0 .0123456789\0\\PTS\\PEDANIM.CFG;1", M2C_FIELD(arg0, s32* , 0x307C));
            printf_176CC8(&D_004E7E70_176CC8);
            temp_v0 = ((u32) *M2C_FIELD(&D_003156C0_176CC8, u32** , 0x3148) >> 1) & 0xF;
            if (temp_v0 == 1) {
                M2C_FIELD(&D_003156C0_176CC8, s32* , 0x1BB0) = temp_v0;
                memset_176CC8(M2C_FIELD(arg0, void** , 0x3148), 0, 0xC8);
                temp_a0 = M2C_FIELD(arg0, void** , 0x3148);
                M2C_FIELD(temp_a0, s32* , 0) = (s32) ((M2C_FIELD(temp_a0, s32* , 0) & ~0x1E) | 4);
                temp_v1 = M2C_FIELD(arg0, void** , 0x3148);
                M2C_FIELD(temp_v1, s32* , 0) = (s32) (M2C_FIELD(temp_v1, s32* , 0) & ~0x20);
                temp_a0_2 = M2C_FIELD(arg0, void** , 0x3148);
                M2C_FIELD(temp_a0_2, s32* , 0) = (s32) ((M2C_FIELD(temp_a0_2, s32* , 0) & ~0x3C0) | 0x40);
                temp_a1 = M2C_FIELD(arg0, void** , 0x3148);
                M2C_FIELD(temp_a1, s32* , 0) = (s32) ((M2C_FIELD(temp_a1, s32* , 0) & ~0xC00) | 0x800);
                M2C_FIELD(M2C_FIELD(arg0, void** , 0x3148), s8* , 4) = 8;
                M2C_FIELD(M2C_FIELD(arg0, void** , 0x3148), s8* , 0x1A) = -1;
                M2C_FIELD(M2C_FIELD(arg0, void** , 0x3148), s8* , 0x1B) = -1;
                M2C_FIELD(arg0, s64* , 0x3080) = (s64) ((M2C_FIELD(arg0, s64* , 0x3080) & 0xFFC0FFFF) | 0x230000);
            }
            func_00174988_176CC8(&D_003156C0_176CC8, -1);
            return 1;
        }
        return 0;
    }
    M2C_FIELD(arg0, s32* , 0x307C) = -1;
    return 0;
}
//@@ func_00176CC8 m2c2
#include "m2c_macros.h"
M2C_UNK func_00174988_176CC8() __asm__("func_00174988");
s32 func_00176B10_176CC8() __asm__("func_00176B10");
s32 func_002663F0_176CC8() __asm__("func_002663F0");
M2C_UNK memset_176CC8() __asm__("memset");
s32 netGetMyClientIndex_176CC8() __asm__("netGetMyClientIndex");
M2C_UNK printf_176CC8() __asm__("printf");
extern M2C_UNK D_003156C0_176CC8 __asm__("D_003156C0");
extern M2C_UNK D_004E7E70_176CC8 __asm__("D_004E7E70");

s32 func_00176CC8(void* arg0) {
    u8 sp[0x4];
    s32 temp_s2;
    s32 temp_v0;
    void* temp_a0;
    void* temp_a0_2;
    void* temp_a1;
    void* temp_v1;

    temp_s2 = netGetMyClientIndex_176CC8(&D_003156C0_176CC8);
    if (func_002663F0_176CC8(M2C_FIELD(arg0, s32* , 0x2CF0), sp) == 0) {
        M2C_FIELD(arg0, s32* , 0x307C) = (s32) subroutine_arg0;
        if (subroutine_arg0 == temp_s2) {
            if (func_00176B10_176CC8(&D_003156C0_176CC8, 1) <= 0) {
                M2C_FIELD(&D_003156C0_176CC8, s32* , 0x1BB0) = (s32) M2C_FIELD(&D_003156C0_176CC8, s32* , 0x1BB4);
                if (M2C_FIELD(&D_003156C0_176CC8, s32* , 0x1BB4) >= 9) {
                    M2C_FIELD(&D_003156C0_176CC8, s32* , 0x1BB0) = 8;
                }
            }
            if (M2C_FIELD(&D_003156C0_176CC8, s32* , 0x1BB4) < 0xA) {
                *M2C_FIELD(&D_003156C0_176CC8, u32** , 0x3148) &= ~1;
            }
            M2C_FIELD(arg0, s32* , 0x307C) = temp_s2;
            printf_176CC8(&D_004E7E70_176CC8);
            printf_176CC8(">>>>> 3 Setting ConnectionSessionMaster = %d\n\0BASCUS-97196\0\0\0 !\"#$%&'()*+,-.0123456789:;<=>?ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_abcdefghijklmnopqrstuvwxyz{}\0\00123456789\0\0 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\0 .0123456789\0\\PTS\\PEDANIM.CFG;1", M2C_FIELD(arg0, s32* , 0x307C));
            printf_176CC8(&D_004E7E70_176CC8);
            temp_v0 = ((u32) *M2C_FIELD(&D_003156C0_176CC8, u32** , 0x3148) >> 1) & 0xF;
            if (temp_v0 == 1) {
                M2C_FIELD(&D_003156C0_176CC8, s32* , 0x1BB0) = temp_v0;
                memset_176CC8(M2C_FIELD(arg0, void** , 0x3148), 0, 0xC8);
                temp_a0 = M2C_FIELD(arg0, void** , 0x3148);
                M2C_FIELD(temp_a0, s32* , 0) = (s32) ((M2C_FIELD(temp_a0, s32* , 0) & ~0x1E) | 4);
                temp_v1 = M2C_FIELD(arg0, void** , 0x3148);
                M2C_FIELD(temp_v1, s32* , 0) = (s32) (M2C_FIELD(temp_v1, s32* , 0) & ~0x20);
                temp_a0_2 = M2C_FIELD(arg0, void** , 0x3148);
                M2C_FIELD(temp_a0_2, s32* , 0) = (s32) ((M2C_FIELD(temp_a0_2, s32* , 0) & ~0x3C0) | 0x40);
                temp_a1 = M2C_FIELD(arg0, void** , 0x3148);
                M2C_FIELD(temp_a1, s32* , 0) = (s32) ((M2C_FIELD(temp_a1, s32* , 0) & ~0xC00) | 0x800);
                M2C_FIELD(M2C_FIELD(arg0, void** , 0x3148), s8* , 4) = 8;
                M2C_FIELD(M2C_FIELD(arg0, void** , 0x3148), s8* , 0x1A) = -1;
                M2C_FIELD(M2C_FIELD(arg0, void** , 0x3148), s8* , 0x1B) = -1;
                M2C_FIELD(arg0, s64* , 0x3080) = (s64) ((M2C_FIELD(arg0, s64* , 0x3080) & 0xFFC0FFFF) | 0x230000);
            }
            func_00174988_176CC8(&D_003156C0_176CC8, -1);
            return 1;
        }
        return 0;
    }
    M2C_FIELD(arg0, s32* , 0x307C) = -1;
    return 0;
}
//@@ func_00176EA0 m2c0
#include "m2c_macros.h"
M2C_UNK func_0013EED0_176EA0() __asm__("func_0013EED0");
s32 func_001734B8_176EA0() __asm__("func_001734B8");
M2C_UNK func_00175588_176EA0() __asm__("func_00175588");
extern u32* D_00318808_176EA0 __asm__("D_00318808");
extern void* D_004FA030_176EA0 __asm__("D_004FA030");

void func_00176EA0(void* arg0) {
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_v0;
    s32 var_a0;
    s32 var_s0;
    s32 var_v0;
    s32* var_v1;
    u32 temp_v1;
    void* temp_a0;
    void* temp_v0_2;
    void* var_v0_2;

    temp_v1 = *D_00318808_176EA0;
    var_s0 = 0;
    if ((temp_v1 >> 0xD) & 1) {
        if (((temp_v1 >> 1) & 0xF) != 1) {
            if (func_001734B8_176EA0() != 0) {
                if (M2C_FIELD(arg0, s32* , 0x1BB4) == 0xB) {
                    var_v1 = arg0 + 0x214;
                    var_a0 = 7;
                    do {
                        temp_v0 = *var_v1;
                        var_a0 -= 1;
                        var_v1 += 0x220;
                        var_s0 += (temp_v0 < 7) ^ 1;
                    } while (var_a0 >= 0);
                    if (var_s0 == 1) {
                        temp_v0_2 = D_004FA030_176EA0;
                        if (M2C_FIELD(D_004FA030_176EA0, s32* , 0x9E690) == 0) {
                            func_00175588_176EA0(arg0, -1);
                        }
                        if (M2C_FIELD(temp_v0_2, s32* , 0x9E694) == 0) {
                            goto block_16;
                        }
                    } else {
                        var_v0 = var_s0 < 3;
                        if (var_s0 == 2) {
                            if (M2C_FIELD(D_004FA030_176EA0, s32* , 0x9E690) != 0) {
                                var_v0 = var_s0 < 3;
                                goto block_17;
                            }
                            var_v0 = var_s0 < 3;
                            if (M2C_FIELD(D_004FA030_176EA0, s32* , 0x9E694) == 0) {
block_16:
                                func_00175588_176EA0(arg0, -1);
                            } else {
                                goto block_17;
                            }
                        } else {
block_17:
                            if (var_v0 == 0) {
                                temp_a0 = D_004FA030_176EA0;
                                var_v0_2 = temp_a0 + 0x98000;
                                temp_a1 = M2C_FIELD(temp_a0, s32* , 0x9E690);
                                if (temp_a1 != 0) {
                                    func_0013EED0_176EA0(temp_a0, temp_a1);
                                    var_v0_2 = D_004FA030_176EA0 + 0x98000;
                                }
                                temp_a1_2 = M2C_FIELD(var_v0_2, s32* , 0x6694);
                                if (temp_a1_2 != 0) {
                                    func_0013EED0_176EA0(temp_a0, temp_a1_2);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
//@@ func_00177078 m2c0
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
//@@ func_001770A8 m2c0
#include "m2c_macros.h"
M2C_UNK func_00177078_1770A8() __asm__("func_00177078");

void func_001770A8(void) {
    func_00177078_1770A8(1, 0xFFFF);
}
