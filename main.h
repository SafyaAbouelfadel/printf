#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

#define DATA_BUFF_SIZE 1024
#define DATA_CLEAR -1

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

/**
 * struct parameter - Holds formatting options
 *
 * @unsign: Flag for unsigned values
 * @left_align: Flag for left alignment
 * @zero_pad: Flag for zero padding
 * @alternate_form: Flag for alternate form
 * @force_sign: Flag for force sign
 * @space_flag: Flag for space
 * @width: Field width
 * @precision: Field precision
 * @short_modif: Flag for short modifier
 * @long_modif: Flag for long modifier
 */

typedef struct parameter
{
	bool unsign;    /* u specifier */
	bool left_align;    /* '-' flag*/
	bool zero_pad;  /* '0' flag */
	bool alternate_form;    /* # flag */
	bool force_sign;    /* + flag */
	bool space_flag;    /* ' ' flag */
	unsigned int width;
	unsigned int precision;
	unsigned int short_modif;
	unsigned int long_modif;

} parameter_t;

/**
 * struct specifier - Holds specifier and function pointer
 * @specifier: The format specifier
 * @f: The function pointer to handle the specifier
 */

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, parameter_t *);
} specifier_t;

int _printf(const char *format, ...);

/* numerals*/
char *converter(long int number, int base, int flags, parameter_t *params);
int print_unsigned_int(va_list args, parameter_t *params);
int format_address(va_list args, parameter_t *params);

/* print_digit */
int is_digit(int d);
int format_number(char *string, parameter_t *params);
int _string_length(char *c);
int format_number_shifted_right(char *string, parameter_t *params);
int format_number_shifted_left(char *string, parameter_t *params);

/* output_functions*/
int print_character(va_list args, parameter_t *params);
int print_integer(va_list args, parameter_t *params);
int output_string(va_list args, parameter_t *params);
int output_percentage(va_list args, parameter_t *params);
int output_S(va_list args, parameter_t *params);

/* strings*/
int _putchar(char c);
int _puts(char *s);

/* format_options*/
void initial_params(parameter_t *params, va_list arg);
char *get_precision(char *s, parameter_t *params, va_list ap);
char *get_width(char *s, parameter_t *params, va_list ap);
int *get_flag(char *s, parameter_t *params);
int get_length_modifiers(char *s, parameter_t *params);

/* function*/
int output_range(char *begin, char *end, char *expect);
int output_reverse(va_list ap, parameter_t params);
int output_rot13(va_list ap, parameter_t params);

/* number_conversion*/
int output_hex(va_list args, parameter_t *params);
int output_HEX(va_list args, parameter_t *params);
int format_binary(va_list args, parameter_t *params);
int output_octal_value(va_list args, parameter_t *params);

/* fetch_specifier*/
int (*get_specifier(char *s))(va_list ap, parameter_t *params);
int fetch_output_function(char *str, va_list arg, parameter_t *params);

#endif /* MAIN_H */
