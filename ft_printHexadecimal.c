// TODO: Add header
#include "ft_printf.h"

int	ft_printHexadecimal(va_list args, const char *format, int *count)
{
	unsigned int num;
	
	// Use the array of chars to express the hex upper/lower cases
	const char *hexDigits = (*format == 'x') ? HEX_DIGITS_LOWER : HEX_DIGITS_UPPER;
	num = va_arg(args, unsigned int);
	if (num == 0)
	{
		write(1, "0", 1); // Handle the case of num being zero
		return (*count++);
	}
	else // Call the helper function to print hexadecimal digits
		return (*count += ft_printDigits(num, hexDigits));
}