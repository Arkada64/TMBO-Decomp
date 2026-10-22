/* m2c drafts of asm/nonmatchings/tmb/game (online SCUS-97196) with the named structs of ../ai_decomp/ctx_types.h.
 * Not matching code: for reading. Regenerate: python3 run_m2c.py (paths inside). */

/* ---- AddVehicle__7TheGameP3_csii ---- */
? func_0010AED0(Vehicle*);                          /* extern */
s32 func_00127AF8(void*);                           /* extern */
s32 func_0014F0B8(s32, ?, Vehicle*, s32, s32);      /* extern */
? hierSetCsDrawMe__FP3_csUc(s32**, ?, ?, s32*, s32*); /* extern */
s32 printf(?*, s32, void*, s32**, s32, s32);        /* extern */
extern s32 D_004FA034;

s32 AddVehicle__7TheGameP3_csii(TheGame* arg0, s32** arg1, s32 arg2, s32 arg3, ...) {
    Vehicle* temp_16;
    s32 temp_2;
    s32* temp_7;
    s32* temp_8;

    if (D_004FA030->unk9FCA8 == -1) {
        D_004FA030->unk9FCA8 = (s32) arg0->unk9FCA4;
    }
    temp_2 = func_00127AF8(D_004FA030 + 0x98000) - 1;
    temp_16 = &arg0->vehicles[temp_2];
    temp_16->nameIndex = arg3;
    temp_16->vehicleIdx = temp_2;
    temp_16->interactiveIdx = func_0014F0B8(D_004FA034, 1, temp_16, arg1 + 0x10, temp_2);
    temp_16->character = arg2;
    if (arg2 < 0x400) {
        temp_16->group = (s32) ((arg2 > -1) ? arg2 : (arg2 + 0x1F)) >> 5;
    }
    temp_16->cs = arg1;
    temp_16->kind = 0;
    func_0010AED0(temp_16);
    temp_8 = *arg1;
    *temp_8 = (*temp_8 & 0x3FFFF) | (arg2 << 0x12);
    temp_7 = *arg1;
    *temp_7 = (*temp_7 & 0xFFFC007F) | ((temp_16->interactiveIdx & 0x7FF) << 7);
    hierSetCsDrawMe__FP3_csUc(arg1, 0, 0xFFFC007F, temp_7, temp_8);
    func_0013B228(arg0, temp_16->vehicleIdx, sp);
    return printf("GAME: Added vehicle #%d %s with cs %p, interactiveIndex %d, dupId %d\n", temp_16->vehicleIdx, sp, arg1, temp_16->interactiveIdx, arg3);
}

/* ---- GetBestAIToBait__7TheGame ---- */
s32 GetBestAIToBait__7TheGame(TheGame* arg0, ...) {
    AIBrain* temp_2;
    Vehicle* temp_5;
    Vehicle* var_7;
    Vehicle** var_4;
    f32 temp_f1;
    f32 var_f2;
    s32 temp_3;
    s32 var_6;

    var_f2 = 10000.0f;
    temp_3 = arg0->numAIs;
    var_7 = NULL;
    if (temp_3 > 0) {
        var_4 = arg0->ais;
        var_6 = temp_3;
        do {
            temp_5 = *var_4;
            if (temp_5->netRemote != 0) {
                var_6 -= 1;
            } else {
                var_6 -= 1;
                if (temp_5->driver->mode != 5) {
                    temp_2 = temp_5->brain;
                    temp_f1 = temp_2->targetDist + ((fabsf(temp_2->targetBearing) * 1000.0f) / 3.1415927f);
                    if (temp_f1 < var_f2) {
                        var_f2 = temp_f1;
                        var_7 = temp_5;
                    }
                }
            }
            var_4 += 4;
        } while (var_6 != 0);
    }
    return (s32) var_7;
}

/* ---- GetNumAIInBaitMode__7TheGame ---- */
s32 GetNumAIInBaitMode__7TheGame(TheGame* arg0, ...) {
    Vehicle* temp_3_2;
    Vehicle** var_6;
    s32 temp_3;
    s32 var_5;
    s32 var_7;

    temp_3 = arg0->numAIs;
    var_5 = 0;
    if (temp_3 > 0) {
        var_7 = temp_3;
        var_6 = arg0->ais;
        do {
            temp_3_2 = *var_6;
            var_7 -= 1;
            if (temp_3_2->netRemote == 0) {
                var_5 = ((temp_3_2->driver->mode ^ 2) == 0) ? (var_5 + 1) : var_5;
            }
            var_6 += 4;
        } while (var_7 != 0);
    }
    return var_5;
}

/* ---- GetNumAIsHunting__7TheGame ---- */
s32 GetNumAIsHunting__7TheGame(TheGame* arg0, ...) {
    Vehicle* temp_4;
    Vehicle** var_6;
    s32 temp_3;
    s32 var_7;
    s32 var_8;

    temp_3 = arg0->numAIs;
    var_7 = 0;
    if (temp_3 > 0) {
        var_8 = temp_3;
        var_6 = arg0->ais;
        do {
            temp_4 = *var_6;
            var_6 += 4;
            var_8 -= 1;
            var_7 = ((temp_4->driver->mode ^ 5) == 0) ? (var_7 + 1) : var_7;
        } while (var_8 != 0);
    }
    return var_7;
}

/* ---- GetVehicleFromName__7TheGameii ---- */
s32 GetVehicleFromName__7TheGameii(TheGame* arg0, s32 arg1, s32 arg2, ...) {
    TheGame* var_9;
    Vehicle* temp_7;
    s32 var_2;
    s32 var_8;

    var_9 = NULL;
    if (arg0->vehicles[0].character == arg1) {
        var_8 = 1;
        if (arg0->vehicles[0].nameIndex == arg2) {
            var_9 = arg0;
        } else {
            goto loop_5;
        }
    } else {
        var_8 = 1;
loop_5:
        var_2 = var_8 < 8;
loop_6:
        if (var_2 != 0) {
            temp_7 = &arg0->vehicles[var_8];
            var_8 += 1;
            if (temp_7->character == arg1) {
                var_2 = var_8 < 8;
                if (temp_7->nameIndex == arg2) {
                    var_9 = (TheGame* ) temp_7;
                } else {
                    goto loop_6;
                }
            } else {
                goto loop_5;
            }
        }
    }
    return (s32) var_9;
}

/* ---- InitTakeHitInfo__7TheGame ---- */
? memset(u8*, ?, ?);                                /* extern */

s32 InitTakeHitInfo__7TheGame(TheGame* arg0, ...) {
    u8* temp_16;

    temp_16 = &arg0->_pad2BB64[0xAC];
    memset(temp_16, 0, 0x1C);
    return (s32) temp_16;
}

/* ---- InitTypeOfVehicles__7TheGame ---- */
s32 InitTypeOfVehicles__7TheGame(TheGame* arg0, ...) {
    Vehicle** var_2_2;
    Vehicle** var_5;
    s32 temp_2;
    s32 var_3;
    s32 var_3_2;
    s32 var_3_3;
    s32* var_4;
    u8* var_2;

    var_3 = 9;
    var_2 = &arg0->_pad18D80[0x3740];
    do {
        *var_2 = 0;
        var_3 -= 1;
        var_2 -= 0x31B0;
    } while (var_3 >= 0);
    var_3_2 = 7;
    var_2_2 = &arg0->humans[7];
    do {
        *var_2_2 = NULL;
        var_3_2 -= 1;
        var_2_2 -= 4;
    } while (var_3_2 >= 0);
    var_5 = arg0->ais;
    var_4 = &arg0->brains[0].cruiseZone;
    var_3_3 = 0;
    do {
        *var_5 = NULL;
        *var_4 = var_3_3;
        var_5 += 4;
        var_3_3 += 1;
        temp_2 = var_3_3 < 2;
        var_4 += 0x630;
    } while (temp_2 != 0);
    return temp_2;
}

/* ---- IsInteractiveAVehicle__7TheGameiPi ---- */
s32 IsInteractiveAVehicle__7TheGameiPi(TheGame* arg0, s32 arg1, s32* arg2, ...) {
    Vehicle* temp_2;
    s32 var_4;
    s32 var_7;

    /* Flowgraph is not reducible, falling back to gotos-only mode. */
    var_7 = 0;
    var_4 = 0;
    if (arg0->vehicles[0].kind == 0) {
        goto block_3;
    }
    var_4 = 1;
    if (arg0->vehicles[0].interactiveIdx != arg1) {
        goto block_4;
    }
    *arg2 = 0;
    goto block_8;
block_3:
    var_4 += 1;
block_4:
    if (var_4 >= 8) {
        goto block_9;
    }
    temp_2 = &arg0->vehicles[var_4];
    if (temp_2->kind == 0) {
        goto block_3;
    }
    if (temp_2->interactiveIdx != arg1) {
        goto block_3;
    }
    *arg2 = var_4;
block_8:
    var_7 = 1;
block_9:
    return var_7;
}

/* ---- SetGravity__7TheGamef ---- */
extern f32 D_004FB4A0;

s32 SetGravity__7TheGamef(TheGame* arg0, f32 fparg0, ...) {
    TheGame* var_4;
    s32 temp_2;
    u8* temp_3;
    void* temp_5;

    var_4 = arg0;
    temp_3 = var_4->_pad18D80;
    var_4->unk9FC8C = fparg0;
    temp_5 = var_4 + 0x98000;
    do {
        var_4->vehicles[0].maxHealth = temp_5->unk7C8C;
        var_4 += 0x31B0;
        temp_2 = (s32) var_4 < (s32) temp_3;
        D_004FB4A0 = temp_5->unk7C8C;
    } while (temp_2 != 0);
    return temp_2;
}

/* ---- UpdateShadow__7TheGame ---- */
? func_00186018(TheGame*, ?);                       /* extern */
? hierSetCsDrawMe__FP3_csUc(void*, ?);              /* extern */

s32 UpdateShadow__7TheGame(TheGame* arg0, ...) {
    TheGame* var_16;
    s32 temp_2;
    s32 temp_2_2;
    s32 var_2;
    u8* temp_17;
    void* temp_4;

    var_16 = arg0;
    temp_17 = var_16->_pad18D80;
    var_2 = var_16->vehicles[0].kind;
loop_1:
    if (var_2 != 0) {
        func_00186018(var_16, 0);
        temp_2_2 = var_16->vehicles[0].character;
        if (temp_2_2 != 0x1C0) {
            if (temp_2_2 == 0x1E0) {
                goto block_5;
            }
        } else {
block_5:
            func_00186018(var_16, 1);
        }
    } else {
        temp_4 = var_16->vehicles[0].drawCs;
        if (temp_4 != NULL) {
            hierSetCsDrawMe__FP3_csUc(temp_4, 0);
        }
    }
    var_16 += 0x31B0;
    temp_2 = (s32) var_16 < (s32) temp_17;
    if (temp_2 != 0) {
        var_2 = var_16->vehicles[0].kind;
        goto loop_1;
    }
    return temp_2;
}

/* ---- func_00138358 ---- */
? CityInitAfter__Fv();                              /* extern */
? ClapperClearHits__8Clappers(u8*);                 /* extern */
? InitAfter__11DebrisStuff(u8*);                    /* extern */
? InitAfter__7EnvHeli(u8*);                         /* extern */
? InitBlimpAfter__5Blimp(u8*);                      /* extern */
? InitDriveInAfter__7DriveIn(u8*);                  /* extern */
? InitGasTankAfter__7GasTanki(u8*, ?);              /* extern */
? InitWaterTowerAfter__10WaterTower(u8*);           /* extern */
? Init__8Clappers(u8*);                             /* extern */
? Init__8Elevator(u8*);                             /* extern */
? JunkyardInitAfter__Fv(s32);                       /* extern */
? attractInitAfterDbLoad__15AttractorPoints(u8*);   /* extern */
? attractInitAfterDbLoad__18AttractPointGroups(u8*); /* extern */
? fogClearSlavedToBg__Fv(s32);                      /* extern */
? func_0010C520();                                  /* extern */
? func_0010D418(u8*);                               /* extern */
? func_0011A550(?*, u8);                            /* extern */
? func_00127BE8(s32);                               /* extern */
? func_001318E8(u8*);                               /* extern */
? func_001332B8(u8*);                               /* extern */
? func_00136CE0(u8*);                               /* extern */
? func_00140958(u8*);                               /* extern */
? func_00141FB8(?*);                                /* extern */
? func_001435D0(u8*, ?);                            /* extern */
? func_00178850(u8*);                               /* extern */
? func_00178C28(u8*);                               /* extern */
? func_0017BC80(u8*);                               /* extern */
? func_0017D4D0(u8*);                               /* extern */
? func_00180658(void*);                             /* extern */
? func_0018ECF8(u8*);                               /* extern */
? func_0019DEC8(u8*);                               /* extern */
? func_001AA000(s32);                               /* extern */
? func_001AC7F8(u8*);                               /* extern */
? func_001E6178(u8*);                               /* extern */
void* func_00213F80();                              /* extern */
? func_00226B08();                                  /* extern */
? func_002331E0();                                  /* extern */
? hdInitCar__Fv();                                  /* extern */
? hdInit__Fv();                                     /* extern */
? hierCsAddToCsList__FP3_cs(void*);                 /* extern */
s32 hierSetTraversalCallback__FPFP3_csP11_hierobjectPA3_fP8_fvector_v(?*); /* extern */
? initAfter__11HighwayLoop(u8*);                    /* extern */
? init__12FodderDriverP15AttractorPoints(u8*);      /* extern */
? plightActivate__Fv();                             /* extern */
? prisonShipInitAfter__Fv(s32);                     /* extern */
? readHighwaysFromDisk__12HighwayPToolP7Highwayi(u8*); /* extern */
? readPointsFromDisk__11PickupPToolP7Pickups(u8*);  /* extern */
extern ? D_003156C0;
extern ? D_00318F2C;
extern ? D_004FB478;
extern s32 D_004FB4D8;
extern ? func_0013E8C8;

s32 func_00138358(TheGame* arg0, ...) {
    TheGame* var_17;
    s32 temp_2;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 temp_4_2;
    s32 temp_4_3;
    s32 var_2;
    s32 var_3;
    u8* temp_16;
    u8* temp_16_2;
    u8* temp_16_3;
    u8* temp_16_4;
    u8* temp_16_5;
    void* temp_2_2;
    void* temp_4;

    temp_16 = &arg0->_pad34890[0x51AB0];
    arg0->unk9FED8 = 1;
    func_00178C28(temp_16);
    func_0010C520();
    func_00178850(&arg0->_pad34890[0x55710]);
    func_001435D0(arg0->highway, 2);
    func_0017BC80(temp_16);
    readHighwaysFromDisk__12HighwayPToolP7Highwayi(temp_16);
    readPointsFromDisk__11PickupPToolP7Pickups(&arg0->_pad34890[0x54440]);
    attractInitAfterDbLoad__18AttractPointGroups(&arg0->_pad34890[0x28A0]);
    attractInitAfterDbLoad__15AttractorPoints(arg0->attractorPoints);
    attractInitAfterDbLoad__15AttractorPoints(arg0->_pad34890);
    func_0010D418(&arg0->_pad34890[0x62240]);
    temp_3 = arg0->levelType;
    switch (temp_3) {                               /* switch 1 */
    case 1:                                         /* switch 1 */
        var_3 = 0xD;
        break;
    case 0:                                         /* switch 1 */
        var_3 = 0x32;
        break;
    case 6:                                         /* switch 1 */
        var_3 = 0x3C;
        break;
    case 14:                                        /* switch 1 */
        var_3 = 0x64;
        break;
    case 3:                                         /* switch 1 */
        var_3 = 0x50;
        break;
    case 8:                                         /* switch 1 */
        var_3 = 0x5A;
        break;
    case 12:                                        /* switch 1 */
        var_3 = 0x3C;
        break;
    case 4:                                         /* switch 1 */
        var_3 = 0x64;
        break;
    case 20:                                        /* switch 1 */
        var_3 = 0x64;
        break;
    default:                                        /* switch 1 */
        var_3 = 0x46;
        break;
    }
    arg0->unk9FD60 = var_3;
    temp_3_2 = arg0->difficulty;
    switch (temp_3_2) {                             /* switch 2; irregular */
    case 0:                                         /* switch 2 */
        temp_2 = arg0->unk9FD60;
        var_2 = (s32) (temp_2 + ((u32) temp_2 >> 0x1F)) >> 1;
block_22:
        arg0->unk9FD60 = var_2;
        break;
    case 2:                                         /* switch 2 */
        temp_3_3 = arg0->unk9FD60 * 2;
        arg0->unk9FD60 = temp_3_3;
        if (temp_3_3 < 0x32) {
            var_2 = 0x32;
            goto block_22;
        }
        if (temp_3_3 >= 0x65) {
            var_2 = 0x64;
            goto block_22;
        }
        break;
    }
    var_17 = arg0;
    D_004FB4D8 = arg0->unk9FD60;
    init__12FodderDriverP15AttractorPoints(arg0->_pad34890);
    func_001E6178(&arg0->_pad34890[0x37A80]);
    func_00226B08();
    func_002331E0();
    InitAfter__11DebrisStuff(&arg0->_pad9A3D8[8]);
    func_001AC7F8(&arg0->_pad9A3D8[0x37F8]);
    hdInit__Fv();
    hdInitCar__Fv();
    func_00140958(&arg0->_pad34890[0x61060]);
    func_00141FB8(&D_004FB478);
    func_0011A550(&D_00318F2C, D_00318F2C.unk-724->unk6);
    func_00180658(&D_00318F2C - 0x638);
    do {
        temp_2_2 = func_00213F80();
        var_17->unk2034 = temp_2_2;
        temp_2_2->unkC = 0;
        temp_4 = var_17->unk2034;
        var_17 += 0x31B0;
        hierCsAddToCsList__FP3_cs(temp_4);
    } while ((s32) var_17 < (s32) &arg0->_pad18D80[0x6360]);
    temp_4_2 = arg0->levelType;
    if ((u32) temp_4_2 < 0x15U) {
        temp_4_3 = *((temp_4_2 * 4) + &jtbl_004E25F0);
        switch (temp_4_2) {                         /* switch 3 */
        case 0:                                     /* switch 3 */
        case 18:                                    /* switch 3 */
            func_001AA000(temp_4_3);
            InitWaterTowerAfter__10WaterTower(&arg0->_pad34890[0x61DC0]);
            func_001332B8(&arg0->_pad34890[0x61E70]);
            break;
        case 1:                                     /* switch 3 */
        case 19:                                    /* switch 3 */
            JunkyardInitAfter__Fv(temp_4_3);
            temp_16_2 = &arg0->_pad34890[0x9C50];
            Init__8Clappers(temp_16_2);
            ClapperClearHits__8Clappers(temp_16_2);
        case 10:                                    /* switch 3 */
            func_0018ECF8(&arg0->_pad34890[0x9CE0]);
            break;
        case 2:                                     /* switch 3 */
            func_00136CE0(&arg0->_pad34890[0x9EC0]);
            break;
        case 3:                                     /* switch 3 */
            func_0017D4D0(&arg0->_pad34890[0x9D30]);
            InitBlimpAfter__5Blimp(&arg0->_pad34890[0x61F80]);
            break;
        case 5:                                     /* switch 3 */
        case 17:                                    /* switch 3 */
            InitAfter__7EnvHeli(&arg0->_pad34890[0x619D0]);
            temp_16_3 = &arg0->_pad34890[0x9A50];
            Init__8Elevator(temp_16_3);
            func_001318E8(temp_16_3);
            CityInitAfter__Fv();
            InitGasTankAfter__7GasTanki(&arg0->_pad34890[0x62030], 0);
            InitGasTankAfter__7GasTanki(&arg0->_pad34890[0x620C0], 1);
            break;
        case 6:                                     /* switch 3 */
            initAfter__11HighwayLoop(&arg0->_pad34890[0xA230]);
            break;
        case 7:                                     /* switch 3 */
            temp_16_4 = &arg0->_pad34890[0x9A50];
            Init__8Elevator(temp_16_4);
            func_001318E8(temp_16_4);
            temp_16_5 = &arg0->_pad34890[0x9C50];
            Init__8Clappers(temp_16_5);
            ClapperClearHits__8Clappers(temp_16_5);
            break;
        case 11:                                    /* switch 3 */
            fogClearSlavedToBg__Fv(temp_4_3);
            break;
        case 12:                                    /* switch 3 */
            InitDriveInAfter__7DriveIn(&arg0->_pad34890[0x61F20]);
            break;
        case 8:                                     /* switch 3 */
            func_00127BE8(temp_4_3);
            break;
        case 15:                                    /* switch 3 */
            prisonShipInitAfter__Fv(temp_4_3);
            break;
        }
    }
    plightActivate__Fv();
    arg0->unk958E4 = 0;
    arg0->unk9FED4 = 0;
    func_0019DEC8(&arg0->_pad9E6A8[0x1028]);
    if (D_003156C0.unk1BB4 != 0) {
        arg0->unk97B50 = 1;
    }
    return hierSetTraversalCallback__FPFP3_csP11_hierobjectPA3_fP8_fvector_v(&func_0013E8C8);
}

/* ---- func_00138888 ---- */
? InitDriveInAfter__7DriveIn(u8*);                  /* extern */
? InitForReplay__11DebrisStuff(u8*);                /* extern */
? InitForReplay__3Hud(u8*);                         /* extern */
? InitForReplay__6Prison(u8*);                      /* extern */
? InitForReplay__8LauncherP7Vehicle(u8*, Vehicle*); /* extern */
? InitWaterTowerAfter__10WaterTower(u8*);           /* extern */
? InitWeaponsForReplay__7Weapons(u8*);              /* extern */
? ResetAllPickups__7Pickups(u8*);                   /* extern */
? ResetDestructs__13Destructibles(s32);             /* extern */
? RoofTopInitForReplay__Fv(s32);                    /* extern */
? SetCameraPOV__6Camerai10_cameraPOV(u8*, s32, ?);  /* extern */
? animationSetToFrame__FR11_animHandlef(void*, ?);  /* extern */
? func_00127BE8(s32);                               /* extern */
? func_001332B8(u8*);                               /* extern */
? func_0013F308(u8*, ?);                            /* extern */
? func_001AA000(s32);                               /* extern */
? func_001FBCF8(void*, ?, ?, ?);                    /* extern */
? func_002134D0();                                  /* extern */
? func_0022A8E0();                                  /* extern */
? func_0022B8B0(?);                                 /* extern */
? hierSetSwitch__FP11_hierswitchi(s32, ?);          /* extern */
? initAfter__11HighwayLoop(u8*);                    /* extern */
? prisonShipInitAfter__Fv(s32);                     /* extern */
extern s32 D_004FA038;

s32 func_00138888(TheGame* arg0, ...) {
    Vehicle* temp_3;
    Vehicle* temp_4;
    Vehicle* var_4;
    Vehicle** var_16;
    Vehicle** var_16_2;
    s32 temp_3_2;
    s32 temp_4_2;
    s32 var_17;
    s32 var_17_2;
    s32* temp_5;
    u8* var_19;

    var_17 = 0;
    ResetAllPickups__7Pickups(&arg0->_pad34890[0x51AB0]);
    ResetDestructs__13Destructibles(D_004FA038);
    if (arg0->numHumans > 0) {
        var_19 = &arg0->_pad34890[0x632C0];
        var_16 = arg0->humans;
        do {
            temp_3 = *var_16;
            if (temp_3 != NULL) {
                if (temp_3->isLocalHuman != 0) {
                    SetCameraPOV__6Camerai10_cameraPOV(arg0->camera, temp_3->viewIdx, 2);
                }
                InitForReplay__3Hud(var_19);
                temp_4 = *var_16;
                InitForReplay__8LauncherP7Vehicle(&temp_4->_pad2160[0x50], temp_4);
            }
            var_17 += 1;
            var_19 += 0xA20;
            var_16 += 4;
        } while (var_17 < arg0->numHumans);
    }
    var_17_2 = 0;
    if (arg0->numAIs > 0) {
        var_16_2 = arg0->ais;
        var_4 = arg0->ais[0];
loop_9:
        var_17_2 += 1;
        var_16_2 += 4;
        InitForReplay__8LauncherP7Vehicle(&var_4->_pad2160[0x50], var_4);
        if (var_17_2 < arg0->numAIs) {
            var_4 = *var_16_2;
            goto loop_9;
        }
    }
    arg0->reassignHunters = 1;
    InitForReplay__11DebrisStuff(&arg0->_pad9A3D8[8]);
    InitWeaponsForReplay__7Weapons(&D_004FA030->_pad34890[0x37A80]);
    func_002134D0();
    func_0022A8E0();
    temp_3_2 = arg0->levelType;
    if ((u32) temp_3_2 < 0x13U) {
        temp_4_2 = *((temp_3_2 * 4) + &jtbl_004E2650);
        switch (temp_3_2) {
        case 0:
        case 18:
            func_001AA000(temp_4_2);
            InitWaterTowerAfter__10WaterTower(&arg0->_pad34890[0x61DC0]);
            func_001332B8(&arg0->_pad34890[0x61E70]);
            break;
        case 1:
            func_0022B8B0(1);
            hierSetSwitch__FP11_hierswitchi(arg0->unk9E940, 0);
            func_001FBCF8(sp, 0x2717, 0, 1);
            animationSetToFrame__FR11_animHandlef(sp, 0);
            break;
        case 5:
            func_0022B8B0(1);
            arg0->unk966FC = 0;
            arg0->unk966F8 = 0;
            /* fallthrough */
        case 17:
            func_0013F308(&arg0->_pad34890[0x62030], 0);
            func_0013F308(&arg0->_pad34890[0x620C0], 1);
            arg0->unk966FC = 0;
            arg0->unk966F8 = 0;
            break;
        case 3:
            InitForReplay__6Prison(&arg0->_pad34890[0x9D30]);
            break;
        case 6:
            initAfter__11HighwayLoop(&arg0->_pad34890[0xA230]);
            break;
        case 4:
            RoofTopInitForReplay__Fv(temp_4_2);
            break;
        case 8:
            func_00127BE8(temp_4_2);
            break;
        case 12:
            InitDriveInAfter__7DriveIn(&arg0->_pad34890[0x61F20]);
            break;
        case 15:
            prisonShipInitAfter__Fv(temp_4_2);
            break;
        }
    }
    temp_5 = arg0->unk97B40;
    *temp_5 = (*temp_5 & ~0x3F) | 9;
    return func_0013E888(arg0, temp_5, -0x40);
}

/* ---- func_00138BA8 ---- */
s32 Terminate__7BurnMan(u8*);                       /* extern */
? func_001DC130(TheGame*);                          /* extern */

s32 func_00138BA8(TheGame* arg0, ...) {
    TheGame* var_16;
    s32 var_17;
    s32 var_2;
    s32 var_2_2;
    u8* var_16_2;

    var_16 = arg0;
    var_2_2 = var_16->vehicles[0].kind;
loop_1:
    if ((u32) (var_2_2 - 1) < 2U) {
        if (arg0->numHumans >= 3) {
            if (var_16->vehicles[0].netRemote != 0) {
                func_001DC130(var_16);
            }
        } else {
            func_001DC130(var_16);
        }
    }
    var_16 += 0x31B0;
    if ((s32) var_16 < (s32) &arg0->_pad18D80[0x6360]) {
        var_2_2 = var_16->vehicles[0].kind;
        goto loop_1;
    }
    var_17 = 2;
    var_16_2 = &arg0->_pad34890[0x62150];
    do {
        var_2 = *var_16_2;
        if (var_2 != 0) {
            var_2 = Terminate__7BurnMan(var_16_2);
        }
        var_17 -= 1;
        var_16_2 += 0x50;
    } while (var_17 >= 0);
    return var_2;
}

/* ---- func_00138C90 ---- */
? ClapperClearHits__8Clappers(u8*);                 /* extern */
? JunkyardPizzaBoyUpdate__Fv();                     /* extern */
? JunkyardTunnelDoorUpdate__Fv();                   /* extern */
? ResetDBElements__3Hud(u8*);                       /* extern */
? SetCameraPOV__6Camerai10_cameraPOV(u8*, s32, ?, ?); /* extern */
? SetCameraToFollowVehicle__6CameraiP7VehicleP3_cs(u8*, s32, Vehicle*, s32); /* extern */
? func_001100F0(u8*);                               /* extern */
? func_00111668(u8*);                               /* extern */
? func_001166B8(u8*);                               /* extern */
? func_00118CD0(u8*);                               /* extern */
? func_00127C30(s32);                               /* extern */
? func_00127C50(s32);                               /* extern */
? func_00127FB8(u8*);                               /* extern */
? func_00129A50(s32);                               /* extern */
? func_0012DF00(u8*);                               /* extern */
? func_001318E8(u8*);                               /* extern */
? func_00131918(u8*);                               /* extern */
? func_001324D0(u8*);                               /* extern */
? func_001334C0(u8*);                               /* extern */
? func_00136D48(u8*);                               /* extern */
? func_0013F3D8(u8*);                               /* extern */
? func_00140B60(u8*);                               /* extern */
? func_0014F008(u8*);                               /* extern */
? func_00150AE8(s32);                               /* extern */
? func_00151840();                                  /* extern */
? func_00170760(?*, TheGame*);                      /* extern */
? func_00171F88(?*);                                /* extern */
? func_00172A90(?*);                                /* extern */
s32 func_001734B8(?*);                              /* extern */
s32 func_00173500(?*);                              /* extern */
? func_00173570(?*, ?);                             /* extern */
? func_00174988(?*, ?);                             /* extern */
? func_00175AA0(?*, ?);                             /* extern */
? func_001761E8(?*);                                /* extern */
s32 func_00176B10(?*, ?);                           /* extern */
? func_001798A8(u8*);                               /* extern */
? func_0017DA58(u8*);                               /* extern */
? func_0017F3E0(s32);                               /* extern */
? func_00184B18(s32);                               /* extern */
? func_0018A5A0();                                  /* extern */
s32 func_0018B3F0(?);                               /* extern */
? func_0018C7D0(?);                                 /* extern */
? func_0018D4A8(u8*);                               /* extern */
? func_0018EE38(u8*);                               /* extern */
? func_001902B0(u8*);                               /* extern */
? func_001AA050(s32);                               /* extern */
? func_001AA3B8(TheGame*);                          /* extern */
s32 func_001AC840(u8*);                             /* extern */
? func_001B0978(u8*);                               /* extern */
? func_001DC130(TheGame*, s32);                     /* extern */
? func_001DC760(TheGame*);                          /* extern */
? func_001DCD48(TheGame*);                          /* extern */
? func_001E0230(TheGame*);                          /* extern */
? func_001E3800(TheGame*);                          /* extern */
? func_001E5C28(u8*);                               /* extern */
? func_001E6398(u8*);                               /* extern */
? func_00217A48(?, ?);                              /* extern */
? func_00218A80(s32, ?);                            /* extern */
? func_0022BC98(s32, ?);                            /* extern */
f32 func_0023C0E8(?);                               /* extern */
? func_00266D78(s32*);                              /* extern */
s32 inputGetInput__Fii(?, s32);                     /* extern */
s32 inputGetPlayerPad__Fi(?);                       /* extern */
s32 inputIsCtlAvailable__Fib(?, ?);                 /* extern */
s32 netGetMyClientIndex(?*, s32);                   /* extern */
? netSendGameEvent(?*, s32, void*);                 /* extern */
? rtReturnToShell__F14RtReturnReasoni(?, ?);        /* extern */
s32 timerGetFieldsLastFrame__Fv(void*);             /* extern */
s32 todActive__Fv();                                /* extern */
? updateAmbientSound__19AmbientSoundManager(u8*);   /* extern */
s32 viewGetNumViews__Fv(s32);                       /* extern */
extern ? D_003156C0;
extern s32 D_004F979C;
extern s32 D_004F97A4;
extern s32 D_004F97A8;
extern s32 D_004F97AC;
extern s32 D_004F97B0;
extern s32 D_004F97B4;
extern s32 D_004F97B8;
extern s32 D_004FA038;
extern s32 D_004FA048;
extern s32 D_004FB4DC;
extern s32 D_004FB4E0;
extern s32 D_004FB4E4;

s32 func_00138C90(TheGame* arg0, ...) {
    s32 sp50;
    s32 sp54;
    s32 sp58;
    ? var_4_2;
    ? var_4_3;
    ?* var_4;
    TheGame* var_16_2;
    TheGame* var_18;
    f32 temp_f0;
    s32 temp_16;
    s32 temp_16_2;
    s32 temp_16_3;
    s32 temp_2;
    s32 temp_3_10;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 temp_3_4;
    s32 temp_3_5;
    s32 temp_3_6;
    s32 temp_3_7;
    s32 temp_4;
    s32 temp_4_2;
    s32 var_16;
    s32 var_17;
    s32 var_30;
    s32 var_5;
    u32 temp_3;
    u8* temp_16_4;
    u8* temp_16_5;
    u8* temp_16_6;
    u8* temp_16_7;
    u8* temp_16_8;
    u8* var_17_2;
    void* temp_3_11;
    void* temp_3_12;
    void* temp_3_13;
    void* temp_3_8;
    void* temp_3_9;

    sp54 = 0;
    func_0018A5A0();
    if (arg0->unk9FED8 != 0) {
        func_001399A8(arg0);
    }
    ResetDBElements__3Hud(&arg0->_pad34890[0x632C0]);
    if (arg0->levelType == 2) {
        func_001B0978(arg0->trafficDirector);
    }
    if (arg0->unk9FD9C == 0) {
        if (arg0->unk9FED8 == 0) {
            updateAmbientSound__19AmbientSoundManager(&arg0->_pad9E6A8[0x2A8]);
        }
        func_0013CC48(arg0);
        func_0013BEA0(arg0);
        func_0013CD18(arg0);
    }
    temp_3 = D_003156C0.unk3148->unk0;
    var_30 = 0;
    if (((temp_3 >> 5) & 1) == 1) {
        var_30 = (temp_3 & 1) ? 0 : 1;
    }
    if (((temp_3 >> 1) & 0xF) != 1) {
        func_00266D78(&D_004FB4DC);
    }
    sp50 = 0;
    sp58 = 0x27780;
    var_18 = arg0;
    do {
        temp_3_3 = var_18->vehicles[0].netRole;
        switch (temp_3_3) {                         /* switch 1; irregular */
        case 6:                                     /* switch 1 */
            /* fallthrough */
        case 1:                                     /* switch 1 */
            if (((((u32) D_003156C0.unk3148->unk0 >> 1) & 0xF) != 1) && (var_18->vehicles[0].netRemote == 0) && (var_30 == 0)) {
                if (D_003156C0.unk321C != 1) {
                default:                            /* switch 1 */
                    if ((var_18->vehicles[0].kind != 0) || ((var_18->vehicles[0].netStats != NULL) && (var_18->unk450 < 0xA))) {
                        if ((var_18->vehicles[0].netRole == 1) && (var_18->vehicles[0].kind != 0)) {
                            if ((D_003156C0.unk2DF6 == 0) || (inputIsCtlAvailable__Fib(0, 1) == 0)) {
                                temp_16 = inputGetInput__Fii(8, inputGetPlayerPad__Fi(0)) != 0;
                                if (((temp_16 != 0) && (D_004F97A4 == 0)) || (inputIsCtlAvailable__Fib(0, 1) == 0)) {
                                    if (D_003156C0.unk2DF6 == 0) {
                                        D_004FA048 = 1;
                                    }
                                    D_003156C0.unk2DF6 = 1;
                                    func_00217A48(0, 0);
                                } else if (temp_16 == 0) {
                                    if (D_004F97A4 != 0) {
                                        D_004F97A4 = 0;
                                    }
                                }
                            }
                            if ((D_003156C0.unk2DF6 != 0) && (func_0018B3F0(0) == 0)) {
                                D_003156C0.unk2DF6 = 0;
                                func_00217A48(1, 0);
                                D_004F97A4 = 1;
                            }
                        }
                        func_001DC760(var_18);
                    }
                } else {
                    goto block_23;
                }
            } else {
block_23:
                temp_3_4 = D_003156C0.unk4->unk20C;
                if (temp_3_4 >= 0x439) {
                    D_003156C0.unk4->unk20C = 0x1E0;
                } else if (temp_3_4 >= 0x30D) {
                    D_003156C0.unk4->unk208 = 0;
                }
                D_003156C0.unk4->unk20C = (s32) (D_003156C0.unk4->unk20C + timerGetFieldsLastFrame__Fv(D_003156C0.unk4));
                if ((((u32) D_003156C0.unk3148->unk0 >> 1) & 0xF) == 1) {
                    sp54 = 1;
                    func_00266D78(&D_004FB4E0);
                    temp_3_5 = D_004FB4E0 - D_004FB4DC;
                    D_004FB4E4 = temp_3_5;
                    if (temp_3_5 >= 0x2711) {
                        if ((u32) (D_003156C0.unk3148->unk20 - 5) < 2U) {
                            arg0->unk9FD9C = sp54;
                            rtReturnToShell__F14RtReturnReasoni(8, 0);
                        } else if (func_001734B8(&D_003156C0) != 0) {
                            if (func_00176B10(&D_003156C0, 1) < 2) {
                                D_003156C0.unk3230 = sp54;
                                arg0->unk9FD9C = sp54;
                                rtReturnToShell__F14RtReturnReasoni(7, 0);
                                func_00171F88(&D_003156C0);
                                func_00174988(&D_003156C0, -1);
                                D_003156C0.unk307C = netGetMyClientIndex(&D_003156C0);
                            }
                        } else {
                            D_003156C0.unk3230 = 0;
                            arg0->unk9FD9C = sp54;
                            rtReturnToShell__F14RtReturnReasoni(7, 0);
                        }
                    }
                } else if (var_30 != 0) {
                    var_17 = 1;
                    D_003156C0.unk3148->unk2C = (s32) D_003156C0.unk3148->unk8;
                    if (func_001734B8(&D_003156C0) != 0) {
                        var_4 = &D_003156C0;
loop_38:
                        if (var_4->unkC8 != 0) {
                            var_4 += 0x220;
                        } else if (var_4->unk10 < 0) {
                            var_4 += 0x220;
                        } else {
                            temp_3_6 = var_4->unk214;
                            var_4 += 0x220;
                            if (temp_3_6 >= 6) {
                                var_17 = ((temp_3_6 ^ 0xA) != 0) ? 0 : var_17;
                            }
                        }
                        if (((s32) var_4 < (s32) (&D_003156C0 + 0x1100)) && (var_17 != 0)) {
                            goto loop_38;
                        }
                        if (var_17 != 0) {
                            D_003156C0.unk3148->unk0 = (u32) (D_003156C0.unk3148->unk0 | 1);
                            func_00173570(&D_003156C0, 0xB);
                        }
                    }
                } else if ((D_003156C0.unk3220 == 0) && (D_003156C0.unk4->unk208 == 0) && (temp_3_7 = D_003156C0.unk4->unk20C, ((temp_3_7 < 0x30C) != 0)) && (temp_3_7 >= 0x1E1)) {
                    if ((var_18->vehicles[0].updateEnabled != 0) && (D_003156C0.unk321C != 1)) {
                        func_001DC130(var_18, netGetMyClientIndex(&D_003156C0, 0x17));
                        func_00170760(&D_003156C0, var_18);
                        netSendGameEvent(&D_003156C0, func_00173500(&D_003156C0), sp);
                        func_00218A80(var_18->vehicles[0].player->unk7B4, 1);
                        if (func_001734B8(&D_003156C0) == 0) {
                            D_003156C0.unk4->unk208 = 1;
                        }
                    } else if ((((u32) D_003156C0.unk3148->unk0 >> 1) & 0xF) == 1) {
                        arg0->unk9FD9C = 1;
                        var_4_2 = 7;
                        if ((u32) (D_003156C0.unk3148->unk20 - 5) < 2U) {
                            var_4_2 = 8;
                        }
                        rtReturnToShell__F14RtReturnReasoni(var_4_2, 0);
                    }
                } else {
                    if ((D_003156C0.unk2DF6 == 0) || (inputIsCtlAvailable__Fib(0, 1) == 0)) {
                        temp_16_2 = inputGetInput__Fii(8, inputGetPlayerPad__Fi(0)) != 0;
                        if (((temp_16_2 != 0) && (D_004F97A4 == 0)) || (inputIsCtlAvailable__Fib(0, 1) == 0)) {
                            if (D_003156C0.unk2DF6 == 0) {
                                D_004FA048 = 1;
                            }
                            D_003156C0.unk2DF6 = 1;
                            func_00217A48(0, 0);
                        } else if (temp_16_2 == 0) {
                            if (D_004F97A4 != 0) {
                                D_004F97A4 = 0;
                            }
                        }
                    }
                    if (D_003156C0.unk2DF6 != 0) {
                        if (func_0018B3F0(0) != 0) {
                            D_004F97A8 = 1;
                        } else {
                            D_003156C0.unk2DF6 = 0;
                            func_00217A48(1, 0);
                            D_004F97A4 = 1;
                            D_004F97A8 = 1;
                        }
                    } else {
                        if (var_30 != 0) {
                            temp_3_8 = D_003156C0.unk3148;
                            temp_3_8->unk2C = (s32) temp_3_8->unk8;
                        }
                        if (inputGetInput__Fii(0x10, var_18->vehicles[0].player->unk7B4) != 0) {
                            D_004F97AC = 1;
                        } else if (D_004F97AC != 0) {
                            D_004F97AC = 0;
                            D_004F97B4 = 1;
                        }
                        if (inputGetInput__Fii(0x40, var_18->vehicles[0].player->unk7B4) != 0) {
                            D_004F97B0 = 1;
                            goto block_92;
                        }
                        if (D_004F97B0 != 0) {
                            D_004F97B0 = 0;
                            if (D_003156C0.unk3220 != 0) {
                                D_003156C0.unk3224 = (s32) (D_003156C0.unk3224 ^ 1);
                                goto block_92;
                            }
                        } else {
block_92:
                            if ((D_003156C0.unk3220 != 0) && (D_004F97B4 != 0)) {
                                var_5 = 0;
                                var_16 = D_004F97B8 + 1;
loop_95:
                                temp_16_3 = ((var_16 ^ 8) == 0) ? 0 : var_16;
                                var_5 += 1;
                                if (D_004FA030->vehicles[temp_16_3].kind == 0) {
                                    if (var_5 < 8) {
                                        var_16 = temp_16_3 + 1;
                                        goto loop_95;
                                    }
                                } else {
                                    SetCameraPOV__6Camerai10_cameraPOV(&D_004FA030->vehicles[0]._pad0[sp58], D_003156C0.unk4->unkA0->unk210C, 5, 0x31B0);
                                    temp_3_9 = D_003156C0.unk4->unkA0;
                                    SetCameraToFollowVehicle__6CameraiP7VehicleP3_cs(&D_004FA030->vehicles[0]._pad0[sp58], temp_3_9->unk210C, &D_004FA030->vehicles[temp_16_3], temp_3_9->unk2028);
                                    D_004F97B8 = temp_16_3;
                                }
                                D_004F97B4 = 0;
                            }
                        }
                        D_004F97A8 = inputGetInput__Fii(0x4000, var_18->vehicles[0].player->unk7B4) == 0;
                    }
                    if ((var_18->vehicles[0].netRemote != 0) && (var_18->vehicles[0].updateEnabled == 0)) {
                        func_001E3800(var_18);
                    }
                }
                D_004F979C = 1;
                if (D_003156C0.unk2DF6 == 0) {
                    var_4_3 = 0;
                    if ((D_003156C0.unk4->unk20C != 0) || (var_30 != 0)) {
                        var_4_3 = 1;
                    }
                    func_0018C7D0(var_4_3);
                } else {
                    func_001761E8(&D_003156C0);
                    func_00175AA0(&D_003156C0, 0);
                }
            }
            break;
        }
        var_18 += 0x31B0;
        temp_3_2 = sp50 + 1;
        sp50 = temp_3_2;
    } while (temp_3_2 < 8);
    if (sp54 == 0) {
        func_0013CEE0(arg0);
    }
    func_0013E630(arg0);
    var_16_2 = arg0;
    var_17_2 = &arg0->vehicles[0]._pad2434[0xB20];
    func_0013D0C0(arg0);
    func_00129A50(D_004FA038);
    do {
        if ((var_16_2->vehicles[0].kind != 0) && (var_16_2->vehicles[0].hidden == 0)) {
            func_001AA3B8(var_16_2);
            func_001E0230(var_16_2);
            func_001DCD48(var_16_2);
        }
        temp_3_10 = var_16_2->vehicles[0].netRole;
        if ((temp_3_10 == 1) || (temp_3_10 == 4)) {
            func_00170760(&D_003156C0, var_16_2);
        }
        if (arg0->unk9FD9C == 0) {
            if (var_16_2->vehicles[0].kind != 0) {
                func_001902B0(var_17_2);
                goto block_145;
            }
        } else {
block_145:
            if (var_16_2->vehicles[0].kind != 0) {
                temp_2 = var_16_2->vehicles[0].netClient;
                if (temp_2 >= 0) {
                    temp_3_11 = var_16_2->vehicles[0].cs;
                    temp_3_11->unk80 = (f32) (temp_3_11->unk80 * ((temp_2 * 0x220) + &D_003156C0)->unkA0);
                    temp_3_12 = var_16_2->vehicles[0].cs;
                    temp_3_12->unk84 = (f32) (temp_3_12->unk84 * ((var_16_2->vehicles[0].netClient * 0x220) + &D_003156C0)->unkA4);
                    temp_3_13 = var_16_2->vehicles[0].cs;
                    temp_3_13->unk88 = (f32) (temp_3_13->unk88 * ((var_16_2->vehicles[0].netClient * 0x220) + &D_003156C0)->unkA8);
                }
            }
        }
        var_16_2 += 0x31B0;
        var_17_2 += 0x31B0;
    } while ((s32) var_16_2 < (s32) arg0->_pad18D80);
    func_00172A90(&D_003156C0);
    func_001166B8(arg0->camera);
    func_0018D4A8(&arg0->_pad34890[0xA3D0]);
    func_001E6398(&arg0->_pad34890[0x37A80]);
    func_001798A8(&arg0->_pad34890[0x51AB0]);
    func_001100F0(&arg0->_pad34890[0x55710]);
    func_00140B60(&arg0->_pad34890[0x61060]);
    func_00139F48(arg0);
    temp_4 = arg0->levelType;
    if ((u32) temp_4 < 0x15U) {
        temp_4_2 = *((temp_4 * 4) + &jtbl_004E26A0);
        switch (temp_4) {                           /* switch 2 */
        case 0:                                     /* switch 2 */
        case 18:                                    /* switch 2 */
            func_001AA050(temp_4_2);
            func_001E5C28(&arg0->_pad34890[0x61DC0]);
            func_001334C0(&arg0->_pad34890[0x61E70]);
            break;
        case 1:                                     /* switch 2 */
            func_00150AE8(viewGetNumViews__Fv(temp_4_2));
            temp_16_4 = &arg0->_pad34890[0x9C50];
            func_00118CD0(temp_16_4);
            ClapperClearHits__8Clappers(temp_16_4);
            func_0018EE38(&arg0->_pad34890[0x9CE0]);
            JunkyardTunnelDoorUpdate__Fv();
            JunkyardPizzaBoyUpdate__Fv();
            func_00151840();
            break;
        case 19:                                    /* switch 2 */
            func_00150AE8(viewGetNumViews__Fv(temp_4_2));
            temp_16_5 = &arg0->_pad34890[0x9C50];
            func_00118CD0(temp_16_5);
            ClapperClearHits__8Clappers(temp_16_5);
            func_0018EE38(&arg0->_pad34890[0x9CE0]);
            JunkyardTunnelDoorUpdate__Fv();
            JunkyardPizzaBoyUpdate__Fv();
            break;
        case 2:                                     /* switch 2 */
            func_00136D48(&arg0->_pad34890[0x9EC0]);
            if (todActive__Fv() != 0) {
                temp_f0 = func_0023C0E8(0x90000);
                if ((temp_f0 < 8.0f) || (temp_f0 > 17.0f)) {
                    if (!(temp_f0 > 17.0f)) {
                        if (temp_f0 > 7.0f) {
                            goto block_159;
                        }
                    } else {
block_161:
                        arg0->unk9FED4 = 1;
                    }
                } else {
block_159:
                    arg0->unk9FED4 = 0;
                }
            }
            break;
        case 14:                                    /* switch 2 */
            goto block_161;
        case 3:                                     /* switch 2 */
            func_0017DA58(&arg0->_pad34890[0x9D30]);
            func_00111668(&arg0->_pad34890[0x61F80]);
            break;
        case 5:                                     /* switch 2 */
        case 17:                                    /* switch 2 */
            func_0022BC98(temp_4_2, 0x457A0000);
            func_001324D0(&arg0->_pad34890[0x619D0]);
            temp_16_6 = &arg0->_pad34890[0x9A50];
            func_00131918(temp_16_6);
            func_001318E8(temp_16_6);
            func_0013F3D8(&arg0->_pad34890[0x62030]);
            func_0013F3D8(&arg0->_pad34890[0x620C0]);
            break;
        case 6:                                     /* switch 2 */
            func_0014F008(&arg0->_pad34890[0xA230]);
            break;
        case 4:                                     /* switch 2 */
        case 13:                                    /* switch 2 */
            func_00184B18(temp_4_2);
            break;
        case 7:                                     /* switch 2 */
            temp_16_7 = &arg0->_pad34890[0x9A50];
            func_00131918(temp_16_7);
            func_001318E8(temp_16_7);
            temp_16_8 = &arg0->_pad34890[0x9C50];
            func_00118CD0(temp_16_8);
            ClapperClearHits__8Clappers(temp_16_8);
            break;
        case 8:                                     /* switch 2 */
            func_00127C30(temp_4_2);
            break;
        case 9:                                     /* switch 2 */
            func_00127C50(temp_4_2);
            break;
        case 10:                                    /* switch 2 */
            func_0018EE38(&arg0->_pad34890[0x9CE0]);
            break;
        case 12:                                    /* switch 2 */
            func_0012DF00(&arg0->_pad34890[0x61F20]);
            break;
        case 15:                                    /* switch 2 */
            func_0017F3E0(temp_4_2);
            break;
        }
    }
    func_00127FB8(&arg0->_pad9A3D8[8]);
    return func_001AC840(&arg0->_pad9A3D8[0x37F8]);
}

/* ---- func_001399A8 ---- */
? SetCameraPOV__6Camerai10_cameraPOV(u8*, s32, ?);  /* extern */
f32 atan2f(f32, f32);                               /* extern */
? collisInitFirstFrame__7Vehicle(TheGame*);         /* extern */
s32 func_001734B8(?*);                              /* extern */
? func_00173570(?*, ?);                             /* extern */
? func_00175588(?*, ?, void*);                      /* extern */
? func_001A5A38(u8*);                               /* extern */
? func_00218E08(s32);                               /* extern */
f32 func_0021F100(?, ?);                            /* extern */
? func_00230680(?*);                                /* extern */
? mathfRotMatrixRPH__FPA3_fP8_fvector(FMATRIX*, void*); /* extern */
? timerSetFieldCount__Fi(?);                        /* extern */
s32 todDisable__Fv(?, u8*);                         /* extern */
extern ? D_002B9830;
extern ? D_003156C0;
extern s32 D_004F9DE4;

s32 func_001399A8(TheGame* arg0, ...) {
    s128 sp200;
    f32 sp284;
    ?* var_2;
    ?* var_4;
    FMATRIX* var_17;
    FVECTOR* var_18;
    TheGame* var_16_5;
    Vehicle* temp_2;
    Vehicle* temp_2_2;
    Vehicle* temp_3;
    Vehicle* temp_3_2;
    Vehicle* temp_4;
    Vehicle* temp_4_2;
    Vehicle** var_17_2;
    Vehicle** var_3_2;
    Vehicle** var_5;
    Vehicle** var_5_2;
    s128* var_6;
    s128* var_6_2;
    s32 var_16;
    s32 var_16_2;
    s32 var_16_3;
    s32 var_16_4;
    s32 var_16_6;
    s32 var_3;
    s32 var_5_3;
    void* temp_3_3;
    void* temp_3_4;
    void* temp_6;
    void* var_4_2;
    void* var_4_3;

    timerSetFieldCount__Fi(0);
    D_004F9DE4 = 0;
    if ((((u32) D_003156C0.unk3148->unk0 >> 5) & 1) == 1) {
        func_00173570(&D_003156C0, 0xA);
    } else {
        func_00173570(&D_003156C0, 0xB);
    }
    if (func_001734B8(&D_003156C0) != 0) {
        var_4 = &D_003156C0;
        if (((u32) D_003156C0.unk3148->unk0 >> 0xD) & 1) {
            var_16 = 0;
            temp_6 = &D_003156C0 + 0x1100;
            do {
                var_3 = 0;
                if (var_4->unk214 >= 7) {
                    var_3 = (var_4->unkC8 != 0) ? 0 : 1;
                }
                var_4 += 0x220;
                var_16 += var_3;
            } while ((s32) var_4 < (s32) temp_6);
            if (var_16 < 3) {
                func_00175588(&D_003156C0, -1, temp_6);
                if (var_16 < 2) {
                    func_00175588(&D_003156C0, -1);
                }
            }
        }
    }
    if (arg0->singlePlayer == 0) {
        func_0013DDD8(arg0);
    }
    var_16_2 = 0;
    if (arg0->maxAIs > 0) {
        var_3_2 = arg0->ais;
        do {
            temp_2 = var_3_2->unk0;
            if (temp_2 != NULL) {
                var_3_2->unk1608 = var_16_2;
                temp_2->brain->sortIndex = var_16_2;
            }
            var_16_2 += 1;
            var_3_2 += 4;
        } while (var_16_2 < arg0->maxAIs);
    }
    if (arg0->levelType != 0x14) {
        func_0013B5E0(arg0);
    }
    var_16_3 = 0;
    arg0->numAIsAlive = arg0->numAIs;
    if (arg0->numHumans > 0) {
        var_6 = &sp200;
        var_5 = arg0->humans;
        var_4_2 = sp;
        do {
            temp_3 = *var_5;
            if (temp_3 != NULL) {
                var_4_2->unk0 = (s128) temp_3->unkD0;
                var_4_2->unk10 = (s128) temp_3->unkE0;
                var_4_2->unk20 = (s128) temp_3->unkF0;
                var_4_2->unk30 = (s128) temp_3->unk100;
                *var_6 = (s128) temp_3->pos;
            }
            var_16_3 += 1;
            var_6 += 0x10;
            var_4_2 += 0x40;
            var_5 += 4;
        } while (var_16_3 < arg0->numHumans);
    }
    func_00230680(&D_002B9830);
    func_001A5A38(&arg0->_pad9E6A8[0x2A8]);
    if (arg0->levelType != 0x15) {
        var_16_4 = 0;
        if (arg0->numHumans > 0) {
            var_6_2 = &sp200;
            var_5_2 = arg0->humans;
            var_4_3 = sp;
            do {
                temp_2_2 = *var_5_2;
                if (temp_2_2 != NULL) {
                    temp_2_2->unkD0 = (s128) var_4_3->unk0;
                    temp_2_2->unkE0 = (s128) var_4_3->unk10;
                    temp_2_2->unkF0 = (s128) var_4_3->unk20;
                    temp_2_2->unk100 = (s128) var_4_3->unk30;
                    (*var_5_2)->pos = *var_6_2;
                }
                var_16_4 += 1;
                var_6_2 += 0x10;
                var_4_3 += 0x40;
                var_5_2 += 4;
            } while (var_16_4 < arg0->numHumans);
        }
    }
    arg0->unk9FED8 = 0;
    var_17 = &arg0->vehicles[0].rot;
    var_18 = &arg0->vehicles[0].pos;
    var_16_5 = arg0;
    do {
        if (var_16_5->vehicles[0].kind != 0) {
            var_16_5->vehicles[0].prevPos2 = (s128) *var_18;
            var_16_5->vehicles[0].prevPos = var_17->unk0;
            var_16_5->unk60 = (s128) var_17->unk10;
            var_16_5->unk70 = (s128) var_17->unk20;
            var_16_5->unk80 = (s128) var_17->unk30;
            collisInitFirstFrame__7Vehicle(var_16_5);
        }
        var_16_5->unk3190 = 0;
        var_17 += 0x31B0;
        var_16_5 += 0x31B0;
        var_18 += 0x31B0;
    } while ((s32) var_16_5 < (s32) arg0->_pad18D80);
    var_16_6 = 0;
    D_003156C0.unk3148->unk30 = 0;
    var_17_2 = arg0->humans;
    D_003156C0.unk3148->unk28 = 0;
    var_5_3 = 0;
    do {
        var_16_6 += 1;
        SetCameraPOV__6Camerai10_cameraPOV(arg0->camera, var_5_3, 2);
        temp_3_2 = *var_17_2;
        var_17_2 += 4;
        func_00218E08(temp_3_2->player->unk7B4);
        var_5_3 = var_16_6;
    } while (var_16_6 <= 0);
    if ((D_003156C0.unk1BB4 == 0) && (1 >= 2) && (arg0->humans[0] != NULL)) {
        if (arg0->humans[1] != NULL) {
            M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($v0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($v1) */);
            M2C_ERROR(/* unknown instruction: vsub.xyz $vf11, $vf11, $vf12 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf11, 0x280($sp) */);
            if (sp284 == 0.0f) {
                sp284 = 0.01f;
            }
            arg0->humans[0]->cs->unk68 = atan2f(sp280, sp284);
            temp_3_3 = arg0->humans[0]->cs;
            temp_3_3->unk68 = (f32) (temp_3_3->unk68 + func_0021F100(0xBF490FDB, 0x3F490FDB));
            temp_4 = arg0->humans[0];
            mathfRotMatrixRPH__FPA3_fP8_fvector(&temp_4->rot, temp_4->cs + 0x60);
            M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($v1) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($v0) */);
            M2C_ERROR(/* unknown instruction: vsub.xyz $vf11, $vf11, $vf12 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf11, 0x280($sp) */);
            if (sp284 == 0.0f) {
                sp284 = 0.01f;
            }
            arg0->humans[1]->cs->unk68 = atan2f(sp280, sp284);
            temp_3_4 = arg0->humans[1]->cs;
            temp_3_4->unk68 = (f32) (temp_3_4->unk68 + func_0021F100(0xBF490FDB, 0x3F490FDB));
            temp_4_2 = arg0->humans[1];
            mathfRotMatrixRPH__FPA3_fP8_fvector(&temp_4_2->rot, temp_4_2->cs + 0x60);
        }
    }
    var_2 = (?* )0x98000;
    if (arg0->levelType == 2) {
        var_2 = &D_003156C0;
        if (D_003156C0.unk1BB4 == 0) {
            var_2 = (?* ) (arg0->numHumans < 2);
            if (var_2 == NULL) {
                var_2 = todDisable__Fv(2, arg0 + 0x98000);
            }
        }
    }
    return (s32) var_2;
}

/* ---- func_00139F48 ---- */
f32 hierGetKlod__Fv();                              /* extern */
s32 hierSetKlod__Ff(f32);                           /* extern */
f32 timerGetOverloadScale__Fv();                    /* extern */

s32 func_00139F48(TheGame* arg0, ...) {
    f32 var_f1;
    f32 var_f20;
    s32 var_condition_bit;

    var_f20 = hierGetKlod__Fv();
    if (timerGetOverloadScale__Fv() > 0.96f) {
        var_f1 = 3.0f;
        var_f20 += 0.05f;
        var_condition_bit = var_f20 > 3.0f;
        goto block_4;
    }
    var_f1 = 1.0f;
    if (var_f20 > 1.0f) {
        var_f20 -= 0.002f;
        var_condition_bit = var_f20 < 1.0f;
block_4:
        if (var_condition_bit) {
            var_f20 = var_f1;
        }
    }
    return hierSetKlod__Ff(var_f20);
}

/* ---- func_0013A0B0 ---- */
s32 func_00127AF8();                                /* extern */

s32 func_0013A0B0(TheGame* arg0, ...) {
    return func_00127AF8() - 1;
}

/* ---- func_0013A0D0 ---- */
? AddEpNode__9FinalBossP9_hierhead(u8*);            /* extern */
? attachAdd__7VehicleiP9_hierhead(s32, s32, u32*);  /* extern */
s32 func_00127AF8();                                /* extern */
void* func_00127B58(u32*, s32);                     /* extern */
s32 hierSetCsDrawMe__FP3_csUc(void*, ?);            /* extern */
? printf(?*, s32, u32, s32);                        /* extern */

s32 func_0013A0D0(TheGame* arg0, u32* arg1, ...) {
    s32 temp_18;
    s32 temp_19;
    s32 temp_20;
    s32 temp_2;
    s32 var_16;
    u32 temp_17;
    void* var_22;

    temp_17 = (u32) *arg1 >> 0x12;
    var_22 = NULL;
    if (temp_17 == 0x200) {
        AddEpNode__9FinalBossP9_hierhead(&arg0->_pad34890[0x62890]);
    }
    var_16 = 0;
    temp_20 = func_00127AF8() - 1;
    temp_19 = temp_17 - ((((s32) temp_17 > -1) ? temp_17 : (temp_17 + 0x1F)) & 0x7FE0);
    temp_18 = temp_17 - temp_19;
loop_3:
    if (var_16 < 0xA) {
        if (GetVehicleFromName__7TheGameii(D_004FA030, temp_18, var_16) != 0) {
            var_16 += 1;
            goto loop_3;
        }
    }
    if (temp_19 == 0) {
        var_22 = func_00127B58(arg1, temp_20);
        arg0->unk9FD38 = temp_20;
        AddVehicle__7TheGameP3_csii(D_004FA030, var_22, temp_18, temp_20);
        var_22->unkD = 1;
    } else if ((s32) temp_17 < 0x400) {
        temp_2 = GetVehicleFromName__7TheGameii(D_004FA030, temp_18, temp_20);
        if (temp_2 != 0) {
            attachAdd__7VehicleiP9_hierhead(temp_2, temp_19, arg1);
        } else {
            printf("Didn't get car %d before getting attachment %d, %d\n", temp_18, temp_17, temp_19);
        }
    }
    return hierSetCsDrawMe__FP3_csUc(var_22, 0);
}

/* ---- func_0013A538 ---- */
s32 attachAdd__7VehicleiP9_hierhead(s32, s32, u32*); /* extern */
s32 func_00127B00(u32*);                            /* extern */

s32 func_0013A538(TheGame* arg0, u32* arg1, ...) {
    s32 temp_17;
    s32 temp_18;
    s32 temp_4;
    s32 var_16;
    s32 var_21;
    s32 var_2;
    u32 temp_19;

    var_21 = -1;
    var_16 = 0;
    temp_19 = (u32) *arg1 >> 0x12;
    temp_4 = temp_19 - 0x7D0;
    temp_17 = temp_4 - (((s32) ((temp_4 > -1) ? temp_4 : (temp_19 - 0x7B1)) >> 5) << 5);
    temp_18 = temp_19 - temp_17;
loop_3:
    if ((var_16 < 0xA) && (GetVehicleFromName__7TheGameii(D_004FA030, temp_18, var_16) != 0)) {
        var_21 = var_16;
        var_16 += 1;
        goto loop_3;
    }
    var_2 = (s32) temp_19 < 0xBB7;
    if (temp_17 == 0) {
        return func_0013A640(D_004FA030, func_00127B00(arg1), temp_18, var_21 + 1);
    }
    if (var_2 != 0) {
        var_2 = GetVehicleFromName__7TheGameii(D_004FA030, temp_18, var_21);
        if (var_2 != 0) {
            var_2 = attachAdd__7VehicleiP9_hierhead(var_2, temp_17, arg1);
        }
    }
    return var_2;
}

/* ---- func_0013A640 ---- */
? func_0010AED0(Vehicle*);                          /* extern */
s32 func_0014F070(s32, ?, Vehicle*, s32, ?);        /* extern */
? hierCsPtLightMe__FP3_csi(s32**, ?, s32, ?, s32*); /* extern */
? hierSetCsDrawMe__FP3_csUc(s32**, ?);              /* extern */
s32 printf(?*, s32, s32**, s32);                    /* extern */
extern s32 D_004FA034;

s32 func_0013A640(TheGame* arg0, s32** arg1, s32 arg2, s32 arg3, ...) {
    Vehicle* temp_16;
    s32 temp_4;
    s32 temp_6;
    s32* temp_8;
    s32* temp_8_2;
    void* temp_20;

    temp_20 = arg0 + 0x98000 + 0x7CD8;
    temp_16 = &arg0->vehicles[arg0->unk9FCA4];
    temp_16->nameIndex = arg3;
    *(temp_20 + (arg0->unk9FCA4 * 4)) = func_0014F070(D_004FA034, 2, &arg0->vehicles[arg0->unk9FCA4], arg1 + 0x10, 0x31B0);
    temp_16->character = arg2;
    temp_16->interactiveIdx = *(temp_20 + (arg0->unk9FCA4 * 4));
    if (arg2 < 0xBB7) {
        temp_4 = arg2 - 0x7D0;
        temp_16->group = (s32) ((temp_4 > -1) ? temp_4 : (arg2 - 0x7C1)) >> 4;
    }
    temp_16->cs = arg1;
    func_0010AED0(temp_16);
    temp_8 = *arg1;
    *temp_8 = (*temp_8 & 0x3FFFF) | (arg2 << 0x12);
    temp_8_2 = *arg1;
    temp_6 = (*temp_8_2 & 0xFFFC007F) | ((*(temp_20 + (arg0->unk9FCA4 * 4)) & 0x7FF) << 7);
    *temp_8_2 = temp_6;
    hierCsPtLightMe__FP3_csi(arg1, 1, temp_6, 0xFFFC007F, temp_8_2);
    hierSetCsDrawMe__FP3_csUc(arg1, 0);
    temp_16->kind = 0;
    arg0->numFodder += 1;
    return printf("Got fodder car %d with cs %p, interactiveIndex %d\n", arg2, arg1, temp_16->interactiveIdx);
}

/* ---- func_0013A7B8 ---- */
? func_0014ECE8(s32, s32);                          /* extern */
s32 func_001734B8(?*, AIBrain*, Driver*);           /* extern */
? func_0017BDD8(Vehicle*, void*, s32);              /* extern */
? func_00185F90(Vehicle*);                          /* extern */
? func_001FDE10(?, s32, s32);                       /* extern */
? hierCsPtLightMe__FP3_csi(void*, ?);               /* extern */
? hierSetCsDrawMe__FP3_csUc(void*, ?);              /* extern */
? shadow2ndOnOff__7Vehiclei(Vehicle*, ?);           /* extern */
extern ? D_002C07F8;
extern ? D_003156C0;

s32 func_0013A7B8(TheGame* arg0, s32 arg1, s32 arg3, s32 arg4, s32 arg5, ...) {
    AIBrain* temp_5_2;
    Driver* temp_6;
    TheGame* var_16;
    TheGame* var_21;
    s32 var_17;
    s32 var_2;
    void* temp_18;
    void* temp_4;
    void* temp_5;

    temp_18 = arg0 + 0x98000;
    temp_5 = arg0 + ((arg1 * 0x7E4) + 0x1F0E0);
    var_21 = NULL;
    var_17 = 0;
    var_16 = arg0;
loop_1:
    if (var_16->vehicles[0].nameIndex != arg3) {
        var_17 += 1;
        var_16 += 0x31B0;
        if (var_17 < 8) {
            goto loop_1;
        }
    } else {
        var_16->vehicles[0].vehicleIdx = var_17;
        if (arg5 != 0) {
            func_001FDE10(1, var_17 + 1, arg1);
            var_21 = var_16;
            var_16->vehicles[0].aiOrPlayerIdx = arg0->numAIs;
            temp_5_2 = &arg0->brains[var_17];
            *(temp_18 + 0x6690 + (arg0->numAIs * 4)) = var_16;
            temp_6 = &arg0->drivers[var_17];
            var_21->vehicles[0].player = NULL;
            var_21->vehicles[0].brain = temp_5_2;
            var_21->vehicles[0].driver = temp_6;
            var_2 = 4;
            if (func_001734B8(&D_003156C0, temp_5_2, temp_6) == 0) {
                var_2 = 3;
            }
            var_21->vehicles[0].netRole = var_2;
            aiInit__7Vehicle(var_16->vehicles);
            temp_4 = var_16->vehicles[0].drawCs;
            if (temp_4 != NULL) {
                hierSetCsDrawMe__FP3_csUc(temp_4, 1);
                shadow2ndOnOff__7Vehiclei(var_16->vehicles, 1);
            }
            hierCsPtLightMe__FP3_csi(var_16->vehicles[0].cs, 1);
            func_00130C00(var_16->vehicles[0].driver, arg0->vehicles);
            arg0->reassignHunters = 1;
            func_0014ECE8(var_16->vehicles[0].aiOrPlayerIdx + 0xA, *((((s32) var_16->vehicles[0].character >> 5) * 4) + &D_002C07F8));
            arg0->numAIs += 1;
        } else {
            var_16->vehicles[0].brain = NULL;
            var_16->vehicles[0].driver = NULL;
            var_16->vehicles[0].aiOrPlayerIdx = arg1;
            var_16->vehicles[0].player = temp_5;
            func_0017BDD8(var_16->vehicles, temp_5, arg1);
            func_00185F90(var_16->vehicles);
            var_16->vehicles[0].netRole = 0;
            *(temp_18 + 0x6670 + (arg1 * 4)) = var_16;
            if (arg4 >= 0) {
                gameInitCamera__7TheGameii(arg0, arg4, var_17);
            }
        }
        var_16->vehicles[0].unk20B8 = -1;
        var_16->vehicles[0].highwayDriver = NULL;
        var_16->vehicles[0].fodderDriver = NULL;
        var_16->vehicles[0].netObjId = -1;
    }
    return (s32) var_21;
}

/* ---- func_0013A9E0 ---- */
? hierCsPtLightMe__FP3_csi(void*, ?);               /* extern */
? hierSetCsDrawMe__FP3_csUc(void*, ?);              /* extern */
? printf(?*, s32, s32, void*);                      /* extern */
? shadow2ndOnOff__7Vehiclei(Vehicle*, ?);           /* extern */

s32 func_0013A9E0(TheGame* arg0, s32 arg1, s32 arg2, s32 arg3, ...) {
    s32 sp20;
    AIBrain* sp24;
    Driver* sp28;
    s32 sp2C;
    TheGame* var_16;
    s32 temp_2;
    s32 var_19;
    s32 var_22;
    void* temp_4;

    sp2C = arg1 * 4;
    var_22 = 0;
    var_19 = 0;
    var_16 = arg0;
    sp24 = &arg0->brains[arg1];
    sp28 = &arg0->drivers[arg1];
    sp20 = arg2;
loop_1:
    if ((var_16->vehicles[0].character == sp20) && (var_16->vehicles[0].nameIndex == arg3)) {
        var_16->vehicles[0].vehicleIdx = var_19;
        var_16->vehicles[0].aiOrPlayerIdx = arg1;
        var_22 = 1;
        var_16->vehicles[0].player = NULL;
        var_16->vehicles[0].brain = sp24;
        var_16->vehicles[0].highwayDriver = NULL;
        var_16->vehicles[0].driver = sp28;
        var_16->vehicles[0].fodderDriver = NULL;
        var_16->vehicles[0].netRole = 3;
        var_16->vehicles[0].netObjId = -1;
        var_16->vehicles[0].unk20B8 = -1;
        (arg0 + 0x98000 + sp2C)->unk6690 = var_16;
        aiInit__7Vehicle(var_16->vehicles);
        temp_4 = var_16->vehicles[0].drawCs;
        if (temp_4 != NULL) {
            hierSetCsDrawMe__FP3_csUc(temp_4, 1);
            shadow2ndOnOff__7Vehiclei(var_16->vehicles, 1);
        }
        hierCsPtLightMe__FP3_csi(var_16->vehicles[0].cs, 1);
        func_0013B228(arg0, var_16->vehicles[0].vehicleIdx, sp);
        printf("Setting vehicle %d to AI car %d (%s)\n", var_19, arg1, sp);
        func_00130C00(var_16->vehicles[0].driver, arg0->vehicles);
        arg0->reassignHunters = 1;
    }
    var_19 += 1;
    temp_2 = var_19 < 8;
    var_16 += 0x31B0;
    if ((temp_2 != 0) && (var_22 == 0)) {
        goto loop_1;
    }
    return temp_2;
}

/* ---- func_0013AB90 ---- */
s32 func_001B0688(u8*, u8*, Vehicle*, s32);         /* extern */
extern s32 D_004FB480;
extern s32 D_004FB484;
extern s32 D_004FB488;

s32 func_0013AB90(TheGame* arg0, void* arg2, ...) {
    TheGame* var_16_2;
    s32 var_16;
    s32 var_17;
    s32 var_19;
    s32 var_2;
    s32 var_2_2;
    void* var_6;

    var_6 = arg2;
    var_17 = 0;
    if (D_004FA030->numHumans >= 2) {
        var_6 = arg0 + 0x98000;
        if (arg0->levelType == 2) {
            arg0->numFodder = 0;
            return func_001B0688(arg0->trafficDirector, arg0->highway, NULL, 0);
        }
        goto block_4;
    }
block_4:
    if (arg0->numHumans < 3) {
        if (arg0->specialFodder[0] != NULL) {
            if (arg0->levelType != 2) {
                var_16 = arg0->numFodder;
            } else {
                var_16 = D_004FB488;
            }
            D_004FB484 = 0;
            func_0013AFD0(arg0, 0x98000, var_6);
            D_004FB484 = var_16;
            return func_0013AFD0(arg0);
        }
        D_004FB488 = 0;
        var_19 = 0;
        var_16_2 = arg0;
        do {
            if ((u32) (var_16_2->vehicles[0].character - 0x7D0) < 0x3E8U) {
                if (arg0->specialFodder[0] == NULL) {
                    arg0->specialFodder[0] = var_16_2->vehicles;
                }
                var_2_2 = var_17 < 0x21;
                if (var_17 >= 0xF) {
                    if (arg0->numHumans == 1) {
                        var_2_2 = var_17 < 0x21;
                        goto block_21;
                    }
                } else {
block_21:
                    if (var_2_2 != 0) {
                        if (var_16_2->vehicles[0].character < 0x8F0) {
                            func_0013ADC0(D_004FA030, var_17, var_19, 1);
                            D_004FB488 += 1;
                        } else {
                            func_0013ADC0(D_004FA030, var_17, var_19, 0);
                        }
                        var_17 += 1;
                    }
                }
            }
            var_19 += 1;
            var_16_2 += 0x31B0;
        } while (var_19 < 8);
        D_004FB480 = var_17;
        D_004FB484 = var_17;
        var_2 = arg0->levelType;
        arg0->numFodder = var_17;
        if (var_2 == 2) {
            D_004FB484 = D_004FB488;
            var_2 = func_001B0688(arg0->trafficDirector, arg0->highway, arg0->specialFodder[0], D_004FB488);
        }
        return var_2;
    }
    arg0->numFodder = 0;
    return 0x98000;
}

/* ---- func_0013ADC0 ---- */
? func_00133EF0(Vehicle*, TheGame*);                /* extern */
? func_001343D8(Vehicle*, TheGame*);                /* extern */
? hierSetCsDrawMe__FP3_csUc(void*, ?);              /* extern */
s32 printf(?*, s32, s32, s32);                      /* extern */

s32 func_0013ADC0(TheGame* arg0, s32 arg1, s32 arg2, s32 arg3, ...) {
    Vehicle* temp_16;
    void* temp_4;

    temp_16 = &arg0->vehicles[arg2];
    temp_16->vehicleIdx = arg2;
    temp_16->aiOrPlayerIdx = arg1;
    temp_16->player = NULL;
    temp_16->brain = NULL;
    temp_16->driver = NULL;
    if (arg0->levelType == 2) {
        if (arg3 != 0) {
            temp_16->fodderDriver = NULL;
            temp_16->highwayDriver = arg0 + ((arg1 * 0x30) + 0x27780);
            func_00133EF0(temp_16, arg0);
        } else {
            goto block_4;
        }
    } else {
block_4:
        temp_16->highwayDriver = NULL;
        temp_16->fodderDriver = arg0 + ((arg1 * 0x70) + 0x27780);
        func_001343D8(temp_16, arg0);
    }
    temp_4 = temp_16->drawCs;
    if (temp_4 != NULL) {
        hierSetCsDrawMe__FP3_csUc(temp_4, 1);
    }
    return printf("Setting vehicle %d to Fodder car %d (carName %d)\n", arg2, arg1, temp_16->character);
}

/* ---- func_0013AF50 ---- */
s32 func_0013AF50(TheGame* arg0, ...) {
    s32 temp_2;
    s32 var_2;

    var_2 = 0x98000;
    if (arg0->singlePlayer == 0) {
        temp_2 = arg0->unk9FCD4 + 1;
        arg0->unk9FCD4 = temp_2;
        if (temp_2 >= arg0->numAIs) {
            arg0->unk9FCD4 = 0;
        }
        var_2 = gameInitCamera__7TheGameii(arg0, 1, (arg0 + 0x98000 + (arg0->unk9FCD4 * 4))->unk6690->unk2104);
    }
    return var_2;
}

/* ---- func_0013AFB8 ---- */
s32 func_0013AFB8(TheGame* arg0, ...) {
    return 0x461C4000;
}

/* ---- func_0013AFD0 ---- */
? changeFodder__15TrafficDirectorP7Vehiclei(u8*, Vehicle*, s32); /* extern */
? disable__13HighwayDriver(s32);                    /* extern */
? vehicleDisable__7Vehicle(u8*);                    /* extern */
? vehicleEnable__7Vehicle12VehicleTypes(u8*, ?);    /* extern */
extern s32 D_004FB484;

s32 func_0013AFD0(TheGame* arg0, ...) {
    s32 temp_2;
    s32 temp_3;
    s32 temp_4;
    s32 var_16;
    s32 var_16_2;
    s32 var_17;
    s32 var_17_2;

    temp_3 = arg0->numFodder;
    var_16 = temp_3;
    if (temp_3 < D_004FB484) {
        var_17 = var_16 * 0x31B0;
        do {
            var_16 += 1;
            vehicleEnable__7Vehicle12VehicleTypes(&arg0->specialFodder[0]->_pad0[var_17], 3);
            var_17 += 0x31B0;
        } while (var_16 < D_004FB484);
    } else {
        var_16_2 = D_004FB484;
        if (var_16_2 < temp_3) {
            var_17_2 = var_16_2 * 0x31B0;
            do {
                vehicleDisable__7Vehicle(&arg0->specialFodder[0]->_pad0[var_17_2]);
                temp_4 = arg0->specialFodder[0]->_pad0[var_17_2].unk201C;
                if (temp_4 != 0) {
                    disable__13HighwayDriver(temp_4);
                }
                var_16_2 += 1;
                var_17_2 += 0x31B0;
            } while (var_16_2 < arg0->numFodder);
        }
    }
    temp_2 = D_004FB484;
    if (arg0->levelType == 2) {
        changeFodder__15TrafficDirectorP7Vehiclei(arg0->trafficDirector, arg0->specialFodder[0], D_004FB484);
    }
    arg0->numFodder = temp_2;
    return temp_2;
}

/* ---- func_0013B108 ---- */
extern s32 D_004FB48C;
extern s32 D_004FB4BC;
extern s32 D_004FB4C0;

s32 func_0013B108(TheGame* arg0, ...) {
    func_0013B148(D_004FA030, D_004FB48C);
    D_004FB4C0 = D_004FB4BC;
    return D_004FB4BC;
}

/* ---- func_0013B148 ---- */
? SetCameraOffsets__6Cameraiffffff(u8*, f32, f32, f32, f32, f32, ?); /* extern */
? func_00116698(u8*, s32, s32, s32, f32);           /* extern */
extern s32 D_004FB490;
extern s32 D_004FB494;
extern f32 D_004FB4A4;
extern f32 D_004FB4A8;
extern f32 D_004FB4AC;
extern f32 D_004FB4B0;
extern f32 D_004FB4B4;
extern f32 D_004FB4B8;
extern s32 D_004FB4BC;
extern s32 D_004FB4C4;

s32 func_0013B148(TheGame* arg0, s32 arg1, ...) {
    s32 temp_2;
    u8* temp_17;
    void* temp_4;

    temp_17 = arg0->camera;
    SetCameraOffsets__6Cameraiffffff(temp_17, D_004FB4A8, D_004FB4AC, D_004FB4B0, D_004FB4B4, (D_004FB4B8 * 3.1415927f) / 180.0f, 0);
    func_00116698(temp_17, arg1, D_004FB490 != 0, D_004FB494 != 0, D_004FB4A4);
    temp_4 = temp_17 + (arg1 * 4);
    temp_2 = D_004FB4BC != 0;
    temp_4->unk4454 = temp_2;
    temp_4->unk4464 = (s32) (D_004FB4C4 != 0);
    return temp_2;
}

/* ---- func_0013B228 ---- */
s32 func_0013B228(TheGame* arg0, s32 arg1, void* arg2, ...) {
    ?* temp_2;
    ?* temp_2_10;
    ?* temp_2_11;
    ?* temp_2_12;
    ?* temp_2_13;
    ?* temp_2_14;
    ?* temp_2_15;
    ?* temp_2_2;
    ?* temp_2_3;
    ?* temp_2_4;
    ?* temp_2_5;
    ?* temp_2_6;
    ?* temp_2_7;
    ?* temp_2_8;
    ?* temp_2_9;
    ?* var_2;
    s32 temp_3;

    M2C_ERROR(/* unknown instruction: ldl $v1, 0x7($a4) */);
    M2C_ERROR(/* unknown instruction: ldr $v1, ($a4) */);
    M2C_ERROR(/* unknown instruction: sdl $v1, 0x7($a2) */);
    M2C_ERROR(/* unknown instruction: sdr $v1, ($a2) */);
    arg2->unk8 = (s8) "NULL    "->unk8;
    temp_3 = arg0->vehicles[arg1].character;
    var_2 = (?* )0x100;
    if ((u32) (temp_3 - 0x20) < 0xB98U) {
        if (temp_3 != 0x100) {
            if (temp_3 < 0x101) {
                if (temp_3 != 0x80) {
                    if (temp_3 < 0x81) {
                        if (temp_3 != 0x40) {
                            if (temp_3 < 0x41) {
                                var_2 = "Charger ";
                                if (temp_3 != 0x20) {
                                    /* Duplicate return node #8. Try simplifying control flow for better match */
                                    return (s32) var_2;
                                }
                                M2C_ERROR(/* unknown instruction: ldl $v1, 0x7($a3) */);
                                M2C_ERROR(/* unknown instruction: ldr $v1, ($a3) */);
                                M2C_ERROR(/* unknown instruction: sdl $v1, 0x7($a2) */);
                                M2C_ERROR(/* unknown instruction: sdr $v1, ($a2) */);
                                arg2->unk8 = (s8) var_2->unk8;
                                return (s32) var_2;
                            }
                            temp_2_15 = "CopSUV  ";
                            if (temp_3 != 0x60) {
                                return (s32) temp_2_15;
                            }
                            M2C_ERROR(/* unknown instruction: ldl $a3, 0x7($a0) */);
                            M2C_ERROR(/* unknown instruction: ldr $a3, ($a0) */);
                            M2C_ERROR(/* unknown instruction: sdl $a3, 0x7($a2) */);
                            M2C_ERROR(/* unknown instruction: sdr $a3, ($a2) */);
                            arg2->unk8 = (s8) temp_2_15->unk8;
                            return (s32) temp_2_15;
                        }
                        temp_2_14 = "Taxi    ";
                        M2C_ERROR(/* unknown instruction: ldl $a4, 0x7($a1) */);
                        M2C_ERROR(/* unknown instruction: ldr $a4, ($a1) */);
                        M2C_ERROR(/* unknown instruction: sdl $a4, 0x7($a2) */);
                        M2C_ERROR(/* unknown instruction: sdr $a4, ($a2) */);
                        arg2->unk8 = (s8) temp_2_14->unk8;
                        return (s32) temp_2_14;
                    }
                    if (temp_3 != 0xC0) {
                        if (temp_3 < 0xC1) {
                            temp_2_13 = "Derby   ";
                            if (temp_3 != 0xA0) {
                                return (s32) temp_2_13;
                            }
                            M2C_ERROR(/* unknown instruction: ldl $a0, 0x7($a4) */);
                            M2C_ERROR(/* unknown instruction: ldr $a0, ($a4) */);
                            M2C_ERROR(/* unknown instruction: sdl $a0, 0x7($a2) */);
                            M2C_ERROR(/* unknown instruction: sdr $a0, ($a2) */);
                            arg2->unk8 = (s8) temp_2_13->unk8;
                            return (s32) temp_2_13;
                        }
                        temp_2_12 = "Preacher";
                        if (temp_3 != 0xE0) {
                            return (s32) temp_2_12;
                        }
                        M2C_ERROR(/* unknown instruction: ldl $a4, 0x7($a1) */);
                        M2C_ERROR(/* unknown instruction: ldr $a4, ($a1) */);
                        M2C_ERROR(/* unknown instruction: sdl $a4, 0x7($a2) */);
                        M2C_ERROR(/* unknown instruction: sdr $a4, ($a2) */);
                        arg2->unk8 = (s8) temp_2_12->unk8;
                        return (s32) temp_2_12;
                    }
                    temp_2_11 = "Sweet To";
                    M2C_ERROR(/* unknown instruction: ldl $v1, 0x7($a3) */);
                    M2C_ERROR(/* unknown instruction: ldr $v1, ($a3) */);
                    M2C_ERROR(/* unknown instruction: sdl $v1, 0x7($a2) */);
                    M2C_ERROR(/* unknown instruction: sdr $v1, ($a2) */);
                    arg2->unk8 = (s8) temp_2_11->unk8;
                    return (s32) temp_2_11;
                }
                temp_2_10 = "Spectre ";
                M2C_ERROR(/* unknown instruction: ldl $a1, 0x7($v1) */);
                M2C_ERROR(/* unknown instruction: ldr $a1, ($v1) */);
                M2C_ERROR(/* unknown instruction: sdl $a1, 0x7($a2) */);
                M2C_ERROR(/* unknown instruction: sdr $a1, ($a2) */);
                arg2->unk8 = (s8) temp_2_10->unk8;
                return (s32) temp_2_10;
            }
            if (temp_3 != 0x180) {
                if (temp_3 < 0x181) {
                    if (temp_3 != 0x140) {
                        if (temp_3 < 0x141) {
                            temp_2_9 = "Hearse  ";
                            if (temp_3 != 0x120) {
                                return (s32) temp_2_9;
                            }
                            M2C_ERROR(/* unknown instruction: ldl $a1, 0x7($v1) */);
                            M2C_ERROR(/* unknown instruction: ldr $a1, ($v1) */);
                            M2C_ERROR(/* unknown instruction: sdl $a1, 0x7($a2) */);
                            M2C_ERROR(/* unknown instruction: sdr $a1, ($a2) */);
                            arg2->unk8 = (s8) temp_2_9->unk8;
                            return (s32) temp_2_9;
                        }
                        temp_2_8 = "Axel    ";
                        if (temp_3 != 0x160) {
                            return (s32) temp_2_8;
                        }
                        M2C_ERROR(/* unknown instruction: ldl $v1, 0x7($a3) */);
                        M2C_ERROR(/* unknown instruction: ldr $v1, ($a3) */);
                        M2C_ERROR(/* unknown instruction: sdl $v1, 0x7($a2) */);
                        M2C_ERROR(/* unknown instruction: sdr $v1, ($a2) */);
                        arg2->unk8 = (s8) temp_2_8->unk8;
                        return (s32) temp_2_8;
                    }
                    temp_2_7 = "Mr Grim ";
                    M2C_ERROR(/* unknown instruction: ldl $a0, 0x7($a4) */);
                    M2C_ERROR(/* unknown instruction: ldr $a0, ($a4) */);
                    M2C_ERROR(/* unknown instruction: sdl $a0, 0x7($a2) */);
                    M2C_ERROR(/* unknown instruction: sdr $a0, ($a2) */);
                    arg2->unk8 = (s8) temp_2_7->unk8;
                    return (s32) temp_2_7;
                }
                if (temp_3 != 0x1C0) {
                    if (temp_3 < 0x1C1) {
                        temp_2_6 = "Semi    ";
                        if (temp_3 != 0x1A0) {
                            return (s32) temp_2_6;
                        }
                        M2C_ERROR(/* unknown instruction: ldl $a3, 0x7($a0) */);
                        M2C_ERROR(/* unknown instruction: ldr $a3, ($a0) */);
                        M2C_ERROR(/* unknown instruction: sdl $a3, 0x7($a2) */);
                        M2C_ERROR(/* unknown instruction: sdr $a3, ($a2) */);
                        arg2->unk8 = (s8) temp_2_6->unk8;
                        return (s32) temp_2_6;
                    }
                    if (temp_3 != 0x1E0) {
                        temp_2_5 = "Tanker  ";
                        if (temp_3 != 0x220) {
                            return (s32) temp_2_5;
                        }
                        M2C_ERROR(/* unknown instruction: ldl $v1, 0x7($a3) */);
                        M2C_ERROR(/* unknown instruction: ldr $v1, ($a3) */);
                        M2C_ERROR(/* unknown instruction: sdl $v1, 0x7($a2) */);
                        M2C_ERROR(/* unknown instruction: sdr $v1, ($a2) */);
                        arg2->unk8 = (s8) temp_2_5->unk8;
                        return (s32) temp_2_5;
                    }
                    temp_2_4 = "Minion  ";
                    M2C_ERROR(/* unknown instruction: ldl $a0, 0x7($a4) */);
                    M2C_ERROR(/* unknown instruction: ldr $a0, ($a4) */);
                    M2C_ERROR(/* unknown instruction: sdl $a0, 0x7($a2) */);
                    M2C_ERROR(/* unknown instruction: sdr $a0, ($a2) */);
                    arg2->unk8 = (s8) temp_2_4->unk8;
                    return (s32) temp_2_4;
                }
                temp_2_3 = "Loader  ";
                M2C_ERROR(/* unknown instruction: ldl $a1, 0x7($v1) */);
                M2C_ERROR(/* unknown instruction: ldr $a1, ($v1) */);
                M2C_ERROR(/* unknown instruction: sdl $a1, 0x7($a2) */);
                M2C_ERROR(/* unknown instruction: sdr $a1, ($a2) */);
                arg2->unk8 = (s8) temp_2_3->unk8;
                return (s32) temp_2_3;
            }
            temp_2_2 = "Tank Car";
            M2C_ERROR(/* unknown instruction: ldl $a4, 0x7($a1) */);
            M2C_ERROR(/* unknown instruction: ldr $a4, ($a1) */);
            M2C_ERROR(/* unknown instruction: sdl $a4, 0x7($a2) */);
            M2C_ERROR(/* unknown instruction: sdr $a4, ($a2) */);
            arg2->unk8 = (s8) temp_2_2->unk8;
            return (s32) temp_2_2;
        }
        temp_2 = "TowTruck";
        M2C_ERROR(/* unknown instruction: ldl $a3, 0x7($a0) */);
        M2C_ERROR(/* unknown instruction: ldr $a3, ($a0) */);
        M2C_ERROR(/* unknown instruction: sdl $a3, 0x7($a2) */);
        M2C_ERROR(/* unknown instruction: sdr $a3, ($a2) */);
        arg2->unk8 = (s8) temp_2->unk8;
        return (s32) temp_2;
    }
    return (s32) var_2;
}

/* ---- func_0013B5E0 ---- */
s32 attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector(u8*, s32); /* extern */

s32 func_0013B5E0(TheGame* arg0, ...) {
    AIBrain* temp_2;
    Vehicle* temp_16;
    Vehicle** var_18;
    s32 temp_3;
    s32 temp_5;
    s32 var_17;
    s32 var_17_2;
    s32 var_2;
    s32* var_16;

    var_17 = 0;
    func_0013BEA0(arg0);
    gameInitCruiseZones__7TheGame(arg0);
    if (arg0->numHumans > 0) {
        var_16 = arg0->humanGroup;
        do {
            temp_5 = var_16->unk-16D0;
            if (temp_5 != 0) {
                var_16->unk0 = attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector(arg0->attractorPoints, temp_5 + 0x1D0);
            }
            var_17 += 1;
            var_16 += 4;
        } while (var_17 < arg0->numHumans);
    }
    var_2 = 0x98000;
    var_17_2 = 0;
    if (arg0->numAIs > 0) {
        var_18 = arg0->ais;
        do {
            temp_16 = *var_18;
            temp_16->brain->lastMode = temp_16->driver->mode;
            temp_16->driver->mode = 4;
            gamePickCruiseZone__7TheGameP7Vehiclei(arg0, temp_16, 1);
            func_001002C0(temp_16, 1);
            temp_2 = temp_16->brain;
            temp_3 = temp_2->lastMode;
            if (temp_3 == 5) {
                temp_2->cruiseZone = -1;
                temp_16->driver->mode = temp_3;
            }
            var_17_2 += 1;
            var_2 = var_17_2 < arg0->numAIs;
            var_18 += 4;
        } while (var_2 != 0);
    }
    return var_2;
}

/* ---- func_0013BC98 ---- */
s32 func_0013BC98(TheGame* arg0, ...) {
    Vehicle* temp_16_3;
    Vehicle** var_17_2;
    s32 temp_16_2;
    s32 temp_3;
    s32 temp_4;
    s32 var_17;
    s32 var_18;
    s32 var_18_2;
    s32 var_23;
    s32* temp_2;
    void* temp_16;
    void* temp_19;
    void* var_2;

    var_2 = arg0 + 0x98000;
    var_17 = 0;
    if (arg0->numHumans > 0) {
        temp_19 = var_2;
        var_18 = 0 * 4;
        do {
            temp_16 = (temp_19 + var_18)->unk6670;
            M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($v1) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf12 */);
            M2C_ERROR(/* unknown instruction: vmulx.xyz $vf11, $vf11, $vf12x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf11, 0x1f30($s0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($a1) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($a0) */);
            M2C_ERROR(/* unknown instruction: vadd.xyz $vf11, $vf11, $vf12 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf11, 0x1f30($s0) */);
            temp_4 = func_0010B950(arg0->attractorPoints, temp_16 + 0x1F30);
            if ((temp_16 != NULL) && (temp_16_2 = temp_16->unk590, (temp_16_2 == 1)) && (temp_2 = temp_19 + 0x7D40 + var_18, (*temp_2 != temp_4))) {
                *temp_2 = temp_4;
                gameInitCruiseZones__7TheGame(arg0);
                temp_3 = temp_19->unk7CAC;
                if (((temp_3 == temp_16_2) && (temp_19->unk7CBC >= 2)) || ((temp_3 == 2) && (temp_19->unk7CBC >= 3))) {
                    gameCheckNewAIToHuntPlayer__7TheGamei(arg0, var_17);
                }
                var_23 = var_17 + 1;
                var_18_2 = 0;
                if (temp_19->unk7EE4 > 0) {
                    var_17_2 = arg0->ais;
                    do {
                        temp_16_3 = *var_17_2;
                        if (temp_16_3->driver->mode != 3) {
                            gamePickCruiseZone__7TheGameP7Vehiclei(arg0, temp_16_3, 1);
                        }
                        var_18_2 += 1;
                        var_17_2 += 4;
                    } while (var_18_2 < arg0->numAIs);
                }
            } else {
                var_23 = var_17 + 1;
                if (temp_19->unk7C90 < ((temp_19->unk7C94 * (f32) temp_19->unk7D60) / 100.0f)) {
                    func_0013CB08(arg0, var_17);
                }
            }
            var_17 = var_23;
            var_2 = (void* ) (var_17 < temp_19->unk7CAC);
            var_18 = var_17 * 4;
        } while (var_2 != NULL);
    }
    return (s32) var_2;
}

/* ---- func_0013BEA0 ---- */
s32 func_001734B8(?*);                              /* extern */
f32 timerGetOverloadScale__Fv(void*, s32);          /* extern */
extern ? D_003156C0;
extern s32 D_004FB4CC;

s32 func_0013BEA0(TheGame* arg0, ...) {
    AIBrain* temp_3_4;
    AIBrain* temp_3_5;
    Driver* temp_4_4;
    Driver* temp_4_5;
    FVECTOR* var_4;
    Vehicle* temp_16;
    Vehicle* temp_2_4;
    Vehicle* temp_4;
    Vehicle* temp_4_3;
    Vehicle** var_16;
    Vehicle** var_16_2;
    Vehicle** var_19;
    Vehicle** var_3;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    s32 temp_2;
    s32 temp_2_3;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 temp_3_7;
    s32 temp_4_6;
    s32 temp_5_2;
    s32 temp_6;
    s32 temp_7;
    s32 var_17;
    s32 var_17_2;
    s32 var_17_3;
    s32 var_17_4;
    s32 var_17_5;
    s32 var_2;
    s32 var_5;
    s32 var_9;
    s32* temp_4_2;
    s32* temp_5_3;
    void* temp_10;
    void* temp_11;
    void* temp_12;
    void* temp_16_2;
    void* temp_17;
    void* temp_2_2;
    void* temp_2_5;
    void* temp_2_6;
    void* temp_2_7;
    void* temp_3;
    void* temp_3_6;
    void* temp_5;
    void* temp_5_4;
    void* temp_6_2;
    void* temp_8;
    void** var_18;

    var_2 = 0x98000;
    if ((arg0->numAIs != 0) && (var_2 = func_001734B8(&D_003156C0), temp_5 = arg0 + 0x98000 + 0x6690, (var_2 != 0))) {
        (*(temp_5 + (arg0->thinkRR * 4)))->unk2014->unk5FC = 0;
        temp_2 = arg0->thinkRR + 1;
        arg0->thinkRR = temp_2;
        if (temp_2 >= arg0->numAIs) {
            arg0->thinkRR = 0;
        }
        temp_16 = *(temp_5 + (arg0->thinkRR * 4));
        temp_16->brain->thinkToken = arg0->thinkValue;
        temp_16->distNearestHuman = 20000.0f;
        var_17 = 0;
        if (arg0->numViews > 0) {
            var_19 = arg0->humans;
            var_18 = arg0->views;
            do {
                temp_2_2 = *var_18;
                if (temp_2_2 != NULL) {
                    temp_4 = *var_19;
                    var_4 = &temp_4->pos;
                    if (temp_4 == NULL) {
                        var_4 = temp_2_2 + 0x10;
                    }
                    temp_f0 = mathfManhatDist__FP8_fvectorT0(var_4, temp_16 + 0x1D0);
                    if (temp_f0 < temp_16->distNearestHuman) {
                        temp_16->distNearestHuman = temp_f0;
                    }
                }
                var_17 += 1;
                var_19 += 4;
                var_18 += 4;
            } while (var_17 < arg0->numViews);
        }
        temp_f1 = temp_16->distNearestHuman;
        if ((temp_f1 < 1500.0f) && ((temp_16->cs->unkE != 0) || (temp_f1 < 300.0f))) {
            temp_16->nearHuman = 1;
        }
        func_00104FA0(temp_16);
        temp_5_2 = arg0->maxAIs;
        arg0->unk9FCC0 = 0;
        if (temp_5_2 > 0) {
            var_17_2 = temp_5_2;
            var_3 = arg0->ais;
            do {
                var_17_2 -= 1;
                if (*var_3 != NULL) {
                    arg0->unk9FCC0 = (s32) (arg0->unk9FCC0 + 1);
                }
                var_3 += 4;
            } while (var_17_2 != 0);
        }
        arg0->numAIsAlive = arg0->unk9FCC0;
        if (arg0->singlePlayer != 0) {
            if (arg0->levelType != 0x14) {
                if (0.0f != 0.0f) {
                    temp_f1_2 = 0.0f / 0.0f;
                    arg0->unk9FDB0 = 1;
                    arg0->progress = temp_f1_2;
                    if ((arg0->difficulty == 0) || ((temp_f1_2 > 0.2f) && ((2.0f * arg0->progressMax) < temp_f1_2))) {
                        arg0->unk9FDB0 = 0;
                    } else if (timerGetOverloadScale__Fv(arg0 + 0x98000, temp_5_2) > 0.9f) {
                        arg0->unk9FDB0 = 0;
                    }
                }
                temp_3 = arg0 + 0x98000;
                var_17_3 = 0;
                if ((arg0->numAIs - 1) > 0) {
                    temp_12 = temp_3 + 0x7C98;
                    temp_11 = temp_3 + 0x6690;
                    var_9 = 1;
                    do {
                        temp_4_2 = temp_12 + (var_17_3 * 4);
                        temp_5_3 = temp_12 + (var_9 * 4);
                        temp_7 = *temp_4_2;
                        temp_6 = *temp_5_3;
                        temp_10 = *(temp_11 + (temp_7 * 4));
                        temp_8 = *(temp_11 + (temp_6 * 4));
                        temp_2_3 = temp_7 ^ temp_6;
                        if (temp_10->unk2014->unk3FC < temp_8->unk2014->unk3FC) {
                            *temp_4_2 = temp_2_3;
                            temp_3_2 = *temp_5_3 ^ temp_2_3;
                            *temp_5_3 = temp_3_2;
                            *temp_4_2 ^= temp_3_2;
                            temp_8->unk2014->unk4B4 = var_17_3;
                            temp_10->unk2014->unk4B4 = var_9;
                        }
                        var_17_3 = var_9;
                        var_9 = var_17_3 + 1;
                    } while (var_17_3 < (arg0->numAIs - 1));
                }
            }
            temp_16_2 = arg0 + 0x98000;
            var_2 = D_004FB4CC;
            if (arg0->singlePlayer == 0) {
                goto block_38;
            }
            if (var_2 != 0) {
                if (arg0->reassignHunters != 0) {
                    var_17_4 = 0;
                    if (arg0->numAIs > 0) {
                        var_16 = arg0->ais;
                        do {
                            temp_4_3 = *var_16;
                            temp_3_3 = temp_4_3->aiOrPlayerIdx;
                            temp_4_4 = temp_4_3->driver;
                            if ((temp_3_3 == arg0->hunterOf[0]) || (temp_3_3 == arg0->hunterOf[1])) {
                                func_00130E88(temp_4_4, 5);
                                (*var_16)->brain->pickupMode = 0;
                                (*var_16)->brain->fleeHealth = 0.0f;
                                temp_2_4 = *var_16;
                                temp_3_4 = temp_2_4->brain;
                                temp_3_4->healthScore = temp_2_4->health * temp_3_4->aggrScale;
                            } else {
                                if (temp_4_4 != NULL) {
                                    func_00130E88(temp_4_4, D_004FB4CC);
                                }
                                temp_3_5 = (*var_16)->brain;
                                if (temp_3_5 != NULL) {
                                    if (D_004FB4CC == 4) {
                                        temp_3_5->unk4C = 0.0f;
                                    }
                                    (*var_16)->brain->pickupMode = 0;
                                }
                            }
                            var_17_4 += 1;
                            var_16 += 4;
                        } while (var_17_4 < arg0->numAIs);
                    }
                    var_2 = (s32) (arg0 + 0x98000);
                    var_2->unk7DA8 = 0;
                } else {
                    func_0013BC98(arg0);
                    temp_17 = temp_16_2 + 0x6690;
                    if (arg0->numAIsAlive > 0) {
                        if ((*(temp_17 + (arg0->hunterOf[0] * 4)))->unk2018->unk4 != 5) {
                            func_0013C568(arg0, 0);
                        }
                        if (arg0->numHumans >= 2) {
                            temp_2_5 = *(temp_17 + (arg0->hunterOf[1] * 4));
                            if ((temp_2_5 != NULL) && (temp_2_5->unk2018->unk4 != 5)) {
                                func_0013C568(arg0, 1);
                            }
                        }
                        var_5 = 2;
                        if (!(timerGetOverloadScale__Fv() < 0.75f)) {
                            var_5 = 0;
                            if (timerGetOverloadScale__Fv() < 0.85f) {
                                var_5 = 1;
                            }
                        }
                        var_2 = 0x98000;
                        var_17_5 = 0;
                        if (arg0->numAIs > 0) {
                            var_16_2 = arg0->ais;
                            do {
                                if ((var_17_5 != arg0->hunterOf[0]) && (var_17_5 != arg0->hunterOf[1]) && (var_5 < 0)) {
                                    temp_4_5 = (*var_16_2)->driver;
                                    if (temp_4_5->mode == 5) {
                                        func_00130E88(temp_4_5, D_004FB4CC);
                                    }
                                }
                                var_17_5 += 1;
                                var_2 = var_17_5 < arg0->numAIs;
                                var_16_2 += 4;
                            } while (var_2 != 0);
                        }
                    } else {
                        temp_6_2 = temp_16_2 + 0x6690;
                        temp_3_6 = *(temp_6_2 + (arg0->hunterOf[0] * 4));
                        temp_4_6 = temp_3_6->unk2018->unk4;
                        if (temp_4_6 != 5) {
                            var_2 = 1;
                            if ((temp_4_6 != 3) || (temp_2_6 = temp_3_6->unk2014, var_2 = 1, (temp_2_6->unk60 < (f32) temp_2_6->unk45C))) {
                                arg0->reassignHunters = 1;
                            }
                        } else {
                            var_2 = arg0->numHumans < 2;
                            if (var_2 == 0) {
                                temp_5_4 = *(temp_6_2 + (arg0->hunterOf[1] * 4));
                                temp_3_7 = temp_5_4->unk2018->unk4;
                                var_2 = 3;
                                if ((temp_3_7 != temp_4_6) && ((var_2 = 1, (temp_3_7 != 3)) || (temp_2_7 = temp_5_4->unk2014, var_2 = 1, (temp_2_7->unk60 < (f32) temp_2_7->unk45C)))) {
                                    arg0->reassignHunters = 1;
                                }
                            }
                        }
                    }
                }
            }
        } else {
block_38:
            var_2 = func_0013DED8(arg0);
        }
    }
    return var_2;
}

/* ---- func_0013C568 ---- */
s32 func_0013C568(TheGame* arg0, s32 arg1, ...) {
    AIBrain* temp_2;
    Vehicle* temp_3;
    Vehicle* var_16;
    Vehicle** var_6;
    f32 var_f0;
    f32 var_f1;
    s32 temp_6;
    s32 temp_6_2;
    s32 var_2;
    s32 var_7;
    void* temp_4;

    var_2 = 0x98000;
    var_f1 = 0.0f;
    temp_6 = arg0->numAIs;
    var_7 = 0;
    var_16 = NULL;
    if (temp_6 > 0) {
        var_6 = arg0->ais;
        do {
            temp_3 = *var_6;
            if (temp_3->netRemote == 0) {
                temp_2 = temp_3->brain;
                if (temp_2 != NULL) {
                    var_f0 = temp_2->threat;
                    if ((var_f1 < var_f0) && ((var_7 != *(arg0 + 0x98000 + 0x7D04 + (arg1 * 4))) || (var_f0 *= 0.25f, (var_f1 < var_f0)))) {
                        var_16 = temp_3;
                        var_f1 = var_f0;
                    }
                }
            }
            var_7 += 1;
            var_2 = var_7 < temp_6;
            var_6 += 4;
        } while (var_2 != 0);
    }
    if (var_16 != NULL) {
        if ((var_16->driver->mode != 3) || (var_2 = (s32) var_16->brain, !((f32) var_2->unk45C < (var_2->unk60 * 0.5f)))) {
            temp_6_2 = var_16->aiOrPlayerIdx;
            temp_4 = arg0 + 0x98000;
            if ((temp_4 + (temp_6_2 * 4))->unk6690 != 0) {
                (temp_4 + (arg1 * 4))->unk7D04 = temp_6_2;
            }
            func_00130E88(var_16->driver, 5);
            var_16->brain->pickupMode = 0;
            var_16->brain->fleeHealth = 0.0f;
            var_2 = (s32) var_16->brain;
            var_2->unk54 = (f32) (var_16->health * var_2->unk5C);
        }
    }
    return var_2;
}

/* ---- func_0013CB08 ---- */
s32 func_0013CB08(TheGame* arg0, s32 arg1, ...) {
    AIBrain* temp_6;
    Driver* temp_3_2;
    Driver* temp_4;
    Vehicle* temp_7;
    Vehicle* var_16;
    Vehicle* var_2;
    Vehicle** var_4;
    f32 temp_f1;
    f32 temp_f2;
    f32 var_f1;
    f32 var_f5;
    s32 temp_3;
    s32 var_8;

    var_2 = arg0 + 0x98000;
    var_f5 = 3.1415927f;
    temp_3 = arg0->numAIs;
    var_16 = NULL;
    if (temp_3 > 0) {
        var_8 = temp_3;
        var_4 = arg0->ais;
        do {
            temp_7 = *var_4;
            var_2 = (Vehicle* ) temp_7->netRemote;
            if (var_2 != NULL) {
                var_8 -= 1;
            } else {
                temp_3_2 = temp_7->driver;
                var_2 = (Vehicle* ) temp_3_2->mode;
                if (var_2 == (Vehicle* )5) {
                    var_8 -= 1;
                } else {
                    temp_6 = temp_7->brain;
                    var_2 = (Vehicle* ) temp_6->sniping;
                    if (var_2 != NULL) {
                        var_8 -= 1;
                    } else {
                        var_2 = temp_3_2->target;
                        if (var_2->aiOrPlayerIdx != arg1) {
                            var_8 -= 1;
                        } else {
                            temp_f2 = temp_6->targetDist;
                            temp_f1 = fabsf(temp_6->targetFacing);
                            if (temp_f2 > 2000.0f) {
                                var_f1 = temp_f1 + 0.7853982f;
                            } else {
                                var_f1 = temp_f1 + ((temp_f2 * 0.7853982f) / 2000.0f);
                            }
                            var_8 -= 1;
                            if (var_f1 < var_f5) {
                                var_f5 = var_f1;
                                var_16 = temp_7;
                            }
                        }
                    }
                }
            }
            var_4 += 4;
        } while (var_8 != 0);
    }
    if ((var_16 != NULL) && (var_f5 < 1.5707964f)) {
        temp_4 = var_16->driver;
        var_2 = (Vehicle* ) temp_4->mode;
        if (var_2 != (Vehicle* )2) {
            func_00130E88(temp_4, 2);
            var_2 = (Vehicle* ) var_16->brain;
            var_2->unk4C = 0;
        }
    }
    return (s32) var_2;
}

/* ---- func_0013CC48 ---- */
? rtReturnToShell__F14RtReturnReasoni(?, ?);        /* extern */
extern s32 D_00317274;

s32 func_0013CC48(TheGame* arg0, ...) {
    Vehicle** var_16;
    f32 temp_f0;
    s32 var_18;
    s32 var_2;

    var_2 = D_00317274;
    if (var_2 == 0) {
        var_2 = 0x98000;
        var_18 = 0;
        arg0->progressMax = 1.0f;
        if (arg0->numHumans > 0) {
            var_16 = arg0->humans;
            do {
                if ((*var_16)->updateEnabled != 0) {
                    rtReturnToShell__F14RtReturnReasoni(1, 0x12C);
                    arg0->unk9FD9C = 1;
                }
                temp_f0 = (*var_16)->health / (*var_16)->turboDrain;
                if (temp_f0 < arg0->progressMax) {
                    arg0->progressMax = temp_f0;
                }
                var_18 += 1;
                var_2 = var_18 < arg0->numHumans;
                var_16 += 4;
            } while (var_2 != 0);
        }
    }
    return var_2;
}

/* ---- func_0013CD18 ---- */
s32 func_0013CD18(TheGame* arg0, ...) {
    FVECTOR* var_4_2;
    Vehicle* temp_16;
    Vehicle* temp_4;
    f32 temp_f0;
    f32 temp_f1;
    s32 temp_22;
    s32 temp_2;
    s32 temp_3;
    s32 var_18;
    s32 var_2;
    s32 var_4;
    void* temp_2_2;
    void** var_17;

    var_2 = 0x98000;
    temp_3 = arg0->numFodder;
    if (temp_3 != 0) {
        temp_2 = arg0->unk9FD28 + 1;
        arg0->unk9FD28 = temp_2;
        if (temp_2 >= temp_3) {
            arg0->unk9FD28 = 0;
        }
        var_4 = 0;
        do {
            temp_16 = &arg0->vehicles[var_4];
            temp_22 = var_4 + 1;
            if (temp_16->kind == 3) {
                temp_16->nearHuman = 0;
                temp_16->distNearestHuman = 20000.0f;
                var_18 = 0;
                if (arg0->numViews > 0) {
                    var_17 = arg0->views;
                    do {
                        temp_2_2 = *var_17;
                        if (temp_2_2 != NULL) {
                            temp_4 = arg0->humans[0];
                            var_4_2 = &temp_4->pos;
                            if (temp_4 != NULL) {

                            } else {
                                var_4_2 = temp_2_2 + 0x10;
                            }
                            temp_f0 = mathfManhatDist__FP8_fvectorT0(var_4_2, temp_16->cs + 0x10);
                            if (temp_f0 < temp_16->distNearestHuman) {
                                temp_16->distNearestHuman = temp_f0;
                            }
                        }
                        var_18 += 1;
                        var_17 += 4;
                    } while (var_18 < arg0->numViews);
                }
                temp_f1 = temp_16->distNearestHuman;
                var_4 = temp_22;
                if (temp_f1 < 1500.0f) {
                    if (temp_16->cs->unkE != 0) {
                        temp_16->nearHuman = 1;
                        goto block_21;
                    }
                    var_2 = var_4 < 8;
                    if (temp_f1 < 300.0f) {
                        temp_16->nearHuman = 1;
                        goto block_20;
                    }
                } else {
                    goto block_21;
                }
            } else {
block_20:
                var_4 = temp_22;
block_21:
                var_2 = var_4 < 8;
            }
        } while (var_2 != 0);
    }
    return var_2;
}

/* ---- func_0013CEE0 ---- */
? func_0011DBE0(TheGame*);                          /* extern */
? func_0011E0E8(TheGame*);                          /* extern */
? func_0011E5C0(TheGame*);                          /* extern */
? func_001212E8(TheGame*);                          /* extern */
? func_00121AC0(TheGame*);                          /* extern */
? func_001DF840(TheGame*);                          /* extern */
? func_001E0230(TheGame*);                          /* extern */
? func_001E03C0(TheGame*);                          /* extern */

s32 func_0013CEE0(TheGame* arg0, ...) {
    TheGame* var_16;
    TheGame* var_16_2;
    TheGame* var_16_3;
    TheGame* var_16_4;
    s32 temp_2;
    s32 var_2;
    u8* temp_17;
    void* temp_3;
    void* temp_3_2;
    void* temp_3_3;
    void* temp_3_4;

    var_16 = arg0;
    var_2 = var_16->vehicles[0].kind;
loop_1:
    if ((var_2 != 0) && (var_16->vehicles[0].hidden == 0)) {
        func_001DF840(var_16);
        func_001E03C0(var_16);
    }
    var_16 += 0x31B0;
    if ((s32) var_16 < (s32) arg0->_pad18D80) {
        var_2 = var_16->vehicles[0].kind;
        goto loop_1;
    }
    var_16_2 = arg0;
    do {
        if ((var_16_2->vehicles[0].kind != 0) && (var_16_2->vehicles[0].hidden == 0)) {
            func_0011DBE0(var_16_2);
            func_0011E5C0(var_16_2);
        }
        var_16_2 += 0x31B0;
    } while ((s32) var_16_2 < (s32) arg0->_pad18D80);
    var_16_3 = arg0;
    do {
        if ((var_16_3->vehicles[0].kind != 0) && (var_16_3->vehicles[0].hidden == 0)) {
            func_00121AC0(var_16_3);
            func_001212E8(var_16_3);
        }
        var_16_3 += 0x31B0;
    } while ((s32) var_16_3 < (s32) arg0->_pad18D80);
    var_16_4 = arg0;
    temp_17 = var_16_4->_pad18D80;
    do {
        if ((var_16_4->vehicles[0].kind != 0) && (var_16_4->vehicles[0].hidden == 0)) {
            if (var_16_4->unk1A78 != 0) {
                func_001E0230(var_16_4);
                func_0011E0E8(var_16_4);
            }
            if (var_16_4->unk1A68 == 0) {
                var_16_4->unk280 = (s128) var_16_4->unk790->unk10;
                temp_3 = var_16_4->unk790;
                temp_3_2 = temp_3 + 0x20;
                var_16_4->unk90 = (s128) temp_3->unk20;
                var_16_4->unkA0 = (s128) temp_3_2->unk10;
                var_16_4->unkB0 = (s128) temp_3_2->unk20;
                var_16_4->unkC0 = (s128) temp_3_2->unk30;
                var_16_4->vehicles[0].prevPos2 = var_16_4->vehicles[0].cs->unk10;
                temp_3_3 = var_16_4->vehicles[0].cs;
                temp_3_4 = temp_3_3 + 0x20;
                var_16_4->vehicles[0].prevPos = temp_3_3->unk20;
                var_16_4->unk60 = (s128) temp_3_4->unk10;
                var_16_4->unk70 = (s128) temp_3_4->unk20;
                var_16_4->unk80 = (s128) temp_3_4->unk30;
            }
        }
        var_16_4 += 0x31B0;
        temp_2 = (s32) var_16_4 < (s32) temp_17;
    } while (temp_2 != 0);
    return temp_2;
}

/* ---- func_0013D0C0 ---- */
? JunkyardTunnelDoorTrigger__Fi(?, s32);            /* extern */
? SetDeathPOV__6Camerai(u8*, s32, s32*, ?);         /* extern */
f32 brightness__7CsColorv();                        /* extern */
f32 contrast__7CsColorv();                          /* extern */
? doAmbientVolume__FiP18_hierambientvolumeP8_fvector(s32, void*, FVECTOR*); /* extern */
? doFogVolume__FiP14_hierfogvolumeP8_fvector(s32, void*, FVECTOR*); /* extern */
s32 dpdiv(s32, s64);                                /* extern */
f32 dptofp(s32);                                    /* extern */
s32 fptodp(f32);                                    /* extern */
? func_00131DB0(u8*, void*, Vehicle*);              /* extern */
? func_0021CD40(void*, FVECTOR*, void*);            /* extern */
s32 func_00232480(FVECTOR*, void*);                 /* extern */
f32 getLightVolWeight__FP16_hierlightvolumeP8_fvector(s32, FVECTOR*); /* extern */
? particleRainShelter__Fii(s32, s32);               /* extern */
? setReverbDepth__19AmbientSoundManagerffii(u8*, s32, u16, void*, f32, f32); /* extern */
? todSetPlightsActive__Fii(s32, ?);                 /* extern */

s32 func_0013D0C0(TheGame* arg0, ...) {
    u8* sp40;
    s32 sp44;
    u8* sp48;
    u8* sp4C;
    u8* sp50;
    s32 sp54;
    s32 sp58;
    FVECTOR* temp_4;
    Vehicle* temp_17;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    s32 temp_18;
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 temp_3_4;
    s32 temp_5;
    s32 var_18;
    s32 var_19;
    s32 var_2;
    s32 var_2_2;
    s32 var_4;
    s32* temp_6;
    u16 temp_3;
    u32 temp_3_5;
    u8* temp_4_2;
    u8* temp_4_3;
    u8* var_5;
    void* temp_3_6;
    void* temp_3_7;
    void* temp_3_8;
    void* temp_5_2;
    void* temp_7;
    void* var_16;
    void** temp_16;

    var_4 = 0;
    sp40 = &arg0->_pad2BB64[0x30];
    var_2 = 1;
loop_1:
    sp54 = var_2;
    temp_17 = &arg0->vehicles[var_4];
    var_4 = sp54;
    if ((u32) (temp_17->kind - 1) < 2U) {
        if (temp_17->isLocalHuman != 0) {
            *(sp40 + (temp_17->viewIdx * 4)) = 0;
        }
        temp_4 = &temp_17->pos;
        temp_17->unk2F54 = 0;
        temp_2_2 = func_00232480(temp_4, sp);
        var_18 = 0;
        sp44 = temp_2_2;
        if (temp_2_2 > 0) {
            temp_4_2 = arg0->camera;
            var_5 = temp_4_2 + 0x4414;
            sp4C = temp_4_2;
            sp48 = &arg0->camera[0x10];
            sp50 = var_5;
            var_2_2 = 0 * 8;
            do {
                temp_3 = (sp + var_2_2)->unk4;
                switch ((s32) temp_3) {             /* switch 1; irregular */
                case 0x12C6:                        /* switch 1 */
                    temp_3_2 = temp_17->netRole;
                    if ((temp_3_2 == 1) || (temp_3_2 == 4)) {
                        temp_4_3 = arg0->camera;
                        if (temp_17->isLocalHuman != 0) {
                            temp_5 = temp_17->viewIdx * 4;
                            temp_6 = temp_4_3 + temp_5;
                            if (*temp_6 != 6) {
                                temp_17->pendingDeath = 1;
                                *(sp48 + temp_5) = *temp_6;
                                SetDeathPOV__6Camerai(temp_4_3, temp_17->viewIdx, temp_6, 1);
                            }
                        } else if (!(temp_17->unk480 & (0xFFFF << 0x28))) {
                            temp_17->pendingDeath = 1;
                        }
                        if (temp_17->character == 0x220) {
                            temp_17->unk450 = 0x1C20;
                        }
                    }
                    break;
                case 0x133E:                        /* switch 1 */
                    temp_3_3 = temp_17->netRole;
                    if (((temp_3_3 == 1) || (temp_3_3 == 4)) && !(temp_17->unk480 & (((0xFF00 << 0x10) | 0xFF00) << 0x20))) {
                        temp_17->_pad487[0] = 1;
                        temp_17->pendingDeath = 1;
                        if (temp_17->isLocalHuman != 0) {
                            temp_2_3 = temp_17->viewIdx * 4;
                            temp_3_4 = *(sp4C + temp_2_3);
                            if (temp_3_4 != 6) {
                                *(sp48 + temp_2_3) = temp_3_4;
                            }
                        }
                    }
                    break;
                default:                            /* switch 1 */
                    func_00131DB0(&arg0->_pad34890[0x9A50], sp + var_2_2, temp_17);
                    break;
                case 0x1327:                        /* switch 1 */
                    JunkyardTunnelDoorTrigger__Fi(1, (s32) var_5);
                    break;
                case 0x1328:                        /* switch 1 */
                    JunkyardTunnelDoorTrigger__Fi(0, (s32) var_5);
                    break;
                }
                if (temp_17->kind == 1) {
                    temp_16 = sp + var_2_2;
                    if ((*temp_16)->unk4 & 4) {
                        todSetPlightsActive__Fii(temp_17->viewIdx, 0);
                    }
                    if ((*temp_16)->unk4 & 2) {
                        particleRainShelter__Fii(((u32) (*temp_16)->unk0 >> 7) & 0x7FF, temp_17->viewIdx);
                        temp_17->unk2F54 = 1;
                    }
                }
                if ((temp_17->isLocalHuman != 0) && ((*(sp + var_2_2))->unk4 & 1)) {
                    *(sp50 + (temp_17->viewIdx * 4)) = 1;
                }
                sp58 = var_18 + 1;
                var_19 = 0;
                if ((*(sp + var_2_2))->unkC > 0) {
                    var_16 = sp + var_2_2;
                    do {
                        temp_18 = var_19 * 4;
                        temp_5_2 = (var_16->unk0 + temp_18)->unk10;
                        temp_3_5 = temp_5_2->unk0 & 0x3F;
                        switch (temp_3_5) {         /* switch 2; irregular */
                        case 26:                    /* switch 2 */
                            func_0021CD40(temp_5_2, temp_4, temp_17->cs + 8);
                            temp_f20 = contrast__7CsColorv();
                            temp_3_6 = temp_17->cs;
                            temp_3_6->unk80 = (f32) (((((2.0f * (f32) temp_3_6->unk8) / 255.0f) - 1.0f) * temp_f20) + 1.0f + brightness__7CsColorv());
                            temp_f20_2 = contrast__7CsColorv();
                            temp_3_7 = temp_17->cs;
                            temp_3_7->unk84 = (f32) (((((2.0f * (f32) temp_3_7->unk9) / 255.0f) - 1.0f) * temp_f20_2) + 1.0f + brightness__7CsColorv());
                            temp_f20_3 = contrast__7CsColorv();
                            temp_3_8 = temp_17->cs;
                            temp_3_8->unk88 = (f32) (((((2.0f * (f32) temp_3_8->unkA) / 255.0f) - 1.0f) * temp_f20_3) + 1.0f + brightness__7CsColorv());
                            temp_17->cs->unk8C = 1.0f;
                            break;
                        case 29:                    /* switch 2 */
                            if (temp_17->netRole == 1) {
                                temp_7 = (var_16->unk0 + temp_18)->unk10;
                                setReverbDepth__19AmbientSoundManagerffii(&D_004FA030->_pad9E6A8[0x2A8], temp_17->viewIdx, var_16->unk4, temp_7, dptofp(dpdiv(fptodp(getLightVolWeight__FP16_hierlightvolumeP8_fvector(temp_5_2->unk4, temp_4)), ((0x80DF << 0x10) | 0xC000) << 0x1F)), temp_7->unk8);
                            }
                            break;
                        case 27:                    /* switch 2 */
                            if (temp_17->netRole == 1) {
                                doFogVolume__FiP14_hierfogvolumeP8_fvector(temp_17->viewIdx, temp_5_2, temp_4);
                            }
                            break;
                        case 28:                    /* switch 2 */
                            if (temp_17->netRole == 1) {
                                doAmbientVolume__FiP18_hierambientvolumeP8_fvector(temp_17->viewIdx, temp_5_2, temp_4);
                            }
                            break;
                        }
                        var_19 += 1;
                        var_16 = sp + var_2_2;
                    } while (var_19 < (*(sp + var_2_2))->unkC);
                }
                var_18 = sp58;
                var_5 = (u8* ) sp44;
                var_2_2 = var_18 * 8;
            } while (var_18 < (s32) var_5);
        }
        var_4 = sp54;
    }
    temp_2 = var_4 < 8;
    if (temp_2 != 0) {
        var_2 = var_4 + 1;
        goto loop_1;
    }
    return temp_2;
}

/* ---- func_0013D788 ---- */
s32 func_0013D788(TheGame* arg0, s32 arg1, ...) {
    s32 temp_2;

    (arg0 + 0x98000 + (arg0->unk9FC80 * 4))->unk7AF0 = arg1;
    temp_2 = arg0->unk9FC80 + 1;
    arg0->unk9FC80 = temp_2;
    return temp_2;
}

/* ---- func_0013D7B8 ---- */
f32 atan2f(u8*, s32, void*, void*, f32, f32);       /* extern */
? func_0010BDC0(s32, s32);                          /* extern */
s32 func_0010BE18(u8*, Vehicle*);                   /* extern */
s32 func_0010BEF8(u8*, FVECTOR*);                   /* extern */
? mathfRotMatrixRPH__FPA3_fP8_fvector(void*, void*); /* extern */
extern s32 D_00317274;
extern s32 D_004FB4D4;

s32 func_0013D7B8(TheGame* arg0, void* arg1, s32 arg2, ...) {
    f32 sp4;
    Vehicle* var_5;
    s32 temp_21;
    s32 temp_4;
    s32 temp_4_2;
    s32 var_2;
    void* temp_17;
    void* temp_2;
    void* temp_4_3;
    void* temp_6;

    var_5 = arg0 + 0x98000;
    temp_4 = arg0->levelType;
    temp_21 = arg1->unk214C;
    if (temp_4 != 0x15) {
        if (arg2 != -1) {
            arg1->unk214C = arg2;
        } else {
            if ((arg1->unk590 == 1) && (arg1->unk2100 != 0) && (temp_4 != 3) && (var_5 = arg0->humans[0], (var_5 != NULL))) {
                if (D_00317274 == 0) {
                    var_2 = func_0010BEF8(arg0->attractorPoints, &var_5->pos);
                } else {
                    goto block_11;
                }
            } else {
block_11:
                var_2 = func_0010BE18(arg0->attractorPoints, var_5);
            }
            arg1->unk214C = var_2;
        }
        if (arg1->unk214C >= 0) {
            if (arg2 == -1) {
                gameCheckStartPoint__7TheGamePib(arg0, arg1 + 0x214C, 0);
            }
            temp_17 = arg0->unk30970 + (arg1->unk214C << 5);
            arg1->unk1D0 = (s128) temp_17->unk0;
            if (arg2 != -1) {
                if ((temp_17->unk1E - 1) < D_004FB4D4) {
                    D_004FB4D4 = 0;
                }
            } else {
                mathfRand__Fii(0, temp_17->unk1E - 1);
            }
            temp_4_2 = arg1->unk214C;
            if ((temp_4_2 < 0) || (temp_4_2 >= arg0->unk30BB8)) {
                arg1->unk214C = 0;
            }
            temp_6 = arg1->unk2028;
            temp_6->unk60 = 0;
            arg1->unk2028->unk64 = 0;
            M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($s1) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($a3) */);
            M2C_ERROR(/* unknown instruction: vsub.xyz $vf11, $vf11, $vf12 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf11, ($sp) */);
            if (sp4 == 0.0f) {
                sp4 = 0.01f;
            }
            arg1->unk2028->unk68 = atan2f(arg0->attractorPoints, arg0->unk30970, temp_6, arg1 + 0x1D0, sp0, sp4);
            temp_4_3 = arg1->unk2028;
            mathfRotMatrixRPH__FPA3_fP8_fvector(temp_4_3 + 0x20, temp_4_3 + 0x60);
        } else {
            temp_2 = arg1 + 0x1D0;
            arg1->unk1D0 = 0;
            temp_2->unk8 = 200.0f;
            temp_2->unk4 = 0;
            arg1->unk214C = -1;
        }
    }
    func_0010BDC0(D_004FA030 + 0x30970, temp_21);
    return func_0013DA30(arg0, arg1);
}

/* ---- func_0013DA30 ---- */
? collisInitFirstFrame__7Vehicle(Vehicle*);         /* extern */
? func_00207690(void*);                             /* extern */
s32 hierSetCameraVehiclePos__FP8_fvectori(s32, s32); /* extern */
? mathfUnitMatrixAsm__FPA3_f(u8*);                  /* extern */
? vehicleSetToPosition__7VehicleP8_fvectorf(Vehicle*, s32, f32); /* extern */
extern s128 D_004FBFB0;

s32 func_0013DA30(TheGame* arg0, Vehicle* arg1, ...) {
    s32 temp_18;
    s32 var_2;
    void* temp_2;
    void* temp_2_2;
    void* temp_4;

    temp_18 = arg1 + 0x1D0;
    vehicleSetToPosition__7VehicleP8_fvectorf(arg1, temp_18, arg1->cs->unk68);
    arg1->aliveTicks = 0;
    collisInitFirstFrame__7Vehicle(arg1);
    arg1->prevPos2 = (s128) arg1->pos;
    arg1->prevPos2.z += 2.0f;
    arg1->unk280 = (s128) arg1->pos;
    arg1->prevPos2.z += 3.0f;
    D_004FBFB0 = (s128) arg1->pos;
    arg1->velAlongHeading = 0.0f;
    arg1->throttle = 0.0f;
    arg1->unk200 = 0;
    arg1->steer = 0.0f;
    arg1->unk204 = 0;
    arg1->unk1F0 = 0;
    arg1->unk1F8 = 0;
    arg1->unk1F4 = 0;
    temp_2 = arg1->cs;
    temp_2_2 = temp_2 + 0x20;
    arg1->unkD0 = (s128) temp_2->unk20;
    arg1->unkE0 = (s128) temp_2_2->unk10;
    arg1->unkF0 = (s128) temp_2_2->unk20;
    arg1->unk100 = (s128) temp_2_2->unk30;
    arg1->prevPos = arg1->unkD0;
    arg1->unk60 = (s128) arg1->unkE0;
    arg1->unk70 = (s128) arg1->unkF0;
    arg1->unk80 = (s128) arg1->unk100;
    arg1->unk90 = (s128) arg1->unkD0;
    arg1->unkA0 = (s128) arg1->unkE0;
    arg1->unkB0 = (s128) arg1->unkF0;
    arg1->unkC0 = (s128) arg1->unk100;
    arg1->unk230 = 0;
    arg1->unk238 = 0;
    arg1->unk234 = 0;
    mathfUnitMatrixAsm__FPA3_f(&arg1->_pad110[0x80]);
    arg1->speedRatio = 0.0f;
    arg1->unk294 = 1.0f;
    arg1->unk298 = 0;
    if (arg1->kind == 2) {
        driverGetNewPointInFrontOfVehicle__6DriverP7Vehicle(arg1->driver, arg1);
        aiLoseBeads__7Vehicle(arg1);
    }
    arg1->cs->unk10 = (s128) arg1->pos;
    temp_4 = arg1->cs;
    temp_4->unk20 = (s128) arg1->unkD0;
    temp_4->unk30 = (s128) arg1->unkE0;
    temp_4->unk40 = (s128) arg1->unkF0;
    temp_4->unk50 = (s128) arg1->unk100;
    func_00207690(arg1->cs);
    var_2 = arg1->isLocalHuman;
    if (var_2 != 0) {
        *(&arg0->_pad2BB64[0x20] + (arg1->viewIdx * 4)) = 1;
        var_2 = hierSetCameraVehiclePos__FP8_fvectori(temp_18, arg1->viewIdx);
    }
    return var_2;
}

/* ---- func_0013DDD8 ---- */
extern s32 D_004FB4CC;

s32 func_0013DDD8(TheGame* arg0, ...) {
    Vehicle** var_17;
    s32 temp_16;
    s32 var_18;
    s32 var_2;

    arg0->unk9FD2C = 0xA8C;
    var_18 = 0;
    arg0->unk9FD30 = 0;
    arg0->unk9FD34 = 0;
    D_004FB4CC = 3;
    gameInitCamera__7TheGameii(arg0, 0, arg0->ais[0]->vehicleIdx);
    var_2 = 0x90000;
    if (arg0->numAIs > 0) {
        var_17 = arg0->ais;
        do {
            temp_16 = var_18 ^ 1;
            var_18 += 1;
            func_00130E88((*var_17)->driver, 5);
            func_00130C00((*var_17)->driver, *(arg0 + 0x98000 + 0x6690 + (temp_16 * 4)));
            (*var_17)->brain->pickupMode = 0;
            (*var_17)->brain->fleeHealth = 0.0f;
            (*var_17)->brain->unk4C = 0.0f;
            var_2 = var_18 < arg0->numAIs;
            var_17 += 4;
        } while (var_2 != 0);
    }
    return var_2;
}

/* ---- func_0013DED8 ---- */
? func_00117B90(u8*, ?);                            /* extern */
s32 inputAnyKey__Fi(?, ?);                          /* extern */
? rtReturnToShell__F14RtReturnReasoni(?, ?);        /* extern */
s32 timerGetFieldsLastFrame__Fv();                  /* extern */

s32 func_0013DED8(TheGame* arg0, ...) {
    s32 temp_19;
    s32 temp_2;
    s32 temp_4;
    s32 var_16;
    s32 var_2;

    arg0->unk9FD30 = (s32) (arg0->unk9FD30 + timerGetFieldsLastFrame__Fv());
    if ((inputAnyKey__Fi(0, 0x98000) != 0) || (inputAnyKey__Fi(1) != 0) || (arg0->unk9FD2C < arg0->unk9FD30) || (arg0->numAIsAlive != arg0->numAIs)) {
        rtReturnToShell__F14RtReturnReasoni(1, 1);
        arg0->unk9FD9C = 1;
    }
    temp_4 = arg0->unk9FD34 + timerGetFieldsLastFrame__Fv();
    var_2 = temp_4 < 0x1A5;
    arg0->unk9FD34 = temp_4;
    if (var_2 == 0) {
        arg0->unk9FD34 = 0;
        temp_2 = mathfRand__Fii(0, 5);
        temp_19 = arg0->unk27780;
        if (temp_2 > 0) {
            var_16 = temp_2;
            do {
                func_00117B90(arg0->camera, 0);
                var_16 -= 1;
            } while (var_16 != 0);
        }
        if (temp_19 == arg0->unk27780) {
            func_00117B90(arg0->camera, 0);
        }
        var_2 = mathfRand__Fii(0, 1);
        if (var_2 != 0) {
            var_2 = gameInitCamera__7TheGameii(arg0, 0, (arg0 + 0x98000 + (mathfRand__Fii(0, arg0->numAIs - 1) * 4))->unk6690->unk2104);
        }
    }
    return var_2;
}

/* ---- func_0013E070 ---- */
s32 func_0013E070(TheGame* arg0, s32 arg1, ...) {
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 var_3;
    s32 var_3_10;
    s32 var_3_2;
    s32 var_3_3;
    s32 var_3_4;
    s32 var_3_5;
    s32 var_3_6;
    s32 var_3_7;
    s32 var_3_8;
    s32 var_3_9;
    s8 var_2;
    u8* temp_10;
    u8* temp_2_10;
    u8* temp_2_11;
    u8* temp_2_12;
    u8* temp_2_5;
    u8* temp_2_6;
    u8* temp_2_7;
    u8* temp_2_8;
    u8* temp_2_9;
    u8* temp_4;
    u8* temp_4_2;
    u8* temp_4_3;
    u8* temp_4_4;
    u8* temp_4_5;
    u8* temp_4_6;
    u8* temp_4_7;
    u8* temp_5;
    u8* temp_5_2;
    u8* temp_7;
    u8* temp_7_2;
    u8* var_4;
    u8* var_4_2;
    u8* var_4_3;
    u8* var_4_4;
    u8* var_4_5;
    u8* var_4_6;
    u8* var_4_7;
    u8* var_5;
    u8* var_5_2;
    u8* var_6;
    u8* var_6_2;
    u8* var_6_3;
    u8* var_7;
    u8* var_7_2;
    u8* var_9;

    temp_7 = &D_004FA030->_pad34890[0x28A0];
    temp_4 = D_004FA030->attractorPoints;
    if (arg1 != 0x17A4) {
        var_2 = 0x17A3;
        if (arg1 < 0x17A5) {
            temp_4_2 = temp_4 + 0xE80;
            if (arg1 != 0x17A3) {
                /* Duplicate return node #3. Try simplifying control flow for better match */
                return (s32) var_2;
            }
            temp_4_2->unk1E = 4;
            temp_4_2->unk16 = 0x62;
            var_5 = temp_7 + 0x2A5C;
            temp_4_3 = temp_7 + 0x2AE0;
            temp_10 = temp_7 + 0x2BC0;
            var_3 = 6;
            do {
                temp_2_5 = &temp_4_3[var_3];
                *var_5 = 0x61;
                var_3 += 1;
                *temp_2_5 = 0xA;
                var_5 += 2;
            } while (var_3 < 0xB);
            var_4 = temp_7 + 0x2A50 + 0x50;
            var_3_2 = 0x28;
            do {
                temp_2_6 = &temp_4_3[var_3_2];
                *var_4 = 0x16;
                var_3_2 += 1;
                *temp_2_6 = 0xA;
                var_4 += 2;
            } while (var_3_2 < 0x2C);
            var_2 = temp_10->unkB6;
            temp_7_2 = temp_10 + 0xB0;
            if (var_2 == 0x1D) {
                var_6 = temp_10 + 0x2C;
                var_3_3 = 6;
                do {
                    temp_2_7 = &temp_7_2[var_3_3];
                    *var_6 = 0x1E;
                    var_3_3 += 1;
                    *temp_2_7 = 0x1B;
                    var_6 += 2;
                } while (var_3_3 < 0xB);
                var_4_2 = temp_10 + 0x20 + 0x50;
                var_3_4 = 0x28;
                do {
                    temp_2_8 = &temp_7_2[var_3_4];
                    *var_4_2 = 0x1E;
                    var_3_4 += 1;
                    *temp_2_8 = 0x1B;
                    temp_2_4 = var_3_4 < 0x2C;
                    var_4_2 += 2;
                } while (temp_2_4 != 0);
                return temp_2_4;
            }
            /* Duplicate return node #3. Try simplifying control flow for better match */
            return (s32) var_2;
        }
        if (arg1 != 0x17A5) {
            temp_4_4 = temp_4 + 0xF60;
            if (arg1 != 0x17A6) {
                return 0x17A6;
            }
            temp_4_4->unk1E = 4;
            temp_4_4->unk16 = 0x66;
            var_5_2 = temp_7 + 0x2D7C;
            temp_4_5 = temp_7 + 0x2E00;
            var_3_5 = 6;
            do {
                temp_2_9 = &temp_4_5[var_3_5];
                *var_5_2 = 0x68;
                var_3_5 += 1;
                *temp_2_9 = 0xB;
                var_5_2 += 2;
            } while (var_3_5 < 0xC);
            var_4_3 = temp_7 + 0x2D70 + 0x50;
            var_3_6 = 0x28;
            do {
                temp_2_10 = &temp_4_5[var_3_6];
                *var_4_3 = 0x68;
                var_3_6 += 1;
                *temp_2_10 = 0xB;
                temp_2_3 = var_3_6 < 0x2C;
                var_4_3 += 2;
            } while (temp_2_3 != 0);
            return temp_2_3;
        }
        temp_4_6 = temp_4 + 0xF00;
        temp_4_6->unk1E = 4;
        temp_4_6->unk16 = 0x66;
        var_6_2 = temp_7 + 0x2C76;
        temp_5 = temp_7 + 0x2BC0;
        var_3_7 = 6;
        var_4_4 = temp_7 + 0x2BEC;
        do {
            if ((u32) (var_3_7 - 8) >= 2U) {
                if (var_3_7 != 0xB) {
                    var_7 = temp_5 + 0xB0;
                    if ((s8) *var_6_2 != 0xA) {
                        *var_4_4 = 0x65;
                        *var_6_2 = 0xB;
                    }
                } else {
                    goto block_34;
                }
            } else {
block_34:
                *var_4_4 = 0x65;
                var_7 = temp_5 + 0xB0;
                *var_6_2 = 0xB;
            }
            var_3_7 += 1;
            var_4_4 += 2;
            var_6_2 += 1;
        } while (var_3_7 < 0xC);
        var_2 = 0xA;
        if (temp_5->unkD8 != 0xA) {
            var_4_5 = temp_5 + 0x70;
            var_3_8 = 0x28;
            do {
                temp_2_11 = &var_7[var_3_8];
                *var_4_5 = 0x65;
                var_3_8 += 1;
                *temp_2_11 = 0xB;
                temp_2_2 = var_3_8 < 0x2C;
                var_4_5 += 2;
            } while (temp_2_2 != 0);
            return temp_2_2;
        }
        return (s32) var_2;
    }
    temp_4_7 = temp_4 + 0xEE0;
    temp_4_7->unk1E = 4;
    temp_4_7->unk16 = 0x62;
    var_6_3 = temp_7 + 0x2C76;
    temp_5_2 = temp_7 + 0x2BC0;
    var_3_9 = 6;
    var_4_6 = temp_7 + 0x2BEC;
    do {
        if ((u32) (var_3_9 - 6) >= 2U) {
            if (var_3_9 != 0xA) {
                var_9 = temp_5_2 + 0x20;
                var_7_2 = temp_5_2 + 0xB0;
                if ((s8) *var_6_3 != 0xB) {
                    *var_4_6 = 0x64;
                    *var_6_3 = 0xA;
                }
            } else {
                goto block_22;
            }
        } else {
block_22:
            *var_4_6 = 0x64;
            var_9 = temp_5_2 + 0x20;
            *var_6_3 = 0xA;
            var_7_2 = temp_5_2 + 0xB0;
        }
        var_3_9 += 1;
        var_4_6 += 2;
        var_6_3 += 1;
    } while (var_3_9 < 0xC);
    var_4_7 = var_9 + 0x50;
    var_3_10 = 0x28;
    do {
        temp_2_12 = &var_7_2[var_3_10];
        *var_4_7 = 0x64;
        var_3_10 += 1;
        *temp_2_12 = 0xA;
        temp_2 = var_3_10 < 0x2C;
        var_4_7 += 2;
    } while (temp_2 != 0);
    return temp_2;
}

/* ---- func_0013E630 ---- */
s32 Update__7BurnMan(u8*);                          /* extern */

s32 func_0013E630(TheGame* arg0, ...) {
    s32 var_17;
    s32 var_2;
    u8* var_16;

    var_17 = 2;
    var_16 = &arg0->_pad34890[0x62150];
    do {
        var_2 = *var_16;
        if (var_2 != 0) {
            var_2 = Update__7BurnMan(var_16);
        }
        var_17 -= 1;
        var_16 += 0x50;
    } while (var_17 >= 0);
    return var_2;
}

/* ---- func_0013E688 ---- */
s32 Terminate__7BurnMan(u8*);                       /* extern */

s32 func_0013E688(TheGame* arg0, ...) {
    s32 var_17;
    s32 var_2;
    u8* var_16;

    var_17 = 2;
    var_16 = &arg0->_pad34890[0x62150];
    do {
        var_2 = *var_16;
        if (var_2 != 0) {
            var_2 = Terminate__7BurnMan(var_16);
        }
        var_17 -= 1;
        var_16 += 0x50;
    } while (var_17 >= 0);
    return var_2;
}

/* ---- func_0013E6E0 ---- */
? func_001E5AE8(s32);                               /* extern */

s32 func_0013E6E0(TheGame* arg0, ...) {
    TheGame* var_16;
    s32 temp_2;
    s32 var_2;
    u8* temp_17;

    var_16 = arg0;
    temp_17 = var_16->_pad18D80;
    var_2 = var_16->vehicles[0].kind;
loop_1:
    if (var_2 != 0) {
        func_001E5AE8((s32) var_16);
    }
    var_16 += 0x31B0;
    temp_2 = (s32) var_16 < (s32) temp_17;
    if (temp_2 != 0) {
        var_2 = var_16->vehicles[0].kind;
        goto loop_1;
    }
    return temp_2;
}

/* ---- func_0013E740 ---- */
s32 func_001F2B40(u8*);                             /* extern */

s32 func_0013E740(TheGame* arg0, ...) {
    return func_001F2B40(&arg0->_pad34890[0x37A80]);
}

/* ---- func_0013E768 ---- */
s32 func_0013E768(TheGame* arg0, ...) {
    s32 temp_4;
    s32 var_2;
    s32 var_5;
    s32 var_8;
    s32* temp_7;
    u8* var_6;

    var_2 = 0x98000;
    var_5 = 0;
    if (arg0->numHumans > 0) {
        var_2 = 0 * 0x54;
        do {
            var_8 = 0;
            var_6 = &(&arg0->_pad9E6A8[0x20])[var_2];
            temp_7 = arg0 + 0x98000 + 0x6670 + (var_5 * 4);
loop_3:
            temp_4 = var_8 * 4;
            var_8 += 1;
            var_6->unk-24 = (s32) (*temp_7 + temp_4)->unk2338;
            var_6->unk0 = (s32) (*temp_7 + temp_4)->unk22AC;
            var_6 += 4;
            if (var_8 < 9) {
                goto loop_3;
            }
            var_5 += 1;
            var_2 = var_5 * 0x54;
        } while (var_5 < arg0->numHumans);
    }
    return var_2;
}

/* ---- func_0013E808 ---- */
s32 func_0013E808(TheGame* arg0, ...) {
    s32 temp_2;
    s32 var_2;

    temp_2 = arg0->numHumans;
    var_2 = temp_2 - 1;
    if (temp_2 > 0) {
        do {
            var_2 -= 1;
        } while (var_2 != 0);
    }
    return var_2;
}

/* ---- func_0013E848 ---- */
s32 func_0013E848(TheGame* arg0, ...) {
    s32 temp_2;
    s32 var_2;

    temp_2 = arg0->numHumans;
    var_2 = temp_2 - 1;
    if (temp_2 > 0) {
        do {
            var_2 -= 1;
        } while (var_2 != 0);
    }
    return var_2;
}

/* ---- func_0013E888 ---- */
s32 func_0013E888(TheGame* arg0, ...) {
    s32 temp_2;
    s32 var_2;

    temp_2 = arg0->numHumans;
    var_2 = temp_2 - 1;
    if (temp_2 > 0) {
        do {
            var_2 -= 1;
        } while (var_2 != 0);
    }
    return var_2;
}

/* ---- func_0013E8D0 ---- */
s32 func_0013E8D0(TheGame* arg0, ...) {
    s32 temp_4;
    s32 temp_5;
    s32 var_10;
    s32 var_11;
    s32 var_2;
    s32 var_4;
    s32 var_5;
    s32 var_6;
    s32 var_7;
    s32 var_8;
    s32 var_9;
    void* var_2_2;

    temp_4 = arg0->levelType;
    arg0->unk9FD90 = 0;
    arg0->unk9FD94 = 0;
    switch (temp_4) {
    case 0:
        arg0->unk9FD68 = 0x117;
        arg0->unk9FD90 = 9;
        arg0->unk9FD6C = 0x45;
        arg0->unk9FD70 = 0x62;
        arg0->unk9FD74 = 0x15A;
        arg0->unk9FD78 = 0x15F;
        arg0->unk9FD7C = 0x108;
        arg0->unk9FD80 = 0x7F;
        arg0->unk9FD84 = 0x163;
        arg0->unk9FD88 = 0x13B;
        break;
    case 1:
        var_11 = 0x89;
        var_10 = 0x56;
        var_2_2 = arg0 + 0x98000;
        var_4 = 0x31;
        var_5 = 0x6D;
        var_6 = 0x69;
        var_7 = 0x21;
        var_8 = 0xA;
        var_9 = 0x18;
block_8:
        var_2_2->unk7D90 = 8;
        var_2_2->unk7D68 = var_11;
        var_2_2->unk7D6C = var_10;
        var_2_2->unk7D70 = var_4;
        var_2_2->unk7D74 = var_5;
        var_2_2->unk7D78 = var_6;
        var_2_2->unk7D7C = var_7;
        var_2_2->unk7D80 = var_8;
        var_2_2->unk7D84 = var_9;
        break;
    case 2:
        var_11 = 0xB3;
        var_10 = 0x2A;
        var_2_2 = arg0 + 0x98000;
        var_4 = 0xAF;
        var_5 = 3;
        var_6 = 0x9E;
        var_7 = 0x90;
        var_8 = 0x8B;
        var_9 = 7;
        goto block_8;
    case 3:
        arg0->unk9FD68 = 0x65;
        arg0->unk9FD90 = 3;
        arg0->unk9FD6C = 0x69;
        arg0->unk9FD70 = 2;
        break;
    case 4:
        var_11 = 0x2F;
        var_10 = 0x34;
        var_2_2 = arg0 + 0x98000;
        var_4 = 0x3E;
        var_5 = 0x11;
        var_6 = 0x1B;
        var_7 = 0x19;
        var_8 = 0x58;
        var_9 = 0x78;
        goto block_8;
    case 5:
        var_11 = 0xD;
        var_10 = 0x12;
        var_2_2 = arg0 + 0x98000;
        var_4 = 0xB;
        var_5 = 5;
        var_6 = 0x31;
        var_7 = 0x2F;
        var_8 = 0x65;
        var_9 = 0x20;
        goto block_8;
    case 6:
        arg0->unk9FD68 = 0x1C;
        arg0->unk9FD90 = 8;
        arg0->unk9FD6C = 0x36;
        arg0->unk9FD74 = 0x34;
        arg0->unk9FD78 = 0x35;
        arg0->unk9FD7C = 0xB;
        arg0->unk9FD80 = 0x33;
        arg0->unk9FD84 = 0x2F;
        arg0->unk9FD70 = 0;
        break;
    case 8:
        arg0->unk9FD68 = 0x1A;
        arg0->unk9FD90 = 8;
        arg0->unk9FD70 = 0xA;
        arg0->unk9FD74 = 0x15;
        arg0->unk9FD78 = 1;
        arg0->unk9FD7C = 0x20;
        arg0->unk9FD80 = 2;
        arg0->unk9FD84 = 4;
        arg0->unk9FD6C = 2;
        break;
    case 12:
        arg0->unk9FD90 = 8;
        arg0->unk9FD6C = 0x1E;
        arg0->unk9FD70 = 0xB;
        arg0->unk9FD74 = 0xA;
        arg0->unk9FD7C = 6;
        arg0->unk9FD80 = 0x27;
        arg0->unk9FD84 = 0x16;
        arg0->unk9FD68 = 0;
        arg0->unk9FD78 = 8;
        break;
    }
    var_2 = 0x98000;
    temp_5 = arg0->unk9FD90;
    if (temp_5 != 0) {
        var_2 = mathfRand__Fii(0, temp_5);
        arg0->unk9FD94 = var_2;
    }
    return var_2;
}

/* ---- func_0013EBC0 ---- */
s32 func_0013EBC0(TheGame* arg0, ...) {
    s32 temp_2;
    s32 temp_2_2;
    s32 var_17;
    s32 var_5;

    var_17 = -1;
    if (arg0->unk9FD90 != 0) {
        var_17 = (arg0 + 0x98000 + (arg0->unk9FD94 * 4))->unk7D68;
        temp_2 = mathfRand__Fii(2, 3);
        if (temp_2 > 0) {
            var_5 = temp_2;
loop_3:
            temp_2_2 = arg0->unk9FD94 + 1;
            arg0->unk9FD94 = temp_2_2;
            if (temp_2_2 >= arg0->unk9FD90) {
                arg0->unk9FD94 = 0;
            }
            var_5 -= 1;
            if (var_5 != 0) {
                goto loop_3;
            }
        }
    }
    return var_17;
}

/* ---- func_0013EC58 ---- */
s32 func_00242658(?, ?);                            /* extern */
? viewSetNumViews__Fi(?);                           /* extern */

s32 func_0013EC58(TheGame* arg0, ...) {
    viewSetNumViews__Fi(2);
    func_00242658(0xE, 1);
    viewSetNumViews__Fi(1);
    return func_00242658(0, 0);
}

/* ---- func_0013EC98 ---- */
? hierSetCsDrawMe__FP3_csUc(void*, ?);              /* extern */
? shadow2ndOnOff__7Vehiclei(Vehicle*, ?);           /* extern */

s32 func_0013EC98(TheGame* arg0, ...) {
    Vehicle* temp_16;
    Vehicle** var_17;
    s32 var_18;
    s32 var_2;
    void* temp_4;

    var_2 = 0x98000;
    var_18 = 0;
    if (arg0->numAIs > 0) {
        var_17 = arg0->ais;
        do {
            temp_16 = *var_17;
            if ((temp_16->health > 0.0f) && (temp_16->kind != 0)) {
                hierSetCsDrawMe__FP3_csUc(temp_16->cs, 0);
                temp_4 = temp_16->drawCs;
                if (temp_4 != NULL) {
                    hierSetCsDrawMe__FP3_csUc(temp_4, 0);
                    shadow2ndOnOff__7Vehiclei(temp_16, 0);
                }
                if (temp_16->character == 0x100) {
                    hierSetCsDrawMe__FP3_csUc(temp_16->unk2038, 0);
                }
            }
            var_18 += 1;
            var_2 = var_18 < arg0->numAIs;
            var_17 += 4;
        } while (var_2 != 0);
    }
    return var_2;
}

/* ---- func_0013ED88 ---- */
? hierSetCsDrawMe__FP3_csUc(void*, ?);              /* extern */
? shadow2ndOnOff__7Vehiclei(Vehicle*, ?);           /* extern */

s32 func_0013ED88(TheGame* arg0, ...) {
    Vehicle* temp_16;
    Vehicle** var_17;
    s32 var_18;
    s32 var_2;
    void* temp_4;

    var_2 = 0x98000;
    var_18 = 0;
    if (arg0->numHumans > 0) {
        var_17 = arg0->humans;
        do {
            temp_16 = *var_17;
            if ((temp_16->health > 0.0f) && (temp_16->kind != 0)) {
                hierSetCsDrawMe__FP3_csUc(temp_16->cs, 0);
                temp_4 = temp_16->drawCs;
                if (temp_4 != NULL) {
                    hierSetCsDrawMe__FP3_csUc(temp_4, 0);
                    shadow2ndOnOff__7Vehiclei(temp_16, 0);
                }
                if (temp_16->character == 0x100) {
                    hierSetCsDrawMe__FP3_csUc(temp_16->unk2038, 0);
                }
            }
            var_18 += 1;
            var_2 = var_18 < arg0->numHumans;
            var_17 += 4;
        } while (var_2 != 0);
    }
    return var_2;
}

/* ---- gameCheckNewAIToHuntPlayer__7TheGamei ---- */
f32 func_0021F100(TheGame*, s32, u8*, Vehicle**, s32, s32, ?, ?); /* extern */

s32 gameCheckNewAIToHuntPlayer__7TheGamei(TheGame* arg0, Driver* arg1, s32 arg2, Vehicle** arg3, s32 arg4, s32 arg5, ...) {
    AIBrain* temp_3_3;
    AIBrain* temp_5;
    Driver* temp_20;
    Driver* temp_3_2;
    Driver* temp_4;
    Driver* var_5;
    TheGame* temp_19;
    TheGame* var_16;
    TheGame* var_17;
    TheGame* var_4;
    Vehicle* temp_3_4;
    Vehicle* var_2;
    Vehicle** var_7;
    f32 temp_f0;
    f32 temp_f2;
    f32 var_f1;
    f32 var_f3;
    f32 var_f5;
    s32 temp_3;
    s32 temp_3_5;
    s32 var_18;
    s32 var_6;
    s32 var_8;
    s32 var_9;
    s32 var_condition_bit;

    var_4 = arg0;
    var_5 = arg1;
    var_6 = arg2;
    var_7 = arg3;
    var_8 = arg4;
    var_9 = arg5;
    temp_19 = var_4;
    var_2 = temp_19 + 0x98000;
    temp_20 = var_5;
    var_16 = NULL;
    var_17 = NULL;
    var_f5 = 10000.0f;
    temp_3 = temp_19->numAIs;
    var_f3 = 10000.0f;
    if (temp_3 > 0) {
        var_7 = temp_19->ais;
        var_6 = temp_3;
        var_9 = 5;
        var_8 = 3;
        do {
            var_4 = (TheGame* ) *var_7;
            var_2 = (Vehicle* ) var_4->vehicles[0].netRemote;
            if (var_2 == NULL) {
                temp_3_2 = var_4->vehicles[0].driver;
                var_2 = (Vehicle* ) temp_3_2->mode;
                var_5 = temp_3_2;
                if ((var_2 == (Vehicle* )5) && (var_2 = var_5->target, (var_2->aiOrPlayerIdx == temp_20))) {
                    var_17 = var_4;
                    var_f5 = var_4->unk2090;
                } else {
                    temp_3_3 = var_4->vehicles[0].brain;
                    if (fabsf(temp_3_3->targetFacing) < 1.0471976f) {
                        var_f1 = temp_3_3->targetDist;
                        var_condition_bit = var_f1 < var_f3;
                        if (var_f1 < var_f3) {
                            var_2 = (Vehicle* ) var_5->mode;
                            if (var_2 == (Vehicle* )3) {
                                temp_f0 = (f32) temp_3_3->unk45C;
                                temp_f2 = temp_3_3->unk60;
                                if (temp_f0 < temp_f2) {
                                    var_f1 = (var_f1 + 20000.0f) - ((temp_f0 * 20000.0f) / temp_f2);
                                }
                                var_condition_bit = var_f1 < var_f3;
                            }
                            if (var_condition_bit) {
                                var_16 = var_4;
                                var_f3 = var_f1;
                            }
                        }
                    }
                }
            }
            var_6 -= 1;
            var_7 += 4;
        } while (var_6 != 0);
    }
    if (var_16 != NULL) {
        var_18 = 0;
        if (var_17 != NULL) {
            var_2 = (Vehicle* ) var_17->vehicles[0].brain;
            temp_3_4 = var_2;
            if (((fabsf(var_2->unk28) > 1.5707964f) || (temp_3_4->unk20 > 1000.0f)) && ((var_f3 < 1000.0f) || (temp_3_4->unk20 > 1000.0f))) {
                var_2 = (Vehicle* )1;
                if ((temp_3_4->unk24 > 1.5707964f) && (temp_3_4->unk4C < 3.0f)) {
                    var_2 = NULL;
                }
                if (var_2 != NULL) {
                    var_2 = (Vehicle* )0x90000;
                    if (var_f3 < (temp_3_4->unk20 * 3.0f)) {
                        var_4 = (TheGame* ) var_16->vehicles[0].driver->group;
                        var_5 = (Driver* ) temp_19->humanGroup[(s32) temp_20];
                        var_2 = (Vehicle* )0x30000;
                        if ((var_4 != var_5) && (var_6 = (s32) &temp_19->attractorPoints[8], temp_3_5 = *(var_6 + ((s32) var_4 * 4)), var_4 = (TheGame* ) &var_5->_pad0[temp_3_5], var_2 = (Vehicle* ) (var_4->vehicles[0]._pad110[0x30] & 1), (var_2 == NULL)) && (var_2 = (Vehicle* ) var_5->_pad0[temp_3_5].unkB0, (var_2 != (Vehicle* )-1))) {
                            var_2 = (Vehicle* ) ((s32) var_2 * 4);
                            if (var_f5 > 500.0f) {
                                var_2 = (Vehicle* ) ~var_5->_pad0[var_2->_pad0[var_6]].unkB0;
                                var_18 = var_2 == NULL;
                            }
                        } else {
                            goto block_31;
                        }
                    }
                }
            }
        } else {
block_31:
            var_18 = 1;
        }
        if (var_18 != 0) {
            if ((var_16 != NULL) && (var_17 != NULL) && (var_16->vehicles[0].brain != NULL) && (var_f5 < 1000.0f)) {
                temp_5 = var_16->vehicles[0].brain;
                if ((temp_5->aggression < func_0021F100(var_4, (s32) var_5, (u8* ) var_6, var_7, var_8, var_9, 0, 0x3F800000)) && ((temp_4 = var_16->vehicles[0].driver, (temp_4->mode != 3)) || ((temp_5->unk60 * 0.5f) < (f32) temp_5->unk45C))) {
                    var_18 = 0;
                    func_00130E88(temp_4, 3);
                    var_16->vehicles[0].brain->pickupMode = 0;
                    var_16->vehicles[0].brain->unk4C = 0.0f;
                    var_16->vehicles[0].brain->unk45C = 0;
                }
            }
            var_2 = (Vehicle* )0x90000;
            if (var_18 != 0) {
                temp_19->hunterOf[(s32) temp_20] = var_16->vehicles[0].aiOrPlayerIdx;
                func_00130E88(var_16->vehicles[0].driver, 5);
                var_16->vehicles[0].brain->pickupMode = 0;
                var_16->vehicles[0].brain->fleeHealth = 0.0f;
                var_2 = (Vehicle* ) var_16->vehicles[0].brain;
                var_2->prevPos.y = var_16->vehicles[0].health * var_2->prevPos.w;
                if (var_17 != NULL) {
                    func_00130E88(var_17->vehicles[0].driver, 4);
                    var_2 = (Vehicle* ) var_17->vehicles[0].brain;
                    var_2->unk5F4 = 0;
                    var_17->vehicles[0].brain->unk4C = 0.0f;
                }
            }
        }
    }
    return (s32) var_2;
}

/* ---- gameCheckStartPointDistFromVehicles__7TheGameP8_fvector ---- */
s32 gameCheckStartPointDistFromVehicles__7TheGameP8_fvector(TheGame* arg0, FVECTOR* arg1, ...) {
    FVECTOR* var_17;
    TheGame* var_16;
    s32 var_2;
    u8* temp_20;

    var_16 = arg0;
    temp_20 = var_16->_pad18D80;
    var_17 = &arg0->vehicles[0].pos;
loop_3:
    var_2 = 1;
    if ((s32) var_16 < (s32) temp_20) {
        if (var_16->vehicles[0].kind != 0) {
            var_17 += 0x31B0;
            if (mathfManhatDist__FP8_fvectorT0(arg1, var_17) < 100.0f) {
                var_2 = 0;
            } else {
                goto block_2;
            }
        } else {
            var_17 += 0x31B0;
block_2:
            var_16 += 0x31B0;
            goto loop_3;
        }
    }
    return var_2;
}

/* ---- gameCheckStartPoint__7TheGamePib ---- */
s32 attractGetRandomTransPoint__15AttractorPointsi(u8*, s32); /* extern */

void gameCheckStartPoint__7TheGamePib(TheGame* arg0, s32* arg1, s32 arg2, ...) {
    s32 var_18;
    s32 var_22;
    s32 var_3;
    u8* var_4;

    var_22 = 0;
    var_18 = 0;
loop_6:
    if (var_18 == 0) {
        if (arg2 != 0) {
            var_3 = arg0->unk34890;
        } else {
            var_3 = arg0->unk30970;
        }
        var_18 = gameCheckStartPointDistFromVehicles__7TheGameP8_fvector(arg0, var_3 + (*arg1 << 5));
        var_22 += 1;
        if ((var_18 != 0) || (var_22 >= 0xB)) {

        } else {
            var_4 = arg0->_pad34890;
            if (arg2 != 0) {

            } else {
                var_4 = arg0->attractorPoints;
            }
            *arg1 = attractGetRandomTransPoint__15AttractorPointsi(var_4, *arg1);
            goto loop_6;
        }
    }
}

/* ---- gameClearCruiseZone__7TheGameP7Vehiclei ---- */
void gameClearCruiseZone__7TheGameP7Vehiclei(TheGame* arg0, Vehicle* arg1, s32 arg2) {
    arg1->brain->cruiseZone = -1;
    *(&arg0->_pad9FDAC[8] + (arg2 * 4)) = 0;
}

/* ---- gameInitCamera__7TheGameii ---- */
? SetCameraToFollowVehicle__6CameraiP7VehicleP3_cs(u8*, Vehicle*, void*); /* extern */

s32 gameInitCamera__7TheGameii(TheGame* arg0, s32 arg1, s32 arg2, ...) {
    Vehicle* temp_17;

    temp_17 = &arg0->vehicles[arg2];
    (arg0 + 0x98000 + (arg1 * 4))->unk7CC4 = arg2;
    SetCameraToFollowVehicle__6CameraiP7VehicleP3_cs(arg0->camera, temp_17, temp_17->cs);
    ((arg1 * 0xA20) + arg0)->unk98134 = temp_17;
    return 0xA20;
}

/* ---- gameInitCruiseZones__7TheGame ---- */
s32 gameInitCruiseZones__7TheGame(TheGame* arg0, ...) {
    Vehicle** var_4;
    s32 var_2;
    s32 var_5;
    s32 var_5_2;
    u8* var_2_2;

    var_5 = 0x47;
    var_2_2 = &arg0->_pad9FDAC[0x124];
    do {
        *var_2_2 = 0;
        var_5 -= 1;
        var_2_2 -= 4;
    } while (var_5 >= 0);
    var_2 = 0x98000;
    var_5_2 = 0;
    if (arg0->numAIs > 0) {
        var_4 = arg0->ais;
        do {
            var_5_2 += 1;
            (*var_4)->brain->cruiseZone = -1;
            var_2 = var_5_2 < arg0->numAIs;
            var_4 += 4;
        } while (var_2 != 0);
    }
    return var_2;
}

/* ---- gameOpenAsylum__7TheGamei ---- */
s32 gameOpenAsylum__7TheGamei(TheGame* arg0, s32 arg1, ...) {
    s16 var_3;
    s8 var_2;
    s8 var_2_2;
    u8* temp_4;
    u8* temp_4_2;
    u8* temp_4_3;
    u8* temp_4_4;
    u8* temp_4_5;
    u8* temp_5;
    u8* temp_5_2;
    u8* temp_5_3;
    u8* temp_5_4;
    u8* temp_5_5;
    u8* temp_5_6;
    u8* temp_5_7;
    u8* temp_6;
    u8* var_5;

    temp_6 = &D_004FA030->_pad34890[0x28A0];
    temp_4 = D_004FA030->attractorPoints;
    if (arg1 != 0x1810) {
        var_2 = 0x180F;
        if (arg1 < 0x1811) {
            temp_4_2 = temp_4 + 0x2CA0;
            if (arg1 != 0x180F) {
                /* Duplicate return node #3. Try simplifying control flow for better match */
                return (s32) var_2;
            }
            temp_4_2->unk12 = 0x1E;
            temp_4_2->unk1E = 2;
            temp_5 = temp_6 + 0x3200;
            temp_5->unkB5 = 5;
            temp_5->unk2A = 0x152;
            temp_5_2 = temp_6 + 0x36B0;
            temp_5_2->unkB5 = 0x20;
            temp_5_2->unk2A = 0x7A;
            temp_5_3 = temp_6 + 0x3520;
            if (temp_5_3->unkB5 != 5) {
                temp_5_3->unkB5 = 0x20;
                temp_5_3->unk2A = 0x7C;
            }
            temp_5_4 = temp_6 + 0x960;
            var_2 = 0x23;
            if (temp_5_4->unkB5 != 5) {
                temp_5_4->unk2A = 0x7A;
                temp_5_4->unkB5 = 0x23;
                temp_5_2->unkB5 = 0x22;
                temp_5_2->unk2A = 0x7A;
                return 0x23;
            }
            /* Duplicate return node #3. Try simplifying control flow for better match */
            return (s32) var_2;
        }
        if (arg1 != 0x1811) {
            temp_4_3 = temp_4 + 0x600;
            if (arg1 != 0x1812) {
                return 0x1812;
            }
            temp_4_3->unk12 = 0x1E;
            temp_4_3->unk1E = 2;
            var_5 = temp_6 + 0x3520;
            var_3 = 0x1D;
            goto block_17;
        }
        temp_4_4 = temp_4 + 0x2D00;
        temp_4_4->unk12 = 0x1E;
        temp_4_4->unk1E = 2;
        var_5 = temp_6 + 0x3390;
        var_3 = 0x155;
block_17:
        var_2_2 = 5;
        /* Duplicate return node #18. Try simplifying control flow for better match */
        var_5->unkB5 = var_2_2;
        var_5->unk2A = var_3;
        return (s32) var_2_2;
    }
    temp_4_5 = temp_4 + 0x2300;
    temp_4_5->unk12 = 0x1E;
    temp_4_5->unk1E = 2;
    temp_5_5 = temp_6 + 0x960;
    temp_5_5->unkB5 = 5;
    temp_5_5->unk2A = 0x105;
    temp_5_6 = temp_6 + 0x3200;
    if (temp_5_6->unkB5 != 5) {
        temp_5_6->unkB5 = 0x23;
        temp_5_6->unk2A = 0x7A;
        temp_5_7 = temp_6 + 0x36B0;
        temp_5_7->unkB5 = 6;
        temp_5_7->unk2A = 0x7A;
    }
    var_5 = temp_6 + 0x3390;
    var_2 = var_5->unkB5;
    var_3 = 0x78;
    if (var_2 != 5) {
        var_2_2 = 6;
        var_5->unkB5 = var_2_2;
        var_5->unk2A = var_3;
        return (s32) var_2_2;
    }
    return (s32) var_2;
}

/* ---- gamePickCruiseZone__7TheGameP7Vehiclei ---- */
? attractGetCenterOfGroup__15AttractorPointsP8_fvectori(u8*, FVECTOR*, u8); /* extern */
f32 func_0021F100(Driver*, ?, ?);                   /* extern */

void gamePickCruiseZone__7TheGameP7Vehiclei(TheGame* arg0, Vehicle* arg1, s32 arg2) {
    s32 sp10;
    s32 sp14;
    void* sp18;
    AIBrain* temp_3;
    Driver* temp_4;
    Driver* temp_5;
    f32 temp_f0;
    f32 var_f20;
    s32 temp_19;
    s32 var_17;
    s32 var_17_2;
    s32 var_19;
    s32 var_condition_bit;
    u8 temp_16;
    u8 temp_16_2;
    u8 var_22;
    u8* var_4;
    void* temp_2;
    void* temp_2_2;

    sp10 = arg2;
    if (arg1->netRemote == 0) {
        if (arg1->kind == 2) {
            if (arg1 != NULL) {
                temp_4 = arg1->driver;
                if (temp_4 != NULL) {
                    if (temp_4->targetPos != NULL) {
                        temp_3 = arg1->brain;
                        if (temp_3->sniping == 0) {
                            if ((temp_3->unk408 != 0.0f) && (temp_4->mode == 4)) {
                                if ((func_0021F100(temp_4, 0, 0x3F800000) < arg1->brain->unk408) && (arg1->driver->nextPoint = func_0013EBC0(arg0), (arg1->driver->nextPoint != -1))) {
                                    arg1->brain->sniping = 1;
                                    arg1->brain->unk46C = 0;
                                    temp_5 = arg1->driver;
                                    temp_5->unk210 = (s32) (arg0->unk30970 + (temp_5->nextPoint << 5))->unk1D;
                                } else {
                                    goto block_12;
                                }
                            } else {
block_12:
                                var_22 = -1U;
                                var_f20 = 10000.0f;
                                sp14 = arg1->driver->target->aiOrPlayerIdx;
                                if (arg1->driver->mode == 3) {
                                    var_f20 = 0.0f;
                                }
                                temp_19 = arg1->brain->sortIndex * 2;
                                if (temp_19 < 2) {
                                    var_19 = 2;
                                } else {
                                    var_19 = (temp_19 >= 9) ? 8 : temp_19;
                                }
                                var_17 = 0;
                                if (var_19 > 0) {
                                    temp_2 = arg0 + 0x98000;
                                    sp18 = temp_2 + 0x7DB4;
loop_20:
                                    temp_16 = (&arg0->_pad34890[0x2A28])[(*(temp_2 + 0x7D40 + (sp14 * 4)) * 0x190) + var_17];
                                    if (*(sp18 + (temp_16 * 4)) != 0) {
                                        var_17 += 1;
                                    } else if (sp10 == 0) {
                                        if (temp_16 == arg1->brain->cruiseZone) {
                                            var_17 += 1;
                                        } else {
                                            goto block_27;
                                        }
                                    } else {
block_27:
                                        attractGetCenterOfGroup__15AttractorPointsP8_fvectori(arg0->attractorPoints, sp, temp_16);
                                        temp_f0 = mathfManhatDist__FP8_fvectorT0(sp, &arg1->pos);
                                        var_condition_bit = temp_f0 < var_f20;
                                        if (arg1->driver->mode == 3) {
                                            var_condition_bit = var_f20 < temp_f0;
                                        }
                                        var_17 += 1;
                                        if (var_condition_bit) {
                                            var_f20 = temp_f0;
                                            var_22 = temp_16;
                                        }
                                    }
                                    if (var_17 < var_19) {
                                        goto loop_20;
                                    }
                                }
                                if (var_22 == -1U) {
                                    temp_2_2 = arg0 + 0x98000;
                                    var_17_2 = 0;
                                    var_4 = ((temp_2_2 + (sp14 * 4))->unk7D40 * 0x190) + &arg0->_pad34890[0x2A28];
loop_36:
                                    temp_16_2 = *var_4;
                                    var_17_2 += 1;
                                    if (*(temp_2_2 + 0x7DB4 + (temp_16_2 * 4)) != 0) {
                                        var_4 += 1;
                                        if (var_17_2 < 8) {
                                            goto loop_36;
                                        }
                                    } else {
                                        var_22 = temp_16_2;
                                    }
                                    if ((var_22 != -1U) || (var_22 = (&arg0->_pad34890[0x2A28])[mathfRand__Fii(0, 7) + (arg0->humanGroup[sp14] * 0x190)], (var_22 != -1U))) {
                                        goto block_40;
                                    }
                                } else {
block_40:
                                    gameTakeCruiseZone__7TheGameP7Vehiclei(arg0, arg1, var_22);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

/* ---- gameSpawnBurningMan__7TheGameP7Vehicle ---- */
s32 Spawn__7BurnManP7Vehicle(void*, s32, ?, TheGame*); /* extern */

s32 gameSpawnBurningMan__7TheGameP7Vehicle(TheGame* arg0, ...) {
    s32 var_2;
    s32 var_6;

    var_6 = 0;
loop_1:
    var_2 = var_6 < 3;
    if (var_2 != 0) {
        if (((var_6 * 0x50) + arg0)->unk969E0 != 0) {
            var_6 += 1;
            goto loop_1;
        }
        var_2 = Spawn__7BurnManP7Vehicle(arg0 + ((var_6 * 0x50) + 0x969E0), var_6, 0x50, arg0);
    }
    return var_2;
}

/* ---- gameTakeCruiseZone__7TheGameP7Vehiclei ---- */
s32 aiGetBestPointToBeDrivingNow__7Vehicle(Vehicle*); /* extern */
s32 func_0010BB10(void*, void*, s32);               /* extern */

s32 gameTakeCruiseZone__7TheGameP7Vehiclei(TheGame* arg0, Vehicle* arg1, s32 arg2, ...) {
    AIBrain* temp_3;
    s32 var_2_2;
    u8* var_2;
    void* temp_16;

    temp_3 = arg1->brain;
    if (temp_3->cruiseZone != -1) {
        temp_3->cruiseZone = -1;
    }
    temp_16 = arg1 + 0x1D0;
    gameClearCruiseZone__7TheGameP7Vehiclei(arg0, arg1, arg2);
    *(&arg0->_pad9FDAC[8] + (arg2 * 4)) = 1;
    arg1->brain->cruiseZone = arg2;
    arg1->driver->nextPoint = func_0010BB10(arg1->driver->points, temp_16, arg1->brain->cruiseZone);
    arg1->driver->nextPoint = func_0010BB10(arg1->driver->points, temp_16, arg1->brain->cruiseZone);
    arg1->driver->unk210 = arg2;
    if (arg1->driver->mode == 4) {
        var_2_2 = 0x98000;
        if (arg1->velAlongHeading == 0.0f) {
            aiStartTurnToNewCruisePoint__7Vehicle(arg1);
            goto block_5;
        }
    } else {
block_5:
        var_2_2 = 0x98000;
    }
    var_2 = &arg0->vehicles[0]._pad0[var_2_2];
    if (var_2->unk23D4 > 0) {
        var_2 = aiGetBestPointToBeDrivingNow__7Vehicle(arg1);
    }
    return (s32) var_2;
}

/* ---- spawnBurningPed__7TheGameP7VehicleP8_fvector ---- */
s32 SpawnLoc__7BurnManP7VehicleP8_fvector(void*, s32, ?, TheGame*); /* extern */

s32 spawnBurningPed__7TheGameP7VehicleP8_fvector(TheGame* arg0, ...) {
    s32 var_2;
    s32 var_7;

    var_7 = 0;
loop_1:
    var_2 = var_7 < 3;
    if (var_2 != 0) {
        if (((var_7 * 0x50) + arg0)->unk969E0 != 0) {
            var_7 += 1;
            goto loop_1;
        }
        var_2 = SpawnLoc__7BurnManP7VehicleP8_fvector(arg0 + ((var_7 * 0x50) + 0x969E0), var_7, 0x50, arg0);
    }
    return var_2;
}

