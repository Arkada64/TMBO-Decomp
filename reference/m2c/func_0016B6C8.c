M2C_UNK func_00111978(void*, void*, M2C_UNK, s32);  /* extern */
M2C_UNK func_00111980(void*, M2C_UNK, void*, void*); /* extern */
M2C_UNK func_00129A70(s32, void*, M2C_UNK, s32);    /* extern */
M2C_UNK func_00132D18(void*, void*, M2C_UNK, s32);  /* extern */
M2C_UNK func_00133028(void*, void*, void*);         /* extern */
M2C_UNK func_00141A38(void*, M2C_UNK, void*);       /* extern */
M2C_UNK func_00141AB8(void*, void*, M2C_UNK, s32);  /* extern */
M2C_UNK func_00141D90(void*, s32, void*, M2C_UNK);  /* extern */
s32 func_001734B8(M2C_UNK*, void*);                 /* extern */
void* func_00174248(M2C_UNK*);                      /* extern */
M2C_UNK hierSetSwitch__FP11_hierswitchi(s32, M2C_UNK); /* extern */
M2C_UNK killBall__8LoopTank(void*, M2C_UNK);        /* extern */
extern M2C_UNK D_003156C0;
extern s32 D_004F9CD0;
extern s32 D_004F9CD4;
extern void* D_004FA030;

void func_0016B6C8(s32 arg0, s32 arg1, s32 arg2) {
    M2C_UNK var_a2;
    f32 var_f0;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_a0_9;
    s32 temp_a1_3;
    s32 temp_v1;
    s32 temp_v1_10;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 temp_v1_6;
    s32 var_a0;
    void* temp_a0;
    void* temp_a0_10;
    void* temp_a0_11;
    void* temp_a0_12;
    void* temp_a0_13;
    void* temp_a0_14;
    void* temp_a0_15;
    void* temp_a0_2;
    void* temp_a0_5;
    void* temp_a0_6;
    void* temp_a0_7;
    void* temp_a0_8;
    void* temp_a1;
    void* temp_a1_2;
    void* temp_s1;
    void* temp_v0;
    void* temp_v0_2;
    void* temp_v0_3;
    void* temp_v1_11;
    void* temp_v1_12;
    void* temp_v1_13;
    void* temp_v1_14;
    void* temp_v1_7;
    void* temp_v1_8;
    void* temp_v1_9;
    void* var_v0;
    void* var_v0_2;

    M2C_ERROR(/* unknown instruction: por $v0, $zero, $zero */);
    temp_s1 = func_00174248(&D_003156C0);
    if ((arg0 != 0x100) && (temp_s1 != NULL)) {
        temp_v0 = M2C_FIELD(temp_s1, void** , 0x1C);
        temp_v1 = M2C_FIELD(temp_v0, s32* , 0);
        switch (temp_v1) {
        case 4:
            if ((M2C_FIELD(&D_003156C0, s32* , 0x2EA4) != 0) && (func_001734B8(&D_003156C0, temp_v0) == 0)) {
                var_a0 = M2C_FIELD(&D_003156C0, s32* , 0x2EA4);
                var_a2 = 0x190;
                var_v0 = M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 4), void** , 0xA0);
block_58:
                func_00129A70(var_a0, sp, var_a2, M2C_FIELD(var_v0, s32* , 0x20FC));
            }
            break;
        case 5:
            temp_v1_2 = M2C_FIELD(temp_v0, s32* , 0x24);
            if (temp_v1_2 == 1) {
                temp_a0 = &D_003156C0 + 0x56C0;
                if (M2C_FIELD(temp_a0, s32* , 0x2ED8) == 0) {
                    M2C_FIELD(temp_a0, s32* , 0x2ED8) = temp_v1_2;
                    return;
                }
                return;
            }
            break;
        case 6:
            temp_a1 = &D_003156C0 + 0x56C0;
            M2C_FIELD(D_004FA030, s32* , 0x96844) = (s32) M2C_FIELD(temp_v0, s32* , 0x20);
            temp_a0_2 = M2C_FIELD(temp_s1, void** , 0x1C);
            temp_v1_3 = M2C_FIELD(temp_a0_2, s32* , 0x24);
            if (M2C_FIELD(temp_a1, s32* , 0x2EB8) != temp_v1_3) {
                switch (temp_v1_3) {                /* switch 1; irregular */
                case 1:                             /* switch 1 */
                    M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x96840), f32* , 0x10) = (f32) M2C_FIELD(temp_a0_2, f32* , 4);
                    M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x96840), f32* , 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x1C), f32* , 8);
                    M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x96840), f32* , 0x18) = (f32) M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x1C), f32* , 0xC);
                    M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x96840), f32* , 0x60) = (f32) M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x1C), f32* , 0x10);
                    M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x96840), f32* , 0x64) = (f32) M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x1C), f32* , 0x14);
                    M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x96840), f32* , 0x68) = (f32) M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x1C), f32* , 0x18);
                    func_00111980(D_004FA030 + 0x96810, 1, D_004FA030 + 0x90000, D_004FA030);
                    break;
                case 3:                             /* switch 1 */
                    func_00111978(D_004FA030 + 0x96810, sp, 0x1F4, M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_a1, void** , 4), void** , 0xA0), s32* , 0x20FC));
                    break;
                case 2:                             /* switch 1 */
                    M2C_FIELD(D_004FA030, s32* , 0x96814) = 0;
                    M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x96840), s8* , 0xC) = 0;
                    break;
                }
                M2C_FIELD((&D_003156C0 + 0x56C0), s32* , 0x2EB8) = (s32) M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x1C), s32* , 0x24);
            }
            break;
        case 7:
            temp_a0_3 = M2C_FIELD(D_004FA030, s32* , 0x962F4);
            if (temp_a0_3 != M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x1C), s32* , 0x20)) {
                M2C_FIELD(D_004FA030, s32* , 0x962F8) = temp_a0_3;
            }
            temp_a1_2 = &D_003156C0 + 0x56C0;
            M2C_FIELD(D_004FA030, s32* , 0x962F4) = (s32) M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x1C), s32* , 0x20);
            temp_v1_4 = M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x1C), s32* , 0x24);
            if (M2C_FIELD(temp_a1_2, s32* , 0x2EC4) != temp_v1_4) {
                switch (temp_v1_4) {                /* switch 2; irregular */
                case 3:                             /* switch 2 */
                    func_00132D18(D_004FA030 + 0x96260, sp, 0x1F4, M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_a1_2, void** , 4), void** , 0xA0), s32* , 0x20FC));
                    break;
                case 1:                             /* switch 2 */
                    func_00133028(D_004FA030 + 0x96260, temp_a1_2, D_004FA030);
                    M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x962F0), f32* , 0x10) = (f32) M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x1C), f32* , 4);
                    M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x962F0), f32* , 0x14) = (f32) M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x1C), f32* , 8);
                    M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x962F0), f32* , 0x18) = (f32) M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x1C), f32* , 0xC);
                    M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x962F0), f32* , 0x60) = (f32) M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x1C), f32* , 0x10);
                    M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x962F0), f32* , 0x64) = (f32) M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x1C), f32* , 0x14);
                    M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x962F0), f32* , 0x68) = (f32) M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x1C), f32* , 0x18);
                    break;
                case 2:                             /* switch 2 */
                    M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x962F0), s8* , 0xC) = 0;
                    break;
                }
                M2C_FIELD((&D_003156C0 + 0x56C0), s32* , 0x2EC4) = (s32) M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x1C), s32* , 0x24);
            }
            break;
        case 8:
            temp_v1_5 = M2C_FIELD(temp_v0, s32* , 0x24);
            switch (temp_v1_5) {                    /* switch 3; irregular */
            case 3:                                 /* switch 3 */
                M2C_FIELD(D_004FA030, s32* , 0x968C4) = 1;
                return;
            case 2:                                 /* switch 3 */
                if (M2C_FIELD(D_004FA030, s32* , 0x968C4) == 0) {
                    M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x96944), s8* , 0xC) = 0;
                    M2C_FIELD(D_004FA030, s32* , 0x968C4) = 0;
                    hierSetSwitch__FP11_hierswitchi(M2C_FIELD(D_004FA030, s32* , 0x96940), 2);
                }
                break;
            }
            break;
        case 9:
            temp_v1_6 = M2C_FIELD(temp_v0, s32* , 0x24);
            switch (temp_v1_6) {                    /* switch 4; irregular */
            case 3:                                 /* switch 4 */
                M2C_FIELD(D_004FA030, s32* , 0x96954) = 1;
                return;
            case 2:                                 /* switch 4 */
                if (M2C_FIELD(D_004FA030, s32* , 0x96954) == 0) {
                    M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x969D4), s8* , 0xC) = 0;
                    M2C_FIELD(D_004FA030, s32* , 0x96954) = 0;
                    hierSetSwitch__FP11_hierswitchi(M2C_FIELD(D_004FA030, s32* , 0x969D0), 2);
                }
                break;
            }
            break;
        case 10:
            temp_a0_4 = M2C_FIELD(temp_v0, s32* , 0x24);
            switch (temp_a0_4) {                    /* switch 5; irregular */
            case 1:                                 /* switch 5 */
                M2C_FIELD((D_004FA030 + 0x3EAC0), s32* , 4) = temp_a0_4;
                break;
            case 3:                                 /* switch 5 */
                killBall__8LoopTank(D_004FA030 + 0x3EAC0, 1);
                if (M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x1C), s32* , 0x1C) == -1) {
                    temp_v0_2 = &D_003156C0 + 0x56C0;
                    var_a2 = 0x1F4;
                    var_a0 = M2C_FIELD(temp_v0_2, s32* , 0x2EC8);
                    var_v0 = M2C_FIELD(M2C_FIELD(temp_v0_2, void** , 4), void** , 0xA0);
                    goto block_58;
                }
                break;
            }
            break;
        case 11:
            if (arg2 == D_004F9CD0) {
                temp_v1_7 = M2C_FIELD(temp_s1, void** , 0x1C);
                M2C_FIELD(M2C_FIELD((D_004FA030 + (M2C_FIELD(temp_v1_7, s32* , 0x28) * 0x110)), void** , 0x95FC8), f32* , 0x10) = (f32) M2C_FIELD(temp_v1_7, f32* , 4);
                temp_a0_5 = M2C_FIELD(temp_s1, void** , 0x1C);
                M2C_FIELD(M2C_FIELD(((M2C_FIELD(temp_a0_5, s32* , 0x28) * 0x110) + D_004FA030), void** , 0x95FC8), f32* , 0x14) = (f32) M2C_FIELD(temp_a0_5, f32* , 8);
                temp_a0_6 = M2C_FIELD(temp_s1, void** , 0x1C);
                M2C_FIELD(M2C_FIELD(((M2C_FIELD(temp_a0_6, s32* , 0x28) * 0x110) + D_004FA030), void** , 0x95FC8), f32* , 0x18) = (f32) M2C_FIELD(temp_a0_6, f32* , 0xC);
            } else {
                temp_v1_8 = M2C_FIELD(temp_s1, void** , 0x1C);
                if (arg2 == D_004F9CD4) {
                    M2C_FIELD(M2C_FIELD((D_004FA030 + (M2C_FIELD(temp_v1_8, s32* , 0x28) * 0x110)), void** , 0x95FC8), f32* , 0x60) = (f32) M2C_FIELD(temp_v1_8, f32* , 0x10);
                    temp_a0_7 = M2C_FIELD(temp_s1, void** , 0x1C);
                    M2C_FIELD(M2C_FIELD(((M2C_FIELD(temp_a0_7, s32* , 0x28) * 0x110) + D_004FA030), void** , 0x95FC8), f32* , 0x64) = (f32) M2C_FIELD(temp_a0_7, f32* , 0x14);
                    temp_a0_8 = M2C_FIELD(temp_s1, void** , 0x1C);
                    var_f0 = M2C_FIELD(temp_a0_8, f32* , 0x18);
                    var_v0_2 = (M2C_FIELD(temp_a0_8, s32* , 0x28) * 0x110) + D_004FA030 + 0x90000;
                    goto block_76;
                }
                M2C_FIELD((D_004FA030 + (M2C_FIELD(temp_v1_8, s32* , 0x28) * 0x110)), s32* , 0x9601C) = arg1;
                temp_v1_9 = M2C_FIELD(temp_s1, void** , 0x1C);
                temp_v0_3 = (M2C_FIELD(temp_v1_9, s32* , 0x28) * 0x110) + D_004FA030;
                temp_v1_10 = M2C_FIELD(temp_v0_3, s32* , 0x95FCC);
                if (temp_v1_10 != M2C_FIELD(temp_v1_9, s32* , 0x20)) {
                    M2C_FIELD(temp_v0_3, s32* , 0x95FD0) = temp_v1_10;
                    temp_v1_11 = M2C_FIELD(temp_s1, void** , 0x1C);
                    M2C_FIELD(((M2C_FIELD(temp_v1_11, s32* , 0x28) * 0x110) + D_004FA030), s32* , 0x95FCC) = (s32) M2C_FIELD(temp_v1_11, s32* , 0x20);
                    func_00141A38(D_004FA030 + ((M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x1C), s32* , 0x28) * 0x110) + 0x95F20), 0x95F20, D_004FA030);
                }
                temp_v1_12 = M2C_FIELD(temp_s1, void** , 0x1C);
                temp_a0_9 = M2C_FIELD(temp_v1_12, s32* , 0x24);
                temp_a1_3 = M2C_FIELD(temp_v1_12, s32* , 0x28) * 0x110;
                temp_v1_13 = D_004FA030 + temp_a1_3;
                if (M2C_FIELD(temp_v1_13, s32* , 0x96020) != temp_a0_9) {
                    switch (temp_a0_9) {            /* switch 6; irregular */
                    case 4:                         /* switch 6 */
                        M2C_FIELD(temp_v1_13, s8* , 0x95F26) = 2;
                        break;
                    case 1:                         /* switch 6 */
                        func_00141D90(D_004FA030 + (temp_a1_3 + 0x95F20), temp_a1_3, D_004FA030, 2);
                        temp_v1_14 = M2C_FIELD(temp_s1, void** , 0x1C);
                        M2C_FIELD(M2C_FIELD((D_004FA030 + (M2C_FIELD(temp_v1_14, s32* , 0x28) * 0x110)), void** , 0x95FC8), f32* , 0x10) = (f32) M2C_FIELD(temp_v1_14, f32* , 4);
                        temp_a0_10 = M2C_FIELD(temp_s1, void** , 0x1C);
                        M2C_FIELD(M2C_FIELD(((M2C_FIELD(temp_a0_10, s32* , 0x28) * 0x110) + D_004FA030), void** , 0x95FC8), f32* , 0x14) = (f32) M2C_FIELD(temp_a0_10, f32* , 8);
                        temp_a0_11 = M2C_FIELD(temp_s1, void** , 0x1C);
                        M2C_FIELD(M2C_FIELD(((M2C_FIELD(temp_a0_11, s32* , 0x28) * 0x110) + D_004FA030), void** , 0x95FC8), f32* , 0x18) = (f32) M2C_FIELD(temp_a0_11, f32* , 0xC);
                        temp_a0_12 = M2C_FIELD(temp_s1, void** , 0x1C);
                        M2C_FIELD(M2C_FIELD(((M2C_FIELD(temp_a0_12, s32* , 0x28) * 0x110) + D_004FA030), void** , 0x95FC8), f32* , 0x60) = (f32) M2C_FIELD(temp_a0_12, f32* , 0x10);
                        temp_a0_13 = M2C_FIELD(temp_s1, void** , 0x1C);
                        M2C_FIELD(M2C_FIELD(((M2C_FIELD(temp_a0_13, s32* , 0x28) * 0x110) + D_004FA030), void** , 0x95FC8), f32* , 0x64) = (f32) M2C_FIELD(temp_a0_13, f32* , 0x14);
                        temp_a0_14 = M2C_FIELD(temp_s1, void** , 0x1C);
                        var_f0 = M2C_FIELD(temp_a0_14, f32* , 0x18);
                        var_v0_2 = (M2C_FIELD(temp_a0_14, s32* , 0x28) * 0x110) + D_004FA030 + 0x90000;
block_76:
                        M2C_FIELD(M2C_FIELD(var_v0_2, void** , 0x5FC8), f32* , 0x68) = var_f0;
                        break;
                    case 3:                         /* switch 6 */
                        func_00141AB8(D_004FA030 + (temp_a1_3 + 0x95F20), sp, 0x1F4, M2C_FIELD(M2C_FIELD(M2C_FIELD((&D_003156C0 + 0x56C0), void** , 4), void** , 0xA0), s32* , 0x20FC));
                        break;
                    case 2:                         /* switch 6 */
                        M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x962F0), s8* , 0xC) = 0;
                        break;
                    }
                }
            }
            temp_a0_15 = M2C_FIELD(temp_s1, void** , 0x1C);
            M2C_FIELD((D_004FA030 + (M2C_FIELD(temp_a0_15, s32* , 0x28) * 0x110)), s32* , 0x96020) = (s32) M2C_FIELD(temp_a0_15, s32* , 0x24);
            break;
        }
    } else {
    default:
    }
}
