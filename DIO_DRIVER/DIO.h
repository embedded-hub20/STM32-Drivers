/*
 * DIO.h
 *
 *  Created on: Apr 25, 2018
 *      Author: SG5530150
 */

#ifndef DIO_H_
#define DIO_H_

#include "DIO_cfg.h"

typedef enum
{
	LOW=0,
	HIGH
}PinValue_t;
extern void test (void);
extern void DIO_Init(void);
extern void DIO_SetPinValue(GPIOPinName_t GPIOPinName,PinValue_t PinValueCpy);
extern PinValue_t DIO_GetPinValue(GPIOPinName_t GPIOPinName);



#endif /* DIO_H_ */
