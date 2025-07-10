//***************************** GMT, IST and PST *******************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved 
//******************************************************************************
//
// Summary : Contains all global constants and forward declarations
// Note    : None
// 
//******************************************************************************
#ifndef GPIOCONTROLLER_H
#define GPIOCONTROLLER_H

//******************************* Include Files ********************************
#include "common.h"

//******************************* Global Types ********************************* 

//***************************** Global Constants ******************************* 
#define GPIO_LINE           (8)  

//***************************** Global Variables ******************************* 

//**************************** Forward Declarations **************************** 
bool GpioChipAndLine(struct gpiod_chip **pstChipInfo, 
                     struct gpiod_line **pstLineNumber);
bool GpioClose(struct gpiod_chip **pstChipInfo, 
               struct gpiod_line **pstLineNumber);
//*********************** Inline Method Implementations ************************ 

#endif // GPIOCONTROLLER_H
// EOF 