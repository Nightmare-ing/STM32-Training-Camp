/**
  @page UTILS_ConfigureSystemClock UTILS example
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/UTILS/UTILS_ConfigureSystemClock/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the UTILS example.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  @endverbatim

@par Example Description

Use of UTILS LL API to configure the system clock using PLL with HSI as source clock. 
The user application just needs to calculate the PLL parameters using STM32CubeMX and call the UTILS LL API.

System starts with clock used after reset.
Then, a system clock switch is done to PLL with HSI as PLL clock source. Automatically, FLASH latency
is tuned according to system constraints described in the reference manual.

User can easily set its own PLL parameters in changing global variable used to store them.

A LED2 toggle of 1sec provides this information that system is well configured to requested frequency.  

Anyway, user can connect on oscilloscope to MCO pin (PA.08) to check requested frequency: 
 - SYSCLK frequency with frequency value around @170MHz.

@par Keywords

Utils, system, Clock, HSI, PLL, flash latency, SYSCLK, frequency, Oscilloscope.

@par Directory contents 

  - UTILS/UTILS_ConfigureSystemClock/Inc/stm32g4xx_it.h          Interrupt handlers header file
  - UTILS/UTILS_ConfigureSystemClock/Inc/main.h                  Header for main.c module
  - UTILS/UTILS_ConfigureSystemClock/Inc/stm32_assert.h          Template file to include assert_failed function
  - UTILS/UTILS_ConfigureSystemClock/Src/stm32g4xx_it.c          Interrupt handlers
  - UTILS/UTILS_ConfigureSystemClock/Src/main.c                  Main program
  - UTILS/UTILS_ConfigureSystemClock/Src/system_stm32g4xx.c      STM32G4xx system source file


@par Hardware and Software environment

  - This example runs on STM32G431RBTx devices.
    
  - This example has been tested with NUCLEO-G431RB RevC board and can be
    easily tailored to any other supported device and development board.

  - NUCLEO-G431RB RevC Set-up
    - Connect the MCO pin to an oscilloscope to monitor the different waveforms:
      - PA.08: Arduino connector CN9 pin D7, Morpho connector C10 pin 23 

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 */
