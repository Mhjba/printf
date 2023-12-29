#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>




int _printf(const char *format, ...);
void handle_char(char c, size_t *count);
void print_null_or_str(char *s, size_t *count);
void print_integer(int num, size_t *count);

#endif
