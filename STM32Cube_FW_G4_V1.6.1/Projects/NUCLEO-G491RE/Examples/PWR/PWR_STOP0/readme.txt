/**
  @page PWR_STOP0 Power Stop 0 Mode Example
  
  @verbatim
  ******************************************************************************
  * @file    PWR/PWR_STOP0/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the Power Stop 0 Mode example.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  @endverbatim

@par Example Description 
 
This example shows how to enter Stop 0 mode and wake up from this mode using 
an interrupt.

In the associated software, the system clock is set to 170 MHz, an EXTI line
is connected to the user button through PC.13 and configured to generate an 
interrupt on falling edge upon key press.
The SysTick is programmed to generate an interrupt each 1 ms and in the SysTick 
interrupt handler, LED2 is toggled in order to indicate whether the MCU is in stop 0 mode 
or run mode.

5 seconds after start-up, the system automatically enters stop 0 mode and LED2 stops toggling.

The User push-button can be pressed at any time to wake-up the system.
The software then comes back in run mode for 5 sec. before automatically entering stop 0 mode again.

LED2 is used to monitor the system state as follows:
 - LED2 toggling: system in run mode
 - LED2 off : system in stop 0 mode
 - LED2 on: configuration failed (system will go to an infinite loop)

These steps are repeated in an infinite loop.

@note To measure the current consumption in stop 0 mode, remove JP6 jumper 
      and connect an amperemeter to JP6 to measure IDD current.     

@note This example can not be used in DEBUG mode due to the fact 
      that the Cortex-M4 core is no longer clocked during low power mode 
      so debugging features are disabled.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Keywords

Power, PWR, Stop 0 mode, Interrupt, EXTI, Wakeup, Low Power, External reset

@par Directory contents

  - PWR/PWR_STOP0/Inc/stm32g4xx_nucleo_conf.h     BSP configuration file
  - PWR/PWR_STOP0/Inc/stm32g4xx_conf.h         HAL Configuration file
  - PWR/PWR_STOP0/Inc/stm32g4xx_it.h               Header for stm32g4xx_it.c
  - PWR/PWR_STOP0/Inc/main.h                   Header file for main.c
  - PWR/PWR_STOP0/Src/system_stm32g4xx.c       STM32G4xx system clock configuration file
  - PWR/PWR_STOP0/Src/stm32g4xx_it.c           Interrupt handlers
  - PWR/PWR_STOP0/Src/main.c                   Main program
  - PWR/PWR_STOP0/Src/stm32g4xx_hal_msp.c      HAL MSP module

@par Hardware and Software environment

  - This example runs on STM32G4xx devices

  - This example has been tested with STMicroelectronics NUCLEO-G491RE RevA
    board and can be easily tailored to any other supported device
    and development board.

  - NUCLEO-G491RE RevA set-up:
    - LED2 connected to PA.05 pin
    - User push-button connected to pin PC.13 (External line 13)

    
@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 */
