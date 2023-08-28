#ifndef __PLATFORM_PINCONFIG_H
#define __PLATFORM_PINCONFIG_H

/* Default S5L8950X SoC Pin Configuration */

#define FMI_DRIVE_STR	DRIVE_X2 | SLOW_SLEW

static const u_int32_t gpio_default_cfg[GPIO_GROUP_COUNT * GPIOPADPINS] = {
/* Port  0 */
	CFG_IN,								// GPIO0		-> MENU_KEY (REQUEST_DFU2)
	CFG_IN,								// GPIO1		-> HOLD_KEY (REQUEST_DFU1)
	CFG_DISABLED,							// GPIO2		->
	CFG_DISABLED,							// GPIO3		->
	CFG_DISABLED,							// GPIO4		->
	CFG_DISABLED,							// GPIO5		->
	CFG_DISABLED,							// GPIO6		->
	CFG_DISABLED,							// GPIO7		->

/* Port  1 */
	CFG_DISABLED,							// GPIO8		->
	CFG_DISABLED,							// GPIO9		->
	CFG_DISABLED,							// GPIO10		->
	CFG_DISABLED,							// GPIO11		->
	CFG_DISABLED,							// GPIO12		->
	CFG_DISABLED,							// GPIO13		->
	CFG_DISABLED,							// GPIO14		->
	CFG_DISABLED,							// GPIO15		->

/* Port  2 */
	CFG_DISABLED,							// GPIO16		-> BOARD_ID[3]
	CFG_DISABLED,							// GPIO17		->
	CFG_DISABLED,							// GPIO18		-> BOOT_CONFIG[0]
	CFG_DISABLED,							// GPIO19		->
	CFG_DISABLED,							// EHCI_PORT_PWR[0]	->
	CFG_DISABLED,							// EHCI_PORT_PWR[1]	->
	CFG_DISABLED,							// EHCI_PORT_PWR[2]	->
	CFG_DISABLED,							// EHCI_PORT_PWR[3]	->

/* Port  3 */
	CFG_DISABLED,							// UART1_TXD		->
	CFG_DISABLED,							// UART1_RXD		->
	CFG_DISABLED,							// UART1_RTSN		->
	CFG_DISABLED,							// UART1_CTSN		->
	CFG_DISABLED,							// UART2_TXD		->
	CFG_DISABLED,							// UART2_RXD		->
	CFG_DISABLED,							// UART2_RTSN		->
	CFG_DISABLED,							// UART2_CTSN		->

/* Port  4 */
	CFG_DISABLED,							// UART3_TXD		->
	CFG_DISABLED,							// UART3_RXD		->
	CFG_DISABLED,							// UART3_RTSN		->
	CFG_DISABLED,							// UART3_CTSN		->
	CFG_DISABLED,							// UART4_TXD/SPI4_MOSI	->
	CFG_DISABLED,							// UART4_RXD/SPI4_MISO	->
	CFG_DISABLED,							// UART4_RTSN/SPI4_SCLK	->
	CFG_DISABLED,							// UART4_CTSN/SPI4_SSIN	->

/* Port  5 */
	CFG_DISABLED,							// UART6_TXD		->
	CFG_DISABLED,							// UART6_RXD		->
	CFG_DISABLED,							// UART6_RTSN		->
	CFG_DISABLED,							// UART6_CTSN		->
	CFG_DISABLED,							// UART5_RXD/UART5_RTXD	->
	CFG_DISABLED,							// UART5_TXD		->
	CFG_DISABLED,							// SPI1_SCLK		->
	CFG_DISABLED,							// SPI1_MOSI		->

/* Port  6 */
	CFG_DISABLED,							// SPI1_MISO		->
	CFG_DISABLED,							// SPI1_SSIN		->
	CFG_DISABLED,							// SPI0_SCLK		-> SPI0_SCLK/BOARD_ID[0]
	CFG_DISABLED,							// SPI0_MOSI		-> SPI0_MOSI/BOARD_ID[1]
	CFG_DISABLED,							// SPI0_MISO		-> SPI0_MISO/BOARD_ID[2]
	CFG_DISABLED | PULL_UP,						// SPI0_SSIN		-> SPI0_SSIN
	CFG_DISABLED,							// SPI2_SCLK		->
	CFG_DISABLED,							// SPI2_MOSI		->

/* Port  7 */
	CFG_DISABLED,							// SPI2_MISO		->
	CFG_DISABLED,							// SPI2_SSIN		->
	CFG_DISABLED,							// I2C0_SDA		->
	CFG_DISABLED,							// I2C0_SCL		->
	CFG_DISABLED,							// I2C1_SDA		->
	CFG_DISABLED,							// I2C1_SCL		->
	CFG_DISABLED,							// ISP0_SDA		->
	CFG_DISABLED,							// ISP0_SCL		->

/* Port  8 */
	CFG_DISABLED,							// ISP1_SDA		->
	CFG_DISABLED,							// ISP1_SCL		->
	CFG_DISABLED,							// MIPI_VSYNC		->
	CFG_DISABLED,							// TMR32_PWM0		->
	CFG_DISABLED,							// TMR32_PWM1		->
	CFG_DISABLED,							// TMR32_PWM2		->
	CFG_DISABLED,							// SWI_DATA		->
	CFG_DISABLED,							// DWI_DI		->

/* Port  9 */
	CFG_DISABLED,							// DWI_DO		->
	CFG_DISABLED,							// DWI_CLK		->
	CFG_DISABLED,							// SENSOR0_RST		->
	CFG_DISABLED,							// SENSOR0_CLK		->
	CFG_DISABLED,							// SENSOR1_RST		->
	CFG_DISABLED,							// SENSOR1_CLK		->
	CFG_FUNC0,							// CPU0_SWITCH		->
	CFG_FUNC0,							// CPU1_SWITCH		->

/* Port 10 */
	CFG_DISABLED,							// ISP0_PRE_FLASH	->
	CFG_DISABLED,							// ISP0_FLASH		->
	CFG_DISABLED,							// ISP1_PRE_FLASH	->
	CFG_DISABLED,							// ISP1_FLASH		->
	CFG_DISABLED,							// SPI3_MOSI		-> 
	CFG_DISABLED,							// SPI3_MISO		-> 
	CFG_DISABLED,							// SPI3_SCLK		-> 
	CFG_DISABLED,							// SPI3_SSIN		-> 

/* Port 11 */
	CFG_DISABLED,							// I2C2_SDA		->
	CFG_DISABLED,							// I2C2_SCL		->
	CFG_DISABLED,							// GPIO_3V0		->
	CFG_DISABLED,							// GPIO_3V1		->
	CFG_DISABLED,							// DP_HPD		->
	CFG_DISABLED,							// LPDP_HPD		->
	CFG_DISABLED,							// UART0_TXD		->
	CFG_DISABLED,							// UART0_RXD		->

/* Port 12 */
	CFG_DISABLED,							// TST_CLKOUT		->
	CFG_DISABLED,							// TST_STPCLK		->
	CFG_DISABLED,							// WDOG			->
	CFG_DISABLED,							// 			->
	CFG_DISABLED,							// 			->
	CFG_DISABLED,							// 			->
	CFG_DISABLED,							// 			->
	CFG_DISABLED,							// 			->

/* Port 13 */
	CFG_DISABLED,							// 			->
	CFG_DISABLED,							// 			->
	CFG_DISABLED,							// 			->
	CFG_DISABLED,							// 			->
	CFG_DISABLED,							// 			->
	CFG_DISABLED,							// 			->
	CFG_DISABLED,							// 			->
	CFG_DISABLED,							// 			->

/* Port 14 */
	CFG_DISABLED,							// 			->
	CFG_DISABLED,							// 			->
	CFG_DISABLED,							// 			->
	CFG_DISABLED,							// 			->
	CFG_DISABLED,							// 			->
	CFG_DISABLED,							// 			->
	CFG_DISABLED,							// 			->
	CFG_DISABLED,							// 			->

/* Port 15 */
	CFG_DISABLED,							// 			->
	CFG_DISABLED,							// 			->
	CFG_DISABLED,							// 			->
	CFG_DISABLED,							// 			->
	CFG_DISABLED,							// 			->
	CFG_DISABLED,							// 			->
	CFG_DISABLED,							// 			->
	CFG_DISABLED,							// 			->

/* Port 16 */
	CFG_DISABLED,							// I2S0_MCK		->
	CFG_DISABLED,							// I2S0_LRCK		->
	CFG_DISABLED,							// I2S0_BCLK		->
	CFG_DISABLED,							// I2S0_DOUT		->
	CFG_DISABLED,							// I2S0_DIN		->
	CFG_DISABLED,							// I2S1_MCK		->
	CFG_DISABLED,							// I2S1_LRCK		->
	CFG_DISABLED,							// I2S1_BCLK		->

/* Port 17 */
	CFG_DISABLED,							// I2S1_DOUT		->
	CFG_DISABLED,							// I2S1_DIN		->
	CFG_DISABLED,							// I2S2_MCK		->
	CFG_DISABLED,							// I2S2_LRCK		->
	CFG_DISABLED,							// I2S2_BCLK		->
	CFG_DISABLED,							// I2S2_DOUT		->
	CFG_DISABLED,							// I2S2_DIN		->
	CFG_DISABLED,							// I2S3_MCK		->

/* Port 18 */
	CFG_DISABLED,							// I2S3_LRCK		->
	CFG_DISABLED,							// I2S3_BCLK		->
	CFG_DISABLED,							// I2S3_DOUT		->
	CFG_DISABLED,							// I2S3_DIN		->
	CFG_DISABLED,							// I2S4_MCK		->
	CFG_DISABLED,							// I2S4_LRCK		->
	CFG_DISABLED,							// I2S4_BCLK		->
	CFG_DISABLED,							// I2S4_DOUT		->

/* Port 19 */
	CFG_DISABLED,							// I2S4_DIN		->
	CFG_DISABLED,							// SPDIF		->
	CFG_DISABLED | FMI_DRIVE_STR,					// FMI0_CEN3		->
	CFG_DISABLED | FMI_DRIVE_STR,					// FMI0_CEN2		->
	CFG_DISABLED | FMI_DRIVE_STR,					// FMI0_CEN1		->
	CFG_DISABLED | FMI_DRIVE_STR,					// FMI0_CEN0		->
	CFG_DISABLED | PULL_DOWN | FMI_DRIVE_STR,			// FMI0_CLE		->
	CFG_DISABLED | PULL_DOWN | FMI_DRIVE_STR,			// FMI0_ALE		->

/* Port 20 */
	CFG_DISABLED | PULL_UP | FMI_DRIVE_STR,				// FMI0_REN		->
	CFG_DISABLED | PULL_UP | FMI_DRIVE_STR,				// FMI0_WEN		->
	CFG_DISABLED | PULL_DOWN | FMI_DRIVE_STR,			// FMI0_WENN		->
	CFG_DISABLED | PULL_DOWN | FMI_DRIVE_STR,			// FMI0_IO7		->
	CFG_DISABLED | PULL_DOWN | FMI_DRIVE_STR,			// FMI0_IO6		->
	CFG_DISABLED | PULL_DOWN | FMI_DRIVE_STR,			// FMI0_IO5		->
	CFG_DISABLED | PULL_DOWN | FMI_DRIVE_STR,			// FMI0_IO4		->
	CFG_DISABLED | PULL_DOWN | FMI_DRIVE_STR,			// FMI0_DQS		->

/* Port 21 */
	CFG_DISABLED | PULL_UP | FMI_DRIVE_STR,				// FMI0_DQSN		->
	CFG_DISABLED | PULL_DOWN | FMI_DRIVE_STR,			// FMI0_IO3		->
	CFG_DISABLED | PULL_DOWN | FMI_DRIVE_STR,			// FMI0_IO2		->
	CFG_DISABLED | PULL_DOWN | FMI_DRIVE_STR,			// FMI0_IO1		->
	CFG_DISABLED | PULL_DOWN | FMI_DRIVE_STR,			// FMI0_IO0		->
	CFG_DISABLED | FMI_DRIVE_STR,					// FMI0_CEN7		->
	CFG_DISABLED | FMI_DRIVE_STR,					// FMI0_CEN6		->
	CFG_DISABLED | FMI_DRIVE_STR,					// FMI0_CEN5		->

/* Port 22 */
	CFG_DISABLED | FMI_DRIVE_STR,					// FMI0_CEN4		->
	CFG_DISABLED | FMI_DRIVE_STR,					// FMI1_CEN3		->
	CFG_DISABLED | FMI_DRIVE_STR,					// FMI1_CEN2		->
	CFG_DISABLED | FMI_DRIVE_STR,					// FMI1_CEN1		->
	CFG_DISABLED | FMI_DRIVE_STR,					// FMI1_CEN0		->
	CFG_DISABLED | PULL_DOWN | FMI_DRIVE_STR,			// FMI1_CLE		->
	CFG_DISABLED | PULL_DOWN | FMI_DRIVE_STR,			// FMI1_ALE		->
	CFG_DISABLED | PULL_UP | FMI_DRIVE_STR,				// FMI1_REN		->

/* Port 23 */
	CFG_DISABLED | PULL_UP | FMI_DRIVE_STR,				// FMI1_WEN		->
	CFG_DISABLED | PULL_DOWN | FMI_DRIVE_STR,			// FMI1_WENN		->
	CFG_DISABLED | PULL_DOWN | FMI_DRIVE_STR,			// FMI1_IO7		->
	CFG_DISABLED | PULL_DOWN | FMI_DRIVE_STR,			// FMI1_IO6		->
	CFG_DISABLED | PULL_DOWN | FMI_DRIVE_STR,			// FMI1_IO5		->
	CFG_DISABLED | PULL_DOWN | FMI_DRIVE_STR,			// FMI1_IO4		->
	CFG_DISABLED | PULL_DOWN | FMI_DRIVE_STR,			// FMI1_DQS		->
	CFG_DISABLED | PULL_UP | FMI_DRIVE_STR,				// FMI1_DQSN		->

/* Port 24 */
	CFG_DISABLED | PULL_DOWN | FMI_DRIVE_STR,			// FMI1_IO3		->
	CFG_DISABLED | PULL_DOWN | FMI_DRIVE_STR,			// FMI1_IO2		->
	CFG_DISABLED | PULL_DOWN | FMI_DRIVE_STR,			// FMI1_IO1		->
	CFG_DISABLED | PULL_DOWN | FMI_DRIVE_STR,			// FMI1_IO0		->
	CFG_DISABLED | FMI_DRIVE_STR,					// FMI1_CEN7		->
	CFG_DISABLED | FMI_DRIVE_STR,					// FMI1_CEN6		->
	CFG_DISABLED | FMI_DRIVE_STR,					// FMI1_CEN5		->
	CFG_DISABLED | FMI_DRIVE_STR,					// FMI1_CEN4		->

/* Port 25 */
	CFG_DISABLED,							// GPIO20		->
	CFG_DISABLED,							// GPIO21		->
	CFG_DISABLED,							// GPIO22		->
	CFG_DISABLED,							// GPIO23		->
	CFG_DISABLED,							// GPIO24		->
	CFG_DISABLED,							// GPIO25		-> BOOT_CONFIG[1]
	CFG_IN | PULL_DOWN,						// GPIO26		-> FORCE_DFU
	CFG_DISABLED | PULL_DOWN,					// GPIO27		-> DFU_STATUS

/* Port 26 */
	CFG_DISABLED,							// GPIO28		-> BOOT_CONFIG[2]
	CFG_DISABLED,							// GPIO29		-> BOOT_CONFIG[3]
	CFG_DISABLED,							// GPIO30		->
	CFG_DISABLED,							// GPIO31		->
	CFG_DISABLED,							//			->
	CFG_DISABLED,							//			->
	CFG_DISABLED,							//			->
	CFG_DISABLED,							//			->

/* Port 27 */
	CFG_DISABLED,							//			->
	CFG_DISABLED,							//			->
	CFG_DISABLED,							//			->
	CFG_DISABLED,							//			->
	CFG_DISABLED,							//			->
	CFG_DISABLED,							//			->
	CFG_DISABLED,							//			->
	CFG_DISABLED,							//			->

/* Port 28 */
	CFG_DISABLED,							// GPIO32		->
	CFG_DISABLED,							// GPIO33		->
	CFG_DISABLED,							// GPIO34		->
	CFG_DISABLED,							// GPIO35		->
	CFG_DISABLED,							// GPIO36		->
	CFG_DISABLED,							// GPIO37		->
	CFG_DISABLED,							// GPIO38		->
	CFG_DISABLED,							// GPIO39		->
};

#endif /* ! __PLATFORM_PINCONFIG_H */
