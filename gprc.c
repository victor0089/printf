#include "main.h"

/**
* gprc - Calculates the precision for printing
* @format: formatted string in which to print the arguments
* @y: pointer to the position of '.' character in format string
* @lst: list of arguments to be printed
*
* Return: Precision
*/
int gprc(const char *format, int *y, va_list lst)
{
unsigned int curr_y = *y + 1;
int prc = -1;

if (format[curr_y] != '.')
return (prc);
prc = 0;

curr_y++;
do {
if (is_digit(format[curr_y])) 
{
prc = (prc * 10) + (format[curr_y] - '0');
curr_y++;
} 
else if (format[curr_y] == '*') {
curr_y++;
prc = va_arg(lst, int);
} 
else
{
break;
}
} 
while (1);

*y = curr_y - 1;

return (prc);
}
