M2C_UNK func_00172FE8(void*, s32, M2C_UNK, s32);    /* extern */
s32 func_001734B8(void*);                           /* extern */

void func_00173340(void* arg0, s32 arg1, M2C_UNK arg2) {
    if ((((u32) *M2C_FIELD(arg0, u32** , 0x3148) >> 1) & 0xF) == 4) {
        if (func_001734B8(arg0) != 0) {
            func_00172FE8(arg0, arg1, arg2, -1);
        }
    }
    if ((((u32) *M2C_FIELD(arg0, u32** , 0x3148) >> 1) & 0xF) == 8) {
        if (func_001734B8(arg0) != 0) {
            func_00172FE8(arg0, arg1, arg2, M2C_FIELD(((arg1 * 0x220) + arg0), s32* , 0x14));
        }
    }
}
