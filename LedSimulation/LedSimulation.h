//***************************** LED ON, LED OFF *******************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved 
//******************************************************************************
//
// Summary : Contains all global constants and forward declarations
// Note    : None
// 
//******************************************************************************
#ifndef LEDSIMULATION_H
#define LEDSIMULATION_H

//******************************* Include Files ******************************** 
#include "common.h"

//******************************* Global Types ********************************* 

//***************************** Global Constants ******************************* 
#define BLINK_DELAY_OFF     (532000)
#define BLINK_DELAY_ON      (840000)

//***************************** Global Variables ******************************* 

//**************************** Forward Declarations **************************** 
bool LedSimulationStatus(struct gpiod_line **pstLineNumber);

//*********************** Inline Method Implementations ************************ 

#endif // LEDSIMULATION_H
// EOF 
