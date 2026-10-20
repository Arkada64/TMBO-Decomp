M2C_UNK func_00167018(s32, s32, s32, void*);        /* extern */
s32 func_00267E60(M2C_UNK, s32, s32, s32);          /* extern */
M2C_UNK printf(M2C_UNK*, s32, s32, s32);            /* extern */
extern M2C_UNK D_004E8590;
extern s32 D_004F9D84;

s32 func_00171DD0(void* arg0, s32 arg1, void* arg2) {
    s32 temp_v0;

    if (*M2C_FIELD(arg0, s32** , 4) == arg1) {
        func_00167018(M2C_FIELD(arg0, s32* , 0x2CF0), M2C_FIELD(arg0, s32* , 0x129C), arg1, arg2);
    } else {
        temp_v0 = func_00267E60(0x40, M2C_FIELD(arg0, s32* , 0x2CF0), arg1, D_004F9D84);
        if (temp_v0 != 0) {
            printf(&D_004E8590, M2C_FIELD(arg2, s32* , 4), arg1, temp_v0);
        }
    }
    return 1;
}
