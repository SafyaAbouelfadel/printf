#include "main.h"
/**
 * output_range - Outputs a range of characters from begin to end and
 * compares the result with the expected output.
 * @begin: Pointer to the start of the range.
 * @end: Pointer to the end of the range.
 * @expect: Expected output for comparison.
 *
 * Return: 0 if the output matches the expected result,
 * or a non-zero value otherwise.
 */
int output_range(char *begin, char *end, char *expect)
{
	int i, range;

	for (i = 0; begin <= end; i++)
	{
		if (begin != expect)
			range += _putchar(*begin);
		begin++;
	}
	return (range);
}

/**
 * output_reverse - Prints a string in reverse
 * @ap: Argument list containing the string to print
 * @params: Parameter struct (if needed)
 *
 * Return: Number of characters printed
 */
int output_reverse(va_list ap, parameter_t params)
{
	int len = 0, count = 0;
	char *s = va_arg(ap, char*);

	(void)(params);

	if (!s)
		s = "(null)";

	while (s[len] != '\0')
		len++;
	int i;

	for (i = len - 1; i >= 0; i--)
	{
		count += _putchar(s[i]);
	}

	return (count);
}
/**
 * output_rot13 - Outputs a string encoded with the ROT13 cipher based on
 * the format specifiers in params.
 * @ap: List of arguments containing the string to encode.
 * @params: parameter_t structure containing format specifiers.
 *
 * Return: The number of characters output.
 */
int output_rot13(va_list ap, parameter_t params)
{
	int i, position, count = 0;
	char *s = va_arg(ap, char *);
	(void)params;
	char ar[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; s[i] != '\0'; i++)
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
		{
			if (s[i] >= 'a' && s[i] <= 'z')
				position = s[i] - 'a';
			else
				position = s[i] - 'A';

			count += _putchar(ar[position]);
		}
		else
			count += _putchar(s[i]);
	}
	return (count);
}
