#include "main.h"

/**********PRINT CHAR**********/

/**
 * print_char - Prints a char
 * @typs: List a of arguments
 * @bufr: Bufr array to handle print
 * @flgs: Calculates active flags
 * @wd: wd
 * @prc: Prc specification
 * @sz: Sz specifier
 * Return: Number of chars printed
 */
int print_char(va_list typs, char bufr[], int flgs, int wd, int prc, int sz)
{
	char c = va_arg(typs, int);

	return (handle_write_char(c, bufr, flgs, wd, prc, sz));
}
/********************PRINT A STRING*******************/

/**
 * print_string - Prints a string
 * @typs: List a of arguments
 * @bufr: Bufr array to handle print
 * @flgs: Calculates active flags
 * @wd: get wd.
 * @prc: Prc specification
 * @sz: Sz specifier
 * Return: Number of chars printed
 */

int print_string(va_list typs, char bufr[], int flgs, int wd, int prc, int sz)
{
	int length = 0, i;
	char *str = va_arg(typs, char *);

	unused(bufr);
	unused(flgs);
	unused(wd);
	unused(prc);
	unused(sz);
	if (str == NULL)
	{
		str = "(null)";
		if (prc >= 6)
			str = "  ";
	}

	while (str[length] != '\0')
		length++;

	if (prc >= 0 && prc < length)
		length = prc;

	if (wd > length)
	{
		if (flgs & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = wd - length; i > 0; i--)
				write(1, " ", 1);
			return (wd);
		}
		else
		{
			for (i = wd - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (wd);
		}
	}

	return (write(1, str, length));
}

/*******************PRINT PERCENT SIGN******************/

/**
 * print_percent - Prints a percent sign
 * @typs: List a of arguments
 * @bufr: Bufr array to handle print
 * @flgs: Calculates active flags
 * @wd: get wd.
 * @prc: Prc specification
 * @sz: Sz specifier
 * Return: Number of chars printed
 */

int print_percent(va_list typs, char bufr[], int flgs, int wd, int prc, int sz)
{
	UNUSED(typs);
	UNUSED(bufr);
	UNUSED(flgs);
	UNUSED(wd);
	UNUSED(prc);
	UNUSED(sz);
	return (write(1, "%%", 1));
}

/*******************PRINT INT******************/

/**
 * print_int - Print int
 * @typs: List a of arguments
 * @bufr: Bufr array to handle print
 * @flgs: Calculates active flags
 * @wd: get wd
 * @prc: Prc specification
 * @sz: Sz specifier
 * Return: Number of chars printed
 */

int print_int(va_list typs, char bufr[], int flgs, int wd, int prc, int sz)
{
	int i = BUFF_SZ - 2;
	int is_negative = 0;
	long int n = va_arg(typs, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		bufr[i--] = '0';

	bufr[BUFF_SZ - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		bufr[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, bufr, flgs, wd, prc, sz));
}

/*********************PRINT BINARY*******************/

/**
 * print_binary - Prints an unsigned number
 * @typs: List a of arguments
 * @bufr: Bufr array to handle
 * @flgs: Calculates active flags
 * @wd: get wd.
 * @prc: Prc specification
 * @sz: Sz specifier
 * Return: Numbers of char printed.
 */

int print_binary(va_list typs, char bufr[], int flgs, int wd, int prc, int sz)
{
	unsigned int i, n, m, sum;
	unsigned int a[32];
	int count;

	UNUSED(bufr);
	UNUSED(flgs);
	UNUSED(wd);
	UNUSED(prc);
	UNUSED(sz);

	n = va_arg(typs, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
