//@@ func_001641A8 a
void func_001641A8(char* p) {
    p[0x64] = 0;
    *(char**)(p + 0x1E64) = p + 0x64;
}
//@@ func_001641A8 b
void func_001641A8(char* p) {
    *(char**)(p + 0x1E64) = p + 0x64;
    p[0x64] = 0;
}
//@@ func_0016EF58 a
char* func_0016EF58(char* base, int slot) {
    return base + (slot * 0x220 + 0x10);
}
//@@ func_0016EF58 b
char* func_0016EF58(char* base, int slot) {
    return base + slot * 0x220 + 0x10;
}
//@@ func_0016EF70 a
char* func_0016EF70(char* base, int index) {
    return base + (index * 0x84 + 0x1110);
}
//@@ func_0016EF70 b
char* func_0016EF70(char* base, int index) {
    return base + index * 0x84 + 0x1110;
}
//@@ func_00174218 a
int func_00174218(char* base, int slot) {
    return *(int*)(base + slot * 0x220 + 0xB4);
}
//@@ func_00174230 a
int func_00174230(char* base, int value, int slot) {
    *(int*)(base + slot * 0x220 + 0xB4) = value;
    return 1;
}
//@@ func_001658C8 a
void func_00259FBC(void);
void func_001658C8(void) {
    func_00259FBC();
}
//@@ func_0016E6D8 a
int iSignalSema(int sema);
void func_0016E6D8(int sema) {
    iSignalSema(sema);
}
//@@ func_00171B58 a
void func_00268260(int handle);
void func_00171B58(void* unused, char* obj) {
    func_00268260(*(int*)(obj + 0x50));
}
//@@ func_001669C8 a
void func_001669A0(int a, int b);
void func_001669C8(void) {
    func_001669A0(1, 0xFFFF);
}
