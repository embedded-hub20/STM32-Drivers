/*
 * DIO_cfg.c
 *
 *  Created on: Apr 25, 2018
 *      Author: SG5530150
 */
#include "../include/DIO_cfg.h"

const PinCfg_t PinCfg[]=
{
	/*Reserved is not used */
	/* Pin Name,Direction,  Mode*/
		{PA0,	Output_S2Mhz,	OutPutPushPull},
		{PA1,	Output_S2Mhz,	OutPutPushPull},
		{PA2,	Output_S2Mhz,	OutPutPushPull},
		{PA3,	Output_S2Mhz,	OutPutPushPull},
		{PA5,	Output_S2Mhz,	OutPutPushPull},
		{PA6,	Output_S2Mhz,	OutPutPushPull},
		{PA7,	Output_S2Mhz,	OutPutPushPull},
		{PA8,	Output_S50Mhz,	AlternateFunctionPushPull},
		{PA9,	Output_S2Mhz,	AlternateFunctionPushPull},
		{PA10,	Input,			InputFloating},
		{PA11,	Output_S2Mhz,	OutPutPushPull},
		{PA12,	Output_S2Mhz,	OutPutPushPull},
		{PB0,	Output_S2Mhz,	OutPutPushPull},
		{PB1,	Output_S2Mhz,	OutPutPushPull},
		{PB5,	Output_S2Mhz,	OutPutPushPull},
		{PB6,	Output_S2Mhz,	OutPutPushPull},
		{PB7,	Input,	         InputPullDown},
		{PB8,	Output_S50Mhz,	AlternateFunctionPushPull},
		{PB9,	Output_S2Mhz,	OutPutPushPull},
		{PB10,	Output_S2Mhz,	OutPutPushPull},
		{PB11,	Input,			 InputPullDown},
		{PB12,	Output_S2Mhz,	OutPutPushPull},
		{PB13,	Output_S2Mhz,	OutPutPushPull},
		{PB14,	Output_S2Mhz,	OutPutPushPull},
		{PB15,	Output_S2Mhz,	OutPutPushPull},
		{PC13,	Output_S2Mhz,	OutPutPushPull},
		{PC14,	Output_S2Mhz,	OutPutPushPull},
		{PC15,	Output_S2Mhz,	OutPutPushPull},
};

