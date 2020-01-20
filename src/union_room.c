#include "global.h"
#include "gflib.h"
#include "event_data.h"
#include "link.h"
#include "link_rfu.h"
#include "list_menu.h"
#include "new_menu_helpers.h"
#include "script.h"
#include "task.h"
#include "union_room.h"

EWRAM_DATA union UnkUnion_Main gUnknown_203B05C = {};
EWRAM_DATA u8 gUnknown_203B058 = 0;
EWRAM_DATA u8 gUnknown_203B059 = 0;

IWRAM_DATA struct UnkStruct_Leader *gUnknown_3002024;

void sub_8115A68(u8 taskId);
void sub_81161E4(struct UnkStruct_Leader * leader);
bool8 sub_8116444(struct UnkStruct_Leader * leader, u32 a1, u32 a2);
u8 sub_81165E8(struct UnkStruct_Main0 * a0);
void sub_8117990(void);
u16 sub_8118658(const u8 *data);
u8 sub_811A054(struct UnkStruct_Main4 *arg0, u32 arg1);
bool8 sub_811A0F8(u8 *textState, const u8 *str);
s8 sub_811A14C(u8 *dest, bool32 arg1);
void sub_811A444(u8 windowId, u8 fontId, const u8 *str, u8 x, u8 y, u8 colorIdx);
void sub_811A5E4(struct UnkStruct_x20 *arg0, u8 count);
void sub_811A650(struct UnkStruct_Main4 *arg0, u8 count);

extern const u8 *const gUnknown_8456C74[];
extern const struct WindowTemplate gUnknown_8456CD0;
extern const u32 gUnknown_8456CD8[];
extern const struct WindowTemplate gUnknown_8456CFC;
extern const struct WindowTemplate gUnknown_8456D04;
extern const struct ListMenuTemplate gUnknown_8456D34;
extern const u8 gUnknown_84571B4[];
extern const u8 gUnknown_8457234[];
extern const u8 gUnknown_8457264[];
extern const u8 gUnknown_845747C[];
extern const u8 gUnknown_8457514[];
extern const u8 gUnknown_8457530[];
extern const u8 gUnknown_8457554[];
extern const u8 gUnknown_8457610[];
extern const u8 *const gUnknown_845767C[];
extern const u8 *const gUnknown_845742C[][5];

void sub_811586C(u8 windowId, u8 arg1, u8 stringId)
{
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    switch (arg1 << 8)
    {
    case 0x200:
        sub_811A444(windowId, 2, gUnknown_845742C[0][stringId - 1], 0, 2, 0);
        break;
    case 0x400:
        sub_811A444(windowId, 2, gUnknown_845742C[1][stringId - 1], 0, 2, 0);
        break;
    case 0x2500:
        sub_811A444(windowId, 2, gUnknown_845742C[2][stringId - 1], 0, 2, 0);
        break;
    case 0x3500:
        sub_811A444(windowId, 2, gUnknown_845742C[3][stringId - 1], 0, 2, 0);
        break;
    }

    CopyWindowToVram(windowId, 2);
}

void sub_8115924(u8 windowId)
{
    u8 text[12];
    u8 text2[12];

    sub_811A444(windowId, 2, gSaveBlock2Ptr->playerName, 0, 2, 0);
    StringCopy(text2, gUnknown_84571B4);
    ConvertIntToDecimalStringN(text, sub_8118658(gSaveBlock2Ptr->playerTrainerId), STR_CONV_MODE_LEADING_ZEROS, 5);
    StringAppend(text2, text);
    sub_811A444(windowId, 0, text2, 0, 0x10, 0);
}

void sub_811599C(u8 *dst, u8 caseId)
{
    switch (caseId)
    {
    case 1 ... 4:
    case 9 ... 11:
    case 21 ... 22:
        // UB: argument *dst isn't used, instead it always prints to gStringVar4
        StringExpandPlaceholders(gStringVar4, gUnknown_8457234);
        break;
    }
}

void TryBecomeLinkLeader(void)
{
    u8 taskId;
    struct UnkStruct_Leader *dataPtr;

    taskId = CreateTask(sub_8115A68, 0);
    gUnknown_203B05C.leader = dataPtr = (void*)(gTasks[taskId].data);
    gUnknown_3002024 = dataPtr;

    dataPtr->state = 0;
    dataPtr->textState = 0;
    gSpecialVar_Result = 0;
}

void sub_8115A68(u8 taskId)
{
    u32 id, val;
    struct UnkStruct_Leader *data = gUnknown_203B05C.leader;

    switch (data->state)
    {
    case 0:
        gUnknown_203B058 = gUnknown_8456CD8[gSpecialVar_0x8004];
        gUnknown_203B059 = gUnknown_8456CD8[gSpecialVar_0x8004] >> 8;
        sub_80FAF58(gUnknown_203B058, 0, 0);
        sub_800B1F4();
        OpenLink();
        sub_80FBB8C(gUnknown_203B059 & 0xF);
        data->state = 3;
        break;
    case 3:
        data->field_4 = AllocZeroed(0x70);
        data->field_0 = AllocZeroed(0xA0);
        data->field_8 = AllocZeroed(0xA0);
        sub_811A650(data->field_4, 4);
        sub_811A5E4(data->field_0->arr, 5);
        LinkRfu3_SetGnameUnameFromStaticBuffers(&data->field_0->arr[0].unk.field_0, data->field_0->arr[0].unk.playerName);
        data->field_0->arr[0].field_18 = 0;
        data->field_0->arr[0].field_1A_0 = 1;
        data->field_0->arr[0].field_1A_1 = 0;
        data->field_0->arr[0].field_1B = 0;
        data->field_17 = sub_811A054(data->field_4, 0xFF);
        data->field_10 = AddWindow(&gUnknown_8456CD0);
        data->listWindowId = AddWindow(&gUnknown_8456CFC);
        data->field_11 = AddWindow(&gUnknown_8456D04);

        FillWindowPixelBuffer(data->field_10, PIXEL_FILL(2));
        sub_811A444(data->field_10, 0, gUnknown_845747C, 8, 2, 4);
        PutWindowTilemap(data->field_10);
        CopyWindowToVram(data->field_10, 2);

        DrawStdWindowFrame(data->listWindowId, FALSE);
        gMultiuseListMenuTemplate = gUnknown_8456D34;
        gMultiuseListMenuTemplate.windowId = data->listWindowId;
        data->listTaskId = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);

        DrawStdWindowFrame(data->field_11, FALSE);
        PutWindowTilemap(data->field_11);
        CopyWindowToVram(data->field_11, 2);

        CopyBgTilemapBufferToVram(0);
        data->field_13 = 1;
        data->state = 4;
        break;
    case 4:
        StringCopy(gStringVar1, gUnknown_8456C74[gUnknown_203B058]);
        if ((gUnknown_203B059 >> 4) != 0)
        {
            if (data->field_13 > (gUnknown_203B059 >> 4) - 1 && (gUnknown_203B059 & 0xF) != 0)
                StringExpandPlaceholders(gStringVar4, gUnknown_8457264);
            else
                StringExpandPlaceholders(gStringVar4, gUnknown_8457234);
        }
        else
        {
            sub_811599C(gStringVar4, gUnknown_203B058);
        }

        sub_811586C(data->field_11, gUnknown_203B059, data->field_13);
        data->state = 5;
        break;
    case 5:
        if (sub_811A0F8(&data->textState, gStringVar4))
            data->state = 6;
        break;
    case 6:
        sub_8116444(data, 7, 10);
        if (gMain.newKeys & B_BUTTON)
        {
            if (data->field_13 == 1)
                data->state = 23;
            else if ((gUnknown_203B059 & 0xF0) != 0)
                data->state = 30;
            else
                data->state = 19;
        }
        if ((gUnknown_203B059 >> 4) != 0
            && data->field_13 > (gUnknown_203B059 >> 4) - 1
            && (gUnknown_203B059 & 0xF) != 0
            && sub_80FC1CC()
            && gMain.newKeys & START_BUTTON)
        {
            data->state = 15;
            sub_80F8F5C();
        }
        if (data->state == 6 && sub_80FA5D4())
        {
            data->state = 9;
        }
        break;
    case 9:
        if (!sub_80FA5D4())
        {
            data->state = 6;
            data->field_13 = sub_81165E8(data->field_0);
        }
        break;
    case 10:
        id = ((gUnknown_203B058 & 0xF) == 2) ? 1 : 0;
        if (sub_811A0F8(&data->textState, gUnknown_845767C[id]))
        {
            data->field_13 = sub_81165E8(data->field_0);
            RedrawListMenu(data->listTaskId);
            data->state = 4;
        }
        break;
    case 29:
        id = ((gUnknown_203B059 & 0xF) == 2) ? 0 : 1;
        if (sub_811A0F8(&data->textState, gUnknown_845767C[id]))
        {
            data->state = 21;
        }
        break;
    case 7:
        if (sub_811A0F8(&data->textState, gStringVar4))
        {
            data->state = 11;
        }
        break;
    case 11:
        switch (sub_811A14C(&data->textState, sub_80FA634(sub_8118658(data->field_0->arr[data->field_13].unk.field_0.unk_00.playerTrainerId), data->field_0->arr[data->field_13].unk.playerName)))
        {
        case 0:
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(0, 0);
            data->field_19 = 5;
            sub_80FA670(5, sub_8118658(data->field_0->arr[data->field_13].unk.field_0.unk_00.playerTrainerId), data->field_0->arr[data->field_13].unk.playerName);
            data->state = 12;
            break;
        case 1:
        case -1:
            data->field_19 = 6;
            sub_80FA670(6, sub_8118658(data->field_0->arr[data->field_13].unk.field_0.unk_00.playerTrainerId), data->field_0->arr[data->field_13].unk.playerName);
            data->state = 12;
            break;
        case -3:
            data->state = 9;
            break;
        }
        break;
    case 12:
        val = sub_80FA6FC(sub_8118658(data->field_0->arr[data->field_13].unk.field_0.unk_00.playerTrainerId), data->field_0->arr[data->field_13].unk.playerName);
        if (val == 1)
        {
            if (data->field_19 == 5)
            {
                data->field_0->arr[data->field_13].field_1B = 0;
                RedrawListMenu(data->listTaskId);
                data->field_13++;
                if (data->field_13 == (gUnknown_203B059 & 0xF))
                {
                    if ((gUnknown_203B059 & 0xF0) != 0 || data->field_13 == 4)
                    {
                        data->state = 15;
                    }
                    else
                    {
                        StringCopy7(gStringVar1, data->field_0->arr[data->field_13 - 1].unk.playerName);
                        ConvertInternationalString(gStringVar1, data->field_0->arr[data->field_13 - 1].unk.field_0.unk_00.unk_00_0);
                        StringExpandPlaceholders(gStringVar4, gUnknown_8457554);
                        data->state = 13;
                    }

                    sub_80F8F5C();
                    sub_811586C(data->field_11, gUnknown_203B059, data->field_13);
                }
                else
                {
                    data->state = 4;
                }
            }
            else
            {
                sub_80FBD4C(data->field_0->arr[data->field_13].unk.playerName, sub_8118658(data->field_0->arr[data->field_13].unk.field_0.unk_00.playerTrainerId));
                data->field_0->arr[data->field_13].field_1A_0 = 0;
                sub_81165E8(data->field_0);
                RedrawListMenu(data->listTaskId);
                data->state = 4;
            }

            data->field_19 = 0;
        }
        else if (val == 2)
        {
            sub_80FB9E4(0, 0);
            data->state = 4;
        }
        break;
    case 13:
        if (sub_811A0F8(&data->textState, gStringVar4))
            data->state = 14;
        break;
    case 14:
        if (++data->field_E > 120)
            data->state = 17;
        break;
    case 15:
        if (sub_811A0F8(&data->textState, gUnknown_8457514))
            data->state = 16;
        break;
    case 16:
        switch (sub_811A14C(&data->textState, FALSE))
        {
        case 0:
            data->state = 17;
            break;
        case 1:
        case -1:
            if ((gUnknown_203B059 & 0xF0) != 0)
                data->state = 30;
            else
                data->state = 19;
            break;
        }
        break;
    case 19:
        if (sub_811A0F8(&data->textState, gUnknown_8457530))
            data->state = 20;
        break;
    case 20:
        switch (sub_811A14C(&data->textState, FALSE))
        {
        case 0:
            data->state = 23;
            break;
        case 1:
        case -1:
            if ((gUnknown_203B059 & 0xF0) != 0)
                data->state = 15;
            else if (data->field_13 == (gUnknown_203B059 & 0xF))
                data->state = 15;
            else
                data->state = 4;
            break;
        }
        break;
    case 17:
        if (!sub_8116444(data, 7, 23))
            data->state = 18;
        break;
    case 18:
        if (sub_80F8F40())
        {
            if (sub_80F8F7C(FALSE))
            {
                data->state = 26;
            }
        }
        else
        {
            data->state = 29;
            data->textState = 0;
        }
        break;
    case 30:
        if (sub_811A0F8(&data->textState, gUnknown_8457610))
            data->state = 23;
        break;
    case 21:
    case 23:
        DestroyWirelessStatusIndicatorSprite();
        sub_80F8DC0();
        sub_81161E4(data);
        data->state++;
        break;
    case 24:
        EnableBothScriptContexts();
        DestroyTask(taskId);
        gSpecialVar_Result = 5;
        break;
    case 22:
        EnableBothScriptContexts();
        DestroyTask(taskId);
        gSpecialVar_Result = 8;
        break;
    case 26:
        if (sub_80FBA00())
        {
            data->state = 29;
        }
        else
        {
            if (gReceivedRemoteLinkPlayers != 0)
            {
                sub_80FAFE0(1);
                sub_8117990();
                sub_81161E4(data);
                DestroyTask(taskId);
            }
        }
        break;
    }
}
