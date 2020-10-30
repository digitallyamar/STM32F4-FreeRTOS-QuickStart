/*****************************************************************************
 * startup.s: Basic startup code to get the STM32 get going & to prepare the 
 * runtime environment to be able to run C programs.
 *****************************************************************************
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
 *****************************************************************************/

    .syntax unified                 // Sets the instrn. set syntax for ARM
                                    // Divided - Old style, where thumb & arm 
                                    // instrns. had seperate syntaxes.
                                    // Unified - New style
    
    .cpu cortex-m4                  // Selects the target processor
    
    .fpu softvfp                    // Selects the fp unit to assemble for
    
    .thumb                          // Selects the intrn. set to be generated

.global g_IVT                       // Global ptr. to Interrupt Vector Table


.word   _sidata                     // Start address for initialized .data
                                    // This is the Flash memory address. 
                                    // Check Linker script for details.

.word   _sdata                      // Start address for .data
                                    // This is the RAM address to where the
                                    // data is expected to be copied.

.word   _edata                      // End address for .data

.word   _sbss                       // Start address for .bss section

.word   _ebss                       // End address for .bss section


/*****************************************************************************
 * Entry Point to our firware code from reset. 
 ****************************************************************************/
    .section .text.Reset_Handler
    .weak Reset_Handler
    .type Reset_Handler, %function

Reset_Handler:
    ldr sp, =_estack                //Set the stack pointer to top of stack

    /* Create zeroed uninitialized data segment ().data) */
    mov r1, #0
    b LoopCopyDataInit


CopyDataInit:
    // Copy data from _sidata (in flash) to _sdata (to RAM)
    ldr r3, =_sidata            // 0x08XXXXXX
    ldr r3, [r3, r1]            // r3 = [r3 + r1]
    str r3, [r0, r1]            // Copy from _sidata to _sdata
    add r1, r1, #4

LoopCopyDataInit:
    ldr r0, =_sdata             // 0x20000000
    ldr r3, =_edata             // 0x2XXXXXXX
    adds r2, r0, r1
    cmp r2, r3                  // Check if end of .data
    bcc CopyDataInit
    ldr r2, =_sbss
    b LoopFillZerobss

FillZerobss:
    movs r3, #0
    str r3, [r2], #4            // Post index - r3 = [r2], r2+=4

LoopFillZerobss:
    ldr r3, = _ebss
    cmp r2, r3
    bcc FillZerobss

    bl main
    bx lr
.size  Reset_Handler, .-Reset_Handler


/*****************************************************************************
 * Vector Table - This is what gets stored in memory at the reset address.
 * 
 * Here, "a" means "allocation only" of space
 *
 * progbits is a designation within the ELF file of a section that actual 
 * contains data/code of the application, and not debug, comments or other 
 * extraneous content.
 *
 *****************************************************************************/
    .section .isr_vector, "a", %progbits
    .type g_IVT, %object
    .size g_IVT, .-g_IVT

g_IVT:
    .word   _estack
    .word   Reset_Handler