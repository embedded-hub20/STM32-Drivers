/*
 * OS_cfg.h
 *
 *  Created on: May 18, 2018
 *      Author: SG5530150
 */

#ifndef OS_CFG_H_
#define OS_CFG_H_


typedef void (*Task_H) (void);
typedef struct
{
	u16 Periodicity;
	u16 FirstDelay;
	Task_H Handler;
}Task_t;

extern const Task_t  SYS_Task[];
extern u8 const NumberOfTasks;

#endif /* OS_CFG_H_ */
