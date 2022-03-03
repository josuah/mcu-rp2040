#include <stddef.h>
#include <stdint.h>

#define PPB ((struct sdk_ppb *)0xE0000000)

struct sdk_ppb {

	/* 0xE010: SysTick Control and Status Register */
	uint32_t volatile SYST_CSR;

	/* 0xE014: SysTick Reload Value Register */
	uint32_t volatile SYST_RVR;

	/* 0xE018: SysTick Current Value Register */
	uint32_t volatile SYST_CVR;

	/* 0xE01C: SysTick Calibration Value Register */
	uint32_t volatile SYST_CALIB;

	/* 0xE100: Interrupt Set-Enable Register */
	uint32_t volatile NVIC_ISER;

	/* 0xE180: Interrupt Clear-Enable Register */
	uint32_t volatile NVIC_ICER;

	/* 0xE200: Interrupt Set-Pending Register */
	uint32_t volatile NVIC_ISPR;

	/* 0xE280: Interrupt Clear-Pending Register */
	uint32_t volatile NVIC_ICPR;

	/* 0xE400: Interrupt Priority Register  */
	uint32_t volatile NVIC_IPR[8];

	/* 0xED00: CPUID Base Register */
	uint32_t volatile CPUID;

	/* 0xED04: Interrupt Control and State Register */
	uint32_t volatile ICSR;

	/* 0xED08: Vector Table Offset Register */
	uint32_t volatile VTOR;

	/* 0xED0C: Application Interrupt and Reset Control Register */
	uint32_t volatile AIRCR;

	/* 0xED10: System Control Register */
	uint32_t volatile SCR;

	/* 0xED14: Configuration and Control Register */
	uint32_t volatile CCR;

	/* 0xED1C: System Handler Priority Register  */
	uint32_t volatile SHPR2;

	/* 0xED20: System Handler Priority Register  */
	uint32_t volatile SHPR3;

	/* 0xED24: System Handler Control and State Register */
	uint32_t volatile SHCSR;

	/* 0xED90: MPU Type Register */
	uint32_t volatile MPU_TYPE;

	/* 0xED94: MPU Control Register */
	uint32_t volatile MPU_CTRL;

	/* 0xED98: MPU Region Number Register */
	uint32_t volatile MPU_RNR;

	/* 0xED9C: MPU Region Base Address Register */
	uint32_t volatile MPU_RBAR;

	/* 0xEDA0: MPU Region Attribute and Size Register */
	uint32_t volatile MPU_RASR;

};
