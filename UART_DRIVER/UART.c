/*
 * UART.c
 *
 *  Created on: May 17, 2018
 *      Author: SG5530150
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "../include/UART.h"
#include "../include/DIO.h"

typedef enum
{
	Idle=0,
	Sending
}UART_TXState_t;
UART_TXState_t TXstatus=Idle;

typedef enum
{
	Open=0,
	Close
}UART_RXState_t;
UART_RXState_t RXstatus=Close;

typedef struct
{
	u32 SR;
	u32 DR;
	u32 BRR;
	u32 CR1;
	u32 CR2;
	u32 CR3;
	u32 GTPR;
}UART_Reg_t;
volatile UART_Reg_t * const UART1 = (volatile UART_Reg_t * const)(0x40013800);


typedef void (*CallBack_t) (void);
static void stub_H (void);
CallBack_t TX_notify= stub_H;
CallBack_t RX_notify= stub_H;



typedef struct
{
	u8* Data;
	u8 Pos;
	u8 Length;
}Tx_Buffer_t;

typedef struct
{
	u8* Data;
	u8 Pos;
	u8 Length;
}Rx_Buffer_t;

Rx_Buffer_t Rx_Buffer;
Tx_Buffer_t Tx_Buffer;


void UART_Init (void)
{
	UART1->CR1=0x0000206C;
	UART1->BRR=0x00001D4C;

}

void UART_SendData(u8* Data,u8 SizeCpy)
{
	Tx_Buffer.Length=SizeCpy;
	if ((Data==Null) || (Tx_Buffer.Length==0)||(TXstatus==Sending))
	{
		return;
	}
	else
	{
		Tx_Buffer.Data=Data;
		Tx_Buffer.Pos=0;
		UART1->DR=Tx_Buffer.Data[Tx_Buffer.Pos];
		Tx_Buffer.Pos++;
		TXstatus=Sending;
	}
}

void UART_RecieveData(u8 *Data,u8 Size)
{
	Rx_Buffer.Data=Data;
	Rx_Buffer.Pos=0;
	Rx_Buffer.Length=Size;
	RXstatus=Open;
}



void UART1_SetTXCallBack(void (*PtrCpy)(void))
{
	TX_notify=PtrCpy;
}

void UART1_SetRXCallBack(void (*PtrCpy)(void))
{
	RX_notify=PtrCpy;
}

void UART1_EnableDMATransmitter(void)
{
	SET_BIT(UART1->CR3,7);
}
void UART1_EnableDMAReceive(void)
{
	SET_BIT(UART1->CR3,6);

}
void UART1_DisableDMATransmitter(void)
{
	CLR_BIT(UART1->CR3,7);
}
void UART1_DisableDMAReceive(void)
{
	CLR_BIT(UART1->CR3,6);
}

void stub_H (void)
{
	return;
}

void USART1_IRQHandler (void)
{
	if (GET_BIT(UART1->SR,6))
	{
		CLR_BIT(UART1->SR,6);
		if (Tx_Buffer.Pos==Tx_Buffer.Length)
		{
			TXstatus=Idle;
			TX_notify();
			return;
		}
		UART1->DR=Tx_Buffer.Data[Tx_Buffer.Pos];
		Tx_Buffer.Pos++;
	}
	if (GET_BIT(UART1->SR,5))
	{
		CLR_BIT(UART1->SR,5);
		Rx_Buffer.Data[Rx_Buffer.Pos]=UART1->DR;
		Rx_Buffer.Pos++;
		if (Rx_Buffer.Pos==Rx_Buffer.Length)
		{
			RX_notify();
			return;
		}
	}
}
