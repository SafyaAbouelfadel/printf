#include "main.h"

/**
 * converter - convert function
 *
 * @number: number
 * @base: base
 * @flags: arg flag
 * @params: params struct
 *
 * Return: string
 */
char *converter(long int number, int base, int flags, parameter_t *params)
{
	static char *anarray;
	static char storage[50];
	char sign = 0;
	char *pointer;
	unsigned long ber = number;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && number < 0)
	{
		ber = -number;
		sign = '-';
	}
	anarray = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pointer = &storage[49];
	*pointer = '\0';

	do {
		*--pointer = anarray[ber % base];
		ber /= base;
	} while (ber != 0);

	if (sign)
		*--pointer = sign;
	return (pointer);
}
/**
 * print_unsigned_int - prints unsigned int num
 *
 * @args: arg pointer
 * @params: params struct
 *
 * Return: printed bytes
 */
int print_unsigned_int(va_list args, parameter_t *params)
{
	unsigned long lng;

	if (params->long_modif)
		lng = (unsigned long)va_arg(args, unsigned long);
	else if (params->short_modif)
		lng = (unsigned short int)va_arg(args, unsigned int);
	else
		lng = (unsigned int)va_arg(args, unsigned int);
	params->unsign = 1;
	return (format_number(converter(lng, 10, CONVERT_UNSIGNED, params), params));
}
/**
 * format_address - prints the address
 *
 * @args: argument pointer
 * @params: params struct
 *
 * Return: printed bytes
 */
int format_address(va_list args, parameter_t *params)
{
	unsigned long int m = va_arg(args, unsigned long int);
	char *string;

	if (!m)
		return (_puts("(nil)"));

	string = converter(m, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--string = 'x';
	*--string = '0';
	return (format_number(string, params));
}
