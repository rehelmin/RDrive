/**
  ******************************************************************************
  * File Name          : gpio.c
  * Description        : This file provides code for the configuration
  *                      of all used GPIO pins.
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

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(RED_LED_Port, RED_LED_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(NEOPIX_Port, NEOPIX_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC1 */
  GPIO_InitStruct.Pin = RED_LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(RED_LED_Port, &GPIO_InitStruct);

  HAL_GPIO_WritePin(NEOPIX_Port, NEOPIX_Pin, GPIO_PIN_RESET);
  /*Configure GPIO pins : PC0 */
  GPIO_InitStruct.Pin = NEOPIX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(NEOPIX_Port, &GPIO_InitStruct);

  
  /* These are hooked up to an oscillator on the feather board

  // Configure GPIO pin Output Level
  HAL_GPIO_WritePin(GPIOC, M0_nCS_Pin|M1_nCS_Pin, GPIO_PIN_SET);

  // Configure GPIO pins : PCPin PCPin
  GPIO_InitStruct.Pin = M0_nCS_Pin|M1_nCS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  */

  //Configure GPIO pins : PCPin PCPin PCPin

  GPIO_InitStruct.Pin = M1_ENC_Z_Pin|M0_ENC_Z_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
  

  GPIO_InitStruct.Pin = GPIO_5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* These are hooked up to GND and the FLASH_SCK
  signal on the Adafruit feather board

  // Configure GPIO pins : PBPin PBPin
  GPIO_InitStruct.Pin = GPIO_6_Pin|GPIO_8_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  */

  /* This is hooked up to the SD_DETECT
  signal on the Adafruit feather board 

  // Configure GPIO pin Output Level
  HAL_GPIO_WritePin(EN_GATE_GPIO_Port, EN_GATE_Pin, GPIO_PIN_RESET);
  
  // Configure GPIO pin : PtPin
  GPIO_InitStruct.Pin = EN_GATE_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(EN_GATE_GPIO_Port, &GPIO_InitStruct);

  */

  /* This is hooked up to the FLASH_CS
  signal on the Adafruit feather board

  // Configure GPIO pin : PtPin
  GPIO_InitStruct.Pin = GPIO_7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIO_7_GPIO_Port, &GPIO_InitStruct);

  */

  /* This is hooked up to the SDIO_CMD
  signal on the Adafruit feather board 

  // Configure GPIO pin : PtPin
  GPIO_InitStruct.Pin = nFAULT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(nFAULT_GPIO_Port, &GPIO_InitStruct);

  */

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
