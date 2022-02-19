#include <stddef.h>
#include <stdint.h>

#define I2C0 ((struct zmcu_i2c *)0x40044000)
#define I2C1 ((struct zmcu_i2c *)0x40048000)

struct zmcu_i2c {

	/* 0x04: I2C Target Address Register */
	uint32_t volatile IC_TAR;

	/* 0x08: I2C Slave Address Register */
	uint32_t volatile IC_SAR;

	/* 0x10: I2C Rx/Tx Data Buffer and Command Register */
	uint32_t volatile IC_DATA_CMD;

	/* 0x14: Standard Speed I2C Clock SCL High Count Register */
	uint32_t volatile IC_SS_SCL_HCNT;

	/* 0x18: Standard Speed I2C Clock SCL Low Count Register */
	uint32_t volatile IC_SS_SCL_LCNT;

	/* 0x1C: Fast Mode or Fast Mode Plus I2C Clock SCL High Count Register */
	uint32_t volatile IC_FS_SCL_HCNT;

	/* 0x20: Fast Mode or Fast Mode Plus I2C Clock SCL Low Count Register */
	uint32_t volatile IC_FS_SCL_LCNT;

	/* 0x2C: I2C Interrupt Status Register */
	uint32_t volatile IC_INTR_STAT;

	/* 0x30: I2C Interrupt Mask Register */
	uint32_t volatile IC_INTR_MASK;

	/* 0x34: I2C Raw Interrupt Status Register */
	uint32_t volatile IC_RAW_INTR_STAT;

	/* 0x38: I2C Receive FIFO Threshold Register */
	uint32_t volatile IC_RX_TL;

	/* 0x3C: I2C Transmit FIFO Threshold Register */
	uint32_t volatile IC_TX_TL;

	/* 0x40: Clear Combined and Individual Interrupt Register */
	uint32_t volatile IC_CLR_INTR;

	/* 0x44: Clear RX_UNDER Interrupt Register */
	uint32_t volatile IC_CLR_RX_UNDER;

	/* 0x48: Clear RX_OVER Interrupt Register */
	uint32_t volatile IC_CLR_RX_OVER;

	/* 0x4C: Clear TX_OVER Interrupt Register */
	uint32_t volatile IC_CLR_TX_OVER;

	/* 0x50: Clear RD_REQ Interrupt Register */
	uint32_t volatile IC_CLR_RD_REQ;

	/* 0x54: Clear TX_ABRT Interrupt Register */
	uint32_t volatile IC_CLR_TX_ABRT;

	/* 0x58: Clear RX_DONE Interrupt Register */
	uint32_t volatile IC_CLR_RX_DONE;

	/* 0x5C: Clear ACTIVITY Interrupt Register */
	uint32_t volatile IC_CLR_ACTIVITY;

	/* 0x60: Clear STOP_DET Interrupt Register */
	uint32_t volatile IC_CLR_STOP_DET;

	/* 0x64: Clear START_DET Interrupt Register */
	uint32_t volatile IC_CLR_START_DET;

	/* 0x68: Clear GEN_CALL Interrupt Register */
	uint32_t volatile IC_CLR_GEN_CALL;

	/* 0x6C: I2C ENABLE Register */
	uint32_t volatile IC_ENABLE;

	/* 0x70: I2C STATUS Register */
	uint32_t volatile IC_STATUS;

	/* 0x74: I2C Transmit FIFO Level Register */
	uint32_t volatile IC_TXFLR;

	/* 0x78: I2C Receive FIFO Level Register */
	uint32_t volatile IC_RXFLR;

	/* 0x7C: I2C SDA Hold Time Length Register */
	uint32_t volatile IC_SDA_HOLD;

	/* 0x80: I2C Transmit Abort Source Register */
	uint32_t volatile IC_TX_ABRT_SOURCE;

	/* 0x84: Generate Slave Data NACK Register */
	uint32_t volatile IC_SLV_DATA_NACK_ONLY;

	/* 0x88: DMA Control Register */
	uint32_t volatile IC_DMA_CR;

	/* 0x8C: DMA Transmit Data Level Register */
	uint32_t volatile IC_DMA_TDLR;

	/* 0x90: DMA Transmit Data Level Register */
	uint32_t volatile IC_DMA_RDLR;

	/* 0x94: I2C SDA Setup Register */
	uint32_t volatile IC_SDA_SETUP;

	/* 0x98: I2C ACK General Call Register */
	uint32_t volatile IC_ACK_GENERAL_CALL;

	/* 0x9C: I2C Enable Status Register */
	uint32_t volatile IC_ENABLE_STATUS;

	/* 0xA0: I2C SS, FS or FM+ spike suppression limit */
	uint32_t volatile IC_FS_SPKLEN;

	/* 0xA8: Clear RESTART_DET Interrupt Register */
	uint32_t volatile IC_CLR_RESTART_DET;

	/* 0xF4: Component Parameter Register 1 */
	uint32_t volatile IC_COMP_PARAM_1;

	/* 0xF8: I2C Component Version Register */
	uint32_t volatile IC_COMP_VERSION;

	/* 0xFC: I2C Component Type Register */
	uint32_t volatile IC_COMP_TYPE;

};
