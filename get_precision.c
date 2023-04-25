#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i:List of arguments to be printed.
 * @list: List of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int crnt_i = *i + 1;
	int precision = -1;

	if (format[crnt_i] != '.')
		return (precision);

	precision = 0;

	for (crnt_i += 1; format[crnt_i] != '\0'; crnt_i++)
	{
		if (is_digit(format[crnt_i]))
		{
			precision *= 10;
			precision += format[crnt_i] - '0';
		}
		else if (format[crnt_i] == '*')
		{
			crnt_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = crnt_i - 1;

	return (precision);
}
