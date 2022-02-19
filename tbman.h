#include <stddef.h>
#include <stdint.h>

#define TBMAN ((struct zmcu_tbman *)0x4006C000)

struct zmcu_tbman {

	/* 0x0: Indicates the type of platform in use */
	uint32_t volatile PLATFORM;

};
