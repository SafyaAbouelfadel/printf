#include "main.h"

/**
 * _printf - Custom printf function
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int idx, length = 0;
	const char *p, *start;
	va_list arg_list;
	parameter_t params;

	if (!format || (format[0] == '%' && !format[1]) ||
		(format[0] == '%' && format[1] == ' ' && !format[2]))
			return (-1);
	va_start(arg_list, format);
	for (idx = 0; format[idx]; idx++)
	{
	initial_params(&params, arg_list);

	if (format[idx] != '%')
	{
	length += _putchar(format[idx]);
		continue;
	}
	p = &format[idx];
	start = p;
	p++;
	while (get_flag((char *)p, &params))
		p++;
	p = get_width((char *)p, &params, arg_list);
	p = get_precision((char *)p, &params, arg_list);

	if (get_length_modifiers((char *)p, &params))
		p++;
	if (!get_specifier((char *)p))
		length += output_range(start, p, params.long_modif ||
		params.short_modif ? p + 1 : 0);
	else
		length += fetch_output_function((char *)p, arg_list, &params);
	idx = p - format;
	}

	_putchar(DATA_CLEAR);
	va_end(arg_list);
	return (length);
}
