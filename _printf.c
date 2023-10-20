#include "main.h"
/**
 * _printf - prints output according to a format.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char * const format, ...)
{
	convert_match m[] = {
		{"%s", _printf_string, '\0'}, {"%c", _printf_char, '\0'},
		{"%%", _printf_percent, '\0'}, {"%d", _printf_decimal, '\0'},
		{"%i", _printf_integer, '\0'}, {"%b", _printf_binary, '\0'},
		{"%u", _printf_unsigned_int, '\0'}, {"%o", _printf_octal, '\0'},
		{"%x", _printf_lower_hex, '\0'}, {"%X", _printf_upper_hex, '\0'},
		{"%S", _printf_special_string, '\0'}, {"%p", _printf_pointer, '\0'}
	};

	va_list args;
	int i = 0, k, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Loopthrough:
	while (format[i] != '\0')
	{
		k = 11;
		while (k >= 0)
		{
			if (m[k].id[0] == format[i] && m[k].id[1] == format[i + 1])
			{
				/* Check for flag characters and call hgandle_flag*/
				handle_flags(&m[k], format, i);
				len += m[k].f(args);
				i = i + 2;
				goto Loopthrough;
			}
			k--;
		}
		_putchar(format[i]);
		len++;
		i++;
	}
	va_end(args);
	return (len);
}
