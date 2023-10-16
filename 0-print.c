#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _int_to_hex - converts integer to hexadecimal
 * @num1: unsigned integer to be converted
 * @upper: 0 for lowercase, 1 for uppercase
 *
 * Return: Nothing.
 */
void _int_to_hex(unsigned int num1, int upper)
{
	int rem;

	rem = 0;

	if (num1 == 0) return;
	_int_to_hex(num1 / 16, upper);
	rem = num1 % 16;
	if (rem < 10)
	{
		_putchar(rem + '0');
	}
	else
	{
		_putchar(rem - 10 + (upper ? 'A' : 'a'));
	}
}

/**
 * _int_to_octal - converts integer to binary
 * @num1: unsigned integer to be converted
 *
 * Return: Nothing.
 */
void _int_to_octal(unsigned int num1)
{
	if (num1 == 0) return;
	_int_to_octal(num1 / 8);
	_putchar((num1 % 8) + '0');
}

/**
 * _int_to_bin - converts unsigned integer to binary
 * and prints on stdout
 * @num1: unsigned integer to be converted
 *
 * Return: Nothing.
 */
void _int_to_bin(unsigned int num1)
{
	if (num1 > 1)
	{
		_int_to_bin(num1 / 2);
	}
	_putchar((num1 % 2) + '0');
}

/**
 * _printf - produces output according to a format
 * @format: format to print
 * @...: arguments
 *
 * Return: Number of characters printed
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
	unsigned int num1;
	unsigned int numreverse1;

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
						numreverse = numreverse * 10 +
						       	num % 10;
						num /= 10;
					}
					while (numreverse > 0)
					{
						_putchar(numreverse % 10 +
							       	'0');
						numreverse /= 10;
						count++;
					}
				}
				break;
			case 'u':
				num1 = va_arg(args, unsigned int);
				if (num1 == 0)
				{
					_putchar('0');
					count++;
				}
				else
				{
					numreverse1 = 0;
					while (num1 > 0)
					{
						numreverse1 = numreverse1 *
						       	10 + num1 % 10;
						num1 /= 10;
					}
					while (numreverse1 > 0)
					{
						_putchar(numreverse1 % 10 +
								'0');
						numreverse1 /= 10;
						count++;
					}
				}
				break;
			case 'b':
				num1 = va_arg(args, unsigned int);
				_int_to_bin(num1);
				count++;
				break;
			case 'o':
				num1 = va_arg(args, unsigned int);
				if (num1 == 0)
				{
					_putchar('0');
					count++;
				}
				_int_to_octal(num1);
				count++;
				break;
			case 'x':
				num1 = va_arg(args, unsigned int);
				if (num1 == 0)
				{
					_putchar('0');
					count++;
				}
				_int_to_hex(num1, 0);
				count++;
				break;
			case 'X':
				num1 = va_arg(args, unsigned int);
				if (num1 == 0)
				{
					_putchar('0');
				}
				_int_to_hex(num1, 1);
				count++;
				break;
			default:
				_putchar(*format);
				count++;
				break;
		}
	}
	va_end(args);
	return (count);
}
