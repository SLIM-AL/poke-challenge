#ifndef GUARD_SAFARI_ZONE_H
#define GUARD_SAFARI_ZONE_H

#include "global.h"

extern u8 gNumSafariBalls;

bool32 GetSafariZoneFlag(void);
void SetSafariZoneFlag(void);
void ResetSafariZoneFlag(void);

void EnterSafariMode(void);
void ExitSafariMode(void);

bool8 SafariZoneTakeStep(void);
void SafariZoneRetirePrompt(void);

#endif // GUARD_SAFARI_ZONE_H
