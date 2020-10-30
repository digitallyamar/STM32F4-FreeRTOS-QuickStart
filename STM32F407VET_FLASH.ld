/*****************************************************************************
*
 * STM32F407ET_FLASH.ld: Linker script for STM32F407VET6 based board aka 
 * "Blackboard" with 512KB of internal Flash & 192KB of RAM
 *
 ******************************************************************************
  * Copyright (C) 2020-2021
 *  
 * Author: DigitallyAmar (@digitallyamar)
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *
 ******************************************************************************
 *
 *  Memory Organization in STM32F407VET6 Chipset
 *
 ******************************************************************************
 * Internal SRAM organization:
 *  _________________________ <== Top Of Stack: _estack(0x20020000)
 * |                         |                    ||
 * |    Aux. SRAM2  (16KB)   |                    \/
 * |                         |
 * | (0x2001C000-0x2001FFFF) |
 * |_________________________|                    /\
 * |                         |                    ||
 * |    Main SRAM1  (112KB)  |                  .heap
 * |                         |                  .bss(zero filled uninitialized)
 * | (0x20000000-0x2001BFFF) |                  .data(init data, copied @RT)
 * |_________________________|<== Start Of RAM: .text(0x20000000)
 *
 *  _________________________ 
 * |                         |
 * |    Backup SRAM2 (4KB)   |
 * |_________________________|
 *
 * Internal CCM organization:
 *  _________________________
 * |                         |
 * |           CCM           |
 * |     Accessible only     |
 * |   through CPU (64KB)    |
 * |                         |
 * | (0x10000000-0x1000FFFF) |
 * |_________________________|
 *
 * Internal Flash memory organization:
 *  _________________________
 * |                         |
 * |   Main Memory Block:    |
 * |  - 4 sectors of 16KB    |
 * |  - 1 sector of 64KB     |
 * |  - 7 sectors of 128KB   |
 * |                         |
 * |         (1MB)           |
 * |                         |
 * | (0x08000000-0x080FFFFF) |
 * |_________________________|
 * |                         |
 * |   System Memory with    |
 * |  Bootloader (BootROM)   |
 * |                         |
 * |         (32KB)          |
 * |                         |
 * | (0x1FFF0000-0x1FFF7FFF) |
 * |_________________________|
 * |                         |
 * |      OTP User Area      |
 * |                         |
 * |      (512 Bytes)        |
 * |                         |
 * | (0x1FFF7800-0x1FFF7A0F) |
 * |_________________________|
 * |                         |
 * |     Option Bytes To     |
 * |    Lock The OTP block   |
 * |                         |
 * |       (16 Bytes)        |
 * |                         |
 * | (0x1FFFC000-0x1FFFC00F) |
 * |_________________________|
 * 
 * We will set the heap size, stack size and the stack location according 
 * to our application requirements.
 *
 * We will also set memory bank area and it's size if external memory is used.
 * On the Blackboard, we have an external W25Q16 SPI Flash chip with 2MB size.
 *
 *  ________________________
 * |                        |
 * | External SPI Flash:    |
 * | - W25Q16 chip          |
 * | - 2MB in size (or)     |
 * | - 16Mbits              |
 * |________________________|
 *
 ****************************************************************************/

/* Entry Point to our firware code */
ENTRY(Reset_Handler)

_estack = 0x20020000;          /* End of RAM (Top of stack - Grows down) */

MEMORY
{
  RAM (rwx)     : ORIGIN = 0x20000000, LENGTH = 128K
  CCMRAM (rw)   : ORIGIN = 0x10000000, LENGTH = 64K
  FLASH (rx)    : ORIGIN = 0x08000000, LENGTH = 1024K
}

SECTIONS
{
  /* Startup code at the beginning of the flash */
  .isr_vector :
  {
      . = ALIGN(4);
      KEEP(*(.isr_vector)) /* Startup code */
      . = ALIGN(4);
  } > FLASH

  /* The program code and other data goes into FLASH */
  .text :
  {
    . = ALIGN(4);
    *(.text)           /* .text sections (code) */
    *(.text*)          /* .text* sections (code) */
    *(.glue_7)         /* glue arm to thumb code */
    *(.glue_7t)        /* glue thumb to arm code */
    *(.eh_frame)

    KEEP (*(.init))
    KEEP (*(.fini))

    . = ALIGN(4);
    _etext = .;        /* define a global symbols at end of code */
  } >FLASH

  /* Constant data goes into FLASH */
  .rodata :
  {
    . = ALIGN(4);
    *(.rodata)         /* .rodata sections (constants, strings, etc.) */
    *(.rodata*)        /* .rodata* sections (constants, strings, etc.) */
    . = ALIGN(4);
  } >FLASH

  .ARM.extab   : { *(.ARM.extab* .gnu.linkonce.armextab.*) } >FLASH
  .ARM : {
    __exidx_start = .;
    *(.ARM.exidx*)
    __exidx_end = .;
  } >FLASH

  /* used by the startup to initialize data 
   * This will return the flash address.
   */
  _sidata = LOADADDR(.data);


  /* Initialized data sections goes into RAM, load LMA copy after code */
  .data : 
  {
    . = ALIGN(4);
    _sdata = .;        /* create a global symbol at data start */
    *(.data)           /* .data sections */
    *(.data*)          /* .data* sections */

    . = ALIGN(4);
    _edata = .;        /* define a global symbol at data end */

  } >RAM AT> FLASH    /* The '>RAM AT> FLASH' clause instructs the linker to
                      resolve the addresses as if they were in the 'RAM'
                      region, but actually write the startup contents to the 
                      'FLASH' region. They will then be copied to RAM at RT */
/* Uninitialized data section */
  . = ALIGN(4);
  .bss :
  {
    /* This is used by the startup in order to initialize the .bss secion */
    _sbss = .;         /* define a global symbol at bss start */
    __bss_start__ = _sbss;
    *(.bss)
    *(.bss*)
    *(COMMON)

    . = ALIGN(4);
    _ebss = .;         /* define a global symbol at bss end */
    __bss_end__ = _ebss;
  } >RAM

}