/*
 * DMA.h
 *
 *  Created on: May 21, 2018
 *      Author: SG5530150
 */

#ifndef DMA_H_
#define DMA_H_

#define CHANNEL_1	((void*)0x40020008)
#define CHANNEL_2	((void*)0x4002001C)
#define CHANNEL_3	((void*)0x40020030)
#define CHANNEL_4	((void*)0x40020044)
#define CHANNEL_5	((void*)0x40020058)
#define CHANNEL_6	((void*)0x4002006C)
#define CHANNEL_7	((void*)0x40020080)


typedef enum
{
	Low=0,
	Meduim,
	High,
	VeryHigh
}Channel_priority_t;

typedef enum
{
	Data_8Bits=0,
	Data_16Bits,
	Data_32Bits
}Data_Size_t;

typedef enum
{
	NonInc_Mode=0,
	Inc_Mode
}DMA_Mode_t;

typedef enum
{
	NonCir_Mode=0,
	Cir_Mode
}DMA_Cir_Mode_t;

typedef enum
{
	Read_From_Preph=0,
	Read_From_Memory
}DMA_Dir_Mode_t;

typedef enum
{
	Int_Disable=0,
	Int_Enable
}DMA_TC_Int_t;

typedef enum
{
	Channel_Disable=0,
	Channel_Enable
}DMA_Channel_Mode_t;


extern void DMA_State(void * ChannelCpy,DMA_Channel_Mode_t DMA_Channel_Mode_t);

extern void DMA_SetChannelPiority(void * ChannelCpy,Channel_priority_t Channel_priority);

extern void DMA_SetMemoryDataSize(void * ChannelCpy ,Data_Size_t Data_Size);
extern void DMA_SetPrepheralDataSize(void * ChannelCpy,Data_Size_t Data_Size);

extern void DMA_SetMemoryMode(void * ChannelCpy,DMA_Mode_t DMA_Mode,DMA_Cir_Mode_t DMA_Cir_Mode);
extern void DMA_SetPrepheralMode(void * ChannelCpy,DMA_Mode_t DMA_Mode);

extern void DMA_DataDirection(void * ChannelCpy,DMA_Dir_Mode_t DMA_Dir_Mode);

extern void DMA_Interupt(void * ChannelCpy,DMA_TC_Int_t DMA_TC_Int);

extern void DMA_NumberOfData(void * ChannelCpy,u16 NumberOfData);

extern void DMA_SetPheripralAddress (void * ChannelCpy, u32 PrepheralAddr);

extern void DMA_SetMemoryAddress (void * ChannelCpy, u32 MemoryAddr);

#endif /* DMA_H_ */
