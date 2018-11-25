	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_812D0C0
sub_812D0C0: @ 812D0C0
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0xAF
	lsls r0, 1
	bl HasTrainerAlreadyBeenFought
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0812D0EA
	cmp r4, 0x9
	bne _0812D0DE
	movs r0, 0xF
	b _0812D0EC
_0812D0DE:
	cmp r4, 0x9
	bls _0812D0EA
	subs r0, r4, 0x1
	lsls r0, 24
	lsrs r0, 24
	b _0812D0EC
_0812D0EA:
	adds r0, r4, 0
_0812D0EC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_812D0C0

	thumb_func_start sub_812D0F4
sub_812D0F4: @ 812D0F4
	push {r4,r5,lr}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	ldr r5, _0812D164 @ =gUnknown_841E5A4
	cmp r0, 0
	beq _0812D10A
	ldr r5, _0812D168 @ =gUnknown_841E5D2
	cmp r0, 0x1
	bne _0812D10A
	ldr r5, _0812D16C @ =gUnknown_841E5B9
_0812D10A:
	movs r0, 0
	adds r1, r5, 0
	movs r2, 0
	bl GetStringWidth
	adds r4, r0, 0
	movs r0, 0xC0
	str r0, [sp]
	movs r0, 0x10
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillWindowPixelRect
	movs r0, 0x44
	negs r0, r0
	adds r2, r0, 0
	subs r2, r4
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	ldr r0, _0812D170 @ =gUnknown_845F5E0
	str r0, [sp, 0x8]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0xC]
	str r5, [sp, 0x10]
	movs r0, 0x1
	movs r1, 0
	movs r3, 0
	bl AddTextPrinterParametrized2
	movs r0, 0x1
	bl sub_812CEE0
	add sp, 0x14
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0812D164: .4byte gUnknown_841E5A4
_0812D168: .4byte gUnknown_841E5D2
_0812D16C: .4byte gUnknown_841E5B9
_0812D170: .4byte gUnknown_845F5E0
	thumb_func_end sub_812D0F4

	thumb_func_start sub_812D174
sub_812D174: @ 812D174
	push {r4,lr}
	movs r4, 0
_0812D178:
	ldr r0, _0812D1A0 @ =gUnknown_203B0FC
	ldr r0, [r0]
	adds r0, 0x1D
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, _0812D1A4 @ =gSprites
	adds r0, r1
	bl DestroySprite
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x5
	bls _0812D178
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0812D1A0: .4byte gUnknown_203B0FC
_0812D1A4: .4byte gSprites
	thumb_func_end sub_812D174

	thumb_func_start sub_812D1A8
sub_812D1A8: @ 812D1A8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r5, 0
	movs r6, 0
	ldr r7, _0812D238 @ =gUnknown_203B0FC
_0812D1BA:
	ldr r0, _0812D23C @ =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, [r7]
	adds r0, 0xC
	add r0, r8
	ldrb r2, [r0]
	lsls r0, r2, 2
	adds r1, r0
	ldr r0, _0812D240 @ =0x00003a54
	adds r1, r0
	ldrh r0, [r1]
	lsls r0, 18
	lsrs r0, 20
	asrs r0, r6
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0812D248
	ldr r1, _0812D244 @ =gUnknown_845F83C
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 1
	adds r0, r6
	adds r0, r1
	ldrb r5, [r0]
	adds r0, r6, 0
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 1
	adds r4, r0
	lsls r4, 4
	subs r4, r0
	adds r4, 0x72
	lsls r4, 16
	asrs r4, 16
	adds r0, r6, 0
	movs r1, 0x3
	bl __udivsi3
	lsls r0, 24
	lsrs r0, 24
	lsls r3, r0, 3
	subs r3, r0
	lsls r3, 2
	subs r3, r0
	adds r3, 0x2F
	lsls r3, 16
	asrs r3, 16
	adds r0, r5, 0
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_805EB44
	ldr r1, [r7]
	adds r1, 0x1D
	adds r1, r6
	strb r0, [r1]
	movs r5, 0x1
	b _0812D2A0
	.align 2, 0
_0812D238: .4byte gUnknown_203B0FC
_0812D23C: .4byte gSaveBlock1Ptr
_0812D240: .4byte 0x00003a54
_0812D244: .4byte gUnknown_845F83C
_0812D248:
	adds r0, r6, 0
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 1
	adds r4, r0
	lsls r4, 4
	subs r4, r0
	adds r4, 0x72
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	movs r1, 0x3
	bl __udivsi3
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	subs r1, r0
	adds r1, 0x1F
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_812D780
	ldr r1, [r7]
	adds r1, 0x1D
	adds r1, r6
	strb r0, [r1]
	ldr r2, _0812D2D0 @ =gSprites
	ldr r0, [r7]
	adds r0, 0x1D
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0xFF
	strh r1, [r0, 0x30]
_0812D2A0:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x5
	bls _0812D1BA
	cmp r5, 0x1
	bne _0812D2E0
	ldr r3, _0812D2D4 @ =gUnknown_203B0FC
	ldr r2, [r3]
	ldrb r0, [r2, 0x7]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x7]
	ldr r0, [r3]
	ldrb r1, [r0, 0x7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0812D2D8
	movs r0, 0x1
	bl sub_812D0F4
	b _0812D2F4
	.align 2, 0
_0812D2D0: .4byte gSprites
_0812D2D4: .4byte gUnknown_203B0FC
_0812D2D8:
	movs r0, 0
	bl sub_812D0F4
	b _0812D2F4
_0812D2E0:
	ldr r0, _0812D300 @ =gUnknown_203B0FC
	ldr r2, [r0]
	ldrb r1, [r2, 0x7]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x7]
	movs r0, 0x1
	bl sub_812D0F4
_0812D2F4:
	adds r0, r5, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0812D300: .4byte gUnknown_203B0FC
	thumb_func_end sub_812D1A8

	thumb_func_start sub_812D304
sub_812D304: @ 812D304
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r4, 0
	ldr r0, _0812D378 @ =gSaveBlock1Ptr
	mov r9, r0
	mov r6, r9
	ldr r5, _0812D37C @ =0x00003a54
	movs r0, 0x4
	negs r0, r0
	mov r8, r0
	ldr r0, _0812D380 @ =0xffffc003
	mov r12, r0
	ldr r7, _0812D384 @ =0x00003a55
_0812D322:
	ldr r1, [r6]
	lsls r3, r4, 2
	adds r1, r3
	adds r1, r5
	ldrb r2, [r1]
	mov r0, r8
	ands r0, r2
	strb r0, [r1]
	ldr r1, [r6]
	adds r1, r3
	adds r3, r1, r5
	ldrh r2, [r3]
	mov r0, r12
	ands r0, r2
	strh r0, [r3]
	adds r1, r7
	ldrb r2, [r1]
	movs r0, 0x3F
	ands r0, r2
	strb r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xF
	bls _0812D322
	mov r0, r9
	ldr r2, [r0]
	ldr r0, _0812D37C @ =0x00003a54
	adds r2, r0
	ldrb r1, [r2]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812D378: .4byte gSaveBlock1Ptr
_0812D37C: .4byte 0x00003a54
_0812D380: .4byte 0xffffc003
_0812D384: .4byte 0x00003a55
	thumb_func_end sub_812D304

	thumb_func_start sub_812D388
sub_812D388: @ 812D388
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	movs r5, 0
	ldr r0, _0812D410 @ =gSaveBlock1Ptr
	mov r12, r0
	ldr r7, _0812D414 @ =0x00003a54
	movs r1, 0x4
	negs r1, r1
	mov r10, r1
	ldr r6, _0812D418 @ =0xffffc003
	mov r9, r6
	movs r0, 0x1
	mov r8, r0
_0812D3AA:
	mov r1, r12
	ldr r2, [r1]
	lsls r3, r5, 2
	adds r2, r3
	adds r2, r7
	ldrb r1, [r2]
	mov r0, r10
	ands r0, r1
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2]
	movs r4, 0
	adds r5, 0x1
	str r5, [sp]
	adds r5, r3, 0
_0812D3C8:
	mov r6, r12
	ldr r2, [r6]
	adds r2, r5
	adds r2, r7
	ldrh r3, [r2]
	lsls r0, r3, 18
	lsrs r0, 20
	mov r1, r8
	lsls r1, r4
	orrs r1, r0
	ldr r6, _0812D41C @ =0x00000fff
	adds r0, r6, 0
	ands r1, r0
	lsls r1, 2
	mov r0, r9
	ands r0, r3
	orrs r0, r1
	strh r0, [r2]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x5
	bls _0812D3C8
	ldr r1, [sp]
	lsls r0, r1, 24
	lsrs r5, r0, 24
	cmp r5, 0xF
	bls _0812D3AA
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812D410: .4byte gSaveBlock1Ptr
_0812D414: .4byte 0x00003a54
_0812D418: .4byte 0xffffc003
_0812D41C: .4byte 0x00000fff
	thumb_func_end sub_812D388

	thumb_func_start sub_812D420
sub_812D420: @ 812D420
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	movs r3, 0xC0
	lsls r3, 19
	movs r4, 0xC0
	lsls r4, 9
	add r0, sp, 0x4
	mov r8, r0
	mov r2, sp
	movs r6, 0
	ldr r1, _0812D550 @ =0x040000d4
	movs r5, 0x80
	lsls r5, 5
	ldr r7, _0812D554 @ =0x81000800
	movs r0, 0x81
	lsls r0, 24
	mov r12, r0
_0812D446:
	strh r6, [r2]
	mov r0, sp
	str r0, [r1]
	str r3, [r1, 0x4]
	str r7, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r3, r5
	subs r4, r5
	cmp r4, r5
	bhi _0812D446
	strh r6, [r2]
	mov r2, sp
	str r2, [r1]
	str r3, [r1, 0x4]
	lsrs r0, r4, 1
	mov r2, r12
	orrs r0, r2
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	movs r0, 0xE0
	lsls r0, 19
	movs r3, 0x80
	lsls r3, 3
	movs r4, 0
	str r4, [sp, 0x4]
	ldr r2, _0812D550 @ =0x040000d4
	mov r1, r8
	str r1, [r2]
	str r0, [r2, 0x4]
	lsrs r0, r3, 2
	movs r1, 0x85
	lsls r1, 24
	orrs r0, r1
	str r0, [r2, 0x8]
	ldr r0, [r2, 0x8]
	movs r1, 0xA0
	lsls r1, 19
	mov r0, sp
	strh r4, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
	lsrs r3, 1
	movs r0, 0x81
	lsls r0, 24
	orrs r3, r0
	str r3, [r2, 0x8]
	ldr r0, [r2, 0x8]
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x8
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x10
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xA
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x14
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x16
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xC
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x18
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xE
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1C
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1E
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x40
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x44
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x48
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812D550: .4byte 0x040000d4
_0812D554: .4byte 0x81000800
	thumb_func_end sub_812D420

	thumb_func_start sub_812D558
sub_812D558: @ 812D558
	push {lr}
	bl remove_some_task
	bl ResetTasks
	bl ResetSpriteData
	bl dp13_810BB8C
	bl ResetPaletteFade
	movs r0, 0
	bl npc_paltag_set_load
	ldr r1, _0812D580 @ =gReservedSpritePaletteCount
	movs r0, 0x7
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0812D580: .4byte gReservedSpritePaletteCount
	thumb_func_end sub_812D558

	thumb_func_start sub_812D584
sub_812D584: @ 812D584
	push {lr}
	movs r1, 0xFA
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	pop {r0}
	bx r0
	thumb_func_end sub_812D584

	thumb_func_start sub_812D594
sub_812D594: @ 812D594
	push {lr}
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	pop {r0}
	bx r0
	thumb_func_end sub_812D594

	thumb_func_start sub_812D5EC
sub_812D5EC: @ 812D5EC
	push {r4-r6,lr}
	ldr r1, _0812D638 @ =gUnknown_20370C0
	ldrh r0, [r1]
	cmp r0, 0xF
	bhi _0812D632
	ldr r5, _0812D63C @ =gSpecialVar_0x8005
	ldrh r0, [r5]
	cmp r0, 0x5
	bhi _0812D632
	ldr r0, _0812D640 @ =gSaveBlock1Ptr
	ldr r2, [r0]
	ldrh r0, [r1]
	lsls r0, 2
	adds r2, r0
	ldr r0, _0812D644 @ =0x00003a54
	adds r2, r0
	ldrh r3, [r2]
	lsls r0, r3, 18
	lsrs r0, 20
	movs r4, 0x1
	adds r1, r4, 0
	ldrh r6, [r5]
	lsls r1, r6
	orrs r1, r0
	ldr r6, _0812D648 @ =0x00000fff
	adds r0, r6, 0
	ands r1, r0
	lsls r1, 2
	ldr r0, _0812D64C @ =0xffffc003
	ands r0, r3
	orrs r0, r1
	strh r0, [r2]
	strh r4, [r5]
	bl sub_812D650
_0812D632:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0812D638: .4byte gUnknown_20370C0
_0812D63C: .4byte gSpecialVar_0x8005
_0812D640: .4byte gSaveBlock1Ptr
_0812D644: .4byte 0x00003a54
_0812D648: .4byte 0x00000fff
_0812D64C: .4byte 0xffffc003
	thumb_func_end sub_812D5EC

	thumb_func_start sub_812D650
sub_812D650: @ 812D650
	push {r4,lr}
	ldr r1, _0812D6A4 @ =gUnknown_20370C0
	ldrh r0, [r1]
	cmp r0, 0xF
	bhi _0812D69E
	ldr r0, _0812D6A8 @ =gSpecialVar_0x8005
	ldrh r4, [r0]
	adds r0, r4, 0
	cmp r0, 0x2
	bhi _0812D69E
	cmp r0, 0
	beq _0812D69E
	ldr r2, _0812D6AC @ =gSaveBlock1Ptr
	ldrh r3, [r1]
	cmp r0, 0x1
	bne _0812D684
	ldr r0, [r2]
	lsls r1, r3, 2
	adds r0, r1
	ldr r1, _0812D6B0 @ =0x00003a54
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r0, 30
	cmp r0, 0x2
	beq _0812D69E
_0812D684:
	ldr r2, [r2]
	lsls r0, r3, 2
	adds r2, r0
	ldr r0, _0812D6B0 @ =0x00003a54
	adds r2, r0
	movs r1, 0x3
	ands r1, r4
	ldrb r3, [r2]
	movs r0, 0x4
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
_0812D69E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0812D6A4: .4byte gUnknown_20370C0
_0812D6A8: .4byte gSpecialVar_0x8005
_0812D6AC: .4byte gSaveBlock1Ptr
_0812D6B0: .4byte 0x00003a54
	thumb_func_end sub_812D650

	thumb_func_start sub_812D6B4
sub_812D6B4: @ 812D6B4
	push {r4,lr}
	ldr r0, _0812D6EC @ =gUnknown_203B0FC
	ldr r4, [r0]
	bl sub_812E064
	lsls r0, 16
	lsrs r0, 16
	adds r4, 0xC
	adds r4, r0
	ldrb r1, [r4]
	movs r2, 0
	ldr r0, _0812D6F0 @ =gSaveBlock1Ptr
	ldr r0, [r0]
	lsls r1, 2
	adds r0, r1
	ldr r1, _0812D6F4 @ =0x00003a54
	adds r0, r1
	ldrh r0, [r0]
	lsls r1, r0, 18
	movs r3, 0x1
_0812D6DC:
	lsrs r0, r1, 20
	asrs r0, r2
	ands r0, r3
	cmp r0, 0
	bne _0812D6F8
	movs r0, 0
	b _0812D704
	.align 2, 0
_0812D6EC: .4byte gUnknown_203B0FC
_0812D6F0: .4byte gSaveBlock1Ptr
_0812D6F4: .4byte 0x00003a54
_0812D6F8:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x5
	bls _0812D6DC
	movs r0, 0x1
_0812D704:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_812D6B4

	thumb_func_start sub_812D70C
sub_812D70C: @ 812D70C
	push {r4,lr}
	movs r4, 0xFA
	lsls r4, 2
	adds r0, r4, 0
	bl FreeSpriteTilesByTag
	adds r0, r4, 0
	bl FreeSpritePaletteByTag
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_812D70C

	thumb_func_start sub_812D724
sub_812D724: @ 812D724
	push {r4,lr}
	lsls r0, 16
	asrs r0, 16
	movs r4, 0x22
	cmp r0, 0x2
	ble _0812D732
	movs r4, 0x3D
_0812D732:
	movs r1, 0x3
	bl __modsi3
	lsls r0, 16
	asrs r0, 16
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 4
	subs r1, r0
	adds r1, 0x72
	ldr r0, _0812D760 @ =gUnknown_845FC44
	lsls r1, 16
	asrs r1, 16
	adds r2, r4, 0
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0812D760: .4byte gUnknown_845FC44
	thumb_func_end sub_812D724

	thumb_func_start sub_812D764
sub_812D764: @ 812D764
	push {lr}
	bl DestroySprite
	pop {r0}
	bx r0
	thumb_func_end sub_812D764

	thumb_func_start sub_812D770
sub_812D770: @ 812D770
	push {lr}
	ldr r0, _0812D77C @ =0x000003e9
	bl FreeSpriteTilesByTag
	pop {r0}
	bx r0
	.align 2, 0
_0812D77C: .4byte 0x000003e9
	thumb_func_end sub_812D770

	thumb_func_start sub_812D780
sub_812D780: @ 812D780
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	lsls r3, 24
	lsrs r3, 24
	lsls r2, 24
	lsrs r2, 24
	ldr r0, _0812D7C0 @ =gUnknown_845FC78
	adds r1, r3, 0
	movs r3, 0x8
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _0812D7C4 @ =gSprites
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r1
	ldrb r3, [r2, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r3
	movs r3, 0x8
	orrs r1, r3
	movs r3, 0xF
	ands r1, r3
	movs r3, 0x20
	orrs r1, r3
	strb r1, [r2, 0x5]
	pop {r1}
	bx r1
	.align 2, 0
_0812D7C0: .4byte gUnknown_845FC78
_0812D7C4: .4byte gSprites
	thumb_func_end sub_812D780

	thumb_func_start sub_812D7C8
sub_812D7C8: @ 812D7C8
	push {r4,lr}
	ldr r4, _0812D7E0 @ =0x000003ea
	adds r0, r4, 0
	bl FreeSpriteTilesByTag
	adds r0, r4, 0
	bl FreeSpritePaletteByTag
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0812D7E0: .4byte 0x000003ea
	thumb_func_end sub_812D7C8

	thumb_func_start sub_812D7E4
sub_812D7E4: @ 812D7E4
	push {lr}
	ldr r0, _0812D7FC @ =gUnknown_845FCB8
	movs r1, 0xE2
	movs r2, 0x42
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.align 2, 0
_0812D7FC: .4byte gUnknown_845FCB8
	thumb_func_end sub_812D7E4

	thumb_func_start sub_812D800
sub_812D800: @ 812D800
	push {r4,lr}
	adds r4, r0, 0
	bl FreeSpriteOamMatrix
	adds r0, r4, 0
	bl DestroySprite
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_812D800

	thumb_func_start sub_812D814
sub_812D814: @ 812D814
	push {lr}
	ldr r0, _0812D834 @ =0x000003ee
	bl FreeSpriteTilesByTag
	ldr r0, _0812D838 @ =0x000003ef
	bl FreeSpriteTilesByTag
	movs r0, 0xFC
	lsls r0, 2
	bl FreeSpriteTilesByTag
	ldr r0, _0812D83C @ =0x000003f1
	bl FreeSpriteTilesByTag
	pop {r0}
	bx r0
	.align 2, 0
_0812D834: .4byte 0x000003ee
_0812D838: .4byte 0x000003ef
_0812D83C: .4byte 0x000003f1
	thumb_func_end sub_812D814

	thumb_func_start sub_812D840
sub_812D840: @ 812D840
	push {lr}
	adds r2, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r2, r1]
	cmp r0, 0x1
	bne _0812D864
	movs r3, 0x24
	ldrsh r0, [r2, r3]
	subs r0, 0xA
	cmp r0, 0
	bge _0812D85E
	movs r0, 0
	strh r0, [r2, 0x24]
	strh r0, [r2, 0x2E]
	b _0812D882
_0812D85E:
	ldrh r0, [r2, 0x24]
	subs r0, 0xA
	b _0812D880
_0812D864:
	cmp r0, 0x2
	bne _0812D882
	ldrh r1, [r2, 0x24]
	movs r3, 0x24
	ldrsh r0, [r2, r3]
	cmp r0, 0xF0
	ble _0812D87C
	movs r1, 0
	movs r0, 0xF0
	strh r0, [r2, 0x24]
	strh r1, [r2, 0x2E]
	b _0812D882
_0812D87C:
	adds r0, r1, 0
	adds r0, 0xA
_0812D880:
	strh r0, [r2, 0x24]
_0812D882:
	pop {r0}
	bx r0
	thumb_func_end sub_812D840

	thumb_func_start sub_812D888
sub_812D888: @ 812D888
	push {r4,r5,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x1
	bne _0812D8B0
	ldr r0, _0812D8A8 @ =gUnknown_845FCE4
	movs r1, 0x94
	movs r2, 0x42
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, _0812D8AC @ =gUnknown_845ED60
	b _0812D906
	.align 2, 0
_0812D8A8: .4byte gUnknown_845FCE4
_0812D8AC: .4byte gUnknown_845ED60
_0812D8B0:
	cmp r5, 0xE
	bne _0812D8D0
	ldr r0, _0812D8C8 @ =gUnknown_845FCFC
	movs r1, 0x94
	movs r2, 0x42
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, _0812D8CC @ =gUnknown_845DD20
	b _0812D906
	.align 2, 0
_0812D8C8: .4byte gUnknown_845FCFC
_0812D8CC: .4byte gUnknown_845DD20
_0812D8D0:
	cmp r5, 0
	bne _0812D8F0
	ldr r0, _0812D8E8 @ =gUnknown_845FD14
	movs r1, 0x94
	movs r2, 0x42
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, _0812D8EC @ =gUnknown_845F580
	b _0812D906
	.align 2, 0
_0812D8E8: .4byte gUnknown_845FD14
_0812D8EC: .4byte gUnknown_845F580
_0812D8F0:
	cmp r5, 0xD
	bne _0812D934
	ldr r0, _0812D928 @ =gUnknown_845FD2C
	movs r1, 0x94
	movs r2, 0x42
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, _0812D92C @ =gUnknown_845E540
_0812D906:
	movs r1, 0xB0
	lsls r1, 1
	movs r2, 0x20
	bl LoadPalette
	ldr r1, _0812D930 @ =gSprites
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	ldrb r2, [r0, 0x5]
	movs r1, 0xF
	ands r1, r2
	movs r2, 0x60
	orrs r1, r2
	strb r1, [r0, 0x5]
	b _0812D950
	.align 2, 0
_0812D928: .4byte gUnknown_845FD2C
_0812D92C: .4byte gUnknown_845E540
_0812D930: .4byte gSprites
_0812D934:
	ldr r0, _0812D98C @ =gUnknown_845F61C
	adds r0, r5, r0
	ldrb r0, [r0]
	movs r1, 0x6
	str r1, [sp]
	ldr r1, _0812D990 @ =0x0000ffff
	str r1, [sp, 0x4]
	movs r1, 0x1
	movs r2, 0x94
	movs r3, 0x42
	bl sub_810C2A4
	lsls r0, 24
	lsrs r4, r0, 24
_0812D950:
	ldr r1, _0812D994 @ =gSprites
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r1, 0x1C
	adds r0, r1
	ldr r1, _0812D998 @ =sub_812D840
	str r1, [r0]
	ldr r0, _0812D99C @ =gSaveBlock1Ptr
	ldr r0, [r0]
	lsls r1, r5, 2
	adds r0, r1
	ldr r1, _0812D9A0 @ =0x00003a54
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r0, 30
	cmp r0, 0x1
	bne _0812D982
	ldr r0, _0812D9A4 @ =gUnknown_845F5C0
	movs r1, 0xB0
	lsls r1, 1
	movs r2, 0x20
	bl LoadPalette
_0812D982:
	adds r0, r4, 0
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0812D98C: .4byte gUnknown_845F61C
_0812D990: .4byte 0x0000ffff
_0812D994: .4byte gSprites
_0812D998: .4byte sub_812D840
_0812D99C: .4byte gSaveBlock1Ptr
_0812D9A0: .4byte 0x00003a54
_0812D9A4: .4byte gUnknown_845F5C0
	thumb_func_end sub_812D888

	thumb_func_start sub_812D9A8
sub_812D9A8: @ 812D9A8
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 3
	ldr r0, _0812D9FC @ =gTasks+0x8
	adds r4, r2, r0
	lsrs r1, 16
	ldr r0, _0812DA00 @ =gUnknown_203B0FC
	ldr r2, [r0]
	ldrb r0, [r2, 0x7]
	lsrs r3, r0, 2
	subs r0, r3, 0x1
	cmp r1, r0
	bne _0812D9D0
	subs r0, r3, 0x2
	lsls r0, 16
	lsrs r1, r0, 16
_0812D9D0:
	adds r0, r2, 0
	adds r0, 0xC
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0812D9E8
	cmp r0, 0xE
	beq _0812D9E8
	cmp r0, 0
	beq _0812D9E8
	cmp r0, 0xD
	bne _0812DA08
_0812D9E8:
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, _0812DA04 @ =gSprites
	adds r0, r1
	bl DestroySprite
	b _0812DA0E
	.align 2, 0
_0812D9FC: .4byte gTasks+0x8
_0812DA00: .4byte gUnknown_203B0FC
_0812DA04: .4byte gSprites
_0812DA08:
	ldrh r0, [r4, 0x4]
	bl sub_810C2E8
_0812DA0E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_812D9A8

	thumb_func_start sub_812DA14
sub_812DA14: @ 812DA14
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_812E064
	ldr r1, _0812DAF8 @ =gUnknown_203B0FC
	ldr r1, [r1]
	lsls r0, 16
	lsrs r0, 16
	adds r1, 0xC
	adds r1, r0
	ldrb r0, [r1]
	lsls r5, r0, 1
	adds r5, r0
	lsls r5, 1
	adds r5, r4
	movs r0, 0x1
	bl sub_812E094
	ldr r1, _0812DAFC @ =gUnknown_3005EC8
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0x58
	str r0, [sp]
	movs r0, 0x20
	str r0, [sp, 0x4]
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillWindowPixelRect
	ldr r0, _0812DB00 @ =gUnknown_845F89C
	lsls r5, 2
	adds r0, r5, r0
	ldr r6, [r0]
	movs r0, 0
	adds r1, r6, 0
	movs r2, 0
	bl GetStringWidth
	movs r4, 0x54
	subs r0, r4, r0
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	lsls r2, r0, 24
	lsrs r2, 24
	movs r7, 0
	str r7, [sp]
	movs r0, 0x2
	mov r10, r0
	str r0, [sp, 0x4]
	ldr r0, _0812DB04 @ =gUnknown_845F5E3
	mov r9, r0
	str r0, [sp, 0x8]
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	str r0, [sp, 0xC]
	str r6, [sp, 0x10]
	movs r0, 0x3
	movs r1, 0
	movs r3, 0
	bl AddTextPrinterParametrized2
	ldr r6, _0812DB08 @ =gStringVar1
	ldr r0, _0812DB0C @ =gUnknown_845FA1C
	adds r5, r0
	ldr r1, [r5]
	adds r0, r6, 0
	bl StringExpandPlaceholders
	movs r0, 0
	adds r1, r6, 0
	movs r2, 0
	bl GetStringWidth
	subs r4, r0
	lsrs r0, r4, 31
	adds r4, r0
	asrs r0, r4, 1
	lsls r2, r0, 24
	lsrs r2, 24
	str r7, [sp]
	mov r0, r10
	str r0, [sp, 0x4]
	mov r0, r9
	str r0, [sp, 0x8]
	mov r0, r8
	str r0, [sp, 0xC]
	str r6, [sp, 0x10]
	movs r0, 0x3
	movs r1, 0
	movs r3, 0xA
	bl AddTextPrinterParametrized2
	movs r0, 0x3
	bl sub_812CEE0
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812DAF8: .4byte gUnknown_203B0FC
_0812DAFC: .4byte gUnknown_3005EC8
_0812DB00: .4byte gUnknown_845F89C
_0812DB04: .4byte gUnknown_845F5E3
_0812DB08: .4byte gStringVar1
_0812DB0C: .4byte gUnknown_845FA1C
	thumb_func_end sub_812DA14

	thumb_func_start sub_812DB10
sub_812DB10: @ 812DB10
	push {lr}
	movs r0, 0
	bl sub_812E094
	ldr r1, _0812DB24 @ =gUnknown_3005EC8
	movs r0, 0xFF
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0812DB24: .4byte gUnknown_3005EC8
	thumb_func_end sub_812DB10

	thumb_func_start sub_812DB28
sub_812DB28: @ 812DB28
	push {r4,lr}
	bl sub_812DB64
	bl sub_812DEF0
	ldr r4, _0812DB5C @ =gUnknown_203B0FC
	ldr r3, [r4]
	lsls r0, 2
	ldrb r2, [r3, 0x7]
	movs r1, 0x3
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x7]
	ldr r0, _0812DB60 @ =gUnknown_3005EB0
	movs r1, 0
	movs r2, 0
	bl ListMenuInit
	ldr r1, [r4]
	strb r0, [r1, 0x8]
	movs r0, 0
	bl sub_812DFE4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0812DB5C: .4byte gUnknown_203B0FC
_0812DB60: .4byte gUnknown_3005EB0
	thumb_func_end sub_812DB28

	thumb_func_start sub_812DB64
sub_812DB64: @ 812DB64
	ldr r2, _0812DBB4 @ =gUnknown_3005EB0
	ldr r0, _0812DBB8 @ =gUnknown_203B100
	ldr r0, [r0]
	str r0, [r2]
	ldr r0, _0812DBBC @ =sub_812DBC0
	str r0, [r2, 0x4]
	movs r0, 0
	str r0, [r2, 0x8]
	movs r1, 0
	movs r0, 0x1
	strh r0, [r2, 0xC]
	strh r0, [r2, 0xE]
	strb r1, [r2, 0x10]
	strb r1, [r2, 0x11]
	movs r0, 0x8
	strb r0, [r2, 0x12]
	strb r1, [r2, 0x13]
	ldrb r1, [r2, 0x14]
	subs r0, 0x18
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	movs r1, 0xF
	ands r0, r1
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r2, 0x14]
	movs r0, 0x30
	strb r0, [r2, 0x15]
	movs r3, 0x3F
	movs r0, 0
	strb r0, [r2, 0x16]
	ldrb r1, [r2, 0x17]
	subs r0, 0x40
	ands r0, r1
	movs r1, 0x2
	orrs r0, r1
	ands r0, r3
	strb r0, [r2, 0x17]
	bx lr
	.align 2, 0
_0812DBB4: .4byte gUnknown_3005EB0
_0812DBB8: .4byte gUnknown_203B100
_0812DBBC: .4byte sub_812DBC0
	thumb_func_end sub_812DB64

	thumb_func_start sub_812DBC0
sub_812DBC0: @ 812DBC0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	adds r7, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r0, _0812DC68 @ =gUnknown_203B104
	mov r10, r0
	movs r2, 0
	mov r8, r2
	str r2, [r0]
	ldr r6, _0812DC6C @ =gUnknown_203B0FC
	ldr r0, [r6]
	ldrb r2, [r0, 0xA]
	ldrb r0, [r0, 0xB]
	adds r2, r0
	mov r9, r2
	adds r0, r7, 0
	bl sub_812DDF0
	ldr r0, _0812DC70 @ =sub_812C694
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xFF
	bne _0812DBFE
	b _0812DD3A
_0812DBFE:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, _0812DC74 @ =gTasks
	adds r5, r0, r1
	movs r0, 0x5
	bl PlaySE
	mov r0, r8
	strh r0, [r5, 0xA]
	ldr r0, [r6]
	ldrb r0, [r0, 0x8]
	add r1, sp, 0x8
	movs r2, 0
	bl get_coro_args_x18_x1A
	ldr r1, [r6]
	add r0, sp, 0x8
	ldrh r0, [r0]
	strh r0, [r1, 0x4]
	ldrb r0, [r1, 0x7]
	lsrs r0, 2
	subs r0, 0x1
	cmp r7, r0
	beq _0812DCD8
	bl sub_812D174
	lsls r0, r7, 24
	lsrs r0, 24
	bl sub_812D1A8
	ldr r2, [r6]
	ldrb r1, [r2, 0x7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0812DCBC
	adds r0, r2, 0
	adds r0, 0x23
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _0812DC7C
	adds r0, r4, 0
	mov r1, r9
	bl sub_812D9A8
	mov r1, r10
	str r7, [r1]
	ldr r0, _0812DC78 @ =sub_812DD50
	str r0, [r5]
	b _0812DD3A
	.align 2, 0
_0812DC68: .4byte gUnknown_203B104
_0812DC6C: .4byte gUnknown_203B0FC
_0812DC70: .4byte sub_812C694
_0812DC74: .4byte gTasks
_0812DC78: .4byte sub_812DD50
_0812DC7C:
	ldr r4, _0812DCB8 @ =gSprites
	movs r2, 0xC
	ldrsh r0, [r5, r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	adds r1, 0x3E
	ldrb r3, [r1]
	movs r2, 0x5
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, 0x23
	ldrb r1, [r0]
	ands r2, r1
	strb r2, [r0]
	movs r0, 0xC
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	mov r1, r8
	strh r1, [r0, 0x2E]
	bl sub_812CD3C
	b _0812DD3A
	.align 2, 0
_0812DCB8: .4byte gSprites
_0812DCBC:
	movs r0, 0xD0
	str r0, [sp]
	movs r0, 0x20
	str r0, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0x11
	movs r2, 0
	movs r3, 0
	bl FillWindowPixelRect
	movs r0, 0x2
	bl sub_812CEE0
	b _0812DD3A
_0812DCD8:
	bl sub_812DDAC
	ldr r0, [r6]
	ldrb r1, [r0, 0x7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0812DD10
	ldr r2, _0812DD0C @ =gSprites
	movs r0, 0xC
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	ldr r1, [r6]
	adds r1, 0x23
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	b _0812DD3A
	.align 2, 0
_0812DD0C: .4byte gSprites
_0812DD10:
	movs r2, 0
	ldr r5, _0812DD4C @ =gSprites
	adds r4, r6, 0
	movs r3, 0x4
_0812DD18:
	ldr r0, [r4]
	adds r0, 0x1D
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r3
	strb r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x5
	bls _0812DD18
_0812DD3A:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812DD4C: .4byte gSprites
	thumb_func_end sub_812DBC0

	thumb_func_start sub_812DD50
sub_812DD50: @ 812DD50
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, _0812DD98 @ =gTasks
	adds r4, r0
	ldr r0, _0812DD9C @ =gUnknown_203B0FC
	ldr r0, [r0]
	ldr r1, _0812DDA0 @ =gUnknown_203B104
	adds r0, 0xC
	ldr r1, [r1]
	adds r0, r1
	ldrb r0, [r0]
	bl sub_812D888
	lsls r0, 24
	lsrs r0, 24
	movs r3, 0
	strh r0, [r4, 0xC]
	ldr r2, _0812DDA4 @ =gSprites
	movs r0, 0xC
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r3, [r0, 0x2E]
	bl sub_812CD3C
	ldr r0, _0812DDA8 @ =sub_812C694
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0812DD98: .4byte gTasks
_0812DD9C: .4byte gUnknown_203B0FC
_0812DDA0: .4byte gUnknown_203B104
_0812DDA4: .4byte gSprites
_0812DDA8: .4byte sub_812C694
	thumb_func_end sub_812DD50

	thumb_func_start sub_812DDAC
sub_812DDAC: @ 812DDAC
	push {lr}
	sub sp, 0x10
	movs r0, 0xD0
	str r0, [sp]
	movs r0, 0x20
	str r0, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0x11
	movs r2, 0
	movs r3, 0
	bl FillWindowPixelRect
	ldr r2, _0812DDEC @ =gUnknown_84181C3
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0x2
	movs r1, 0x2
	movs r3, 0
	bl AddTextPrinterParametrized
	movs r0, 0x2
	bl sub_812CEE0
	add sp, 0x10
	pop {r0}
	bx r0
	.align 2, 0
_0812DDEC: .4byte gUnknown_84181C3
	thumb_func_end sub_812DDAC

	thumb_func_start sub_812DDF0
sub_812DDF0: @ 812DDF0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x18
	mov r8, r0
	lsls r5, r1, 24
	lsrs r5, 24
	ldr r7, _0812DE68 @ =gUnknown_203B0FC
	ldr r0, [r7]
	ldrb r0, [r0, 0x8]
	mov r4, sp
	adds r4, 0x16
	add r1, sp, 0x14
	adds r2, r4, 0
	bl get_coro_args_x18_x1A
	add r1, sp, 0x14
	ldrh r0, [r4]
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 16
	lsrs r6, r0, 16
	ldrh r0, [r4]
	lsls r3, r0, 3
	subs r3, r0
	lsls r3, 25
	movs r0, 0x80
	lsls r0, 19
	adds r3, r0
	lsrs r3, 24
	movs r1, 0
	str r1, [sp]
	str r1, [sp, 0x4]
	ldr r0, _0812DE6C @ =gUnknown_845F5E6
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	ldr r0, _0812DE70 @ =gUnknown_203B100
	ldr r1, [r0]
	mov r2, r8
	lsls r0, r2, 3
	adds r0, r1
	ldr r0, [r0]
	str r0, [sp, 0x10]
	movs r0, 0
	movs r1, 0x2
	movs r2, 0x8
	bl AddTextPrinterParametrized2
	cmp r5, 0
	bne _0812DEC0
	add r0, sp, 0x14
	ldr r1, [r7]
	ldrh r2, [r0]
	ldrb r0, [r1, 0xA]
	cmp r2, r0
	bcs _0812DE74
	ldrb r0, [r1, 0xB]
	adds r0, 0x1
	b _0812DE86
	.align 2, 0
_0812DE68: .4byte gUnknown_203B0FC
_0812DE6C: .4byte gUnknown_845F5E6
_0812DE70: .4byte gUnknown_203B100
_0812DE74:
	cmp r2, r0
	bls _0812DE88
	ldrb r0, [r1, 0x7]
	lsrs r0, 2
	subs r0, 0x1
	cmp r6, r0
	beq _0812DE88
	ldrb r0, [r1, 0xB]
	subs r0, 0x1
_0812DE86:
	strb r0, [r1, 0xB]
_0812DE88:
	ldr r0, _0812DEE4 @ =gUnknown_203B0FC
	ldr r2, [r0]
	ldrb r0, [r2, 0xB]
	lsls r3, r0, 3
	subs r3, r0
	lsls r3, 25
	movs r0, 0x80
	lsls r0, 19
	adds r3, r0
	lsrs r3, 24
	movs r1, 0
	str r1, [sp]
	str r1, [sp, 0x4]
	ldr r0, _0812DEE8 @ =gUnknown_845F5E3
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	ldrb r0, [r2, 0x9]
	ldr r1, _0812DEEC @ =gUnknown_203B100
	ldr r1, [r1]
	lsls r0, 3
	adds r0, r1
	ldr r0, [r0]
	str r0, [sp, 0x10]
	movs r0, 0
	movs r1, 0x2
	movs r2, 0x8
	bl AddTextPrinterParametrized2
_0812DEC0:
	ldr r1, _0812DEE4 @ =gUnknown_203B0FC
	ldr r0, [r1]
	mov r2, r8
	strb r2, [r0, 0x9]
	ldr r2, [r1]
	ldrh r0, [r4]
	strb r0, [r2, 0xB]
	ldr r1, [r1]
	add r0, sp, 0x14
	ldrh r0, [r0]
	strb r0, [r1, 0xA]
	add sp, 0x18
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812DEE4: .4byte gUnknown_203B0FC
_0812DEE8: .4byte gUnknown_845F5E3
_0812DEEC: .4byte gUnknown_203B100
	thumb_func_end sub_812DDF0

	thumb_func_start sub_812DEF0
sub_812DEF0: @ 812DEF0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r4, 0
	movs r6, 0
	ldr r0, _0812DF44 @ =0x0000fdff
	mov r8, r0
	ldr r7, _0812DF48 @ =gUnknown_845F60C
_0812DF00:
	adds r0, r6, 0
	bl sub_812D0C0
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, _0812DF4C @ =gSaveBlock1Ptr
	ldr r0, [r0]
	lsls r1, r5, 2
	adds r0, r1
	ldr r1, _0812DF50 @ =0x00003a54
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 30
	cmp r0, 0
	beq _0812DF88
	ldr r0, _0812DF54 @ =gUnknown_845F5EA
	lsls r1, r5, 1
	adds r3, r1, r0
	ldrh r0, [r3]
	cmp r0, r8
	bhi _0812DF60
	ldr r0, _0812DF58 @ =gUnknown_203B100
	ldr r0, [r0]
	lsls r2, r4, 3
	adds r2, r0
	ldrh r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	ldr r1, _0812DF5C @ =gTrainers+0x4
	adds r0, r1
	str r0, [r2]
	str r4, [r2, 0x4]
	b _0812DF78
	.align 2, 0
_0812DF44: .4byte 0x0000fdff
_0812DF48: .4byte gUnknown_845F60C
_0812DF4C: .4byte gSaveBlock1Ptr
_0812DF50: .4byte 0x00003a54
_0812DF54: .4byte gUnknown_845F5EA
_0812DF58: .4byte gUnknown_203B100
_0812DF5C: .4byte gTrainers+0x4
_0812DF60:
	ldr r0, _0812DFC0 @ =gUnknown_203B100
	ldr r0, [r0]
	lsls r1, r4, 3
	adds r1, r0
	ldrh r0, [r3]
	ldr r2, _0812DFC4 @ =0xffff0200
	adds r0, r2
	lsls r0, 2
	adds r0, r7
	ldr r0, [r0]
	str r0, [r1]
	str r4, [r1, 0x4]
_0812DF78:
	ldr r0, _0812DFC8 @ =gUnknown_203B0FC
	ldr r0, [r0]
	adds r0, 0xC
	adds r0, r4
	strb r5, [r0]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_0812DF88:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0xF
	bls _0812DF00
	ldr r0, _0812DFC0 @ =gUnknown_203B100
	ldr r1, [r0]
	lsls r0, r4, 3
	adds r0, r1
	ldr r1, _0812DFCC @ =gUnknown_84161C1
	str r1, [r0]
	str r4, [r0, 0x4]
	ldr r0, _0812DFC8 @ =gUnknown_203B0FC
	ldr r0, [r0]
	adds r0, 0xC
	adds r0, r4
	movs r1, 0xFF
	strb r1, [r0]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, _0812DFD0 @ =gUnknown_3005EB0
	strh r4, [r1, 0xC]
	cmp r4, 0x4
	bhi _0812DFD4
	strh r4, [r1, 0xE]
	b _0812DFD8
	.align 2, 0
_0812DFC0: .4byte gUnknown_203B100
_0812DFC4: .4byte 0xffff0200
_0812DFC8: .4byte gUnknown_203B0FC
_0812DFCC: .4byte gUnknown_84161C1
_0812DFD0: .4byte gUnknown_3005EB0
_0812DFD4:
	movs r0, 0x5
	strh r0, [r1, 0xE]
_0812DFD8:
	adds r0, r4, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_812DEF0

	thumb_func_start sub_812DFE4
sub_812DFE4: @ 812DFE4
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl PutWindowTilemap
	adds r0, r4, 0
	movs r1, 0x3
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_812DFE4

	thumb_func_start sub_812E000
sub_812E000: @ 812E000
	push {r4,lr}
	sub sp, 0x10
	mov r1, sp
	ldr r0, _0812E040 @ =gUnknown_845FD44
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	ldr r4, _0812E044 @ =gUnknown_203B0FC
	ldr r2, [r4]
	ldrb r0, [r2, 0x7]
	lsrs r0, 2
	cmp r0, 0x5
	bls _0812E036
	mov r1, sp
	movs r0, 0
	strh r0, [r1, 0x6]
	ldrb r0, [r2, 0x7]
	lsrs r0, 2
	subs r0, 0x5
	strh r0, [r1, 0x8]
	adds r1, r2, 0x4
	mov r0, sp
	bl AddScrollIndicatorArrowPair
	ldr r1, [r4]
	strb r0, [r1, 0x6]
_0812E036:
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0812E040: .4byte gUnknown_845FD44
_0812E044: .4byte gUnknown_203B0FC
	thumb_func_end sub_812E000

	thumb_func_start sub_812E048
sub_812E048: @ 812E048
	push {lr}
	ldr r0, _0812E060 @ =gUnknown_203B0FC
	ldr r1, [r0]
	ldrb r0, [r1, 0x7]
	lsrs r0, 2
	cmp r0, 0x5
	bls _0812E05C
	ldrb r0, [r1, 0x6]
	bl RemoveScrollIndicatorArrowPair
_0812E05C:
	pop {r0}
	bx r0
	.align 2, 0
_0812E060: .4byte gUnknown_203B0FC
	thumb_func_end sub_812E048

	thumb_func_start sub_812E064
sub_812E064: @ 812E064
	push {r4,lr}
	sub sp, 0x4
	ldr r0, _0812E090 @ =gUnknown_203B0FC
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	mov r4, sp
	adds r4, 0x2
	mov r1, sp
	adds r2, r4, 0
	bl get_coro_args_x18_x1A
	mov r1, sp
	ldrh r0, [r4]
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0812E090: .4byte gUnknown_203B0FC
	thumb_func_end sub_812E064

	thumb_func_start sub_812E094
sub_812E094: @ 812E094
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	ldr r6, _0812E0EC @ =gUnknown_203B0FC
	ldr r0, [r6]
	adds r0, 0x23
	ldrb r0, [r0]
	lsls r0, 31
	lsrs r0, 31
	cmp r0, r4
	beq _0812E108
	ldr r5, _0812E0F0 @ =sub_812E110
	adds r0, r5, 0
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	bne _0812E0C8
	adds r0, r5, 0
	movs r1, 0x8
	bl CreateTask
	lsls r0, 24
	lsrs r2, r0, 24
_0812E0C8:
	ldr r0, _0812E0F4 @ =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	movs r0, 0
	strh r0, [r1, 0x8]
	movs r0, 0x4
	strh r0, [r1, 0xA]
	cmp r4, 0x1
	bne _0812E0F8
	strh r4, [r1, 0xC]
	ldr r0, [r6]
	adds r0, 0x23
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	b _0812E106
	.align 2, 0
_0812E0EC: .4byte gUnknown_203B0FC
_0812E0F0: .4byte sub_812E110
_0812E0F4: .4byte gTasks
_0812E0F8:
	strh r0, [r1, 0xC]
	ldr r0, [r6]
	adds r0, 0x23
	ldrb r2, [r0]
	movs r1, 0x2
	negs r1, r1
	ands r1, r2
_0812E106:
	strb r1, [r0]
_0812E108:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_812E094

	thumb_func_start sub_812E110
sub_812E110: @ 812E110
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, _0812E130 @ =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0812E134
	cmp r0, 0x1
	beq _0812E154
	b _0812E170
	.align 2, 0
_0812E130: .4byte gTasks
_0812E134:
	ldrh r0, [r4, 0xA]
	subs r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	cmp r0, 0
	bne _0812E170
	movs r0, 0x1
	movs r1, 0
	bl sub_812E178
	movs r0, 0x4
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0812E170
_0812E154:
	ldrh r0, [r4, 0xA]
	subs r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	cmp r0, 0
	bne _0812E170
	movs r0, 0xC
	ldrsh r1, [r4, r0]
	movs r0, 0x1
	bl sub_812E178
	adds r0, r5, 0
	bl DestroyTask
_0812E170:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_812E110

	thumb_func_start sub_812E178
sub_812E178: @ 812E178
	push {r4-r6,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 16
	asrs r5, r1, 16
	cmp r5, 0
	beq _0812E18C
	cmp r5, 0x3
	bne _0812E252
_0812E18C:
	movs r4, 0x1
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x8C
	movs r2, 0xE
	movs r3, 0xA
	bl FillBgTilemapBufferRect
	movs r5, 0xA
	str r5, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0xA1
	movs r2, 0xF
	movs r3, 0xA
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x8D
	movs r2, 0x19
	movs r3, 0xA
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x8E
	movs r2, 0x1A
	movs r3, 0xA
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x8F
	movs r2, 0xE
	movs r3, 0xB
	bl FillBgTilemapBufferRect
	movs r0, 0xB
	str r0, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0xF
	movs r3, 0xB
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x90
	movs r2, 0x1A
	movs r3, 0xB
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x91
	movs r2, 0xE
	movs r3, 0xC
	bl FillBgTilemapBufferRect
	str r5, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0xA3
	movs r2, 0xF
	movs r3, 0xC
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x92
	movs r2, 0x19
	movs r3, 0xC
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x93
	b _0812E470
_0812E252:
	cmp r5, 0x1
	bne _0812E2F4
	str r5, [sp]
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x9B
	movs r2, 0xE
	movs r3, 0xA
	bl FillBgTilemapBufferRect
	movs r4, 0xB
	str r4, [sp]
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x9C
	movs r2, 0xF
	movs r3, 0xA
	bl FillBgTilemapBufferRect
	str r5, [sp]
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x96
	movs r2, 0x1A
	movs r3, 0xA
	bl FillBgTilemapBufferRect
	str r5, [sp]
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x9D
	movs r2, 0xE
	movs r3, 0xB
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0xF
	movs r3, 0xB
	bl FillBgTilemapBufferRect
	str r5, [sp]
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x90
	movs r2, 0x1A
	movs r3, 0xB
	bl FillBgTilemapBufferRect
	str r5, [sp]
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x9E
	movs r2, 0xE
	movs r3, 0xC
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x9F
	movs r2, 0xF
	movs r3, 0xC
	bl FillBgTilemapBufferRect
	str r5, [sp]
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x99
	b _0812E470
_0812E2F4:
	cmp r5, 0x2
	bne _0812E398
	movs r4, 0x1
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x94
	movs r2, 0xE
	movs r3, 0xA
	bl FillBgTilemapBufferRect
	movs r5, 0xB
	str r5, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x95
	movs r2, 0xF
	movs r3, 0xA
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x96
	movs r2, 0x1A
	movs r3, 0xA
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x8F
	movs r2, 0xE
	movs r3, 0xB
	bl FillBgTilemapBufferRect
	str r5, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x9A
	movs r2, 0xF
	movs r3, 0xB
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x90
	movs r2, 0x1A
	movs r3, 0xB
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x97
	movs r2, 0xE
	movs r3, 0xC
	bl FillBgTilemapBufferRect
	str r5, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x98
	movs r2, 0xF
	movs r3, 0xC
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x99
	b _0812E470
_0812E398:
	cmp r5, 0x4
	bne _0812E47A
	movs r4, 0x1
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x83
	movs r2, 0xE
	movs r3, 0xA
	bl FillBgTilemapBufferRect
	movs r5, 0xA
	str r5, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0xA0
	movs r2, 0xF
	movs r3, 0xA
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x84
	movs r2, 0x19
	movs r3, 0xA
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x85
	movs r2, 0x1A
	movs r3, 0xA
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x86
	movs r2, 0xE
	movs r3, 0xB
	bl FillBgTilemapBufferRect
	str r5, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0xA2
	movs r2, 0xF
	movs r3, 0xB
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x87
	movs r2, 0x19
	movs r3, 0xB
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x88
	movs r2, 0x1A
	movs r3, 0xB
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x83
	movs r2, 0xE
	movs r3, 0xC
	bl FillBgTilemapBufferRect
	str r5, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0xA0
	movs r2, 0xF
	movs r3, 0xC
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x84
	movs r2, 0x19
	movs r3, 0xC
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x85
_0812E470:
	movs r2, 0x1A
	movs r3, 0xC
	bl FillBgTilemapBufferRect
	b _0812E496
_0812E47A:
	cmp r5, 0x5
	bne _0812E496
	movs r0, 0xD
	str r0, [sp]
	movs r0, 0x3
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0xE
	movs r3, 0xA
	bl FillBgTilemapBufferRect
_0812E496:
	adds r0, r6, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_812E178

	thumb_func_start sub_812E4A4
sub_812E4A4: @ 812E4A4
	push {r4,lr}
	sub sp, 0x14
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, _0812E4E0 @ =gUnknown_203B0FC
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	bl ListMenuGetYCoordForPrintingArrowCursor
	lsls r0, 16
	lsrs r0, 16
	cmp r4, 0x1
	bne _0812E4EC
	lsls r3, r0, 24
	lsrs r3, 24
	movs r1, 0
	str r1, [sp]
	str r1, [sp, 0x4]
	ldr r0, _0812E4E4 @ =gUnknown_845F5E3
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	ldr r0, _0812E4E8 @ =gUnknown_841623B
	str r0, [sp, 0x10]
	movs r0, 0
	movs r1, 0x2
	movs r2, 0
	bl AddTextPrinterParametrized2
	b _0812E50A
	.align 2, 0
_0812E4E0: .4byte gUnknown_203B0FC
_0812E4E4: .4byte gUnknown_845F5E3
_0812E4E8: .4byte gUnknown_841623B
_0812E4EC:
	lsls r3, r0, 24
	lsrs r3, 24
	movs r1, 0
	str r1, [sp]
	str r1, [sp, 0x4]
	ldr r0, _0812E514 @ =gUnknown_845F5E0
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	ldr r0, _0812E518 @ =gUnknown_841623B
	str r0, [sp, 0x10]
	movs r0, 0
	movs r1, 0x2
	movs r2, 0
	bl AddTextPrinterParametrized2
_0812E50A:
	add sp, 0x14
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0812E514: .4byte gUnknown_845F5E0
_0812E518: .4byte gUnknown_841623B
	thumb_func_end sub_812E4A4

	.align 2, 0 @ Don't pad with nop.
