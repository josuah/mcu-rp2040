#include <stddef.h>
#include <stdint.h>

#define PSM ((struct zmcu_psm *)0x40010000)

struct zmcu_psm {

	/* 0x0: Force block out of reset (i.e. power it on) */
	uint32_t volatile FRCE_ON;

	/* 0x4: Force into reset (i.e. power it off) */
	uint32_t volatile FRCE_OFF;

	/* 0x8: Set to 1 if this peripheral should be reset when the watchdog fires */
	uint32_t volatile WDSEL;

	/* 0xC: Indicates the peripheral’s registers are ready to access */
	uint32_t volatile DONE;

};
