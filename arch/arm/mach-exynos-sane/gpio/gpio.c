#include <agpio.h>
#include "../spi/spi.h"
#include "../regs.h"
#include "gpio.h"
#include "../gpiodef.h"
#if GPIO_VERSION > 5
#include <platform/soc/pmgr.h>
#endif

static const struct {
	uintptr_t	base_addr;
	uint32_t	pin_count;
} gpio_cfgs[GPIOC_COUNT] = {
#if GPIOC_COUNT > 0
	{ GPIO_BASE_ADDR, GPIO_GROUP_COUNT * GPIOPADPINS },
#endif
#if GPIOC_COUNT > 1
	{ GPIO_1_BASE_ADDR, GPIO_1_GROUP_COUNT * GPIOPADPINS },
#endif
};


/* Platform gpio cfg */
/*const uint32_t* platform_get_default_gpio_cfg(uint32_t gpioc)
{
	if (gpioc == 0)
		return gpio_default_cfg_0;
#ifdef GPIO_1_GROUP_COUNT
	if (gpioc == 1)
		return gpio_default_cfg_0;
#endif
	panic("unknown gpio controller %u", gpioc);
}*/

uint32_t gpio_read(gpio_t gpio)
{
	uint8_t gpioc = GPIO2CONTROLLER(gpio);
	uint8_t pad = GPIO2PAD(gpio);
	uint8_t pin = GPIO2PIN(gpio);
	uint8_t gpion = pad * GPIOPADPINS + pin;

	if (pad == GPIO_PAD_SPI) return spi_gpio_read(pin);

	return (rGPIOCFG(gpio_cfgs[gpioc].base_addr, gpion) & 1) ? 1UL : 0UL;
}

void gpio_write(gpio_t gpio, uint32_t val)
{
	uint32_t cfg_val, cfg_mask;
	uint8_t gpioc = GPIO2CONTROLLER(gpio);
	uint8_t pad = GPIO2PAD(gpio);
	uint8_t pin = GPIO2PIN(gpio);
	uint8_t gpion = pad * GPIOPADPINS + pin;

	if (pad == GPIO_PAD_SPI) {	
		spi_gpio_write(pin, val);
		return;
	}

	cfg_val  = (val) ? CFG_OUT_1 : CFG_OUT_0;
	cfg_mask = INPUT_ENABLE | FUNC_MASK | INT_MASKED | CFG_MASK | DATA_1;

	rGPIOCFG(gpio_cfgs[gpioc].base_addr, gpion) = (rGPIOCFG(gpio_cfgs[gpioc].base_addr, gpion) & ~cfg_mask) | (cfg_val & cfg_mask);
}

void gpio_safe_reconfigure(uint8_t gpioc, uint8_t gpion, uint32_t config)
{
	uint32_t old_config;
	uint32_t new_input_enable;
	uint32_t old_input_enable;

	old_config = rGPIOCFG(gpio_cfgs[gpioc].base_addr, gpion);
	new_input_enable = config & INPUT_ENABLE;

	if (new_input_enable == 0) {
		rGPIOCFG(gpio_cfgs[gpioc].base_addr, gpion) = old_config & ~INPUT_ENABLE;
		old_input_enable = 0;
	} else {
		old_input_enable = old_config & INPUT_ENABLE;
	}

	rGPIOCFG(gpio_cfgs[gpioc].base_addr, gpion) = (config & ~INPUT_ENABLE) | old_input_enable;

	if (new_input_enable != 0 && old_input_enable == 0)
		rGPIOCFG(gpio_cfgs[gpioc].base_addr, gpion) = config;
}

/*void gpio_configure(gpio_t gpio, uint32_t config)
{
	uint32_t cfg_val, cfg_mask;
	uint8_t gpioc = GPIO2CONTROLLER(gpio);
	uint8_t pad = GPIO2PAD(gpio);
	uint8_t pin = GPIO2PIN(gpio);
	uint8_t gpion = pad * GPIOPADPINS + pin;

#if WITH_HW_SPI && defined(GPIO_PAD_SPI)
	if (pad == GPIO_PAD_SPI) {
		spi_gpio_configure(pin, config);
		return;
	}
#endif

	cfg_mask = INPUT_ENABLE | FUNC_MASK | INT_MASKED | CFG_MASK;

	switch (config) {
	       	case GPIO_CFG_IN    : cfg_val = CFG_IN;								break;
	       	case GPIO_CFG_OUT_0 : cfg_val = CFG_OUT_0;	 	 cfg_mask |= DATA_1; 			break;
	       	case GPIO_CFG_OUT_1 : cfg_val = CFG_OUT_1;		 cfg_mask |= DATA_1; 			break;
	       	case GPIO_CFG_OUT   : cfg_val = CFG_OUT;	 	 	    				break;
	       	case GPIO_CFG_FUNC0 : cfg_val = CFG_FUNC0;							break;
	       	case GPIO_CFG_FUNC1 : cfg_val = CFG_FUNC1;							break;
	       	case GPIO_CFG_FUNC2 : cfg_val = CFG_FUNC2;							break;
		case GPIO_CFG_DFLT  :
			cfg_val = platform_get_default_gpio_cfg(gpioc)[gpion]; cfg_mask |= PULL_MASK | DATA_1;	break;
		default :											return;
	}

	gpio_safe_reconfigure(gpioc, gpion, (rGPIOCFG(gpio_cfgs[gpioc].base_addr, gpion) & ~cfg_mask) | (cfg_val & cfg_mask));
}*/

void gpio_configure_pupdn(gpio_t gpio, int32_t pupdn)
{
	uint8_t gpioc = GPIO2CONTROLLER(gpio);
	uint8_t pad = GPIO2PAD(gpio);
	uint8_t pin = GPIO2PIN(gpio);
	uint8_t gpion = pad * GPIOPADPINS + pin;
	uint32_t cfg_val;

	if (pupdn < GPIO_NO_PUPDN) {
		cfg_val = PULL_DOWN;
	} else if (pupdn > GPIO_NO_PUPDN) {
		#if GPIO_VERSION < 5
			cfg_val = PULL_UP;
		#else
			cfg_val = (pupdn > GPIO_PUP) ? PULL_UP_STRONG : PULL_UP;	
		#endif
	} else {
		/* GPIO_NO_PUPDN */
		cfg_val = PULL_NONE;
	}

	rGPIOCFG(gpio_cfgs[gpioc].base_addr, gpion) = (rGPIOCFG(gpio_cfgs[gpioc].base_addr, gpion) & ~PULL_MASK) | (cfg_val & PULL_MASK);
}


/*int gpio_init_pinconfig(void)
{
	uint8_t cnt, gpioc;

	for (gpioc = 0; gpioc < GPIOC_COUNT; gpioc++) {
		const uint32_t *pin_config = platform_get_default_gpio_cfg(gpioc);

		for (cnt = 0; cnt < gpio_cfgs[gpioc].pin_count; cnt++) {
			gpio_safe_reconfigure(gpioc, cnt, pin_config[cnt]);
		}

#ifdef FMI_SLEW_RATE
		// Adjust global FMI pads slew rate.
		rGPIO_SR_EN(gpio_cfgs[gpioc].base_addr) = (rGPIO_SR_EN(gpio_cfgs[gpioc].base_addr) & ~1) | (FMI_SLEW_RATE & 1);
#endif

#ifdef FMI_DIFF_SEL
		// Configure FMI differential pin selection
		rGPIO_FMI_DIFF_SEL(gpio_cfgs[gpioc].base_addr) = FMI_DIFF_SEL;
#endif

#if GPIO_VERSION > 0
		// Enable interrupt when pin not configured as GPIO
		rGPIO_NPL_IN_EN(gpio_cfgs[gpioc].base_addr) = 1;
#endif
	}

#if GPIO_VERSION > 6
#if !APPLICATION_SECUREROM
	// The GPIO Micro-Architecture Specification v1.3, section 4.1 (5) says:
	//
	//	"To control the XTAL_DRIVE strength software needs to program
	//	the GPIO_MISC_CTRL[XTAL_DRIVE_STRENGTH] bit. This should be
	//	programmed only after 140,000 24MHZ clocks to allow the xtal
	//	to lock to 24MHz. Once this change is made we should allow
	//	20,000 clocks for a stable duty cycle.
	//
	// Since we're not doing this in the SecureROM we're definitely far
	// enough along here that we've met the 140K cycles requirement.
	rGPIO_MISC_CTRL(gpio_cfgs[0].base_addr) = 0;
#endif
#endif

	return 0;
}*/

void gpio_fixup_pinconfig(const uint32_t *fixup_list) {
	int32_t i;
	
	for (i = 0; fixup_list[i * 2] != UINT32_MAX; i ++) {
		gpio_t gpio = fixup_list[(i * 2) + 0];
		uint8_t gpioc = GPIO2CONTROLLER(gpio);
		uint8_t pad = GPIO2PAD(gpio);
		uint8_t pin = GPIO2PIN(gpio);
		uint8_t gpion = pad * GPIOPADPINS + pin;

		gpio_safe_reconfigure(gpioc, gpion, fixup_list[(i * 2) + 1]);
	}
}

int gpio_init_memory(uint32_t drive_strength)
{
	gpio_t   gpio;
	uint32_t pin, pad, gpion, config;
	int32_t  cnt, pin_count  = sizeof(memory_interface_gpios) / sizeof(memory_interface_gpios[0]);

	/* 
	 * XXXX only one gpio controller is supported
	 */

	config = CFG_IN;
#if GPIO_VERSION < 5
	switch (drive_strength) {
		case GPIO_DRIVE_X1 : config |= DRIVE_X1; break;
		case GPIO_DRIVE_X2 : config |= DRIVE_X2; break;
		case GPIO_DRIVE_X3 : config |= DRIVE_X3; break;
		case GPIO_DRIVE_X4 : config |= DRIVE_X4; break;
		case GPIO_DRIVE_X6 : config |= DRIVE_X6; break;
	}
#else
	switch (drive_strength) {
		case GPIO_DRIVE_S0 : config |= DRIVE_S0; break;
		case GPIO_DRIVE_S1 : config |= DRIVE_S1; break;
		case GPIO_DRIVE_S2 : config |= DRIVE_S2; break;
		case GPIO_DRIVE_S3 : config |= DRIVE_S3; break;
		case GPIO_DRIVE_S4 : config |= DRIVE_S4; break;
		case GPIO_DRIVE_S5 : config |= DRIVE_S5; break;
		case GPIO_DRIVE_S6 : config |= DRIVE_S6; break;
		case GPIO_DRIVE_S7 : config |= DRIVE_S7; break;
		case GPIO_DRIVE_S8 : config |= DRIVE_S8; break;
		case GPIO_DRIVE_S9 : config |= DRIVE_S9; break;
		case GPIO_DRIVE_S10 : config |= DRIVE_S10; break;
		case GPIO_DRIVE_S11 : config |= DRIVE_S11; break;
		case GPIO_DRIVE_S12 : config |= DRIVE_S12; break;
		case GPIO_DRIVE_S13 : config |= DRIVE_S13; break;
		case GPIO_DRIVE_S14 : config |= DRIVE_S14; break;
		case GPIO_DRIVE_S15 : config |= DRIVE_S15; break;
	}
#endif

	for (cnt = 0; cnt < pin_count; cnt++) {
		gpio = memory_interface_gpios[cnt];
		pad = GPIO2PAD(gpio);
		pin = GPIO2PIN(gpio);
		gpion = pad * GPIOPADPINS + pin;

		gpio_safe_reconfigure(0, gpion, config);
	}

	return 0;
}

uint32_t gpio_get_board_id(void)
{
#if GPIO_VERSION > 5
	// The board ID pins must have been sampled by the time this request is made.
	RELEASE_ASSERT(rGPIO_PINSTRAPS_VALID(gpio_cfgs[0].base_addr) & 1);

	// Return the sampled board ID value.
	return MINIPMGR_SECURITY_GPIO_STRAPS_BOARD_ID_XTRCT(rMINIPMGR_SECURITY_GPIO_STRAPS);
#else
	panic("gpio_get_board_id() not supported for this platform");
#endif
}

#if APPLICATION_IBOOT

int gpio_diag_pinconfig(void)
{
	return 0;
}

#endif /* APPLICATION_IBOOT */
