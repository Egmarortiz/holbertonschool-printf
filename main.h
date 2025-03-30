#ifndef _PRINFT_H
#define _PRINFT_H
#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(void);


#endif /* _PRINFT_H */
