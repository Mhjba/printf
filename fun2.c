#include "main.h"

/**
 * print_p - Function that prints value of a (void *) in hexadecimal(base(16))
 * to stdout
 * @h: va_list argument with value needed
 *
 * Return: Number of hexadecimal characters printed to stdout
 */
int print_p(va_list h)
{
	unsigned long int num = (unsigned long int)va_arg(h, void *);
	int total = 0, hex[32], i = 0;

	if (num == 0)
	{
		total += _putchar('(');
		total += _putchar('n');
		total += _putchar('i');
		total += _putchar('l');
		total += _putchar(')');
			return (total);
	}
	total += _putchar('0');
	total += _putchar('x');
	while (num > 0)
	{
		hex[i] = num % 16;
		if (hex[i] < 10)
			hex[i] += '0';
		else
			hex[i] += ('a' - 10);
		num /= 16;
		i++;
	}
	for (--i; i >= 0; i--)
		total += _putchar(hex[i]);
	return (total);
}

/**
 * print_S - Function to print a string to stdout
 * Description: Non printable characters (0 < ASCII value < 32 or >= 127) are
 * printed this way: \x, followed by the ASCII code value in hexadecimal (upper
 * case - always 2 characters)
 * @h: va_list argument with value needed
 *
 * Return: Number of Characters printed to stdout
 */
int print_S(va_list h)
{
	int pSi = 0, counter = 0;
	char *S;

	S = (va_arg(h, char *));
	if (S == NULL)
		S = "(null)";
	while (S[pSi])
	{
		if ((S[pSi] > 0 && S[pSi] < 32) || S[pSi] >= 127)
		{
			counter += _putchar('\\');
			counter += _putchar('x');
			if (S[pSi] < 16)
			{
				counter += _putchar('0');
				if (S[pSi] < 10)
					counter += _putchar(S[pSi++] + '0');
				else
					counter += _putchar(S[pSi++] + 55);
			}
			else
			{
				if ((S[pSi] / 16) < 10)
					counter += _putchar((S[pSi] / 16) + '0');
				else if ((S[pSi] / 16) >= 10)
					counter += _putchar((S[pSi] / 16) + 55);
				if ((S[pSi] % 16) < 10)
					counter += _putchar((S[pSi] % 16) + '0');
				else if ((S[pSi] % 16) >= 10)
					counter += _putchar((S[pSi] % 16) + 55);
				pSi++;
			}
		}
		else
			counter += _putchar(S[pSi++]);
	}
	return (counter);
}

/**
 * print_rev - Prints a string in reverse.
 * @h: Va_list argument with value needed.
 *
 * Return: lenght of string
 */
int print_rev(va_list h)
{
	int len = 0, i;
	char *s = va_arg(h, char *);

	while (*s != '\0')
	{
		len++;
		++s;
	}

	s--;

	for (i = len; i > 0; i--)
	{
		_putchar(*s);
		s--;
	}
	return (len);
}

/**
 * print_uil_num - Prints an integar number
 * @n: Integar number to be printed
 *
 * Return: Number integer characters printed to stdout
 */
int print_uil_num(uil n)
{
	uil num = n, count = 0;

	if (num / 10)
		count += print_uil_num(num / 10);
	count += _putchar((num % 10) + '0');
	return (count);
}

/**
 * print_unsign - Function that prints an unsigned int to stdout
 * @h: va_list argument with value needed
 *
 * Return: The number of unsinged integers printed to stdout
 */
int print_unsign(va_list h)
{
	unsigned int num = va_arg(h, unsigned int);
	int total;

	total = print_uil_num((uil) num);
	return (total);
}
