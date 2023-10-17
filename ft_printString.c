// TODO: Add header
#include "ft_printf.h"

int	ft_printString(va_list args, int *count)
{
	char	*str;
	unsigned int	len;

	str = va_arg(args, char *);
	len = ft_strlen(str); // Get the length of the string
	write(1, str, len); // Print 'str' using the write function
	return (*count += len); // Return the total characters printed
}