#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/pickup_part2", AddPickupEpNode__7PickupsiP9_hierhead);

#include "m2c_macros.h"
void func_0017AC58(void* arg0, s32 arg1, s32 arg2) {
    if (arg1 == 0x1E17) {
        M2C_FIELD_V1(arg0, s32* , 0x48) = arg2;
    }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/pickup_part2", func_0017AC70);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/pickup_part2", func_0017AD10);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/pickup_part2", func_0017AE20);

#include "m2c_macros.h"
void AddPickupsByTypeEntry__7Pickupsi(s32 arg0, s32 arg1)
{
  s32 temp_v1;
  int new_var;
  s32 *temp_a2;
  temp_v1 = (*((s32 *) (((u8 *) ((arg1 * 0x18) + arg0)) + 0x5C))) * 4;
  new_var = 0x2804;
  temp_a2 = (arg0 + new_var) + temp_v1;
  *((s32 *) (((u8 *) (arg0 + (((*temp_a2) * 0x48) + temp_v1))) + 0xA7C)) = arg1;
  *temp_a2 += 1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/pickup_part2", func_0017AF50);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/pickup_part2", ChangePickupType__7Pickupsii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/pickup_part2", LoadRegenTimes__7Pickups);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/pickup_part2", TakeHit__7PickupsP7VehicleP3_csb);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/pickup_part2", GetClosestPickup__7PickupsP8_fvectori);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/pickup_part2", ResetAllPickups__7Pickups);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/pickup_part2", pickupGetPickupsWeaponType__7PickupsP3_cs);
