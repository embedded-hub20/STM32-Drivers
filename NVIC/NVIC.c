/*
 * NVIC.c
 *
 *  Created on: May 9, 2018
 *      Author: SG5530150
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "../include/NVIC.h"


#define NVIC_BASE_ADDRESS  0xE000E100

#define ISER0_OFFSET 	   0x00000000
#define ISER1_OFFSET 	   0x00000004

#define ICER0_OFFSET 	   0x00000080
#define ICER1_OFFSET 	   0x00000084

#define ISPR0_OFFSET	   0x00000100
#define ISPR1_OFFSET	   0x00000104

#define IABR0_OFFSET       0x00000200
#define IABR1_OFFSET	   0x00000204

#define ISER0 *((volatile u32 *)(NVIC_BASE_ADDRESS+ISER0_OFFSET))
#define ISER1 *((volatile u32 *)(NVIC_BASE_ADDRESS+ISER1_OFFSET))

#define ICER0 *((volatile u32 *)(NVIC_BASE_ADDRESS+ICER0_OFFSET))
#define ICER1 *((volatile u32 *)(NVIC_BASE_ADDRESS+ICER1_OFFSET))

#define ISPR0 *((volatile u32 *)(NVIC_BASE_ADDRESS+ISPR0_OFFSET))
#define ISPR1 *((volatile u32 *)(NVIC_BASE_ADDRESS+ISPR1_OFFSET))

#define IABR0 *((volatile u32 *)(NVIC_BASE_ADDRESS+IABR0_OFFSET))
#define IABR1 *((volatile u32 *)(NVIC_BASE_ADDRESS+IABR1_OFFSET))

typedef struct
{
	u32 IPR[15];
}IPR_Reg_t;

volatile IPR_Reg_t * const IPR= (volatile IPR_Reg_t * const)(0xE000E400);

void NVIC_Enable (NVIC_Index_t NVIC_Index)
{
	u8 Reg;
	u8 Pin;
	Reg=NVIC_Index/32;
	Pin=NVIC_Index%32;
	if (0==Reg)
	{
		SET_BIT(ISER0,Pin);
	}
	else
	{
		SET_BIT(ISER1,Pin);
	}
}

void NVIC_Disable (NVIC_Index_t NVIC_Index)
{
	u8 Reg;
	u8 Pin;
	Reg=NVIC_Index/32;
	Pin=NVIC_Index%32;
	if (0==Reg)
	{
		SET_BIT(ICER0,Pin);
	}
	else
	{
		SET_BIT(ICER1,Pin);
	}
}

void NVIC_SoftwareIn(NVIC_Index_t NVIC_Index)
{
	u8 Reg;
	u8 Pin;
	Reg=NVIC_Index/32;
	Pin=NVIC_Index%32;
	if (0==Reg)
	{
		SET_BIT(ISPR0,Pin);
	}
	else
	{
		SET_BIT(ISPR1,Pin);
	}

}

void NVIC_EnbaleAllInt(void)
{
	asm("MOV R0,#0");
	asm("MSR PRIMASK,R0");
}

void NVIC_DisableAllInt(void)
{
	asm("MOV R0,#1");
	asm("MSR PRIMASK,R0");
}

void NVIC_SetPriority(NVIC_Index_t NVIC_Index,u8 Priority)
{
	u8 Reg;
	u8 Pin;
	Reg=NVIC_Index/4;
	Pin=NVIC_Index%4;
	IPR->IPR[Reg]|=(Priority<<(Pin*8));

}


