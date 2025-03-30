#include "main.h"
#include <stddef.h>
#include <stdarg.h>

/**
 * print_char - Prints a character from a va_list.
 * @args: A va_list containing the character to print.
 *
 * Return: The number of characters printed.
 */

int print_char(va_list args)
{
	char c = (char)va_arg(args, int);

	return (_putchar(c));
}

/**
 * print_string - Prints a string from a va_list.
 * @args: A va_list containing the string to print.
 *
 * Return: The number of characters printed.
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char*);
	int count = 0;
	int i;

	if (str == NULL)
	{
		str = "(null)";
		for (i = 0; str[i] != '\0'; i++)
		{
			count += _putchar(str[i]);
		}
		return (count);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		count += _putchar(str[i]);
	}
	return (count);
}


/**
 * print_percent - Prints a percent sign.
 *
 * Return: The number of characters printed.
 */
int print_percent(void)
{
	return (_putchar('%'));
}
