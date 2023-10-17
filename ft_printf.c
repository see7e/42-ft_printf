#include "ft_printf.h"

// Handle format specifiers
static int	ft_handleFormatSpecifier(const char *format, va_list args, int *count)
{
	format++; // Move past '%'
	if (*format == 'c')
		*count += ft_printChar(args, &count);
	else if (*format == 's')
		*count += ft_printString(args, &count);
	else if (*format == 'p')
		*count += ft_printPointer(args, &count);
	else if (*format == 'd' || *format == 'i')
		*count += ft_printDecimal(args, &count);
	else if (*format == 'u')
		*count += ft_printUnsignedDecimal(args, &count);
	else if (*format == 'x' || *format == 'X')
		*count += ft_printHexadecimal(args, &count, format);
	else if (*format == '%')
		*count += ft_printPercent(&count);
	return (*count);
}

int	ft_printf(const char *format, ...)
{
	int *count;
	va_list args;

	*count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%') // Handle the format specifier
			*count += ft_handleFormatSpecifier(format, args, &count);
		else
		{ // Handle non-% characters
			write(1, format, 1); // Print the character using the write function
			*count++; // Update the character count
		}
		format++; // Move to the next character in the format string
	}
	va_end(args); // Clean up the va_list
	return (*count); // Return the total characters printed
}
