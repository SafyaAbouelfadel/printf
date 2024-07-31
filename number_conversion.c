#include "main.h"

/**
 * output_hex - prints unsigned hex digits in lowecase
 *
 * @args: arg pointer
 * @params: params struct
 *
 * Return: printed bytes
 */
int output_hex(va_list args, parameter_t *params)
{
	unsigned long lng;
	int r = 0;
	char *string;

	if (params->long_modif)
		lng = (unsigned long)va_arg(args, unsigned long);
	else if (params->hModifier)
		lng = (unsigned short int)va_arg(args, unsigned int);
	else
		lng = (unsigned int)va_arg(args, unsigned int);

	string = converter(lng, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->alternate_form && lng)
	{
		*--string = 'x';
		*--string = '0';
	}
	params->unsign = 1;
	return (r += format_number(string, params));
}
/**
 * output_HEX - prints unsigned hex digits in uppercase
 *
 * @args: arg ptr
 * @params: params struct
 *
 * Return: printed byytes
 */
int output_HEX(va_list args, parameter_t *params)
{
	unsigned long lng;
	int r = 0;
	char *string;

	if (params->long_modif)
		lng = (unsigned long)va_arg(args, unsigned long);
	else if (params->hModifier)
		lng = (unsigned short int)va_arg(args, unsigned int);
	else
		lng = (unsigned int)va_arg(args, unsigned int);

	string = converter(lng, 16, CONVERT_UNSIGNED, params);
	if (params->alternate_form && lng)
	{
		*--string = 'X';
		*--string = '0';
	}
	params->unsign = lng;
	return (r += format_number(string, params));
}
/**
 * output_binary - prints unsigned binary digit
 *
 * @args: arg ptr
 * @params: params struct
 *
 * Return: printed bytes
 */
int output_binary(va_list args, parameter_t *params)
{
	unsigned int m = va_arg(args, unsigned int);
	char *string = converter(m, 2, CONVERT_UNSIGNED, params);
	int s = 0;

	if (params->alternate_form && m)
		*--string = '0';
	params->unsign = 1;
	return (s += format_number(string, params));
}
/**
 * output_octal_value - prints unsigned octal digits
 *
 * @args: arg ptr
 * @params: params struct
 *
 * Return: printed bytes
 */
int output_octal_value(va_list args, parameter_t *params)
{
	unsigned long lng;
	char *string;
	int d = 0;

	if (params->long_modif)
		lng = (unsigned long)va_arg(args, unsigned long);
	else if (params->hModifier)
		lng = (unsigned short int)va_arg(args, unsigned int);
	else
		lng = (unsigned int)va_arg(args, unsigned int);
	string = converter(lng, 8, CONVERT_UNSIGNED, params);

	if (params->alternate_form && lng)
		*--string = '0';
	params->unsign = lng;
	return (d += format_number(string, params));
}
