#include  "main.h"

/**
 * handle_flags - Handles the f;ag chracters for non-custome conversion specifiers
 * @m: pointer to the conver
 * @format: the format string
 * @i: the current index
 *
 * return: void
 */
void handle_flags(convert_match *m, const char *format, int i)
{
	if (format[i - 1] == '+')
		m->flag = '+';
	else if (format[i - 1] == ' ')
		m->flag = ' ';
	else if (format[i - 1] == '#')
		m->flag = '#';
	else
		m->flag = '\0';
}
