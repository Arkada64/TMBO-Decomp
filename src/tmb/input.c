#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputInit__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputClearInputs__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputUpdate__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputUpdateState__Fii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputLgUpdate__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputLgConvertPositionData__FiP13lgDevPosition);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputSetActuator__FiUcUci);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputUsingActuator__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputUseActuator__Fib);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputSetPlayerActuator__Fib);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputUseLgActuator__Fib);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputAnyKey__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputIsCtlAvailable__Fib);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputGetPadButtons__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputGetPadType__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputGetCtlPadState__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputGetPadAnalog__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputSetInputMode__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputSetAlternateButtons__Fii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputGetAlternateButtons__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputGetPlayerPad__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputIsMtapConnected__Fv);

int inputAnyKey__Fi_5C_75(int) __asm__("inputAnyKey__Fi");
extern u8 keyWasAlreadyDown_5C_75[] __asm__("keyWasAlreadyDown");

s32 inputGetAnyInput__Fi(s32 arg0) {
    s32* temp_s0;

    temp_s0 = (arg0 * 4) + ((u8*)keyWasAlreadyDown_5C_75);
    if (*temp_s0 == 0) {
        if (inputAnyKey__Fi_5C_75(arg0) != 0) {
            *temp_s0 = 1;
            return 1;
        }
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputGetInput__Fii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputGetAnalogButton__Fii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputGetCtlPadAnalogAxis__Fii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputGetShellAnalogInput__Fii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputUsingUSB__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputFixAnalogValue__Fii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputScaleAnalogButton__Fiii);

extern u8 padPortMap_18_97[] __asm__("padPortMap");

volatile int inputGetPadPort__Fi(s32 arg0)
{
  s32 *new_var2;
  u8 *new_var;
  new_var2 = &arg0;
  new_var = ((*new_var2) * 4) + ((u8 *) padPortMap_18_97);
  new_var2 = &(*new_var);
  return *new_var2;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputGetPadSlot__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputSetSpringSaturation__Fii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputLgInitForces__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputSetLgSpringOffset__Fii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputSetLgSpringEffect__Fiiiii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputStartLgSpringEffect__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputStopLgSpringEffect__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputSetLgCollisionEffect__Fiiii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputStartLgCollisionEffect__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputStopLgCollisionEffect__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputSetLgSmallActuatorEffect__Fiii);

void inputStartLgEffect__FiPi_8C_133(int, void*) __asm__("inputStartLgEffect__FiPi");
extern u8 smallActuatorEffectId_8C_133[] __asm__("smallActuatorEffectId");
extern u8 smallActuatorStarted_8C_133[] __asm__("smallActuatorStarted");

void inputStartLgSmallActuatorEffect__Fi(s32 arg0) {
    s32 temp_s1;
    s32* temp_v1;

    temp_v1 = (arg0 * 4) + ((u8*)smallActuatorStarted_8C_133);
    if (*temp_v1 == 0) {
        temp_s1 = arg0 * 8;
        *temp_v1 = 1;
        inputStartLgEffect__FiPi_8C_133(arg0, temp_s1 + ((u8*)smallActuatorEffectId_8C_133));
        inputStartLgEffect__FiPi_8C_133(arg0, temp_s1 + (((u8*)smallActuatorEffectId_8C_133) + 4));
    }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputStopLgSmallActuatorEffect__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputSetLgLargeActuatorEffect__Fiiiiii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputStartLgLargeActuatorEffect__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputStopLgLargeActuatorEffect__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputStopLgEffect__FiPi);

s32 lgDevStartForceEffect_78_151() __asm__("lgDevStartForceEffect");
extern u8 usbDeviceId_78_151[] __asm__("usbDeviceId");

void inputStartLgEffect__FiPi(s32 arg0, s32* arg1) {
    s32 temp_a0;
    s32 temp_a1;
    s32* temp_s1;

    temp_s1 = (arg0 * 4) + ((u8*)usbDeviceId_78_151);
    temp_a0 = *temp_s1;
    if (temp_a0 != -1) {
        temp_a1 = *arg1;
        if ((temp_a1 != -1) && (lgDevStartForceEffect_78_151(temp_a0, temp_a1) == 0x80000006)) {
            *temp_s1 = -1;
            *arg1 = -1;
        }
    }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputSetLgTurningFriction__Fif);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/input", inputUsingTypeAWheel__Fi);

extern u8 lgCombo_18_159[] __asm__("lgCombo");

s32 inputGetLogitechCombo__Fi(s32 arg0)
{
  s32 new_var2;
  s32 *new_var;
  u8 *new_var3;
  new_var2 = *(new_var = &arg0);
  new_var3 = (new_var2 * 4) + ((u8 *) lgCombo_18_159);
  new_var = &(*new_var3);
  return *new_var;
}

extern u8 lgCombo_18_162[] __asm__("lgCombo");

s32 inputClearLogitechCombo__Fi(s32 arg0)
{
  u8 *new_var2;
  s32 *new_var;
  new_var2 = (u8 *) lgCombo_18_162;
  ;
  new_var = ((*(&arg0)) * 4) + new_var2;
  *new_var = 0;
  return (s32) new_var2;
}
