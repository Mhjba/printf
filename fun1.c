#include "main.h"

/**
 * print_bin - Function that converts an integer and prints it to stdout
 * in binary
 * @h: va_list argument with value needed
 *
 * Return: The number of character interger in binary printed to stdout
 */
int print_bin(va_list h)
{
	unsigned int num = va_arg(h, unsigned int);
	int bin[32], total = 0, i = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	while (num > 0)
	{
		bin[i] = (num % 2);
		num /= 2;
		i++;
	}
	for (--i; i >= 0; i--)
		total += _putchar(bin[i] + '0');
	return (total);
}


/**
 * print_octal - Function that prints unsigned int in octal(base(8)) to stdout
 * @h: va_list argument with value needed
 *
 * Return: Number of octal characters printed to stdout
 */
int print_octal(va_list h)
{
	unsigned int num = va_arg(h, unsigned int);
	int total;

	total = print_octal_num(num);
	return (total);
}

/**
 * print_octal_num - Converts decimal number to octal and prints to stdout
 * @n: Decimal number
 *
 * Return: NUmber of characters printed to stdout
 */
int print_octal_num(unsigned int n)
{
	int total = 0, oct[32], i = 0;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	while (n > 0)
	{
		oct[i] = n % 8;
		n /= 8;
		i++;
	}
	for (--i; i >= 0; i--)
		total += _putchar(oct[i] + '0');
	return (total);
}

/**
 * print_heXa - Function that prints unsigned int in hexadecimal(base(16))
 * to stdout
 * @h: va_list argument with value needed
 *
 * Return: Number of hexadecimal characters printed to stdout
 */
int print_heXa(va_list h)
{
	unsigned int num = va_arg(h, unsigned int);
	int total;

	total = print_heXa_num(num);
	return (total);
}

/**
 * print_heXa_num - Converts decimal to heXadecimal and prints to stdout
 * @n: Decimal number
 *
 * Return: Number of chracters printed to stdout
 */
int print_heXa_num(unsigned int n)
{
	int total = 0, heX[12], i = 0;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	while (n > 0)
	{
		heX[i] = n % 16;
		if (heX[i] < 10)
			heX[i] += '0';
		else
			heX[i] += ('A' - 10);
		n /= 16;
		i++;
	}
	for (--i; i >= 0; i--)
		total += _putchar(heX[i]);
	return (total);
}
