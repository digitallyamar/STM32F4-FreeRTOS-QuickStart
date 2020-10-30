##########################################################################################################################
# Top level Makefile based on GCC for FreeRTOS build on STM32F4 based board.
# Copyright (C) 2020-2021
#  
# Author: DigitallyAmar (@digitallyamar)
#
# This program is free software; you can redistribute it and/or modify it
# under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation; either version 2.1 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program; if not, write to the Free Software Foundation,
# Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.

# ------------------------------------------------
# Generic Makefile (based on gcc)
#
# ChangeLog :
#   2020-10-28 - first version
# ------------------------------------------------
##########################################################################################################################

######################################
# target
######################################
TARGET = STM32_FreeRTOS

######################################
# building variables
######################################
# Select debug or retail build
DEBUG = 1

# optimization
OPT = -Og

#######################################
# paths
#######################################
# source path
SOURCES_DIR =  \
FreeRTOS/Source

# Build path
BUILD_DIR = build

######################################
# source
######################################
# C sources
C_SOURCES =  \
src/main.c \
src/rcc.c \
src/gpio.c \
src/stm32f4_init.c \
FreeRTOS/Source/tasks.c \
FreeRTOS/Source/list.c \
FreeRTOS/Source/queue.c \
FreeRTOS/Source/timers.c \
FreeRTOS/Source/portable/GCC/ARM_CM4F/port.c \
FreeRTOS/Source/portable/MemMang/heap_1.c

# ASM sources
ASM_SOURCES =  \
src/startup.s

#######################################
# binaries
#######################################
BINPATH = ~/tools/gcc-arm-none-eabi-6-2017-q2-update/bin

PREFIX = arm-none-eabi-
AS = $(BINPATH)/$(PREFIX)gcc -x assembler-with-cpp
CC = $(BINPATH)/$(PREFIX)gcc
CP = $(BINPATH)/$(PREFIX)objcopy
AR = $(BINPATH)/$(PREFIX)ar
SZ = $(BINPATH)/$(PREFIX)size
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S

#######################################
# CFLAGS
#######################################
# cpu
CPU = -mcpu=cortex-m4

# fpu
FPU = -mfpu=fpv4-sp-d16

# float-abi
FLOAT-ABI = -mfloat-abi=hard

# mcu
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

# macros for gcc
# AS defines
AS_DEFS = 

# C defines
C_DEFS =

# AS includes
AS_INCLUDES =

# C includes
C_INCLUDES = \
-Isrc/include \
-IFreeRTOS/Source/include \
-IFreeRTOS/Source/portable/GCC/ARM_CM4F


# compile gcc flags
ASFLAGS = $(MCU) $(AS_DEFS) $(AS_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

CFLAGS = $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif


# Generate dependency information
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"


#######################################
# LDFLAGS
#######################################
# link script
LDSCRIPT = STM32F407VET_FLASH.ld


# libraries
LIBS = -lc -lm -lnosys 
LIBDIR = 
LDFLAGS = $(MCU) -specs=nano.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections


# default action: build all
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin


#######################################
# build the application
#######################################
# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
# list of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))


$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR)
	$(info ************  Building C Files ************)
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	$(info ************  Building AS Files ************)
	$(AS) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(info ************  Link objects & build ELF Files ************)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(info ************  Calling SZ ************)
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(HEX) $< $@
	
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@	
	
$(BUILD_DIR):
	mkdir $@

#######################################
# clean up
#######################################
clean:
	rm -rf .dep $(BUILD_DIR)