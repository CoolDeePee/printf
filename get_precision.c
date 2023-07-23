#include "main.h"

/**
 * get_precision - Calculates all the precision in the printing
 * @format: Formatted string to print all the arguments
 * @i: List Of All The Arguments To Be Printed.
 * @list: list all the arguments
 * created by Dennis and Zainab.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
	/* chars = 30 */
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}
