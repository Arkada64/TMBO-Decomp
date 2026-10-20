M2C_UNK func_002666A8(M2C_UNK*);                    /* extern */
M2C_UNK func_00266BF0(M2C_UNK*);                    /* extern */
M2C_UNK func_00266D78(M2C_UNK*);                    /* extern */
M2C_UNK func_00266EB0(s32*, s32);                   /* extern */
M2C_UNK func_002674D8(M2C_UNK, M2C_UNK*, M2C_UNK, s32); /* extern */
M2C_UNK func_0026B998(void*, M2C_UNK*, M2C_UNK, void*); /* extern */
M2C_UNK func_0026DFF8();                            /* extern */
s32 strcmp(void*, void*);                           /* extern */
M2C_UNK strcpy(M2C_UNK*, M2C_UNK*);                 /* extern */
extern M2C_UNK D_003156C0;
extern M2C_UNK D_003183D6;
extern s32 D_004F9D94;
extern void* D_004FA03C;
extern M2C_UNK func_00169050;

s32 func_001685E8(void* arg3) {
    M2C_UNK sp4;
    M2C_UNK sp24;
    M2C_UNK sp34;
    s32 sp44;
    M2C_UNK sp48;
    s32 sp4C;
    s32 sp50;
    s32 sp54;
    s32 sp58;
    s32 sp5C;
    M2C_UNK sp60;
    M2C_UNK sp70;
    s32 sp80;
    s32 var_s0;
    s32 var_s2;
    s32 var_s3;
    void* temp_a3;
    void* temp_s0;
    void* temp_s4;
    void* temp_v0;
    void* var_a1;
    void* var_a2;
    void* var_a2_2;
    void* var_v1;

    if (M2C_FIELD(arg3, s32* , 0) == 1) {
        func_00266BF0(&sp60);
        func_002666A8(&sp70);
        strcpy(&sp4, &D_003183D6);
        strcpy(&sp24, &D_003183D6 + 0x20);
        strcpy(&sp34, &D_003183D6 - 0x1282);
        sp44 = M2C_FIELD(arg3, s32* , 0x44);
        func_00266D78(&sp48);
        temp_s0 = &D_003183D6 - 0x2D16;
        if (M2C_FIELD(temp_s0, s32* , 0x2E90) != 0) {
            sp4C = ((u32) *M2C_FIELD(temp_s0, u32** , 0x3148) >> 1) & 0xF;
        } else {
            sp4C = (((u32) *M2C_FIELD(temp_s0, u32** , 0x3148) >> 1) & 0xF) | 0x80000000;
        }
        sp50 = M2C_FIELD(D_004FA03C, s32* , 0x1A3AC);
        func_00266EB0(&sp80, M2C_FIELD(&D_003156C0, s32* , 0x2CF0));
        sp54 = sp80;
        sp5C = 0x1869F;
        sp58 = (s32) M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 0x3148), u8* , 4);
        func_002674D8(0, &sp60, 2, D_004F9D94);
    }
    if (M2C_FIELD(arg3, s32* , 0) == 2) {
        var_s2 = 0;
        var_s3 = 0;
        if (M2C_FIELD(&D_003156C0, s32* , 0x1980) > 0) {
            temp_s4 = &D_003156C0 + 0x1588;
            var_s0 = 0 * 0x5C;
            do {
                if (strcmp(var_s0 + (&D_003156C0 + 0x1560), arg3 + 0x34) == 0) {
                    var_a2 = var_s0 + (&D_003156C0 + 0x1530);
                    var_a1 = arg3 + 4;
                    var_s3 = 1;
                    if (((s32) var_a1 | (s32) var_a2) & 7) {
                        do {
                            M2C_ERROR(/* unknown instruction: ldl $a3, 0x7($a1) */);
                            M2C_ERROR(/* unknown instruction: ldr $a3, ($a1) */);
                            M2C_ERROR(/* unknown instruction: ldl $a4, 0xf($a1) */);
                            M2C_ERROR(/* unknown instruction: ldr $a4, 0x8($a1) */);
                            M2C_ERROR(/* unknown instruction: ldl $a5, 0x17($a1) */);
                            M2C_ERROR(/* unknown instruction: ldr $a5, 0x10($a1) */);
                            M2C_ERROR(/* unknown instruction: ldl $a6, 0x1f($a1) */);
                            M2C_ERROR(/* unknown instruction: ldr $a6, 0x18($a1) */);
                            M2C_ERROR(/* unknown instruction: sdl $a3, 0x7($a2) */);
                            M2C_ERROR(/* unknown instruction: sdr $a3, ($a2) */);
                            M2C_ERROR(/* unknown instruction: sdl $a4, 0xf($a2) */);
                            M2C_ERROR(/* unknown instruction: sdr $a4, 0x8($a2) */);
                            M2C_ERROR(/* unknown instruction: sdl $a5, 0x17($a2) */);
                            M2C_ERROR(/* unknown instruction: sdr $a5, 0x10($a2) */);
                            M2C_ERROR(/* unknown instruction: sdl $a6, 0x1f($a2) */);
                            M2C_ERROR(/* unknown instruction: sdr $a6, 0x18($a2) */);
                            var_a1 += 0x20;
                            var_a2 += 0x20;
                        } while (var_a1 != (arg3 + 0x44));
                    } else {
                        do {
                            M2C_FIELD(var_a2, s64* , 0) = (s64) M2C_FIELD(var_a1, s64* , 0);
                            M2C_FIELD(var_a2, s64* , 8) = (s64) M2C_FIELD(var_a1, s64* , 8);
                            M2C_FIELD(var_a2, s64* , 0x10) = (s64) M2C_FIELD(var_a1, s64* , 0x10);
                            M2C_FIELD(var_a2, s64* , 0x18) = (s64) M2C_FIELD(var_a1, s64* , 0x18);
                            var_a1 += 0x20;
                            var_a2 += 0x20;
                        } while (var_a1 != (arg3 + 0x44));
                    }
                    M2C_ERROR(/* unknown instruction: ldl $a4, 0x7($a1) */);
                    M2C_ERROR(/* unknown instruction: ldr $a4, ($a1) */);
                    M2C_ERROR(/* unknown instruction: ldl $a5, 0xf($a1) */);
                    M2C_ERROR(/* unknown instruction: ldr $a5, 0x8($a1) */);
                    M2C_ERROR(/* unknown instruction: ldl $a6, 0x17($a1) */);
                    M2C_ERROR(/* unknown instruction: ldr $a6, 0x10($a1) */);
                    M2C_ERROR(/* unknown instruction: sdl $a4, 0x7($a2) */);
                    M2C_ERROR(/* unknown instruction: sdr $a4, ($a2) */);
                    M2C_ERROR(/* unknown instruction: sdl $a5, 0xf($a2) */);
                    M2C_ERROR(/* unknown instruction: sdr $a5, 0x8($a2) */);
                    M2C_ERROR(/* unknown instruction: sdl $a6, 0x17($a2) */);
                    M2C_ERROR(/* unknown instruction: sdr $a6, 0x10($a2) */);
                    M2C_FIELD(var_a2, s32* , 0x18) = (s32) M2C_FIELD(var_a1, s32* , 0x18);
                    *((var_s2 * 0x5C) + temp_s4) = *(var_s0 + temp_s4);
                }
                var_s2 += 1;
                var_s0 = var_s2 * 0x5C;
            } while (var_s2 < M2C_FIELD(&D_003156C0, s32* , 0x1980));
        }
        if ((var_s3 == 0) && (M2C_FIELD(arg3, s32* , 0x4C) >= 0) && (M2C_FIELD(&D_003156C0, s32* , 0x1980) < 0xC)) {
            var_a2_2 = arg3 + 4;
            var_v1 = (M2C_FIELD(&D_003156C0, s32* , 0x1980) * 0x5C) + (&D_003156C0 + 0x1530);
            temp_v0 = arg3 + 0x44;
            if (((s32) var_a2_2 | (s32) var_v1) & 7) {
                do {
                    M2C_ERROR(/* unknown instruction: ldl $a5, 0x7($a2) */);
                    M2C_ERROR(/* unknown instruction: ldr $a5, ($a2) */);
                    M2C_ERROR(/* unknown instruction: ldl $a6, 0xf($a2) */);
                    M2C_ERROR(/* unknown instruction: ldr $a6, 0x8($a2) */);
                    M2C_ERROR(/* unknown instruction: ldl $a0, 0x17($a2) */);
                    M2C_ERROR(/* unknown instruction: ldr $a0, 0x10($a2) */);
                    M2C_ERROR(/* unknown instruction: ldl $a3, 0x1f($a2) */);
                    M2C_ERROR(/* unknown instruction: ldr $a3, 0x18($a2) */);
                    M2C_ERROR(/* unknown instruction: sdl $a5, 0x7($v1) */);
                    M2C_ERROR(/* unknown instruction: sdr $a5, ($v1) */);
                    M2C_ERROR(/* unknown instruction: sdl $a6, 0xf($v1) */);
                    M2C_ERROR(/* unknown instruction: sdr $a6, 0x8($v1) */);
                    M2C_ERROR(/* unknown instruction: sdl $a0, 0x17($v1) */);
                    M2C_ERROR(/* unknown instruction: sdr $a0, 0x10($v1) */);
                    M2C_ERROR(/* unknown instruction: sdl $a3, 0x1f($v1) */);
                    M2C_ERROR(/* unknown instruction: sdr $a3, 0x18($v1) */);
                    var_a2_2 += 0x20;
                    var_v1 += 0x20;
                } while (var_a2_2 != temp_v0);
            } else {
                do {
                    M2C_FIELD(var_v1, s64* , 0) = (s64) M2C_FIELD(var_a2_2, s64* , 0);
                    M2C_FIELD(var_v1, s64* , 8) = (s64) M2C_FIELD(var_a2_2, s64* , 8);
                    M2C_FIELD(var_v1, s64* , 0x10) = (s64) M2C_FIELD(var_a2_2, s64* , 0x10);
                    M2C_FIELD(var_v1, s64* , 0x18) = (s64) M2C_FIELD(var_a2_2, s64* , 0x18);
                    var_a2_2 += 0x20;
                    var_v1 += 0x20;
                } while (var_a2_2 != temp_v0);
            }
            M2C_ERROR(/* unknown instruction: ldl $a3, 0x7($a2) */);
            M2C_ERROR(/* unknown instruction: ldr $a3, ($a2) */);
            M2C_ERROR(/* unknown instruction: ldl $a4, 0xf($a2) */);
            M2C_ERROR(/* unknown instruction: ldr $a4, 0x8($a2) */);
            M2C_ERROR(/* unknown instruction: ldl $a5, 0x17($a2) */);
            M2C_ERROR(/* unknown instruction: ldr $a5, 0x10($a2) */);
            M2C_ERROR(/* unknown instruction: sdl $a3, 0x7($v1) */);
            M2C_ERROR(/* unknown instruction: sdr $a3, ($v1) */);
            M2C_ERROR(/* unknown instruction: sdl $a4, 0xf($v1) */);
            M2C_ERROR(/* unknown instruction: sdr $a4, 0x8($v1) */);
            M2C_ERROR(/* unknown instruction: sdl $a5, 0x17($v1) */);
            M2C_ERROR(/* unknown instruction: sdr $a5, 0x10($v1) */);
            M2C_FIELD(var_v1, s32* , 0x18) = (s32) M2C_FIELD(var_a2_2, s32* , 0x18);
            temp_a3 = &D_003156C0 + 0x1560;
            M2C_FIELD(((M2C_FIELD(&D_003156C0, s32* , 0x1980) * 0x5C) + &D_003156C0), s32* , 0x1588) = 0x1869F;
            func_0026B998((M2C_FIELD(&D_003156C0, s32* , 0x1980) * 0x5C) + temp_a3, &func_00169050, 0x5C, temp_a3);
            func_0026DFF8();
            M2C_FIELD(&D_003156C0, s32* , 0x1980) = (s32) (M2C_FIELD(&D_003156C0, s32* , 0x1980) + 1);
        }
    }
    return 0x60;
}
