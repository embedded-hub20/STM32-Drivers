/*
 * OS.c
 *
 *  Created on: May 18, 2018
 *      Author: SG5530150
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "../include/SYSTICK.h"
#include "../include/OS.h"
#include "../include/DIO.h"

u8 OSFlag=0;
u16 Delay[100];

static void OS_Func (void);
static void Schedular (void);

void OS_Init(void)
{
	u8 i;
	STK_SetCallBack(OS_Func);
	for (i=0;i<NumberOfTasks;i++)
	{
		Delay[i]=SYS_Task[i].FirstDelay;
	}

}

void OS_Start(void)
{
	while (1)
	{
		if (OSFlag)
		{
			OSFlag=0;
			Schedular();

		}
	}

}

void Schedular (void)
{
	u8 i;
	for (i=0;i<NumberOfTasks;i++)
	{
		if (0==Delay[i])
		{
			SYS_Task[i].Handler();
			Delay[i]=SYS_Task[i].Periodicity;
		}
		Delay[i]--;
	}
}
void OS_Func (void)
{

	OSFlag=1;
}
