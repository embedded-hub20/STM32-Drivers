/*
 * UART.h
 *
 *  Created on: May 17, 2018
 *      Author: SG5530150
 */

#ifndef UART_H_
#define UART_H_

extern void UART_Init (void);
extern void UART_SendData(u8* Data,u8 SizeCpy);
extern void UART_RecieveData(u8 *Data,u8 Size);
extern void UART1_SetTXCallBack(void (*PtrCpy)(void));
extern void UART1_SetRXCallBack(void (*PtrCpy)(void));
extern void UART1_EnableDMATransmitter(void);
extern void UART1_EnableDMAReceive(void);
extern void UART1_DisableDMATransmitter(void);
extern void UART1_DisableDMAReceive(void);




#endif /* UART_H_ */
