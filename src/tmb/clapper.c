#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/clapper", func_00118A00);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/clapper", Init__8Clappers);

#include "m2c_macros.h"
void ClapperClearHits__8Clappers(void *arg0)
{
  *((s32 *) (((u8 *) arg0) + 0x80)) = 0;
 do { } while (0);
  *((s32 *) (((u8 *) arg0) + 0x78)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x7C)) = 0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/clapper", func_00118CD0);
