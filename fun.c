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


/**
 * print_char - Function to print a single char to stdout
 * @h: va_list argument with value needed
 *
 * Return: Always 1 for success, exit -3 if fail
 */
int print_char(va_list h)
{
	int pci;

	pci = _putchar(va_arg(h, int));
	if (pci == -1)
		exit(-3);
	return (pci);
}

/**
 * print_str - Function to print a string to stdout
 * @h: va_list argument with value needed
 *
 * Return: Number of Characters printed to stdout
 */
int print_str(va_list h)
{
	int psi = 0;
	char *s;

	s = (va_arg(h, char *));
	if (s == NULL)
		s = "(null)";
	while (s[psi])
		_putchar(s[psi++]);
	return (psi);
}

/**
 * print_num - Prints an integar number
 * @n: Integar number to be printed
 *
 * Return: Number integer characters printed to stdout
 */
int print_num(long int n)
{
	long int num = n, count = 0;

	if (num < 0)
	{
		count += _putchar('-');
		num *= -1;
	}

	if (num / 10)
		count += print_num(num / 10);
	count += _putchar((num % 10) + '0');
	return (count);
}

/**
 * print_int - Function that Prints an integer to stdout
 * @h: va_list argument with value needed
 *
 * Return: Number of integer characters printed
 */
int print_int(va_list h)
{
	long int num = (long int)va_arg(h, int);
	int total;

	total = print_num(num);
	return (total);
}
