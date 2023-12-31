#include "main.h"

/**
 * _putchar - Function to print a single char to stdout
 * @c: Character to print
 *
 * Return: Always 1 for success. -1 if fail
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

