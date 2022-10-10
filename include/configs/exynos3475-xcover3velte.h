/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2017, STMicroelectronics - All Rights Reserved
 * Author(s): Patrice Chotard, <patrice.chotard@foss.st.com> for STMicroelectronics.
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include <linux/sizes.h>

/* ram memory-related information */
#define CONFIG_SYS_SDRAM_BASE		0x20000000
#define PHYS_SDRAM_SIZE		0x59000000

//#define hang() puts("calling hang in: %s\n", __func__); actual_hang()

//void actual_hang(void)

/* DRAM Memory Banks */
#define SDRAM_BANK_SIZE	(256UL << 20UL)	/* 256 MB */

#define PHYS_SDRAM_1		CONFIG_SYS_SDRAM_BASE
#define PHYS_SDRAM_1_SIZE	SDRAM_BANK_SIZE
#define PHYS_SDRAM_2		(CONFIG_SYS_SDRAM_BASE + SDRAM_BANK_SIZE)
#define PHYS_SDRAM_2_SIZE	SDRAM_BANK_SIZE
#define PHYS_SDRAM_3		(CONFIG_SYS_SDRAM_BASE + (2 * SDRAM_BANK_SIZE))
#define PHYS_SDRAM_3_SIZE	SDRAM_BANK_SIZE
#define PHYS_SDRAM_4		(CONFIG_SYS_SDRAM_BASE + (3 * SDRAM_BANK_SIZE))
#define PHYS_SDRAM_4_SIZE	SDRAM_BANK_SIZE
#define PHYS_SDRAM_5		(CONFIG_SYS_SDRAM_BASE + (4 * SDRAM_BANK_SIZE))
#define PHYS_SDRAM_5_SIZE	SDRAM_BANK_SIZE
#define PHYS_SDRAM_6		(CONFIG_SYS_SDRAM_BASE + (5 * SDRAM_BANK_SIZE))
#define PHYS_SDRAM_6_SIZE	SDRAM_BANK_SIZE




//#define CONFIG_SYS_HZ_CLOCK		1000000000	/* 1 GHz */

/* Environment */

/*
 * For booting Linux, use the first 256 MB of memory, since this is
 * the maximum mapped by the Linux kernel during initialization.
 */
#define CONFIG_SYS_BOOTMAPSZ		SZ_256M

#define CONFIG_SYS_BOOTM_LEN		SZ_16M

#define BOOT_TARGET_DEVICES(func) \
	func(MMC, mmc, 0) \
	func(USB, usb, 0) \
	func(DHCP, dhcp, na)
#include <config_distro_bootcmd.h>
#define CONFIG_EXTRA_ENV_SETTINGS				\
			"kernel_addr_r=0x40000000\0"		\
			"fdtfile=stih410-b2260.dtb\0"		\
			"fdt_addr_r=0x47000000\0"		\
			"scriptaddr=0x50000000\0"		\
			"pxefile_addr_r=0x50100000\0"		\
			"ramdisk_addr_r=0x48000000\0"		\
			BOOTENV

/* Extra Commands */

#define CONFIG_SYS_GBL_DATA_SIZE	1024	/* Global data structures */
#define CONFIG_SYS_INIT_SP_ADDR		CONFIG_SYS_TEXT_BASE + SZ_2M - GENERATED_GBL_DATA_SIZE

/* Monitor Command Prompt */
#define CONFIG_SYS_CBSIZE		1024	/* Console I/O Buffer Size */

/* USB Configs */
#define CONFIG_USB_OHCI_NEW
#define CONFIG_SYS_USB_OHCI_MAX_ROOT_PORTS	2

/* NET Configs */

#endif /* __CONFIG_H */
