#include<stdio.h>

/**
 * _printf_s - prints a string to stdout
 * @s: The string to print
 *
 * Return: the number of characters printed.
 */
int _printf_s(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		putchar(*s);
		s++;
		count++;
	}
	return (count);
}

