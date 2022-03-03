#include <sio.h>
#include <io_bank.h>

#define GPIO_LED 25

int
main(void)
{
	IO_BANK0->GPIO[GPIO_LED].CTRL = IO_BANK_GPIO_CTRL_FUNCSEL(5);
	SIO->GPIO_OE = 1 << GPIO_LED;

	for (;;)
		SIO->GPIO_OUT_SET = 1 << GPIO_LED;
}
