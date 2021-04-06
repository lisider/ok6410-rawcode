.text
.code 32

.global _start
_start:
	// 将 iRAM的最高位置设为SP
	ldr sp, =0x52000000
	bl main

loop:
	b loop

