RP2040
======
<https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf>

`git clone git://git.josuah.net/sdk-rp2040`

![rp2040](/image/rp2040.png)

Difficult to use from bare metal? (not that much)
-------------------------------------------------
While some might have mixed feelings about using the rp2040 bare-bones,
it is really not that bad.

Something like this is enough to get it to turn the Pico board's
led (GPIO 25) on: The usual reset handler calling main at the end,
and enabling the clocks for the peripheral you need, then writing
to the peripheral itself:

```
$ cat rp2040.c

#include <stdint.h>
#include "rp2040.h"

#define GPIO_LED 25

int
main(void)
{
	/* enable the GPIO and the PADs by taking them out of reset state */
	RESETS->RESET &= ~RESETS_RESET_IO_BANK0;
	RESETS->RESET &= ~RESETS_RESET_PADS_BANK0;

	/* enable output mode for the LED pin */
	SIO->GPIO_OE_SET = 1u << GPIO_LED;
	IO_BANK0->GPIO[GPIO_LED].CTRL = IO_BANK0_GPIO_CTRL_FUNCSEL_SIO;

	/* continuously turn the led on */
	for (;;)
		SIO->GPIO_OUT_SET = (1u << GPIO_LED);
	return 0;
}

void
__reset_handler(void)
{
	extern char __data_start, __data_end, __data_load_start;
	extern char __bss_start, __bss_end;

	volatile char *src, *dst;

	/* fill initialised and uninitialised variables */
	src = &__data_load_start;
	for (dst = &__data_start; dst < &__data_end; *dst++ = *src++);
	for (dst = &__bss_start; dst < &__bss_end; *dst++ = 0);

	main();
}

/*
 * Boot stage 2 bootloader: padded and checksummed version of
 * pico-sdk/src/rp2_common/boot_stage2/bs2_default.bin
 * It is placed at the top of the ROM by the linker script
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

char __stack_top;
void *__stack_pointer = &__stack_top;

void (*__vectors[])(void) = {
	&__reset_handler,
	/* other interrupts here... */
};
```

The big block might feel a bit like a proprietary blob. Thankfully
it is not: the source is easily available from the
[pico-sdk](https://github.com/raspberrypi/pico-sdk/) repo, and you
can compile it from source, and put the generated assembly onto a
bootloader.S, or like the above in an array of bytes.

Some registers definitions needed for that C file:

```
$ cat rp2040.h

#define RESETS ((struct sdk_resets *)0x4000C000)

struct sdk_resets {

	/* 0x00: Reset control. */
	uint32_t volatile RESET;
#define RESETS_RESET_PADS_BANK0					(1u << 8)
#define RESETS_RESET_IO_BANK0					(1u << 5)

	/* 0x04: Watchdog select. */
	uint32_t volatile WDSEL;

	/* 0x08: Reset done. */
	uint32_t volatile RESET_DONE;
#define RESETS_RESET_DONE_PADS_BANK0				(1u << 8)
#define RESETS_RESET_DONE_IO_BANK0				(1u << 5)

	/* ... */
};

#define IO_BANK0 ((struct sdk_io_bank0 *)0x40014000)

struct sdk_io_bank0 {

	struct sdk_io_bank0_gpio {

		/* 0x00: GPIO status */
		uint32_t volatile STATUS;

		/* 0x04: GPIO control including function select and overrides. */
		uint32_t volatile CTRL;
		/* selects pin function according to the gpio table */
#define IO_BANK0_GPIO_CTRL_FUNCSEL_SIO				(0x5u << 0)

	} GPIO[29];

	/* ... */
};

#define SIO ((struct sdk_sio *)0xD0000000)

struct sdk_sio {

	/* 0x00: Processor core identifier */
	uint32_t volatile CPUID;

	/* 0x04: Input value for GPIO pins */
	uint32_t volatile GPIO_IN;

	/* 0x08: Input value for QSPI pins */
	uint32_t volatile GPIO_HI_IN;

	/* 0x0C */
	uint8_t RESERVED0[0x10u-0x0Cu];

	/* 0x10: GPIO output value */
	uint32_t volatile GPIO_OUT;

	/* 0x14: GPIO output value set */
	uint32_t volatile GPIO_OUT_SET;

	/* 0x18: GPIO output value clear */
	uint32_t volatile GPIO_OUT_CLR;

	/* 0x1C: GPIO output value XOR */
	uint32_t volatile GPIO_OUT_XOR;

	/* 0x20: GPIO output enable */
	uint32_t volatile GPIO_OE;

	/* 0x24: GPIO output enable set */
	uint32_t volatile GPIO_OE_SET;

	/* 0x28: GPIO output enable clear */
	uint32_t volatile GPIO_OE_CLR;

	/* 0x2C: GPIO output enable XOR */
	uint32_t volatile GPIO_OE_XOR;

	/* ... */
};
```

And a regular, straightforward linker script:

```
$ cat rp2040.ld
MEMORY {
	ROM (rx) : ORIGIN = 0x10000000, LENGTH = 2048K
	RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 256K
}

ENTRY(__reset_handler)

SECTIONS {
	.text : {
		KEEP(*(.data.__bootloader))
		KEEP(*(.data.__stack_pointer))
		KEEP(*(.data.__vectors))
		. = ALIGN(4);
		*(.text .text.*)
		*(.rodata .rodata.*)
	} > ROM

	.data : {
		PROVIDE(__data_start = .);
		*(.data .data.*)
		PROVIDE(__data_end = .);
	} > RAM AT> ROM

	.bss ADDR(.data) + SIZEOF (.data) : AT (ADDR (.bss)) {
		PROVIDE(__bss_start = .);
		*(.bss)
		PROVIDE(__bss_end = .);
	} > RAM

	__data_load_start = LOADADDR(.data);
	__data_load_end = __data_load_start + SIZEOF(.data);
	__stack_top = ORIGIN(RAM) + LENGTH(RAM);
}
```

Then a Makefile to wrap it all together:

```
$ cat Makefile

all: rp2040.uf2

rp2040.elf: rp2040.o
	arm-none-eabi-ld -Map=rp2040.map --gc-sections -Trp2040.ld -nostdlib -static -o $@ rp2040.o

.SUFFIXES: .elf .uf2

clean:
	rm -f *.o *.elf *.uf2 *.map

.c.o:
	arm-none-eabi-gcc -mthumb -mcpu=cortex-m0plus -msoft-float -ffunction-sections -fdata-sections -c -o $@ $<

.elf.uf2:
	elf2uf2 $< $@
```

Trying "make" then copying the `rp2040.uf2` file generated did work.

Drag-and-Drop to flash: useless bloat?
--------------------------------------
What about that fancy UF2 bootloader that lets you drag-and-drop
binaries to flash the firmware? It comes for free: there is an USB
peripheral on the pico, and while pressing the "BOOTSEL" button at
startup, the RP2040 loads a firmware that make use of that USB
peripheral to expose a FAT drive device from this bootloader firmware.

So it sounds a bit of an overkill, it was not compromising to add it,
since it does not require anything special in hardware at all, only
a firmware that handles that complexity.

Would you like a different interface like SWD? That is also completely
possible through projects like https://github.com/majbthrd/pico-debug/
can help.

Lack of standard interfaces
---------------------------
After trying it out, the RP2040 has much fewer over-engineering
than it looks.

From my point of view I saw a single catch to that crazy set of
features: for $1: the lack of a standard interface for debugging:
CMSIS-DAP was replaced by a custom protocol.

While the recommanded way using one board to debug another
(the [picoprobe](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf) project),
this also means the standard ARM tools like ST-Link or J-Link
will not work, and a custom fork of OpenOCD not yet upstreamed
is the only way to access the debug interface of the RP2040 for
now.

Maybe there are reasons why they avoided the ARM way, I might
just have missed their article about that, but here we are now.

Not as convenient as STM32?
---------------------------
Besides this, it might have a few things made different, but it is
also not an STM32, as the STM32 are the best at being an STM32
already, and yet another "STM32 killer" would not be so useful.

Conclusion
----------
As soon as I managed to boot that RP2040 with this few code, I
started to consider that board seriously, as very little boilerplate
is required to make it start executing your code after all, even
if the pico-sdk is having a lot, it definitely is usable stand-alone
just like any other microcontroller.

Links
-----
* <https://hackaday.com/2021/01/20/raspberry-pi-enters-microcontroller-game-with-4-pico/>
* <https://hackaday.com/2021/05/19/raspberry-pi-rp2040-hands-on-experiences-from-an-stm32-perspective/>
* <https://www.eevblog.com/forum/microcontrollers/rp2040-baremetal-starter-project/>
