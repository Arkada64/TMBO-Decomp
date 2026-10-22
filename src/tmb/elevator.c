#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/elevator", Init__8Elevator);

s32 ElevatorClearHits__8Elevator(void* arg0) {
    s32 var_v0;
    s32* var_a0;

    var_a0 = arg0 + 0x4C;
    var_v0 = 3;
    do {
        *var_a0 = 0;
        var_v0 -= 1;
        var_a0 -=0x1;
    } while (var_v0 >= 0);
    return var_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/elevator", ElevatorCheck__8Elevator);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/elevator", ElevatorTriggerHit__8ElevatorP9_tdResultP7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/elevator", ElevatorCollisionHit__8ElevatorP9_hdResultP7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/elevator", ElevatorOverload__8Elevatori);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/elevator", ElevatorSuckCar__8Elevatori);
