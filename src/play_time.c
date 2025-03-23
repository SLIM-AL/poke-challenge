#include "play_time.h"
#include "event_data.h"
#include "sound.h"
#include "start_menu.h"
#include "constants/songs.h"

static u8 sPlayTimeCounterState;

enum
{
    STOPPED,
    RUNNING,
    MAXED_OUT,
};

void PlayTimeCounter_Reset(void)
{
    sPlayTimeCounterState = STOPPED;
    gSaveBlock2Ptr->playTimeHours = 0;
    gSaveBlock2Ptr->playTimeMinutes = 0;
    gSaveBlock2Ptr->playTimeSeconds = 0;
    gSaveBlock2Ptr->playTimeVBlanks = 0;
}

void PlayTimeCounter_Start(void)
{
    sPlayTimeCounterState = RUNNING;
    if (gSaveBlock2Ptr->playTimeHours > 999)
        PlayTimeCounter_SetToMax();
}

void PlayTimeCounter_Stop(void)
{
    sPlayTimeCounterState = STOPPED;
}

void PlayTimeCounter_Update(void)
{
    if (!FlagGet(FLAG_CHALLENGE_NOT_OVER) || (sPlayTimeCounterState != RUNNING)) {
        return;
    }
    gSaveBlock2Ptr->playTimeVBlanks++;
    if (JOY_NEW(SELECT_BUTTON) || JOY_HELD(SELECT_BUTTON))
    {
        if (gSaveBlock2Ptr->playTimeVBlanks % 60 == 0)
        {
            PlaySE(SE_CLICK);
        }
        else if (gSaveBlock2Ptr->playTimeVBlanks % 30 == 0)
        {
            PlaySE(SE_CLICK);
        }
    }
    if (gSaveBlock2Ptr->playTimeVBlanks > 59)
    {
        gSaveBlock2Ptr->playTimeVBlanks = 0;
        gSaveBlock2Ptr->playTimeSeconds++;
        if (gSaveBlock2Ptr->playTimeSeconds > 59)
        {
            if (JOY_NEW(SELECT_BUTTON) || JOY_HELD(SELECT_BUTTON))
            {
                PlaySE(SE_ITEMFINDER);
            }
            gSaveBlock2Ptr->playTimeSeconds = 0;
            gSaveBlock2Ptr->playTimeMinutes++;
            if (gSaveBlock2Ptr->playTimeMinutes > 59)
            {
                gSaveBlock2Ptr->playTimeMinutes = 0;
                gSaveBlock2Ptr->playTimeHours++;
                if (gSaveBlock2Ptr->playTimeHours > 999)
                    PlayTimeCounter_SetToMax();
            }
        }
    }
}

void PlayTimeCounter_SetToMax(void)
{
    sPlayTimeCounterState = MAXED_OUT;
    gSaveBlock2Ptr->playTimeHours = 999;
    gSaveBlock2Ptr->playTimeMinutes = 59;
    gSaveBlock2Ptr->playTimeSeconds = 59;
    gSaveBlock2Ptr->playTimeVBlanks = 59;
    PlaySE(SE_FAILURE);
}
