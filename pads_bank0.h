#include <stddef.h>
#include <stdint.h>

#define PADS_BANK0 ((struct zmcu_pads_bank0 *)0x4001C000)

struct zmcu_pads_bank0 {

	/* 0x00: Voltage select. Per bank control */
	uint32_t volatile VOLTAGE_SELECT;

	/* 0x04: Pad control register */
	uint32_t volatile GPIO[30];

	/* 0x7C: Pad control register */
	uint32_t volatile SWCLK;

	/* 0x80: Pad control register */
	uint32_t volatile SWD;

};
