#include "main.h"

/******************** PRINT CHAR FOR THE TEAM PROJECT ********************/

/**
 * print_char - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width for the team work
 * @precision: Precision specification
 * @size: Size specifier
 * created by Dennis and Zainab
 *
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/******************** PRINT A STRING FOR FUN ********************/
/**
 * print_string - Prints a string
 * @types: List a Of The Arguments
 * @buffer: Buffer array to the handle of the print
 * @flags:  Calculates the active flags
 * @width: get width for team work.
 * @precision: Precision specification
 * @size: Size specifier
 * created by Dennis and Zainab
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
	/* chars = 30 */
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/*************** PRINT THE PERCENT SIGN FOR THIS PROJECT  ***************/
/**
 * print_percent - Prints all the  percent and sign
 * @types: Lista of all the arguments
 * @buffer: Buffer array to the handle print
 * @flags:  Calculates all the  active flags
 * @width: get width for this.
 * @precision: Precision for all the specification
 * @size: Size of the specifier
 * created by Dennis and Zainab
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
	/* chars = 30 */
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/******************** PRINT ALL THE INT ********************/
/**
 * print_int - Print all the int for this project
 * @types: Lista all the  arguments
 * @buffer: Buffer Array To The Handle Print
 * @flags:  Calculates all the active flags
 * @width: get width for this project.
 * @precision: Precision of all the specification
 * @size: Size of the specifier
 * created by Dennis and Zainab
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
	/* chars = 30 */
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/******************** PRINT ALL THE BINARY ********************/
/**
 * print_binary - Prints all  unsigned number for the project
 * @types: Lista all the arguments
 * @buffer: Buffer array to the handle print
 * @flags:  Calculates all the active flags
 * @width: get width for  this project.
 * @precision: Precision for all specification
 * @size: Size of the specifier
 * created by Dennis and Zainab
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
	/* chars =30 */
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
