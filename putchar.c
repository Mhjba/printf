#include "main.h"

/**
 * _putchar - writes chacacter(s)
 * to stdout one char at a time
 *
 * @c: current char
 *
 * Return: (1) success (-1) failure
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _putstr - print a string.
 * @str: pointer to the first character in the string.
 * Return: 1 Seccuess, -1 Failed.
*/

int _putstr(char *str)
{
	int i = -1;

	while (str[++i])
		_putchar(str[i]);
	return (i);
}
