/**
 * @file cpu.h
 * @author Tim (V01D)
 * @brief Manages anything directly CPU related
 * @version 0.1
 * @date 2021-04-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef CPU_H
#define CPU_H

/*
    While the folder may say amd64/ this OS is fine when working with Intel CPU's aswell.
    I just refer to the AMD manual rather than the Intel manual and a cpu/ folder that doesn't hold gdt/idt seemed kinda lame so I went the AMD/
*/

#include <stdint.h>
#include "../asm/x86/x86.h"
#include "../boot/bootloader_stivale2.h"

struct cpuid_regs_t
{
    int eax;
    int ebx;
    int ecx;
    int edx;
    int function;
};


void cpuid(struct cpuid_regs_t *cpuid_regs);

void cpu_info();

/**
 * @brief CPU information
 * 
 */
typedef struct cpu_hw {
    uint64_t cpu_count;
    uint32_t bsp_lapic_id; //Bootstrap Processor lapic id
    char     *vendor_string;
} cpu_hw_t;

/**
 * @brief A list of registers preserved by the interupt stack frame
 * 
 */
typedef struct regs {
    int64_t r15;
    int64_t r14;
    int64_t r13;
    int64_t r12;
    int64_t r11;
    int64_t r10;
    int64_t r9;
    int64_t r8;
    int64_t rsi;
    int64_t rdi;
    int64_t rbp;
    int64_t rdx;
    int64_t rcx;
    int64_t rbx;
    int64_t rax;
    int64_t isr_number;
    int64_t error_code;
    int64_t rip;
    int64_t cs; 
    int64_t rflags; 
    int64_t rsp;
    int64_t ss;
} regs_t;

/**
 * @brief Gather CPU information from various sources & combine them into a single struct
 * 
 * @param[in] cpu_info Bootloader cpu information
 */
void cpu_info_init(boot_info_t cpu_info);

#endif // CPU_H