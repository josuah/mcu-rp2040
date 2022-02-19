#include <stddef.h>
#include <stdint.h>

#define VREG_AND_CHIP_RESET ((struct zmcu_vreg_and_chip_reset *)0x40064000)

struct zmcu_vreg_and_chip_reset {

	/* 0x0: Voltage regulator control and statu */
	uint32_t volatile VREG;

	/* 0x4: brown-out detection contro */
	uint32_t volatile BOD;

	/* 0x8: Chip reset control and statu */
	uint32_t volatile CHIP_RESET;

};
