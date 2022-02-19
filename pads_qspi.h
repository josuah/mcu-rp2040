#include <stddef.h>
#include <stdint.h>

#define PADS_QSPI ((struct zmcu_pads_qspi *)0x40020000)

struct zmcu_pads_qspi {

	/* 0x00: Voltage select. Per bank control */
	uint32_t volatile VOLTAGE_SELECT;

	/* 0x04: Pad control register */
	uint32_t volatile GPIO_QSPI_SCLK;

	/* 0x08: Pad control register */
	uint32_t volatile GPIO_QSPI_SD[4];

	/* 0x18: Pad control register */
	uint32_t volatile GPIO_QSPI_SS;

};
