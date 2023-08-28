#include <asm-offsets.h>
#include <config.h>
#include <linux/linkage.h>
#include <common.h>
#include "spi.h"
#include "../clks.h"
#include "../isr.h"

#ifndef SPIS_MASK
#define SPIS_MASK		((1 << SPIS_COUNT) - 1)
#endif

typedef struct {
	volatile uint32_t *spclkcon;
	volatile uint32_t *spcon;
	volatile uint32_t *spsta;
	volatile uint32_t *sppin;
	volatile uint32_t *sptdat;
	volatile uint32_t *sprdat;
	volatile uint32_t *sppre;
	volatile uint32_t *spcnt;
	volatile uint32_t *spidd;
	volatile uint32_t *spirto;
	volatile uint32_t *spihangd;
	volatile uint32_t *spiswrst;
	volatile uint32_t *spiver;
	volatile uint32_t *sptdcnt;
	uint32_t clock;
	uint32_t irq;
} spi_regs_t;

static const spi_regs_t spi_regs[] = {
#if SPIS_COUNT > 0
	{ &rSPCLKCON0, &rSPCON0, &rSPSTA0, &rSPPIN0, &rSPTDAT0, &rSPRDAT0, &rSPPRE0, &rSPCNT0,
	  &rSPIDD0, &rSPIRTO0, &rSPIHANGD0, &rSPISWRST0, &rSPIVER0, &rSPTDCNT0, CLK_SPI0, INT_SPI0 },
#endif
#if SPIS_COUNT > 1
	{ &rSPCLKCON1, &rSPCON1, &rSPSTA1, &rSPPIN1, &rSPTDAT1, &rSPRDAT1, &rSPPRE1, &rSPCNT1,
	  &rSPIDD1, &rSPIRTO1, &rSPIHANGD1, &rSPISWRST1, &rSPIVER1, &rSPTDCNT1, CLK_SPI1, INT_SPI1 },
#endif
#if SPIS_COUNT > 2
	{ &rSPCLKCON2, &rSPCON2, &rSPSTA2, &rSPPIN2, &rSPTDAT2, &rSPRDAT2, &rSPPRE2, &rSPCNT2,
	  &rSPIDD2, &rSPIRTO2, &rSPIHANGD2, &rSPISWRST2, &rSPIVER2, &rSPTDCNT2, CLK_SPI2, INT_SPI2 },
#endif
#if SPIS_COUNT > 3
	{ &rSPCLKCON3, &rSPCON3, &rSPSTA3, &rSPPIN3, &rSPTDAT3, &rSPRDAT3, &rSPPRE3, &rSPCNT3,
	  &rSPIDD3, &rSPIRTO3, &rSPIHANGD3, &rSPISWRST3, &rSPIVER3, &rSPTDCNT3, CLK_SPI3, INT_SPI3 },
#endif
#if SPIS_COUNT > 4
	{ &rSPCLKCON4, &rSPCON4, &rSPSTA4, &rSPPIN4, &rSPTDAT4, &rSPRDAT4, &rSPPRE4, &rSPCNT4,
	  &rSPIDD4, &rSPIRTO4, &rSPIHANGD4, &rSPISWRST4, &rSPIVER4, &rSPTDCNT4, CLK_SPI4, INT_SPI4 },
#endif
};

static const spi_regs_t *spiregs(int port)
{
	if (port < 0 || port >= SPIS_COUNT || !(SPIS_MASK & (1 << port)))
		panic("Trying to access a nonexisted spi port\n");

	return &spi_regs[port];
}

uint32_t spi_gpio_read(int port)
{
	const spi_regs_t *regs = spiregs(port);

	if (regs == 0)
		return 0;

	return (*regs->sppin >> 1) & 1;
}

void spi_gpio_write(int port, uint32_t val)
{
	const spi_regs_t *regs = spiregs(port);

	if (regs == 0)
		return;

	if (val) *regs->sppin |= (1 << 1);
	else *regs->sppin &= ~(1 << 1);
}
