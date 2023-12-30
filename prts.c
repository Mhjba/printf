#include "main.h"


/**
 * print_binary_number - Outputs an unsigned integer in binary representation.
 * @args: The argument list (not used).
 * @b: A buffer for printing (not used).
 * @f: Formatting flags (not used).
 * @w: Width setting (not used).
 * @p: Precision setting (not used).
 * @s: Size specifier (not used).
 *
 * Return: The count of printed characters.
 */

int print_binary_number(va_list args, char b[], int f, int w, int p, int s)
{
    unsigned int n;
    unsigned int m;
    unsigned int i;
    unsigned int sum;
    unsigned int a[32];
    int count;

    UNUSED(b);
    UNUSED(f);
    UNUSED(w);
    UNUSED(p);
    UNUSED(s);

    n = va_arg(args, unsigned int);
    m = 2147483648; /* this is the equal of = (2 ^ 31) = 2147483648 */
    a[0] = n / m;
    
    for (i = 1; i < 32; i++)
    {
        m /= 2;
        a[i] = (n / m) % 2;
    }
    
    for (i = 0, sum = 0, count = 0; i < 32; i++)
    {
        sum += a[i];
         /*sum= sum+a[i];*/
        if (sum || i == 31)
        {
            char z = '0' + a[i];
            write(1, &z, 1);
            count += 1; /*count++;*/
        }
    }
    return (count);
}
/**
 * print_hexa - Prints a hexadecimal number in lowercase or uppercase
 * @types: variable contains a list of arguments
 * @map_to: Array of values to map the number to
 * @b: Buffer
 * @f: flags
 * @flag_ch: Calculates active flags
 * @w: width
 * @p: Precision
 * @s: Size
 * @s: Size
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char map_to[], char b[],
	int f, char flag_ch, int w, int p, int s)
{
	int index = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(w);

	num = convert_unsigned_size(num, s);

	if (num == 0)
		b[index--] = '0';

	b[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		b[index--] = map_to[num % 16];
		num /= 16;
	}

	if (f & FLAG_HASH && init_num != 0)
	{
		b[index--] = flag_ch;
		b[index--] = '0';
	}

	index++;

	return (write_unsigned(0, index, b, f, w, p, s));
}
