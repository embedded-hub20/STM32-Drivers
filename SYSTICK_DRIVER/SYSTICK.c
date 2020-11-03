/*
 * SYSTICK.c
 *
 *  Created on: May 18, 2018
 *      Author: SG5530150
 */
#include "STD_TYPES.h"
#include  "BIT_MATH.h"
#include "../include/SYSTICK.h"
#include "../include/DIO.h"

typedef void (*STKCallBack_t) (void);
static void stunb_H (void);
STKCallBack_t STKCallBack =stunb_H;

typedef struct
{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;

}STK_t;

volatile STK_t * const STK=(volatile STK_t * const)(0xE000E010);

void STK_Configuration (STK_Source_t STK_Source,u32 InitValue)
{
	if (STK_Source)
	{
		SET_BIT(STK->CTRL,2);
	}
	else
	{
		CLR_BIT(STK->CTRL,2);
	}
	STK->LOAD=InitValue;
}

void STK_EnableExcep (void)
{
	SET_BIT(STK->CTRL,1);
}

void STK_DisableExcep (void)
{
	CLR_BIT(STK->CTRL,1);

}

void STK_Start(void)
{
	SET_BIT(STK->CTRL,0);
}

void STK_SetCallBack(void(*PtrCpy)(void))
{
	STKCallBack=PtrCpy;
}

void SysTick_Handler (void)
{
	STKCallBack();
}

void stunb_H (void)
{
	return;
}
