#include "main.h"

/**
 * get_size - Calculates all the size in cast and the argument
 * @format: Formatted string in which can  print all of the arguments
 * @i: List of all the arguments to be printed out
 * created by Dennis and Zaianb
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
	/* chars = 8 */
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}
