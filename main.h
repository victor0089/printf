#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h> /* va_list */
#include <stdlib.h> /* malloc, free */
#include <unistd.h> /* write */
#include <stdio.h>
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* helper functions */
char* (*get_func(char i))(va_list);
char *create_buffer(void);
void write_buffer(char *buffer, int len, va_list list);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

/* printf functions */
int _printf(const char *format, ...);
char *print_s(va_list list);
char *print_c(va_list list);
char *print_d(va_list list);
char *itob(va_list list);
char *rot13(va_list list);
char *rev_string(va_list list);
char *itoOctal(va_list list);

/**
 * * struct types - struct
 * * @id: identifier of type to print (e.g. c means char)
 * * @func: ptr to functions that print according to identifier (e.g. print_c)
 * */

typedef struct types
{
	char id;
	char* (*func)(va_list);
} print;

#endif
