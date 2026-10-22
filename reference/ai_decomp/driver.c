/* m2c drafts of asm/nonmatchings/tmb/driver (online SCUS-97196) with the named structs of ../ai_decomp/ctx_types.h.
 * Not matching code: for reading. Regenerate: python3 run_m2c.py (paths inside). */

/* ---- driverCalcDistFromLine__6DriverP8_fvectorT1T1 ---- */
? boundFAngle__FPf(void*);                          /* extern */
f32 sqrtf(f32);                                     /* extern */

s32 driverCalcDistFromLine__6DriverP8_fvectorT1T1(Driver* arg0, void* arg1, void* arg2, void* arg3, ...) {
    f32 sp0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;
    f32 var_f0;
    f32 var_f20;

    temp_f5 = arg1->unk0;
    temp_f3 = arg1->unk4;
    temp_f4 = arg2->unk4 - temp_f3;
    temp_f1 = arg2->unk0 - temp_f5;
    temp_f2 = ((arg3->unk4 - temp_f3) * temp_f1) - ((arg3->unk0 - temp_f5) * temp_f4);
    if ((temp_f1 != 0.0f) || (var_f20 = 0.0f, (temp_f4 != 0.0f))) {
        var_f0 = (temp_f1 * temp_f1) + (temp_f4 * temp_f4);
        M2C_ERROR(/* unknown instruction: c1 0x140004 */);
        if (var_f0 != var_f0) {
            var_f0 = sqrtf((temp_f2 * temp_f2) / var_f0);
        }
        var_f20 = var_f0;
    }
    sp0 = arg0->unk58 - arg0->heading48;
    boundFAngle__FPf(sp);
    if (sp0 < 0.0f) {
        var_f20 = -var_f20;
    }
    return (bitwise s32) var_f20;
}

/* ---- driverCalcLookahead__6DriverP8_fvector ---- */
s32 driverCalcLookahead__6DriverP8_fvector(Driver* arg0, s128* arg1, ...) {
    ? sp10;
    Vehicle* temp_4;
    s128 temp_2;

    temp_4 = arg0->target;
    if ((temp_4 != NULL) && (temp_4->throttle != 0.0f) && (mathfManhatDist__FP8_fvectorT0(&temp_4->pos, &arg0->self->pos) > 1000.0f)) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf13, 0x10($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf14, 0x20($v0) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz ACC, $vf12, $vf11x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz ACC, $vf13, $vf11y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf11, $vf14, $vf11z */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf11, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($v1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($v0) */);
        M2C_ERROR(/* unknown instruction: vadd.xyz $vf11, $vf11, $vf12 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf11, ($s1) */);
        return (s32) &sp10;
    }
    temp_2 = arg0->targetCs->unk10;
    *arg1 = temp_2;
    return (s32) temp_2;
}

/* ---- driverCalcNextPointTurn__6Driver ---- */
? boundFAngle__FPf(void*);                          /* extern */
f32 cosf(f32);                                      /* extern */
f32 sinf(f32);                                      /* extern */

s32 driverCalcNextPointTurn__6Driver(Driver* arg0, ...) {
    f32 sp0;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_5;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f2_5;
    f32 temp_f2_6;
    f32 temp_f2_7;
    f32 temp_f2_8;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f3_3;
    f32 temp_f3_4;
    f32 temp_f3_5;
    f32 temp_f3_6;
    f32 temp_f3_7;
    f32 temp_f3_8;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f4_3;
    f32 temp_f5;
    f32 temp_f5_2;
    f32 temp_f5_3;
    f32 temp_f5_4;
    f32 temp_f6;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f0_4;
    f32 var_f1;
    f32 var_f20;
    f32 var_f21;
    f32 var_f2;
    f32 var_f2_2;
    f32 var_f3;
    f32 var_f7;

    if (arg0->unk27C == 0) {
        if ((arg0->unk284 != 0) || (arg0->unk280 != 0)) {
            var_f0 = arg0->self->unk330;
        } else {
            var_f0 = arg0->self->cruiseSpeed;
        }
        arg0->speedLimit = var_f0;
        temp_f2 = arg0->unk50;
        temp_f3 = arg0->unk1B4;
        if (temp_f2 < temp_f3) {
            temp_f0 = (arg0->self->unk330 * temp_f2) / temp_f3;
            if (temp_f0 < arg0->speedLimit) {
                arg0->speedLimit = temp_f0;
            }
            if (arg0->speedLimit < 0.85555553f) {
                arg0->speedLimit = 0.85555553f;
            }
            if (arg0->unk284 != 0) {
                arg0->speedLimit *= 1.3f;
            }
        }
    }
    temp_f0_2 = arg0->unk5C - arg0->selfCs->unk68;
    sp0 = temp_f0_2;
    boundFAngle__FPf(sp);
    var_f21 = fabsf(temp_f0_2);
    if (var_f21 > 2.3561945f) {
        var_f21 = 2.3561945f;
    }
    arg0->minSpeed = 1.0f;
    if (var_f21 > 1.8325958f) {
        var_f7 = 3.0f;
    } else {
        var_f7 = (f32) (((*arg0->points + (arg0->pointA << 5))->unk1C * 8) + 3);
    }
    if (var_f21 < 0.122173056f) {
        temp_f1 = (arg0->unk1D4 * var_f21) / 0.122173056f;
        arg0->unk194 = (arg0->unk1B8 * var_f21) / 0.122173056f;
        var_f20 = temp_f1;
        arg0->unk198 = temp_f1;
    } else {
        if (var_f21 < 0.2617994f) {
            temp_f3_2 = arg0->unk1BC;
            temp_f5 = 0.2617994f - var_f21;
            temp_f2_2 = arg0->unk1D8;
            var_f3 = temp_f3_2 - (((temp_f3_2 - arg0->unk1B8) * temp_f5) / 0.13962634f);
            var_f2 = temp_f2_2 - (((temp_f2_2 - arg0->unk1D4) * temp_f5) / 0.13962634f);
            goto block_35;
        }
        if (var_f21 < 0.5235988f) {
            temp_f3_3 = arg0->unk1C0;
            temp_f4 = 0.5235988f - var_f21;
            temp_f2_3 = arg0->unk1DC;
            var_f3 = temp_f3_3 - (((temp_f3_3 - arg0->unk1BC) * temp_f4) / 0.2617994f);
            var_f2 = temp_f2_3 - (((temp_f2_3 - arg0->unk1D8) * temp_f4) / 0.2617994f);
            goto block_35;
        }
        if (var_f21 < 0.7853982f) {
            temp_f3_4 = arg0->unk1C4;
            temp_f4_2 = 0.7853982f - var_f21;
            temp_f2_4 = arg0->unk1E0;
            var_f3 = temp_f3_4 - (((temp_f3_4 - arg0->unk1C0) * temp_f4_2) / 0.2617994f);
            var_f2 = temp_f2_4 - (((temp_f2_4 - arg0->unk1DC) * temp_f4_2) / 0.2617994f);
            goto block_35;
        }
        if (var_f21 < 1.0471976f) {
            temp_f3_5 = arg0->unk1C8;
            temp_f4_3 = 1.0471976f - var_f21;
            temp_f2_5 = arg0->unk1E4;
            var_f3 = temp_f3_5 - (((temp_f3_5 - arg0->unk1C4) * temp_f4_3) / 0.2617994f);
            var_f2 = temp_f2_5 - (((temp_f2_5 - arg0->unk1E0) * temp_f4_3) / 0.2617994f);
            goto block_35;
        }
        if (var_f21 < 1.308997f) {
            temp_f3_6 = arg0->unk1CC;
            temp_f5_2 = 1.308997f - var_f21;
            temp_f2_6 = arg0->unk1E8;
            var_f3 = temp_f3_6 - (((temp_f3_6 - arg0->unk1C8) * temp_f5_2) / 0.26179945f);
            var_f2 = temp_f2_6 - (((temp_f2_6 - arg0->unk1E4) * temp_f5_2) / 0.26179945f);
            goto block_35;
        }
        if (var_f21 < 1.5707964f) {
            temp_f3_7 = arg0->unk1D0;
            temp_f5_3 = 1.5707964f - var_f21;
            temp_f2_7 = arg0->unk1EC;
            temp_f6 = arg0->unk1E8;
            temp_f1_2 = ((temp_f2_7 - temp_f6) * temp_f5_3) / 0.26179934f;
            var_f20 = temp_f6 - temp_f1_2;
            arg0->unk198 = (f32) (temp_f2_7 - temp_f1_2);
            arg0->unk194 = temp_f3_7 - (((temp_f3_7 - arg0->unk1CC) * temp_f5_3) / 0.26179934f);
        } else if (!(var_f21 < 1.8325958f)) {
            temp_f1_3 = arg0->unk1EC;
            arg0->unk194 = arg0->unk1D0;
            temp_f1_4 = temp_f1_3 + ((temp_f1_3 * (var_f21 - 1.5707964f)) / 1.5707964f);
            arg0->unk198 = temp_f1_4;
            var_f20 = temp_f1_4;
        } else {
            temp_f3_8 = arg0->unk1D0;
            temp_f5_4 = var_f21 - 1.5707964f;
            temp_f2_8 = arg0->unk1EC;
            var_f3 = temp_f3_8 + (((temp_f3_8 - arg0->unk1CC) * temp_f5_4) / 0.26179945f);
            var_f2 = temp_f2_8 + (((temp_f2_8 - arg0->unk1E8) * temp_f5_4) / 0.26179945f);
block_35:
            arg0->unk194 = var_f3;
            var_f20 = var_f2;
            arg0->unk198 = var_f2;
        }
    }
    if (var_f20 == 0.0f) {
        var_f0_2 = arg0->speedLimit;
    } else {
        var_f0_2 = (2.0f * var_f7) / var_f20;
    }
    arg0->minSpeed = var_f0_2;
    if (arg0->unk27C == 0) {
        if (arg0->unk278 == 0) {
            if (arg0->unk284 == 0) {
                if (arg0->unk280 != 0) {
                    var_f0_3 = arg0->minSpeed;
                    var_f1 = 1.3f;
                    goto block_53;
                }
            } else {
                var_f1 = 1.7f;
                var_f0_3 = arg0->minSpeed;
block_53:
                goto block_54;
            }
        } else {
            goto block_45;
        }
    } else {
block_45:
        var_f1 = arg0->self->unk36C;
        if (var_f1 < arg0->minSpeed) {
            var_f0_3 = 0.95f;
block_54:
            arg0->minSpeed = var_f0_3 * var_f1;
        }
    }
    temp_f1_5 = arg0->minSpeed;
    var_f0_4 = 0.36666667f;
    if ((temp_f1_5 < 0.36666667f) || (var_f0_4 = arg0->speedLimit, (var_f0_4 < temp_f1_5))) {
        arg0->minSpeed = var_f0_4;
    }
    temp_f0_3 = sinf(var_f21);
    if (fabsf(temp_f0_3) > 0.15f) {
        var_f2_2 = -((var_f20 / temp_f0_3) * cosf(var_f21));
    } else {
        var_f2_2 = 0.0f;
    }
    temp_f0_4 = (arg0->unk194 + var_f2_2) * arg0->minSpeed;
    arg0->unk194 = temp_f0_4;
    if (temp_f0_4 < 7.0f) {
        arg0->unk194 = 7.0f;
    }
    arg0->unk290 = 1;
    return 1;
}

/* ---- driverCheckDrivingLOS__6Driver ---- */
? func_0021D258(FMATRIX*, u8*, FVECTOR*);           /* extern */
? mathfMatrixFromNormal__FPA3_fP8_fvector(u8*, FVECTOR*); /* extern */
s32 tireIsDrivableSlope__7VehicleP8_fvector(Vehicle*, s128*); /* extern */

s32 driverCheckDrivingLOS__6Driver(Driver* arg0, ...) {
    f32 sp0;
    f32 sp4;
    f32 sp8;
    FVECTOR sp10;
    FVECTOR sp20;
    s128 sp30;
    s128 sp40;
    Vehicle* temp_4;
    f32 temp_f0;
    f32 temp_f3;
    f32 var_f20;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 temp_3_4;
    s32 temp_4_2;
    s32 temp_4_3;
    s32 var_17;
    s32 var_2;

    var_f20 = 0.0f;
    temp_3 = arg0->unk238 + 1;
    arg0->unk238 = temp_3;
    if (temp_3 >= 4) {
        if (temp_3 != 4) {
            arg0->unk238 = 0;
        } else {
            M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($v1) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($v0) */);
            M2C_ERROR(/* unknown instruction: vsub.xyz $vf11, $vf11, $vf12 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf11, ($sp) */);
            var_f20 = mathfManhatDist__FP8_fvectorT0(sp, NULL);
            M2C_ERROR(/* unknown instruction: madd.s $f0, $f3, $f3 */);
            temp_f0 = M2C_ERROR(/* unknown instruction: rsqrt.s $f0, $f4, $f0 */);
            sp0 = M2C_ERROR(/* unknown instruction: mula.s $f1, $f1 */) * temp_f0;
            sp4 = M2C_ERROR(/* unknown instruction: madda.s $f2, $f2 */) * temp_f0;
            sp8 *= temp_f0;
            mathfMatrixFromNormal__FPA3_fP8_fvector(&arg0->_pad50[0x10], sp);
        }
    }
    temp_3_2 = arg0->unk238;
    if (temp_3_2 == 4) {
        sp8 = 3.0f;
        sp4 = arg0->self->unk3C0;
        sp0 = 0.0f;
        M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($v1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf13, 0x10($v1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf14, 0x20($v1) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz ACC, $vf12, $vf11x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz ACC, $vf13, $vf11y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf11, $vf14, $vf11z */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf11, 0x10($sp) */);
    } else {
        sp0 = (arg0 + (temp_3_2 * 4))->unk178;
        sp4 = arg0->self->unk3C0;
        sp8 = 3.0f;
        M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($a0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf13, 0x10($a0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf14, 0x20($a0) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz ACC, $vf12, $vf11x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz ACC, $vf13, $vf11y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf11, $vf14, $vf11z */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf11, 0x10($sp) */);
    }
    temp_4 = arg0->self;
    M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($v1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($v0) */);
    M2C_ERROR(/* unknown instruction: vadd.xyz $vf11, $vf11, $vf12 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf11, 0x10($sp) */);
    temp_f3 = sp4 + 30.0f;
    sp10.z += temp_4->height;
    sp4 = temp_f3;
    if (temp_4->velAlongHeading > 0.0f) {
        sp4 = temp_f3 + (arg0->unk1D0 * temp_4->throttle);
    }
    if (arg0->unk238 != 4) {
        goto block_16;
    }
    if (!(sp4 < var_f20)) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($v1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($v0) */);
        M2C_ERROR(/* unknown instruction: vsub.xyz $vf11, $vf11, $vf12 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf11, 0x20($sp) */);
    } else {
block_16:
        M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf13, 0x10($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf14, 0x20($v0) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz ACC, $vf12, $vf11x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz ACC, $vf13, $vf11y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf11, $vf14, $vf11z */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf11, 0x20($sp) */);
    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($s2) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($v0) */);
    M2C_ERROR(/* unknown instruction: vadd.xyz $vf11, $vf11, $vf12 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf11, 0x20($sp) */);
    sp20.z += arg0->self->height;
    var_17 = hdLosTest__FP8_fvectorT0P9_hdResulti(&sp10, &sp20, &sp30, 0) != 0;
    temp_3_3 = arg0->unk238;
    if (temp_3_3 == 4) {
        if (var_17 == 0) {
            var_17 = (tireIsDrivableSlope__7VehicleP8_fvector(arg0->self, &sp40) != 0) ? 1 : var_17;
        }
        temp_3_4 = arg0->unk23C;
        arg0->unk240 = var_17;
        if (temp_3_4 != 0) {
            var_2 = arg0->unk298;
            if (var_2 == 0) {
                var_2 = temp_3_4 & 9;
                if (var_2 != 0) {
                    func_0021D258(&arg0->self->rot, &arg0->_padBC[0x54], &sp10);
                    func_0021D258(&arg0->self->rot, &arg0->_padBC[0x84], &sp20);
                    var_2 = 1;
                    if (((bitwise f32) sp10 * (bitwise f32) sp20) < 0.0f) {
                        arg0->unk298 = 1;
                        var_2 = mathfRand__Fii(0, 1) != 0;
                        arg0->unk29C = var_2;
                    }
                }
            }
        } else {
            var_2 = arg0->unk298;
            if (var_2 != 0) {
                arg0->unk298 = 0;
            }
        }
    } else if (var_17 != 0) {
        temp_4_2 = arg0->unk23C;
        var_2 = 1;
        if ((temp_4_2 >> temp_3_3) & 1) {
            var_2 = temp_4_2 ^ (1 << temp_3_3);
            arg0->unk23C = var_2;
        }
    } else {
        var_2 = tireIsDrivableSlope__7VehicleP8_fvector(arg0->self, &sp40);
        if (var_2 == 0) {
            temp_4_3 = arg0->unk238;
            arg0->unk23C = (s32) (arg0->unk23C | (1 << temp_4_3));
            ((temp_4_3 * 0x10) + arg0)->unkC0 = (s128) sp30;
            var_2 = (s32) sp40;
            ((arg0->unk238 * 0x10) + arg0)->unk110 = (s128) var_2;
        }
    }
    return var_2;
}

/* ---- driverGetCruiseNextPoint__6Driver ---- */
s32 driverGetCruiseNextPoint__6Driver(Driver* arg0, ...) {
    return driverGetLongRangePoint__6DriverP8_fvectorii(arg0, sp, arg0->pointA, driverGetLookAheadPos__6DriverP8_fvectori(arg0, sp, arg0->unk210));
}

/* ---- driverGetFleeNextPoint__6Driver ---- */
s32 driverGetFleeNextPoint__6Driver(Driver* arg0, ...) {
    return driverGetLongRangePoint__6DriverP8_fvectorii(arg0, sp, arg0->pointA, driverGetLookAheadPos__6DriverP8_fvectori(arg0, sp, arg0->unk210));
}

/* ---- driverGetHuntNextPoint__6Driver ---- */
s32 attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector(void*, FVECTOR*); /* extern */

s32 driverGetHuntNextPoint__6Driver(Driver* arg0, ...) {
    s32 var_2;
    void* temp_4;

    temp_4 = arg0->points;
    if (arg0->unk2AC != 0) {
        var_2 = driverGetLookAheadPos__6DriverP8_fvectori(arg0, sp, attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector(temp_4, arg0->targetPredPos));
    } else {
        var_2 = driverGetLookAheadPos__6DriverP8_fvectori(arg0, sp, attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector(temp_4, arg0->targetPos));
    }
    return driverGetLongRangePoint__6DriverP8_fvectorii(arg0, sp, arg0->pointA, var_2);
}

/* ---- driverGetInitialGuessNextPoint__6Driver ---- */
s32 driverGetInitialGuessNextPoint__6Driver(Driver* arg0, ...) {
    s32 temp_3;
    s32 var_2;

    temp_3 = arg0->mode;
    switch (temp_3) {                               /* irregular */
    case 2:
        var_2 = driverGetHuntNextPoint__6Driver(arg0);
        break;
    case 3:
        var_2 = driverGetFleeNextPoint__6Driver(arg0);
        break;
    case 4:
        var_2 = driverGetCruiseNextPoint__6Driver(arg0);
        break;
    case 5:
        var_2 = driverGetHuntNextPoint__6Driver(arg0);
        break;
    default:
        var_2 = driverGetRandomNextPoint__6Driverb(arg0, 0);
        break;
    }
    arg0->curPoint = var_2;
    return var_2;
}

/* ---- driverGetLongRangePoint__6DriverP8_fvectorii ---- */
s32 driverGetLongRangePoint__6DriverP8_fvectorii(Driver* arg0, FVECTOR* arg1, s32 arg2, ...) {
    FVECTOR* temp_16;
    FVECTOR* temp_16_2;
    f32 temp_f0;
    f32 var_f20;
    s32 temp_17;
    s32 var_18;
    s32 var_21;
    s32 var_2;

    var_18 = driverGetNextClosestPointToLookAheadPos__6DriverP8_fvectorii(arg0);
    temp_16 = *arg0->points + (arg2 << 5);
    var_2 = var_18;
    if (temp_16->unk1C == 5) {
        var_f20 = mathfManhatDist__FP8_fvectorT0(arg1, temp_16);
loop_2:
        temp_16_2 = *arg0->points + (var_18 << 5);
        var_21 = 1;
        if (temp_16_2->unk1C == 5) {
            temp_17 = driverGetNextClosestPointToLookAheadPos__6DriverP8_fvectorii(arg0, arg1, var_18, -1);
            temp_f0 = mathfManhatDist__FP8_fvectorT0(arg1, temp_16_2);
            if (temp_f0 < var_f20) {
                var_18 = temp_17;
                var_f20 = temp_f0;
                var_21 = 0;
            }
        }
        if (var_21 == 0) {
            goto loop_2;
        }
        var_2 = var_18;
    }
    return var_2;
}

/* ---- driverGetLookAheadPos__6DriverP8_fvectori ---- */
? attractGetCenterOfGroup__15AttractorPointsP8_fvectori(void*, s128*, s32, ?); /* extern */
s32 attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector(void*, FVECTOR*, ?); /* extern */
? func_0010C250(void*, s128*, s8, ?);               /* extern */
f32 mathfDist2Squared__FP8_fvectorT0(FVECTOR*, void*, void*); /* extern */
f32 mathfDist2__FP8_fvectorT0(void*, void*);        /* extern */

s32 driverGetLookAheadPos__6DriverP8_fvectori(Driver* arg0, s128* arg1, s32 arg2, ...) {
    s32 sp0;
    f32 temp_f0;
    f32 var_f20;
    f32 var_f21;
    s16 temp_18;
    s16 var_5;
    s16* var_19;
    s32 temp_3;
    s32 temp_4_2;
    s32 var_21;
    s32 var_2_2;
    s8 var_22;
    s8 var_2;
    s8 var_30;
    void* temp_16;
    void* temp_20;
    void* temp_4;

    temp_4 = arg0->points;
    temp_20 = *temp_4 + (arg0->pointA << 5);
    var_22 = temp_20->unk1D;
    if (arg2 == -1) {
        var_5 = -1;
        var_30 = -1;
        var_22 = -1;
    } else if (arg2 == var_22) {
        var_5 = -1;
        var_30 = var_22;
    } else {
        temp_3 = (temp_4 + (var_22 * 4))->unk8;
        var_30 = (temp_3 + arg2)->unkB0;
        var_5 = (temp_3 + (arg2 * 2))->unk20;
        var_22 = (~var_30 == 0) ? -1 : var_22;
    }
    temp_4_2 = arg0->mode;
    if ((temp_4_2 == 5) && (arg0->target->invisible != 0)) {
        func_0010C250(arg0->points, arg1, temp_20->unk1D, -1);
        goto block_49;
    }
    if ((var_30 >= 0) && (var_30 != var_22)) {
        if (var_5 < 0) {
            if (var_30 != attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector(arg0->points, arg0->targetPos, -1)) {
                func_0010C250(arg0->points, arg1, var_30);
                var_22 = -1;
            } else {
                *arg1 = (s128) *arg0->targetPos;
                var_22 = -1;
            }
        } else {
            if (var_5 == arg0->pointA) {
                var_21 = 0;
                sp0 = (s32) temp_20->unk10;
                var_f21 = 1e8f;
                if (temp_20->unk1E > 0) {
                    var_19 = temp_20 + 0x10;
                    do {
                        temp_18 = *var_19;
                        temp_16 = *arg0->points + (temp_18 << 5);
                        var_2_2 = (u8) temp_20->unk1E << 0x18;
                        if (temp_16->unk1D == var_30) {
                            var_f20 = mathfDist2Squared__FP8_fvectorT0(arg0->targetPos, temp_16, arg0->points);
                            if (temp_16->unk1C < 2) {
                                temp_f0 = mathfDist2__FP8_fvectorT0(arg0->selfCs + 0x10, temp_16) * 0.5f;
                                var_f20 += temp_f0 * temp_f0;
                            }
                            if (var_f20 < var_f21) {
                                sp0 = (s32) temp_18;
                                var_f21 = var_f20;
                                var_22 = var_30;
                            }
                            var_2_2 = (u8) temp_20->unk1E << 0x18;
                        }
                        var_21 += 1;
                        var_19 += 2;
                    } while (var_21 < (var_2_2 >> 0x18));
                }
                var_5 = (s16) sp0;
            }
            *arg1 = *(*arg0->points + (var_5 << 5));
        }
        goto block_49;
    }
    switch (temp_4_2) {                             /* irregular */
    case 3:
        if (arg0->nextPoint == -1) {
block_38:
            attractGetCenterOfGroup__15AttractorPointsP8_fvectori(arg0->points, arg1, arg0->unk210, -1);
        } else {
block_37:
            *arg1 = *(*arg0->points + (arg0->nextPoint << 5));
        }
block_49:
        var_2 = var_22;
        break;
    case 4:
        if (arg0->nextPoint == -1) {
            goto block_38;
        }
        goto block_37;
        goto block_49;
    case 5:
        if (arg0->subState != 4) {
        default:
            var_2 = var_22;
            if (arg0->targetCs != NULL) {
                goto block_48;
            }
        } else {
            if (var_30 != attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector(arg0->points, arg0->targetPos, -1)) {
                driverCalcLookahead__6DriverP8_fvector(arg0, arg1);
            } else {
block_48:
                *arg1 = (s128) *arg0->targetPos;
            }
            goto block_49;
        }
        break;
    }
    return (s32) var_2;
}

/* ---- driverGetNewPointInFrontOfVehicle__6DriverP7Vehicle ---- */
s32 driverGetNewPointInFrontOfVehicle__6DriverP7Vehicle(Driver* arg0, ...) {
    s32 temp_2;
    s32 var_2;

    var_2 = arg0->ticks244 < 0x79;
    if (var_2 == 0) {
        temp_2 = driverGetPointInFrontOfVehicle__6DriverP7Vehicle(arg0);
        arg0->curPoint = temp_2;
        driverGetNextPoint__6Driveri(arg0, temp_2);
        driverCalcNextPointTurn__6Driver(arg0);
        arg0->unk2A8 = 0;
        driverGetOffsetFromPoint__6Driver(arg0);
        driverUpdateNextPoint__6DriverP8_fvector(arg0, 0);
        var_2 = 1;
        arg0->ticks244 = 0;
        arg0->turning = 1;
        arg0->following = 0;
        arg0->performing = 0;
    }
    return var_2;
}

/* ---- driverGetNewPointThisSideOfPlane__6DriverP8_fvector ---- */
s32 attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector(void*, FVECTOR*); /* extern */
s32 func_0010BC10(void*, FVECTOR*, s32, s32);       /* extern */

s32 driverGetNewPointThisSideOfPlane__6DriverP8_fvector(Driver* arg0, s32 arg1, ...) {
    s32 temp_2;
    s32 var_2;

    var_2 = arg0->ticks244 < 0x79;
    if (var_2 == 0) {
        temp_2 = func_0010BC10(arg0->points, &arg0->self->pos, attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector(arg0->points, &arg0->self->pos), arg1);
        arg0->curPoint = temp_2;
        if (temp_2 == -1) {
            arg0->curPoint = func_0010BC10(arg0->points, &arg0->self->pos, -1, arg1);
        }
        driverUpdateNextPoint__6DriverP8_fvector(arg0, 0);
        var_2 = 1;
        arg0->targetReachable = 0;
        arg0->unk2B0 = 1;
        arg0->turning = 1;
        arg0->following = 0;
        arg0->performing = 0;
        arg0->ticks244 = 0;
    }
    return var_2;
}

/* ---- driverGetNextClosestPointToLookAheadPos__6DriverP8_fvectorii ---- */
? boundFAngle__FPf(void*);                          /* extern */
f32 func_0021EB98(u8*, FVECTOR*, u8);               /* extern */

s32 driverGetNextClosestPointToLookAheadPos__6DriverP8_fvectorii(Driver* arg0, FVECTOR* arg1, s32 arg2, s32 arg3, ...) {
    f32 sp0;
    FVECTOR* temp_5;
    FVECTOR* temp_5_2;
    f32 temp_f0;
    f32 temp_f22;
    f32 temp_f3;
    f32 temp_f4;
    f32 var_f20;
    f32 var_f23;
    f32 var_f2;
    s16 temp_16;
    s16 var_23;
    s16* var_19;
    s32 var_18;
    s32 var_18_2;
    s32 var_22;
    s32 var_2;
    s32 var_2_2;
    u8 temp_6;
    void* temp_20;

    var_22 = 0;
    var_f23 = 0.0f;
    var_f20 = 1.6e9f;
    temp_20 = *arg0->points + (arg2 << 5);
    var_23 = temp_20->unk10;
    if ((arg0->subState == 4) && (arg3 == -1) && (var_18 = 0, (arg0->targetReachable != 0))) {
        temp_f22 = mathfManhatDist__FP8_fvectorT0(arg0->selfCs + 0x10, arg0->targetPos);
        if (temp_20->unk1E > 0) {
            var_19 = temp_20 + 0x10;
loop_5:
            temp_5 = *arg0->points + (*var_19 << 5);
            if ((arg1->x - temp_5->x) == 0.0f) {
                if ((arg1->y - temp_5->y) == 0.0f) {
                    var_22 = 0;
                } else {
                    goto block_9;
                }
            } else {
block_9:
                if (temp_f22 < mathfManhatDist__FP8_fvectorT0(arg1, temp_5)) {
                    var_f20 = 3.1415927f;
                    var_22 = 1;
                    var_f23 = func_0021EB98(&arg0->_padC[4], arg0->targetPos);
                }
                var_18 += 1;
                var_19 += 2;
                if (var_18 < temp_20->unk1E) {
                    goto loop_5;
                }
            }
        }
    }
    var_18_2 = 0;
    if (temp_20->unk1E > 0) {
        var_2 = 0 * 2;
        do {
            temp_16 = (temp_20 + var_2)->unk10;
            temp_5_2 = *arg0->points + (temp_16 << 5);
            temp_f4 = arg1->x - temp_5_2->x;
            temp_f3 = arg1->y - temp_5_2->y;
            var_f2 = (temp_f4 * temp_f4) + (temp_f3 * temp_f3);
            if (((temp_f4 == 0.0f) && (temp_f3 == 0.0f)) || (arg3 < 0) || (var_2_2 = (u8) temp_20->unk1E << 0x18, (temp_5_2->unk1D == arg3))) {
                if (var_22 != 0) {
                    temp_f0 = var_f23 - func_0021EB98(&arg0->_padC[4], temp_5_2, (u8) temp_20->unk1E);
                    sp0 = temp_f0;
                    boundFAngle__FPf(sp);
                    var_f2 = fabsf(temp_f0);
                }
                temp_6 = (u8) temp_20->unk1E;
                if (var_f2 < var_f20) {
                    if (temp_16 == arg0->unk204) {
                        var_2_2 = temp_6 << 0x18;
                        if (arg0->unk21C < arg0->unk220) {
                            var_23 = temp_16;
                            var_f20 = var_f2;
                            if (var_22 == 0) {
                                var_f20 = var_f2 + 25.0f;
                                goto block_29;
                            }
                        }
                    } else {
                        var_23 = temp_16;
                        var_f20 = var_f2;
                        goto block_29;
                    }
                } else {
block_29:
                    var_2_2 = temp_6 << 0x18;
                }
            }
            var_18_2 += 1;
            var_2 = var_18_2 * 2;
        } while (var_18_2 < (var_2_2 >> 0x18));
    }
    return (s32) var_23;
}

/* ---- driverGetNextPoint__6Driveri ---- */
? boundFAngle__FPf(void*);                          /* extern */

s32 driverGetNextPoint__6Driveri(Driver* arg0, s32 arg1, ...) {
    f32 sp0;
    f32 temp_f0;

    if (arg1 != -1) {
        arg0->curPoint = arg1;
    } else {
        driverGetInitialGuessNextPoint__6Driver(arg0);
    }
    if (arg0->curPoint == arg0->unk204) {
        arg0->unk21C = (s32) (arg0->unk21C + 1);
    } else {
        arg0->unk21C = 0;
    }
    driverInitPointInfo__6DriverP8_fvector(arg0, 0);
    temp_f0 = arg0->unk5C - arg0->selfCs->unk68;
    sp0 = temp_f0;
    boundFAngle__FPf(sp);
    if (fabsf(temp_f0) > 2.3561945f) {
        arg0->unk260 = 1;
    } else {
        arg0->unk260 = 0;
    }
    arg0->unk248 = 1;
    return 1;
}

/* ---- driverGetOffsetFromPoint__6Driver ---- */
? boundFAngle__FPf(f32*);                           /* extern */
? func_0021D258(void*, ?*, ?*);                     /* extern */
f32 mathfManhatDist2D__FP8_fvectorT0(FVECTOR*, void*); /* extern */
? mathfRotMatrixRPH__FPA3_fP8_fvector(void*, f32*); /* extern */

s32 driverGetOffsetFromPoint__6Driver(Driver* arg0, ...) {
    f32 sp40;
    f32 sp44;
    f32 sp48;
    s32 sp50;
    s32 sp54;
    s32 sp58;
    ? sp60;
    ? sp70;
    ? sp80;
    s32 sp90;
    s32 sp98;
    FVECTOR spA0;
    ? spB0;
    f32 spF0;
    f32 temp_f2;
    f32 var_f0;
    f32 var_f1;
    s32 var_19;
    void* temp_18;
    void* temp_4;

    var_19 = 1;
    temp_18 = *arg0->points + (arg0->pointA << 5);
    if ((arg0->targetReachable != 0) && (arg0->unk2A8 != 0)) {
        temp_4 = arg0->targetCs;
        if ((temp_4 != NULL) && (arg0->selfCs != NULL) && (arg0->mode == 5) && (arg0->subState == 4)) {
            M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($v1) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($v0) */);
            M2C_ERROR(/* unknown instruction: vsub.xyz $vf11, $vf11, $vf12 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf11, 0x60($sp) */);
            func_0021D258(temp_4 + 0x20, &sp60, &sp70);
            M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($s2) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($v0) */);
            M2C_ERROR(/* unknown instruction: vsub.xyz $vf11, $vf11, $vf12 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf11, 0x60($sp) */);
            func_0021D258(arg0->targetCs + 0x20, &sp60, &sp80);
            if (sp84 < sp74) {
                sp90 = 0;
                sp90.unk4 = 150.0f;
                sp98 = 0;
                M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($a0) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($v1) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf13, 0x10($v1) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf14, 0x20($v1) */);
                M2C_ERROR(/* unknown instruction: vmulax.xyz ACC, $vf12, $vf11x */);
                M2C_ERROR(/* unknown instruction: vmadday.xyz ACC, $vf13, $vf11y */);
                M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf11, $vf14, $vf11z */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf11, 0xa0($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($s0) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($v0) */);
                M2C_ERROR(/* unknown instruction: vadd.xyz $vf11, $vf11, $vf12 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf11, 0xa0($sp) */);
                if (mathfManhatDist2D__FP8_fvectorT0(&spA0, arg0->selfCs + 0x10) > 100.0f) {
                    spA0.z += 3.0f;
                    if (hdLosTest__FP8_fvectorT0P9_hdResulti(&arg0->self->pos, &spA0, &spB0, 0) != 0) {
                        M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($s0) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($s2) */);
                        M2C_ERROR(/* unknown instruction: vsub.xyz $vf11, $vf11, $vf12 */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf11, 0x50($sp) */);
                        var_19 = 0;
                    }
                }
            }
        }
    }
    arg0->unk2A8 = var_19;
    if (var_19 != 0) {
        temp_f2 = arg0->unk1F4;
        if (temp_f2 != 0.0f) {
            arg0->unk40 = (f32) ((f32) (*arg0->points + (arg0->curPoint << 5))->unk1C * 17.0f * temp_f2);
        }
        if ((arg0->unk40 != 0.0f) && (temp_18->unk1F > 0)) {
            sp48 = arg0->unk58;
            sp40 = 0.0f;
            sp44 = 0.0f;
            mathfRotMatrixRPH__FPA3_fP8_fvector(sp, &sp40);
            spF0 = arg0->unk5C - arg0->unk58;
            boundFAngle__FPf(&spF0);
            if (spF0 < 0.0f) {
                spF0 = -1.5707964f - spF0;
                boundFAngle__FPf(&spF0);
                var_f1 = arg0->unk40;
                var_f0 = (var_f1 * fabsf(spF0)) / 1.5707964f;
            } else {
                spF0 = 1.5707964f - spF0;
                boundFAngle__FPf(&spF0);
                var_f1 = -arg0->unk40;
                var_f0 = (var_f1 * fabsf(spF0)) / 1.5707964f;
            }
            arg0->unk44 = (f32) (var_f1 - var_f0);
            sp40 = arg0->unk40;
            sp44 = arg0->unk44;
            sp48 = 0.0f;
            M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($s3) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf13, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf14, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz ACC, $vf12, $vf11x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz ACC, $vf13, $vf11y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf11, $vf14, $vf11z */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf11, 0x50($sp) */);
        } else if (var_19 != 0) {
            sp50 = 0;
            sp54 = 0;
            sp58 = 0;
        }
    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($s2) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($v0) */);
    M2C_ERROR(/* unknown instruction: vadd.xyz $vf11, $vf11, $vf12 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf11, 0x10($s1) */);
    return (s32) &sp50;
}

/* ---- driverGetPointInFrontOfVehicle__6DriverP7Vehicle ---- */
s16 attractGetClosestPoint__15AttractorPointsP8_fvector(void*, FVECTOR*); /* extern */
s32 attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector(void*, FVECTOR*); /* extern */
? boundFAngle__FPf(f32*);                           /* extern */
s16 func_0010BA78(void*, FVECTOR*, s32);            /* extern */
f32 func_0021EB98(FVECTOR*, s128*, void*, s8);      /* extern */
f32 mathfDist2__FP8_fvectorT0(FVECTOR*, ?);         /* extern */
f32 mathfManhatDist2D__FP8_fvectorT0(FVECTOR*, FVECTOR*); /* extern */
s32 tireIsDrivableSlope__7VehicleP8_fvector(Vehicle*, s128*); /* extern */

s32 driverGetPointInFrontOfVehicle__6DriverP7Vehicle(Driver* arg0, void* arg1, ...) {
    f32 sp8;
    s128 sp10;
    ? sp20;
    s128 sp30;
    s128 sp40;
    f32 sp60;
    f32 sp64;
    FVECTOR* var_4;
    f32 var_f20;
    s128* temp_5;
    s128* temp_5_2;
    s128* temp_5_3;
    s128* var_20;
    s16 temp_17;
    s16 temp_17_2;
    s16 temp_2;
    s16 var_21;
    s32 temp_16;
    s32 temp_22;
    s32 var_16;
    s32 var_19;
    s32 var_19_2;
    s32 var_2;
    s32 var_2_2;
    s8 temp_7;
    void* temp_20;
    void* temp_2_2;
    void* temp_3;
    void* temp_4;
    void* temp_6;
    void* temp_6_2;

    temp_22 = attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector(arg0->points, &arg0->self->pos);
    temp_4 = arg0->points;
    var_21 = attractGetClosestPoint__15AttractorPointsP8_fvector(arg0->points, &arg0->self->pos);
    var_20 = *temp_4 + (var_21 << 5);
    temp_2 = func_0010BA78(temp_4, &arg0->self->pos, temp_22);
    if ((temp_2 != -1) && (var_21 != temp_2)) {
        temp_2_2 = arg0->points;
        temp_5 = *temp_2_2 + (temp_2 << 5);
        if (!(((temp_2_2 + (temp_22 * 4))->unk8 + temp_5->unk1D)->unk140 & 1)) {
            var_21 = temp_2;
            var_20 = temp_5;
        }
    }
    if (arg1 == arg0->self) {
        var_f20 = arg1->unk2028->unk68;
    } else {
        M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($v1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($v0) */);
        M2C_ERROR(/* unknown instruction: vsub.xyz $vf11, $vf11, $vf12 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf11, ($sp) */);
        if (mathfDist2__FP8_fvectorT0(sp, 0) < 100.0f) {
            var_4 = arg1 + 0x1F0;
        } else {
            var_4 = sp;
        }
        sp10 = M2C_ERROR(/* unknown instruction: por $v0, $zero, $zero */);
        var_f20 = func_0021EB98(var_4, &sp10);
    }
    var_19 = 0;
    sp60 = func_0021EB98(&arg0->self->pos, var_20) - var_f20;
    boundFAngle__FPf(&sp60);
    sp60 = fabsf(sp60);
    if (var_20->unk1E > 0) {
        var_2 = 0 * 2;
        do {
            temp_6 = arg0->points;
            temp_17 = (var_20 + var_2)->unk10;
            temp_5_2 = *temp_6 + (temp_17 << 5);
            temp_7 = temp_5_2->unk1D;
            if ((temp_7 == var_20->unk1D) || (((temp_6 + (temp_22 * 4))->unk8 + temp_7)->unk140 & 1)) {
                sp64 = func_0021EB98(&arg0->self->pos, temp_5_2, temp_6, temp_7) - var_f20;
                boundFAngle__FPf(&sp64);
                if (fabsf(sp64) < sp60) {
                    sp8 += 3.0f;
                    var_16 = hdLosTest__FP8_fvectorT0P9_hdResulti(&arg0->self->pos, sp, &sp20, 0, /* extra? */ var_20->unk0) != 0;
                    if (var_16 == 0) {
                        if (mathfManhatDist2D__FP8_fvectorT0(&arg0->self->pos, sp) < 200.0f) {
                            var_16 = (tireIsDrivableSlope__7VehicleP8_fvector(arg0->self, &sp30) != 0) ? 1 : var_16;
                        }
                        if (var_16 != 0) {
                            goto block_19;
                        }
                    } else {
block_19:
                        var_21 = temp_17;
                        sp60 = fabsf(sp64);
                    }
                }
            }
            var_19 += 1;
            var_2 = var_19 * 2;
        } while (var_19 < var_20->unk1E);
    }
    if (arg0->unk294 != 0) {
        temp_20 = *arg0->points + (var_21 << 5);
        var_19_2 = 0;
        if (temp_20->unk1E > 0) {
            var_2_2 = 0 * 2;
            do {
                temp_3 = arg0->points;
                temp_17_2 = (temp_20 + var_2_2)->unk10;
                temp_6_2 = *temp_3;
                temp_5_3 = temp_6_2 + (temp_17_2 << 5);
                if (((temp_3 + (temp_22 * 4))->unk8 + temp_5_3->unk1D)->unk140 & 1) {
                    sp64 = func_0021EB98(&arg0->self->pos, temp_5_3, temp_6_2) - var_f20;
                    boundFAngle__FPf(&sp64);
                    if ((fabsf(sp64) < sp60) && ((sp40 = temp_20->unk0, unksp48 += 3.0f, temp_16 = hdLosTest__FP8_fvectorT0P9_hdResulti(&arg0->self->pos, (FVECTOR* ) &sp40, sp, 0) != 0, (temp_16 != 0)) || (((tireIsDrivableSlope__7VehicleP8_fvector(arg0->self, &sp10) == 0) ? temp_16 : 1) != 0))) {
                        var_21 = temp_17_2;
                        sp60 = fabsf(sp64);
                    }
                }
                var_19_2 += 1;
                var_2_2 = var_19_2 * 2;
            } while (var_19_2 < temp_20->unk1E);
        }
    }
    return (s32) var_21;
}

/* ---- driverGetRandomNextPoint__6Driverb ---- */
f32 atan2f(s32, f32, f32);                          /* extern */
? boundFAngle__FPf(f32*);                           /* extern */

s32 driverGetRandomNextPoint__6Driverb(Driver* arg0, ...) {
    f32 sp0;
    f32 sp4;
    f32 temp_f0;
    f32 var_f13;
    s16 temp_16;
    s16 var_21;
    s32 temp_4;
    s32 var_17;
    s32 var_2;
    s8 temp_5;
    s8 var_19;
    void* temp_18;
    void* temp_3;

    temp_18 = *arg0->points + (arg0->pointA << 5);
    temp_5 = temp_18->unk1E;
    if (temp_5 < 2) {
        return (s32) temp_18->unk10;
    }
    var_21 = -1;
    var_19 = temp_18->unk1E;
    var_17 = mathfRand__Fii(0, temp_5 - 1);
    if (var_19 != 0) {
        var_2 = var_17 * 2;
loop_5:
        temp_16 = *(temp_18 + 0x10 + var_2);
        temp_3 = *arg0->points + (temp_16 << 5);
        temp_4 = temp_16 ^ arg0->unk204;
        var_21 = (temp_4 != 0) ? temp_16 : var_21;
        var_f13 = temp_3->unk4 - temp_18->unk4;
        if (var_f13 == 0.0f) {
            var_f13 = 0.01f;
        }
        temp_f0 = atan2f(temp_4, temp_3->unk0 - temp_18->unk0, var_f13);
        sp0 = temp_f0;
        boundFAngle__FPf(sp);
        sp4 = arg0->unk58 - temp_f0;
        boundFAngle__FPf(&sp4);
        var_17 -= 1;
        if (!(fabsf(sp4) < 1.9198622f)) {
            var_19 -= 1;
            if (var_17 < 0) {
                var_17 = temp_18->unk1E - 1;
            }
            var_2 = var_17 * 2;
            if (var_19 == 0) {
                goto block_11;
            }
            goto loop_5;
        }
        return (s32) temp_16;
    }
block_11:
    return (s32) var_21;
}

/* ---- driverGetSnipePoint__6Driver ---- */
s32 attractGetSnipePoint__15AttractorPointsi(void*, s32); /* extern */

s32 driverGetSnipePoint__6Driver(Driver* arg0, ...) {
    s32 temp_2;

    temp_2 = attractGetSnipePoint__15AttractorPointsi(arg0->points, arg0->group);
    arg0->nextPoint = temp_2;
    return temp_2;
}

/* ---- driverInitPointInfo__6DriverP8_fvector ---- */
f32 atan2f(f32, f32);                               /* extern */
f32 mathfManhatDist2D__FP8_fvectorT0(void*, ?);     /* extern */

s32 driverInitPointInfo__6DriverP8_fvector(Driver* arg0, s32 arg1, ...) {
    f32 sp4;
    f32 temp_ret;

    if (arg1 != 0) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($a1) */);
        M2C_ERROR(/* unknown instruction: vsub.xyz $vf11, $vf11, $vf12 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf11, ($sp) */);
    } else {
        M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($v1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($v0) */);
        M2C_ERROR(/* unknown instruction: vsub.xyz $vf11, $vf11, $vf12 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf11, ($sp) */);
    }
    if (sp4 == 0.0f) {
        sp4 = 0.01f;
    }
    arg0->unk58 = atan2f(sp0, sp4);
    M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($v1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($s1) */);
    M2C_ERROR(/* unknown instruction: vsub.xyz $vf11, $vf11, $vf12 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf11, ($sp) */);
    arg0->unk50 = mathfManhatDist2D__FP8_fvectorT0(sp, 0);
    if (sp4 == 0.0f) {
        sp4 = 0.01f;
    }
    if (arg0->unk50 == 0.0f) {
        arg0->unk50 = 0.01f;
    }
    temp_ret = atan2f(sp0, sp4);
    arg0->unk5C = temp_ret;
    return (bitwise s32) temp_ret;
}

/* ---- driverInitToPoint__6Driveri ---- */
? vehicleSetToPosition__7VehicleP8_fvectorf(Vehicle*, void*, f32); /* extern */

s32 driverInitToPoint__6Driveri(Driver* arg0, s32 arg1, ...) {
    void* temp_3;

    arg0->unk1F4 = 0.33f;
    arg0->speedLimit = 1.1733333f;
    arg0->unk280 = 0;
    arg0->unk284 = 0;
    arg0->unk27C = 0;
    arg0->unk28C = 0;
    if (arg1 >= 0) {
        temp_3 = *arg0->points + (arg1 << 5);
        arg0->selfCs->unk10 = (s128) temp_3->unk0;
        arg0->pointA = arg1;
        arg0->curPoint = (s32) temp_3->unk10;
        driverUpdateNextPoint__6DriverP8_fvector(arg0, 0, arg1);
        vehicleSetToPosition__7VehicleP8_fvectorf(arg0->self, arg0->selfCs + 0x10, arg0->heading48);
        driverCalcNextPointTurn__6Driver(arg0);
    } else {
        arg0->unk204 = 0;
        arg0->pointA = 0;
        arg0->curPoint = 0;
    }
    arg0->turning = 0;
    arg0->following = 1;
    arg0->performing = 0;
    return 1;
}

/* ---- driverInitTurn__6Driver ---- */
s32 driverInitTurn__6Driver(Driver* arg0, ...) {
    Vehicle* temp_3;

    temp_3 = arg0->self;
    arg0->unk22C = 0x64;
    arg0->unk288 = 0;
    arg0->unk248 = 0;
    arg0->odometer = 0.0f;
    arg0->turnCount = 0;
    if (temp_3 != NULL) {
        temp_3->unk1A90 = 0;
    }
    return 0x64;
}

/* ---- driverMustSnipe__6Driver ---- */
s32 driverMustSnipe__6Driver(Driver* arg0, ...) {
    return (s32) ((u8) ((arg0->points + (arg0->group * 4))->unk8 + D_004FA030->humanGroup[arg0->target->aiOrPlayerIdx])->unk140 >> 7);
}

/* ---- driverSetLineDriving__6Driverb ---- */
s32 driverSetLineDriving__6Driverb(Driver* arg0, s32 arg1, ...) {
    s32 var_2;

    var_2 = arg0->unk2A0;
    if (arg1 != var_2) {
        arg0->unk2A0 = arg1;
        if (arg1 != 0) {
            arg0->performing = 0;
            arg0->turning = 0;
            arg0->following = 0;
            return var_2;
        }
        var_2 = 1;
        arg0->performing = 0;
        arg0->turning = 1;
        arg0->following = 0;
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return var_2;
    }
    return var_2;
}

/* ---- driverUpdateNextPoint__6DriverP8_fvector ---- */
s32 driverUpdateNextPoint__6DriverP8_fvector(Driver* arg0, s32 arg1, ...) {
    FVECTOR* temp_17;
    f32 temp_f1;
    f32 var_f0;
    f32 var_f0_2;
    s32 temp_3;
    s32 temp_4;
    s32 temp_4_2;
    s32 temp_5;
    s8 temp_3_2;
    s8 temp_5_2;
    void* temp_2;
    void* temp_7;

    arg0->unk204 = (s32) arg0->pointA;
    arg0->unk20 = (s128) arg0->unk10;
    arg0->unk58 = (f32) arg0->unk5C;
    arg0->group = (s32) (*arg0->points + (arg0->pointA << 5))->unk1D;
    if (arg0->curPoint < 0) {
        arg0->curPoint = driverGetPointInFrontOfVehicle__6DriverP7Vehicle(arg0, arg0->self);
    }
    temp_4 = arg0->curPoint;
    temp_7 = arg0->points;
    arg0->pointA = temp_4;
    temp_5 = *temp_7;
    temp_3 = D_004FA030->levelType;
    temp_17 = temp_5 + (temp_4 << 5);
    switch (temp_3) {                               /* switch 1; irregular */
    case 20:                                        /* switch 1 */
        /* fallthrough */
    case 8:                                         /* switch 1 */
    case 4:                                         /* switch 1 */
        var_f0 = 8.0f;
        break;
    default:                                        /* switch 1 */
        var_f0 = (f32) temp_17->unk1C * 8.0f;
        break;
    }
    arg0->unk1F8 = var_f0;
    driverGetInitialGuessNextPoint__6Driver(arg0, temp_5, 8, temp_7);
    arg0->unk248 = 0;
    arg0->unk24C = 0;
    arg0->unk290 = 0;
    driverGetOffsetFromPoint__6Driver(arg0);
    driverInitPointInfo__6DriverP8_fvector(arg0, arg1);
    driverUpdatePointInfo__6Driver(arg0);
    arg0->goalPos = temp_17;
    arg0->unk264 = 0;
    arg0->unk268 = 0;
    arg0->unk26C = 0;
    arg0->unk18C = arg0->dist4C + 1.0f;
    temp_3_2 = temp_17->unk1F;
    switch (temp_3_2) {                             /* switch 2; irregular */
    case 1:                                         /* switch 2 */
        arg0->unk264 = (s32) (temp_3_2 != 0);
        break;
    case 3:                                         /* switch 2 */
        arg0->unk268 = 1;
        break;
    case 4:                                         /* switch 2 */
        arg0->unk26C = 1;
        break;
    }
    if (temp_17->unk1C < 2) {
        arg0->unk278 = 1;
    } else {
        arg0->unk278 = 0;
    }
    temp_5_2 = temp_17->unk1D;
    temp_4_2 = arg0->group;
    if (temp_4_2 != temp_5_2) {
        arg0->unk1A0 = (f32) ((arg0->points + (temp_4_2 * 4))->unk8 + temp_5_2)->unkF8 * 0.024444444f;
    } else {
        arg0->unk1A0 = 0.0f;
    }
    temp_2 = arg0->selfCs;
    var_f0_2 = temp_17->z;
    temp_f1 = temp_2->unk18;
    if (!(var_f0_2 < temp_f1)) {
        var_f0_2 = temp_f1 - 1.0f;
    }
    arg0->unk190 = var_f0_2;
    return (s32) temp_2;
}

/* ---- driverUpdatePointInfo__6Driver ---- */
f32 atan2f(f32, f32);                               /* extern */
f32 mathfManhatDist2D__FP8_fvectorT0(void*, ?);     /* extern */

s32 driverUpdatePointInfo__6Driver(Driver* arg0, ...) {
    f32 sp4;
    f32 temp_ret;

    M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($v1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($v0) */);
    M2C_ERROR(/* unknown instruction: vsub.xyz $vf11, $vf11, $vf12 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf11, ($sp) */);
    arg0->dist4C = mathfManhatDist2D__FP8_fvectorT0(sp, 0);
    if (sp4 == 0.0f) {
        sp4 = 0.01f;
    }
    temp_ret = atan2f(sp0, sp4);
    arg0->heading48 = temp_ret;
    return (bitwise s32) temp_ret;
}

/* ---- func_0012E2E0 ---- */
s32 func_0012E2E0(Driver* arg0, Vehicle* arg1, void* arg2, s32 arg3, ...) {
    Vehicle* temp_2;
    f32 temp_f2;
    s32 var_5;

    var_5 = 0x64;
    arg0->self = arg1;
    arg0->points = arg2;
    arg0->selfCs = arg1->cs;
    arg0->unk0 = arg3;
    arg0->unk22C = 0x64;
    arg0->mode = 0;
    if ((D_004FA030->singlePlayer == 0) || (var_5 = arg1->character, (var_5 == 0x140)) || (var_5 == 0x80)) {
        arg0->unk220 = 0;
    } else {
        arg0->unk220 = 1;
    }
    arg0->unk218 = 0;
    arg0->unk21C = 0;
    arg0->unk294 = 0;
    arg0->targetReachable = 0;
    arg0->unk260 = 0;
    arg0->unk274 = 0;
    arg0->unk2B0 = 0;
    func_0012E410(arg0, var_5, arg1);
    temp_2 = arg0->self;
    temp_f2 = (-temp_2->unk3C8 * 0.5f) - 3.0f;
    arg0->unk178 = temp_f2;
    arg0->unk17C = (f32) (temp_f2 + ((temp_2->unk3C8 + 6.0f) * 0.333f));
    arg0->unk180 = (f32) (temp_f2 + ((temp_2->unk3C8 + 6.0f) * 0.667f));
    arg0->unk238 = 4;
    arg0->unk184 = (f32) ((temp_2->unk3C8 * 0.5f) + 3.0f);
    return (s32) temp_2;
}

/* ---- func_0012E410 ---- */
f32 cosf(f32);                                      /* extern */
f32 sinf(f32);                                      /* extern */
? vehicleUpdateTurn__7Vehicle(Vehicle*);            /* extern */

s32 func_0012E410(Driver* arg0, ...) {
    Vehicle* temp_2;
    f32 var_f20;
    f32 var_f21;
    f32 var_f22;
    f32 var_f2;

    var_f21 = 0.0f;
    var_f20 = 0.0f;
    arg0->self->steer = 0.0f;
    var_f22 = 0.0f;
    arg0->self->pad[0xA] = 1;
    arg0->unk1B8 = 0.0f;
    arg0->unk1BC = 0.0f;
    arg0->unk1C0 = 0.0f;
    arg0->unk1C4 = 0.0f;
    arg0->unk1C8 = 0.0f;
    arg0->unk1CC = 0.0f;
    arg0->unk1D0 = 0.0f;
    do {
loop_20:
        vehicleUpdateTurn__7Vehicle(arg0->self);
        var_f21 += arg0->self->steer;
        var_f20 += sinf(var_f21);
        var_f22 += cosf(var_f21);
        if (!(var_f21 > 1.5707964f)) {
            if (var_f21 > 1.308997f) {
                if (arg0->unk1CC == 0.0f) {
                    arg0->unk1CC = var_f22;
                    arg0->unk1E8 = var_f20;
                }
            } else if (var_f21 > 1.0471976f) {
                if (arg0->unk1C8 == 0.0f) {
                    arg0->unk1C8 = var_f22;
                    arg0->unk1E4 = var_f20;
                }
            } else if (var_f21 > 0.7853982f) {
                if (arg0->unk1C4 == 0.0f) {
                    arg0->unk1C4 = var_f22;
                    arg0->unk1E0 = var_f20;
                }
            } else if (var_f21 > 0.5235988f) {
                if (arg0->unk1C0 == 0.0f) {
                    arg0->unk1C0 = var_f22;
                    arg0->unk1DC = var_f20;
                }
            } else if (var_f21 > 0.2617994f) {
                if (arg0->unk1BC == 0.0f) {
                    arg0->unk1BC = var_f22;
                    arg0->unk1D8 = var_f20;
                }
            } else if ((var_f21 > 0.122173056f) && (arg0->unk1B8 == 0.0f)) {
                arg0->unk1B8 = var_f22;
                arg0->unk1D4 = var_f20;
            }
            goto loop_20;
        }
    } while (arg0->unk1D0 != 0.0f);
    arg0->unk1D0 = var_f22;
    arg0->unk1EC = var_f20;
    arg0->self->steer = 0.0f;
    arg0->unk1B4 = 0.0f;
    temp_2 = arg0->self;
    var_f2 = temp_2->unk330;
    if (var_f2 > 0.0f) {
        do {
            var_f2 -= temp_2->unk33C;
            arg0->unk1B4 = (f32) (arg0->unk1B4 + var_f2);
        } while (var_f2 > 0.0f);
    }
    return (s32) temp_2;
}

/* ---- func_0012E798 ---- */
s32 func_0012E798(Driver* arg0, ...) {
    Vehicle* temp_2;
    Vehicle* temp_4;
    Vehicle* temp_5;
    f32 temp_f2;
    f32 temp_f3;
    s32 temp_17;
    s32 temp_3;
    s32 temp_5_2;
    s32 var_2;

    var_2 = arg0->mode;
    if (var_2 != 0) {
        temp_5 = arg0->self;
        arg0->ticks228 += temp_5->frameTicks;
        arg0->ticks244 += temp_5->frameTicks;
        if (fabsf(temp_5->steerInput) < 0.2f) {
            arg0->distSincePoint += temp_5->throttle * (f32) temp_5->frameTicks;
        }
        driverUpdatePointInfo__6Driver(arg0, temp_5);
        if (arg0->self->kind == 2) {
            temp_5_2 = arg0->snipe;
            temp_17 = D_004FA030->humanGroup[arg0->target->aiOrPlayerIdx];
            if (temp_5_2 != 0) {
                if (arg0->mode != 5) {
                    arg0->snipe = 0;
                } else {
                    arg0->snipe = driverMustSnipe__6Driver(arg0, temp_5_2);
                }
            }
            if (arg0->unk2B0 == 0) {
                temp_3 = D_004FA030->levelType;
                switch (temp_3) {                   /* irregular */
                case 20:
                    /* fallthrough */
                case 8:
                case 4:
                    temp_2 = arg0->self;
                    arg0->targetReachable = 0;
                    if ((temp_2 != NULL) && (temp_2->turbo > 0.25f)) {
                        arg0->unk27C = 1;
                    }
                    break;
                default:
                    if (arg0->group != temp_17) {
                        arg0->targetReachable = ((arg0->points + (arg0->group * 4))->unk8 + temp_17)->unk140 & 1;
                    } else {
                        arg0->targetReachable = 1;
                    }
                    arg0->unk27C = 0;
                    break;
                }
            }
        }
        temp_f2 = arg0->dist4C;
        temp_f3 = arg0->unk18C;
        if (!(temp_f3 < temp_f2)) {
            goto block_34;
        }
        if (!(arg0->self->throttle > 0.36666667f)) {
block_34:
            arg0->unk274 = 0;
            arg0->unk18C = arg0->dist4C;
        } else if ((temp_f3 + 5.0f) < temp_f2) {
            arg0->unk18C = temp_f2;
            arg0->unk274 = 1;
        }
        temp_4 = arg0->self;
        arg0->speedRatio = temp_4->velAlongHeading / arg0->speedLimit;
        if (arg0->turning != 0) {
            aiTurn__7Vehicle(temp_4);
            arg0->turnCount += 1;
        } else if (arg0->following == 0) {
            if (arg0->performing == 0) {
                if (arg0->unk2A0 != 0) {
                    func_001048D0(temp_4);
                } else {
                    arg0->turning = 1;
                }
            } else {
                aiPerform__7Vehicle(temp_4);
            }
        } else {
            func_00102D78(temp_4);
            if (arg0->following != 0) {
                arg0->followCount += 1;
            } else {
                driverUpdateNextPoint__6DriverP8_fvector(arg0, 0);
                arg0->followCount = 0;
                arg0->unk2B0 = 0;
            }
        }
        var_2 = (s32) arg0->self;
        arg0->odometer += fabsf(var_2->unk208);
    }
    return var_2;
}

/* ---- func_0012F8D8 ---- */
s32 func_0012F8D8(Driver* arg0, s32 arg2, s32 arg3, ...) {
    f32 sp0;
    f32 sp4;
    f32 sp8;
    f32 sp10;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 var_f20;
    s16 temp_17;
    s16 var_23;
    s16* var_21;
    s32 var_22;
    void* temp_18;
    void* temp_19;

    var_f20 = 2.0f;
    temp_19 = *arg0->points + (arg2 << 5);
    var_23 = temp_19->unk10;
    M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($a1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($s3) */);
    M2C_ERROR(/* unknown instruction: vsub.xyz $vf11, $vf11, $vf12 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf11, ($sp) */);
    M2C_ERROR(/* unknown instruction: madd.s $f0, $f3, $f3 */);
    temp_f0 = M2C_ERROR(/* unknown instruction: rsqrt.s $f0, $f4, $f0 */);
    sp0 = M2C_ERROR(/* unknown instruction: mula.s $f1, $f1 */) * temp_f0;
    sp4 = M2C_ERROR(/* unknown instruction: madda.s $f2, $f2 */) * temp_f0;
    sp8 *= temp_f0;
    var_22 = 0;
    if (temp_19->unk1E > 0) {
        var_21 = temp_19 + 0x10;
        do {
            temp_17 = *var_21;
            temp_18 = *arg0->points + (temp_17 << 5);
            M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($s2) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($s3) */);
            M2C_ERROR(/* unknown instruction: vsub.xyz $vf11, $vf11, $vf12 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf11, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: madd.s $f0, $f3, $f3 */);
            temp_f0_2 = M2C_ERROR(/* unknown instruction: rsqrt.s $f0, $f4, $f0 */);
            sp10 = M2C_ERROR(/* unknown instruction: mula.s $f1, $f1 */) * temp_f0_2;
            sp10.unk4 = (f32) (M2C_ERROR(/* unknown instruction: madda.s $f2, $f2 */) * temp_f0_2);
            sp10.unk8 = (f32) (sp10.unk8 * temp_f0_2);
            M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf12, ($s0) */);
            M2C_ERROR(/* unknown instruction: vsub.xyz $vf11, $vf11, $vf12 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf11, 0x10($sp) */);
            temp_f0_3 = mathfManhatDist__FP8_fvectorT0((FVECTOR* ) &sp10, NULL);
            if (((temp_f0_3 == 0.0f) || (arg3 < 0) || (temp_18->unk1D == arg3)) && (temp_f0_3 < var_f20) && ((temp_17 != arg0->unk204) || (arg0->unk21C < arg0->unk220))) {
                var_23 = temp_17;
                var_f20 = temp_f0_3;
            }
            var_22 += 1;
            var_21 += 2;
        } while (var_22 < temp_19->unk1E);
    }
    return (s32) var_23;
}

/* ---- func_00130598 ---- */
s32 func_00130598(Driver* arg0, s32 arg1, ...) {
    s32 temp_ret;
    u8* var_5;
    u8* var_6;

    if (arg1 != 0) {
        var_6 = &arg0->_padC[4];
        var_5 = &arg0->_padC[0x14];
    } else {
        var_5 = &arg0->_padC[4];
        var_6 = *arg0->points + (arg0->curPoint << 5);
    }
    temp_ret = driverCalcDistFromLine__6DriverP8_fvectorT1T1(arg0, var_5, var_6, arg0->selfCs + 0x10);
    arg0->unk54 = (bitwise f32) temp_ret;
    return temp_ret;
}

/* ---- func_00130C00 ---- */
void func_00130C00(Driver* arg0, Vehicle* arg1) {
    void* temp_3;

    arg0->target = arg1;
    temp_3 = arg1->cs;
    arg0->targetPredPos = &arg1->predictedPos;
    arg0->targetCs = temp_3;
    arg0->targetPos = temp_3 + 0x10;
}

/* ---- func_00130C50 ---- */
? boundFAngle__FPf(void*);                          /* extern */

s32 func_00130C50(Driver* arg0, ...) {
    f32 sp0;
    f32 temp_f3;
    f32 var_f2;
    s32 var_2;

    if (!(arg0->dist4C < 25.0f)) {
        sp0 = arg0->heading48 - arg0->selfCs->unk68;
        boundFAngle__FPf(sp);
        temp_f3 = arg0->dist4C;
        var_f2 = fabsf(arg0->self->steer) * 4.0f;
        if (temp_f3 < 100.0f) {
            var_f2 += 0.5235988f - ((temp_f3 * 0.5235988f) / 100.0f);
        }
        if (var_f2 < 0.08726647f) {
            var_f2 = 0.08726647f;
        }
        if (!(fabsf(sp0) < var_f2)) {
            var_2 = 0;
            if (arg0->turnCount >= 0xF1) {
                arg0->turnCount = 0;
                arg0->unk2A4 = (s32) (arg0->unk2A4 ^ 1);
                goto block_11;
            }
        } else {
            goto block_8;
        }
    } else {
block_8:
block_11:
        var_2 = 1;
    }
    return var_2;
}

/* ---- func_00130D68 ---- */
? boundFAngle__FPf(void*, f32);                     /* extern */

s32 func_00130D68(Driver* arg0, f32 fparg0, ...) {
    f32 sp0;
    Vehicle* temp_4;
    Vehicle* temp_4_2;
    f32 temp_f12;
    f32 var_f0;
    u8 var_2;

    temp_f12 = fparg0 - (arg0->selfCs->unk68 + (arg0->self->steer * 4.0f));
    sp0 = temp_f12;
    boundFAngle__FPf(sp, temp_f12);
    temp_4 = arg0->self;
    var_f0 = 2.0f * fabsf(temp_4->steer);
    if (var_f0 < 0.017453292f) {
        var_f0 = 0.017453292f;
    }
    var_2 = 0x64;
    if (var_f0 < sp0) {
        if (arg0->unk22C != 0x64) {
            var_2 = (u8) arg0->unk22C;
            temp_4->pad[0xA] = var_2;
        } else {
            var_2 = 1;
            temp_4->pad[0xA] = 1;
        }
    } else if (sp0 < -var_f0) {
        if (arg0->unk22C != 0x64) {
            var_2 = (u8) arg0->unk22C;
        } else {
            var_2 = 1;
        }
        temp_4->pad[9] = var_2;
    }
    if (fabsf(sp0) > 2.0943952f) {
        temp_4_2 = arg0->self;
        var_2 = (u8) temp_4_2->aiOrPlayerIdx;
        if (var_2 == 0) {
            temp_4_2->pad[2] = 1;
            var_2 = (u8) arg0->self;
            var_2->unk48B = 1;
        }
    }
    return (s32) var_2;
}

/* ---- func_00130E88 ---- */
extern ? D_003156C0;

void func_00130E88(Driver* arg0, s32 arg1) {
    AIBrain* temp_2;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 var_f20;
    s32 temp_3_2;
    s32 var_17;
    s32 var_18;
    void* temp_3;
    void** var_19;

    if (arg0->mode != arg1) {
        if (arg1 != 6) {
            arg0->mode = arg1;
            arg0->subState = 0;
            if (arg1 == 5) {
                var_f20 = 1e8f;
                var_17 = 0;
                var_19 = &D_003156C0 + 0xB0;
                var_18 = *D_003156C0.unk4;
                arg0->subState = 4;
                do {
                    temp_3 = *var_19;
                    if ((temp_3 != NULL) && (temp_3->unk590 == 1)) {
                        temp_f0 = mathfManhatDist__FP8_fvectorT0(arg0->selfCs + 0x10, temp_3->unk2028 + 0x10);
                        if (temp_f0 < var_f20) {
                            var_f20 = temp_f0;
                            var_18 = var_17;
                        }
                    }
                    var_17 += 1;
                    var_19 += 0x220;
                } while (var_17 < 8);
                func_00130C00(arg0, ((var_18 * 0x220) + &D_003156C0)->unkB0);
            } else if (arg1 == 4) {
                temp_2 = arg0->self->brain;
                if (temp_2 != NULL) {
                    temp_2->unk434 = 0;
                }
            }
        } else {
            arg0->mode = 5;
            arg0->subState = 4;
        }
        arg0->ticks228 = 0;
        arg0->performing = 0;
        if (arg0->turning == 0) {
            if (arg0->following == 0) {
                driverGetNewPointInFrontOfVehicle__6DriverP7Vehicle(arg0, arg0->self);
                temp_f0_2 = arg0->self->cruiseSpeed;
                arg0->minSpeed = temp_f0_2;
                arg0->speedLimit = temp_f0_2;
                temp_3_2 = D_004FA030->levelType;
                if (temp_3_2 != 8) {
                    if (temp_3_2 < 9) {
                        if (temp_3_2 != 4) {

                        } else {
                            goto block_23;
                        }
                    } else if (temp_3_2 == 0x14) {
                        goto block_23;
                    }
                } else {
block_23:
                    temp_f0_3 = arg0->self->cruiseSpeed * 0.5f;
                    arg0->minSpeed = temp_f0_3;
                    arg0->speedLimit = temp_f0_3;
                }
            }
        }
        arg0->unk22C = 0x64;
    }
}

