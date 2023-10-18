#include "main.h"

/**
 * _printf_special_char_hex - prints hexadecimal value of
 * special character.
 * @num: number to convert.
 * Return: number of characters printed.
 */
int _printf_special_char_hex(unsigned int num)
{
	int i;
	int *array;
	int charsprinted = 0;
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		charsprinted++;
	}
	charsprinted++;
	array = malloc(charsprinted * sizeof(int));

	for (i = 0; i < charsprinted; i++)
	{
		array[i] = temp % 16;
		temp /= 16;
	}
	for (i = charsprinted - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 7;
		_putchar(array[i] + '0');
	}
	free(array);
	return (charsprinted);
}
