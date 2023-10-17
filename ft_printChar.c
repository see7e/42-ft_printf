// TODO: Add Header
#include "ft_printf.h"

int	ft_printChar(va_list args, int *count)
{
	char	c;

	c = va_arg(args, int);
	write(1, &c, 1); // Print 'c' using the write function
	return (*count++); // Update the character count
}