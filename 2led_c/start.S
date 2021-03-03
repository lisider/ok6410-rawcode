.text
.code 32

.global _start
_start:
	// 将 iRAM的最高位置设为SP
	ldr sp, =0x0c002000
	bl led_sample

loop:
	b loop

