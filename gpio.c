#include "libc.h"
#include "registers.h"
#include "functions.h"

void
gpio_init(void)
{
	RESETS->RESET &= ~RESETS_RESET_IO_BANK0;
	RESETS->RESET &= ~RESETS_RESET_PADS_BANK0;
	while ((RESETS->RESET_DONE & RESETS_RESET_DONE_IO_BANK0) == 0);
	while ((RESETS->RESET_DONE & RESETS_RESET_DONE_PADS_BANK0) == 0);
}

void
gpio_set_mode_output(uint8_t pin)
{
	SIO->GPIO_OE_SET = 1u << pin;
	IO_BANK0->GPIO[pin].CTRL = IO_BANK0_GPIO_CTRL_FUNCSEL_SIO;
}

void
gpio_set_pin_up(uint8_t pin)
{
	SIO->GPIO_OUT_SET = (1u << pin);
}
