#include "libc.h"
#include "registers.h"
#include "functions.h"

void
uart_init(struct sdk_uart *uart, uint8_t pin_rx, uint8_t pin_tx)
{
	RESETS->RESET &= ~RESETS_RESET_IO_BANK0; // TODO: realy needed?
	RESETS->RESET &= ~RESETS_RESET_PADS_BANK0; // TODO: really needed?
	while ((RESETS->RESET_DONE & RESETS_RESET_DONE_IO_BANK0) == 0);
	while ((RESETS->RESET_DONE & RESETS_RESET_DONE_PADS_BANK0) == 0);

	if (uart == UART0) {
		RESETS->RESET &= ~RESETS_RESET_UART0;
		while ((RESETS->RESET_DONE & RESETS_RESET_DONE_UART0) == 0);
		
	}
	if (uart == UART1) {
		RESETS->RESET &= ~RESETS_RESET_UART1;
		while ((RESETS->RESET_DONE & RESETS_RESET_DONE_UART1) == 0);
	}

	IO_BANK0->GPIO[pin_rx].CTRL = IO_BANK0_GPIO_CTRL_FUNCSEL_UART;
	IO_BANK0->GPIO[pin_tx].CTRL = IO_BANK0_GPIO_CTRL_FUNCSEL_UART;

	;
}
