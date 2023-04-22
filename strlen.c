#include "main.h"
/**
 * _strlen - prints length string in integer
 * @s: string passed to function
 * Return: a
 */
int _strlen(char *s)
{
	int a = 0;

	while (*(s + a))
		a++;

	return (a);
}
