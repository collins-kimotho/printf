#include "main.h"
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: format to print
 * @...: arguments
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count;
	va_list args;
	const char *fmt;
	char *str;
	char ch;

	count = 0;

	va_start(args, format);
	for(fmt = format; *fmt != '\0'; fmt++)
	{
		while (*fmt != '%' && *fmt != '\0')
		{
			_putchar(*fmt);
			fmt++;
			count++;
		}

		if (*fmt == '\0')
		{
			break;
		}

		fmt++;

		switch (*fmt)
		{
			case 'c':
				ch = va_arg(args, int);
				_putchar(ch);
				count++;
				break;
			case 's':
				for(str = va_arg(args, char *); *str != '\0';
						str++)
				{
					_putchar(*str);
					count++;
				}
				break;
			case '%':
				_putchar('%');
				count++;
				break;
			default:
				break;
		}
	}
	va_end(args);
	return (count);
}
