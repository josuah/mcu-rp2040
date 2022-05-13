#include "libc.h"
#include "registers.h"
#include "functions.h"

void
spi_init(struct mcu_spi *spi, uint32_t baud_rate_hz,
	uint8_t pin_sck, uint8_t pin_csn, uint8_t pin_rx, uint8_t pin_tx)
{
	/* take the ports out of reset */
	RESETS->RESET &= ~RESETS_RESET_IO_BANK0; // TODO: realy needed?
	RESETS->RESET &= ~RESETS_RESET_PADS_BANK0; // TODO: really needed?
	while (~RESETS->RESET_DONE & RESETS_RESET_DONE_IO_BANK0);
	while (~RESETS->RESET_DONE & RESETS_RESET_DONE_PADS_BANK0);

	/* setup the ports function multiplexing */
	IO_BANK0->GPIO[pin_sck].CTRL = IO_BANK0_GPIO_CTRL_FUNCSEL_SPI;
	IO_BANK0->GPIO[pin_csn].CTRL = IO_BANK0_GPIO_CTRL_FUNCSEL_SPI;
	IO_BANK0->GPIO[pin_rx].CTRL = IO_BANK0_GPIO_CTRL_FUNCSEL_SPI;
	IO_BANK0->GPIO[pin_tx].CTRL = IO_BANK0_GPIO_CTRL_FUNCSEL_SPI;

	/* set the direction of pins to input or output */
	SIO->GPIO_OE_SET = 1u << pin_sck | 1u << pin_csn | 1u << pin_tx;
	SIO->GPIO_OE_CLR = 1u << pin_rx;

	/* enable the peripheral clock, used by the TX/RX logic */
	CLOCKS->CLK[CLK_PERI].CTRL = CLOCKS_CLK_PERI_CTRL_ENABLE;

	/* take the SPI peripheral out of reset */
	if (spi == SPI0) {
		RESETS->RESET &= ~RESETS_RESET_SPI0;
		while (~RESETS->RESET_DONE & RESETS_RESET_DONE_SPI0);
	} else if (spi == SPI1) {
		RESETS->RESET &= ~RESETS_RESET_SPI1;
		while (~RESETS->RESET_DONE & RESETS_RESET_DONE_SPI0);
	} else {
		assert(!"not reached");
	}

	/* assume an incoming SSPCLK clock derived from CLK_PERI at 125MHz */
	spi->SSPCR0 = 0
	/* set SPI mode */
	 | SPI_SSPCR0_FRF_MOTOROLA
	/* set the number of bits per frames */
	 | (8 - 1) << SPI_SSPCR0_DSS_Pos;

	/* enable all interrupts */
	spi->SSPIMSC = SPI_SSPIMSC_TXIM | SPI_SSPIMSC_RXIM
	 | SPI_SSPIMSC_RTIM | SPI_SSPIMSC_RORIM;

	/* the result of the division is expected to be >1 */
	spi->SSPCPSR = 125; // CLK_PERI_HZ /  baud_rate_hz;

	/* enable the SPI module *after* (#4.4.4) it was configured */
	spi->SSPCR1 = SPI_SSPCR1_SSE;

	for (;;) {
		spi->SSPDR = 0xB0;
		//if ( spi->SSPSR & SPI_SSPSR_BSY)	// HIGH	sometimes busy
		//if (~spi->SSPSR & SPI_SSPSR_BSY)	// LOW	always busy
		//if ( spi->SSPSR & SPI_SSPSR_RFF)	// LOW	RX never full
		//if (~spi->SSPSR & SPI_SSPSR_RFF)	// HIGH	RX sometimes empty
		//if ( spi->SSPSR & SPI_SSPSR_RNE)	// LOW	RX always empty
		//if (~spi->SSPSR & SPI_SSPSR_RNE)	// HIGH	RX sometimes empty
		//if ( spi->SSPSR & SPI_SSPSR_TNF)	// HIGH	TX sometimes has room left
		//if (~spi->SSPSR & SPI_SSPSR_TNF)	// HIGH	TX sometimes full
		//if ( spi->SSPSR & SPI_SSPSR_TFE)	// LOW	TX never empty
		//if (~spi->SSPSR & SPI_SSPSR_TFE)	// HIGH	TX sometimes containing something
		//	gpio_set_pin_high(25);
	}
}
