#include "main.h"

/**
 * get_specifier - Returns a function pointer for a format specifier.
 * @s: The format specifier character.
 *
 * Return: Pointer to the function that handles the format specifier, or NULL
 *         if not found.
 */

int (*get_specifier(char *s))(va_list ap, parameter_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_character},
		{"d", print_integer},
		{"i", print_integer},
		{"s", output_string},
		{"%", output_percentage},
		{"b", output_binary},
		{"o", output_octal_value},
		{"u", print_unsigned_int},
		{"x", output_hex},
		{"X", output_HEX},
		{"p", format_address},
		{"S", output_S},
		{"r", output_reverse},
		{"R", output_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}
/**
 * fetch_output_function - Calls the function for the format specifier.
 * @str: The format specifier string.
 * @arg: List of arguments for the format function.
 * @params: Format parameters.
 *
 * Return: Number of characters printed, or 0 if no function found.
 */
int fetch_output_function(char *str, va_list arg, parameter_t *params)
{
	int (*f)(va_list, parameter_t *) = get_specifier(str);

	if (f)
		return (f(arg, params));

	return (0);
}
