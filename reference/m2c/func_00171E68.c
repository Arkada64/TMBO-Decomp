M2C_UNK func_001681D0(s32, s32, s32, void*);        /* extern */
s32 func_00267E60(M2C_UNK, s32, s32, s32);          /* extern */
M2C_UNK printf(M2C_UNK*, s32, s32, s32);            /* extern */
extern M2C_UNK D_004E85D8;
extern s32 D_004F9D90;

s32 func_00171E68(void* arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;
    s32 var_v1;
    void* var_a1;

    var_v1 = arg2;
    var_a1 = sp;
    if (arg2 & 7) {
        do {
            M2C_ERROR(/* unknown instruction: ldl $a2, 0x7($v1) */);
            M2C_ERROR(/* unknown instruction: ldr $a2, ($v1) */);
            M2C_ERROR(/* unknown instruction: ldl $a3, 0xf($v1) */);
            M2C_ERROR(/* unknown instruction: ldr $a3, 0x8($v1) */);
            M2C_ERROR(/* unknown instruction: ldl $a4, 0x17($v1) */);
            M2C_ERROR(/* unknown instruction: ldr $a4, 0x10($v1) */);
            M2C_ERROR(/* unknown instruction: ldl $a5, 0x1f($v1) */);
            M2C_ERROR(/* unknown instruction: ldr $a5, 0x18($v1) */);
            M2C_ERROR(/* unknown instruction: sdl $a2, 0x7($a1) */);
            M2C_ERROR(/* unknown instruction: sdr $a2, ($a1) */);
            M2C_ERROR(/* unknown instruction: sdl $a3, 0xf($a1) */);
            M2C_ERROR(/* unknown instruction: sdr $a3, 0x8($a1) */);
            M2C_ERROR(/* unknown instruction: sdl $a4, 0x17($a1) */);
            M2C_ERROR(/* unknown instruction: sdr $a4, 0x10($a1) */);
            M2C_ERROR(/* unknown instruction: sdl $a5, 0x1f($a1) */);
            M2C_ERROR(/* unknown instruction: sdr $a5, 0x18($a1) */);
            var_v1 += 0x20;
        } while (var_v1 != (arg2 + 0xC0));
    } else {
        do {
            M2C_FIELD(var_a1, s64* , 0) = (s64) M2C_FIELD(var_v1, s64* , 0);
            M2C_FIELD(var_a1, s64* , 8) = (s64) M2C_FIELD(var_v1, s64* , 8);
            M2C_FIELD(var_a1, s64* , 0x10) = (s64) M2C_FIELD(var_v1, s64* , 0x10);
            M2C_FIELD(var_a1, s64* , 0x18) = (s64) M2C_FIELD(var_v1, s64* , 0x18);
            var_v1 += 0x20;
            var_a1 += 0x20;
        } while (var_v1 != (arg2 + 0xC0));
    }
    if (*M2C_FIELD(arg0, s32** , 4) != arg1) {
        temp_v0 = func_00267E60(0x40, M2C_FIELD(arg0, s32* , 0x2CF0), arg1, D_004F9D90);
        if (temp_v0 != 0) {
            printf(&D_004E85D8, subroutine_arg0, arg1, temp_v0);
        }
    } else {
        func_001681D0(M2C_FIELD(arg0, s32* , 0x2CF0), M2C_FIELD(arg0, s32* , 0x129C), arg1, sp);
    }
    return 1;
}
