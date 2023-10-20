/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ANALOG1_Pin GPIO_PIN_0
#define ANALOG1_GPIO_Port GPIOC
#define ANALOG2_Pin GPIO_PIN_1
#define ANALOG2_GPIO_Port GPIOC
#define ANALOG3_Pin GPIO_PIN_2
#define ANALOG3_GPIO_Port GPIOC
#define ANALOG4_Pin GPIO_PIN_3
#define ANALOG4_GPIO_Port GPIOC
#define ANALOG5_Pin GPIO_PIN_0
#define ANALOG5_GPIO_Port GPIOA
#define ANALOG6_Pin GPIO_PIN_1
#define ANALOG6_GPIO_Port GPIOA
#define ANALOG7_Pin GPIO_PIN_2
#define ANALOG7_GPIO_Port GPIOA
#define ANALOG8_Pin GPIO_PIN_3
#define ANALOG8_GPIO_Port GPIOA
#define ANALOG9_Pin GPIO_PIN_4
#define ANALOG9_GPIO_Port GPIOA
#define ANALOG10_Pin GPIO_PIN_5
#define ANALOG10_GPIO_Port GPIOA
#define ANALOG11_Pin GPIO_PIN_6
#define ANALOG11_GPIO_Port GPIOA
#define ANALOG12_Pin GPIO_PIN_7
#define ANALOG12_GPIO_Port GPIOA
#define ANALOG13_Pin GPIO_PIN_4
#define ANALOG13_GPIO_Port GPIOC
#define ANALOG14_Pin GPIO_PIN_5
#define ANALOG14_GPIO_Port GPIOC
#define ANALOG15_Pin GPIO_PIN_0
#define ANALOG15_GPIO_Port GPIOB
#define ANALOG16_Pin GPIO_PIN_1
#define ANALOG16_GPIO_Port GPIOB
#define ID_LR_Pin GPIO_PIN_12
#define ID_LR_GPIO_Port GPIOB
#define ID_FR_Pin GPIO_PIN_13
#define ID_FR_GPIO_Port GPIOB
#define LED3_Pin GPIO_PIN_2
#define LED3_GPIO_Port GPIOD
#define LED2_Pin GPIO_PIN_3
#define LED2_GPIO_Port GPIOB
#define LED1_Pin GPIO_PIN_4
#define LED1_GPIO_Port GPIOB
#define LED0_Pin GPIO_PIN_5
#define LED0_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
