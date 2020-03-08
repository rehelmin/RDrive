/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#include "console.h"
#include "can.h"

uint8_t ucHeap[configTOTAL_HEAP_SIZE] __attribute__((section("ccmram")));

/* Definitions for defaultTask */
osThreadId_t consoleTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "consoleTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128
};

osThreadId_t communicationTaskHandle;
const osThreadAttr_t communicationTask_attributes = {
  .name = "communicationTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128
};

osThreadId_t motionTaskHandle;
const osThreadAttr_t motionTask_attributes = {
  .name = "motionTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128
};

osThreadId_t controllerTaskHandle;
const osThreadAttr_t controllerTask_attributes = {
  .name = "controllerTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128
};



/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
   
/* USER CODE END FunctionPrototypes */

void StartConsoleTask(void *argument);
void StartCommunicationTask(void *argument);
void StartMotionTask(void *argument);
void StartControllerTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
       
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  consoleTaskHandle = osThreadNew(StartConsoleTask, NULL, &defaultTask_attributes);
  communicationTaskHandle = osThreadNew(StartCommunicationTask, NULL, &communicationTask_attributes);
  motionTaskHandle = osThreadNew(StartMotionTask, NULL, &motionTask_attributes);
  controllerTaskHandle = osThreadNew(StartControllerTask, NULL, &controllerTask_attributes);


}

/* USER CODE BEGIN Header_StartConsoleTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_StartConsoleTask */
void StartConsoleTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    ConsoleProcess();
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_1);
    osDelay(50);
    SEGGER_SYSVIEW_Print("Console Task\n");
  }
  /* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
void StartCommunicationTask(void *argument)
{

  /* Infinite loop */
  for(;;)
  {
    CanProcess();
    osDelay(10);
  }
}

void StartMotionTask(void *argument)
{

  /* Infinite loop */
  for(;;)
  {
    osDelay(1000);
  }
  /* USER CODE END StartDefaultTask */
}

void StartControllerTask(void *argument)
{

  /* Infinite loop */
  for(;;)
  {
    osDelay(1000);
  }
  /* USER CODE END StartDefaultTask */
}   
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
