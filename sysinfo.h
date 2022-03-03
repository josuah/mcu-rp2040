#include <stddef.h>
#include <stdint.h>

#define SYSINFO ((struct sdk_sysinfo *)0x40000000)

struct sdk_sysinfo {

	/* 0x00: JEDEC JEP-106 compliant chip identifier */
	uint32_t volatile CHIP_ID;

	/* 0x04: Platform register. Allows software to know what environment it is running in */
	uint32_t volatile PLATFORM;

	/* 0x40: Git hash of the chip source. Used to identify chip version */
	uint32_t volatile GITREF_RP2040;

};
