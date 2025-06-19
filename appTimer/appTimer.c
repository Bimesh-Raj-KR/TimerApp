//**************************** GMT, IST and PST ********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : appTimer.c
// Summary : Contain functions to find time in GMT,IST and PST
// Note    : None
// Author  : Bimesh Raj K R
// Date    : 18/Jun/2025
//******************************************************************************

//****************************** Include Files *********************************
#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include"appTimer.h"
#include "..\common.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//***************************** Local Functions ********************************
static bool appTimerCheckLeap(uint32 years);
//*****************************.appTimerCheckLeap.******************************
// Purpose : Bool function to check if an year is leap year or not
// Inputs  : Years - current year
// Outputs : None
// Return  : true,false
// Notes   : None
//******************************************************************************
static bool appTimerCheckLeap(uint32 years)
{
    if(ZERO == years % LEAP_CHECK_ONE)
    {
        if (ZERO == years % MAX_ARRAY_SIZE)
        {
            if (ZERO == years % LEAP_CHECK_TWO)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

//***************************.appTimerDisplayPST.*******************************
// Purpose : Function to display time in GMT
// Inputs  : currentTime - Stores current epoch time
// Outputs : Date and Time in PST
// Return  : true,false
// Notes   : None
//******************************************************************************
bool appTimerDisplayPST(time_t currentTime)
{
    if(ZERO == currentTime)
    {
        return false;
    }
    uint16 unIterator;
    uint16 merdianCheck;
    uint16 seconds;
    uint16 minutes;
    uint16 hours;
    uint16 months;
    uint32 days;
    uint32 years;
    currentTime = currentTime - TIME_PST;
    seconds = currentTime % SECONDS;
    currentTime /= SECONDS;
    minutes = currentTime % SECONDS;
    currentTime /= SECONDS;
    hours = currentTime % HOURS;
    currentTime /= HOURS;
    days = currentTime % DAYS;
    years = INITIAL_YEAR + currentTime / DAYS;
    days = days + ONE - ((years)/LEAP_CHECK_ONE - MAX_LEAP);
    uint16 arrayMonths[] = {MAX_MONTH, FEBRUARY, MAX_MONTH, MIN_MONTH, 
        MAX_MONTH, MIN_MONTH, MAX_MONTH, MAX_MONTH, MIN_MONTH, MAX_MONTH,
        MIN_MONTH, MAX_MONTH};
    
    for (unIterator = ZERO; unIterator < MONTHS; unIterator++)
    {
        if (days >= arrayMonths[unIterator])
        {
            days -= arrayMonths[unIterator];
            if(appTimerCheckLeap(years) && ONE == unIterator)
            {
                days--;
            }
        }
        else
        {
            break;
        }
    }

    months = unIterator + ONE;

    if (MONTHS < hours)
    {
        hours = hours - MONTHS;

        merdianCheck = ONE;
    }
    else
    {
        merdianCheck = ZERO;
    }

    if(MONTHS == hours)
    {
        if(ONE == merdianCheck)
        {
            merdianCheck = ZERO;
        }
        else
        {
            merdianCheck = ONE;
        }
    }

    if(0 == merdianCheck)
    {
        printf("\nPST (-8:00)\n--------------------\n");
        printf("Time : %02hu:%02hu:%02hu AM\nDate : %02ld/%02hu/%02ld\n", 
            hours, minutes, seconds, days, months, years);
    }
    else
    {
        printf("\nPST (-8:00)\n--------------------\n");
        printf("Time : %02hu:%02hu:%02hu PM\nDate : %02ld/%02hu/%02ld\n", 
            hours,minutes, seconds, days, months, years);
    }

    return true;
}

//***************************.appTimerDisplayIST.*******************************
// Purpose : Function to display time in IST
// Inputs  : currentTime - Stores current epoch time
// Outputs : Date and Time in IST
// Return  : true,false
// Notes   : None
//******************************************************************************
bool appTimerDisplayIST(time_t currentTime)
{
    if(ZERO == currentTime)
    {
        return false;
    }
    uint16 unIterator;
    uint16 merdianCheck;
    uint16 seconds;
    uint16 minutes;
    uint16 hours;
    uint16 months;
    uint32 days;
    uint32 years;
    currentTime = currentTime + TIME_IST;
    seconds = currentTime % SECONDS;
    currentTime /= SECONDS;
    minutes = currentTime % SECONDS;
    currentTime /= SECONDS;
    hours = currentTime % HOURS;
    currentTime /= HOURS;
    days = currentTime % DAYS;
    years = INITIAL_YEAR + currentTime / DAYS;
    days = days + ONE - ((years)/LEAP_CHECK_ONE - MAX_LEAP);
    uint16 arrayMonths[] = {MAX_MONTH, FEBRUARY, MAX_MONTH, MIN_MONTH, 
        MAX_MONTH, MIN_MONTH, MAX_MONTH, MAX_MONTH, MIN_MONTH, MAX_MONTH,
        MIN_MONTH, MAX_MONTH};
    

    for (unIterator = ZERO; unIterator < MONTHS; unIterator++)
    {
        if (days >= arrayMonths[unIterator])
        {
            days -= arrayMonths[unIterator];
            if(appTimerCheckLeap(years) && ONE == unIterator)
            {
                days--;
            }
        }
        else
        {
            break;
        }
    }

    months = unIterator + ONE;
    if (MONTHS < hours)
    {
        hours = hours - MONTHS;

        merdianCheck = ONE;
    }
    else
    {
        merdianCheck = ZERO;
    }

    if(MONTHS == hours)
    {
        if(ONE == merdianCheck)
        {
            merdianCheck = ZERO;
        }
        else
        {
            merdianCheck = ONE;
        }
    }

    if(ZERO == merdianCheck)
    {
        printf("\nIST (+5:30)\n--------------------\n");
        printf("Time : %02hu:%02hu:%02hu AM\nDate : %02ld/%02hu/%02ld\n", 
            hours, minutes, seconds, days, months, years);
    }
    else
    {
        printf("\nIST (+5:30)\n--------------------\n");
        printf("Time : %02hu:%02hu:%02hu PM\nDate : %02ld/%02hu/%02ld\n", 
            hours,minutes, seconds, days, months, years);
    }

    return true;
}

//***************************.appTimerDisplayGMT.*******************************
// Purpose : Function to display time in GMT
// Inputs  : currentTime - Stores current epoch time
// Outputs : Date and Time in UTC
// Return  : true,false
// Notes   : None
//******************************************************************************
bool appTimerDisplayGMT(time_t currentTime)
{
    if(ZERO == currentTime)
    {
        return false;
    }
    uint16 unIterator;
    uint16 merdianCheck;
    uint16 seconds;
    uint16 minutes;
    uint16 hours;
    uint16 months;
    uint32 days;
    uint32 years;
    seconds = currentTime % SECONDS;
    currentTime /= SECONDS;
    minutes = currentTime % SECONDS;
    currentTime /= SECONDS;
    hours = currentTime % HOURS;
    currentTime /= HOURS;
    days = currentTime % DAYS;
    years = INITIAL_YEAR + currentTime / DAYS;
    days = days + ONE - ((years)/LEAP_CHECK_ONE - MAX_LEAP);
    uint16 arrayMonths[] = {MAX_MONTH, FEBRUARY, MAX_MONTH, MIN_MONTH, 
        MAX_MONTH, MIN_MONTH, MAX_MONTH, MAX_MONTH, MIN_MONTH, MAX_MONTH,
        MIN_MONTH, MAX_MONTH};
    

    for (unIterator = ZERO; unIterator < MONTHS; unIterator++)
    {
        if (days >= arrayMonths[unIterator])
        {
            days -= arrayMonths[unIterator];
            if(appTimerCheckLeap(years) && ONE == unIterator)
            {
                days--;
            }
        }
        else
        {
            break;
        }
    }

    months = unIterator + ONE;
    if (MONTHS < hours)
    {
        hours = hours - MONTHS;

        merdianCheck = ONE;
    }
    else
    {
        merdianCheck = ZERO;
    }

    if(MONTHS == hours)
    {
        if(ONE == merdianCheck)
        {
            merdianCheck = ZERO;
        }
        else
        {
            merdianCheck = ONE;
        }
    }

    if(ZERO == merdianCheck)
    {
        printf("\nUTC (0:00)\n--------------------\n");
        printf("Time : %02hu:%02hu:%02hu AM\nDate : %02ld/%02hu/%02ld\n", 
            hours, minutes, seconds, days, months, years);
        printf("Epoch : %ld\n",time(&currentTime));
    }
    else
    {
        printf("\nUTC (0:00)\n--------------------\n");
        printf("Time : %02hu:%02hu:%02hu PM\nDate : %02ld/%02hu/%02ld\n", 
            hours,minutes, seconds, days, months, years);
        printf("Epoch : %ld\n",time(&currentTime)*1000);
    }

    return true;
}

//EOF