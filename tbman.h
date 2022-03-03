#include <stddef.h>
#include <stdint.h>

#define TBMAN ((struct sdk_tbman *)0x4006C000)

struct sdk_tbman {

	/* 0x0: Indicates the type of platform in use */
	uint32_t volatile PLATFORM;

};
