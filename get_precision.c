#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */

void get_precision(const char *format, ...) {
    va_list list;
    va_start(list, format);
    
    while (*format) {
        if (*format == '%' && *(format+1) == 'p') {
            int precision = va_arg(list, int);
            double value = va_arg(list, double);
            format += 2;
        } else {
            putchar(*format++);
        }
    }
    
    return(list);
}
