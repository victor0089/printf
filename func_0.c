#include "main.h"

/************** PRINT A STRING *******************/
/**
 * pstring - Prints a string
 * @typs: list a of arguments
 * @bufr: Buffer array is to handle print
 * @flgs:  calculates active flags
 * @wid: get width.
 * @prc: Precision specifications
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int pstring(va_list typs, char bufr[],
	int flgs, int wid, int prc, int sz)
{
	int length = 0, y;
	char *str = va_arg(typs, char *);

	UNUSED(bufr);
	UNUSED(flgs);
	UNUSED(wid);
	UNUSED(prc);
	UNUSED(sz);
	if (str == NULL)
	{
		str = "(null)";
		if (prc >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (prc >= 0 && prc < length)
		length = prc;

	if (wid > length)
	{
		if (flgs & F_MINUS)
		{
			write(1, &str[0], length);
			for (y = wid - length; y > 0; y--)
				write(1, " ", 1);
			return (wid);
		}
		else
		{
			for (y = wid - length; y > 0; y--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (wid);
		}
	}

	return (write(1, str, length));
}
/******************* PrINT PErCEnT SIGN ********************/
/**
 * ppercent - Prints a percent sign
 * @typs: lista of arguments
 * @bufr: Buffer array is to handle print
 * @flgs:  calculates active flags
 * @wid: get width.
 * @prc: Precision specifications
 * @sz: Size specifier
 * Return: Number of chars printed
 */

/*********************** PRNT INT *********************/
/**
 * pint - Print int
 * @typs: lista of arguments
 * @bufr: Buffer array is to handle print
 * @flgs:  calculates active flags
 * @wid: get width.
 * @prc: Precision specifications
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int pint(va_list typs, char bufr[],
	int flgs, int wid, int prc, int sz)
{
	int y = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(typs, long int);
	unsigned long int num;

	n = convert_size_number(n, sz);

	if (n == 0)
		bufr[y--] = '0';

	bufr[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		bufr[y--] = (num % 10) + '0';
		num /= 10;
	}

	y++;

	return (write_number(is_negative, y, bufr, flgs, wid, prc, sz));
}
/**************** PRINT CHAR **************/

/**
 * pchar - Prints a char
 * @typs: list a of arguments
 * @bufr: Buffer array is to handle print
 * @flgs:  calculates active flags
 * @wid: Width
 * @prc: Precision specifications
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int pchar(va_list typs, char bufr[],
	int flgs, int wid, int prc, int sz)
{
	char c = va_arg(typs, int);

	return (handle_write_char(c, bufr, flgs, wid, prc, sz));
}
/******************** PrNT BInARY **********************/
/**
 * pbinary - Prints an unsigned number
 * @typs: lista of arguments
 * @bufr: Buffer array is to handle print
 * @flgs:  calculates active flags
 * @wid: get width.
 * @prc: Precision specifications
 * @sz: Size specifier
 * Return: Numbers of char printed.
 */
int ppercent(va_list typs, char bufr[],
	int flgs, int wid, int prc, int sz)
{
	UNUSED(typs);
	UNUSED(bufr);
	UNUSED(flgs);
	UNUSED(wid);
	UNUSED(prc);
	UNUSED(sz);
	return (write(1, "%%", 1));
}
int pbinary(va_list typs, char bufr[],
	int flgs, int wid, int prc, int sz)
{
	unsigned int n, m, y, sum;
	unsigned int a[32];
	int count;

	UNUSED(bufr);
	UNUSED(flgs);
	UNUSED(wid);
	UNUSED(prc);
	UNUSED(sz);

	n = va_arg(typs, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (y = 1; y < 32; y++)
	{
		m /= 2;
		a[y] = (n / m) % 2;
	}
	for (y = 0, sum = 0, count = 0; y < 32; y++)
	{
		sum += a[y];
		if (sum || y == 31)
		{
			char d = '0' + a[y];

			write(1, &d, 1);
			count++;
		}
	}
	return (count);
}
