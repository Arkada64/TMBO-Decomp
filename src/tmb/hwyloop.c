#include "common.h"

#include "m2c_macros.h"
M2C_UNK func_00161650_ayLoop() __asm__("func_00161650");

void initAfter__11HighwayLoop(void) {
    func_00161650_ayLoop();
}

#include "m2c_macros.h"
M2C_UNK func_00161868_14F008() __asm__("func_00161868");

void func_0014F008(void) {
    func_00161868_14F008();
}

#include "m2c_macros.h"
void addNode__11HighwayLoopiP9_hierhead(void* arg0, s32 arg1, s32 arg2) {
    if (arg1 == 0x2972) {
        M2C_FIELD(arg0, s32* , 0x84) = arg2;
    }
}
