#ifndef __PLATFORM_GPIO_H
#define __PLATFORM_GPIO_H

#include <common.h>

typedef uint32_t gpio_t;

extern uint32_t spi_gpio_read(int port);

extern void spi_gpio_write(int port, uint32_t val);

// Macro trickery to allow specifying GPIOs as either port and pin (Samsung GPIO style)
// or by ID number (Apple GPIO controller)
// For compatiblity reasons, the Apple GPIO controller driver expects the packing of the
// ID number to skip bits 4-7
#define GPIO_PORT_PIN(port, pin)	((gpio_t)(((port) & 0xFF) << 8) | ((pin) & 0xFF))
#define GPIO_COMPAT_SELECT(_1, _2, NAME, ...)	NAME
#define GPIO(...)			GPIO_COMPAT_SELECT(__VA_ARGS__, GPIO_PORT_PIN, GPIO_ID)(__VA_ARGS__)

#define GPIOC(controller, port, pin)	((gpio_t)(((controller) & 0xFF) << 24) | (((port) & 0xFF) << 8) | ((pin) & 0xFF))
#define GPIO_ID(gpio_id)		(GPIO_PORT_PIN(((gpio_id) / 8), ((gpio_id) % 8)))
#define GPIO_PORT(gpio)			(((gpio) >> 8) & 0xFF)
#define GPIO_PIN(gpio)			((gpio) & 0xFF)

#define GPIOC_0				(0)
#define GPIOC_1				(1)

#define GPIO_NONE		(0xFFFFFFFF)

#define GPIO_CFG_IN		0
#define GPIO_CFG_OUT		1
#define GPIO_CFG_OUT_0		2
#define GPIO_CFG_OUT_1		3
#define GPIO_CFG_DFLT		4
#define GPIO_CFG_FUNC0		5
#define GPIO_CFG_FUNC1		6
#define GPIO_CFG_FUNC2		7
#define GPIO_CFG_FUNC(_n)	(GPIO_CFG_FUNC0 + (_n))
#define GPIO_CFG_MAX		GPIO_CFG_FUNC(16)

#define GPIO_NO_PUPDN		(0)
#define GPIO_PUP		(1)
#define GPIO_PUP_STRONG		(2)
#define GPIO_PDN		(-1)

#define GPIO_DRIVE_X1		(0)
#define GPIO_DRIVE_X2		(1)
#define GPIO_DRIVE_X3		(2)
#define GPIO_DRIVE_X4		(3)
#define GPIO_DRIVE_X6		(4)

#define GPIO_DRIVE_S0		(0)
#define GPIO_DRIVE_S1		(1)
#define GPIO_DRIVE_S2		(2)
#define GPIO_DRIVE_S3		(3)
#define GPIO_DRIVE_S4		(4)
#define GPIO_DRIVE_S5		(5)
#define GPIO_DRIVE_S6		(6)
#define GPIO_DRIVE_S7		(7)
#define GPIO_DRIVE_S8		(8)
#define GPIO_DRIVE_S9		(9)
#define GPIO_DRIVE_S10		(10)
#define GPIO_DRIVE_S11		(11)
#define GPIO_DRIVE_S12		(12)
#define GPIO_DRIVE_S13		(13)
#define GPIO_DRIVE_S14		(14)
#define GPIO_DRIVE_S15		(15)

int	  gpio_init_pinconfig(void); /* set up default pin configuration */
int	  gpio_init_memory(uint32_t drive_strength);
int	  gpio_diag_pinconfig(void); /* set up pins for diag use */
uint32_t  gpio_read(gpio_t gpio);
void	  gpio_write(gpio_t gpio, uint32_t val);
void	  gpio_configure(gpio_t gpio, uint32_t config);
void	  gpio_configure_pupdn(gpio_t gpio, int32_t pupdn);
void	  gpio_fixup_pinconfig(const uint32_t *fixup_list);
uint32_t  gpio_get_board_id(void);

#define gpio_configure_in(gpio) gpio_configure((gpio), GPIO_CFG_IN)
#define gpio_configure_out(gpio, val) gpio_configure((gpio), (val) ? GPIO_CFG_OUT_1 : GPIO_CFG_OUT_0);

#endif
