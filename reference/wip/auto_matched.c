//@@ func_00173ED0
#include "m2c_macros.h"
s32 func_00173ED0(s32 arg0, s32 arg1, s32 arg2) {
    void* temp_v0;

    temp_v0 = netGetDmeTime();
    if (temp_v0 != NULL) {
        M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), s32* , 0x24) = arg2;
        return 1;
    }
    return 0;
}
//@@ func_00173F10
#include "m2c_macros.h"
s32 func_00173F10(void) {
    void* temp_v0;

    temp_v0 = netGetDmeTime();
    if (temp_v0 != NULL) {
        return M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), s32* , 0x24);
    }
    return 0;
}
//@@ func_00173F40
#include "m2c_macros.h"
s32 func_00173F40(s32 arg0, s32 arg1, s32 arg2) {
    void* temp_v0;

    temp_v0 = netGetDmeTime();
    if (temp_v0 != NULL) {
        M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), s32* , 0x1C) = arg2;
        return 1;
    }
    return 0;
}
//@@ func_00173F80
#include "m2c_macros.h"
s32 func_00173F80(s32 arg0, s32 arg1, s32 arg2) {
    void* temp_v0;

    temp_v0 = netGetDmeTime();
    if (temp_v0 != NULL) {
        M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), s32* , 0x20) = arg2;
        return 1;
    }
    return 0;
}
//@@ func_00173FC0
#include "m2c_macros.h"
s32 func_00173FC0(void) {
    void* temp_v0;

    temp_v0 = netGetDmeTime();
    if (temp_v0 != NULL) {
        return M2C_FIELD(M2C_FIELD(temp_v0, void** , 0x1C), s32* , 0x20);
    }
    return 0;
}
