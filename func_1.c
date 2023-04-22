#include "main.h"

/*****************PRINT UNSIGNED NUMBER******************/

/**
 * print_unsigned - Prints an unsigned number
 * @typs: List a of arguments
 * @buffer: Buffer array to handle print
 * @flgs: Calculates active flgs
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */

int print_unsigned(va_list typs, char buffer[], int flgs, int width,  int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(typs, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flgs, width, precision, size));
}

/******************PRINT UNSIGNED NUMBER IN OCTAL*******************/

/**
 * print_octal - Prints an unsigned number in octal notation
 * @typs: Lista a of arguments
 * @buffer: Buffer array to handle print
 * @flgs: Calculates active flgs
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_octal(va_list typs, char buffer[], int flgs, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int init_num = va_arg(typs, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = cinver_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flgs & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flgs, width, precision, size));
}

/*********************PRINT UNSIGNED NUMBER IN HEXADECIMAL********************/

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @typs: Lista a arguments
 * @buffer: Buffer array to handle print
 * @flgs: Calculates active flgs
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_hexadecimal(va_list typs, char buffer[], int flgs, int width, int precision, int size)
{
	return (print_hexa(typs, "0123456789abcdef", buffer, flgs, 'x', width, precision, size));
}

/************************PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL*********************/

/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @typs: List a arguments
 * @buffer: Buffer array to handle print
 * @flgs: Clalculates active flgs
 * @width: get width
 * @precision: Precision specification
 * @size: size specifier
 * Return: Number of chars printed
 */

int print_hexa_upper(va_list typs, char buffer[], int flgs, int width, int precision, int size)
{
	return (print_hexa_upper(typs, "0123456789ABCDEF", buffer, flgs, 'X', width, precision, size));
}

/**********************PRINT HEXX NUM IN LOWER OR UPPER*******************/

/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @typs: List a of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flgs: Calculates active flgs
 * @flag_ch: Calculates active flgs
 * @width: get width
 * @precision: Precision on specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */

int print_hexa(va_list typs, char map_to[], char buffer[], int flgs, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int init_num = va_arg(typs, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flgs & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flgs, width, precision, size));
}
