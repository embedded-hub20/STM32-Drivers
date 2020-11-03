/*
 * RCC.c
 *
 *  Created on: Apr 22, 2018
 *      Author: SG5530150
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "../include/RCC.h"

typedef struct
{
	u32 CR;
	u32 CFGR;
	u32 CIR;
	u32 APB2RSTR;
	u32 APB1RSTR;
	u32 AHBENR;
	u32 APB2ENR;
	u32 APB1ENR;
	u32 BDCR;
	u32 CSR;
}rcc_t;

volatile rcc_t * const rcc = (volatile rcc_t * const)(0x40021000);

/* HSI or HSE*/
return_status_t rcc_setClockStatus(CLK_t CLK,status_t status)
{
	return_status_t returnStatus;

	if(status == enable)
	{
		switch (CLK)
		{
		case hsi:
			SET_BIT(rcc->CR,0);
			while(GET_BIT(rcc->CR,1) == 0);
			break;
		case hse:
			SET_BIT(rcc->CR,16);
			while(GET_BIT(rcc->CR,17) == 0);
			break;
		case pll:
			SET_BIT(rcc->CR,24);
			while(GET_BIT(rcc->CR,25)==0);
			break;
		}
		returnStatus = Ok;
	}
	else
	{
		switch (CLK)
		{
		case hsi:
			CLR_BIT(rcc->CR,0);
			break;
		case hse:
			CLR_BIT(rcc->CR,16);
			break;
		case pll:
			CLR_BIT(rcc->CR,24);
			break;
		}
	}

	return returnStatus;
}

return_status_t rcc_configurePLL(CLK_t CLK,PLL_MULL_t PLL_MULL)
{
	if(CLK==hsi)
	{
		CLR_BIT(rcc->CFGR,16);
	}
	else
	{
		SET_BIT(rcc->CFGR,16);
	}
	rcc->CFGR &=~(0x003C0000);
	rcc->CFGR |= (PLL_MULL<<18);
	return Ok;
}

void rcc_configureSYSCLK(CLK_t CLK)
{
	rcc->CFGR&=~(0x00000003);
	rcc->CFGR|=CLK;
}
void rcc_configureMCO(MCO_source_t MCO_source)
{
	rcc->CFGR|=(MCO_source<<24);
}

void rcc_setAPB1Prescalar (APB_PRE_t APB1_PRE)
{
	rcc->CFGR|=(APB1_PRE<<8);
}
void rcc_setAPB2Prescalar (APB_PRE_t  APB2_PRE)
{
	rcc->CFGR|=(APB2_PRE<<11);
}
void rcc_setAHBPrescalar (AHB_PRE_t AHB_PRE)
{
	rcc->CFGR|=(AHB_PRE<<4);
}
void rcc_setADCPrescalar (ADC_PRE_t ADC_PRE)
{
	rcc->CFGR|=(ADC_PRE<<14);
}

void rcc_APB1PeriCmd (APB1_PERI_t APB1_PERI,status_t status)
{
	if (status==enable)
	{
		SET_BIT(rcc->APB1ENR,APB1_PERI);
	}
	else
	{
		CLR_BIT(rcc->APB1ENR,APB1_PERI);
	}
}


void rcc_APB2PeriCmd (APB2_PERI_t APB2_PERI,status_t status)
{
	if (status==enable)
	{
		SET_BIT(rcc->APB2ENR,APB2_PERI);
	}
	else
	{
		CLR_BIT(rcc->APB2ENR,APB2_PERI);
	}
}
void rcc_AHBPeriCmd (AHB_PERI_t AHB_PERI,status_t status)
{
	if (status==enable)
	{
		SET_BIT(rcc->AHBENR,AHB_PERI);
	}
	else
	{
		CLR_BIT(rcc->AHBENR,AHB_PERI);
	}
}

