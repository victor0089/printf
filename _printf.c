#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 *
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
#include "main.h"

void print_buffer(char buffer[], int *buff_ind);
int _printf(const char *format, ...);

int main(void)
{
int printed = _printf("Hello, %s! The answer is %d.\n", "world", 42);
_printf("Printed %d characters.\n", printed);
return 0;
}

int _printf(const char *format, ...)
{
if (format == NULL)
return -1;

int i, printed = 0, printed_chars = 0;
int flgs, wid, prc, sz, buff_ind = 0;
char buffer[BUFF_SIZE];

va_list list;
va_start(list, format);

for (i = 0; format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buffer[buff_ind++] = format[i];
if (buff_ind == BUFF_SIZE)
{
print_buffer(buffer, &buff_ind);
}
printed_chars++;
}
else
{
print_buffer(buffer, &buff_ind);
flgs = get_flags(format, &i);
wid = get_width(format, &i, list);
prc = get_precision(format, &i, list);
sz = get_size(format, &i);
++i;
printed = handle_print(format, &i, list, buffer, flgs, wid, prc, sz);
if (printed == -1)
{
return -1;
}
printed_chars += printed;
}
}

print_buffer(buffer, &buff_ind);
va_end(list);

return printed_chars;
}

void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
{
write(1, &buffer[0], *buff_ind);
}
*buff_ind = 0;
}
