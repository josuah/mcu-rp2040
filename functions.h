#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define FIELD(reg, fld)		(((reg) & fld##_Msk) >> fld##_Pos)

extern void __stop_program(void);

/** CLOCKS **/

#define CLK_SYS_HZ 125000000
#define CLK_PERI_HZ CLK_SYS_HZ

/** GPIO **/

extern void gpio_init(void);
extern void gpio_set_mode_output(uint8_t pin);
extern void gpio_set_pin(uint8_t pin);
extern void gpio_clear_pin(uint8_t pin);

/** SPI **/

/* submit a write, then processed by the SPI interrupts */
extern void spi_interrupt(struct mcu_spi *spi);

/* the clock speed might not be exact due to integer division */
extern void spi_init(struct mcu_spi *spi, uint8_t clock_divider,
	uint8_t pin_sck, uint8_t pin_csn, uint8_t pin_rx, uint8_t pin_tx);

/* interrupt handler for SPI events */
extern void spi_io_callback(struct mcu_spi *spi, uint8_t rx, uint8_t volatile *tx);

/* set SPI interrupts on or off */
extern void spi_enable_interrupts(struct mcu_spi *spi);
extern void spi_disable_interrupts(struct mcu_spi *spi);

#endif
