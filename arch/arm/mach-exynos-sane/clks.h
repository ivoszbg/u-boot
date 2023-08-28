/*
 * Copyright (C) 2010-2011 Apple Inc. All rights reserved.
 *
 * This document is the property of Apple Inc.
 * It is considered confidential and proprietary.
 *
 * This document may not be reproduced or transmitted in any form,
 * in whole or in part, without the express written permission of
 * Apple Inc.
 */
#ifndef __PLATFORM_SOC_HWCLOCKS_H
#define __PLATFORM_SOC_HWCLOCKS_H

//#include <platform/clocks.h>

#if SUPPORT_FPGA
#define OSC_FREQ			(10000000UL)
#else
#define OSC_FREQ			(24000000UL)
#endif

#define CLK_FCLK	(HWCLOCK_BASE+0)
#define CLK_ACLK	(HWCLOCK_BASE+1)
#define CLK_HCLK	(HWCLOCK_BASE+2)
#define CLK_PCLK	(HWCLOCK_BASE+3)
#define CLK_VCLK0	(HWCLOCK_BASE+4)
#define CLK_VCLK1	(HWCLOCK_BASE+5)
#define CLK_MCLK	(HWCLOCK_BASE+6)
#define CLK_NCLK	(HWCLOCK_BASE+7)
#define CLK_USBPHYCLK	(HWCLOCK_BASE+8)
#define CLK_NCOREF	(HWCLOCK_BASE+9)
#define CLK_FMI		(HWCLOCK_BASE+10)

/* S5L8950X clock gate devices */
enum {
	CLK_rsvd0 = 0,
	CLK_SCC,
	CLK_CPU0,
	CLK_CPU1,
	CLK_L2_BIU,
	CLK_L2,
	CLK_rsvd1,
	CLK_rsvd2,
	CLK_MCU,
	CLK_GFX_SYS,
	CLK_GFX_CORES,
	CLK_HPERFNRT,
	CLK_VDEC,
	CLK_SCALER0,
	CLK_SCALER1,
	CLK_JPG0,
	CLK_JPG1,
	CLK_rsvd3,
	CLK_VENC,
	CLK_HPERFRT,
	CLK_ISP,
	CLK_LPDP,
	CLK_DISP0,
	CLK_DISP1,
	CLK_DISPOUT,
	CLK_MIPI,
	CLK_CLCD,
	CLK_TVDAC,
	CLK_RGBOUT,
	CLK_DPLINK,
	CLK_CDIO,
	CLK_CDMA,
	CLK_IOP,
	CLK_UPERF,
	CLK_USBOTG,
	CLK_USB20,
	CLK_USB11,
	CLK_USBOHCI0,
	CLK_USBOHCI1,
	CLK_USBPHY,
	CLK_AUDIO,
	CLK_I2S0,
	CLK_I2S1,
	CLK_I2S2,
	CLK_I2S3,
	CLK_SPDIF,
	CLK_ADSP,
	CLK_SDIO,
	CLK_SHA1,
	CLK_SHA2,
	CLK_FMI0,
	CLK_FMI0BCH,
	CLK_FMI1,
	CLK_FMI1BCH,
	CLK_FMI_DLL,
	CLK_XMBIST,
	CLK_MCA,
	CLK_SPI0,
	CLK_SPI1,
	CLK_SPI2,
	CLK_SPI3,
	CLK_SPI4,
	CLK_UART0,
	CLK_UART1,
	CLK_UART2,
	CLK_UART3,
	CLK_UART4,
	CLK_UART5,
	CLK_UART6,
	CLK_PKE,
	CLK_I2C0,
	CLK_I2C1,
	CLK_I2C2,
	CLK_PWM,
	CLK_SCRT,
	CLK_GPIO,
	CLK_SWI,
	CLK_DWI,
	CLK_DEBUG,
	CLK_AIC,
};

#endif /* ! __PLATFORM_SOC_HWCLOCKS_H */
