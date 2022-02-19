#include <stddef.h>
#include <stdint.h>

struct zmcu_spi {

	/* 0x000: Control register, SSPCR on page 3-4 */
	uint32_t volatile SSPCR[2];

	/* 0x008: Data register, SSPDR on page 3-6 */
	uint32_t volatile SSPDR;

	/* 0x00C: Status register, SSPSR on page 3-7 */
	uint32_t volatile SSPSR;

	/* 0x010: Clock prescale register, SSPCPSR on page 3-8 */
	uint32_t volatile SSPCPSR;

	/* 0x014: Interrupt mask set or clear register, SSPIMSC on page 3-9 */
	uint32_t volatile SSPIMSC;

	/* 0x018: Raw interrupt status register, SSPRIS on page 3-10 */
	uint32_t volatile SSPRIS;

	/* 0x01C: Masked interrupt status register, SSPMIS on page 3-11 */
	uint32_t volatile SSPMIS;

	/* 0x020: Interrupt clear register, SSPICR on page 3-11 */
	uint32_t volatile SSPICR;

	/* 0x024: DMA control register, SSPDMACR on page 3-12 */
	uint32_t volatile SSPDMACR;

	/* 0x028-0x0FDC */
	uint32_t volatile RESERVED1[1006];

	/* 0xFE0: Peripheral identification registers, SSPPeriphID0-3 on page 3-13 */
	uint32_t volatile SSPPERIPHID[4];

	/* 0xFF0: PrimeCell identification registers, SSPPCellID0-3 on page 3-16 */
	uint32_t volatile SSPPCELLID[4];

};
