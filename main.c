//****************************** GMT,IST and PST *******************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : main.c
// Summary : Gives time in GMT,IST and PST
// Note    : None
// Author  : Bimesh Raj K R
// Date    : 18/Jun/2025
//******************************************************************************

//****************************** Include Files *********************************
#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include"appTimer.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//***************************** Local Functions ********************************

//*************************************.main.***********************************
// Purpose : Calls functions to display time in GMT, IST, PST
// Inputs  : None
// Outputs : None
// Return  : 0
// Notes   : Prints Time every second until externally stopped
//******************************************************************************


int main()
{
    time_t currentTime;

    while (1)
    {
        time(&currentTime);
        appTimerDisplayGMT(currentTime);
        appTimerDisplayIST(currentTime);
        appTimerDisplayPST(currentTime);
        Sleep(1);
    }

    return 0;
}
//EOF