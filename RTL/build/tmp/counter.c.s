	.file	"counter.c"
	.option nopic
	.attribute arch, "rv32i2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.globl	initData
	.section	.sdata,"aw"
	.align	2
	.type	initData, @object
	.size	initData, 4
initData:
	.word	255
	.globl	initData2
	.align	2
	.type	initData2, @object
	.size	initData2, 4
initData2:
	.word	-1412567279
	.globl	aproxsecond
	.align	2
	.type	aproxsecond, @object
	.size	aproxsecond, 4
aproxsecond:
	.word	1000000
	.text
	.align	2
	.globl	wait1sec
	.type	wait1sec, @function
wait1sec:
	addi	sp,sp,-32
	sw	s0,28(sp)
	addi	s0,sp,32
	sw	zero,-20(s0)
	j	.L2
.L3:
 #APP
# 7 "./firmware/counter.c" 1
	nop
# 0 "" 2
 #NO_APP
	lw	a5,-20(s0)
	addi	a5,a5,1
	sw	a5,-20(s0)
.L2:
	lw	a4,-20(s0)
	li	a5,999424
	addi	a5,a5,575
	ble	a4,a5,.L3
	nop
	nop
	lw	s0,28(sp)
	addi	sp,sp,32
	jr	ra
	.size	wait1sec, .-wait1sec
	.align	2
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-32
	sw	ra,28(sp)
	sw	s0,24(sp)
	addi	s0,sp,32
.L5:
	li	a5,8192
	addi	a5,a5,1
	sw	a5,-20(s0)
	lw	a5,-20(s0)
	sb	zero,0(a5)
	lw	a5,-20(s0)
	li	a4,1
	sb	a4,0(a5)
	call	wait1sec
	lw	a5,-20(s0)
	li	a4,2
	sb	a4,0(a5)
	call	wait1sec
	lw	a5,-20(s0)
	li	a4,4
	sb	a4,0(a5)
	call	wait1sec
	lw	a5,-20(s0)
	li	a4,8
	sb	a4,0(a5)
	call	wait1sec
	lw	a5,-20(s0)
	li	a4,16
	sb	a4,0(a5)
	call	wait1sec
	lw	a5,-20(s0)
	li	a4,32
	sb	a4,0(a5)
	call	wait1sec
	lw	a5,-20(s0)
	li	a4,64
	sb	a4,0(a5)
	call	wait1sec
	lw	a5,-20(s0)
	li	a4,-128
	sb	a4,0(a5)
	call	wait1sec
	lw	a5,-20(s0)
	li	a4,-64
	sb	a4,0(a5)
	call	wait1sec
	lw	a5,-20(s0)
	li	a4,-32
	sb	a4,0(a5)
	call	wait1sec
	lw	a5,-20(s0)
	li	a4,-16
	sb	a4,0(a5)
	call	wait1sec
	lw	a5,-20(s0)
	li	a4,-8
	sb	a4,0(a5)
	call	wait1sec
	lw	a5,-20(s0)
	li	a4,-4
	sb	a4,0(a5)
	call	wait1sec
	lw	a5,-20(s0)
	li	a4,-2
	sb	a4,0(a5)
	call	wait1sec
	lw	a5,-20(s0)
	li	a4,-1
	sb	a4,0(a5)
	call	wait1sec
	j	.L5
	.size	main, .-main
	.ident	"GCC: (GNU) 11.1.0"
