    /**
  @page CORTEXM_ModePrivilege Cortex-M4 Mode Privilege example

  @verbatim
  ******************************************************************************
  * @file    CORTEX/CORTEXM_ModePrivilege/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the Cortex-M4 Mode Privilege example.
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

How to modify the Thread mode privilege access and stack. Thread mode is entered
on reset or when returning from an exception.

The associated program is used to:

1. Switch the Thread mode stack from Main stack to Process stack

2. Switch the Thread mode from Privileged to Unprivileged

3. Switch the Thread mode from Unprivileged back to Privileged

To monitor the stack used and the privileged or unprivileged access level of code
in Thread mode, a set of variables is available within the program. It is also
possible to use the 'Cortex register' window of the debugger.

LED2 Turns ON when the test is finished successfully.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Keywords

System, Cortex, Mode Privilege, Privileged access, thread mode, main stack, process stack

@par Directory contents 

  - CORTEX/CORTEXM_ModePrivilege/Inc/stm32g4xx_nucleo_conf.h     BSP configuration file
  - CORTEX/CORTEXM_ModePrivilege/Inc/stm32g4xx_hal_conf.h    HAL configuration file
  - CORTEX/CORTEXM_ModePrivilege/Inc/stm32g4xx_it.h          Interrupt handlers header file
  - CORTEX/CORTEXM_ModePrivilege/Inc/main.h                  Header for main.c module
  - CORTEX/CORTEXM_ModePrivilege/Src/stm32g4xx_it.c          Interrupt handlers
  - CORTEX/CORTEXM_ModePrivilege/Src//stm32g4xx_hal_msp.c     HAL MSP file
  - CORTEX/CORTEXM_ModePrivilege/Src/main.c                  Main program
  - CORTEX/CORTEXM_ModePrivilege/Src/system_stm32g4xx.c      STM32G4xx system source file

@par Hardware and Software environment

  - This example runs on STM32G491RETx devices.
    
  - This example has been tested with NUCLEO-G491RE RevA board and can be
    easily tailored to any other supported device and development board.      

@par How to use it ? 
In order to make the program work, you must do the following :
- Open your preferred toolchain 
- Rebuild all files and load your image into target memory
- Run the example

 */
