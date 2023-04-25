#include "main.h"

int size_thox(va_list va)
{
	unsigned int k;
	int a, b, ka;
	int ur[100];

	k = va_arg(va, unsigned int);
	a = 0;
	ka = 0;
	if (k == 0)
	{
		write(1, 0, 1);
		return (1);
	}
	while (k != 0)
	{
		ka = k % 16;
		if (ka < 10)
		{
			ur[a] = 48 + ka;
		}
		else
		{
			ur[a] = 87 + ka;
		}
		k = k / 16;
		a++;
	}
	for (b = a -1; b >= 0; b--)
	{
		putchar(ur[b]);
	}
	return (a);
}

int size_tCAPX(va_list va)
{
	unsigned int k;
	int a, b, ka;
	int ur[100];

	k = va_arg(va, unsigned);
	a = ka = 0;
	if(k == 0)
	{
		write(1, 0, 1);
	}
	while (k != 0)
	{
		ka = k % 16;
		if (ka < 10)
		{
			ur[a] = 48 + ka;
		}
		else
		{
			ur[a] = 55 + ka;
		}
		a++;
	}
	for (b = a - 1; b >= 0; b--)
	{
		putchar(ur[b]);
	}
	return (a);
}

