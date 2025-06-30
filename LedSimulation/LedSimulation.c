//**************************** LED ON, LED OFF *********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : LedSimulation.c
// Summary : Either LED ON or OFF state is printed after checking the value 
//           in pointer 
// Note    : None
// Author  : Bimesh Raj K R
// Date    : 30/Jun/2025
//******************************************************************************

//****************************** Include Files *********************************
#include "LedSimulation.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************
static uint16 unLedState = INITIALIZER_ZERO;

//***************************** Local Functions ********************************

//**************************.LedSimulationStatus.*******************************
// Purpose : Bool function to print The LED state using if statements
// Inputs  : None
// Outputs : None
// Return  : blCheck
// Notes   : None
//******************************************************************************
bool LedSimulationStatus()
{
    if (INITIALIZER_ZERO == unLedState)
    {
        unLedState = INITIALIZER_ONE;
        printf("\nLED OFF\n");
    }
    else
    {
        unLedState = INITIALIZER_ZERO;
        printf("\nLED ON\n");
    }

    return true;
}
//EOF