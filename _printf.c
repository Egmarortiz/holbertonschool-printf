#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - writes a character to stdout.
 * @c: The character to print.
 *
 * Return: 1 on success.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - produces output according to a format.
 * @format: The format string.
 *
 * Description: Supports conversion specifiers:
 *		c: char
 *		s: string (prints "(null)" if the string is NULL)
 *		%: prints a literal '%'
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0;
	char *str;
	char c;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					c = (char)va_arg(args, int);
					_putchar(c);
					count++;
					break;
				case 's':
					str = va_arg(args, char *);
					if (str == NULL)
						str = "(null)";
					while (*str)
					{
						_putchar(*str);
						count++;
						str++;
					}
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				default:
					_putchar('%');
					_putchar(format[i]);
					count += 2;
					break;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}

	va_end(args);
	return (count);
}


