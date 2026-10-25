//@@ func_00218AA0 hand
/* steering-wheel spring force for a port: remember the strength, then apply it with the port's other settings
 * (the m2c draft dropped the port - passed straight through in $4 - and the fifth argument: bench 10-25) */
extern void inputSetLgSpringEffect_h(int port, int a, int b, int strength, int c) __asm__("inputSetLgSpringEffect__Fiiiii");
extern int D_006138A0_h[] __asm__("D_006138A0");
extern int D_006138C0_h[] __asm__("D_006138C0");
extern int D_006138E0_h[] __asm__("D_006138E0");
extern int D_00613900_h[] __asm__("D_00613900");
void func_00218AA0(int port, int strength)
{
    D_006138E0_h[port] = strength;
    inputSetLgSpringEffect_h(port, D_006138A0_h[port], D_006138C0_h[port], strength, D_00613900_h[port]);
}
