#include<stdarg.h>
#include "main.h"
#include <unistd.h>

/**
 * _printf - produes output according to format
 * @format: The format string
 * @...: The avariable number of arguments
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			switch (*++format)
			{
				case 'c':
					count += _printf_c(va_arg(args, int));
					break;
				case 's':
					count += _printf_s(va_arg(args, char *));
					break;
				case '%':
					count += _printf_percent();
					break;
				default:
					/* Ignore unknown conversion specifers*/
				break;
			}
		}
		else
		{
			count += _printf_c(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
