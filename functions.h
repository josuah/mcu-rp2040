#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define FIELD(reg, fld)		(((reg) & fld##_Msk) >> fld##_Pos)

extern void __stop_program(void);

/** CLOCKS **/

#define CLK_SYS_HZ 125000000

/** GPIO **/

extern void gpio_init(void);
extern void gpio_set_mode_output(uint8_t pin);
extern void gpio_set_pin_up(uint8_t pin);

/** SPI **/

/* the clock speed might not be exact due to integer division */
extern void spi_init(struct mcu_spi *spi, uint32_t baud_rate_hz);

#endif
