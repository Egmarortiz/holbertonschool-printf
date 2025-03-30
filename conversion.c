#include "main.h"
#include <stddef.h>
#include <stdarg.h>

int print_char(va_list args)
{
	char c = (char)va_arg(args, int);

	return (_putchar(c));
}

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


int print_percent(void)
{
	return (_putchar('%'));
}
