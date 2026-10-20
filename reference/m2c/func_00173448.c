u32 func_00266378(void*, s32);                      /* extern */
M2C_UNK printf(M2C_UNK*, u32, s32, s32);            /* extern */
extern M2C_UNK D_004E8990;
extern M2C_UNK D_004E89C8;

s32 func_00173448(void* arg0) {
    s32 var_v0;
    u32 temp_v0;

    temp_v0 = func_00266378(sp, M2C_FIELD(arg0, s32* , 0x2CF0));
    if (temp_v0 != 0) {
        printf(&D_004E89C8, temp_v0, subroutine_arg0, M2C_FIELD(arg0, s32* , 0x2CF0));
        var_v0 = 0;
        /* Duplicate return node #6. Try simplifying control flow for better match */
        return var_v0;
    }
    var_v0 = subroutine_arg0;
    if ((u32) subroutine_arg0 >= 8U) {
        printf(&D_004E8990, subroutine_arg0);
        return subroutine_arg0;
    }
    return var_v0;
}
