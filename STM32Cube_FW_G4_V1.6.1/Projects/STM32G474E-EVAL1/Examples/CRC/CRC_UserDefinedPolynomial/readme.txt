/**
  @page CRC_UserDefinedPolynomial User-defined generating polynomial CRC Example
  
  @verbatim
  ******************************************************************************
  * @file    CRC/CRC_UserDefinedPolynomial/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of CRC Example with user-defined generating polynomial.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  @endverbatim

@par Example Description 

How to configure the CRC using the HAL API. The CRC (cyclic
redundancy check) calculation unit computes the 8-bit CRC code for a given
buffer of 32-bit data words, based on a user-defined generating polynomial.
In this example, the polynomial is set manually to 0x9B, that is,
X^8 + X^7 + X^4 + X^3 + X + 1.

At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system
clock (SYSCLK).

The CRC peripheral configuration is ensured by HAL_CRC_Init() function.
The latter is calling HAL_CRC_MspInit() function which core is implementing
the configuration of the needed CRC resources according to the used hardware (CLOCK). 
You can update HAL_CRC_Init() input parameters to change the CRC configuration.

The calculated CRC code is stored in uwCRCValue variable.
Once calculated, the CRC value (uwCRCValue) is compared to the CRC expected value (uwExpectedCRCValue).

STM32 board's LEDs are used to monitor the example status:
  - LED1 (GREEN) is ON when the correct CRC value is calculated
  - LED3 (RED) is ON when there is an error in initialization or if an incorrect CRC value is calculated.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
 to have correct HAL operation.

@par Keywords

Security, CRC, CRC Polynomial, IEC 60870-5, hardware CRC, user-defined generating polynomial

@par Directory contents

  - CRC/CRC_UserDefinedPolynomial/Inc/stm32g474e_eval_conf.h     BSP configuration file
  - CRC/CRC_UserDefinedPolynomial/Inc/stm32g4xx_hal_conf.h    HAL configuration file
  - CRC/CRC_UserDefinedPolynomial/Inc/stm32g4xx_it.h          Interrupt handlers header file
  - CRC/CRC_UserDefinedPolynomial/Inc/main.h                  Header for main.c module
  - CRC/CRC_UserDefinedPolynomial/Src/stm32g4xx_it.c          Interrupt handlers
  - CRC/CRC_UserDefinedPolynomial/Src/main.c                  Main program
  - CRC/CRC_UserDefinedPolynomial/Src/stm32g4xx_hal_msp.c     HAL MSP module 
  - CRC/CRC_UserDefinedPolynomial/Src/system_stm32g4xx.c      STM32G4xx system source file

     
@par Hardware and Software environment

  - This example runs on STM32G474QETx devices.
  - This example has been tested with STM32G474E-EVAL1 Rev B board and can be
    easily tailored to any other supported device and development board.

@par How to use it ? 

In order to make the program work, you must do the following:
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example
 
 */
 
