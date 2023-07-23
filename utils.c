#include "main.h"

/**
 * is_printable - Evaluates that all of the  char is printable
 * @c: Char is to be evaluated in this project
 * Updated by Dennis and Zainab.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
	/* char = 8 */
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascci in all of hexadecimal code of the buffer
 * @buffer: Array each of the chars.
 * @i: Index at which is to start all of the appending.
 * @ascii_code:THIS IS ALL OF THE ASSCI CODE
 * Updated by Dennis and Zainab.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
	/* chars = 8 */
{
	char map_to[] = "0123456789ABCDEF";
	/* This hexa format code has always been 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies all of the char is in the digit
 * @c: Char is always to be evaluated
 * Updated by Zainab and Dennis.
 *
 * Return: 1 if c is the digit, 0 otherwise
 */
int is_digit(char c)
	/* char = 8 */
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts all of the numbers in the specified size
 * @num: Number are to be casted out
 * @size: Number indicating all of the types that is to be casted
 * Updated by Dennis and Zainab.
 *
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int size)
	/* char = 8 */
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Casts the number to be  specified in the size
 * @num: Number to be casted out is listed
 * @size: Number is indicating all the type to be casted
 * Created by Dennis and Zainab
 *
 * Return: Casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
	/* char = 8 */
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
