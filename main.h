#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLgS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZeS */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct victor - Struct nada
 *
 * @victor: The format.
 * @nad: The function associated.
 */
struct victor
{
	char victor;
	int (*nad)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct victor victor_t - Struct nada
 *
 * @victor: The format.
 * @victor_t: The function associated.
 */
typedef struct victor victor_t;

int _printf(const char *format, ...);
int hprint(const char *victor, int *y,
va_list lst, char bufr[], int flgs, int wid, int prc, int sz);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int pchar(va_list typs, char bufr[],
	int flgs, int wid, int prc, int sz);
int pstring(va_list typs, char bufr[],
	int flgs, int wid, int prc, int sz);
int ppercent(va_list typs, char bufr[],
	int flgs, int wid, int prc, int sz);

/* Functions to print numbers */
int pint(va_list typs, char bufr[],
	int flgs, int wid, int prc, int sz);
int pbinary(va_list typs, char bufr[],
	int flgs, int wid, int prc, int sz);
int punsigned(va_list typs, char bufr[],
	int flgs, int wid, int prc, int sze);
int poctal(va_list typs, char bufr[],
	int flgs, int wid, int prc, int sz);
int phexadecimal(va_list typs, char bufr[],
	int flgs, int wid, int prc, int sz);
int phexa_upper(va_list typs, char bufr[],
	int flgs, int wid, int prc, int sz);

int phexa(va_list typs, char map_to[],
char bufr[], int flgs, char flg_ch, int wid, int prc, int sz);

/* Function to print non printable characters */
int pnon_printable(va_list typs, char bufr[],
	int flgs, int wid, int prc, int sz);

/* Funcion to print memory address */
int ppointer(va_list typs, char bufr[],
	int flgs, int wid, int prc, int sz);

/* Funciotns to handle other specifiers */
int gflgs(const char *format, int *y);
int gwid(const char *format, int *y, va_list lst);
int gprc(const char *format, int *y, va_list lst);
int gsz(const char *format, int *y);

/*Function to print string in reverse*/
int preverse(va_list typs, char bufr[],
	int flgs, int wid, int prc, int sz);

/*Function to print a sTring in Rot 13*/
int prot13string(va_list typs, char bufr[],
	int flgs, int wid, int prc, int sz);

/* width haNdler */
int handle_write_char(char c, char bufr[],
	int flgs, int wid, int prc, int sz);
int write_number(int is_positive, int ind, char bufr[],
	int flgs, int wid, int prc, int sz);
int write_num(int ind, char bff[], int flgs, int wid, int prc,
	int length, char padd, char extra_c);
int write_pointer(char bufr[], int ind, int length,
	int wid, int flgs, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char bufr[],
	int flgs, int wid, int prc, int sz);

/**** UiIls ****/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int sz);
long int convert_size_unsgnd(unsigned long int num, int sz);

#endif /* MAIN_H */
