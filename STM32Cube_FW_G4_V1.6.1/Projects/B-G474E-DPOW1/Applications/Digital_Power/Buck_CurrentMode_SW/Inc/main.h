/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file         main.h
  * @author       STMicroelectronics
  * @brief        Header for main.c file.
  * @details      This file contains the common defines of the application.
  ******************************************************************************
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file in
  * the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  *
 * @history Date       Version Person  Change
 * @history ---------- ------- ------- ----------------------------------------
  * @history 2020-02-14 1.0     PBo     Created with the support of Biricha Digital Power LTd
  * @history 2022-01-04 1.0     RGo     Header modifications
  * @history 2022-01-10 2.0     NSa     Moved Systick_Handler to ISR file and Load_Handler to 
  *                                     app code file
 */

/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "app_dpow.h"

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
//#define DSMPS_DEBUG   // Used for debugging purpose
  
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_HRTIM_MspPostInit(HRTIM_HandleTypeDef *hhrtim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define JOYSTICK_SELECT_Pin GPIO_PIN_13
#define JOYSTICK_SELECT_GPIO_Port GPIOC
#define JOYSTICK_SELECT_EXTI_IRQn EXTI15_10_IRQn
#define BUCKBOOST_LOAD_1_Pin GPIO_PIN_14
#define BUCKBOOST_LOAD_1_GPIO_Port GPIOC
#define BUCKBOOST_LOAD_2_Pin GPIO_PIN_15
#define BUCKBOOST_LOAD_2_GPIO_Port GPIOC
#define BUCKBOOST_USBPD_EN_Pin GPIO_PIN_3
#define BUCKBOOST_USBPD_EN_GPIO_Port GPIOC
#define BUCKBOOST_VIN_Pin GPIO_PIN_1
#define BUCKBOOST_VIN_GPIO_Port GPIOA
#define BUCKBOOST_I_IN_AVG_Pin GPIO_PIN_2
#define BUCKBOOST_I_IN_AVG_GPIO_Port GPIOA
#define BUCKBOOST_VOUT_Pin GPIO_PIN_3
#define BUCKBOOST_VOUT_GPIO_Port GPIOA
#define JOYSTICK_LEFT_Pin GPIO_PIN_4
#define JOYSTICK_LEFT_GPIO_Port GPIOC
#define JOYSTICK_LEFT_EXTI_IRQn EXTI4_IRQn
#define JOYSTICK_DOWN_Pin GPIO_PIN_5
#define JOYSTICK_DOWN_GPIO_Port GPIOC
#define JOYSTICK_DOWN_EXTI_IRQn EXTI9_5_IRQn
#define LED_LEFT_ORANGE_Pin GPIO_PIN_1
#define LED_LEFT_ORANGE_GPIO_Port GPIOB
#define JOYSTICK_RIGHT_Pin GPIO_PIN_2
#define JOYSTICK_RIGHT_GPIO_Port GPIOB
#define JOYSTICK_RIGHT_EXTI_IRQn EXTI2_IRQn
#define JOYSTICK_UP_Pin GPIO_PIN_10
#define JOYSTICK_UP_GPIO_Port GPIOB
#define JOYSTICK_UP_EXTI_IRQn EXTI15_10_IRQn
#define BUCKBOOST_I_IN_SENSE_Pin GPIO_PIN_11
#define BUCKBOOST_I_IN_SENSE_GPIO_Port GPIOB
#define BUCKBOOST_P1_DRIVE_Pin GPIO_PIN_12
#define BUCKBOOST_P1_DRIVE_GPIO_Port GPIOB
#define BUCKBOOST_N1_DRIVE_Pin GPIO_PIN_13
#define BUCKBOOST_N1_DRIVE_GPIO_Port GPIOB
#define BUCKBOOST_N2_DRIVE_Pin GPIO_PIN_14
#define BUCKBOOST_N2_DRIVE_GPIO_Port GPIOB
#define BUCKBOOST_P2_DRIVE_Pin GPIO_PIN_15
#define BUCKBOOST_P2_DRIVE_GPIO_Port GPIOB
#define T_SWDIO_Pin GPIO_PIN_13
#define T_SWDIO_GPIO_Port GPIOA
#define T_SWCLK_Pin GPIO_PIN_14
#define T_SWCLK_GPIO_Port GPIOA
#define LED_DOWN_BLUE_Pin GPIO_PIN_15
#define LED_DOWN_BLUE_GPIO_Port GPIOA
#define T_SWO_Pin GPIO_PIN_3
#define T_SWO_GPIO_Port GPIOB
#define LED_UP_RED_Pin GPIO_PIN_5
#define LED_UP_RED_GPIO_Port GPIOB
#define LED_RIGHT_GREEN_Pin GPIO_PIN_7
#define LED_RIGHT_GREEN_GPIO_Port GPIOB
#define GPO1_Pin GPIO_PIN_9
#define GPO1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
/* Filter parameter P: number of feed-forward taps or coefficients in the range [2:64] */
#define COEFF_VECTOR_B_SIZE     3

/* Filter parameter Q: number of feedback coefficients in the range [1:COEFF_VECTOR_B_SIZE-1] */
#define COEFF_VECTOR_A_SIZE     2
    
/* Throughput parameter: extra space in the input buffer (minimum: 0) */
#define MEMORY_PARAMETER_D1     1

/* Throughput parameter: extra space in the output buffer (minimum: 1) */
#define MEMORY_PARAMETER_D2     2

/* Throughput parameter: watermark threshold for the input buffer */
#define INPUT_THRESHOLD         FMAC_THRESHOLD_1

/* Throughput parameter: watermark threshold for the output buffer (inferior or equal to MEMORY_PARAMETER_D1) */
#define OUTPUT_THRESHOLD        FMAC_THRESHOLD_1

/* FMAC internal memory configuration: base address of the coefficient buffer */
#define COEFFICIENT_BUFFER_BASE 0

/* FMAC internal memory configuration: size of the two coefficient buffers */
#define COEFFICIENT_BUFFER_SIZE COEFF_VECTOR_B_SIZE + COEFF_VECTOR_A_SIZE

/* FMAC internal memory configuration: base address of the input buffer */
#define INPUT_BUFFER_BASE       COEFFICIENT_BUFFER_SIZE

/* FMAC internal memory configuration: size of the input buffer */
#define INPUT_BUFFER_SIZE       COEFF_VECTOR_B_SIZE + MEMORY_PARAMETER_D1

/* FMAC internal memory configuration: base address of the output buffer */
#define OUTPUT_BUFFER_BASE      COEFFICIENT_BUFFER_SIZE + INPUT_BUFFER_SIZE

/* FMAC internal memory configuration: size of the output buffer */
#define OUTPUT_BUFFER_SIZE      COEFF_VECTOR_A_SIZE + MEMORY_PARAMETER_D2

/* FMAC WDATA register address (for DMA transfer) */
#define FMAC_WDATA (0x40021418)

/* HR timer COMP register address (for DMA transfer */
#define HRTIM_TIMA_CMP1 (0x4001689C)

/**************************************************/
/* Paste coefficients from Biricha ST-WDS below   */
/**************************************************/

/* The coefficients were calculated using ST-WDS
 */

/* Coefficients for a 200kHz Buck */
#define SwitchFreq 200e3f

/* Floating point coefficients */
#define B0 (+0.222975898974)
#define B1 (+0.010730533294)
#define B2 (-0.212245365679)
#define A1 (+1.743589743590)
#define A2 (-0.743589743590)
#define K (+5.050505050505)
#define REF (775)
#define DUTY_TICKS_MIN (0)
#define DUTY_TICKS_MAX (4095)
#define SLOPE_VPP (0.5000)
#define DECVAL (0.3650)

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
