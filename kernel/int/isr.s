[bits 64]

%include "asm/defs.inc"

[extern isr_handler]
;[extern irq_handler]

_asm_isr_handler_stub:
    cld
    pusha64
    
    call isr_handler   ; C interrupt handler routine
    popa64
    _cleanup_stack 16  ; Clean up pushed error code and interrupt number from stack
    iretq              ; Pop other flags and return to normal execution State

_asm_irq_handler_stub:
    pusha64
    ;call irq_handler
    popa64
    _cleanup_stack 16
    iretq

%macro isr 1
global isr%1
isr%1:
    push 0  ; Dummy error code
    push %1 ; Push interrupt number
    jmp _asm_isr_handler_stub
%endmacro

%macro isr_err 1
global isr_err%1
isr_err%1:
    ; Error code pushed by CPU
    push %1 ; Push interrupt number
    jmp _asm_isr_handler_stub
%endmacro

%macro irq 2
global irq%1
irq%1:
    cli
    push 0  ; Dummy error code
    push %2 ; Interrupt number
    jmp _asm_irq_handler_stub
%endmacro

global load_idt
load_idt:
    lidt [rdi]

    ; Reload cs and ds
    push 0x08
    push .reload
    retfq
    .reload:
       mov ax, 0x10
       mov ds, ax
       mov fs, ax
       mov gs, ax
       mov ss, ax
       mov es, ax
       sti
       ret


isr 0
isr 1
isr 2
isr 3
isr 4
isr 5
isr 6
isr 7
isr_err 8
isr 9
isr_err 10
isr_err 11
isr_err 12
isr_err 13
isr_err 14
isr 15
isr 16
isr 17
isr 18
isr 19
isr 20
isr 21
isr 22
isr 23
isr 24
isr 25
isr 26
isr 27
isr 28
isr 29
isr 30
isr 31

irq 0, 32
irq 1, 33
irq 2, 34
irq 3, 35
irq 4, 36
irq 5, 37
irq 6, 38
irq 7, 39
irq 8, 40
irq 9, 41
irq 10, 42
irq 11, 43
irq 12, 44
irq 13, 45
irq 14, 46
irq 15, 47

; Custom ISR's (user defined)
isr 80