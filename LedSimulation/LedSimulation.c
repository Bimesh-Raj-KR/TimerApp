//**************************** LED ON, LED OFF *********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : appTimer.c
// Summary : Either LED ON or OFF state is printed after checking the value 
//           in pointer 
// Note    : None
// Author  : Bimesh Raj K R
// Date    : 18/Jun/2025
//******************************************************************************

//****************************** Include Files *********************************
#include "LedSimulation.h"
//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//***************************** Local Functions ********************************

//*******************************.appTimerLed.**********************************
// Purpose : Bool function to print The LED state using if statements
// Inputs  : *unLedState - Points to the location of state of LED
// Outputs : None
// Return  : blCheck
// Notes   : None
//******************************************************************************
bool LedSimulationStatus(uint16 *unpLedState)
{
    bool blCheck = true;

    if (NULL == unpLedState)
    {
        blCheck = false;
    }
    else
    {
        if (INITIALIZER_ZERO == *unpLedState)
        {
            *unpLedState = INITIALIZER_ONE;
            printf("\nLED OFF\n");
        }
        else
        {
            *unpLedState = INITIALIZER_ZERO;
            printf("\nLED ON\n");
        }
    }

    return blCheck;
}

//EOF