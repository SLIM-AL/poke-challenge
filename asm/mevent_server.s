	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8144CA0
sub_8144CA0: @ 8144CA0
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x10]
	lsls r2, r0, 3
	ldr r1, [r4, 0x1C]
	adds r2, r1, r2
	adds r0, 0x1
	str r0, [r4, 0x10]
	ldr r0, [r2]
	cmp r0, 0x15
	bls _08144CB8
	b _08144E60
_08144CB8:
	lsls r0, 2
	ldr r1, _08144CC4 @ =_08144CC8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08144CC4: .4byte _08144CC8
	.align 2, 0
_08144CC8:
	.4byte _08144E60
	.4byte _08144D20
	.4byte _08144D28
	.4byte _08144D38
	.4byte _08144D70
	.4byte _08144D78
	.4byte _08144D62
	.4byte _08144D6A
	.4byte _08144DC6
	.4byte _08144DF0
	.4byte _08144DE8
	.4byte _08144D8E
	.4byte _08144DA4
	.4byte _08144DBA
	.4byte _08144DDC
	.4byte _08144E18
	.4byte _08144E1C
	.4byte _08144E24
	.4byte _08144E30
	.4byte _08144D4E
	.4byte _08144D3C
	.4byte _08144E4C
_08144D20:
	ldr r0, [r2, 0x4]
	str r0, [r4, 0x4]
	movs r0, 0x1
	b _08144E5A
_08144D28:
	adds r0, r4, 0
	adds r0, 0x24
	ldr r1, [r2, 0x4]
	ldr r2, [r4, 0x18]
	bl sub_81448AC
	movs r0, 0x2
	b _08144E5A
_08144D38:
	movs r0, 0x3
	b _08144E5A
_08144D3C:
	adds r0, r4, 0
	adds r0, 0x24
	ldr r2, [r4, 0x14]
	movs r1, 0x14
	movs r3, 0
	bl sub_8144888
	movs r0, 0x3
	b _08144E5A
_08144D4E:
	ldrb r0, [r2, 0x4]
	bl GetGameStat
	adds r2, r0, 0
	adds r0, r4, 0
	movs r1, 0x12
	bl sub_8144C00
	movs r0, 0x3
	b _08144E5A
_08144D62:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	bne _08144E60
	b _08144D70
_08144D6A:
	ldr r0, [r4, 0x4]
	cmp r0, 0x1
	bne _08144E60
_08144D70:
	adds r0, r4, 0
	bl sub_8144BE4
	b _08144E60
_08144D78:
	ldr r0, [r4, 0x20]
	ldr r1, [r4, 0x18]
	movs r2, 0x40
	bl memcpy
	movs r0, 0x5
	str r0, [r4, 0x8]
	movs r0, 0
	str r0, [r4, 0xC]
	movs r0, 0x2
	b _08144E62
_08144D8E:
	ldr r0, [r4, 0x20]
	ldr r1, [r4, 0x18]
	movs r2, 0x40
	bl memcpy
	movs r0, 0x5
	str r0, [r4, 0x8]
	movs r0, 0
	str r0, [r4, 0xC]
	movs r0, 0x3
	b _08144E62
_08144DA4:
	ldr r0, [r4, 0x20]
	ldr r1, [r4, 0x18]
	movs r2, 0x40
	bl memcpy
	movs r0, 0x5
	str r0, [r4, 0x8]
	movs r0, 0
	str r0, [r4, 0xC]
	movs r0, 0x5
	b _08144E62
_08144DBA:
	movs r0, 0x5
	str r0, [r4, 0x8]
	movs r0, 0
	str r0, [r4, 0xC]
	movs r0, 0x4
	b _08144E62
_08144DC6:
	ldr r0, [r4, 0x14]
	bl sub_81442CC
	adds r0, r4, 0
	adds r0, 0x24
	ldr r2, [r4, 0x14]
	movs r1, 0x11
	movs r3, 0x64
	bl sub_8144888
	b _08144E60
_08144DDC:
	ldr r2, [r4, 0x4]
	adds r0, r4, 0
	movs r1, 0x13
	bl sub_8144C00
	b _08144E60
_08144DE8:
	ldr r0, [r4, 0x18]
	bl sub_8143F68
	b _08144E60
_08144DF0:
	ldr r0, [r4, 0x18]
	bl sub_8143EF4
	cmp r0, 0
	bne _08144E0C
	ldr r0, [r4, 0x18]
	bl sub_8143DC8
	adds r0, r4, 0
	movs r1, 0x13
	movs r2, 0
	bl sub_8144C00
	b _08144E60
_08144E0C:
	adds r0, r4, 0
	movs r1, 0x13
	movs r2, 0x1
	bl sub_8144C00
	b _08144E60
_08144E18:
	movs r0, 0x6
	b _08144E5A
_08144E1C:
	ldr r0, [r4, 0x18]
	bl sub_8144254
	b _08144E60
_08144E24:
	ldr r0, [r4, 0x18]
	movs r1, 0xFA
	lsls r1, 2
	bl sub_8069EA4
	b _08144E60
_08144E30:
	ldr r0, _08144E48 @ =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r1, 0x94
	lsls r1, 3
	adds r0, r1
	ldr r1, [r4, 0x18]
	movs r2, 0xBC
	bl memcpy
	bl sub_80E7490
	b _08144E60
	.align 2, 0
_08144E48: .4byte gSaveBlock2Ptr
_08144E4C:
	ldr r0, _08144E68 @ =gDecompressionBuffer
	ldr r1, [r4, 0x18]
	movs r2, 0x80
	lsls r2, 3
	bl memcpy
	movs r0, 0x7
_08144E5A:
	str r0, [r4, 0x8]
	movs r0, 0
	str r0, [r4, 0xC]
_08144E60:
	movs r0, 0x1
_08144E62:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08144E68: .4byte gDecompressionBuffer
	thumb_func_end sub_8144CA0

	thumb_func_start sub_8144E6C
sub_8144E6C: @ 8144E6C
	push {lr}
	adds r1, r0, 0
	ldr r0, [r1, 0xC]
	cmp r0, 0
	beq _08144E7E
	movs r0, 0x4
	str r0, [r1, 0x8]
	movs r0, 0
	str r0, [r1, 0xC]
_08144E7E:
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8144E6C

	thumb_func_start sub_8144E84
sub_8144E84: @ 8144E84
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0xC]
	cmp r0, 0
	beq _08144E94
	cmp r0, 0x1
	beq _08144EA2
	b _08144EB4
_08144E94:
	ldr r0, [r4, 0x18]
	bl sub_80DA89C
	ldr r0, [r4, 0xC]
	adds r0, 0x1
	str r0, [r4, 0xC]
	b _08144EB4
_08144EA2:
	adds r0, r4, 0x4
	bl sub_80DA8B0
	adds r1, r0, 0
	cmp r1, 0
	bne _08144EB4
	movs r0, 0x4
	str r0, [r4, 0x8]
	str r1, [r4, 0xC]
_08144EB4:
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8144E84

	thumb_func_start sub_8144EBC
sub_8144EBC: @ 8144EBC
	push {r4,lr}
	adds r4, r0, 0
	ldr r3, _08144EE4 @ =gDecompressionBuffer
	adds r0, r4, 0x4
	ldr r1, _08144EE8 @ =gSaveBlock2Ptr
	ldr r1, [r1]
	ldr r2, _08144EEC @ =gSaveBlock1Ptr
	ldr r2, [r2]
	bl _call_via_r3
	cmp r0, 0x1
	bne _08144EDC
	movs r0, 0x4
	str r0, [r4, 0x8]
	movs r0, 0
	str r0, [r4, 0xC]
_08144EDC:
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08144EE4: .4byte gDecompressionBuffer
_08144EE8: .4byte gSaveBlock2Ptr
_08144EEC: .4byte gSaveBlock1Ptr
	thumb_func_end sub_8144EBC

	thumb_func_start mevent_srv_ish_exec
mevent_srv_ish_exec: @ 8144EF0
	push {r4,r5,lr}
	sub sp, 0x20
	mov r2, sp
	ldr r1, _08144F18 @ =gUnknown_8466F60
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r1!, {r3,r4}
	stm r2!, {r3,r4}
	ldr r1, [r0, 0x8]
	lsls r1, 2
	add r1, sp
	ldr r1, [r1]
	bl _call_via_r1
	add sp, 0x20
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08144F18: .4byte gUnknown_8466F60
	thumb_func_end mevent_srv_ish_exec

	thumb_func_start sub_8144F1C
sub_8144F1C: @ 8144F1C
	push {r4,lr}
	ldr r4, _08144F38 @ =gUnknown_203F3C4
	movs r0, 0x60
	bl AllocZeroed
	str r0, [r4]
	ldr r1, _08144F3C @ =gUnknown_8468B6C
	movs r2, 0
	movs r3, 0x1
	bl mevent_srv_init_common
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08144F38: .4byte gUnknown_203F3C4
_08144F3C: .4byte gUnknown_8468B6C
	thumb_func_end sub_8144F1C

	thumb_func_start sub_8144F40
sub_8144F40: @ 8144F40
	push {r4,lr}
	ldr r4, _08144F5C @ =gUnknown_203F3C4
	movs r0, 0x60
	bl AllocZeroed
	str r0, [r4]
	ldr r1, _08144F60 @ =gUnknown_8468BCC
	movs r2, 0
	movs r3, 0x1
	bl mevent_srv_init_common
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08144F5C: .4byte gUnknown_203F3C4
_08144F60: .4byte gUnknown_8468BCC
	thumb_func_end sub_8144F40

	thumb_func_start sub_8144F64
sub_8144F64: @ 8144F64
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r4, _08144F74 @ =gUnknown_203F3C4
	ldr r0, [r4]
	cmp r0, 0
	bne _08144F78
	movs r0, 0x3
	b _08144F98
	.align 2, 0
_08144F74: .4byte gUnknown_203F3C4
_08144F78:
	bl sub_8145600
	adds r5, r0, 0
	cmp r5, 0x3
	bne _08144F96
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	strh r1, [r6]
	bl mevent_srv_free_resources
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
_08144F96:
	adds r0, r5, 0
_08144F98:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8144F64

	thumb_func_start mevent_srv_init_common
mevent_srv_init_common: @ 8144FA0
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	adds r4, r0, 0
	adds r6, r1, 0
	mov r8, r2
	mov r9, r3
	movs r5, 0
	str r5, [r4]
	str r5, [r4, 0x8]
	movs r0, 0xA6
	lsls r0, 1
	bl AllocZeroed
	str r0, [r4, 0x18]
	movs r0, 0xDE
	lsls r0, 1
	bl AllocZeroed
	str r0, [r4, 0x1C]
	movs r0, 0x80
	lsls r0, 3
	bl AllocZeroed
	str r0, [r4, 0x14]
	movs r0, 0x64
	bl AllocZeroed
	str r0, [r4, 0x20]
	str r6, [r4, 0x10]
	str r5, [r4, 0xC]
	adds r4, 0x38
	adds r0, r4, 0
	mov r1, r8
	mov r2, r9
	bl sub_814485C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end mevent_srv_init_common

	thumb_func_start mevent_srv_free_resources
mevent_srv_free_resources: @ 8144FF8
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x18]
	bl Free
	ldr r0, [r4, 0x1C]
	bl Free
	ldr r0, [r4, 0x14]
	bl Free
	ldr r0, [r4, 0x20]
	bl Free
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end mevent_srv_free_resources

	thumb_func_start sub_814501C
sub_814501C: @ 814501C
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	adds r4, r3, 0
	movs r0, 0x80
	lsls r0, 3
	cmp r4, r0
	bls _0814503A
	ldr r0, _08145050 @ =gUnknown_8466F80	"C:/WORK/POKeFRLG/src/pm_lgfr_ose/source/mevent_server.c"
	ldr r1, _08145054 @ =0x00000101
	ldr r2, _08145058 @ =gUnknown_8466FB8	"size <= ME_SEND_BUF_SIZE"
	movs r3, 0x1
	bl AGBAssert
_0814503A:
	adds r0, r5, 0
	adds r0, 0x38
	adds r1, r6, 0
	adds r2, r7, 0
	adds r3, r4, 0
	bl sub_8144888
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08145050: .4byte gUnknown_8466F80
_08145054: .4byte 0x00000101
_08145058: .4byte gUnknown_8466FB8
	thumb_func_end sub_814501C

	thumb_func_start sub_814505C
sub_814505C: @ 814505C
	push {lr}
	cmp r0, 0
	bne _08145064
	adds r0, r1, 0
_08145064:
	pop {r1}
	bx r1
	thumb_func_end sub_814505C

	thumb_func_start sub_8145068
sub_8145068: @ 8145068
	push {lr}
	cmp r1, r0
	bcs _08145072
	movs r0, 0
	b _0814507C
_08145072:
	cmp r1, r0
	beq _0814507A
	movs r0, 0x2
	b _0814507C
_0814507A:
	movs r0, 0x1
_0814507C:
	pop {r1}
	bx r1
	thumb_func_end sub_8145068

	thumb_func_start sub_8145080
sub_8145080: @ 8145080
	movs r1, 0x4
	str r1, [r0, 0x8]
	movs r0, 0
	bx lr
	thumb_func_end sub_8145080

	thumb_func_start sub_8145088
sub_8145088: @ 8145088
	movs r0, 0x3
	bx lr
	thumb_func_end sub_8145088

	thumb_func_start sub_814508C
sub_814508C: @ 814508C
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x38
	bl sub_8144844
	cmp r0, 0
	beq _0814509E
	movs r0, 0x4
	str r0, [r4, 0x8]
_0814509E:
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_814508C

	thumb_func_start sub_81450A8
sub_81450A8: @ 81450A8
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x38
	bl sub_8144850
	cmp r0, 0
	beq _081450BA
	movs r0, 0x4
	str r0, [r4, 0x8]
_081450BA:
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81450A8

	thumb_func_start sub_81450C4
sub_81450C4: @ 81450C4
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, [r5, 0xC]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	ldr r2, [r5, 0x10]
	adds r4, r2, r1
	adds r0, 0x1
	str r0, [r5, 0xC]
	ldr r0, [r4]
	cmp r0, 0x1D
	bls _081450E0
	b _081455F8
_081450E0:
	lsls r0, 2
	ldr r1, _081450EC @ =_081450F0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081450EC: .4byte _081450F0
	.align 2, 0
_081450F0:
	.4byte _08145168
	.4byte _08145190
	.4byte _08145196
	.4byte _081451C4
	.4byte _08145268
	.4byte _081451E4
	.4byte _08145228
	.4byte _0814527C
	.4byte _081452AC
	.4byte _081452EC
	.4byte _08145320
	.4byte _08145350
	.4byte _08145378
	.4byte _081453D8
	.4byte _081453A4
	.4byte _08145440
	.4byte _0814540C
	.4byte _081454AA
	.4byte _08145458
	.4byte _08145470
	.4byte _0814549C
	.4byte _08145510
	.4byte _081454B8
	.4byte _081454E4
	.4byte _08145538
	.4byte _08145542
	.4byte _0814554C
	.4byte _08145588
	.4byte _081455C0
	.4byte _081455EC
_08145168:
	ldr r0, [r4, 0x8]
	cmp r0, 0
	beq _0814517C
	ldr r0, _08145188 @ =gUnknown_8466F80	"C:/WORK/POKeFRLG/src/pm_lgfr_ose/source/mevent_server.c"
	movs r1, 0xB1
	lsls r1, 1
	ldr r2, _0814518C @ =gUnknown_8466FD4	"cmd->parameter == NULL"
	movs r3, 0x1
	bl AGBAssert
_0814517C:
	movs r0, 0x1
	str r0, [r5, 0x8]
	ldr r0, [r4, 0x4]
	str r0, [r5, 0x4]
	b _081455F8
	.align 2, 0
_08145188: .4byte gUnknown_8466F80
_0814518C: .4byte gUnknown_8466FD4
_08145190:
	movs r0, 0x3
	str r0, [r5, 0x8]
	b _081455F8
_08145196:
	ldr r0, [r4, 0x8]
	cmp r0, 0
	beq _081451AA
	ldr r0, _081451BC @ =gUnknown_8466F80	"C:/WORK/POKeFRLG/src/pm_lgfr_ose/source/mevent_server.c"
	movs r1, 0xB6
	lsls r1, 1
	ldr r2, _081451C0 @ =gUnknown_8466FD4	"cmd->parameter == NULL"
	movs r3, 0x1
	bl AGBAssert
_081451AA:
	adds r0, r5, 0
	adds r0, 0x38
	ldr r1, [r4, 0x4]
	ldr r2, [r5, 0x14]
	bl sub_81448AC
	movs r0, 0x2
	str r0, [r5, 0x8]
	b _081455F8
	.align 2, 0
_081451BC: .4byte gUnknown_8466F80
_081451C0: .4byte gUnknown_8466FD4
_081451C4:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _08145272
	ldr r0, _081451DC @ =gUnknown_8466F80	"C:/WORK/POKeFRLG/src/pm_lgfr_ose/source/mevent_server.c"
	movs r1, 0xB9
	lsls r1, 1
	ldr r2, _081451E0 @ =gUnknown_8466FEC	"cmd->flag == FALSE"
	movs r3, 0x1
	bl AGBAssert
	b _08145272
	.align 2, 0
_081451DC: .4byte gUnknown_8466F80
_081451E0: .4byte gUnknown_8466FEC
_081451E4:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _081451F8
	ldr r0, _08145218 @ =gUnknown_8466F80	"C:/WORK/POKeFRLG/src/pm_lgfr_ose/source/mevent_server.c"
	movs r1, 0xBC
	lsls r1, 1
	ldr r2, _0814521C @ =gUnknown_8466FEC	"cmd->flag == FALSE"
	movs r3, 0x1
	bl AGBAssert
_081451F8:
	ldr r0, [r4, 0x8]
	cmp r0, 0
	beq _0814520A
	ldr r0, _08145218 @ =gUnknown_8466F80	"C:/WORK/POKeFRLG/src/pm_lgfr_ose/source/mevent_server.c"
	ldr r1, _08145220 @ =0x00000179
	ldr r2, _08145224 @ =gUnknown_8466FD4	"cmd->parameter == NULL"
	movs r3, 0x1
	bl AGBAssert
_0814520A:
	ldr r0, [r5, 0x20]
	ldr r1, [r5, 0x14]
	movs r2, 0x64
	bl memcpy
	b _081455F8
	.align 2, 0
_08145218: .4byte gUnknown_8466F80
_0814521C: .4byte gUnknown_8466FEC
_08145220: .4byte 0x00000179
_08145224: .4byte gUnknown_8466FD4
_08145228:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _0814523C
	ldr r0, _08145258 @ =gUnknown_8466F80	"C:/WORK/POKeFRLG/src/pm_lgfr_ose/source/mevent_server.c"
	movs r1, 0xBF
	lsls r1, 1
	ldr r2, _0814525C @ =gUnknown_8466FEC	"cmd->flag == FALSE"
	movs r3, 0x1
	bl AGBAssert
_0814523C:
	ldr r0, [r4, 0x8]
	cmp r0, 0
	beq _0814524E
	ldr r0, _08145258 @ =gUnknown_8466F80	"C:/WORK/POKeFRLG/src/pm_lgfr_ose/source/mevent_server.c"
	ldr r1, _08145260 @ =0x0000017f
	ldr r2, _08145264 @ =gUnknown_8466FD4	"cmd->parameter == NULL"
	movs r3, 0x1
	bl AGBAssert
_0814524E:
	ldr r0, [r5, 0x20]
	bl sub_81443D4
	str r0, [r5, 0x4]
	b _081455F8
	.align 2, 0
_08145258: .4byte gUnknown_8466F80
_0814525C: .4byte gUnknown_8466FEC
_08145260: .4byte 0x0000017f
_08145264: .4byte gUnknown_8466FD4
_08145268:
	ldr r1, [r5, 0x4]
	ldr r0, [r4, 0x4]
	cmp r1, r0
	beq _08145272
	b _081455F8
_08145272:
	movs r0, 0
	str r0, [r5, 0xC]
	ldr r0, [r4, 0x8]
	str r0, [r5, 0x10]
	b _081455F8
_0814527C:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _08145290
	ldr r0, _081452A4 @ =gUnknown_8466F80	"C:/WORK/POKeFRLG/src/pm_lgfr_ose/source/mevent_server.c"
	movs r1, 0xC6
	lsls r1, 1
	ldr r2, _081452A8 @ =gUnknown_8466FEC	"cmd->flag == FALSE"
	movs r3, 0x1
	bl AGBAssert
_08145290:
	ldr r0, [r4, 0x8]
	ldr r1, [r5, 0x18]
	bl sub_814505C
	adds r2, r0, 0
	ldr r1, [r5, 0x20]
	bl sub_8144418
	str r0, [r5, 0x4]
	b _081455F8
	.align 2, 0
_081452A4: .4byte gUnknown_8466F80
_081452A8: .4byte gUnknown_8466FEC
_081452AC:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _081452C0
	ldr r0, _081452DC @ =gUnknown_8466F80	"C:/WORK/POKeFRLG/src/pm_lgfr_ose/source/mevent_server.c"
	movs r1, 0xC9
	lsls r1, 1
	ldr r2, _081452E0 @ =gUnknown_8466FEC	"cmd->flag == FALSE"
	movs r3, 0x1
	bl AGBAssert
_081452C0:
	ldr r0, [r4, 0x8]
	cmp r0, 0
	beq _081452D2
	ldr r0, _081452DC @ =gUnknown_8466F80	"C:/WORK/POKeFRLG/src/pm_lgfr_ose/source/mevent_server.c"
	ldr r1, _081452E4 @ =0x00000193
	ldr r2, _081452E8 @ =gUnknown_8466FD4	"cmd->parameter == NULL"
	movs r3, 0x1
	bl AGBAssert
_081452D2:
	ldr r0, [r5, 0x14]
	ldr r0, [r0]
	str r0, [r5, 0x4]
	b _081455F8
	.align 2, 0
_081452DC: .4byte gUnknown_8466F80
_081452E0: .4byte gUnknown_8466FEC
_081452E4: .4byte 0x00000193
_081452E8: .4byte gUnknown_8466FD4
_081452EC:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _08145300
	ldr r0, _08145318 @ =gUnknown_8466F80	"C:/WORK/POKeFRLG/src/pm_lgfr_ose/source/mevent_server.c"
	movs r1, 0xCC
	lsls r1, 1
	ldr r2, _0814531C @ =gUnknown_8466FEC	"cmd->flag == FALSE"
	movs r3, 0x1
	bl AGBAssert
_08145300:
	ldr r0, [r4, 0x8]
	adds r1, r5, 0
	adds r1, 0x34
	bl sub_814505C
	adds r2, r0, 0
	ldr r1, [r5, 0x20]
	bl sub_8144434
	str r0, [r5, 0x4]
	b _081455F8
	.align 2, 0
_08145318: .4byte gUnknown_8466F80
_0814531C: .4byte gUnknown_8466FEC
_08145320:
	ldr r0, [r4, 0x8]
	cmp r0, 0
	beq _08145332
	ldr r0, _08145344 @ =gUnknown_8466F80	"C:/WORK/POKeFRLG/src/pm_lgfr_ose/source/mevent_server.c"
	ldr r1, _08145348 @ =0x0000019f
	ldr r2, _0814534C @ =gUnknown_8466FD4	"cmd->parameter == NULL"
	movs r3, 0x1
	bl AGBAssert
_08145332:
	ldr r0, [r5, 0x20]
	ldr r1, [r4, 0x4]
	bl sub_81444B0
	lsls r0, 16
	lsrs r0, 16
	str r0, [r5, 0x4]
	b _081455F8
	.align 2, 0
_08145344: .4byte gUnknown_8466F80
_08145348: .4byte 0x0000019f
_0814534C: .4byte gUnknown_8466FD4
_08145350:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _08145364
	ldr r0, _08145370 @ =gUnknown_8466F80	"C:/WORK/POKeFRLG/src/pm_lgfr_ose/source/mevent_server.c"
	movs r1, 0xD2
	lsls r1, 1
	ldr r2, _08145374 @ =gUnknown_8466FEC	"cmd->flag == FALSE"
	movs r3, 0x1
	bl AGBAssert
_08145364:
	ldr r0, [r5, 0x20]
	ldr r1, [r4, 0x8]
	bl sub_8144474
	str r0, [r5, 0x4]
	b _081455F8
	.align 2, 0
_08145370: .4byte gUnknown_8466F80
_08145374: .4byte gUnknown_8466FEC
_08145378:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _0814538C
	ldr r0, _0814539C @ =gUnknown_8466F80	"C:/WORK/POKeFRLG/src/pm_lgfr_ose/source/mevent_server.c"
	movs r1, 0xD5
	lsls r1, 1
	ldr r2, _081453A0 @ =gUnknown_8466FEC	"cmd->flag == FALSE"
	movs r3, 0x1
	bl AGBAssert
_0814538C:
	ldr r0, [r4, 0x8]
	ldr r1, [r5, 0x14]
	ldr r1, [r1]
	bl sub_8145068
	str r0, [r5, 0x4]
	b _081455F8
	.align 2, 0
_0814539C: .4byte gUnknown_8466F80
_081453A0: .4byte gUnknown_8466FEC
_081453A4:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _081453B8
	ldr r0, _081453D0 @ =gUnknown_8466F80	"C:/WORK/POKeFRLG/src/pm_lgfr_ose/source/mevent_server.c"
	movs r1, 0xD8
	lsls r1, 1
	ldr r2, _081453D4 @ =gUnknown_8466FEC	"cmd->flag == FALSE"
	movs r3, 0x1
	bl AGBAssert
_081453B8:
	ldr r0, [r4, 0x8]
	ldr r1, [r5, 0x1C]
	bl sub_814505C
	adds r2, r0, 0
	movs r3, 0xDE
	lsls r3, 1
	adds r0, r5, 0
	movs r1, 0x17
	bl sub_814501C
	b _081455F8
	.align 2, 0
_081453D0: .4byte gUnknown_8466F80
_081453D4: .4byte gUnknown_8466FEC
_081453D8:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _081453EC
	ldr r0, _08145404 @ =gUnknown_8466F80	"C:/WORK/POKeFRLG/src/pm_lgfr_ose/source/mevent_server.c"
	movs r1, 0xDB
	lsls r1, 1
	ldr r2, _08145408 @ =gUnknown_8466FEC	"cmd->flag == FALSE"
	movs r3, 0x1
	bl AGBAssert
_081453EC:
	ldr r0, [r4, 0x8]
	ldr r1, [r5, 0x18]
	bl sub_814505C
	adds r2, r0, 0
	movs r3, 0xA6
	lsls r3, 1
	adds r0, r5, 0
	movs r1, 0x16
	bl sub_814501C
	b _081455F8
	.align 2, 0
_08145404: .4byte gUnknown_8466F80
_08145408: .4byte gUnknown_8466FEC
_0814540C:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _08145420
	ldr r0, _08145438 @ =gUnknown_8466F80	"C:/WORK/POKeFRLG/src/pm_lgfr_ose/source/mevent_server.c"
	movs r1, 0xDE
	lsls r1, 1
	ldr r2, _0814543C @ =gUnknown_8466FEC	"cmd->flag == FALSE"
	movs r3, 0x1
	bl AGBAssert
_08145420:
	ldr r0, [r4, 0x8]
	adds r1, r5, 0
	adds r1, 0x34
	bl sub_814505C
	adds r2, r0, 0
	adds r0, r5, 0
	movs r1, 0x18
	movs r3, 0x4
	bl sub_814501C
	b _081455F8
	.align 2, 0
_08145438: .4byte gUnknown_8466F80
_0814543C: .4byte gUnknown_8466FEC
_08145440:
	ldr r2, [r4, 0x8]
	cmp r2, 0
	bne _0814544C
	ldr r2, [r5, 0x24]
	ldr r3, [r5, 0x28]
	b _0814544E
_0814544C:
	ldr r3, [r4, 0x4]
_0814544E:
	adds r0, r5, 0
	movs r1, 0x19
	bl sub_814501C
	b _081455F8
_08145458:
	ldr r2, [r4, 0x8]
	cmp r2, 0
	bne _08145464
	ldr r2, [r5, 0x2C]
	ldr r3, [r5, 0x30]
	b _08145466
_08145464:
	ldr r3, [r4, 0x4]
_08145466:
	adds r0, r5, 0
	movs r1, 0x10
	bl sub_814501C
	b _081455F8
_08145470:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _08145484
	ldr r0, _08145494 @ =gUnknown_8466F80	"C:/WORK/POKeFRLG/src/pm_lgfr_ose/source/mevent_server.c"
	movs r1, 0xE9
	lsls r1, 1
	ldr r2, _08145498 @ =gUnknown_8466FEC	"cmd->flag == FALSE"
	movs r3, 0x1
	bl AGBAssert
_08145484:
	ldr r2, [r4, 0x8]
	adds r0, r5, 0
	movs r1, 0x1A
	movs r3, 0xBC
	bl sub_814501C
	b _081455F8
	.align 2, 0
_08145494: .4byte gUnknown_8466F80
_08145498: .4byte gUnknown_8466FEC
_0814549C:
	ldr r2, [r4, 0x8]
	ldr r3, [r4, 0x4]
	adds r0, r5, 0
	movs r1, 0x15
	bl sub_814501C
	b _081455F8
_081454AA:
	ldr r2, [r4, 0x8]
	ldr r3, [r4, 0x4]
	adds r0, r5, 0
	movs r1, 0x1C
	bl sub_814501C
	b _081455F8
_081454B8:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _081454CA
	ldr r0, _081454D8 @ =gUnknown_8466F80	"C:/WORK/POKeFRLG/src/pm_lgfr_ose/source/mevent_server.c"
	ldr r1, _081454DC @ =0x000001e1
	ldr r2, _081454E0 @ =gUnknown_8466FEC	"cmd->flag == FALSE"
	movs r3, 0x1
	bl AGBAssert
_081454CA:
	ldr r0, [r5, 0x18]
	ldr r1, [r4, 0x8]
	movs r2, 0xA6
	lsls r2, 1
	bl memcpy
	b _081455F8
	.align 2, 0
_081454D8: .4byte gUnknown_8466F80
_081454DC: .4byte 0x000001e1
_081454E0: .4byte gUnknown_8466FEC
_081454E4:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _081454F8
	ldr r0, _08145508 @ =gUnknown_8466F80	"C:/WORK/POKeFRLG/src/pm_lgfr_ose/source/mevent_server.c"
	movs r1, 0xF3
	lsls r1, 1
	ldr r2, _0814550C @ =gUnknown_8466FEC	"cmd->flag == FALSE"
	movs r3, 0x1
	bl AGBAssert
_081454F8:
	ldr r0, [r5, 0x1C]
	ldr r1, [r4, 0x8]
	movs r2, 0xDE
	lsls r2, 1
	bl memcpy
	b _081455F8
	.align 2, 0
_08145508: .4byte gUnknown_8466F80
_0814550C: .4byte gUnknown_8466FEC
_08145510:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _08145522
	ldr r0, _0814552C @ =gUnknown_8466F80	"C:/WORK/POKeFRLG/src/pm_lgfr_ose/source/mevent_server.c"
	ldr r1, _08145530 @ =0x000001eb
	ldr r2, _08145534 @ =gUnknown_8466FEC	"cmd->flag == FALSE"
	movs r3, 0x1
	bl AGBAssert
_08145522:
	ldr r0, [r4, 0x8]
	ldr r0, [r0]
	str r0, [r5, 0x34]
	b _081455F8
	.align 2, 0
_0814552C: .4byte gUnknown_8466F80
_08145530: .4byte 0x000001eb
_08145534: .4byte gUnknown_8466FEC
_08145538:
	ldr r0, [r4, 0x8]
	str r0, [r5, 0x24]
	ldr r0, [r4, 0x4]
	str r0, [r5, 0x28]
	b _081455F8
_08145542:
	ldr r0, [r4, 0x8]
	str r0, [r5, 0x2C]
	ldr r0, [r4, 0x4]
	str r0, [r5, 0x30]
	b _081455F8
_0814554C:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	bne _08145558
	ldr r0, [r4, 0x8]
	cmp r0, 0
	beq _08145566
_08145558:
	ldr r0, _08145580 @ =gUnknown_8466F80	"C:/WORK/POKeFRLG/src/pm_lgfr_ose/source/mevent_server.c"
	movs r1, 0xFD
	lsls r1, 1
	ldr r2, _08145584 @ =gUnknown_8467000	"cmd->flag == FALSE && cmd->parameter == NULL"
	movs r3, 0x1
	bl AGBAssert
_08145566:
	ldr r4, [r5, 0x18]
	bl sav1_get_mevent_buffer_1
	adds r1, r0, 0
	movs r2, 0xA6
	lsls r2, 1
	adds r0, r4, 0
	bl memcpy
	ldr r0, [r5, 0x18]
	bl sub_814410C
	b _081455F8
	.align 2, 0
_08145580: .4byte gUnknown_8466F80
_08145584: .4byte gUnknown_8467000
_08145588:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	bne _08145594
	ldr r0, [r4, 0x8]
	cmp r0, 0
	beq _081455A2
_08145594:
	ldr r0, _081455B8 @ =gUnknown_8466F80	"C:/WORK/POKeFRLG/src/pm_lgfr_ose/source/mevent_server.c"
	movs r1, 0x80
	lsls r1, 2
	ldr r2, _081455BC @ =gUnknown_8467000	"cmd->flag == FALSE && cmd->parameter == NULL"
	movs r3, 0x1
	bl AGBAssert
_081455A2:
	ldr r4, [r5, 0x1C]
	bl sub_8143D58
	adds r1, r0, 0
	movs r2, 0xDE
	lsls r2, 1
	adds r0, r4, 0
	bl memcpy
	b _081455F8
	.align 2, 0
_081455B8: .4byte gUnknown_8466F80
_081455BC: .4byte gUnknown_8467000
_081455C0:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	bne _081455CC
	ldr r0, [r4, 0x8]
	cmp r0, 0
	beq _081455D8
_081455CC:
	ldr r0, _081455E0 @ =gUnknown_8466F80	"C:/WORK/POKeFRLG/src/pm_lgfr_ose/source/mevent_server.c"
	ldr r1, _081455E4 @ =0x00000205
	ldr r2, _081455E8 @ =gUnknown_8467000	"cmd->flag == FALSE && cmd->parameter == NULL"
	movs r3, 0x1
	bl AGBAssert
_081455D8:
	bl sub_8069E48
	str r0, [r5, 0x24]
	b _081455F8
	.align 2, 0
_081455E0: .4byte gUnknown_8466F80
_081455E4: .4byte 0x00000205
_081455E8: .4byte gUnknown_8467000
_081455EC:
	ldr r2, [r4, 0x8]
	ldr r3, [r4, 0x4]
	adds r0, r5, 0
	movs r1, 0x1B
	bl sub_814501C
_081455F8:
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81450C4

	thumb_func_start sub_8145600
sub_8145600: @ 8145600
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x8]
	cmp r0, 0x4
	bls _08145616
	ldr r0, _08145644 @ =gUnknown_8466F80	"C:/WORK/POKeFRLG/src/pm_lgfr_ose/source/mevent_server.c"
	ldr r1, _08145648 @ =0x00000222
	ldr r2, _0814564C @ =gUnknown_8467044	"svr->mainseqno < NELEMS(func_tbl)"
	movs r3, 0x1
	bl AGBAssert
_08145616:
	ldr r1, _08145650 @ =gUnknown_8467030
	ldr r0, [r4, 0x8]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	adds r5, r0, 0
	ldr r0, [r4, 0x8]
	cmp r0, 0x4
	bls _0814563C
	ldr r0, _08145644 @ =gUnknown_8466F80	"C:/WORK/POKeFRLG/src/pm_lgfr_ose/source/mevent_server.c"
	movs r1, 0x89
	lsls r1, 2
	ldr r2, _0814564C @ =gUnknown_8467044	"svr->mainseqno < NELEMS(func_tbl)"
	movs r3, 0x1
	bl AGBAssert
_0814563C:
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08145644: .4byte gUnknown_8466F80
_08145648: .4byte 0x00000222
_0814564C: .4byte gUnknown_8467044
_08145650: .4byte gUnknown_8467030
	thumb_func_end sub_8145600

	.align 2, 0 @ Don't pad with nop.
