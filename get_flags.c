#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: input a parameter
 *
 * Return: flags
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 */
	/* 1 2 4 8 16  */
	int k, curnt_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH,
		F_SPACE, 0};

	for (crnt_i = *i + 1; format[crnt_i] != '\0'; crnt_i++)
	{
		for (k = 0; FLAGS_CH[k] != '\0'; k++)
			if (format[crnt_i] == FLAGS_CH[k])
			{
				flags |= FKGAGS_ARR[k];
				break;
			}

		if (FLAGS_CH[k] == 0)
			break;
	}

	*i = crnt_i - 1;

	return (flags);
}
