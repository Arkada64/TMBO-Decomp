M2C_UNK func_001735E8(M2C_UNK*, void*, s32, u8);    /* extern */
void* func_00174248(M2C_UNK*);                      /* extern */
M2C_UNK func_001F02A8(void*, void*);                /* extern */
extern M2C_UNK D_003156C0;
extern void* D_004FA030;

void func_0016B420(s32 arg0) {
    s32 var_a2;
    s32 var_v0;
    s8 temp_a2;
    s8 temp_v1;
    u8 temp_a3;
    void* temp_a0;
    void* temp_a1;

    if (arg0 != 0x100) {
        temp_a1 = M2C_FIELD(func_00174248(&D_003156C0), void** , 0x1C);
        if (M2C_FIELD(temp_a1, s16* , 0xA) != 0xA0) {
            goto block_14;
        }
        temp_a2 = M2C_FIELD(temp_a1, s8* , 6);
        if (temp_a2 != 1) {
block_14:
            if (((M2C_FIELD(temp_a1, s16* , 0xA) != 0x180) || (M2C_FIELD(temp_a1, s8* , 6) != 1)) && (M2C_FIELD(temp_a1, u8* , 4) == 1)) {
                temp_a0 = M2C_FIELD(temp_a1, void** , 0);
                if (temp_a0 != NULL) {
                    if (M2C_FIELD(temp_a0, s32* , 0x54) == 0) {
                        func_001F02A8(temp_a0, temp_a1);
                    }
                }
            }
        } else {
            temp_v1 = M2C_FIELD(temp_a1, s8* , 0xC);
            temp_a3 = (u8) M2C_FIELD(temp_a1, s8* , 0xC);
            if (temp_v1 == temp_a2) {
                var_a2 = M2C_FIELD(((arg0 * 0x220) + &D_003156C0), s32* , 0xB0);
                goto block_13;
            }
            var_v0 = temp_a3 << 0x18;
            if ((temp_v1 != -2) || (var_a2 = M2C_FIELD(D_004FA030, s32* , 0x9E690), var_v0 = temp_a3 << 0x18, (var_a2 == 0))) {
                if ((var_v0 >> 0x18) == -3) {
                    var_a2 = M2C_FIELD(D_004FA030, s32* , 0x9E694);
                    if (var_a2 != 0) {
                        goto block_13;
                    }
                }
            } else {
block_13:
                func_001735E8(&D_003156C0, temp_a1, var_a2, temp_a3);
            }
        }
    }
}
