#include "main.h"


/*********** PrInT UNSiGNeD NUMBER IN OCTL  **************/
/**
 * poctal - Prints an unsigned number in octal notation
 * @typs: lista of arGuments
 * @bufr: Buffer array is to handle print
 * @flgs:  calculates acTive flags
 * @wid: get width
 * @prc: Precision specifications
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int poctal(va_list typs, char bufr[],
	int flgs, int wid, int prc, int sz)
{

	int y = BUFF_SIZE - 2;
	unsigned long int num = va_arg(typs, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(wid);

	num = convert_size_unsgnd(num, sz);

	if (num == 0)
		bufr[y--] = '0';

	bufr[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		bufr[y--] = (num % 8) + '0';
		num /= 8;
	}

	if (flgs & F_HASH && init_num != 0)
		bufr[y--] = '0';

	y++;

	return (write_unsgnd(0, y, bufr, flgs, wid, prc, sz));
}

/********** PrInT UNsIgNeD nUmBeR IN HExADECiMAL **********/
/**
 * phexadecimal - Prints an unsigned number in hexadecimal notation
 * @typs: lista of arguments
 * @bufr: Buffer array is to handle print
 * @flgs:  calculates active flags
 * @wid: get width
 * @prc: Precision specifications
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int phexadecimal(va_list typs, char bufr[],
	int flgs, int wid, int prc, int sz)
{
	return (phexa(typs, "0123456789abcdef", bufr,
		flgs, 'x', wid, prc, sz));
}

/*********** PRiNT UNSIGNED NUmBER IN UpPER HExADEcIMAL ************/
/**
 * phexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @typs: lista of arguments
 * @bufr: Buffer array is to handle print
 * @flgs:  calculates active flags
 * @wid: get width
 * @prc: Precision specifications
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int phexa_upper(va_list typs, char bufr[],
	int flgs, int wid, int prc, int sz)
{
	return (phexa(typs, "0123456789ABCDEF", bufr,
		flgs, 'X', wid, prc, sz));
}
/******* pRiNT UNSiGNED ********/

/**
 * punsigned - Prints an unsigned number
 * @typs: list a of arguments
 * @bufr: Buffer array is to handle print
 * @flgs:  calculates active flags
 * @wid: get width
 * @prc: Precision specifications
 * @sz: Size specifier
 * Return: Number of chars printed.
 */
int punsigned(va_list typs, char bufr[],
	int flgs, int wid, int prc, int sz)
{
	int y = BUFF_SIZE - 2;
	unsigned long int num = va_arg(typs, unsigned long int);

	num = convert_size_unsgnd(num, sz);

	if (num == 0)
		bufr[y--] = '0';

	bufr[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		bufr[y--] = (num % 10) + '0';
		num /= 10;
	}

	y++;

	return (write_unsgnd(0, y, bufr, flgs, wid, prc, sz));
}

/*********** PRINT HExX NuM IN LoWeR OR UpPeR ***********/
/**
 * phexa - Prints a hexadecimal number in lower or upper
 * @typs: lista of arguments
 * @map_to: Array of values to map the number to
 * @bufr: Buffer array is to handle print
 * @flgs:  CaLculates acTive flags
 * @flg_ch: calculates active flags
 * @wid: get width
 * @prc: Precision specifications
 * @sz: Size specification
 * Return: Number of chars printed
 */
int phexa(va_list typs, char map_to[], char bufr[],
	int flgs, char flg_ch, int wid, int prc, int sz)
{
	int y = BUFF_SIZE - 2;
	unsigned long int num = va_arg(typs, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(wid);

	num = convert_size_unsgnd(num, sz);

	if (num == 0)
		bufr[y--] = '0';

	bufr[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		bufr[y--] = map_to[num % 16];
		num /= 16;
	}

	if (flgs & F_HASH && init_num != 0)
	{
		bufr[y--] = flg_ch;
		bufr[y--] = '0';
	}

	y++;

	return (write_unsgnd(0, y, bufr, flgs, wid, prc, sz));
}
