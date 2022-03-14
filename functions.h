#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define FIELD(reg, fld)		(((reg) & fld##_Msk) >> fld##_Pos)

/* halt the execution */
void __stop_program(void);

/** GPIO **/

void gpio_init(void);
void gpio_set_mode_output(uint8_t pin);
void gpio_set_pin_up(uint8_t pin);

/** CLOCKS **/

#endif
