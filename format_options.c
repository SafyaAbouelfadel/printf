#include "main.h"

/**
 * initial_params - Initializes the parameter_t structure with default values
 * and processes variable arguments.
 * @params: Pointer to the parameter_t structure to initialize.
 * @arg: List of arguments to process.
 *
 * Return: None.
 */
void initial_params(parameter_t *params, va_list arg)
{
	params->unsign = false;
	params->left_align = false;
	params->zero_pad = false;
	params->alternate_form = false;
	params->force_sign = false;
	params->space_flag = false;
	params->width = 0;
	params->precision = UINT_MAX;
	params->short_modif = 0;
	params->long_modif = 0;
	(void)arg;
}

/**
 * get_precision - Extracts the precision specifier from the format string
 * and updates the parameter_t structure.
 * @s: Pointer to the current position in the format string.
 * @params: Pointer to the parameter_t structure to update.
 * @ap: List of arguments if precision requires additional values.
 *
 * Return: Updated position in the format string.
 */

char *get_precision(char *s, parameter_t *params, va_list ap)
{
	if (*s != '.')
	{
		params->precision = -1;
		return (s);
	}

	s++;
	if (*s == '*')
	{
		params->precision = va_arg(ap, int);
	return (s + 1);
	}

	params->precision = 0;
	while (_is_digit(*s))
	{
		params->precision = params->precision * 10 + (*s - '0');
		s++;
	}
	return (s);
}


/**
 * get_width - Extracts the width specifier from the format string and
 * updates the parameter_t structure.
 * @s: Pointer to the current position in the format string.
 * @params: Pointer to the parameter_t structure to update.
 * @ap: List of arguments if width requires additional values.
 *
 * Return: Updated position in the format string.
 */
char *get_width(char *s, parameter_t *params, va_list ap)
{
	int width = 0;

	if (*s == '*')
	{
		width = va_arg(ap, int);
		params->width = width;
		return (s + 1);
	}

	params->width = 0;
	while (_is_digit(*s))
	{
	params->width = params->width * 10 + (*s - '0');
	s++;
	}

	if (params->width < 0)
	{
	params->width = -params->width;
	}

	return (s);
}
/**
 * get_flag - Parses flags from the format string and updates the
 * parameter_t structure with flag values.
 * @s: Pointer to the current position in the format string.
 * @params: Pointer to the parameter_t structure to update.
 *
 * Return: Pointer to an integer representing the parsed flags.
 */
int *get_flag(char *s, parameter_t *params)
{
	int flag_set = 0;

	if (s == NULL || params == NULL)
		return (s);/* handle if s is NULL*/
	while (*s == '-' || *s == '0' || *s == '#' || *s == '+' || *s == ' ')
	{
	if (*s == '-')
	{
		params->left_align = true;
		params->zero_pad = false; /* '-' flag overrides '0' flag */
		flag_set = 1;
	}
	else if (*s == '0' && !params->left_align)
	{
		params->zero_pad = true;
		flag_set = 1;
	}
	else if (*s == '#')
	{
		params->alternate_form = true;
		flag_set = 1;
	}
	else if (*s == '+')
	{
		params->force_sign = true;
		flag_set = 1;
	}
	else if (*s == ' ')
	{
		params->space_flag = true;
		flag_set = 1;
	}
	s++;
	}
	return (flag_set);
	}
/**
 * get_length_modifiers - Extracts length modifiers (e.g., h, l, L) from
 * the format string and updates the parameter_t structure.
 * @s: Pointer to the current position in the format string.
 * @params: Pointer to the parameter_t structure to update.
 *
 * Return: The length modifier as an integer.
 */
int get_length_modifiers(char *s, parameter_t *params)
{
	int mod = 0;

	if (*s == 'h')
	{
		params->short_modif = 1;
		mod = 1;
	}
	else if (*s == 'l')
	{
	params->long_modif = 1;
	mod = 1;
	}

	return (mod);
}
