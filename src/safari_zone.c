#include "global.h"
#include "battle.h"
#include "event_scripts.h"
#include "overworld.h"
#include "script.h"
#include "event_data.h"
#include "sound.h"
#include "start_menu.h"
#include "constants/songs.h"
#include "field_screen_effect.h"

EWRAM_DATA u8 gNumSafariBalls = 0;
EWRAM_DATA u16 gSafariZoneStepCounter = 0;

bool32 GetSafariZoneFlag(void)
{
    return FlagGet(FLAG_SYS_SAFARI_MODE);
}

void SetSafariZoneFlag(void)
{
    FlagSet(FLAG_SYS_SAFARI_MODE);
}

void ResetSafariZoneFlag(void)
{
    FlagClear(FLAG_SYS_SAFARI_MODE);
}

void EnterSafariMode(void)
{
    IncrementGameStat(GAME_STAT_ENTERED_SAFARI_ZONE);
    SetSafariZoneFlag();
    gNumSafariBalls = 30;
    gSafariZoneStepCounter = 600;
}

void ExitSafariMode(void)
{
    ResetSafariZoneFlag();
    gNumSafariBalls = 0;
    gSafariZoneStepCounter = 0;
}

bool8 SafariZoneTakeStep(void)
{
    u16 i;
    u16 limit = 5;
    for (i = 0; i < 14; ++i) {
      if (FlagGet(FLAG_EXT1+i)) limit += (i/2)+1;
    }
    if ((limit < 61) && FlagGet(FLAG_CHALLENGE_NOT_OVER) && (gSaveBlock2Ptr->playTimeHours >= limit))
    {
        PlaySE(SE_DING_DONG);
        FlagClear(FLAG_CHALLENGE_NOT_OVER);
        ExitSafariMode();
        ScriptContext_SetupScript(SafariZone_EventScript_ChallengeDone);
        return TRUE;
    }

    if (GetSafariZoneFlag() == FALSE)
        return FALSE;
    gSafariZoneStepCounter--;
    if (gSafariZoneStepCounter == 0)
    {
        ScriptContext_SetupScript(SafariZone_EventScript_TimesUp);
        return TRUE;
    }
    return FALSE;
}

void SafariZoneRetirePrompt(void)
{
    ScriptContext_SetupScript(SafariZone_EventScript_RetirePrompt);
}

void CB2_EndSafariBattle(void)
{
    if (gNumSafariBalls != 0)
    {
        SetMainCallback2(CB2_ReturnToField);
    }
    else if (gBattleOutcome == B_OUTCOME_NO_SAFARI_BALLS)
    {
        RunScriptImmediately(SafariZone_EventScript_OutOfBallsMidBattle);
        WarpIntoMap();
        gFieldCallback = FieldCB_SafariZoneRanOutOfBalls;
        SetMainCallback2(CB2_LoadMap);
    }
    else if (gBattleOutcome == B_OUTCOME_CAUGHT)
    {
        ScriptContext_SetupScript(SafariZone_EventScript_OutOfBalls);
        ScriptContext_Stop();
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
    }
}
