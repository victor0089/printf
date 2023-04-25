#include "main.h"

/**
* get_precision - Calculates the precision for printing
* @format: Formatted string in which to print the arguments
* @i: List of arguments to be printed.
* @list: list of arguments.
*
* Return: Precision.
*/
int get_precision(const char *format, int *i, va_list list)
{
int curr_i = *i + 1;
int prc = 0;   // Fixed: initialize to 0

if (format[curr_i] != '.')
return prc;

prc = 0;

for (curr_i += 1; format[curr_i] != '\0'; curr_i++) {   // Added check for '\0'
if (is_digit(format[curr_i])) {
if (prc <= INT_MAX / 10)  // Added overflow check
prc *= 10;
prc += format[curr_i] - '0';
} else if (format[curr_i] == '*') {
curr_i++;
int val = va_arg(list, int);
if (val >= 0) {   // Added check that value retrieved is valid
prc = val;
} else {
return -2;  // Return error code
}
break;
} else {
break;   // Added check to break on non-digit
}
}
*i = curr_i - 1;

return prc;
}
