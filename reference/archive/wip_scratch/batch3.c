//@@ func_00164240 b-noparens
int func_00164240(char* p, char* text) {
    int n = *(int*)(p + 0x1E68);

    if (n < 0x100) {
        *(int*)(p + 0x1E68) = n + 1;
        strcpy(p + n * 1000 + 0x1E6C, text);
        return 1;
    }
    return 0;
}
//@@ func_00164240 c-2d-array
int func_00164240(char* p, char* text) {
    int n = *(int*)(p + 0x1E68);

    if (n < 0x100) {
        *(int*)(p + 0x1E68) = n + 1;
        strcpy(((char (*)[1000])(p + 0x1E6C))[n], text);
        return 1;
    }
    return 0;
}
//@@ func_00164240 a-orig
int func_00164240(char* p, char* text) {
    int n = *(int*)(p + 0x1E68);

    if (n < 0x100) {
        *(int*)(p + 0x1E68) = n + 1;
        strcpy(p + (n * 1000 + 0x1E6C), text);
        return 1;
    }
    return 0;
}
//@@ func_0016D638 b-store-order
void func_0028B414(void);
void func_00259D38(void);
void func_0026E4E8(void);
int func_0016D638(char* p) {
    printf("Taking down the RTime Interface...\n");
    func_0028B414();
    func_00259D38();
    func_0026E4E8();
    *(int*)(p + 0x1BB8) = 4;
    *(int*)(p + 0x1BBC) = 0;
    return 0;
}
//@@ func_0016D638 a-orig
void func_0028B414(void);
void func_00259D38(void);
void func_0026E4E8(void);
int func_0016D638(char* p) {
    printf("Taking down the RTime Interface...\n");
    func_0028B414();
    func_00259D38();
    func_0026E4E8();
    *(int*)(p + 0x1BBC) = 0;
    *(int*)(p + 0x1BB8) = 4;
    return 0;
}
//@@ func_001653D8 b-array
void func_001625F0(void);
void func_00259A58(void* callbacks, void* out);
void func_001653D8(void) {
    void* cb[5];
    int out[4];

    cb[0] = func_001625D8;
    cb[1] = func_001625E0;
    cb[2] = func_001625E8;
    cb[3] = func_001625F0;
    cb[4] = (void*)30000;
    func_00259A58(cb, out);
}
//@@ func_001653D8 a-orig
void func_001625F0(void);
void func_00259A58(void* callbacks, void* out);
void func_001653D8(void) {
    struct { void* fn[4]; int timeout; } cb;
    char out[16];

    cb.fn[0] = func_001625D8;
    cb.fn[1] = func_001625E0;
    cb.fn[2] = func_001625E8;
    cb.fn[3] = func_001625F0;
    cb.timeout = 30000;
    func_00259A58(&cb, out);
}
