#include "main.h"
/**
 * print_percent - Handles printing of a percent sign.
 * @args: List of arguments (not used in this function).
 * @b: Buffer to handle printing (not used in this function).
 * @f: Flags to calculate active flags (not used in this function).
 * @w: Width specification (not used in this function).
 * @p: Precision specification (not used in this function).
 * @s: Size specifier (not used in this function).
 *
 * Return: The number of characters printed (always 1 for the percent sign).
 */

int print_percentage(va_list args, char b[], int f, int w, int p, int s)
{
    UNUSED(args);
    UNUSED(b);
    UNUSED(f);
    UNUSED(w);
    UNUSED(p);
    UNUSED(s);
    
    return (write(1, "%%", 1));
}

/**
 * print_unsigned_number - Prints an unsigned number.
 * @types: contains list of arguments.
 * @b: b for Buffer - array for printing.
 * @f: f for flag - Flag options that determine formatting.
 * @w:  w for width - Width specification.
 * @p:  p for precision - Precision specification.
 * @s: s for size - Size specifier.
 *
 * Return: The number of characters printed.
 */

int print_unsigned_number(va_list types, char b[],
	int f, int w, int p, int s)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
/*convert_unsigned_size*/
	num = convert_unsigned_size(num, s);

	if (num == 0)
		b[i--] = '0';

	b[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		b[i--] = (num % 10) + '0';
		num /= 10;
	}
    i=i+1;


	return (write_unsigned(0, i, b, f, w, p, s));
}

/**
 * print_hexa_upper - uppercase hexadecimal notation
 * @types: this variable contains list of arguments
 * @b: Buffer - array to handle print
 * @f: flags - Calculates active flags
 * @w:  width
 * @p: Precision
 * @s: size
 * Return: the number of characters that is  printed
 */
int print_uppercase_hexadecimal(va_list types, char b[],
	int f, int w, int p, int s)
{
	return (print_hexadecimal(types, "0123456789ABCDEF", b,
		f, 'X', w, p, s));
}
