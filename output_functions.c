#include "main.h"

/**
 * print_character - prints a char
 *
 * @args: argument pointer
 * @params: parameters struct
 *
 * Return: return char printed
 */
int print_character(va_list args, parameter_t *params)
{
	char filler_char = ' ';
	unsigned int filler = 1, total =  0, chr = va_arg(args, int);

	if (params->left_align)
		total += _putchar(chr);
	while (filler++ < params->width)
		total += _putchar(filler_char);
	if (!params->left_align)
		total += _putchar(chr);
	return (total);
}
/**
 * print_integer - prints int
 *
 * @args: arg pointer
 * @params: parameters struct
 *
 * Return: num chars printed
 */
int print_integer(va_list args, parameter_t *params)
{
	long lng;

	if (params->long_modif)
		lng = va_arg(args, long);
	else if (params->hModifier)
		lng = (short int)va_arg(args, int);
	else
		lng = (int)va_arg(args, int);
	return (format_number(converter(lng, 10, 0, params), params));
}
/**
 * output_string - prints a string
 *
 * @args: args pointer
 * @params: params struct
 *
 * Return: num chars printed
 */
int output_string(va_list args, parameter_t *params)
{
	char *string = va_arg(args, char *), filler_char = ' ';
	unsigned int filler = 0, total = 0, u = 0, k;
	(void)params;
	switch ((int)(!string))
	case 1:
		string = NULL_STRING;
		k = filler = _string_length(string);
	if (params->precision < filler)
		k = filler = params->precision;
	if (params->left_align)
	{
		if (params->precision != UINT_MAX)
			for (u = 0; u < filler; u++)
				total += _putchar(*string++);
		else
			total += _puts(string);
	}
	while (k++ < params->width)
		total += _putchar(filler_char);
	if (!params->left_align)
	{
		if (params->precision != UINT_MAX)
			for (u = 0; u < filler; u++)
				total += _putchar(*string++);
		else
			total += _puts(string);
	}
	return (total);
}
/**
 * output_percentage - priNTS STRING
 *
 * @args: arg pointer
 * @params: params struct
 *
 * Return: num chars printed
 */
int output_percentage(va_list args, parameter_t *params)
{
	(void)args;
	(void)params;
	return (_putchar('%'));
}
/**
 * output_S - customized format specifier
 *
 * @args: arg ptr
 * @params: params struct
 *
 * Return: returns num chars printed
 */
int output_S(va_list args, parameter_t *params)
{
	char *string = va_arg(args, char *);
	char *hex;
	int total = 0;

	if ((int)(!string))
		return (_puts(NULL_STRING));
	for (; *string; string++)
	{
		if ((*string > 0 && *string < 32) || *string >= 127)
		{
			total += _putchar('\\');
			total += _putchar('X');
			hex = converter(*string, 16, 0, params);
			if (!hex[1])
				total += _putchar('0');
			total += _puts(hex);
		}
		else
		{
			total += _putchar(*string);
		}
	}
	return (total);
}
