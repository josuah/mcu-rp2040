#include "libc.h"
#include "registers.h"
#include "functions.h"

extern int main(void);
extern char __data_start, __data_end, __data_load_start;
extern char __bss_start, __bss_end, __stack_top;

void
__reset_handler(void)
{
	volatile char *dst, *src = &__data_load_start;

	for (dst = &__data_start; dst < &__data_end; *dst++ = *src++);
	for (dst = &__bss_start; dst < &__bss_end; *dst++ = 0);
	main();
	for (int volatile i = 0 ;; i++);
}

/* so that the debugger can immediately see which fault was triggered */
void __null_handler(void)		{ for (int volatile i = 0;; i++); }
void __isr_hard_fault(void)		{ for (int volatile i = 0;; i++); }
void __isr_memory_management(void)	{ for (int volatile i = 0;; i++); }
void __isr_non_maskable_interrupt(void)	{ for (int volatile i = 0;; i++); }
void __isr_bus_fault(void)		{ for (int volatile i = 0;; i++); }
void __isr_usage_fault(void)		{ for (int volatile i = 0;; i++); }
void __isr_secure_fault(void)		{ for (int volatile i = 0;; i++); }

/*
 * boot stage 2 bootloader: padded and checksummed version of
 * pico-sdk/src/rp2_common/boot_stage2/bs2_default.bin
 */
char __bootloader[] =			/* 0x00 with other addresses shifted */
	"\x00\xB5\x32\x4B\x21\x20\x58\x60\x98\x68\x02\x21\x88\x43\x98\x60"
	"\xD8\x60\x18\x61\x58\x61\x2E\x4B\x00\x21\x99\x60\x02\x21\x59\x61"
	"\x01\x21\xF0\x22\x99\x50\x2B\x49\x19\x60\x01\x21\x99\x60\x35\x20"
	"\x00\xF0\x44\xF8\x02\x22\x90\x42\x14\xD0\x06\x21\x19\x66\x00\xF0"
	"\x34\xF8\x19\x6E\x01\x21\x19\x66\x00\x20\x18\x66\x1A\x66\x00\xF0"
	"\x2C\xF8\x19\x6E\x19\x6E\x19\x6E\x05\x20\x00\xF0\x2F\xF8\x01\x21"
	"\x08\x42\xF9\xD1\x00\x21\x99\x60\x1B\x49\x19\x60\x00\x21\x59\x60"
	"\x1A\x49\x1B\x48\x01\x60\x01\x21\x99\x60\xEB\x21\x19\x66\xA0\x21"
	"\x19\x66\x00\xF0\x12\xF8\x00\x21\x99\x60\x16\x49\x14\x48\x01\x60"
	"\x01\x21\x99\x60\x01\xBC\x00\x28\x00\xD0\x00\x47\x12\x48\x13\x49"
	"\x08\x60\x03\xC8\x80\xF3\x08\x88\x08\x47\x03\xB5\x99\x6A\x04\x20"
	"\x01\x42\xFB\xD0\x01\x20\x01\x42\xF8\xD1\x03\xBD\x02\xB5\x18\x66"
	"\x18\x66\xFF\xF7\xF2\xFF\x18\x6E\x18\x6E\x02\xBD\x00\x00\x02\x40"
	"\x00\x00\x00\x18\x00\x00\x07\x00\x00\x03\x5F\x00\x21\x22\x00\x00"
	"\xF4\x00\x00\x18\x22\x20\x00\xA0\x00\x01\x00\x10\x08\xED\x00\xE0"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x74\xB2\x4E\x7A";

void *__stack_pointer = &__stack_top;	/* 0x00 */

void (*__vectors[])(void) = {
	&__reset_handler,		/* 0x04 -15 ARM Reset */
	&__isr_non_maskable_interrupt,	/* 0x08 -14 ARM NonMaskableInt */
	&__isr_hard_fault,		/* 0x0C -13 ARM HardFault */
	&__isr_memory_management,	/* 0x10 -12 ARM MemoryManagement */
	&__isr_bus_fault,		/* 0x14 -11 ARM BusFault */
	&__isr_usage_fault,		/* 0x18 -10 ARM UsageFault */
	&__isr_secure_fault,		/* 0x1C -9 ARM SecureFault */
	&__null_handler,		/* 0x20 -8 Reserved */
	&__null_handler,		/* 0x24 -7 Reserved */
	&__null_handler,		/* 0x28 -6 Reserved */
	&__null_handler,		/* 0x2C -5 ARM SVCall */
	&__null_handler,		/* 0x30 -4 ARM DebugMonitor */
	&__null_handler,		/* 0x34 -3 Reserved */
	&__null_handler,		/* 0x38 -2 ARM PendSV */
	&__null_handler,		/* 0x3C -1 ARM SysTick */
	&__null_handler,		/* 0x40 #0 TIMER_IRQ_0 */
	&__null_handler,		/* 0x44 #1 TIMER_IRQ_1 */
	&__null_handler,		/* 0x48 #2 TIMER_IRQ_2 */
	&__null_handler,		/* 0x4C #3 TIMER_IRQ_3 */
	&__null_handler,		/* 0x50 #4 PWM_IRQ_WRAP */
	&__null_handler,		/* 0x54 #5 USBCTRL_IRQ */
	&__null_handler,		/* 0x58 #6 XIP_IRQ */
	&__null_handler,		/* 0x5C #7 PIO0_IRQ_0 */
	&__null_handler,		/* 0x60 #8 PIO0_IRQ_1 */
	&__null_handler,		/* 0x64 #9 PIO1_IRQ_0 */
	&__null_handler,		/* 0x68 #10 PIO1_IRQ_1 */
	&__null_handler,		/* 0x6C #11 DMA_IRQ_0 */
	&__null_handler,		/* 0x70 #12 DMA_IRQ_1 */
	&__null_handler,		/* 0x74 #13 IO_IRQ_BANK0 */
	&__null_handler,		/* 0x78 #14 IO_IRQ_QSPI */
	&__null_handler,		/* 0x7C #15 SIO_IRQ_PROC0 */
	&__null_handler,		/* 0x80 #16 SIO_IRQ_PROC1 */
	&__null_handler,		/* 0x84 #17 CLOCKS_IRQ */
	&__null_handler,		/* 0x88 #18 SPI0_IRQ */
	&__null_handler,		/* 0x8C #19 SPI1_IRQ */
	&__null_handler,		/* 0x90 #20 UART0_IRQ */
	&__null_handler,		/* 0x94 #21 UART1_IRQ */
	&__null_handler,		/* 0x98 #22 ADC_IRQ_FIFO */
	&__null_handler,		/* 0x9C #23 I2C0_IRQ */
	&__null_handler,		/* 0xA0 #24 I2C1_IRQ */
	&__null_handler,		/* 0xA4 #25 RTC_IRQ */
};
