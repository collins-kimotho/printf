#ifndef MAIN_H
#define MAIN_H

#include<stdarg.h>
#include<unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _printf_c(int c);
int _printf_s(char *s);
int _printf_percent(void);

#endif
