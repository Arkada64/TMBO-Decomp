M2C_UNK func_0011BD50(M2C_UNK*);                    /* extern */
M2C_UNK func_00173570(M2C_UNK*, M2C_UNK);           /* extern */
M2C_UNK func_00176580(M2C_UNK*);                    /* extern */
M2C_UNK func_001814D0(M2C_UNK*);                    /* extern */
M2C_UNK func_001A9278(void*, s32);                  /* extern */
extern M2C_UNK D_003156C0;
extern M2C_UNK D_003188F4;
extern M2C_UNK D_00318F2C;
extern s32 D_004F9CBC;
extern s32 D_004F9CC0;
extern s32 D_004F9CC8;

void func_0016BF00(s32 arg0, s32 arg2) {
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;

    if (arg0 != 0x100) {
        temp_v0 = D_004F9CBC;
        if ((M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 0x3148), s32* , 0) & 1) && ((u32) (M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 4), s32* , 0x204) - 9) < 2U)) {
            func_00173570(&D_003156C0, 0xB);
        }
        temp_v0_2 = D_004F9CC0;
        if (arg2 == temp_v0) {
            func_0011BD50(&D_00318F2C);
        }
        temp_v0_3 = D_004F9CC8;
        if (arg2 == temp_v0_2) {
            func_001814D0(&D_003188F4);
        }
        if (arg2 == temp_v0_3) {
            temp_a1 = M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 4), s32* , 0);
            if (M2C_FIELD(M2C_FIELD(&D_003156C0, void** , 0x3148), s8* , 0x1A) == temp_a1) {
                func_001A9278(M2C_FIELD(&D_003156C0, void** , 0x3148), temp_a1);
            }
        }
        func_00176580(&D_003156C0);
    }
}
