/* m2c drafts of asm/nonmatchings/tmb/ai (online SCUS-97196) with the named structs of ../ai_decomp/ctx_types.h.
 * Not matching code: for reading. Regenerate: python3 run_m2c.py (paths inside). */

/* ---- aiCheckForBeadOnHuntCs__7Vehicle ---- */
s32 tireIsDrivableSlope__7VehicleP8_fvector(Vehicle*, ?*); /* extern */

s32 aiCheckForBeadOnHuntCs__7Vehicle(Vehicle* arg0, ...) {
    ? sp10;
    AIBrain* temp_4;
    Driver* temp_3;
    s32 var_2;

    temp_4 = arg0->brain;
    var_2 = temp_4->ramming;
    if (var_2 == 0) {
        var_2 = temp_4->unk5A8;
        if (var_2 == 0) {
            var_2 = arg0->unk1A64;
            if ((var_2 == 0) && (temp_4->targetDist < (2.0f * temp_4->range18))) {
                temp_3 = arg0->driver;
                if (temp_3->unk294 != 0) {
                    arg0->brain->unk5A8 = hdLosTest__FP8_fvectorT0P9_hdResulti(&arg0->pos, temp_3->targetPos, sp, 0) != 0;
                    if ((arg0->brain->unk5A8 == 0) && (tireIsDrivableSlope__7VehicleP8_fvector(arg0, &sp10) != 0)) {
                        arg0->brain->unk5A8 = 1;
                    }
                } else {
                    temp_4->unk5A8 = 1;
                }
                var_2 = 0x258;
                arg0->brain->unk42C = 0x258;
            }
        }
    }
    return var_2;
}

/* ---- aiCheckForPickup__7Vehicle ---- */
void* GetClosestPickup__7PickupsP8_fvectori(u8*, FVECTOR*, ?); /* extern */
f32 atan2f(f32, f32);                               /* extern */
s32 attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector(void*, void*); /* extern */
? boundFAngle__FPf(f32*);                           /* extern */

s32 aiCheckForPickup__7Vehicle(Vehicle* arg0, ...) {
    f32 sp0;
    f32 sp4;
    f32 sp8;
    f32 sp10;
    AIBrain* temp_3;
    s32 var_18;
    s32 var_4;
    void* temp_5;

    var_18 = 0;
    temp_3 = arg0->brain;
    var_4 = 0;
    if (temp_3->pickupMode != 0) {
        var_4 = 1;
    } else if (temp_3->sawTarget != 0) {
        var_4 = arg0->unk1A64 == 0;
    }
    if (var_4 != 0) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($s1) */);
        M2C_ERROR(/* unknown instruction: vsub.xyz $vf11, $vf11, $vf12 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf11, ($sp) */);
        sp0 *= 0.5f;
        sp4 *= 0.5f;
        sp8 *= 0.5f;
        M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($s1) */);
        M2C_ERROR(/* unknown instruction: vadd.xyz $vf11, $vf11, $vf12 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf11, ($sp) */);
        arg0->brain->targetCs = GetClosestPickup__7PickupsP8_fvectori(&D_004FA030->_pad34890[0x51AB0], sp, -1);
        temp_5 = arg0->brain->targetCs;
        if ((temp_5 != NULL) && (temp_5->unkC != 0) && (func_00104DF8(arg0, temp_5) != 0)) {
            M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($v0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($s1) */);
            M2C_ERROR(/* unknown instruction: vsub.xyz $vf11, $vf11, $vf12 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf11, ($sp) */);
            if (mathfManhatDist__FP8_fvectorT0(sp, NULL) < arg0->driver->dist4C) {
                sp10 = arg0->cs->unk68 - atan2f(sp0, sp4);
                boundFAngle__FPf(&sp10);
                if (fabsf(sp10) < 0.5235988f) {
                    var_18 = attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector(arg0->driver->points, arg0->brain->targetCs + 0x10) == arg0->driver->group;
                }
            }
        }
    }
    arg0->brain->unk5C4 = 1;
    return var_18;
}

/* ---- aiCheckShadowDetonation__7Vehicle ---- */
extern f32 D_004FAD74;

s32 aiCheckShadowDetonation__7Vehicle(Vehicle* arg0, ...) {
    AIBrain* temp_3;
    AIBrain* var_2;
    f32 temp_f2;
    f32 temp_ret;
    s32 temp_4_2;
    s32 var_3;
    void* temp_4;

    if ((arg0->unk2780 != 0) && (temp_4 = arg0->unk2784, (temp_4 != NULL)) && (temp_4_2 = temp_4->unk150, (temp_4_2 != 0))) {
        temp_ret = mathfManhatDist__FP8_fvectorT0(temp_4_2 + 0x10, &arg0->pos);
        var_2 = (bitwise AIBrain* ) temp_ret;
        if ((D_004FAD74 * 0.5f) < temp_ret) {
            temp_f2 = mathfManhatDist__FP8_fvectorT0(arg0->unk2784->unk150 + 0x10, arg0->driver->targetPos);
            if (arg0->unk2AC0 != 0.0f) {
                var_2 = arg0->brain;
                goto block_9;
            }
            var_2 = arg0->brain;
            if ((arg0->unk2AC4 != 0.0f) || (arg0->unk2AC8 != 0.0f)) {
block_9:
                temp_3 = var_2;
                if ((var_2->weapRange[0x98] < temp_f2) && (var_2 = (AIBrain* )1, (D_004FAD74 < temp_f2))) {
                    arg0->pad[0xF] = 1;
                    temp_3->specialActive = 0;
                    var_2 = arg0->brain;
                    var_2->specialTimer = 0;
                } else {
                    temp_3->weapRange[0x98] = temp_f2;
                }
            } else {
                var_3 = 0;
                if (fabsf(var_2->targetFacing) > 1.9198622f) {
                    if (var_2->weapRange[0x98] < temp_f2) {
                        var_3 = 1;
                    }
                } else if (temp_f2 < (D_004FAD74 * 0.5f)) {
                    var_3 = 1;
                } else if (var_2->weapRange[0x98] < temp_f2) {
                    var_3 = 1;
                } else {
                    var_2->weapRange[0x98] = temp_f2;
                }
                if (var_3 != 0) {
                    var_2 = arg0->brain;
                    arg0->pad[0xF] = 1;
                    goto block_26;
                }
            }
        }
    } else {
        var_2 = arg0->brain;
block_26:
        var_2->specialActive = 0;
        arg0->brain->specialTimer = 0;
    }
    return (s32) var_2;
}

/* ---- aiCheckSkillAttack__7Vehicle ---- */
f32 func_0021F100(?, ?);                            /* extern */

s32 aiCheckSkillAttack__7Vehicle(Vehicle* arg0, ...) {
    AIBrain* temp_3_2;
    AIBrain* temp_5;
    f32 var_f0;
    f32 var_f1;
    f32 var_f2;
    s32 temp_3;
    s32 temp_6;
    s32 var_17;
    s32 var_2;
    s32 var_condition_bit;

    temp_3 = arg0->weapSlot[5];
    var_17 = 0;
    if (temp_3 != 0xC) {
        var_2 = 0xB;
        if (temp_3 < 0xD) {
            if (temp_3 != 0xB) {

            } else {
                if (arg0->ammo[0x24] != 0) {
                    if (arg0->ammo[0x25] >= 0xA) {
                        if ((arg0->ammo[0x26] != 0) && ((temp_5 = arg0->brain, temp_6 = temp_5->unk5F8, (temp_6 == 0)) || (temp_5->targetDist < 200.0f)) && (arg0->ammo[0x28] < (arg0->ammo[0x27] * 5))) {
                            var_f2 = 70.0f;
                            if (arg0->driver->target->throttle > 1.0f) {
                                var_f2 = 200.0f;
                            }
                            if (temp_5->targetDist < var_f2) {
                                var_f1 = 2.617994f;
                                var_f0 = fabsf(temp_5->targetFacing);
                                goto block_31;
                            }
                            if (temp_6 == 0) {
                                var_condition_bit = fabsf(temp_5->targetFacing) > 0.34906587f;
                                goto block_32;
                            }
                        }
                    } else {
                        goto block_33;
                    }
                } else {
                    temp_3_2 = arg0->brain;
                    if (temp_3_2->specialTimer < 0x12D) {
                        if ((arg0->pad[0xF] == 0) && (arg0->unk5B5 == 0)) {
                            arg0->pad[0xF] = 1;
                        }
                    } else {
                        temp_3_2->specialActive = 0;
                    }
                }
                goto block_34;
            }
        } else {
            var_2 = 0xD;
            if (temp_3 != 0xD) {

            } else {
                var_2 = arg0->ammo[0x34];
                if (var_2 == 0) {
                    var_2 = (s32) arg0->brain;
                    var_2->unk604 = 0;
                }
            }
        }
    } else {
        if (arg0->ammo[0x2E] != 0) {
            if ((arg0->brain->specialTimer >= 0x3D) && (mathfManhatDist__FP8_fvectorT0((FVECTOR* ) &arg0->ammo[0x2A], arg0->driver->targetPos) < 65.0f)) {
                var_f0 = func_0021F100(0, 0x3F800000);
                var_f1 = arg0->brain->fairness * 0.5f;
block_31:
                var_condition_bit = var_f0 < var_f1;
block_32:
                if (var_condition_bit) {
                    goto block_33;
                }
            }
        } else {
block_33:
            var_17 = 1;
        }
block_34:
        var_2 = 1;
        if (var_17 != 0) {
            arg0->pad[0xF] = 1;
            arg0->brain->specialActive = 0;
        }
    }
    return var_2;
}

/* ---- aiCheckSpecialWeaponFiring__7Vehicle ---- */
s32 aiCheckSpecialWeaponFiring__7Vehicle(Vehicle* arg0, ...) {
    AIBrain* temp_2;
    AIBrain* temp_3_2;
    AIBrain* temp_4_2;
    f32 temp_f1;
    f32 temp_f2;
    s32 temp_3;
    s32 temp_3_3;
    s32 temp_4;
    s32 var_2;
    s32 var_condition_bit;

    temp_3 = arg0->character;
    switch (temp_3) {                               /* irregular */
    case 0x1A0:
        if ((arg0->unk242C == 0) && (arg0->unk17D8 >= 0x79)) {
        default:
block_36:
            arg0->brain->specialActive = 0;
        }
        break;
    case 0x20:
        if (arg0->brain->tasActive == 0) {
            aiInitTurnAndShoot__7Vehicleii(arg0, 0x78, 1);
        }
        arg0->specialHold = 1;
        arg0->pad[0xF] = 1;
        arg0->brain->tasDuration = 0xA;
        arg0->brain->tasWeapon = 1;
        temp_4 = arg0->unk2280;
        if ((arg0->unk2284 - 0xA) >= temp_4) {
            if (temp_4 < 0x65) {
                temp_3_2 = arg0->brain;
                temp_f1 = temp_3_2->specialAngle;
                if ((fabsf(temp_3_2->targetBearing) < temp_f1) && (temp_3_2->unk5F8 == 0) && (temp_4 >= 0x33)) {
                    temp_f2 = fabsf(temp_3_2->targetFacing);
                    if (temp_f2 < temp_f1) {
                        var_condition_bit = (temp_f1 * 0.5f) < temp_f2;
                        goto block_21;
                    }
                }
            } else {
                temp_2 = arg0->brain;
                var_condition_bit = fabsf(temp_2->targetFacing) < temp_2->specialAngle;
block_21:
                if (var_condition_bit) {
                    goto block_22;
                }
            }
        } else {
block_22:
            arg0->pad[0xF] = 0;
        }
        if (arg0->pad[0xF] == 0) {
            arg0->brain->specialActive = 0;
            arg0->specialHold = 0;
            arg0->brain->tasWeapon = 0;
            temp_4_2 = arg0->brain;
            temp_3_3 = (s32) temp_4_2->specialInterval >> 1;
            if (temp_3_3 < temp_4_2->specialTimer) {
                temp_4_2->specialTimer = temp_3_3;
            }
        }
        break;
    case 0xA0:
        if (mathfRand__Fii(0, 0x2A) == 7) {
            arg0->pad[0xF] = 1;
        }
        break;
    case 0xC0:
        if (arg0->brain->tasActive == 0) {
            aiInitTurnAndShoot__7Vehicleii(arg0, 0x78, 2);
        }
        goto block_36;
    }
    var_2 = arg0->specialHold;
    if (var_2 <= 0) {
        var_2 = (s32) arg0->brain;
        var_2->unk604 = 0;
    }
    return var_2;
}

/* ---- aiCheckSpeed__7Vehiclef ---- */
s32 aiCheckSpeed__7Vehiclef(Vehicle* arg0, f32 fparg0, ...) {
    Driver* temp_3;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 var_f1;
    s32 var_17;
    s32 var_18;
    s32 var_condition_bit;
    s8 var_2;

    var_18 = 0;
    var_17 = 0;
    temp_f1 = arg0->driver->unk1A0;
    if (temp_f1 != 0.0f) {
        temp_f2 = arg0->velAlongHeading;
        var_2 = 1;
        if (temp_f2 < (temp_f1 * 0.995f)) {
            arg0->pad[7] = 1;
            goto block_48;
        }
        if ((temp_f1 * 1.05f) < temp_f2) {
            arg0->pad[8] = 1;
        }
        goto block_50;
    }
    if ((aiNeedToSlowDown__7VehiclefPf(arg0, sp, fparg0) != 0) || ((arg0->_pad5A8[6] != 0) && (arg0->brain->ramming == 0) && !(arg0->throttle < arg0->driver->minSpeed) && (fparg0 < sp0))) {
        var_18 = 1;
    }
    if (var_18 == 0) {
        temp_3 = arg0->driver;
        if (temp_3->unk1A0 == 0.0f) {
            if (temp_3->unk27C == 0) {
                if (temp_3->unk278 == 0) {
                    goto block_19;
                }
                goto block_17;
            }
block_17:
            if (((fparg0 - sp0) / arg0->velAlongHeading) < 60.0f) {
                var_f1 = arg0->unk36C;
                var_condition_bit = var_f1 < temp_3->speedLimit;
            } else {
block_19:
                var_f1 = arg0->cruiseSpeed;
                var_condition_bit = temp_3->speedLimit < var_f1;
            }
            if (var_condition_bit) {
                temp_3->speedLimit = var_f1;
            }
        }
        temp_f1_2 = arg0->driver->speedLimit;
        temp_f2_2 = arg0->velAlongHeading;
        if (temp_f2_2 < (temp_f1_2 * 0.98f)) {
            var_17 = 1;
        } else if (arg0->_pad5A8[2] != 0) {
            if (!(temp_f2_2 < (temp_f1_2 * 1.1f))) {
                if (arg0->_pad5A8[5] != 0) {
                    var_17 = arg0->brain->unk48C < 0x78;
                }
            } else {
                var_17 = 1;
            }
        }
    }
    var_2 = (s8) arg0->_pad48A[5];
    if (var_2 != 0) {
        var_2 = 1;
        if (arg0->brain->unk5BC != 0) {
            arg0->pad[7] = 1;
            goto block_49;
        }
    }
    if (var_17 != 0) {
        if (aiGoingTooFast__7Vehicle(arg0) == 0) {
            arg0->pad[4] = 1;
        }
        if (arg0->brain->slowDown != 0) {
            arg0->pad[7] = 1;
        }
        var_2 = (s8) arg0->pad[7];
        if (var_2 != 0) {
            if ((arg0->unk34C * 0.25f) < fabsf(arg0->steer)) {
                arg0->pad[4] = 0;
                arg0->pad[7] = 0;
                return (s32) var_2;
            }
            /* Duplicate return node #51. Try simplifying control flow for better match */
            return (s32) var_2;
        }
        goto block_50;
    }
    if (var_18 != 0) {
        var_2 = (s8) arg0->brain;
        if (var_2->unk5B0 == 0) {
            temp_f1_3 = arg0->driver->minSpeed;
            temp_f2_3 = arg0->throttle;
            var_2 = 1;
            if ((temp_f1_3 * 1.1f) < temp_f2_3) {
                arg0->pad[8] = 1;
                return 1;
            }
            if (temp_f2_3 < (temp_f1_3 * 0.98f)) {
block_48:
                arg0->pad[4] = 1;
block_49:
            }
            goto block_50;
        }
        /* Duplicate return node #51. Try simplifying control flow for better match */
        return (s32) var_2;
    }
block_50:
    return (s32) var_2;
}

/* ---- aiDriveToAttackRange__7Vehicle ---- */
? boundFAngle__FPf(f32*);                           /* extern */
? func_0021D258(FMATRIX*, s32, void*);              /* extern */

s32 aiDriveToAttackRange__7Vehicle(Vehicle* arg0, ...) {
    f32 sp10;
    f32 temp_f1;
    f32 temp_f20;
    f32 var_f2;
    s32 temp_3;

    sp10 = arg0->cs->unk68 - arg0->brain->targetBearing;
    boundFAngle__FPf(&sp10);
    if (arg0->character != 0x40) {
        goto block_7;
    }
    temp_3 = arg0->unk21B0;
    if (temp_3 != 1) {
block_7:
        if ((arg0->brain->unk5B8 == 0) || !(fabsf(sp10) < 0.5235988f)) {
            if (arg0->unk21B0 == 5) {
                var_f2 = 400.0f;
                if (arg0->weapSlot[5] == 0xB) {

                } else {
                    goto block_13;
                }
            } else {
block_13:
                var_f2 = 70.0f;
                temp_f1 = (arg0->brain + (arg0->brain->weapon * 4))->unk208;
                if (temp_f1 > 70.0f) {
                    var_f2 = temp_f1 + 40.0f;
                }
            }
            temp_f20 = arg0->brain->targetDist - (var_f2 + (arg0->unk2DC * arg0->driver->unk1B4));
            func_0021D258(&arg0->rot, arg0->driver->target + 0x1F0, sp);
            if ((temp_f20 + (sp4 * 50.0f)) > 0.0f) {
                goto block_16;
            }
            arg0->pad[8] = 1;
            return 1;
        }
block_16:
        arg0->pad[4] = 1;
        return 1;
    }
    arg0->pad[4] = (u8) temp_3;
    return 1;
}

/* ---- aiGetFleeSpot__7Vehiclei ---- */
s32 aiGetFleeSpot__7Vehiclei(Vehicle* arg0, s32 arg1, ...) {
    Driver* temp_5;
    s32 temp_2;

    gamePickCruiseZone__7TheGameP7Vehiclei(D_004FA030, arg0, arg1);
    temp_5 = arg0->driver;
    temp_2 = temp_5->nextPoint << 5;
    temp_5->unk210 = (s32) (*temp_5->points + temp_2)->unk1D;
    return temp_2;
}

/* ---- aiGetWeapRangeInfo__7VehicleiPfT2T2T2 ---- */
s32 aiGetWeapRangeInfo__7VehicleiPfT2T2T2(Vehicle* arg0, s32 arg1, f32* arg2, f32* arg3, f32* arg4, f32* arg5, ...) {
    AIBrain* temp_2;
    f32 var_f0;
    f32 var_f2;
    s32 temp_3;
    s32 temp_4;
    void* var_2;

    temp_3 = arg1 * 4;
    *arg2 = arg0->brain->weapRange[arg1];
    *arg3 = (arg0->brain + temp_3)->unk208;
    *arg4 = arg0->brain->weapMaxBearing[arg1];
    temp_2 = arg0->brain;
    var_2 = temp_2 + temp_3;
    *arg5 = temp_2->weapMaxPitch[arg1];
    if (arg1 == 5) {
        temp_4 = arg0->weapSlot[5];
        var_2 = (void* ) (temp_4 < 0xD);
        if (temp_4 != 0xC) {
            var_2 = (void* )0xB;
            if (var_2 != NULL) {
                if (temp_4 != 0xB) {
                    /* Duplicate return node #4. Try simplifying control flow for better match */
                    return (s32) var_2;
                }
                *arg2 = 700.0f;
                var_f2 = 0.34906587f;
                var_f0 = 0.69813174f;
                *arg3 = 100.0f;
                /* Duplicate return node #10. Try simplifying control flow for better match */
                *arg4 = var_f2;
                *arg5 = var_f0;
                return (s32) var_2;
            }
            var_2 = (void* )0xD;
            if (temp_4 != 0xD) {
                return 0xD;
            }
            *arg2 = 300.0f;
            var_f2 = 0.17453294f;
            *arg3 = 50.0f;
            var_f0 = 0.34906587f;
            /* Duplicate return node #10. Try simplifying control flow for better match */
            *arg4 = var_f2;
            *arg5 = var_f0;
            return (s32) var_2;
        }
        *arg2 = 400.0f;
        var_f2 = 0.5235988f;
        var_f0 = 1.0471976f;
        *arg3 = 50.0f;
        *arg4 = var_f2;
        *arg5 = var_f0;
        return (s32) var_2;
    }
    return (s32) var_2;
}

/* ---- aiGoingTooFast__7Vehicle ---- */
s32 aiGoingTooFast__7Vehicle(Vehicle* arg0, ...) {
    return 0;
}

/* ---- aiGoodRearWeaponToPick__7Vehiclei ---- */
s32 aiGoodRearWeaponToPick__7Vehiclei(Vehicle* arg0, s32 arg1, ...) {
    AIBrain* temp_3;
    f32 temp_f2;
    s32 var_4;
    void* temp_2;

    temp_3 = arg0->brain;
    temp_2 = temp_3 + (arg1 * 4);
    temp_f2 = temp_2->unk3AC;
    var_4 = 0;
    if ((temp_f2 != 0.0f) && (((f32) temp_2->unk54C / (f32) temp_3->unk548) < temp_f2)) {
        var_4 = 1;
    }
    return var_4;
}

/* ---- aiGoodWeaponToPick__7Vehiclei ---- */
s32 aiGoodWeaponToPick__7Vehiclei(Vehicle* arg0, s32 arg1, ...) {
    AIBrain* temp_3;
    f32 temp_f2;
    s32 var_4;
    void* temp_2;

    temp_3 = arg0->brain;
    temp_2 = temp_3 + (arg1 * 4);
    temp_f2 = temp_2->unk320;
    var_4 = 0;
    if ((temp_f2 != 0.0f) && (((f32) temp_2->unk4BC / (f32) temp_3->unk4B8) < temp_f2)) {
        var_4 = 1;
    }
    return var_4;
}

/* ---- aiHuntUsingLOS__7Vehicle ---- */
f32 atan2f(Driver*, u8*, Driver*, u8*, f32, f32);   /* extern */
? boundFAngle__FPf(f32*);                           /* extern */

s32 aiHuntUsingLOS__7Vehicle(Vehicle* arg0, ...) {
    f32 sp4;
    f32 sp8;
    f32 sp10;
    f32 sp14;
    AIBrain* temp_3_2;
    Driver* temp_2;
    Driver* temp_2_3;
    Driver* temp_2_4;
    Driver* temp_6;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 var_f0;
    s32 temp_2_2;
    s32 temp_3;
    s32 temp_3_3;
    s32 temp_3_4;
    u8* var_5;
    u8* var_7;
    void* temp_5;

    temp_2 = arg0->driver;
    temp_2->unk16C = (void* ) (temp_2->targetCs + 0x10);
    driverCheckDrivingLOS__6Driver(arg0->driver);
    temp_6 = arg0->driver;
    if (temp_6->unk23C != 0) {
        temp_5 = arg0->cs;
        sp10 = temp_5->unk68;
        if (temp_6->unk298 == 0) {
            temp_3 = temp_6->unk23C;
            if (temp_3 < 4) {
                goto block_11;
            }
            if ((temp_3 == 4) || (temp_3 == 8) || (var_7 = NULL, (temp_3 == 0xC))) {
                var_f0 = arg0->cs->unk68;
                goto block_16;
            }
            var_5 = NULL;
            if (temp_3 & 1) {
                var_7 = &temp_6->_padBC[4];
                if (temp_3 & 2) {
                    var_5 = &temp_6->_padBC[0x14];
                } else if (temp_3 & 4) {
                    var_5 = &temp_6->_padBC[0x24];
                } else {
                    goto block_27;
                }
            } else {
                temp_2_2 = temp_3 & 4;
                if (temp_3 & 2) {
                    var_7 = &temp_6->_padBC[0x14];
                    if (temp_2_2 != 0) {
                        var_5 = &temp_6->_padBC[0x24];
                    } else {
block_27:
                        var_5 = !(temp_3 & 8) ? NULL : &temp_6->_padBC[0x34];
                    }
                } else if (temp_2_2 != 0) {
                    var_5 = !(temp_3 & 8) ? NULL : &temp_6->_padBC[0x34];
                    var_7 = &temp_6->_padBC[0x24];
                }
            }
            if ((var_7 != NULL) && (var_5 != NULL)) {
                M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($a1) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($a3) */);
                M2C_ERROR(/* unknown instruction: vsub.xyz $vf11, $vf11, $vf12 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf11, ($sp) */);
                if (sp4 == 0.0f) {
                    sp4 = 0.01f;
                }
                temp_f0 = atan2f(temp_6, var_5, temp_6, var_7, sp0, sp4);
                sp10 = temp_f0;
                sp8 = temp_f0 - arg0->cs->unk68;
                boundFAngle__FPf(&sp8);
                if (fabsf(sp8) > 1.5707964f) {
                    sp10 -= 3.1415927f;
                    boundFAngle__FPf(&sp10);
                }
            }
        } else {
            var_f0 = temp_5->unk68;
            if (temp_6->unk29C == 0) {
block_16:
                sp10 = var_f0 - 0.17453294f;
            } else {
block_11:
                sp10 = temp_5->unk68 + 0.17453294f;
            }
        }
    } else {
        sp10 = arg0->cs->unk68 + arg0->brain->targetBearing;
        boundFAngle__FPf(&sp10);
    }
    func_00130D68(arg0->driver, sp10);
    sp14 = arg0->cs->unk68 - sp10;
    boundFAngle__FPf(&sp14);
    temp_f0_2 = fabsf(sp14);
    if (!(temp_f0_2 > 1.5707964f)) {
        temp_f1 = arg0->cruiseSpeed;
        arg0->driver->speedLimit = temp_f1 - ((temp_f1 * temp_f0_2) / 1.5707964f);
        temp_2_3 = arg0->driver;
        if (temp_2_3->speedLimit < 1.1733333f) {
            temp_2_3->speedLimit = 1.1733333f;
        }
    } else {
        arg0->driver->speedLimit = 1.1733333f;
    }
    temp_2_4 = arg0->driver;
    temp_2_4->minSpeed = temp_2_4->speedLimit;
    temp_3_2 = arg0->brain;
    if ((temp_3_2->specialActive != 0) && ((temp_3_3 = temp_3_2->weapon, (temp_3_3 == 5)) || ((temp_3_3 == 1) && ((temp_3_4 = arg0->character, (temp_3_4 == 0xC0)) || (temp_3_4 == 0x1A0))))) {
        return func_00103888(arg0);
    }
    return aiCheckSpeed__7Vehiclef(arg0, 0x447A0000);
}

/* ---- aiInWeaponRange__7Vehiclei ---- */
s32 aiInWeaponRange__7Vehiclei(Vehicle* arg0, s32 arg1, ...) {
    s32 temp_3;
    s32 var_7;

    var_7 = 0;
    if (arg0->brain->noLosTicks < 0xA) {
        temp_3 = D_004FA030->levelType;
        if ((temp_3 != 4) && (temp_3 != 8)) {
            goto block_4;
        }
        goto block_5;
    }
block_4:
    if (arg0->brain->targetDist < (arg0->brain + (arg1 * 4))->unk17C) {
block_5:
        var_7 = 1;
    }
    return var_7;
}

/* ---- aiInitTurnAndShoot__7Vehicleii ---- */
s32 aiInitTurnAndShoot__7Vehicleii(Vehicle* arg0, s32 arg1, s32 arg2, ...) {
    if (arg0->driver->unk1A0 == 0.0f) {
        arg0->brain->tasActive = 1;
        arg0->brain->unk5D0 = 0;
        arg0->brain->tasDuration = arg1;
        arg0->brain->tasWeapon = arg2;
        arg0->brain->tasTicks = 0;
        arg0->driver->turning = 0;
        arg0->driver->following = 0;
        arg0->driver->performing = 1;
    }
    return (s32) arg0->driver;
}

/* ---- aiInit__7Vehicle ---- */
? func_001D6F78();                                  /* extern */

s32 aiInit__7Vehicle(Vehicle* arg0, ...) {
    AIBrain* temp_2;
    AIBrain* temp_6;
    Driver* temp_4;

    arg0->kind = 2;
    arg0->unk2180 = 0;
    func_001D6F78();
    if ((D_004FA030->difficulty == 2) && (D_004FA030->levelType != 0xC)) {
        arg0->turboDrain *= 1.25f;
    }
    arg0->health = arg0->turboDrain;
    arg0->driver->unk1F0 = 0;
    arg0->driver->points = D_004FA030->attractorPoints;
    temp_4 = arg0->driver;
    func_0012E2E0(temp_4, arg0, temp_4->points, 0);
    arg0->brain->cruiseZone = -1;
    func_001002C0(arg0, 0);
    arg0->brain->unk14 = &D_004FA030->_pad34890[0x62240];
    aiSetAggressiveness__7Vehiclei(arg0, D_004FA030->unk9FD60, D_004FA030 + 0x98000);
    func_00100E88(arg0);
    arg0->prevPos2 = (s128) arg0->pos;
    arg0->prevPos = arg0->unkD0;
    arg0->unk60 = (s128) arg0->unkE0;
    arg0->unk70 = (s128) arg0->unkF0;
    arg0->unk80 = (s128) arg0->unk100;
    temp_6 = arg0->brain;
    temp_6->targetDist = 10000.0f;
    arg0->brain->weapon = 0;
    arg0->brain->unk480 = 0;
    aiSetAttackState__7Vehicle12_attackState(arg0, 0, temp_6);
    arg0->brain->unk594 = 0;
    arg0->brain->seesTarget = 0;
    arg0->brain->sawTarget = 0;
    arg0->brain->aimed = 0;
    arg0->brain->unk5A8 = 0;
    arg0->brain->okToAttack = 0;
    arg0->brain->tasActive = 0;
    arg0->brain->fire = 0;
    temp_2 = arg0->brain;
    temp_2->unk61C = 0;
    arg0->brain->unk620 = -1;
    return (s32) temp_2;
}

/* ---- aiIsGoodWeaponChoice__7Vehiclei ---- */
s32 aiIsGoodWeaponChoice__7Vehiclei(Vehicle* arg0, s32 arg1, ...) {
    f32 sp4;
    f32 sp8;
    f32 spC;
    AIBrain* temp_2;
    f32 temp_f1;
    s32 var_18;
    s32 var_2;

    var_18 = 0;
    if (((arg0->brain + (arg1 * 4))->unk320 != 0.0f) && (aiGetWeapRangeInfo__7VehicleiPfT2T2T2(arg0, sp, &sp4, &sp8, &spC), temp_2 = arg0->brain, temp_f1 = temp_2->targetDist, (temp_f1 < sp0)) && (sp4 < temp_f1)) {
        if (!(fabsf(temp_2->targetBearing) < sp8) || !(fabsf(temp_2->targetPitch) < spC)) {
            if (aiOkToUseWeaponForRearFiring__7Vehiclei(arg0, arg1) != 0) {
                var_2 = 0;
                if ((3.1415927f - sp8) < fabsf(arg0->brain->targetBearing)) {
                    goto block_7;
                }
            } else {
                goto block_8;
            }
        } else {
block_7:
            var_18 = 1;
            goto block_8;
        }
    } else {
block_8:
        var_2 = var_18;
    }
    return var_2;
}

/* ---- aiIsPlayerLookingAtAIEnoughForAIToShoot__7Vehicle ---- */
f32 func_0021F100(Vehicle*, Vehicle*, AIBrain*, ?, ?); /* extern */

s32 aiIsPlayerLookingAtAIEnoughForAIToShoot__7Vehicle(Vehicle* arg0, ...) {
    AIBrain* temp_3;
    Vehicle* temp_16;
    Vehicle* temp_5;
    Vehicle* var_4;
    f32 temp_f1;
    f32 var_f2;
    s32 temp_3_2;
    s32 var_17;
    s32 var_2;

    var_4 = arg0;
    var_f2 = 3.1415927f;
    temp_16 = var_4;
    temp_5 = temp_16->driver->target;
    var_17 = 1;
    if (temp_5 != NULL) {
        temp_3 = temp_16->brain;
        if (((temp_3->noLosTicks >= 0xA) || ((var_4 = (Vehicle* )4, temp_3_2 = D_004FA030->levelType, (temp_3_2 != 4)) && (temp_3_2 != 8))) && !(temp_3->fairness > 0.89f)) {
            if ((temp_5->idleTicks >= 0x709) || (D_004FA030->progressMax > 0.67f) || ((temp_5->unk497 != 0) && (temp_5->unk464 < 0x2D)) || (temp_f1 = temp_16->brain->fairness, (func_0021F100(var_4, temp_5, temp_3, 0, 0x3F800000) < temp_f1))) {
                var_f2 = 3.1415927f;
            } else {
                var_f2 = temp_f1 * 3.1415927f;
            }
        }
        if (!(fabsf(temp_16->brain->targetFacing) < var_f2)) {
            var_17 = 0;
            goto block_18;
        }
        if (temp_16->onGround != 0) {
            var_2 = 1;
            if (temp_16->character == 0x1A0) {
                var_17 = ((temp_16->brain->weapon ^ 1) == 0) ? 0 : 1;
                goto block_18;
            }
        } else {
            goto block_18;
        }
    } else {
block_18:
        var_2 = var_17;
    }
    return var_2;
}

/* ---- aiLineUpShot__7Vehicle ---- */
? boundFAngle__FPf(f32*);                           /* extern */

s32 aiLineUpShot__7Vehicle(Vehicle* arg0, ...) {
    f32 sp0;
    f32 sp4;
    AIBrain* temp_2;
    AIBrain* temp_3;
    AIBrain* temp_3_2;
    AIBrain* temp_4;
    AIBrain* temp_5;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f12;
    f32 temp_f13;
    f32 temp_f1;
    s32 temp_2_2;
    s32 temp_5_2;
    s32 var_2;

    if (arg0->driver->mode != 3) {
        if ((arg0->brain->aimed != 0) || (var_2 = aiUsingNonLOSWeapon__7Vehicle(arg0), (var_2 != 0))) {
            if (arg0->brain->tasActive == 0) {
                if (aiIsPlayerLookingAtAIEnoughForAIToShoot__7Vehicle(arg0) == 0) {
                    temp_3 = arg0->brain;
                    if (temp_3->tasActive == 0) {
                        var_2 = temp_3->specialTimer < 0x12D;
                        if (var_2 == 0) {
                            goto block_28;
                        }
                    } else {
block_28:
                        var_2 = aiSetAttackState__7Vehicle12_attackState(arg0, 1);
                    }
                    /* Duplicate return node #30. Try simplifying control flow for better match */
                    return var_2;
                }
                temp_5 = arg0->brain;
                if (temp_5->tasActive == 0) {
                    if (arg0->driver->mode != 5) {
                        if (temp_5->unk614 == 0) {
                            goto block_19;
                        }
                    } else {
block_19:
                        aiInitTurnAndShoot__7Vehicleii(arg0, 0x78, 1);
                    }
                }
                goto block_20;
            }
block_20:
            temp_4 = arg0->brain;
            temp_f12 = fabsf(temp_4->targetBearing);
            sp0 = temp_f12;
            temp_f13 = fabsf(temp_4->targetPitch);
            sp4 = temp_f13;
            temp_2_2 = temp_4->weapon;
            temp_5_2 = temp_2_2 * 4;
            var_2 = (s32) (temp_4 + temp_5_2);
            if (temp_f12 < temp_4->weapMaxBearing[temp_2_2]) {
                if ((temp_f13 < var_2->unkF0) && (temp_4->targetDist < var_2->unk17C)) {
                    var_2 = func_00106D50(arg0, temp_5_2, temp_f12, temp_f13);
                    if (var_2 != 0) {
                        temp_2 = arg0->brain;
                        temp_2->fire = 0;
                        return (s32) temp_2;
                    }
                }
                /* Duplicate return node #30. Try simplifying control flow for better match */
                return var_2;
            }
            goto block_29;
        }
        /* Duplicate return node #30. Try simplifying control flow for better match */
        return var_2;
    }
    temp_3_2 = arg0->brain;
    if (temp_3_2->unk480 != 0) {
        temp_f0 = temp_3_2->targetBearing + 3.1415927f;
        sp0 = temp_f0;
        boundFAngle__FPf(sp);
        sp0 = fabsf(temp_f0);
        temp_f1 = arg0->cs->unk60;
        sp4 = -(arg0->brain->targetPitch + temp_f1) - temp_f1;
        boundFAngle__FPf(&sp4);
        temp_f0_2 = fabsf(sp4);
        sp4 = temp_f0_2;
        var_2 = 1;
        if (func_00107048(arg0, sp0, temp_f0_2) != 0) {
            arg0->brain->fire = 1;
        }
    } else {
        var_2 = aiSetAttackState__7Vehicle12_attackState(arg0, 1);
    }
block_29:
    return var_2;
}

/* ---- aiLockingOnHuntCs__7Vehicle ---- */
s32 aiLockingOnHuntCs__7Vehicle(Vehicle* arg0, ...) {
    return 0;
}

/* ---- aiLoseBeads__7Vehicle ---- */
s32 aiLoseBeads__7Vehicle(Vehicle* arg0, ...) {
    s32 var_2;

    arg0->brain->unk5A8 = 0;
    var_2 = arg0->brain->ramming;
    if (var_2 != 0) {
        var_2 = (s32) arg0->driver;
        var_2->unk258 = 0;
        arg0->brain->ramming = 0;
    }
    return var_2;
}

/* ---- aiNeedToSlowDown__7VehiclefPf ---- */
s32 aiNeedToSlowDown__7VehiclefPf(Vehicle* arg0, f32* arg1, f32 fparg0, ...) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f4;
    s32 var_3;

    var_3 = 0;
    temp_f1 = arg0->velAlongHeading;
    temp_f4 = arg0->driver->minSpeed;
    temp_f0 = ((temp_f1 - temp_f4) / (arg0->unk338 * arg0->unk574 * 0.95f)) * ((temp_f1 + temp_f4) * 0.5f);
    *arg1 = temp_f0;
    if ((fparg0 - 3.0f) < temp_f0) {
        var_3 = 1;
    }
    return var_3;
}

/* ---- aiOkToHuntUsingLOS__7Vehicle ---- */
s32 aiOkToHuntUsingLOS__7Vehicle(Vehicle* arg0, ...) {
    AIBrain* temp_3_2;
    Driver* temp_3;
    Driver* temp_6;
    s32 var_8;

    temp_3 = arg0->driver;
    var_8 = 0;
    if (temp_3->unk294 != 0) {
        if (temp_3->mode != 5) {
            temp_3_2 = arg0->brain;
            if (temp_3_2->specialActive != 0) {
                var_8 = temp_3_2->weapon != 4;
            }
        } else {
            var_8 = 1;
        }
    }
    if (var_8 != 0) {
        temp_6 = arg0->driver;
        if (!(((u8) ((temp_6->points + (temp_6->group * 4))->unk8 + D_004FA030->humanGroup[temp_6->target->aiOrPlayerIdx])->unk140 >> 1) & 1)) {
            var_8 = 0;
        } else {
            var_8 = (arg0->unk17E4 >= 0x10) ? 0 : var_8;
        }
    }
    return var_8;
}

/* ---- aiOkToUseWeaponForRearFiring__7Vehiclei ---- */
s32 aiOkToUseWeaponForRearFiring__7Vehiclei(Vehicle* arg0, s32 arg1, ...) {
    s32 var_5;

    var_5 = 0;
    switch (arg1) {
    case 2:
    case 3:
    case 4:
    case 6:
    case 7:
        var_5 = 1;
        break;
    case 1:
        var_5 = arg0->brain->unk610;
        break;
    }
    return var_5;
}

/* ---- aiPerformBeadOnHuntCs__7Vehicle ---- */
f32 atan2f(f32*, f32, f32);                         /* extern */
f32 func_0021F100(Driver*, f32, f32);               /* extern */

s32 aiPerformBeadOnHuntCs__7Vehicle(Vehicle* arg0, ...) {
    f32 sp4;
    s32 sp8;
    f32 sp10;
    AIBrain* temp_2_3;
    AIBrain* temp_2_4;
    AIBrain* temp_3_3;
    AIBrain* temp_4;
    Driver* temp_2;
    Driver* temp_2_2;
    Driver* temp_4_2;
    Driver* temp_4_3;
    Vehicle* temp_3_4;
    f32 temp_f13;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 var_f0;
    s32 temp_3;
    s32 temp_3_2;

    temp_4 = arg0->brain;
    if (!((temp_4->range18 * 1.5f) < temp_4->targetDist) && (arg0->driver->targetReachable != 0)) {
        if (temp_4->okToAttack != 0) {
            if ((temp_4->specialActive != 0) && ((temp_3 = temp_4->weapon, (temp_3 == 5)) || ((temp_3 == 1) && ((temp_3_2 = arg0->character, (temp_3_2 == 0xC0)) || (temp_3_2 == 0x1A0))))) {
                func_00103888(arg0);
            } else {
                temp_2_2 = arg0->driver;
                temp_f1 = arg0->cruiseSpeed;
                if (temp_2_2->minSpeed < temp_f1) {
                    temp_2_2->minSpeed = temp_f1;
                }
                temp_2_3 = arg0->brain;
                if (arg0->unk17D8 < 5) {
                    temp_f1_2 = temp_2_3->unk3EC;
                    if (temp_f1_2 < 30.0f) {
                        var_f0 = temp_f1_2 * 1.5f;
                        goto block_24;
                    }
                } else {
                    temp_f2 = temp_2_3->unk3EC;
                    if (temp_2_3->unk3E8 < fabsf(temp_f2)) {
                        var_f0 = temp_f2 * 0.75f;
block_24:
                        temp_2_3->unk3EC = var_f0;
                    }
                }
                temp_3_3 = arg0->brain;
                sp4 = 0.0f;
                sp8 = 0;
                if ((temp_3_3->unk5B8 == 0) && (temp_3_3->targetDist < 150.0f)) {
                    if (sp4 < temp_3_3->unk3EC) {

                    }
                }
                M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($v0) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf13, 0x10($v0) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf14, 0x20($v0) */);
                M2C_ERROR(/* unknown instruction: vmulax.xyz ACC, $vf12, $vf11x */);
                M2C_ERROR(/* unknown instruction: vmadday.xyz ACC, $vf13, $vf11y */);
                M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf11, $vf14, $vf11z */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf11, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($v0) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($a0) */);
                M2C_ERROR(/* unknown instruction: vadd.xyz $vf11, $vf11, $vf12 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf11, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($a0) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($v1) */);
                M2C_ERROR(/* unknown instruction: vsub.xyz $vf11, $vf11, $vf12 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf11, 0x10($sp) */);
                temp_3_4 = arg0->driver->target;
                temp_f20 = atan2f(&sp10, sp10, sp14);
                if ((temp_3_4 != NULL) && (temp_3_4->dying != 0) && (temp_3_4->unk41C < arg0->brain->unk3F0)) {
                    aiCheckSpeed__7Vehiclef(arg0, 0x447A0000);
                } else {
                    aiDriveToAttackRange__7Vehicle(arg0);
                }
                func_00130D68(arg0->driver, temp_f20);
            }
        } else {
            goto block_5;
        }
    } else {
block_5:
        temp_4_2 = arg0->driver;
        driverGetNewPointInFrontOfVehicle__6DriverP7Vehicle(temp_4_2, temp_4_2->target);
        aiLoseBeads__7Vehicle(arg0);
        temp_4_3 = arg0->driver;
        temp_4_3->unk288 = 1;
        temp_f13 = arg0->brain->unk3E8;
        arg0->brain->unk3EC = func_0021F100(temp_4_3, -temp_f13, temp_f13);
        temp_2_4 = arg0->brain;
        temp_f2_2 = temp_2_4->unk3EC;
        temp_f1_3 = temp_2_4->unk3E4;
        if (fabsf(temp_f2_2) < temp_f1_3) {
            if (!(temp_f2_2 > 0.0f)) {
                temp_2_4->unk3EC = (f32) -temp_f1_3;
            } else {
                temp_2_4->unk3EC = temp_f1_3;
            }
        }
    }
    temp_2 = arg0->driver;
    temp_2->unk54 = 1000.0f;
    return (s32) temp_2;
}

/* ---- aiPerform__7Vehicle ---- */
s32 aiPerform__7Vehicle(Vehicle* arg0, ...) {
    AIBrain* temp_4;
    Driver* temp_3;

    temp_3 = arg0->driver;
    if (temp_3->snipe == 0) {
        temp_4 = arg0->brain;
        if (temp_4->tasActive == 0) {
            if (temp_4->ramming == 0) {
                if ((u32) (temp_3->mode - 2) < 3U) {
                    return func_00104760(arg0);
                }
                driverGetNewPointInFrontOfVehicle__6DriverP7Vehicle(temp_3, arg0);
                aiInitTurnAndShoot__7Vehicleii(arg0, 0x78, 1);
                arg0->brain->unk5D0 = 1;
                return 1;
            }
            return aiPerformBeadOnHuntCs__7Vehicle(arg0);
        }
        temp_3->goalPos = temp_3->targetPos;
        return func_00102948(arg0);
    }
    return func_00104848(arg0);
}

/* ---- aiPickBestWeaponToFireNow__7Vehicle ---- */
s32 aiPickBestWeaponToFireNow__7Vehicle(Vehicle* arg0, ...) {
    AIBrain* temp_2;
    s32 temp_17;
    s32 temp_2_2;
    s32 var_2;
    s32* temp_3;

    temp_17 = arg0->driver->mode;
    temp_2 = arg0->brain;
    if ((temp_17 == 3) && (fabsf(temp_2->targetBearing) > 2.268928f)) {
        if (aiIsGoodWeaponChoice__7Vehiclei(arg0, 6) == 0) {
            if (aiIsGoodWeaponChoice__7Vehiclei(arg0, 3) == 0) {
                if (aiIsGoodWeaponChoice__7Vehiclei(arg0, 4) == 0) {
                    if (aiIsGoodWeaponChoice__7Vehiclei(arg0, 2) == 0) {
                        goto block_6;
                    }
                    goto block_17;
                }
                goto block_21;
            }
block_6:
            arg0->brain->weapon = temp_17;
        } else {
            goto block_11;
        }
    } else if (temp_2->aimed != 0) {
        if (aiIsGoodWeaponChoice__7Vehiclei(arg0, 1) != 0) {
            arg0->brain->weapon = 1;
        } else if (aiIsGoodWeaponChoice__7Vehiclei(arg0, 6) != 0) {
block_11:
            arg0->brain->weapon = 6;
        } else if (aiIsGoodWeaponChoice__7Vehiclei(arg0, 7) != 0) {
            arg0->brain->weapon = 7;
        } else if (aiIsGoodWeaponChoice__7Vehiclei(arg0, 3) == 0) {
            if (aiIsGoodWeaponChoice__7Vehiclei(arg0, 4) == 0) {
                if (aiIsGoodWeaponChoice__7Vehiclei(arg0, 2) != 0) {
block_17:
                    arg0->brain->weapon = 2;
                } else {
                    if (aiIsGoodWeaponChoice__7Vehiclei(arg0, 5) == 0) {
                        goto block_19;
                    }
                    goto block_24;
                }
            } else {
                goto block_21;
            }
        } else {
block_19:
            arg0->brain->weapon = 3;
        }
    } else if (aiIsGoodWeaponChoice__7Vehiclei(arg0, 4) != 0) {
block_21:
        arg0->brain->weapon = 4;
    } else if (aiIsGoodWeaponChoice__7Vehiclei(arg0, 5) != 0) {
block_24:
        arg0->brain->weapon = 5;
        arg0->weapSlot[5] = mathfRand__Fii(0xB, 0xD);
    }
    temp_2_2 = arg0->brain->weapon;
    var_2 = temp_2_2 * 4;
    if (temp_2_2 != 0) {
        temp_3 = &arg0->ammo[temp_2_2];
        if (*temp_3 <= 0) {
            var_2 = 1;
            *temp_3 = 1;
        }
    }
    return var_2;
}

/* ---- aiSeekPointAndStop__7Vehicle ---- */
? boundFAngle__FPf(u8*, Driver*);                   /* extern */

s32 aiSeekPointAndStop__7Vehicle(Vehicle* arg0, ...) {
    Driver* temp_4;
    Driver* temp_5;
    f32 temp_f12;
    f32 temp_f20;
    s128 temp_2;

    temp_5 = arg0->driver;
    if ((*temp_5->points + (temp_5->pointA << 5))->unk1C < 2) {
        goto block_9;
    }
    if (temp_5->mode != 2) {
block_9:
        temp_f12 = arg0->driver->dist4C;
        arg0->driver->minSpeed = 0.0f;
        if (temp_f12 < 10.0f) {
            temp_f20 = arg0->driver->minSpeed;
            if (arg0->velAlongHeading == temp_f20) {
                arg0->driver->unk288 = 1;
                arg0->driver->following = 0;
                driverGetNextPoint__6Driveri(arg0->driver, -1, temp_f12);
                driverCalcNextPointTurn__6Driver(arg0->driver);
                driverGetOffsetFromPoint__6Driver(arg0->driver);
                arg0->driver->performing = 1;
                arg0->brain->unk34 = temp_f20;
                arg0->brain->aimPoint = (s128) arg0->driver->target->pos;
            }
            arg0->pad[4] = 0;
            arg0->pad[8] = 1;
            arg0->pad[7] = 0;
        } else {
            aiCheckSpeed__7Vehiclef(arg0, temp_5, temp_f12);
        }
        temp_4 = arg0->driver;
        return func_00130D68(temp_4, temp_4->heading48);
    }
    if (arg0->velAlongHeading < 0.1f) {
        driverGetNextPoint__6Driveri(temp_5, temp_5->nextPoint);
        driverCalcNextPointTurn__6Driver(arg0->driver);
        driverGetOffsetFromPoint__6Driver(arg0->driver);
        arg0->brain->unk34 = 0.0f;
        arg0->driver->unk288 = 1;
        arg0->driver->turning = 0;
        arg0->driver->following = 0;
        arg0->driver->performing = 1;
        arg0->brain->unk438 = 0;
        temp_2 = (s128) arg0->driver->target->pos;
        arg0->brain->aimPoint = temp_2;
        return (s32) temp_2;
    }
    arg0->brain->unk40 = (f32) (temp_5->unk58 + 1.5707964f);
    boundFAngle__FPf(&arg0->brain->_pad30[0x10], temp_5);
    return func_00103F20(arg0);
}

/* ---- aiSetAggressiveness__7Vehiclei ---- */
s32 aiSetAggressiveness__7Vehiclei(Vehicle* arg0, s32 arg1, ...) {
    AIBrain* temp_2;
    AIBrain* temp_3;
    AIBrain* temp_4;
    AIBrain* temp_4_2;
    AIBrain* temp_4_3;
    AIBrain* temp_4_4;
    AIBrain* temp_4_5;
    AIBrain* temp_4_6;
    AIBrain* temp_4_7;
    AIBrain* temp_4_8;
    AIBrain* temp_4_9;
    AIBrain* temp_5;
    AIBrain* temp_5_2;
    AIBrain* temp_5_3;
    AIBrain* temp_5_4;
    f32 temp_f20;
    f32 var_f2;
    s32 temp_3_2;
    s32 temp_6;

    temp_f20 = (f32) arg1 / 100.0f;
    func_001003C0(arg0);
    temp_6 = arg1 < 0x1E;
    arg0->brain->fairness = temp_f20;
    arg0->brain->unk584 = (s32) (0x3C - ((s32) (arg1 * 0x3C) / 100));
    temp_4 = arg0->brain;
    temp_4->specialInterval = temp_4->unk584 + 0x1E;
    if (temp_6 != 0) {
        temp_2 = arg0->brain;
        temp_2->unk400 = (f32) (temp_2->unk400 * 0.5f);
    }
    arg0->brain->unk3E0 = arg0->cruiseSpeed * 0.25f;
    if (temp_6 != 0) {
        temp_4_2 = arg0->brain;
        temp_4_2->unk4A0 *= 3;
        temp_5 = arg0->brain;
        temp_5->unk498 = (s32) (temp_5->unk498 * 3);
        temp_4_3 = arg0->brain;
        temp_4_3->unk4A8 = (s32) (temp_4_3->unk4A8 * 3);
    } else if (arg1 >= 0x3C) {
        temp_4_4 = arg0->brain;
        temp_4_4->unk474 = (s32) temp_4_4->unk474 / 2;
        temp_5_2 = arg0->brain;
        temp_5_2->unk4A0 = (s32) temp_5_2->unk4A0 / 2;
        temp_4_5 = arg0->brain;
        temp_4_5->unk498 = (s32) ((s32) temp_4_5->unk498 / 2);
    } else {
        arg0->unk318 = (f32) (arg0->unk318 * 0.75f);
    }
    temp_4_6 = arg0->brain;
    temp_4_6->unk588 = (s32) (temp_4_6->unk588 * 0x64);
    if (arg1 != 0) {
        temp_3 = arg0->brain;
        temp_3->unk588 = (s32) ((s32) temp_3->unk588 / arg1);
        if (arg1 >= 0x3D) {
            arg0->brain->tasTicks = mathfRand__Fii(0, arg0->brain->unk588);
            if (arg1 >= 0x56) {
                temp_4_7 = arg0->brain;
                temp_4_7->tasTicks += mathfRand__Fii(0, arg0->brain->unk588);
                temp_5_3 = arg0->brain;
                temp_5_3->unk4A0 = (s32) temp_5_3->unk4A0 / 2;
                temp_4_8 = arg0->brain;
                temp_4_8->unk498 = (s32) ((s32) temp_4_8->unk498 / 2);
                temp_5_4 = arg0->brain;
                temp_5_4->unk4A8 = (s32) ((s32) temp_5_4->unk4A8 / 2);
            }
        }
    }
    temp_4_9 = arg0->brain;
    temp_4_9->unk3F0 *= 2.0f * temp_f20;
    temp_3_2 = D_004FA030->difficulty;
    switch (temp_3_2) {                             /* irregular */
    case 0:
        var_f2 = 0.5f;
        arg0->brain->unk3E0 = arg0->cruiseSpeed * 0.95f;
        arg0->unk318 = (f32) (arg0->unk318 * 0.5f);
block_18:
        arg0->brain->fairness *= var_f2;
        return (s32) arg0->brain;
    case 2:
        var_f2 = 1.5f;
        arg0->brain->unk3E0 = arg0->cruiseSpeed * 0.01f;
        goto block_18;
    default:
        return 2;
    }
}

/* ---- aiSetAttackState__7Vehicle12_attackState ---- */
s32 aiSetAttackState__7Vehicle12_attackState(Vehicle* arg0, s32 arg1, ...) {
    AIBrain* temp_3;
    s32 var_2;

    temp_3 = arg0->brain;
    var_2 = temp_3->attackState;
    if (var_2 != arg1) {
        temp_3->attackState = arg1;
        var_2 = (s32) arg0->brain;
        var_2->unk488 = 0;
    }
    return var_2;
}

/* ---- aiStartTurnToNewCruisePoint__7Vehicle ---- */
s32 aiStartTurnToNewCruisePoint__7Vehicle(Vehicle* arg0, ...) {
    AIBrain* temp_2;
    Driver* temp_3;

    arg0->driver->turning = 1;
    arg0->driver->following = 0;
    temp_3 = arg0->driver;
    if (temp_3->performing != 0) {
        temp_3->performing = 0;
        driverGetNewPointInFrontOfVehicle__6DriverP7Vehicle(arg0->driver, arg0);
    }
    arg0->brain->unk428 = 0;
    if (D_004FA030->singlePlayer != 0) {
        func_00130E88(arg0->driver, 4);
    }
    temp_2 = arg0->brain;
    temp_2->unk4C = 0.0f;
    arg0->brain->unk438 = 0;
    return (s32) temp_2;
}

/* ---- aiToPlayerLOSCheck__7Vehicle ---- */
s32 aiToPlayerLOSCheck__7Vehicle(Vehicle* arg0, ...) {
    f32 sp8;
    s128 sp10;
    AIBrain* temp_2_2;
    AIBrain* temp_3;
    AIBrain* temp_3_2;
    AIBrain* temp_3_3;
    AIBrain* temp_3_4;
    Driver* temp_4_2;
    s32 temp_2;
    s32 temp_4;
    s32 var_2;
    s32 var_2_2;
    s32 var_3;

    temp_3 = arg0->brain;
    var_2 = temp_3->thinkToken;
    if (var_2 != 0) {
        temp_4 = temp_3->noLosTicks;
        if (temp_4 < 0x12C) {
            temp_3->noLosTicks = temp_4 + arg0->frameTicks;
        }
        temp_4_2 = arg0->driver;
        var_2 = (s32) temp_4_2->targetPos;
        if (var_2 != 0) {
            if (arg0->brain->targetDist < 1300.0f) {
                sp8 = sp8 + arg0->height + 5.0f;
                sp10 = (s128) *temp_4_2->targetPos;
                unksp18 += 5.0f;
                temp_3_2 = arg0->brain;
                if (hdLosTest__FP8_fvectorT0P9_hdResulti(sp, (FVECTOR* ) &sp10, NULL, 0, /* extra? */ (s128) arg0->pos) != 0) {
                    temp_2 = temp_3_2->noLosTicks;
                    if (temp_2 != 0) {
                        temp_3_2->noLosTicks = temp_2 >> 1;
                    }
                }
            }
            if (arg0->brain->noLosTicks >= 0x3C) {
                arg0->brain->seesTarget = 0;
                arg0->brain->sawTarget = 0;
                arg0->brain->aimedPitch = 0;
                var_2 = (s32) arg0->brain;
                var_2->unk5A4 = 0;
            } else {
                var_2_2 = 1;
                if (!(fabsf(arg0->brain->targetFacing) < 0.7853982f)) {
                    var_2_2 = 0;
                }
                arg0->brain->seesTarget = var_2_2;
                temp_3_3 = arg0->brain;
                if (temp_3_3->seesTarget != 0) {
                    temp_3_3->sawTarget = 1;
                }
                temp_2_2 = arg0->brain;
                var_3 = 1;
                if (!(fabsf(temp_2_2->targetBearing) < 0.6108653f)) {
                    var_3 = 0;
                }
                temp_2_2->aimedPitch = var_3;
                temp_3_4 = arg0->brain;
                var_2 = 1;
                if (temp_3_4->aimedPitch != 0) {
                    temp_3_4->aimed = 1;
                }
            }
        }
    }
    return var_2;
}

/* ---- aiTurnCorner__7Vehicle ---- */
s32 aiTurnCorner__7Vehicle(Vehicle* arg0, ...) {
    AIBrain* temp_3_4;
    AIBrain* temp_3_6;
    Driver* temp_2;
    Driver* temp_2_2;
    Driver* temp_2_3;
    Driver* temp_3;
    Driver* temp_3_2;
    Driver* temp_3_3;
    Driver* temp_3_5;
    Driver* temp_4;
    Driver* temp_4_2;
    Vehicle* temp_2_4;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f2;
    s32 var_17;
    s32 var_2;
    s32 var_condition_bit;

    temp_4 = arg0->driver;
    var_17 = 1;
    if (temp_4->unk288 != 0) {
        driverInitTurn__6Driver(temp_4);
    }
    if (func_00130C50(arg0->driver) == 0) {
        temp_3 = arg0->driver;
        if (temp_3->unk260 == 0) {
            arg0->_pad48A[1] = 0;
            if ((arg0->onGround != 0) && ((arg0->cruiseSpeed * 0.5f) < temp_3->minSpeed)) {
                temp_3->minSpeed = arg0->unk36C * 0.95f;
            }
        } else {
            arg0->_pad48A[1] = 1;
            arg0->pad[2] = 1;
        }
        temp_4_2 = arg0->driver;
        func_00130D68(temp_4_2, temp_4_2->heading48);
        temp_3_2 = arg0->driver;
        if (temp_3_2->unk284 == 0) {
            goto block_21;
        }
        if (!(fabsf(temp_3_2->unk54) < 5.0f)) {
block_21:
            if (arg0->driver->unk1AC > 0.0f) {
                func_00130598(arg0->driver, 1);
                temp_3_3 = arg0->driver;
                var_2 = 1;
                if (temp_3_3->unk260 == 0) {
                    var_2 = 1;
                    if (arg0->pad[0xA] != 0) {
                        var_condition_bit = temp_3_3->unk54 < 0.0f;
                        goto block_27;
                    }
                    var_2 = 1;
                    if (arg0->pad[9] != 0) {
                        var_condition_bit = temp_3_3->unk54 > 0.0f;
block_27:
                        if (!var_condition_bit) {
                            goto block_28;
                        }
                    } else {
block_28:
                        var_2 = 0;
                    }
                }
                if ((var_2 == 0) && (arg0->throttle > 0.36666667f)) {
                    arg0->pad[9] = 0;
                    arg0->pad[8] = 1;
                    arg0->pad[0xA] = 0;
                    arg0->pad[4] = 0;
                    arg0->pad[7] = 0;
                }
                temp_2 = arg0->driver;
                temp_2->unk1AC = (f32) (temp_2->unk1AC - (arg0->unk338 * arg0->unk570));
                temp_f0 = arg0->throttle;
                temp_2_2 = arg0->driver;
                if (temp_f0 > 0.36666667f) {
                    temp_2_2->minSpeed = temp_f0;
                } else if (temp_2_2->minSpeed < 0.36666667f) {
                    temp_2_2->minSpeed = 0.36666667f;
                    arg0->driver->unk1AC = 0.0f;
                }
            }
        } else if (temp_3_2->turnCount < 3) {
            arg0->_pad48A[1] = 1;
            arg0->pad[2] = 1;
        }
    } else {
        var_17 = 0;
        arg0->driver->unk1F0 = 0;
    }
    temp_3_4 = arg0->brain;
    if (temp_3_4->ramming == 0) {
        temp_3_5 = arg0->driver;
        if ((temp_3_5->unk260 != 0) && ((temp_3_5->unk27C != 0) || (temp_3_5->unk278 != 0))) {
            arg0->pad[4] = 0;
            arg0->pad[8] = 1;
        } else if (!(temp_3_5->dist4C < (temp_3_5->unk1B4 * arg0->unk2DC))) {
            temp_f2 = temp_3_5->minSpeed;
            temp_f1 = arg0->velAlongHeading;
            if ((temp_f2 * 1.1f) < temp_f1) {
                arg0->pad[8] = 1;
            } else if (temp_f1 < (temp_f2 * 0.98f)) {
                arg0->pad[4] = 1;
            }
        } else {
            if (arg0->throttle > 0.36666667f) {
                arg0->pad[8] = 1;
            }
            temp_2_3 = arg0->driver;
            temp_f1_2 = arg0->throttle;
            if (temp_f1_2 < temp_2_3->minSpeed) {
                if (!(temp_f1_2 > 0.36666667f)) {
                    temp_2_3->minSpeed = 0.36666667f;
                } else {
                    temp_2_3->minSpeed = temp_f1_2;
                }
            }
        }
    } else {
        temp_3_4->ramming = 0;
        arg0->pad[8] = 0;
    }
    if (var_17 == 0) {
        arg0->brain->unk5B8 = 0;
        temp_2_4 = arg0->driver->target;
        if (temp_2_4 != NULL) {
            temp_3_6 = arg0->brain;
            if (temp_2_4->turbo < temp_3_6->unk3F0) {
                temp_3_6->unk5B8 = 1;
            }
        }
        arg0->brain->unk420 = 0x258;
        arg0->driver->odometer = 0.0f;
    }
    return var_17;
}

/* ---- aiTurn__7Vehicle ---- */
s32 aiTurn__7Vehicle(Vehicle* arg0, ...) {
    Driver* temp_4;
    Driver* temp_4_2;
    Driver* temp_6;
    s32 var_2;

    var_2 = aiTurnCorner__7Vehicle(arg0);
    if (var_2 == 0) {
        temp_4 = arg0->driver;
        if (temp_4->snipe == 0) {
            goto block_8;
        }
        if (temp_4->unk204 != temp_4->nextPoint) {
block_8:
            arg0->driver->turning = 0;
            arg0->driver->following = 1;
            arg0->driver->performing = 0;
            arg0->brain->unk5C4 = 0;
        } else {
            temp_4->turning = 0;
            arg0->driver->following = 0;
            arg0->driver->performing = 1;
        }
        temp_6 = arg0->driver;
        if (temp_6->group != (*temp_6->points + (temp_6->pointA << 5))->unk1D) {
            temp_6->unk218 += 1;
        } else {
            temp_6->unk218 = 0;
        }
        temp_4_2 = arg0->driver;
        var_2 = temp_4_2->unk218 < 4;
        if (var_2 == 0) {
            driverGetNewPointInFrontOfVehicle__6DriverP7Vehicle(temp_4_2, arg0, temp_6);
            var_2 = (s32) arg0->driver;
            var_2->unk218 = 0;
        }
    }
    return var_2;
}

/* ---- aiUpdateAttack__7Vehicle ---- */
f32 func_0021F100(s32, AIBrain*, Vehicle*, ?, ?);   /* extern */

s32 aiUpdateAttack__7Vehicle(Vehicle* arg0, ...) {
    AIBrain* temp_3_4;
    AIBrain* temp_3_5;
    AIBrain* temp_3_7;
    AIBrain* temp_4;
    AIBrain* temp_4_2;
    AIBrain* temp_4_6;
    AIBrain* temp_4_9;
    AIBrain* temp_5;
    AIBrain* temp_5_2;
    AIBrain* temp_5_3;
    Driver* temp_2;
    Driver* temp_3_3;
    Driver* temp_4_3;
    Driver* temp_4_7;
    Driver* var_2;
    Driver* var_4;
    Vehicle* temp_5_4;
    Vehicle* temp_6;
    f32 var_f1;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_3_6;
    s32 temp_4_10;
    s32 temp_4_4;
    s32 temp_4_5;
    s32* temp_4_8;

    temp_4 = arg0->brain;
    temp_4->specialTimer += arg0->frameTicks;
    temp_5 = arg0->brain;
    temp_5->timer494 += arg0->frameTicks;
    temp_4_2 = arg0->brain;
    temp_4_2->timer49C += arg0->frameTicks;
    temp_5_2 = arg0->brain;
    temp_5_2->timer4A4 += arg0->frameTicks;
    temp_4_3 = arg0->driver;
    if (temp_4_3->mode != 0) {
        if (temp_4_3->target->invisible == 0) {
            temp_3 = arg0->character;
            if ((temp_3 != 0xC0) && (temp_3 != 0x60)) {
                if (temp_3 < 0x161) {
                    if (temp_4_3->unk294 != 0) {
                        if (D_004FA030->progressMax < (D_004FA030->progress * 0.75f)) {
                            temp_4_3->unk294 = 0;
                        }
                    } else if ((D_004FA030->progress * 0.9f) < D_004FA030->progressMax) {
                        temp_4_3->unk294 = 1;
                    }
                } else {
                    goto block_15;
                }
            } else {
block_15:
                arg0->driver->unk294 = 1;
            }
            temp_3_2 = D_004FA030->levelType;
            if (temp_3_2 != 8) {
                if (temp_3_2 < 9) {
                    if (temp_3_2 != 4) {

                    } else {
                        goto block_29;
                    }
                } else if (temp_3_2 == 0x14) {
                    goto block_29;
                }
            } else {
block_29:
                arg0->driver->unk294 = 0;
            }
            func_00107920(arg0, temp_5_2);
            arg0->brain->okToAttack = 0;
            temp_2 = arg0->driver;
            if (D_004FA030->difficulty > 0) {
                var_4 = temp_2;
                if (temp_2->target != NULL) {
                    arg0->brain->okToAttack = 1;
                    temp_3_3 = arg0->driver;
                    if (temp_3_3->targetReachable != 0) {
                        if (temp_3_3->target->invisible == 0) {
                            if ((arg0->character != 0x140) || !(fabsf(arg0->brain->targetFacing) < 1.0471976f)) {
                                temp_6 = arg0->driver->target;
                                if (temp_6->dying == 0) {
                                    temp_5_3 = arg0->brain;
                                    if (temp_5_3->unk490 >= arg0->unk18B8) {
                                        if (arg0->unk5B5 != 0) {
                                            temp_4_4 = D_004FA030->singlePlayer;
                                            if ((temp_4_4 != 0) && (fabsf(temp_5_3->targetFacing) < 0.5235988f) && (fabsf(temp_5_3->targetBearing) < 0.5235988f) && (temp_5_3->targetDist < 100.0f) && (arg0->unk1A64 == 0) && (temp_5_3->unk3F0 < temp_6->unk41C) && (arg0->brain->unk400 < func_0021F100(temp_4_4, temp_5_3, temp_6, 0, 0x3F800000))) {
                                                goto block_55;
                                            }
                                        }
                                    } else if (temp_5_3->targetDist < 50.0f) {
                                        temp_5_3->okToAttack = 0;
                                    }
                                }
                            } else {
                                goto block_55;
                            }
                        } else {
block_55:
                            arg0->brain->okToAttack = 0;
                        }
                    }
                    goto block_57;
                }
                goto block_71;
            }
block_57:
            temp_5_4 = arg0->driver->target;
            var_4 = arg0->driver;
            if ((temp_5_4 != NULL) && (var_4->mode == 5)) {
                if (temp_5_4->dying == 0) {
                    if ((var_4->performing != 0) && (var_4->snipe != 0) && (aiIsGoodWeaponChoice__7Vehiclei(arg0, arg0->brain->weapon) == 0)) {
                        aiPickBestWeaponToFireNow__7Vehicle(arg0);
                    }
                } else if (var_4->targetReachable != 0) {
                    temp_3_4 = arg0->brain;
                    if ((temp_3_4->okToAttack != 0) && (temp_5_4->turbo < temp_3_4->unk3F0) && (temp_3_4->ramming == 0)) {
                        temp_3_4->ramming = 1;
                        arg0->driver->turning = 0;
                        arg0->driver->following = 0;
                        arg0->driver->performing = 1;
                        arg0->brain->unk5B8 = 1;
                    }
                }
            } else {
block_71:
                temp_4_5 = var_4->mode;
                if (temp_4_5 == 4) {
                    temp_3_5 = arg0->brain;
                    if ((temp_3_5->tasActive == 0) && (temp_3_5->okToAttack != 0) && (temp_3_5->noLosTicks < 0xA)) {
                        var_f1 = 0.7853982f;
                        temp_3_6 = D_004FA030->levelType;
                        if ((temp_3_6 == temp_4_5) || (temp_3_6 == 8)) {
                            var_f1 = 6.2831855f;
                        }
                        if (fabsf(arg0->brain->targetFacing) < var_f1) {
                            aiInitTurnAndShoot__7Vehicleii(arg0, 0x78, 1);
                        }
                    }
                }
            }
            temp_4_6 = arg0->brain;
            if ((temp_4_6->unk5A8 != 0) && (temp_4_6->ramming == 0)) {
                temp_4_6->unk42C -= arg0->frameTicks;
                temp_3_7 = arg0->brain;
                if (temp_3_7->unk42C > 0) {
                    temp_4_7 = arg0->driver;
                    if ((temp_4_7->turning == 0) && (temp_3_7->noLosTicks < 0xA) && (temp_4_7->targetReachable != 0) && (temp_3_7->okToAttack != 0) && (temp_3_7->targetDist < temp_3_7->range18)) {
                        temp_3_7->ramming = 1;
                        arg0->driver->turning = 0;
                        arg0->driver->following = 0;
                        arg0->driver->performing = 1;
                    }
                } else {
                    temp_3_7->unk42C = 0;
                    arg0->brain->unk5A8 = 0;
                }
            }
        } else if (arg0->brain->attackState >= 2) {
            aiSetAttackState__7Vehicle12_attackState(arg0, 1);
        }
    } else if (arg0->brain->attackState != 0) {
        aiSetAttackState__7Vehicle12_attackState(arg0, 0);
    }
    if ((u32) (arg0->brain->attackState - 2) < 5U) {
        if ((u32) (arg0->brain->weapon - 1) >= 8U) {
            aiSetAttackState__7Vehicle12_attackState(arg0, 1);
        }
        temp_4_8 = &arg0->ammo[arg0->brain->weapon];
        if (*temp_4_8 <= 0) {
            *temp_4_8 = 1;
        }
        temp_4_9 = arg0->brain;
        if ((temp_4_9->targetDist < 300.0f) && (fabsf(arg0->steerInput) < 0.4f) && (temp_4_9->unk4A0 < temp_4_9->timer49C) && (fabsf(temp_4_9->targetBearing) < 0.17453294f) && (fabsf(temp_4_9->targetPitch) < 0.17453294f)) {
            if ((D_004FA030->progress * 0.25f) < D_004FA030->progressMax) {
                temp_4_9->wantTurbo = 1;
            }
            arg0->brain->timer49C = 0;
        }
    }
    temp_4_10 = arg0->brain->attackState;
    switch (temp_4_10) {
    case 0:
        var_2 = arg0->driver;
        if (var_2->mode != 0) {
            return aiSetAttackState__7Vehicle12_attackState(arg0, 1);
        }
        return (s32) var_2;
    case 1:
        return func_00106370(arg0);
    case 2:
        return func_00106888(arg0);
    case 3:
        return func_00106A00(arg0);
    case 4:
        return func_00106A60(arg0);
    case 5:
        return func_00106AC8(arg0);
    case 6:
        return aiLineUpShot__7Vehicle(arg0);
    case 7:
        return func_00107380(arg0);
    case 8:
        return func_001076E8(arg0);
    default:
        var_2 = aiSetAttackState__7Vehicle12_attackState(arg0, 1);
        /* Duplicate return node #119. Try simplifying control flow for better match */
        return (s32) var_2;
    }
}

/* ---- aiUpdateBaitModeOld__7Vehicle ---- */
s32 attractGetClosestPoint__15AttractorPointsP8_fvector(void*, ?*, Driver*, s32, f32, s32); /* extern */

s32 aiUpdateBaitModeOld__7Vehicle(Vehicle* arg0, ...) {
    ? sp10;
    AIBrain* temp_3;
    AIBrain* temp_3_2;
    AIBrain* temp_4;
    AIBrain* temp_6_2;
    Driver* temp_4_2;
    Driver* temp_4_3;
    Driver* temp_4_4;
    Driver* temp_6;
    Vehicle* temp_2;
    s32 temp_5;
    s32 temp_5_2;
    s32 var_17;
    s32 var_2;

    temp_4 = arg0->brain;
    temp_4->unk464 += arg0->frameTicks;
    temp_2 = arg0->driver->target;
    var_17 = 0;
    if (temp_2 != NULL) {
        var_2 = temp_2->idleTicks < 0x258;
        if (var_2 != 0) {
            var_17 = 1;
        } else {
            goto block_4;
        }
    } else {
block_4:
        temp_3 = arg0->brain;
        if ((temp_3->unk5E4 != 0) && (temp_3->unk34 < 0.9f)) {
            temp_6 = arg0->driver;
            if (temp_6->performing == 0) {
                temp_5 = temp_3->unk434;
                if (temp_5 != 0) {
                    if (temp_6->target->idleTicks != 0) {
                        if (temp_6->nextPoint == -1) {
                            M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($sp) */);
                            M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($v0) */);
                            M2C_ERROR(/* unknown instruction: lqc2 $vf13, 0x10($v0) */);
                            M2C_ERROR(/* unknown instruction: lqc2 $vf14, 0x20($v0) */);
                            M2C_ERROR(/* unknown instruction: vmulax.xyz ACC, $vf12, $vf11x */);
                            M2C_ERROR(/* unknown instruction: vmadday.xyz ACC, $vf13, $vf11y */);
                            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf11, $vf14, $vf11z */);
                            M2C_ERROR(/* unknown instruction: sqc2 $vf11, 0x10($sp) */);
                            M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($a1) */);
                            M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($v1) */);
                            M2C_ERROR(/* unknown instruction: vadd.xyz $vf11, $vf11, $vf12 */);
                            M2C_ERROR(/* unknown instruction: sqc2 $vf11, 0x10($sp) */);
                            arg0->driver->nextPoint = attractGetClosestPoint__15AttractorPointsP8_fvector(temp_6->points, &sp10, temp_6, 0, 130.0f, 0);
                            temp_4_2 = arg0->driver;
                            temp_4_2->targetPos = *temp_4_2->points + (temp_4_2->nextPoint << 5);
                        }
                        arg0->driver->subState = 1;
                        var_2 = (s32) arg0->brain;
                        var_2->unk450 = 0x78;
                    } else {
                        temp_3->unk434 = temp_5 + arg0->frameTicks;
                        temp_6_2 = arg0->brain;
                        temp_5_2 = temp_6_2->unk434;
                        var_2 = temp_5_2 < 0x709;
                        if (var_2 != 0) {
                            temp_4_3 = arg0->driver;
                            var_2 = temp_4_3->subState;
                            if (var_2 == 1) {
                                var_2 = temp_4_3->target->idleTicks < temp_5_2;
                                if (var_2 != 0) {
                                    temp_6_2->unk434 = 0;
                                }
                            }
                        } else {
                            var_17 = 1;
                        }
                    }
                } else {
                    var_2 = -1;
                    temp_6->nextPoint = -1;
                    arg0->brain->unk434 = 1;
                }
            } else {
                var_2 = temp_3->unk428 < 0x259;
                goto block_28;
            }
        } else {
            var_2 = temp_3->unk424 < 0x12D;
block_28:
            var_17 = var_2 ^ 1;
        }
    }
    if (var_17 != 0) {
        func_00130E88(arg0->driver, 3);
        gamePickCruiseZone__7TheGameP7Vehiclei(D_004FA030, arg0, 0);
        arg0->brain->unk45C = 0;
        arg0->brain->unk4C = 0.0f;
        arg0->brain->unk428 = 0;
        arg0->driver->unk210 = -1;
        temp_3_2 = arg0->brain;
        if (temp_3_2->unk5E0 != 0) {
            temp_3_2->unk434 = 1;
        }
        temp_4_4 = arg0->driver;
        temp_4_4->targetPos = temp_4_4->targetCs + 0x10;
        var_2 = arg0->driver->performing;
        if (var_2 != 0) {
            aiInitTurnAndShoot__7Vehicleii(arg0, 0x78, 1);
            var_2 = (s32) arg0->brain;
            if (var_2->unk34 == 0.0f) {
                driverGetNewPointInFrontOfVehicle__6DriverP7Vehicle(arg0->driver, arg0);
                arg0->driver->turning = 0;
                var_2 = (s32) arg0->driver;
                var_2->unk258 = 1;
                arg0->brain->unk5D0 = 1;
            }
        }
    }
    return var_2;
}

/* ---- aiUpdateBaitMode__7Vehicle ---- */
s32 func_0010C458(void*, s32, FVECTOR*, Driver*);   /* extern */

s32 aiUpdateBaitMode__7Vehicle(Vehicle* arg0, ...) {
    AIBrain* temp_2;
    Driver* temp_7;
    s32 var_2;

    if (arg0->unk2128 >= 0xA) {
        temp_7 = arg0->driver;
        var_2 = D_004FA030->levelType ^ 4;
        if ((((var_2 == 0) ? 0x4EC : 0x1A4) < temp_7->ticks228) && ((temp_2 = arg0->brain, (temp_2->targetDist > 1000.0f)) || (fabsf(temp_2->targetBearing) > 2.268928f) || (fabsf(temp_2->targetFacing) > 1.9198622f) || (var_2 = func_0010C458(temp_7->points, temp_7->group, temp_7->targetPos, temp_7) < 2, (var_2 == 0)))) {
            var_2 = aiStartTurnToNewCruisePoint__7Vehicle(arg0);
        }
    } else {
        var_2 = aiStartTurnToNewCruisePoint__7Vehicle(arg0);
    }
    return var_2;
}

/* ---- aiUpdateFleeMode__7Vehicle ---- */
s32 aiUpdateFleeMode__7Vehicle(Vehicle* arg0, ...) {
    AIBrain* temp_2;
    AIBrain* temp_3;
    AIBrain* temp_4;
    AIBrain* temp_5;
    AIBrain* temp_5_2;
    Driver* temp_4_2;
    f32 temp_f1;
    s32 var_2;
    s32 var_4;

    temp_4 = arg0->brain;
    temp_4->unk45C += arg0->frameTicks;
    temp_2 = arg0->brain;
    temp_f1 = temp_2->aggression2;
    if (temp_f1 < 1.0f) {
        temp_2->aggression2 = temp_f1 + 0.00009259259f;
    }
    temp_5 = arg0->brain;
    if (temp_5->unk4C != 0.0f) {
        temp_5->unk45C -= M2C_ERROR(/* Read from unset register $f2 */) * 0x3C;
        arg0->brain->unk4C = 0.0f;
        temp_3 = arg0->brain;
        if (temp_3->unk45C < 0) {
            temp_3->unk45C = 0;
        }
    }
    temp_5_2 = arg0->brain;
    var_4 = 0;
    if (temp_5_2->unk60 < (f32) temp_5_2->unk45C) {
        var_4 = D_004FA030->singlePlayer != 0;
    }
    if (var_4 != 0) {
        aiGetFleeSpot__7Vehiclei(arg0, 0, 1);
        return aiStartTurnToNewCruisePoint__7Vehicle(arg0);
    }
    if (temp_5_2->unk594 == 0) {
        temp_4_2 = arg0->driver;
        var_2 = temp_4_2->nextPoint;
        if (temp_4_2->pointA == var_2) {
            var_2 = temp_4_2->subState;
            if (var_2 != 1) {
                temp_4_2->subState = 1;
                var_2 = (s32) arg0->brain;
                var_2->unk5E8 = 0;
                arg0->brain->unk438 = 0;
            }
        }
        /* Duplicate return node #17. Try simplifying control flow for better match */
        return var_2;
    }
    var_2 = (s32) arg0->driver;
    if (var_2->unk214 == var_2->unk210) {
        return aiGetFleeSpot__7Vehiclei(arg0, 0, 1);
    }
    return var_2;
}

/* ---- aiUpdatePickupGameMode__7Vehicle ---- */
f32 func_0021F100(f32, f32);                        /* extern */

s32 aiUpdatePickupGameMode__7Vehicle(Vehicle* arg0, ...) {
    AIBrain* temp_5;
    AIBrain* var_2;
    Driver* temp_6;
    f32 temp_f0;
    f32 temp_f13;
    f32 temp_f1;
    f32 var_f4;
    f32* var_2_2;
    s32 temp_3;
    s32 var_4;
    s32* var_3;

    var_f4 = 0.0f;
    var_3 = &arg0->ammo[1];
    var_4 = 0x21;
    temp_5 = arg0->brain;
    var_2_2 = &temp_5->weapRange[0x47];
    do {
        temp_f0 = (f32) *var_3;
        temp_f1 = *var_2_2;
        var_2_2 += 4;
        var_3 += 4;
        var_4 -= 1;
        var_f4 += temp_f0 * temp_f1;
    } while (var_4 >= 0);
    temp_6 = arg0->driver;
    temp_3 = temp_6->mode;
    if (temp_3 != 5) {
        var_2 = (AIBrain* )3;
        if (temp_3 == 3) {
            var_2 = D_004FA030 + 0x98000;
            if ((D_004FA030->singlePlayer != 0) && ((temp_5->unk60 + (temp_5->unk4C * 60.0f)) < (f32) temp_5->unk45C) && (temp_5->unk44 < arg0->health)) {
                var_2 = (AIBrain* )1;
                if (!(temp_5->unk58 < var_f4)) {
                    var_2 = (AIBrain* )1;
                    if (!(temp_6->target->health < var_f4)) {
                        var_2 = NULL;
                    }
                }
                if (var_2 != NULL) {
                    func_00130E88(arg0->driver, 5);
                    arg0->brain->fleeHealth = 0.0f;
                    temp_f13 = arg0->brain->aggrScale;
                    var_2 = arg0->brain;
                    var_2->healthScore = arg0->health * func_0021F100(temp_f13 * 0.3f, temp_f13);
                }
            }
        }
    } else {
        var_2 = (AIBrain* )1;
        if (!(arg0->health < temp_5->unk44) && !(temp_5->healthScore < temp_5->fleeHealth)) {
            var_2 = NULL;
            if (var_f4 < temp_5->unk58) {
                var_2 = (AIBrain* )1;
            }
        }
        if (var_2 != NULL) {
            func_00130E88(arg0->driver, 3);
            gamePickCruiseZone__7TheGameP7Vehiclei(D_004FA030, arg0, 0);
            arg0->brain->unk4C = 0.0f;
            arg0->brain->unk45C = 0;
            var_2 = arg0->brain;
            var_2->fleeHealth = 0.0f;
        }
    }
    return (s32) var_2;
}

/* ---- aiUpdateSnipeMode__7Vehicle ---- */
s32 aiUpdateSnipeMode__7Vehicle(Vehicle* arg0, ...) {
    AIBrain* temp_2;
    AIBrain* temp_2_2;
    AIBrain* temp_3;
    AIBrain* temp_4;
    Driver* temp_4_2;
    f32 temp_f1;
    s32 temp_3_2;
    s32 temp_5;
    s32 var_6;

    temp_4 = arg0->brain;
    temp_4->unk46C += arg0->frameTicks;
    temp_2_2 = arg0->brain;
    temp_f1 = temp_2_2->aggression2;
    if (temp_f1 < 1.0f) {
        temp_2_2->aggression2 = temp_f1 + 0.00009259259f;
    }
    var_6 = 0;
    if ((D_004FA030->numAIsAlive < 2) || (temp_3 = arg0->brain, ((temp_3->unk46C < 0xE11) == 0)) || ((temp_3->noLosTicks < 0xA) && (temp_3->targetDist < 100.0f))) {
        var_6 = 1;
    }
    temp_4_2 = arg0->driver;
    temp_5 = temp_4_2->pointA;
    temp_3_2 = temp_4_2->nextPoint;
    if ((temp_5 == temp_3_2) || (temp_4_2->curPoint == temp_3_2)) {
        if (var_6 != 0) {
            if ((arg0->unk1A64 == 0) && (fabsf(arg0->brain->targetBearing) < 0.7853982f)) {
                aiPerformBeadOnHuntCs__7Vehicle(arg0, 0, var_6, 1);
            } else {
                aiGetFleeSpot__7Vehiclei(arg0, 0, var_6, 1);
                arg0->brain->sniping = 0;
                arg0->brain->unk46C = 0;
                aiStartTurnToNewCruisePoint__7Vehicle(arg0);
                func_00130E88(arg0->driver, 2);
                driverGetNewPointInFrontOfVehicle__6DriverP7Vehicle(arg0->driver, arg0);
            }
        } else if ((temp_5 == temp_3_2) && (temp_4_2->subState != 1)) {
            temp_4_2->subState = 1;
            arg0->brain->unk5E8 = 0;
            arg0->brain->unk438 = 0;
        }
    }
    temp_2 = arg0->brain;
    temp_2->timer49C = 0;
    arg0->brain->timer494 = 0;
    return (s32) temp_2;
}

/* ---- aiUsingNonLOSWeapon__7Vehicle ---- */
s32 aiUsingNonLOSWeapon__7Vehicle(Vehicle* arg0, ...) {
    AIBrain* temp_5;
    s32 temp_3;
    s32 var_6;

    temp_5 = arg0->brain;
    var_6 = 0;
    if ((temp_5->weapon == 5) && (arg0->weapSlot[5] == 0xC) && ((temp_3 = D_004FA030->levelType, var_6 = 1, (temp_3 == 4)) || (temp_3 == 8)) && (temp_5->range18 < temp_5->targetDist)) {
        var_6 = 0;
    }
    return var_6;
}

/* ---- func_001002C0 ---- */
s32 func_0010BA78(void*, FVECTOR*, s32);            /* extern */
s32 func_0010BE18(void*, ?, s32);                   /* extern */
? mathfRotMatrixRPH__FPA3_fP8_fvector(FMATRIX*, void*); /* extern */
? vehicleDisable__7Vehicle(s32);                    /* extern */

s32 func_001002C0(Vehicle* arg0, s32 arg1, ...) {
    Driver* temp_4;
    s32 var_2;
    s32 var_6;

    var_6 = arg1;
    if (arg0->character == 0x220) {
        arg0->driver->nextPoint = 0;
        vehicleDisable__7Vehicle(var_6);
    } else {
        if ((D_004FA030->levelType != 3) && (var_6 != 0)) {
            var_6 = arg0->brain->cruiseZone;
            if (var_6 != -1) {
                var_2 = func_0010BA78(arg0->driver->points, &arg0->pos, var_6);
            } else {
                goto block_7;
            }
        } else {
block_7:
            var_2 = func_0010BE18(arg0->driver->points, 3, var_6);
        }
        arg0->driver->nextPoint = var_2;
    }
    gameCheckStartPoint__7TheGamePib(D_004FA030, &arg0->driver->nextPoint, 0);
    temp_4 = arg0->driver;
    arg0->unk214C = (s32) temp_4->nextPoint;
    driverInitToPoint__6Driveri(temp_4, temp_4->nextPoint);
    arg0->pos = arg0->cs->unk10;
    mathfRotMatrixRPH__FPA3_fP8_fvector(&arg0->rot, arg0->cs + 0x60);
    arg0->brain->unk420 = 0x258;
    return 0x258;
}

/* ---- func_001003C0 ---- */
f32 func_0021F100(f32, f32, ?, ?, ?, s32, ?, f32, f32); /* extern */

s32 func_001003C0(Vehicle* arg0, ...) {
    ? var_6;
    ? var_7;
    ? var_8;
    AIBrain* temp_2;
    AIBrain* temp_3_2;
    AIBrain* temp_4;
    AIBrain* var_4;
    f32 temp_f13;
    f32 temp_f13_2;
    f32 temp_f1;
    f32 temp_f2;
    f32 var_5;
    s32 temp_3;
    s32 var_9;

    var_6 = 0xB4;
    var_7 = 0x78;
    arg0->brain->unk3F0 = 0.2f;
    var_5 = 7.567e-42f;
    var_8 = 0x2A30;
    var_9 = 0x258;
    arg0->brain->unk5C8 = 0;
    arg0->brain->unk1C = 0.08726647f;
    arg0->brain->unk5E0 = 1;
    arg0->brain->unk5EC = 0;
    arg0->brain->unk44 = 15.0f;
    arg0->brain->unk58 = 15.0f;
    arg0->brain->unk60 = 1800.0f;
    arg0->brain->unk474 = 7;
    arg0->brain->specialInterval = 0xB4;
    arg0->brain->aggrScale = 0.33f;
    arg0->brain->unk3C = 0.5f;
    arg0->brain->unk50 = 3.0f;
    arg0->brain->unk490 = 0x78;
    arg0->brain->unk498 = 0x1518;
    arg0->brain->unk4A0 = 0x1518;
    arg0->brain->unk4A8 = 0x1518;
    arg0->brain->unk4AC = 0x2A30;
    arg0->brain->aggression = 0.5f;
    arg0->brain->aggression2 = 1.0f;
    var_4 = arg0->brain;
    var_4->threat = arg0->health * var_4->aggression * var_4->aggression2;
    arg0->brain->unk580 = 0x258;
    arg0->brain->unk588 = 0x1518;
    arg0->brain->unk408 = 0;
    arg0->brain->unk58C = 0;
    arg0->brain->unk5D8 = 0;
    arg0->brain->unk5DC = 0;
    arg0->brain->unk400 = 0.2f;
    arg0->driver->unk2AC = 1;
    arg0->brain->unk3E4 = 1.0f;
    arg0->brain->unk3E8 = 5.0f;
    arg0->brain->unk610 = 0;
    temp_3 = arg0->group;
    switch (temp_3) {
    case 1:
        var_4 = (AIBrain* )0x834;
        var_5 = 8.41e-43f;
        var_6 = 1;
        arg0->brain->unk3E4 = 2.0f;
        var_7 = 0x5A;
        var_8 = 0xEC4;
        var_9 = 2;
        arg0->brain->aggression = 0.25f;
        arg0->brain->unk4A0 = 0x834;
        arg0->brain->unk498 = 0x258;
        arg0->brain->unk610 = 1;
        arg0->brain->unk580 = 0x5A;
        arg0->brain->unk588 = 0xEC4;
        arg0->brain->unk408 = 0x3DCCCCCD;
block_12:
        arg0->brain->unk58C = var_9;
        break;
    case 2:
        var_4 = (AIBrain* )1;
        var_5 = 1.26e-43f;
        var_6 = 0x10E0;
        arg0->brain->unk3F0 = 0.6f;
        var_7 = 0x708;
        arg0->brain->unk1C = 0.15707964f;
        arg0->brain->unk5E0 = 1;
        arg0->brain->unk5EC = 1;
        arg0->brain->unk3C = 0.65f;
        arg0->brain->unk50 = 5.0f;
        arg0->brain->unk610 = 1;
        arg0->brain->unk3E4 = 3.0f;
        arg0->brain->unk400 = 0.5f;
        arg0->brain->unk408 = 0x3D4CCCCD;
        arg0->brain->aggression = 0.15f;
        arg0->brain->unk580 = 0x5A;
        arg0->brain->unk588 = 0x10E0;
        arg0->brain->unk5DC = 1;
        arg0->brain->unk4A8 = 0x708;
        break;
    case 3:
        var_4 = (AIBrain* )0x12C;
        var_5 = 1e-45f;
        arg0->brain->unk3F0 = 0.7f;
        var_6 = 0x4B0;
        var_7 = 0x2D;
        var_8 = 0x12FC;
        arg0->brain->unk4AC = 0x1C20;
        arg0->brain->unk490 = 0x12C;
        arg0->brain->aggrScale = 0.5f;
        arg0->brain->unk3E8 = 3.0f;
        arg0->brain->unk400 = 0.6f;
        arg0->brain->aggression = 0.75f;
        arg0->brain->unk610 = 1;
        arg0->brain->unk4A0 = 0x4B0;
        arg0->brain->unk580 = 0x2D;
        arg0->brain->unk588 = 0x12FC;
        arg0->brain->unk5D8 = 1;
block_19:
        arg0->driver->unk2AC = 0;
        break;
    case 4:
        var_6 = 1;
        var_4 = (AIBrain* )0x1E;
        var_5 = 2.102e-42f;
        arg0->brain->unk3E4 = 3.0f;
        var_7 = 4;
        arg0->brain->unk400 = 0.1f;
        arg0->brain->aggression = 0.05f;
        arg0->brain->unk610 = 1;
        arg0->brain->unk580 = 0x1E;
        arg0->brain->aggrScale = 0.2f;
        arg0->brain->unk588 = 0x5DC;
        arg0->brain->unk408 = 0x3F4CCCCD;
        arg0->brain->unk58C = 4;
        arg0->brain->unk5DC = 1;
        break;
    case 5:
        var_4 = (AIBrain* )0x5DC;
        var_5 = 1.261e-42f;
        var_8 = 1;
        arg0->brain->unk3E4 = 4.0f;
        var_6 = 0x64;
        var_7 = 0xDD4;
        var_9 = 2;
        arg0->brain->aggression = 0.15f;
        arg0->brain->unk4A0 = 0x5DC;
        arg0->brain->unk498 = 0x384;
        arg0->brain->aggrScale = 0.2f;
        arg0->brain->unk610 = 1;
        arg0->brain->unk580 = 0x64;
        arg0->brain->unk588 = 0xDD4;
        arg0->brain->unk408 = 0x3E4CCCCD;
        arg0->brain->unk58C = 2;
        arg0->brain->unk5DC = 1;
        break;
    case 6:
        var_4 = (AIBrain* )0x708;
        var_5 = 8.41e-43f;
        var_6 = 0xFF0;
        arg0->brain->unk3F0 = 0.7f;
        var_7 = 1;
        arg0->brain->unk400 = 0.75f;
        arg0->brain->unk4AC = 0x708;
        arg0->brain->unk490 = 0x258;
        arg0->brain->aggrScale = 0.6f;
        arg0->brain->aggression = 0.5f;
        arg0->brain->unk60 = 600.0f;
        arg0->brain->unk588 = 0xFF0;
        arg0->brain->unk5D8 = 1;
block_14:
        arg0->driver->unk2AC = 0;
        break;
    case 7:
        var_4 = (AIBrain* )0x384;
        var_5 = 1.68e-43f;
        var_6 = 0x1C20;
        arg0->brain->aggression = 0.27f;
        var_7 = 1;
        var_8 = 0xA8C;
        arg0->brain->unk498 = 0x384;
        arg0->brain->unk580 = 0x78;
        arg0->brain->unk588 = 0x1C20;
        arg0->brain->unk408 = 0x3CF5C28F;
        arg0->brain->unk5DC = 1;
        arg0->brain->unk4A8 = 0xA8C;
        break;
    case 8:
        var_4 = (AIBrain* )0x258;
        var_5 = 4.2e-43f;
        var_6 = 0x4B0;
        arg0->brain->unk3F0 = 0.75f;
        var_7 = 0x78;
        var_8 = 1;
        arg0->brain->unk400 = 0.5f;
        arg0->brain->unk4AC = 0x258;
        arg0->brain->unk490 = 0x12C;
        arg0->brain->unk408 = 0x3CA3D70A;
        arg0->brain->aggression = 0.5f;
        arg0->brain->unk60 = 1140.0f;
        arg0->brain->unk498 = 0x4B0;
        arg0->brain->unk580 = 0x78;
        arg0->brain->unk5D8 = 1;
        break;
    case 9:
        var_4 = (AIBrain* )0x3C;
        var_5 = 4.792e-42f;
        var_6 = 1;
        arg0->brain->aggression = 0.37f;
        arg0->brain->unk580 = 0x3C;
        arg0->brain->unk588 = 0xD5C;
        arg0->brain->unk5DC = 1;
        goto block_14;
    case 10:
        var_4 = (AIBrain* )0x384;
        arg0->brain->unk4AC = 0x3840;
        var_5 = 2.52e-43f;
        var_6 = 1;
        var_7 = 0x14;
        var_8 = 0x618;
        arg0->brain->unk400 = 0.01f;
        var_9 = 7;
        arg0->brain->aggression = 0.07f;
        arg0->brain->unk4A0 = 0x384;
        arg0->brain->unk498 = 0xB4;
        arg0->brain->unk60 = 1200.0f;
        arg0->brain->aggrScale = 0.05f;
        arg0->brain->unk610 = 1;
        arg0->brain->unk580 = 0x14;
        arg0->brain->unk588 = 0x618;
        arg0->brain->unk408 = 0x3F666666;
        goto block_12;
    case 11:
        var_4 = (AIBrain* )0x1C20;
        var_5 = 4.624e-42f;
        var_6 = 1;
        arg0->brain->unk3F0 = 0.4f;
        var_7 = 0xA8C;
        arg0->brain->unk400 = 0.4f;
        arg0->brain->unk4AC = 0x1C20;
        arg0->brain->aggression = 0.4f;
        arg0->brain->unk60 = 1020.0f;
        arg0->brain->unk588 = 0xCE4;
        arg0->brain->unk610 = 1;
        arg0->brain->unk4A8 = 0xA8C;
        goto block_14;
    case 12:
        var_4 = (AIBrain* )0xA8C;
        var_5 = 7.57e-43f;
        var_6 = 0xF0;
        arg0->brain->unk3F0 = 0.7f;
        var_7 = 0x13B0;
        var_8 = 0x960;
        var_9 = 1;
        arg0->brain->unk400 = 0.75f;
        arg0->brain->unk4AC = 0xA8C;
        arg0->brain->unk490 = 0x21C;
        arg0->brain->aggression = 0.65f;
        arg0->brain->unk60 = 780.0f;
        arg0->brain->unk498 = 0xF0;
        arg0->brain->unk588 = 0x13B0;
        arg0->brain->unk4A8 = 0x960;
        arg0->brain->unk5D8 = 1;
        break;
    case 13:
        var_5 = 1.261e-42f;
        var_4 = (AIBrain* )0x4B0;
        var_6 = 1;
        arg0->brain->unk3F0 = 1.5f;
        var_7 = 0x111C;
        arg0->brain->unk400 = 0.95f;
        arg0->brain->unk4AC = 0x384;
        arg0->brain->unk490 = 0x4B0;
        arg0->brain->unk3E8 = 2.0f;
        arg0->brain->aggression = 0.85f;
        arg0->brain->unk60 = 720.0f;
        arg0->brain->unk4A0 = 0x384;
        arg0->brain->aggrScale = 0.65f;
        arg0->brain->unk610 = 1;
        arg0->brain->unk588 = 0x111C;
        break;
    case 14:
        var_4 = (AIBrain* )0x258;
        var_6 = 0x384;
        var_7 = 0x10E0;
        arg0->brain->unk3F0 = 0.9f;
        var_5 = 1e-45f;
        arg0->brain->unk400 = 0.75f;
        arg0->brain->unk4AC = 0x258;
        arg0->brain->unk490 = 0x258;
        arg0->brain->aggression = 0.6f;
        arg0->brain->unk60 = 900.0f;
        arg0->brain->unk4A0 = 0x384;
        arg0->brain->unk588 = 0x10E0;
        arg0->brain->unk610 = 1;
        arg0->brain->unk5D8 = 1;
        goto block_19;
    case 15:
    case 16:
    case 17:
        var_4 = (AIBrain* )0x12C;
        var_5 = 8.41e-43f;
        var_6 = 1;
        arg0->brain->unk3F0 = 1.5f;
        arg0->brain->unk400 = 0.75f;
        arg0->brain->unk4AC = 0x12C;
        arg0->brain->unk490 = 0x258;
        arg0->brain->aggression = 1.0f;
        arg0->brain->unk60 = 180.0f;
        arg0->brain->unk4A0 = 0x258;
        arg0->brain->unk610 = 1;
        goto block_19;
    }
    temp_f13 = arg0->brain->aggrScale;
    arg0->brain->healthScore = arg0->health * func_0021F100((bitwise f32) var_4, var_5, var_6, var_7, var_8, var_9, 1, temp_f13 * 0.3f, temp_f13);
    temp_3_2 = arg0->brain;
    temp_3_2->unk38 = (f32) (arg0->turboDrain * temp_3_2->unk3C);
    temp_f13_2 = arg0->brain->unk3E8;
    temp_2 = arg0->brain;
    temp_2->unk3EC = func_0021F100(-temp_f13_2, temp_f13_2);
    temp_4 = arg0->brain;
    temp_f2 = temp_4->unk3EC;
    temp_f1 = temp_4->unk3E4;
    if (fabsf(temp_f2) < temp_f1) {
        if (!(temp_f2 > 0.0f)) {
            temp_4->unk3EC = (f32) -temp_f1;
            /* Duplicate return node #26. Try simplifying control flow for better match */
            return (s32) temp_2;
        }
        temp_4->unk3EC = temp_f1;
        return (s32) temp_2;
    }
    return (s32) temp_2;
}

/* ---- func_00100E88 ---- */
extern s32 D_004FAB54;
extern s32 D_004FAB74;
extern s32 D_004FAB88;
extern s32 D_004FABFC;
extern s32 D_004FAC18;

s32 func_00100E88(Vehicle* arg0, ...) {
    f32 temp_f10;
    f32 temp_f9;
    f32* temp_2;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 temp_4;
    s32 temp_5;
    s32 var_7;
    s32 var_7_2;

    var_7_2 = 0;
    do {
        temp_4 = var_7_2 * 4;
        var_7_2 += 1;
        temp_5 = var_7_2 < 0x23;
        (arg0->brain + temp_4)->unk208 = 0;
        (arg0->brain + temp_4)->unk17C = 1000.0f;
        (arg0->brain + temp_4)->unk64 = 0.13962634f;
        (arg0->brain + temp_4)->unkF0 = 0.5235988f;
        (arg0->brain + temp_4)->unk294 = 0;
        (arg0->brain + temp_4)->unk320 = 0;
    } while (temp_5 != 0);
    var_7 = 0;
    do {
        temp_3 = var_7 * 4;
        var_7 += 1;
        (arg0->brain + temp_3)->unk3AC = 0;
    } while (var_7 < 0xC);
    temp_f9 = (f32) D_004FAB74;
    temp_f10 = (f32) D_004FAB54;
    arg0->brain->weapRange[2] = 1000.0f;
    arg0->brain->weapRange[3] = 1300.0f;
    arg0->brain->weapRange[6] = 500.0f;
    arg0->brain->weapRange[0x27] = 80.0f;
    arg0->brain->weapRange[4] = 900.0f;
    arg0->brain->weapRange[7] = 700.0f;
    arg0->brain->weapRange[5] = 800.0f;
    arg0->brain->weapRange[0x28] = 50.0f;
    arg0->brain->unk6C = 0.17453294f;
    arg0->brain->unk70 = 0.31415927f;
    arg0->brain->unk78 = 0.5235988f;
    arg0->brain->unk74 = 0.2617994f;
    arg0->brain->weapMaxPitch[5] = 1.0471976f;
    arg0->brain->weapMaxPitch[4] = 0.7853982f;
    arg0->brain->weapRange[0x47] = temp_f9;
    arg0->brain->weapRange[0x48] = temp_f10;
    arg0->brain->weapRange[0x49] = temp_f9;
    arg0->brain->weapRange[0x4C] = (f32) D_004FAB88;
    arg0->brain->weapRange[0x4A] = (f32) D_004FABFC;
    arg0->brain->weapRange[0x4D] = (f32) D_004FAC18;
    arg0->brain->weapRange[0x4E] = temp_f10;
    arg0->brain->weapRange[0x4B] = 10.0f;
    temp_3_2 = arg0->group;
    switch (temp_3_2) {
    case 1:
        arg0->brain->weapRange[0x6A] = 0.4f;
        arg0->brain->weapRange[0x6B] = 0.25f;
        arg0->brain->weapRange[0x70] = 0.25f;
        arg0->brain->weapRange[0x6D] = 0.1f;
        arg0->brain->weapRange[1] = 1200.0f;
        arg0->brain->specialAngle = 0.5235988f;
        arg0->brain->weapRange[0x8E] = 0.55f;
        arg0->brain->weapRange[0x8F] = 0.05f;
        arg0->brain->weapRange[0x92] = 0.25f;
        arg0->brain->weapRange[0x95] = 0.15f;
        break;
    case 2:
        arg0->brain->weapRange[0x6A] = 0.4f;
        arg0->brain->weapRange[0x6B] = 0.1f;
        arg0->brain->weapRange[0x6C] = 0.1f;
        arg0->brain->weapRange[0x6E] = 0.25f;
        arg0->brain->weapRange[0x70] = 0.15f;
        arg0->brain->specialAngle = 0.2617994f;
        arg0->brain->weapRange[0x8D] = 0.15f;
        arg0->brain->weapRange[0x92] = 0.7f;
        arg0->brain->weapRange[0x97] = 0.15f;
        break;
    case 3:
        arg0->brain->weapRange[0x6A] = 0.5f;
        arg0->brain->weapRange[0x6E] = 0.15f;
        arg0->brain->weapRange[0x6F] = 0.1f;
        arg0->brain->weapRange[0x6B] = 0.25f;
        arg0->brain->specialAngle = 1.0471976f;
        arg0->brain->weapMaxPitch[1] = 1.0471976f;
        arg0->brain->weapRange[0x8D] = 0.35f;
        arg0->brain->weapRange[0x91] = 0.15f;
        arg0->brain->weapRange[0x92] = 0.15f;
        arg0->brain->weapRange[0x93] = 0.35f;
        break;
    case 4:
        arg0->brain->weapRange[0x6F] = 0.15f;
        arg0->brain->weapRange[0x6D] = 0.2f;
        arg0->brain->weapRange[0x6E] = 0.2f;
        arg0->brain->weapRange[0x6B] = 0.1f;
        arg0->brain->weapRange[0x6C] = 0.15f;
        arg0->brain->weapRange[0x6A] = 0.2f;
        arg0->brain->specialAngle = 0.7853982f;
        arg0->brain->weapMaxPitch[1] = 0.7853982f;
        arg0->brain->weapRange[0x92] = 0.45f;
        arg0->brain->weapRange[0x94] = 0.1f;
        arg0->brain->weapRange[0x96] = 0.45f;
        break;
    case 5:
        arg0->brain->weapRange[0x6B] = 0.4f;
        arg0->brain->weapRange[0x6A] = 0.25f;
        arg0->brain->weapRange[0x6E] = 0.2f;
        arg0->brain->weapRange[0x6D] = 0.15f;
        arg0->brain->specialAngle = 0.5235988f;
        arg0->brain->weapRange[0x8D] = 0.25f;
        arg0->brain->weapRange[0x8E] = 0.5f;
        arg0->brain->weapRange[0x90] = 0.1f;
        arg0->brain->weapRange[0x96] = 0.15f;
        break;
    case 6:
        arg0->brain->weapRange[0x6A] = 0.25f;
        arg0->brain->weapRange[0x6C] = 0.15f;
        arg0->brain->weapRange[0x6B] = 0.2f;
        arg0->brain->weapRange[0x6F] = 0.1f;
        arg0->brain->weapRange[0x70] = 0.3f;
        arg0->brain->weapRange[0x92] = 1.0f;
        break;
    case 7:
        arg0->brain->weapRange[0x6A] = 0.25f;
        arg0->brain->weapRange[0x6E] = 0.3f;
        arg0->brain->weapRange[0x6F] = 0.1f;
        arg0->brain->weapRange[0x70] = 0.05f;
        arg0->brain->weapRange[0x6C] = 0.15f;
        arg0->brain->weapRange[0x6B] = 0.15f;
        arg0->brain->specialAngle = 0.17453294f;
        arg0->brain->weapRange[0x8E] = 0.2f;
        arg0->brain->weapRange[0x8F] = 0.1f;
        arg0->brain->weapRange[0x90] = 0.15f;
        arg0->brain->weapRange[0x92] = 0.1f;
        arg0->brain->weapRange[0x94] = 0.1f;
        arg0->brain->weapRange[0x95] = 0.15f;
        arg0->brain->weapRange[0x96] = 0.1f;
block_21:
        arg0->brain->weapRange[0x97] = 0.1f;
        break;
    case 8:
        arg0->brain->weapRange[0x6C] = 0.2f;
        arg0->brain->weapRange[0x6A] = 0.3f;
        arg0->brain->weapRange[0x6D] = 0.2f;
        arg0->brain->weapRange[0x6E] = 0.2f;
        arg0->brain->weapRange[0x6F] = 0.1f;
        arg0->brain->weapRange[0x8D] = 0.2f;
        arg0->brain->weapRange[0x8F] = 0.1f;
        arg0->brain->weapRange[0x90] = 0.25f;
        arg0->brain->weapRange[0x92] = 0.45f;
        break;
    case 9:
        arg0->brain->weapRange[0x6A] = 0.35f;
        arg0->brain->weapRange[0x6E] = 0.2f;
        arg0->brain->weapRange[0x6D] = 0.2f;
        arg0->brain->weapRange[0x6C] = 0.25f;
        arg0->brain->weapRange[0x24] = 70.0f;
        arg0->brain->specialAngle = 0.17453294f;
        arg0->brain->weapRange[0x8D] = 0.45f;
        arg0->brain->weapRange[0x90] = 0.35f;
        arg0->brain->weapRange[0x92] = 0.2f;
        break;
    case 10:
        arg0->brain->weapRange[0x6A] = 0.5f;
        arg0->brain->weapRange[0x70] = 0.3f;
        arg0->brain->weapRange[0x6E] = 0.15f;
        arg0->brain->weapRange[0x6C] = 0.05f;
        arg0->brain->specialAngle = 0.122173056f;
        arg0->brain->weapMaxPitch[1] = 0.2617994f;
        arg0->brain->weapRange[0x8D] = 0.35f;
        arg0->brain->weapRange[0x8E] = 0.3f;
        arg0->brain->weapRange[0x91] = 0.2f;
        arg0->brain->weapRange[0x92] = 0.15f;
        break;
    case 11:
        arg0->brain->weapRange[0x6A] = 0.6f;
        arg0->brain->weapRange[0x6D] = 0.1f;
        arg0->brain->weapRange[0x6B] = 0.2f;
        arg0->brain->weapRange[0x6F] = 0.05f;
        arg0->brain->weapRange[0x6C] = 0.05f;
        arg0->brain->specialAngle = 3.1415927f;
        arg0->brain->weapRange[0x24] = 0.0f;
        arg0->brain->weapRange[1] = 100.0f;
        arg0->brain->weapRange[0x8D] = 0.5f;
        arg0->brain->weapRange[0x90] = 0.1f;
        arg0->brain->weapRange[0x92] = 0.1f;
        arg0->brain->weapRange[0x97] = 0.3f;
        break;
    case 12:
        arg0->brain->weapRange[0x6A] = 0.5f;
        arg0->brain->weapRange[0x6D] = 0.25f;
        arg0->brain->weapRange[0x6C] = 0.1f;
        arg0->brain->weapRange[0x6E] = 0.15f;
        arg0->brain->weapRange[0x8E] = 0.6f;
        arg0->brain->weapRange[0x90] = 0.1f;
        arg0->brain->weapRange[0x91] = 0.1f;
        arg0->brain->weapRange[0x97] = 0.2f;
        break;
    case 13:
        arg0->brain->weapRange[0x70] = 0.35f;
        arg0->brain->weapRange[0x6B] = 0.2f;
        arg0->brain->weapRange[0x6A] = 0.4f;
        arg0->brain->weapRange[0x6C] = 0.05f;
        arg0->brain->specialAngle = 0.17453294f;
        arg0->brain->weapMaxPitch[1] = 0.34906587f;
        arg0->brain->weapRange[0x8D] = 0.25f;
        arg0->brain->weapRange[0x8E] = 0.1f;
        arg0->brain->weapRange[0x93] = 0.45f;
        arg0->brain->weapRange[0x97] = 0.2f;
        break;
    case 14:
        arg0->brain->weapRange[0x6A] = 0.4f;
        arg0->brain->weapRange[0x6F] = 0.3f;
        arg0->brain->weapRange[0x70] = 0.25f;
        arg0->brain->weapRange[0x6C] = 0.05f;
        arg0->brain->weapRange[0x8D] = 0.55f;
        arg0->brain->weapRange[0x91] = 0.1f;
        arg0->brain->weapRange[0x93] = 0.35f;
        break;
    case 15:
        arg0->brain->weapRange[0x70] = 0.15f;
        arg0->brain->weapRange[0x6B] = 0.15f;
        arg0->brain->weapRange[0x6A] = 0.4f;
        arg0->brain->weapRange[0x6D] = 0.15f;
        arg0->brain->weapRange[0x6C] = 0.15f;
        arg0->brain->specialAngle = 3.1415927f;
        arg0->brain->weapRange[1] = 1000.0f;
        arg0->brain->weapRange[0x8D] = 0.7f;
        arg0->brain->weapRange[0x8E] = 0.1f;
        arg0->brain->weapRange[0x93] = 0.1f;
        goto block_21;
    case 17:
        arg0->brain->weapRange[0x6A] = 0.7f;
        arg0->brain->weapRange[0x6B] = 0.3f;
        arg0->brain->specialAngle = 3.1415927f;
        arg0->brain->weapRange[1] = 500.0f;
        arg0->brain->weapRange[0x8D] = 0.7f;
        arg0->brain->weapRange[0x92] = 0.3f;
        break;
    default:
        arg0->brain->weapRange[0x6A] = 0.8f;
        arg0->brain->weapRange[0x6B] = 0.1f;
        arg0->brain->weapRange[0x6C] = 0.1f;
        arg0->brain->weapRange[0x8D] = 1.0f;
        break;
    }
    temp_3_3 = D_004FA030->levelType;
    if ((temp_3_3 == 4) || (temp_3_3 == 8)) {
        temp_2 = &arg0->brain->weapRange[var_7];
        *temp_2 *= 2.0f;
    }
    return func_00101DF0(arg0, temp_5, arg0, var_7);
}

/* ---- func_00101DF0 ---- */
extern ? D_003156C0;

s32 func_00101DF0(Vehicle* arg0, ...) {
    f32 var_f0;
    s32 temp_4;
    s32 temp_ret;
    s32 var_18;
    s32* var_17;

    var_18 = 1;
    var_17 = &arg0->ammo[1];
    arg0->brain->unk4B8 = 1;
    arg0->brain->unk548 = 1;
    do {
        temp_4 = var_18 * 4;
        (arg0->brain + temp_4)->unk4BC = 0;
        var_f0 = (arg0->brain + temp_4)->unk320 * 10.0f;
        *var_17 = M2C_ERROR(/* Read from unset register $f1 */);
        var_17 += 4;
        if ((var_18 == 5) && ((*D_003156C0.unk3148 & 0x3F0000) == 0x230000)) {
            temp_ret = mathfRand__Fii(0xB, 0xD);
            var_f0 = (bitwise f32) temp_ret;
            arg0->weapSlot[5] = temp_ret;
        }
        var_18 += 1;
    } while (var_18 < 9);
    return (bitwise s32) var_f0;
}

/* ---- func_00101F88 ---- */
? func_00117B90(u8*, s32);                          /* extern */
u8 inputGetInput__Fii(?, ?);                        /* extern */
? vehicleSaveAndClearPadFlags__7Vehicle();          /* extern */
s32 viewGetNumViews__Fv(u32);                       /* extern */
? viewToggleSplitScreen__Fbb(?, ?);                 /* extern */
extern u32* D_00318808;

s32 func_00101F88(Vehicle* arg0, ...) {
    AIBrain* temp_2_2;
    AIBrain* temp_3_3;
    AIBrain* temp_3_4;
    AIBrain* temp_4_4;
    AIBrain* temp_4_5;
    AIBrain* temp_5;
    Driver* temp_2_3;
    Driver* temp_4;
    Driver* temp_4_2;
    Driver* temp_4_3;
    Driver* temp_5_2;
    s32 temp_2;
    s32 temp_3_2;
    u32 temp_3;
    u32 var_4;
    u32** var_2;

    vehicleSaveAndClearPadFlags__7Vehicle();
    var_2 = &D_00318808;
    if (arg0->netRole == 4) {
        temp_3 = *D_00318808;
        if (((temp_3 >> 5) & 1) != 1) {
            goto block_8;
        }
        var_2 = (u32** ) (temp_3 & 1);
        if (var_2 != NULL) {
block_8:
            if (arg0->driver->mode == 3) {
                arg0->pad[0x11] = 0;
            }
            var_4 = arg0->group - 1;
            if (var_4 < 0x11U) {
                var_4 = *((var_4 * 4) + &jtbl_004DEF80);
                switch (var_4) {                    /* unable to parse jump table */
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 16:
                    arg0->pad[0x11] = 0;
                    break;
                }
            }
            arg0->brain->wantTurbo = 0;
            if ((arg0->isLocalHuman != 0) && (viewGetNumViews__Fv(var_4) >= 2) && (D_004FA030->singlePlayer == 0)) {
                arg0->pad[1] = inputGetInput__Fii(1, 1);
                temp_3_2 = inputGetInput__Fii(0x40, 1) != 0;
                if (arg0->unk489 != 0) {
                    if (temp_3_2 != 0) {
                        if ((s8) arg0->pad[1] != 0) {
                            func_00117B90(D_004FA030->camera, arg0->viewIdx);
                            arg0->unk489 = 0;
                            goto block_22;
                        }
                    } else {
                        goto block_23;
                    }
                } else {
                    if (temp_3_2 == 0) {
                        arg0->unk489 = 1;
                    }
block_22:
block_23:
                    if (((s8) arg0->pad[1] != 0) && ((s8) arg0->unk5A7 == 0)) {
                        if (inputGetInput__Fii(0x80, 1) == 0) {
                            arg0->pad[1] = 0;
                        } else {
                            viewToggleSplitScreen__Fbb(1, 0);
                            D_004FA030->numViews = viewGetNumViews__Fv();
                        }
                    }
                }
            }
            temp_5 = arg0->brain;
            temp_5->ticks430 += arg0->frameTicks;
            arg0->_pad48A[3] = 0;
            func_001054E8(arg0);
            aiUpdateAttack__7Vehicle(arg0);
            temp_4 = arg0->driver;
            if (temp_4->mode != 0) {
                if ((arg0->brain->tasActive != 0) && (temp_4->performing == 0)) {
                    temp_4->turning = 0;
                    arg0->driver->following = 0;
                    arg0->driver->performing = 1;
                }
                if (aiOkToHuntUsingLOS__7Vehicle(arg0) == 0) {
                    temp_2_3 = arg0->driver;
                    if (temp_2_3->minSpeed < 0.36666667f) {
                        temp_2_3->minSpeed = 0.36666667f;
                    }
                    func_0012E798(arg0->driver);
                } else {
                    aiHuntUsingLOS__7Vehicle(arg0);
                    temp_4_2 = arg0->driver;
                    temp_4_2->ticks228 += arg0->frameTicks;
                    temp_5_2 = arg0->driver;
                    temp_5_2->ticks244 += arg0->frameTicks;
                }
            }
            if (arg0->unk17A0 < 3) {
                if (arg0->onGround != 0) {
                    temp_3_3 = arg0->brain;
                    if (temp_3_3->unk470 == 0) {
                        if (arg0->speedRatio > 0.17f) {
                            temp_3_3->unk470 = temp_3_3->unk474;
                        }
                        goto block_53;
                    }
                    goto block_54;
                }
                goto block_53;
            }
            if (arg0->framesSinceX >= 0x3C) {
                if (arg0->unk1F08 == 0) {
                    temp_4_3 = arg0->driver;
                    arg0->pad[2] = 1;
                    arg0->pad[0xA] = temp_4_3->_pad2A4[0];
                    arg0->pad[8] = 1;
                    arg0->pad[4] = 0;
                    arg0->pad[9] = (s32) temp_4_3->unk2A4 ^ 1;
                    arg0->pad[7] = 0;
                }
            } else {
                arg0->pad[0xA] = 0;
                arg0->pad[9] = 0;
                arg0->pad[4] = 0;
                arg0->pad[7] = 0;
            }
block_53:
            if (arg0->brain->unk470 != 0) {
block_54:
                if ((arg0->driver->speedLimit * 0.6f) < arg0->throttle) {
                    arg0->pad[4] = 0;
                    arg0->pad[7] = 0;
                }
                temp_4_4 = arg0->brain;
                temp_4_4->unk470 -= arg0->frameTicks;
                temp_3_4 = arg0->brain;
                if (temp_3_4->unk470 < 0) {
                    temp_3_4->unk470 = 0;
                }
            }
            if (arg0->pad[7] == 0) {
                temp_2_2 = arg0->brain;
                temp_2_2->unk48C = 0;
                return (s32) temp_2_2;
            }
            temp_4_5 = arg0->brain;
            temp_2 = temp_4_5->unk48C + arg0->frameTicks;
            temp_4_5->unk48C = temp_2;
            arg0->unk420 = 100.0f;
            return temp_2;
        }
        goto block_7;
    }
block_7:
    arg0->unk420 = 100.0f;
    return (s32) var_2;
}

/* ---- func_00102360 ---- */
? vehicleInitJump__7Vehicle9_jumpType(Vehicle*, ?); /* extern */
? vehicleSaveAndClearPadFlags__7Vehicle();          /* extern */

s32 func_00102360(Vehicle* arg0, ...) {
    AIBrain* temp_4;
    AIBrain* temp_5;
    s32 temp_5_2;
    u8 temp_2;
    u8 var_2;

    vehicleSaveAndClearPadFlags__7Vehicle();
    temp_2 = arg0->_pad49C[0xC];
    var_2 = temp_2 - 1;
    if (temp_2 != 0) {
        arg0->_pad49C[0xC] = var_2;
    } else {
        temp_4 = arg0->brain;
        temp_4->unk57C = (s32) (temp_4->unk57C + arg0->frameTicks);
        if ((s8) arg0->_pad498[2] == 0) {
            var_2 = (u8) (s8) arg0->pad[2];
            goto block_10;
        }
        temp_5 = arg0->brain;
        if (temp_5->unk580 < temp_5->unk57C) {
            arg0->pad[2] = 1;
            temp_5_2 = temp_5->unk580;
            arg0->brain->unk57C = mathfRand__Fii(0, (s32) (temp_5_2 + ((u32) temp_5_2 >> 0x1F)) >> 1);
        }
        var_2 = (u8) (s8) arg0->pad[2];
        if ((s8) arg0->_pad498[2] != 0) {
            if (var_2 != 0) {
                arg0->_pad498[2] = 0;
                vehicleInitJump__7Vehicle9_jumpType(arg0, 3);
                var_2 = arg0->unk458 + 0xD;
                arg0->unk458 = (s32) var_2;
                arg0->unk45C = (s32) (arg0->unk45C + 0xD);
                arg0->unk2288 = (s32) (arg0->unk2288 - 0x14);
            }
        } else {
block_10:
            if (var_2 == 0) {
                var_2 = 1;
                arg0->_pad498[2] = 1;
            }
        }
    }
    return (s32) var_2;
}

/* ---- func_00102948 ---- */
? boundFAngle__FPf(f32*);                           /* extern */

s32 func_00102948(Vehicle* arg0, ...) {
    f32 sp0;
    f32 sp4;
    AIBrain* temp_3;
    AIBrain* temp_3_3;
    AIBrain* temp_3_4;
    AIBrain* temp_3_5;
    AIBrain* temp_3_6;
    AIBrain* temp_4_4;
    Driver* temp_4;
    Driver* temp_4_2;
    Driver* temp_5;
    f32 temp_f1;
    f32 var_f20;
    s32 temp_3_2;
    s32 temp_4_3;
    s32 var_17;
    s32 var_18;
    s32 var_2;
    s32 var_2_2;

    temp_3 = arg0->brain;
    if (temp_3->unk5D0 != 0) {
        var_f20 = 1.0471976f;
        sp0 = arg0->driver->heading48 - arg0->cs->unk68;
        boundFAngle__FPf(sp);
        temp_3_2 = D_004FA030->levelType;
        if ((temp_3_2 == 4) || (temp_3_2 == 8)) {
            var_f20 = 0.122173056f;
        }
        if (var_f20 < fabsf(sp0)) {
            arg0->pad[4] = 0;
            arg0->pad[8] = 1;
        }
        temp_4 = arg0->driver;
        func_00130D68(temp_4, temp_4->heading48);
        var_2 = func_00130C50(arg0->driver);
        if (var_2 != 0) {
            arg0->brain->tasActive = 0;
            arg0->brain->unk34 = 0;
            arg0->brain->tasTicks = 0;
            arg0->driver->turning = 0;
            arg0->driver->following = 1;
            var_2 = (s32) arg0->driver;
            var_2->unk258 = 0;
            arg0->brain->unk5D0 = 0;
            if (arg0->throttle < (arg0->cruiseSpeed * 0.5f)) {
                if (fabsf(sp0) < var_f20) {
                    arg0->pad[4] = 1;
                }
            }
        }
    } else if ((temp_3->range18 < 100.0f) && (arg0->throttle > 0.36666667f)) {
        temp_4_2 = arg0->driver;
        arg0->pad[8] = 1;
        arg0->pad[4] = 0;
        var_2 = func_00130D68(temp_4_2, temp_4_2->heading48);
    } else {
        var_2 = (s32) arg0->driver;
        var_18 = 0;
        if (var_2->unkB4->unk49B == 0) {
            if (arg0->brain->ramming == 0) {
                func_00130598((Driver* ) var_2, 1);
                if (arg0->brain->range18 < 100.0f) {
                    arg0->pad[4] = 0;
                    arg0->pad[8] = 1;
                }
            }
            temp_3_3 = arg0->brain;
            var_17 = 0;
            if ((temp_3_3->ramming != 0) || ((temp_5 = arg0->driver, (temp_3_3->okToAttack != 0)) && (temp_5->targetReachable != 0)) || (temp_f1 = temp_5->unk1F8, (fabsf(temp_5->unk54) < temp_f1))) {
                var_17 = 1;
                aiDriveToAttackRange__7Vehicle(arg0);
            } else {
                if (temp_f1 > 15.0f) {
                    arg0->_pad48A[1] = 1;
                    arg0->pad[8] = 1;
                    arg0->pad[2] = 1;
                } else {
                    arg0->pad[8] = 1;
                }
                temp_3_4 = arg0->brain;
                if (temp_3_4->weapRange[temp_3_4->weapon] < temp_3_4->targetDist) {
                    temp_3_4->tasDuration = 0;
                }
            }
            if ((var_17 != 0) || (arg0->throttle < 0.07333333f)) {
                sp4 = arg0->cs->unk68 + arg0->brain->targetBearing;
                boundFAngle__FPf(&sp4);
                func_00130D68(arg0->driver, sp4);
            }
            temp_4_3 = arg0->unk21B0;
            if ((temp_4_3 != 5) || (arg0->weapSlot[5] != 0xD)) {
                if (arg0->character != 0xC0) {
                    goto block_42;
                }
                if (temp_4_3 != 1) {
block_42:
                    if (arg0->unk2128 == 0) {
                        var_2_2 = arg0->brain->tasWeapon - 1;
                        goto block_44;
                    }
                } else {
                    goto block_40;
                }
            } else {
block_40:
                temp_3_5 = arg0->brain;
                var_2_2 = 2;
                if (temp_3_5->tasDuration <= 0) {
                    temp_3_5->tasWeapon = 0;
                } else {
block_44:
                    arg0->brain->tasWeapon = var_2_2;
                }
            }
            temp_4_4 = arg0->brain;
            temp_4_4->tasDuration -= arg0->frameTicks;
            temp_3_6 = arg0->brain;
            if (((temp_3_6->tasDuration < 0) || (temp_3_6->tasWeapon <= 0) || (var_2 = temp_3_6->attackState < 6, (var_2 != 0))) && ((var_2 = 0x140, (arg0->character != 0x140)) || (var_2 = arg0->specialHold < 0x12, (var_2 != 0)))) {
                goto block_50;
            }
        } else {
block_50:
            var_18 = 1;
        }
        if (var_18 != 0) {
            driverGetNewPointInFrontOfVehicle__6DriverP7Vehicle(arg0->driver, arg0);
            arg0->driver->turning = 0;
            arg0->driver->following = 0;
            arg0->driver->performing = 1;
            var_2 = (s32) arg0->brain;
            var_2->unk5D0 = 1;
            arg0->brain->tasDuration = 0;
        }
    }
    return var_2;
}

/* ---- func_00102D78 ---- */
? aiGetBestPointToBeDrivingNow__7Vehicle(Vehicle*); /* extern */
f32 atan2f(AIBrain*, void*, AIBrain*, void*);       /* extern */
s32 attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector(void*, void*); /* extern */
s32 boundFAngle__FPf(f32*, Driver*, f32);           /* extern */
? func_0021D258(FMATRIX*, u8*, FVECTOR*);           /* extern */
f32 mathfManhatDist2D__FP8_fvectorT0(FVECTOR*, FVECTOR*, Driver*, void*); /* extern */
? vehicleInitJump__7Vehicle9_jumpType(Vehicle*, ?, void*, ?, f32); /* extern */

s32 func_00102D78(Vehicle* arg0, ...) {
    FVECTOR sp10;
    s128 sp20;
    f32 sp30;
    ? sp34;
    f32 sp38;
    f32 sp3C;
    AIBrain* temp_3;
    AIBrain* temp_4_7;
    AIBrain* temp_4_8;
    Driver* temp_2;
    Driver* temp_2_2;
    Driver* temp_2_3;
    Driver* temp_2_4;
    Driver* temp_3_3;
    Driver* temp_4;
    Driver* temp_4_2;
    Driver* temp_4_3;
    Driver* temp_4_4;
    Driver* temp_4_5;
    Driver* temp_4_6;
    Driver* temp_5;
    Driver* temp_5_2;
    Driver* temp_5_4;
    Driver* temp_5_5;
    Driver* temp_6;
    Driver* temp_6_2;
    Driver* temp_6_3;
    Driver* var_2;
    FVECTOR* temp_17;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f12;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f4;
    f32 var_f20;
    f32 var_f20_2;
    f32 var_f20_3;
    f32 var_f22;
    s32 temp_3_2;
    s32 temp_6_4;
    s32 var_19;
    s32 var_20;
    s32 var_21;
    s32 var_22;
    void* temp_5_3;
    void* temp_6_5;
    void* temp_7;

    var_22 = 1;
    var_21 = 0;
    temp_3 = arg0->brain;
    var_20 = 0;
    if ((temp_3->specialActive != 0) && ((temp_3_2 = temp_3->weapon, (temp_3_2 == 5)) || ((temp_3_2 == 1) && (arg0->character == 0xC0)))) {
        return func_00103888(arg0);
    }
    temp_4 = arg0->driver;
    if (temp_4->subState != 1) {
        goto block_12;
    }
    if (temp_4->nextPoint != temp_4->pointA) {
block_12:
        if ((arg0->driver->mode == 5) && (arg0->driver->subState == 3)) {
            temp_4_2 = arg0->driver;
            if (temp_4_2->group == attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector(arg0->driver->points, arg0->brain->targetCs + 0x10)) {
                temp_f0 = mathfManhatDist__FP8_fvectorT0(temp_4_2->targetPos, &arg0->pos);
                if (temp_f0 < arg0->driver->dist4C) {
                    M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($v0) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($s1) */);
                    M2C_ERROR(/* unknown instruction: vsub.xyz $vf11, $vf11, $vf12 */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf11, ($sp) */);
                    arg0->driver->heading48 = atan2f(sp0, sp4);
                    arg0->driver->dist4C = temp_f0;
                    if ((arg0->nearHuman != 0) && (arg0->brain->unk5C4 == 0)) {
                        arg0->brain->pickup = aiCheckForPickup__7Vehicle(arg0);
                        var_20 = arg0->brain->pickup;
                    }
                }
            }
        }
        if (var_20 != 0) {
            arg0->driver->unk274 = 0;
            arg0->driver->unk248 = 1;
            temp_4_3 = arg0->driver;
            temp_4_3->goalPos = temp_4_3->targetPos;
            arg0->driver->dist4C = mathfManhatDist2D__FP8_fvectorT0(arg0->driver->targetPos, &arg0->pos, (Driver* )1);
            var_2 = arg0->driver;
            temp_f0_2 = var_2->speedLimit;
            if (!(temp_f0_2 > 0.36666667f)) {
                var_2->minSpeed = 0.36666667f;
            } else {
                var_2->minSpeed = temp_f0_2;
            }
            goto block_122;
        }
        var_19 = 0;
        if (arg0->brain->thinkToken != 0) {
            M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($v1) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($a0) */);
            M2C_ERROR(/* unknown instruction: vsub.xyz $vf11, $vf11, $vf12 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf11, 0x10($sp) */);
            if (mathfManhatDist2D__FP8_fvectorT0(&sp10, NULL, (Driver* )1) > 20.0f) {
                arg0->brain->aimPoint = (s128) arg0->driver->target->pos;
                aiGetBestPointToBeDrivingNow__7Vehicle(arg0);
            }
        }
        temp_5 = arg0->driver;
        temp_f22 = temp_5->dist4C - temp_5->unk194;
        if ((temp_5->unk218 < 3) && (temp_5->unk294 != 0) && (arg0->brain->thinkToken != 0) && (arg0->unk1A90 == 0) && (temp_5->distSincePoint > 100.0f)) {
            sp30 = arg0->cs->unk68 - temp_5->heading48;
            boundFAngle__FPf(&sp30, temp_5);
            if (fabsf(sp30) < 0.05235988f) {
                driverGetInitialGuessNextPoint__6Driver(arg0->driver);
                temp_6 = arg0->driver;
                temp_7 = temp_6->points;
                temp_17 = *temp_7 + (temp_6->curPoint << 5);
                if ((temp_17->unk1C >= 2) && (((temp_7 + (temp_6->group * 4))->unk8 + temp_17->unk1D)->unkB0 == -1)) {
                    temp_2 = arg0->driver;
                    temp_f20 = mathfManhatDist2D__FP8_fvectorT0(temp_6->targetPos, temp_17, temp_6, temp_7);
                    temp_6_2 = *temp_2->points;
                    if (temp_f20 < mathfManhatDist2D__FP8_fvectorT0(temp_2->targetPos, temp_6_2 + (temp_2->pointA << 5), temp_6_2)) {
                        sp10 = (s128) arg0->pos;
                        sp10.z = sp10.z + arg0->height + 5.0f;
                        sp20 = (s128) temp_17->unk0;
                        unksp28 += 5.0f;
                        if (hdLosTest__FP8_fvectorT0P9_hdResulti(&sp10, (FVECTOR* ) &sp20, NULL, 0) != 0) {
                            temp_4_4 = arg0->driver;
                            var_21 = 1;
                            driverGetNextPoint__6Driveri(temp_4_4, temp_4_4->curPoint);
                            driverCalcNextPointTurn__6Driver(arg0->driver);
                            driverGetOffsetFromPoint__6Driver(arg0->driver);
                            arg0->driver->distSincePoint = 0.0f;
                        }
                    }
                }
            }
        }
        if (var_21 == 0) {
            temp_4_5 = arg0->driver;
            var_f20 = temp_4_5->unk194;
            if (temp_4_5->unk248 != 0) {
                var_19 = 1;
            } else {
                temp_f4 = temp_4_5->dist4C;
                if ((temp_f4 < (temp_4_5->unk1B4 * arg0->unk2DC)) || (temp_f4 < (temp_4_5->unk1D0 * 1.2f * arg0->throttle))) {
                    driverGetNextPoint__6Driveri(temp_4_5, -1);
                    driverCalcNextPointTurn__6Driver(arg0->driver);
                    driverGetOffsetFromPoint__6Driver(arg0->driver);
                    temp_6_3 = arg0->driver;
                    if (aiNeedToSlowDown__7VehiclefPf(arg0, &sp34, temp_f22) != 0) {
                        var_f20 = arg0->driver->dist4C + 10.0f;
                    }
                    var_19 = 1;
                    if ((temp_6_3->unk218 != 0) && (temp_6_3->group == (*temp_6_3->points + (temp_6_3->pointA << 5))->unk1D)) {
                        temp_6_3->unk218 = 0;
                    }
                }
            }
            temp_4_6 = arg0->driver;
            if (var_19 != 0) {
                temp_f2 = arg0->throttle;
                temp_f1 = temp_4_6->minSpeed;
                if (temp_f2 < temp_f1) {
                    var_f20 = (temp_4_6->unk194 * temp_f2) / temp_f1;
                }
                if (temp_4_6->unk260 != 0) {
                    if (arg0->brain->sawTarget == 0) {
                        goto block_62;
                    }
                    if (temp_4_6->unk27C != 0) {
                        goto block_62;
                    }
                    if (temp_4_6->unk278 != 0) {
block_62:
                        var_f20 = arg0->driver->unk194;
                    } else {
                        var_f20 = temp_4_6->unk1D0 * temp_f2;
                        temp_4_6->minSpeed = arg0->unk2E0;
                    }
                }
            }
            func_00130598(arg0->driver, 1);
            temp_5_2 = arg0->driver;
            var_f20_2 = var_f20 + fabsf(temp_5_2->unk54) + arg0->throttle;
            if (var_f20_2 < 10.0f) {
                var_f20_2 = 10.0f;
            }
            temp_f12 = temp_5_2->dist4C;
            if (!(temp_f12 < var_f20_2)) {
                if (temp_5_2->unk274 != 0) {
                    arg0->pad[8] = 1;
                    sp30 = arg0->cs->unk68 - temp_5_2->heading48;
                    boundFAngle__FPf(&sp30, temp_5_2, temp_f12);
                    sp38 = arg0->cs->unk68 - arg0->driver->unk5C;
                    boundFAngle__FPf(&sp38);
                    if (fabsf(sp38) < fabsf(sp30)) {
                        var_21 = 1;
                    }
                } else {
                    var_f22 = temp_f12;
                    if (var_20 != 0) {
                        var_f20_3 = temp_5_2->speedLimit;
                    } else {
                        if (arg0->brain->unk5C4 == 0) {
                            arg0->brain->pickup = aiCheckForPickup__7Vehicle(arg0, temp_5_2, temp_f12);
                        }
                        temp_4_7 = arg0->brain;
                        temp_2_2 = arg0->driver;
                        if (temp_4_7->pickup != 0) {
                            temp_5_3 = temp_4_7->targetCs;
                            var_f20_3 = temp_2_2->speedLimit;
                            var_f22 = temp_2_2->dist4C;
                            if (temp_5_3->unkC != 0) {
                                M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($v1) */);
                                M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($v0) */);
                                M2C_ERROR(/* unknown instruction: vsub.xyz $vf11, $vf11, $vf12 */);
                                M2C_ERROR(/* unknown instruction: sqc2 $vf11, ($sp) */);
                                temp_f0_3 = atan2f(temp_4_7, temp_5_3, sp0, sp4);
                                sp30 = arg0->cs->unk68 - temp_f0_3;
                                boundFAngle__FPf(&sp30);
                                if (!(fabsf(sp30) < 0.5235988f)) {
                                    arg0->brain->pickup = 0;
                                } else {
                                    arg0->driver->heading48 = temp_f0_3;
                                }
                            } else {
                                temp_4_7->pickup = 0;
                            }
                        } else {
                            var_f20_3 = temp_2_2->speedLimit;
                            var_f22 = temp_2_2->dist4C - temp_2_2->unk194;
                        }
                    }
                    if (var_f20_3 != 0.0f) {
                        goto block_104;
                    }
                    if (!(var_f22 < 10.0f)) {
block_104:
                        if (arg0->driver->unk248 == 0) {
                            temp_f1_2 = arg0->driver->speedLimit;
                            if (arg0->driver->minSpeed < temp_f1_2) {
                                arg0->driver->minSpeed = temp_f1_2;
                            }
                        }
                        aiCheckSpeed__7Vehiclef(arg0, var_f22);
                    } else {
                        if (arg0->velAlongHeading == 0.0f) {
                            var_22 = 0;
                            driverGetNextPoint__6Driveri(arg0->driver, -1);
                            driverCalcNextPointTurn__6Driver(arg0->driver);
                            driverGetOffsetFromPoint__6Driver(arg0->driver);
                            arg0->driver->performing = 1;
                            arg0->brain->unk34 = 0.0f;
                            arg0->brain->aimPoint = (s128) arg0->driver->target->pos;
                        }
                        arg0->pad[4] = 0;
                        arg0->pad[8] = 1;
                        arg0->pad[7] = 0;
                    }
                }
            } else if (temp_5_2->unk264 == 0) {
                var_21 = 1;
            } else if ((arg0->pos.z < temp_5_2->unk190) || (temp_f12 < 15.0f) || (temp_5_2->unk274 != 0)) {
                temp_3_3 = arg0->driver;
                temp_6_4 = *temp_3_3->points;
                temp_6_5 = temp_6_4 + (temp_3_3->unk204 << 5);
                if ((temp_3_3->unk264 == 1) || (temp_6_5->unk1D != (temp_6_4 + (temp_3_3->curPoint << 5))->unk1D)) {
                    vehicleInitJump__7Vehicle9_jumpType(arg0, 1, temp_6_5, 1, temp_f12);
                }
                var_21 = 1;
                arg0->brain->unk420 = 0x12C;
            }
            temp_5_4 = arg0->driver;
            temp_4_8 = arg0->brain;
            sp3C = temp_5_4->heading48;
            if ((temp_4_8->okToAttack != 0) && (temp_5_4->targetReachable != 0) && (arg0->unk1A64 == 0) && (temp_5_4->mode != 5) && (fabsf(temp_4_8->targetFacing) < 0.7853982f) && (temp_4_8->targetDist < 700.0f)) {
                temp_f1_3 = temp_4_8->targetBearing;
                if (fabsf(temp_f1_3) < 0.7853982f) {
                    sp3C = arg0->cs->unk68 + temp_f1_3;
                    func_0021D258(&arg0->rot, &temp_5_4->target->_pad1E0[0x10], &sp10);
                    sp3C += (bitwise f32) sp10 * 0.17453294f;
                    boundFAngle__FPf(&sp3C);
                }
            }
            func_00130D68(arg0->driver, sp3C);
            sp30 = arg0->driver->heading48 - arg0->cs->unk68;
            var_2 = boundFAngle__FPf(&sp30);
            if (fabsf(sp30) > 0.08726647f) {
                var_2 = arg0->driver;
                temp_f2_2 = var_2->unk54;
                if (fabsf(temp_f2_2) > 2.0f) {
                    var_2 = (Driver* )1;
                    if ((sp30 * temp_f2_2) < 0.0f) {
                        arg0->pad[4] = 0;
                        arg0->pad[8] = 1;
                    }
                }
            }
block_122:
            if (var_21 != 0) {
                goto block_123;
            }
        } else {
block_123:
            temp_5_5 = arg0->driver;
            var_22 = 0;
            temp_5_5->turning = 1;
            sp30 = arg0->cs->unk68 - arg0->driver->unk5C;
            boundFAngle__FPf(&sp30, temp_5_5);
            temp_2_3 = arg0->driver;
            if (fabsf(sp30) < 1.8325958f) {
                temp_2_3->unk1AC = 0.0f;
            } else {
                temp_2_3->unk1AC = (f32) (arg0->throttle - temp_2_3->minSpeed);
            }
            temp_2_4 = arg0->driver;
            temp_f1_4 = arg0->throttle;
            if ((temp_2_4->minSpeed < temp_f1_4) && (temp_f1_4 > 0.36666667f)) {
                temp_2_4->minSpeed = temp_f1_4;
            }
            var_2 = (Driver* )0x12C;
            arg0->brain->unk420 = 0x12C;
        }
        if (var_22 == 0) {
            var_2 = arg0->driver;
            var_2->unk288 = 1;
            arg0->driver->following = 0;
        }
        return (s32) var_2;
    }
    return aiSeekPointAndStop__7Vehicle(arg0);
}

/* ---- func_00103888 ---- */
? boundFAngle__FPf(f32*);                           /* extern */
? func_0021D258(FMATRIX*, u8*, void*);              /* extern */

s32 func_00103888(Vehicle* arg0, ...) {
    f32 sp10;
    AIBrain* temp_3;
    f32 temp_f3;
    f32 temp_f4;
    f32 var_f0;

    temp_3 = arg0->brain;
    temp_f4 = temp_3->targetBearing;
    temp_f3 = arg0->cs->unk68 + temp_f4;
    sp10 = temp_f3;
    if (temp_3->targetDist < 30.0f) {
        if (temp_f4 > 0.0f) {
            var_f0 = temp_f3 - 0.17453294f;
        } else {
            var_f0 = temp_f3 + 0.17453294f;
        }
        sp10 = var_f0;
    }
    func_0021D258(&arg0->rot, &arg0->driver->target->_pad1E0[0x10], sp);
    sp10 += sp0 * 0.17453294f;
    boundFAngle__FPf(&sp10);
    func_00130D68(arg0->driver, sp10);
    return aiDriveToAttackRange__7Vehicle(arg0);
}

/* ---- func_00103F20 ---- */
s32 func_00103F20(Vehicle* arg0, s32 arg1, ...) {
    AIBrain* temp_2;
    AIBrain* temp_4;
    AIBrain* temp_4_2;
    AIBrain* temp_4_3;
    Driver* temp_3;
    f32 temp_f4;
    f32 var_f12;
    s32 var_5;

    var_5 = arg1;
    temp_4 = arg0->brain;
    if ((temp_4->specialActive != 0) && (temp_4->weapon != 4) && (arg0->driver->targetReachable != 0) && (temp_4->okToAttack != 0)) {
        var_f12 = temp_4->unk40;
    } else {
        temp_f4 = arg0->velAlongHeading;
        var_5 = 1;
        if (temp_f4 < 0.1f) {
            temp_4_2 = arg0->brain;
            temp_4_2->unk438 += arg0->frameTicks;
            arg0->pad[8] = 1;
            arg0->_pad48A[1] = 1;
            arg0->pad[4] = 0;
            arg0->pad[7] = 0;
            temp_2 = arg0->brain;
            temp_2->unk5E8 = 0;
            var_f12 = temp_2->unk40;
        } else {
            temp_4_3 = arg0->brain;
            if (temp_4_3->unk5E8 != 0) {
                arg0->pad[4] = 0;
                arg0->pad[8] = 1;
                arg0->_pad48A[1] = 1;
                arg0->_pad48A[3] = 1;
                arg0->pad[7] = 0;
                var_f12 = temp_4_3->unk40;
            } else {
                temp_3 = arg0->driver;
                if (!(temp_3->dist4C < ((temp_f4 / (arg0->unk338 * arg0->unk574 * 0.75f)) * temp_f4 * 0.5f))) {
                    arg0->pad[4] = 1;
                    var_f12 = temp_3->heading48;
                } else {
                    arg0->_pad48A[3] = 1;
                    arg0->pad[8] = 1;
                    arg0->_pad48A[1] = 1;
                    temp_4_3->unk5E8 = 1;
                    arg0->brain->unk438 = 0;
                    var_f12 = arg0->brain->unk40;
                }
            }
        }
    }
    return func_00130D68(arg0->driver, var_5, arg0, var_f12);
}

/* ---- func_00104760 ---- */
? boundFAngle__FPf(void*, AIBrain*);                /* extern */

s32 func_00104760(Vehicle* arg0, ...) {
    f32 sp0;
    AIBrain* temp_3;

    if (D_004FA030->singlePlayer == 0) {
        goto block_11;
    }
    temp_3 = arg0->brain;
    if (temp_3->seesTarget == 0) {
        if (arg0->isLocalHuman != 0) {
            goto block_12;
        }
        if (!(arg0->distNearestHuman < 300.0f)) {
block_12:
            temp_3->unk438 += arg0->frameTicks;
            sp0 = arg0->brain->targetBearing + arg0->cs->unk68;
            boundFAngle__FPf(sp, temp_3);
            func_00130D68(arg0->driver, sp0);
            arg0->pad[7] = 0;
            arg0->pad[8] = 1;
            arg0->pad[4] = 0;
            return 1;
        }
        goto block_10;
    }
block_10:
block_11:
    gamePickCruiseZone__7TheGameP7Vehiclei(D_004FA030, arg0, 0);
    return aiStartTurnToNewCruisePoint__7Vehicle(arg0);
}

/* ---- func_00104848 ---- */
? boundFAngle__FPf(void*, AIBrain*);                /* extern */

s32 func_00104848(Vehicle* arg0, ...) {
    f32 sp0;
    AIBrain* temp_5;
    s32 temp_3;

    temp_5 = arg0->brain;
    temp_3 = temp_5->unk438;
    if (temp_3 < 0x259) {
        temp_5->unk438 = temp_3 + arg0->frameTicks;
        sp0 = arg0->brain->targetBearing + arg0->cs->unk68;
        boundFAngle__FPf(sp, temp_5);
        func_00130D68(arg0->driver, sp0);
        arg0->pad[7] = 0;
        arg0->pad[8] = 1;
        arg0->pad[4] = 0;
        return 1;
    }
    return aiStartTurnToNewCruisePoint__7Vehicle(arg0, temp_5);
}

/* ---- func_001048D0 ---- */
? boundFAngle__FPf(f32*);                           /* extern */

s32 func_001048D0(Vehicle* arg0, ...) {
    f32 sp0;
    f32 sp4;
    Driver* temp_2;
    Driver* temp_2_2;
    Driver* temp_2_3;
    Driver* temp_4;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f3;
    f32 temp_f4;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f1;
    f32 var_f20;
    f32 var_f21;
    s32 var_17;

    var_17 = 0;
    temp_f0 = arg0->driver->heading48 - arg0->cs->unk68;
    sp0 = temp_f0;
    boundFAngle__FPf(sp);
    temp_f0_2 = fabsf(temp_f0);
    if (temp_f0_2 > 1.5707964f) {
        var_f21 = 1.1733333f;
    } else {
        temp_f1 = arg0->driver->speedLimit;
        var_f21 = temp_f1 - ((temp_f1 * temp_f0_2) / 1.5707964f);
    }
    arg0->driver->unk1F0 = 0;
    var_f0 = 0.95f;
    if (arg0->_pad5A8[2] != 0) {
        var_f0 = 1.1f;
    }
    if (arg0->velAlongHeading < (var_f21 * var_f0)) {
        arg0->pad[4] = 1;
    }
    if (fabsf(sp0) > 1.5707964f) {
        arg0->pad[4] = 0;
        arg0->pad[8] = 1;
    }
    func_00130598(arg0->driver, 1);
    temp_4 = arg0->driver;
    var_f20 = temp_4->unk54;
    if ((temp_4->unk248 == 0) && (temp_4->dist4C < ((temp_4->unk1D0 * arg0->throttle) + 30.0f))) {
        driverGetNextPoint__6Driveri(temp_4, -1);
        driverCalcNextPointTurn__6Driver(arg0->driver);
        driverGetOffsetFromPoint__6Driver(arg0->driver);
    }
    temp_2 = arg0->driver;
    temp_f3 = arg0->throttle;
    temp_f2 = temp_2->unk194;
    temp_f1_2 = temp_2->minSpeed;
    temp_f4 = temp_2->dist4C;
    if (temp_f4 < (var_f20 + ((temp_f2 * temp_f3) / temp_f1_2))) {
        if (temp_f3 < (temp_f1_2 * 1.05f)) {
            var_17 = 1;
        } else if (temp_f4 < temp_f2) {
            var_17 = 1;
        } else {
            arg0->pad[4] = 0;
            arg0->pad[8] = 1;
        }
        if (var_17 != 0) {
            driverUpdateNextPoint__6DriverP8_fvector(arg0->driver, 0);
            func_00130598(arg0->driver, 1);
            var_f20 = arg0->driver->unk54;
        }
    }
    temp_2_2 = arg0->driver;
    if (fabsf(var_f20) > 1.0f) {
        temp_f2_2 = arg0->throttle;
        temp_f1_3 = temp_2_2->unk1D0 * temp_f2_2;
        if ((temp_f1_3 != 0.0f) && (temp_f1_3 < temp_2_2->dist4C)) {
            if (temp_f2_2 != 0.0f) {
                var_f0_2 = (var_f20 * -0.017453292f) / temp_f2_2;
            } else {
                var_f0_2 = 1.0471976f;
                if (var_f20 > 0.0f) {
                    var_f0_2 = -1.0471976f;
                }
            }
            temp_2_2->unk1F0 = var_f0_2;
            temp_2_3 = arg0->driver;
            var_f1 = fabsf((var_f20 * 1.0471976f) / (temp_2_3->unk1D0 * var_f21));
            if (var_f1 > 1.0471976f) {
                var_f1 = 1.0471976f;
            }
            temp_f2_3 = temp_2_3->unk1F0;
            if (var_f1 < fabsf(temp_f2_3)) {
                if (!(temp_f2_3 > 0.0f)) {
                    temp_2_3->unk1F0 = (f32) -var_f1;
                } else {
                    temp_2_3->unk1F0 = var_f1;
                }
            }
        }
    }
    sp4 = arg0->driver->heading48 + arg0->driver->unk1F0;
    boundFAngle__FPf(&sp4);
    return func_00130D68(arg0->driver, sp4);
}

/* ---- func_00104DF8 ---- */
s32 pickupGetPickupsWeaponType__7PickupsP3_cs(u8*); /* extern */

s32 func_00104DF8(Vehicle* arg0, s32** arg1, ...) {
    TheGame* temp_2_2;
    f32 temp_f1;
    s32 temp_2;
    s32 var_19;
    s32 var_2;

    var_19 = 0;
    temp_2 = pickupGetPickupsWeaponType__7PickupsP3_cs(&D_004FA030->_pad34890[0x51AB0]);
    temp_2_2 = D_004FA030;
    if (((temp_2 != 5) || (mathfRand__Fii(0, 1) == 0) || (arg0->ammo[5] != 0)) && ((temp_2_2->singlePlayer != 0) || (mathfRand__Fii(0, 3) != 1))) {
        if ((**arg1 & 0xFFFC0000) == 0x4E400000) {
            var_2 = 0;
            if (arg0->health < 50.0f) {
                goto block_12;
            }
        } else if (temp_2 >= 0) {
            temp_f1 = (arg0->brain + (temp_2 * 4))->unk320;
            if (!(temp_f1 > 0.2f)) {
                if (temp_f1 > 0.09f) {
                    var_2 = 0;
                    if (mathfRand__Fii(0, 1) != 0) {
                        goto block_12;
                    }
                } else {
                    goto block_13;
                }
            } else {
                goto block_12;
            }
        } else {
            goto block_13;
        }
    } else {
block_12:
        var_19 = 1;
block_13:
        var_2 = var_19;
    }
    return var_2;
}

/* ---- func_00104FA0 ---- */
s32 attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector(void*, FVECTOR*); /* extern */
f32 attractGetMaxRangeForBeadBetweenGroups__15AttractorPointsii(void*, s32, s32); /* extern */
? boundFAngle__FPf(f32*, AIBrain*);                 /* extern */
? mathfRotationFromVector__FP8_fvectorT0(f32*, FVECTOR*); /* extern */

s32 func_00104FA0(Vehicle* arg0, ...) {
    f32 sp10;
    f32 sp18;
    AIBrain* temp_2_2;
    AIBrain* temp_2_3;
    AIBrain* temp_3;
    AIBrain* temp_3_2;
    AIBrain* temp_3_3;
    AIBrain* temp_3_6;
    AIBrain* temp_4;
    AIBrain* temp_4_3;
    AIBrain* temp_5;
    Driver* temp_2_5;
    Driver* temp_3_4;
    Driver* temp_3_5;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f20;
    f32 temp_f3;
    s32 temp_2;
    s32 temp_2_4;
    s32 temp_5_2;
    s32 var_3;
    s32 var_4;
    void* temp_4_2;

    if (arg0->driver->target != NULL) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($s0) */);
        M2C_ERROR(/* unknown instruction: vsub.xyz $vf11, $vf11, $vf12 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf11, ($sp) */);
        arg0->brain->targetDist = mathfManhatDist__FP8_fvectorT0(sp, NULL);
        temp_f20 = arg0->brain->targetBearing;
        mathfRotationFromVector__FP8_fvectorT0(&sp10, sp);
        arg0->brain->targetBearing = sp18 - arg0->cs->unk68;
        boundFAngle__FPf(&arg0->brain->targetBearing);
        arg0->brain->targetPitch = sp10 - arg0->cs->unk60;
        boundFAngle__FPf(&arg0->brain->targetPitch);
        temp_2_2 = arg0->brain;
        var_3 = 1;
        if (!(fabsf(temp_2_2->targetBearing) < fabsf(temp_f20))) {
            var_3 = 0;
        }
        temp_2_2->unk5F8 = var_3;
        temp_f1 = sp18 - 3.1415927f;
        temp_5 = arg0->brain;
        sp18 = temp_f1;
        temp_5->targetFacing = temp_f1 - arg0->driver->target->cs->unk68;
        boundFAngle__FPf(&arg0->brain->targetFacing, temp_5);
        arg0->brain->unk30 = (f32) (sp10 - arg0->driver->target->cs->unk60);
        boundFAngle__FPf((f32* ) arg0->brain->_pad30);
        temp_3 = arg0->brain;
        var_4 = 1;
        if (!(temp_3->targetDist < 800.0f)) {
            var_4 = 0;
        }
        if ((var_4 != 0) && (temp_3->unk594 == 0)) {
            temp_3->unk614 = 0;
        }
        arg0->brain->unk594 = var_4;
    } else {
        arg0->brain->unk594 = 0;
    }
    aiToPlayerLOSCheck__7Vehicle(arg0);
    temp_4 = arg0->brain;
    if (temp_4->sawTarget == 0) {
        temp_4->unk424 = 0;
    } else {
        temp_4->unk424 += arg0->frameTicks;
    }
    temp_3_2 = arg0->brain;
    if (temp_3_2->sawTarget != 0) {
        temp_3_2->unk428 = 0;
    } else {
        if (!(temp_3_2->targetDist < 700.0f)) {
            goto block_24;
        }
        if (!(fabsf(temp_3_2->targetFacing) < 0.7853982f)) {
block_24:
            arg0->brain->unk428 = (s32) (arg0->brain->unk428 + arg0->frameTicks);
        } else {
            temp_3_2->unk428 = 0;
        }
    }
    temp_3_3 = arg0->brain;
    temp_f1_2 = temp_3_3->unk34;
    if ((temp_f1_2 != 0.0f) && (temp_3_3->ticks430 >= 0x385)) {
        temp_3_3->unk34 = (f32) (temp_f1_2 - 0.05f);
        temp_2_3 = arg0->brain;
        if (temp_2_3->unk34 < 0.0f) {
            temp_2_3->unk34 = 0.0f;
        }
    }
    arg0->driver->group = attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector(arg0->driver->points, &arg0->pos);
    temp_3_4 = arg0->driver;
    if (temp_3_4->mode < 5) {
        goto block_44;
    }
    if (temp_3_4->target == NULL) {
block_44:
        arg0->brain->range18 = 0.0f;
    } else {
        temp_2_4 = attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector(temp_3_4->points, temp_3_4->targetPos);
        temp_3_5 = arg0->driver;
        temp_5_2 = temp_3_5->group;
        temp_4_2 = temp_3_5->points;
        if (temp_5_2 == temp_2_4) {
            arg0->brain->range18 = (temp_4_2 + (((temp_3_5->pointA << 5) + *temp_4_2)->unk1D * 4))->unk8->unk18;
        } else {
            arg0->brain->range18 = attractGetMaxRangeForBeadBetweenGroups__15AttractorPointsii(temp_4_2, temp_5_2, temp_2_4);
        }
        temp_3_6 = arg0->brain;
        if (temp_3_6->ramming == 0) {
            temp_2_5 = arg0->driver;
            temp_f3 = temp_3_6->targetDist;
            if (temp_f3 < temp_2_5->dist4C) {
                if ((temp_f3 * 0.5f) < fabsf(arg0->pos.z - temp_2_5->target->pos.z)) {
                    temp_3_6->range18 = 0.0f;
                }
            }
        }
    }
    temp_4_3 = arg0->brain;
    temp_2 = temp_4_3->tasTicks + arg0->frameTicks;
    temp_4_3->tasTicks = temp_2;
    return temp_2;
}

/* ---- func_001054E8 ---- */
s32 attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector(void*, s32); /* extern */

void func_001054E8(Vehicle* arg0) {
    AIBrain* temp_2;
    AIBrain* temp_4_4;
    AIBrain* temp_5_2;
    Driver* temp_3;
    Driver* temp_3_2;
    Driver* temp_3_3;
    Driver* temp_4_2;
    Vehicle* temp_2_2;
    s32 temp_2_3;
    s32 temp_4;
    s32 temp_5;
    void* temp_4_3;

    temp_2 = arg0->brain;
    temp_2->threat = arg0->health * temp_2->aggression * temp_2->aggression2;
    temp_3 = arg0->driver;
    temp_4 = temp_3->mode;
    switch (temp_4) {                               /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        arg0->pad[8] = 1;
        break;
    case 2:                                         /* switch 1 */
        temp_2_2 = temp_3->target;
        if ((temp_2_2 != NULL) && (temp_2_2->idleTicks > 0x4F1A00)) {
            aiUpdateBaitModeOld__7Vehicle(arg0);
        } else {
            aiUpdateBaitMode__7Vehicle(arg0);
        }
        break;
    default:                                        /* switch 1 */
        if (arg0->brain->sniping != 0) {
            aiUpdateSnipeMode__7Vehicle(arg0);
        } else {
            switch (temp_4) {                       /* switch 2; irregular */
            case 3:                                 /* switch 2 */
                aiUpdateFleeMode__7Vehicle(arg0);
                break;
            case 4:                                 /* switch 2 */
                func_001082C8(arg0);
                break;
            case 5:                                 /* switch 2 */
                func_00108618(arg0);
                break;
            }
        }
        if (arg0->brain->pickupMode != 0) {
            aiUpdatePickupGameMode__7Vehicle(arg0);
        }
        break;
    }
    temp_4_2 = arg0->driver;
    temp_5 = temp_4_2->mode;
    if (temp_5 != arg0->brain->lastMode) {
        if (temp_5 != 3) {
            if (temp_4_2->unk1F4 != 0.33f) {
                temp_4_2->unk1F4 = 0.33f;
            }
        } else {
            aiGetFleeSpot__7Vehiclei(arg0, 1);
            temp_3_2 = arg0->driver;
            temp_2_3 = temp_3_2->nextPoint;
            if (temp_2_3 != 0) {
                temp_4_3 = temp_3_2->points;
                arg0->driver->unk210 = attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector(temp_4_3, *temp_4_3 + (temp_2_3 << 5));
            }
        }
        arg0->brain->lastMode = arg0->driver->mode;
        arg0->brain->unk5D4 = 0;
        arg0->brain->unk45C = 0;
        arg0->brain->unk464 = 0;
        arg0->brain->unk468 = 0;
        arg0->brain->unk46C = 0;
        arg0->brain->sniping = 0;
    }
    arg0->brain->slowDown = 0;
    temp_5_2 = arg0->brain;
    if ((temp_5_2->unk3E0 < arg0->velAlongHeading) && (temp_3_3 = arg0->driver, (temp_3_3->unk27C == 0)) && (temp_3_3->target != NULL)) {
        if (temp_5_2->unk594 != 0) {
            if (temp_3_3->mode == 3) {
                temp_5_2->slowDown = 1;
                return;
            }
            goto block_36;
        }
block_36:
        if (temp_3_3->mode == 5) {
            if (temp_3_3->target->throttle > 0.85555553f) {
                arg0->brain->slowDown = 1;
                return;
            }
            temp_4_4 = arg0->brain;
            if (temp_4_4->unk594 == 0) {
                temp_4_4->slowDown = 1;
            }
        }
    }
}

/* ---- func_00106370 ---- */
s32 func_00106370(Vehicle* arg0, ...) {
    AIBrain* temp_6;
    s32 temp_5;

    temp_6 = arg0->brain;
    if (temp_6->targetDist < 1300.0f) {
        temp_5 = arg0->driver->mode;
        switch (temp_5) {                           /* irregular */
        case 3:
            return func_001065A0(arg0, temp_5, temp_6);
        case 4:
            if ((temp_6->sniping == 0) && (D_004FA030->progressMax > 0.15f) && (D_004FA030->unk9FD60 >= 0x1F)) {
                return func_00106778(arg0, temp_5, temp_6);
            }
        default:
            return func_00106440(arg0, temp_5, temp_6);
        }
    } else {
        return func_00106778(arg0, temp_6);
    }
}

/* ---- func_00106440 ---- */
extern u32* D_00318808;

s32 func_00106440(Vehicle* arg0, ...) {
    s32 temp_16;
    s32 temp_2_2;
    s32 var_16;
    s32 var_18;
    s32 var_19;
    s32 var_2;
    s32* temp_4;
    u32 temp_2;

    var_18 = 0;
    var_19 = 0;
    var_16 = mathfRand__Fii(0, 9);
    arg0->brain->unk480 = 0;
    temp_2 = *D_00318808;
    if ((temp_2 & 0x3F0000) != 0x230000) {
        var_2 = (temp_2 >> 0x10) & 0x3F;
        var_19 = 1;
        arg0->brain->weapon = var_2;
        goto block_8;
    }
loop_3:
    temp_16 = (var_16 >= 9) ? 1 : var_16;
    if (((arg0->brain + (temp_16 * 4))->unk320 != 0.0f) && (aiGoodWeaponToPick__7Vehiclei(arg0, temp_16) != 0)) {
        var_19 = 1;
        arg0->brain->weapon = temp_16;
    }
    if (var_19 == 0) {
        var_18 += 1;
        var_2 = var_18 < 9;
        var_16 = temp_16 + 1;
        if (var_2 == 0) {
block_8:
            if (var_19 != 0) {
                goto block_9;
            }
        } else {
            goto loop_3;
        }
    } else {
block_9:
        aiSetAttackState__7Vehicle12_attackState(arg0, 2);
        if (arg0->brain->weapon == 5) {
            arg0->weapSlot[5] = mathfRand__Fii(0xB, 0xD);
        }
        temp_2_2 = arg0->brain->weapon;
        var_2 = temp_2_2 * 4;
        temp_4 = &arg0->ammo[temp_2_2];
        if (*temp_4 <= 0) {
            var_2 = 1;
            *temp_4 = 1;
        }
    }
    return var_2;
}

/* ---- func_001065A0 ---- */
extern s32* D_00318808;

s32 func_001065A0(Vehicle* arg0, ...) {
    s32 temp_16;
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_3;
    s32 var_16;
    s32 var_18;
    s32 var_19;
    s32 var_2;
    s32 var_2_2;
    s32* temp_4;

    var_18 = 0;
    var_19 = 0;
    var_16 = mathfRand__Fii(0, 0xC);
    arg0->brain->weapon = 0;
    if ((*D_00318808 & 0x3F0000) != 0x230000) {
        arg0->brain->weapon = arg0->unk21B0;
        return aiSetAttackState__7Vehicle12_attackState(arg0, 2, 0x3F0000);
    }
loop_3:
    temp_16 = (var_16 >= 0xC) ? 1 : var_16;
    if (((arg0->brain + (temp_16 * 4))->unk3AC != 0.0f) && (aiGoodRearWeaponToPick__7Vehiclei(arg0, temp_16) != 0)) {
        var_19 = 1;
        arg0->brain->unk480 = temp_16;
    }
    var_18 += 1;
    if (var_19 == 0) {
        temp_2 = var_18 < 0xC;
        var_16 = temp_16 + 1;
        if (temp_2 == 0) {
            return temp_2;
        }
        goto loop_3;
    }
    temp_3 = arg0->brain->unk480;
    switch (temp_3) {
    case 1:
        var_2_2 = 1;
block_17:
        arg0->brain->weapon = var_2_2;
        aiSetAttackState__7Vehicle12_attackState(arg0, 2);
        break;
    case 4:
    case 5:
        var_2_2 = 4;
        goto block_17;
    case 6:
        var_2_2 = 2;
        goto block_17;
    case 7:
        var_2_2 = 7;
        goto block_17;
    case 8:
        var_2_2 = 6;
        goto block_17;
    case 9:
        var_2_2 = 3;
        goto block_17;
    default:
        arg0->brain->weapon = arg0->unk21B0;
        aiSetAttackState__7Vehicle12_attackState(arg0, 2);
        break;
    }
    temp_2_2 = arg0->brain->weapon;
    var_2 = temp_2_2 * 4;
    temp_4 = &arg0->ammo[temp_2_2];
    if (*temp_4 <= 0) {
        var_2 = 1;
        *temp_4 = 1;
    }
    return var_2;
}

/* ---- func_00106778 ---- */
extern u32* D_00318808;

s32 func_00106778(Vehicle* arg0, ...) {
    AIBrain* temp_3;
    s32 temp_2;
    s32 var_2;
    s32 var_2_2;
    s32* temp_4;
    u32 temp_5;

    temp_5 = *D_00318808;
    if ((temp_5 & 0x3F0000) != 0x230000) {
        arg0->brain->weapon = (temp_5 >> 0x10) & 0x3F;
        return aiSetAttackState__7Vehicle12_attackState(arg0, 2);
    }
    temp_3 = arg0->brain;
    if (arg0->character == 0x80) {
        var_2_2 = 1;
    } else {
        var_2_2 = 2;
        if (temp_3->weapRange[0x6C] != 0.0f) {
            var_2_2 = 3;
        }
    }
    temp_3->weapon = var_2_2;
    aiSetAttackState__7Vehicle12_attackState(arg0, 2);
    temp_2 = arg0->brain->weapon;
    var_2 = temp_2 * 4;
    temp_4 = &arg0->ammo[temp_2];
    if (*temp_4 <= 0) {
        var_2 = 1;
        *temp_4 = 1;
    }
    return var_2;
}

/* ---- func_00106888 ---- */
s32 func_00106888(Vehicle* arg0, ...) {
    AIBrain* temp_4;
    AIBrain* temp_6;
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_3;
    s32 temp_5;

    temp_6 = arg0->brain;
    temp_2_3 = temp_6->weapon;
    if (temp_2_3 != 0) {
        temp_5 = arg0->unk21B0;
        if (temp_5 != temp_2_3) {
            temp_3 = temp_6->unk484;
            temp_2_4 = temp_5 - temp_2_3;
            if (temp_3 != 0) {
                temp_6->unk484 = (s32) (temp_3 - arg0->frameTicks);
                temp_4 = arg0->brain;
                temp_2_2 = temp_4->unk484;
                if (temp_2_2 < 0) {
                    temp_4->unk484 = 0;
                    return temp_2_2;
                }
                return temp_2_2;
            }
            if (temp_2_4 <= 0) {
                if (temp_2_4 < -4) {
                    goto block_20;
                }
                goto block_21;
            }
            if (temp_2_4 >= 4) {
block_21:
                arg0->pad[0xE] = 1;
            } else {
block_20:
                arg0->pad[0xD] = 1;
            }
            if (arg0->unk24B4 != 0) {
                if (arg0->unk21B0 == 1) {
                    arg0->brain->unk484 = 0xF0;
                    return 0xF0;
                }
                goto block_26;
            }
block_26:
            temp_2 = arg0->brain->unk474;
            arg0->brain->unk484 = temp_2;
            return temp_2;
        }
        if ((temp_5 == 1) && (arg0->character == 0xC0) && (arg0->unk24B4 == 0)) {
            arg0->pad[0xF] = (u8) temp_5;
            temp_6->unk484 = 0xF0;
        }
        return aiSetAttackState__7Vehicle12_attackState(arg0, 3, temp_6);
    }
    return aiSetAttackState__7Vehicle12_attackState(arg0, 1, temp_6);
}

/* ---- func_00106A00 ---- */
s32 func_00106A00(Vehicle* arg0, ...) {
    AIBrain* temp_7;
    s32 temp_3;
    s32 temp_6;
    s32 temp_8;
    s32 var_2;

    temp_7 = arg0->brain;
    temp_3 = temp_7->unk584;
    temp_6 = D_004FA030->numAIsAlive;
    temp_8 = temp_7->specialTimer;
    var_2 = temp_3 >> 2;
    if (((temp_6 <= 1) ? var_2 : temp_3) < temp_8) {
        var_2 = aiSetAttackState__7Vehicle12_attackState(arg0, 4, temp_6, temp_7, temp_8, arg0);
    }
    return var_2;
}

/* ---- func_00106A60 ---- */
s32 func_00106A60(Vehicle* arg0, ...) {
    AIBrain* temp_3;
    s32 var_2;

    if (aiInWeaponRange__7Vehiclei(arg0, arg0->unk21B0) != 0) {
        var_2 = aiSetAttackState__7Vehicle12_attackState(arg0, 5);
    } else {
        temp_3 = arg0->brain;
        var_2 = temp_3->specialTimer < 0x12D;
        if (var_2 == 0) {
            var_2 = temp_3->unk594;
            if (var_2 != 0) {
                var_2 = aiSetAttackState__7Vehicle12_attackState(arg0, 1);
            }
        }
    }
    return var_2;
}

/* ---- func_00106AC8 ---- */
s32 func_00106AC8(Vehicle* arg0, ...) {
    AIBrain* temp_3;
    s32 var_2;

    temp_3 = arg0->brain;
    if (!(temp_3->targetDist < temp_3->weapRange[temp_3->weapon])) {
        var_2 = aiSetAttackState__7Vehicle12_attackState(arg0, 1);
        /* Duplicate return node #7. Try simplifying control flow for better match */
        return var_2;
    }
    if ((temp_3->noLosTicks < 0xA) || (var_2 = aiUsingNonLOSWeapon__7Vehicle(arg0), (var_2 != 0))) {
        return aiSetAttackState__7Vehicle12_attackState(arg0, 6);
    }
    return var_2;
}

/* ---- func_00106D50 ---- */
? func_0021D258(FMATRIX*, u8*, void*);              /* extern */

s32 func_00106D50(Vehicle* arg0, f32 fparg0, f32 fparg1, ...) {
    AIBrain* temp_2_2;
    AIBrain* temp_4;
    AIBrain* temp_4_2;
    Vehicle* temp_5;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f20;
    s32 temp_2;
    s32 temp_3;
    s32 temp_3_2;
    s32 var_17;
    s32 var_17_2;
    s32 var_18;
    s32 var_2;

    var_18 = 0;
    var_17 = 1;
    if (D_004FA030->progressMax < 0.1f) {
        var_f20 = 0.7f;
        var_f1 = 0.3f;
    } else {
        var_f20 = 3.0f;
        var_f1 = 0.75f;
    }
    if ((fabsf(arg0->steerInput) < var_f1) && ((temp_5 = arg0->driver->target, (temp_5->throttle < var_f20)) || (func_0021D258(&arg0->rot, &temp_5->_pad1E0[0x10], sp), (fabsf(sp0) < var_f20)))) {
        var_17 = 0;
    }
    temp_4 = arg0->brain;
    if ((var_17 == 0) || (var_2 = 0, (temp_4->unk614 == 0))) {
        temp_2 = temp_4->weapon;
        var_f1_2 = temp_4->weapMaxBearing[temp_2];
        if (temp_4->targetDist < 50.0f) {
            var_f1_2 *= 0.5f;
        }
        var_2 = 0;
        if (fparg1 < temp_4->weapMaxPitch[temp_2]) {
            if ((fparg0 < var_f1_2) && ((temp_4->unk614 != 0) || (fparg0 < (var_f1_2 * 0.25f)) || ((var_2 = 0, (temp_4->unk5F8 == 0)) && (fparg0 < var_f1_2)))) {
                arg0->unk2AB4 = 0;
                var_17_2 = 0;
                if (arg0->brain->tasActive == 0) {
                    if (aiIsPlayerLookingAtAIEnoughForAIToShoot__7Vehicle(arg0) == 0) {
                        temp_2_2 = arg0->brain;
                        if (!(temp_2_2->targetDist > 100.0f) || ((u32) (temp_2_2->weapon - 2) >= 2U)) {
                            temp_3 = temp_2_2->weapon;
                            if (temp_3 != 4) {
                                if (temp_3 == 1) {
                                    temp_3_2 = arg0->character;
                                    if ((temp_3_2 != 0x100) && (temp_3_2 != 0x120)) {
                                        goto block_29;
                                    }
                                    goto block_30;
                                }
block_29:
                                if (temp_2_2->weapon == 5) {
                                    goto block_30;
                                }
                            } else {
block_30:
                                goto block_31;
                            }
                        } else {
block_31:
                            var_17_2 = 1;
                            arg0->unk2AB4 = 1;
                        }
                    } else {
                        goto block_21;
                    }
                } else {
block_21:
                    var_17_2 = 1;
                }
                if (var_17_2 != 0) {
                    if (arg0->character == 0x40) {
                        temp_4_2 = arg0->brain;
                        if ((temp_4_2->weapon == 1) && (temp_4_2->okToAttack != 0) && (arg0->driver->targetReachable != 0) && (temp_4_2->targetFacing < 1.0471976f)) {
                            var_17_2 = (temp_4_2->specialTimer <= 0xEF) ? 0 : var_17_2;
                        }
                    }
                    if (var_17_2 != 0) {
                        aiSetAttackState__7Vehicle12_attackState(arg0, 7);
                        var_18 = 1;
                    }
                }
                var_2 = var_18;
            }
        }
    }
    return var_2;
}

/* ---- func_00107048 ---- */
? func_0021D258(FMATRIX*, u8*, void*);              /* extern */

s32 func_00107048(Vehicle* arg0, f32 fparg0, f32 fparg1, ...) {
    AIBrain* temp_5;
    f32 var_f2;
    s32 temp_2;
    s32 var_17;
    s32 var_18;
    s32 var_2;

    var_18 = 0;
    var_17 = 1;
    if (fabsf(arg0->steerInput) < 0.5f) {
        func_0021D258(&arg0->rot, &arg0->driver->target->_pad1E0[0x10], sp);
        if (fabsf(sp0) < 1.5f) {
            var_17 = 0;
        }
    }
    temp_5 = arg0->brain;
    if ((var_17 == 0) || (var_2 = 0, (temp_5->unk614 == 0))) {
        temp_2 = temp_5->unk480;
        switch (temp_2) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
            var_f2 = 0.08726647f;
            break;
        case 2:
        case 4:
        case 10:
        case 11:
            var_f2 = 0.5235988f;
            break;
        default:
            var_f2 = 0.2617994f;
            break;
        }
        if (temp_5->targetDist < 50.0f) {
            var_f2 *= 0.5f;
        }
        var_2 = 0;
        if (fparg1 < 0.2617994f) {
            if (fparg0 < var_f2) {
                arg0->unk2AB4 = 0;
                if (aiIsPlayerLookingAtAIEnoughForAIToShoot__7Vehicle(arg0, temp_5) != 0) {
                    aiSetAttackState__7Vehicle12_attackState(arg0, 7);
                    var_18 = 1;
                }
                var_2 = var_18;
            }
        }
    }
    return var_2;
}

/* ---- func_00107380 ---- */
s32 func_00107380(Vehicle* arg0, ...) {
    AIBrain* temp_2_3;
    AIBrain* temp_3_2;
    AIBrain* temp_4;
    AIBrain* temp_4_2;
    AIBrain* temp_4_4;
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_3;
    s32 temp_3_4;
    s32 temp_4_3;
    s32* temp_3_3;

    arg0->brain->unk590 = 0;
    temp_4 = arg0->brain;
    if (temp_4->wantTurbo == 0) {
        if ((temp_4->targetDist < (temp_4 + (temp_4->weapon * 4))->unk208) && (mathfRand__Fii(0, 1) != 0)) {
            arg0->brain->weapon = 0;
            return aiSetAttackState__7Vehicle12_attackState(arg0, 1);
        }
        if (arg0->unk5B5 == 0) {
            temp_4_2 = arg0->brain;
            arg0->pad[0xF] = 1;
            if (temp_4_2->unk594 != 0) {
                temp_4_2->unk614 = 1;
            }
            if (arg0->brain->fire != 0) {
                arg0->pad[0xF] = func_00107580(arg0);
            }
            if (arg0->pad[0xF] != 0) {
                temp_2_3 = arg0->brain;
                temp_4_3 = temp_2_3->weapon;
                if ((temp_4_3 != 4) && ((temp_3 = arg0->character, (temp_3 != 0x100)) || (temp_4_3 != 1))) {
                    if (temp_3 != 0x120) {
                        goto block_32;
                    }
                    if (temp_4_3 != 1) {
block_32:
                        if (temp_2_3->weapon == 5) {
                            temp_2_3->specialActive = 1;
                        } else if (temp_2_3->weapon != 1) {
                            temp_2_3->specialActive = 0;
                        } else {
                            temp_2_3->specialActive = temp_2_3->weapon;
                        }
                    } else {
                        goto block_31;
                    }
                } else {
block_31:
                    temp_2_3->specialActive = 1;
                    arg0->brain->weapRange[0x98] = mathfManhatDist__FP8_fvectorT0(&arg0->pos, arg0->driver->targetPos);
                }
            }
            aiSetAttackState__7Vehicle12_attackState(arg0, 8);
            temp_4_4 = arg0->brain;
            temp_4_4->unk4B8 = (s32) (temp_4_4->unk4B8 + 1);
            temp_3_2 = arg0->brain;
            temp_3_3 = &temp_3_2->_pad4B8[4] + (temp_3_2->weapon * 4);
            temp_2_2 = *temp_3_3 + 1;
            *temp_3_3 = temp_2_2;
            return temp_2_2;
        }
        return aiSetAttackState__7Vehicle12_attackState(arg0, 1);
    }
    if ((temp_4->tasActive != 0) && (arg0->driver->performing != 0)) {
        temp_3_4 = temp_4->tasWeapon;
        if (temp_3_4 < 2) {
            temp_4->tasWeapon = temp_3_4 + 1;
        }
    }
    if (arg0->brain->wantTurbo != 3) {
        temp_2 = arg0->brain->specialInterval;
        arg0->brain->specialTimer = temp_2;
        return temp_2;
    }
    return aiSetAttackState__7Vehicle12_attackState(arg0, 1);
}

/* ---- func_00107580 ---- */
s32 func_00107580(Vehicle* arg0, ...) {
    AIBrain* temp_2;
    AIBrain* temp_4;
    AIBrain* temp_4_2;
    AIBrain* temp_5;
    f32 temp_f1;
    f32 temp_f2;
    s32 temp_3;
    s32 var_17;
    s32* temp_4_3;

    temp_3 = arg0->brain->unk480;
    var_17 = 0;
    switch (temp_3) {
    case 1:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        var_17 = 1;
        arg0->brain->wantTurbo = 3;
        break;
    case 2:
        arg0->brain->wantTurbo = 4;
        break;
    case 3:
        arg0->brain->wantTurbo = 5;
        break;
    case 4:
        var_17 = 1;
        arg0->brain->wantTurbo = 6;
        temp_f2 = mathfManhatDist__FP8_fvectorT0(&arg0->driver->target->pos, &arg0->pos);
        temp_f1 = arg0->driver->target->throttle;
        temp_2 = arg0->brain;
        if (temp_f1 != 0.0f) {
            temp_2->unk590 = temp_f1;
        } else {
            temp_2->unk590 = temp_f1;
        }
        break;
    case 11:
        temp_4 = arg0->brain;
        if (temp_4->unk4A8 < temp_4->timer4A4) {
            temp_4->wantTurbo = 7;
            arg0->brain->timer4A4 = 0;
        }
        break;
    }
    temp_5 = arg0->brain;
    temp_5->unk548 = (s32) (temp_5->unk548 + 1);
    temp_4_2 = arg0->brain;
    temp_4_3 = &temp_4_2->_pad4B8[0x94] + (temp_4_2->unk480 * 4);
    *temp_4_3 += 1;
    return var_17;
}

/* ---- func_001076E8 ---- */
s32 func_001076E8(Vehicle* arg0, ...) {
    AIBrain* temp_4;
    AIBrain* temp_5;
    f32 temp_f2;
    f32 var_f0;
    f32 var_f2;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_4_2;
    s32 var_2;

    temp_4 = arg0->brain;
    if (temp_4->specialActive != 0) {
        temp_3 = temp_4->weapon;
        if (temp_3 != 4) {
            temp_4_2 = arg0->character;
            if ((temp_4_2 == 0x100) && (temp_3 == 1)) {
                var_2 = func_00108FD8(arg0);
            } else {
                temp_5 = arg0->brain;
                if (temp_4_2 == 0x120) {
                    if (temp_5->weapon == 1) {
                        var_2 = aiCheckShadowDetonation__7Vehicle(arg0, temp_5);
                    } else {
                        goto block_12;
                    }
                } else {
block_12:
                    var_2 = 1;
                    if (temp_5->weapon == 5) {
                        var_2 = aiCheckSkillAttack__7Vehicle(arg0, temp_5);
                    } else if (temp_5->weapon != 1) {
                        temp_5->specialActive = 0;
                    } else {
                        var_2 = aiCheckSpecialWeaponFiring__7Vehicle(arg0, temp_5);
                    }
                }
            }
        } else {
            var_2 = func_00108DD0(arg0);
        }
    } else {
        var_f0 = 0.0f;
        temp_f2 = D_004FA030->progressMax;
        if (temp_f2 != 0.0f) {
            temp_3_2 = D_004FA030->difficulty;
            switch (temp_3_2) {                     /* irregular */
            case 0:
                var_f2 = 4.0f;
                break;
            case 1:
                var_f2 = 2.0f;
                break;
            default:
                var_f2 = 1.0f;
                break;
            }
            if (D_004FA030->numAIsAlive < 2) {
                var_f2 *= 0.25f;
            }
            var_f0 = (f32) arg0->brain->specialInterval * var_f2;
            if (var_f0 < (((f32) temp_4->specialInterval * D_004FA030->progress) / temp_f2)) {

            }
        }
        var_2 = (bitwise s32) var_f0 < arg0->brain->specialTimer;
        if (var_2 != 0) {
            aiSetAttackState__7Vehicle12_attackState(arg0, 1, D_004FA030);
            var_2 = 0x140;
            if (arg0->character == 0x140) {
                var_2 = (s32) arg0->brain;
                if (fabsf(var_2->unk28) < 1.5707964f) {
                    func_00130E88(arg0->driver, 3);
                    gamePickCruiseZone__7TheGameP7Vehiclei(D_004FA030, arg0, 0);
                    arg0->brain->unk4C = 0.0f;
                    arg0->brain->unk45C = 0;
                    var_2 = (s32) arg0->brain;
                    var_2->unk48 = 0;
                }
            }
        }
    }
    return var_2;
}

/* ---- func_00107920 ---- */
extern s32* D_00318808;

s32 func_00107920(Vehicle* arg0, ...) {
    AIBrain* temp_2;
    AIBrain* temp_5;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f2;
    f32 var_f3;
    s32 temp_3;
    s32 var_2;
    s32 var_condition_bit;

    temp_5 = arg0->brain;
    if (temp_5->aimed != 0) {
        var_f3 = fabsf(temp_5->targetBearing);
        if (fabsf(temp_5->targetFacing) > 2.268928f) {
            if (var_f3 < temp_5->unk1C) {
                temp_f2 = temp_5->targetDist;
                var_f0 = 0.034906585f;
                if (!(temp_f2 > 200.0f)) {
                    var_f0 = 0.122173056f - (temp_f2 * 0.034906585f);
                }
                var_condition_bit = var_f0 < var_f3;
                goto block_24;
            }
        } else if (D_004FA030->unk9FDB0 != 0) {
            var_f2 = temp_5->targetDist;
            if ((var_f3 < temp_5->unk1C) && (var_f2 > 300.0f) && (var_f3 < 0.17453294f)) {
                var_f2 *= 0.75f;
                if (var_f3 < 0.08726647f) {
                    var_f2 *= 0.75f;
                }
            }
            if (var_f2 < 300.0f) {
                if (!(var_f2 < 150.0f)) {
                    var_f3 += (var_f3 * 3.0f * (var_f2 - 150.0f)) / 300.0f;
                } else {
                    var_f3 = (var_f3 * 0.25f) + ((var_f3 * 0.75f * var_f2) / 150.0f);
                }
            }
            temp_2 = arg0->brain;
            temp_f1 = temp_2->unk1C;
            if ((var_f3 < temp_f1) && (var_f2 < 500.0f)) {
                temp_f2_2 = temp_2->targetDist;
                var_f0_2 = temp_f1;
                if (!(temp_f2_2 < 25.0f)) {
                    var_f0_2 = 0.017453292f;
                    if (!(temp_f2_2 > 500.0f)) {
                        var_f0_2 = temp_f1 - (((temp_f1 - 0.017453292f) * temp_f2_2) / 500.0f);
                    }
                }
                var_condition_bit = var_f3 < var_f0_2;
block_24:
                if (var_condition_bit) {
                    arg0->ammo[0] = 0;
                    arg0->pad[0x10] = 1;
                }
            }
        }
    }
    temp_3 = *D_00318808 & 0x3F0000;
    var_2 = 0x260000;
    if (temp_3 != 0x230000) {
        var_2 = 0x90000;
        if (temp_3 != 0x260000) {
            var_2 = 0x250000;
            if ((temp_3 != 0x90000) && (temp_3 != 0x250000)) {
                arg0->pad[0x10] = 0;
            }
        }
    }
    return var_2;
}

/* ---- func_001082C8 ---- */
s32 func_0010C458(void*, s32, FVECTOR*);            /* extern */
f32 func_0021F100(f32, f32);                        /* extern */

s32 func_001082C8(Vehicle* arg0, ...) {
    AIBrain* temp_2;
    AIBrain* temp_2_2;
    AIBrain* temp_2_4;
    AIBrain* temp_3;
    AIBrain* temp_4;
    Driver* temp_2_3;
    Driver* temp_4_2;
    f32 temp_f13;
    f32 temp_f1;
    s32 temp_16;
    s32 temp_3_2;
    s32 temp_5;
    s32 var_18;
    s32 var_7;

    temp_4 = arg0->brain;
    temp_4->unk460 = (s32) (temp_4->unk460 + arg0->frameTicks);
    temp_2_2 = arg0->brain;
    temp_f1 = temp_2_2->aggression2;
    if (!(temp_f1 < 1.0f)) {

    } else {
        temp_2_2->aggression2 = temp_f1 + 0.00009259259f;
    }
    var_18 = 0;
    if (D_004FA030->singlePlayer != 0) {
        temp_3 = arg0->brain;
        if (temp_3->healthScore < temp_3->unk4C) {
            var_18 = 1;
        } else if ((temp_3->unk594 != 0) && (temp_3->seesTarget != 0)) {
            var_18 = 1;
        } else if (D_004FA030->numAIsAlive >= 4) {
            if (D_004FA030->levelType == 4) {
                temp_2_3 = arg0->driver;
                if (func_0010C458(temp_2_3->points, temp_2_3->group, temp_2_3->targetPos) < 3) {
                    temp_16 = GetNumAIsHunting__7TheGame(D_004FA030);
                    if ((temp_16 + GetNumAIInBaitMode__7TheGame(D_004FA030)) < 2) {
                        func_00130E88(arg0->driver, 2);
                        arg0->brain->fleeHealth = 0.0f;
                        temp_f13 = arg0->brain->aggrScale;
                        arg0->brain->healthScore = arg0->health * func_0021F100(temp_f13 * 0.3f, temp_f13);
                    }
                }
            }
        } else {
            func_00130E88(arg0->driver, 5);
        }
    }
    if (var_18 == 0) {
        temp_2_4 = arg0->brain;
        var_7 = 0;
        if ((temp_2_4->unk60 < (f32) temp_2_4->unk45C) || (temp_2_4->seesTarget != 0) || ((arg0->isLocalHuman == 0) && (arg0->distNearestHuman < 300.0f))) {
            var_7 = 1;
        }
        temp_4_2 = arg0->driver;
        temp_5 = temp_4_2->pointA;
        temp_3_2 = temp_4_2->nextPoint;
        if ((temp_5 == temp_3_2) || (temp_4_2->curPoint == temp_3_2)) {
            if (var_7 != 0) {
                aiGetFleeSpot__7Vehiclei(arg0, 0, 1, var_7);
                aiStartTurnToNewCruisePoint__7Vehicle(arg0);
            } else if ((temp_5 == temp_3_2) && (temp_4_2->subState != 1)) {
                temp_4_2->subState = 1;
                arg0->brain->unk5E8 = 0;
                arg0->brain->unk438 = 0;
            }
        }
    } else {
        func_00130E88(arg0->driver, 3);
        gamePickCruiseZone__7TheGameP7Vehiclei(D_004FA030, arg0, 0);
        arg0->brain->unk45C = 0;
        arg0->brain->unk4C = 0.0f;
        arg0->brain->unk424 = 0;
    }
    temp_2 = arg0->brain;
    temp_2->timer49C = 0;
    arg0->brain->timer494 = 0;
    return (s32) temp_2;
}

/* ---- func_00108618 ---- */
s32 func_00108618(Vehicle* arg0, ...) {
    AIBrain* temp_3;
    AIBrain* temp_4_3;
    AIBrain* temp_6;
    Driver* temp_4;
    Driver* temp_4_2;
    Driver* temp_4_4;
    Vehicle* temp_2;
    Vehicle* var_2;
    s32 temp_6_2;

    if ((D_004FA030->singlePlayer == 0) || (temp_2 = arg0->driver->target, (temp_2 == NULL)) || !(temp_2->health <= 0.0f)) {
        temp_6 = arg0->brain;
        if (!(temp_6->healthScore < temp_6->fleeHealth)) {
            temp_6_2 = temp_6->cruiseZone;
            if (temp_6_2 != -1) {
                gameClearCruiseZone__7TheGameP7Vehiclei(D_004FA030, arg0, temp_6_2);
            }
            temp_4 = arg0->driver;
            if ((temp_4->targetReachable != 0) && (arg0->brain->ramming == 0) && (temp_4->turning == 0)) {
                if ((temp_4->targetPos != NULL) && (temp_4->subState >= 4)) {
                    aiCheckForBeadOnHuntCs__7Vehicle(arg0);
                }
            } else if (driverMustSnipe__6Driver(arg0->driver) != 0) {
                temp_4_2 = arg0->driver;
                if (temp_4_2->snipe == 0) {
                    driverGetSnipePoint__6Driver(temp_4_2);
                    arg0->driver->snipe = 1;
                }
                if ((arg0->driver->pointA == arg0->driver->nextPoint) && (arg0->driver->subState != 1)) {
                    arg0->driver->subState = 1;
                    arg0->brain->unk5E8 = 0;
                    arg0->brain->unk438 = 0;
                }
            }
        } else {
            goto block_6;
        }
    } else {
block_6:
        func_00130E88(arg0->driver, 3);
        gamePickCruiseZone__7TheGameP7Vehiclei(D_004FA030, arg0, 0);
        arg0->brain->unk45C = 0;
        arg0->brain->unk4C = 0.0f;
        arg0->brain->unk424 = 0;
    }
    temp_4_3 = arg0->brain;
    if ((temp_4_3->ramming != 0) && (temp_4_3->unk490 < arg0->unk18B8) && (temp_4_3->targetDist < 50.0f)) {
        temp_4_3->okToAttack = 0;
    }
    temp_4_4 = arg0->driver;
    var_2 = temp_4_4->target;
    if (var_2 != NULL) {
        var_2 = (Vehicle* ) (var_2->idleTicks > 0x4F1A00);
        if (var_2 != NULL) {
            func_00130E88(temp_4_4, 2);
            temp_3 = arg0->brain;
            if (temp_3->unk5E0 != 0) {
                temp_3->unk5E4 = 1;
                arg0->brain->unk434 = 0;
            }
            var_2 = (Vehicle* ) arg0->driver;
            var_2->unk164 = (s32) (var_2->unk170 + 0x10);
            arg0->brain->unk424 = 0;
        }
    }
    return (s32) var_2;
}

/* ---- func_00108DD0 ---- */
extern f32 D_004FAC14;

s32 func_00108DD0(Vehicle* arg0, ...) {
    AIBrain* temp_2;
    AIBrain* temp_3_2;
    AIBrain* temp_4_3;
    f32 temp_f2;
    f32 temp_ret;
    s32 temp_3;
    s32 temp_3_3;
    s32 temp_4;
    s32 temp_4_2;
    s32 var_2;

    temp_4 = arg0->ammo[0x39];
    if (temp_4 != 0) {
        temp_4_2 = temp_4->unk150;
        if (temp_4_2 != 0) {
            temp_ret = mathfManhatDist__FP8_fvectorT0(temp_4_2 + 0x10, &arg0->pos);
            var_2 = (bitwise s32) temp_ret;
            if (D_004FAC14 < temp_ret) {
                temp_4_3 = arg0->brain;
                temp_3 = temp_4_3->unk590;
                temp_f2 = mathfManhatDist__FP8_fvectorT0(arg0->ammo[0x39]->unk150 + 0x10, &arg0->driver->target->pos);
                if (temp_3 != 0) {
                    temp_4_3->unk590 = (s32) (temp_3 - arg0->frameTicks);
                    temp_3_2 = arg0->brain;
                    var_2 = temp_3_2->unk590;
                    if (var_2 <= 0) {
                        arg0->pad[0xF] = 1;
                        temp_3_2->specialActive = 0;
                        temp_2 = arg0->brain;
                        temp_2->specialTimer = 0;
                        arg0->brain->unk590 = 0;
                        return (s32) temp_2;
                    }
                    /* Duplicate return node #31. Try simplifying control flow for better match */
                    return var_2;
                }
                if ((arg0->unk2AC0 == 0.0f) && (arg0->unk2AC4 == 0.0f)) {
                    if (arg0->unk2AC8 == 0.0f) {
                        var_2 = 0;
                        if (fabsf(temp_4_3->targetFacing) > 1.9198622f) {
                            if (((D_004FAC14 * 0.5f) < temp_f2) && (temp_4_3->weapRange[0x98] < temp_f2)) {
                                var_2 = 1;
                            }
                        } else if (temp_f2 < D_004FAC14) {
                            var_2 = 1;
                        } else if (temp_4_3->weapRange[0x98] < temp_f2) {
                            var_2 = 1;
                        } else {
                            temp_4_3->weapRange[0x98] = temp_f2;
                        }
                        if (var_2 != 0) {
                            var_2 = (s32) arg0->brain;
                            arg0->pad[0xF] = 1;
                            goto block_29;
                        }
                    } else {
                        goto block_11;
                    }
                } else {
block_11:
                    var_2 = (s32) arg0->brain;
                    temp_3_3 = var_2;
                    if ((var_2->unk3DC < temp_f2) && (var_2 = 1, (D_004FAC14 < temp_f2))) {
                        arg0->pad[0xF] = 1;
                        temp_3_3->unk604 = 0;
                        var_2 = (s32) arg0->brain;
                        var_2->unk488 = 0;
                    } else {
                        temp_3_3->unk3DC = temp_f2;
                    }
                }
                goto block_30;
            }
            /* Duplicate return node #31. Try simplifying control flow for better match */
            return var_2;
        }
    }
    var_2 = (s32) arg0->brain;
block_29:
    var_2->unk604 = 0;
    arg0->brain->specialTimer = 0;
block_30:
    return var_2;
}

/* ---- func_00108FD8 ---- */
extern f32 D_004FAC14;

s32 func_00108FD8(Vehicle* arg0, ...) {
    AIBrain* temp_2;
    AIBrain* temp_3_2;
    AIBrain* temp_4_3;
    f32 temp_f2;
    f32 temp_ret;
    s32 temp_3;
    s32 temp_3_3;
    s32 temp_4_2;
    s32 var_2;
    void* temp_4;

    temp_4 = arg0->unk2760;
    if (temp_4 != NULL) {
        temp_4_2 = temp_4->unk150;
        if (temp_4_2 != 0) {
            temp_ret = mathfManhatDist__FP8_fvectorT0(temp_4_2 + 0x10, &arg0->pos);
            var_2 = (bitwise s32) temp_ret;
            if (D_004FAC14 < temp_ret) {
                temp_4_3 = arg0->brain;
                temp_3 = temp_4_3->unk590;
                temp_f2 = mathfManhatDist__FP8_fvectorT0(arg0->unk2760->unk150 + 0x10, &arg0->driver->target->pos);
                if (temp_3 != 0) {
                    temp_4_3->unk590 = (s32) (temp_3 - arg0->frameTicks);
                    temp_3_2 = arg0->brain;
                    var_2 = temp_3_2->unk590;
                    if (var_2 <= 0) {
                        arg0->pad[0xF] = 1;
                        temp_3_2->specialActive = 0;
                        temp_2 = arg0->brain;
                        temp_2->specialTimer = 0;
                        arg0->brain->unk590 = 0;
                        return (s32) temp_2;
                    }
                    /* Duplicate return node #32. Try simplifying control flow for better match */
                    return var_2;
                }
                if ((arg0->unk2AC0 == 0.0f) && (arg0->unk2AC4 == 0.0f)) {
                    if (arg0->unk2AC8 == 0.0f) {
                        var_2 = 0;
                        if (fabsf(temp_4_3->targetFacing) > 1.9198622f) {
                            if (((D_004FAC14 * 0.5f) < temp_f2) && (temp_4_3->weapRange[0x98] < temp_f2)) {
                                var_2 = 1;
                            }
                        } else if (temp_f2 < D_004FAC14) {
                            var_2 = 1;
                        } else if (temp_4_3->weapRange[0x98] < temp_f2) {
                            var_2 = 1;
                        } else {
                            temp_4_3->weapRange[0x98] = temp_f2;
                        }
                        if (var_2 != 0) {
                            var_2 = (s32) arg0->brain;
                            arg0->pad[0xF] = 1;
                            goto block_30;
                        }
                    } else {
                        goto block_11;
                    }
                } else {
block_11:
                    var_2 = (s32) arg0->brain;
                    temp_3_3 = var_2;
                    if ((var_2->unk3DC < temp_f2) && (var_2 = 1, (D_004FAC14 < temp_f2))) {
                        arg0->pad[0xF] = 1;
                        temp_3_3->unk604 = 0;
                        var_2 = (s32) arg0->brain;
                        var_2->unk488 = 0;
                    } else {
                        temp_3_3->unk3DC = temp_f2;
                    }
                }
                goto block_31;
            }
            /* Duplicate return node #32. Try simplifying control flow for better match */
            return var_2;
        }
    }
    var_2 = arg0->unk242C;
    if (var_2 == 0) {
        var_2 = (s32) arg0->brain;
block_30:
        var_2->unk604 = 0;
        arg0->brain->specialTimer = 0;
block_31:
    }
    return var_2;
}

