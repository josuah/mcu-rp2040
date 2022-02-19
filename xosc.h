#include <stddef.h>
#include <stdint.h>

#define XOSC ((struct zmcu_xosc *)0x40024000)

struct zmcu_xosc {

	/* 0x00: Crystal Oscillator Control */
	uint32_t volatile CTRL;

	/* 0x04: Crystal Oscillator Status */
	uint32_t volatile STATUS;

	/* 0x08: Crystal Oscillator pause control */
	uint32_t volatile DORMANT;

	/* 0x0C: Controls the startup delay */
	uint32_t volatile STARTUP;

	/* 0x1C: A down counter running at the XOSC frequency which counts to zero and stops */
	uint32_t volatile COUNT;

};

#define XOSC_MHZ			12
