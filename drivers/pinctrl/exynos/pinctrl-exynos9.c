// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2016 Samsung Electronics
 * Thomas Abraham <thomas.ab@samsung.com>
 * Copyright (C) 2020 Ivaylo Ivanov <ivo.ivanov@null.net>
 */

#include <log.h>
#include <common.h>
#include <dm.h>
#include <errno.h>
#include <asm/io.h>
#include <dm/pinctrl.h>
#include <dm/root.h>
#include <fdtdec.h>
#include <asm/arch/pinmux.h>

#include "pinctrl-exynos.h"

#define DEBUG

static struct pinctrl_ops exynos9_pinctrl_ops = {
	.set_state	= exynos_pinctrl_set_state
};

/* pin banks of exynos8895 pin-controller 6 (PERIC0) */
static const struct samsung_pin_bank_data exynos8895_pin_banks6[] = {
	EXYNOS_PIN_BANK(4, 0x080, "gpb1"),
	EXYNOS_PIN_BANK(8, 0x000, "gpd0"),
	EXYNOS_PIN_BANK(8, 0x020, "gpd1"),
	EXYNOS_PIN_BANK(4, 0x040, "gpd2"),
	EXYNOS_PIN_BANK(5, 0x060, "gpd3"),
	EXYNOS_PIN_BANK(8, 0x0A0, "gpe7"),
	EXYNOS_PIN_BANK(8, 0x0C0, "gpf1"),
};

static const struct samsung_pin_ctrl exynos8895_pin_ctrl[] = {
	{
		/* pin-controller instance 6 PERIC0 data */
		.pin_banks	= exynos8895_pin_banks6,
		.nr_banks	= ARRAY_SIZE(exynos8895_pin_banks6),
	}, {
		/* list terminator */
	}
};

static const struct udevice_id exynos9_pinctrl_ids[] = {
	{
		.compatible = "samsung,exynos8895-pinctrl",
		.data = (ulong)exynos8895_pin_ctrl
	}, {
		/* list terminator */
	}
};

U_BOOT_DRIVER(pinctrl_exynos9) = {
	.name		= "pinctrl_exynos9",
	.id		= UCLASS_PINCTRL,
	.of_match	= exynos9_pinctrl_ids,
	.priv_auto_alloc_size = sizeof(struct exynos_pinctrl_priv),
	.ops		= &exynos9_pinctrl_ops,
	.probe		= exynos_pinctrl_probe,
};
