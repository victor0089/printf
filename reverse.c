#include "main.h"

/**
 * rev_string - reverses a string
 * @list: string to reverse
 * Return: reversed string
 */

char *rev_string(va_list list)
{
        char *rev;
	char *str;
	int i = 0, len, j;

	str = va_arg(list, char *); /* store argument to access only once */
	if (str == NULL)
		str = ")llun(";

	len = _strlen(str);

	rev = malloc(sizeof(char) * (len + 1)); /* malloc new variable */
	if (rev == NULL)
		return (NULL);

	for(j = (len - 1); j >= 0; j--) /* store reverse in new variable */
	{
		rev[i++] = str[j];
	}
	rev[i] = '\0';

	return (rev);
}
