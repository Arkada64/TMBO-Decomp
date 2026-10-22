# Known fields (online SCUS-97196). (offset, ctype, name, comment). Built from reading the AI code; names are
# our best guesses unless marked "sure".
VEHICLE = 0x31B0
V = [
 (0x050, "FVECTOR", "prevPos", ""),
 (0x0D0, "FMATRIX", "rot", "orientation matrix"),
 (0x1D0, "FVECTOR", "pos", "position"),
 (0x208, "f32", "steer", ""),
 (0x270, "FVECTOR", "prevPos2", ""),
 (0x290, "f32", "speedRatio", ""),
 (0x2D4, "f32", "velAlongHeading", ""),
 (0x2E4, "f32", "throttle", "pad accel 0..1"),
 (0x2EC, "f32", "steerInput", ""),
 (0x324, "f32", "cruiseSpeed", ""),
 (0x3A4, "f32", "height", ""),
 (0x3F0, "f32", "maxHealth", ""),
 (0x400, "f32", "turboDrain", ""),
 (0x404, "f32", "health", "sure: damage subtracts from it"),
 (0x418, "f32", "turbo", ""),
 (0x43C, "f32", "recentDamage", "anti dogpile: AI damage to humans scaled down when high"),
 (0x444, "s32", "framesSinceX", ""),
 (0x464, "s32", "unk464", ""),
 (0x480, "s32", "unk480", ""),
 (0x484, "s8", "onGround", ""),
 (0x485, "s8", "netRemote", "1 = driven by the network (remote player)"),
 (0x486, "s8", "pendingDeath", ""),
 (0x488, "s8", "updateEnabled", ""),
 (0x489, "s8", "unk489", ""),
 (0x496, "s8", "dying", "respawning / exploding"),
 (0x497, "s8", "unk497", ""),
 (0x49B, "s8", "invisible", "target can't be attacked"),
 (0x590, "s32", "kind", "sure: 0 off, 1 human, 2 AI, 3 traffic (fodder)"),
 (0x594, "u8", "pad[0x12]", "AI pad flags, cleared each frame"),
 (0x5A3, "u8", "fireSpecial", ""),
 (0x5A4, "u8", "padBits", ""),
 (0x5A5, "u8", "unk5A5", ""),
 (0x5A7, "u8", "unk5A7", ""),
 (0x5B5, "u8", "unk5B5", ""),
 (0x17A0, "s32", "unk17A0", ""),
 (0x17D8, "s32", "unk17D8", ""),
 (0x18B8, "s32", "unk18B8", ""),
 (0x1F08, "s32", "unk1F08", ""),
 (0x1F30, "FVECTOR", "predictedPos", "pos + velocity*k, used for attractor group lookup"),
 (0x2010, "void*", "player", "Player* (humans only)"),
 (0x2014, "AIBrain*", "brain", "sure"),
 (0x2018, "Driver*", "driver", "sure"),
 (0x201C, "void*", "highwayDriver", ""),
 (0x2020, "void*", "fodderDriver", ""),
 (0x2028, "void*", "cs", "sure: model coordinate system, +0x10 = position"),
 (0x202C, "void*", "drawCs", ""),
 (0x20A8, "f32", "distNearestHuman", ""),
 (0x20B4, "s32", "netRole", "1 local human, 2 remote human, 3 AI(host), 4 AI, 5 AI(client copy)"),
 (0x20B8, "s32", "unk20B8", ""),
 (0x20C0, "s32", "netClient", ""),
 (0x20C4, "s32", "netObjId", ""),
 (0x20D0, "void*", "netVehicle", ""),
 (0x20D4, "void*", "netPadFlags", ""),
 (0x20D8, "void*", "netStats", ""),
 (0x20E0, "s32", "unk20E0", ""),
 (0x20F0, "s32", "nameIndex", ""),
 (0x20F4, "s32", "character", "sure: car id (0x20 = Sweet Tooth? x>>5 = index)"),
 (0x20F8, "s32", "group", ""),
 (0x20FC, "s32", "interactiveIdx", ""),
 (0x2100, "s32", "aiOrPlayerIdx", "sure: AI index for bots, player index for humans"),
 (0x2104, "s32", "vehicleIdx", "sure: 0..7"),
 (0x2108, "s32", "isLocalHuman", ""),
 (0x210C, "s32", "viewIdx", ""),
 (0x2114, "s32", "frameTicks", "sure: ticks this frame"),
 (0x2118, "s32", "prevFrameTicks", ""),
 (0x211C, "s32", "idleTicks", "sure: ticks since the pad was last used"),
 (0x2134, "s32", "farTicks", "traffic: ticks far from humans"),
 (0x2150, "s32", "aliveTicks", ""),
 (0x2155, "u8", "deaths", ""),
 (0x2158, "s32", "hidden", ""),
 (0x215C, "s32", "nearHuman", "sure: set each frame for the round-robin AI when a human is close & visible"),
 (0x22AC, "s32", "weapSlot[]", ""),
 (0x2280, "s32", "unk2280", ""),
 (0x2284, "s32", "unk2284", ""),
 (0x2338, "s32", "ammo[]", "sure: per weapon; AI forces the chosen one to >= 1 while attacking"),
 (0x242C, "s32", "unk242C", ""),
 (0x2430, "s32", "specialHold", ""),
 (0x31A4, "s32", "unk31A4", ""),
]
BRAIN = 0x630
B = [
 (0x000, "FVECTOR", "aimPoint", ""),
 (0x010, "void*", "targetCs", ""),
 (0x018, "f32", "range18", ""),
 (0x020, "f32", "targetDist", "sure (log): distance to driver->target"),
 (0x024, "f32", "targetBearing", "angle of the target relative to our heading"),
 (0x028, "f32", "targetFacing", "angle of our position relative to the TARGET's heading (fairness gate)"),
 (0x02C, "f32", "targetPitch", ""),
 (0x048, "f32", "fleeHealth", ""),
 (0x04C, "f32", "unk4C", ""),
 (0x054, "f32", "healthScore", "health * aggression; flee when < fleeHealth"),
 (0x05C, "f32", "aggrScale", ""),
 (0x060, "f32", "unk60", ""),
 (0x064, "f32", "weapMaxBearing[]", "per weapon"),
 (0x068, "f32", "specialAngle", ""),
 (0x0F0, "f32", "weapMaxPitch[]", "per weapon"),
 (0x17C, "f32", "weapRange[]", "per weapon"),
 (0x3E0, "f32", "unk3E0", ""),
 (0x3F0, "f32", "unk3F0", ""),
 (0x3F4, "f32", "aggression", ""),
 (0x3F8, "f32", "aggression2", ""),
 (0x3FC, "f32", "threat", "health*aggression*aggression2; AIs sorted by it"),
 (0x404, "f32", "fairness", "scales the fairness angle"),
 (0x40C, "s32", "lastMode", ""),
 (0x414, "s32", "attackState", "sure: 0..8, switch in aiUpdateAttack"),
 (0x418, "s32", "wantTurbo", ""),
 (0x41C, "s32", "cruiseZone", ""),
 (0x424, "s32", "unk424", ""),
 (0x42C, "s32", "unk42C", ""),
 (0x430, "s32", "ticks430", ""),
 (0x434, "s32", "unk434", ""),
 (0x438, "s32", "unk438", ""),
 (0x444, "s32", "tasDuration", "turn-and-shoot"),
 (0x448, "s32", "tasWeapon", ""),
 (0x458, "s32", "tasTicks", ""),
 (0x45C, "s32", "unk45C", ""),
 (0x464, "s32", "unk464", ""),
 (0x468, "s32", "unk468", ""),
 (0x46C, "s32", "unk46C", ""),
 (0x470, "s32", "unk470", ""),
 (0x474, "s32", "unk474", ""),
 (0x478, "s32", "specialInterval", "sure: special fires when specialTimer > interval * difficulty factor"),
 (0x47C, "s32", "weapon", "sure: weapon chosen (1 = special)"),
 (0x480, "s32", "unk480", ""),
 (0x488, "s32", "specialTimer", "sure"),
 (0x490, "s32", "unk490", ""),
 (0x494, "s32", "timer494", ""),
 (0x49C, "s32", "timer49C", ""),
 (0x4A0, "s32", "unk4A0", ""),
 (0x4A4, "s32", "timer4A4", ""),
 (0x4B0, "s32", "noLosTicks", "sure: grows without line of sight, halved when LOS ok; >=60 clears the see flags"),
 (0x4B4, "s32", "sortIndex", ""),
 (0x594, "s32", "unk594", ""),
 (0x598, "s32", "seesTarget", "LOS and target within 45 deg ahead"),
 (0x59C, "s32", "sawTarget", ""),
 (0x5A0, "s32", "aimedPitch", ""),
 (0x5A4, "s32", "aimed", "sticky: target within 35 deg ahead"),
 (0x5A8, "s32", "unk5A8", ""),
 (0x5B0, "s32", "ramming", ""),
 (0x5B4, "s32", "pickup", ""),
 (0x5B8, "s32", "unk5B8", ""),
 (0x5C0, "s32", "slowDown", ""),
 (0x5C4, "s32", "unk5C4", ""),
 (0x5CC, "s32", "tasActive", "turn-and-shoot in progress"),
 (0x5D0, "s32", "unk5D0", ""),
 (0x5D4, "s32", "unk5D4", ""),
 (0x5E0, "s32", "unk5E0", ""),
 (0x5E4, "s32", "unk5E4", ""),
 (0x5E8, "s32", "unk5E8", ""),
 (0x5F4, "s32", "pickupMode", ""),
 (0x5F8, "s32", "unk5F8", ""),
 (0x5FC, "s32", "thinkToken", "sure: one AI per frame (round robin in func_0013BEA0) runs LOS checks"),
 (0x604, "s32", "specialActive", ""),
 (0x608, "s32", "fire", ""),
 (0x60C, "s32", "okToAttack", "sure: only set when difficulty (game+0x9A3D4) > 0"),
 (0x614, "s32", "unk614", ""),
 (0x618, "s32", "sniping", ""),
]
DRIVER = 0x2C0
D = [
 (0x004, "s32", "mode", "sure: 0 idle, 2 bait/attack-in-front, 3 flee/cruise, 4 cruise, 5 hunt"),
 (0x008, "s32", "subState", ""),
 (0x048, "f32", "heading48", ""),
 (0x04C, "f32", "dist4C", ""),
 (0x0B0, "Vehicle*", "self", "sure"),
 (0x0B4, "Vehicle*", "target", "sure"),
 (0x0B8, "void*", "points", "sure: AttractorPoints (waypoint graph)"),
 (0x160, "FVECTOR*", "targetPredPos", ""),
 (0x164, "FVECTOR*", "targetPos", "sure"),
 (0x168, "FVECTOR*", "goalPos", ""),
 (0x170, "void*", "targetCs", ""),
 (0x174, "void*", "selfCs", ""),
 (0x18C, "f32", "unk18C", ""),
 (0x194, "f32", "unk194", ""),
 (0x19C, "f32", "speedLimit", ""),
 (0x1A0, "f32", "unk1A0", ""),
 (0x1A4, "f32", "speedRatio", ""),
 (0x1A8, "f32", "minSpeed", ""),
 (0x1B0, "f32", "odometer", ""),
 (0x1F4, "f32", "unk1F4", ""),
 (0x1FC, "f32", "distSincePoint", ""),
 (0x200, "s32", "pointA", ""),
 (0x208, "s32", "curPoint", ""),
 (0x20C, "s32", "nextPoint", ""),
 (0x210, "s32", "unk210", ""),
 (0x214, "s32", "group", "sure: attractor group the driver is in"),
 (0x218, "s32", "unk218", ""),
 (0x228, "s32", "ticks228", ""),
 (0x22C, "s32", "unk22C", ""),
 (0x230, "s32", "turnCount", ""),
 (0x234, "s32", "followCount", ""),
 (0x244, "s32", "ticks244", ""),
 (0x248, "s32", "unk248", ""),
 (0x250, "s32", "turning", "sure: aiTurn"),
 (0x254, "s32", "following", "sure: follow attractor points (func_00102D78)"),
 (0x258, "s32", "performing", "sure: aiPerform (direct attack driving)"),
 (0x25C, "s32", "snipe", ""),
 (0x270, "s32", "targetReachable", "target's group connected to ours (0 on arena level types 4/8/20)"),
 (0x274, "s32", "unk274", ""),
 (0x27C, "s32", "unk27C", ""),
 (0x294, "s32", "unk294", ""),
 (0x2A0, "s32", "unk2A0", ""),
 (0x2B0, "s32", "unk2B0", ""),
]

def struct(name, size, fields):
    out = ["typedef struct %s {" % name]
    pos = 0
    for off, ty, nm, cm in sorted(fields):
        if off < pos:
            continue
        if off > pos:
            out.append("    u8 _pad%X[0x%X];" % (pos, off - pos))
        arr = nm.endswith("[]") or "[" in nm
        base = nm.split("[")[0]
        sz = {"Vehicle": 0x31B0, "AIBrain": 0x630, "Driver": 0x2C0, "FVECTOR": 16, "FMATRIX": 64, "f32": 4, "s32": 4, "u8": 1, "s8": 1}.get(ty, 4)
        if nm.endswith("[]"):
            n = 1
            # extend array up to next field
            nxt = min([o for o, _, _, _ in fields if o > off] + [size])
            n = max(1, (nxt - off) // sz)
            out.append("    %s %s[%d]; /* 0x%X %s */" % (ty, base, n, off, cm))
            pos = off + n * sz
        elif "[" in nm:
            n = int(nm.split("[")[1].rstrip("]"), 0)
            out.append("    %s %s[%d]; /* 0x%X %s */" % (ty, base, n, off, cm))
            pos = off + n * sz
        else:
            out.append("    %s %s; /* 0x%X %s */" % (ty, nm, off, cm))
            pos = off + sz
    if pos < size:
        out.append("    u8 _pad%X[0x%X];" % (pos, size - pos))
    out.append("} %s; /* size 0x%X */" % (name, size))
    return "\n".join(out)

if __name__ == "__main__":
    hdr = """typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32;
typedef struct { f32 x, y, z, w; } FVECTOR;
typedef struct { f32 m[4][4]; } FMATRIX;
typedef struct Vehicle Vehicle; typedef struct AIBrain AIBrain; typedef struct Driver Driver;
"""
    print(hdr)
    print(struct("AIBrain", BRAIN, B)); print()
    print(struct("Driver", DRIVER, D)); print()
    print(struct("Vehicle", VEHICLE, V))

GAME = 0xA0000
G = [
 (0x00000, "Vehicle", "vehicles[8]", "sure: 8 x 0x31B0"),
 (0x23000, "AIBrain", "brains[8]", "sure: per vehicle index"),
 (0x26180, "Driver", "drivers[8]", "sure: per vehicle index"),
 (0x27780, "u8", "camera[0x42A0]", "Camera"),
 (0x2BA20, "void*", "views[80]", ""),
 (0x2BB60, "s32", "numViews", "count used with views[] / humans[] in distance loops"),
 (0x2BC30, "u8", "highway[0x48E0]", ""),
 (0x30510, "u8", "trafficDirector[0x460]", ""),
 (0x30970, "u8", "attractorPoints[0x3F20]", "sure: AttractorPoints for AI driving"),
 (0x9A3D0, "s32", "singlePlayer", "AI hunting logic only runs when set? (func_0013BEA0)"),
 (0x9A3D4, "s32", "difficulty", "sure: 0 easy (online default) .. 2 hard"),
 (0x9E670, "Vehicle*", "humans[8]", "sure: by player index"),
 (0x9E690, "Vehicle*", "ais[2]", "sure: AI list (bots mod: 6 entries, into 0x9E698..)"),
 (0x9E698, "Vehicle*", "specialFodder[4]", ""),
 (0x9FC90, "f32", "progress", "game progress (score/time) used to scale AI"),
 (0x9FC94, "f32", "progressMax", ""),
 (0x9FC98, "s32", "aiSort[2]", "AIs sorted by threat (bots mod moves it to 0x9E6A8)"),
 (0x9FCA0, "s32", "levelType", "sure: 2 highway, 4/8/20 arenas"),
 (0x9FCAC, "s32", "numHumans", "sure"),
 (0x9FCB4, "s32", "maxAIs", "sure: 2"),
 (0x9FCB8, "s32", "numFodder", ""),
 (0x9FCBC, "s32", "numAIsAlive", ""),
 (0x9FCC4, "s32", "human0Vehicle", ""),
 (0x9FCC8, "s32", "human1Vehicle", ""),
 (0x9FD00, "s32", "thinkRR", "sure: round-robin AI index holding the think token"),
 (0x9FD04, "s32", "hunterOf[8]", "sure: AI index hunting each human"),
 (0x9FD40, "s32", "humanGroup[8]", "sure: attractor group each human is in"),
 (0x9FD60, "s32", "unk9FD60", ""),
 (0x9FDA4, "s32", "thinkValue", ""),
 (0x9FDA8, "s32", "reassignHunters", ""),
 (0x9FEE4, "s32", "numAIs", "sure"),
]

def game_struct():
    return struct("TheGame", GAME, G)
