M2C_UNK func_00171B78(M2C_UNK*, M2C_UNK, s64, s64); /* extern */
M2C_UNK func_00171C90(M2C_UNK*, s32, void*);        /* extern */
M2C_UNK func_00171DD0(M2C_UNK*, s32, void*);        /* extern */
s32 func_001734B8(M2C_UNK*);                        /* extern */
M2C_UNK func_00173570(M2C_UNK*, M2C_UNK, s32*, M2C_UNK); /* extern */
M2C_UNK func_00174988(M2C_UNK*, s32);               /* extern */
s8 func_00176C20(M2C_UNK*);                         /* extern */
M2C_UNK func_00176CC8(M2C_UNK*);                    /* extern */
M2C_UNK func_00188E38(void*, s32);                  /* extern */
s32 func_00264448();                                /* extern */
M2C_UNK printf(M2C_UNK*, s32);                      /* extern */
M2C_UNK strncpy(void*, void*, M2C_UNK);             /* extern */
extern s32 D_00313F00;
extern M2C_UNK D_003156C0;
extern M2C_UNK D_003156D8;
extern M2C_UNK D_004E6500;
extern M2C_UNK D_004E6530;
extern M2C_UNK D_004E6560;
extern M2C_UNK D_004E6578;
extern M2C_UNK D_004E65A8;
extern M2C_UNK D_004E65D8;
extern M2C_UNK D_004E6600;
extern M2C_UNK D_004E6630;
extern void* D_004FA03C;
extern s32 D_004FA9D4;
extern s32 D_004FA9D8;

s32 func_00166A68(s32 arg2, void* arg3) {
    M2C_UNK* var_a1_2;
    s32 temp_a0;
    s32 temp_s0_2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_5;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s0_4;
    s32 var_v1;
    s32* temp_v0_4;
    s32* var_a0_2;
    s32* var_a2_2;
    s32* var_a3_2;
    s32* var_s1;
    s64 var_a2;
    s64 var_a3;
    s8 temp_v0_3;
    s8* var_a0;
    s8* var_a1_3;
    s8* var_s3;
    void* temp_s0;
    void* temp_s0_3;
    void* temp_s1;
    void* var_a1;
    void* var_s0;

    if (arg2 != 0x100) {
        temp_v0 = M2C_FIELD(arg3, s32* , 0);
        switch (temp_v0) {
        case 0x2:
            M2C_FIELD(&D_003156C0, s32* , 0x307C) = arg2;
            printf(&D_004E6500);
            printf(&D_004E6530, M2C_FIELD(&D_003156C0, s32* , 0x307C));
            printf(&D_004E6560, func_00264448());
            printf(&D_004E6500);
            M2C_FIELD(&D_003156C0, s32* , 0x2EE4) = 0;
            temp_v0_2 = ((s64) (M2C_FIELD(arg3, u64* , 0x10) << 0x13) >> 0x20) & 0xF;
            M2C_FIELD(&D_003156C0, s32* , 0x1BB0) = temp_v0_2;
            if (temp_v0_2 == 1) {
                D_004FA9D8 = 0;
                D_004FA9D4 = 0;
            }
            var_s0 = &D_003156C0 + 0x3080;
            var_a1 = arg3 + 0x14;
            M2C_FIELD(D_004FA03C, s32* , 0x1A3AC) = (s32) (((s64) (M2C_FIELD(arg3, u64* , 0x10) << 0x1E) >> 0x20) & 0x1F);
            if (((s32) var_a1 | (s32) var_s0) & 7) {
                var_s3 = arg3 + 0xDC;
                do {
                    M2C_ERROR(/* unknown instruction: ldl $v1, 0x7($a1) */);
                    M2C_ERROR(/* unknown instruction: ldr $v1, ($a1) */);
                    M2C_ERROR(/* unknown instruction: ldl $a0, 0xf($a1) */);
                    M2C_ERROR(/* unknown instruction: ldr $a0, 0x8($a1) */);
                    M2C_ERROR(/* unknown instruction: ldl $a2, 0x17($a1) */);
                    M2C_ERROR(/* unknown instruction: ldr $a2, 0x10($a1) */);
                    M2C_ERROR(/* unknown instruction: ldl $a3, 0x1f($a1) */);
                    M2C_ERROR(/* unknown instruction: ldr $a3, 0x18($a1) */);
                    M2C_ERROR(/* unknown instruction: sdl $v1, 0x7($s0) */);
                    M2C_ERROR(/* unknown instruction: sdr $v1, ($s0) */);
                    M2C_ERROR(/* unknown instruction: sdl $a0, 0xf($s0) */);
                    M2C_ERROR(/* unknown instruction: sdr $a0, 0x8($s0) */);
                    M2C_ERROR(/* unknown instruction: sdl $a2, 0x17($s0) */);
                    var_a2 = M2C_ERROR(/* unknown instruction: sdr $a2, 0x10($s0) */);
                    M2C_ERROR(/* unknown instruction: sdl $a3, 0x1f($s0) */);
                    var_a3 = M2C_ERROR(/* unknown instruction: sdr $a3, 0x18($s0) */);
                    var_a1 += 0x20;
                } while (var_a1 != (arg3 + 0xD4));
            } else {
                var_s3 = arg3 + 0xDC;
                do {
                    var_a2 = M2C_FIELD(var_a1, s64* , 0x10);
                    var_a3 = M2C_FIELD(var_a1, s64* , 0x18);
                    M2C_FIELD(var_s0, s64* , 0) = (s64) M2C_FIELD(var_a1, s64* , 0);
                    M2C_FIELD(var_s0, s64* , 8) = (s64) M2C_FIELD(var_a1, s64* , 8);
                    M2C_FIELD(var_s0, s64* , 0x10) = var_a2;
                    M2C_FIELD(var_s0, s64* , 0x18) = var_a3;
                    var_a1 += 0x20;
                    var_s0 += 0x20;
                } while (var_a1 != (arg3 + 0xD4));
            }
            M2C_ERROR(/* unknown instruction: ldl $v0, 0x7($a1) */);
            M2C_ERROR(/* unknown instruction: ldr $v0, ($a1) */);
            M2C_ERROR(/* unknown instruction: sdl $v0, 0x7($s0) */);
            M2C_ERROR(/* unknown instruction: sdr $v0, ($s0) */);
            if ((((u64) M2C_FIELD(arg3, u64* , 0x10) >> 0x21) & 0xF) >= 6) {
                func_00171B78(&D_003156C0, -1, var_a2, var_a3);
            }
            if ((((u64) M2C_FIELD(arg3, u64* , 0x10) >> 0x21) & 0xF) == 1) {
                printf(&D_004E6578);
                printf(&D_004E65A8);
                printf(&D_004E65D8);
                printf(&D_004E65A8);
                printf(&D_004E6578);
                func_00176CC8(&D_003156C0);
            }
            var_a1_2 = &D_003156C0;
            var_a2_2 = &D_00313F00;
            var_a0 = var_s3;
            var_s0_2 = 7;
            do {
                *var_a2_2 = *var_a0 << 5;
                if ((M2C_FIELD(var_a1_2, s32* , 0xB4) == -1) || (M2C_FIELD(var_a1_2, s32* , 0x214) == 0)) {
                    M2C_FIELD(var_a1_2, s32* , 0xB4) = (s32) (*var_a0 << 5);
                }
                var_a1_2 += 0x220;
                var_a2_2 += 4;
                var_s0_2 -= 1;
                var_a0 += 1;
            } while (var_s0_2 >= 0);
            if (((s32) M2C_FIELD(arg3, u64* , 0x10) & 3) != M2C_FIELD(&D_003156C0, s32* , 0)) {
                func_00173570(&D_003156C0, 0xE, var_a2_2, -1);
            }
            break;
        case 0xB:
            if (func_001734B8(&D_003156C0) != 0) {
                M2C_FIELD(arg3, s32* , 0) = 0xC;
block_36:
                func_00171C90(&D_003156C0, arg2, arg3);
            }
            break;
        case 0xC:
            M2C_FIELD(&D_003156C0, s32* , 0x307C) = arg2;
            printf(&D_004E6500);
            printf(&D_004E6600, M2C_FIELD(&D_003156C0, s32* , 0x307C));
            printf(&D_004E6500);
            break;
        case 0xD:
            temp_a0 = arg2 * 0x220;
            (&D_00313F00)[arg2] = (s32) M2C_FIELD(arg3, u64* , 0x10);
            temp_s0 = temp_a0 + &D_003156C0;
            M2C_FIELD(temp_s0, s32* , 0xB4) = (s32) M2C_FIELD(arg3, u64* , 0x10);
            strncpy(temp_a0 + (&D_003156C0 + 0x18), arg3 + 0x18, 0xF);
            M2C_FIELD(temp_s0, s8* , 0x27) = 0;
            M2C_FIELD(temp_s0, f32* , 0xA0) = (f32) M2C_FIELD(arg3, f32* , 0x30);
            M2C_FIELD(temp_s0, f32* , 0xA4) = (f32) M2C_FIELD(arg3, f32* , 0x34);
            M2C_FIELD(temp_s0, f32* , 0xA8) = (f32) M2C_FIELD(arg3, f32* , 0x38);
            M2C_FIELD(temp_s0, f32* , 0xAC) = (f32) M2C_FIELD(arg3, f32* , 0x3C);
            M2C_FIELD(temp_s0, s32* , 0x214) = (s32) M2C_FIELD(arg3, s32* , 0x40);
            break;
        case 0xE:
            temp_s0_2 = arg2 * 0x220;
            strncpy(temp_s0_2 + &D_003156D8, arg3 + 0x18, 0xF);
            temp_s1 = &D_003156D8 - 0x18;
            temp_s0_3 = temp_s0_2 + temp_s1;
            M2C_FIELD(temp_s0_3, s8* , 0x27) = 0;
            M2C_FIELD(temp_s0_3, s32* , 0xB4) = (s32) M2C_FIELD(arg3, u64* , 0x10);
            M2C_FIELD(temp_s0_3, s32* , 0xC8) = (s32) M2C_FIELD(arg3, s32* , 0x14);
            if ((M2C_FIELD(arg3, s32* , 0x14) == 0) && (M2C_FIELD(temp_s1, s32* , 0x1BB4) >= 2)) {
                func_00188E38(D_004FA03C, arg2);
            case 0x1:
            }
            if (func_001734B8(&D_003156C0) != 0) {
                func_00174988(&D_003156C0, arg2);
            }
            break;
        case 0x39:
            var_a1_3 = arg3 + 0xDC;
            var_a0_2 = &D_003156C0 + 0xB4;
            do {
                temp_v0_3 = *var_a1_3;
                var_a1_3 += 1;
                *var_a0_2 = temp_v0_3 << 5;
                var_a0_2 += 0x220;
            } while ((s32) var_a1_3 < (s32) (arg3 + 0xE4));
            M2C_FIELD(&D_003156C0, s32* , 0x3228) = 0;
            break;
        case 0xF:
            M2C_FIELD(arg3, s32* , 0) = 0x10;
            M2C_FIELD(arg3, u64* , 0x10) = func_00176C20(&D_003156C0);
            goto block_36;
        case 0x10:
            var_s0_3 = 0;
            M2C_FIELD(&D_003156C0, s32* , 0x2EEC) = 1;
            var_s1 = &D_003156C0 + 0x305C;
            M2C_FIELD(&D_003156C0, s32* , 0x2EE8) = 0;
            do {
                *var_s1 = 1;
                if ((var_s0_3 != M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 4), s32* , 0)) && (((s8) M2C_FIELD(arg3, u64* , 0x10) >> var_s0_3) & 1)) {
                    func_00171DD0(&D_003156C0, var_s0_3, sp);
                    printf(&D_004E6630, var_s0_3);
                    *var_s1 = 0;
                }
                var_s0_3 += 1;
                var_s1 += 4;
            } while (var_s0_3 < 8);
            break;
        case 0x11:
            temp_v0_4 = &D_003156C0 + 0x305C;
            var_a3_2 = temp_v0_4;
            *((arg2 * 4) + temp_v0_4) = 1;
            var_s0_4 = 7;
            var_v1 = 0;
            do {
                temp_v0_5 = *var_a3_2;
                var_s0_4 -= 1;
                var_a3_2 += 4;
                var_v1 += temp_v0_5;
            } while (var_s0_4 >= 0);
            if (var_v1 == 8) {
                M2C_FIELD(&D_003156C0, s32* , 0x2EEC) = 0;
            }
            break;
        }
    } else {
    default:
    }
    return 0xF0;
}
