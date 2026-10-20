s32 func_002665A0(void*, s32);                      /* extern */
s32 func_00267390(s8, s32, s32, M2C_UNK);           /* extern */
s32 func_002674D8(s8, void*, M2C_UNK, M2C_UNK);     /* extern */
s32 func_00267568(M2C_UNK, M2C_UNK, s8, M2C_UNK);   /* extern */
u32 func_0026E738(M2C_UNK, s32);                    /* extern */
s32 func_0026E7F0(M2C_UNK, s32, u32);               /* extern */
s32 func_0026E910(M2C_UNK, s32, u32);               /* extern */
s32 func_0026EA90(M2C_UNK, s32, u32);               /* extern */
s32 func_0026EC00(M2C_UNK, void**);                 /* extern */
s32 func_0026EEE0(M2C_UNK, s32);                    /* extern */

s32 func_00267720(s8 arg0, M2C_UNK arg1, s32 arg2, M2C_UNK arg3) {
    void* sp4;
    s32 sp8;
    s32 temp_s0;
    s32 var_s4;
    s32 var_v0;
    u32 temp_s3;

    var_s4 = 0;
    sp8 = M2C_ERROR(/* Read from unset register $a6 */);
    sp4 = NULL;
    if (arg2 == -1) {
        var_s4 = func_00267568(0, 0, arg0, arg1);
        goto block_18;
    }
    if (arg2 == 0xFFFF) {
        var_v0 = func_002665A0(sp, func_0026EEE0(arg1, arg2));
        if (var_v0 == 0) {
            if (func_002674D8(arg0, sp, arg3, M2C_ERROR(/* Read from unset register $a4 */)) != 0) {
                var_s4 = 0xD;
            }
            goto block_18;
        }
        /* Duplicate return node #19. Try simplifying control flow for better match */
        return var_v0;
    }
    temp_s3 = func_0026E738(arg1, arg2);
    var_v0 = func_0026EC00(arg1, &sp4);
    var_s4 = var_v0;
    if ((var_s4 == 0) && (sp4 != NULL)) {
        if (temp_s3 >= 2U) {
            return var_s4;
        }
        if ((func_0026E910(arg1, arg2, temp_s3) != 0) && (arg2 != M2C_FIELD(sp4, s32* , 0x400))) {
            temp_s0 = func_0026E7F0(arg1, arg2, temp_s3);
            var_s4 = (func_00267390(arg0, temp_s0, func_0026EA90(arg1, arg2, temp_s3), arg3) != 0) ? 0xD : var_s4;
        }
block_18:
        var_v0 = var_s4;
        /* Duplicate return node #19. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
