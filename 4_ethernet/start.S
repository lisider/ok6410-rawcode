.text
.code 32

.global _start
_start:
	// 将 iRAM的最高位置设为SP
	ldr sp, =0x0c002000

	// 时钟设置是为 uart 工作的前提
	bl clock_init
	bl uart_init
	bl main

loop:
	b loop

