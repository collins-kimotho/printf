#include "main.h"
/**
 * _printf_pointer - prints pointer address
 * @args: arguments.
 * Return: Number of characters printed.
 */
int _printf_pointer(va_list args)
{
	long int n;
	int i, counter;
	void *p;
	char *s = "(nil)";

	p = va_arg(args, void *);
	if (p == NULL)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			_putchar(s[i]);
		}
		return (i);
	}
	n = (unsigned long int)p;
	_putchar('0');
	_putchar('x');
	counter = _printf_another_lower_hex(n);
	return (2 + counter);
}
