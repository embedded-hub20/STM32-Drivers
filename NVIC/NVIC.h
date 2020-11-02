/*
 * NVIC.h
 *
 *  Created on: May 9, 2018
 *      Author: SG5530150
 */

#ifndef NVIC_H_
#define NVIC_H_

#include "../src/STD_TYPES.h"

typedef enum
{
	Wwdg=0,
	pvd,
	tamper,
	rtc,
	flash,
	rcc,
	exti0,
	exti1,
	exti2,
	exti3,
	exti4,
	dma1_channel1,
	dma1_channel2,
	dma1_channel3,
	dma1_channel4,
	dma1_channel5,
	dma1_channel6,
	dma1_channel7,
	adc1_2,
	usb_hp_can_tx,
	usb_hp_can_rx0,
	can_rx1,
	can_sce,
	exti9_5,
	tim1_brk,
	tim1_up,
	tim1_trg_com,
	tim1_cc,
	Tim2,
	Tim3,
	Tim4,
	i2c1_ev,
	i2c1_er,
	i2c2_ev,
	i2c2_er,
	Spi1,
	Spi2,
	Usart1,
	Usart2,
	Usart3,
	exti5_10,
	rtcalarm,
	usbwakeup,
	tim8_brk,
	tim8_up,
	tim8_trg_com,
	tim8_cc,
	Adc3,
	Fsmc,
	Sdio,
	Tim5,
	Spi3,
	Uart4,
	Uart5,
	Tim6,
	Tim7,
	dma2_channel1,
	dam2_cahnnel2,
	dma2_cahnnel3,
	dam2_cahnnel4_5
}NVIC_Index_t;

extern void NVIC_Enable(NVIC_Index_t NVIC_Index);

extern void NVIC_Disable (NVIC_Index_t NVIC_Index);

extern void NVIC_SoftwareIn(NVIC_Index_t NVIC_Index);

extern void NVIC_EnbaleAllInt(void);

extern void NVIC_DisableAllInt(void);

extern void NVIC_SetPriority(NVIC_Index_t NVIC_Index,u8 Priority);



#endif /* NVIC_H_ */
