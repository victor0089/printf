#include "main.h"

/**
 * get_precision - gets the precision from the format string
 * @s: the format string
 * @i: the parameters struct
 * @list: the argument pointer
 * Return: new pointer
*/

char *get_precision(char *s, int *i, va_list list)
{
	int prc = 0;

	if (*s != '.')
		return (s);
	s++;
	if (*s == '*')
	{
		prc = va_arg(list, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			prc = prc * 10 + (*s++ - '0');
	}
	i->precision = prc;
	return (s);
}
