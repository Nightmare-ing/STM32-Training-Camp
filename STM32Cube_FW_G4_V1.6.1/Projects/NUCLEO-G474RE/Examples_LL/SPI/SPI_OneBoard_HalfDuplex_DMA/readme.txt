/**
  @page SPI_OneBoard_HalfDuplex_DMA SPI example

  @verbatim
  ******************************************************************************
  * @file    Examples_LL/SPI/SPI_OneBoard_HalfDuplex_DMA/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the SPI_OneBoard_HalfDuplex_DMA example.
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

Configuration of GPIO and SPI peripherals to transmit
bytes from a SPI Master device to a SPI Slave device in DMA mode. This example
is based on the STM32G4xx SPI LL API. The peripheral initialization uses
LL unitary service functions for optimization purposes (performance and size).

This example works with only one NUCLEO-G474RE RevC.

SPI1 Peripheral is configured in Master mode Half-Duplex Tx.
SPI2 Peripheral is configured in Slave mode Half-Duplex Rx.
GPIO associated to User push-button is linked with EXTI.

Example execution:

LED2 is blinking Fast (200ms) and waits User push-button action.
Press User push-button on BOARD starts a Half-Duplex communication through DMA.
On MASTER side (SPI1), Clock will be generated on SCK line, Transmission done on MOSI Line.
On SLAVE side (SPI2) reception is done through the MISO Line.

LED2 is On if data is well received.

In case of errors, LED2 is blinking Slowly (1s).

@par Keywords

Connectivity, SPI, Half-duplex, DMA, Transmission, Reception, Master, Slave, MISO, MOSI.

@par Directory contents

  - SPI/SPI_OneBoard_HalfDuplex_DMA/Inc/stm32g4xx_it.h          Interrupt handlers header file
  - SPI/SPI_OneBoard_HalfDuplex_DMA/Inc/main.h                  Header for main.c module
  - SPI/SPI_OneBoard_HalfDuplex_DMA/Inc/stm32_assert.h          Template file to include assert_failed function
  - SPI/SPI_OneBoard_HalfDuplex_DMA/Src/stm32g4xx_it.c          Interrupt handlers
  - SPI/SPI_OneBoard_HalfDuplex_DMA/Src/main.c                  Main program
  - SPI/SPI_OneBoard_HalfDuplex_DMA/Src/system_stm32g4xx.c      STM32G4xx system source file

@par Hardware and Software environment

  - This example runs on STM32G4xx devices.

  - This example has been tested with NUCLEO-G474RE RevC board and can be
    easily tailored to any other supported device and development board.

  - NUCLEO-G474RE RevC Set-up
    - Connect Master SCK  PB3 to Slave SCK  PB13
    - Connect Master MOSI PB5 to Slave MISO PB14

Relation with Board connector:
  PB3  is connected to pin 31 of CN10 connector
  PB5  is connected to pin 29 of CN10 connector
  PB13 is connected to pin 30 of CN10 connector
  PB14 is connected to pin 28 of CN10 connector

@par How to use it ?

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 */
