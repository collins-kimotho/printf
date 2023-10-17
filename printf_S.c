#include <stdarg.h>
/**
 * printf_S - prints a sting, replacing non printable characters
 * @args: A va_list arguments
 *
 * Return: the number of characters printed
 */
int printf_S(va_list args)
{
	char *s = va_arg(args, char *);
	int count = 0;

	for (int i = 0; s[i] != '\0'; i++)
	{
		if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			char hex[3];

			sprintf(hex, "%02X", s[i]);
			_putchar(hex[0]);
			_putchar(hex[1]);
			count += 4;
		}
		else
		{
			_putchar(s[i]);
			count++;
		}
	}
	return (count);
}
