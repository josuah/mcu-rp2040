#include "libc.h"
#include "registers.h"
#include "functions.h"

#define LED		25

#define SPI_RX		16
#define SPI_CSN		17
#define SPI_SCK		18
#define SPI_TX		19

int
main(void)
{
	gpio_init();
	gpio_set_mode_output(LED);

	spi_init(SPI0, 1000000, SPI_SCK, SPI_CSN, SPI_RX, SPI_TX);
//	gpio_set_pin_high(LED);

	for (;;)
		SPI0->SSPDR = 0xB0;
}
