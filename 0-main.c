#include "main.h"

int main(void)
{
	char c;
	char *str;
	int num1;

	c = 'A';
	str = "Words";
	num1 = 52;

	_printf("%c\n", c);
	_printf("%s\n", str);
	_printf("%%\n");
	_printf("%d\n", num1);
	_printf("%i\n", num1);
	return (0);
}
