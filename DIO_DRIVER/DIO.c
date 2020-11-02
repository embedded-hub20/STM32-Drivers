/*
 * DIO.c
 *
 *  Created on: Apr 25, 2018
 *      Author: SG5530150
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "../include/DIO.h"

typedef struct
{
	u32 CRL;
	u32 CRH;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 BRR;
	u32 LCK;
}gpio_t;

volatile gpio_t * const PORTA= (volatile gpio_t * const)(0x40010800);
volatile gpio_t * const PORTB = (volatile gpio_t * const)(0x40010C00);
volatile gpio_t * const PORTC = (volatile gpio_t * const)(0x40011000);

void test (void)
{
	PORTA->CRH=0x0000000B;
}

 void DIO_Init(void)
{
	u8 LoopIndex;
	u8 temp;
	u8 PORT;
	u8 PIN;
	PORTA->CRL=0;
	PORTA->CRH=0;
	PORTB->CRL=0;
	PORTB->CRH=0;
	PORTC->CRL=0;
	PORTC->CRH=0;
	for (LoopIndex=0;LoopIndex<NUMBER_OF_USED_PINS;LoopIndex++)
	{
		temp=PinCfg[LoopIndex].GPIOPinName;
		PORT=temp/16;
		PIN=temp%16;
		switch (PORT)
		{
		case PA:
		{
			if (PIN<8)
			{
				PORTA->CRL|=(PinCfg[LoopIndex].GPIODirCfg<<(PIN*4));
				if (PinCfg[LoopIndex].GPIODirCfg==Input)
				{
					if (PinCfg[LoopIndex].GPIOModeCfg==InputPullUp)
					{
						PORTA->CRL|=(2<<((PIN*4)+2));
						SET_BIT(PORTA->ODR,PIN);
					}
					else if (PinCfg[LoopIndex].GPIOModeCfg==InputPullDown)
					{
						PORTA->CRL|=(2<<((PIN*4)+2));
						CLR_BIT(PORTA->ODR,PIN);
					}
					else
					{
						PORTA->CRL|=(PinCfg[LoopIndex].GPIOModeCfg<<((PIN*4)+2));
					}

				}
				else
				{
					PORTA->CRL|=(PinCfg[LoopIndex].GPIOModeCfg<<((PIN*4)+2));
				}
			}
			else
			{
				PIN=PIN-8;
				PORTA->CRH|=(PinCfg[LoopIndex].GPIODirCfg<<(PIN*4));
				if (PinCfg[LoopIndex].GPIODirCfg==Input)
				{
					if (PinCfg[LoopIndex].GPIOModeCfg==InputPullUp)
					{
						PORTA->CRH|=(2<<((PIN*4)+2));
						SET_BIT(PORTA->ODR,(PIN+8));
					}
					else if (PinCfg[LoopIndex].GPIOModeCfg==InputPullDown)
					{
						PORTA->CRH|=(2<<((PIN*4)+2));
						CLR_BIT(PORTA->ODR,(PIN+8));
					}
					else
					{
						PORTA->CRH|=(PinCfg[LoopIndex].GPIOModeCfg<<((PIN*4)+2));
					}

				}
				else
				{
					PORTA->CRH|=(PinCfg[LoopIndex].GPIOModeCfg<<((PIN*4)+2));
				}
			}

			break;
		}
		case PB:
		{
			if (PIN<8)
			{
				PORTB->CRL|=(PinCfg[LoopIndex].GPIODirCfg<<(PIN*4));
				if (PinCfg[LoopIndex].GPIODirCfg==Input)
				{
					if (PinCfg[LoopIndex].GPIOModeCfg==InputPullUp)
					{
						PORTB->CRL|=(2<<((PIN*4)+2));
						SET_BIT(PORTB->ODR,PIN);
					}
					else if (PinCfg[LoopIndex].GPIOModeCfg==InputPullDown)
					{
						PORTB->CRL|=(2<<((PIN*4)+2));
						CLR_BIT(PORTB->ODR,PIN);
					}
					else
					{
						PORTB->CRL|=(PinCfg[LoopIndex].GPIOModeCfg<<((PIN*4)+2));
					}

				}
				else
				{
					PORTB->CRL|=(PinCfg[LoopIndex].GPIOModeCfg<<((PIN*4)+2));
				}
			}
			else
			{
				PIN=PIN-8;
				PORTB->CRH|=(PinCfg[LoopIndex].GPIODirCfg<<(PIN*4));
				if (PinCfg[LoopIndex].GPIODirCfg==Input)
				{
					if (PinCfg[LoopIndex].GPIOModeCfg==InputPullUp)
					{
						PORTB->CRH|=(2<<((PIN*4)+2));
						SET_BIT(PORTB->ODR,(PIN+8));
					}
					else if (PinCfg[LoopIndex].GPIOModeCfg==InputPullDown)
					{
						PORTB->CRH|=(2<<((PIN*4)+2));
						CLR_BIT(PORTB->ODR,(PIN+8));
					}
					else
					{
						PORTB->CRH|=(PinCfg[LoopIndex].GPIOModeCfg<<((PIN*4)+2));
					}

				}
				else
				{
					PORTB->CRH|=(PinCfg[LoopIndex].GPIOModeCfg<<((PIN*4)+2));
				}
			}
			break;
		}
		case PC:
		{
			if (PIN<8)
			{
				PORTC->CRL|=(PinCfg[LoopIndex].GPIODirCfg<<(PIN*4));
				if (PinCfg[LoopIndex].GPIODirCfg==Input)
				{
					if (PinCfg[LoopIndex].GPIOModeCfg==InputPullUp)
					{
						PORTC->CRL|=(2<<((PIN*4)+2));
						SET_BIT(PORTC->ODR,PIN);
					}
					else if (PinCfg[LoopIndex].GPIOModeCfg==InputPullDown)
					{
						PORTC->CRL|=(2<<((PIN*4)+2));
						CLR_BIT(PORTC->ODR,PIN);
					}
					else
					{
						PORTC->CRL|=(PinCfg[LoopIndex].GPIOModeCfg<<((PIN*4)+2));
					}

				}
				else
				{
					PORTC->CRL|=(PinCfg[LoopIndex].GPIOModeCfg<<((PIN*4)+2));
				}
			}
			else
			{
				PIN=PIN-8;
				PORTC->CRH|=(PinCfg[LoopIndex].GPIODirCfg<<(PIN*4));
				if (PinCfg[LoopIndex].GPIODirCfg==Input)
				{
					if (PinCfg[LoopIndex].GPIOModeCfg==InputPullUp)
					{
						PORTC->CRH|=(2<<((PIN*4)+2));
						SET_BIT(PORTC->ODR,(PIN+8));
					}
					else if (PinCfg[LoopIndex].GPIOModeCfg==InputPullDown)
					{
						PORTC->CRH|=(2<<((PIN*4)+2));
						CLR_BIT(PORTC->ODR,(PIN+8));
					}
					else
					{
						PORTC->CRH|=(PinCfg[LoopIndex].GPIOModeCfg<<((PIN*4)+2));
					}

				}
				else
				{
					PORTC->CRH|=(PinCfg[LoopIndex].GPIOModeCfg<<((PIN*4)+2));
				}
			}
			break;
		}
		}
	}
};


 void DIO_SetPinValue(GPIOPinName_t GPIOPinName,PinValue_t PinValueCpy)
{
	u8 temp;
	u8 PORT;
	u8 PIN;
	temp=GPIOPinName;
	PORT=temp/16;
	PIN=temp%16;
	switch (PORT)
	{
	case PA:
	{
		if (PinValueCpy==HIGH)
		{
			SET_BIT(PORTA->BSRR,PIN);
		}
		else
		{
			SET_BIT(PORTA->BRR,PIN);
		}
		break;
	}
	case PB:
	{
		if (PinValueCpy==HIGH)
		{
			SET_BIT(PORTB->BSRR,PIN);
		}
		else
		{
			SET_BIT(PORTB->BRR,PIN);
		}

		break;
	}
	case PC:
	{
		if (PinValueCpy==HIGH)
		{
			SET_BIT(PORTC->BSRR,PIN);
		}
		else
		{
			SET_BIT(PORTC->BRR,PIN);
		}
		break;
	}
	}
}

PinValue_t DIO_GetPinValue(GPIOPinName_t GPIOPinName)
{
	u8 temp;
	u8 PORT;
	u8 PIN;
	PinValue_t status;
	temp=GPIOPinName;
	PORT=temp/16;
	PIN=temp%16;
	switch (PORT)
	{
	case PA:
	{
		if (GET_BIT(PORTA->IDR,PIN))
		{
			status=HIGH;
		}
		else
		{
			status=LOW;
		}
		break;
	}
	case PB:
	{
		if (GET_BIT(PORTB->IDR,PIN))
		{
			status=HIGH;
		}
		else
		{
			status=LOW;
		}

		break;
	}
	case PC:
	{
		if (GET_BIT(PORTC->IDR,PIN))
		{
			status=HIGH;
		}
		else
		{
			status=LOW;
		}
		break;
	}
	}
return status;
}


