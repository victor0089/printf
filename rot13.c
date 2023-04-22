#include "main.h"
/**
 * rot13 - encrypts string with rot13
 * @list: string to change
 * Return: modified string
 */
char *rot13(va_list list)
{
	int i = 0;
	char *str;
	char *nstr;

	/* store va_arg to only access argument once */
	str = va_arg(list, char *);

	/* malloc new variable to assign over new rot13 characters */
	nstr = malloc(sizeof(char) * (_strlen(str) + 1));
	if (nstr == NULL)
		return (NULL);

	/* iterate str and assign rot13 char to nstr */
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'm') || (str[i] >= 'A' && str[i] <= 'M'))
		{
			nstr[i] = str[i] + 13;
		}
		else if ((str[i] >= 'n' && str[i] <= 'z') || (str[i] >= 'N' && str[i] <= 'Z'))
		{
			nstr[i] = str[i] - 13;
		}
		else
			(nstr[i] = str[i]);
		i++;
	}
	nstr[i] = '\0';

	return (nstr);
}
