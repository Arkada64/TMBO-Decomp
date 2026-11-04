//@@ fontDmaFontData__Fv hand
/* Found by the boot bisect: font.c alone stalls (cloud/out/bisect2.log), and inside font.c this one
   function as C is enough (cloud/out/bisect_font.log: MINIMAL CULPRIT fontDmaFontData__Fv).
   Two defects, both fatal:
     - (0x8000 << 0x2D) is a 32-bit shift by 45 (UB) -> 0x10008001 instead of 0x1000000000008001, so the
       GIF A+D tag written into the packet was garbage;
     - the D_004FB5C4 == 2 branch did a 4-byte store where the asm does `sh`, clobbering the next field.
   The asm: dsll32 $6, $6, 13 on 0x8000 (= << 45).
   NB func_002029D8 has the same class of defect but is kept as asm for now: a hand version that reads
   instruction-for-instruction like the asm (same tags, same stores) still hung the boot at UI state 1
   with no TLB misses, i.e. a DMA wait that never completes. It is in logs/nm_skip.txt until that is
   understood. */
void sceGsSyncPath_pf() __asm__("sceGsSyncPath");
void sceGsExecLoadImage_pf() __asm__("sceGsExecLoadImage");
void FlushCache_pf() __asm__("FlushCache");
extern s32 D_004FAEAC_pf __asm__("D_004FAEAC");
extern u16 D_004FB5BC_pf __asm__("D_004FB5BC");
extern s32 D_004FB5C0_pf __asm__("D_004FB5C0");
extern s32 D_004FB5C4_pf __asm__("D_004FB5C4");
extern s32 D_004FB5C8_pf __asm__("D_004FB5C8");
extern s32 D_004FB5CC_pf __asm__("D_004FB5CC");
extern s32 D_00505E30_pf __asm__("D_00505E30");
extern s32 D_00505E90_pf __asm__("D_00505E90");
extern s32 D_00505F30_pf __asm__("D_00505F30");
extern s32 D_002AC880_pf __asm__("D_002AC880");
extern s32 D_002AC8C0_pf __asm__("D_002AC8C0");

void fontDmaFontData__Fv(void) {
    u8* const pkts = (u8*)&D_00505F30_pf;
    s32 t;
    s64 tag;
    u8* p;

    if (D_004FB5C4_pf == 0) return;
    if (D_004FAEAC_pf != 0) {
        sceGsSyncPath_pf(0, 0);
        sceGsExecLoadImage_pf(&D_00505E30_pf, &D_002AC8C0_pf);
    }
    sceGsSyncPath_pf(0, 0);
    FlushCache_pf(0);
    if (D_004FAEAC_pf != 0) {
        sceGsExecLoadImage_pf(&D_00505E90_pf, &D_002AC880_pf);
        sceGsSyncPath_pf(0, 0);
        D_004FAEAC_pf = 0;
    }
    if (D_004FB5C4_pf == 2) {
        *(u16*)(pkts + D_004FB5C8_pf * 0x10) = (u16)D_004FB5BC_pf;
    }
    t = D_004FB5C0_pf;
    tag = ((s64)0x8000 << 0x2D) | 0x8001;
    p = pkts + t * 0x10;
    *((s64*)(p + 8)) = 0xE;
    *((s64*)p) = tag;
    p = pkts + (t + 1) * 0x10;
    D_004FB5C0_pf = t + 2;
    *((s64*)(p + 8)) = 0x4A;
    *((s64*)p) = 0;
    FlushCache_pf(0);
    *(s32*)0x1000A020 = D_004FB5C0_pf;
    *(s32*)0x1000A010 = (s32)(u32)pkts;
    *(s32*)0x1000E010 = 4;
    *(s32*)0x1000A000 = 0x101;
    D_004FB5C4_pf = 1;
    D_004FB5BC_pf = 0;
    D_004FB5C0_pf = D_004FB5CC_pf;
    D_004FB5C8_pf = D_004FB5CC_pf - 2;
}

//@@ func_00202AD8 hand
/* m2c lost the tail call's argument. The asm leaves $4 (the font index) untouched and calls
   func_002029D8, but the draft passed the halved colour bytes, so the packet was written at
   (garbage << 5) past D_00505EF0 - an out-of-bounds write into the neighbouring globals. */
extern s32 D_00505EF0_h__202AD8 __asm__("D_00505EF0");
void func_002029D8_h__202AD8(s32 arg0) __asm__("func_002029D8");

void func_00202AD8(s32 arg0) {
    u8* p = (u8*)((arg0 << 5) + (s32)&D_00505EF0_h__202AD8);
    u32 g = (u32)(p[0x18] >> 1);
    u32 b = (u32)(p[0x1A] >> 1);
    p[0x1B] = 0x80;
    p[0x18] = (u8)g;
    p[0x19] = (u8)(p[0x19] >> 1);
    p[0x1A] = (u8)b;
    func_002029D8_h__202AD8(arg0);
}

//@@ func_00202B30 hand
/* same lost argument: the draft called func_002029D8(0xC0, 0x80), i.e. the blue/alpha constants. */
extern s32 D_00505EF0_h__202B30 __asm__("D_00505EF0");
void func_002029D8_h__202B30(s32 arg0) __asm__("func_002029D8");

void func_00202B30(s32 arg0) {
    u8* p = (u8*)((arg0 << 5) + (s32)&D_00505EF0_h__202B30);
    p[0x1B] = 0x80;
    p[0x18] = 0xFF;
    p[0x19] = 0xC0;
    p[0x1A] = 0x80;
    func_002029D8_h__202B30(arg0);
}

//@@ fontSetColor__Fiiii hand
/* same lost argument: the draft called func_002029D8() with no arguments at all. */
extern s32 D_00505EF0_h__Fiiii __asm__("D_00505EF0");
void func_002029D8_h__Fiiii(s32 arg0) __asm__("func_002029D8");

void fontSetColor__Fiiii(s32 arg0, s8 arg1, s8 arg2, s8 arg3) {
    u8* p = (u8*)((arg0 << 5) + (s32)&D_00505EF0_h__Fiiii);
    p[0x18] = (u8)arg1;
    p[0x1B] = 0x80;
    p[0x19] = (u8)arg2;
    p[0x1A] = (u8)arg3;
    func_002029D8_h__Fiiii(arg0);
}
