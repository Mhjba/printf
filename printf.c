#include "main.h"
/**
 * _printf -  entry point. custom printf
 * @format:  a charcter string
 * Return: Number of characters printed to  stdout
 */
int _printf(const char *format, ...)
{
	va_list head;
	int i = 0, counter = 0, ret;
	fmt spec[] = {
		{'c', print_char},
		{'s', print_str},
		{'i', print_int},
		{'d', print_int},
		{'b', print_bin},
		{'u', print_unsign},
		{'o', print_octal},
		{'x', print_hexa},
		{'X', print_heXa},
		{'p', print_p},
		{'S', print_S},
		{'r', print_rev},
		{'R', print_rot13}};

	va_start(head, format);
	if (format == NULL)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			ret = flag_char(format, head, &i);
			if (ret > 0)
			{
				counter += ret;
				continue;
			}
			ret = con_spec(format, &i, spec, head);
			if (ret == -1)
				return (-1);
			counter += ret;
			continue;
		}
		counter += _putchar(format[i++]);
	}
	return (counter);
}
