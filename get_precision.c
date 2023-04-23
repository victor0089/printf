
#include "main.h"

/**
 * get_precision - gets the precision from the format string
 * @s: the format string
 * @params: the parameters struct
 * @ap: the argument pointer
 * Return: new pointer
*/

char *get_precision(char *s, params_t *params, va_list ap)
{
	int d = 0;

	if (*s != '.')
		return (s);
	s++;
	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->precision = d;
	return (s);
}
