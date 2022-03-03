#include <stddef.h>
#include <stdint.h>

#define ROSC ((struct sdk_rosc *)0x40060000)

struct sdk_rosc {

	/* 0x00: Ring Oscillator control */
	uint32_t volatile CTRL;

	/* 0x04: Ring Oscillator frequency control  */
	uint32_t volatile FREQA;

	/* 0x08: Ring Oscillator frequency control  */
	uint32_t volatile FREQB;

	/* 0x0C: Ring Oscillator pause control */
	uint32_t volatile DORMANT;

	/* 0x10: Controls the output divider */
	uint32_t volatile DIV;

	/* 0x14: Controls the phase shifted output */
	uint32_t volatile PHASE;

	/* 0x18: Ring Oscillator Status */
	uint32_t volatile STATUS;

	/* 0x1C: Returns a 1 bit random value */
	uint32_t volatile RANDOMBIT;

	/* 0x20: A down counter running at the ROSC frequency which counts to zero and stops */
	uint32_t volatile COUNT;

};
