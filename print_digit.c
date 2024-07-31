#include "main.h"

/**
 * is_digit - verifies id char is a num
 *
 * @d: char to be checked
 *
 * Return: returns 1 if d is num, 0 if not
 */
int is_digit(int d)
{
	return (d >= '0' && d <= '9');
}
/**
 * _string_length - returns the length of a string
 *
 * @c: string to check the length of
 *
 * Return: returns str length as an int
 */
int _string_length(char *c)
{
	int u = 0;

	while (*c++)
		u++;
	return (u);
}
/**
 * format_number - prints a num with opts
 *
 * @string: base string
 * @params: params struct
 *
 * Return: returns printed chars
 */
int format_number(char *string, parameter_t *params)
{
	unsigned int u = _string_length(string);
	int ngt = (!params->unsign && *string == '-');

	if (!params->precision && *string == '0' && !string[1])
		string = "";
	if (ngt)
	{
		string++;
		u--;
	}
	if (params->precision != UINT_MAX)
		while (u++ < params->precision)
			*--string = '0';
	if (ngt)
		*--string = '-';

	if (!params->left_align)
		return (format_number_shifted_right(string, params));
	else
		return (format_number_shifted_left(string, params));
}
/**
 * format_number_shifted_right - prints numbers with options
 *
 * @string: string of base number
 * @params: params struct
 *
 * Return: returns printed char
 */
int format_number_shifted_right(char *string, parameter_t *params)
{
	unsigned int m = 0, ngt, ngt2, u = _string_length(string);
	char filler_char = ' ';

	if (params->zero_pad && !params->left_align)
		filler_char = '0';
	ngt = ngt2 = (!params->unsign && *string == '-');
	if (ngt && u < params->width && filler_char == '0' && !params->left_align)
		string++;
	else
		ngt = 0;
	if ((params->force_sign && !ngt2) ||
			(!params->force_sign && params->space_flag && !ngt2))
		u++;
	if (ngt && filler_char == '0')
		m += _putchar('-');
	if (params->force_sign && !ngt2 && filler_char == '0' && !params->unsign)
		m += _putchar('+');
	else if (!params->force_sign && params->space_flag && !ngt2 &&
			!params->unsign && params->zero_pad)
		m += _putchar(' ');
	while (u++ < params->width)
		m += _putchar(filler_char);
	if (ngt && filler_char == ' ')
		m += _putchar('-');
	if (params->force_sign && !ngt2 && filler_char == ' ' && !params->unsign)
		m += _putchar('+');
	else if (!params->force_sign && params->space_flag && !ngt2 &&
			!params->unsign && !params->zero_pad)
		m += _putchar(' ');
	m += _puts(string);
	return (m);
}
/**
 * format_number_shifted_left - prints num with options
 *
 * @string: base num as string
 * @params: parameters Struct
 *
 * Return: returns printed chars
 */
int format_number_shifted_left(char *string, parameter_t *params)
{
	unsigned int m = 0, ngt2, u = _string_length(string);
	char filler_char = ' ';

	if (params->zero_pad && !params->left_align)
	{
		filler_char = '0';
		ngt2 = (!params->width && filler_char == '0' && !params->left_align);
		string++;
	}
	else
	{
		ngt2 = 0;
	}
	if (params->force_sign && !ngt2 && !params->unsign)
	{
		m += _putchar(' ');
		u++;
	}
	m += _puts(string);
	while (u++ < params->width)
	{
		m += _putchar(filler_char);
	}
	return (m);
}
