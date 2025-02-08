set(MCU_FAMILY STM32G4xx)
set(MCU_MODEL STM32G474xx)
set(CPU_PARAMETERS
        -mcpu=cortex-m4
        -mthumb
        -mfpu=fpv4-sp-d16
        -mfloat-abi=hard)

set(START_SCRIPT ../CubeMX/startup_stm32g474xx.s)
set(MCU_LINKER_SCRIPT ../CubeMX/stm32g474vetx_flash.ld)
