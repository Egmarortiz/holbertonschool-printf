#include "main.h"
#include <stdarg.h>

/**
 * _printf - produces output according to a format.
 * @format: format string.
 *
 * Return: number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, i = 0;

	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
			{
				va_end(args);
				return (-1);
			}
			if (format[i] == 'c')
				count += print_char(args);
			else if (format[i] == 's')
				count += print_string(args);
			else if (format[i] == 'd' || format[i] == 'i')
				count += print_int(args);
			else if (format[i] == '%')
				count += print_percent();
			else
			{
				_putchar('%');
				_putchar(format[i]);
				count += 2;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}


