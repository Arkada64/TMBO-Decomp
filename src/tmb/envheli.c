#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/envheli", InitAfter__7EnvHeli);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/envheli", func_001324D0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/envheli", UpdateEnvHeli__7EnvHeli);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/envheli", func_00132920);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/envheli", func_00132B08);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/envheli", func_00132BA0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/envheli", func_00132C88);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/envheli", func_00132D18);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/envheli", func_00132E38);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/envheli", func_00133028);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/envheli", func_001330F8);

#include "m2c_macros.h"
void AddEpNode__7EnvHeliP9_hierhead(void* arg0, void* arg1) {
    s32 temp_a2;

    temp_a2 = M2C_FIELD_V1(arg1, s32* , 0);
    if ((temp_a2 & 0xFFFC0000) == 0x9C800000) {
        if ((temp_a2 & 0x3F) == 3) {
            M2C_FIELD_V1(arg0, void** , 0x298) = (void* ) M2C_FIELD_V1(arg1, void** , 0x1C);
            return;
        }
        M2C_FIELD_V1(arg0, void** , 0x298) = arg1;
        return;
    }
    M2C_FIELD_V1(arg0, void** , 0x294) = arg1;
}
