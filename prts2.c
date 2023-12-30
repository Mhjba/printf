#include "main.h"


/**
 * print_memory_address - Prints the value stored in a pointer variable
 * @types: variable that contains arguments
 * @b: Buffer 
 * @f: flags
 * @w: width - variable when we put the width
 * @p: Precision - variable when we put the precision
 * @s: Size - variable when we put the size
 * Return: Number of characters that we  printed.
 */
int print_memory_address(va_list types, char b[],
	int f, int w, int p, int s)
{
	char extra_char = 0; 
    char padding_char = ' ';
	int index = BUFFER_SIZE - 2;
    unsigned long num_addresses;
    int length = 2;
    int padding_start = 1; 
	
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(types, void *);

	UNUSED(w);
	UNUSED(s);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	b[BUFFER_SIZE - 1] = '\0';
	UNUSED(p);

	num_addresses = (unsigned long)address;

	while (num_addresses > 0)
	{
		b[index--] = map_to[num_addresses % 16];
		num_addresses /= 16;
		length++;
	}

	if ((f & FLAG_ZERO) && !(f & FLAG_MINUS))
		padding_char = '0';
	if (f & FLAG_PLUS)
		extra_char = '+', length++;
	else if (f & FLAG_SPACE)
		extra_char = ' ', length++;

	index++;

	/*return (write(1, &buffer[i], BUFFER_SIZE - i - 1));*/
	return (write_memory_address(b, index, length,
		w, f, padding_char, extra_char, padding_start));
}

/**
 * print_octal_number - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @b: Buffer array to handle print
 * @f: flags that  Calculates active flags
 * @w: w for width - get width
 * @p: p for Precision specification
 * @s: s for Size specifier
 * Return: Number of chars printed
 */
int print_octal_number(va_list types, char b[],
	int f, int w, int p, int s)
{

	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(w);

	num = convert_unsigned_size(num, s);

	if (num == 0)
		b[i--] = '0';

	b[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		b[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (f & FLAG_HASH && init_num != 0)
		b[i--] = '0';

	i++;

	return (write_unsigned(0, i, b, f, w, p, s));
}
