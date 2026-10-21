#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", func_00215F50);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", inputClearInputs__Fi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", func_002165A0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", func_00216840);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", func_00216D70);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", inputLgConvertPositionData__FiP13lgDevPosition);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", inputSetActuator__FiUcUci);

#include "m2c_macros.h"
extern M2C_UNK D_00612CA0_or__Fi __asm__("D_00612CA0");

s32 inputUsingActuator__Fi(s32 arg0) {
    return *((arg0 * 0x1) + &D_00612CA0_or__Fi);
}

#include "m2c_macros.h"
#include "m2c_macros.h"
extern M2C_UNK D_00612CA0_r__Fib __asm__("D_00612CA0");

void inputUseActuator__Fib(s32 arg0, s32 arg1)
{
  int new_var;
  s32 new_var2;
  new_var = new_var * 4;
  new_var = arg0;
  new_var2 = arg1;
  *(new_var + (&D_00612CA0_r__Fib)) = new_var2;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", inputSetPlayerActuator__Fib);

#include "m2c_macros.h"
extern M2C_UNK D_00612DA0_r__Fib __asm__("D_00612DA0");

void inputUseLgActuator__Fib(s32 arg0, s32 arg1) {
    *((arg0 * 0x1) + &D_00612DA0_r__Fib) = arg1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", inputAnyKey__Fi);

#include "m2c_macros.h"
#include "m2c_macros.h"
extern M2C_UNK D_00612CC0_e__Fib __asm__("D_00612CC0");

s32 inputIsCtlAvailable__Fib(s32 arg0)
{
  s32 new_var;
  M2C_UNK *new_var2;
  M2C_UNK *new_var3;
  new_var3 = &D_00612CC0_e__Fib;
  new_var = 2 * (new_var * 2);
  new_var2 = new_var3;
  return *(arg0 + new_var2);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", inputGetPadButtons__Fi);

#include "m2c_macros.h"
extern M2C_UNK D_004B1340_pe__Fi __asm__("D_004B1340");

s32 inputGetPadType__Fi(s32 arg0) {
    return *((arg0 * 0x1) + &D_004B1340_pe__Fi);
}

#include "m2c_macros.h"
extern M2C_UNK D_00612BA0_te__Fi __asm__("D_00612BA0");

s32 inputGetCtlPadState__Fi(s32 arg0) {
    return *((arg0 * 0x1) + &D_00612BA0_te__Fi);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", inputGetPadAnalog__Fi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", func_00217A48);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", inputSetAlternateButtons__Fii);

#include "m2c_macros.h"
extern unsigned char D_004B1360_ns__Fi __asm__("D_004B1360");

s32 inputGetAlternateButtons__Fi(s32 arg0)
{
  M2C_UNK *new_var;
  new_var = (arg0 * 4) + (&D_004B1360_ns__Fi);
  return *new_var;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", inputGetPlayerPad__Fi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", inputIsMtapConnected__Fv);

#include "m2c_macros.h"
s32 inputAnyKey__Fi_217BE8() __asm__("inputAnyKey__Fi");
extern char D_00612C20_217BE8 __asm__("D_00612C20");

s32 func_00217BE8(s32 arg0)
{
  s32 *temp_s0;
  temp_s0 = (arg0 * 4) + (&D_00612C20_217BE8);
  if ((*temp_s0) == 0)
  {
    if (inputAnyKey__Fi_217BE8(arg0, arg0) != 0)
    {
      *temp_s0 = 1;
      return 1;
    }
    return 0;
  }
  return 0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", inputGetInput__Fii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", inputGetAnalogButton__Fii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", inputGetCtlPadAnalogAxis__Fii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", inputGetShellAnalogInput__Fii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", func_00218260);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", inputFixAnalogValue__Fii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", func_00218600);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", inputScaleAnalogButton__Fiii);

#include "m2c_macros.h"
#include "m2c_macros.h"
extern M2C_UNK D_00612B60_rt__Fi __asm__("D_00612B60");

s32 inputGetPadPort__Fi(s32 arg0)
{
  long new_var2;
  int new_var;
  new_var2 = new_var * 4;
  new_var = new_var2;
  new_var = arg0;
  return *(new_var + (&D_00612B60_rt__Fi));
}

#include "m2c_macros.h"
extern M2C_UNK D_00612B80_ot__Fi __asm__("D_00612B80");

s32 inputGetPadSlot__Fi(s32 arg0) {
    return *((arg0 * 0x1) + &D_00612B80_ot__Fi);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", func_00218A30);

#include "m2c_macros.h"
extern M2C_UNK D_00612CC0_218A80 __asm__("D_00612CC0");

s32 func_00218A80(s32 arg0, s32 arg1) {
    *((arg0 * 0x1) + &D_00612CC0_218A80) = arg1;
    return arg1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", func_00218AA0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", inputLgInitForces__Fi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", inputSetLgSpringOffset__Fii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", inputSetLgSpringEffect__Fiiiii);

#include "m2c_macros.h"
M2C_UNK func_002194B8_218E08() __asm__("func_002194B8");
extern M2C_UNK D_00613800_218E08 __asm__("D_00613800");

void func_00218E08(s32 arg0) {
    func_002194B8_218E08(arg0, (arg0 * 0x1) + &D_00613800_218E08);
}

#include "m2c_macros.h"
M2C_UNK func_00219470_218E30() __asm__("func_00219470");
extern M2C_UNK D_00613800_218E30 __asm__("D_00613800");

void func_00218E30(s32 arg0) {
    func_00219470_218E30(arg0, (arg0 * 0x1) + &D_00613800_218E30);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", func_00218E58);

#include "m2c_macros.h"
M2C_UNK func_002194B8_218F90() __asm__("func_002194B8");
extern M2C_UNK D_00613820_218F90 __asm__("D_00613820");

void func_00218F90(s32 arg0) {
    func_002194B8_218F90(arg0, (arg0 * 0x1) + &D_00613820_218F90);
}

#include "m2c_macros.h"
M2C_UNK func_00219470_218FB8() __asm__("func_00219470");
extern M2C_UNK D_00613820_218FB8 __asm__("D_00613820");

void func_00218FB8(s32 arg0) {
    func_00219470_218FB8(arg0, (arg0 * 0x1) + &D_00613820_218FB8);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", func_00218FE0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", inputStartLgSmallActuatorEffect__Fi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", inputStopLgSmallActuatorEffect__Fi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", func_002192B0);

#include "m2c_macros.h"
M2C_UNK func_002194B8_219420() __asm__("func_002194B8");
extern M2C_UNK D_00613880_219420 __asm__("D_00613880");

void func_00219420(s32 arg0) {
    func_002194B8_219420(arg0, (arg0 * 0x1) + &D_00613880_219420);
}

#include "m2c_macros.h"
M2C_UNK func_00219470_219448() __asm__("func_00219470");
extern M2C_UNK D_00613880_219448 __asm__("D_00613880");

void func_00219448(s32 arg0) {
    func_00219470_219448(arg0, (arg0 * 0x1) + &D_00613880_219448);
}

#include "m2c_macros.h"
M2C_UNK lgDevStopForceEffect_219470() __asm__("lgDevStopForceEffect");
extern M2C_UNK D_00612D80_219470 __asm__("D_00612D80");

void func_00219470(s32 arg0, s32* arg1) {
    s32 temp_a0;
    s32 temp_a1;

    temp_a0 = *((arg0 * 0x1) + &D_00612D80_219470);
    if (temp_a0 != -1) {
        temp_a1 = *arg1;
        if (temp_a1 != -1) {
            lgDevStopForceEffect_219470(temp_a0, temp_a1);
        }
    }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", func_002194B8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", inputSetLgTurningFriction__Fif);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/input", inputUsingTypeAWheel__Fi);

#include "m2c_macros.h"
extern M2C_UNK D_00613AC0_bo__Fi __asm__("D_00613AC0");

s32 inputGetLogitechCombo__Fi(s32 arg0) {
    return *((arg0 * 0x1) + &D_00613AC0_bo__Fi);
}

#include "m2c_macros.h"
#include "m2c_macros.h"
extern M2C_UNK D_00613AC0_bo__Fi __asm__("D_00613AC0");

void inputClearLogitechCombo__Fi(s32 arg0)
{
  int new_var;
  s32 new_var2;
  new_var2 = arg0;
  new_var = new_var2;
  *(new_var + (&D_00613AC0_bo__Fi)) = 0;
  new_var = new_var * 4;
}
