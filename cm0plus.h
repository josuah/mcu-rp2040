#ifndef CM0PLUS_H
#define CM0PLUS_H

#define NVIC ((struct mcu_nvic *)0xE000E100)

struct mcu_nvic {

	/* 0x00: Interrupt Set Enable Register */
	uint32_t volatile ISER;

	/* 0x04 */
	uint8_t RESERVED1[0x80-0x04];

	/* 0x80: Interrupt Clear Enable Register */
	uint32_t volatile ICER;

	/* 0x84 */
	uint8_t RESERVED2[0x100-0x84];

	/* 0x100: Interrupt Set-Pending Register */
	uint32_t volatile ISPR;

	/* 0x104 */
	uint8_t RESERVED3[0x180-0x104];

	/* 0x180: Interrupt Clear-Pending Register */
	uint32_t volatile ICPR;

	/* 0x184 */
	uint8_t RESERVED4[0x300-0x184];

	/* 0x300: Interrupt Priority Registers */
	uint32_t volatile IPR[8];

};

#endif
