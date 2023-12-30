#include "main.h"

/**
 * print_hexa - Function that prints unsigned int in hexadecimal(base(16))
 * to stdout
 * @h: va_list argument with value needed
 *
 * Return: Number of hexadecimal characters printed to stdout
 */
int print_hexa(va_list h)
{
	unsigned int num = va_arg(h, unsigned int);
	int total;

	total = print_hexa_num(num);
	return (total);
}

/**
 * print_hexa_num - Converts decimal to hexadecimal and prints to stdout
 * @n: Decimal number
 *
 * Return: Number of characters printed
 */
int print_hexa_num(unsigned int n)
{
	int total = 0, hex[12], i = 0;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	while (n > 0)
	{
		hex[i] = n % 16;
		if (hex[i] < 10)
			hex[i] += '0';
		else
			hex[i] += ('a' - 10);
		n /= 16;
		i++;
	}
	for (--i; i >= 0; i--)
		total += _putchar(hex[i]);
	return (total);
}

/**
 * print_rot13 - Encodes a string using rot13 and prints to stdout
 * @h: va_list argument with value needed
 *
 * Return: Number of characters printed
 */
int print_rot13(va_list h)
{
	char *ptr = va_arg(h, char *);
	char alp[52] = {
	'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E',
	'f', 'F', 'g', 'G', 'h', 'H', 'i', 'I', 'j', 'J',
	'k', 'K', 'l', 'L', 'm', 'M', 'n', 'N', 'o', 'O',
	'p', 'P', 'q', 'Q', 'r', 'R', 's', 'S', 't', 'T',
	'u', 'U', 'v', 'V', 'w', 'W', 'x', 'X', 'y', 'Y',
	'z', 'Z',};
	char rot[52] = {
	'n', 'N', 'o', 'O', 'p', 'P', 'q', 'Q', 'r', 'R',
	's', 'S', 't', 'T', 'u', 'U', 'v', 'V', 'w', 'W',
	'x', 'X', 'y', 'Y', 'z', 'Z', 'a', 'A', 'b', 'B',
	'c', 'C', 'd', 'D', 'e', 'E', 'f', 'F', 'g', 'G',
	'h', 'H', 'i', 'I', 'j', 'J', 'k', 'K', 'l', 'L',
	'm', 'M',};
	int i, counter = 0;

	while (*ptr != '\0')
	{
		for (i = 0; i < 52; i++)
		{
			if (*ptr == alp[i])
			{
				counter += _putchar(rot[i]);
				break;
			}
			else if (i == 51)
				counter += _putchar(*ptr);
		}
		ptr++;
	}
	return (counter);
}
