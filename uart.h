#include <stddef.h>
#include <stdint.h>

#define UART0 ((struct zmcu_uart *)0x40034000)
#define UART1 ((struct zmcu_uart *)0x40038000)

struct zmcu_uart {

	/* 0x000: Data Register, UARTDR */
	uint32_t volatile UARTDR;

	/* 0x004: Receive Status Register/Error Clear Register, UARTRSR/UARTECR */
	uint32_t volatile UARTRSR;

	/* 0x018: Flag Register, UARTFR */
	uint32_t volatile UARTFR;

	/* 0x020: IrDA Low-Power Counter Register, UARTILPR */
	uint32_t volatile UARTILPR;

	/* 0x024: Integer Baud Rate Register, UARTIBRD */
	uint32_t volatile UARTIBRD;

	/* 0x028: Fractional Baud Rate Register, UARTFBRD */
	uint32_t volatile UARTFBRD;

	/* 0x02C: Line Control Register, UARTLCR_H */
	uint32_t volatile UARTLCR_H;

	/* 0x030: Control Register, UARTCR */
	uint32_t volatile UARTCR;

	/* 0x034: Interrupt FIFO Level Select Register, UARTIFLS */
	uint32_t volatile UARTIFLS;

	/* 0x038: Interrupt Mask Set/Clear Register, UARTIMSC */
	uint32_t volatile UARTIMSC;

	/* 0x03C: Raw Interrupt Status Register, UARTRIS */
	uint32_t volatile UARTRIS;

	/* 0x040: Masked Interrupt Status Register, UARTMIS */
	uint32_t volatile UARTMIS;

	/* 0x044: Interrupt Clear Register, UARTICR */
	uint32_t volatile UARTICR;

	/* 0x048: DMA Control Register, UARTDMACR */
	uint32_t volatile UARTDMACR;

	/* 0xFE0: UARTPeriphID0 Register */
	uint32_t volatile UARTPERIPHID[4];

	/* 0xFF0: UARTPCellID0 Register */
	uint32_t volatile UARTPCELLID[4];

};
