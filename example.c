#include "libc.h"
#include "registers.h"
#include "functions.h"

#define LED 25

int
main(void)
{
	gpio_init();

	gpio_set_mode_output(LED);
	for (;;)
		gpio_set_pin_up(LED);
		
}
