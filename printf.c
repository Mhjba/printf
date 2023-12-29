#include "main.h"

/**
 * _printf - work as printf function
 * @format: pointer to argument
 * @...: ...
 * Return: (int)
 */

int _printf(const char *format, ...)
{
va_list pa;
int i = 0, count = 0;

va_start(pa, format);


if (format == NULL)
return (-1);

while (format[i])
{
if (format[i] != '%')
{
_putchar(format[i]);
count++;
}
else
{
switch (format[i + 1])
{
case 'c':
count += print_char(pa);
break;
case 's':
count += print_string(pa);
break;
case '%':
count += print_percentage(pa);
break;
default:
return (-1);
}
i++;
}
i++;
}

va_end(pa);
return (count);
}
