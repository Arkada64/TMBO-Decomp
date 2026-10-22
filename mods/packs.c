/* TMB-Reloaded mod: restore retail content the online maps lost, from "packs" on the disc.
 * Peds: online FREEWAY/PRISON have no pedestrian models (retail had them). A pack is the retail ped subtree
 * (model nodes 3000-3999 + everything they point to), its textures (TEX records), CLUTs (RTX records) and the
 * list of its animation characters, built offline by TMB Decomp/mkpack.py + texpack.py and placed by
 * mkblobs.py at fixed free addresses of the online memory map (tail of the level NGP slot, the gap after the
 * 8 car NGP slots, tail of the level TEX slot) with absolute pointers. Files: \PCAR\<NAME><n>.BIN; blob 0
 * starts with a manifest. Two hooks (tools/mods/apply_mods.py):
 * 1. Level TEX init (func_00188930: jal func_0023D560 at 0x1889E4 -> tmbr_LevelTexInitStub, which passes the
 *    shell in $a2): read the blobs; add the pack's texture counts to the level TEX header's size classes
 *    before the original builds the texture bins (else the pack's textures take the cars' bin entries and
 *    cars show garbage textures when many peds are on screen); upload the CLUTs right after the level's own
 *    (D_006F268C); register the textures as file slot 9 with ids after the level's (ids >= 1000 are rejected,
 *    cars use 600..999).
 * 2. Level db init (LoadLevelDB: jal func_00127330 at 0x18890C -> tmbr_LevelDbLoaded): patch the model's
 *    texture-id slots and GS TEX0 CBPs; put the pack's animation characters into global animation table 0
 *    (a merged copy of the level's; animationGetHandle finds a ped's clips by its id there); walk the entry
 *    points with the online level loader callback (func_00127650), which the baked "Pedestrians Online"
 *    patch routes to addPedEpNode: the peds join the pool like the level's own.
 * Only in the online fixed-slot layout (D_004FAE38 set). Status lines go to the emulog (scePrintf). */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned long u64;

extern void dbInitSlot(int ngp, int vram, int slot) __asm__("func_00127330");
extern int fileRead(const char* name, void* dst) __asm__("func_002006D0");
extern int getMaxTexId(int i) __asm__("getMaxTexId__Fi");
extern int texIdBase(int slot) __asm__("func_00200C20");
extern void setTexIdBase(int slot, int base) __asm__("func_00200C80");
extern u32 clutBase(int slot) __asm__("func_00200C68");
extern u32 resBase(int slot) __asm__("func_00200C50");
extern void setClutBase(int slot, u32 words) __asm__("func_00200CC8");
extern void rtxUpload(void* rtx) __asm__("func_0023E628");
extern void texRegister(int vram, int slot) __asm__("func_0023D560");
extern void dbsTraverse(void* ep, void* cb, void* vec) __asm__("func_001FE4D0");
extern void dbLevelCallback(void) __asm__("func_00127650");
extern void animInit(void* anim, void* chr, int i) __asm__("func_001FDE28");
extern int scePrintf(const char* fmt, ...);
extern int D_004FAE38;    /* online fixed slot layout */
extern u32 D_006F268C;    /* end of the CLUTs loaded so far (blocks): the level's, right after its RTX init */
extern u32 D_004CEC78, D_004CEC7C; /* texm VRAM cursors, moved by rtxUpload */
extern int D_004F9714;    /* db index being walked */
extern u32 D_0048AC10[];  /* file table: [0..13] TEX file addresses */
extern u32 D_00465E68[];  /* global animation table per db (op7 nodes) */
extern unsigned char D_004FB748; /* PedPimp: number of peds in the pool */

#define PACK_SLOT 9
#define TMBR_PRISON_BISECT 0  /* 1: Prison loads cycle read-only / CLUTs only / textures only / full */
#define MAGIC 0x50424D54
#define LEVEL_TEX 0x1C05670
typedef struct { char name[16]; u32 addr, size; } Blob;
typedef struct {
    u32 magic, version, nblobs, hdr, pairs, npairs, tex, rtx, clutBlocks, ntex;
    u32 anims, nanims, animTable, animCap, pad[2];
    Blob blob[4];
} Manifest;

static const struct { int level; const char* blob0; u32 addr; } PACKS[] = {
    { 2, "\\PCAR\\ZFP0.BIN;1", 0x1E7F280 }, /* FREEWAY */
    { 3, "\\PCAR\\ZRP0.BIN;1", 0x15FB980 }, /* PRISON */
};
static float zeroVec[4];
static Manifest* pending;   /* loaded at TEX init, finished at db init */
int tmbr_levelSerial;       /* bumped on every level load (traffic.c sets up on the next game frame) */
int tmbr_levelIndex = -1;   /* shell level index of the level being loaded */
static u32 texBase, clutStart;

/* TEMP diagnostics */
extern u32 D_004CEC70;    /* number of texture bins */
extern u32 D_004CEB70[];  /* bins: (count, block size) */
extern u32 D_004CEC84;    /* small-VRAM mode */
extern u32 D_004CEC88[];  /* textures registered per file slot */
static int diagPrisonLoads, diagFrame, diagMode;
static u32 diagSum[4], diagCnt[14];
static Manifest* diagWatch;
static u32 sum32(u32 a, u32 n)
{
    u32 s = 0, *p = (u32*)a;
    for (n >>= 2; n; n--) s = (s << 1 | s >> 31) ^ *p++;
    return s;
}
static int binFor(u32 bs)
{
    u32 i;
    for (i = 0; i < D_004CEC70; i++) if (D_004CEB70[2 * i + 1] == bs) return i;
    return -1;
}
static void diagBins(int vram, int level)
{
    u32 i, bytes = 0;
    scePrintf("TMBR diag: level %d vram %x small %d bins %d:", level, vram, D_004CEC84, D_004CEC70);
    for (i = 0; i < D_004CEC70; i++) {
        scePrintf(" %dx%d", D_004CEB70[2 * i], D_004CEB70[2 * i + 1]);
        bytes += D_004CEB70[2 * i] * D_004CEB70[2 * i + 1];
    }
    scePrintf(" | paging %x..%x (%d KB)\n", D_004CEC7C, D_004CEC78, bytes >> 10);
}

static Manifest* readPack(const char* blob0, u32 addr)
{
    Manifest* m = (Manifest*)addr;
    u32 i;
    int got = fileRead(blob0, (void*)addr);
    if (got <= 0 || m->magic != MAGIC || m->version != 2 || m->nblobs > 4 || m->blob[0].addr != addr) {
        scePrintf("TMBR pack %s: not on disc or bad (%d)\n", blob0, got);
        return 0;
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
            return 0;
        }
    }
    return m;
}

/* level TEX header: u32 nclass, u32 recq, nclass x (u32 count, u32 blocksize) */
static void binCounts(u32* level, u32* pack, int sign)
{
    u32 i, j;
    for (i = 0; i < pack[0]; i++)
        for (j = 0; j < level[0]; j++)
            if (level[2 + 2 * j + 1] == pack[2 + 2 * i + 1]) {
                level[2 + 2 * j] += sign * pack[2 + 2 * i];
                break;
            }
}

void tmbr_LevelTexInit(int vram, int slot, char* shell)
{
    int level = *(int*)(shell + 0x18000 + 0x23AC), i, s78, s7C;
    Manifest* m = 0;
    char* r;
    pending = 0;
    if (slot == 0) { tmbr_levelIndex = level; tmbr_levelSerial++; }
    if (D_004FAE38 && slot == 0 && D_0048AC10[0] == LEVEL_TEX)
        for (i = 0; i < (int)(sizeof(PACKS) / sizeof(PACKS[0])); i++)
            if (PACKS[i].level == level) {
                m = readPack(PACKS[i].blob0, PACKS[i].addr);
                scePrintf("TMBR step: pack read %x\n", (u32)m);
                if (m && level == 3 && TMBR_PRISON_BISECT) {
                    diagMode = diagPrisonLoads++ % 4;
                    scePrintf("TMBR diag: Prison load %d, mode %d (%s)\n", diagPrisonLoads, diagMode,
                        diagMode == 0 ? "pack read only" : diagMode == 1 ? "CLUT upload only" :
                        diagMode == 2 ? "texture registration only" : "full");
                    if (diagMode == 0) m = 0;
                } else diagMode = 3;
            }
    if (m && diagMode == 1) binCounts((u32*)LEVEL_TEX, (u32*)m->tex, 0);
    else if (m) binCounts((u32*)LEVEL_TEX, (u32*)m->tex, 1);
    /* our CLUTs go to the start of the texture paging area (clutBase(9)), which moves up by whole pages before
     * texm builds its bins: VRAM right after the level's CLUTs (D_006F268C) is used by something car-related
     * (uploading there corrupted car textures on PRISON) */
    if (m) {
        clutStart = clutBase(PACK_SLOT) >> 6;
        setClutBase(PACK_SLOT, clutBase(PACK_SLOT) + ((m->clutBlocks + 31) & ~31) * 64);
    }
    texRegister(vram, slot); /* the original call: level textures + texture bins */
    if (slot == 0) {
        diagBins(vram, level);
        for (i = 0; i < 14; i++) diagCnt[i] = 0;
    }
    diagWatch = 0;
    if (!m) return;
    binCounts((u32*)LEVEL_TEX, (u32*)m->tex, diagMode == 1 ? 0 : -1);
    texBase = getMaxTexId(0);
    if (texBase + m->ntex >= (u32)texIdBase(1)) {
        scePrintf("TMBR pack: no room (tex id %d+%d, clut %d+%d)\n", texBase, m->ntex, clutStart, m->clutBlocks);
        return;
    }
    /* CLUTs: into the level's CLUT area after its own, upload (keep texm's VRAM cursors) */
    r = (char*)m->rtx;
    while (*(u32*)r) {
        *(u16*)(r + 0xA) += clutStart;
        r += *(u32*)r * 4;
    }
    s78 = D_004CEC78; s7C = D_004CEC7C;
    if (diagMode != 2) rtxUpload((void*)m->rtx);
    D_004CEC78 = s78; D_004CEC7C = s7C;
    scePrintf("TMBR step: cluts %s\n", diagMode != 2 ? "uploaded" : "skipped");
    /* textures: file slot 9, ids after the level's */
    if (diagMode != 1) {
        D_0048AC10[PACK_SLOT] = m->tex;
        setTexIdBase(PACK_SLOT, texBase);
        texRegister(vram, PACK_SLOT);
    }
    scePrintf("TMBR step: textures %s; res base 0:%x 1:%x 8:%x 9:%x, clut base 1:%x 9:%x\n",
        diagMode != 1 ? "registered" : "skipped", resBase(0), resBase(1), resBase(8), resBase(9),
        clutBase(1) >> 6, clutBase(9) >> 6);
    pending = m;
    diagWatch = m;
    for (i = 0; i < (int)m->nblobs; i++) diagSum[i] = sum32(m->blob[i].addr, m->blob[i].size);
}

/* TEMP diagnostics (Prison car textures): called every game frame from tmbr_TrafficUpdate */
void tmbr_PackWatch(void)
{
    u32 i, j, *h;
    if (++diagFrame % 60) return;
    for (i = 1; i <= 8; i++)
        if (D_004CEC88[i] != diagCnt[i]) {
            diagCnt[i] = D_004CEC88[i];
            h = (u32*)D_0048AC10[i];
            scePrintf("TMBR diag: car slot %d: %d textures, tex %x, idbase %d maxid %d, clut %d res %d", i, diagCnt[i],
                (u32)h, texIdBase(i), getMaxTexId(i), clutBase(i) >> 6, resBase(i));
            if (h && h[0] < 16)
                for (j = 0; j < h[0]; j++)
                    scePrintf(" [%d x %d bin %d]", h[2 + 2 * j], h[3 + 2 * j], binFor(h[3 + 2 * j]));
            scePrintf("\n");
        }
    if (diagWatch)
        for (i = 0; i < diagWatch->nblobs; i++)
            if (diagSum[i] != sum32(diagWatch->blob[i].addr, diagWatch->blob[i].size)) {
                scePrintf("TMBR diag: blob %d (%x) CHANGED at frame %d\n", i, diagWatch->blob[i].addr, diagFrame);
                diagSum[i] = sum32(diagWatch->blob[i].addr, diagWatch->blob[i].size);
            }
}

void tmbr_LevelDbLoaded(int ngp, int vram, int slot)
{
    Manifest* m = pending;
    u32 i, j, n, *p, *hdr, *lvl, *tab, *chr;
    int saveDb, before;
    if (slot == 0) scePrintf("TMBR step: db init (pack %x)\n", m);
    dbInitSlot(ngp, vram, slot);
    if (!m || slot != 0) return;
    pending = 0;
    scePrintf("TMBR step: db init done\n");
    if (diagMode != 3) return;
    /* model texture-id slots + GS TEX0 CBPs */
    p = (u32*)m->pairs;
    for (i = 0; i < m->npairs; i++, p += 2) {
        if (p[0]) *(u16*)p[0] += texBase;
        if (p[1]) {
            u64 w = *(u64*)p[1];
            u64 cbp = ((w >> 37) & 0x3FFF) + clutStart;
            *(u64*)p[1] = (w & ~((u64)0x3FFF << 37)) | ((cbp & 0x3FFF) << 37);
        }
    }
    /* animation characters: merged copy of the level's table 0 + ours, then initialise ours */
    lvl = (u32*)D_00465E68[0];
    tab = (u32*)m->animTable;
    n = lvl ? lvl[1] : 0;
    if (lvl && n + m->nanims <= m->animCap) {
        tab[0] = lvl[0];
        tab[1] = n + m->nanims;
        for (i = 0; i < n; i++) tab[2 + i] = lvl[2 + i];
        for (i = 0; i < m->nanims; i++) {
            tab[2 + n + i] = ((u32*)m->anims)[i];
            chr = (u32*)((u32*)m->anims)[i];
            chr[0x24 / 4] = 0;
            for (j = 0; j < *(u16*)chr[0x20 / 4]; j++)
                animInit((void*)((u32*)chr[0x20 / 4])[2 + j], chr, j);
        }
        D_00465E68[0] = (u32)tab;
    } else {
        scePrintf("TMBR pack: animation table not merged (level %p, %d + %d > %d)\n", lvl, n, m->nanims, m->animCap);
    }
    scePrintf("TMBR step: pairs + anims done\n");
    /* walk the entry points with the level loader callback (peds -> addPedEpNode) */
    hdr = (u32*)m->hdr;
    saveDb = D_004F9714;
    D_004F9714 = 0;
    before = D_004FB748;
    for (i = 0; i < hdr[0]; i++)
        dbsTraverse(&hdr[1 + i], (void*)dbLevelCallback, zeroVec);
    D_004F9714 = saveDb;
    scePrintf("TMBR pack: %d blobs, %d entry points, tex ids %d.., clut %d.. (%d), anims %d+%d, peds in pool %d -> %d\n",
        m->nblobs, hdr[0], texBase + 1, clutStart, m->clutBlocks, n, m->nanims, before, D_004FB748);
    for (i = 0; i < m->nblobs; i++) diagSum[i] = sum32(m->blob[i].addr, m->blob[i].size); /* after our own patching */
}
