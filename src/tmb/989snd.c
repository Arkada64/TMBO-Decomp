#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_StartSoundSystem);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_FlushSoundCommands);

M2C_UNK snd_SendIOPCommandAndWait_2C_6() __asm__("snd_SendIOPCommandAndWait");
extern u8 gStreamingInited_2C_6[] __asm__("gStreamingInited");

void snd_StopSoundSystem(void) {
    snd_SendIOPCommandAndWait_2C_6(1, 0, 0);
    (*(s32*)gStreamingInited_2C_6) = 0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_GetTick);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_GetTick_CB);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_GotReturns);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_PrepareReturnBuffer);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_BankLoad);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_BankLoad_CB);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_BankLoadByLoc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_BankLoadByLoc_CB);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_SendPendingLoadCommand);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_MMDLoad);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_MMDLoad_CB);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_MMDLoadByLoc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_MMDLoadByLoc_CB);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_ResolveBankXREFS);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_UnloadBank);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_UnloadBank_CB);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_UnloadMMD);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_UnloadMMD_CB);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_SetMasterVolume);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_GetMasterVolume);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_GetMasterVolume_CB);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_SetPlaybackMode);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_GetPlaybackMode);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_GetPlaybackMode_CB);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_SetMixerMode);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_PlaySoundVolPanPMPB);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_PlaySoundVolPanPMPB_A);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_PlaySoundVolPanPMPB_CB);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_StopSound);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_PauseSound);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_ContinueSound);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_StopAllSounds);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_PauseAllSoundsInGroup);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_ContinueAllSoundsInGroup);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_SoundIsStillPlaying);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_SoundIsStillPlaying_CB);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_IsSoundALooper);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_IsSoundALooper_CB);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_SetSoundVolPan);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_GetSoundOriginalPitch);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_GetSoundOriginalPitch_CB);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_GetSoundCurrentPitch);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_GetSoundCurrentPitch_CB);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_SetSoundPitch);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_SetSoundPitchBend);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_SetSoundPitchModifier);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_SetSoundParams);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_SetSoundParams_A);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_SetSoundParams_CB);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_AutoVol);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_AutoPan);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_AutoPitch);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_AutoPitchBend);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_SetMIDIRegister);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_GetMIDIRegister);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_GetMIDIRegister_CB);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_SetGlobalExcite);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_GetGlobalExcite);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_GetGlobalExcite_CB);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_GetVoiceAllocation);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_GetVoiceAllocation_CB);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_SendIOPCommandAndWait);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_SendIOPCommandNoWait);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_PostMessage);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_SendCurrentBatch);

extern u8 gCaching_10_207[] __asm__("gCaching");

void snd_StartCaching(void) {
    (*(s32*)gCaching_10_207) = 1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_SendCache);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_InitVAGStreamingEx);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_StopVAGStream);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_StopAllStreams);

M2C_UNK snd_SendIOPCommandNoWait_58_222() __asm__("snd_SendIOPCommandNoWait");
M2C_UNK snd_StreamSafeCdSync_58_222() __asm__("snd_StreamSafeCdSync");
extern u8 gStreamingInited_58_222[] __asm__("gStreamingInited");

void snd_CloseVAGStreaming(void) {
    if ((*(s32*)gStreamingInited_58_222) != 0) {
        snd_StreamSafeCdSync_58_222(0);
        (*(s32*)gStreamingInited_58_222) = 0;
        snd_SendIOPCommandNoWait_58_222(0x35, 0, 0, 0, 0);
    }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_PlayVAGStreamByLoc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_PlayVAGStreamByLoc_A);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_PlayVAGStreamByLoc_CB);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_PauseVAGStream);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_ContinueVAGStream);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_GetVAGStreamQueueCount);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_GetVAGStreamQueueCount_CB);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_GetVAGStreamLoc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_GetVAGStreamLoc_CB);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_GetVAGStreamTimeRemaining);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_GetVAGStreamTimeRemaining_CB);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_GetVAGStreamTotalTime);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_GetVAGStreamTotalTime_CB);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_StreamSafeCheckCDIdle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_StreamSafeCheckCDIdle_CB);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_StreamSafeCdRead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_StreamSafeCdSync);

s32 sceCdBreak_4C_276() __asm__("sceCdBreak");
M2C_UNK snd_SendIOPCommandNoWait_4C_276() __asm__("snd_SendIOPCommandNoWait");
extern u8 gStreamingInited_4C_276[] __asm__("gStreamingInited");

s32 snd_StreamSafeCdBreak(void) {
    if ((*(s32*)gStreamingInited_4C_276) == 0) {
        return sceCdBreak_4C_276();
    }
    snd_SendIOPCommandNoWait_4C_276(0x37, 0, 0, 0, 0);
    return 1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_StreamSafeCdGetError);

s32 sceCdCallback_3C_282() __asm__("sceCdCallback");
extern u8 gCdCallback_3C_282[] __asm__("gCdCallback");
extern u8 gStreamingInited_3C_282[] __asm__("gStreamingInited");

s32 snd_StreamSafeCdCallback(s32 arg0) {
    s32 temp_v0;

    if ((*(s32*)gStreamingInited_3C_282) == 0) {
        return sceCdCallback_3C_282();
    }
    temp_v0 = (*(s32*)gCdCallback_3C_282);
    (*(s32*)gCdCallback_3C_282) = arg0;
    return temp_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_SetReverbType);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_SetReverbDepth);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_AutoReverb);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_LockVoiceAllocator);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_ExternVoiceAlloc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_ExternVoiceFree);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_UnlockVoiceAllocator);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_SRAMMalloc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_SRAMMarkUsed);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_SRAMFree);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_InitMovieSound);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_ResetMovieSound);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_PauseMovieSound);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_CloseMovieSound);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_StartMovieSound);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/989snd", snd_GetTransStatus);

s32 snd_GetDopplerPitchMod(s32 arg0) {
    return (s32) (arg0 * 0x5F4) / 741;
}
