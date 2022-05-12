#include "libc.h"
#include "registers.h"
#include "functions.h"

void
spi_init(struct mcu_spi *spi, uint32_t baud_rate_hz)
{
	/* assume an incoming SSPCLK clock derived from CLK_SYS at 125MHz */
	spi->SSPCR0 = 0
	/* set clock polarity to positive edge */
	 | SPI_SSPCR0_SPO
	/* set spi mode */
	 | SPI_SSPCR0_FRF_MOTOROLA
	/* set data size to 8-bit byte */
	 | (8 - 1) << SPI_SSPCR0_DSS_Pos;

	/* the result of the division is expected to be >1 */
	spi->SSPCPSR = CLK_SYS_HZ / baud_rate_hz;

	/* enable the SPI module *after* (#4.4.4) it was configured */
	spi->SSPCR1 = SPI_SSPCR1_SSE;
}
