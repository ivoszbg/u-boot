#ifndef __PLATFORM_GPIODEF_H
#define __PLATFORM_GPIODEF_H

/* S5L8950X specific gpio -> pin mappings */

#include "gpio/gpio.h"
#include "../regs.h"

#if WITH_TARGET_CONFIG
# include "n42gpiodef.h"
#endif

/* define platform-specific gpios in a generic fashion here. */
#define GPIO_IIC0_SCL		GPIO( 7, 3)
#define GPIO_IIC0_SDA		GPIO( 7, 2)
#define GPIO_IIC1_SCL		GPIO( 7, 5)
#define GPIO_IIC1_SDA		GPIO( 7, 4)
#define GPIO_IIC2_SCL		GPIO(11, 1)
#define GPIO_IIC2_SDA		GPIO(11, 0)

#define GPIO_BOARD_ID0		GPIO( 6, 2)
#define GPIO_BOARD_ID1		GPIO( 6, 3)
#define GPIO_BOARD_ID2		GPIO( 6, 4)
#define GPIO_BOARD_ID3		GPIO( 2, 0)

#define GPIO_BOOT_CONFIG0	GPIO( 2, 2)
#define GPIO_BOOT_CONFIG1	GPIO(25, 5)
#define GPIO_BOOT_CONFIG2	GPIO(26, 0)
#define GPIO_BOOT_CONFIG3	GPIO(26, 1)

#define GPIO_REQUEST_DFU1	GPIO( 0, 1)	// formerly known as HOLD_KEY
#define GPIO_REQUEST_DFU2	GPIO( 0, 0)	// formerly known as MENU_KEY
#define GPIO_FORCE_DFU		GPIO(25, 6)
#define GPIO_DFU_STATUS		GPIO(25, 7)

#define SPI_NOR0		(0)
#define SPI_NOR3		(3)

#if SUPPORT_FPGA
#define GPIO_SPI0_CS		GPIO(GPIO_PAD_SPI, 0)
#define GPIO_SPI3_CS		GPIO(GPIO_PAD_SPI, 3)
#else
#define GPIO_SPI0_CS		GPIO( 6, 5)
#define GPIO_SPI3_CS		GPIO(10, 7)
#endif

#define GPIO_UART1_TXD		GPIO( 3, 0)

#define GPIO_SYSTEM_RESET	GPIO(12, 2)

/* S5L8950X SoC Mem Pin Configuration */

static const gpio_t memory_interface_gpios[] = {
	/* Not needed */
};

#endif /* ! __PLATFORM_GPIODEF_H */
