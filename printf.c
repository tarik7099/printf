#include <stdarg.h>
#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 *_printf - function that produces output according to a format.
 *@foramt: 
 *
 *
 *
 *
 *
 */
int _printf(const char *format, ...)
{
if (format == "\0")
	return 0;
int i = 0;
int counter = 0;

va_list args;
va_start(args, format); 
while(*format){
	if(*format == '%')
	{
		format++;

		if (*format == 's')
	{
		print_string(va_arg(args, char*));
		counter++;
	}	
		else if(*format == 'c')
        {
                print_char(va_arg(args, char*));
		counter++;
        }
		else if(*format ==  '%')
	{
		_putchar('%');
		counter++;

	}
		if (*format == '\0')
                break;
		else if (*format == 'b')
		{
			decimalTobinary(va_arg(args,unsigned int));
		}
}
	else
{
	_putchar(*format);
	counter++;
}
format++;
}
va_end(args);
return counter;
}

void print_string(char *str)
{
	int counte =  0;
for (int i = 0;str[i] != '\0';i++ )
	{
		_putchar(str[i]);
		counte++;
	}
}
void print_char(char *c)
{
	int countr = 0;
	for (int i = 0; c[i]; c++) {
        _putchar(c[i]);
		countr++;

	}
}
void decimalTobinary(unsigned int d)
{
if (d == 0) {
        _putchar('0');
        return;
    }
int quotient[32];
int i = 0;
while(d > 0)
{
  quotient[i] = d % 2;
  d = d / 2;

i++;
}
for (int j = i - 1; j >= 0; j--) {
       _putchar( quotient[j] + '0');
}
}
int main()
{
}
