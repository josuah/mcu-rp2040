#include <stddef.h>
#include <stdint.h>

#define BUSCTRL ((struct zmcu_busctrl *)0x40030000)

struct zmcu_busctrl {

	/* 0x00: Set the priority of each master for bus arbitration */
	uint32_t volatile BUS_PRIORITY;

	/* 0x04: Bus priority acknowledge */
	uint32_t volatile BUS_PRIORITY_ACK;

	struct {

		/* 0x08: Bus fabric performance counter 0 */
		uint32_t volatile CTR;

		/* 0x0C: Bus fabric performance event select for PERFCTR0 */
		uint32_t volatile SEL;

	} PERF[4];

};
