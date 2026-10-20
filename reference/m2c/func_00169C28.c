M2C_UNK collisSlideVehicle__7VehicleP8_fvectorff(M2C_UNK, void*, void*); /* extern */
s32 dpcmp(s32, s32);                                /* extern */
s32 dpmul(s32, s32);                                /* extern */
s32 fptodp(f32);                                    /* extern */
M2C_UNK func_00156E08(void*, void*);                /* extern */
M2C_UNK func_001599A0(void*, void*);                /* extern */
M2C_UNK func_00159A90(void*, void*);                /* extern */
s32 func_001734B8(M2C_UNK*);                        /* extern */
s32 func_00173500(M2C_UNK*);                        /* extern */
void* func_00174248(M2C_UNK*);                      /* extern */
M2C_UNK func_001923B0(void*);                       /* extern */
M2C_UNK func_001AE050(void*, void*);                /* extern */
M2C_UNK func_001AEAE0(void*, void*, M2C_UNK*);      /* extern */
M2C_UNK func_001D6F78(void*);                       /* extern */
M2C_UNK func_001DC130(void*);                       /* extern */
M2C_UNK func_001E52F0(void*);                       /* extern */
M2C_UNK func_001E5420(void*);                       /* extern */
M2C_UNK func_001E5758(void*);                       /* extern */
M2C_UNK func_001E5790(void*, void*);                /* extern */
M2C_UNK func_00218A30(s32, void*);                  /* extern */
M2C_UNK func_00266DB8(s32*);                        /* extern */
f32 hdHatTest__FP8_fvectorT0P14ColorUnionType(void*, M2C_UNK*, M2C_UNK); /* extern */
M2C_UNK hierSetSwitch__FP11_hierswitchi(s32, M2C_UNK); /* extern */
M2C_UNK inputClearInputs__Fi(s32, void*);           /* extern */
M2C_UNK mathfRotMatrixRPH__FPA3_fP8_fvector(void*, void*); /* extern */
s32 particleCreateFx__FP8_fvectorPA3_fifT0T1bf(M2C_UNK, void*, void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK shadow2ndOnOff__7Vehiclei(void*, s32, void*, s8); /* extern */
M2C_UNK vehicleInitJump__7Vehicle9_jumpType(void*, M2C_UNK); /* extern */
M2C_UNK vehicleSetToPosition__7VehicleP8_fvectorf(f32, void*, void*); /* extern */
extern M2C_UNK D_003156C0;
extern s32 D_004F9AF8;
extern f32 D_004F9C8C;
extern f32 D_004F9C90;
extern s32 D_004F9C94;
extern s32 D_004F9C98;
extern s32 D_004F9CD8;
extern s32 D_004F9D28;
extern void* D_004FA030;

void func_00169C28(s32 arg0) {
    M2C_UNK sp10;
    s32 sp20;
    void* sp24;
    void* sp28;
    void* sp2C;
    void* sp30;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 var_f0;
    f32 var_f0_2;
    s32 temp_a0_3;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 temp_v0_12;
    s32 temp_v0_16;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 temp_v1_3;
    s32 var_a0;
    s32 var_a2;
    s32 var_s3;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32* var_a1;
    s8 temp_a2_2;
    s8 temp_a3;
    s8 temp_v0_5;
    u16 temp_s0;
    u32 var_a3;
    u32 var_v1;
    void* temp_a0;
    void* temp_a0_2;
    void* temp_a0_4;
    void* temp_a0_5;
    void* temp_a0_6;
    void* temp_a0_7;
    void* temp_a0_8;
    void* temp_a1;
    void* temp_a1_2;
    void* temp_a2;
    void* temp_s1;
    void* temp_s2;
    void* temp_s5;
    void* temp_s6;
    void* temp_v0;
    void* temp_v0_10;
    void* temp_v0_11;
    void* temp_v0_13;
    void* temp_v0_14;
    void* temp_v0_15;
    void* temp_v0_17;
    void* temp_v0_18;
    void* temp_v0_19;
    void* temp_v0_20;
    void* temp_v0_21;
    void* temp_v0_3;
    void* temp_v0_6;
    void* temp_v0_7;
    void* temp_v0_8;
    void* temp_v0_9;
    void* temp_v1_10;
    void* temp_v1_11;
    void* temp_v1_12;
    void* temp_v1_13;
    void* temp_v1_14;
    void* temp_v1_15;
    void* temp_v1_16;
    void* temp_v1_17;
    void* temp_v1_2;
    void* temp_v1_4;
    void* temp_v1_5;
    void* temp_v1_6;
    void* temp_v1_7;
    void* temp_v1_8;
    void* temp_v1_9;
    void** temp_v0_2;

    temp_v0 = func_00174248(&D_003156C0);
    if (arg0 != 0x100) {
        temp_v0_2 = M2C_FIELD(temp_v0, void*** , 0x1C);
        if (temp_v0_2 != NULL) {
            temp_s1 = *temp_v0_2;
            if (temp_s1 != NULL) {
                if ((M2C_FIELD(temp_s1, s8* , 0x485) != 0) && !(M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x20D0), u8* , 0x32) & 0x20)) {
                    func_001DC130(temp_s1);
                    func_001D6F78(temp_s1);
                    M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x202C), s32* , 0x10) = 0;
                    M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x202C), s32* , 0x14) = 0;
                    M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x202C), s32* , 0x18) = 0;
                    if (M2C_FIELD(temp_s1, s32* , 0x20F4) == 0x100) {
                        M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x2038), s32* , 0x10) = 0;
                        M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x2038), s32* , 0x14) = 0;
                        M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x2038), s32* , 0x18) = 0;
                    }
                }
                temp_s6 = temp_s1 + 0xD0;
                if (M2C_FIELD(temp_s1, s32* , 0x590) == 1) {
                    var_a2 = 0;
                    var_a1 = temp_s1 + 0x2338;
                    do {
                        if (!(M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x20D0), u16* , 0x2C) & ((1 << var_a2) & 0xFFFF))) {
                            *var_a1 = 0;
                        } else {
                            *var_a1 = 0xC8;
                        }
                        var_a2 += 1;
                        var_a1 += 4;
                    } while (var_a2 < 9);
                }
                temp_v0_3 = M2C_FIELD(temp_s1, void** , 0x20D0);
                M2C_FIELD(temp_s1, s32* , 0x22C0) = (s32) M2C_FIELD(temp_v0_3, u8* , 0x31);
                temp_s0 = M2C_FIELD(temp_v0_3, u16* , 0x2A);
                var_v0 = temp_s0 & 0x10;
                if (temp_s0 & 0x40) {
                    var_v0 = temp_s0 & 0x10;
                    if (M2C_FIELD(temp_s1, s8* , 0x49D) == 0) {
                        temp_a2 = M2C_FIELD(temp_s1, void** , 0x2028);
                        M2C_FIELD(temp_s1, s32* , 0x46C) = 0x3C;
                        M2C_FIELD(temp_s1, s8* , 0x49B) = 1;
                        M2C_FIELD(temp_s1, s32* , 0x468) = 0;
                        M2C_FIELD(temp_a2, s8* , 0xC) = 0;
                        M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x202C), s8* , 0xC) = 0;
                        shadow2ndOnOff__7Vehiclei(temp_s1, 0, temp_a2);
                        temp_v0_4 = particleCreateFx__FP8_fvectorPA3_fifT0T1bf(0x3F800000, temp_s1 + 0x1D0, M2C_FIELD(temp_s1, void** , 0x2028) + 0x20, 0x4B, 0);
                        M2C_FIELD(temp_s1, s32* , 0x2F40) = 0;
                        M2C_FIELD(temp_s1, s32* , 0x2F44) = temp_v0_4;
                        func_001923B0(temp_s1 + 0x2F54);
                        var_v0 = temp_s0 & 0x10;
                    }
                }
                var_v0_2 = temp_s0 & 8;
                if (var_v0 != 0) {
                    var_v0_2 = temp_s0 & 8;
                    if (M2C_FIELD(temp_s1, s8* , 0x497) == 0) {
                        hierSetSwitch__FP11_hierswitchi(M2C_FIELD(temp_s1, s32* , 0x2068), 1);
                        hierSetSwitch__FP11_hierswitchi(M2C_FIELD(temp_s1, s32* , 0x206C), 1);
                        M2C_FIELD(temp_s1, s8* , 0x497) = 1;
                        var_v0_2 = temp_s0 & 8;
                    }
                }
                var_v0_3 = temp_s0 & 0x20;
                if (var_v0_2 != 0) {
                    var_v0_3 = temp_s0 & 0x20;
                    if (M2C_FIELD(temp_s1, s8* , 0x490) == 0) {
                        vehicleInitJump__7Vehicle9_jumpType(temp_s1, 1);
                        var_v0_3 = temp_s0 & 0x20;
                    }
                }
                temp_v0_5 = M2C_FIELD(temp_s1, s8* , 0x496);
                if (var_v0_3 != 0) {
                    if (temp_v0_5 == 0) {
                        func_001E52F0(temp_s1);
                    }
                } else if (temp_v0_5 != 0) {
                    func_001E5420(temp_s1);
                }
                if (M2C_FIELD(temp_s1, s32* , 0x20F4) == 0xA0) {
                    temp_v1 = temp_s0 & 7;
                    if ((temp_v1 != 0) && (M2C_FIELD(temp_s1, s32* , 0x2508) == 0)) {
                        M2C_FIELD(temp_s1, s32* , 0x2508) = temp_v1;
                        M2C_FIELD(temp_s1, s32* , 0x250C) = 0x1E;
                    }
                }
                if ((M2C_FIELD(temp_s1, s32* , 0x20F4) == 0x160) && (temp_s0 & 0x100) && (M2C_FIELD(temp_s1, s32* , 0x242C) == 0)) {
                    M2C_FIELD(temp_s1, s32* , 0x24F8) = 1;
                    func_001599A0(temp_s1 + 0x21B0, temp_s1);
                }
                var_v1 = temp_s0 >> 7;
                if (M2C_FIELD(temp_s1, s32* , 0x20F4) == 0x120) {
                    var_a3 = temp_s0 >> 4;
                    if ((temp_s0 & 0x100) && (M2C_FIELD(temp_s1, s32* , 0x242C) == 0)) {
                        M2C_FIELD(temp_s1, s32* , 0x2778) = 2;
                        func_00159A90(temp_s1 + 0x21B0, temp_s1);
                        var_v1 = temp_s0 >> 7;
                        goto block_40;
                    }
                } else {
block_40:
                    var_a3 = temp_s0 >> 4;
                }
                M2C_FIELD(temp_s1, s8* , 0x49E) = (s8) (var_v1 & 1);
                temp_a2_2 = (temp_s0 >> 3) & 1;
                temp_a3 = var_a3 & 1;
                M2C_FIELD(temp_s1, s8* , 0x496) = (s8) ((temp_s0 >> 5) & 1);
                M2C_FIELD(temp_s1, s8* , 0x49D) = (s8) ((temp_s0 >> 6) & 1);
                M2C_FIELD(temp_s1, s8* , 0x490) = temp_a2_2;
                M2C_FIELD(temp_s1, s8* , 0x498) = temp_a3;
                temp_v1_2 = M2C_FIELD(temp_s1, void** , 0x20D0);
                M2C_FIELD(temp_s1, f32* , 0x404) = (f32) M2C_FIELD(temp_v1_2, f32* , 0x1C);
                M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x2028), s8* , 0xC) = (s8) (((u8) M2C_FIELD(temp_v1_2, u8* , 0x32) >> 1) & 1);
                M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x202C), s8* , 0xC) = (s8) (((u8) M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x20D0), u8* , 0x32) >> 1) & 1);
                shadow2ndOnOff__7Vehiclei(temp_s1, ((u8) M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x20D0), u8* , 0x32) >> 1) & 1, (void* ) temp_a2_2, temp_a3);
                temp_a0 = M2C_FIELD(temp_s1, void** , 0x2038);
                if ((temp_a0 != NULL) && (M2C_FIELD(temp_s1, s32* , 0x20F4) == 0x100)) {
                    M2C_FIELD(temp_a0, s8* , 0xC) = (s8) (((u8) M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x20D0), u8* , 0x32) >> 1) & 1);
                }
                temp_a1 = M2C_FIELD(temp_s1, void** , 0x20D0);
                temp_a0_2 = M2C_FIELD(temp_s1, void** , 0x2010);
                M2C_FIELD(temp_s1, s32* , 0x590) = (s32) M2C_FIELD(temp_a1, s8* , 0x2E);
                M2C_FIELD(temp_s1, s8* , 0x485) = (s8) (((u8) M2C_FIELD(temp_a1, u8* , 0x32) >> 5) & 1);
                M2C_FIELD(temp_s1, s8* , 0x486) = (s8) (((u8) M2C_FIELD(temp_a1, u8* , 0x32) >> 3) & 1);
                if (temp_a0_2 != NULL) {
                    if (!(M2C_FIELD(temp_a1, u8* , 0x32) & 0x40)) {
                        func_00218A30(M2C_FIELD(temp_a0_2, s32* , 0x7B4), temp_a1 + 0x33);
                    } else {
                        inputClearInputs__Fi(M2C_FIELD(temp_a0_2, s32* , 0x7B4), temp_a1);
                        func_001E5758(temp_s1);
                    }
                }
                temp_v1_3 = M2C_FIELD(temp_s1, s32* , 0x20F4);
                switch (temp_v1_3) {                /* irregular */
                case 0xC0:
                    temp_v1_4 = M2C_FIELD(temp_s1, void** , 0x20D0);
                    if (!(M2C_FIELD(temp_v1_4, u8* , 0x32) & 1)) {
                        goto block_58;
                    }
                    if (M2C_FIELD(temp_s1, s32* , 0x24B4) != 0) {
block_58:
                        if ((M2C_FIELD(temp_v1_4, u8* , 0x32) ^ 1) & 1) {
                            if (M2C_FIELD(temp_s1, s32* , 0x24B4) != 0) {
                                M2C_FIELD(temp_s1, s32* , 0x24A4) = 0;
                            }
                        }
                    } else {
                        M2C_FIELD(temp_s1, s32* , 0x24A4) = 1;
                    }
                    break;
                case 0x160:
                    if (M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x20D0), u8* , 0x32) & 1) {
                        if (M2C_FIELD(temp_s1, s32* , 0x24F0) != 2) {
                            M2C_FIELD(temp_s1, s32* , 0x24F8) = 1;
                            func_001599A0(temp_s1 + 0x21B0, temp_s1);
                        }
                    }
                    break;
                case 0x120:
                    if ((M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x20D0), u8* , 0x32) & 1) && (M2C_FIELD(temp_s1, s32* , 0x242C) == 0)) {
                        M2C_FIELD(temp_s1, s32* , 0x2780) = 0;
                        M2C_FIELD(temp_s1, s32* , 0x2778) = 1;
                        func_00159A90(temp_s1 + 0x21B0, temp_s1);
                    }
                    break;
                }
                if ((M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x20D0), u8* , 0x32) & 0x80) && (D_004F9D28 == 0) && (D_004F9AF8 == 0)) {
                    temp_s0_2 = M2C_FIELD(temp_s1, s32* , 0x21B0);
                    M2C_FIELD(temp_s1, s32* , 0x21B0) = 8;
                    func_00156E08(temp_s1 + 0x21B0, temp_s1);
                    M2C_FIELD(temp_s1, s32* , 0x21B0) = temp_s0_2;
                }
                D_004F9D28 = M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x20D0), u8* , 0x32) & 0x80;
                func_00266DB8(&sp20);
                temp_v1_5 = M2C_FIELD(temp_s1, void** , 0x20D0);
                M2C_FIELD(temp_s1, s32* , 0x219C) = 0x41855567;
                temp_a0_3 = M2C_FIELD(temp_v1_5, s32* , 0x20);
                if (temp_a0_3 >= M2C_FIELD(temp_s1, s32* , 0x318C)) {
                    goto block_83;
                }
                if (!(M2C_FIELD(temp_v1_5, u8* , 0x32) & 0x10)) {
block_83:
                    M2C_FIELD(temp_s1, s32* , 0x318C) = (s32) M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x20D0), s32* , 0x20);
                } else {
                    M2C_FIELD(temp_s1, s32* , 0x318C) = temp_a0_3;
                    M2C_FIELD(temp_v1_5, s32* , 0x20) = 0x41855567;
                }
                temp_v0_6 = M2C_FIELD(temp_s1, void** , 0x20D0);
                M2C_FIELD(temp_s1, f32* , 0x2D4) = (f32) M2C_FIELD(temp_v0_6, f32* , 0x10);
                M2C_FIELD(temp_s1, f32* , 0x1E0) = (f32) M2C_FIELD(temp_v0_6, f32* , 4);
                M2C_FIELD(temp_s1, f32* , 0x1E4) = (f32) M2C_FIELD(temp_v0_6, f32* , 8);
                func_001E5790(temp_s1, temp_s1 + 0x3188);
                temp_a0_4 = M2C_FIELD(temp_s1, void** , 0x20D0);
                if (temp_a0_4 == NULL) {
                    goto block_101;
                }
                if (M2C_FIELD(temp_s1, s8* , 0x3188) == (M2C_FIELD(temp_a0_4, u8* , 0x32) & 4)) {
                    goto block_94;
                }
                temp_f2 = M2C_FIELD(temp_a0_4, f32* , 0xC);
                if (!(fabsf(M2C_FIELD(temp_s1, f32* , 0x1D8) - temp_f2) > 100.0f)) {
block_94:
                    if (M2C_FIELD(temp_s1, void** , 0x20D0) == NULL) {
                        goto block_101;
                    }
                    if (!(M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x20D0), u8* , 0x32) & 4)) {
block_101:
                        var_f0 = M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x20D0), f32* , 0xC);
                    } else {
                        var_f0 = M2C_FIELD(temp_s1, f32* , 0x1D8);
                    }
                } else {
                    M2C_FIELD(temp_s1, f32* , 0x1D8) = temp_f2;
                    var_f0 = M2C_FIELD(temp_a0_4, f32* , 0xC);
                }
                M2C_FIELD(temp_s1, f32* , 0x1E8) = var_f0;
                if (D_004F9C94 < M2C_BITWISE(s32, D_004F9C8C)) {
                    var_a0 = D_004F9C94;
                } else {
                    var_a0 = (M2C_BITWISE(s32, D_004F9C8C) < D_004F9C98) ? D_004F9C98 : M2C_BITWISE(s32, D_004F9C8C);
                }
                M2C_FIELD(temp_s1, s32* , 0x3190) = var_a0;
                if (arg0 == func_00173500(&D_003156C0)) {
                    D_004F9CD8 = M2C_FIELD(temp_s1, s32* , 0x3190);
                } else if (func_001734B8(&D_003156C0) != 0) {
                    D_004F9CD8 = 0;
                }
                temp_v0_7 = M2C_FIELD(temp_s1, void** , 0x20D0);
                M2C_FIELD(temp_s1, s32* , 0x318C) = (s32) M2C_FIELD(temp_v0_7, s32* , 0x20);
                if ((((f32) M2C_FIELD(temp_v0_7, s16* , 0x24) * 0.125f) + ((f32) M2C_FIELD(temp_v0_7, s16* , 0x26) * 0.125f)) > 100.0f) {

                }
                var_v0_4 = M2C_FIELD(temp_s1, s32* , 0x3190);
                if (var_v0_4 > 0) {
loop_113:
                    var_v0_4 -= 1;
                    if (var_v0_4 == 0) {
                        M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($v1) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($sp) */);
                        M2C_ERROR(/* unknown instruction: vadd.xyz $vf11, $vf11, $vf12 */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf11, 0x1e0($s1) */);
                    }
                    if (var_v0_4 > 0) {
                        goto loop_113;
                    }
                }
                M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x2028), f32* , 0x68) = (f32) M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x20D0), f32* , 0x14);
                temp_v0_8 = M2C_FIELD(temp_s1, void** , 0x20D0);
                temp_v1_6 = M2C_FIELD(temp_s1, void** , 0x2028);
                M2C_FIELD(temp_s1, f32* , 0x208) = (f32) M2C_FIELD(temp_v0_8, f32* , 0x18);
                M2C_FIELD(temp_v1_6, f32* , 0x68) = (f32) (M2C_FIELD(temp_v1_6, f32* , 0x68) + (M2C_FIELD(temp_v0_8, f32* , 0x18) * (f32) M2C_FIELD(temp_s1, s32* , 0x3190)));
                temp_v0_9 = M2C_FIELD(temp_s1, void** , 0x2028);
                temp_f1 = M2C_FIELD(temp_v0_9, f32* , 0x68);
                if (temp_f1 > 6.2831855f) {
                    var_f0_2 = temp_f1 - 6.2831855f;
                    goto block_122;
                }
                if (temp_f1 < -6.2831855f) {
                    var_f0_2 = temp_f1 + 6.2831855f;
block_122:
                    M2C_FIELD(temp_v0_9, f32* , 0x68) = var_f0_2;
                }
                temp_a0_5 = M2C_FIELD(temp_s1, void** , 0x2028);
                mathfRotMatrixRPH__FPA3_fP8_fvector(temp_a0_5 + 0x20, temp_a0_5 + 0x60);
                temp_v0_10 = M2C_FIELD(temp_s1, void** , 0x2028);
                temp_v0_11 = temp_v0_10 + 0x20;
                M2C_FIELD(temp_s1, s128* , 0xD0) = (s128) M2C_FIELD(temp_v0_10, s128* , 0x20);
                M2C_FIELD(temp_s6, s128* , 0x10) = (s128) M2C_FIELD(temp_v0_11, s128* , 0x10);
                M2C_FIELD(temp_s6, s128* , 0x20) = (s128) M2C_FIELD(temp_v0_11, s128* , 0x20);
                M2C_FIELD(temp_s6, s128* , 0x30) = (s128) M2C_FIELD(temp_v0_11, s128* , 0x30);
                temp_v1_7 = M2C_FIELD(temp_s1, void** , 0x20D0);
                temp_f20 = fabsf(M2C_FIELD(temp_s1, f32* , 0x1D8) - M2C_FIELD(temp_v1_7, f32* , 0xC));
                if (M2C_FIELD(temp_v1_7, u8* , 0x32) & 0x10) {
                    if (M2C_FIELD(temp_s1, s32* , 0x2190) == 0) {
                        if (dpcmp(fptodp(fabsf(M2C_FIELD(temp_s1, f32* , 0x2D4))), (((((0xFEE6 << 0x11) | 0xCCCC) << 0x10) | 0xCCCC) << 0xD) | 0x199A) < 0) {
                            temp_v0_12 = M2C_FIELD(temp_s1, s32* , 0x21A0) + 1;
                            M2C_FIELD(temp_s1, s32* , 0x21A0) = temp_v0_12;
                            if (M2C_FIELD(temp_s1, s8* , 0x3188) == 0) {
                                if ((temp_v0_12 < 7) || (temp_s0_3 = fptodp(temp_f20), (dpcmp(temp_s0_3, dpmul(fptodp(D_004F9C90), (((((0xFF66 << 0x11) | 0xCCCC) << 0x10) | 0xCCCC) << 0xD) | 0x199A)) <= 0))) {
                                    if (M2C_FIELD(temp_s1, s8* , 0x3188) != 0) {
                                        goto block_134;
                                    }
                                } else {
                                    goto block_135;
                                }
                            } else {
block_134:
                                if (D_004F9C90 < temp_f20) {
block_135:
                                    temp_v0_13 = M2C_FIELD(temp_s1, void** , 0x20D0);
                                    M2C_FIELD(temp_s1, f32* , 0x1D0) = (f32) M2C_FIELD(temp_v0_13, f32* , 4);
                                    M2C_FIELD(temp_s1, f32* , 0x1D4) = (f32) M2C_FIELD(temp_v0_13, f32* , 8);
                                    M2C_FIELD(temp_s1, f32* , 0x1D8) = (f32) M2C_FIELD(temp_v0_13, f32* , 0xC);
                                    M2C_FIELD(temp_s1, f32* , 0x1E8) = (f32) M2C_FIELD(temp_v0_13, f32* , 0xC);
                                    M2C_FIELD(temp_s1, f32* , 0x1E0) = (f32) M2C_FIELD(temp_v0_13, f32* , 4);
                                    M2C_FIELD(temp_s1, f32* , 0x1E4) = (f32) M2C_FIELD(temp_v0_13, f32* , 8);
                                    M2C_FIELD(temp_s1, s32* , 0x1F0) = 0;
                                    M2C_FIELD(temp_s1, f32* , 0x1E8) = (f32) M2C_FIELD(temp_v0_13, f32* , 0xC);
                                    M2C_FIELD(temp_s1, s32* , 0x1F4) = 0;
                                    M2C_FIELD(temp_s1, s32* , 0x1F8) = 0;
                                    M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x2028), s128* , 0x10) = (s128) M2C_FIELD(temp_s1, f32* , 0x1D0);
                                    temp_v0_14 = M2C_FIELD(temp_s1, void** , 0x2028);
                                    M2C_FIELD(temp_v0_14, s32* , 0x60) = 0;
                                    temp_v0_15 = temp_v0_14 + 0x60;
                                    M2C_FIELD(temp_v0_15, f32* , 8) = (f32) M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x20D0), f32* , 0x14);
                                    M2C_FIELD(temp_v0_15, s32* , 4) = 0;
                                    temp_a0_6 = M2C_FIELD(temp_s1, void** , 0x2028);
                                    mathfRotMatrixRPH__FPA3_fP8_fvector(temp_a0_6 + 0x20, temp_a0_6 + 0x60);
                                    temp_v1_8 = M2C_FIELD(temp_s1, void** , 0x2028);
                                    temp_v1_9 = temp_v1_8 + 0x20;
                                    M2C_FIELD(temp_s1, s128* , 0xD0) = (s128) M2C_FIELD(temp_v1_8, s128* , 0x20);
                                    M2C_FIELD(temp_s6, s128* , 0x10) = (s128) M2C_FIELD(temp_v1_9, s128* , 0x10);
                                    M2C_FIELD(temp_s6, s128* , 0x20) = (s128) M2C_FIELD(temp_v1_9, s128* , 0x20);
                                    M2C_FIELD(temp_s6, s128* , 0x30) = (s128) M2C_FIELD(temp_v1_9, s128* , 0x30);
                                    M2C_FIELD(temp_s1, s128* , 0x260) = (s128) M2C_FIELD(temp_s1, f32* , 0x1D0);
                                    M2C_FIELD(temp_s1, s128* , 0x270) = (s128) M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x2028), s128* , 0x10);
                                    temp_v1_10 = M2C_FIELD(temp_s1, void** , 0x2028);
                                    temp_v1_11 = temp_v1_10 + 0x20;
                                    M2C_FIELD(temp_s1, s128* , 0x50) = (s128) M2C_FIELD(temp_v1_10, s128* , 0x20);
                                    M2C_FIELD(temp_s1, s128* , 0x60) = (s128) M2C_FIELD(temp_v1_11, s128* , 0x10);
                                    M2C_FIELD(temp_s1, s128* , 0x70) = (s128) M2C_FIELD(temp_v1_11, s128* , 0x20);
                                    M2C_FIELD(temp_s1, s128* , 0x80) = (s128) M2C_FIELD(temp_v1_11, s128* , 0x30);
                                    temp_v1_12 = temp_s1 + 0x1F0;
                                    M2C_FIELD(temp_s1, s32* , 0x1F0) = 0;
                                    M2C_FIELD(temp_s1, s32* , 0x2118) = (s32) M2C_FIELD(temp_s1, s32* , 0x2114);
                                    M2C_FIELD(temp_v1_12, s32* , 8) = 0;
                                    M2C_FIELD(temp_v1_12, s32* , 4) = 0;
                                    M2C_FIELD(temp_s1, s32* , 0x1EE0) = 0;
                                    func_001AE050(temp_s1, temp_s1 + 0x1AA0);
                                    func_001AE050(temp_s1, temp_s1 + 0x1B90);
                                    func_001AE050(temp_s1, temp_s1 + 0x1C80);
                                    func_001AE050(temp_s1, temp_s1 + 0x1D70);
                                    collisSlideVehicle__7VehicleP8_fvectorff(0, temp_s1, temp_s1 + 0xE0);
                                }
                            }
                        } else if ((M2C_FIELD(temp_s1, s8* , 0x3188) != 0) || !((((fabsf(M2C_FIELD(temp_s1, f32* , 0x2D4) * 1.5f) + 100.0f) / 200.0f) * D_004F9C90) < temp_f20)) {
                            if (!(D_004F9C90 < temp_f20)) {
                                M2C_FIELD(temp_s1, s32* , 0x21A0) = 0;
                            } else {
                                goto block_141;
                            }
                        } else {
block_141:
                            temp_v0_16 = M2C_FIELD(temp_s1, s32* , 0x21A0) + 1;
                            M2C_FIELD(temp_s1, s32* , 0x21A0) = temp_v0_16;
                            if (temp_v0_16 >= 7) {
                                var_s3 = 0;
                                M2C_FIELD(temp_s1, f32* , 0x1D0) = (f64) M2C_FIELD(temp_s1, f32* , 0x1E4);
                                M2C_FIELD(temp_s1, s32* , 0x21A0) = 0;
                                temp_v0_17 = M2C_FIELD(temp_s1, void** , 0x20D0);
                                temp_v1_13 = M2C_FIELD(temp_s1, void** , 0x2028);
                                M2C_FIELD(temp_s1, f32* , 0x1D8) = (f32) M2C_FIELD(temp_v0_17, f32* , 0xC);
                                M2C_FIELD(temp_s1, s32* , 0x1F0) = 0;
                                M2C_FIELD(temp_s1, f32* , 0x1E8) = (f32) M2C_FIELD(temp_v0_17, f32* , 0xC);
                                M2C_FIELD(temp_s1, s32* , 0x1F4) = 0;
                                M2C_FIELD(temp_s1, s32* , 0x1F8) = 0;
                                M2C_FIELD(temp_v1_13, f32* , 0x18) = (f32) (M2C_FIELD(temp_v1_13, f32* , 0x18) + 10.0f);
                                sp28 = temp_s1 + 0x1B90;
                                temp_s2 = temp_s1 + 0x50;
                                temp_s5 = temp_s1 + 0x1F0;
                                sp30 = temp_s1 + 0x1C80;
                                sp2C = temp_s1 + 0x1D70;
                                sp24 = temp_s1 + 0xE0;
loop_144:
                                temp_f0 = hdHatTest__FP8_fvectorT0P14ColorUnionType(M2C_FIELD(temp_s1, void** , 0x2028) + 0x10, &sp10, 0);
                                temp_a1_2 = M2C_FIELD(temp_s1, void** , 0x2028);
                                temp_f2_2 = M2C_FIELD(temp_a1_2, f32* , 0x18);
                                if (!(M2C_FIELD(D_004FA030, f32* , 0x9FC88) < (temp_f2_2 - temp_f0))) {
                                    var_s3 += 1;
                                    if (var_s3 < 4) {
                                        M2C_FIELD(temp_a1_2, f32* , 0x18) = (f32) (temp_f2_2 + 20.0f);
                                        goto loop_144;
                                    }
                                }
                                M2C_FIELD(temp_a1_2, f32* , 0x18) = (f32) (temp_f2_2 - (temp_f0 + M2C_FIELD(temp_s1, f32* , 0x3A4)));
                                func_001AEAE0(temp_s1, M2C_FIELD(temp_s1, void** , 0x2028) + 0x20, &sp10);
                                M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x2028), s128* , 0x10) = (s128) M2C_FIELD(temp_s1, f32* , 0x1D0);
                                temp_v0_18 = M2C_FIELD(temp_s1, void** , 0x2028);
                                M2C_FIELD(temp_v0_18, s32* , 0x60) = 0;
                                temp_v0_19 = temp_v0_18 + 0x60;
                                M2C_FIELD(temp_v0_19, f32* , 8) = (f32) M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x20D0), f32* , 0x14);
                                M2C_FIELD(temp_v0_19, s32* , 4) = 0;
                                temp_a0_7 = M2C_FIELD(temp_s1, void** , 0x2028);
                                mathfRotMatrixRPH__FPA3_fP8_fvector(temp_a0_7 + 0x20, temp_a0_7 + 0x60);
                                temp_v1_14 = M2C_FIELD(temp_s1, void** , 0x2028);
                                temp_v1_15 = temp_v1_14 + 0x20;
                                M2C_FIELD(temp_s1, s128* , 0xD0) = (s128) M2C_FIELD(temp_v1_14, s128* , 0x20);
                                M2C_FIELD(temp_s6, s128* , 0x10) = (s128) M2C_FIELD(temp_v1_15, s128* , 0x10);
                                M2C_FIELD(temp_s6, s128* , 0x20) = (s128) M2C_FIELD(temp_v1_15, s128* , 0x20);
                                M2C_FIELD(temp_s6, s128* , 0x30) = (s128) M2C_FIELD(temp_v1_15, s128* , 0x30);
                                M2C_FIELD(temp_s1, s128* , 0x260) = (s128) M2C_FIELD(temp_s1, f32* , 0x1D0);
                                M2C_FIELD(temp_s1, s128* , 0x270) = (s128) M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x2028), s128* , 0x10);
                                temp_v1_16 = M2C_FIELD(temp_s1, void** , 0x2028);
                                temp_v1_17 = temp_v1_16 + 0x20;
                                M2C_FIELD(temp_s1, s128* , 0x50) = (s128) M2C_FIELD(temp_v1_16, s128* , 0x20);
                                M2C_FIELD(temp_s2, s128* , 0x10) = (s128) M2C_FIELD(temp_v1_17, s128* , 0x10);
                                M2C_FIELD(temp_s2, s128* , 0x20) = (s128) M2C_FIELD(temp_v1_17, s128* , 0x20);
                                M2C_FIELD(temp_s2, s128* , 0x30) = (s128) M2C_FIELD(temp_v1_17, s128* , 0x30);
                                M2C_FIELD(temp_s1, s32* , 0x1F0) = 0;
                                M2C_FIELD(temp_s1, s32* , 0x2118) = (s32) M2C_FIELD(temp_s1, s32* , 0x2114);
                                M2C_FIELD(temp_s5, s32* , 8) = 0;
                                M2C_FIELD(temp_s5, s32* , 4) = 0;
                                M2C_FIELD(temp_s1, s32* , 0x1EE0) = 0;
                                func_001AE050(temp_s1, temp_s1 + 0x1AA0);
                                func_001AE050(temp_s1, sp28);
                                func_001AE050(temp_s1, sp30);
                                func_001AE050(temp_s1, sp2C);
                                collisSlideVehicle__7VehicleP8_fvectorff(0, temp_s1, sp24);
                            }
                        }
                    } else {
                        goto block_127;
                    }
                } else {
block_127:
                    M2C_FIELD(temp_s1, s32* , 0x21A0) = 0;
                    M2C_FIELD(temp_s1, f32* , 0x2D4) = (f32) M2C_FIELD(temp_v1_7, f32* , 0x10);
                    M2C_FIELD(temp_s1, f32* , 0x1D0) = (f32) M2C_FIELD(temp_v1_7, f32* , 4);
                    M2C_FIELD(temp_s1, f32* , 0x1D4) = (f32) M2C_FIELD(temp_v1_7, f32* , 8);
                    M2C_FIELD(temp_s1, f32* , 0x1D8) = (f32) M2C_FIELD(temp_v1_7, f32* , 0xC);
                    M2C_FIELD(temp_s1, s32* , 0x318C) = (s32) M2C_FIELD(temp_v1_7, s32* , 0x20);
                    M2C_FIELD(temp_s1, f32* , 0x1E0) = (s128) M2C_FIELD(temp_s1, f32* , 0x1D0);
                    M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x2028), s128* , 0x10) = (s128) M2C_FIELD(temp_s1, f32* , 0x1D0);
                    M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x2028), f32* , 0x68) = (f32) M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x20D0), f32* , 0x14);
                    temp_a0_8 = M2C_FIELD(temp_s1, void** , 0x2028);
                    M2C_FIELD(temp_s1, f32* , 0x208) = (f32) M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x20D0), f32* , 0x18);
                    mathfRotMatrixRPH__FPA3_fP8_fvector(temp_a0_8 + 0x20, temp_a0_8 + 0x60);
                    temp_v0_20 = M2C_FIELD(temp_s1, void** , 0x2028);
                    temp_v0_21 = temp_v0_20 + 0x20;
                    M2C_FIELD(temp_s1, s128* , 0xD0) = (s128) M2C_FIELD(temp_v0_20, s128* , 0x20);
                    M2C_FIELD(temp_s6, s128* , 0x10) = (s128) M2C_FIELD(temp_v0_21, s128* , 0x10);
                    M2C_FIELD(temp_s6, s128* , 0x20) = (s128) M2C_FIELD(temp_v0_21, s128* , 0x20);
                    M2C_FIELD(temp_s6, s128* , 0x30) = (s128) M2C_FIELD(temp_v0_21, s128* , 0x30);
                    if (M2C_FIELD(temp_s1, s32* , 0x2190) != 0) {
                        vehicleSetToPosition__7VehicleP8_fvectorf(M2C_FIELD(M2C_FIELD(temp_s1, void** , 0x20D0), f32* , 0x14), temp_s1, temp_s1 + 0x1D0);
                        M2C_FIELD(temp_s1, s32* , 0x2190) = 0;
                    }
                }
            }
        }
    }
}
