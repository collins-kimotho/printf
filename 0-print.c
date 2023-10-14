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
	int num;
	int numreverse;

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
			case 'd':
			case 'i':
				num = va_arg(args, int);
				if (num == 0)
				{
					_putchar('0');
				}
				else
				{
					if (num < 0)
					{
						_putchar('-');
						num = -num;
					}
					numreverse = 0;
					while (num > 0)
					{
						numreverse = numreverse * 10 + num % 10;
						num /= 10;
					}
					while (numreverse > 0)
					{
						_putchar(numreverse % 10 + '0');
						numreverse /= 10;
						count++;
					}
				}
				break;
			default:
				break;
		}
	}
	va_end(args);
	return (count);
}
