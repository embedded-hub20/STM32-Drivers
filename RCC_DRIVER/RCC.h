/*
 * jjj.h
 *
 *  Created on: Apr 21, 2018
 *      Author: SG5530150
 */

#ifndef RCC_H_
#define RCC_H_


typedef enum
{
	hsi=0,
	hse,
	pll
}CLK_t;

typedef enum
{
	MULL_4=2,
	MULL_5,
	MULL_6,
	MULL_7,
	MULL_8,
	MULL_9,
}PLL_MULL_t;

typedef enum
{
	NoClk=3,
	SysClk,
	MCO_HSI,
	MCO_HSE,
	PLL_DIV_2
}MCO_source_t;

typedef enum
{
	NotOk=0,
	Ok
}return_status_t;

typedef enum
{
	disable=0,
	enable,
	reset
}status_t;

typedef enum
{
	APB_NoDiv=3,
	APB_Div2,
	APB_Div4,
	APB_Div8,
	APB_Div16,
}APB_PRE_t;

typedef enum
{
	AHB_NoDiv=7,
	AHB_Div2,
	AHB_Div4,
	AHB_Div8,
	AHB_Div16,
	AHB_Div64,
	AHB_Div128,
	AHB_Div256,
	AHB_Div512

}AHB_PRE_t;

typedef enum
{
	ADC_Div2=0,
	ADC_Div4,
	ADC_Div6,
	ADC_Div8

}ADC_PRE_t;

typedef enum
{
	dma1=0,
	dma2,
	sram,
	flitf=4,
	crce=6,
	fsmc=8,
	sdio=10,
}AHB_PERI_t;

typedef enum
{
	afio=0,
	pa=2,
	pb,
	pc,
	pd,
	pe,
	pf,
	pg,
	adc1,
	adc2,
	tim1,
	spi1,
	tim8,
	usart1,
	adc3,
	tim9=19,
	tim10,
	tim11,

}APB2_PERI_t;

typedef enum
{
	tim2=0,
	tim3,
	tim4,
	tim5,
	tim6,
	tim7,
	tim12,
	tim13,
	tim14,
	wwdg=11,
	spi2=14,
	spi3,
	usart2=17,
	usart3,
	uart4,
	uart5,
	i2c1,
	i2c2,
	usb,
	can=25,
	bkq=27,
	pwr,
	dac,
}APB1_PERI_t;


extern return_status_t rcc_setClockStatus(CLK_t CLK,status_t status);
extern return_status_t rcc_configurePLL(CLK_t CLK,PLL_MULL_t PLL_MULL);
extern void rcc_configureSYSCLK(CLK_t CLK);
extern void rcc_configureMCO(MCO_source_t MCO_source);

extern void rcc_setAPB1Prescalar (APB_PRE_t APB1_PRE);
extern void rcc_setAPB2Prescalar (APB_PRE_t  APB2_PRE);
extern void rcc_setAHBPrescalar (AHB_PRE_t AHB_PRE);
extern void rcc_setADCPrescalar (ADC_PRE_t  ADC_PRE);

extern void rcc_APB1PeriCmd (APB1_PERI_t APB1_PERI,status_t status);
extern void rcc_APB2PeriCmd (APB2_PERI_t APB2_PERI,status_t status);
extern void rcc_AHBPeriCmd (AHB_PERI_t AHB_PERI,status_t status);


#endif /* RCC_H_ */
