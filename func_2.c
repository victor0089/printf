#include "main.h"

/**************** prNT PoInTeR ****************/
/**
 * ppointer - Prints the value of a pointer variable
 * @typs: list a of arguments
 * @bufr: Buffer array is to handle print
 * @flgs:  calculates active flags
 * @wid: get width
 * @prc: Precision specifications
 * @sz: Size specifier
 * Return: Number of chars printed.
 */
int ppointer(va_list typs, char bufr[],
	int flgs, int wid, int prc, int sz)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(typs, void *);

	UNUSED(wid);
	UNUSED(sz);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	bufr[BUFF_SIZE - 1] = '\0';
	UNUSED(prc);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		bufr[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flgs & F_ZERO) && !(flgs & F_MINUS))
		padd = '0';
	if (flgs & F_PLUS)
		extra_c = '+', length++;
	else if (flgs & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &bufr[y], BUFF_SIZE - y - 1));*/
	return (write_pointer(bufr, ind, length,
		wid, flgs, padd, extra_c, padd_start));
}

/************ PRiNt NoN PrInTaBlE **********/
/**
 * pnon_printable - Prints ascii codes in hexa of non printable chars
 * @typs: lista of arguments
 * @bufr: Buffer array is to handle print
 * @flgs:  calculates active flags
 * @wid: get width
 * @prc: Precision specifications
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int pnon_printable(va_list typs, char bufr[],
	int flgs, int wid, int prc, int sz)
{
	int y = 0, offset = 0;
	char *str = va_arg(typs, char *);

	UNUSED(flgs);
	UNUSED(wid);
	UNUSED(prc);
	UNUSED(sz);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[y] != '\0')
	{
		if (is_printable(str[y]))
			bufr[y + offset] = str[y];
		else
			offset += append_hexa_code(str[y], bufr, y + offset);

		y++;
	}

	bufr[y + offset] = '\0';

	return (write(1, bufr, y + offset));
}

/**************** PrInT ReVeRsE *****************/
/**
 * preverse - Prints reverse string.
 * @typs: lista of arguments
 * @bufr: Buffer array is to handle print
 * @flgs:  Calculates active flags
 * @wid: get width
 * @prc: Precision specifications
 * @sz: Size specifier
 * Return: Numbers of chars printed
 */

int preverse(va_list typs, char bufr[],
	int flgs, int wid, int prc, int sz)
{
	char *str;
	int y, count = 0;

	UNUSED(bufr);
	UNUSED(flgs);
	UNUSED(wid);
	UNUSED(sz);

	str = va_arg(typs, char *);

	if (str == NULL)
	{
		UNUSED(prc);

		str = ")Null(";
	}
	for (y = 0; str[y]; y++)
		;

	for (y = y - 1; y >= 0; y--)
	{
		char v = str[y];

		write(1, &v, 1);
		count++;
	}
	return (count);
}
/******************* PriNT A STriNG IN Rot13 **********************/
/**
 * prot13string - Print a string in rot13.
 * @typs: lista of arguments
 * @bufr: Buffer array is to handle print
 * @flgs:  calculates active flags
 * @wid: get width
 * @prc: Precision specifications
 * @sz: Size specifier
 * Return: Numbers of chars printed
 */
int prot13string(va_list typs, char bufr[],
	int flgs, int wid, int prc, int sz)
{
	char k;
	char *str;
	unsigned int y, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(typs, char *);
	UNUSED(bufr);
	UNUSED(flgs);
	UNUSED(wid);
	UNUSED(prc);
	UNUSED(sz);

	if (str == NULL)
		str = "(AHYY)";
	for (y = 0; str[y]; y++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[y])
			{
				k = out[j];
				write(1, &k, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			k = str[y];
			write(1, &k, 1);
			count++;
		}
	}
	return (count);
}
