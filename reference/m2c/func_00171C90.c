M2C_UNK func_00166A68(s32, s32, s32, s32*);         /* extern */
s32 func_00266708(void*, s32, s32);                 /* extern */
s32 func_00267E60(M2C_UNK, s32, s32, s32);          /* extern */
M2C_UNK printf(M2C_UNK*, s32, s32, s32);            /* extern */
extern M2C_UNK D_004E8538;
extern s32 D_004F9D88;

s32 func_00171C90(void* arg0, s32 arg1, s32* arg2) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_s0;

    temp_v1 = *M2C_FIELD(arg0, s32** , 4);
    if ((temp_v1 != -1) && (temp_v1 == arg1)) {
        func_00166A68(M2C_FIELD(arg0, s32* , 0x2CF0), M2C_FIELD(arg0, s32* , 0x129C), arg1, arg2);
        goto block_17;
    }
    switch (arg1) {                                 /* irregular */
    case -1:
        var_s0 = 0;
        do {
            if ((func_00266708(sp, M2C_FIELD(arg0, s32* , 0x2CF0), var_s0) == 0) && (subroutine_arg0 != 0)) {
                temp_v0 = func_00267E60(0x40, M2C_FIELD(arg0, s32* , 0x2CF0), var_s0, D_004F9D88);
                if (temp_v0 != 0) {
                    printf(&D_004E8538, *arg2, var_s0, temp_v0);
                }
            }
            var_s0 += 1;
        } while (var_s0 < 8);
block_17:
        return 1;
    case -99:
        return 0;
    default:
        temp_v0_2 = func_00267E60(0x40, M2C_FIELD(arg0, s32* , 0x2CF0), arg1, D_004F9D88);
        if (temp_v0_2 != 0) {
            printf(&D_004E8538, *arg2, arg1, temp_v0_2);
        }
        goto block_17;
    }
}
