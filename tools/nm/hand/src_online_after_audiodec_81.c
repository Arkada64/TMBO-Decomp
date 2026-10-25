//@@ func_00246FC0 hand
/* stores its 4th argument, then calls func_00246FE8 with the same four arguments (the asm leaves a0-a3 as they
 * came in). Written by hand to test the "exits at the lobby settings screen" failures: if this exact version
 * still fails there, the build/link of one-function files is the problem, not the drafts. */
extern int D_004FB390;
extern void func_00246FE8(int a0, int a1, int a2, int a3);
void func_00246FC0(int a0, int a1, int a2, int a3)
{
    D_004FB390 = a3;
    func_00246FE8(a0, a1, a2, a3);
}
