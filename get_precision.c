#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
void get_precision(char *format, ...)
{
    char *traverse;
    unsigned int i;
    char *s;
    va_list arg;
    va_start(arg, format);

    for (traverse = format; *traverse != '\0'; traverse++)
    {
        while (*traverse != '%')
        {
            putchar(*traverse);
            traverse++;
        }
        traverse++;
        switch (*traverse)
        {
        case 's':
            s = va_arg(arg, char *);
            puts(s);
            break;
        case 'c':
            putchar(va_arg(lst, int));
            break;
        }
        va_end(arg);
    }
}
