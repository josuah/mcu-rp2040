#include <stddef.h>
#include <stdint.h>

#define CLOCKS ((struct zmcu_clocks *)0x40008000)

struct zmcu_clocks {

	/* 0x00: Clock control, divisor, selector */
	uint32_t volatile CLK_GPOUT0_CTRL;
	uint32_t volatile CLK_GPOUT0_DIV;
	uint32_t volatile CLK_GPOUT0_SELECTED;

	/* 0x0C: clock control, divisor, selector */
	uint32_t volatile CLK_GPOUT1_CTRL;
	uint32_t volatile CLK_GPOUT1_DIV;
	uint32_t volatile CLK_GPOUT1_SELECTED;

	/* 0x18: Clock control, divisor, selector */
	uint32_t volatile CLK_GPOUT2_CTRL;
	uint32_t volatile CLK_GPOUT2_DIV;
	uint32_t volatile CLK_GPOUT2_SELECTED;

	/* 0x24: Clock control, divisor, selector */
	uint32_t volatile CLK_GPOUT3_CTRL;
	uint32_t volatile CLK_GPOUT3_DIV;
	uint32_t volatile CLK_GPOUT3_SELECTED;

	/* 0x30: Clock control, divisor, selector */
	uint32_t volatile CLK_REF_CTRL;
	uint32_t volatile CLK_REF_DIV;
	uint32_t volatile CLK_REF_SELECTED;

	/* 0x3C: Clock control, divisor, selector */
	uint32_t volatile CLK_SYS_CTRL;
	uint32_t volatile CLK_SYS_DIV;
	uint32_t volatile CLK_SYS_SELECTED;

	/* 0x48: Clock control, selector */
	uint32_t volatile CLK_PERI_CTRL;
	uint32_t volatile CLK_PERI_SELECTED;

	/* 0x54: Clock control, divisor, selector */
	uint32_t volatile CLK_USB_CTRL;
	uint32_t volatile CLK_USB_DIV;
	uint32_t volatile CLK_USB_SELECTED;

	/* 0x60: Clock control, divisor, selector */
	uint32_t volatile CLK_ADC_CTRL;
	uint32_t volatile CLK_ADC_DIV;
	uint32_t volatile CLK_ADC_SELECTED;

	/* 0x6C: Clock control, divisor, selector */
	uint32_t volatile CLK_RTC_CTRL;
	uint32_t volatile CLK_RTC_DIV;
	uint32_t volatile CLK_RTC_SELECTED;

	/* 0x78: system clock control and status */
	uint32_t volatile CLK_SYS_RESUS_CTRL;
	uint32_t volatile CLK_SYS_RESUS_STATUS;

#define CLOCKS_CLK_CTRL_NUDGE			(1u << 20)
#define CLOCKS_CLK_CTRL_PHASE(x)		((x) << 16)
#define CLOCKS_CLK_CTRL_ENABLE			(1u << 11)
#define CLOCKS_CLK_CTRL_KILL			(1u << 10)
#define CLOCKS_CLK_CTRL_AUXSRC(x)		((x) << 5)

	/* 0x80: Reference clock, minimum, maximum frequency in kHz and status */
	uint32_t volatile FC0_REF_KHZ;
	uint32_t volatile FC0_MIN_KHZ;
	uint32_t volatile FC0_MAX_KHZ;
	uint32_t volatile FC0_DELAY;
	uint32_t volatile FC0_INTERVAL;
	uint32_t volatile FC0_SRC;
	uint32_t volatile FC0_STATUS;
	uint32_t volatile FC0_RESULT;

	/* 0xA0: enable clock in wake mode */
	uint32_t volatile WAKE_EN[2];

	/* 0xA8: enable clock in sleep mode */
	uint32_t volatile SLEEP_EN[2];

	/* 0xB0: indicates the state of the clock enable */
	uint32_t volatile ENABLED[2];

	/* 0xB8: Raw Interrupt */
	uint32_t volatile INTR;

	/* 0xBC: Interrupt Enable */
	uint32_t volatile INTE;

	/* 0xC0: Interrupt Force */
	uint32_t volatile INTF;

	/* 0xC4: Interrupt status after masking & forcing */
	uint32_t volatile INTS;

};
