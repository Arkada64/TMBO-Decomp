/* TMB-Reloaded mod: restore retail content the online maps lost, from "packs" on the disc.
 * Peds: online FREEWAY/PRISON have no pedestrian models (retail had them). A pack is the retail ped subtree
 * (model nodes 3000-3999 + everything they point to), its textures (TEX records), CLUTs (RTX records) and the
 * list of its animation characters, built offline by TMB Decomp/mkpack.py + texpack.py and placed by
 * mkblobs.py at fixed free addresses of the online memory map (tail of the level NGP slot, the gap after the
 * 8 car NGP slots, tail of the level TEX slot) with absolute pointers. Files: \PCAR\<NAME><n>.BIN; blob 0
 * starts with a manifest. Three hooks (tools/mods/apply_mods.py), in load order:
 * 1. Level RTX (func_00188688: jal func_0023EC80 at 0x18873C -> tmbr_LevelRtxStub, shell in $a3): read
 *    blob 0 and append the pack's CLUT records to the level's RTX right after its last CLUT, so the game's own
 *    RTX code relocates and uploads them with the level's (uploading them ourselves later corrupted car
 *    palettes on PRISON, wherever they went).
 * 2. Level TEX (func_00188930: jal func_0023D560 at 0x1889E4 -> tmbr_LevelTexInitStub, shell in $a2): add
 *    the pack's texture counts to the level TEX header's size classes while the texture bins are built.
 * 3. Level db (LoadLevelDB: jal func_00127330 at 0x18890C -> tmbr_LevelDbLoaded), after the level NGP is in:
 *    read all blobs (the NGP-tail blob must not be read before: the previous level's db is still live there
 *    until the new NGP replaces it - FREEWAY after PRISON froze), register the textures as file slot 9 with
 *    ids after the level's (ids >= 1000 are rejected, cars use 600..999), patch the model's texture-id slots
 *    and GS TEX0 CBPs, merge the animation characters into global animation table 0, walk the entry points
 *    with the online level loader callback (func_00127650, routed to addPedEpNode by the baked "Pedestrians
 *    Online" patch): the peds join the pool like the level's own.
 * Only in the online fixed-slot layout (D_004FAE38 set). Status lines go to the emulog (scePrintf). */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned long u64;

extern void dbInitSlot(int ngp, int vram, int slot) __asm__("func_00127330");
extern void rtxInit(int vram, void* rtx, int slot) __asm__("func_0023EC80");
extern int fileRead(const char* name, void* dst) __asm__("func_002006D0");
extern int getMaxTexId(int i) __asm__("getMaxTexId__Fi");
extern void setTexIdBase(int slot, int base) __asm__("func_00200C80");
extern u32 clutBase(int slot) __asm__("func_00200C68");
extern void texRegister(int vram, int slot) __asm__("func_0023D560");
extern void dbsTraverse(void* ep, void* cb, void* vec) __asm__("func_001FE4D0");
extern void dbLevelCallback(void) __asm__("func_00127650");
extern void animInit(void* anim, void* chr, int i) __asm__("func_001FDE28");
extern int scePrintf(const char* fmt, ...);
extern int D_004FAE38;    /* online fixed slot layout */
extern char* D_004FA030;  /* game */
extern int D_004F9714;    /* db index being walked */
extern u32 D_0048AC10[];  /* file table: [0..13] TEX file addresses */
extern u32 D_00465E68[];  /* global animation table per db (op7 nodes) */
extern unsigned char D_004FB748; /* PedPimp: number of peds in the pool */

#define PACK_SLOT 9
#define MAGIC 0x50424D54
#define LEVEL_TEX 0x1C05670
/* blob 0 is read during the level's RTX stage, before its home may be free. LEVEL_TEX + 0x200000 was inside
 * FREEWAY's loading-screen data (corrupt load screen until the map was in). The RAM gap after the car NGP slots
 * is free during loading (blobs that live there are read later, at the db stage). */
#define RTX_SCRATCH 0x1B93480
typedef struct { char name[16]; u32 addr, size; } Blob;
typedef struct {
    u32 magic, version, nblobs, hdr, pairs, npairs, tex, rtx, clutBlocks, ntex;
    u32 anims, nanims, animTable, animCap, pad[2];
    Blob blob[4];
} Manifest;

/* classes: the pack TEX header's (count, block size) list (TMB Decomp/packs/<NAME>.json "classes") */
static const struct { int level; const char* blob0; u32 addr; u32 classes[10]; } PACKS[] = {
    { 2, "\\PCAR\\ZFP0.BIN;1", 0x1E7F280, { 2, 0, 3, 4096, 8, 2048 } }, /* FREEWAY */
    { 3, "\\PCAR\\ZRP0.BIN;1", 0x15FB980, { 2, 0, 4, 4096, 7, 2048 } }, /* PRISON */
    /* retail PRISON's inmates (ped types 9-11) on the two Prison Passage maps (they only have type 2) */
    { 15, "\\PCAR\\ZSP0.BIN;1", 0x1B93480, { 2, 0, 3, 4096, 5, 2048 } }, /* SHIP */
    { 16, "\\PCAR\\ZAP0.BIN;1", 0x1B93480, { 2, 0, 3, 4096, 5, 2048 } }, /* ASYLUM */
    /* retail SUBURB's traffic cars (online stripped them), 2 of each model: traffic.c fod_suburb */
    { 0, "\\PCAR\\ZSF0.BIN;1", 0x1E57C00, { 4, 0, 11, 8192, 3, 16384, 1, 4096, 3, 2048 } }, /* SUBURB */
};
static float zeroVec[4];
static int pack = -1;       /* PACKS index of the level being loaded */
int tmbr_levelSerial;       /* bumped on every level load (traffic.c sets up on the next game frame) */
int tmbr_levelIndex = -1;   /* shell level index of the level being loaded */
static u32 clutStart;       /* GS block of the pack's first CLUT */
static int retypeSerial, retypeLevel;    /* level serial whose ped groups still need the inmate types (tmbr_PedsRetype) */

static Manifest* readBlob0(int p, u32 at)
{
    Manifest* m = (Manifest*)at;
    int got = fileRead(PACKS[p].blob0, m);
    if (got <= 0 || m->magic != MAGIC || m->version != 2 || m->nblobs > 4 || m->blob[0].addr != PACKS[p].addr) {
        scePrintf("TMBR pack %s: not on disc or bad (%d)\n", PACKS[p].blob0, got);
        return 0;
    }
    return m;
}

static Manifest* readPack(int p)
{
    Manifest* m = readBlob0(p, PACKS[p].addr);
    u32 i;
    int got;
    if (!m) return 0;
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

#define RSIZE(r) (*(u32*)(r) * 4)                 /* record size in bytes (first word: size in words) */
#define RADDR(r) (*(u16*)((char*)(r) + 0xA))      /* GS block, relative to the slot's CLUT base */
#define RLOG2(r, sh) ((int)((*(u64*)((char*)(r) + 8) >> (sh)) & 0xF))

/* hook 1: before the level's RTX init (func_0023EC80(vram, rtx, 0)) */
void tmbr_LevelRtxInit(int vram, char* rtx, int slot, char* shell)
{
    int level = *(int*)(shell + 0x18000 + 0x23AC), i;
    char *r, *q;
    u32 maxAddr = 0, end = 0, px, resMax = 0, resEnd = 0;
    char *last, *lvlLast = 0;
    Manifest* m;
    pack = -1;
    if (D_004FAE38 && slot == 0)
        for (i = 0; i < (int)(sizeof(PACKS) / sizeof(PACKS[0])); i++)
            if (PACKS[i].level == level) pack = i;
    /* blob 0 goes to a scratch spot (RTX_SCRATCH), not to its home: FREEWAY's is the TEX slot tail, which still
     * holds loading-screen data at this point */
    if (pack >= 0 && (m = readBlob0(pack, RTX_SCRATCH)) != 0) {
        /* Record lists end with a record whose size word is 0: the game processes it, then stops. The level's
         * last RTX record is a real one (a res texture on every pack level), so it gets its true size and stays,
         * ours follow it and our last one gets size 0. (Overwriting it, and ending with an all-zero record that
         * the game also processes, broke a level res texture and CLUT block 0: the car corruption on packs maps.)
         * CLUT addresses continue after the highest level CLUT (as func_0023EC80 computes D_006F268C), res
         * addresses after the highest res texture. */
        r = rtx + *(u32*)(rtx + 4) * 16;
        for (;;) {
            u32 psm = (u32)(*(u64*)(r + 8) >> 32) & 0x3F, sz = RSIZE(r);
            px = (u32)(1 << RLOG2(r, 40)) << RLOG2(r, 44);
            if (psm != 0x1B && psm != 0x24 && psm != 0x2C) {
                if (RADDR(r) >= maxAddr) {
                    u32 p2 = px & 0xFFFF;
                    if (p2 < 0x40) p2 = 0x40;
                    maxAddr = RADDR(r);
                    end = maxAddr + (p2 >> 6);
                }
            } else if (RADDR(r) >= resMax) {
                u32 w = 1u << RLOG2(r, 40);
                if (w < 0x40) w = 0x40;
                resMax = RADDR(r);
                resEnd = resMax + ((w << RLOG2(r, 44)) >> 6);
            }
            if (sz == 0) {
                sz = psm == 0x1B ? 0x80 + px : (psm == 0x24 || psm == 0x2C) ? 0x80 + px / 2 : 16 + 4 * px;
                *(u32*)r = sz / 4;
                lvlLast = r;
                r += sz;
                break;
            }
            r += sz;
        }
        last = 0;
        for (q = (char*)m + (m->rtx - PACKS[pack].addr); RSIZE(q); q += RSIZE(q)) {
            u32 psm = (u32)(*(u64*)(q + 8) >> 32) & 0x3F;
            for (i = 0; i < (int)RSIZE(q); i++) r[i] = q[i];
            RADDR(r) += (psm == 0x1B || psm == 0x24 || psm == 0x2C) ? resEnd : end;
            last = r;
            r += RSIZE(r);
        }
        if (last) *(u32*)last = 0; else *(u32*)lvlLast = 0;
        clutStart = (vram >> 6) + end;
    } else {
        pack = -1;
    }
    rtxInit(vram, rtx, slot);
}

/* level TEX header: u32 nclass, u32 recq, nclass x (u32 count, u32 blocksize) */
static void binCounts(u32* level, const u32* add, int sign)
{
    u32 i, j;
    for (i = 0; i < add[0]; i++)
        for (j = 0; j < level[0]; j++)
            if (level[2 + 2 * j + 1] == add[2 + 2 * i + 1]) {
                level[2 + 2 * j] += sign * add[2 + 2 * i];
                break;
            }
}

/* hook 2: level texture init (func_0023D560(vram, 0)) */
void tmbr_LevelTexInit(int vram, int slot, char* shell)
{
    if (slot == 0) { tmbr_levelIndex = *(int*)(shell + 0x18000 + 0x23AC); tmbr_levelSerial++; }
    if (slot != 0 || pack < 0 || D_0048AC10[0] != LEVEL_TEX) { texRegister(vram, slot); return; }
    binCounts((u32*)LEVEL_TEX, PACKS[pack].classes, 1);
    texRegister(vram, slot); /* the original call: level textures + texture bins */
    binCounts((u32*)LEVEL_TEX, PACKS[pack].classes, -1);
}

/* hook 3: level db init (func_00127330(0x980000, vram, 0)) */
void tmbr_LevelDbLoaded(int ngp, int vram, int slot)
{
    Manifest* m;
    u32 i, j, n, texBase, *p, *hdr, *lvl, *tab, *chr;
    int saveDb, before, p0 = pack;
    if (slot != 0 || p0 < 0 || !(m = readPack(p0))) { dbInitSlot(ngp, vram, slot); return; }
    pack = -1;
    /* textures: file slot 9, ids after the level's */
    texBase = getMaxTexId(0);
    if (texBase + m->ntex >= 600) {
        scePrintf("TMBR pack: no texture ids left (%d + %d)\n", texBase, m->ntex);
        dbInitSlot(ngp, vram, slot);
        return;
    }
    {   /* pack TEX: the record before the all-zero terminator becomes the size-0 last record */
        char *t = (char*)m->tex, *r = t + *(u32*)(t + 4) * 16, *prev = 0;
        while (RSIZE(r)) { prev = r; r += RSIZE(r); }
        if (prev) *(u32*)prev = 0;
    }
    D_0048AC10[PACK_SLOT] = m->tex;
    setTexIdBase(PACK_SLOT, texBase);
    texRegister(vram, PACK_SLOT);
    dbInitSlot(ngp, vram, slot);
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
        scePrintf("TMBR pack: animation table not merged (level %x, %d + %d > %d)\n", (u32)lvl, n, m->nanims, m->animCap);
    }
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
    retypeSerial = tmbr_levelSerial;
    retypeLevel = PACKS[p0].level;   /* inmate packs: retype the ped groups on the first game frame */
}

/* Peds spawn from the level's ped groups (PedWorldManager at game+0x89FA0: u8 count, groups of 0x670 from
 * +0x10; group+1 = entry count, entries of 3 bytes {point, ped type, behavior} at group+0x630; a group fills
 * its entries with allocPedType(type) when a player comes near, func_00110338). SHIP / ASYLUM only list type 2,
 * so the packed inmates (types 9-11) sat in the pool. On the first frame after such a pack loaded, 3 of every 4
 * entries become an inmate type, round robin. Called every frame from the camera hook (cheap when idle). */
void tmbr_PedsRetype(void)
{
    static int k, tick, total;
    char* mgr;
    int g, e, n = 0, ng;
    if (retypeLevel != 15 && retypeLevel != 16) return;
    if (tmbr_levelIndex != retypeLevel) { retypeLevel = 0; return; }       /* another map now */
    if (!D_004FA030 || ++tick < 30) return;
    tick = 0;
    /* every 0.5 s for the whole match: the ped groups fill in after load (only 1 group existed on the first
     * frame), so every type-2 entry found becomes an inmate (types 9-11 in turn) */
    mgr = D_004FA030 + 0x89FA0;
    ng = *(unsigned char*)mgr;
    for (g = 0; g < ng; g++) {
        unsigned char* grp = (unsigned char*)mgr + 0x10 + g * 0x670;
        for (e = 0; e < grp[1] && e < 21; e++) {
            unsigned char* ent = grp + 0x630 + e * 3;
            if (ent[1] != 2) continue;
            ent[1] = 9 + (k++ % 3);
            n++;
        }
    }
    if (n) { total += n; scePrintf("TMBR peds: %d groups, %d more inmates (types 9-11), %d total\n", ng, n, total); }
}
