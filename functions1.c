#include "main.h"

/***************** PRINT ALL THE UNSIGNED NUMBER *****************/
/**
 * print_unsigned - Prints all the unsigned of number
 * @types: List a of all the arguments
 * @buffer: Buffer Array To All The Handle Print
 * @flags:  Calculates all the active flags
 * @width: get width for this task
 * @precision: Precision for all the specification
 * @size: Size of the specifier
 * created by Dennis and Zainab
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
	/* chars = 30 */
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/******** PRINT ALL THE UNSIGNED NUMBER IN THE OCTAL  ***********/
/**
 * print_octal - Prints all the unsigned number in octal notation
 * @types: Lista of all the arguments
 * @buffer: Buffer Array To The Handle Print
 * @flags:  Calculates all the active flags
 * @width: get width for this task
 * @precision: Precision of the specification
 * @size: Size of the specifier
 * created by Dennis and Zainab
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
	/* chars = 30 */
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/********* PRINT ALL THE UNSIGNED NUMBER IN HEXADECIMAL *********/
/**
 * print_hexadecimal - Prints all the unsigned number in hexadecimal notation
 * @types: Lista of all the  arguments
 * @buffer: Buffer Array To The Handle Print
 * @flags:  Calculates all the active flags
 * @width: get width for this task
 * @precision: Precision of the specification
 * @size: Size of the specifier
 * created by Dennis and Zainab
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
	/* chars = 30 */
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/********** PRINT ALL THE UNSIGNED NUMBER IN THE UPPER HEXADECIMAL ***********/
/**
 * print_hexa_upper - Prints all the unsigned number upper hexadecimal notation
 * @types: Lista of the arguments
 * @buffer: Buffer Array To The Handle Print
 * @flags:  Calculates all the active flags
 * @width: get width for this task
 * @precision: Precision of all the specification
 * @size: Size of the specifier
 * created by Dennis and Zainab
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
	/* chars = 30 */
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT ALL THE HEXX IN THE NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints all hexadecimal in the number in lower or upper
 * @types: Lista of the arguments
 * @map_to: Array of the values to the map and the number too
 * @buffer: Buffer Array To The Handle Print
 * @flags:  Calculates all the active flags
 * @flag_ch: Calculates all the active flags
 * @width: get width for this task
 * @precision: Precision of the specification
 * @size: Size of the specifier
 * @size: Size of the specification
 * created by Dennis and Zainab
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
	/* chars = 30 */
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
