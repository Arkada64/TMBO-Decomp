M2C_UNK animationStart__FR11_animHandleb(void*, M2C_UNK); /* extern */
M2C_UNK func_001FBCF8(void*, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK hierSetSwitch__FP11_hierswitchi(s32, M2C_UNK, void*, M2C_UNK); /* extern */
extern void* D_004FA030;
extern s32 D_004FA038;

s32 func_001681D0(s32 arg2, void* arg3) {
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
