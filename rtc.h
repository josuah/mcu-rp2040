#include <stddef.h>
#include <stdint.h>

#define RTC ((struct zmcu_rtc *)0x4005C000)

struct zmcu_rtc {

	/* 0x00: Divider minus 1 for the 1 second counter */
	uint32_t volatile CLKDIV_M1;

	/* 0x04: RTC setup register 0 */
	uint32_t volatile SETUP_0;

	/* 0x08: RTC setup register 1 */
	uint32_t volatile SETUP_1;

	/* 0x0C: RTC Control and status */
	uint32_t volatile CTRL;

	/* 0x10: Interrupt setup register 0 */
	uint32_t volatile IRQ_SETUP_0;

	/* 0x14: Interrupt setup register 1 */
	uint32_t volatile IRQ_SETUP_1;

	/* 0x18: RTC register 1 */
	uint32_t volatile RTC_1;

	/* 0x1C: RTC register 0 */
	uint32_t volatile RTC_0;

	/* 0x20: Raw Interrupts */
	uint32_t volatile INTR;

	/* 0x24: Interrupt Enable */
	uint32_t volatile INTE;

	/* 0x28: Interrupt Force */
	uint32_t volatile INTF;

	/* 0x2C: Interrupt status after masking & forcing */
	uint32_t volatile INTS;

};
