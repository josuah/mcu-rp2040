#include "libc.h"
#include "registers.h"
#include "functions.h"

#define GPIO_LED 25

int
main(void)
{
	RESETS->RESET &= ~RESETS_RESET_IO_BANK0;
	RESETS->RESET &= ~RESETS_RESET_PADS_BANK0;

	SIO->GPIO_OE_SET = 1 << 25;
	IO_BANK0->GPIO25_CTRL = IO_BANK0_GPIO25_CTRL_FUNCSEL_SIO_25;

	for (;;)
		SIO->GPIO_OUT_SET = 1 << 25;
}
