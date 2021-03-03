// .text段保存代码，是只读和可执行的，后面那些指令都属于.text段
.text

// 表示后面的指令全部用arm指令集
.code 32


// .global 将符号 声明为 一个 全局符号, 其他汇编文件或者c语言可以引用
// 连接的时候表明入口地址 -e _start
.global _start


// 一个符号,符号不占用 bin 文件的空间,
// 符号有一个地址,可以在本汇编文件中引用这个符号
_start:

//sys_init:
	// DDI0301H_arm1176jzfs_r0p7_trm.pdf
	// MCR p15, 0, <Rd>, c15, c2, 4 ; Write Peripheral Port Memory Remap Register
	// 暂时没用
//	ldr r0, =0x70000000
//	orr r0, r0, #0x13
//	mcr p15,0,r0,c15,c2,4       @ 256M(0x70000000-0x7fffffff)
//
//  bl0 中已经关了看门狗,不用再关一次
//	/* 关看门狗 */
//	/* 往WTCON(0x7E004000)写0 */
//	ldr r0, =0x7E004000
//	mov r1, #0
//	str r1, [r0]

led_init:
	/* 设置GPMCON让GPM0-3作为输出引脚 */
	/*GPMCON = 0x7F008820
	  GPMDAT = 0x7F008824*/
	ldr r0, =0x7F008820
	ldr r1, =0x1111
	str r1, [r0]

	// LED operations

	// on bic

	/* LED1 	0b0001 */
	/* LED2 	0b0010 */
	/* LED3 	0b0100 */
	/* LED4 	0b1000 */
	/* LEDall 	0b1111 */

	// off orr

	/* LED1 	0b0001 */
	/* LED2 	0b0010 */
	/* LED3 	0b0100 */
	/* LED4  	0b1000 */
	/* LEDall  	0b1111 */


led_all_on:

	ldr r0, =0x7F008824
	ldr r1, [r0]
	bic r1,r1,#0b1111
	str r1, [r0]
	bl delay



led4_flash:


	ldr r0, =0x7F008824
	ldr r1, [r0]
	bic r1,r1,#0b1000
	str r1, [r0]
	bl delay

	ldr r0, =0x7F008824
	ldr r1, [r0]
	orr r1,r1,#0b1000
	str r1, [r0]
	bl delay

	b led4_flash


delay:
	mov r2, #0x1000000
delay_loop:
	sub r2, r2,#1
	cmp r2, #0
	bne delay_loop
	mov pc, lr
