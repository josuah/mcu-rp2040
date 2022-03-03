#include <stddef.h>
#include <stdint.h>

#define PIO0 ((struct sdk_pio0 *)0x50300000)

struct sdk_pio0 {

	/* 0x000: PIO control register */
	uint32_t volatile CTRL;

	/* 0x004: FIFO status register */
	uint32_t volatile FSTAT;

	/* 0x008: FIFO debug register */
	uint32_t volatile FDEBUG;

	/* 0x00C: FIFO levels */
	uint32_t volatile FLEVEL;

	/* 0x010: Direct write access to the TX FIFO for this state machine */
	uint32_t volatile TXF[4];

	/* 0x020: Direct read access to the RX FIFO for this state machine */
	uint32_t volatile RXF[4];

	/* 0x030: State machine IRQ flags register. Write 1 to clear */
	uint32_t volatile IRQ;

	/* 0x034: Writing a 1 to each of these bits will forcibly assert the corresponding IRQ */
	uint32_t volatile IRQ_FORCE;

	/* 0x038: increases input delay */
	uint32_t volatile INPUT_SYNC_BYPASS;

	/* 0x03C: Read to sample the pad output values PIO is currently driving to the GPIOs */
	uint32_t volatile DBG_PADOUT;

	/* 0x040: sample the pad output enables (direction) PIO is currently driving to the GPIOs */
	uint32_t volatile DBG_PADOE;

	/* 0x044: some free parameters that may vary between chip products */
	uint32_t volatile DBG_CFGINFO;

	/* 0x048: Write-only access to instruction memory location */
	uint32_t volatile INSTR_MEM[32];

	/* 0x0C8: Clock divisor register for state machine 0 */
	uint32_t volatile SM0_CLKDIV;

	/* 0x0CC: Execution/behavioural settings for state machine 0 */
	uint32_t volatile SM0_EXECCTRL;

	struct {

		/* 0x0: Control behaviour of the input/output shift registers for state machine 0 */
		uint32_t volatile SHIFTCTRL;

		/* 0x4: Current instruction address of state machine 0 */
		uint32_t volatile ADDR;

		/* 0x8: Read to see the instruction currently addressed by state machine 0's program counter */
		uint32_t volatile INSTR;

		/* 0xC: State machine pin control */
		uint32_t volatile PINCTRL;

	} SM[4];

	/* 0x128: Raw Interrupts */
	uint32_t volatile INTR;

	/* 0x12C: Interrupt Enable for irq0 */
	uint32_t volatile IRQ0_INTE;

	/* 0x130: Interrupt Force for irq0 */
	uint32_t volatile IRQ0_INTF;

	/* 0x134: Interrupt status after masking & forcing for irq0 */
	uint32_t volatile IRQ0_INTS;

	/* 0x138: Interrupt Enable for irq1 */
	uint32_t volatile IRQ1_INTE;

	/* 0x13C: Interrupt Force for irq1 */
	uint32_t volatile IRQ1_INTF;

	/* 0x140: Interrupt status after masking & forcing for irq1 */
	uint32_t volatile IRQ1_INTS;

};
