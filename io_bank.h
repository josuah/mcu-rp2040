#include <stddef.h>
#include <stdint.h>

#define IO_BANK0 ((struct sdk_io_bank *)0x40014000)

struct sdk_io_bank {

	struct {

		/* 0x000: GPIO status */
		uint32_t volatile STATUS;

		/* 0x004: GPIO control including function select and overrides */
		uint32_t volatile CTRL;
#define IO_BANK_GPIO_CTRL_FUNCSEL(x)		((x) << 0)

	} GPIO[30];

	/* 0x0F0: Raw Interrupts */
	uint32_t volatile INTR[4];

	/* 0x100: Interrupt Enable for proc0 */
	uint32_t volatile PROC0_INTE[4];

	/* 0x110: Interrupt Force for proc0 */
	uint32_t volatile PROC0_INTF[4];

	/* 0x120: Interrupt status after masking & forcing for proc0 */
	uint32_t volatile PROC0_INTS[4];

	/* 0x130: Interrupt Enable for proc1 */
	uint32_t volatile PROC1_INTE[4];

	/* 0x140: Interrupt Force for proc1 */
	uint32_t volatile PROC1_INTF[4];

	/* 0x150: Interrupt status after masking & forcing for proc1 */
	uint32_t volatile PROC1_INTS[4];

	/* 0x160: Interrupt Enable for dormant_wake */
	uint32_t volatile DORMANT_WAKE_INTE[4];

	/* 0x170: Interrupt Force for dormant_wake */
	uint32_t volatile DORMANT_WAKE_INTF[4];

	/* 0x180: Interrupt status after masking & forcing for dormant_wake */
	uint32_t volatile DORMANT_WAKE_INTS[4];

};
