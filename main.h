#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _printf_char(va_list args);
int _printf_string(va_list args);
int _strlen(char *s);
int _printf_percent(void);
int _printf_decimal(va_list args);
int _printf_integer(va_list args);
int _printf_binary(va_list args);
int _printf_unsigned(va_list args);
int _printf_octal(va_list args);
int _printf_lower_hex(va_list args);
int _printf_upper_hex(va_list args);
int printf_S(va_list args);

/**
 * struct format - match the conversion specifiers for printf
 * @id: type char pointer of the specifier i.e (l, h) for (d, i, u, o, x, X)
 * @f: type pointer to function for the conversion specifier
 *
 */
typedef struct format
{
	char *id;
	int (*f)();
} convert_match;

#endif
