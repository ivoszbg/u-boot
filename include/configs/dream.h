/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Configuration settings for the SAMSUNG A5 2017 (A520F)(a5y17lte) board.
 *
 * Copyright (C) 2020 Dzmitry Sankouski (dsankouski@gmail.com)
 * Copyright (C) 2020 Ivaylo Ivanov <ivo.ivanov@null.net>
 * based on configs/espresso7420.h
 * Copyright (C) 2016 Samsung Electronics
 * Thomas Abraham <thomas.ab@samsung.com>
 */

#ifndef __CONFIG_DREAM_H
#define __CONFIG_DREAM_H

#include <configs/exynos8895-common.h>

#define CONFIG_BOARD_COMMON

#define CONFIG_SYS_SDRAM_BASE		0x80000000
#define CONFIG_SYS_INIT_SP_ADDR		(CONFIG_SYS_TEXT_BASE + SZ_2M - GENERATED_GBL_DATA_SIZE)
#define CONFIG_SYS_LOAD_ADDR		0x80001000

/* select serial console configuration */
#define CONFIG_EXTRA_ENV_SETTINGS \
		"console=ttySAC2,115200n8\0" \

/* DRAM Memory Banks */
#define SDRAM_BANK_SIZE		(256UL << 20UL)	/* 256 MB */

#endif	/* __CONFIG_DREAM_H */
