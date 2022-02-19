#include <stddef.h>
#include <stdint.h>

#define DMA ((struct zmcu_dma *)0x50000000)

struct zmcu_dma {

	struct {

		/* 0x000: DMA Channel 0 Read Address pointer */
		uint32_t volatile READ_ADDR;

		/* 0x004: DMA Channel 0 Write Address pointer */
		uint32_t volatile WRITE_ADDR;

		/* 0x008: DMA Channel 0 Transfer Coun */
		uint32_t volatile TRANS_COUNT;

		/* 0x00C: DMA Channel 0 Control and Statu */
		uint32_t volatile CTRL_TRIG;

		/* 0x010: Alias for channel 0 CTRL register */
		uint32_t volatile AL1_CTRL;

		/* 0x014: Alias for channel 0 READ_ADDR register */
		uint32_t volatile AL1_READ_ADDR;

		/* 0x018: Alias for channel 0 WRITE_ADDR register */
		uint32_t volatile AL1_WRITE_ADDR;

		/* 0x01C: Alias for channel 0 TRANS_COUNT register */
		uint32_t volatile AL1_TRANS_COUNT_TRIG;

		/* 0x020: Alias for channel 0 CTRL register */
		uint32_t volatile AL2_CTRL;

		/* 0x024: Alias for channel 0 TRANS_COUNT register */
		uint32_t volatile AL2_TRANS_COUNT;

		/* 0x028: Alias for channel 0 READ_ADDR register */
		uint32_t volatile AL2_READ_ADDR;

		/* 0x02C: Alias for channel 0 WRITE_ADDR register */
		uint32_t volatile AL2_WRITE_ADDR_TRIG;

		/* 0x030: Alias for channel 0 CTRL register */
		uint32_t volatile AL3_CTRL;

		/* 0x034: Alias for channel 0 WRITE_ADDR register */
		uint32_t volatile AL3_WRITE_ADDR;

		/* 0x038: Alias for channel 0 TRANS_COUNT register */
		uint32_t volatile AL3_TRANS_COUNT;

		/* 0x03C: Alias for channel 0 READ_ADDR register */
		uint32_t volatile AL3_READ_ADDR_TRIG;

	} DMA_CH[12];

	/* 0x400: Interrupt Status (raw */
	uint32_t volatile INTR;

	/* 0x404: Interrupt Enables for IRQ  */
	uint32_t volatile INTE0;

	/* 0x408: Force Interrupt */
	uint32_t volatile INTF0;

	/* 0x40C: Interrupt Status for IRQ  */
	uint32_t volatile INTS0;

	/* 0x414: Interrupt Enables for IRQ  */
	uint32_t volatile INTE1;

	/* 0x418: Force Interrupts for IRQ  */
	uint32_t volatile INTF1;

	/* 0x41C: Interrupt Status (masked) for IRQ  */
	uint32_t volatile INTS1;

	/* 0x420: Pacing (X/Y) Fractional Time */
	uint32_t volatile TIMER[4];

	/* 0x430: Trigger one or more channels simultaneousl */
	uint32_t volatile MULTI_CHAN_TRIGGER;

	/* 0x434: Sniffer Contro */
	uint32_t volatile SNIFF_CTRL;

	/* 0x438: Data accumulator for sniff hardwar */
	uint32_t volatile SNIFF_DATA;

	/* 0x440: Debug RAF, WAF, TDF level */
	uint32_t volatile FIFO_LEVELS;

	/* 0x444: Abort an in-progress transfer sequence on one or more channel */
	uint32_t volatile CHAN_ABORT;

	/* 0x448: The number of channels this DMA instance is equipped with */
	uint32_t volatile N_CHANNELS;

	struct {

		/* 0x800: channel DREQ counter */
		uint32_t volatile CH0_DBG_CTDREQ;

		/* 0x804: channel TRANS_COUNT reload valu */
		uint32_t volatile CH0_DBG_TCR;

	} CH_DBG[12];

};
