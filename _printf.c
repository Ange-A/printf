#include <stdlib.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - print anything
 * @format: arguments
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arguments;
	const char *p;
	int numb = 0;

	if (format == NULL)
		return (-1);
	va_start(arguments, format);
	for (p = format; *p; p++)
	{
		if (*p == '%' && *p + 1 == '%')
		{
			_putchar(*p), numb++;
			continue;
		}
		else if (*p == '%' && *p + 1 != '%')
		{
			switch (*++p)
			{
				case 's':
					numb += func_string(arguments);
					break;
				case 'c':
					numb += func_character(arguments);
					break;
				case '%':
					_putchar('%'), numb++;
					break;
				case '\0':
					return (-1);
				case 'i':
				case 'd':
					numb += func_integer(arguments);
					break;
				default:
					_putchar('%'), _putchar(*p), numb += 2;
			}
		}
		else
			_putchar(*p), numb++;
	}
va_end(arguments);
return (numb);
}
