#include "main.c"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: List of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int crnt_i;
	int width = 0;

	for (crnt_i = *i + 1; format[crnt_i] != '\0'; crnt_i++)
	{
		if (is_digit(format[crnt_i]))
		{
			width *= 10;
			width += format[crnt_i] - '0';
		}
		else if (format[crnt_i] == '*')
		{
			crnt_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = crnt_i - 1;

	return (width);
}
