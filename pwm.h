#include <stddef.h>
#include <stdint.h>

#define PWM ((struct sdk_pwm *)0x40050000)

struct sdk_pwm {

	struct {

		/* 0x00: Control and status register */
		uint32_t volatile CSR;

		/* 0x04: INT and FRAC form a fixed-point fractional number */
		uint32_t volatile DIV;

		/* 0x08: Direct access to the PWM counter */
		uint32_t volatile CTR;

		/* 0x0C: Counter compare values */
		uint32_t volatile CC;

		/* 0x10: Counter wrap value */
		uint32_t volatile TOP;

	} CH[8];

	/* 0xA0: This register aliases the CSR_EN bits for all channels */
	uint32_t volatile EN;

	/* 0xA4: Raw Interrupts */
	uint32_t volatile INTR;

	/* 0xA8: Interrupt Enable */
	uint32_t volatile INTE;

	/* 0xAC: Interrupt Force */
	uint32_t volatile INTF;

	/* 0xB0: Interrupt status after masking & forcing */
	uint32_t volatile INTS;

};
