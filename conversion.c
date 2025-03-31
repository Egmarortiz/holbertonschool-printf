#include "main.h"
#include <stdarg.h>
#include <unistd.h>

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
 * print_percent - Prints a percent character
 * Return: Number of characters printed (always 1)
 */
int print_percent(void)
{
    return (_putchar('%'));
}

/**
 * print_int - Prints an integer to stdout
 * @args: variadic list containing integer
 * Return: Number of characters printed
 */
int print_int(va_list args)
{
    int num = va_arg(args, int);
    unsigned int abs_num;
    int div = 1, len = 0;

    if (num < 0)
    {
        len += _putchar('-');
        abs_num = -num;
    }
    else
    {
        abs_num = num;
    }

    while (abs_num / div > 9)
        div *= 10;

    while (div != 0)
    {
        len += _putchar('0' + (abs_num / div));
        abs_num %= div;
        div /= 10;
    }

    return (len);
}

