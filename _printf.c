#include "main.h"

/**
 * _printf - Custom printf function
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int idx = 0, length = 0;
	const char *start;
	va_list arg_list;
	parameter_t params;

	if (!format || (format[0] == '%' && !format[1]) ||
		(format[0] == '%' && format[1] == ' ' && !format[2]))
	return (-1);

	va_start(arg_list, format);
	while (format[idx])
	{
		initial_params(&params, arg_list);

	if (format[idx] != '%')
	{
		length += _putchar(format[idx++]);
		continue;
	}
	start = &format[idx++];
	while (get_flag((char *)format + idx, &params))
		idx++;

	idx = get_width((char *)format + idx, &params, arg_list) - format;
	idx = get_precision((char *)format + idx, &params, arg_list) - format;

	if (get_length_modifiers((char *)format + idx, &params))
		idx++;
	if (!get_specifier((char *)format + idx))
		length += output_range(start, &format[idx], params.long_modif ||
			params.short_modif ? &format[idx] + 1 : 0);
	else
		length += fetch_output_function((char *)format + idx, arg_list, &params);

	idx += &format[idx] - (format + idx);
	}

	_putchar(DATA_CLEAR);
	va_end(arg_list);
	return (length);
}
