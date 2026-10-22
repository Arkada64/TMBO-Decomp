#include "common.h"
#include "m2c_macros.h"

M2C_UNK InitLoopTankBefore__8LoopTank_8_2() __asm__("InitLoopTankBefore__8LoopTank");

void initBefore__11HighwayLoop(void) {
    InitLoopTankBefore__8LoopTank_8_2();
}

M2C_UNK InitLoopTankAfter__8LoopTank_8_5() __asm__("InitLoopTankAfter__8LoopTank");

void initAfter__11HighwayLoop(void) {
    InitLoopTankAfter__8LoopTank_8_5();
}

M2C_UNK update__8LoopTank_8_8() __asm__("update__8LoopTank");

void update__11HighwayLoop(void) {
    update__8LoopTank_8_8();
}

s32 addNode__11HighwayLoopiP9_hierhead(void* arg0, s32 arg1, void* arg2) {
    if (arg1 == 0x2972) {
        M2C_FIELD(arg0, void** , 0x84) = arg2;
    }
    return 0x2972;
}
