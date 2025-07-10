//**************************** LED ON, LED OFF *********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : LedSimulation.c
// Summary : Either LED ON or OFF state is printed after checking the value 
//           in pointer. It also Blinks LED if Build Macro is enabled
// Note    : None
// Author  : Bimesh Raj K R
// Date    : 10/Jul/2025
//******************************************************************************

//****************************** Include Files *********************************
#include "LedSimulation.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//***************************** Local Functions ********************************

//**************************.LedSimulationStatus.*******************************
// Purpose : Bool function to print The LED state using if statements
//           Also Display LED state if Build Macro is enabled
//           OFF state is enabled for 532 ms and ON state for 840 ms
// Inputs  : **pstLineNumber - Points to the Address of pointer *pstLineNumber 
//           which represents a GPIO line on a GPIO chip
// Outputs : None
// Return  : true
// Notes   : None
//******************************************************************************
bool LedSimulationStatus(struct gpiod_line **pstLineNumber)
{
    static uint16 unLedState = INITIALIZER_ZERO;

    #ifndef ENABLE_LED_BLINK

    *pstLineNumber = NULL;

    #endif

    if (INITIALIZER_ZERO == unLedState)
    {
        unLedState = INITIALIZER_ONE;
        printf("\nLED OFF\n");

        #ifdef ENABLE_LED_BLINK

        gpiod_line_set_value(*pstLineNumber, false);

        #endif

        usleep(BLINK_DELAY_OFF);
    }
    else
    {
        unLedState = INITIALIZER_ZERO;
        printf("\nLED ON\n");

        #ifdef ENABLE_LED_BLINK

        gpiod_line_set_value(*pstLineNumber, true);

        #endif

        usleep(BLINK_DELAY_ON);
    }

    return true;
}
//EOF