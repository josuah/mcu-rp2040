#include <stddef.h>
#include <stdint.h>

#define SYSCFG ((struct zmcu_syscfg *)0x40004000)

struct zmcu_syscfg {

	/* 0x00: Processor core 0 NMI source mask */
	uint32_t volatile PROC0_NMI_MASK;

	/* 0x04: Processor core 1 NMI source mask */
	uint32_t volatile PROC1_NMI_MASK;

	/* 0x08: Configuration for processors */
	uint32_t volatile PROC_CONFIG;

	/* 0x0C: bypass the input synchronizer between that GPIO and the GPIO input register in the SIO */
	uint32_t volatile PROC_IN_SYNC_BYPASS;

	/* 0x10: bypass the input synchronizer between that GPIO and the GPIO input register in the SIO */
	uint32_t volatile PROC_IN_SYNC_BYPASS_HI;

	/* 0x14: Directly control the SWD debug port of either processor */
	uint32_t volatile DBGFORCE;

	/* 0x18: Control power downs to memories */
	uint32_t volatile MEMPOWERDOWN;

};
