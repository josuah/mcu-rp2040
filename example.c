#include "libc.h"
#include "librp2040.h"

/* Send requests to a Wishbone B4 bus as master through SPI */

#define LED		25

void
alert(void)
{
	static uint16_t i = 0;

	if (i++ < UINT16_MAX / 2)
		gpio_set_pin(LED);
	else
		gpio_clear_pin(LED);
}

int
main(void)
{
	gpio_init();
	gpio_set_mode_output(LED);
	gpio_set_pin(LED);
	return 0;
}
