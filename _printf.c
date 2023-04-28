#include "main.h"

void print_buf(char bufr[], int *buff_ind);

/**
* _printf - Printf function
* @format: format.
* Return: Printed chars.
*/
int _printf(const char *format, ...)
{
int y, printed = 0, printed_chars = 0;
int flgs, wid, prc, sz, buff_ind = 0;
va_list list;
char bufr[BUFF_SIZE];

if (format == NULL)
return (-1);

va_start(lst, format);

for (y = 0; format && format[y] != '\0'; y++)
{
if (format[y] != '%')
{
buffer[buff_ind++] = format[y];
if (buff_ind == BUFF_SIZE)
print_buf(bufr, &buff_ind);
printed_chars++;
}
else
{
print_buf(bufr, &buff_ind);
flgs = get_flags(format, &y);
wid = get_width(format, &y, lst);
prc = get_precision(format, &y, lst);
sze = get_size(format, &y;
++y;
printed = handle_print(format, &y, lst, bufr,
flgs, wid, prc ,sz);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}

print_buf(bufr, &buff_ind);

va_end(lst);

return (printed_chars);
}

/**
* print_buffer - Prints the contents of the buffer if it exist
* @buffer: Array of chars
* @buff_ind: Index at which to add next char, represents the length.
*/
void print_buf(char bufr[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &bufr[0], *buff_ind);

*buff_ind = 0;
}
