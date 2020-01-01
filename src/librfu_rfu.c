#include "global.h"
#include "librfu.h"

struct RfuHeader
{
    u8 unk00;
    u8 unk01;
    u8 unk02;
    u8 unk03;
    u8 unk04;
    u8 unk05;
    u8 unk06;
    u8 unk07;
    u8 unk08;
    u8 unk09;
    u8 unk0A;
    u8 unk0B;
    u8 unk0C;
    u16 unk0E;
};

struct RfuLocalStruct
{
    u8 unk00;
    u8 unk01;
    u8 unk02;
    u8 unk03;
    u8 unk04;
    u8 unk05;
    u16 unk06;
};

static void rfu_CB_defaultCallback(u8, u16);
static void rfu_CB_reset(u8, u16);
static void rfu_CB_configGameData(u8, u16);
static void rfu_CB_stopMode(u8, u16);
static void rfu_CB_startSearchChild(u8, u16);
static void rfu_CB_pollAndEndSearchChild(u8, u16);
static void rfu_CB_startSearchParent(u8, u16);
static void rfu_CB_pollSearchParent(u8, u16);
static void rfu_CB_pollConnectParent(u8, u16);
static void rfu_CB_pollConnectParent(u8, u16);
static void rfu_CB_disconnect(u8, u16);
static void rfu_CB_CHILD_pollConnectRecovery(u8, u16);
static void rfu_CB_sendData(UNUSED u8, u16);
static void rfu_CB_sendData2(UNUSED u8, u16);
static void rfu_CB_sendData3(u8, u16);
static void rfu_CB_recvData(u8, u16);
static s32 sub_81E349C(u8);
static void sub_81E36B8(void);
static void sub_81E3550(void);
static s32 sub_81E35C4(void);
static void rfu_enableREQCallback(bool8);
static void rfu_STC_clearAPIVariables(void);
static void rfu_STC_readChildList(void);
static void rfu_STC_readParentCandidateList(void);
static void rfu_STC_REQ_callback(u8, u16);
static void rfu_STC_removeLinkData(u8, u8);
static void rfu_STC_fastCopy(const u8 **, u8 **, s32);
static void rfu_STC_clearLinkStatus(u8);
static void rfu_NI_checkCommFailCounter(void);
static u16 rfu_STC_setSendData_org(u8, u8, u8, const void *, u32);
static void rfu_constructSendLLFrame(void);
static u16 rfu_STC_NI_constructLLSF(u8, u8 **, struct NIComm *);
static u16 rfu_STC_UNI_constructLLSF(u8, u8 **);
static void rfu_STC_PARENT_analyzeRecvPacket(void);
static void rfu_STC_CHILD_analyzeRecvPacket(void);
static u16 rfu_STC_analyzeLLSF(u8, const u8 *, u16);
static void rfu_STC_UNI_receive(u8, const struct RfuLocalStruct *, const u8 *);
static void rfu_STC_NI_receive_Receiver(u8, const struct RfuLocalStruct *, const u8 *);
static void rfu_STC_NI_receive_Sender(u8, u8, const struct RfuLocalStruct *, UNUSED const u8 *);
static void rfu_STC_NI_initSlot_asRecvDataEntity(u8, struct NIComm *);
static void rfu_STC_NI_initSlot_asRecvControllData(u8, struct NIComm *);

extern const char _Str_RFU_MBOOT[];
extern const struct RfuHeader _Str_RfuHeader[2];
extern const u16 _Str_Sio32ID[];

struct RfuStruct *gRfuState;
ALIGNED(8) struct RfuSlotStatusUNI *gRfuSlotStatusUNI[4];
struct RfuSlotStatusNI *gRfuSlotStatusNI[4];
struct RfuLinkStatus *gRfuLinkStatus;
struct RfuStatic *gRfuStatic;
struct RfuFixed *gRfuFixed;
ALIGNED(8) struct Unk_3007470 gUnknown_3007470;

u16 rfu_initializeAPI(struct Unk_3001190 *unk0, u16 unk1, IntrFunc *interrupt, bool8 copyInterruptToRam)
{
    u16 i;
    u16 *dst;
    const u16 *src;
    u16 r3;

    // is in EWRAM? 
    if (((u32)unk0 & 0xF000000) == 0x2000000 && copyInterruptToRam)
        return 2;
    // is not 4-byte aligned? 
    if ((u32)unk0 & 3)
        return 2;
    if (copyInterruptToRam)
    {
        // An assert/debug print may have existed before, ie
        // printf("%s %u < %u", "somefile.c:12345", unk1, num)
        // to push this into r3?
        r3 = 0xe64;
        if (unk1 < r3)
            return 1;
    }
    if (!copyInterruptToRam)
    {
        r3 = 0x504; // same as above, this should be r3 not r0
        if (unk1 < r3)
            return 1;
    }
    gRfuLinkStatus = &unk0->linkStatus;
    gRfuStatic = &unk0->static_;
    gRfuFixed = &unk0->fixed;
    gRfuSlotStatusNI[0] = &unk0->NI[0];
    gRfuSlotStatusUNI[0] = &unk0->UNI[0];
    for (i = 1; i < NELEMS(gRfuSlotStatusNI); ++i)
    {
        gRfuSlotStatusNI[i] = &gRfuSlotStatusNI[i - 1][1];
        gRfuSlotStatusUNI[i] = &gRfuSlotStatusUNI[i - 1][1];
    }
    // TODO: Is it possible to fix the following 2 statements? 
    // It's equivalent to: 
    // gRfuFixed->STWIBuffer = &unk0->intr;
    // STWI_init_all(&unk0->intr, interrupt, copyInterruptToRam);
    gRfuFixed->STWIBuffer = (struct RfuIntrStruct *)&gRfuSlotStatusUNI[3][1];
    STWI_init_all((struct RfuIntrStruct *)&gRfuSlotStatusUNI[3][1], interrupt, copyInterruptToRam);
    rfu_STC_clearAPIVariables();
    for (i = 0; i < NELEMS(gRfuSlotStatusNI); ++i)
    {
        gRfuSlotStatusNI[i]->recvBuffer = 0;
        gRfuSlotStatusNI[i]->recvBufferSize = 0;
        gRfuSlotStatusUNI[i]->recvBuffer = 0;
        gRfuSlotStatusUNI[i]->recvBufferSize = 0;
    }
    src = (const u16 *)((u32)&rfu_STC_fastCopy & ~1);
    dst = gRfuFixed->fastCopyBuffer;
    // rfu_REQ_changeMasterSlave is the function next to rfu_STC_fastCopy
    for (r3 = ((void *)rfu_REQ_changeMasterSlave - (void *)rfu_STC_fastCopy) / sizeof(u16), --r3; r3 != 0xFFFF; --r3)
        *dst++ = *src++;
    gRfuFixed->fastCopyPtr = (void *)gRfuFixed->fastCopyBuffer + 1;
    return 0;
}

static void rfu_STC_clearAPIVariables(void)
{
    u16 IMEBackup = REG_IME;
    u8 i, r4;

    REG_IME = 0;
    r4 = gRfuStatic->flags;
    CpuFill16(0, gRfuStatic, sizeof(struct RfuStatic));
    gRfuStatic->flags = r4 & 8;
    CpuFill16(0, gRfuLinkStatus, sizeof(struct RfuLinkStatus));
    gRfuLinkStatus->watchInterval = 4;
    gRfuStatic->nowWatchInterval = 0;
    gRfuLinkStatus->connMode = 0xFF;
    rfu_clearAllSlot();
    gRfuStatic->SCStartFlag = 0;
    for (i = 0; i < NELEMS(gRfuStatic->cidBak); ++i)
        gRfuStatic->cidBak[i] = 0;
    REG_IME = IMEBackup;
}

void rfu_REQ_PARENT_resumeRetransmitAndChange(void)
{
    STWI_set_Callback_M(rfu_STC_REQ_callback);
    STWI_send_ResumeRetransmitAndChangeREQ();
}

u16 rfu_UNI_PARENT_getDRAC_ACK(u8 *ackFlag)
{
    struct RfuIntrStruct *buf;

    *ackFlag = 0;
    if (gRfuLinkStatus->connMode != 1)
        return 0x300;
    buf = rfu_getSTWIRecvBuffer();
    switch (buf->rxPacketAlloc.rfuPacket8.data[0])
    {
    case 40:
    case 54:
        if (buf->rxPacketAlloc.rfuPacket8.data[1] == 0)
            *ackFlag = gRfuLinkStatus->connSlotFlag;
        else
            *ackFlag = buf->rxPacketAlloc.rfuPacket8.data[4];
        return 0;
    default:
        return 0x10;
    }
}

void rfu_setTimerInterrupt(u8 which, IntrFunc *intr)
{
    STWI_init_timer(intr, which);
}

struct RfuIntrStruct *rfu_getSTWIRecvBuffer(void)
{
    return gRfuFixed->STWIBuffer;
}

void rfu_setMSCCallback(void (*callback)(u16))
{
    STWI_set_Callback_S(callback);
}

void rfu_setREQCallback(void (*callback)(u16, u16))
{
    gRfuFixed->reqCallback = callback;
    rfu_enableREQCallback(callback != NULL);
}

static void rfu_enableREQCallback(bool8 enable)
{
    if (enable)
        gRfuStatic->flags |= 8;
    else
        gRfuStatic->flags &= 0xF7;
}

static void rfu_STC_REQ_callback(u8 r5, u16 reqResult)
{
    STWI_set_Callback_M(rfu_CB_defaultCallback);
    gRfuStatic->reqResult = reqResult;
    if (gRfuStatic->flags & 8)
        gRfuFixed->reqCallback(r5, reqResult);
}

static void rfu_CB_defaultCallback(u8 r0, u16 reqResult)
{
    s32 r5;
    u8 i;

    if (r0 == 0xFF)
    {
        if (gRfuStatic->flags & 8)
            gRfuFixed->reqCallback(r0, reqResult);
        r5 = gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag;
        for (i = 0; i < 4; ++i)
            if ((r5 >> i) & 1)
                rfu_STC_removeLinkData(i, 1);
        gRfuLinkStatus->connMode = 0xFF;
    }
}

u16 rfu_waitREQComplete(void)
{
    STWI_poll_CommandEnd();
    return gRfuStatic->reqResult;
}

void rfu_REQ_RFUStatus(void)
{
    STWI_set_Callback_M(rfu_STC_REQ_callback);
    STWI_send_SystemStatusREQ();
}

u32 rfu_getRFUStatus(u8 *status)
{
    if (gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[0] != 0x93)
        return 0x10;
    if (STWI_poll_CommandEnd() == 0)
        *status = gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[7];
    else
        *status = 0xFF;
    return 0;
}

static s32 rfu_MBOOT_CHILD_inheritanceLinkStatus(void)
{
    const char *s1 = _Str_RFU_MBOOT;
    char *s2 = (char *)0x30000F0;
    u16 checksum;
    u16 *r2;
    u8 i;

    while (*s1 != '\0')
        if (*s1++ != *s2++)
            return 1;
    r2 = (u16 *)0x3000000;
    checksum = 0;
    for (i = 0; i < 90; ++i)
        checksum += *r2++;
    if (checksum != *(u16 *)0x30000FA)
        return 1;
    CpuCopy16((u16 *)0x3000000, gRfuLinkStatus, sizeof(struct RfuLinkStatus));
    gRfuStatic->flags |= 0x80;
    return 0;
}

void rfu_REQ_stopMode(void)
{
    vu32 *timerReg;

    if (REG_IME == 0)
    {
        rfu_STC_REQ_callback(61, 6);
        gRfuState->error = 6;
    }
    else
    {
        AgbRFU_SoftReset();
        rfu_STC_clearAPIVariables();
        if (sub_81E349C(8) == 0x8001)
        {
            timerReg = &REG_TMCNT(gRfuState->timerSelect);
            *timerReg = 0;
            *timerReg = (TIMER_ENABLE | TIMER_1024CLK) << 16;
            while (*timerReg << 16 < 262 << 16)
                ;
            *timerReg = 0;
            STWI_set_Callback_M(rfu_CB_stopMode);
            STWI_send_StopModeREQ();
        }
        else
        {
            REG_SIOCNT = SIO_MULTI_MODE;
            rfu_STC_REQ_callback(61, 0);
        }
    }
}

static void rfu_CB_stopMode(u8 a1, u16 reqResult)
{
    if (reqResult == 0)
        REG_SIOCNT = SIO_MULTI_MODE;
    rfu_STC_REQ_callback(a1, reqResult);
}

s32 rfu_REQBN_softReset_and_checkID(void)
{
    s32 r2;

    if (REG_IME == 0)
        return -1;
    AgbRFU_SoftReset();
    rfu_STC_clearAPIVariables();
    if ((r2 = sub_81E349C(30)) == 0)
        REG_SIOCNT = SIO_MULTI_MODE;
    return r2;
}

void rfu_REQ_reset(void)
{
    STWI_set_Callback_M(rfu_CB_reset);
    STWI_send_ResetREQ();
}

static void rfu_CB_reset(u8 a1, u16 reqResult)
{
    if (reqResult == 0)
        rfu_STC_clearAPIVariables();
    rfu_STC_REQ_callback(a1, reqResult);
}

void rfu_REQ_configSystem(u16 r4, u8 r5, u8 r6)
{
    STWI_set_Callback_M(rfu_STC_REQ_callback);
    STWI_send_SystemConfigREQ((r4 & 3) | 0x3C, r5, r6);
    if (r6 == 0)
    {
        gRfuStatic->unk_1a = 1;
    }
    else
    {
        u16 IMEBackup = REG_IME;

        REG_IME = 0;
        gRfuStatic->unk_1a = Div(600, r6);
        REG_IME = IMEBackup;
    }
}

void rfu_REQ_configGameData(u8 r6, u16 r2, const u8 *r4, const u8 *r7)
{
    u8 sp[16];
    u8 i;
    u8 r3;
    const u8 *r5 = r4;
    const u8 *r1;

    sp[0] = r2;
    sp[1] = r2 >> 8;
    if (r6 != 0)
        sp[1] = (r2 >> 8) | 0x80;
    for (i = 2; i < 15; ++i)
        sp[i] = *r4++;
    r3 = 0;
    r1 = r7;
    for (i = 0; i < 8; ++i)
    {
        r3 += *r1++;
        r3 += *r5++;
    }
    sp[15] = ~r3;
    if (r6 != 0)
        sp[14] = 0;
    STWI_set_Callback_M(rfu_CB_configGameData);
    STWI_send_GameConfigREQ(sp, r7);
}

static void rfu_CB_configGameData(u8 ip, u16 r7)
{
    s32 r2, r3;
    u8 *r4;
    u8 i;
    u8 *r1;

    if (r7 == 0)
    {
        r1 = gRfuState->txPacket->rfuPacket8.data;
        r2 = gRfuLinkStatus->my.serialNum = r1[4];
        gRfuLinkStatus->my.serialNum = (r1[5] << 8) | r2;
        r4 = &r1[6];
        if (gRfuLinkStatus->my.serialNum & 0x8000)
        {
            gRfuLinkStatus->my.serialNum = gRfuLinkStatus->my.serialNum ^ 0x8000;
            gRfuLinkStatus->my.multibootFlag = 1;
        }
        else
        {
            gRfuLinkStatus->my.multibootFlag = 0;
        }
        for (i = 0; i < NELEMS(gRfuLinkStatus->my.gname) - 2; ++i)
            gRfuLinkStatus->my.gname[i] = *r4++;
        ++r4;
        for (i = 0; i < NELEMS(gRfuLinkStatus->my.uname) - 1; ++i)
            gRfuLinkStatus->my.uname[i] = *r4++;
    }
    rfu_STC_REQ_callback(ip, r7);
}

void rfu_REQ_startSearchChild(void)
{
    u16 r1;
    
    STWI_set_Callback_M(rfu_CB_defaultCallback);
    STWI_send_SystemStatusREQ();
    r1 = STWI_poll_CommandEnd();
    if (r1 == 0)
    {
        if (gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[7] == 0)
            rfu_STC_clearLinkStatus(1);
    }
    else
    {
        rfu_STC_REQ_callback(25, r1);
    }
    STWI_set_Callback_M(rfu_CB_startSearchChild);
    STWI_send_SC_StartREQ();
}

static void rfu_CB_startSearchChild(u8 r3, u16 reqResult)
{
    if (reqResult == 0)
        gRfuStatic->SCStartFlag = 1;
    rfu_STC_REQ_callback(r3, reqResult);
}

static void rfu_STC_clearLinkStatus(u8 r4)
{
    u8 i;
    
    rfu_clearAllSlot();
    if (r4 != 0)
    {
        CpuFill16(0, gRfuLinkStatus->partner, sizeof(gRfuLinkStatus->partner));
        gRfuLinkStatus->findParentCount = 0;
    }
    for (i = 0; i < NELEMS(gRfuLinkStatus->strength); ++i)
        gRfuLinkStatus->strength[i] = 0;
    gRfuLinkStatus->connCount = 0;
    gRfuLinkStatus->connSlotFlag = 0;
    gRfuLinkStatus->linkLossSlotFlag = 0;
    gRfuLinkStatus->getNameFlag = 0;
}

void rfu_REQ_pollSearchChild(void)
{
    STWI_set_Callback_M(rfu_CB_pollAndEndSearchChild);
    STWI_send_SC_PollingREQ();
}

void rfu_REQ_endSearchChild(void)
{
    STWI_set_Callback_M(rfu_CB_pollAndEndSearchChild);
    STWI_send_SC_EndREQ();
}

static void rfu_CB_pollAndEndSearchChild(u8 r4, u16 reqResult)
{
    if (reqResult == 0)
        rfu_STC_readChildList();
    if (r4 == 26)
    {
        if (gRfuLinkStatus->my.id == 0)
        {
            STWI_set_Callback_M(rfu_CB_defaultCallback);
            STWI_send_SystemStatusREQ();
            if (STWI_poll_CommandEnd() == 0)
                gRfuLinkStatus->my.id = *(u16 *)&gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket32.data[0];
        }
    }
    else if (r4 == 27)
    {
        if (gRfuLinkStatus->connMode == 255)
            gRfuLinkStatus->my.id = 0;
        gRfuStatic->SCStartFlag = 0;
    }
    rfu_STC_REQ_callback(r4, reqResult);
}

static void rfu_STC_readChildList(void)
{
    u32 r5;
    u8 r8 = gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[1];
    u8 *r4;
    u8 i;
    u8 sp[4];
    u8 r2;

    if (r8 != 0)
    {
        r5 = gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket32.data[0];
        STWI_set_Callback_M(rfu_CB_defaultCallback);
        STWI_send_LinkStatusREQ();
        if (STWI_poll_CommandEnd() == 0)
        {
            r4 = &gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[4];
            for (i = 0; i < NELEMS(sp); ++i)
                sp[i] = *r4++;
        }
        gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket32.data[0] = r5;
    }
    for (r4 = &gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[4];
         r8 != 0;
         r4 += 4)
    {
        r2 = r4[2];
        if (r2 < 4 && !((gRfuLinkStatus->connSlotFlag >> r2) & 1) && !((gRfuLinkStatus->linkLossSlotFlag >> r2) & 1))
        {
            if (sp[r2] != 0)
                ++gRfuStatic->lsFixedCount[r2];
            if (gRfuStatic->lsFixedCount[r2] >= 4)
            {
                gRfuStatic->lsFixedCount[r2] = 0;
                gRfuLinkStatus->strength[r2] = 0xFF;
                gRfuLinkStatus->connSlotFlag |= 1 << r2;
                ++gRfuLinkStatus->connCount;
                gRfuLinkStatus->partner[r2].id = *(u16 *)r4;
                gRfuLinkStatus->partner[r2].slot = r2;
                gRfuLinkStatus->connMode = 1;
                gRfuStatic->flags &= 0x7F;
                gRfuStatic->cidBak[r2] = gRfuLinkStatus->partner[r2].id;
            }
        }
        --r8;
    }
}

void rfu_REQ_startSearchParent(void)
{
    STWI_set_Callback_M(rfu_CB_startSearchParent);
    STWI_send_SP_StartREQ();
}

static void rfu_CB_startSearchParent(u8 r5, u16 reqResult)
{
    if (reqResult == 0)
        rfu_STC_clearLinkStatus(0);
    rfu_STC_REQ_callback(r5, reqResult);
}

void rfu_REQ_pollSearchParent(void)
{
    STWI_set_Callback_M(rfu_CB_pollSearchParent);
    STWI_send_SP_PollingREQ();
}

static void rfu_CB_pollSearchParent(u8 r5, u16 reqResult)
{
    if (reqResult == 0)
        rfu_STC_readParentCandidateList();
    rfu_STC_REQ_callback(r5, reqResult);
}

void rfu_REQ_endSearchParent(void)
{
    STWI_set_Callback_M(rfu_STC_REQ_callback);
    STWI_send_SP_EndREQ();
}

static void rfu_STC_readParentCandidateList(void)
{
    u8 r7, r6, r5, r4, r3;
    u8 *r1, *r2;
    struct RfuTgtData *r4_;

    CpuFill16(0, gRfuLinkStatus->partner, sizeof(gRfuLinkStatus->partner));
    r2 = &gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[0];
    r7 = r2[1];
    r2 += 4;
    gRfuLinkStatus->findParentCount = 0;
    for (r6 = 0; r6 < 4 && r7 != 0; ++r6)
    {
        r7 -= 7;
        r1 = r2 + 6;
        r2 += 19;
        r5 = ~*r2;
        ++r2;
        r4 = 0;
        for (r3 = 0; r3 < 8; ++r3)
        {
            r4 += *r2++;
            r4 += *r1++;
        }
        if (r4 == r5)
        {
            r2 -= 28;
            r4_ = &gRfuLinkStatus->partner[gRfuLinkStatus->findParentCount];
            r4_->id = *(u16 *)r2;
            r2 += 2;
            r4_->slot = *r2;
            r2 += 2;
            r4_->serialNum = *(u16 *)r2 & 0x7FFF;
            if (*(u16 *)r2 & 0x8000)
                r4_->multibootFlag = 1;
            else
                r4_->multibootFlag = 0;
            r2 += 2;
            for (r3 = 0; r3 < NELEMS(r4_->gname) - 2; ++r3)
                r4_->gname[r3] = *r2++;
            ++r2;
            for (r3 = 0; r3 < NELEMS(r4_->uname) - 1; ++r3)
                r4_->uname[r3] = *r2++;
            ++gRfuLinkStatus->findParentCount;
        }
    }
}

void rfu_REQ_startConnectParent(u16 r4)
{
    u16 r3 = 0;
    u8 i;
    for (i = 0; i < NELEMS(gRfuLinkStatus->partner) && gRfuLinkStatus->partner[i].id != r4; ++i)
        ;
    if (i == 4)
        r3 = 256;
    if (r3 == 0)
    {
        gRfuStatic->tryPid = r4;
        STWI_set_Callback_M(rfu_STC_REQ_callback);
        STWI_send_CP_StartREQ(r4);
    }
    else
    {
        rfu_STC_REQ_callback(31, r3);
    }
}

void rfu_REQ_pollConnectParent(void)
{
    STWI_set_Callback_M(rfu_CB_pollConnectParent);
    STWI_send_CP_PollingREQ();
}

static void rfu_CB_pollConnectParent(u8 sp24, u16 sp28)
{
    u16 id;
    u8 slot;
    u8 r2, r5;
    struct RfuTgtData *r9;
    struct RfuTgtData sp;

    if (sp28 == 0)
    {
        id = gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket32.data[0];
        slot = gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[6];
        if (gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[7] == 0)
        {
            r2 = 1 << slot;
            if (!(r2 & gRfuLinkStatus->connSlotFlag))
            {
                gRfuLinkStatus->connSlotFlag |= r2;
                gRfuLinkStatus->linkLossSlotFlag &= ~r2;
                gRfuLinkStatus->my.id = id;
                ++gRfuLinkStatus->connCount;
                gRfuLinkStatus->connMode = 0;
                gRfuStatic->flags |= 0x80;
                for (r5 = 0; r5 < NELEMS(gRfuLinkStatus->partner); ++r5)
                {
                    if (gRfuLinkStatus->partner[r5].id == gRfuStatic->tryPid)
                    {
                        if (gRfuLinkStatus->findParentCount != 0)
                        {
                            r9 = &sp;
                            CpuCopy16(&gRfuLinkStatus->partner[r5], &sp, sizeof(struct RfuTgtData));
                            CpuFill16(0, gRfuLinkStatus->partner, sizeof(gRfuLinkStatus->partner));
                            gRfuLinkStatus->findParentCount = 0;
                        }
                        else
                        {
                            r9 = &gRfuLinkStatus->partner[r5];
                        }
                        break;
                    }
                }
                if (r5 < 4)
                {
                    CpuCopy16(r9, &gRfuLinkStatus->partner[slot], sizeof(struct RfuTgtData));
                    gRfuLinkStatus->partner[slot].slot = slot;
                }
            }
        }
    }
    rfu_STC_REQ_callback(sp24, sp28);
}

u16 rfu_getConnectParentStatus(u8 *status, u8 *r1)
{
    u8 r0, *r2;

    *status = 0xFF;
    r2 = gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data;
    r0 = r2[0] + 96;
    if (r0 <= 1)
    {
        r2 += 6;
        *r1 = r2[0];
        *status = r2[1];
        return 0;
    }
    return 0x10;
}

void rfu_REQ_endConnectParent(void)
{
    STWI_set_Callback_M(rfu_CB_pollConnectParent);
    STWI_send_CP_EndREQ();
    if (gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[6] < 4)
        gRfuStatic->linkEmergencyFlag[gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[6]] = 0;
}

u16 rfu_syncVBlank(void)
{
    u8 r3, r4;
    s32 r5;

    rfu_NI_checkCommFailCounter();
    if (gRfuLinkStatus->connMode == 0xFF)
        return 0;
    if (gRfuStatic->nowWatchInterval != 0)
        --gRfuStatic->nowWatchInterval;
    r3 = rfu_getMasterSlave();
    if (!(gRfuStatic->flags & 2))
    {
        if (r3 == 0)
        {
            gRfuStatic->flags |= 4;
            gRfuStatic->watchdogTimer = 360;
        }
    }
    else if (r3 != 0)
    {
        gRfuStatic->flags &= 0xFB;
    }
    if (r3 != 0)
        gRfuStatic->flags &= 0xFD;
    else
        gRfuStatic->flags |= 2;
    if (!(gRfuStatic->flags & 4))
        return 0;
    if (gRfuStatic->watchdogTimer == 0)
    {
        gRfuStatic->flags &= 0xFB;
        r5 = gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag;
        for (r4 = 0; r4 < 4; ++r4)
            if ((r5 >> r4) & 1)
                rfu_STC_removeLinkData(r4, 1);
        gRfuLinkStatus->connMode = 0xFF;
        return 1;
    }
    --gRfuStatic->watchdogTimer;
    return 0;
}

s32 rfu_REQBN_watchLink(u16 r5, u8 *r8, u8 *sp00, u8 *sp04)
{
    u8 sp08 = 0;
    u8 sp0C = 0;
    u8 i;
    s32 sp10, sp14;
    u8 *r2;
    u8 r9, r6, r3, r1, r0;
    
    *r8 = 0;
    *sp00 = 0;
    *sp04 = 0;
    if (gRfuLinkStatus->connMode == 0xFF || gRfuState->msMode == 0)
        return 0;
    if (gRfuStatic->flags & 4)
        gRfuStatic->watchdogTimer = 360;
    if (gRfuStatic->nowWatchInterval == 0)
    {
        gRfuStatic->nowWatchInterval = gRfuLinkStatus->watchInterval;
        sp08 = 1;
    }
    if ((u8)r5 == 41)
    {
        u8 *r1 = gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data;
        
        *r8 = r1[4];
        *sp00 = r1[5];
        if (*sp00 == 1)
            *r8 = gRfuLinkStatus->connSlotFlag;
        sp08 = 2;
    }
    else
    {
        if (r5 == 310)
        {
            r6 = gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[5];
            r6 ^= gRfuLinkStatus->connSlotFlag;
            *r8 = r6 & gRfuLinkStatus->connSlotFlag;
            *sp00 = 1;
            for (i = 0; i < NELEMS(gRfuLinkStatus->strength); ++i)
            {
                if ((*r8 >> i) & 1)
                {
                    gRfuLinkStatus->strength[i] = 0;
                    rfu_STC_removeLinkData(i, 0);
                }
            }
        }
        if (sp08 == 0)
            return 0;
    }
    sp10 = gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket32.command;
    sp14 = gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket32.data[0];
    STWI_set_Callback_M(rfu_CB_defaultCallback);
    STWI_send_LinkStatusREQ();
    sp0C = STWI_poll_CommandEnd();
    if (sp0C == 0)
    {
        r2 = &gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[4];
        for (i = 0; i < NELEMS(gRfuLinkStatus->strength); ++i)
            gRfuLinkStatus->strength[i] = *r2++;
        r9 = 0;
        i = 0;
    }
    else
    {
        rfu_STC_REQ_callback(17, sp0C);
        return sp0C;
    }
    for (; i < 4; ++i)
    {
        r6 = 1 << i;
        if (sp0C == 0)
        {
            if (sp08 == 1 && (gRfuLinkStatus->connSlotFlag & r6))
            {
                if (gRfuLinkStatus->strength[i] == 0)
                {
                    if (gRfuLinkStatus->connMode == 1)
                    {
                        ++gRfuStatic->linkEmergencyFlag[i];
                        if (gRfuStatic->linkEmergencyFlag[i] > 3)
                        {
                            *r8 |= r6;
                            *sp00 = sp08; // why not directly use 1?
                        }
                    }
                    else
                    {
                        STWI_send_SystemStatusREQ();
                        if (STWI_poll_CommandEnd() == 0)
                        {
                            if (gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[7] == 0)
                            {
                                *r8 |= r6;
                                *sp00 = sp08;
                            }
                            else
                            {
                                if (++gRfuStatic->linkEmergencyFlag[i] > gRfuStatic->unk_1a)
                                {
                                    gRfuStatic->linkEmergencyFlag[i] = 0;
                                    STWI_send_DisconnectREQ(gRfuLinkStatus->connSlotFlag);
                                    STWI_poll_CommandEnd();
                                    *r8 |= r6;
                                    *sp00 = sp08; // why not directly use 1?
                                }
                            }
                        }
                    }
                }
                else
                {
                    gRfuStatic->linkEmergencyFlag[i] = sp0C; // why not directly use 0? 
                }
            }
            if (gRfuLinkStatus->connMode == 1 && gRfuLinkStatus->strength[i] != 0)
            {
                if (r6 & gRfuLinkStatus->linkLossSlotFlag)
                {
                    if (gRfuLinkStatus->strength[i] > 10)
                    {
                        *sp04 |= r6;
                        gRfuLinkStatus->connSlotFlag |= r6;
                        gRfuLinkStatus->linkLossSlotFlag &= ~r6;
                        ++gRfuLinkStatus->connCount;
                        gRfuStatic->linkEmergencyFlag[i] = 0;
                    }
                    else
                    {
                        gRfuLinkStatus->strength[i] = 0;
                    }
                }
                else
                {
                    if (!((gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag) & r6))
                    {
                        STWI_send_SlotStatusREQ();
                        STWI_poll_CommandEnd();
                        r2 = gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data;
                        r3 = r2[1] - 1;
                        for (r2 += 8; r3 != 0; r2 += 4, --r3)
                        {
                            u16 r4 = *(u16 *)r2;

                            if (r2[2] == i && r4 == gRfuStatic->cidBak[i])
                            {
                                r9 |= 1 << i;
                                break;
                            }
                        }
                    }
                }
            }
        }
        r1 = gRfuLinkStatus->connSlotFlag;
        r0 = *r8;
        r0 &= r1;
        if (r6 & r0)
            rfu_STC_removeLinkData(i, 0);
    }
    if (r9 != 0)
    {
        STWI_send_DisconnectREQ(r9);
        STWI_poll_CommandEnd();
    }
    // equivalent to:
    // gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket32.command = sp10;
    *(u32 *)gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data = sp10;
    gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket32.data[0] = sp14;
    return 0;
}

static void rfu_STC_removeLinkData(u8 r7, u8 r12)
{
    u8 r5 = 1 << r7;
    s32 r6;

    if ((gRfuLinkStatus->connSlotFlag & r5) && gRfuLinkStatus->connCount != 0)
        --gRfuLinkStatus->connCount;
    gRfuLinkStatus->connSlotFlag &= r6 = ~r5;
    gRfuLinkStatus->linkLossSlotFlag |= r5;
    if ((*(u32 *)gRfuLinkStatus & 0xFF00FF) == 0)
        gRfuLinkStatus->connMode = 0xFF;
    if (r12 != 0)
    {
        CpuFill16(0, &gRfuLinkStatus->partner[r7], sizeof(struct RfuTgtData));
        gRfuLinkStatus->linkLossSlotFlag &= r6;
        gRfuLinkStatus->getNameFlag &= r6;
        gRfuLinkStatus->strength[r7] = 0;
    }
}

void rfu_REQ_disconnect(u8 who)
{
    u16 r1;

    if ((gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag) & who)
    {
        gRfuStatic->recoveryBmSlot = who;
        if (gRfuLinkStatus->connMode == 0xFF && gRfuStatic->flags & 0x80)
        {
            if (gRfuLinkStatus->linkLossSlotFlag & who)
                rfu_CB_disconnect(48, 0);
        }
        else if (gRfuStatic->SCStartFlag
              && (STWI_set_Callback_M(rfu_CB_defaultCallback),
                  STWI_send_SC_EndREQ(),
                  (r1 = STWI_poll_CommandEnd()) != 0))
        {
            rfu_STC_REQ_callback(27, r1);
        }
        else
        {
            STWI_set_Callback_M(rfu_CB_disconnect);
            STWI_send_DisconnectREQ(who);
        }
    }
}

static void rfu_CB_disconnect(u8 r6, u16 r5)
{
    u8 r4, r0;

    if (r5 == 3 && gRfuLinkStatus->connMode == 0)
    {
        STWI_set_Callback_M(rfu_CB_defaultCallback);
        STWI_send_SystemStatusREQ();
        if (STWI_poll_CommandEnd() == 0 && gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[7] == 0)
            r5 = 0;
    }
    gRfuStatic->recoveryBmSlot &= gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag;
    gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[8] = gRfuStatic->recoveryBmSlot;
    if (r5 == 0)
    {
        for (r4 = 0; r4 < 4; ++r4)
        {
            r0 = 1 << r4;
            if (r0 & gRfuStatic->recoveryBmSlot)
                rfu_STC_removeLinkData(r4, 1);
        }
    }
    if ((gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag) == 0)
        gRfuLinkStatus->connMode = 0xFF;
    rfu_STC_REQ_callback(r6, r5);
    if (gRfuStatic->SCStartFlag)
    {
        STWI_set_Callback_M(rfu_CB_defaultCallback);
        STWI_send_SC_StartREQ();
        r5 = STWI_poll_CommandEnd();
        if (r5 != 0)
            rfu_STC_REQ_callback(25, r5);
    }
}

void rfu_REQ_CHILD_startConnectRecovery(u8 r5)
{
    u8 i;

    gRfuStatic->recoveryBmSlot = r5;
    for (i = 0; i < 4 && !((r5 >> i) & 1); ++i)
        ;
    STWI_set_Callback_M(rfu_STC_REQ_callback);
    // if i == 4, gRfuLinkStatus->partner[i].id becomes gRfuLinkStatus->my.id
    STWI_send_CPR_StartREQ(gRfuLinkStatus->partner[i].id, gRfuLinkStatus->my.id, r5);
}

void rfu_REQ_CHILD_pollConnectRecovery(void)
{
    STWI_set_Callback_M(rfu_CB_CHILD_pollConnectRecovery);
    STWI_send_CPR_PollingREQ();
}

static void rfu_CB_CHILD_pollConnectRecovery(u8 r8, u16 r7)
{
    u8 r3, r4;
    struct RfuLinkStatus *r2;

    if (r7 == 0 && gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[4] == 0 && gRfuStatic->recoveryBmSlot)
    {
        gRfuLinkStatus->connMode = 0;
        for (r4 = 0; r4 < NELEMS(gRfuStatic->linkEmergencyFlag); ++r4)
        {
            r3 = 1 << r4;
            r2 = gRfuLinkStatus; // ???
            if (gRfuStatic->recoveryBmSlot & r3 & r2->linkLossSlotFlag)
            {
                gRfuLinkStatus->connSlotFlag |= r3;
                gRfuLinkStatus->linkLossSlotFlag &= ~r3;
                ++gRfuLinkStatus->connCount;
                gRfuStatic->linkEmergencyFlag[r4] = 0;
            }
        }
        gRfuStatic->recoveryBmSlot = 0;
    }
    rfu_STC_REQ_callback(r8, r7);
}

u16 rfu_CHILD_getConnectRecoveryStatus(u8 *status)
{
    u8 r0;

    *status = 0xFF;
    r0 = gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[0] + 77;
    if (r0 <= 1)
    {
        *status = gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[4];
        return 0;
    }
    return 0x10;
}

void rfu_REQ_CHILD_endConnectRecovery(void)
{
    STWI_set_Callback_M(rfu_CB_CHILD_pollConnectRecovery);
    STWI_send_CPR_EndREQ();
}

static void rfu_STC_fastCopy(const u8 **src_p, u8 **dst_p, s32 size)
{
    const u8 *src = *src_p;
    u8 *dst = *dst_p;
    s32 i;

    for (i = size - 1; i != -1; --i)
        *dst++ = *src++;
    *src_p = src;
    *dst_p = dst;
}

void rfu_REQ_changeMasterSlave(void)
{
    if (STWI_read_status(1) == 1)
    {
        STWI_set_Callback_M(rfu_STC_REQ_callback);
        STWI_send_MS_ChangeREQ();
    }
    else
    {
        rfu_STC_REQ_callback(39, 0);
    }
}

bool8 rfu_getMasterSlave(void)
{
    bool8 r2 = STWI_read_status(1);

    if (r2 == 1)
    {
        if (gRfuState->unk_2c)
        {
            if (gRfuState->reqActiveCommand == 39
             || gRfuState->reqActiveCommand == 37
             || gRfuState->reqActiveCommand == 55)
                r2 = 0;
        }
    }
    return r2;
}

void rfu_clearAllSlot(void)
{
    u16 i;
    u16 IMEBackup = REG_IME;
    
    REG_IME = 0;
    for (i = 0; i < NELEMS(gRfuSlotStatusNI); ++i)
    {
        CpuFill16(0, gRfuSlotStatusNI[i], sizeof(gRfuSlotStatusNI[i]->sub));
        CpuFill16(0, gRfuSlotStatusUNI[i], sizeof(gRfuSlotStatusUNI[i]->sub));
        gRfuLinkStatus->remainLLFrameSizeChild[i] = 16;
    }
    gRfuLinkStatus->remainLLFrameSizeParent = 87;
    gRfuLinkStatus->sendSlotNIFlag = 0;
    gRfuLinkStatus->recvSlotNIFlag = 0;
    gRfuLinkStatus->sendSlotUNIFlag = 0;
    gRfuStatic->recvRenewalFlag = 0;
    REG_IME = IMEBackup;
}

static void rfu_STC_releaseFrame(u8 r5, u8 r3, struct NIComm *r4)
{

    if (!(gRfuStatic->flags & 0x80))
    {
        if (r3 == 0)
            gRfuLinkStatus->remainLLFrameSizeParent += r4->payloadSize;
        gRfuLinkStatus->remainLLFrameSizeParent += 3;
    }
    else
    {
        if (r3 == 0)
            gRfuLinkStatus->remainLLFrameSizeChild[r5] += r4->payloadSize;
        gRfuLinkStatus->remainLLFrameSizeChild[r5] += 2;
    }
}

s32 rfu_clearSlot(u8 r8, u8 r7)
{
    u16 r10, r3, r1;
    struct NIComm *r4;

    if (r7 > 3)
        return 0x400;
    if ((r8 & 0xF) == 0)
        return 0x600;
    r10 = REG_IME;
    REG_IME = 0;
    if (r8 & 0xC)
    {
        for (r3 = 0; r3 < 2; ++r3)
        {
            r4 = NULL;
            if (r3 == 0)
            {
                if (r8 & 4)
                {
                    r4 = &gRfuSlotStatusNI[r7]->sub.send;
                    gRfuLinkStatus->sendSlotNIFlag &= ~r4->bmSlotOrg;
                }
            }
            else
            {
                if (r8 & 8)
                {
                    r4 = &gRfuSlotStatusNI[r7]->sub.recv;
                    gRfuLinkStatus->recvSlotNIFlag &= ~(1 << r7);
                }
            }
            if (r4 != NULL)
            {
                if (r4->state & 0x8000)
                {
                    rfu_STC_releaseFrame(r7, r3, r4);
                    for (r1 = 0; r1 < 4; ++r1)
                        if ((r4->bmSlotOrg >> r1) & 1)
                            r4->failCounter = 0;
                }
                CpuFill16(0, r4, sizeof(struct NIComm));
            }
        }
    }
    if (r8 & 1)
    {
        struct RfuSlotStatusUNI *r3 = gRfuSlotStatusUNI[r7];

        if (r3->sub.send.state & 0x8000)
        {
            if (!(gRfuStatic->flags & 0x80))
                gRfuLinkStatus->remainLLFrameSizeParent += 3 + (u8)r3->sub.send.payloadSize;
            else
                gRfuLinkStatus->remainLLFrameSizeChild[r7] += 2 + (u8)r3->sub.send.payloadSize;
            gRfuLinkStatus->sendSlotUNIFlag &= ~r3->sub.send.bmSlot;
        }
        CpuFill16(0, &r3->sub.send, sizeof(struct UNISend));
    }
    if (r8 & 2)
    {
        CpuFill16(0, &gRfuSlotStatusUNI[r7]->sub.recv, sizeof(struct UNIRecv));
    }
    REG_IME = r10;
    return 0;
}

s32 rfu_setRecvBuffer(u8 r3, u8 r4, void *r5, size_t r6)
{
    if (r4 > 3)
        return 0x400;
    if (r3 & 0x20)
    {
        gRfuSlotStatusNI[r4]->recvBuffer = r5;
        gRfuSlotStatusNI[r4]->recvBufferSize = r6;
    }
    else if (!(r3 & 0x10))
    {
        return 0x600;
    }
    else
    {
        gRfuSlotStatusUNI[r4]->recvBuffer = r5;
        gRfuSlotStatusUNI[r4]->recvBufferSize = r6;
    }
    return 0;
}

s32 rfu_NI_setSendData(u8 a1, u8 a2, const void *a3, u32 a4)
{
    return rfu_STC_setSendData_org(32, a1, a2, a3, a4);
}

s32 rfu_UNI_setSendData(u8 flag, const void *ptr, u8 size)
{
    u8 r0;

    if (gRfuLinkStatus->connMode == 1)
        r0 = size + 3;
    else
        r0 = size + 2;
    return rfu_STC_setSendData_org(16, flag, r0, ptr, 0);
}

s32 rfu_NI_CHILD_setSendGameName(u8 a1, u8 a2)
{
    return rfu_STC_setSendData_org(64, 1 << a1, a2, &gRfuLinkStatus->my.serialNum, 26);
}

static u16 rfu_STC_setSendData_org(u8 r6, u8 r3, u8 r8, const void *sp00, u32 sp28)
{
    u8 r2, r0;
    u8 r4;
    u8 *r9;
    u8 r5;
    u8 i;
    u16 sp04;
    struct RfuSlotStatusUNI *r1;
    struct RfuSlotStatusNI *r12;

    if (gRfuLinkStatus->connMode == 0xFF)
        return 0x301;
    if (!(r3 & 0xF))
        return 0x400;
    if (((gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag) & r3) != r3)
        return 0x401;
    if (r6 & 0x10)
        r0 = gRfuLinkStatus->sendSlotUNIFlag;
    else
        r0 = gRfuLinkStatus->sendSlotNIFlag;
    if (r0 & r3)
        return 0x402;
    for (r2 = 0; r2 < 4 && !((r3 >> r2) & 1); ++r2)
        ;
    if (gRfuLinkStatus->connMode == 1)
        r9 = &gRfuLinkStatus->remainLLFrameSizeParent;
    else if (gRfuLinkStatus->connMode == 0)
        r9 = &gRfuLinkStatus->remainLLFrameSizeChild[r2];
    r4 = _Str_RfuHeader[gRfuLinkStatus->connMode].unk00;
    if (r8 > *r9 || r8 <= r4)
        return 0x500;
    sp04 = REG_IME;
    REG_IME = 0;
    r5 = r6 & 0x20;
    if (r5 || r6 == 0x40)
    {
        u8 *r1; // a hack to swap instructions

        r12 = gRfuSlotStatusNI[r2];
        r1 = NULL;
        r12->sub.send.errorCode = 0;
        *r12->sub.send.nowP = r1 = &r12->sub.send.dataType;
        r12->sub.send.remainSize = 7;
        r12->sub.send.bmSlotOrg = r3;
        r12->sub.send.bmSlot = r3;
        r12->sub.send.payloadSize = r8 - r4;
        if (r5 != 0)
            *r1 = 0;
        else
            *r1 = 1;
        r12->sub.send.dataSize = sp28;
        r12->sub.send.src = sp00;
        r12->sub.send.ack = 0;
        r12->sub.send.phase = 0;
    #ifndef NONMATCHING // to fix r2, r3, r4, r5 register roulette
        asm("":::"r2");
    #endif
        for (i = 0; i < NELEMS(r12->sub.send.recvAckFlag); ++i)
        {
            r12->sub.send.recvAckFlag[i] = 0;
            r12->sub.send.n[i] = 1;
        }
        for (r2 = 0; r2 < NELEMS(gRfuSlotStatusNI); ++r2)
            if ((r3 >> r2) & 1)
                gRfuSlotStatusNI[r2]->sub.send.failCounter = 0;
        gRfuLinkStatus->sendSlotNIFlag |= r3;
        *r9 -= r8;
        r12->sub.send.state = 0x8021;
    }
    else if (r6 & 0x10)
    {
        r1 = gRfuSlotStatusUNI[r2];
        r1->sub.send.bmSlot = r3;
        r1->sub.send.src = sp00;
        r1->sub.send.payloadSize = r8 - r4;
        *r9 -= r8;
        r1->sub.send.state = 0x8024;
        gRfuLinkStatus->sendSlotUNIFlag |= r3;
    }
    REG_IME = sp04;
    return 0;
}

s32 rfu_changeSendTarget(u8 r3, u8 r7, u8 r6)
{
    struct RfuSlotStatusNI *r5;
    u16 r8;
    u8 r2;

    if (r7 >= NELEMS(gRfuSlotStatusNI))
        return 0x400;
    if (r3 == 0x20)
    {
        r5 = gRfuSlotStatusNI[r7];
        if ((r5->sub.send.state & 0x8000)
         && (r5->sub.send.state & 0x20))
        {
            r3 = r6 ^ r5->sub.send.bmSlot;
            
            if (!(r3 & r6))
            {
                if (r3)
                {
                    r8 = REG_IME;
                    REG_IME = 0;
                    for (r2 = 0; r2 < NELEMS(gRfuSlotStatusNI); ++r2)
                    {
                        if ((r3 >> r2) & 1)
                            gRfuSlotStatusNI[r2]->sub.send.failCounter = 0;
                    }
                    gRfuLinkStatus->sendSlotNIFlag &= ~r3;
                    r5->sub.send.bmSlot = r6;
                    if (r5->sub.send.bmSlot == 0)
                    {
                        rfu_STC_releaseFrame(r7, 0, &r5->sub.send);
                        r5->sub.send.state = 39;
                    }
                    REG_IME = r8;
                }
            }
            else
            {
                return 0x404;
            }
        }
        else
        {
            return 0x403;
        }
    }
    else
    {
        if (r3 == 16)
        {
            s32 r3;

            if (gRfuSlotStatusUNI[r7]->sub.send.state != 0x8024)
                return 0x403;
            for (r3 = 0, r2 = 0; r2 < NELEMS(gRfuSlotStatusUNI); ++r2)
                if (r2 != r7)
                    r3 |= gRfuSlotStatusUNI[r2]->sub.send.bmSlot;
            if (r6 & r3)
                return 0x404;
            r8 = REG_IME;
            REG_IME = 0;
            gRfuLinkStatus->sendSlotUNIFlag &= ~gRfuSlotStatusUNI[r7]->sub.send.bmSlot;
            gRfuLinkStatus->sendSlotUNIFlag |= r6;
            gRfuSlotStatusUNI[r7]->sub.send.bmSlot = r6;
            REG_IME = r8;
        }
        else
        {
            return 0x600;
        }
    }
    return 0;
}

s32 rfu_NI_stopReceivingData(u8 who)
{
#ifndef NONMATCHING // r4, r5 register swap
    register struct NIComm *r5 asm("r5");
#else
    struct NIComm *r5;
#endif
    u16 r4, r1;

    if (who > 3)
        return 0x400;
    r5 = &gRfuSlotStatusNI[who]->sub.recv;
    r4 = REG_IME;
    REG_IME = 0;
    if (gRfuSlotStatusNI[who]->sub.recv.state & 0x8000)
    {
        if (gRfuSlotStatusNI[who]->sub.recv.state == 0x8043)
            gRfuSlotStatusNI[who]->sub.recv.state = 72;
        else
            gRfuSlotStatusNI[who]->sub.recv.state = 71;
        gRfuLinkStatus->recvSlotNIFlag &= ~(1 << who);
        rfu_STC_releaseFrame(who, 1, r5);
    }
    REG_IME = r4;
    return 0;
}

s32 rfu_UNI_changeAndReadySendData(u8 r3, const void *r7, u8 r5)
{
    struct UNISend *r4;
    u8 *r6;
    u16 r1;
    u8 r3_;

    if (r3 >= 4)
        return 0x400;
    r4 = &gRfuSlotStatusUNI[r3]->sub.send;
    if (r4->state != 0x8024)
        return 0x403;
    if (gRfuLinkStatus->connMode == 1)
    {
        r6 = &gRfuLinkStatus->remainLLFrameSizeParent;
        r3_ = gRfuLinkStatus->remainLLFrameSizeParent + (u8)r4->payloadSize;
    }
    else
    {
        r6 = &gRfuLinkStatus->remainLLFrameSizeChild[r3];
        r3_ = gRfuLinkStatus->remainLLFrameSizeChild[r3] + (u8)r4->payloadSize;
    }
    if (r3_ < r5)
        return 0x500;
    r1 = REG_IME;
    REG_IME = 0;
    r4->src = r7;
    *r6 = r3_ - r5;
    r4->payloadSize = r5;
    r4->dataReadyFlag = 1;
    REG_IME = r1;
    return 0;
}

void rfu_UNI_readySendData(u8 a1)
{
    if (a1 < NELEMS(gRfuSlotStatusUNI))
    {
        if (gRfuSlotStatusUNI[a1]->sub.send.state == 0x8024)
            gRfuSlotStatusUNI[a1]->sub.send.dataReadyFlag = 1;
    }
}

void rfu_UNI_clearRecvNewDataFlag(u8 a1)
{
    if (a1 < NELEMS(gRfuSlotStatusUNI))
        gRfuSlotStatusUNI[a1]->sub.recv.newDataFlag = 0;
}

void rfu_REQ_sendData(u8 r5)
{
    if (gRfuLinkStatus->connMode != 0xFF)
    {
        if (gRfuLinkStatus->connMode == 1
         && !(gRfuLinkStatus->sendSlotNIFlag | gRfuLinkStatus->recvSlotNIFlag | gRfuLinkStatus->sendSlotUNIFlag))
        {
            if (gRfuStatic->commExistFlag)
            {
                gRfuStatic->emberCount = 16;
                gRfuStatic->nullFrameCount = 0;
            }
            if (gRfuStatic->emberCount)
                --gRfuStatic->emberCount;
            else
                ++gRfuStatic->nullFrameCount;
            if (gRfuStatic->emberCount
             || !(gRfuStatic->nullFrameCount & 0xF))
            {
                gRfuFixed->LLFBuffer[0] = 1;
                gRfuFixed->LLFBuffer[4] = 0xFF;
                STWI_set_Callback_M(rfu_CB_sendData3);
                if (r5 == 0)
                    STWI_send_DataTxREQ(gRfuFixed->LLFBuffer, 1);
                else
                    STWI_send_DataTxAndChangeREQ(gRfuFixed->LLFBuffer, 1);
                return;
            }
        }
        else
        {
            if (!gRfuLinkStatus->LLFReadyFlag)
                rfu_constructSendLLFrame();
            if (gRfuLinkStatus->LLFReadyFlag)
            {
                STWI_set_Callback_M(rfu_CB_sendData);
                if (r5 != 0)
                {
                    STWI_send_DataTxAndChangeREQ(gRfuFixed->LLFBuffer, gRfuStatic->totalPacketSize + 4);
                    return;
                }
                STWI_send_DataTxREQ(gRfuFixed->LLFBuffer, gRfuStatic->totalPacketSize + 4);
            }
        }
        if (r5 != 0)
        {
            if (gRfuLinkStatus->connMode == 1)
            {
                if (gRfuState->callbackS != NULL)
                    gRfuState->callbackS(39);
            }
            else
            {
                STWI_set_Callback_M(rfu_CB_sendData2);
                STWI_send_MS_ChangeREQ();
            }
        }
    }
}

static void rfu_CB_sendData(UNUSED u8 r0, u16 r7)
{
    u8 r6;
    struct NIComm *r4;

    if (r7 == 0)
    {
        for (r6 = 0; r6 < NELEMS(gRfuSlotStatusNI); ++r6)
        {
            if (gRfuSlotStatusUNI[r6]->sub.send.dataReadyFlag)
                gRfuSlotStatusUNI[r6]->sub.send.dataReadyFlag = 0;
            r4 = &gRfuSlotStatusNI[r6]->sub.send;
            if (r4->state == 0x8020)
            {
                rfu_STC_releaseFrame(r6, 0, r4);
                gRfuLinkStatus->sendSlotNIFlag &= ~r4->bmSlot;
                if (r4->dataType == 1)
                    gRfuLinkStatus->getNameFlag |= 1 << r6;
                r4->state = 38;
            }
        }
    }
    gRfuLinkStatus->LLFReadyFlag = 0;
    rfu_STC_REQ_callback(36, r7);
}

static void rfu_CB_sendData2(UNUSED u8 r0, u16 r1)
{
    rfu_STC_REQ_callback(36, r1);
}

static void rfu_CB_sendData3(u8 r0, u16 r1)
{
    if (r1 != 0)
        rfu_STC_REQ_callback(36, r1);
    else if (r0 == 0xFF)
        rfu_STC_REQ_callback(0xFF, 0);
}

static void rfu_constructSendLLFrame(void)
{
    u32 r8, r5;
    u8 r6;
    u8 *sp00;
    struct RfuSlotStatusNI *r2;

    if (gRfuLinkStatus->connMode != 0xFF
     && gRfuLinkStatus->sendSlotNIFlag | gRfuLinkStatus->recvSlotNIFlag | gRfuLinkStatus->sendSlotUNIFlag)
    {
        gRfuLinkStatus->LLFReadyFlag = 0;
        r8 = 0;
        sp00 = (u8 *)&gRfuFixed->LLFBuffer[1];
        for (r6 = 0; r6 < NELEMS(gRfuSlotStatusUNI); ++r6)
        {
            r5 = 0;
            if (gRfuSlotStatusNI[r6]->sub.send.state & 0x8000)
                r5 = rfu_STC_NI_constructLLSF(r6, &sp00, &gRfuSlotStatusNI[r6]->sub.send);
            if (gRfuSlotStatusNI[r6]->sub.recv.state & 0x8000)
                r5 += rfu_STC_NI_constructLLSF(r6, &sp00, &gRfuSlotStatusNI[r6]->sub.recv);
            if (gRfuSlotStatusUNI[r6]->sub.send.state == 0x8024)
                r5 += rfu_STC_UNI_constructLLSF(r6, &sp00);
            if (r5 != 0)
            {
                if (gRfuLinkStatus->connMode == 1)
                    r8 += r5;
                else
                    r8 |= r5 << (5 * r6 + 8);
            }
        }
        if (r8 != 0)
        {
            while ((u32)sp00 & 3)
                *sp00++ = 0;
            gRfuFixed->LLFBuffer[0] = r8;
            if (gRfuLinkStatus->connMode == 0)
            {
                u8 *r0 = sp00 - offsetof(struct RfuFixed, LLFBuffer[1]);
                
                // Does the volatile qualifier make sense? 
                // It's the same as: 
                // asm("":::"memory");
                r8 = r0 - *(u8 *volatile *)&gRfuFixed;
            }
        }
        gRfuStatic->totalPacketSize = r8;
    }
}

static u16 rfu_STC_NI_constructLLSF(u8 r10, u8 **r12, struct NIComm *r4)
{
    u16 r5;
    u32 sp00;
    u8 i;
    u8 *r2;
    const struct RfuHeader *r8 = &_Str_RfuHeader[gRfuLinkStatus->connMode];

    if (r4->state == 0x8022)
    {
        while (r4->nowP[r4->phase] >= (const u8 *)r4->src + r4->dataSize)
        {
            ++r4->phase;
            if (r4->phase == 4)
                r4->phase = 0;
        }
    }
    if (r4->state & 0x40)
    {
        r5 = 0;
    }
    else if (r4->state == 0x8022)
    {
        if (r4->nowP[r4->phase] + r4->payloadSize > (const u8 *)r4->src + r4->dataSize)
            r5 = (const u8 *)r4->src + r4->dataSize - r4->nowP[r4->phase];
        else
            r5 = r4->payloadSize;
    }
    else
    {
        if ((u32)r4->remainSize >= r4->payloadSize)
            r5 = r4->payloadSize;
        else
            r5 = r4->remainSize;
    }
    sp00 = (r4->state & 0xF) << r8->unk03
         | r4->ack << r8->unk04
         | r4->phase << r8->unk05
         | r4->n[r4->phase] << r8->unk06
         | r5;
    if (gRfuLinkStatus->connMode == 1)
        sp00 |= r4->bmSlot << 18;
    r2 = (u8 *)&sp00;
    for (i = 0; i < r8->unk00; ++i)
        *(*r12)++ = *r2++;
    if (r5 != 0)
    {
        const u8 *sp04 = r4->nowP[r4->phase];

        gRfuFixed->fastCopyPtr(&sp04, r12, r5);
    }
    if (r4->state == 0x8022)
    {
        ++r4->phase;
        if (r4->phase == 4)
            r4->phase = 0;
    }
    if (gRfuLinkStatus->connMode == 1)
        gRfuLinkStatus->LLFReadyFlag = 1;
    else
        gRfuLinkStatus->LLFReadyFlag |= 1 << r10;
    return r5 + r8->unk00;
}

static u16 rfu_STC_UNI_constructLLSF(u8 r8, u8 **r6)
{
    const struct RfuHeader *r5;
    const u8 *sp04;
    u32 sp00;
    u8 *r2;
    u8 i;
    struct UNISend *r4 = &gRfuSlotStatusUNI[r8]->sub.send;

    if (!r4->dataReadyFlag || !r4->bmSlot)
        return 0;
    r5 = &_Str_RfuHeader[gRfuLinkStatus->connMode];
    sp00 = (r4->state & 0xF) << r5->unk03
         | r4->payloadSize;
    if (gRfuLinkStatus->connMode == 1)
        sp00 |= r4->bmSlot << 18;
    r2 = (u8 *)&sp00;
    for (i = 0; i < r5->unk00; ++i)
        *(*r6)++ = *r2++;
    sp04 = r4->src;
    gRfuFixed->fastCopyPtr(&sp04, r6, r4->payloadSize);
    if (gRfuLinkStatus->connMode == 1)
        gRfuLinkStatus->LLFReadyFlag = 16;
    else
        gRfuLinkStatus->LLFReadyFlag |= 16 << r8;
    return r5->unk00 + r4->payloadSize;
}

void rfu_REQ_recvData(void)
{
    if (gRfuLinkStatus->connMode != 0xFF)
    {
        gRfuStatic->commExistFlag = gRfuLinkStatus->sendSlotNIFlag | gRfuLinkStatus->recvSlotNIFlag | gRfuLinkStatus->sendSlotUNIFlag;
        gRfuStatic->recvErrorFlag = 0;
        STWI_set_Callback_M(rfu_CB_recvData);
        STWI_send_DataRxREQ();
    }
}

static void rfu_CB_recvData(u8 r9, u16 r7)
{
    u8 r6;
    struct RfuSlotStatusNI *r4;
    struct NIComm *r5;

    if (r7 == 0 && gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[1])
    {
        gRfuStatic->NIEndRecvFlag = 0;
        if (gRfuLinkStatus->connMode == 1)
            rfu_STC_PARENT_analyzeRecvPacket();
        else
            rfu_STC_CHILD_analyzeRecvPacket();
        for (r6 = 0; r6 < NELEMS(gRfuSlotStatusNI); ++r6)
        {
            r4 = gRfuSlotStatusNI[r6];
            if (r4->sub.recv.state == 0x8043 && !((gRfuStatic->NIEndRecvFlag >> r6) & 1))
            {
                r5 = &r4->sub.recv;
                if (r5->dataType == 1)
                    gRfuLinkStatus->getNameFlag |= 1 << r6;
                rfu_STC_releaseFrame(r6, 1, r5);
                gRfuLinkStatus->recvSlotNIFlag &= ~r5->bmSlot;
                r4->sub.recv.state = 70;
            }
        }
        if (gRfuStatic->recvErrorFlag)
            r7 = gRfuStatic->recvErrorFlag | 0x700;
    }
    rfu_STC_REQ_callback(r9, r7);
}

static void rfu_STC_PARENT_analyzeRecvPacket(void)
{
    u32 r3;
    u8 r5;
    u8 sp[4];
    u8 *r6;

    r3 = gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket32.data[0] >> 8;
    for (r5 = 0; r5 < NELEMS(sp); ++r5)
    {
        sp[r5] = r3 & 0x1F;
        r3 >>= 5;
        if (sp[r5] == 0)
            gRfuStatic->NIEndRecvFlag |= 1 << r5;
    }
    r6 = &gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[8];
    for (r5 = 0; r5 < NELEMS(sp); ++r5)
    {
        if (sp[r5])
        {
            u8 *r4 = &sp[r5];

            do
            {
                u8 r0 = rfu_STC_analyzeLLSF(r5, r6, *r4);

                r6 += r0;
                *r4 -= r0;
            } while (!(*r4 & 0x80) && (*r4));
        }
    }
}

static void rfu_STC_CHILD_analyzeRecvPacket(void)
{
    u16 r4;
    u8 *r5;
    u16 r0;

    r4 = *(u16 *)&gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[4] & 0x7F;
    r5 = &gRfuFixed->STWIBuffer->rxPacketAlloc.rfuPacket8.data[8];
    if (r4 == 0)
        gRfuStatic->NIEndRecvFlag = 15;
    do
    {
        if (r4 == 0)
            break;
        r0 = rfu_STC_analyzeLLSF(0, r5, r4);
        r5 += r0;
        r4 -= r0;
    } while (!(r4 & 0x8000));
}

static u16 rfu_STC_analyzeLLSF(u8 r12, const u8 *r7, u16 r3)
{
    struct RfuLocalStruct sp00;
    const struct RfuHeader *r6;
    u32 r5;
    u8 r4;
    u32 r0;
    u16 r10;

    r6 = &_Str_RfuHeader[~gRfuLinkStatus->connMode & 1];
    if (r3 < r6->unk00)
        return r3;
    r5 = 0;
    for (r4 = 0; r4 < r6->unk00; ++r4)
        r5 |= *r7++ << 8 * r4;
    sp00.unk00 = (r5 >> r6->unk01) & r6->unk07;
    sp00.unk01 = (r5 >> r6->unk02) & r6->unk08;
    sp00.unk02 = (r5 >> r6->unk03) & r6->unk09;
    sp00.unk03 = (r5 >> r6->unk04) & r6->unk0A;
    sp00.unk04 = (r5 >> r6->unk05) & r6->unk0B;
    sp00.unk05 = (r5 >> r6->unk06) & r6->unk0C;
    sp00.unk06 = (r5  & r6->unk0E) & r5;
    r10 = sp00.unk06 + r6->unk00;
    if (sp00.unk00 == 0)
    {
        if (gRfuLinkStatus->connMode == 1)
        {
            if ((gRfuLinkStatus->connSlotFlag >> r12) & 1)
            {
                if (sp00.unk02 == 4)
                {
                    rfu_STC_UNI_receive(r12, &sp00, r7);
                }
                else if (sp00.unk03 == 0)
                {
                    rfu_STC_NI_receive_Receiver(r12, &sp00, r7);
                }
                else
                {
                    for (r4 = 0; r4 < NELEMS(gRfuSlotStatusNI); ++r4)
                        if (((gRfuSlotStatusNI[r4]->sub.send.bmSlot >> r12) & 1)
                         && ((gRfuLinkStatus->sendSlotNIFlag >> r12) & 1))
                            break;
                    if (r4 <= 3)
                        rfu_STC_NI_receive_Sender(r4, r12, &sp00, r7);
                }
            }
        }
        else
        {
            s32 r5 = gRfuLinkStatus->connSlotFlag & sp00.unk01;

            if (r5)
            {
                for (r4 = 0; r4 < 4; ++r4)
                {
                    if ((r5 >> r4) & 1)
                    {
                        if (sp00.unk02 == 4)
                            rfu_STC_UNI_receive(r4, &sp00, r7);
                        else if (sp00.unk03 == 0)
                            rfu_STC_NI_receive_Receiver(r4, &sp00, r7);
                        else if ((gRfuLinkStatus->sendSlotNIFlag >> r4) & 1)
                            rfu_STC_NI_receive_Sender(r4, r4, &sp00, r7);
                    }
                }
            }
        }
    }
    return r10;
}

static void rfu_STC_UNI_receive(u8 r7, const struct RfuLocalStruct *r6, const u8 *sp00)
{
    u8 *sp04;
    u32 r2;
    struct RfuSlotStatusUNI *r3 = gRfuSlotStatusUNI[r7];
    struct UNIRecv *r5 = &r3->sub.recv;

    r5->errorCode = 0;
    if (gRfuSlotStatusUNI[r7]->recvBufferSize < r6->unk06)
    {
        r3->sub.recv.state = 73;
        r5->errorCode = 0x701;
    }
    else
    { 
        if (r5->dataBlockFlag)
        {
            if (r5->newDataFlag)
            {
                r5->errorCode = 0x709;
                goto _081E2F0E;
            }
        }
        else
        {
            if (r5->newDataFlag)
                r5->errorCode = 0x708;
        }
        r5->state = 0x8042;
        r2 = r5->dataSize = r6->unk06;
        sp04 = gRfuSlotStatusUNI[r7]->recvBuffer;
        gRfuFixed->fastCopyPtr(&sp00, &sp04, r2);
        r5->newDataFlag = 1;
        r5->state = 0;
    }
_081E2F0E:
    if (r5->errorCode)
        gRfuStatic->recvErrorFlag |= 16 << r7;
}

static void rfu_STC_NI_receive_Sender(u8 r0, u8 r10, const struct RfuLocalStruct *r6, const u8 *r3)
{
    struct NIComm *r12 = &gRfuSlotStatusNI[r0]->sub.send;
    u16 r9 = r12->state;
    u8 sp00 = r12->n[r6->unk04];
    u8 *r8;
    u8 r4;
    u16 r2;

    if ((r6->unk02 == 2 && r9 == 0x8022)
     || (r6->unk02 == 1 && r9 == 0x8021)
     || (r6->unk02 == 3 && r9 == 0x8023))
    {
        if (r12->n[r6->unk04] == r6->unk05)
            r12->recvAckFlag[r6->unk04] |= 1 << r10;
    }
    if ((r12->recvAckFlag[r6->unk04] & r12->bmSlot) == r12->bmSlot)
    {
        r12->n[r6->unk04] = (r12->n[r6->unk04] + 1) & 3;
        r12->recvAckFlag[r6->unk04] = 0;
        if ((u16)(r12->state + ~0x8020) <= 1)
        {
            if (r12->state == 0x8021)
                r12->nowP[r6->unk04] += r12->payloadSize;
            else
                r12->nowP[r6->unk04] += r12->payloadSize << 2;
            r12->remainSize -= r12->payloadSize;
            if (r12->remainSize != 0)
                if (r12->remainSize >= 0)
                    goto _081E30AE;
            // Above is a hack to avoid optimization over comparison. 
            // rfu_STC_NI_constructLLSF uses this field as u32. 
            // It's equivalent to the following condition: 
            // if (r12->remainSize == 0 || r12->remainSize < 0)
            {
                r12->phase = 0;
                if (r12->state == 0x8021)
                {
                    for (r4 = 0; r4 < NELEMS(r12->n); ++r4)
                    {
                        r12->n[r4] = 1;
                        r12->nowP[r4] = r12->src + r12->payloadSize * r4;
                    }
                    r12->remainSize = r12->dataSize;
                    r12->state = 0x8022;
                }
                else
                {
                    r12->n[0] = 0;
                    r12->remainSize = 0;
                    r12->state = 0x8023;
                }
            }
        _081E30AE:
        }
        else if (r12->state == 0x8023)
        {
            r12->state = 0x8020;
        }
    }
    if (r12->state != r9
     || r12->n[r6->unk04] != sp00
     || (r12->recvAckFlag[r6->unk04] >> r10) & 1)
    {
        r2 = REG_IME;
        REG_IME = 0;
        gRfuStatic->recvRenewalFlag |= 16 << r10;
        gRfuSlotStatusNI[r10]->sub.send.failCounter = 0;
        REG_IME = r2;
    }
}

static void rfu_STC_NI_receive_Receiver(u8 r8, const struct RfuLocalStruct *r6, const u8 *sp00)
{
    u16 r2;
    u32 r7 = 0;
    struct RfuSlotStatusNI *r4 = gRfuSlotStatusNI[r8];
    struct NIComm *r5 = &r4->sub.recv;
    u16 r9 = r4->sub.recv.state;
    u8 r10 = r4->sub.recv.n[r6->unk04];

    if (r6->unk02 == 3)
    {
        gRfuStatic->NIEndRecvFlag |= 1 << r8;
        if (r4->sub.recv.state == 0x8042)
        {
            r4->sub.recv.phase = 0;
            r4->sub.recv.n[0] = 0;
            r4->sub.recv.state = 0x8043;
        }
    }
    else if (r6->unk02 == 2)
    {
        if (r9 == 0x8041 && !r5->remainSize)
            rfu_STC_NI_initSlot_asRecvDataEntity(r8, r5);
        if (r5->state == 0x8042)
            r7 = 1;
    }
    else if (r6->unk02 == 1)
    {
        if (r9 == 0x8041)
        {
            r7 = 1;
        }
        else
        {
            rfu_STC_NI_initSlot_asRecvControllData(r8, r5);
            if (r4->sub.recv.state != 0x8041)
                return;
            r7 = 1;
        }
    }
    if (r7 != 0)
    {
        if (r6->unk05 == ((r5->n[r6->unk04] + 1) & 3))
        {
            gRfuFixed->fastCopyPtr(&sp00, (u8 **)&r5->nowP[r6->unk04], r6->unk06);
            if (r5->state == 0x8042)
                r5->nowP[r6->unk04] += 3 * r5->payloadSize;
            r5->remainSize -= r6->unk06;
            r5->n[r6->unk04] = r6->unk05;
        }
    }
    if (r5->errorCode == 0)
    {
        r5->phase = r6->unk04;
        if (r5->state != r9 || r5->n[r6->unk04] != r10 || r5->n[r6->unk04] == r6->unk05)
        {
            r2 = REG_IME;
            REG_IME = 0;
            gRfuStatic->recvRenewalFlag |= 1 << r8;
            r5->failCounter = 0;
            REG_IME = r2;
        }
    }
}

static void rfu_STC_NI_initSlot_asRecvControllData(u8 r4, struct NIComm *r2)
{
    u8 *r1;
    u32 r5;
    u8 r6;

    if (gRfuLinkStatus->connMode == 1)
    {
        r5 = 3;
        r1 = &gRfuLinkStatus->remainLLFrameSizeParent;
    }
    else
    {
        r5 = 2;
        r1 = &gRfuLinkStatus->remainLLFrameSizeChild[r4];
    }
    r6 = 1 << r4;
    if (r2->state == 0)
    {
        if (*r1 < r5)
        {
            r2->state = 73;
            r2->errorCode = 0x702;
            gRfuStatic->recvErrorFlag |= r6;
        }
        else
        {
            r2->errorCode = 0;
            *r1 -= r5;
            r2->nowP[0] = &r2->dataType;
            r2->remainSize = 7;
            r2->ack = 1;
            r2->payloadSize = 0;
            r2->bmSlot = r6;
            r2->state = 0x8041;
            gRfuLinkStatus->recvSlotNIFlag |= r6;
        }
    }
}

static void rfu_STC_NI_initSlot_asRecvDataEntity(u8 r5, struct NIComm *r4)
{
    u8 r1, r3;

    if (r4->dataType == 1)
    {
        r4->nowP[0] = (void *)&gRfuLinkStatus->partner[r5].serialNum;
    }
    else
    {
        if (r4->dataSize > gRfuSlotStatusNI[r5]->recvBufferSize)
        {
            r1 = 1 << r5;
            gRfuStatic->recvErrorFlag |= r1;
            gRfuLinkStatus->recvSlotNIFlag &= ~r1;
            r4->errorCode = 0x701;
            r4->state = 71;
            rfu_STC_releaseFrame(r5, 1, r4);
            return;
        }
        r4->nowP[0] = gRfuSlotStatusNI[r5]->recvBuffer;
    }
    for (r3 = 0; r3 < 4; ++r3)
    {
        r4->n[r3] = 0;
        r4->nowP[r3] = &r4->nowP[0][r4->payloadSize * r3];
    }
    r4->remainSize = r4->dataSize;
    r4->state = 0x8042;
}

static void rfu_NI_checkCommFailCounter(void)
{
    u16 r12;
    u32 r7;
    u8 r2, r3;

    if (gRfuLinkStatus->sendSlotNIFlag | gRfuLinkStatus->recvSlotNIFlag)
    {
        r12 = REG_IME;
        REG_IME = 0;
        r7 = gRfuStatic->recvRenewalFlag >> 4;
        for (r3 = 0; r3 < NELEMS(gRfuSlotStatusNI); ++r3)
        {
            r2 = 1 << r3;
            if (gRfuLinkStatus->sendSlotNIFlag & r2
             && !(gRfuStatic->recvRenewalFlag & r2))
                ++gRfuSlotStatusNI[r3]->sub.send.failCounter;
            if (gRfuLinkStatus->recvSlotNIFlag & r2
             && !(r7 & r2))
                ++gRfuSlotStatusNI[r3]->sub.recv.failCounter;
        }
        gRfuStatic->recvRenewalFlag = 0;
        REG_IME = r12;
    }
}

void rfu_REQ_noise(void)
{
    STWI_set_Callback_M(rfu_STC_REQ_callback);
    STWI_send_TestModeREQ(1, 0);
}

static s32 sub_81E349C(u8 r5)
{
    u16 r8;
    vu16 *r4;
    s32 r6;

    if (REG_IME == 0)
        return -1;
    r8 = REG_IE;
    gRfuState->state = 10;
    STWI_set_CallbackUnk(sub_81E36B8);
    sub_81E3550();
    r4 = &REG_TMCNT_L(gRfuState->timerSelect);
    r5 *= 8;
    while (--r5 != 0xFF)
    {
        r6 = sub_81E35C4();
        if (r6 != 0)
            break;
        r4[1] = 0;
        r4[0] = 0;
        r4[1] = TIMER_1024CLK | TIMER_ENABLE;
        while (r4[0] < 32)
            ;
        r4[1] = 0;
        r4[0] = 0;
    }
    REG_IME = 0;
    REG_IE = r8;
    REG_IME = 1;
    gRfuState->state = 0;
    STWI_set_CallbackUnk(NULL);
    return r6;
}

static void sub_81E3550(void)
{
    REG_IME = 0;
    REG_IE &= ~((8 << gRfuState->timerSelect) | INTR_FLAG_SERIAL);
    REG_IME = 1;
    REG_RCNT = 0;
    REG_SIOCNT = SIO_32BIT_MODE;
    REG_SIOCNT |= SIO_INTR_ENABLE | SIO_ENABLE;
    CpuFill32(0, &gUnknown_3007470, sizeof(struct Unk_3007470));
    REG_IF = INTR_FLAG_SERIAL;
}

static s32 sub_81E35C4(void)
{
    u8 r12;

    switch (r12 = gUnknown_3007470.unk1)
    {
    case 0:
        gUnknown_3007470.unk0 = 1;
        REG_SIOCNT |= SIO_38400_BPS;
        REG_IME = r12;
        REG_IE |= INTR_FLAG_SERIAL;
        REG_IME = 1;
        gUnknown_3007470.unk1 = 1;
        *(vu8 *)&REG_SIOCNT |= SIO_ENABLE;
        break;
    case 1:
        if (gUnknown_3007470.unkA == 0)
        {
            if (gUnknown_3007470.unk0 == 1)
            {
                if (gUnknown_3007470.unk2 == 0)
                {
                    REG_IME = gUnknown_3007470.unk2;
                    REG_SIOCNT |= SIO_ENABLE;
                    REG_IME = r12;
                }
            }
            else if (gUnknown_3007470.unk4 != 0x8001 && !gUnknown_3007470.unk2)
            {
                REG_IME = gUnknown_3007470.unk2;
                REG_IE &= ~INTR_FLAG_SERIAL;
                REG_IME = r12;
                REG_SIOCNT = gUnknown_3007470.unk2;
                REG_SIOCNT = SIO_32BIT_MODE;
                REG_IF = INTR_FLAG_SERIAL;
                REG_SIOCNT |= SIO_INTR_ENABLE | SIO_ENABLE;
                REG_IME = gUnknown_3007470.unk2;
                REG_IE |= INTR_FLAG_SERIAL;
                REG_IME = r12;
            }
            break;
        }
        else
        {
            gUnknown_3007470.unk1 = 2;
            // fallthrough
        }
    default:
        return gUnknown_3007470.unkA;
    }
    return 0;
}

static void sub_81E36B8(void)
{
    u32 r5;
    u16 r0;
#ifndef NONMATCHING
    register u32 r1 asm("a2");
    register u16 r0_ asm("a1");
#else
    u32 r1;
    u16 r0_;
#endif

    r5 = REG_SIODATA32;
    if (gUnknown_3007470.unk0 != 1)
        REG_SIOCNT |= SIO_ENABLE;
    r1 = 16 * gUnknown_3007470.unk0; // to handle side effect of inline asm
    r1 = (r5 << r1) >> 16;
    r5 = (r5 << 16 * (1 - gUnknown_3007470.unk0)) >> 16;
    if (gUnknown_3007470.unkA == 0)
    {
        if (r1 == gUnknown_3007470.unk6)
        {
            if (gUnknown_3007470.unk2 > 3)
            {
                gUnknown_3007470.unkA = r5;
            }
            else if (r1 == (u16)~gUnknown_3007470.unk4)
            {
                r0_ = ~gUnknown_3007470.unk6;
                if (r5 == r0_)
                    ++gUnknown_3007470.unk2;
            }
        }
        else
        {
            gUnknown_3007470.unk2 = gUnknown_3007470.unkA;
        }
    }
    if (gUnknown_3007470.unk2 < 4)
        gUnknown_3007470.unk4 = *(gUnknown_3007470.unk2 + _Str_Sio32ID);
    else
        gUnknown_3007470.unk4 = 0x8001;
    gUnknown_3007470.unk6 = ~r5;
    REG_SIODATA32 = (gUnknown_3007470.unk4 << 16 * (1 - gUnknown_3007470.unk0))
                  + (gUnknown_3007470.unk6 << 16 * gUnknown_3007470.unk0);
    if (gUnknown_3007470.unk0 == 1 && (gUnknown_3007470.unk2 || r5 == 0x494E))
    {
        for (r0 = 0; r0 < 600; ++r0)
            ;
        if (gUnknown_3007470.unkA == 0)
            REG_SIOCNT |= SIO_ENABLE;
    }
}
