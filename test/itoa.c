#include "main.h"

char *_itoa(int num)
{
	char *str;
	int i = 1, m, k = 0, len, power, keep;
	len = num < 0 ? 3 : 2;
	k = num < 0 ? 1 : 0;
	num *= num < 0 ? -1 : 1;

	keep = num;

	while (keep > 9)
	{
		keep /= 10;
		len++;
	}

	power = len - 2;

	str = malloc(sizeof(char) * len);
	if (str == NULL)
	{
		exit (1);
	}
	else if (k == 1)
	{
		str[0] = '-';
		power -= 1;
	}

	for (m = 0; m < power; m++)
	{
		i *= 10;
	}
	while (i >= 1)
	{
		str[k] = ((num / i) % 10) + '0';
		i /= 10;
		k++;
	}
	str[k] = '\0';
	return (str);
}
