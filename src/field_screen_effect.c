#include "global.h"
#include "field_screen_effect.h"
#include "gpu_regs.h"
#include "overworld.h"
#include "scanline_effect.h"
#include "script.h"
#include "task.h"

static const u16 sFlashLevelPixelRadii[] = {
    0x00c8, 0x0048, 0x0038, 0x0028, 0x0018, 0x0000
};

static void Task_EnableScriptAfterMusicFade(u8 taskId);
static void Task_BarnDoorWipeChild(u8 taskId);

static void SetFlashScanlineEffectWindowBoundary(u16 *dest, u32 y, s32 left, s32 right)
{
    if (y <= 160)
    {
        if (left < 0)
            left = 0;
        if (left > 255)
            left = 255;
        if (right < 0)
            right = 0;
        if (right > 255)
            right = 255;
        dest[y] = (left << 8) | right;
    }
}

/*
 * Draws a circle by approximating xy² + yx² = radius².
 *
 * error is approximately xy² - yx². Negative values mean the circle is
 * slightly too large, and positive values mean the circle is slightly
 * too small. By decreasing xy whenever the error becomes negative the
 * code slightly under-approximates the size of the circle.
 *
 * The subtractive terms compute yx² - (yx - 1)², and therefore the sum
 * is yx² - 1:
 *   yx               |  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7
 *   (yx * 2) - 1     | -1 |  1 |  3 |  5 |  7 |  9 | 11 | 13
 *   yx² - (yx - 1)²  | -1 |  1 |  3 |  5 |  7 |  9 | 11 | 13
 *   cumulative error | -1 |  0 |  3 |  8 | 15 | 24 | 35 | 48
 *   yx²              |  0 |  1 |  4 |  9 | 16 | 25 | 36 | 49
 *
 * The additive terms compute xy² - (xy - 1)² - 1, and therefore the sum
 * (badly) approximates Σi² - (i - 1)², i ∈ (xy, r), consider r = 18:
 *   xy               | 18 | 17 | 16 |  15 |  14 |  13 | ... |   0
 *   xy² - (xy - 1)²  | 35 | 33 | 31 |  29 |  27 |  25 | ... |  -1
 *   2 * (xy - 1)     | 34 | 32 | 30 |  28 |  26 |  24 | ... |  -2
 *   cumulative error | 34 | 66 | 96 | 124 | 150 | 174 | ... | 304
 *   Σi² - (i - 1)²   | 35 | 68 | 99 | 128 | 155 | 180 | ... | 323
 * 18² = 324, so if the iterations ran until xy = 0 the cumulative error
 * would be xy² - r.
 *
 * The error is initialized to r, which corrects for the error in the
 * additive terms. In practice all r iterations don't occur because we
 * early-exit when yx > xy, so it's half-way between a fix for that
 * error and an approximation of the midpoint between r² and (r + 1)².
 *
 * The algorithm takes advantage of symmetry to compute boundaries in
 * both directions out from centerY (using yx for y), and also both
 * directions *in* from centerY ± radius (using xy for y). Because xy
 * doesn't change on every iteration, we will frequently overwrite
 * boundaries set in the previous iteration.
 */
void SetFlashScanlineEffectWindowBoundaries(u16 *dest, s32 centerX, s32 centerY, s32 radius)
{
    s32 xy = radius;
    s32 error = radius;
    s32 yx = 0;
    while (xy >= yx)
    {
        SetFlashScanlineEffectWindowBoundary(dest, centerY - yx, centerX - xy, centerX + xy);
        SetFlashScanlineEffectWindowBoundary(dest, centerY + yx, centerX - xy, centerX + xy);
        SetFlashScanlineEffectWindowBoundary(dest, centerY - xy, centerX - yx, centerX + yx);
        SetFlashScanlineEffectWindowBoundary(dest, centerY + xy, centerX - yx, centerX + yx);
        error -= (yx * 2) - 1;
        yx++;
        if (error < 0)
        {
            error += 2 * (xy - 1);
            xy--;
        }
    }
}

#define tState               data[0]
#define tFlashCenterX        data[1]
#define tFlashCenterY        data[2]
#define tCurFlashRadius      data[3]
#define tDestFlashRadius     data[4]
#define tFlashRadiusDelta    data[5]
#define tClearScanlineEffect data[6]

static void UpdateFlashLevelEffect(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        SetFlashScanlineEffectWindowBoundaries(gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer], tFlashCenterX, tFlashCenterY, tCurFlashRadius);
        tState = 1;
        break;
    case 1:
        SetFlashScanlineEffectWindowBoundaries(gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer], tFlashCenterX, tFlashCenterY, tCurFlashRadius);
        tState = 0;
        tCurFlashRadius += tFlashRadiusDelta;
        if (tCurFlashRadius > tDestFlashRadius)
        {
            if (tClearScanlineEffect == TRUE)
            {
                ScanlineEffect_Stop();
                tState = 2;
            }
            else
            {
                DestroyTask(taskId);
            }
        }
        break;
    case 2:
        ScanlineEffect_Clear();
        DestroyTask(taskId);
        break;
    }
}

static void sub_807EF7C(u8 taskId)
{
    if (!FuncIsActiveTask(UpdateFlashLevelEffect))
    {
        EnableBothScriptContexts();
        DestroyTask(taskId);
    }
}

static void sub_807EFA4(void)
{
    if (!FuncIsActiveTask(sub_807EF7C))
        CreateTask(sub_807EF7C, 80);
}

static u8 sub_807EFC8(s32 centerX, s32 centerY, s32 initialFlashRadius, s32 destFlashRadius, bool32 clearScanlineEffect, u8 delta)
{
    u8 taskId = CreateTask(UpdateFlashLevelEffect, 80);
    s16 *data = gTasks[taskId].data;

    tCurFlashRadius = initialFlashRadius;
    tDestFlashRadius = destFlashRadius;
    tFlashCenterX = centerX;
    tFlashCenterY = centerY;
    tClearScanlineEffect = clearScanlineEffect;

    if (initialFlashRadius < destFlashRadius)
        tFlashRadiusDelta = delta;
    else
        tFlashRadiusDelta = -delta;

    return taskId;
}

#undef tState
#undef tCurFlashRadius
#undef tDestFlashRadius
#undef tFlashRadiusDelta
#undef tClearScanlineEffect

void AnimateFlash(u8 flashLevel)
{
    u8 curFlashLevel = Overworld_GetFlashLevel();
    bool32 value = FALSE;
    if (!flashLevel)
        value = TRUE;
    sub_807EFC8(120, 80, sFlashLevelPixelRadii[curFlashLevel], sFlashLevelPixelRadii[flashLevel], value, 2);
    sub_807EFA4();
    ScriptContext2_Enable();
}

void WriteFlashScanlineEffectBuffer(u8 flashLevel)
{
    if (flashLevel)
    {
        SetFlashScanlineEffectWindowBoundaries(&gScanlineEffectRegBuffers[0][0], 120, 80, sFlashLevelPixelRadii[flashLevel]);
        CpuFastCopy(&gScanlineEffectRegBuffers[0], &gScanlineEffectRegBuffers[1], 240 * 8);
    }
}

void sub_807F0B0(void)
{
    Overworld_FadeOutMapMusic();
    CreateTask(Task_EnableScriptAfterMusicFade, 80);
}

static void Task_EnableScriptAfterMusicFade(u8 taskId)
{
    if (BGMusicStopped() == TRUE)
    {
        DestroyTask(taskId);
        EnableBothScriptContexts();
    }
}

#define tState data[9]
#define tDirection data[10]
#define DIR_WIPE_IN 0 // From edges to center.
#define DIR_WIPE_OUT 1 // From center to edges.
#define tChildOffset data[0]

static void DoInwardBarnDoorFade(void)
{
    u8 taskId = CreateTask(Task_BarnDoorWipe, 80);
    gTasks[taskId].tDirection = DIR_WIPE_IN;
}

void DoOutwardBarnDoorWipe(void)
{
    u8 taskId = CreateTask(Task_BarnDoorWipe, 80);
    gTasks[taskId].tDirection = DIR_WIPE_OUT;
}

static void BarnDoorWipeSaveGpuRegs(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    data[0] = GetGpuReg(REG_OFFSET_DISPCNT);
    data[1] = GetGpuReg(REG_OFFSET_WININ);
    data[2] = GetGpuReg(REG_OFFSET_WINOUT);
    data[3] = GetGpuReg(REG_OFFSET_BLDCNT);
    data[4] = GetGpuReg(REG_OFFSET_BLDALPHA);
    data[5] = GetGpuReg(REG_OFFSET_WIN0H);
    data[6] = GetGpuReg(REG_OFFSET_WIN0V);
    data[7] = GetGpuReg(REG_OFFSET_WIN1H);
    data[8] = GetGpuReg(REG_OFFSET_WIN1V);
}

static void BarnDoorWipeLoadGpuRegs(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    SetGpuReg(REG_OFFSET_DISPCNT, data[0]);
    SetGpuReg(REG_OFFSET_WININ, data[1]);
    SetGpuReg(REG_OFFSET_WINOUT, data[2]);
    SetGpuReg(REG_OFFSET_BLDCNT, data[3]);
    SetGpuReg(REG_OFFSET_BLDALPHA, data[4]);
    SetGpuReg(REG_OFFSET_WIN0H, data[5]);
    SetGpuReg(REG_OFFSET_WIN0V, data[6]);
    SetGpuReg(REG_OFFSET_WIN1H, data[7]);
    SetGpuReg(REG_OFFSET_WIN1V, data[8]);
}

void Task_BarnDoorWipe(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    switch (tState)
    {
        case 0:
            BarnDoorWipeSaveGpuRegs(taskId);
            SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
            SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN1_ON);
            if (data[10] == 0)
            {
                SetGpuReg(REG_OFFSET_WIN0H, 0);
                SetGpuReg(REG_OFFSET_WIN1H, WIN_RANGE(240, 255));
                SetGpuReg(REG_OFFSET_WIN0V, 255);
                SetGpuReg(REG_OFFSET_WIN1V, 255);
            }
            else
            {
                SetGpuReg(REG_OFFSET_WIN0H, 120);
                SetGpuReg(REG_OFFSET_WIN0V, 255);
                SetGpuReg(REG_OFFSET_WIN1H, WIN_RANGE(120, 255));
                SetGpuReg(REG_OFFSET_WIN1V, 255);
            }
            SetGpuReg(REG_OFFSET_WININ, 0);
            SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
            tState = 1;
            break;
        case 1:
            CreateTask(Task_BarnDoorWipeChild, 80);
            tState = 2;
            break;
        case 2:
            if (!FuncIsActiveTask(Task_BarnDoorWipeChild))
            {
                tState = 3;
            }
            break;
        case 3:
            BarnDoorWipeLoadGpuRegs(taskId);
            DestroyTask(taskId);
            break;
    }
}

// TODO: Find an implicit way to generate lhs/rhs shifts.
static void Task_BarnDoorWipeChild(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
	u8 parentTaskId = FindTaskIdByFunc(Task_BarnDoorWipe);
    u32 lhs, rhs;
    if (gTasks[parentTaskId].tDirection == DIR_WIPE_IN)
    {
        lhs = (u16)tChildOffset;
        rhs = (u16)(240 - lhs);
        if ((s16)lhs > 120)
        {
            DestroyTask(taskId);
            return;
        }
    }
    else
    {
        u16 offset = tChildOffset;
        u32 lhs2 = (120 - offset) << 16;
        u32 rhs2 = (120 + offset) << 16;
        lhs = lhs2 >> 16;
        rhs = rhs2 >> 16;
        if ((s16)(lhs2 >> 16) < 0)
        {
            DestroyTask(taskId);
            return;
        }
    }
    lhs <<= 16;
    SetGpuReg(REG_OFFSET_WIN0H, lhs >> 16);
    SetGpuReg(REG_OFFSET_WIN1H, WIN_RANGE((((s16)rhs) << 16) >> 16, 240));
    lhs = (s32)lhs >> 16;
    if ((s32)lhs <= 89)
    {
        tChildOffset += 4;
    }
    else
    {
        tChildOffset += 2;
    }
}

#undef tState
#undef tDirection
#undef DIR_WIPE_IN
#undef DIR_WIPE_OUT
#undef tChildOffset
