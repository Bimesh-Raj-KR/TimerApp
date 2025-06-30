//**************************** LED state and Time ********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : appTimer.c
// Summary : Contain functions to find time in GMT,IST and PST timezones and to
//           and to altenate and print LED state every second
// Note    : None
// Author  : Bimesh Raj K R
// Date    : 18/Jun/2025
//******************************************************************************

//****************************** Include Files *********************************
#include"appTimer.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//***************************** Local Functions ********************************
static bool appTimerCheckLeap(uint32 ulYears);

//*******************************.appTimerLed.**********************************
// Purpose : Bool function to print The LED state using if statements
// Inputs  : *unLedState - Points to the location of state of LED
// Outputs : None
// Return  : blCheck
// Notes   : None
//******************************************************************************
bool appTimerLed(uint16 *unpLedState)
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
//*****************************.appTimerCheckLeap.******************************
// Purpose : Bool function to check if an year is leap year or not
// Inputs  : Years - current year
// Outputs : None
// Return  : blCheck
// Notes   : None
//******************************************************************************
static bool appTimerCheckLeap(uint32 ulYears)
{
    bool blCheck = true;

    if (INITIALIZER_ZERO == (ulYears % LEAP_CHECK_ONE))
    {
        if (INITIALIZER_ZERO == (ulYears % MAX_ARRAY_SIZE))
        {
            if (INITIALIZER_ZERO == (ulYears % LEAP_CHECK_TWO))
            {
                blCheck = true;
            }
            else
            {
                blCheck = false;
            }
        }
        else
        {
            blCheck = true;
        }
    }
    else
    {
        blCheck = false;
    }

    return blCheck;
}

//***************************.appTimerDisplayPST.*******************************
// Purpose : Display time of PST timezone in 12 hour system
// Inputs  : ulCurrentTime - Stores current epoch time
// Outputs : Date and Time in PST
// Return  : blCheck
// Notes   : None
//******************************************************************************
bool appTimerDisplayPST(time_t ulCurrentTime)
{
    bool blCheck = true;

    if (INITIALIZER_ZERO == ulCurrentTime)
    {
        blCheck = false;
    }

    uint16 unIterator = INITIALIZER_ZERO;
    uint16 unMerdianCheck = INITIALIZER_ZERO;
    uint16 unSeconds = INITIALIZER_ZERO;
    uint16 unMinutes = INITIALIZER_ZERO;
    uint16 unHours = INITIALIZER_ZERO;
    uint16 unMonths = INITIALIZER_ZERO;
    uint32 ulDays = INITIALIZER_ZERO;
    uint32 ulYears = INITIALIZER_ZERO;
    ulCurrentTime = ulCurrentTime - TIME_PST;
    unSeconds = ulCurrentTime % SECONDS;
    ulCurrentTime /= SECONDS;
    unMinutes = ulCurrentTime % SECONDS;
    ulCurrentTime /= SECONDS;
    unHours = ulCurrentTime % HOURS;
    ulCurrentTime /= HOURS;
    ulDays = ulCurrentTime % DAYS;
    ulYears = INITIAL_YEAR + ulCurrentTime / DAYS;
    ulDays = ulDays + INITIALIZER_ONE - ((ulYears)/LEAP_CHECK_ONE - MAX_LEAP);
    uint16 unArrayMonths[] = {MAX_MONTH, FEBRUARY, MAX_MONTH, MIN_MONTH, 
        MAX_MONTH, MIN_MONTH, MAX_MONTH, MAX_MONTH, MIN_MONTH, MAX_MONTH,
        MIN_MONTH, MAX_MONTH};

// Loop to Find the Current Day and Month
    for (unIterator = INITIALIZER_ZERO; unIterator < MONTHS; unIterator++)
    {
        if (ulDays >= unArrayMonths[unIterator])
        {
            if (appTimerCheckLeap(ulYears) && (INITIALIZER_ONE == unIterator))
            {
                unArrayMonths[unIterator] ++;
                ulDays -= unArrayMonths[unIterator];
                unArrayMonths[unIterator] --;
            }
            else
            {
                ulDays -= unArrayMonths[unIterator];
            }
        }
        else
        {
            break;
        }
    }

    unMonths = unIterator + INITIALIZER_ONE;

    if (ulDays == INITIALIZER_ZERO)
    {
        unMonths -= INITIALIZER_ONE;
        ulDays = unArrayMonths[unMonths - INITIALIZER_ONE];
    }

    if (TIME_LIMIT < unHours)
    {
        unHours = unHours - TIME_LIMIT;

        unMerdianCheck = INITIALIZER_ONE;
    }
    else
    {
        unMerdianCheck = INITIALIZER_ZERO;
    }

    if (TIME_LIMIT == unHours)
    {
        if (INITIALIZER_ONE == unMerdianCheck)
        {
            unMerdianCheck = INITIALIZER_ZERO;
        }
        else
        {
            unMerdianCheck = INITIALIZER_ONE;
        }
    }

    if (INITIALIZER_ZERO == unMerdianCheck)
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

    return blCheck;
}

//***************************.appTimerDisplayIST.*******************************
// Purpose : Display time of IST timezone in 12 hour system
// Inputs  : ulCurrentTime - Stores current epoch time
// Outputs : Date and Time in IST
// Return  : blCheck
// Notes   : None
//******************************************************************************
bool appTimerDisplayIST(time_t ulCurrentTime)
{
    bool blCheck = true;

    if (INITIALIZER_ZERO == ulCurrentTime)
    {
        blCheck = false;
    }

    uint16 unIterator = INITIALIZER_ZERO;
    uint16 unMerdianCheck = INITIALIZER_ZERO;
    uint16 unSeconds = INITIALIZER_ZERO;
    uint16 unMinutes = INITIALIZER_ZERO;
    uint16 unHours = INITIALIZER_ZERO;
    uint16 unMonths = INITIALIZER_ZERO;
    uint32 ulDays = INITIALIZER_ZERO;
    uint32 ulYears = INITIALIZER_ZERO;
    ulCurrentTime = ulCurrentTime + TIME_IST;
    unSeconds = ulCurrentTime % SECONDS;
    ulCurrentTime /= SECONDS;
    unMinutes = ulCurrentTime % SECONDS;
    ulCurrentTime /= SECONDS;
    unHours = ulCurrentTime % HOURS;
    ulCurrentTime /= HOURS;
    ulDays = ulCurrentTime % DAYS;
    ulYears = INITIAL_YEAR + ulCurrentTime / DAYS;
    ulDays = ulDays + INITIALIZER_ONE - ((ulYears)/LEAP_CHECK_ONE - MAX_LEAP);
    uint16 unArrayMonths[] = {MAX_MONTH, FEBRUARY, MAX_MONTH, MIN_MONTH, 
        MAX_MONTH, MIN_MONTH, MAX_MONTH, MAX_MONTH, MIN_MONTH, MAX_MONTH,
        MIN_MONTH, MAX_MONTH};

// Loop to Find the Current Day and Month
    for (unIterator = INITIALIZER_ZERO; unIterator < MONTHS; unIterator++)
    {
        if (ulDays >= unArrayMonths[unIterator])
        {
            if (appTimerCheckLeap(ulYears) && (INITIALIZER_ONE == unIterator))
            {
                unArrayMonths[unIterator] ++;
                ulDays -= unArrayMonths[unIterator];
                unArrayMonths[unIterator] --;
            }
            else
            {
                ulDays -= unArrayMonths[unIterator];
            }
        }
        else
        {
            break;
        }
    }

    unMonths = unIterator + INITIALIZER_ONE;

    if (ulDays == INITIALIZER_ZERO)
    {
        unMonths -= INITIALIZER_ONE;
        ulDays = unArrayMonths[unMonths - INITIALIZER_ONE];
    }

    if (TIME_LIMIT < unHours)
    {
        unHours = unHours - TIME_LIMIT;
        unMerdianCheck = INITIALIZER_ONE;
    }
    else
    {
        unMerdianCheck = INITIALIZER_ZERO;
    }

    if (TIME_LIMIT == unHours)
    {
        if (INITIALIZER_ONE == unMerdianCheck)
        {
            unMerdianCheck = INITIALIZER_ZERO;
        }
        else
        {
            unMerdianCheck = INITIALIZER_ONE;
        }
    }

    if (INITIALIZER_ZERO == unMerdianCheck)
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

    return blCheck;
}

//***************************.appTimerDisplayGMT.*******************************
// Purpose : Display time of GMT timezone in 12 hour system
// Inputs  : ulCurrentTime - Stores current epoch time
// Outputs : Date and Time in UTC
// Return  : blCheck
// Notes   : None
//******************************************************************************
bool appTimerDisplayGMT(time_t ulCurrentTime)
{
    bool blCheck = true;

    if (INITIALIZER_ZERO == ulCurrentTime)
    {
        blCheck = false;
    }

    uint16 unIterator = INITIALIZER_ZERO;
    uint16 unMerdianCheck = INITIALIZER_ZERO;
    uint16 unSeconds = INITIALIZER_ZERO;
    uint16 unMinutes = INITIALIZER_ZERO;
    uint16 unHours = INITIALIZER_ZERO;
    uint16 unMonths = INITIALIZER_ZERO;
    uint32 ulDays = INITIALIZER_ZERO;
    uint32 ulYears = INITIALIZER_ZERO;
    unSeconds = ulCurrentTime % SECONDS;
    ulCurrentTime /= SECONDS;
    unMinutes = ulCurrentTime % SECONDS;
    ulCurrentTime /= SECONDS;
    unHours = ulCurrentTime % HOURS;
    ulCurrentTime /= HOURS;
    ulDays = ulCurrentTime % DAYS;
    ulYears = INITIAL_YEAR + ulCurrentTime / DAYS;
    ulDays = ulDays + INITIALIZER_ONE - ((ulYears)/LEAP_CHECK_ONE - MAX_LEAP);
    uint16 unArrayMonths[] = {MAX_MONTH, FEBRUARY, MAX_MONTH, MIN_MONTH, 
        MAX_MONTH, MIN_MONTH, MAX_MONTH, MAX_MONTH, MIN_MONTH, MAX_MONTH,
        MIN_MONTH, MAX_MONTH};

//Loop to Find the Current Day and Month
    for (unIterator = INITIALIZER_ZERO; unIterator < MONTHS; unIterator++)
    {
        if (ulDays >= unArrayMonths[unIterator])
        {
            if (appTimerCheckLeap(ulYears) && (INITIALIZER_ONE == unIterator))
            {
                unArrayMonths[unIterator] ++;
                ulDays -= unArrayMonths[unIterator];
                unArrayMonths[unIterator] --;
            }
            else
            {
                ulDays -= unArrayMonths[unIterator];
            }
        }
        else
        {
            break;
        }
    }

    unMonths = unIterator + INITIALIZER_ONE;

    if (ulDays == INITIALIZER_ZERO)
    {
        unMonths -= INITIALIZER_ONE;
        ulDays = unArrayMonths[unMonths - INITIALIZER_ONE];
    }

    if (TIME_LIMIT < unHours)
    {
        unHours = unHours - TIME_LIMIT;
        unMerdianCheck = INITIALIZER_ONE;
    }
    else
    {
        unMerdianCheck = INITIALIZER_ZERO;
    }

    if (TIME_LIMIT == unHours)
    {
        if (INITIALIZER_ONE == unMerdianCheck)
        {
            unMerdianCheck = INITIALIZER_ZERO;
        }
        else
        {
            unMerdianCheck = INITIALIZER_ONE;
        }
    }

    if (INITIALIZER_ZERO == unMerdianCheck)
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
    printf("Epoch : %ld\n",time(&ulCurrentTime));

    return blCheck;
}

//EOF