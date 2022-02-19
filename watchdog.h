#include <stddef.h>
#include <stdint.h>

#define WATCHDOG ((struct zmcu_watchdog *)0x40058000)

struct zmcu_watchdog {

	/* 0x00: Watchdog control */
	uint32_t volatile CTRL;

	/* 0x04: Load the watchdog timer */
	uint32_t volatile LOAD;

	/* 0x08: Logs the reason for the last reset */
	uint32_t volatile REASON;

	/* 0x0C: Scratch register */
	uint32_t volatile SCRATCH[8];

	/* 0x2C: Controls the tick generator */
	uint32_t volatile TICK;

};
