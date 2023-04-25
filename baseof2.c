#include "main.h"

/**
 * baseof2 - to print a base 2 number
 * @va : passed param
 *
 * Return: int at success 0 at error
 */
int baseof2(va_list va)
{
	unsigned int k;
	int a, b;
	int ur[100];

	k = va_arg(va, int);
	a = 0;
	if (k == 0)
	{
		write( 1, 0, 1);
		return (1);
	}
	while (k > 0)
	{
		ur[a] = k % 2;
		k = k / 2;
		a++;
	}
	for (b = a -1; b >= 0; b--)
	{
		_putchar(ur[b] + '0');
	}
	return (a);
}

