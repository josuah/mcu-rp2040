#include <stddef.h>
#include <stdint.h>

#define IO_QSPI ((struct sdk_io_qspi *)0x40018000)

struct sdk_io_qspi {

	/* 0x00: GPIO status */
	uint32_t volatile GPIO_QSPI_SCLK_STATUS;

	/* 0x04: GPIO control including function select and overrides */
	uint32_t volatile GPIO_QSPI_SCLK_CTRL;

	/* 0x08: GPIO status */
	uint32_t volatile GPIO_QSPI_SS_STATUS;

	/* 0x0C: GPIO control including function select and overrides */
	uint32_t volatile GPIO_QSPI_SS_CTRL;

	/* 0x10: GPIO status */
	uint32_t volatile GPIO_QSPI_SD0_STATUS;

	/* 0x14: GPIO control including function select and overrides */
	uint32_t volatile GPIO_QSPI_SD0_CTRL;

	/* 0x18: GPIO status */
	uint32_t volatile GPIO_QSPI_SD1_STATUS;

	/* 0x1C: GPIO control including function select and overrides */
	uint32_t volatile GPIO_QSPI_SD1_CTRL;

	/* 0x20: GPIO status */
	uint32_t volatile GPIO_QSPI_SD2_STATUS;

	/* 0x24: GPIO control including function select and overrides */
	uint32_t volatile GPIO_QSPI_SD2_CTRL;

	/* 0x28: GPIO status */
	uint32_t volatile GPIO_QSPI_SD3_STATUS;

	/* 0x2C: GPIO control including function select and overrides */
	uint32_t volatile GPIO_QSPI_SD3_CTRL;

	/* 0x30: Raw Interrupts */
	uint32_t volatile INTR;

	/* 0x34: Interrupt Enable for proc0 */
	uint32_t volatile PROC0_INTE;

	/* 0x38: Interrupt Force for proc0 */
	uint32_t volatile PROC0_INTF;

	/* 0x3C: Interrupt status after masking & forcing for proc0 */
	uint32_t volatile PROC0_INTS;

	/* 0x40: Interrupt Enable for proc1 */
	uint32_t volatile PROC1_INTE;

	/* 0x44: Interrupt Force for proc1 */
	uint32_t volatile PROC1_INTF;

	/* 0x48: Interrupt status after masking & forcing for proc1 */
	uint32_t volatile PROC1_INTS;

	/* 0x4C: Interrupt Enable for dormant_wake */
	uint32_t volatile DORMANT_WAKE_INTE;

	/* 0x50: Interrupt Force for dormant_wake */
	uint32_t volatile DORMANT_WAKE_INTF;

	/* 0x54: Interrupt status after masking & forcing for dormant_wake */
	uint32_t volatile DORMANT_WAKE_INTS;

};
