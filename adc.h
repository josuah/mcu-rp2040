#include <stddef.h>
#include <stdint.h>

#define ADC ((struct sdk_adc *)0x4004C000)

struct sdk_adc {

	/* 0x00: ADC Control and Status */
	uint32_t volatile CS;

	/* 0x04: Result of most recent ADC conversion */
	uint32_t volatile RESULT;

	/* 0x08: FIFO control and status */
	uint32_t volatile FCS;

	/* 0x0C: Conversion result FIFO */
	uint32_t volatile FIFO;

	/* 0x10: Clock divider */
	uint32_t volatile DIV;

	/* 0x14: Raw Interrupts */
	uint32_t volatile INTR;

	/* 0x18: Interrupt Enable */
	uint32_t volatile INTE;

	/* 0x1C: Interrupt Force */
	uint32_t volatile INTF;

	/* 0x20: Interrupt status after masking & forcing */
	uint32_t volatile INTS;

};
