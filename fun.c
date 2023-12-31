#include "main.h"

/**
 * con_spec - Function to check Conversion specifier
 * @ptr: Pointer to format string
 * @a: Pointer to format string index
 * @specptr: Array of typedef fmt
 * @point: va_list argument with variable needed
 *
 * Return: NUmber characters printed to stdout
 */
int con_spec(const char *ptr, int *a, fmt specptr[SIZE], va_list point)
{
	int j, count = 0;

	for (j = 0; j < SIZE; j++)
	{
		if (ptr[*a + 1] == specptr[j].c)
		{
			count += specptr[j].f(point);
			*a += 2;
			break;
		}
		else if (j == (SIZE - 1))
		{
			if (ptr[*a + 1] == '\0')
				return (-1);
			count += _putchar(ptr[*a]);
			*a += 1;
			if (ptr[*a] == '%')
				*a += 1;
		}
	}
	return (count);
}

/**
 * flag_char - Function to check flag character and print to stdout
 * @str: Pointer to format string
 * @point: va_list argument with value needed
 * @a: Pointer to format string index
 *
 * Return: Number of characters printed
 */
int flag_char(const char *str, va_list point, int *a)
{
	int count = 0;

	if (str[*a + 1] == '+' || str[*a + 1] == ' ')
	{
		if ((str[*a + 2] == 'i' || str[*a + 2] == 'd'))
			count += _putchar(str[*a + 1]);
		count += print_int(point);
		*a += 3;
	}
	else if (str[*a + 1] == '#')
	{
		if (str[*a + 2] == 'o')
		{
			count += _putchar('0');
			count += print_octal(point);
			*a += 3;
		}
		else if (str[*a + 2] == 'x')
		{
			count += _putchar('0');
			count += _putchar('x');
			count += print_hexa(point);
			*a += 3;
		}
		else if (str[*a + 2] == 'X')
		{
			count += _putchar('0');
			count += _putchar('X');
			count += print_heXa(point);
			*a += 3;
		}
	}
	return (count);
}
