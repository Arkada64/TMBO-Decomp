//@@ func_00164240 a
int func_00164240(char* p, char* text) {
    int n = *(int*)(p + 0x1E68);

    if (n < 0x100) {
        *(int*)(p + 0x1E68) = n + 1;
        strcpy(p + (n * 1000 + 0x1E6C), text);
        return 1;
    }
    return 0;
}
//@@ func_00168D90 a
extern char D_003156C0[];
char func_00176B10(char* state, int arg);
void func_00168D90(int connection, int client) {
    char* state;

    if (client != 0x100) {
        state = D_003156C0;
        if (connection == *(int*)(state + 0x2CF0)) {
            *(char*)(*(char**)(state + 0x3148) + 0x24) = func_00176B10(state, 0);
        }
    }
}
//@@ func_001733F8 a
int func_00264AE0(int* out, int connection, int index);
int func_001733F8(NetState* state) {
    int index;
    int value;

    if (dmeGetMyClientIndex(&index, state->mConnectionIndex) != 0) {
        return 0;
    }
    if (func_00264AE0(&value, state->mConnectionIndex, index) != 0) {
        return 0;
    }
    return value;
}
//@@ func_001733F8 b
int func_00264AE0(int* out, int connection, int index);
int func_001733F8(NetState* state) {
    int buf[2];

    if (dmeGetMyClientIndex(&buf[0], state->mConnectionIndex) != 0) {
        return 0;
    }
    if (func_00264AE0(&buf[1], state->mConnectionIndex, buf[0]) != 0) {
        return 0;
    }
    return buf[1];
}
//@@ func_00177028 a
extern int* D_003156C4;
int func_00177028(int value) {
    int i;
    int* table = D_00321018[*D_003156C4];

    for (i = 0; i < 8; i++) {
        if (table[i] == value) {
            return i;
        }
    }
    return -1;
}
//@@ func_0016D638 a
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
//@@ func_00172F48 a
int func_00172F48(char* state, int which) {
    char* game = *(char**)(state + 0x3148);
    int mode = (*(unsigned int*)game >> 1) & 0xF;

    if (mode == 4 || mode == 8) {
        if (which == 0) {
            return *(signed char*)(game + 0x1A);
        }
        if (which == 1) {
            return *(signed char*)(game + 0x1B);
        }
        return -1;
    }
    return -1;
}
//@@ func_001653D8 a
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
