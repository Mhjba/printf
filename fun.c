#include "main.h"

/**
 * printf_binary - prints a binary number
 * @num: number arguements
 * @printed: the printed characters
 * Return: printed charcaters
 */

int printf_binary(unsigned int num, int printed)
{
	int binary[32] = {0};
	int i = 0;

	if (num == 0)
	{
		_putchar('0');
		printed++;
		return (printed);
	}

	while (num > 0)
	{
		binary[i] = num % 2;
		num /= 2;
		i++;
	}

	while (i > 0)
	{
		i--;
		_putchar('0' + binary[i]);
		printed++;
	}

	return (printed);
}
/**
 * printf_char - prints a binary number
 * @args: the arguements to use
 * @printed: the printed characters
 * Return: printed charcaters
 */

int printf_char(va_list args, int printed)
{
	int character = va_arg(args, int);

	_putchar(character);
	return (printed + 1);
}
/**
 * _x - prints a binary number
 * @num: number arguements
 * @printed: the printed characters
 * @uppercase: the uppercase equivalent
 * Return: printed charcaters
 */

int _x(unsigned int num, int printed, int uppercase)
{
	int hex[100], i = 0, j;

	while (num != 0)
	{
		int remainder = num % 16;

		if (remainder < 10)
		{
			hex[i] = 48 + remainder;
		}
		else
		{
			if (uppercase)
			{
				hex[i] = 65 + (remainder - 10);
			}
			else
			{
				hex[i] = 97 + (remainder - 10);
			}
		}
		i++;
		num /= 16;
	}
	if (i == 0)
	{
		_putchar('0');
		printed++;
	}
	else
	{
		for (j = i - 1; j >= 0; j--)
		{
			_putchar(hex[j]);
			printed++;
		}
	}
	return (printed);
}
