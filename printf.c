#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_char - Prints a character to stdout
 * @args: A va_list containing the character to be printed
 * Return: The number of characters printed
 */
int print_char(va_list args)
{
char c = va_arg(args, int);
putchar(c);
return (1);
}
/**
 * print_string - Prints a string to stdout
 * @args: A va_list containing the string to be printed
 * Return: The number of characters printed
 */
int print_string(va_list args)
{
char *str = va_arg(args, char *);
int len = 0;
if (str == NULL)
str = "(null)";
while (*str)
{
putchar(*str);
str++;
len++;
}
return (len);
}
/**
 * print_percent - Prints a percent sign to stdout
 * @args: Unused
 * Return: The number of characters printed
 */
int print_percent(__attribute__((unused)) va_list args)
{
putchar('%');
return (1);
}
/**
 * print_integer - Print an integer
 * @arg: The integer to print
 * Return: The number of characters printed
 */
int print_integer(va_list arg)
{
int n = va_arg(arg, int);
char buffer[12];
int len;
itoa(n, buffer, 10);
len = print_string(buffer);
return (len);
}
/**
 * print_decimal - Print a decimal integer
 * @arg: The integer to print
 * Return: The number of characters printed
 */
int print_decimal(va_list arg)
{
return (print_integer(arg));
}
/**
 * _printf - Prints a formatted string to stdout
 * @format: The format string to print
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
if (*format == '\0')
break;
if (*format == '%')
count += print_percent(args);
else if (*format == 'c')
count += print_char(args);
else if (*format == 's')
count += print_string(args);
else
{
putchar('%');
putchar(*format);
count += 2;
}
}
else
{
putchar(*format);
count++;
}
format++;
}
va_end(args);
return (count);
}
