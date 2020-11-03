/*
 * OS_cfg.c
 *
 *  Created on: May 18, 2018
 *      Author: SG5530150
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "../include/OS_cfg.h"
#include "../include/DIO.h"

void App1_H (void)
{
	static u8 flag=0;
	if (flag)
	{
		DIO_SetPinValue(PA0,HIGH);
		flag=0;
	}
	else
	{
		DIO_SetPinValue(PA0,LOW);
		flag=1;
	}
}
void APP2_H (void)
{
	static u8 flag=0;
	if (flag)
	{
		DIO_SetPinValue(PA1,HIGH);
		flag=0;
	}
	else
	{
		DIO_SetPinValue(PA1,LOW);
		flag=1;
	}
}

const Task_t  SYS_Task[]=
{
		{1000,	0,	App1_H},
		{2000,	0,	APP2_H}
};

const u8 NumberOfTasks= sizeof(SYS_Task)/sizeof(Task_t);
