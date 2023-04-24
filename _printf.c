#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	 va_list args;
	 va_start(args, format);
	 int printed_chars = 0;
	 char *str;
	 char chr;

	 if (format == NULL)
		return (-1);
	 while (*format != '\0')
	 {
		 if (*format == '%')
		 {
			 format++;
			 switch (*format)
			 {
				 case 'c':
					 chr = va_arg(args, int);
					 write(1, &chr, 1);
					 printed_chars++;
					 break;
				 case 's':
					 str = va_arg(args, char *);
					 if (str == NULL)
						 str = "(null)";
					 while (*str != '\0')
					 {
						 write(1, str, 1);
						 str++;
						 printed_chars++;
					 }
					 break;
				 default:
					 write(1, "%", 1);
					 write(1, format, 1);
					 printed_chars += 2;
					 break;
			 }
		 }
		 else
		 {
			 write(1, format, 1);
			 printed_chars++;
		 }
		 format++;
	 }
	 va_end(args);
	 return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
