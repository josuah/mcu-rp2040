#include <stddef.h>
#include <stdint.h>

#define XIP_SSI ((struct sdk_xip_ssi *)0x18000000)

struct sdk_xip_ssi {

	/* 0x00: Control register */
	uint32_t volatile CTRLR[2];

	/* 0x08: SSI Enable */
	uint32_t volatile SSIENR;

	/* 0x0C: Microwire Control */
	uint32_t volatile MWCR;

	/* 0x10: Slave enable */
	uint32_t volatile SER;

	/* 0x14: Baud rate */
	uint32_t volatile BAUDR;

	/* 0x18: TX FIFO threshold level */
	uint32_t volatile TXFTLR;

	/* 0x1C: RX FIFO threshold level */
	uint32_t volatile RXFTLR;

	/* 0x20: TX FIFO level */
	uint32_t volatile TXFLR;

	/* 0x24: RX FIFO level */
	uint32_t volatile RXFLR;

	/* 0x28: Status register */
	uint32_t volatile SR;

	/* 0x2C: Interrupt mask */
	uint32_t volatile IMR;

	/* 0x30: Interrupt status */
	uint32_t volatile ISR;

	/* 0x34: Raw interrupt status */
	uint32_t volatile RISR;

	/* 0x38: TX FIFO overflow interrupt clear */
	uint32_t volatile TXOICR;

	/* 0x3C: RX FIFO overflow interrupt clear */
	uint32_t volatile RXOICR;

	/* 0x40: RX FIFO underflow interrupt clear */
	uint32_t volatile RXUICR;

	/* 0x44: Multi-master interrupt clear */
	uint32_t volatile MSTICR;

	/* 0x48: Interrupt clear */
	uint32_t volatile ICR;

	/* 0x4C: DMA control */
	uint32_t volatile DMACR;

	/* 0x50: DMA TX data level */
	uint32_t volatile DMATDLR;

	/* 0x54: DMA RX data level */
	uint32_t volatile DMARDLR;

	/* 0x58: Identification register */
	uint32_t volatile IDR;

	/* 0x5C: Version ID */
	uint32_t volatile SSI_VERSION_ID;

	/* 0x60: Data Register 0 (of 36) */
	uint32_t volatile DR0;

	/* 0xF0: RX sample delay */
	uint32_t volatile RX_SAMPLE_DLY;

	/* 0xF4: SPI control */
	uint32_t volatile SPI_CTRLR0;

	/* 0xF8: TX drive edge */
	uint32_t volatile TXD_DRIVE_EDGE;

};

#endif
