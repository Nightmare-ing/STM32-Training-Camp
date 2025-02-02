cmake_minimum_required(VERSION 3.29.6)

include(../cmake/gcc-arm-none-eabi.cmake)
include(cmake/mcu.cmake)

project(Lab0)
set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(EXECUTABLE ${CMAKE_PROJECT_NAME})
enable_language(C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# Headers
set(CUBEMX_INCLUDE_DIR
        ${CMAKE_CURRENT_SOURCE_DIR}/Core/Inc
        ${CMAKE_CURRENT_SOURCE_DIR}/../STM32Cube_FW_G4_V1.6.1/Drivers/STM32G4xx_HAL_Driver/Inc
        ${CMAKE_CURRENT_SOURCE_DIR}/../STM32Cube_FW_G4_V1.6.1/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy
        ${CMAKE_CURRENT_SOURCE_DIR}/../STM32Cube_FW_G4_V1.6.1/Drivers/CMSIS/Device/ST/STM32G4xx/Include
        ${CMAKE_CURRENT_SOURCE_DIR}/../STM32Cube_FW_G4_V1.6.1/Drivers/CMSIS/Include)
set(PROJECT_INCLUDE_DIR
        ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_DIR})

# Sources
set(STM32CUBEMX_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/main.c
        ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/stm32g4xx_it.c
        ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/stm32g4xx_hal_msp.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../STM32Cube_FW_G4_V1.6.1/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_pwr_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../STM32Cube_FW_G4_V1.6.1/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../STM32Cube_FW_G4_V1.6.1/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_rcc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../STM32Cube_FW_G4_V1.6.1/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_rcc_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../STM32Cube_FW_G4_V1.6.1/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_flash.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../STM32Cube_FW_G4_V1.6.1/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_flash_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../STM32Cube_FW_G4_V1.6.1/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_flash_ramfunc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../STM32Cube_FW_G4_V1.6.1/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_gpio.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../STM32Cube_FW_G4_V1.6.1/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_exti.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../STM32Cube_FW_G4_V1.6.1/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_dma.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../STM32Cube_FW_G4_V1.6.1/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_dma_ex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../STM32Cube_FW_G4_V1.6.1/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_pwr.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../STM32Cube_FW_G4_V1.6.1/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_cortex.c
        ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/system_stm32g4xx.c
        ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/sysmem.c
        ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/syscalls.c)

# Executable files
add_executable(${EXECUTABLE}
        ${STM32CUBEMX_SOURCES}
        ${PROJECT_SOURCES}
        ${START_SCRIPT})

# Embedded macros(defines)
target_compile_definitions(${EXECUTABLE} PRIVATE
        ${MCU_MODEL}
        USE_HAL_DRIVER)

# Add header directories (AFTER add_executable!!)
target_include_directories(${EXECUTABLE} PRIVATE
        ${CUBEMX_INCLUDE_DIR}
        ${PROJECT_INCLUDE_DIR})

# Compiler and linker options
target_compile_options(${EXECUTABLE} PRIVATE
        ${CPU_PARAMETERS}
        -Wall
        -Wextra
        -Wno-unused-parameter
        $<$<COMPILE_LANGUAGE:CXX>:
            -Wno-volatle
            -Wold-style-cast
            -Wuseless-cast
            -Wsuggest-override>
        $<$<CONFIG:Debug>: -Og -g3 -ggdb>
        $<$<CONFIG:Release>: -Og -g0>)

target_link_options(${EXECUTABLE} PRIVATE
        -T${MCU_LINKER_SCRIPT}
        ${CPU_PARAMETERS}
        -Wl,-Map=${EXECUTABLE}.map
        --specs=nosys.specs
        -Wl,--start-group
        -lc
        -lm
        -lstdc++
        -Wl,--end-group
        -Wl,--print-memory-usage)

# Post build commands
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
        COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${EXECUTABLE}>)

add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${EXECUTABLE}> ${EXECUTABLE}.hex
        COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${EXECUTABLE}> ${EXECUTABLE}.bin)
