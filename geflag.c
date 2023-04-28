#include "main.h"

/**
 * gflgs - Calculates active flags
 * @format: ForMatted string in which to print the arguments
 * @y: Take a PaRameter.
 *
 * Return: Flags:
 */
int gflgs(const char *format, int *y)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_y;
	int flgs = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_y = *y + 1; format[curr_y] != '\0'; curr_y++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_y] == FLAGS_CH[j])
			{
				flgs |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*y = curr_y - 1;

	return (flgs);
}
