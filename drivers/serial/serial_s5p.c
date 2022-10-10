// SPDX-License-Identifier: GPL-2.0+
/*
 * (C) Copyright 2009 SAMSUNG Electronics
 * Minkyu Kang <mk7.kang@samsung.com>
 * Heungjun Kim <riverful.kim@samsung.com>
 *
 * based on drivers/serial/s3c64xx.c
 */

#include <common.h>
#include <dm.h>
#include <errno.h>
#include <fdtdec.h>
#include <asm/global_data.h>
#include <linux/compiler.h>
#include <asm/io.h>
#include <serial.h>
#include <clk.h>

#include <video_font.h>
#include <lcd_console.h>

DECLARE_GLOBAL_DATA_PTR;

enum {
	PORT_S5P = 0,
	PORT_S5L
};

#define S5L_RX_FIFO_COUNT_SHIFT	0
#define S5L_RX_FIFO_COUNT_MASK	(0xf << S5L_RX_FIFO_COUNT_SHIFT)
#define S5L_RX_FIFO_FULL	(1 << 8)
#define S5L_TX_FIFO_COUNT_SHIFT	4
#define S5L_TX_FIFO_COUNT_MASK	(0xf << S5L_TX_FIFO_COUNT_SHIFT)
#define S5L_TX_FIFO_FULL	(1 << 9)

#define S5P_RX_FIFO_COUNT_SHIFT	0
#define S5P_RX_FIFO_COUNT_MASK	(0xff << S5P_RX_FIFO_COUNT_SHIFT)
#define S5P_RX_FIFO_FULL	(1 << 8)
#define S5P_TX_FIFO_COUNT_SHIFT	16
#define S5P_TX_FIFO_COUNT_MASK	(0xff << S5P_TX_FIFO_COUNT_SHIFT)
#define S5P_TX_FIFO_FULL	(1 << 24)

/* Information about a serial port */
struct s5p_serial_plat {
	struct s5p_uart *reg;  /* address of registers in physical memory */
	u8 reg_width;	/* register width */
	u8 port_id;     /* uart port number */
	u8 rx_fifo_count_shift;
	u8 tx_fifo_count_shift;
	u32 rx_fifo_count_mask;
	u32 tx_fifo_count_mask;
	u32 rx_fifo_full;
	u32 tx_fifo_full;
};

/*
 * The coefficient, used to calculate the baudrate on S5P UARTs is
 * calculated as
 * C = UBRDIV * 16 + number_of_set_bits_in_UDIVSLOT
 * however, section 31.6.11 of the datasheet doesn't recomment using 1 for 1,
 * 3 for 2, ... (2^n - 1) for n, instead, they suggest using these constants:
 */
static const int udivslot[] = {
	0,
	0x0080,
	0x0808,
	0x0888,
	0x2222,
	0x4924,
	0x4a52,
	0x54aa,
	0x5555,
	0xd555,
	0xd5d5,
	0xddd5,
	0xdddd,
	0xdfdd,
	0xdfdf,
	0xffdf,
};

static void __maybe_unused s5p_serial_init(struct s5p_uart *uart)
{

}

static void __maybe_unused s5p_serial_baud(struct s5p_uart *uart, u8 reg_width,
					   uint uclk, int baudrate)
{

}

#ifndef CONFIG_SPL_BUILD
int s5p_serial_setbrg(struct udevice *dev, int baudrate)
{

	return 0;
}

static int s5p_serial_probe(struct udevice *dev)
{
	struct s5p_serial_plat *plat = dev_get_plat(dev);
	struct s5p_uart *const uart = plat->reg;

	s5p_serial_init(uart);

	return 0;
}

static int serial_err_check(const struct s5p_uart *const uart, int op)
{
	return 0;
}

static int s5p_serial_getc(struct udevice *dev)
{
	return 0;
}

static int s5p_serial_putc(struct udevice *dev, const char ch)
{

	return 0;
}

static int s5p_serial_pending(struct udevice *dev, bool input)
{

	return 0;
}

static int s5p_serial_of_to_plat(struct udevice *dev)
{


	return 0;
}

static const struct dm_serial_ops s5p_serial_ops = {
	.putc = s5p_serial_putc,
	.pending = s5p_serial_pending,
	.getc = s5p_serial_getc,
	.setbrg = s5p_serial_setbrg,
};

static const struct udevice_id s5p_serial_ids[] = {
	{ .compatible = "samsung,exynos4210-uart",	.data = PORT_S5P },
	{ .compatible = "apple,s5l-uart",		.data = PORT_S5L },
	{ }
};

U_BOOT_DRIVER(serial_s5p) = {
	.name	= "serial_s5p",
	.id	= UCLASS_SERIAL,
	.of_match = s5p_serial_ids,
	.of_to_plat = s5p_serial_of_to_plat,
	.plat_auto	= sizeof(struct s5p_serial_plat),
	.probe = s5p_serial_probe,
	.ops	= &s5p_serial_ops,
};
#endif

#include <debug_uart.h>

static struct console_t hax_cons = {.cols = 270, .rows = 150};

static inline void hax_console_newline(void)
{
	hax_cons.curr_col = 0;
	//hax_cons.curr_row += 1;

	if(hax_cons.curr_row >= 24) {
		//memmove(0x57e05000 + 4 * 480 * VIDEO_FONT_HEIGHT, 0x57e05000, (480 * 800 * 4) - (480 * 4) * VIDEO_FONT_HEIGHT);
		for (volatile int addr = 0x57e05000ull; addr < 0x57e05000ull + (800 * 480 * 4); addr += 4) {
			*(volatile int *) (addr) = 0;
		}
		hax_cons.curr_row = 0;
	} else { hax_cons.curr_row += 1; }

	//if(hax_cons.curr_row >= 24) {
	//	for (volatile char addr = 0x57e05000ull; addr < 0x57e05000ull + (800 * 480 * 4); addr += 4) {
	//		*(volatile char *) (addr) = 0;
	//	}
	//}
}

static void hax_lcd_putc_xy0(struct console_t *pcons, ushort x, ushort y, char c)
 {
	int fg_color = 0xFFFFFFFF;
	int bg_color = 0x00000000;
	int i, row;
	int *dst = (int *)(long int)(0x57e05000) +
				  y * (480 * 4 /2) +
				  x;

	for (row = 0; row < VIDEO_FONT_HEIGHT; row++) {
		uchar bits = video_fontdata[c * VIDEO_FONT_HEIGHT + row];
		for (i = 0; i < VIDEO_FONT_WIDTH; ++i) {
			*dst++ = (bits & 0x80) ? fg_color : bg_color;
			bits <<= 1;
		}
		dst += ((480 * 4 /2) - VIDEO_FONT_WIDTH);
	}
}

static inline void hax_console_back(void)
{
	if (--hax_cons.curr_col < 0) {
		hax_cons.curr_col = hax_cons.cols - 1;
		if (--hax_cons.curr_row < 0)
			hax_cons.curr_row = 0;
	}

	hax_lcd_putc_xy0(&hax_cons,
			hax_cons.curr_col * VIDEO_FONT_WIDTH,
			hax_cons.curr_row * VIDEO_FONT_HEIGHT, ' ');
}

static inline void _debug_uart_putc(int c)
{
	switch (c) {
	case '\r':
		hax_cons.curr_col = 0;
		return;
	case '\n':
		hax_console_newline();

		return;
	case '\t':	/* Tab (8 chars alignment) */
		hax_cons.curr_col +=  8;
		hax_cons.curr_col &= ~7;

		if (hax_cons.curr_col >= hax_cons.cols)
			hax_console_newline();

		return;
	case '\b':
		hax_console_back();

		return;
	default:
		hax_lcd_putc_xy0(&hax_cons,
				hax_cons.curr_col * VIDEO_FONT_WIDTH,
				hax_cons.curr_row * VIDEO_FONT_HEIGHT, c);
		if (++hax_cons.curr_col >= hax_cons.cols)
			hax_console_newline();
	}


}

void hax_lcd_puts(const char *s)
{
	while (*s)
		_debug_uart_putc(*s++);
}

static inline void _debug_uart_init(void)
{
	hax_lcd_puts("HOLY");
}

DEBUG_UART_FUNCS
