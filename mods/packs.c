/* TMB-Reloaded mod: restore retail content the online maps lost, from "packs" on the disc.
 * Peds: online FREEWAY/PRISON have no pedestrian models (retail had them). A pack is the retail ped subtree
 * (model nodes 3000-3999 + everything they point to), its textures (TEX records) and CLUTs (RTX records),
 * built offline by TMB Decomp/mkpack.py + texpack.py and placed by mkblobs.py at fixed free addresses of the
 * online memory map (tail of the level NGP slot, the gap after the 8 car NGP slots, tail of the level TEX
 * slot) with absolute pointers. Files: \PCAR\<NAME><n>.BIN; blob 0 starts with a manifest.
 * Hook (tools/mods/apply_mods.py): LoadLevelDB's level db init (jal func_00127330 at 0x18890C) goes to
 * tmbr_LevelDbLoaded, which runs it and then loads the pack for this level:
 *   - CLUTs go right after the level's own CLUTs in the level's CLUT area (slot 0): record addrs and the
 *     GS TEX0 words' CBP += that end. (Slot 9's CLUT base is where texture paging starts: not usable.)
 *   - textures: ids 1..n become levelMaxId+1.., registered through func_0023D560 with file slot 9 pointing
 *     at the pack's TEX (ids >= 1000 are rejected, car slots use 600..999, the level < 600).
 *   - the pack's entry points are walked with the online level loader callback (func_00127650), which the
 *     baked "Pedestrians Online" patch routes to addPedEpNode: the peds join the pool like the level's own.
 * Only in the online fixed-slot layout (D_004FAE38 set). Status lines go to the emulog (scePrintf). */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned long u64;

extern void dbInitSlot(int ngp, int vram, int slot) __asm__("func_00127330");
extern char* getGenericName(int i) __asm__("getGenericName__Fi");
extern int getNgpAddr(int i) __asm__("getNgpAddr__Fi");
extern int getMaxTexId(int i) __asm__("getMaxTexId__Fi");
extern int fileRead(const char* name, void* dst) __asm__("func_002006D0");
extern int texIdBase(int slot) __asm__("func_00200C20");
extern void setTexIdBase(int slot, int base) __asm__("func_00200C80");
extern u32 clutBase(int slot) __asm__("func_00200C68");
extern void rtxUpload(void* rtx) __asm__("func_0023E628");
extern void texRegister(int vram, int slot) __asm__("func_0023D560");
extern void dbsTraverse(void* ep, void* cb, void* vec) __asm__("func_001FE4D0");
extern void dbLevelCallback(void) __asm__("func_00127650");
extern int scePrintf(const char* fmt, ...);
extern int D_004FAE38;    /* online fixed slot layout */
extern u32 D_006F268C;    /* end of the CLUTs loaded so far (blocks), level after its RTX init */
extern u32 D_004CEC78, D_004CEC7C; /* texm VRAM cursors, moved by rtxUpload */
extern int D_004F9714;    /* db index being walked */
extern u32 D_0048AC10[];  /* file table: [0..13] TEX file addresses */
extern unsigned char D_004FB748; /* PedPimp: number of peds in the pool */

#define PACK_SLOT 9
#define MAGIC 0x50424D54
typedef struct { char name[16]; u32 addr, size; } Blob;
typedef struct {
    u32 magic, version, nblobs, hdr, pairs, npairs, tex, rtx, clutBlocks, ntex;
    u32 pad[6];
    Blob blob[4];
} Manifest;

static const struct { const char* level; const char* blob0; u32 addr; } PACKS[] = {
    { "FREEWAY", "\\PCAR\\ZFP0.BIN;1", 0x1E7F280 },
    { "PRISON", "\\PCAR\\ZRP0.BIN;1", 0x15FB980 },
};
static float zeroVec[4];

static int same(const char* a, const char* b)
{
    while (*a && *b) {
        char x = *a++, y = *b++;
        if (x >= 'a' && x <= 'z') x -= 32;
        if (y >= 'a' && y <= 'z') y -= 32;
        if (x != y) return 0;
    }
    return *a == *b;
}

static void loadPack(int vram, const char* blob0, u32 addr)
{
    Manifest* m = (Manifest*)addr;
    u32* hdr;
    u32 i, base, cbase, *p;
    char* r;
    int got = fileRead(blob0, (void*)addr), save78, save7C, saveDb;
    if (got <= 0 || m->magic != MAGIC || m->nblobs > 4 || m->blob[0].addr != addr) {
        scePrintf("TMBR pack %s: not on disc or bad (%d)\n", blob0, got);
        return;
    }
    for (i = 1; i < m->nblobs; i++) {
        char name[32];
        char* s = name;
        const char* q = "\\PCAR\\";
        while (*q) *s++ = *q++;
        q = m->blob[i].name;
        while (*q) *s++ = *q++;
        *s++ = ';'; *s++ = '1'; *s = 0;
        got = fileRead(name, (void*)m->blob[i].addr);
        if (got != (int)m->blob[i].size) {
            scePrintf("TMBR pack: %s read %d, want %d\n", name, got, m->blob[i].size);
            return;
        }
    }
    base = getMaxTexId(0);
    cbase = D_006F268C;
    if (base + m->ntex >= (u32)texIdBase(1) || cbase + m->clutBlocks > (clutBase(1) >> 6)) {
        scePrintf("TMBR pack: no room (tex id %d+%d, clut %d+%d)\n", base, m->ntex, cbase, m->clutBlocks);
        return;
    }
    /* CLUTs: relocate into the level's CLUT area and upload (keep texm's VRAM cursors) */
    r = (char*)m->rtx;
    while (*(u32*)r) {
        *(u16*)(r + 0xA) += cbase;
        r += *(u32*)r * 4;
    }
    save78 = D_004CEC78; save7C = D_004CEC7C;
    rtxUpload((void*)m->rtx);
    D_004CEC78 = save78; D_004CEC7C = save7C;
    /* textures: register as file slot 9 with ids after the level's */
    D_0048AC10[PACK_SLOT] = m->tex;
    setTexIdBase(PACK_SLOT, base);
    texRegister(vram, PACK_SLOT);
    /* model texture slots + GS TEX0 words */
    p = (u32*)m->pairs;
    for (i = 0; i < m->npairs; i++, p += 2) {
        if (p[0]) *(u16*)p[0] += base;
        if (p[1]) {
            u64 w = *(u64*)p[1];
            u64 cbp = ((w >> 37) & 0x3FFF) + cbase;
            *(u64*)p[1] = (w & ~((u64)0x3FFF << 37)) | ((cbp & 0x3FFF) << 37);
        }
    }
    /* walk the entry points with the level loader callback (peds -> addPedEpNode) */
    hdr = (u32*)m->hdr;
    saveDb = D_004F9714;
    D_004F9714 = 0;
    got = D_004FB748;
    for (i = 0; i < hdr[0]; i++)
        dbsTraverse(&hdr[1 + i], (void*)dbLevelCallback, zeroVec);
    D_004F9714 = saveDb;
    scePrintf("TMBR pack %s: %d blobs, %d entry points, tex ids %d.., clut %d.. (%d), peds in pool %d -> %d\n",
        blob0, m->nblobs, hdr[0], base + 1, cbase, m->clutBlocks, got, D_004FB748);
}

void tmbr_LevelDbLoaded(int ngp, int vram, int slot)
{
    const char* lvl;
    int i;
    dbInitSlot(ngp, vram, slot);
    lvl = getGenericName(0);
    for (i = 0; i < (int)(sizeof(PACKS) / sizeof(PACKS[0])); i++) {
        if (!same(lvl, PACKS[i].level))
            continue;
        if (!D_004FAE38 || slot != 0 || getNgpAddr(0) != 0x980000 || D_0048AC10[0] != 0x1C05670) {
            scePrintf("TMBR pack %s: skipped, unexpected memory layout (%d %d %x %x)\n", lvl, D_004FAE38, slot,
                getNgpAddr(0), D_0048AC10[0]);
            return;
        }
        loadPack(vram, PACKS[i].blob0, PACKS[i].addr);
    }
}
