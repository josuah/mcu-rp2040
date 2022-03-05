#include "libc.h"
#include "registers.h"
#include "functions.h"

#define GPIO_LED 25

int
main(void)
{
	IO_BANK0->GPIO25_CTRL = BITS(IO_BANK0_GPIO25_CTRL_FUNCSEL, IO_BANK0_GPIO25_CTRL_FUNCSEL_SIO_25);
	SIO->GPIO_OE = 1 << GPIO_LED;

	for (;;)
		SIO->GPIO_OUT_SET = 1 << GPIO_LED;
}
