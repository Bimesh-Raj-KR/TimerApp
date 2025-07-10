//*********************************** GPIO *************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : GpioController.c
// Summary : Contain functions to check and release chip and line
// Note    : None
// Author  : Bimesh Raj K R
// Date    : 10/Jul/2025
//******************************************************************************

//****************************** Include Files *********************************
#include "GpioController.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//***************************** Local Functions ********************************

//******************************.GpioChipAndLine.*******************************
// Purpose : Bool function to initialize and check chip and line used for Led 
//           Blinking 
// Inputs  : **pstChipInfo - Points to the Address of pointer *pstChipInfo 
//           which represents a GPIO chip
//           **pstLineNumber - Points to the Address of pointer *pstLineNumber 
//           which represents a GPIO line on a GPIO chip
// Outputs : None
// Return  : blCheck
// Notes   : None
//******************************************************************************
bool GpioChipAndLine(struct gpiod_chip **pstChipInfo, 
                     struct gpiod_line **pstLineNumber)
{
    bool blCheck = true;
    *pstChipInfo = gpiod_chip_open("/dev/gpiochip0");

    if (!*pstChipInfo)
    {
        perror("Cannot open GPIO chip");
        blCheck = false;
    }

    *pstLineNumber = gpiod_chip_get_line(*pstChipInfo, GPIO_LINE);

    if (!*pstLineNumber)
    {
        perror("Invalid or Unavailable line");
        gpiod_chip_close(*pstChipInfo);
        blCheck = false;
    }

    if (INITIALIZER_ZERO > gpiod_line_request_output(*pstLineNumber, 
            "Blink LED", INITIALIZER_ZERO))
    {
        perror("Cannot Reserve the Pin as Output");
        gpiod_chip_close(*pstChipInfo);
        blCheck = false;
    }

    if (INITIALIZER_ZERO > gpiod_line_set_value(*pstLineNumber, 
            INITIALIZER_ZERO))
    {
        perror("Cannot set output value of pin");
        gpiod_chip_close(*pstChipInfo);
        blCheck = false;
    }

    return blCheck;
}

//**********************************.GpioClose.*********************************
// Purpose : Bool function to free up the pin and chip for future use 
// Inputs  : **pstChipInfo - Points to the Address of pointer *pstChipInfo 
//           which represents a GPIO chip
//           **pstLineNumber - Points to the Address of pointer *pstLineNumber 
//           which represents a GPIO line on a GPIO chip
// Outputs : None
// Return  : true
// Notes   : None
//******************************************************************************
bool GpioClose(struct gpiod_chip **pstChipInfo, 
               struct gpiod_line **pstLineNumber)
{
    gpiod_line_release(*pstLineNumber);
    gpiod_chip_close(*pstChipInfo);

    return true;
}
//EOF