#include <stddef.h>
#include <stdint.h>

#define RESETS ((struct zmcu_resets *)0x4000C000)

struct zmcu_resets {

	/* 0x0: Reset control */
	uint32_t volatile RESET;

	/* 0x4: Watchdog select */
	uint32_t volatile WDSEL;

	/* 0x8: Reset done */
	uint32_t volatile RESET_DONE;

	/* peripheral to reset */
#define RESETS_MASK				0x01FFFFFFu
#define RESETS_USBCTRL				(1u << 24)
#define RESETS_UART1				(1u << 22)
#define RESETS_UART0				(1u << 22)
#define RESETS_TIMER				(1u << 21)
#define RESETS_TBMAN				(1u << 20)
#define RESETS_SYSINFO				(1u << 19)
#define RESETS_SYSCFG				(1u << 18)
#define RESETS_SPI1				(1u << 17)
#define RESETS_SPI0				(1u << 16)
#define RESETS_RTC				(1u << 15)
#define RESETS_PWM				(1u << 14)
#define RESETS_PLL_USB				(1u << 13)
#define RESETS_PLL_SYS				(1u << 12)
#define RESETS_PIO1				(1u << 11)
#define RESETS_PIO0				(1u << 10)
#define RESETS_PADS_QSPI			(1u << 9)
#define RESETS_PADS_BANK0			(1u << 8)
#define RESETS_JTAG				(1u << 7)
#define RESETS_IO_QSPI				(1u << 6)
#define RESETS_IO_BANK0				(1u << 5)
#define RESETS_I2C1				(1u << 4)
#define RESETS_I2C0				(1u << 3)
#define RESETS_DMA				(1u << 2)
#define RESETS_BUSCTRL				(1u << 1)
#define RESETS_ADC				(1u << 0)

};
