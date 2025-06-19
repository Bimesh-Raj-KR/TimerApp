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

//******************************* Include Files ******************************* 
#include<stdio.h>
#include<time.h>
#include<stdbool.h>
//******************************* Global Types ******************************** 
typedef unsigned short uint16;
typedef unsigned long uint32;
//***************************** Global Constants ****************************** 
#define ZERO            (0)
#define ONE             (1)
#define LEAP_CHECK_ONE  (4)
#define MONTHS          (12)
#define HOURS           (24)
#define MIN_MONTH       (30)
#define FEBRUARY        (28)
#define MAX_MONTH       (31)
#define SECONDS         (60)
#define MAX_ARRAY_SIZE  (100)
#define DAYS            (365)
#define LEAP_CHECK_TWO  (400)
#define MAX_LEAP        (492)
#define INITIAL_YEAR    (1970)
#define TIME_PST        (28800)
#define TIME_IST        (19800)
//***************************** Global Variables ****************************** 

//**************************** Forward Declarations *************************** 
bool appTimerDisplayPST(time_t currentTime);
bool appTimerDisplayIST(time_t currentTime);
bool appTimerDisplayGMT(time_t currentTime);
//*********************** Inline Method Implementations *********************** 

#endif // APPTIMER_H
// EOF 
