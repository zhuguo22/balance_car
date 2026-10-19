cmake_minimum_required(VERSION 3.22)

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME balance_car)

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME}
        APP/Inc/maintask.h
        APP/Src/maintask.c
        BSP/HC-SR04/Src/sr04.c
        BSP/HC-SR04/Inc/sr04.h
        BSP/Delay/Src/usDelay.c
        BSP/Delay/Inc/usDelay.h
        BSP/Motor_520/Src/motor.c
        BSP/Motor_520/Inc/motor.h
        BSP/Encoder/Src/encoder.c
        BSP/Encoder/Inc/encoder.h
        BSP/Encoder/Src/encoder.c)

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined library search paths
)

file(GLOB_RECURSE USER_SOURCES
        BSP/OLED/Src/*.c
        BSP/MPU6050/Src/*.c
        APP/Src/*.c
        BSP/HC-SR04/Src/*.c
        BSP/Delay/Src/*.c
        BSP/Motor_520/Src/*.c
        BSP/Encoder/Src/*.c
)


# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user sources here
        ${USER_SOURCES}
)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined include paths
        BSP/OLED/Inc
        BSP/MPU6050/Inc
        APP/Inc
        BSP/HC-SR04/Inc
        BSP/Delay/Inc
        BSP/Motor_520/Inc
        BSP/Encoder/Inc
 )

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
)

# Remove wrong libob.a library dependency when using cpp files
list(REMOVE_ITEM CMAKE_C_IMPLICIT_LINK_LIBRARIES ob)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx

    # Add user defined libraries
)
