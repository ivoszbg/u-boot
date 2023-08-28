#ifndef __PLATFORM_SOC_HWISR_H
#define __PLATFORM_SOC_HWISR_H

#define INT_SW0			0	// Software 0 Interrupt
#define INT_SW1			1	// Software 1 Interrupt
#define INT_SW2			2	// Software 2 Interrupt
#define INT_SW3			3	// Software 3 Interrupt
#define INT_WDT			4	// Watchdog Timer Interrupt
#define INT_SWI			5	// SWI Interrupt
#define INT_DWI			6	// DWI Interrupt
#define INT_ISP0		7	// ISP 0 Interrupt
#define INT_ISP1       		8	// ISP 1 Interrupt
#define INT_SCALER0		9	// Scaler Interrupt
#define INT_SCALER1		10	// Scaler Interrupt
#define INT_USB_OTG		11	// USB OTG Interrupt
#define INT_USB_EHCI		12	// USB EHCI Interrupt
#define INT_USB_OHCI0		13	// USB OHCI 0 Interrupt
#define INT_USB_OHCI1		14	// USB OHCI 1 Interrupt
#define INT_USB_RES		15	// USB PHY Interrupt
#define INT_PWM			16	// PWM Interrupt
#define INT_PKE			17	// PKE Interrupt
#define INT_IIC0		18	// I2C 0 Interrupt
#define INT_IIC1		19	// I2C 1 Interrupt
#define INT_IIC2		20	// I2C 2 Interrupt
#define INT_UART0		21	// UART 0 Interrupt
#define INT_UART1		22	// UART 1 Interrupt
#define INT_UART2		23	// UART 2 Interrupt
#define INT_UART3		24	// UART 3 Interrupt
#define INT_UART4 		25	// UART 4 Interrupt
#define INT_UART5 		26	// UART 5 Interrupt
#define INT_UART6 		27	// UART 6 Interrupt
#define INT_SPI0 		28	// SPI 0 Interrupt
#define INT_SPI1		29	// SPI 1 Interrupt
#define INT_SPI2		30	// SPI 2 Interrupt
#define INT_SPI3		31	// SPI 3 Interrupt
#define INT_SPI4		32	// SPI 4 Interrupt
#define INT_FMI0		33	// FMI 0 Interrupt
#define INT_FMI1		34	// FMI 1 Interrupt

// Reserved 35 - 36

#define INT_SHA1		37	// SHA-1 Interrupt
#define INT_SHA2		38	// SHA-1 Interrupt
#define INT_WIFI		39	// WiFi Interrupt
#define INT_TVOUT		40	// TV Out Interrupt

// Reserved 41

#define INT_CLCD		42	// CLCD Interrupt
#define INT_DISP0		43	// Display Pipe 0 Interrupt	
#define INT_DISP1		44	// Display Pipe 1 Interrupt
#define INT_RGBOUT		45	// RGB Out Interrupt
#define INT_DPORT0		46	// DisplayPort 0 Interrupt
#define INT_DPORT1		47	// DisplayPort 1 Interrupt
#define INT_VENC		48	// Video Encoder Interrupt
#define INT_SGX			49	// SGX Interrupt
#define INT_VDEC		50	// Video Decoder Interrupt
#define INT_CDMA_DMAC1		51	// CDMA DMA Channel 1 Interrupt
#define INT_CDMA_DMAC2		52	// CDMA DMA Channel 2 Interrupt
#define INT_CDMA_DMAC3		53	// CDMA DMA Channel 3 Interrupt
#define INT_CDMA_DMAC4		54	// CDMA DMA Channel 4 Interrupt
#define INT_CDMA_DMAC5		55	// CDMA DMA Channel 5 Interrupt
#define INT_CDMA_DMAC6		56	// CDMA DMA Channel 6 Interrupt
#define INT_CDMA_DMAC7		57	// CDMA DMA Channel 7 Interrupt
#define INT_CDMA_DMAC8		58	// CDMA DMA Channel 8 Interrupt
#define INT_CDMA_DMAC9		59	// CDMA DMA Channel 9 Interrupt
#define INT_CDMA_DMAC10		60	// CDMA DMA Channel 10 Interrupt
#define INT_CDMA_DMAC11		61	// CDMA DMA Channel 11 Interrupt
#define INT_CDMA_DMAC12		62	// CDMA DMA Channel 12 Interrupt
#define INT_CDMA_DMAC13		63	// CDMA DMA Channel 13 Interrupt
#define INT_CDMA_DMAC14		64	// CDMA DMA Channel 14 Interrupt
#define INT_CDMA_DMAC15		65	// CDMA DMA Channel 15 Interrupt
#define INT_CDMA_DMAC16		66	// CDMA DMA Channel 16 Interrupt
#define INT_CDMA_DMAC17		67	// CDMA DMA Channel 17 Interrupt
#define INT_CDMA_DMAC18		68	// CDMA DMA Channel 18 Interrupt
#define INT_CDMA_DMAC19		69	// CDMA DMA Channel 19 Interrupt
#define INT_CDMA_DMAC20		70	// CDMA DMA Channel 20 Interrupt
#define INT_CDMA_DMAC21		71	// CDMA DMA Channel 21 Interrupt
#define INT_CDMA_DMAC22		72	// CDMA DMA Channel 22 Interrupt
#define INT_CDMA_DMAC23		73	// CDMA DMA Channel 23 Interrupt
#define INT_CDMA_DMAC24		74	// CDMA DMA Channel 24 Interrupt
#define INT_CDMA_DMAC25		75	// CDMA DMA Channel 25 Interrupt
#define INT_CDMA_DMAC26		76	// CDMA DMA Channel 26 Interrupt
#define INT_CDMA_DMAC27		77	// CDMA DMA Channel 27 Interrupt
#define INT_CDMA_DMAC28		78	// CDMA DMA Channel 28 Interrupt
#define INT_CDMA_DMAC29		79	// CDMA DMA Channel 29 Interrupt
#define INT_CDMA_DMAC30		80	// CDMA DMA Channel 30 Interrupt
#define INT_CDMA_DMAC31		81	// CDMA DMA Channel 31 Interrupt
#define INT_CDMA_DMAC32		82	// CDMA DMA Channel 32 Interrupt
#define INT_CDMA_DMAC33		83	// CDMA DMA Channel 33 Interrupt
#define INT_CDMA_DMAC34		84	// CDMA DMA Channel 34 Interrupt
#define INT_CDMA_DMAC35		85	// CDMA DMA Channel 35 Interrupt
#define INT_CDMA_DMAC36		86	// CDMA DMA Channel 36 Interrupt
#define INT_CDMA_DMAC37		87	// CDMA DMA Channel 37 Interrupt
#define INT_CDMA_DMAC38		88	// CDMA DMA Channel 38 Interrupt
#define INT_CDMA_DMAC39		89	// CDMA DMA Channel 39 Interrupt
#define INT_CDMA_DMAC40		90	// CDMA DMA Channel 40 Interrupt
#define INT_CDMA_DMAC41		91	// CDMA DMA Channel 41 Interrupt
#define INT_CDMA_DMAC42		92	// CDMA DMA Channel 42 Interrupt
#define INT_CDMA_DMAC43		93	// CDMA DMA Channel 43 Interrupt

// Reserved 94 - 96

// Audio and Highland Park Interrupts 97 - 115

#define INT_AUDIO_CPU_IRQ0	97	// 
#define INT_AUDIO_CPU_IRQ1	98	// 

#define INT_ADSP_F0		112	// DSP
#define INT_ADSP_F1		113	// DSP
#define INT_ADSP_T0		114	// DSP
#define INT_ADSP_T1		115	// DSP

#define INT_HPERFNRT_DART	116	// HPerf-NRT DART Interrupt
#define INT_HPERFRT_DART	117	// HPerf-RT DART Interrupt
#define INT_JPEG0		118	// JPEG 0 Interrupt
#define INT_GPIO0		119	// GPIO 0 Interrupt
#define INT_GPIO1		120	// GPIO 1 Interrupt
#define INT_MCU			121	// MCU Interrupt
#define INT_MCU0		122	// MCU Phy 0 Interrupt
#define INT_MCU1		123	// MCU Phy 1 Interrupt
#define INT_PIO0		124	// PIO 0 Interrupt
#define INT_PIO1		125	// PIO 1 Interrupt
#define INT_JPEG1		126	// JPEG 1 Interrupt
#define INT_IOP_COMMRX		127	// IOP CommRx Interrupt
#define INT_IOP_COMMTX		128	// IOP CommTx Interrupt
#define INT_IOP_PMI		129	// IOP PerfMon Interrupt
#define INT_IOP_CTIIRQ		130	// IOP CTIIRQ Interrupt
#define INT_ISP_COMMRX		131	// IOP CommRx Interrupt
#define INT_ISP_COMMTX		132	// IOP CommTx Interrupt
#define INT_ISP_PMI		133	// IOP PerfMon Interrupt
#define INT_ISP_CTIIRQ		134	// IOP CTIIRQ Interrupt

// Reserved 135 - 136

#define INT_CPU0_COMMRX		137	// IOP CommRx Interrupt
#define INT_CPU0_COMMTX		138	// IOP CommTx Interrupt

// Reserved 139 - 140

#define INT_CPU1_COMMRX		141	// IOP CommRx Interrupt
#define INT_CPU1_COMMTX		142	// IOP CommTx Interrupt

// Reserved 143

#define INT_LPDP		144	// Low Power Display Port Interrupt

// Reserved 145 - 149

#define INT_MCU2		150	// MCU Phy 2 Interrupt
#define INT_MCU3		151	// MCU Phy 3 Interrupt
#define INT_PMGR_PMI		152	// PMGR PerfMon Interrupt
#define INT_HPERFNTR_PMI	153	// HPerf-NRT PerfMon Interrupt
#define INT_HPERFRT_PMI		154	// HPerf-RT PerfMon Interrupt
#define INT_DPIPE0_PMI		155	// Display Pipe 0 PerfMon Interrupt
#define INT_DPIPE1_PMI		156	// Display Pipe 1 PerfMon Interrupt

// Reserved 157 - 159

#define INT_ETB_FULL		160	// ETB Full Interrupt

// Reserved 161

#define INT_CPU0_VTIMER		162	// CPU 0 Virtual Timer Interrupt
#define INT_CPU0_DEBUG		163	// CPU 0 Debug Interrupt

// Reserved 164

#define INT_CPU1_VTIMER		165	// CPU 1 Virtual Timer Interrupt
#define INT_CPU1_DEBUG		166	// CPU 1 Debug Interrupt

// Reserved 167

#define INT_MCA			168	// Multi-Channel Audio Interrupt
#define INT_KEYGEN		169	// CDMA Keygen Interrupt
#define INT_THERM_ALARM0	170	// Thermal Alarm 0 Interrupt
#define INT_THERM_ALARM1	171	// Thermal Alarm 1 Interrupt
#define INT_THERM_TEMP0		172	// Thermal Temp 0 Interrupt
#define INT_THERM_TEMP1		173	// Thermal Temp 1 Interrupt

// Reserved 174 - 191

#if PLATFORM_VARIANT_IOP

#include <drivers/aic/aic.h>

#define INT_HOST		INT_SW2			// Host processor doorbell
#define INT_IOP			INT_SW3			// I/O coprocessor doorbell
#define INT_IOP_NMI		kAIC_VEC_SW_TMR		// I/O coprocessor NMI

#elif PLATFORM_VARIANT_AUDIO

#include <drivers/audio/audio.h>

#define INT_HOST		AE2_INT_SW0		// Host processor doorbell
#define INT_IOP			AE2_INT_SW0		// I/O coprocessor doorbell
#define INT_IOP_NMI		AE2_INT_SW1		// I/O coprocessor NMI

#endif

#endif /* ! __PLATFORM_SOC_HWISR_H */
