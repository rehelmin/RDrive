/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "dataDefs.h"
#include "FreeRTOS.h"
#include "queue.h"

#define CONSOLE_QUEUE_MAX_LENGTH  256

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* Data definitions ---------------------------------------------------------*/

QueueHandle_t consoleQueue;
QueueHandle_t controllerQueue;
QueueHandle_t motionQueue;
QueueHandle_t communicationsQueue;

typedef struct
{
  ConsoleMessageID_t eDataID;
  ConsoleMessageSource_t eDataSource;
  char * messageBuffer;
} ConsoleData_t;

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
