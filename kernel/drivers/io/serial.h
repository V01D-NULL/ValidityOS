/**
 * @file serial.h
 * @author Tim (V01D)
 * @brief Reading and writing to the serial port
 * @version 0.1
 * @date 2021-04-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef SERIAL_H
#define SERIAL_H

#include <libk/kprintf.h>
#include <libk/kstring.h>
#include "../../common.h"
#include <stdint.h>

#define COM1 0x3F8
#define COM2 0x2F8
#define COM3 0x3E8
#define COM4 0x2E8

#define BASH_RED     "\e[31m"
#define BASH_CYAN    "\e[36m"
#define BASH_GREEN   "\e[32m"
#define BASH_WHITE   "\e[97m"
#define BASH_YELLOW  "\e[93m"
#define BASH_DEFAULT "\e[39m"

void serial_write(char chr);
char serial_read();
void serial_write_str(const char* str);
void serial_set_color(const char* color_code);

/// Output a formatted string to the serial port
int debug(char* fmt, ...);

#endif