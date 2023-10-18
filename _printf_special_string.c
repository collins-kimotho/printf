#include "main.h"
/**
 * _printf_special_string - prints special string.
 * @args: arguments.
 * Return: the length of the string.
 */

int _printf_special_string(va_list args)
{
	char *s;
	int i, strlen = 0;
	int strvalue;

	s = va_arg(args, char *);
	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
	{
		if ((s[i] >= 0 && s[i] < 32) || s[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			strlen = strlen + 2;
			strvalue = s[i];
			if (strvalue < 16)
			{
				_putchar('0');
				strlen++;
			}
			strlen = strlen + _printf_special_char_hex(strvalue);
		}
		else
		{
			_putchar(s[i]);
			strlen++;
		}
	}
	return (strlen);
}
