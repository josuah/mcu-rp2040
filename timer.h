#include <stddef.h>
#include <stdint.h>

#define TIMER ((struct zmcu_timer *)0x40054000)

struct zmcu_timer {

	/* 0x00: Write to bits 63:32 of time */
	uint32_t volatile TIMEHW;

	/* 0x04: Write to bits 31:0 of time */
	uint32_t volatile TIMELW;

	/* 0x08: Read from bits 63:32 of time always read timelr before timehr */
	uint32_t volatile TIMEHR;

	/* 0x0C: Read from bits 31:0 of time */
	uint32_t volatile TIMELR;

	/* 0x10: Arm alarm, and configure the time it will fire */
	uint32_t volatile ALARM[4];

	/* 0x20: Indicates the armed/disarmed status of each alarm */
	uint32_t volatile ARMED;

	/* 0x24: Raw read from bits 63:32 of time (no side effects) */
	uint32_t volatile TIMERAWH;

	/* 0x28: Raw read from bits 31:0 of time (no side effects) */
	uint32_t volatile TIMERAWL;

	/* 0x2C: Set bits high to enable pause when the corresponding debug ports are active */
	uint32_t volatile DBGPAUSE;

	/* 0x30: Set high to pause the timer */
	uint32_t volatile PAUSE;

	/* 0x34: Raw Interrupts */
	uint32_t volatile INTR;

	/* 0x38: Interrupt Enable */
	uint32_t volatile INTE;

	/* 0x3C: Interrupt Force */
	uint32_t volatile INTF;

	/* 0x40: Interrupt status after masking & forcingi */
	uint32_t volatile INTS;

};
