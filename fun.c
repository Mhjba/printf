#include "main.h"
/**
 * _putchar - write the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * print_char - ...
 * @pa: pointer to argument
 * Return: int
 */

int print_char(va_list pa)
{
char x;

x = va_arg(pa, int);
_putchar(x);
return (1);
}

/**
 * print_string - ...
 * @pa: pointer to argument
 * Return: counter
 */

int print_string(va_list pa)
{
char *str;
int i = 0;

str = va_arg(pa, char *);

if (str == NULL)
str = "(null)";

while (str[i])
{
_putchar(str[i]);
i++;
}

return (i);
}

/**
 * print_percentage - ...
 * @pa: pointer to argument
 * Return: nothing
 */

int print_percentage(va_list pa)
{
(void) pa;
_putchar('%');
return (1);
}

