# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# compile ASM with /home/rafael/Desktop/Core/core/gcc-arm-none-eabi/bin/arm-none-eabi-gcc
# compile C with /home/rafael/Desktop/Core/core/gcc-arm-none-eabi/bin/arm-none-eabi-gcc
# compile CXX with /home/rafael/Desktop/Core/core/gcc-arm-none-eabi/bin/arm-none-eabi-g++
ASM_FLAGS = -mthumb -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -x assembler-with-cpp -ggdb  

ASM_DEFINES = -DCHPRINTF_USE_FLOAT=TRUE -DCORE_ITERATE_PUBSUB=1 -DCORE_MODULE_NAME=\"proximity\" -DCORE_USE_BOOTLOADER=0 -DCORE_USE_BRIDGE_MODE=0 -DCORTEX_USE_FPU=TRUE -DSTM32F3 -DSTM32F303xx -DUSE_CORE_ASSERT -DUSE_RTCANTRANSPORT

ASM_INCLUDES = -I/home/rafael/Desktop/Robocom-firmware/src/targets/proximity -I/home/rafael/Desktop/Core/core/core-base/include -I/home/rafael/Desktop/Core/core/core-base/port/chibios/include -I/home/rafael/Desktop/Core/core/core-os/include -I/home/rafael/Desktop/Core/core/core-os/port/chibios/include -I/home/rafael/Desktop/Core/core/core-mw/include -I/home/rafael/Desktop/Core/core/core-mw/port/chibios/include -I/home/rafael/Desktop/Core/core/core-transport-rtcan/include -I/home/rafael/Desktop/Core/core/core-hw/include -I/home/rafael/Desktop/Core/core/core-hw/port/chibios/include -I/home/rafael/Desktop/Core/core/core-utils/include -I/home/rafael/Desktop/Core/core/core-comm-can/include -I/home/rafael/Desktop/Core/core/core-comm-can/platforms/STM32 -I/home/rafael/Desktop/Robocom-firmware/generated/packages/led/include -I/home/rafael/Desktop/Robocom-firmware/generated/packages/common_msgs/include -I/home/rafael/Desktop/Core/core/chibios_3/os/rt/include -I/home/rafael/Desktop/Core/core/chibios_3/os/rt/ports/ARMCMx -I/home/rafael/Desktop/Core/core/chibios_3/os/rt/ports/ARMCMx/compilers/GCC -I/home/rafael/Desktop/Core/core/chibios_3/os/ext/CMSIS/include -I/home/rafael/Desktop/Core/core/chibios_3/os/ext/CMSIS/ST -I/home/rafael/Desktop/Core/core/chibios_3/os/common/ports/ARMCMx/devices/STM32F3xx -I/home/rafael/Desktop/Core/core/chibios_3/os/hal/include -I/home/rafael/Desktop/Core/core/chibios_3/os/hal/osal/rt -I/home/rafael/Desktop/Core/core/chibios_3/os/hal/ports/STM32/STM32F3xx -I/home/rafael/Desktop/Core/core/chibios_3/os/hal/ports/common/ARMCMx -I/home/rafael/Desktop/Core/core/chibios_3/os/hal/ports/STM32/LLD -I/home/rafael/Desktop/Core/core/chibios_3/os/hal/ports/STM32/LLD/TIMv1 -I/home/rafael/Desktop/Core/core/chibios_3/os/hal/ports/STM32/LLD/GPIOv2 -I/home/rafael/Desktop/Robocom-firmware/generated/modules/proximity/include -I/home/rafael/Desktop/Robocom-firmware/generated/modules/proximity/include/proximity 

C_FLAGS = -mthumb -fno-builtin -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -Wall -std=gnu99 -fno-common -ffunction-sections -fdata-sections -fomit-frame-pointer -mabi=aapcs -fno-unroll-loops -ffast-math -ftree-vectorize -Og -ggdb  

C_DEFINES = -DCHPRINTF_USE_FLOAT=TRUE -DCORE_ITERATE_PUBSUB=1 -DCORE_MODULE_NAME=\"proximity\" -DCORE_USE_BOOTLOADER=0 -DCORE_USE_BRIDGE_MODE=0 -DCORTEX_USE_FPU=TRUE -DSTM32F3 -DSTM32F303xx -DUSE_CORE_ASSERT -DUSE_RTCANTRANSPORT

C_INCLUDES = -I/home/rafael/Desktop/Robocom-firmware/src/targets/proximity -I/home/rafael/Desktop/Core/core/core-base/include -I/home/rafael/Desktop/Core/core/core-base/port/chibios/include -I/home/rafael/Desktop/Core/core/core-os/include -I/home/rafael/Desktop/Core/core/core-os/port/chibios/include -I/home/rafael/Desktop/Core/core/core-mw/include -I/home/rafael/Desktop/Core/core/core-mw/port/chibios/include -I/home/rafael/Desktop/Core/core/core-transport-rtcan/include -I/home/rafael/Desktop/Core/core/core-hw/include -I/home/rafael/Desktop/Core/core/core-hw/port/chibios/include -I/home/rafael/Desktop/Core/core/core-utils/include -I/home/rafael/Desktop/Core/core/core-comm-can/include -I/home/rafael/Desktop/Core/core/core-comm-can/platforms/STM32 -I/home/rafael/Desktop/Robocom-firmware/generated/packages/led/include -I/home/rafael/Desktop/Robocom-firmware/generated/packages/common_msgs/include -I/home/rafael/Desktop/Core/core/chibios_3/os/rt/include -I/home/rafael/Desktop/Core/core/chibios_3/os/rt/ports/ARMCMx -I/home/rafael/Desktop/Core/core/chibios_3/os/rt/ports/ARMCMx/compilers/GCC -I/home/rafael/Desktop/Core/core/chibios_3/os/ext/CMSIS/include -I/home/rafael/Desktop/Core/core/chibios_3/os/ext/CMSIS/ST -I/home/rafael/Desktop/Core/core/chibios_3/os/common/ports/ARMCMx/devices/STM32F3xx -I/home/rafael/Desktop/Core/core/chibios_3/os/hal/include -I/home/rafael/Desktop/Core/core/chibios_3/os/hal/osal/rt -I/home/rafael/Desktop/Core/core/chibios_3/os/hal/ports/STM32/STM32F3xx -I/home/rafael/Desktop/Core/core/chibios_3/os/hal/ports/common/ARMCMx -I/home/rafael/Desktop/Core/core/chibios_3/os/hal/ports/STM32/LLD -I/home/rafael/Desktop/Core/core/chibios_3/os/hal/ports/STM32/LLD/TIMv1 -I/home/rafael/Desktop/Core/core/chibios_3/os/hal/ports/STM32/LLD/GPIOv2 -I/home/rafael/Desktop/Robocom-firmware/generated/modules/proximity/include -I/home/rafael/Desktop/Robocom-firmware/generated/modules/proximity/include/proximity 

CXX_FLAGS = -mthumb -fno-builtin -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -Wall -std=c++11 -fno-exceptions -fno-common -ffunction-sections -fdata-sections -fomit-frame-pointer -mabi=aapcs -fno-unroll-loops -ffast-math -ftree-vectorize -fno-rtti -std=c++11 -Og -ggdb  

CXX_DEFINES = -DCHPRINTF_USE_FLOAT=TRUE -DCORE_ITERATE_PUBSUB=1 -DCORE_MODULE_NAME=\"proximity\" -DCORE_USE_BOOTLOADER=0 -DCORE_USE_BRIDGE_MODE=0 -DCORTEX_USE_FPU=TRUE -DSTM32F3 -DSTM32F303xx -DUSE_CORE_ASSERT -DUSE_RTCANTRANSPORT

CXX_INCLUDES = -I/home/rafael/Desktop/Robocom-firmware/src/targets/proximity -I/home/rafael/Desktop/Core/core/core-base/include -I/home/rafael/Desktop/Core/core/core-base/port/chibios/include -I/home/rafael/Desktop/Core/core/core-os/include -I/home/rafael/Desktop/Core/core/core-os/port/chibios/include -I/home/rafael/Desktop/Core/core/core-mw/include -I/home/rafael/Desktop/Core/core/core-mw/port/chibios/include -I/home/rafael/Desktop/Core/core/core-transport-rtcan/include -I/home/rafael/Desktop/Core/core/core-hw/include -I/home/rafael/Desktop/Core/core/core-hw/port/chibios/include -I/home/rafael/Desktop/Core/core/core-utils/include -I/home/rafael/Desktop/Core/core/core-comm-can/include -I/home/rafael/Desktop/Core/core/core-comm-can/platforms/STM32 -I/home/rafael/Desktop/Robocom-firmware/generated/packages/led/include -I/home/rafael/Desktop/Robocom-firmware/generated/packages/common_msgs/include -I/home/rafael/Desktop/Core/core/chibios_3/os/rt/include -I/home/rafael/Desktop/Core/core/chibios_3/os/rt/ports/ARMCMx -I/home/rafael/Desktop/Core/core/chibios_3/os/rt/ports/ARMCMx/compilers/GCC -I/home/rafael/Desktop/Core/core/chibios_3/os/ext/CMSIS/include -I/home/rafael/Desktop/Core/core/chibios_3/os/ext/CMSIS/ST -I/home/rafael/Desktop/Core/core/chibios_3/os/common/ports/ARMCMx/devices/STM32F3xx -I/home/rafael/Desktop/Core/core/chibios_3/os/hal/include -I/home/rafael/Desktop/Core/core/chibios_3/os/hal/osal/rt -I/home/rafael/Desktop/Core/core/chibios_3/os/hal/ports/STM32/STM32F3xx -I/home/rafael/Desktop/Core/core/chibios_3/os/hal/ports/common/ARMCMx -I/home/rafael/Desktop/Core/core/chibios_3/os/hal/ports/STM32/LLD -I/home/rafael/Desktop/Core/core/chibios_3/os/hal/ports/STM32/LLD/TIMv1 -I/home/rafael/Desktop/Core/core/chibios_3/os/hal/ports/STM32/LLD/GPIOv2 -I/home/rafael/Desktop/Robocom-firmware/generated/modules/proximity/include -I/home/rafael/Desktop/Robocom-firmware/generated/modules/proximity/include/proximity 

