/**
  ******************************************************************************
  * @file    BSP/Src/button.c
  * @author  MCD Application Team
  * @brief   This example code shows how to use the button feature in the
  *          STM32G474E EVAL driver
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup STM32G4xx_HAL_Examples
  * @{
  */

/** @addtogroup BSP
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Button demo
  * @param  None
  * @retval 0 if ok, else value < 0.
  */
int32_t Button_demo(void)
{
  int32_t  result = 0;

  printf("TEST OF BUTTONS\n");

  /* ----------------- */
  /* Test in GPIO mode */
  /* ----------------- */
  /* Initialize buttons */
  if (BSP_PB_Init(BUTTON_USER, BUTTON_MODE_GPIO) != BSP_ERROR_NONE) result--;

  /* Check buttons state */
  if (BSP_PB_GetState(BUTTON_USER) != 0) result--;

  /* Ask user to press buttons and check results */
  printf("Please press user button\n");
  while (BSP_PB_GetState(BUTTON_USER) != 1);
  printf("User button pressed\n");

  /* De-initialize buttons */
  if (BSP_PB_DeInit(BUTTON_USER) != BSP_ERROR_NONE) result--;

  HAL_Delay(1000);

  /* ----------------- */
  /* Test in EXTI mode */
  /* ----------------- */
  /* Initialize buttons */
  UserButtonPressed = 0;
  if (BSP_PB_Init(BUTTON_USER, BUTTON_MODE_EXTI) != BSP_ERROR_NONE) result--;

  /* Check buttons state */
  if (BSP_PB_GetState(BUTTON_USER) != 0) result--;

  /* Ask user to press buttons and check results */
  printf("Please press User button\n");
  while (UserButtonPressed == 0);
  printf("User button pressed\n");

  HAL_Delay(1000);
  UserButtonPressed = 0;

  /* Re-ask user to press buttons and check results */
  printf("Please press one more time User button\n");
  while (UserButtonPressed == 0);
  printf("User button pressed\n");

  HAL_Delay(1000);
  UserButtonPressed = 0;

  /* De-initialize buttons */
  if (BSP_PB_DeInit(BUTTON_USER) != BSP_ERROR_NONE) result--;

  /*restore button now, else next keypress is not detected anymore */
  BSP_PB_Init(BUTTON_USER, BUTTON_MODE_EXTI);

  return result;
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
