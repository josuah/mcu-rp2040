#include <stddef.h>
#include <stdint.h>

#define PLL_SYS ((struct sdk_pll *)0x40028000)
#define PLL_USB ((struct sdk_pll *)0x4002C000)

struct sdk_pll {

	/* 0x0: Control and Status */
	uint32_t volatile CS;
#define PLL_CS_MASK				0x8000013Fu
#define PLL_CS_LOCK				(1u << 31)
#define PLL_CS_BYPASS				(1u << 8)
#define PLL_CS_REFDIV				(1u << 0)

	/* 0x4: Controls the PLL power modes */
	uint32_t volatile PWR;
#define PLL_PWR_VCOPD				(1u << 5)
#define PLL_PWR_POSTDIVPD(x)			((x) << 3)
#define PLL_PWR_DSMPD				(1u << 2)
#define PLL_PWR_PD				(1u << 0)

	/* 0x8: Feedback divison */
	uint32_t volatile FBDIV_INT;
#define PLL_FBDIV_INT_MASK			0x00000FFFu

	/* 0xC: Controls the PLL post dividers for the primary output */
	uint32_t volatile PRIM;
#define PLL_PRIM_MASK				0x00077000u
#define PLL_PRIM_POSTDIV1(x)			((x) << 16)
#define PLL_PRIM_POSTDIV2(x)			((x) << 12)

};
