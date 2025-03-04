/**
  @page ADC_SingleConversion_TriggerSW_IT_Init ADC example
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/ADC/ADC_SingleConversion_TriggerSW_IT_Init/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the ADC_SingleConversion_TriggerSW_IT_Init example.
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

How to use an ADC peripheral to perform a single ADC conversion on a channel, 
at each software start. This example uses the interrupt programming model 
(for polling or DMA programming models, please refer to other examples).
This example is based on the STM32G4xx ADC LL API.
The peripheral initialization is done using LL unitary service functions 
for optimization purposes (performance and size).

Example configuration:
ADC is configured to convert a single channel, in single conversion mode,
from SW trigger.
ADC interruption enabled: EOC (end of conversion of ADC group regular).

Example execution:
At each press on User push-button, the ADC performs 1 conversion of the selected channel.
When conversion is completed, ADC interruption occurs.
IRQ handler callback function reads conversion data from ADC data register
and stores it into a variable, LED2 is turned on.

For debug: variables to monitor with debugger watch window:
 - "uhADCxConvertedData": ADC group regular conversion data
 - "uhADCxConvertedData_Voltage_mVolt": ADC conversion data computation to physical values

LED2 is blinking every 1 sec in case of error. 
 
Connection needed:
None.
Note: Optionally, a voltage can be supplied to the analog input pin (cf pin below),
      between 0V and Vdda=3.3V, to perform a ADC conversion on a determined
      voltage level.
      Otherwise, this pin can be let floating (in this case ADC conversion data
      will be undetermined).

Other peripherals used:
  1 GPIO for User push-button
  1 GPIO for LED2
  1 GPIO for analog input: PA.00 (Arduino connector CN8 pin A0, Morpho connector CN7 pin 28)
@par Keywords

ADC, ADC channel, conversion, single channel, single conversion mode, interrupt,

@par Directory contents 

  - ADC/ADC_SingleConversion_TriggerSW_IT_Init/Inc/stm32g4xx_it.h          Interrupt handlers header file
  - ADC/ADC_SingleConversion_TriggerSW_IT_Init/Inc/main.h                  Header for main.c module
  - ADC/ADC_SingleConversion_TriggerSW_IT_Init/Inc/stm32_assert.h          Template file to include assert_failed function
  - ADC/ADC_SingleConversion_TriggerSW_IT_Init/Src/stm32g4xx_it.c          Interrupt handlers
  - ADC/ADC_SingleConversion_TriggerSW_IT_Init/Src/main.c                  Main program
  - ADC/ADC_SingleConversion_TriggerSW_IT_Init/Src/system_stm32g4xx.c      STM32G4xx system source file


@par Hardware and Software environment

  - This example runs on STM32G474RETx devices.
    
  - This example has been tested with NUCLEO-G474RE RevC board and can be
    easily tailored to any other supported device and development board.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 */
