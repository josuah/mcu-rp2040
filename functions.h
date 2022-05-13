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
extern void gpio_set_pin_high(uint8_t pin);
extern void gpio_set_pin_low(uint8_t pin);

/** SPI **/

/* the clock speed might not be exact due to integer division */
extern void spi_init(struct mcu_spi *spi, uint32_t baud_rate_hz,
	uint8_t pin_sck, uint8_t pin_csn, uint8_t pin_rx, uint8_t pin_tx);

#endif
