#ifndef __APPLE_GPIO_H
#define __APPLE_GPIO_H

#include "../regs.h"

#if !defined(GPIOC_COUNT)
# define GPIOC_COUNT			(1)
#endif // GPIOC_COUNT

/* Register Offsets for Apple GPIOs */
#define rGPIOCFG(_b, _n)		(*(volatile u_int32_t *)((_b) + 0x000 + (_n) * 4))
#define rGPIOINT(_b, _n)		(*(volatile u_int32_t *)((_b) + 0x800 + (_n) * 4))
#if GPIO_VERSION < 3
#define rGPIO_SR_EN(_b)			(*(volatile u_int32_t *)((_b) + 0xC4C))
#define rGPIO_FMI_DIFF_SEL(_b)		(*(volatile u_int32_t *)((_b) + 0xC4C))
#endif
#define rGPIO_NPL_IN_EN(_b)		(*(volatile u_int32_t *)((_b) + 0xC48))
#if GPIO_VERSION > 5
#define rGPIO_PINSTRAPS_VALID(_b)	(*(volatile u_int32_t *)((_b) + 0xC4C))
#define rGPIO_MISC_CTRL(_b)		(*(volatile u_int32_t *)((_b) + 0xC50))
#endif

/* Base Pin Defines for Apple GPIOs */

#define GPIOPADPINS 	(8)

#define GPIO2PIN(gpio) 		((gpio) & (GPIOPADPINS - 1))
#define GPIO2PAD(gpio)		(((gpio) >> 8) & 0xFF)
#define GPIO2CONTROLLER(gpio)	(((gpio) >> 24) & 0xFF)

#define DATA_0		(0 << 0)
#define DATA_1		(1 << 0)

#define CFG_GP_IN	(0 << 1)
#define CFG_GP_OUT	(1 << 1)
#define CFG_INT_LVL_HI	(2 << 1)
#define CFG_INT_LVL_LO	(3 << 1)
#define CFG_INT_EDG_RIS	(4 << 1)
#define CFG_INT_EDG_FAL	(5 << 1)
#define CFG_INT_EDG_ANY	(6 << 1)
#define CFG_DISABLE	(7 << 1)
#define CFG_MASK	(7 << 1)

#if GPIO_VERSION < 3
#define INT_MASKED	(1 << 4)
#endif

#define FUNC_GPIO	(0 << 5)
#define FUNC_ALT0	(1 << 5)
#define FUNC_ALT1	(2 << 5)
#define FUNC_ALT2	(3 << 5)
#define FUNC_MASK	(3 << 5)

#define PULL_NONE	(0 << 7)
#if GPIO_VERSION == 0
#define PULL_UP		(1 << 7)
#define PULL_DOWN	(2 << 7)
#else
#define PULL_UP		(3 << 7)
#if GPIO_VERSION > 4
#define PULL_UP_STRONG  (2 << 7)
#endif
#define PULL_DOWN	(1 << 7)
#endif
#define PULL_MASK	(3 << 7)

#define INPUT_ENABLE	(1 << 9)

#if GPIO_VERSION < 5
#define DRIVE_X1	(0 << 10)
#define DRIVE_X2	(1 << 10)
#if GPIO_VERSION < 2
#define DRIVE_X3	(2 << 10)
#define DRIVE_X4	(3 << 10)
#define DRIVE_X6	DRIVE_X4
#else
#define DRIVE_X3	DRIVE_X2
#define DRIVE_X4	(2 << 10)
#define DRIVE_X6	(3 << 10)
#endif
#else
#define DRIVE_S0	(0 << 10 | 0 << 22)
#define DRIVE_S1	(1 << 10 | 0 << 22)
#define DRIVE_S2	(2 << 10 | 0 << 22)
#define DRIVE_S3	(3 << 10 | 0 << 22)
#define DRIVE_S4	(0 << 10 | 1 << 22)
#define DRIVE_S5	(1 << 10 | 1 << 22)
#define DRIVE_S6	(2 << 10 | 1 << 22)
#define DRIVE_S7	(3 << 10 | 1 << 22)
#define DRIVE_S8	(0 << 10 | 2 << 22)
#define DRIVE_S9	(1 << 10 | 2 << 22)
#define DRIVE_S10	(2 << 10 | 2 << 22)
#define DRIVE_S11	(3 << 10 | 2 << 22)
#define DRIVE_S12	(0 << 10 | 3 << 22)
#define DRIVE_S13	(1 << 10 | 3 << 22)
#define DRIVE_S14	(2 << 10 | 3 << 22)
#define DRIVE_S15	(3 << 10 | 3 << 22)
#endif

#if GPIO_VERSION < 3
#define BUS_HOLD	(1 << 12)
#endif

#if GPIO_VERSION < 5
#define FAST_SLEW	(0 << 13)
#define SLOW_SLEW	(1 << 13)
#else
#define VERY_FAST_SLEW  (0 << 15 | 0 << 13)
#define FAST_SLEW	(0 << 15 | 1 << 13)
#define SLOW_SLEW	(1 << 15 | 0 << 13)
#endif

#if GPIO_VERSION > 3
#define INPUT_CMOS	(0 << 14)
#define INPUT_SCHMITT	(1 << 14)
#endif

#if GPIO_VERSION > 2
#define INTR_GRP_SEL0	(0 << 16)
#define INTR_GRP_SEL1	(1 << 16)
#define INTR_GRP_SEL2	(2 << 16)
#define INTR_GRP_SEL3	(3 << 16)
#define INTR_GRP_SEL4	(4 << 16)
#define INTR_GRP_SEL5	(5 << 16)
#define INTR_GRP_SEL6	(6 << 16)
#define INT_MASKED	(7 << 16)
#endif

#define CFG_DISABLED	(               FUNC_GPIO | CFG_DISABLE |          INT_MASKED)
#define CFG_IN		(INPUT_ENABLE | FUNC_GPIO | CFG_GP_IN   |          INT_MASKED)
#define CFG_OUT		(INPUT_ENABLE | FUNC_GPIO | CFG_GP_OUT  | 	   INT_MASKED)
#define CFG_OUT_0	(INPUT_ENABLE | FUNC_GPIO | CFG_GP_OUT  | DATA_0 | INT_MASKED)
#define CFG_OUT_1	(INPUT_ENABLE | FUNC_GPIO | CFG_GP_OUT  | DATA_1 | INT_MASKED)
#define CFG_FUNC0	(INPUT_ENABLE | FUNC_ALT0 |                        INT_MASKED)
#define CFG_FUNC1	(INPUT_ENABLE | FUNC_ALT1 |                        INT_MASKED)
#define CFG_FUNC2	(INPUT_ENABLE | FUNC_ALT2 |                        INT_MASKED)

/* Global slew rate adjustment, for hardware which supports it */

#define SLEW_RATE_FAST	0
#define SLEW_RATE_SLOW	1

#endif /* ! __APPLE_GPIO_H */
