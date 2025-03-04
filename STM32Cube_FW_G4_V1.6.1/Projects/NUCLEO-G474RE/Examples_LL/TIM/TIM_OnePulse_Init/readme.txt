/**
  @page TIM_OnePulse_Init TIM example
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/TIM/TIM_OnePulse_Init/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the TIM_OnePulse_Init example.
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

Configuration of a timer to generate a positive pulse in 
Output Compare mode with a length of tPULSE and after a delay of tDELAY. This example 
is based on the STM32G4xx TIM LL API. The peripheral initialization uses 
LL initialization function to demonstrate LL Init.

The pulse is generated on OC1.

This example uses 2 timer instances:

  - TIM1 generates a positive pulse of 50 us after a delay of 50 us. User push-button
    is used to start TIM1 counter. 
                                              ___ 
                                             |   |
    User push-button ________________________|   |________________________________
                                                            ___________
                                                           |           |
    OC1              ______________________________________|           |________
    (TIM1_CH1)                                <---50 us---><---50 us--->
                                                |            |_ uwMeasuredPulseLength
                                                |_ uwMeasuredDelay

  TIM1_CH1 delay and pulse length are measured every time a pulse is generated. 
  Both can be observed through the debugger by monitoring the variables uwMeasuredDelay and
  uwMeasuredPulseLength respectively.

  - TIM2 generates a positive pulse of 3 s after a delay of 2 s. TIM2 counter start
    is controlled through the slave mode controller. TI2FP2 signals is selected as
    trigger input meaning that TIM2 counter starts when a rising edge is detected on
    TI2FP2.
    The TIM2 output channel is mapped on the pin PA.05 (connected to LED2 on board
    NUCLEO-G474RE RevC).
    Thus LED2 status (on/off) mirrors the timer output level (active v.s. inactive).
                                  ___
                                 |   |
    TI2 _________________________|   |_________________________________________
    (TIM2_CH2)
                                               ___________________________
                                              |                           |
    OC1 ______________________________________|                           |____
    (TIM2_CH1)                   <-----2s-----><----------3 s------------->
   


Both TIM1 and TIM2 are configured to generate a single pulse (timer counter 
stops automatically at the next update event (UEV).

Connecting TIM1 OC1 to TIM2 TI2 allows to trigger TIM2 counter by pressing
the User push-button.

@par Keywords

Timers, TIM, Output, signals, One Pulse, PWM, Oscilloscope, External signal, Autoreload, Waveform.

@par Directory contents 

  - TIM/TIM_OnePulse_Init/Inc/stm32g4xx_it.h          Interrupt handlers header file
  - TIM/TIM_OnePulse_Init/Inc/main.h                  Header for main.c module
  - TIM/TIM_OnePulse_Init/Inc/stm32_assert.h          Template file to include assert_failed function
  - TIM/TIM_OnePulse_Init/Src/stm32g4xx_it.c          Interrupt handlers
  - TIM/TIM_OnePulse_Init/Src/main.c                  Main program
  - TIM/TIM_OnePulse_Init/Src/system_stm32g4xx.c      STM32G4xx system source file


@par Hardware and Software environment

  - This example runs on STM32G474RETx devices.
    
  - This example has been tested with NUCLEO-G474RE RevC board and can be
    easily tailored to any other supported device and development board.

  - NUCLEO-G474RE RevC Set-up:
      - TIM1_CH1  PA.08: connected to pin 23 of CN10 connector  
      - TIM2_CH1  PA.05: connected to pin 11 of CN10 connector 
      - TIM2_CH2  PA.01: connected to pin 30 of CN7 connector 

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 */
