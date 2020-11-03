/*
 * SYSTICK.h
 *
 *  Created on: May 18, 2018
 *      Author: SG5530150
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

typedef enum
{
	AHB_DIV_8=0,
	AHB_Speed
}STK_Source_t;

extern void STK_Configuration (STK_Source_t STK_Source,u32 InitValue);
extern void STK_EnableExcep (void);
extern void STK_DisableExcep (void);
extern void STK_Start(void);
extern void STK_SetCallBack(void(*PtrCpy)(void));


#endif /* SYSTICK_H_ */
