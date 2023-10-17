#include "main.h"

/**
 * _printf_char - prints a char.
 * @val: arguments.
 * Return: 1.
 */
int _printf_char(va_list val)
{
	char s;

	s = va_arg(val, int);
	_putchar(s);
	return (1);
}
