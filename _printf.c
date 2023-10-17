#include "main.h"
/**
 * _printf - prints output according to a format.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char * const format, ...)
{
	convert_match m[] = {
		{"%s", _printf_string}, {"%c", _printf_char},
		{"%%", _printf_percent}, {"%d", _printf_decimal},
		{"%i", _printf_integer}, {"%b", _printf_binary},
		{"%u", _printf_unsigned}, {"%o", _printf_octal},
		{"%x", _printf_lower_hex}, {"%X", _printf_upper_hex}
	};

	va_list args;
	int i = 0, k, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Loopthrough:
	while (format[i] != '\0')
	{
		k = 9;
		while (k >= 0)
		{
			if (m[k].id[0] == format[i] && m[k].id[1] == format[i + 1])
			{
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
