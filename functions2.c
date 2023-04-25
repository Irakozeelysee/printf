#include "main.h"
/**
 *  write_pointer - helper function to write pointer value to buffer
 *  @buffer: Buffer array to handle print
 *  @ind: current index in buffer
 *  @length: length of pointer value string
 *  @padd_start: indicates if padding should start at the beginning or end
 *  @padd_char: character to use for padding
 *  Return: Number of chars printed
 */

int write_pointer(char buffer[], int ind, int length,
		int padd_start, char padd_char)
{
	int i, count = 0;
	
	if (padd_start)
	{
		for (; ind >= 0; ind--)
		{
			if (ind == length - 1)
				buffer[ind] = 'x';
			else if (ind == length - 2)
				buffer[ind] = '0';
			else
				buffer[ind] = padd_char;
		}
		count += write(1, buffer, length);
	}
	else
	{
		for (i = 0; i < padd_start; i++)
		{
			buffer[ind--] = padd_char;
			count++;
		}
		count += write(1, buffer + ind + 1, length - ind - 1);
	}
	return (count);
}

/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list types, char buffer[],
		                int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);
	UNUSED(width);
	UNUSED(size);
	
	if (addrs == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);
	num_addrs = (unsigned long)addrs;
	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;
	ind++;
	return (write_pointer(buffer, ind, length, padd_start, padd));
}
