#include "main.h"
/**
 * hprint - Prints an argument based on its type
 * @victor: Formatted string in which to print the arguments.
 * @lst: List of arguments to be printed.
 * @ind: ind.
 * @bufr: Buffer array to handle print.
 * @flgs: Calculates active flags
 * @wid: get width.
 * @prc: Precision specification
 * @sz: Size specifier
 *
 * Return: 1 or 2;
 */
int hprint(const char *victor, int *ind, va_list lst, char bufr[],
	int flgs, int wid, int prc, int sz)
{
	int y, unknow_len = 0, pchars = -1;
	victor_t victor_types[] = {
		{'c', pchar}, {'s', pstring}, {'%', ppercent},
		{'i', pint}, {'d', pint}, {'b', pbinary},
		{'u', punsigned}, {'o', poctal}, {'x', phexadecimal},
		{'X', phexa_upper}, {'p', ppointer}, {'S', pnon_printable},
		{'r', preverse}, {'R', prot13string}, {'\0', NULL}
	};
	for (y = 0; victor_types[y].victor != '\0'; y++)
		if (victor[*ind] == victor_types[y].victor)
			return (victor_types[y].nad(lst, bufr, flgs, wid, prc, sz));

	if (victor_types[y].victor == '\0')
	{
		if (victor[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (victor[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (wid)
		{
			--(*ind);
			while (victor[*ind] != ' ' && victor[*ind] != '%')
				--(*ind);
			if (victor[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &victor[*ind], 1);
		return (unknow_len);
	}
	return (pchars);
}
