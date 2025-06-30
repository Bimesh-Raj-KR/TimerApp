//****************************** LED state and Time ****************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : main.c
// Summary : Time is continously displayed in GMT,IST and PST timezones and 
//           also displays alternating LED states every second until externally 
//           stopped.
// Note    : None
// Author  : Bimesh Raj K R
// Date    : 18/Jun/2025
//******************************************************************************

//****************************** Include Files *********************************
#include<stdio.h>
#include<unistd.h>
#include"appTimer.h"
#include "LedSimulation.h"
//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//***************************** Local Functions ********************************

//*************************************.main.***********************************
// Purpose : Calls functions to display time every second in GMT, IST, PST 
//            and print LED states through an infinite while loop.
// Inputs  : None
// Outputs : None
// Return  : 0
// Notes   : Prints Time every second until externally stopped
//******************************************************************************

int main()
{
    time_t ulCurrentTime;
    uint16 unLedState = INITIALIZER_ZERO;
    while (true)
    {
        time(&ulCurrentTime);
        appTimerDisplayGMT(ulCurrentTime);
        appTimerDisplayIST(ulCurrentTime);
        appTimerDisplayPST(ulCurrentTime);
        LedSimulationStatus(&unLedState);
        printf("\x1b[H");// Move Cursor to top-left
        sleep(1);
        printf("\x1b[J");// clear screen
    }

    return 0;
}
//EOF