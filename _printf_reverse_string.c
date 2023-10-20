#include "main.h"

/**
 * _printf_reverse_string - prints a reversed string
 * @args: arguments.
 * Return: Number of string characters printed.
 */
int _printf_reverse_string(va_list args)
{
	int i, counter;
	char *s = va_arg(args, char *);

	counter = 0;
	if (s == NULL)
	{
		s = "(null)";
	}
	while (s[counter] != '\0')
	{
		counter++;
	}
	for (i = counter - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}
	return (counter);
}
