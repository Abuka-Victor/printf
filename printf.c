#include "print.h"


int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, len = 0, k, j;
	char *dest = NULL;
	char *argStr;
	char *argChar;

	while (format[len] != '\0')
		len++;

	dest = malloc(sizeof(char) * len);
	if (dest == NULL)
		exit(1);

	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			argStr = malloc(sizeof(char) * 2);
			argStr[0] = (char)va_arg(ap, int);
			argStr[1] = '\0';
			_sprintf(argStr);
			free(argStr);
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
		}
		else
		{
			for (j = i, k = 0; format[j] != '\0' ; k++, j++, i++)
			{
				if (format[j] == '%')
				{
					i = j;
					break;
				}
				else
				{
					dest[k] = format[j];
				}
			}
			dest[k] = '\0';
			_sprintf(dest);
		}
	}
}
