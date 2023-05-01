#include <stdarg.h>
#include <unistd.h>

int _putchar(char c)
{
	return write(1, &c, 1);
}

int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	const char *p = format;
	
	va_start(args, format);
	while (*p != '\0')
	{
		if (*p == '%')
		{
			p++;
			if (*p == 'c')
			{
				char c = (char) va_arg(args, int);
				printed_chars += _putchar(c);
			}
			else if (*p == 's')
			{
				char *str = va_arg(args, char*);
				while (*str != '\0')
				{
					printed_chars += _putchar(*str);
					str++;
				}
			}
			else if (*p == '%')
			{
				printed_chars += _putchar('%');
			}
			else
			{
				printed_chars += _putchar('%');
				printed_chars += _putchar(*p);
			}
		}
		else
		{
			printed_chars += _putchar(*p);
		}
		p++;
	}
	va_end(args);
	return printed_chars;
}
