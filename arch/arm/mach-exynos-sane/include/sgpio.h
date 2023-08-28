/*
 * Copyright (C) 2007 Apple Inc. All rights reserved.
 * Copyright (C) 2006 Apple Computer, Inc. All rights reserved.
 *
 * This document is the property of Apple Inc.
 * It is considered confidential and proprietary.
 *
 * This document may not be reproduced or transmitted in any form,
 * in whole or in part, without the express written permission of
 * Apple Inc.
 */
#ifndef __SAMSUNG_GPIO_H
#define __SAMSUNG_GPIO_H

#include "../regs.h"

/* Register Offsets for Samsung GPIOs */
#define rPCONn(n)	(*(volatile u_int32_t *)(GPIO_BASE_ADDR + 0x000 + (n) * 0x20))
#define rPDATn(n)	(*(volatile u_int32_t *)(GPIO_BASE_ADDR + 0x004 + (n) * 0x20))
#define rPCTLn(n)	(*(volatile u_int32_t *)(GPIO_BASE_ADDR + 0x008 + (n) * 0x20))
#define rPPURn(n)	(*(volatile u_int32_t *)(GPIO_BASE_ADDR + 0x00C + (n) * 0x20))
#define rPPDRn(n)	(*(volatile u_int32_t *)(GPIO_BASE_ADDR + 0x010 + (n) * 0x20))
#define rPPIEn(n)	(*(volatile u_int32_t *)(GPIO_BASE_ADDR + 0x014 + (n) * 0x20))

#define rFSEL		(*(volatile u_int32_t *)(GPIO_BASE_ADDR + GPIO_FSEL_OFFSET))

#define rDSTR0		(*(volatile u_int32_t *)(GPIO_BASE_ADDR + 0x380))
#define rOSC_DSTR	(*(volatile u_int32_t *)(GPIO_BASE_ADDR + 0x388))

#define rODEN		(*(volatile u_int32_t *)(GPIO_BASE_ADDR + 0x3C0))
#define rEMAC0		(*(volatile u_int32_t *)(GPIO_BASE_ADDR + 0x3C4))
#define rEMAC1		(*(volatile u_int32_t *)(GPIO_BASE_ADDR + 0x3C8))
#define rEMAC2		(*(volatile u_int32_t *)(GPIO_BASE_ADDR + 0x3CC))


/* Base Pin Defines for Samsung GPIOs */
#define PORT(port, pin) ((u_int32_t)((port) << 8) | pin)
#define GPIO2PIN(gpio) ((gpio) & 0x7)
#define GPIO2PAD(gpio) (((gpio) >> 8) & 0x1f)

/* Precomputes the PCON register's value */
#define PCON(pinfunc0, pinfunc1, pinfunc2, pinfunc3, pinfunc4, pinfunc5, pinfunc6, pinfunc7) \
	((u_int32_t)(((pinfunc0) << 0) | ((pinfunc1) << 4) | ((pinfunc2) << 8) | ((pinfunc3) << 12) | \
		     ((pinfunc4) << 16) | ((pinfunc5) << 20) | ((pinfunc6) << 24) | ((pinfunc7) << 28)))

/* some PCON constants */
enum {
	PCON_IN    = 0,
	PCON_OUT   = 1,
	PCON_FUNC2 = 2,
	PCON_FUNC3 = 3,
	PCON_FUNC4 = 4,
	PCON_FUNC5 = 5,
	PCON_FUNC6 = 6,

	PCON_DISABLE = 0xd,	/* not actually supported by the hardware, implies PCON_IN
				   and input enable disabled */
	PCON_OUT_0 = 0xe,	/* same as PCON_OUT, but also sets PDAT to zero */
	PCON_OUT_1 = 0xf	/* same as PCON_OUT, but also sets PDAT to one */
};

/* pull up/down configuration */
enum {
	NO_PUPDN = 0,
	PUP = (1 << 0),
	PDN = (1 << 8)
};

#define PUPDN(pinupdn0, pinupdn1, pinupdn2, pinupdn3, pinupdn4, pinupdn5, pinupdn6, pinupdn7) \
	((uint16_t)(((pinupdn0) << 0) | ((pinupdn1) << 1) | ((pinupdn2) << 2) | ((pinupdn3) << 3) | \
		    ((pinupdn4) << 4) | ((pinupdn5) << 5) | ((pinupdn6) << 6) | ((pinupdn7) << 7)))

struct gpio_default_config {
	uint32_t	pcon;
	uint16_t	pupdn;
};

#define PINCONFIG(pcon0, pupdn0, pcon1, pupdn1, pcon2, pupdn2, pcon3, pupdn3, \
		  pcon4, pupdn4, pcon5, pupdn5, pcon6, pupdn6, pcon7, pupdn7) \
	{ .pcon = PCON(pcon0, pcon1, pcon2, pcon3, pcon4, pcon5, pcon6, pcon7), \
	  .pupdn = PUPDN(pupdn0, pupdn1, pupdn2, pupdn3, pupdn4, pupdn5, pupdn6, pupdn7) \
	}

#endif /* __SAMSUNG_GPIO_H */
