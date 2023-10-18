#include "main.h"

/**
 * _printf_another_lower_hex - prints hexadecimal number
 * representing memory address
 * @n: argument.
 * Return: Number of characters printed.
 */
int _printf_another_lower_hex(unsigned long int n)
{
	/* long int i, counter;
	long int *array;
	unsigned long int temp = n;

	counter = 0;
	while (n / 16 != 0)
	{
		n /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(long int));

	for (i = 0; i < counter; i++)
	{
		array[i] = temp % 16;
		temp /= 16;
	}
	for (i = counter - 1; i >= 0; i--)
	{
		if (array[i] > 9)
		{
			array[i] = array[i] + 39;
		}
		_putchar(array[i] + '0');
	}
	free(array);
	return (counter); */

	int counter;
	unsigned long int num;
	char c;

	counter = 0;
	num = n;

	if (num < 16)
	{
		c = num < 10 ? '0' + n : 'a' + num - 10;
		_putchar(c);
		counter++;
	}
	else
	{
		_printf_another_lower_hex(num / 16);
		_printf_another_lower_hex(num % 16);
	}
	return (counter);
}
