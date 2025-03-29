#include "_printf.h"
#include <stdarg.h>

int print_char(va_list args)
{
    char c = (char)va_arg(args,int);
    return (_putchar(c));
}

int print_string(va_list args)
{
    char *str = va arg(args, char*);
    int count = 0;

    if (str == NULL)
	str = "(null)";

    for (int i = 0; str [i]; i++)
	count += _putchar(str[i]);

    return (count);

int print_percent(void)
{
    return (_putchar('%'));
}

