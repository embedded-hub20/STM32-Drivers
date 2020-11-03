/*
 * DMA.c
 *
 *  Created on: May 21, 2018
 *      Author: SG5530150
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "../include/DMA.h"
#include "../include/DIO.h"


typedef struct
{
	u32 ISR;
	u32 IFCR;
}DMA_Int_Reg_t;

volatile DMA_Int_Reg_t * const DMA_INT = (volatile DMA_Int_Reg_t * const )(0x40020000);

typedef struct
{
	u32 CCR;
	u32 CNDR;
	u32 CPAR;
	u32 CMAR;
}DMA_Regiter_t;


typedef volatile DMA_Regiter_t * const DMA_Reg;


void DMA_State(void *ChannelCpy,DMA_Channel_Mode_t DMA_Channel_Mode_t)
{
	DMA_Reg Channel =(DMA_Reg)(ChannelCpy);
	if(Channel_Disable==DMA_Channel_Mode_t)
	{
		CLR_BIT(Channel->CCR,0);
	}
	else
	{
		SET_BIT(Channel->CCR,0);
	}
}

void DMA_SetChannelPiority(void * ChannelCpy,Channel_priority_t Channel_priority)
{
	DMA_Reg Channel = (DMA_Reg)(ChannelCpy);
	Channel->CCR|=(Channel_priority<<12);
}

void DMA_SetMemoryDataSize(void * ChannelCpy,Data_Size_t Data_Size)
{
	DMA_Reg Channel = (DMA_Reg)(ChannelCpy);
	Channel->CCR|=(Data_Size<<10);
}

void DMA_SetPrepheralDataSize(void * ChannelCpy,Data_Size_t Data_Size)
{
	DMA_Reg Channel = (DMA_Reg)(ChannelCpy);
	Channel->CCR|=(Data_Size<<8);
}

void DMA_SetMemoryMode(void * ChannelCpy,DMA_Mode_t DMA_Mode,DMA_Cir_Mode_t DMA_Cir_Mode)
{
	DMA_Reg Channel = (DMA_Reg)(ChannelCpy);
	Channel->CCR|=(DMA_Mode<<7);
	Channel->CCR|=(DMA_Cir_Mode<<5);
}

void DMA_SetPrepheralMode(void * ChannelCpy,DMA_Mode_t DMA_Mode)
{
	DMA_Reg Channel = (DMA_Reg)(ChannelCpy);
	if (NonInc_Mode==DMA_Mode)
	{
		CLR_BIT(Channel->CCR,6);
	}
	else
	{
		SET_BIT(Channel->CCR,6);
	}
}

void DMA_DataDirection(void * ChannelCpy,DMA_Dir_Mode_t DMA_Dir_Mode)
{
	DMA_Reg Channel = (DMA_Reg)(ChannelCpy);
	if (Read_From_Preph==DMA_Dir_Mode)
	{
		CLR_BIT(Channel->CCR,4);
	}
	else
	{
		SET_BIT(Channel->CCR,4);
	}


}

void DMA_Interupt(void * ChannelCpy,DMA_TC_Int_t DMA_TC_Int)
{
	DMA_Reg Channel = (DMA_Reg)(ChannelCpy);
	if(Int_Disable==DMA_TC_Int)
	{
		CLR_BIT(Channel->CCR,1);
	}
	else
	{
		SET_BIT(Channel->CCR,1);
	}
}


void DMA_NumberOfData(void * ChannelCpy,u16 NumberOfData)
{
	DMA_Reg Channel = (DMA_Reg)(ChannelCpy);
	Channel->CNDR=NumberOfData;


}
void DMA_SetPheripralAddress (void * ChannelCpy, u32 PrepheralAddr)
{
	DMA_Reg Channel = (DMA_Reg)(ChannelCpy);
	Channel->CPAR=PrepheralAddr;
}

void DMA_SetMemoryAddress (void * ChannelCpy, u32 MemoryAddr)
{
	DMA_Reg Channel = (DMA_Reg)(ChannelCpy);
	Channel->CMAR=MemoryAddr;
}


void DMA1_Channel1_IRQHandler(void)
{

}
void DMA1_Channel2_IRQHandler(void)
{

}

void DMA1_Channel3_IRQHandler(void)
{

}

void DMA1_Channel4_IRQHandler(void)
{
	DIO_SetPinValue(PA0,HIGH);
}

void DMA1_Channel5_IRQHandler(void)
{

}

void DMA1_Channel6_IRQHandler(void)
{

}

void DMA1_Channel7_IRQHandler(void)
{

}


