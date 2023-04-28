#include "main.h"

/**
 * gwid - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @y: list of arguments to be printed.
 * @lst: list of arguments.
 *
 * Return: width.
 */
int gwid(const char *format, int *y, va_list lst)
{
	int curr_y;
	int wid = 0;

	for (curr_y = *y + 1; format[curr_y] != '\0'; curr_y++)
	{
		if (is_digit(format[curr_y]))
		{
			wid *= 10;
			wid += format[curr_y] - '0';
		}
		else if (format[curr_y] == '*')
		{
			curr_y++;
			wid = va_arg(lst, int);
			break;
		}
		else
			break;
	}

	*y = curr_y - 1;

	return (wid);
}
