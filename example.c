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

	for (;;)
		if (spi_write_completed(SPI0))
			spi_queue_write(SPI0, (uint8_t *)"0000000000", 10);
}

extern void
spi_handle_byte(struct mcu_spi *spi, uint8_t byte)
{
        gpio_set_pin(25);
        gpio_clear_pin(25);
}
