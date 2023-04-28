#include "main.h"

/**
 * gsz -Calculates the SIze to cast the argument
 * @format: ForMatted sTring in which to print the arguments
 * @y: list of arguments to be printed.
 *
 * Return: Precision.
 */
int gsz(const char *format, int *y)
{
	int curr_y = *y + 1;
	int sz = 0;

	if (format[curr_y] == 'l')
		sz = S_LONG;
	else if (format[curr_y] == 'h')
		sz = S_SHORT;

	if (sz == 0)
		*y = curr_y - 1;
	else
		*y = curr_y;

	return (sz);
}
