//**************************** GMT, IST and PST ********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : appTimer.c
// Summary : Contain functions to find time in GMT,IST and PST timezones
// Note    : None
// Author  : Bimesh Raj K R
// Date    : 18/Jun/2025
//******************************************************************************

//****************************** Include Files *********************************
#include"appTimer.h"
#include "../common.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//***************************** Local Functions ********************************
static bool appTimerCheckLeap(uint32 ulYears);
//*****************************.appTimerCheckLeap.******************************
// Purpose : Bool function to check if an year is leap year or not
// Inputs  : Years - current year
// Outputs : None
// Return  : true,false
// Notes   : None
//******************************************************************************
static bool appTimerCheckLeap(uint32 ulYears)
{
    if (ZERO == (ulYears % LEAP_CHECK_ONE))
    {
        if (ZERO == (ulYears % MAX_ARRAY_SIZE))
        {
            if (ZERO == (ulYears % LEAP_CHECK_TWO))
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
// Purpose : Display time of PST timezone in 12 hour system
// Inputs  : tCurrentTime - Stores current epoch time
// Outputs : Date and Time in PST
// Return  : true,false
// Notes   : None
//******************************************************************************
bool appTimerDisplayPST(time_t tCurrentTime)
{
    if (ZERO == tCurrentTime)
    {
        return false;
    }

    uint16 unIterator;
    uint16 unMerdianCheck;
    uint16 unSeconds;
    uint16 unMinutes;
    uint16 unHours;
    uint16 unMonths;
    uint32 ulDays;
    uint32 ulYears;
    tCurrentTime = tCurrentTime - TIME_PST;
    unSeconds = tCurrentTime % SECONDS;
    tCurrentTime /= SECONDS;
    unMinutes = tCurrentTime % SECONDS;
    tCurrentTime /= SECONDS;
    unHours = tCurrentTime % HOURS;
    tCurrentTime /= HOURS;
    ulDays = tCurrentTime % DAYS;
    ulYears = INITIAL_YEAR + tCurrentTime / DAYS;
    ulDays = ulDays + ONE - ((ulYears)/LEAP_CHECK_ONE - MAX_LEAP);
    uint16 unArrayMonths[] = {MAX_MONTH, FEBRUARY, MAX_MONTH, MIN_MONTH, 
        MAX_MONTH, MIN_MONTH, MAX_MONTH, MAX_MONTH, MIN_MONTH, MAX_MONTH,
        MIN_MONTH, MAX_MONTH};

// Loop to Find the Current Day and Month
    for (unIterator = ZERO; unIterator < MONTHS; unIterator++)
    {
        if (ulDays >= unArrayMonths[unIterator])
        {
            ulDays -= unArrayMonths[unIterator];

            if (appTimerCheckLeap(ulYears) && (ONE == unIterator))
            {
                ulDays--;
            }
        }
        else
        {
            break;
        }
    }

    unMonths = unIterator + ONE;

    if (TIME_LIMIT < unHours)
    {
        unHours = unHours - TIME_LIMIT;

        unMerdianCheck = ONE;
    }
    else
    {
        unMerdianCheck = ZERO;
    }

    if (TIME_LIMIT == unHours)
    {
        if (ONE == unMerdianCheck)
        {
            unMerdianCheck = ZERO;
        }
        else
        {
            unMerdianCheck = ONE;
        }
    }

    if (ZERO == unMerdianCheck)
    {
        printf("\nPST (-8:00)\n--------------------\n");
        printf("Time : %02hu:%02hu:%02hu AM\nDate : %02ld/%02hu/%02ld\n", 
            unHours, unMinutes, unSeconds, ulDays, unMonths, ulYears);
    }
    else
    {
        printf("\nPST (-8:00)\n--------------------\n");
        printf("Time : %02hu:%02hu:%02hu PM\nDate : %02ld/%02hu/%02ld\n", 
            unHours,unMinutes, unSeconds, ulDays, unMonths, ulYears);
    }

    return true;
}

//***************************.appTimerDisplayIST.*******************************
// Purpose : Display time of IST timezone in 12 hour system
// Inputs  : tCurrentTime - Stores current epoch time
// Outputs : Date and Time in IST
// Return  : true,false
// Notes   : None
//******************************************************************************
bool appTimerDisplayIST(time_t tCurrentTime)
{
    if (ZERO == tCurrentTime)
    {
        return false;
    }

    uint16 unIterator;
    uint16 unMerdianCheck;
    uint16 unSeconds;
    uint16 unMinutes;
    uint16 unHours;
    uint16 unMonths;
    uint32 ulDays;
    uint32 ulYears;
    tCurrentTime = tCurrentTime + TIME_IST;
    unSeconds = tCurrentTime % SECONDS;
    tCurrentTime /= SECONDS;
    unMinutes = tCurrentTime % SECONDS;
    tCurrentTime /= SECONDS;
    unHours = tCurrentTime % HOURS;
    tCurrentTime /= HOURS;
    ulDays = tCurrentTime % DAYS;
    ulYears = INITIAL_YEAR + tCurrentTime / DAYS;
    ulDays = ulDays + ONE - ((ulYears)/LEAP_CHECK_ONE - MAX_LEAP);
    uint16 unArrayMonths[] = {MAX_MONTH, FEBRUARY, MAX_MONTH, MIN_MONTH, 
        MAX_MONTH, MIN_MONTH, MAX_MONTH, MAX_MONTH, MIN_MONTH, MAX_MONTH,
        MIN_MONTH, MAX_MONTH};

// Loop to Find the Current Day and Month
    for (unIterator = ZERO; unIterator < MONTHS; unIterator++)
    {
        if (ulDays >= unArrayMonths[unIterator])
        {
            ulDays -= unArrayMonths[unIterator];

            if (appTimerCheckLeap(ulYears) && (ONE == unIterator))
            {
                ulDays--;
            }
        }
        else
        {
            break;
        }
    }

    unMonths = unIterator + ONE;

    if (TIME_LIMIT < unHours)
    {
        unHours = unHours - TIME_LIMIT;
        unMerdianCheck = ONE;
    }
    else
    {
        unMerdianCheck = ZERO;
    }

    if (TIME_LIMIT == unHours)
    {
        if (ONE == unMerdianCheck)
        {
            unMerdianCheck = ZERO;
        }
        else
        {
            unMerdianCheck = ONE;
        }
    }

    if (ZERO == unMerdianCheck)
    {
        printf("\nIST (+5:30)\n--------------------\n");
        printf("Time : %02hu:%02hu:%02hu AM\nDate : %02ld/%02hu/%02ld\n", 
            unHours, unMinutes, unSeconds, ulDays, unMonths, ulYears);
    }
    else
    {
        printf("\nIST (+5:30)\n--------------------\n");
        printf("Time : %02hu:%02hu:%02hu PM\nDate : %02ld/%02hu/%02ld\n", 
            unHours,unMinutes, unSeconds, ulDays, unMonths, ulYears);
    }

    return true;
}

//***************************.appTimerDisplayGMT.*******************************
// Purpose : Display time of GMT timezone in 12 hour system
// Inputs  : tCurrentTime - Stores current epoch time
// Outputs : Date and Time in UTC
// Return  : true,false
// Notes   : None
//******************************************************************************
bool appTimerDisplayGMT(time_t tCurrentTime)
{
    if (ZERO == tCurrentTime)
    {
        return false;
    }

    uint16 unIterator;
    uint16 unMerdianCheck;
    uint16 unSeconds;
    uint16 unMinutes;
    uint16 unHours;
    uint16 unMonths;
    uint32 ulDays;
    uint32 ulYears;
    unSeconds = tCurrentTime % SECONDS;
    tCurrentTime /= SECONDS;
    unMinutes = tCurrentTime % SECONDS;
    tCurrentTime /= SECONDS;
    unHours = tCurrentTime % HOURS;
    tCurrentTime /= HOURS;
    ulDays = tCurrentTime % DAYS;
    ulYears = INITIAL_YEAR + tCurrentTime / DAYS;
    ulDays = ulDays + ONE - ((ulYears)/LEAP_CHECK_ONE - MAX_LEAP);
    uint16 unArrayMonths[] = {MAX_MONTH, FEBRUARY, MAX_MONTH, MIN_MONTH, 
        MAX_MONTH, MIN_MONTH, MAX_MONTH, MAX_MONTH, MIN_MONTH, MAX_MONTH,
        MIN_MONTH, MAX_MONTH};

//Loop to Find the Current Day and Month
    for (unIterator = ZERO; unIterator < MONTHS; unIterator++)
    {
        if (ulDays >= unArrayMonths[unIterator])
        {
            ulDays -= unArrayMonths[unIterator];

            if (appTimerCheckLeap(ulYears) && (ONE == unIterator))
            {
                ulDays--;
            }
        }
        else
        {
            break;
        }
    }

    unMonths = unIterator + ONE;

    if (TIME_LIMIT < unHours)
    {
        unHours = unHours - TIME_LIMIT;
        unMerdianCheck = ONE;
    }
    else
    {
        unMerdianCheck = ZERO;
    }

    if (TIME_LIMIT == unHours)
    {
        if (ONE == unMerdianCheck)
        {
            unMerdianCheck = ZERO;
        }
        else
        {
            unMerdianCheck = ONE;
        }
    }

    if (ZERO == unMerdianCheck)
    {
        printf("\nUTC (0:00)\n--------------------\n");
        printf("Time : %02hu:%02hu:%02hu AM\nDate : %02ld/%02hu/%02ld\n", 
            unHours, unMinutes, unSeconds, ulDays, unMonths, ulYears);
    }
    else
    {
        printf("\nUTC (0:00)\n--------------------\n");
        printf("Time : %02hu:%02hu:%02hu PM\nDate : %02ld/%02hu/%02ld\n", 
            unHours,unMinutes, unSeconds, ulDays, unMonths, ulYears);
    }
    printf("Epoch : %ld\n",time(&tCurrentTime));

    return true;
}

//EOF