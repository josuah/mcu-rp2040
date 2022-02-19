#include <stddef.h>
#include <stdint.h>

#define SIO ((struct zmcu_sio *)0xD0000000)

struct zmcu_sio {

	/* 0x000: Processor core identifier */
	uint32_t volatile CPUID;

	/* 0x004: Input value for GPIO pins */
	uint32_t volatile GPIO_IN;

	/* 0x008: Input value for QSPI pins */
	uint32_t volatile GPIO_HI_IN;

	/* 0x010: GPIO output value */
	uint32_t volatile GPIO_OUT;

	/* 0x014: GPIO output value set */
	uint32_t volatile GPIO_OUT_SET;

	/* 0x018: GPIO output value clear */
	uint32_t volatile GPIO_OUT_CLR;

	/* 0x01C: GPIO output value XOR */
	uint32_t volatile GPIO_OUT_XOR;

	/* 0x020: GPIO output enable */
	uint32_t volatile GPIO_OE;

	/* 0x024: GPIO output enable set */
	uint32_t volatile GPIO_OE_SET;

	/* 0x028: GPIO output enable clear */
	uint32_t volatile GPIO_OE_CLR;

	/* 0x02C: GPIO output enable XOR */
	uint32_t volatile GPIO_OE_XOR;

	/* 0x030: QSPI output value */
	uint32_t volatile GPIO_HI_OUT;

	/* 0x034: QSPI output value set */
	uint32_t volatile GPIO_HI_OUT_SET;

	/* 0x038: QSPI output value clear */
	uint32_t volatile GPIO_HI_OUT_CLR;

	/* 0x03C: QSPI output value XOR */
	uint32_t volatile GPIO_HI_OUT_XOR;

	/* 0x040: QSPI output enable */
	uint32_t volatile GPIO_HI_OE;

	/* 0x044: QSPI output enable set */
	uint32_t volatile GPIO_HI_OE_SET;

	/* 0x048: QSPI output enable clear */
	uint32_t volatile GPIO_HI_OE_CLR;

	/* 0x04C: QSPI output enable XOR */
	uint32_t volatile GPIO_HI_OE_XOR;

	/* 0x050: Status register for inter-core FIFOs (mailboxes) */
	uint32_t volatile FIFO_ST;

	/* 0x054: Write access to this core’s TX FIFO */
	uint32_t volatile FIFO_WR;

	/* 0x058: Read access to this core’s RX FIFO */
	uint32_t volatile FIFO_RD;

	/* 0x05C: Spinlock state */
	uint32_t volatile SPINLOCK_ST;

	/* 0x060: Divider unsigned dividend */
	uint32_t volatile DIV_UDIVIDEND;

	/* 0x064: Divider unsigned divisor */
	uint32_t volatile DIV_UDIVISOR;

	/* 0x068: Divider signed dividend */
	uint32_t volatile DIV_SDIVIDEND;

	/* 0x06C: Divider signed divisor */
	uint32_t volatile DIV_SDIVISOR;

	/* 0x070: Divider result quotient */
	uint32_t volatile DIV_QUOTIENT;

	/* 0x074: Divider result remainder */
	uint32_t volatile DIV_REMAINDER;

	/* 0x078: Control and status register for divider */
	uint32_t volatile DIV_CSR;

	struct {

		/* 0x080: Read/write access to accumulator */
		uint32_t volatile ACCUM[2];

		/* 0x088: Read/write access to BASE0 register */
		uint32_t volatile BASE[3];

		/* 0x094: Read LANE result, and simultaneously write lane results to both */
		uint32_t volatile POP_LANE[2];

		/* 0x09C: Read FULL result, and simultaneously write lane results to both accumulators (POP) */
		uint32_t volatile POP_FULL;

		/* 0x0A0: Read LANE result, without altering any internal state (PEEK) */
		uint32_t volatile PEEK_LANE[2];

		/* 0x0A8: Read FULL result, without altering any internal state (PEEK) */
		uint32_t volatile PEEK_FULL;

		/* 0x0AC: Control register for lane 0 */
		uint32_t volatile CTRL_LANE[2];

		/* 0x0B4: Values written here are atomically added to ACCUM */
		uint32_t volatile ACCUM_ADD[2];

		/* 0x0BC: On write, the lower 16 bits go to BASE0, upper bits to BASE1 simultaneously */
		uint32_t volatile BASE_1AND0;

	} INTERP[2];

	/* 0x100: Spinlock register 0 */
	uint32_t volatile SPINLOCK[32];

};
