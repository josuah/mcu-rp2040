#include "resets.h"
#include "pll.h"
#include "clocks.h"
#include "xosc.h"
#include "main.h"

extern int main(void);
extern void __reset_handler(void);

extern char __data_start, __data_end, __data_load_start;
extern char __bss_start, __bss_end, __stack_top;

/*
 * boot stage 2 bootloader: padded and checksummed version of
 * pico-sdk/src/rp2_common/boot_stage2/bs2_default.bin
 */
char __bootloader[] = {
	0x00, 0xb5, 0x32, 0x4b, 0x21, 0x20, 0x58, 0x60, 0x98, 0x68, 0x02, 0x21,
	0x88, 0x43, 0x98, 0x60, 0xd8, 0x60, 0x18, 0x61, 0x58, 0x61, 0x2e, 0x4b,
	0x00, 0x21, 0x99, 0x60, 0x02, 0x21, 0x59, 0x61, 0x01, 0x21, 0xf0, 0x22,
	0x99, 0x50, 0x2b, 0x49, 0x19, 0x60, 0x01, 0x21, 0x99, 0x60, 0x35, 0x20,
	0x00, 0xf0, 0x44, 0xf8, 0x02, 0x22, 0x90, 0x42, 0x14, 0xd0, 0x06, 0x21,
	0x19, 0x66, 0x00, 0xf0, 0x34, 0xf8, 0x19, 0x6e, 0x01, 0x21, 0x19, 0x66,
	0x00, 0x20, 0x18, 0x66, 0x1a, 0x66, 0x00, 0xf0, 0x2c, 0xf8, 0x19, 0x6e,
	0x19, 0x6e, 0x19, 0x6e, 0x05, 0x20, 0x00, 0xf0, 0x2f, 0xf8, 0x01, 0x21,
	0x08, 0x42, 0xf9, 0xd1, 0x00, 0x21, 0x99, 0x60, 0x1b, 0x49, 0x19, 0x60,
	0x00, 0x21, 0x59, 0x60, 0x1a, 0x49, 0x1b, 0x48, 0x01, 0x60, 0x01, 0x21,
	0x99, 0x60, 0xeb, 0x21, 0x19, 0x66, 0xa0, 0x21, 0x19, 0x66, 0x00, 0xf0,
	0x12, 0xf8, 0x00, 0x21, 0x99, 0x60, 0x16, 0x49, 0x14, 0x48, 0x01, 0x60,
	0x01, 0x21, 0x99, 0x60, 0x01, 0xbc, 0x00, 0x28, 0x00, 0xd0, 0x00, 0x47,
	0x12, 0x48, 0x13, 0x49, 0x08, 0x60, 0x03, 0xc8, 0x80, 0xf3, 0x08, 0x88,
	0x08, 0x47, 0x03, 0xb5, 0x99, 0x6a, 0x04, 0x20, 0x01, 0x42, 0xfb, 0xd0,
	0x01, 0x20, 0x01, 0x42, 0xf8, 0xd1, 0x03, 0xbd, 0x02, 0xb5, 0x18, 0x66,
	0x18, 0x66, 0xff, 0xf7, 0xf2, 0xff, 0x18, 0x6e, 0x18, 0x6e, 0x02, 0xbd,
	0x00, 0x00, 0x02, 0x40, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x07, 0x00,
	0x00, 0x03, 0x5f, 0x00, 0x21, 0x22, 0x00, 0x00, 0xf4, 0x00, 0x00, 0x18,
	0x22, 0x20, 0x00, 0xa0, 0x00, 0x01, 0x00, 0x10, 0x08, 0xed, 0x00, 0xe0,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x74, 0xb2, 0x4e, 0x7a,
};

void *__stack_pointer = &__stack_top;	/* 0x00 */

void (*__vectors[])(void) = {
	&__reset_handler,		/* 0x04 -15 ARM Reset */
	&__stop_program,		/* 0x08 -14 ARM NonMaskableInt */
	&__stop_program,		/* 0x0C -13 ARM HardFault */
	&__stop_program,		/* 0x10 -12 ARM MemoryManagement */
	&__stop_program,		/* 0x14 -11 ARM BusFault */
	&__stop_program,		/* 0x18 -10 ARM UsageFault */
	&__stop_program,		/* 0x1C -9 ARM SecureFault */
	&__stop_program,		/* 0x20 -8 Reserved */
	&__stop_program,		/* 0x24 -7 Reserved */
	&__stop_program,		/* 0x28 -6 Reserved */
	&__stop_program,		/* 0x2C -5 ARM SVCall */
	&__stop_program,		/* 0x30 -4 ARM DebugMonitor */
	&__stop_program,		/* 0x34 -2 ARM PendSV */
	&__stop_program,		/* 0x38 -1 ARM SysTick */
	&__stop_program,		/* 0x3C #0 TIMER_IRQ_0 */
	&__stop_program,		/* 0x40 #1 TIMER_IRQ_1 */
	&__stop_program,		/* 0x44 #2 TIMER_IRQ_2 */
	&__stop_program,		/* 0x48 #3 TIMER_IRQ_3 */
	&__stop_program,		/* 0x4C #4 PWM_IRQ_WRAP */
	&__stop_program,		/* 0x50 #5 USBCTRL_IRQ */
	&__stop_program,		/* 0x54 #6 XIP_IRQ */
	&__stop_program,		/* 0x58 #7 PIO0_IRQ_0 */
	&__stop_program,		/* 0x5C #8 PIO0_IRQ_1 */
	&__stop_program,		/* 0x60 #9 PIO1_IRQ_0 */
	&__stop_program,		/* 0x64 #10 PIO1_IRQ_1 */
	&__stop_program,		/* 0x68 #11 DMA_IRQ_0 */
	&__stop_program,		/* 0x6C #12 DMA_IRQ_1 */
	&__stop_program,		/* 0x70 #13 IO_IRQ_BANK0 */
	&__stop_program,		/* 0x74 #14 IO_IRQ_QSPI */
	&__stop_program,		/* 0x78 #15 SIO_IRQ_PROC0 */
	&__stop_program,		/* 0x7C #16 SIO_IRQ_PROC1 */
	&__stop_program,		/* 0x80 #17 CLOCKS_IRQ */
	&__stop_program,		/* 0x84 #18 SPI0_IRQ */
	&__stop_program,		/* 0x88 #19 SPI1_IRQ */
	&__stop_program,		/* 0x8C #20 UART0_IRQ */
	&__stop_program,		/* 0x90 #21 UART1_IRQ */
	&__stop_program,		/* 0x94 #22 ADC_IRQ_FIFO */
	&__stop_program,		/* 0x98 #23 I2C0_IRQ */
	&__stop_program,		/* 0x9C #24 I2C1_IRQ */
	&__stop_program,		/* 0xA0 #25 RTC_IRQ */
};

void
__reset_handler(void)
{
	volatile char *src, *dst;

	/* fill initialised and uninitialised variables */
	src = &__data_load_start;
	for (dst = &__data_start; dst < &__data_end; *dst++ = *src++);
	for (dst = &__bss_start; dst < &__bss_end; *dst++ = 0);

	/* configure the PLL to the SDK's default */
	RESETS->RESET |= RESETS_PLL_USB;
	RESETS->RESET &= ~RESETS_PLL_USB;
	PLL_USB->CS = 1;
	PLL_USB->FBDIV_INT = 400 / XOSC_MHZ;
	PLL_USB->PWR &= ~(PLL_PWR_PD | PLL_PWR_VCOPD);
	while (!(PLL_USB->CS & PLL_CS_LOCK));
	PLL_USB->PRIM = PLL_PRIM_POSTDIV1(6) | PLL_PRIM_POSTDIV2(2);
	PLL_USB->PWR &= ~PLL_PWR_POSTDIVPD(1);

	/* configure `usb`, `adc` and `peri` clocks */
	CLOCKS->CLK_USB_CTRL |= CLOCKS_CLK_CTRL_ENABLE;
	CLOCKS->CLK_ADC_CTRL |= CLOCKS_CLK_CTRL_ENABLE;
	CLOCKS->CLK_PERI_CTRL |= CLOCKS_CLK_CTRL_ENABLE;
	RESETS->RESET &= ~RESETS_MASK;
	while (~RESETS->RESET_DONE & RESETS_MASK);

	main();
	__stop_program();
}

void
__stop_program(void)
{
	for (int volatile i = 0 ;; i++);
}
