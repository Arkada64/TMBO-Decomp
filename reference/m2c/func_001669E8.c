M2C_UNK func_00118380(void*, M2C_UNK);              /* extern */
M2C_UNK func_001186C8(M2C_UNK*, void*);             /* extern */
M2C_UNK func_001188C0(void*);                       /* extern */
M2C_UNK strcpy(M2C_UNK*, void*);                    /* extern */
extern M2C_UNK D_002B90A0;
extern M2C_UNK D_003156D8;

s32 func_001669E8(s32 arg2, M2C_UNK arg3) {
    M2C_UNK sp4;

    func_001188C0(sp);
    if (arg2 != 0x100) {
        strcpy(&sp4, (arg2 * 0x220) + &D_003156D8);
        func_00118380(sp, arg3);
        func_001186C8(&D_002B90A0, sp);
    }
    return 0x44;
}
