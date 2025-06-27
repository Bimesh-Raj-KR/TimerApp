//***************************** GMT, IST and PST *******************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved 
//******************************************************************************
//
// Summary : Contains all global constants and forward declarations
// Note    : None
// 
//******************************************************************************
#ifndef APPTIMER_H
#define APPTIMER_H

//******************************* Include Files ******************************** 
#include<time.h>
#include<stdbool.h>
#include "common.h"
//******************************* Global Types ********************************* 

//***************************** Global Constants ******************************* 
#define INITIALIZER_ZERO    (0)
#define INITIALIZER_ONE     (1)
#define LEAP_CHECK_ONE      (4)
#define MONTHS              (12)
#define TIME_LIMIT          (12)
#define HOURS               (24)
#define MIN_MONTH           (30)
#define FEBRUARY            (28)
#define MAX_MONTH           (31)
#define SECONDS             (60)
#define MAX_ARRAY_SIZE      (100)
#define DAYS                (365)
#define LEAP_CHECK_TWO      (400)
#define MAX_LEAP            (492)
#define INITIAL_YEAR        (1970)
#define TIME_IST            (19800)
#define TIME_PST            (28800)
//***************************** Global Variables ******************************* 

//**************************** Forward Declarations **************************** 
bool appTimerLed(uint16 *unpLedState);
bool appTimerDisplayPST(time_t ulCurrentTime);
bool appTimerDisplayIST(time_t ulCurrentTime);
bool appTimerDisplayGMT(time_t ulCurrentTime);
//*********************** Inline Method Implementations ************************ 

#endif // APPTIMER_H
// EOF 
