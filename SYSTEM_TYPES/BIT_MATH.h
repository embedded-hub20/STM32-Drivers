#ifndef _BIT_MATH_h
#define _BIT_MATH_h

#define SET_BIT(var,bitNo)    (var)|=(1<<bitNo)
#define CLR_BIT(var,bitNo)   (var)&=~(1<<bitNo)
#define TOGGLE_BIT(var,bitNo) (var)^=(1<<bitNo)
#define GET_BIT(var,bitNo)    (((var)>>(bitNo))&0x00000001)
#define CIRCULAR_SHIFT(x,shift) (x << shift) | (x >> (sizeof(x)*8 - shift))

#define BIT_CONC(B7,B6,B5,B4,B3,B2,B1,B0) CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)
#define CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0) 0b##B7##B6##B5##B4##B3##B2##B1##B0



#endif 
