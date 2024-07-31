#include "main.h"

/**
 * _putchar - Outputs a single character to the standard output.
 * @c: The character to output.
 *
 * Return: 0 on success, or a negative value on failure.
 */
int _putchar(char c)
{
	static int i;
	static char buffer[DATA_BUFF_SIZE];

	if (c == DATA_CLEAR || i >= DATA_BUFF_SIZE)
	{
		write(1, buffer, i);
		i = 0;
	}
	if (c != DATA_CLEAR)
		buffer[i++] = c;
	return (1);
}
/**
 * _puts - Outputs a string to the standard output followed by a newline.
 * @s: Pointer to the string to output.
 *
 * Return: The number of characters written, or a negative value on failure.
 */
int _puts(char *s)
{
	char *start = s;

	while (*s != '\0')
		_putchar(*s++);
	return (s - start);
}
