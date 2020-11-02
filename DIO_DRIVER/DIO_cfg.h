/*
 * DIO_cfg.h
 *
 *  Created on: Apr 25, 2018
 *      Author: SG5530150
 */

#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#define NUMBER_OF_USED_PINS 28

typedef enum
{
	PA=0,
	PB,
	PC
}PORTS_t;
typedef enum
{
	PA0=0,
	PA1,
	PA2,
	PA3,
	PA4,
	PA5,
	PA6,
	PA7,
	PA8,
	PA9,
	PA10,
	PA11,
	PA12,
    PB0=16,
	PB1,
	PB5=21,
	PB6,
	PB7,
	PB8,
	PB9,
	PB10,
	PB11,
	PB12,
	PB13,
	PB14,
	PB15,
	PC13=45,
	PC14,
	PC15
}GPIOPinName_t;

typedef enum
{
	Input,
	Output_S10Mhz,
	Output_S2Mhz,
	Output_S50Mhz

}GPIODirCfg_t;


typedef enum
{
	Analog=0,
	InputFloating,
	InputPullUp,
	InputPullDown,


	OutPutPushPull=0,
	OutPutOpenDrain,
	AlternateFunctionPushPull,
	AlternateFunctionOpenDrain

}GPIOModeCfg_t;




typedef struct
{
	GPIOPinName_t GPIOPinName;
	GPIODirCfg_t GPIODirCfg;
	GPIOModeCfg_t GPIOModeCfg;

}PinCfg_t;



extern const PinCfg_t PinCfg[];

#endif /* DIO_CFG_H_ */
