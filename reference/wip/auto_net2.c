//@@ func_001625F0 m2c
#include "m2c_macros.h"
extern M2C_UNK D_002B8A00;
extern M2C_UNK D_002C1690;
extern M2C_UNK D_003156C0;

void func_001625F0(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    M2C_FIELD(&D_002C1690, s32* , 0x52438) = (s32) M2C_FIELD(arg3, s32* , 4);
    func_0010A7D8(&D_002B8A00, M2C_FIELD(arg3, s32* , 4));
    if ((M2C_FIELD(&D_003156C0, s32* , 0x1BB4) > 0) && (func_001734B8(&D_003156C0) != 0)) {
        func_00166808(&D_002C1690, M2C_FIELD(&D_002C1690, s32* , 0x52438));
    }
}
//@@ func_00162698 m2c
#include "m2c_macros.h"
extern M2C_UNK D_002C1690;

void func_00162698(s32 arg0) {
    M2C_FIELD(&D_002C1690, s32* , 8) = arg0;
    if (arg0 == -1) {
        func_00163EB8(&D_002C1690, 0xFFFFFF);
    } else {
        func_00163EB8(&D_002C1690, 0);
    }
    M2C_FIELD(&D_002C1690, s32* , 0) = 1;
}
//@@ func_001626F8 m2c
#include "m2c_macros.h"
extern s32 D_002C1690;
extern M2C_UNK D_004F9C20;

void func_001626F8(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    func_00163EB8(&D_002C1690, M2C_FIELD(arg3, s32* , 0x18));
    if (M2C_FIELD(arg3, s32* , 0x18) == 0) {
        strcpy(&D_002C1690 + 0xC, arg3 + 0x1C);
    } else {
        strcpy(&D_002C1690 + 0xC, &D_004F9C20);
    }
    D_002C1690 = 1;
}
//@@ func_00162778 m2c
#include "m2c_macros.h"
extern s32 D_002C1690;

void func_00162778(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    func_00163EB8(&D_002C1690, M2C_FIELD(arg3, s32* , 0x18));
    D_002C1690 = 1;
}
//@@ func_001628E0 m2c
#include "m2c_macros.h"
extern s32 D_002C1690;

void func_001628E0(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    func_00163EB8(&D_002C1690, M2C_FIELD(arg3, s32* , 0x18));
    D_002C1690 = 1;
}
//@@ func_00162918 m2c
#include "m2c_macros.h"
extern s32 D_002C1690;

void func_00162918(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    func_00163EB8(&D_002C1690, M2C_FIELD(arg3, s32* , 0x18));
    D_002C1690 = 1;
}
//@@ func_00162950 m2c
#include "m2c_macros.h"
extern s32 D_002C1690;

void func_00162950(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    func_00163EB8(&D_002C1690, M2C_FIELD(arg3, s32* , 0x18));
    D_002C1690 = 1;
}
//@@ func_00162988 m2c
#include "m2c_macros.h"
extern s32 D_002C1690;

void func_00162988(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    func_00163EB8(&D_002C1690, M2C_FIELD(arg3, s32* , 0x18));
    D_002C1690 = 1;
}
//@@ func_001629C0 m2c
#include "m2c_macros.h"
extern M2C_UNK D_002C1690;

void func_001629C0(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    M2C_FIELD(&D_002C1690, s32* , 0x60) = (s32) M2C_FIELD(arg3, s32* , 0x18);
    func_00163EB8(&D_002C1690, M2C_FIELD(arg3, s32* , 0x1C));
    M2C_FIELD(&D_002C1690, s32* , 0) = 1;
}
//@@ func_00162A00 m2c
#include "m2c_macros.h"
extern s32 D_002C1690;

void func_00162A00(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    func_00163EB8(&D_002C1690, M2C_FIELD(arg3, s32* , 0x58));
    D_002C1690 = 1;
}
//@@ func_00162A38 m2c
#include "m2c_macros.h"
extern s32 D_002C1690;

void func_00162A38(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    void* temp_a1;

    func_00163EB8(&D_002C1690, M2C_FIELD(arg3, s32* , 0x18));
    if (M2C_FIELD(arg3, s32* , 0x18) == 0) {
        temp_a1 = arg3 + 0x1C;
        if (temp_a1 != NULL) {
            func_001641B8(&D_002C1690, temp_a1);
        }
    }
    if (M2C_FIELD(arg3, s8* , 0x11C) != 0) {
        D_002C1690 = 1;
    }
}
//@@ func_00162AB0 m2c
#include "m2c_macros.h"
extern s32 D_002C1690;

void func_00162AB0(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    func_00163EB8(&D_002C1690, M2C_FIELD(arg3, s32* , 0x18));
    if (M2C_FIELD(arg3, s32* , 0x18) == 0) {
        func_00164240(&D_002C1690, arg3 + 0x20);
    }
    if (M2C_FIELD(arg3, s8* , 0x408) != 0) {
        D_002C1690 = 1;
    }
}
//@@ func_00162B20 m2c
#include "m2c_macros.h"
extern M2C_UNK D_002C1690;
extern M2C_UNK D_00301690;
extern M2C_UNK D_003156C0;
extern M2C_UNK D_004E58D0;
extern s32 D_004F9C58;
extern s32 D_004F9C5C;
extern s32 D_004F9C60;
extern s32 D_004F9C64;
extern s32 D_004F9C68;
extern s32 D_004F9C6C;
extern s32 D_004F9C70;
extern s32 D_004F9C74;
extern s32 D_004F9C78;
extern s32 D_004F9C7C;
extern s32 D_004F9C80;
extern M2C_UNK func_001648B0;
extern M2C_UNK func_00164938;

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
        D_004F9C58 -= 1;
    }
    if (D_004F9C58 < 0) {
        printf(&D_004E58D0);
        printf("!!!!     Ping Counter < 0  (%d)  !!!!\n", D_004F9C58);
        printf(&D_004E58D0);
    }
    if (M2C_FIELD(&D_002C1690, s32* , 0x41AB0) == 0) {
        if (M2C_FIELD(&D_002C1690, s32* , 0x406A4) == 0) {
            if (M2C_FIELD(&D_002C1690, s32* , 0x406A8) != 0) {
                var_s5 = 0;
                if (M2C_FIELD(&D_002C1690, s32* , 0x406A8) > 0) {
                    do {
                        temp_s0 = (var_s5 << 7) + 0x406AC + &D_002C1690;
                        if (strcmp(temp_s0 + 0x54, sp20) == 0) {
                            if (M2C_FIELD(temp_s0, M2C_UNK** , 0x7C) == (M2C_UNK* )0x270F) {
                                switch (arg0) {     /* irregular */
                                case 0x0:
                                case 0xFFFFFF:
                                    M2C_FIELD(temp_s0, M2C_UNK** , 0x7C) = arg2;
                                    D_004F9C60 += 1;
                                    if (M2C_FIELD(&D_003156C0, s32* , 0x4264) != 0) {
                                        var_a2 = temp_s0 + 4;
block_19:
                                        func_001649D8(&D_002C1690, M2C_FIELD(temp_s0, s32* , 0), var_a2, M2C_FIELD(temp_s0, s32* , 0x44), &func_00164938);
                                    } else {
                                        func_001649D8(&D_002C1690, M2C_FIELD(temp_s0, s32* , 0), temp_s0 + 4, M2C_FIELD(temp_s0, s32* , 0x44), arg2, &func_001648B0);
                                    }
                                    break;
                                case 0xE:
                                    M2C_FIELD(temp_s0, M2C_UNK** , 0x7C) = arg2;
                                    D_004F9C64 += 1;
                                    if (M2C_FIELD(&D_003156C0, s32* , 0x4264) != 0) {
                                        var_a2 = temp_s0 + 4;
                                        goto block_19;
                                    }
                                    func_001649D8(&D_002C1690, M2C_FIELD(temp_s0, s32* , 0), temp_s0 + 4, M2C_FIELD(temp_s0, s32* , 0x44), (M2C_UNK* )0x270E, &func_001648B0);
                                    break;
                                }
                            }
                        }
                        var_s5 += 1;
                    } while (var_s5 < M2C_FIELD(&D_00301690, s32* , 0x6A8));
                }
                var_v1 = 0;
                if (M2C_FIELD(&D_002C1690, s32* , 0x406A8) > 0) {
                    var_a0 = &D_002C1690 + 0x40728;
loop_25:
                    temp_v0 = *var_a0;
                    if (temp_v0 != 0x270F) {
                        var_v1 += 1;
                        if (temp_v0 != 0x2710) {
                            var_a0 += 0x80;
                            if (var_v1 >= M2C_FIELD(&D_002C1690, s32* , 0x406A8)) {
                                goto block_28;
                            }
                            goto loop_25;
                        }
                    }
                } else {
block_28:
                    if (D_004F9C58 == 0) {
                        M2C_FIELD(&D_002C1690, s32* , 0x406A4) = 1;
                        D_004F9C70 += D_004F9C5C;
                        D_004F9C74 += D_004F9C60;
                        D_004F9C78 += D_004F9C64;
                        D_004F9C7C += D_004F9C68;
                        D_004F9C80 += D_004F9C6C;
                        D_004F9C5C = 0;
                    }
                }
            }
        }
    }
}
//@@ func_00162F00 m2c
#include "m2c_macros.h"
extern M2C_UNK D_004F9C28;
extern M2C_UNK D_004F9C30;

void func_00162F00(void* arg0) {
    u8 sp[0x100];
    s32 var_a0;
    s32 var_s0;

    strcpy(sp);
    var_s0 = func_00299350(sp, &D_004F9C28);
    if (var_s0 != 0) {
        var_a0 = var_s0;
loop_2:
        if (func_00298010(var_a0, &D_004F9C30, 3) == 0) {
            strcpy(arg0, var_s0 + 4);
            return;
        }
        var_s0 = func_00299350(NULL, &D_004F9C28);
        var_a0 = var_s0;
        if (var_s0 == 0) {

        } else {
            goto loop_2;
        }
    }
}
//@@ func_00162FA0 m2c
#include "m2c_macros.h"
extern M2C_UNK D_004F9C28;
extern M2C_UNK D_004F9C30;

void func_00162FA0(s32 arg0) {
    u8 sp[0x100];
    s32 var_a0;
    s32 var_s0;

    strcpy(sp);
    var_s0 = func_00299350(sp, &D_004F9C28);
    if (var_s0 != 0) {
        var_a0 = var_s0;
loop_2:
        if (func_00298010(var_a0, &D_004F9C30, 3) == 0) {
            strcpy(var_s0 + 4, arg0);
            return;
        }
        var_s0 = func_00299350(NULL, &D_004F9C28);
        var_a0 = var_s0;
        if (var_s0 == 0) {

        } else {
            goto loop_2;
        }
    }
}
//@@ func_00163040 m2c
#include "m2c_macros.h"
extern M2C_UNK D_002C1690;
extern M2C_UNK D_004E58D0;
extern M2C_UNK D_004F9C38;
extern s32 D_004F9C58;

void func_00163040(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    M2C_UNK sp10;
    M2C_UNK* var_s0;
    M2C_UNK* var_s3;
    s32 temp_a2;
    s32 temp_s0;
    s32 var_s2;

    temp_s0 = arg3 + 0x134;
    func_00162F00(&sp10, arg3 + 0x34);
    if (func_00164610(&D_002C1690, temp_s0, M2C_FIELD(arg3, s32* , 0x174), M2C_FIELD(arg3, s32* , 0x28)) == 0) {
        printf("Game %s not found in the current temp list\n", temp_s0);
    } else if (strcmp(&sp10, &D_004F9C38) == 0) {
        printf("No IP address found for game %s\n", temp_s0);
    } else {
        var_s2 = 0;
        if (M2C_FIELD(&D_002C1690, s32* , 0x406A8) > 0) {
            var_s0 = &D_002C1690 + 0x40700;
            var_s3 = &D_002C1690 + 0x406B0;
loop_6:
            if (strcmp(var_s0, &sp10) != 0) {
                goto block_14;
            }
            if (strcmp(var_s3, arg3 + 0x134) == 0) {
block_14:
                var_s2 += 1;
                var_s3 += 0x80;
                var_s0 += 0x80;
                if (var_s2 >= M2C_FIELD(&D_002C1690, s32* , 0x406A8)) {
                    goto block_15;
                }
                goto loop_6;
            }
            temp_a2 = M2C_FIELD(var_s0, s32* , 0x28);
            if (temp_a2 < 0x270F) {
                func_00162B20(0xFFFFFF, var_s0, temp_a2);
            }
        } else {
block_15:
            if (func_0026B998(&sp10, func_00162B20) == 0) {
                D_004F9C58 += 1;
            }
            if (D_004F9C58 >= 0x29) {
                printf(&D_004E58D0);
                printf("!!!!     Ping Counter < %d (%d)  !!!!\n", 0x28, D_004F9C58);
                printf(&D_004E58D0);
            }
        }
    }
}
//@@ func_00163200 m2c
#include "m2c_macros.h"
extern M2C_UNK D_002C1690;

void func_00163200(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    printf("%d TOTAL GAMES\n", M2C_FIELD(arg3, s32* , 0x18));
    M2C_FIELD(&D_002C1690, s32* , 0x41AAC) = (s32) M2C_FIELD(arg3, s32* , 0x18);
    M2C_FIELD((&D_002C1690 + 0x41AB8), s32* , 0x50) = (s32) M2C_FIELD(arg3, s32* , 0x18);
    func_00163EB8(&D_002C1690, M2C_FIELD(arg3, s32* , 0x1C));
    M2C_FIELD(&D_002C1690, s32* , 0) = 1;
}
//@@ func_00163278 m2c
#include "m2c_macros.h"
extern M2C_UNK D_002C1690;
extern M2C_UNK D_00313EE0;
extern s32 D_004F9C5C;
extern s32 D_004F9C60;
extern s32 D_004F9C64;
extern s32 D_004F9C68;
extern s32 D_004F9C6C;
extern s32 D_004F9C70;
extern s32 D_004F9C74;
extern s32 D_004F9C78;
extern s32 D_004F9C7C;
extern s32 D_004F9C80;
extern s32 D_004F9C84;
extern M2C_UNK func_00163040;

void func_00163278(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_a3_2;
    s32 temp_t6;

    func_00163EB8(&D_002C1690, M2C_FIELD(arg3, s32* , 0x18));
    if (strcmp(arg3, &D_00313EE0) != 0) {
        printf("Received a GameListResponse for a game not in this page.\n");
    } else {
        if (M2C_FIELD(arg3, s32* , 0x18) == 0) {
            temp_a3 = M2C_FIELD(arg3, s32* , 0x60);
            if (temp_a3 != 0) {
                D_004F9C5C += 1;
                func_001644D0(&D_002C1690, M2C_FIELD(arg3, s32* , 0x1C), arg3 + 0x20, temp_a3);
                func_0025BD88(&D_002C1690 + 0x11, 0x1C, sp);
                strcpy(&sp15, &D_002C1690 + 0xC);
                sp28 = M2C_FIELD(arg3, s32* , 0x1C);
                func_0025B1D0(sp, &func_00163040);
            }
        }
        if (M2C_FIELD(arg3, s8* , 0x6C) != 0) {
            printf("Reached the end of this page. Games read %d\n", D_004F9C5C);
            D_004F9C84 = 1;
        }
        if (M2C_FIELD(arg3, s32* , 0x18) < 0) {
            M2C_FIELD(&D_002C1690, s32* , 0x41AB0) = 1;
            temp_a3_2 = D_004F9C7C + D_004F9C68;
            temp_a2 = D_004F9C80 + D_004F9C6C;
            D_004F9C74 += D_004F9C60;
            D_004F9C78 += D_004F9C64;
            D_004F9C7C = temp_a3_2;
            D_004F9C80 = temp_a2;
            D_004F9C70 += D_004F9C5C;
            M2C_FIELD(&D_002C1690, s32* , 0x406A4) = 1;
            D_004F9C5C = 0;
            printf("End of List = %d (Server Error - Aborted List)\n", 1, temp_a2, temp_a3_2);
            printf("List Stats: Count:%d, Ready:%d, TimedOut:%d, NoPing:%d, Tossed:%d\n", D_004F9C70, D_004F9C74, D_004F9C78);
        }
        temp_t6 = M2C_FIELD(arg3, s32* , 0x18);
        if (temp_t6 == 1) {
            M2C_FIELD(&D_002C1690, s32* , 0x41AB0) = temp_t6;
            D_004F9C7C += D_004F9C68;
            D_004F9C70 += D_004F9C5C;
            D_004F9C74 += D_004F9C60;
            D_004F9C78 += D_004F9C64;
            D_004F9C80 += D_004F9C6C;
            M2C_FIELD(&D_002C1690, s32* , 0x406A4) = temp_t6;
            D_004F9C5C = 0;
            printf("End of List = %d\n", 1, D_004F9C64, D_004F9C68);
            printf("List Stats: Count:%d, Ready:%d, TimedOut:%d, NoPing:%d, Tossed:%d\n", D_004F9C70, D_004F9C74, D_004F9C78);
        }
    }
}
//@@ func_00163560 m2c
#include "m2c_macros.h"
extern M2C_UNK D_002C1690;
extern M2C_UNK func_00163658;

void func_00163560(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    M2C_UNK sp30;
    M2C_UNK sp45;
    s32 sp58;

    func_00163EB8(&D_002C1690, M2C_FIELD(arg3, s32* , 0x18));
    if (M2C_FIELD(arg3, s32* , 0x18) == 0) {
        func_00164E60(&D_002C1690, M2C_FIELD(&D_002C1690, s32* , 0x52438), M2C_FIELD(arg3, s32* , 0x30), arg3 + 0x134, M2C_FIELD(arg3, s32* , 0x178), M2C_FIELD(arg3, s32* , 0x17C), M2C_FIELD(arg3, s32* , 0x180), M2C_FIELD(arg3, s32* , 0x184));
        func_0025BD88(&D_002C1690 + 0x11, 0x1F, &sp30);
        strcpy(&D_002C1690 + 0x51AF0, &sp30);
        strcpy(&sp45, &D_002C1690 + 0xC);
        sp58 = M2C_FIELD(&D_002C1690, s32* , 0x51B0C);
        func_0025B090(&sp30, &func_00163658);
    }
}
//@@ func_00163658 m2c
#include "m2c_macros.h"
extern M2C_UNK D_002C1690;

void func_00163658(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    void* temp_s0;

    temp_s0 = &D_002C1690 + 0x51AF0;
    printf("PlayerListHandler() called <<<%s>>>   <<<%s>>>)\n", temp_s0, arg3);
    if (strcmp(temp_s0, arg3) == 0) {
        func_00163EB8(&D_002C1690, M2C_FIELD(arg3, s32* , 0x18));
        if (M2C_FIELD(arg3, s32* , 0x18) == 0) {
            func_00164B60(&D_002C1690, M2C_FIELD(arg3, s32* , 0x1C), arg3 + 0x20, arg3 + 0x40);
        }
        if (M2C_FIELD(arg3, s8* , 0x144) != 0) {
            M2C_FIELD(&D_002C1690, s32* , 0x51B14) = 1;
        }
    }
}
//@@ func_00163708 m2c
#include "m2c_macros.h"
extern M2C_UNK D_002C1690;
extern M2C_UNK D_00313D6C;

void func_00163708(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    func_00163EB8(&D_002C1690, M2C_FIELD(arg3, s32* , 0x18));
    if (M2C_FIELD(arg3, s32* , 0x18) == 0) {
        M2C_FIELD(&D_002C1690, s32* , 0x52438) = (s32) M2C_FIELD(arg3, s32* , 0x1C);
    }
    func_00266D78(&D_00313D6C);
    M2C_FIELD(&D_002C1690, s32* , 0) = 1;
}
//@@ func_00163778 m2c
#include "m2c_macros.h"
extern M2C_UNK D_002C1690;

void func_00163778(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    void* temp_s2;

    printf("FindWorldByName response\n");
    printf("MessageID %s\n", arg3);
    printf("StatusCode %d\n", M2C_FIELD(arg3, void** , 0x18));
    if (M2C_FIELD(arg3, void** , 0x18) != (void* )1) {
        temp_s2 = arg3 + 0x48;
        if ((M2C_FIELD(arg3, s32* , 0x40) == 0) && (strcmp(&D_002C1690 + 0x1D, temp_s2) == 0)) {
            printf("Game World found with id %d\n", M2C_FIELD(arg3, void** , 0x44));
            M2C_FIELD(&D_002C1690, void** , 0x52438) = (void* ) M2C_FIELD(arg3, void** , 0x44);
            func_00163EB8(&D_002C1690, M2C_FIELD(arg3, void** , 0x18));
        }
        printf("ApplicationID %d\n", M2C_FIELD(arg3, void** , 0x1C));
        printf("ApplicationName %s\n", arg3 + 0x20);
        printf("MediusWorldID %d\n", M2C_FIELD(arg3, void** , 0x44));
        printf("World Name %s\n", temp_s2);
        printf("WorldStatus %d\n", M2C_FIELD(arg3, void** , 0x88));
        printf("EndOfList %c\n", (void* ) M2C_FIELD(arg3, s8* , 0x8C));
    } else {
        printf("World not found\n");
    }
    if (M2C_FIELD(arg3, s8* , 0x8C) != 0) {
        M2C_FIELD(&D_002C1690, s32* , 0) = 1;
    }
}
//@@ func_001639F8 m2c
#include "m2c_macros.h"
extern M2C_UNK D_002C1690;

void func_001639F8(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    func_00163EB8(&D_002C1690, M2C_FIELD(arg3, s32* , 0x18));
    M2C_FIELD(&D_002C1690, s32* , 0x51AEC) = (s32) M2C_FIELD(arg3, s32* , 0x24);
    M2C_FIELD(&D_002C1690, s32* , 0) = 1;
}
//@@ func_00163A58 m2c
#include "m2c_macros.h"
extern M2C_UNK D_002C1690;

void func_00163A58(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    func_00163EB8(&D_002C1690, M2C_FIELD(arg3, s32* , 0x18));
    func_00164E60(&D_002C1690, M2C_FIELD(&D_002C1690, s32* , 0x52438), M2C_FIELD(arg3, s32* , 0x30), arg3 + 0x134, M2C_FIELD(arg3, s32* , 0x178), M2C_FIELD(arg3, s32* , 0x17C), M2C_FIELD(arg3, s32* , 0x180), M2C_FIELD(arg3, s32* , 0x184));
    M2C_FIELD(&D_002C1690, s32* , 0) = 1;
}
//@@ func_00163B00 m2c
#include "m2c_macros.h"
extern M2C_UNK D_002C1690;
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
        func_00163EB8(&D_002C1690, temp_a1);
        M2C_FIELD(&D_002C1690, s32* , 0) = 1;
        printf(&D_004E5BD8);
        printf("In GetAndSendWorldReportHandler()\n gameLevel %d\n skillLevel %d\n playerCount %d\n gameName %s\n mode %d\n worldStatus %d\n gameStats %s\n", M2C_FIELD(arg3, M2C_UNK** , 0x28), M2C_FIELD(arg3, s32* , 0x2C), M2C_FIELD(arg3, s32* , 0x30));
        return;
    }
    temp_s3 = arg3 + 0x34;
    temp_s4 = arg3 + 0x134;
    func_00163EB8(&D_002C1690, 0);
    func_002666A8(&sp30);
    printf("replacing IP addy %s\n", &sp30);
    func_00162FA0(&sp30, temp_s3);
    printf("new stats %s\n", temp_s3);
    temp_t6 = M2C_FIELD(arg3, s32* , 0x17C);
    func_00164E60(&D_002C1690, M2C_FIELD(&D_002C1690, s32* , 0x52438), M2C_FIELD(arg3, s32* , 0x30), temp_s4, M2C_FIELD(arg3, s32* , 0x178), temp_t6, temp_t6, M2C_FIELD(arg3, s32* , 0x184));
    strcpy(&sp130, &D_002C1690 + 0xC);
    sp144 = M2C_FIELD(&D_002C1690, s32* , 0x52438);
    sp148 = M2C_FIELD(arg3, s32* , 0x30);
    strcpy(&sp14C, temp_s4);
    strcpy(&sp18C, temp_s3);
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
    func_0025B938(&sp130, temp_a1_2, temp_a2, temp_a3);
    M2C_FIELD(&D_002C1690, s32* , 0) = 1;
}
//@@ func_00163CE0 m2c
#include "m2c_macros.h"
extern M2C_UNK D_002C1690;

void func_00163CE0(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    func_00163EB8(&D_002C1690, M2C_FIELD(arg3, s32* , 0x18));
    func_00164F68(&D_002C1690, M2C_FIELD(&D_002C1690, s32* , 0x52438), arg3 + 0x48);
    M2C_FIELD(&D_002C1690, s32* , 0) = 1;
}
//@@ func_00163D48 m2c
#include "m2c_macros.h"
extern M2C_UNK D_002C1690;

void func_00163D48(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    u8 sp[0x120];
    M2C_UNK sp18;

    func_00163EB8(&D_002C1690, M2C_FIELD(arg3, s32* , 0x18));
    strcpy(sp, &D_002C1690 + 0xC);
    strcpy(&sp18, arg3 + 0x48, M2C_FIELD(&D_002C1690, s32* , 0x52438));
    func_0025B8AC(sp);
    M2C_FIELD(&D_002C1690, s32* , 0) = 1;
}
//@@ func_00163DC8 m2c
#include "m2c_macros.h"
extern s32 D_004F9C70;
extern s32 D_004F9C74;
extern s32 D_004F9C78;
extern s32 D_004F9C7C;
extern s32 D_004F9C80;

void func_00163DC8(void* arg0) {
    M2C_FIELD(arg0, s32* , 0x41AB4) = 0;
    M2C_FIELD(arg0, s32* , 0x41AB0) = 0;
    D_004F9C70 = 0;
    D_004F9C74 = 0;
    D_004F9C78 = 0;
    D_004F9C7C = 0;
    D_004F9C80 = 0;
}
//@@ func_00163E00 m2c
#include "m2c_macros.h"
void func_00163E00(s32* arg0, s32 arg1) {
    u8 sp[0x10];
    s32 sp4;
    s32 sp8;

    func_00266D78(sp);
    sp8 = subroutine_arg0;
    if (*arg0 == 0) {
        do {
            func_00266D78(&sp4);
            if ((sp4 - sp8) >= 0x33) {
                func_0025A020();
                func_00266D78(&sp8);
            }
            if (arg1 < (sp4 - subroutine_arg0)) {
                *arg0 = 1;
                func_00163EB8(arg0, -0x32);
            }
        } while (*arg0 == 0);
    }
    *arg0 = 0;
}
//@@ func_00163EC0 m2c
#include "m2c_macros.h"
extern M2C_UNK D_002C1690;
extern M2C_UNK D_00301690;
extern M2C_UNK D_003156C0;
extern s32 D_004F9C58;
extern s32 D_004F9C5C;
extern s32 D_004F9C60;
extern s32 D_004F9C64;
extern s32 D_004F9C68;
extern s32 D_004F9C6C;
extern s32 D_004F9C70;
extern s32 D_004F9C74;
extern s32 D_004F9C78;
extern s32 D_004F9C7C;
extern s32 D_004F9C80;
extern M2C_UNK func_001648B0;
extern M2C_UNK func_00164938;

s32 func_00163EC0(void* arg0, s32 arg1, s32 arg2) {
    s32 sp20;
    s32 temp_fp;
    s32 temp_v0;
    s32 var_s2;
    s32 var_v0;
    void* temp_s0;
    void* temp_s1;

    func_00266D78(&sp20);
    temp_fp = sp20 - M2C_FIELD(arg0, s32* , 0x406A0);
    var_v0 = 0;
    if (arg1 < temp_fp) {
        if (arg2 != 0) {
            var_s2 = 0;
            if (M2C_FIELD(&D_002C1690, s32* , 0x406A8) > 0) {
                do {
                    temp_s0 = (var_s2 << 7) + 0x406AC + &D_002C1690;
                    temp_v0 = M2C_FIELD(temp_s0, s32* , 0x7C);
                    temp_s1 = temp_s0 + 4;
                    if (temp_v0 == 0x2710) {
                        printf("Throwing away No-Info Game %s\n", temp_s1);
                        M2C_FIELD(temp_s0, s32* , 0x7C) = 0x270E;
                        D_004F9C6C += 1;
                        func_001649D8(&D_002C1690, M2C_FIELD(temp_s0, s32* , 0), temp_s1, M2C_FIELD(temp_s0, s32* , 0x44), 0x270F, &func_001648B0);
                    } else if (temp_v0 == 0x270F) {
                        M2C_FIELD(temp_s0, s32* , 0x7C) = 0x270E;
                        D_004F9C68 += 1;
                        if (M2C_FIELD(&D_003156C0, s32* , 0x4264) != 0) {
                            func_001649D8(&D_002C1690, M2C_FIELD(temp_s0, s32* , 0), temp_s0 + 4, M2C_FIELD(temp_s0, s32* , 0x44), 0x270E, &func_00164938);
                        } else {
                            func_001649D8(&D_002C1690, M2C_FIELD(temp_s0, s32* , 0), temp_s0 + 4, M2C_FIELD(temp_s0, s32* , 0x44), 0x270E, &func_001648B0);
                        }
                    }
                    var_s2 += 1;
                } while (var_s2 < M2C_FIELD(&D_00301690, s32* , 0x6A8));
            }
        }
        if ((D_004F9C58 == 0) || (var_v0 = 0, ((temp_fp < 0x7531) == 0))) {
            var_v0 = 1;
            D_004F9C70 += D_004F9C5C;
            D_004F9C74 += D_004F9C60;
            D_004F9C78 += D_004F9C64;
            D_004F9C7C += D_004F9C68;
            D_004F9C80 += D_004F9C6C;
            M2C_FIELD(arg0, s32* , 0x406A4) = 1;
            M2C_FIELD(arg0, s32* , 0x406A8) = 0;
        }
    }
    return var_v0;
}
//@@ func_001641B8 m2c
#include "m2c_macros.h"
void func_001641B8(void* arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = strlen(arg0 + 0x64);
    if ((u32) (temp_s0 + strlen(arg1)) >= 0x1E00U) {
        printf("Policy array full. Further policy information not stored\n");
        return;
    }
    strcpy(M2C_FIELD(arg0, s32* , 0x1E64), arg1);
    M2C_FIELD(arg0, s32* , 0x1E64) = (s32) (M2C_FIELD(arg0, s32* , 0x1E64) + strlen(arg1));
}
//@@ func_00164240 m2c
#include "m2c_macros.h"
s32 func_00164240(void* arg0) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32* , 0x1E68);
    if (temp_v1 < 0x100) {
        M2C_FIELD(arg0, s32* , 0x1E68) = (s32) (temp_v1 + 1);
        strcpy(arg0 + ((temp_v1 * 0x3E8) + 0x1E6C), arg0);
        return 1;
    }
    return 0;
}
//@@ func_00164750 m2c
#include "m2c_macros.h"
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
            strcpy(var_s2, temp_a1);
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
            strcpy(temp_a0, temp_a1_2, temp_a2, temp_a3);
            M2C_FIELD(var_s1, s32* , 0) = (s32) M2C_FIELD(var_s1, s32* , 0x80);
            M2C_FIELD(var_s1, s32* , -4) = (s32) M2C_FIELD(var_s1, s32* , 0x7C);
            var_s1 += 0x80;
        } while (var_s0 < (M2C_FIELD(arg0, s32* , 0x406A8) + 1));
    }
    M2C_FIELD(arg0, s32* , 0x406A8) = (s32) (M2C_FIELD(arg0, s32* , 0x406A8) - 1);
    return 1;
}
//@@ func_00164B60 m2c
#include "m2c_macros.h"
s32 func_00164B60(void* arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3) {
    s32 temp_a2;
    s32 temp_v1;
    s32 temp_v1_2;

    temp_v1 = M2C_FIELD(arg0, s32* , 0x51B10);
    if (temp_v1 < 8) {
        temp_a2 = temp_v1 * 0x124;
        M2C_FIELD((temp_a2 + (arg0 + 0x50000)), s32* , 0x1B18) = arg1;
        strcpy(arg0 + ((M2C_FIELD(arg0, s32* , 0x51B10) * 0x124) + 0x51B18) + 4, arg2, temp_a2);
        temp_v1_2 = M2C_FIELD(arg0, s32* , 0x51B10);
        M2C_FIELD(arg0, s32* , 0x51B10) = (s32) (temp_v1_2 + 1);
        strcpy(arg0 + ((temp_v1_2 * 0x124) + 0x51B18) + 0x24, arg3);
        return 1;
    }
    return 0;
}
//@@ func_00164FD8 m2c
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
//@@ func_001653D8 m2c
#include "m2c_macros.h"
extern M2C_UNK func_001625D8;
extern M2C_UNK func_001625E0;
extern M2C_UNK func_001625E8;
extern M2C_UNK func_001625F0;

void func_001653D8(void) {
    u8 sp[0x30];
    M2C_UNK sp20;

    func_00259A58(sp, &sp20, &func_001625F0, 0x7530, 0x7530);
}
//@@ func_00165430 m2c
#include "m2c_macros.h"
extern u16 D_004F9C40;
extern M2C_UNK func_00162670;

void func_00165430(s32 arg0) {
    u8 sp[0x30];
    M2C_UNK sp15;

    strcpy(&sp15, arg0 + 0xC);
    printf("Trying to request the server version\n");
    printf("Session Key = %s\n", &sp15);
    func_00259C6C(sp, &func_00162670);
}
//@@ func_001658E8 m2c
#include "m2c_macros.h"
extern s32 D_002C1694;
extern s32 D_00319924;
extern M2C_UNK func_001626F8;

s32 func_001658E8(s32* arg0) {
    u8 sp[0x20];
    s32 temp_v0;

    func_0025BD88(arg0 + 0xC, 0x35, sp);
    if (D_00319924 != 0) {

    }
    *arg0 = 0;
    temp_v0 = func_0025A208(sp, &func_001626F8);
    if (temp_v0 != 0) {
        func_00163EB8(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00(arg0, 0xC350);
    return (D_002C1694 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165998 m2c
#include "m2c_macros.h"
extern s32 D_002C1694;
extern M2C_UNK func_00162778;

s32 func_00165998(s32* arg0) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88(temp_s0, 0x36, sp);
    strcpy(&sp15, temp_s0);
    *arg0 = 0;
    temp_v0 = func_0025A2A0(sp, &func_00162778);
    if (temp_v0 != 0) {
        func_00163EB8(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00(arg0, 0xC350);
    return (D_002C1694 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165A38 m2c
#include "m2c_macros.h"
extern s32 D_002C1694;
extern M2C_UNK func_001627B0;

s32 func_00165A38(s32* arg0, s32 arg1, s32 arg2) {
    u8 sp[0x70];
    M2C_UNK sp15;
    M2C_UNK sp26;
    M2C_UNK sp46;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88(temp_s0, 3, sp);
    strcpy(&sp15, temp_s0);
    strcpy(&sp26, arg1);
    strcpy(&sp46, arg2);
    *arg0 = 0;
    temp_v0 = func_0025A344(sp, &func_001627B0);
    if (temp_v0 != 0) {
        func_00163EB8(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00(arg0, 0xC350);
    return (D_002C1694 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165B08 m2c
#include "m2c_macros.h"
extern s32 D_002C1694;
extern M2C_UNK func_001628E0;

s32 func_00165B08(s32* arg0) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88(temp_s0, 4, sp);
    strcpy(&sp15, temp_s0);
    *arg0 = 0;
    temp_v0 = func_0025A3FC(sp, &func_001628E0);
    if (temp_v0 != 0) {
        func_00163EB8(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00(arg0, 0xC350);
    return (D_002C1694 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165BA8 m2c
#include "m2c_macros.h"
extern s32 D_002C1694;
extern M2C_UNK func_00162918;

s32 func_00165BA8(s32* arg0, s32 arg1, s32 arg2) {
    u8 sp[0x70];
    M2C_UNK sp15;
    s32 sp28;
    M2C_UNK sp2C;
    M2C_UNK sp4C;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88(temp_s0, 5, sp);
    strcpy(&sp15, temp_s0);
    sp28 = 1;
    strcpy(&sp2C, arg1);
    strcpy(&sp4C, arg2);
    *arg0 = 0;
    temp_v0 = func_0025A53C(sp, &func_00162918);
    if (temp_v0 != 0) {
        func_00163EB8(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00(arg0, 0xC350);
    return (D_002C1694 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165C80 m2c
#include "m2c_macros.h"
extern s32 D_002C1694;
extern M2C_UNK func_00162950;

s32 func_00165C80(s32* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp[0x70];
    M2C_UNK sp15;
    M2C_UNK sp26;
    M2C_UNK sp46;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88(temp_s0, 7, sp);
    strcpy(&sp15, temp_s0);
    strcpy(&sp26, arg2);
    strcpy(&sp46, arg3);
    *arg0 = 0;
    temp_v0 = func_0025A5F4(sp, &func_00162950);
    if (temp_v0 != 0) {
        func_00163EB8(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00(arg0, 0xC350);
    return (D_002C1694 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165D50 m2c
#include "m2c_macros.h"
extern s32 D_002C1694;
extern M2C_UNK func_00162988;

s32 func_00165D50(s32* arg0, s32 arg1) {
    u8 sp[0x50];
    M2C_UNK sp15;
    M2C_UNK sp26;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88(temp_s0, 0, sp);
    strcpy(&sp15, temp_s0);
    strcpy(&sp26, arg1);
    *arg0 = 0;
    temp_v0 = func_0025A888(sp, &func_00162988);
    if (temp_v0 != 0) {
        func_00163EB8(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00(arg0, 0xC350);
    return (D_002C1694 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00165E08 m2c
#include "m2c_macros.h"
extern s32 D_002C1694;
extern M2C_UNK func_001629C0;

s32 func_00165E08(void* arg0, s32 arg1) {
    u8 sp[0x50];
    M2C_UNK sp15;
    M2C_UNK sp26;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88(temp_s0, 1, sp);
    strcpy(&sp15, temp_s0);
    strcpy(&sp26, arg1);
    M2C_FIELD(arg0, s32* , 0) = 0;
    temp_v0 = func_0025C088(sp, &func_001629C0);
    if (temp_v0 == 0) {
        func_00163E00(arg0, 0xC350);
        if (D_002C1694 >= 0) {
            return 0;
        }
        M2C_FIELD(arg0, s32* , 0x60) = -1;
        return 0xFFFFFF;
    }
    M2C_FIELD(arg0, s32* , 0x60) = -1;
    func_00163EB8(arg0, 0xFFFFFF);
    return temp_v0;
}
//@@ func_00165ED0 m2c
#include "m2c_macros.h"
void func_00165ED0(s32 arg0, s32 arg1) {
    u8 sp[0x20];
    strcpy(sp, arg0 + 0xC);
    func_0025A184(sp, arg1);
}
//@@ func_00165F08 m2c
#include "m2c_macros.h"
extern M2C_UNK func_00162A00;

s32 func_00165F08(s32* arg0, s32 arg1) {
    u8 sp[0x70];
    M2C_UNK sp15;
    s32 sp28;
    M2C_UNK sp2C;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88(temp_s0, 0x5A, sp);
    strcpy(&sp15, temp_s0);
    sp28 = 0;
    strcpy(&sp2C, arg1);
    *arg0 = 0;
    temp_v0 = func_0025AA6C(sp, &func_00162A00);
    if (temp_v0 != 0) {
        func_00163EB8(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00(arg0, 0xC350);
    return 0;
}
//@@ func_00165FB0 m2c
#include "m2c_macros.h"
extern s32 D_002C1694;
extern M2C_UNK func_00162A38;

s32 func_00165FB0(void* arg0) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x1E64) = (s32) (arg0 + 0x64);
    func_0025BD88(temp_s0, 0x24, sp);
    strcpy(&sp15, temp_s0);
    M2C_FIELD(arg0, s32* , 0) = 0;
    sp28 = 0;
    temp_v0 = func_0025B80C(sp, &func_00162A38);
    if (temp_v0 != 0) {
        func_00163EB8(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00(arg0, 0xC350);
    return (D_002C1694 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166060 m2c
#include "m2c_macros.h"
extern s32 D_002C1694;
extern M2C_UNK func_00162AB0;

s32 func_00166060(void* arg0) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x1E68) = 0;
    func_0025BD88(temp_s0, 0x18, sp);
    strcpy(&sp15, temp_s0);
    M2C_FIELD(arg0, s32* , 0) = 0;
    sp28 = 0x272F;
    temp_v0 = func_0025BA68(sp, &func_00162AB0);
    if (temp_v0 != 0) {
        func_00163EB8(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00(arg0, 0xC350);
    return (D_002C1694 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166110 m2c
#include "m2c_macros.h"
extern M2C_UNK func_00163200;

s32 func_00166110(s32* arg0) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88(temp_s0, 0x61, sp);
    strcpy(&sp15, temp_s0);
    *arg0 = 0;
    sp28 = 0x272F;
    temp_v0 = func_0025C93C(sp, &func_00163200);
    if (temp_v0 == 0) {
        func_00163E00(arg0, 0xC350);
    }
    return temp_v0;
}
//@@ func_00166190 m2c
#include "m2c_macros.h"
extern M2C_UNK D_00313EE0;
extern s32 D_004F9C58;
extern s32 D_004F9C5C;
extern s32 D_004F9C60;
extern s32 D_004F9C64;
extern s32 D_004F9C68;
extern s32 D_004F9C6C;
extern s32 D_004F9C84;
extern M2C_UNK func_00163278;

void func_00166190(void* arg0, s16 arg1) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 sp28;
    s16 sp2C;
    s16 sp2E;
    void* temp_s1;

    printf("Get Available Games - Page:%d PageSize:%d ListSize:%d\n\0BASCUS-97196\0\0\0 !\"#$%&'()*+,-.0123456789:;<=>?ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_abcdefghijklmnopqrstuvwxyz{}\0\00123456789\0\0 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\0 .0123456789", 0x28, 0x200);
    temp_s1 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x406A4) = 0;
    M2C_FIELD(arg0, s32* , 0x406A8) = 0;
    D_004F9C58 = 0;
    D_004F9C6C = 0;
    D_004F9C68 = 0;
    D_004F9C64 = 0;
    D_004F9C60 = 0;
    D_004F9C5C = 0;
    D_004F9C84 = 0;
    func_0025BD88(temp_s1, 0x20, sp);
    strcpy(&D_00313EE0, sp);
    strcpy(&sp15, temp_s1);
    sp2C = arg1;
    sp28 = 0x272F;
    sp2E = 0x28;
    func_00266D78(arg0 + 0x406A0);
    func_0025AEB0(sp, &func_00163278);
}
//@@ func_00166280 m2c
#include "m2c_macros.h"
extern M2C_UNK func_00163560;

void func_00166280(void* arg0, s32 arg1) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;

    temp_s0 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x51B0C) = arg1;
    M2C_FIELD(arg0, s32* , 0x51B10) = 0;
    M2C_FIELD(arg0, s32* , 0x51B14) = 0;
    func_0025BD88(temp_s0, 0x1C, sp);
    strcpy(&sp15, temp_s0);
    sp28 = M2C_FIELD(arg0, s32* , 0x51B0C);
    func_0025B1D0(sp, &func_00163560);
}
//@@ func_001662F8 m2c
#include "m2c_macros.h"
extern M2C_UNK func_00163658;

void func_001662F8(void* arg0, s32 arg1) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;

    temp_s0 = arg0 + 0xC;
    M2C_FIELD(arg0, s32* , 0x51B14) = 0;
    M2C_FIELD(arg0, s32* , 0x51B10) = 0;
    func_0025BD88(temp_s0, 0x1F, sp);
    strcpy(&sp15, temp_s0);
    sp28 = arg1;
    func_0025B090(sp, &func_00163658);
}
//@@ func_00166368 m2c
#include "m2c_macros.h"
extern s32 D_002C1694;
extern M2C_UNK func_00163708;

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
    func_0025BD88(temp_s0, 0x10, sp);
    strcpy(&sp15, temp_s0);
    sp28 = 0x272F;
    sp30 = 8;
    sp34 = arg3;
    sp2C = 1;
    strcpy(&sp38, arg1);
    strcpy(&sp78, arg2);
    M2C_FIELD(arg0, s32* , 0x52440) = 0;
    M2C_FIELD(arg0, s32* , 0) = 0;
    sp98 = 1;
    sp9C = -1;
    spAC = 0;
    spA0 = 0;
    spA4 = 0;
    spA8 = 0;
    var_v0 = func_0025A9B4(sp, &func_00163708);
    if (var_v0 == 0) {
        func_00163E00(arg0, 0xC350);
        var_v0 = (D_002C1694 >= 0) ? 0 : 0xFFFFFF;
    }
    return var_v0;
}
//@@ func_00166478 m2c
#include "m2c_macros.h"
extern M2C_UNK D_002C1690;
extern M2C_UNK func_00163778;

s32 func_00166478(s32* arg0, s32 arg1) {
    u8 sp[0x70];
    M2C_UNK sp15;
    M2C_UNK sp26;
    s32 sp68;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    strcpy(arg0 + 0x1D);
    func_0025BD88(temp_s0, 0x15, sp);
    strcpy(&sp15, temp_s0);
    strcpy(&sp26, arg1);
    sp68 = 2;
    func_00163EB8(&D_002C1690, 1);
    *arg0 = 0;
    temp_v0 = func_0025B3BC(sp, &func_00163778);
    if (temp_v0 == 0) {
        func_00163E00(arg0, 0xC350);
    }
    return temp_v0;
}
//@@ func_00166528 m2c
#include "m2c_macros.h"
extern s32 D_002C1694;
extern M2C_UNK func_001638C0;

s32 func_00166528(s32* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp[0x80];
    M2C_UNK sp15;
    s32 sp28;
    M2C_UNK sp2C;
    s32 sp4C;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88(temp_s0, 0x2A, sp);
    strcpy(&sp15, temp_s0);
    sp28 = arg1;
    strcpy(&sp2C, arg2);
    *arg0 = 0;
    sp4C = arg3;
    temp_v0 = func_0025ACF0(sp, &func_001638C0);
    if (temp_v0 != 0) {
        func_00163EB8(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00(arg0, 0xC350);
    return (D_002C1694 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166600 m2c
#include "m2c_macros.h"
extern M2C_UNK D_004F9C48;
extern M2C_UNK D_004F9C50;

void func_00166600(s32 arg0, s32 arg1) {
    u8 sp[0x80];
    strcpy(sp, arg0 + 0xC);
    func_0025B9D0(sp, &D_004F9C50, &D_004F9C50, M2C_FIELD(&D_004F9C48, u8* , 4), arg1, M2C_FIELD(&D_004F9C48, s32* , 0), M2C_FIELD(&D_004F9C48, u8* , 4), M2C_FIELD(&D_004F9C50, s32* , 0), M2C_FIELD(&D_004F9C50, u16* , 4), M2C_FIELD(&D_004F9C50, u8* , 6), 0x3E8);
}
//@@ func_00166678 m2c
#include "m2c_macros.h"
extern s32 D_002C1694;
extern M2C_UNK func_001639F8;

s32 func_00166678(s32* arg0, s32 arg1) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 sp28;
    s32 sp2C;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88(temp_s0, 0xFFFFFF, sp);
    strcpy(&sp15, temp_s0);
    *arg0 = 0;
    sp28 = arg1;
    sp2C = 0;
    temp_v0 = func_0025BF48(sp, &func_001639F8);
    if (temp_v0 != 0) {
        func_00163EB8(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00(arg0, 0xC350);
    return (D_002C1694 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166730 m2c
#include "m2c_macros.h"
extern s32 D_002C1694;
extern M2C_UNK func_00163A58;

s32 func_00166730(s32* arg0, s32 arg1) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88(temp_s0, 0x1C, sp);
    strcpy(&sp15, temp_s0);
    *arg0 = 0;
    sp28 = arg1;
    temp_v0 = func_0025B1D0(sp, &func_00163A58);
    if (temp_v0 != 0) {
        func_00163EB8(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00(arg0, 0xC350);
    return (D_002C1694 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166808 m2c
#include "m2c_macros.h"
extern M2C_UNK func_00163B00;

void func_00166808(s32 arg0, s32 arg1) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88(temp_s0, 0x1C, sp);
    strcpy(&sp15, temp_s0);
    sp28 = arg1;
    func_0025B1D0(sp, &func_00163B00);
}
//@@ func_00166868 m2c
#include "m2c_macros.h"
extern s32 D_002C1694;
extern M2C_UNK func_00163CE0;

s32 func_00166868(s32 arg0, s32 arg1, s32 arg2) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88(temp_s0, 0x23, sp);
    strcpy(&sp15, temp_s0);
    sp28 = arg2;
    temp_v0 = func_0025B130(sp, &func_00163CE0);
    if (temp_v0 != 0) {
        func_00163EB8(arg0, 0xFFFFFF);
        return temp_v0;
    }
    func_00163E00(arg0, 0xC350);
    return (D_002C1694 >= 0) ? 0 : 0xFFFFFF;
}
//@@ func_00166940 m2c
#include "m2c_macros.h"
extern M2C_UNK func_00163D48;

void func_00166940(s32 arg0, s32 arg1, s32 arg2) {
    u8 sp[0x30];
    M2C_UNK sp15;
    s32 sp28;
    s32 temp_s0;

    temp_s0 = arg0 + 0xC;
    func_0025BD88(temp_s0, 0x23, sp);
    strcpy(&sp15, temp_s0);
    sp28 = arg2;
    func_0025B130(sp, &func_00163D48);
}
//@@ netMsgWorldEventHandler m2c
#include "m2c_macros.h"
extern void* D_004FA030;
extern s32 D_004FA038;

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
                    temp_a0 = M2C_FIELD((D_004FA030 + 0x80000 + var_a2), void** , 0x63A0);
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
                M2C_FIELD(D_004FA030, s32* , 0x9651C) = 1;
                M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x96580), s8* , 0xC) = 0;
                hierSetSwitch__FP11_hierswitchi(M2C_FIELD(D_004FA030, s32* , 0x96604), 1, (void* )0x90000);
            }
            goto block_59;
        }
        var_s3_2 = 0;
        var_v1_2 = 1;
loop_16:
        var_s0_2 = 7;
        if (var_v1_2 != 0) {
            temp_v1_2 = D_004FA038;
loop_18:
            temp_v0_2 = var_s1 << 6;
            temp_a1_2 = temp_v1_2 + temp_v0_2;
            temp_a2 = M2C_FIELD(temp_a1_2, void** , 0x10);
            if (temp_a2 != NULL) {
                if ((M2C_FIELD((arg3 + var_s3_2), u8* , 4) & (1 << var_s0_2)) > 0) {
                    M2C_FIELD(temp_a1_2, s32* , 4) = -1;
                    M2C_FIELD(temp_a2, s8* , 8) = 1;
                    temp_v1_3 = (u32) *M2C_FIELD((D_004FA038 + temp_v0_2), u32** , 0x10) >> 0x12;
                    switch (temp_v1_3) {
                    case 0x179F:
                        M2C_FIELD(D_004FA030, s32* , 0x967B8) = 1;
                        M2C_FIELD(D_004FA030, s32* , 0x967B4) = 1;
                        hierSetSwitch__FP11_hierswitchi(M2C_FIELD(D_004FA030, s32* , 0x96800), 1, temp_a2, 1);
                        break;
                    case 0x177F:
                        func_001FBCF8(sp, 0x271D, 0, 1);
                        animationStart__FR11_animHandleb(sp, 1);
                        break;
                    case 0x1793:
                        M2C_FIELD(D_004FA030, s32* , 0x96658) = 1;
                        break;
                    case 0x178F:
                        M2C_FIELD(D_004FA030, s32* , 0x96664) = 1;
                        break;
                    case 0x1790:
                        M2C_FIELD(D_004FA030, s32* , 0x96668) = 1;
                        break;
                    case 0x1791:
                        M2C_FIELD(D_004FA030, s32* , 0x9666C) = 1;
                        break;
                    case 0x1792:
                        M2C_FIELD(D_004FA030, s32* , 0x96670) = 1;
                        break;
                    case 0x17B3:
                        func_001FBCF8(sp, 0x2909, 0, 1);
                        animationStart__FR11_animHandleb(sp, 1);
                        break;
                    }
                } else {
                default:
                }
                temp_a1_3 = M2C_FIELD((D_004FA038 + temp_v0_2), u32** , 0x10);
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
        if (M2C_FIELD(D_004FA030, s32* , 0x96658) != 0) {
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
//@@ netMsgRosterHandler m2c
#include "m2c_macros.h"
extern M2C_UNK D_003156C0;
extern M2C_UNK D_00318416;

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
        var_a2 = &D_00318416;
        var_t0 = &D_00318416 + 0x272;
        var_s7 = arg3 + 0x2C;
        var_s6 = arg3 + 0x28;
        var_s5 = arg3 + 0x1C;
        var_s4 = arg3 + 0x18;
        var_s3 = arg3 + 0x20;
        var_s2 = arg3 + 0x24;
        var_s1 = arg3 + 0x14;
        var_s0 = &D_00318416 + 0x252;
        do {
            temp_a1 = var_fp;
            var_fp += 0x30;
            strcpy((s128) var_a2, temp_a1, (s128) var_a2, (s128) var_t0, var_t1);
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
        M2C_FIELD(&D_003156C0, s32* , 0x3230) = 1;
    }
    return 0x180;
}
//@@ func_00168B60 m2c
#include "m2c_macros.h"
extern M2C_UNK D_003156C0;
extern M2C_UNK D_003156D0;

void func_00168B60(s32 arg0, s32 arg1, M2C_UNK arg2) {
    if (arg1 != 0x100) {
        if (arg0 == M2C_FIELD(&D_003156C0, s32* , 0x2CF0)) {
            if (M2C_FIELD(&D_003156C0, s32* , 0x1BB4) > 0) {
                if (func_001734B8(&D_003156C0) != 0) {
                    func_00174988(&D_003156C0, arg1);
                }
            }
            *((arg1 * 0x220) + &D_003156D0) = arg1;
            strcpy((arg1 * 0x220) + &D_003156D0 + 0xC4, arg2);
            printf("Client %d Connecting on Connection %d from IP %s\n", arg1, arg0, arg2);
            func_00171B78(&D_003156D0 - 0x10, arg1);
        }
    }
}
//@@ func_00168C30 m2c
#include "m2c_macros.h"
extern M2C_UNK D_003156C0;
extern M2C_UNK D_004E6A00;
extern void* D_004FA030;

void func_00168C30(s32 arg0, s32 arg1) {
    void* temp_v1;
    void* temp_v1_2;

    if ((arg1 != 0x100) && (arg0 == M2C_FIELD(&D_003156C0, s32* , 0x2CF0))) {
        func_0016EF90(&D_003156C0);
        if ((func_001733F8(&D_003156C0) == 1) && (func_00176B10(&D_003156C0, 1) <= 0)) {
            printf(&D_004E6A00);
            func_00176CC8(&D_003156C0);
        } else if (func_001734B8(&D_003156C0) != 0) {
            func_00174988(&D_003156C0, -1);
            M2C_FIELD(&D_003156C0, s32* , 0x2EE4) = 0;
            if (func_001733F8(&D_003156C0) == 2) {
                temp_v1 = M2C_FIELD(D_004FA030, void** , 0x9E690);
                if (temp_v1 != NULL) {
                    M2C_FIELD(temp_v1, s32* , 0x20C0) = -1;
                    M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x9E690), s32* , 0x20B4) = 4;
                }
                temp_v1_2 = M2C_FIELD(D_004FA030, void** , 0x9E694);
                if (temp_v1_2 != NULL) {
                    M2C_FIELD(temp_v1_2, s32* , 0x20C0) = -1;
                    M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x9E694), s32* , 0x20B4) = 4;
                }
            }
        } else if (func_001733F8(&D_003156C0) == 1) {
            func_00173500(&D_003156C0);
        }
        func_0016F1C8(&D_003156C0, arg1);
        func_0016EF90(&D_003156C0, arg1);
    }
}
//@@ func_00168DE0 m2c
#include "m2c_macros.h"
extern M2C_UNK D_003156C0;
extern M2C_UNK D_003186FC;
extern void* D_004FA030;
extern void* D_004FA03C;

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
        if (arg0 == M2C_FIELD(&D_003156C0, s32* , 0x2CF0)) {
            M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 0x3148), s8* , 0x24) = func_00176B10(&D_003156C0, 0);
            if (func_001734B8(&D_003156C0) != 0) {
                M2C_FIELD(&D_003156C0, s32* , 0x307C) = netGetMyClientIndex(&D_003156C0);
                temp_v1 = M2C_FIELD(D_004FA030, void** , 0x9E690);
                if (temp_v1 != NULL) {
                    M2C_FIELD(temp_v1, s32* , 0x20C0) = -1;
                }
                temp_v1_2 = M2C_FIELD(D_004FA030, void** , 0x9E694);
                if (temp_v1_2 != NULL) {
                    M2C_FIELD(temp_v1_2, s32* , 0x20C0) = -1;
                }
                func_00174BF0(&D_003156C0);
                func_00170DF0(&D_003156C0, M2C_FIELD(D_004FA03C, s32* , 0x1A3AC));
                var_v0 = &D_003156C0 + 0x3058;
                var_a1 = 7;
                do {
                    *var_v0 = 0;
                    var_a1 -= 1;
                    var_v0 -= 4;
                } while (var_a1 >= 0);
                var_v1 = D_004FA030 + 0x20D8;
                var_a1_2 = 7;
                do {
                    temp_v0 = *var_v1;
                    if (temp_v0 != NULL) {
                        temp_v0_2 = M2C_FIELD(temp_v0, s32* , 4);
                        if (temp_v0_2 != -1) {
                            *((temp_v0_2 * 4) + &D_003186FC) = 1;
                        }
                    }
                    var_a1_2 -= 1;
                    var_v1 += 0x31B0;
                } while (var_a1_2 >= 0);
            }
        }
    }
}
//@@ func_00168F30 m2c
#include "m2c_macros.h"
extern M2C_UNK D_004F9D10;
extern s32 D_004F9D94;

void func_00168F30(s32 arg0, s32 arg1) {
    u8 sp[0x70];
    s32 sp10;
    M2C_UNK sp44;
    s32 sp54;

    if (strcmp(&D_004F9D10, arg0) != 0) {
        func_002665A0(sp, arg0);
        sp10 = 1;
        strcpy(&sp44, arg0);
        sp54 = arg1;
        dmeSendMsg(0, sp, 2, D_004F9D94);
    }
}
//@@ func_00168FB8 m2c
#include "m2c_macros.h"
extern M2C_UNK D_003156C0;

void func_00168FB8(s32 arg0, M2C_UNK arg1, s32 arg2) {
    M2C_UNK* var_s0;
    void* var_s1;

    if (arg0 == 0) {
        var_s0 = &D_003156C0;
        var_s1 = &D_003156C0 + 0xD4;
        do {
            if ((M2C_FIELD(var_s0, s32* , 0x10) != -1) && (strcmp(var_s1, arg1) == 0)) {
                M2C_FIELD(var_s0, s32* , 0xCC) = arg2;
            }
            var_s0 += 0x220;
            var_s1 += 0x220;
        } while ((s32) var_s0 < (s32) (&D_003156C0 + 0x1100));
    }
}
//@@ func_00169050 m2c
#include "m2c_macros.h"
extern M2C_UNK D_003156C0;

void func_00169050(s32 arg0, M2C_UNK arg1, s32 arg2) {
    s32 var_s1;
    s32* var_s0;
    void* var_s2;

    if (arg0 == 0) {
        var_s1 = 0;
        if (M2C_FIELD(&D_003156C0, s32* , 0x1980) > 0) {
            var_s0 = &D_003156C0 + 0x1588;
            var_s2 = &D_003156C0 + 0x1560;
            do {
                if (strcmp(var_s2, arg1) == 0) {
                    *var_s0 = arg2;
                }
                var_s1 += 1;
                var_s0 += 0x5C;
                var_s2 += 0x5C;
            } while (var_s1 < M2C_FIELD(&D_003156C0, s32* , 0x1980));
        }
    }
}
//@@ func_001690F0 m2c
#include "m2c_macros.h"
extern M2C_UNK D_003156C0;
extern s32 D_004FA030;

s32 func_001690F0(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s0;
    s32 temp_s1;
    s32 var_s1;
    s32 var_v0;
    u32 var_v0_2;
    void* temp_v0;
    void* temp_v0_2;
    void* temp_v1;

    var_v0 = *(D_004FA030 + 0x9E690 + (arg1 * 4));
    if (var_v0 == 0) {
        if (arg2 != -1) {
            var_s1 = func_00174268(&D_003156C0, arg2, D_004FA030) - 1;
            goto block_12;
        }
        temp_v1 = D_004FA030 + 0x31B0;
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
                temp_v0 = (var_s1 * 0x31B0) + D_004FA030;
                if ((M2C_FIELD(temp_v0, s32* , 0x20F4) == arg0) && (M2C_FIELD(temp_v0, s32* , 0x20C4) == -1)) {

                } else {
                    goto loop_7;
                }
            }
block_12:
            var_v0_2 = var_s1 - 1;
        }
        temp_s1 = (var_v0_2 >= 7U) ? 7 : var_s1;
        func_0013A7B8(D_004FA030, -1, arg0, temp_s1);
        temp_s0 = temp_s1 * 0x31B0;
        temp_v0_2 = D_004FA030 + temp_s0;
        M2C_FIELD(temp_v0_2, s32* , 0x20B4) = 5;
        M2C_FIELD(temp_v0_2, s32* , 0x20C0) = arg2;
        func_001FDE10(1, temp_s1 + 1);
        var_v0 = D_004FA030 + temp_s0;
    }
    return var_v0;
}
//@@ func_00169230 m2c
#include "m2c_macros.h"
extern M2C_UNK D_003156C0;
extern s32 D_004FA030;

void* func_00169230(s32 arg0) {
    u32 temp_a1;
    void* temp_s0;
    void* temp_s2;
    void* var_v0;

    temp_s2 = (arg0 * 0x220) + &D_003156C0;
    var_v0 = M2C_FIELD(temp_s2, void** , 0xB0);
    if (var_v0 == NULL) {
        temp_a1 = func_00174268(&D_003156C0, arg0) - 1;
        if (temp_a1 < 8U) {
            temp_s0 = *(D_004FA030 + 0x9E670 + (temp_a1 * 4));
            func_0013A7B8(D_004FA030, temp_a1, M2C_FIELD(temp_s0, s32* , 0x20F4), M2C_FIELD(temp_s0, s32* , 0x20F0));
            M2C_FIELD(temp_s0, s32* , 0x590) = 0;
            M2C_FIELD(temp_s2, void** , 0xB0) = temp_s0;
            M2C_FIELD(temp_s0, s32* , 0x20C0) = arg0;
            M2C_FIELD(M2C_FIELD(temp_s2, void** , 0xB0), s32* , 0x20B4) = 2;
            func_0016F058(&D_003156C0, arg0, M2C_FIELD(&D_003156C0, s32* , 0x2CF0));
            var_v0 = temp_s0;
        } else {
            var_v0 = NULL;
        }
    }
    return var_v0;
}
//@@ netObjDestroyCB m2c
#include "m2c_macros.h"
extern M2C_UNK D_003156C0;
extern s32 D_004F9CA4;
extern s32 D_004F9CAC;
extern s32 D_004F9D18;
extern void* D_004FA030;

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

    temp_v1 = netGetDmeTime(&D_003156C0);
    if (arg0 != 0x100) {
        if (arg1 == M2C_FIELD(&D_003156C0, s32* , 0x2F00)) {
            M2C_FIELD(&D_003156C0, s32* , 0x2F04) = 0;
            M2C_FIELD(&D_003156C0, s32* , 0x2F00) = -1;
        } else if (temp_v1 != NULL) {
            temp_a0 = M2C_FIELD(temp_v1, u8* , 0);
            if (temp_a0 == D_004F9CA4) {
                temp_s0 = M2C_FIELD(temp_v1, void** , 0x1C);
                if (M2C_FIELD(temp_s0, s32* , 4) != -1) {
                    var_a0 = D_004FA030;
                    if (M2C_FIELD(&D_003156C0, s32* , 0x2F04) != 0) {
                        var_a0 = D_004FA030;
                        if (func_001734B8(&D_003156C0) != 0) {
                            var_a2 = D_004FA030;
                            var_t1 = 0;
                            var_t0 = temp_s0 + 0x30;
                            var_a3 = temp_s0 + 0x10;
                            do {
                                temp_a1 = var_t1 * 4;
                                temp_v1_2 = M2C_FIELD(&D_003156C0, s32* , 0x2F04) + 0x40 + temp_a1;
                                *temp_v1_2 += *var_a3;
                                temp_a0_2 = M2C_FIELD(&D_003156C0, s32* , 0x2F04) + temp_a1;
                                *temp_a0_2 += *var_t0;
                                temp_a1_2 = M2C_FIELD(var_a2, void** , 0x20D8);
                                var_t1 += 1;
                                if (temp_a1_2 != NULL) {
                                    temp_a0_3 = M2C_FIELD(&D_003156C0, s32* , 0x2F04) + 0x20 + (M2C_FIELD(temp_a1_2, s32* , 4) * 4);
                                    *temp_a0_3 += M2C_FIELD((temp_a1_2 + (M2C_FIELD(temp_s0, s32* , 4) * 4)), f32* , 0x30);
                                    temp_a1_3 = M2C_FIELD(var_a2, void** , 0x20D8);
                                    temp_a0_4 = M2C_FIELD(&D_003156C0, s32* , 0x2F04) + 0x60 + (M2C_FIELD(temp_a1_3, s32* , 4) * 4);
                                    *temp_a0_4 += M2C_FIELD((temp_a1_3 + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x10);
                                }
                                var_a2 += 0x31B0;
                                var_t0 += 4;
                                var_a3 += 4;
                            } while (var_t1 < 8);
                            M2C_FIELD((M2C_FIELD(&D_003156C0, s32* , 0x2F04) + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x40) = 0;
                            *(M2C_FIELD(&D_003156C0, s32* , 0x2F04) + (M2C_FIELD(temp_s0, s32* , 4) * 4)) = 0;
                            M2C_FIELD((M2C_FIELD(&D_003156C0, s32* , 0x2F04) + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x60) = 0;
                            M2C_FIELD((M2C_FIELD(&D_003156C0, s32* , 0x2F04) + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x20) = 0;
                            M2C_FIELD((&D_003156C0 + (M2C_FIELD(temp_s0, s32* , 4) * 4)), s32* , 0x303C) = 0;
                            var_a0 = D_004FA030;
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
                    M2C_FIELD(((arg0 * 0x220) + &D_003156C0), s32* , 0x220) = 0;
                }
                if (M2C_FIELD(D_004FA030, s32* , 0x20D8) == temp_s0) {
                    M2C_FIELD(D_004FA030, s32* , 0x20D8) = 0;
                } else {
                    var_a0_2 = 1;
loop_23:
                    if (var_a0_2 < 8) {
                        temp_v0 = (var_a0_2 * 0x31B0) + D_004FA030;
                        var_a0_2 += 1;
                        if (M2C_FIELD(temp_v0, s32* , 0x20D8) == temp_s0) {
                            M2C_FIELD(temp_v0, s32* , 0x20D8) = 0;
                        } else {
                            goto loop_23;
                        }
                    }
                }
            } else if (temp_a0 == D_004F9CAC) {
                M2C_FIELD(&D_003156C0, void** , 0x3148) = (void* ) (&D_003156C0 + 0x3080);
            } else if ((temp_a0 == D_004F9D18) && (temp_s0_2 = M2C_FIELD(temp_v1, void** , 0x1C), (temp_s0_2 != NULL)) && (temp_a1_5 = M2C_FIELD(temp_s0_2, s32* , 0), (temp_a1_5 != 0))) {
                if ((u32) (M2C_FIELD(temp_a1_5, s32* , 0x20B4) - 4) < 2U) {
                    if (arg0 != *M2C_FIELD(&D_003156C0, s32** , 4)) {
                        func_0013EED0(D_004FA030, temp_a1_5);
                        func_001759D8(&D_003156C0, M2C_FIELD(temp_s0_2, s32* , 0));
                    }
                } else {
                    if (func_001734B8(&D_003156C0, temp_a1_5) != 0) {
                        temp_s0_3 = (arg0 * 0x220) + &D_003156C0;
                        temp_a1_6 = M2C_FIELD(temp_s0_3, void** , 0xB0);
                        if (temp_a1_6 != NULL) {
                            temp_a1_7 = M2C_FIELD(temp_a1_6, s32* , 0x20E0);
                            if (temp_a1_7 != -1) {
                                func_00181AA8(&D_003156C0 + 0x3234, temp_a1_7, 0);
                            }
                            if (M2C_FIELD(&D_003156C0, s32* , 0x3870) != 0) {
                                func_0011B308(&D_003156C0 + 0x386C, M2C_FIELD(temp_s0_3, void** , 0xB0));
                            }
                        }
                    }
                    temp_s0_4 = &D_003156C0 + 0x56C0;
                    func_00264A60(&sp80, M2C_FIELD(temp_s0_4, s32* , 0x2CF0), arg0);
                    if (M2C_FIELD(temp_s0_4, s32* , 0x1BB4) == 0xB) {
                        func_001A9240();
                    }
                    sprintf(sp, "%s has left the game.", (arg0 * 0x220) + (temp_s0_4 + 0x18));
                    func_0014EDA0(sp);
                    AddMessage__3Hudiii(D_004FA030 + 0x97B50, 0xF9, 2, 0);
                    func_0016F1C8(temp_s0_4, arg0);
                    if (M2C_FIELD(temp_s0_4, s32* , 0x3220) != 0) {
                        if (M2C_FIELD(M2C_FIELD(temp_s0_4, void** , 0x3148), u8* , 0x24) == 0) {
                            func_00174D78(temp_s0_4, 0, 0);
                        }
                    }
                }
            }
        }
    }
}
//@@ netWeaponCreateCB m2c
#include "m2c_macros.h"
extern M2C_UNK D_003156C0;
extern void* D_004FA030;

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
        temp_s2 = M2C_FIELD(netGetDmeTime(&D_003156C0), void** , 0x1C);
        M2C_FIELD(temp_s2, void** , 0) = NULL;
        if (M2C_FIELD(temp_s2, s16* , 0xA) != -1) {
            temp_v1 = M2C_FIELD(temp_s2, s8* , 0xC);
            temp_a0 = (u8) M2C_FIELD(temp_s2, s8* , 0xC);
            if (temp_v1 == 1) {
                var_s3 = M2C_FIELD(((arg0 * 0x220) + &D_003156C0), void** , 0xB0);
                goto block_9;
            }
            var_v0 = temp_a0 << 0x18;
            if (temp_v1 == -2) {
                temp_a1 = M2C_FIELD(D_004FA030, void** , 0x9E690);
                var_s3 = temp_a1;
                if (temp_a1 == NULL) {
                    var_v0 = temp_a0 << 0x18;
                    goto block_7;
                }
                goto block_9;
            }
block_7:
            if ((var_v0 >> 0x18) == -3) {
                temp_a1_2 = M2C_FIELD(D_004FA030, void** , 0x9E694);
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
                var_s4 = M2C_FIELD(((M2C_FIELD(temp_s2, s16* , 0x10) * 0x220) + &D_003156C0), void** , 0xB0);
            } else if (temp_v1_2 == -2) {
                var_s4 = M2C_FIELD(D_004FA030, void** , 0x9E690);
            } else {
                var_s4 = NULL;
                if (temp_v1_2 == -3) {
                    var_s4 = M2C_FIELD(D_004FA030, void** , 0x9E694);
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
                    func_001735E8(&D_003156C0, temp_s2, var_s3);
                } else {
                    goto block_23;
                }
            } else {
                var_v0_2 = temp_a0_2 << 0x10;
block_23:
                var_v0_3 = temp_a0_2 << 0x10;
                if (((var_v0_2 >> 0x10) == 0x180) && (var_v0_3 = temp_a0_2 << 0x10, (M2C_FIELD(temp_s2, s8* , 6) == 1))) {
                    func_00159C98(var_s3 + 0x21B0, var_s3);
                } else {
                    var_v0_4 = temp_a0_2 << 0x10;
                    if (((var_v0_3 >> 0x10) == 0x1E0) && (var_v0_4 = temp_a0_2 << 0x10, (M2C_FIELD(temp_s2, s8* , 6) == 1))) {
                        FireSpecial__8LauncherP7Vehicle(var_s3 + 0x21B0, var_s3);
                    } else {
                        if (((var_v0_4 >> 0x10) == 0x20) && (M2C_FIELD(temp_s2, s8* , 6) == 0x11)) {
                            terminateChargerSpecialChargeUpSound__13LauncherSound(var_s3 + 0x2AD0);
                            M2C_FIELD(var_s3, s32* , 0x2508) = (s32) M2C_FIELD(temp_s2, u8* , 4);
                        }
                        sp10 = M2C_FIELD(temp_s2, f32* , 0x2C);
                        sp14 = M2C_FIELD(temp_s2, f32* , 0x30);
                        sp1C = 0;
                        sp18 = M2C_FIELD(temp_s2, f32* , 0x34);
                        M2C_FIELD(&D_003156C0, void** , 0x2E94) = NULL;
                        if (var_s3 != NULL) {
                            M2C_FIELD((var_s3 + (M2C_FIELD(temp_s2, s8* , 6) * 4)), s32* , 0x22AC) = (s32) M2C_FIELD(temp_s2, s8* , 7);
                            temp_v1_4 = M2C_FIELD(temp_s2, s8* , 6);
                            switch (temp_v1_4) {    /* irregular */
                            case 4:
                                if (M2C_FIELD(temp_s2, u8* , 4) != 0x20) {
                                    var_s0 = var_s3 + 0x21B0;
                                    if (M2C_FIELD(&D_003156C0, s32* , 0x1BB4) == 0xB) {
                                        func_0019FB70(var_s3 + 0x2AD0, var_s3);
                                    }
                                } else {
                                    temp_v1_5 = var_s3 + 0x21B0;
                                    M2C_FIELD(var_s3, s32* , 0x2420) = 1;
                                    var_s0 = temp_v1_5;
                                    StartAnimation__8LauncherP7Vehicleif(0x3F800000, temp_v1_5, var_s3, 4);
                                    if (M2C_FIELD(&D_003156C0, s32* , 0x1BB4) == 0xB) {
                                        func_0019FB28(var_s3 + 0x2AD0, var_s3);
                                    }
                                }
                                ReverseAnimation__8LauncherP7Vehicleifi(0x40000000, var_s0, var_s3, 4, 0);
                                break;
                            case 28:
                                if (M2C_FIELD(temp_s2, u8* , 4) == 0x20) {
                                    M2C_FIELD(var_s3, s32* , 0x21B4) = 1;
                                }
                                M2C_FIELD(var_s3, s32* , 0x27B4) = timerGetCurTics__Fv(4);
                                M2C_FIELD(var_s3, s32* , 0x27B8) = 0;
                                break;
                            case 18:
                                M2C_FIELD(var_s3, s32* , 0x21B4) = 0;
                                M2C_FIELD(var_s3, s32* , 0x27B8) = 0;
                                M2C_FIELD(var_s3, s32* , 0x27B4) = timerGetCurTics__Fv(4);
                                break;
                            }
                            if (M2C_FIELD(temp_s2, s8* , 6) == 0xC) {
                                if (M2C_FIELD(var_s3, s32* , 0x23F0) == 0) {
                                    temp_v1_6 = M2C_FIELD(var_s3, u32*** , 0x2404);
                                    M2C_FIELD(var_s3, s32* , 0x23F4) = -1;
                                    if (temp_v1_6 != NULL) {
                                        func_001FBCF8(&sp20, (u32) **temp_v1_6 >> 0x12, 0, 0);
                                        animationStart__FR11_animHandleb(&sp20, 1);
                                    }
                                }
                                if (M2C_FIELD(&D_003156C0, s32* , 0x1BB4) == 0xB) {
                                    func_001A01F8(var_s3 + 0x2AD0, var_s3 + 0x23E0);
                                }
                                M2C_FIELD(var_s3, s32* , 0x23F0) = 1;
                                M2C_FIELD(var_s3, s32* , 0x23F4) = (s32) (M2C_FIELD(var_s3, s32* , 0x23F4) + 1);
                            }
                            if (M2C_FIELD(temp_s2, s8* , 7) == 0x7F) {
                                if (var_s4 != NULL) {
                                    func_00133198(D_004FA030 + 0x96260, var_s3, var_s4, 1);
                                }
                            } else {
                                func_001EDDF0(D_004FA030 + 0x6C310, M2C_FIELD(temp_s2, s8* , 6), var_s3, var_s4);
                            }
                            if (M2C_FIELD(temp_s2, s8* , 6) == 0x1C) {
                                temp_s0 = var_s3 + 0x2E8C;
                                M2C_FIELD(var_s3, s32* , 0x21B4) = 0;
                                M2C_FIELD(var_s3, s32* , 0x2244) = 0;
                                temp_s1 = var_s3 + 0x21B0;
                                animationPause__FR11_animHandle(temp_s0);
                                animationSetToFrame__FR11_animHandlef(0, temp_s0);
                                animationSetToFrame__FR11_animHandlef(0, var_s3 + ((GetWeaponMapping__8Launcheri(temp_s1, 1) * 0xC) + 0x2D9C));
                                StartAnimation__8LauncherP7Vehicleif(0x3F800000, temp_s1, var_s3, 1);
                            }
                            if (M2C_FIELD(&D_003156C0, void** , 0x2E94) != NULL) {
                                M2C_FIELD(temp_s2, void** , 0) = (void* ) M2C_FIELD(&D_003156C0, void** , 0x2E94);
                                M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 0x2E94), s32* , 0x50) = arg1;
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
//@@ netWeaponUpdateCB m2c
#include "m2c_macros.h"
extern M2C_UNK D_003156C0;
extern void* D_004FA030;

void netWeaponUpdateCB(s32 arg0) {
    s32 var_a2;
    s32 var_v0;
    s8 temp_a2;
    s8 temp_v1;
    u8 temp_a3;
    void* temp_a0;
    void* temp_a1;

    if (arg0 != 0x100) {
        temp_a1 = M2C_FIELD(netGetDmeTime(&D_003156C0), void** , 0x1C);
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
                        func_001F02A8(temp_a0, temp_a1);
                    }
                }
            }
        } else {
            temp_v1 = M2C_FIELD(temp_a1, s8* , 0xC);
            temp_a3 = (u8) M2C_FIELD(temp_a1, s8* , 0xC);
            if (temp_v1 == temp_a2) {
                var_a2 = M2C_FIELD(((arg0 * 0x220) + &D_003156C0), s32* , 0xB0);
                goto block_13;
            }
            var_v0 = temp_a3 << 0x18;
            if ((temp_v1 != -2) || (var_a2 = M2C_FIELD(D_004FA030, s32* , 0x9E690), var_v0 = temp_a3 << 0x18, (var_a2 == 0))) {
                if ((var_v0 >> 0x18) == -3) {
                    var_a2 = M2C_FIELD(D_004FA030, s32* , 0x9E694);
                    if (var_a2 != 0) {
                        goto block_13;
                    }
                }
            } else {
block_13:
                func_001735E8(&D_003156C0, temp_a1, var_a2, temp_a3);
            }
        }
    }
}
//@@ netWeaponDestroyCB m2c
#include "m2c_macros.h"
extern M2C_UNK D_003156C0;
extern void* D_004FA030;

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
        temp_s1 = M2C_FIELD(netGetDmeTime(&D_003156C0), void** , 0x1C);
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
                            func_001F02A8(temp_a0, temp_s1);
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
                var_a2 = M2C_FIELD(((arg0 * 0x220) + &D_003156C0), s32* , 0xB0);
                goto block_14;
            }
            var_v0 = temp_a3 << 0x18;
            if (temp_v1 == -2) {
                var_a2 = M2C_FIELD(D_004FA030, s32* , 0x9E690);
                if (var_a2 == 0) {
                    var_v0 = temp_a3 << 0x18;
                    goto block_12;
                }
                goto block_15;
            }
block_12:
            if ((var_v0 >> 0x18) == -3) {
                var_a2 = M2C_FIELD(D_004FA030, s32* , 0x9E694);
                if (var_a2 != 0) {
block_14:
block_15:
                    func_001735E8(&D_003156C0, temp_s1, var_a2, temp_a3);
                }
            }
        }
    }
}
//@@ netGameDataUpdateCB m2c
#include "m2c_macros.h"
extern M2C_UNK D_003156C0;
extern M2C_UNK D_003188F4;
extern M2C_UNK D_00318F2C;
extern s32 D_004F9CBC;
extern s32 D_004F9CC0;
extern s32 D_004F9CC8;

void netGameDataUpdateCB(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;

    if (arg0 != 0x100) {
        temp_v0 = D_004F9CBC;
        if ((M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 0x3148), s32* , 0) & 1) && ((u32) (M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 4), s32* , 0x204) - 9) < 2U)) {
            func_00173570(&D_003156C0, 0xB);
        }
        temp_v0_2 = D_004F9CC0;
        if (arg2 == temp_v0) {
            func_0011BD50(&D_00318F2C);
        }
        temp_v0_3 = D_004F9CC8;
        if (arg2 == temp_v0_2) {
            func_001814D0(&D_003188F4);
        }
        if (arg2 == temp_v0_3) {
            temp_a1 = M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 4), s32* , 0);
            if (M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 0x3148), s8* , 0x1A) == temp_a1) {
                func_001A9278(M2C_FIELD(&D_003156C0, void** , 0x3148), temp_a1);
            }
        }
        func_00176580(&D_003156C0);
    }
}
//@@ netPadFlagsUpdateCB m2c
#include "m2c_macros.h"
extern M2C_UNK D_003156C0;

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

    temp_a1 = netGetDmeTime(&D_003156C0);
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
//@@ func_0016C480 m2c
#include "m2c_macros.h"
extern s32 D_004F9EB0;

void func_0016C480(s32 arg0, s32 arg1, s32 arg2) {
    D_004F9EB0 = arg2;
}
//@@ func_0016C488 m2c
#include "m2c_macros.h"
extern M2C_UNK D_003156C0;
extern s32 D_004FA030;

void func_0016C488(void) {
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_t0;
    s32 var_a2;
    void* var_v0;

    temp_a1 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 4), void** , 0xA0), s32* , 0x210C);
    temp_t0 = temp_a1 * 4;
    temp_a2 = *(D_004FA030 + 0x27790 + temp_t0);
    if ((u32) (temp_a2 - 1) < 4U) {
        SetCameraPOV__6Camerai10_cameraPOV(D_004FA030 + 0x27780, temp_a1, temp_a2, D_004FA030);
    } else {
        temp_a0 = D_004FA030 + 0x27780;
        SetCameraPOV__6Camerai10_cameraPOV(temp_a0, temp_a1, *(temp_a0 + temp_t0), D_004FA030);
    }
    var_a2 = M2C_FIELD((D_004FA030 + 0x27780), s32* , 0x43E0);
    if (var_a2 > 0) {
        var_v0 = D_004FA030 + 0x2B9E0;
        do {
            M2C_FIELD(var_v0, s32* , 0) = 0;
            var_a2 -= 1;
            M2C_FIELD(var_v0, s32* , 4) = 0;
            M2C_FIELD(var_v0, s32* , 8) = 0;
            var_v0 += 0x10;
        } while (var_a2 != 0);
    }
    M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 4), s32* , 0x208) = 0;
    M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 4), s32* , 0x20C) = 0;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 4), void** , 0xA0), s32* , 0x590) = 1;
    func_001D6F78(M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 4), void** , 0xA0), 1, var_a2);
}
//@@ func_0016C590 m2c
#include "m2c_macros.h"
extern M2C_UNK D_002B8A00;
extern M2C_UNK D_003156C0;
extern M2C_UNK D_004E6500;
extern M2C_UNK D_004E6A00;
extern void* D_004FA030;
static M2C_UNK D_004E6BB0;                          /* unable to generate initializer: unknown type; const */

void func_0016C590(s32 arg0, s32 arg1) {
    u8 sp[0x10];
    s32 temp_s0;

    temp_s0 = func_001733F8(&D_003156C0);
    printf("In HostChangeCallback...\n");
    switch (temp_s0) {                              /* irregular */
    case 1:
        if (func_00176B10(&D_003156C0, 1) <= 0) {
            printf(&D_004E6A00, &D_003156C0);
            if (func_00176CC8(&D_003156C0) != 0) {
                printf(&D_004E6BB0);
                M2C_FIELD(&D_003156C0, s32* , 0x1BB0) = temp_s0;
                func_00174988(&D_003156C0, -1);
            }
        }
        if ((arg1 == *M2C_FIELD(&D_003156C0, s32** , 4)) && (M2C_FIELD(D_004FA030, s32* , 0x9FD9C) != 0) && (M2C_FIELD(&D_003156C0, s32* , 0x3230) == 0)) {
            func_00171F88(&D_003156C0, &D_003156C0);
        }
        break;
    case 2:
        func_00266DE0(&D_003156C0 + 0x307C, M2C_FIELD(&D_003156C0, s32* , 0x2CF0));
        printf(&D_004E6500);
        printf(">>>>> 6 Setting ConnectionSessionMaster = %d\n\0BASCUS-97196\0\0\0 !\"#$%&'()*+,-.0123456789:;<=>?ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_abcdefghijklmnopqrstuvwxyz{}\0\00123456789\0\0 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\0 .0123456789", M2C_FIELD(&D_003156C0, M2C_UNK** , 0x307C));
        printf(&D_004E6500);
        break;
    }
    if (M2C_FIELD(&D_003156C0, s32* , 0x2E90) == 0) {
        if (M2C_FIELD(&D_003156C0, s32* , 0x1BB4) > 0) {
            if (arg1 == netGetMyClientIndex(&D_003156C0, 0)) {
                M2C_FIELD(&D_002B8A00, s32* , 0xE0) = 1;
                func_00266EB0(sp, M2C_FIELD(&D_003156C0, s32* , 0x2CF0));
                M2C_FIELD(&D_002B8A00, s32* , 0xEC) = (s32) subroutine_arg0;
            }
        }
    }
    M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 0x3148), s8* , 0x24) = func_00176B10(&D_003156C0, 0);
}
//@@ func_0016C738 m2c
#include "m2c_macros.h"
void func_0016C738(void* arg0) {
    M2C_FIELD(arg0, s8* , 0x14) = 0;
    M2C_FIELD(arg0, s8* , 4) = 0;
}
//@@ func_0016C748 m2c
#include "m2c_macros.h"
extern M2C_UNK D_004E6D30;
extern M2C_UNK D_004F9D38;
extern s32 D_004F9D9C;

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
    D_004F9D9C = timerGetCurTics__Fv();
    func_0016E7D0(0);
    func_00161598(&D_004F9D38, "cdrom0:\\NET\\NETCNF.IRX;1", 0x3A, &D_004E6D30);
}
//@@ func_0016C7D0 m2c
#include "m2c_macros.h"
extern s32 D_00313F40;
extern M2C_UNK D_00313F70;
extern M2C_UNK D_00314380;
extern M2C_UNK D_004F9D40;

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

    printf("\nNETINIT: Reading the Network Configuration Files\n");
    M2C_FIELD(arg0, s32* , 0x1BC4) = 0;
    func_00161508();
    temp_v0 = func_00258910(&D_004F9D40, &D_00313F40);
    if (temp_v0 > 0) {
        M2C_FIELD(arg0, s32** , 0x43D0) = &D_00313F40;
    }
    var_s1 = 0;
    M2C_FIELD(arg0, s32* , 0x4278) = func_00258850(&D_004F9D40, 0);
    M2C_FIELD(arg0, s32* , 0x427C) = func_00258850(&D_004F9D40, 1);
    M2C_FIELD(arg0, s32* , 0x4280) = func_00258850(&D_004F9D40, 2);
    M2C_FIELD(arg0, s32* , 0xB788) = 0;
    M2C_FIELD(arg0, s32* , 0xB788) = func_00258A50(&D_00313F40);
    var_a1 = 0;
    if (D_00313F40 > 0) {
        do {
            temp_v0_2 = func_002589D0(&D_00313F40, var_a1);
            if ((temp_v0_2 != NULL) && (*temp_v0_2 != 0) && (var_s1 < 6)) {
                var_v1 = var_s1 + 1;
                if (func_00258B98(&D_004F9D40, temp_v0_2 + 8, &D_00314380) == 0) {
                    var_a2 = &D_00314380;
                    var_v0 = (var_s1 * 0x1340) + arg0 + 0x4400;
                    do {
                        M2C_FIELD(var_v0, s128* , 0) = (s128) M2C_FIELD(var_a2, s128* , 0);
                        M2C_FIELD(var_v0, s128* , 0x10) = (s128) M2C_FIELD(var_a2, s128* , 0x10);
                        var_a2 += 0x20;
                        var_v0 += 0x20;
                    } while (var_a2 != (&D_00314380 + 0x1340));
                }
            } else {
                memset(arg0 + ((var_s1 * 0x1340) + 0x4400), 0, 0x1340);
                var_v1 = var_s1 + 1;
            }
            var_s1 = var_v1;
            var_a1 = var_s1;
        } while (var_s1 < D_00313F40);
    }
    func_002587F0();
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
        printf("NETINIT: Configuration Count = %d\n", M2C_FIELD(arg0, s32* , 0x4278));
        printf("NETINIT: Interface Count = %d\n", M2C_FIELD(arg0, s32* , 0x427C));
        printf("NETINIT: Device Count = %d\n", M2C_FIELD(arg0, s32* , 0x4280));
        printf("NETINIT: Memory Card can hold %d Configurations\n", M2C_FIELD(M2C_FIELD(arg0, s32** , 0x43D0), s32* , 0));
        printf("NETINIT: Default Configuration = %d\n", M2C_FIELD(M2C_FIELD(arg0, s32** , 0x43D0), s32* , 4));
        printf("NETINIT: Listing all configurations...\n");
        if (M2C_FIELD(M2C_FIELD(arg0, s32** , 0x43D0), s32* , 0) > 0) {
            var_s1_2 = &D_00313F70;
            do {
                printf("NETINIT: Configuration #%d\n", var_s0);
                var_s0 += 1;
                func_00161588(var_s1_2);
                var_s1_2 += 0x68;
            } while (var_s0 < M2C_FIELD(M2C_FIELD(arg0, s32** , 0x43D0), s32* , 0));
        }
        printf("...Done Listing Configurations.\n\n");
    }
}
//@@ func_0016CA88 m2c
#include "m2c_macros.h"
extern M2C_UNK D_003156C0;
extern M2C_UNK D_004F9D48;

s32 func_0016CA88(void* arg0, s32 arg1) {
    s32* temp_v0;

    M2C_FIELD(&D_003156C0, s32* , 0x2DFC) = 8;
    M2C_FIELD(&D_003156C0, s32* , 0x2DF8) = 8;
    M2C_FIELD(arg0, s32** , 0xB780) = NULL;
    temp_v0 = func_002589D0(M2C_FIELD(arg0, s32* , 0x43D0));
    M2C_FIELD(arg0, s32** , 0xB780) = temp_v0;
    if (*temp_v0 != 0) {
        M2C_FIELD(arg0, void** , 0xB784) = (void* ) (arg0 + ((arg1 * 0x1340) + 0x4400));
        printf("NETINIT: Evaluating the Network Configuration %d...\n", arg1);
        if (M2C_FIELD(arg0, s32* , 0x4278) > 0) {
            if (func_00298010(M2C_FIELD(arg0, void** , 0xB784) + 0xE00, &D_004F9D48, 3) == 0) {
                M2C_FIELD(arg0, s32* , 0x4260) = 0;
                M2C_FIELD(arg0, s32* , 0x425C) = 1;
                printf("    Using the Sony Duel Network Adapter\n");
            } else {
                M2C_FIELD(arg0, s32* , 0x425C) = 0;
                M2C_FIELD(arg0, s32* , 0x4260) = 1;
                printf("    Using a USB Network Adapter\n");
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
//@@ func_0016CB90 m2c
#include "m2c_macros.h"
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

            } while (func_001A9590() != 0);
            var_v0 = 0;
            if (M2C_FIELD(arg0, s32* , 0x1BB8) <= 0) {
                printf("ERROR: No Config File on the Mem Card - cannot play a network game!!!\n");
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
            return func_0016CA88(arg0, M2C_FIELD(arg0, s32* , 0x4284) + 1);
        }
        goto block_11;
    }
    var_v0_2 = arg1 < 0x14;
block_11:
    var_v0 = var_a1;
    if (var_v0_2 == 0) {
        temp_v1_2 = M2C_FIELD(arg0, s32* , 0x1BB8);
        if (temp_v1_2 == 2) {
            return func_0016CD88(arg0, arg1);
        }
        if ((arg1 < 0x15) || (var_v0 = -1, ((temp_v1_2 < 2) == 0))) {
            var_v0_3 = arg1 < 0x83;
            if (M2C_FIELD(arg0, s32* , 0x1BB8) == 3) {
                if ((u32) (arg1 - 0x82) < 0xAU) {
                    var_a1 = func_0016D238(arg0, arg1);
                }
                var_a1 = ((arg1 ^ 0x8C) == 0) ? 0x3E7 : var_a1;
                if (arg1 == 0x8D) {
                    var_a1 = func_0016D3B0(arg0, var_a1);
                }
                var_v0_3 = arg1 < 0x83;
            }
            if ((var_v0_3 != 0) || (var_v0 = -1, ((M2C_FIELD(arg0, s32* , 0x1BB8) < 3) == 0))) {
                var_v0_4 = arg1 < 0x97;
                if (M2C_FIELD(arg0, s32* , 0x1BB8) == 4) {
                    var_v0_4 = arg1 < 0x97;
                    if ((u32) (arg1 - 0x96) < 0x1EU) {
                        var_a1 = func_0016D4F8(arg0, arg1);
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
//@@ func_0016CD88 m2c
#include "m2c_macros.h"
extern M2C_UNK D_003156C0;
extern M2C_UNK D_004F9D38;
extern M2C_UNK D_004F9D50;

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
        var_s0 = func_00161598(&D_004F9D38, "cdrom0:\\NET\\INET.IRX;1", 0, NULL);
    }
    if (arg1 == 0x1E) {
        var_s0 = (M2C_FIELD(arg0, s32* , 0x4274) != 0) ? 0x3E7 : var_s0;
    }
    if (arg1 == 0x27) {
        var_s0 = func_00161598(&D_004F9D38, "cdrom0:\\NET\\INETCTL.IRX;1", 9, "-no_auto");
    }
    temp_a0 = M2C_FIELD(M2C_FIELD(arg0, void** , 0xB780), s32* , 4);
    if (temp_a0 != 2) {
        if (temp_a0 < 3) {
            if (temp_a0 != 1) {
                M2C_FIELD(arg0, s32* , 0x1BBC) = 0;
                goto block_55;
            }
            M2C_FIELD(&D_003156C0, s32* , 0x2DFC) = 2;
            M2C_FIELD(&D_003156C0, s32* , 0x4264) = temp_a0;
            M2C_FIELD(&D_003156C0, s32* , 0x2DF8) = 2;
            if (arg1 == 0x28) {
                var_s0 = (M2C_FIELD(arg0, s32* , 0x4274) != 0) ? 0x3E7 : var_s0;
            }
            if (arg1 == 0x31) {
                var_s0 = func_00161598(&D_004F9D38, "cdrom0:\\NET\\PPP.IRX;1", 0, NULL);
            }
            if (M2C_FIELD(arg0, s32* , 0x425C) != 0) {
                if (arg1 == 0x3C) {
                    var_s0 = (M2C_FIELD(arg0, s32* , 0x4274) != 0) ? 0x3E7 : var_s0;
                }
                if (arg1 == 0x45) {
                    var_s0 = func_00161598(&D_004F9D38, "cdrom0:\\NET\\DEV9.IRX;1", 0, NULL);
                }
                if (arg1 == 0x5A) {
                    var_s0 = (M2C_FIELD(arg0, s32* , 0x4274) != 0) ? 0x3E7 : var_s0;
                }
                if (arg1 == 0x63) {
                    var_s0 = func_00161598(&D_004F9D38, "cdrom0:\\NET\\SPDUART.IRX;1", 0x20, "dial=cdrom0:\\NET\\DIAL_SPD.CNF;1");
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
        var_s0 = func_00161598(&D_004F9D38, "cdrom0:\\NET\\PPP.IRX;1", 0, NULL);
    }
    if (arg1 == 0x32) {
        var_s0 = (M2C_FIELD(arg0, s32* , 0x4274) != 0) ? 0x3E7 : var_s0;
    }
    if (arg1 == 0x3B) {
        var_s0 = func_00161598(&D_004F9D38, "cdrom0:\\NET\\PPPOE.IRX;1", 0, NULL);
    }
block_22:
    if (M2C_FIELD(arg0, s32* , 0x425C) != 0) {
        if (arg1 == 0x3C) {
            var_s0 = (M2C_FIELD(arg0, s32* , 0x4274) != 0) ? 0x3E7 : var_s0;
        }
        if (arg1 == 0x45) {
            var_s0 = func_00161598(&D_004F9D38, "cdrom0:\\NET\\DEV9.IRX;1", 0, NULL);
        }
        if (arg1 == 0x46) {
            var_s0 = (M2C_FIELD(arg0, s32* , 0x4274) != 0) ? 0x3E7 : var_s0;
        }
        if (arg1 == 0x4F) {
            var_s0 = func_00161598(&D_004F9D38, "cdrom0:\\NET\\SMAP.IRX;1", 0, NULL);
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
            var_s0 = func_00161598(&D_004F9D38, var_a1, var_a2, var_a3);
        }
    }
block_57:
    if (arg1 == 0x6E) {
        var_s0 = (M2C_FIELD(arg0, s32* , 0x4274) != 0) ? 0x3E7 : var_s0;
    }
    if (arg1 == 0x72) {
        var_s0 = func_00161598(&D_004F9D38, "cdrom0:\\NET\\MSIFRPC.IRX;1", 0, NULL);
    }
    if (arg1 == 0x73) {
        var_s0 = (M2C_FIELD(arg0, s32* , 0x4274) != 0) ? 0x3E7 : var_s0;
    }
    if (arg1 == 0x77) {
        var_s0 = func_00161598(&D_004F9D38, "cdrom0:\\NET\\LIBNETB.IRX;1", 8, &D_004F9D50);
        func_00290058(0);
    }
    if (arg1 == 0x78) {
        var_s0 = (M2C_FIELD(arg0, s32* , 0x4274) != 0) ? 0x3E7 : var_s0;
    }
    if (arg1 == 0x7C) {
        var_s0 = func_00161548();
    }
    if (arg1 == 0x7D) {
        M2C_FIELD(arg0, s32* , 0x1BB8) = 3;
    }
    return var_s0;
}
//@@ func_0016D238 m2c
#include "m2c_macros.h"
extern M2C_UNK D_00319980;
extern s32 D_00319984;
extern s32 D_004F9D60;

s32 func_0016D238(void* arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_s1;
    s32 var_v0;
    void* temp_v1;

    var_s1 = ((arg1 ^ 0x82) != 0) ? 0 : 0x3E7;
    if (arg1 == 0x85) {
        var_s1 = func_0016D338();
    }
    if (arg1 == 0x87) {
        var_s1 = func_00258D98(M2C_FIELD(arg0, s32* , 0xB784));
        D_00319984 = var_s1;
        printf("NETINIT: ezNetCtlSetProperties returned %d\n", var_s1);
    }
    var_v0 = var_s1;
    if (arg1 == 0x89) {
        temp_v0 = func_00259098(0);
        printf("NETINIT: ezNetCtlUpInterface returned %d\n", temp_v0);
        if (temp_v0 >= 0) {
            func_00258F80(&D_00319980);
            temp_v1 = &D_00319980 - 0x42C0;
            printf("(ID=%d:%d) state %d, link %d, Message:[%s]\n", M2C_FIELD(temp_v1, s32* , 0x42C4), M2C_FIELD(temp_v1, s32* , 0x42C0), M2C_FIELD(temp_v1, s32* , 0x42CC));
        }
        M2C_FIELD(arg0, s32* , 0x4290) = 0;
        M2C_FIELD(arg0, s32* , 0x428C) = 0;
        D_004F9D60 = timerGetCurTics__Fv();
        var_v0 = temp_v0;
    }
    return var_v0;
}
//@@ func_0016D338 m2c
#include "m2c_macros.h"
extern s32 D_00319984;

s32 func_0016D338(void* arg0) {
    s32 temp_s1;

    temp_s1 = func_00259110(0);
    printf("NETINIT: Taking down the Network Interface...\n");
    printf("NETINIT: ezNetCtlDownInterface returned %d\n", temp_s1);
    M2C_FIELD(arg0, s32* , 0x1BB8) = 3;
    D_00319984 = -1;
    M2C_FIELD(arg0, s32* , 0x4290) = 0;
    M2C_FIELD(arg0, s32* , 0x4268) = 0;
    M2C_FIELD(arg0, s32* , 0x426C) = 0;
    M2C_FIELD(arg0, s32* , 0x428C) = 0;
    return temp_s1;
}
//@@ func_0016D3B0 m2c
#include "m2c_macros.h"
extern M2C_UNK D_00319980;
extern s32 D_004F9D58;
extern s32 D_004F9D5C;
extern s32 D_004F9D60;

s32 func_0016D3B0(void* arg0) {
    s32 temp_a0;
    s32 temp_a3;
    s32 temp_s3;
    s32 temp_v0;
    s32 var_v0;
    void* temp_s1;

    temp_s1 = &D_00319980 - 0x42C0;
    temp_s3 = func_00258F80(&D_00319980);
    temp_a0 = timerGetCurTics__Fv();
    if ((M2C_FIELD(temp_s1, s32* , 0x42CC) != D_004F9D58) || (M2C_FIELD(temp_s1, s32* , 0x42C8) != D_004F9D5C)) {
        temp_v0 = timerGetCurTics__Fv(temp_a0);
        temp_a3 = M2C_FIELD(temp_s1, s32* , 0x42CC);
        D_004F9D5C = M2C_FIELD(temp_s1, s32* , 0x42C8);
        D_004F9D60 = temp_v0;
        D_004F9D58 = temp_a3;
        strncpy(arg0 + 0x1BC8, &D_00319980 + 0x10, 0x100, temp_a3);
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
    strncpy(arg0 + 0x1BC8, &D_00319980 + 0x10, 0x100);
    var_v0 = -1;
    M2C_FIELD(arg0, s32* , 0x1BC4) = 6;
    return var_v0;
}
//@@ func_0016D4F8 m2c
#include "m2c_macros.h"
extern M2C_UNK D_002B8A00;
extern M2C_UNK D_002C1690;

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
        var_s2 = netInitDme(arg0);
        if (var_s2 <= 0) {
            M2C_FIELD(arg0, s32* , 0x1BBC) = 0;
            return -1;
        }
        func_00265A50(0x4000, 0x4000);
        temp_s0 = arg0 + 0x1A94;
        func_002666A8(temp_s0);
        printf("Local IP Address: [%s]\n", temp_s0);
        if (arg1 == 0xA0) {
        case 0xA0:
            var_s2 = (M2C_FIELD(arg0, s32* , 0x4274) != 0) ? 0x3E7 : var_s2;
        }
        if (arg1 == 0xA9) {
        case 0xA9:
            var_s2 = -1;
            if (func_001653D8(&D_002C1690) != 0) {
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
            if (func_0010A210(&D_002B8A00) == 0) {
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
//@@ func_0016D690 m2c
#include "m2c_macros.h"
extern M2C_UNK D_003156C0;
extern M2C_UNK D_00319980;
extern s32 D_004F9D58;
extern s32 D_004F9D5C;
extern s32 D_004F9D9C;

s32 func_0016D690(void* arg0) {
    s32 temp_v1;
    s32 var_v0;

    timerGetCurTics__Fv();
    if (0x44100000 >= 0x3E9) {
        func_00258F80(&D_00319980);
        D_004F9D9C = timerGetCurTics__Fv();
    }
    if ((M2C_FIELD(&D_003156C0, s32* , 0x42CC) != D_004F9D58) || (M2C_FIELD(&D_003156C0, s32* , 0x42C8) != D_004F9D5C)) {
        printf("(ID=%d:%d) state %d -> %d, link %d, Message:[%s]\n", M2C_FIELD(&D_003156C0, s32* , 0x42C4), M2C_FIELD(&D_003156C0, s32* , 0x42C0), D_004F9D58);
        D_004F9D5C = M2C_FIELD(&D_003156C0, s32* , 0x42C8);
        D_004F9D58 = M2C_FIELD(&D_003156C0, s32* , 0x42CC);
    }
    temp_v1 = M2C_FIELD(arg0, s32* , 0x4264);
    if (temp_v1 != 0) {
        var_v0 = 0;
        if (M2C_FIELD(&D_003156C0, s32* , 0x42CC) == 5) {
            strncpy(arg0 + 0x1BC8, &D_003156C0 + 0x42D0, 0x100);
            M2C_FIELD(arg0, s32* , 0x1BC4) = (s32) M2C_FIELD(&D_003156C0, s32* , 0x42CC);
            return -1;
        }
        /* Duplicate return node #9. Try simplifying control flow for better match */
        return var_v0;
    }
    var_v0 = (temp_v1 >= M2C_FIELD(&D_003156C0, s32* , 0x42C8)) ? -1 : M2C_FIELD(&D_003156C0, s32* , 0x42C8);
    return var_v0;
}
//@@ func_0016D800 m2c
#include "m2c_macros.h"
s32 func_0016D800(void* arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32* , 0x43D0);
    if (temp_v1 == 0) {
        return 0;
    }
    return (arg1 * 0x68) + temp_v1 + 0x38;
}
//@@ netInitDme m2c
#include "m2c_macros.h"
extern s32 D_00319924;
extern u8 D_004E72A0;
extern s32 D_004F9CA0;
extern s32 D_004F9CA4;
extern s32 D_004F9CA8;
extern s32 D_004F9CAC;
extern s32 D_004F9CB0;
extern s32 D_004F9CB4;
extern M2C_UNK D_004F9CB8;
extern M2C_UNK D_004F9CBC;
extern M2C_UNK D_004F9CC0;
extern M2C_UNK D_004F9CC4;
extern M2C_UNK D_004F9CC8;
extern M2C_UNK D_004F9CCC;
extern M2C_UNK D_004F9CD0;
extern M2C_UNK D_004F9CD4;
extern s32 D_004F9D18;
extern s32 D_004F9D24;
extern s32 D_004F9D80;
extern s32 D_004F9D88;
extern s32 D_004F9D90;
extern s32 D_004F9D94;
extern s32 D_004F9D98;
extern M2C_UNK func_0016C590;
extern M2C_UNK netFodderUpdateCB;
extern M2C_UNK netGameDataUpdateCB;
extern M2C_UNK netMsgChatHandler;
extern M2C_UNK netMsgGameEventHandler;
extern M2C_UNK netMsgPlayerInfoHandler;
extern M2C_UNK netMsgRosterHandler;
extern M2C_UNK netMsgSessionHandler;
extern M2C_UNK netMsgWorldEventHandler;
extern M2C_UNK netObjCreateCB;
extern M2C_UNK netObjDestroyCB;
extern M2C_UNK netObjUpdateVehicleCB;
extern M2C_UNK netPadFlagsUpdateCB;
extern M2C_UNK netStatsUpdateCB;
extern M2C_UNK netWeaponCreateCB;
extern M2C_UNK netWeaponDestroyCB;
extern M2C_UNK netWeaponUpdateCB;

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

    temp_s0 = D_004E72A0;
    memset(&sp1, 0, 0xFF);
    sp100 = temp_s0;
    memset(&sp101, 0, 0xFF);
    func_00268ED0(&sp200);
    sp208 = 0x272F;
    sp204 = 0x40;
    func_00268F20(&sp200, &sp220);
    func_00269318(0x2000, 0x2000);
    var_v0 = -1;
    if (func_00266F50(sp) == 0) {
        var_v0 = -1;
        if (func_00267080(&sp100) == 0) {
            temp_s0_2 = "-----------------------------------------------------------------\n";
            printf(temp_s0_2);
            printf("NETWORK: Initialized Distributed Memory Engine\n");
            printf("         Build Version  %s\n", sp);
            printf("         Client Version %s\n", &sp100);
            printf(temp_s0_2);
            var_v0_2 = 0x12C;
            if (D_00319924 == 0) {
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
            dmeObjLayoutBegin(0x85, 0, 0x43, 0x7D0);
            spA48 = &sp2C0;
            dmeObjLayoutAddField(&spA40, 4, 1, 1);
            dmeObjRegisterType(&D_004F9D18, "NetVehicle", 0x38);
            dmeObjSetCallbacks(D_004F9D18, &netObjCreateCB, &netObjUpdateVehicleCB, &netObjDestroyCB);
            dmeObjLayoutBegin();
            dmeObjLayoutAddField(&spA40, 4, 1, 1);
            dmeObjLayoutAddField(&spA40, &sp320 - &sp31B, 1, 1);
            dmeObjLayoutAddField(&spA40, &sp320 - &sp31A, 1, 0);
            dmeObjLayoutAddField(&spA40, &sp320 - &sp319, 1, 0);
            dmeObjLayoutAddField(&spA40, &sp320 - &sp318, 1, 0);
            dmeObjLayoutAddField(&spA40, &sp320 - &sp316, 2, 2);
            dmeObjLayoutAddField(&spA40, &sp320 - &sp314, 1, 0);
            dmeObjLayoutAddField(&spA40, &sp320 - &sp312, 2, 2);
            dmeObjLayoutAddField(&spA40, &sp320 - &sp310, 2, 2);
            dmeObjLayoutAddField(&spA40, &sp320 - &sp30E, 2, 2);
            dmeObjLayoutAddField(&spA40, &sp320 - &sp30C, 0xC, 0xD);
            dmeObjLayoutAddField(&spA40, &sp320 - &sp300, 0xC, 0xD);
            dmeObjLayoutAddField(&spA40, &sp320 - &sp2F4, 0xC, 0xD);
            dmeObjLayoutAddField(&spA40, &sp320 - &sp2E8, 4, 6);
            dmeObjLayoutAddField(&spA40, &sp320 - &sp2E4, 1, 1);
            dmeObjLayoutAddField(&spA40, &sp320 - &sp2DC, 1, 1);
            dmeObjRegisterType(&D_004F9D24, "NetWeapon", 0x4C);
            dmeObjSetCallbacks(D_004F9D24, &netWeaponCreateCB, &netWeaponUpdateCB, &netWeaponDestroyCB);
            dmeObjLayoutBegin();
            dmeObjLayoutAddField(&spA40, 0, 4, 4);
            dmeObjLayoutAddField(&D_004F9CD0, &sp370 - &sp36C, 0xC, 0xD);
            dmeObjLayoutAddField(&D_004F9CD4, &sp370 - &sp360, 0xC, 0xD);
            dmeObjLayoutAddField(&spA40, &sp370 - &sp354, 4, 4);
            dmeObjLayoutAddField(&spA40, &sp370 - &sp350, 4, 4);
            dmeObjLayoutAddField(&spA40, &sp370 - &sp34C, 4, 4);
            dmeObjLayoutAddField(&spA40, &sp370 - &sp348, 4, 4);
            dmeObjRegisterType(&D_004F9CA0, "NetFodder", 0x2C);
            dmeObjSetCallbacks(D_004F9CA0, &netObjCreateCB, &netFodderUpdateCB, &netObjDestroyCB);
            dmeObjLayoutBegin();
            dmeObjLayoutAddField(&spA40, 0, 4, 4);
            dmeObjLayoutAddField(&spA40, &sp3A0 - &sp39C, 4, 4);
            dmeObjLayoutAddField(&spA40, &sp3A0 - &sp398, 4, 5);
            dmeObjLayoutAddField(&spA40, &sp3A0 - &sp394, 4, 5);
            dmeObjLayoutAddField(&spA40, &sp3A0 - &sp390, 4, 4);
            dmeObjLayoutAddField(&spA40, &sp3A0 - &sp370, 4, 6);
            dmeObjLayoutAddField(&spA40, &sp3A0 - &sp350, 4, 4);
            dmeObjLayoutAddField(&spA40, &sp3A0 - &sp34C, 4, 4);
            dmeObjRegisterType(&D_004F9CA4, "NetStats", 0x58);
            dmeObjSetCallbacks(D_004F9CA4, &netObjCreateCB, &netStatsUpdateCB, &netObjDestroyCB);
            dmeObjLayoutBegin();
            dmeObjLayoutAddField(&spA40, 0, 4, 6);
            dmeObjLayoutAddField(&spA40, &sp400 - &sp3E0, 4, 6);
            dmeObjLayoutAddField(&spA40, &sp400 - &sp3C0, 4, 4);
            dmeObjLayoutAddField(&spA40, &sp400 - &sp3A0, 4, 4);
            dmeObjLayoutAddField(&spA40, &sp400 - &sp380, 4, 4);
            dmeObjLayoutAddField(&spA40, &sp400 - &sp378, 4, 5);
            dmeObjLayoutAddField(&spA40, &sp400 - &sp370, 4, 4);
            dmeObjLayoutAddField(&spA40, &sp400 - &sp368, 4, 4);
            dmeObjRegisterType(&D_004F9CA8, "NetPersistantStats", 0xA0);
            dmeObjSetCallbacks(D_004F9CA8, &netObjCreateCB, &netStatsUpdateCB, &netObjDestroyCB);
            dmeObjLayoutBegin();
            dmeObjLayoutAddField(&spA40, 0, 4, 5);
            dmeObjLayoutAddField(&spA40, &sp4A0 - &sp49C, 1, 1);
            dmeObjLayoutAddField(&spA40, &sp4A0 - &sp49B, 1, 1);
            dmeObjLayoutAddField(&spA40, &sp4A0 - &sp49A, 1, 1);
            dmeObjLayoutAddField(&spA40, &sp4A0 - &sp498, 4, 5);
            dmeObjLayoutAddField(&spA40, &sp4A0 - &sp494, 4, 5);
            dmeObjLayoutAddField(&spA40, &sp4A0 - &sp490, 4, 5);
            dmeObjLayoutAddField(&spA40, &sp4A0 - &sp48C, 4, 5);
            dmeObjLayoutAddField(&spA40, &sp4A0 - &sp488, 2, 3);
            dmeObjLayoutAddField(&spA40, &sp4A0 - &sp485, 1, 0);
            dmeObjLayoutAddField(&spA40, &sp4A0 - &sp480, 4, 4);
            dmeObjLayoutAddField(&spA40, &sp4A0 - &sp47C, 1, 1);
            dmeObjLayoutAddField(&spA40, &sp4A0 - &sp47B, 1, 1);
            dmeObjLayoutAddField(&spA40, &sp4A0 - &sp478, 4, 5);
            dmeObjLayoutAddField(&spA40, &sp4A0 - &sp474, 4, 5);
            dmeObjLayoutAddField(&spA40, &sp4A0 - &sp470, 2, 3);
            dmeObjLayoutAddField(&D_004F9CB8, &sp4A0 - &sp46E, 1, 0);
            dmeObjLayoutAddField(&D_004F9CBC, &sp4A0 - &sp464, 1, 1);
            dmeObjLayoutAddField(&D_004F9CC0, &sp4A0 - &sp414, 1, 1);
            dmeObjLayoutAddField(&D_004F9CCC, &sp4A0 - &sp3E4, 1, 1);
            dmeObjLayoutAddField(&D_004F9CC8, &sp4A0 - &sp486, 1, 0);
            dmeObjLayoutAddField(&D_004F9CC4, &sp4A0 - &sp3DC, 1, 0);
            dmeObjRegisterType(&D_004F9CAC, "NetGameData", 0xC8);
            dmeObjSetCallbacks(D_004F9CAC, &netObjCreateCB, &netGameDataUpdateCB, &netObjDestroyCB);
            dmeObjLayoutBegin();
            dmeObjLayoutAddField(&spA40, 0, 1, 1);
            dmeObjLayoutAddField(&spA40, &sp570 - &sp560, 1, 0);
            dmeObjLayoutAddField(&spA40, &sp570 - &sp55F, 1, 0);
            dmeObjLayoutAddField(&spA40, &sp570 - &sp55E, 2, 2);
            dmeObjLayoutAddField(&spA40, &sp570 - &sp55C, 2, 2);
            dmeObjRegisterType(&D_004F9CB0, "NetVehiclePadFlagsObj", 0x18);
            dmeObjSetCallbacks(D_004F9CB0, &netObjCreateCB, &netPadFlagsUpdateCB, &netObjDestroyCB);
            func_001192E8(&sp590);
            dmeObjLayoutBegin();
            dmeObjLayoutAddField(&spA40, 0, 4, 4);
            dmeObjLayoutAddField(&spA40, &sp590 - &sp584, 4, 4);
            dmeObjLayoutAddField(&spA40, &sp590 - &sp580, 4, 4);
            dmeObjLayoutAddField(&spA40, &sp590 - &sp57C, 4, 4);
            dmeObjLayoutAddField(&spA40, &sp590 - &sp570, 4, 4);
            dmeObjRegisterType(&D_004F9CB4, "NetArtifactObj\0BASCUS-97196\0 !\"#$%&'()*+,-.0123456789:;<=>?ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_abcdefghijklmnopqrstuvwxyz{}\0\00123456789\0\0 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\0 .0123456789", 0x7C);
            dmeObjSetCallbacks(D_004F9CB4, &netObjCreateCB, &netObjUpdateVehicleCB, &netObjDestroyCB);
            dmeMsgLayoutBegin();
            dmeMsgLayoutAddField(&sp610, &sp610, 4, 1);
            dmeMsgLayoutAddField(&sp610, &sp614, 4, 1);
            dmeMsgLayoutAddField(&sp610, &sp620, 0x40, 1);
            dmeMsgRegister(&spA44, &netMsgGameEventHandler);
            D_004F9D84 = spA44;
            dmeMsgLayoutBegin();
            dmeMsgLayoutAddField(&sp660, &sp660, 4, 1);
            dmeMsgLayoutAddField(&sp660, &sp670, 0xE0, 1);
            dmeMsgRegister(&spA44, &netMsgSessionHandler);
            D_004F9D88 = spA44;
            dmeMsgLayoutBegin();
            dmeMsgLayoutAddField(&sp750, &sp750, 4, 1);
            dmeMsgLayoutAddField(&sp750, &sp754, 0xBC, 1);
            dmeMsgRegister(&spA44, &netMsgWorldEventHandler);
            D_004F9D90 = spA44;
            dmeMsgLayoutBegin();
            dmeMsgLayoutAddField(&sp810, &sp810, 4, 1);
            dmeMsgLayoutAddField(&sp810, &sp814, 0x5C, 1);
            dmeMsgRegister(&spA44, &netMsgPlayerInfoHandler);
            D_004F9D94 = spA44;
            dmeMsgLayoutBegin();
            dmeMsgLayoutAddField(&sp870, &sp870, 0x30, 8);
            dmeMsgRegister(&spA44, &netMsgRosterHandler);
            D_004F9D98 = spA44;
            dmeMsgLayoutBegin();
            dmeMsgLayoutAddField(&sp9F0, &sp9F0, 4, 4);
            dmeMsgLayoutAddField(&sp9F0, &sp9F4, 0x44, 0x44);
            dmeMsgRegister(&spA44, &netMsgChatHandler);
            D_004F9D80 = spA44;
            func_00266478(&func_0016C590);
            var_v0 = 1;
        }
    }
    return var_v0;
}
//@@ func_0016E6F8 m2c
#include "m2c_macros.h"
extern s32 D_004F9D64;
extern M2C_UNK D_004F9D68;
extern M2C_UNK D_004F9D70;
extern M2C_UNK D_004F9D78;

void func_0016E6F8(s32 arg0) {
    u8 sp[0x10];
loop_1:
    WaitSema(arg0);
    if (D_004F9D64 & 1) {
        func_002A7AF8(&D_004F9D68, 0x5003, 0, 0);
        do {

        } while (func_002A7AF8(&D_004F9D70, 0x4806, 0, 0) < 0);
    } else {
        do {

        } while (func_002A7AF8(&D_004F9D78, 0x4402, 0, 0) < 0);
    }
    do {
loop_7:
        if (func_00291E90(sp) == 0) {
            goto loop_7;
        }
    } while (subroutine_arg0 != 0);
    goto loop_1;
}
//@@ func_0016E7D0 m2c
#include "m2c_macros.h"
extern s32 D_004F9D64;
extern M2C_UNK D_004FDD60;
extern M2C_UNK D_005015F0;
extern M2C_UNK func_0016E6D8;
extern M2C_UNK func_0016E6F8;

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
    temp_v0 = CreateSema(&sp30);
    if (temp_v0 != -1) {
        ChangeThreadPriority(GetThreadId(), 2);
        temp_v0_2 = CreateThread(sp, &D_004FDD60, &D_005015F0, &D_005015F0, 1);
        if (temp_v0_2 != -1) {
            StartThread(temp_v0_2, temp_v0);
            func_00290D20(&func_0016E6D8, temp_v0);
            D_004F9D64 = arg0;
            return temp_v0;
        }
        DeleteSema(temp_v0);
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return -1;
    }
    return -1;
}
//@@ func_0016E8E0 m2c
#include "m2c_macros.h"
extern M2C_UNK D_004F9DA8;
extern M2C_UNK D_004F9DB0;

void func_0016E8E0(void* arg0) {
    M2C_FIELD(arg0, s32* , 0) = -1;
    M2C_FIELD(arg0, s32* , 4) = -1;
    strcpy(arg0 + 8, &D_004F9DA8);
    strcpy(arg0 + 0x48, &D_004F9DB0);
    M2C_FIELD(arg0, f32* , 0xC0) = 10000.0f;
    M2C_FIELD(arg0, s32* , 0xBC) = 0x2710;
    strcpy(arg0 + 0xC4, "10.0.0.82");
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
//@@ func_0016E9A0 m2c
#include "m2c_macros.h"
extern M2C_UNK D_004F9DB0;

void* func_0016E9A0(void* arg0) {
    strcpy("Default Team\0BASCUS-97196\0 !\"#$%&'()*+,-.0123456789:;<=>?ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_abcdefghijklmnopqrstuvwxyz{}\0\00123456789\0\0 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\0 .0123456789");
    strcpy(arg0 + 0x40, &D_004F9DB0);
    M2C_FIELD(arg0, s32* , 0x80) = -1;
    return arg0;
}
//@@ func_0016EB78 m2c
#include "m2c_macros.h"
extern M2C_UNK D_003156C0;
extern s32 D_004F9DD8;
extern M2C_UNK func_00169050;

void func_0016EB78(void) {
    s32 temp_v0;
    s32 var_s0;
    void* var_s1;

    temp_v0 = timerGetFieldCount__Fv();
    if ((temp_v0 - D_004F9DD8) >= 0x259) {
        var_s0 = 0;
        if (M2C_FIELD(&D_003156C0, s32* , 0x1980) > 0) {
            var_s1 = &D_003156C0 + 0x1560;
            do {
                func_0026B998(var_s1, &func_00169050);
                var_s0 += 1;
                func_0026DFF8();
                var_s1 += 0x5C;
            } while (var_s0 < M2C_FIELD(&D_003156C0, s32* , 0x1980));
        }
        D_004F9DD8 = temp_v0;
    }
}
//@@ func_0016EC50 m2c
#include "m2c_macros.h"
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
        func_0016E8B8(var_s0);
        var_s0 += 0x220;
    } while (var_s2 != -1);
    var_s0_2 = arg0 + 0x1110;
    var_s2_2 = 1;
    do {
        var_s2_2 -= 1;
        func_0016E9A0(var_s0_2);
        var_s0_2 += 0x84;
    } while (var_s2_2 != -1);
    var_s0_3 = arg0 + 0x3244;
    func_0016E9E8(arg0 + 0x1218);
    var_s2_3 = 0xB;
    func_0016E8B8(arg0 + 0x1990);
    do {
        var_s2_3 -= 1;
        func_0017F848(var_s0_3);
        var_s0_3 += 0x7C;
    } while (var_s2_3 != -1);
    var_s0_4 = arg0 + 0x387C;
    var_s2_4 = 0x13;
    do {
        var_s2_4 -= 1;
        func_001192E8(var_s0_4);
        var_s0_4 += 0x7C;
    } while (var_s2_4 != -1);
    M2C_FIELD(arg0, s32* , 0) = 3;
    memset(arg0 + 0x3080, 0, 0xC8);
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
    func_001746E8(arg0, -1, 0x20, 0xFFC0FFFF);
    func_00174860(arg0);
    return arg0;
}
//@@ func_0016EE60 m2c
#include "m2c_macros.h"
void func_0016EE60(void* arg0, s32 arg1, s32 arg2, M2C_UNK arg3) {
    void* temp_v0;
    void* temp_v0_2;
    void* temp_v0_3;

    switch (arg1) {                                 /* irregular */
    case 0x1E47:
        temp_v0 = func_00213F80();
        M2C_FIELD(arg0, void** , 0xB790) = temp_v0;
        M2C_FIELD(temp_v0, s8* , 0xC) = 0;
        hierSetCsEpNode__FP3_csP9_hierhead(M2C_FIELD(arg0, void** , 0xB790), arg3);
        hierCsAddToCsList__FP3_cs(M2C_FIELD(arg0, void** , 0xB790));
        return;
    case 0x1E48:
        temp_v0_2 = func_00213F80();
        M2C_FIELD(arg0, void** , 0xB794) = temp_v0_2;
        M2C_FIELD(temp_v0_2, s8* , 0xC) = 0;
        hierSetCsEpNode__FP3_csP9_hierhead(M2C_FIELD(arg0, void** , 0xB794), arg3);
        hierCsAddToCsList__FP3_cs(M2C_FIELD(arg0, void** , 0xB794));
        break;
    case 0x1E49:
        temp_v0_3 = func_00213F80();
        M2C_FIELD(arg0, void** , 0xB798) = temp_v0_3;
        M2C_FIELD(temp_v0_3, s8* , 0xC) = 0;
        hierSetCsEpNode__FP3_csP9_hierhead(M2C_FIELD(arg0, void** , 0xB798), arg3);
        hierCsAddToCsList__FP3_cs(M2C_FIELD(arg0, void** , 0xB798));
        break;
    }
}
//@@ func_0016EF90 m2c
#include "m2c_macros.h"
extern M2C_UNK D_004F9E38;

void func_0016EF90(s32 arg0, s32 arg1) {
    void* temp_v1;
    void* temp_v1_2;

    temp_v1 = (arg1 * 0x220) + arg0;
    M2C_FIELD(temp_v1, s32* , 0x10) = -1;
    M2C_FIELD(temp_v1, s32* , 0x14) = -1;
    strcpy((arg1 * 0x220) + arg0 + 0x18, &D_004F9E38, temp_v1);
    strcpy((arg1 * 0x220) + arg0 + 0x58, &D_004F9E38);
    temp_v1_2 = (arg1 * 0x220) + arg0;
    M2C_FIELD(temp_v1_2, s32* , 0xCC) = 0x2710;
    M2C_FIELD(temp_v1_2, f32* , 0xD0) = 10000.0f;
    strcpy(temp_v1_2 + 0xD4, &D_004F9E38, temp_v1_2);
    M2C_FIELD(((arg1 * 0x220) + arg0), s32* , 0x214) = 0;
}
//@@ func_0016F058 m2c
#include "m2c_macros.h"
extern void* D_003156C4;
extern u8 D_004E79B8;
extern M2C_UNK D_004E79C0;
extern s32 D_004FA030;

s32 func_0016F058(void* arg0, s32 arg1, M2C_UNK arg2) {
    u8 sp[0x180];
    M2C_UNK sp1;
    M2C_UNK sp100;
    s32* temp_s2;
    void* temp_s1;

    memset(&sp1, 0, 0xFF);
    func_00267080(sp);
    printf(&D_004E79C0);
    temp_s2 = M2C_FIELD(arg0, s32** , 4);
    func_00264448();
    printf("Network: Remote Client (%d) has Joined Game %d (my client ID = %d) DME >>%s<< DME TIME >>%s<<\n", arg1, arg2, *temp_s2);
    printf(&D_004E79C0);
    M2C_FIELD(((arg1 * 0x220) + arg0), s32* , 0x10) = arg1;
    temp_s1 = arg0 + ((arg1 * 0x220) + 0x10) + 8;
    func_0014ECE8(arg1, temp_s1);
    func_0014ED08(arg1, temp_s1);
    if (M2C_FIELD(arg0, s32* , 0x1BB4) == 0xB) {
        func_001A9208();
        sprintf(&sp100, "%s is joining the game.", temp_s1);
        func_0014EDA0(&sp100);
        AddMessage__3Hudiii(D_004FA030 + ((M2C_FIELD(M2C_FIELD(D_003156C4, void** , 0xA0), s32* , 0x210C) * 0xA20) + 0x97B50), 0xF9, 2, 0);
    }
    return arg1;
}
//@@ func_0016F1C8 m2c
#include "m2c_macros.h"
extern M2C_UNK D_003156C0;
extern M2C_UNK D_004E79C0;
extern s32 D_004FA030;

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
    temp_s0 = M2C_FIELD((temp_s1 + &D_003156C0), void** , 0xB0);
    printf(&D_004E79C0);
    temp_a2 = temp_s1 + 0x10;
    if (arg1 >= 0) {
        printf("Network: Remote Client (%d) %s, Leaves Game\n", arg1, arg0 + temp_a2 + 8);
    } else {
        printf("Network: Remote Client (%d) Leaves Game\n", arg1, temp_a2);
    }
    printf("Network: Cleaning up Client Car and Client Object.\n");
    printf(&D_004E79C0);
    if (temp_s0 != NULL) {
        printf("  car name           = %d\n", M2C_FIELD(temp_s0, s32* , 0x20F4));
        printf("  car netPlayerType  = %d\n", M2C_FIELD(temp_s0, s32* , 0x20B4));
        var_s1 = 0x6C3C0;
        var_s2 = 0;
        printf("  car typeOfVehicle  = %d\n", M2C_FIELD(temp_s0, s32* , 0x590));
        var_s5 = 0xC7;
        printf("Remove Player Turning OFF the visual for car %d\n", M2C_FIELD(temp_s0, s32* , 0x20F4));
        func_0010BDC0(D_004FA030 + 0x30970, M2C_FIELD(temp_s0, s32* , 0x214C));
        func_001940E0(temp_s0 + 0x2F54);
        M2C_FIELD(temp_s0, s8* , 0x2155) = 0;
        M2C_FIELD(temp_s0, s8* , 0x2154) = 0;
        M2C_FIELD(temp_s0, s16* , 0x2156) = 0;
        func_001FDE10(0, func_00174268(&D_003156C0, arg1));
        func_001DC130(temp_s0);
        M2C_FIELD(temp_s0, s32* , 0x215C) = 0;
        M2C_FIELD(M2C_FIELD(temp_s0, void** , 0x2028), s8* , 0xD) = 0;
        M2C_FIELD(M2C_FIELD(temp_s0, void** , 0x2034), s8* , 0xC) = 0;
        do {
            temp_v0 = D_004FA030 + var_s2;
            if ((M2C_FIELD(temp_v0, s32* , 0x6C3C0) != 0) && (M2C_FIELD(temp_v0, s32* , 0x6C4F0) == temp_s0)) {
                func_001EFF98(D_004FA030 + var_s1);
                M2C_FIELD((D_004FA030 + var_s2), s32* , 0x6C3C0) = 0;
            }
            var_s1 += 0x210;
            var_s5 -= 1;
            var_s2 += 0x210;
        } while (var_s5 >= 0);
        temp_v1 = M2C_FIELD(temp_s0, u32* , 0x31A4);
        if (temp_v1 < 5U) {
            func_00128F48(D_004FA030 + ((temp_v1 * 0xB30) + 0x9A3E0));
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
        vehicleDisable__7Vehicle(temp_s0);
    }
    M2C_FIELD(((arg1 * 0x220) + arg0), s32* , 0xB0) = 0;
    printf("JUST Cleaned Up mPlayers[%d]\n", arg1);
    M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 0x3148), s8* , 0x24) = func_00176B10(&D_003156C0, 0);
    func_00176EA0(arg0);
    return arg1;
}
//@@ func_0016F718 m2c
#include "m2c_macros.h"
extern M2C_UNK D_004E7BC8;
extern M2C_UNK D_004E7D38;
extern M2C_UNK D_004E7DE0;
extern M2C_UNK D_004E7E08;
extern M2C_UNK D_004E7E30;
extern M2C_UNK D_004E7E58;
extern M2C_UNK D_004E7E70;
extern M2C_UNK D_004E7EA0;
extern M2C_UNK D_004E7ED0;
extern s32 D_004F9EB0;
extern s32 D_004F9EB4;
extern M2C_UNK D_004F9EB8;
extern M2C_UNK func_00168B60;
extern M2C_UNK func_00168C30;
extern M2C_UNK func_0016C480;
extern M2C_UNK func_0016C590;

s32 func_0016F718(void* arg0, s32 arg1) {
    u8 sp[0x40];
    M2C_UNK sp20;
    M2C_UNK sp30;
    s32 temp_s2;
    s32 var_s2;

    temp_s2 = arg0 + 0x1258;
    func_00266478(&func_0016C590);
    D_004F9EB4 = 2;
    D_004F9EB0 = 0;
    func_00266D78(&D_004F9EB8);
    printf(&D_004E7BC8);
    printf("NETWORK: Attempting to connect to Peer 2 Peer Server:\n");
    printf(&D_004E7DE0, temp_s2);
    printf(&D_004E7E08, M2C_FIELD(arg0, s32* , 0x1298));
    printf(&D_004E7E30, M2C_FIELD(arg0, s32* , 0x129C));
    if (arg1 != 0) {
        func_0026A4F8(sp);
        var_s2 = func_0026A550(sp, &sp20, &func_00168C30, M2C_FIELD(arg0, s32* , 0x2DFC));
        printf(&D_004E7E58, var_s2);
        M2C_FIELD(arg0, s32* , 0x2CF0) = sp28;
loop_4:
        if (func_0016F910(arg0, &sp30) == 2) {
            func_001703E8(arg0);
            goto loop_4;
        }
        M2C_FIELD(arg0, s32* , 0x307C) = netGetMyClientIndex(arg0);
        printf(&D_004E7E70);
        printf(&D_004E7EA0, M2C_FIELD(arg0, s32* , 0x307C));
        printf(&D_004E7E70);
    } else {
        var_s2 = func_002697C0(arg0 + 0x2CF0, 0, temp_s2, &func_0016C480);
    }
    if (var_s2 != 0) {
        D_004F9EB0 = 1;
        func_0026E2D8(M2C_FIELD(arg0, s32* , 0x2CF0));
    }
    printf(&D_004E7D38, M2C_FIELD(arg0, s32* , 0x2CF0));
    printf(&D_004E7ED0);
    return D_004F9EB0;
}
//@@ func_0016F910 m2c
#include "m2c_macros.h"
extern s32 D_004F9EB0;
extern s32 D_004F9EB4;
extern s32 D_004F9EB8;

s32 func_0016F910(void* arg0, s32* arg1) {
    u8 sp[0x10];
    s32 temp_s0;
    s32 temp_s1;

    func_00266D78(sp);
    temp_s1 = (dpcmp(litodp(subroutine_arg0 - D_004F9EB8), ((0x81BA << 0x10) | 0x9800) << 0x1F) < 1) ? 0 : 1;
    func_00266E48(&D_004F9EB4, M2C_FIELD(arg0, s32* , 0x2CF0));
    temp_s0 = D_004F9EB4;
    switch (temp_s0) {                              /* irregular */
    case 2:
        if (temp_s1 == 0) {
            switch (temp_s0) {                      /* switch 1; irregular */
            case 1:
            case 1:                                 /* switch 1 */
                if (func_0016FA30(arg0) != temp_s0) {
                    D_004F9EB0 = temp_s0;
                } else {
                    D_004F9EB0 = 0;
                }
                break;
            }
        } else {
        case 0:
        case 3:
        case 0:                                     /* switch 1 */
        case 3:                                     /* switch 1 */
            func_0016FD68(arg0);
            D_004F9EB4 = 3;
            if (D_004F9EB0 == 0) {
                D_004F9EB0 = 1;
            }
        }
        break;
    }
    *arg1 = D_004F9EB0;
    return D_004F9EB4;
}
//@@ func_0016FA30 m2c
#include "m2c_macros.h"
extern s32 D_00317270;
extern M2C_UNK D_004E7BC8;
extern s32 D_004F9EB4;

s32 func_0016FA30(void* arg0) {
    u8 sp[0x100];
    s32 spF0;
    s32 spF4;
    s32 spF8;
    s32 spFC;
    s32 var_s1;
    s32* temp_a2;
    s32* temp_v0;

    printf("NETWORK: Successfully connected to Server %s, Connection Index = %d\n", arg0 + 0x1258, M2C_FIELD(arg0, s32* , 0x2CF0));
    dmeGetMyClientIndex(&spF0, M2C_FIELD(arg0, s32* , 0x2CF0));
    printf("NETWORK: NetGetMyClientIndex(mConnectionIndex) = %d\n", spF0);
    temp_v0 = arg0 + ((spF0 * 0x220) + 0x10);
    M2C_FIELD(arg0, s32** , 4) = temp_v0;
    *temp_v0 = spF0;
    M2C_FIELD(M2C_FIELD(arg0, s32** , 4), s32* , 4) = -1;
    strcpy(M2C_FIELD(arg0, s32** , 4) + 8, arg0 + 0x1998, -1);
    strcpy(M2C_FIELD(arg0, s32** , 4) + 0x48, arg0 + 0x19D8);
    M2C_FIELD(M2C_FIELD(arg0, s32** , 4), s32* , 0xA4) = (s32) M2C_FIELD(arg0, s32* , 0x1A34);
    strcpy(M2C_FIELD(arg0, s32** , 4) + 0xC4, arg0 + 0x1A94);
    temp_a2 = M2C_FIELD(arg0, s32** , 4);
    M2C_FIELD(temp_a2, s32* , 0x204) = (s32) M2C_FIELD(arg0, s32* , 0x1B94);
    M2C_FIELD(M2C_FIELD(arg0, s32** , 4), s32* , 0xBC) = 0;
    func_00173570(arg0, 1, temp_a2);
    func_00266EB0(&spF4, M2C_FIELD(arg0, s32* , 0x2CF0));
    if (spF4 != 1) {
        printf("NETWORK: Connection count = %d, I am NOT the Session Master\n", spF4);
    } else {
        printf("NETWORK: Connection count = %d, I should be the Session Master\n", 1);
    }
    if (spF4 == 1) {
        D_00317270 = 1;
        func_00174598(arg0);
        M2C_FIELD(M2C_FIELD(arg0, s32** , 4), s32* , 0xA4) = (s32) M2C_FIELD(arg0, s32* , 0x1A34);
        memset(arg0 + 0x3080, 0, 0xC8);
        M2C_FIELD(arg0, s64* , 0x3080) = (s64) ((((((M2C_FIELD(arg0, s64* , 0x3080) & ~0x1E) | 4) & ~0x20 & ~0x3C0) | 0x40) & ~0xC00) | 0x800);
        M2C_FIELD(arg0, u8* , 0x3084) = (u8) M2C_FIELD(arg0, u8* , 0x2DFC);
        M2C_FIELD(arg0, s8* , 0x309B) = -1;
        M2C_FIELD(arg0, s8* , 0x309A) = -1;
        M2C_FIELD(arg0, s64* , 0x3080) = (s64) ((M2C_FIELD(arg0, s64* , 0x3080) & 0xFFC0FFFF) | 0x230000);
    }
    if (spF4 < 2) {
        M2C_FIELD(arg0, s32* , 0x2EE4) = 0;
    } else {
        func_00266D78(&spF8);
        printf("NETWORK: Waiting for state info...\n");
        M2C_FIELD(arg0, s32* , 0x2EE4) = 1;
    }
    var_s1 = 0;
    if (M2C_FIELD(arg0, s32* , 0x2EE4) != 0) {
loop_13:
        func_00266D78(&spFC);
        if (((spFC - spF8) < 0x1389) || (netSendSessionMsg(arg0, func_00173500(arg0), sp), func_00266D78(&spF8), printf("NETWORK: Still waiting for state info...\n"), func_00266E48(&D_004F9EB4, M2C_FIELD(arg0, s32* , 0x2CF0)), var_s1 = ((D_004F9EB4 ^ 1) != 0) ? 0xB : (var_s1 + 1), ((var_s1 < 0xB) != 0))) {
            func_001703E8(arg0);
            if (M2C_FIELD(arg0, s32* , 0x2EE4) == 0) {
                goto block_16;
            }
            goto loop_13;
        }
        func_00173570(arg0, 0);
        func_0016FD68(arg0);
        func_001748D8(arg0);
        D_004F9EB4 = 3;
        return 3;
    }
block_16:
    if (M2C_FIELD(arg0, s32* , 0x1BB4) != 0xE) {
        printf("NETWORK: Got State Info...\n");
        printf(&D_004E7BC8);
        D_004F9EB4 = 1;
        return 1;
    }
    func_0026E2D8(M2C_FIELD(arg0, s32* , 0x2CF0));
    func_001748D8(arg0);
    func_00173570(arg0, 0);
    D_004F9EB4 = 0;
    return 0;
}
//@@ func_0016FD68 m2c
#include "m2c_macros.h"
extern M2C_UNK D_002C1690;
extern s32 D_003183B0;
extern M2C_UNK D_004E7BC8;
extern M2C_UNK D_004E7DE0;
extern M2C_UNK D_004E7E08;
extern M2C_UNK D_004E7E30;

void func_0016FD68(void* arg0) {
    u8 sp[0x10];
    if (M2C_FIELD(arg0, s32* , 0x2CF0) >= 0) {
        if (M2C_FIELD(arg0, s32* , 0x2E90) == 0) {
            func_00165ED0(&D_002C1690, 2);
            func_00266EB0(sp, D_003183B0);
            if ((subroutine_arg0 < 2) && (func_001734B8(arg0) != 0)) {
                func_00166600(&D_002C1690, M2C_FIELD(&D_002C1690, s32* , 0x52438));
            }
        }
        printf(&D_004E7BC8);
        printf("NETWORK: Disconnecting from connection %d:\n", M2C_FIELD(arg0, s32* , 0x2CF0));
        printf(&D_004E7DE0, (s32) (arg0 + 0x1258));
        printf(&D_004E7E08, M2C_FIELD(arg0, s32* , 0x1298));
        printf(&D_004E7E30, M2C_FIELD(arg0, s32* , 0x129C));
        printf(&D_004E7BC8);
        M2C_FIELD(arg0, s32* , 0x1BB0) = 0;
        M2C_FIELD(arg0, s32* , 0x1BB4) = 0;
        func_0026E2D8(M2C_FIELD(arg0, s32* , 0x2CF0));
        M2C_FIELD(arg0, s32* , 0x2CF0) = -1;
    }
}
//@@ func_00170308 m2c
#include "m2c_macros.h"
extern M2C_UNK D_004E7BC8;
extern M2C_UNK D_004E80E0;
extern M2C_UNK D_004E8108;
extern M2C_UNK D_004E8130;
extern M2C_UNK D_004E8158;
extern void* D_004FA03C;

void func_00170308(void* arg0) {
    if (M2C_FIELD(arg0, s32* , 0x2CF0) >= 0) {
        func_00173570(0xC);
        printf(&D_004E7BC8);
        printf("NETWORK: Leaving the Game\n");
        printf(&D_004E80E0, M2C_FIELD(arg0, s32* , 0x2CF0));
        printf(&D_004E8108, M2C_FIELD(arg0, s32* , 4) + 8);
        printf(&D_004E8130, M2C_FIELD(arg0, s32* , 0x2E04));
        printf(&D_004E8158, M2C_FIELD(arg0, s32* , 0x2E08));
        printf(&D_004E7BC8);
        func_0026AE18(M2C_FIELD(arg0, s32* , 0x2CF0), 0);
        func_0026B340(M2C_FIELD(arg0, s32* , 0x2CF0));
        M2C_FIELD(arg0, s32* , 0x1BB0) = 1;
        M2C_FIELD(arg0, s32* , 0x3214) = (s32) M2C_FIELD(D_004FA03C, s32* , 0x1A3AC);
    }
}
//@@ func_001703E8 m2c
#include "m2c_macros.h"
extern s32 D_002B8A00;
extern M2C_UNK D_002C1690;
extern s32 D_00313D6C;
extern M2C_UNK D_003156C0;
extern s32 D_004F9E3C;
extern u32 D_004F9E40;
extern f32 D_004F9E44;
extern f32 D_004F9E48;
extern s32 D_004F9E4C;
extern s32 D_004F9E50;
extern M2C_UNK func_00168FB8;

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
            var_s2 = func_0026E028();
        } else {
            temp_v0 = func_0025A020();
            if (temp_v0 != 0) {
                var_s2 = func_0025C268(&D_002B8A00);
                printf("Medius Update returned an Error %d, NetError %d\n", temp_v0, var_s2);
            } else {
                temp_v0_2 = func_0010A588(&D_002B8A00);
                if (temp_v0_2 != 0) {
                    var_s1 = 0;
                    func_0026E278(sp);
loop_7:
                    if (var_s1 < 4) {
                        temp_s0 = &(&sp4[0])[var_s1];
                        printf("Connection %d Error = %d\n", var_s1, *temp_s0);
                        temp_s0_2 = *temp_s0;
                        if (temp_s0_2 == 0) {
                            var_s1 += 1;
                            goto loop_7;
                        }
                        var_s2 = temp_s0_2;
                    }
                    printf("MGCL Update returned an Error %d - Connection Index %d, NetError %d\n", temp_v0_2, D_002B8A00, var_s2);
                }
            }
        }
        if (func_0016D690(arg0) == -1) {
            var_a0 = "InitCheckConnectionStatus returned an Error...\n";
            goto block_18;
        }
        if (var_s2 != 0) {
            printf("NETWORK: Update Error = %d\n", var_s2);
            switch (var_s2) {                       /* irregular */
            case 2:
                var_a0 = "Update Error - Connection Lost\n";
block_18:
                printf(var_a0);
                func_00174D78(arg0, 6, 2);
                break;
            case 12:
                printf("Update Error - Bad Packet received from the server\n");
                break;
            default:
                printf("Update Error - Network Error\n");
                func_00174D78(arg0, 6, 2);
                break;
            }
        }
        temp_a0 = M2C_FIELD(arg0, s32* , 0x1BB4);
        if ((u32) (temp_a0 - 1) < 6U) {
            temp_v0_3 = D_004F9E4C + 1;
            D_004F9E4C = temp_v0_3;
            if (temp_v0_3 == 0x259) {
                if (temp_a0 > 0) {
                    if (M2C_FIELD(((D_004F9E50 * 0x220) + arg0), s32* , 0x10) != -1) {
                        func_0026B7A0(M2C_FIELD(arg0, s32* , 0x2CF0), D_004F9E50, &func_00168FB8);
                        func_0026DFF8();
                    }
                    temp_v0_4 = D_004F9E50 + 1;
                    D_004F9E50 = temp_v0_4;
                    if (temp_v0_4 >= 8) {
                        D_004F9E50 = 0;
                    }
                }
                D_004F9E4C = 0;
            }
        }
        if (M2C_FIELD(arg0, s32* , 0x1BB4) > 0) {
            func_00266DB8(&sp40);
            func_00266228(&sp20);
            D_004F9E3C += 1;
            D_004F9E44 += sp28;
            D_004F9E48 += sp38;
            func_00266D78(&sp44);
            if (((sp44 - M2C_FIELD(&D_002C1690, s32* , 0x526DC)) >= 0x4E21) && (M2C_FIELD(&D_002C1690, s32* , 8) >= 0) && (M2C_FIELD(arg0, s32* , 0x1BBC) != 0) && (M2C_FIELD(arg0, s32* , 0x2E90) == 0)) {
                if (func_001734B8(&D_003156C0) != 0) {
                    func_00166808(&D_002C1690, M2C_FIELD(&D_002C1690, s32* , 0x52438));
                }
                func_00166940(&D_002C1690, M2C_FIELD(&D_002C1690, s32* , 0x52438), M2C_FIELD(&D_002C1690, s32* , 0x60));
                func_0025A020();
                func_00266D78(&D_00313D6C);
            }
            if (M2C_FIELD(arg0, s32* , 0x1BB4) == 0xB) {
                if (func_001734B8(arg0) != 0) {
                    temp_v0_5 = D_004F9E40 + 1;
                    D_004F9E40 = temp_v0_5;
                    if (temp_v0_5 >= 0x12DU) {
                        M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 0x3148), s8* , 0x24) = func_00176B10(&D_003156C0, 0);
                        D_004F9E40 = 0;
                    }
                }
            }
        }
    }
}
//@@ func_00170760 m2c
#include "m2c_macros.h"
extern s8 D_003184B6;
extern s32 D_004F9D18;
extern s32 D_004F9DE4;

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
        func_001E5790(arg1, sp);
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
        if (D_003184B6 != 0) {
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
        func_00266DB8(&sp4, var_a1, var_a2, 1);
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), f32* , 0x20) = 16.6667f;
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), f32* , 0x10) = (f32) M2C_FIELD(arg1, f32* , 0x2D4);
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), f32* , 0x14) = (f32) M2C_FIELD(M2C_FIELD(arg1, void** , 0x2028), f32* , 0x68);
        M2C_FIELD(M2C_FIELD(arg1, void** , 0x20D0), f32* , 0x18) = (f32) M2C_FIELD(arg1, f32* , 0x208);
        if (M2C_FIELD(arg1, s32* , 0x20B4) == 4) {
            func_00109810(arg1, M2C_FIELD(arg1, s32* , 0x20D4));
        }
        if (timerGetFieldCount__Fv() >= 0x5B) {
            if (D_004F9DE4 == 0) {
                D_004F9DE4 = 1;
                func_0026C948(-1, D_004F9D18);
            }
            temp_v1_11 = M2C_FIELD(arg1, void** , 0x20D0);
            M2C_FIELD(temp_v1_11, u8* , 0x32) = (u8) (M2C_FIELD(temp_v1_11, u8* , 0x32) | 0x10);
        }
    }
}
//@@ func_00170B68 m2c
#include "m2c_macros.h"
extern s32 D_004F9CA0;
extern void* D_004FA030;

void func_00170B68(s32 arg0) {
    s32 temp_s0;
    s32 temp_s1;
    s32 var_s2;
    void* temp_a1;
    void* temp_a1_2;
    void* temp_v0;

    temp_a1 = D_004FA030;
    var_s2 = 0;
    if (M2C_FIELD(temp_a1, s32* , 0x96250) > 0) {
        do {
            temp_s1 = var_s2 * 0x110;
            temp_s0 = M2C_FIELD((temp_a1 + temp_s1), s32* , 0x9601C);
            if (temp_s0 != -1) {

            } else if (func_0026BD50(temp_a1 + (temp_s1 + 0x95F20) + 0xFC, 1, 3, 0) != 0) {
                M2C_FIELD((D_004FA030 + temp_s1), s32* , 0x9601C) = temp_s0;
            } else {
                temp_v0 = netGetDmeTime(arg0, M2C_FIELD((D_004FA030 + temp_s1), s32* , 0x9601C));
                memset(M2C_FIELD(temp_v0, void** , 0x1C), 0, 0x2C);
                M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), s32* , 0) = 0xB;
                temp_a1_2 = D_004FA030 + temp_s1;
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
        } while (var_s2 < M2C_FIELD(D_004FA030, s32* , 0x96250));
    }
}
//@@ func_00170D38 m2c
#include "m2c_macros.h"
extern s32 D_004F9CA0;
extern M2C_UNK D_004F9E58;

void func_00170D38(void* arg0) {
    s32 temp_s1;
    void* temp_v0;

    temp_s1 = M2C_FIELD(arg0, s32* , 0x2E9C);
    if (temp_s1 == -1) {
        if (func_0026BD50(arg0 + 0x2E9C, 1, 3, 0) != 0) {
            M2C_FIELD(arg0, s32* , 0x2E9C) = temp_s1;
        } else {
            temp_v0 = netGetDmeTime(arg0, M2C_FIELD(arg0, s32* , 0x2E9C));
            memset(M2C_FIELD(temp_v0, void** , 0x1C), 0, 0x2C);
            M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), s32* , 0) = 1;
            M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), s32* , 0x24) = 0;
        }
    }
}
//@@ func_00170DF0 m2c
#include "m2c_macros.h"
extern s32 D_004F9CA0;
extern M2C_UNK D_004F9E60;
extern M2C_UNK D_004F9E68;
extern M2C_UNK D_004F9E70;
extern void* D_004FA030;

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

    if (func_001734B8() != 0) {
        func_00170B68(arg0);
        switch (arg1) {
        case 0:
        case 18:
            temp_s0 = M2C_FIELD(arg0, s32* , 0x2EAC);
            if (temp_s0 == -1) {
                if (func_0026BD50(arg0 + 0x2EAC, 1, 3, 0) != 0) {
                    M2C_FIELD(arg0, s32* , 0x2EAC) = temp_s0;
                } else {
                    var_s0 = netGetDmeTime(arg0, M2C_FIELD(arg0, s32* , 0x2EAC));
                    if (var_s0 != NULL) {
                        memset(M2C_FIELD(var_s0, s32** , 0x1C), 0, 0x2C);
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
            func_00170D38(arg0);
            temp_s0_2 = M2C_FIELD(arg0, s32* , 0x2EA8);
            if (temp_s0_2 != -1) {

            } else if (func_0026BD50(arg0 + 0x2EA8, 1, 3, 0) == 0) {
                temp_v0 = netGetDmeTime(arg0, M2C_FIELD(arg0, s32* , 0x2EA8));
                memset(M2C_FIELD(temp_v0, s32** , 0x1C), 0, 0x2C);
                M2C_FIELD(M2C_FIELD(temp_v0, s32** , 0x1C), s32* , 0) = 2;
                M2C_FIELD(M2C_FIELD(temp_v0, s32** , 0x1C), s32* , 0x24) = 0;
            } else {
                M2C_FIELD(arg0, s32* , 0x2EA8) = temp_s0_2;
            }
            if (M2C_FIELD(arg0, s32* , 0x2EA0) == -1) {
                if (func_0026BD50(arg0 + 0x2EA0, 1, 3, 0) != 0) {
                    M2C_FIELD(arg0, s32* , 0x2EA0) = M2C_FIELD(arg0, s32* , 0x2EA0);
                } else {
                    var_s0 = netGetDmeTime(arg0, M2C_FIELD(arg0, s32* , 0x2EA0));
                    memset(M2C_FIELD(var_s0, s32** , 0x1C), 0, 0x2C);
                    var_v1 = M2C_FIELD(var_s0, s32** , 0x1C);
                    var_v0 = 4;
                    goto block_52;
                }
            }
            break;
        case 3:
            temp_s0_3 = M2C_FIELD(arg0, s32* , 0x2EB4);
            if (temp_s0_3 == -1) {
                if (func_0026BD50(arg0 + 0x2EB4, 1, 3, 0) != 0) {
                    M2C_FIELD(arg0, s32* , 0x2EB4) = temp_s0_3;
                } else {
                    temp_v0_2 = netGetDmeTime(arg0, M2C_FIELD(arg0, s32* , 0x2EB4));
                    memset(M2C_FIELD(temp_v0_2, s32** , 0x1C), 0, 0x2C);
                    M2C_FIELD(M2C_FIELD(temp_v0_2, s32** , 0x1C), s32* , 0) = 6;
                    M2C_FIELD(M2C_FIELD(temp_v0_2, s32** , 0x1C), s32* , 0x24) = 1;
                    M2C_FIELD(M2C_FIELD(temp_v0_2, s32** , 0x1C), s32* , 0x20) = (s32) M2C_FIELD(D_004FA030, s32* , 0x96844);
                    M2C_FIELD(M2C_FIELD(temp_v0_2, s32** , 0x1C), f32* , 4) = (f32) M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x96840), f32* , 0x10);
                    M2C_FIELD(M2C_FIELD(temp_v0_2, s32** , 0x1C), f32* , 8) = (f32) M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x96840), f32* , 0x14);
                    M2C_FIELD(M2C_FIELD(temp_v0_2, s32** , 0x1C), f32* , 0xC) = (f32) M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x96840), f32* , 0x18);
                    M2C_FIELD(M2C_FIELD(temp_v0_2, s32** , 0x1C), f32* , 0x10) = (f32) M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x96840), f32* , 0x60);
                    M2C_FIELD(M2C_FIELD(temp_v0_2, s32** , 0x1C), f32* , 0x14) = (f32) M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x96840), f32* , 0x64);
                    M2C_FIELD(M2C_FIELD(temp_v0_2, s32** , 0x1C), f32* , 0x18) = (f32) M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x96840), f32* , 0x68);
                }
            }
            break;
        case 5:
        case 17:
            temp_s0_4 = M2C_FIELD(arg0, s32* , 0x2EC0);
            temp_a1 = D_004FA030;
            if (temp_s0_4 == -1) {
                if (func_0026BD50(arg0 + 0x2EC0, 1, 3, 0) == 0) {
                    temp_v0_3 = netGetDmeTime(arg0, M2C_FIELD(arg0, s32* , 0x2EC0));
                    memset(M2C_FIELD(temp_v0_3, s32** , 0x1C), 0, 0x2C);
                    M2C_FIELD(M2C_FIELD(temp_v0_3, s32** , 0x1C), s32* , 0) = 7;
                    M2C_FIELD(M2C_FIELD(temp_v0_3, s32** , 0x1C), s32* , 0x24) = 1;
                    M2C_FIELD(M2C_FIELD(temp_v0_3, s32** , 0x1C), s32* , 0x20) = (s32) M2C_FIELD(D_004FA030, s32* , 0x962F4);
                    M2C_FIELD(M2C_FIELD(temp_v0_3, s32** , 0x1C), f32* , 4) = (f32) M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x962F0), f32* , 0x10);
                    M2C_FIELD(M2C_FIELD(temp_v0_3, s32** , 0x1C), f32* , 8) = (f32) M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x962F0), f32* , 0x14);
                    M2C_FIELD(M2C_FIELD(temp_v0_3, s32** , 0x1C), f32* , 0xC) = (f32) M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x962F0), f32* , 0x18);
                    M2C_FIELD(M2C_FIELD(temp_v0_3, s32** , 0x1C), f32* , 0x10) = (f32) M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x962F0), f32* , 0x60);
                    M2C_FIELD(M2C_FIELD(temp_v0_3, s32** , 0x1C), f32* , 0x14) = (f32) M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x962F0), f32* , 0x64);
                    M2C_FIELD(M2C_FIELD(temp_v0_3, s32** , 0x1C), f32* , 0x18) = (f32) M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x962F0), f32* , 0x68);
                } else {
                    M2C_FIELD(arg0, s32* , 0x2EC0) = temp_s0_4;
                }
            }
            temp_s2 = M2C_FIELD(temp_a1, s32* , 0x968D8);
            if (temp_s2 != -1) {

            } else if (func_0026BD50(temp_a1 + 0x968D8, 1, 3, 0) != 0) {
                M2C_FIELD(D_004FA030, s32* , 0x968D8) = temp_s2;
            } else {
                temp_v0_4 = netGetDmeTime(arg0, M2C_FIELD(D_004FA030, s32* , 0x968D8));
                memset(M2C_FIELD(temp_v0_4, s32** , 0x1C), 0, 0x2C);
                M2C_FIELD(M2C_FIELD(temp_v0_4, s32** , 0x1C), s32* , 0) = 8;
                M2C_FIELD(M2C_FIELD(temp_v0_4, s32** , 0x1C), s32* , 0x24) = 0;
            }
            temp_s2_2 = M2C_FIELD(D_004FA030, s32* , 0x96968);
            if (temp_s2_2 == -1) {
                if (func_0026BD50(D_004FA030 + 0x96968, 1, 3, 0) != 0) {
                    M2C_FIELD(D_004FA030, s32* , 0x96968) = temp_s2_2;
                } else {
                    temp_v0_5 = netGetDmeTime(arg0, M2C_FIELD(D_004FA030, s32* , 0x96968));
                    memset(M2C_FIELD(temp_v0_5, s32** , 0x1C), 0, 0x2C);
                    M2C_FIELD(M2C_FIELD(temp_v0_5, s32** , 0x1C), s32* , 0) = 9;
                    M2C_FIELD(M2C_FIELD(temp_v0_5, s32** , 0x1C), s32* , 0x24) = 0;
                }
            }
            break;
        case 6:
            temp_a0 = D_004FA030 + 0x3EAC0;
            temp_s2_3 = M2C_FIELD(temp_a0, s32* , 0x188);
            if (temp_s2_3 == -1) {
                if (func_0026BD50(temp_a0 + 0x188, 1, 3, 0) != 0) {
                    M2C_FIELD((D_004FA030 + 0x3EAC0), s32* , 0x188) = temp_s2_3;
                } else {
                    temp_v0_6 = netGetDmeTime(arg0, M2C_FIELD((D_004FA030 + 0x3EAC0), s32* , 0x188));
                    memset(M2C_FIELD(temp_v0_6, s32** , 0x1C), 0, 0x2C);
                    M2C_FIELD(M2C_FIELD(temp_v0_6, s32** , 0x1C), s32* , 0) = 0xA;
                    M2C_FIELD(M2C_FIELD(temp_v0_6, s32** , 0x1C), s32* , 0x24) = 0;
                    M2C_FIELD(M2C_FIELD(temp_v0_6, s32** , 0x1C), s32* , 0x1C) = 0;
                }
            }
            break;
        case 7:
            func_00170D38(arg0);
            break;
        case 10:
            temp_s0_5 = M2C_FIELD(arg0, s32* , 0x2EA8);
            if (temp_s0_5 == -1) {
                if (func_0026BD50(arg0 + 0x2EA8, 1, 3, 0) != 0) {
                    M2C_FIELD(arg0, s32* , 0x2EA8) = temp_s0_5;
                } else {
                    var_s0 = netGetDmeTime(arg0, M2C_FIELD(arg0, s32* , 0x2EA8));
                    memset(M2C_FIELD(var_s0, s32** , 0x1C), 0, 0x2C);
                    var_v1 = M2C_FIELD(var_s0, s32** , 0x1C);
                    var_v0 = 2;
                    goto block_52;
                }
            }
            break;
        }
    }
}
//@@ func_001714D0 m2c
#include "m2c_macros.h"
extern M2C_UNK D_003156C0;
extern M2C_UNK D_0041BF00;
extern M2C_UNK D_004E8528;
extern s32 D_004F9CA4;
extern s32 D_004F9D18;
extern s32 D_004FA030;

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
    temp_a0 = *(D_004FA030 + 0x9E670 + ((func_00174268(&D_003156C0, M2C_FIELD(M2C_FIELD(arg0, void** , 4), s32* , 0)) - 1) * 4));
    temp_a1 = M2C_FIELD(temp_a2, s32* , 0xA4);
    if ((M2C_FIELD(temp_a0, s32* , 0x20F4) == temp_a1) && (M2C_FIELD(temp_a0, s32* , 0x20C4) == -1)) {
        M2C_FIELD(temp_a2, void** , 0xA0) = temp_a0;
        if (M2C_FIELD(&D_003156C0, s32* , 0x3220) != 0) {
            var_a0 = 6;
        } else {
            var_a0 = 1;
        }
        M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), s32* , 0x20B4) = var_a0;
    }
    temp_v1 = M2C_FIELD(arg0, void** , 4);
    M2C_FIELD(M2C_FIELD(temp_v1, void** , 0xA0), s32* , 0x20C0) = (s32) M2C_FIELD(temp_v1, s32* , 0);
    vehicleDisable__7Vehicle(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), temp_a1, temp_a2);
    temp_v1_2 = M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0);
    if (M2C_FIELD(temp_v1_2, s32* , 0x20F4) == 0x100) {
        temp_a0_2 = M2C_FIELD(temp_v1_2, s32* , 0x2038);
        if (temp_a0_2 != 0) {
            hierSetCsDrawMe__FP3_csUc(temp_a0_2, 1);
        }
    }
    if (M2C_FIELD(arg0, s32* , 0x3220) != 0) {
        M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), s8* , 0x485) = 1;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), s8* , 0x488) = 1;
    } else {
        memset(&sp10, 0, 0x38);
        temp_t4 = M2C_FIELD(arg0, void** , 4);
        sp38 = (u16) M2C_FIELD(temp_t4, s32* , 0xA4);
        sp10 = M2C_FIELD(temp_t4, void** , 0xA0);
        sp3E = M2C_FIELD(M2C_FIELD(temp_t4, void** , 0xA0), u8* , 0x590);
        temp_v1_3 = M2C_FIELD(arg0, void** , 4);
        if (func_0026BD50(M2C_FIELD(temp_t4, void** , 0xA0) + 0x20C4, 1, 2, 0) != 0) {
            M2C_FIELD(M2C_FIELD(temp_v1_3, void** , 0xA0), s32* , 0x20C4) = -1;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), s32* , 0x20B8) = -1;
        } else {
            M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), s32* , 0x20D0) = (s32) M2C_FIELD(netGetDmeTime(arg0, M2C_FIELD(M2C_FIELD(temp_v1_3, void** , 0xA0), s32* , 0x20C4)), s32* , 0x1C);
            func_00265180(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), s32* , 0x20C4));
            if (func_001734B8(arg0) != 0) {
                vehicleEnable__7Vehicle12VehicleTypes(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), 1);
            }
        }
        if (D_004F9CA4 >= 0) {
            memset(&sp50, 0, 0x58);
            sp50 = (void* ) M2C_FIELD(M2C_FIELD(arg0, void** , 4), s32* , 0xA4);
            if (func_001734B8(arg0) != 0) {
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
            if (func_0026BD50(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0) + 0x20CC, 1, 2, 0) != 0) {
                M2C_FIELD(M2C_FIELD(arg0, void** , 4), s32* , 0x210) = 0;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), s32* , 0x20CC) = -1;
            } else {
                M2C_FIELD(M2C_FIELD(arg0, void** , 4), s32* , 0x210) = (s32) M2C_FIELD(netGetDmeTime(arg0, M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), s32* , 0x20CC)), s32* , 0x1C);
                temp_v1_5 = M2C_FIELD(arg0, void** , 4);
                M2C_FIELD(M2C_FIELD(temp_v1_5, void** , 0xA0), s32* , 0x20D8) = (s32) M2C_FIELD(temp_v1_5, s32* , 0x210);
            }
        }
    }
    func_00170760(arg0, M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0));
}
//@@ func_00171818 m2c
#include "m2c_macros.h"
extern s32 D_004F9D24;
extern M2C_UNK D_004F9E78;
extern void* D_004FA030;

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

    memset(&sp10, 0, 0x4C);
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
        if (temp_a1 == M2C_FIELD(D_004FA030, s32* , 0x9E690)) {
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
            if (temp_a1_3 == M2C_FIELD(D_004FA030, s32* , 0x9E690)) {
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
    func_0026BD50(arg1 + 0x50, 1, 2, 0);
    return M2C_FIELD(arg1, s32* , 0x50);
}
//@@ func_00171AA8 m2c
#include "m2c_macros.h"
extern M2C_UNK D_003156C0;

void func_00171AA8(s32 arg0, void* arg1, void* arg2, s8 arg3) {
    s32 temp_a0;
    u8 var_v0;
    void* temp_v1;

    temp_v1 = M2C_FIELD(netGetDmeTime(&D_003156C0, M2C_FIELD(arg1, s32* , 0x50)), void** , 0x1C);
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
    func_0026C948(-1, M2C_FIELD(arg1, s32* , 0x50));
}
//@@ func_00171B78 m2c
#include "m2c_macros.h"
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
    strncpy(&sp18, temp_a1 + 8, 0xF, M2C_FIELD(temp_a1, s32* , 0xA4));
    sp27 = 0;
    temp_v0 = M2C_FIELD(arg0, void** , 4);
    sp30 = M2C_FIELD(temp_v0, f32* , 0x90);
    sp34 = M2C_FIELD(temp_v0, f32* , 0x94);
    sp38 = M2C_FIELD(temp_v0, f32* , 0x98);
    sp40 = M2C_FIELD(arg0, s32* , 0x1BB4);
    sp3C = M2C_FIELD(temp_v0, f32* , 0x9C);
    netSendSessionMsg(arg0, arg1, sp);
}
//@@ func_00171C08 m2c
#include "m2c_macros.h"
extern s32 D_004F9D80;

void func_00171C08(void* arg0) {
    u8 sp[0x60];
    s8 sp50;
    s32 temp_a2;
    s32 var_s0;

    var_s0 = 0;
    strcpy(sp);
loop_1:
    func_00266708(&sp50, M2C_FIELD(arg0, s32* , 0x2CF0), var_s0);
    temp_a2 = var_s0;
    var_s0 += 1;
    if (sp50 != 0) {
        dmeSendMsgToClient(0x40, M2C_FIELD(arg0, s32* , 0x2CF0), temp_a2, D_004F9D80);
    }
    if (var_s0 < 8) {
        goto loop_1;
    }
}
//@@ netSendSessionMsg m2c
#include "m2c_macros.h"
extern s32 D_004F9D88;

s32 netSendSessionMsg(void* arg0, s32 arg1, s32* arg2) {
    u8 sp[0x10];
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_s0;

    temp_v1 = *M2C_FIELD(arg0, s32** , 4);
    if ((temp_v1 != -1) && (temp_v1 == arg1)) {
        netMsgSessionHandler(M2C_FIELD(arg0, s32* , 0x2CF0), M2C_FIELD(arg0, s32* , 0x129C), arg1, arg2);
        goto block_17;
    }
    switch (arg1) {                                 /* irregular */
    case -1:
        var_s0 = 0;
        do {
            if ((func_00266708(sp, M2C_FIELD(arg0, s32* , 0x2CF0), var_s0) == 0) && (subroutine_arg0 != 0)) {
                temp_v0 = dmeSendMsgToClient(0x40, M2C_FIELD(arg0, s32* , 0x2CF0), var_s0, D_004F9D88);
                if (temp_v0 != 0) {
                    printf("NETWORK WARNING: Failed to send PREGAME (1) command %d to client %d NetError = %d\n", *arg2, var_s0, temp_v0);
                }
            }
            var_s0 += 1;
        } while (var_s0 < 8);
block_17:
        return 1;
    case -99:
        return 0;
    default:
        temp_v0_2 = dmeSendMsgToClient(0x40, M2C_FIELD(arg0, s32* , 0x2CF0), arg1, D_004F9D88);
        if (temp_v0_2 != 0) {
            printf("NETWORK WARNING: Failed to send PREGAME (1) command %d to client %d NetError = %d\n", *arg2, arg1, temp_v0_2);
        }
        goto block_17;
    }
}
//@@ netSendGameEvent m2c
#include "m2c_macros.h"
s32 netSendGameEvent(void* arg0, s32 arg1, void* arg2) {
    s32 temp_v0;

    if (*M2C_FIELD(arg0, s32** , 4) == arg1) {
        netMsgGameEventHandler(M2C_FIELD(arg0, s32* , 0x2CF0), M2C_FIELD(arg0, s32* , 0x129C), arg1, arg2);
    } else {
        temp_v0 = dmeSendMsgToClient(0x40, M2C_FIELD(arg0, s32* , 0x2CF0), arg1, D_004F9D84);
        if (temp_v0 != 0) {
            printf("NETWORK WARNING: Failed to send command %d to client %d NetError = %d\n", M2C_FIELD(arg2, s32* , 4), arg1, temp_v0);
        }
    }
    return 1;
}
//@@ func_00171F88 m2c
#include "m2c_macros.h"
extern M2C_UNK D_00318416;
extern s32 D_004F9D98;
extern s32 D_004FA030;

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
    var_t2 = &D_00318416;
    var_t1 = &sp2C;
    var_t4 = &D_00318416 + 0x272;
    var_t0 = &sp28;
    var_fp = &sp1C;
    var_s7 = &sp18;
    var_s1 = 0;
    var_s6 = &sp20;
    var_s4 = &sp24;
    var_s3 = &sp14;
    var_s2 = sp;
    var_s0 = &D_00318416 + 0x252;
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
        strcpy(temp_a0, (s128) var_t2, var_a2, var_a3);
        var_a3 = var_s1 < 8;
        temp_v1 = M2C_FIELD((D_004FA030 + var_t3), s32* , 0x20F4);
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
        netMsgRosterHandler(M2C_FIELD(arg0, s32* , 0x2CF0), M2C_FIELD(arg0, s32* , 0x129C), var_s1_2, sp);
    } else {
        temp_v0_2 = func_00266708(&sp180, M2C_FIELD(arg0, s32* , 0x2CF0), var_s1_2);
        if (temp_v0_2 != 0) {
            sp18F = 0;
            printf("NETWORK WARNING:  NetGetClientIpAddress Failed %d (%s)\n", temp_v0_2, &sp180);
        }
        if (sp180 != 0) {
            temp_v0_3 = dmeSendMsgToClient(0x40, M2C_FIELD(arg0, s32* , 0x2CF0), var_s1_2, D_004F9D98);
            if (temp_v0_3 != NULL) {
                printf("NETWORK WARNING: Failed to FINAL SCORE to client %d NetError = %d\n", var_s1_2, temp_v0_3);
            }
        }
    }
    var_s1_2 += 1;
    if (var_s1_2 < 8) {
        goto loop_3;
    }
    return 1;
}
//@@ func_00172190 m2c
#include "m2c_macros.h"
extern s32 D_004FA03C;

void func_00172190(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 temp_s2;

    temp_s2 = arg0 + 0x1CC8;
    memset(temp_s2, 0, 0x1000);
    if (func_001B0428(D_004FA03C + 0x19E60, arg1, temp_s2, arg2) != 0) {
        func_00172378(arg0, temp_s2);
    }
}
//@@ func_00172218 m2c
#include "m2c_macros.h"
s32 func_00172218(void* arg0) {
    s32 temp_s1;

    temp_s1 = arg0 + 0x1CC8;
    memset(temp_s1, 0, 0x1000);
    sprintf(temp_s1, "[CONNECT_IP] %s\n[CLIENT_IP] %s\n[CLIENT_SUBNET] %s\n[CLIENT_GATEWAY] %s\n[WORLD_ID] %d\n[SERVER_IP] %s\n[DNS_SERVERS] %s %s\n[SERVER_PORT] %d\n[CURRENT_CONFIG] %d\n[AUTO_RECONNECT] %d\n[SHOW_DIAGNOSTICS] %d\n[MEDIUS_SERVER] %s\n[MEDIUS_PORT] %s\n", arg0 + 0x13AC, arg0 + 0x1A54, M2C_FIELD(arg0, s32* , 0x1298), M2C_FIELD(arg0, s32* , 0x4288), M2C_FIELD(arg0, s32* , 0x4270), M2C_FIELD(arg0, s32* , 0x4274), arg0 + 0x142C, arg0 + 0x146C);
    return 1;
}
//@@ func_001722C0 m2c
#include "m2c_macros.h"
s32 func_001722C0(void* arg0) {
    s32 temp_s1;

    temp_s1 = arg0 + 0x1CC8;
    memset(temp_s1, 0, 0x1000);
    sprintf(temp_s1, "[USER_NAME] %s\n[USER_CAR] %d\n[GAME_NAME] %s\n", arg0 + 0x1998, M2C_FIELD(arg0, s32* , 0x1A34));
    return 1;
}
//@@ func_00172A10 m2c
#include "m2c_macros.h"
extern s8* D_004FB4F0;

s8* func_00172A10(s32 arg0, s8* arg1) {
    s32 var_a1;
    s8 var_v0;
    s8* var_v1;

    if (arg1 != NULL) {
        D_004FB4F0 = arg1;
    }
    var_a1 = 0;
    var_v1 = D_004FB4F0;
    if (*D_004FB4F0 == 0) {
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
            D_004FB4F0 = var_v1;
            goto block_8;
        }
    } else {
block_8:
        var_v0 = *var_v1;
    }
    if ((var_v0 != 0) && (var_a1 == 0)) {
        goto loop_5;
    }
    return D_004FB4F0;
}
//@@ func_00172A90 m2c
#include "m2c_macros.h"
extern M2C_UNK D_003156C0;
extern s32 D_004F9E8C;

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
                    M2C_FIELD(var_a2, s32* , 8) = (s32) (M2C_FIELD(var_a2, s32* , 8) + (M2C_FIELD(var_a1, s8* , 0x32) * timerGetFieldsLastFrame__Fv(4U)));
                }
                func_0011A8D0(arg0 + 0x386C, var_a1, var_a2);
                var_s2 = arg0 + 0x3234;
            }
        }
    } else {
        var_s2 = arg0 + 0x3234;
        if (func_001734B8(arg0) != 0) {
            var_a2_2 = 0;
            if (M2C_FIELD(M2C_FIELD(arg0, void** , 0x3148), s8* , 0x1A) < 0) {
                M2C_FIELD(M2C_FIELD(arg0, void** , 0x3148), s8* , 0x1A) = netGetMyClientIndex(arg0);
                func_001A9278();
                func_00174988(arg0, -1);
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
            if ((temp_a1 != -1) && ((temp_v1_4 = M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 0x3148), u32* , 0), (((temp_v1_4 >> 5) & 1) != 1)) || (temp_v1_4 & 1))) {
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
                    func_00173248(arg0, M2C_FIELD(temp_v0_2, s8* , 0x1A), -1, -1);
                    func_00174988(arg0, -1);
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
        temp_v1_7 = M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 0x3148), s8* , 0x1A);
        var_s1 = NULL;
        if (temp_v1_7 >= 0) {
            var_s1 = M2C_FIELD(((temp_v1_7 * 0x220) + &D_003156C0), void** , 0xB0);
        }
        if (var_s1 != NULL) {
            temp_a1_2 = M2C_FIELD(arg0, void** , 4);
            if ((M2C_FIELD(M2C_FIELD(arg0, void** , 0x3148), s8* , 0x1A) == M2C_FIELD(temp_a1_2, s32* , 0)) && ((temp_a0_3 = M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 0x3148), u32* , 0), (((temp_a0_3 >> 5) & 1) != 1)) || (temp_a0_3 & 1)) && (M2C_FIELD(temp_a1_2, void** , 0x210) != NULL) && (M2C_FIELD(M2C_FIELD(temp_a1_2, void** , 0xA0), s8* , 0x485) == 0)) {
                temp_a1_3 = M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0x210);
                M2C_FIELD(temp_a1_3, s32* , 8) = (s32) (M2C_FIELD(temp_a1_3, s32* , 8) + timerGetFieldsLastFrame__Fv(temp_a0_3, temp_a1_2, M2C_FIELD(&D_003156C0, void** , 0x3148)));
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
    func_001808F0(var_s2);
    temp_v0_6 = D_004F9E8C + 1;
    D_004F9E8C = temp_v0_6;
    if (temp_v0_6 >= 0x709) {
        D_004F9E8C = 0;
        func_00176EA0(arg0);
    }
}
//@@ func_00172FA0 m2c
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
//@@ func_00172FE8 m2c
#include "m2c_macros.h"
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
            if (func_001734B8(arg0, temp_a1) != 0) {
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
                            func_001731A8(arg0, arg1, arg3);
                        }
                        break;
                    default:
                        func_00173248(arg0, arg1, arg3);
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
                        func_001731A8(arg0, arg1, arg3);
                        break;
                    default:                        /* switch 1 */
                        func_00173248(arg0, arg1, arg3);
                        break;
                    }
                }
                temp_a0_6 = M2C_FIELD(arg0, void** , 0x3148);
                temp_a1_3 = *M2C_FIELD(arg0, s32** , 4);
                if (M2C_FIELD(temp_a0_6, s8* , 0x1A) == temp_a1_3) {
                    func_001A9278(temp_a0_6, temp_a1_3);
                }
            }
        }
    }
}
//@@ func_001731A8 m2c
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
//@@ func_00173248 m2c
#include "m2c_macros.h"
void func_00173248(void* arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;
    s32 var_s0;
    s8 temp_v0;
    void* temp_v0_2;
    void* temp_v1;

    var_s0 = 0;
loop_1:
    temp_v0 = mathfRand__Fii(0, 7);
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
        func_001731A8(arg0, arg1, arg2);
        return;
    }
    temp_v0_2 = M2C_FIELD(arg0, void** , 0x3148);
    if ((u32) (arg2 + 1) < 2U) {
        M2C_FIELD(temp_v0_2, s8* , 0x1A) = temp_v0;
        return;
    }
    M2C_FIELD(temp_v0_2, s8* , 0x1B) = temp_v0;
}
//@@ func_001734B8 m2c
#include "m2c_macros.h"
s32 func_001734B8(void* arg0) {
    u8 sp[0x10];
    s32 var_v0;

    var_v0 = 0;
    if (dmeGetMyClientIndex(sp, M2C_FIELD(arg0, s32* , 0x2CF0)) == 0) {
        var_v0 = subroutine_arg0 == func_00173500(arg0);
    }
    return var_v0;
}
//@@ func_00173500 m2c
#include "m2c_macros.h"
s32 func_00173500(void* arg0) {
    u8 sp[0x10];
    s32 temp_v0;

    temp_v0 = func_001733F8();
    if (temp_v0 == 1) {

    } else if (temp_v0 == 2) {
        if (func_00266DE0(sp, M2C_FIELD(arg0, s32* , 0x2CF0)) != 0) {

        }
    }
    return subroutine_arg0;
}
//@@ func_00173570 m2c
#include "m2c_macros.h"
void func_00173570(void* arg0, s32 arg1) {
    M2C_FIELD(arg0, s32* , 0x1BB4) = arg1;
    M2C_FIELD(M2C_FIELD(arg0, void** , 4), s32* , 0x204) = arg1;
    if (M2C_FIELD(arg0, s32* , 0x1BB4) > 0) {
        func_00171B78(-1);
    }
}
//@@ func_001735A8 m2c
#include "m2c_macros.h"
u8 func_001735A8(s32 arg0, s32 arg1, void* arg2) {
    s32 var_s0;
    void* temp_v0;

    var_s0 = M2C_FIELD(arg2, s32* , 0x21B0);
    if (arg1 >= 0) {
        temp_v0 = netGetDmeTime();
        if (temp_v0 != NULL) {
            var_s0 = (s32) M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), u8* , 0x30);
        }
    }
    return (u8) var_s0;
}
//@@ func_00173810 m2c
#include "m2c_macros.h"
void func_00173810(s32 arg0, s32 arg1) {
    s32 var_a1;
    s32 var_s0;
    s32 var_s1;

    var_a1 = arg1;
loop_1:
    var_s1 = 1;
    func_001703E8(arg0, var_a1);
    var_s0 = 0;
    var_a1 = 0;
    do {
        var_s0 += 1;
        var_s1 = (netGetDmeTime(arg0, var_a1) == 0) ? 0 : var_s1;
        var_a1 = var_s0;
    } while (var_s0 < 4);
    if (var_s1 == 0) {
        goto loop_1;
    }
}
//@@ func_00173880 m2c
#include "m2c_macros.h"
extern s32 D_004B1340;
extern s32 D_004B1360;
extern M2C_UNK D_004B1380;
extern s32 D_004FA858;

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
            if (D_004FA858 != 3) {
                M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), void** , 0x20D0), u8* , 0x36) = (u8) M2C_FIELD(arg1, u8* , 5);
                M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), void** , 0x20D0), u8* , 0x37) = (u8) M2C_FIELD(arg1, u8* , 6);
                if (D_004B1360 != 0) {
                    temp_a0 = M2C_FIELD(arg0, void** , 4);
                    temp_a3 = M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_a0, void** , 0xA0), void** , 0x20D0), u8* , 0x35) << 8;
                    var_a1 = 0;
                    if (temp_a3 & 0x100) {
                        if (D_004B1360 == 1) {
                            var_a1 = 0x4000;
                        } else {
                            var_a1 = ((D_004B1360 ^ 2) != 0) ? 0U : 0x4000U;
                        }
                    }
                    if (temp_a3 & 0x200) {
                        temp_v1_2 = (&D_004B1360)[0];
                        if (temp_v1_2 == 1) {
                            var_a1 |= 0x8000;
                        } else if (temp_v1_2 == 2) {
                            var_a1 |= 0x2000;
                        }
                    }
                    if (temp_a3 & 0x400) {
                        temp_v1_3 = (&D_004B1360)[0];
                        if (temp_v1_3 == 1) {
                            var_a1 |= 0x1000;
                        } else if (temp_v1_3 == 2) {
                            var_a1 |= 0x400;
                        }
                    }
                    if (temp_a3 & 0x800) {
                        temp_v1_4 = (&D_004B1360)[0];
                        if (temp_v1_4 == 1) {
                            var_a1 |= 0x2000;
                        } else if (temp_v1_4 == 2) {
                            var_a1 |= 0x800;
                        }
                    }
                    if (temp_a3 & 0x1000) {
                        temp_v1_5 = (&D_004B1360)[0];
                        if (temp_v1_5 == 1) {
                            var_a1 |= 0x400;
                        } else if (temp_v1_5 == 2) {
                            var_a1 |= 0x1000;
                        }
                    }
                    if (temp_a3 & 0x2000) {
                        temp_v1_6 = (&D_004B1360)[0];
                        if (temp_v1_6 == 1) {
                            var_a1 |= 0x800;
                        } else if (temp_v1_6 == 2) {
                            var_a1 |= 0x100;
                        }
                    }
                    if (temp_a3 & 0x4000) {
                        temp_v1_7 = (&D_004B1360)[0];
                        if (temp_v1_7 == 1) {
                            var_a1 |= 0x100;
                        } else if (temp_v1_7 == 2) {
                            var_a1 |= 0x8000;
                        }
                    }
                    if ((temp_a3 & 0x8000) && ((temp_v1_8 = (&D_004B1360)[0], (temp_v1_8 == 1)) || (temp_v1_8 == 2))) {
                        var_a1 |= 0x200;
                    }
                    M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_a0, void** , 0xA0), void** , 0x20D0), s8* , 0x35) = (s8) (var_a1 >> 8);
                }
            } else {
                if (M2C_FIELD(&D_004B1380, s8* , 2) >= 0) {
                    M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), void** , 0x20D0), u8* , 0x36) = (u8) M2C_FIELD(&D_004B1380, s8* , 2);
                } else {
                    if ((u32) ((u8) M2C_FIELD(&D_004B1380, s8* , 2) & 0xFF) >= 0xA0U) {
                        temp_a0_2 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), void** , 0x20D0);
                        M2C_FIELD(temp_a0_2, u8* , 0x35) = (u8) (M2C_FIELD(temp_a0_2, u8* , 0x35) & 0xDF);
                    }
                    M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), void** , 0x20D0), s8* , 0x36) = 0x7F;
                }
                M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), void** , 0x20D0), u8* , 0x37) = (u8) M2C_FIELD(&D_004B1380, u8* , 1);
            }
            if (D_004B1340 == 4) {
                M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), void** , 0x20D0), s8* , 0x36) = 0x88;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), void** , 0x20D0), s8* , 0x37) = 0x88;
                if (D_004B1340 == D_004B1340) {
                    M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), void** , 0x20D0), s8* , 0x36) = 0x88;
                    M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void** , 4), void** , 0xA0), void** , 0x20D0), s8* , 0x37) = 0x88;
                }
            }
        }
    }
    return 1;
}
//@@ func_00173BE8 m2c
#include "m2c_macros.h"
extern s32 D_004F9C9C;

void func_00173BE8(s32 arg0, M2C_UNK arg1) {
    u8 sp[0x50];
    if (D_004F9C9C == 0) {
        netSendGameEvent(arg0, arg1, sp, timerGetCurTics__Fv());
        D_004F9C9C = 1;
    }
}
//@@ func_00173C50 m2c
#include "m2c_macros.h"
extern M2C_UNK D_004E7E70;

void func_00173C50(void* arg0) {
    u8 sp[0x50];
    netGetMyClientIndex();
    if (func_001734B8(arg0) != 0) {
        M2C_FIELD(arg0, s32* , 0x307C) = (s32) subroutine_arg0;
        printf(&D_004E7E70);
        printf(">>>>> 2 Setting ConnectionSessionMaster = %d\n", M2C_FIELD(arg0, s32* , 0x307C));
        printf(&D_004E7E70);
        M2C_FIELD(arg0, s32* , 0x2E8C) = 1;
        netMsgGameEventHandler(M2C_FIELD(arg0, s32* , 0x2CF0), M2C_FIELD(arg0, s32* , 0x129C), netGetMyClientIndex(arg0), sp);
        return;
    }
    netSendGameEvent(arg0, func_00173500(arg0), sp);
}
//@@ func_00173D08 m2c
#include "m2c_macros.h"
extern s32 D_003188E0;

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
    var_s3 = timerGetCurTics__Fv();
    var_s1 = var_s3;
    if (arg1 > 0) {
        var_s4 = arg1 * 0x3E8;
    }
    var_s0 = (s64) (var_s3 << 0x20) >> 0x20;
    netSendGameEvent(arg0, func_00173500(arg0), sp);
    netSendGameEvent(arg0, func_00173500(arg0), sp);
    netSendGameEvent(arg0, func_00173500(arg0), sp);
    var_v0 = 1;
    if (D_003188E0 == 0) {
        func_00173C50(arg0);
        M2C_FIELD(arg0, s32* , 0x2E8C) = 0;
loop_4:
        temp_v0 = timerGetCurTics__Fv();
        if (temp_v0 < var_s0) {
            var_v0_2 = (temp_v0 + 0x10000) - var_s0;
        } else {
            var_v0_2 = temp_v0 - var_s0;
        }
        var_s1 += var_v0_2;
        temp_a0 = var_s1 - var_s3;
        var_s0 = temp_v0;
        if (temp_a0 >= 0) {
            var_f0 = func_001F2CC8(temp_a0);
        } else {
            var_f0 = 2.0f * func_001F2CC8((temp_a0 & 1) | ((u64) temp_a0 >> 1));
        }
        if ((var_f0 / 576.0f) > 5000.0f) {
            var_s4 -= 0x1388;
            var_v0 = 0;
            if (var_s4 >= 0) {
                func_00173C50(arg0);
                var_s3 = timerGetCurTics__Fv();
                var_s1 = var_s3;
                var_s0 = (s64) (var_s3 << 0x20) >> 0x20;
                goto block_13;
            }
        } else {
block_13:
            func_001703E8(arg0);
            var_v0 = 1;
            if (M2C_FIELD(arg0, s32* , 0x2E8C) == 0) {
                goto loop_4;
            }
        }
    }
    return var_v0;
}
//@@ func_00173ED0 m2c
#include "m2c_macros.h"
s32 func_00173ED0(s32 arg0, s32 arg1, s32 arg2) {
    void* temp_v0;

    temp_v0 = netGetDmeTime();
    if (temp_v0 != NULL) {
        M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), s32* , 0x24) = arg2;
        return 1;
    }
    return 0;
}
//@@ func_00173F10 m2c
#include "m2c_macros.h"
s32 func_00173F10(void) {
    void* temp_v0;

    temp_v0 = netGetDmeTime();
    if (temp_v0 != NULL) {
        return M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), s32* , 0x24);
    }
    return 0;
}
//@@ func_00173F40 m2c
#include "m2c_macros.h"
s32 func_00173F40(s32 arg0, s32 arg1, s32 arg2) {
    void* temp_v0;

    temp_v0 = netGetDmeTime();
    if (temp_v0 != NULL) {
        M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), s32* , 0x1C) = arg2;
        return 1;
    }
    return 0;
}
//@@ func_00173F80 m2c
#include "m2c_macros.h"
s32 func_00173F80(s32 arg0, s32 arg1, s32 arg2) {
    void* temp_v0;

    temp_v0 = netGetDmeTime();
    if (temp_v0 != NULL) {
        M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), s32* , 0x20) = arg2;
        return 1;
    }
    return 0;
}
//@@ func_00173FC0 m2c
#include "m2c_macros.h"
s32 func_00173FC0(void) {
    void* temp_v0;

    temp_v0 = netGetDmeTime();
    if (temp_v0 != NULL) {
        return M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), s32* , 0x20);
    }
    return 0;
}
//@@ func_00173FF0 m2c
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
//@@ func_001740B0 m2c
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
//@@ func_001742B0 m2c
#include "m2c_macros.h"
extern s32 D_004FA030;
extern s32 D_004FA03C;

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
    temp_a0 = func_00174268(arg0, var_s3);
    temp_s0 = temp_a0 - 1;
    if ((M2C_FIELD(temp_s1, s32* , 0x10) != -1) && (temp_a1 = M2C_FIELD(temp_s1, s32* , 0xB4), (temp_a1 != -1)) && (temp_v1 = M2C_FIELD(temp_s1, s32* , 0xB8), (temp_v1 != 0))) {
        if (temp_v1 == 1) {
            temp_s0_2 = M2C_FIELD((D_004FA030 + 0x98000 + (temp_s0 * 4)), void** , 0x6670);
            if (temp_s0_2 != NULL) {
                if (M2C_FIELD(temp_s0_2, s32* , 0x20F4) != temp_a1) {
                    memset(temp_s0_2 + 0x10, 0, 0x300);
                    memset(temp_s0_2 + 0x310, 0, 0x174);
                    memset(temp_s0_2 + 0x484, 0, 0x25);
                    memset(temp_s0_2 + 0x4B0, 0, 0xE0);
                    memset(temp_s0_2 + 0x5C0, 0, 0x14E0);
                    memset(temp_s0_2 + 0x1AA0, 0, 0x490);
                    memset(temp_s0_2 + 0x21B0, 0, 0xD90);
                    temp_a0_2 = M2C_FIELD(temp_s0_2, void** , 0x2010);
                    if (temp_a0_2 != NULL) {
                        memset(temp_a0_2, 0, 0x7E4);
                    }
                    temp_a0_3 = M2C_FIELD(temp_s0_2, void** , 0x2014);
                    if (temp_a0_3 != NULL) {
                        memset(temp_a0_3, 0, 0x630);
                    }
                    temp_a0_4 = M2C_FIELD(temp_s0_2, void** , 0x2018);
                    if (temp_a0_4 != NULL) {
                        memset(temp_a0_4, 0, 0x2C0);
                    }
                    temp_a0_5 = M2C_FIELD(temp_s0_2, void** , 0x201C);
                    if (temp_a0_5 != NULL) {
                        memset(temp_a0_5, 0, 0x30);
                    }
                    temp_a0_6 = M2C_FIELD(temp_s0_2, void** , 0x2020);
                    if (temp_a0_6 != NULL) {
                        memset(temp_a0_6, 0, 0x70);
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
            func_001FE0B8(func_00174268(arg0, var_s3));
            func_001703E8(arg0);
            func_001890F0(D_004FA03C, var_s3);
            M2C_FIELD(((var_s3 * 0x220) + arg0), s32* , 0xB8) = 2;
            goto block_24;
        }
        var_s3 = temp_s6;
        if (func_0018A480(temp_a0, temp_a1) != 0) {
            var_v0_3 = var_s3 < 8;
            if (M2C_FIELD(temp_s1, s32* , 0xB8) == 2) {
                func_001703E8(arg0);
                vehicleDisable__7Vehicle(M2C_FIELD((D_004FA030 + 0x98000 + (temp_s0 * 4)), s32* , 0x6670));
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
//@@ func_00174598 m2c
#include "m2c_macros.h"
void func_00174598(void* arg0) {
    s32 temp_s1;
    s32 var_v0;
    void* var_s0;

    var_s0 = arg0;
    temp_s1 = var_s0 + 0x1100;
    var_v0 = M2C_FIELD(var_s0, s32* , 0x10);
loop_1:
    if (var_v0 == -1) {
        M2C_FIELD(var_s0, s32* , 0xB4) = (s32) (mathfRand__Fii(1, 0xE) << 5);
    }
    var_s0 += 0x220;
    if ((s32) var_s0 < temp_s1) {
        var_v0 = M2C_FIELD(var_s0, s32* , 0x10);
        goto loop_1;
    }
}
//@@ func_00174608 m2c
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
//@@ func_001746E8 m2c
#include "m2c_macros.h"
extern s32 D_004F9F70;
extern s32 D_004F9F74;
extern void* D_004FA030;

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
    M2C_FIELD(D_004FA030, s32* , 0x9FD9C) = 1;
    do {
        *var_s1 = 0;
        temp_a1 = var_s2_2;
        var_s2_2 += 1;
        func_0016F1C8(arg0, temp_a1);
        var_s1 += 4;
    } while (var_s2_2 < 8);
    M2C_FIELD(arg0, s32* , 0x3010) = 0;
    D_004F9F70 = 0;
    D_004F9F74 = 0;
}
//@@ func_00174860 m2c
#include "m2c_macros.h"
void func_00174860(void* arg0) {
    s32 var_s2;
    void* var_s0;

    var_s2 = 7;
    M2C_FIELD(arg0, s32* , 4) = (s32) (arg0 + 0x1990);
    var_s0 = arg0 + 0x10;
    do {
        var_s2 -= 1;
        func_0016E8E0(var_s0);
        var_s0 += 0x220;
    } while (var_s2 >= 0);
    M2C_FIELD(arg0, s32* , 0x1BB4) = 0;
    M2C_FIELD(arg0, s32* , 0x2CF0) = -1;
    M2C_FIELD(arg0, s32* , 0x307C) = -0x63;
    func_00174910(arg0);
}
//@@ func_001748D8 m2c
#include "m2c_macros.h"
extern s32 D_004FA030;

void func_001748D8(s32 arg0) {
    func_001746E8();
    func_00174860(arg0);
    InitTypeOfVehicles__7TheGame(D_004FA030);
}
//@@ func_00174BF0 m2c
#include "m2c_macros.h"
extern s32 D_004F9CA8;
extern s32 D_004F9CAC;
extern s32 D_004FA03C;

void func_00174BF0(void* arg0) {
    M2C_UNK sp10;
    s32 temp_s1;
    s32 temp_s1_2;

    if (func_001734B8() != 0) {
        if (D_004F9CAC == -1) {

        } else {
            temp_s1 = M2C_FIELD(arg0, s32* , 0x3218);
            if (temp_s1 == -1) {
                *(D_004FA03C + 0x1A3C8 + (*M2C_FIELD(arg0, s32** , 4) * 4)) = (s32) M2C_FIELD(arg0, u8* , 0x3085);
                if (func_0026BD50(arg0 + 0x3218, 1, 3, 0) == 0) {
                    M2C_FIELD(arg0, void** , 0x3148) = (void* ) M2C_FIELD(netGetDmeTime(arg0, M2C_FIELD(arg0, s32* , 0x3218)), void** , 0x1C);
                } else {
                    M2C_FIELD(arg0, s32* , 0x3218) = temp_s1;
                }
            }
        }
        if (D_004F9CA8 != -1) {
            temp_s1_2 = M2C_FIELD(arg0, s32* , 0x2F00);
            if (temp_s1_2 == -1) {
                memset(&sp10, 0, 0xA0);
                M2C_FIELD(M2C_FIELD(arg0, void** , 0x3148), s8* , 0x24) = 1;
                if (func_0026BD50(arg0 + 0x2F00, 1, 3, 0) == 0) {
                    M2C_FIELD(arg0, s32* , 0x2F04) = (s32) M2C_FIELD(netGetDmeTime(arg0, M2C_FIELD(arg0, s32* , 0x2F00)), s32* , 0x1C);
                } else {
                    M2C_FIELD(arg0, s32* , 0x2F00) = temp_s1_2;
                    M2C_FIELD(arg0, s32* , 0x2F04) = 0;
                }
            }
        }
    }
}
//@@ func_00174D58 m2c
#include "m2c_macros.h"
extern M2C_UNK D_00320E80;

s32 func_00174D58(void* arg0) {
    return *((M2C_FIELD(M2C_FIELD(arg0, void** , 0x3148), s32* , 0x20) * 4) + &D_00320E80);
}
//@@ func_00175588 m2c
#include "m2c_macros.h"
extern void* D_004FA030;

s32 func_00175588(s32 arg0, s32 arg1) {
    s32 var_a1;
    s32 var_s0;
    s32* var_s1;

    var_s0 = arg1;
    var_a1 = 2;
    if ((M2C_FIELD(D_004FA030, s32* , 0x9E690) == 0) || (M2C_FIELD(D_004FA030, s32* , 0x9E694) == 0)) {
        if (var_s0 == -1) {
            var_s0 = 0;
            var_s1 = arg0 + 0x214;
loop_6:
            if (var_s0 < 8) {
                if (*var_s1 != 0) {
                    var_s1 += 0x220;
                    goto block_5;
                }
                var_a1 = func_00174268(arg0, var_s0) - 1;
                var_s1 += 0x220;
                if (M2C_FIELD(M2C_FIELD((D_004FA030 + 0x98000 + (var_a1 * 4)), void** , 0x6670), s32* , 0x20D0) == 0) {

                } else {
block_5:
                    var_s0 += 1;
                    goto loop_6;
                }
            }
        }
        func_001756A0(arg0, func_0013A7B8(D_004FA030, var_a1, M2C_FIELD(((var_s0 * 0x220) + arg0), s32* , 0xB4), var_a1));
    }
    return 1;
}
//@@ func_001756A0 m2c
#include "m2c_macros.h"
extern M2C_UNK D_0041BF00;
extern M2C_UNK D_004E8528;
extern s32 D_004F9CA4;
extern s32 D_004F9CB0;
extern s32 D_004F9D18;
extern void* D_004FA030;

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
            if (arg1 == (D_004FA030 + var_v1)) {
                var_s4 = func_00177028(var_s2 + 1);
            } else {
                var_s2 += 1;
                goto loop_3;
            }
        }
        if (M2C_FIELD(arg1, void*** , 0x20D0) == NULL) {
            var_s2 = 0;
            memset(&sp10, 0, 0x38);
            sp3E = 2;
            sp38 = M2C_FIELD(arg1, u16* , 0x20F4);
            if (arg1 == M2C_FIELD(D_004FA030, s32* , 0x9E690)) {
                sp3F = 0;
            } else {
loop_10:
                var_s2 += 1;
                if (var_s2 < 2) {
                    if (arg1 == *(D_004FA030 + 0x9E690 + (var_s2 * 4))) {
                        sp3F = var_s2;
                    } else {
                        goto loop_10;
                    }
                }
            }
            sp43 = var_s4;
            if (func_0026BD50(arg1 + 0x20C4, 1, 3, 0) != 0) {
                M2C_FIELD(arg1, s32* , 0x20B8) = -1;
                M2C_FIELD(arg1, s32* , 0x20C4) = -1;
            } else {
                temp_v1 = M2C_FIELD(netGetDmeTime(arg0, M2C_FIELD(arg1, s32* , 0x20C4)), void*** , 0x1C);
                M2C_FIELD(arg1, void*** , 0x20D0) = temp_v1;
                *temp_v1 = arg1;
            }
        }
        if (M2C_FIELD(arg1, void** , 0x20D4) == NULL) {
            memset(&sp50, 0, 0x18);
            func_00109810(arg1, &sp50);
            sp62 = M2C_FIELD(arg1, u16* , 0x20F4);
            sp60 = 2;
            sp61 = var_s2;
            sp64 = (s16) var_s4;
            if (func_0026BD50(arg1 + 0x20C8, 1, 3, 0) != 0) {
                M2C_FIELD(arg1, void** , 0x20D4) = NULL;
                M2C_FIELD(arg1, s32* , 0x20C8) = -1;
            } else {
                temp_v1_2 = M2C_FIELD(netGetDmeTime(arg0, M2C_FIELD(arg1, s32* , 0x20C8)), void** , 0x1C);
                M2C_FIELD(arg1, void** , 0x20D4) = temp_v1_2;
                M2C_FIELD(temp_v1_2, void** , 0xC) = arg1;
            }
        }
        if (M2C_FIELD(arg1, s32* , 0x20D8) == 0) {
            memset(&sp70, 0, 0x58);
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
            if (func_0026BD50(arg1 + 0x20CC, 1, 3, 0) != 0) {
                M2C_FIELD(arg1, s32* , 0x20D8) = 0;
                M2C_FIELD(arg1, s32* , 0x20CC) = -1;
            } else {
                M2C_FIELD(arg1, s32* , 0x20D8) = (s32) M2C_FIELD(netGetDmeTime(arg0, M2C_FIELD(arg1, s32* , 0x20CC)), s32* , 0x1C);
            }
        }
    }
    return 1;
}
//@@ func_001759D8 m2c
#include "m2c_macros.h"
void func_001759D8(s32 arg0, void* arg1) {
    s32* temp_v0;
    void* temp_v0_2;

    if (arg1 != NULL) {
        temp_v0 = M2C_FIELD(arg1, s32** , 0x20D0);
        if (temp_v0 != NULL) {
            *temp_v0 = 0;
            if (func_001734B8() != 0) {
                func_00268260(M2C_FIELD(arg1, s32* , 0x20C4));
            }
            M2C_FIELD(arg1, s32** , 0x20D0) = NULL;
            M2C_FIELD(arg1, s32* , 0x20C4) = -1;
        }
        temp_v0_2 = M2C_FIELD(arg1, void** , 0x20D4);
        if (temp_v0_2 != NULL) {
            M2C_FIELD(temp_v0_2, s32* , 0xC) = 0;
            if (func_001734B8(arg0) != 0) {
                func_00268260(M2C_FIELD(arg1, s32* , 0x20C8));
            }
            M2C_FIELD(arg1, void** , 0x20D4) = NULL;
            M2C_FIELD(arg1, s32* , 0x20C8) = -1;
        }
        if (M2C_FIELD(arg1, s32* , 0x20D8) != 0) {
            if (func_001734B8(arg0) != 0) {
                func_00268260(M2C_FIELD(arg1, s32* , 0x20CC));
            }
            M2C_FIELD(arg1, s32* , 0x20D8) = 0;
            M2C_FIELD(arg1, s32* , 0x20CC) = -1;
        }
    }
}
//@@ func_001761E8 m2c
#include "m2c_macros.h"
extern M2C_UNK D_003156C0;
extern void* D_004FA030;

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
    if (M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 0x3148), u32* , 8) == 0) {
        goto block_13;
    }
    temp_s4 = (u32) M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 0x3148), u32* , 0x2C) / 60U;
    M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 0x3148), u32* , 0x2C) = (u32) (M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 0x3148), u32* , 0x2C) - timerGetFieldsLastFrame__Fv());
    temp_lo = (u32) M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 0x3148), u32* , 0x2C) / 60U;
    if (M2C_FIELD(D_004FA030, s32* , 0x9FD9C) != 0) {
        goto block_4;
    }
    if (temp_lo == temp_s4) {
        goto block_4;
    }
    func_001A94C0(temp_lo, 0x98000, 0x3C);
block_4:
    temp_v1 = M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 0x3148), u32* , 0x2C);
    if (temp_v1 == 0) {
        goto block_6;
    }
    if ((u32) M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 0x3148), u32* , 8) >= temp_v1) {
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
    M2C_FIELD(temp_a1_2, s32* , 8) = (s32) (M2C_FIELD(temp_a1_2, s32* , 8) + timerGetFieldsLastFrame__Fv(&D_003156C0, temp_a1));
block_11:
block_12:
    func_00174D78(&D_003156C0, 1, 0);
block_13:
block_14:
    if (M2C_FIELD(&D_003156C0, s32* , 0x3220) == 0) {
        goto block_25;
    }
    if (M2C_FIELD(&D_003156C0, s32* , 0x322C) != 0xB4) {
        goto block_25;
    }
    var_a2 = 0;
    if (M2C_FIELD(D_004FA030, s32* , 0x20D8) == 0) {
        goto loop_19;
    }
    var_v0 = M2C_FIELD(D_004FA030, s32* , 0x20B4);
    goto block_22;
loop_19:
    var_a2 += 1;
    if (var_a2 >= 8) {
        goto block_23;
    }
    temp_v0 = (var_a2 * 0x31B0) + D_004FA030;
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
    func_00174D78(&D_003156C0, 0, 0);
block_25:
    temp_v1_2 = M2C_FIELD(arg0, s32* , 0x322C);
    if (temp_v1_2 >= 0xB4) {
        goto block_27;
    }
    M2C_FIELD(arg0, s32* , 0x322C) = (s32) (temp_v1_2 + 1);
block_27:
    if (M2C_FIELD(&D_003156C0, s32* , 0x3220) == 0) {
        goto block_29;
    }
    if (M2C_FIELD(arg0, s32* , 0x322C) != 0xB4) {
        goto block_53;
    }
block_29:
    var_a2_2 = 0;
    var_a3 = D_004FA030 + 0x2104;
loop_30:
    if (M2C_FIELD(var_a3, s32* , -0x2C) == 0) {
        goto block_47;
    }
    if (M2C_FIELD(&D_003156C0, u16* , 0x3098) == 0) {
        goto block_34;
    }
    if (M2C_FIELD((&D_003156C0 + (var_a2_2 * 4)), s32* , 0x2F28) < (s32) M2C_FIELD(&D_003156C0, u16* , 0x3098)) {
        goto block_35;
    }
    func_00174D78(&D_003156C0, 2, 0, var_a3);
    goto block_52;
block_34:
block_35:
    if (M2C_FIELD(&D_003156C0, s32* , 0x308C) == 0) {
        goto block_38;
    }
    if (M2C_FIELD((&D_003156C0 + (var_a2_2 * 4)), s32* , 0x2F88) < M2C_FIELD(&D_003156C0, s32* , 0x308C)) {
        goto block_38;
    }
    var_a1 = 4;
    goto block_42;
block_38:
    if (M2C_FIELD(&D_003156C0, s32* , 0x3090) == 0) {
        goto block_43;
    }
    temp_v0_2 = M2C_FIELD((&D_003156C0 + (var_a2_2 * 4)), s32* , 0x2FC8);
    if (temp_v0_2 == 0xF4240) {
        goto block_43;
    }
    if (temp_v0_2 < M2C_FIELD(&D_003156C0, s32* , 0x3090)) {
        goto block_44;
    }
    var_a1 = 7;
block_42:
    func_00174D78(&D_003156C0, var_a1, 0, var_a3);
    goto block_52;
block_43:
block_44:
    if (M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 0x3148), u8* , 5) == 0) {
        goto block_46;
    }
    if (M2C_FIELD((&D_003156C0 + (M2C_FIELD(var_a3, s32* , 0) * 4)), s32* , 0x2F48) >= (s32) M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 0x3148), u8* , 5)) {
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
    if (!(M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 0x3148), s32* , 0) & 1)) {
        goto block_52;
    }
    if ((((s64) (M2C_FIELD(&D_003156C0, s64* , 0x3080) << 0x1F) >> 0x20) & 0xF) != 3) {
        goto block_53;
    }
    if (var_s5 >= 2) {
        goto block_53;
    }
    func_00174D78(&D_003156C0, 3, 0, var_a3);
block_52:
block_53:
    return;
}
//@@ func_00176B10 m2c
#include "m2c_macros.h"
extern M2C_UNK D_003156C0;

s32 func_00176B10(void* arg0, s32 arg1) {
    u8 sp[0x10];
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s2;
    s32* var_a0;
    s32* var_s1;
    s32* var_v1;

    var_s2 = 0;
    if (func_001733F8(&D_003156C0) != 1) {
        var_s0 = 0;
        var_s1 = arg0 + 0xC8;
        do {
            func_00264AE0(sp, M2C_FIELD(arg0, s32* , 0x2CF0), var_s0);
            if ((subroutine_arg0 == 2) && ((*var_s1 == 0) || (arg1 != 0))) {
                var_s2 += 1;
            }
            var_s0 += 1;
            var_s1 += 0x220;
        } while (var_s0 < 8);
    } else {
        var_v1 = &D_003156C0 + 0x214;
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
//@@ func_00176C20 m2c
#include "m2c_macros.h"
s8 func_00176C20(void* arg0) {
    u8 sp[0x10];
    s32 var_s0;
    s8 var_s1;

    var_s1 = 0;
    var_s0 = 0;
loop_1:
    func_00264AE0(sp, M2C_FIELD(arg0, s32* , 0x2CF0), var_s0);
    if (subroutine_arg0 == 2) {
        var_s1 |= 1 << var_s0;
    }
    var_s0 += 1;
    if (var_s0 < 8) {
        goto loop_1;
    }
    printf("GetPlayersJoinedList = 0x%x\n", var_s1);
    return var_s1;
}
//@@ func_00176CC8 m2c
#include "m2c_macros.h"
extern M2C_UNK D_003156C0;
extern M2C_UNK D_004E7E70;

s32 func_00176CC8(void* arg0) {
    u8 sp[0x10];
    s32 temp_s2;
    s32 temp_v0;
    void* temp_a0;
    void* temp_a0_2;
    void* temp_a1;
    void* temp_v1;

    temp_s2 = netGetMyClientIndex(&D_003156C0);
    if (func_002663F0(M2C_FIELD(arg0, s32* , 0x2CF0), sp) == 0) {
        M2C_FIELD(arg0, s32* , 0x307C) = (s32) subroutine_arg0;
        if (subroutine_arg0 == temp_s2) {
            if (func_00176B10(&D_003156C0, 1) <= 0) {
                M2C_FIELD(&D_003156C0, s32* , 0x1BB0) = (s32) M2C_FIELD(&D_003156C0, s32* , 0x1BB4);
                if (M2C_FIELD(&D_003156C0, s32* , 0x1BB4) >= 9) {
                    M2C_FIELD(&D_003156C0, s32* , 0x1BB0) = 8;
                }
            }
            if (M2C_FIELD(&D_003156C0, s32* , 0x1BB4) < 0xA) {
                *M2C_FIELD(&D_003156C0, u32** , 0x3148) &= ~1;
            }
            M2C_FIELD(arg0, s32* , 0x307C) = temp_s2;
            printf(&D_004E7E70);
            printf(">>>>> 3 Setting ConnectionSessionMaster = %d\n\0BASCUS-97196\0\0\0 !\"#$%&'()*+,-.0123456789:;<=>?ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_abcdefghijklmnopqrstuvwxyz{}\0\00123456789\0\0 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\0 .0123456789\0\\PTS\\PEDANIM.CFG;1", M2C_FIELD(arg0, s32* , 0x307C));
            printf(&D_004E7E70);
            temp_v0 = ((u32) *M2C_FIELD(&D_003156C0, u32** , 0x3148) >> 1) & 0xF;
            if (temp_v0 == 1) {
                M2C_FIELD(&D_003156C0, s32* , 0x1BB0) = temp_v0;
                memset(M2C_FIELD(arg0, void** , 0x3148), 0, 0xC8);
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
            func_00174988(&D_003156C0, -1);
            return 1;
        }
        return 0;
    }
    M2C_FIELD(arg0, s32* , 0x307C) = -1;
    return 0;
}
//@@ func_00176EA0 m2c
#include "m2c_macros.h"
extern u32* D_00318808;
extern void* D_004FA030;

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

    temp_v1 = *D_00318808;
    var_s0 = 0;
    if ((temp_v1 >> 0xD) & 1) {
        if (((temp_v1 >> 1) & 0xF) != 1) {
            if (func_001734B8() != 0) {
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
                        temp_v0_2 = D_004FA030;
                        if (M2C_FIELD(D_004FA030, s32* , 0x9E690) == 0) {
                            func_00175588(arg0, -1);
                        }
                        if (M2C_FIELD(temp_v0_2, s32* , 0x9E694) == 0) {
                            goto block_16;
                        }
                    } else {
                        var_v0 = var_s0 < 3;
                        if (var_s0 == 2) {
                            if (M2C_FIELD(D_004FA030, s32* , 0x9E690) != 0) {
                                var_v0 = var_s0 < 3;
                                goto block_17;
                            }
                            var_v0 = var_s0 < 3;
                            if (M2C_FIELD(D_004FA030, s32* , 0x9E694) == 0) {
block_16:
                                func_00175588(arg0, -1);
                            } else {
                                goto block_17;
                            }
                        } else {
block_17:
                            if (var_v0 == 0) {
                                temp_a0 = D_004FA030;
                                var_v0_2 = temp_a0 + 0x98000;
                                temp_a1 = M2C_FIELD(temp_a0, s32* , 0x9E690);
                                if (temp_a1 != 0) {
                                    func_0013EED0(temp_a0, temp_a1);
                                    var_v0_2 = D_004FA030 + 0x98000;
                                }
                                temp_a1_2 = M2C_FIELD(var_v0_2, s32* , 0x6694);
                                if (temp_a1_2 != 0) {
                                    func_0013EED0(temp_a0, temp_a1_2);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
