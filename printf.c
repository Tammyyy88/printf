#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
/**
 * print_char - Prints a single character to stdout.
 * @c: The character to print.
 * Return: Always 1.
 */
int print_char(char c)
{
putchar(c);
return (1);
}
/**
 * print_string - Prints a string of characters to stdout.
 * @str: The string to print.
 * Return: The number of characters printed.
 */
int print_string(char *str)
{
int i = 0;
while (str[i])
{
putchar(str[i]);
i++;
}
return (i);
}
/**
 * print_number - Prints an integer to stdout.
 * @n: The integer to print.
 * Return: The number of digits printed.
 */
int print_number(int n)
{
int digits = 0;
if (n < 0)
{
digits += print_char('-');
n = -n;
}
if (n / 10)
digits += print_number(n / 10);
digits += print_char(n % 10 + '0');
return (digits);
}
/**
 * _printf - Produces output according to a format string.
 * @format: The format string.
 * @...: Optional arguments to be inserted into the output.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
va_list args;
int printed = 0;
if (!format)
return (-1);
va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
if (*format == '\0')
return (-1);
else if (*format == '%')
printed += print_char('%');
else if (*format == 'c')
printed += print_char(va_arg(args, int));
else if (*format == 's')
printed += print_string(va_arg(args, char *));
else if (*format == 'd' || *format == 'i')
printed += print_number(va_arg(args, int));
else if (*format == 'u')
printed += print_unsigned_number(va_arg(args, unsigned int));
else if (*format == 'o')
printed += print_octal_number(va_arg(args, unsigned int));
else if (*format == 'x')
printed += print_hex_number(va_arg(args, unsigned int), 0);
else if (*format == 'X')
printed += print_hex_number(va_arg(args, unsigned int), 1);
else if (*format == 'p')
printed += print_pointer(va_arg(args, void *));
else
printed += print_char('%'), printed += print_char(*format);
}
else
{
printed += print_char(*format);
}
format++;
}
va_end(args);
return (printed);
}
