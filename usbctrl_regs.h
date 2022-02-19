#include <stddef.h>
#include <stdint.h>

#define USBCTRL_REGS ((struct zmcu_usbctrl_regs *)0x50110000)

struct zmcu_usbctrl_regs {

	/* 0x00: Device address and endpoint control */
	uint32_t volatile ADDR_ENDP_CTRL;

	/* 0x04: Interrupt endpoint */
	uint32_t volatile ADDR_ENDP[16];

	/* 0x40: Main control register */
	uint32_t volatile MAIN_CTRL;

	/* 0x44: Set the SOF (Start of Frame) frame number in the host controller */
	uint32_t volatile SOF_WR;

	/* 0x48: Read the last SOF (Start of Frame) frame number seen */
	uint32_t volatile SOF_RD;

	/* 0x4C: SIE control register */
	uint32_t volatile SIE_CTRL;

	/* 0x50: SIE status register */
	uint32_t volatile SIE_STATUS;

	/* 0x54: interrupt endpoint control register */
	uint32_t volatile INT_EP_CTRL;

	/* 0x58: Buffer status register */
	uint32_t volatile BUFF_STATUS;

	/* 0x5C: Which of the double buffers should be handled */
	uint32_t volatile BUFF_CPU_SHOULD_HANDLE;

	/* 0x60: ignore the buffer control register for this endpoint */
	uint32_t volatile EP_ABORT;

	/* 0x64: Used in conjunction with EP_ABORT */
	uint32_t volatile EP_ABORT_DONE;

	/* 0x68: send a STALL on EP0 */
	uint32_t volatile EP_STALL_ARM;

	/* 0x6C: wait time in microseconds before trying again if the device replies with a NAK */
	uint32_t volatile NAK_POLL;

	/* 0x70: IRQ_ON_NAK or IRQ_ON_STALL */
	uint32_t volatile EP_STATUS_STALL_NAK;

	/* 0x74: Where to connect the USB controller */
	uint32_t volatile USB_MUXING;

	/* 0x78: Overrides for the power signals in the event that the VBUS signals are not hooked up to GPIO */
	uint32_t volatile USB_PWR;

	/* 0x7C: direct control of the USB phy */
	uint32_t volatile USBPHY_DIRECT;

	/* 0x80: Override enable for each control in usbphy_direct */
	uint32_t volatile USBPHY_DIRECT_OVERRIDE;

	/* 0x84: Used to adjust trim values of USB phy pull down resistors */
	uint32_t volatile USBPHY_TRIM;

	/* 0x8C: Raw Interrupts */
	uint32_t volatile INTR;

	/* 0x90: Interrupt Enable */
	uint32_t volatile INTE;

	/* 0x94: Interrupt Force */
	uint32_t volatile INTF;

	/* 0x98: Interrupt status after masking & forcing */
	uint32_t volatile INTS;

};
