#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - Writes a character to stdout
 * @c: character to write
 * Return: 1 on success, -1 on failure
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
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

