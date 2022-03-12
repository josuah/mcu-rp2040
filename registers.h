#ifndef REGISTERS_H
#define REGISTERS_H


#define XIP_CTRL ((struct sdk_xip_ctrl *)0x14000000)

struct sdk_xip_ctrl {

	/* 0x00: Cache control */
	uint32_t volatile CTRL;
	/* When 1, the cache memories are powered down. */
#define XIP_CTRL_CTRL_POWER_DOWN				3u
	/* When 1, writes to any alias other than 0x0 (caching, allocating) */
#define XIP_CTRL_CTRL_ERR_BADWRITE				1u
	/* When 1, enable the cache. */
#define XIP_CTRL_CTRL_EN					0u

	/* 0x04: Cache Flush control */
	uint32_t volatile FLUSH;
	/* Write 1 to flush the cache. */
#define XIP_CTRL_FLUSH_FLUSH					0u

	/* 0x08: Cache Status */
	uint32_t volatile STAT;
	/* When 1, indicates the XIP streaming FIFO is completely full. */
#define XIP_CTRL_STAT_FIFO_FULL					2u
	/* When 1, indicates the XIP streaming FIFO is completely empty. */
#define XIP_CTRL_STAT_FIFO_EMPTY				1u
	/* Reads as 0 while a cache flush is in progress, and 1 otherwise. */
#define XIP_CTRL_STAT_FLUSH_READY				0u

	/* 0x0C: Cache Hit counter */
	uint32_t volatile CTR_HIT;

	/* 0x10: Cache Access counter */
	uint32_t volatile CTR_ACC;

	/* 0x14: FIFO stream address */
	uint32_t volatile STREAM_ADDR;
	/* The address of the next word to be streamed from flash to the streaming FIFO. */
#define XIP_CTRL_STREAM_ADDR_STREAM_ADDR_Msb			31u
#define XIP_CTRL_STREAM_ADDR_STREAM_ADDR_Lsb			2u

	/* 0x18: FIFO stream control */
	uint32_t volatile STREAM_CTR;
	/* Write a nonzero value to start a streaming read. */
#define XIP_CTRL_STREAM_CTR_STREAM_CTR_Msb			21u
#define XIP_CTRL_STREAM_CTR_STREAM_CTR_Lsb			0u

	/* 0x1C: FIFO stream data */
	uint32_t volatile STREAM_FIFO;

};


#define XIP_SSI ((struct sdk_xip_ssi *)0x18000000)

struct sdk_xip_ssi {

	/* 0x00: Control register 0 */
	uint32_t volatile CTRLR0;
	/* Slave select toggle enable */
#define XIP_SSI_CTRLR0_SSTE					24u
	/* SPI frame format */
#define XIP_SSI_CTRLR0_SPI_FRF_Msb				22u
#define XIP_SSI_CTRLR0_SPI_FRF_Lsb				21u
#define XIP_SSI_CTRLR0_SPI_FRF_STD				0u
#define XIP_SSI_CTRLR0_SPI_FRF_DUAL				1u
#define XIP_SSI_CTRLR0_SPI_FRF_QUAD				2u
	/* Data frame size in 32b transfer mode */
#define XIP_SSI_CTRLR0_DFS_32_Msb				20u
#define XIP_SSI_CTRLR0_DFS_32_Lsb				16u
	/* Control frame size */
#define XIP_SSI_CTRLR0_CFS_Msb					15u
#define XIP_SSI_CTRLR0_CFS_Lsb					12u
	/* Shift register loop (test mode) */
#define XIP_SSI_CTRLR0_SRL					11u
	/* Slave output enable */
#define XIP_SSI_CTRLR0_SLV_OE					10u
	/* Transfer mode */
#define XIP_SSI_CTRLR0_TMOD_Msb					9u
#define XIP_SSI_CTRLR0_TMOD_Lsb					8u
#define XIP_SSI_CTRLR0_TMOD_TX_AND_RX				0u
#define XIP_SSI_CTRLR0_TMOD_TX_ONLY				1u
#define XIP_SSI_CTRLR0_TMOD_RX_ONLY				2u
#define XIP_SSI_CTRLR0_TMOD_EEPROM_READ				3u
	/* Serial clock polarity */
#define XIP_SSI_CTRLR0_SCPOL					7u
	/* Serial clock phase */
#define XIP_SSI_CTRLR0_SCPH					6u
	/* Frame format */
#define XIP_SSI_CTRLR0_FRF_Msb					5u
#define XIP_SSI_CTRLR0_FRF_Lsb					4u
	/* Data frame size */
#define XIP_SSI_CTRLR0_DFS_Msb					3u
#define XIP_SSI_CTRLR0_DFS_Lsb					0u

	/* 0x04: Master Control register 1 */
	uint32_t volatile CTRLR1;
	/* Number of data frames */
#define XIP_SSI_CTRLR1_NDF_Msb					15u
#define XIP_SSI_CTRLR1_NDF_Lsb					0u

	/* 0x08: SSI Enable */
	uint32_t volatile SSIENR;
	/* SSI enable */
#define XIP_SSI_SSIENR_SSI_EN					0u

	/* 0x0C: Microwire Control */
	uint32_t volatile MWCR;
	/* Microwire handshaking */
#define XIP_SSI_MWCR_MHS					2u
	/* Microwire control */
#define XIP_SSI_MWCR_MDD					1u
	/* Microwire transfer mode */
#define XIP_SSI_MWCR_MWMOD					0u

	/* 0x10: Slave enable */
	uint32_t volatile SER;
	/* For each bit: */
#define XIP_SSI_SER_SER						0u

	/* 0x14: Baud rate */
	uint32_t volatile BAUDR;
	/* SSI clock divider */
#define XIP_SSI_BAUDR_SCKDV_Msb					15u
#define XIP_SSI_BAUDR_SCKDV_Lsb					0u

	/* 0x18: TX FIFO threshold level */
	uint32_t volatile TXFTLR;
	/* Transmit FIFO threshold */
#define XIP_SSI_TXFTLR_TFT_Msb					7u
#define XIP_SSI_TXFTLR_TFT_Lsb					0u

	/* 0x1C: RX FIFO threshold level */
	uint32_t volatile RXFTLR;
	/* Receive FIFO threshold */
#define XIP_SSI_RXFTLR_RFT_Msb					7u
#define XIP_SSI_RXFTLR_RFT_Lsb					0u

	/* 0x20: TX FIFO level */
	uint32_t volatile TXFLR;
	/* Transmit FIFO level */
#define XIP_SSI_TXFLR_TFTFL_Msb					7u
#define XIP_SSI_TXFLR_TFTFL_Lsb					0u

	/* 0x24: RX FIFO level */
	uint32_t volatile RXFLR;
	/* Receive FIFO level */
#define XIP_SSI_RXFLR_RXTFL_Msb					7u
#define XIP_SSI_RXFLR_RXTFL_Lsb					0u

	/* 0x28: Status register */
	uint32_t volatile SR;
	/* Data collision error */
#define XIP_SSI_SR_DCOL						6u
	/* Transmission error */
#define XIP_SSI_SR_TXE						5u
	/* Receive FIFO full */
#define XIP_SSI_SR_RFF						4u
	/* Receive FIFO not empty */
#define XIP_SSI_SR_RFNE						3u
	/* Transmit FIFO empty */
#define XIP_SSI_SR_TFE						2u
	/* Transmit FIFO not full */
#define XIP_SSI_SR_TFNF						1u
	/* SSI busy flag */
#define XIP_SSI_SR_BUSY						0u

	/* 0x2C: Interrupt mask */
	uint32_t volatile IMR;
	/* Multi-master contention interrupt mask */
#define XIP_SSI_IMR_MSTIM					5u
	/* Receive FIFO full interrupt mask */
#define XIP_SSI_IMR_RXFIM					4u
	/* Receive FIFO overflow interrupt mask */
#define XIP_SSI_IMR_RXOIM					3u
	/* Receive FIFO underflow interrupt mask */
#define XIP_SSI_IMR_RXUIM					2u
	/* Transmit FIFO overflow interrupt mask */
#define XIP_SSI_IMR_TXOIM					1u
	/* Transmit FIFO empty interrupt mask */
#define XIP_SSI_IMR_TXEIM					0u

	/* 0x30: Interrupt status */
	uint32_t volatile ISR;
	/* Multi-master contention interrupt status */
#define XIP_SSI_ISR_MSTIS					5u
	/* Receive FIFO full interrupt status */
#define XIP_SSI_ISR_RXFIS					4u
	/* Receive FIFO overflow interrupt status */
#define XIP_SSI_ISR_RXOIS					3u
	/* Receive FIFO underflow interrupt status */
#define XIP_SSI_ISR_RXUIS					2u
	/* Transmit FIFO overflow interrupt status */
#define XIP_SSI_ISR_TXOIS					1u
	/* Transmit FIFO empty interrupt status */
#define XIP_SSI_ISR_TXEIS					0u

	/* 0x34: Raw interrupt status */
	uint32_t volatile RISR;
	/* Multi-master contention raw interrupt status */
#define XIP_SSI_RISR_MSTIR					5u
	/* Receive FIFO full raw interrupt status */
#define XIP_SSI_RISR_RXFIR					4u
	/* Receive FIFO overflow raw interrupt status */
#define XIP_SSI_RISR_RXOIR					3u
	/* Receive FIFO underflow raw interrupt status */
#define XIP_SSI_RISR_RXUIR					2u
	/* Transmit FIFO overflow raw interrupt status */
#define XIP_SSI_RISR_TXOIR					1u
	/* Transmit FIFO empty raw interrupt status */
#define XIP_SSI_RISR_TXEIR					0u

	/* 0x38: TX FIFO overflow interrupt clear */
	uint32_t volatile TXOICR;
	/* Clear-on-read transmit FIFO overflow interrupt */
#define XIP_SSI_TXOICR_TXOICR					0u

	/* 0x3C: RX FIFO overflow interrupt clear */
	uint32_t volatile RXOICR;
	/* Clear-on-read receive FIFO overflow interrupt */
#define XIP_SSI_RXOICR_RXOICR					0u

	/* 0x40: RX FIFO underflow interrupt clear */
	uint32_t volatile RXUICR;
	/* Clear-on-read receive FIFO underflow interrupt */
#define XIP_SSI_RXUICR_RXUICR					0u

	/* 0x44: Multi-master interrupt clear */
	uint32_t volatile MSTICR;
	/* Clear-on-read multi-master contention interrupt */
#define XIP_SSI_MSTICR_MSTICR					0u

	/* 0x48: Interrupt clear */
	uint32_t volatile ICR;
	/* Clear-on-read all active interrupts */
#define XIP_SSI_ICR_ICR						0u

	/* 0x4C: DMA control */
	uint32_t volatile DMACR;
	/* Transmit DMA enable */
#define XIP_SSI_DMACR_TDMAE					1u
	/* Receive DMA enable */
#define XIP_SSI_DMACR_RDMAE					0u

	/* 0x50: DMA TX data level */
	uint32_t volatile DMATDLR;
	/* Transmit data watermark level */
#define XIP_SSI_DMATDLR_DMATDL_Msb				7u
#define XIP_SSI_DMATDLR_DMATDL_Lsb				0u

	/* 0x54: DMA RX data level */
	uint32_t volatile DMARDLR;
	/* Receive data watermark level (DMARDLR+1) */
#define XIP_SSI_DMARDLR_DMARDL_Msb				7u
#define XIP_SSI_DMARDLR_DMARDL_Lsb				0u

	/* 0x58: Identification register */
	uint32_t volatile IDR;
	/* Peripheral dentification code */
#define XIP_SSI_IDR_IDCODE_Msb					31u
#define XIP_SSI_IDR_IDCODE_Lsb					0u

	/* 0x5C: Version ID */
	uint32_t volatile SSI_VERSION_ID;
	/* SNPS component version (format X.YY) */
#define XIP_SSI_SSI_VERSION_ID_SSI_COMP_VERSION_Msb		31u
#define XIP_SSI_SSI_VERSION_ID_SSI_COMP_VERSION_Lsb		0u

	/* 0x60: Data Register 0 (of 36) */
	uint32_t volatile DR0;
	/* First data register of 36 */
#define XIP_SSI_DR0_DR_Msb					31u
#define XIP_SSI_DR0_DR_Lsb					0u

	/* 0x64 */
	uint8_t RESERVED0[0xF0-0x64];

	/* 0xF0: RX sample delay */
	uint32_t volatile RX_SAMPLE_DLY;
	/* RXD sample delay (in SCLK cycles) */
#define XIP_SSI_RX_SAMPLE_DLY_RSD_Msb				7u
#define XIP_SSI_RX_SAMPLE_DLY_RSD_Lsb				0u

	/* 0xF4: SPI control */
	uint32_t volatile SPI_CTRLR0;
	/* SPI Command to send in XIP mode (INST_L = 8-bit) or to append to Address (INST_L = 0-bit) */
#define XIP_SSI_SPI_CTRLR0_XIP_CMD_Msb				31u
#define XIP_SSI_SPI_CTRLR0_XIP_CMD_Lsb				24u
	/* Read data strobe enable */
#define XIP_SSI_SPI_CTRLR0_SPI_RXDS_EN				18u
	/* Instruction DDR transfer enable */
#define XIP_SSI_SPI_CTRLR0_INST_DDR_EN				17u
	/* SPI DDR transfer enable */
#define XIP_SSI_SPI_CTRLR0_SPI_DDR_EN				16u
	/* Wait cycles between control frame transmit and data reception (in SCLK cycles) */
#define XIP_SSI_SPI_CTRLR0_WAIT_CYCLES_Msb			15u
#define XIP_SSI_SPI_CTRLR0_WAIT_CYCLES_Lsb			11u
	/* Instruction length (0/4/8/16b) */
#define XIP_SSI_SPI_CTRLR0_INST_L_Msb				9u
#define XIP_SSI_SPI_CTRLR0_INST_L_Lsb				8u
#define XIP_SSI_SPI_CTRLR0_INST_L_NONE				0u
#define XIP_SSI_SPI_CTRLR0_INST_L_4B				1u
#define XIP_SSI_SPI_CTRLR0_INST_L_8B				2u
#define XIP_SSI_SPI_CTRLR0_INST_L_16B				3u
	/* Address length (0b-60b in 4b increments) */
#define XIP_SSI_SPI_CTRLR0_ADDR_L_Msb				5u
#define XIP_SSI_SPI_CTRLR0_ADDR_L_Lsb				2u
	/* Address and instruction transfer format */
#define XIP_SSI_SPI_CTRLR0_TRANS_TYPE_Msb			1u
#define XIP_SSI_SPI_CTRLR0_TRANS_TYPE_Lsb			0u
#define XIP_SSI_SPI_CTRLR0_TRANS_TYPE_1C1A			0u
#define XIP_SSI_SPI_CTRLR0_TRANS_TYPE_1C2A			1u
#define XIP_SSI_SPI_CTRLR0_TRANS_TYPE_2C2A			2u

	/* 0xF8: TX drive edge */
	uint32_t volatile TXD_DRIVE_EDGE;
	/* TXD drive edge */
#define XIP_SSI_TXD_DRIVE_EDGE_TDE_Msb				7u
#define XIP_SSI_TXD_DRIVE_EDGE_TDE_Lsb				0u

};


#define SYSINFO ((struct sdk_sysinfo *)0x40000000)

struct sdk_sysinfo {

	/* 0x00: JEDEC JEP-106 compliant chip identifier. */
	uint32_t volatile CHIP_ID;
	/*  */
#define SYSINFO_CHIP_ID_REVISION_Msb				31u
#define SYSINFO_CHIP_ID_REVISION_Lsb				28u
	/*  */
#define SYSINFO_CHIP_ID_PART_Msb				27u
#define SYSINFO_CHIP_ID_PART_Lsb				12u
	/*  */
#define SYSINFO_CHIP_ID_MANUFACTURER_Msb			11u
#define SYSINFO_CHIP_ID_MANUFACTURER_Lsb			0u

	/* 0x04: Platform register. */
	uint32_t volatile PLATFORM;
	/*  */
#define SYSINFO_PLATFORM_ASIC					1u
	/*  */
#define SYSINFO_PLATFORM_FPGA					0u

	/* 0x08 */
	uint8_t RESERVED0[0x40-0x08];

	/* 0x40: Git hash of the chip source. */
	uint32_t volatile GITREF_RP2040;

};


#define SYSCFG ((struct sdk_syscfg *)0x40004000)

struct sdk_syscfg {

	/* 0x00: Processor core 0 NMI source mask */
	uint32_t volatile PROC0_NMI_MASK;

	/* 0x04: Processor core 1 NMI source mask */
	uint32_t volatile PROC1_NMI_MASK;

	/* 0x08: Configuration for processors */
	uint32_t volatile PROC_CONFIG;
	/* Configure proc1 DAP instance ID. */
#define SYSCFG_PROC_CONFIG_PROC1_DAP_INSTID_Msb			31u
#define SYSCFG_PROC_CONFIG_PROC1_DAP_INSTID_Lsb			28u
	/* Configure proc0 DAP instance ID. */
#define SYSCFG_PROC_CONFIG_PROC0_DAP_INSTID_Msb			27u
#define SYSCFG_PROC_CONFIG_PROC0_DAP_INSTID_Lsb			24u
	/* Indication that proc1 has halted */
#define SYSCFG_PROC_CONFIG_PROC1_HALTED				1u
	/* Indication that proc0 has halted */
#define SYSCFG_PROC_CONFIG_PROC0_HALTED				0u

	/* 0x0C: For each bit, if 1, bypass the input synchronizer between that GPIO */
	uint32_t volatile PROC_IN_SYNC_BYPASS;
	/*  */
#define SYSCFG_PROC_IN_SYNC_BYPASS_PROC_IN_SYNC_BYPASS_Msb	29u
#define SYSCFG_PROC_IN_SYNC_BYPASS_PROC_IN_SYNC_BYPASS_Lsb	0u

	/* 0x10: For each bit, if 1, bypass the input synchronizer between that GPIO */
	uint32_t volatile PROC_IN_SYNC_BYPASS_HI;
	/*  */
#define SYSCFG_PROC_IN_SYNC_BYPASS_HI_PROC_IN_SYNC_BYPASS_HI_Msb	5u
#define SYSCFG_PROC_IN_SYNC_BYPASS_HI_PROC_IN_SYNC_BYPASS_HI_Lsb	0u

	/* 0x14: Directly control the SWD debug port of either processor */
	uint32_t volatile DBGFORCE;
	/* Attach processor 1 debug port to syscfg controls, and disconnect it from external SWD pads. */
#define SYSCFG_DBGFORCE_PROC1_ATTACH				7u
	/* Directly drive processor 1 SWCLK, if PROC1_ATTACH is set */
#define SYSCFG_DBGFORCE_PROC1_SWCLK				6u
	/* Directly drive processor 1 SWDIO input, if PROC1_ATTACH is set */
#define SYSCFG_DBGFORCE_PROC1_SWDI				5u
	/* Observe the value of processor 1 SWDIO output. */
#define SYSCFG_DBGFORCE_PROC1_SWDO				4u
	/* Attach processor 0 debug port to syscfg controls, and disconnect it from external SWD pads. */
#define SYSCFG_DBGFORCE_PROC0_ATTACH				3u
	/* Directly drive processor 0 SWCLK, if PROC0_ATTACH is set */
#define SYSCFG_DBGFORCE_PROC0_SWCLK				2u
	/* Directly drive processor 0 SWDIO input, if PROC0_ATTACH is set */
#define SYSCFG_DBGFORCE_PROC0_SWDI				1u
	/* Observe the value of processor 0 SWDIO output. */
#define SYSCFG_DBGFORCE_PROC0_SWDO				0u

	/* 0x18: Control power downs to memories. */
	uint32_t volatile MEMPOWERDOWN;
	/*  */
#define SYSCFG_MEMPOWERDOWN_ROM					7u
	/*  */
#define SYSCFG_MEMPOWERDOWN_USB					6u
	/*  */
#define SYSCFG_MEMPOWERDOWN_SRAM5				5u
	/*  */
#define SYSCFG_MEMPOWERDOWN_SRAM4				4u
	/*  */
#define SYSCFG_MEMPOWERDOWN_SRAM3				3u
	/*  */
#define SYSCFG_MEMPOWERDOWN_SRAM2				2u
	/*  */
#define SYSCFG_MEMPOWERDOWN_SRAM1				1u
	/*  */
#define SYSCFG_MEMPOWERDOWN_SRAM0				0u

};


#define CLOCKS ((struct sdk_clocks *)0x40008000)

struct sdk_clocks {

	/* 0x00: Clock control, can be changed on-the-fly (except for auxsrc) */
	uint32_t volatile CLK_GPOUT0_CTRL;
	/* An edge on this signal shifts the phase of the output by 1 cycle of the input clock */
#define CLOCKS_CLK_GPOUT0_CTRL_NUDGE				20u
	/* This delays the enable signal by up to 3 cycles of the input clock */
#define CLOCKS_CLK_GPOUT0_CTRL_PHASE_Msb			17u
#define CLOCKS_CLK_GPOUT0_CTRL_PHASE_Lsb			16u
	/* Enables duty cycle correction for odd divisors */
#define CLOCKS_CLK_GPOUT0_CTRL_DC50				12u
	/* Starts and stops the clock generator cleanly */
#define CLOCKS_CLK_GPOUT0_CTRL_ENABLE				11u
	/* Asynchronously kills the clock generator */
#define CLOCKS_CLK_GPOUT0_CTRL_KILL				10u
	/* Selects the auxiliary clock source, will glitch when switching */
#define CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_Msb			8u
#define CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_Lsb			5u
#define CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLKSRC_PLL_SYS		0u
#define CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLKSRC_GPIN0		1u
#define CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLKSRC_GPIN1		2u
#define CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLKSRC_PLL_USB		3u
#define CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_ROSC_CLKSRC		4u
#define CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_XOSC_CLKSRC		5u
#define CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLK_SYS			6u
#define CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLK_USB			7u
#define CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLK_ADC			8u
#define CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLK_RTC			9u
#define CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLK_REF			10u

	/* 0x04: Clock divisor, can be changed on-the-fly */
	uint32_t volatile CLK_GPOUT0_DIV;
	/* Integer component of the divisor, 0 -> divide by 2^16 */
#define CLOCKS_CLK_GPOUT0_DIV_INT_Msb				31u
#define CLOCKS_CLK_GPOUT0_DIV_INT_Lsb				8u
	/* Fractional component of the divisor */
#define CLOCKS_CLK_GPOUT0_DIV_FRAC_Msb				7u
#define CLOCKS_CLK_GPOUT0_DIV_FRAC_Lsb				0u

	/* 0x08: Indicates which SRC is currently selected by the glitchless mux (one-hot). */
	uint32_t volatile CLK_GPOUT0_SELECTED;

	/* 0x0C: Clock control, can be changed on-the-fly (except for auxsrc) */
	uint32_t volatile CLK_GPOUT1_CTRL;
	/* An edge on this signal shifts the phase of the output by 1 cycle of the input clock */
#define CLOCKS_CLK_GPOUT1_CTRL_NUDGE				20u
	/* This delays the enable signal by up to 3 cycles of the input clock */
#define CLOCKS_CLK_GPOUT1_CTRL_PHASE_Msb			17u
#define CLOCKS_CLK_GPOUT1_CTRL_PHASE_Lsb			16u
	/* Enables duty cycle correction for odd divisors */
#define CLOCKS_CLK_GPOUT1_CTRL_DC50				12u
	/* Starts and stops the clock generator cleanly */
#define CLOCKS_CLK_GPOUT1_CTRL_ENABLE				11u
	/* Asynchronously kills the clock generator */
#define CLOCKS_CLK_GPOUT1_CTRL_KILL				10u
	/* Selects the auxiliary clock source, will glitch when switching */
#define CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_Msb			8u
#define CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_Lsb			5u
#define CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLKSRC_PLL_SYS		0u
#define CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLKSRC_GPIN0		1u
#define CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLKSRC_GPIN1		2u
#define CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLKSRC_PLL_USB		3u
#define CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_ROSC_CLKSRC		4u
#define CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_XOSC_CLKSRC		5u
#define CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLK_SYS			6u
#define CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLK_USB			7u
#define CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLK_ADC			8u
#define CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLK_RTC			9u
#define CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLK_REF			10u

	/* 0x10: Clock divisor, can be changed on-the-fly */
	uint32_t volatile CLK_GPOUT1_DIV;
	/* Integer component of the divisor, 0 -> divide by 2^16 */
#define CLOCKS_CLK_GPOUT1_DIV_INT_Msb				31u
#define CLOCKS_CLK_GPOUT1_DIV_INT_Lsb				8u
	/* Fractional component of the divisor */
#define CLOCKS_CLK_GPOUT1_DIV_FRAC_Msb				7u
#define CLOCKS_CLK_GPOUT1_DIV_FRAC_Lsb				0u

	/* 0x14: Indicates which SRC is currently selected by the glitchless mux (one-hot). */
	uint32_t volatile CLK_GPOUT1_SELECTED;

	/* 0x18: Clock control, can be changed on-the-fly (except for auxsrc) */
	uint32_t volatile CLK_GPOUT2_CTRL;
	/* An edge on this signal shifts the phase of the output by 1 cycle of the input clock */
#define CLOCKS_CLK_GPOUT2_CTRL_NUDGE				20u
	/* This delays the enable signal by up to 3 cycles of the input clock */
#define CLOCKS_CLK_GPOUT2_CTRL_PHASE_Msb			17u
#define CLOCKS_CLK_GPOUT2_CTRL_PHASE_Lsb			16u
	/* Enables duty cycle correction for odd divisors */
#define CLOCKS_CLK_GPOUT2_CTRL_DC50				12u
	/* Starts and stops the clock generator cleanly */
#define CLOCKS_CLK_GPOUT2_CTRL_ENABLE				11u
	/* Asynchronously kills the clock generator */
#define CLOCKS_CLK_GPOUT2_CTRL_KILL				10u
	/* Selects the auxiliary clock source, will glitch when switching */
#define CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_Msb			8u
#define CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_Lsb			5u
#define CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLKSRC_PLL_SYS		0u
#define CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLKSRC_GPIN0		1u
#define CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLKSRC_GPIN1		2u
#define CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLKSRC_PLL_USB		3u
#define CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_ROSC_CLKSRC_PH		4u
#define CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_XOSC_CLKSRC		5u
#define CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLK_SYS			6u
#define CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLK_USB			7u
#define CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLK_ADC			8u
#define CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLK_RTC			9u
#define CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLK_REF			10u

	/* 0x1C: Clock divisor, can be changed on-the-fly */
	uint32_t volatile CLK_GPOUT2_DIV;
	/* Integer component of the divisor, 0 -> divide by 2^16 */
#define CLOCKS_CLK_GPOUT2_DIV_INT_Msb				31u
#define CLOCKS_CLK_GPOUT2_DIV_INT_Lsb				8u
	/* Fractional component of the divisor */
#define CLOCKS_CLK_GPOUT2_DIV_FRAC_Msb				7u
#define CLOCKS_CLK_GPOUT2_DIV_FRAC_Lsb				0u

	/* 0x20: Indicates which SRC is currently selected by the glitchless mux (one-hot). */
	uint32_t volatile CLK_GPOUT2_SELECTED;

	/* 0x24: Clock control, can be changed on-the-fly (except for auxsrc) */
	uint32_t volatile CLK_GPOUT3_CTRL;
	/* An edge on this signal shifts the phase of the output by 1 cycle of the input clock */
#define CLOCKS_CLK_GPOUT3_CTRL_NUDGE				20u
	/* This delays the enable signal by up to 3 cycles of the input clock */
#define CLOCKS_CLK_GPOUT3_CTRL_PHASE_Msb			17u
#define CLOCKS_CLK_GPOUT3_CTRL_PHASE_Lsb			16u
	/* Enables duty cycle correction for odd divisors */
#define CLOCKS_CLK_GPOUT3_CTRL_DC50				12u
	/* Starts and stops the clock generator cleanly */
#define CLOCKS_CLK_GPOUT3_CTRL_ENABLE				11u
	/* Asynchronously kills the clock generator */
#define CLOCKS_CLK_GPOUT3_CTRL_KILL				10u
	/* Selects the auxiliary clock source, will glitch when switching */
#define CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_Msb			8u
#define CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_Lsb			5u
#define CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLKSRC_PLL_SYS		0u
#define CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLKSRC_GPIN0		1u
#define CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLKSRC_GPIN1		2u
#define CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLKSRC_PLL_USB		3u
#define CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_ROSC_CLKSRC_PH		4u
#define CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_XOSC_CLKSRC		5u
#define CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLK_SYS			6u
#define CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLK_USB			7u
#define CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLK_ADC			8u
#define CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLK_RTC			9u
#define CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLK_REF			10u

	/* 0x28: Clock divisor, can be changed on-the-fly */
	uint32_t volatile CLK_GPOUT3_DIV;
	/* Integer component of the divisor, 0 -> divide by 2^16 */
#define CLOCKS_CLK_GPOUT3_DIV_INT_Msb				31u
#define CLOCKS_CLK_GPOUT3_DIV_INT_Lsb				8u
	/* Fractional component of the divisor */
#define CLOCKS_CLK_GPOUT3_DIV_FRAC_Msb				7u
#define CLOCKS_CLK_GPOUT3_DIV_FRAC_Lsb				0u

	/* 0x2C: Indicates which SRC is currently selected by the glitchless mux (one-hot). */
	uint32_t volatile CLK_GPOUT3_SELECTED;

	/* 0x30: Clock control, can be changed on-the-fly (except for auxsrc) */
	uint32_t volatile CLK_REF_CTRL;
	/* Selects the auxiliary clock source, will glitch when switching */
#define CLOCKS_CLK_REF_CTRL_AUXSRC_Msb				6u
#define CLOCKS_CLK_REF_CTRL_AUXSRC_Lsb				5u
#define CLOCKS_CLK_REF_CTRL_AUXSRC_CLKSRC_PLL_USB		0u
#define CLOCKS_CLK_REF_CTRL_AUXSRC_CLKSRC_GPIN0			1u
#define CLOCKS_CLK_REF_CTRL_AUXSRC_CLKSRC_GPIN1			2u
	/* Selects the clock source glitchlessly, can be changed on-the-fly */
#define CLOCKS_CLK_REF_CTRL_SRC_Msb				1u
#define CLOCKS_CLK_REF_CTRL_SRC_Lsb				0u
#define CLOCKS_CLK_REF_CTRL_SRC_ROSC_CLKSRC_PH			0u
#define CLOCKS_CLK_REF_CTRL_SRC_CLKSRC_CLK_REF_AUX		1u
#define CLOCKS_CLK_REF_CTRL_SRC_XOSC_CLKSRC			2u

	/* 0x34: Clock divisor, can be changed on-the-fly */
	uint32_t volatile CLK_REF_DIV;
	/* Integer component of the divisor, 0 -> divide by 2^16 */
#define CLOCKS_CLK_REF_DIV_INT_Msb				9u
#define CLOCKS_CLK_REF_DIV_INT_Lsb				8u

	/* 0x38: Indicates which SRC is currently selected by the glitchless mux (one-hot). */
	uint32_t volatile CLK_REF_SELECTED;

	/* 0x3C: Clock control, can be changed on-the-fly (except for auxsrc) */
	uint32_t volatile CLK_SYS_CTRL;
	/* Selects the auxiliary clock source, will glitch when switching */
#define CLOCKS_CLK_SYS_CTRL_AUXSRC_Msb				7u
#define CLOCKS_CLK_SYS_CTRL_AUXSRC_Lsb				5u
#define CLOCKS_CLK_SYS_CTRL_AUXSRC_CLKSRC_PLL_SYS		0u
#define CLOCKS_CLK_SYS_CTRL_AUXSRC_CLKSRC_PLL_USB		1u
#define CLOCKS_CLK_SYS_CTRL_AUXSRC_ROSC_CLKSRC			2u
#define CLOCKS_CLK_SYS_CTRL_AUXSRC_XOSC_CLKSRC			3u
#define CLOCKS_CLK_SYS_CTRL_AUXSRC_CLKSRC_GPIN0			4u
#define CLOCKS_CLK_SYS_CTRL_AUXSRC_CLKSRC_GPIN1			5u
	/* Selects the clock source glitchlessly, can be changed on-the-fly */
#define CLOCKS_CLK_SYS_CTRL_SRC					0u
#define CLOCKS_CLK_SYS_CTRL_SRC_CLK_REF				0u
#define CLOCKS_CLK_SYS_CTRL_SRC_CLKSRC_CLK_SYS_AUX		1u

	/* 0x40: Clock divisor, can be changed on-the-fly */
	uint32_t volatile CLK_SYS_DIV;
	/* Integer component of the divisor, 0 -> divide by 2^16 */
#define CLOCKS_CLK_SYS_DIV_INT_Msb				31u
#define CLOCKS_CLK_SYS_DIV_INT_Lsb				8u
	/* Fractional component of the divisor */
#define CLOCKS_CLK_SYS_DIV_FRAC_Msb				7u
#define CLOCKS_CLK_SYS_DIV_FRAC_Lsb				0u

	/* 0x44: Indicates which SRC is currently selected by the glitchless mux (one-hot). */
	uint32_t volatile CLK_SYS_SELECTED;

	/* 0x48: Clock control, can be changed on-the-fly (except for auxsrc) */
	uint32_t volatile CLK_PERI_CTRL;
	/* Starts and stops the clock generator cleanly */
#define CLOCKS_CLK_PERI_CTRL_ENABLE				11u
	/* Asynchronously kills the clock generator */
#define CLOCKS_CLK_PERI_CTRL_KILL				10u
	/* Selects the auxiliary clock source, will glitch when switching */
#define CLOCKS_CLK_PERI_CTRL_AUXSRC_Msb				7u
#define CLOCKS_CLK_PERI_CTRL_AUXSRC_Lsb				5u
#define CLOCKS_CLK_PERI_CTRL_AUXSRC_CLK_SYS			0u
#define CLOCKS_CLK_PERI_CTRL_AUXSRC_CLKSRC_PLL_SYS		1u
#define CLOCKS_CLK_PERI_CTRL_AUXSRC_CLKSRC_PLL_USB		2u
#define CLOCKS_CLK_PERI_CTRL_AUXSRC_ROSC_CLKSRC_PH		3u
#define CLOCKS_CLK_PERI_CTRL_AUXSRC_XOSC_CLKSRC			4u
#define CLOCKS_CLK_PERI_CTRL_AUXSRC_CLKSRC_GPIN0		5u
#define CLOCKS_CLK_PERI_CTRL_AUXSRC_CLKSRC_GPIN1		6u

	/* 0x4C */
	uint8_t RESERVED0[0x50-0x4C];

	/* 0x50: Indicates which SRC is currently selected by the glitchless mux (one-hot). */
	uint32_t volatile CLK_PERI_SELECTED;

	/* 0x54: Clock control, can be changed on-the-fly (except for auxsrc) */
	uint32_t volatile CLK_USB_CTRL;
	/* An edge on this signal shifts the phase of the output by 1 cycle of the input clock */
#define CLOCKS_CLK_USB_CTRL_NUDGE				20u
	/* This delays the enable signal by up to 3 cycles of the input clock */
#define CLOCKS_CLK_USB_CTRL_PHASE_Msb				17u
#define CLOCKS_CLK_USB_CTRL_PHASE_Lsb				16u
	/* Starts and stops the clock generator cleanly */
#define CLOCKS_CLK_USB_CTRL_ENABLE				11u
	/* Asynchronously kills the clock generator */
#define CLOCKS_CLK_USB_CTRL_KILL				10u
	/* Selects the auxiliary clock source, will glitch when switching */
#define CLOCKS_CLK_USB_CTRL_AUXSRC_Msb				7u
#define CLOCKS_CLK_USB_CTRL_AUXSRC_Lsb				5u
#define CLOCKS_CLK_USB_CTRL_AUXSRC_CLKSRC_PLL_USB		0u
#define CLOCKS_CLK_USB_CTRL_AUXSRC_CLKSRC_PLL_SYS		1u
#define CLOCKS_CLK_USB_CTRL_AUXSRC_ROSC_CLKSRC_PH		2u
#define CLOCKS_CLK_USB_CTRL_AUXSRC_XOSC_CLKSRC			3u
#define CLOCKS_CLK_USB_CTRL_AUXSRC_CLKSRC_GPIN0			4u
#define CLOCKS_CLK_USB_CTRL_AUXSRC_CLKSRC_GPIN1			5u

	/* 0x58: Clock divisor, can be changed on-the-fly */
	uint32_t volatile CLK_USB_DIV;
	/* Integer component of the divisor, 0 -> divide by 2^16 */
#define CLOCKS_CLK_USB_DIV_INT_Msb				9u
#define CLOCKS_CLK_USB_DIV_INT_Lsb				8u

	/* 0x5C: Indicates which SRC is currently selected by the glitchless mux (one-hot). */
	uint32_t volatile CLK_USB_SELECTED;

	/* 0x60: Clock control, can be changed on-the-fly (except for auxsrc) */
	uint32_t volatile CLK_ADC_CTRL;
	/* An edge on this signal shifts the phase of the output by 1 cycle of the input clock */
#define CLOCKS_CLK_ADC_CTRL_NUDGE				20u
	/* This delays the enable signal by up to 3 cycles of the input clock */
#define CLOCKS_CLK_ADC_CTRL_PHASE_Msb				17u
#define CLOCKS_CLK_ADC_CTRL_PHASE_Lsb				16u
	/* Starts and stops the clock generator cleanly */
#define CLOCKS_CLK_ADC_CTRL_ENABLE				11u
	/* Asynchronously kills the clock generator */
#define CLOCKS_CLK_ADC_CTRL_KILL				10u
	/* Selects the auxiliary clock source, will glitch when switching */
#define CLOCKS_CLK_ADC_CTRL_AUXSRC_Msb				7u
#define CLOCKS_CLK_ADC_CTRL_AUXSRC_Lsb				5u
#define CLOCKS_CLK_ADC_CTRL_AUXSRC_CLKSRC_PLL_USB		0u
#define CLOCKS_CLK_ADC_CTRL_AUXSRC_CLKSRC_PLL_SYS		1u
#define CLOCKS_CLK_ADC_CTRL_AUXSRC_ROSC_CLKSRC_PH		2u
#define CLOCKS_CLK_ADC_CTRL_AUXSRC_XOSC_CLKSRC			3u
#define CLOCKS_CLK_ADC_CTRL_AUXSRC_CLKSRC_GPIN0			4u
#define CLOCKS_CLK_ADC_CTRL_AUXSRC_CLKSRC_GPIN1			5u

	/* 0x64: Clock divisor, can be changed on-the-fly */
	uint32_t volatile CLK_ADC_DIV;
	/* Integer component of the divisor, 0 -> divide by 2^16 */
#define CLOCKS_CLK_ADC_DIV_INT_Msb				9u
#define CLOCKS_CLK_ADC_DIV_INT_Lsb				8u

	/* 0x68: Indicates which SRC is currently selected by the glitchless mux (one-hot). */
	uint32_t volatile CLK_ADC_SELECTED;

	/* 0x6C: Clock control, can be changed on-the-fly (except for auxsrc) */
	uint32_t volatile CLK_RTC_CTRL;
	/* An edge on this signal shifts the phase of the output by 1 cycle of the input clock */
#define CLOCKS_CLK_RTC_CTRL_NUDGE				20u
	/* This delays the enable signal by up to 3 cycles of the input clock */
#define CLOCKS_CLK_RTC_CTRL_PHASE_Msb				17u
#define CLOCKS_CLK_RTC_CTRL_PHASE_Lsb				16u
	/* Starts and stops the clock generator cleanly */
#define CLOCKS_CLK_RTC_CTRL_ENABLE				11u
	/* Asynchronously kills the clock generator */
#define CLOCKS_CLK_RTC_CTRL_KILL				10u
	/* Selects the auxiliary clock source, will glitch when switching */
#define CLOCKS_CLK_RTC_CTRL_AUXSRC_Msb				7u
#define CLOCKS_CLK_RTC_CTRL_AUXSRC_Lsb				5u
#define CLOCKS_CLK_RTC_CTRL_AUXSRC_CLKSRC_PLL_USB		0u
#define CLOCKS_CLK_RTC_CTRL_AUXSRC_CLKSRC_PLL_SYS		1u
#define CLOCKS_CLK_RTC_CTRL_AUXSRC_ROSC_CLKSRC_PH		2u
#define CLOCKS_CLK_RTC_CTRL_AUXSRC_XOSC_CLKSRC			3u
#define CLOCKS_CLK_RTC_CTRL_AUXSRC_CLKSRC_GPIN0			4u
#define CLOCKS_CLK_RTC_CTRL_AUXSRC_CLKSRC_GPIN1			5u

	/* 0x70: Clock divisor, can be changed on-the-fly */
	uint32_t volatile CLK_RTC_DIV;
	/* Integer component of the divisor, 0 -> divide by 2^16 */
#define CLOCKS_CLK_RTC_DIV_INT_Msb				31u
#define CLOCKS_CLK_RTC_DIV_INT_Lsb				8u
	/* Fractional component of the divisor */
#define CLOCKS_CLK_RTC_DIV_FRAC_Msb				7u
#define CLOCKS_CLK_RTC_DIV_FRAC_Lsb				0u

	/* 0x74: Indicates which SRC is currently selected by the glitchless mux (one-hot). */
	uint32_t volatile CLK_RTC_SELECTED;

	/* 0x78:  */
	uint32_t volatile CLK_SYS_RESUS_CTRL;
	/* For clearing the resus after the fault that triggered it has been corrected */
#define CLOCKS_CLK_SYS_RESUS_CTRL_CLEAR				16u
	/* Force a resus, for test purposes only */
#define CLOCKS_CLK_SYS_RESUS_CTRL_FRCE				12u
	/* Enable resus */
#define CLOCKS_CLK_SYS_RESUS_CTRL_ENABLE			8u
	/* This is expressed as a number of clk_ref cycles */
#define CLOCKS_CLK_SYS_RESUS_CTRL_TIMEOUT_Msb			7u
#define CLOCKS_CLK_SYS_RESUS_CTRL_TIMEOUT_Lsb			0u

	/* 0x7C:  */
	uint32_t volatile CLK_SYS_RESUS_STATUS;
	/* Clock has been resuscitated, correct the error then send ctrl_clear=1 */
#define CLOCKS_CLK_SYS_RESUS_STATUS_RESUSSED			0u

	/* 0x80: Reference clock frequency in kHz */
	uint32_t volatile FC0_REF_KHZ;
	/*  */
#define CLOCKS_FC0_REF_KHZ_FC0_REF_KHZ_Msb			19u
#define CLOCKS_FC0_REF_KHZ_FC0_REF_KHZ_Lsb			0u

	/* 0x84: Minimum pass frequency in kHz. */
	uint32_t volatile FC0_MIN_KHZ;
	/*  */
#define CLOCKS_FC0_MIN_KHZ_FC0_MIN_KHZ_Msb			24u
#define CLOCKS_FC0_MIN_KHZ_FC0_MIN_KHZ_Lsb			0u

	/* 0x88: Maximum pass frequency in kHz. */
	uint32_t volatile FC0_MAX_KHZ;
	/*  */
#define CLOCKS_FC0_MAX_KHZ_FC0_MAX_KHZ_Msb			24u
#define CLOCKS_FC0_MAX_KHZ_FC0_MAX_KHZ_Lsb			0u

	/* 0x8C: Delays the start of frequency counting to allow the mux to settle */
	uint32_t volatile FC0_DELAY;
	/*  */
#define CLOCKS_FC0_DELAY_FC0_DELAY_Msb				2u
#define CLOCKS_FC0_DELAY_FC0_DELAY_Lsb				0u

	/* 0x90: The test interval is 0.98us * 2**interval, but let's call it 1us * 2**interval */
	uint32_t volatile FC0_INTERVAL;
	/*  */
#define CLOCKS_FC0_INTERVAL_FC0_INTERVAL_Msb			3u
#define CLOCKS_FC0_INTERVAL_FC0_INTERVAL_Lsb			0u

	/* 0x94: Clock sent to frequency counter, set to 0 when not required */
	uint32_t volatile FC0_SRC;
	/*  */
#define CLOCKS_FC0_SRC_FC0_SRC_Msb				7u
#define CLOCKS_FC0_SRC_FC0_SRC_Lsb				0u
#define CLOCKS_FC0_SRC_FC0_SRC_NULL				0u
#define CLOCKS_FC0_SRC_FC0_SRC_PLL_SYS_CLKSRC_PRIMARY		1u
#define CLOCKS_FC0_SRC_FC0_SRC_PLL_USB_CLKSRC_PRIMARY		2u
#define CLOCKS_FC0_SRC_FC0_SRC_ROSC_CLKSRC			3u
#define CLOCKS_FC0_SRC_FC0_SRC_ROSC_CLKSRC_PH			4u
#define CLOCKS_FC0_SRC_FC0_SRC_XOSC_CLKSRC			5u
#define CLOCKS_FC0_SRC_FC0_SRC_CLKSRC_GPIN0			6u
#define CLOCKS_FC0_SRC_FC0_SRC_CLKSRC_GPIN1			7u
#define CLOCKS_FC0_SRC_FC0_SRC_CLK_REF				8u
#define CLOCKS_FC0_SRC_FC0_SRC_CLK_SYS				9u
#define CLOCKS_FC0_SRC_FC0_SRC_CLK_PERI				10u
#define CLOCKS_FC0_SRC_FC0_SRC_CLK_USB				11u
#define CLOCKS_FC0_SRC_FC0_SRC_CLK_ADC				12u
#define CLOCKS_FC0_SRC_FC0_SRC_CLK_RTC				13u

	/* 0x98: Frequency counter status */
	uint32_t volatile FC0_STATUS;
	/* Test clock stopped during test */
#define CLOCKS_FC0_STATUS_DIED					28u
	/* Test clock faster than expected, only valid when status_done=1 */
#define CLOCKS_FC0_STATUS_FAST					24u
	/* Test clock slower than expected, only valid when status_done=1 */
#define CLOCKS_FC0_STATUS_SLOW					20u
	/* Test failed */
#define CLOCKS_FC0_STATUS_FAIL					16u
	/* Waiting for test clock to start */
#define CLOCKS_FC0_STATUS_WAITING				12u
	/* Test running */
#define CLOCKS_FC0_STATUS_RUNNING				8u
	/* Test complete */
#define CLOCKS_FC0_STATUS_DONE					4u
	/* Test passed */
#define CLOCKS_FC0_STATUS_PASS					0u

	/* 0x9C: Result of frequency measurement, only valid when status_done=1 */
	uint32_t volatile FC0_RESULT;
	/*  */
#define CLOCKS_FC0_RESULT_KHZ_Msb				29u
#define CLOCKS_FC0_RESULT_KHZ_Lsb				5u
	/*  */
#define CLOCKS_FC0_RESULT_FRAC_Msb				4u
#define CLOCKS_FC0_RESULT_FRAC_Lsb				0u

	/* 0xA0: enable clock in wake mode */
	uint32_t volatile WAKE_EN0;
	/*  */
#define CLOCKS_WAKE_EN0_CLK_SYS_SRAM3				31u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_SYS_SRAM2				30u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_SYS_SRAM1				29u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_SYS_SRAM0				28u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_SYS_SPI1				27u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_PERI_SPI1				26u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_SYS_SPI0				25u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_PERI_SPI0				24u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_SYS_SIO				23u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_SYS_RTC				22u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_RTC_RTC				21u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_SYS_ROSC				20u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_SYS_ROM				19u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_SYS_RESETS				18u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_SYS_PWM				17u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_SYS_PSM				16u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_SYS_PLL_USB				15u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_SYS_PLL_SYS				14u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_SYS_PIO1				13u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_SYS_PIO0				12u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_SYS_PADS				11u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_SYS_VREG_AND_CHIP_RESET		10u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_SYS_JTAG				9u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_SYS_IO				8u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_SYS_I2C1				7u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_SYS_I2C0				6u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_SYS_DMA				5u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_SYS_BUSFABRIC			4u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_SYS_BUSCTRL				3u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_SYS_ADC				2u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_ADC_ADC				1u
	/*  */
#define CLOCKS_WAKE_EN0_CLK_SYS_CLOCKS				0u

	/* 0xA4: enable clock in wake mode */
	uint32_t volatile WAKE_EN1;
	/*  */
#define CLOCKS_WAKE_EN1_CLK_SYS_XOSC				14u
	/*  */
#define CLOCKS_WAKE_EN1_CLK_SYS_XIP				13u
	/*  */
#define CLOCKS_WAKE_EN1_CLK_SYS_WATCHDOG			12u
	/*  */
#define CLOCKS_WAKE_EN1_CLK_USB_USBCTRL				11u
	/*  */
#define CLOCKS_WAKE_EN1_CLK_SYS_USBCTRL				10u
	/*  */
#define CLOCKS_WAKE_EN1_CLK_SYS_UART1				9u
	/*  */
#define CLOCKS_WAKE_EN1_CLK_PERI_UART1				8u
	/*  */
#define CLOCKS_WAKE_EN1_CLK_SYS_UART0				7u
	/*  */
#define CLOCKS_WAKE_EN1_CLK_PERI_UART0				6u
	/*  */
#define CLOCKS_WAKE_EN1_CLK_SYS_TIMER				5u
	/*  */
#define CLOCKS_WAKE_EN1_CLK_SYS_TBMAN				4u
	/*  */
#define CLOCKS_WAKE_EN1_CLK_SYS_SYSINFO				3u
	/*  */
#define CLOCKS_WAKE_EN1_CLK_SYS_SYSCFG				2u
	/*  */
#define CLOCKS_WAKE_EN1_CLK_SYS_SRAM5				1u
	/*  */
#define CLOCKS_WAKE_EN1_CLK_SYS_SRAM4				0u

	/* 0xA8: enable clock in sleep mode */
	uint32_t volatile SLEEP_EN0;
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_SYS_SRAM3				31u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_SYS_SRAM2				30u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_SYS_SRAM1				29u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_SYS_SRAM0				28u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_SYS_SPI1				27u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_PERI_SPI1				26u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_SYS_SPI0				25u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_PERI_SPI0				24u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_SYS_SIO				23u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_SYS_RTC				22u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_RTC_RTC				21u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_SYS_ROSC				20u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_SYS_ROM				19u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_SYS_RESETS				18u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_SYS_PWM				17u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_SYS_PSM				16u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_SYS_PLL_USB			15u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_SYS_PLL_SYS			14u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_SYS_PIO1				13u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_SYS_PIO0				12u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_SYS_PADS				11u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_SYS_VREG_AND_CHIP_RESET		10u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_SYS_JTAG				9u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_SYS_IO				8u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_SYS_I2C1				7u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_SYS_I2C0				6u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_SYS_DMA				5u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_SYS_BUSFABRIC			4u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_SYS_BUSCTRL			3u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_SYS_ADC				2u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_ADC_ADC				1u
	/*  */
#define CLOCKS_SLEEP_EN0_CLK_SYS_CLOCKS				0u

	/* 0xAC: enable clock in sleep mode */
	uint32_t volatile SLEEP_EN1;
	/*  */
#define CLOCKS_SLEEP_EN1_CLK_SYS_XOSC				14u
	/*  */
#define CLOCKS_SLEEP_EN1_CLK_SYS_XIP				13u
	/*  */
#define CLOCKS_SLEEP_EN1_CLK_SYS_WATCHDOG			12u
	/*  */
#define CLOCKS_SLEEP_EN1_CLK_USB_USBCTRL			11u
	/*  */
#define CLOCKS_SLEEP_EN1_CLK_SYS_USBCTRL			10u
	/*  */
#define CLOCKS_SLEEP_EN1_CLK_SYS_UART1				9u
	/*  */
#define CLOCKS_SLEEP_EN1_CLK_PERI_UART1				8u
	/*  */
#define CLOCKS_SLEEP_EN1_CLK_SYS_UART0				7u
	/*  */
#define CLOCKS_SLEEP_EN1_CLK_PERI_UART0				6u
	/*  */
#define CLOCKS_SLEEP_EN1_CLK_SYS_TIMER				5u
	/*  */
#define CLOCKS_SLEEP_EN1_CLK_SYS_TBMAN				4u
	/*  */
#define CLOCKS_SLEEP_EN1_CLK_SYS_SYSINFO			3u
	/*  */
#define CLOCKS_SLEEP_EN1_CLK_SYS_SYSCFG				2u
	/*  */
#define CLOCKS_SLEEP_EN1_CLK_SYS_SRAM5				1u
	/*  */
#define CLOCKS_SLEEP_EN1_CLK_SYS_SRAM4				0u

	/* 0xB0: indicates the state of the clock enable */
	uint32_t volatile ENABLED0;
	/*  */
#define CLOCKS_ENABLED0_CLK_SYS_SRAM3				31u
	/*  */
#define CLOCKS_ENABLED0_CLK_SYS_SRAM2				30u
	/*  */
#define CLOCKS_ENABLED0_CLK_SYS_SRAM1				29u
	/*  */
#define CLOCKS_ENABLED0_CLK_SYS_SRAM0				28u
	/*  */
#define CLOCKS_ENABLED0_CLK_SYS_SPI1				27u
	/*  */
#define CLOCKS_ENABLED0_CLK_PERI_SPI1				26u
	/*  */
#define CLOCKS_ENABLED0_CLK_SYS_SPI0				25u
	/*  */
#define CLOCKS_ENABLED0_CLK_PERI_SPI0				24u
	/*  */
#define CLOCKS_ENABLED0_CLK_SYS_SIO				23u
	/*  */
#define CLOCKS_ENABLED0_CLK_SYS_RTC				22u
	/*  */
#define CLOCKS_ENABLED0_CLK_RTC_RTC				21u
	/*  */
#define CLOCKS_ENABLED0_CLK_SYS_ROSC				20u
	/*  */
#define CLOCKS_ENABLED0_CLK_SYS_ROM				19u
	/*  */
#define CLOCKS_ENABLED0_CLK_SYS_RESETS				18u
	/*  */
#define CLOCKS_ENABLED0_CLK_SYS_PWM				17u
	/*  */
#define CLOCKS_ENABLED0_CLK_SYS_PSM				16u
	/*  */
#define CLOCKS_ENABLED0_CLK_SYS_PLL_USB				15u
	/*  */
#define CLOCKS_ENABLED0_CLK_SYS_PLL_SYS				14u
	/*  */
#define CLOCKS_ENABLED0_CLK_SYS_PIO1				13u
	/*  */
#define CLOCKS_ENABLED0_CLK_SYS_PIO0				12u
	/*  */
#define CLOCKS_ENABLED0_CLK_SYS_PADS				11u
	/*  */
#define CLOCKS_ENABLED0_CLK_SYS_VREG_AND_CHIP_RESET		10u
	/*  */
#define CLOCKS_ENABLED0_CLK_SYS_JTAG				9u
	/*  */
#define CLOCKS_ENABLED0_CLK_SYS_IO				8u
	/*  */
#define CLOCKS_ENABLED0_CLK_SYS_I2C1				7u
	/*  */
#define CLOCKS_ENABLED0_CLK_SYS_I2C0				6u
	/*  */
#define CLOCKS_ENABLED0_CLK_SYS_DMA				5u
	/*  */
#define CLOCKS_ENABLED0_CLK_SYS_BUSFABRIC			4u
	/*  */
#define CLOCKS_ENABLED0_CLK_SYS_BUSCTRL				3u
	/*  */
#define CLOCKS_ENABLED0_CLK_SYS_ADC				2u
	/*  */
#define CLOCKS_ENABLED0_CLK_ADC_ADC				1u
	/*  */
#define CLOCKS_ENABLED0_CLK_SYS_CLOCKS				0u

	/* 0xB4: indicates the state of the clock enable */
	uint32_t volatile ENABLED1;
	/*  */
#define CLOCKS_ENABLED1_CLK_SYS_XOSC				14u
	/*  */
#define CLOCKS_ENABLED1_CLK_SYS_XIP				13u
	/*  */
#define CLOCKS_ENABLED1_CLK_SYS_WATCHDOG			12u
	/*  */
#define CLOCKS_ENABLED1_CLK_USB_USBCTRL				11u
	/*  */
#define CLOCKS_ENABLED1_CLK_SYS_USBCTRL				10u
	/*  */
#define CLOCKS_ENABLED1_CLK_SYS_UART1				9u
	/*  */
#define CLOCKS_ENABLED1_CLK_PERI_UART1				8u
	/*  */
#define CLOCKS_ENABLED1_CLK_SYS_UART0				7u
	/*  */
#define CLOCKS_ENABLED1_CLK_PERI_UART0				6u
	/*  */
#define CLOCKS_ENABLED1_CLK_SYS_TIMER				5u
	/*  */
#define CLOCKS_ENABLED1_CLK_SYS_TBMAN				4u
	/*  */
#define CLOCKS_ENABLED1_CLK_SYS_SYSINFO				3u
	/*  */
#define CLOCKS_ENABLED1_CLK_SYS_SYSCFG				2u
	/*  */
#define CLOCKS_ENABLED1_CLK_SYS_SRAM5				1u
	/*  */
#define CLOCKS_ENABLED1_CLK_SYS_SRAM4				0u

	/* 0xB8: Raw Interrupts */
	uint32_t volatile INTR;
	/*  */
#define CLOCKS_INTR_CLK_SYS_RESUS				0u

	/* 0xBC: Interrupt Enable */
	uint32_t volatile INTE;
	/*  */
#define CLOCKS_INTE_CLK_SYS_RESUS				0u

	/* 0xC0: Interrupt Force */
	uint32_t volatile INTF;
	/*  */
#define CLOCKS_INTF_CLK_SYS_RESUS				0u

	/* 0xC4: Interrupt status after masking & forcing */
	uint32_t volatile INTS;
	/*  */
#define CLOCKS_INTS_CLK_SYS_RESUS				0u

};


#define RESETS ((struct sdk_resets *)0x4000C000)

struct sdk_resets {

	/* 0x00: Reset control. */
	uint32_t volatile RESET;
	/*  */
#define RESETS_RESET_USBCTRL					24u
	/*  */
#define RESETS_RESET_UART1					23u
	/*  */
#define RESETS_RESET_UART0					22u
	/*  */
#define RESETS_RESET_TIMER					21u
	/*  */
#define RESETS_RESET_TBMAN					20u
	/*  */
#define RESETS_RESET_SYSINFO					19u
	/*  */
#define RESETS_RESET_SYSCFG					18u
	/*  */
#define RESETS_RESET_SPI1					17u
	/*  */
#define RESETS_RESET_SPI0					16u
	/*  */
#define RESETS_RESET_RTC					15u
	/*  */
#define RESETS_RESET_PWM					14u
	/*  */
#define RESETS_RESET_PLL_USB					13u
	/*  */
#define RESETS_RESET_PLL_SYS					12u
	/*  */
#define RESETS_RESET_PIO1					11u
	/*  */
#define RESETS_RESET_PIO0					10u
	/*  */
#define RESETS_RESET_PADS_QSPI					9u
	/*  */
#define RESETS_RESET_PADS_BANK0					8u
	/*  */
#define RESETS_RESET_JTAG					7u
	/*  */
#define RESETS_RESET_IO_QSPI					6u
	/*  */
#define RESETS_RESET_IO_BANK0					5u
	/*  */
#define RESETS_RESET_I2C1					4u
	/*  */
#define RESETS_RESET_I2C0					3u
	/*  */
#define RESETS_RESET_DMA					2u
	/*  */
#define RESETS_RESET_BUSCTRL					1u
	/*  */
#define RESETS_RESET_ADC					0u

	/* 0x04: Watchdog select. */
	uint32_t volatile WDSEL;
	/*  */
#define RESETS_WDSEL_USBCTRL					24u
	/*  */
#define RESETS_WDSEL_UART1					23u
	/*  */
#define RESETS_WDSEL_UART0					22u
	/*  */
#define RESETS_WDSEL_TIMER					21u
	/*  */
#define RESETS_WDSEL_TBMAN					20u
	/*  */
#define RESETS_WDSEL_SYSINFO					19u
	/*  */
#define RESETS_WDSEL_SYSCFG					18u
	/*  */
#define RESETS_WDSEL_SPI1					17u
	/*  */
#define RESETS_WDSEL_SPI0					16u
	/*  */
#define RESETS_WDSEL_RTC					15u
	/*  */
#define RESETS_WDSEL_PWM					14u
	/*  */
#define RESETS_WDSEL_PLL_USB					13u
	/*  */
#define RESETS_WDSEL_PLL_SYS					12u
	/*  */
#define RESETS_WDSEL_PIO1					11u
	/*  */
#define RESETS_WDSEL_PIO0					10u
	/*  */
#define RESETS_WDSEL_PADS_QSPI					9u
	/*  */
#define RESETS_WDSEL_PADS_BANK0					8u
	/*  */
#define RESETS_WDSEL_JTAG					7u
	/*  */
#define RESETS_WDSEL_IO_QSPI					6u
	/*  */
#define RESETS_WDSEL_IO_BANK0					5u
	/*  */
#define RESETS_WDSEL_I2C1					4u
	/*  */
#define RESETS_WDSEL_I2C0					3u
	/*  */
#define RESETS_WDSEL_DMA					2u
	/*  */
#define RESETS_WDSEL_BUSCTRL					1u
	/*  */
#define RESETS_WDSEL_ADC					0u

	/* 0x08: Reset done. */
	uint32_t volatile RESET_DONE;
	/*  */
#define RESETS_RESET_DONE_USBCTRL				24u
	/*  */
#define RESETS_RESET_DONE_UART1					23u
	/*  */
#define RESETS_RESET_DONE_UART0					22u
	/*  */
#define RESETS_RESET_DONE_TIMER					21u
	/*  */
#define RESETS_RESET_DONE_TBMAN					20u
	/*  */
#define RESETS_RESET_DONE_SYSINFO				19u
	/*  */
#define RESETS_RESET_DONE_SYSCFG				18u
	/*  */
#define RESETS_RESET_DONE_SPI1					17u
	/*  */
#define RESETS_RESET_DONE_SPI0					16u
	/*  */
#define RESETS_RESET_DONE_RTC					15u
	/*  */
#define RESETS_RESET_DONE_PWM					14u
	/*  */
#define RESETS_RESET_DONE_PLL_USB				13u
	/*  */
#define RESETS_RESET_DONE_PLL_SYS				12u
	/*  */
#define RESETS_RESET_DONE_PIO1					11u
	/*  */
#define RESETS_RESET_DONE_PIO0					10u
	/*  */
#define RESETS_RESET_DONE_PADS_QSPI				9u
	/*  */
#define RESETS_RESET_DONE_PADS_BANK0				8u
	/*  */
#define RESETS_RESET_DONE_JTAG					7u
	/*  */
#define RESETS_RESET_DONE_IO_QSPI				6u
	/*  */
#define RESETS_RESET_DONE_IO_BANK0				5u
	/*  */
#define RESETS_RESET_DONE_I2C1					4u
	/*  */
#define RESETS_RESET_DONE_I2C0					3u
	/*  */
#define RESETS_RESET_DONE_DMA					2u
	/*  */
#define RESETS_RESET_DONE_BUSCTRL				1u
	/*  */
#define RESETS_RESET_DONE_ADC					0u

};


#define PSM ((struct sdk_psm *)0x40010000)

struct sdk_psm {

	/* 0x00: Force block out of reset (i.e. power it on) */
	uint32_t volatile FRCE_ON;
	/*  */
#define PSM_FRCE_ON_PROC1					16u
	/*  */
#define PSM_FRCE_ON_PROC0					15u
	/*  */
#define PSM_FRCE_ON_SIO						14u
	/*  */
#define PSM_FRCE_ON_VREG_AND_CHIP_RESET				13u
	/*  */
#define PSM_FRCE_ON_XIP						12u
	/*  */
#define PSM_FRCE_ON_SRAM5					11u
	/*  */
#define PSM_FRCE_ON_SRAM4					10u
	/*  */
#define PSM_FRCE_ON_SRAM3					9u
	/*  */
#define PSM_FRCE_ON_SRAM2					8u
	/*  */
#define PSM_FRCE_ON_SRAM1					7u
	/*  */
#define PSM_FRCE_ON_SRAM0					6u
	/*  */
#define PSM_FRCE_ON_ROM						5u
	/*  */
#define PSM_FRCE_ON_BUSFABRIC					4u
	/*  */
#define PSM_FRCE_ON_RESETS					3u
	/*  */
#define PSM_FRCE_ON_CLOCKS					2u
	/*  */
#define PSM_FRCE_ON_XOSC					1u
	/*  */
#define PSM_FRCE_ON_ROSC					0u

	/* 0x04: Force into reset (i.e. power it off) */
	uint32_t volatile FRCE_OFF;
	/*  */
#define PSM_FRCE_OFF_PROC1					16u
	/*  */
#define PSM_FRCE_OFF_PROC0					15u
	/*  */
#define PSM_FRCE_OFF_SIO					14u
	/*  */
#define PSM_FRCE_OFF_VREG_AND_CHIP_RESET			13u
	/*  */
#define PSM_FRCE_OFF_XIP					12u
	/*  */
#define PSM_FRCE_OFF_SRAM5					11u
	/*  */
#define PSM_FRCE_OFF_SRAM4					10u
	/*  */
#define PSM_FRCE_OFF_SRAM3					9u
	/*  */
#define PSM_FRCE_OFF_SRAM2					8u
	/*  */
#define PSM_FRCE_OFF_SRAM1					7u
	/*  */
#define PSM_FRCE_OFF_SRAM0					6u
	/*  */
#define PSM_FRCE_OFF_ROM					5u
	/*  */
#define PSM_FRCE_OFF_BUSFABRIC					4u
	/*  */
#define PSM_FRCE_OFF_RESETS					3u
	/*  */
#define PSM_FRCE_OFF_CLOCKS					2u
	/*  */
#define PSM_FRCE_OFF_XOSC					1u
	/*  */
#define PSM_FRCE_OFF_ROSC					0u

	/* 0x08: Set to 1 if this peripheral should be reset when the watchdog fires. */
	uint32_t volatile WDSEL;
	/*  */
#define PSM_WDSEL_PROC1						16u
	/*  */
#define PSM_WDSEL_PROC0						15u
	/*  */
#define PSM_WDSEL_SIO						14u
	/*  */
#define PSM_WDSEL_VREG_AND_CHIP_RESET				13u
	/*  */
#define PSM_WDSEL_XIP						12u
	/*  */
#define PSM_WDSEL_SRAM5						11u
	/*  */
#define PSM_WDSEL_SRAM4						10u
	/*  */
#define PSM_WDSEL_SRAM3						9u
	/*  */
#define PSM_WDSEL_SRAM2						8u
	/*  */
#define PSM_WDSEL_SRAM1						7u
	/*  */
#define PSM_WDSEL_SRAM0						6u
	/*  */
#define PSM_WDSEL_ROM						5u
	/*  */
#define PSM_WDSEL_BUSFABRIC					4u
	/*  */
#define PSM_WDSEL_RESETS					3u
	/*  */
#define PSM_WDSEL_CLOCKS					2u
	/*  */
#define PSM_WDSEL_XOSC						1u
	/*  */
#define PSM_WDSEL_ROSC						0u

	/* 0x0C: Indicates the peripheral's registers are ready to access. */
	uint32_t volatile DONE;
	/*  */
#define PSM_DONE_PROC1						16u
	/*  */
#define PSM_DONE_PROC0						15u
	/*  */
#define PSM_DONE_SIO						14u
	/*  */
#define PSM_DONE_VREG_AND_CHIP_RESET				13u
	/*  */
#define PSM_DONE_XIP						12u
	/*  */
#define PSM_DONE_SRAM5						11u
	/*  */
#define PSM_DONE_SRAM4						10u
	/*  */
#define PSM_DONE_SRAM3						9u
	/*  */
#define PSM_DONE_SRAM2						8u
	/*  */
#define PSM_DONE_SRAM1						7u
	/*  */
#define PSM_DONE_SRAM0						6u
	/*  */
#define PSM_DONE_ROM						5u
	/*  */
#define PSM_DONE_BUSFABRIC					4u
	/*  */
#define PSM_DONE_RESETS						3u
	/*  */
#define PSM_DONE_CLOCKS						2u
	/*  */
#define PSM_DONE_XOSC						1u
	/*  */
#define PSM_DONE_ROSC						0u

};


#define IO_BANK0 ((struct sdk_io_bank0 *)0x40014000)

struct sdk_io_bank0 {

	/* 0x00: GPIO status */
	uint32_t volatile GPIO0_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO0_STATUS_IRQTOPROC				26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO0_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO0_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO0_STATUS_INFROMPAD				17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO0_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO0_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO0_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO0_STATUS_OUTFROMPERI			8u

	/* 0x04: GPIO control including function select and overrides. */
	uint32_t volatile GPIO0_CTRL;
	/*  */
#define IO_BANK0_GPIO0_CTRL_IRQOVER_Msb				29u
#define IO_BANK0_GPIO0_CTRL_IRQOVER_Lsb				28u
#define IO_BANK0_GPIO0_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO0_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO0_CTRL_IRQOVER_LOW				2u
#define IO_BANK0_GPIO0_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO0_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO0_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO0_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO0_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO0_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO0_CTRL_INOVER_HIGH				3u
	/*  */
#define IO_BANK0_GPIO0_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO0_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO0_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO0_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO0_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO0_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO0_CTRL_OUTOVER_Msb				9u
#define IO_BANK0_GPIO0_CTRL_OUTOVER_Lsb				8u
#define IO_BANK0_GPIO0_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO0_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO0_CTRL_OUTOVER_LOW				2u
#define IO_BANK0_GPIO0_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO0_CTRL_FUNCSEL_Msb				4u
#define IO_BANK0_GPIO0_CTRL_FUNCSEL_Lsb				0u
#define IO_BANK0_GPIO0_CTRL_FUNCSEL_JTAG_TCK			0u
#define IO_BANK0_GPIO0_CTRL_FUNCSEL_SPI0_RX			1u
#define IO_BANK0_GPIO0_CTRL_FUNCSEL_UART0_TX			2u
#define IO_BANK0_GPIO0_CTRL_FUNCSEL_I2C0_SDA			3u
#define IO_BANK0_GPIO0_CTRL_FUNCSEL_PWM_A_0			4u
#define IO_BANK0_GPIO0_CTRL_FUNCSEL_SIO_0			5u
#define IO_BANK0_GPIO0_CTRL_FUNCSEL_PIO0_0			6u
#define IO_BANK0_GPIO0_CTRL_FUNCSEL_PIO1_0			7u
#define IO_BANK0_GPIO0_CTRL_FUNCSEL_USB_MUXING_OVERCURR_DETECT	9u
#define IO_BANK0_GPIO0_CTRL_FUNCSEL_NULL			31u

	/* 0x08: GPIO status */
	uint32_t volatile GPIO1_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO1_STATUS_IRQTOPROC				26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO1_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO1_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO1_STATUS_INFROMPAD				17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO1_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO1_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO1_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO1_STATUS_OUTFROMPERI			8u

	/* 0x0C: GPIO control including function select and overrides. */
	uint32_t volatile GPIO1_CTRL;
	/*  */
#define IO_BANK0_GPIO1_CTRL_IRQOVER_Msb				29u
#define IO_BANK0_GPIO1_CTRL_IRQOVER_Lsb				28u
#define IO_BANK0_GPIO1_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO1_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO1_CTRL_IRQOVER_LOW				2u
#define IO_BANK0_GPIO1_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO1_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO1_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO1_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO1_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO1_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO1_CTRL_INOVER_HIGH				3u
	/*  */
#define IO_BANK0_GPIO1_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO1_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO1_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO1_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO1_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO1_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO1_CTRL_OUTOVER_Msb				9u
#define IO_BANK0_GPIO1_CTRL_OUTOVER_Lsb				8u
#define IO_BANK0_GPIO1_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO1_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO1_CTRL_OUTOVER_LOW				2u
#define IO_BANK0_GPIO1_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO1_CTRL_FUNCSEL_Msb				4u
#define IO_BANK0_GPIO1_CTRL_FUNCSEL_Lsb				0u
#define IO_BANK0_GPIO1_CTRL_FUNCSEL_JTAG_TMS			0u
#define IO_BANK0_GPIO1_CTRL_FUNCSEL_SPI0_SS_N			1u
#define IO_BANK0_GPIO1_CTRL_FUNCSEL_UART0_RX			2u
#define IO_BANK0_GPIO1_CTRL_FUNCSEL_I2C0_SCL			3u
#define IO_BANK0_GPIO1_CTRL_FUNCSEL_PWM_B_0			4u
#define IO_BANK0_GPIO1_CTRL_FUNCSEL_SIO_1			5u
#define IO_BANK0_GPIO1_CTRL_FUNCSEL_PIO0_1			6u
#define IO_BANK0_GPIO1_CTRL_FUNCSEL_PIO1_1			7u
#define IO_BANK0_GPIO1_CTRL_FUNCSEL_USB_MUXING_VBUS_DETECT	9u
#define IO_BANK0_GPIO1_CTRL_FUNCSEL_NULL			31u

	/* 0x10: GPIO status */
	uint32_t volatile GPIO2_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO2_STATUS_IRQTOPROC				26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO2_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO2_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO2_STATUS_INFROMPAD				17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO2_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO2_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO2_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO2_STATUS_OUTFROMPERI			8u

	/* 0x14: GPIO control including function select and overrides. */
	uint32_t volatile GPIO2_CTRL;
	/*  */
#define IO_BANK0_GPIO2_CTRL_IRQOVER_Msb				29u
#define IO_BANK0_GPIO2_CTRL_IRQOVER_Lsb				28u
#define IO_BANK0_GPIO2_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO2_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO2_CTRL_IRQOVER_LOW				2u
#define IO_BANK0_GPIO2_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO2_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO2_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO2_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO2_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO2_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO2_CTRL_INOVER_HIGH				3u
	/*  */
#define IO_BANK0_GPIO2_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO2_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO2_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO2_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO2_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO2_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO2_CTRL_OUTOVER_Msb				9u
#define IO_BANK0_GPIO2_CTRL_OUTOVER_Lsb				8u
#define IO_BANK0_GPIO2_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO2_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO2_CTRL_OUTOVER_LOW				2u
#define IO_BANK0_GPIO2_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO2_CTRL_FUNCSEL_Msb				4u
#define IO_BANK0_GPIO2_CTRL_FUNCSEL_Lsb				0u
#define IO_BANK0_GPIO2_CTRL_FUNCSEL_JTAG_TDI			0u
#define IO_BANK0_GPIO2_CTRL_FUNCSEL_SPI0_SCLK			1u
#define IO_BANK0_GPIO2_CTRL_FUNCSEL_UART0_CTS			2u
#define IO_BANK0_GPIO2_CTRL_FUNCSEL_I2C1_SDA			3u
#define IO_BANK0_GPIO2_CTRL_FUNCSEL_PWM_A_1			4u
#define IO_BANK0_GPIO2_CTRL_FUNCSEL_SIO_2			5u
#define IO_BANK0_GPIO2_CTRL_FUNCSEL_PIO0_2			6u
#define IO_BANK0_GPIO2_CTRL_FUNCSEL_PIO1_2			7u
#define IO_BANK0_GPIO2_CTRL_FUNCSEL_USB_MUXING_VBUS_EN		9u
#define IO_BANK0_GPIO2_CTRL_FUNCSEL_NULL			31u

	/* 0x18: GPIO status */
	uint32_t volatile GPIO3_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO3_STATUS_IRQTOPROC				26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO3_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO3_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO3_STATUS_INFROMPAD				17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO3_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO3_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO3_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO3_STATUS_OUTFROMPERI			8u

	/* 0x1C: GPIO control including function select and overrides. */
	uint32_t volatile GPIO3_CTRL;
	/*  */
#define IO_BANK0_GPIO3_CTRL_IRQOVER_Msb				29u
#define IO_BANK0_GPIO3_CTRL_IRQOVER_Lsb				28u
#define IO_BANK0_GPIO3_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO3_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO3_CTRL_IRQOVER_LOW				2u
#define IO_BANK0_GPIO3_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO3_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO3_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO3_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO3_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO3_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO3_CTRL_INOVER_HIGH				3u
	/*  */
#define IO_BANK0_GPIO3_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO3_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO3_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO3_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO3_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO3_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO3_CTRL_OUTOVER_Msb				9u
#define IO_BANK0_GPIO3_CTRL_OUTOVER_Lsb				8u
#define IO_BANK0_GPIO3_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO3_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO3_CTRL_OUTOVER_LOW				2u
#define IO_BANK0_GPIO3_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO3_CTRL_FUNCSEL_Msb				4u
#define IO_BANK0_GPIO3_CTRL_FUNCSEL_Lsb				0u
#define IO_BANK0_GPIO3_CTRL_FUNCSEL_JTAG_TDO			0u
#define IO_BANK0_GPIO3_CTRL_FUNCSEL_SPI0_TX			1u
#define IO_BANK0_GPIO3_CTRL_FUNCSEL_UART0_RTS			2u
#define IO_BANK0_GPIO3_CTRL_FUNCSEL_I2C1_SCL			3u
#define IO_BANK0_GPIO3_CTRL_FUNCSEL_PWM_B_1			4u
#define IO_BANK0_GPIO3_CTRL_FUNCSEL_SIO_3			5u
#define IO_BANK0_GPIO3_CTRL_FUNCSEL_PIO0_3			6u
#define IO_BANK0_GPIO3_CTRL_FUNCSEL_PIO1_3			7u
#define IO_BANK0_GPIO3_CTRL_FUNCSEL_USB_MUXING_OVERCURR_DETECT	9u
#define IO_BANK0_GPIO3_CTRL_FUNCSEL_NULL			31u

	/* 0x20: GPIO status */
	uint32_t volatile GPIO4_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO4_STATUS_IRQTOPROC				26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO4_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO4_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO4_STATUS_INFROMPAD				17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO4_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO4_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO4_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO4_STATUS_OUTFROMPERI			8u

	/* 0x24: GPIO control including function select and overrides. */
	uint32_t volatile GPIO4_CTRL;
	/*  */
#define IO_BANK0_GPIO4_CTRL_IRQOVER_Msb				29u
#define IO_BANK0_GPIO4_CTRL_IRQOVER_Lsb				28u
#define IO_BANK0_GPIO4_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO4_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO4_CTRL_IRQOVER_LOW				2u
#define IO_BANK0_GPIO4_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO4_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO4_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO4_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO4_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO4_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO4_CTRL_INOVER_HIGH				3u
	/*  */
#define IO_BANK0_GPIO4_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO4_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO4_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO4_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO4_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO4_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO4_CTRL_OUTOVER_Msb				9u
#define IO_BANK0_GPIO4_CTRL_OUTOVER_Lsb				8u
#define IO_BANK0_GPIO4_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO4_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO4_CTRL_OUTOVER_LOW				2u
#define IO_BANK0_GPIO4_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO4_CTRL_FUNCSEL_Msb				4u
#define IO_BANK0_GPIO4_CTRL_FUNCSEL_Lsb				0u
#define IO_BANK0_GPIO4_CTRL_FUNCSEL_SPI0_RX			1u
#define IO_BANK0_GPIO4_CTRL_FUNCSEL_UART1_TX			2u
#define IO_BANK0_GPIO4_CTRL_FUNCSEL_I2C0_SDA			3u
#define IO_BANK0_GPIO4_CTRL_FUNCSEL_PWM_A_2			4u
#define IO_BANK0_GPIO4_CTRL_FUNCSEL_SIO_4			5u
#define IO_BANK0_GPIO4_CTRL_FUNCSEL_PIO0_4			6u
#define IO_BANK0_GPIO4_CTRL_FUNCSEL_PIO1_4			7u
#define IO_BANK0_GPIO4_CTRL_FUNCSEL_USB_MUXING_VBUS_DETECT	9u
#define IO_BANK0_GPIO4_CTRL_FUNCSEL_NULL			31u

	/* 0x28: GPIO status */
	uint32_t volatile GPIO5_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO5_STATUS_IRQTOPROC				26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO5_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO5_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO5_STATUS_INFROMPAD				17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO5_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO5_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO5_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO5_STATUS_OUTFROMPERI			8u

	/* 0x2C: GPIO control including function select and overrides. */
	uint32_t volatile GPIO5_CTRL;
	/*  */
#define IO_BANK0_GPIO5_CTRL_IRQOVER_Msb				29u
#define IO_BANK0_GPIO5_CTRL_IRQOVER_Lsb				28u
#define IO_BANK0_GPIO5_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO5_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO5_CTRL_IRQOVER_LOW				2u
#define IO_BANK0_GPIO5_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO5_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO5_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO5_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO5_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO5_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO5_CTRL_INOVER_HIGH				3u
	/*  */
#define IO_BANK0_GPIO5_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO5_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO5_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO5_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO5_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO5_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO5_CTRL_OUTOVER_Msb				9u
#define IO_BANK0_GPIO5_CTRL_OUTOVER_Lsb				8u
#define IO_BANK0_GPIO5_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO5_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO5_CTRL_OUTOVER_LOW				2u
#define IO_BANK0_GPIO5_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO5_CTRL_FUNCSEL_Msb				4u
#define IO_BANK0_GPIO5_CTRL_FUNCSEL_Lsb				0u
#define IO_BANK0_GPIO5_CTRL_FUNCSEL_SPI0_SS_N			1u
#define IO_BANK0_GPIO5_CTRL_FUNCSEL_UART1_RX			2u
#define IO_BANK0_GPIO5_CTRL_FUNCSEL_I2C0_SCL			3u
#define IO_BANK0_GPIO5_CTRL_FUNCSEL_PWM_B_2			4u
#define IO_BANK0_GPIO5_CTRL_FUNCSEL_SIO_5			5u
#define IO_BANK0_GPIO5_CTRL_FUNCSEL_PIO0_5			6u
#define IO_BANK0_GPIO5_CTRL_FUNCSEL_PIO1_5			7u
#define IO_BANK0_GPIO5_CTRL_FUNCSEL_USB_MUXING_VBUS_EN		9u
#define IO_BANK0_GPIO5_CTRL_FUNCSEL_NULL			31u

	/* 0x30: GPIO status */
	uint32_t volatile GPIO6_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO6_STATUS_IRQTOPROC				26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO6_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO6_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO6_STATUS_INFROMPAD				17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO6_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO6_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO6_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO6_STATUS_OUTFROMPERI			8u

	/* 0x34: GPIO control including function select and overrides. */
	uint32_t volatile GPIO6_CTRL;
	/*  */
#define IO_BANK0_GPIO6_CTRL_IRQOVER_Msb				29u
#define IO_BANK0_GPIO6_CTRL_IRQOVER_Lsb				28u
#define IO_BANK0_GPIO6_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO6_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO6_CTRL_IRQOVER_LOW				2u
#define IO_BANK0_GPIO6_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO6_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO6_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO6_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO6_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO6_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO6_CTRL_INOVER_HIGH				3u
	/*  */
#define IO_BANK0_GPIO6_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO6_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO6_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO6_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO6_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO6_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO6_CTRL_OUTOVER_Msb				9u
#define IO_BANK0_GPIO6_CTRL_OUTOVER_Lsb				8u
#define IO_BANK0_GPIO6_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO6_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO6_CTRL_OUTOVER_LOW				2u
#define IO_BANK0_GPIO6_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO6_CTRL_FUNCSEL_Msb				4u
#define IO_BANK0_GPIO6_CTRL_FUNCSEL_Lsb				0u
#define IO_BANK0_GPIO6_CTRL_FUNCSEL_SPI0_SCLK			1u
#define IO_BANK0_GPIO6_CTRL_FUNCSEL_UART1_CTS			2u
#define IO_BANK0_GPIO6_CTRL_FUNCSEL_I2C1_SDA			3u
#define IO_BANK0_GPIO6_CTRL_FUNCSEL_PWM_A_3			4u
#define IO_BANK0_GPIO6_CTRL_FUNCSEL_SIO_6			5u
#define IO_BANK0_GPIO6_CTRL_FUNCSEL_PIO0_6			6u
#define IO_BANK0_GPIO6_CTRL_FUNCSEL_PIO1_6			7u
#define IO_BANK0_GPIO6_CTRL_FUNCSEL_USB_MUXING_EXTPHY_SOFTCON	8u
#define IO_BANK0_GPIO6_CTRL_FUNCSEL_USB_MUXING_OVERCURR_DETECT	9u
#define IO_BANK0_GPIO6_CTRL_FUNCSEL_NULL			31u

	/* 0x38: GPIO status */
	uint32_t volatile GPIO7_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO7_STATUS_IRQTOPROC				26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO7_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO7_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO7_STATUS_INFROMPAD				17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO7_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO7_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO7_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO7_STATUS_OUTFROMPERI			8u

	/* 0x3C: GPIO control including function select and overrides. */
	uint32_t volatile GPIO7_CTRL;
	/*  */
#define IO_BANK0_GPIO7_CTRL_IRQOVER_Msb				29u
#define IO_BANK0_GPIO7_CTRL_IRQOVER_Lsb				28u
#define IO_BANK0_GPIO7_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO7_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO7_CTRL_IRQOVER_LOW				2u
#define IO_BANK0_GPIO7_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO7_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO7_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO7_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO7_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO7_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO7_CTRL_INOVER_HIGH				3u
	/*  */
#define IO_BANK0_GPIO7_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO7_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO7_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO7_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO7_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO7_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO7_CTRL_OUTOVER_Msb				9u
#define IO_BANK0_GPIO7_CTRL_OUTOVER_Lsb				8u
#define IO_BANK0_GPIO7_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO7_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO7_CTRL_OUTOVER_LOW				2u
#define IO_BANK0_GPIO7_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO7_CTRL_FUNCSEL_Msb				4u
#define IO_BANK0_GPIO7_CTRL_FUNCSEL_Lsb				0u
#define IO_BANK0_GPIO7_CTRL_FUNCSEL_SPI0_TX			1u
#define IO_BANK0_GPIO7_CTRL_FUNCSEL_UART1_RTS			2u
#define IO_BANK0_GPIO7_CTRL_FUNCSEL_I2C1_SCL			3u
#define IO_BANK0_GPIO7_CTRL_FUNCSEL_PWM_B_3			4u
#define IO_BANK0_GPIO7_CTRL_FUNCSEL_SIO_7			5u
#define IO_BANK0_GPIO7_CTRL_FUNCSEL_PIO0_7			6u
#define IO_BANK0_GPIO7_CTRL_FUNCSEL_PIO1_7			7u
#define IO_BANK0_GPIO7_CTRL_FUNCSEL_USB_MUXING_EXTPHY_OE_N	8u
#define IO_BANK0_GPIO7_CTRL_FUNCSEL_USB_MUXING_VBUS_DETECT	9u
#define IO_BANK0_GPIO7_CTRL_FUNCSEL_NULL			31u

	/* 0x40: GPIO status */
	uint32_t volatile GPIO8_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO8_STATUS_IRQTOPROC				26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO8_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO8_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO8_STATUS_INFROMPAD				17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO8_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO8_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO8_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO8_STATUS_OUTFROMPERI			8u

	/* 0x44: GPIO control including function select and overrides. */
	uint32_t volatile GPIO8_CTRL;
	/*  */
#define IO_BANK0_GPIO8_CTRL_IRQOVER_Msb				29u
#define IO_BANK0_GPIO8_CTRL_IRQOVER_Lsb				28u
#define IO_BANK0_GPIO8_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO8_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO8_CTRL_IRQOVER_LOW				2u
#define IO_BANK0_GPIO8_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO8_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO8_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO8_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO8_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO8_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO8_CTRL_INOVER_HIGH				3u
	/*  */
#define IO_BANK0_GPIO8_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO8_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO8_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO8_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO8_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO8_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO8_CTRL_OUTOVER_Msb				9u
#define IO_BANK0_GPIO8_CTRL_OUTOVER_Lsb				8u
#define IO_BANK0_GPIO8_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO8_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO8_CTRL_OUTOVER_LOW				2u
#define IO_BANK0_GPIO8_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO8_CTRL_FUNCSEL_Msb				4u
#define IO_BANK0_GPIO8_CTRL_FUNCSEL_Lsb				0u
#define IO_BANK0_GPIO8_CTRL_FUNCSEL_SPI1_RX			1u
#define IO_BANK0_GPIO8_CTRL_FUNCSEL_UART1_TX			2u
#define IO_BANK0_GPIO8_CTRL_FUNCSEL_I2C0_SDA			3u
#define IO_BANK0_GPIO8_CTRL_FUNCSEL_PWM_A_4			4u
#define IO_BANK0_GPIO8_CTRL_FUNCSEL_SIO_8			5u
#define IO_BANK0_GPIO8_CTRL_FUNCSEL_PIO0_8			6u
#define IO_BANK0_GPIO8_CTRL_FUNCSEL_PIO1_8			7u
#define IO_BANK0_GPIO8_CTRL_FUNCSEL_USB_MUXING_EXTPHY_RCV	8u
#define IO_BANK0_GPIO8_CTRL_FUNCSEL_USB_MUXING_VBUS_EN		9u
#define IO_BANK0_GPIO8_CTRL_FUNCSEL_NULL			31u

	/* 0x48: GPIO status */
	uint32_t volatile GPIO9_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO9_STATUS_IRQTOPROC				26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO9_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO9_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO9_STATUS_INFROMPAD				17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO9_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO9_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO9_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO9_STATUS_OUTFROMPERI			8u

	/* 0x4C: GPIO control including function select and overrides. */
	uint32_t volatile GPIO9_CTRL;
	/*  */
#define IO_BANK0_GPIO9_CTRL_IRQOVER_Msb				29u
#define IO_BANK0_GPIO9_CTRL_IRQOVER_Lsb				28u
#define IO_BANK0_GPIO9_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO9_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO9_CTRL_IRQOVER_LOW				2u
#define IO_BANK0_GPIO9_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO9_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO9_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO9_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO9_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO9_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO9_CTRL_INOVER_HIGH				3u
	/*  */
#define IO_BANK0_GPIO9_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO9_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO9_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO9_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO9_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO9_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO9_CTRL_OUTOVER_Msb				9u
#define IO_BANK0_GPIO9_CTRL_OUTOVER_Lsb				8u
#define IO_BANK0_GPIO9_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO9_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO9_CTRL_OUTOVER_LOW				2u
#define IO_BANK0_GPIO9_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO9_CTRL_FUNCSEL_Msb				4u
#define IO_BANK0_GPIO9_CTRL_FUNCSEL_Lsb				0u
#define IO_BANK0_GPIO9_CTRL_FUNCSEL_SPI1_SS_N			1u
#define IO_BANK0_GPIO9_CTRL_FUNCSEL_UART1_RX			2u
#define IO_BANK0_GPIO9_CTRL_FUNCSEL_I2C0_SCL			3u
#define IO_BANK0_GPIO9_CTRL_FUNCSEL_PWM_B_4			4u
#define IO_BANK0_GPIO9_CTRL_FUNCSEL_SIO_9			5u
#define IO_BANK0_GPIO9_CTRL_FUNCSEL_PIO0_9			6u
#define IO_BANK0_GPIO9_CTRL_FUNCSEL_PIO1_9			7u
#define IO_BANK0_GPIO9_CTRL_FUNCSEL_USB_MUXING_EXTPHY_VP	8u
#define IO_BANK0_GPIO9_CTRL_FUNCSEL_USB_MUXING_OVERCURR_DETECT	9u
#define IO_BANK0_GPIO9_CTRL_FUNCSEL_NULL			31u

	/* 0x50: GPIO status */
	uint32_t volatile GPIO10_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO10_STATUS_IRQTOPROC			26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO10_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO10_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO10_STATUS_INFROMPAD			17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO10_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO10_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO10_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO10_STATUS_OUTFROMPERI			8u

	/* 0x54: GPIO control including function select and overrides. */
	uint32_t volatile GPIO10_CTRL;
	/*  */
#define IO_BANK0_GPIO10_CTRL_IRQOVER_Msb			29u
#define IO_BANK0_GPIO10_CTRL_IRQOVER_Lsb			28u
#define IO_BANK0_GPIO10_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO10_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO10_CTRL_IRQOVER_LOW			2u
#define IO_BANK0_GPIO10_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO10_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO10_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO10_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO10_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO10_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO10_CTRL_INOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO10_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO10_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO10_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO10_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO10_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO10_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO10_CTRL_OUTOVER_Msb			9u
#define IO_BANK0_GPIO10_CTRL_OUTOVER_Lsb			8u
#define IO_BANK0_GPIO10_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO10_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO10_CTRL_OUTOVER_LOW			2u
#define IO_BANK0_GPIO10_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO10_CTRL_FUNCSEL_Msb			4u
#define IO_BANK0_GPIO10_CTRL_FUNCSEL_Lsb			0u
#define IO_BANK0_GPIO10_CTRL_FUNCSEL_SPI1_SCLK			1u
#define IO_BANK0_GPIO10_CTRL_FUNCSEL_UART1_CTS			2u
#define IO_BANK0_GPIO10_CTRL_FUNCSEL_I2C1_SDA			3u
#define IO_BANK0_GPIO10_CTRL_FUNCSEL_PWM_A_5			4u
#define IO_BANK0_GPIO10_CTRL_FUNCSEL_SIO_10			5u
#define IO_BANK0_GPIO10_CTRL_FUNCSEL_PIO0_10			6u
#define IO_BANK0_GPIO10_CTRL_FUNCSEL_PIO1_10			7u
#define IO_BANK0_GPIO10_CTRL_FUNCSEL_USB_MUXING_EXTPHY_VM	8u
#define IO_BANK0_GPIO10_CTRL_FUNCSEL_USB_MUXING_VBUS_DETECT	9u
#define IO_BANK0_GPIO10_CTRL_FUNCSEL_NULL			31u

	/* 0x58: GPIO status */
	uint32_t volatile GPIO11_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO11_STATUS_IRQTOPROC			26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO11_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO11_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO11_STATUS_INFROMPAD			17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO11_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO11_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO11_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO11_STATUS_OUTFROMPERI			8u

	/* 0x5C: GPIO control including function select and overrides. */
	uint32_t volatile GPIO11_CTRL;
	/*  */
#define IO_BANK0_GPIO11_CTRL_IRQOVER_Msb			29u
#define IO_BANK0_GPIO11_CTRL_IRQOVER_Lsb			28u
#define IO_BANK0_GPIO11_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO11_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO11_CTRL_IRQOVER_LOW			2u
#define IO_BANK0_GPIO11_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO11_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO11_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO11_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO11_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO11_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO11_CTRL_INOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO11_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO11_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO11_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO11_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO11_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO11_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO11_CTRL_OUTOVER_Msb			9u
#define IO_BANK0_GPIO11_CTRL_OUTOVER_Lsb			8u
#define IO_BANK0_GPIO11_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO11_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO11_CTRL_OUTOVER_LOW			2u
#define IO_BANK0_GPIO11_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO11_CTRL_FUNCSEL_Msb			4u
#define IO_BANK0_GPIO11_CTRL_FUNCSEL_Lsb			0u
#define IO_BANK0_GPIO11_CTRL_FUNCSEL_SPI1_TX			1u
#define IO_BANK0_GPIO11_CTRL_FUNCSEL_UART1_RTS			2u
#define IO_BANK0_GPIO11_CTRL_FUNCSEL_I2C1_SCL			3u
#define IO_BANK0_GPIO11_CTRL_FUNCSEL_PWM_B_5			4u
#define IO_BANK0_GPIO11_CTRL_FUNCSEL_SIO_11			5u
#define IO_BANK0_GPIO11_CTRL_FUNCSEL_PIO0_11			6u
#define IO_BANK0_GPIO11_CTRL_FUNCSEL_PIO1_11			7u
#define IO_BANK0_GPIO11_CTRL_FUNCSEL_USB_MUXING_EXTPHY_SUSPND	8u
#define IO_BANK0_GPIO11_CTRL_FUNCSEL_USB_MUXING_VBUS_EN		9u
#define IO_BANK0_GPIO11_CTRL_FUNCSEL_NULL			31u

	/* 0x60: GPIO status */
	uint32_t volatile GPIO12_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO12_STATUS_IRQTOPROC			26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO12_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO12_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO12_STATUS_INFROMPAD			17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO12_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO12_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO12_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO12_STATUS_OUTFROMPERI			8u

	/* 0x64: GPIO control including function select and overrides. */
	uint32_t volatile GPIO12_CTRL;
	/*  */
#define IO_BANK0_GPIO12_CTRL_IRQOVER_Msb			29u
#define IO_BANK0_GPIO12_CTRL_IRQOVER_Lsb			28u
#define IO_BANK0_GPIO12_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO12_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO12_CTRL_IRQOVER_LOW			2u
#define IO_BANK0_GPIO12_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO12_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO12_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO12_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO12_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO12_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO12_CTRL_INOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO12_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO12_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO12_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO12_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO12_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO12_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO12_CTRL_OUTOVER_Msb			9u
#define IO_BANK0_GPIO12_CTRL_OUTOVER_Lsb			8u
#define IO_BANK0_GPIO12_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO12_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO12_CTRL_OUTOVER_LOW			2u
#define IO_BANK0_GPIO12_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO12_CTRL_FUNCSEL_Msb			4u
#define IO_BANK0_GPIO12_CTRL_FUNCSEL_Lsb			0u
#define IO_BANK0_GPIO12_CTRL_FUNCSEL_SPI1_RX			1u
#define IO_BANK0_GPIO12_CTRL_FUNCSEL_UART0_TX			2u
#define IO_BANK0_GPIO12_CTRL_FUNCSEL_I2C0_SDA			3u
#define IO_BANK0_GPIO12_CTRL_FUNCSEL_PWM_A_6			4u
#define IO_BANK0_GPIO12_CTRL_FUNCSEL_SIO_12			5u
#define IO_BANK0_GPIO12_CTRL_FUNCSEL_PIO0_12			6u
#define IO_BANK0_GPIO12_CTRL_FUNCSEL_PIO1_12			7u
#define IO_BANK0_GPIO12_CTRL_FUNCSEL_USB_MUXING_EXTPHY_SPEED	8u
#define IO_BANK0_GPIO12_CTRL_FUNCSEL_USB_MUXING_OVERCURR_DETECT	9u
#define IO_BANK0_GPIO12_CTRL_FUNCSEL_NULL			31u

	/* 0x68: GPIO status */
	uint32_t volatile GPIO13_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO13_STATUS_IRQTOPROC			26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO13_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO13_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO13_STATUS_INFROMPAD			17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO13_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO13_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO13_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO13_STATUS_OUTFROMPERI			8u

	/* 0x6C: GPIO control including function select and overrides. */
	uint32_t volatile GPIO13_CTRL;
	/*  */
#define IO_BANK0_GPIO13_CTRL_IRQOVER_Msb			29u
#define IO_BANK0_GPIO13_CTRL_IRQOVER_Lsb			28u
#define IO_BANK0_GPIO13_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO13_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO13_CTRL_IRQOVER_LOW			2u
#define IO_BANK0_GPIO13_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO13_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO13_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO13_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO13_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO13_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO13_CTRL_INOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO13_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO13_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO13_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO13_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO13_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO13_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO13_CTRL_OUTOVER_Msb			9u
#define IO_BANK0_GPIO13_CTRL_OUTOVER_Lsb			8u
#define IO_BANK0_GPIO13_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO13_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO13_CTRL_OUTOVER_LOW			2u
#define IO_BANK0_GPIO13_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO13_CTRL_FUNCSEL_Msb			4u
#define IO_BANK0_GPIO13_CTRL_FUNCSEL_Lsb			0u
#define IO_BANK0_GPIO13_CTRL_FUNCSEL_SPI1_SS_N			1u
#define IO_BANK0_GPIO13_CTRL_FUNCSEL_UART0_RX			2u
#define IO_BANK0_GPIO13_CTRL_FUNCSEL_I2C0_SCL			3u
#define IO_BANK0_GPIO13_CTRL_FUNCSEL_PWM_B_6			4u
#define IO_BANK0_GPIO13_CTRL_FUNCSEL_SIO_13			5u
#define IO_BANK0_GPIO13_CTRL_FUNCSEL_PIO0_13			6u
#define IO_BANK0_GPIO13_CTRL_FUNCSEL_PIO1_13			7u
#define IO_BANK0_GPIO13_CTRL_FUNCSEL_USB_MUXING_EXTPHY_VPO	8u
#define IO_BANK0_GPIO13_CTRL_FUNCSEL_USB_MUXING_VBUS_DETECT	9u
#define IO_BANK0_GPIO13_CTRL_FUNCSEL_NULL			31u

	/* 0x70: GPIO status */
	uint32_t volatile GPIO14_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO14_STATUS_IRQTOPROC			26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO14_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO14_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO14_STATUS_INFROMPAD			17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO14_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO14_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO14_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO14_STATUS_OUTFROMPERI			8u

	/* 0x74: GPIO control including function select and overrides. */
	uint32_t volatile GPIO14_CTRL;
	/*  */
#define IO_BANK0_GPIO14_CTRL_IRQOVER_Msb			29u
#define IO_BANK0_GPIO14_CTRL_IRQOVER_Lsb			28u
#define IO_BANK0_GPIO14_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO14_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO14_CTRL_IRQOVER_LOW			2u
#define IO_BANK0_GPIO14_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO14_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO14_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO14_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO14_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO14_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO14_CTRL_INOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO14_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO14_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO14_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO14_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO14_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO14_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO14_CTRL_OUTOVER_Msb			9u
#define IO_BANK0_GPIO14_CTRL_OUTOVER_Lsb			8u
#define IO_BANK0_GPIO14_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO14_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO14_CTRL_OUTOVER_LOW			2u
#define IO_BANK0_GPIO14_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO14_CTRL_FUNCSEL_Msb			4u
#define IO_BANK0_GPIO14_CTRL_FUNCSEL_Lsb			0u
#define IO_BANK0_GPIO14_CTRL_FUNCSEL_SPI1_SCLK			1u
#define IO_BANK0_GPIO14_CTRL_FUNCSEL_UART0_CTS			2u
#define IO_BANK0_GPIO14_CTRL_FUNCSEL_I2C1_SDA			3u
#define IO_BANK0_GPIO14_CTRL_FUNCSEL_PWM_A_7			4u
#define IO_BANK0_GPIO14_CTRL_FUNCSEL_SIO_14			5u
#define IO_BANK0_GPIO14_CTRL_FUNCSEL_PIO0_14			6u
#define IO_BANK0_GPIO14_CTRL_FUNCSEL_PIO1_14			7u
#define IO_BANK0_GPIO14_CTRL_FUNCSEL_USB_MUXING_EXTPHY_VMO	8u
#define IO_BANK0_GPIO14_CTRL_FUNCSEL_USB_MUXING_VBUS_EN		9u
#define IO_BANK0_GPIO14_CTRL_FUNCSEL_NULL			31u

	/* 0x78: GPIO status */
	uint32_t volatile GPIO15_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO15_STATUS_IRQTOPROC			26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO15_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO15_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO15_STATUS_INFROMPAD			17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO15_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO15_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO15_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO15_STATUS_OUTFROMPERI			8u

	/* 0x7C: GPIO control including function select and overrides. */
	uint32_t volatile GPIO15_CTRL;
	/*  */
#define IO_BANK0_GPIO15_CTRL_IRQOVER_Msb			29u
#define IO_BANK0_GPIO15_CTRL_IRQOVER_Lsb			28u
#define IO_BANK0_GPIO15_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO15_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO15_CTRL_IRQOVER_LOW			2u
#define IO_BANK0_GPIO15_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO15_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO15_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO15_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO15_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO15_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO15_CTRL_INOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO15_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO15_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO15_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO15_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO15_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO15_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO15_CTRL_OUTOVER_Msb			9u
#define IO_BANK0_GPIO15_CTRL_OUTOVER_Lsb			8u
#define IO_BANK0_GPIO15_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO15_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO15_CTRL_OUTOVER_LOW			2u
#define IO_BANK0_GPIO15_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO15_CTRL_FUNCSEL_Msb			4u
#define IO_BANK0_GPIO15_CTRL_FUNCSEL_Lsb			0u
#define IO_BANK0_GPIO15_CTRL_FUNCSEL_SPI1_TX			1u
#define IO_BANK0_GPIO15_CTRL_FUNCSEL_UART0_RTS			2u
#define IO_BANK0_GPIO15_CTRL_FUNCSEL_I2C1_SCL			3u
#define IO_BANK0_GPIO15_CTRL_FUNCSEL_PWM_B_7			4u
#define IO_BANK0_GPIO15_CTRL_FUNCSEL_SIO_15			5u
#define IO_BANK0_GPIO15_CTRL_FUNCSEL_PIO0_15			6u
#define IO_BANK0_GPIO15_CTRL_FUNCSEL_PIO1_15			7u
#define IO_BANK0_GPIO15_CTRL_FUNCSEL_USB_MUXING_DIGITAL_DP	8u
#define IO_BANK0_GPIO15_CTRL_FUNCSEL_USB_MUXING_OVERCURR_DETECT	9u
#define IO_BANK0_GPIO15_CTRL_FUNCSEL_NULL			31u

	/* 0x80: GPIO status */
	uint32_t volatile GPIO16_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO16_STATUS_IRQTOPROC			26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO16_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO16_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO16_STATUS_INFROMPAD			17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO16_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO16_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO16_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO16_STATUS_OUTFROMPERI			8u

	/* 0x84: GPIO control including function select and overrides. */
	uint32_t volatile GPIO16_CTRL;
	/*  */
#define IO_BANK0_GPIO16_CTRL_IRQOVER_Msb			29u
#define IO_BANK0_GPIO16_CTRL_IRQOVER_Lsb			28u
#define IO_BANK0_GPIO16_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO16_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO16_CTRL_IRQOVER_LOW			2u
#define IO_BANK0_GPIO16_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO16_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO16_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO16_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO16_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO16_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO16_CTRL_INOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO16_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO16_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO16_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO16_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO16_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO16_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO16_CTRL_OUTOVER_Msb			9u
#define IO_BANK0_GPIO16_CTRL_OUTOVER_Lsb			8u
#define IO_BANK0_GPIO16_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO16_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO16_CTRL_OUTOVER_LOW			2u
#define IO_BANK0_GPIO16_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO16_CTRL_FUNCSEL_Msb			4u
#define IO_BANK0_GPIO16_CTRL_FUNCSEL_Lsb			0u
#define IO_BANK0_GPIO16_CTRL_FUNCSEL_SPI0_RX			1u
#define IO_BANK0_GPIO16_CTRL_FUNCSEL_UART0_TX			2u
#define IO_BANK0_GPIO16_CTRL_FUNCSEL_I2C0_SDA			3u
#define IO_BANK0_GPIO16_CTRL_FUNCSEL_PWM_A_0			4u
#define IO_BANK0_GPIO16_CTRL_FUNCSEL_SIO_16			5u
#define IO_BANK0_GPIO16_CTRL_FUNCSEL_PIO0_16			6u
#define IO_BANK0_GPIO16_CTRL_FUNCSEL_PIO1_16			7u
#define IO_BANK0_GPIO16_CTRL_FUNCSEL_USB_MUXING_DIGITAL_DM	8u
#define IO_BANK0_GPIO16_CTRL_FUNCSEL_USB_MUXING_VBUS_DETECT	9u
#define IO_BANK0_GPIO16_CTRL_FUNCSEL_NULL			31u

	/* 0x88: GPIO status */
	uint32_t volatile GPIO17_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO17_STATUS_IRQTOPROC			26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO17_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO17_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO17_STATUS_INFROMPAD			17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO17_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO17_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO17_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO17_STATUS_OUTFROMPERI			8u

	/* 0x8C: GPIO control including function select and overrides. */
	uint32_t volatile GPIO17_CTRL;
	/*  */
#define IO_BANK0_GPIO17_CTRL_IRQOVER_Msb			29u
#define IO_BANK0_GPIO17_CTRL_IRQOVER_Lsb			28u
#define IO_BANK0_GPIO17_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO17_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO17_CTRL_IRQOVER_LOW			2u
#define IO_BANK0_GPIO17_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO17_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO17_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO17_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO17_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO17_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO17_CTRL_INOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO17_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO17_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO17_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO17_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO17_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO17_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO17_CTRL_OUTOVER_Msb			9u
#define IO_BANK0_GPIO17_CTRL_OUTOVER_Lsb			8u
#define IO_BANK0_GPIO17_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO17_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO17_CTRL_OUTOVER_LOW			2u
#define IO_BANK0_GPIO17_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO17_CTRL_FUNCSEL_Msb			4u
#define IO_BANK0_GPIO17_CTRL_FUNCSEL_Lsb			0u
#define IO_BANK0_GPIO17_CTRL_FUNCSEL_SPI0_SS_N			1u
#define IO_BANK0_GPIO17_CTRL_FUNCSEL_UART0_RX			2u
#define IO_BANK0_GPIO17_CTRL_FUNCSEL_I2C0_SCL			3u
#define IO_BANK0_GPIO17_CTRL_FUNCSEL_PWM_B_0			4u
#define IO_BANK0_GPIO17_CTRL_FUNCSEL_SIO_17			5u
#define IO_BANK0_GPIO17_CTRL_FUNCSEL_PIO0_17			6u
#define IO_BANK0_GPIO17_CTRL_FUNCSEL_PIO1_17			7u
#define IO_BANK0_GPIO17_CTRL_FUNCSEL_USB_MUXING_VBUS_EN		9u
#define IO_BANK0_GPIO17_CTRL_FUNCSEL_NULL			31u

	/* 0x90: GPIO status */
	uint32_t volatile GPIO18_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO18_STATUS_IRQTOPROC			26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO18_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO18_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO18_STATUS_INFROMPAD			17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO18_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO18_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO18_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO18_STATUS_OUTFROMPERI			8u

	/* 0x94: GPIO control including function select and overrides. */
	uint32_t volatile GPIO18_CTRL;
	/*  */
#define IO_BANK0_GPIO18_CTRL_IRQOVER_Msb			29u
#define IO_BANK0_GPIO18_CTRL_IRQOVER_Lsb			28u
#define IO_BANK0_GPIO18_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO18_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO18_CTRL_IRQOVER_LOW			2u
#define IO_BANK0_GPIO18_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO18_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO18_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO18_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO18_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO18_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO18_CTRL_INOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO18_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO18_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO18_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO18_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO18_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO18_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO18_CTRL_OUTOVER_Msb			9u
#define IO_BANK0_GPIO18_CTRL_OUTOVER_Lsb			8u
#define IO_BANK0_GPIO18_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO18_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO18_CTRL_OUTOVER_LOW			2u
#define IO_BANK0_GPIO18_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO18_CTRL_FUNCSEL_Msb			4u
#define IO_BANK0_GPIO18_CTRL_FUNCSEL_Lsb			0u
#define IO_BANK0_GPIO18_CTRL_FUNCSEL_SPI0_SCLK			1u
#define IO_BANK0_GPIO18_CTRL_FUNCSEL_UART0_CTS			2u
#define IO_BANK0_GPIO18_CTRL_FUNCSEL_I2C1_SDA			3u
#define IO_BANK0_GPIO18_CTRL_FUNCSEL_PWM_A_1			4u
#define IO_BANK0_GPIO18_CTRL_FUNCSEL_SIO_18			5u
#define IO_BANK0_GPIO18_CTRL_FUNCSEL_PIO0_18			6u
#define IO_BANK0_GPIO18_CTRL_FUNCSEL_PIO1_18			7u
#define IO_BANK0_GPIO18_CTRL_FUNCSEL_USB_MUXING_OVERCURR_DETECT	9u
#define IO_BANK0_GPIO18_CTRL_FUNCSEL_NULL			31u

	/* 0x98: GPIO status */
	uint32_t volatile GPIO19_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO19_STATUS_IRQTOPROC			26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO19_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO19_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO19_STATUS_INFROMPAD			17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO19_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO19_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO19_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO19_STATUS_OUTFROMPERI			8u

	/* 0x9C: GPIO control including function select and overrides. */
	uint32_t volatile GPIO19_CTRL;
	/*  */
#define IO_BANK0_GPIO19_CTRL_IRQOVER_Msb			29u
#define IO_BANK0_GPIO19_CTRL_IRQOVER_Lsb			28u
#define IO_BANK0_GPIO19_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO19_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO19_CTRL_IRQOVER_LOW			2u
#define IO_BANK0_GPIO19_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO19_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO19_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO19_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO19_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO19_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO19_CTRL_INOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO19_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO19_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO19_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO19_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO19_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO19_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO19_CTRL_OUTOVER_Msb			9u
#define IO_BANK0_GPIO19_CTRL_OUTOVER_Lsb			8u
#define IO_BANK0_GPIO19_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO19_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO19_CTRL_OUTOVER_LOW			2u
#define IO_BANK0_GPIO19_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO19_CTRL_FUNCSEL_Msb			4u
#define IO_BANK0_GPIO19_CTRL_FUNCSEL_Lsb			0u
#define IO_BANK0_GPIO19_CTRL_FUNCSEL_SPI0_TX			1u
#define IO_BANK0_GPIO19_CTRL_FUNCSEL_UART0_RTS			2u
#define IO_BANK0_GPIO19_CTRL_FUNCSEL_I2C1_SCL			3u
#define IO_BANK0_GPIO19_CTRL_FUNCSEL_PWM_B_1			4u
#define IO_BANK0_GPIO19_CTRL_FUNCSEL_SIO_19			5u
#define IO_BANK0_GPIO19_CTRL_FUNCSEL_PIO0_19			6u
#define IO_BANK0_GPIO19_CTRL_FUNCSEL_PIO1_19			7u
#define IO_BANK0_GPIO19_CTRL_FUNCSEL_USB_MUXING_VBUS_DETECT	9u
#define IO_BANK0_GPIO19_CTRL_FUNCSEL_NULL			31u

	/* 0xA0: GPIO status */
	uint32_t volatile GPIO20_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO20_STATUS_IRQTOPROC			26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO20_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO20_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO20_STATUS_INFROMPAD			17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO20_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO20_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO20_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO20_STATUS_OUTFROMPERI			8u

	/* 0xA4: GPIO control including function select and overrides. */
	uint32_t volatile GPIO20_CTRL;
	/*  */
#define IO_BANK0_GPIO20_CTRL_IRQOVER_Msb			29u
#define IO_BANK0_GPIO20_CTRL_IRQOVER_Lsb			28u
#define IO_BANK0_GPIO20_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO20_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO20_CTRL_IRQOVER_LOW			2u
#define IO_BANK0_GPIO20_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO20_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO20_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO20_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO20_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO20_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO20_CTRL_INOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO20_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO20_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO20_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO20_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO20_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO20_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO20_CTRL_OUTOVER_Msb			9u
#define IO_BANK0_GPIO20_CTRL_OUTOVER_Lsb			8u
#define IO_BANK0_GPIO20_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO20_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO20_CTRL_OUTOVER_LOW			2u
#define IO_BANK0_GPIO20_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO20_CTRL_FUNCSEL_Msb			4u
#define IO_BANK0_GPIO20_CTRL_FUNCSEL_Lsb			0u
#define IO_BANK0_GPIO20_CTRL_FUNCSEL_SPI0_RX			1u
#define IO_BANK0_GPIO20_CTRL_FUNCSEL_UART1_TX			2u
#define IO_BANK0_GPIO20_CTRL_FUNCSEL_I2C0_SDA			3u
#define IO_BANK0_GPIO20_CTRL_FUNCSEL_PWM_A_2			4u
#define IO_BANK0_GPIO20_CTRL_FUNCSEL_SIO_20			5u
#define IO_BANK0_GPIO20_CTRL_FUNCSEL_PIO0_20			6u
#define IO_BANK0_GPIO20_CTRL_FUNCSEL_PIO1_20			7u
#define IO_BANK0_GPIO20_CTRL_FUNCSEL_CLOCKS_GPIN_0		8u
#define IO_BANK0_GPIO20_CTRL_FUNCSEL_USB_MUXING_VBUS_EN		9u
#define IO_BANK0_GPIO20_CTRL_FUNCSEL_NULL			31u

	/* 0xA8: GPIO status */
	uint32_t volatile GPIO21_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO21_STATUS_IRQTOPROC			26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO21_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO21_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO21_STATUS_INFROMPAD			17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO21_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO21_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO21_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO21_STATUS_OUTFROMPERI			8u

	/* 0xAC: GPIO control including function select and overrides. */
	uint32_t volatile GPIO21_CTRL;
	/*  */
#define IO_BANK0_GPIO21_CTRL_IRQOVER_Msb			29u
#define IO_BANK0_GPIO21_CTRL_IRQOVER_Lsb			28u
#define IO_BANK0_GPIO21_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO21_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO21_CTRL_IRQOVER_LOW			2u
#define IO_BANK0_GPIO21_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO21_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO21_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO21_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO21_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO21_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO21_CTRL_INOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO21_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO21_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO21_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO21_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO21_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO21_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO21_CTRL_OUTOVER_Msb			9u
#define IO_BANK0_GPIO21_CTRL_OUTOVER_Lsb			8u
#define IO_BANK0_GPIO21_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO21_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO21_CTRL_OUTOVER_LOW			2u
#define IO_BANK0_GPIO21_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO21_CTRL_FUNCSEL_Msb			4u
#define IO_BANK0_GPIO21_CTRL_FUNCSEL_Lsb			0u
#define IO_BANK0_GPIO21_CTRL_FUNCSEL_SPI0_SS_N			1u
#define IO_BANK0_GPIO21_CTRL_FUNCSEL_UART1_RX			2u
#define IO_BANK0_GPIO21_CTRL_FUNCSEL_I2C0_SCL			3u
#define IO_BANK0_GPIO21_CTRL_FUNCSEL_PWM_B_2			4u
#define IO_BANK0_GPIO21_CTRL_FUNCSEL_SIO_21			5u
#define IO_BANK0_GPIO21_CTRL_FUNCSEL_PIO0_21			6u
#define IO_BANK0_GPIO21_CTRL_FUNCSEL_PIO1_21			7u
#define IO_BANK0_GPIO21_CTRL_FUNCSEL_CLOCKS_GPOUT_0		8u
#define IO_BANK0_GPIO21_CTRL_FUNCSEL_USB_MUXING_OVERCURR_DETECT	9u
#define IO_BANK0_GPIO21_CTRL_FUNCSEL_NULL			31u

	/* 0xB0: GPIO status */
	uint32_t volatile GPIO22_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO22_STATUS_IRQTOPROC			26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO22_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO22_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO22_STATUS_INFROMPAD			17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO22_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO22_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO22_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO22_STATUS_OUTFROMPERI			8u

	/* 0xB4: GPIO control including function select and overrides. */
	uint32_t volatile GPIO22_CTRL;
	/*  */
#define IO_BANK0_GPIO22_CTRL_IRQOVER_Msb			29u
#define IO_BANK0_GPIO22_CTRL_IRQOVER_Lsb			28u
#define IO_BANK0_GPIO22_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO22_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO22_CTRL_IRQOVER_LOW			2u
#define IO_BANK0_GPIO22_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO22_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO22_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO22_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO22_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO22_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO22_CTRL_INOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO22_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO22_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO22_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO22_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO22_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO22_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO22_CTRL_OUTOVER_Msb			9u
#define IO_BANK0_GPIO22_CTRL_OUTOVER_Lsb			8u
#define IO_BANK0_GPIO22_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO22_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO22_CTRL_OUTOVER_LOW			2u
#define IO_BANK0_GPIO22_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO22_CTRL_FUNCSEL_Msb			4u
#define IO_BANK0_GPIO22_CTRL_FUNCSEL_Lsb			0u
#define IO_BANK0_GPIO22_CTRL_FUNCSEL_SPI0_SCLK			1u
#define IO_BANK0_GPIO22_CTRL_FUNCSEL_UART1_CTS			2u
#define IO_BANK0_GPIO22_CTRL_FUNCSEL_I2C1_SDA			3u
#define IO_BANK0_GPIO22_CTRL_FUNCSEL_PWM_A_3			4u
#define IO_BANK0_GPIO22_CTRL_FUNCSEL_SIO_22			5u
#define IO_BANK0_GPIO22_CTRL_FUNCSEL_PIO0_22			6u
#define IO_BANK0_GPIO22_CTRL_FUNCSEL_PIO1_22			7u
#define IO_BANK0_GPIO22_CTRL_FUNCSEL_CLOCKS_GPIN_1		8u
#define IO_BANK0_GPIO22_CTRL_FUNCSEL_USB_MUXING_VBUS_DETECT	9u
#define IO_BANK0_GPIO22_CTRL_FUNCSEL_NULL			31u

	/* 0xB8: GPIO status */
	uint32_t volatile GPIO23_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO23_STATUS_IRQTOPROC			26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO23_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO23_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO23_STATUS_INFROMPAD			17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO23_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO23_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO23_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO23_STATUS_OUTFROMPERI			8u

	/* 0xBC: GPIO control including function select and overrides. */
	uint32_t volatile GPIO23_CTRL;
	/*  */
#define IO_BANK0_GPIO23_CTRL_IRQOVER_Msb			29u
#define IO_BANK0_GPIO23_CTRL_IRQOVER_Lsb			28u
#define IO_BANK0_GPIO23_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO23_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO23_CTRL_IRQOVER_LOW			2u
#define IO_BANK0_GPIO23_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO23_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO23_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO23_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO23_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO23_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO23_CTRL_INOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO23_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO23_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO23_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO23_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO23_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO23_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO23_CTRL_OUTOVER_Msb			9u
#define IO_BANK0_GPIO23_CTRL_OUTOVER_Lsb			8u
#define IO_BANK0_GPIO23_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO23_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO23_CTRL_OUTOVER_LOW			2u
#define IO_BANK0_GPIO23_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO23_CTRL_FUNCSEL_Msb			4u
#define IO_BANK0_GPIO23_CTRL_FUNCSEL_Lsb			0u
#define IO_BANK0_GPIO23_CTRL_FUNCSEL_SPI0_TX			1u
#define IO_BANK0_GPIO23_CTRL_FUNCSEL_UART1_RTS			2u
#define IO_BANK0_GPIO23_CTRL_FUNCSEL_I2C1_SCL			3u
#define IO_BANK0_GPIO23_CTRL_FUNCSEL_PWM_B_3			4u
#define IO_BANK0_GPIO23_CTRL_FUNCSEL_SIO_23			5u
#define IO_BANK0_GPIO23_CTRL_FUNCSEL_PIO0_23			6u
#define IO_BANK0_GPIO23_CTRL_FUNCSEL_PIO1_23			7u
#define IO_BANK0_GPIO23_CTRL_FUNCSEL_CLOCKS_GPOUT_1		8u
#define IO_BANK0_GPIO23_CTRL_FUNCSEL_USB_MUXING_VBUS_EN		9u
#define IO_BANK0_GPIO23_CTRL_FUNCSEL_NULL			31u

	/* 0xC0: GPIO status */
	uint32_t volatile GPIO24_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO24_STATUS_IRQTOPROC			26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO24_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO24_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO24_STATUS_INFROMPAD			17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO24_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO24_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO24_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO24_STATUS_OUTFROMPERI			8u

	/* 0xC4: GPIO control including function select and overrides. */
	uint32_t volatile GPIO24_CTRL;
	/*  */
#define IO_BANK0_GPIO24_CTRL_IRQOVER_Msb			29u
#define IO_BANK0_GPIO24_CTRL_IRQOVER_Lsb			28u
#define IO_BANK0_GPIO24_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO24_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO24_CTRL_IRQOVER_LOW			2u
#define IO_BANK0_GPIO24_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO24_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO24_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO24_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO24_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO24_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO24_CTRL_INOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO24_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO24_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO24_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO24_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO24_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO24_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO24_CTRL_OUTOVER_Msb			9u
#define IO_BANK0_GPIO24_CTRL_OUTOVER_Lsb			8u
#define IO_BANK0_GPIO24_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO24_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO24_CTRL_OUTOVER_LOW			2u
#define IO_BANK0_GPIO24_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO24_CTRL_FUNCSEL_Msb			4u
#define IO_BANK0_GPIO24_CTRL_FUNCSEL_Lsb			0u
#define IO_BANK0_GPIO24_CTRL_FUNCSEL_SPI1_RX			1u
#define IO_BANK0_GPIO24_CTRL_FUNCSEL_UART1_TX			2u
#define IO_BANK0_GPIO24_CTRL_FUNCSEL_I2C0_SDA			3u
#define IO_BANK0_GPIO24_CTRL_FUNCSEL_PWM_A_4			4u
#define IO_BANK0_GPIO24_CTRL_FUNCSEL_SIO_24			5u
#define IO_BANK0_GPIO24_CTRL_FUNCSEL_PIO0_24			6u
#define IO_BANK0_GPIO24_CTRL_FUNCSEL_PIO1_24			7u
#define IO_BANK0_GPIO24_CTRL_FUNCSEL_CLOCKS_GPOUT_2		8u
#define IO_BANK0_GPIO24_CTRL_FUNCSEL_USB_MUXING_OVERCURR_DETECT	9u
#define IO_BANK0_GPIO24_CTRL_FUNCSEL_NULL			31u

	/* 0xC8: GPIO status */
	uint32_t volatile GPIO25_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO25_STATUS_IRQTOPROC			26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO25_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO25_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO25_STATUS_INFROMPAD			17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO25_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO25_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO25_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO25_STATUS_OUTFROMPERI			8u

	/* 0xCC: GPIO control including function select and overrides. */
	uint32_t volatile GPIO25_CTRL;
	/*  */
#define IO_BANK0_GPIO25_CTRL_IRQOVER_Msb			29u
#define IO_BANK0_GPIO25_CTRL_IRQOVER_Lsb			28u
#define IO_BANK0_GPIO25_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO25_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO25_CTRL_IRQOVER_LOW			2u
#define IO_BANK0_GPIO25_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO25_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO25_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO25_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO25_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO25_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO25_CTRL_INOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO25_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO25_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO25_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO25_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO25_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO25_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO25_CTRL_OUTOVER_Msb			9u
#define IO_BANK0_GPIO25_CTRL_OUTOVER_Lsb			8u
#define IO_BANK0_GPIO25_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO25_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO25_CTRL_OUTOVER_LOW			2u
#define IO_BANK0_GPIO25_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO25_CTRL_FUNCSEL_Msb			4u
#define IO_BANK0_GPIO25_CTRL_FUNCSEL_Lsb			0u
#define IO_BANK0_GPIO25_CTRL_FUNCSEL_SPI1_SS_N			1u
#define IO_BANK0_GPIO25_CTRL_FUNCSEL_UART1_RX			2u
#define IO_BANK0_GPIO25_CTRL_FUNCSEL_I2C0_SCL			3u
#define IO_BANK0_GPIO25_CTRL_FUNCSEL_PWM_B_4			4u
#define IO_BANK0_GPIO25_CTRL_FUNCSEL_SIO_25			5u
#define IO_BANK0_GPIO25_CTRL_FUNCSEL_PIO0_25			6u
#define IO_BANK0_GPIO25_CTRL_FUNCSEL_PIO1_25			7u
#define IO_BANK0_GPIO25_CTRL_FUNCSEL_CLOCKS_GPOUT_3		8u
#define IO_BANK0_GPIO25_CTRL_FUNCSEL_USB_MUXING_VBUS_DETECT	9u
#define IO_BANK0_GPIO25_CTRL_FUNCSEL_NULL			31u

	/* 0xD0: GPIO status */
	uint32_t volatile GPIO26_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO26_STATUS_IRQTOPROC			26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO26_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO26_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO26_STATUS_INFROMPAD			17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO26_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO26_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO26_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO26_STATUS_OUTFROMPERI			8u

	/* 0xD4: GPIO control including function select and overrides. */
	uint32_t volatile GPIO26_CTRL;
	/*  */
#define IO_BANK0_GPIO26_CTRL_IRQOVER_Msb			29u
#define IO_BANK0_GPIO26_CTRL_IRQOVER_Lsb			28u
#define IO_BANK0_GPIO26_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO26_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO26_CTRL_IRQOVER_LOW			2u
#define IO_BANK0_GPIO26_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO26_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO26_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO26_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO26_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO26_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO26_CTRL_INOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO26_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO26_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO26_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO26_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO26_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO26_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO26_CTRL_OUTOVER_Msb			9u
#define IO_BANK0_GPIO26_CTRL_OUTOVER_Lsb			8u
#define IO_BANK0_GPIO26_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO26_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO26_CTRL_OUTOVER_LOW			2u
#define IO_BANK0_GPIO26_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO26_CTRL_FUNCSEL_Msb			4u
#define IO_BANK0_GPIO26_CTRL_FUNCSEL_Lsb			0u
#define IO_BANK0_GPIO26_CTRL_FUNCSEL_SPI1_SCLK			1u
#define IO_BANK0_GPIO26_CTRL_FUNCSEL_UART1_CTS			2u
#define IO_BANK0_GPIO26_CTRL_FUNCSEL_I2C1_SDA			3u
#define IO_BANK0_GPIO26_CTRL_FUNCSEL_PWM_A_5			4u
#define IO_BANK0_GPIO26_CTRL_FUNCSEL_SIO_26			5u
#define IO_BANK0_GPIO26_CTRL_FUNCSEL_PIO0_26			6u
#define IO_BANK0_GPIO26_CTRL_FUNCSEL_PIO1_26			7u
#define IO_BANK0_GPIO26_CTRL_FUNCSEL_USB_MUXING_VBUS_EN		9u
#define IO_BANK0_GPIO26_CTRL_FUNCSEL_NULL			31u

	/* 0xD8: GPIO status */
	uint32_t volatile GPIO27_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO27_STATUS_IRQTOPROC			26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO27_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO27_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO27_STATUS_INFROMPAD			17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO27_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO27_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO27_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO27_STATUS_OUTFROMPERI			8u

	/* 0xDC: GPIO control including function select and overrides. */
	uint32_t volatile GPIO27_CTRL;
	/*  */
#define IO_BANK0_GPIO27_CTRL_IRQOVER_Msb			29u
#define IO_BANK0_GPIO27_CTRL_IRQOVER_Lsb			28u
#define IO_BANK0_GPIO27_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO27_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO27_CTRL_IRQOVER_LOW			2u
#define IO_BANK0_GPIO27_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO27_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO27_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO27_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO27_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO27_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO27_CTRL_INOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO27_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO27_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO27_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO27_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO27_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO27_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO27_CTRL_OUTOVER_Msb			9u
#define IO_BANK0_GPIO27_CTRL_OUTOVER_Lsb			8u
#define IO_BANK0_GPIO27_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO27_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO27_CTRL_OUTOVER_LOW			2u
#define IO_BANK0_GPIO27_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO27_CTRL_FUNCSEL_Msb			4u
#define IO_BANK0_GPIO27_CTRL_FUNCSEL_Lsb			0u
#define IO_BANK0_GPIO27_CTRL_FUNCSEL_SPI1_TX			1u
#define IO_BANK0_GPIO27_CTRL_FUNCSEL_UART1_RTS			2u
#define IO_BANK0_GPIO27_CTRL_FUNCSEL_I2C1_SCL			3u
#define IO_BANK0_GPIO27_CTRL_FUNCSEL_PWM_B_5			4u
#define IO_BANK0_GPIO27_CTRL_FUNCSEL_SIO_27			5u
#define IO_BANK0_GPIO27_CTRL_FUNCSEL_PIO0_27			6u
#define IO_BANK0_GPIO27_CTRL_FUNCSEL_PIO1_27			7u
#define IO_BANK0_GPIO27_CTRL_FUNCSEL_USB_MUXING_OVERCURR_DETECT	9u
#define IO_BANK0_GPIO27_CTRL_FUNCSEL_NULL			31u

	/* 0xE0: GPIO status */
	uint32_t volatile GPIO28_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO28_STATUS_IRQTOPROC			26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO28_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO28_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO28_STATUS_INFROMPAD			17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO28_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO28_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO28_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO28_STATUS_OUTFROMPERI			8u

	/* 0xE4: GPIO control including function select and overrides. */
	uint32_t volatile GPIO28_CTRL;
	/*  */
#define IO_BANK0_GPIO28_CTRL_IRQOVER_Msb			29u
#define IO_BANK0_GPIO28_CTRL_IRQOVER_Lsb			28u
#define IO_BANK0_GPIO28_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO28_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO28_CTRL_IRQOVER_LOW			2u
#define IO_BANK0_GPIO28_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO28_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO28_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO28_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO28_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO28_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO28_CTRL_INOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO28_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO28_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO28_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO28_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO28_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO28_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO28_CTRL_OUTOVER_Msb			9u
#define IO_BANK0_GPIO28_CTRL_OUTOVER_Lsb			8u
#define IO_BANK0_GPIO28_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO28_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO28_CTRL_OUTOVER_LOW			2u
#define IO_BANK0_GPIO28_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO28_CTRL_FUNCSEL_Msb			4u
#define IO_BANK0_GPIO28_CTRL_FUNCSEL_Lsb			0u
#define IO_BANK0_GPIO28_CTRL_FUNCSEL_SPI1_RX			1u
#define IO_BANK0_GPIO28_CTRL_FUNCSEL_UART0_TX			2u
#define IO_BANK0_GPIO28_CTRL_FUNCSEL_I2C0_SDA			3u
#define IO_BANK0_GPIO28_CTRL_FUNCSEL_PWM_A_6			4u
#define IO_BANK0_GPIO28_CTRL_FUNCSEL_SIO_28			5u
#define IO_BANK0_GPIO28_CTRL_FUNCSEL_PIO0_28			6u
#define IO_BANK0_GPIO28_CTRL_FUNCSEL_PIO1_28			7u
#define IO_BANK0_GPIO28_CTRL_FUNCSEL_USB_MUXING_VBUS_DETECT	9u
#define IO_BANK0_GPIO28_CTRL_FUNCSEL_NULL			31u

	/* 0xE8: GPIO status */
	uint32_t volatile GPIO29_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_BANK0_GPIO29_STATUS_IRQTOPROC			26u
	/* interrupt from pad before override is applied */
#define IO_BANK0_GPIO29_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_BANK0_GPIO29_STATUS_INTOPERI				19u
	/* input signal from pad, before override is applied */
#define IO_BANK0_GPIO29_STATUS_INFROMPAD			17u
	/* output enable to pad after register override is applied */
#define IO_BANK0_GPIO29_STATUS_OETOPAD				13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO29_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_BANK0_GPIO29_STATUS_OUTTOPAD				9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_BANK0_GPIO29_STATUS_OUTFROMPERI			8u

	/* 0xEC: GPIO control including function select and overrides. */
	uint32_t volatile GPIO29_CTRL;
	/*  */
#define IO_BANK0_GPIO29_CTRL_IRQOVER_Msb			29u
#define IO_BANK0_GPIO29_CTRL_IRQOVER_Lsb			28u
#define IO_BANK0_GPIO29_CTRL_IRQOVER_NORMAL			0u
#define IO_BANK0_GPIO29_CTRL_IRQOVER_INVERT			1u
#define IO_BANK0_GPIO29_CTRL_IRQOVER_LOW			2u
#define IO_BANK0_GPIO29_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO29_CTRL_INOVER_Msb				17u
#define IO_BANK0_GPIO29_CTRL_INOVER_Lsb				16u
#define IO_BANK0_GPIO29_CTRL_INOVER_NORMAL			0u
#define IO_BANK0_GPIO29_CTRL_INOVER_INVERT			1u
#define IO_BANK0_GPIO29_CTRL_INOVER_LOW				2u
#define IO_BANK0_GPIO29_CTRL_INOVER_HIGH			3u
	/*  */
#define IO_BANK0_GPIO29_CTRL_OEOVER_Msb				13u
#define IO_BANK0_GPIO29_CTRL_OEOVER_Lsb				12u
#define IO_BANK0_GPIO29_CTRL_OEOVER_NORMAL			0u
#define IO_BANK0_GPIO29_CTRL_OEOVER_INVERT			1u
#define IO_BANK0_GPIO29_CTRL_OEOVER_DISABLE			2u
#define IO_BANK0_GPIO29_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_BANK0_GPIO29_CTRL_OUTOVER_Msb			9u
#define IO_BANK0_GPIO29_CTRL_OUTOVER_Lsb			8u
#define IO_BANK0_GPIO29_CTRL_OUTOVER_NORMAL			0u
#define IO_BANK0_GPIO29_CTRL_OUTOVER_INVERT			1u
#define IO_BANK0_GPIO29_CTRL_OUTOVER_LOW			2u
#define IO_BANK0_GPIO29_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_BANK0_GPIO29_CTRL_FUNCSEL_Msb			4u
#define IO_BANK0_GPIO29_CTRL_FUNCSEL_Lsb			0u
#define IO_BANK0_GPIO29_CTRL_FUNCSEL_SPI1_SS_N			1u
#define IO_BANK0_GPIO29_CTRL_FUNCSEL_UART0_RX			2u
#define IO_BANK0_GPIO29_CTRL_FUNCSEL_I2C0_SCL			3u
#define IO_BANK0_GPIO29_CTRL_FUNCSEL_PWM_B_6			4u
#define IO_BANK0_GPIO29_CTRL_FUNCSEL_SIO_29			5u
#define IO_BANK0_GPIO29_CTRL_FUNCSEL_PIO0_29			6u
#define IO_BANK0_GPIO29_CTRL_FUNCSEL_PIO1_29			7u
#define IO_BANK0_GPIO29_CTRL_FUNCSEL_USB_MUXING_VBUS_EN		9u
#define IO_BANK0_GPIO29_CTRL_FUNCSEL_NULL			31u

	/* 0xF0: Raw Interrupts */
	uint32_t volatile INTR0;
	/*  */
#define IO_BANK0_INTR0_GPIO7_EDGE_HIGH				31u
	/*  */
#define IO_BANK0_INTR0_GPIO7_EDGE_LOW				30u
	/*  */
#define IO_BANK0_INTR0_GPIO7_LEVEL_HIGH				29u
	/*  */
#define IO_BANK0_INTR0_GPIO7_LEVEL_LOW				28u
	/*  */
#define IO_BANK0_INTR0_GPIO6_EDGE_HIGH				27u
	/*  */
#define IO_BANK0_INTR0_GPIO6_EDGE_LOW				26u
	/*  */
#define IO_BANK0_INTR0_GPIO6_LEVEL_HIGH				25u
	/*  */
#define IO_BANK0_INTR0_GPIO6_LEVEL_LOW				24u
	/*  */
#define IO_BANK0_INTR0_GPIO5_EDGE_HIGH				23u
	/*  */
#define IO_BANK0_INTR0_GPIO5_EDGE_LOW				22u
	/*  */
#define IO_BANK0_INTR0_GPIO5_LEVEL_HIGH				21u
	/*  */
#define IO_BANK0_INTR0_GPIO5_LEVEL_LOW				20u
	/*  */
#define IO_BANK0_INTR0_GPIO4_EDGE_HIGH				19u
	/*  */
#define IO_BANK0_INTR0_GPIO4_EDGE_LOW				18u
	/*  */
#define IO_BANK0_INTR0_GPIO4_LEVEL_HIGH				17u
	/*  */
#define IO_BANK0_INTR0_GPIO4_LEVEL_LOW				16u
	/*  */
#define IO_BANK0_INTR0_GPIO3_EDGE_HIGH				15u
	/*  */
#define IO_BANK0_INTR0_GPIO3_EDGE_LOW				14u
	/*  */
#define IO_BANK0_INTR0_GPIO3_LEVEL_HIGH				13u
	/*  */
#define IO_BANK0_INTR0_GPIO3_LEVEL_LOW				12u
	/*  */
#define IO_BANK0_INTR0_GPIO2_EDGE_HIGH				11u
	/*  */
#define IO_BANK0_INTR0_GPIO2_EDGE_LOW				10u
	/*  */
#define IO_BANK0_INTR0_GPIO2_LEVEL_HIGH				9u
	/*  */
#define IO_BANK0_INTR0_GPIO2_LEVEL_LOW				8u
	/*  */
#define IO_BANK0_INTR0_GPIO1_EDGE_HIGH				7u
	/*  */
#define IO_BANK0_INTR0_GPIO1_EDGE_LOW				6u
	/*  */
#define IO_BANK0_INTR0_GPIO1_LEVEL_HIGH				5u
	/*  */
#define IO_BANK0_INTR0_GPIO1_LEVEL_LOW				4u
	/*  */
#define IO_BANK0_INTR0_GPIO0_EDGE_HIGH				3u
	/*  */
#define IO_BANK0_INTR0_GPIO0_EDGE_LOW				2u
	/*  */
#define IO_BANK0_INTR0_GPIO0_LEVEL_HIGH				1u
	/*  */
#define IO_BANK0_INTR0_GPIO0_LEVEL_LOW				0u

	/* 0xF4: Raw Interrupts */
	uint32_t volatile INTR1;
	/*  */
#define IO_BANK0_INTR1_GPIO15_EDGE_HIGH				31u
	/*  */
#define IO_BANK0_INTR1_GPIO15_EDGE_LOW				30u
	/*  */
#define IO_BANK0_INTR1_GPIO15_LEVEL_HIGH			29u
	/*  */
#define IO_BANK0_INTR1_GPIO15_LEVEL_LOW				28u
	/*  */
#define IO_BANK0_INTR1_GPIO14_EDGE_HIGH				27u
	/*  */
#define IO_BANK0_INTR1_GPIO14_EDGE_LOW				26u
	/*  */
#define IO_BANK0_INTR1_GPIO14_LEVEL_HIGH			25u
	/*  */
#define IO_BANK0_INTR1_GPIO14_LEVEL_LOW				24u
	/*  */
#define IO_BANK0_INTR1_GPIO13_EDGE_HIGH				23u
	/*  */
#define IO_BANK0_INTR1_GPIO13_EDGE_LOW				22u
	/*  */
#define IO_BANK0_INTR1_GPIO13_LEVEL_HIGH			21u
	/*  */
#define IO_BANK0_INTR1_GPIO13_LEVEL_LOW				20u
	/*  */
#define IO_BANK0_INTR1_GPIO12_EDGE_HIGH				19u
	/*  */
#define IO_BANK0_INTR1_GPIO12_EDGE_LOW				18u
	/*  */
#define IO_BANK0_INTR1_GPIO12_LEVEL_HIGH			17u
	/*  */
#define IO_BANK0_INTR1_GPIO12_LEVEL_LOW				16u
	/*  */
#define IO_BANK0_INTR1_GPIO11_EDGE_HIGH				15u
	/*  */
#define IO_BANK0_INTR1_GPIO11_EDGE_LOW				14u
	/*  */
#define IO_BANK0_INTR1_GPIO11_LEVEL_HIGH			13u
	/*  */
#define IO_BANK0_INTR1_GPIO11_LEVEL_LOW				12u
	/*  */
#define IO_BANK0_INTR1_GPIO10_EDGE_HIGH				11u
	/*  */
#define IO_BANK0_INTR1_GPIO10_EDGE_LOW				10u
	/*  */
#define IO_BANK0_INTR1_GPIO10_LEVEL_HIGH			9u
	/*  */
#define IO_BANK0_INTR1_GPIO10_LEVEL_LOW				8u
	/*  */
#define IO_BANK0_INTR1_GPIO9_EDGE_HIGH				7u
	/*  */
#define IO_BANK0_INTR1_GPIO9_EDGE_LOW				6u
	/*  */
#define IO_BANK0_INTR1_GPIO9_LEVEL_HIGH				5u
	/*  */
#define IO_BANK0_INTR1_GPIO9_LEVEL_LOW				4u
	/*  */
#define IO_BANK0_INTR1_GPIO8_EDGE_HIGH				3u
	/*  */
#define IO_BANK0_INTR1_GPIO8_EDGE_LOW				2u
	/*  */
#define IO_BANK0_INTR1_GPIO8_LEVEL_HIGH				1u
	/*  */
#define IO_BANK0_INTR1_GPIO8_LEVEL_LOW				0u

	/* 0xF8: Raw Interrupts */
	uint32_t volatile INTR2;
	/*  */
#define IO_BANK0_INTR2_GPIO23_EDGE_HIGH				31u
	/*  */
#define IO_BANK0_INTR2_GPIO23_EDGE_LOW				30u
	/*  */
#define IO_BANK0_INTR2_GPIO23_LEVEL_HIGH			29u
	/*  */
#define IO_BANK0_INTR2_GPIO23_LEVEL_LOW				28u
	/*  */
#define IO_BANK0_INTR2_GPIO22_EDGE_HIGH				27u
	/*  */
#define IO_BANK0_INTR2_GPIO22_EDGE_LOW				26u
	/*  */
#define IO_BANK0_INTR2_GPIO22_LEVEL_HIGH			25u
	/*  */
#define IO_BANK0_INTR2_GPIO22_LEVEL_LOW				24u
	/*  */
#define IO_BANK0_INTR2_GPIO21_EDGE_HIGH				23u
	/*  */
#define IO_BANK0_INTR2_GPIO21_EDGE_LOW				22u
	/*  */
#define IO_BANK0_INTR2_GPIO21_LEVEL_HIGH			21u
	/*  */
#define IO_BANK0_INTR2_GPIO21_LEVEL_LOW				20u
	/*  */
#define IO_BANK0_INTR2_GPIO20_EDGE_HIGH				19u
	/*  */
#define IO_BANK0_INTR2_GPIO20_EDGE_LOW				18u
	/*  */
#define IO_BANK0_INTR2_GPIO20_LEVEL_HIGH			17u
	/*  */
#define IO_BANK0_INTR2_GPIO20_LEVEL_LOW				16u
	/*  */
#define IO_BANK0_INTR2_GPIO19_EDGE_HIGH				15u
	/*  */
#define IO_BANK0_INTR2_GPIO19_EDGE_LOW				14u
	/*  */
#define IO_BANK0_INTR2_GPIO19_LEVEL_HIGH			13u
	/*  */
#define IO_BANK0_INTR2_GPIO19_LEVEL_LOW				12u
	/*  */
#define IO_BANK0_INTR2_GPIO18_EDGE_HIGH				11u
	/*  */
#define IO_BANK0_INTR2_GPIO18_EDGE_LOW				10u
	/*  */
#define IO_BANK0_INTR2_GPIO18_LEVEL_HIGH			9u
	/*  */
#define IO_BANK0_INTR2_GPIO18_LEVEL_LOW				8u
	/*  */
#define IO_BANK0_INTR2_GPIO17_EDGE_HIGH				7u
	/*  */
#define IO_BANK0_INTR2_GPIO17_EDGE_LOW				6u
	/*  */
#define IO_BANK0_INTR2_GPIO17_LEVEL_HIGH			5u
	/*  */
#define IO_BANK0_INTR2_GPIO17_LEVEL_LOW				4u
	/*  */
#define IO_BANK0_INTR2_GPIO16_EDGE_HIGH				3u
	/*  */
#define IO_BANK0_INTR2_GPIO16_EDGE_LOW				2u
	/*  */
#define IO_BANK0_INTR2_GPIO16_LEVEL_HIGH			1u
	/*  */
#define IO_BANK0_INTR2_GPIO16_LEVEL_LOW				0u

	/* 0xFC: Raw Interrupts */
	uint32_t volatile INTR3;
	/*  */
#define IO_BANK0_INTR3_GPIO29_EDGE_HIGH				23u
	/*  */
#define IO_BANK0_INTR3_GPIO29_EDGE_LOW				22u
	/*  */
#define IO_BANK0_INTR3_GPIO29_LEVEL_HIGH			21u
	/*  */
#define IO_BANK0_INTR3_GPIO29_LEVEL_LOW				20u
	/*  */
#define IO_BANK0_INTR3_GPIO28_EDGE_HIGH				19u
	/*  */
#define IO_BANK0_INTR3_GPIO28_EDGE_LOW				18u
	/*  */
#define IO_BANK0_INTR3_GPIO28_LEVEL_HIGH			17u
	/*  */
#define IO_BANK0_INTR3_GPIO28_LEVEL_LOW				16u
	/*  */
#define IO_BANK0_INTR3_GPIO27_EDGE_HIGH				15u
	/*  */
#define IO_BANK0_INTR3_GPIO27_EDGE_LOW				14u
	/*  */
#define IO_BANK0_INTR3_GPIO27_LEVEL_HIGH			13u
	/*  */
#define IO_BANK0_INTR3_GPIO27_LEVEL_LOW				12u
	/*  */
#define IO_BANK0_INTR3_GPIO26_EDGE_HIGH				11u
	/*  */
#define IO_BANK0_INTR3_GPIO26_EDGE_LOW				10u
	/*  */
#define IO_BANK0_INTR3_GPIO26_LEVEL_HIGH			9u
	/*  */
#define IO_BANK0_INTR3_GPIO26_LEVEL_LOW				8u
	/*  */
#define IO_BANK0_INTR3_GPIO25_EDGE_HIGH				7u
	/*  */
#define IO_BANK0_INTR3_GPIO25_EDGE_LOW				6u
	/*  */
#define IO_BANK0_INTR3_GPIO25_LEVEL_HIGH			5u
	/*  */
#define IO_BANK0_INTR3_GPIO25_LEVEL_LOW				4u
	/*  */
#define IO_BANK0_INTR3_GPIO24_EDGE_HIGH				3u
	/*  */
#define IO_BANK0_INTR3_GPIO24_EDGE_LOW				2u
	/*  */
#define IO_BANK0_INTR3_GPIO24_LEVEL_HIGH			1u
	/*  */
#define IO_BANK0_INTR3_GPIO24_LEVEL_LOW				0u

	/* 0x100: Interrupt Enable for proc0 */
	uint32_t volatile PROC0_INTE0;
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO7_EDGE_HIGH			31u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO7_EDGE_LOW			30u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO7_LEVEL_HIGH			29u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO7_LEVEL_LOW			28u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO6_EDGE_HIGH			27u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO6_EDGE_LOW			26u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO6_LEVEL_HIGH			25u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO6_LEVEL_LOW			24u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO5_EDGE_HIGH			23u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO5_EDGE_LOW			22u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO5_LEVEL_HIGH			21u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO5_LEVEL_LOW			20u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO4_EDGE_HIGH			19u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO4_EDGE_LOW			18u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO4_LEVEL_HIGH			17u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO4_LEVEL_LOW			16u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO3_EDGE_HIGH			15u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO3_EDGE_LOW			14u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO3_LEVEL_HIGH			13u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO3_LEVEL_LOW			12u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO2_EDGE_HIGH			11u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO2_EDGE_LOW			10u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO2_LEVEL_HIGH			9u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO2_LEVEL_LOW			8u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO1_EDGE_HIGH			7u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO1_EDGE_LOW			6u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO1_LEVEL_HIGH			5u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO1_LEVEL_LOW			4u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO0_EDGE_HIGH			3u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO0_EDGE_LOW			2u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO0_LEVEL_HIGH			1u
	/*  */
#define IO_BANK0_PROC0_INTE0_GPIO0_LEVEL_LOW			0u

	/* 0x104: Interrupt Enable for proc0 */
	uint32_t volatile PROC0_INTE1;
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO15_EDGE_HIGH			31u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO15_EDGE_LOW			30u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO15_LEVEL_HIGH			29u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO15_LEVEL_LOW			28u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO14_EDGE_HIGH			27u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO14_EDGE_LOW			26u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO14_LEVEL_HIGH			25u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO14_LEVEL_LOW			24u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO13_EDGE_HIGH			23u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO13_EDGE_LOW			22u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO13_LEVEL_HIGH			21u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO13_LEVEL_LOW			20u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO12_EDGE_HIGH			19u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO12_EDGE_LOW			18u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO12_LEVEL_HIGH			17u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO12_LEVEL_LOW			16u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO11_EDGE_HIGH			15u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO11_EDGE_LOW			14u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO11_LEVEL_HIGH			13u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO11_LEVEL_LOW			12u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO10_EDGE_HIGH			11u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO10_EDGE_LOW			10u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO10_LEVEL_HIGH			9u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO10_LEVEL_LOW			8u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO9_EDGE_HIGH			7u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO9_EDGE_LOW			6u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO9_LEVEL_HIGH			5u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO9_LEVEL_LOW			4u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO8_EDGE_HIGH			3u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO8_EDGE_LOW			2u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO8_LEVEL_HIGH			1u
	/*  */
#define IO_BANK0_PROC0_INTE1_GPIO8_LEVEL_LOW			0u

	/* 0x108: Interrupt Enable for proc0 */
	uint32_t volatile PROC0_INTE2;
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO23_EDGE_HIGH			31u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO23_EDGE_LOW			30u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO23_LEVEL_HIGH			29u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO23_LEVEL_LOW			28u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO22_EDGE_HIGH			27u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO22_EDGE_LOW			26u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO22_LEVEL_HIGH			25u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO22_LEVEL_LOW			24u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO21_EDGE_HIGH			23u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO21_EDGE_LOW			22u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO21_LEVEL_HIGH			21u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO21_LEVEL_LOW			20u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO20_EDGE_HIGH			19u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO20_EDGE_LOW			18u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO20_LEVEL_HIGH			17u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO20_LEVEL_LOW			16u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO19_EDGE_HIGH			15u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO19_EDGE_LOW			14u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO19_LEVEL_HIGH			13u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO19_LEVEL_LOW			12u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO18_EDGE_HIGH			11u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO18_EDGE_LOW			10u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO18_LEVEL_HIGH			9u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO18_LEVEL_LOW			8u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO17_EDGE_HIGH			7u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO17_EDGE_LOW			6u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO17_LEVEL_HIGH			5u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO17_LEVEL_LOW			4u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO16_EDGE_HIGH			3u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO16_EDGE_LOW			2u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO16_LEVEL_HIGH			1u
	/*  */
#define IO_BANK0_PROC0_INTE2_GPIO16_LEVEL_LOW			0u

	/* 0x10C: Interrupt Enable for proc0 */
	uint32_t volatile PROC0_INTE3;
	/*  */
#define IO_BANK0_PROC0_INTE3_GPIO29_EDGE_HIGH			23u
	/*  */
#define IO_BANK0_PROC0_INTE3_GPIO29_EDGE_LOW			22u
	/*  */
#define IO_BANK0_PROC0_INTE3_GPIO29_LEVEL_HIGH			21u
	/*  */
#define IO_BANK0_PROC0_INTE3_GPIO29_LEVEL_LOW			20u
	/*  */
#define IO_BANK0_PROC0_INTE3_GPIO28_EDGE_HIGH			19u
	/*  */
#define IO_BANK0_PROC0_INTE3_GPIO28_EDGE_LOW			18u
	/*  */
#define IO_BANK0_PROC0_INTE3_GPIO28_LEVEL_HIGH			17u
	/*  */
#define IO_BANK0_PROC0_INTE3_GPIO28_LEVEL_LOW			16u
	/*  */
#define IO_BANK0_PROC0_INTE3_GPIO27_EDGE_HIGH			15u
	/*  */
#define IO_BANK0_PROC0_INTE3_GPIO27_EDGE_LOW			14u
	/*  */
#define IO_BANK0_PROC0_INTE3_GPIO27_LEVEL_HIGH			13u
	/*  */
#define IO_BANK0_PROC0_INTE3_GPIO27_LEVEL_LOW			12u
	/*  */
#define IO_BANK0_PROC0_INTE3_GPIO26_EDGE_HIGH			11u
	/*  */
#define IO_BANK0_PROC0_INTE3_GPIO26_EDGE_LOW			10u
	/*  */
#define IO_BANK0_PROC0_INTE3_GPIO26_LEVEL_HIGH			9u
	/*  */
#define IO_BANK0_PROC0_INTE3_GPIO26_LEVEL_LOW			8u
	/*  */
#define IO_BANK0_PROC0_INTE3_GPIO25_EDGE_HIGH			7u
	/*  */
#define IO_BANK0_PROC0_INTE3_GPIO25_EDGE_LOW			6u
	/*  */
#define IO_BANK0_PROC0_INTE3_GPIO25_LEVEL_HIGH			5u
	/*  */
#define IO_BANK0_PROC0_INTE3_GPIO25_LEVEL_LOW			4u
	/*  */
#define IO_BANK0_PROC0_INTE3_GPIO24_EDGE_HIGH			3u
	/*  */
#define IO_BANK0_PROC0_INTE3_GPIO24_EDGE_LOW			2u
	/*  */
#define IO_BANK0_PROC0_INTE3_GPIO24_LEVEL_HIGH			1u
	/*  */
#define IO_BANK0_PROC0_INTE3_GPIO24_LEVEL_LOW			0u

	/* 0x110: Interrupt Force for proc0 */
	uint32_t volatile PROC0_INTF0;
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO7_EDGE_HIGH			31u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO7_EDGE_LOW			30u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO7_LEVEL_HIGH			29u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO7_LEVEL_LOW			28u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO6_EDGE_HIGH			27u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO6_EDGE_LOW			26u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO6_LEVEL_HIGH			25u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO6_LEVEL_LOW			24u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO5_EDGE_HIGH			23u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO5_EDGE_LOW			22u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO5_LEVEL_HIGH			21u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO5_LEVEL_LOW			20u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO4_EDGE_HIGH			19u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO4_EDGE_LOW			18u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO4_LEVEL_HIGH			17u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO4_LEVEL_LOW			16u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO3_EDGE_HIGH			15u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO3_EDGE_LOW			14u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO3_LEVEL_HIGH			13u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO3_LEVEL_LOW			12u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO2_EDGE_HIGH			11u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO2_EDGE_LOW			10u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO2_LEVEL_HIGH			9u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO2_LEVEL_LOW			8u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO1_EDGE_HIGH			7u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO1_EDGE_LOW			6u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO1_LEVEL_HIGH			5u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO1_LEVEL_LOW			4u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO0_EDGE_HIGH			3u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO0_EDGE_LOW			2u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO0_LEVEL_HIGH			1u
	/*  */
#define IO_BANK0_PROC0_INTF0_GPIO0_LEVEL_LOW			0u

	/* 0x114: Interrupt Force for proc0 */
	uint32_t volatile PROC0_INTF1;
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO15_EDGE_HIGH			31u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO15_EDGE_LOW			30u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO15_LEVEL_HIGH			29u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO15_LEVEL_LOW			28u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO14_EDGE_HIGH			27u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO14_EDGE_LOW			26u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO14_LEVEL_HIGH			25u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO14_LEVEL_LOW			24u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO13_EDGE_HIGH			23u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO13_EDGE_LOW			22u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO13_LEVEL_HIGH			21u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO13_LEVEL_LOW			20u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO12_EDGE_HIGH			19u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO12_EDGE_LOW			18u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO12_LEVEL_HIGH			17u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO12_LEVEL_LOW			16u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO11_EDGE_HIGH			15u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO11_EDGE_LOW			14u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO11_LEVEL_HIGH			13u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO11_LEVEL_LOW			12u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO10_EDGE_HIGH			11u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO10_EDGE_LOW			10u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO10_LEVEL_HIGH			9u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO10_LEVEL_LOW			8u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO9_EDGE_HIGH			7u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO9_EDGE_LOW			6u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO9_LEVEL_HIGH			5u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO9_LEVEL_LOW			4u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO8_EDGE_HIGH			3u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO8_EDGE_LOW			2u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO8_LEVEL_HIGH			1u
	/*  */
#define IO_BANK0_PROC0_INTF1_GPIO8_LEVEL_LOW			0u

	/* 0x118: Interrupt Force for proc0 */
	uint32_t volatile PROC0_INTF2;
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO23_EDGE_HIGH			31u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO23_EDGE_LOW			30u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO23_LEVEL_HIGH			29u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO23_LEVEL_LOW			28u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO22_EDGE_HIGH			27u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO22_EDGE_LOW			26u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO22_LEVEL_HIGH			25u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO22_LEVEL_LOW			24u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO21_EDGE_HIGH			23u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO21_EDGE_LOW			22u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO21_LEVEL_HIGH			21u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO21_LEVEL_LOW			20u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO20_EDGE_HIGH			19u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO20_EDGE_LOW			18u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO20_LEVEL_HIGH			17u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO20_LEVEL_LOW			16u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO19_EDGE_HIGH			15u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO19_EDGE_LOW			14u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO19_LEVEL_HIGH			13u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO19_LEVEL_LOW			12u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO18_EDGE_HIGH			11u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO18_EDGE_LOW			10u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO18_LEVEL_HIGH			9u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO18_LEVEL_LOW			8u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO17_EDGE_HIGH			7u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO17_EDGE_LOW			6u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO17_LEVEL_HIGH			5u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO17_LEVEL_LOW			4u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO16_EDGE_HIGH			3u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO16_EDGE_LOW			2u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO16_LEVEL_HIGH			1u
	/*  */
#define IO_BANK0_PROC0_INTF2_GPIO16_LEVEL_LOW			0u

	/* 0x11C: Interrupt Force for proc0 */
	uint32_t volatile PROC0_INTF3;
	/*  */
#define IO_BANK0_PROC0_INTF3_GPIO29_EDGE_HIGH			23u
	/*  */
#define IO_BANK0_PROC0_INTF3_GPIO29_EDGE_LOW			22u
	/*  */
#define IO_BANK0_PROC0_INTF3_GPIO29_LEVEL_HIGH			21u
	/*  */
#define IO_BANK0_PROC0_INTF3_GPIO29_LEVEL_LOW			20u
	/*  */
#define IO_BANK0_PROC0_INTF3_GPIO28_EDGE_HIGH			19u
	/*  */
#define IO_BANK0_PROC0_INTF3_GPIO28_EDGE_LOW			18u
	/*  */
#define IO_BANK0_PROC0_INTF3_GPIO28_LEVEL_HIGH			17u
	/*  */
#define IO_BANK0_PROC0_INTF3_GPIO28_LEVEL_LOW			16u
	/*  */
#define IO_BANK0_PROC0_INTF3_GPIO27_EDGE_HIGH			15u
	/*  */
#define IO_BANK0_PROC0_INTF3_GPIO27_EDGE_LOW			14u
	/*  */
#define IO_BANK0_PROC0_INTF3_GPIO27_LEVEL_HIGH			13u
	/*  */
#define IO_BANK0_PROC0_INTF3_GPIO27_LEVEL_LOW			12u
	/*  */
#define IO_BANK0_PROC0_INTF3_GPIO26_EDGE_HIGH			11u
	/*  */
#define IO_BANK0_PROC0_INTF3_GPIO26_EDGE_LOW			10u
	/*  */
#define IO_BANK0_PROC0_INTF3_GPIO26_LEVEL_HIGH			9u
	/*  */
#define IO_BANK0_PROC0_INTF3_GPIO26_LEVEL_LOW			8u
	/*  */
#define IO_BANK0_PROC0_INTF3_GPIO25_EDGE_HIGH			7u
	/*  */
#define IO_BANK0_PROC0_INTF3_GPIO25_EDGE_LOW			6u
	/*  */
#define IO_BANK0_PROC0_INTF3_GPIO25_LEVEL_HIGH			5u
	/*  */
#define IO_BANK0_PROC0_INTF3_GPIO25_LEVEL_LOW			4u
	/*  */
#define IO_BANK0_PROC0_INTF3_GPIO24_EDGE_HIGH			3u
	/*  */
#define IO_BANK0_PROC0_INTF3_GPIO24_EDGE_LOW			2u
	/*  */
#define IO_BANK0_PROC0_INTF3_GPIO24_LEVEL_HIGH			1u
	/*  */
#define IO_BANK0_PROC0_INTF3_GPIO24_LEVEL_LOW			0u

	/* 0x120: Interrupt status after masking & forcing for proc0 */
	uint32_t volatile PROC0_INTS0;
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO7_EDGE_HIGH			31u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO7_EDGE_LOW			30u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO7_LEVEL_HIGH			29u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO7_LEVEL_LOW			28u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO6_EDGE_HIGH			27u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO6_EDGE_LOW			26u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO6_LEVEL_HIGH			25u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO6_LEVEL_LOW			24u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO5_EDGE_HIGH			23u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO5_EDGE_LOW			22u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO5_LEVEL_HIGH			21u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO5_LEVEL_LOW			20u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO4_EDGE_HIGH			19u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO4_EDGE_LOW			18u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO4_LEVEL_HIGH			17u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO4_LEVEL_LOW			16u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO3_EDGE_HIGH			15u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO3_EDGE_LOW			14u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO3_LEVEL_HIGH			13u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO3_LEVEL_LOW			12u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO2_EDGE_HIGH			11u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO2_EDGE_LOW			10u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO2_LEVEL_HIGH			9u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO2_LEVEL_LOW			8u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO1_EDGE_HIGH			7u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO1_EDGE_LOW			6u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO1_LEVEL_HIGH			5u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO1_LEVEL_LOW			4u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO0_EDGE_HIGH			3u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO0_EDGE_LOW			2u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO0_LEVEL_HIGH			1u
	/*  */
#define IO_BANK0_PROC0_INTS0_GPIO0_LEVEL_LOW			0u

	/* 0x124: Interrupt status after masking & forcing for proc0 */
	uint32_t volatile PROC0_INTS1;
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO15_EDGE_HIGH			31u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO15_EDGE_LOW			30u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO15_LEVEL_HIGH			29u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO15_LEVEL_LOW			28u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO14_EDGE_HIGH			27u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO14_EDGE_LOW			26u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO14_LEVEL_HIGH			25u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO14_LEVEL_LOW			24u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO13_EDGE_HIGH			23u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO13_EDGE_LOW			22u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO13_LEVEL_HIGH			21u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO13_LEVEL_LOW			20u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO12_EDGE_HIGH			19u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO12_EDGE_LOW			18u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO12_LEVEL_HIGH			17u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO12_LEVEL_LOW			16u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO11_EDGE_HIGH			15u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO11_EDGE_LOW			14u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO11_LEVEL_HIGH			13u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO11_LEVEL_LOW			12u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO10_EDGE_HIGH			11u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO10_EDGE_LOW			10u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO10_LEVEL_HIGH			9u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO10_LEVEL_LOW			8u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO9_EDGE_HIGH			7u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO9_EDGE_LOW			6u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO9_LEVEL_HIGH			5u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO9_LEVEL_LOW			4u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO8_EDGE_HIGH			3u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO8_EDGE_LOW			2u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO8_LEVEL_HIGH			1u
	/*  */
#define IO_BANK0_PROC0_INTS1_GPIO8_LEVEL_LOW			0u

	/* 0x128: Interrupt status after masking & forcing for proc0 */
	uint32_t volatile PROC0_INTS2;
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO23_EDGE_HIGH			31u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO23_EDGE_LOW			30u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO23_LEVEL_HIGH			29u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO23_LEVEL_LOW			28u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO22_EDGE_HIGH			27u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO22_EDGE_LOW			26u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO22_LEVEL_HIGH			25u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO22_LEVEL_LOW			24u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO21_EDGE_HIGH			23u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO21_EDGE_LOW			22u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO21_LEVEL_HIGH			21u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO21_LEVEL_LOW			20u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO20_EDGE_HIGH			19u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO20_EDGE_LOW			18u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO20_LEVEL_HIGH			17u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO20_LEVEL_LOW			16u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO19_EDGE_HIGH			15u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO19_EDGE_LOW			14u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO19_LEVEL_HIGH			13u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO19_LEVEL_LOW			12u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO18_EDGE_HIGH			11u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO18_EDGE_LOW			10u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO18_LEVEL_HIGH			9u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO18_LEVEL_LOW			8u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO17_EDGE_HIGH			7u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO17_EDGE_LOW			6u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO17_LEVEL_HIGH			5u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO17_LEVEL_LOW			4u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO16_EDGE_HIGH			3u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO16_EDGE_LOW			2u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO16_LEVEL_HIGH			1u
	/*  */
#define IO_BANK0_PROC0_INTS2_GPIO16_LEVEL_LOW			0u

	/* 0x12C: Interrupt status after masking & forcing for proc0 */
	uint32_t volatile PROC0_INTS3;
	/*  */
#define IO_BANK0_PROC0_INTS3_GPIO29_EDGE_HIGH			23u
	/*  */
#define IO_BANK0_PROC0_INTS3_GPIO29_EDGE_LOW			22u
	/*  */
#define IO_BANK0_PROC0_INTS3_GPIO29_LEVEL_HIGH			21u
	/*  */
#define IO_BANK0_PROC0_INTS3_GPIO29_LEVEL_LOW			20u
	/*  */
#define IO_BANK0_PROC0_INTS3_GPIO28_EDGE_HIGH			19u
	/*  */
#define IO_BANK0_PROC0_INTS3_GPIO28_EDGE_LOW			18u
	/*  */
#define IO_BANK0_PROC0_INTS3_GPIO28_LEVEL_HIGH			17u
	/*  */
#define IO_BANK0_PROC0_INTS3_GPIO28_LEVEL_LOW			16u
	/*  */
#define IO_BANK0_PROC0_INTS3_GPIO27_EDGE_HIGH			15u
	/*  */
#define IO_BANK0_PROC0_INTS3_GPIO27_EDGE_LOW			14u
	/*  */
#define IO_BANK0_PROC0_INTS3_GPIO27_LEVEL_HIGH			13u
	/*  */
#define IO_BANK0_PROC0_INTS3_GPIO27_LEVEL_LOW			12u
	/*  */
#define IO_BANK0_PROC0_INTS3_GPIO26_EDGE_HIGH			11u
	/*  */
#define IO_BANK0_PROC0_INTS3_GPIO26_EDGE_LOW			10u
	/*  */
#define IO_BANK0_PROC0_INTS3_GPIO26_LEVEL_HIGH			9u
	/*  */
#define IO_BANK0_PROC0_INTS3_GPIO26_LEVEL_LOW			8u
	/*  */
#define IO_BANK0_PROC0_INTS3_GPIO25_EDGE_HIGH			7u
	/*  */
#define IO_BANK0_PROC0_INTS3_GPIO25_EDGE_LOW			6u
	/*  */
#define IO_BANK0_PROC0_INTS3_GPIO25_LEVEL_HIGH			5u
	/*  */
#define IO_BANK0_PROC0_INTS3_GPIO25_LEVEL_LOW			4u
	/*  */
#define IO_BANK0_PROC0_INTS3_GPIO24_EDGE_HIGH			3u
	/*  */
#define IO_BANK0_PROC0_INTS3_GPIO24_EDGE_LOW			2u
	/*  */
#define IO_BANK0_PROC0_INTS3_GPIO24_LEVEL_HIGH			1u
	/*  */
#define IO_BANK0_PROC0_INTS3_GPIO24_LEVEL_LOW			0u

	/* 0x130: Interrupt Enable for proc1 */
	uint32_t volatile PROC1_INTE0;
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO7_EDGE_HIGH			31u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO7_EDGE_LOW			30u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO7_LEVEL_HIGH			29u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO7_LEVEL_LOW			28u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO6_EDGE_HIGH			27u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO6_EDGE_LOW			26u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO6_LEVEL_HIGH			25u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO6_LEVEL_LOW			24u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO5_EDGE_HIGH			23u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO5_EDGE_LOW			22u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO5_LEVEL_HIGH			21u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO5_LEVEL_LOW			20u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO4_EDGE_HIGH			19u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO4_EDGE_LOW			18u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO4_LEVEL_HIGH			17u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO4_LEVEL_LOW			16u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO3_EDGE_HIGH			15u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO3_EDGE_LOW			14u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO3_LEVEL_HIGH			13u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO3_LEVEL_LOW			12u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO2_EDGE_HIGH			11u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO2_EDGE_LOW			10u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO2_LEVEL_HIGH			9u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO2_LEVEL_LOW			8u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO1_EDGE_HIGH			7u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO1_EDGE_LOW			6u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO1_LEVEL_HIGH			5u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO1_LEVEL_LOW			4u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO0_EDGE_HIGH			3u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO0_EDGE_LOW			2u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO0_LEVEL_HIGH			1u
	/*  */
#define IO_BANK0_PROC1_INTE0_GPIO0_LEVEL_LOW			0u

	/* 0x134: Interrupt Enable for proc1 */
	uint32_t volatile PROC1_INTE1;
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO15_EDGE_HIGH			31u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO15_EDGE_LOW			30u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO15_LEVEL_HIGH			29u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO15_LEVEL_LOW			28u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO14_EDGE_HIGH			27u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO14_EDGE_LOW			26u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO14_LEVEL_HIGH			25u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO14_LEVEL_LOW			24u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO13_EDGE_HIGH			23u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO13_EDGE_LOW			22u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO13_LEVEL_HIGH			21u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO13_LEVEL_LOW			20u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO12_EDGE_HIGH			19u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO12_EDGE_LOW			18u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO12_LEVEL_HIGH			17u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO12_LEVEL_LOW			16u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO11_EDGE_HIGH			15u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO11_EDGE_LOW			14u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO11_LEVEL_HIGH			13u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO11_LEVEL_LOW			12u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO10_EDGE_HIGH			11u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO10_EDGE_LOW			10u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO10_LEVEL_HIGH			9u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO10_LEVEL_LOW			8u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO9_EDGE_HIGH			7u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO9_EDGE_LOW			6u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO9_LEVEL_HIGH			5u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO9_LEVEL_LOW			4u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO8_EDGE_HIGH			3u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO8_EDGE_LOW			2u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO8_LEVEL_HIGH			1u
	/*  */
#define IO_BANK0_PROC1_INTE1_GPIO8_LEVEL_LOW			0u

	/* 0x138: Interrupt Enable for proc1 */
	uint32_t volatile PROC1_INTE2;
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO23_EDGE_HIGH			31u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO23_EDGE_LOW			30u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO23_LEVEL_HIGH			29u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO23_LEVEL_LOW			28u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO22_EDGE_HIGH			27u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO22_EDGE_LOW			26u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO22_LEVEL_HIGH			25u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO22_LEVEL_LOW			24u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO21_EDGE_HIGH			23u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO21_EDGE_LOW			22u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO21_LEVEL_HIGH			21u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO21_LEVEL_LOW			20u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO20_EDGE_HIGH			19u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO20_EDGE_LOW			18u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO20_LEVEL_HIGH			17u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO20_LEVEL_LOW			16u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO19_EDGE_HIGH			15u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO19_EDGE_LOW			14u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO19_LEVEL_HIGH			13u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO19_LEVEL_LOW			12u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO18_EDGE_HIGH			11u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO18_EDGE_LOW			10u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO18_LEVEL_HIGH			9u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO18_LEVEL_LOW			8u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO17_EDGE_HIGH			7u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO17_EDGE_LOW			6u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO17_LEVEL_HIGH			5u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO17_LEVEL_LOW			4u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO16_EDGE_HIGH			3u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO16_EDGE_LOW			2u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO16_LEVEL_HIGH			1u
	/*  */
#define IO_BANK0_PROC1_INTE2_GPIO16_LEVEL_LOW			0u

	/* 0x13C: Interrupt Enable for proc1 */
	uint32_t volatile PROC1_INTE3;
	/*  */
#define IO_BANK0_PROC1_INTE3_GPIO29_EDGE_HIGH			23u
	/*  */
#define IO_BANK0_PROC1_INTE3_GPIO29_EDGE_LOW			22u
	/*  */
#define IO_BANK0_PROC1_INTE3_GPIO29_LEVEL_HIGH			21u
	/*  */
#define IO_BANK0_PROC1_INTE3_GPIO29_LEVEL_LOW			20u
	/*  */
#define IO_BANK0_PROC1_INTE3_GPIO28_EDGE_HIGH			19u
	/*  */
#define IO_BANK0_PROC1_INTE3_GPIO28_EDGE_LOW			18u
	/*  */
#define IO_BANK0_PROC1_INTE3_GPIO28_LEVEL_HIGH			17u
	/*  */
#define IO_BANK0_PROC1_INTE3_GPIO28_LEVEL_LOW			16u
	/*  */
#define IO_BANK0_PROC1_INTE3_GPIO27_EDGE_HIGH			15u
	/*  */
#define IO_BANK0_PROC1_INTE3_GPIO27_EDGE_LOW			14u
	/*  */
#define IO_BANK0_PROC1_INTE3_GPIO27_LEVEL_HIGH			13u
	/*  */
#define IO_BANK0_PROC1_INTE3_GPIO27_LEVEL_LOW			12u
	/*  */
#define IO_BANK0_PROC1_INTE3_GPIO26_EDGE_HIGH			11u
	/*  */
#define IO_BANK0_PROC1_INTE3_GPIO26_EDGE_LOW			10u
	/*  */
#define IO_BANK0_PROC1_INTE3_GPIO26_LEVEL_HIGH			9u
	/*  */
#define IO_BANK0_PROC1_INTE3_GPIO26_LEVEL_LOW			8u
	/*  */
#define IO_BANK0_PROC1_INTE3_GPIO25_EDGE_HIGH			7u
	/*  */
#define IO_BANK0_PROC1_INTE3_GPIO25_EDGE_LOW			6u
	/*  */
#define IO_BANK0_PROC1_INTE3_GPIO25_LEVEL_HIGH			5u
	/*  */
#define IO_BANK0_PROC1_INTE3_GPIO25_LEVEL_LOW			4u
	/*  */
#define IO_BANK0_PROC1_INTE3_GPIO24_EDGE_HIGH			3u
	/*  */
#define IO_BANK0_PROC1_INTE3_GPIO24_EDGE_LOW			2u
	/*  */
#define IO_BANK0_PROC1_INTE3_GPIO24_LEVEL_HIGH			1u
	/*  */
#define IO_BANK0_PROC1_INTE3_GPIO24_LEVEL_LOW			0u

	/* 0x140: Interrupt Force for proc1 */
	uint32_t volatile PROC1_INTF0;
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO7_EDGE_HIGH			31u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO7_EDGE_LOW			30u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO7_LEVEL_HIGH			29u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO7_LEVEL_LOW			28u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO6_EDGE_HIGH			27u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO6_EDGE_LOW			26u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO6_LEVEL_HIGH			25u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO6_LEVEL_LOW			24u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO5_EDGE_HIGH			23u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO5_EDGE_LOW			22u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO5_LEVEL_HIGH			21u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO5_LEVEL_LOW			20u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO4_EDGE_HIGH			19u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO4_EDGE_LOW			18u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO4_LEVEL_HIGH			17u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO4_LEVEL_LOW			16u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO3_EDGE_HIGH			15u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO3_EDGE_LOW			14u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO3_LEVEL_HIGH			13u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO3_LEVEL_LOW			12u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO2_EDGE_HIGH			11u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO2_EDGE_LOW			10u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO2_LEVEL_HIGH			9u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO2_LEVEL_LOW			8u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO1_EDGE_HIGH			7u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO1_EDGE_LOW			6u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO1_LEVEL_HIGH			5u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO1_LEVEL_LOW			4u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO0_EDGE_HIGH			3u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO0_EDGE_LOW			2u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO0_LEVEL_HIGH			1u
	/*  */
#define IO_BANK0_PROC1_INTF0_GPIO0_LEVEL_LOW			0u

	/* 0x144: Interrupt Force for proc1 */
	uint32_t volatile PROC1_INTF1;
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO15_EDGE_HIGH			31u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO15_EDGE_LOW			30u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO15_LEVEL_HIGH			29u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO15_LEVEL_LOW			28u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO14_EDGE_HIGH			27u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO14_EDGE_LOW			26u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO14_LEVEL_HIGH			25u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO14_LEVEL_LOW			24u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO13_EDGE_HIGH			23u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO13_EDGE_LOW			22u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO13_LEVEL_HIGH			21u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO13_LEVEL_LOW			20u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO12_EDGE_HIGH			19u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO12_EDGE_LOW			18u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO12_LEVEL_HIGH			17u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO12_LEVEL_LOW			16u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO11_EDGE_HIGH			15u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO11_EDGE_LOW			14u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO11_LEVEL_HIGH			13u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO11_LEVEL_LOW			12u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO10_EDGE_HIGH			11u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO10_EDGE_LOW			10u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO10_LEVEL_HIGH			9u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO10_LEVEL_LOW			8u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO9_EDGE_HIGH			7u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO9_EDGE_LOW			6u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO9_LEVEL_HIGH			5u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO9_LEVEL_LOW			4u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO8_EDGE_HIGH			3u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO8_EDGE_LOW			2u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO8_LEVEL_HIGH			1u
	/*  */
#define IO_BANK0_PROC1_INTF1_GPIO8_LEVEL_LOW			0u

	/* 0x148: Interrupt Force for proc1 */
	uint32_t volatile PROC1_INTF2;
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO23_EDGE_HIGH			31u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO23_EDGE_LOW			30u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO23_LEVEL_HIGH			29u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO23_LEVEL_LOW			28u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO22_EDGE_HIGH			27u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO22_EDGE_LOW			26u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO22_LEVEL_HIGH			25u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO22_LEVEL_LOW			24u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO21_EDGE_HIGH			23u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO21_EDGE_LOW			22u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO21_LEVEL_HIGH			21u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO21_LEVEL_LOW			20u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO20_EDGE_HIGH			19u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO20_EDGE_LOW			18u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO20_LEVEL_HIGH			17u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO20_LEVEL_LOW			16u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO19_EDGE_HIGH			15u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO19_EDGE_LOW			14u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO19_LEVEL_HIGH			13u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO19_LEVEL_LOW			12u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO18_EDGE_HIGH			11u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO18_EDGE_LOW			10u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO18_LEVEL_HIGH			9u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO18_LEVEL_LOW			8u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO17_EDGE_HIGH			7u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO17_EDGE_LOW			6u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO17_LEVEL_HIGH			5u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO17_LEVEL_LOW			4u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO16_EDGE_HIGH			3u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO16_EDGE_LOW			2u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO16_LEVEL_HIGH			1u
	/*  */
#define IO_BANK0_PROC1_INTF2_GPIO16_LEVEL_LOW			0u

	/* 0x14C: Interrupt Force for proc1 */
	uint32_t volatile PROC1_INTF3;
	/*  */
#define IO_BANK0_PROC1_INTF3_GPIO29_EDGE_HIGH			23u
	/*  */
#define IO_BANK0_PROC1_INTF3_GPIO29_EDGE_LOW			22u
	/*  */
#define IO_BANK0_PROC1_INTF3_GPIO29_LEVEL_HIGH			21u
	/*  */
#define IO_BANK0_PROC1_INTF3_GPIO29_LEVEL_LOW			20u
	/*  */
#define IO_BANK0_PROC1_INTF3_GPIO28_EDGE_HIGH			19u
	/*  */
#define IO_BANK0_PROC1_INTF3_GPIO28_EDGE_LOW			18u
	/*  */
#define IO_BANK0_PROC1_INTF3_GPIO28_LEVEL_HIGH			17u
	/*  */
#define IO_BANK0_PROC1_INTF3_GPIO28_LEVEL_LOW			16u
	/*  */
#define IO_BANK0_PROC1_INTF3_GPIO27_EDGE_HIGH			15u
	/*  */
#define IO_BANK0_PROC1_INTF3_GPIO27_EDGE_LOW			14u
	/*  */
#define IO_BANK0_PROC1_INTF3_GPIO27_LEVEL_HIGH			13u
	/*  */
#define IO_BANK0_PROC1_INTF3_GPIO27_LEVEL_LOW			12u
	/*  */
#define IO_BANK0_PROC1_INTF3_GPIO26_EDGE_HIGH			11u
	/*  */
#define IO_BANK0_PROC1_INTF3_GPIO26_EDGE_LOW			10u
	/*  */
#define IO_BANK0_PROC1_INTF3_GPIO26_LEVEL_HIGH			9u
	/*  */
#define IO_BANK0_PROC1_INTF3_GPIO26_LEVEL_LOW			8u
	/*  */
#define IO_BANK0_PROC1_INTF3_GPIO25_EDGE_HIGH			7u
	/*  */
#define IO_BANK0_PROC1_INTF3_GPIO25_EDGE_LOW			6u
	/*  */
#define IO_BANK0_PROC1_INTF3_GPIO25_LEVEL_HIGH			5u
	/*  */
#define IO_BANK0_PROC1_INTF3_GPIO25_LEVEL_LOW			4u
	/*  */
#define IO_BANK0_PROC1_INTF3_GPIO24_EDGE_HIGH			3u
	/*  */
#define IO_BANK0_PROC1_INTF3_GPIO24_EDGE_LOW			2u
	/*  */
#define IO_BANK0_PROC1_INTF3_GPIO24_LEVEL_HIGH			1u
	/*  */
#define IO_BANK0_PROC1_INTF3_GPIO24_LEVEL_LOW			0u

	/* 0x150: Interrupt status after masking & forcing for proc1 */
	uint32_t volatile PROC1_INTS0;
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO7_EDGE_HIGH			31u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO7_EDGE_LOW			30u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO7_LEVEL_HIGH			29u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO7_LEVEL_LOW			28u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO6_EDGE_HIGH			27u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO6_EDGE_LOW			26u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO6_LEVEL_HIGH			25u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO6_LEVEL_LOW			24u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO5_EDGE_HIGH			23u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO5_EDGE_LOW			22u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO5_LEVEL_HIGH			21u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO5_LEVEL_LOW			20u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO4_EDGE_HIGH			19u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO4_EDGE_LOW			18u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO4_LEVEL_HIGH			17u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO4_LEVEL_LOW			16u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO3_EDGE_HIGH			15u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO3_EDGE_LOW			14u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO3_LEVEL_HIGH			13u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO3_LEVEL_LOW			12u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO2_EDGE_HIGH			11u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO2_EDGE_LOW			10u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO2_LEVEL_HIGH			9u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO2_LEVEL_LOW			8u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO1_EDGE_HIGH			7u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO1_EDGE_LOW			6u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO1_LEVEL_HIGH			5u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO1_LEVEL_LOW			4u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO0_EDGE_HIGH			3u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO0_EDGE_LOW			2u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO0_LEVEL_HIGH			1u
	/*  */
#define IO_BANK0_PROC1_INTS0_GPIO0_LEVEL_LOW			0u

	/* 0x154: Interrupt status after masking & forcing for proc1 */
	uint32_t volatile PROC1_INTS1;
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO15_EDGE_HIGH			31u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO15_EDGE_LOW			30u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO15_LEVEL_HIGH			29u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO15_LEVEL_LOW			28u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO14_EDGE_HIGH			27u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO14_EDGE_LOW			26u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO14_LEVEL_HIGH			25u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO14_LEVEL_LOW			24u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO13_EDGE_HIGH			23u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO13_EDGE_LOW			22u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO13_LEVEL_HIGH			21u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO13_LEVEL_LOW			20u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO12_EDGE_HIGH			19u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO12_EDGE_LOW			18u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO12_LEVEL_HIGH			17u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO12_LEVEL_LOW			16u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO11_EDGE_HIGH			15u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO11_EDGE_LOW			14u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO11_LEVEL_HIGH			13u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO11_LEVEL_LOW			12u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO10_EDGE_HIGH			11u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO10_EDGE_LOW			10u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO10_LEVEL_HIGH			9u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO10_LEVEL_LOW			8u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO9_EDGE_HIGH			7u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO9_EDGE_LOW			6u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO9_LEVEL_HIGH			5u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO9_LEVEL_LOW			4u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO8_EDGE_HIGH			3u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO8_EDGE_LOW			2u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO8_LEVEL_HIGH			1u
	/*  */
#define IO_BANK0_PROC1_INTS1_GPIO8_LEVEL_LOW			0u

	/* 0x158: Interrupt status after masking & forcing for proc1 */
	uint32_t volatile PROC1_INTS2;
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO23_EDGE_HIGH			31u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO23_EDGE_LOW			30u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO23_LEVEL_HIGH			29u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO23_LEVEL_LOW			28u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO22_EDGE_HIGH			27u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO22_EDGE_LOW			26u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO22_LEVEL_HIGH			25u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO22_LEVEL_LOW			24u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO21_EDGE_HIGH			23u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO21_EDGE_LOW			22u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO21_LEVEL_HIGH			21u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO21_LEVEL_LOW			20u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO20_EDGE_HIGH			19u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO20_EDGE_LOW			18u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO20_LEVEL_HIGH			17u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO20_LEVEL_LOW			16u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO19_EDGE_HIGH			15u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO19_EDGE_LOW			14u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO19_LEVEL_HIGH			13u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO19_LEVEL_LOW			12u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO18_EDGE_HIGH			11u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO18_EDGE_LOW			10u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO18_LEVEL_HIGH			9u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO18_LEVEL_LOW			8u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO17_EDGE_HIGH			7u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO17_EDGE_LOW			6u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO17_LEVEL_HIGH			5u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO17_LEVEL_LOW			4u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO16_EDGE_HIGH			3u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO16_EDGE_LOW			2u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO16_LEVEL_HIGH			1u
	/*  */
#define IO_BANK0_PROC1_INTS2_GPIO16_LEVEL_LOW			0u

	/* 0x15C: Interrupt status after masking & forcing for proc1 */
	uint32_t volatile PROC1_INTS3;
	/*  */
#define IO_BANK0_PROC1_INTS3_GPIO29_EDGE_HIGH			23u
	/*  */
#define IO_BANK0_PROC1_INTS3_GPIO29_EDGE_LOW			22u
	/*  */
#define IO_BANK0_PROC1_INTS3_GPIO29_LEVEL_HIGH			21u
	/*  */
#define IO_BANK0_PROC1_INTS3_GPIO29_LEVEL_LOW			20u
	/*  */
#define IO_BANK0_PROC1_INTS3_GPIO28_EDGE_HIGH			19u
	/*  */
#define IO_BANK0_PROC1_INTS3_GPIO28_EDGE_LOW			18u
	/*  */
#define IO_BANK0_PROC1_INTS3_GPIO28_LEVEL_HIGH			17u
	/*  */
#define IO_BANK0_PROC1_INTS3_GPIO28_LEVEL_LOW			16u
	/*  */
#define IO_BANK0_PROC1_INTS3_GPIO27_EDGE_HIGH			15u
	/*  */
#define IO_BANK0_PROC1_INTS3_GPIO27_EDGE_LOW			14u
	/*  */
#define IO_BANK0_PROC1_INTS3_GPIO27_LEVEL_HIGH			13u
	/*  */
#define IO_BANK0_PROC1_INTS3_GPIO27_LEVEL_LOW			12u
	/*  */
#define IO_BANK0_PROC1_INTS3_GPIO26_EDGE_HIGH			11u
	/*  */
#define IO_BANK0_PROC1_INTS3_GPIO26_EDGE_LOW			10u
	/*  */
#define IO_BANK0_PROC1_INTS3_GPIO26_LEVEL_HIGH			9u
	/*  */
#define IO_BANK0_PROC1_INTS3_GPIO26_LEVEL_LOW			8u
	/*  */
#define IO_BANK0_PROC1_INTS3_GPIO25_EDGE_HIGH			7u
	/*  */
#define IO_BANK0_PROC1_INTS3_GPIO25_EDGE_LOW			6u
	/*  */
#define IO_BANK0_PROC1_INTS3_GPIO25_LEVEL_HIGH			5u
	/*  */
#define IO_BANK0_PROC1_INTS3_GPIO25_LEVEL_LOW			4u
	/*  */
#define IO_BANK0_PROC1_INTS3_GPIO24_EDGE_HIGH			3u
	/*  */
#define IO_BANK0_PROC1_INTS3_GPIO24_EDGE_LOW			2u
	/*  */
#define IO_BANK0_PROC1_INTS3_GPIO24_LEVEL_HIGH			1u
	/*  */
#define IO_BANK0_PROC1_INTS3_GPIO24_LEVEL_LOW			0u

	/* 0x160: Interrupt Enable for dormant_wake */
	uint32_t volatile DORMANT_WAKE_INTE0;
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO7_EDGE_HIGH		31u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO7_EDGE_LOW		30u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO7_LEVEL_HIGH		29u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO7_LEVEL_LOW		28u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO6_EDGE_HIGH		27u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO6_EDGE_LOW		26u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO6_LEVEL_HIGH		25u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO6_LEVEL_LOW		24u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO5_EDGE_HIGH		23u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO5_EDGE_LOW		22u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO5_LEVEL_HIGH		21u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO5_LEVEL_LOW		20u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO4_EDGE_HIGH		19u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO4_EDGE_LOW		18u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO4_LEVEL_HIGH		17u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO4_LEVEL_LOW		16u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO3_EDGE_HIGH		15u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO3_EDGE_LOW		14u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO3_LEVEL_HIGH		13u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO3_LEVEL_LOW		12u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO2_EDGE_HIGH		11u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO2_EDGE_LOW		10u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO2_LEVEL_HIGH		9u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO2_LEVEL_LOW		8u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO1_EDGE_HIGH		7u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO1_EDGE_LOW		6u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO1_LEVEL_HIGH		5u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO1_LEVEL_LOW		4u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO0_EDGE_HIGH		3u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO0_EDGE_LOW		2u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO0_LEVEL_HIGH		1u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE0_GPIO0_LEVEL_LOW		0u

	/* 0x164: Interrupt Enable for dormant_wake */
	uint32_t volatile DORMANT_WAKE_INTE1;
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO15_EDGE_HIGH		31u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO15_EDGE_LOW		30u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO15_LEVEL_HIGH		29u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO15_LEVEL_LOW		28u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO14_EDGE_HIGH		27u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO14_EDGE_LOW		26u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO14_LEVEL_HIGH		25u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO14_LEVEL_LOW		24u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO13_EDGE_HIGH		23u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO13_EDGE_LOW		22u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO13_LEVEL_HIGH		21u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO13_LEVEL_LOW		20u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO12_EDGE_HIGH		19u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO12_EDGE_LOW		18u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO12_LEVEL_HIGH		17u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO12_LEVEL_LOW		16u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO11_EDGE_HIGH		15u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO11_EDGE_LOW		14u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO11_LEVEL_HIGH		13u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO11_LEVEL_LOW		12u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO10_EDGE_HIGH		11u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO10_EDGE_LOW		10u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO10_LEVEL_HIGH		9u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO10_LEVEL_LOW		8u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO9_EDGE_HIGH		7u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO9_EDGE_LOW		6u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO9_LEVEL_HIGH		5u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO9_LEVEL_LOW		4u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO8_EDGE_HIGH		3u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO8_EDGE_LOW		2u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO8_LEVEL_HIGH		1u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE1_GPIO8_LEVEL_LOW		0u

	/* 0x168: Interrupt Enable for dormant_wake */
	uint32_t volatile DORMANT_WAKE_INTE2;
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO23_EDGE_HIGH		31u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO23_EDGE_LOW		30u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO23_LEVEL_HIGH		29u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO23_LEVEL_LOW		28u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO22_EDGE_HIGH		27u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO22_EDGE_LOW		26u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO22_LEVEL_HIGH		25u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO22_LEVEL_LOW		24u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO21_EDGE_HIGH		23u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO21_EDGE_LOW		22u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO21_LEVEL_HIGH		21u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO21_LEVEL_LOW		20u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO20_EDGE_HIGH		19u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO20_EDGE_LOW		18u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO20_LEVEL_HIGH		17u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO20_LEVEL_LOW		16u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO19_EDGE_HIGH		15u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO19_EDGE_LOW		14u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO19_LEVEL_HIGH		13u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO19_LEVEL_LOW		12u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO18_EDGE_HIGH		11u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO18_EDGE_LOW		10u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO18_LEVEL_HIGH		9u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO18_LEVEL_LOW		8u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO17_EDGE_HIGH		7u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO17_EDGE_LOW		6u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO17_LEVEL_HIGH		5u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO17_LEVEL_LOW		4u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO16_EDGE_HIGH		3u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO16_EDGE_LOW		2u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO16_LEVEL_HIGH		1u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE2_GPIO16_LEVEL_LOW		0u

	/* 0x16C: Interrupt Enable for dormant_wake */
	uint32_t volatile DORMANT_WAKE_INTE3;
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO29_EDGE_HIGH		23u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO29_EDGE_LOW		22u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO29_LEVEL_HIGH		21u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO29_LEVEL_LOW		20u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO28_EDGE_HIGH		19u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO28_EDGE_LOW		18u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO28_LEVEL_HIGH		17u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO28_LEVEL_LOW		16u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO27_EDGE_HIGH		15u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO27_EDGE_LOW		14u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO27_LEVEL_HIGH		13u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO27_LEVEL_LOW		12u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO26_EDGE_HIGH		11u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO26_EDGE_LOW		10u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO26_LEVEL_HIGH		9u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO26_LEVEL_LOW		8u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO25_EDGE_HIGH		7u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO25_EDGE_LOW		6u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO25_LEVEL_HIGH		5u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO25_LEVEL_LOW		4u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO24_EDGE_HIGH		3u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO24_EDGE_LOW		2u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO24_LEVEL_HIGH		1u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTE3_GPIO24_LEVEL_LOW		0u

	/* 0x170: Interrupt Force for dormant_wake */
	uint32_t volatile DORMANT_WAKE_INTF0;
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO7_EDGE_HIGH		31u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO7_EDGE_LOW		30u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO7_LEVEL_HIGH		29u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO7_LEVEL_LOW		28u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO6_EDGE_HIGH		27u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO6_EDGE_LOW		26u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO6_LEVEL_HIGH		25u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO6_LEVEL_LOW		24u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO5_EDGE_HIGH		23u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO5_EDGE_LOW		22u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO5_LEVEL_HIGH		21u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO5_LEVEL_LOW		20u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO4_EDGE_HIGH		19u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO4_EDGE_LOW		18u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO4_LEVEL_HIGH		17u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO4_LEVEL_LOW		16u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO3_EDGE_HIGH		15u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO3_EDGE_LOW		14u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO3_LEVEL_HIGH		13u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO3_LEVEL_LOW		12u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO2_EDGE_HIGH		11u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO2_EDGE_LOW		10u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO2_LEVEL_HIGH		9u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO2_LEVEL_LOW		8u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO1_EDGE_HIGH		7u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO1_EDGE_LOW		6u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO1_LEVEL_HIGH		5u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO1_LEVEL_LOW		4u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO0_EDGE_HIGH		3u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO0_EDGE_LOW		2u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO0_LEVEL_HIGH		1u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF0_GPIO0_LEVEL_LOW		0u

	/* 0x174: Interrupt Force for dormant_wake */
	uint32_t volatile DORMANT_WAKE_INTF1;
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO15_EDGE_HIGH		31u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO15_EDGE_LOW		30u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO15_LEVEL_HIGH		29u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO15_LEVEL_LOW		28u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO14_EDGE_HIGH		27u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO14_EDGE_LOW		26u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO14_LEVEL_HIGH		25u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO14_LEVEL_LOW		24u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO13_EDGE_HIGH		23u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO13_EDGE_LOW		22u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO13_LEVEL_HIGH		21u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO13_LEVEL_LOW		20u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO12_EDGE_HIGH		19u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO12_EDGE_LOW		18u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO12_LEVEL_HIGH		17u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO12_LEVEL_LOW		16u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO11_EDGE_HIGH		15u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO11_EDGE_LOW		14u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO11_LEVEL_HIGH		13u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO11_LEVEL_LOW		12u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO10_EDGE_HIGH		11u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO10_EDGE_LOW		10u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO10_LEVEL_HIGH		9u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO10_LEVEL_LOW		8u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO9_EDGE_HIGH		7u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO9_EDGE_LOW		6u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO9_LEVEL_HIGH		5u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO9_LEVEL_LOW		4u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO8_EDGE_HIGH		3u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO8_EDGE_LOW		2u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO8_LEVEL_HIGH		1u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF1_GPIO8_LEVEL_LOW		0u

	/* 0x178: Interrupt Force for dormant_wake */
	uint32_t volatile DORMANT_WAKE_INTF2;
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO23_EDGE_HIGH		31u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO23_EDGE_LOW		30u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO23_LEVEL_HIGH		29u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO23_LEVEL_LOW		28u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO22_EDGE_HIGH		27u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO22_EDGE_LOW		26u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO22_LEVEL_HIGH		25u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO22_LEVEL_LOW		24u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO21_EDGE_HIGH		23u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO21_EDGE_LOW		22u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO21_LEVEL_HIGH		21u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO21_LEVEL_LOW		20u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO20_EDGE_HIGH		19u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO20_EDGE_LOW		18u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO20_LEVEL_HIGH		17u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO20_LEVEL_LOW		16u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO19_EDGE_HIGH		15u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO19_EDGE_LOW		14u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO19_LEVEL_HIGH		13u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO19_LEVEL_LOW		12u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO18_EDGE_HIGH		11u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO18_EDGE_LOW		10u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO18_LEVEL_HIGH		9u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO18_LEVEL_LOW		8u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO17_EDGE_HIGH		7u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO17_EDGE_LOW		6u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO17_LEVEL_HIGH		5u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO17_LEVEL_LOW		4u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO16_EDGE_HIGH		3u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO16_EDGE_LOW		2u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO16_LEVEL_HIGH		1u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF2_GPIO16_LEVEL_LOW		0u

	/* 0x17C: Interrupt Force for dormant_wake */
	uint32_t volatile DORMANT_WAKE_INTF3;
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO29_EDGE_HIGH		23u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO29_EDGE_LOW		22u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO29_LEVEL_HIGH		21u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO29_LEVEL_LOW		20u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO28_EDGE_HIGH		19u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO28_EDGE_LOW		18u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO28_LEVEL_HIGH		17u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO28_LEVEL_LOW		16u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO27_EDGE_HIGH		15u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO27_EDGE_LOW		14u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO27_LEVEL_HIGH		13u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO27_LEVEL_LOW		12u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO26_EDGE_HIGH		11u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO26_EDGE_LOW		10u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO26_LEVEL_HIGH		9u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO26_LEVEL_LOW		8u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO25_EDGE_HIGH		7u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO25_EDGE_LOW		6u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO25_LEVEL_HIGH		5u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO25_LEVEL_LOW		4u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO24_EDGE_HIGH		3u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO24_EDGE_LOW		2u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO24_LEVEL_HIGH		1u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTF3_GPIO24_LEVEL_LOW		0u

	/* 0x180: Interrupt status after masking & forcing for dormant_wake */
	uint32_t volatile DORMANT_WAKE_INTS0;
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO7_EDGE_HIGH		31u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO7_EDGE_LOW		30u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO7_LEVEL_HIGH		29u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO7_LEVEL_LOW		28u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO6_EDGE_HIGH		27u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO6_EDGE_LOW		26u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO6_LEVEL_HIGH		25u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO6_LEVEL_LOW		24u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO5_EDGE_HIGH		23u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO5_EDGE_LOW		22u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO5_LEVEL_HIGH		21u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO5_LEVEL_LOW		20u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO4_EDGE_HIGH		19u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO4_EDGE_LOW		18u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO4_LEVEL_HIGH		17u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO4_LEVEL_LOW		16u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO3_EDGE_HIGH		15u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO3_EDGE_LOW		14u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO3_LEVEL_HIGH		13u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO3_LEVEL_LOW		12u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO2_EDGE_HIGH		11u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO2_EDGE_LOW		10u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO2_LEVEL_HIGH		9u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO2_LEVEL_LOW		8u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO1_EDGE_HIGH		7u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO1_EDGE_LOW		6u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO1_LEVEL_HIGH		5u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO1_LEVEL_LOW		4u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO0_EDGE_HIGH		3u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO0_EDGE_LOW		2u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO0_LEVEL_HIGH		1u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS0_GPIO0_LEVEL_LOW		0u

	/* 0x184: Interrupt status after masking & forcing for dormant_wake */
	uint32_t volatile DORMANT_WAKE_INTS1;
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO15_EDGE_HIGH		31u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO15_EDGE_LOW		30u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO15_LEVEL_HIGH		29u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO15_LEVEL_LOW		28u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO14_EDGE_HIGH		27u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO14_EDGE_LOW		26u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO14_LEVEL_HIGH		25u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO14_LEVEL_LOW		24u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO13_EDGE_HIGH		23u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO13_EDGE_LOW		22u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO13_LEVEL_HIGH		21u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO13_LEVEL_LOW		20u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO12_EDGE_HIGH		19u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO12_EDGE_LOW		18u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO12_LEVEL_HIGH		17u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO12_LEVEL_LOW		16u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO11_EDGE_HIGH		15u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO11_EDGE_LOW		14u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO11_LEVEL_HIGH		13u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO11_LEVEL_LOW		12u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO10_EDGE_HIGH		11u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO10_EDGE_LOW		10u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO10_LEVEL_HIGH		9u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO10_LEVEL_LOW		8u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO9_EDGE_HIGH		7u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO9_EDGE_LOW		6u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO9_LEVEL_HIGH		5u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO9_LEVEL_LOW		4u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO8_EDGE_HIGH		3u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO8_EDGE_LOW		2u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO8_LEVEL_HIGH		1u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS1_GPIO8_LEVEL_LOW		0u

	/* 0x188: Interrupt status after masking & forcing for dormant_wake */
	uint32_t volatile DORMANT_WAKE_INTS2;
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO23_EDGE_HIGH		31u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO23_EDGE_LOW		30u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO23_LEVEL_HIGH		29u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO23_LEVEL_LOW		28u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO22_EDGE_HIGH		27u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO22_EDGE_LOW		26u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO22_LEVEL_HIGH		25u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO22_LEVEL_LOW		24u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO21_EDGE_HIGH		23u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO21_EDGE_LOW		22u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO21_LEVEL_HIGH		21u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO21_LEVEL_LOW		20u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO20_EDGE_HIGH		19u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO20_EDGE_LOW		18u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO20_LEVEL_HIGH		17u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO20_LEVEL_LOW		16u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO19_EDGE_HIGH		15u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO19_EDGE_LOW		14u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO19_LEVEL_HIGH		13u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO19_LEVEL_LOW		12u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO18_EDGE_HIGH		11u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO18_EDGE_LOW		10u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO18_LEVEL_HIGH		9u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO18_LEVEL_LOW		8u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO17_EDGE_HIGH		7u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO17_EDGE_LOW		6u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO17_LEVEL_HIGH		5u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO17_LEVEL_LOW		4u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO16_EDGE_HIGH		3u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO16_EDGE_LOW		2u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO16_LEVEL_HIGH		1u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS2_GPIO16_LEVEL_LOW		0u

	/* 0x18C: Interrupt status after masking & forcing for dormant_wake */
	uint32_t volatile DORMANT_WAKE_INTS3;
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO29_EDGE_HIGH		23u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO29_EDGE_LOW		22u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO29_LEVEL_HIGH		21u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO29_LEVEL_LOW		20u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO28_EDGE_HIGH		19u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO28_EDGE_LOW		18u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO28_LEVEL_HIGH		17u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO28_LEVEL_LOW		16u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO27_EDGE_HIGH		15u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO27_EDGE_LOW		14u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO27_LEVEL_HIGH		13u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO27_LEVEL_LOW		12u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO26_EDGE_HIGH		11u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO26_EDGE_LOW		10u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO26_LEVEL_HIGH		9u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO26_LEVEL_LOW		8u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO25_EDGE_HIGH		7u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO25_EDGE_LOW		6u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO25_LEVEL_HIGH		5u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO25_LEVEL_LOW		4u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO24_EDGE_HIGH		3u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO24_EDGE_LOW		2u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO24_LEVEL_HIGH		1u
	/*  */
#define IO_BANK0_DORMANT_WAKE_INTS3_GPIO24_LEVEL_LOW		0u

};


#define IO_QSPI ((struct sdk_io_qspi *)0x40018000)

struct sdk_io_qspi {

	/* 0x00: GPIO status */
	uint32_t volatile GPIO_QSPI_SCLK_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_QSPI_GPIO_QSPI_SCLK_STATUS_IRQTOPROC			26u
	/* interrupt from pad before override is applied */
#define IO_QSPI_GPIO_QSPI_SCLK_STATUS_IRQFROMPAD		24u
	/* input signal to peripheral, after override is applied */
#define IO_QSPI_GPIO_QSPI_SCLK_STATUS_INTOPERI			19u
	/* input signal from pad, before override is applied */
#define IO_QSPI_GPIO_QSPI_SCLK_STATUS_INFROMPAD			17u
	/* output enable to pad after register override is applied */
#define IO_QSPI_GPIO_QSPI_SCLK_STATUS_OETOPAD			13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_QSPI_GPIO_QSPI_SCLK_STATUS_OEFROMPERI		12u
	/* output signal to pad after register override is applied */
#define IO_QSPI_GPIO_QSPI_SCLK_STATUS_OUTTOPAD			9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_QSPI_GPIO_QSPI_SCLK_STATUS_OUTFROMPERI		8u

	/* 0x04: GPIO control including function select and overrides. */
	uint32_t volatile GPIO_QSPI_SCLK_CTRL;
	/*  */
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_IRQOVER_Msb			29u
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_IRQOVER_Lsb			28u
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_IRQOVER_NORMAL		0u
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_IRQOVER_INVERT		1u
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_IRQOVER_LOW			2u
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_IRQOVER_HIGH		3u
	/*  */
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_INOVER_Msb			17u
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_INOVER_Lsb			16u
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_INOVER_NORMAL		0u
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_INOVER_INVERT		1u
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_INOVER_LOW			2u
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_INOVER_HIGH			3u
	/*  */
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_OEOVER_Msb			13u
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_OEOVER_Lsb			12u
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_OEOVER_NORMAL		0u
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_OEOVER_INVERT		1u
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_OEOVER_DISABLE		2u
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_OEOVER_ENABLE		3u
	/*  */
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_OUTOVER_Msb			9u
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_OUTOVER_Lsb			8u
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_OUTOVER_NORMAL		0u
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_OUTOVER_INVERT		1u
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_OUTOVER_LOW			2u
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_OUTOVER_HIGH		3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_FUNCSEL_Msb			4u
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_FUNCSEL_Lsb			0u
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_FUNCSEL_XIP_SCLK		0u
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_FUNCSEL_SIO_30		5u
#define IO_QSPI_GPIO_QSPI_SCLK_CTRL_FUNCSEL_NULL		31u

	/* 0x08: GPIO status */
	uint32_t volatile GPIO_QSPI_SS_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_QSPI_GPIO_QSPI_SS_STATUS_IRQTOPROC			26u
	/* interrupt from pad before override is applied */
#define IO_QSPI_GPIO_QSPI_SS_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_QSPI_GPIO_QSPI_SS_STATUS_INTOPERI			19u
	/* input signal from pad, before override is applied */
#define IO_QSPI_GPIO_QSPI_SS_STATUS_INFROMPAD			17u
	/* output enable to pad after register override is applied */
#define IO_QSPI_GPIO_QSPI_SS_STATUS_OETOPAD			13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_QSPI_GPIO_QSPI_SS_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_QSPI_GPIO_QSPI_SS_STATUS_OUTTOPAD			9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_QSPI_GPIO_QSPI_SS_STATUS_OUTFROMPERI			8u

	/* 0x0C: GPIO control including function select and overrides. */
	uint32_t volatile GPIO_QSPI_SS_CTRL;
	/*  */
#define IO_QSPI_GPIO_QSPI_SS_CTRL_IRQOVER_Msb			29u
#define IO_QSPI_GPIO_QSPI_SS_CTRL_IRQOVER_Lsb			28u
#define IO_QSPI_GPIO_QSPI_SS_CTRL_IRQOVER_NORMAL		0u
#define IO_QSPI_GPIO_QSPI_SS_CTRL_IRQOVER_INVERT		1u
#define IO_QSPI_GPIO_QSPI_SS_CTRL_IRQOVER_LOW			2u
#define IO_QSPI_GPIO_QSPI_SS_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_QSPI_GPIO_QSPI_SS_CTRL_INOVER_Msb			17u
#define IO_QSPI_GPIO_QSPI_SS_CTRL_INOVER_Lsb			16u
#define IO_QSPI_GPIO_QSPI_SS_CTRL_INOVER_NORMAL			0u
#define IO_QSPI_GPIO_QSPI_SS_CTRL_INOVER_INVERT			1u
#define IO_QSPI_GPIO_QSPI_SS_CTRL_INOVER_LOW			2u
#define IO_QSPI_GPIO_QSPI_SS_CTRL_INOVER_HIGH			3u
	/*  */
#define IO_QSPI_GPIO_QSPI_SS_CTRL_OEOVER_Msb			13u
#define IO_QSPI_GPIO_QSPI_SS_CTRL_OEOVER_Lsb			12u
#define IO_QSPI_GPIO_QSPI_SS_CTRL_OEOVER_NORMAL			0u
#define IO_QSPI_GPIO_QSPI_SS_CTRL_OEOVER_INVERT			1u
#define IO_QSPI_GPIO_QSPI_SS_CTRL_OEOVER_DISABLE		2u
#define IO_QSPI_GPIO_QSPI_SS_CTRL_OEOVER_ENABLE			3u
	/*  */
#define IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_Msb			9u
#define IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_Lsb			8u
#define IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_NORMAL		0u
#define IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_INVERT		1u
#define IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_LOW			2u
#define IO_QSPI_GPIO_QSPI_SS_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_QSPI_GPIO_QSPI_SS_CTRL_FUNCSEL_Msb			4u
#define IO_QSPI_GPIO_QSPI_SS_CTRL_FUNCSEL_Lsb			0u
#define IO_QSPI_GPIO_QSPI_SS_CTRL_FUNCSEL_XIP_SS_N		0u
#define IO_QSPI_GPIO_QSPI_SS_CTRL_FUNCSEL_SIO_31		5u
#define IO_QSPI_GPIO_QSPI_SS_CTRL_FUNCSEL_NULL			31u

	/* 0x10: GPIO status */
	uint32_t volatile GPIO_QSPI_SD0_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_QSPI_GPIO_QSPI_SD0_STATUS_IRQTOPROC			26u
	/* interrupt from pad before override is applied */
#define IO_QSPI_GPIO_QSPI_SD0_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_QSPI_GPIO_QSPI_SD0_STATUS_INTOPERI			19u
	/* input signal from pad, before override is applied */
#define IO_QSPI_GPIO_QSPI_SD0_STATUS_INFROMPAD			17u
	/* output enable to pad after register override is applied */
#define IO_QSPI_GPIO_QSPI_SD0_STATUS_OETOPAD			13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_QSPI_GPIO_QSPI_SD0_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_QSPI_GPIO_QSPI_SD0_STATUS_OUTTOPAD			9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_QSPI_GPIO_QSPI_SD0_STATUS_OUTFROMPERI		8u

	/* 0x14: GPIO control including function select and overrides. */
	uint32_t volatile GPIO_QSPI_SD0_CTRL;
	/*  */
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_IRQOVER_Msb			29u
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_IRQOVER_Lsb			28u
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_IRQOVER_NORMAL		0u
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_IRQOVER_INVERT		1u
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_IRQOVER_LOW			2u
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_INOVER_Msb			17u
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_INOVER_Lsb			16u
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_INOVER_NORMAL		0u
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_INOVER_INVERT		1u
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_INOVER_LOW			2u
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_INOVER_HIGH			3u
	/*  */
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_OEOVER_Msb			13u
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_OEOVER_Lsb			12u
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_OEOVER_NORMAL		0u
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_OEOVER_INVERT		1u
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_OEOVER_DISABLE		2u
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_OEOVER_ENABLE		3u
	/*  */
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_OUTOVER_Msb			9u
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_OUTOVER_Lsb			8u
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_OUTOVER_NORMAL		0u
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_OUTOVER_INVERT		1u
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_OUTOVER_LOW			2u
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_FUNCSEL_Msb			4u
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_FUNCSEL_Lsb			0u
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_FUNCSEL_XIP_SD0		0u
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_FUNCSEL_SIO_32		5u
#define IO_QSPI_GPIO_QSPI_SD0_CTRL_FUNCSEL_NULL			31u

	/* 0x18: GPIO status */
	uint32_t volatile GPIO_QSPI_SD1_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_QSPI_GPIO_QSPI_SD1_STATUS_IRQTOPROC			26u
	/* interrupt from pad before override is applied */
#define IO_QSPI_GPIO_QSPI_SD1_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_QSPI_GPIO_QSPI_SD1_STATUS_INTOPERI			19u
	/* input signal from pad, before override is applied */
#define IO_QSPI_GPIO_QSPI_SD1_STATUS_INFROMPAD			17u
	/* output enable to pad after register override is applied */
#define IO_QSPI_GPIO_QSPI_SD1_STATUS_OETOPAD			13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_QSPI_GPIO_QSPI_SD1_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_QSPI_GPIO_QSPI_SD1_STATUS_OUTTOPAD			9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_QSPI_GPIO_QSPI_SD1_STATUS_OUTFROMPERI		8u

	/* 0x1C: GPIO control including function select and overrides. */
	uint32_t volatile GPIO_QSPI_SD1_CTRL;
	/*  */
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_IRQOVER_Msb			29u
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_IRQOVER_Lsb			28u
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_IRQOVER_NORMAL		0u
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_IRQOVER_INVERT		1u
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_IRQOVER_LOW			2u
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_INOVER_Msb			17u
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_INOVER_Lsb			16u
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_INOVER_NORMAL		0u
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_INOVER_INVERT		1u
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_INOVER_LOW			2u
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_INOVER_HIGH			3u
	/*  */
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_OEOVER_Msb			13u
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_OEOVER_Lsb			12u
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_OEOVER_NORMAL		0u
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_OEOVER_INVERT		1u
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_OEOVER_DISABLE		2u
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_OEOVER_ENABLE		3u
	/*  */
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_OUTOVER_Msb			9u
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_OUTOVER_Lsb			8u
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_OUTOVER_NORMAL		0u
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_OUTOVER_INVERT		1u
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_OUTOVER_LOW			2u
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_FUNCSEL_Msb			4u
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_FUNCSEL_Lsb			0u
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_FUNCSEL_XIP_SD1		0u
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_FUNCSEL_SIO_33		5u
#define IO_QSPI_GPIO_QSPI_SD1_CTRL_FUNCSEL_NULL			31u

	/* 0x20: GPIO status */
	uint32_t volatile GPIO_QSPI_SD2_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_QSPI_GPIO_QSPI_SD2_STATUS_IRQTOPROC			26u
	/* interrupt from pad before override is applied */
#define IO_QSPI_GPIO_QSPI_SD2_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_QSPI_GPIO_QSPI_SD2_STATUS_INTOPERI			19u
	/* input signal from pad, before override is applied */
#define IO_QSPI_GPIO_QSPI_SD2_STATUS_INFROMPAD			17u
	/* output enable to pad after register override is applied */
#define IO_QSPI_GPIO_QSPI_SD2_STATUS_OETOPAD			13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_QSPI_GPIO_QSPI_SD2_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_QSPI_GPIO_QSPI_SD2_STATUS_OUTTOPAD			9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_QSPI_GPIO_QSPI_SD2_STATUS_OUTFROMPERI		8u

	/* 0x24: GPIO control including function select and overrides. */
	uint32_t volatile GPIO_QSPI_SD2_CTRL;
	/*  */
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_IRQOVER_Msb			29u
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_IRQOVER_Lsb			28u
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_IRQOVER_NORMAL		0u
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_IRQOVER_INVERT		1u
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_IRQOVER_LOW			2u
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_INOVER_Msb			17u
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_INOVER_Lsb			16u
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_INOVER_NORMAL		0u
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_INOVER_INVERT		1u
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_INOVER_LOW			2u
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_INOVER_HIGH			3u
	/*  */
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_OEOVER_Msb			13u
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_OEOVER_Lsb			12u
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_OEOVER_NORMAL		0u
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_OEOVER_INVERT		1u
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_OEOVER_DISABLE		2u
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_OEOVER_ENABLE		3u
	/*  */
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_OUTOVER_Msb			9u
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_OUTOVER_Lsb			8u
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_OUTOVER_NORMAL		0u
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_OUTOVER_INVERT		1u
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_OUTOVER_LOW			2u
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_FUNCSEL_Msb			4u
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_FUNCSEL_Lsb			0u
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_FUNCSEL_XIP_SD2		0u
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_FUNCSEL_SIO_34		5u
#define IO_QSPI_GPIO_QSPI_SD2_CTRL_FUNCSEL_NULL			31u

	/* 0x28: GPIO status */
	uint32_t volatile GPIO_QSPI_SD3_STATUS;
	/* interrupt to processors, after override is applied */
#define IO_QSPI_GPIO_QSPI_SD3_STATUS_IRQTOPROC			26u
	/* interrupt from pad before override is applied */
#define IO_QSPI_GPIO_QSPI_SD3_STATUS_IRQFROMPAD			24u
	/* input signal to peripheral, after override is applied */
#define IO_QSPI_GPIO_QSPI_SD3_STATUS_INTOPERI			19u
	/* input signal from pad, before override is applied */
#define IO_QSPI_GPIO_QSPI_SD3_STATUS_INFROMPAD			17u
	/* output enable to pad after register override is applied */
#define IO_QSPI_GPIO_QSPI_SD3_STATUS_OETOPAD			13u
	/* output enable from selected peripheral, before register override is applied */
#define IO_QSPI_GPIO_QSPI_SD3_STATUS_OEFROMPERI			12u
	/* output signal to pad after register override is applied */
#define IO_QSPI_GPIO_QSPI_SD3_STATUS_OUTTOPAD			9u
	/* output signal from selected peripheral, before register override is applied */
#define IO_QSPI_GPIO_QSPI_SD3_STATUS_OUTFROMPERI		8u

	/* 0x2C: GPIO control including function select and overrides. */
	uint32_t volatile GPIO_QSPI_SD3_CTRL;
	/*  */
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_IRQOVER_Msb			29u
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_IRQOVER_Lsb			28u
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_IRQOVER_NORMAL		0u
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_IRQOVER_INVERT		1u
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_IRQOVER_LOW			2u
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_IRQOVER_HIGH			3u
	/*  */
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_INOVER_Msb			17u
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_INOVER_Lsb			16u
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_INOVER_NORMAL		0u
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_INOVER_INVERT		1u
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_INOVER_LOW			2u
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_INOVER_HIGH			3u
	/*  */
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_OEOVER_Msb			13u
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_OEOVER_Lsb			12u
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_OEOVER_NORMAL		0u
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_OEOVER_INVERT		1u
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_OEOVER_DISABLE		2u
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_OEOVER_ENABLE		3u
	/*  */
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_OUTOVER_Msb			9u
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_OUTOVER_Lsb			8u
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_OUTOVER_NORMAL		0u
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_OUTOVER_INVERT		1u
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_OUTOVER_LOW			2u
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_OUTOVER_HIGH			3u
	/* 0-31 -> selects pin function according to the gpio table */
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_FUNCSEL_Msb			4u
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_FUNCSEL_Lsb			0u
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_FUNCSEL_XIP_SD3		0u
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_FUNCSEL_SIO_35		5u
#define IO_QSPI_GPIO_QSPI_SD3_CTRL_FUNCSEL_NULL			31u

	/* 0x30: Raw Interrupts */
	uint32_t volatile INTR;
	/*  */
#define IO_QSPI_INTR_GPIO_QSPI_SD3_EDGE_HIGH			23u
	/*  */
#define IO_QSPI_INTR_GPIO_QSPI_SD3_EDGE_LOW			22u
	/*  */
#define IO_QSPI_INTR_GPIO_QSPI_SD3_LEVEL_HIGH			21u
	/*  */
#define IO_QSPI_INTR_GPIO_QSPI_SD3_LEVEL_LOW			20u
	/*  */
#define IO_QSPI_INTR_GPIO_QSPI_SD2_EDGE_HIGH			19u
	/*  */
#define IO_QSPI_INTR_GPIO_QSPI_SD2_EDGE_LOW			18u
	/*  */
#define IO_QSPI_INTR_GPIO_QSPI_SD2_LEVEL_HIGH			17u
	/*  */
#define IO_QSPI_INTR_GPIO_QSPI_SD2_LEVEL_LOW			16u
	/*  */
#define IO_QSPI_INTR_GPIO_QSPI_SD1_EDGE_HIGH			15u
	/*  */
#define IO_QSPI_INTR_GPIO_QSPI_SD1_EDGE_LOW			14u
	/*  */
#define IO_QSPI_INTR_GPIO_QSPI_SD1_LEVEL_HIGH			13u
	/*  */
#define IO_QSPI_INTR_GPIO_QSPI_SD1_LEVEL_LOW			12u
	/*  */
#define IO_QSPI_INTR_GPIO_QSPI_SD0_EDGE_HIGH			11u
	/*  */
#define IO_QSPI_INTR_GPIO_QSPI_SD0_EDGE_LOW			10u
	/*  */
#define IO_QSPI_INTR_GPIO_QSPI_SD0_LEVEL_HIGH			9u
	/*  */
#define IO_QSPI_INTR_GPIO_QSPI_SD0_LEVEL_LOW			8u
	/*  */
#define IO_QSPI_INTR_GPIO_QSPI_SS_EDGE_HIGH			7u
	/*  */
#define IO_QSPI_INTR_GPIO_QSPI_SS_EDGE_LOW			6u
	/*  */
#define IO_QSPI_INTR_GPIO_QSPI_SS_LEVEL_HIGH			5u
	/*  */
#define IO_QSPI_INTR_GPIO_QSPI_SS_LEVEL_LOW			4u
	/*  */
#define IO_QSPI_INTR_GPIO_QSPI_SCLK_EDGE_HIGH			3u
	/*  */
#define IO_QSPI_INTR_GPIO_QSPI_SCLK_EDGE_LOW			2u
	/*  */
#define IO_QSPI_INTR_GPIO_QSPI_SCLK_LEVEL_HIGH			1u
	/*  */
#define IO_QSPI_INTR_GPIO_QSPI_SCLK_LEVEL_LOW			0u

	/* 0x34: Interrupt Enable for proc0 */
	uint32_t volatile PROC0_INTE;
	/*  */
#define IO_QSPI_PROC0_INTE_GPIO_QSPI_SD3_EDGE_HIGH		23u
	/*  */
#define IO_QSPI_PROC0_INTE_GPIO_QSPI_SD3_EDGE_LOW		22u
	/*  */
#define IO_QSPI_PROC0_INTE_GPIO_QSPI_SD3_LEVEL_HIGH		21u
	/*  */
#define IO_QSPI_PROC0_INTE_GPIO_QSPI_SD3_LEVEL_LOW		20u
	/*  */
#define IO_QSPI_PROC0_INTE_GPIO_QSPI_SD2_EDGE_HIGH		19u
	/*  */
#define IO_QSPI_PROC0_INTE_GPIO_QSPI_SD2_EDGE_LOW		18u
	/*  */
#define IO_QSPI_PROC0_INTE_GPIO_QSPI_SD2_LEVEL_HIGH		17u
	/*  */
#define IO_QSPI_PROC0_INTE_GPIO_QSPI_SD2_LEVEL_LOW		16u
	/*  */
#define IO_QSPI_PROC0_INTE_GPIO_QSPI_SD1_EDGE_HIGH		15u
	/*  */
#define IO_QSPI_PROC0_INTE_GPIO_QSPI_SD1_EDGE_LOW		14u
	/*  */
#define IO_QSPI_PROC0_INTE_GPIO_QSPI_SD1_LEVEL_HIGH		13u
	/*  */
#define IO_QSPI_PROC0_INTE_GPIO_QSPI_SD1_LEVEL_LOW		12u
	/*  */
#define IO_QSPI_PROC0_INTE_GPIO_QSPI_SD0_EDGE_HIGH		11u
	/*  */
#define IO_QSPI_PROC0_INTE_GPIO_QSPI_SD0_EDGE_LOW		10u
	/*  */
#define IO_QSPI_PROC0_INTE_GPIO_QSPI_SD0_LEVEL_HIGH		9u
	/*  */
#define IO_QSPI_PROC0_INTE_GPIO_QSPI_SD0_LEVEL_LOW		8u
	/*  */
#define IO_QSPI_PROC0_INTE_GPIO_QSPI_SS_EDGE_HIGH		7u
	/*  */
#define IO_QSPI_PROC0_INTE_GPIO_QSPI_SS_EDGE_LOW		6u
	/*  */
#define IO_QSPI_PROC0_INTE_GPIO_QSPI_SS_LEVEL_HIGH		5u
	/*  */
#define IO_QSPI_PROC0_INTE_GPIO_QSPI_SS_LEVEL_LOW		4u
	/*  */
#define IO_QSPI_PROC0_INTE_GPIO_QSPI_SCLK_EDGE_HIGH		3u
	/*  */
#define IO_QSPI_PROC0_INTE_GPIO_QSPI_SCLK_EDGE_LOW		2u
	/*  */
#define IO_QSPI_PROC0_INTE_GPIO_QSPI_SCLK_LEVEL_HIGH		1u
	/*  */
#define IO_QSPI_PROC0_INTE_GPIO_QSPI_SCLK_LEVEL_LOW		0u

	/* 0x38: Interrupt Force for proc0 */
	uint32_t volatile PROC0_INTF;
	/*  */
#define IO_QSPI_PROC0_INTF_GPIO_QSPI_SD3_EDGE_HIGH		23u
	/*  */
#define IO_QSPI_PROC0_INTF_GPIO_QSPI_SD3_EDGE_LOW		22u
	/*  */
#define IO_QSPI_PROC0_INTF_GPIO_QSPI_SD3_LEVEL_HIGH		21u
	/*  */
#define IO_QSPI_PROC0_INTF_GPIO_QSPI_SD3_LEVEL_LOW		20u
	/*  */
#define IO_QSPI_PROC0_INTF_GPIO_QSPI_SD2_EDGE_HIGH		19u
	/*  */
#define IO_QSPI_PROC0_INTF_GPIO_QSPI_SD2_EDGE_LOW		18u
	/*  */
#define IO_QSPI_PROC0_INTF_GPIO_QSPI_SD2_LEVEL_HIGH		17u
	/*  */
#define IO_QSPI_PROC0_INTF_GPIO_QSPI_SD2_LEVEL_LOW		16u
	/*  */
#define IO_QSPI_PROC0_INTF_GPIO_QSPI_SD1_EDGE_HIGH		15u
	/*  */
#define IO_QSPI_PROC0_INTF_GPIO_QSPI_SD1_EDGE_LOW		14u
	/*  */
#define IO_QSPI_PROC0_INTF_GPIO_QSPI_SD1_LEVEL_HIGH		13u
	/*  */
#define IO_QSPI_PROC0_INTF_GPIO_QSPI_SD1_LEVEL_LOW		12u
	/*  */
#define IO_QSPI_PROC0_INTF_GPIO_QSPI_SD0_EDGE_HIGH		11u
	/*  */
#define IO_QSPI_PROC0_INTF_GPIO_QSPI_SD0_EDGE_LOW		10u
	/*  */
#define IO_QSPI_PROC0_INTF_GPIO_QSPI_SD0_LEVEL_HIGH		9u
	/*  */
#define IO_QSPI_PROC0_INTF_GPIO_QSPI_SD0_LEVEL_LOW		8u
	/*  */
#define IO_QSPI_PROC0_INTF_GPIO_QSPI_SS_EDGE_HIGH		7u
	/*  */
#define IO_QSPI_PROC0_INTF_GPIO_QSPI_SS_EDGE_LOW		6u
	/*  */
#define IO_QSPI_PROC0_INTF_GPIO_QSPI_SS_LEVEL_HIGH		5u
	/*  */
#define IO_QSPI_PROC0_INTF_GPIO_QSPI_SS_LEVEL_LOW		4u
	/*  */
#define IO_QSPI_PROC0_INTF_GPIO_QSPI_SCLK_EDGE_HIGH		3u
	/*  */
#define IO_QSPI_PROC0_INTF_GPIO_QSPI_SCLK_EDGE_LOW		2u
	/*  */
#define IO_QSPI_PROC0_INTF_GPIO_QSPI_SCLK_LEVEL_HIGH		1u
	/*  */
#define IO_QSPI_PROC0_INTF_GPIO_QSPI_SCLK_LEVEL_LOW		0u

	/* 0x3C: Interrupt status after masking & forcing for proc0 */
	uint32_t volatile PROC0_INTS;
	/*  */
#define IO_QSPI_PROC0_INTS_GPIO_QSPI_SD3_EDGE_HIGH		23u
	/*  */
#define IO_QSPI_PROC0_INTS_GPIO_QSPI_SD3_EDGE_LOW		22u
	/*  */
#define IO_QSPI_PROC0_INTS_GPIO_QSPI_SD3_LEVEL_HIGH		21u
	/*  */
#define IO_QSPI_PROC0_INTS_GPIO_QSPI_SD3_LEVEL_LOW		20u
	/*  */
#define IO_QSPI_PROC0_INTS_GPIO_QSPI_SD2_EDGE_HIGH		19u
	/*  */
#define IO_QSPI_PROC0_INTS_GPIO_QSPI_SD2_EDGE_LOW		18u
	/*  */
#define IO_QSPI_PROC0_INTS_GPIO_QSPI_SD2_LEVEL_HIGH		17u
	/*  */
#define IO_QSPI_PROC0_INTS_GPIO_QSPI_SD2_LEVEL_LOW		16u
	/*  */
#define IO_QSPI_PROC0_INTS_GPIO_QSPI_SD1_EDGE_HIGH		15u
	/*  */
#define IO_QSPI_PROC0_INTS_GPIO_QSPI_SD1_EDGE_LOW		14u
	/*  */
#define IO_QSPI_PROC0_INTS_GPIO_QSPI_SD1_LEVEL_HIGH		13u
	/*  */
#define IO_QSPI_PROC0_INTS_GPIO_QSPI_SD1_LEVEL_LOW		12u
	/*  */
#define IO_QSPI_PROC0_INTS_GPIO_QSPI_SD0_EDGE_HIGH		11u
	/*  */
#define IO_QSPI_PROC0_INTS_GPIO_QSPI_SD0_EDGE_LOW		10u
	/*  */
#define IO_QSPI_PROC0_INTS_GPIO_QSPI_SD0_LEVEL_HIGH		9u
	/*  */
#define IO_QSPI_PROC0_INTS_GPIO_QSPI_SD0_LEVEL_LOW		8u
	/*  */
#define IO_QSPI_PROC0_INTS_GPIO_QSPI_SS_EDGE_HIGH		7u
	/*  */
#define IO_QSPI_PROC0_INTS_GPIO_QSPI_SS_EDGE_LOW		6u
	/*  */
#define IO_QSPI_PROC0_INTS_GPIO_QSPI_SS_LEVEL_HIGH		5u
	/*  */
#define IO_QSPI_PROC0_INTS_GPIO_QSPI_SS_LEVEL_LOW		4u
	/*  */
#define IO_QSPI_PROC0_INTS_GPIO_QSPI_SCLK_EDGE_HIGH		3u
	/*  */
#define IO_QSPI_PROC0_INTS_GPIO_QSPI_SCLK_EDGE_LOW		2u
	/*  */
#define IO_QSPI_PROC0_INTS_GPIO_QSPI_SCLK_LEVEL_HIGH		1u
	/*  */
#define IO_QSPI_PROC0_INTS_GPIO_QSPI_SCLK_LEVEL_LOW		0u

	/* 0x40: Interrupt Enable for proc1 */
	uint32_t volatile PROC1_INTE;
	/*  */
#define IO_QSPI_PROC1_INTE_GPIO_QSPI_SD3_EDGE_HIGH		23u
	/*  */
#define IO_QSPI_PROC1_INTE_GPIO_QSPI_SD3_EDGE_LOW		22u
	/*  */
#define IO_QSPI_PROC1_INTE_GPIO_QSPI_SD3_LEVEL_HIGH		21u
	/*  */
#define IO_QSPI_PROC1_INTE_GPIO_QSPI_SD3_LEVEL_LOW		20u
	/*  */
#define IO_QSPI_PROC1_INTE_GPIO_QSPI_SD2_EDGE_HIGH		19u
	/*  */
#define IO_QSPI_PROC1_INTE_GPIO_QSPI_SD2_EDGE_LOW		18u
	/*  */
#define IO_QSPI_PROC1_INTE_GPIO_QSPI_SD2_LEVEL_HIGH		17u
	/*  */
#define IO_QSPI_PROC1_INTE_GPIO_QSPI_SD2_LEVEL_LOW		16u
	/*  */
#define IO_QSPI_PROC1_INTE_GPIO_QSPI_SD1_EDGE_HIGH		15u
	/*  */
#define IO_QSPI_PROC1_INTE_GPIO_QSPI_SD1_EDGE_LOW		14u
	/*  */
#define IO_QSPI_PROC1_INTE_GPIO_QSPI_SD1_LEVEL_HIGH		13u
	/*  */
#define IO_QSPI_PROC1_INTE_GPIO_QSPI_SD1_LEVEL_LOW		12u
	/*  */
#define IO_QSPI_PROC1_INTE_GPIO_QSPI_SD0_EDGE_HIGH		11u
	/*  */
#define IO_QSPI_PROC1_INTE_GPIO_QSPI_SD0_EDGE_LOW		10u
	/*  */
#define IO_QSPI_PROC1_INTE_GPIO_QSPI_SD0_LEVEL_HIGH		9u
	/*  */
#define IO_QSPI_PROC1_INTE_GPIO_QSPI_SD0_LEVEL_LOW		8u
	/*  */
#define IO_QSPI_PROC1_INTE_GPIO_QSPI_SS_EDGE_HIGH		7u
	/*  */
#define IO_QSPI_PROC1_INTE_GPIO_QSPI_SS_EDGE_LOW		6u
	/*  */
#define IO_QSPI_PROC1_INTE_GPIO_QSPI_SS_LEVEL_HIGH		5u
	/*  */
#define IO_QSPI_PROC1_INTE_GPIO_QSPI_SS_LEVEL_LOW		4u
	/*  */
#define IO_QSPI_PROC1_INTE_GPIO_QSPI_SCLK_EDGE_HIGH		3u
	/*  */
#define IO_QSPI_PROC1_INTE_GPIO_QSPI_SCLK_EDGE_LOW		2u
	/*  */
#define IO_QSPI_PROC1_INTE_GPIO_QSPI_SCLK_LEVEL_HIGH		1u
	/*  */
#define IO_QSPI_PROC1_INTE_GPIO_QSPI_SCLK_LEVEL_LOW		0u

	/* 0x44: Interrupt Force for proc1 */
	uint32_t volatile PROC1_INTF;
	/*  */
#define IO_QSPI_PROC1_INTF_GPIO_QSPI_SD3_EDGE_HIGH		23u
	/*  */
#define IO_QSPI_PROC1_INTF_GPIO_QSPI_SD3_EDGE_LOW		22u
	/*  */
#define IO_QSPI_PROC1_INTF_GPIO_QSPI_SD3_LEVEL_HIGH		21u
	/*  */
#define IO_QSPI_PROC1_INTF_GPIO_QSPI_SD3_LEVEL_LOW		20u
	/*  */
#define IO_QSPI_PROC1_INTF_GPIO_QSPI_SD2_EDGE_HIGH		19u
	/*  */
#define IO_QSPI_PROC1_INTF_GPIO_QSPI_SD2_EDGE_LOW		18u
	/*  */
#define IO_QSPI_PROC1_INTF_GPIO_QSPI_SD2_LEVEL_HIGH		17u
	/*  */
#define IO_QSPI_PROC1_INTF_GPIO_QSPI_SD2_LEVEL_LOW		16u
	/*  */
#define IO_QSPI_PROC1_INTF_GPIO_QSPI_SD1_EDGE_HIGH		15u
	/*  */
#define IO_QSPI_PROC1_INTF_GPIO_QSPI_SD1_EDGE_LOW		14u
	/*  */
#define IO_QSPI_PROC1_INTF_GPIO_QSPI_SD1_LEVEL_HIGH		13u
	/*  */
#define IO_QSPI_PROC1_INTF_GPIO_QSPI_SD1_LEVEL_LOW		12u
	/*  */
#define IO_QSPI_PROC1_INTF_GPIO_QSPI_SD0_EDGE_HIGH		11u
	/*  */
#define IO_QSPI_PROC1_INTF_GPIO_QSPI_SD0_EDGE_LOW		10u
	/*  */
#define IO_QSPI_PROC1_INTF_GPIO_QSPI_SD0_LEVEL_HIGH		9u
	/*  */
#define IO_QSPI_PROC1_INTF_GPIO_QSPI_SD0_LEVEL_LOW		8u
	/*  */
#define IO_QSPI_PROC1_INTF_GPIO_QSPI_SS_EDGE_HIGH		7u
	/*  */
#define IO_QSPI_PROC1_INTF_GPIO_QSPI_SS_EDGE_LOW		6u
	/*  */
#define IO_QSPI_PROC1_INTF_GPIO_QSPI_SS_LEVEL_HIGH		5u
	/*  */
#define IO_QSPI_PROC1_INTF_GPIO_QSPI_SS_LEVEL_LOW		4u
	/*  */
#define IO_QSPI_PROC1_INTF_GPIO_QSPI_SCLK_EDGE_HIGH		3u
	/*  */
#define IO_QSPI_PROC1_INTF_GPIO_QSPI_SCLK_EDGE_LOW		2u
	/*  */
#define IO_QSPI_PROC1_INTF_GPIO_QSPI_SCLK_LEVEL_HIGH		1u
	/*  */
#define IO_QSPI_PROC1_INTF_GPIO_QSPI_SCLK_LEVEL_LOW		0u

	/* 0x48: Interrupt status after masking & forcing for proc1 */
	uint32_t volatile PROC1_INTS;
	/*  */
#define IO_QSPI_PROC1_INTS_GPIO_QSPI_SD3_EDGE_HIGH		23u
	/*  */
#define IO_QSPI_PROC1_INTS_GPIO_QSPI_SD3_EDGE_LOW		22u
	/*  */
#define IO_QSPI_PROC1_INTS_GPIO_QSPI_SD3_LEVEL_HIGH		21u
	/*  */
#define IO_QSPI_PROC1_INTS_GPIO_QSPI_SD3_LEVEL_LOW		20u
	/*  */
#define IO_QSPI_PROC1_INTS_GPIO_QSPI_SD2_EDGE_HIGH		19u
	/*  */
#define IO_QSPI_PROC1_INTS_GPIO_QSPI_SD2_EDGE_LOW		18u
	/*  */
#define IO_QSPI_PROC1_INTS_GPIO_QSPI_SD2_LEVEL_HIGH		17u
	/*  */
#define IO_QSPI_PROC1_INTS_GPIO_QSPI_SD2_LEVEL_LOW		16u
	/*  */
#define IO_QSPI_PROC1_INTS_GPIO_QSPI_SD1_EDGE_HIGH		15u
	/*  */
#define IO_QSPI_PROC1_INTS_GPIO_QSPI_SD1_EDGE_LOW		14u
	/*  */
#define IO_QSPI_PROC1_INTS_GPIO_QSPI_SD1_LEVEL_HIGH		13u
	/*  */
#define IO_QSPI_PROC1_INTS_GPIO_QSPI_SD1_LEVEL_LOW		12u
	/*  */
#define IO_QSPI_PROC1_INTS_GPIO_QSPI_SD0_EDGE_HIGH		11u
	/*  */
#define IO_QSPI_PROC1_INTS_GPIO_QSPI_SD0_EDGE_LOW		10u
	/*  */
#define IO_QSPI_PROC1_INTS_GPIO_QSPI_SD0_LEVEL_HIGH		9u
	/*  */
#define IO_QSPI_PROC1_INTS_GPIO_QSPI_SD0_LEVEL_LOW		8u
	/*  */
#define IO_QSPI_PROC1_INTS_GPIO_QSPI_SS_EDGE_HIGH		7u
	/*  */
#define IO_QSPI_PROC1_INTS_GPIO_QSPI_SS_EDGE_LOW		6u
	/*  */
#define IO_QSPI_PROC1_INTS_GPIO_QSPI_SS_LEVEL_HIGH		5u
	/*  */
#define IO_QSPI_PROC1_INTS_GPIO_QSPI_SS_LEVEL_LOW		4u
	/*  */
#define IO_QSPI_PROC1_INTS_GPIO_QSPI_SCLK_EDGE_HIGH		3u
	/*  */
#define IO_QSPI_PROC1_INTS_GPIO_QSPI_SCLK_EDGE_LOW		2u
	/*  */
#define IO_QSPI_PROC1_INTS_GPIO_QSPI_SCLK_LEVEL_HIGH		1u
	/*  */
#define IO_QSPI_PROC1_INTS_GPIO_QSPI_SCLK_LEVEL_LOW		0u

	/* 0x4C: Interrupt Enable for dormant_wake */
	uint32_t volatile DORMANT_WAKE_INTE;
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTE_GPIO_QSPI_SD3_EDGE_HIGH	23u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTE_GPIO_QSPI_SD3_EDGE_LOW	22u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTE_GPIO_QSPI_SD3_LEVEL_HIGH	21u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTE_GPIO_QSPI_SD3_LEVEL_LOW	20u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTE_GPIO_QSPI_SD2_EDGE_HIGH	19u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTE_GPIO_QSPI_SD2_EDGE_LOW	18u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTE_GPIO_QSPI_SD2_LEVEL_HIGH	17u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTE_GPIO_QSPI_SD2_LEVEL_LOW	16u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTE_GPIO_QSPI_SD1_EDGE_HIGH	15u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTE_GPIO_QSPI_SD1_EDGE_LOW	14u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTE_GPIO_QSPI_SD1_LEVEL_HIGH	13u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTE_GPIO_QSPI_SD1_LEVEL_LOW	12u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTE_GPIO_QSPI_SD0_EDGE_HIGH	11u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTE_GPIO_QSPI_SD0_EDGE_LOW	10u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTE_GPIO_QSPI_SD0_LEVEL_HIGH	9u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTE_GPIO_QSPI_SD0_LEVEL_LOW	8u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTE_GPIO_QSPI_SS_EDGE_HIGH	7u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTE_GPIO_QSPI_SS_EDGE_LOW		6u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTE_GPIO_QSPI_SS_LEVEL_HIGH	5u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTE_GPIO_QSPI_SS_LEVEL_LOW	4u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTE_GPIO_QSPI_SCLK_EDGE_HIGH	3u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTE_GPIO_QSPI_SCLK_EDGE_LOW	2u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTE_GPIO_QSPI_SCLK_LEVEL_HIGH	1u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTE_GPIO_QSPI_SCLK_LEVEL_LOW	0u

	/* 0x50: Interrupt Force for dormant_wake */
	uint32_t volatile DORMANT_WAKE_INTF;
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTF_GPIO_QSPI_SD3_EDGE_HIGH	23u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTF_GPIO_QSPI_SD3_EDGE_LOW	22u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTF_GPIO_QSPI_SD3_LEVEL_HIGH	21u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTF_GPIO_QSPI_SD3_LEVEL_LOW	20u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTF_GPIO_QSPI_SD2_EDGE_HIGH	19u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTF_GPIO_QSPI_SD2_EDGE_LOW	18u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTF_GPIO_QSPI_SD2_LEVEL_HIGH	17u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTF_GPIO_QSPI_SD2_LEVEL_LOW	16u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTF_GPIO_QSPI_SD1_EDGE_HIGH	15u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTF_GPIO_QSPI_SD1_EDGE_LOW	14u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTF_GPIO_QSPI_SD1_LEVEL_HIGH	13u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTF_GPIO_QSPI_SD1_LEVEL_LOW	12u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTF_GPIO_QSPI_SD0_EDGE_HIGH	11u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTF_GPIO_QSPI_SD0_EDGE_LOW	10u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTF_GPIO_QSPI_SD0_LEVEL_HIGH	9u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTF_GPIO_QSPI_SD0_LEVEL_LOW	8u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTF_GPIO_QSPI_SS_EDGE_HIGH	7u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTF_GPIO_QSPI_SS_EDGE_LOW		6u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTF_GPIO_QSPI_SS_LEVEL_HIGH	5u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTF_GPIO_QSPI_SS_LEVEL_LOW	4u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTF_GPIO_QSPI_SCLK_EDGE_HIGH	3u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTF_GPIO_QSPI_SCLK_EDGE_LOW	2u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTF_GPIO_QSPI_SCLK_LEVEL_HIGH	1u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTF_GPIO_QSPI_SCLK_LEVEL_LOW	0u

	/* 0x54: Interrupt status after masking & forcing for dormant_wake */
	uint32_t volatile DORMANT_WAKE_INTS;
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTS_GPIO_QSPI_SD3_EDGE_HIGH	23u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTS_GPIO_QSPI_SD3_EDGE_LOW	22u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTS_GPIO_QSPI_SD3_LEVEL_HIGH	21u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTS_GPIO_QSPI_SD3_LEVEL_LOW	20u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTS_GPIO_QSPI_SD2_EDGE_HIGH	19u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTS_GPIO_QSPI_SD2_EDGE_LOW	18u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTS_GPIO_QSPI_SD2_LEVEL_HIGH	17u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTS_GPIO_QSPI_SD2_LEVEL_LOW	16u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTS_GPIO_QSPI_SD1_EDGE_HIGH	15u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTS_GPIO_QSPI_SD1_EDGE_LOW	14u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTS_GPIO_QSPI_SD1_LEVEL_HIGH	13u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTS_GPIO_QSPI_SD1_LEVEL_LOW	12u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTS_GPIO_QSPI_SD0_EDGE_HIGH	11u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTS_GPIO_QSPI_SD0_EDGE_LOW	10u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTS_GPIO_QSPI_SD0_LEVEL_HIGH	9u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTS_GPIO_QSPI_SD0_LEVEL_LOW	8u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTS_GPIO_QSPI_SS_EDGE_HIGH	7u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTS_GPIO_QSPI_SS_EDGE_LOW		6u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTS_GPIO_QSPI_SS_LEVEL_HIGH	5u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTS_GPIO_QSPI_SS_LEVEL_LOW	4u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTS_GPIO_QSPI_SCLK_EDGE_HIGH	3u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTS_GPIO_QSPI_SCLK_EDGE_LOW	2u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTS_GPIO_QSPI_SCLK_LEVEL_HIGH	1u
	/*  */
#define IO_QSPI_DORMANT_WAKE_INTS_GPIO_QSPI_SCLK_LEVEL_LOW	0u

};


#define PADS_BANK0 ((struct sdk_pads_bank0 *)0x4001C000)

struct sdk_pads_bank0 {

	/* 0x00: Voltage select. */
	uint32_t volatile VOLTAGE_SELECT;
	/*  */
#define PADS_BANK0_VOLTAGE_SELECT_VOLTAGE_SELECT		0u
#define PADS_BANK0_VOLTAGE_SELECT_VOLTAGE_SELECT_3V3		0u
#define PADS_BANK0_VOLTAGE_SELECT_VOLTAGE_SELECT_1V8		1u

	/* 0x04: Pad control register */
	uint32_t volatile GPIO0;
	/* Output disable. */
#define PADS_BANK0_GPIO0_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO0_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO0_DRIVE_Msb				5u
#define PADS_BANK0_GPIO0_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO0_DRIVE_2MA				0u
#define PADS_BANK0_GPIO0_DRIVE_4MA				1u
#define PADS_BANK0_GPIO0_DRIVE_8MA				2u
#define PADS_BANK0_GPIO0_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO0_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO0_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO0_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO0_SLEWFAST				0u

	/* 0x08: Pad control register */
	uint32_t volatile GPIO1;
	/* Output disable. */
#define PADS_BANK0_GPIO1_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO1_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO1_DRIVE_Msb				5u
#define PADS_BANK0_GPIO1_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO1_DRIVE_2MA				0u
#define PADS_BANK0_GPIO1_DRIVE_4MA				1u
#define PADS_BANK0_GPIO1_DRIVE_8MA				2u
#define PADS_BANK0_GPIO1_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO1_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO1_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO1_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO1_SLEWFAST				0u

	/* 0x0C: Pad control register */
	uint32_t volatile GPIO2;
	/* Output disable. */
#define PADS_BANK0_GPIO2_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO2_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO2_DRIVE_Msb				5u
#define PADS_BANK0_GPIO2_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO2_DRIVE_2MA				0u
#define PADS_BANK0_GPIO2_DRIVE_4MA				1u
#define PADS_BANK0_GPIO2_DRIVE_8MA				2u
#define PADS_BANK0_GPIO2_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO2_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO2_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO2_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO2_SLEWFAST				0u

	/* 0x10: Pad control register */
	uint32_t volatile GPIO3;
	/* Output disable. */
#define PADS_BANK0_GPIO3_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO3_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO3_DRIVE_Msb				5u
#define PADS_BANK0_GPIO3_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO3_DRIVE_2MA				0u
#define PADS_BANK0_GPIO3_DRIVE_4MA				1u
#define PADS_BANK0_GPIO3_DRIVE_8MA				2u
#define PADS_BANK0_GPIO3_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO3_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO3_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO3_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO3_SLEWFAST				0u

	/* 0x14: Pad control register */
	uint32_t volatile GPIO4;
	/* Output disable. */
#define PADS_BANK0_GPIO4_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO4_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO4_DRIVE_Msb				5u
#define PADS_BANK0_GPIO4_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO4_DRIVE_2MA				0u
#define PADS_BANK0_GPIO4_DRIVE_4MA				1u
#define PADS_BANK0_GPIO4_DRIVE_8MA				2u
#define PADS_BANK0_GPIO4_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO4_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO4_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO4_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO4_SLEWFAST				0u

	/* 0x18: Pad control register */
	uint32_t volatile GPIO5;
	/* Output disable. */
#define PADS_BANK0_GPIO5_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO5_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO5_DRIVE_Msb				5u
#define PADS_BANK0_GPIO5_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO5_DRIVE_2MA				0u
#define PADS_BANK0_GPIO5_DRIVE_4MA				1u
#define PADS_BANK0_GPIO5_DRIVE_8MA				2u
#define PADS_BANK0_GPIO5_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO5_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO5_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO5_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO5_SLEWFAST				0u

	/* 0x1C: Pad control register */
	uint32_t volatile GPIO6;
	/* Output disable. */
#define PADS_BANK0_GPIO6_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO6_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO6_DRIVE_Msb				5u
#define PADS_BANK0_GPIO6_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO6_DRIVE_2MA				0u
#define PADS_BANK0_GPIO6_DRIVE_4MA				1u
#define PADS_BANK0_GPIO6_DRIVE_8MA				2u
#define PADS_BANK0_GPIO6_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO6_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO6_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO6_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO6_SLEWFAST				0u

	/* 0x20: Pad control register */
	uint32_t volatile GPIO7;
	/* Output disable. */
#define PADS_BANK0_GPIO7_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO7_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO7_DRIVE_Msb				5u
#define PADS_BANK0_GPIO7_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO7_DRIVE_2MA				0u
#define PADS_BANK0_GPIO7_DRIVE_4MA				1u
#define PADS_BANK0_GPIO7_DRIVE_8MA				2u
#define PADS_BANK0_GPIO7_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO7_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO7_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO7_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO7_SLEWFAST				0u

	/* 0x24: Pad control register */
	uint32_t volatile GPIO8;
	/* Output disable. */
#define PADS_BANK0_GPIO8_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO8_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO8_DRIVE_Msb				5u
#define PADS_BANK0_GPIO8_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO8_DRIVE_2MA				0u
#define PADS_BANK0_GPIO8_DRIVE_4MA				1u
#define PADS_BANK0_GPIO8_DRIVE_8MA				2u
#define PADS_BANK0_GPIO8_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO8_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO8_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO8_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO8_SLEWFAST				0u

	/* 0x28: Pad control register */
	uint32_t volatile GPIO9;
	/* Output disable. */
#define PADS_BANK0_GPIO9_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO9_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO9_DRIVE_Msb				5u
#define PADS_BANK0_GPIO9_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO9_DRIVE_2MA				0u
#define PADS_BANK0_GPIO9_DRIVE_4MA				1u
#define PADS_BANK0_GPIO9_DRIVE_8MA				2u
#define PADS_BANK0_GPIO9_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO9_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO9_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO9_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO9_SLEWFAST				0u

	/* 0x2C: Pad control register */
	uint32_t volatile GPIO10;
	/* Output disable. */
#define PADS_BANK0_GPIO10_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO10_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO10_DRIVE_Msb				5u
#define PADS_BANK0_GPIO10_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO10_DRIVE_2MA				0u
#define PADS_BANK0_GPIO10_DRIVE_4MA				1u
#define PADS_BANK0_GPIO10_DRIVE_8MA				2u
#define PADS_BANK0_GPIO10_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO10_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO10_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO10_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO10_SLEWFAST				0u

	/* 0x30: Pad control register */
	uint32_t volatile GPIO11;
	/* Output disable. */
#define PADS_BANK0_GPIO11_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO11_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO11_DRIVE_Msb				5u
#define PADS_BANK0_GPIO11_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO11_DRIVE_2MA				0u
#define PADS_BANK0_GPIO11_DRIVE_4MA				1u
#define PADS_BANK0_GPIO11_DRIVE_8MA				2u
#define PADS_BANK0_GPIO11_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO11_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO11_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO11_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO11_SLEWFAST				0u

	/* 0x34: Pad control register */
	uint32_t volatile GPIO12;
	/* Output disable. */
#define PADS_BANK0_GPIO12_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO12_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO12_DRIVE_Msb				5u
#define PADS_BANK0_GPIO12_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO12_DRIVE_2MA				0u
#define PADS_BANK0_GPIO12_DRIVE_4MA				1u
#define PADS_BANK0_GPIO12_DRIVE_8MA				2u
#define PADS_BANK0_GPIO12_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO12_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO12_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO12_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO12_SLEWFAST				0u

	/* 0x38: Pad control register */
	uint32_t volatile GPIO13;
	/* Output disable. */
#define PADS_BANK0_GPIO13_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO13_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO13_DRIVE_Msb				5u
#define PADS_BANK0_GPIO13_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO13_DRIVE_2MA				0u
#define PADS_BANK0_GPIO13_DRIVE_4MA				1u
#define PADS_BANK0_GPIO13_DRIVE_8MA				2u
#define PADS_BANK0_GPIO13_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO13_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO13_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO13_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO13_SLEWFAST				0u

	/* 0x3C: Pad control register */
	uint32_t volatile GPIO14;
	/* Output disable. */
#define PADS_BANK0_GPIO14_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO14_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO14_DRIVE_Msb				5u
#define PADS_BANK0_GPIO14_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO14_DRIVE_2MA				0u
#define PADS_BANK0_GPIO14_DRIVE_4MA				1u
#define PADS_BANK0_GPIO14_DRIVE_8MA				2u
#define PADS_BANK0_GPIO14_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO14_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO14_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO14_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO14_SLEWFAST				0u

	/* 0x40: Pad control register */
	uint32_t volatile GPIO15;
	/* Output disable. */
#define PADS_BANK0_GPIO15_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO15_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO15_DRIVE_Msb				5u
#define PADS_BANK0_GPIO15_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO15_DRIVE_2MA				0u
#define PADS_BANK0_GPIO15_DRIVE_4MA				1u
#define PADS_BANK0_GPIO15_DRIVE_8MA				2u
#define PADS_BANK0_GPIO15_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO15_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO15_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO15_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO15_SLEWFAST				0u

	/* 0x44: Pad control register */
	uint32_t volatile GPIO16;
	/* Output disable. */
#define PADS_BANK0_GPIO16_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO16_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO16_DRIVE_Msb				5u
#define PADS_BANK0_GPIO16_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO16_DRIVE_2MA				0u
#define PADS_BANK0_GPIO16_DRIVE_4MA				1u
#define PADS_BANK0_GPIO16_DRIVE_8MA				2u
#define PADS_BANK0_GPIO16_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO16_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO16_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO16_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO16_SLEWFAST				0u

	/* 0x48: Pad control register */
	uint32_t volatile GPIO17;
	/* Output disable. */
#define PADS_BANK0_GPIO17_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO17_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO17_DRIVE_Msb				5u
#define PADS_BANK0_GPIO17_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO17_DRIVE_2MA				0u
#define PADS_BANK0_GPIO17_DRIVE_4MA				1u
#define PADS_BANK0_GPIO17_DRIVE_8MA				2u
#define PADS_BANK0_GPIO17_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO17_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO17_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO17_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO17_SLEWFAST				0u

	/* 0x4C: Pad control register */
	uint32_t volatile GPIO18;
	/* Output disable. */
#define PADS_BANK0_GPIO18_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO18_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO18_DRIVE_Msb				5u
#define PADS_BANK0_GPIO18_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO18_DRIVE_2MA				0u
#define PADS_BANK0_GPIO18_DRIVE_4MA				1u
#define PADS_BANK0_GPIO18_DRIVE_8MA				2u
#define PADS_BANK0_GPIO18_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO18_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO18_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO18_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO18_SLEWFAST				0u

	/* 0x50: Pad control register */
	uint32_t volatile GPIO19;
	/* Output disable. */
#define PADS_BANK0_GPIO19_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO19_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO19_DRIVE_Msb				5u
#define PADS_BANK0_GPIO19_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO19_DRIVE_2MA				0u
#define PADS_BANK0_GPIO19_DRIVE_4MA				1u
#define PADS_BANK0_GPIO19_DRIVE_8MA				2u
#define PADS_BANK0_GPIO19_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO19_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO19_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO19_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO19_SLEWFAST				0u

	/* 0x54: Pad control register */
	uint32_t volatile GPIO20;
	/* Output disable. */
#define PADS_BANK0_GPIO20_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO20_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO20_DRIVE_Msb				5u
#define PADS_BANK0_GPIO20_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO20_DRIVE_2MA				0u
#define PADS_BANK0_GPIO20_DRIVE_4MA				1u
#define PADS_BANK0_GPIO20_DRIVE_8MA				2u
#define PADS_BANK0_GPIO20_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO20_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO20_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO20_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO20_SLEWFAST				0u

	/* 0x58: Pad control register */
	uint32_t volatile GPIO21;
	/* Output disable. */
#define PADS_BANK0_GPIO21_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO21_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO21_DRIVE_Msb				5u
#define PADS_BANK0_GPIO21_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO21_DRIVE_2MA				0u
#define PADS_BANK0_GPIO21_DRIVE_4MA				1u
#define PADS_BANK0_GPIO21_DRIVE_8MA				2u
#define PADS_BANK0_GPIO21_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO21_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO21_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO21_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO21_SLEWFAST				0u

	/* 0x5C: Pad control register */
	uint32_t volatile GPIO22;
	/* Output disable. */
#define PADS_BANK0_GPIO22_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO22_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO22_DRIVE_Msb				5u
#define PADS_BANK0_GPIO22_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO22_DRIVE_2MA				0u
#define PADS_BANK0_GPIO22_DRIVE_4MA				1u
#define PADS_BANK0_GPIO22_DRIVE_8MA				2u
#define PADS_BANK0_GPIO22_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO22_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO22_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO22_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO22_SLEWFAST				0u

	/* 0x60: Pad control register */
	uint32_t volatile GPIO23;
	/* Output disable. */
#define PADS_BANK0_GPIO23_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO23_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO23_DRIVE_Msb				5u
#define PADS_BANK0_GPIO23_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO23_DRIVE_2MA				0u
#define PADS_BANK0_GPIO23_DRIVE_4MA				1u
#define PADS_BANK0_GPIO23_DRIVE_8MA				2u
#define PADS_BANK0_GPIO23_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO23_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO23_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO23_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO23_SLEWFAST				0u

	/* 0x64: Pad control register */
	uint32_t volatile GPIO24;
	/* Output disable. */
#define PADS_BANK0_GPIO24_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO24_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO24_DRIVE_Msb				5u
#define PADS_BANK0_GPIO24_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO24_DRIVE_2MA				0u
#define PADS_BANK0_GPIO24_DRIVE_4MA				1u
#define PADS_BANK0_GPIO24_DRIVE_8MA				2u
#define PADS_BANK0_GPIO24_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO24_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO24_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO24_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO24_SLEWFAST				0u

	/* 0x68: Pad control register */
	uint32_t volatile GPIO25;
	/* Output disable. */
#define PADS_BANK0_GPIO25_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO25_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO25_DRIVE_Msb				5u
#define PADS_BANK0_GPIO25_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO25_DRIVE_2MA				0u
#define PADS_BANK0_GPIO25_DRIVE_4MA				1u
#define PADS_BANK0_GPIO25_DRIVE_8MA				2u
#define PADS_BANK0_GPIO25_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO25_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO25_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO25_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO25_SLEWFAST				0u

	/* 0x6C: Pad control register */
	uint32_t volatile GPIO26;
	/* Output disable. */
#define PADS_BANK0_GPIO26_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO26_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO26_DRIVE_Msb				5u
#define PADS_BANK0_GPIO26_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO26_DRIVE_2MA				0u
#define PADS_BANK0_GPIO26_DRIVE_4MA				1u
#define PADS_BANK0_GPIO26_DRIVE_8MA				2u
#define PADS_BANK0_GPIO26_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO26_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO26_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO26_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO26_SLEWFAST				0u

	/* 0x70: Pad control register */
	uint32_t volatile GPIO27;
	/* Output disable. */
#define PADS_BANK0_GPIO27_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO27_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO27_DRIVE_Msb				5u
#define PADS_BANK0_GPIO27_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO27_DRIVE_2MA				0u
#define PADS_BANK0_GPIO27_DRIVE_4MA				1u
#define PADS_BANK0_GPIO27_DRIVE_8MA				2u
#define PADS_BANK0_GPIO27_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO27_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO27_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO27_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO27_SLEWFAST				0u

	/* 0x74: Pad control register */
	uint32_t volatile GPIO28;
	/* Output disable. */
#define PADS_BANK0_GPIO28_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO28_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO28_DRIVE_Msb				5u
#define PADS_BANK0_GPIO28_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO28_DRIVE_2MA				0u
#define PADS_BANK0_GPIO28_DRIVE_4MA				1u
#define PADS_BANK0_GPIO28_DRIVE_8MA				2u
#define PADS_BANK0_GPIO28_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO28_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO28_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO28_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO28_SLEWFAST				0u

	/* 0x78: Pad control register */
	uint32_t volatile GPIO29;
	/* Output disable. */
#define PADS_BANK0_GPIO29_OD					7u
	/* Input enable */
#define PADS_BANK0_GPIO29_IE					6u
	/* Drive strength. */
#define PADS_BANK0_GPIO29_DRIVE_Msb				5u
#define PADS_BANK0_GPIO29_DRIVE_Lsb				4u
#define PADS_BANK0_GPIO29_DRIVE_2MA				0u
#define PADS_BANK0_GPIO29_DRIVE_4MA				1u
#define PADS_BANK0_GPIO29_DRIVE_8MA				2u
#define PADS_BANK0_GPIO29_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_GPIO29_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_GPIO29_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_GPIO29_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_GPIO29_SLEWFAST				0u

	/* 0x7C: Pad control register */
	uint32_t volatile SWCLK;
	/* Output disable. */
#define PADS_BANK0_SWCLK_OD					7u
	/* Input enable */
#define PADS_BANK0_SWCLK_IE					6u
	/* Drive strength. */
#define PADS_BANK0_SWCLK_DRIVE_Msb				5u
#define PADS_BANK0_SWCLK_DRIVE_Lsb				4u
#define PADS_BANK0_SWCLK_DRIVE_2MA				0u
#define PADS_BANK0_SWCLK_DRIVE_4MA				1u
#define PADS_BANK0_SWCLK_DRIVE_8MA				2u
#define PADS_BANK0_SWCLK_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_SWCLK_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_SWCLK_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_SWCLK_SCHMITT				1u
	/* Slew rate control. */
#define PADS_BANK0_SWCLK_SLEWFAST				0u

	/* 0x80: Pad control register */
	uint32_t volatile SWD;
	/* Output disable. */
#define PADS_BANK0_SWD_OD					7u
	/* Input enable */
#define PADS_BANK0_SWD_IE					6u
	/* Drive strength. */
#define PADS_BANK0_SWD_DRIVE_Msb				5u
#define PADS_BANK0_SWD_DRIVE_Lsb				4u
#define PADS_BANK0_SWD_DRIVE_2MA				0u
#define PADS_BANK0_SWD_DRIVE_4MA				1u
#define PADS_BANK0_SWD_DRIVE_8MA				2u
#define PADS_BANK0_SWD_DRIVE_12MA				3u
	/* Pull up enable */
#define PADS_BANK0_SWD_PUE					3u
	/* Pull down enable */
#define PADS_BANK0_SWD_PDE					2u
	/* Enable schmitt trigger */
#define PADS_BANK0_SWD_SCHMITT					1u
	/* Slew rate control. */
#define PADS_BANK0_SWD_SLEWFAST					0u

};


#define PADS_QSPI ((struct sdk_pads_qspi *)0x40020000)

struct sdk_pads_qspi {

	/* 0x00: Voltage select. */
	uint32_t volatile VOLTAGE_SELECT;
	/*  */
#define PADS_QSPI_VOLTAGE_SELECT_VOLTAGE_SELECT			0u
#define PADS_QSPI_VOLTAGE_SELECT_VOLTAGE_SELECT_3V3		0u
#define PADS_QSPI_VOLTAGE_SELECT_VOLTAGE_SELECT_1V8		1u

	/* 0x04: Pad control register */
	uint32_t volatile GPIO_QSPI_SCLK;
	/* Output disable. */
#define PADS_QSPI_GPIO_QSPI_SCLK_OD				7u
	/* Input enable */
#define PADS_QSPI_GPIO_QSPI_SCLK_IE				6u
	/* Drive strength. */
#define PADS_QSPI_GPIO_QSPI_SCLK_DRIVE_Msb			5u
#define PADS_QSPI_GPIO_QSPI_SCLK_DRIVE_Lsb			4u
#define PADS_QSPI_GPIO_QSPI_SCLK_DRIVE_2MA			0u
#define PADS_QSPI_GPIO_QSPI_SCLK_DRIVE_4MA			1u
#define PADS_QSPI_GPIO_QSPI_SCLK_DRIVE_8MA			2u
#define PADS_QSPI_GPIO_QSPI_SCLK_DRIVE_12MA			3u
	/* Pull up enable */
#define PADS_QSPI_GPIO_QSPI_SCLK_PUE				3u
	/* Pull down enable */
#define PADS_QSPI_GPIO_QSPI_SCLK_PDE				2u
	/* Enable schmitt trigger */
#define PADS_QSPI_GPIO_QSPI_SCLK_SCHMITT			1u
	/* Slew rate control. */
#define PADS_QSPI_GPIO_QSPI_SCLK_SLEWFAST			0u

	/* 0x08: Pad control register */
	uint32_t volatile GPIO_QSPI_SD0;
	/* Output disable. */
#define PADS_QSPI_GPIO_QSPI_SD0_OD				7u
	/* Input enable */
#define PADS_QSPI_GPIO_QSPI_SD0_IE				6u
	/* Drive strength. */
#define PADS_QSPI_GPIO_QSPI_SD0_DRIVE_Msb			5u
#define PADS_QSPI_GPIO_QSPI_SD0_DRIVE_Lsb			4u
#define PADS_QSPI_GPIO_QSPI_SD0_DRIVE_2MA			0u
#define PADS_QSPI_GPIO_QSPI_SD0_DRIVE_4MA			1u
#define PADS_QSPI_GPIO_QSPI_SD0_DRIVE_8MA			2u
#define PADS_QSPI_GPIO_QSPI_SD0_DRIVE_12MA			3u
	/* Pull up enable */
#define PADS_QSPI_GPIO_QSPI_SD0_PUE				3u
	/* Pull down enable */
#define PADS_QSPI_GPIO_QSPI_SD0_PDE				2u
	/* Enable schmitt trigger */
#define PADS_QSPI_GPIO_QSPI_SD0_SCHMITT				1u
	/* Slew rate control. */
#define PADS_QSPI_GPIO_QSPI_SD0_SLEWFAST			0u

	/* 0x0C: Pad control register */
	uint32_t volatile GPIO_QSPI_SD1;
	/* Output disable. */
#define PADS_QSPI_GPIO_QSPI_SD1_OD				7u
	/* Input enable */
#define PADS_QSPI_GPIO_QSPI_SD1_IE				6u
	/* Drive strength. */
#define PADS_QSPI_GPIO_QSPI_SD1_DRIVE_Msb			5u
#define PADS_QSPI_GPIO_QSPI_SD1_DRIVE_Lsb			4u
#define PADS_QSPI_GPIO_QSPI_SD1_DRIVE_2MA			0u
#define PADS_QSPI_GPIO_QSPI_SD1_DRIVE_4MA			1u
#define PADS_QSPI_GPIO_QSPI_SD1_DRIVE_8MA			2u
#define PADS_QSPI_GPIO_QSPI_SD1_DRIVE_12MA			3u
	/* Pull up enable */
#define PADS_QSPI_GPIO_QSPI_SD1_PUE				3u
	/* Pull down enable */
#define PADS_QSPI_GPIO_QSPI_SD1_PDE				2u
	/* Enable schmitt trigger */
#define PADS_QSPI_GPIO_QSPI_SD1_SCHMITT				1u
	/* Slew rate control. */
#define PADS_QSPI_GPIO_QSPI_SD1_SLEWFAST			0u

	/* 0x10: Pad control register */
	uint32_t volatile GPIO_QSPI_SD2;
	/* Output disable. */
#define PADS_QSPI_GPIO_QSPI_SD2_OD				7u
	/* Input enable */
#define PADS_QSPI_GPIO_QSPI_SD2_IE				6u
	/* Drive strength. */
#define PADS_QSPI_GPIO_QSPI_SD2_DRIVE_Msb			5u
#define PADS_QSPI_GPIO_QSPI_SD2_DRIVE_Lsb			4u
#define PADS_QSPI_GPIO_QSPI_SD2_DRIVE_2MA			0u
#define PADS_QSPI_GPIO_QSPI_SD2_DRIVE_4MA			1u
#define PADS_QSPI_GPIO_QSPI_SD2_DRIVE_8MA			2u
#define PADS_QSPI_GPIO_QSPI_SD2_DRIVE_12MA			3u
	/* Pull up enable */
#define PADS_QSPI_GPIO_QSPI_SD2_PUE				3u
	/* Pull down enable */
#define PADS_QSPI_GPIO_QSPI_SD2_PDE				2u
	/* Enable schmitt trigger */
#define PADS_QSPI_GPIO_QSPI_SD2_SCHMITT				1u
	/* Slew rate control. */
#define PADS_QSPI_GPIO_QSPI_SD2_SLEWFAST			0u

	/* 0x14: Pad control register */
	uint32_t volatile GPIO_QSPI_SD3;
	/* Output disable. */
#define PADS_QSPI_GPIO_QSPI_SD3_OD				7u
	/* Input enable */
#define PADS_QSPI_GPIO_QSPI_SD3_IE				6u
	/* Drive strength. */
#define PADS_QSPI_GPIO_QSPI_SD3_DRIVE_Msb			5u
#define PADS_QSPI_GPIO_QSPI_SD3_DRIVE_Lsb			4u
#define PADS_QSPI_GPIO_QSPI_SD3_DRIVE_2MA			0u
#define PADS_QSPI_GPIO_QSPI_SD3_DRIVE_4MA			1u
#define PADS_QSPI_GPIO_QSPI_SD3_DRIVE_8MA			2u
#define PADS_QSPI_GPIO_QSPI_SD3_DRIVE_12MA			3u
	/* Pull up enable */
#define PADS_QSPI_GPIO_QSPI_SD3_PUE				3u
	/* Pull down enable */
#define PADS_QSPI_GPIO_QSPI_SD3_PDE				2u
	/* Enable schmitt trigger */
#define PADS_QSPI_GPIO_QSPI_SD3_SCHMITT				1u
	/* Slew rate control. */
#define PADS_QSPI_GPIO_QSPI_SD3_SLEWFAST			0u

	/* 0x18: Pad control register */
	uint32_t volatile GPIO_QSPI_SS;
	/* Output disable. */
#define PADS_QSPI_GPIO_QSPI_SS_OD				7u
	/* Input enable */
#define PADS_QSPI_GPIO_QSPI_SS_IE				6u
	/* Drive strength. */
#define PADS_QSPI_GPIO_QSPI_SS_DRIVE_Msb			5u
#define PADS_QSPI_GPIO_QSPI_SS_DRIVE_Lsb			4u
#define PADS_QSPI_GPIO_QSPI_SS_DRIVE_2MA			0u
#define PADS_QSPI_GPIO_QSPI_SS_DRIVE_4MA			1u
#define PADS_QSPI_GPIO_QSPI_SS_DRIVE_8MA			2u
#define PADS_QSPI_GPIO_QSPI_SS_DRIVE_12MA			3u
	/* Pull up enable */
#define PADS_QSPI_GPIO_QSPI_SS_PUE				3u
	/* Pull down enable */
#define PADS_QSPI_GPIO_QSPI_SS_PDE				2u
	/* Enable schmitt trigger */
#define PADS_QSPI_GPIO_QSPI_SS_SCHMITT				1u
	/* Slew rate control. */
#define PADS_QSPI_GPIO_QSPI_SS_SLEWFAST				0u

};


#define XOSC ((struct sdk_xosc *)0x40024000)

struct sdk_xosc {

	/* 0x00: Crystal Oscillator Control */
	uint32_t volatile CTRL;
	/* On power-up this field is initialised to DISABLE and the chip runs from the ROSC. */
#define XOSC_CTRL_ENABLE_Msb					23u
#define XOSC_CTRL_ENABLE_Lsb					12u
#define XOSC_CTRL_ENABLE_DISABLE				3358u
#define XOSC_CTRL_ENABLE_ENABLE					4011u
	/* Frequency range. */
#define XOSC_CTRL_FREQ_RANGE_Msb				11u
#define XOSC_CTRL_FREQ_RANGE_Lsb				0u
#define XOSC_CTRL_FREQ_RANGE_1_15MHZ				2720u
#define XOSC_CTRL_FREQ_RANGE_RESERVED_1				2721u
#define XOSC_CTRL_FREQ_RANGE_RESERVED_2				2722u
#define XOSC_CTRL_FREQ_RANGE_RESERVED_3				2723u

	/* 0x04: Crystal Oscillator Status */
	uint32_t volatile STATUS;
	/* Oscillator is running and stable */
#define XOSC_STATUS_STABLE					31u
	/* An invalid value has been written to CTRL_ENABLE or CTRL_FREQ_RANGE or DORMANT */
#define XOSC_STATUS_BADWRITE					24u
	/* Oscillator is enabled but not necessarily running and stable, resets to 0 */
#define XOSC_STATUS_ENABLED					12u
	/* The current frequency range setting, always reads 0 */
#define XOSC_STATUS_FREQ_RANGE_Msb				1u
#define XOSC_STATUS_FREQ_RANGE_Lsb				0u
#define XOSC_STATUS_FREQ_RANGE_1_15MHZ				0u
#define XOSC_STATUS_FREQ_RANGE_RESERVED_1			1u
#define XOSC_STATUS_FREQ_RANGE_RESERVED_2			2u
#define XOSC_STATUS_FREQ_RANGE_RESERVED_3			3u

	/* 0x08: Crystal Oscillator pause control */
	uint32_t volatile DORMANT;

	/* 0x0C: Controls the startup delay */
	uint32_t volatile STARTUP;
	/* Multiplies the startup_delay by 4. */
#define XOSC_STARTUP_X4						20u
	/* in multiples of 256*xtal_period. */
#define XOSC_STARTUP_DELAY_Msb					13u
#define XOSC_STARTUP_DELAY_Lsb					0u

	/* 0x10 */
	uint8_t RESERVED0[0x1C-0x10];

	/* 0x1C: A down counter running at the xosc frequency which counts to zero and stops. */
	uint32_t volatile COUNT;
	/*  */
#define XOSC_COUNT_COUNT_Msb					7u
#define XOSC_COUNT_COUNT_Lsb					0u

};


#define PLL_SYS ((struct sdk_pll *)0x40028000)
#define PLL_USB ((struct sdk_pll *)0x4002C000)

struct sdk_pll {

	/* 0x00: Control and Status */
	uint32_t volatile CS;
	/* PLL is locked */
#define PLL_CS_LOCK						31u
	/* Passes the reference clock to the output instead of the divided VCO. */
#define PLL_CS_BYPASS						8u
	/* Divides the PLL input reference clock. */
#define PLL_CS_REFDIV_Msb					5u
#define PLL_CS_REFDIV_Lsb					0u

	/* 0x04: Controls the PLL power modes. */
	uint32_t volatile PWR;
	/* PLL VCO powerdown */
#define PLL_PWR_VCOPD						5u
	/* PLL post divider powerdown */
#define PLL_PWR_POSTDIVPD					3u
	/* PLL DSM powerdown */
#define PLL_PWR_DSMPD						2u
	/* PLL powerdown */
#define PLL_PWR_PD						0u

	/* 0x08: Feedback divisor */
	uint32_t volatile FBDIV_INT;
	/* see ctrl reg description for constraints */
#define PLL_FBDIV_INT_FBDIV_INT_Msb				11u
#define PLL_FBDIV_INT_FBDIV_INT_Lsb				0u

	/* 0x0C: Controls the PLL post dividers for the primary output */
	uint32_t volatile PRIM;
	/* divide by 1-7 */
#define PLL_PRIM_POSTDIV1_Msb					18u
#define PLL_PRIM_POSTDIV1_Lsb					16u
	/* divide by 1-7 */
#define PLL_PRIM_POSTDIV2_Msb					14u
#define PLL_PRIM_POSTDIV2_Lsb					12u

};


#define BUSCTRL ((struct sdk_busctrl *)0x40030000)

struct sdk_busctrl {

	/* 0x00: Set the priority of each master for bus arbitration. */
	uint32_t volatile BUS_PRIORITY;
	/* 0 - low priority, 1 - high priority */
#define BUSCTRL_BUS_PRIORITY_DMA_W				12u
	/* 0 - low priority, 1 - high priority */
#define BUSCTRL_BUS_PRIORITY_DMA_R				8u
	/* 0 - low priority, 1 - high priority */
#define BUSCTRL_BUS_PRIORITY_PROC1				4u
	/* 0 - low priority, 1 - high priority */
#define BUSCTRL_BUS_PRIORITY_PROC0				0u

	/* 0x04: Bus priority acknowledge */
	uint32_t volatile BUS_PRIORITY_ACK;
	/* Goes to 1 once all arbiters have registered the new global priority levels. */
#define BUSCTRL_BUS_PRIORITY_ACK_BUS_PRIORITY_ACK		0u

	/* 0x08: Bus fabric performance counter 0 */
	uint32_t volatile PERFCTR0;
	/* Busfabric saturating performance counter 0 */
#define BUSCTRL_PERFCTR0_PERFCTR0_Msb				23u
#define BUSCTRL_PERFCTR0_PERFCTR0_Lsb				0u

	/* 0x0C: Bus fabric performance event select for PERFCTR0 */
	uint32_t volatile PERFSEL0;
	/* Select an event for PERFCTR0. */
#define BUSCTRL_PERFSEL0_PERFSEL0_Msb				4u
#define BUSCTRL_PERFSEL0_PERFSEL0_Lsb				0u
#define BUSCTRL_PERFSEL0_PERFSEL0_APB_CONTESTED			0u
#define BUSCTRL_PERFSEL0_PERFSEL0_APB				1u
#define BUSCTRL_PERFSEL0_PERFSEL0_FASTPERI_CONTESTED		2u
#define BUSCTRL_PERFSEL0_PERFSEL0_FASTPERI			3u
#define BUSCTRL_PERFSEL0_PERFSEL0_SRAM5_CONTESTED		4u
#define BUSCTRL_PERFSEL0_PERFSEL0_SRAM5				5u
#define BUSCTRL_PERFSEL0_PERFSEL0_SRAM4_CONTESTED		6u
#define BUSCTRL_PERFSEL0_PERFSEL0_SRAM4				7u
#define BUSCTRL_PERFSEL0_PERFSEL0_SRAM3_CONTESTED		8u
#define BUSCTRL_PERFSEL0_PERFSEL0_SRAM3				9u
#define BUSCTRL_PERFSEL0_PERFSEL0_SRAM2_CONTESTED		10u
#define BUSCTRL_PERFSEL0_PERFSEL0_SRAM2				11u
#define BUSCTRL_PERFSEL0_PERFSEL0_SRAM1_CONTESTED		12u
#define BUSCTRL_PERFSEL0_PERFSEL0_SRAM1				13u
#define BUSCTRL_PERFSEL0_PERFSEL0_SRAM0_CONTESTED		14u
#define BUSCTRL_PERFSEL0_PERFSEL0_SRAM0				15u
#define BUSCTRL_PERFSEL0_PERFSEL0_XIP_MAIN_CONTESTED		16u
#define BUSCTRL_PERFSEL0_PERFSEL0_XIP_MAIN			17u
#define BUSCTRL_PERFSEL0_PERFSEL0_ROM_CONTESTED			18u
#define BUSCTRL_PERFSEL0_PERFSEL0_ROM				19u

	/* 0x10: Bus fabric performance counter 1 */
	uint32_t volatile PERFCTR1;
	/* Busfabric saturating performance counter 1 */
#define BUSCTRL_PERFCTR1_PERFCTR1_Msb				23u
#define BUSCTRL_PERFCTR1_PERFCTR1_Lsb				0u

	/* 0x14: Bus fabric performance event select for PERFCTR1 */
	uint32_t volatile PERFSEL1;
	/* Select an event for PERFCTR1. */
#define BUSCTRL_PERFSEL1_PERFSEL1_Msb				4u
#define BUSCTRL_PERFSEL1_PERFSEL1_Lsb				0u
#define BUSCTRL_PERFSEL1_PERFSEL1_APB_CONTESTED			0u
#define BUSCTRL_PERFSEL1_PERFSEL1_APB				1u
#define BUSCTRL_PERFSEL1_PERFSEL1_FASTPERI_CONTESTED		2u
#define BUSCTRL_PERFSEL1_PERFSEL1_FASTPERI			3u
#define BUSCTRL_PERFSEL1_PERFSEL1_SRAM5_CONTESTED		4u
#define BUSCTRL_PERFSEL1_PERFSEL1_SRAM5				5u
#define BUSCTRL_PERFSEL1_PERFSEL1_SRAM4_CONTESTED		6u
#define BUSCTRL_PERFSEL1_PERFSEL1_SRAM4				7u
#define BUSCTRL_PERFSEL1_PERFSEL1_SRAM3_CONTESTED		8u
#define BUSCTRL_PERFSEL1_PERFSEL1_SRAM3				9u
#define BUSCTRL_PERFSEL1_PERFSEL1_SRAM2_CONTESTED		10u
#define BUSCTRL_PERFSEL1_PERFSEL1_SRAM2				11u
#define BUSCTRL_PERFSEL1_PERFSEL1_SRAM1_CONTESTED		12u
#define BUSCTRL_PERFSEL1_PERFSEL1_SRAM1				13u
#define BUSCTRL_PERFSEL1_PERFSEL1_SRAM0_CONTESTED		14u
#define BUSCTRL_PERFSEL1_PERFSEL1_SRAM0				15u
#define BUSCTRL_PERFSEL1_PERFSEL1_XIP_MAIN_CONTESTED		16u
#define BUSCTRL_PERFSEL1_PERFSEL1_XIP_MAIN			17u
#define BUSCTRL_PERFSEL1_PERFSEL1_ROM_CONTESTED			18u
#define BUSCTRL_PERFSEL1_PERFSEL1_ROM				19u

	/* 0x18: Bus fabric performance counter 2 */
	uint32_t volatile PERFCTR2;
	/* Busfabric saturating performance counter 2 */
#define BUSCTRL_PERFCTR2_PERFCTR2_Msb				23u
#define BUSCTRL_PERFCTR2_PERFCTR2_Lsb				0u

	/* 0x1C: Bus fabric performance event select for PERFCTR2 */
	uint32_t volatile PERFSEL2;
	/* Select an event for PERFCTR2. */
#define BUSCTRL_PERFSEL2_PERFSEL2_Msb				4u
#define BUSCTRL_PERFSEL2_PERFSEL2_Lsb				0u
#define BUSCTRL_PERFSEL2_PERFSEL2_APB_CONTESTED			0u
#define BUSCTRL_PERFSEL2_PERFSEL2_APB				1u
#define BUSCTRL_PERFSEL2_PERFSEL2_FASTPERI_CONTESTED		2u
#define BUSCTRL_PERFSEL2_PERFSEL2_FASTPERI			3u
#define BUSCTRL_PERFSEL2_PERFSEL2_SRAM5_CONTESTED		4u
#define BUSCTRL_PERFSEL2_PERFSEL2_SRAM5				5u
#define BUSCTRL_PERFSEL2_PERFSEL2_SRAM4_CONTESTED		6u
#define BUSCTRL_PERFSEL2_PERFSEL2_SRAM4				7u
#define BUSCTRL_PERFSEL2_PERFSEL2_SRAM3_CONTESTED		8u
#define BUSCTRL_PERFSEL2_PERFSEL2_SRAM3				9u
#define BUSCTRL_PERFSEL2_PERFSEL2_SRAM2_CONTESTED		10u
#define BUSCTRL_PERFSEL2_PERFSEL2_SRAM2				11u
#define BUSCTRL_PERFSEL2_PERFSEL2_SRAM1_CONTESTED		12u
#define BUSCTRL_PERFSEL2_PERFSEL2_SRAM1				13u
#define BUSCTRL_PERFSEL2_PERFSEL2_SRAM0_CONTESTED		14u
#define BUSCTRL_PERFSEL2_PERFSEL2_SRAM0				15u
#define BUSCTRL_PERFSEL2_PERFSEL2_XIP_MAIN_CONTESTED		16u
#define BUSCTRL_PERFSEL2_PERFSEL2_XIP_MAIN			17u
#define BUSCTRL_PERFSEL2_PERFSEL2_ROM_CONTESTED			18u
#define BUSCTRL_PERFSEL2_PERFSEL2_ROM				19u

	/* 0x20: Bus fabric performance counter 3 */
	uint32_t volatile PERFCTR3;
	/* Busfabric saturating performance counter 3 */
#define BUSCTRL_PERFCTR3_PERFCTR3_Msb				23u
#define BUSCTRL_PERFCTR3_PERFCTR3_Lsb				0u

	/* 0x24: Bus fabric performance event select for PERFCTR3 */
	uint32_t volatile PERFSEL3;
	/* Select an event for PERFCTR3. */
#define BUSCTRL_PERFSEL3_PERFSEL3_Msb				4u
#define BUSCTRL_PERFSEL3_PERFSEL3_Lsb				0u
#define BUSCTRL_PERFSEL3_PERFSEL3_APB_CONTESTED			0u
#define BUSCTRL_PERFSEL3_PERFSEL3_APB				1u
#define BUSCTRL_PERFSEL3_PERFSEL3_FASTPERI_CONTESTED		2u
#define BUSCTRL_PERFSEL3_PERFSEL3_FASTPERI			3u
#define BUSCTRL_PERFSEL3_PERFSEL3_SRAM5_CONTESTED		4u
#define BUSCTRL_PERFSEL3_PERFSEL3_SRAM5				5u
#define BUSCTRL_PERFSEL3_PERFSEL3_SRAM4_CONTESTED		6u
#define BUSCTRL_PERFSEL3_PERFSEL3_SRAM4				7u
#define BUSCTRL_PERFSEL3_PERFSEL3_SRAM3_CONTESTED		8u
#define BUSCTRL_PERFSEL3_PERFSEL3_SRAM3				9u
#define BUSCTRL_PERFSEL3_PERFSEL3_SRAM2_CONTESTED		10u
#define BUSCTRL_PERFSEL3_PERFSEL3_SRAM2				11u
#define BUSCTRL_PERFSEL3_PERFSEL3_SRAM1_CONTESTED		12u
#define BUSCTRL_PERFSEL3_PERFSEL3_SRAM1				13u
#define BUSCTRL_PERFSEL3_PERFSEL3_SRAM0_CONTESTED		14u
#define BUSCTRL_PERFSEL3_PERFSEL3_SRAM0				15u
#define BUSCTRL_PERFSEL3_PERFSEL3_XIP_MAIN_CONTESTED		16u
#define BUSCTRL_PERFSEL3_PERFSEL3_XIP_MAIN			17u
#define BUSCTRL_PERFSEL3_PERFSEL3_ROM_CONTESTED			18u
#define BUSCTRL_PERFSEL3_PERFSEL3_ROM				19u

};


#define UART0 ((struct sdk_uart0 *)0x40034000)
#define UART1 ((struct sdk_uart1 *)0x40038000)

struct sdk_uart0 {

	/* 0x00: Data Register, UARTDR */
	uint32_t volatile UARTDR;
	/* Overrun error. */
#define UART0_UARTDR_OE						11u
	/* Break error. This bit is set to 1 if a break condition was detected, indicating that the received data input was held LOW for longer than a full-word transmission time (defined as start, data, parity and stop bits). In FIFO mode, this error is associated with the character at the top of the FIFO. When a break occurs, only one 0 character is loaded into the FIFO. The next character is only enabled after the receive data input goes to a 1 (marking state), and the next valid start bit is received. */
#define UART0_UARTDR_BE						10u
	/* Parity error. */
#define UART0_UARTDR_PE						9u
	/* Framing error. When set to 1, it indicates that the received character did not have a valid stop bit (a valid stop bit is 1). */
#define UART0_UARTDR_FE						8u
	/* Receive (read) data character. Transmit (write) data character. */
#define UART0_UARTDR_DATA_Msb					7u
#define UART0_UARTDR_DATA_Lsb					0u

	/* 0x04: Receive Status Register/Error Clear Register, UARTRSR/UARTECR */
	uint32_t volatile UARTRSR;
	/* Overrun error. */
#define UART0_UARTRSR_OE					3u
	/* Break error. This bit is set to 1 if a break condition was detected, indicating that the received data input was held LOW for longer than a full-word transmission time (defined as start, data, parity, and stop bits). This bit is cleared to 0 after a write to UARTECR. In FIFO mode, this error is associated with the character at the top of the FIFO. When a break occurs, only one 0 character is loaded into the FIFO. The next character is only enabled after the receive data input goes to a 1 (marking state) and the next valid start bit is received. */
#define UART0_UARTRSR_BE					2u
	/* Parity error. */
#define UART0_UARTRSR_PE					1u
	/* Framing error. When set to 1, it indicates that the received character did not have a valid stop bit (a valid stop bit is 1). */
#define UART0_UARTRSR_FE					0u

	/* 0x08 */
	uint8_t RESERVED0[0x18-0x08];

	/* 0x18: Flag Register, UARTFR */
	uint32_t volatile UARTFR;
	/* Ring indicator. */
#define UART0_UARTFR_RI						8u
	/* Transmit FIFO empty. */
#define UART0_UARTFR_TXFE					7u
	/* Receive FIFO full. */
#define UART0_UARTFR_RXFF					6u
	/* Transmit FIFO full. */
#define UART0_UARTFR_TXFF					5u
	/* Receive FIFO empty. */
#define UART0_UARTFR_RXFE					4u
	/* UART busy. */
#define UART0_UARTFR_BUSY					3u
	/* Data carrier detect. */
#define UART0_UARTFR_DCD					2u
	/* Data set ready. */
#define UART0_UARTFR_DSR					1u
	/* Clear to send. */
#define UART0_UARTFR_CTS					0u

	/* 0x1C */
	uint8_t RESERVED1[0x20-0x1C];

	/* 0x20: IrDA Low-Power Counter Register, UARTILPR */
	uint32_t volatile UARTILPR;
	/* 8-bit low-power divisor value. */
#define UART0_UARTILPR_ILPDVSR_Msb				7u
#define UART0_UARTILPR_ILPDVSR_Lsb				0u

	/* 0x24: Integer Baud Rate Register, UARTIBRD */
	uint32_t volatile UARTIBRD;
	/* The integer baud rate divisor. */
#define UART0_UARTIBRD_BAUD_DIVINT_Msb				15u
#define UART0_UARTIBRD_BAUD_DIVINT_Lsb				0u

	/* 0x28: Fractional Baud Rate Register, UARTFBRD */
	uint32_t volatile UARTFBRD;
	/* The fractional baud rate divisor. */
#define UART0_UARTFBRD_BAUD_DIVFRAC_Msb				5u
#define UART0_UARTFBRD_BAUD_DIVFRAC_Lsb				0u

	/* 0x2C: Line Control Register, UARTLCR_H */
	uint32_t volatile UARTLCR_H;
	/* Stick parity select. */
#define UART0_UARTLCR_H_SPS					7u
	/* Word length. */
#define UART0_UARTLCR_H_WLEN_Msb				6u
#define UART0_UARTLCR_H_WLEN_Lsb				5u
	/* Enable FIFOs: 0 = FIFOs are disabled (character mode) that is, the FIFOs become 1-byte-deep holding registers 1 = transmit and receive FIFO buffers are enabled (FIFO mode). */
#define UART0_UARTLCR_H_FEN					4u
	/* Two stop bits select. */
#define UART0_UARTLCR_H_STP2					3u
	/* Even parity select. */
#define UART0_UARTLCR_H_EPS					2u
	/* Parity enable: 0 = parity is disabled and no parity bit added to the data frame 1 = parity checking and generation is enabled. */
#define UART0_UARTLCR_H_PEN					1u
	/* Send break. */
#define UART0_UARTLCR_H_BRK					0u

	/* 0x30: Control Register, UARTCR */
	uint32_t volatile UARTCR;
	/* CTS hardware flow control enable. */
#define UART0_UARTCR_CTSEN					15u
	/* RTS hardware flow control enable. */
#define UART0_UARTCR_RTSEN					14u
	/* This bit is the complement of the UART Out2 (nUARTOut2) modem status output. That is, when the bit is programmed to a 1, the output is 0. For DTE this can be used as Ring Indicator (RI). */
#define UART0_UARTCR_OUT2					13u
	/* This bit is the complement of the UART Out1 (nUARTOut1) modem status output. That is, when the bit is programmed to a 1 the output is 0. For DTE this can be used as Data Carrier Detect (DCD). */
#define UART0_UARTCR_OUT1					12u
	/* Request to send. */
#define UART0_UARTCR_RTS					11u
	/* Data transmit ready. */
#define UART0_UARTCR_DTR					10u
	/* Receive enable. */
#define UART0_UARTCR_RXE					9u
	/* Transmit enable. */
#define UART0_UARTCR_TXE					8u
	/* Loopback enable. */
#define UART0_UARTCR_LBE					7u
	/* SIR low-power IrDA mode. */
#define UART0_UARTCR_SIRLP					2u
	/* SIR enable: 0 = IrDA SIR ENDEC is disabled. nSIROUT remains LOW (no light pulse generated), and signal transitions on SIRIN have no effect. */
#define UART0_UARTCR_SIREN					1u
	/* UART enable: 0 = UART is disabled. */
#define UART0_UARTCR_UARTEN					0u

	/* 0x34: Interrupt FIFO Level Select Register, UARTIFLS */
	uint32_t volatile UARTIFLS;
	/* Receive interrupt FIFO level select. */
#define UART0_UARTIFLS_RXIFLSEL_Msb				5u
#define UART0_UARTIFLS_RXIFLSEL_Lsb				3u
	/* Transmit interrupt FIFO level select. */
#define UART0_UARTIFLS_TXIFLSEL_Msb				2u
#define UART0_UARTIFLS_TXIFLSEL_Lsb				0u

	/* 0x38: Interrupt Mask Set/Clear Register, UARTIMSC */
	uint32_t volatile UARTIMSC;
	/* Overrun error interrupt mask. */
#define UART0_UARTIMSC_OEIM					10u
	/* Break error interrupt mask. */
#define UART0_UARTIMSC_BEIM					9u
	/* Parity error interrupt mask. */
#define UART0_UARTIMSC_PEIM					8u
	/* Framing error interrupt mask. */
#define UART0_UARTIMSC_FEIM					7u
	/* Receive timeout interrupt mask. */
#define UART0_UARTIMSC_RTIM					6u
	/* Transmit interrupt mask. */
#define UART0_UARTIMSC_TXIM					5u
	/* Receive interrupt mask. */
#define UART0_UARTIMSC_RXIM					4u
	/* nUARTDSR modem interrupt mask. */
#define UART0_UARTIMSC_DSRMIM					3u
	/* nUARTDCD modem interrupt mask. */
#define UART0_UARTIMSC_DCDMIM					2u
	/* nUARTCTS modem interrupt mask. */
#define UART0_UARTIMSC_CTSMIM					1u
	/* nUARTRI modem interrupt mask. */
#define UART0_UARTIMSC_RIMIM					0u

	/* 0x3C: Raw Interrupt Status Register, UARTRIS */
	uint32_t volatile UARTRIS;
	/* Overrun error interrupt status. */
#define UART0_UARTRIS_OERIS					10u
	/* Break error interrupt status. */
#define UART0_UARTRIS_BERIS					9u
	/* Parity error interrupt status. */
#define UART0_UARTRIS_PERIS					8u
	/* Framing error interrupt status. */
#define UART0_UARTRIS_FERIS					7u
	/* Receive timeout interrupt status. */
#define UART0_UARTRIS_RTRIS					6u
	/* Transmit interrupt status. */
#define UART0_UARTRIS_TXRIS					5u
	/* Receive interrupt status. */
#define UART0_UARTRIS_RXRIS					4u
	/* nUARTDSR modem interrupt status. */
#define UART0_UARTRIS_DSRRMIS					3u
	/* nUARTDCD modem interrupt status. */
#define UART0_UARTRIS_DCDRMIS					2u
	/* nUARTCTS modem interrupt status. */
#define UART0_UARTRIS_CTSRMIS					1u
	/* nUARTRI modem interrupt status. */
#define UART0_UARTRIS_RIRMIS					0u

	/* 0x40: Masked Interrupt Status Register, UARTMIS */
	uint32_t volatile UARTMIS;
	/* Overrun error masked interrupt status. */
#define UART0_UARTMIS_OEMIS					10u
	/* Break error masked interrupt status. */
#define UART0_UARTMIS_BEMIS					9u
	/* Parity error masked interrupt status. */
#define UART0_UARTMIS_PEMIS					8u
	/* Framing error masked interrupt status. */
#define UART0_UARTMIS_FEMIS					7u
	/* Receive timeout masked interrupt status. */
#define UART0_UARTMIS_RTMIS					6u
	/* Transmit masked interrupt status. */
#define UART0_UARTMIS_TXMIS					5u
	/* Receive masked interrupt status. */
#define UART0_UARTMIS_RXMIS					4u
	/* nUARTDSR modem masked interrupt status. */
#define UART0_UARTMIS_DSRMMIS					3u
	/* nUARTDCD modem masked interrupt status. */
#define UART0_UARTMIS_DCDMMIS					2u
	/* nUARTCTS modem masked interrupt status. */
#define UART0_UARTMIS_CTSMMIS					1u
	/* nUARTRI modem masked interrupt status. */
#define UART0_UARTMIS_RIMMIS					0u

	/* 0x44: Interrupt Clear Register, UARTICR */
	uint32_t volatile UARTICR;
	/* Overrun error interrupt clear. */
#define UART0_UARTICR_OEIC					10u
	/* Break error interrupt clear. */
#define UART0_UARTICR_BEIC					9u
	/* Parity error interrupt clear. */
#define UART0_UARTICR_PEIC					8u
	/* Framing error interrupt clear. */
#define UART0_UARTICR_FEIC					7u
	/* Receive timeout interrupt clear. */
#define UART0_UARTICR_RTIC					6u
	/* Transmit interrupt clear. */
#define UART0_UARTICR_TXIC					5u
	/* Receive interrupt clear. */
#define UART0_UARTICR_RXIC					4u
	/* nUARTDSR modem interrupt clear. */
#define UART0_UARTICR_DSRMIC					3u
	/* nUARTDCD modem interrupt clear. */
#define UART0_UARTICR_DCDMIC					2u
	/* nUARTCTS modem interrupt clear. */
#define UART0_UARTICR_CTSMIC					1u
	/* nUARTRI modem interrupt clear. */
#define UART0_UARTICR_RIMIC					0u

	/* 0x48: DMA Control Register, UARTDMACR */
	uint32_t volatile UARTDMACR;
	/* DMA on error. */
#define UART0_UARTDMACR_DMAONERR				2u
	/* Transmit DMA enable. */
#define UART0_UARTDMACR_TXDMAE					1u
	/* Receive DMA enable. */
#define UART0_UARTDMACR_RXDMAE					0u

	/* 0x4C */
	uint8_t RESERVED2[0xFE0-0x4C];

	/* 0xFE0: UARTPeriphID0 Register */
	uint32_t volatile UARTPERIPHID0;
	/* These bits read back as 0x11 */
#define UART0_UARTPERIPHID0_PARTNUMBER0_Msb			7u
#define UART0_UARTPERIPHID0_PARTNUMBER0_Lsb			0u

	/* 0xFE4: UARTPeriphID1 Register */
	uint32_t volatile UARTPERIPHID1;
	/* These bits read back as 0x1 */
#define UART0_UARTPERIPHID1_DESIGNER0_Msb			7u
#define UART0_UARTPERIPHID1_DESIGNER0_Lsb			4u
	/* These bits read back as 0x0 */
#define UART0_UARTPERIPHID1_PARTNUMBER1_Msb			3u
#define UART0_UARTPERIPHID1_PARTNUMBER1_Lsb			0u

	/* 0xFE8: UARTPeriphID2 Register */
	uint32_t volatile UARTPERIPHID2;
	/* This field depends on the revision of the UART: r1p0 0x0 r1p1 0x1 r1p3 0x2 r1p4 0x2 r1p5 0x3 */
#define UART0_UARTPERIPHID2_REVISION_Msb			7u
#define UART0_UARTPERIPHID2_REVISION_Lsb			4u
	/* These bits read back as 0x4 */
#define UART0_UARTPERIPHID2_DESIGNER1_Msb			3u
#define UART0_UARTPERIPHID2_DESIGNER1_Lsb			0u

	/* 0xFEC: UARTPeriphID3 Register */
	uint32_t volatile UARTPERIPHID3;
	/* These bits read back as 0x00 */
#define UART0_UARTPERIPHID3_CONFIGURATION_Msb			7u
#define UART0_UARTPERIPHID3_CONFIGURATION_Lsb			0u

	/* 0xFF0: UARTPCellID0 Register */
	uint32_t volatile UARTPCELLID0;
	/* These bits read back as 0x0D */
#define UART0_UARTPCELLID0_UARTPCELLID0_Msb			7u
#define UART0_UARTPCELLID0_UARTPCELLID0_Lsb			0u

	/* 0xFF4: UARTPCellID1 Register */
	uint32_t volatile UARTPCELLID1;
	/* These bits read back as 0xF0 */
#define UART0_UARTPCELLID1_UARTPCELLID1_Msb			7u
#define UART0_UARTPCELLID1_UARTPCELLID1_Lsb			0u

	/* 0xFF8: UARTPCellID2 Register */
	uint32_t volatile UARTPCELLID2;
	/* These bits read back as 0x05 */
#define UART0_UARTPCELLID2_UARTPCELLID2_Msb			7u
#define UART0_UARTPCELLID2_UARTPCELLID2_Lsb			0u

	/* 0xFFC: UARTPCellID3 Register */
	uint32_t volatile UARTPCELLID3;
	/* These bits read back as 0xB1 */
#define UART0_UARTPCELLID3_UARTPCELLID3_Msb			7u
#define UART0_UARTPCELLID3_UARTPCELLID3_Lsb			0u

};


#define SPI0 ((struct sdk_spi0 *)0x4003C000)
#define SPI1 ((struct sdk_spi1 *)0x40040000)

struct sdk_spi0 {

	/* 0x00: Control register 0, SSPCR0 on page 3-4 */
	uint32_t volatile SSPCR0;
	/* Serial clock rate. The value SCR is used to generate the transmit and receive bit rate of the PrimeCell SSP. The bit rate is: F SSPCLK CPSDVSR x (1+SCR) where CPSDVSR is an even value from 2-254, programmed through the SSPCPSR register and SCR is a value from 0-255. */
#define SPI0_SSPCR0_SCR_Msb					15u
#define SPI0_SSPCR0_SCR_Lsb					8u
	/* SSPCLKOUT phase, applicable to Motorola SPI frame format only. */
#define SPI0_SSPCR0_SPH						7u
	/* SSPCLKOUT polarity, applicable to Motorola SPI frame format only. */
#define SPI0_SSPCR0_SPO						6u
	/* Frame format: 00 Motorola SPI frame format. */
#define SPI0_SSPCR0_FRF_Msb					5u
#define SPI0_SSPCR0_FRF_Lsb					4u
	/* Data Size Select: 0000 Reserved, undefined operation. */
#define SPI0_SSPCR0_DSS_Msb					3u
#define SPI0_SSPCR0_DSS_Lsb					0u

	/* 0x04: Control register 1, SSPCR1 on page 3-5 */
	uint32_t volatile SSPCR1;
	/* Slave-mode output disable. */
#define SPI0_SSPCR1_SOD						3u
	/* Master or slave mode select. */
#define SPI0_SSPCR1_MS						2u
	/* Synchronous serial port enable: 0 SSP operation disabled. */
#define SPI0_SSPCR1_SSE						1u
	/* Loop back mode: 0 Normal serial port operation enabled. */
#define SPI0_SSPCR1_LBM						0u

	/* 0x08: Data register, SSPDR on page 3-6 */
	uint32_t volatile SSPDR;
	/* Transmit/Receive FIFO: Read Receive FIFO. */
#define SPI0_SSPDR_DATA_Msb					15u
#define SPI0_SSPDR_DATA_Lsb					0u

	/* 0x0C: Status register, SSPSR on page 3-7 */
	uint32_t volatile SSPSR;
	/* PrimeCell SSP busy flag, RO: 0 SSP is idle. */
#define SPI0_SSPSR_BSY						4u
	/* Receive FIFO full, RO: 0 Receive FIFO is not full. */
#define SPI0_SSPSR_RFF						3u
	/* Receive FIFO not empty, RO: 0 Receive FIFO is empty. */
#define SPI0_SSPSR_RNE						2u
	/* Transmit FIFO not full, RO: 0 Transmit FIFO is full. */
#define SPI0_SSPSR_TNF						1u
	/* Transmit FIFO empty, RO: 0 Transmit FIFO is not empty. */
#define SPI0_SSPSR_TFE						0u

	/* 0x10: Clock prescale register, SSPCPSR on page 3-8 */
	uint32_t volatile SSPCPSR;
	/* Clock prescale divisor. */
#define SPI0_SSPCPSR_CPSDVSR_Msb				7u
#define SPI0_SSPCPSR_CPSDVSR_Lsb				0u

	/* 0x14: Interrupt mask set or clear register, SSPIMSC on page 3-9 */
	uint32_t volatile SSPIMSC;
	/* Transmit FIFO interrupt mask: 0 Transmit FIFO half empty or less condition interrupt is masked. */
#define SPI0_SSPIMSC_TXIM					3u
	/* Receive FIFO interrupt mask: 0 Receive FIFO half full or less condition interrupt is masked. */
#define SPI0_SSPIMSC_RXIM					2u
	/* Receive timeout interrupt mask: 0 Receive FIFO not empty and no read prior to timeout period interrupt is masked. */
#define SPI0_SSPIMSC_RTIM					1u
	/* Receive overrun interrupt mask: 0 Receive FIFO written to while full condition interrupt is masked. */
#define SPI0_SSPIMSC_RORIM					0u

	/* 0x18: Raw interrupt status register, SSPRIS on page 3-10 */
	uint32_t volatile SSPRIS;
	/* Gives the raw interrupt state, prior to masking, of the SSPTXINTR interrupt */
#define SPI0_SSPRIS_TXRIS					3u
	/* Gives the raw interrupt state, prior to masking, of the SSPRXINTR interrupt */
#define SPI0_SSPRIS_RXRIS					2u
	/* Gives the raw interrupt state, prior to masking, of the SSPRTINTR interrupt */
#define SPI0_SSPRIS_RTRIS					1u
	/* Gives the raw interrupt state, prior to masking, of the SSPRORINTR interrupt */
#define SPI0_SSPRIS_RORRIS					0u

	/* 0x1C: Masked interrupt status register, SSPMIS on page 3-11 */
	uint32_t volatile SSPMIS;
	/* Gives the transmit FIFO masked interrupt state, after masking, of the SSPTXINTR interrupt */
#define SPI0_SSPMIS_TXMIS					3u
	/* Gives the receive FIFO masked interrupt state, after masking, of the SSPRXINTR interrupt */
#define SPI0_SSPMIS_RXMIS					2u
	/* Gives the receive timeout masked interrupt state, after masking, of the SSPRTINTR interrupt */
#define SPI0_SSPMIS_RTMIS					1u
	/* Gives the receive over run masked interrupt status, after masking, of the SSPRORINTR interrupt */
#define SPI0_SSPMIS_RORMIS					0u

	/* 0x20: Interrupt clear register, SSPICR on page 3-11 */
	uint32_t volatile SSPICR;
	/* Clears the SSPRTINTR interrupt */
#define SPI0_SSPICR_RTIC					1u
	/* Clears the SSPRORINTR interrupt */
#define SPI0_SSPICR_RORIC					0u

	/* 0x24: DMA control register, SSPDMACR on page 3-12 */
	uint32_t volatile SSPDMACR;
	/* Transmit DMA Enable. */
#define SPI0_SSPDMACR_TXDMAE					1u
	/* Receive DMA Enable. */
#define SPI0_SSPDMACR_RXDMAE					0u

	/* 0x28 */
	uint8_t RESERVED0[0xFE0-0x28];

	/* 0xFE0: Peripheral identification registers, SSPPeriphID0-3 on page 3-13 */
	uint32_t volatile SSPPERIPHID0;
	/* These bits read back as 0x22 */
#define SPI0_SSPPERIPHID0_PARTNUMBER0_Msb			7u
#define SPI0_SSPPERIPHID0_PARTNUMBER0_Lsb			0u

	/* 0xFE4: Peripheral identification registers, SSPPeriphID0-3 on page 3-13 */
	uint32_t volatile SSPPERIPHID1;
	/* These bits read back as 0x1 */
#define SPI0_SSPPERIPHID1_DESIGNER0_Msb				7u
#define SPI0_SSPPERIPHID1_DESIGNER0_Lsb				4u
	/* These bits read back as 0x0 */
#define SPI0_SSPPERIPHID1_PARTNUMBER1_Msb			3u
#define SPI0_SSPPERIPHID1_PARTNUMBER1_Lsb			0u

	/* 0xFE8: Peripheral identification registers, SSPPeriphID0-3 on page 3-13 */
	uint32_t volatile SSPPERIPHID2;
	/* These bits return the peripheral revision */
#define SPI0_SSPPERIPHID2_REVISION_Msb				7u
#define SPI0_SSPPERIPHID2_REVISION_Lsb				4u
	/* These bits read back as 0x4 */
#define SPI0_SSPPERIPHID2_DESIGNER1_Msb				3u
#define SPI0_SSPPERIPHID2_DESIGNER1_Lsb				0u

	/* 0xFEC: Peripheral identification registers, SSPPeriphID0-3 on page 3-13 */
	uint32_t volatile SSPPERIPHID3;
	/* These bits read back as 0x00 */
#define SPI0_SSPPERIPHID3_CONFIGURATION_Msb			7u
#define SPI0_SSPPERIPHID3_CONFIGURATION_Lsb			0u

	/* 0xFF0: PrimeCell identification registers, SSPPCellID0-3 on page 3-16 */
	uint32_t volatile SSPPCELLID0;
	/* These bits read back as 0x0D */
#define SPI0_SSPPCELLID0_SSPPCELLID0_Msb			7u
#define SPI0_SSPPCELLID0_SSPPCELLID0_Lsb			0u

	/* 0xFF4: PrimeCell identification registers, SSPPCellID0-3 on page 3-16 */
	uint32_t volatile SSPPCELLID1;
	/* These bits read back as 0xF0 */
#define SPI0_SSPPCELLID1_SSPPCELLID1_Msb			7u
#define SPI0_SSPPCELLID1_SSPPCELLID1_Lsb			0u

	/* 0xFF8: PrimeCell identification registers, SSPPCellID0-3 on page 3-16 */
	uint32_t volatile SSPPCELLID2;
	/* These bits read back as 0x05 */
#define SPI0_SSPPCELLID2_SSPPCELLID2_Msb			7u
#define SPI0_SSPPCELLID2_SSPPCELLID2_Lsb			0u

	/* 0xFFC: PrimeCell identification registers, SSPPCellID0-3 on page 3-16 */
	uint32_t volatile SSPPCELLID3;
	/* These bits read back as 0xB1 */
#define SPI0_SSPPCELLID3_SSPPCELLID3_Msb			7u
#define SPI0_SSPPCELLID3_SSPPCELLID3_Lsb			0u

};


#define I2C0 ((struct sdk_i2c0 *)0x40044000)
#define I2C1 ((struct sdk_i2c1 *)0x40048000)

struct sdk_i2c0 {

	/* 0x00: I2C Control Register. */
	uint32_t volatile IC_CON;
	/* Master issues the STOP_DET interrupt irrespective of whether master is active or not */
#define I2C0_IC_CON_STOP_DET_IF_MASTER_ACTIVE			10u
	/* This bit controls whether DW_apb_i2c should hold the bus when the Rx FIFO is physically full to its RX_BUFFER_DEPTH, as described in the IC_RX_FULL_HLD_BUS_EN parameter. */
#define I2C0_IC_CON_RX_FIFO_FULL_HLD_CTRL			9u
#define I2C0_IC_CON_RX_FIFO_FULL_HLD_CTRL_DISABLED		0u
#define I2C0_IC_CON_RX_FIFO_FULL_HLD_CTRL_ENABLED		1u
	/* This bit controls the generation of the TX_EMPTY interrupt, as described in the IC_RAW_INTR_STAT register. */
#define I2C0_IC_CON_TX_EMPTY_CTRL				8u
#define I2C0_IC_CON_TX_EMPTY_CTRL_DISABLED			0u
#define I2C0_IC_CON_TX_EMPTY_CTRL_ENABLED			1u
	/* In slave mode: - 1'b1:  issues the STOP_DET interrupt only when it is addressed. */
#define I2C0_IC_CON_STOP_DET_IFADDRESSED			7u
#define I2C0_IC_CON_STOP_DET_IFADDRESSED_DISABLED		0u
#define I2C0_IC_CON_STOP_DET_IFADDRESSED_ENABLED		1u
	/* This bit controls whether I2C has its slave disabled, which means once the presetn signal is applied, then this bit is set and the slave is disabled. */
#define I2C0_IC_CON_IC_SLAVE_DISABLE				6u
#define I2C0_IC_CON_IC_SLAVE_DISABLE_SLAVE_ENABLED		0u
#define I2C0_IC_CON_IC_SLAVE_DISABLE_SLAVE_DISABLED		1u
	/* Determines whether RESTART conditions may be sent when acting as a master. Some older slaves do not support handling RESTART conditions; however, RESTART conditions are used in several DW_apb_i2c operations. When RESTART is disabled, the master is prohibited from performing the following functions: - Sending a START BYTE - Performing any high-speed mode operation - High-speed mode operation - Performing direction changes in combined format mode - Performing a read operation with a 10-bit address By replacing RESTART condition followed by a STOP and a subsequent START condition, split operations are broken down into multiple DW_apb_i2c transfers. If the above operations are performed, it will result in setting bit 6 (TX_ABRT) of the IC_RAW_INTR_STAT register. */
#define I2C0_IC_CON_IC_RESTART_EN				5u
#define I2C0_IC_CON_IC_RESTART_EN_DISABLED			0u
#define I2C0_IC_CON_IC_RESTART_EN_ENABLED			1u
	/* Controls whether the DW_apb_i2c starts its transfers in 7- or 10-bit addressing mode when acting as a master. */
#define I2C0_IC_CON_IC_10BITADDR_MASTER				4u
#define I2C0_IC_CON_IC_10BITADDR_MASTER_ADDR_7BITS		0u
#define I2C0_IC_CON_IC_10BITADDR_MASTER_ADDR_10BITS		1u
	/* When acting as a slave, this bit controls whether the DW_apb_i2c responds to 7- or 10-bit addresses. */
#define I2C0_IC_CON_IC_10BITADDR_SLAVE				3u
#define I2C0_IC_CON_IC_10BITADDR_SLAVE_ADDR_7BITS		0u
#define I2C0_IC_CON_IC_10BITADDR_SLAVE_ADDR_10BITS		1u
	/* These bits control at which speed the DW_apb_i2c operates; its setting is relevant only if one is operating the DW_apb_i2c in master mode. */
#define I2C0_IC_CON_SPEED_Msb					2u
#define I2C0_IC_CON_SPEED_Lsb					1u
#define I2C0_IC_CON_SPEED_STANDARD				1u
#define I2C0_IC_CON_SPEED_FAST					2u
#define I2C0_IC_CON_SPEED_HIGH					3u
	/* This bit controls whether the DW_apb_i2c master is enabled. */
#define I2C0_IC_CON_MASTER_MODE					0u
#define I2C0_IC_CON_MASTER_MODE_DISABLED			0u
#define I2C0_IC_CON_MASTER_MODE_ENABLED				1u

	/* 0x04: I2C Target Address Register */
	uint32_t volatile IC_TAR;
	/* This bit indicates whether software performs a Device-ID or General Call or START BYTE command. */
#define I2C0_IC_TAR_SPECIAL					11u
#define I2C0_IC_TAR_SPECIAL_DISABLED				0u
#define I2C0_IC_TAR_SPECIAL_ENABLED				1u
	/* If bit 11 (SPECIAL) is set to 1 and bit 13(Device-ID) is set to 0, then this bit indicates whether a General Call or START byte command is to be performed by the DW_apb_i2c. - 0: General Call Address - after issuing a General Call, only writes may be performed. Attempting to issue a read command results in setting bit 6 (TX_ABRT) of the IC_RAW_INTR_STAT register. The DW_apb_i2c remains in General Call mode until the SPECIAL bit value (bit 11) is cleared. */
#define I2C0_IC_TAR_GC_OR_START					10u
#define I2C0_IC_TAR_GC_OR_START_GENERAL_CALL			0u
#define I2C0_IC_TAR_GC_OR_START_START_BYTE			1u
	/* This is the target address for any master transaction. */
#define I2C0_IC_TAR_IC_TAR_Msb					9u
#define I2C0_IC_TAR_IC_TAR_Lsb					0u

	/* 0x08: I2C Slave Address Register */
	uint32_t volatile IC_SAR;
	/* The IC_SAR holds the slave address when the I2C is operating as a slave. */
#define I2C0_IC_SAR_IC_SAR_Msb					9u
#define I2C0_IC_SAR_IC_SAR_Lsb					0u

	/* 0x0C */
	uint8_t RESERVED0[0x10-0x0C];

	/* 0x10: I2C Rx/Tx Data Buffer and Command Register; this is the register the CPU writes to when filling the TX FIFO and the CPU reads from when retrieving bytes from RX FIFO. */
	uint32_t volatile IC_DATA_CMD;
	/* Indicates the first data byte received after the address phase for receive transfer in Master receiver or Slave receiver mode. */
#define I2C0_IC_DATA_CMD_FIRST_DATA_BYTE			11u
#define I2C0_IC_DATA_CMD_FIRST_DATA_BYTE_INACTIVE		0u
#define I2C0_IC_DATA_CMD_FIRST_DATA_BYTE_ACTIVE			1u
	/* This bit controls whether a RESTART is issued before the byte is sent or received. */
#define I2C0_IC_DATA_CMD_RESTART				10u
#define I2C0_IC_DATA_CMD_RESTART_DISABLE			0u
#define I2C0_IC_DATA_CMD_RESTART_ENABLE				1u
	/* This bit controls whether a STOP is issued after the byte is sent or received. */
#define I2C0_IC_DATA_CMD_STOP					9u
#define I2C0_IC_DATA_CMD_STOP_DISABLE				0u
#define I2C0_IC_DATA_CMD_STOP_ENABLE				1u
	/* This bit controls whether a read or a write is performed. */
#define I2C0_IC_DATA_CMD_CMD					8u
#define I2C0_IC_DATA_CMD_CMD_WRITE				0u
#define I2C0_IC_DATA_CMD_CMD_READ				1u
	/* This register contains the data to be transmitted or received on the I2C bus. If you are writing to this register and want to perform a read, bits 7:0 (DAT) are ignored by the DW_apb_i2c. */
#define I2C0_IC_DATA_CMD_DAT_Msb				7u
#define I2C0_IC_DATA_CMD_DAT_Lsb				0u

	/* 0x14: Standard Speed I2C Clock SCL High Count Register */
	uint32_t volatile IC_SS_SCL_HCNT;
	/* This register must be set before any I2C bus transaction can take place to ensure proper I/O timing. */
#define I2C0_IC_SS_SCL_HCNT_IC_SS_SCL_HCNT_Msb			15u
#define I2C0_IC_SS_SCL_HCNT_IC_SS_SCL_HCNT_Lsb			0u

	/* 0x18: Standard Speed I2C Clock SCL Low Count Register */
	uint32_t volatile IC_SS_SCL_LCNT;
	/* This register must be set before any I2C bus transaction can take place to ensure proper I/O timing. */
#define I2C0_IC_SS_SCL_LCNT_IC_SS_SCL_LCNT_Msb			15u
#define I2C0_IC_SS_SCL_LCNT_IC_SS_SCL_LCNT_Lsb			0u

	/* 0x1C: Fast Mode or Fast Mode Plus I2C Clock SCL High Count Register */
	uint32_t volatile IC_FS_SCL_HCNT;
	/* This register must be set before any I2C bus transaction can take place to ensure proper I/O timing. */
#define I2C0_IC_FS_SCL_HCNT_IC_FS_SCL_HCNT_Msb			15u
#define I2C0_IC_FS_SCL_HCNT_IC_FS_SCL_HCNT_Lsb			0u

	/* 0x20: Fast Mode or Fast Mode Plus I2C Clock SCL Low Count Register */
	uint32_t volatile IC_FS_SCL_LCNT;
	/* This register must be set before any I2C bus transaction can take place to ensure proper I/O timing. */
#define I2C0_IC_FS_SCL_LCNT_IC_FS_SCL_LCNT_Msb			15u
#define I2C0_IC_FS_SCL_LCNT_IC_FS_SCL_LCNT_Lsb			0u

	/* 0x24 */
	uint8_t RESERVED1[0x2C-0x24];

	/* 0x2C: I2C Interrupt Status Register */
	uint32_t volatile IC_INTR_STAT;
	/* See IC_RAW_INTR_STAT for a detailed description of R_RESTART_DET bit. */
#define I2C0_IC_INTR_STAT_R_RESTART_DET				12u
#define I2C0_IC_INTR_STAT_R_RESTART_DET_INACTIVE		0u
#define I2C0_IC_INTR_STAT_R_RESTART_DET_ACTIVE			1u
	/* See IC_RAW_INTR_STAT for a detailed description of R_GEN_CALL bit. */
#define I2C0_IC_INTR_STAT_R_GEN_CALL				11u
#define I2C0_IC_INTR_STAT_R_GEN_CALL_INACTIVE			0u
#define I2C0_IC_INTR_STAT_R_GEN_CALL_ACTIVE			1u
	/* See IC_RAW_INTR_STAT for a detailed description of R_START_DET bit. */
#define I2C0_IC_INTR_STAT_R_START_DET				10u
#define I2C0_IC_INTR_STAT_R_START_DET_INACTIVE			0u
#define I2C0_IC_INTR_STAT_R_START_DET_ACTIVE			1u
	/* See IC_RAW_INTR_STAT for a detailed description of R_STOP_DET bit. */
#define I2C0_IC_INTR_STAT_R_STOP_DET				9u
#define I2C0_IC_INTR_STAT_R_STOP_DET_INACTIVE			0u
#define I2C0_IC_INTR_STAT_R_STOP_DET_ACTIVE			1u
	/* See IC_RAW_INTR_STAT for a detailed description of R_ACTIVITY bit. */
#define I2C0_IC_INTR_STAT_R_ACTIVITY				8u
#define I2C0_IC_INTR_STAT_R_ACTIVITY_INACTIVE			0u
#define I2C0_IC_INTR_STAT_R_ACTIVITY_ACTIVE			1u
	/* See IC_RAW_INTR_STAT for a detailed description of R_RX_DONE bit. */
#define I2C0_IC_INTR_STAT_R_RX_DONE				7u
#define I2C0_IC_INTR_STAT_R_RX_DONE_INACTIVE			0u
#define I2C0_IC_INTR_STAT_R_RX_DONE_ACTIVE			1u
	/* See IC_RAW_INTR_STAT for a detailed description of R_TX_ABRT bit. */
#define I2C0_IC_INTR_STAT_R_TX_ABRT				6u
#define I2C0_IC_INTR_STAT_R_TX_ABRT_INACTIVE			0u
#define I2C0_IC_INTR_STAT_R_TX_ABRT_ACTIVE			1u
	/* See IC_RAW_INTR_STAT for a detailed description of R_RD_REQ bit. */
#define I2C0_IC_INTR_STAT_R_RD_REQ				5u
#define I2C0_IC_INTR_STAT_R_RD_REQ_INACTIVE			0u
#define I2C0_IC_INTR_STAT_R_RD_REQ_ACTIVE			1u
	/* See IC_RAW_INTR_STAT for a detailed description of R_TX_EMPTY bit. */
#define I2C0_IC_INTR_STAT_R_TX_EMPTY				4u
#define I2C0_IC_INTR_STAT_R_TX_EMPTY_INACTIVE			0u
#define I2C0_IC_INTR_STAT_R_TX_EMPTY_ACTIVE			1u
	/* See IC_RAW_INTR_STAT for a detailed description of R_TX_OVER bit. */
#define I2C0_IC_INTR_STAT_R_TX_OVER				3u
#define I2C0_IC_INTR_STAT_R_TX_OVER_INACTIVE			0u
#define I2C0_IC_INTR_STAT_R_TX_OVER_ACTIVE			1u
	/* See IC_RAW_INTR_STAT for a detailed description of R_RX_FULL bit. */
#define I2C0_IC_INTR_STAT_R_RX_FULL				2u
#define I2C0_IC_INTR_STAT_R_RX_FULL_INACTIVE			0u
#define I2C0_IC_INTR_STAT_R_RX_FULL_ACTIVE			1u
	/* See IC_RAW_INTR_STAT for a detailed description of R_RX_OVER bit. */
#define I2C0_IC_INTR_STAT_R_RX_OVER				1u
#define I2C0_IC_INTR_STAT_R_RX_OVER_INACTIVE			0u
#define I2C0_IC_INTR_STAT_R_RX_OVER_ACTIVE			1u
	/* See IC_RAW_INTR_STAT for a detailed description of R_RX_UNDER bit. */
#define I2C0_IC_INTR_STAT_R_RX_UNDER				0u
#define I2C0_IC_INTR_STAT_R_RX_UNDER_INACTIVE			0u
#define I2C0_IC_INTR_STAT_R_RX_UNDER_ACTIVE			1u

	/* 0x30: I2C Interrupt Mask Register. */
	uint32_t volatile IC_INTR_MASK;
	/* This bit masks the R_RESTART_DET interrupt in IC_INTR_STAT register. */
#define I2C0_IC_INTR_MASK_M_RESTART_DET				12u
#define I2C0_IC_INTR_MASK_M_RESTART_DET_ENABLED			0u
#define I2C0_IC_INTR_MASK_M_RESTART_DET_DISABLED		1u
	/* This bit masks the R_GEN_CALL interrupt in IC_INTR_STAT register. */
#define I2C0_IC_INTR_MASK_M_GEN_CALL				11u
#define I2C0_IC_INTR_MASK_M_GEN_CALL_ENABLED			0u
#define I2C0_IC_INTR_MASK_M_GEN_CALL_DISABLED			1u
	/* This bit masks the R_START_DET interrupt in IC_INTR_STAT register. */
#define I2C0_IC_INTR_MASK_M_START_DET				10u
#define I2C0_IC_INTR_MASK_M_START_DET_ENABLED			0u
#define I2C0_IC_INTR_MASK_M_START_DET_DISABLED			1u
	/* This bit masks the R_STOP_DET interrupt in IC_INTR_STAT register. */
#define I2C0_IC_INTR_MASK_M_STOP_DET				9u
#define I2C0_IC_INTR_MASK_M_STOP_DET_ENABLED			0u
#define I2C0_IC_INTR_MASK_M_STOP_DET_DISABLED			1u
	/* This bit masks the R_ACTIVITY interrupt in IC_INTR_STAT register. */
#define I2C0_IC_INTR_MASK_M_ACTIVITY				8u
#define I2C0_IC_INTR_MASK_M_ACTIVITY_ENABLED			0u
#define I2C0_IC_INTR_MASK_M_ACTIVITY_DISABLED			1u
	/* This bit masks the R_RX_DONE interrupt in IC_INTR_STAT register. */
#define I2C0_IC_INTR_MASK_M_RX_DONE				7u
#define I2C0_IC_INTR_MASK_M_RX_DONE_ENABLED			0u
#define I2C0_IC_INTR_MASK_M_RX_DONE_DISABLED			1u
	/* This bit masks the R_TX_ABRT interrupt in IC_INTR_STAT register. */
#define I2C0_IC_INTR_MASK_M_TX_ABRT				6u
#define I2C0_IC_INTR_MASK_M_TX_ABRT_ENABLED			0u
#define I2C0_IC_INTR_MASK_M_TX_ABRT_DISABLED			1u
	/* This bit masks the R_RD_REQ interrupt in IC_INTR_STAT register. */
#define I2C0_IC_INTR_MASK_M_RD_REQ				5u
#define I2C0_IC_INTR_MASK_M_RD_REQ_ENABLED			0u
#define I2C0_IC_INTR_MASK_M_RD_REQ_DISABLED			1u
	/* This bit masks the R_TX_EMPTY interrupt in IC_INTR_STAT register. */
#define I2C0_IC_INTR_MASK_M_TX_EMPTY				4u
#define I2C0_IC_INTR_MASK_M_TX_EMPTY_ENABLED			0u
#define I2C0_IC_INTR_MASK_M_TX_EMPTY_DISABLED			1u
	/* This bit masks the R_TX_OVER interrupt in IC_INTR_STAT register. */
#define I2C0_IC_INTR_MASK_M_TX_OVER				3u
#define I2C0_IC_INTR_MASK_M_TX_OVER_ENABLED			0u
#define I2C0_IC_INTR_MASK_M_TX_OVER_DISABLED			1u
	/* This bit masks the R_RX_FULL interrupt in IC_INTR_STAT register. */
#define I2C0_IC_INTR_MASK_M_RX_FULL				2u
#define I2C0_IC_INTR_MASK_M_RX_FULL_ENABLED			0u
#define I2C0_IC_INTR_MASK_M_RX_FULL_DISABLED			1u
	/* This bit masks the R_RX_OVER interrupt in IC_INTR_STAT register. */
#define I2C0_IC_INTR_MASK_M_RX_OVER				1u
#define I2C0_IC_INTR_MASK_M_RX_OVER_ENABLED			0u
#define I2C0_IC_INTR_MASK_M_RX_OVER_DISABLED			1u
	/* This bit masks the R_RX_UNDER interrupt in IC_INTR_STAT register. */
#define I2C0_IC_INTR_MASK_M_RX_UNDER				0u
#define I2C0_IC_INTR_MASK_M_RX_UNDER_ENABLED			0u
#define I2C0_IC_INTR_MASK_M_RX_UNDER_DISABLED			1u

	/* 0x34: I2C Raw Interrupt Status Register */
	uint32_t volatile IC_RAW_INTR_STAT;
	/* Indicates whether a RESTART condition has occurred on the I2C interface when DW_apb_i2c is operating in Slave mode and the slave is being addressed. */
#define I2C0_IC_RAW_INTR_STAT_RESTART_DET			12u
#define I2C0_IC_RAW_INTR_STAT_RESTART_DET_INACTIVE		0u
#define I2C0_IC_RAW_INTR_STAT_RESTART_DET_ACTIVE		1u
	/* Set only when a General Call address is received and it is acknowledged. */
#define I2C0_IC_RAW_INTR_STAT_GEN_CALL				11u
#define I2C0_IC_RAW_INTR_STAT_GEN_CALL_INACTIVE			0u
#define I2C0_IC_RAW_INTR_STAT_GEN_CALL_ACTIVE			1u
	/* Indicates whether a START or RESTART condition has occurred on the I2C interface regardless of whether DW_apb_i2c is operating in slave or master mode. */
#define I2C0_IC_RAW_INTR_STAT_START_DET				10u
#define I2C0_IC_RAW_INTR_STAT_START_DET_INACTIVE		0u
#define I2C0_IC_RAW_INTR_STAT_START_DET_ACTIVE			1u
	/* Indicates whether a STOP condition has occurred on the I2C interface regardless of whether DW_apb_i2c is operating in slave or master mode. */
#define I2C0_IC_RAW_INTR_STAT_STOP_DET				9u
#define I2C0_IC_RAW_INTR_STAT_STOP_DET_INACTIVE			0u
#define I2C0_IC_RAW_INTR_STAT_STOP_DET_ACTIVE			1u
	/* This bit captures DW_apb_i2c activity and stays set until it is cleared. */
#define I2C0_IC_RAW_INTR_STAT_ACTIVITY				8u
#define I2C0_IC_RAW_INTR_STAT_ACTIVITY_INACTIVE			0u
#define I2C0_IC_RAW_INTR_STAT_ACTIVITY_ACTIVE			1u
	/* When the DW_apb_i2c is acting as a slave-transmitter, this bit is set to 1 if the master does not acknowledge a transmitted byte. */
#define I2C0_IC_RAW_INTR_STAT_RX_DONE				7u
#define I2C0_IC_RAW_INTR_STAT_RX_DONE_INACTIVE			0u
#define I2C0_IC_RAW_INTR_STAT_RX_DONE_ACTIVE			1u
	/* This bit indicates if DW_apb_i2c, as an I2C transmitter, is unable to complete the intended actions on the contents of the transmit FIFO. */
#define I2C0_IC_RAW_INTR_STAT_TX_ABRT				6u
#define I2C0_IC_RAW_INTR_STAT_TX_ABRT_INACTIVE			0u
#define I2C0_IC_RAW_INTR_STAT_TX_ABRT_ACTIVE			1u
	/* This bit is set to 1 when DW_apb_i2c is acting as a slave and another I2C master is attempting to read data from DW_apb_i2c. The DW_apb_i2c holds the I2C bus in a wait state (SCL=0) until this interrupt is serviced, which means that the slave has been addressed by a remote master that is asking for data to be transferred. */
#define I2C0_IC_RAW_INTR_STAT_RD_REQ				5u
#define I2C0_IC_RAW_INTR_STAT_RD_REQ_INACTIVE			0u
#define I2C0_IC_RAW_INTR_STAT_RD_REQ_ACTIVE			1u
	/* The behavior of the TX_EMPTY interrupt status differs based on the TX_EMPTY_CTRL selection in the IC_CON register. */
#define I2C0_IC_RAW_INTR_STAT_TX_EMPTY				4u
#define I2C0_IC_RAW_INTR_STAT_TX_EMPTY_INACTIVE			0u
#define I2C0_IC_RAW_INTR_STAT_TX_EMPTY_ACTIVE			1u
	/* Set during transmit if the transmit buffer is filled to IC_TX_BUFFER_DEPTH and the processor attempts to issue another I2C command by writing to the IC_DATA_CMD register. */
#define I2C0_IC_RAW_INTR_STAT_TX_OVER				3u
#define I2C0_IC_RAW_INTR_STAT_TX_OVER_INACTIVE			0u
#define I2C0_IC_RAW_INTR_STAT_TX_OVER_ACTIVE			1u
	/* Set when the receive buffer reaches or goes above the RX_TL threshold in the IC_RX_TL register. It is automatically cleared by hardware when buffer level goes below the threshold. If the module is disabled (IC_ENABLE[0]=0), the RX FIFO is flushed and held in reset; therefore the RX FIFO is not full. */
#define I2C0_IC_RAW_INTR_STAT_RX_FULL				2u
#define I2C0_IC_RAW_INTR_STAT_RX_FULL_INACTIVE			0u
#define I2C0_IC_RAW_INTR_STAT_RX_FULL_ACTIVE			1u
	/* Set if the receive buffer is completely filled to IC_RX_BUFFER_DEPTH and an additional byte is received from an external I2C device. The DW_apb_i2c acknowledges this, but any data bytes received after the FIFO is full are lost. If the module is disabled (IC_ENABLE[0]=0), this bit keeps its level until the master or slave state machines go into idle, and when ic_en goes to 0, this interrupt is cleared. */
#define I2C0_IC_RAW_INTR_STAT_RX_OVER				1u
#define I2C0_IC_RAW_INTR_STAT_RX_OVER_INACTIVE			0u
#define I2C0_IC_RAW_INTR_STAT_RX_OVER_ACTIVE			1u
	/* Set if the processor attempts to read the receive buffer when it is empty by reading from the IC_DATA_CMD register. If the module is disabled (IC_ENABLE[0]=0), this bit keeps its level until the master or slave state machines go into idle, and when ic_en goes to 0, this interrupt is cleared. */
#define I2C0_IC_RAW_INTR_STAT_RX_UNDER				0u
#define I2C0_IC_RAW_INTR_STAT_RX_UNDER_INACTIVE			0u
#define I2C0_IC_RAW_INTR_STAT_RX_UNDER_ACTIVE			1u

	/* 0x38: I2C Receive FIFO Threshold Register */
	uint32_t volatile IC_RX_TL;
	/* Receive FIFO Threshold Level. */
#define I2C0_IC_RX_TL_RX_TL_Msb					7u
#define I2C0_IC_RX_TL_RX_TL_Lsb					0u

	/* 0x3C: I2C Transmit FIFO Threshold Register */
	uint32_t volatile IC_TX_TL;
	/* Transmit FIFO Threshold Level. */
#define I2C0_IC_TX_TL_TX_TL_Msb					7u
#define I2C0_IC_TX_TL_TX_TL_Lsb					0u

	/* 0x40: Clear Combined and Individual Interrupt Register */
	uint32_t volatile IC_CLR_INTR;
	/* Read this register to clear the combined interrupt, all individual interrupts, and the IC_TX_ABRT_SOURCE register. */
#define I2C0_IC_CLR_INTR_CLR_INTR				0u

	/* 0x44: Clear RX_UNDER Interrupt Register */
	uint32_t volatile IC_CLR_RX_UNDER;
	/* Read this register to clear the RX_UNDER interrupt (bit 0) of the IC_RAW_INTR_STAT register. */
#define I2C0_IC_CLR_RX_UNDER_CLR_RX_UNDER			0u

	/* 0x48: Clear RX_OVER Interrupt Register */
	uint32_t volatile IC_CLR_RX_OVER;
	/* Read this register to clear the RX_OVER interrupt (bit 1) of the IC_RAW_INTR_STAT register. */
#define I2C0_IC_CLR_RX_OVER_CLR_RX_OVER				0u

	/* 0x4C: Clear TX_OVER Interrupt Register */
	uint32_t volatile IC_CLR_TX_OVER;
	/* Read this register to clear the TX_OVER interrupt (bit 3) of the IC_RAW_INTR_STAT register. */
#define I2C0_IC_CLR_TX_OVER_CLR_TX_OVER				0u

	/* 0x50: Clear RD_REQ Interrupt Register */
	uint32_t volatile IC_CLR_RD_REQ;
	/* Read this register to clear the RD_REQ interrupt (bit 5) of the IC_RAW_INTR_STAT register. */
#define I2C0_IC_CLR_RD_REQ_CLR_RD_REQ				0u

	/* 0x54: Clear TX_ABRT Interrupt Register */
	uint32_t volatile IC_CLR_TX_ABRT;
	/* Read this register to clear the TX_ABRT interrupt (bit 6) of the IC_RAW_INTR_STAT register, and the IC_TX_ABRT_SOURCE register. */
#define I2C0_IC_CLR_TX_ABRT_CLR_TX_ABRT				0u

	/* 0x58: Clear RX_DONE Interrupt Register */
	uint32_t volatile IC_CLR_RX_DONE;
	/* Read this register to clear the RX_DONE interrupt (bit 7) of the IC_RAW_INTR_STAT register. */
#define I2C0_IC_CLR_RX_DONE_CLR_RX_DONE				0u

	/* 0x5C: Clear ACTIVITY Interrupt Register */
	uint32_t volatile IC_CLR_ACTIVITY;
	/* Reading this register clears the ACTIVITY interrupt if the I2C is not active anymore. If the I2C module is still active on the bus, the ACTIVITY interrupt bit continues to be set. It is automatically cleared by hardware if the module is disabled and if there is no further activity on the bus. The value read from this register to get status of the ACTIVITY interrupt (bit 8) of the IC_RAW_INTR_STAT register. */
#define I2C0_IC_CLR_ACTIVITY_CLR_ACTIVITY			0u

	/* 0x60: Clear STOP_DET Interrupt Register */
	uint32_t volatile IC_CLR_STOP_DET;
	/* Read this register to clear the STOP_DET interrupt (bit 9) of the IC_RAW_INTR_STAT register. */
#define I2C0_IC_CLR_STOP_DET_CLR_STOP_DET			0u

	/* 0x64: Clear START_DET Interrupt Register */
	uint32_t volatile IC_CLR_START_DET;
	/* Read this register to clear the START_DET interrupt (bit 10) of the IC_RAW_INTR_STAT register. */
#define I2C0_IC_CLR_START_DET_CLR_START_DET			0u

	/* 0x68: Clear GEN_CALL Interrupt Register */
	uint32_t volatile IC_CLR_GEN_CALL;
	/* Read this register to clear the GEN_CALL interrupt (bit 11) of IC_RAW_INTR_STAT register. */
#define I2C0_IC_CLR_GEN_CALL_CLR_GEN_CALL			0u

	/* 0x6C: I2C Enable Register */
	uint32_t volatile IC_ENABLE;
	/* In Master mode: - 1'b1: Blocks the transmission of data on I2C bus even if Tx FIFO has data to transmit. - 1'b0: The transmission of data starts on I2C bus automatically, as soon as the first data is available in the Tx FIFO. Note: To block the execution of Master commands, set the TX_CMD_BLOCK bit only when Tx FIFO is empty (IC_STATUS[2]==1) and Master is in Idle state (IC_STATUS[5] == 0). */
#define I2C0_IC_ENABLE_TX_CMD_BLOCK				2u
#define I2C0_IC_ENABLE_TX_CMD_BLOCK_NOT_BLOCKED			0u
#define I2C0_IC_ENABLE_TX_CMD_BLOCK_BLOCKED			1u
	/* When set, the controller initiates the transfer abort. */
#define I2C0_IC_ENABLE_ABORT					1u
#define I2C0_IC_ENABLE_ABORT_DISABLE				0u
#define I2C0_IC_ENABLE_ABORT_ENABLED				1u
	/* Controls whether the DW_apb_i2c is enabled. - 0: Disables DW_apb_i2c (TX and RX FIFOs are held in an erased state) - 1: Enables DW_apb_i2c Software can disable DW_apb_i2c while it is active. */
#define I2C0_IC_ENABLE_ENABLE					0u
#define I2C0_IC_ENABLE_ENABLE_DISABLED				0u
#define I2C0_IC_ENABLE_ENABLE_ENABLED				1u

	/* 0x70: I2C Status Register */
	uint32_t volatile IC_STATUS;
	/* Slave FSM Activity Status. When the Slave Finite State Machine (FSM) is not in the IDLE state, this bit is set. */
#define I2C0_IC_STATUS_SLV_ACTIVITY				6u
#define I2C0_IC_STATUS_SLV_ACTIVITY_IDLE			0u
#define I2C0_IC_STATUS_SLV_ACTIVITY_ACTIVE			1u
	/* Master FSM Activity Status. When the Master Finite State Machine (FSM) is not in the IDLE state, this bit is set. */
#define I2C0_IC_STATUS_MST_ACTIVITY				5u
#define I2C0_IC_STATUS_MST_ACTIVITY_IDLE			0u
#define I2C0_IC_STATUS_MST_ACTIVITY_ACTIVE			1u
	/* Receive FIFO Completely Full. */
#define I2C0_IC_STATUS_RFF					4u
#define I2C0_IC_STATUS_RFF_NOT_FULL				0u
#define I2C0_IC_STATUS_RFF_FULL					1u
	/* Receive FIFO Not Empty. */
#define I2C0_IC_STATUS_RFNE					3u
#define I2C0_IC_STATUS_RFNE_EMPTY				0u
#define I2C0_IC_STATUS_RFNE_NOT_EMPTY				1u
	/* Transmit FIFO Completely Empty. */
#define I2C0_IC_STATUS_TFE					2u
#define I2C0_IC_STATUS_TFE_NON_EMPTY				0u
#define I2C0_IC_STATUS_TFE_EMPTY				1u
	/* Transmit FIFO Not Full. */
#define I2C0_IC_STATUS_TFNF					1u
#define I2C0_IC_STATUS_TFNF_FULL				0u
#define I2C0_IC_STATUS_TFNF_NOT_FULL				1u
	/* I2C Activity Status. */
#define I2C0_IC_STATUS_ACTIVITY					0u
#define I2C0_IC_STATUS_ACTIVITY_INACTIVE			0u
#define I2C0_IC_STATUS_ACTIVITY_ACTIVE				1u

	/* 0x74: I2C Transmit FIFO Level Register This register contains the number of valid data entries in the transmit FIFO buffer. */
	uint32_t volatile IC_TXFLR;
	/* Transmit FIFO Level. */
#define I2C0_IC_TXFLR_TXFLR_Msb					4u
#define I2C0_IC_TXFLR_TXFLR_Lsb					0u

	/* 0x78: I2C Receive FIFO Level Register This register contains the number of valid data entries in the receive FIFO buffer. */
	uint32_t volatile IC_RXFLR;
	/* Receive FIFO Level. */
#define I2C0_IC_RXFLR_RXFLR_Msb					4u
#define I2C0_IC_RXFLR_RXFLR_Lsb					0u

	/* 0x7C: I2C SDA Hold Time Length Register */
	uint32_t volatile IC_SDA_HOLD;
	/* Sets the required SDA hold time in units of ic_clk period, when DW_apb_i2c acts as a receiver. */
#define I2C0_IC_SDA_HOLD_IC_SDA_RX_HOLD_Msb			23u
#define I2C0_IC_SDA_HOLD_IC_SDA_RX_HOLD_Lsb			16u
	/* Sets the required SDA hold time in units of ic_clk period, when DW_apb_i2c acts as a transmitter. */
#define I2C0_IC_SDA_HOLD_IC_SDA_TX_HOLD_Msb			15u
#define I2C0_IC_SDA_HOLD_IC_SDA_TX_HOLD_Lsb			0u

	/* 0x80: I2C Transmit Abort Source Register */
	uint32_t volatile IC_TX_ABRT_SOURCE;
	/* This field indicates the number of Tx FIFO Data Commands which are flushed due to TX_ABRT interrupt. */
#define I2C0_IC_TX_ABRT_SOURCE_TX_FLUSH_CNT_Msb			31u
#define I2C0_IC_TX_ABRT_SOURCE_TX_FLUSH_CNT_Lsb			23u
	/* This is a master-mode-only bit. Master has detected the transfer abort (IC_ENABLE[1]) */
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_USER_ABRT			16u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_USER_ABRT_ABRT_USER_ABRT_VOID	0u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_USER_ABRT_ABRT_USER_ABRT_GENERATED	1u
	/* 1: When the processor side responds to a slave mode request for data to be transmitted to a remote master and user writes a 1 in CMD (bit 8) of IC_DATA_CMD register. */
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_SLVRD_INTX			15u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_ABRT_SLVRD_INTX_VOID	0u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_ABRT_SLVRD_INTX_GENERATED	1u
	/* This field indicates that a Slave has lost the bus while transmitting data to a remote master. */
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST			14u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_ABRT_SLV_ARBLOST_VOID	0u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_ABRT_SLV_ARBLOST_GENERATED	1u
	/* This field specifies that the Slave has received a read command and some data exists in the TX FIFO, so the slave issues a TX_ABRT interrupt to flush old data in TX FIFO. */
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO		13u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_ABRT_SLVFLUSH_TXFIFO_VOID	0u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_ABRT_SLVFLUSH_TXFIFO_GENERATED	1u
	/* This field specifies that the Master has lost arbitration, or if IC_TX_ABRT_SOURCE[14] is also set, then the slave transmitter has lost arbitration. */
#define I2C0_IC_TX_ABRT_SOURCE_ARB_LOST				12u
#define I2C0_IC_TX_ABRT_SOURCE_ARB_LOST_ABRT_LOST_VOID		0u
#define I2C0_IC_TX_ABRT_SOURCE_ARB_LOST_ABRT_LOST_GENERATED	1u
	/* This field indicates that the User tries to initiate a Master operation with the Master mode disabled. */
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_MASTER_DIS			11u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_MASTER_DIS_ABRT_MASTER_DIS_VOID	0u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_MASTER_DIS_ABRT_MASTER_DIS_GENERATED	1u
	/* This field indicates that the restart is disabled (IC_RESTART_EN bit (IC_CON[5]) =0) and the master sends a read command in 10-bit addressing mode. */
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT		10u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_ABRT_10B_RD_VOID	0u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_ABRT_10B_RD_GENERATED	1u
	/* To clear Bit 9, the source of the ABRT_SBYTE_NORSTRT must be fixed first; restart must be enabled (IC_CON[5]=1), the SPECIAL bit must be cleared (IC_TAR[11]), or the GC_OR_START bit must be cleared (IC_TAR[10]). Once the source of the ABRT_SBYTE_NORSTRT is fixed, then this bit can be cleared in the same manner as other bits in this register. If the source of the ABRT_SBYTE_NORSTRT is not fixed before attempting to clear this bit, bit 9 clears for one cycle and then gets reasserted. When this field is set to 1, the restart is disabled (IC_RESTART_EN bit (IC_CON[5]) =0) and the user is trying to send a START Byte. */
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT		9u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_ABRT_SBYTE_NORSTRT_VOID	0u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_ABRT_SBYTE_NORSTRT_GENERATED	1u
	/* This field indicates that the restart is disabled (IC_RESTART_EN bit (IC_CON[5]) =0) and the user is trying to use the master to transfer data in High Speed mode. */
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_HS_NORSTRT			8u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_ABRT_HS_NORSTRT_VOID	0u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_ABRT_HS_NORSTRT_GENERATED	1u
	/* This field indicates that the Master has sent a START Byte and the START Byte was acknowledged (wrong behavior). */
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET		7u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_ABRT_SBYTE_ACKDET_VOID	0u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_ABRT_SBYTE_ACKDET_GENERATED	1u
	/* This field indicates that the Master is in High Speed mode and the High Speed Master code was acknowledged (wrong behavior). */
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_HS_ACKDET			6u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_HS_ACKDET_ABRT_HS_ACK_VOID	0u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_HS_ACKDET_ABRT_HS_ACK_GENERATED	1u
	/* This field indicates that DW_apb_i2c in the master mode has sent a General Call but the user programmed the byte following the General Call to be a read from the bus (IC_DATA_CMD[9] is set to 1). */
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_GCALL_READ			5u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_GCALL_READ_ABRT_GCALL_READ_VOID	0u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_GCALL_READ_ABRT_GCALL_READ_GENERATED	1u
	/* This field indicates that DW_apb_i2c in master mode has sent a General Call and no slave on the bus acknowledged the General Call. */
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_GCALL_NOACK			4u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_ABRT_GCALL_NOACK_VOID	0u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_ABRT_GCALL_NOACK_GENERATED	1u
	/* This field indicates the master-mode only bit. When the master receives an acknowledgement for the address, but when it sends data byte(s) following the address, it did not receive an acknowledge from the remote slave(s). */
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK		3u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_ABRT_TXDATA_NOACK_VOID	0u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_ABRT_TXDATA_NOACK_GENERATED	1u
	/* This field indicates that the Master is in 10-bit address mode and that the second address byte of the 10-bit address was not acknowledged by any slave. */
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK		2u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_INACTIVE	0u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_ACTIVE	1u
	/* This field indicates that the Master is in 10-bit address mode and the first 10-bit address byte was not acknowledged by any slave. */
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK		1u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_INACTIVE	0u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_ACTIVE	1u
	/* This field indicates that the Master is in 7-bit addressing mode and the address sent was not acknowledged by any slave. */
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK		0u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_INACTIVE	0u
#define I2C0_IC_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_ACTIVE	1u

	/* 0x84: Generate Slave Data NACK Register */
	uint32_t volatile IC_SLV_DATA_NACK_ONLY;
	/* Generate NACK. */
#define I2C0_IC_SLV_DATA_NACK_ONLY_NACK				0u
#define I2C0_IC_SLV_DATA_NACK_ONLY_NACK_DISABLED		0u
#define I2C0_IC_SLV_DATA_NACK_ONLY_NACK_ENABLED			1u

	/* 0x88: DMA Control Register */
	uint32_t volatile IC_DMA_CR;
	/* Transmit DMA Enable. */
#define I2C0_IC_DMA_CR_TDMAE					1u
#define I2C0_IC_DMA_CR_TDMAE_DISABLED				0u
#define I2C0_IC_DMA_CR_TDMAE_ENABLED				1u
	/* Receive DMA Enable. */
#define I2C0_IC_DMA_CR_RDMAE					0u
#define I2C0_IC_DMA_CR_RDMAE_DISABLED				0u
#define I2C0_IC_DMA_CR_RDMAE_ENABLED				1u

	/* 0x8C: DMA Transmit Data Level Register */
	uint32_t volatile IC_DMA_TDLR;
	/* Transmit Data Level. */
#define I2C0_IC_DMA_TDLR_DMATDL_Msb				3u
#define I2C0_IC_DMA_TDLR_DMATDL_Lsb				0u

	/* 0x90: I2C Receive Data Level Register */
	uint32_t volatile IC_DMA_RDLR;
	/* Receive Data Level. */
#define I2C0_IC_DMA_RDLR_DMARDL_Msb				3u
#define I2C0_IC_DMA_RDLR_DMARDL_Lsb				0u

	/* 0x94: I2C SDA Setup Register */
	uint32_t volatile IC_SDA_SETUP;
	/* SDA Setup. */
#define I2C0_IC_SDA_SETUP_SDA_SETUP_Msb				7u
#define I2C0_IC_SDA_SETUP_SDA_SETUP_Lsb				0u

	/* 0x98: I2C ACK General Call Register */
	uint32_t volatile IC_ACK_GENERAL_CALL;
	/* ACK General Call. When set to 1, DW_apb_i2c responds with a ACK (by asserting ic_data_oe) when it receives a General Call. Otherwise, DW_apb_i2c responds with a NACK (by negating ic_data_oe). */
#define I2C0_IC_ACK_GENERAL_CALL_ACK_GEN_CALL			0u
#define I2C0_IC_ACK_GENERAL_CALL_ACK_GEN_CALL_DISABLED		0u
#define I2C0_IC_ACK_GENERAL_CALL_ACK_GEN_CALL_ENABLED		1u

	/* 0x9C: I2C Enable Status Register */
	uint32_t volatile IC_ENABLE_STATUS;
	/* Slave Received Data Lost. This bit indicates if a Slave-Receiver operation has been aborted with at least one data byte received from an I2C transfer due to the setting bit 0 of IC_ENABLE from 1 to 0. When read as 1, DW_apb_i2c is deemed to have been actively engaged in an aborted I2C transfer (with matching address) and the data phase of the I2C transfer has been entered, even though a data byte has been responded with a NACK. */
#define I2C0_IC_ENABLE_STATUS_SLV_RX_DATA_LOST			2u
#define I2C0_IC_ENABLE_STATUS_SLV_RX_DATA_LOST_INACTIVE		0u
#define I2C0_IC_ENABLE_STATUS_SLV_RX_DATA_LOST_ACTIVE		1u
	/* Slave Disabled While Busy (Transmit, Receive). */
#define I2C0_IC_ENABLE_STATUS_SLV_DISABLED_WHILE_BUSY		1u
#define I2C0_IC_ENABLE_STATUS_SLV_DISABLED_WHILE_BUSY_INACTIVE	0u
#define I2C0_IC_ENABLE_STATUS_SLV_DISABLED_WHILE_BUSY_ACTIVE	1u
	/* ic_en Status. This bit always reflects the value driven on the output port ic_en. - When read as 1, DW_apb_i2c is deemed to be in an enabled state. - When read as 0, DW_apb_i2c is deemed completely inactive. Note:  The CPU can safely read this bit anytime. When this bit is read as 0, the CPU can safely read SLV_RX_DATA_LOST (bit 2) and SLV_DISABLED_WHILE_BUSY (bit 1). */
#define I2C0_IC_ENABLE_STATUS_IC_EN				0u
#define I2C0_IC_ENABLE_STATUS_IC_EN_DISABLED			0u
#define I2C0_IC_ENABLE_STATUS_IC_EN_ENABLED			1u

	/* 0xA0: I2C SS, FS or FM+ spike suppression limit */
	uint32_t volatile IC_FS_SPKLEN;
	/* This register must be set before any I2C bus transaction can take place to ensure stable operation. */
#define I2C0_IC_FS_SPKLEN_IC_FS_SPKLEN_Msb			7u
#define I2C0_IC_FS_SPKLEN_IC_FS_SPKLEN_Lsb			0u

	/* 0xA4 */
	uint8_t RESERVED2[0xA8-0xA4];

	/* 0xA8: Clear RESTART_DET Interrupt Register */
	uint32_t volatile IC_CLR_RESTART_DET;
	/* Read this register to clear the RESTART_DET interrupt (bit 12) of IC_RAW_INTR_STAT register. */
#define I2C0_IC_CLR_RESTART_DET_CLR_RESTART_DET			0u

	/* 0xAC */
	uint8_t RESERVED3[0xF4-0xAC];

	/* 0xF4: Component Parameter Register 1 */
	uint32_t volatile IC_COMP_PARAM_1;
	/* TX Buffer Depth = 16 */
#define I2C0_IC_COMP_PARAM_1_TX_BUFFER_DEPTH_Msb		23u
#define I2C0_IC_COMP_PARAM_1_TX_BUFFER_DEPTH_Lsb		16u
	/* RX Buffer Depth = 16 */
#define I2C0_IC_COMP_PARAM_1_RX_BUFFER_DEPTH_Msb		15u
#define I2C0_IC_COMP_PARAM_1_RX_BUFFER_DEPTH_Lsb		8u
	/* Encoded parameters not visible */
#define I2C0_IC_COMP_PARAM_1_ADD_ENCODED_PARAMS			7u
	/* DMA handshaking signals are enabled */
#define I2C0_IC_COMP_PARAM_1_HAS_DMA				6u
	/* COMBINED Interrupt outputs */
#define I2C0_IC_COMP_PARAM_1_INTR_IO				5u
	/* Programmable count values for each mode. */
#define I2C0_IC_COMP_PARAM_1_HC_COUNT_VALUES			4u
	/* MAX SPEED MODE = FAST MODE */
#define I2C0_IC_COMP_PARAM_1_MAX_SPEED_MODE_Msb			3u
#define I2C0_IC_COMP_PARAM_1_MAX_SPEED_MODE_Lsb			2u
	/* APB data bus width is 32 bits */
#define I2C0_IC_COMP_PARAM_1_APB_DATA_WIDTH_Msb			1u
#define I2C0_IC_COMP_PARAM_1_APB_DATA_WIDTH_Lsb			0u

	/* 0xF8: I2C Component Version Register */
	uint32_t volatile IC_COMP_VERSION;
	/*  */
#define I2C0_IC_COMP_VERSION_IC_COMP_VERSION_Msb		31u
#define I2C0_IC_COMP_VERSION_IC_COMP_VERSION_Lsb		0u

	/* 0xFC: I2C Component Type Register */
	uint32_t volatile IC_COMP_TYPE;
	/* Designware Component Type number = 0x44_57_01_40. */
#define I2C0_IC_COMP_TYPE_IC_COMP_TYPE_Msb			31u
#define I2C0_IC_COMP_TYPE_IC_COMP_TYPE_Lsb			0u

};


#define ADC ((struct sdk_adc *)0x4004C000)

struct sdk_adc {

	/* 0x00: ADC Control and Status */
	uint32_t volatile CS;
	/* Round-robin sampling. */
#define ADC_CS_RROBIN_Msb					20u
#define ADC_CS_RROBIN_Lsb					16u
	/* Select analog mux input. */
#define ADC_CS_AINSEL_Msb					14u
#define ADC_CS_AINSEL_Lsb					12u
	/* Some past ADC conversion encountered an error. */
#define ADC_CS_ERR_STICKY					10u
	/* The most recent ADC conversion encountered an error; result is undefined or noisy. */
#define ADC_CS_ERR						9u
	/* 1 if the ADC is ready to start a new conversion. */
#define ADC_CS_READY						8u
	/* Continuously perform conversions whilst this bit is 1. */
#define ADC_CS_START_MANY					3u
	/* Start a single conversion. */
#define ADC_CS_START_ONCE					2u
	/* Power on temperature sensor. */
#define ADC_CS_TS_EN						1u
	/* Power on ADC and enable its clock. */
#define ADC_CS_EN						0u

	/* 0x04: Result of most recent ADC conversion */
	uint32_t volatile RESULT;
	/*  */
#define ADC_RESULT_RESULT_Msb					11u
#define ADC_RESULT_RESULT_Lsb					0u

	/* 0x08: FIFO control and status */
	uint32_t volatile FCS;
	/* DREQ/IRQ asserted when level >= threshold */
#define ADC_FCS_THRESH_Msb					27u
#define ADC_FCS_THRESH_Lsb					24u
	/* The number of conversion results currently waiting in the FIFO */
#define ADC_FCS_LEVEL_Msb					19u
#define ADC_FCS_LEVEL_Lsb					16u
	/* 1 if the FIFO has been overflowed. */
#define ADC_FCS_OVER						11u
	/* 1 if the FIFO has been underflowed. */
#define ADC_FCS_UNDER						10u
	/*  */
#define ADC_FCS_FULL						9u
	/*  */
#define ADC_FCS_EMPTY						8u
	/* If 1: assert DMA requests when FIFO contains data */
#define ADC_FCS_DREQ_EN						3u
	/* If 1: conversion error bit appears in the FIFO alongside the result */
#define ADC_FCS_ERR						2u
	/* If 1: FIFO results are right-shifted to be one byte in size. */
#define ADC_FCS_SHIFT						1u
	/* If 1: write result to the FIFO after each conversion. */
#define ADC_FCS_EN						0u

	/* 0x0C: Conversion result FIFO */
	uint32_t volatile FIFO;
	/* 1 if this particular sample experienced a conversion error. */
#define ADC_FIFO_ERR						15u
	/*  */
#define ADC_FIFO_VAL_Msb					11u
#define ADC_FIFO_VAL_Lsb					0u

	/* 0x10: Clock divider. */
	uint32_t volatile DIV;
	/* Integer part of clock divisor. */
#define ADC_DIV_INT_Msb						23u
#define ADC_DIV_INT_Lsb						8u
	/* Fractional part of clock divisor. */
#define ADC_DIV_FRAC_Msb					7u
#define ADC_DIV_FRAC_Lsb					0u

	/* 0x14: Raw Interrupts */
	uint32_t volatile INTR;
	/* Triggered when the sample FIFO reaches a certain level. */
#define ADC_INTR_FIFO						0u

	/* 0x18: Interrupt Enable */
	uint32_t volatile INTE;
	/* Triggered when the sample FIFO reaches a certain level. */
#define ADC_INTE_FIFO						0u

	/* 0x1C: Interrupt Force */
	uint32_t volatile INTF;
	/* Triggered when the sample FIFO reaches a certain level. */
#define ADC_INTF_FIFO						0u

	/* 0x20: Interrupt status after masking & forcing */
	uint32_t volatile INTS;
	/* Triggered when the sample FIFO reaches a certain level. */
#define ADC_INTS_FIFO						0u

};


#define PWM ((struct sdk_pwm *)0x40050000)

struct sdk_pwm {

	/* 0x00: Control and status register */
	uint32_t volatile CH0_CSR;
	/* Advance the phase of the counter by 1 count, while it is running. */
#define PWM_CH0_CSR_PH_ADV					7u
	/* Retard the phase of the counter by 1 count, while it is running. */
#define PWM_CH0_CSR_PH_RET					6u
	/*  */
#define PWM_CH0_CSR_DIVMODE_Msb					5u
#define PWM_CH0_CSR_DIVMODE_Lsb					4u
#define PWM_CH0_CSR_DIVMODE_DIV					0u
#define PWM_CH0_CSR_DIVMODE_LEVEL				1u
#define PWM_CH0_CSR_DIVMODE_RISE				2u
#define PWM_CH0_CSR_DIVMODE_FALL				3u
	/* Invert output B */
#define PWM_CH0_CSR_B_INV					3u
	/* Invert output A */
#define PWM_CH0_CSR_A_INV					2u
	/* 1: Enable phase-correct modulation. */
#define PWM_CH0_CSR_PH_CORRECT					1u
	/* Enable the PWM channel. */
#define PWM_CH0_CSR_EN						0u

	/* 0x04: INT and FRAC form a fixed-point fractional number. */
	uint32_t volatile CH0_DIV;
	/*  */
#define PWM_CH0_DIV_INT_Msb					11u
#define PWM_CH0_DIV_INT_Lsb					4u
	/*  */
#define PWM_CH0_DIV_FRAC_Msb					3u
#define PWM_CH0_DIV_FRAC_Lsb					0u

	/* 0x08: Direct access to the PWM counter */
	uint32_t volatile CH0_CTR;
	/*  */
#define PWM_CH0_CTR_CH0_CTR_Msb					15u
#define PWM_CH0_CTR_CH0_CTR_Lsb					0u

	/* 0x0C: Counter compare values */
	uint32_t volatile CH0_CC;
	/*  */
#define PWM_CH0_CC_B_Msb					31u
#define PWM_CH0_CC_B_Lsb					16u
	/*  */
#define PWM_CH0_CC_A_Msb					15u
#define PWM_CH0_CC_A_Lsb					0u

	/* 0x10: Counter wrap value */
	uint32_t volatile CH0_TOP;
	/*  */
#define PWM_CH0_TOP_CH0_TOP_Msb					15u
#define PWM_CH0_TOP_CH0_TOP_Lsb					0u

	/* 0x14: Control and status register */
	uint32_t volatile CH1_CSR;
	/* Advance the phase of the counter by 1 count, while it is running. */
#define PWM_CH1_CSR_PH_ADV					7u
	/* Retard the phase of the counter by 1 count, while it is running. */
#define PWM_CH1_CSR_PH_RET					6u
	/*  */
#define PWM_CH1_CSR_DIVMODE_Msb					5u
#define PWM_CH1_CSR_DIVMODE_Lsb					4u
#define PWM_CH1_CSR_DIVMODE_DIV					0u
#define PWM_CH1_CSR_DIVMODE_LEVEL				1u
#define PWM_CH1_CSR_DIVMODE_RISE				2u
#define PWM_CH1_CSR_DIVMODE_FALL				3u
	/* Invert output B */
#define PWM_CH1_CSR_B_INV					3u
	/* Invert output A */
#define PWM_CH1_CSR_A_INV					2u
	/* 1: Enable phase-correct modulation. */
#define PWM_CH1_CSR_PH_CORRECT					1u
	/* Enable the PWM channel. */
#define PWM_CH1_CSR_EN						0u

	/* 0x18: INT and FRAC form a fixed-point fractional number. */
	uint32_t volatile CH1_DIV;
	/*  */
#define PWM_CH1_DIV_INT_Msb					11u
#define PWM_CH1_DIV_INT_Lsb					4u
	/*  */
#define PWM_CH1_DIV_FRAC_Msb					3u
#define PWM_CH1_DIV_FRAC_Lsb					0u

	/* 0x1C: Direct access to the PWM counter */
	uint32_t volatile CH1_CTR;
	/*  */
#define PWM_CH1_CTR_CH1_CTR_Msb					15u
#define PWM_CH1_CTR_CH1_CTR_Lsb					0u

	/* 0x20: Counter compare values */
	uint32_t volatile CH1_CC;
	/*  */
#define PWM_CH1_CC_B_Msb					31u
#define PWM_CH1_CC_B_Lsb					16u
	/*  */
#define PWM_CH1_CC_A_Msb					15u
#define PWM_CH1_CC_A_Lsb					0u

	/* 0x24: Counter wrap value */
	uint32_t volatile CH1_TOP;
	/*  */
#define PWM_CH1_TOP_CH1_TOP_Msb					15u
#define PWM_CH1_TOP_CH1_TOP_Lsb					0u

	/* 0x28: Control and status register */
	uint32_t volatile CH2_CSR;
	/* Advance the phase of the counter by 1 count, while it is running. */
#define PWM_CH2_CSR_PH_ADV					7u
	/* Retard the phase of the counter by 1 count, while it is running. */
#define PWM_CH2_CSR_PH_RET					6u
	/*  */
#define PWM_CH2_CSR_DIVMODE_Msb					5u
#define PWM_CH2_CSR_DIVMODE_Lsb					4u
#define PWM_CH2_CSR_DIVMODE_DIV					0u
#define PWM_CH2_CSR_DIVMODE_LEVEL				1u
#define PWM_CH2_CSR_DIVMODE_RISE				2u
#define PWM_CH2_CSR_DIVMODE_FALL				3u
	/* Invert output B */
#define PWM_CH2_CSR_B_INV					3u
	/* Invert output A */
#define PWM_CH2_CSR_A_INV					2u
	/* 1: Enable phase-correct modulation. */
#define PWM_CH2_CSR_PH_CORRECT					1u
	/* Enable the PWM channel. */
#define PWM_CH2_CSR_EN						0u

	/* 0x2C: INT and FRAC form a fixed-point fractional number. */
	uint32_t volatile CH2_DIV;
	/*  */
#define PWM_CH2_DIV_INT_Msb					11u
#define PWM_CH2_DIV_INT_Lsb					4u
	/*  */
#define PWM_CH2_DIV_FRAC_Msb					3u
#define PWM_CH2_DIV_FRAC_Lsb					0u

	/* 0x30: Direct access to the PWM counter */
	uint32_t volatile CH2_CTR;
	/*  */
#define PWM_CH2_CTR_CH2_CTR_Msb					15u
#define PWM_CH2_CTR_CH2_CTR_Lsb					0u

	/* 0x34: Counter compare values */
	uint32_t volatile CH2_CC;
	/*  */
#define PWM_CH2_CC_B_Msb					31u
#define PWM_CH2_CC_B_Lsb					16u
	/*  */
#define PWM_CH2_CC_A_Msb					15u
#define PWM_CH2_CC_A_Lsb					0u

	/* 0x38: Counter wrap value */
	uint32_t volatile CH2_TOP;
	/*  */
#define PWM_CH2_TOP_CH2_TOP_Msb					15u
#define PWM_CH2_TOP_CH2_TOP_Lsb					0u

	/* 0x3C: Control and status register */
	uint32_t volatile CH3_CSR;
	/* Advance the phase of the counter by 1 count, while it is running. */
#define PWM_CH3_CSR_PH_ADV					7u
	/* Retard the phase of the counter by 1 count, while it is running. */
#define PWM_CH3_CSR_PH_RET					6u
	/*  */
#define PWM_CH3_CSR_DIVMODE_Msb					5u
#define PWM_CH3_CSR_DIVMODE_Lsb					4u
#define PWM_CH3_CSR_DIVMODE_DIV					0u
#define PWM_CH3_CSR_DIVMODE_LEVEL				1u
#define PWM_CH3_CSR_DIVMODE_RISE				2u
#define PWM_CH3_CSR_DIVMODE_FALL				3u
	/* Invert output B */
#define PWM_CH3_CSR_B_INV					3u
	/* Invert output A */
#define PWM_CH3_CSR_A_INV					2u
	/* 1: Enable phase-correct modulation. */
#define PWM_CH3_CSR_PH_CORRECT					1u
	/* Enable the PWM channel. */
#define PWM_CH3_CSR_EN						0u

	/* 0x40: INT and FRAC form a fixed-point fractional number. */
	uint32_t volatile CH3_DIV;
	/*  */
#define PWM_CH3_DIV_INT_Msb					11u
#define PWM_CH3_DIV_INT_Lsb					4u
	/*  */
#define PWM_CH3_DIV_FRAC_Msb					3u
#define PWM_CH3_DIV_FRAC_Lsb					0u

	/* 0x44: Direct access to the PWM counter */
	uint32_t volatile CH3_CTR;
	/*  */
#define PWM_CH3_CTR_CH3_CTR_Msb					15u
#define PWM_CH3_CTR_CH3_CTR_Lsb					0u

	/* 0x48: Counter compare values */
	uint32_t volatile CH3_CC;
	/*  */
#define PWM_CH3_CC_B_Msb					31u
#define PWM_CH3_CC_B_Lsb					16u
	/*  */
#define PWM_CH3_CC_A_Msb					15u
#define PWM_CH3_CC_A_Lsb					0u

	/* 0x4C: Counter wrap value */
	uint32_t volatile CH3_TOP;
	/*  */
#define PWM_CH3_TOP_CH3_TOP_Msb					15u
#define PWM_CH3_TOP_CH3_TOP_Lsb					0u

	/* 0x50: Control and status register */
	uint32_t volatile CH4_CSR;
	/* Advance the phase of the counter by 1 count, while it is running. */
#define PWM_CH4_CSR_PH_ADV					7u
	/* Retard the phase of the counter by 1 count, while it is running. */
#define PWM_CH4_CSR_PH_RET					6u
	/*  */
#define PWM_CH4_CSR_DIVMODE_Msb					5u
#define PWM_CH4_CSR_DIVMODE_Lsb					4u
#define PWM_CH4_CSR_DIVMODE_DIV					0u
#define PWM_CH4_CSR_DIVMODE_LEVEL				1u
#define PWM_CH4_CSR_DIVMODE_RISE				2u
#define PWM_CH4_CSR_DIVMODE_FALL				3u
	/* Invert output B */
#define PWM_CH4_CSR_B_INV					3u
	/* Invert output A */
#define PWM_CH4_CSR_A_INV					2u
	/* 1: Enable phase-correct modulation. */
#define PWM_CH4_CSR_PH_CORRECT					1u
	/* Enable the PWM channel. */
#define PWM_CH4_CSR_EN						0u

	/* 0x54: INT and FRAC form a fixed-point fractional number. */
	uint32_t volatile CH4_DIV;
	/*  */
#define PWM_CH4_DIV_INT_Msb					11u
#define PWM_CH4_DIV_INT_Lsb					4u
	/*  */
#define PWM_CH4_DIV_FRAC_Msb					3u
#define PWM_CH4_DIV_FRAC_Lsb					0u

	/* 0x58: Direct access to the PWM counter */
	uint32_t volatile CH4_CTR;
	/*  */
#define PWM_CH4_CTR_CH4_CTR_Msb					15u
#define PWM_CH4_CTR_CH4_CTR_Lsb					0u

	/* 0x5C: Counter compare values */
	uint32_t volatile CH4_CC;
	/*  */
#define PWM_CH4_CC_B_Msb					31u
#define PWM_CH4_CC_B_Lsb					16u
	/*  */
#define PWM_CH4_CC_A_Msb					15u
#define PWM_CH4_CC_A_Lsb					0u

	/* 0x60: Counter wrap value */
	uint32_t volatile CH4_TOP;
	/*  */
#define PWM_CH4_TOP_CH4_TOP_Msb					15u
#define PWM_CH4_TOP_CH4_TOP_Lsb					0u

	/* 0x64: Control and status register */
	uint32_t volatile CH5_CSR;
	/* Advance the phase of the counter by 1 count, while it is running. */
#define PWM_CH5_CSR_PH_ADV					7u
	/* Retard the phase of the counter by 1 count, while it is running. */
#define PWM_CH5_CSR_PH_RET					6u
	/*  */
#define PWM_CH5_CSR_DIVMODE_Msb					5u
#define PWM_CH5_CSR_DIVMODE_Lsb					4u
#define PWM_CH5_CSR_DIVMODE_DIV					0u
#define PWM_CH5_CSR_DIVMODE_LEVEL				1u
#define PWM_CH5_CSR_DIVMODE_RISE				2u
#define PWM_CH5_CSR_DIVMODE_FALL				3u
	/* Invert output B */
#define PWM_CH5_CSR_B_INV					3u
	/* Invert output A */
#define PWM_CH5_CSR_A_INV					2u
	/* 1: Enable phase-correct modulation. */
#define PWM_CH5_CSR_PH_CORRECT					1u
	/* Enable the PWM channel. */
#define PWM_CH5_CSR_EN						0u

	/* 0x68: INT and FRAC form a fixed-point fractional number. */
	uint32_t volatile CH5_DIV;
	/*  */
#define PWM_CH5_DIV_INT_Msb					11u
#define PWM_CH5_DIV_INT_Lsb					4u
	/*  */
#define PWM_CH5_DIV_FRAC_Msb					3u
#define PWM_CH5_DIV_FRAC_Lsb					0u

	/* 0x6C: Direct access to the PWM counter */
	uint32_t volatile CH5_CTR;
	/*  */
#define PWM_CH5_CTR_CH5_CTR_Msb					15u
#define PWM_CH5_CTR_CH5_CTR_Lsb					0u

	/* 0x70: Counter compare values */
	uint32_t volatile CH5_CC;
	/*  */
#define PWM_CH5_CC_B_Msb					31u
#define PWM_CH5_CC_B_Lsb					16u
	/*  */
#define PWM_CH5_CC_A_Msb					15u
#define PWM_CH5_CC_A_Lsb					0u

	/* 0x74: Counter wrap value */
	uint32_t volatile CH5_TOP;
	/*  */
#define PWM_CH5_TOP_CH5_TOP_Msb					15u
#define PWM_CH5_TOP_CH5_TOP_Lsb					0u

	/* 0x78: Control and status register */
	uint32_t volatile CH6_CSR;
	/* Advance the phase of the counter by 1 count, while it is running. */
#define PWM_CH6_CSR_PH_ADV					7u
	/* Retard the phase of the counter by 1 count, while it is running. */
#define PWM_CH6_CSR_PH_RET					6u
	/*  */
#define PWM_CH6_CSR_DIVMODE_Msb					5u
#define PWM_CH6_CSR_DIVMODE_Lsb					4u
#define PWM_CH6_CSR_DIVMODE_DIV					0u
#define PWM_CH6_CSR_DIVMODE_LEVEL				1u
#define PWM_CH6_CSR_DIVMODE_RISE				2u
#define PWM_CH6_CSR_DIVMODE_FALL				3u
	/* Invert output B */
#define PWM_CH6_CSR_B_INV					3u
	/* Invert output A */
#define PWM_CH6_CSR_A_INV					2u
	/* 1: Enable phase-correct modulation. */
#define PWM_CH6_CSR_PH_CORRECT					1u
	/* Enable the PWM channel. */
#define PWM_CH6_CSR_EN						0u

	/* 0x7C: INT and FRAC form a fixed-point fractional number. */
	uint32_t volatile CH6_DIV;
	/*  */
#define PWM_CH6_DIV_INT_Msb					11u
#define PWM_CH6_DIV_INT_Lsb					4u
	/*  */
#define PWM_CH6_DIV_FRAC_Msb					3u
#define PWM_CH6_DIV_FRAC_Lsb					0u

	/* 0x80: Direct access to the PWM counter */
	uint32_t volatile CH6_CTR;
	/*  */
#define PWM_CH6_CTR_CH6_CTR_Msb					15u
#define PWM_CH6_CTR_CH6_CTR_Lsb					0u

	/* 0x84: Counter compare values */
	uint32_t volatile CH6_CC;
	/*  */
#define PWM_CH6_CC_B_Msb					31u
#define PWM_CH6_CC_B_Lsb					16u
	/*  */
#define PWM_CH6_CC_A_Msb					15u
#define PWM_CH6_CC_A_Lsb					0u

	/* 0x88: Counter wrap value */
	uint32_t volatile CH6_TOP;
	/*  */
#define PWM_CH6_TOP_CH6_TOP_Msb					15u
#define PWM_CH6_TOP_CH6_TOP_Lsb					0u

	/* 0x8C: Control and status register */
	uint32_t volatile CH7_CSR;
	/* Advance the phase of the counter by 1 count, while it is running. */
#define PWM_CH7_CSR_PH_ADV					7u
	/* Retard the phase of the counter by 1 count, while it is running. */
#define PWM_CH7_CSR_PH_RET					6u
	/*  */
#define PWM_CH7_CSR_DIVMODE_Msb					5u
#define PWM_CH7_CSR_DIVMODE_Lsb					4u
#define PWM_CH7_CSR_DIVMODE_DIV					0u
#define PWM_CH7_CSR_DIVMODE_LEVEL				1u
#define PWM_CH7_CSR_DIVMODE_RISE				2u
#define PWM_CH7_CSR_DIVMODE_FALL				3u
	/* Invert output B */
#define PWM_CH7_CSR_B_INV					3u
	/* Invert output A */
#define PWM_CH7_CSR_A_INV					2u
	/* 1: Enable phase-correct modulation. */
#define PWM_CH7_CSR_PH_CORRECT					1u
	/* Enable the PWM channel. */
#define PWM_CH7_CSR_EN						0u

	/* 0x90: INT and FRAC form a fixed-point fractional number. */
	uint32_t volatile CH7_DIV;
	/*  */
#define PWM_CH7_DIV_INT_Msb					11u
#define PWM_CH7_DIV_INT_Lsb					4u
	/*  */
#define PWM_CH7_DIV_FRAC_Msb					3u
#define PWM_CH7_DIV_FRAC_Lsb					0u

	/* 0x94: Direct access to the PWM counter */
	uint32_t volatile CH7_CTR;
	/*  */
#define PWM_CH7_CTR_CH7_CTR_Msb					15u
#define PWM_CH7_CTR_CH7_CTR_Lsb					0u

	/* 0x98: Counter compare values */
	uint32_t volatile CH7_CC;
	/*  */
#define PWM_CH7_CC_B_Msb					31u
#define PWM_CH7_CC_B_Lsb					16u
	/*  */
#define PWM_CH7_CC_A_Msb					15u
#define PWM_CH7_CC_A_Lsb					0u

	/* 0x9C: Counter wrap value */
	uint32_t volatile CH7_TOP;
	/*  */
#define PWM_CH7_TOP_CH7_TOP_Msb					15u
#define PWM_CH7_TOP_CH7_TOP_Lsb					0u

	/* 0xA0: This register aliases the CSR_EN bits for all channels. */
	uint32_t volatile EN;
	/*  */
#define PWM_EN_CH7						7u
	/*  */
#define PWM_EN_CH6						6u
	/*  */
#define PWM_EN_CH5						5u
	/*  */
#define PWM_EN_CH4						4u
	/*  */
#define PWM_EN_CH3						3u
	/*  */
#define PWM_EN_CH2						2u
	/*  */
#define PWM_EN_CH1						1u
	/*  */
#define PWM_EN_CH0						0u

	/* 0xA4: Raw Interrupts */
	uint32_t volatile INTR;
	/*  */
#define PWM_INTR_CH7						7u
	/*  */
#define PWM_INTR_CH6						6u
	/*  */
#define PWM_INTR_CH5						5u
	/*  */
#define PWM_INTR_CH4						4u
	/*  */
#define PWM_INTR_CH3						3u
	/*  */
#define PWM_INTR_CH2						2u
	/*  */
#define PWM_INTR_CH1						1u
	/*  */
#define PWM_INTR_CH0						0u

	/* 0xA8: Interrupt Enable */
	uint32_t volatile INTE;
	/*  */
#define PWM_INTE_CH7						7u
	/*  */
#define PWM_INTE_CH6						6u
	/*  */
#define PWM_INTE_CH5						5u
	/*  */
#define PWM_INTE_CH4						4u
	/*  */
#define PWM_INTE_CH3						3u
	/*  */
#define PWM_INTE_CH2						2u
	/*  */
#define PWM_INTE_CH1						1u
	/*  */
#define PWM_INTE_CH0						0u

	/* 0xAC: Interrupt Force */
	uint32_t volatile INTF;
	/*  */
#define PWM_INTF_CH7						7u
	/*  */
#define PWM_INTF_CH6						6u
	/*  */
#define PWM_INTF_CH5						5u
	/*  */
#define PWM_INTF_CH4						4u
	/*  */
#define PWM_INTF_CH3						3u
	/*  */
#define PWM_INTF_CH2						2u
	/*  */
#define PWM_INTF_CH1						1u
	/*  */
#define PWM_INTF_CH0						0u

	/* 0xB0: Interrupt status after masking & forcing */
	uint32_t volatile INTS;
	/*  */
#define PWM_INTS_CH7						7u
	/*  */
#define PWM_INTS_CH6						6u
	/*  */
#define PWM_INTS_CH5						5u
	/*  */
#define PWM_INTS_CH4						4u
	/*  */
#define PWM_INTS_CH3						3u
	/*  */
#define PWM_INTS_CH2						2u
	/*  */
#define PWM_INTS_CH1						1u
	/*  */
#define PWM_INTS_CH0						0u

};


#define TIMER ((struct sdk_timer *)0x40054000)

struct sdk_timer {

	/* 0x00: Write to bits 63:32 of time */
	uint32_t volatile TIMEHW;

	/* 0x04: Write to bits 31:0 of time */
	uint32_t volatile TIMELW;

	/* 0x08: Read from bits 63:32 of time */
	uint32_t volatile TIMEHR;

	/* 0x0C: Read from bits 31:0 of time */
	uint32_t volatile TIMELR;

	/* 0x10: Arm alarm 0, and configure the time it will fire. */
	uint32_t volatile ALARM0;

	/* 0x14: Arm alarm 1, and configure the time it will fire. */
	uint32_t volatile ALARM1;

	/* 0x18: Arm alarm 2, and configure the time it will fire. */
	uint32_t volatile ALARM2;

	/* 0x1C: Arm alarm 3, and configure the time it will fire. */
	uint32_t volatile ALARM3;

	/* 0x20: Indicates the armed/disarmed status of each alarm. */
	uint32_t volatile ARMED;
	/*  */
#define TIMER_ARMED_ARMED_Msb					3u
#define TIMER_ARMED_ARMED_Lsb					0u

	/* 0x24: Raw read from bits 63:32 of time (no side effects) */
	uint32_t volatile TIMERAWH;

	/* 0x28: Raw read from bits 31:0 of time (no side effects) */
	uint32_t volatile TIMERAWL;

	/* 0x2C: Set bits high to enable pause when the corresponding debug ports are active */
	uint32_t volatile DBGPAUSE;
	/* Pause when processor 1 is in debug mode */
#define TIMER_DBGPAUSE_DBG1					2u
	/* Pause when processor 0 is in debug mode */
#define TIMER_DBGPAUSE_DBG0					1u

	/* 0x30: Set high to pause the timer */
	uint32_t volatile PAUSE;
	/*  */
#define TIMER_PAUSE_PAUSE					0u

	/* 0x34: Raw Interrupts */
	uint32_t volatile INTR;
	/*  */
#define TIMER_INTR_ALARM_3					3u
	/*  */
#define TIMER_INTR_ALARM_2					2u
	/*  */
#define TIMER_INTR_ALARM_1					1u
	/*  */
#define TIMER_INTR_ALARM_0					0u

	/* 0x38: Interrupt Enable */
	uint32_t volatile INTE;
	/*  */
#define TIMER_INTE_ALARM_3					3u
	/*  */
#define TIMER_INTE_ALARM_2					2u
	/*  */
#define TIMER_INTE_ALARM_1					1u
	/*  */
#define TIMER_INTE_ALARM_0					0u

	/* 0x3C: Interrupt Force */
	uint32_t volatile INTF;
	/*  */
#define TIMER_INTF_ALARM_3					3u
	/*  */
#define TIMER_INTF_ALARM_2					2u
	/*  */
#define TIMER_INTF_ALARM_1					1u
	/*  */
#define TIMER_INTF_ALARM_0					0u

	/* 0x40: Interrupt status after masking & forcing */
	uint32_t volatile INTS;
	/*  */
#define TIMER_INTS_ALARM_3					3u
	/*  */
#define TIMER_INTS_ALARM_2					2u
	/*  */
#define TIMER_INTS_ALARM_1					1u
	/*  */
#define TIMER_INTS_ALARM_0					0u

};


#define WATCHDOG ((struct sdk_watchdog *)0x40058000)

struct sdk_watchdog {

	/* 0x00: Watchdog control */
	uint32_t volatile CTRL;
	/* Trigger a watchdog reset */
#define WATCHDOG_CTRL_TRIGGER					31u
	/* When not enabled the watchdog timer is paused */
#define WATCHDOG_CTRL_ENABLE					30u
	/* Pause the watchdog timer when processor 1 is in debug mode */
#define WATCHDOG_CTRL_PAUSE_DBG1				26u
	/* Pause the watchdog timer when processor 0 is in debug mode */
#define WATCHDOG_CTRL_PAUSE_DBG0				25u
	/* Pause the watchdog timer when JTAG is accessing the bus fabric */
#define WATCHDOG_CTRL_PAUSE_JTAG				24u
	/* Indicates the number of ticks / 2 (see errata RP2040-E1) before a watchdog reset will be triggered */
#define WATCHDOG_CTRL_TIME_Msb					23u
#define WATCHDOG_CTRL_TIME_Lsb					0u

	/* 0x04: Load the watchdog timer. The maximum setting is 0xffffff which corresponds to 0xffffff / 2 ticks before triggering a watchdog reset (see errata RP2040-E1). */
	uint32_t volatile LOAD;
	/*  */
#define WATCHDOG_LOAD_LOAD_Msb					23u
#define WATCHDOG_LOAD_LOAD_Lsb					0u

	/* 0x08: Logs the reason for the last reset. */
	uint32_t volatile REASON;
	/*  */
#define WATCHDOG_REASON_FORCE					1u
	/*  */
#define WATCHDOG_REASON_TIMER					0u

	/* 0x0C: Scratch register. */
	uint32_t volatile SCRATCH0;

	/* 0x10: Scratch register. */
	uint32_t volatile SCRATCH1;

	/* 0x14: Scratch register. */
	uint32_t volatile SCRATCH2;

	/* 0x18: Scratch register. */
	uint32_t volatile SCRATCH3;

	/* 0x1C: Scratch register. */
	uint32_t volatile SCRATCH4;

	/* 0x20: Scratch register. */
	uint32_t volatile SCRATCH5;

	/* 0x24: Scratch register. */
	uint32_t volatile SCRATCH6;

	/* 0x28: Scratch register. */
	uint32_t volatile SCRATCH7;

	/* 0x2C: Controls the tick generator */
	uint32_t volatile TICK;
	/* Count down timer: the remaining number clk_tick cycles before the next tick is generated. */
#define WATCHDOG_TICK_COUNT_Msb					19u
#define WATCHDOG_TICK_COUNT_Lsb					11u
	/* Is the tick generator running? */
#define WATCHDOG_TICK_RUNNING					10u
	/* start / stop tick generation */
#define WATCHDOG_TICK_ENABLE					9u
	/* Total number of clk_tick cycles before the next tick. */
#define WATCHDOG_TICK_CYCLES_Msb				8u
#define WATCHDOG_TICK_CYCLES_Lsb				0u

};


#define RTC ((struct sdk_rtc *)0x4005C000)

struct sdk_rtc {

	/* 0x00: Divider minus 1 for the 1 second counter. */
	uint32_t volatile CLKDIV_M1;
	/*  */
#define RTC_CLKDIV_M1_CLKDIV_M1_Msb				15u
#define RTC_CLKDIV_M1_CLKDIV_M1_Lsb				0u

	/* 0x04: RTC setup register 0 */
	uint32_t volatile SETUP_0;
	/* Year */
#define RTC_SETUP_0_YEAR_Msb					23u
#define RTC_SETUP_0_YEAR_Lsb					12u
	/* Month (1..12) */
#define RTC_SETUP_0_MONTH_Msb					11u
#define RTC_SETUP_0_MONTH_Lsb					8u
	/* Day of the month (1..31) */
#define RTC_SETUP_0_DAY_Msb					4u
#define RTC_SETUP_0_DAY_Lsb					0u

	/* 0x08: RTC setup register 1 */
	uint32_t volatile SETUP_1;
	/* Day of the week: 1-Monday...0-Sunday ISO 8601 mod 7 */
#define RTC_SETUP_1_DOTW_Msb					26u
#define RTC_SETUP_1_DOTW_Lsb					24u
	/* Hours */
#define RTC_SETUP_1_HOUR_Msb					20u
#define RTC_SETUP_1_HOUR_Lsb					16u
	/* Minutes */
#define RTC_SETUP_1_MIN_Msb					13u
#define RTC_SETUP_1_MIN_Lsb					8u
	/* Seconds */
#define RTC_SETUP_1_SEC_Msb					5u
#define RTC_SETUP_1_SEC_Lsb					0u

	/* 0x0C: RTC Control and status */
	uint32_t volatile CTRL;
	/* If set, leapyear is forced off. */
#define RTC_CTRL_FORCE_NOTLEAPYEAR				8u
	/* Load RTC */
#define RTC_CTRL_LOAD						4u
	/* RTC enabled (running) */
#define RTC_CTRL_RTC_ACTIVE					1u
	/* Enable RTC */
#define RTC_CTRL_RTC_ENABLE					0u

	/* 0x10: Interrupt setup register 0 */
	uint32_t volatile IRQ_SETUP_0;
	/*  */
#define RTC_IRQ_SETUP_0_MATCH_ACTIVE				29u
	/* Global match enable. */
#define RTC_IRQ_SETUP_0_MATCH_ENA				28u
	/* Enable year matching */
#define RTC_IRQ_SETUP_0_YEAR_ENA				26u
	/* Enable month matching */
#define RTC_IRQ_SETUP_0_MONTH_ENA				25u
	/* Enable day matching */
#define RTC_IRQ_SETUP_0_DAY_ENA					24u
	/* Year */
#define RTC_IRQ_SETUP_0_YEAR_Msb				23u
#define RTC_IRQ_SETUP_0_YEAR_Lsb				12u
	/* Month (1..12) */
#define RTC_IRQ_SETUP_0_MONTH_Msb				11u
#define RTC_IRQ_SETUP_0_MONTH_Lsb				8u
	/* Day of the month (1..31) */
#define RTC_IRQ_SETUP_0_DAY_Msb					4u
#define RTC_IRQ_SETUP_0_DAY_Lsb					0u

	/* 0x14: Interrupt setup register 1 */
	uint32_t volatile IRQ_SETUP_1;
	/* Enable day of the week matching */
#define RTC_IRQ_SETUP_1_DOTW_ENA				31u
	/* Enable hour matching */
#define RTC_IRQ_SETUP_1_HOUR_ENA				30u
	/* Enable minute matching */
#define RTC_IRQ_SETUP_1_MIN_ENA					29u
	/* Enable second matching */
#define RTC_IRQ_SETUP_1_SEC_ENA					28u
	/* Day of the week */
#define RTC_IRQ_SETUP_1_DOTW_Msb				26u
#define RTC_IRQ_SETUP_1_DOTW_Lsb				24u
	/* Hours */
#define RTC_IRQ_SETUP_1_HOUR_Msb				20u
#define RTC_IRQ_SETUP_1_HOUR_Lsb				16u
	/* Minutes */
#define RTC_IRQ_SETUP_1_MIN_Msb					13u
#define RTC_IRQ_SETUP_1_MIN_Lsb					8u
	/* Seconds */
#define RTC_IRQ_SETUP_1_SEC_Msb					5u
#define RTC_IRQ_SETUP_1_SEC_Lsb					0u

	/* 0x18: RTC register 1. */
	uint32_t volatile RTC_1;
	/* Year */
#define RTC_RTC_1_YEAR_Msb					23u
#define RTC_RTC_1_YEAR_Lsb					12u
	/* Month (1..12) */
#define RTC_RTC_1_MONTH_Msb					11u
#define RTC_RTC_1_MONTH_Lsb					8u
	/* Day of the month (1..31) */
#define RTC_RTC_1_DAY_Msb					4u
#define RTC_RTC_1_DAY_Lsb					0u

	/* 0x1C: RTC register 0 */
	uint32_t volatile RTC_0;
	/* Day of the week */
#define RTC_RTC_0_DOTW_Msb					26u
#define RTC_RTC_0_DOTW_Lsb					24u
	/* Hours */
#define RTC_RTC_0_HOUR_Msb					20u
#define RTC_RTC_0_HOUR_Lsb					16u
	/* Minutes */
#define RTC_RTC_0_MIN_Msb					13u
#define RTC_RTC_0_MIN_Lsb					8u
	/* Seconds */
#define RTC_RTC_0_SEC_Msb					5u
#define RTC_RTC_0_SEC_Lsb					0u

	/* 0x20: Raw Interrupts */
	uint32_t volatile INTR;
	/*  */
#define RTC_INTR_RTC						0u

	/* 0x24: Interrupt Enable */
	uint32_t volatile INTE;
	/*  */
#define RTC_INTE_RTC						0u

	/* 0x28: Interrupt Force */
	uint32_t volatile INTF;
	/*  */
#define RTC_INTF_RTC						0u

	/* 0x2C: Interrupt status after masking & forcing */
	uint32_t volatile INTS;
	/*  */
#define RTC_INTS_RTC						0u

};


#define ROSC ((struct sdk_rosc *)0x40060000)

struct sdk_rosc {

	/* 0x00: Ring Oscillator control */
	uint32_t volatile CTRL;
	/* On power-up this field is initialised to ENABLE */
#define ROSC_CTRL_ENABLE_Msb					23u
#define ROSC_CTRL_ENABLE_Lsb					12u
#define ROSC_CTRL_ENABLE_DISABLE				3358u
#define ROSC_CTRL_ENABLE_ENABLE					4011u
	/* Controls the number of delay stages in the ROSC ring */
#define ROSC_CTRL_FREQ_RANGE_Msb				11u
#define ROSC_CTRL_FREQ_RANGE_Lsb				0u
#define ROSC_CTRL_FREQ_RANGE_LOW				4004u
#define ROSC_CTRL_FREQ_RANGE_MEDIUM				4005u
#define ROSC_CTRL_FREQ_RANGE_HIGH				4007u
#define ROSC_CTRL_FREQ_RANGE_TOOHIGH				4006u

	/* 0x04: The FREQA & FREQB registers control the frequency by controlling the drive strength of each stage */
	uint32_t volatile FREQA;
	/* Set to 0x9696 to apply the settings */
#define ROSC_FREQA_PASSWD_Msb					31u
#define ROSC_FREQA_PASSWD_Lsb					16u
#define ROSC_FREQA_PASSWD_PASS					38550u
	/* Stage 3 drive strength */
#define ROSC_FREQA_DS3_Msb					14u
#define ROSC_FREQA_DS3_Lsb					12u
	/* Stage 2 drive strength */
#define ROSC_FREQA_DS2_Msb					10u
#define ROSC_FREQA_DS2_Lsb					8u
	/* Stage 1 drive strength */
#define ROSC_FREQA_DS1_Msb					6u
#define ROSC_FREQA_DS1_Lsb					4u
	/* Stage 0 drive strength */
#define ROSC_FREQA_DS0_Msb					2u
#define ROSC_FREQA_DS0_Lsb					0u

	/* 0x08: For a detailed description see freqa register */
	uint32_t volatile FREQB;
	/* Set to 0x9696 to apply the settings */
#define ROSC_FREQB_PASSWD_Msb					31u
#define ROSC_FREQB_PASSWD_Lsb					16u
#define ROSC_FREQB_PASSWD_PASS					38550u
	/* Stage 7 drive strength */
#define ROSC_FREQB_DS7_Msb					14u
#define ROSC_FREQB_DS7_Lsb					12u
	/* Stage 6 drive strength */
#define ROSC_FREQB_DS6_Msb					10u
#define ROSC_FREQB_DS6_Lsb					8u
	/* Stage 5 drive strength */
#define ROSC_FREQB_DS5_Msb					6u
#define ROSC_FREQB_DS5_Lsb					4u
	/* Stage 4 drive strength */
#define ROSC_FREQB_DS4_Msb					2u
#define ROSC_FREQB_DS4_Lsb					0u

	/* 0x0C: Ring Oscillator pause control */
	uint32_t volatile DORMANT;

	/* 0x10: Controls the output divider */
	uint32_t volatile DIV;
	/* set to 0xaa0 + div where */
#define ROSC_DIV_DIV_Msb					11u
#define ROSC_DIV_DIV_Lsb					0u
#define ROSC_DIV_DIV_PASS					2720u

	/* 0x14: Controls the phase shifted output */
	uint32_t volatile PHASE;
	/* set to 0xaa */
#define ROSC_PHASE_PASSWD_Msb					11u
#define ROSC_PHASE_PASSWD_Lsb					4u
	/* enable the phase-shifted output */
#define ROSC_PHASE_ENABLE					3u
	/* invert the phase-shifted output */
#define ROSC_PHASE_FLIP						2u
	/* phase shift the phase-shifted output by SHIFT input clocks */
#define ROSC_PHASE_SHIFT_Msb					1u
#define ROSC_PHASE_SHIFT_Lsb					0u

	/* 0x18: Ring Oscillator Status */
	uint32_t volatile STATUS;
	/* Oscillator is running and stable */
#define ROSC_STATUS_STABLE					31u
	/* An invalid value has been written to CTRL_ENABLE or CTRL_FREQ_RANGE or FREQA or FREQB or DIV or PHASE or DORMANT */
#define ROSC_STATUS_BADWRITE					24u
	/* post-divider is running */
#define ROSC_STATUS_DIV_RUNNING					16u
	/* Oscillator is enabled but not necessarily running and stable */
#define ROSC_STATUS_ENABLED					12u

	/* 0x1C: This just reads the state of the oscillator output so randomness is compromised if the ring oscillator is stopped or run at a harmonic of the bus frequency */
	uint32_t volatile RANDOMBIT;
	/*  */
#define ROSC_RANDOMBIT_RANDOMBIT				0u

	/* 0x20: A down counter running at the ROSC frequency which counts to zero and stops. */
	uint32_t volatile COUNT;
	/*  */
#define ROSC_COUNT_COUNT_Msb					7u
#define ROSC_COUNT_COUNT_Lsb					0u

};


#define VREG_AND_CHIP_RESET ((struct sdk_vreg_and_chip_reset *)0x40064000)

struct sdk_vreg_and_chip_reset {

	/* 0x00: Voltage regulator control and status */
	uint32_t volatile VREG;
	/* regulation status */
#define VREG_AND_CHIP_RESET_VREG_ROK				12u
	/* output voltage select */
#define VREG_AND_CHIP_RESET_VREG_VSEL_Msb			7u
#define VREG_AND_CHIP_RESET_VREG_VSEL_Lsb			4u
	/* high impedance mode select */
#define VREG_AND_CHIP_RESET_VREG_HIZ				1u
	/* enable */
#define VREG_AND_CHIP_RESET_VREG_EN				0u

	/* 0x04: brown-out detection control */
	uint32_t volatile BOD;
	/* threshold select */
#define VREG_AND_CHIP_RESET_BOD_VSEL_Msb			7u
#define VREG_AND_CHIP_RESET_BOD_VSEL_Lsb			4u
	/* enable */
#define VREG_AND_CHIP_RESET_BOD_EN				0u

	/* 0x08: Chip reset control and status */
	uint32_t volatile CHIP_RESET;
	/* This is set by psm_restart from the debugger. */
#define VREG_AND_CHIP_RESET_CHIP_RESET_PSM_RESTART_FLAG		24u
	/* Last reset was from the debug port */
#define VREG_AND_CHIP_RESET_CHIP_RESET_HAD_PSM_RESTART		20u
	/* Last reset was from the RUN pin */
#define VREG_AND_CHIP_RESET_CHIP_RESET_HAD_RUN			16u
	/* Last reset was from the power-on reset or brown-out detection blocks */
#define VREG_AND_CHIP_RESET_CHIP_RESET_HAD_POR			8u

};


#define TBMAN ((struct sdk_tbman *)0x4006C000)

struct sdk_tbman {

	/* 0x00: Indicates the type of platform in use */
	uint32_t volatile PLATFORM;
	/* Indicates the platform is an FPGA */
#define TBMAN_PLATFORM_FPGA					1u
	/* Indicates the platform is an ASIC */
#define TBMAN_PLATFORM_ASIC					0u

};


#define DMA ((struct sdk_dma *)0x50000000)

struct sdk_dma {

	/* 0x00: DMA Channel 0 Read Address pointer */
	uint32_t volatile CH0_READ_ADDR;

	/* 0x04: DMA Channel 0 Write Address pointer */
	uint32_t volatile CH0_WRITE_ADDR;

	/* 0x08: DMA Channel 0 Transfer Count */
	uint32_t volatile CH0_TRANS_COUNT;

	/* 0x0C: DMA Channel 0 Control and Status */
	uint32_t volatile CH0_CTRL_TRIG;
	/* Logical OR of the READ_ERROR and WRITE_ERROR flags. */
#define DMA_CH0_CTRL_TRIG_AHB_ERROR				31u
	/* If 1, the channel received a read bus error. */
#define DMA_CH0_CTRL_TRIG_READ_ERROR				30u
	/* If 1, the channel received a write bus error. */
#define DMA_CH0_CTRL_TRIG_WRITE_ERROR				29u
	/* This flag goes high when the channel starts a new transfer sequence, and low when the last transfer of that sequence completes. */
#define DMA_CH0_CTRL_TRIG_BUSY					24u
	/* If 1, this channel's data transfers are visible to the sniff hardware, and each transfer will advance the state of the checksum. */
#define DMA_CH0_CTRL_TRIG_SNIFF_EN				23u
	/* Apply byte-swap transformation to DMA data. */
#define DMA_CH0_CTRL_TRIG_BSWAP					22u
	/* In QUIET mode, the channel does not generate IRQs at the end of every transfer block. */
#define DMA_CH0_CTRL_TRIG_IRQ_QUIET				21u
	/* Select a Transfer Request signal. */
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_Msb				20u
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_Lsb				15u
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_TIMER0			59u
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_TIMER1			60u
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_TIMER2			61u
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_TIMER3			62u
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PERMANENT			63u
	/* When this channel completes, it will trigger the channel indicated by CHAIN_TO. Disable by setting CHAIN_TO = _(this channel)_. */
#define DMA_CH0_CTRL_TRIG_CHAIN_TO_Msb				14u
#define DMA_CH0_CTRL_TRIG_CHAIN_TO_Lsb				11u
	/* Select whether RING_SIZE applies to read or write addresses. */
#define DMA_CH0_CTRL_TRIG_RING_SEL				10u
	/* Size of address wrap region. If 0, don't wrap. For values n > 0, only the lower n bits of the address will change. This wraps the address on a (1 << n) byte boundary, facilitating access to naturally-aligned ring buffers. */
#define DMA_CH0_CTRL_TRIG_RING_SIZE_Msb				9u
#define DMA_CH0_CTRL_TRIG_RING_SIZE_Lsb				6u
#define DMA_CH0_CTRL_TRIG_RING_SIZE_RING_NONE			0u
	/* If 1, the write address increments with each transfer. */
#define DMA_CH0_CTRL_TRIG_INCR_WRITE				5u
	/* If 1, the read address increments with each transfer. */
#define DMA_CH0_CTRL_TRIG_INCR_READ				4u
	/* Set the size of each bus transfer (byte/halfword/word). READ_ADDR and WRITE_ADDR advance by this amount (1/2/4 bytes) with each transfer. */
#define DMA_CH0_CTRL_TRIG_DATA_SIZE_Msb				3u
#define DMA_CH0_CTRL_TRIG_DATA_SIZE_Lsb				2u
#define DMA_CH0_CTRL_TRIG_DATA_SIZE_SIZE_BYTE			0u
#define DMA_CH0_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD		1u
#define DMA_CH0_CTRL_TRIG_DATA_SIZE_SIZE_WORD			2u
	/* HIGH_PRIORITY gives a channel preferential treatment in issue scheduling: in each scheduling round, all high priority channels are considered first, and then only a single low priority channel, before returning to the high priority channels. */
#define DMA_CH0_CTRL_TRIG_HIGH_PRIORITY				1u
	/* DMA Channel Enable. */
#define DMA_CH0_CTRL_TRIG_EN					0u

	/* 0x10: Alias for channel 0 CTRL register */
	uint32_t volatile CH0_AL1_CTRL;

	/* 0x14: Alias for channel 0 READ_ADDR register */
	uint32_t volatile CH0_AL1_READ_ADDR;

	/* 0x18: Alias for channel 0 WRITE_ADDR register */
	uint32_t volatile CH0_AL1_WRITE_ADDR;

	/* 0x1C: Alias for channel 0 TRANS_COUNT register */
	uint32_t volatile CH0_AL1_TRANS_COUNT_TRIG;

	/* 0x20: Alias for channel 0 CTRL register */
	uint32_t volatile CH0_AL2_CTRL;

	/* 0x24: Alias for channel 0 TRANS_COUNT register */
	uint32_t volatile CH0_AL2_TRANS_COUNT;

	/* 0x28: Alias for channel 0 READ_ADDR register */
	uint32_t volatile CH0_AL2_READ_ADDR;

	/* 0x2C: Alias for channel 0 WRITE_ADDR register */
	uint32_t volatile CH0_AL2_WRITE_ADDR_TRIG;

	/* 0x30: Alias for channel 0 CTRL register */
	uint32_t volatile CH0_AL3_CTRL;

	/* 0x34: Alias for channel 0 WRITE_ADDR register */
	uint32_t volatile CH0_AL3_WRITE_ADDR;

	/* 0x38: Alias for channel 0 TRANS_COUNT register */
	uint32_t volatile CH0_AL3_TRANS_COUNT;

	/* 0x3C: Alias for channel 0 READ_ADDR register */
	uint32_t volatile CH0_AL3_READ_ADDR_TRIG;

	/* 0x40: DMA Channel 1 Read Address pointer */
	uint32_t volatile CH1_READ_ADDR;

	/* 0x44: DMA Channel 1 Write Address pointer */
	uint32_t volatile CH1_WRITE_ADDR;

	/* 0x48: DMA Channel 1 Transfer Count */
	uint32_t volatile CH1_TRANS_COUNT;

	/* 0x4C: DMA Channel 1 Control and Status */
	uint32_t volatile CH1_CTRL_TRIG;
	/* Logical OR of the READ_ERROR and WRITE_ERROR flags. */
#define DMA_CH1_CTRL_TRIG_AHB_ERROR				31u
	/* If 1, the channel received a read bus error. */
#define DMA_CH1_CTRL_TRIG_READ_ERROR				30u
	/* If 1, the channel received a write bus error. */
#define DMA_CH1_CTRL_TRIG_WRITE_ERROR				29u
	/* This flag goes high when the channel starts a new transfer sequence, and low when the last transfer of that sequence completes. */
#define DMA_CH1_CTRL_TRIG_BUSY					24u
	/* If 1, this channel's data transfers are visible to the sniff hardware, and each transfer will advance the state of the checksum. */
#define DMA_CH1_CTRL_TRIG_SNIFF_EN				23u
	/* Apply byte-swap transformation to DMA data. */
#define DMA_CH1_CTRL_TRIG_BSWAP					22u
	/* In QUIET mode, the channel does not generate IRQs at the end of every transfer block. */
#define DMA_CH1_CTRL_TRIG_IRQ_QUIET				21u
	/* Select a Transfer Request signal. */
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_Msb				20u
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_Lsb				15u
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_TIMER0			59u
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_TIMER1			60u
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_TIMER2			61u
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_TIMER3			62u
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PERMANENT			63u
	/* When this channel completes, it will trigger the channel indicated by CHAIN_TO. Disable by setting CHAIN_TO = _(this channel)_. */
#define DMA_CH1_CTRL_TRIG_CHAIN_TO_Msb				14u
#define DMA_CH1_CTRL_TRIG_CHAIN_TO_Lsb				11u
	/* Select whether RING_SIZE applies to read or write addresses. */
#define DMA_CH1_CTRL_TRIG_RING_SEL				10u
	/* Size of address wrap region. If 0, don't wrap. For values n > 0, only the lower n bits of the address will change. This wraps the address on a (1 << n) byte boundary, facilitating access to naturally-aligned ring buffers. */
#define DMA_CH1_CTRL_TRIG_RING_SIZE_Msb				9u
#define DMA_CH1_CTRL_TRIG_RING_SIZE_Lsb				6u
#define DMA_CH1_CTRL_TRIG_RING_SIZE_RING_NONE			0u
	/* If 1, the write address increments with each transfer. */
#define DMA_CH1_CTRL_TRIG_INCR_WRITE				5u
	/* If 1, the read address increments with each transfer. */
#define DMA_CH1_CTRL_TRIG_INCR_READ				4u
	/* Set the size of each bus transfer (byte/halfword/word). READ_ADDR and WRITE_ADDR advance by this amount (1/2/4 bytes) with each transfer. */
#define DMA_CH1_CTRL_TRIG_DATA_SIZE_Msb				3u
#define DMA_CH1_CTRL_TRIG_DATA_SIZE_Lsb				2u
#define DMA_CH1_CTRL_TRIG_DATA_SIZE_SIZE_BYTE			0u
#define DMA_CH1_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD		1u
#define DMA_CH1_CTRL_TRIG_DATA_SIZE_SIZE_WORD			2u
	/* HIGH_PRIORITY gives a channel preferential treatment in issue scheduling: in each scheduling round, all high priority channels are considered first, and then only a single low priority channel, before returning to the high priority channels. */
#define DMA_CH1_CTRL_TRIG_HIGH_PRIORITY				1u
	/* DMA Channel Enable. */
#define DMA_CH1_CTRL_TRIG_EN					0u

	/* 0x50: Alias for channel 1 CTRL register */
	uint32_t volatile CH1_AL1_CTRL;

	/* 0x54: Alias for channel 1 READ_ADDR register */
	uint32_t volatile CH1_AL1_READ_ADDR;

	/* 0x58: Alias for channel 1 WRITE_ADDR register */
	uint32_t volatile CH1_AL1_WRITE_ADDR;

	/* 0x5C: Alias for channel 1 TRANS_COUNT register */
	uint32_t volatile CH1_AL1_TRANS_COUNT_TRIG;

	/* 0x60: Alias for channel 1 CTRL register */
	uint32_t volatile CH1_AL2_CTRL;

	/* 0x64: Alias for channel 1 TRANS_COUNT register */
	uint32_t volatile CH1_AL2_TRANS_COUNT;

	/* 0x68: Alias for channel 1 READ_ADDR register */
	uint32_t volatile CH1_AL2_READ_ADDR;

	/* 0x6C: Alias for channel 1 WRITE_ADDR register */
	uint32_t volatile CH1_AL2_WRITE_ADDR_TRIG;

	/* 0x70: Alias for channel 1 CTRL register */
	uint32_t volatile CH1_AL3_CTRL;

	/* 0x74: Alias for channel 1 WRITE_ADDR register */
	uint32_t volatile CH1_AL3_WRITE_ADDR;

	/* 0x78: Alias for channel 1 TRANS_COUNT register */
	uint32_t volatile CH1_AL3_TRANS_COUNT;

	/* 0x7C: Alias for channel 1 READ_ADDR register */
	uint32_t volatile CH1_AL3_READ_ADDR_TRIG;

	/* 0x80: DMA Channel 2 Read Address pointer */
	uint32_t volatile CH2_READ_ADDR;

	/* 0x84: DMA Channel 2 Write Address pointer */
	uint32_t volatile CH2_WRITE_ADDR;

	/* 0x88: DMA Channel 2 Transfer Count */
	uint32_t volatile CH2_TRANS_COUNT;

	/* 0x8C: DMA Channel 2 Control and Status */
	uint32_t volatile CH2_CTRL_TRIG;
	/* Logical OR of the READ_ERROR and WRITE_ERROR flags. */
#define DMA_CH2_CTRL_TRIG_AHB_ERROR				31u
	/* If 1, the channel received a read bus error. */
#define DMA_CH2_CTRL_TRIG_READ_ERROR				30u
	/* If 1, the channel received a write bus error. */
#define DMA_CH2_CTRL_TRIG_WRITE_ERROR				29u
	/* This flag goes high when the channel starts a new transfer sequence, and low when the last transfer of that sequence completes. */
#define DMA_CH2_CTRL_TRIG_BUSY					24u
	/* If 1, this channel's data transfers are visible to the sniff hardware, and each transfer will advance the state of the checksum. */
#define DMA_CH2_CTRL_TRIG_SNIFF_EN				23u
	/* Apply byte-swap transformation to DMA data. */
#define DMA_CH2_CTRL_TRIG_BSWAP					22u
	/* In QUIET mode, the channel does not generate IRQs at the end of every transfer block. */
#define DMA_CH2_CTRL_TRIG_IRQ_QUIET				21u
	/* Select a Transfer Request signal. */
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_Msb				20u
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_Lsb				15u
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_TIMER0			59u
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_TIMER1			60u
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_TIMER2			61u
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_TIMER3			62u
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PERMANENT			63u
	/* When this channel completes, it will trigger the channel indicated by CHAIN_TO. Disable by setting CHAIN_TO = _(this channel)_. */
#define DMA_CH2_CTRL_TRIG_CHAIN_TO_Msb				14u
#define DMA_CH2_CTRL_TRIG_CHAIN_TO_Lsb				11u
	/* Select whether RING_SIZE applies to read or write addresses. */
#define DMA_CH2_CTRL_TRIG_RING_SEL				10u
	/* Size of address wrap region. If 0, don't wrap. For values n > 0, only the lower n bits of the address will change. This wraps the address on a (1 << n) byte boundary, facilitating access to naturally-aligned ring buffers. */
#define DMA_CH2_CTRL_TRIG_RING_SIZE_Msb				9u
#define DMA_CH2_CTRL_TRIG_RING_SIZE_Lsb				6u
#define DMA_CH2_CTRL_TRIG_RING_SIZE_RING_NONE			0u
	/* If 1, the write address increments with each transfer. */
#define DMA_CH2_CTRL_TRIG_INCR_WRITE				5u
	/* If 1, the read address increments with each transfer. */
#define DMA_CH2_CTRL_TRIG_INCR_READ				4u
	/* Set the size of each bus transfer (byte/halfword/word). READ_ADDR and WRITE_ADDR advance by this amount (1/2/4 bytes) with each transfer. */
#define DMA_CH2_CTRL_TRIG_DATA_SIZE_Msb				3u
#define DMA_CH2_CTRL_TRIG_DATA_SIZE_Lsb				2u
#define DMA_CH2_CTRL_TRIG_DATA_SIZE_SIZE_BYTE			0u
#define DMA_CH2_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD		1u
#define DMA_CH2_CTRL_TRIG_DATA_SIZE_SIZE_WORD			2u
	/* HIGH_PRIORITY gives a channel preferential treatment in issue scheduling: in each scheduling round, all high priority channels are considered first, and then only a single low priority channel, before returning to the high priority channels. */
#define DMA_CH2_CTRL_TRIG_HIGH_PRIORITY				1u
	/* DMA Channel Enable. */
#define DMA_CH2_CTRL_TRIG_EN					0u

	/* 0x90: Alias for channel 2 CTRL register */
	uint32_t volatile CH2_AL1_CTRL;

	/* 0x94: Alias for channel 2 READ_ADDR register */
	uint32_t volatile CH2_AL1_READ_ADDR;

	/* 0x98: Alias for channel 2 WRITE_ADDR register */
	uint32_t volatile CH2_AL1_WRITE_ADDR;

	/* 0x9C: Alias for channel 2 TRANS_COUNT register */
	uint32_t volatile CH2_AL1_TRANS_COUNT_TRIG;

	/* 0xA0: Alias for channel 2 CTRL register */
	uint32_t volatile CH2_AL2_CTRL;

	/* 0xA4: Alias for channel 2 TRANS_COUNT register */
	uint32_t volatile CH2_AL2_TRANS_COUNT;

	/* 0xA8: Alias for channel 2 READ_ADDR register */
	uint32_t volatile CH2_AL2_READ_ADDR;

	/* 0xAC: Alias for channel 2 WRITE_ADDR register */
	uint32_t volatile CH2_AL2_WRITE_ADDR_TRIG;

	/* 0xB0: Alias for channel 2 CTRL register */
	uint32_t volatile CH2_AL3_CTRL;

	/* 0xB4: Alias for channel 2 WRITE_ADDR register */
	uint32_t volatile CH2_AL3_WRITE_ADDR;

	/* 0xB8: Alias for channel 2 TRANS_COUNT register */
	uint32_t volatile CH2_AL3_TRANS_COUNT;

	/* 0xBC: Alias for channel 2 READ_ADDR register */
	uint32_t volatile CH2_AL3_READ_ADDR_TRIG;

	/* 0xC0: DMA Channel 3 Read Address pointer */
	uint32_t volatile CH3_READ_ADDR;

	/* 0xC4: DMA Channel 3 Write Address pointer */
	uint32_t volatile CH3_WRITE_ADDR;

	/* 0xC8: DMA Channel 3 Transfer Count */
	uint32_t volatile CH3_TRANS_COUNT;

	/* 0xCC: DMA Channel 3 Control and Status */
	uint32_t volatile CH3_CTRL_TRIG;
	/* Logical OR of the READ_ERROR and WRITE_ERROR flags. */
#define DMA_CH3_CTRL_TRIG_AHB_ERROR				31u
	/* If 1, the channel received a read bus error. */
#define DMA_CH3_CTRL_TRIG_READ_ERROR				30u
	/* If 1, the channel received a write bus error. */
#define DMA_CH3_CTRL_TRIG_WRITE_ERROR				29u
	/* This flag goes high when the channel starts a new transfer sequence, and low when the last transfer of that sequence completes. */
#define DMA_CH3_CTRL_TRIG_BUSY					24u
	/* If 1, this channel's data transfers are visible to the sniff hardware, and each transfer will advance the state of the checksum. */
#define DMA_CH3_CTRL_TRIG_SNIFF_EN				23u
	/* Apply byte-swap transformation to DMA data. */
#define DMA_CH3_CTRL_TRIG_BSWAP					22u
	/* In QUIET mode, the channel does not generate IRQs at the end of every transfer block. */
#define DMA_CH3_CTRL_TRIG_IRQ_QUIET				21u
	/* Select a Transfer Request signal. */
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_Msb				20u
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_Lsb				15u
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_TIMER0			59u
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_TIMER1			60u
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_TIMER2			61u
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_TIMER3			62u
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PERMANENT			63u
	/* When this channel completes, it will trigger the channel indicated by CHAIN_TO. Disable by setting CHAIN_TO = _(this channel)_. */
#define DMA_CH3_CTRL_TRIG_CHAIN_TO_Msb				14u
#define DMA_CH3_CTRL_TRIG_CHAIN_TO_Lsb				11u
	/* Select whether RING_SIZE applies to read or write addresses. */
#define DMA_CH3_CTRL_TRIG_RING_SEL				10u
	/* Size of address wrap region. If 0, don't wrap. For values n > 0, only the lower n bits of the address will change. This wraps the address on a (1 << n) byte boundary, facilitating access to naturally-aligned ring buffers. */
#define DMA_CH3_CTRL_TRIG_RING_SIZE_Msb				9u
#define DMA_CH3_CTRL_TRIG_RING_SIZE_Lsb				6u
#define DMA_CH3_CTRL_TRIG_RING_SIZE_RING_NONE			0u
	/* If 1, the write address increments with each transfer. */
#define DMA_CH3_CTRL_TRIG_INCR_WRITE				5u
	/* If 1, the read address increments with each transfer. */
#define DMA_CH3_CTRL_TRIG_INCR_READ				4u
	/* Set the size of each bus transfer (byte/halfword/word). READ_ADDR and WRITE_ADDR advance by this amount (1/2/4 bytes) with each transfer. */
#define DMA_CH3_CTRL_TRIG_DATA_SIZE_Msb				3u
#define DMA_CH3_CTRL_TRIG_DATA_SIZE_Lsb				2u
#define DMA_CH3_CTRL_TRIG_DATA_SIZE_SIZE_BYTE			0u
#define DMA_CH3_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD		1u
#define DMA_CH3_CTRL_TRIG_DATA_SIZE_SIZE_WORD			2u
	/* HIGH_PRIORITY gives a channel preferential treatment in issue scheduling: in each scheduling round, all high priority channels are considered first, and then only a single low priority channel, before returning to the high priority channels. */
#define DMA_CH3_CTRL_TRIG_HIGH_PRIORITY				1u
	/* DMA Channel Enable. */
#define DMA_CH3_CTRL_TRIG_EN					0u

	/* 0xD0: Alias for channel 3 CTRL register */
	uint32_t volatile CH3_AL1_CTRL;

	/* 0xD4: Alias for channel 3 READ_ADDR register */
	uint32_t volatile CH3_AL1_READ_ADDR;

	/* 0xD8: Alias for channel 3 WRITE_ADDR register */
	uint32_t volatile CH3_AL1_WRITE_ADDR;

	/* 0xDC: Alias for channel 3 TRANS_COUNT register */
	uint32_t volatile CH3_AL1_TRANS_COUNT_TRIG;

	/* 0xE0: Alias for channel 3 CTRL register */
	uint32_t volatile CH3_AL2_CTRL;

	/* 0xE4: Alias for channel 3 TRANS_COUNT register */
	uint32_t volatile CH3_AL2_TRANS_COUNT;

	/* 0xE8: Alias for channel 3 READ_ADDR register */
	uint32_t volatile CH3_AL2_READ_ADDR;

	/* 0xEC: Alias for channel 3 WRITE_ADDR register */
	uint32_t volatile CH3_AL2_WRITE_ADDR_TRIG;

	/* 0xF0: Alias for channel 3 CTRL register */
	uint32_t volatile CH3_AL3_CTRL;

	/* 0xF4: Alias for channel 3 WRITE_ADDR register */
	uint32_t volatile CH3_AL3_WRITE_ADDR;

	/* 0xF8: Alias for channel 3 TRANS_COUNT register */
	uint32_t volatile CH3_AL3_TRANS_COUNT;

	/* 0xFC: Alias for channel 3 READ_ADDR register */
	uint32_t volatile CH3_AL3_READ_ADDR_TRIG;

	/* 0x100: DMA Channel 4 Read Address pointer */
	uint32_t volatile CH4_READ_ADDR;

	/* 0x104: DMA Channel 4 Write Address pointer */
	uint32_t volatile CH4_WRITE_ADDR;

	/* 0x108: DMA Channel 4 Transfer Count */
	uint32_t volatile CH4_TRANS_COUNT;

	/* 0x10C: DMA Channel 4 Control and Status */
	uint32_t volatile CH4_CTRL_TRIG;
	/* Logical OR of the READ_ERROR and WRITE_ERROR flags. */
#define DMA_CH4_CTRL_TRIG_AHB_ERROR				31u
	/* If 1, the channel received a read bus error. */
#define DMA_CH4_CTRL_TRIG_READ_ERROR				30u
	/* If 1, the channel received a write bus error. */
#define DMA_CH4_CTRL_TRIG_WRITE_ERROR				29u
	/* This flag goes high when the channel starts a new transfer sequence, and low when the last transfer of that sequence completes. */
#define DMA_CH4_CTRL_TRIG_BUSY					24u
	/* If 1, this channel's data transfers are visible to the sniff hardware, and each transfer will advance the state of the checksum. */
#define DMA_CH4_CTRL_TRIG_SNIFF_EN				23u
	/* Apply byte-swap transformation to DMA data. */
#define DMA_CH4_CTRL_TRIG_BSWAP					22u
	/* In QUIET mode, the channel does not generate IRQs at the end of every transfer block. */
#define DMA_CH4_CTRL_TRIG_IRQ_QUIET				21u
	/* Select a Transfer Request signal. */
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_Msb				20u
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_Lsb				15u
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_TIMER0			59u
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_TIMER1			60u
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_TIMER2			61u
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_TIMER3			62u
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PERMANENT			63u
	/* When this channel completes, it will trigger the channel indicated by CHAIN_TO. Disable by setting CHAIN_TO = _(this channel)_. */
#define DMA_CH4_CTRL_TRIG_CHAIN_TO_Msb				14u
#define DMA_CH4_CTRL_TRIG_CHAIN_TO_Lsb				11u
	/* Select whether RING_SIZE applies to read or write addresses. */
#define DMA_CH4_CTRL_TRIG_RING_SEL				10u
	/* Size of address wrap region. If 0, don't wrap. For values n > 0, only the lower n bits of the address will change. This wraps the address on a (1 << n) byte boundary, facilitating access to naturally-aligned ring buffers. */
#define DMA_CH4_CTRL_TRIG_RING_SIZE_Msb				9u
#define DMA_CH4_CTRL_TRIG_RING_SIZE_Lsb				6u
#define DMA_CH4_CTRL_TRIG_RING_SIZE_RING_NONE			0u
	/* If 1, the write address increments with each transfer. */
#define DMA_CH4_CTRL_TRIG_INCR_WRITE				5u
	/* If 1, the read address increments with each transfer. */
#define DMA_CH4_CTRL_TRIG_INCR_READ				4u
	/* Set the size of each bus transfer (byte/halfword/word). READ_ADDR and WRITE_ADDR advance by this amount (1/2/4 bytes) with each transfer. */
#define DMA_CH4_CTRL_TRIG_DATA_SIZE_Msb				3u
#define DMA_CH4_CTRL_TRIG_DATA_SIZE_Lsb				2u
#define DMA_CH4_CTRL_TRIG_DATA_SIZE_SIZE_BYTE			0u
#define DMA_CH4_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD		1u
#define DMA_CH4_CTRL_TRIG_DATA_SIZE_SIZE_WORD			2u
	/* HIGH_PRIORITY gives a channel preferential treatment in issue scheduling: in each scheduling round, all high priority channels are considered first, and then only a single low priority channel, before returning to the high priority channels. */
#define DMA_CH4_CTRL_TRIG_HIGH_PRIORITY				1u
	/* DMA Channel Enable. */
#define DMA_CH4_CTRL_TRIG_EN					0u

	/* 0x110: Alias for channel 4 CTRL register */
	uint32_t volatile CH4_AL1_CTRL;

	/* 0x114: Alias for channel 4 READ_ADDR register */
	uint32_t volatile CH4_AL1_READ_ADDR;

	/* 0x118: Alias for channel 4 WRITE_ADDR register */
	uint32_t volatile CH4_AL1_WRITE_ADDR;

	/* 0x11C: Alias for channel 4 TRANS_COUNT register */
	uint32_t volatile CH4_AL1_TRANS_COUNT_TRIG;

	/* 0x120: Alias for channel 4 CTRL register */
	uint32_t volatile CH4_AL2_CTRL;

	/* 0x124: Alias for channel 4 TRANS_COUNT register */
	uint32_t volatile CH4_AL2_TRANS_COUNT;

	/* 0x128: Alias for channel 4 READ_ADDR register */
	uint32_t volatile CH4_AL2_READ_ADDR;

	/* 0x12C: Alias for channel 4 WRITE_ADDR register */
	uint32_t volatile CH4_AL2_WRITE_ADDR_TRIG;

	/* 0x130: Alias for channel 4 CTRL register */
	uint32_t volatile CH4_AL3_CTRL;

	/* 0x134: Alias for channel 4 WRITE_ADDR register */
	uint32_t volatile CH4_AL3_WRITE_ADDR;

	/* 0x138: Alias for channel 4 TRANS_COUNT register */
	uint32_t volatile CH4_AL3_TRANS_COUNT;

	/* 0x13C: Alias for channel 4 READ_ADDR register */
	uint32_t volatile CH4_AL3_READ_ADDR_TRIG;

	/* 0x140: DMA Channel 5 Read Address pointer */
	uint32_t volatile CH5_READ_ADDR;

	/* 0x144: DMA Channel 5 Write Address pointer */
	uint32_t volatile CH5_WRITE_ADDR;

	/* 0x148: DMA Channel 5 Transfer Count */
	uint32_t volatile CH5_TRANS_COUNT;

	/* 0x14C: DMA Channel 5 Control and Status */
	uint32_t volatile CH5_CTRL_TRIG;
	/* Logical OR of the READ_ERROR and WRITE_ERROR flags. */
#define DMA_CH5_CTRL_TRIG_AHB_ERROR				31u
	/* If 1, the channel received a read bus error. */
#define DMA_CH5_CTRL_TRIG_READ_ERROR				30u
	/* If 1, the channel received a write bus error. */
#define DMA_CH5_CTRL_TRIG_WRITE_ERROR				29u
	/* This flag goes high when the channel starts a new transfer sequence, and low when the last transfer of that sequence completes. */
#define DMA_CH5_CTRL_TRIG_BUSY					24u
	/* If 1, this channel's data transfers are visible to the sniff hardware, and each transfer will advance the state of the checksum. */
#define DMA_CH5_CTRL_TRIG_SNIFF_EN				23u
	/* Apply byte-swap transformation to DMA data. */
#define DMA_CH5_CTRL_TRIG_BSWAP					22u
	/* In QUIET mode, the channel does not generate IRQs at the end of every transfer block. */
#define DMA_CH5_CTRL_TRIG_IRQ_QUIET				21u
	/* Select a Transfer Request signal. */
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_Msb				20u
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_Lsb				15u
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_TIMER0			59u
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_TIMER1			60u
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_TIMER2			61u
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_TIMER3			62u
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PERMANENT			63u
	/* When this channel completes, it will trigger the channel indicated by CHAIN_TO. Disable by setting CHAIN_TO = _(this channel)_. */
#define DMA_CH5_CTRL_TRIG_CHAIN_TO_Msb				14u
#define DMA_CH5_CTRL_TRIG_CHAIN_TO_Lsb				11u
	/* Select whether RING_SIZE applies to read or write addresses. */
#define DMA_CH5_CTRL_TRIG_RING_SEL				10u
	/* Size of address wrap region. If 0, don't wrap. For values n > 0, only the lower n bits of the address will change. This wraps the address on a (1 << n) byte boundary, facilitating access to naturally-aligned ring buffers. */
#define DMA_CH5_CTRL_TRIG_RING_SIZE_Msb				9u
#define DMA_CH5_CTRL_TRIG_RING_SIZE_Lsb				6u
#define DMA_CH5_CTRL_TRIG_RING_SIZE_RING_NONE			0u
	/* If 1, the write address increments with each transfer. */
#define DMA_CH5_CTRL_TRIG_INCR_WRITE				5u
	/* If 1, the read address increments with each transfer. */
#define DMA_CH5_CTRL_TRIG_INCR_READ				4u
	/* Set the size of each bus transfer (byte/halfword/word). READ_ADDR and WRITE_ADDR advance by this amount (1/2/4 bytes) with each transfer. */
#define DMA_CH5_CTRL_TRIG_DATA_SIZE_Msb				3u
#define DMA_CH5_CTRL_TRIG_DATA_SIZE_Lsb				2u
#define DMA_CH5_CTRL_TRIG_DATA_SIZE_SIZE_BYTE			0u
#define DMA_CH5_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD		1u
#define DMA_CH5_CTRL_TRIG_DATA_SIZE_SIZE_WORD			2u
	/* HIGH_PRIORITY gives a channel preferential treatment in issue scheduling: in each scheduling round, all high priority channels are considered first, and then only a single low priority channel, before returning to the high priority channels. */
#define DMA_CH5_CTRL_TRIG_HIGH_PRIORITY				1u
	/* DMA Channel Enable. */
#define DMA_CH5_CTRL_TRIG_EN					0u

	/* 0x150: Alias for channel 5 CTRL register */
	uint32_t volatile CH5_AL1_CTRL;

	/* 0x154: Alias for channel 5 READ_ADDR register */
	uint32_t volatile CH5_AL1_READ_ADDR;

	/* 0x158: Alias for channel 5 WRITE_ADDR register */
	uint32_t volatile CH5_AL1_WRITE_ADDR;

	/* 0x15C: Alias for channel 5 TRANS_COUNT register */
	uint32_t volatile CH5_AL1_TRANS_COUNT_TRIG;

	/* 0x160: Alias for channel 5 CTRL register */
	uint32_t volatile CH5_AL2_CTRL;

	/* 0x164: Alias for channel 5 TRANS_COUNT register */
	uint32_t volatile CH5_AL2_TRANS_COUNT;

	/* 0x168: Alias for channel 5 READ_ADDR register */
	uint32_t volatile CH5_AL2_READ_ADDR;

	/* 0x16C: Alias for channel 5 WRITE_ADDR register */
	uint32_t volatile CH5_AL2_WRITE_ADDR_TRIG;

	/* 0x170: Alias for channel 5 CTRL register */
	uint32_t volatile CH5_AL3_CTRL;

	/* 0x174: Alias for channel 5 WRITE_ADDR register */
	uint32_t volatile CH5_AL3_WRITE_ADDR;

	/* 0x178: Alias for channel 5 TRANS_COUNT register */
	uint32_t volatile CH5_AL3_TRANS_COUNT;

	/* 0x17C: Alias for channel 5 READ_ADDR register */
	uint32_t volatile CH5_AL3_READ_ADDR_TRIG;

	/* 0x180: DMA Channel 6 Read Address pointer */
	uint32_t volatile CH6_READ_ADDR;

	/* 0x184: DMA Channel 6 Write Address pointer */
	uint32_t volatile CH6_WRITE_ADDR;

	/* 0x188: DMA Channel 6 Transfer Count */
	uint32_t volatile CH6_TRANS_COUNT;

	/* 0x18C: DMA Channel 6 Control and Status */
	uint32_t volatile CH6_CTRL_TRIG;
	/* Logical OR of the READ_ERROR and WRITE_ERROR flags. */
#define DMA_CH6_CTRL_TRIG_AHB_ERROR				31u
	/* If 1, the channel received a read bus error. */
#define DMA_CH6_CTRL_TRIG_READ_ERROR				30u
	/* If 1, the channel received a write bus error. */
#define DMA_CH6_CTRL_TRIG_WRITE_ERROR				29u
	/* This flag goes high when the channel starts a new transfer sequence, and low when the last transfer of that sequence completes. */
#define DMA_CH6_CTRL_TRIG_BUSY					24u
	/* If 1, this channel's data transfers are visible to the sniff hardware, and each transfer will advance the state of the checksum. */
#define DMA_CH6_CTRL_TRIG_SNIFF_EN				23u
	/* Apply byte-swap transformation to DMA data. */
#define DMA_CH6_CTRL_TRIG_BSWAP					22u
	/* In QUIET mode, the channel does not generate IRQs at the end of every transfer block. */
#define DMA_CH6_CTRL_TRIG_IRQ_QUIET				21u
	/* Select a Transfer Request signal. */
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_Msb				20u
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_Lsb				15u
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_TIMER0			59u
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_TIMER1			60u
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_TIMER2			61u
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_TIMER3			62u
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PERMANENT			63u
	/* When this channel completes, it will trigger the channel indicated by CHAIN_TO. Disable by setting CHAIN_TO = _(this channel)_. */
#define DMA_CH6_CTRL_TRIG_CHAIN_TO_Msb				14u
#define DMA_CH6_CTRL_TRIG_CHAIN_TO_Lsb				11u
	/* Select whether RING_SIZE applies to read or write addresses. */
#define DMA_CH6_CTRL_TRIG_RING_SEL				10u
	/* Size of address wrap region. If 0, don't wrap. For values n > 0, only the lower n bits of the address will change. This wraps the address on a (1 << n) byte boundary, facilitating access to naturally-aligned ring buffers. */
#define DMA_CH6_CTRL_TRIG_RING_SIZE_Msb				9u
#define DMA_CH6_CTRL_TRIG_RING_SIZE_Lsb				6u
#define DMA_CH6_CTRL_TRIG_RING_SIZE_RING_NONE			0u
	/* If 1, the write address increments with each transfer. */
#define DMA_CH6_CTRL_TRIG_INCR_WRITE				5u
	/* If 1, the read address increments with each transfer. */
#define DMA_CH6_CTRL_TRIG_INCR_READ				4u
	/* Set the size of each bus transfer (byte/halfword/word). READ_ADDR and WRITE_ADDR advance by this amount (1/2/4 bytes) with each transfer. */
#define DMA_CH6_CTRL_TRIG_DATA_SIZE_Msb				3u
#define DMA_CH6_CTRL_TRIG_DATA_SIZE_Lsb				2u
#define DMA_CH6_CTRL_TRIG_DATA_SIZE_SIZE_BYTE			0u
#define DMA_CH6_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD		1u
#define DMA_CH6_CTRL_TRIG_DATA_SIZE_SIZE_WORD			2u
	/* HIGH_PRIORITY gives a channel preferential treatment in issue scheduling: in each scheduling round, all high priority channels are considered first, and then only a single low priority channel, before returning to the high priority channels. */
#define DMA_CH6_CTRL_TRIG_HIGH_PRIORITY				1u
	/* DMA Channel Enable. */
#define DMA_CH6_CTRL_TRIG_EN					0u

	/* 0x190: Alias for channel 6 CTRL register */
	uint32_t volatile CH6_AL1_CTRL;

	/* 0x194: Alias for channel 6 READ_ADDR register */
	uint32_t volatile CH6_AL1_READ_ADDR;

	/* 0x198: Alias for channel 6 WRITE_ADDR register */
	uint32_t volatile CH6_AL1_WRITE_ADDR;

	/* 0x19C: Alias for channel 6 TRANS_COUNT register */
	uint32_t volatile CH6_AL1_TRANS_COUNT_TRIG;

	/* 0x1A0: Alias for channel 6 CTRL register */
	uint32_t volatile CH6_AL2_CTRL;

	/* 0x1A4: Alias for channel 6 TRANS_COUNT register */
	uint32_t volatile CH6_AL2_TRANS_COUNT;

	/* 0x1A8: Alias for channel 6 READ_ADDR register */
	uint32_t volatile CH6_AL2_READ_ADDR;

	/* 0x1AC: Alias for channel 6 WRITE_ADDR register */
	uint32_t volatile CH6_AL2_WRITE_ADDR_TRIG;

	/* 0x1B0: Alias for channel 6 CTRL register */
	uint32_t volatile CH6_AL3_CTRL;

	/* 0x1B4: Alias for channel 6 WRITE_ADDR register */
	uint32_t volatile CH6_AL3_WRITE_ADDR;

	/* 0x1B8: Alias for channel 6 TRANS_COUNT register */
	uint32_t volatile CH6_AL3_TRANS_COUNT;

	/* 0x1BC: Alias for channel 6 READ_ADDR register */
	uint32_t volatile CH6_AL3_READ_ADDR_TRIG;

	/* 0x1C0: DMA Channel 7 Read Address pointer */
	uint32_t volatile CH7_READ_ADDR;

	/* 0x1C4: DMA Channel 7 Write Address pointer */
	uint32_t volatile CH7_WRITE_ADDR;

	/* 0x1C8: DMA Channel 7 Transfer Count */
	uint32_t volatile CH7_TRANS_COUNT;

	/* 0x1CC: DMA Channel 7 Control and Status */
	uint32_t volatile CH7_CTRL_TRIG;
	/* Logical OR of the READ_ERROR and WRITE_ERROR flags. */
#define DMA_CH7_CTRL_TRIG_AHB_ERROR				31u
	/* If 1, the channel received a read bus error. */
#define DMA_CH7_CTRL_TRIG_READ_ERROR				30u
	/* If 1, the channel received a write bus error. */
#define DMA_CH7_CTRL_TRIG_WRITE_ERROR				29u
	/* This flag goes high when the channel starts a new transfer sequence, and low when the last transfer of that sequence completes. */
#define DMA_CH7_CTRL_TRIG_BUSY					24u
	/* If 1, this channel's data transfers are visible to the sniff hardware, and each transfer will advance the state of the checksum. */
#define DMA_CH7_CTRL_TRIG_SNIFF_EN				23u
	/* Apply byte-swap transformation to DMA data. */
#define DMA_CH7_CTRL_TRIG_BSWAP					22u
	/* In QUIET mode, the channel does not generate IRQs at the end of every transfer block. */
#define DMA_CH7_CTRL_TRIG_IRQ_QUIET				21u
	/* Select a Transfer Request signal. */
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_Msb				20u
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_Lsb				15u
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_TIMER0			59u
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_TIMER1			60u
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_TIMER2			61u
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_TIMER3			62u
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PERMANENT			63u
	/* When this channel completes, it will trigger the channel indicated by CHAIN_TO. Disable by setting CHAIN_TO = _(this channel)_. */
#define DMA_CH7_CTRL_TRIG_CHAIN_TO_Msb				14u
#define DMA_CH7_CTRL_TRIG_CHAIN_TO_Lsb				11u
	/* Select whether RING_SIZE applies to read or write addresses. */
#define DMA_CH7_CTRL_TRIG_RING_SEL				10u
	/* Size of address wrap region. If 0, don't wrap. For values n > 0, only the lower n bits of the address will change. This wraps the address on a (1 << n) byte boundary, facilitating access to naturally-aligned ring buffers. */
#define DMA_CH7_CTRL_TRIG_RING_SIZE_Msb				9u
#define DMA_CH7_CTRL_TRIG_RING_SIZE_Lsb				6u
#define DMA_CH7_CTRL_TRIG_RING_SIZE_RING_NONE			0u
	/* If 1, the write address increments with each transfer. */
#define DMA_CH7_CTRL_TRIG_INCR_WRITE				5u
	/* If 1, the read address increments with each transfer. */
#define DMA_CH7_CTRL_TRIG_INCR_READ				4u
	/* Set the size of each bus transfer (byte/halfword/word). READ_ADDR and WRITE_ADDR advance by this amount (1/2/4 bytes) with each transfer. */
#define DMA_CH7_CTRL_TRIG_DATA_SIZE_Msb				3u
#define DMA_CH7_CTRL_TRIG_DATA_SIZE_Lsb				2u
#define DMA_CH7_CTRL_TRIG_DATA_SIZE_SIZE_BYTE			0u
#define DMA_CH7_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD		1u
#define DMA_CH7_CTRL_TRIG_DATA_SIZE_SIZE_WORD			2u
	/* HIGH_PRIORITY gives a channel preferential treatment in issue scheduling: in each scheduling round, all high priority channels are considered first, and then only a single low priority channel, before returning to the high priority channels. */
#define DMA_CH7_CTRL_TRIG_HIGH_PRIORITY				1u
	/* DMA Channel Enable. */
#define DMA_CH7_CTRL_TRIG_EN					0u

	/* 0x1D0: Alias for channel 7 CTRL register */
	uint32_t volatile CH7_AL1_CTRL;

	/* 0x1D4: Alias for channel 7 READ_ADDR register */
	uint32_t volatile CH7_AL1_READ_ADDR;

	/* 0x1D8: Alias for channel 7 WRITE_ADDR register */
	uint32_t volatile CH7_AL1_WRITE_ADDR;

	/* 0x1DC: Alias for channel 7 TRANS_COUNT register */
	uint32_t volatile CH7_AL1_TRANS_COUNT_TRIG;

	/* 0x1E0: Alias for channel 7 CTRL register */
	uint32_t volatile CH7_AL2_CTRL;

	/* 0x1E4: Alias for channel 7 TRANS_COUNT register */
	uint32_t volatile CH7_AL2_TRANS_COUNT;

	/* 0x1E8: Alias for channel 7 READ_ADDR register */
	uint32_t volatile CH7_AL2_READ_ADDR;

	/* 0x1EC: Alias for channel 7 WRITE_ADDR register */
	uint32_t volatile CH7_AL2_WRITE_ADDR_TRIG;

	/* 0x1F0: Alias for channel 7 CTRL register */
	uint32_t volatile CH7_AL3_CTRL;

	/* 0x1F4: Alias for channel 7 WRITE_ADDR register */
	uint32_t volatile CH7_AL3_WRITE_ADDR;

	/* 0x1F8: Alias for channel 7 TRANS_COUNT register */
	uint32_t volatile CH7_AL3_TRANS_COUNT;

	/* 0x1FC: Alias for channel 7 READ_ADDR register */
	uint32_t volatile CH7_AL3_READ_ADDR_TRIG;

	/* 0x200: DMA Channel 8 Read Address pointer */
	uint32_t volatile CH8_READ_ADDR;

	/* 0x204: DMA Channel 8 Write Address pointer */
	uint32_t volatile CH8_WRITE_ADDR;

	/* 0x208: DMA Channel 8 Transfer Count */
	uint32_t volatile CH8_TRANS_COUNT;

	/* 0x20C: DMA Channel 8 Control and Status */
	uint32_t volatile CH8_CTRL_TRIG;
	/* Logical OR of the READ_ERROR and WRITE_ERROR flags. */
#define DMA_CH8_CTRL_TRIG_AHB_ERROR				31u
	/* If 1, the channel received a read bus error. */
#define DMA_CH8_CTRL_TRIG_READ_ERROR				30u
	/* If 1, the channel received a write bus error. */
#define DMA_CH8_CTRL_TRIG_WRITE_ERROR				29u
	/* This flag goes high when the channel starts a new transfer sequence, and low when the last transfer of that sequence completes. */
#define DMA_CH8_CTRL_TRIG_BUSY					24u
	/* If 1, this channel's data transfers are visible to the sniff hardware, and each transfer will advance the state of the checksum. */
#define DMA_CH8_CTRL_TRIG_SNIFF_EN				23u
	/* Apply byte-swap transformation to DMA data. */
#define DMA_CH8_CTRL_TRIG_BSWAP					22u
	/* In QUIET mode, the channel does not generate IRQs at the end of every transfer block. */
#define DMA_CH8_CTRL_TRIG_IRQ_QUIET				21u
	/* Select a Transfer Request signal. */
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_Msb				20u
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_Lsb				15u
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_TIMER0			59u
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_TIMER1			60u
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_TIMER2			61u
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_TIMER3			62u
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PERMANENT			63u
	/* When this channel completes, it will trigger the channel indicated by CHAIN_TO. Disable by setting CHAIN_TO = _(this channel)_. */
#define DMA_CH8_CTRL_TRIG_CHAIN_TO_Msb				14u
#define DMA_CH8_CTRL_TRIG_CHAIN_TO_Lsb				11u
	/* Select whether RING_SIZE applies to read or write addresses. */
#define DMA_CH8_CTRL_TRIG_RING_SEL				10u
	/* Size of address wrap region. If 0, don't wrap. For values n > 0, only the lower n bits of the address will change. This wraps the address on a (1 << n) byte boundary, facilitating access to naturally-aligned ring buffers. */
#define DMA_CH8_CTRL_TRIG_RING_SIZE_Msb				9u
#define DMA_CH8_CTRL_TRIG_RING_SIZE_Lsb				6u
#define DMA_CH8_CTRL_TRIG_RING_SIZE_RING_NONE			0u
	/* If 1, the write address increments with each transfer. */
#define DMA_CH8_CTRL_TRIG_INCR_WRITE				5u
	/* If 1, the read address increments with each transfer. */
#define DMA_CH8_CTRL_TRIG_INCR_READ				4u
	/* Set the size of each bus transfer (byte/halfword/word). READ_ADDR and WRITE_ADDR advance by this amount (1/2/4 bytes) with each transfer. */
#define DMA_CH8_CTRL_TRIG_DATA_SIZE_Msb				3u
#define DMA_CH8_CTRL_TRIG_DATA_SIZE_Lsb				2u
#define DMA_CH8_CTRL_TRIG_DATA_SIZE_SIZE_BYTE			0u
#define DMA_CH8_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD		1u
#define DMA_CH8_CTRL_TRIG_DATA_SIZE_SIZE_WORD			2u
	/* HIGH_PRIORITY gives a channel preferential treatment in issue scheduling: in each scheduling round, all high priority channels are considered first, and then only a single low priority channel, before returning to the high priority channels. */
#define DMA_CH8_CTRL_TRIG_HIGH_PRIORITY				1u
	/* DMA Channel Enable. */
#define DMA_CH8_CTRL_TRIG_EN					0u

	/* 0x210: Alias for channel 8 CTRL register */
	uint32_t volatile CH8_AL1_CTRL;

	/* 0x214: Alias for channel 8 READ_ADDR register */
	uint32_t volatile CH8_AL1_READ_ADDR;

	/* 0x218: Alias for channel 8 WRITE_ADDR register */
	uint32_t volatile CH8_AL1_WRITE_ADDR;

	/* 0x21C: Alias for channel 8 TRANS_COUNT register */
	uint32_t volatile CH8_AL1_TRANS_COUNT_TRIG;

	/* 0x220: Alias for channel 8 CTRL register */
	uint32_t volatile CH8_AL2_CTRL;

	/* 0x224: Alias for channel 8 TRANS_COUNT register */
	uint32_t volatile CH8_AL2_TRANS_COUNT;

	/* 0x228: Alias for channel 8 READ_ADDR register */
	uint32_t volatile CH8_AL2_READ_ADDR;

	/* 0x22C: Alias for channel 8 WRITE_ADDR register */
	uint32_t volatile CH8_AL2_WRITE_ADDR_TRIG;

	/* 0x230: Alias for channel 8 CTRL register */
	uint32_t volatile CH8_AL3_CTRL;

	/* 0x234: Alias for channel 8 WRITE_ADDR register */
	uint32_t volatile CH8_AL3_WRITE_ADDR;

	/* 0x238: Alias for channel 8 TRANS_COUNT register */
	uint32_t volatile CH8_AL3_TRANS_COUNT;

	/* 0x23C: Alias for channel 8 READ_ADDR register */
	uint32_t volatile CH8_AL3_READ_ADDR_TRIG;

	/* 0x240: DMA Channel 9 Read Address pointer */
	uint32_t volatile CH9_READ_ADDR;

	/* 0x244: DMA Channel 9 Write Address pointer */
	uint32_t volatile CH9_WRITE_ADDR;

	/* 0x248: DMA Channel 9 Transfer Count */
	uint32_t volatile CH9_TRANS_COUNT;

	/* 0x24C: DMA Channel 9 Control and Status */
	uint32_t volatile CH9_CTRL_TRIG;
	/* Logical OR of the READ_ERROR and WRITE_ERROR flags. */
#define DMA_CH9_CTRL_TRIG_AHB_ERROR				31u
	/* If 1, the channel received a read bus error. */
#define DMA_CH9_CTRL_TRIG_READ_ERROR				30u
	/* If 1, the channel received a write bus error. */
#define DMA_CH9_CTRL_TRIG_WRITE_ERROR				29u
	/* This flag goes high when the channel starts a new transfer sequence, and low when the last transfer of that sequence completes. */
#define DMA_CH9_CTRL_TRIG_BUSY					24u
	/* If 1, this channel's data transfers are visible to the sniff hardware, and each transfer will advance the state of the checksum. */
#define DMA_CH9_CTRL_TRIG_SNIFF_EN				23u
	/* Apply byte-swap transformation to DMA data. */
#define DMA_CH9_CTRL_TRIG_BSWAP					22u
	/* In QUIET mode, the channel does not generate IRQs at the end of every transfer block. */
#define DMA_CH9_CTRL_TRIG_IRQ_QUIET				21u
	/* Select a Transfer Request signal. */
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_Msb				20u
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_Lsb				15u
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_TIMER0			59u
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_TIMER1			60u
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_TIMER2			61u
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_TIMER3			62u
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PERMANENT			63u
	/* When this channel completes, it will trigger the channel indicated by CHAIN_TO. Disable by setting CHAIN_TO = _(this channel)_. */
#define DMA_CH9_CTRL_TRIG_CHAIN_TO_Msb				14u
#define DMA_CH9_CTRL_TRIG_CHAIN_TO_Lsb				11u
	/* Select whether RING_SIZE applies to read or write addresses. */
#define DMA_CH9_CTRL_TRIG_RING_SEL				10u
	/* Size of address wrap region. If 0, don't wrap. For values n > 0, only the lower n bits of the address will change. This wraps the address on a (1 << n) byte boundary, facilitating access to naturally-aligned ring buffers. */
#define DMA_CH9_CTRL_TRIG_RING_SIZE_Msb				9u
#define DMA_CH9_CTRL_TRIG_RING_SIZE_Lsb				6u
#define DMA_CH9_CTRL_TRIG_RING_SIZE_RING_NONE			0u
	/* If 1, the write address increments with each transfer. */
#define DMA_CH9_CTRL_TRIG_INCR_WRITE				5u
	/* If 1, the read address increments with each transfer. */
#define DMA_CH9_CTRL_TRIG_INCR_READ				4u
	/* Set the size of each bus transfer (byte/halfword/word). READ_ADDR and WRITE_ADDR advance by this amount (1/2/4 bytes) with each transfer. */
#define DMA_CH9_CTRL_TRIG_DATA_SIZE_Msb				3u
#define DMA_CH9_CTRL_TRIG_DATA_SIZE_Lsb				2u
#define DMA_CH9_CTRL_TRIG_DATA_SIZE_SIZE_BYTE			0u
#define DMA_CH9_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD		1u
#define DMA_CH9_CTRL_TRIG_DATA_SIZE_SIZE_WORD			2u
	/* HIGH_PRIORITY gives a channel preferential treatment in issue scheduling: in each scheduling round, all high priority channels are considered first, and then only a single low priority channel, before returning to the high priority channels. */
#define DMA_CH9_CTRL_TRIG_HIGH_PRIORITY				1u
	/* DMA Channel Enable. */
#define DMA_CH9_CTRL_TRIG_EN					0u

	/* 0x250: Alias for channel 9 CTRL register */
	uint32_t volatile CH9_AL1_CTRL;

	/* 0x254: Alias for channel 9 READ_ADDR register */
	uint32_t volatile CH9_AL1_READ_ADDR;

	/* 0x258: Alias for channel 9 WRITE_ADDR register */
	uint32_t volatile CH9_AL1_WRITE_ADDR;

	/* 0x25C: Alias for channel 9 TRANS_COUNT register */
	uint32_t volatile CH9_AL1_TRANS_COUNT_TRIG;

	/* 0x260: Alias for channel 9 CTRL register */
	uint32_t volatile CH9_AL2_CTRL;

	/* 0x264: Alias for channel 9 TRANS_COUNT register */
	uint32_t volatile CH9_AL2_TRANS_COUNT;

	/* 0x268: Alias for channel 9 READ_ADDR register */
	uint32_t volatile CH9_AL2_READ_ADDR;

	/* 0x26C: Alias for channel 9 WRITE_ADDR register */
	uint32_t volatile CH9_AL2_WRITE_ADDR_TRIG;

	/* 0x270: Alias for channel 9 CTRL register */
	uint32_t volatile CH9_AL3_CTRL;

	/* 0x274: Alias for channel 9 WRITE_ADDR register */
	uint32_t volatile CH9_AL3_WRITE_ADDR;

	/* 0x278: Alias for channel 9 TRANS_COUNT register */
	uint32_t volatile CH9_AL3_TRANS_COUNT;

	/* 0x27C: Alias for channel 9 READ_ADDR register */
	uint32_t volatile CH9_AL3_READ_ADDR_TRIG;

	/* 0x280: DMA Channel 10 Read Address pointer */
	uint32_t volatile CH10_READ_ADDR;

	/* 0x284: DMA Channel 10 Write Address pointer */
	uint32_t volatile CH10_WRITE_ADDR;

	/* 0x288: DMA Channel 10 Transfer Count */
	uint32_t volatile CH10_TRANS_COUNT;

	/* 0x28C: DMA Channel 10 Control and Status */
	uint32_t volatile CH10_CTRL_TRIG;
	/* Logical OR of the READ_ERROR and WRITE_ERROR flags. */
#define DMA_CH10_CTRL_TRIG_AHB_ERROR				31u
	/* If 1, the channel received a read bus error. */
#define DMA_CH10_CTRL_TRIG_READ_ERROR				30u
	/* If 1, the channel received a write bus error. */
#define DMA_CH10_CTRL_TRIG_WRITE_ERROR				29u
	/* This flag goes high when the channel starts a new transfer sequence, and low when the last transfer of that sequence completes. */
#define DMA_CH10_CTRL_TRIG_BUSY					24u
	/* If 1, this channel's data transfers are visible to the sniff hardware, and each transfer will advance the state of the checksum. */
#define DMA_CH10_CTRL_TRIG_SNIFF_EN				23u
	/* Apply byte-swap transformation to DMA data. */
#define DMA_CH10_CTRL_TRIG_BSWAP				22u
	/* In QUIET mode, the channel does not generate IRQs at the end of every transfer block. */
#define DMA_CH10_CTRL_TRIG_IRQ_QUIET				21u
	/* Select a Transfer Request signal. */
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_Msb				20u
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_Lsb				15u
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_TIMER0			59u
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_TIMER1			60u
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_TIMER2			61u
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_TIMER3			62u
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PERMANENT			63u
	/* When this channel completes, it will trigger the channel indicated by CHAIN_TO. Disable by setting CHAIN_TO = _(this channel)_. */
#define DMA_CH10_CTRL_TRIG_CHAIN_TO_Msb				14u
#define DMA_CH10_CTRL_TRIG_CHAIN_TO_Lsb				11u
	/* Select whether RING_SIZE applies to read or write addresses. */
#define DMA_CH10_CTRL_TRIG_RING_SEL				10u
	/* Size of address wrap region. If 0, don't wrap. For values n > 0, only the lower n bits of the address will change. This wraps the address on a (1 << n) byte boundary, facilitating access to naturally-aligned ring buffers. */
#define DMA_CH10_CTRL_TRIG_RING_SIZE_Msb			9u
#define DMA_CH10_CTRL_TRIG_RING_SIZE_Lsb			6u
#define DMA_CH10_CTRL_TRIG_RING_SIZE_RING_NONE			0u
	/* If 1, the write address increments with each transfer. */
#define DMA_CH10_CTRL_TRIG_INCR_WRITE				5u
	/* If 1, the read address increments with each transfer. */
#define DMA_CH10_CTRL_TRIG_INCR_READ				4u
	/* Set the size of each bus transfer (byte/halfword/word). READ_ADDR and WRITE_ADDR advance by this amount (1/2/4 bytes) with each transfer. */
#define DMA_CH10_CTRL_TRIG_DATA_SIZE_Msb			3u
#define DMA_CH10_CTRL_TRIG_DATA_SIZE_Lsb			2u
#define DMA_CH10_CTRL_TRIG_DATA_SIZE_SIZE_BYTE			0u
#define DMA_CH10_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD		1u
#define DMA_CH10_CTRL_TRIG_DATA_SIZE_SIZE_WORD			2u
	/* HIGH_PRIORITY gives a channel preferential treatment in issue scheduling: in each scheduling round, all high priority channels are considered first, and then only a single low priority channel, before returning to the high priority channels. */
#define DMA_CH10_CTRL_TRIG_HIGH_PRIORITY			1u
	/* DMA Channel Enable. */
#define DMA_CH10_CTRL_TRIG_EN					0u

	/* 0x290: Alias for channel 10 CTRL register */
	uint32_t volatile CH10_AL1_CTRL;

	/* 0x294: Alias for channel 10 READ_ADDR register */
	uint32_t volatile CH10_AL1_READ_ADDR;

	/* 0x298: Alias for channel 10 WRITE_ADDR register */
	uint32_t volatile CH10_AL1_WRITE_ADDR;

	/* 0x29C: Alias for channel 10 TRANS_COUNT register */
	uint32_t volatile CH10_AL1_TRANS_COUNT_TRIG;

	/* 0x2A0: Alias for channel 10 CTRL register */
	uint32_t volatile CH10_AL2_CTRL;

	/* 0x2A4: Alias for channel 10 TRANS_COUNT register */
	uint32_t volatile CH10_AL2_TRANS_COUNT;

	/* 0x2A8: Alias for channel 10 READ_ADDR register */
	uint32_t volatile CH10_AL2_READ_ADDR;

	/* 0x2AC: Alias for channel 10 WRITE_ADDR register */
	uint32_t volatile CH10_AL2_WRITE_ADDR_TRIG;

	/* 0x2B0: Alias for channel 10 CTRL register */
	uint32_t volatile CH10_AL3_CTRL;

	/* 0x2B4: Alias for channel 10 WRITE_ADDR register */
	uint32_t volatile CH10_AL3_WRITE_ADDR;

	/* 0x2B8: Alias for channel 10 TRANS_COUNT register */
	uint32_t volatile CH10_AL3_TRANS_COUNT;

	/* 0x2BC: Alias for channel 10 READ_ADDR register */
	uint32_t volatile CH10_AL3_READ_ADDR_TRIG;

	/* 0x2C0: DMA Channel 11 Read Address pointer */
	uint32_t volatile CH11_READ_ADDR;

	/* 0x2C4: DMA Channel 11 Write Address pointer */
	uint32_t volatile CH11_WRITE_ADDR;

	/* 0x2C8: DMA Channel 11 Transfer Count */
	uint32_t volatile CH11_TRANS_COUNT;

	/* 0x2CC: DMA Channel 11 Control and Status */
	uint32_t volatile CH11_CTRL_TRIG;
	/* Logical OR of the READ_ERROR and WRITE_ERROR flags. */
#define DMA_CH11_CTRL_TRIG_AHB_ERROR				31u
	/* If 1, the channel received a read bus error. */
#define DMA_CH11_CTRL_TRIG_READ_ERROR				30u
	/* If 1, the channel received a write bus error. */
#define DMA_CH11_CTRL_TRIG_WRITE_ERROR				29u
	/* This flag goes high when the channel starts a new transfer sequence, and low when the last transfer of that sequence completes. */
#define DMA_CH11_CTRL_TRIG_BUSY					24u
	/* If 1, this channel's data transfers are visible to the sniff hardware, and each transfer will advance the state of the checksum. */
#define DMA_CH11_CTRL_TRIG_SNIFF_EN				23u
	/* Apply byte-swap transformation to DMA data. */
#define DMA_CH11_CTRL_TRIG_BSWAP				22u
	/* In QUIET mode, the channel does not generate IRQs at the end of every transfer block. */
#define DMA_CH11_CTRL_TRIG_IRQ_QUIET				21u
	/* Select a Transfer Request signal. */
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_Msb				20u
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_Lsb				15u
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_TIMER0			59u
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_TIMER1			60u
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_TIMER2			61u
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_TIMER3			62u
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PERMANENT			63u
	/* When this channel completes, it will trigger the channel indicated by CHAIN_TO. Disable by setting CHAIN_TO = _(this channel)_. */
#define DMA_CH11_CTRL_TRIG_CHAIN_TO_Msb				14u
#define DMA_CH11_CTRL_TRIG_CHAIN_TO_Lsb				11u
	/* Select whether RING_SIZE applies to read or write addresses. */
#define DMA_CH11_CTRL_TRIG_RING_SEL				10u
	/* Size of address wrap region. If 0, don't wrap. For values n > 0, only the lower n bits of the address will change. This wraps the address on a (1 << n) byte boundary, facilitating access to naturally-aligned ring buffers. */
#define DMA_CH11_CTRL_TRIG_RING_SIZE_Msb			9u
#define DMA_CH11_CTRL_TRIG_RING_SIZE_Lsb			6u
#define DMA_CH11_CTRL_TRIG_RING_SIZE_RING_NONE			0u
	/* If 1, the write address increments with each transfer. */
#define DMA_CH11_CTRL_TRIG_INCR_WRITE				5u
	/* If 1, the read address increments with each transfer. */
#define DMA_CH11_CTRL_TRIG_INCR_READ				4u
	/* Set the size of each bus transfer (byte/halfword/word). READ_ADDR and WRITE_ADDR advance by this amount (1/2/4 bytes) with each transfer. */
#define DMA_CH11_CTRL_TRIG_DATA_SIZE_Msb			3u
#define DMA_CH11_CTRL_TRIG_DATA_SIZE_Lsb			2u
#define DMA_CH11_CTRL_TRIG_DATA_SIZE_SIZE_BYTE			0u
#define DMA_CH11_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD		1u
#define DMA_CH11_CTRL_TRIG_DATA_SIZE_SIZE_WORD			2u
	/* HIGH_PRIORITY gives a channel preferential treatment in issue scheduling: in each scheduling round, all high priority channels are considered first, and then only a single low priority channel, before returning to the high priority channels. */
#define DMA_CH11_CTRL_TRIG_HIGH_PRIORITY			1u
	/* DMA Channel Enable. */
#define DMA_CH11_CTRL_TRIG_EN					0u

	/* 0x2D0: Alias for channel 11 CTRL register */
	uint32_t volatile CH11_AL1_CTRL;

	/* 0x2D4: Alias for channel 11 READ_ADDR register */
	uint32_t volatile CH11_AL1_READ_ADDR;

	/* 0x2D8: Alias for channel 11 WRITE_ADDR register */
	uint32_t volatile CH11_AL1_WRITE_ADDR;

	/* 0x2DC: Alias for channel 11 TRANS_COUNT register */
	uint32_t volatile CH11_AL1_TRANS_COUNT_TRIG;

	/* 0x2E0: Alias for channel 11 CTRL register */
	uint32_t volatile CH11_AL2_CTRL;

	/* 0x2E4: Alias for channel 11 TRANS_COUNT register */
	uint32_t volatile CH11_AL2_TRANS_COUNT;

	/* 0x2E8: Alias for channel 11 READ_ADDR register */
	uint32_t volatile CH11_AL2_READ_ADDR;

	/* 0x2EC: Alias for channel 11 WRITE_ADDR register */
	uint32_t volatile CH11_AL2_WRITE_ADDR_TRIG;

	/* 0x2F0: Alias for channel 11 CTRL register */
	uint32_t volatile CH11_AL3_CTRL;

	/* 0x2F4: Alias for channel 11 WRITE_ADDR register */
	uint32_t volatile CH11_AL3_WRITE_ADDR;

	/* 0x2F8: Alias for channel 11 TRANS_COUNT register */
	uint32_t volatile CH11_AL3_TRANS_COUNT;

	/* 0x2FC: Alias for channel 11 READ_ADDR register */
	uint32_t volatile CH11_AL3_READ_ADDR_TRIG;

	/* 0x300 */
	uint8_t RESERVED0[0x400-0x300];

	/* 0x400: Interrupt Status (raw) */
	uint32_t volatile INTR;
	/* Raw interrupt status for DMA Channels 0..15. */
#define DMA_INTR_INTR_Msb					15u
#define DMA_INTR_INTR_Lsb					0u

	/* 0x404: Interrupt Enables for IRQ 0 */
	uint32_t volatile INTE0;
	/* Set bit n to pass interrupts from channel n to DMA IRQ 0. */
#define DMA_INTE0_INTE0_Msb					15u
#define DMA_INTE0_INTE0_Lsb					0u

	/* 0x408: Force Interrupts */
	uint32_t volatile INTF0;
	/* Write 1s to force the corresponding bits in INTE0. */
#define DMA_INTF0_INTF0_Msb					15u
#define DMA_INTF0_INTF0_Lsb					0u

	/* 0x40C: Interrupt Status for IRQ 0 */
	uint32_t volatile INTS0;
	/* Indicates active channel interrupt requests which are currently causing IRQ 0 to be asserted. */
#define DMA_INTS0_INTS0_Msb					15u
#define DMA_INTS0_INTS0_Lsb					0u

	/* 0x410 */
	uint8_t RESERVED1[0x414-0x410];

	/* 0x414: Interrupt Enables for IRQ 1 */
	uint32_t volatile INTE1;
	/* Set bit n to pass interrupts from channel n to DMA IRQ 1. */
#define DMA_INTE1_INTE1_Msb					15u
#define DMA_INTE1_INTE1_Lsb					0u

	/* 0x418: Force Interrupts for IRQ 1 */
	uint32_t volatile INTF1;
	/* Write 1s to force the corresponding bits in INTE0. */
#define DMA_INTF1_INTF1_Msb					15u
#define DMA_INTF1_INTF1_Lsb					0u

	/* 0x41C: Interrupt Status (masked) for IRQ 1 */
	uint32_t volatile INTS1;
	/* Indicates active channel interrupt requests which are currently causing IRQ 1 to be asserted. */
#define DMA_INTS1_INTS1_Msb					15u
#define DMA_INTS1_INTS1_Lsb					0u

	/* 0x420: Pacing (X/Y) Fractional Timer */
	uint32_t volatile TIMER0;
	/* Pacing Timer Dividend. Specifies the X value for the (X/Y) fractional timer. */
#define DMA_TIMER0_X_Msb					31u
#define DMA_TIMER0_X_Lsb					16u
	/* Pacing Timer Divisor. Specifies the Y value for the (X/Y) fractional timer. */
#define DMA_TIMER0_Y_Msb					15u
#define DMA_TIMER0_Y_Lsb					0u

	/* 0x424: Pacing (X/Y) Fractional Timer */
	uint32_t volatile TIMER1;
	/* Pacing Timer Dividend. Specifies the X value for the (X/Y) fractional timer. */
#define DMA_TIMER1_X_Msb					31u
#define DMA_TIMER1_X_Lsb					16u
	/* Pacing Timer Divisor. Specifies the Y value for the (X/Y) fractional timer. */
#define DMA_TIMER1_Y_Msb					15u
#define DMA_TIMER1_Y_Lsb					0u

	/* 0x428: Pacing (X/Y) Fractional Timer */
	uint32_t volatile TIMER2;
	/* Pacing Timer Dividend. Specifies the X value for the (X/Y) fractional timer. */
#define DMA_TIMER2_X_Msb					31u
#define DMA_TIMER2_X_Lsb					16u
	/* Pacing Timer Divisor. Specifies the Y value for the (X/Y) fractional timer. */
#define DMA_TIMER2_Y_Msb					15u
#define DMA_TIMER2_Y_Lsb					0u

	/* 0x42C: Pacing (X/Y) Fractional Timer */
	uint32_t volatile TIMER3;
	/* Pacing Timer Dividend. Specifies the X value for the (X/Y) fractional timer. */
#define DMA_TIMER3_X_Msb					31u
#define DMA_TIMER3_X_Lsb					16u
	/* Pacing Timer Divisor. Specifies the Y value for the (X/Y) fractional timer. */
#define DMA_TIMER3_Y_Msb					15u
#define DMA_TIMER3_Y_Lsb					0u

	/* 0x430: Trigger one or more channels simultaneously */
	uint32_t volatile MULTI_CHAN_TRIGGER;
	/* Each bit in this register corresponds to a DMA channel. */
#define DMA_MULTI_CHAN_TRIGGER_MULTI_CHAN_TRIGGER_Msb		15u
#define DMA_MULTI_CHAN_TRIGGER_MULTI_CHAN_TRIGGER_Lsb		0u

	/* 0x434: Sniffer Control */
	uint32_t volatile SNIFF_CTRL;
	/* If set, the result appears inverted (bitwise complement) when read. */
#define DMA_SNIFF_CTRL_OUT_INV					11u
	/* If set, the result appears bit-reversed when read. */
#define DMA_SNIFF_CTRL_OUT_REV					10u
	/* Locally perform a byte reverse on the sniffed data, before feeding into checksum. */
#define DMA_SNIFF_CTRL_BSWAP					9u
	/*  */
#define DMA_SNIFF_CTRL_CALC_Msb					8u
#define DMA_SNIFF_CTRL_CALC_Lsb					5u
#define DMA_SNIFF_CTRL_CALC_CRC32				0u
#define DMA_SNIFF_CTRL_CALC_CRC32R				1u
#define DMA_SNIFF_CTRL_CALC_CRC16				2u
#define DMA_SNIFF_CTRL_CALC_CRC16R				3u
#define DMA_SNIFF_CTRL_CALC_EVEN				14u
#define DMA_SNIFF_CTRL_CALC_SUM					15u
	/* DMA channel for Sniffer to observe */
#define DMA_SNIFF_CTRL_DMACH_Msb				4u
#define DMA_SNIFF_CTRL_DMACH_Lsb				1u
	/* Enable sniffer */
#define DMA_SNIFF_CTRL_EN					0u

	/* 0x438: Data accumulator for sniff hardware */
	uint32_t volatile SNIFF_DATA;

	/* 0x43C */
	uint8_t RESERVED2[0x440-0x43C];

	/* 0x440: Debug RAF, WAF, TDF levels */
	uint32_t volatile FIFO_LEVELS;
	/* Current Read-Address-FIFO fill level */
#define DMA_FIFO_LEVELS_RAF_LVL_Msb				23u
#define DMA_FIFO_LEVELS_RAF_LVL_Lsb				16u
	/* Current Write-Address-FIFO fill level */
#define DMA_FIFO_LEVELS_WAF_LVL_Msb				15u
#define DMA_FIFO_LEVELS_WAF_LVL_Lsb				8u
	/* Current Transfer-Data-FIFO fill level */
#define DMA_FIFO_LEVELS_TDF_LVL_Msb				7u
#define DMA_FIFO_LEVELS_TDF_LVL_Lsb				0u

	/* 0x444: Abort an in-progress transfer sequence on one or more channels */
	uint32_t volatile CHAN_ABORT;
	/* Each bit corresponds to a channel. */
#define DMA_CHAN_ABORT_CHAN_ABORT_Msb				15u
#define DMA_CHAN_ABORT_CHAN_ABORT_Lsb				0u

	/* 0x448: The number of channels this DMA instance is equipped with. */
	uint32_t volatile N_CHANNELS;
	/*  */
#define DMA_N_CHANNELS_N_CHANNELS_Msb				4u
#define DMA_N_CHANNELS_N_CHANNELS_Lsb				0u

	/* 0x44C */
	uint8_t RESERVED3[0x800-0x44C];

	/* 0x800: Read: get channel DREQ counter (i.e. */
	uint32_t volatile CH0_DBG_CTDREQ;
	/*  */
#define DMA_CH0_DBG_CTDREQ_CH0_DBG_CTDREQ_Msb			5u
#define DMA_CH0_DBG_CTDREQ_CH0_DBG_CTDREQ_Lsb			0u

	/* 0x804: Read to get channel TRANS_COUNT reload value, i.e. */
	uint32_t volatile CH0_DBG_TCR;

	/* 0x808 */
	uint8_t RESERVED4[0x840-0x808];

	/* 0x840: Read: get channel DREQ counter (i.e. */
	uint32_t volatile CH1_DBG_CTDREQ;
	/*  */
#define DMA_CH1_DBG_CTDREQ_CH1_DBG_CTDREQ_Msb			5u
#define DMA_CH1_DBG_CTDREQ_CH1_DBG_CTDREQ_Lsb			0u

	/* 0x844: Read to get channel TRANS_COUNT reload value, i.e. */
	uint32_t volatile CH1_DBG_TCR;

	/* 0x848 */
	uint8_t RESERVED5[0x880-0x848];

	/* 0x880: Read: get channel DREQ counter (i.e. */
	uint32_t volatile CH2_DBG_CTDREQ;
	/*  */
#define DMA_CH2_DBG_CTDREQ_CH2_DBG_CTDREQ_Msb			5u
#define DMA_CH2_DBG_CTDREQ_CH2_DBG_CTDREQ_Lsb			0u

	/* 0x884: Read to get channel TRANS_COUNT reload value, i.e. */
	uint32_t volatile CH2_DBG_TCR;

	/* 0x888 */
	uint8_t RESERVED6[0x8C0-0x888];

	/* 0x8C0: Read: get channel DREQ counter (i.e. */
	uint32_t volatile CH3_DBG_CTDREQ;
	/*  */
#define DMA_CH3_DBG_CTDREQ_CH3_DBG_CTDREQ_Msb			5u
#define DMA_CH3_DBG_CTDREQ_CH3_DBG_CTDREQ_Lsb			0u

	/* 0x8C4: Read to get channel TRANS_COUNT reload value, i.e. */
	uint32_t volatile CH3_DBG_TCR;

	/* 0x8C8 */
	uint8_t RESERVED7[0x900-0x8C8];

	/* 0x900: Read: get channel DREQ counter (i.e. */
	uint32_t volatile CH4_DBG_CTDREQ;
	/*  */
#define DMA_CH4_DBG_CTDREQ_CH4_DBG_CTDREQ_Msb			5u
#define DMA_CH4_DBG_CTDREQ_CH4_DBG_CTDREQ_Lsb			0u

	/* 0x904: Read to get channel TRANS_COUNT reload value, i.e. */
	uint32_t volatile CH4_DBG_TCR;

	/* 0x908 */
	uint8_t RESERVED8[0x940-0x908];

	/* 0x940: Read: get channel DREQ counter (i.e. */
	uint32_t volatile CH5_DBG_CTDREQ;
	/*  */
#define DMA_CH5_DBG_CTDREQ_CH5_DBG_CTDREQ_Msb			5u
#define DMA_CH5_DBG_CTDREQ_CH5_DBG_CTDREQ_Lsb			0u

	/* 0x944: Read to get channel TRANS_COUNT reload value, i.e. */
	uint32_t volatile CH5_DBG_TCR;

	/* 0x948 */
	uint8_t RESERVED9[0x980-0x948];

	/* 0x980: Read: get channel DREQ counter (i.e. */
	uint32_t volatile CH6_DBG_CTDREQ;
	/*  */
#define DMA_CH6_DBG_CTDREQ_CH6_DBG_CTDREQ_Msb			5u
#define DMA_CH6_DBG_CTDREQ_CH6_DBG_CTDREQ_Lsb			0u

	/* 0x984: Read to get channel TRANS_COUNT reload value, i.e. */
	uint32_t volatile CH6_DBG_TCR;

	/* 0x988 */
	uint8_t RESERVED10[0x9C0-0x988];

	/* 0x9C0: Read: get channel DREQ counter (i.e. */
	uint32_t volatile CH7_DBG_CTDREQ;
	/*  */
#define DMA_CH7_DBG_CTDREQ_CH7_DBG_CTDREQ_Msb			5u
#define DMA_CH7_DBG_CTDREQ_CH7_DBG_CTDREQ_Lsb			0u

	/* 0x9C4: Read to get channel TRANS_COUNT reload value, i.e. */
	uint32_t volatile CH7_DBG_TCR;

	/* 0x9C8 */
	uint8_t RESERVED11[0xA00-0x9C8];

	/* 0xA00: Read: get channel DREQ counter (i.e. */
	uint32_t volatile CH8_DBG_CTDREQ;
	/*  */
#define DMA_CH8_DBG_CTDREQ_CH8_DBG_CTDREQ_Msb			5u
#define DMA_CH8_DBG_CTDREQ_CH8_DBG_CTDREQ_Lsb			0u

	/* 0xA04: Read to get channel TRANS_COUNT reload value, i.e. */
	uint32_t volatile CH8_DBG_TCR;

	/* 0xA08 */
	uint8_t RESERVED12[0xA40-0xA08];

	/* 0xA40: Read: get channel DREQ counter (i.e. */
	uint32_t volatile CH9_DBG_CTDREQ;
	/*  */
#define DMA_CH9_DBG_CTDREQ_CH9_DBG_CTDREQ_Msb			5u
#define DMA_CH9_DBG_CTDREQ_CH9_DBG_CTDREQ_Lsb			0u

	/* 0xA44: Read to get channel TRANS_COUNT reload value, i.e. */
	uint32_t volatile CH9_DBG_TCR;

	/* 0xA48 */
	uint8_t RESERVED13[0xA80-0xA48];

	/* 0xA80: Read: get channel DREQ counter (i.e. */
	uint32_t volatile CH10_DBG_CTDREQ;
	/*  */
#define DMA_CH10_DBG_CTDREQ_CH10_DBG_CTDREQ_Msb			5u
#define DMA_CH10_DBG_CTDREQ_CH10_DBG_CTDREQ_Lsb			0u

	/* 0xA84: Read to get channel TRANS_COUNT reload value, i.e. */
	uint32_t volatile CH10_DBG_TCR;

	/* 0xA88 */
	uint8_t RESERVED14[0xAC0-0xA88];

	/* 0xAC0: Read: get channel DREQ counter (i.e. */
	uint32_t volatile CH11_DBG_CTDREQ;
	/*  */
#define DMA_CH11_DBG_CTDREQ_CH11_DBG_CTDREQ_Msb			5u
#define DMA_CH11_DBG_CTDREQ_CH11_DBG_CTDREQ_Lsb			0u

	/* 0xAC4: Read to get channel TRANS_COUNT reload value, i.e. */
	uint32_t volatile CH11_DBG_TCR;

};


#define USBCTRL_DPRAM ((struct sdk_usbctrl_dpram *)0x50100000)

struct sdk_usbctrl_dpram {

	/* 0x00: Bytes 0-3 of the SETUP packet from the host. */
	uint32_t volatile SETUP_PACKET_LOW;
	/*  */
#define USBCTRL_DPRAM_SETUP_PACKET_LOW_WVALUE_Msb		31u
#define USBCTRL_DPRAM_SETUP_PACKET_LOW_WVALUE_Lsb		16u
	/*  */
#define USBCTRL_DPRAM_SETUP_PACKET_LOW_BREQUEST_Msb		15u
#define USBCTRL_DPRAM_SETUP_PACKET_LOW_BREQUEST_Lsb		8u
	/*  */
#define USBCTRL_DPRAM_SETUP_PACKET_LOW_BMREQUESTTYPE_Msb	7u
#define USBCTRL_DPRAM_SETUP_PACKET_LOW_BMREQUESTTYPE_Lsb	0u

	/* 0x04: Bytes 4-7 of the setup packet from the host. */
	uint32_t volatile SETUP_PACKET_HIGH;
	/*  */
#define USBCTRL_DPRAM_SETUP_PACKET_HIGH_WLENGTH_Msb		31u
#define USBCTRL_DPRAM_SETUP_PACKET_HIGH_WLENGTH_Lsb		16u
	/*  */
#define USBCTRL_DPRAM_SETUP_PACKET_HIGH_WINDEX_Msb		15u
#define USBCTRL_DPRAM_SETUP_PACKET_HIGH_WINDEX_Lsb		0u

	/* 0x08:  */
	uint32_t volatile EP1_IN_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP1_IN_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP1_IN_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP1_IN_CONTROL_INTERRUPT_PER_BUFF		29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP1_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP1_IN_CONTROL_ENDPOINT_TYPE_Msb		27u
#define USBCTRL_DPRAM_EP1_IN_CONTROL_ENDPOINT_TYPE_Lsb		26u
#define USBCTRL_DPRAM_EP1_IN_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP1_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP1_IN_CONTROL_ENDPOINT_TYPE_BULK		2u
#define USBCTRL_DPRAM_EP1_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP1_IN_CONTROL_INTERRUPT_ON_STALL		17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP1_IN_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP1_IN_CONTROL_BUFFER_ADDRESS_Msb		15u
#define USBCTRL_DPRAM_EP1_IN_CONTROL_BUFFER_ADDRESS_Lsb		0u

	/* 0x0C:  */
	uint32_t volatile EP1_OUT_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP1_OUT_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP1_OUT_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP1_OUT_CONTROL_INTERRUPT_PER_BUFF	29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP1_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP1_OUT_CONTROL_ENDPOINT_TYPE_Msb		27u
#define USBCTRL_DPRAM_EP1_OUT_CONTROL_ENDPOINT_TYPE_Lsb		26u
#define USBCTRL_DPRAM_EP1_OUT_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP1_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP1_OUT_CONTROL_ENDPOINT_TYPE_BULK	2u
#define USBCTRL_DPRAM_EP1_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP1_OUT_CONTROL_INTERRUPT_ON_STALL	17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP1_OUT_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP1_OUT_CONTROL_BUFFER_ADDRESS_Msb	15u
#define USBCTRL_DPRAM_EP1_OUT_CONTROL_BUFFER_ADDRESS_Lsb	0u

	/* 0x10:  */
	uint32_t volatile EP2_IN_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP2_IN_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP2_IN_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP2_IN_CONTROL_INTERRUPT_PER_BUFF		29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP2_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP2_IN_CONTROL_ENDPOINT_TYPE_Msb		27u
#define USBCTRL_DPRAM_EP2_IN_CONTROL_ENDPOINT_TYPE_Lsb		26u
#define USBCTRL_DPRAM_EP2_IN_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP2_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP2_IN_CONTROL_ENDPOINT_TYPE_BULK		2u
#define USBCTRL_DPRAM_EP2_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP2_IN_CONTROL_INTERRUPT_ON_STALL		17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP2_IN_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP2_IN_CONTROL_BUFFER_ADDRESS_Msb		15u
#define USBCTRL_DPRAM_EP2_IN_CONTROL_BUFFER_ADDRESS_Lsb		0u

	/* 0x14:  */
	uint32_t volatile EP2_OUT_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP2_OUT_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP2_OUT_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP2_OUT_CONTROL_INTERRUPT_PER_BUFF	29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP2_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP2_OUT_CONTROL_ENDPOINT_TYPE_Msb		27u
#define USBCTRL_DPRAM_EP2_OUT_CONTROL_ENDPOINT_TYPE_Lsb		26u
#define USBCTRL_DPRAM_EP2_OUT_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP2_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP2_OUT_CONTROL_ENDPOINT_TYPE_BULK	2u
#define USBCTRL_DPRAM_EP2_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP2_OUT_CONTROL_INTERRUPT_ON_STALL	17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP2_OUT_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP2_OUT_CONTROL_BUFFER_ADDRESS_Msb	15u
#define USBCTRL_DPRAM_EP2_OUT_CONTROL_BUFFER_ADDRESS_Lsb	0u

	/* 0x18:  */
	uint32_t volatile EP3_IN_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP3_IN_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP3_IN_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP3_IN_CONTROL_INTERRUPT_PER_BUFF		29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP3_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP3_IN_CONTROL_ENDPOINT_TYPE_Msb		27u
#define USBCTRL_DPRAM_EP3_IN_CONTROL_ENDPOINT_TYPE_Lsb		26u
#define USBCTRL_DPRAM_EP3_IN_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP3_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP3_IN_CONTROL_ENDPOINT_TYPE_BULK		2u
#define USBCTRL_DPRAM_EP3_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP3_IN_CONTROL_INTERRUPT_ON_STALL		17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP3_IN_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP3_IN_CONTROL_BUFFER_ADDRESS_Msb		15u
#define USBCTRL_DPRAM_EP3_IN_CONTROL_BUFFER_ADDRESS_Lsb		0u

	/* 0x1C:  */
	uint32_t volatile EP3_OUT_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP3_OUT_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP3_OUT_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP3_OUT_CONTROL_INTERRUPT_PER_BUFF	29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP3_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP3_OUT_CONTROL_ENDPOINT_TYPE_Msb		27u
#define USBCTRL_DPRAM_EP3_OUT_CONTROL_ENDPOINT_TYPE_Lsb		26u
#define USBCTRL_DPRAM_EP3_OUT_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP3_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP3_OUT_CONTROL_ENDPOINT_TYPE_BULK	2u
#define USBCTRL_DPRAM_EP3_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP3_OUT_CONTROL_INTERRUPT_ON_STALL	17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP3_OUT_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP3_OUT_CONTROL_BUFFER_ADDRESS_Msb	15u
#define USBCTRL_DPRAM_EP3_OUT_CONTROL_BUFFER_ADDRESS_Lsb	0u

	/* 0x20:  */
	uint32_t volatile EP4_IN_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP4_IN_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP4_IN_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP4_IN_CONTROL_INTERRUPT_PER_BUFF		29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP4_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP4_IN_CONTROL_ENDPOINT_TYPE_Msb		27u
#define USBCTRL_DPRAM_EP4_IN_CONTROL_ENDPOINT_TYPE_Lsb		26u
#define USBCTRL_DPRAM_EP4_IN_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP4_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP4_IN_CONTROL_ENDPOINT_TYPE_BULK		2u
#define USBCTRL_DPRAM_EP4_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP4_IN_CONTROL_INTERRUPT_ON_STALL		17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP4_IN_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP4_IN_CONTROL_BUFFER_ADDRESS_Msb		15u
#define USBCTRL_DPRAM_EP4_IN_CONTROL_BUFFER_ADDRESS_Lsb		0u

	/* 0x24:  */
	uint32_t volatile EP4_OUT_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP4_OUT_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP4_OUT_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP4_OUT_CONTROL_INTERRUPT_PER_BUFF	29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP4_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP4_OUT_CONTROL_ENDPOINT_TYPE_Msb		27u
#define USBCTRL_DPRAM_EP4_OUT_CONTROL_ENDPOINT_TYPE_Lsb		26u
#define USBCTRL_DPRAM_EP4_OUT_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP4_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP4_OUT_CONTROL_ENDPOINT_TYPE_BULK	2u
#define USBCTRL_DPRAM_EP4_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP4_OUT_CONTROL_INTERRUPT_ON_STALL	17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP4_OUT_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP4_OUT_CONTROL_BUFFER_ADDRESS_Msb	15u
#define USBCTRL_DPRAM_EP4_OUT_CONTROL_BUFFER_ADDRESS_Lsb	0u

	/* 0x28:  */
	uint32_t volatile EP5_IN_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP5_IN_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP5_IN_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP5_IN_CONTROL_INTERRUPT_PER_BUFF		29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP5_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP5_IN_CONTROL_ENDPOINT_TYPE_Msb		27u
#define USBCTRL_DPRAM_EP5_IN_CONTROL_ENDPOINT_TYPE_Lsb		26u
#define USBCTRL_DPRAM_EP5_IN_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP5_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP5_IN_CONTROL_ENDPOINT_TYPE_BULK		2u
#define USBCTRL_DPRAM_EP5_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP5_IN_CONTROL_INTERRUPT_ON_STALL		17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP5_IN_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP5_IN_CONTROL_BUFFER_ADDRESS_Msb		15u
#define USBCTRL_DPRAM_EP5_IN_CONTROL_BUFFER_ADDRESS_Lsb		0u

	/* 0x2C:  */
	uint32_t volatile EP5_OUT_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP5_OUT_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP5_OUT_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP5_OUT_CONTROL_INTERRUPT_PER_BUFF	29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP5_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP5_OUT_CONTROL_ENDPOINT_TYPE_Msb		27u
#define USBCTRL_DPRAM_EP5_OUT_CONTROL_ENDPOINT_TYPE_Lsb		26u
#define USBCTRL_DPRAM_EP5_OUT_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP5_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP5_OUT_CONTROL_ENDPOINT_TYPE_BULK	2u
#define USBCTRL_DPRAM_EP5_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP5_OUT_CONTROL_INTERRUPT_ON_STALL	17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP5_OUT_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP5_OUT_CONTROL_BUFFER_ADDRESS_Msb	15u
#define USBCTRL_DPRAM_EP5_OUT_CONTROL_BUFFER_ADDRESS_Lsb	0u

	/* 0x30:  */
	uint32_t volatile EP6_IN_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP6_IN_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP6_IN_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP6_IN_CONTROL_INTERRUPT_PER_BUFF		29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP6_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP6_IN_CONTROL_ENDPOINT_TYPE_Msb		27u
#define USBCTRL_DPRAM_EP6_IN_CONTROL_ENDPOINT_TYPE_Lsb		26u
#define USBCTRL_DPRAM_EP6_IN_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP6_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP6_IN_CONTROL_ENDPOINT_TYPE_BULK		2u
#define USBCTRL_DPRAM_EP6_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP6_IN_CONTROL_INTERRUPT_ON_STALL		17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP6_IN_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP6_IN_CONTROL_BUFFER_ADDRESS_Msb		15u
#define USBCTRL_DPRAM_EP6_IN_CONTROL_BUFFER_ADDRESS_Lsb		0u

	/* 0x34:  */
	uint32_t volatile EP6_OUT_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP6_OUT_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP6_OUT_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP6_OUT_CONTROL_INTERRUPT_PER_BUFF	29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP6_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP6_OUT_CONTROL_ENDPOINT_TYPE_Msb		27u
#define USBCTRL_DPRAM_EP6_OUT_CONTROL_ENDPOINT_TYPE_Lsb		26u
#define USBCTRL_DPRAM_EP6_OUT_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP6_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP6_OUT_CONTROL_ENDPOINT_TYPE_BULK	2u
#define USBCTRL_DPRAM_EP6_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP6_OUT_CONTROL_INTERRUPT_ON_STALL	17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP6_OUT_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP6_OUT_CONTROL_BUFFER_ADDRESS_Msb	15u
#define USBCTRL_DPRAM_EP6_OUT_CONTROL_BUFFER_ADDRESS_Lsb	0u

	/* 0x38:  */
	uint32_t volatile EP7_IN_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP7_IN_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP7_IN_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP7_IN_CONTROL_INTERRUPT_PER_BUFF		29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP7_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP7_IN_CONTROL_ENDPOINT_TYPE_Msb		27u
#define USBCTRL_DPRAM_EP7_IN_CONTROL_ENDPOINT_TYPE_Lsb		26u
#define USBCTRL_DPRAM_EP7_IN_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP7_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP7_IN_CONTROL_ENDPOINT_TYPE_BULK		2u
#define USBCTRL_DPRAM_EP7_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP7_IN_CONTROL_INTERRUPT_ON_STALL		17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP7_IN_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP7_IN_CONTROL_BUFFER_ADDRESS_Msb		15u
#define USBCTRL_DPRAM_EP7_IN_CONTROL_BUFFER_ADDRESS_Lsb		0u

	/* 0x3C:  */
	uint32_t volatile EP7_OUT_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP7_OUT_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP7_OUT_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP7_OUT_CONTROL_INTERRUPT_PER_BUFF	29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP7_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP7_OUT_CONTROL_ENDPOINT_TYPE_Msb		27u
#define USBCTRL_DPRAM_EP7_OUT_CONTROL_ENDPOINT_TYPE_Lsb		26u
#define USBCTRL_DPRAM_EP7_OUT_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP7_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP7_OUT_CONTROL_ENDPOINT_TYPE_BULK	2u
#define USBCTRL_DPRAM_EP7_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP7_OUT_CONTROL_INTERRUPT_ON_STALL	17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP7_OUT_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP7_OUT_CONTROL_BUFFER_ADDRESS_Msb	15u
#define USBCTRL_DPRAM_EP7_OUT_CONTROL_BUFFER_ADDRESS_Lsb	0u

	/* 0x40:  */
	uint32_t volatile EP8_IN_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP8_IN_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP8_IN_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP8_IN_CONTROL_INTERRUPT_PER_BUFF		29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP8_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP8_IN_CONTROL_ENDPOINT_TYPE_Msb		27u
#define USBCTRL_DPRAM_EP8_IN_CONTROL_ENDPOINT_TYPE_Lsb		26u
#define USBCTRL_DPRAM_EP8_IN_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP8_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP8_IN_CONTROL_ENDPOINT_TYPE_BULK		2u
#define USBCTRL_DPRAM_EP8_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP8_IN_CONTROL_INTERRUPT_ON_STALL		17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP8_IN_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP8_IN_CONTROL_BUFFER_ADDRESS_Msb		15u
#define USBCTRL_DPRAM_EP8_IN_CONTROL_BUFFER_ADDRESS_Lsb		0u

	/* 0x44:  */
	uint32_t volatile EP8_OUT_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP8_OUT_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP8_OUT_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP8_OUT_CONTROL_INTERRUPT_PER_BUFF	29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP8_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP8_OUT_CONTROL_ENDPOINT_TYPE_Msb		27u
#define USBCTRL_DPRAM_EP8_OUT_CONTROL_ENDPOINT_TYPE_Lsb		26u
#define USBCTRL_DPRAM_EP8_OUT_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP8_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP8_OUT_CONTROL_ENDPOINT_TYPE_BULK	2u
#define USBCTRL_DPRAM_EP8_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP8_OUT_CONTROL_INTERRUPT_ON_STALL	17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP8_OUT_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP8_OUT_CONTROL_BUFFER_ADDRESS_Msb	15u
#define USBCTRL_DPRAM_EP8_OUT_CONTROL_BUFFER_ADDRESS_Lsb	0u

	/* 0x48:  */
	uint32_t volatile EP9_IN_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP9_IN_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP9_IN_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP9_IN_CONTROL_INTERRUPT_PER_BUFF		29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP9_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP9_IN_CONTROL_ENDPOINT_TYPE_Msb		27u
#define USBCTRL_DPRAM_EP9_IN_CONTROL_ENDPOINT_TYPE_Lsb		26u
#define USBCTRL_DPRAM_EP9_IN_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP9_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP9_IN_CONTROL_ENDPOINT_TYPE_BULK		2u
#define USBCTRL_DPRAM_EP9_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP9_IN_CONTROL_INTERRUPT_ON_STALL		17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP9_IN_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP9_IN_CONTROL_BUFFER_ADDRESS_Msb		15u
#define USBCTRL_DPRAM_EP9_IN_CONTROL_BUFFER_ADDRESS_Lsb		0u

	/* 0x4C:  */
	uint32_t volatile EP9_OUT_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP9_OUT_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP9_OUT_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP9_OUT_CONTROL_INTERRUPT_PER_BUFF	29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP9_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP9_OUT_CONTROL_ENDPOINT_TYPE_Msb		27u
#define USBCTRL_DPRAM_EP9_OUT_CONTROL_ENDPOINT_TYPE_Lsb		26u
#define USBCTRL_DPRAM_EP9_OUT_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP9_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP9_OUT_CONTROL_ENDPOINT_TYPE_BULK	2u
#define USBCTRL_DPRAM_EP9_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP9_OUT_CONTROL_INTERRUPT_ON_STALL	17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP9_OUT_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP9_OUT_CONTROL_BUFFER_ADDRESS_Msb	15u
#define USBCTRL_DPRAM_EP9_OUT_CONTROL_BUFFER_ADDRESS_Lsb	0u

	/* 0x50:  */
	uint32_t volatile EP10_IN_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP10_IN_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP10_IN_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP10_IN_CONTROL_INTERRUPT_PER_BUFF	29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP10_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP10_IN_CONTROL_ENDPOINT_TYPE_Msb		27u
#define USBCTRL_DPRAM_EP10_IN_CONTROL_ENDPOINT_TYPE_Lsb		26u
#define USBCTRL_DPRAM_EP10_IN_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP10_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP10_IN_CONTROL_ENDPOINT_TYPE_BULK	2u
#define USBCTRL_DPRAM_EP10_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP10_IN_CONTROL_INTERRUPT_ON_STALL	17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP10_IN_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP10_IN_CONTROL_BUFFER_ADDRESS_Msb	15u
#define USBCTRL_DPRAM_EP10_IN_CONTROL_BUFFER_ADDRESS_Lsb	0u

	/* 0x54:  */
	uint32_t volatile EP10_OUT_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP10_OUT_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP10_OUT_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP10_OUT_CONTROL_INTERRUPT_PER_BUFF	29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP10_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP10_OUT_CONTROL_ENDPOINT_TYPE_Msb	27u
#define USBCTRL_DPRAM_EP10_OUT_CONTROL_ENDPOINT_TYPE_Lsb	26u
#define USBCTRL_DPRAM_EP10_OUT_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP10_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP10_OUT_CONTROL_ENDPOINT_TYPE_BULK	2u
#define USBCTRL_DPRAM_EP10_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP10_OUT_CONTROL_INTERRUPT_ON_STALL	17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP10_OUT_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP10_OUT_CONTROL_BUFFER_ADDRESS_Msb	15u
#define USBCTRL_DPRAM_EP10_OUT_CONTROL_BUFFER_ADDRESS_Lsb	0u

	/* 0x58:  */
	uint32_t volatile EP11_IN_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP11_IN_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP11_IN_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP11_IN_CONTROL_INTERRUPT_PER_BUFF	29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP11_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP11_IN_CONTROL_ENDPOINT_TYPE_Msb		27u
#define USBCTRL_DPRAM_EP11_IN_CONTROL_ENDPOINT_TYPE_Lsb		26u
#define USBCTRL_DPRAM_EP11_IN_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP11_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP11_IN_CONTROL_ENDPOINT_TYPE_BULK	2u
#define USBCTRL_DPRAM_EP11_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP11_IN_CONTROL_INTERRUPT_ON_STALL	17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP11_IN_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP11_IN_CONTROL_BUFFER_ADDRESS_Msb	15u
#define USBCTRL_DPRAM_EP11_IN_CONTROL_BUFFER_ADDRESS_Lsb	0u

	/* 0x5C:  */
	uint32_t volatile EP11_OUT_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP11_OUT_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP11_OUT_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP11_OUT_CONTROL_INTERRUPT_PER_BUFF	29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP11_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP11_OUT_CONTROL_ENDPOINT_TYPE_Msb	27u
#define USBCTRL_DPRAM_EP11_OUT_CONTROL_ENDPOINT_TYPE_Lsb	26u
#define USBCTRL_DPRAM_EP11_OUT_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP11_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP11_OUT_CONTROL_ENDPOINT_TYPE_BULK	2u
#define USBCTRL_DPRAM_EP11_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP11_OUT_CONTROL_INTERRUPT_ON_STALL	17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP11_OUT_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP11_OUT_CONTROL_BUFFER_ADDRESS_Msb	15u
#define USBCTRL_DPRAM_EP11_OUT_CONTROL_BUFFER_ADDRESS_Lsb	0u

	/* 0x60:  */
	uint32_t volatile EP12_IN_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP12_IN_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP12_IN_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP12_IN_CONTROL_INTERRUPT_PER_BUFF	29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP12_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP12_IN_CONTROL_ENDPOINT_TYPE_Msb		27u
#define USBCTRL_DPRAM_EP12_IN_CONTROL_ENDPOINT_TYPE_Lsb		26u
#define USBCTRL_DPRAM_EP12_IN_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP12_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP12_IN_CONTROL_ENDPOINT_TYPE_BULK	2u
#define USBCTRL_DPRAM_EP12_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP12_IN_CONTROL_INTERRUPT_ON_STALL	17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP12_IN_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP12_IN_CONTROL_BUFFER_ADDRESS_Msb	15u
#define USBCTRL_DPRAM_EP12_IN_CONTROL_BUFFER_ADDRESS_Lsb	0u

	/* 0x64:  */
	uint32_t volatile EP12_OUT_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP12_OUT_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP12_OUT_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP12_OUT_CONTROL_INTERRUPT_PER_BUFF	29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP12_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP12_OUT_CONTROL_ENDPOINT_TYPE_Msb	27u
#define USBCTRL_DPRAM_EP12_OUT_CONTROL_ENDPOINT_TYPE_Lsb	26u
#define USBCTRL_DPRAM_EP12_OUT_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP12_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP12_OUT_CONTROL_ENDPOINT_TYPE_BULK	2u
#define USBCTRL_DPRAM_EP12_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP12_OUT_CONTROL_INTERRUPT_ON_STALL	17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP12_OUT_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP12_OUT_CONTROL_BUFFER_ADDRESS_Msb	15u
#define USBCTRL_DPRAM_EP12_OUT_CONTROL_BUFFER_ADDRESS_Lsb	0u

	/* 0x68:  */
	uint32_t volatile EP13_IN_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP13_IN_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP13_IN_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP13_IN_CONTROL_INTERRUPT_PER_BUFF	29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP13_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP13_IN_CONTROL_ENDPOINT_TYPE_Msb		27u
#define USBCTRL_DPRAM_EP13_IN_CONTROL_ENDPOINT_TYPE_Lsb		26u
#define USBCTRL_DPRAM_EP13_IN_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP13_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP13_IN_CONTROL_ENDPOINT_TYPE_BULK	2u
#define USBCTRL_DPRAM_EP13_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP13_IN_CONTROL_INTERRUPT_ON_STALL	17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP13_IN_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP13_IN_CONTROL_BUFFER_ADDRESS_Msb	15u
#define USBCTRL_DPRAM_EP13_IN_CONTROL_BUFFER_ADDRESS_Lsb	0u

	/* 0x6C:  */
	uint32_t volatile EP13_OUT_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP13_OUT_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP13_OUT_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP13_OUT_CONTROL_INTERRUPT_PER_BUFF	29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP13_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP13_OUT_CONTROL_ENDPOINT_TYPE_Msb	27u
#define USBCTRL_DPRAM_EP13_OUT_CONTROL_ENDPOINT_TYPE_Lsb	26u
#define USBCTRL_DPRAM_EP13_OUT_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP13_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP13_OUT_CONTROL_ENDPOINT_TYPE_BULK	2u
#define USBCTRL_DPRAM_EP13_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP13_OUT_CONTROL_INTERRUPT_ON_STALL	17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP13_OUT_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP13_OUT_CONTROL_BUFFER_ADDRESS_Msb	15u
#define USBCTRL_DPRAM_EP13_OUT_CONTROL_BUFFER_ADDRESS_Lsb	0u

	/* 0x70:  */
	uint32_t volatile EP14_IN_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP14_IN_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP14_IN_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP14_IN_CONTROL_INTERRUPT_PER_BUFF	29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP14_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP14_IN_CONTROL_ENDPOINT_TYPE_Msb		27u
#define USBCTRL_DPRAM_EP14_IN_CONTROL_ENDPOINT_TYPE_Lsb		26u
#define USBCTRL_DPRAM_EP14_IN_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP14_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP14_IN_CONTROL_ENDPOINT_TYPE_BULK	2u
#define USBCTRL_DPRAM_EP14_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP14_IN_CONTROL_INTERRUPT_ON_STALL	17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP14_IN_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP14_IN_CONTROL_BUFFER_ADDRESS_Msb	15u
#define USBCTRL_DPRAM_EP14_IN_CONTROL_BUFFER_ADDRESS_Lsb	0u

	/* 0x74:  */
	uint32_t volatile EP14_OUT_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP14_OUT_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP14_OUT_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP14_OUT_CONTROL_INTERRUPT_PER_BUFF	29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP14_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP14_OUT_CONTROL_ENDPOINT_TYPE_Msb	27u
#define USBCTRL_DPRAM_EP14_OUT_CONTROL_ENDPOINT_TYPE_Lsb	26u
#define USBCTRL_DPRAM_EP14_OUT_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP14_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP14_OUT_CONTROL_ENDPOINT_TYPE_BULK	2u
#define USBCTRL_DPRAM_EP14_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP14_OUT_CONTROL_INTERRUPT_ON_STALL	17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP14_OUT_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP14_OUT_CONTROL_BUFFER_ADDRESS_Msb	15u
#define USBCTRL_DPRAM_EP14_OUT_CONTROL_BUFFER_ADDRESS_Lsb	0u

	/* 0x78:  */
	uint32_t volatile EP15_IN_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP15_IN_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP15_IN_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP15_IN_CONTROL_INTERRUPT_PER_BUFF	29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP15_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP15_IN_CONTROL_ENDPOINT_TYPE_Msb		27u
#define USBCTRL_DPRAM_EP15_IN_CONTROL_ENDPOINT_TYPE_Lsb		26u
#define USBCTRL_DPRAM_EP15_IN_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP15_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP15_IN_CONTROL_ENDPOINT_TYPE_BULK	2u
#define USBCTRL_DPRAM_EP15_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP15_IN_CONTROL_INTERRUPT_ON_STALL	17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP15_IN_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP15_IN_CONTROL_BUFFER_ADDRESS_Msb	15u
#define USBCTRL_DPRAM_EP15_IN_CONTROL_BUFFER_ADDRESS_Lsb	0u

	/* 0x7C:  */
	uint32_t volatile EP15_OUT_CONTROL;
	/* Enable this endpoint. */
#define USBCTRL_DPRAM_EP15_OUT_CONTROL_ENABLE			31u
	/* This endpoint is double buffered. */
#define USBCTRL_DPRAM_EP15_OUT_CONTROL_DOUBLE_BUFFERED		30u
	/* Trigger an interrupt each time a buffer is done. */
#define USBCTRL_DPRAM_EP15_OUT_CONTROL_INTERRUPT_PER_BUFF	29u
	/* Trigger an interrupt each time both buffers are done. */
#define USBCTRL_DPRAM_EP15_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF	28u
	/*  */
#define USBCTRL_DPRAM_EP15_OUT_CONTROL_ENDPOINT_TYPE_Msb	27u
#define USBCTRL_DPRAM_EP15_OUT_CONTROL_ENDPOINT_TYPE_Lsb	26u
#define USBCTRL_DPRAM_EP15_OUT_CONTROL_ENDPOINT_TYPE_CONTROL	0u
#define USBCTRL_DPRAM_EP15_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS	1u
#define USBCTRL_DPRAM_EP15_OUT_CONTROL_ENDPOINT_TYPE_BULK	2u
#define USBCTRL_DPRAM_EP15_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT	3u
	/* Trigger an interrupt if a STALL is sent. */
#define USBCTRL_DPRAM_EP15_OUT_CONTROL_INTERRUPT_ON_STALL	17u
	/* Trigger an interrupt if a NAK is sent. */
#define USBCTRL_DPRAM_EP15_OUT_CONTROL_INTERRUPT_ON_NAK		16u
	/* 64 byte aligned buffer address for this EP (bits 0-5 are ignored). */
#define USBCTRL_DPRAM_EP15_OUT_CONTROL_BUFFER_ADDRESS_Msb	15u
#define USBCTRL_DPRAM_EP15_OUT_CONTROL_BUFFER_ADDRESS_Lsb	0u

	/* 0x80: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP0_IN_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP0_IN_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP0_IN_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP0_IN_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP0_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP0_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP0_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP0_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP0_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP0_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP0_IN_BUFFER_CONTROL_AVAILABLE_1		26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP0_IN_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP0_IN_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP0_IN_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP0_IN_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP0_IN_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP0_IN_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP0_IN_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP0_IN_BUFFER_CONTROL_AVAILABLE_0		10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP0_IN_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP0_IN_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0x84: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP0_OUT_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP0_OUT_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP0_OUT_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP0_OUT_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP0_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP0_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP0_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP0_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP0_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP0_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP0_OUT_BUFFER_CONTROL_AVAILABLE_1	26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP0_OUT_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP0_OUT_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP0_OUT_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP0_OUT_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP0_OUT_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP0_OUT_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP0_OUT_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP0_OUT_BUFFER_CONTROL_AVAILABLE_0	10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP0_OUT_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP0_OUT_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0x88: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP1_IN_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP1_IN_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP1_IN_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP1_IN_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP1_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP1_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP1_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP1_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP1_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP1_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP1_IN_BUFFER_CONTROL_AVAILABLE_1		26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP1_IN_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP1_IN_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP1_IN_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP1_IN_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP1_IN_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP1_IN_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP1_IN_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP1_IN_BUFFER_CONTROL_AVAILABLE_0		10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP1_IN_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP1_IN_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0x8C: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP1_OUT_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP1_OUT_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP1_OUT_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP1_OUT_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP1_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP1_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP1_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP1_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP1_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP1_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP1_OUT_BUFFER_CONTROL_AVAILABLE_1	26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP1_OUT_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP1_OUT_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP1_OUT_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP1_OUT_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP1_OUT_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP1_OUT_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP1_OUT_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP1_OUT_BUFFER_CONTROL_AVAILABLE_0	10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP1_OUT_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP1_OUT_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0x90: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP2_IN_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP2_IN_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP2_IN_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP2_IN_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP2_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP2_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP2_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP2_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP2_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP2_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP2_IN_BUFFER_CONTROL_AVAILABLE_1		26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP2_IN_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP2_IN_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP2_IN_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP2_IN_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP2_IN_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP2_IN_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP2_IN_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP2_IN_BUFFER_CONTROL_AVAILABLE_0		10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP2_IN_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP2_IN_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0x94: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP2_OUT_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP2_OUT_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP2_OUT_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP2_OUT_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP2_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP2_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP2_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP2_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP2_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP2_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP2_OUT_BUFFER_CONTROL_AVAILABLE_1	26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP2_OUT_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP2_OUT_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP2_OUT_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP2_OUT_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP2_OUT_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP2_OUT_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP2_OUT_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP2_OUT_BUFFER_CONTROL_AVAILABLE_0	10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP2_OUT_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP2_OUT_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0x98: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP3_IN_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP3_IN_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP3_IN_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP3_IN_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP3_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP3_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP3_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP3_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP3_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP3_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP3_IN_BUFFER_CONTROL_AVAILABLE_1		26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP3_IN_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP3_IN_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP3_IN_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP3_IN_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP3_IN_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP3_IN_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP3_IN_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP3_IN_BUFFER_CONTROL_AVAILABLE_0		10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP3_IN_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP3_IN_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0x9C: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP3_OUT_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP3_OUT_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP3_OUT_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP3_OUT_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP3_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP3_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP3_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP3_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP3_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP3_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP3_OUT_BUFFER_CONTROL_AVAILABLE_1	26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP3_OUT_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP3_OUT_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP3_OUT_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP3_OUT_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP3_OUT_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP3_OUT_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP3_OUT_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP3_OUT_BUFFER_CONTROL_AVAILABLE_0	10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP3_OUT_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP3_OUT_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0xA0: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP4_IN_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP4_IN_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP4_IN_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP4_IN_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP4_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP4_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP4_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP4_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP4_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP4_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP4_IN_BUFFER_CONTROL_AVAILABLE_1		26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP4_IN_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP4_IN_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP4_IN_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP4_IN_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP4_IN_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP4_IN_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP4_IN_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP4_IN_BUFFER_CONTROL_AVAILABLE_0		10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP4_IN_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP4_IN_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0xA4: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP4_OUT_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP4_OUT_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP4_OUT_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP4_OUT_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP4_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP4_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP4_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP4_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP4_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP4_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP4_OUT_BUFFER_CONTROL_AVAILABLE_1	26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP4_OUT_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP4_OUT_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP4_OUT_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP4_OUT_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP4_OUT_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP4_OUT_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP4_OUT_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP4_OUT_BUFFER_CONTROL_AVAILABLE_0	10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP4_OUT_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP4_OUT_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0xA8: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP5_IN_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP5_IN_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP5_IN_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP5_IN_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP5_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP5_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP5_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP5_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP5_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP5_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP5_IN_BUFFER_CONTROL_AVAILABLE_1		26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP5_IN_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP5_IN_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP5_IN_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP5_IN_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP5_IN_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP5_IN_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP5_IN_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP5_IN_BUFFER_CONTROL_AVAILABLE_0		10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP5_IN_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP5_IN_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0xAC: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP5_OUT_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP5_OUT_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP5_OUT_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP5_OUT_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP5_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP5_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP5_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP5_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP5_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP5_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP5_OUT_BUFFER_CONTROL_AVAILABLE_1	26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP5_OUT_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP5_OUT_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP5_OUT_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP5_OUT_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP5_OUT_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP5_OUT_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP5_OUT_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP5_OUT_BUFFER_CONTROL_AVAILABLE_0	10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP5_OUT_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP5_OUT_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0xB0: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP6_IN_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP6_IN_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP6_IN_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP6_IN_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP6_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP6_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP6_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP6_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP6_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP6_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP6_IN_BUFFER_CONTROL_AVAILABLE_1		26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP6_IN_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP6_IN_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP6_IN_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP6_IN_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP6_IN_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP6_IN_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP6_IN_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP6_IN_BUFFER_CONTROL_AVAILABLE_0		10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP6_IN_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP6_IN_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0xB4: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP6_OUT_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP6_OUT_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP6_OUT_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP6_OUT_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP6_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP6_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP6_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP6_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP6_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP6_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP6_OUT_BUFFER_CONTROL_AVAILABLE_1	26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP6_OUT_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP6_OUT_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP6_OUT_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP6_OUT_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP6_OUT_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP6_OUT_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP6_OUT_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP6_OUT_BUFFER_CONTROL_AVAILABLE_0	10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP6_OUT_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP6_OUT_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0xB8: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP7_IN_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP7_IN_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP7_IN_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP7_IN_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP7_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP7_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP7_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP7_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP7_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP7_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP7_IN_BUFFER_CONTROL_AVAILABLE_1		26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP7_IN_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP7_IN_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP7_IN_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP7_IN_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP7_IN_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP7_IN_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP7_IN_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP7_IN_BUFFER_CONTROL_AVAILABLE_0		10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP7_IN_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP7_IN_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0xBC: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP7_OUT_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP7_OUT_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP7_OUT_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP7_OUT_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP7_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP7_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP7_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP7_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP7_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP7_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP7_OUT_BUFFER_CONTROL_AVAILABLE_1	26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP7_OUT_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP7_OUT_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP7_OUT_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP7_OUT_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP7_OUT_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP7_OUT_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP7_OUT_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP7_OUT_BUFFER_CONTROL_AVAILABLE_0	10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP7_OUT_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP7_OUT_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0xC0: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP8_IN_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP8_IN_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP8_IN_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP8_IN_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP8_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP8_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP8_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP8_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP8_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP8_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP8_IN_BUFFER_CONTROL_AVAILABLE_1		26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP8_IN_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP8_IN_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP8_IN_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP8_IN_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP8_IN_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP8_IN_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP8_IN_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP8_IN_BUFFER_CONTROL_AVAILABLE_0		10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP8_IN_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP8_IN_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0xC4: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP8_OUT_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP8_OUT_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP8_OUT_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP8_OUT_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP8_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP8_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP8_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP8_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP8_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP8_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP8_OUT_BUFFER_CONTROL_AVAILABLE_1	26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP8_OUT_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP8_OUT_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP8_OUT_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP8_OUT_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP8_OUT_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP8_OUT_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP8_OUT_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP8_OUT_BUFFER_CONTROL_AVAILABLE_0	10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP8_OUT_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP8_OUT_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0xC8: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP9_IN_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP9_IN_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP9_IN_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP9_IN_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP9_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP9_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP9_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP9_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP9_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP9_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP9_IN_BUFFER_CONTROL_AVAILABLE_1		26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP9_IN_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP9_IN_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP9_IN_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP9_IN_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP9_IN_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP9_IN_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP9_IN_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP9_IN_BUFFER_CONTROL_AVAILABLE_0		10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP9_IN_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP9_IN_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0xCC: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP9_OUT_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP9_OUT_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP9_OUT_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP9_OUT_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP9_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP9_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP9_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP9_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP9_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP9_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP9_OUT_BUFFER_CONTROL_AVAILABLE_1	26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP9_OUT_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP9_OUT_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP9_OUT_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP9_OUT_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP9_OUT_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP9_OUT_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP9_OUT_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP9_OUT_BUFFER_CONTROL_AVAILABLE_0	10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP9_OUT_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP9_OUT_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0xD0: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP10_IN_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP10_IN_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP10_IN_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP10_IN_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP10_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP10_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP10_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP10_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP10_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP10_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP10_IN_BUFFER_CONTROL_AVAILABLE_1	26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP10_IN_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP10_IN_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP10_IN_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP10_IN_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP10_IN_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP10_IN_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP10_IN_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP10_IN_BUFFER_CONTROL_AVAILABLE_0	10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP10_IN_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP10_IN_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0xD4: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP10_OUT_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP10_OUT_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP10_OUT_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP10_OUT_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP10_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP10_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP10_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP10_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP10_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP10_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP10_OUT_BUFFER_CONTROL_AVAILABLE_1	26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP10_OUT_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP10_OUT_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP10_OUT_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP10_OUT_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP10_OUT_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP10_OUT_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP10_OUT_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP10_OUT_BUFFER_CONTROL_AVAILABLE_0	10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP10_OUT_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP10_OUT_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0xD8: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP11_IN_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP11_IN_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP11_IN_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP11_IN_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP11_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP11_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP11_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP11_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP11_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP11_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP11_IN_BUFFER_CONTROL_AVAILABLE_1	26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP11_IN_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP11_IN_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP11_IN_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP11_IN_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP11_IN_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP11_IN_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP11_IN_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP11_IN_BUFFER_CONTROL_AVAILABLE_0	10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP11_IN_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP11_IN_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0xDC: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP11_OUT_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP11_OUT_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP11_OUT_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP11_OUT_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP11_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP11_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP11_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP11_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP11_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP11_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP11_OUT_BUFFER_CONTROL_AVAILABLE_1	26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP11_OUT_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP11_OUT_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP11_OUT_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP11_OUT_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP11_OUT_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP11_OUT_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP11_OUT_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP11_OUT_BUFFER_CONTROL_AVAILABLE_0	10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP11_OUT_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP11_OUT_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0xE0: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP12_IN_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP12_IN_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP12_IN_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP12_IN_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP12_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP12_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP12_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP12_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP12_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP12_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP12_IN_BUFFER_CONTROL_AVAILABLE_1	26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP12_IN_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP12_IN_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP12_IN_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP12_IN_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP12_IN_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP12_IN_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP12_IN_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP12_IN_BUFFER_CONTROL_AVAILABLE_0	10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP12_IN_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP12_IN_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0xE4: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP12_OUT_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP12_OUT_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP12_OUT_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP12_OUT_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP12_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP12_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP12_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP12_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP12_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP12_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP12_OUT_BUFFER_CONTROL_AVAILABLE_1	26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP12_OUT_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP12_OUT_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP12_OUT_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP12_OUT_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP12_OUT_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP12_OUT_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP12_OUT_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP12_OUT_BUFFER_CONTROL_AVAILABLE_0	10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP12_OUT_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP12_OUT_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0xE8: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP13_IN_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP13_IN_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP13_IN_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP13_IN_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP13_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP13_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP13_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP13_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP13_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP13_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP13_IN_BUFFER_CONTROL_AVAILABLE_1	26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP13_IN_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP13_IN_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP13_IN_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP13_IN_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP13_IN_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP13_IN_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP13_IN_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP13_IN_BUFFER_CONTROL_AVAILABLE_0	10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP13_IN_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP13_IN_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0xEC: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP13_OUT_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP13_OUT_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP13_OUT_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP13_OUT_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP13_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP13_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP13_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP13_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP13_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP13_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP13_OUT_BUFFER_CONTROL_AVAILABLE_1	26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP13_OUT_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP13_OUT_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP13_OUT_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP13_OUT_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP13_OUT_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP13_OUT_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP13_OUT_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP13_OUT_BUFFER_CONTROL_AVAILABLE_0	10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP13_OUT_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP13_OUT_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0xF0: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP14_IN_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP14_IN_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP14_IN_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP14_IN_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP14_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP14_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP14_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP14_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP14_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP14_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP14_IN_BUFFER_CONTROL_AVAILABLE_1	26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP14_IN_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP14_IN_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP14_IN_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP14_IN_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP14_IN_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP14_IN_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP14_IN_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP14_IN_BUFFER_CONTROL_AVAILABLE_0	10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP14_IN_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP14_IN_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0xF4: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP14_OUT_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP14_OUT_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP14_OUT_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP14_OUT_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP14_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP14_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP14_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP14_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP14_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP14_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP14_OUT_BUFFER_CONTROL_AVAILABLE_1	26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP14_OUT_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP14_OUT_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP14_OUT_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP14_OUT_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP14_OUT_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP14_OUT_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP14_OUT_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP14_OUT_BUFFER_CONTROL_AVAILABLE_0	10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP14_OUT_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP14_OUT_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0xF8: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP15_IN_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP15_IN_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP15_IN_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP15_IN_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP15_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP15_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP15_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP15_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP15_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP15_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP15_IN_BUFFER_CONTROL_AVAILABLE_1	26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP15_IN_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP15_IN_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP15_IN_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP15_IN_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP15_IN_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP15_IN_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP15_IN_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP15_IN_BUFFER_CONTROL_AVAILABLE_0	10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP15_IN_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP15_IN_BUFFER_CONTROL_LENGTH_0_Lsb	0u

	/* 0xFC: Buffer control for both buffers of an endpoint. */
	uint32_t volatile EP15_OUT_BUFFER_CONTROL;
	/* Buffer 1 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP15_OUT_BUFFER_CONTROL_FULL_1		31u
	/* Buffer 1 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP15_OUT_BUFFER_CONTROL_LAST_1		30u
	/* The data pid of buffer 1. */
#define USBCTRL_DPRAM_EP15_OUT_BUFFER_CONTROL_PID_1		29u
	/* The number of bytes buffer 1 is offset from buffer 0 in Isochronous mode. */
#define USBCTRL_DPRAM_EP15_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Msb	28u
#define USBCTRL_DPRAM_EP15_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_Lsb	27u
#define USBCTRL_DPRAM_EP15_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128	0u
#define USBCTRL_DPRAM_EP15_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256	1u
#define USBCTRL_DPRAM_EP15_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512	2u
#define USBCTRL_DPRAM_EP15_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024	3u
	/* Buffer 1 is available. */
#define USBCTRL_DPRAM_EP15_OUT_BUFFER_CONTROL_AVAILABLE_1	26u
	/* The length of the data in buffer 1. */
#define USBCTRL_DPRAM_EP15_OUT_BUFFER_CONTROL_LENGTH_1_Msb	25u
#define USBCTRL_DPRAM_EP15_OUT_BUFFER_CONTROL_LENGTH_1_Lsb	16u
	/* Buffer 0 is full. For an IN transfer (TX to the host) the bit is set to indicate the data is valid. For an OUT transfer (RX from the host) this bit should be left as a 0. */
#define USBCTRL_DPRAM_EP15_OUT_BUFFER_CONTROL_FULL_0		15u
	/* Buffer 0 is the last buffer of the transfer. */
#define USBCTRL_DPRAM_EP15_OUT_BUFFER_CONTROL_LAST_0		14u
	/* The data pid of buffer 0. */
#define USBCTRL_DPRAM_EP15_OUT_BUFFER_CONTROL_PID_0		13u
	/* Reset the buffer selector to buffer 0. */
#define USBCTRL_DPRAM_EP15_OUT_BUFFER_CONTROL_RESET		12u
	/* Reply with a stall (valid for both buffers). */
#define USBCTRL_DPRAM_EP15_OUT_BUFFER_CONTROL_STALL		11u
	/* Buffer 0 is available. */
#define USBCTRL_DPRAM_EP15_OUT_BUFFER_CONTROL_AVAILABLE_0	10u
	/* The length of the data in buffer 0. */
#define USBCTRL_DPRAM_EP15_OUT_BUFFER_CONTROL_LENGTH_0_Msb	9u
#define USBCTRL_DPRAM_EP15_OUT_BUFFER_CONTROL_LENGTH_0_Lsb	0u

};


#define USBCTRL_REGS ((struct sdk_usbctrl_regs *)0x50110000)

struct sdk_usbctrl_regs {

	/* 0x00: Device address and endpoint control */
	uint32_t volatile ADDR_ENDP;
	/* Device endpoint to send data to. */
#define USBCTRL_REGS_ADDR_ENDP_ENDPOINT_Msb			19u
#define USBCTRL_REGS_ADDR_ENDP_ENDPOINT_Lsb			16u
	/* In device mode, the address that the device should respond to. */
#define USBCTRL_REGS_ADDR_ENDP_ADDRESS_Msb			6u
#define USBCTRL_REGS_ADDR_ENDP_ADDRESS_Lsb			0u

	/* 0x04: Interrupt endpoint 1. */
	uint32_t volatile ADDR_ENDP1;
	/* Interrupt EP requires preamble (is a low speed device on a full speed hub) */
#define USBCTRL_REGS_ADDR_ENDP1_INTEP_PREAMBLE			26u
	/* Direction of the interrupt endpoint. */
#define USBCTRL_REGS_ADDR_ENDP1_INTEP_DIR			25u
	/* Endpoint number of the interrupt endpoint */
#define USBCTRL_REGS_ADDR_ENDP1_ENDPOINT_Msb			19u
#define USBCTRL_REGS_ADDR_ENDP1_ENDPOINT_Lsb			16u
	/* Device address */
#define USBCTRL_REGS_ADDR_ENDP1_ADDRESS_Msb			6u
#define USBCTRL_REGS_ADDR_ENDP1_ADDRESS_Lsb			0u

	/* 0x08: Interrupt endpoint 2. */
	uint32_t volatile ADDR_ENDP2;
	/* Interrupt EP requires preamble (is a low speed device on a full speed hub) */
#define USBCTRL_REGS_ADDR_ENDP2_INTEP_PREAMBLE			26u
	/* Direction of the interrupt endpoint. */
#define USBCTRL_REGS_ADDR_ENDP2_INTEP_DIR			25u
	/* Endpoint number of the interrupt endpoint */
#define USBCTRL_REGS_ADDR_ENDP2_ENDPOINT_Msb			19u
#define USBCTRL_REGS_ADDR_ENDP2_ENDPOINT_Lsb			16u
	/* Device address */
#define USBCTRL_REGS_ADDR_ENDP2_ADDRESS_Msb			6u
#define USBCTRL_REGS_ADDR_ENDP2_ADDRESS_Lsb			0u

	/* 0x0C: Interrupt endpoint 3. */
	uint32_t volatile ADDR_ENDP3;
	/* Interrupt EP requires preamble (is a low speed device on a full speed hub) */
#define USBCTRL_REGS_ADDR_ENDP3_INTEP_PREAMBLE			26u
	/* Direction of the interrupt endpoint. */
#define USBCTRL_REGS_ADDR_ENDP3_INTEP_DIR			25u
	/* Endpoint number of the interrupt endpoint */
#define USBCTRL_REGS_ADDR_ENDP3_ENDPOINT_Msb			19u
#define USBCTRL_REGS_ADDR_ENDP3_ENDPOINT_Lsb			16u
	/* Device address */
#define USBCTRL_REGS_ADDR_ENDP3_ADDRESS_Msb			6u
#define USBCTRL_REGS_ADDR_ENDP3_ADDRESS_Lsb			0u

	/* 0x10: Interrupt endpoint 4. */
	uint32_t volatile ADDR_ENDP4;
	/* Interrupt EP requires preamble (is a low speed device on a full speed hub) */
#define USBCTRL_REGS_ADDR_ENDP4_INTEP_PREAMBLE			26u
	/* Direction of the interrupt endpoint. */
#define USBCTRL_REGS_ADDR_ENDP4_INTEP_DIR			25u
	/* Endpoint number of the interrupt endpoint */
#define USBCTRL_REGS_ADDR_ENDP4_ENDPOINT_Msb			19u
#define USBCTRL_REGS_ADDR_ENDP4_ENDPOINT_Lsb			16u
	/* Device address */
#define USBCTRL_REGS_ADDR_ENDP4_ADDRESS_Msb			6u
#define USBCTRL_REGS_ADDR_ENDP4_ADDRESS_Lsb			0u

	/* 0x14: Interrupt endpoint 5. */
	uint32_t volatile ADDR_ENDP5;
	/* Interrupt EP requires preamble (is a low speed device on a full speed hub) */
#define USBCTRL_REGS_ADDR_ENDP5_INTEP_PREAMBLE			26u
	/* Direction of the interrupt endpoint. */
#define USBCTRL_REGS_ADDR_ENDP5_INTEP_DIR			25u
	/* Endpoint number of the interrupt endpoint */
#define USBCTRL_REGS_ADDR_ENDP5_ENDPOINT_Msb			19u
#define USBCTRL_REGS_ADDR_ENDP5_ENDPOINT_Lsb			16u
	/* Device address */
#define USBCTRL_REGS_ADDR_ENDP5_ADDRESS_Msb			6u
#define USBCTRL_REGS_ADDR_ENDP5_ADDRESS_Lsb			0u

	/* 0x18: Interrupt endpoint 6. */
	uint32_t volatile ADDR_ENDP6;
	/* Interrupt EP requires preamble (is a low speed device on a full speed hub) */
#define USBCTRL_REGS_ADDR_ENDP6_INTEP_PREAMBLE			26u
	/* Direction of the interrupt endpoint. */
#define USBCTRL_REGS_ADDR_ENDP6_INTEP_DIR			25u
	/* Endpoint number of the interrupt endpoint */
#define USBCTRL_REGS_ADDR_ENDP6_ENDPOINT_Msb			19u
#define USBCTRL_REGS_ADDR_ENDP6_ENDPOINT_Lsb			16u
	/* Device address */
#define USBCTRL_REGS_ADDR_ENDP6_ADDRESS_Msb			6u
#define USBCTRL_REGS_ADDR_ENDP6_ADDRESS_Lsb			0u

	/* 0x1C: Interrupt endpoint 7. */
	uint32_t volatile ADDR_ENDP7;
	/* Interrupt EP requires preamble (is a low speed device on a full speed hub) */
#define USBCTRL_REGS_ADDR_ENDP7_INTEP_PREAMBLE			26u
	/* Direction of the interrupt endpoint. */
#define USBCTRL_REGS_ADDR_ENDP7_INTEP_DIR			25u
	/* Endpoint number of the interrupt endpoint */
#define USBCTRL_REGS_ADDR_ENDP7_ENDPOINT_Msb			19u
#define USBCTRL_REGS_ADDR_ENDP7_ENDPOINT_Lsb			16u
	/* Device address */
#define USBCTRL_REGS_ADDR_ENDP7_ADDRESS_Msb			6u
#define USBCTRL_REGS_ADDR_ENDP7_ADDRESS_Lsb			0u

	/* 0x20: Interrupt endpoint 8. */
	uint32_t volatile ADDR_ENDP8;
	/* Interrupt EP requires preamble (is a low speed device on a full speed hub) */
#define USBCTRL_REGS_ADDR_ENDP8_INTEP_PREAMBLE			26u
	/* Direction of the interrupt endpoint. */
#define USBCTRL_REGS_ADDR_ENDP8_INTEP_DIR			25u
	/* Endpoint number of the interrupt endpoint */
#define USBCTRL_REGS_ADDR_ENDP8_ENDPOINT_Msb			19u
#define USBCTRL_REGS_ADDR_ENDP8_ENDPOINT_Lsb			16u
	/* Device address */
#define USBCTRL_REGS_ADDR_ENDP8_ADDRESS_Msb			6u
#define USBCTRL_REGS_ADDR_ENDP8_ADDRESS_Lsb			0u

	/* 0x24: Interrupt endpoint 9. */
	uint32_t volatile ADDR_ENDP9;
	/* Interrupt EP requires preamble (is a low speed device on a full speed hub) */
#define USBCTRL_REGS_ADDR_ENDP9_INTEP_PREAMBLE			26u
	/* Direction of the interrupt endpoint. */
#define USBCTRL_REGS_ADDR_ENDP9_INTEP_DIR			25u
	/* Endpoint number of the interrupt endpoint */
#define USBCTRL_REGS_ADDR_ENDP9_ENDPOINT_Msb			19u
#define USBCTRL_REGS_ADDR_ENDP9_ENDPOINT_Lsb			16u
	/* Device address */
#define USBCTRL_REGS_ADDR_ENDP9_ADDRESS_Msb			6u
#define USBCTRL_REGS_ADDR_ENDP9_ADDRESS_Lsb			0u

	/* 0x28: Interrupt endpoint 10. */
	uint32_t volatile ADDR_ENDP10;
	/* Interrupt EP requires preamble (is a low speed device on a full speed hub) */
#define USBCTRL_REGS_ADDR_ENDP10_INTEP_PREAMBLE			26u
	/* Direction of the interrupt endpoint. */
#define USBCTRL_REGS_ADDR_ENDP10_INTEP_DIR			25u
	/* Endpoint number of the interrupt endpoint */
#define USBCTRL_REGS_ADDR_ENDP10_ENDPOINT_Msb			19u
#define USBCTRL_REGS_ADDR_ENDP10_ENDPOINT_Lsb			16u
	/* Device address */
#define USBCTRL_REGS_ADDR_ENDP10_ADDRESS_Msb			6u
#define USBCTRL_REGS_ADDR_ENDP10_ADDRESS_Lsb			0u

	/* 0x2C: Interrupt endpoint 11. */
	uint32_t volatile ADDR_ENDP11;
	/* Interrupt EP requires preamble (is a low speed device on a full speed hub) */
#define USBCTRL_REGS_ADDR_ENDP11_INTEP_PREAMBLE			26u
	/* Direction of the interrupt endpoint. */
#define USBCTRL_REGS_ADDR_ENDP11_INTEP_DIR			25u
	/* Endpoint number of the interrupt endpoint */
#define USBCTRL_REGS_ADDR_ENDP11_ENDPOINT_Msb			19u
#define USBCTRL_REGS_ADDR_ENDP11_ENDPOINT_Lsb			16u
	/* Device address */
#define USBCTRL_REGS_ADDR_ENDP11_ADDRESS_Msb			6u
#define USBCTRL_REGS_ADDR_ENDP11_ADDRESS_Lsb			0u

	/* 0x30: Interrupt endpoint 12. */
	uint32_t volatile ADDR_ENDP12;
	/* Interrupt EP requires preamble (is a low speed device on a full speed hub) */
#define USBCTRL_REGS_ADDR_ENDP12_INTEP_PREAMBLE			26u
	/* Direction of the interrupt endpoint. */
#define USBCTRL_REGS_ADDR_ENDP12_INTEP_DIR			25u
	/* Endpoint number of the interrupt endpoint */
#define USBCTRL_REGS_ADDR_ENDP12_ENDPOINT_Msb			19u
#define USBCTRL_REGS_ADDR_ENDP12_ENDPOINT_Lsb			16u
	/* Device address */
#define USBCTRL_REGS_ADDR_ENDP12_ADDRESS_Msb			6u
#define USBCTRL_REGS_ADDR_ENDP12_ADDRESS_Lsb			0u

	/* 0x34: Interrupt endpoint 13. */
	uint32_t volatile ADDR_ENDP13;
	/* Interrupt EP requires preamble (is a low speed device on a full speed hub) */
#define USBCTRL_REGS_ADDR_ENDP13_INTEP_PREAMBLE			26u
	/* Direction of the interrupt endpoint. */
#define USBCTRL_REGS_ADDR_ENDP13_INTEP_DIR			25u
	/* Endpoint number of the interrupt endpoint */
#define USBCTRL_REGS_ADDR_ENDP13_ENDPOINT_Msb			19u
#define USBCTRL_REGS_ADDR_ENDP13_ENDPOINT_Lsb			16u
	/* Device address */
#define USBCTRL_REGS_ADDR_ENDP13_ADDRESS_Msb			6u
#define USBCTRL_REGS_ADDR_ENDP13_ADDRESS_Lsb			0u

	/* 0x38: Interrupt endpoint 14. */
	uint32_t volatile ADDR_ENDP14;
	/* Interrupt EP requires preamble (is a low speed device on a full speed hub) */
#define USBCTRL_REGS_ADDR_ENDP14_INTEP_PREAMBLE			26u
	/* Direction of the interrupt endpoint. */
#define USBCTRL_REGS_ADDR_ENDP14_INTEP_DIR			25u
	/* Endpoint number of the interrupt endpoint */
#define USBCTRL_REGS_ADDR_ENDP14_ENDPOINT_Msb			19u
#define USBCTRL_REGS_ADDR_ENDP14_ENDPOINT_Lsb			16u
	/* Device address */
#define USBCTRL_REGS_ADDR_ENDP14_ADDRESS_Msb			6u
#define USBCTRL_REGS_ADDR_ENDP14_ADDRESS_Lsb			0u

	/* 0x3C: Interrupt endpoint 15. */
	uint32_t volatile ADDR_ENDP15;
	/* Interrupt EP requires preamble (is a low speed device on a full speed hub) */
#define USBCTRL_REGS_ADDR_ENDP15_INTEP_PREAMBLE			26u
	/* Direction of the interrupt endpoint. */
#define USBCTRL_REGS_ADDR_ENDP15_INTEP_DIR			25u
	/* Endpoint number of the interrupt endpoint */
#define USBCTRL_REGS_ADDR_ENDP15_ENDPOINT_Msb			19u
#define USBCTRL_REGS_ADDR_ENDP15_ENDPOINT_Lsb			16u
	/* Device address */
#define USBCTRL_REGS_ADDR_ENDP15_ADDRESS_Msb			6u
#define USBCTRL_REGS_ADDR_ENDP15_ADDRESS_Lsb			0u

	/* 0x40: Main control register */
	uint32_t volatile MAIN_CTRL;
	/* Reduced timings for simulation */
#define USBCTRL_REGS_MAIN_CTRL_SIM_TIMING			31u
	/* Device mode = 0, Host mode = 1 */
#define USBCTRL_REGS_MAIN_CTRL_HOST_NDEVICE			1u
	/* Enable controller */
#define USBCTRL_REGS_MAIN_CTRL_CONTROLLER_EN			0u

	/* 0x44: Set the SOF (Start of Frame) frame number in the host controller. */
	uint32_t volatile SOF_WR;
	/*  */
#define USBCTRL_REGS_SOF_WR_COUNT_Msb				10u
#define USBCTRL_REGS_SOF_WR_COUNT_Lsb				0u

	/* 0x48: Read the last SOF (Start of Frame) frame number seen. */
	uint32_t volatile SOF_RD;
	/*  */
#define USBCTRL_REGS_SOF_RD_COUNT_Msb				10u
#define USBCTRL_REGS_SOF_RD_COUNT_Lsb				0u

	/* 0x4C: SIE control register */
	uint32_t volatile SIE_CTRL;
	/* Device: Set bit in EP_STATUS_STALL_NAK when EP0 sends a STALL */
#define USBCTRL_REGS_SIE_CTRL_EP0_INT_STALL			31u
	/* Device: EP0 single buffered = 0, double buffered = 1 */
#define USBCTRL_REGS_SIE_CTRL_EP0_DOUBLE_BUF			30u
	/* Device: Set bit in BUFF_STATUS for every buffer completed on EP0 */
#define USBCTRL_REGS_SIE_CTRL_EP0_INT_1BUF			29u
	/* Device: Set bit in BUFF_STATUS for every 2 buffers completed on EP0 */
#define USBCTRL_REGS_SIE_CTRL_EP0_INT_2BUF			28u
	/* Device: Set bit in EP_STATUS_STALL_NAK when EP0 sends a NAK */
#define USBCTRL_REGS_SIE_CTRL_EP0_INT_NAK			27u
	/* Direct bus drive enable */
#define USBCTRL_REGS_SIE_CTRL_DIRECT_EN				26u
	/* Direct control of DP */
#define USBCTRL_REGS_SIE_CTRL_DIRECT_DP				25u
	/* Direct control of DM */
#define USBCTRL_REGS_SIE_CTRL_DIRECT_DM				24u
	/* Power down bus transceiver */
#define USBCTRL_REGS_SIE_CTRL_TRANSCEIVER_PD			18u
	/* Device: Pull-up strength (0=1K2, 1=2k3) */
#define USBCTRL_REGS_SIE_CTRL_RPU_OPT				17u
	/* Device: Enable pull up resistor */
#define USBCTRL_REGS_SIE_CTRL_PULLUP_EN				16u
	/* Host: Enable pull down resistors */
#define USBCTRL_REGS_SIE_CTRL_PULLDOWN_EN			15u
	/* Host: Reset bus */
#define USBCTRL_REGS_SIE_CTRL_RESET_BUS				13u
	/* Device: Remote wakeup. */
#define USBCTRL_REGS_SIE_CTRL_RESUME				12u
	/* Host: Enable VBUS */
#define USBCTRL_REGS_SIE_CTRL_VBUS_EN				11u
	/* Host: Enable keep alive packet (for low speed bus) */
#define USBCTRL_REGS_SIE_CTRL_KEEP_ALIVE_EN			10u
	/* Host: Enable SOF generation (for full speed bus) */
#define USBCTRL_REGS_SIE_CTRL_SOF_EN				9u
	/* Host: Delay packet(s) until after SOF */
#define USBCTRL_REGS_SIE_CTRL_SOF_SYNC				8u
	/* Host: Preable enable for LS device on FS hub */
#define USBCTRL_REGS_SIE_CTRL_PREAMBLE_EN			6u
	/* Host: Stop transaction */
#define USBCTRL_REGS_SIE_CTRL_STOP_TRANS			4u
	/* Host: Receive transaction (IN to host) */
#define USBCTRL_REGS_SIE_CTRL_RECEIVE_DATA			3u
	/* Host: Send transaction (OUT from host) */
#define USBCTRL_REGS_SIE_CTRL_SEND_DATA				2u
	/* Host: Send Setup packet */
#define USBCTRL_REGS_SIE_CTRL_SEND_SETUP			1u
	/* Host: Start transaction */
#define USBCTRL_REGS_SIE_CTRL_START_TRANS			0u

	/* 0x50: SIE status register */
	uint32_t volatile SIE_STATUS;
	/* Data Sequence Error. */
#define USBCTRL_REGS_SIE_STATUS_DATA_SEQ_ERROR			31u
	/* ACK received. */
#define USBCTRL_REGS_SIE_STATUS_ACK_REC				30u
	/* Host: STALL received */
#define USBCTRL_REGS_SIE_STATUS_STALL_REC			29u
	/* Host: NAK received */
#define USBCTRL_REGS_SIE_STATUS_NAK_REC				28u
	/* RX timeout is raised by both the host and device if an ACK is not received in the maximum time specified by the USB spec. */
#define USBCTRL_REGS_SIE_STATUS_RX_TIMEOUT			27u
	/* RX overflow is raised by the Serial RX engine if the incoming data is too fast. */
#define USBCTRL_REGS_SIE_STATUS_RX_OVERFLOW			26u
	/* Bit Stuff Error. */
#define USBCTRL_REGS_SIE_STATUS_BIT_STUFF_ERROR			25u
	/* CRC Error. */
#define USBCTRL_REGS_SIE_STATUS_CRC_ERROR			24u
	/* Device: bus reset received */
#define USBCTRL_REGS_SIE_STATUS_BUS_RESET			19u
	/* Transaction complete. */
#define USBCTRL_REGS_SIE_STATUS_TRANS_COMPLETE			18u
	/* Device: Setup packet received */
#define USBCTRL_REGS_SIE_STATUS_SETUP_REC			17u
	/* Device: connected */
#define USBCTRL_REGS_SIE_STATUS_CONNECTED			16u
	/* Host: Device has initiated a remote resume. */
#define USBCTRL_REGS_SIE_STATUS_RESUME				11u
	/* VBUS over current detected */
#define USBCTRL_REGS_SIE_STATUS_VBUS_OVER_CURR			10u
	/* Host: device speed. */
#define USBCTRL_REGS_SIE_STATUS_SPEED_Msb			9u
#define USBCTRL_REGS_SIE_STATUS_SPEED_Lsb			8u
	/* Bus in suspended state. */
#define USBCTRL_REGS_SIE_STATUS_SUSPENDED			4u
	/* USB bus line state */
#define USBCTRL_REGS_SIE_STATUS_LINE_STATE_Msb			3u
#define USBCTRL_REGS_SIE_STATUS_LINE_STATE_Lsb			2u
	/* Device: VBUS Detected */
#define USBCTRL_REGS_SIE_STATUS_VBUS_DETECTED			0u

	/* 0x54: interrupt endpoint control register */
	uint32_t volatile INT_EP_CTRL;
	/* Host: Enable interrupt endpoint 1 -> 15 */
#define USBCTRL_REGS_INT_EP_CTRL_INT_EP_ACTIVE_Msb		15u
#define USBCTRL_REGS_INT_EP_CTRL_INT_EP_ACTIVE_Lsb		1u

	/* 0x58: Buffer status register. A bit set here indicates that a buffer has completed on the endpoint (if the buffer interrupt is enabled). */
	uint32_t volatile BUFF_STATUS;
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP15_OUT			31u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP15_IN			30u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP14_OUT			29u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP14_IN			28u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP13_OUT			27u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP13_IN			26u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP12_OUT			25u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP12_IN			24u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP11_OUT			23u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP11_IN			22u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP10_OUT			21u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP10_IN			20u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP9_OUT			19u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP9_IN				18u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP8_OUT			17u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP8_IN				16u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP7_OUT			15u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP7_IN				14u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP6_OUT			13u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP6_IN				12u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP5_OUT			11u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP5_IN				10u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP4_OUT			9u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP4_IN				8u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP3_OUT			7u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP3_IN				6u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP2_OUT			5u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP2_IN				4u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP1_OUT			3u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP1_IN				2u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP0_OUT			1u
	/*  */
#define USBCTRL_REGS_BUFF_STATUS_EP0_IN				0u

	/* 0x5C: Which of the double buffers should be handled. Only valid if using an interrupt per buffer (i.e. not per 2 buffers). */
	uint32_t volatile BUFF_CPU_SHOULD_HANDLE;
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP15_OUT		31u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP15_IN		30u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP14_OUT		29u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP14_IN		28u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP13_OUT		27u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP13_IN		26u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP12_OUT		25u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP12_IN		24u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP11_OUT		23u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP11_IN		22u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP10_OUT		21u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP10_IN		20u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP9_OUT		19u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP9_IN		18u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP8_OUT		17u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP8_IN		16u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP7_OUT		15u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP7_IN		14u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP6_OUT		13u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP6_IN		12u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP5_OUT		11u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP5_IN		10u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP4_OUT		9u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP4_IN		8u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP3_OUT		7u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP3_IN		6u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP2_OUT		5u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP2_IN		4u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP1_OUT		3u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP1_IN		2u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP0_OUT		1u
	/*  */
#define USBCTRL_REGS_BUFF_CPU_SHOULD_HANDLE_EP0_IN		0u

	/* 0x60: Device only: Can be set to ignore the buffer control register for this endpoint in case you would like to revoke a buffer. */
	uint32_t volatile EP_ABORT;
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP15_OUT				31u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP15_IN				30u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP14_OUT				29u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP14_IN				28u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP13_OUT				27u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP13_IN				26u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP12_OUT				25u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP12_IN				24u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP11_OUT				23u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP11_IN				22u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP10_OUT				21u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP10_IN				20u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP9_OUT				19u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP9_IN				18u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP8_OUT				17u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP8_IN				16u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP7_OUT				15u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP7_IN				14u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP6_OUT				13u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP6_IN				12u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP5_OUT				11u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP5_IN				10u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP4_OUT				9u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP4_IN				8u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP3_OUT				7u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP3_IN				6u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP2_OUT				5u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP2_IN				4u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP1_OUT				3u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP1_IN				2u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP0_OUT				1u
	/*  */
#define USBCTRL_REGS_EP_ABORT_EP0_IN				0u

	/* 0x64: Device only: Used in conjunction with `EP_ABORT`. */
	uint32_t volatile EP_ABORT_DONE;
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP15_OUT			31u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP15_IN			30u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP14_OUT			29u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP14_IN			28u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP13_OUT			27u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP13_IN			26u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP12_OUT			25u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP12_IN			24u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP11_OUT			23u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP11_IN			22u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP10_OUT			21u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP10_IN			20u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP9_OUT			19u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP9_IN			18u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP8_OUT			17u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP8_IN			16u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP7_OUT			15u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP7_IN			14u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP6_OUT			13u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP6_IN			12u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP5_OUT			11u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP5_IN			10u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP4_OUT			9u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP4_IN			8u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP3_OUT			7u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP3_IN			6u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP2_OUT			5u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP2_IN			4u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP1_OUT			3u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP1_IN			2u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP0_OUT			1u
	/*  */
#define USBCTRL_REGS_EP_ABORT_DONE_EP0_IN			0u

	/* 0x68: Device: this bit must be set in conjunction with the `STALL` bit in the buffer control register to send a STALL on EP0. */
	uint32_t volatile EP_STALL_ARM;
	/*  */
#define USBCTRL_REGS_EP_STALL_ARM_EP0_OUT			1u
	/*  */
#define USBCTRL_REGS_EP_STALL_ARM_EP0_IN			0u

	/* 0x6C: Used by the host controller. */
	uint32_t volatile NAK_POLL;
	/* NAK polling interval for a full speed device */
#define USBCTRL_REGS_NAK_POLL_DELAY_FS_Msb			25u
#define USBCTRL_REGS_NAK_POLL_DELAY_FS_Lsb			16u
	/* NAK polling interval for a low speed device */
#define USBCTRL_REGS_NAK_POLL_DELAY_LS_Msb			9u
#define USBCTRL_REGS_NAK_POLL_DELAY_LS_Lsb			0u

	/* 0x70: Device: bits are set when the `IRQ_ON_NAK` or `IRQ_ON_STALL` bits are set. */
	uint32_t volatile EP_STATUS_STALL_NAK;
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP15_OUT		31u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP15_IN		30u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP14_OUT		29u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP14_IN		28u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP13_OUT		27u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP13_IN		26u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP12_OUT		25u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP12_IN		24u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP11_OUT		23u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP11_IN		22u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP10_OUT		21u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP10_IN		20u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP9_OUT		19u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP9_IN			18u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP8_OUT		17u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP8_IN			16u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP7_OUT		15u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP7_IN			14u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP6_OUT		13u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP6_IN			12u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP5_OUT		11u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP5_IN			10u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP4_OUT		9u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP4_IN			8u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP3_OUT		7u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP3_IN			6u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP2_OUT		5u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP2_IN			4u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP1_OUT		3u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP1_IN			2u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP0_OUT		1u
	/*  */
#define USBCTRL_REGS_EP_STATUS_STALL_NAK_EP0_IN			0u

	/* 0x74: Where to connect the USB controller. */
	uint32_t volatile USB_MUXING;
	/*  */
#define USBCTRL_REGS_USB_MUXING_SOFTCON				3u
	/*  */
#define USBCTRL_REGS_USB_MUXING_TO_DIGITAL_PAD			2u
	/*  */
#define USBCTRL_REGS_USB_MUXING_TO_EXTPHY			1u
	/*  */
#define USBCTRL_REGS_USB_MUXING_TO_PHY				0u

	/* 0x78: Overrides for the power signals in the event that the VBUS signals are not hooked up to GPIO. */
	uint32_t volatile USB_PWR;
	/*  */
#define USBCTRL_REGS_USB_PWR_OVERCURR_DETECT_EN			5u
	/*  */
#define USBCTRL_REGS_USB_PWR_OVERCURR_DETECT			4u
	/*  */
#define USBCTRL_REGS_USB_PWR_VBUS_DETECT_OVERRIDE_EN		3u
	/*  */
#define USBCTRL_REGS_USB_PWR_VBUS_DETECT			2u
	/*  */
#define USBCTRL_REGS_USB_PWR_VBUS_EN_OVERRIDE_EN		1u
	/*  */
#define USBCTRL_REGS_USB_PWR_VBUS_EN				0u

	/* 0x7C: This register allows for direct control of the USB phy. */
	uint32_t volatile USBPHY_DIRECT;
	/* DM over voltage */
#define USBCTRL_REGS_USBPHY_DIRECT_DM_OVV			22u
	/* DP over voltage */
#define USBCTRL_REGS_USBPHY_DIRECT_DP_OVV			21u
	/* DM overcurrent */
#define USBCTRL_REGS_USBPHY_DIRECT_DM_OVCN			20u
	/* DP overcurrent */
#define USBCTRL_REGS_USBPHY_DIRECT_DP_OVCN			19u
	/* DPM pin state */
#define USBCTRL_REGS_USBPHY_DIRECT_RX_DM			18u
	/* DPP pin state */
#define USBCTRL_REGS_USBPHY_DIRECT_RX_DP			17u
	/* Differential RX */
#define USBCTRL_REGS_USBPHY_DIRECT_RX_DD			16u
	/* TX_DIFFMODE=0: Single ended mode */
#define USBCTRL_REGS_USBPHY_DIRECT_TX_DIFFMODE			15u
	/* TX_FSSLEW=0: Low speed slew rate */
#define USBCTRL_REGS_USBPHY_DIRECT_TX_FSSLEW			14u
	/* TX power down override (if override enable is set). */
#define USBCTRL_REGS_USBPHY_DIRECT_TX_PD			13u
	/* RX power down override (if override enable is set). */
#define USBCTRL_REGS_USBPHY_DIRECT_RX_PD			12u
	/* Output data. */
#define USBCTRL_REGS_USBPHY_DIRECT_TX_DM			11u
	/* Output data. */
#define USBCTRL_REGS_USBPHY_DIRECT_TX_DP			10u
	/* Output enable. */
#define USBCTRL_REGS_USBPHY_DIRECT_TX_DM_OE			9u
	/* Output enable. */
#define USBCTRL_REGS_USBPHY_DIRECT_TX_DP_OE			8u
	/* DM pull down enable */
#define USBCTRL_REGS_USBPHY_DIRECT_DM_PULLDN_EN			6u
	/* DM pull up enable */
#define USBCTRL_REGS_USBPHY_DIRECT_DM_PULLUP_EN			5u
	/* Enable the second DM pull up resistor. */
#define USBCTRL_REGS_USBPHY_DIRECT_DM_PULLUP_HISEL		4u
	/* DP pull down enable */
#define USBCTRL_REGS_USBPHY_DIRECT_DP_PULLDN_EN			2u
	/* DP pull up enable */
#define USBCTRL_REGS_USBPHY_DIRECT_DP_PULLUP_EN			1u
	/* Enable the second DP pull up resistor. */
#define USBCTRL_REGS_USBPHY_DIRECT_DP_PULLUP_HISEL		0u

	/* 0x80: Override enable for each control in usbphy_direct */
	uint32_t volatile USBPHY_DIRECT_OVERRIDE;
	/*  */
#define USBCTRL_REGS_USBPHY_DIRECT_OVERRIDE_TX_DIFFMODE_OVERRIDE_EN	15u
	/*  */
#define USBCTRL_REGS_USBPHY_DIRECT_OVERRIDE_DM_PULLUP_OVERRIDE_EN	12u
	/*  */
#define USBCTRL_REGS_USBPHY_DIRECT_OVERRIDE_TX_FSSLEW_OVERRIDE_EN	11u
	/*  */
#define USBCTRL_REGS_USBPHY_DIRECT_OVERRIDE_TX_PD_OVERRIDE_EN	10u
	/*  */
#define USBCTRL_REGS_USBPHY_DIRECT_OVERRIDE_RX_PD_OVERRIDE_EN	9u
	/*  */
#define USBCTRL_REGS_USBPHY_DIRECT_OVERRIDE_TX_DM_OVERRIDE_EN	8u
	/*  */
#define USBCTRL_REGS_USBPHY_DIRECT_OVERRIDE_TX_DP_OVERRIDE_EN	7u
	/*  */
#define USBCTRL_REGS_USBPHY_DIRECT_OVERRIDE_TX_DM_OE_OVERRIDE_EN	6u
	/*  */
#define USBCTRL_REGS_USBPHY_DIRECT_OVERRIDE_TX_DP_OE_OVERRIDE_EN	5u
	/*  */
#define USBCTRL_REGS_USBPHY_DIRECT_OVERRIDE_DM_PULLDN_EN_OVERRIDE_EN	4u
	/*  */
#define USBCTRL_REGS_USBPHY_DIRECT_OVERRIDE_DP_PULLDN_EN_OVERRIDE_EN	3u
	/*  */
#define USBCTRL_REGS_USBPHY_DIRECT_OVERRIDE_DP_PULLUP_EN_OVERRIDE_EN	2u
	/*  */
#define USBCTRL_REGS_USBPHY_DIRECT_OVERRIDE_DM_PULLUP_HISEL_OVERRIDE_EN	1u
	/*  */
#define USBCTRL_REGS_USBPHY_DIRECT_OVERRIDE_DP_PULLUP_HISEL_OVERRIDE_EN	0u

	/* 0x84: Used to adjust trim values of USB phy pull down resistors. */
	uint32_t volatile USBPHY_TRIM;
	/* Value to drive to USB PHY */
#define USBCTRL_REGS_USBPHY_TRIM_DM_PULLDN_TRIM_Msb		12u
#define USBCTRL_REGS_USBPHY_TRIM_DM_PULLDN_TRIM_Lsb		8u
	/* Value to drive to USB PHY */
#define USBCTRL_REGS_USBPHY_TRIM_DP_PULLDN_TRIM_Msb		4u
#define USBCTRL_REGS_USBPHY_TRIM_DP_PULLDN_TRIM_Lsb		0u

	/* 0x88 */
	uint8_t RESERVED0[0x8C-0x88];

	/* 0x8C: Raw Interrupts */
	uint32_t volatile INTR;
	/* Raised when any bit in EP_STATUS_STALL_NAK is set. */
#define USBCTRL_REGS_INTR_EP_STALL_NAK				19u
	/* Raised when any bit in ABORT_DONE is set. */
#define USBCTRL_REGS_INTR_ABORT_DONE				18u
	/* Set every time the device receives a SOF (Start of Frame) packet. */
#define USBCTRL_REGS_INTR_DEV_SOF				17u
	/* Device. */
#define USBCTRL_REGS_INTR_SETUP_REQ				16u
	/* Set when the device receives a resume from the host. */
#define USBCTRL_REGS_INTR_DEV_RESUME_FROM_HOST			15u
	/* Set when the device suspend state changes. */
#define USBCTRL_REGS_INTR_DEV_SUSPEND				14u
	/* Set when the device connection state changes. */
#define USBCTRL_REGS_INTR_DEV_CONN_DIS				13u
	/* Source: SIE_STATUS.BUS_RESET */
#define USBCTRL_REGS_INTR_BUS_RESET				12u
	/* Source: SIE_STATUS.VBUS_DETECTED */
#define USBCTRL_REGS_INTR_VBUS_DETECT				11u
	/* Source: SIE_STATUS.STALL_REC */
#define USBCTRL_REGS_INTR_STALL					10u
	/* Source: SIE_STATUS.CRC_ERROR */
#define USBCTRL_REGS_INTR_ERROR_CRC				9u
	/* Source: SIE_STATUS.BIT_STUFF_ERROR */
#define USBCTRL_REGS_INTR_ERROR_BIT_STUFF			8u
	/* Source: SIE_STATUS.RX_OVERFLOW */
#define USBCTRL_REGS_INTR_ERROR_RX_OVERFLOW			7u
	/* Source: SIE_STATUS.RX_TIMEOUT */
#define USBCTRL_REGS_INTR_ERROR_RX_TIMEOUT			6u
	/* Source: SIE_STATUS.DATA_SEQ_ERROR */
#define USBCTRL_REGS_INTR_ERROR_DATA_SEQ			5u
	/* Raised when any bit in BUFF_STATUS is set. */
#define USBCTRL_REGS_INTR_BUFF_STATUS				4u
	/* Raised every time SIE_STATUS.TRANS_COMPLETE is set. */
#define USBCTRL_REGS_INTR_TRANS_COMPLETE			3u
	/* Host: raised every time the host sends a SOF (Start of Frame). */
#define USBCTRL_REGS_INTR_HOST_SOF				2u
	/* Host: raised when a device wakes up the host. */
#define USBCTRL_REGS_INTR_HOST_RESUME				1u
	/* Host: raised when a device is connected or disconnected (i.e. when SIE_STATUS.SPEED changes). */
#define USBCTRL_REGS_INTR_HOST_CONN_DIS				0u

	/* 0x90: Interrupt Enable */
	uint32_t volatile INTE;
	/* Raised when any bit in EP_STATUS_STALL_NAK is set. */
#define USBCTRL_REGS_INTE_EP_STALL_NAK				19u
	/* Raised when any bit in ABORT_DONE is set. */
#define USBCTRL_REGS_INTE_ABORT_DONE				18u
	/* Set every time the device receives a SOF (Start of Frame) packet. */
#define USBCTRL_REGS_INTE_DEV_SOF				17u
	/* Device. */
#define USBCTRL_REGS_INTE_SETUP_REQ				16u
	/* Set when the device receives a resume from the host. */
#define USBCTRL_REGS_INTE_DEV_RESUME_FROM_HOST			15u
	/* Set when the device suspend state changes. */
#define USBCTRL_REGS_INTE_DEV_SUSPEND				14u
	/* Set when the device connection state changes. */
#define USBCTRL_REGS_INTE_DEV_CONN_DIS				13u
	/* Source: SIE_STATUS.BUS_RESET */
#define USBCTRL_REGS_INTE_BUS_RESET				12u
	/* Source: SIE_STATUS.VBUS_DETECTED */
#define USBCTRL_REGS_INTE_VBUS_DETECT				11u
	/* Source: SIE_STATUS.STALL_REC */
#define USBCTRL_REGS_INTE_STALL					10u
	/* Source: SIE_STATUS.CRC_ERROR */
#define USBCTRL_REGS_INTE_ERROR_CRC				9u
	/* Source: SIE_STATUS.BIT_STUFF_ERROR */
#define USBCTRL_REGS_INTE_ERROR_BIT_STUFF			8u
	/* Source: SIE_STATUS.RX_OVERFLOW */
#define USBCTRL_REGS_INTE_ERROR_RX_OVERFLOW			7u
	/* Source: SIE_STATUS.RX_TIMEOUT */
#define USBCTRL_REGS_INTE_ERROR_RX_TIMEOUT			6u
	/* Source: SIE_STATUS.DATA_SEQ_ERROR */
#define USBCTRL_REGS_INTE_ERROR_DATA_SEQ			5u
	/* Raised when any bit in BUFF_STATUS is set. */
#define USBCTRL_REGS_INTE_BUFF_STATUS				4u
	/* Raised every time SIE_STATUS.TRANS_COMPLETE is set. */
#define USBCTRL_REGS_INTE_TRANS_COMPLETE			3u
	/* Host: raised every time the host sends a SOF (Start of Frame). */
#define USBCTRL_REGS_INTE_HOST_SOF				2u
	/* Host: raised when a device wakes up the host. */
#define USBCTRL_REGS_INTE_HOST_RESUME				1u
	/* Host: raised when a device is connected or disconnected (i.e. when SIE_STATUS.SPEED changes). */
#define USBCTRL_REGS_INTE_HOST_CONN_DIS				0u

	/* 0x94: Interrupt Force */
	uint32_t volatile INTF;
	/* Raised when any bit in EP_STATUS_STALL_NAK is set. */
#define USBCTRL_REGS_INTF_EP_STALL_NAK				19u
	/* Raised when any bit in ABORT_DONE is set. */
#define USBCTRL_REGS_INTF_ABORT_DONE				18u
	/* Set every time the device receives a SOF (Start of Frame) packet. */
#define USBCTRL_REGS_INTF_DEV_SOF				17u
	/* Device. */
#define USBCTRL_REGS_INTF_SETUP_REQ				16u
	/* Set when the device receives a resume from the host. */
#define USBCTRL_REGS_INTF_DEV_RESUME_FROM_HOST			15u
	/* Set when the device suspend state changes. */
#define USBCTRL_REGS_INTF_DEV_SUSPEND				14u
	/* Set when the device connection state changes. */
#define USBCTRL_REGS_INTF_DEV_CONN_DIS				13u
	/* Source: SIE_STATUS.BUS_RESET */
#define USBCTRL_REGS_INTF_BUS_RESET				12u
	/* Source: SIE_STATUS.VBUS_DETECTED */
#define USBCTRL_REGS_INTF_VBUS_DETECT				11u
	/* Source: SIE_STATUS.STALL_REC */
#define USBCTRL_REGS_INTF_STALL					10u
	/* Source: SIE_STATUS.CRC_ERROR */
#define USBCTRL_REGS_INTF_ERROR_CRC				9u
	/* Source: SIE_STATUS.BIT_STUFF_ERROR */
#define USBCTRL_REGS_INTF_ERROR_BIT_STUFF			8u
	/* Source: SIE_STATUS.RX_OVERFLOW */
#define USBCTRL_REGS_INTF_ERROR_RX_OVERFLOW			7u
	/* Source: SIE_STATUS.RX_TIMEOUT */
#define USBCTRL_REGS_INTF_ERROR_RX_TIMEOUT			6u
	/* Source: SIE_STATUS.DATA_SEQ_ERROR */
#define USBCTRL_REGS_INTF_ERROR_DATA_SEQ			5u
	/* Raised when any bit in BUFF_STATUS is set. */
#define USBCTRL_REGS_INTF_BUFF_STATUS				4u
	/* Raised every time SIE_STATUS.TRANS_COMPLETE is set. */
#define USBCTRL_REGS_INTF_TRANS_COMPLETE			3u
	/* Host: raised every time the host sends a SOF (Start of Frame). */
#define USBCTRL_REGS_INTF_HOST_SOF				2u
	/* Host: raised when a device wakes up the host. */
#define USBCTRL_REGS_INTF_HOST_RESUME				1u
	/* Host: raised when a device is connected or disconnected (i.e. when SIE_STATUS.SPEED changes). */
#define USBCTRL_REGS_INTF_HOST_CONN_DIS				0u

	/* 0x98: Interrupt status after masking & forcing */
	uint32_t volatile INTS;
	/* Raised when any bit in EP_STATUS_STALL_NAK is set. */
#define USBCTRL_REGS_INTS_EP_STALL_NAK				19u
	/* Raised when any bit in ABORT_DONE is set. */
#define USBCTRL_REGS_INTS_ABORT_DONE				18u
	/* Set every time the device receives a SOF (Start of Frame) packet. */
#define USBCTRL_REGS_INTS_DEV_SOF				17u
	/* Device. */
#define USBCTRL_REGS_INTS_SETUP_REQ				16u
	/* Set when the device receives a resume from the host. */
#define USBCTRL_REGS_INTS_DEV_RESUME_FROM_HOST			15u
	/* Set when the device suspend state changes. */
#define USBCTRL_REGS_INTS_DEV_SUSPEND				14u
	/* Set when the device connection state changes. */
#define USBCTRL_REGS_INTS_DEV_CONN_DIS				13u
	/* Source: SIE_STATUS.BUS_RESET */
#define USBCTRL_REGS_INTS_BUS_RESET				12u
	/* Source: SIE_STATUS.VBUS_DETECTED */
#define USBCTRL_REGS_INTS_VBUS_DETECT				11u
	/* Source: SIE_STATUS.STALL_REC */
#define USBCTRL_REGS_INTS_STALL					10u
	/* Source: SIE_STATUS.CRC_ERROR */
#define USBCTRL_REGS_INTS_ERROR_CRC				9u
	/* Source: SIE_STATUS.BIT_STUFF_ERROR */
#define USBCTRL_REGS_INTS_ERROR_BIT_STUFF			8u
	/* Source: SIE_STATUS.RX_OVERFLOW */
#define USBCTRL_REGS_INTS_ERROR_RX_OVERFLOW			7u
	/* Source: SIE_STATUS.RX_TIMEOUT */
#define USBCTRL_REGS_INTS_ERROR_RX_TIMEOUT			6u
	/* Source: SIE_STATUS.DATA_SEQ_ERROR */
#define USBCTRL_REGS_INTS_ERROR_DATA_SEQ			5u
	/* Raised when any bit in BUFF_STATUS is set. */
#define USBCTRL_REGS_INTS_BUFF_STATUS				4u
	/* Raised every time SIE_STATUS.TRANS_COMPLETE is set. */
#define USBCTRL_REGS_INTS_TRANS_COMPLETE			3u
	/* Host: raised every time the host sends a SOF (Start of Frame). */
#define USBCTRL_REGS_INTS_HOST_SOF				2u
	/* Host: raised when a device wakes up the host. */
#define USBCTRL_REGS_INTS_HOST_RESUME				1u
	/* Host: raised when a device is connected or disconnected (i.e. when SIE_STATUS.SPEED changes). */
#define USBCTRL_REGS_INTS_HOST_CONN_DIS				0u

};


#define PIO0 ((struct sdk_pio0 *)0x50200000)
#define PIO1 ((struct sdk_pio1 *)0x50300000)

struct sdk_pio0 {

	/* 0x00: PIO control register */
	uint32_t volatile CTRL;
	/* Restart a state machine's clock divider from an initial phase of 0. Clock dividers are free-running, so once started, their output (including fractional jitter) is completely determined by the integer/fractional divisor configured in SMx_CLKDIV. */
#define PIO0_CTRL_CLKDIV_RESTART_Msb				11u
#define PIO0_CTRL_CLKDIV_RESTART_Lsb				8u
	/* Write 1 to instantly clear internal SM state which may be otherwise difficult to access and will affect future execution. */
#define PIO0_CTRL_SM_RESTART_Msb				7u
#define PIO0_CTRL_SM_RESTART_Lsb				4u
	/* Enable/disable each of the four state machines by writing 1/0 to each of these four bits. */
#define PIO0_CTRL_SM_ENABLE_Msb					3u
#define PIO0_CTRL_SM_ENABLE_Lsb					0u

	/* 0x04: FIFO status register */
	uint32_t volatile FSTAT;
	/* State machine TX FIFO is empty */
#define PIO0_FSTAT_TXEMPTY_Msb					27u
#define PIO0_FSTAT_TXEMPTY_Lsb					24u
	/* State machine TX FIFO is full */
#define PIO0_FSTAT_TXFULL_Msb					19u
#define PIO0_FSTAT_TXFULL_Lsb					16u
	/* State machine RX FIFO is empty */
#define PIO0_FSTAT_RXEMPTY_Msb					11u
#define PIO0_FSTAT_RXEMPTY_Lsb					8u
	/* State machine RX FIFO is full */
#define PIO0_FSTAT_RXFULL_Msb					3u
#define PIO0_FSTAT_RXFULL_Lsb					0u

	/* 0x08: FIFO debug register */
	uint32_t volatile FDEBUG;
	/* State machine has stalled on empty TX FIFO during a blocking PULL, or an OUT with autopull enabled. */
#define PIO0_FDEBUG_TXSTALL_Msb					27u
#define PIO0_FDEBUG_TXSTALL_Lsb					24u
	/* TX FIFO overflow (i.e. write-on-full by the system) has occurred. */
#define PIO0_FDEBUG_TXOVER_Msb					19u
#define PIO0_FDEBUG_TXOVER_Lsb					16u
	/* RX FIFO underflow (i.e. read-on-empty by the system) has occurred. */
#define PIO0_FDEBUG_RXUNDER_Msb					11u
#define PIO0_FDEBUG_RXUNDER_Lsb					8u
	/* State machine has stalled on full RX FIFO during a blocking PUSH, or an IN with autopush enabled. */
#define PIO0_FDEBUG_RXSTALL_Msb					3u
#define PIO0_FDEBUG_RXSTALL_Lsb					0u

	/* 0x0C: FIFO levels */
	uint32_t volatile FLEVEL;
	/*  */
#define PIO0_FLEVEL_RX3_Msb					31u
#define PIO0_FLEVEL_RX3_Lsb					28u
	/*  */
#define PIO0_FLEVEL_TX3_Msb					27u
#define PIO0_FLEVEL_TX3_Lsb					24u
	/*  */
#define PIO0_FLEVEL_RX2_Msb					23u
#define PIO0_FLEVEL_RX2_Lsb					20u
	/*  */
#define PIO0_FLEVEL_TX2_Msb					19u
#define PIO0_FLEVEL_TX2_Lsb					16u
	/*  */
#define PIO0_FLEVEL_RX1_Msb					15u
#define PIO0_FLEVEL_RX1_Lsb					12u
	/*  */
#define PIO0_FLEVEL_TX1_Msb					11u
#define PIO0_FLEVEL_TX1_Lsb					8u
	/*  */
#define PIO0_FLEVEL_RX0_Msb					7u
#define PIO0_FLEVEL_RX0_Lsb					4u
	/*  */
#define PIO0_FLEVEL_TX0_Msb					3u
#define PIO0_FLEVEL_TX0_Lsb					0u

	/* 0x10: Direct write access to the TX FIFO for this state machine. */
	uint32_t volatile TXF0;

	/* 0x14: Direct write access to the TX FIFO for this state machine. */
	uint32_t volatile TXF1;

	/* 0x18: Direct write access to the TX FIFO for this state machine. */
	uint32_t volatile TXF2;

	/* 0x1C: Direct write access to the TX FIFO for this state machine. */
	uint32_t volatile TXF3;

	/* 0x20: Direct read access to the RX FIFO for this state machine. */
	uint32_t volatile RXF0;

	/* 0x24: Direct read access to the RX FIFO for this state machine. */
	uint32_t volatile RXF1;

	/* 0x28: Direct read access to the RX FIFO for this state machine. */
	uint32_t volatile RXF2;

	/* 0x2C: Direct read access to the RX FIFO for this state machine. */
	uint32_t volatile RXF3;

	/* 0x30: State machine IRQ flags register. */
	uint32_t volatile IRQ;
	/*  */
#define PIO0_IRQ_IRQ_Msb					7u
#define PIO0_IRQ_IRQ_Lsb					0u

	/* 0x34: Writing a 1 to each of these bits will forcibly assert the corresponding IRQ. */
	uint32_t volatile IRQ_FORCE;
	/*  */
#define PIO0_IRQ_FORCE_IRQ_FORCE_Msb				7u
#define PIO0_IRQ_FORCE_IRQ_FORCE_Lsb				0u

	/* 0x38: There is a 2-flipflop synchronizer on each GPIO input, which protects PIO logic from metastabilities. This increases input delay, and for fast synchronous IO (e.g. SPI) these synchronizers may need to be bypassed. */
	uint32_t volatile INPUT_SYNC_BYPASS;

	/* 0x3C: Read to sample the pad output values PIO is currently driving to the GPIOs. */
	uint32_t volatile DBG_PADOUT;

	/* 0x40: Read to sample the pad output enables (direction) PIO is currently driving to the GPIOs. */
	uint32_t volatile DBG_PADOE;

	/* 0x44: The PIO hardware has some free parameters that may vary between chip products. */
	uint32_t volatile DBG_CFGINFO;
	/* The size of the instruction memory, measured in units of one instruction */
#define PIO0_DBG_CFGINFO_IMEM_SIZE_Msb				21u
#define PIO0_DBG_CFGINFO_IMEM_SIZE_Lsb				16u
	/* The number of state machines this PIO instance is equipped with. */
#define PIO0_DBG_CFGINFO_SM_COUNT_Msb				11u
#define PIO0_DBG_CFGINFO_SM_COUNT_Lsb				8u
	/* The depth of the state machine TX/RX FIFOs, measured in words. */
#define PIO0_DBG_CFGINFO_FIFO_DEPTH_Msb				5u
#define PIO0_DBG_CFGINFO_FIFO_DEPTH_Lsb				0u

	/* 0x48: Write-only access to instruction memory location 0 */
	uint32_t volatile INSTR_MEM0;
	/*  */
#define PIO0_INSTR_MEM0_INSTR_MEM0_Msb				15u
#define PIO0_INSTR_MEM0_INSTR_MEM0_Lsb				0u

	/* 0x4C: Write-only access to instruction memory location 1 */
	uint32_t volatile INSTR_MEM1;
	/*  */
#define PIO0_INSTR_MEM1_INSTR_MEM1_Msb				15u
#define PIO0_INSTR_MEM1_INSTR_MEM1_Lsb				0u

	/* 0x50: Write-only access to instruction memory location 2 */
	uint32_t volatile INSTR_MEM2;
	/*  */
#define PIO0_INSTR_MEM2_INSTR_MEM2_Msb				15u
#define PIO0_INSTR_MEM2_INSTR_MEM2_Lsb				0u

	/* 0x54: Write-only access to instruction memory location 3 */
	uint32_t volatile INSTR_MEM3;
	/*  */
#define PIO0_INSTR_MEM3_INSTR_MEM3_Msb				15u
#define PIO0_INSTR_MEM3_INSTR_MEM3_Lsb				0u

	/* 0x58: Write-only access to instruction memory location 4 */
	uint32_t volatile INSTR_MEM4;
	/*  */
#define PIO0_INSTR_MEM4_INSTR_MEM4_Msb				15u
#define PIO0_INSTR_MEM4_INSTR_MEM4_Lsb				0u

	/* 0x5C: Write-only access to instruction memory location 5 */
	uint32_t volatile INSTR_MEM5;
	/*  */
#define PIO0_INSTR_MEM5_INSTR_MEM5_Msb				15u
#define PIO0_INSTR_MEM5_INSTR_MEM5_Lsb				0u

	/* 0x60: Write-only access to instruction memory location 6 */
	uint32_t volatile INSTR_MEM6;
	/*  */
#define PIO0_INSTR_MEM6_INSTR_MEM6_Msb				15u
#define PIO0_INSTR_MEM6_INSTR_MEM6_Lsb				0u

	/* 0x64: Write-only access to instruction memory location 7 */
	uint32_t volatile INSTR_MEM7;
	/*  */
#define PIO0_INSTR_MEM7_INSTR_MEM7_Msb				15u
#define PIO0_INSTR_MEM7_INSTR_MEM7_Lsb				0u

	/* 0x68: Write-only access to instruction memory location 8 */
	uint32_t volatile INSTR_MEM8;
	/*  */
#define PIO0_INSTR_MEM8_INSTR_MEM8_Msb				15u
#define PIO0_INSTR_MEM8_INSTR_MEM8_Lsb				0u

	/* 0x6C: Write-only access to instruction memory location 9 */
	uint32_t volatile INSTR_MEM9;
	/*  */
#define PIO0_INSTR_MEM9_INSTR_MEM9_Msb				15u
#define PIO0_INSTR_MEM9_INSTR_MEM9_Lsb				0u

	/* 0x70: Write-only access to instruction memory location 10 */
	uint32_t volatile INSTR_MEM10;
	/*  */
#define PIO0_INSTR_MEM10_INSTR_MEM10_Msb			15u
#define PIO0_INSTR_MEM10_INSTR_MEM10_Lsb			0u

	/* 0x74: Write-only access to instruction memory location 11 */
	uint32_t volatile INSTR_MEM11;
	/*  */
#define PIO0_INSTR_MEM11_INSTR_MEM11_Msb			15u
#define PIO0_INSTR_MEM11_INSTR_MEM11_Lsb			0u

	/* 0x78: Write-only access to instruction memory location 12 */
	uint32_t volatile INSTR_MEM12;
	/*  */
#define PIO0_INSTR_MEM12_INSTR_MEM12_Msb			15u
#define PIO0_INSTR_MEM12_INSTR_MEM12_Lsb			0u

	/* 0x7C: Write-only access to instruction memory location 13 */
	uint32_t volatile INSTR_MEM13;
	/*  */
#define PIO0_INSTR_MEM13_INSTR_MEM13_Msb			15u
#define PIO0_INSTR_MEM13_INSTR_MEM13_Lsb			0u

	/* 0x80: Write-only access to instruction memory location 14 */
	uint32_t volatile INSTR_MEM14;
	/*  */
#define PIO0_INSTR_MEM14_INSTR_MEM14_Msb			15u
#define PIO0_INSTR_MEM14_INSTR_MEM14_Lsb			0u

	/* 0x84: Write-only access to instruction memory location 15 */
	uint32_t volatile INSTR_MEM15;
	/*  */
#define PIO0_INSTR_MEM15_INSTR_MEM15_Msb			15u
#define PIO0_INSTR_MEM15_INSTR_MEM15_Lsb			0u

	/* 0x88: Write-only access to instruction memory location 16 */
	uint32_t volatile INSTR_MEM16;
	/*  */
#define PIO0_INSTR_MEM16_INSTR_MEM16_Msb			15u
#define PIO0_INSTR_MEM16_INSTR_MEM16_Lsb			0u

	/* 0x8C: Write-only access to instruction memory location 17 */
	uint32_t volatile INSTR_MEM17;
	/*  */
#define PIO0_INSTR_MEM17_INSTR_MEM17_Msb			15u
#define PIO0_INSTR_MEM17_INSTR_MEM17_Lsb			0u

	/* 0x90: Write-only access to instruction memory location 18 */
	uint32_t volatile INSTR_MEM18;
	/*  */
#define PIO0_INSTR_MEM18_INSTR_MEM18_Msb			15u
#define PIO0_INSTR_MEM18_INSTR_MEM18_Lsb			0u

	/* 0x94: Write-only access to instruction memory location 19 */
	uint32_t volatile INSTR_MEM19;
	/*  */
#define PIO0_INSTR_MEM19_INSTR_MEM19_Msb			15u
#define PIO0_INSTR_MEM19_INSTR_MEM19_Lsb			0u

	/* 0x98: Write-only access to instruction memory location 20 */
	uint32_t volatile INSTR_MEM20;
	/*  */
#define PIO0_INSTR_MEM20_INSTR_MEM20_Msb			15u
#define PIO0_INSTR_MEM20_INSTR_MEM20_Lsb			0u

	/* 0x9C: Write-only access to instruction memory location 21 */
	uint32_t volatile INSTR_MEM21;
	/*  */
#define PIO0_INSTR_MEM21_INSTR_MEM21_Msb			15u
#define PIO0_INSTR_MEM21_INSTR_MEM21_Lsb			0u

	/* 0xA0: Write-only access to instruction memory location 22 */
	uint32_t volatile INSTR_MEM22;
	/*  */
#define PIO0_INSTR_MEM22_INSTR_MEM22_Msb			15u
#define PIO0_INSTR_MEM22_INSTR_MEM22_Lsb			0u

	/* 0xA4: Write-only access to instruction memory location 23 */
	uint32_t volatile INSTR_MEM23;
	/*  */
#define PIO0_INSTR_MEM23_INSTR_MEM23_Msb			15u
#define PIO0_INSTR_MEM23_INSTR_MEM23_Lsb			0u

	/* 0xA8: Write-only access to instruction memory location 24 */
	uint32_t volatile INSTR_MEM24;
	/*  */
#define PIO0_INSTR_MEM24_INSTR_MEM24_Msb			15u
#define PIO0_INSTR_MEM24_INSTR_MEM24_Lsb			0u

	/* 0xAC: Write-only access to instruction memory location 25 */
	uint32_t volatile INSTR_MEM25;
	/*  */
#define PIO0_INSTR_MEM25_INSTR_MEM25_Msb			15u
#define PIO0_INSTR_MEM25_INSTR_MEM25_Lsb			0u

	/* 0xB0: Write-only access to instruction memory location 26 */
	uint32_t volatile INSTR_MEM26;
	/*  */
#define PIO0_INSTR_MEM26_INSTR_MEM26_Msb			15u
#define PIO0_INSTR_MEM26_INSTR_MEM26_Lsb			0u

	/* 0xB4: Write-only access to instruction memory location 27 */
	uint32_t volatile INSTR_MEM27;
	/*  */
#define PIO0_INSTR_MEM27_INSTR_MEM27_Msb			15u
#define PIO0_INSTR_MEM27_INSTR_MEM27_Lsb			0u

	/* 0xB8: Write-only access to instruction memory location 28 */
	uint32_t volatile INSTR_MEM28;
	/*  */
#define PIO0_INSTR_MEM28_INSTR_MEM28_Msb			15u
#define PIO0_INSTR_MEM28_INSTR_MEM28_Lsb			0u

	/* 0xBC: Write-only access to instruction memory location 29 */
	uint32_t volatile INSTR_MEM29;
	/*  */
#define PIO0_INSTR_MEM29_INSTR_MEM29_Msb			15u
#define PIO0_INSTR_MEM29_INSTR_MEM29_Lsb			0u

	/* 0xC0: Write-only access to instruction memory location 30 */
	uint32_t volatile INSTR_MEM30;
	/*  */
#define PIO0_INSTR_MEM30_INSTR_MEM30_Msb			15u
#define PIO0_INSTR_MEM30_INSTR_MEM30_Lsb			0u

	/* 0xC4: Write-only access to instruction memory location 31 */
	uint32_t volatile INSTR_MEM31;
	/*  */
#define PIO0_INSTR_MEM31_INSTR_MEM31_Msb			15u
#define PIO0_INSTR_MEM31_INSTR_MEM31_Lsb			0u

	/* 0xC8: Clock divisor register for state machine 0 */
	uint32_t volatile SM0_CLKDIV;
	/* Effective frequency is sysclk/(int + frac/256). */
#define PIO0_SM0_CLKDIV_INT_Msb					31u
#define PIO0_SM0_CLKDIV_INT_Lsb					16u
	/* Fractional part of clock divisor */
#define PIO0_SM0_CLKDIV_FRAC_Msb				15u
#define PIO0_SM0_CLKDIV_FRAC_Lsb				8u

	/* 0xCC: Execution/behavioural settings for state machine 0 */
	uint32_t volatile SM0_EXECCTRL;
	/* If 1, an instruction written to SMx_INSTR is stalled, and latched by the state machine. */
#define PIO0_SM0_EXECCTRL_EXEC_STALLED				31u
	/* If 1, the MSB of the Delay/Side-set instruction field is used as side-set enable, rather than a side-set data bit. */
#define PIO0_SM0_EXECCTRL_SIDE_EN				30u
	/* If 1, side-set data is asserted to pin directions, instead of pin values */
#define PIO0_SM0_EXECCTRL_SIDE_PINDIR				29u
	/* The GPIO number to use as condition for JMP PIN. */
#define PIO0_SM0_EXECCTRL_JMP_PIN_Msb				28u
#define PIO0_SM0_EXECCTRL_JMP_PIN_Lsb				24u
	/* Which data bit to use for inline OUT enable */
#define PIO0_SM0_EXECCTRL_OUT_EN_SEL_Msb			23u
#define PIO0_SM0_EXECCTRL_OUT_EN_SEL_Lsb			19u
	/* If 1, use a bit of OUT data as an auxiliary write enable */
#define PIO0_SM0_EXECCTRL_INLINE_OUT_EN				18u
	/* Continuously assert the most recent OUT/SET to the pins */
#define PIO0_SM0_EXECCTRL_OUT_STICKY				17u
	/* After reaching this address, execution is wrapped to wrap_bottom. */
#define PIO0_SM0_EXECCTRL_WRAP_TOP_Msb				16u
#define PIO0_SM0_EXECCTRL_WRAP_TOP_Lsb				12u
	/* After reaching wrap_top, execution is wrapped to this address. */
#define PIO0_SM0_EXECCTRL_WRAP_BOTTOM_Msb			11u
#define PIO0_SM0_EXECCTRL_WRAP_BOTTOM_Lsb			7u
	/* Comparison used for the MOV x, STATUS instruction. */
#define PIO0_SM0_EXECCTRL_STATUS_SEL				4u
#define PIO0_SM0_EXECCTRL_STATUS_SEL_TXLEVEL			0u
#define PIO0_SM0_EXECCTRL_STATUS_SEL_RXLEVEL			1u
	/* Comparison level for the MOV x, STATUS instruction */
#define PIO0_SM0_EXECCTRL_STATUS_N_Msb				3u
#define PIO0_SM0_EXECCTRL_STATUS_N_Lsb				0u

	/* 0xD0: Control behaviour of the input/output shift registers for state machine 0 */
	uint32_t volatile SM0_SHIFTCTRL;
	/* When 1, RX FIFO steals the TX FIFO's storage, and becomes twice as deep. */
#define PIO0_SM0_SHIFTCTRL_FJOIN_RX				31u
	/* When 1, TX FIFO steals the RX FIFO's storage, and becomes twice as deep. */
#define PIO0_SM0_SHIFTCTRL_FJOIN_TX				30u
	/* Number of bits shifted out of OSR before autopull, or conditional pull (PULL IFEMPTY), will take place. */
#define PIO0_SM0_SHIFTCTRL_PULL_THRESH_Msb			29u
#define PIO0_SM0_SHIFTCTRL_PULL_THRESH_Lsb			25u
	/* Number of bits shifted into ISR before autopush, or conditional push (PUSH IFFULL), will take place. */
#define PIO0_SM0_SHIFTCTRL_PUSH_THRESH_Msb			24u
#define PIO0_SM0_SHIFTCTRL_PUSH_THRESH_Lsb			20u
	/* 1 = shift out of output shift register to right. */
#define PIO0_SM0_SHIFTCTRL_OUT_SHIFTDIR				19u
	/* 1 = shift input shift register to right (data enters from left). */
#define PIO0_SM0_SHIFTCTRL_IN_SHIFTDIR				18u
	/* Pull automatically when the output shift register is emptied, i.e. */
#define PIO0_SM0_SHIFTCTRL_AUTOPULL				17u
	/* Push automatically when the input shift register is filled, i.e. */
#define PIO0_SM0_SHIFTCTRL_AUTOPUSH				16u

	/* 0xD4: Current instruction address of state machine 0 */
	uint32_t volatile SM0_ADDR;
	/*  */
#define PIO0_SM0_ADDR_SM0_ADDR_Msb				4u
#define PIO0_SM0_ADDR_SM0_ADDR_Lsb				0u

	/* 0xD8: Read to see the instruction currently addressed by state machine 0's program counter */
	uint32_t volatile SM0_INSTR;
	/*  */
#define PIO0_SM0_INSTR_SM0_INSTR_Msb				15u
#define PIO0_SM0_INSTR_SM0_INSTR_Lsb				0u

	/* 0xDC: State machine pin control */
	uint32_t volatile SM0_PINCTRL;
	/* The number of MSBs of the Delay/Side-set instruction field which are used for side-set. Inclusive of the enable bit, if present. Minimum of 0 (all delay bits, no side-set) and maximum of 5 (all side-set, no delay). */
#define PIO0_SM0_PINCTRL_SIDESET_COUNT_Msb			31u
#define PIO0_SM0_PINCTRL_SIDESET_COUNT_Lsb			29u
	/* The number of pins asserted by a SET. */
#define PIO0_SM0_PINCTRL_SET_COUNT_Msb				28u
#define PIO0_SM0_PINCTRL_SET_COUNT_Lsb				26u
	/* The number of pins asserted by an OUT PINS, OUT PINDIRS or MOV PINS instruction. */
#define PIO0_SM0_PINCTRL_OUT_COUNT_Msb				25u
#define PIO0_SM0_PINCTRL_OUT_COUNT_Lsb				20u
	/* The pin which is mapped to the least-significant bit of a state machine's IN data bus. */
#define PIO0_SM0_PINCTRL_IN_BASE_Msb				19u
#define PIO0_SM0_PINCTRL_IN_BASE_Lsb				15u
	/* The lowest-numbered pin that will be affected by a side-set operation. The MSBs of an instruction's side-set/delay field (up to 5, determined by SIDESET_COUNT) are used for side-set data, with the remaining LSBs used for delay. */
#define PIO0_SM0_PINCTRL_SIDESET_BASE_Msb			14u
#define PIO0_SM0_PINCTRL_SIDESET_BASE_Lsb			10u
	/* The lowest-numbered pin that will be affected by a SET PINS or SET PINDIRS instruction. */
#define PIO0_SM0_PINCTRL_SET_BASE_Msb				9u
#define PIO0_SM0_PINCTRL_SET_BASE_Lsb				5u
	/* The lowest-numbered pin that will be affected by an OUT PINS, OUT PINDIRS or MOV PINS instruction. */
#define PIO0_SM0_PINCTRL_OUT_BASE_Msb				4u
#define PIO0_SM0_PINCTRL_OUT_BASE_Lsb				0u

	/* 0xE0: Clock divisor register for state machine 1 */
	uint32_t volatile SM1_CLKDIV;
	/* Effective frequency is sysclk/(int + frac/256). */
#define PIO0_SM1_CLKDIV_INT_Msb					31u
#define PIO0_SM1_CLKDIV_INT_Lsb					16u
	/* Fractional part of clock divisor */
#define PIO0_SM1_CLKDIV_FRAC_Msb				15u
#define PIO0_SM1_CLKDIV_FRAC_Lsb				8u

	/* 0xE4: Execution/behavioural settings for state machine 1 */
	uint32_t volatile SM1_EXECCTRL;
	/* If 1, an instruction written to SMx_INSTR is stalled, and latched by the state machine. */
#define PIO0_SM1_EXECCTRL_EXEC_STALLED				31u
	/* If 1, the MSB of the Delay/Side-set instruction field is used as side-set enable, rather than a side-set data bit. */
#define PIO0_SM1_EXECCTRL_SIDE_EN				30u
	/* If 1, side-set data is asserted to pin directions, instead of pin values */
#define PIO0_SM1_EXECCTRL_SIDE_PINDIR				29u
	/* The GPIO number to use as condition for JMP PIN. */
#define PIO0_SM1_EXECCTRL_JMP_PIN_Msb				28u
#define PIO0_SM1_EXECCTRL_JMP_PIN_Lsb				24u
	/* Which data bit to use for inline OUT enable */
#define PIO0_SM1_EXECCTRL_OUT_EN_SEL_Msb			23u
#define PIO0_SM1_EXECCTRL_OUT_EN_SEL_Lsb			19u
	/* If 1, use a bit of OUT data as an auxiliary write enable */
#define PIO0_SM1_EXECCTRL_INLINE_OUT_EN				18u
	/* Continuously assert the most recent OUT/SET to the pins */
#define PIO0_SM1_EXECCTRL_OUT_STICKY				17u
	/* After reaching this address, execution is wrapped to wrap_bottom. */
#define PIO0_SM1_EXECCTRL_WRAP_TOP_Msb				16u
#define PIO0_SM1_EXECCTRL_WRAP_TOP_Lsb				12u
	/* After reaching wrap_top, execution is wrapped to this address. */
#define PIO0_SM1_EXECCTRL_WRAP_BOTTOM_Msb			11u
#define PIO0_SM1_EXECCTRL_WRAP_BOTTOM_Lsb			7u
	/* Comparison used for the MOV x, STATUS instruction. */
#define PIO0_SM1_EXECCTRL_STATUS_SEL				4u
#define PIO0_SM1_EXECCTRL_STATUS_SEL_TXLEVEL			0u
#define PIO0_SM1_EXECCTRL_STATUS_SEL_RXLEVEL			1u
	/* Comparison level for the MOV x, STATUS instruction */
#define PIO0_SM1_EXECCTRL_STATUS_N_Msb				3u
#define PIO0_SM1_EXECCTRL_STATUS_N_Lsb				0u

	/* 0xE8: Control behaviour of the input/output shift registers for state machine 1 */
	uint32_t volatile SM1_SHIFTCTRL;
	/* When 1, RX FIFO steals the TX FIFO's storage, and becomes twice as deep. */
#define PIO0_SM1_SHIFTCTRL_FJOIN_RX				31u
	/* When 1, TX FIFO steals the RX FIFO's storage, and becomes twice as deep. */
#define PIO0_SM1_SHIFTCTRL_FJOIN_TX				30u
	/* Number of bits shifted out of OSR before autopull, or conditional pull (PULL IFEMPTY), will take place. */
#define PIO0_SM1_SHIFTCTRL_PULL_THRESH_Msb			29u
#define PIO0_SM1_SHIFTCTRL_PULL_THRESH_Lsb			25u
	/* Number of bits shifted into ISR before autopush, or conditional push (PUSH IFFULL), will take place. */
#define PIO0_SM1_SHIFTCTRL_PUSH_THRESH_Msb			24u
#define PIO0_SM1_SHIFTCTRL_PUSH_THRESH_Lsb			20u
	/* 1 = shift out of output shift register to right. */
#define PIO0_SM1_SHIFTCTRL_OUT_SHIFTDIR				19u
	/* 1 = shift input shift register to right (data enters from left). */
#define PIO0_SM1_SHIFTCTRL_IN_SHIFTDIR				18u
	/* Pull automatically when the output shift register is emptied, i.e. */
#define PIO0_SM1_SHIFTCTRL_AUTOPULL				17u
	/* Push automatically when the input shift register is filled, i.e. */
#define PIO0_SM1_SHIFTCTRL_AUTOPUSH				16u

	/* 0xEC: Current instruction address of state machine 1 */
	uint32_t volatile SM1_ADDR;
	/*  */
#define PIO0_SM1_ADDR_SM1_ADDR_Msb				4u
#define PIO0_SM1_ADDR_SM1_ADDR_Lsb				0u

	/* 0xF0: Read to see the instruction currently addressed by state machine 1's program counter */
	uint32_t volatile SM1_INSTR;
	/*  */
#define PIO0_SM1_INSTR_SM1_INSTR_Msb				15u
#define PIO0_SM1_INSTR_SM1_INSTR_Lsb				0u

	/* 0xF4: State machine pin control */
	uint32_t volatile SM1_PINCTRL;
	/* The number of MSBs of the Delay/Side-set instruction field which are used for side-set. Inclusive of the enable bit, if present. Minimum of 0 (all delay bits, no side-set) and maximum of 5 (all side-set, no delay). */
#define PIO0_SM1_PINCTRL_SIDESET_COUNT_Msb			31u
#define PIO0_SM1_PINCTRL_SIDESET_COUNT_Lsb			29u
	/* The number of pins asserted by a SET. */
#define PIO0_SM1_PINCTRL_SET_COUNT_Msb				28u
#define PIO0_SM1_PINCTRL_SET_COUNT_Lsb				26u
	/* The number of pins asserted by an OUT PINS, OUT PINDIRS or MOV PINS instruction. */
#define PIO0_SM1_PINCTRL_OUT_COUNT_Msb				25u
#define PIO0_SM1_PINCTRL_OUT_COUNT_Lsb				20u
	/* The pin which is mapped to the least-significant bit of a state machine's IN data bus. */
#define PIO0_SM1_PINCTRL_IN_BASE_Msb				19u
#define PIO0_SM1_PINCTRL_IN_BASE_Lsb				15u
	/* The lowest-numbered pin that will be affected by a side-set operation. The MSBs of an instruction's side-set/delay field (up to 5, determined by SIDESET_COUNT) are used for side-set data, with the remaining LSBs used for delay. */
#define PIO0_SM1_PINCTRL_SIDESET_BASE_Msb			14u
#define PIO0_SM1_PINCTRL_SIDESET_BASE_Lsb			10u
	/* The lowest-numbered pin that will be affected by a SET PINS or SET PINDIRS instruction. */
#define PIO0_SM1_PINCTRL_SET_BASE_Msb				9u
#define PIO0_SM1_PINCTRL_SET_BASE_Lsb				5u
	/* The lowest-numbered pin that will be affected by an OUT PINS, OUT PINDIRS or MOV PINS instruction. */
#define PIO0_SM1_PINCTRL_OUT_BASE_Msb				4u
#define PIO0_SM1_PINCTRL_OUT_BASE_Lsb				0u

	/* 0xF8: Clock divisor register for state machine 2 */
	uint32_t volatile SM2_CLKDIV;
	/* Effective frequency is sysclk/(int + frac/256). */
#define PIO0_SM2_CLKDIV_INT_Msb					31u
#define PIO0_SM2_CLKDIV_INT_Lsb					16u
	/* Fractional part of clock divisor */
#define PIO0_SM2_CLKDIV_FRAC_Msb				15u
#define PIO0_SM2_CLKDIV_FRAC_Lsb				8u

	/* 0xFC: Execution/behavioural settings for state machine 2 */
	uint32_t volatile SM2_EXECCTRL;
	/* If 1, an instruction written to SMx_INSTR is stalled, and latched by the state machine. */
#define PIO0_SM2_EXECCTRL_EXEC_STALLED				31u
	/* If 1, the MSB of the Delay/Side-set instruction field is used as side-set enable, rather than a side-set data bit. */
#define PIO0_SM2_EXECCTRL_SIDE_EN				30u
	/* If 1, side-set data is asserted to pin directions, instead of pin values */
#define PIO0_SM2_EXECCTRL_SIDE_PINDIR				29u
	/* The GPIO number to use as condition for JMP PIN. */
#define PIO0_SM2_EXECCTRL_JMP_PIN_Msb				28u
#define PIO0_SM2_EXECCTRL_JMP_PIN_Lsb				24u
	/* Which data bit to use for inline OUT enable */
#define PIO0_SM2_EXECCTRL_OUT_EN_SEL_Msb			23u
#define PIO0_SM2_EXECCTRL_OUT_EN_SEL_Lsb			19u
	/* If 1, use a bit of OUT data as an auxiliary write enable */
#define PIO0_SM2_EXECCTRL_INLINE_OUT_EN				18u
	/* Continuously assert the most recent OUT/SET to the pins */
#define PIO0_SM2_EXECCTRL_OUT_STICKY				17u
	/* After reaching this address, execution is wrapped to wrap_bottom. */
#define PIO0_SM2_EXECCTRL_WRAP_TOP_Msb				16u
#define PIO0_SM2_EXECCTRL_WRAP_TOP_Lsb				12u
	/* After reaching wrap_top, execution is wrapped to this address. */
#define PIO0_SM2_EXECCTRL_WRAP_BOTTOM_Msb			11u
#define PIO0_SM2_EXECCTRL_WRAP_BOTTOM_Lsb			7u
	/* Comparison used for the MOV x, STATUS instruction. */
#define PIO0_SM2_EXECCTRL_STATUS_SEL				4u
#define PIO0_SM2_EXECCTRL_STATUS_SEL_TXLEVEL			0u
#define PIO0_SM2_EXECCTRL_STATUS_SEL_RXLEVEL			1u
	/* Comparison level for the MOV x, STATUS instruction */
#define PIO0_SM2_EXECCTRL_STATUS_N_Msb				3u
#define PIO0_SM2_EXECCTRL_STATUS_N_Lsb				0u

	/* 0x100: Control behaviour of the input/output shift registers for state machine 2 */
	uint32_t volatile SM2_SHIFTCTRL;
	/* When 1, RX FIFO steals the TX FIFO's storage, and becomes twice as deep. */
#define PIO0_SM2_SHIFTCTRL_FJOIN_RX				31u
	/* When 1, TX FIFO steals the RX FIFO's storage, and becomes twice as deep. */
#define PIO0_SM2_SHIFTCTRL_FJOIN_TX				30u
	/* Number of bits shifted out of OSR before autopull, or conditional pull (PULL IFEMPTY), will take place. */
#define PIO0_SM2_SHIFTCTRL_PULL_THRESH_Msb			29u
#define PIO0_SM2_SHIFTCTRL_PULL_THRESH_Lsb			25u
	/* Number of bits shifted into ISR before autopush, or conditional push (PUSH IFFULL), will take place. */
#define PIO0_SM2_SHIFTCTRL_PUSH_THRESH_Msb			24u
#define PIO0_SM2_SHIFTCTRL_PUSH_THRESH_Lsb			20u
	/* 1 = shift out of output shift register to right. */
#define PIO0_SM2_SHIFTCTRL_OUT_SHIFTDIR				19u
	/* 1 = shift input shift register to right (data enters from left). */
#define PIO0_SM2_SHIFTCTRL_IN_SHIFTDIR				18u
	/* Pull automatically when the output shift register is emptied, i.e. */
#define PIO0_SM2_SHIFTCTRL_AUTOPULL				17u
	/* Push automatically when the input shift register is filled, i.e. */
#define PIO0_SM2_SHIFTCTRL_AUTOPUSH				16u

	/* 0x104: Current instruction address of state machine 2 */
	uint32_t volatile SM2_ADDR;
	/*  */
#define PIO0_SM2_ADDR_SM2_ADDR_Msb				4u
#define PIO0_SM2_ADDR_SM2_ADDR_Lsb				0u

	/* 0x108: Read to see the instruction currently addressed by state machine 2's program counter */
	uint32_t volatile SM2_INSTR;
	/*  */
#define PIO0_SM2_INSTR_SM2_INSTR_Msb				15u
#define PIO0_SM2_INSTR_SM2_INSTR_Lsb				0u

	/* 0x10C: State machine pin control */
	uint32_t volatile SM2_PINCTRL;
	/* The number of MSBs of the Delay/Side-set instruction field which are used for side-set. Inclusive of the enable bit, if present. Minimum of 0 (all delay bits, no side-set) and maximum of 5 (all side-set, no delay). */
#define PIO0_SM2_PINCTRL_SIDESET_COUNT_Msb			31u
#define PIO0_SM2_PINCTRL_SIDESET_COUNT_Lsb			29u
	/* The number of pins asserted by a SET. */
#define PIO0_SM2_PINCTRL_SET_COUNT_Msb				28u
#define PIO0_SM2_PINCTRL_SET_COUNT_Lsb				26u
	/* The number of pins asserted by an OUT PINS, OUT PINDIRS or MOV PINS instruction. */
#define PIO0_SM2_PINCTRL_OUT_COUNT_Msb				25u
#define PIO0_SM2_PINCTRL_OUT_COUNT_Lsb				20u
	/* The pin which is mapped to the least-significant bit of a state machine's IN data bus. */
#define PIO0_SM2_PINCTRL_IN_BASE_Msb				19u
#define PIO0_SM2_PINCTRL_IN_BASE_Lsb				15u
	/* The lowest-numbered pin that will be affected by a side-set operation. The MSBs of an instruction's side-set/delay field (up to 5, determined by SIDESET_COUNT) are used for side-set data, with the remaining LSBs used for delay. */
#define PIO0_SM2_PINCTRL_SIDESET_BASE_Msb			14u
#define PIO0_SM2_PINCTRL_SIDESET_BASE_Lsb			10u
	/* The lowest-numbered pin that will be affected by a SET PINS or SET PINDIRS instruction. */
#define PIO0_SM2_PINCTRL_SET_BASE_Msb				9u
#define PIO0_SM2_PINCTRL_SET_BASE_Lsb				5u
	/* The lowest-numbered pin that will be affected by an OUT PINS, OUT PINDIRS or MOV PINS instruction. */
#define PIO0_SM2_PINCTRL_OUT_BASE_Msb				4u
#define PIO0_SM2_PINCTRL_OUT_BASE_Lsb				0u

	/* 0x110: Clock divisor register for state machine 3 */
	uint32_t volatile SM3_CLKDIV;
	/* Effective frequency is sysclk/(int + frac/256). */
#define PIO0_SM3_CLKDIV_INT_Msb					31u
#define PIO0_SM3_CLKDIV_INT_Lsb					16u
	/* Fractional part of clock divisor */
#define PIO0_SM3_CLKDIV_FRAC_Msb				15u
#define PIO0_SM3_CLKDIV_FRAC_Lsb				8u

	/* 0x114: Execution/behavioural settings for state machine 3 */
	uint32_t volatile SM3_EXECCTRL;
	/* If 1, an instruction written to SMx_INSTR is stalled, and latched by the state machine. */
#define PIO0_SM3_EXECCTRL_EXEC_STALLED				31u
	/* If 1, the MSB of the Delay/Side-set instruction field is used as side-set enable, rather than a side-set data bit. */
#define PIO0_SM3_EXECCTRL_SIDE_EN				30u
	/* If 1, side-set data is asserted to pin directions, instead of pin values */
#define PIO0_SM3_EXECCTRL_SIDE_PINDIR				29u
	/* The GPIO number to use as condition for JMP PIN. */
#define PIO0_SM3_EXECCTRL_JMP_PIN_Msb				28u
#define PIO0_SM3_EXECCTRL_JMP_PIN_Lsb				24u
	/* Which data bit to use for inline OUT enable */
#define PIO0_SM3_EXECCTRL_OUT_EN_SEL_Msb			23u
#define PIO0_SM3_EXECCTRL_OUT_EN_SEL_Lsb			19u
	/* If 1, use a bit of OUT data as an auxiliary write enable */
#define PIO0_SM3_EXECCTRL_INLINE_OUT_EN				18u
	/* Continuously assert the most recent OUT/SET to the pins */
#define PIO0_SM3_EXECCTRL_OUT_STICKY				17u
	/* After reaching this address, execution is wrapped to wrap_bottom. */
#define PIO0_SM3_EXECCTRL_WRAP_TOP_Msb				16u
#define PIO0_SM3_EXECCTRL_WRAP_TOP_Lsb				12u
	/* After reaching wrap_top, execution is wrapped to this address. */
#define PIO0_SM3_EXECCTRL_WRAP_BOTTOM_Msb			11u
#define PIO0_SM3_EXECCTRL_WRAP_BOTTOM_Lsb			7u
	/* Comparison used for the MOV x, STATUS instruction. */
#define PIO0_SM3_EXECCTRL_STATUS_SEL				4u
#define PIO0_SM3_EXECCTRL_STATUS_SEL_TXLEVEL			0u
#define PIO0_SM3_EXECCTRL_STATUS_SEL_RXLEVEL			1u
	/* Comparison level for the MOV x, STATUS instruction */
#define PIO0_SM3_EXECCTRL_STATUS_N_Msb				3u
#define PIO0_SM3_EXECCTRL_STATUS_N_Lsb				0u

	/* 0x118: Control behaviour of the input/output shift registers for state machine 3 */
	uint32_t volatile SM3_SHIFTCTRL;
	/* When 1, RX FIFO steals the TX FIFO's storage, and becomes twice as deep. */
#define PIO0_SM3_SHIFTCTRL_FJOIN_RX				31u
	/* When 1, TX FIFO steals the RX FIFO's storage, and becomes twice as deep. */
#define PIO0_SM3_SHIFTCTRL_FJOIN_TX				30u
	/* Number of bits shifted out of OSR before autopull, or conditional pull (PULL IFEMPTY), will take place. */
#define PIO0_SM3_SHIFTCTRL_PULL_THRESH_Msb			29u
#define PIO0_SM3_SHIFTCTRL_PULL_THRESH_Lsb			25u
	/* Number of bits shifted into ISR before autopush, or conditional push (PUSH IFFULL), will take place. */
#define PIO0_SM3_SHIFTCTRL_PUSH_THRESH_Msb			24u
#define PIO0_SM3_SHIFTCTRL_PUSH_THRESH_Lsb			20u
	/* 1 = shift out of output shift register to right. */
#define PIO0_SM3_SHIFTCTRL_OUT_SHIFTDIR				19u
	/* 1 = shift input shift register to right (data enters from left). */
#define PIO0_SM3_SHIFTCTRL_IN_SHIFTDIR				18u
	/* Pull automatically when the output shift register is emptied, i.e. */
#define PIO0_SM3_SHIFTCTRL_AUTOPULL				17u
	/* Push automatically when the input shift register is filled, i.e. */
#define PIO0_SM3_SHIFTCTRL_AUTOPUSH				16u

	/* 0x11C: Current instruction address of state machine 3 */
	uint32_t volatile SM3_ADDR;
	/*  */
#define PIO0_SM3_ADDR_SM3_ADDR_Msb				4u
#define PIO0_SM3_ADDR_SM3_ADDR_Lsb				0u

	/* 0x120: Read to see the instruction currently addressed by state machine 3's program counter */
	uint32_t volatile SM3_INSTR;
	/*  */
#define PIO0_SM3_INSTR_SM3_INSTR_Msb				15u
#define PIO0_SM3_INSTR_SM3_INSTR_Lsb				0u

	/* 0x124: State machine pin control */
	uint32_t volatile SM3_PINCTRL;
	/* The number of MSBs of the Delay/Side-set instruction field which are used for side-set. Inclusive of the enable bit, if present. Minimum of 0 (all delay bits, no side-set) and maximum of 5 (all side-set, no delay). */
#define PIO0_SM3_PINCTRL_SIDESET_COUNT_Msb			31u
#define PIO0_SM3_PINCTRL_SIDESET_COUNT_Lsb			29u
	/* The number of pins asserted by a SET. */
#define PIO0_SM3_PINCTRL_SET_COUNT_Msb				28u
#define PIO0_SM3_PINCTRL_SET_COUNT_Lsb				26u
	/* The number of pins asserted by an OUT PINS, OUT PINDIRS or MOV PINS instruction. */
#define PIO0_SM3_PINCTRL_OUT_COUNT_Msb				25u
#define PIO0_SM3_PINCTRL_OUT_COUNT_Lsb				20u
	/* The pin which is mapped to the least-significant bit of a state machine's IN data bus. */
#define PIO0_SM3_PINCTRL_IN_BASE_Msb				19u
#define PIO0_SM3_PINCTRL_IN_BASE_Lsb				15u
	/* The lowest-numbered pin that will be affected by a side-set operation. The MSBs of an instruction's side-set/delay field (up to 5, determined by SIDESET_COUNT) are used for side-set data, with the remaining LSBs used for delay. */
#define PIO0_SM3_PINCTRL_SIDESET_BASE_Msb			14u
#define PIO0_SM3_PINCTRL_SIDESET_BASE_Lsb			10u
	/* The lowest-numbered pin that will be affected by a SET PINS or SET PINDIRS instruction. */
#define PIO0_SM3_PINCTRL_SET_BASE_Msb				9u
#define PIO0_SM3_PINCTRL_SET_BASE_Lsb				5u
	/* The lowest-numbered pin that will be affected by an OUT PINS, OUT PINDIRS or MOV PINS instruction. */
#define PIO0_SM3_PINCTRL_OUT_BASE_Msb				4u
#define PIO0_SM3_PINCTRL_OUT_BASE_Lsb				0u

	/* 0x128: Raw Interrupts */
	uint32_t volatile INTR;
	/*  */
#define PIO0_INTR_SM3						11u
	/*  */
#define PIO0_INTR_SM2						10u
	/*  */
#define PIO0_INTR_SM1						9u
	/*  */
#define PIO0_INTR_SM0						8u
	/*  */
#define PIO0_INTR_SM3_TXNFULL					7u
	/*  */
#define PIO0_INTR_SM2_TXNFULL					6u
	/*  */
#define PIO0_INTR_SM1_TXNFULL					5u
	/*  */
#define PIO0_INTR_SM0_TXNFULL					4u
	/*  */
#define PIO0_INTR_SM3_RXNEMPTY					3u
	/*  */
#define PIO0_INTR_SM2_RXNEMPTY					2u
	/*  */
#define PIO0_INTR_SM1_RXNEMPTY					1u
	/*  */
#define PIO0_INTR_SM0_RXNEMPTY					0u

	/* 0x12C: Interrupt Enable for irq0 */
	uint32_t volatile IRQ0_INTE;
	/*  */
#define PIO0_IRQ0_INTE_SM3					11u
	/*  */
#define PIO0_IRQ0_INTE_SM2					10u
	/*  */
#define PIO0_IRQ0_INTE_SM1					9u
	/*  */
#define PIO0_IRQ0_INTE_SM0					8u
	/*  */
#define PIO0_IRQ0_INTE_SM3_TXNFULL				7u
	/*  */
#define PIO0_IRQ0_INTE_SM2_TXNFULL				6u
	/*  */
#define PIO0_IRQ0_INTE_SM1_TXNFULL				5u
	/*  */
#define PIO0_IRQ0_INTE_SM0_TXNFULL				4u
	/*  */
#define PIO0_IRQ0_INTE_SM3_RXNEMPTY				3u
	/*  */
#define PIO0_IRQ0_INTE_SM2_RXNEMPTY				2u
	/*  */
#define PIO0_IRQ0_INTE_SM1_RXNEMPTY				1u
	/*  */
#define PIO0_IRQ0_INTE_SM0_RXNEMPTY				0u

	/* 0x130: Interrupt Force for irq0 */
	uint32_t volatile IRQ0_INTF;
	/*  */
#define PIO0_IRQ0_INTF_SM3					11u
	/*  */
#define PIO0_IRQ0_INTF_SM2					10u
	/*  */
#define PIO0_IRQ0_INTF_SM1					9u
	/*  */
#define PIO0_IRQ0_INTF_SM0					8u
	/*  */
#define PIO0_IRQ0_INTF_SM3_TXNFULL				7u
	/*  */
#define PIO0_IRQ0_INTF_SM2_TXNFULL				6u
	/*  */
#define PIO0_IRQ0_INTF_SM1_TXNFULL				5u
	/*  */
#define PIO0_IRQ0_INTF_SM0_TXNFULL				4u
	/*  */
#define PIO0_IRQ0_INTF_SM3_RXNEMPTY				3u
	/*  */
#define PIO0_IRQ0_INTF_SM2_RXNEMPTY				2u
	/*  */
#define PIO0_IRQ0_INTF_SM1_RXNEMPTY				1u
	/*  */
#define PIO0_IRQ0_INTF_SM0_RXNEMPTY				0u

	/* 0x134: Interrupt status after masking & forcing for irq0 */
	uint32_t volatile IRQ0_INTS;
	/*  */
#define PIO0_IRQ0_INTS_SM3					11u
	/*  */
#define PIO0_IRQ0_INTS_SM2					10u
	/*  */
#define PIO0_IRQ0_INTS_SM1					9u
	/*  */
#define PIO0_IRQ0_INTS_SM0					8u
	/*  */
#define PIO0_IRQ0_INTS_SM3_TXNFULL				7u
	/*  */
#define PIO0_IRQ0_INTS_SM2_TXNFULL				6u
	/*  */
#define PIO0_IRQ0_INTS_SM1_TXNFULL				5u
	/*  */
#define PIO0_IRQ0_INTS_SM0_TXNFULL				4u
	/*  */
#define PIO0_IRQ0_INTS_SM3_RXNEMPTY				3u
	/*  */
#define PIO0_IRQ0_INTS_SM2_RXNEMPTY				2u
	/*  */
#define PIO0_IRQ0_INTS_SM1_RXNEMPTY				1u
	/*  */
#define PIO0_IRQ0_INTS_SM0_RXNEMPTY				0u

	/* 0x138: Interrupt Enable for irq1 */
	uint32_t volatile IRQ1_INTE;
	/*  */
#define PIO0_IRQ1_INTE_SM3					11u
	/*  */
#define PIO0_IRQ1_INTE_SM2					10u
	/*  */
#define PIO0_IRQ1_INTE_SM1					9u
	/*  */
#define PIO0_IRQ1_INTE_SM0					8u
	/*  */
#define PIO0_IRQ1_INTE_SM3_TXNFULL				7u
	/*  */
#define PIO0_IRQ1_INTE_SM2_TXNFULL				6u
	/*  */
#define PIO0_IRQ1_INTE_SM1_TXNFULL				5u
	/*  */
#define PIO0_IRQ1_INTE_SM0_TXNFULL				4u
	/*  */
#define PIO0_IRQ1_INTE_SM3_RXNEMPTY				3u
	/*  */
#define PIO0_IRQ1_INTE_SM2_RXNEMPTY				2u
	/*  */
#define PIO0_IRQ1_INTE_SM1_RXNEMPTY				1u
	/*  */
#define PIO0_IRQ1_INTE_SM0_RXNEMPTY				0u

	/* 0x13C: Interrupt Force for irq1 */
	uint32_t volatile IRQ1_INTF;
	/*  */
#define PIO0_IRQ1_INTF_SM3					11u
	/*  */
#define PIO0_IRQ1_INTF_SM2					10u
	/*  */
#define PIO0_IRQ1_INTF_SM1					9u
	/*  */
#define PIO0_IRQ1_INTF_SM0					8u
	/*  */
#define PIO0_IRQ1_INTF_SM3_TXNFULL				7u
	/*  */
#define PIO0_IRQ1_INTF_SM2_TXNFULL				6u
	/*  */
#define PIO0_IRQ1_INTF_SM1_TXNFULL				5u
	/*  */
#define PIO0_IRQ1_INTF_SM0_TXNFULL				4u
	/*  */
#define PIO0_IRQ1_INTF_SM3_RXNEMPTY				3u
	/*  */
#define PIO0_IRQ1_INTF_SM2_RXNEMPTY				2u
	/*  */
#define PIO0_IRQ1_INTF_SM1_RXNEMPTY				1u
	/*  */
#define PIO0_IRQ1_INTF_SM0_RXNEMPTY				0u

	/* 0x140: Interrupt status after masking & forcing for irq1 */
	uint32_t volatile IRQ1_INTS;
	/*  */
#define PIO0_IRQ1_INTS_SM3					11u
	/*  */
#define PIO0_IRQ1_INTS_SM2					10u
	/*  */
#define PIO0_IRQ1_INTS_SM1					9u
	/*  */
#define PIO0_IRQ1_INTS_SM0					8u
	/*  */
#define PIO0_IRQ1_INTS_SM3_TXNFULL				7u
	/*  */
#define PIO0_IRQ1_INTS_SM2_TXNFULL				6u
	/*  */
#define PIO0_IRQ1_INTS_SM1_TXNFULL				5u
	/*  */
#define PIO0_IRQ1_INTS_SM0_TXNFULL				4u
	/*  */
#define PIO0_IRQ1_INTS_SM3_RXNEMPTY				3u
	/*  */
#define PIO0_IRQ1_INTS_SM2_RXNEMPTY				2u
	/*  */
#define PIO0_IRQ1_INTS_SM1_RXNEMPTY				1u
	/*  */
#define PIO0_IRQ1_INTS_SM0_RXNEMPTY				0u

};


#define SIO ((struct sdk_sio *)0xD0000000)

struct sdk_sio {

	/* 0x00: Processor core identifier */
	uint32_t volatile CPUID;

	/* 0x04: Input value for GPIO pins */
	uint32_t volatile GPIO_IN;
	/* Input value for GPIO0...29 */
#define SIO_GPIO_IN_GPIO_IN_Msb					29u
#define SIO_GPIO_IN_GPIO_IN_Lsb					0u

	/* 0x08: Input value for QSPI pins */
	uint32_t volatile GPIO_HI_IN;
	/* Input value on QSPI IO in order 0..5: SCLK, SSn, SD0, SD1, SD2, SD3 */
#define SIO_GPIO_HI_IN_GPIO_HI_IN_Msb				5u
#define SIO_GPIO_HI_IN_GPIO_HI_IN_Lsb				0u

	/* 0x0C */
	uint8_t RESERVED0[0x10-0x0C];

	/* 0x10: GPIO output value */
	uint32_t volatile GPIO_OUT;
	/* Set output level (1/0 -> high/low) for GPIO0...29. */
#define SIO_GPIO_OUT_GPIO_OUT_Msb				29u
#define SIO_GPIO_OUT_GPIO_OUT_Lsb				0u

	/* 0x14: GPIO output value set */
	uint32_t volatile GPIO_OUT_SET;
	/* Perform an atomic bit-set on GPIO_OUT, i.e. */
#define SIO_GPIO_OUT_SET_GPIO_OUT_SET_Msb			29u
#define SIO_GPIO_OUT_SET_GPIO_OUT_SET_Lsb			0u

	/* 0x18: GPIO output value clear */
	uint32_t volatile GPIO_OUT_CLR;
	/* Perform an atomic bit-clear on GPIO_OUT, i.e. */
#define SIO_GPIO_OUT_CLR_GPIO_OUT_CLR_Msb			29u
#define SIO_GPIO_OUT_CLR_GPIO_OUT_CLR_Lsb			0u

	/* 0x1C: GPIO output value XOR */
	uint32_t volatile GPIO_OUT_XOR;
	/* Perform an atomic bitwise XOR on GPIO_OUT, i.e. */
#define SIO_GPIO_OUT_XOR_GPIO_OUT_XOR_Msb			29u
#define SIO_GPIO_OUT_XOR_GPIO_OUT_XOR_Lsb			0u

	/* 0x20: GPIO output enable */
	uint32_t volatile GPIO_OE;
	/* Set output enable (1/0 -> output/input) for GPIO0...29. */
#define SIO_GPIO_OE_GPIO_OE_Msb					29u
#define SIO_GPIO_OE_GPIO_OE_Lsb					0u

	/* 0x24: GPIO output enable set */
	uint32_t volatile GPIO_OE_SET;
	/* Perform an atomic bit-set on GPIO_OE, i.e. */
#define SIO_GPIO_OE_SET_GPIO_OE_SET_Msb				29u
#define SIO_GPIO_OE_SET_GPIO_OE_SET_Lsb				0u

	/* 0x28: GPIO output enable clear */
	uint32_t volatile GPIO_OE_CLR;
	/* Perform an atomic bit-clear on GPIO_OE, i.e. */
#define SIO_GPIO_OE_CLR_GPIO_OE_CLR_Msb				29u
#define SIO_GPIO_OE_CLR_GPIO_OE_CLR_Lsb				0u

	/* 0x2C: GPIO output enable XOR */
	uint32_t volatile GPIO_OE_XOR;
	/* Perform an atomic bitwise XOR on GPIO_OE, i.e. */
#define SIO_GPIO_OE_XOR_GPIO_OE_XOR_Msb				29u
#define SIO_GPIO_OE_XOR_GPIO_OE_XOR_Lsb				0u

	/* 0x30: QSPI output value */
	uint32_t volatile GPIO_HI_OUT;
	/* Set output level (1/0 -> high/low) for QSPI IO0...5. */
#define SIO_GPIO_HI_OUT_GPIO_HI_OUT_Msb				5u
#define SIO_GPIO_HI_OUT_GPIO_HI_OUT_Lsb				0u

	/* 0x34: QSPI output value set */
	uint32_t volatile GPIO_HI_OUT_SET;
	/* Perform an atomic bit-set on GPIO_HI_OUT, i.e. */
#define SIO_GPIO_HI_OUT_SET_GPIO_HI_OUT_SET_Msb			5u
#define SIO_GPIO_HI_OUT_SET_GPIO_HI_OUT_SET_Lsb			0u

	/* 0x38: QSPI output value clear */
	uint32_t volatile GPIO_HI_OUT_CLR;
	/* Perform an atomic bit-clear on GPIO_HI_OUT, i.e. */
#define SIO_GPIO_HI_OUT_CLR_GPIO_HI_OUT_CLR_Msb			5u
#define SIO_GPIO_HI_OUT_CLR_GPIO_HI_OUT_CLR_Lsb			0u

	/* 0x3C: QSPI output value XOR */
	uint32_t volatile GPIO_HI_OUT_XOR;
	/* Perform an atomic bitwise XOR on GPIO_HI_OUT, i.e. */
#define SIO_GPIO_HI_OUT_XOR_GPIO_HI_OUT_XOR_Msb			5u
#define SIO_GPIO_HI_OUT_XOR_GPIO_HI_OUT_XOR_Lsb			0u

	/* 0x40: QSPI output enable */
	uint32_t volatile GPIO_HI_OE;
	/* Set output enable (1/0 -> output/input) for QSPI IO0...5. */
#define SIO_GPIO_HI_OE_GPIO_HI_OE_Msb				5u
#define SIO_GPIO_HI_OE_GPIO_HI_OE_Lsb				0u

	/* 0x44: QSPI output enable set */
	uint32_t volatile GPIO_HI_OE_SET;
	/* Perform an atomic bit-set on GPIO_HI_OE, i.e. */
#define SIO_GPIO_HI_OE_SET_GPIO_HI_OE_SET_Msb			5u
#define SIO_GPIO_HI_OE_SET_GPIO_HI_OE_SET_Lsb			0u

	/* 0x48: QSPI output enable clear */
	uint32_t volatile GPIO_HI_OE_CLR;
	/* Perform an atomic bit-clear on GPIO_HI_OE, i.e. */
#define SIO_GPIO_HI_OE_CLR_GPIO_HI_OE_CLR_Msb			5u
#define SIO_GPIO_HI_OE_CLR_GPIO_HI_OE_CLR_Lsb			0u

	/* 0x4C: QSPI output enable XOR */
	uint32_t volatile GPIO_HI_OE_XOR;
	/* Perform an atomic bitwise XOR on GPIO_HI_OE, i.e. */
#define SIO_GPIO_HI_OE_XOR_GPIO_HI_OE_XOR_Msb			5u
#define SIO_GPIO_HI_OE_XOR_GPIO_HI_OE_XOR_Lsb			0u

	/* 0x50: Status register for inter-core FIFOs (mailboxes). */
	uint32_t volatile FIFO_ST;
	/* Sticky flag indicating the RX FIFO was read when empty. */
#define SIO_FIFO_ST_ROE						3u
	/* Sticky flag indicating the TX FIFO was written when full. */
#define SIO_FIFO_ST_WOF						2u
	/* Value is 1 if this core's TX FIFO is not full (i.e. if FIFO_WR is ready for more data) */
#define SIO_FIFO_ST_RDY						1u
	/* Value is 1 if this core's RX FIFO is not empty (i.e. if FIFO_RD is valid) */
#define SIO_FIFO_ST_VLD						0u

	/* 0x54: Write access to this core's TX FIFO */
	uint32_t volatile FIFO_WR;

	/* 0x58: Read access to this core's RX FIFO */
	uint32_t volatile FIFO_RD;

	/* 0x5C: Spinlock state */
	uint32_t volatile SPINLOCK_ST;

	/* 0x60: Divider unsigned dividend */
	uint32_t volatile DIV_UDIVIDEND;

	/* 0x64: Divider unsigned divisor */
	uint32_t volatile DIV_UDIVISOR;

	/* 0x68: Divider signed dividend */
	uint32_t volatile DIV_SDIVIDEND;

	/* 0x6C: Divider signed divisor */
	uint32_t volatile DIV_SDIVISOR;

	/* 0x70: Divider result quotient */
	uint32_t volatile DIV_QUOTIENT;

	/* 0x74: Divider result remainder */
	uint32_t volatile DIV_REMAINDER;

	/* 0x78: Control and status register for divider. */
	uint32_t volatile DIV_CSR;
	/* Changes to 1 when any register is written, and back to 0 when QUOTIENT is read. */
#define SIO_DIV_CSR_DIRTY					1u
	/* Reads as 0 when a calculation is in progress, 1 otherwise. */
#define SIO_DIV_CSR_READY					0u

	/* 0x7C */
	uint8_t RESERVED1[0x80-0x7C];

	/* 0x80: Read/write access to accumulator 0 */
	uint32_t volatile INTERP0_ACCUM0;

	/* 0x84: Read/write access to accumulator 1 */
	uint32_t volatile INTERP0_ACCUM1;

	/* 0x88: Read/write access to BASE0 register. */
	uint32_t volatile INTERP0_BASE0;

	/* 0x8C: Read/write access to BASE1 register. */
	uint32_t volatile INTERP0_BASE1;

	/* 0x90: Read/write access to BASE2 register. */
	uint32_t volatile INTERP0_BASE2;

	/* 0x94: Read LANE0 result, and simultaneously write lane results to both accumulators (POP). */
	uint32_t volatile INTERP0_POP_LANE0;

	/* 0x98: Read LANE1 result, and simultaneously write lane results to both accumulators (POP). */
	uint32_t volatile INTERP0_POP_LANE1;

	/* 0x9C: Read FULL result, and simultaneously write lane results to both accumulators (POP). */
	uint32_t volatile INTERP0_POP_FULL;

	/* 0xA0: Read LANE0 result, without altering any internal state (PEEK). */
	uint32_t volatile INTERP0_PEEK_LANE0;

	/* 0xA4: Read LANE1 result, without altering any internal state (PEEK). */
	uint32_t volatile INTERP0_PEEK_LANE1;

	/* 0xA8: Read FULL result, without altering any internal state (PEEK). */
	uint32_t volatile INTERP0_PEEK_FULL;

	/* 0xAC: Control register for lane 0 */
	uint32_t volatile INTERP0_CTRL_LANE0;
	/* Set if either OVERF0 or OVERF1 is set. */
#define SIO_INTERP0_CTRL_LANE0_OVERF				25u
	/* Indicates if any masked-off MSBs in ACCUM1 are set. */
#define SIO_INTERP0_CTRL_LANE0_OVERF1				24u
	/* Indicates if any masked-off MSBs in ACCUM0 are set. */
#define SIO_INTERP0_CTRL_LANE0_OVERF0				23u
	/* Only present on INTERP0 on each core. */
#define SIO_INTERP0_CTRL_LANE0_BLEND				21u
	/* ORed into bits 29:28 of the lane result presented to the processor on the bus. */
#define SIO_INTERP0_CTRL_LANE0_FORCE_MSB_Msb			20u
#define SIO_INTERP0_CTRL_LANE0_FORCE_MSB_Lsb			19u
	/* If 1, mask + shift is bypassed for LANE0 result. */
#define SIO_INTERP0_CTRL_LANE0_ADD_RAW				18u
	/* If 1, feed the opposite lane's result into this lane's accumulator on POP. */
#define SIO_INTERP0_CTRL_LANE0_CROSS_RESULT			17u
	/* If 1, feed the opposite lane's accumulator into this lane's shift + mask hardware. */
#define SIO_INTERP0_CTRL_LANE0_CROSS_INPUT			16u
	/* If SIGNED is set, the shifted and masked accumulator value is sign-extended to 32 bits */
#define SIO_INTERP0_CTRL_LANE0_SIGNED				15u
	/* The most-significant bit allowed to pass by the mask (inclusive) */
#define SIO_INTERP0_CTRL_LANE0_MASK_MSB_Msb			14u
#define SIO_INTERP0_CTRL_LANE0_MASK_MSB_Lsb			10u
	/* The least-significant bit allowed to pass by the mask (inclusive) */
#define SIO_INTERP0_CTRL_LANE0_MASK_LSB_Msb			9u
#define SIO_INTERP0_CTRL_LANE0_MASK_LSB_Lsb			5u
	/* Logical right-shift applied to accumulator before masking */
#define SIO_INTERP0_CTRL_LANE0_SHIFT_Msb			4u
#define SIO_INTERP0_CTRL_LANE0_SHIFT_Lsb			0u

	/* 0xB0: Control register for lane 1 */
	uint32_t volatile INTERP0_CTRL_LANE1;
	/* ORed into bits 29:28 of the lane result presented to the processor on the bus. */
#define SIO_INTERP0_CTRL_LANE1_FORCE_MSB_Msb			20u
#define SIO_INTERP0_CTRL_LANE1_FORCE_MSB_Lsb			19u
	/* If 1, mask + shift is bypassed for LANE1 result. */
#define SIO_INTERP0_CTRL_LANE1_ADD_RAW				18u
	/* If 1, feed the opposite lane's result into this lane's accumulator on POP. */
#define SIO_INTERP0_CTRL_LANE1_CROSS_RESULT			17u
	/* If 1, feed the opposite lane's accumulator into this lane's shift + mask hardware. */
#define SIO_INTERP0_CTRL_LANE1_CROSS_INPUT			16u
	/* If SIGNED is set, the shifted and masked accumulator value is sign-extended to 32 bits */
#define SIO_INTERP0_CTRL_LANE1_SIGNED				15u
	/* The most-significant bit allowed to pass by the mask (inclusive) */
#define SIO_INTERP0_CTRL_LANE1_MASK_MSB_Msb			14u
#define SIO_INTERP0_CTRL_LANE1_MASK_MSB_Lsb			10u
	/* The least-significant bit allowed to pass by the mask (inclusive) */
#define SIO_INTERP0_CTRL_LANE1_MASK_LSB_Msb			9u
#define SIO_INTERP0_CTRL_LANE1_MASK_LSB_Lsb			5u
	/* Logical right-shift applied to accumulator before masking */
#define SIO_INTERP0_CTRL_LANE1_SHIFT_Msb			4u
#define SIO_INTERP0_CTRL_LANE1_SHIFT_Lsb			0u

	/* 0xB4: Values written here are atomically added to ACCUM0 */
	uint32_t volatile INTERP0_ACCUM0_ADD;
	/*  */
#define SIO_INTERP0_ACCUM0_ADD_INTERP0_ACCUM0_ADD_Msb		23u
#define SIO_INTERP0_ACCUM0_ADD_INTERP0_ACCUM0_ADD_Lsb		0u

	/* 0xB8: Values written here are atomically added to ACCUM1 */
	uint32_t volatile INTERP0_ACCUM1_ADD;
	/*  */
#define SIO_INTERP0_ACCUM1_ADD_INTERP0_ACCUM1_ADD_Msb		23u
#define SIO_INTERP0_ACCUM1_ADD_INTERP0_ACCUM1_ADD_Lsb		0u

	/* 0xBC: On write, the lower 16 bits go to BASE0, upper bits to BASE1 simultaneously. */
	uint32_t volatile INTERP0_BASE_1AND0;

	/* 0xC0: Read/write access to accumulator 0 */
	uint32_t volatile INTERP1_ACCUM0;

	/* 0xC4: Read/write access to accumulator 1 */
	uint32_t volatile INTERP1_ACCUM1;

	/* 0xC8: Read/write access to BASE0 register. */
	uint32_t volatile INTERP1_BASE0;

	/* 0xCC: Read/write access to BASE1 register. */
	uint32_t volatile INTERP1_BASE1;

	/* 0xD0: Read/write access to BASE2 register. */
	uint32_t volatile INTERP1_BASE2;

	/* 0xD4: Read LANE0 result, and simultaneously write lane results to both accumulators (POP). */
	uint32_t volatile INTERP1_POP_LANE0;

	/* 0xD8: Read LANE1 result, and simultaneously write lane results to both accumulators (POP). */
	uint32_t volatile INTERP1_POP_LANE1;

	/* 0xDC: Read FULL result, and simultaneously write lane results to both accumulators (POP). */
	uint32_t volatile INTERP1_POP_FULL;

	/* 0xE0: Read LANE0 result, without altering any internal state (PEEK). */
	uint32_t volatile INTERP1_PEEK_LANE0;

	/* 0xE4: Read LANE1 result, without altering any internal state (PEEK). */
	uint32_t volatile INTERP1_PEEK_LANE1;

	/* 0xE8: Read FULL result, without altering any internal state (PEEK). */
	uint32_t volatile INTERP1_PEEK_FULL;

	/* 0xEC: Control register for lane 0 */
	uint32_t volatile INTERP1_CTRL_LANE0;
	/* Set if either OVERF0 or OVERF1 is set. */
#define SIO_INTERP1_CTRL_LANE0_OVERF				25u
	/* Indicates if any masked-off MSBs in ACCUM1 are set. */
#define SIO_INTERP1_CTRL_LANE0_OVERF1				24u
	/* Indicates if any masked-off MSBs in ACCUM0 are set. */
#define SIO_INTERP1_CTRL_LANE0_OVERF0				23u
	/* Only present on INTERP1 on each core. */
#define SIO_INTERP1_CTRL_LANE0_CLAMP				22u
	/* ORed into bits 29:28 of the lane result presented to the processor on the bus. */
#define SIO_INTERP1_CTRL_LANE0_FORCE_MSB_Msb			20u
#define SIO_INTERP1_CTRL_LANE0_FORCE_MSB_Lsb			19u
	/* If 1, mask + shift is bypassed for LANE0 result. */
#define SIO_INTERP1_CTRL_LANE0_ADD_RAW				18u
	/* If 1, feed the opposite lane's result into this lane's accumulator on POP. */
#define SIO_INTERP1_CTRL_LANE0_CROSS_RESULT			17u
	/* If 1, feed the opposite lane's accumulator into this lane's shift + mask hardware. */
#define SIO_INTERP1_CTRL_LANE0_CROSS_INPUT			16u
	/* If SIGNED is set, the shifted and masked accumulator value is sign-extended to 32 bits */
#define SIO_INTERP1_CTRL_LANE0_SIGNED				15u
	/* The most-significant bit allowed to pass by the mask (inclusive) */
#define SIO_INTERP1_CTRL_LANE0_MASK_MSB_Msb			14u
#define SIO_INTERP1_CTRL_LANE0_MASK_MSB_Lsb			10u
	/* The least-significant bit allowed to pass by the mask (inclusive) */
#define SIO_INTERP1_CTRL_LANE0_MASK_LSB_Msb			9u
#define SIO_INTERP1_CTRL_LANE0_MASK_LSB_Lsb			5u
	/* Logical right-shift applied to accumulator before masking */
#define SIO_INTERP1_CTRL_LANE0_SHIFT_Msb			4u
#define SIO_INTERP1_CTRL_LANE0_SHIFT_Lsb			0u

	/* 0xF0: Control register for lane 1 */
	uint32_t volatile INTERP1_CTRL_LANE1;
	/* ORed into bits 29:28 of the lane result presented to the processor on the bus. */
#define SIO_INTERP1_CTRL_LANE1_FORCE_MSB_Msb			20u
#define SIO_INTERP1_CTRL_LANE1_FORCE_MSB_Lsb			19u
	/* If 1, mask + shift is bypassed for LANE1 result. */
#define SIO_INTERP1_CTRL_LANE1_ADD_RAW				18u
	/* If 1, feed the opposite lane's result into this lane's accumulator on POP. */
#define SIO_INTERP1_CTRL_LANE1_CROSS_RESULT			17u
	/* If 1, feed the opposite lane's accumulator into this lane's shift + mask hardware. */
#define SIO_INTERP1_CTRL_LANE1_CROSS_INPUT			16u
	/* If SIGNED is set, the shifted and masked accumulator value is sign-extended to 32 bits */
#define SIO_INTERP1_CTRL_LANE1_SIGNED				15u
	/* The most-significant bit allowed to pass by the mask (inclusive) */
#define SIO_INTERP1_CTRL_LANE1_MASK_MSB_Msb			14u
#define SIO_INTERP1_CTRL_LANE1_MASK_MSB_Lsb			10u
	/* The least-significant bit allowed to pass by the mask (inclusive) */
#define SIO_INTERP1_CTRL_LANE1_MASK_LSB_Msb			9u
#define SIO_INTERP1_CTRL_LANE1_MASK_LSB_Lsb			5u
	/* Logical right-shift applied to accumulator before masking */
#define SIO_INTERP1_CTRL_LANE1_SHIFT_Msb			4u
#define SIO_INTERP1_CTRL_LANE1_SHIFT_Lsb			0u

	/* 0xF4: Values written here are atomically added to ACCUM0 */
	uint32_t volatile INTERP1_ACCUM0_ADD;
	/*  */
#define SIO_INTERP1_ACCUM0_ADD_INTERP1_ACCUM0_ADD_Msb		23u
#define SIO_INTERP1_ACCUM0_ADD_INTERP1_ACCUM0_ADD_Lsb		0u

	/* 0xF8: Values written here are atomically added to ACCUM1 */
	uint32_t volatile INTERP1_ACCUM1_ADD;
	/*  */
#define SIO_INTERP1_ACCUM1_ADD_INTERP1_ACCUM1_ADD_Msb		23u
#define SIO_INTERP1_ACCUM1_ADD_INTERP1_ACCUM1_ADD_Lsb		0u

	/* 0xFC: On write, the lower 16 bits go to BASE0, upper bits to BASE1 simultaneously. */
	uint32_t volatile INTERP1_BASE_1AND0;

	/* 0x100: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK0;

	/* 0x104: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK1;

	/* 0x108: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK2;

	/* 0x10C: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK3;

	/* 0x110: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK4;

	/* 0x114: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK5;

	/* 0x118: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK6;

	/* 0x11C: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK7;

	/* 0x120: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK8;

	/* 0x124: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK9;

	/* 0x128: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK10;

	/* 0x12C: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK11;

	/* 0x130: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK12;

	/* 0x134: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK13;

	/* 0x138: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK14;

	/* 0x13C: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK15;

	/* 0x140: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK16;

	/* 0x144: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK17;

	/* 0x148: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK18;

	/* 0x14C: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK19;

	/* 0x150: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK20;

	/* 0x154: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK21;

	/* 0x158: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK22;

	/* 0x15C: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK23;

	/* 0x160: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK24;

	/* 0x164: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK25;

	/* 0x168: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK26;

	/* 0x16C: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK27;

	/* 0x170: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK28;

	/* 0x174: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK29;

	/* 0x178: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK30;

	/* 0x17C: Reading from a spinlock address will: */
	uint32_t volatile SPINLOCK31;

};


#define PPB ((struct sdk_ppb *)0xE0000000)

struct sdk_ppb {

	/* 0x180 */
	uint8_t RESERVED0[0xE010-0x180];

	/* 0xE010: Use the SysTick Control and Status Register to enable the SysTick features. */
	uint32_t volatile SYST_CSR;
	/* Returns 1 if timer counted to 0 since last time this was read. */
#define PPB_SYST_CSR_COUNTFLAG					16u
	/* SysTick clock source. */
#define PPB_SYST_CSR_CLKSOURCE					2u
	/* Enables SysTick exception request: */
#define PPB_SYST_CSR_TICKINT					1u
	/* Enable SysTick counter: */
#define PPB_SYST_CSR_ENABLE					0u

	/* 0xE014: Use the SysTick Reload Value Register to specify the start value to load into the current value register when the counter reaches 0. */
	uint32_t volatile SYST_RVR;
	/* Value to load into the SysTick Current Value Register when the counter reaches 0. */
#define PPB_SYST_RVR_RELOAD_Msb					23u
#define PPB_SYST_RVR_RELOAD_Lsb					0u

	/* 0xE018: Use the SysTick Current Value Register to find the current value in the register. */
	uint32_t volatile SYST_CVR;
	/* Reads return the current value of the SysTick counter. */
#define PPB_SYST_CVR_CURRENT_Msb				23u
#define PPB_SYST_CVR_CURRENT_Lsb				0u

	/* 0xE01C: Use the SysTick Calibration Value Register to enable software to scale to any required speed using divide and multiply. */
	uint32_t volatile SYST_CALIB;
	/* If reads as 1, the Reference clock is not provided - the CLKSOURCE bit of the SysTick Control and Status register will be forced to 1 and cannot be cleared to 0. */
#define PPB_SYST_CALIB_NOREF					31u
	/* If reads as 1, the calibration value for 10ms is inexact (due to clock frequency). */
#define PPB_SYST_CALIB_SKEW					30u
	/* An optional Reload value to be used for 10ms (100Hz) timing, subject to system clock skew errors. */
#define PPB_SYST_CALIB_TENMS_Msb				23u
#define PPB_SYST_CALIB_TENMS_Lsb				0u

	/* 0xE020 */
	uint8_t RESERVED1[0xE100-0xE020];

	/* 0xE100: Use the Interrupt Set-Enable Register to enable interrupts and determine which interrupts are currently enabled. */
	uint32_t volatile NVIC_ISER;
	/* Interrupt set-enable bits. */
#define PPB_NVIC_ISER_SETENA_Msb				31u
#define PPB_NVIC_ISER_SETENA_Lsb				0u

	/* 0xE104 */
	uint8_t RESERVED2[0xE180-0xE104];

	/* 0xE180: Use the Interrupt Clear-Enable Registers to disable interrupts and determine which interrupts are currently enabled. */
	uint32_t volatile NVIC_ICER;
	/* Interrupt clear-enable bits. */
#define PPB_NVIC_ICER_CLRENA_Msb				31u
#define PPB_NVIC_ICER_CLRENA_Lsb				0u

	/* 0xE184 */
	uint8_t RESERVED3[0xE200-0xE184];

	/* 0xE200: The NVIC_ISPR forces interrupts into the pending state, and shows which interrupts are pending. */
	uint32_t volatile NVIC_ISPR;
	/* Interrupt set-pending bits. */
#define PPB_NVIC_ISPR_SETPEND_Msb				31u
#define PPB_NVIC_ISPR_SETPEND_Lsb				0u

	/* 0xE204 */
	uint8_t RESERVED4[0xE280-0xE204];

	/* 0xE280: Use the Interrupt Clear-Pending Register to clear pending interrupts and determine which interrupts are currently pending. */
	uint32_t volatile NVIC_ICPR;
	/* Interrupt clear-pending bits. */
#define PPB_NVIC_ICPR_CLRPEND_Msb				31u
#define PPB_NVIC_ICPR_CLRPEND_Lsb				0u

	/* 0xE284 */
	uint8_t RESERVED5[0xE400-0xE284];

	/* 0xE400: Use the Interrupt Priority Registers to assign a priority from 0 to 3 to each of the available interrupts. */
	uint32_t volatile NVIC_IPR0;
	/* Priority of interrupt 3 */
#define PPB_NVIC_IPR0_IP_3_Msb					31u
#define PPB_NVIC_IPR0_IP_3_Lsb					30u
	/* Priority of interrupt 2 */
#define PPB_NVIC_IPR0_IP_2_Msb					23u
#define PPB_NVIC_IPR0_IP_2_Lsb					22u
	/* Priority of interrupt 1 */
#define PPB_NVIC_IPR0_IP_1_Msb					15u
#define PPB_NVIC_IPR0_IP_1_Lsb					14u
	/* Priority of interrupt 0 */
#define PPB_NVIC_IPR0_IP_0_Msb					7u
#define PPB_NVIC_IPR0_IP_0_Lsb					6u

	/* 0xE404: Use the Interrupt Priority Registers to assign a priority from 0 to 3 to each of the available interrupts. */
	uint32_t volatile NVIC_IPR1;
	/* Priority of interrupt 7 */
#define PPB_NVIC_IPR1_IP_7_Msb					31u
#define PPB_NVIC_IPR1_IP_7_Lsb					30u
	/* Priority of interrupt 6 */
#define PPB_NVIC_IPR1_IP_6_Msb					23u
#define PPB_NVIC_IPR1_IP_6_Lsb					22u
	/* Priority of interrupt 5 */
#define PPB_NVIC_IPR1_IP_5_Msb					15u
#define PPB_NVIC_IPR1_IP_5_Lsb					14u
	/* Priority of interrupt 4 */
#define PPB_NVIC_IPR1_IP_4_Msb					7u
#define PPB_NVIC_IPR1_IP_4_Lsb					6u

	/* 0xE408: Use the Interrupt Priority Registers to assign a priority from 0 to 3 to each of the available interrupts. */
	uint32_t volatile NVIC_IPR2;
	/* Priority of interrupt 11 */
#define PPB_NVIC_IPR2_IP_11_Msb					31u
#define PPB_NVIC_IPR2_IP_11_Lsb					30u
	/* Priority of interrupt 10 */
#define PPB_NVIC_IPR2_IP_10_Msb					23u
#define PPB_NVIC_IPR2_IP_10_Lsb					22u
	/* Priority of interrupt 9 */
#define PPB_NVIC_IPR2_IP_9_Msb					15u
#define PPB_NVIC_IPR2_IP_9_Lsb					14u
	/* Priority of interrupt 8 */
#define PPB_NVIC_IPR2_IP_8_Msb					7u
#define PPB_NVIC_IPR2_IP_8_Lsb					6u

	/* 0xE40C: Use the Interrupt Priority Registers to assign a priority from 0 to 3 to each of the available interrupts. */
	uint32_t volatile NVIC_IPR3;
	/* Priority of interrupt 15 */
#define PPB_NVIC_IPR3_IP_15_Msb					31u
#define PPB_NVIC_IPR3_IP_15_Lsb					30u
	/* Priority of interrupt 14 */
#define PPB_NVIC_IPR3_IP_14_Msb					23u
#define PPB_NVIC_IPR3_IP_14_Lsb					22u
	/* Priority of interrupt 13 */
#define PPB_NVIC_IPR3_IP_13_Msb					15u
#define PPB_NVIC_IPR3_IP_13_Lsb					14u
	/* Priority of interrupt 12 */
#define PPB_NVIC_IPR3_IP_12_Msb					7u
#define PPB_NVIC_IPR3_IP_12_Lsb					6u

	/* 0xE410: Use the Interrupt Priority Registers to assign a priority from 0 to 3 to each of the available interrupts. */
	uint32_t volatile NVIC_IPR4;
	/* Priority of interrupt 19 */
#define PPB_NVIC_IPR4_IP_19_Msb					31u
#define PPB_NVIC_IPR4_IP_19_Lsb					30u
	/* Priority of interrupt 18 */
#define PPB_NVIC_IPR4_IP_18_Msb					23u
#define PPB_NVIC_IPR4_IP_18_Lsb					22u
	/* Priority of interrupt 17 */
#define PPB_NVIC_IPR4_IP_17_Msb					15u
#define PPB_NVIC_IPR4_IP_17_Lsb					14u
	/* Priority of interrupt 16 */
#define PPB_NVIC_IPR4_IP_16_Msb					7u
#define PPB_NVIC_IPR4_IP_16_Lsb					6u

	/* 0xE414: Use the Interrupt Priority Registers to assign a priority from 0 to 3 to each of the available interrupts. */
	uint32_t volatile NVIC_IPR5;
	/* Priority of interrupt 23 */
#define PPB_NVIC_IPR5_IP_23_Msb					31u
#define PPB_NVIC_IPR5_IP_23_Lsb					30u
	/* Priority of interrupt 22 */
#define PPB_NVIC_IPR5_IP_22_Msb					23u
#define PPB_NVIC_IPR5_IP_22_Lsb					22u
	/* Priority of interrupt 21 */
#define PPB_NVIC_IPR5_IP_21_Msb					15u
#define PPB_NVIC_IPR5_IP_21_Lsb					14u
	/* Priority of interrupt 20 */
#define PPB_NVIC_IPR5_IP_20_Msb					7u
#define PPB_NVIC_IPR5_IP_20_Lsb					6u

	/* 0xE418: Use the Interrupt Priority Registers to assign a priority from 0 to 3 to each of the available interrupts. */
	uint32_t volatile NVIC_IPR6;
	/* Priority of interrupt 27 */
#define PPB_NVIC_IPR6_IP_27_Msb					31u
#define PPB_NVIC_IPR6_IP_27_Lsb					30u
	/* Priority of interrupt 26 */
#define PPB_NVIC_IPR6_IP_26_Msb					23u
#define PPB_NVIC_IPR6_IP_26_Lsb					22u
	/* Priority of interrupt 25 */
#define PPB_NVIC_IPR6_IP_25_Msb					15u
#define PPB_NVIC_IPR6_IP_25_Lsb					14u
	/* Priority of interrupt 24 */
#define PPB_NVIC_IPR6_IP_24_Msb					7u
#define PPB_NVIC_IPR6_IP_24_Lsb					6u

	/* 0xE41C: Use the Interrupt Priority Registers to assign a priority from 0 to 3 to each of the available interrupts. */
	uint32_t volatile NVIC_IPR7;
	/* Priority of interrupt 31 */
#define PPB_NVIC_IPR7_IP_31_Msb					31u
#define PPB_NVIC_IPR7_IP_31_Lsb					30u
	/* Priority of interrupt 30 */
#define PPB_NVIC_IPR7_IP_30_Msb					23u
#define PPB_NVIC_IPR7_IP_30_Lsb					22u
	/* Priority of interrupt 29 */
#define PPB_NVIC_IPR7_IP_29_Msb					15u
#define PPB_NVIC_IPR7_IP_29_Lsb					14u
	/* Priority of interrupt 28 */
#define PPB_NVIC_IPR7_IP_28_Msb					7u
#define PPB_NVIC_IPR7_IP_28_Lsb					6u

	/* 0xE420 */
	uint8_t RESERVED6[0xED00-0xE420];

	/* 0xED00: Read the CPU ID Base Register to determine: the ID number of the processor core, the version number of the processor core, the implementation details of the processor core. */
	uint32_t volatile CPUID;
	/* Implementor code: 0x41 = ARM */
#define PPB_CPUID_IMPLEMENTER_Msb				31u
#define PPB_CPUID_IMPLEMENTER_Lsb				24u
	/* Major revision number n in the rnpm revision status: */
#define PPB_CPUID_VARIANT_Msb					23u
#define PPB_CPUID_VARIANT_Lsb					20u
	/* Constant that defines the architecture of the processor: */
#define PPB_CPUID_ARCHITECTURE_Msb				19u
#define PPB_CPUID_ARCHITECTURE_Lsb				16u
	/* Number of processor within family: 0xC60 = Cortex-M0+ */
#define PPB_CPUID_PARTNO_Msb					15u
#define PPB_CPUID_PARTNO_Lsb					4u
	/* Minor revision number m in the rnpm revision status: */
#define PPB_CPUID_REVISION_Msb					3u
#define PPB_CPUID_REVISION_Lsb					0u

	/* 0xED04: Use the Interrupt Control State Register to set a pending Non-Maskable Interrupt (NMI), set or clear a pending PendSV, set or clear a pending SysTick, check for pending exceptions, check the vector number of the highest priority pended exception, check the vector number of the active exception. */
	uint32_t volatile ICSR;
	/* Setting this bit will activate an NMI. */
#define PPB_ICSR_NMIPENDSET					31u
	/* PendSV set-pending bit. */
#define PPB_ICSR_PENDSVSET					28u
	/* PendSV clear-pending bit. */
#define PPB_ICSR_PENDSVCLR					27u
	/* SysTick exception set-pending bit. */
#define PPB_ICSR_PENDSTSET					26u
	/* SysTick exception clear-pending bit. */
#define PPB_ICSR_PENDSTCLR					25u
	/* The system can only access this bit when the core is halted. */
#define PPB_ICSR_ISRPREEMPT					23u
	/* External interrupt pending flag */
#define PPB_ICSR_ISRPENDING					22u
	/* Indicates the exception number for the highest priority pending exception: 0 = no pending exceptions. */
#define PPB_ICSR_VECTPENDING_Msb				20u
#define PPB_ICSR_VECTPENDING_Lsb				12u
	/* Active exception number field. */
#define PPB_ICSR_VECTACTIVE_Msb					8u
#define PPB_ICSR_VECTACTIVE_Lsb					0u

	/* 0xED08: The VTOR holds the vector table offset address. */
	uint32_t volatile VTOR;
	/* Bits [31:8] of the indicate the vector table offset address. */
#define PPB_VTOR_TBLOFF_Msb					31u
#define PPB_VTOR_TBLOFF_Lsb					8u

	/* 0xED0C: Use the Application Interrupt and Reset Control Register to: determine data endianness, clear all active state information from debug halt mode, request a system reset. */
	uint32_t volatile AIRCR;
	/* Register key: */
#define PPB_AIRCR_VECTKEY_Msb					31u
#define PPB_AIRCR_VECTKEY_Lsb					16u
	/* Data endianness implemented: */
#define PPB_AIRCR_ENDIANESS					15u
	/* Writing 1 to this bit causes the SYSRESETREQ signal to the outer system to be asserted to request a reset. */
#define PPB_AIRCR_SYSRESETREQ					2u
	/* Clears all active state information for fixed and configurable exceptions. */
#define PPB_AIRCR_VECTCLRACTIVE					1u

	/* 0xED10: System Control Register. */
	uint32_t volatile SCR;
	/* Send Event on Pending bit: */
#define PPB_SCR_SEVONPEND					4u
	/* Controls whether the processor uses sleep or deep sleep as its low power mode: */
#define PPB_SCR_SLEEPDEEP					2u
	/* Indicates sleep-on-exit when returning from Handler mode to Thread mode: */
#define PPB_SCR_SLEEPONEXIT					1u

	/* 0xED14: The Configuration and Control Register permanently enables stack alignment and causes unaligned accesses to result in a Hard Fault. */
	uint32_t volatile CCR;
	/* Always reads as one, indicates 8-byte stack alignment on exception entry. */
#define PPB_CCR_STKALIGN					9u
	/* Always reads as one, indicates that all unaligned accesses generate a HardFault. */
#define PPB_CCR_UNALIGN_TRP					3u

	/* 0xED18 */
	uint8_t RESERVED7[0xED1C-0xED18];

	/* 0xED1C: System handlers are a special class of exception handler that can have their priority set to any of the priority levels. */
	uint32_t volatile SHPR2;
	/* Priority of system handler 11, SVCall */
#define PPB_SHPR2_PRI_11_Msb					31u
#define PPB_SHPR2_PRI_11_Lsb					30u

	/* 0xED20: System handlers are a special class of exception handler that can have their priority set to any of the priority levels. */
	uint32_t volatile SHPR3;
	/* Priority of system handler 15, SysTick */
#define PPB_SHPR3_PRI_15_Msb					31u
#define PPB_SHPR3_PRI_15_Lsb					30u
	/* Priority of system handler 14, PendSV */
#define PPB_SHPR3_PRI_14_Msb					23u
#define PPB_SHPR3_PRI_14_Lsb					22u

	/* 0xED24: Use the System Handler Control and State Register to determine or clear the pending status of SVCall. */
	uint32_t volatile SHCSR;
	/* Reads as 1 if SVCall is Pending. */
#define PPB_SHCSR_SVCALLPENDED					15u

	/* 0xED28 */
	uint8_t RESERVED8[0xED90-0xED28];

	/* 0xED90: Read the MPU Type Register to determine if the processor implements an MPU, and how many regions the MPU supports. */
	uint32_t volatile MPU_TYPE;
	/* Instruction region. */
#define PPB_MPU_TYPE_IREGION_Msb				23u
#define PPB_MPU_TYPE_IREGION_Lsb				16u
	/* Number of regions supported by the MPU. */
#define PPB_MPU_TYPE_DREGION_Msb				15u
#define PPB_MPU_TYPE_DREGION_Lsb				8u
	/* Indicates support for separate instruction and data address maps. */
#define PPB_MPU_TYPE_SEPARATE					0u

	/* 0xED94: Use the MPU Control Register to enable and disable the MPU, and to control whether the default memory map is enabled as a background region for privileged accesses, and whether the MPU is enabled for HardFaults and NMIs. */
	uint32_t volatile MPU_CTRL;
	/* Controls whether the default memory map is enabled as a background region for privileged accesses. */
#define PPB_MPU_CTRL_PRIVDEFENA					2u
	/* Controls the use of the MPU for HardFaults and NMIs. */
#define PPB_MPU_CTRL_HFNMIENA					1u
	/* Enables the MPU. */
#define PPB_MPU_CTRL_ENABLE					0u

	/* 0xED98: Use the MPU Region Number Register to select the region currently accessed by MPU_RBAR and MPU_RASR. */
	uint32_t volatile MPU_RNR;
	/* Indicates the MPU region referenced by the MPU_RBAR and MPU_RASR registers. */
#define PPB_MPU_RNR_REGION_Msb					3u
#define PPB_MPU_RNR_REGION_Lsb					0u

	/* 0xED9C: Read the MPU Region Base Address Register to determine the base address of the region identified by MPU_RNR. */
	uint32_t volatile MPU_RBAR;
	/* Base address of the region. */
#define PPB_MPU_RBAR_ADDR_Msb					31u
#define PPB_MPU_RBAR_ADDR_Lsb					8u
	/* On writes, indicates whether the write must update the base address of the region identified by the REGION field, updating the MPU_RNR to indicate this new region. */
#define PPB_MPU_RBAR_VALID					4u
	/* On writes, specifies the number of the region whose base address to update provided VALID is set written as 1. */
#define PPB_MPU_RBAR_REGION_Msb					3u
#define PPB_MPU_RBAR_REGION_Lsb					0u

	/* 0xEDA0: Use the MPU Region Attribute and Size Register to define the size, access behaviour and memory type of the region identified by MPU_RNR, and enable that region. */
	uint32_t volatile MPU_RASR;
	/* The MPU Region Attribute field. */
#define PPB_MPU_RASR_ATTRS_Msb					31u
#define PPB_MPU_RASR_ATTRS_Lsb					16u
	/* Subregion Disable. */
#define PPB_MPU_RASR_SRD_Msb					15u
#define PPB_MPU_RASR_SRD_Lsb					8u
	/* Indicates the region size. Region size in bytes = 2^(SIZE+1). The minimum permitted value is 7 (b00111) = 256Bytes */
#define PPB_MPU_RASR_SIZE_Msb					5u
#define PPB_MPU_RASR_SIZE_Lsb					1u
	/* Enables the region. */
#define PPB_MPU_RASR_ENABLE					0u

};

#endif
