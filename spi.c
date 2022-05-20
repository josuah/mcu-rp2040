#include "libc.h"
#include "registers.h"
#include "functions.h"

void
spi_init(struct mcu_spi *spi, uint32_t baud_rate_hz,
	uint8_t pin_sck, uint8_t pin_csn, uint8_t pin_rx, uint8_t pin_tx)
{
	uint8_t id = (spi == SPI1);

	/* enable the peripheral clock, used by the TX/RX logic */
	CLOCKS->CLK[CLK_PERI].CTRL = CLOCKS_CLK_PERI_CTRL_ENABLE;

	/* take I/O, and SPI out of reset */
	RESETS->RESET &= ~RESETS_RESET_IO_BANK0;
	RESETS->RESET &= ~RESETS_RESET_PADS_BANK0;
	RESETS->RESET &= ~(RESETS_RESET_SPI0 << id);
	while (~RESETS->RESET_DONE & RESETS_RESET_DONE_IO_BANK0);
	while (~RESETS->RESET_DONE & RESETS_RESET_DONE_PADS_BANK0);
	while (~RESETS->RESET_DONE & (RESETS_RESET_DONE_SPI0 << id));

	/* setup the ports function multiplexing */
	IO_BANK0->GPIO[pin_sck].CTRL = IO_BANK0_GPIO_CTRL_FUNCSEL_SPI;
	IO_BANK0->GPIO[pin_csn].CTRL = IO_BANK0_GPIO_CTRL_FUNCSEL_SPI;
	IO_BANK0->GPIO[pin_rx].CTRL = IO_BANK0_GPIO_CTRL_FUNCSEL_SPI;
	IO_BANK0->GPIO[pin_tx].CTRL = IO_BANK0_GPIO_CTRL_FUNCSEL_SPI;

	/* set the direction of pins to input or output */
	SIO->GPIO_OE_SET = 1u << pin_sck | 1u << pin_csn | 1u << pin_tx;
	SIO->GPIO_OE_CLR = 1u << pin_rx;

	/* assume an incoming SSPCLK clock derived from CLK_PERI at 125MHz */
	spi->SSPCR0 = 0
	/* set SPI mode */
	 | SPI_SSPCR0_FRF_MOTOROLA
	/* set the number of bits per frames */
	 | (8 - 1) << SPI_SSPCR0_DSS_Pos;

	/* enable all interrupts generation */
	spi->SSPIMSC = SPI_SSPIMSC_TXIM | SPI_SSPIMSC_RXIM
	 | SPI_SSPIMSC_RTIM | SPI_SSPIMSC_RORIM;

	/* enable interrupts triggering */
	M0PLUS->NVIC_ISER |= 1u << (18 + id);

	/* the result of the division is expected to be >1 */
	spi->SSPCPSR = 2; // CLK_PERI_HZ /  baud_rate_hz;

	/* enable the SPI module *after* (#4.4.4) it was configured */
	spi->SSPCR1 = SPI_SSPCR1_SSE;
}
