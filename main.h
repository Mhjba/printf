#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>




int _putchar(char c);
int print_char(va_list pa);
int print_string(va_list pa);
int print_percentage(va_list pa);
int _printf(const char *format, ...);
#define BUFF_SIZE 1024
#endif
