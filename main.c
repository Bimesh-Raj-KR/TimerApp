//****************************** LED state and Time ****************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : main.c
// Summary : Time is continously displayed in GMT, IST and PST timezones and 
//           also displays alternating LED states every second until externally 
//           stopped. Also Displays LED and prints its state on Terminal
// Note    : None
// Author  : Bimesh Raj K R
// Date    : 10/Jul/2025
//******************************************************************************

//****************************** Include Files *********************************
#include "appTimer.h"
#include "LedSimulation.h"

#ifdef ENABLE_LED_BLINK

#include "GpioController.h"

#endif

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//***************************** Local Functions ********************************

//*************************************.main.***********************************
// Purpose : Calls functions to display time in GMT, IST, PST and print LED 
//           states through an infinite while loop. Enabling Build Macro
//           also Blinks LED ON and OFF
// Inputs  : None
// Outputs : None
// Return  : 0
// Notes   : Prints Time every 1.372 seconds until externally stopped
//******************************************************************************
int main()
{
    time_t ulCurrentTime;
    struct gpiod_line *pstLineNumber = NULL;

    #ifdef ENABLE_LED_BLINK
    struct gpiod_chip *pstChipInfo = NULL;
    GpioChipAndLine(&pstChipInfo, &pstLineNumber);

    #endif

    while (true)
    {
        time(&ulCurrentTime);
        appTimerDisplayGMT(ulCurrentTime);
        appTimerDisplayIST(ulCurrentTime);
        appTimerDisplayPST(ulCurrentTime);
        LedSimulationStatus(&pstLineNumber);
        printf("\x1b[H");// Move Cursor to top-left
        printf("\x1b[J");// clear screen
    }

    #ifdef ENABLE_LED_BLINK

    GpioClose(&pstChipInfo, &pstLineNumber);

    #endif

    return 0;
}
//EOF