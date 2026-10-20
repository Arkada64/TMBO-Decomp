M2C_UNK func_0011BD50(void*, void**, M2C_UNK);      /* extern */
M2C_UNK func_00129A70(s32, void*, M2C_UNK, s32);    /* extern */
void* func_001690F0(s16, s8, u8, s32);              /* extern */
void* func_00169230(s32, s32);                      /* extern */
M2C_UNK func_00169C28(s32, s32, M2C_UNK, M2C_UNK);  /* extern */
M2C_UNK func_00171DD0(M2C_UNK*, s32, s32*);         /* extern */
s32 func_001734B8(M2C_UNK*, void**);                /* extern */
void* func_00174248(M2C_UNK*);                      /* extern */
s32 func_00174268(M2C_UNK*, s32);                   /* extern */
M2C_UNK func_001814D0(void*);                       /* extern */
M2C_UNK func_001FDE10(M2C_UNK, s32);                /* extern */
M2C_UNK hierSetSwitch__FP11_hierswitchi(s32, M2C_UNK, void**, M2C_UNK); /* extern */
M2C_UNK printf(M2C_UNK*, u8);                       /* extern */
extern M2C_UNK D_003156C0;
extern M2C_UNK D_004E6AD8;
extern s32 D_004F9CA0;
extern s32 D_004F9CA4;
extern s32 D_004F9CA8;
extern s32 D_004F9CAC;
extern s32 D_004F9CB0;
extern s32 D_004F9D18;
extern void* D_004FA030;
extern s32 D_004FA03C;

void func_00169308(s32 arg0, s32 arg1) {
    s32 sp10;
    s32 sp14;
    s32 temp_a0_4;
    s32 temp_a1_3;
    s32 temp_a1_4;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 temp_v1_6;
    s32 var_a1;
    s32* temp_a0_8;
    u8 temp_a1;
    void* temp_a0_2;
    void* temp_a0_3;
    void* temp_a0_5;
    void* temp_a0_6;
    void* temp_a0_7;
    void* temp_a1_2;
    void* temp_a1_5;
    void* temp_s1;
    void* temp_v0;
    void* temp_v0_3;
    void* temp_v0_4;
    void* temp_v0_5;
    void* temp_v0_6;
    void* temp_v0_7;
    void* var_v0;
    void** temp_a0;
    void** temp_a1_6;
    void** temp_a1_7;
    void** temp_a1_8;
    void** temp_a2;
    void** temp_v0_2;
    void** temp_v0_8;
    void** temp_v1;
    void** temp_v1_7;

    temp_s1 = func_00174248(&D_003156C0);
    if (arg0 != 0x100) {
        temp_a1 = M2C_FIELD(temp_s1, u8* , 0);
        if (temp_a1 == D_004F9D18) {
            temp_a0 = M2C_FIELD(temp_s1, void*** , 0x1C);
            if (M2C_FIELD(temp_a0, s8* , 0x2E) != 2) {
                func_001FDE10(1, func_00174268(&D_003156C0, arg0));
                temp_v0 = func_00169230(arg0, arg1);
                if (temp_v0 != NULL) {
                    temp_a0_2 = (arg0 * 0x220) + &D_003156C0;
                    M2C_FIELD(M2C_FIELD(temp_a0_2, void** , 0xB0), void*** , 0x20D0) = (void** ) M2C_FIELD(temp_s1, void*** , 0x1C);
                    M2C_FIELD(M2C_FIELD(temp_a0_2, void** , 0xB0), s32* , 0x20C4) = arg1;
                    *M2C_FIELD(M2C_FIELD(temp_a0_2, void** , 0xB0), void*** , 0x20D0) = temp_v0;
                    M2C_FIELD(temp_v0, s32* , 0x3190) = 0;
                    if ((M2C_FIELD(M2C_FIELD(&D_003156C0, void*** , 0x3148), s32* , 0) & 0x3F0000) == 0x250000) {
                        M2C_FIELD(M2C_FIELD(temp_a0_2, void** , 0xB0), s32* , 0x22A8) = 1;
                    }
                    M2C_FIELD(temp_v0, s32* , 0x2190) = 1;
                    func_00169C28(arg0, arg1, -1, 0x250000);
                } else {
                    *M2C_FIELD(M2C_FIELD(((arg0 * 0x220) + &D_003156C0), void** , 0xB0), s32** , 0x20D0) = 0;
                }
            } else {
                func_001FDE10(1, M2C_FIELD(temp_a0, s8* , 0x2F) + 1);
                temp_v0_2 = M2C_FIELD(temp_s1, void*** , 0x1C);
                temp_v0_3 = func_001690F0(M2C_FIELD(temp_v0_2, s16* , 0x28), M2C_FIELD(temp_v0_2, s8* , 0x2F), M2C_FIELD(temp_v0_2, u8* , 0x33), arg1);
                temp_v1 = M2C_FIELD(temp_s1, void*** , 0x1C);
                M2C_FIELD(temp_v0_3, s32* , 0x20C4) = arg1;
                M2C_FIELD(temp_v0_3, void*** , 0x20D0) = temp_v1;
                M2C_FIELD(temp_v1, void** , 0) = temp_v0_3;
                M2C_FIELD(temp_v0_3, s32* , 0x3190) = 0;
            }
        } else if (temp_a1 == D_004F9CA0) {
            temp_a2 = M2C_FIELD(temp_s1, void*** , 0x1C);
            temp_a0_3 = M2C_FIELD(temp_a2, void** , 0) - 1;
            switch ((s32) temp_a0_3) {
            case 0:
                M2C_FIELD((&D_003156C0 + 0x56C0), s32* , 0x2E9C) = arg1;
                break;
            case 1:
                M2C_FIELD((&D_003156C0 + 0x56C0), s32* , 0x2EA8) = arg1;
                break;
            case 2:
                M2C_FIELD((&D_003156C0 + 0x56C0), s32* , 0x2E98) = arg1;
                break;
            case 3:
                temp_a1_2 = &D_003156C0 + 0x56C0;
                M2C_FIELD(temp_a1_2, s32* , 0x2EA0) = arg1;
                if (M2C_FIELD(temp_a2, s32* , 0x24) == 3) {
                    temp_a0_4 = M2C_FIELD(temp_a1_2, s32* , 0x2EA4);
                    M2C_ERROR(/* unknown instruction: por $v0, $zero, $zero */);
                    if (temp_a0_4 != 0) {
                        func_00129A70(temp_a0_4, sp, 0x190, M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_a1_2, void** , 4), void** , 0xA0), s32* , 0x20FC));
                    }
                }
                break;
            case 4:
                M2C_FIELD((&D_003156C0 + 0x56C0), s32* , 0x2EAC) = arg1;
                temp_v1_2 = M2C_FIELD(temp_a2, s32* , 0x24);
                switch (temp_v1_2) {                /* switch 1; irregular */
                case 1:                             /* switch 1 */
                    M2C_FIELD(D_004FA030, s32* , 0x96704) = 1;
                    M2C_FIELD(D_004FA030, s32* , 0x96710) = (s32) M2C_FIELD(temp_a2, s32* , 0x20);
                    M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x96790), f32* , 0x10) = (f32) M2C_FIELD(temp_a2, f32* , 4);
                    M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x96790), f32* , 0x14) = (f32) M2C_FIELD(temp_a2, f32* , 8);
                    M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x96790), void** , 0x18) = (void* ) M2C_FIELD(temp_a2, void** , 0xC);
                    M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x96790), f32* , 0x60) = (f32) M2C_FIELD(temp_a2, f32* , 0x10);
                    M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x96790), f32* , 0x64) = (f32) M2C_FIELD(temp_a2, f32* , 0x14);
                    M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x96790), f32* , 0x68) = (f32) M2C_FIELD(temp_a2, f32* , 0x18);
                    break;
                case 2:                             /* switch 1 */
                    M2C_FIELD(D_004FA030, s32* , 0x9670C) = 1;
                    return;
                }
                break;
            case 5:
                temp_a0_5 = &D_003156C0 + 0x56C0;
                M2C_FIELD(temp_a0_5, s32* , 0x2EB4) = arg1;
                M2C_FIELD(temp_a0_5, s32* , 0x2EB8) = (s32) M2C_FIELD(temp_a2, s32* , 0x24);
                M2C_FIELD(D_004FA030, s32* , 0x96844) = (s32) M2C_FIELD(temp_a2, s32* , 0x20);
                M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x96840), f32* , 0x10) = (f32) M2C_FIELD(temp_a2, f32* , 4);
                M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x96840), f32* , 0x14) = (f32) M2C_FIELD(temp_a2, f32* , 8);
                M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x96840), void** , 0x18) = (void* ) M2C_FIELD(temp_a2, void** , 0xC);
                M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x96840), f32* , 0x60) = (f32) M2C_FIELD(temp_a2, f32* , 0x10);
                M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x96840), f32* , 0x64) = (f32) M2C_FIELD(temp_a2, f32* , 0x14);
                M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x96840), f32* , 0x68) = (f32) M2C_FIELD(temp_a2, f32* , 0x18);
                temp_v1_3 = M2C_FIELD(temp_a2, s32* , 0x24);
                switch (temp_v1_3) {                /* switch 2; irregular */
                case 1:                             /* switch 2 */
                    M2C_FIELD(D_004FA030, s32* , 0x96814) = temp_v1_3;
                    break;
                case 2:                             /* switch 2 */
                    M2C_FIELD(D_004FA030, s32* , 0x96814) = 0;
                    break;
                case 3:                             /* switch 2 */
                    M2C_FIELD(D_004FA030, s32* , 0x96818) = 1;
                    M2C_FIELD(D_004FA030, s32* , 0x96814) = 1;
                    break;
                }
                break;
            case 6:
                temp_a0_6 = &D_003156C0 + 0x56C0;
                M2C_FIELD(temp_a0_6, s32* , 0x2EC0) = arg1;
                M2C_FIELD(temp_a0_6, s32* , 0x2EC4) = (s32) M2C_FIELD(temp_a2, s32* , 0x24);
                M2C_FIELD(D_004FA030, s32* , 0x962F4) = (s32) M2C_FIELD(temp_a2, s32* , 0x20);
                M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x962F0), f32* , 0x10) = (f32) M2C_FIELD(temp_a2, f32* , 4);
                M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x962F0), f32* , 0x14) = (f32) M2C_FIELD(temp_a2, f32* , 8);
                M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x962F0), void** , 0x18) = (void* ) M2C_FIELD(temp_a2, void** , 0xC);
                M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x962F0), f32* , 0x60) = (f32) M2C_FIELD(temp_a2, f32* , 0x10);
                M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x962F0), f32* , 0x64) = (f32) M2C_FIELD(temp_a2, f32* , 0x14);
                M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x962F0), f32* , 0x68) = (f32) M2C_FIELD(temp_a2, f32* , 0x18);
                temp_v1_4 = M2C_FIELD(temp_a2, s32* , 0x24);
                switch (temp_v1_4) {                /* switch 3; irregular */
                case 2:                             /* switch 3 */
                    M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x962F0), s8* , 0xC) = 0;
                    break;
                case 3:                             /* switch 3 */
                    M2C_FIELD(D_004FA030, s32* , 0x96270) = 1;
                    break;
                }
                break;
            case 7:
                M2C_FIELD(D_004FA030, s32* , 0x968D8) = arg1;
                temp_a1_3 = M2C_FIELD(temp_a2, s32* , 0x24);
                switch (temp_a1_3) {                /* switch 4; irregular */
                case 3:                             /* switch 4 */
                    M2C_FIELD(D_004FA030, s32* , 0x968C4) = 1;
                    return;
                case 2:                             /* switch 4 */
                    M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x96944), s8* , 0xC) = 0;
                    M2C_FIELD(D_004FA030, s32* , 0x968C4) = 0;
                    hierSetSwitch__FP11_hierswitchi(M2C_FIELD(D_004FA030, s32* , 0x96940), 2, temp_a2, 0x90000);
                    break;
                }
                break;
            case 8:
                M2C_FIELD(D_004FA030, s32* , 0x968D8) = arg1;
                temp_a1_4 = M2C_FIELD(temp_a2, s32* , 0x24);
                switch (temp_a1_4) {                /* switch 5; irregular */
                case 3:                             /* switch 5 */
                    M2C_FIELD(D_004FA030, s32* , 0x96954) = 1;
                    return;
                case 2:                             /* switch 5 */
                    M2C_FIELD(M2C_FIELD(D_004FA030, void** , 0x969D4), s8* , 0xC) = 0;
                    M2C_FIELD(D_004FA030, s32* , 0x96954) = 0;
                    hierSetSwitch__FP11_hierswitchi(M2C_FIELD(D_004FA030, s32* , 0x969D0), 2, temp_a2, 0x90000);
                    break;
                }
                break;
            case 9:
                temp_a1_5 = D_004FA030 + 0x3EAC0;
                M2C_FIELD(temp_a1_5, s32* , 0x188) = arg1;
                temp_v1_5 = M2C_FIELD(temp_a2, s32* , 0x24);
                switch (temp_v1_5) {                /* switch 6; irregular */
                case 1:                             /* switch 6 */
                    M2C_FIELD(temp_a1_5, s32* , 0x10) = (s32) M2C_FIELD(temp_a2, s32* , 0x20);
                    M2C_FIELD(M2C_FIELD(temp_a1_5, void** , 0x80), f32* , 0x10) = (f32) M2C_FIELD(temp_a2, f32* , 4);
                    M2C_FIELD(M2C_FIELD(temp_a1_5, void** , 0x80), f32* , 0x14) = (f32) M2C_FIELD(temp_a2, f32* , 8);
                    M2C_FIELD(M2C_FIELD(temp_a1_5, void** , 0x80), void** , 0x18) = (void* ) M2C_FIELD(temp_a2, void** , 0xC);
                    M2C_FIELD(M2C_FIELD(temp_a1_5, void** , 0x80), f32* , 0x60) = (f32) M2C_FIELD(temp_a2, f32* , 0x10);
                    M2C_FIELD(M2C_FIELD(temp_a1_5, void** , 0x80), f32* , 0x64) = (f32) M2C_FIELD(temp_a2, f32* , 0x14);
                    M2C_FIELD(M2C_FIELD(temp_a1_5, void** , 0x80), f32* , 0x68) = (f32) M2C_FIELD(temp_a2, f32* , 0x18);
                    M2C_FIELD(temp_a1_5, s32* , 4) = 1;
                    break;
                case 3:                             /* switch 6 */
                    M2C_FIELD(temp_a1_5, s32* , 8) = 1;
                    M2C_FIELD(M2C_FIELD(temp_a1_5, void** , 0x80), s8* , 0xC) = 0;
                    temp_v0_4 = D_004FA030;
                    if (M2C_FIELD(temp_a2, s32* , 0x1C) == -1) {
                        M2C_ERROR(/* unknown instruction: por $v1, $zero, $zero */);
                        temp_v0_5 = &D_003156C0 + 0x56C0;
                        func_00129A70(M2C_FIELD(temp_v0_5, s32* , 0x2EC8), sp, 0x1F4, M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_v0_5, void** , 4), void** , 0xA0), s32* , 0x20FC));
                    }
                    M2C_FIELD((temp_v0_4 + 0x3EAC0), s32* , 4) = 0;
                    break;
                }
                break;
            case 10:
                M2C_FIELD((D_004FA030 + ((s32) M2C_FIELD(temp_a2, s16* , 0x28) * 0x110)), s32* , 0x9601C) = arg1;
                M2C_FIELD((((s32) M2C_FIELD(temp_a2, s16* , 0x28) * 0x110) + D_004FA030), s32* , 0x95FCC) = (s32) M2C_FIELD(temp_a2, s32* , 0x20);
                M2C_FIELD(M2C_FIELD((((s32) M2C_FIELD(temp_a2, s16* , 0x28) * 0x110) + D_004FA030), void** , 0x95FC8), f32* , 0x10) = (f32) M2C_FIELD(temp_a2, f32* , 4);
                M2C_FIELD(M2C_FIELD((((s32) M2C_FIELD(temp_a2, s16* , 0x28) * 0x110) + D_004FA030), void** , 0x95FC8), f32* , 0x14) = (f32) M2C_FIELD(temp_a2, f32* , 8);
                M2C_FIELD(M2C_FIELD((((s32) M2C_FIELD(temp_a2, s16* , 0x28) * 0x110) + D_004FA030), void** , 0x95FC8), void** , 0x18) = (void* ) M2C_FIELD(temp_a2, void** , 0xC);
                M2C_FIELD(M2C_FIELD((((s32) M2C_FIELD(temp_a2, s16* , 0x28) * 0x110) + D_004FA030), void** , 0x95FC8), f32* , 0x60) = (f32) M2C_FIELD(temp_a2, f32* , 0x10);
                M2C_FIELD(M2C_FIELD((((s32) M2C_FIELD(temp_a2, s16* , 0x28) * 0x110) + D_004FA030), void** , 0x95FC8), f32* , 0x64) = (f32) M2C_FIELD(temp_a2, f32* , 0x14);
                M2C_FIELD(M2C_FIELD((((s32) M2C_FIELD(temp_a2, s16* , 0x28) * 0x110) + D_004FA030), void** , 0x95FC8), f32* , 0x68) = (f32) M2C_FIELD(temp_a2, f32* , 0x18);
                M2C_FIELD((((s32) M2C_FIELD(temp_a2, s16* , 0x28) * 0x110) + D_004FA030), s32* , 0x96020) = (s32) M2C_FIELD(temp_a2, s32* , 0x24);
                temp_v1_6 = M2C_FIELD(temp_a2, s32* , 0x24);
                if (temp_v1_6 < 4) {
                    if (temp_v1_6 >= 2) {
                        M2C_FIELD(M2C_FIELD((((s32) M2C_FIELD(temp_a2, s16* , 0x28) * 0x110) + D_004FA030), void** , 0x95FC8), s8* , 0xC) = 0;
                        return;
                    }
                }
                break;
            }
        } else if (temp_a1 == D_004F9CA4) {
            temp_v1_7 = M2C_FIELD(temp_s1, void*** , 0x1C);
            temp_a0_7 = M2C_FIELD(temp_v1_7, void** , 0);
            if ((s32) temp_a0_7 <= 0xFFFF) {
                temp_v0_6 = func_00169230(arg0, arg1);
                if (temp_v0_6 != NULL) {
                    temp_a1_6 = M2C_FIELD(temp_s1, void*** , 0x1C);
                    M2C_FIELD(((arg0 * 0x220) + &D_003156C0), void*** , 0x220) = temp_a1_6;
                    M2C_FIELD(temp_v0_6, s32* , 0x20CC) = -1;
                    M2C_FIELD(temp_v0_6, void*** , 0x20D8) = temp_a1_6;
                    if (func_001734B8(&D_003156C0, temp_a1_6) != 0) {
                        sp14 = 0x36;
                        var_a1 = 0;
                        if (M2C_FIELD(&D_003156C0, s32* , 0x303C) == 0) {
                            M2C_FIELD(&D_003156C0, s32* , 0x303C) = 1;
                        } else {
loop_63:
                            var_a1 += 1;
                            if (var_a1 < 8) {
                                temp_a0_8 = (var_a1 * 4) + (&D_003156C0 + 0x303C);
                                if (*temp_a0_8 == 0) {
                                    *temp_a0_8 = 1;
                                } else {
                                    goto loop_63;
                                }
                            }
                        }
                        sp10 = var_a1;
                        func_00171DD0(&D_003156C0, arg0, &sp10);
                    }
                }
            } else {
                temp_v0_7 = func_001690F0((s32) temp_a0_7 & 0xFFFF, ((s32) temp_a0_7 >> 0x10) - 1, (u8) M2C_FIELD(temp_v1_7, s32* , 0x54), arg1);
                M2C_FIELD(temp_v0_7, s32* , 0x20CC) = arg1;
                M2C_FIELD(temp_v0_7, void*** , 0x20D8) = (void** ) M2C_FIELD(temp_s1, void*** , 0x1C);
            }
        } else if (temp_a1 == D_004F9CA8) {
            M2C_FIELD(&D_003156C0, s32* , 0x2F00) = arg1;
            M2C_FIELD(&D_003156C0, void*** , 0x2F04) = (void** ) M2C_FIELD(temp_s1, void*** , 0x1C);
        } else if (temp_a1 == D_004F9CAC) {
            temp_a1_7 = M2C_FIELD(temp_s1, void*** , 0x1C);
            M2C_FIELD(&D_003156C0, s32* , 0x3218) = arg1;
            M2C_FIELD(&D_003156C0, void*** , 0x3148) = temp_a1_7;
            M2C_FIELD(&D_003156C0, s64* , 0x3080) = (s64) ((M2C_FIELD(&D_003156C0, s64* , 0x3080) & ~0x1E) | ((((u32) M2C_FIELD(temp_a1_7, void** , 0) >> 1) & 0xF) * 2));
            func_0011BD50(&D_003156C0 + 0x386C, temp_a1_7, -0x1F);
            func_001814D0(&D_003156C0 + 0x3234);
            *(D_004FA03C + 0x1A3C8 + (*M2C_FIELD(&D_003156C0, s32** , 4) * 4)) = (s32) M2C_FIELD(M2C_FIELD(&D_003156C0, void*** , 0x3148), u8* , 5);
        } else if (temp_a1 == D_004F9CB0) {
            temp_a1_8 = M2C_FIELD(temp_s1, void*** , 0x1C);
            if ((s8) M2C_FIELD(temp_a1_8, f32* , 0x10) == 2) {
                var_v0 = func_001690F0(M2C_FIELD(temp_a1_8, s16* , 0x12), M2C_FIELD(temp_a1_8, s8* , 0x11), (u8) (s16) M2C_FIELD(temp_a1_8, f32* , 0x14), arg1);
            } else {
                var_v0 = func_00169230(arg0, arg1);
            }
            if (var_v0 != NULL) {
                M2C_FIELD(var_v0, s32* , 0x20C8) = arg1;
                temp_v0_8 = M2C_FIELD(temp_s1, void*** , 0x1C);
                M2C_FIELD(var_v0, void*** , 0x20D4) = temp_v0_8;
                M2C_FIELD(temp_v0_8, void** , 0xC) = var_v0;
            }
        } else {
            printf(&D_004E6AD8, temp_a1);
        }
    } else {
    default:
    }
}
