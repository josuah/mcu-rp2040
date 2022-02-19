#include <stddef.h>
#include <stdint.h>

#define XIP_CTRL ((struct zmcu_xip_ctrl *)0x14000000)

struct zmcu_xip_ctrl {

	/* 0x00: Cache contro */
	uint32_t volatile CTRL;

	/* 0x04: Cache Flush contro */
	uint32_t volatile FLUSH;

	/* 0x08: Cache Statu */
	uint32_t volatile STAT;

	/* 0x0C: Cache Hit counte */
	uint32_t volatile CTR_HIT;

	/* 0x10: Cache Access counte */
	uint32_t volatile CTR_ACC;

	/* 0x14: FIFO stream addres */
	uint32_t volatile STREAM_ADDR;

	/* 0x18: FIFO stream contro */
	uint32_t volatile STREAM_CTR;

	/* 0x1C: FIFO stream dat */
	uint32_t volatile STREAM_FIFO;

};
