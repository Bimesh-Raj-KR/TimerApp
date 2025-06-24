//****************************** GMT,IST and PST *******************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : main.c
// Summary : Current GMT, IST and PST time is displayed every second in 12 hour 
//           system format until externally stopped.
// Note    : None
// Author  : Bimesh Raj K R
// Date    : 18/Jun/2025
//******************************************************************************

//****************************** Include Files *********************************
#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include"appTimer.h"
//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//***************************** Local Functions ********************************

//*************************************.main.***********************************
// Purpose : Calls functions to display time every second in GMT, IST, PST 
//           through an infinite while loop.
// Inputs  : None
// Outputs : None
// Return  : 0
// Notes   : Prints Time every second until externally stopped
//******************************************************************************

int main()
{
    time_t tCurrentTime;

    while (1)
    {
        time(&tCurrentTime);
        appTimerDisplayGMT(tCurrentTime);
        appTimerDisplayIST(tCurrentTime);
        appTimerDisplayPST(tCurrentTime);
        printf("\x1b[H");// Move Cursor to top-left
        sleep(1);
        printf("\x1b[J");// clear screen
    }

    return 0;
}
//EOF