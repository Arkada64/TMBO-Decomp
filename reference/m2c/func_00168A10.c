M2C_UNK strcpy(s128, s32, s128, s128, s128);        /* extern */
extern M2C_UNK D_003156C0;
extern M2C_UNK D_00318416;

s32 func_00168A10(s32 arg2, s32 arg3) {
    M2C_UNK* var_a2;
    s128 var_a5;
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
    void* var_a4;
    void* var_s0;

    if (arg2 != 0x100) {
        var_fp = arg3;
        var_a5 = 0;
        var_a2 = &D_00318416;
        var_a4 = &D_00318416 + 0x272;
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
            strcpy((s128) var_a2, temp_a1, (s128) var_a2, (s128) var_a4, var_a5);
            temp_v0 = *var_s1;
            var_s1 += 0x30;
            M2C_FIELD(var_s0, s32* , -0xA0) = temp_v0;
            var_a5 = subroutine_arg8 + 1;
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
            var_a4 = subroutine_arg4 + 4;
        } while (var_a5 < 8);
        M2C_FIELD(&D_003156C0, s32* , 0x3230) = 1;
    }
    return 0x180;
}
