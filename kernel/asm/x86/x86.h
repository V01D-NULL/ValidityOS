/**
 * @file x86.h
 * @author Tim (V01D)
 * @brief Architecture specific code (this excludes gdt and interrupts)
 * @version 0.1
 * @date 2021-04-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef ASM_ARCH_X86_H
#define ASM_ARCH_X86_H

/*
    x86.h - Takes all the assembly functions and provides them in a single header file for ease-of-access
    
    - Assembly labels must be prefixed with ASM_<ARCHITECTURE>
*/

#include <libk/kstring.h>
#include "../../common.h"
#include "../../amd64/validity.h"

/// (x86_64) Return CPU vendor string
__export const char *ASM_x86_cpuid_vendor_string();

/// (x86_64) Read from the RIP register
__export int         ASM_x86_regs_read_rip();

//C functions:
/// (C) Print vendor string
void x86_cpuid_vendor_string(const char *a, const char *b, const char *c);

void x86_cpu_info();
#endif // ASM_ARCH_X86_H